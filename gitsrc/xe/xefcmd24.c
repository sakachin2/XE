//*CID://+vbq6R~:                             update#=  518;       //~vbq6R~
//*************************************************************
//*xefcmd24.c                                                      //~v42hR~
//*  same,xx,ppsrch                                                //~v42hR~
//****************************************************************
//vbq6:200516 (Bug)word of errmsg of "Alt+] not found" corrupted   //~vbq6I~
//vbq3:200420 Alt/Ctrl+[/](search word); miss prev word containing splitter by pgdn/up/left/right//~vbp3I~
//vbp2:181028 (Bug)Alt+"/" did not stop at "/>" (e.g. <tag .... />) when next is not space but crlf; ==>pair not found//~vbp2I~
//vbe0:171231 add function to search xml tag pair                  //~vbe0I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120615 (BUF)FWF cmd reverse not continue after macsrch/pairsrch//~vafhI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7s:100823 (BUG)searchword recover fail for EBC file(u8str saved but recovery is by simple getmixword//~va7sI~
//va7n:100821 FWF cmd:issue errmsg for invalid specification if not func key//~va7mI~
//va7m:100821 (BUG)FWF cmd;\(xx[(|)], \)x[(|)] was ignored. 1st (/) should be accepted as data//~va7mI~
//va7k:100821 (BUG)FWF cmd;getword fail on ebc file when delm str input is by utf8.//~va7kI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5a:100502 (BUG) FWF cmd,punctuation is not effebctive when multimute delm not found(1 byte delm case is ok)//~va5aI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2g:091231 (BUG)/* */ ppsrch fail by if * between /* and */     //~va2gI~
//va23:091210 (BUG)FWF cmd search previous word when csr is out of area even if operand specified//~va20I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v7b0:090504 os/s compiler warning                                //~v7b0I~
//v7av:090411 allow dbcs boundary char for FWF/FWB                 //~v7avI~
//v79V:081028 save and restore search word(A+[) between sessions.  //~v79VI~
//v78P:080526 (BUG)A+]/[ (srch word) ABEND when reserch(csr is out of file area)//~v78PI~
//v77M:080206 C+[ etc;allow prev word search when csr is out of screen//~v77MI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v66t:051119 (BUG) pair search match with dbcs 2nd byte for []{} search//~v66tI~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v62d:050312 matching cmd;find *= col1 col2 & ^* col3 col4        //~v62dI~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v62a:050311 -m[n] option of find cmd to keep previous reverse;n:multi rev from next//~v62aI~
//v52i:030831 dos and os2 compiler waring                          //~v52iR~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v498:020617 XX cmd support .a .b                                 //~v498I~
//v494:020616 xx cmd;too many operand err chk                      //~v494I~
//v47h:020223 (BUG)compiler allow like as #endif//                 //~v47hI~
//            c1021 means no # allowd before identifier.           //~v47hI~
//            identifier is letter,digit,"_".                      //~v47hI~
//v47g:020223 (BUG)macro pair serach reverse offset err when cont type macro//~v47gI~
//v47f:020223 (BUG)macro pair serach err when nested backword search//~v47fI~
//            sequence of #if,#elid,#elsif,#else                   //~v47fI~
//v47e:020223 (BUG)macro pair serach err when nested backword search//~v47eI~
//            sequence of #else,#if,#endif                         //~v47eI~
//v45t:011215 #if/#endif pair search                               //~v45tI~
//v43h:011030 (BUG)no highlight pair when on the same line         //~v43hI~
//v42w:010929 pair-parenthesis search  by alt+, except excluded line//~v42wI~
//v42h:010929 pair-parenthesis search  by alt+.                    //~v42hI~
//v40L:010716 add option to "x *= all" of minimum same lineno      //~v40LI~
//v40z:010625 column range support for x =all(same as above)       //~v40zI~
//v40p:010603 add x *= (exclude same as above line)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>

#ifdef DOS
#else
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>
#include <ustring.h>
#include <ufile.h>
#include <uedit.h>
#include <utrace.h>
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20R~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"
#include "xefile22.h"                                              //~v77EI~
#include "xefile3.h"                                               //~v42hI~
#include "xefile6.h"
#include "xefunc.h"
#include "xefcmd2.h"
#include "xefcmd22.h"
#include "xefcmd23.h"                                              //~v77MI~
#include "xefcmd24.h"                                              //~v498I~
#include "xefcmd3.h"                                               //~v498I~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd4.h"                                               //~v62dI~
#include "xeerr.h"
#include "xefsub.h"
#include "xepan.h"                                                 //~v77EI~
#include "xecap.h"                                                 //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub2.h"                                                //~va20I~
#include "xeutf.h"                                                 //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
#define MAX_ELEMENT_NAME 128                                       //~vbe0M~
#define XML_VALID_CHAR       "-_."                                 //~vbe0M~
                                                                   //~vbe0I~
#define XML_TAG1             '<'     //<element>...                //~vbe0I~
#define XML_TAG2             '>'     //                            //~vbe0I~
#define XML_TAGT             '/'     //<elemennt ... />, </element>//~vbe0R~
#define XML_CMT1             '!'     //<elemennt ... />, </element>//~vbe0I~
#define XML_CMT2             '-'     //<elemennt ... />, </element>//~vbe0I~
#define XML_OTH1             '?'     //                            //~vbe0I~
#define XML_DELM_NAME      "> \t"                                  //~vbe0R~
                                                                   //~vbe0I~
#define XMLT_START           1       //<xxx>                       //~vbe0I~
#define XMLT_STARTATTR       2       //<xxx ... />                 //~vbe0I~
#define XMLT_STARTCMT        3       //<!--                        //~vbe0I~
#define XMLT_STARTOTHER      4       //<! but not <--, <?          //~vbe0I~
#define XMLT_END             5       //</xxx>                      //~vbe0I~
#define XMLT_CLOSEATTR       6       //"/>" ,csr is on ">"         //~vbe0R~
#define XMLT_ENDCMT          7       // -->                        //~vbe0I~
#define XMLT_CLOSEOTHER      8       //">" but not "/>"            //~vbe0I~
#define XMLT_CLOSEATTR2      9       //"/>" ,csr is on "/"         //~vbe0I~
#define XMLT_ENDCMT2        10       //"-->" ,csr is on 1st "-"    //~vbe0I~
#define XMLT_ENDCMT3        11       //"-->" ,csr is on 2nd "-"    //~vbe0I~
                                                                   //~vbe0I~
#define MACTR          6                                           //~v45tI~
#define MAC_IF         0                                           //~v45tI~
#define MAC_IFDEF      1                                           //~v45tI~
#define MAC_IFNDEF     2                                           //~v45tI~
#define MAC_ELSE       3                                           //~v45tI~
#define MAC_ENDIF      4                                           //~v45tI~
#define MAC_ELIF       5                                           //~v45tI~
static char *Smacname[MACTR]={"if","ifdef","ifndef","else","endif","elif"};//~v45tR~
static int   Smacdest[MACTR]={1   ,1      ,1       ,0     ,-1     ,0     };//~v45tR~
static int   Smaclen [MACTR]={2   ,5      ,6       ,4     ,5      ,4     };//~v45tR~
                                                                   //~v45tI~
static char Snxsw=0;  //cmd id of NX search                        //~v42wR~
//static int Soldkbdinpctr=0;	  //to chk continuous input            //~v45tI~//~v79VR~
static int Soldkbdinpctr=-2;	  //never match with Gkbdinpctr before search//~v79VI~
static int Sstartmacdest;	  //dest id by macro type              //~v45tR~
//static char   Ssrchword[MAXCOLUMN];   //word get area              //~v77ER~//~v79VR~
//static int    Ssrchwordlen,Ssrchwordoffs;                        //~v79VR~
static int    Ssrchwordoffs;                                       //~v79VI~
static int    Ssrchstat;                                           //~v77MI~
#define SS_WORD_REUSE      0x01    //prev word srch                //~v77MI~
#ifdef UTF8UCS2                                                    //~va20I~
#define SS_RESTART         0x02    //cv after session restart done //~va20R~
	static char   Sswu8[MAXCOLUMN*UTF8_MAXCHARSZMAX];   //word get area//~va20R~
	static char   Sswlc[MAXCOLUMN];   //word get area              //~va20R~
	static char   Sswdd[MAXCOLUMN];   //word get area              //~va20R~
	static char   Sswdbcs[MAXCOLUMN];   //word get area            //~va20R~
    static int    Sswlenu8,Sswlendd,Sswlenlc;                      //~va20R~
#endif                                                             //~va20I~
static PULINEH    Ssrchwordplh;                                    //~v77EI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define COMMENT_SLASH      '/'                                     //~va50I~
#define COMMENT_AST        '*'                                     //~va50I~
#define MACRO_ID           '#'        //macro                      //~va50I~
#define WORD_ID            'w'        //word search                //~va50I~
static char Sparenid[]  ="()[]{}<>/*#";                            //~va50I~
static char Sparenid2[] =")(][}{><**#";                            //~va50I~
static int  Sparendest[]={1,-1,1,-1,1,-1,1,-1,2,-2,0};//dest and string len//~va50I~
                                                                   //~va50I~
static char Sparenid_ebc[sizeof(Sparenid)];                        //~va50I~
static char Sparenid2_ebc[sizeof(Sparenid2)];                      //~va50I~
static char Sparenid3_ebc[]={COMMENT_SLASH,COMMENT_AST,MACRO_ID,WORD_ID};//~va50R~
static int 	Shandle=-1;                                            //~va79I~
#define COMMENT_SLASH_EBC  Sparenid3_ebc[0]                        //~va50I~
#define COMMENT_AST_EBC    Sparenid3_ebc[1]                        //~va50I~
#define MACRO_ID_EBC       Sparenid3_ebc[2]                        //~va50I~
#define WORD_ID_EBC        Sparenid3_ebc[3]                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************************************************
//****************************************************************
//LONG saasrchstring(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pplhend,//~v49bR~
//					PULINEH *Ppplhs,PULINEH *Ppplhe,               //~v49bR~
//  				int Pcasesw,SHORT Prange1,SHORT Prange2);      //~v49bR~
int ppsrchsub(PUCLIENTWE Ppcw,PULINEH Pplh,int Poffset,int Pppsrch,int Pppsrch2,int Pdest);//~v42hI~
int ppsrchsub2(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pppsrch,int Pppsrch2,int Pdest);//~v42hR~
int ppsrchmac(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int *Ppmactype,int *Ppdest);//~v45tR~
int ppsrchmacrochk(int Pinitsw,PULINEH Pplh,int *Ppoffset,int *Prevlen,//~v45tI~
					int *Ppmactype,int *Ppdest,int *Pporgdest);    //~v45tI~
int fcmdgetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffs,int *Pplen,int Pmaxlen,char *Pdelm);//~v77EI~//~vbp3R~
int fcmdsrchwordopdchk(PUCLIENTWE Ppcw,char *Pdelm);               //~v77EI~
int ppsrchword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pswcase,int Pdest);//~v77EI~
////****************************************************************//~v49bR~
////!fcmdxallsame                                                  //~v49bR~
////*find command                                                  //~v49bR~
////* parm1 :pcw                                                   //~v49bR~
////* parm2 :pfh                                                   //~v49bR~
////* parm3 :1:case sensitive                                      //~v49bR~
////* parm4 :column start                                          //~v49bR~
////* parm5 :column end                                            //~v49bR~
////* parm6 :minimum line count to be excluded(same line count -1) //~v49bR~
////* ret   :rc                                                    //~v49bR~
////****************************************************************//~v49bR~
//int fcmdxallsame(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pcasesw,       //~v49bR~
//                SHORT Prange1,SHORT Prange2,int Pminsame)        //~v49bR~
//{                                                                //~v49bR~
//    PULINEH plh,plhs,plhe,plh0,plhx,plhend;                      //~v49bR~
//    int rc;                                                      //~v49bR~
//    LONG xline,totxline=0;                                       //~v49bR~
////*********************************                              //~v49bR~
////*set linerange                                                 //~v49bR~
////  if (Ppcw->UCWtype!=UCWTFILE)                                 //~v49bR~
////  {                                                            //~v49bR~
////      uerrmsg("\"eXclude same line\" cmd is file screen only", //~v49bR~
////              "同一内容行の非\x95\\コマンドはファイル画面でのみ有効");//~v49bR~
////      return 4;                                                //~v49bR~
////  }                                                            //~v49bR~
//    plh=UGETQNEXT(UGETQTOP(&Ppfh->UFHlineque));                  //~v49bR~
//    rc=fcmdsetabrange(Ppcw,Ppfh,SUBCMD_ALL,&plh,&plhend);//set from/to plh//~v49bR~
////*plhend is next line of label                                  //~v49bR~
//    if (rc>=4)  //label err,not found                            //~v49bR~
//            return 4;                                            //~v49bR~
//    if (rc==2)  //label not found                                //~v49bR~
//        return 1;                                                //~v49bR~
////*search                                                        //~v49bR~
//    for (;;)                                                     //~v49bR~
//    {                                                            //~v49bR~
////      xline=saasrchstring(Ppcw,Ppfh,plh,plhend,&plhs,&plhe,Pcasesw,Prange1,Prange2);//~v49bR~
//        xline=0;    //no stop at minsame count                   //~v49bR~
//        rc=fcmdsamesrch(Ppcw,Ppfh,plh,plhend,&plhs,&plhe,Pcasesw,Prange1,Prange2,Pminsame,SUBCMD_ALL,&xline,1);//~v49bR~
////      if (!xline)                                              //~v49bR~
//        if (rc)         //not found                              //~v49bR~
//            break;                                               //~v49bR~
////    if (xline>=Pminsame)                                       //~v49bR~
////    {                                                          //~v49bR~
//        plhx=UGETQNEXT(plhs);   //exclude from next              //~v49bR~
//        if (lcmdexcsame(Ppcw,plhx,plhe)==UALLOC_FAILED)  //excluded one line//~v49bR~
//            return UALLOC_FAILED;                                //~v49bR~
//        if (!totxline)                                           //~v49bR~
//            plh0=plhs;                                           //~v49bR~
//        totxline+=xline;                                         //~v49bR~
////    }                                                          //~v49bR~
//        plh=UGETQNEXT(plhe);                                     //~v49bR~
//        if (plhend==plhe)    //reached to label end line         //~v49bR~
//            break;                                               //~v49bR~
//    }                                                            //~v49bR~
//    if (totxline)           //exclude/include occured            //~v49bR~
//    {                                                            //~v49bR~
//        UPCTRREQ(Ppfh);                                          //~v49bR~
//        fcmdscrollpage(Ppcw,plh0); //to 2nd line                 //~v49bR~
//        filesetcsr(Ppcw,plh0,0,0);      //csr set by lcmdexc     //~v49bR~
//        rc=0;                                                    //~v49bR~
//    }//first time                                                //~v49bR~
//    else                                                         //~v49bR~
//        rc=4;                                                    //~v49bR~
//    uerrmsg("Excluded %d lines",                                 //~v49bR~
//            "%d 行 非\x95\\示化",                                //~v49bR~
//            totxline);                                           //~v49bR~
//    return rc;                                                   //~v49bR~
//}//fcmdxallsame                                                  //~v49bR~
//****************************************************************
//!fcmdsamesrch                                                    //~v49bR~
//*search same as above line                                       //~v49bR~
//* parm1 :pcw
//* parm2 :plh search start                                        //~v49bR~
//* parm3 :plh search end(next of label line)                      //~v49bR~
//* parm4 :output plh 1st same line                                //~v49bR~
//* parm5 :optional output plh last same line                      //~v49bR~
//* parm6 :case sw                                                 //~v49bR~
//* parm7 :col range start                                         //~v49bR~
//* parm8 :col range end                                           //~v49bR~
//* parm9 :same minimum count                                      //~v49bR~
//* parm10:subcmdid                                                //~v49bR~
//* parm11:input:search stop line count,optional output same line count//~v49bR~
//* parm12:excludesw                                               //~v49bI~
//*rc     :rc 0,4,UALLOC_FAILED;                                   //~v49bR~
//****************************************************************
//LONG saasrchstring(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pplhend,//~v49bR~
int fcmdsamesrch(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pplhend,//~v49bR~
					PULINEH *Ppplhs,PULINEH *Ppplhe,               //~v40zI~
//      			int Pcasesw,SHORT Prange1,SHORT Prange2)       //~v49bR~
        			int Pcasesw,SHORT Prange1,SHORT Prange2,int Pminsame,//~v49bR~
					int Psubcmdid,LONG *Psamelinectr,int Pexcludesw)//~v49bI~
{
	PULINEH plhs=NULL,plhe=NULL,plh;                               //~vaf9R~
	PULINEH plh2,plhn=0;                                           //~v52iR~
    int len,lens=0,rc;                                               //~v40zR~//~vaf9R~
    int stoplinectr;                                               //~v49bI~
    LONG xline=0;                                                  //~vaf9R~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,optdds;                                         //~va20I~
#endif                                                             //~va20I~
//*****************
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20R~
    optdds=XESUBDDSCO_EQCHKONLY;                                   //~va20R~
    if (!Pcasesw)                                                  //~va20R~
    	optdds=FCMDDDSCO_NOCASE;                                   //~va20R~
#endif                                                             //~va20I~
	if (Psamelinectr)                                              //~v49bI~
//  	stoplinectr=*Psamelinectr;                                 //~v49bI~//~vb2ER~
    	stoplinectr=(int)(*Psamelinectr);                          //~vb2EI~
    else                                                           //~v49bI~
    	stoplinectr=0;                                             //~v49bI~
    for (plh=Pplh;plh;)
    {
//      for (plhs=0,xline=0;plh;plh=UGETQNEXT(plh))                //~v49bR~
        for (plhs=0,xline=0;plh;plh=plhn)                          //~v49bR~
        {
            if (Psubcmdid==SUBCMD_PREV)                            //~v49bM~
				plhn=UGETQPREV(plh);                               //~v49bM~
            else                                                   //~v49bM~
				plhn=UGETQNEXT(plh);                               //~v49bM~
        	if (plh==Pplhend)                                      //~v40zI~
                break;                                             //~v40zI~
//          if (plh->ULHtype==ULHTEXCLUDE)	//exclude hdr          //~v49bR~
//          {                                                      //~v49bR~
//          	if (xline) 		//same line continuing             //~v49bR~
//              	break;                                         //~v49bR~
//          	for (;plh=UGETQNEXT(plh),plh;)                     //~v49bR~
//          		if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //skip exluded//~v49bR~
//              		break;                                     //~v49bR~
//          }                                                      //~v49bR~
            if (plh->ULHtype!=ULHTDATA)     //hdr nochk
                continue;
            if (!plh->ULHdbcs) //not displayed
                if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len
                    return UALLOC_FAILED;
            len=plh->ULHlen;
            if (!plhs)
            {
	            if (len<Prange1)	//short line                   //~v40zR~
    	        	continue;                                      //~v40zI~
              if (len>Prange2)                                     //~v40zR~
                lens=Prange2;                                      //~v40zI~
              else                                                 //~v40zI~
                lens=len;   //start line len
                plhs=plh;   //top data line
                continue;
            }
            if (len<Prange1)	//short line after 1st line        //~v40zR~
            	break;                                             //~v40zI~
          	if (len>Prange2)                                       //~v40zR~
          		len=Prange2;                                       //~v40zR~
            if (len!=lens)  //length match
                break;
            len-=Prange1;                                          //~v40zI~
#ifdef UTF8UCS2                                                    //~va20I~
          if (swutf8file)                                          //~va20I~
          {                                                        //~va20I~
			rc=fcmdddstrcmp(optdds,plh,Prange1,plhs,Prange1,len);  //~va20R~
          }                                                        //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
          {                                                        //~va20I~
            if (Pcasesw)
                rc=memcmp(plh->ULHdata+Prange1,plhs->ULHdata+Prange1,(UINT)len);//~v40zR~
            else
                rc=memicmp(plh->ULHdata+Prange1,plhs->ULHdata+Prange1,(UINT)len);//~v40zR~
          }                                                        //~va20I~
            if (rc)        //same line
                break;
//          if (xline)                                             //~v49bR~
//          	lcmdclearlcmd(Ppfh,plh); //clear pending cmd for to be excluded//~v49bR~
            xline++;
            plhe=plh;		//last matched
            if (stoplinectr)                                       //~v49bI~
            	if (stoplinectr==xline)	//reached to stop line ctr //~v49bR~
                	break;                                         //~v49bI~
        }//until unmatch line appear
//      if (xline)                                                 //~v49bR~
        if (xline && xline>=Pminsame)                              //~v49bR~
        {                                                          //~v49bR~
        	if (Pexcludesw)                                        //~v49bI~
                for (plh2=plhs;plh2;plh2=plhn)                     //~v49bR~
                {                                                  //~v49bR~
            		if (Psubcmdid==SUBCMD_PREV)                    //~v49bI~
						plhn=UGETQPREV(plh2);                      //~v49bR~
            		else                                           //~v49bI~
						plhn=UGETQNEXT(plh2);                      //~v49bR~
                    lcmdclearlcmd(Ppfh,plh2); //clear pending cmd for to be excluded//~v49bR~
                    if (plh2==plhe)                                //~v49bR~
                        break;                                     //~v49bR~
                }                                                  //~v49bR~
        	break;                                                 //~v49bR~
        }                                                          //~v49bR~
        if (!plh)
        	break;
        if (plh==Pplhend)                                          //~v40zI~
            break;                                                 //~v40zI~
    }//until eof
    *Ppplhs=plhs;
  if (Ppplhe)                                                      //~v49bR~
    *Ppplhe=plhe;
    if (Psamelinectr)                                              //~v49bR~
    	*Psamelinectr=xline;                                       //~v49bR~
//  return xline;                                                  //~v49bR~
    if (!xline || xline<Pminsame)                                  //~v49bR~
        return 4;                                                  //~v49bR~
    return 0;                                                      //~v49bR~
}//fcmdsamesrch                                                    //~v49bR~
//**************************************************************** //~v62dI~
//!fcmdsamematch                                                   //~v62dI~
//*search word of 2nd scr file                                     //~v62dI~
//* parm1 :pcw                                                     //~v62dI~
//* parm2 :plh search start                                        //~v62dI~
//* parm3 :plh search end(next of label line)                      //~v62dI~
//* parm4 :case sw                                                 //~v62dI~
//* parm5 :col range start                                         //~v62dI~
//* parm6 :col range end                                           //~v62dI~
//* parm7 :subcmdid                                                //~v62dI~
//* parm8 :excludesw                                               //~v62dI~
//*rc     :rc 0:matched,1:bypass this line(not DATA),4:notf ,UALLOC_FAILED;//~v62dR~
//*rc     :rc 8:invalid file type                                  //~va20I~
//**************************************************************** //~v62dI~
int fcmdsamematch(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUFILEH Ppfh2,PULINEH Pplh,PULINEH Pplhend,//~v62dI~
        		int Pcasesw,int Pexcludesw,SHORT Prange1,SHORT Prange2,int Pkeypos)//~v62fR~
{                                                                  //~v62dI~
	PULINEH plh;                                                   //~v62dR~
    char *psrc;                                                    //~v62dI~
    int  lens,rc,range1,range2,ulhlen;                             //~v62dR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,optdds;                                         //~va20R~
#endif                                                             //~va20I~
//*****************                                                //~v62dI~
    if (Pplh->ULHtype!=ULHTDATA)     //hdr nochk                   //~v62dI~
    	return 1;					//continue                     //~v62dI~
    if (!Pplh->ULHdbcs) //not displayed                            //~v62dI~
    	if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand data len  //~v62dI~
        	return UALLOC_FAILED;                                  //~v62dI~
    ulhlen=Pplh->ULHlen;                                           //~v62dI~
	if (ulhlen<Prange2)	//short line                               //~v62dI~
    	return 4;       //for ! search                             //~v62dI~
//*****************                                                //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20R~
    optdds=0;                                                      //~va20I~
    if (!Pcasesw)                                                  //~va20R~
    	optdds=FCMDDDSCO_NOCASE;                                   //~va20R~
#endif                                                             //~va20I~
    psrc=Pplh->ULHdata+Prange1;                                    //~v62dI~
    lens=Prange2-Prange1;                                          //~v62dI~
    range1=Pkeypos;                                                //~v62fR~
    range2=range1+lens;	//same len as source                       //~v62dI~
    plh=UGETQTOP(&Ppfh2->UFHlineque);                              //~v62dR~
    for (;plh;plh=UGETQNEXT(plh))                                  //~v62fR~
    {                                                              //~v62dI~
    	if (plh->ULHtype!=ULHTDATA)     //hdr nochk                //~v62dR~
        	continue;                                              //~v62dR~
        if (!plh->ULHdbcs) //not displayed                         //~v62dR~
        	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v62dR~
            	return UALLOC_FAILED;                              //~v62dR~
        ulhlen=plh->ULHlen;                                        //~v62dR~
                                                                   //~va20I~
	    if (ulhlen<range2)	//short line                           //~v62dR~
    		continue;                                              //~v62dR~
#ifdef UTF8UCS2                                                    //~va20I~
      if (swutf8file)                                              //~va20I~
      {                                                            //~va20I~
		rc=fcmdddstrcmp(optdds,plh,range1,Pplh,Prange1,lens);      //~va20R~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
      {                                                            //~va20I~
        if (Pcasesw)                                               //~v62dR~
            rc=memcmp(plh->ULHdata+range1,psrc,(UINT)lens);        //~v62dR~
        else                                                       //~v62dR~
            rc=memicmp(plh->ULHdata+range1,psrc,(UINT)lens);       //~v62dR~
      }                                                            //~va20I~
        if (!rc)        //matched                                  //~v62dR~
            break;                                                 //~v62dR~
    }//until eof                                                   //~v62dI~
    if (plh)                                                       //~v62dI~
    {                                                              //~v62dI~
		lcmdshifterr(plh,0,0);//no exclude line highlight,no output 1st err line//~v62dI~
    	return 0;		//matched                                  //~v62dI~
    }                                                              //~v62dI~
    return 4;			//unmatch                                  //~v62dR~
}//fcmdsamematch                                                   //~v62dI~
//**************************************************************** //~v40LI~
// exclude line exchange                                           //~v40LI~
//*rc   :                                                          //~v40LI~
//**************************************************************** //~v40LI~
int func_xx_file(PUCLIENTWE Ppcw)                                  //~v40LI~
{                                                                  //~v40LI~
    PUFILEH pfh;                                                   //~v40LI~
    PULINEH plh,plh1,plh2=0,plhx;                                    //~v40LR~
    PULINEH plhend,plhn;                                           //~v498R~
    PUFILEC pfc;                                                   //~v40LI~
    int     rc,opdno,plhendsw=0;                                   //~v498R~
    long   xctr=0,nxctr=0;                                         //~v498I~
    long   incfctr=0;                                              //~v498I~
//*********************************                                //~v40LI~
//  if (Ppcw->UCWparm)		//operand                              //~v498R~
//  	return errtoomany();                                       //~v498R~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v498I~
	pfc=Ppcw->UCWpfc;                                              //~v40LI~
	pfh=pfc->UFCpfh;                                               //~v40LI~
    if (pfh->UFHtype==UFHTKFI)	//menu opt file                    //~v40LI~
    	return 4;                                                  //~v40LI~
//*set linerange                                                   //~v498I~
    plh=UGETQTOP(&pfh->UFHlineque);//search from first if no label //~v498I~
    if (rc=fcmdgetabplh(Ppcw,pfh,&plh,&plhend,0),rc)//set from/to plh(0:end is plh on label)//~v498R~
    	return rc;                                                 //~v498I~
    if (plhend)                                                    //~v498I~
    {                                                              //~v498I~
    	if (opdno!=2)                                              //~v498I~
			return errtoomany();                                   //~v498I~
    }                                                              //~v498I~
    else                                                           //~v498I~
    	if (opdno)                                                 //~v498I~
			return errtoomany();                                   //~v498I~
    UPCTRREQ(pfh);                                                 //~v40LI~
//  plh=UGETQTOP(&pfh->UFHlineque);//search from first             //~v498R~
//for the case label plh is in excluded line                       //~v498I~
	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                     //~v498I~
        for(plhn=0;plh && UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);plh=plhn)//~v498R~
        {                                                          //~v498I~
            plhn=UGETQNEXT(plh);    //                             //~v498I~
			if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)	//display excluded line//~v498I~
                return UALLOC_FAILED;                              //~v498I~
            nxctr++;                                               //~v498I~
        	if (plh==plhend)                                       //~v498R~
            {                                                      //~v498I~
		        plhendsw=1;                                        //~v498I~
                break;                                             //~v498I~
            }                                                      //~v498I~
        }                                                          //~v498I~
  if (!plhendsw)                                                   //~v498I~
  {                                                                //~v498I~
    for (plh1=0;plh;)                                              //~v40LR~
	{                                                              //~v40LI~
        plhendsw=(plh==plhend);                                    //~v498I~
        switch(plh->ULHtype)                                       //~v40LI~
        {                                                          //~v40LI~
        case ULHTHDR:       	//hdr line                         //~v40LI~
	    	plh=UGETQNEXT(plh);                                    //~v40LI~
        	break;                                                 //~v40LI~
        case ULHTEXCLUDE:       //excluded line hdr                //~v40LI~
            plhx=plh;                                              //~v40LI~
		    plh=UGETQNEXT(plh);                                    //~v40LI~
            incfctr=0;                                             //~v498I~
			for(;plh && UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);plh=UGETQNEXT(plh))//~v40LI~
            {                                                      //~v498I~
	        	nxctr++;                                           //~v40LI~
                incfctr++;                                         //~v498I~
        		if (plh==plhend)                                   //~v498I~
                {                                                  //~v498I~
        			plhendsw=2;                                    //~v498I~
                    break;                                         //~v498I~
                }                                                  //~v498I~
            }                                                      //~v498I~
          if (plhendsw==2)  //end at intermediate of excluded      //~v498I~
          {                                                        //~v498I~
			if (lcmdincf(Ppcw,plhx,(int)incfctr,0)==UALLOC_FAILED)	//excluded one line//~v52iR~
	        	return UALLOC_FAILED;                              //~v498I~
          }                                                        //~v498I~
          else                                                     //~v498I~
			if (lcmdincall(Ppcw,plhx,plhx,1)==UALLOC_FAILED)	//excluded one line//~v40LI~
	        		return UALLOC_FAILED;                          //~v40LI~
            if (plh1) 		//prev display line                    //~v40LR~
            {                                                      //~v40LI~
				if (lcmdexc(Ppcw,plh1,plh2,0)==UALLOC_FAILED)	//excluded one line//~v40LI~
	        		return UALLOC_FAILED;                          //~v40LI~
            	plh1=0;		//excluded previous display line       //~v40LI~
    		}	                                                   //~v40LI~
        	break;                                                 //~v40LI~
        default:				//not excluded data line           //~v40LI~
		    for (plh1=plh,plh2=0;plh;plh2=plh,plh=UGETQNEXT(plh))  //~v40LI~
            {                                                      //~v40LI~
				if (plh->ULHtype!=ULHTDATA)      //not displayed line//~v40LI~
                	break;                                         //~v40LI~
                xctr++;                                            //~v40LI~
        		if (plh==plhend)                                   //~v498I~
                {                                                  //~v498I~
                    plh2=plh;                                      //~v498I~
        			plhendsw=1;                                    //~v498I~
                    break;                                         //~v498I~
                }                                                  //~v498I~
            }                                                      //~v40LI~
		}                                                          //~v40LI~
        if (plhendsw)                                              //~v498I~
        	break;                                                 //~v498I~
	}//                                                            //~v40LI~
    if (plh1)       //prev display line                            //~v40LR~
        if (lcmdexc(Ppcw,plh1,plh2,0)==UALLOC_FAILED)   //excluded one line//~v40LI~
            return UALLOC_FAILED;                                  //~v40LI~
                                                                   //~v40LI~
  }                                                                //~v498I~
    UPCTRREQ(pfh);                                                 //~v40LI~
    uerrmsg("X=%ld,NX=%ld",0,                                      //~v40LI~
        		xctr,nxctr);                                       //~v40LI~
    lcmdexcludedmsg(LCXMO_MSGCAT,pfh);                             //~vb86I~
	return 0;                                                      //~v40LI~
}//func_xx_file                                                    //~v40LI~
//**************************************************************** //~v42wI~
// parethesis search except excluded                               //~v42wI~
//*rc   :                                                          //~v42wI~
//**************************************************************** //~v42wI~
int func_ppsrchnx(PUCLIENTWE Ppcw)                                 //~v42wI~
{                                                                  //~v42wI~
	int rc;                                                        //~v42wI~
//*********************************                                //~v42wI~
	Snxsw=1;                                                       //~v42wI~
	rc=func_ppsrch(Ppcw);                                          //~v42wR~
	Snxsw=0;                                                       //~v42wI~
    return rc;                                                     //~v42wI~
}//func_ppsrchnx                                                   //~v42wR~
//**************************************************************** //~v42hI~
// parethesis search                                               //~v42wR~
//*rc   :                                                          //~v42hI~
//**************************************************************** //~v42hI~
int func_ppsrch(PUCLIENTWE Ppcw)                                   //~v42hI~
{                                                                  //~v42hI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#else                                                              //~va50I~
#define COMMENT_SLASH      '/'                                     //~v42hR~
#define COMMENT_AST        '*'                                     //~v42hR~
#define MACRO_ID           '#'        //macro                      //~v45tI~
#define WORD_ID            'w'        //word search                //~v77EI~
//static char Sparenid[]  ="()[]{}<>/*";                           //~v45tR~
static char Sparenid[]  ="()[]{}<>/*#";                            //~v45tI~
//static char Sparenid2[] =")(][}{><**";                           //~v45tR~
static char Sparenid2[] =")(][}{><**#";                            //~v45tI~
//static int  Sparendest[]={1,-1,1,-1,1,-1,1,-1,2,-2};             //~v45tR~
static int  Sparendest[]={1,-1,1,-1,1,-1,1,-1,2,-2,0};//dest and string len//~v45tI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
    PUFILEH pfh;                                                   //~v42hI~
    PULINEH plh;                                                   //~v42hR~
    PUFILEC pfc;                                                   //~v42hI~
	PUSCRD psd;                                                    //~v42hI~
	int offset;                                                    //~v42hR~
	int rc,ppsrch,ppsrch2,ppdest;                                  //~v42hR~
    int lrecl,ii;                                                  //~v42hR~
    int macrotype,revlen;                                          //~v45tR~
	UCHAR *pdata;                                                  //~v42hR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
	UCHAR *pdbcs;                                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,/*ppsrch_ebc,*/swebc_utf8;                           //~va50R~//~vaa7R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v42hI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*get ebcdic char                                                 //~va50I~
//  if (!Sparenid_ebc[0])	//not yet ebc trans                    //~va50I~//~va79R~
//  {                                                              //~va50I~//~va79R~
//  	UCVEBC_a2bcopy(1/*swebc*/,Sparenid,Sparenid_ebc,sizeof(Sparenid));//~va50I~//~va79R~
//  	UCVEBC_a2bcopy(1/*swebc*/,Sparenid2,Sparenid2_ebc,sizeof(Sparenid2));//~va50I~//~va79R~
//  	UCVEBC_a2bfld(1/*swebc*/,Sparenid3_ebc,sizeof(Sparenid3_ebc));//~va50R~//~va79R~
//  }                                                              //~va50I~//~va79R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	pfc=Ppcw->UCWpfc;                                              //~v42hI~
	pfh=pfc->UFCpfh;                                               //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
    handle=pfh->UFHhandle;                                         //~va79I~
    if (handle!=Shandle)	//not yet ebc trans                    //~va79I~
    {                                                              //~va79I~
    	Shandle=handle;                                            //~va79I~
    	UCVEBC_a2bcopy(1/*swebc*/,handle,Sparenid,Sparenid_ebc,sizeof(Sparenid)-1);//~va79I~//~va7kR~
    	UCVEBC_a2bcopy(1/*swebc*/,handle,Sparenid2,Sparenid2_ebc,sizeof(Sparenid2)-1);//~va79I~//~va7kR~
    	UCVEBC_a2bfld(1/*swebc*/,handle,Sparenid3_ebc,sizeof(Sparenid3_ebc));//~va79I~//~va7kR~
    }                                                              //~va79I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
    swebc_utf8=swutf8file|swebcfile;                               //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~v42hI~
    {                                                              //~v42hI~
    	uerrmsg("parenthesis search is not supported for binary file",//~v42hI~
        		"バイナリーファイルは括弧探索できません。");       //~v42hI~
        return 4;                                                  //~v42hI~
    }                                                              //~v42hI~
	if (!CSRONFILELINE(Ppcw))	//chk csr on file line             //~v42hI~
   		return errcsrpos();				//not on file client area  //~v42hR~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v42hI~
    offset=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;          //~v42hI~
	plh=psd->USDbuffc;                                             //~v42hI~
    pdata=plh->ULHdata;                                            //~v42hI~
    lrecl=plh->ULHlen;                                             //~v42hI~
    if (offset>=lrecl)                                             //~v42hI~
    	return errcsrpos();			//no filedata                  //~v42hR~
    if (plh->ULHtype!=ULHTDATA)                                    //~v42hI~
        return errcsrpos();                                        //~v42hR~
//*chk srch char                                                   //~v42hI~
    ppsrch=*(pdata+offset);                                        //~v42hR~
#ifdef UTF8UCS2                                                    //~va20I~
    pdbcs=plh->ULHdbcs;                                            //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    if (!UTF_isasciidbcs(swebc_utf8,*(pdbcs+offset)))//dbcs exist confirmed when ebc or utf8 file//~va50I~
  #else                                                            //~va50I~
    if (!UTF_isasciidbcs(swutf8file,*(pdbcs+offset)))              //~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
        return errcsrpos();                                        //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (swebcfile)                                                   //~va50I~
  {                                                                //~va50I~
    for (ii=0;ii<sizeof(Sparenid_ebc);ii++)                        //~va50I~
    	if (ppsrch==Sparenid_ebc[ii])                              //~va50I~
        	break;                                                 //~va50I~
    if (ii<sizeof(Sparenid_ebc))                                   //~va50I~
    {                                                              //~va50I~
//  	ppsrch_ebc=ppsrch;                                         //~va50I~//~vaa7R~
    	ppsrch=Sparenid[ii];                                       //~va50I~
    }                                                              //~va50I~
  }                                                                //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  {                                                                //~va50I~
    for (ii=0;ii<sizeof(Sparenid);ii++)                            //~v42hI~
    	if (ppsrch==Sparenid[ii])                                  //~v42hR~
        	break;                                                 //~v42hI~
  }                                                                //~va50I~
    if (ii>=sizeof(Sparenid))                                      //~v42hI~
    {                                                              //~v42hI~
    	uerrmsg("\"%c\" is not a parenthesis.\"%s\".",             //~v42hR~
        		"\"%c\" は括弧探索対象外\"%s\".",                  //~v42hR~
                ppsrch,Sparenid);                                  //~v42hI~
        return 4;                                                  //~v42hI~
    }                                                              //~v42hI~
    rc=0;                                                          //~v42hI~
    switch(ppsrch)                                                 //~v42hI~
    {                                                              //~v42hI~
    case COMMENT_SLASH:			// "/" of  "/*"                    //~v42hR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	if (offset>=lrecl-1 || *(pdata+offset+1)!=UCVEBC_CONST(swebcfile,COMMENT_AST))//~va50I~
#else                                                              //~va50I~
    	if (offset>=lrecl-1 || *(pdata+offset+1)!=COMMENT_AST)     //~v42hR~
#endif                                                             //~va50I~
        	rc=4;                                                  //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
		else                                                       //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (!UTF_isasciidbcs(swebc_utf8,*(pdbcs+offset+1)))        //~va50I~
	#else                                                          //~va50I~
    	if (!UTF_isasciidbcs(swutf8file,*(pdbcs+offset+1)))        //~va20I~
	#endif                                                         //~va50I~
        	rc=4;                                                  //~va20I~
#endif                                                             //~va20I~
    	break;                                                     //~v42hI~
    case COMMENT_AST:			//  "*" of "*/"                    //~v42hR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	if (offset>=lrecl-1 || *(pdata+offset+1)!=UCVEBC_CONST(swebcfile,COMMENT_SLASH))//~va50I~
#else                                                              //~va50I~
    	if (offset>=lrecl-1 || *(pdata+offset+1)!=COMMENT_SLASH)   //~v42hR~
#endif                                                             //~va50I~
        	rc=4;                                                  //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
		else                                                       //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (!UTF_isasciidbcs(swebc_utf8,*(pdbcs+offset+1)))        //~va50I~
	#else                                                          //~va50I~
    	if (!UTF_isasciidbcs(swutf8file,*(pdbcs+offset+1)))        //~va20I~
	#endif                                                         //~va50I~
        	rc=4;                                                  //~va20I~
#endif                                                             //~va20I~
    	break;                                                     //~v42hI~
    }                                                              //~v42hI~
    if (rc)                                                        //~v42hI~
    {                                                              //~v42hI~
        uerrmsg("Cursor is not on \"/*\" nor \"*/\"",0);           //~v42hR~
        return 4;                                                  //~v42hI~
    }                                                              //~v42hI~
    if (ppsrch==MACRO_ID)       //macro seach                      //~v45tI~
    {                                                              //~v45tI~
		if (ppsrchmacrochk(1,plh,&offset,&revlen,&macrotype,&ppdest,&Sstartmacdest))	//initial chk//~v45tR~
    		return 4;			//invalid macro stmt               //~v45tI~
        if (ppdest>0)                                              //~v45tI~
        	ppdest=revlen;                                         //~v45tI~
        else                                                       //~v45tI~
        	ppdest=-revlen;                                        //~v45tI~
        ppsrch2=macrotype;                                         //~v45tI~
    }                                                              //~v45tI~
    else                                                           //~v45tI~
    {                                                              //~v45tI~
    ppsrch2=Sparenid2[ii];                                         //~v42hR~
    ppdest=Sparendest[ii];                                         //~v42hI~
        Sstartmacdest=1;    //not use but avoid 0                  //~v45tI~
    }                                                              //~v45tI~
//search                                                           //~v42hI~
	if (rc=ppsrchsub(Ppcw,plh,offset,ppsrch,ppsrch2,ppdest),rc)    //~v42hR~
		return rc;                                                 //~v42hI~
	return 0;                                                      //~v42hI~
}//func_ppsrch                                                     //~v42hI~
//**************************************************************** //~v42hI~
// ppsrchsub                                                       //~v42hI~
// parm1:pcw                                                       //~v45tI~
// parm2:plh                                                       //~v45tI~
// parm3:start offset on plhdata                                   //~v45tI~
// parm4:one of pair                                               //~v45tI~
// parm5:another of pair to be serached/macro type for macro search//~v45tI~
// parm6:dest id and contain len of search word                    //~v45tR~
//*rc   :                                                          //~v42hI~
//**************************************************************** //~v42hI~
int ppsrchsub(PUCLIENTWE Ppcw,PULINEH Pplh,int Poffset,int Pppsrch,int Pppsrch2,int Pdest)//~v42hR~
{                                                                  //~v42hI~
	int offset,rc,width,scrollsz,nest;                             //~v42hR~
    int mactype,dest,locatesw;                                     //~v45tR~
    PULINEH plh;                                                   //~v42hI~
    PUFILEH pfh;                                                   //~v42hI~
    PUFILEC pfc;                                                   //~v42hI~
//**************************************                           //~v42hI~
	pfc=Ppcw->UCWpfc;                                              //~v42hM~
	pfh=pfc->UFCpfh;                                               //~v42hR~
	plh=Pplh;                                                      //~v42hR~
	offset=Poffset;                                                //~v42hR~
    nest=1;                                                        //~v42hI~
    mactype=Pppsrch2;	//for the case macro search                //~v45tI~
    dest=Pdest;                                                    //~v45tI~
    while(nest)                                                    //~v42hR~
    {                                                              //~v42hI~
      if (Pppsrch==WORD_ID)                                        //~v77ER~
      {                                                            //~v77EI~
		rc=ppsrchword(Ppcw,&plh,&offset,Pppsrch2/*casesw*/,Pdest);//dest determined by macro itself//~v77ER~
      }                                                            //~v77EI~
      else                                                         //~v77EI~
      if (Pppsrch==MACRO_ID)                                       //~v45tR~
		rc=ppsrchmac(Ppcw,&plh,&offset,&mactype,&dest);//dest determined by macro itself//~v45tR~
      else                                                         //~v45tM~
      {                                                            //~v45tI~
	    if (Pdest>0)                                               //~v42hR~
    		offset+=Pdest;     //skip current char                 //~v42hI~
		rc=ppsrchsub2(Ppcw,&plh,&offset,Pppsrch,Pppsrch2,Pdest);   //~v42hI~
      }                                                            //~v45tI~
        switch(rc)                                                 //~v42hI~
        {                                                          //~v42hI~
        case UALLOC_FAILED:                                        //~v42hR~
        	return rc;                                             //~v42hI~
        case 0:			//found                                    //~v42hI~
        	nest--;                                                //~v42hI~
            break;                                                 //~v42hI~
        case 1:         //nested                                   //~v42hI~
        	nest++;                                                //~v42hI~
            rc=0;                                                  //~v42hI~
            break;                                                 //~v42hI~
        case 2:         //cont found(else etc);exit only when nest==1//~v45tI~
        	if (nest==1)	//same level                           //~v45tI~
            	nest=0;     //exit loop                            //~v45tR~
            rc=0;                                                  //~v45tI~
            break;                                                 //~v45tI~
        default:                                                   //~v42hI~
        	break;                                                 //~v42hI~
        }                                                          //~v42hI~
        if (rc)       //not found                                  //~v42hR~
            break;                                                 //~v42hI~
    }//nest loop                                                   //~v42hI~
    if (nest)                                                      //~v42hI~
    {                                                              //~v42hI~
      if (Pppsrch!=WORD_ID)                                        //~v77ER~
    	uerrmsg("No corresponding for %c found(nest=%d)",          //~v47hR~
				"%c の相手が見つかりません(nest=%d)",              //~v47hR~
                Pppsrch,nest);                                     //~v42hR~
		Soldkbdinpctr=Gkbdinpctr;	//save for double ESC chk      //~vafhI~
        return 4;                                                  //~v42hI~
    }                                                              //~v42hI~
	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                     //~v42hI~
    {                                                              //~v42hI~
        UPCTRREQ(pfh);                                             //~v42hR~
		if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)	//display excluded line//~v42hI~
        	return UALLOC_FAILED;                                  //~v42hI~
    	UPCTRREQ(pfh);                                             //~v42hR~
	}                                                              //~v42hI~
//*move page to the line if not on current page                    //~v42hI~
	fcmdscrollpagemid(Ppcw,plh);                                   //~v42hI~
	width=Ppcw->UCWwidth-Ppcw->UCWlinenosz;                        //~v42hI~
	if (offset<pfc->UFCleft                                        //~v42hI~
	|| 	offset>=pfc->UFCleft+width)                                //~v42hI~
    {                                                              //~v42hI~
        if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))                 //~v42hI~
        {                                                          //~v42hI~
            if (offset>=pfc->UFCleft+width)                        //~v42hI~
                filepgrighthalf(Ppcw);                             //~v42hI~
        }                                                          //~v42hI~
        else                                                       //~v42hI~
        {                                                          //~v42hI~
            scrollsz=filehalfhscrollsz(Ppcw);//half scroll size    //~v42hI~
            pfc->UFCleft=max(0,(offset/scrollsz)*scrollsz-scrollsz);//~v42hI~
            UCBITON(Ppcw->UCWflag,UCWFDRAW);                       //~v42hI~
        }                                                          //~v42hI~
    }                                                              //~v42hI~
	filesetcsr(Ppcw,plh,1,offset-pfc->UFCleft);//csr set           //~v42hI~
//  plh->ULHrevoffs=(USHORT)offset;                                //~v43hR~
    if (Pdest<0)                                                   //~v45tR~
        Pdest=-Pdest;                                              //~v45tR~
  	if (Pppsrch!=MACRO_ID)                                         //~v45tI~
    	dest=Pdest;                                                //~v45tI~
    if (dest<0)                                                    //~v45tM~
        dest=-dest;                                                //~v45tM~
//  plh->ULHrevlen=(USHORT)Pdest;//reverse len  //same upctr as prev//~v43hR~
//  UCBITOFF(plh->ULHflag2,ULHF2MFOUND);//reset multiple           //~v43hR~
//  plh->ULHrevctr=pfh->UFHfindctr;//find cmd ctr for disply current;//~v43hR~
//  UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v43hR~
//  UCBITOFF(plh->ULHflag,ULHFCURCAP);//reset hilight reason cap   //~v43hR~
//  fcmdsetfindhighlight(pfh,Pplh,1,0, 	//1:locate,0:no linesrch   //~v45tR~
  if (Pppsrch==WORD_ID)                                            //~vafhI~
  {                                                                //~vafhI~
	if (Ssrchstat & SS_WORD_REUSE                                  //~vafhR~
    ||  (Soldkbdinpctr+1)==Gkbdinpctr)	//continued input          //~vafhI~
    	locatesw=0;                                                //~vafhI~
    else                                                           //~vafhI~
    	locatesw=1;                                                //~vafhI~
  }                                                                //~vafhI~
  else                                                             //~vafhI~
  {                                                                //~vafhI~
    if (!Sstartmacdest		//start from else etc                  //~v45tR~
    &&  (Soldkbdinpctr+1)==Gkbdinpctr)	//continued input          //~v45tR~
    	locatesw=0;                                                //~v45tI~
    else                                                           //~v45tI~
    	locatesw=1;                                                //~v45tI~
  }                                                                //~vafhI~
    locatesw|=FCMDSFHOPT_NOMULTIREV;        //reset multiple reverse//~v62aI~
  if (!(Ssrchstat & SS_WORD_REUSE))                                //~v77MI~
    fcmdsetfindhighlight(pfh,Pplh,locatesw,0, 	//1:locate,0:no linesrch//~v45tI~
			Poffset,Pdest,0);			//no span ;first char      //~v43hR~
//  fcmdsetfindhighlight(pfh,plh,0,0, 	//0:no locate,0:no linesrch//~v62aR~
    fcmdsetfindhighlight(pfh,plh,FCMDSFHOPT_NOMULTIREV,0, 	//0:no locate,0:no linesrch//~v62aI~
//  		offset,Pdest,0);			//no span                  //~v45tR~
    		offset,dest,0);			//no span                      //~v45tI~
//  if (fcmdcpymfwt(pfh))                                          //~v62bR~
//      return 8;                                                  //~v62bR~
	Soldkbdinpctr=Gkbdinpctr;	//save for double ESC chk          //~v45tI~
	return 0;                                                      //~v42hR~
}//ppsrchsub                                                       //~v42hI~
//**************************************************************** //~v42hI~
// ppsrchsub2                                                      //~v43hR~
//*rc   :                                                          //~v42hI~
//**************************************************************** //~v42hI~
int ppsrchsub2(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pppsrch,int Pppsrch2,int Pdest)//~v42hR~
{                                                                  //~v42hI~
	int offset,rc,srchlen,nestsw=0;                                //~v42hR~
    PULINEH plh;                                                   //~v42hI~
    UCHAR *pc,*pcd,*pcnest;                                        //~v42hR~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20I~
    UCHAR *pcd2;                                                   //~va2gI~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************                           //~v42hI~
	plh=*Ppplh;                                                    //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=PLHUTF8MODE(plh);                                   //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(plh);                                      //~va50I~
    handle=UGETPFH(plh)->UFHhandle;                                //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	offset=*Ppoffset;                                              //~v42hI~
	if (Pdest<0)                                                   //~v42hI~
	{                                                              //~v42hI~
    	Pdest=-Pdest;  		//0 or 1                               //~v42hI~
        for (;plh;(plh=UGETQPREV(plh))?offset=plh->ULHlen:0)       //~v42hI~
        {                                                          //~v42hI~
            if (plh->ULHtype!=ULHTDATA)                            //~v42hI~
                continue;                                          //~v42hI~
            if (Snxsw) 				//not excluded search          //~v42wI~
				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~v42wI~
	                continue;                                      //~v42wI~
            if (offset<Pdest-1)   //may not match                  //~v42hI~
                continue;                                          //~v42hI~
            for (;;)                                               //~v42hI~
            {                                                      //~v42hI~
                pc=plh->ULHdata;                                   //~v42hI~
                pcd=plh->ULHdbcs;                                  //~v42hI~
              for (;;)  //for search "/*"                          //~va2gI~
              {                                                    //~va2gI~
                if (Pppsrch2!=COMMENT_AST)     //nest chk require  //~v42hR~
//              	pcnest=umemrchr(pc,(UCHAR)Pppsrch,(UINT)offset);//nest chk//~v66tR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              	pcnest=UCVEBCUTF_umemrchr2_a2b(swebcfile,swutf8file,pc,pcd,Pppsrch,offset);//nest chk//~va50R~//~va79R~
                	pcnest=UCVEBCUTF_umemrchr2_a2b(swebcfile,swutf8file,handle,pc,pcd,Pppsrch,offset);//nest chk//~va79I~
    #else                                                          //~va50I~
                	pcnest=UTF_umemrchr2(swutf8file,pc,pcd,Pppsrch,offset);//nest chk//~va20I~//~va2gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                	pcnest=umemrchr2(pc,(UCHAR)Pppsrch,(UINT)offset);//nest chk//~v66tI~
#endif                                                             //~va20I~
                else                                               //~v42hI~
                	pcnest=0;                                      //~v42hR~
//              pc=umemrchr(pc,(UCHAR)Pppsrch2,(UINT)offset);      //~v66tR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              pc=UCVEBCUTF_umemrchr2_a2b(swebcfile,swutf8file,pc,pcd,Pppsrch2,offset);//~va50R~//~va79R~
                pc=UCVEBCUTF_umemrchr2_a2b(swebcfile,swutf8file,handle,pc,pcd,Pppsrch2,offset);//~va79I~
    #else                                                          //~va50I~
                pc=UTF_umemrchr2(swutf8file,pc,pcd,Pppsrch2,offset);//~va20I~//~va2gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                pc=umemrchr2(pc,(UCHAR)Pppsrch2,(UINT)offset);     //~v66tI~
#endif                                                             //~va20I~
                if (pcnest)                                        //~v42hI~
                	if (pc<pcnest)                                 //~v42hI~
                    {                                              //~v42hI~
                        pc=pcnest;                                 //~v42hI~
                        nestsw=1;                                  //~v42hI~
                    }                                              //~v42hI~
                if (pc)                                            //~v42hI~
                	if (Pppsrch2==COMMENT_AST)     //csr on "*/"   //~v42hR~
                    {                                              //~v42hI~
                		if (pc==plh->ULHdata                       //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	                ||  UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,*(pc-1),*XEUTF_PLHPC2PCD(plh,pc-1),COMMENT_SLASH))//~va50I~//~va79R~
    	                ||  UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,handle,*(pc-1),*XEUTF_PLHPC2PCD(plh,pc-1),COMMENT_SLASH))//~va79I~
    #else                                                          //~va50I~
    	                ||  UTF_ne(swutf8file,*(pc-1),*XEUTF_PLHPC2PCD(plh,pc-1),COMMENT_SLASH))//~va2gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va2gR~
                        ||  *(pc-1)!=COMMENT_SLASH)                //~v42hI~
#endif                                                             //~va2gI~
                        {                                          //~va2gI~
//                          offset=(ULONG)pc-(ULONG)(plh->ULHdata);//~va2gI~//~vafkR~
//                          offset=(ULPTR)pc-(ULPTR)(plh->ULHdata);//~vafkI~//~vb2DR~
                            offset=PTRDIFF(pc,plh->ULHdata);       //~vb2DI~
                            pc=plh->ULHdata;                       //~va2gI~
                            if (offset>1)	//serch length         //~va2gI~
                            	continue;                          //~va2gI~
                        	pc=0;		//not "/*"                 //~v42hI~
                        }                                          //~va2gI~
                    }                                              //~v42hI~
                break;                                             //~va2gI~
              }//         "/*" search                              //~va2gI~
                rc=0;                                              //~v42hI~
                if (!pc||pcd)   //not found or found under tab expanded//~v42hI~
                    break;                                         //~v42hI~
                rc=filechktabdbcs(plh);    //no tab or tab processed//~v42hI~
                if (rc==UALLOC_FAILED)                             //~v42hI~
                    return UALLOC_FAILED;                          //~v42hI~
                offset=plh->ULHlen; //after tab expand for nor csr line//~v42hI~
            }//for                                                 //~v42hI~
            if (pc) //found last                                   //~v42hI~
            {                                                      //~v42hI~
//              offset=(int)((ULONG)pc-(ULONG)plh->ULHdata);       //~v42hI~//~vafkR~
                offset=(int)((ULPTR)pc-(ULPTR)plh->ULHdata);       //~vafkI~
                if (Pppsrch2==COMMENT_AST)     //csr on "*/"       //~v42hR~
                    offset --;          //to "/" of "/*"           //~v42hI~
                break;                                             //~v42hI~
            }                                                      //~v42hI~
        }//all plh                                                 //~v42hI~
	}//prev                                                        //~v42hI~
	else			//not prev                                     //~v42hI~
	{				//next                                         //~v42hI~
        for (;plh;plh=UGETQNEXT(plh),offset=0)                     //~v42hI~
        {                                                          //~v42hI~
            if (plh->ULHtype!=ULHTDATA)                            //~v42hI~
                continue;                                          //~v42hI~
            if (Snxsw) 				//not excluded search          //~v42wI~
				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~v42wI~
	                continue;                                      //~v42wI~
            if (plh->ULHlen-offset<Pdest)   //may not match        //~v42hI~
                continue;                                          //~v42hI~
            for (;;)                                               //~v42hI~
            {                                                      //~v42hI~
                pc=plh->ULHdata;                                   //~v42hI~
                pcd=plh->ULHdbcs;                                  //~v42hI~
                pc+=offset;                                        //~v42hI~
                srchlen=plh->ULHlen-offset;                        //~v42hI~
              for (;;)  //for search "*/"                          //~va2gI~
              {                                                    //~va2gI~
                if (Pppsrch2!=COMMENT_AST)     //nest chk require  //~v42hR~
//              	pcnest=memchr(pc,Pppsrch,(UINT)srchlen);//nest chk//~v66tR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              	pcnest=UCVEBCUTF_umemchr2_a2b(swebcfile,swutf8file,pc,pcd+offset,Pppsrch,srchlen);//nest chk//~va50R~//~va79R~
                	pcnest=UCVEBCUTF_umemchr2_a2b(swebcfile,swutf8file,handle,pc,pcd+offset,Pppsrch,srchlen);//nest chk//~va79I~
    #else                                                          //~va50I~
                	pcnest=UTF_umemchr2(swutf8file,pc,pcd+offset,Pppsrch,srchlen);//nest chk//~va20I~//~va2gR~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                	pcnest=umemchr2(pc,(char)Pppsrch,(UINT)srchlen);//nest chk//~v66tR~
#endif                                                             //~va20I~
                else                                               //~v42hI~
                	pcnest=0;                                      //~v42hR~
//              pc=memchr(pc,Pppsrch2,(UINT)srchlen);              //~v66tR~
#ifdef UTF8UCS2                                                    //~va20I~
                pcd2=XEUTF_PC2PCD(plh->ULHdbcs,pc,plh->ULHdata);   //~va2gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              pc=UCVEBCUTF_umemchr2_a2b(swebcfile,swutf8file,pc,pcd2,Pppsrch2,srchlen);//~va50R~//~va79R~
                pc=UCVEBCUTF_umemchr2_a2b(swebcfile,swutf8file,handle,pc,pcd2,Pppsrch2,srchlen);//~va79I~
    #else                                                          //~va50I~
                pc=UTF_umemchr2(swutf8file,pc,pcd2,Pppsrch2,srchlen);//~va2gI~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                pc=umemchr2(pc,(char)Pppsrch2,(UINT)srchlen);      //~v66tR~
#endif                                                             //~va20I~
                if (pcnest)                                        //~v42hI~
					if (!pc || pc>pcnest)                          //~v42hI~
                	{                                              //~v42hI~
                        nestsw=1;                                  //~v42hI~
                        pc=pcnest;                                 //~v42hI~
                    }                                              //~v42hI~
                if (pc)                                            //~v42hI~
                	if (Pppsrch2==COMMENT_AST)     //csr on "/*"   //~v42hR~
                    {                                              //~v42hI~
                		if (pc==plh->ULHdata+plh->ULHlen-1         //~v42hI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	                ||  UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,*(pc+1),*XEUTF_PLHPC2PCD(plh,pc+1),COMMENT_SLASH))//~va50I~//~va79R~
    	                ||  UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,handle,*(pc+1),*XEUTF_PLHPC2PCD(plh,pc+1),COMMENT_SLASH))//~va79I~
    #else                                                          //~va50I~
    	                ||  UTF_ne(swutf8file,*(pc+1),*XEUTF_PLHPC2PCD(plh,pc+1),COMMENT_SLASH))//~va2gR~
    #endif                                                         //~va50I~
#else                                                              //~va2gI~
                        ||  *(pc+1)!=COMMENT_SLASH)                //~v42hI~
#endif                                                             //~va20I~//~va2gM~
                        {                                          //~va2gI~
                        	pc++;		//restart from next of "*" //~va2gI~
//                          srchlen=plh->ULHlen-((ULONG)pc-(ULONG)(plh->ULHdata));//~va2gI~//~vafkR~
//                          srchlen=plh->ULHlen-((ULPTR)pc-(ULPTR)(plh->ULHdata));//~vafkI~//~vb2DR~
                            srchlen=plh->ULHlen-PTRDIFF(pc,plh->ULHdata);//~vb2DI~
                            if (srchlen>1)                         //~va2gI~
                            	continue;                          //~va2gI~
                        	pc=0;		//not "*/"                 //~v42hI~
                        }                                          //~va2gI~
                    }                                              //~v42hI~
                break;                                             //~va2gI~
              } //"*/" search                                      //~va2gI~
                rc=0;                                              //~v42hI~
                if (!pc || pcd)                                    //~v42hI~
                    break;                                         //~v42hI~
                rc=filechktabdbcs(plh);                            //~v42hI~
                if (rc==UALLOC_FAILED)                             //~v42hI~
                    return UALLOC_FAILED;                          //~v42hI~
                offset=0;                                          //~v42hI~
            }//for                                                 //~v42hI~
            if (pc)                                                //~v42hI~
            {                                                      //~v42hI~
//              offset=(int)((ULONG)pc-(ULONG)plh->ULHdata);       //~v42hI~//~vafkR~
                offset=(int)((ULPTR)pc-(ULPTR)plh->ULHdata);       //~vafkI~
                break;                                             //~v42hI~
            }                                                      //~v42hI~
        }//all plh                                                 //~v42hI~
    }//prev/next                                                   //~v42hI~
    if (!plh)                                                      //~v42hI~
    	return 4;                                                  //~v42hI~
    *Ppplh=plh;                                                    //~v42hI~
    *Ppoffset=offset;                                              //~v42hI~
    return nestsw;                                                 //~v42hI~
}//ppsrchsub2                                                      //~v42hI~
//**************************************************************** //~v45tI~
// ppsrchmac                                                       //~v45tR~
// search for macro                                                //~v45tI~
//   # must be first char(preceding allowed is space and tab)      //~v45tI~
//parm1:pce                                                        //~v45tI~
//parm2:&plh                                                       //~v45tR~
//parm3:&offset found offset of #                                  //~v45tR~
//parm4:current line macrotype                                     //~v45tI~
//parm5:&dest(dest and reverse len)                                //~v45tR~
//*rc   :0:found,1:nest found,2:found but continue(else etc),      //~v45tR~
//       4:reached to eof                                          //~v45tI~
//**************************************************************** //~v45tI~
int ppsrchmac(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int *Ppmactype,int *Ppdest)//~v45tR~
{                                                                  //~v45tI~
//  int offset,rc,dest,nestsw=0,mactype,revlen;                    //~v45tR~//~vaf9R~
    int offset=0,rc,dest,nestsw=0,mactype,revlen=0;                //~vaf9I~
    PULINEH plh;                                                   //~v45tI~
//**************************************                           //~v45tI~
	plh=*Ppplh;                                                    //~v45tI~
    dest=*Ppdest;                                                  //~v45tI~
    mactype=*Ppmactype;                                            //~v45tI~
	if (dest<0)                                                    //~v45tI~
	{                                                              //~v45tI~
        for (;plh=UGETQPREV(plh),plh;)                             //~v45tR~
        {                                                          //~v45tI~
            if (plh->ULHtype!=ULHTDATA)                            //~v45tI~
                continue;                                          //~v45tI~
            if (Snxsw) 				//not excluded search          //~v45tI~
				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~v45tI~
	                continue;                                      //~v45tI~
            if (ppsrchmacrochk(0,plh,&offset,&revlen,&mactype,0,0))//next line search//~v45tR~
                continue;                                          //~v45tI~
//macro line found                                                 //~v45tI~
            switch(*Ppmactype)                                     //~v45tR~
            {                                                      //~v45tI~
            case  MAC_ELSE:         //-->else                      //~v45tI~
                switch(mactype)                                    //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                    nestsw=4;       //else-->else;err              //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=1;       //endif-->else;nested          //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
//                  nestsw=0;       //elif-->else;found cont       //~v47fR~
                    nestsw=2;       //elif-->else;found cont       //~v47fI~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=0;       //if -->else;found             //~v45tI~
                }                                                  //~v45tI~
                break;                                             //~v45tI~
            case  MAC_ENDIF:        //-->endif                     //~v45tI~
                switch(mactype)                                    //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                    nestsw=2;       //else-->endif;cont found      //~v45tR~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=1;       //endif-->endif;nested         //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
//                  nestsw=0;       //elif-->endif;found           //~v47fR~
                    nestsw=2;       //elif-->endif;cont found      //~v47fI~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=0;       //if-->endif;found             //~v45tI~
                }                                                  //~v45tI~
                break;                                             //~v45tI~
            default:				//-->elif                      //~v45tI~
                switch(mactype)                                    //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                  if (*Ppmactype==MAC_ELIF)                        //~v47eI~
                    nestsw=4;       //else-->elif;err              //~v45tI~
                  else                                             //~v47eI~
                    nestsw=2;       //else-->if                    //~v47eI~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=1;       //endif-->elif;nested          //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
                    nestsw=2;       //elif-->elif;cont found       //~v45tR~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=0;       //if-->elif;found              //~v45tI~
                }                                                  //~v45tI~
                break;                                             //~v45tI~
            }//by Pmactype                                         //~v45tR~
            break;                                                 //~v45tI~
        }//all plh                                                 //~v45tI~
	}//prev                                                        //~v45tI~
	else			//not prev                                     //~v45tI~
	{				//next                                         //~v45tI~
        for (;plh=UGETQNEXT(plh),plh;)                             //~v45tI~
        {                                                          //~v45tI~
            if (plh->ULHtype!=ULHTDATA)                            //~v45tI~
                continue;                                          //~v45tI~
            if (Snxsw) 				//not excluded search          //~v45tI~
				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~v45tI~
	                continue;                                      //~v45tI~
            if (ppsrchmacrochk(0,plh,&offset,&revlen,&mactype,0,0))//next line search//~v45tR~
                continue;                                          //~v45tI~
            switch(*Ppmactype)                                     //~v45tI~
            {                                                      //~v45tI~
            case  MAC_ELSE:         //else-->                      //~v45tR~
                switch(mactype)                                    //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                    nestsw=4;       //else-->else;err              //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=0;       //else-->endif;found           //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
                    nestsw=4;       //else-->elif;err              //~v45tI~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=1;       //else-->if;nested             //~v45tI~
                }                                                  //~v45tI~
                break;                                             //~v45tI~
            case  MAC_ELIF: 		//elif-->                      //~v45tR~
                switch(mactype)                                    //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                    nestsw=2;       //elif-->else;cont found       //~v45tR~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=0;       //elif-->endif;found           //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
                    nestsw=2;       //elif-->elif;cont found       //~v45tR~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=1;       //elif-->if;nested             //~v45tI~
                }                                                  //~v45tI~
                break;                                             //~v45tI~
            default:            //if,ifdef,ifndef                  //~v45tI~
                switch(mactype)     //if-->                        //~v45tI~
                {                                                  //~v45tI~
                case  MAC_ELSE:                                    //~v45tI~
                    nestsw=2;       //if-->else;cont found         //~v45tR~
                    break;                                         //~v45tI~
                case  MAC_ENDIF:                                   //~v45tI~
                    nestsw=0;       //if-->endif;found             //~v45tI~
                    break;                                         //~v45tI~
                case  MAC_ELIF:                                    //~v45tI~
                    nestsw=2;       //if-->elif;cont found         //~v45tR~
                    break;                                         //~v45tI~
                default:            //if,ifdef,ifndef              //~v45tI~
                    nestsw=1;       //if-->if;nested               //~v45tI~
                }                                                  //~v45tI~
            }//by Pmactype                                         //~v45tR~
            break;                                                 //~v45tI~
        }//all plh                                                 //~v45tI~
    }//prev/next                                                   //~v45tI~
    if (!plh)                                                      //~v45tI~
    	return 4;                                                  //~v45tI~
    if (!plh->ULHdbcs)                                             //~v45tI~
//      if (!nestsw)        //found                                //~v47gR~
        if (!nestsw||nestsw==2)        //found or cont             //~v47gR~
        {                                                          //~v45tI~
            rc=filechktabdbcs(plh); //expand tab                   //~v45tI~
            if (rc==UALLOC_FAILED)                                 //~v45tI~
                return UALLOC_FAILED;                              //~v45tI~
            ppsrchmacrochk(0,plh,&offset,&revlen,&mactype,0,0);//next line search//~v45tR~
        }                                                          //~v45tI~
    *Ppplh=plh;                                                    //~v45tI~
    *Ppoffset=offset;                                              //~v45tI~
    *Ppmactype=mactype;                                            //~v45tI~
    if (dest>0)                                                    //~v45tR~
	    *Ppdest=revlen;                                            //~v45tI~
    else                                                           //~v45tI~
	    *Ppdest=-revlen;                                           //~v45tI~
    return nestsw;                                                 //~v45tI~
}//ppsrchmac                                                       //~v45tI~
//**************************************************************** //~v45tI~
// ppsrchmacrochk                                                  //~v45tI~
// chk macro statement                                             //~v45tI~
//   # must be first char(preceding allowed is space and tab)      //~v45tI~
//parm1:initial sw; 1:initial chk of csr pos, 0:next line macro search//~v45tI~
//parm2:plh                                                        //~v45tI~
//parm3:&offset of #                                               //~v45tI~
//parm4:&reverse len;until next space                              //~v45tI~
//parm5:&macro type                                                //~v45tI~
//parm6:&dest,set at init case                                     //~v45tR~
//parm7:original dest by mac type                                  //~v45tI~
//*rc   :1:not macro line,4:non space before macro or invalid macro//~v45tI~
//**************************************************************** //~v45tI~
int ppsrchmacrochk(int Pinitsw,PULINEH Pplh,int *Ppoffset,int *Pprevlen,//~v45tR~
					int *Ppmactype,int *Ppdest,int *Pporgdest)     //~v45tR~
{                                                                  //~v45tI~
static int  Sprevdest=0;                                           //~v45tI~
	int ii,maclen=0,rlen,plhlen,offset,skiplen,dest;                 //~v45tR~//~vaf9R~
    char *pdata0,*pdata;                                           //~v45tI~
#ifdef UTF8UCS2                                                    //~va20I~
    char *pdbcs,*pdbcs0;                                           //~va20R~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************                           //~v45tI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
    pdbcs=pdbcs0=Pplh->ULHdbcs;                                    //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	offset=*Ppoffset;                                              //~v45tI~
    pdata=pdata0=Pplh->ULHdata;                                    //~v45tI~
    plhlen=Pplh->ULHlen;                                           //~v45tI~
//chk space before csr                                             //~v45tI~
    if (Pinitsw)                                                   //~v45tI~
    {                                                              //~v45tI~
		if (offset)			//csr pos is #                         //~v45tR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    		if ((int)UCVEBCUTF_umemspnc_spacetab(swebcfile,swutf8file,pdata,pdbcs,offset)!=offset)//~va50I~
    #else                                                          //~va50I~
    		if ((int)UTF_ustrnspn(swutf8file,pdata,pdbcs," \t",offset)!=offset)//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
    		if ((int)ustrnspn(pdata," \t",(UINT)offset)!=offset)   //~v45tR~
#endif                                                             //~va20I~
        	{                                                      //~v45tI~
        		uerrmsg("Non-space char before",                   //~v45tI~
            			"前に空白以外の文字");                     //~v45tI~
            	return 4;                                          //~v45tI~
            }                                                      //~v45tI~
        pdata+=offset;                                             //~v45tR~
    }                                                              //~v45tI~
    else                                                           //~v45tI~
    {                                                              //~v45tI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	    pdata+=UCVEBCUTF_umemspnc_spacetab(swebcfile,swutf8file,pdata,pdbcs,plhlen);//~va50I~
    #else                                                          //~va50I~
	    pdata+=UTF_ustrnspn(swutf8file,pdata,pdbcs," \t",plhlen);  //~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~o
	    pdata+=ustrnspn(pdata," \t",(UINT)plhlen);                 //~v45tI~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (*pdata!=UCVEBC_CONST(swebcfile,MACRO_ID))              //~va50I~
#else                                                              //~va50I~
        if (*pdata!=MACRO_ID)                                      //~v45tI~
#endif                                                             //~va50I~
        	return 1;		//bypass line                          //~v45tI~
    }                                                              //~v45tI~
//chk macro stmt                                                   //~v45tI~
//  *Ppoffset=(int)((ULONG)pdata-(ULONG)pdata0);	//offset of #  //~v47hR~//~vafkR~
    *Ppoffset=(int)((ULPTR)pdata-(ULPTR)pdata0);	//offset of #  //~vafkI~
    pdata++;	//next of #                                        //~v45tI~
    rlen=plhlen-*Ppoffset-1;            //len after #              //~v45tI~
#ifdef UTF8UCS2                                                    //~va20I~
    pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);	//offset of #      //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    skiplen=(int)UCVEBCUTF_umemspnc_spacetab(swebcfile,swutf8file,pdata,pdbcs,rlen);//~va50I~
  #else                                                            //~va50I~
    skiplen=(int)UTF_ustrnspn(swutf8file,pdata,pdbcs," \t",rlen);  //~va20I~
  #endif                                                           //~va50I~
#else                                                              //~va20I~
    skiplen=(int)ustrnspn(pdata," \t",(UINT)rlen);                 //~v47hR~
#endif                                                             //~va20I~
    pdata+=skiplen;                                                //~v45tI~
    rlen-=skiplen;                                                 //~v45tI~
#ifdef UTF8UCS2                                                    //~va20I~
    pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);	//offset of #      //~va20R~
#endif                                                             //~va20I~
    for (ii=0;ii<MACTR;ii++)                                       //~v45tI~
    {                                                              //~v45tI~
        maclen=Smaclen[ii];                                        //~v45tI~
    	if (rlen>=maclen                                           //~v45tR~
#ifdef UTF8UCS2                                                    //~va20I~
  	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	&& !XESUB_EBCUTF8_memcmpeq_bandl(swebcfile,swutf8file,pdata,pdbcs,Smacname[ii],0/*pdbcs2*/,maclen)//~va50R~//~va79R~
    	&& !XESUB_EBCUTF8_memcmpeq_bandl(swebcfile,swutf8file,handle,pdata,pdbcs,Smacname[ii],0/*pdbcs2*/,maclen)//~va79I~
    #else                                                          //~va50I~
		&& !XESUB_memcmpeq(swutf8file,pdata,pdbcs,Smacname[ii],0/*pdbcs2*/,maclen)//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
		&& !memcmp(Smacname[ii],pdata,(UINT)maclen)                //~v45tI~
#endif                                                             //~va20I~
//  	&& (rlen==maclen||*(pdata+maclen)==' '||*(pdata+maclen)=='\t'))//~v47hR~
    	&& (rlen==maclen||                                         //~v47hI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                 (UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,*(pdata+maclen),*(pdbcs+maclen),'_')//~va50R~//~va79R~
                   (UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,handle,*(pdata+maclen),*(pdbcs+maclen),'_')//~va79I~
//                  && !UCVEBCUTF_isalnum_b2a(swebcfile,swutf8file,*(pdata+maclen),*(pdbcs+maclen))//~va50R~//~va79R~
                    && !UCVEBCUTF_isalnum_b2a(swebcfile,swutf8file,handle,*(pdata+maclen),*(pdbcs+maclen))//~va79I~
                   )                                               //~va50I~
           )                                                       //~va50I~
       )                                                           //~va50I~
#else                                                              //~va50I~
                   (*(pdata+maclen)!='_' && !isalnum(*(pdata+maclen)))))//~v47hR~
#endif                                                             //~va50I~
        	break;                                                 //~v45tI~
    }                                                              //~v45tI~
    if (ii>=MACTR)	//notfound                                     //~v45tR~
    {                                                              //~v62fI~
    	if (Pinitsw)                                               //~v45tI~
        {                                                          //~v45tI~
        	uerrmsg("Not a valid macro stmt to be searched",       //~v45tI~
                "探索対象外のマクロ文");                           //~v45tI~
        	return 4;                                              //~v45tI~
        }                                                          //~v45tI~
        else                                                       //~v45tI~
        	return 1;                                              //~v45tI~
    }                                                              //~v62fR~
    *Ppmactype=ii;		//macro type                               //~v45tI~
    if (Pinitsw)                                                   //~v45tR~
    {                                                              //~v45tI~
		dest=Smacdest[ii];                                         //~v45tI~
        if (Pporgdest)                                             //~v45tI~
        	*Pporgdest=dest;                                       //~v45tI~
        if (!dest)                                                 //~v45tI~
        {                                                          //~v45tI~
		    dest=Sprevdest;                                        //~v45tR~
            if (!dest)                                             //~v45tI~
                dest=1;     //at first                             //~v45tI~
        }                                                          //~v45tI~
        if (Ppdest)                                                //~v45tI~
        	*Ppdest=dest;                                          //~v45tI~
		Sprevdest=dest;                                            //~v45tI~
    }                                                              //~v45tI~
    if (Pprevlen)                                                  //~v45tI~
//    	*Pprevlen=(int)((ULONG)pdata-(ULONG)pdata0+maclen-*Ppoffset);//~v47hR~//~vafkR~
//    	*Pprevlen=(int)((ULPTR)pdata-(ULPTR)pdata0+maclen-*Ppoffset);//~vafkI~//~vb2DR~
      	*Pprevlen=PTRDIFF(pdata,pdata0)+maclen-*Ppoffset;          //~vb2DI~
	return 0;                                                      //~v45tI~
}//ppsrchmacrochk                                                  //~v45tI~
//**************************************************************** //~v498I~
// get label plh                                                   //~v498I~
//* parm1:pcw                                                      //~v498I~
//* parm2:pfh                                                      //~v498I~
//* parm3:output start plh                                         //~v498I~
//* parm4:output end   plh;0 if no label specified                 //~v498I~
//* parm5:option;1:set endplh to next of label plh                 //~v498I~
//*rc   :0                                                         //~v498I~
//**************************************************************** //~v498I~
int fcmdgetabplh(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Pplhs,PULINEH *Pplhe,int Popt)//~v498I~
{                                                                  //~v498I~
    int ii,opdno;                                                  //~v498I~
	UCHAR *pc;                                                     //~v498I~
    int lblcnt=0;                                                  //~v498I~
    UCHAR labelt[2][ULHLINENOSZ+1];                                //~v498I~
    PULINEH plht[2];			//output of lcmdgetabplh           //~v498I~
    int rc;                                                        //~v498I~
//*********************************                                //~v498I~
	*Pplhe=0;						//for the case no label        //~v498R~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v498I~
    pc=Ppcw->UCWopdpot;                                            //~v498I~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v498I~
	{                                                              //~v498I~
      	if (*pc!=ULCCMDLABEL)    //start by '.'                    //~v498I~
        	continue;                                              //~v498I~
        if (lblcnt>=2)                                             //~v498I~
            return fcmdlabelerr(pc);                               //~v498I~
        strncpy(labelt[lblcnt],pc,ULHLINENOSZ);                    //~v498I~
        labelt[lblcnt][ULHLINENOSZ]=0;                             //~v498I~
        lblcnt++;                                                  //~v498I~
	}//loop by operand no                                          //~v498I~
	if (!lblcnt)	//odd number                                   //~v498I~
    	return 0;                                                  //~v498I~
    if (lblcnt!=2)                                                 //~v498R~
    	return fcmdlabelerr("Need From/To");                       //~v498I~
    if (rc=fcmdgetlabelrange(Ppfh,lblcnt,labelt,plht,Popt),rc)	//1:get next of label//~v498R~
    	return rc;                                                 //~v498I~
    *Pplhs=plht[0];  //start plh                                   //~v498I~
    *Pplhe=plht[1];  //endplh(o next of endplh)                    //~v498I~
	return 0;                                                      //~v498I~
}//fcmdgetabplh                                                    //~v498I~
//**************************************************************** //~v62dI~
//  get 2nd scr pfh for matching                                   //~v62dI~
//*ret :pfh or 0 if err                                            //~v62dI~
//**************************************************************** //~v62dI~
//PUFILEH fcmdget2ndpfh(PUCLIENTWE Ppcw)                           //~v62fR~
PUFILEH fcmdget2ndpfh(PUCLIENTWE Ppcw,char *Pparm)                 //~v62fI~
{                                                                  //~v62dI~
	PUCLIENTWE pcw;                                                //~v62dI~
	PUFILEH    pfh;                                                //~v62dI~
#ifdef UTF8UCS2                                                    //~va20I~
	PUFILEH    pfh1;                                               //~va20I~
#endif                                                             //~va20I~
//*********************************                                //~v62dI~
    pcw=scrgetcw(-1);  //another screen                            //~v62dI~
    if (!pcw)                                                      //~v62dI~
    {                                                              //~v62dI~
//      errscrnotsplited();                                        //~v62fR~
        errscrnotsplited(Pparm);                                   //~v62fI~
        return 0;                                                  //~v62dI~
    }                                                              //~v62dI~
    if (pcw->UCWtype!=UCWTFILE)                                    //~v62dI~
    {                                                              //~v62dI~
//      err2ndscrisnotfile();                                      //~v62fR~
        err2ndscrisnotfile(Pparm);                                 //~v62fI~
        return 0;                                                  //~v62dI~
    }                                                              //~v62dI~
    pfh=UGETPFHFROMPCW(pcw);                                       //~v62dI~
#ifdef UTF8UCS2                                                    //~va20I~
    pfh1=UGETPFHFROMPCW(Ppcw);                                     //~va20I~
	if (pfh && pfh1)                                               //~va20I~
    	if (FILEUTF8MODE(pfh1)!=FILEUTF8MODE(pfh))                 //~va20I~
    	{                                                          //~va20I~
			errutf8andnonutf8("Matching",4);                       //~va20I~
        	pfh=0;                                                 //~va20I~
    	}                                                          //~va20I~
#endif                                                             //~va20I~
    return pfh;                                                    //~v62dI~
}//fcmget2ndpfh                                                    //~v62dI~
#ifdef UTF8UCS2                                                    //~va20I~
//*******************************************************          //~va20I~
//* search word translation according search file type                  //~va20I~//~va79R~
//rc 4:err                                                         //~va20I~
//*******************************************************          //~va20I~
int fcmdcvsrchword(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdbcs,UCHAR **Pperrmsgsrchword)//~va20R~
{                                                                  //~va20I~
	PUFILEH pfh;                                                   //~va20I~
    int swutf8file,rc=0,opt,rc2;                                   //~va20R~
    UCHAR *pemsrchword;                                            //~va20R~
    UCHAR wkct[sizeof(Sswlc)];                                     //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,u8len;                                           //~va50R~
    int handle;                                                    //~va79I~
    UCHAR *pwu8;                                                   //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    UCHAR *pwebcdata,*pwebcdbcs,*pdbcs;                            //~va7sR~
    int ebclen;                                                    //~va7sI~
//***********************                                          //~va20I~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~va20M~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
    handle=pfh->UFHhandle;                                         //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Popt & SS_WORD_REUSE)  //setup Ssrchword for reuse case    //~va20R~
    {                                                              //~va20I~
        if (!(Ssrchstat & SS_RESTART))                             //~va20I~
        {                                                          //~va20I~
            Ssrchstat|=SS_RESTART;                                 //~va20I~
            if (Sothopt & SEARCH_UCS2WORD)   //Ssrchword is saved as utf8str on ini file//~va20R~
            {  //set dd and lc                                     //~va20R~
                Sswlenu8=Ssrchwordlen;                             //~va20R~
                memcpy(Sswu8,Ssrchword,(UINT)Sswlenu8);            //~va20R~
                rc2=xeutfcvf2ldd(0,Ppcw,Ssrchword,Ssrchwordlen,    //~va20R~
                    Sswdd,Sswdbcs,sizeof(Sswdd),&Sswlendd,         //~va20R~
                    Sswlc,wkct,sizeof(Sswlc),&Sswlenlc);           //~va20R~
                if (rc2>1)                                         //~va20I~
                    rc=4;                                          //~va20R~
                else                                               //~va20R~
                {                                                  //~va20R~
                	if (rc2==1)	//f2l trans err                    //~va20I~
                    	Sswlenlc=0;                                //~va20I~
                    Ssrchwordlen=Sswlendd;                         //~va20R~
                    memcpy(Ssrchword,Sswdd,(UINT)Ssrchwordlen);    //~va20R~
                }                                                  //~va20R~
            }                                                      //~va20R~
            else                                                   //~va20R~
            if (Sothopt & SEARCH_EBCWORD)   //Ssrchword is saved as utf8str on ini file//~va7sI~
            {  //recover ebc str                                   //~va7sI~
                Sswlenu8=Ssrchwordlen;                             //~va7sI~
                memcpy(Sswu8,Ssrchword,(UINT)Sswlenu8);            //~va7sI~
                opt=XEEBCO_DROPSOSI;    //drop boundary SOSI       //~va7sR~
			    rc2=xeebc_f2bsetdbcs(opt,handle,Sswu8,Sswlenu8,&pwebcdata,&pwebcdbcs,&ebclen);//~va7sR~
                if (rc2>1)                                         //~va7sI~
                    rc=4;                                          //~va7sI~
                else                                               //~va7sI~
                {                                                  //~va7sI~
                    ebclen=min(ebclen,MAXCOLUMN-1);                //~va7sI~
                    Ssrchwordlen=ebclen;                           //~va7sI~
                    UmemcpyZ(Ssrchword,pwebcdata,(UINT)ebclen);    //~va7sR~
                    memcpy(Sswdbcs,pwebcdbcs,(UINT)ebclen);        //~va7sI~
                }                                                  //~va7sI~
            }                                                      //~va7sI~
            else                                                   //~va7sI~
            {  //set dd image                                      //~va20R~
                Sswlenlc=Ssrchwordlen;                             //~va20R~
                UmemcpyZ(Sswlc,Ssrchword,(UINT)Sswlenlc);          //~va20R~
                if (xeutfcvl2fdd(0,Sswlc,Sswlenlc,                 //~va20R~
                    Sswu8,sizeof(Sswu8),&Sswlenu8,                 //~va20R~
                    Sswdd,Sswdbcs,sizeof(Sswdd),&Sswlendd)         //~va20R~
                )                                                  //~va20R~
                    rc=4;                                          //~va20R~
            }                                                      //~va20R~
            if (rc)                                                //~va20R~
                uerrmsg("Searchword recovery failed, re-specify",0);//~va20R~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else   //new getword                                           //~va20R~
    {                                                              //~va20I~
        Ssrchstat|=SS_RESTART;  //no need in the same session      //~va20R~
        if (swutf8file)     //search word is ddstr                 //~va20R~
        {//save lc/u8 image                                        //~va20R~
            Sothopt|=SEARCH_UCS2WORD;   //word selected from utf8 file//~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            Sothopt&=~SEARCH_EBCWORD;   //word selected from utf8 file//~va50I~
#endif                                                             //~va50I~
            Sswlendd=Ssrchwordlen;                                 //~va20R~
            memcpy(Sswdd,Ssrchword,(UINT)Sswlendd);                //~va20R~
            memcpy(Sswdbcs,Pdbcs,(UINT)Sswlendd);                  //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            opt=0;  //no need set errmsg because xeerrmsg support codetbl//~va50I~
#else                                                              //~va50I~
            opt=XEUTFDD2FLO_U8ERRMSG;                              //~va20R~
#endif                                                             //~va50I~
            if (xeutfcvdd2fl(opt,Ppcw,Sswdd,Sswdbcs,Sswlendd,      //~va20R~
                    Sswu8,sizeof(Sswu8),&Sswlenu8,                 //~va20R~
                    Sswlc,0/*outdbcs*/,wkct,sizeof(Sswlc),&Sswlenlc)            //~va20R~//~va2gR~
            )                                                      //~va20R~
            //*rc=1:err rep by '.'                                 //~vafkI~
                Sswlenlc=0;                                        //~va20R~
            UstrncpyZ(Gsrchwordforini,Sswu8,sizeof(Gsrchwordforini));//~va20R~
            if (Sswlenu8>=sizeof(Gsrchwordforini))                 //~va20R~
                rc=4;                                              //~va20R~
        }                                                          //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        else                                                       //~va50I~
        if (swebcfile)     //search word is ebc str                //~va50I~
        {//save lc/u8 image                                        //~va50I~
            Sothopt|=SEARCH_EBCWORD;   //word selected from utf8 file//~va50I~
            Sothopt&=~SEARCH_UCS2WORD;   //word selected from utf8 file//~va50I~
            opt=XEEBCO_B2F|XEEBCO_SOSI2SPACE;                      //~va50R~
            opt|=XEEBCO_CHKDBCSTB;  //cv b2f using so/si anddbcstb //~va7sI~
            pdbcs=Pdbcs;	//input to ucvebc3_b2dd	               //~va7sI~
//          if (xeebc_b2msetdbcs(opt,Ssrchword,Pdbcs,Ssrchwordlen,&pwu8,0/*outdbcs*/,&u8len))//~va50R~//~va79R~
            if (xeebc_b2msetdbcs(opt,handle,Ssrchword,Pdbcs,Ssrchwordlen,&pwu8,&pdbcs,&u8len))//~va7sR~
                Sswlenlc=0;                                        //~va50I~
//          Sswlenu8=min(u8len,sizeof(Sswu8)-1);                   //~va50R~//~vb2DR~
            Sswlenu8=min(u8len,(int)sizeof(Sswu8)-1);              //~vb2DI~
//          UmemcpyZ(Sswu8,pwu8,Sswlenu8);                         //~va50R~//~vb2DR~
            UmemcpyZ(Sswu8,pwu8,(size_t)Sswlenu8);                 //~vb2DI~
            memcpy(Sswdbcs,Pdbcs,(UINT)Ssrchwordlen);              //~va50I~
            UstrncpyZ(Gsrchwordforini,Sswu8,sizeof(Gsrchwordforini));//~va50I~
            if (Sswlenu8>=sizeof(Gsrchwordforini))                 //~va50I~
                rc=4;                                              //~va50I~
        }                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        else    //  getword from localefile                        //~va20R~
        {//save dd/u8 image                                        //~va20R~
            Sothopt&=~SEARCH_UCS2WORD;   //word selected from utf8 file//~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            Sothopt&=~SEARCH_EBCWORD;   //word selected from utf8 file//~va50I~
#endif                                                             //~va50I~
            Sswlenlc=Ssrchwordlen;                                 //~va20R~
            UmemcpyZ(Sswlc,Ssrchword,(UINT)Sswlenlc);              //~va20R~
            if (xeutfcvl2fdd(0,Sswlc,Sswlenlc,                     //~va20R~
                    Sswu8,sizeof(Sswu8),&Sswlenu8,                 //~va20R~
                    Sswdd,Sswdbcs,sizeof(Sswdd),&Sswlendd)         //~va20R~
            )                                                      //~va20R~
                Sswlendd=0;                                        //~va20R~
            UstrncpyZ(Gsrchwordforini,Sswlc,sizeof(Gsrchwordforini));//~va20R~
            if (Sswlenlc>=sizeof(Gsrchwordforini))                 //~va20R~
                rc=4;                                              //~va20R~
        }                                                          //~va20R~
        if (rc)                                                    //~va20R~
//          uerrmsg("Too long searchword",0);                      //~va20R~//~va5aR~
        	uerrmsg("Too long search word(Delimiter not found)",   //~va5aI~
                "探索文字列が長すぎます。(分離文字が見つかりません)");//~va5aI~
    }                                                              //~va20I~
    if (swutf8file) //search on utf8 file                          //~va20I~
    {                                                              //~va20I~
    	Ssrchwordlen=Sswlendd;                                     //~va20I~
        memcpy(Ssrchword,Sswdd,(UINT)Ssrchwordlen);                //~va20I~
      if (Sothopt & SEARCH_UCS2WORD)   //Ssrchword is saved as utf8str on ini file//+vbq6I~
        pemsrchword=Sswu8;                                         //~va20I~
      else                                                         //+vbq6I~
        pemsrchword=Sswlc;                                         //+vbq6I~
    }                                                              //~va20I~
    else                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (swebcfile)     //search word is ubc str                    //~va50I~
    {//save lc/u8 image                                            //~va50I~
        pemsrchword=Sswu8;                                         //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif                                                             //~va50I~
    {                                                              //~va20I~
    	if (!Sswlenlc)                                             //~va20I~
        {                                                          //~va20I~
            uerrmsg("translation failed from utf8 to locale code",0);//~va20I~
            rc=4;                                                  //~va20I~
        }                                                          //~va20I~
    	Ssrchwordlen=Sswlenlc;                                     //~va20I~
        UmemcpyZ(Ssrchword,Sswlc,(UINT)Ssrchwordlen);              //~va20R~
        pemsrchword=Sswlc;                                         //~va20I~
    }                                                              //~va20I~
    if (Pperrmsgsrchword)                                          //~va20R~
    	*Pperrmsgsrchword=pemsrchword;                             //~va20R~
    return rc;                                                     //~va20R~
}//fcmdcvsrchword                                                  //~va20I~
#endif                                                             //~va20I~
//*******************************************************          //~v77EI~
//* search word on cursor pos                                      //~v77ER~
//*******************************************************          //~v77EI~
int fcmdsrchword(PUCLIENTWE Ppcw,int Pswcase,int Pdest)            //~v77EI~
{                                                                  //~v77EI~
static int Ssrchwordkbdctr=-1;                                     //~v77ER~
static int Sfindstatus=0;                                          //~v77EI~
static USHORT Sfuncid=0;                                           //~v77ER~
	int rc,offs,len,dest,rc2=0,researchsw=0,contsrchsw=0;          //~v77MR~
    PULINEH plh;                                                   //~v77EI~
    PUFILEH pfh;                                                   //~v77EI~
//  char delm[4];                                                  //~v77EI~//~v7avR~
//  char delm[4+FGW_DELM_MAXLEN*2];                                //~v7avI~//~va7kR~
    char delm[FGW_DELM_STRUCSZ];                                   //~va7kI~
    PFUNCTBL pft;                                                  //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
	UCHAR *pemsrchword=Ssrchword;                                  //~va20R~
#endif                                                             //~va20I~
//  int optebc,handle=0;                                           //~va79R~//~vafcR~
    int optebc=0,handle=0;                                         //~vafcI~
//***********************                                          //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
    if (Ssrchwordlen)  //1st time after session restart            //~va20R~
    {                                                              //~va20I~
		if (fcmdcvsrchword(SS_WORD_REUSE,Ppcw,0/*pdbcs*/,&pemsrchword))//~va20R~
        	return 4;                                              //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
	Ssrchstat&=~SS_WORD_REUSE;                                     //~v77MI~
    pft=Ppcw->UCWpfunct;                                           //~v77EI~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~va79I~
    memset(delm,0,sizeof(delm));                                   //~va7kI~
    if (Gkbdinpctr!=Ssrchwordkbdctr+1)	//not continued            //~v77EI~
    {                                                              //~v77EI~
    	Sfindstatus=0;                                             //~v77EI~
    	switch(fcmdsrchwordopdchk(Ppcw,delm))                      //~v77ER~
        {                                                          //~v77EI~
        case 0:                                                    //~v77EI~
        	break;                                                 //~v77EI~
    	case 1:      //operand ignored                             //~v77EI~
    		rc2=1;                                                 //~v77EI~
        	break;                                                 //~v77EI~
        case 2:     //help                                         //~v77EI~
        	return 0;                                              //~v77ER~
        default:                                                   //~v77EI~
        	return 4;                                              //~v77EI~
        }                                                          //~v77EI~
    	if (rc=fcmdgetword(Ppcw,&plh,&offs,&len,sizeof(Ssrchword)-1,delm),rc)//~v77MR~//~vbp3R~
    		return rc;                                             //~v77ER~
        Ssrchwordlen=len;                                          //~v77EI~
        Ssrchwordoffs=offs;                                        //~v77EI~
        Ssrchwordplh=plh;                                          //~v77EI~
	  if (Ssrchstat & SS_WORD_REUSE)                               //~v77MI~
      {                                                            //~va23I~
        if (Ppcw->UCWopdno)                                        //~va23I~
        {                                                          //~va23I~
            uerrmsg("set cursor around the word",0);               //~va23I~
            return 4;                                              //~va23I~
        }                                                          //~va23I~
        contsrchsw=1;                                              //~v77MI~
      }                                                            //~va23I~
      else                                                         //~v77MI~
      {                                                            //~va20I~
    	UmemcpyZ(Ssrchword,plh->ULHdata+offs,(UINT)len);           //~v77ER~
#ifdef UTF8UCS2                                                    //~va20I~
		if (fcmdcvsrchword(0,Ppcw,plh->ULHdbcs+offs,&pemsrchword)>=4)//~va20R~
        	return 4;                                              //~va20I~
#endif                                                             //~va20I~
      }                                                            //~va20I~
    }                                                              //~v77EI~
    else                                                           //~v77EI~
    {                                                              //~v77EI~
    	len=Ssrchwordlen;                                          //~v77ER~
    	if (Sfindstatus<0 && Sfuncid==pft->FTfuncid)	//same functionid and prevously not found//~v77EI~
        {                                                          //~v77EI~
//      	pfh=UGETPFHFROMPCW(Ppcw);                              //~v77EI~//~va79R~
        	if (Sfuncid==FUNCID_FINDWORDF||Sfuncid==FUNCID_IFINDWORDF)	//forward search//~v77EI~
            {                     //research from top              //~v77EI~
        		offs=0;                                            //~v77EI~
            	plh=UGETQTOP(&pfh->UFHlineque);//search from first //~v77EI~
   	         	researchsw=1;	//from top                         //~v77EI~
            }                                                      //~v77EI~
            else                  //research from last             //~v77EI~
            {                                                      //~v77EI~
            	plh=UGETQEND(&pfh->UFHlineque);//search from first //~v77EI~
        		offs=plh->ULHlen;                                  //~v77EI~
   	         	researchsw=-1;   //from backend                    //~v77EI~
            }                                                      //~v77EI~
        }                                                          //~v77EI~
        else                                                       //~v77EI~
        {                                                          //~v77EI~
        	offs=Ssrchwordoffs;                                    //~v77ER~
        	plh=Ssrchwordplh;                                      //~v77ER~
        }                                                          //~v77EI~
    }                                                              //~v77EI~
    Sfuncid=pft->FTfuncid;                                         //~v77EI~
    Ssrchwordkbdctr=Gkbdinpctr;                                    //~v77EI~
    if (Pdest>0)   //forward                                       //~v77ER~
        dest=len;                                                  //~v77EI~
    else                                                           //~v77EI~
    	dest=-len;                                                 //~v77EI~
    if (pfh)                                                       //~va79I~
    {                                                              //~va79I~
        handle=pfh->UFHhandle;                                     //~va79R~
        optebc=XEERMO_SETHANDLE(handle);                           //~va79I~
    }                                                              //~va79I~
    rc=ppsrchsub(Ppcw,plh,offs,WORD_ID,Pswcase,dest);              //~v77ER~
    if (rc)                                                        //~v77EI~
    {                                                              //~v77EI~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (Sothopt & SEARCH_UCS2WORD)                             //~va50I~
    		xeerrmsg(0,4/*parmctr*/,                               //~va50I~
				 XEERMPTS_LC XEERMPTS_DDFMT,                       //~va50R~
    			"%s:\"%s\" Not Found",                             //~va50I~
				"%s:\"%s\" が見つかりません",                      //~va50I~
        			pft->FTcmd,Sswdd,Sswdbcs,Sswlendd);            //~va50I~
        else                                                       //~va50I~
        if (Sothopt & SEARCH_EBCWORD)                              //~va50I~
//  		xeerrmsg(0,3/*parmctr*/,                               //~va50I~//~va79R~
    		xeerrmsg(optebc,3/*parmctr*/,                          //~va79R~
				 XEERMPTS_LC XEERMPTS_EBCDBCSPARM,                 //~va50I~
    			"%s:\"%s\" Not Found",                             //~va50I~
				"%s:\"%s\" が見つかりません",                      //~va50I~
        			pft->FTcmd,Ssrchword,Sswdbcs);                 //~va50R~
        else                                                       //~va50I~
    		uerrmsg("%s:\"%s\" Not Found",                         //~va50R~
					"%s:\"%s\" が見つかりません",                  //~va50I~
//      			pft->FTcmd,Ssrchword);                         //~va50I~//~vbq6R~
        			pft->FTcmd,pemsrchword);                       //~vbq6I~
#else                                                              //~va50I~
    	uerrmsg("%s:\"%s\" Not Found",                             //~v77MR~
				"%s:\"%s\" が見つかりません",                      //~v77MR~
#ifdef UTF8UCS2                                                    //~va20I~
        			pft->FTcmd,pemsrchword);                       //~va20R~
#else                                                              //~va20I~
        			pft->FTcmd,Ssrchword);                         //~v77MI~
#endif                                                             //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        Sfindstatus=-1;                                            //~v77EI~
    }                                                              //~v77EI~
    else                                                           //~v77EI~
    {                                                              //~v77EI~
    	if (researchsw>0)                                          //~v77ER~
    		uerrmsg("%s:Found:re-search from Top",0,               //~v77MR~
        			pft->FTcmd);                                   //~v77EI~
        else                                                       //~v77EI~
    	if (researchsw<0)                                          //~v77ER~
    		uerrmsg("%s:Found:re-search from End",0,               //~v77MR~
        			pft->FTcmd);                                   //~v77EI~
        else                                                       //~v77EI~
        if (contsrchsw)                                            //~v77MI~
    		uerrmsg("%s:Found:previous word",0,                    //~v77MR~
        			pft->FTcmd);                                   //~v77MI~
        else                                                       //~v77MI~
    		uerrmsg("%s:Found",0,                                  //~v77MR~
        			pft->FTcmd);                                   //~v77ER~
        Sfindstatus=1;                                             //~v77EI~
    }                                                              //~v77EI~
    if (!rc)                                                       //~v77EI~
    	rc=rc2;                                                    //~v77EI~
    return rc;                                                     //~v77EI~
}//fcmdsrchword                                                    //~v77ER~
//*******************************************************          //~v77EI~
//* setdelm                                                        //~v77EI~
//*    left    include (x   , exclude x(  or \(( or \)(            //~v77ER~
//*    right   include x)  or \)) or \(), exclude )x               //~v77ER~
//*    "" for " , \an for alphanumeric                             //~v77EI~
//* rc: 1:opd ignore ,2:help,4:err                                 //~v77EI~
//*******************************************************          //~v77EI~
int fcmdsrchwordopdchk(PUCLIENTWE Ppcw,char *Pdelm)                //~v77ER~
{                                                                  //~v77EI~
	int opdno,ii,rc;                                               //~v77ER~
    char *pc;                                                      //~v77EI~
    PFUNCTBL pft;                                                  //~v77EI~
	char *wkbuff;                                                  //~v77EI~
#define DELM_ALPHNUM     "AN"                                      //~v77ER~
#define DELM_SPACE       "SP"                                      //~v77ER~
#define DELM_DQUOTE      "DQ"                                      //~v77ER~
#define DELM_SQUOTE      "SQ"                                      //~v77ER~
//  char defaultdelm[4]={FGW_DELM_PUNCT,0,FGW_DELM_PUNCT,0};       //~v77ER~//~v7avR~
    char defaultdelm[4+FGW_DELM_MAXLEN*2]={FGW_DELM_PUNCT,0,FGW_DELM_PUNCT,0};//~v7avI~
    int mblen;                                                     //~v7avI~
    char *pcmb;                                                    //~v7avI~
    char wkebcdata[4+FGW_DELM_MAXLEN],*pebc;                       //~va7kI~
    char wkebcdbcs[4+FGW_DELM_MAXLEN];                             //~va7kR~
    PUFILEH pfh;                                                   //~va7kI~
    int opdlen,ebclen,swebcfile,offs;                              //~va7kR~
    char *pc0;                                                     //~va7nR~
//***********************                                          //~v77EI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~va7kI~
    swebcfile=(pfh && PFH_ISEBC(pfh));                             //~va7kI~
	memcpy(Pdelm,defaultdelm,4);                                   //~v77ER~
    wkbuff=Ppcw->UCWparm;                                          //~v77EI~
    if (wkbuff)                                                    //~v77EI~
    {                                                              //~v77EI~
        if (!stricmp(wkbuff,DELM_ALPHNUM))                         //~v77ER~
            return 0;                                              //~v77ER~
        if (!stricmp(wkbuff,DELM_SQUOTE))                          //~v77ER~
        {                                                          //~v77EI~
            Pdelm[0]=FGW_DELM_EXCLUDE;    //exclude                //~v77EI~
            Pdelm[1]='\'';                                         //~v77ER~
            Pdelm[2]=FGW_DELM_EXCLUDE;    //exclude                //~v77EI~
            Pdelm[3]='\'';                                         //~v77ER~
            return 0;                                              //~v77EI~
        }                                                          //~v77EI~
        if (!stricmp(wkbuff,DELM_DQUOTE))                          //~v77ER~
        {                                                          //~v77EI~
            Pdelm[0]=FGW_DELM_EXCLUDE;    //exclude                //~v77EI~
            Pdelm[1]='\"';                                         //~v77ER~
            Pdelm[2]=FGW_DELM_EXCLUDE;    //exclude                //~v77EI~
            Pdelm[3]='\"';                                         //~v77ER~
            return 0;                                              //~v77EI~
        }                                                          //~v77EI~
        if (!stricmp(wkbuff,DELM_SPACE))                           //~v77ER~
        {                                                          //~v77EI~
			memset(Pdelm,0,4);                                     //~v77EI~
            return 0;                                              //~v77EI~
        }                                                          //~v77EI~
    }                                                              //~v77EI~
    if (Ppcw->UCWkeytype!=UCWKTCMD  //func key,cmdline nmot yet parsed//~v77EI~
    &&  wkbuff  //input on cmdline set by funccall                 //~v77ER~
    )                                                              //~v77EI~
    {                                                              //~v77EI~
        uparse(wkbuff,wkbuff,&opdno,0,","); //parse out,accept cr/lf//~v77EI~
        pc=wkbuff;                                                 //~v77EI~
    }                                                              //~v77EI~
    else                                                           //~v77EI~
    {                                                              //~v77EI~
    	opdno=Ppcw->UCWopdno;           //funccmd created already  //~v77ER~
   	 	pc=Ppcw->UCWopdpot;                                        //~v77ER~
    }                                                              //~v77EI~
    if (Ppcw->UCWkeytype==UCWKTCMD                                 //~v77ER~
    &&  (!opdno || *pc=='?'))                                      //~v77EI~
    {                                                              //~v77EI~
    	pft=Ppcw->UCWpfunct;                                       //~v77EI~
    	uerrmsg("%s  [ %s | %s | %s | %s | [ (x | x( ]  [ x) | )x ] ];   default is %s(punch except %s), \"\" for \", \\( and \\) if start from ( or ).",//~v77ER~
    	        "%s  [ %s | %s | %s | %s | [ (x | x( ]  [ x) | )x ] ];   省略値は %s(%s 以外の全ての区切り文字), \"には \"\", ( か ) で始まる時は \\( や \\)。",//~v77ER~
        		pft->FTcmd,DELM_ALPHNUM,DELM_SPACE,DELM_DQUOTE,DELM_SQUOTE,//~v77ER~
				DELM_ALPHNUM,USTR_NOPUNCT);                        //~v77EI~
    	return 2;                                                  //~v77EI~
    }                                                              //~v77EI~
    if (opdno<1)                                                   //~v77EM~
    	return 0;                                                  //~v77EM~
 	if (opdno>2)                                                   //~v77EI~
    	return 1;                                                  //~v77ER~
    rc=0;                                                          //~v77EI~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v77EI~
	{                                                              //~v77EI~
    	pc0=pc;                                                    //~va7nR~
//  	opdlen=strlen(pc);                                         //~va7kI~//~vb2DR~
    	opdlen=(int)strlen(pc);                                    //~vb2DI~
        ebclen=0;                                                  //~va7kI~
    	if (swebcfile)                                             //~va7kI~
			if (xeebc_m2ddebc(0,pfh,pc,opdlen,wkebcdata,wkebcdbcs,sizeof(wkebcdbcs),&ebclen))//~va7kR~
            	ebclen=0;                                          //~va7kI~
        if (*pc=='(')        //left edge                           //~v77EI~
        {                                                          //~v77EI~
            if (*(pc+1))                                           //~v77EI~
            {                                                      //~v77EI~
//          	mblen=(int)strlen(pc+1);                                //~v7avI~//~v7b0R~//~va7kR~
            	mblen=opdlen-1;                                    //~va7kI~
              if (mblen>1)                                         //~v7avI~
              {                                                    //~v7avI~
                mblen=min(FGW_DELM_MAXLEN,mblen);                  //~v7avI~
                Pdelm[0]=FGW_DELM_INCLUDEM;    //include multibyte //~v7avI~
                Pdelm[1]=(UCHAR)mblen;                             //~v7avI~
                memcpy(Pdelm+4,pc+1,(UINT)mblen);                  //~v7avI~
                if (ebclen)                                        //~va7kI~
                {                                                  //~va7kI~
                  pebc=Pdelm+4+FGW_DELM_MAXLEN*2+1;                //~va7kR~
                  ebclen--;                                        //~va7kI~
                  memcpy(pebc,wkebcdata+1,(UINT)ebclen);           //~va7kI~
                  memcpy(pebc+FGW_DELM_MAXLEN,wkebcdbcs+1,(UINT)ebclen);//~va7kI~
//                *(pebc-1)=UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~va7kI~//~vb2CR~
                  *(pebc-1)=(char)UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~vb2CI~
                }                                                  //~va7kI~
              }                                                    //~v7avI~
              else                                                 //~v7avI~
              {                                                    //~v7avI~
                Pdelm[0]=FGW_DELM_INCLUDE;    //include            //~v77ER~
               if (ebclen)                                         //~va7kR~
                Pdelm[1]=wkebcdata[1];                             //~va7kI~
               else                                                //~va7kI~
                Pdelm[1]=*(pc+1);                                  //~v77EI~
              }                                                    //~v7avI~
            }                                                      //~v77EI~
            else                                                   //~v77EI~
                rc=1;                                              //~v77ER~
        }                                                          //~v77EI~
        else                                                       //~v77EI~
        if (*pc==')')        //left edge                           //~v77EI~
        {                                                          //~v77EI~
            if (*(pc+1))                                           //~v77EI~
            {                                                      //~v77EI~
//          	mblen=(int)strlen(pc+1);                                //~v7avI~//~v7b0R~//~va7kR~
            	mblen=opdlen-1;                                    //~va7kI~
              if (mblen>1)                                         //~v7avI~
              {                                                    //~v7avI~
                mblen=min(FGW_DELM_MAXLEN,mblen);                  //~v7avI~
                Pdelm[2]=FGW_DELM_EXCLUDEM;    //include multibyte //~v7avI~
                Pdelm[3]=(UCHAR)mblen;                             //~v7avI~
                memcpy(Pdelm+4+FGW_DELM_MAXLEN,pc+1,(UINT)mblen);  //~v7avI~
                if (ebclen)                                        //~va7kI~
                {                                                  //~va7kI~
                  pebc=Pdelm+4+FGW_DELM_MAXLEN*2+(1+FGW_DELM_MAXLEN*2)+1;//~va7kR~
                  ebclen--;                                        //~va7kI~
                  memcpy(pebc,wkebcdata+1,(UINT)ebclen);           //~va7kI~
                  memcpy(pebc+FGW_DELM_MAXLEN,wkebcdbcs+1,(UINT)ebclen);//~va7kI~
//                *(pebc-1)=UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~va7kI~//~vb2CR~
                  *(pebc-1)=(char)UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~vb2CI~
                }                                                  //~va7kI~
              }                                                    //~v7avI~
              else                                                 //~v7avI~
              {                                                    //~v7avI~
                Pdelm[2]=FGW_DELM_EXCLUDE; //exclude               //~v77ER~
               if (ebclen)	//transleted for ebc file              //~va7kI~
                Pdelm[3]=wkebcdata[1];                             //~va7kI~
               else                                                //~va7kI~
                Pdelm[3]=*(pc+1);                                  //~v77EI~
              }                                                    //~v7avI~
            }                                                      //~v77EI~
            else                                                   //~v77EI~
                rc=1;                                              //~v77ER~
        }                                                          //~v77EI~
        else                                                       //~v77EI~
        {                                                          //~v77EI~
        	offs=0;                                                //~va7kI~
            if (*pc=='\\'                                          //~v77ER~
            &&  (*(pc+1)=='('||*(pc+1)==')')                       //~v77ER~
//          &&  (*(pc+2)=='('||*(pc+2)==')')                       //~v77EI~//~va7mR~
            &&  opdlen>2                                           //~va7mR~
            )                                                      //~v77EI~
            {                                                      //~va7kI~
                pc++;                                              //~v77EI~
                offs=1;                                            //~va7kI~
            }                                                      //~va7kI~
            mblen=(int)strlen(pc)-1;	//except last char                 //~v7avI~//~v7b0R~
            pcmb=pc;				//mb delm top                  //~v7avI~
            pc+=mblen-1;             //for 1byte delm              //~v7avI~
            if (*(pc+1)=='(')        //left edge                   //~v77EI~
            {                                                      //~v77EI~
                if (*(pc+1))                                       //~v77EI~
                {                                                  //~v77EI~
                  if (mblen>1)                                     //~v7avI~
                  {                                                //~v7avI~
                    mblen=min(FGW_DELM_MAXLEN,mblen);              //~v7avI~
                    Pdelm[0]=FGW_DELM_EXCLUDEM;    //include multibyte//~v7avI~
                    Pdelm[1]=(UCHAR)mblen;                         //~v7avI~
                    memcpy(Pdelm+4,pcmb,(UINT)mblen);              //~v7avR~
                    if (ebclen)                                    //~va7kI~
                    {                                              //~va7kI~
                      pebc=Pdelm+4+FGW_DELM_MAXLEN*2+1;            //~va7kR~
                      ebclen-=1+offs;                              //~va7kI~
                      memcpy(pebc,wkebcdata+offs,(UINT)ebclen);    //~va7kI~
                      memcpy(pebc+FGW_DELM_MAXLEN,wkebcdbcs+offs,(UINT)ebclen);//~va7kI~
//                    *(pebc-1)=UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~va7kI~//~vb2CR~
                      *(pebc-1)=(char)UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~vb2CI~
                    }                                              //~va7kI~
                  }                                                //~v7avI~
                  else                                             //~v7avI~
                  {                                                //~v7avI~
                    Pdelm[0]=FGW_DELM_EXCLUDE;  //exclude          //~v77ER~
                   if (ebclen)                                     //~va7kI~
                    Pdelm[1]=wkebcdata[offs];                      //~va7kR~
                   else                                            //~va7kI~
                    Pdelm[1]=*(pc);                                //~v77EI~
                  }                                                //~v7avI~
                }                                                  //~v77EI~
                else                                               //~v77EI~
                    rc=1;                                          //~v77ER~
            }                                                      //~v77EI~
            else                                                   //~v77EI~
            if (*(pc+1)==')')        //left edge                   //~v77EI~
            {                                                      //~v77EI~
                if (*(pc+1))                                       //~v77EI~
                {                                                  //~v77EI~
                  if (mblen>1)                                     //~v7avI~
                  {                                                //~v7avI~
                    mblen=min(FGW_DELM_MAXLEN,mblen);              //~v7avI~
                    Pdelm[2]=FGW_DELM_INCLUDEM;    //include multibyte//~v7avI~
                    Pdelm[3]=(UCHAR)mblen;                         //~v7avI~
                    memcpy(Pdelm+4+FGW_DELM_MAXLEN,pcmb,(UINT)mblen);//~v7avR~
                    if (ebclen)                                    //~va7kI~
                    {                                              //~va7kI~
                      pebc=Pdelm+4+FGW_DELM_MAXLEN*2+(1+FGW_DELM_MAXLEN*2)+1;//~va7kR~
                      ebclen-=1+offs;                              //~va7kI~
                      memcpy(pebc,wkebcdata+offs,(UINT)ebclen);    //~va7kI~
                      memcpy(pebc+FGW_DELM_MAXLEN,wkebcdbcs+offs,(UINT)ebclen);//~va7kI~
//                    *(pebc-1)=UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~va7kI~//~vb2CR~
                      *(pebc-1)=(char)UCVEBC_CUTSIDESOSI(pebc,pebc+FGW_DELM_MAXLEN,ebclen);//~vb2CI~
                    }                                              //~va7kI~
                  }                                                //~v7avI~
                  else                                             //~v7avI~
                  {                                                //~v7avI~
                    Pdelm[2]=FGW_DELM_INCLUDE; //include           //~v77ER~
                   if (ebclen)                                     //~va7kI~
                    Pdelm[3]=wkebcdata[offs];                      //~va7kR~
                   else                                            //~va7kI~
                    Pdelm[3]=*(pc);                                //~v77EI~
                  }                                                //~v7avI~
                }                                                  //~v77EI~
                else                                               //~v77EI~
                    rc=1;                                          //~v77ER~
            }                                                      //~v77EI~
            else                                                   //~va7mI~
                rc=1;                                              //~va7mI~
        }                                                          //~v77EI~
    	if (rc==1)                                                 //~va7nR~
			if (Ppcw->UCWkeytype==UCWKTCMD)	//cmd input            //~va7nR~
        	{                                                      //~va7nR~
        		uerrmsg("delimiter format err(%s)",0,              //~va7nR~
                			pc0);                                  //~va7nR~
                rc=4;                                              //~va7nR~
                break;                                             //~va7nR~
        	}                                                      //~va7nR~
    }                                                              //~v77EI~
    return rc;                                                     //~v77EI~
}//fcmdsrchwordopdchk                                              //~v77ER~
//*******************************************************          //~v77EM~
//* get search word                                                //~v77EM~
//*******************************************************          //~v77EM~
int fcmdgetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffs,int *Pplen,int Pmaxlen,char *Pdelm)//~v77EI~//~vbp3R~
{                                                                  //~v77EM~
	int rc=0,offs=0;                                                 //~v77MR~//~vaf9R~
    int swSamePos=0;                                               //~vbp3I~
    PULINEH plh;                                                   //~v77MI~
    PULINEH plh2;                                                  //~vbp3I~
//*******************                                              //~v77EM~
	*Pplen=0;                                                      //~v77EM~
	switch (((PUPANELC)Ppcw->UCWppc)->UPCid)                       //~v77EM~
    {                                                              //~v77EM~
	case PANFBROWSE:                                               //~v77EM~
	case PANFEDIT:                                                 //~v77EM~
        if (capgetmouseword(0,Ppcw,Ppplh,Ppoffs,Pplen))	//no mouse block//~v77ER~
        {                                                          //~v77MI~
            plh=0;                                                 //~v77MI~
            if (Ssrchwordlen)         //prev word                  //~v77MR~
            {                                                      //~v77MI~
            	if (!CSRONFILEDATA(Ppcw))       //csr not on filedata//~v77MR~
					fcmdgetstartplhoffs(Ppcw,&plh,&offs,0/*no minus return*/);//~v77MI~
                else                                               //~vbp3I~
                {                                                  //~vbp3I~
					if (fcmdgetstartplhoffs(Ppcw,&plh2,&offs,0/*no minus return*/)==0)  //csr is on client area//~vbp3I~
                    {                                              //~vbp3I~
                    	if (plh2 && (offs+Ssrchwordlen)<=plh2->ULHlen)//~vbp3I~
                        	if (!memcmp(Ssrchword,plh2->ULHdata+offs,(size_t)Ssrchwordlen))//~vbp3R~
                            {                                      //~vbp3I~
                            	plh=plh2;                          //~vbp3I~
                                swSamePos=1;                       //~vbp3I~
                            }                                      //~vbp3I~
                    }                                              //~vbp3I~
                }                                                  //~vbp3I~
            }                                                      //~v77MI~
          if (plh)      //                                         //~v77MI~
          {                                                        //~v77MI~
          	*Ppplh=plh;                                            //~v77MI~
            *Ppoffs=offs;                                          //~v77MR~
            *Pplen=Ssrchwordlen;                                   //~v77MI~
          if (!swSamePos)                                          //~vbp3I~
			Ssrchstat|=SS_WORD_REUSE;                              //~v77MI~
          }                                                        //~v77MI~
          else                                                     //~v77MI~
			*Pplen=filegetword(Ppcw,Ppplh,Ppoffs,Pdelm);           //~v77ER~
        }                                                          //~v77MI~
        break;                                                     //~v77EM~
    default:                                                       //~v77EM~
  		return errscrtype("(I)Find Word");                         //~v77EM~
    }                                                              //~v77EM~
    if (!*Pplen)                                                   //~v77EM~
        return 4;                                                  //~v77EM~
    if (*Pplen>Pmaxlen)                                            //~v77EM~
    {                                                              //~va5aI~
//  	return errtoolong();                                       //~v77EM~//~va5aR~
        uerrmsg("Too long search word(Delimiter not found)",       //~va5aI~
                "探索文字列が長すぎます。(分離文字が見つかりません)");//~va5aI~
        return 4;                                                  //~va5aI~
    }                                                              //~va5aI~
	return rc;                                                     //~v77MR~
}//fcmdgetword                                                     //~vafhR~
//**************************************************************** //~v77EI~
// ppsrchword                                                      //~v77EI~
//**************************************************************** //~v77EI~
int ppsrchword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pswcase,int Pdest)//~v77ER~
{                                                                  //~v77EI~
	int offs,rc,wordlen,len;                                       //~v77ER~
    char *pc,*pc2;                                                 //~v77EI~
    PULINEH plh,plh0;                                              //~v77ER~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************                           //~v77EI~
	plh=plh0=*Ppplh;                                               //~v77ER~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=PLHUTF8MODE(plh);                                   //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(plh);                                      //~va50I~
    handle=UGETPFH(plh)->UFHhandle;                                //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    offs=*Ppoffset;                                                //~v77EI~
	if (Pdest<0)                                                   //~v77ER~
	{                                                              //~v77EI~
    	wordlen=-Pdest;                                            //~v77EI~
        for (;plh;plh=UGETQPREV(plh))                              //~v77ER~
        {                                                          //~v77EI~
            if (plh->ULHtype!=ULHTDATA)                            //~v77EI~
                continue;                                          //~v77EI~
	    	if (!plh->ULHdbcs)                                     //~v77EI~
            {                                                      //~v77EI~
            	rc=filechktabdbcs(plh); //expand tab               //~v77EI~
            	if (rc==UALLOC_FAILED)                             //~v77EI~
                	return UALLOC_FAILED;                          //~v77EI~
            }                                                      //~v77EI~
            pc=plh->ULHdata;                                       //~v77EI~
            if (plh==plh0)                                         //~v77EI~
	            len=offs;                                          //~v77ER~
            else                                                   //~v77EI~
        		len=plh->ULHlen;                                   //~v77EI~
            if (Pswcase)                                           //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	            pc2=UCVEBCUTF_umemrmem(swebcfile,swutf8file,pc,plh->ULHdbcs,Ssrchword,Sswdbcs,len,wordlen);//~va50R~
    #else                                                          //~va50I~
	            pc2=UTF_umemrmem(swutf8file,pc,plh->ULHdbcs,Ssrchword,0/*key dbcs*/,len,wordlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	            pc2=umemrmem(pc,Ssrchword,(UINT)len,(UINT)wordlen);//~v77ER~
#endif                                                             //~va20I~
            else                                                   //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              pc2=UCVEBCUTF_umemrmemi(swebcfile,swutf8file,pc,plh->ULHdbcs,Ssrchword,Sswdbcs,len,wordlen);//~va50R~//~va79R~
                pc2=UCVEBCUTF_umemrmemi(swebcfile,swutf8file,handle,pc,plh->ULHdbcs,Ssrchword,Sswdbcs,len,wordlen);//~va79I~
    #else                                                          //~va50I~
	            pc2=UTF_umemrmemi(swutf8file,pc,plh->ULHdbcs,Ssrchword,0/*key dbcs*/,len,wordlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	            pc2=umemrmemi(pc,Ssrchword,(UINT)len,(UINT)wordlen);//~v77EI~
#endif                                                             //~va20I~
            if (pc2)                                               //~v77EI~
            {                                                      //~v77EI~
//            	offs=(int)((ULONG)pc2-(ULONG)pc);                  //~v77EI~//~vafkR~
            	offs=(int)((ULPTR)pc2-(ULPTR)pc);                  //~vafkI~
	            break;                                             //~v77ER~
            }                                                      //~v77EI~
        }//all plh                                                 //~v77EI~
	}//prev                                                        //~v77EI~
	else			//not prev                                     //~v77EI~
	{				//next                                         //~v77EI~
    	wordlen=Pdest;                                             //~v77EI~
//      for (offs+=wordlen;plh;plh=UGETQNEXT(plh),offs=0)          //~v78PR~
		if (Ssrchstat & SS_WORD_REUSE)                             //~v78PI~
        	offs=0;                                                //~v78PI~
        else                                                       //~v78PI~
        	offs+=wordlen;                                         //~v78PI~
        for (;plh;plh=UGETQNEXT(plh),offs=0)                       //~v78PI~
        {                                                          //~v77EI~
            if (plh->ULHtype!=ULHTDATA)                            //~v77EI~
                continue;                                          //~v77EI~
	    	if (!plh->ULHdbcs)                                     //~v77EI~
            {                                                      //~v77EI~
            	rc=filechktabdbcs(plh); //expand tab               //~v77EI~
            	if (rc==UALLOC_FAILED)                             //~v77EI~
                	return UALLOC_FAILED;                          //~v77EI~
            }                                                      //~v77EI~
            pc=plh->ULHdata+offs;                                  //~v77EI~
            len=plh->ULHlen-offs;                                  //~v77EI~
          if (len>0)  //for safety                                 //~v78PI~
          {                                                        //~v78PI~
            if (Pswcase)                                           //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	            pc2=UCVEBCUTF_umemmem(swebcfile,swutf8file,pc,plh->ULHdbcs+offs,Ssrchword,Sswdbcs,len,wordlen);//~va50R~
    #else                                                          //~va50I~
	            pc2=UTF_umemmem(swutf8file,pc,plh->ULHdbcs+offs,Ssrchword,0/*keydbcs*/,len,wordlen);//~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
	            pc2=umemmem(pc,Ssrchword,(UINT)len,(UINT)wordlen); //~v77ER~
#endif                                                             //~va20I~
            else                                                   //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              pc2=UCVEBCUTF_umemmemi(swebcfile,swutf8file,pc,plh->ULHdbcs+offs,Ssrchword,Sswdbcs,len,wordlen);//~va50R~//~va79R~
                pc2=UCVEBCUTF_umemmemi(swebcfile,swutf8file,handle,pc,plh->ULHdbcs+offs,Ssrchword,Sswdbcs,len,wordlen);//~va79I~
    #else                                                          //~va50I~
	            pc2=UTF_umemmemi(swutf8file,pc,plh->ULHdbcs+offs,Ssrchword,0/*Ssrchworddbcs*/,len,wordlen);//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
	            pc2=umemmemi(pc,Ssrchword,(UINT)len,(UINT)wordlen);//~v77EI~
#endif                                                             //~va20I~
            if (pc2)                                               //~v77EI~
            {                                                      //~v77EI~
//            	offs=(int)((ULONG)pc2-(ULONG)pc+offs);             //~v77EI~//~vafkR~
//          	offs=(int)((ULPTR)pc2-(ULPTR)pc+offs);             //~vafkI~//~vb2DR~
            	offs=PTRDIFF(pc2,pc)+offs;                         //~vb2DI~
	            break;                                             //~v77EI~
            }                                                      //~v77EI~
          }                                                        //~v78PI~
        }//all plh                                                 //~v77EI~
    }//prev/next                                                   //~v77EI~
    if (!plh)                                                      //~v77EI~
    	return 4;                                                  //~v77EI~
    *Ppplh=plh;                                                    //~v77EI~
    *Ppoffset=offs;                                                //~v77ER~
    Ssrchwordoffs=offs;                                            //~v77EI~
    Ssrchwordplh=plh;                                              //~v77EI~
    return 0;                                                      //~v77ER~
}//ppsrchword                                                      //~v77ER~
//*************************************************************************//~vbe0I~
int isValidElementName(int Popt,int Pch,int Pdbcsid,int Ppos)      //~vbe0R~
{                                                                  //~vbe0I~
	if (Pdbcsid)                                                   //~vbe0I~
    	return 1;                                                  //~vbe0R~
	if (!Ppos)                                                     //~vbe0I~
    	if (Pch>='0' && Pch<='9')                                  //~vbe0I~
        	return 0;	//err                                      //~vbe0I~
    if (strchr(XML_VALID_CHAR,Pch))                                //~vbe0R~
    	return 1;                                                  //~vbe0I~
    if (ispunct(Pch)) //                                           //~vbe0I~
    	return 0;                                                  //~vbe0I~
    return 1;                                                      //~vbe0I~
}//isValidElementName                                              //~vbe0R~
//*************************************************************************//~vbe0I~
//*Poffs:pos of cursor                                             //~vbe0I~
//*return XMLT_xx,0 if err                                         //~vbe0I~
//*************************************************************************//~vbe0I~
int getxmltype(int Popt,char *Pdata,char *Pdbcs,int Plen,int Poffs,char *Pname,char *Pnamedbcs,//~vbe0R~
					int Pbuffsz,int *Ppposnext,int *Ppnamelen)     //~vbe0I~
{                                                                  //~vbe0I~
	int type=0,ch,ctr=0,namepos=0,namelen=0,posnext;               //~vbe0R~
    char *pc,*pc0,*pce,*pcd;                                       //~vbe0I~
//******************************************                       //~vbe0I~
	if (Poffs>=Plen || Poffs<0)                                    //~vbe0I~
    	return 0;                                                  //~vbe0I~
	pc0=Pdata+Poffs;                                               //~vbe0I~
	pce=Pdata+Plen;                                                //~vbe0I~
    pcd=Pdbcs+Poffs;                                               //~vbe0I~
    pc=pc0;                                                        //~vbe0I~
    if (*pcd)       //dbcs                                         //~vbe0I~
    	return 0;                                                  //~vbe0I~
	ch=*pc0;                                                       //~vbe0I~
    switch(ch)                                                     //~vbe0I~
    {                                                              //~vbe0I~
    case XML_TAG1:  //"<"                                          //~vbe0I~
    	pc++;                                                      //~vbe0I~
        pcd++;                                                     //~vbe0I~
        if (pc>=pce)                                               //~vbe0I~
        	return 0;                                              //~vbe0I~
        ch=*pc;                                                    //~vbe0I~
        if (!*pcd)                                                 //~vbe0I~
        {                                                          //~vbe0I~
        	switch(ch)                                             //~vbe0I~
            {                                                      //~vbe0I~
            case XML_TAGT:      // "</"                            //~vbe0I~
            	type=XMLT_END;                                     //~vbe0I~
                pc++;                                              //~vbe0I~
                pcd++;                                             //~vbe0I~
                break;                                             //~vbe0I~
	        case XML_CMT1:       // "<!"                           //~vbe0I~
            	if (pc+1<pce                                       //~vbe0I~
            	&&  *(pc+1)==XML_CMT2 && !*(pcd+1) //<!-           //~vbe0I~
                )                                                  //~vbe0I~
                {                                                  //~vbe0I~
            		if (pc+2<pce                                   //~vbe0I~
	            	&&  *(pc+2)==XML_CMT2 && !*(pcd+2)  //<!--     //~vbe0I~
    	            )                                              //~vbe0I~
                    {                                              //~vbe0I~
	            		type=XMLT_STARTCMT;                        //~vbe0I~
                   		pc+=2;                                     //~vbe0I~
                    	pcd+=2;                                    //~vbe0I~
                    	break;                                     //~vbe0I~
                    }                                              //~vbe0I~
		        	return 0;                                      //~vbe0I~
				}                                                  //~vbe0I~
                else                                               //~vbe0I~
                {                                                  //~vbe0I~
                	if (!isValidElementName(0,*(pc+1),*(pcd+1),0)) //~vbe0R~
                    	return 0;                                  //~vbe0I~
                }                                                  //~vbe0I~
	            type=XMLT_STARTOTHER;                              //~vbe0I~
                break;                                             //~vbe0I~
	        case XML_OTH1:       // "<?"                           //~vbe0I~
            	type=XMLT_STARTOTHER;                              //~vbe0I~
                break;                                             //~vbe0I~
            default:                                               //~vbe0I~
                if (ch>='0' && ch<='9')                            //~vbe0I~
                	return 0;                                      //~vbe0I~
            	type=XMLT_START;                                   //~vbe0I~
            }                                                      //~vbe0I~
        }                                                          //~vbe0I~
        else                                                       //~vbe0I~
            type=XMLT_START;                                       //~vbe0I~
        switch(type)                                               //~vbe0I~
        {                                                          //~vbe0I~
        case XMLT_STARTCMT:                                        //~vbe0I~
        case XMLT_STARTOTHER:                                      //~vbe0I~
        	break;                                                 //~vbe0I~
        default:    //START(<xxx) or END(</)                       //~vbe0I~
            namepos=PTRDIFF(pc,Pdata);                             //~vbe0I~
            for (ctr=0;pc<pce;pc++)                                //~vbe0I~
            {                                                      //~vbe0I~
                ch=*pc;                                            //~vbe0I~
                pcd=Pdbcs+PTRDIFF(pc,Pdata);                       //~vbe0I~
                if (ch==XML_TAG2 && !*pcd)    //">"                //~vbe0I~
                    break;                                         //~vbe0I~
                if (ch==' ' || ch=='\t')    //"<xxx ...>"          //~vbe0I~
                {                                                  //~vbe0I~
                	if (type==XMLT_END)                            //~vbe0I~
                    	return 0;                                  //~vbe0I~
                    type=XMLT_STARTATTR;                           //~vbe0I~
                    break;                                         //~vbe0I~
                }                                                  //~vbe0I~
                if (!isValidElementName(0,ch,*pcd,ctr))            //~vbe0I~
                    return 0;                                      //~vbe0I~
                ctr++;                                             //~vbe0I~
        	}                                                      //~vbe0I~
            if (type==XMLT_START)	// <xxx+crlf>                  //~vbp2I~
            	type=XMLT_STARTATTR;   //search </xxx or />        //~vbp2I~
            namelen=ctr;                                           //~vbe0I~
        }                                                          //~vbe0I~
    	posnext=PTRDIFF(pc,Pdata)+1;                               //~vbe0I~
        break;                                                     //~vbe0I~
    case XML_TAG2:  //">"                                          //~vbe0I~
    	type=XMLT_CLOSEOTHER;                                      //~vbe0I~
    	if (pc>Pdata)                                              //~vbe0I~
        {                                                          //~vbe0I~
    		pc--;                                                  //~vbe0I~
        	pcd--;                                                 //~vbe0I~
        	ch=*pc;                                                //~vbe0I~
            if (!*pcd)                                             //~vbe0I~
            {                                                      //~vbe0I~
                switch(ch)                                         //~vbe0I~
                {                                                  //~vbe0I~
                case XML_TAGT:   //     "/>"                       //~vbe0I~
                	type=XMLT_CLOSEATTR;                           //~vbe0I~
                    break;                                         //~vbe0I~
                case XML_CMT2:   //     "->"                       //~vbe0I~
                	if (pc>Pdata)                                  //~vbe0I~
                    {                                              //~vbe0I~
                    	pc--;                                      //~vbe0I~
                        pcd--;                                     //~vbe0I~
                        if (*pc==XML_CMT2 && !*pcd)                //~vbe0I~
                        {                                          //~vbe0I~
                        	type=XMLT_ENDCMT;                      //~vbe0I~
                            break;                                 //~vbe0I~
                        }                                          //~vbe0I~
                    }                                              //~vbe0I~
                    return 0;                                      //~vbe0R~
                }                                                  //~vbe0I~
            }                                                      //~vbe0I~
        }                                                          //~vbe0I~
    	posnext=PTRDIFF(pc,Pdata);                                 //~vbe0I~
        break;                                                     //~vbe0I~
    case XML_TAGT:  //"/"                                          //~vbe0I~
    	if (pc+1<pce)                                              //~vbe0I~
        {                                                          //~vbe0I~
            if (*(pc+1)==XML_TAG2 && !*(pcd+1)) // "/>"            //~vbe0R~
            {                                                      //~vbe0I~
            	type=XMLT_CLOSEATTR2;                              //~vbe0R~
		    	posnext=PTRDIFF(pc,Pdata);                         //~vbe0I~
                break;                                             //~vbe0I~
            }                                                      //~vbe0I~
        }                                                          //~vbe0I~
        return 0;                                                  //~vbe0I~
    case XML_CMT2:  //"-"       allow cursor on "-->" to easy back to "<!--"//~vbe0I~
    	if (pc+2<pce)                                              //~vbe0I~
        {                                                          //~vbe0I~
            if (*(pc+1)==XML_CMT2 && !*(pcd+1)                     //~vbe0I~
            &&  *(pc+2)==XML_TAG2 && !*(pcd+2)                     //~vbe0I~
            )                                                      //~vbe0I~
            {                                                      //~vbe0I~
            	type=XMLT_ENDCMT2;                                 //~vbe0I~
		    	posnext=PTRDIFF(pc,Pdata);                         //~vbe0I~
                break;                                             //~vbe0I~
            }                                                      //~vbe0I~
        }                                                          //~vbe0I~
    	if (pc+1<pce && pc>Pdata)                                  //~vbe0I~
        {                                                          //~vbe0I~
            if (*(pc-1)==XML_CMT2 && !*(pcd+1)   //"-"             //~vbe0I~
            &&  *(pc+1)==XML_TAG2 && !*(pcd+1)   //">"             //~vbe0I~
            )                                                      //~vbe0I~
            {                                                      //~vbe0I~
            	type=XMLT_ENDCMT3;                                 //~vbe0I~
		    	posnext=PTRDIFF(pc,Pdata)-1;                       //~vbe0I~
                break;                                             //~vbe0I~
            }                                                      //~vbe0I~
        }                                                          //~vbe0I~
        return 0;                                                  //~vbe0I~
    default:                                                       //~vbe0I~
    	return 0;                                                  //~vbe0I~
    }                                                              //~vbe0I~
    if (namepos)                                                   //~vbe0I~
    {                                                              //~vbe0I~
    	if (namelen>=Pbuffsz)                                      //~vbe0I~
        	namelen=Pbuffsz-1;                                     //~vbe0I~
        UmemcpyZ(Pname,Pdata+namepos,(size_t)namelen);             //~vbe0R~
        UmemcpyZ(Pnamedbcs,Pdbcs+namepos,(size_t)namelen);         //~vbe0R~
    }                                                              //~vbe0I~
    *Ppposnext=posnext;                                            //~vbe0I~
    *Ppnamelen=namelen;                                            //~vbe0I~
    return type;                                                   //~vbe0I~
}//getxmltype                                                      //~vbe0I~
//*************************************************************************//~vbe0I~
int xml_gettypename(int Popt,char *Pdata,char *Pdbcs,int Plen,int Poffs,//~vbe0I~
		char *Pname,char *Pnamedbcs,int Pbuffsz,int *Ppposnext,int *Ppnamelen,int *Ppdest,//~vbe0R~
        int *Ppsrcpos,int *Ppsrclen,char *Psrchword)               //~vbe0I~
{                                                                  //~vbe0I~
	int type,namelen=0,nextpos,dest=0,srcpos=0,srclen=0;           //~vbe0I~
//******************************************                       //~vbe0I~
    type=getxmltype(Popt,Pdata,Pdbcs,Plen,Poffs,Pname,Pnamedbcs,Pbuffsz,&nextpos,&namelen);   //word following//~vbe0R~
    *Psrchword=0;                                                  //~vbe0I~
    switch (type)                                                  //~vbe0I~
    {                                                              //~vbe0I~
	case XMLT_START:      //1:<xxx> ,srch  </xxx> forward          //~vbe0I~
    	srcpos=Poffs;                                              //~vbe0I~
    	srclen=namelen+2;                                          //~vbe0I~
        sprintf(Psrchword,"</%s>",Pname);                          //~vbe0I~
        dest=1;                                                    //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_STARTATTR:  //2:<xxx ...> , srch </xxx> or </> forward//~vbe0I~
    	srcpos=Poffs;                                              //~vbe0I~
    	srclen=namelen+1;                                          //~vbe0I~
        sprintf(Psrchword,"</%s>",Pname);  //for errmsg            //~vbe0R~
        dest=1;                                                    //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_STARTCMT:   //3:"<!--"   , srch "-->" forward        //~vbe0I~
    	srcpos=Poffs;                                              //~vbe0I~
    	srclen=4;                                                  //~vbe0I~
        strcpy(Psrchword,"-->");                                   //~vbe0I~
        dest=1;                                                    //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_STARTOTHER:  //4:     //<! but not <--, <? ,srch ">" forward//~vbe0R~
    	srcpos=Poffs;                                              //~vbe0I~
    	srclen=2;                                                  //~vbe0I~
        strcpy(Psrchword,">");                                     //~vbe0I~
        dest=1;                                                    //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_END:        //5:</xxx> , srch <xxx> or <xxx ... backword//~vbe0R~
    	srcpos=Poffs;                                              //~vbe0I~
    	srclen=namelen+3;                                          //~vbe0I~
        sprintf(Psrchword,"<%s",Pname); //for errmsg,srch is done by name//~vbe0R~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_CLOSEATTR:  //6:"/>"  csr on  ">" , srch "<" backward//~vbe0R~
	    srcpos=Poffs-1;                                            //~vbe0I~
    	srclen=2;                                                  //~vbe0I~
        strcpy(Psrchword,"<");                                     //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_CLOSEATTR2: //9:"/>"  csr on "/"  , srch "<" backward//~vbe0I~
	    srcpos=Poffs;                                              //~vbe0I~
    	srclen=2;                                                  //~vbe0I~
        strcpy(Psrchword,"<");                                     //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        type=XMLT_CLOSEATTR;                                       //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_ENDCMT:     //7:"-->"   , srch "<!--" backward       //~vbe0R~
	    srcpos=Poffs-2;                                            //~vbe0I~
    	srclen=3;                                                  //~vbe0I~
        strcpy(Psrchword,"<!--");                                  //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_ENDCMT2:     //10:"-->"  csr on 1st "-" , srch "<!--" backward//~vbe0I~
	    srcpos=Poffs;                                              //~vbe0I~
    	srclen=3;                                                  //~vbe0I~
        strcpy(Psrchword,"<!--");                                  //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        type=XMLT_ENDCMT;                                          //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_ENDCMT3:     //10:"-->"  csr on 2nd "-" , srch "<!--" backward//~vbe0R~
	    srcpos=Poffs-1;                                            //~vbe0I~
    	srclen=3;                                                  //~vbe0I~
        strcpy(Psrchword,"<!--");                                  //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        type=XMLT_ENDCMT;                                          //~vbe0I~
        break;                                                     //~vbe0I~
	case XMLT_CLOSEOTHER:  //8:       //">" but not "/>",srch "<" backward//~vbe0R~
	    srcpos=Poffs;                                              //~vbe0I~
    	srclen=1;                                                  //~vbe0I~
        strcpy(Psrchword,"<");                                     //~vbe0I~
        dest=-1;                                                   //~vbe0I~
        nextpos=srcpos;                                            //~vbe0I~
        break;                                                     //~vbe0I~
    }                                                              //~vbe0I~
    *Ppdest=dest;                                                  //~vbe0I~
    *Ppposnext=nextpos;                                            //~vbe0I~
    *Ppnamelen=namelen;                                            //~vbe0I~
    *Ppsrcpos=srcpos;                                              //~vbe0I~
    *Ppsrclen=srclen;                                              //~vbe0I~
    return type;                                                   //~vbe0I~
}//xml_gettypename                                                 //~vbe0I~
//**************************************************************** //~vbe0M~
// xmlsrchword                                                     //~vbe0R~
// xml keyword search                                              //~vbe0I~
//**************************************************************** //~vbe0M~
int xmlsrchwordsub(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pdest,//~vbe0R~
		char *Psrch,char *Psrchdbcs,int Psrchlen)                  //~vbe0R~
{                                                                  //~vbe0M~
	int offs,rc,len;                                               //~vbe0R~
    char *pc,*pc2;                                                 //~vbe0R~
    PULINEH plh,plh0;                                              //~vbe0I~
	int swutf8file;                                                //~vbe0I~
//**************************************                           //~vbe0I~
	plh=plh0=*Ppplh;                                               //~vbe0I~
	swutf8file=PLHUTF8MODE(plh);                                   //~vbe0I~
    offs=*Ppoffset;                                                //~vbe0I~
	if (Pdest<0)                                                   //~vbe0I~
	{                                                              //~vbe0I~
        for (;plh;plh=UGETQPREV(plh))                              //~vbe0I~
        {                                                          //~vbe0I~
            if (plh->ULHtype!=ULHTDATA)                            //~vbe0I~
                continue;                                          //~vbe0I~
	    	if (!plh->ULHdbcs)                                     //~vbe0I~
            {                                                      //~vbe0I~
            	rc=filechktabdbcs(plh); //expand tab               //~vbe0I~
            	if (rc==UALLOC_FAILED)                             //~vbe0I~
                	return UALLOC_FAILED;                          //~vbe0I~
            }                                                      //~vbe0I~
            pc=plh->ULHdata;                                       //~vbe0I~
            if (plh==plh0)                                         //~vbe0I~
                len=offs;                                          //~vbe0I~
            else                                                   //~vbe0I~
                len=plh->ULHlen;                                   //~vbe0I~
            pc2=UTF_umemrmem(swutf8file,pc,plh->ULHdbcs,Psrch,Psrchdbcs,len,Psrchlen);//~vbe0R~
            if (pc2)                                               //~vbe0R~
            {                                                      //~vbe0I~
                offs=PTRDIFF(pc2,pc);                              //~vbe0R~
                break;                                             //~vbe0R~
            }                                                      //~vbe0I~
        }//all plh                                                 //~vbe0I~
	}//prev                                                        //~vbe0I~
	else			//forward                                      //~vbe0I~
	{				//next                                         //~vbe0I~
        for (;plh;plh=UGETQNEXT(plh),offs=0)                       //~vbe0I~
        {                                                          //~vbe0I~
            if (plh->ULHtype!=ULHTDATA)                            //~vbe0I~
                continue;                                          //~vbe0I~
	    	if (!plh->ULHdbcs)                                     //~vbe0I~
            {                                                      //~vbe0I~
            	rc=filechktabdbcs(plh); //expand tab               //~vbe0I~
            	if (rc==UALLOC_FAILED)                             //~vbe0I~
                	return UALLOC_FAILED;                          //~vbe0I~
            }                                                      //~vbe0I~
            pc=plh->ULHdata+offs;                                  //~vbe0R~
            len=plh->ULHlen-offs;                                  //~vbe0R~
          	if (len>0)  //for safety                               //~vbe0R~
            {                                                      //~vbe0R~
	            pc2=UTF_umemmem(swutf8file,pc,plh->ULHdbcs+offs,Psrch,Psrchdbcs,len,Psrchlen);//~vbe0R~
                if (pc2)                                           //~vbe0R~
                {                                                  //~vbe0I~
        	    	offs+=PTRDIFF(pc2,pc);                         //~vbe0R~
                	break;                                         //~vbe0I~
                }                                                  //~vbe0I~
            }                                                      //~vbe0I~
        }//all plh                                                 //~vbe0I~
    }//prev/next                                                   //~vbe0I~
    if (!plh)                                                      //~vbe0I~
    	return 4;                                                  //~vbe0I~
    *Ppplh=plh;                                                    //~vbe0I~
    *Ppoffset=offs;                                                //~vbe0I~
    return 0;                                                      //~vbe0I~
}//xmlsrchwordsub                                                  //~vbe0R~
//**************************************************************** //~vbe0I~
//*rc 0:not in comment,1:incomment                                 //~vbe0I~
//*set startPLH if dest =-1,else endPLH                            //~vbe0I~
//*output is optional                                              //~vbe0I~
//**************************************************************** //~vbe0I~
int xmlchkcomment(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Poffs,int Pdest,PULINEH *Ppplh,int *Ppoffs)//~vbe0I~
{                                                                  //~vbe0I~
	int offs1,offs2,rc;                                            //~vbe0R~
    PULINEH plh1,plh2;                                             //~vbe0R~
//**************************************                           //~vbe0I~
    plh1=Pplh;                                                     //~vbe0I~
    offs1=Poffs;                                                   //~vbe0I~
    rc=xmlsrchwordsub(Popt,Ppcw,&plh1,&offs1,-1,"<!--",0/*dbcs*/,4);//~vbe0R~
    if (rc)                                                        //~vbe0I~
    	return 0;                                                  //~vbe0I~
    plh2=plh1;                                                     //~vbe0R~
    offs2=offs1+4;                                                 //~vbe0R~
    rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs2,1,"-->",0/*dbcs*/,3); //~vbe0R~
    if (rc)                                                        //~vbe0I~
    	return 0;	//no cmt terminator,in comment                 //~vbe0R~
    if (plh2->ULHlinenor<Pplh->ULHlinenor)   //cmd end after current plh//~vbe0I~
    	return 0;                                                  //~vbe0I~
    if (plh2->ULHlinenor==Pplh->ULHlinenor && plh2->ULHsuffix<Pplh->ULHsuffix)//~vbe0I~
    	return 0;                                                  //~vbe0I~
    if (plh2->ULHlinenor==Pplh->ULHlinenor && plh2->ULHsuffix==Pplh->ULHsuffix && offs2<Poffs)//~vbe0R~
    	return 0;                                                  //~vbe0I~
    if (Pdest<0)                                                   //~vbe0R~
    {                                                              //~vbe0R~
	    if (Ppplh)                                                 //~vbe0I~
            *Ppplh=plh1;                                           //~vbe0R~
	    if (Ppoffs)                                                //~vbe0I~
            *Ppoffs=offs1;                                         //~vbe0R~
    }                                                              //~vbe0R~
    else                                                           //~vbe0R~
    {                                                              //~vbe0R~
	    if (Ppplh)                                                 //~vbe0I~
            *Ppplh=plh2;                                           //~vbe0R~
	    if (Ppoffs)                                                //~vbe0I~
            *Ppoffs=offs2+3;                                       //~vbe0R~
    }                                                              //~vbe0R~
    return 1;                                                      //~vbe0I~
}//xmlchkcomment                                                   //~vbe0I~
//**************************************************************** //~vbe0I~
// xmlsrchtagnest                                                  //~vbe0R~
//    case XMLT_STARTOTHER:  //4:     <! but not <!--, <? ,srch ">" forward//~vbe0I~
//    case XMLT_CLOSEATTR:   //6:     "/>"   , srch "<" backword   //~vbe0I~
//    case XMLT_CLOSEOTHER:  //8:     ">" but not   "/>",srch "<" back srch//~vbe0I~
//rc:0 found,3:in comment,4:notfound                               //~vbe0I~
//**************************************************************** //~vbe0I~
int xmlsrchtagnest(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pdest,//~vbe0I~
		int Ptype,int *Ppfoundlen)                                 //~vbe0I~
{                                                                  //~vbe0I~
    int offs,offs2,offs3,rc,foundlen=0;                            //~vbe0R~
    PULINEH plh,plh2,plh3;                                         //~vbe0I~
//**************************************                           //~vbe0I~
	plh=*Ppplh;                                                    //~vbe0I~
	offs=*Ppoffset;                                                //~vbe0I~
	plh=*Ppplh;                                                    //~vbe0I~
	if (Pdest<0)        //  "/>" ,back srch "<" , ">" ,back srch "<"//~vbe0I~
	{                                                              //~vbe0I~
        for (;plh;)                                                //~vbe0I~
        {                                                          //~vbe0I~
            plh2=plh;                                              //~vbe0I~
            offs2=offs;                                            //~vbe0I~
            rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs2,Pdest,"<",0/*dbcs*/,1);//~vbe0R~
            if (rc)                                                //~vbe0I~
                return 4;                                          //~vbe0I~
	    	rc=xmlchkcomment(Popt,Ppcw,plh2,offs2,Pdest,&plh3,&offs3);//~vbe0I~
            if (rc)                                                //~vbe0I~
            {                                                      //~vbe0I~
            	plh=plh3;                                          //~vbe0I~
                offs=offs3;                                        //~vbe0I~
                continue;                                          //~vbe0I~
            }                                                      //~vbe0I~
            plh=plh2;                                              //~vbe0I~
            offs=offs2;                                            //~vbe0I~
            foundlen=1;                                            //~vbe0I~
            break;                                                 //~vbe0I~
        }//nest loop                                               //~vbe0I~
	}//prev                                                        //~vbe0I~
	else			// <!xx, <? forward srch ">"                   //~vbe0I~
	{                                                              //~vbe0I~
        for (;plh;)                                                //~vbe0I~
        {                                                          //~vbe0I~
            plh2=plh;                                              //~vbe0I~
            offs2=offs;                                            //~vbe0I~
            rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs2,Pdest,">",0/*dbcs*/,1);//~vbe0R~
            if (rc)                                                //~vbe0I~
                return 4;                                          //~vbe0I~
            rc=xmlchkcomment(Popt,Ppcw,plh2,offs2,Pdest,&plh3,&offs3);//~vbe0I~
            if (rc)                                                //~vbe0I~
            {                                                      //~vbe0I~
                plh=plh3;                                          //~vbe0I~
                offs=offs3;                                        //~vbe0I~
                continue;                                          //~vbe0I~
            }                                                      //~vbe0I~
            plh=plh2;                                              //~vbe0I~
            offs=offs2;                                            //~vbe0I~
            foundlen=1;                                            //~vbe0I~
            break;                                                 //~vbe0I~
        }//nest loop                                               //~vbe0I~
    }//prev/next                                                   //~vbe0I~
    if (!plh)                                                      //~vbe0I~
    	return 4;                                                  //~vbe0I~
    *Ppplh=plh;                                                    //~vbe0I~
    *Ppoffset=offs;                                                //~vbe0I~
    *Ppfoundlen=foundlen;                                          //~vbe0I~
    return 0;                                                      //~vbe0I~
}//xmlsrchtagnest                                                  //~vbe0R~
//**************************************************************** //~vbe0M~
//rc:1 partial name,0 enclosed by punctuation                      //~vbe0M~
//**************************************************************** //~vbe0M~
int xmlchkpartialname(int Popt,PULINEH Pplh,int Poffs,int Pnamelen)//~vbe0I~
{                                                                  //~vbe0M~
	char *pc,*pcd;                                                 //~vbe0M~
    int len,offs;                                                  //~vbe0R~
//***********************                                          //~vbe0M~
    pc=Pplh->ULHdata;                                              //~vbe0M~
    pcd=Pplh->ULHdbcs;                                             //~vbe0M~
    len=Pplh->ULHlen;                                              //~vbe0M~
    offs=Poffs+Pnamelen;                                           //~vbe0I~
    if (offs>0 && offs<len)                                        //~vbe0I~
    {                                                              //~vbe0M~
        if (*(pcd+offs)                                            //~vbe0M~
		||  !strchr(XML_DELM_NAME,*(pc+offs))  //     "> \t"       //~vbe0I~
        )                                                          //~vbe0M~
        	return 1; //partial                                    //~vbe0M~
    }                                                              //~vbe0M~
    return 0;                                                      //~vbe0M~
}//xmlchkpartialname                                               //~vbe0M~
//**************************************************************** //~vbe0I~
// xmlsrchwordnest                                                 //~vbe0I~
//    case XMLT_START:      //1:<xxx> ,srch  </xxx> forward        //~vbe0I~
//    case XMLT_STARTATTR:  //2:<xxx ...> , srch </xxx>            //~vbe0I~
//    case XMLT_END:        //5:</xxx> , srch <xxx> backword       //~vbe0I~
//rc:0 found,3:in comment,4:notfound                               //~vbe0I~
//**************************************************************** //~vbe0I~
int xmlsrchwordnest(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pdest,//~vbe0I~
		int Ptype,char *Pname,char *Pnamedbcs,int Pnamelen,char *Psrch,int Psrchlen,int *Ppfoundlen)//~vbe0R~
{                                                                  //~vbe0I~
    int offs,offs2,offs3,rc,foundlen=0,nestctr;                    //~vbe0R~
    PULINEH plh,plh2,plh3;                                         //~vbe0R~
//**************************************                           //~vbe0I~
	plh=*Ppplh;                                                    //~vbe0R~
	offs=*Ppoffset;                                                //~vbe0R~
	plh=*Ppplh;                                                    //~vbe0I~
	if (Pdest<0)        // </xxx>  :XMLT_END                       //~vbe0R~
	{                                                              //~vbe0I~
        nestctr=1;                                                 //~vbe0R~
        for (;plh;)                                                //~vbe0I~
        {                                                          //~vbe0I~
            plh2=plh;                                              //~vbe0I~
            offs2=offs;                                            //~vbe0I~
            rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs2,Pdest,Pname,Pnamedbcs,Pnamelen);//~vbe0R~
            if (rc)                                                //~vbe0I~
                return 4;                                          //~vbe0I~
            if (xmlchkpartialname(Popt,plh2,offs2,Pnamelen))       //~vbe0I~
            {                                                      //~vbe0I~
                plh=plh2;                                          //~vbe0I~
                offs=offs2;                                        //~vbe0I~
                continue;                                          //~vbe0I~
            }                                                      //~vbe0I~
	    	rc=xmlchkcomment(Popt,Ppcw,plh2,offs2,Pdest,&plh3,&offs3);//~vbe0R~
            if (rc)                                                //~vbe0I~
            {                                                      //~vbe0I~
            	plh=plh3;                                          //~vbe0I~
                offs=offs3;                                        //~vbe0I~
                continue;                                          //~vbe0I~
            }                                                      //~vbe0I~
            if (offs2>0 && *(plh2->ULHdata+offs2-1)==XML_TAGT && !*(plh2->ULHdbcs+offs2-1)//~vbe0I~
            &&  offs2>1 && *(plh2->ULHdata+offs2-2)==XML_TAG1 && !*(plh2->ULHdbcs+offs2-2)// "</"//~vbe0R~
            )         //</xxx                                      //~vbe0I~
            {                                                      //~vbe0I~
                nestctr++;                                         //~vbe0R~
                plh=plh2;                                          //~vbe0R~
                offs=offs2-2;                                      //~vbe0R~
                continue;                                          //~vbe0I~
            }                                                      //~vbe0I~
            if (offs2>0 && *(plh2->ULHdata+offs2-1)==XML_TAG1 && !*(plh2->ULHdbcs+offs2-1)) // <xxx//~vbe0I~
            {                                                      //~vbe0I~
                offs3=offs2;                                       //~vbp2I~
                plh3=plh2;                                         //~vbp2I~
	            rc=xmlsrchwordsub(Popt,Ppcw,&plh3,&offs3,1/*dest:forward*/,">",0/*dbcs*/,1/*srchwordlen*/);//~vbp2R~
              if (!rc && offs3>0 && *(plh3->ULHdata+offs3-1)==XML_TAGT && !*(plh3->ULHdbcs+offs3-1)) // "/>"//~vbp2R~
                ;  //it is closed like <xxx ... />                 //~vbp2I~
              else                                                 //~vbp2I~
                nestctr--;                                         //~vbe0I~
                if (!nestctr)                                      //~vbe0I~
                {                                                  //~vbe0I~
                	plh=plh2;                                      //~vbe0R~
                	offs=offs2-1;                                  //~vbe0R~
                    foundlen=Pnamelen+1;                           //~vbe0I~
                    if ((offs+foundlen)<plh->ULHlen && *(plh->ULHdata+offs+foundlen)==XML_TAG2//~vbe0I~
                    &&  !*(plh->ULHdbcs+offs+foundlen))            //~vbe0I~
                    	foundlen++;                                //~vbe0I~
                    break;                                         //~vbe0I~
                }                                                  //~vbe0I~
            }                                                      //~vbe0I~
            plh=plh2;                                              //~vbe0I~
            offs=offs2;                                            //~vbe0R~
        }//nest loop                                               //~vbe0I~
	}//prev                                                        //~vbe0I~
	else			//<xxx>:XMLT_START, <xxx ...>:XMT_STARTATTR    //~vbe0R~
	{			                                                   //~vbe0I~
    	for (;;)                                                   //~vbe0I~
        {                                                          //~vbe0I~
            if (Ptype==XMLT_STARTATTR) //at first srch ">"//2:<xxx ...> , srch </xxx>//~vbe0I~
            {                                                      //~vbe0I~
                rc=xmlsrchwordsub(Popt,Ppcw,&plh,&offs,Pdest,">",0/*dbcs*/,1);//~vbe0R~
                if (rc)                                            //~vbe0I~
                    return 4;                                      //~vbe0R~
                if (offs>0 && *(plh->ULHdata+offs-1)==XML_TAGT && !*(plh->ULHdbcs+offs-1)) // "/>"//~vbe0I~
                {                                                  //~vbe0I~
                	foundlen=2;                                    //~vbe0I~
                    offs--;                                        //~vbe0I~
                    break;                                         //~vbe0I~
                }                                                  //~vbe0I~
                offs++;                                            //~vbe0I~
            }                                                      //~vbe0I~
            nestctr=1;                                             //~vbe0I~
            for (;plh;)                                            //~vbe0I~
            {                                                      //~vbe0I~
                plh2=plh;                                          //~vbe0I~
                offs2=offs;                                        //~vbe0I~
                rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs2,Pdest,Pname,Pnamedbcs,Pnamelen);//~vbe0R~
                if (rc)                                            //~vbe0I~
                    return 4;                                      //~vbe0I~
                if (xmlchkpartialname(Popt,plh2,offs2,Pnamelen))   //~vbe0I~
                {                                                  //~vbe0I~
                	plh=plh2;                                      //~vbe0I~
                    offs=offs2+Pnamelen;                           //~vbe0I~
                	continue;                                      //~vbe0I~
                }                                                  //~vbe0I~
                rc=xmlchkcomment(Popt,Ppcw,plh2,offs2,Pdest,&plh3,&offs3);//~vbe0I~
                if (rc)                                            //~vbe0I~
                {                                                  //~vbe0I~
                    plh=plh3;                                      //~vbe0I~
                    offs=offs3+Pnamelen;                           //~vbe0I~
                    continue;                                      //~vbe0I~
                }                                                  //~vbe0I~
                if (offs2>0 && *(plh2->ULHdata+offs2-1)==XML_TAGT && !*(plh2->ULHdbcs+offs2-1)//~vbe0I~
                &&  offs2>1 && *(plh2->ULHdata+offs2-2)==XML_TAG1 && !*(plh2->ULHdbcs+offs2-2)//~vbe0I~
                )         //</xxx                                  //~vbe0I~
                {                                                  //~vbe0I~
                	nestctr--;                                     //~vbe0I~
                    if  (!nestctr)                                 //~vbe0I~
                    {                                              //~vbe0I~
                		plh=plh2;	                               //~vbe0I~
                		offs=offs2-2;                              //~vbe0R~
                    	foundlen=Pnamelen+3;                       //~vbe0I~
                    	break;                                     //~vbe0I~
                    }                                              //~vbe0I~
                }                                                  //~vbe0I~
                else                                               //~vbe0I~
                if (offs2>0 && *(plh2->ULHdata+offs2-1)==XML_TAG1 && !*(plh2->ULHdbcs+offs2-1)) // <xxx//~vbe0I~
                {                                                  //~vbp2I~
                	offs3=offs2;                                   //~vbp2I~
	                rc=xmlsrchwordsub(Popt,Ppcw,&plh2,&offs3,Pdest,">",0/*dbcs*/,1/*srchwordlen*/);//~vbp2R~
                	if (rc)                                        //~vbp2I~
                    	return 4;                                  //~vbp2I~
                	if (offs3>0 && *(plh2->ULHdata+offs3-1)==XML_TAGT && !*(plh2->ULHdbcs+offs3-1)) // "/>"//~vbp2R~
                    	;                                          //~vbp2I~
                    else                                           //~vbp2I~
                    	nestctr++;                                     //~vbe0I~//~vbp2R~
                }                                                  //~vbp2I~
                plh=plh2;                                          //~vbe0I~
                offs=offs2+Pnamelen;                               //~vbe0R~
            }//nest loop                                           //~vbe0I~
            break;                                                 //~vbe0I~
        }//break loop                                              //~vbe0I~
    }//prev/next                                                   //~vbe0I~
    if (!plh)                                                      //~vbe0I~
    	return 4;                                                  //~vbe0I~
    *Ppplh=plh;                                                    //~vbe0I~
    *Ppoffset=offs;                                                //~vbe0R~
    *Ppfoundlen=foundlen;                                          //~vbe0I~
    return 0;                                                      //~vbe0R~
}//xmlsrchwordnest                                                 //~vbe0R~
//**************************************************************** //~vbe0I~
// xmlsrchword                                                     //~vbe0I~
//**************************************************************** //~vbe0I~
int xmlsrchword(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Pdest,//~vbe0I~
		int Ptype,char *Pname,char *Pnamedbcs,int Pnamedlen,char *Psrch,int Psrchlen,int *Ppfoundlen)//~vbe0R~
{                                                                  //~vbe0I~
    int offs,foundlen,rc=0;                                        //~vbe0R~
    PULINEH plh;                                                   //~vbe0I~
//**************************************                           //~vbe0I~
	plh=*Ppplh;                                                    //~vbe0I~
	offs=*Ppoffset;                                                //~vbe0I~
	switch(Ptype)                                                  //~vbe0I~
    {                                                              //~vbe0I~
	case XMLT_STARTOTHER:  //4:     <! but not <!--, <? ,srch ">" forward//~vbe0R~
	case XMLT_CLOSEATTR:   //6:     "/>"   , srch "<" backword     //~vbe0R~
	case XMLT_CLOSEOTHER:  //8:     ">" but not "/>",srch "<"      //~vbe0R~
		rc=xmlsrchtagnest(Popt,Ppcw,&plh,&offs,Pdest,Ptype,&foundlen);//~vbe0R~
        break;                                                     //~vbe0I~
	case XMLT_STARTCMT:   //3:"<!--"   , srch "-->" forward        //~vbe0I~
	case XMLT_ENDCMT:     //7:"-->"   , srch "<!--" backword       //~vbe0I~
		rc=xmlsrchwordsub(Popt,Ppcw,&plh,&offs,Pdest,Psrch,0/*dbcs*/,Psrchlen);//~vbe0R~
        foundlen=Psrchlen;                                         //~vbe0I~
        break;                                                     //~vbe0I~
    default:                                                       //~vbe0I~
//    case XMLT_START:      //1:<xxx> ,srch  </xxx> forward        //~vbe0I~
//    case XMLT_STARTATTR:  //2:<xxx ...> , srch </xxx>            //~vbe0I~
//    case XMLT_END:        //5:</xxx> , srch <xxx> backword       //~vbe0I~
		rc=xmlsrchwordnest(Popt,Ppcw,&plh,&offs,Pdest,Ptype,Pname,Pnamedbcs,Pnamedlen,Psrch,Psrchlen,&foundlen);//~vbe0R~
    }                                                              //~vbe0I~
    if (rc)                                                        //~vbe0R~
    	return 4;                                                  //~vbe0I~
    *Ppplh=plh;                                                    //~vbe0I~
    *Ppoffset=offs;                                                //~vbe0I~
    *Ppfoundlen=foundlen;                                          //~vbe0I~
    return 0;                                                      //~vbe0I~
}//xmlsrchword                                                     //~vbe0I~
//*************************************************************************//~vbe0M~
//*                                                                //~vbe0M~
//*************************************************************************//~vbe0M~
int xmlsrchsub(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Poffs,int Pdest,//~vbe0R~
		int Ptype,char *Pname,char *Pnamedbcs,int Pnamelen,int Ppossrc,int Plensrc,char *Psrchword)//~vbe0R~
{                                                                  //~vbe0M~
	int offset,rc,width,srchlen,scrollsz,wordlen;                  //~vbe0R~
    int locatesw;                                                  //~vbe0R~
    PULINEH plh;                                                   //~vbe0M~
    PUFILEH pfh;                                                   //~vbe0M~
    PUFILEC pfc;                                                   //~vbe0M~
//**************************************                           //~vbe0M~
	pfc=Ppcw->UCWpfc;                                              //~vbe0M~
	pfh=pfc->UFCpfh;                                               //~vbe0M~
	plh=Pplh;                                                      //~vbe0M~
	offset=Poffs;                                                  //~vbe0R~
    srchlen=(int)strlen(Psrchword);                                //~vbe0I~
	rc=xmlsrchword(Popt,Ppcw,&plh,&offset,Pdest,Ptype,Pname,Pnamedbcs,Pnamelen,Psrchword,srchlen,&wordlen);//~vbe0R~
    if (rc)                                                        //~vbe0M~
    {                                                              //~vbe0M~
    	uerrmsg("No corresponding for %s found",                   //~vbe0M~
				"%s が見つかりません",                             //~vbe0M~
                Psrchword);                                        //~vbe0R~
        return 4;                                                  //~vbe0M~
    }                                                              //~vbe0M~
	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                     //~vbe0M~
    {                                                              //~vbe0M~
        UPCTRREQ(pfh);                                             //~vbe0M~
		if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)	//display excluded line//~vbe0M~
        	return UALLOC_FAILED;                                  //~vbe0M~
    	UPCTRREQ(pfh);                                             //~vbe0M~
	}                                                              //~vbe0M~
//*move page to the line if not on current page                    //~vbe0M~
	fcmdscrollpagemid(Ppcw,plh);                                   //~vbe0M~
	width=Ppcw->UCWwidth-Ppcw->UCWlinenosz;                        //~vbe0M~
	if (offset<pfc->UFCleft                                        //~vbe0M~
	|| 	offset>=pfc->UFCleft+width)                                //~vbe0M~
    {                                                              //~vbe0M~
    	 scrollsz=filehalfhscrollsz(Ppcw);//half scroll size       //~vbe0M~
         pfc->UFCleft=max(0,(offset/scrollsz)*scrollsz-scrollsz);  //~vbe0M~
         UCBITON(Ppcw->UCWflag,UCWFDRAW);                          //~vbe0M~
    }                                                              //~vbe0M~
	filesetcsr(Ppcw,plh,1,offset-pfc->UFCleft);//csr set           //~vbe0M~
    locatesw=1;                                                    //~vbe0I~
    locatesw|=FCMDSFHOPT_NOMULTIREV;        //reset multiple reverse//~vbe0M~
    fcmdsetfindhighlight(pfh,Pplh,locatesw,0, 	//1:locate,0:no linesrch//~vbe0M~
			Ppossrc,Plensrc,0);			//no span ;first char      //~vbe0I~
    fcmdsetfindhighlight(pfh,plh,FCMDSFHOPT_NOMULTIREV,0, 	//0:no locate,0:no linesrch//~vbe0M~
    		offset,wordlen,0);			//no span                  //~vbe0I~
	return 0;                                                      //~vbe0M~
}//xmlsrchsub                                                      //~vbe0R~
//**************************************************************** //~vbe0I~
// xml tag search                                                  //~vbe0I~
//*rc   :                                                          //~vbe0I~
//**************************************************************** //~vbe0I~
int func_xmlsrch(PUCLIENTWE Ppcw)                                  //~vbe0I~
{                                                                  //~vbe0I~
    PUFILEH pfh;                                                   //~vbe0I~
    PULINEH plh;                                                   //~vbe0I~
    PUFILEC pfc;                                                   //~vbe0I~
	PUSCRD psd;                                                    //~vbe0I~
	int offset;                                                    //~vbe0I~
    int lrecl;                                                     //~vbe0R~
    int rc,namelen,type,dest,srcpos,srclen,posnext;                //~vbe0R~
	UCHAR *pdata;                                                  //~vbe0I~
	UCHAR *pdbcs;                                                  //~vbe0I~
    char name[MAX_ELEMENT_NAME];                                   //~vbe0I~
    char namedbcs[MAX_ELEMENT_NAME];                               //~vbe0I~
    char srchword[MAX_ELEMENT_NAME+8];                             //~vbe0I~
//*********************************                                //~vbe0I~
	pfc=Ppcw->UCWpfc;                                              //~vbe0I~
	pfh=pfc->UFCpfh;                                               //~vbe0I~
    if (PFH_ISEBC(pfh))                                            //~vbe0I~
    {                                                              //~vbe0I~
    	uerrmsg("Ebcdic file is not supported",0);                 //~vbe0R~
        return 4;                                                  //~vbe0I~
    }                                                              //~vbe0I~
	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~vbe0I~
    {                                                              //~vbe0I~
    	uerrmsg("XML tag search is not supported for binary file", //~vbe0R~
        		"バイナリーファイルはXMLタグ探索できません。");    //~vbe0R~
        return 4;                                                  //~vbe0I~
    }                                                              //~vbe0I~
	if (!CSRONFILEDATA(Ppcw))	//chk csr on file line             //~vbe0R~
   		return errcsrpos();				//not on file client area  //~vbe0I~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~vbe0I~
    offset=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;          //~vbe0I~
	plh=psd->USDbuffc;                                             //~vbe0I~
    pdata=plh->ULHdata;                                            //~vbe0I~
    pdbcs=plh->ULHdbcs;                                            //~vbe0I~
    lrecl=plh->ULHlen;                                             //~vbe0I~
    if (offset>=lrecl)                                             //~vbe0I~
    	return errcsrpos();			//no filedata                  //~vbe0I~
    if (plh->ULHtype!=ULHTDATA)                                    //~vbe0I~
        return errcsrpos();                                        //~vbe0I~
	type=xml_gettypename(0,pdata,pdbcs,lrecl,offset,name,namedbcs,(int)sizeof(name),&posnext,&namelen,&dest,//~vbe0R~
					&srcpos,&srclen,srchword);                     //~vbe0R~
    if (type<=0)                                                   //~vbe0R~
    {                                                              //~vbe0I~
    	uerrmsg("Invalid cursor position for XML pair tag search", //~vbe0R~
        		"カー\x83\\ル位置の文字は XML タグ探索対象外です");//~vbe0I~
        return 4;                                                  //~vbe0I~
    }                                                              //~vbe0I~
	if (rc=xmlsrchsub(0,Ppcw,plh,posnext,dest,type,name,namedbcs,namelen,srcpos,srclen,srchword),rc)//~vbe0R~
		return rc;                                                 //~vbe0I~
	return 0;                                                      //~vbe0I~
}//func_ppsrch                                                     //~vbe0I~
