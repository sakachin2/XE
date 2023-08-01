//*CID://+vas3R~:                            update#= 1003;        //~vas1R~//~vas3R~
//*************************************************************
//*xci
//* C source text indentation shift
//*************************************************************
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vas1:230612 ARM;warning by audroidstudio compiler                //~vas1I~
//vap0:200616 Axe compiler warning;                                //~vap0I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va76:130622 compiler warning and err by ndk-r9                   //~va76I~
//v@@4 120908 use ufreads                                          //~@@@5I~
//v@@4 120907 supprt /D for macro selection                        //~@@@3R~
//v@@@ 120901 if/do/while stmt without { } block;                  //~@@@3I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX
	#include <unistd.h>
#else
#include <conio.h>
#endif

#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
#else
    #define INCL_DOSFILEMGR  //DCPY_EXISTING
    #include <os2.h>
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ufile5.h>
#include <ustring.h>
#include <utrace.h>

//*******************************************************
#define VER "V1.1"   //version                                     //~vaa0R~
#define PGM "xci"

#define HELPMSG         uerrhelpmsg(stdout,stderr,

#define MACRO_HELPMSG    	"HELPMSG"
#define MACRO_HELPMSG_LEN   7
#define MAX_LINESZ  	4096
#define MAX_LINESZ_MIN   64
#define MAX_LINESZ_MAX  32768
#define CH_BSTART        '{'
#define CH_BEND          '}'
#define CH_SPACE         ' '
#define CH_DQ            '\"'    //double quote
#define CH_SQ            '\''    //single quote
#define CH_STAR          '*'
#define CH_SLASH         '/'
#define CH_CONT          '\\'
#define CH_ESCAPE        '\\'
#define CH_TAB           '\t'
#define CH_TYPEELSE       '.'
#define CH_ERR            '?'
#define CH_UPDATE         '!'
#define CH_NOT            '!'                                      //~@@@4I~
#define CH_SEP            '|'
#define CH_CR             0x0d
#define CH_LF             0x0a
#define CH_LP             '('
#define CH_RP             ')'
#define CH_SEMICOLON      ';'
#define CH_STMT           'S'
#define CH_MACRO          '#'
#define CH_EOF             0x1a
#define TABSPACE " \t"
#define DEFAULT_INDCOLS     8
#define DEFAULT_TABCOLS     8
#define DEFAULT_IFELSE      1
#define MAX_INDCOLS        20
#define MAX_TABCOLS        20
#define MAX_NEST           30
#define MAX_MACRONEST      10
#define MAX_MACROPARM      20                                      //~@@@3I~
#define MACRO_DEFINED      "defined"                               //~@@@4I~
#define MACRO_OR           "||"                                    //~@@@4I~
#define MACRO_AND          "&&"                                    //~@@@4I~
#define MACRO_DEFINED_LEN  7                                       //~@@@4I~

#define TABSKIPCTR(tabskip,tabcharoffset) \
    ((tabskip)-(tabcharoffset) % (tabskip))

typedef struct _INDWORK {
			int IDWopt;
#define IDWO_1STERRMSG     0x01      //issue only 1st errmsg
#define IDWO_UPDATEFLAG    0x02      //flag updated line
#define IDWO_NOSLCSHIFT    0x04      //keep slc position if possible
#define IDWO_SPLITOK       0x08      //no errmsg for too long line
#define IDWO_KEEPWORD      0x10      //no errmsg for too long line
#define IDWO_MACROSELECT   0x20      //use macro selection  #if/#else//~@@@3I~
			int IDWstat;
#define IDWS_CONT1           	0x0001      //continued to next line(SLC,QUOTE,MLC)
#define IDWS_CONT2           	0x0002      //continued line from prev line
#define IDWS_SPLIT1          	0x0004      //line split to next line by input buffsz
#define IDWS_SPLIT2          	0x0008      //next line of SPLIT1
#define IDWS_QUOTATIONCONT   	0x0010      //quotation continued to nextline
#define IDWS_QUOTATIONCONT2  	0x0020      //quotation continued to nextline
#define IDWS_ESCAPECONT       	0x0040      //split line ended by "\"
#define IDWS_ESCAPECONT2      	0x0080      //continued line from prev line ended by "\"
#define IDWS_MLCOMMENTCONT   	0x0100      //multiline comment (/*)
#define IDWS_MLCOMMENTCONTEND	0x0200      //continued multiline comment was ended at this line
#define IDWS_MLCOMMENTONLY   	0x0400      //no data other than MLC
#define IDWS_MACROSTMT       	0x0800      //macro stmt
#define IDWS_SLCOMMENT       	0x1000      //single line comment(//) if slc noshift option
#define IDWS_SLCOMMENTCONT   	0x2000      //single line comment end width (\)
#define IDWS_SLCOMMENTONLY   	0x4000      //no data other than SLC
#define IDWS_SLCOMMENTSTAY   	0x8000      //keep slc if possible

#define IDWS_ERR              0x01000000    //line updated
#define IDWS_ERRMSG           0x02000000    //errmsgissued
#define IDWS_TAB              0x04000000    //TAB detected
#define IDWS_UPDATED          0x08000000    //line updated
#define IDWS_COPYWRITE        0x10000000    //input line copyed
#define IDWS_MACROELSE        0x20000000    //#else detected       //~@@@3I~
			int   IDWindentationcols;
			int   IDWtabskip;
			int   IDWnestlevel;
			int   IDWindLevelTop;
			int   IDWcurStmtType;
			int   IDWcontrolPnest;		//if/for/while nest () nest
			int   IDWcontrollevel;			//if/for/while nest level
			int   IDWindMacro;
			int   IDWindMacronext;
			int   IDW1stpos;           //1st detected posistion
			int   IDWslcoffs;          // "//" comment offset
			int   IDWslcoffstab;          // "//" comment offset
			int   IDWcontendoffs;       // next offs of "*/"
			int   IDWnonspaceoffs;      //1st non space/tab offset
			int   IDWnonspaceoffstab;      //1st non space/tab offset
			int   IDWlineno;
			int   IDWlinenoInMacro;      //non comment line between #if/#else/#endif macro//~@@@3R~
			int   IDWlinenoOfMacro;      //lineno of the macro     //~@@@3I~
			int   IDWmacroParmIndex;      //#if defined(),#ifdef #ifndef,#elif defined()//~@@@4I~
			int   IDWoutlineno;
			int   IDWerrlineno;
			int   IDWupdatelineno;
			char *IDWlinedata;
			int   IDWlinebuffsz;
			int   IDWdatalen;
			char *IDWscandata;
			char *IDWoutbuff;
			int   IDWoutbuffsz;
			int   IDWoutoffs;
			int (*IDWfuncRead)(struct _INDWORK *Pindwk);
			int (*IDWfuncWrite)(int Popt,struct _INDWORK *Pindwk);
			int   IDWindLevel0[MAX_NEST+2];           //indentation level at start of the nest
			int   IDWindLevel[MAX_NEST+2];            //indentation level  in the nest
			int   IDWPNest[MAX_NEST+2];               //() nest
			int   IDWblocknest[MAX_NEST+2];            //block next ctr
			int   IDWblockclosed[MAX_NEST+2];            //block closed
			int   IDWdostmt[MAX_NEST+2];               //for do while
			int   IDWstmttype[MAX_NEST+2];
			int   IDWswControlStmt[MAX_NEST+2];            //sw control stmt enclosing block
#define CS_NOSTMT      		0
#define CS_STMT        		'C'       //control stmt
#define CS_LP          		'('
#define CS_RP          		')'
#define CS_RPNEXT      		'>'
#define CS_BSTART      		'{'
#define CS_BEND        		'}'
#define CS_SINGLESTMT  		'S'
#define CS_STMTEND  		'E'
#define CS_STMTENDNEXT      'N'
		} INDWORK,*PINDWORK;
typedef int (XCI_FUNC_READ)(struct _INDWORK *Pindwk);
typedef int (XCI_FUNC_WRITE)(int Popt,struct _INDWORK *Pindwk);
#define GET_CURRENT_STMT_SW(Pindwk) \
	    (/*UTRACEP("GET_CURRENT_STMTSW line=%d,nest-1=%d,stmt=%c\n",__LINE__,Pindwk->IDWnestlevel-1,Pindwk->IDWswControlStmt[max(Pindwk->IDWnestlevel-1,0)]),*/\
		Pindwk->IDWswControlStmt[max(Pindwk->IDWnestlevel-1,0)])
#define SET_CURRENT_STMT_SW(Pindwk,PcontrolSw) \
	    (/*UTRACEP("SET_CURRENT_STMTSW line=%d,nest-1=%d,stmt=%c\n",__LINE__,Pindwk->IDWnestlevel-1,PcontrolSw),*/\
		Pindwk->IDWswControlStmt[max(Pindwk->IDWnestlevel-1,0)]=PcontrolSw)
#define CUR_NEST()    		(max(Pindwk->IDWnestlevel-1,0))
#define CUR_NESTINDWK(pindwk)    		(max(pindwk->IDWnestlevel-1,0))//~@@@3I~
#define CUR_INDLEVEL()     	(Pindwk->IDWindLevel[CUR_NEST()])
#define CUR_PNEST(nest)     (Pindwk->IDWPNest[nest])
#define INDLEVEL_UP(nest)    (/*UTRACEP("INDLEVEL_UP from %d\n",Pindwk->IDWindLevel[nest]),*/\
								(++Pindwk->IDWindLevel[nest]))
#define INDLEVEL_DOWN(nest)  (/*UTRACEP("INDLEVEL_DOWN from %d\n",Pindwk->IDWindLevel[nest]),*/\
								(Pindwk->IDWindLevel[nest]>0?--Pindwk->IDWindLevel[nest]:0))
#define SET_INDLEVEL_TOP(swtop,indlevel)	\
        if (swtop)	                              \
        	Pindwk->IDWindLevelTop=max(indlevel,0)
//*******************************************************
static char *Spgm=PGM,*Sver=VER;
static FILE *Sfh=0,*Sfho=0;
static char *Spfnm=0,*Spfnmo=0;
static long Sfilesz;
static char  Sfnmo[_MAX_PATH];
static int Supdateflag;
static int Sindcols=DEFAULT_INDCOLS;
static int Stabcols=DEFAULT_TABCOLS;
static int Sdebugmode;
static int Snoslcshift;
static int Smaxifelse=DEFAULT_IFELSE;
static int Skeepword;
static int Shelpmsg;       //for xsub/xe assume "(" after HELPMSG
static int Smaxlinesz=MAX_LINESZ;
static int Smaxbuffsz;
static int Ssplitok;
static INDWORK Sindwk;
static INDWORK  SstackIndwk[MAX_MACRONEST];
static INDWORK  SstackIndwkelse[MAX_MACRONEST];  //status at #else //~@@@3I~
static int      SstackMacroCtr[MAX_MACRONEST];   //ctr under the macro//~@@@3I~
static int      SstackParmDefined[MAX_MACRONEST];   //sw matched with -D parm//~@@@4I~
static int SstackIndwkCtr;                                         //~@@@4R~
static char *Smacroparm[MAX_MACROPARM];                            //~@@@3I~
static int  SmacroparmLen[MAX_MACROPARM];                          //~@@@4R~
static int  SmacroparmUndef[MAX_MACROPARM];                        //~@@@4I~
static int  Smacroparmctr;                                         //~@@@4R~
//**************
static char *ScontrolStmt[]={0,"if","else","elif","for","while","do","switch","case","try","catch",0};
static int ScontrolStmtLen[]={0,2,4,4,3,5,2,6,4,3,5,0};
#define CST_NONE   0      //
#define CST_IF     1      //index of if
#define CST_ELSE   2      //
#define CST_ELIF   3      //
#define CST_FOR    4      //
#define CST_WHILE  5      //
#define CST_DO     6      //
#define CST_SWITCH 7      //
#define CST_CASE   8      //
#define CST_TRY    9      //
#define CST_CATCH  10     //
#define CST_BSTART 11
#define CST_BEND   12
#define CST_LP     21
#define CST_RP     22
//**************
static char *SmacroStmt[]={0,"if","else","elif","ifdef","ifndef","endif",0};
static int SmacroStmtLen[]={0,2,4,4,5,6,5};
#define MST_NONE   0      //
#define MST_IF     1      //index of if
#define MST_ELSE   2      //
#define MST_ELIF   3      //
#define MST_IFDEF  4      //
#define MST_IFNDEF 5      //
#define MST_ENDIF  6      //
//********************************************************
void parmprechk(int parmc,char *parmp[]);
int opdchk(int Popdno,char **Ppopd);
FILE *openoutfile(char **Pppfnmo,char *Prename);
//int fmtmain();                                                   //~vaa1R~
int fmtmain(INDWORK *Pindwk);                                      //~vaa1R~
int help(int Popt);
int fmtopdchk4(char *Popd);
int opderr(char *Pparm);
XCI_FUNC_READ funcRead;
XCI_FUNC_WRITE funcWrite;
int formatDataSub(INDWORK *Pindwk);
int scanData(INDWORK *Pindwk);
int enqPrint(int Popt,INDWORK *Pindwk,char *Pdata,int Pdatalen);
int updateNest(int Popt,INDWORK *Pindwk,int Pctr,int Pstmttype);
#define EPO_FULLLINE     0x01
//#define EPO_SETBUFF      0x02
#define EPO_INDENTATION  0x03
#define EPO_SETSLC       0x04
#define EPO_FLASH        0x05
#define EPO_FUNCMASK     0xff
int xci_errmsg(int Pcase,INDWORK *Pindwk,int Prc);
#define EMO_DQCLOSE           1
#define EMO_UNDERNEST         2
#define EMO_OVERNEST          3
#define EMO_LONGLINE          4
#define EMO_LPRPUNMATCH       5
#define EMO_CASE              6
#define EMO_ELSE              7
#define EMO_BLOCKNEST         8
#define EMO_CATCH             9
#define EMO_MACRONEST        10
#define EMO_MACRONESTOVER    11
int chkTabShift(INDWORK *Pindwk,char *Pdata,int Plen,int Pindoffs,int *Ppspacectr);
int chkTabShiftSLC(int Popt,INDWORK *Pindwk,int *Ppspacectr);
int updatePNest(INDWORK *Pindwk,int Pnest,int Pctr);
int chkControlStmt(INDWORK *Pindwk,int Poffs,char *Pdata,int Plen,int *Pstmttypeindex);
int updateStmtNest(int Popt,INDWORK *Pindwk,int PswStmt,int Pnonspacetop);
#define UCSNO_ELSE            'e'   //detected "else"
#define UCSNO_STMT            'S'   //new if stmt
#define UCSNO_NEXTSTMT  	  'N'   //single stmt/block end
#define UCSNO_BSTART          '{'   //if block stmt's
#define UCSNO_BEND            '}'   //if block stmt's
#define UCSNO_CASE            'c'   //if block stmt's
#define UCSNO_LP              '('   //1st "(" for function
#define UCSNO_RP              ')'   //last ")"
#define UCSNO_WHILE           'w'   //while
#define UCSNO_TRY             't'   //try
#define UCSNO_CATCH           'h'   //catch
//#define UCSNO_BSTART2         '['   //if block stmt's
#define UCSNO_BEND2           ']'   //if block stmt's
#define UCSNO_IF              'i'   //if

#define UCSNRC_DOWHILE         4    //while of do while
#define UCSNRC_DOCLOSED        8    //retry nextstmt after while of do while
#define UCSNRC_BEND           12    //"}" is enclosed control stmt
#define UCSNRC_LPOPEN          1    //1st (
#define UCSNRC_RPCLOSE         2    //last )
int backStmtNest(int Popt,INDWORK *Pindwk,int Ptopsw);
int resetEntry(int Popt,INDWORK *Pindwk,int Pnest,int Pstmttype);
int chkMacroStmt(INDWORK *Pindwk,char *Pdata,int Plen,int Pswcont,int *Ppstmttypeindex,int *Ppparmsw);//~@@@4R~
int macroProcess(INDWORK *Pindwk,char *Pdata,int Plen,int Pswcont);//~@@@4R~
int macroContinueData(INDWORK *Pindwk,INDWORK *Pfrom);
int macroSelection(INDWORK *Pindwk,int Pstmttype,int Pparmdefined,INDWORK **Ppindwksaved);//~@@@3R~//~@@@4R~
int macroSelectionSub(INDWORK *Pindwk);                            //~@@@3I~
int chkMacroText(INDWORK *Pindwk,int Pstmttype,char *Pdata,int Plen,int Pswcont);//~@@@4R~
int srchMacroParm(char *Pdata,int Plen,int *Ppundef);              //~@@@4R~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int main(int parmc,char * parmp[])
{
    int rc,buffsz1;                                                //~@@@5R~
	char pgmver[16];
    char *buff3,*buff1,*buff2;
//*********************************
	Sfho=stdout;
	sprintf(pgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);
	uerrmsg_init(pgmver,stderr,0);//msg to stderr
	uerrexit_init(pgmver,stderr,0,0,0);//stderr only,no pathmsg
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit
    memset(&Sindwk,0,sizeof(Sindwk));
	parmprechk(parmc,parmp);
    if (rc=opdchk(parmc,parmp),rc)
    	return rc;                      //err
    Smaxbuffsz=Smaxlinesz*2;
    if (Spfnmo)
        Sfho=openoutfile(&Spfnmo,Sfnmo);
    else
    	Spfnmo="stdout";
    Sindwk.IDWindentationcols=Sindcols;
    Sindwk.IDWtabskip=Stabcols;
    if (Supdateflag)
        Sindwk.IDWopt|=IDWO_UPDATEFLAG;
    if (Snoslcshift)
        Sindwk.IDWopt|=IDWO_NOSLCSHIFT;     //keep slc position if possible
    if (Skeepword)
        Sindwk.IDWopt|=IDWO_KEEPWORD;     //keep slc position if possible
    if (Ssplitok)
        Sindwk.IDWopt|=IDWO_SPLITOK;
    buffsz1=Smaxlinesz+2;	//redundancy for ufreads(1 for crlf split,1 for optionally last null)//~@@@5R~
//  buff1=umalloc(buffsz1);                                        //~@@@5I~//~vaa0R~
    buff1=umalloc((size_t)buffsz1);                                //~vaa0I~
    UALLOCCHK(buff1,UALLOC_FAILED);
    if (Sdebugmode)
    {
//  	buff2=umalloc(Smaxlinesz);                                 //~@@@5R~//~vaa0R~
    	buff2=umalloc((size_t)Smaxlinesz);                         //~vaa0I~
    	UALLOCCHK(buff2,UALLOC_FAILED);
    }
    else
    	buff2=0;	//no scan data
//  buff3=umalloc(Smaxbuffsz);                                     //~vaa0R~
    buff3=umalloc((size_t)Smaxbuffsz);                             //~vaa0I~
    UALLOCCHK(buff3,UALLOC_FAILED);
    Sindwk.IDWlinedata=buff1;
    Sindwk.IDWlinebuffsz=buffsz1;                                  //~@@@5R~
    Sindwk.IDWscandata=buff2;
    Sindwk.IDWoutbuff=buff3;
    Sindwk.IDWoutbuffsz=Smaxbuffsz;
    Sindwk.IDWfuncRead=funcRead;
    Sindwk.IDWfuncWrite=funcWrite;
    Sindwk.IDWnestlevel=1;
	Sindwk.IDWopt|=IDWO_MACROSELECT;     //use macro selection  #if/#else//~@@@3I~
    rc=fmtmain(&Sindwk);
    if (!rc)
    {
		uerrmsg("*** Done *** %s read:% 4d, update=% 4d, err=%d",0,//~@@@5R~
       			Spfnm,Sindwk.IDWlineno,Sindwk.IDWupdatelineno,Sindwk.IDWerrlineno);//~@@@5R~
		if (Sindwk.IDWerrlineno)
			rc=4;
    }
	if (rc)
		ubell();
    fclose(Sfh);                                                   //~@@@5I~
  if (Sfho!=stdout)                                                //+vas3I~
    fclose(Sfho);                                                  //~@@@5I~
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
    return rc;
}//main
//****************************************************************
// format
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
int fmtmain(INDWORK *Pindwk)
{
	int    rc=0;
//*********************************
//chk field width 
    for (;;)
    {
      	if (Pindwk->IDWfuncRead(Pindwk)<0)
        	break;
        if (rc=formatDataSub(Pindwk),rc)
        {
            if (rc>4)
                break;
        }
	}//all plh
    return rc;
}//fmtmain
//****************************************************************
// comment /* or // is effective one of first detected
// /* and // in dquote is not comment starter
// but after /*, */ in quate is effective as comment end
// (")quote bay continue to next line
//****************************************************************
int formatDataSub(INDWORK *Pindwk)
{
    int rlen,rlen0;
    char  *pc,*pc0;
//****************************************
    pc=pc0=Pindwk->IDWlinedata;
    rlen=rlen0=Pindwk->IDWdatalen;
    for (;;)
    {
        scanData(Pindwk);	//flag comment and quotation data
//  	if (Pindwk->IDWstat & (IDWS_MLCOMMENTONLY|IDWS_SLCOMMENTONLY|IDWS_MACROSTMT))
    	if (Pindwk->IDWstat & (IDWS_MLCOMMENTONLY|IDWS_SLCOMMENTONLY))
        {
        	enqPrint(EPO_FULLLINE,Pindwk,0,0);	//full line write
            break;
    	}
    	if (Pindwk->IDWstat & IDWS_CONT2)	//continued line from prev line
        {
        	enqPrint(EPO_FULLLINE,Pindwk,0,0);	//full line write
            break;
    	}
//*contains "//"
    	if (Pindwk->IDWstat & IDWS_SLCOMMENTSTAY)
        {
        	rlen=Pindwk->IDWslcoffs;	//write after
        }
//*after (../*..)
//        if (Pindwk->IDWstat & IDWS_MLCOMMENTCONTEND)     // prev line "/*" enclosed by "*/"
//        {
//            offs=Pindwk->IDWcontendoffs;
//            enqPrint(EPO_SETBUFF,Pindwk,pc,offs);   //full line write
//            rlen-=offs;
//            pc+=offs;
//        }
        enqPrint(EPO_INDENTATION,Pindwk,pc,rlen);
        if (!(Pindwk->IDWstat&IDWS_COPYWRITE))	//not case of indentation write input copy because shift not occured
        {
            if (Pindwk->IDWstat & IDWS_SLCOMMENTSTAY)
            {
                enqPrint(EPO_SETSLC,Pindwk,0,0);    //full line write
            }
            enqPrint(EPO_FLASH,Pindwk,0,0);
        }
        break;
    }
	return 0;
}//formatDataSub
//****************************************************************
// scan data to chk comment, quotation, { ,}, continuation
//set 1st ({) , (}) , (//) position
//*rc:0x04: nest level dwon to minus,0x08: dquote not enclosed
//****************************************************************
int scanData(INDWORK *Pindwk)
{
	char *pc,*pc0,*pco,*pco0,ch,*pc2;
    int swSq=0,swDq=0,swEscape=0,rlen,swCont=0,swSlc=0,swMlc=0;
    int contendoffs=-1,rc=0,offs=0,offsaddtab=0,tabskip;
    int nonspaceoffs=-1,nonspaceoffsNonMlc=-1;                     //~@@@3R~
    int cslen,swControlStmt,swElse,stmttypeindex,step,rc2;
    int swMlcStart=0,swMlcEnd=0,offsMlcEnd=-1,swSplit1=0,swMacro=0;
//*************************
    UTRACED("scandata inp",Pindwk->IDWlinedata,Pindwk->IDWdatalen);
    pc=pc0=Pindwk->IDWlinedata;
    rlen=Pindwk->IDWdatalen;
	pco=pco0=Pindwk->IDWscandata;

	Pindwk->IDWstat&=~(IDWS_SLCOMMENT
						|IDWS_QUOTATIONCONT2
						|IDWS_CONT2
            			|IDWS_UPDATED
            			|IDWS_ERR
            			|IDWS_COPYWRITE
            			|IDWS_MLCOMMENTONLY
            			|IDWS_SLCOMMENTONLY
            			|IDWS_SLCOMMENTSTAY
            			|IDWS_ESCAPECONT2
						|IDWS_TAB);
    Pindwk->IDWindLevelTop=CUR_INDLEVEL();
    Pindwk->IDWindMacro=Pindwk->IDWindMacronext;
    UTRACEP("scandata inp lineno=%d,nest=%d,indlevel=%d\n",Pindwk->IDWlineno,CUR_NEST(),Pindwk->IDWindLevelTop);
    tabskip=Pindwk->IDWtabskip;

    if (Pindwk->IDWstat & IDWS_QUOTATIONCONT)
    {
		Pindwk->IDWstat&=~IDWS_QUOTATIONCONT;
		Pindwk->IDWstat|=IDWS_CONT2|IDWS_QUOTATIONCONT2;
    	swDq=1;
    }
    if (Pindwk->IDWstat & IDWS_SLCOMMENTCONT)	// prev line // end with '\'
    {
		Pindwk->IDWstat&=~IDWS_SLCOMMENTCONT;
		Pindwk->IDWstat|=IDWS_CONT2|IDWS_SLCOMMENTONLY;
    	swSlc=1;
    }
    if (Pindwk->IDWstat & IDWS_MLCOMMENTCONT)	// prev line // end with '\'
    {
		Pindwk->IDWstat|=IDWS_CONT2;
    	swMlc=2;	// assume "/*" detected
        swMlcStart=1;
    }
    if (Pindwk->IDWstat & IDWS_CONT1)	// prev line cont to next line
    {
		Pindwk->IDWstat|=IDWS_CONT2;    //this is cont line from prev
    	Pindwk->IDWstat &=~IDWS_CONT1;	//reset cont to next line
    }
    if (Pindwk->IDWstat & IDWS_SPLIT1)	//no CRLF was reda
    {
    	swSplit1=1;
		Pindwk->IDWstat|=IDWS_CONT1;    //this is cont to next line
    }
    else
    if (rlen && *(pc+rlen-1)==CH_ESCAPE)
    {
        swCont=1;
        rlen--;             //chk at last
    }
    if (Pindwk->IDWstat & IDWS_SPLIT2)	// this is next line of previous
		Pindwk->IDWstat|=IDWS_CONT2;
	if (Pindwk->IDWstat & IDWS_CONT2)   //2nd line of split or cont sign(\)
    {
    	if (Pindwk->IDWstat & IDWS_MACROSTMT)	// prev line is macro stmt
			swMacro=2;        //macro cont line
    }
    else                                        //single or 1st of split
    	Pindwk->IDWstat &= ~IDWS_MACROSTMT;	//MACRO STMT is used for enqPrint
    if (Pindwk->IDWstat & IDWS_ESCAPECONT)
    {
        swEscape=1;
		Pindwk->IDWstat &=~IDWS_ESCAPECONT;
		Pindwk->IDWstat |= IDWS_ESCAPECONT2;
    }
    Pindwk->IDWnonspaceoffs=-1;
    for (;rlen>0;rlen-=step,pc+=step,pco+=step,offs+=step)
    {
    	if (swMacro==2)    //macro continued line
        	break;
    	step=1;
        ch=*pc;
    	if (ch==CH_ESCAPE)
        {
        	if (!swMlc)
        		swEscape=~swEscape;
        }
        else
        {
            switch(ch)
            {
            case CH_SQ:
                if (!swEscape&&!swMlc&&!swDq)
                {
                	if (swSq)
                    	swSq=2;	//close
                    else
                    	swSq=1; //start
                }
                break;
            case CH_DQ:
                if (!swEscape&&!swMlc&&!swSq)
                {
                	if (swDq)
                    	swDq=2; //close
                    else
                    	swDq=1; //start
                }
                break;
            case CH_SLASH:
            	if (swMlc==3)      // after "/*...*"
                	swMlc=4;
                else
                if (rlen>0)
                {
					if (*(pc+1)==CH_SLASH) // 1st "/" of "//"
                    {
                        if (!swMlc&&!swDq)
                        {
                            swSlc=1;       //SLC start
                            if (nonspaceoffs<0) //"/" is first nonspace
								Pindwk->IDWstat|=IDWS_SLCOMMENTONLY;
                        }
                    }
                    else
                	if (*(pc+1)==CH_STAR)  // "/" of "/*"
                    {
                        if (!swMlc&&!swDq)
                        {
UTRACEP("scanData MLC start nonspaceoffs=%d,offs=%d\n",nonspaceoffs,offs);
                            if (nonspaceoffs<0) //"/" is first nonspace
                                swMlcStart=1;
                            swMlc=1;      //MLC start
                        }
                    }
                }
                break;
            case CH_MACRO:
                if (nonspaceoffs<0) //"/" is first nonspace
                    if (!swDq&&!swMlc)
                    {
                        Pindwk->IDWstat|=IDWS_MACROSTMT;
                        swMacro=1;
                        macroProcess(Pindwk,pc+1,rlen-1,swCont);   //~@@@4R~
                    }
                break;
            case CH_STAR:
            	if (swMlc==1)      // 2nd of "/*"
                	swMlc=2;       //until "*/"
                else
                if (rlen>0 && *(pc+1)==CH_SLASH)	//	"*/"
                {
                    if (!swDq)
						if (swMlc==2)   // "/*...*/"
                        	swMlc=3;  	//until next "/" of "*/"
                }
                break;
            case CH_BSTART:   //"{"
                if (!swDq&&!swSq&&!swMlc&&!swMacro)
                {
					swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
		        	if (swControlStmt==CS_STMTENDNEXT)  //pendig next of stmt
                    {
						backStmtNest(0/*not controlStmt*/,Pindwk,(nonspaceoffs<0));
						swControlStmt=GET_CURRENT_STMT_SW(Pindwk);	//nest may be changed
                    }
//                    if (swControlStmt==CS_RPNEXT)
//                    {
						updateStmtNest(UCSNO_BSTART,Pindwk,swControlStmt,(nonspaceoffs<0));
						SET_CURRENT_STMT_SW(Pindwk,CS_BSTART);
//                    }
//                    else
//                        updateStmtNest(UCSNO_BSTART2,Pindwk,swControlStmt,(nonspaceoffs<0));
		        	if (pco0)
        				*pco=ch;
UTRACEP("scanData CH_BSTART swControlStmt=%c,nest=%d,indlevel=%d\n",swControlStmt,CUR_NEST(),CUR_INDLEVEL());
                }
                break;
            case CH_BEND:     //"}"
                if (!swDq&&!swSq&&!swMlc&&!swMacro)
                {
UTRACEP("scanData CH_BEND swControlStmt=%c of nest=%d\n",GET_CURRENT_STMT_SW(Pindwk),CUR_NEST());
					swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
#ifdef AAA
		        	if (swControlStmt==CS_STMTENDNEXT)
						backStmtNest(0/*not controlStmt*/,Pindwk,(nonspaceoffs<0));
#endif
					rc2=updateStmtNest(UCSNO_BEND,Pindwk,swControlStmt,(nonspaceoffs<0));
                    if (rc2==UCSNRC_BEND)	//control stmt closed
						SET_CURRENT_STMT_SW(Pindwk,CS_STMTEND);
UTRACEP("scanData CH_BEND rc2=%d,swControlStmt=%c of nest=%d\n",rc2,GET_CURRENT_STMT_SW(Pindwk),CUR_NEST());
		        	if (pco0)
        				*pco=ch;
                }
                break;
            case CH_LP:  	//"("
            case CH_RP:  	//")"
                if (!swDq&&!swSq&&!swMlc&&!swMacro)
                {
					swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
		        	if (swControlStmt==CS_STMTENDNEXT)  //pendig next of stmt
                    {
						backStmtNest(0/*not controlStmt*/,Pindwk,(nonspaceoffs<0));
						swControlStmt=GET_CURRENT_STMT_SW(Pindwk);	//nest may be changed
                    }
					rc2=updateStmtNest(ch,Pindwk,swControlStmt,(nonspaceoffs<0));
                    if (swControlStmt==CS_STMT)
                    {
	                    if (rc2==UCSNRC_RPCLOSE)
							SET_CURRENT_STMT_SW(Pindwk,CS_RP);
                    }
#ifdef AAA  //SINGLE_STMT was deleted
                    else
						SET_CURRENT_STMT_SW(Pindwk,CS_NOSTMT);
#endif
UTRACEP("scanData CH_LP/RP updateContrstatementPnest\n");
                }
                break;
            case CH_SEMICOLON:
                if (!swDq&&!swSq&&!swMlc&&!swMacro)
                {
					swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
	            	if (swControlStmt==CS_SINGLESTMT
	            	||  swControlStmt==CS_RPNEXT)      //null stmt(";" only)
						SET_CURRENT_STMT_SW(Pindwk,CS_STMTEND);
		        	if (pco0)
        				*pco=ch;
UTRACEP("scanData SEMICOLON wsControlStmt=%c,new=%d\n",swControlStmt,GET_CURRENT_STMT_SW(Pindwk));
                }
                break;
            case CH_TAB:
	        	if (pco0)
    	    		*pco=CH_TAB;
            	Pindwk->IDWstat|=IDWS_TAB;
            	offsaddtab+=TABSKIPCTR(tabskip,offs+offsaddtab)-1;
                break;
            case CH_SPACE:
                if (!swDq&&!swSq&&!swMlc)
		        	if (pco0)
        				*pco=CH_SPACE;
                break;
            default:
                if (!swDq&&!swSq&&!swMlc)
		        	if (pco0)
        				*pco=CH_TYPEELSE;
            }
            swEscape=0;
        }
        if (swSlc)
        	break;   //clear followings
//      if (swMacro)
//      	break;
        if (swDq)
        {
        	if (pco0)
	        	*pco=CH_DQ;
            if (swDq==2)
            {
    			if (Pindwk->IDWstat & IDWS_QUOTATIONCONT2)	// quotation cont from top of line
                	if (contendoffs<0)
                    {
	    				Pindwk->IDWcontendoffs=contendoffs=offs+1;
                    }
            	swDq=0;
            }
        }
        else
        if (swSq)
        {
        	if (pco0)
        		*pco=CH_SQ;
            if (swSq==2)
            {
            	swSq=0;
            }
        }
        else
        if (swMlc)
        {
        	if (pco0)
        		*pco=CH_STAR;
            if (swMlc==4)	//reached to "/" of "*/"
            {
    			if (Pindwk->IDWstat & IDWS_MLCOMMENTCONT)	// mlcomment from top of line
                {
                	if (contendoffs<0)
                    {
	    				Pindwk->IDWcontendoffs=contendoffs=PTRDIFF(pc,pc0)+1;
		    			Pindwk->IDWstat|=IDWS_MLCOMMENTCONTEND;
		    			Pindwk->IDWstat&=~IDWS_MLCOMMENTCONT;
                    }
                }
            	swMlc=5;    //clear at next                        //~@@@3R~
                offsMlcEnd=offs+1;
                swMlcEnd=1;
UTRACEP("scanData MLC end offs=%d\n",offs);
            }
        }
        if (ch==CH_SPACE)
        {
//      	step=umemspnc(pc,CH_SPACE,rlen);                       //~vaa0R~
        	step=(int)umemspnc(pc,CH_SPACE,(unsigned)rlen);        //~vaa0I~
		    if (pco0)
//          	memset(pco,CH_SPACE,step);                         //~vaa0R~
            	memset(pco,CH_SPACE,(size_t)step);                 //~vaa0I~
        }
        else
        if (ch==CH_TAB)
        	;
        else
        if (ch!=CH_SPACE&&ch!=CH_TAB)
        {
        	if (nonspaceoffs<0)
            {
            	Pindwk->IDWnonspaceoffs=nonspaceoffs=offs;
            	Pindwk->IDWnonspaceoffstab=nonspaceoffs+offsaddtab;
            }
        	if (nonspaceoffsNonMlc<0 && !swMlc && !swMacro)        //~@@@3R~
            {                                                      //~@@@3I~
        		nonspaceoffsNonMlc=offs;                           //~@@@3I~
            	Pindwk->IDWlinenoInMacro++;                        //~@@@3I~
            }                                                      //~@@@3I~
            if (offsMlcEnd>=0 && offs>=offsMlcEnd)
            	swMlcEnd=0;		//nonspace after "*/" or slc only
            if (!swDq&&!swSq&&!swMlc&&!swMacro)
            {
				swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
            UTRACEP("nonspace swControlStmt=%c,pc=%s,nonspaceoffs=%d\n",swControlStmt,pc,nonspaceoffs);
	            if (swControlStmt==CS_RP)   //")" after control stmt
                {
					SET_CURRENT_STMT_SW(Pindwk,CS_RPNEXT);
                }
                else
                if (swControlStmt==CS_STMTEND)
                {
					SET_CURRENT_STMT_SW(Pindwk,CS_STMTENDNEXT);
                }
                else
                if (ch!=CH_BSTART&&ch!=CH_BEND)  //swControlStmt=0 if CH_BSTART
                {
                    cslen=chkControlStmt(Pindwk,offs,pc,rlen,&stmttypeindex);
                    if (cslen>0)
                    {
                    	swElse=(stmttypeindex==CST_ELSE||stmttypeindex==CST_ELIF);
                        if (swElse)  //else/elif
                        {
							updateStmtNest(UCSNO_ELSE,Pindwk,swControlStmt,(offs==nonspaceoffs));
							SET_CURRENT_STMT_SW(Pindwk,CS_RPNEXT);
                        }
                        else
                    	if (stmttypeindex==CST_CATCH) //before NEXTSTMT process
                        {
							updateStmtNest(UCSNO_CATCH,Pindwk,swControlStmt,(offs==nonspaceoffs));
							SET_CURRENT_STMT_SW(Pindwk,CS_STMT); //next is ()
                        }
                        else
                        {
                            rc2=0;
                    		if (stmttypeindex==CST_WHILE)
                            {
								rc2=updateStmtNest(UCSNO_WHILE,Pindwk,swControlStmt,(offs==nonspaceoffs));
                                if (rc2==UCSNRC_DOWHILE)              //while is not while {} stmt
									SET_CURRENT_STMT_SW(Pindwk,CS_SINGLESTMT);
                            }
                            if (!rc2)
                            {
                                if (swControlStmt==CS_STMTENDNEXT)
                                {
                                    backStmtNest(1/*controlStmt*/,Pindwk,(offs==nonspaceoffs));
									swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
                                }
                                if (stmttypeindex==CST_CASE)
                                {
                                    updateStmtNest(UCSNO_CASE,Pindwk,swControlStmt,(offs==nonspaceoffs));
                    UTRACEP("CST_CASE indlevel=%d,nest=%d,nonspaceoffs=%d,offs=%d\n",CUR_INDLEVEL(),CUR_NEST(),nonspaceoffs,offs);
                                }
                                else
                                {
                                    updateStmtNest(UCSNO_STMT,Pindwk,swControlStmt,(offs==nonspaceoffs));
                                    if (stmttypeindex==CST_DO)
                                        SET_CURRENT_STMT_SW(Pindwk,CS_RPNEXT);  //no () is fllowed
                                    else
                                    if (stmttypeindex==CST_TRY)
                                        SET_CURRENT_STMT_SW(Pindwk,CS_RPNEXT);  //no () is fllowed
                                    else
                                        SET_CURRENT_STMT_SW(Pindwk,CS_STMT);
                                }
                            }
                        }
                        step=cslen;
					    if (pco0)
//          				memset(pco,CH_STMT,cslen);             //~vaa0R~
            				memset(pco,CH_STMT,(size_t)cslen);     //~vaa0I~
                    }
                    else	//not control stmt
                    {
                    	if (swControlStmt==CS_STMTENDNEXT)
                    	{
							backStmtNest(0,Pindwk,(offs==nonspaceoffs));
							swControlStmt=GET_CURRENT_STMT_SW(Pindwk);
                    	}
                        else
                        if (swControlStmt==CS_RPNEXT)
                        {
							SET_CURRENT_STMT_SW(Pindwk,CS_SINGLESTMT);
                        }
                        if (cslen<0)	//HELPMSG
                        {
							updateStmtNest(CH_LP,Pindwk,swControlStmt,(offs==nonspaceoffs));
							SET_CURRENT_STMT_SW(Pindwk,CS_NOSTMT);
                            step=-cslen;
                        }
                        else
                        {
                            if (isalpha(ch))
                            {
                                for (step=1,pc2=pc+1;step<rlen;step++)
                                {
                                    ch=*pc2++;
                                    if (!isalnum(ch))
                                        break;
                                }
                            }
                            else
                            if (ch>='0' && ch<='9')
                            {
                                for (step=1,pc2=pc+1;step<rlen;step++)
                                {
                                    ch=*pc2++;
                                    if (ch<'0' || ch>'9')
                                        break;
                                }
                            }
                        }
                    }//not control stmt
                }
            }
        }
        if (swMlc==5)
            swMlc=0;      //after last "/" of /*... */
    }//for
    if (swSlc)
    {
        if (pco0)
//      	memset(pco,CH_SLASH,rlen);                             //~vaa0R~
        	memset(pco,CH_SLASH,(size_t)rlen);                     //~vaa0I~
        Pindwk->IDWslcoffs=offs;
        Pindwk->IDWslcoffstab=offs+offsaddtab;
		Pindwk->IDWstat|=IDWS_SLCOMMENT;     //copy SLC after indent
        if (Pindwk->IDWopt & IDWO_NOSLCSHIFT)     //keep slc position if possible
			Pindwk->IDWstat|=IDWS_SLCOMMENTSTAY;     //copy SLC after indent
        pc+=rlen;
        pco+=rlen;
    }
UTRACEP("scanData MLC swMlcStart=%d,swMlcEnd=%d\n",swMlcStart,swMlcEnd);
    if (swMlcStart && (swMlc || swMlcEnd))
		Pindwk->IDWstat|=IDWS_MLCOMMENTONLY;
    if (swMlc)
    	Pindwk->IDWstat|=IDWS_MLCOMMENTCONT|IDWS_CONT1;
    if (swCont)  //ended by "\"
    {
//last "\\" is not one "\" but one "\" and continuation
//        if (swEscape)
//        {
//            if (pco0)
//                *pco=CH_TYPEELSE;
//            swCont=0;    //eol is "\\"
//        }
//        else
//        {
            if (swDq)
                Pindwk->IDWstat|=IDWS_QUOTATIONCONT;
            else
            if (swSlc)
                Pindwk->IDWstat|=IDWS_SLCOMMENTCONT;
            Pindwk->IDWstat|=IDWS_CONT1;
	        if (pco0)
            	*pco++=CH_CONT;
//        }
    }
    else
    if (swSplit1) 	//split to next line
    {
    	if (swEscape)
        {
        	Pindwk->IDWstat|=IDWS_ESCAPECONT;
        }
        else
        {
            if (swDq)
                Pindwk->IDWstat|=IDWS_QUOTATIONCONT;
            else
            if (swSlc)
                Pindwk->IDWstat|=IDWS_SLCOMMENTCONT;
        }
    }
    if (!swCont && !swSplit1)
    {
    	if (swDq||swSq)
			rc|=xci_errmsg(EMO_DQCLOSE,Pindwk,8);
    }
	UTRACED("scandata out",pco0,Pindwk->IDWdatalen);
	UTRACEP("scandata lineno=%d,stat=%x,slcoffs=%d,rc=%d\n",Pindwk->IDWlineno,Pindwk->IDWstat,Pindwk->IDWslcoffs,rc);//~vas1R~
//  return 0;                                                      //~vas1R~
    return rc;                                                     //~vas1I~
}//scanData
//*****************************************************************
//*stack INDWORK by #if and unstack by #else
//*return stmt len
//*****************************************************************
int macroProcess(INDWORK *Pindwk,char *Pdata,int Plen,int Pswcont) //~@@@4R~
{
    int stmttype,rc=0,rc2,linectrMacro,parmdefined;                            //~@@@3R~//~@@@4R~
	INDWORK *pindwk,*pindwksaved;                                  //~@@@3R~
//********************************
	if (!chkMacroStmt(Pindwk,Pdata,Plen,Pswcont,&stmttype,&parmdefined))//~@@@4R~
    	return 0;         //#define etc
	linectrMacro=Pindwk->IDWlinenoInMacro;                         //~@@@3I~
UTRACEP("macroProcess before ctr=%d,nest=%d,indelevel=%d,stmtsw=%c,macroctr=%d,parmdef=%d\n",SstackIndwkCtr,CUR_NEST(),CUR_INDLEVEL(),GET_CURRENT_STMT_SW(Pindwk),linectrMacro,parmdefined);//~@@@3I~//~@@@4R~
    Pindwk->IDWlinenoOfMacro=Pindwk->IDWlineno;	                   //~@@@3I~
    switch(stmttype)
    {
	case MST_ELIF:
	case MST_ELSE:
    	if (!SstackIndwkCtr)
			rc=xci_errmsg(EMO_MACRONEST,Pindwk,-4);
        else
        {
			SstackMacroCtr[SstackIndwkCtr-1]+=linectrMacro;  //#if //~@@@3R~
            if (SstackIndwkCtr>1)                                  //~@@@3R~
				SstackMacroCtr[SstackIndwkCtr-2]+=linectrMacro;	//accum ton higher level//~@@@3I~
			if (Pindwk->IDWopt&IDWO_MACROSELECT)    //use macro selection  #if/#else//~@@@3I~
				macroSelection(Pindwk,stmttype,parmdefined,0);                 //~@@@3R~//~@@@4R~
	    	pindwk=SstackIndwk+(SstackIndwkCtr-1);
            macroContinueData(pindwk,Pindwk);	//copy data to be continued
    		*Pindwk=*pindwk;
			SstackMacroCtr[SstackIndwkCtr-1]=0;                    //~@@@3I~
        }
        break;
	case MST_ENDIF:
    	if (!SstackIndwkCtr)
			rc=xci_errmsg(EMO_MACRONEST,Pindwk,-4);
        else
        {                                                          //~@@@3I~
			SstackMacroCtr[SstackIndwkCtr-1]+=linectrMacro;	//of #else//~@@@3R~
            if (SstackIndwkCtr>1)                                  //~@@@3I~
				SstackMacroCtr[SstackIndwkCtr-2]+=linectrMacro;    //~@@@3I~
			if (Pindwk->IDWopt&IDWO_MACROSELECT)    //use macro selection  #if/#else//~@@@3I~
            {                                                      //~@@@3I~
				rc2=macroSelection(Pindwk,stmttype,0/*parmdefined*/,&pindwksaved);  //~@@@3R~//~@@@4R~
                if (rc2==1)   //select #if                         //~@@@3I~
                {                                                  //~@@@3I~
		            macroContinueData(pindwksaved,Pindwk);	//copy data to be continued//~@@@3I~
		    		*Pindwk=*pindwksaved;                          //~@@@3I~
                }                                                  //~@@@3I~
            }                                                      //~@@@3I~
    		SstackIndwkCtr--;
        }                                                          //~@@@3I~
    	Pindwk->IDWindMacro=SstackIndwkCtr;
        break;	//continue
	default:        //if,ifdef,ifndef
    	if (SstackIndwkCtr==MAX_MACRONEST)
			rc=xci_errmsg(EMO_MACRONESTOVER,Pindwk,-4);
        else
        {                                                          //~@@@3I~
            if (SstackIndwkCtr)                                    //~@@@3I~
				SstackMacroCtr[SstackIndwkCtr-1]+=linectrMacro;    //~@@@3I~
    		SstackIndwkelse[SstackIndwkCtr].IDWstat&=~IDWS_MACROELSE;//~@@@3R~
			SstackMacroCtr[SstackIndwkCtr]=0;                      //~@@@3I~
			SstackParmDefined[SstackIndwkCtr]=parmdefined;         //~@@@4I~
    		SstackIndwk[SstackIndwkCtr++]=*Pindwk;
        }                                                          //~@@@3I~
    }
    Pindwk->IDWlinenoInMacro=0;                                    //~@@@3I~
    Pindwk->IDWindMacronext=SstackIndwkCtr;
UTRACEP("macroProcess after parmdefined=%d, ctr=%d,nest=%d,indmacro=%d,stmtsw=%c,parmdefined=%d\n",parmdefined,SstackIndwkCtr,CUR_NEST(),Pindwk->IDWindMacro,GET_CURRENT_STMT_SW(Pindwk),parmdefined);//~@@@4R~
    return rc;
}//macroProcess
//*****************************************************************//~@@@3I~
//*stack INDWORK for path selection of #if or #else                //~@@@3I~
//*return stmt len                                                 //~@@@3I~
//*****************************************************************//~@@@3I~
int macroSelection(INDWORK *Pindwk,int Pstmttype,int Pparmdefined,INDWORK **Ppindwksaved)//~@@@3R~//~@@@4R~
{                                                                  //~@@@3I~
    int rc=0,linectrMacro,parmdefined;                                         //~@@@3R~//~@@@4R~
//  INDWORK *pindwkif,*pindwkelse;                                 //~@@@3R~//~va76R~
    INDWORK           *pindwkelse;                                 //~va76I~
//********************************                                 //~@@@3I~
	linectrMacro=SstackMacroCtr[SstackIndwkCtr-1];                 //~@@@3I~
//  pindwkif=SstackIndwk+(SstackIndwkCtr-1);                       //~va76R~
    pindwkelse=SstackIndwkelse+(SstackIndwkCtr-1);                 //~@@@3I~
    parmdefined=SstackParmDefined[SstackIndwkCtr-1];               //~@@@4R~
UTRACEP("macroProcessSelection stmttype=%d,linenoInMacro=%d,macroelsesw=%d,parmdefined=%d,oldparmdefined=%d\n",Pstmttype,linectrMacro,(pindwkelse->IDWstat&IDWS_MACROELSE)!=0,Pparmdefined,parmdefined);    //status after #if by else//~@@@3R~//~@@@4R~
    switch(Pstmttype)                                              //~@@@3R~
    {                                                              //~@@@3I~
	case MST_ELIF:                                                 //~@@@4I~
        if (parmdefined>0)	//match at previous #if/#elif          //~@@@4I~
        {                                                          //~@@@4I~
        	if (parmdefined<MAX_MACROPARM)                         //~@@@4R~
            {                                                      //~@@@4I~
    			SstackParmDefined[SstackIndwkCtr-1]=MAX_MACROPARM;	//saved//~@@@4I~
        		rc=1;	//save current                             //~@@@4I~
UTRACEP("macroProcess  #elif previously match Set1 defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
            }                                                      //~@@@4I~
UTRACEP("macroProcess  #elif previously match Set2 defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
        }                                                          //~@@@4I~
        else                                                       //~@@@4I~
        {                                                          //~@@@4I~
            if (Pparmdefined)                                      //~@@@4I~
            {                                                      //~@@@4I~
				SstackParmDefined[SstackIndwkCtr-1]=Pparmdefined;	//select #else//~@@@4R~
UTRACEP("macroProcess #elif text match defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
			}                                                      //~@@@4I~
            else                                                   //~@@@4I~
            {                                                      //~@@@4I~
                if (!linectrMacro)                                         //~@@@3R~//~@@@4I~
                    break;                                                 //~@@@3I~//~@@@4I~
                if (pindwkelse->IDWstat & IDWS_MACROELSE)   //once saved(#elif)//~@@@3I~//~@@@4R~
                {                                                          //~@@@3I~//~@@@4R~
                    if (macroSelectionSub(Pindwk))  //this entry to be selected                       //~@@@3I~//~@@@4R~
                    {                                                      //~@@@3I~//~@@@4R~
                        rc=1;                                      //~@@@4R~
    UTRACEP("macroProcess update save #elif by #elif ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@3R~//~@@@4R~
                    }                                                      //~@@@3I~//~@@@4R~
                }                                                          //~@@@3I~//~@@@4R~
                else                                                       //~@@@3I~//~@@@4R~
                {                                                  //~@@@4R~
                    rc=1;                                          //~@@@4R~
        UTRACEP("macroProcess update by ist #elif by  ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@3R~//~@@@4R~
                }                                                          //~@@@3I~//~@@@4R~
            }                                                      //~@@@4I~
        }                                                          //~@@@4I~
        if (rc==1)                                                 //~@@@4I~
        {                                                          //~@@@4I~
            *pindwkelse=*Pindwk;                                   //~@@@4I~
            pindwkelse->IDWstat|=IDWS_MACROELSE;    //status after #if by else//~@@@4I~
        }                                                          //~@@@4I~
        break;                                                     //~@@@3I~
	case MST_ELSE:                                                 //~@@@4I~
        if (parmdefined>0)	//match at previous #if/#elif          //~@@@4I~
        {                                                          //~@@@4I~
        	if (parmdefined<MAX_MACROPARM)                         //~@@@4I~
            {                                                      //~@@@4I~
    			SstackParmDefined[SstackIndwkCtr-1]=MAX_MACROPARM;	//saved//~@@@4I~
        		rc=1;	//save current                             //~@@@4I~
UTRACEP("macroProcess  #else previously match Set1 defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
            }                                                      //~@@@4I~
UTRACEP("macroProcess  #else previously match Set2 defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
        }                                                          //~@@@4I~
        else                                                       //~@@@4I~
        if (parmdefined<0)	//match at previous #if/#elif          //~@@@4I~
        {                                                          //~@@@4I~
    		SstackParmDefined[SstackIndwkCtr-1]=-parmdefined;   //save #else at #endif//~@@@4I~
UTRACEP("macroProcess  #else previously ! match defined=%d,old=%d\n",Pparmdefined,parmdefined);//~@@@4I~
        }                                                          //~@@@4I~
        else                                                       //~@@@4I~
        {                                                          //~@@@4I~
            if (!linectrMacro)                                     //~@@@4I~
            {                                                      //~@@@4I~
    UTRACEP("macroProcess update #else no line\n");                //~@@@4I~
                break;                                             //~@@@4I~
            }                                                      //~@@@4I~
            if (pindwkelse->IDWstat & IDWS_MACROELSE)   //once saved(#elif)//~@@@4R~
            {                                                      //~@@@4R~
                if (macroSelectionSub(Pindwk))  //this entry to be selected//~@@@4R~
                {                                                  //~@@@4R~
                    rc=1;                                          //~@@@4R~
    UTRACEP("macroProcess update #else by selction ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@4R~
                }                                                  //~@@@4R~
            }                                                      //~@@@4R~
            else                                                   //~@@@4R~
            {                                                      //~@@@4R~
                rc=1;                                              //~@@@4R~
    UTRACEP("macroProcess update #else by no elif  ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@4R~
            }                                                      //~@@@4R~
        }                                                          //~@@@4I~
        if (rc==1)                                                 //~@@@4I~
        {                                                          //~@@@4I~
            *pindwkelse=*Pindwk;                                   //~@@@4I~
            pindwkelse->IDWstat|=IDWS_MACROELSE;    //status after #if by else//~@@@4I~
        }                                                          //~@@@4I~
        break;                                                     //~@@@4I~
	case MST_ENDIF:                                                //~@@@3I~
    	if (parmdefined)                                           //~@@@4I~
        {                                                          //~@@@4I~
        	if (parmdefined>0)   //text of -D parm matched with #if//~@@@4R~
        		if (parmdefined<MAX_MACROPARM)  //not yet saved at #else//~@@@4R~
 		           	rc=2;                                          //~@@@4R~
                else                                               //~@@@4I~
 		           	rc=1;                                          //~@@@4I~
            else  // ! match(use after #else                       //~@@@4R~
            	rc=2;                                              //~@@@4R~
        }                                                          //~@@@4I~
        else                                                       //~@@@4I~
        if (!(pindwkelse->IDWstat & IDWS_MACROELSE)   //no stmt under #if//~@@@3R~
        ||   (linectrMacro && macroSelectionSub(Pindwk))   //chk if stmt under #else//~@@@3R~//~@@@5R~
        )                                                          //~@@@3I~
        {                                                          //~@@@3R~
            rc=2;          //selected #else                        //~@@@3R~
UTRACEP("macroProcess update at #endif ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@3R~
        }                                                          //~@@@3R~
        else                                                       //~@@@3R~
        {                                                          //~@@@3R~
            rc=1;          //selected #if/#elif                    //~@@@3R~
UTRACEP("macroProcess update at #endif selcted #if ctr=%d,blocknest=%d,blockclosed=%d\n",SstackIndwkCtr,Pindwk->IDWblocknest[CUR_NEST()],Pindwk->IDWblockclosed[CUR_NEST()]);//~@@@3R~
        }                                                          //~@@@3R~
        if (rc==2)                                                 //~@@@4I~
            *pindwkelse=*Pindwk;	//continue from #else part                                   //~@@@3R~//~@@@4I~
        if (*Ppindwksaved)                                     //~@@@3R~//~@@@4I~
            *Ppindwksaved=pindwkelse;                          //~@@@3R~//~@@@4I~
        break;                                                     //~@@@3R~
    }                                                              //~@@@3I~
UTRACEP("macroProcessSelection after rc=%d ctr=%d,nest=%d,indmacro=%d,stmtsw=%c\n",rc,SstackIndwkCtr,CUR_NEST(),Pindwk->IDWindMacro,GET_CURRENT_STMT_SW(Pindwk));//~@@@3I~
    return rc;                                                     //~@@@3I~
}//macroSelection                                                  //~@@@3R~
//*****************************************************************//~@@@3I~
int macroSelectionSub(INDWORK *Pindwk)                             //~@@@3I~
{                                                                  //~@@@3I~
    int nestif,nest,nestelse,blocknestif,blocknestelse,blocknest;  //~@@@3R~
    int blockclosed,blockclosedelse,swrep=0;                       //~@@@3R~
	INDWORK *pindwkif,*pindwkelse;                                 //~@@@3I~
//********************************                                 //~@@@3I~
    pindwkif=SstackIndwk+(SstackIndwkCtr-1);                       //~@@@3I~
    pindwkelse=SstackIndwkelse+(SstackIndwkCtr-1);                 //~@@@3I~
    nestif=CUR_NESTINDWK(pindwkif);                                //~@@@3I~
    nestelse=CUR_NESTINDWK(pindwkelse);                            //~@@@3I~
    nest=CUR_NESTINDWK(Pindwk);                                    //~@@@3I~
UTRACEP("macroSelectionSub nest=%d,nestelse=%d,nestif=%d\n",nest,nestelse,nestif);//~@@@3R~
    if (nestelse>nestif) //nestup                                  //~@@@3I~
    {                                                              //~@@@3I~
    	if (nest>nestelse)                                         //~@@@3I~
        	swrep=1;                                               //~@@@3I~
    }                                                              //~@@@3I~
    else                                                           //~@@@3I~
    if (nestelse<nestif) //nestdown                                //~@@@3I~
    {                                                              //~@@@3I~
    	if (nest<nestelse)                                         //~@@@3I~
        	swrep=1;                                               //~@@@3I~
    }                                                              //~@@@3I~
    else                                                           //~@@@3I~
    {                                                              //~@@@3I~
		blocknestif=pindwkif->IDWblocknest[nestif];                //~@@@3I~
		blocknestelse=pindwkelse->IDWblocknest[nestelse];          //~@@@3I~
		blocknest=Pindwk->IDWblocknest[nest];                      //~@@@3I~
UTRACEP("macroSelectionSub blocknest=%d,blocknestelse=%d,blocknestif=%d\n",blocknest,blocknestelse,blocknestif);//~@@@3R~
		if (blocknestelse>blocknestif)                             //~@@@3I~
        {                                                          //~@@@3I~
        	if (blocknest>blocknestelse)                           //~@@@3I~
            	swrep=1;                                           //~@@@3I~
        }                                                          //~@@@3I~
        else                                                       //~@@@3I~
		if (blocknestelse<blocknestif)                             //~@@@3I~
        {                                                          //~@@@3I~
        	if (blocknest<blocknestelse)                           //~@@@3I~
            	swrep=1;                                           //~@@@3I~
        }                                                          //~@@@3I~
        else                                                       //~@@@3I~
        {                                                          //~@@@3I~
			blockclosedelse=Pindwk->IDWblockclosed[nestelse];      //~@@@3R~
			blockclosed=Pindwk->IDWblockclosed[nest];              //~@@@3I~
UTRACEP("macroSelectionSub blockclosed=%d\n",blockclosed);         //~@@@3R~
			if (!blockclosedelse)	//select else                  //~@@@3R~
				if (blockclosed)                                   //~@@@3I~
    	        	swrep=1;                                       //~@@@3I~
        }                                                          //~@@@3I~
    }                                                              //~@@@3I~
UTRACEP("macroSelectionSub rc=%d\n",swrep);                        //~@@@3R~
    return swrep;                                                  //~@@@3I~
}//macroSelectionSub                                               //~@@@3I~
//*****************************************************************
//*keep data to be continued
//*****************************************************************
int macroContinueData(INDWORK *Pindwk,INDWORK *Pfrom)
{
//********************************
	Pindwk->IDWlineno=Pfrom->IDWlineno;
	Pindwk->IDWoutlineno=Pfrom->IDWoutlineno;
	Pindwk->IDWupdatelineno=Pfrom->IDWupdatelineno;
	Pindwk->IDWlinedata=Pfrom->IDWlinedata;
	Pindwk->IDWdatalen=Pfrom->IDWdatalen;
    return 0;
}//macroContinueData
//*****************************************************************
//*next back by NEXT statement
//*Popt:1:ControlStmt,0:other
//*****************************************************************
int backStmtNest(int Popt,INDWORK *Pindwk,int Ptopsw)
{
    int rc;
//********************************
	UTRACEP("backStmtNest topsw=%d\n",Ptopsw);
	rc=updateStmtNest(UCSNO_NEXTSTMT,Pindwk,CS_STMTENDNEXT,Ptopsw);
    if (Popt!=1 || rc!=UCSNRC_DOCLOSED)
    	SET_CURRENT_STMT_SW(Pindwk,CS_NOSTMT);
	UTRACEP("backStmtNest rc=%d\n",rc);
    return rc;
}//backStmtNest
//*****************************************************************
//*chk Constrol statement if/do/for/while/...
//*return stmt len,minus for special word
//*****************************************************************
int chkControlStmt(INDWORK *Pindwk,int Poffs,char *Pdata,int Plen,int *Ppstmttypeindex)
{
    int ii,len=0,ch,swControl=0,rc;
    char *pc,*pc2;                                                 //~@@@4R~
//********************************
    *Ppstmttypeindex=CST_NONE;
    for (ii=1;(pc=ScontrolStmt[ii])!=0;ii++)
    {
    	len=ScontrolStmtLen[ii];
        swControl=0;
//      if (len<=Plen && !memcmp(Pdata,pc,len))                    //~vaa0R~
        if (len<=Plen && !memcmp(Pdata,pc,(size_t)len))            //~vaa0I~
        {
        	if (len==Plen)
            	swControl=1;
            else
            {
		        pc2=Pdata+len;                                     //~@@@4R~
		        ch=*pc2;                                           //~@@@4I~
        		if (ch==CH_SPACE||ch==CH_TAB||ch==CH_LP            //~@@@4R~
                ||  (len>=2 && (                                   //~@@@4I~
                                    *pc2==CH_SLASH                 //~@@@4I~
                                 && (  *(pc2+1)==CH_SLASH // "//" comment//~@@@4I~
                                     ||*(pc2+1)==CH_STAR  // "/*" comment//~@@@4I~
                                    )                              //~@@@4I~
                               )                                   //~@@@4I~
                    )                                              //~@@@4I~
                )                                                  //~@@@4I~
	            	swControl=1;
            }
        }
        if (swControl)
        {
        	if (Poffs>0)
            {
		        ch=*(Pdata-1);
        		if (ch!=CH_TAB && ch!=CH_SPACE)
                	if (ispunct(ch))
		            	swControl=0;

            }
        }
        if (swControl)
        {
    		*Ppstmttypeindex=ii;
        	break;
        }
    }
    if (!swControl)
    {
    	rc=0;
    	if (Shelpmsg && Plen>=MACRO_HELPMSG_LEN && !memcmp(Pdata,MACRO_HELPMSG,MACRO_HELPMSG_LEN))
        {
        	rc=-MACRO_HELPMSG_LEN;
        }
    }
    else
    	rc=len;
    Pindwk->IDWcurStmtType=*Ppstmttypeindex;
UTRACEP("chkControlStmt curtype=%d,offs=%d,len=%d,data=%s\n",Pindwk->IDWcurStmtType,Poffs,rc,Pdata);
	return rc;
}//chkControlStmt
//*****************************************************************
//*chk Macro statement if/else/...
//*return stmt len
//*****************************************************************
int chkMacroStmt(INDWORK *Pindwk,char *Pdata,int Plen,int Pswcont,int *Ppstmttypeindex,int *Ppparmdefined)//~@@@4R~
{
//  int ii,len=0,ch,swMacro=0,rc;                                  //~va76R~
    int ii,len=0,ch,          rc;                                  //~va76I~
    char *pc,*pdata;
//********************************
	*Ppparmdefined=0;                                              //~@@@4I~
    Pindwk->IDWmacroParmIndex=0;                                   //~@@@4R~
//  pdata=Pdata+umemspn_spacetab(Pdata,Plen);                      //~vaa0R~
    pdata=Pdata+umemspn_spacetab(Pdata,(unsigned)Plen);            //~vaa0I~
    for (ii=1;(pc=SmacroStmt[ii])!=0;ii++)
    {
    	len=SmacroStmtLen[ii];
//      swMacro=0;                                                 //~va76R~
//      if (len<=Plen && !memcmp(pdata,pc,len))                    //~vaa0R~
        if (len<=Plen && !memcmp(pdata,pc,(size_t)len))            //~vaa0I~
        {
        	if (len==Plen)
            	break;
            else
            {
		        ch=*(pdata+len);
                if (!isalnum(ch))                                  //~@@@4I~
	            	break;
            }
        }
    }
    if (pc)
    {
    	*Ppstmttypeindex=ii;
    	rc=len;
	    if (Smacroparmctr)                                         //~@@@4I~
			*Ppparmdefined=chkMacroText(Pindwk,ii,Pdata+len,Plen-len,Pswcont);//~@@@4R~
    }
    else
    {
    	*Ppstmttypeindex=MST_NONE;
    	rc=0;
    }
UTRACEP("chkMacroStmt curtype=%d,rc=%d,data=%s\n",*Ppstmttypeindex,rc,pdata);
	return rc;
}//chkMacroStmt
//*****************************************************************//~@@@4I~
//*chk #ifdef TEXT                                                 //~@@@4I~
//*  # if A=B is not supported, supports [!]defined() only         //~@@@4M~
//*return index (minus if !(not))                                  //~@@@4R~
//*****************************************************************//~@@@4I~
int chkMacroText(INDWORK *Pindwk,int Pstmttype,char *Pdata,int Plen,int Pswcont)//~@@@4R~
{                                                                  //~@@@4I~
    int len,idx=-1,textlen,swnot=0,len2,swundef=0;                 //~@@@4R~
    char *pc,*pdata,*pc2;                                          //~@@@4R~
//********************************                                 //~@@@4I~
UTRACEP("chkMacroText stmt=%d,swcont=%d,text=%s\n",Pstmttype,Pswcont,Pdata);//~@@@4R~
	pdata=Pdata;                                                   //~@@@4I~
    len=Plen;                                                      //~@@@4I~
	USKIP_SPACETAB(pdata,len);                                     //~@@@4R~
    switch(Pstmttype)                                              //~@@@4I~
    {                                                              //~@@@4I~
	case MST_IF:                                                   //~@@@4I~
	case MST_ELIF:                                                 //~@@@4I~
    	if (Pswcont)                                               //~@@@4I~
        	break;                                                 //~@@@4I~
        if (*pdata==CH_NOT)                                        //~@@@4M~
        {                                                          //~@@@4M~
        	swnot=1;                                               //~@@@4M~
            pdata++;                                               //~@@@4I~
            len--;                                                 //~@@@4I~
			USKIP_SPACETAB(pdata,len);                             //~@@@4R~
        }                                                          //~@@@4M~
    	if (len<=MACRO_DEFINED_LEN)                                //~@@@4M~
        	break;                                                 //~@@@4M~
    	if (memcmp(pdata,MACRO_DEFINED,MACRO_DEFINED_LEN))         //~@@@4R~
        	break;                                                 //~@@@4I~
        pdata+=MACRO_DEFINED_LEN;                                  //~@@@4I~
        len-=MACRO_DEFINED_LEN;                                    //~@@@4I~
        if (!len)                                                  //~@@@4I~
            break;                                                 //~@@@4I~
		USKIP_SPACETAB(pdata,len);                                 //~@@@4R~
        if (*pdata!=CH_LP)                                         //~@@@4I~
            break;                                                 //~@@@4I~
        pdata++;                                                   //~@@@4I~
        len--;                                                     //~@@@4I~
		USKIP_SPACETAB(pdata,len);                                 //~@@@4R~
//      pc=memchr(pdata,CH_RP,len);                                //~@@@4I~//~vaa0R~
        pc=memchr(pdata,CH_RP,(size_t)len);                        //~vaa0I~
        if (!pc)                                                   //~@@@4I~
        	break;                                                 //~@@@4I~
        pc2=pc+1;                                                  //~@@@4I~
        len2=len-1;                                                //~@@@4I~
        textlen=PTRDIFF(pc,pdata);                                 //~@@@4R~
//      pc=umempbrk(pdata,TABSPACE,textlen);                       //~@@@4R~//~vaa0R~
        pc=umempbrk(pdata,TABSPACE,(size_t)textlen);               //~vaa0I~
        if (pc)                                                    //~@@@4I~
        	textlen=PTRDIFF(pc,pdata);                             //~@@@4R~
        if (!textlen)                                              //~@@@4I~
        	break;                                                 //~@@@4I~
        idx=srchMacroParm(pdata,textlen,&swundef);                 //~@@@4R~
        if (idx<0)                                                 //~@@@4I~
        	break;                                                 //~@@@4I~
		USKIP_SPACETAB(pc2,len2);                                  //~@@@4R~
//      if (umemstr(pc2,MACRO_OR,len2)                             //~@@@4R~//~vaa0R~
//      if (umemstr(pc2,MACRO_OR,(size_t)len2)                     //~vaa0I~//~vaa1R~
        if (umemstr(pc2,MACRO_OR,(unsigned)len2)                   //~vaa1I~
//      ||  umemstr(pc2,MACRO_AND,len2))                           //~@@@4R~//~vaa0R~
//      ||  umemstr(pc2,MACRO_AND,(size_t)len2))                   //~vaa0I~//~vaa1R~
        ||  umemstr(pc2,MACRO_AND,(unsigned)len2))                 //~vaa1I~
        {                                                          //~@@@4I~
            idx=-1;                                                //~@@@4I~
        	break;                                                 //~@@@4I~
        }                                                          //~@@@4I~
        if (swundef)                                               //~@@@4I~
        	swnot=(swnot==0);                                      //~@@@4I~
    	break;                                                     //~@@@4I~
	case MST_IFDEF:                                                //~@@@4I~
	case MST_IFNDEF:                                               //~@@@4I~
//      pc=umempbrk(pdata,TABSPACE,len);                           //~@@@4R~//~vaa0R~
        pc=umempbrk(pdata,TABSPACE,(size_t)len);                   //~vaa0I~
        if (pc)                                                    //~@@@4I~
        	textlen=PTRDIFF(pc,pdata);                             //~@@@4R~
        else                                                       //~@@@4I~
        	textlen=len;                                           //~@@@4I~
        idx=srchMacroParm(pdata,textlen,&swundef);                 //~@@@4R~
        if (idx<0)                                                 //~@@@4I~
        	break;                                                 //~@@@4I~
        if (Pstmttype==MST_IFNDEF)                                 //~@@@4I~
			swnot=1;                                               //~@@@4I~
        if (swundef)                                               //~@@@4I~
        	swnot=(swnot==0);                                      //~@@@4I~
    	break;                                                     //~@@@4I~
    }                                                              //~@@@4I~
    if (idx>=0)                                                    //~@@@4I~
    {                                                              //~@@@4I~
    	if (swnot)                                                 //~@@@4I~
            idx=-idx-1;                                            //~@@@4I~
        else                                                       //~@@@4I~
            idx=idx+1;                                             //~@@@4I~
    }                                                              //~@@@4I~
    else                                                           //~@@@4I~
        idx=0;                                                     //~@@@4I~
UTRACEP("chkMacroText index=%d\n",idx);                            //~@@@4R~
	return idx;                                                    //~@@@4R~
}//chkMacroText                                                    //~@@@4R~
//*****************************************************************//~@@@4I~
//*search in cmd line parameter                                    //~@@@4I~
//*****************************************************************//~@@@4I~
int srchMacroParm(char *Pdata,int Plen,int *Ppswundef)             //~@@@4R~
{                                                                  //~@@@4I~
    int ii,len,rc;                                                 //~@@@4R~
//********************************                                 //~@@@4I~
    for (ii=0;ii<Smacroparmctr;ii++)                               //~@@@4I~
    {                                                              //~@@@4I~
    	len=SmacroparmLen[ii];                                     //~@@@4I~
//  	if (Plen>=len && !memcmp(Smacroparm[ii],Pdata,len))        //~@@@4R~//~vaa0R~
    	if (Plen>=len && !memcmp(Smacroparm[ii],Pdata,(size_t)len))//~vaa0I~
        	break;                                                 //~@@@4I~
    }                                                              //~@@@4I~
    if (ii<Smacroparmctr)                                          //~@@@4I~
    {                                                              //~@@@4I~
        *Ppswundef=SmacroparmUndef[ii];                            //~@@@4I~
    	rc=ii;                                                     //~@@@4I~
    }                                                              //~@@@4I~
    else                                                           //~@@@4I~
    	rc=-1;                                                     //~@@@4I~
UTRACEP("srchMacroParm len=%d,rc=%d,data=%s\n",Plen,rc,Pdata);     //~@@@4R~
	return rc;                                                     //~@@@4I~
}//srchMacroParm                                                   //~@@@4I~
//*****************************************************************
//*update by statement level
//*****************************************************************
int updateStmtNest(int Popt,INDWORK *Pindwk,int PswStmt,int Pswtop)
{
//  int nest,nestnew,nestold,stmttype,rc=0,newind,curstmttype,rc2; //~va76R~
    int nest,                stmttype,rc=0,newind,curstmttype,rc2; //~va76R~
    int ifelsectr,nest2;
//********************************
	nest=CUR_NEST();
UTRACEP("updateStmtNest opt=%c=x%X,Pswtop=%d,nest=%d,indlevel=%d\n",Popt,Popt,Pswtop,nest,CUR_INDLEVEL());
	switch (Popt)
    {
	case UCSNO_BSTART: //"{" for control stmt
        stmttype=Pindwk->IDWstmttype[nest];
    	if (stmttype && !Pindwk->IDWblocknest[nest])	//Control statement 1st "{"
			newind=CUR_INDLEVEL();	//already uped at stmt
        else
			newind=INDLEVEL_UP(nest);
        Pindwk->IDWblocknest[nest]++;
        SET_INDLEVEL_TOP(Pswtop,newind-1);
UTRACEP("updateStmtNest BSTART nest=%d,indlevel=%d,blocknest=%d,stmttype=%d\n",nest,CUR_INDLEVEL(),Pindwk->IDWblocknest[nest],Pindwk->IDWstmttype[nest]);
    	break;
//    case UCSNO_BSTART2: //"{" function block
//        updateNest(Pindwk,1,CH_BSTART);
//        nest=CUR_NEST();
//        Pindwk->IDWblocknest[nest]++;
//        newind=INDLEVEL_UP(nest);
//        SET_INDLEVEL_TOP(Pswtop,newind-1);
//UTRACEP("updateStmtNest BSTART2 nest=%d,indlevel=%d,\n",CUR_NEST(),CUR_INDLEVEL());
//        break;
	case UCSNO_BEND: //"}" for control stmt
        stmttype=Pindwk->IDWstmttype[nest];
//        if (stmttype==CH_BSTART)    //simple block
//            return updateStmtNest(UCSNO_BEND2,Pindwk,CH_BEND,Pswtop);
        if (!Pindwk->IDWblocknest[nest])//closed
        {
			return  updateStmtNest(UCSNO_BEND2,Pindwk,CH_BEND,Pswtop);
        }
        if (!(--Pindwk->IDWblocknest[nest]))	//stmt block closed
        {
        	if (stmttype)
        	{
UTRACEP("updateStmtNest BEND  UCSNRC_BEND\n");
	            rc=UCSNRC_BEND; 	//re-call by STMTEND
        	}
            if (nest)	//except nest=0
				Pindwk->IDWblockclosed[nest]=1;
        }
		newind=INDLEVEL_DOWN(nest);
        if (newind<0)
			xci_errmsg(EMO_BLOCKNEST,Pindwk,-4);
        else
        	SET_INDLEVEL_TOP(Pswtop,newind);
UTRACEP("updateStmtNest BEND  rc=%d,nest=%d,indlevel=%d,top=%d,blocknest=%d\n",rc,CUR_NEST(),CUR_INDLEVEL(),Pindwk->IDWindLevelTop,Pindwk->IDWblocknest[nest]);
    	break;
    case UCSNO_BEND2: //search enclosing block
//        updateNest(Pindwk,-1,0/*stmttype*/);
//        newind=CUR_INDLEVEL();
//        SET_INDLEVEL_TOP(Pswtop,newind);
		rc2=0;
        for (;nest>=0;)
        {
    UTRACEP("updateStmtNest BEND2 loop nest=%d,stmttype=%d,blocknest=%d\n",nest,Pindwk->IDWstmttype[nest],Pindwk->IDWblocknest[nest]);
    		if (Pindwk->IDWblocknest[nest])//opend block
            	break;
			rc2=updateNest(0,Pindwk,-1,0/*stmttype*/);
            if (rc2<0)
            	break;	//underflow
			nest=CUR_NEST();
        }
        if (nest>=0 && !rc2)
        {
	        Pindwk->IDWblocknest[nest]--;
        	newind=INDLEVEL_DOWN(nest);
       		if (newind<0)
				xci_errmsg(EMO_BLOCKNEST,Pindwk,-4);
            else
            {
	        	SET_INDLEVEL_TOP(Pswtop,newind);
		        if (!Pindwk->IDWblocknest[nest])
                {
		        	if (Pindwk->IDWstmttype[nest])
	    		        rc=UCSNRC_BEND; 	//re-call by STMTEND
  					if (nest)	//except nest=0
						Pindwk->IDWblockclosed[nest]=1;
            	}
            }
        }
        else
			xci_errmsg(EMO_BLOCKNEST,Pindwk,-4);
UTRACEP("updateStmtNest BEND2  rc=%d,nest=%d,indlevel=%d,top=%d\n",rc,CUR_NEST(),CUR_INDLEVEL(),Pindwk->IDWindLevelTop);
        break;
	case UCSNO_LP: //"(" for function
		if (updatePNest(Pindwk,nest,1)==UCSNRC_LPOPEN)	//1st open
        {
			rc=UCSNRC_LPOPEN;   //1st (
			newind=INDLEVEL_UP(nest);
        	SET_INDLEVEL_TOP(Pswtop,newind-1);
        }
UTRACEP("updateStmtNest LP  nest=%d,indlevel=%d Pnest=%d\n",CUR_NEST(),CUR_INDLEVEL(),CUR_PNEST(nest));
    	break;
	case UCSNO_RP: //")" for function
		if (updatePNest(Pindwk,nest,-1)==UCSNRC_RPCLOSE)	//closed
        {
			rc=UCSNRC_RPCLOSE;   //last )
			newind=INDLEVEL_DOWN(nest);
        	SET_INDLEVEL_TOP(Pswtop,newind);
        }
UTRACEP("updateStmtNest RP  nest=%d,indlevel=%d Pnest=%d\n",CUR_NEST(),CUR_INDLEVEL(),CUR_PNEST(nest));
    	break;
	case UCSNO_IF:       //change too many id-else-if-else to elif
        if (!Smaxifelse)
        	return 0;
        stmttype=Pindwk->IDWstmttype[nest];
UTRACEP("updateStmtNest UCSNO_IF before nest=%d,nest stmttype=%d\n",CUR_NEST(),stmttype);
        ifelsectr=0;
        for (nest2=nest;nest2>=0;nest2--,ifelsectr++)
        {
            stmttype=Pindwk->IDWstmttype[nest2];
            UTRACEP("updateStmtNest IF loop nest=%d,stmttype=%d,block=%d\n",nest2,stmttype,Pindwk->IDWblocknest[nest2]);
            if (stmttype!=CST_ELSE||Pindwk->IDWblocknest[nest2])
                break;
        }
        if (ifelsectr>=Smaxifelse)
            rc=1;
        if (rc)
        {
			newind=resetEntry(0/*keep status*/,Pindwk,nest,CST_IF);	//else or elif
			INDLEVEL_UP(nest);
	        SET_INDLEVEL_TOP(Pswtop,newind);
        }
UTRACEP("updateStmtNest IF  nest=%d,indlevel=%d,\n",CUR_NEST(),CUR_INDLEVEL());
    	break;
	case UCSNO_ELSE:
UTRACEP("updateStmtNest UCSNO_ELSE nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
        rc2=0;
        for (;nest>=0;)
        {
    UTRACEP("updateStmtNest ELSE loop nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
            stmttype=Pindwk->IDWstmttype[nest];
            if (stmttype==CST_IF || stmttype==CST_ELIF)
            {
            	if (Pindwk->IDWblocknest[nest]) //block but not closed
                	rc2=-4;
            	break;
            }
			rc2=updateNest(0,Pindwk,-1,0/*stmttype*/);
            if (rc2<0)
            	break;	//underflow
			nest=CUR_NEST();
        }
        if (nest>=0 && !rc2)
        {
			newind=resetEntry(0/*keep status*/,Pindwk,nest,Pindwk->IDWcurStmtType);	//else or elif
			INDLEVEL_UP(nest);
	        SET_INDLEVEL_TOP(Pswtop,newind);
        }
        else
			xci_errmsg(EMO_ELSE,Pindwk,-4);
UTRACEP("updateStmtNest ELSE  nest=%d,indlevel=%d,\n",CUR_NEST(),CUR_INDLEVEL());
    	break;
	case UCSNO_WHILE:
UTRACEP("updateStmtNest UCSNO_WHILE nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
        stmttype=Pindwk->IDWstmttype[nest];
        if (stmttype==CST_DO && !Pindwk->IDWdostmt[nest])
        {
UTRACEP("updateStmtNest DOWHILE\n");
            Pindwk->IDWdostmt[nest]=CST_WHILE;  //
            newind=Pindwk->IDWindLevel0[nest]; //reset indentation in the "if"
            Pindwk->IDWindLevel[nest]=newind; //reset indentation in the "if"
	        SET_INDLEVEL_TOP(Pswtop,newind);
            rc=UCSNRC_DOWHILE;              //while is not while {} stmt
        }
    	break;
	case UCSNO_CATCH:
UTRACEP("updateStmtNest UCSNO_CATCH nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
        stmttype=Pindwk->IDWstmttype[nest];
//      if (stmttype==CST_TRY||CST_CATCH)                          //~vap0R~
        if (stmttype==CST_TRY||stmttype==CST_CATCH)                //~vap0I~
        {
			newind=resetEntry(0/*keep status*/,Pindwk,nest,CST_CATCH);
			INDLEVEL_UP(nest);
	        SET_INDLEVEL_TOP(Pswtop,newind);
        }
        else
			xci_errmsg(EMO_CATCH,Pindwk,-4);
    	break;
	case UCSNO_CASE:
UTRACEP("updateStmtNest UCSNO_CASE nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
        stmttype=Pindwk->IDWstmttype[nest];
        if (stmttype==CST_SWITCH)
        {
            newind=Pindwk->IDWindLevel0[nest]; //reset indentation in the "if"
            Pindwk->IDWindLevel[nest]=newind; //reset indentation in the "if"
			INDLEVEL_UP(nest);
        	SET_INDLEVEL_TOP(Pswtop,newind);
UTRACEP("updateStmtNest CASE  nest=%d,indlevel=%d,top=%d\n",CUR_NEST(),CUR_INDLEVEL(),newind);
        }
        else
			xci_errmsg(EMO_CASE,Pindwk,-4);
    	break;
	case UCSNO_STMT:       //control stmt other than else/elif/case
        stmttype=Pindwk->IDWstmttype[nest];
        curstmttype=Pindwk->IDWcurStmtType;
UTRACEP("updateStmtNest UCSNO_STMT before nest=%d,nest stmttype=%d,cur stmttype=%d\n",CUR_NEST(),stmttype,curstmttype);
        if (curstmttype==CST_IF)
        {
			if (updateStmtNest(UCSNO_IF,Pindwk,0,Pswtop))
            	return 0;
        }
        if (curstmttype==CST_CATCH)
        {
			if (updateStmtNest(UCSNO_CATCH,Pindwk,0,Pswtop))
            	return 0;
        }
		updateNest(1/*underflow msg*/,Pindwk,1,curstmttype);
        nest=CUR_NEST();
		newind=INDLEVEL_UP(nest);
        SET_INDLEVEL_TOP(Pswtop,newind-1);
UTRACEP("updateStmtNest STMT  nest=%d,indlevel=%d,\n",CUR_NEST(),CUR_INDLEVEL());
    	break;
	case UCSNO_NEXTSTMT:
        stmttype=Pindwk->IDWstmttype[nest];
        if (stmttype==CST_DO)
        {
	        if (Pindwk->IDWdostmt[nest]==CST_WHILE)
            {
UTRACEP("updateStmtNest NEXTSTMT rc=DOCLOSED\n");
            	rc=UCSNRC_DOCLOSED;              //while is not while {} stmt
            }
        }
//      nestold=nestnew=0;                                         //~va76R~
UTRACEP("updateStmtNest NEXTSTMT nest=%d,blockstmt=%d\n",nest,Pindwk->IDWblocknest[nest]);
        if (nest>0 && Pindwk->IDWdostmt[nest]==CST_WHILE)	//while of do-while
        {
			updateNest(0,Pindwk,-1,0/*stmttype*/);
			nest=CUR_NEST();
    UTRACEP("updateStmtNest NEXTSTMT loop0 is WHILE nest=%d\n",nest);
        }
#ifdef BBB
        if (nest>0 && Pindwk->IDWblocknest[nest])	//opend block
        {
			updateNest(0,Pindwk,-1,0/*stmttype*/);
			nest=CUR_NEST();
    UTRACEP("updateStmtNest NEXTSTMT loop0 is BEND nest=%d\n",nest);
        }
#endif
        for (;nest>=0;)
        {
    UTRACEP("updateStmtNest NEXTSTMT loop nest=%d,stmttype=%d\n",nest,Pindwk->IDWstmttype[nest]);
            stmttype=Pindwk->IDWstmttype[nest];
            if (Pindwk->IDWblockclosed[nest])
            {
    UTRACEP("updateStmtNest NEXTSTMT continue by closed block\n");
    			;
            }
            else
            {
#ifdef BBB
                if (stmttype!=CST_IF && stmttype!=CST_ELSE)
                {
        UTRACEP("updateStmtNest NEXTSTMT break by non IF\n");
                    break;
                }
#endif
                if (Pindwk->IDWblocknest[nest])
                {
        UTRACEP("updateStmtNest NEXTSTMT break by {\n");
                    break;
                }
            }
			rc2=updateNest(1,Pindwk,-1,0/*stmttype*/);
            if (rc2<0)
            	break;	//underflow
			nest=CUR_NEST();
        }
		newind=CUR_INDLEVEL();
        SET_INDLEVEL_TOP(Pswtop,newind);
UTRACEP("updateStmtNest NEXTSTMT  nest=%d,indlevel=%d,\n",CUR_NEST(),CUR_INDLEVEL());
    	break;
    }
    return rc;
}//updateStmtNest
//************************************************************************
//*reset nest entry
//************************************************************************
int resetEntry(int Popt,INDWORK *Pindwk,int Pnest,int Pstmttype)
{
	int newind;
//**************
    Pindwk->IDWstmttype[Pnest]=Pstmttype;
    Pindwk->IDWblocknest[Pnest]=0;
    Pindwk->IDWblockclosed[Pnest]=0;
    Pindwk->IDWdostmt[Pnest]=0;
	Pindwk->IDWPNest[Pnest]=0;
    if (Popt)
    {
        if (Pnest>0)
	        	Pindwk->IDWindLevel0[Pnest]=Pindwk->IDWindLevel[Pnest-1];
        else
	        	Pindwk->IDWindLevel0[Pnest]=0;
	    Pindwk->IDWswControlStmt[Pnest]=0;
    }
    Pindwk->IDWindLevel[Pnest]=newind=Pindwk->IDWindLevel0[Pnest]; //reset indentation in the "if"
    return newind;
}//resetEntry
//************************************************************************
//*update block level
//*rc:old level,-4 nest level dwon to minus
//************************************************************************
int updateNest(int Popt,INDWORK *Pindwk,int Pctr,int Pstmttype)
{
	int rc=0,nest,nest0;                                           //~@@@5R~
//*******************
    nest=nest0=Pindwk->IDWnestlevel;
    nest+=Pctr;
    if (nest<0)
    {
    	if (Popt)	//msg opt
			rc=xci_errmsg(EMO_UNDERNEST,Pindwk,-4);
        else
        	rc=-4;
    }
    else
    if (nest>=MAX_NEST)
		rc=xci_errmsg(EMO_OVERNEST,Pindwk,-4);
    else
    {
        Pindwk->IDWnestlevel=nest;
UTRACEP("updateNest SET_CONTROL_STMT nest=%d,old=%d,stmttype=%d\n",nest,nest0,Pstmttype);
        if (Pctr>0)	//up
        {
			resetEntry(1/*copy from prev entry*/,Pindwk,nest0,Pstmttype);
        }
    }
UTRACEP("updateStmtNest updateNest  stmttype=%d,nest0=%d,nest=%d,dostmt=%d\n",Pstmttype,nest0,nest,Pindwk->IDWdostmt[nest-1]);//~@@@5R~
    return rc;
}//updateNest
//*****************************************************************
//*chk Constrol statement nest level
//rc:1:1st "(", 2:last ")"
//*****************************************************************
int updatePNest(INDWORK *Pindwk,int Pnest,int Pctr)
{
	int rc=0;
//********************************
    UTRACEP("upadtePNest req=%d,nest=%d,ctr=%d\n",Pctr,Pnest,CUR_PNEST(Pnest));
	if (Pctr>0)
    {
    	if (!CUR_PNEST(Pnest)++)
			rc=UCSNRC_LPOPEN;   //1st (
    }
    else
    {
    	if (CUR_PNEST(Pnest))
        {
	    	if (!(--CUR_PNEST(Pnest)))
            {
				rc=UCSNRC_RPCLOSE;   //last )
            }
        }
        else
			rc=xci_errmsg(EMO_LPRPUNMATCH,Pindwk,4);
    }
    UTRACEP("upadtePNest ret nest=%d,ctr=%d\n",Pnest,CUR_PNEST(Pnest));
    return rc;
}//updatePNest
//****************************************************************
// scan data to chk comment, quotation, { ,}, continuation
//set 1st ({) , (}) , (//) position
//*rc:0x04: nest level dwon to minus,0x08: dquote not enclosed
//****************************************************************
int getTabColumn(INDWORK *Pindwk,char *Pdata,int Plen)
{
	char *pc;
    int cols=0,tabskip,offs;
//*************************
    tabskip=Pindwk->IDWtabskip;
    if (tabskip>1)
    {
        for (offs=0,pc=Pdata;offs<Plen;offs++,pc++)
        {
            if (*pc==CH_TAB)
            {
				cols+=TABSKIPCTR(tabskip,cols);
            }
            else
                cols++;
        }//for
    }
    else
    	cols=Plen;
UTRACED("getTabColumn",Pdata,Plen);
UTRACEP("getTabColumn tabcols=%d\n",cols);
    return cols;
}//getTabColumn
//************************************************************************
//*get block level in the line
//************************************************************************
int enqPrint(int Popt,INDWORK *Pindwk,char *Pdata,int Pdatalen)
{
	int rc=0,rlen,oldl,len,spcctr;
	int outoffs,indoffs,func,datalen,offs;
    int copyctr,fillspacectr,delctr,spacesw;
    char *pc,*pco,*pco0;
//*****************************
    pco=pco0=Pindwk->IDWoutbuff;
    outoffs=Pindwk->IDWoutoffs;
    rlen=Pindwk->IDWoutbuffsz;
    rlen-=outoffs;
    pco+=outoffs;
    func=Popt & EPO_FUNCMASK;
    switch (func)
    {
    case EPO_FULLLINE:
        rc=Pindwk->IDWfuncWrite(0/*write input*/,Pindwk);
        break;
    case EPO_FLASH:
	    rc=Pindwk->IDWfuncWrite(1/*write outbuff*/,Pindwk);
        break;
//    case EPO_SETBUFF:
//        len=min(Pdatalen,rlen);
//        memcpy(pco,Pdata,len);
//        Pindwk->IDWoutoffs+=len;
//        break;
    case EPO_INDENTATION:
UTRACED("enqPrint indentation",Pdata,Pdatalen);
	    spcctr=Pindwk->IDWnonspaceoffs;
        if (spcctr<0)  	//all space or datalen=0
        {
	    	rc=Pindwk->IDWfuncWrite(0/*write input*/,Pindwk);
        	break;
        }
        pc=Pdata+spcctr;
        datalen=Pdatalen-spcctr;
    	if (Pindwk->IDWstat & IDWS_MACROSTMT)	//MACRO STMT is used for enqPrint
        	oldl=Pindwk->IDWindMacro;
        else
        	oldl=Pindwk->IDWindLevelTop;
UTRACEP("enqPrint top ind=%d\n",oldl);
//        if (*pc==CH_BEND)   //"}" at top of line
//        {
//            if (oldl)
//                oldl--;
//        }
        indoffs=oldl*Pindwk->IDWindentationcols;
        if (indoffs==Pindwk->IDWnonspaceoffstab)
        {
        	rc=Pindwk->IDWfuncWrite(0/*write input*/,Pindwk);
UTRACEP("enqprint Indentation indoffs=nonspaceoffstab pos=%d\n",indoffs);
            break;
        }
        copyctr=chkTabShift(Pindwk,Pdata,Pdatalen,indoffs,&fillspacectr);
        if (copyctr)
        {
        	len=min(copyctr,rlen);
//      	memcpy(pco,Pdata,len);                                 //~vaa0R~
        	memcpy(pco,Pdata,(size_t)len);                         //~vaa0I~
            pco+=len;
            rlen-=len;
        }
        if (fillspacectr)
        {
        	len=min(fillspacectr,rlen);
//      	memset(pco,CH_SPACE,len);                              //~vaa0R~
        	memset(pco,CH_SPACE,(size_t)len);                      //~vaa0I~
            pco+=len;
            rlen-=len;
        }
        len=min(datalen,rlen);
//      memcpy(pco,pc,len);                                        //~vaa0R~
        memcpy(pco,pc,(size_t)len);                                //~vaa0I~
        pco+=len;
        Pindwk->IDWoutoffs=PTRDIFF(pco,pco0);
        break;
    case EPO_SETSLC:
        offs=Pindwk->IDWslcoffs;    //write after
        pc=Pindwk->IDWlinedata+offs;
        datalen=Pindwk->IDWdatalen-offs;
        spacesw=(offs>0 && (*(pc-1)==CH_SPACE || *(pc-1)==CH_TAB));//space before "//"
		delctr=chkTabShiftSLC(spacesw,Pindwk,&fillspacectr);
        pco-=delctr;
        outoffs-=delctr;
        rlen+=delctr;
        if (fillspacectr)
        {
        	len=min(fillspacectr,rlen);
//      	memset(pco,CH_SPACE,len);                              //~vaa0R~
        	memset(pco,CH_SPACE,(size_t)len);                      //~vaa0I~
            pco+=len;
            rlen-=len;
        }
        len=min(datalen,rlen);
//      memcpy(pco,pc,len);                                        //~vaa0R~
        memcpy(pco,pc,(size_t)len);                                //~vaa0I~
        pco+=len;
        Pindwk->IDWoutoffs=PTRDIFF(pco,pco0);
        break;
    }
    return rc;
}//enqPrint
//*****************************************************************
//*chk available tab for top indentation
//*****************************************************************
int chkTabShift(INDWORK *Pindwk,char *Pdata,int Plen,int Pindoffs,int *Ppspacectr)
{
	char *pc,*pce;
    int offs,offso=0,tabskip,copyctr,fillspacectr;
//********************************
    if (Pindwk->IDWstat&IDWS_TAB)
    {
        tabskip=Pindwk->IDWtabskip;
        for (pc=Pdata,pce=pc+Plen,offs=0;pc<pce;pc++)
        {
            offso=offs;
            if (*pc==CH_SPACE)
                offs++;
            else
            if (*pc==CH_TAB)
                offs+=TABSKIPCTR(tabskip,offs);
            else
                break;
            if (offs>Pindoffs)
            	break;
        }
	    fillspacectr=Pindoffs-offso;
    	copyctr=PTRDIFF(pc,Pdata);
    }
    else
    {
    	copyctr=0;
        fillspacectr=Pindoffs;
    }
    *Ppspacectr=fillspacectr;
UTRACEP("chkTabShift copyctr=%d,fillspacectr=%d\n",copyctr,fillspacectr);
    return copyctr;
}//chkTabShift
//*****************************************************************
//*chk available tab befor SLC
//*popt:1:space before // comment
//*****************************************************************
int chkTabShiftSLC(int Popt,INDWORK *Pindwk,int *Ppspacectr)
{
	char *pco0,*pco;
//  int slcoffstab,outoffs,tabskip,delctr=0,fillspacectr=0;        //~va76R~
    int slcoffstab,outoffs,        delctr=0,fillspacectr=0;        //~va76I~
    int outoffstab,outoffs0,step,ch;
    int swnospace;
//********************************
UTRACED("chkTabShiftSLC",Pindwk->IDWoutbuff,Pindwk->IDWoutoffs);
    slcoffstab=Pindwk->IDWslcoffstab;
	pco0=Pindwk->IDWoutbuff;
	outoffs=outoffs0=Pindwk->IDWoutoffs;
	swnospace=(!Popt && (Pindwk->IDWopt & IDWO_KEEPWORD));//input has no space before // comment
	if (swnospace)
    {
        if (outoffs0)
        {
//          delctr=umemrspn(pco0,TABSPACE,outoffs0);               //~vaa0R~
            delctr=(int)umemrspn(pco0,TABSPACE,(unsigned)outoffs0);//~vaa0I~
            outoffs-=delctr;
        }
    }
    if (Pindwk->IDWstat&IDWS_TAB)
        outoffstab=getTabColumn(Pindwk,pco0,outoffs);
    else
        outoffstab=outoffs;
    if (slcoffstab>outoffstab)
    {
        if (swnospace)
        	fillspacectr=0;
        else
        	fillspacectr=slcoffstab-outoffstab;
    }
    else
    if (slcoffstab<outoffstab)
    {
		if (!swnospace)
        {
//          tabskip=Pindwk->IDWtabskip;                            //~va76R~
            if (outoffs)
            {
                pco=pco0+outoffs;
                ch=*(pco-1);
                if (ch==CH_SPACE||ch==CH_TAB)
                {
                    pco--;
                    for (;outoffs>0;pco--,outoffs--)
                    {
            UTRACEP("chkTabShift slcomment ch=%c,outoffs=%d,outoffstab=%d,slcoffstab=%d\n",ch,outoffs,outoffstab,slcoffstab);
                        if (ch==CH_SPACE)
                        {
                            outoffstab--;
                            if (outoffstab==slcoffstab)
                            {
                                outoffs--;
                                break;
                            }
                        }
                        else
                        if (ch==CH_TAB)
                        {
                            step=outoffstab-getTabColumn(Pindwk,pco0,outoffs-1);
                            outoffstab-=step;
                            if (outoffstab<=slcoffstab)
                            {
                                outoffs--;
                                break;
                            }
                        }
                        else
                            break;
            UTRACEP("chkTabShift slcomment outoffstab=%d,outoffs=%d\n",outoffstab,outoffs);
                        ch=*(pco-1);
                    }
                    delctr=outoffs0-outoffs;
                    fillspacectr=max(slcoffstab-outoffstab,0);
                }
            }
        }//input has space before // comment
    }
    *Ppspacectr=fillspacectr;
UTRACEP("chkTabShift slcomment slcoffstab=%d,delctr=%d,fillspacectr=%d\n",slcoffstab,delctr,fillspacectr);
    return delctr;
}//chkTabShiftSLC
//****************************************************************
// get valid plh
//*rc   :-1:eof or readlen except last \n
//****************************************************************
int funcRead(struct _INDWORK *Pindwk)
{
    int readlen,buffsz,opt,eolsz;                       //~@@@3R~  //~@@@5R~
	char *buff;                                                    //~@@@5R~
//*********************************
    opt=UFRO_DROPLF|UFRO_DROPCR|UFRO_DROPEOF|UFRO_LASTNULL;        //~@@@5I~
    buff=Pindwk->IDWlinedata;
    buffsz=Pindwk->IDWlinebuffsz;                                  //~@@@5R~
    for (;;)
    {
    	eolsz=ufreads(opt,Sfh,Sfilesz,buff,buffsz,&readlen);       //~@@@5R~
        Pindwk->IDWlineno++;
        UTRACEP("funcRead line=%d,eolsz=%d\n",Pindwk->IDWlineno,eolsz);//~@@@5I~
        if (eolsz<0)	//EOF or err                               //~@@@5I~
        	return -1;                                             //~@@@5I~
        if (Pindwk->IDWstat & IDWS_SPLIT1)
        {
            Pindwk->IDWstat |= IDWS_SPLIT2;
            Pindwk->IDWstat &=~IDWS_SPLIT1;
        }
        else
            Pindwk->IDWstat &= ~IDWS_SPLIT2;
		if (eolsz)		                                           //~@@@5I~
        {                                                          //~@@@5I~
            if (!readlen)
	            if (Pindwk->IDWstat & IDWS_SPLIT2)	//next of split
                {
			        Pindwk->IDWlineno--;
                	continue;		//line split at just before CRLF
                }
        }                                                          //~@@@5I~
        else                                                       //~@@@5I~
        {                                                          //~@@@5R~
			Pindwk->IDWstat |= IDWS_SPLIT1;                        //~@@@5R~
            if (!(Pindwk->IDWopt & IDWO_SPLITOK))                  //~@@@5R~
				xci_errmsg(EMO_LONGLINE,Pindwk,4);                 //~@@@5R~
        }
        break;
    }
    Pindwk->IDWdatalen=readlen;
UTRACED("funcRead",buff,readlen);                                  //~@@@5I~
    return readlen;                                                //~@@@5R~
}//funcRead
//**********************************************************************
//* write exception file
//**********************************************************************
int funcWrite(int Popt,struct _INDWORK *Pindwk)
{
	int rc=0,wsz,len,tabskip,sz;
    char *buff;
    char flags[MAX_TABCOLS];
//****************
	Pindwk->IDWoutlineno++;
    if (Popt & 1)
    {
    	buff=Pindwk->IDWoutbuff;
        len=Pindwk->IDWoutoffs;
        if (len!=Pindwk->IDWdatalen
//      ||  memcmp(buff,Pindwk->IDWlinedata,len))                  //~vaa0R~
        ||  memcmp(buff,Pindwk->IDWlinedata,(size_t)len))          //~vaa0I~
        {
            Pindwk->IDWupdatelineno++;
            Pindwk->IDWstat|=IDWS_UPDATED;
        }
    }
    else
    {
    	buff=Pindwk->IDWlinedata;
        len=Pindwk->IDWdatalen;
        Pindwk->IDWstat|=IDWS_COPYWRITE;
    }
    if (Sdebugmode)
    {
    	tabskip=Pindwk->IDWtabskip;
        sz=3+TABSKIPCTR(tabskip,3);
//  	memset(flags,CH_SPACE,sz);                                 //~vaa0R~
    	memset(flags,CH_SPACE,(size_t)sz);                         //~vaa0I~
        if (Pindwk->IDWstat&IDWS_UPDATED)
        	flags[0]=CH_UPDATE;
        else
        if (Pindwk->IDWstat&IDWS_MLCOMMENTONLY)
        	flags[0]=CH_STAR;
        else
        if (Pindwk->IDWstat&IDWS_SLCOMMENTONLY)
        	flags[0]=CH_SLASH;

        if (Pindwk->IDWstat&IDWS_ERR)
        	flags[1]=CH_ERR;
        if (Pindwk->IDWstat&IDWS_CONT1)
        	flags[2]=CH_CONT;
        flags[sz-1]=CH_SEP;
		wsz=(int)fwrite(flags,1,(size_t)sz,Sfho);
    	if (wsz!=sz)
	    	rc=4;
    }
    else
    if (Pindwk->IDWopt & IDWO_UPDATEFLAG)
    {
    	tabskip=Pindwk->IDWtabskip;
        sz=3+TABSKIPCTR(tabskip,3);
//  	memset(flags,CH_SPACE,sz);                                 //~vaa0R~
    	memset(flags,CH_SPACE,(size_t)sz);                         //~vaa0I~
        if (Pindwk->IDWstat&IDWS_UPDATED)
        	flags[0]=CH_UPDATE;
        if (Pindwk->IDWstat&IDWS_ERR)
        	flags[1]=CH_ERR;
        flags[sz-1]=CH_SEP;
		wsz=(int)fwrite(flags,1,(size_t)sz,Sfho);
    	if (wsz!=sz)
	    	rc=4;
    }
    if (len)
		wsz=(int)fwrite(buff,1,(size_t)len,Sfho);
    else
    	wsz=0;
    if (len!=wsz)
    	rc=4;
    else
		fwrite("\n",1,1,Sfho);
	Pindwk->IDWoutoffs=0;
	return rc;
}//funcWrite
//**********************************************************************
//*open outputfile
//**********************************************************************
int xci_errmsg(int Pcase,INDWORK *Pindwk,int Prc)
{
	int lineno;
//****************
	Pindwk->IDWerrlineno++;
    Pindwk->IDWstat|=IDWS_ERR;
    if (Pindwk->IDWopt & IDWO_1STERRMSG)  //issue only 1st errmsg
    {
  		if (Pindwk->IDWstat & IDWS_ERRMSG)
        	return Prc;
    }
    Pindwk->IDWstat|=IDWS_ERRMSG;
    lineno=Pindwk->IDWlineno;
	switch(Pcase)
    {
    case EMO_DQCLOSE:
        uerrmsg("E01:line-%4d:missing enclosing quotation",
                "E01:%4d 行目:引用符が閉じれていません",
                lineno);
        break;
	case EMO_BLOCKNEST:
        uerrmsg("E02:line-%4d:No no corresponding \"{\" for \"}\".",
                "E02:%4d 行目:\"}\"に対応する\"{\"がありません",
                lineno);
        break;
	case EMO_UNDERNEST:
        uerrmsg("E03:line-%4d:No corresponding statement.",
                "E03:%4d 行目:対応する文がありません",
                lineno);
        break;
	case EMO_OVERNEST:
        uerrmsg("E04:line-%4d:Statement nest overflow(>%d)\".",
                "E04:%4d 行目:文のネスト階層溢れ(>%d)",
                lineno,MAX_NEST);
        break;
	case EMO_LONGLINE:
        uerrmsg("E05:line %d:too long line(>=%d).",
                "E05:%4d 行目:入力行が長すぎます(>=%d)",
                lineno,Pindwk->IDWlinebuffsz);
        break;
	case EMO_LPRPUNMATCH:
        uerrmsg("E06:line-%4d:No no corresponding \")\" for \"(\".",
                "E06:%4d 行目:\")\"に対応する\"(\"がありません",
                lineno);
        break;
	case EMO_CASE:
        uerrmsg("E07:line-%4d:No corresponding \"switch\" for \"case\".",
                "E07:%4d 行目:\"case\"に対応する\"switch\"がありません",
                lineno);
        break;
	case EMO_ELSE:
        uerrmsg("E08:line-%4d:No corresponding \"if\"/\"elid\" for \"else\"/\"elif\".",
                "E08:%4d 行目:\"else\"/\"elif\"に対応する\"if\"/\"elif\"がありません",
                lineno);
        break;
	case EMO_CATCH:
        uerrmsg("E09:line-%4d:No corresponding \"try\" for \"catch\".",
                "E09:%4d 行目:\"catch\"に対応する\"try\"がありません",
                lineno);
        break;
	case EMO_MACRONEST:
        uerrmsg("E10:line-%4d:No corresponding Macro(\"#\") statement.",
                "E10:%4d 行目:対応するマクロ文(\"#\")がありません",
                lineno);
        break;
	case EMO_MACRONESTOVER:
        uerrmsg("E04:line-%4d:Statement nest overflow(>%d)\".",
                "E04:%4d 行目:マクロ文のネスト階層溢れ(>%d)",
                lineno,MAX_MACRONEST);
        break;
    }
    return Prc;
}//xci_errmsg
//**********************************************************************
//*open outputfile
//**********************************************************************
FILE *openoutfile(char **Pppfnmo,char *Prename)
{
    FILEFINDBUF3 fstat3;
	char *pfnmo;
    FILE *fho;
//******************
	pfnmo=*Pppfnmo;
    if (WILDCARD(pfnmo))
    {
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,(UCHAR*)Spfnm,(UCHAR*)pfnmo,(UCHAR*)Prename);    //src,patern,output
        pfnmo=Prename;
        *Pppfnmo=pfnmo;
    }

    if (!ufstat(pfnmo,&fstat3))
    {
        if (fstat3.attrFile & FILE_DIRECTORY)
            uerrexit("%s is directory",0,
                        pfnmo);
    }
    fho=fopen(pfnmo,"w");
    if (!fho)
        uerrexit("%s open failed,rc=%d",0,
                    pfnmo,errno);
    return fho;
}//openoutfile
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmprechk(int parmc,char *parmp[])
{
    int parmno;
  	char ch,*cptr;
//************************************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
  		{//option
    		ch=*(++cptr);                      //first option byte
    		switch(toupper(ch))             //option
    		{
    		case '?':
        		if (toupper(*(cptr+1))=='H'
        		||  toupper(*(cptr+1))=='?')
					help(1);
        		else
        			help(0);
                break;
    		case 'Y':
        	  	while(ch=*(++cptr),ch)
              	{
    				switch(toupper(ch))             //option
                	{
                	case '9':
                    	UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                    	UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                		break;
                	}
              	}
                break;
    		case 'N':
        	  	while(ch=*(++cptr),ch)
              	{
    				switch(toupper(ch))             //option
                	{
                	case '9':
                    	UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                   		UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                		break;
                    }
              	}
                break;
            }//sw
    	}//flag
	}//for all parm
}//parmprechk
//****************************************************************
// calc fmt opd chk
//*rc   :0
//****************************************************************
int opdchk(int Popdno,char **Ppopd)
{
    char *pc;
    int  ii,posparmno=0,rc2;
	FILEFINDBUF3 ffb3;
//*********************************
    if (Popdno<=1)
        help(0);
    for (ii=1;ii<Popdno;ii++)
    {
    	pc=Ppopd[ii];
    	if (*pc==CMDFLAG_PREFIX || *pc==CMDFLAG_PREFIX2)	//flag parm
        {
			rc2=fmtopdchk4(pc+1);
            if (rc2)
            {
            	if (rc2==16)
                	return rc2;
                else
                	return opderr(pc);
            }
        }
        else
        {
        	if (!posparmno)	//1st postional parm
            	Spfnm=pc;		//filename
            else
            {
            	return opderr(pc);
            }
            posparmno++;
        }
    }
    if (!posparmno)
    	uerrexit("specify input filename",0);
//  rc2=ufstat(Spfnm,&ffb3);                                       //~vaa0R~
    rc2=(int)ufstat(Spfnm,&ffb3);                                  //~vaa0I~
    if (rc2)
    	uerrexit("%s not found",0,Spfnm);
    Sfilesz=(long)ffb3.cbFile;                                     //~@@@5R~
    Sfh=fopen(Spfnm,"rb");
    if (!Sfh)
    	uerrexit("%s open failed",0,Spfnm);
    UTRACEP("%s size is %ld\n",Spfnm,Sfilesz);
    return 0;
}//opdchk
//****************************************************************
// xfmt specific parm
//*rc   :0  ,4
//****************************************************************
int fmtopdchk4(char *Popd)
{
	char *pc,*pc2;
    int ch,len,swdefined=0;                                        //~@@@4R~
//***************************
    pc=Popd;
    switch(toupper(*pc))
    {
    case 'H':
    case '?':
        break;
    case 'B':
        pc2=pc+1;
        Smaxlinesz=atoi(pc2);
        if (Smaxlinesz<MAX_LINESZ_MIN||Smaxlinesz>MAX_LINESZ_MAX)
        {
        	uerrmsg("Input Buffser size err(%s), It shoud be >=%d && <=%d",0,
            		pc,MAX_LINESZ_MIN,MAX_LINESZ_MAX);
	        return 16;  //no parm err
        }
        break;
    case 'D':                                                      //~@@@4I~
        swdefined=1;                                               //~@@@4I~
    case 'U':                                                      //~@@@4I~
        pc2=pc+1;                                                  //~@@@4I~
//      if (len=strlen(pc2),len)                                   //~@@@4R~//~vaa0R~
        if (len=(int)strlen(pc2),len)                              //~vaa0I~
        {                                                          //~@@@4I~
            if (Smacroparmctr<MAX_MACROPARM)                       //~@@@4I~
            {                                                      //~@@@4I~
                if (!swdefined)                                    //~@@@4I~
	                SmacroparmUndef[Smacroparmctr]=1;              //~@@@4I~
                SmacroparmLen[Smacroparmctr]=len;                  //~@@@4I~
                Smacroparm[Smacroparmctr++]=pc2;                   //~@@@4R~
            }                                                      //~@@@4I~
            else                                                   //~@@@4I~
        		uerrexit("macro parameter count overflow max is %d(%s)",0,//~@@@4I~
            		MAX_MACROPARM,pc);                             //~@@@4I~
        }                                                          //~@@@4I~
        break;                                                     //~@@@4I~
    case 'E':
        pc2=pc+1;
        Smaxifelse=atoi(pc2);
        break;
    case 'I':
        pc2=pc+1;
        Sindcols=atoi(pc2);
        if (Sindcols<=0||Sindcols>MAX_INDCOLS)
        {
        	uerrmsg("Indentation columns err(%s), It shoud be >0 && <=%d",0,
            		pc,MAX_INDCOLS);
	        return 16;
        }
        break;
    case 'O':		//input delm
        Spfnmo=pc+1;
        break;
    case 'T':
        pc2=pc+1;
        Stabcols=atoi(pc2);
        if (Stabcols<=0||Stabcols>MAX_TABCOLS)
        {
        	uerrmsg("Tab skip columns err(%s), It shoud be >0 && <=%d",0,
            		pc,MAX_TABCOLS);
	        return 16;
        }
        break;
    case 'Y':
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'D':
                Sdebugmode=1;
                break;
            case 'H':
                Shelpmsg=1;
                break;
            case 'L':
                Ssplitok=0;
                break;
		    case 'S':		//shift comment
        		Snoslcshift=0;
        		break;
		    case 'U':                                              //~@@@4I~
        		Supdateflag=1;                                     //~@@@4I~
        		break;                                             //~@@@4I~
		    case 'W':		//shift comment
        		Skeepword=1;
        		break;
            default:
	            return opderr(Popd);
            }
        }
        break;
    case 'N':
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'D':
                Sdebugmode=0;
                break;
            case 'H':
                Shelpmsg=0;
                break;
            case 'L':
                Ssplitok=1;
                break;
		    case 'S':		//shift comment
        		Snoslcshift=1;
        		break;
		    case 'U':                                              //~@@@4I~
        		Supdateflag=0;                                     //~@@@4I~
        		break;                                             //~@@@4I~
		    case 'W':		//shift comment
        		Skeepword=0;
        		break;
            default:
	            return opderr(Popd);
            }
        }
        break;
    default:
        return 4;
    }
    return 0;
}//fmtopdchk4
//****************************************************************
int opderr(char *Pparm)
{
    uerrexit("parm(%s) err",0,Pparm);
    return 4;
}//opderr
//****************************************************************
// hel for fmt
//*ret :0
//****************************************************************
int help(int Popt)
{
        HELPMSG
"%s : %s=(%c)= Indentation for C source text(C, C++, Java).\n",
"%s : %s=(%c)= C \x83\\ーステキストのインデンテーション(C, C++, Java)\n",
                Spgm,Sver,OSTYPE);
        HELPMSG
"format:%s [%coptions] filename\n",
"形式  :%s [%coptions] filename\n",
                Spgm,CMDFLAG_PREFIX);
        HELPMSG                                                    //~@@@4I~
"*******************************************************************************\n", //80 column limit indicator//~@@@4R~
"*******************************************************************************\n");//~@@@4R~
        HELPMSG
"  options\n",                                                     //~@@@4R~
"  options\n");                                                    //~@@@4R~
        HELPMSG
"    %cBn         :Input Buffer size. Default is n=%d\n",
"    %cBn         :入力バッファーサイズ。省略値は n=%d\n",
				CMDFLAG_PREFIX,MAX_LINESZ);
        HELPMSG                                                    //~@@@4R~
"    %cDxxx       :Macro parameter for #ifdef/#else path selection.\n",//~@@@4R~
"    %cDxxx       :#ifdef/#elseの経路を選択するためのマクロパラメータ\n",//~@@@4R~
				CMDFLAG_PREFIX);                                   //~@@@4R~
        HELPMSG                                                    //~@@@4R~
"                 Use when unmatch error of \"if\" and \"else\", \"{\" and \"}\"\n",//~@@@4R~
"                 \"if\" と \"else\", \"{\" と \"}\"の不一致が発生するときに使用.\n");//~@@@4R~
        HELPMSG                                                    //~@@@4I~
"                 With %cU, up to number of %d. ex) %cDWIN32 %cU_UNICODE.\n",//~@@@4I~
"                 %cUと共に最大 %d 個まで指定. 例) %cDWIN32 %cU_UNICODE.\n",//~@@@4I~
				CMDFLAG_PREFIX,MAX_MACROPARM,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~@@@4I~
        HELPMSG
"    %cEn         :if-else-if-else... repeat limit for indentation.\n",
"    %cEn         :if-elseの繰り返しに対するインデンテーション制限値\n",
				CMDFLAG_PREFIX);
        HELPMSG
"                 \"0\" means no-limit. Default is n=%d\n",
"                 \"0\"は無制限にインデンテーションする。省略値はn=%d\n",
				DEFAULT_IFELSE);
        HELPMSG
"    %cIn         :Indentation space count. Default is n=%d\n",
"    %cIn         :インデンテーション桁ずらし数。省略値は n=%d\n",
				CMDFLAG_PREFIX,DEFAULT_INDCOLS);
        HELPMSG
"    %cOxxx       :Output filename. default is stdout.\n",
"    %cOxxx       :出力ファイル省略値はstdout\n",
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~@@@4I~
"                 Use wildcard(*) to edit from input filename\n",  //~@@@4I~
"                 ワイルドカードで入力ファイルから編集することも可\n");//~@@@4I~
        HELPMSG
"    %cTn         :Tab skip columns. Default is n=%d\n",
"    %cTn         :タブによる桁ずらし数。省略値は n=%d\n",
				CMDFLAG_PREFIX,DEFAULT_TABCOLS);
        HELPMSG                                                    //~@@@4I~
"    %cUxxx       :explicitly #undef the macro.\n",                //~@@@4R~
"    %cUxxx       :明示的にマクロを#undefする\n",                  //~@@@4R~
				CMDFLAG_PREFIX);                                   //~@@@4I~
        HELPMSG                                                    //~@@@4I~
"\n",                                                              //~@@@4I~
"\n");                                                             //~@@@4I~
    if (Popt & 1)
    {
        HELPMSG
"    %cYd         :Debug Mode.\n",
"    %cYd         :デバッグモード\n",
				CMDFLAG_PREFIX);
    }
    if (Popt & 1)
    {
        HELPMSG
"    %cYh         :assme \"(\" after \"HELPMSG\" macro.\n",
"    %cYh         :\"HELPMSG\"マクロのあとに\"(\"を想定する\n",
				CMDFLAG_PREFIX);
    }
        HELPMSG                                                    //~@@@4M~
"    %cYu         :set line changed flag(\"%c\").\n",              //~@@@4I~
"    %cYu         :変更行に識別フラグ(\"%c\")を\x95\\示\n",        //~@@@4I~
				CMDFLAG_PREFIX,CH_UPDATE);                         //~@@@4M~
        HELPMSG
"    %cYw         :Keep space exist or not in front of line comment(//).\n",
"    %cYw         :行コメント前のスペース有無は保持する\n",
				CMDFLAG_PREFIX);
        HELPMSG
"                  Use with %cNs to compare by \"xfc\" utility.\n",//~@@@5R~
"                  ツール\"xfc\" で結果をチェックするため %cNs と共に指定\n",//~@@@5R~
				CMDFLAG_PREFIX);                                   //~@@@5R~
        HELPMSG                                                    //~@@@5I~
"                     ex) \"xfc %cW src.c  src.xciout\".\n",       //~@@@5R~
"                     例えば \"xfc %cW src.c  src.xciout\".\n",    //~@@@5R~
				CMDFLAG_PREFIX);                                   //~@@@5I~
        HELPMSG
"    %cNl         :Ignore Long line Error Msg.\n",
"    %cNl         :入力行長オーバーのエラーMsgを出さない\n",
				CMDFLAG_PREFIX,CH_UPDATE);
        HELPMSG
"    %cNs         :Keep \"//\" comment posiotion if possible.\n",
"    %cNs         :可\x94\\なら\"//\"コメントの位置はシフトしない\n",
				CMDFLAG_PREFIX);
        HELPMSG
"  ex) %s file3 %cI4 %cT4,   %s file2.c %cO*.ind %cNs\n",          //~@@@4R~
"  例) %s file3 %cI4 %cT4,   %s file2.c %cO*.ind %cNs\n",          //~@@@4R~
               Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);
    exit(1);
#ifndef VC10EXP	//C4702 unreachable warning
    return 0;
#endif
}//help
