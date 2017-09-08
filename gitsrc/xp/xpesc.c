//*CID://+v9e6R~:                             update#=  107;       //~v9e6R~
//**********************************************************************//~5A28I~
//* xpesc.c                                                     //~5A29R~
//**********************************************************************//~v74lI~
//v9e6:170826 compiler warning samename parm and gbl               //~v9e6I~
//v98i:140208 (BUG)Paper width/haight re-evaluation is required when orientation was changed by dialog//~v98iI~
//v987:140201 (BUG)when papersize change by dialog,need to adjust maxcol/maxline//~v987I~
//v977:131025 (gxp)other pagesize support by margin shift /E/pper/[T|B|L|R[nn]]//~v977I~
//v974:131011 (GtkPrint)no cmdfile support                         //~v974I~
//v973:131011 (GtkPrint)new form option(E[w]/form[L](2p is by /Y2 only)//~v973I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//071014 v92j (Win/GXP)set maxline when line pitch specified without line count//~v92jI~
//071013 v92f (Win)auto-set maxcol/maxline when not predefined pich specified//~v92fI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//040920 v91p :correct error msg(form type err)                    //~v91pI~
//020803 v91d ajust default cols/line table                        //~v91dI~
//020727 v91a ajust maxcol of form2p                               //~v91aI~
//020727 v918 (BUG)maxcol for b5p                                  //~v918I~
//020727 v917 (BUG)minimum colomn for form2p is not 70(COLMAX1)    //~v917I~
//020720 v916 (WIN)auto set form orientation                       //~v916I~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//020518 v9.3 v90y support form parm for printer type=win          //~v90yI~
//020518 v9.3 v90x set default when printer type missing(like as /E/B4)//~v90xI~
//020408 v90w :(BUG)compiler warning for aix                       //~v90wR~
//010522 v90i :LINUX support(default change-->/N1)                 //~v90iI~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//990915 v891 :EBCDIC support /M.e[k/e]                            //~v891I~
//981116 v883 :(WIN)calc lpi for also line numbers not specified(default)//~v883I~
//981116 v881 :(CANON)fo non FONT case also,soft reset cmd is at 1st page only//~v881I~
//981116 v880 :(WIN)calc cpi for also calc char numbers            //~v880I~
//981116 v879 :LinePrinter-Bold is not unreadable print            //~v879I~
//981115 v877 :(WIN)any value lpi                                  //~v877I~
//981115 v876 :(WIN)drop 18cpi because cpi can be any value and may calc by maxcol//~v876I~
//981114 v875 :(WIN)set lpi when specified maxline only(no lpi/no form specified)//~v875I~
//981114 v874 :(WIN)set cpi when specified maxcol only(no cpi/no form specified)//~v874I~
//981114 v873 :(WIN)any cpi value support                          //~v873I~
//981114 v872 :(WIN)133 colum support(18cpi)                       //~v873R~
//981114 v871 :(CANON)esccmd jobstart+soft reset cause printer performance down//~v871I~
//981104 v870 :(BUG:cannon)DBCS space should be double of SBCS,    //~v864I~
//              and it is scalable if chande to G2                 //~v864I~
//981024 v864 :setup graphic set for CANON                         //~v864I~
//             Swiss,Dutch,Ncourier for ascii                      //~v864I~
//             try intermedeate cpi for cannon(for v787)           //~v864I~
//981006 v854 :IBM printer CPI=7.2 is ignored                      //~v854I~
//981005 v848 :char set cmd for ESCP(ESCt)                         //~v848I~
//981001 v845 :printer type=IBM/CANON,cpi=75 treated as cpi=7.2    //~v845I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//971124 v831 :split xppf from xprint                              //~v831I~
//971123 v827 :split xpsub1 from xrint.c                           //~v827I~
//970928 v826 :w95 version                                         //~v826I~
//970214 v807:use FINDBUF3 by ufile.h                              //~v807I~
//961210 v788:72cpi for ibm pagep                                  //~v788I~
//961210 v787:lipsIII kanji cpi is fixed at 72 cpi(max colum=100)  //~v787I~
//961210 v786:use unit 1/180 inchi not but 1/360 inch              //~v786I~
//            because canon escp emulator not supported 1/360      //~v786I~
//961108 v785:1st page EJECT bypass option                         //~v785I~
//961106 v784:ESCP has ROMAN font                                  //~v784I~
//961106 v783:Cannon printer support(LIPS-III)                     //~v783I~
//960113 v752 :set lpitch default to 6-lpi                      //~v752I~
//950829 v74l :form id on /E                                    //~v74lI~
//**********************************************************************//~5A28I~
#include <time.h>     //v1.1                                    //~5A28I~
#include <stdio.h>                                              //~5A28I~
#include <stdlib.h>                                             //~5A28I~
#include <ctype.h>    //v1.6add                                 //~5A28I~
#include <string.h>   //v1.3add                                 //~5A28I~
                                                                //~5A28I~
#ifdef DOS                           //v3.6a                    //~5A28I~
#else                                                           //~5A28I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
	#define INCL_BASE                     //v1.3 add v3.7r      //~5A28I~
	#include <os2.h>         //v1.3 add                         //~5A28I~
  #endif                                                           //~v826I~
#endif                                                          //~5A28I~
                                                                //~5A28I~
#include <ulib.h>   //v1.3add                                   //~5A29I~
#include <ufile.h>   //v1.3add                                     //~v807I~
#include <utrace.h>   //v1.3add                                    //~v977I~
#ifdef GXP                                                         //~v92fI~
	#include <uerr.h>                                              //~v92fR~
#endif                                                             //~v92fI~
                                                                //~v74lI~
#include "xp.h"                                                 //~v74lI~
#include "xpesc.h"                                                 //~v831I~
#include "xpsub1.h"                                                //~v827I~
#ifdef W32                                                         //~v844I~
	#include  "xpwinp.h"                                           //~v844I~
#endif                                                             //~v844I~
#ifdef GXP                                                         //~v92dR~
	#include  "xplnxp.h"                                           //~v92dI~
#endif                                                             //~v92dI~
//*********************************************************************//~5A28I~
typedef struct _FORML{                                          //~v74lM~
                  	  char* 		formname;                   //~v74lM~
	                  int           formid;                     //~v74lM~
	                } FORML;                                    //~v74lM~
//*form id                                                      //~v74lI~
#define FORM_A4P        0                                       //~v74lM~
#define FORM_A4L        1                                       //~v74lM~
#define FORM_B4P        2                                       //~v74lM~
#define FORM_B4L        3                                       //~v74lM~
#define FORM_B5P        4                                       //~v74lM~
#define FORM_B5L        5                                       //~v74lM~
#define FORM_A4P2       6                                          //~v911I~
#define FORM_A4L2       7                                          //~v911I~
#define FORM_B4P2       8                                          //~v911I~
#define FORM_B4L2       9                                          //~v911I~
#define FORM_B5P2      10                                          //~v911I~
#define FORM_B5L2      11                                          //~v911I~
                                                                //~v74lI~
#define PITCH_5CPI      0                                       //~v74lI~
#define PITCH_6CPI      1                                       //~v74lI~
#define PITCH_67CPI     2                                       //~v74lI~
#define PITCH_75CPI     3                                       //~v74lI~
#define PITCH_72CPI     4                                          //~v787I~
                                                                //~v74lI~
#define PITCH_2LPI      0                                       //~v74lI~
#define PITCH_3LPI      1                                       //~v74lI~
#define PITCH_4LPI      2                                       //~v74lI~
#define PITCH_5LPI      3                                       //~v74lI~
#define PITCH_6LPI      4                                       //~v74lI~
#define PITCH_75LPI     5                                       //~v74lI~
#define PITCH_8LPI      6                                       //~v74lI~
#define ESCPLPIBASE   180     	//by unit 1/180 cpi                //~v788I~
//*********************************************************************//~v864I~
#define CMD_ESC     0x1b                                           //~v864I~
#define CMD_SO		0x0e                                           //~v864I~
#define CMD_SI		0x0f                                           //~v864I~
//*********************************************************************//~v74lI~
#define CRLF     '\n' //0x0d0a v2.7add                          //~5A28I~
//*********************************************************************//~5A28I~
       char esccmd[MAXESCCMD];          //v2.9add esc command string v2.9add v5.5r//~5A28I~
       int endjobreq;                   //canon endjob requied sw  //~v864I~
	char topcmd[32];    //CANON:cmd only at top of page of each file//~v871I~
    int  topcmdlen;		//CANON:cmd only at top of page of each file//~v871I~
    int  Gformtype=PFT_A4;		//Form type,LANDSCAPE or FORM2P    //~v916R~
//*********************************************************************//~5A28I~
extern char pgmid[];                                            //~5A28R~
extern char ver[];                                              //~5A28R~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r//~5A28I~
extern int maxcol;      //colomn no per line v1.4rep v1.7rep v7.23r//~v74lI~
//extern int colomnspec;                                           //~v880R~
extern char docname[];                                             //~v844I~
//extern int colmax1;  	//maxcolomn for  pich 5cpi                 //~v787R~
//extern int colmax2;  	//maxcolomn for  pich 6cpi                 //~v787R~
//extern int colmax3;  	//maxcolomn for  pich 6.7cpi if over pich 7.5 cpi//~v787R~
extern int maxline;    //line   no per page v7.23r              //~v74lI~
extern int linespec;      //line option specified sw  v6.7a     //~v74lI~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~5A28I~
extern int escsw;            //Esc cmd issue sw v3.3add         //~5A28I~
extern int lineprefixsw;		//line prefix output v7.12a     //~5A28I~
extern int  cpitch,lpitch;	//pitch parameter        v7.24a     //~5A28I~
extern char *fontstyle;	//font style parm    v7.24a             //~5A28R~
extern int Gebcdictype;      //1:katakana,2:english            v2.5add//~v891I~
extern int asciimode;        //char set id                     v2.5add//~v848I~
//extern int  fontid;        	//font style parm    v7.24a        //~v783R~
//extern int  fontid2;        	//ESCP kanji         v7.28a        //~v783R~
//*****************************************************************//~v783R~
#ifdef GTKPRINT                                                    //~v973I~
    static int Sotherform;   //col/line calc by pagesize           //~v973I~
    #define CUSTOM_CPI       72      //7.2cpi                      //~v973I~
    #define CUSTOM_LPI       DEFAULTLPI     //6lpi                 //~v973I~
#endif                                                             //~v973I~
#if defined(W32)||defined(GXP)                                     //~v92fR~
    static int Scolbypitch=0,Srowbypitch=0;                        //~v92fI~
#endif                                                             //~v92fI~
//static int colmax1=COLMAX1;  	//maxcolomn for  pich 5cpi v7.23a  //~v917R~
       int colmax1=COLMAX1;  	//maxcolomn for  pich 5cpi v7.23a  //~v917I~
static int colmax2=COLMAX2;  	//maxcolomn for  pich 6cpi v7.23a  //~v787I~
static int colmax3=COLMAX3;  	//maxcolomn for  pich 6.7cpi if over pich 7.5 cpi v7.23a//~v787I~
static int colmax4=COLMAX4;  	//maxcolomn for  pich 72cpi if over pich 7.5 cpi v7.23a//~v787I~
//#ifdef W32                                                       //~v876R~
//static int colmax5=105;         //WIN only,maxcolomn for  pich 75cpi if over pich 9.0//~v876R~
//#endif                                                           //~v876R~
static int  fontid=0;        	//font style parm    v7.24a        //~v783R~
static int  fontid2=0;        	//ESCP kanji         v7.28a        //~v783R~
static int  fontsetreq=0;     	//setup font cmd                   //~v864I~
static int Sformid;                                             //~v74lM~
#ifdef GTKPRINT                                                   //~v980I~//~v977I~//~v98iR~
	static char *Sdialogpapersize;                                 //~v977I~
#endif                                                             //~v980I~//~v977I~
//#ifdef W32                                                       //~v90yR~
//static int Sformspecsw;                                          //~v90yR~
//#endif                                                           //~v90yR~
static FORML Sformlist[]={                                      //~v74lM~
			{"A4", FORM_A4P},                                   //~v74lR~
			{"A4P",FORM_A4P},                                   //~v74lM~
			{"A4V",FORM_A4P},                                   //~v74lM~
			{"A4L",FORM_A4L},                                   //~v74lM~
			{"A4H",FORM_A4L},                                   //~v74lM~
                                                                //~v74lM~
			{"B4", FORM_B4P},                                   //~v74lR~
			{"B4P",FORM_B4P},                                   //~v74lR~
			{"B4V",FORM_B4P},                                   //~v74lR~
			{"B4L",FORM_B4L},                                   //~v74lR~
			{"B4H",FORM_B4L},                                   //~v74lR~
                                                                //~v74lM~
			{"B5", FORM_B5P},                                   //~v74lR~
			{"B5P",FORM_B5P},                                   //~v74lR~
			{"B5V",FORM_B5P},                                   //~v74lR~
			{"B5L",FORM_B5L},                                   //~v74lR~
			{"B5H",FORM_B5L},                                   //~v74lR~
                                                                   //~v911I~
			{"A42", FORM_A4P2},                                    //~v911R~
			{"A4P2",FORM_A4P2},                                    //~v911I~
			{"A4V2",FORM_A4P2},                                    //~v911I~
			{"A4L2",FORM_A4L2},                                    //~v911I~
			{"A4H2",FORM_A4L2},                                    //~v911I~
                                                                   //~v911I~
			{"B42", FORM_B4P2},                                    //~v911I~
			{"B4P2",FORM_B4P2},                                    //~v911I~
			{"B4V2",FORM_B4P2},                                    //~v911I~
			{"B4L2",FORM_B4L2},                                    //~v911I~
			{"B4H2",FORM_B4L2},                                    //~v911I~
                                                                   //~v911I~
			{"B52", FORM_B5P2},                                    //~v911I~
			{"B5P2",FORM_B5P2},                                    //~v911I~
			{"B5V2",FORM_B5P2},                                    //~v911I~
			{"B5L2",FORM_B5L2},                                    //~v911I~
			{"B5H2",FORM_B5L2},                                    //~v911I~
            {0}                                                 //~v74lM~
            };                                                  //~v74lM~
static PITCHL Spitchtbl[]={                                     //~v74lI~
//cpi  5,  6,6.7,7.5,               7.2,                           //~v911I~
	{{{COLMAX1,COLMAX2,COLMAX3,MAXCOL,100},{  75, 90,100,115,110}}, MAXLINE,PFT_A4},//A4P//~v91pR~
//	{ 70, 85, 95,105,   	        100,  75, 90,100,115,110, 60}, //A4P//~v787R~
//  {100,125,140,155, /*a4l*/   	145, 110,130,145,165,155, 39,PFT_A4|PFT_YOKO}, //A4L//~v91dR~
    {{{100,125,140,155, /*a4l*/   	145},{ 110,130,145,165,155}}, 42,PFT_A4|PFT_YOKO}, //A4L//~v91pR~
	{{{ 85,105,120,135,   			125},{  95,110,125,140,130}}, 75,PFT_B4}, //B4P//~v91pR~
//  {125,150,165,190, /*b4l*/   	180, 130,155,175,195,185, 50,PFT_B4|PFT_YOKO}, //B4L//~v91dR~
    {{{130,155,175,195, /*b4l*/   	180},{ 135,160,180,205,185}}, 53,PFT_B4|PFT_YOKO}, //B4L//~v91pR~
//  { 60, 70, 80, 90, /*b5p*/   	 85,  65, 75, 85, 95, 90, 50,PFT_B5}, //B5P//~v91dR~
    {{{ 55, 70, 80, 90, /*b5p*/   	 85},{  65, 75, 85, 95, 90}}, 53,PFT_B5}, //B5P//~v91pR~
//  { 85,105,120,135, /*b5l*/   	125,  95,115,125,140,130, 33,PFT_B5|PFT_YOKO}, //B5L//~v91dR~
    {{{ 85,105,120,135, /*b5l*/   	125},{  95,110,125,140,130}}, 35,PFT_B5|PFT_YOKO}, //B5L//~v91pR~
//  { 30, 40, 45, 50, /*a4p2*/  	 50,  35, 45, 50, 55, 55, 60,PFT_A4|PFT_2P}, //A4P2//~v91dR~
    {{{ 30, 35, 40, 50, /*a4p2*/  	 45},{  35, 40, 45, 55, 50}}, 60,PFT_A4|PFT_2P}, //A4P2//~v91pR~
//  { 45, 60, 65, 75, /*a4l2*/  	 70,  50, 65, 70, 80, 75, 39,PFT_A4|PFT_YOKO|PFT_2P}, //A4L2//~v91dR~
    {{{ 45, 55, 65, 75, /*a4l2*/  	 70},{  50, 65, 70, 80, 75}}, 42,PFT_A4|PFT_YOKO|PFT_2P}, //A4L2//~v91pR~
//  { 40, 50, 55, 65, /*b4p2*/  	 60,  45, 55, 60, 70, 65, 75,PFT_B4|PFT_2P}, //B4P2//~v91dR~
    {{{ 40, 45, 55, 60, /*b4p2*/  	 60},{  45, 55, 60, 70, 65}}, 75,PFT_B4|PFT_2P}, //B4P2//~v91pR~
//  { 60, 75, 85, 95, /*b4l2*/  	 90,  65, 80, 90,100, 95, 50,PFT_B4|PFT_YOKO|PFT_2P}, //B4L2=B5//~v91dR~
    {{{ 60, 70, 80, 95, /*b4l2*/  	 85},{  65, 80, 85,100, 90}}, 53,PFT_B4|PFT_YOKO|PFT_2P}, //B4L2=B5//~v91pR~
//  { 25, 30, 35, 40, /*b5p2*/  	 40,  30, 35, 40, 45, 45, 50,PFT_B5|PFT_2P}, //B5P2//~v91dR~
    {{{ 25, 30, 35, 40, /*b5p2*/  	 40},{  30, 35, 40, 45, 45}}, 53,PFT_B5|PFT_2P}, //B5P2//~v91pR~
//  { 40, 50, 55, 65, /*b5l2*/  	 60,  45, 55, 60, 70, 65, 33,PFT_B5|PFT_YOKO|PFT_2P}, //B5L2//~v91dR~
    {{{ 40, 45, 55, 60, /*b5l2*/  	 60},{  45, 55, 60, 70, 65}}, 35,PFT_B5|PFT_YOKO|PFT_2P}, //B5L2//~v91pR~
//  0};                                                            //~v91pI~
    {{{  0,  0,  0,  0, /*last*/  	  0},{   0,  0,  0,  0,  0}},  0,0                     }};//terminater//~v91pR~
//**********************************************************************//~v864I~
void canonfontset(int Pvmi,int Phmi);                              //~v864R~
//**********************************************************************//~v74lI~
//* ESC form parm chk                                           //~v74lI~
//**********************************************************************//~v74lI~
void escformchk(char *Pform)                                    //~v74lI~
{                                                               //~v74lI~
	int ii;                                                     //~v74lI~
    char *pc;                                                   //~v74lI~
#ifdef GTKPRINT                                                    //~v973I~
	int rcformchk=0;                                               //~v973I~
#endif                                                             //~v973I~
//********************                                          //~v74lI~
	UTRACEP("escformchk form=%s\n",Pform);                         //~v977R~
#ifdef GTKPRINT                                                    //~v98iI~
    if (Sdialogpapersize)                                          //~v977I~
    	Pform=Sdialogpapersize;                                    //~v977I~
	UTRACEP("escformchk form=%s,of dialog=%s\n",Pform,Sdialogpapersize);//~v977R~
#endif                                                             //~v980I~//~v977I~
#ifdef GTKPRINT                                                    //~v973I~
	Gpapersizeparm=0;                                              //~v973R~
#endif                                                             //~v973I~
    if (!*Pform)                                                //~v74lI~
    	ii=0;                                                   //~v74lR~
	else                                                        //~v74lI~
    {                                                           //~v74lI~
//#ifdef W32                                                       //~v90yR~
//        Sformspecsw=1;          //form specified sw              //~v90yR~
//#endif                                                           //~v90yR~
    	if (*Pform=='/')                                        //~v74lI~
        	Pform++;                                            //~v74lI~
#ifdef GTKPRINT    	                                               //~v973M~
		rcformchk=lnx_formchk(Pform);	//cups form chk,-1:err,0:port,1:landscape;drop shift parm//~v973R~//~v977R~
#endif                                                             //~v973M~
		for (ii=0;pc=Sformlist[ii].formname,pc;ii++)            //~v74lR~
    		if (!stricmp(Pform,pc))                             //~v74lR~
        		break;                                          //~v74lR~
    }                                                           //~v74lI~
    if (!Sformlist[ii].formname)	//not found                 //~v74lI~
    {                                                              //~v91pI~
#ifdef GTKPRINT                                                    //~v973I~
		if (rcformchk==0)                                          //~v973R~
        	ii=FORM_A4P;                                           //~v973I~
        else                                                       //~v973I~
        	ii=FORM_A4L;                                           //~v973I~
        Sotherform=1;   //col/line calc by pagesize                //~v973I~
#else                                                              //~v973I~
		if (dbcsenv)	//DBCS mode                             //~v74lI~
//      	optionerr("Esc/用紙タイプ",Pform);//errmsg and exit v4.9a//~v91pR~
        	optionerr("用紙タイプ",Pform);//errmsg and exit v4.9a  //~v91pI~
		else			//SBCS mode                             //~v74lI~
//      	optionerr("Esc/form type",Pform);//errmsg and exit v3.8r//~v91pR~
        	optionerr("form type",Pform);//errmsg and exit v3.8r   //~v91pI~
#endif                                                             //~v973I~
    }                                                              //~v91pI~
	Sformid=Sformlist[ii].formid;                               //~v74lI~
	Gformtype=Spitchtbl[Sformid].formtype;                         //~v916R~
#ifdef GTKPRINT                                                    //~v977I~
	if (rcformchk==1)	//cups form chk,-1:err,0:port,1:landscape;drop shift parm//~v977I~
    {                                                              //~v98iI~
		Gformtype=PFT_YOKO;                                        //~v977I~
		Gformtype|=PFT_REVERSE;	//default for cmdline parm         //~v98iI~
    }                                                              //~v98iI~
#endif                                                             //~v977I~
	if (Gformtype & PFT_2P)                                        //~v916R~
    	UCBITON(swsw3,SW3FORM2P);	//2p form                      //~v911I~
    return;                                                     //~v74lI~
}//escformchk                                                   //~v74lI~
#ifdef GTKPRINT                                                   //~v980I~//~v987R~//~v98iR~
//**********************************************************************//~v987R~
//* replace parameter formname by papersize selected by dialog     //~v987R~
//*Plandscape:0:port,1:landscape,2:reverse portrait,3:reverse landscape//~v98iI~
//**********************************************************************//~v987R~
int escformchkGtk(char *Pform,char *Pdisplayname,int Plandscape)   //~v987R~
{                                                                  //~v987R~
	int ii,rc=1;                                                   //~v987R~
    char landscapeform[32],*pform,*pc;                             //~v987R~
//********************                                             //~v987R~
    UTRACEP("escformchkGtk Plandscape=%d,form=%s,display=%s\n",Plandscape,Pform,Pdisplayname);//~v98iI~
	pform=Pdisplayname;                                            //~v987R~
//  if (Plandscape)                                                //~v987R~//~v98iR~
    if (Plandscape & 1)	//landscape or reverse landscape           //~v98iI~
    {                                                              //~v987R~
    	strcpy(landscapeform,Pdisplayname);                        //~v987R~
        strcat(landscapeform,"L");                                 //~v987R~
		pform=landscapeform;                                       //~v98iR~
		Gformtype|=PFT_YOKO;                                       //~v98iI~
        if (Plandscape==3)                                         //~v98iI~
			Gformtype|=PFT_REVERSE; //reverse landscape            //~v98iI~
        else                                                       //~v98iI~
			Gformtype&=~PFT_REVERSE; //reverse landscape           //~v98iI~
    }                                                              //~v987R~
    else                                                           //~v98iI~
    {                                                              //~v98iI~
		Gformtype&=~PFT_YOKO;                                      //~v98iI~
        if (Plandscape==2)                                         //~v98iI~
			Gformtype|=PFT_REVERSE;	//reverse portrait             //~v98iI~
        else                                                       //~v98iI~
			Gformtype&=~PFT_REVERSE; //reverse landscape           //~v98iI~
    }                                                              //~v98iI~
                                                                   //~v98iI~
	for (ii=0;pc=Sformlist[ii].formname,pc;ii++)                   //~v987R~
    	if (!stricmp(pform,pc))                                    //~v987R~
        {                                                          //~v987R~
        	rc=0;	//not otherform                                //~v987R~
			Sformid=Sformlist[ii].formid;                          //~v98iI~
        	pform=pc;                                              //~v987R~
        	break;                                                 //~v987R~
        }                                                          //~v987R~
    if (rc)                                                        //~v98iI~
    {                                                              //~v98iI~
		pform=Pform;                                               //~v98iI~
    	if (Plandscape & 1)	//landscape or reverse landscape       //~v98iI~
    	{                                                          //~v98iI~
    		strcpy(landscapeform,Pform);                           //~v98iI~
       		strcat(landscapeform,"L");                             //~v98iI~
			pform=landscapeform;                                   //~v98iI~
        }                                                          //~v98iI~
    }                                                              //~v98iI~
    Sdialogpapersize=strdup(pform);                                //~v987R~
    Sotherform=rc;                                                 //~v987R~
    UTRACEP("escformchkGtk rc=%d,newform=%s,displayname=%s\n",rc,pform,Pdisplayname);//~v987R~//~v98iR~
    return rc;                                                     //~v987R~
}//escformchkGtk                                                   //~v987R~
#endif	//GTKPRINT                                                            //~v980I~//~v987R~//~v98iR~
//**********************************************************************//~v74lI~
//* ESC form parm chk                                           //~v74lI~
//**********************************************************************//~v74lI~
void escdefaultmax(int Pprntyp)                                 //~v74lR~
{                                                               //~v74lI~
	int maxcol_index=0,nonumsw;                                   //~v74lR~//~v965R~
#if defined(W32)||defined(GXP)                                     //~v92fR~
	int cperr=0,lperr=0;                                           //~v92fI~
#endif                                                             //~v92fI~
//********************                                          //~v74lI~
#ifdef GTKPRINT                                                    //~v977I~
    UTRACEP("escdefaultmax Sotherform=%d\n",Sotherform);           //~v977I~
#endif                                                             //~v977I~
//max column by form and pitch                                  //~v74lI~
 	switch (Pprntyp)			//v5.5a                         //~v74lR~
	{                                                           //~v74lI~
	case PRINTER_ESCP:                  //ESC/P av4.5 v5.5r        //~v783R~
	 	switch(cpitch)                                          //~v74lI~
	  	{	                                                    //~v74lI~
	  	case 0:						//no parm                   //~v74lI~
			maxcol_index=PITCH_75CPI;                           //~v74lI~
			break;                                              //~v74lI~
	  	case 5:						//5cpi                      //~v74lI~
			maxcol_index=PITCH_5CPI;                            //~v74lI~
			break;                                              //~v74lI~
	  	case 6:						//6cpi                      //~v74lI~
			maxcol_index=PITCH_6CPI;                            //~v74lI~
			break;                                              //~v74lI~
	  	case 75:					//7.5cpi                    //~v74lI~
			maxcol_index=PITCH_75CPI;                           //~v74lI~
			break;                                              //~v74lI~
	  	default:					//parm err                  //~v74lI~
			if (dbcsenv)	//DBCS mode                         //~v74lI~
    	  		printf("%s:%s:文字ピッチが無効(ESC/Pプリンタ－)。\n",//~v74lI~
		  				pgmid,ver);                             //~v74lI~
			else			//SBCS mode                         //~v74lI~
    	  		printf("%s:%s:Invalid Char pitch value(ESC/P printer).\n",//~v74lI~
		  				pgmid,ver);                             //~v74lI~
                                                                //~v74lI~
			uexit(4);                                           //~v74lI~
			break;                                              //~v74lI~
		}                                                       //~v74lI~
		break;                                                  //~v74lI~
	case PRINTER_IBM:	//v5.5r                                    //~v783R~
	 	switch(cpitch)                                          //~v74lI~
	  	{	                                                    //~v74lI~
	  	case 0:						//no parm                   //~v74lI~
			maxcol_index=PITCH_75CPI;                           //~v74lI~
			break;                                              //~v74lI~
	  	case 5:						//5cpi                      //~v74lI~
			maxcol_index=PITCH_5CPI;                            //~v74lI~
			break;                                              //~v74lI~
	  	case 6:						//6cpi                      //~v74lI~
			maxcol_index=PITCH_6CPI;                            //~v74lI~
			break;                                              //~v74lI~
	  	case 67:					//6.7cpi                    //~v74lI~
			maxcol_index=PITCH_67CPI;                           //~v74lI~
			break;                                              //~v74lI~
//    	case 72:					//6.7cpi                       //~v854R~
//  		maxcol_index=PITCH_72CPI;                              //~v854R~
//  		break;                                                 //~v854R~
	  	case 75:					//7.5cpi                    //~v74lI~
			maxcol_index=PITCH_75CPI;                           //~v74lI~
			break;                                              //~v74lI~
	  	default:					//parm err                  //~v74lI~
			if (dbcsenv)	//DBCS mode                         //~v74lI~
    	  		printf("%s:%s:文字ピッチが無効(IBMプリンタ－)。\n",//~v74lR~
		  				pgmid,ver);                             //~v74lI~
			else			//SBCS mode                         //~v74lI~
    	  		printf("%s:%s:Invalid Char pitch value(IBM printer).\n",//~v74lR~
		  				pgmid,ver);                             //~v74lI~
                                                                //~v74lI~
			uexit(4);                                           //~v74lI~
			break;                                              //~v74lI~
		}                                                       //~v74lI~
		break;                                                  //~v74lI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
	case PRINTER_WIN:                                              //~v844I~
        if (cpitch)                                                //~v904I~
            if (UCBITCHK(swsw3,SW3WIN2P))                          //~v904I~
            {                                                      //~v904I~
                if (dbcsenv)    //DBCS mode                        //~v904I~
                    printf("2頁/1枚 印刷で 文字ピッチは指定できません。\n");//~v904I~
                else            //SBCS mode                        //~v904I~
                    printf("Char-pictch is invalid when double page print.\n");//~v904R~
                uexit(4);                                          //~v904I~
            }                                                      //~v904I~
	 	switch(cpitch)                                             //~v844I~
	  	{                                                          //~v844I~
	  	case 0:						//no parm                      //~v844I~
			maxcol_index=PITCH_75CPI;                              //~v844I~
			break;                                                 //~v844I~
	  	case 5:						//5cpi                         //~v844I~
			maxcol_index=PITCH_5CPI;                               //~v844I~
			break;                                                 //~v844I~
	  	case 6:						//6cpi                         //~v844I~
			maxcol_index=PITCH_6CPI;                               //~v844I~
			break;                                                 //~v844I~
	  	case 67:					//6.7cpi                       //~v844I~
			maxcol_index=PITCH_67CPI;                              //~v844I~
			break;                                                 //~v844I~
      	case 72:					//7.2cpi                       //~v844I~
    		maxcol_index=PITCH_72CPI;                              //~v844I~
    		break;                                                 //~v844I~
	  	case 75:					//7.5cpi                       //~v844I~
			maxcol_index=PITCH_75CPI;                              //~v844I~
			break;                                                 //~v844I~
	  	case 9:					//9.0cpi                           //~v872R~
			maxcol_index=PITCH_75CPI;                              //~v872I~
			break;                                                 //~v872I~
	  	default:					//parm err                     //~v844I~
//            if (dbcsenv)    //DBCS mode                          //~v873R~
//                printf("%s:%s:文字ピッチが無効(/Windowsプリンタ－)。\n",//~v873R~
//                        pgmid,ver);                              //~v873R~
//            else            //SBCS mode                          //~v873R~
//                printf("%s:%s:Invalid Char pitch value(/Windows).\n",//~v873R~
//                        pgmid,ver);                              //~v873R~
//                                                                 //~v873R~
//            uexit(4);                                            //~v873R~
			maxcol_index=PITCH_75CPI;                              //~v873I~
            cperr=1;                                               //~v92fI~
			break;                                                 //~v844I~
		}                                                          //~v844I~
		break;                                                     //~v844I~
#endif                                                             //~v844I~
	case PRINTER_CANNON:                                           //~v787I~
	 	switch(cpitch)                                             //~v787I~
	  	{                                                          //~v787I~
	  	case 0:						//no parm                      //~v787I~
//  		maxcol_index=PITCH_72CPI;                              //~v864R~
			maxcol_index=PITCH_75CPI;                              //~v864I~
			break;                                                 //~v787I~
	  	case 5:						//5cpi                         //~v787I~
			maxcol_index=PITCH_5CPI;                               //~v787I~
			break;                                                 //~v787I~
	  	case 6:						//6cpi                         //~v787I~
			maxcol_index=PITCH_6CPI;                               //~v787I~
			break;                                                 //~v787I~
	  	case 67:					//6.7cpi                       //~v787I~
			maxcol_index=PITCH_67CPI;                              //~v787I~
			break;                                                 //~v787I~
	  	case 72:					//7.2cpi                       //~v787I~
			maxcol_index=PITCH_72CPI;                              //~v787I~
			break;                                                 //~v787I~
	  	case 75:					//7.5cpi                       //~v787I~
			maxcol_index=PITCH_75CPI;                              //~v787I~
			break;                                                 //~v787I~
	  	default:					//parm err                     //~v787I~
			if (dbcsenv)	//DBCS mode                            //~v787I~
    	  		printf("%s:%s:文字ピッチが無効(/キャノンプリンタ－)。\n",//~v787I~
		  				pgmid,ver);                                //~v787I~
			else			//SBCS mode                            //~v787I~
    	  		printf("%s:%s:Invalid Char pitch value(Canon printer).\n",//~v864R~
		  				pgmid,ver);                                //~v787I~
			uexit(4);                                              //~v787I~
			break;                                                 //~v787I~
		}                                                          //~v787I~
		break;                                                     //~v787I~
	case '@':	//v5.5r                                         //~v74lI~
		maxcol_index=PITCH_75CPI;                               //~v74lI~
	}//by printer type	//v5.5a                                 //~v74lI~
//*process line pitch parm start v7.24a                         //~v74lI~
	switch(lpitch)                                              //~v74lI~
	{	                                                        //~v74lI~
	case 0:						//no parm                       //~v74lI~
	case 2:						//2cpi                          //~v74lI~
	case 3:						//3cpi                          //~v74lI~
	case 4:						//4cpi                          //~v74lI~
	case 5:						//5cpi                          //~v74lI~
	case 6:						//6cpi                          //~v74lI~
	case 75:					//7.5 cpi                       //~v74lI~
	case 8:						//8cpi                          //~v74lI~
#if defined(W32)||defined(GXP)                                     //~v92jI~
	  if (lpitch)	//parm specified                               //~v92jI~
        lperr=1;               //calc maxline using lpitch         //~v92jI~
#endif                                                             //~v92jI~
        break;                                                  //~v74lI~
	default:					//parm err                      //~v74lI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
 	  if (Pprntyp!=PRINTER_WIN)                                    //~v877I~
      {                                                            //~v877I~
#endif                                                             //~v877I~
		if (dbcsenv)	//DBCS mode                             //~v74lI~
      		printf("%s:%s:改行ピッチが無効。\n",                //~v74lR~
	 				pgmid,ver);                                 //~v74lI~
		else			//SBCS mode                             //~v74lI~
      		printf("%s:%s:Invalid Line pitch value.\n",         //~v74lR~
	  				pgmid,ver);                                 //~v74lI~
                                                                //~v74lI~
		uexit(4);                                               //~v74lI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
      }                                                            //~v877I~
      else                                                         //~v92fI~
        lperr=1;                                                   //~v92fI~
#endif                                                             //~v877I~
		break;                                                  //~v74lI~
	}//sw by lpitch                                             //~v74lI~
    nonumsw=(lineprefixsw==0);                                  //~v74lI~
    colmax1=Spitchtbl[Sformid].formmaxcol[nonumsw][0];          //~v74lR~
    colmax2=Spitchtbl[Sformid].formmaxcol[nonumsw][1];          //~v74lR~
    colmax3=Spitchtbl[Sformid].formmaxcol[nonumsw][2];          //~v74lR~
    colmax4=Spitchtbl[Sformid].formmaxcol[nonumsw][4];             //~v787I~
	if (!UCBITCHK(swsw2,SW2MAXCOLP))	//parm not specified    //~v74lR~
    {                                                              //~v92fI~
#if defined(W32)||defined(GXP)                                     //~v92fI~
      if (cperr)                                                   //~v92fI~
    #ifdef GXP                                                     //~v92fI~
		Scolbypitch=maxcol=lnx_getmaxcol(Spitchtbl[Sformid].formtype,nonumsw,cpitch);//~v92fI~
    #else                                                          //~v92fI~
		Scolbypitch=maxcol=win_getmaxcol(Spitchtbl[Sformid].formtype,nonumsw,cpitch);//~v92fI~
    #endif                                                         //~v92fI~
      else                                                         //~v92fI~
  #ifdef GTKPRINT                                                  //~v973I~
      if (Sotherform)   //pagesize gotten by cups printer          //~v973I~
		Scolbypitch=maxcol=lnx_getmaxcol(Spitchtbl[Sformid].formtype,nonumsw,(cpitch?cpitch:CUSTOM_CPI));//~v973R~
      else                                                         //~v973I~
  #endif                                                           //~v973I~
#endif                                                             //~v92fI~
		maxcol=Spitchtbl[Sformid].formmaxcol[nonumsw][maxcol_index];//~v74lR~
    }                                                              //~v92fI~
	if (!linespec)	//parm not specified                        //~v74lR~
    {                                                              //~v92fI~
#if defined(W32)||defined(GXP)                                     //~v92fI~
      if (lperr)                                                   //~v92fI~
    #ifdef GXP                                                     //~v92fI~
		Srowbypitch=maxline=lnx_getmaxline(Spitchtbl[Sformid].formtype,lpitch);//~v92fR~
    #else                                                          //~v92fI~
		Srowbypitch=maxline=win_getmaxline(Spitchtbl[Sformid].formtype,lpitch);//~v92fI~
    #endif                                                         //~v92fI~
      else                                                         //~v92fI~
  #ifdef GTKPRINT                                                  //~v973I~
      if (Sotherform)   //pagesize gotten by cups printer          //~v973I~
		Srowbypitch=maxline=lnx_getmaxline(Spitchtbl[Sformid].formtype,(lpitch?lpitch:CUSTOM_LPI));//~v973R~
      else                                                         //~v973I~
  #endif                                                           //~v973I~
#endif                                                             //~v92fI~
    	maxline=Spitchtbl[Sformid].formmaxline;                 //~v74lR~
    }                                                              //~v92fI~
//printf("c1=%d,c2=%d,c3=%d,c4=%d,maxc=%d,maxl=%d\n",              //~v844R~
//  	colmax1,colmax2,colmax3,colmax4,maxcol,maxline);           //~v844R~
    return;                                                     //~v74lI~
}//escdefaultmax                                                   //~v844R~
//**********************************************************************
//* ESC cmd setup		v5.1a
//* parm1:linewidth-LINENOSZ-1                                     //~v844I~
//* parm2:printer type                                             //~v844I~
//* parm3:output cmd area                                          //~v844I~
//**********************************************************************
void esccmdsetup(int pmaxcol,int prntyp,char *cmdfile) //v5.5r v7.12r
{
void getescdata(char *,int,char*,int *);
	int cmaxcol;			//v7.12a
	int lpitchw=0;				//v7.24a                           //~v965R~
    int vmi=0,hmi;			//asciifontset virtical,horizontal movement//~v864R~//~v965R~
    int chsz;                                                      //~v864I~
//    char *chsnm;                                                 //~v879R~
//********************
	if (!escsw)			//v5.3a
	{					//v5.3a
		esccmdlen=0;	//v5.3a	
		return;			//v5.3a
	}					//v5.3a
	cmaxcol=pmaxcol;		//v7.12a
 	switch (prntyp)			//v5.5a
	{
//************************
//*ESC/P printer         *
//************************
	case PRINTER_ESCP:                  //ESC/P av4.5 v5.5r        //~v783R~
//  	if (!lineprefixsw)		//v7.12a                        //~v74lR~
//  		cmaxcol-=5;		//v7.12a                            //~v74lR~
//*process pitch parm start v7.24a
	 	switch(cpitch)
	  	{	
	  	case 0:						//no parm
			break;
	  	case 5:						//5cpi
			cmaxcol=colmax1;		//temporary,to set 5cpi next
			break;
	  	case 6:						//6cpi
			cmaxcol=colmax2;		//temporary,to set 6cpi next
			break;
	  	case 75:					//7.5cpi
			cmaxcol=colmax2+1;		//temporary,to set 7.5cpi next
			break;
		}
//*process pitch parm end  v7.24a

  		if (cmaxcol<=colmax1)                      //av4.5 v5.1rv7.12r//~5A28R~
    		memcpy(esccmd,"\x1b\x50\x1c\x53\x00\x0c",6);//cpi=5 and DBCS space av4.5
  		else 								//av4.5
  		if (cmaxcol<=colmax2)                      //av4.5 v5.1rv7.12r//~5A28R~
    		memcpy(esccmd,"\x1b\x4d\x1c\x53\x00\x06",6);//cpi=6 and DBCS space av4.5
		else 								//av4.5
			memcpy(esccmd,"\x1b\x67\x1c\x53\x00\x00",6);//cpi=7.5 and DBCS space av4.5
		esccmdlen=6;                           //av4.5
//*process line pitch parm start v7.24a
	 	switch(lpitch)
	  	{	
	  	case 0:						//no parm
			lpitchw=ESCPLPIBASE/DEFAULTLPI;     	//by unit 1/180 cpi//~v788R~
			break;
	  	case 2:						//2cpi
	  	case 3:						//3cpi
	  	case 4:						//4cpi
	  	case 5:						//5cpi
	  	case 6:						//6cpi
	  	case 8:						//8cpi
			lpitchw=ESCPLPIBASE/lpitch;     	//by unit 1/180 cpi//~v788R~
			break;
	  	case 75:					//7.5 cpi
			lpitchw=ESCPLPIBASE*10/lpitch;     //by unit 1/180 cpi //~v788R~
			break;
		}
//  	if (lpitch)                                             //~v752R~
//  	{                                                       //~v752R~
//  		memcpy(esccmd+esccmdlen,"\x1b\x2b\x00",3);//lpi format by 1/360//~v786R~
    		memcpy(esccmd+esccmdlen,"\x1b\x33\x00",3);//lpi format by 1/180//~v786I~
			esccmdlen+=3;			//line pitch cmd
			esccmd[esccmdlen-1]=(UCHAR)lpitchw;
//  	}                                                       //~v752R~
//*process line pitch parm end  v7.24a
//*process font style parm startv7.24a
		if (fontstyle)
		{
			memcpy(esccmd+esccmdlen,"\x1b\x6b\x00",3);//font style
			esccmdlen+=3;			//line pitch cmd
			esccmd[esccmdlen-1]=(UCHAR)fontid;
		}
//*process font style parm end  v7.24a
//*process DBCS font style parm startvv7.28a
		if (fontid2)
		{
			memcpy(esccmd+esccmdlen,"\x1c\x6b\x00",3);//font style
			esccmdlen+=3;			//line pitch cmd
			esccmd[esccmdlen-1]=(UCHAR)(fontid2-1);
		}
        if (asciimode!=1)                                          //~v848R~
          if (Gebcdictype==2)		//ebcidic english              //~v891R~
            memcpy(esccmd+esccmdlen,"\x1b\x74\x01",3); //ext graphic//~v891I~
          else                                                     //~v891I~
            memcpy(esccmd+esccmdlen,"\x1b\x74\x03",3); //katakana  //~v848R~
        else                                                       //~v848I~
            memcpy(esccmd+esccmdlen,"\x1b\x74\x01",3); //ext graphic//~v848R~
        esccmdlen+=3;                                              //~v848I~
//*process DBCS font style parm end  v7.28a
		break;	//v5.5r
//************************
//*ibm printer           *
//************************
	case PRINTER_IBM:	//v5.5r                                    //~v783R~
//  	if (!lineprefixsw)		//v7.12a                        //~v74lR~
//  		cmaxcol-=5;		//v7.12a                            //~v74lR~
//*process char pitch parm start v7.24a
	 	switch(cpitch)
	  	{	
	  	case 0:						//no parm
			break;
	  	case 5:						//5cpi
			cmaxcol=colmax1;		//temporary,to set 5cpi next
			break;
	  	case 6:						//6cpi
			cmaxcol=colmax2;		//temporary,to set 6cpi next
			break;
	  	case 67:					//6.7cpi
			cmaxcol=colmax3;		//temporary,to set 6.7cpi next
			break;
	  	case 72:					//7.2cpi                       //~v788I~
			cmaxcol=colmax4;		//temporary,to set 7.2cpi next //~v788I~
			break;                                                 //~v788I~
	  	case 75:					//7.5cpi
//  		cmaxcol=colmax3+1;		//temporary,to set 7.5cpi next //~v845R~
    		cmaxcol=colmax4+1;		//temporary,to set 7.5cpi next //~v845I~
			break;
		}
//*process char pitch parm end  v7.24a

  		if (cmaxcol<=colmax1)                      //v2.3 v5.1rv7.12r//~5A28R~
    		memcpy(esccmd,"\x1b\x7e\x02\x00\x01\x32",6);//cpi=5 v2.3 v2.9add
  		else 
  		if (cmaxcol<=colmax2)                      //v2.3 v5.1rv7.12r//~5A28R~
    		memcpy(esccmd,"\x1b\x7e\x02\x00\x01\x3c",6);//cpi=6 v2.3 v2.9add
		else 
		if (cmaxcol<=colmax3)                      //v2.3 v5.1rv7.12r//~5A28R~
			memcpy(esccmd,"\x1b\x7e\x02\x00\x01\x43",6);//cpi=6.7 v2.3 v2.9add
		else 
//  	if (cmaxcol<=colmax4)                      //v2.3 v5.1rv7.12r//~v854R~
//  		memcpy(esccmd,"\x1b\x7e\x02\x00\x01\x48",6);//cpi=7.2  //~v854R~
//  	else                                                       //~v854R~
			memcpy(esccmd,"\x1b\x7e\x02\x00\x01\x4b",6);//cpi=7.5 v2.3 v2.9add
		esccmdlen=6;                           //v2.9add
//*process line pitch parm start v7.24a
	 	switch(lpitch)
	  	{	
	  	case 0:						//no parm
			lpitchw=DEFAULTLPI*10;     		//by unit 1/10 cpi  //~v752I~
			break;                                              //~v752I~
	  	case 2:						//2cpi
	  	case 3:						//3cpi
	  	case 4:						//4cpi
	  	case 5:						//5cpi
	  	case 6:						//6cpi
	  	case 8:						//8cpi
			lpitchw=lpitch*10;     		//by unit 1/10 cpi
			break;
	  	case 75:					//7.5 cpi
			lpitchw=lpitch;     		//by unit 1/10 cpi
			break;
		}
//		if (lpitch)                                             //~v752R~
//		{                                                       //~v752R~
			memcpy(esccmd+esccmdlen,"\x1b\x7e\x03\x00\x01\x00",6);//lpi format
			esccmdlen+=6;			//line pitch cmd
			esccmd[esccmdlen-1]=(UCHAR)lpitchw;
//		}                                                       //~v752R~
//*process line pitch parm end  v7.24a
//*process font style parm start  v7.24a
		if (fontstyle)
		{
			memcpy(esccmd+esccmdlen,"\x1b\x7e\x06\x00\x01\x00",6);//font style
			esccmdlen+=6;			//line pitch cmd
			esccmd[esccmdlen-1]=(UCHAR)fontid;
		}
//*process font style parm end  v7.24a
		break;			//v5.5r
//************************                                         //~v783I~
//*Cannon printer        *                                         //~v783I~
//************************                                         //~v783I~
	case PRINTER_CANNON:                                           //~v783R~
//common cmd                                                       //~v783I~
    	esccmdlen=0;                                               //~v783I~
//*                                                                //~v864I~
//*process char pitch parm start                                   //~v783I~
//printf("cmaxcol=%d,cmaxcol3=%d,cmaxcol4=%d\n",cmaxcol,colmax3,colmax4);//~v864R~
	 	switch(cpitch)                                             //~v783I~
	  	{	                                                       //~v783I~
	  	case 0:						//no parm                      //~v783I~
//  		cmaxcol=colmax4;		//temporary,to set 72cpi next  //~v864R~
			break;                                                 //~v783I~
	  	case 5:						//5cpi                         //~v783I~
			cmaxcol=colmax1;		//temporary,to set 5cpi next   //~v783I~
			break;                                                 //~v783I~
	  	case 6:						//6cpi                         //~v783I~
			cmaxcol=colmax2;		//temporary,to set 6cpi next   //~v783I~
			break;                                                 //~v783I~
	  	case 67:					//6.7cpi                       //~v783I~
			cmaxcol=colmax3;		//temporary,to set 6.7cpi next //~v783I~
			break;                                                 //~v783I~
	  	case 72:					//7.2cpi                       //~v787I~
			cmaxcol=colmax4;		//temporary,to set 7.2cpi next //~v787I~
			break;                                                 //~v787I~
	  	case 75:					//7.5cpi                       //~v783I~
//  		cmaxcol=colmax3+1;		//temporary,to set 7.5cpi next //~v845R~
    		cmaxcol=colmax4+1;		//temporary,to set 7.5cpi next //~v845I~
			break;                                                 //~v783I~
		}                                                          //~v783I~
//*process char pitch parm end                                     //~v783I~
                                                                   //~v783I~
  		if (cmaxcol<=colmax1)                                      //~v783I~
    		hmi=72;			//720 / 10CPI                          //~v783I~
  		else                                                       //~v783I~
  		if (cmaxcol<=colmax2)                                      //~v783I~
    		hmi=60;			//720 / 12CPI                          //~v783I~
		else                                                       //~v783I~
    	if (cmaxcol<=colmax3)                                      //~v864I~
    		hmi=54;			//720 / 13+1/3 CPI                     //~v864I~
		else                                                       //~v864M~
		if (cmaxcol<=colmax4)                                      //~v787I~
    		hmi=50;			//720 / 14.4CPI                        //~v787I~
//  	if (cmaxcol<=colmax3)                                      //~v864R~
//  		hmi=54;			//720 / 13+1/3 CPI                     //~v864R~
		else                                                       //~v783I~
    		hmi=48;			//720 / 15 CPI                         //~v783I~
//*process line pitch parm start                                   //~v783I~
	 	switch(lpitch)                                             //~v783I~
	  	{	                                                       //~v783I~
	  	case 0:						//no parm                      //~v783I~
			vmi=720/DEFAULTLPI;     //by unit 1/720 inch           //~v783I~
			break;                                                 //~v783I~
	  	case 2:						//2cpi                         //~v783I~
	  	case 3:						//3cpi                         //~v783I~
	  	case 4:						//4cpi                         //~v783I~
	  	case 5:						//5cpi                         //~v783I~
	  	case 6:						//6cpi                         //~v783I~
	  	case 8:						//8cpi                         //~v783I~
			vmi=720/lpitch;     	//by unit 1/720 inch           //~v783I~
			break;                                                 //~v783I~
	  	case 75:					//7.5 cpi                      //~v783I~
			vmi=7200/lpitch;     	//by unit 1/720 inch           //~v783I~
			break;                                                 //~v783I~
		}                                                          //~v783I~
        chsz=(hmi<<1);                                             //~v864I~
	    if (chsz>=vmi)                                             //~v864R~
    		chsz=(vmi*9)/10;       //90percent                     //~v864R~
       if (asciimode==1         //ascii mode                       //~v864I~
       ||  Gebcdictype==2	//ebcidic english                      //~v891R~
       ||  fontsetreq)         //char set set req                  //~v864I~
           canonfontset(vmi,hmi);                                  //~v864R~
       else                                                        //~v864I~
       {                                                           //~v864I~
		topcmdlen=0;                                               //~v881I~
    	topcmdlen+=sprintf(topcmd          ,"%c%%@",CMD_ESC); //emulation mode to text mode//~v881I~
	    topcmdlen+=sprintf(topcmd+topcmdlen,"%c<",CMD_ESC);  //soft rest//~v881I~
                                                                   //~v881I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%s","\x1b%@");	//emulation mode to text mode//~v864I~
//	    esccmdlen+=sprintf(esccmd+esccmdlen,"%c<",CMD_ESC);  //soft rest//~v881R~
    	esccmdlen+=sprintf(esccmd+esccmdlen,"%s","\x1b%0");	//shift JIS//~v864I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%s","\x1b[2 I");//size unit,2:1/720inch//~v864M~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%c[?23h",CMD_ESC);//prohibit HMI auto change//~v864I~
//DBCS                                                             //~v864I~
    	esccmdlen+=sprintf(esccmd+esccmdlen,"%cn",CMD_ESC); //LS2(G2-->GL)//~v864I~
//  	esccmdlen+=sprintf(esccmd+esccmdlen,"%cPz%s%s"%c\\",       //~v864I~
//              CMD_ESC,                                           //~v864I~
//              "Mincho-Medium.J83,                                //~v864I~
//              CMD_ESC);                                          //~v864I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"\x1b[%d;%d G",vmi,(hmi<<1));//spacing for dbcs//~v864R~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d C",CMD_ESC,chsz);//char size//~v864R~
		if (fontstyle)                                             //~v864I~
			esccmdlen+=sprintf(esccmd+esccmdlen,"\x1b[%d;y",fontid);//spacing//~v864I~
//        if (fontstyle && fontid==0)     //LIN                    //~v879R~
//        {                                                        //~v879R~
//            chsnm="LinePrinter-Bold";                            //~v879R~
////Right                                                          //~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%c",CMD_SO);//shift out(G1-->GL)//~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%cPz%s.%s%c\\", //~v879R~
//                CMD_ESC,                                         //~v879R~
//                chsnm,"KATA",                                    //~v879R~
//                CMD_ESC);                                        //~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"\x1b[%d;y",fontid);//spacing//~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d;%d G",CMD_ESC,vmi,hmi);//spacing//~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d C",CMD_ESC,chsz);//char size//~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%c~",CMD_ESC);  //LS1R(G1-->GR)//~v879R~
//        }//LIN                                                   //~v879R~
//back to g0                                                       //~v864I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%c",CMD_SI);//G0-->GL //~v864I~
//        if (fontstyle && fontid==0)     //LIN                    //~v879R~
//        {                                                        //~v879R~
//            esccmdlen+=sprintf(esccmd+esccmdlen,"%cPz%s.%s%c\\", //~v879R~
//                CMD_ESC,                                         //~v879R~
//                chsnm,"ROMA",                                    //~v879R~
//                CMD_ESC);                                        //~v879R~
//        }   //LIN                                                //~v879R~
		esccmdlen+=sprintf(esccmd+esccmdlen,"\x1b[%d;%d G",vmi,hmi);//spacing//~v864I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d C",CMD_ESC,chsz);//char size//~v864R~
                                                                   //~v864I~
//*process line pitch parm end  v7.24a                             //~v783I~
//*process font style parm start  v7.24a                           //~v783I~
		if (fontstyle)                                             //~v783I~
			esccmdlen+=sprintf(esccmd+esccmdlen,"\x1b[%d;y",fontid);//spacing//~v783R~
       }                                                           //~v864I~
//*process font style parm end  v7.24a                             //~v783I~
		break;			//v5.5r                                    //~v783I~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
//************************                                         //~v844I~
//*Windows printer       *                                         //~v844I~
//************************                                         //~v844I~
	case PRINTER_WIN:                                              //~v844I~
//common cmd                                                       //~v844I~
    	esccmdlen=0;                                               //~v844I~
//*process char pitch parm start                                   //~v844I~
//printf("pmaxcol=%d\n",pmaxcol);                                  //~v844R~
	 	switch(cpitch)                                             //~v844I~
	  	{                                                          //~v844I~
	  	case 0:						//no parm                      //~v844I~
//          if (!Sformspecsw)	//no form parm                     //~v90yR~
//          	if (colomnspec)	//column/recordsize(record dump mode)specified or hexdump mode//~v880R~
	            	cmaxcol=-cmaxcol;	//calc at win_opendoc      //~v874I~
			break;                                                 //~v844I~
	  	case 5:						//5cpi                         //~v844I~
			cmaxcol=colmax1;		//temporary,to set 5cpi next   //~v844I~
			break;                                                 //~v844I~
	  	case 6:						//6cpi                         //~v844I~
			cmaxcol=colmax2;		//temporary,to set 6cpi next   //~v844I~
			break;                                                 //~v844I~
	  	case 67:					//6.7cpi                       //~v844I~
			cmaxcol=colmax3;		//temporary,to set 6.7cpi next //~v844I~
			break;                                                 //~v844I~
	  	case 72:					//7.2cpi                       //~v844I~
			cmaxcol=colmax4;		//temporary,to set 7.2cpi next //~v844I~
			break;                                                 //~v844I~
	  	case 75:					//7.5cpi                       //~v844I~
			cmaxcol=colmax4+1;		//temporary,to set 7.5cpi next //~v844R~
			break;                                                 //~v844I~
//        case 9:                 //9.5cpi                         //~v876R~
//            cmaxcol=colmax5+1;      //                           //~v876R~
//            break;                                               //~v876R~
        default:                                                   //~v873I~
		  if (Scolbypitch)                                         //~v92fI~
            cmaxcol=-Scolbypitch;                                  //~v92fI~
          else                                                     //~v92fI~
            cmaxcol=999;        //id of not predefined             //~v873I~
		}                                                          //~v844I~
//*process char pitch parm end                                     //~v844I~
    if (cmaxcol<0)	//calc cpi by maxcol	                       //~v874I~
    	hmi=cmaxcol;			//minus parm to win_opendoc        //~v874I~
    else                                                           //~v874I~
    if (cmaxcol==999)                                              //~v873R~
        if (cpitch>=15)                                            //~v873R~
	        hmi=7200/(cpitch*2);                                   //~v873I~
        else                                                       //~v873I~
	        hmi=720/(cpitch*2);                                    //~v873R~
    else                                                           //~v873I~
        if (cmaxcol<=colmax1)                                      //~v844R~
            hmi=72;         //720 / 10CPI                          //~v844R~
        else                                                       //~v844R~
        if (cmaxcol<=colmax2)                                      //~v844R~
            hmi=60;         //720 / 12CPI                          //~v844R~
        else                                                       //~v844R~
        if (cmaxcol<=colmax3)                                      //~v844R~
            hmi=54;         //720 / 13+1/3 CPI                     //~v844R~
        else                                                       //~v844R~
        if (cmaxcol<=colmax4)                                      //~v844R~
            hmi=50;         //720 / 14.4CPI                        //~v844R~
        else                                                       //~v844R~
//        if (cmaxcol<=colmax5)                                    //~v876R~
            hmi=48;         //720 / 15 CPI                         //~v844R~
//        else                                                     //~v876R~
//            hmi=40;         //720 / 19  CPI                      //~v876R~
//*process line pitch parm start                                   //~v844I~
        switch(lpitch)                                             //~v844R~
        {                                                          //~v844R~
        case 0:                     //no parm                      //~v844R~
//        if (!Sformspecsw	//no form parm                         //~v90yR~
//        )                                                        //~v90yR~
//        &&   linespec)	//column/recordsize(record dump mode)specified or hexdump mode//~v883R~
	        vmi=-maxline;	//calc at win_opendoc                  //~v875I~
//        else                                                     //~v90yR~
//          vmi=720/DEFAULTLPI;     //by unit 1/720 inch           //~v90yR~
            break;                                                 //~v844R~
        case 2:                     //2cpi                         //~v844R~
        case 3:                     //3cpi                         //~v844R~
        case 4:                     //4cpi                         //~v844R~
        case 5:                     //5cpi                         //~v844R~
        case 6:                     //6cpi                         //~v844R~
        case 8:                     //8cpi                         //~v844R~
		  if (Srowbypitch)                                         //~v92jI~
            vmi=-Srowbypitch;                                      //~v92jI~
          else                                                     //~v92jI~
            vmi=720/lpitch;         //by unit 1/720 inch           //~v844R~
            break;                                                 //~v844R~
        case 75:                    //7.5 cpi                      //~v844R~
		  if (Srowbypitch)                                         //~v92jI~
            vmi=-Srowbypitch;                                      //~v92jI~
          else                                                     //~v92jI~
            vmi=7200/lpitch;        //by unit 1/720 inch           //~v844R~
            break;                                                 //~v844R~
        default:                                                   //~v877I~
		  if (Srowbypitch)                                         //~v92fI~
            vmi=-Srowbypitch;                                      //~v92fR~
          else                                                     //~v92fI~
	        if (lpitch>=15)                                        //~v877I~
		        vmi=7200/lpitch;                                   //~v877I~
            else                                                   //~v877I~
            	vmi=720/lpitch;         //by unit 1/720 inch       //~v877R~
        }//lpi                                                     //~v844R~
        if (phase2sw)                                              //~v844M~
#ifdef W32                                                         //~v92dI~
			win_opendoc(hmi,vmi,docname);	//char width,hight by unit 1/720//~v844R~
#else                                                              //~v92dI~
			lnx_opendoc(hmi,vmi,docname);	//char width,hight by unit 1/720//~v92dI~
#endif                                                             //~v92dI~
		break;			//v5.5r                                    //~v844I~
#endif                                                             //~v844I~
    case '@':					//v5.5a command file spec
		getescdata(cmdfile,cmaxcol,esccmd,&esccmdlen);	//cmd file data v5.5av7.12r
        break;                                              //v3.8a
	}	//v5.5a
	return;
}//esccmdsetup
//***********************************************************      //~v864I~
//* canon font set cmd setup                                       //~v864I~
//***********************************************************      //~v864I~
void canonfontset(int Pvmi,int Phmi)                               //~v864R~
{                                                                  //~v864I~
//  char *chsnm,*chsl="IBML",*chsr="IBMR1";                        //~v864R~//~v965R~
    char *chsnm="Symbol",*chsl="IBML",*chsr="IBMR1";               //~v965I~
    int chsz;                                                      //~v864I~
//***************                                                  //~v864I~
	chsz=Phmi*3/2;                                                 //~v864I~
                                                                   //~v864I~
    if (!fontsetreq)         //font not specified but ascii        //~v864I~
    	fontid=5;			//use DUT                              //~v864I~
    switch(fontid)                                                 //~v864I~
    {                                                              //~v864I~
    case 3:         //COU    not scalable                          //~v864I~
        if (Phmi>=72)        //10cpi                               //~v864R~
            chsnm="Ncourier10";                                    //~v864I~
        else                                                       //~v864I~
            chsnm="Ncourier17";                                    //~v864I~
        break;                                                     //~v864I~
    case 4:         //SWI                                          //~v864I~
        chsnm="Swiss";                                             //~v864I~
        break;                                                     //~v864I~
    case 5:         //DUT                                          //~v864I~
        chsnm="Dutch-Roman";                                       //~v864I~
        break;                                                     //~v864I~
    case 99:        //SYM                                          //~v864I~
        chsnm="Symbol";                                            //~v864I~
        chsl="SYML";                                               //~v864I~
        chsr="SYMR";                                               //~v864I~
        break;                                                     //~v864I~
    }//font style                                                  //~v864I~
//cmd write at top op file                                         //~v871I~
	topcmdlen=0;                                                   //~v871I~
    topcmdlen+=sprintf(topcmd          ,"%c%%@",CMD_ESC); //emulation mode to text mode//~v871R~
    topcmdlen+=sprintf(topcmd+topcmdlen,"%cP31;300;1J%c\\",CMD_ESC,CMD_ESC);//~v871R~
                                //job start,31=lips3;300dpi,1=jis  //~v871I~
    topcmdlen+=sprintf(topcmd+topcmdlen,"%c<",CMD_ESC);  //soft rest//~v871R~
	topcmdlen+=sprintf(topcmd+topcmdlen,"%c[0$p",CMD_ESC);//all pair rest//~v871R~
                                                                   //~v871I~
//*for each page                                                   //~v871R~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%c%%@",CMD_ESC); //emulation mode to text mode//~v864R~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[2 I",CMD_ESC);//size unit,2:1/720inch//~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[?23h",CMD_ESC);//prohibit HMI auto change//~v864I~
//Right                                                            //~v864I~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%c",CMD_SO);//shift out(G1-->GL)//~v864R~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%cPz%s.%s%c\\",           //~v864R~
                CMD_ESC,                                           //~v864R~
                chsnm,chsr,                                        //~v864R~
                CMD_ESC);                                          //~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[?8h",CMD_ESC);//no propotinal//~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d;%d G",CMD_ESC,Pvmi,Phmi);//spacing//~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d C",CMD_ESC,chsz);//char size//~v864R~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%c~",CMD_ESC);  //LS1R(G1-->GR)//~v864I~
//Left                                                             //~v864I~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%c",CMD_SI); //shift in(G0-->GL)//~v864R~
    esccmdlen+=sprintf(esccmd+esccmdlen,"%cPz%s.%s%c\\",           //~v864R~
                CMD_ESC,                                           //~v864R~
                chsnm,chsl,                                        //~v864R~
                CMD_ESC);                                          //~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[?8h",CMD_ESC);//no propotinal//~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d;%d G",CMD_ESC,Pvmi,Phmi);//spacing//~v864I~
	esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d C",CMD_ESC,chsz);//char size//~v864R~
                                                                   //~v864I~
	if (fontid!=99)                                                //~v864I~
		esccmdlen+=sprintf(esccmd+esccmdlen,"%c[%d;y",CMD_ESC,fontid);//spacing//~v864R~
                                                                   //~v864I~
	endjobreq=1;                 //canon endjob requied sw         //~v864R~
}//canonfontset                                                    //~v864I~
//***********************************************************
//* process esc cmd data file	v5.5a
//***********************************************************
//***********************************************************
//*parm1  : file name
//*parm2  : max column per line
//*parm3  : output esc cmd string buff
//*parm4  : output string length addr
//*return : none
//**********************************************/
//void getescdata(char *file,int colomn,char *esccmd,int *len)     //~v9e6R~
void getescdata(char *file,int colomn,char *Pesccmd,int *len)      //~v9e6I~
{
    char buff[MAXESCCMD];
	int fcol=0,fcolo=0;
	int recno=0;
//	int c;					//v7.0d
	char *pc;				//*pc0,*out; v7.0r
	FILE * hfile;
int gethexvalue(char *,char *);
//***********************
	if (!(hfile=fopen(file,"r")))      //open ascii input
	{
		if (dbcsenv)	//DBCS mode
			printf("\n%s:%s:ESC コマンドファイル(%s) オープンエラー\n",pgmid,ver,file);//~v74lR~
		else			//SBCS mode v4.9a	
			printf("\n%s:%s:ESC cmd data file(%s) open err\n",pgmid,ver,file);//~v74lR~
		uexit(4);                                               //~v742R~
	}

	while(fgets(buff,MAXESCCMD,hfile))	//null return if error or eof r940527
	{
		recno++;
		fcol=atoi(buff);
		if (fcol<=fcolo)	//seq down
		{
			if (dbcsenv)	//DBCS mode
				printf("\n%s:%s:ESC コマンドファイル(%s)の第 %d レコードで最大桁数順-順序エラー\n",//~v74lR~
				pgmid,ver,file,recno);
			else			//SBCS mode v4.9a	
				printf("\n%s:%s:ESC cmd data file(%s) record sequence err at record-no %d\n",//~v74lR~
				pgmid,ver,file,recno);
			uexit(4);                                           //~v742R~
		}
		fcolo=fcol;
		if (colomn<=fcol)
		{
			pc=buff+strspn(buff,"0123456789");	//skip max colomn field
			pc+=strspn(pc," ");					//skip to first hex char
			*len=gethexvalue(pc,Pesccmd);                          //~v9e6R~
			if (*len==-1)
			{
				if (dbcsenv)	//DBCS mode
					printf("\n%s:%s:ESC コマンドファイル(%s)の第 %d レコードが不当な HEX 文字を含んでいます\n",//~v74lR~
					pgmid,ver,file,recno);
				else			//SBCS mode v4.9a	
					printf("\n%s:%s:ESC cmd data file(%s) record-no %d has invalid hex digit\n",//~v74lR~
					pgmid,ver,file,recno);
				uexit(4);                                       //~v742R~
			}
			break;
		}//under the maxcolomn line
	}//until eof

	if (colomn>fcol)//no that data
	{
		if (dbcsenv)	//DBCS mode
			printf("\n%s:%s:ESC コマンドファイル(%s)に最大桁数 %d の為の レコードがありません\n",//~v74lR~
			pgmid,ver,file,colomn);
		else			//SBCS mode v4.9a	
			printf("\n%s:%s:ESC cmd data file(%s) ha no record for max-colomn %d",//~v74lR~
			pgmid,ver,file,colomn);
		uexit(4);                                               //~v742R~
	}	

	fclose(hfile);
}//getescdata
//*************************************
//* convert hex digit to integer data
//*  return data len,-1 if err
//*************************************
int gethexvalue(char *hex,char *bin)
{
	int i;
	char *in;
	char *out;
	int  c,co=0;			//v7.0r
//********************
	in=hex;
	out=bin;
	for (i=0;*in!=CRLF;in++,i++) 
	{
		c=toupper(*in);	
		if (!isxdigit(c))
			return -1;
		if (c>='A')
			c-='A'-10;
		else
			c-='0';
		if (i%2)
			*out++=(unsigned char)((co<<4)+c);
		else
			co=c;
	}
	if (i%2)
		return -1;
	return i/2;
}
//*************************************                            //~v783R~
//* font parameter chk                                             //~v783R~
//*  parm1 :printer type                                           //~v783R~
//*  parm2 :fontid parm string                                     //~v783R~
//*  return:none                                                   //~v783R~
//*************************************                            //~v783R~
//void escfontchk(int prntyp,char *fontstyle)                        //~v783R~//+v9e6R~
void escfontchk(int prntyp,char *Pfontstyle)                       //+v9e6I~
{                                                                  //~v783R~
	char *pc;                                                      //~v783R~
//********************                                             //~v783R~
//*process font style parm start  v7.24a
 	switch (prntyp)
	{
	case PRINTER_ESCP:                  //ESC/P                    //~v783R~
//kanji font style v7.28a start
		if (Pfontstyle)                                            //+v9e6R~
		{
//          pc=strpbrk(cptr,"/");		//search '/'               //~v782R~
            pc=strpbrk(Pfontstyle,"/");		//search '/'           //~v782R~//+v9e6R~
			if (pc)						//with kanji parm
			{
				pc++;
				if (!stricmp(pc,"MIN"))                         //~v742R~
		  			fontid2=1;
		  		if (!stricmp(pc,"GOT"))                         //~v742R~
		  			fontid2=2;
		  		if (!fontid2)
                {                                                  //~v91pI~
					if (dbcsenv)	//DBCS mode
        				optionerr("漢字フォントスタイル(ESC/P)",Pfontstyle-2);//errmsg and exit//+v9e6R~
					else			//SBCS mode
			        	optionerr("DBCS Font Style(ESC/P)",Pfontstyle-2);  //errmsg and exit//+v9e6R~
                }                                                  //~v91pI~
				*(--pc)=0;
				if (!strlen(Pfontstyle))                           //+v9e6R~
					Pfontstyle=NULL;                               //+v9e6R~
			}
		}
//kanji font style v7.28a end
		if (Pfontstyle)                                            //+v9e6R~
		{
			fontid=-1;
			if (!stricmp(Pfontstyle,"0"))                        //~v742R~//+v9e6R~
	  			fontid=0;
	  		if (!stricmp(Pfontstyle,"ROM"))                         //~v784I~//+v9e6R~
	  			fontid=0;                                          //~v784I~
	  		if (!stricmp(Pfontstyle,"SAN"))                      //~v742R~//+v9e6R~
	  			fontid=1;
	  		if (!stricmp(Pfontstyle,"COU"))                      //~v742R~//+v9e6R~
	  			fontid=2;
	  		if (!stricmp(Pfontstyle,"PRE"))                      //~v742R~//+v9e6R~
	  			fontid=3;
	  		if (!stricmp(Pfontstyle,"SCR"))                      //~v742R~//+v9e6R~
	  			fontid=4;
	  		if (!stricmp(Pfontstyle,"OCB"))                      //~v742R~//+v9e6R~
	  			fontid=5;
	  		if (!stricmp(Pfontstyle,"OCA"))                      //~v742R~//+v9e6R~
	  			fontid=6;
	  		if (fontid==-1)
            {                                                      //~v91pI~
				if (dbcsenv)	//DBCS mode
        			optionerr("フォントスタイル(ESC/P)",Pfontstyle-2);//errmsg and exit//+v9e6R~
				else			//SBCS mode
		        	optionerr("Font Style(ESC/P)",Pfontstyle-2);  //errmsg and exit//+v9e6R~
            }                                                      //~v91pI~
		}
		break;
	case PRINTER_IBM:                                              //~v783R~
		if (Pfontstyle)                                            //+v9e6R~
		{
			fontid=-1;
			if (!stricmp(Pfontstyle,"0"))                        //~v742R~//+v9e6R~
	  			fontid=0;
	  		if (!stricmp(Pfontstyle,"GOT"))                      //~v742R~//+v9e6R~
	  			fontid=1;
	  		if (!stricmp(Pfontstyle,"ELI"))                      //~v742R~//+v9e6R~
	  			fontid=6;
	  		if (!stricmp(Pfontstyle,"COU"))                      //~v742R~//+v9e6R~
	  			fontid=7;
	  		if (!stricmp(Pfontstyle,"MIN"))                      //~v742R~//+v9e6R~
	  			fontid=8;
	  		if (!stricmp(Pfontstyle,"OCB"))                      //~v742R~//+v9e6R~
	  			fontid=0x11;
	  		if (!stricmp(Pfontstyle,"ORE"))                      //~v742R~//+v9e6R~
	  			fontid=0x12;
	  		if (fontid==-1)
            {                                                      //~v91pI~
				if (dbcsenv)	//DBCS mode
        			optionerr("フォントスタイル(IBM)",Pfontstyle-2);//errmsg and exit//+v9e6R~
				else			//SBCS mode
		        	optionerr("Font Style(IBM)",Pfontstyle-2);  //errmsg and exit//+v9e6R~
            }                                                      //~v91pI~

		}//font style parm exist
		break;                                                     //~v783I~
	case PRINTER_CANNON:                    //[ESC][[primary];<secondary>y//~v783R~
		if (Pfontstyle)                                             //~v783I~//+v9e6R~
		{                                                          //~v783I~
			fontid=-1;                                             //~v783I~
	  		if (!stricmp(Pfontstyle,"LIN"))                         //~v783I~//+v9e6R~
	  			fontid=0;                    //[ESC][0;y           //~v783I~
	  		if (!stricmp(Pfontstyle,"COU"))                         //~v783I~//+v9e6R~
            {                                                      //~v864I~
                fontsetreq=2;                //set char set name by cpi//~v864R~
	  			fontid=3;                    //[ESC][3;y           //~v783I~
            }                                                      //~v864I~
	  		if (!stricmp(Pfontstyle,"SWI"))   //swiss               //~v783I~//+v9e6R~
            {                                                      //~v864I~
                fontsetreq=1;                                      //~v864I~
	  			fontid=4;                    //[ESC][4;y           //~v783I~
            }                                                      //~v864I~
	  		if (!stricmp(Pfontstyle,"DUT"))   //dutch801            //~v783I~//+v9e6R~
            {                                                      //~v864I~
                fontsetreq=1;                                      //~v864I~
	  			fontid=5;                    //[ESC][5;y           //~v783I~
            }                                                      //~v864I~
	  		if (!stricmp(Pfontstyle,"MIN"))                         //~v783I~//+v9e6R~
	  			fontid=80;                   //[ESC][80;y          //~v783I~
	  		if (!stricmp(Pfontstyle,"GOT"))                         //~v783I~//+v9e6R~
	  			fontid=81;                   //[ESC][81;y          //~v783I~
                                                                   //~v864I~
	  		if (!stricmp(Pfontstyle,"SYM"))   //dutch801            //~v864R~//+v9e6R~
            {                                                      //~v864I~
                fontsetreq=1;                //set char set name   //~v864I~
                fontid=99;                   //dummy(bypass [esc][n;y)//~v864I~
            }                                                      //~v864I~
                                                                   //~v864I~
	  		if (fontid==-1)                                        //~v783I~
            {                                                      //~v91pI~
				if (dbcsenv)	//DBCS mode                        //~v783I~
        			optionerr("フォントスタイル(Canon)",Pfontstyle-2);//errmsg and exit//~v864R~//+v9e6R~
				else			//SBCS mode                        //~v783I~
		        	optionerr("Font Style(Canon)",Pfontstyle-2);  //errmsg and exit//~v864R~//+v9e6R~
            }                                                      //~v91pI~
                                                                   //~v783I~
		}//font style parm exist                                   //~v783I~
        break;                                                     //~v844I~
                                                                   //~v844I~
#ifdef W32                                                         //~v844I~
	case PRINTER_WIN:   //windows                                  //~v844I~
		win_setupfont(Pfontstyle);                                  //~v844R~//+v9e6R~
        break;                                                     //~v844I~
#endif                                                             //~v844I~
#ifdef GXP                                                         //~v92dI~
	case PRINTER_WIN:   //windows                                  //~v92dR~
		lnx_setupfont(Pfontstyle);                                  //~v92dI~//+v9e6R~
        break;                                                     //~v92dI~
#endif                                                             //~v92dI~
                                                                   //~v844I~
	}//by prn type
//*process font style parm end  v7.24a
}//escfontchk                                                      //~v783R~
                                                                   //~v783R~
//*************************************                            //~v783R~
//* printer type chk                                               //~v783R~
//* parm1 :printer type parameter                                  //~v783R~
//* parm2 :int printer type output area                            //~v783I~
//* return:cmdfile name ptr                                        //~v783R~
//*************************************                            //~v783R~
char *escprntyp(char *cptr,int *Ppprntyp,int *Ppskip1stff)         //~v785I~
{                                                                  //~v783R~
	int prntyp;                                                    //~v783R~
	char *cmdfile=NULL;                                                 //~v783I~//~v965R~
//********************                                             //~v783R~
      prntyp=toupper(*cptr);			//v7.0r                 //~v74lI~
      switch (prntyp)					//v7.0r                 //~v74lI~
      {                                                         //~v74lI~
//    case 'I':                                                    //~v783R~
//    case 'E':                                                    //~v783R~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
	  case PRINTER_WIN:           //win version only               //~v844M~
#else                                                              //~v844I~
	  case PRINTER_WIN:           //win version only               //~v844I~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v844I~
//        	printf("プリンタータイプ =W はWin版のみ\n");//errmsg and exit v4.9a//~v92nR~
        	printf("プリンタータイプ =W はWin/Gnome版のみ\n");//errmsg and exit v4.9a//~v92nI~
		else			//SBCS mode v4.9a                          //~v844I~
//      	printf("Printer Type=W is for Win version only\n");//errmsg and exit v3.8r//~v92nR~
        	printf("Printer Type=W is for Win/Gnome version only\n");//errmsg and exit v3.8r//~v92nI~
        uexit(8);                                                  //~v848I~
        break;                                              //v3.8a//~v844I~
#endif                                                             //~v844I~
#ifdef GTKPRINT                                                    //~v973M~
#else                                                              //~v973M~
	  case PRINTER_IBM:                                            //~v783I~
      case PRINTER_ESCP:                                           //~v783I~
      case PRINTER_CANNON:                                         //~v783I~
#endif //!GTKPRINT                                                 //~v973I~
      case '/':     //missing printer type                         //~v90xI~
      	if (prntyp=='/')					//v7.0r                //~v90xI~
        {                                                          //~v90xI~
      		prntyp=*Ppprntyp;		//input is default             //~v90xI~
            cptr--;		//cptr+1 is form                           //~v90xI~
        }                                                          //~v90xI~
    	cmdfile=0;          	//reset previous /E@               //~v783R~
//#ifdef W32                                                       //~v90yR~
//        if (prntyp==PRINTER_WIN)    //nor form                   //~v90yR~
//            if (*(cptr+1))  //form specified                     //~v90yR~
//            {                                                    //~v90yR~
//                if (dbcsenv)    //DBCS mode v4.9a                //~v90yR~
//                    printf("プリンタータイプ W ではフォーム指定できません");//~v90yR~
//                else            //SBCS mode v4.9a                //~v90yR~
//                    printf("Form specification is not allowed for Printer-Type=W");//~v90yR~
//                uexit(8);                                        //~v90yR~
//            }                                                    //~v90yR~
//#endif                                                           //~v90yR~
        escformchk(cptr+1);                                        //~v783I~
#ifdef UNX                                                         //~v90iI~
#else                                                              //~v90iI~
        if (prntyp==PRINTER_CANNON)                                //~v785I~
        	*Ppskip1stff=1;	//skip first FF                        //~v785I~
		else                                                       //~v785I~
        	*Ppskip1stff=0; //write FF                             //~v785I~
#endif                                                             //~v90wR~
        break;                                              //v3.8a//~v783R~
//#endif                                                           //~v90wR~
      case '@':					//v5.5a command file spec       //~v74lI~
#ifdef GTKPRINT                                                    //~v974I~
        uerrexit("cmdfile(%cE@) option is not supported by gxp.",0,//~v974I~
        		CMDFLAG_PREFIX);                                   //~v974I~
#else                                                              //~v974I~
		cmdfile=cptr+1;			//v5.5a                         //~v74lI~
#endif                                                             //~v974I~
        break;                                              //v3.8a//~v74lI~
      default:                                                  //~v74lI~
#ifdef GTKPRINT                                                    //~v973I~
		uerrexit("printer type is \"w\" only for gxp",             //~v973I~
        		 "gxpでは プリンタータイプは \"w\" のみです");     //~v973I~
#else                                                              //~v973I~
		if (dbcsenv)	//DBCS mode v4.9a                       //~v74lI~
        	optionerr("プリンタータイプ",cptr-2);//errmsg and exit v4.9a//~v783R~
		else			//SBCS mode v4.9a	                    //~v74lI~
        	optionerr("Printer Type",cptr-2);//errmsg and exit v3.8r//~v783R~
#endif                                                             //~v973I~
        break;                                              //v3.8a//~v74lI~
	  }	                                                        //~v74lI~
      *Ppprntyp=prntyp;                                            //~v783I~
#ifdef W32                                                         //~v848I~
	if (prntyp!=PRINTER_WIN)	                                   //~v848I~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v848I~
        	printf("\nプリンタータイプに Windows 以外が指定されました\n");//errmsg and exit v4.9a//~v848R~
		else			//SBCS mode v4.9a                          //~v848I~
//      	printf("\n(Warning)Printer type is not Windows\n",cptr-2);//errmsg and exit v3.8r//~v848I~//~v9e6R~
        	printf("\n(Warning)Printer type is not Windows\n");//errmsg and exit v3.8r//~v9e6I~
#endif                                                             //~v848I~
#ifdef GXP                                                         //~v92dI~
	if (prntyp!=PRINTER_WIN)                                       //~v92dR~
        uerrmsg("(Warning)Printer type is not GnomePrint(W)\n",    //~v92dR~
             "(Warning)プリンタータイプに GnomePrint(W) 以外が指定されました");//~v92dI~
#endif                                                             //~v92dI~
      return cmdfile;                                              //~v783I~
}//escprntyp                                                       //~v783R~
