//*CID://+vb2DR~:                             update#= 1384;       //~vb2DR~
//*************************************************************
//*xefcmd42.c*                                                     //~v74VR~
//**file cmd:SPLIT,JOIN                                            //~v74VR~
//*************************************************************
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vag9:120823 spl/tf cmd:support hex notation for delm string(\x__).//~vag9I~
//            \x__ is assumed all ascii(no spit inter EBC DBCS/DBCS unicode from UTF8//~vag9I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa5:111017 (BUG of va50)tflow from lcmd did not Space character(EBC or ASCII)//~vaa5I~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8v:101208 (BUG)spl with width+delm dose not split at last delm in the joined line//~va8vI~
//va8u:101205 (BUG)TFLow with TOL;indentation space was re-split to 2 line//~va8uI~
//va8s:101026 (BUG)TFLow:head count for top dbcssplit              //~va8sI~
//va8r:101023 (BUG)SPL/TFL dbcs addressing err when SPACE1 option specified//~va8rI~
//va8q:101020 (BUG)TFLOW: tol delm was appended to prev line(not split line)//~va8qI~//~va8uR~
//va8n:101018 (BUG:TFLOW) remains dup byte when shift occured      //~va8nI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option.(split to fcmd43)//~va8kI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5q:100512 SPL/TFLOW cmd support sbcs utf8 delm char            //~0512I~
//va5i:100510 (BUG) SPLIT cmd;should chk dbcs for utf8             //~va5iI~
//va5h:100510 (BUG) SPLIT cmd;reject tail with strdelm option      //~va5hI~
//va5g:100510 (BUG) SPLIT cmd;dbcs strdelm dose not work           //~va5gI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd42.c:reject SBCS option for utf8 file            //~va20I~
//                     set also plhdbcs                            //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va17:091025 spliterr count err after undo by remained temperrflag(it was set before undoupdate)//~va17I~
//v7ap:090217 TFLOW msg correction if errcount=0                   //~v7apI~
//v77v:080117*xuerpchk(uerrmsg parameter chk)                      //~v77vI~
//v77f:071226*"spl [all] width CRLF" for change display width of text file//~v77fI~
//v76N:070915*(BUG)TFL miss the line with length of parm width     //~v76NI~
//v76L:070913*(BUG)SPL cmd;for margined file,"split by all delm if width is not specified" is not true.//~v76LI~//~va8rR~
//v76K:070913*(BUG)SPL ignore delm for margined file               //~v76KI~
//v76E:070827*(BUG)missing free for malloc                         //~v76ER~
//v76a:070613 renum after split width change for bin file          //~v76aI~
//v769:070613 (BUG of v69B)spl cmd may abend for bin file          //~v769I~
//v761:070529 split tail cmd:del continued line if all space       //~v761I~
//v75L:070510 (BUG)TFLOW null line should be end of paragraph(if set to indentoffs=0,it may be paragrapth line of indentoffs=0)//~v75LI~
//v75B:070430 SPLit cmd:delmstr for EXP;1 byte=padding,2byte=delm+padding,3byte=delm+padding+terminator//~v75BI~
//v75y:070429 TFLOW:reject STRSPACE option                         //~v75yI~
//v75w:070429 TFLOW:NOP is not conflict width Pn;Pn is range NOP ignore paragraph boundary//~v75wI~
//v75v:070429 TFLOW:set line count of processed msg to update count//~v75vI~
//v75u:070428 TFLOW:delete KEEPLINE option(that is same as KEEPWORD)//~v75uI~
//            when no intemediate space on target width,           //~v75uI~
//            AWORD:split at after the word,SWORD:split by the width,else dose not split//~v75uI~
//            fcmd42.c                                             //~v75uI~
//v75t:070427 TFLOW LCMD:assign EACH option to ";" lcmd            //~v75tI~
//v75r:070426 TFLOW:Splitoption default change to BWORD;and always BWORD when 2ndjoin regardress param option//~v75rI~
//v75q:070426 TFLOW:if "." at EOL,inser 2 space                    //~v75qI~
//v75n:070426 TFLOW:delete null line(bnds1=0,bnds2=ulhlen,and srlen=0)//~v75nI~
//v75m:070426 (BUG)TFLOW:updatechk for short src                   //~v75mI~
//v75k:070426 TFLOW:EACH option to insert remaininmg data after each end of paragraph//~v75kI~
//v75j:070425 (BUG)TFLOW:use all data(not limit by width parm) for parag change//~v75jI~
//v75i:070425 (BUG)TFLOW:bnds;do not chk paragraph at save plhdata //~v75iI~
//v75h:070424 TFLOW:p0 option to ignore paragraph(all is all paragrapth)//~v75hI~
//v75g:070423 TFLOW:indentation base is 2nd line as default        //~v75gI~
//v75f:070423 SPL/TFLOW:correct err line counter                   //~v75fI~
//v75e:070421 TFLOW:KWS option(keepword and split at next delm/space if long)//~v75dI~
//v75d:070421 SPLIT:drop TFLOW option from SPLit cmd to reduce number of option for the shake of TFLOW//~v75cI~
//v75c:070419 TFLOW:SPACE1 support                                 //~v75cI~
//v75a:070419 lcmd TFn/":"/";" support                             //~v75aR~
//v759:070419 split cmd;n of Pn for number of paragraph(0 for all paragaraph)//~v759I~
//v758:070418 split cmd;for TFLOW,new option PN(paragraph new),P1(paragraph stop)//~v758I~
//v757:070418 split cmd;for TFLOW use cursor line when no lab specified//~v757I~
//v753:070418 split cmd;option KEEPWORD for TFLOW(split word by target boundary)//~v753R~
//v752:070417 split cmd;add I[n] (indentation) option(TFLOW is ALL only)//~v752I~
//v751:070416 split cmd;BNDS+TFLOW                                 //~v751I~
//v750:070416 split cmd;setdbcs when dbcs split by SBCS option     //~v750I~
//v74Z:070413 split cmd;TFLOW pattern(shrik space at line boundary)//~v74ZI~
//v74Y:070413 split cmd;SPACE1 option(reduce continued space to one space)//~v74YI~
//            accept also when no width and no delm                //~v74YI~
//v74X:070413 split cmd;STRSPACE option(1 split by continued space)//~v74XI~
//v74W:070407 split cmd bnds/margin support                        //~v74VI~
//            new OOM option to ignore margin                      //~v74WI~
//v74V:070407*split xefcmd4 to xefcmd42.c                          //~v74VI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>                                               //~v45xI~
#include <ucalc.h>                                                 //~v62EI~
#include <udbcschk.h>                                              //~v750I~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20R~
#include <ucvebc.h>                                                //~va50I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"        //filerenum                           //~v76aI~
#include "xefile2.h"        //filesetcsr                           //~v17dR~
#include "xefile22.h"        //filesetcsr                          //~v446I~
#include "xefile6.h"		//tab
#include "xefcmd2.h"		                                       //~v47iR~
#include "xefcmd22.h"		//fcmdlabelerr
#include "xefcmd23.h"		//bnds                                 //~v74WI~
#include "xefcmd3.h"                                               //~v165I~
#include "xefcmd4.h"
#include "xefcmd43.h"                                              //~va8kI~
#include "xefcmd6.h"                                               //~v51GI~
#include "xeerr.h"
#include "xelcmd.h"
#include "xelcmd2.h"                                               //~v45xI~
#include "xelcmd4.h"                                               //~v172I~
#include "xeundo.h"
#include "xesub.h"                                                 //~v11NI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va17I~
#endif                                                             //~va1qI~
#include "xefsub.h"                                                //~v47iI~
#include "xefunc.h"                                                //~v17eI~
#include "xecalc2.h"                                               //~v62EI~
#include "xechar12.h"                                              //~v74EI~
#include "xechar2.h"                                               //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//****************************************************************
static int Sindentoffs;                                            //~v74ZI~
static int Sindentoffsbyalldata;                                   //~v75jI~
static int Sindentoffs0;                                           //~v758I~
static int Sindentoffsmax;                                         //~v751I~
static int Sbndsheadcnt;                                           //~v75iI~
static int Smaxparagno;                                            //~v759I~
static int Soldupctr;   		//to chk line is not yet updated   //~v758I~
static int Sbndscontwkwidth; //contwk size for tflow               //~v751R~
static int Soldplhupctr;         //intf between splitspace1 and getindent//~v75cI~
static PULINEH Soldplhupctrplh;                                    //~v75cI~
//static int Sopt2;                                                  //~v77fI~//~va8wR~
#define Sopt2 Gopt2_fc43                                           //~va8wI~
#ifdef UTF8UCS2                                                    //~va20I~
//static int Sswutf8file;		//file is utf8 file                    //~va20I~//~va8kR~
#define Sswutf8file Gswutf8file_fc43                               //~va8kI~
static UCHAR *Sporgdelmstr;                                        //~va5gR~
static UCHAR *Spdelmdbcs;                                          //~va5gI~
static int Sdelmstrlen;                                            //~va5gI~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//static int Sswebcfile;		//file is utf8 file                    //~va50I~//~va8kR~
#define Sswebcfile Gswebcfile_fc43                                 //~va8kI~
static int Shandle;			//ebc translater handle                //~va79I~
//static int Schspace;		//file is utf8 file                    //~va50I~//~va8kR~
#define Schspace  Gchspace_fc43                                    //~va8kI~
//static int Sotheropt;                                              //~va5qI~//~va8wR~
#define Sotheropt  Gotheropt_fc43                                  //~va8wI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************************************** //~v74ZI~
int fcmdcutoff(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2);//~v45xR~
int fcmdsplitbydelm(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v45xI~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth);   //~v45xR~
int fcmdsplitsplit(PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,UCHAR //~v45xR~
					*Pdelmstr,UCHAR *Pcontwk,                      //~v45xI~
					int Psplittype,int *Pperrctr);                 //~v45xR~
int fcmdsplitjoin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v45xR~
					UCHAR *Pdelmstr,UCHAR *Pcontwk,int Pallsw,     //~v45xR~
					int *Ppdonectr,int *Pperrctr);                 //~v45xR~
int fcmdsplitexp(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,//~v45xR~
					int Pwidth,UCHAR *Pdelmstr);                   //~v45xI~
int fcmdsplitlen(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v45xI~
						int Pdatalen,int Pwidth,int *Ppsplitlen);  //~v45xR~
//int fcmdsplitcut(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdemstr);//~v53NR~
//int fcmdsplitcut(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdemstr,int Pwidth);//~v74SR~
int fcmdsplitcut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdemstr,int Pwidth);//~v74SI~
int fcmdjoin(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2,//~v47iI~
                int Pjointype,int Popt);                           //~v47iI~
int fcmdsplitbydelmbnds(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v74WI~
						PULINEH Pplh1,PULINEH Pplh2,UCHAR *Ppcontwk,int Pcontwkwidth,int Pwidth,//~v751R~
                        PULINEH *Ppplh1st,int *Ppdonectr,int *Pperrctr);//~v74WR~
int fcmdsplitbndsgetsrc(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR *Ppdelmstr,PULINEH *Ppplhs,PULINEH Pplh2,int Pwidth,//~v758R~
							int Pbndsoffs1,int Pbndsoffs2,UCHAR *Pcontwk,int Pcontwkwidth,int *Ppplhctrr,int *Ppsrcoffs,int *Ppsrclen,int *Pperrctr,UQUEH *Pqhbnds);//~v751R~
int fcmdsplitbndsgetsrcplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Pplh2,//~v758R~
							int Pwidth,int Pbndsoffs1,int Pbndsoffs2,int *Ppplhctrr,UQUEH *Pqhbnds,int *Pperrctr);//~v751R~
int fcmdsplitbndsupdate(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,     //~v74WR~
						PULINEH Pplh,int Pwidth,int Pbndsoffs1,int Pbndsoffs2,//~v74WM~
                        char *Pcontwk,int Pcontwkwidth,int Psrclen);//~v751R~
int fcmdsplitlenbnds(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v74WI~
					int Pdatalen,int Pwidth,int *Ppsplitlen);      //~v74WI~
int fcmdsplitspace1(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int *Ppdelctr);//~v74YI~
int fcmdtflowjoin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v74ZI~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,int Popt,      //~v74ZI~
					int *Ppdonectr,int *Pperrctr);                 //~v74ZI~
int fcmdtflowjoinsub(int Popt,UCHAR *Ppdelmstr,PULINEH Pplh,PULINEH Pplh2,int *Ppindentoffs,int Pwidth,UCHAR *Pcontdata,UCHAR *Pcontdbcs,int *Ppcontlen,//~v75eR~
							int *Ppcopyedlen);                     //~v74ZI~
int fcmdtflowsplit(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,//~v74ZR~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,int *Pperrctr);//~v74ZR~
int fcmdtflowsplitsub(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Pwidth,//~v74ZR~
                          UCHAR *Pcontdata,UCHAR *Pcontdbcs,int *Ppcontlen,int *Ppcopyedlen);//~v74ZR~
int fcmdtflowindentshift(int Popt,PULINEH Pplh,int Pwidth,UCHAR *Pcontdata,UCHAR *Pcontdbcs,int *Ppnewlen);//~v74ZI~
#ifdef UTF8UCS2                                                    //~va20I~
int fcmdtflowgetindent(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int *Ppshiftcnt);//~va20I~
#else                                                              //~va20I~
int fcmdtflowgetindent(int Popt,PULINEH Pplh,UCHAR *Pdata,int Pdatalen,int *Ppshiftcnt);//~v751R~
#endif                                                             //~va20I~
int fcmdtflowsplitlen(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v75eI~
					int Pdatalen,int Pwidth,int *Ppsplitlen,int *Pplinewilled);//~v75eR~
int fcmdplhpadspace(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Plen);//~v758I~
int fcmdgetparagendplh(int Popt,PULINEH Pplh1,PULINEH *Ppplh2,int Pmaxparagno,int Pbndsoffs1,int Pbndsoffs2);//~v75iR~
int fcmdsplitbydelmbndseach(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v75kI~
						PULINEH Pplh1,PULINEH Pplh2,               //~v75kI~
                        int Pbndsoffs1,int Pbndsoffs2,             //~v75kR~
						UCHAR *Pcontwk,int Pcontwkwidth,int Pwidth,//~v75kI~
                        PULINEH *Ppplh1st,int *Ppdonectr,int *Pperrctr);//~v75kI~
int fcmdchangewidthsub(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,      //~v77fI~
						PULINEH Pplh1,PULINEH Pplh2,UCHAR *Pcontwk,int Pwidth,//~v77fR~
                        int *Ppdonectr,int *Pperrctr);             //~v77fI~
PSPLITWK fcmdsplitbndsjoinedsplit(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,//~va8vI~
					int Pdatalen,int Psplitlen);                   //~va8vI~
//**************************************************************** //~v75aI~
// fcmdtflowlcmd                                                   //~v75aI~
// TFLOW line cmd                                                  //~v75aI~
//**************************************************************** //~v75aI~
int fcmdtflowlcmd(PUCLIENTWE Ppcw,int Pcmdid,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip)//~v75aR~
{                                                                  //~v75aI~
#ifdef DOSDOS                                                      //~v75aI~
    return errnotsupported("TFlow line command","DOS version");    //~v75aI~
#else                                                              //~v76NR~
    PUFILEC pfc;                                                   //~v75aI~
    PUFILEH pfh;                                                   //~v75aI~
    PULINEH plh1,plh2,plhn;                                        //~v75aR~
    int width=0,opt,rc;                                            //~v75aR~
    int bndsoffs1=0,bndsoffs2=0,splittype=1,indentoffs=-1,paragno=0;//~v75wR~
//*********************************                                //~v75aI~
	opt=FCSPL_TFLOW|FCSPL_TFLOWLCMD;                               //~v75aM~
	pfc=Ppcw->UCWpfc;                                              //~v75aI~
    pfh=pfc->UFCpfh;                                               //~v75aI~
#ifdef UTF8UCS2                                                    //~va20R~
	Sswutf8file=FILEUTF8MODE(pfh)!=0;                              //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	Sswebcfile=PFH_ISEBC(pfh);                                     //~va50I~
    if (Sswebcfile)                                                //~vaa5I~
        Schspace=CHAR_EBC_SPACE;                                   //~vaa5I~
    else                                                           //~vaa5I~
        Schspace=' ';                                              //~vaa5I~
	Shandle=pfh->UFHhandle;                                        //~va79I~
    Sotheropt=0;                                                   //~vaa5I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //text file             //~v75aR~
    {                                                              //~v75aI~
    	uerrmsg("support Text File only",                          //~v75aI~
        	    "バイナリーファイルでは使用できません");           //~v75aI~
        return 4;                                                  //~v75aI~
    }                                                              //~v75aI~
    plh1=Pplh1;                                                    //~v75aI~
    plh2=Pplh2;                                                    //~v75aI~
    if (Pcmdid==ULCCMDTFLOWSTR)        //"TF"                      //~v75aI~
    {                                                              //~v75aI~
    	width=Prepeat;	                                           //~v75aI~
        plh2=UGETQEND(&pfh->UFHlineque);//max                      //~v75aR~
        paragno=1;          //process 1 paragraph                  //~v75aI~
    }                                                              //~v75aI~
    else			//":"/";"                                      //~v75aR~
    {                                                              //~v75aI~
        if (Pplh1==Pplh2)   //":[l,m,i]"                           //~v75aR~
        {                                                          //~v75aR~
            if (Prepeat>1)  //line count                           //~v75aI~
            {                                                      //~v75aI~
                if (lcmdgetplhrange(&Pplh1,&plh2,Prepeat+1)==8)    //~v75aR~
                    return 4;                                      //~v75aI~
                paragno=0;  //all paragraph                        //~v75aI~
            }                                                      //~v75aI~
            else                                                   //~v75aI~
            {                                                      //~v75aI~
                plh2=UGETQEND(&pfh->UFHlineque);//max              //~v75aI~
                paragno=1;  //1 paragraph                          //~v75aI~
            }                                                      //~v75aI~
        }                                                          //~v75aR~
        else                //"::[m,i]"                            //~v75aR~
        {                                                          //~v75aR~
            if (plhn=UGETQNEXT(plh2),plhn)  //stopper is next line //~v75aR~
                plh2=plhn;                                         //~v75aR~
            paragno=0;                                             //~v75aI~
        }                                                          //~v75aR~
        if (Pbandle>=0)       //m                                  //~v75aI~
            width=Pbandle;                                         //~v75aI~
        if (Pskip>=0)         //i                                  //~v75aI~
            indentoffs=Pskip;                                      //~v75aI~
	    if (Pcmdid==ULCCMDTFLOWKW)        //";"                    //~v75aI~
        {                                                          //~v75wI~
        	if (paragno!=1)               //linecount or range specified//~v75aI~
//      		paragno=-1;				//ignore paragraph         //~v75wR~
        		paragno=0;				//ignore paragraph         //~v75wI~
        	opt|=FCSPL_TFNOP;                                      //~v75wI~
        }                                                          //~v75wI~
    }                                                              //~v75aI~
                                                                   //~v75aI~
    opt|=FCSPL_KEEPWORD; //defalt keepword for TF cmd              //~v75rR~
                                                                   //~v75aI~
    if (fcmdgetbnds(0,pfh,&bndsoffs1,&bndsoffs2))   //bnds is set  //~v75aI~
    {                                                              //~v75aI~
        opt|=FCSPL_MARGIN;                                         //~v75aI~
        if (bndsoffs2)                                             //~v75aI~
            Sbndscontwkwidth=bndsoffs2;                            //~v75aI~
        else                                                       //~v75aI~
            Sbndscontwkwidth=MAXLINEDATA;                          //~v75aI~
    }                                                              //~v75aI~
    if (!width && bndsoffs2)                                       //~v75aI~
        width=bndsoffs2;                                           //~v75aI~
    if (width && (opt & FCSPL_MARGIN))  //bnds is set              //~v75aI~
        if (width<=bndsoffs1||(bndsoffs2 && width>bndsoffs2))      //~v75aI~
        {                                                          //~v75aI~
            uerrmsg("Width param(%d) is out of margin(%d-%d). OOM option is required to ignore margin setting",//~v75aI~
                    "位置(%d)パラメータがマージン外(%d-%d)です。マージン設定を無視するには OOM オプションが必要",//~v75aI~
                    width,bndsoffs1+1,bndsoffs2);                  //~v75aI~
            return 4;                                              //~v75aI~
        }                                                          //~v75aI~
    if (!width)                                                    //~v75aI~
    {                                                              //~v75aI~
    	uerrmsg("Specify width,or set right boundary by BND cmd",  //~v75aI~
                   "行幅を指定するか、BND コマンドで右境界を設定してください。");//~v75aI~
        return 4;                                                  //~v75aI~
    }                                                              //~v75aI~
	Sindentoffs0=indentoffs;	//requested indentation            //~v75aI~
	Sindentoffs=-1;				//reset indenttation               //~v75aI~
	Smaxparagno=paragno;   		//process n paragraph              //~v75aI~
	Sindentoffsmax=width-bndsoffs1;				//reset indenttation//~v751I~
    rc=fcmdsplitbydelm(splittype|opt,Ppcw,pfh,0,plh1,plh2,width);  //~v75aR~
    return rc;                                                     //~v75aI~
#endif                                                             //~v76NI~
}//fcmdtflowlcmd                                                   //~v75aI~
//**************************************************************** //~v751I~
// func_tflow                                                      //~v751I~
// TFLOW cmd(subset of SPLIT cmd)                                  //~v751I~
//**************************************************************** //~v751I~
int func_tflow(PUCLIENTWE Ppcw)                                    //~v751I~
{                                                                  //~v751I~
#ifdef DOSDOS                                                      //~v751I~
    return errnotsupported("TFlow","DOS version");                 //~v751I~
#else                                                              //~v751I~
    if (!Ppcw->UCWparm)                                            //~v751R~
    if (!CSRONFILELINE(Ppcw))            //not on data line        //~v751I~
    {                                                              //~v757I~
//      uerrmsg("TFL [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [I[n]] [KEEPWORD|KW] [width] ['del-chars'} [.lab1 .lab2]",0);//~v758R~
        uerrmsg("TFL [width] [SBCS] [TOL] [STRDELM] [SPACE1] [In] [ALL|[%s|%s]] [Pn] [%s] [%s|%s] ['del-chars'} [.lab1 .lab2]",0,//~v75yR~
        			PARM_EACHPARAG,                                //~v75kI~
        			PARM_IGNPARAG,                                 //~v75hI~
        			PARM_IBASE1,                                   //~v75gI~
					/*PARM_SPLITEOL,PARM_WORDBEFORE,*/PARM_WORDAFTER,PARM_WORDSPLIT);//~v75uR~
        return 0;                                                  //~v757I~
    }                                                              //~v757I~
    return fcmdsplit(Ppcw);                                        //~v751I~
#endif                                                             //~v751I~
}//func_tflow                                                      //~v751I~
//**************************************************************** //~v45xM~
// fcmdsplit                                                       //~v45xR~
// split cmd                                                       //~v45xM~
// SPLIT {CONT|OVER|ALL|EXP|TAIL} [SBCS] [width] [delm] [.label]   //~v45xR~
//   CONT  :split splitline                                        //~v45xR~
//   OVER  :split splitline and len>width                          //~v45xI~
//   ALL   :split/join all line by width and delm                  //~v45xR~
//   EXP   :expand line up to width                                //~v45xI~
//   TAIL  :cut tail delm char                                     //~v45xI~
//   width :line width if not = /Mnn parm                          //~v45xR~
//   'delm':split delmeter,no default except for CONT              //~v45xI~
//*rc   :0                                                         //~v45xM~
//**************************************************************** //~v45xM~
int fcmdsplit(PUCLIENTWE Ppcw)                                     //~v45xR~
{                                                                  //~v45xM~
#ifdef DOSDOS                                                      //~v50JI~
    return errnotsupported("SPLit","DOS version");                 //~v50JI~
#else                                                              //~v50JI~
static UCHAR *Swordtbl="CONT\0" "ALL\0" "OVER\0" "EXP\0" "SBCS\0"  //~v45xR~
//  					"TAIL\0" "TOL\0" "STRDELM\0" ;             //~v74WR~
    					"TAIL\0" "TOL\0" "STRDELM\0"               //~v74WI~
                        "OOM\0"                                    //~v74WI~
                        "STRSPACE\0"                               //~v74XI~
                        "SPACE1\0"                                 //~v74YI~
                        "\xff\0" //12 "\xff\0"  //"TFLOW\0"        //~v75eR~
                        "\xff\0"  //"KEEPWORD\0"             //13  //~v75dR~
                        "\xff\0" //"KW\0"                    //14  //~v75dR~
//                      "PN\0"                    //15             //~v759R~
                        "\xff\0" //"SW\0"                    //15  //~v75dR~
//                      "P1\0"                    //16             //~v759R~
                        "\xff\0"                  //16             //~v75gI~
                        "\xff\0"                  //17             //~v75hI~
                        "\xff\0"                  //18             //~v75kI~
                        PARM_CRLF "\0"            //19             //~v77fI~
                        ;                                          //~v74WI~
static UCHAR *Swordtbltflow="\xff\0" "ALL\0" "\xff\0" "\xff\0" "SBCS\0"//~v751R~
    					"\xff\0" "TOL\0" "STRDELM\0"  //6,7,8      //~v751R~
                        "\xff\0"                      //9          //~v751R~
//                      "STRSPACE\0"              //10             //~v75yI~
                        "\xff\0"                      //10         //~v75yI~
                        "SPACE1\0"                //11             //~v751I~
                        PARM_WORDAFTER  "\0" //"\xff\0"                  //12//~v75eR~
                        "\xff\0"                       //14        //~v75uI~
                        "\xff\0"                       //14        //~v75uI~
//                      "PN\0"                    //15             //~v759R~
                        PARM_WORDSPLIT "\0"                    //15//~v75eR~
//                      "P1\0"                    //16             //~v759R~
                        PARM_IBASE1   "\0"        //16             //~v75gI~
                        PARM_IGNPARAG "\0"        //17             //~v75hI~
                        PARM_EACHPARAG "\0"       //18             //~v75kI~
                        "\xff\0"                  //19             //~v77fI~
                        ;                                          //~v751I~
    PUFILEC pfc;                                                   //~v45xM~
    PUFILEH pfh;                                                   //~v45xM~
    PULINEH plh1,plh2;                                             //~v45xI~
    UPODELMTBL *podt;                                              //~v45xI~
	PUSCRD 	 psd;                                                  //~v757I~
    int ii,opdno,opid,rc,splittype,delmctr=0,width=0,len,opt=0;    //~v45xR~
	UCHAR *pc,*pdelmstr;                                           //~v45xR~
	UCHAR delmstr[MAXCOLUMN];                                      //~v74XI~
	UCHAR delmstresc[MAXCOLUMN];                                   //~vag9R~
	UCHAR delmddstr[MAXCOLUMN];                                    //~va5gI~
	UCHAR delmdbcs[MAXCOLUMN];                                     //~va5gI~
    int bndsoffs1=0,bndsoffs2=0;                                   //~v74WR~
    int indentoffs=-1;                                             //~v752R~
    int paragno=1;                                                 //~v751R~
	UCHAR *pc2;                                                    //~v752I~
    int tflowcmdsw;                                                //~v751R~
//  int splitopt=0;                                                //~v75eI~
    int paragnosw=0;                                               //~v75kI~
    int widthparmsw=0;                                             //~v76LI~
    int parmcrlfsw=0;                                              //~v77fI~
#ifdef UTF8UCS2                                                    //~va5gI~
	int ddlen;                                                     //~va5gI~
#endif                                                             //~va5gI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5GI~
	int opt2;                                                      //~va5GI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5GI~
	int esclen=0;                                                  //~vag9R~
//*********************************                                //~v45xM~
	tflowcmdsw=(((PFUNCTBL)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_TFLOW);//~v751R~
    opt=FCSPL_KEEPWORD; //defalt keepword for TF cmd               //~v75rR~
  if (!tflowcmdsw)	//split cmd                                    //~v757R~
    if (!(Ppcw->UCWparm))       //operand                          //~v45xM~
    {                                                              //~v45xM~
//      uerrmsg("SPL {CONT | OVER | ALL | EXP | TAIL} [SBCS] [TOL] [STRDELM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v60tR~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v74WR~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v74XR~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM|STRSPACE] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v74YR~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v752R~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL | TFLOW] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [I[n]] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v753R~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL | TFLOW] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [I[n]] [KEEPWORD|KW] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v758R~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL | TFLOW] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [I[n]] [P[n]] [KEEPWORD|KW|SW] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v75dR~
//      uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [OOM] [width] ['del-chars'} [.lab1 .lab2]",0);//~v77fR~
        uerrmsg("SPL [ALL | CONT | OVER | EXP | TAIL] [SBCS] [TOL] [STRDELM|STRSPACE] [SPACE1] [OOM] [width] [CRLF] ['del-chars'} [.lab1 .lab2]",0);//~v77fI~
        return 0;                                                  //~v47iR~
    }                                                              //~v45xM~
	pfc=Ppcw->UCWpfc;                                              //~v45xM~
//  if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v60sR~
//  	return errbrowsemode();                                    //~v60sR~
    pfh=pfc->UFCpfh;                                               //~v45xM~
//  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file              //~v60sR~
//      return fcmdinvalidbinfile();                               //~v60sR~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v60sI~
    {                                                              //~v60sI~
    	if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //text file        //~v60sI~
			return errbrowsemode();                                //~v60sI~
    }                                                              //~v60sI~
#ifdef UTF8UCS2                                                    //~va20R~
	Sswutf8file=FILEUTF8MODE(pfh)!=0;                              //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	Sswebcfile=PFH_ISEBC(pfh);                                     //~va50I~
	Shandle=pfh->UFHhandle;                                        //~va79I~
    Sotheropt=0;                                                   //~va5qI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//  rc=fcmdgetlabparm(Ppcw,&plh1,&plh2,FCGLP_NEXTPLH|FCGLP_SPLITCHK); 	//get next of endplh//~v62HR~
    rc=fcmdgetlabparm(Ppcw,0,&plh1,&plh2,FCGLP_NEXTPLH|FCGLP_SPLITCHK); 	//get next of endplh//~v62HI~
    if (rc)                                                        //~v45xI~
    	return rc;                                                 //~v45xI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v45xM~
    pc=Ppcw->UCWopdpot;                                            //~v45xM~
    podt=Ppcw->UCWopddelmt;                                        //~v45xI~
    pdelmstr=0;                                                    //~v45xI~
    splittype=-1;               //no default                       //~v60tR~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)	//next operand addr//~v45xR~
	{                                                              //~v45xM~
      	if ((*pc==ULCCMDLABEL && !podt->upoquate))  //start by . but not in quate//~v45xR~
    		continue;                                              //~v45xI~
      if (tflowcmdsw)                                              //~v751I~
        opid=wordtblisrch(pc,Swordtbltflow);                       //~v751I~
      else                                                         //~v751I~
        opid=wordtblisrch(pc,Swordtbl);                            //~v45xR~
        switch(opid)                                               //~v45xR~
        {                                                          //~v45xR~
        case 0: //err                                              //~v45xR~
      		if (!podt->upoquate                                    //~v45xI~
        	&&  *pc>='0' && *pc<='9')	//numeric                  //~v45xR~
            {                                                      //~v45xI~
                widthparmsw=1;                                     //~v76LI~
            	len=(int)strlen(pc);                               //~v45xR~
            	width=atoi(pc);                                    //~v45xM~
            	if (unumlen(pc,0,len)!=len||!width)                //~v45xR~
                	return errinvalid(pc);                         //~v45xI~
                if (width>=MAXLINEDATA)                            //~v60sI~
//              	return errinvalid(pc);                         //~v62QR~
                	return errovermax("width",pc,"<",(LONG)MAXLINEDATA);//~v62QR~
                break;                                             //~v45xI~
            }                                                      //~v45xI~
      		if (!podt->upoquate                                    //~v752I~
			&&  tflowcmdsw                                         //~v75dR~
        	&&  toupper(*pc)=='I')                                 //~v752R~
            {                                                      //~v752I~
            	pc2=pc+1;                                          //~v752I~
			 	if (!*pc2 || (*pc2>='0' && *pc2<='9'))	//numeric  //~v752I~
                {                                                  //~v752I~
            		len=(int)strlen(pc2);                          //~v752I~
                    if (len)                                       //~v752I~
                    {                                              //~v752I~
            			indentoffs=atoi(pc2);                      //~v752R~
            			if (unumlen(pc2,0,len)!=len)               //~v752I~
	                		return errinvalid(pc);                 //~v752I~
                    }                                              //~v752I~
                    else                                           //~v752I~
                    	indentoffs=0;                              //~v752R~
//  		    	opt|=FCSPL_TFLOW;                              //~v75dR~
	                break;                                         //~v752I~
                }                                                  //~v752I~
            }                                                      //~v752I~
      		if (!podt->upoquate                                    //~v759I~
			&&  tflowcmdsw                                         //~v75dR~
        	&&  toupper(*pc)=='P')                                 //~v759I~
            {                                                      //~v759I~
            	pc2=pc+1;                                          //~v759I~
			 	if (!*pc2 || (*pc2>='0' && *pc2<='9'))	//numeric  //~v759I~
                {                                                  //~v759I~
            		len=(int)strlen(pc2);                          //~v759I~
                    if (len)                                       //~v759I~
                    {                                              //~v759I~
            			paragno=atoi(pc2);                         //~v759R~
            			if (unumlen(pc2,0,len)!=len)               //~v759R~
	                		return errinvalid(pc);                 //~v759R~
                    }                                              //~v759I~
                    else                                           //~v759I~
                    	paragno=0;                                 //~v759I~
                    paragnosw=1;                                   //~v75kI~
	                break;                                         //~v759I~
                }                                                  //~v759I~
            }                                                      //~v759I~
          if (*pc!='\\'||toupper(*(pc+1))!='X')                    //~vag9R~
      		if (!podt->upoquate)	//delm strin should be enclosed by quate//~v491I~
            	return errinvalid(pc);                             //~v491I~
            if (delmctr)                                           //~v45xR~
                return errtoomany();                               //~v45xR~
            delmctr++;                                             //~v45xR~
      	    if (!podt->upoquate                                    //~vag9I~
            &&  *pc=='\\')        // \x__ etc                      //~vag9I~
            {                                                      //~vag9I~
				esclen=fcmdchkescseq(pc+1,delmstresc,0/*no chk valid char*/);//~vag9R~
                if (esclen<0)  //err                               //~vag9R~
                	return 4;                                      //~vag9I~
                if (!esclen)   //not esc                           //~vag9R~
	            	return errinvalid(pc);                         //~vag9I~
            }                                                      //~vag9I~
            pdelmstr=pc;                                           //~v45xR~
            break;                                                 //~v45xR~
        case 1: //CONT                                             //~v45xR~
	    	if (splittype>=0)                                      //~v490M~
                return errconflict(pc,0);                          //~v490I~
            splittype=0;                                           //~v45xR~
            break;                                                 //~v45xR~
        case 2: //ALL                                              //~v45xR~
          if (splittype!=1) //allow TFLOW                          //~v751I~
	    	if (splittype>=0)                                      //~v490I~
                return errconflict(pc,0);                          //~v490I~
            splittype=1;                                           //~v45xR~
          if (!paragnosw)                                          //~v75kI~
            paragno=0;  //process all paragraph                    //~v751I~
            opt&=~FCSPL_EACHPARAG;  //insert at each parag         //~v75kI~
            break;                                                 //~v45xR~
        case 3: //OVER;                                            //~v45xI~
	    	if (splittype>=0)                                      //~v490I~
                return errconflict(pc,0);                          //~v490I~
            splittype=2;                                           //~v45xI~
            break;                                                 //~v45xI~
        case 4: //EXP;                                             //~v45xI~
	    	if (splittype>=0)                                      //~v490I~
                return errconflict(pc,0);                          //~v490I~
            splittype=3;                                           //~v45xI~
            break;                                                 //~v45xI~
        case 5: //SBCS                                             //~v45xI~
			if (Sswutf8file)  //utf8file                           //~va20R~
            	return errnotsupported("SBCS option","UTF8 file"); //~va20I~
            opt|=FCSPL_SBCS;                                       //~v45xI~
            break;                                                 //~v45xI~
        case 6: //TAIL                                             //~v45xR~
            if (splittype>=0)                                      //~v490I~
                return errconflict(pc,0);                          //~v490I~
                                                                   //~va5hI~
            splittype=4;                                           //~v45xI~
            break;                                                 //~v45xI~
        case 7: //TOL                                              //~v50AI~
            opt|=FCSPL_TOL;                                        //~v50AI~
            break;                                                 //~v50AI~
        case 8: //STRDELM                                          //~v50BI~
	        if (splittype==4)                                      //~va5hI~
                return errconflict(pc,0);                          //~va5hI~
	        opt|=FCSPL_STRDELM;                                    //~v50BI~
            break;                                                 //~v50BI~
        case 9: //OOM                                              //~v74WI~
	        opt|=FCSPL_OOM;                                        //~v74WI~
            break;                                                 //~v74WI~
        case 10: //STRSPACE                                        //~v74XI~
	        opt|=FCSPL_STRSPACE;                                   //~v74XI~
            break;                                                 //~v74XI~
        case 11: //SPACE1                                          //~v74YI~
	        opt|=FCSPL_SPACE1;                                     //~v74YI~
            break;                                                 //~v74YI~
        case 12: //SAW                                             //~v75eR~
//          if (splittype!=1)                                      //~v75eR~
//            if (splittype>=0)                                    //~v75eR~
//                return errconflict(pc,0);                        //~v75eR~
//            splittype=1;                                         //~v75eR~
//            opt|=FCSPL_TFLOW;                                    //~v75eR~
            opt|=FCSPL_KEEPWORDSN;                                 //~v75eI~
//          splitopt=1;                                            //~v75eI~
            opt&=~(FCSPL_KEEPWORD); //reset before word            //~v75uI~
            break;                                                 //~v74ZI~
//      case 15: //PN                                              //~v759R~
//          opt|=FCSPL_PNEW;  //new paragraph                      //~v759R~
//          break;                                                 //~v759R~
        case 15: //SW              //splitword                     //~v753I~
            opt&=~(FCSPL_KEEPWORD|FCSPL_KEEPWORDSN); //1  paragraph//~v75uI~
//          splitopt=1;                                            //~v75eI~
            break;                                                 //~v753I~
//      case 16: //P1                                              //~v759R~
//          opt|=FCSPL_PSTOP; //1  paragraph                       //~v759R~
//          break;                                                 //~v759R~
        case 16: //P1                                              //~v75gI~
            opt|=FCSPL_IND1ST;//paragraph base is 1st line         //~v75gI~
            break;                                                 //~v75gI~
        case 17: //NOP                                             //~v75hR~
            opt&=~FCSPL_EACHPARAG;  //insert at each parag         //~v75kI~
//          paragno=-1;  //ignore paragrapth                       //~v75wR~
          	if (!paragnosw)                                        //~v75wI~
            	paragno=0;  //process all paragraph                //~v75wI~
            opt|=FCSPL_TFNOP;      //ignore paragraph              //~v75wI~
            break;                                                 //~v75hI~
        case 18: //EACH                                            //~v75kR~
            opt|=FCSPL_EACHPARAG;  //insert at each parag          //~v75kI~
            opt&=~FCSPL_TFNOP;      //ignore paragraph             //~v75wI~
          	if (!paragnosw)                                        //~v75kI~
            	paragno=0;  //process all paragraph                //~v75kI~
            break;                                                 //~v75kI~
        case 19: //CRLF                                            //~v77fI~
			if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file      //~v77fI~
            {                                                      //~v77fI~
            	uerrmsg("%s is for textfile file only",0,          //~v77fI~
							PARM_CRLF);                            //~v77fI~
                return 4;                                          //~v77fI~
            }                                                      //~v77fI~
            parmcrlfsw=1;                                          //~v77fI~
            break;                                                 //~v77fI~
        }                                                          //~v45xR~
	}//loop by operand no                                          //~v45xM~
    if (tflowcmdsw)                                                //~v751I~
    {                                                              //~v751I~
    	splittype=1;                                               //~v751I~
	    opt|=FCSPL_TFLOW|FCSPL_TFLOWCMD;                           //~v751I~
    }                                                              //~v751I~
    if (splittype<0)               //no type parm                  //~v60tI~
    	splittype=1;               //default  "ALL"                //~v60tI~
    if (opt & FCSPL_STRSPACE)                                      //~v74XI~
    {                                                              //~v74XI~
	    if (opt & FCSPL_STRDELM)                                   //~v74XR~
        {                                                          //~v74XI~
        	uerrmsg("STRDELM and STRSPACE is mutualy exclusive",   //~v74XR~
            		"STRDELM と STRSPCEはどちらかを指定する");     //~v74XI~
            return 4;                                              //~v74XI~
        }                                                          //~v74XI~
    	if (pdelmstr)                                              //~v74XI~
        {	                                                       //~v74XI~
//*parm str                                                        //~va20I~
        	if (!strchr(pdelmstr,' '))                             //~v74XI~
            {                                                      //~v74XI~
	            delmstr[0]=' ';                                    //~v74XI~
                strncpy(delmstr+1,pdelmstr,sizeof(delmstr)-2);     //~v74XR~
                *(delmstr+sizeof(delmstr)-1)=0;                    //~v74XI~
                pdelmstr=delmstr;                                  //~v74XI~
                Sotheropt|=SOTHO_STRSPACEADD;                      //~va5qI~
            }                                                      //~v74XI~
        }                                                          //~v74XI~
        else                                                       //~v74XI~
//*parm str                                                        //~va20I~
        	pdelmstr=" ";                                          //~v74XI~
    }                                                              //~v74XI~
  	if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN)   //text file            //~v74WI~
	&&  !(opt & FCSPL_OOM))                                        //~v74WR~
    {                                                              //~v74WI~
		if (fcmdgetbnds(0,pfh,&bndsoffs1,&bndsoffs2))	//bnds is set//~v74WI~
        {                                                          //~v751I~
			opt|=FCSPL_MARGIN;                                     //~v74WI~
            if (bndsoffs2)                                         //~v751I~
			    Sbndscontwkwidth=bndsoffs2;                        //~v751I~
            else                                                   //~v751I~
    			Sbndscontwkwidth=MAXLINEDATA;                      //~v751I~
        }                                                          //~v751I~
		if (width && (opt & FCSPL_MARGIN))	//bnds is set          //~v74WR~
            if (width<=bndsoffs1||(bndsoffs2 && width>bndsoffs2))  //~v751R~
            {                                                      //~v74WI~
                uerrmsg("Width param(%d) is out of margin(%d-%d). OOM option is required to ignore margin setting",//~v751R~
                        "位置(%d)パラメータがマージン外(%d-%d)です。マージン設定を無視するには OOM オプションが必要",//~v751R~
						width,bndsoffs1+1,bndsoffs2);              //~v751I~
                return 4;                                          //~v74WI~
            }                                                      //~v74WI~
        if (splittype==1)     //ALL                                //~v74WI~
        	if (!width && bndsoffs2)                               //~v74WR~
            	width=bndsoffs2;                                   //~v74WI~
    }                                                              //~v74WI~
    if (!width && splittype==1)                                    //~v76LR~
    {                                                              //~v50zR~
      if (!(opt & FCSPL_SPACE1))                                   //~v74YI~
    	if (!pdelmstr)                                             //~v50zR~
        {                                                          //~v50zR~
//      	uerrmsg("Specifi delm or width",                       //~v74WR~
//              "行幅か分離文字を指定してください。");             //~v74WR~
        	uerrmsg("Specify delm or width,or set right boundary by BND cmd",//~v74WR~
                   "行幅か分離文字を指定するか、BND コマンドで右境界を設定してください。");//~v74WR~
        	return 4;                                              //~v74WR~
        }                                                          //~v50zR~
		opt|=FCSPL_ALLWIDTH0;                                      //~v50zR~
    }                                                              //~v50zR~
    if (!widthparmsw && splittype==1)                              //~v76LI~
		opt|=FCSPL_NOWIDTH;                                        //~v76LI~
	Sindentoffs0=indentoffs;	//requested indentation            //~v758R~
	Sindentoffs=-1;				//reset indenttation               //~v758I~
	Sindentoffsmax=width-bndsoffs1;				//reset indenttation//~v751I~
	Smaxparagno=paragno;   		//process n paragraph              //~v759I~
    if (opt & FCSPL_TFLOW)                                         //~v74ZI~
    {                                                              //~v74ZI~
        if (!width)                                                //~v74ZI~
        {                                                          //~v74ZI~
        	uerrmsg("TFLOW requires Width or Right-margin-boundary setting.",//~v74ZI~
                   "TFLOWのときは行幅指定か右境界設定が必要。");   //~v74ZI~
        	return 4;                                              //~v74ZI~
        }                                                          //~v74ZI~
//*parm str                                                        //~va20I~
        if (pdelmstr                                               //~v751I~
        &&  strchr(pdelmstr,' ')                                   //~v751R~
        &&  (!(opt & FCSPL_STRDELM)||(strspn(pdelmstr," ")==strlen(pdelmstr))))//~v751R~
        {                                                          //~v751I~
        	uerrmsg("Dont specify space in delm(%s) when TFLOW",   //~v751I~
//                 "TFLOWのときは分離文字にスペースを指定できません",//~v77vR~
                   "TFLOWのときは分離文字(%s)にスペースを指定できません",//~v77vI~
                   pdelmstr);                                      //~v751I~
        	return 4;                                              //~v751I~
        }                                                          //~v751I~
        if (plh1==UGETQTOP(&pfh->UFHlineque)                       //~v757I~
        &&  plh2==UGETQEND(&pfh->UFHlineque)//no lab parm          //~v757I~
        &&  CSRONFILELINE(Ppcw))            //on data line         //~v757I~
        {                                                          //~v757I~
		 	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                       //~v757I~
			plh1=psd->USDbuffc;                                    //~v757I~
        }                                                          //~v757I~
    }                                                              //~v74ZI~
//    else                                                         //~v75dR~
//    {                                                            //~v75dR~
//        if (indentoffs>=0)                                       //~v75dR~
//        {                                                        //~v75dR~
//            uerrmsg("In is for TFLOW only.",                     //~v75dR~
//                   "InはTFLOWのときのオプションです。");         //~v75dR~
//            return 4;                                            //~v75dR~
//        }                                                        //~v75dR~
//    }                                                            //~v75dR~
//    if (opt & FCSPL_KEEPWORD)                                    //~v75dR~
//        if (!(opt & FCSPL_TFLOW))                                //~v75dR~
//        {                                                        //~v75dR~
//            uerrmsg("KEEPWORD is for TFLOW only.",               //~v75dR~
//                   "KEEPWORDはTFLOWのときのオプションです。");   //~v75dR~
//            return 4;                                            //~v75dR~
//        }                                                        //~v75dR~
//    if (splittype<0)                                             //~v60tR~
//    {                                                            //~v60tR~
//        uerrmsg("missing split type parm",                       //~v60tR~
//                "分割タイプを指定してください");                 //~v60tR~
//        return 4;                                                //~v60tR~
//    }                                                            //~v60tR~
    UPCTRREQ(pfh);         //write at save                         //~v45xI~
#ifdef UTF8UCS2                                                    //~va5gI~
	Sdelmstrlen=0;                                                 //~va5gR~
    Sporgdelmstr=pdelmstr; //save original for errmsg              //~va50I~
    if (esclen)	//by escape seq notation(\x__ etc)                 //~vag9I~
    {                                                              //~vag9I~
		if (Sotheropt & SOTHO_STRSPACEADD)    //insert space in delmstr//~vag9I~
        {                                                          //~vag9I~
            uerrmsg("When escape seq notation of delmiter, include space char in it for alternative of STRSPACE",//~vag9I~
                    "分離文字を\"\\\"ではじめる場合はSTRSPACEの代わりにスペース文字をその中に含めてください");//~vag9R~
            return 4;                                              //~vag9I~
        }                                                          //~vag9I~
    	pdelmstr=delmstresc;                                       //~vag9I~
    }                                                              //~vag9I~
	if (pdelmstr)                                                  //~va5gI~
    {                                                              //~va5gI~
      if (esclen)	//by escape seq notation(\x__ etc)             //~vag9I~
    	Sdelmstrlen=esclen;                                        //~vag9I~
      else                                                         //~vag9I~
//    	Sdelmstrlen=strlen(pdelmstr);                              //~va5gI~//~vb2DR~
     	Sdelmstrlen=(int)strlen(pdelmstr);                         //~vb2DI~
        memset(delmdbcs,0,sizeof(delmdbcs));                       //~va5gR~
        Spdelmdbcs=delmdbcs;                                       //~va5gI~
//      if (opt & FCSPL_STRDELM)                                   //~va50R~
//      {                                                          //~va50R~
          if (esclen)	//by escape seq notation(\x__ etc)         //~vag9R~
          {                                                        //~vag9I~
            ;  //assume all as sbcs                                //~vag9R~
          }                                                        //~vag9I~
          else                                                     //~vag9I~
          {                                                        //~vag9I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    		if (Sswutf8file||Sswebcfile)                           //~va50I~
    #else                                                          //~va50I~
    		if (Sswutf8file)                                       //~va5gR~
    #endif                                                         //~va50I~
                                                                   //~va50I~
            {                                                      //~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                opt2=XEEBCM2DEO_SAVECT|XEEBCM2DEO_ERRMSG;          //~va5qR~
			  if (Sotheropt & SOTHO_STRSPACEADD)    //insert space in delmstr//~va5qR~
              {                                                    //~va5qI~
              	delmddstr[0]=' ';                                  //~va5qI~
              	delmdbcs[0]=0;                                     //~va5qI~
                rc=xeebc_m2ddebc(opt2,pfh,pdelmstr+1,Sdelmstrlen-1,delmddstr+1,delmdbcs+1,sizeof(delmddstr)-1,&ddlen);//~va5qI~
                ddlen++;                                           //~va5qI~
              }                                                    //~va5qI~
              else                                                 //~va5qI~
                rc=xeebc_m2ddebc(opt2,pfh,pdelmstr,Sdelmstrlen,delmddstr,delmdbcs,sizeof(delmddstr),&ddlen);//~va5GI~
    #else                                                          //~va50I~
                rc=xeutfgetddstr(0,pdelmstr,Sdelmstrlen,delmddstr,sizeof(delmddstr),&ddlen,delmdbcs);//~va5gR~
    #endif                                                         //~va50I~
                if (rc)                                            //~va5gR~
                    return 4;                                      //~va5GR~
                pdelmstr=delmddstr;                                //~va5gR~
                delmddstr[ddlen]=0;                                //~0512R~
                Sdelmstrlen=ddlen;  //for memcmp,dbcs may contains null//~va5gR~
            }                                                      //~va5gR~
          }//not esc notation                                      //~vag9I~
//  	}                                                          //~va50R~
    }                                                              //~va5gI~
#endif                                                             //~va5gI~
    if (Sswebcfile)                                                //~va50R~
    {                                                              //~va50I~
        Schspace=CHAR_EBC_SPACE;                                   //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
    {                                                              //~va50I~
        Schspace=' ';                                              //~va50R~
    }                                                              //~va50I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file                //~v60sI~
  {                                                                //~v60sI~
    rc=fcmdsplitbin(splittype|opt,Ppcw,pfh,pdelmstr,plh1,plh2,width);//~v60sI~
  }                                                                //~v60sI~
  else                                                             //~v60sI~
  {                                                                //~v60sI~
  	if (parmcrlfsw)                                                //~v77fI~
    	rc=fcmdchangewidth(1/*all*/|opt,Ppcw,pfh,plh1,plh2,width); //~v77fI~
    else                                                           //~v77fI~
    if (!splittype && !delmctr && !width)//cont without delm nor width//~v45xR~
    	rc=fcmdcutoff(Ppcw,pfh,plh1,plh2);  //simple split         //~v45xR~
    else                                                           //~v45xI~
    	rc=fcmdsplitbydelm(splittype|opt,Ppcw,pfh,pdelmstr,plh1,plh2,width);//~v45xR~
  }                                                                //~v60sI~
    UPCTRREQ(pfh);         //write at save                         //~v45xI~
    return rc;                                                     //~v45xI~
#endif                                                             //~v50JI~
}//fcmdsplit                                                       //~v45xR~
#ifdef DOSDOS                                                      //~v50JI~
#else                                                              //~v50JI~
//**************************************************************** //~v45xR~
// fcmdsplitbydelm                                                 //~v45xR~
//*split continued line                                            //~v45xR~
//*parm1 :option all or cont or exp only                           //~v45xR~
//*parm2 :pcw                                                      //~v45xR~
//*parm3 :pfh                                                      //~v45xR~
//*parm4 :del char tbl                                             //~v45xR~
//*parm5 :start plh                                                //~v45xR~
//*parm6 :end plh                                                  //~v45xR~
//*parm7 :width parm value                                         //~v45xI~
//*return:rc                                                       //~v45xR~
//**************************************************************** //~v45xR~
int fcmdsplitbydelm(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v45xR~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth)    //~v45xR~
{                                                                  //~v45xR~
    PULINEH plh1st=0,plh,plhn=0,plh2;                              //~v45xR~
    int   splitflag,width,errctr=0,donectr=0,oldupctr;             //~v47iR~
    UCHAR *pcontwk;                                                //~v45xR~
    int   rc=0,donesw,splittype,ulhlen;                            //~v45xR~
    int delmstrlen;                                                //~v50BI~
    int delspacectr;                                               //~v74YI~
    int shiftcnt;                                                  //~v74ZI~
    int contwkwidth;                                               //~v751I~
    int rcparag;                                                   //~v758I~
    int bndsoffs1=0,bndsoffs2=0;                                       //~v75aI~//~vaf9R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    char srchct[MAXCOLUMN];                                        //~va5qR~
    UCHAR *psrchct;                                                //~va5qI~
    int opt;                                                       //~va5qI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v45xR~
    Soldupctr=Ppfh->UFHupctr; //used at getindent                  //~v751I~
	if (Popt & FCSPL_TFLOW)                                        //~v751I~
    {                                                              //~v751I~
		fcmdgetbnds(0,Ppfh,&bndsoffs1,&bndsoffs2);	//bnds is set  //~v75aI~
        if (Sindentoffs0>=0)  //In parm                            //~v751I~
        {                                                          //~v751I~
            if (Sindentoffs0>=Sindentoffsmax)                      //~v751I~
            {                                                      //~v751I~
                uerrmsg("%d is too large indentation(>=%d)",       //~v751I~
                        "インデンテーション%dが大きすぎます(>=%d)。",//~v751I~
                        Sindentoffs0,Sindentoffsmax);              //~v751I~
                return 4;                                          //~v751I~
            }                                                      //~v751I~
        }                                                          //~v751I~
      if (!(Popt & FCSPL_EACHPARAG))                               //~v75kI~
        if (Smaxparagno>0)    //limit of paragraph to be processed //~v75aI~
        {                                                          //~v751I~
//  		fcmdgetparagendplh(Popt,Pplh1,&Pplh2,Smaxparagno,bndsoffs1,bndsoffs2);//~v75wR~
    		fcmdgetparagendplh((Popt & ~FCSPL_TFNOP),Pplh1,&Pplh2,Smaxparagno,bndsoffs1,bndsoffs2);//reset NOP when serach end plh//~v75wR~
            Smaxparagno=0;                                         //~v751I~
        }                                                          //~v751I~
    }                                                              //~v751I~
	if (Ppdelmstr)                                                 //~v50BI~
//    	delmstrlen=(int)strlen(Ppdelmstr);                         //~va5gR~
      	delmstrlen=Sdelmstrlen;                                    //~va5gI~
    else                                                           //~v50BI~
    	delmstrlen=0;                                              //~v50BI~
	splittype=Popt & FCSPL_TYPEMASK;                               //~v45xI~
    if (splittype==4)	//TAIL                                     //~v45xR~
//  	return fcmdsplitcut(Ppcw,Ppfh,Pplh1,Pplh2,Ppdelmstr);      //~v53NR~
//  	return fcmdsplitcut(Ppcw,Ppfh,Pplh1,Pplh2,Ppdelmstr,Pwidth);//~v74SR~
    	return fcmdsplitcut(Popt,Ppcw,Ppfh,Pplh1,Pplh2,Ppdelmstr,Pwidth);//~v74SI~
	if (Pwidth)                                                    //~v45xI~
    	width=Pwidth;                                              //~v45xI~
    else                                                           //~v45xI~
    {                                                              //~v470I~
	    width=Ppfh->UFHwidth;                                      //~v45xR~
        if (!width)                                                //~v470I~
        {                                                          //~v54YI~
            if (Ppfh->UFHlrecl==STDSPFLRECL)                       //~v470R~
            	width=STDSPFLRECL;                                 //~v470I~
            else                                                   //~v470I~
            {                                                      //~v50EI~
            	if (Ppfh->UFHmergin!=MAXLINEDATA)                  //~v470R~
	            	width=Ppfh->UFHmergin;                         //~v470I~
    			if (!width && !splittype)	//cont but no width    //~v50EI~
            		width=MAXLINEDATA;                             //~v50EI~
            }                                                      //~v50EI~
        }//width                                                   //~v54YI~
    }                                                              //~v470I~
    if (!width && splittype)	//all but no width                 //~v45xR~
    {                                                              //~v45xR~
	  if (!(Popt & FCSPL_ALLWIDTH0))                               //~v50zR~
      {                                                            //~v50zR~
        uerrmsg("This file is not specified display width,use width operand",//~v50zR~
                "\x95\\示幅指定で開かれていません,幅を指定してください");//~v50zR~
        return 4;                                                  //~v50zR~
      }                                                            //~v50zR~
      else                                                         //~v74WI~
		if (Popt & FCSPL_MARGIN)	//bnds is set                  //~v74WR~
	      	width=MAXLINEDATA;  //for contwk len                   //~v74WR~
    }                                                              //~v45xR~
    if (splittype==3)	//EXP                                      //~v45xI~
		return fcmdsplitexp(Ppcw,Ppfh,Pplh1,Pplh2,width,Ppdelmstr);//~v45xR~
    oldupctr=Ppfh->UFHupctr;                                       //~v45xI~
//  pcontwk=malloc((UINT)((width+1)<<1));	//data and dbcs,and read next 1 byte//~v74WR~
//  pcontwk=umalloc((UINT)((width+1)<<1));	//data and dbcs,and read next 1 byte//~v751R~
  	if (Popt & FCSPL_MARGIN)                                       //~v751R~
		contwkwidth=Sbndscontwkwidth+1;                            //~v751R~
    else                                                           //~v751I~
		contwkwidth=width+1;                                       //~v751I~
    contwkwidth+=8; //for sosi                                     //~va8rI~
    pcontwk=umalloc((UINT)(contwkwidth<<1));	//data and dbcs,and read next 1 byte//~v751I~//~va8rR~
    UALLOCCHK(pcontwk,UALLOC_FAILED);                              //~v74WI~
  if (Popt & FCSPL_MARGIN)                                         //~v74WM~
  {                                                                //~v75fI~
   if (Popt & FCSPL_TFLOW && Popt & FCSPL_EACHPARAG)               //~v75kI~
    rc=fcmdsplitbydelmbndseach(Popt,Ppcw,Ppfh,Ppdelmstr,Pplh1,Pplh2,bndsoffs1,bndsoffs2,pcontwk,contwkwidth,width,&plh1st,&donectr,&errctr);//~v75kI~
   else                                                            //~v75kI~
    rc=fcmdsplitbydelmbnds(Popt,Ppcw,Ppfh,Ppdelmstr,Pplh1,Pplh2,pcontwk,contwkwidth,width,&plh1st,&donectr,&errctr);//~v751R~
    fcmdresettemperr(0,Ppcw,Pplh1,Pplh2,&errctr);                  //~v75fR~
  }                                                                //~v75fI~
  else                                                             //~v74WM~
  {                                                                //~v74WM~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=plhn)                     //~v45xR~
    {                                                              //~v45xR~
	    plhn=UGETQNEXT(plh);	//for consideration plh delete     //~v45xI~
        if (plh->ULHtype!=ULHTDATA)                                //~v45xI~
        	continue;                                              //~v45xI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v45xM~
        {                                                          //~v54YI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v45xM~
                break;                                             //~v45xM~
            else                                                   //~v50zR~
                rc=0;   //ignore TAB found rc                      //~v50zR~
        }//dbcs                                                    //~v54YI~
        delspacectr=0;                                             //~v74YI~
		if (Popt & FCSPL_SPACE1)	//bnds is set                  //~v74YI~
            if (rc=fcmdsplitspace1(Popt,Ppcw,plh,&delspacectr),rc)   //reduce space//~v75cR~
            	return rc;                                         //~v74YR~
        splitflag=(plh->ULHflag2 & (ULHF2SPLIT1|ULHF2SPLIT2));     //~v45xR~
	    ulhlen=plh->ULHlen;                                        //~v45xI~
        if (!splitflag)	//if split ,always processed               //~v45xR~
        {                                                          //~v45xI~
        	if (!splittype)         //CONT                         //~v45xR~
	        	continue;                                          //~v45xR~
        	if (splittype==2)		//over                         //~v45xR~
	        	if (ulhlen<=Pwidth)	//short line                   //~v45xR~
		        	continue;                                      //~v45xI~
        }                                                          //~v45xI~
	  	if ((Popt & FCSPL_ALLWIDTH0))                              //~v50zR~
        {                                                          //~v50zR~
        	if (!ulhlen)                                           //~v50zR~
            	continue;                                          //~v50zR~
          if (Ppdelmstr)    //no delmstr when SPACE1               //~v74YI~
          {                                                        //~v74YI~
	  		if (Popt & FCSPL_STRDELM) //string delemeter           //~v50BI~
            {                                                      //~v50BI~
#ifdef UTF8UCS2                                                    //~va20I~
//      		if (!UTF_umemmem(Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,0/*demstrdbcs*/,ulhlen,delmstrlen))//delm not found//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        		if (!UCVEBCUTF_umemmem(Sswebcfile,Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,Spdelmdbcs,ulhlen,delmstrlen))//delm not found//~va50I~
	#else                                                          //~va50I~
        		if (!UTF_umemmem(Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,Spdelmdbcs,ulhlen,delmstrlen))//delm not found//~va5gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        		if (!umemmem(plh->ULHdata,Ppdelmstr,(UINT)ulhlen,(UINT)delmstrlen))//delm not found//~v50BR~
#endif                                                             //~va20I~
            		continue;                                      //~v50BI~
            }                                                      //~v50BI~
            else                                                   //~v50BI~
            {                                                      //~v76ER~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      	if (!UCVEBCUTF_umempbrk(Sswebcfile,Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,ulhlen))//delm not found//~0512R~
//      	if (!UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,Spdelmdbcs,ulhlen))//delm not found//~0512I~//~va79R~
        	if (!UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,Spdelmdbcs,ulhlen))//delm not found//~va79I~
    #else                                                          //~va50I~
        	if (!UTF_umempbrk(Sswutf8file,plh->ULHdata,plh->ULHdbcs,Ppdelmstr,ulhlen))//delm not found//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
        	if (!umempbrk(plh->ULHdata,Ppdelmstr,(UINT)ulhlen))//delm not found//~v50BR~
#endif                                                             //~va20I~
            	continue;                                          //~v50zR~
            }                                                      //~v76ER~
          }                                                        //~v74YI~
          else                                                     //~v74YI~
          	if (!delspacectr)                                      //~v74YI~
            	continue;                                          //~v74YI~
        }                                                          //~v50zR~
        if (plh->ULHupctr<=oldupctr                                //~v45xI~
        &&  !(splitflag & ULHF2SPLIT2))                            //~v45xI~
        {	                                                       //~v45xI~
        	donesw=1;                                              //~v45xI~
            donectr++;                                             //~v45xI~
        }                                                          //~v45xI~
        else                                                       //~v45xI~
        	donesw=0;                                              //~v45xI~
        plh2=plh;		//for 1st updated                          //~v45xI~
//      if (ulhlen>width)                                          //~v74ZR~
		rcparag=0;                                                 //~v758I~
  		if (Popt & FCSPL_TFLOW) //TFLOW pattern                    //~v74ZI~
        {                                                          //~v758I~
#ifdef UTF8UCS2                                                    //~va20I~
			rcparag=fcmdtflowgetindent(Popt,plh,plh->ULHdata,plh->ULHdbcs,ulhlen,&shiftcnt);//~va20I~
#else                                                              //~va20I~
			rcparag=fcmdtflowgetindent(Popt,plh,plh->ULHdata,ulhlen,&shiftcnt);//~v751R~
#endif                                                             //~va20I~
            if (rcparag==FCSPLRC_PSTOP)	//paragraph changed        //~v758I~
            	break;                                             //~v758I~
        }                                                          //~v758I~
        else                                                       //~v74ZI~
            shiftcnt=0;                                            //~v74ZI~
        if ((ulhlen+shiftcnt)>width)                               //~v74ZI~
        {                                                          //~v45xR~
            rc=fcmdsplitsplit(Ppcw,&plh,width,Ppdelmstr,pcontwk,Popt,&errctr);//plh:last inserted//~v45xR~
            if (rc)                                                //~v45xR~
                break;                                             //~v45xR~
            rc=1;		//modified                                 //~v45xI~
            plhn=plh;     //last short of split or next            //~v45xR~
        }                                                          //~v45xR~
        else                                                       //~v45xR~
        {                                                          //~v45xR~
//        if (rcparag==FCSPLRC_PNEW)	//force new paragraph      //~v758R~
//          rc=0;                       //process next plh         //~v758R~
//        else                                                     //~v758R~
//        {                                                        //~v758R~
            rc=fcmdsplitjoin(Ppcw,&plh,Pplh2,width,Ppdelmstr,pcontwk,Popt,//~v45xR~
							&donectr,&errctr);                     //~v45xR~
            if (rc>1)                                              //~v45xR~
                break;                                             //~v45xR~
            if (!rc && donesw)  //not updated                      //~v45xI~
            	donectr--;		//reset count up                   //~v45xI~
            plhn=plh;                                              //~v45xI~
//        }                                                        //~v758R~
        }                                                          //~v45xR~
        if (rc==1)                                                 //~v45xI~
        {                                                          //~v45xI~
            rc=0;                                                  //~v45xI~
        	if (!plh1st)                                           //~v45xR~
            	plh1st=plh2;     //1st changed                     //~v45xR~
    	}                                                          //~v45xI~
    }//plh loop                                                    //~v45xR~
  }//!bnds                                                         //~v74WI~
  	ufree(pcontwk);                                                //~v74WI~
    if (rc==FCSPLRC_PSTOP)	//paragraph changed                    //~v758M~
        rc=0;                                                      //~v758M~
    if (rc)                                                        //~v45xR~
        return rc;                                                 //~v45xR~
    if (plh1st)                                                    //~v45xR~
    {                                                              //~v45xR~
        UPCTRREQ(Ppfh);         //write at save                    //~v45xR~
        undocsrmove(Ppcw,plh1st);                                  //~v45xR~
    }                                                              //~v45xR~
////count inserted                                                 //~v45xR~
//    for (addctr=0,plh=Pplh1;plh && plh!=Pplh2;plh=plhn)          //~v45xR~
//    {                                                            //~v45xR~
//        plhn=UGETQNEXT(plh);    //for consideration plh delete   //~v45xR~
//        if (plh->ULHtype!=ULHTDATA)                              //~v45xR~
//            continue;                                            //~v45xR~
//        if (plh->ULHupctr>oldupctr)                              //~v45xR~
//            addctr++;                                            //~v45xR~
//    }//plh loop                                                  //~v45xR~
//    addctr-=donectr;                                             //~v45xR~
    if (!Ppdelmstr)                                                //~v491I~
    	Ppdelmstr="";                                              //~v491I~
  if (!(Popt & FCSPL_TFLOWLCMD))                                   //~v75aI~
  {                                                                //~v7apI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	psrchct=Ppdelmstr;                                             //~va50I~
    if (Ppdelmstr && *Ppdelmstr)                                   //~va50I~
    {                                                              //~va50I~
    	psrchct=Sporgdelmstr;                                      //~va50R~
    	if (Sporgdelmstr)                                          //~va50R~
        {                                                          //~va5qI~
    		psrchct=srchct;                                        //~va5qI~
    		opt=FCSCFEMO_SETCTPREFIX;                              //~va5qR~
			if (Sotheropt & SOTHO_STRSPACEADD)    //insert space in delmstr//~va5qR~
            {                                                      //~va5qI~
            	*psrchct++=' ';                                    //~va5qI~
//  			if (fcmd_savelcctforerrmsg(opt,0/*1st word*/,Sporgdelmstr+1,strlen(Sporgdelmstr+1),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~va5qI~//~vb2DR~
    			if (fcmd_savelcctforerrmsg(opt,0/*1st word*/,Sporgdelmstr+1,(int)strlen(Sporgdelmstr+1),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~vb2DI~
    				psrchct=Sporgdelmstr;                          //~va5qI~
                else                                               //~va5qI~
                	psrchct--;                                     //~va5qI~
            }                                                      //~va5qI~
            else                                                   //~va5qI~
//  		if (fcmd_savelcctforerrmsg(opt,0/*1st word*/,Sporgdelmstr,strlen(Sporgdelmstr),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~va5qR~//~vb2DR~
    		if (fcmd_savelcctforerrmsg(opt,0/*1st word*/,Sporgdelmstr,(int)strlen(Sporgdelmstr),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~vb2DI~
    			psrchct=Sporgdelmstr;                              //~va50R~
        }                                                          //~va5qI~
    }                                                              //~va50I~
#endif                                                             //~va50I~
   if (errctr)                                                     //~v7apR~
    uerrmsg("%d line(s) processed,%d err line,delm=\"%s\".",       //~v75uR~
            "対象 %d, %d 行エラー,分離文字列=\"%s\"｡",             //~v491R~
//              donectr,errctr,Ppdelmstr);                         //~va5gR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                donectr,errctr,psrchct);                           //~va50I~
#else                                                              //~va50I~
                donectr,errctr,Sporgdelmstr);                      //~va5gI~
#endif                                                             //~va50I~
   else                                                            //~v7apI~
   if (Ppdelmstr && *Ppdelmstr)                                    //~v7apR~
    uerrmsg("%d line(s) processed. (delm=\"%s\")",                 //~v7apI~
            "対象 %d 行 (分離文字列=\"%s\")｡",                     //~v7apI~
//              donectr,Ppdelmstr);                                //~va5gR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                donectr,psrchct);                                  //~va50R~
#else                                                              //~va50I~
                donectr,Sporgdelmstr);                             //~va5gI~
#endif                                                             //~va50I~
   else                                                            //~v7apI~
    uerrmsg("%d line(s) processed.",                               //~v7apI~
            "対象 %d 行｡",                                         //~v7apI~
                donectr);                                          //~v7apI~
    if (!donectr && Sdelmstrlen>1 && !(Popt & FCSPL_STRDELM))      //~va5GR~
	    uerrmsgcat("(Warning:multibyte delmstring without STRDELM option)",0);//~va5gI~
  }                                                                //~v7apI~
    return 0;                                                      //~v45xR~
}//filesplitbydelm                                                 //~v45xR~
//**************************************************************** //~v77fI~
// fcmdchangewidth                                                 //~v77fI~
//*change text file display width                                  //~v77fI~
//*return:rc                                                       //~v77fI~
//**************************************************************** //~v77fI~
int fcmdchangewidth(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,         //~v77fI~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth)    //~v77fI~
{                                                                  //~v77fI~
    int   width,errctr,donectr,opt;                                //~v77fR~
    UCHAR *pcontwk;                                                //~v77fI~
    int   rc=0;                                                    //~v77fI~
    int contwkwidth;                                               //~v77fI~
//*********************************                                //~v77fI~
	if (Pwidth)                                                    //~v77fI~
    	width=Pwidth;                                              //~v77fI~
    else                                                           //~v77fI~
	    width=Ppfh->UFHwidth;                                      //~v77fI~
    if (!width)	//all but no width                                 //~v77fI~
    {                                                              //~v77fI~
        uerrmsg("This file is not specified display width,use width operand",//~v77fI~
                "\x95\\示幅指定で開かれていません,幅を指定してください");//~v77fI~
        return 4;                                                  //~v77fI~
    }                                                              //~v77fI~
	contwkwidth=width+1;                                           //~v77fI~
    	pcontwk=umalloc((UINT)(contwkwidth<<1));	//data and dbcs,and read next 1 byte//~v77fI~
    UALLOCCHK(pcontwk,UALLOC_FAILED);                              //~v77fI~
	Sopt2|=SOPT2_SPLCRLF;                                          //~v77fI~
    opt=Popt & (FCSPL_TYPEMASK                                     //~v77fI~
				|FCSPL_SBCS                                        //~v77fI~
                );                                                 //~v77fI~
    if (Sswebcfile)                                                //~va8kI~
        opt|=FCSPL_SBCS;    //don't insert SO/SI by split          //~va8kI~
	rc=fcmdchangewidthsub(opt,Ppcw,Ppfh,Pplh1,Pplh2,pcontwk,width,&donectr,&errctr);//~v77fR~
	Sopt2&=~SOPT2_SPLCRLF;                                         //~v77fI~
  	ufree(pcontwk);                                                //~v77fI~
    if (rc)                                                        //~v77fI~
        return rc;                                                 //~v77fI~
    uerrmsg("%d line(s) processed,%d err line.",                   //~v77fI~
            "対象 %d, %d 行エラー｡",                               //~v77fI~
                donectr,errctr);                                   //~v77fI~
    return 0;                                                      //~v77fI~
}//fcmdchangewidth                                                 //~v77fI~
//**************************************************************** //~v77fI~
// fcmdchangewidth                                                 //~v77fI~
//*change text file display width                                  //~v77fI~
//*return:rc                                                       //~v77fI~
//**************************************************************** //~v77fI~
int fcmdchangewidthsub(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,      //~v77fI~
						PULINEH Pplh1,PULINEH Pplh2,UTCPARMD(UCHAR *,Pcontwk),int Pwidth,//~v77fI~
                        int *Ppdonectr,int *Pperrctr)              //~v77fI~
{                                                                  //~v77fI~
    PULINEH plh1st=0,plh,plhn=0,plh2;                              //~v77fI~
    int   errctr=0,donectr=0,oldupctr;                             //~v77fI~
    int   rc=0,ulhlen;                                             //~v77fI~
//*********************************                                //~v77fI~
    oldupctr=Ppfh->UFHupctr;                                       //~v77fI~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=plhn)                     //~v77fI~
    {                                                              //~v77fI~
	    plhn=UGETQNEXT(plh);	//for consideration plh delete     //~v77fI~
        if (plh->ULHtype!=ULHTDATA)                                //~v77fI~
        	continue;                                              //~v77fI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v77fI~
        {                                                          //~v77fI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v77fI~
                break;                                             //~v77fI~
        }//dbcs                                                    //~v77fI~
	    ulhlen=plh->ULHlen;                                        //~v77fI~
        plh2=plh;		//for 1st updated                          //~v77fI~
        if (ulhlen>Pwidth)                                         //~v77fI~
        {                                                          //~v77fI~
            rc=fcmdsplitsplit(Ppcw,&plh,Pwidth,0/*delmstr*/,Pcontwk,Popt,&errctr);//plh:last inserted//~v77fI~
            if (rc)                                                //~v77fI~
                break;                                             //~v77fI~
	        donectr++;                                             //~v77fI~
            rc=1;		//modified                                 //~v77fI~
            plhn=plh;     //last short of split or next            //~v77fI~
        }                                                          //~v77fI~
        else    //call even when len=width for x line              //~v77fI~
        {                                                          //~v77fI~
	        if (plh->ULHflag2 & ULHF2SPLIT1)	//has following cont line//~v77fI~
            {                                                      //~v77fI~
        		if (plh->ULHupctr<=oldupctr)	//not inserted by this time split//~v77fI~
                    donectr++;      //reset count up               //~v77fI~
                rc=fcmdsplitjoin(Ppcw,&plh,Pplh2,Pwidth,0/*delmstr*/,Pcontwk,Popt,&donectr,&errctr);//~v77fI~
                if (rc>1)                                          //~v77fI~
                    break;                                         //~v77fI~
                if (!rc)  //updated                                //~v77fI~
                	donectr--;                                     //~v77fI~
                plhn=plh;                                          //~v77fI~
            }                                                      //~v77fI~
            else                    //EOL line                     //~v77fI~
	            plhn=UGETQNEXT(plh);                               //~v77fI~
        }                                                          //~v77fI~
        if (rc==1)                                                 //~v77fI~
        {                                                          //~v77fI~
            rc=0;                                                  //~v77fI~
        	if (!plh1st)                                           //~v77fI~
            	plh1st=plh2;     //1st changed                     //~v77fI~
    	}                                                          //~v77fI~
    }//plh loop                                                    //~v77fI~
    if (Ppdonectr)                                                 //~v77fI~
	    *Ppdonectr=donectr;                                        //~v77fI~
    if (Pperrctr)                                                  //~v77fI~
	    *Pperrctr=errctr;                                          //~v77fI~
    if (rc==FCSPLRC_PSTOP)	//paragraph changed                    //~v77fI~
        rc=0;                                                      //~v77fI~
    if (rc)                                                        //~v77fI~
        return rc;                                                 //~v77fI~
    if (plh1st)                                                    //~v77fI~
    {                                                              //~v77fI~
        UPCTRREQ(Ppfh);         //write at save                    //~v77fI~
        undocsrmove(Ppcw,plh1st);                                  //~v77fI~
    }                                                              //~v77fI~
    return 0;                                                      //~v77fI~
}//fcmdchangewidth                                                 //~v77fI~
//**************************************************************** //~v45xM~
// fcmdsplitexp                                                    //~v45xM~
//*expand short line                                               //~v45xM~
//*parm1 :pcw                                                      //~v45xR~
//*parm2 :pfh                                                      //~v45xR~
//*parm3 :start plh                                                //~v45xR~
//*parm4 :end plh                                                  //~v45xR~
//*parm5 :width parm value                                         //~v45xR~
//*parm6 :padding char specification                               //~v45xI~
//(1byte)padding or (2bte)TermChar+padding or (3byte)TearmChar+padding+EOL char//~va20I~
//*return:rc                                                       //~v45xM~
//**************************************************************** //~v45xM~
int fcmdsplitexp(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,//~v45xR~
					int Pwidth,UCHAR *Ppdelmstr)                   //~v45xR~
{                                                                  //~v45xM~
    PULINEH plh,plhn=0;                                            //~v45xM~
    int  donectr=0,ulhlen,paddch;                                  //~v45xR~
    int delmstrlen,delmch=0,termch=0,reslen;                       //~v75BI~
    char *pdata;                                                   //~v75BI~
//*********************************                                //~v45xM~
	if (Ppdelmstr)                                                 //~v45xI~
    {                                                              //~v75BI~
    	paddch=*Ppdelmstr;                                         //~v45xI~
        delmstrlen=(int)strlen(Ppdelmstr);                              //~v75BR~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (!utfddisasciistr(0,Ppdelmstr,Spdelmdbcs,delmstrlen))   //~va50I~
#else                                                              //~va50I~
        if (!utfddisasciistr(0,Ppdelmstr,0/*dbcs*/,delmstrlen))    //~va20R~
#endif                                                             //~va50I~
        {                                                          //~va20I~
        	uerrmsg("\"%s\" is not ascii",                         //~va20R~
            		"\"%s\" が無効、パディング文字などはASCII文字に限ります",//~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    				Sporgdelmstr);                                 //~va50I~
#else                                                              //~va50I~
                    Ppdelmstr);                                    //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            return 4;                                              //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
        if (delmstrlen>1)                                          //~v75BI~
        {                                                          //~v75BI~
        	delmch=paddch;                                         //~v75BR~
            paddch=*(Ppdelmstr+1);                                 //~v75BR~
	        if (delmstrlen>2)                                      //~v75BI~
	            termch=*(Ppdelmstr+2);                             //~v75BI~
        }                                                          //~v75BI~
    }                                                              //~v75BI~
    else                                                           //~v45xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	paddch=Schspace;                                           //~va50I~
#else                                                              //~va50I~
    	paddch=' ';                                                //~v45xI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=plhn)                     //~v45xM~
    {                                                              //~v45xM~
	    plhn=UGETQNEXT(plh);	//for consideration plh delete     //~v45xM~
        if (plh->ULHtype!=ULHTDATA)                                //~v45xM~
        	continue;                                              //~v45xM~
        if (!plh->ULHdbcs)  //not once displayed                   //~v74RI~
            if (filechktabdbcs(plh)==UALLOC_FAILED)//expand tab for width and tab is space//~v74RR~
            	return UALLOC_FAILED;                              //~v74RI~
        ulhlen=plh->ULHlen;                                        //~v45xM~
		if (ulhlen<Pwidth)                                         //~v45xM~
        {                                                          //~v45xM~
            if (fileexpandbuff(plh,Pwidth)==UALLOC_FAILED)      //expand buff//~v45xM~
                return 4;                                          //~v45xM~
//*expand,add ascii only,nod dbcstbl chng                          //~va50I~
            if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v45xM~
                return UALLOC_FAILED;                              //~v45xM~
            reslen=Pwidth-ulhlen;                                  //~v75BI~
          if (delmch)	//multi byte delmstr                       //~v75BI~
          {                                                        //~v75BI~
            pdata=plh->ULHdata+ulhlen;                             //~v75BR~
            *pdata++=(char)delmch;                                       //~v75BI~
            reslen--;                                              //~v75BI~
            if (termch && reslen>0)                                //~v75BI~
            {                                                      //~v75BI~
            	reslen--;                                          //~v75BI~
            	*(pdata+reslen)=(char)termch;                            //~v75BI~
            }                                                      //~v75BI~
            memset(pdata,paddch,(UINT)reslen);                     //~v75BI~
          }                                                        //~v75BI~
          else                                                     //~v75BI~
            memset(plh->ULHdata+ulhlen,paddch,(UINT)(Pwidth-ulhlen));//~v45xR~
//          if (plh->ULHdbcs)                                      //~v74RR~
                memset(plh->ULHdbcs+ulhlen,0,(UINT)(Pwidth-ulhlen));//~v45xM~
            plh->ULHlen=Pwidth;                                    //~v45xM~
            donectr++;                                             //~v45xM~
        }                                                          //~v45xM~
    }//plh loop                                                    //~v45xM~
    uerrmsg("%d line(s) expanded",                                 //~v45xM~
            "%d 行を拡張｡",                                        //~v45xM~
                donectr);                                          //~v45xM~
    return 0;                                                      //~v45xM~
}//filesplitexp                                                    //~v45xM~
//**************************************************************** //~v45xI~
// fcmdsplitsplit                                                  //~v45xR~
//*long line by width and delmtbl                                  //~v45xR~
//* split line or long line for OVER/ALL case.                     //~v45xI~
//*parm1 :pcw                                                      //~v45xR~
//*parm2 :&plh cause overflow(len>width),output:last inserted      //~v45xR~
//*parm3 :split width                                              //~v45xR~
//*parm4 :delm string                                              //~v45xR~
//*parm5 :expandwk                                                 //~v45xI~
//*parm6 :opt                                                      //~v45xR~
//*parm7 :having no delm ctr                                       //~v45xR~
//*parm8 :inserted line ctr                                        //~v45xR~
//*return:rc:0:no err, 4:err,PSTOP(32)                             //~v758R~
//**************************************************************** //~v45xI~
int fcmdsplitsplit(PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,      //~v45xR~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,               //~v45xI~
					int Popt,int *Pperrctr)                        //~v45xR~
{                                                                  //~v45xI~
    PULINEH plh;                                                   //~v45xR~
    PULINEH plh0;                                                  //~va8kI~
    int   rlen,newlen,splitflag,errsw,ulhlen,splittype;            //~v45xR~
    UCHAR *pdata,*pdbcs;                                           //~v45xR~
    int   rc=0;                                                    //~v45xR~
    int   insertsw=0;                                              //~v492I~
    int   optild,swinsertsosi0=0,swinsertsosi1,swinsertsosi2,width;//~va8kR~
//*********************************                                //~v45xI~
	splittype=Popt & FCSPL_TYPEMASK;                               //~v45xI~
    plh=*Ppplh;                                                    //~v45xR~
    ulhlen=plh->ULHlen;                                            //~v45xR~
    pdata=plh->ULHdata;                                            //~v45xR~
    pdbcs=plh->ULHdbcs;                                            //~v45xI~
    splitflag=UCBITCHK(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2));   //~v45xR~
//*ebc setdbcstbl later                                            //~va50I~
	if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v45xI~
    	return UALLOC_FAILED;                                      //~v45xI~
    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line    //~v45xI~
    	if (rc=lcmdincm(Ppcw,plh),rc)                              //~v45xI~
        	return rc;                                             //~v45xI~
  	if (Popt & FCSPL_TFLOW) //TFLOW pattern                        //~v74ZR~
    	return fcmdtflowsplit(Popt,Ppcw,Ppplh,Pwidth,Ppdelmstr,Pcontwk,Pperrctr);//~v74ZR~
//  errsw=fcmdsplitlen(Popt,pdata,pdbcs,Ppdelmstr,ulhlen,Pwidth,&newlen);//~v750R~
    errsw=fcmdsplitlen(Popt|FCSPL_SETDBCSERR,                      //~v750I~
						pdata,pdbcs,Ppdelmstr,ulhlen,Pwidth,&newlen);//~v750I~
    if (errsw)                                                     //~v45xI~
	if (!(Popt & FCSPL_ALLWIDTH0))                                 //~v50BI~
    {                                                              //~v45xI~
        lcmdshifterr(plh,0,0);  //set reverse                      //~v45xI~
        (*Pperrctr)++;                                             //~v45xI~
    }                                                              //~v45xI~
  if (!(Sopt2 & SOPT2_SPLCRLF))                                    //~v77fI~
	UCBITOFF(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2));             //~v45xI~
    plh->ULHlen=newlen;                                            //~v45xM~
//insert remaining data                                            //~v45xI~
	plh0=plh;                                                      //~va8kI~
	if (ulhlen>newlen)                                             //~v74TI~
    {                                                              //~va5qI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (Sswebcfile)                                              //~va50R~
      {                                                            //~va8kI~
		swinsertsosi0=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SO for split ebc dbcs string//~va8kR~
       if (!swinsertsosi0)	//setdbcstbl after si inserted         //~va8kI~
		xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);           //~va50I~
      }                                                            //~va8kI~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	    chartabclear(pdbcs+newlen,ulhlen-newlen);                  //~v74TI~
    }                                                              //~va5qI~
    swinsertsosi1=swinsertsosi0;                                   //~va8kI~
    for (rlen=ulhlen-newlen,pdata+=newlen,pdbcs+=newlen;rlen>0;)   //~v45xR~
    {                                                              //~v45xI~
    	width=Pwidth;                                              //~va8kI~
        if (Pwidth)                                                //~va8kI~
        	width-=swinsertsosi1;                                  //~va8kR~
      if (!(Popt & FCSPL_TFLOW) //SPLIT cmd                        //~va8sI~
      &&  Ppdelmstr                                                //~va8sI~
      &&  width                                                    //~va8sI~
      )                                                            //~va8sI~
      {                                                            //~va8sI~
        newlen=rlen;                                               //~va8sI~
	   	Sotheropt&=~SOTHO_APPENDSO;                                //~va8sI~
      }                                                            //~va8sI~
      else                                                         //~va8sI~
      {                                                            //~va8sI~
//      errsw=fcmdsplitlen(Popt,pdata,pdbcs,Ppdelmstr,rlen,Pwidth,&newlen);//~v750R~
        errsw=fcmdsplitlen(Popt|FCSPL_SETDBCSERR,                  //~v750I~
//  						pdata,pdbcs,Ppdelmstr,rlen,Pwidth,&newlen);//~v750I~//~va8kR~
    						pdata,pdbcs,Ppdelmstr,rlen,width,&newlen);//~va8kI~
//  	rc=fcmdisrtline(Ppcw,plh,pdata,newlen);                    //~v69tR~
      }                                                            //~va8sI~
      if (Sswebcfile)                                              //~va8kI~
      {                                                            //~va8kI~
	   	swinsertsosi2=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SO for split ebc dbcs string//~va8kR~
      	optild=0;                                                  //~va8kI~
        if (swinsertsosi1)                                         //~va8kI~
        	optild|=FCILDEO_INSERT_SO;                             //~va8kI~
        if (swinsertsosi2)                                         //~va8kI~
        	optild|=FCILDEO_APPEND_SI;                             //~va8kI~
    	rc=fcmdisrtlinedbcsebcsosi(optild,Ppcw,plh,pdata,pdbcs,newlen);//~va8kI~
        swinsertsosi1=swinsertsosi2;	//for next line            //~va8kR~
      }                                                            //~va8kI~
      else                                                         //~va8kI~
    	rc=fcmdisrtlinedbcs(Ppcw,plh,pdata,pdbcs,newlen);          //~v69tI~
        if (rc)                                                    //~v45xR~
        	return rc;                                             //~v45xR~
        insertsw=1;                                                //~v492I~
  		if ((Sopt2 & SOPT2_SPLCRLF))                               //~v77fI~
			UCBITON(plh->ULHflag2,ULHF2SPLIT1);   //line now has follower//~v77fI~
        plh=UGETQNEXT(plh);	//inserted                             //~v45xM~
  		if ((Sopt2 & SOPT2_SPLCRLF))                               //~v77fI~
			UCBITON(plh->ULHflag2,ULHF2SPLIT2);   //following line //~v77fI~
        if (errsw)                                                 //~v45xM~
	  	 if (!(Popt & FCSPL_ALLWIDTH0))                            //~v50zR~
        {                                                          //~v45xI~
	        lcmdshifterr(plh,0,0);  //set reverse                  //~v45xM~
            (*Pperrctr)++;                                         //~v45xI~
        }                                                          //~v45xI~
        rlen-=newlen;                                              //~v45xR~
        pdata+=newlen;                                             //~v45xR~
        pdbcs+=newlen;                                             //~v45xI~
    }//split long line                                             //~v45xR~
    if (swinsertsosi0)	//setdbcstbl after si inserted             //~va8kR~
    {                                                              //~va8kI~
		if (fcmdebcappendsoeol(0,plh0))	//append si to top plh     //~va8kR~
        	return UALLOC_FAILED;                                  //~va8kI~
		xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);           //~va8kI~
    }                                                              //~va8kI~
    if (splittype!=1)		//not all(all process current)         //~v45xR~
	    if (splitflag & ULHF2SPLIT1)    //has follower             //~v45xR~
    	    UCBITON(plh->ULHflag2,ULHF2SPLIT1);                    //~v45xR~
    	else                                                       //~v45xR~
       		plh=UGETQNEXT(plh);     //process next                 //~v45xR~
    else                                                           //~v492I~
        if (!insertsw)                                             //~v492I~
       		plh=UGETQNEXT(plh);     //process next                 //~v492I~
    *Ppplh=plh;                                                    //~v45xI~
    return 0;                                                      //~v45xR~
}//filesplitsplit                                                  //~v45xR~
//**************************************************************** //~v74ZI~
// fcmdtflowsplit                                                  //~va8jR~
// search split position(try split at last space in the width)     //~v74ZI~
//*rc   :0 no split,1:tail is shift to next line                   //~v74ZI~
//*     :PSTOP(32)                                                 //~v758I~
//**************************************************************** //~v74ZI~
int fcmdtflowsplit(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,//~v74ZR~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,int *Pperrctr) //~v74ZR~
{                                                                  //~v74ZI~
    PULINEH plh,plh0;                                              //~v74ZR~
    int   rlen,newlen,errsw,ulhlen;                                //~v74ZR~
    UCHAR *pdata,*pdbcs/*,*pcontdata,*pcontdbcs*/;                     //~v74ZI~
    int   rc=0;                                                    //~v74ZI~
    int   insertsw=0;                                              //~v75BR~
    int   /*copyedlen,contlen,topshiftlen,*/headcnt,width/*,opt,rc2*/;//~v75eR~
    int  linefilledsw,toplinefilledsw;                             //~v75eR~
    int   optild,swinsertsosi0=0,swinsertsosi1,swinsertsosi2;      //~va8kI~
    int expandsw;                                                  //~va8uI~
//*********************************                                //~v74ZI~
//  pcontdata=Pcontwk;                                             //~v74ZI~
//  pcontdbcs=Pcontwk+Pwidth+1;                                    //~v74ZI~
    plh=plh0=*Ppplh;                                               //~v74ZR~
	if ((rc=fcmdtflowindentshift(Popt,plh,Pwidth,0,0,0))>1)//shift by indentation on plh//~v74ZR~
    	return rc;                     //UALLOC_FAILED             //~v74ZR~
    ulhlen=plh->ULHlen;                                            //~v74ZI~
    if (ulhlen<=Pwidth)	//shrinked by indentation                  //~v74ZI~
    	return 0;	//retry join                                   //~v74ZI~
    pdata=plh->ULHdata;                                            //~v74ZI~
    pdbcs=plh->ULHdbcs;                                            //~v74ZI~
    errsw=fcmdtflowsplitlen(Popt|FCSPL_TFTOPLINE,pdata,pdbcs,Ppdelmstr,ulhlen,Pwidth,&newlen,&toplinefilledsw);//~v75eR~
//    if (linefilledsw==FCSPLRC_TAILSPACECUT)                      //~v75eR~
//    {                                                            //~v75eR~
//        plh->ULHlen=newlen;                                      //~v75eR~
//        *Ppplh=plh;        //retry join                          //~v75eR~
//        return 0;                                                //~v75eR~
//    }                                                            //~v75eR~
    if (errsw)                                                     //~v74ZI~
    {                                                              //~v751I~
		if (!(Popt & FCSPL_ALLWIDTH0))                             //~v74ZI~
    	{                                                          //~v74ZI~
        	lcmdshifterr(plh,0,0);  //set reverse                  //~v74ZI~
        	(*Pperrctr)++;                                         //~v74ZI~
    	}                                                          //~v74ZI~
      if (errsw==1)	//split failed                                 //~v75eI~
      {                                                            //~v751I~
        *Ppplh=UGETQNEXT(plh);                                     //~v751R~
        return 0;                                                  //~v751I~
      }                                                            //~v751I~
    }                                                              //~v751I~
    plh->ULHlen=newlen;                                            //~v74ZI~
//insert remaining data                                            //~v74ZI~
	if (ulhlen>newlen)                                             //~v74ZI~
    {                                                              //~va8kI~
      if (Sswebcfile)                                              //~va8kI~
      {                                                            //~va8kI~
		swinsertsosi0=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SO for split ebc dbcs string//~va8kI~
       	if (!swinsertsosi0)	//do setdbcstbl after si inserted      //~va8kI~
			xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);       //~va8kI~
      }                                                            //~va8kI~
      else                                                         //~va8kI~
	    chartabclear(pdbcs+newlen,ulhlen-newlen);                  //~v74ZI~
    }                                                              //~va8kI~
    width=Pwidth-Sindentoffs;                                      //~v74ZI~
    swinsertsosi1=swinsertsosi0;                                   //~va8kI~
    for (rlen=ulhlen-newlen,pdata+=newlen,pdbcs+=newlen;rlen>0;    //~v75eR~
        rlen-=newlen,pdata+=newlen,pdbcs+=newlen)                  //~v75eI~
    {                                                              //~v74ZI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,rlen);//~va50I~
    #else                                                          //~va50I~
    	headcnt=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',rlen);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	headcnt=(int)umemspnc(pdata,' ',(UINT)rlen);                          //~v74ZI~
#endif                                                             //~va20I~
        pdata+=headcnt;                                            //~v74ZI~
        pdbcs+=headcnt;                                            //~v74ZI~
        rlen-=headcnt;                                             //~v74ZI~
        if (rlen<=0)                                               //~v74ZI~
            break;                                                 //~v74ZI~
        width-=swinsertsosi1;                                      //~va8kI~
        errsw=fcmdtflowsplitlen(Popt,pdata,pdbcs,Ppdelmstr,rlen,width,&newlen,&linefilledsw);//~v75eR~
//        if (linefilledsw==FCSPLRC_TAILSPACECUT) //tail space is cut//~v75eR~
//            copyedlen=rlen;                                      //~v75eR~
//        else                                                     //~v75eR~
//            copyedlen=newlen;                                    //~v75eR~
//      if (newlen && (int)umemspnc(pdata,' ',newlen)==newlen)     //~v75eR~
//          continue;   //skip insert all space line               //~v75eR~
      if (Sswebcfile)                                              //~va8kI~
      {                                                            //~va8kI~
	   	swinsertsosi2=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SO for split ebc dbcs string//~va8kI~
      	optild=0;                                                  //~va8kI~
        if (swinsertsosi1)                                         //~va8kI~
        	optild|=FCILDEO_INSERT_SO;                             //~va8kI~
        if (swinsertsosi2)                                         //~va8kI~
        	optild|=FCILDEO_APPEND_SI;                             //~va8kI~
    	rc=fcmdisrtlinedbcsebcsosi(optild,Ppcw,plh,pdata,pdbcs,newlen);//~va8kI~
        swinsertsosi1=swinsertsosi2;	//for next line            //~va8kI~
      }                                                            //~va8kI~
      else                                                         //~va8kI~
    	rc=fcmdisrtlinedbcs(Ppcw,plh,pdata,pdbcs,newlen);          //~v75eR~
        if (rc)                                                    //~v75eI~
        	return rc;                                             //~v75eI~
//        newlen=copyedlen;   //advance on pdbcs                   //~v75eR~
        insertsw=1;                                                //~v75eI~
        plh=UGETQNEXT(plh);	//inserted                             //~v75eI~
        expandsw=(rlen>newlen)||(errsw==1);	//not split last or split err(return join start plh is next of inserted)//~va8uR~
      if (expandsw)                                                //~va8uI~
      {                                                            //~va8uI~
		rc=fcmdtflowindentshift(Popt,plh,Pwidth,0,0,0);//shift by indentation on plh//~v75eR~
        if (rc>1)     //1:shifted                                  //~v75eR~
        	return rc;                                             //~v75eI~
        if (linefilledsw)	//splitted by delm or shift by keepword//~v75eI~
			if (fcmdplhpadspace(Popt,Ppcw,plh,Pwidth)==UALLOC_FAILED)//~v75eI~
		        return UALLOC_FAILED;                              //~v75eI~
      }                                                            //~va8uI~
//        if (errsw)                                                 //~v74ZI~//~va8uR~
//            if (!(Popt & FCSPL_ALLWIDTH0))                         //~v74ZI~//~va8uR~
//            {                                                      //~v74ZI~//~va8uR~
//                lcmdshifterr(plh,0,0);  //set reverse              //~v74ZI~//~va8uR~
//                (*Pperrctr)++;                                     //~v74ZI~//~va8uR~
//            }                                                      //~v74ZI~//~va8uR~
    }//split long line                                             //~v74ZI~
    if (swinsertsosi0)	//setdbcstbl after si inserted             //~va8kI~
    {                                                              //~va8kI~
		if (fcmdebcappendsoeol(0,plh0))	//append si to top plh     //~va8kI~
        	return UALLOC_FAILED;                                  //~va8kI~
		xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);           //~va8kI~
    }                                                              //~va8kI~
    if (toplinefilledsw)//topline tail shift out by width          //~v75eI~
    {                                                              //~v75eI~
        if (fcmdplhpadspace(Popt,Ppcw,plh0,Pwidth)==UALLOC_FAILED) //~v75eI~
            return UALLOC_FAILED;                                  //~v75eI~
    }                                                              //~v75eI~
    if (insertsw && errsw==1)	//last split err                   //~v75eR~
        plh=UGETQNEXT(plh);  //next of inserted                    //~v75eR~
    else                                                           //~v75eI~
    if (!insertsw && toplinefilledsw)//retry when trailer is all space//~v75eR~
        plh=UGETQNEXT(plh);                                        //~v74ZI~
    *Ppplh=plh;                                                    //~v74ZI~
    return 0;                                                      //~v74ZI~
}//fcmdtflowsplit                                                  //~v74ZR~
//**************************************************************** //~v75eI~
// fcmdtflowsplitlen                                               //~v75eI~
//*get splt length considering KEEPWORD parm                       //~v75eI~
//*parm1 :cmd option                                               //~v75eI~
//*parm2 :pada                                                     //~v75eI~
//*parm3 :pdbcs                                                    //~v75eI~
//*parm4 :delmstr                                                  //~v75eI~
//*parm5 :datalen                                                  //~v75eI~
//*parm6 :target width                                             //~v75eI~
//*parm7 :&splitlen                                                //~v75eI~
//*return:rc: 0:short rec or split by delm,1:could not split,2:dbcs split by SBCS option//~v75eR~
//*           4:dbcs could not be split,len was not changed        //~va8kI~
//**************************************************************** //~v75eI~
int fcmdtflowsplitlen(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v75eI~
					int Pdatalen,int Pwidth,int *Ppsplitlen,int *Pplinefilledsw)//~v75eR~
{                                                                  //~v75eI~
	int splitlen,len,rlen,rc2;                                     //~v75BR~
    UCHAR *pc;                                                     //~v75eI~
    int headcnt;                                                   //~va8uI~
    int width0;                                                    //~v@@@R~
    int swtol=0;                                                   //~v@@@I~
//*****************************                                    //~v75eI~
    *Ppsplitlen=Pdatalen;	//default                              //~v75eI~
    *Pplinefilledsw=0;                                             //~v75eI~
    if (Popt & FCSPL_SPLITBNDS)                                    //~v@@@I~
        width0=Pwidth;                                             //~v@@@R~
    else                                                           //~v@@@I~
        width0=0;                                                  //~v@@@I~
	if (Pdatalen && Ppdelmstr)                                     //~v75eR~
    {                                                              //~v75eI~
      if ((Popt & FCSPL_TFTOPLINE) && (Popt & FCSPL_TOL))	//chk space only before delm//~va8uI~
      {                                                            //~va8uI~
		headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Pdatalen);//~va8uI~
        Sotheropt|=SOTHO_TOPLINETOL;   //err when TOL is delm      //~va8uI~
//  	rc2=fcmdsplitlen(Popt|FCSPL_ALLWIDTH0,Ppdata+headcnt,Ppdbcs+headcnt,Ppdelmstr,Pdatalen-headcnt,0,&splitlen);//0:width,serach first//~va8uI~//~v@@@R~
		rc2=fcmdsplitlen(Popt|FCSPL_ALLWIDTH0,Ppdata+headcnt,Ppdbcs+headcnt,Ppdelmstr,Pdatalen-headcnt,width0,&splitlen);//width for ebc dbcs2nd ok//~v@@@I~
        Sotheropt&=~SOTHO_TOPLINETOL;                              //~va8uI~
        splitlen+=headcnt;                                         //~va8uI~
      }                                                            //~va8uI~
      else                                                         //~va8uI~
      {                                                            //~va8uI~
        if (Popt & FCSPL_TFJOIN)                                   //~va8uI~
		  Sotheropt|=SOTHO_JOIN;                                   //~va8uI~
//  	rc2=fcmdsplitlen(Popt|FCSPL_ALLWIDTH0,Ppdata,Ppdbcs,Ppdelmstr,Pdatalen,0,&splitlen);//0:width,serach first//~v75eR~//~v@@@R~
    	rc2=fcmdsplitlen(Popt|FCSPL_ALLWIDTH0,Ppdata,Ppdbcs,Ppdelmstr,Pdatalen,width0,&splitlen);//0:width,serach first//~v@@@I~
		Sotheropt&=~SOTHO_JOIN;                                    //~va8uM~
        if (Popt & FCSPL_TOL)	//chk space only before delm       //~va8uI~
			if (Sotheropt & SOTHO_DELMONTOL)   //delm matched on tol//~va8uI~
            {                                                      //~va8uI~
//          	return 1;						//join end         //~va8uI~//~v@@@R~
            	swtol=1;        //not topline and not joined line,matched at TOL;accept concatination//~v@@@I~
            }                                                      //~va8uI~
      }                                                            //~va8uI~
//        if (rc2==1)                                              //~va8qR~
//            if (Sotheropt & SOTHO_DELMONTOL)   //delm matched on tol//~va8qR~
//                rc2=0;                                           //~va8qR~
        if (!rc2)	//delmfound                                    //~v75eI~
        {                                                          //~v75eI~
          if (!swtol)                                              //~v@@@I~
        	*Pplinefilledsw=FCSPLRC_DELMFOUND;		//splitted at before the word//~v75eI~
        	if (splitlen<=Pwidth)                                  //~v75eI~
            {                                                      //~v75eI~
            	*Ppsplitlen=splitlen;                              //~v75eI~
                return 0;                                          //~v75eI~
            }                                                      //~v75eI~
        }                                                          //~v75eI~
        else                                                       //~v@@@I~
        {                                                          //~v@@@I~
          	if (swtol)//rc2=2                                      //~v@@@I~
          	{                                                      //~v@@@I~
        		*Pplinefilledsw=FCSPLRC_DELMFOUND;		//splitted at before the word//~v@@@I~
            	*Ppsplitlen=splitlen;                              //~v@@@I~
                return 0;                                          //~v@@@I~
        	}                                                      //~v@@@I~
        }                                                          //~v@@@I~
    }                                                              //~v75eI~
	Sotheropt&=~SOTHO_APPENDSO;    //append SO for split ebc dbcs string//~va8kM~
    if (Pdatalen<Pwidth)    //fully included                       //~v75eR~
        return 0;   //can be joind                                 //~v75eR~
    rlen=Pdatalen-Pwidth;                                          //~v75eI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    if (UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*(Ppdata+Pwidth-1),*(Ppdbcs+Pwidth-1)))//~va50I~
  #else                                                            //~va50I~
    if (UTF_eqspace(Sswutf8file,*(Ppdata+Pwidth-1),*(Ppdbcs+Pwidth-1)))//~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (*(Ppdata+Pwidth-1)==' ')                                   //~v75eR~
#endif                                                             //~va20I~
    {                                                              //~v75eI~
        *Ppsplitlen=Pwidth; //leave last space                     //~v75eI~
        *Pplinefilledsw=FCSPLRC_SPACEDELM;		//split by space at edge//~v75mI~
        return 0;                                                  //~v75eI~
    }                                                              //~v75eI~
//*right end is not space                                          //~v75uI~
    for (;;)                                                       //~v75uI~
    {                                                              //~v75uI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      pc=UCVEBCUTF_umemrchr_space(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,(UINT)Pwidth); //search last space in the range//~va50I~//~vb2DR~
        pc=UCVEBCUTF_umemrchr_space(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Pwidth); //search last space in the range//~vb2DI~
	#else                                                          //~va50I~
        pc=UTF_umemrchr(Sswutf8file,Ppdata,Ppdbcs,' ',(UINT)Pwidth); //search last space in the range//~va20I~
    #endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        pc=umemrchr(Ppdata,' ',(UINT)Pwidth); //search last space in the range//~v75uI~
#endif                                                             //~va20I~
        if (!pc)                                                   //~v75uI~
            break;	//chk space after the word                     //~v75uI~
//      len=(int)((ULONG)pc-(ULONG)Ppdata)+1;    //including last space//~v75uI~//~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)Ppdata)+1;    //including last space//~vafkI~
        if (Popt & FCSPL_TFTOPLINE                                 //~v75uI~
        && len==Sindentoffs)   //space is by shift only            //~v75uI~
            break;	//chk space after the word                     //~v75uI~
        *Ppsplitlen=len;                                           //~v75uI~
        *Pplinefilledsw=FCSPLRC_WORDKEPT;		//splitted at before the word//~v75uI~
        return 0;                                                  //~v75uI~
    }                                                              //~v75uI~
//*no intermediate spce                                            //~v75uI~
	if (Popt & FCSPL_TFJOIN)	//2ndline                          //~v75uI~
    	return 1;   //no delm found(move to next line)             //~v75uI~
    if (Popt & FCSPL_KEEPWORD)  //avoid word split                 //~v75uI~
    	return 1;   //no delm found(move to next line)             //~v75uI~
    if (Popt & FCSPL_KEEPWORDSN)  //allow split after the word     //~v75eR~
    {                                                              //~v75eI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	    pc=UCVEBCUTF_umemchr_space(Sswebcfile,Sswutf8file,Ppdata+Pwidth,Ppdbcs+Pwidth,rlen);	//search last space in the range//~va50R~
    #else                                                          //~va50I~
	    pc=UTF_memchr(Sswutf8file,Ppdata+Pwidth,Ppdbcs+Pwidth,' ',rlen);	//search last space in the range//~va20R~
    #endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	    pc=memchr(Ppdata+Pwidth,' ',(UINT)rlen);	//search last space in the range//~v75eI~
#endif                                                             //~va20I~
	    if (!pc)                                                   //~v75eI~
        	return 1;   //no delm found                            //~v75eI~
//    	len=(int)((ULONG)pc-(ULONG)Ppdata)+1;    //including last space//~v75eI~//~vafkR~
    	len=(int)((ULPTR)pc-(ULPTR)Ppdata)+1;    //including last space//~vafkI~
	    *Ppsplitlen=len;                                           //~v75eI~
        *Pplinefilledsw=FCSPLRC_WORDKEPTAFTER;		//splitted at before the word//~v75eR~
	    return 0;          //splitted at after the word            //~v75eR~
    }                                                              //~v75eI~
//split in the word                                                //~v75eI~
    rc2=fcmdsplitlen(Popt|FCSPL_SETDBCSERR,Ppdata,Ppdbcs,0,Pdatalen,Pwidth,Ppsplitlen);//0:delmstr dbcs split chk//~v75eR~
    return rc2;	//2 or 4(dbcs split err)                           //~v75eI~
}//fcmdtflowsplitlen                                               //~v75eI~
//**************************************************************** //~v75aI~
// get end plh by specified max paragno                            //~v75aI~
// rc:1:plh2 changed                                               //~v75aI~
//**************************************************************** //~v75aI~
int fcmdgetparagendplh(int Popt,PULINEH Pplh1,PULINEH *Ppplh2,int Pmaxparagno,int Pbndsoffs1,int Pbndsoffs2)//~v75iR~
{                                                                  //~v75aI~
	PULINEH plh,plh2;                                              //~v75aR~
    int rcparag=0,rc=0;                                            //~v75aR~
    int len,maxparagnosv;                                          //~v75kR~
//*************************                                        //~v75aI~
    maxparagnosv=Smaxparagno;   //save original                    //~v75kI~
    Smaxparagno=Pmaxparagno;                                       //~v75kI~
    Sindentoffs=-1;	//reset to init value                          //~v75kI~
    for (plh=Pplh1,plh2=*Ppplh2;plh && plh!=plh2;plh=UGETQNEXT(plh))//~v75aI~
    {                                                              //~v75aI~
        if (plh->ULHtype!=ULHTDATA)                                //~v75aI~
        	continue;                                              //~v75aI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v75aI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v75aI~
                return rc;                                         //~v75aI~
		len=plh->ULHlen-Pbndsoffs1;                                //~v75iI~
        if (Pbndsoffs2)                                            //~v75iI~
        	len=min(len,(Pbndsoffs2-Pbndsoffs1));                  //~v75iI~
#ifdef UTF8UCS2                                                    //~va20I~
		rcparag=fcmdtflowgetindent(Popt,plh,plh->ULHdata+Pbndsoffs1,plh->ULHdbcs+Pbndsoffs1,len,0);//~va20I~
#else                                                              //~va20I~
		rcparag=fcmdtflowgetindent(Popt,plh,plh->ULHdata+Pbndsoffs1,len,0);//~v75iR~
#endif                                                             //~va20I~
        if (rcparag==FCSPLRC_PSTOP)	//paragraph changed            //~v75aI~
        	break;                                                 //~v75aI~
    }                                                              //~v75aI~
    Sindentoffs=-1;	//reset to init value                          //~v75aI~
    Smaxparagno=maxparagnosv;                                      //~v75kI~
    if (rcparag==FCSPLRC_PSTOP)	//paragraph changed                //~v75aI~
    {                                                              //~v75aI~
    	*Ppplh2=plh;                                               //~v75aI~
        rc=1;                                                      //~v75aI~
    }                                                              //~v75aI~
    return rc;                                                     //~v75aI~
}//fcmdgetparagendplh                                              //~v75aI~
//**************************************************************** //~v74ZI~
// set indentation space at top of line                            //~v74ZI~
// output:shift count;<0:shoten count,>0:expand cnt                //~v74ZI~
//*rc   :1:1st time indetation gotten; 2:1st line space>Pwidth indentation set to 0//~v74ZI~
//*     :PSTOP stop by indentation change,-1:new paragraph by indentation change//~v758I~
//**************************************************************** //~v74ZI~
#ifdef UTF8UCS2                                                    //~va20I~
int fcmdtflowgetindent(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int *Ppshiftcnt)//~va20I~
#else                                                              //~va20I~
int fcmdtflowgetindent(int Popt,PULINEH Pplh,UCHAR *Pdata,int Pdatalen,int *Ppshiftcnt)//~v751R~
#endif                                                             //~va20I~
{                                                                  //~v74ZI~
    int shiftcnt,headcnt,rc=0;                                     //~v74ZR~
    int plholdupctr;                                               //~v75cI~
static PULINEH Sparagplh;                                          //~v759R~
static int Sparagcnt;                                              //~v759I~
static int Slineno;                                                //~v75gR~
static PULINEH Slinenoplh;                                         //~v75gR~
	int indentoffs;                                                //~v75eI~
    int nullsw=0;                                                  //~v75LI~
//*****************************                                    //~v74ZI~
  if (Pdatalen>0)                                                  //~v75aI~
// if ((Popt & FCSPL_SPWKPARAG))	//if BNDS,only once call for each plh,so skip upctr compare//~v75iR~//~vb2DR~
   if (((UINT)Popt & FCSPL_SPWKPARAG))	//if BNDS,only once call for each plh,so skip upctr compare//~vb2DI~
    headcnt=Sbndsheadcnt;	//parm from getsrc                     //~v75iI~
   else                                                            //~v75iI~
   {                                                               //~v75LI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,Pdata,Pdbcs,(UINT)Pdatalen);//~va50I~//~vb2DR~
    headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,Pdata,Pdbcs,Pdatalen);//~vb2DI~
  #else                                                            //~va50I~
	headcnt=(int)UTF_umemspnc(Sswutf8file,Pdata,Pdbcs,' ',(UINT)Pdatalen);//~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
	headcnt=(int)umemspnc(Pdata,' ',(UINT)Pdatalen);                          //~v758R~
#endif                                                             //~va20I~
    nullsw=(headcnt==Pdatalen); //all space                        //~v75LI~
   }                                                               //~v75LI~
  else                                                             //~v75aI~
  {                                                                //~v75LI~
  	headcnt=0;                                                     //~v75aI~
    nullsw=1;                                                      //~v75LI~
  }                                                                //~v75LI~
	if (Sindentoffs<0)                                             //~v74ZI~
    {                                                              //~v74ZI~
        Sparagplh=0;                                               //~v759I~
        Sparagcnt=1;                                               //~v75gR~
        Slineno=0;                                                 //~v75gR~
//    if (!(Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm      //~v75iR~//~vb2DR~
      if (!((UINT)Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm  //~vb2DI~
        Slinenoplh=Pplh;                                           //~v75gI~
      if (Sindentoffs0>=0)	//parameter specified                  //~v758I~
      {                                                            //~v758I~
      	Sindentoffs=Sindentoffs0;                                  //~v758I~
        rc=1;                                                      //~v758I~
      }                                                            //~v758I~
      else                                                         //~v758I~
      {                                                            //~v75LI~
    	if (headcnt<Sindentoffsmax)                                //~v751R~
        {                                                          //~v74ZI~
			Sindentoffs=headcnt;                                   //~v74ZI~
            rc=1;                                                  //~v74ZI~
        }                                                          //~v74ZI~
        else                                                       //~v74ZI~
        {                                                          //~v74ZI~
        	Sindentoffs=0;                                         //~v74ZI~
            rc=2;                                                  //~v74ZI~
        }                                                          //~v74ZI~
      }                                                            //~v75LI~
        Sindentoffsbyalldata=headcnt;                              //~v75jI~
    }                                                              //~v74ZI~
    else    //2nd time                                             //~v758I~
    {                                                              //~v758I~
//   if (Smaxparagno>=0)	//not ignore parag                     //~v75wR~
     if (!(Popt & FCSPL_TFNOP))	//not ignore parag                 //~v75wI~
     {                                                             //~v75hI~
//    if (Pplh->ULHupctr<=Soldupctr)	//updated by this cmd      //~v75cR~
//    if ((Popt & FCSPL_SPWKPARAG))	//if BNDS,only once call for each plh,so skip upctr compare//~v75iR~//~vb2DR~
      if (((UINT)Popt & FCSPL_SPWKPARAG))	//if BNDS,only once call for each plh,so skip upctr compare//~vb2DI~
        plholdupctr=Soldplhupctr;  //donot access plh              //~v75iI~
      else                                                         //~v75iI~
      {                                                            //~v75iI~
        plholdupctr=Pplh->ULHupctr;                                //~v75cI~
        if ((Soldplhupctr>=0)    //splitspace1 updated             //~v75cI~
        &&  (Pplh==Soldplhupctrplh)                                //~v75cI~
//      &&  !(Popt & FCSPL_SPWKPARAG))	//if BNDS,space1data is used//~v75iR~
        )                                                          //~v75iI~
        	plholdupctr=Soldplhupctr;                              //~v75cI~
      }                                                            //~v75iI~
      if (plholdupctr<=Soldupctr)	//updated by this cmd          //~v75cR~
      {                                                            //~v75gI~
//     if ((Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm      //~v75iR~//~vb2DR~
       if (((UINT)Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm  //~vb2DI~
       {                                                           //~v75LI~
          if (Sindentoffsbyalldata>=0)    //not after null line    //~v75LI~
        	Slineno++;                                             //~v75iI~
       }                                                           //~v75LI~
       else                                                        //~v75iI~
      	if (Pplh!=Slinenoplh)                                      //~v75gI~
        {                                                          //~v75gI~
        	Slinenoplh=Pplh;                                       //~v75gI~
          if (Sindentoffsbyalldata>=0)    //not after null line    //~v75LI~
        	Slineno++;                                             //~v75gR~
        }                                                          //~v75gI~
        if (headcnt<Sindentoffsmax)                                //~v75eI~
            indentoffs=headcnt;                                    //~v75eI~
        else                                                       //~v75eI~
            indentoffs=0;                                          //~v75eI~
//      if (headcnt!=Sindentoffs)   //indentation changed          //~v75eR~
//      if (headcnt!=Sindentoffsbyalldata)   //indentation changed //~v75LR~
        if (headcnt!=Sindentoffsbyalldata    //indentation changed //~v75LI~
		|| nullsw)                           //null line           //~v75LI~
        {                                                          //~v758I~
          if ((Popt & FCSPL_IND1ST)     //paragraph indetation base is from 2nd line//~v75gR~
          ||  nullsw 	//reached null line                        //~v75LI~
          ||  (Slineno!=1)) 	//not 2ndline                      //~v75gR~
          {                                                        //~v75eI~
//         if ((Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm  //~v75iR~//~vb2DR~
           if (((UINT)Popt & FCSPL_SPWKPARAG))	//if BNDS,no plh parm//~vb2DI~
           {                                                       //~v75iI~
        	  if (Sindentoffsbyalldata>=0)    //not after null line//~v75LI~
            	Sparagcnt++;                                       //~v75iI~
                Slineno=0;			//topline of new paragrapth    //~v75iI~
                rc=FCSPLRC_PNEW;    //33              //start new paragraph//~v75iI~
           }                                                       //~v75iI~
           else                                                    //~v75iI~
            if (Pplh!=Sparagplh)                                   //~v759I~
            {                                                      //~v759I~
            	Sparagplh=Pplh;                                    //~v759I~
        	  if (Sindentoffsbyalldata>=0)    //not after null line//~v75LI~
            	Sparagcnt++;                                       //~v759I~
                Slineno=0;			//topline of new paragrapth    //~v75gM~
                rc=FCSPLRC_PNEW;    //33              //start new paragraph//~v75iI~
            }                                                      //~v759I~
           if (rc==FCSPLRC_PNEW)    //33              //start new paragraph//~v75iI~
            if (Smaxparagno>0 && Sparagcnt>Smaxparagno)            //~v75gR~
                rc=FCSPLRC_PSTOP;    //32              //stop paragraph//~v758R~
          }//new paragraph                                         //~v75eI~
            if (Sindentoffs0>=0)	//parameter specified          //~v758I~
		        Sindentoffs=Sindentoffs0;                          //~v758M~
            else                                                   //~v758I~
//     	      if (headcnt<Sindentoffsmax)                          //~v75eR~
//              Sindentoffs=headcnt;                               //~v75eR~
//            else                                                 //~v75eR~
//              Sindentoffs=0;                                     //~v75eR~
                Sindentoffs=indentoffs;                            //~v75eI~
        	Sindentoffsbyalldata=headcnt;                          //~v75jI~
        }                                                          //~v758I~
      }//not updated plh                                           //~v75gI~
     }//!ignore paragraph                                          //~v75hI~
    }                                                              //~v758I~
  	if (nullsw)	//1st line is null space                           //~v75LI~
  	{                                                              //~v75LI~
//    	Sindentoffs=0;             	//del null line                //~v75LI~
      	Sindentoffs=Sindentoffsmax;	//keep null line               //~v75LR~
        Sindentoffsbyalldata=-1;    //to chk continued null line   //~v75LI~
  	}                                                              //~v75LI~
    shiftcnt=Sindentoffs-headcnt;                                  //~v74ZI~
    if (Ppshiftcnt)                                                //~v74ZI~
    	*Ppshiftcnt=shiftcnt;                                      //~v74ZI~
    return rc;                                                     //~v74ZI~
}//fcmdtflowgetindent                                              //~v74ZI~
//**************************************************************** //~v74ZI~
// set indentation space at top of line                            //~v74ZI~
// output:new datalen                                              //~v74ZR~
//*rc   :UALLOC_FAILED,1:shifted,PSTOP(32)                         //~v758R~
//**************************************************************** //~v74ZI~
int fcmdtflowindentshift(int Popt,PULINEH Pplh,int Pwidth,UCHAR *Pcontdata,UCHAR *Pcontdbcs,int *Ppnewlen)//~v74ZR~
{                                                                  //~v74ZI~
	UCHAR *pdata,*pdbcs;                                           //~v74ZI~
    int rc,shiftcnt,newlen,headcnt,ulhlen,indentoffs;              //~v74ZR~
    int rcparag;                                                   //~v758I~
//*****************************                                    //~v74ZI~
	pdata=Pplh->ULHdata;                                           //~v74ZI~
	pdbcs=Pplh->ULHdbcs;                                           //~v74ZI~
    ulhlen=Pplh->ULHlen;                                           //~v74ZR~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,ulhlen);//~va50R~
  #else                                                            //~va50R~
	headcnt=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',ulhlen); //~va20I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
	headcnt=(int)umemspnc(pdata,' ',(UINT)ulhlen);                            //~v74ZI~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	rcparag=fcmdtflowgetindent(Popt,Pplh,pdata,pdbcs,ulhlen,&shiftcnt);//~va20I~
#else                                                              //~va20I~
	rcparag=fcmdtflowgetindent(Popt,Pplh,pdata,ulhlen,&shiftcnt);  //~v751R~
#endif                                                             //~va20I~
    if (rcparag==FCSPLRC_PSTOP)                                    //~v758I~
    	return rcparag;                                            //~v759R~
    rc=(shiftcnt!=0);                                              //~v74ZI~
    newlen=ulhlen+shiftcnt;                                        //~v74ZI~
	if (Ppnewlen)                                                  //~v74ZI~
    	*Ppnewlen=newlen;                                          //~v74ZI~
    if (Pcontdbcs)	//req to set to work                           //~v74ZI~
    {                                                              //~v74ZI~
    	indentoffs=Sindentoffs;                                    //~v74ZI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	memset(Pcontdata,Schspace,(UINT)indentoffs);               //~va50I~
#else                                                              //~va50R~
    	memset(Pcontdata,' ',(UINT)indentoffs);                    //~v74ZI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	memset(Pcontdbcs,0,(UINT)indentoffs);                      //~v74ZI~
        memcpy(Pcontdata+indentoffs,pdata+headcnt,(UINT)(ulhlen-headcnt)); //~v74ZI~
        memcpy(Pcontdbcs+indentoffs,pdbcs+headcnt,(UINT)(ulhlen-headcnt)); //~v74ZI~
		chartabclear(Pcontdbcs+indentoffs,ulhlen-headcnt);         //~v74ZI~
    }                                                              //~v74ZR~
    else                                                           //~v74ZI~
    {                                                              //~v74ZI~
        if (shiftcnt)                                              //~v74ZR~
        {                                                          //~v74ZI~
            if (shiftcnt<0) //to be shift to left                  //~v74ZR~
            {                                                      //~v74ZR~
                memcpy(pdata+headcnt+shiftcnt,pdata+headcnt,(UINT)(ulhlen-headcnt));//~v74ZR~
                memcpy(pdbcs+headcnt+shiftcnt,pdbcs+headcnt,(UINT)(ulhlen-headcnt));//~v74ZR~
            }                                                      //~v74ZR~
            else                                                   //~v74ZR~
            {                                                      //~v74ZR~
                if (newlen>Pplh->ULHbufflen)                       //~v74ZR~
                    if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)      //expand buff//~v74ZR~
                        return UALLOC_FAILED;                      //~v74ZR~
                pdata=Pplh->ULHdata;                               //~v74ZR~
                pdbcs=Pplh->ULHdbcs;                               //~v74ZR~
                memmove(pdata+headcnt+shiftcnt,pdata+headcnt,(UINT)(ulhlen-headcnt));//~v74ZR~
                memmove(pdbcs+headcnt+shiftcnt,pdbcs+headcnt,(UINT)(ulhlen-headcnt));//~v74ZR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                memset(pdata+headcnt,Schspace,(UINT)shiftcnt);     //~va50I~
#else                                                              //~va50I~
                memset(pdata+headcnt,' ',(UINT)shiftcnt);                //~v751I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                memset(pdbcs+headcnt,0  ,(UINT)shiftcnt);                //~v751I~
            }                                                      //~v74ZR~
            Pplh->ULHlen=newlen;                                   //~v74ZR~
            chartabclear(pdbcs,newlen);                            //~v74ZR~
        }                                                          //~v74ZI~
    }                                                              //~v74ZI~
    return rc;                                                     //~v74ZR~
}//fcmdtflowindentshift                                            //~v758R~
//**************************************************************** //~v74YI~
// fcmdsplitspace1                                                 //~v74YI~
// continued space to 1 space                                      //~v74YI~
//return:rc:UALLOC_FAILED                                          //~v74YI~
//**************************************************************** //~v74YI~
int fcmdsplitspace1(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int *Ppdelctr)//~v75cR~
{                                                                  //~v74YI~
    int   rlen,delctr,totctr,ulhlen;                               //~v74YI~
    UCHAR *pdata,*pdata0,*pdbcs0;                                  //~v74YR~
    int oldupctr=-1;                                               //~v75cI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR *pdbcs;                                                  //~va20I~
#endif                                                             //~va20I~
//*********************************                                //~v74YI~
    ulhlen=Pplh->ULHlen;                                           //~v74YR~
    pdata=pdata0=Pplh->ULHdata;                                    //~v74YR~
    if (Popt & FCSPL_TFLOW)	//keep head space for indentation(TFLOW without BNDS)//~v75cI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	pdata+=UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,Pplh->ULHdbcs,ulhlen);	//keep head space//~va50I~
    #else                                                          //~va50I~
    	pdata+=UTF_umemspnc(Sswutf8file,pdata,Pplh->ULHdbcs,' ',ulhlen);	//keep head space//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	pdata+=umemspnc(pdata,' ',(UINT)ulhlen);	//keep head space      //~v75cI~
#endif                                                             //~va20I~
    pdbcs0=Pplh->ULHdbcs;                                          //~v74YR~
    for (totctr=0;;)                                               //~v74YR~
    {                                                              //~v74YI~
//      rlen=ulhlen-(int)((ULONG)pdata-(ULONG)pdata0);                  //~v74YI~//~vafkR~
        rlen=ulhlen-(int)((ULPTR)pdata-(ULPTR)pdata0);             //~vafkI~
        if (rlen<=0)                                               //~v74YI~
        	break;                                                 //~v74YI~
#ifdef UTF8UCS2                                                    //~va20I~
		pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);                   //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	pdata=UCVEBCUTF_umemchr_space(Sswebcfile,Sswutf8file,pdata,pdbcs,rlen);//~va50I~
    #else                                                          //~va50I~
    	pdata=UTF_memchr(Sswutf8file,pdata,pdbcs,' ',rlen);        //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	pdata=memchr(pdata,' ',(UINT)rlen);                        //~v74YR~
#endif                                                             //~va20I~
        if (!pdata)                                                //~v74YR~
        	break;                                                 //~v74YI~
        pdata++;                                                   //~v74YR~
//      rlen=ulhlen-(int)((ULONG)pdata-(ULONG)pdata0);                  //~v74YR~//~vafkR~
        rlen=ulhlen-(int)((ULPTR)pdata-(ULPTR)pdata0);             //~vafkI~
#ifdef UTF8UCS2                                                    //~va20I~
		pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);                   //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      delctr=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,(UINT)rlen);//~va50I~//~vb2DR~
        delctr=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,rlen);//~vb2DI~
    #else                                                          //~va50I~
        delctr=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',(UINT)rlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        delctr=(int)umemspnc(pdata,' ',(UINT)rlen);                           //~v74YR~
#endif                                                             //~va20I~
        if (delctr)                                                //~v74YI~
        {                                                          //~v74YI~
        	if (!totctr)	//1st update                           //~v74YI~
            {                                                      //~v74YI~
            	oldupctr=Pplh->ULHupctr;                           //~v75cI~
//*reduce space,no change on dbcstbl                               //~va50I~
				if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v74YI~
    				return UALLOC_FAILED;                          //~v74YI~
			    chartabclear(pdbcs0,ulhlen);                       //~v74YI~
            }                                                      //~v74YI~
        	totctr+=delctr;                                        //~v74YI~
            memcpy(pdata,pdata+delctr,(UINT)(rlen-delctr));        //~v74YR~
            memcpy(pdbcs0+ulhlen-rlen,pdbcs0+ulhlen-rlen+delctr,(UINT)(rlen-delctr));//~v74YI~
            ulhlen-=delctr;                                        //~v74YI~
        }                                                          //~v74YI~
    }                                                              //~v74YI~
    if (Ppdelctr)                                                  //~v74YI~
    	*Ppdelctr=totctr;                                          //~v74YI~
    Pplh->ULHlen-=totctr;                                          //~v74YR~
    Soldplhupctr=oldupctr;	//parm to getindent                    //~v75cI~
    Soldplhupctrplh=Pplh;   //parm to getindent                    //~v75cI~
    return 0;                                                      //~v74YI~
}//fcmdsplitspace1                                                 //~v74YI~//~va20R~
//**************************************************************** //~v45xI~
// fcmdsplitjoin                                                   //~v45xI~
//*join short line with next up to width by delm tbl               //~v45xI~
//*     split line or short line for ALL case                      //~v45xI~
//*parm1 :pcw                                                      //~v45xI~
//*parm2 :&plh short line(len<=width);output:next plh to be chked  //~v45xR~
//*parm3 :next of end plh                                          //~v45xI~
//*parm4 :split width                                              //~v45xR~
//*parm5 :delm string                                              //~v45xR~
//*parm6 :join work area                                           //~v45xR~
//*parm7 :opt                                                      //~v45xR~
//*parm8 :ins/del ctr                                              //~v45xI~
//*parm9 :line no with no delm                                     //~v45xI~
//*return:rc: 0:no update,1:update occuered,4:err                  //~v45xR~
//            PSTOP,UALLOC_FAILED                                  //~v758I~
//**************************************************************** //~v45xI~
int fcmdsplitjoin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v45xR~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,int Popt,      //~v45xR~
					int *Ppdonectr,int *Pperrctr)                  //~v45xR~
{                                                                  //~v45xI~
    PULINEH plh,plh0,plhn;                                         //~v45xR~
    int   rlen,newlen,len,ulhlen,offs,contlen,addlen;              //~v45xR~
    UCHAR *pdata,*pdbcs;                                           //~v45xR~
    int   rc=0,tabsw,splitflag,splitflag2,errsw,splittype,lasttabsw=0,lastdbcssw=0;//~v45xR~
    int  delsw=0;                                                  //~v77fI~
    int swinsertsosi,optild;                                       //~va8kI~
    int swebcfileconcatdbcs;                                       //~va8wI~
    PULINEH plhebcconcatold=0;                                     //~va8wI~
    int droppedsosilen;                                            //~va8wI~
//*********************************                                //~v45xI~
    if (Popt & FCSPL_TFLOW) //TFLOW pattern                        //~v74ZI~
		return fcmdtflowjoin(Ppcw,Ppplh,Pplh2,Pwidth,Ppdelmstr,Pcontwk,Popt,Ppdonectr,Pperrctr);//~v74ZI~
	splittype=Popt & FCSPL_TYPEMASK;                               //~v45xI~
    plh0=plh=*Ppplh;                                               //~v45xR~
    plhn=UGETQNEXT(plh);                                           //~v45xR~
    pdata=Pcontwk;                                                 //~v45xI~
    pdbcs=Pcontwk+Pwidth+1;                                        //~v45xR~
    splitflag=UCBITCHK(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2));   //~v45xR~
    ulhlen=plh->ULHlen;                                            //~v45xI~
//gather data upto width                                           //~v45xI~
	tabsw=0;                                                       //~v45xI~
    for (contlen=0,rlen=0,splitflag2=0;plh && plh!=Pplh2;plh=plhn) //~v45xR~
    {                                                              //~v45xI~
//      plh->ULHflag6&=~(ULHF6EBCDBCSCONCAT1|ULHF6EBCDBCSCONCAT2); //~va8wI~//+vb2DR~
        plh->ULHflag6&=(UCHAR)(~(ULHF6EBCDBCSCONCAT1|ULHF6EBCDBCSCONCAT2));//+vb2DI~
		plhn=UGETQNEXT(plh);                                       //~v45xI~
        if (plh->ULHtype!=ULHTDATA)                                //~v45xI~
        	continue;                                              //~v45xI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v45xI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v45xI~
                return rc;                                         //~v45xR~
	    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v45xI~
    		if (rc=lcmdincm(Ppcw,plh),rc)                          //~v45xI~
        		return rc;                                         //~v45xI~
    	splitflag2=UCBITCHK(plh->ULHflag2,ULHF2SPLIT1);//last plh remained//~v45xM~
        len=Pwidth-contlen;                                        //~v45xR~
		if (Popt & FCSPL_SPACE1)	//bnds is set                  //~v74YI~
            if (rc=fcmdsplitspace1(0,Ppcw,plh,0),rc)   //reduce space//~v74YI~
            	return rc;                                         //~v74YI~
        ulhlen=plh->ULHlen;                                        //~v45xI~
        lasttabsw=0;                                               //~v45xI~
        swebcfileconcatdbcs=fcmdebcchkdbcsconcat(Popt,pdata,pdbcs,contlen,plh->ULHdata,plh->ULHdbcs,ulhlen);//~va8wI~
        if (swebcfileconcatdbcs)                                   //~va8wI~
        {                                                          //~va8wI~
        	len++/*width*/,ulhlen--,contlen--;                     //~va8wR~
        }                                                          //~va8wI~
        if (ulhlen<len)                                            //~v45xR~
        	len=ulhlen;                                            //~v45xI~
        else                                                       //~v45xI~
        	if (ulhlen>len)                                        //~v45xI~
            {                                                      //~v45xI~
              if (!Sswebcfile)                                     //~va8wR~
              {                                                    //~va8wI~
            	lasttabsw=1;	//1byte mode copyed sw             //~v45xI~
            	len++;                                             //~v45xI~
              }                                                    //~va8wI~
            }                                                      //~v45xI~
            else                                                   //~v45xI~
                if (splitflag2) //last splitted to next            //~v45xI~
                {                                                  //~v45xI~
                  if (plhn->ULHlen)                                //~v77fI~
                  {                                                //~v77fI~
                	*(pdata+contlen+len)=*(plhn->ULHdata);         //~v45xR~
#ifdef UTF8UCS2                                                    //~va20M~
				 	if (Sswutf8file)//utf8 file ucs2 code is not split by width//~va20I~
	                	*(pdbcs+contlen+len)=*(plhn->ULHdbcs);     //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					else                                           //~va50I~
      				if (Sswebcfile)  //keep original dbcstbl even if it is split to chk dbcs delmstr//~va50I~
	                	*(pdbcs+contlen+len)=*(plhn->ULHdbcs);     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20M~
	            	lastdbcssw=1;	//1byte mode copyed sw         //~v45xI~
                  }                                                //~v77fI~
                }                                                  //~v45xI~
      if (swebcfileconcatdbcs)                                     //~va8wI~
      {                                                            //~va8wI~
        memcpy(pdata+contlen,plh->ULHdata+1,(UINT)len);            //~va8wR~
        memcpy(pdbcs+contlen,plh->ULHdbcs+1,(UINT)len);            //~va8wR~
		if (plhebcconcatold)                                       //~va8wI~
        	plhebcconcatold->ULHflag6|=ULHF6EBCDBCSCONCAT1;    //split/tflow join dropped intermediate si//~va8wI~
        plh->ULHflag6|=ULHF6EBCDBCSCONCAT2;                    //split/tflow join dropped intermediate so//~va8wI~
      }                                                            //~va8wI~
      else                                                         //~va8wI~
      {                                                            //~va8wI~
        memcpy(pdata+contlen,plh->ULHdata,(UINT)len);              //~v45xR~
        memcpy(pdbcs+contlen,plh->ULHdbcs,(UINT)len);              //~v45xR~
      }                                                            //~va8wI~
      	if (len)                                                   //~va8wI~
      		plhebcconcatold=plh;                                   //~va8wI~
      	if (contlen)    //2nd line to be concatinated              //~v74TI~
        	chartabclear(pdbcs+contlen,len);                       //~v74TI~
        len-=lasttabsw;			//net data len                     //~v45xI~
        contlen+=len;                                              //~v45xR~
        rlen=ulhlen-len;	//last line remaining                  //~v45xM~
        rlen-=swebcfileconcatdbcs;                                 //~va8wI~
    	if (UCBITCHK(plh->ULHflag2,ULHF2TABFOUND))                 //~v45xR~
        	tabsw=1;                                               //~v45xI~
      if (!(Sopt2 & SOPT2_SPLCRLF))                                //~v77fM~
      {                                                            //~v77fM~
        if (contlen==Pwidth)                                       //~v45xR~
        	break;                                                 //~v45xI~
        if (splittype!=1)                                          //~v45xR~
        	if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))              //~v45xI~
        		break;                                             //~v45xI~
      }                                                            //~v77fI~
      else                                                         //~v77fI~
      {                                                            //~v77fI~
        if (plh!=plh0)                                             //~v77fI~
            delsw=1;        //do del even if rlen=0(ulhlen=0 follows)//~v77fI~
        if (contlen==Pwidth)                                       //~v77fI~
          if (rlen>0)   //not null line                            //~v77fI~
        	break;                                                 //~v77fI~
        if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))   //last of split line//~v77fI~
        	break;                                                 //~v77fI~
      }                                                            //~v77fI~
//  	plh=UGETQNEXT(plh);                                        //~v74UR~
    }                                                              //~v45xI~
    plh=plh0;                                                      //~v45xM~
    pdata=Pcontwk;                                                 //~v45xI~
    pdbcs=Pcontwk+Pwidth+1;                                        //~v45xR~
    lasttabsw|=lastdbcssw;                                         //~v45xI~
    if (lasttabsw)	//1 byte more read                             //~v45xR~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
      if (!Sswutf8file)                                            //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (!Sswebcfile)  //keep original dbcstbl even if it is split to chk dbcs delmstr//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20I~
		filesetdbcstbl(pdata,pdbcs,contlen+lasttabsw,FSDT_TABSAVE);//~v45xR~
    }                                                              //~va20I~
//  errsw=fcmdsplitlen(Popt,pdata,pdbcs,Ppdelmstr,contlen+lasttabsw,Pwidth,&newlen);//~v750R~
    errsw=fcmdsplitlen(Popt|FCSPL_SETDBCSERR,                      //~v750I~
						pdata,pdbcs,Ppdelmstr,contlen+lasttabsw,Pwidth,&newlen);//~v750I~
	swinsertsosi=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SI for split ebc dbcs string//~va8kI~
//update 1st line                                                  //~v45xM~
	offs=plh->ULHlen;                                              //~v45xI~
  	if (plh->ULHflag6 & ULHF6EBCDBCSCONCAT1)	//dropped intermediate sI//~va8wI~
    	offs--;                                                    //~va8wI~
    addlen=newlen-offs;                                            //~v45xI~
  if (!(Sopt2 & SOPT2_SPLCRLF)	//display width change             //~v77fI~
  ||  !delsw)                                                      //~v77fI~
    if (addlen==0)	//no change                                    //~v45xR~
    {                                                              //~v45xI~
//  	*Ppplh=plhn;                                               //~v74UR~
    	*Ppplh=UGETQNEXT(plh);                                     //~v74UI~
      if (!(Sopt2 & SOPT2_SPLCRLF)) //no update split flag         //~v77fI~
      {                                                            //~v77fI~
        if (splitflag)                                             //~v45xR~
        {                                                          //~v45xI~
//*undoprep CUTOFF,chnage cont flag only                           //~va50I~
            rc=undoupdate(Ppcw,plh,UUHTCUTOFF);//prepare and flag clear//~v45xI~
            if (rc)                                                //~v45xI~
                return rc;                                         //~v45xI~
            UCBITOFF(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);       //~v45xI~
            if (errsw)                                             //~v45xI~
            {                                                      //~v45xI~
                lcmdshifterr(plh,0,0);  //set reverse              //~v45xI~
                (*Pperrctr)++;                                     //~v45xI~
            }                                                      //~v45xI~
            return 1;                                              //~v45xR~
        }                                                          //~v45xI~
      }                                                            //~v77fI~
    	return 0;                                                  //~v45xR~
    }                                                              //~v45xI~
    if (addlen<0)	//to be shorten by delm                        //~v45xI~
    {                                                              //~v45xI~
//*fcmdisrtlinedbcs ,reset dbcstbl                                 //~va50I~
        if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v45xI~
            return UALLOC_FAILED;                                  //~v45xI~
	    UCBITOFF(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);           //~v45xI~
        plh->ULHlen=newlen;		//cut line                         //~v45xI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//    if (Sswebcfile||Sswutf8file)                                 //~va50I~//~va8kR~
      if (Sswebcfile)                                              //~va8kI~
      {                                                            //~va8kI~
        if (swinsertsosi)   //dbcs split                           //~va8kI~
        {                                                          //~va8kI~
            *(plh->ULHdata+plh->ULHlen)=CHAR_SI;    //for cut line //~va8kI~
            *(plh->ULHdbcs+plh->ULHlen)=0;                         //~va8kI~
        	plh->ULHlen++;		//cut line                         //~va8kI~
        }                                                          //~va8kI~
      	optild=0;                                                  //~va8kI~
        if (swinsertsosi)   //dbcs split                           //~va8kI~
        	optild|=FCILDEO_INSERT_SO;                             //~va8kR~
    	rc=fcmdisrtlinedbcsebcsosi(optild,Ppcw,plh,pdata+newlen,pdbcs+newlen,-addlen);//~va8kI~
      }                                                            //~va8kI~
      else                                                         //~va8kI~
      if (Sswutf8file)                                             //~va8kI~
	#else                                                          //~va50I~
      if (Sswutf8file)                                             //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
    	rc=fcmdisrtlinedbcs(Ppcw,plh,pdata+newlen,pdbcs+newlen,-addlen);//~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
        rc=fcmdisrtline(Ppcw,plh,pdata+newlen,-addlen);            //~v45xI~
        if (rc)                                                    //~v45xI~
            return rc;                                             //~v45xI~
        plh=UGETQNEXT(plh);	//inserted                             //~v45xI~
        if (splitflag & ULHF2SPLIT1)	//top line has follower    //~v45xI~
	    	UCBITON(plh->ULHflag2,ULHF2SPLIT1);                    //~v45xI~
    	*Ppplh=plh;                                                //~v45xI~
    	return 1;                                                  //~v45xI~
    }                                                              //~v45xI~
//  if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)      //expand buff//~v45xR~//~va8kR~
    if (fileexpandbuff(plh,newlen+1)==UALLOC_FAILED)      //+1 for append SI//~va8kI~
        return 4;                                                  //~v45xR~
//*ebc_setdbcstbl later                                            //~va50I~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v45xR~
        return UALLOC_FAILED;                                      //~v45xR~
    if (errsw)                                                     //~v45xI~
    {                                                              //~v45xI~
        lcmdshifterr(plh,0,0);  //set reverse                      //~v45xI~
        (*Pperrctr)++;                                             //~v45xI~
    }                                                              //~v45xI~
    plh->ULHlen=newlen;                                            //~v45xR~
    memcpy(plh->ULHdata+offs,pdata+offs,(UINT)addlen);             //~v45xR~
    memcpy(plh->ULHdbcs+offs,pdbcs+offs,(UINT)addlen);             //~v45xR~
    if (Sswebcfile  && swinsertsosi)   //dbcs split                //~va8kI~
    {                                                              //~va8kI~
	    plh->ULHlen++;                                             //~va8kI~
	    *(plh->ULHdata+offs+addlen)=CHAR_SI;                       //~va8kR~
    	*(plh->ULHdbcs+offs+addlen)=0;                             //~va8kI~
    }                                                              //~va8kI~
  if (!(Sopt2 & SOPT2_SPLCRLF))                                    //~v77fI~
    UCBITOFF(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2));             //~v45xI~
    len=addlen;   //for next line filetabexp                       //~v50FI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (Sswebcfile)                                                  //~va50I~
	xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);               //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (tabsw)                                                     //~v45xR~
        if (filetabexp(1,plh,offs,&len)==UALLOC_FAILED)  //tab re-expand(len update)//~v45xR~
            return UALLOC_FAILED;                                  //~v45xR~
//delete joind line                                                //~v45xI~
//  for (plh=UGETQNEXT(plh0),rlen=addlen;rlen;plh=plhn)            //~v77fR~
    for (plh=UGETQNEXT(plh0),rlen=addlen;plh;plh=plhn)             //~v77fI~
    {                                                              //~v45xR~
        plhn=UGETQNEXT(plh);                                       //~v45xR~
        if (plh->ULHtype!=ULHTDATA)                                //~v45xR~
            continue;                                              //~v45xR~
        ulhlen=plh->ULHlen;                                        //~v45xI~
	    droppedsosilen=0;                                          //~va8wI~
        if (plh->ULHflag6 & ULHF6EBCDBCSCONCAT1)	//dropped intermediate so/si//~va8wI~
	    	droppedsosilen++;                                      //~va8wI~
        if (plh->ULHflag6 & ULHF6EBCDBCSCONCAT2)	//dropped intermediate so/si//~va8wI~
	    	droppedsosilen++;                                      //~va8wI~
        ulhlen-=droppedsosilen;                                    //~va8wI~
	  	if ((Sopt2 & SOPT2_SPLCRLF))	//display width change     //~v77fI~
        {                                                          //~v77fI~
        	if (!rlen)                                             //~v77fI~
            	if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//next is new line start//~v77fI~
                	break;                                         //~v77fI~
        }                                                          //~v77fI~
        else                                                       //~v77fI~
        {                                                          //~v77fI~
        	if (!rlen)                                             //~v77fI~
            	break;                                             //~v77fI~
        }                                                          //~v77fI~
	  if (!(Sopt2 & SOPT2_SPLCRLF))	//display width change         //~v77fI~
        if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//no followed  //~v45xI~
        	(*Ppdonectr)++;                                        //~v45xR~
        if (rlen<ulhlen)	//partialy used                        //~v45xI~
        	break;			//not used data plh                    //~v45xI~
        if (rc=lcmddel(Ppcw,plh,plh,1,0,1),rc)//1 line,no csr set,not from lcmd main//~v45xI~
            return rc;                                             //~v45xI~
        rlen-=ulhlen;                                              //~v45xR~
    }                                                              //~v45xR~
//update last plh having not joind remaining data                  //~v45xM~
    if (!rlen)	//last is fully concatinated                       //~v45xR~
    {                                                              //~v45xI~
	  if ((Sopt2 & SOPT2_SPLCRLF))	//display width change         //~v77fI~
    	*Ppplh=plh;      //break by nex topline                    //~v77fI~
      else                                                         //~v77fI~
      {                                                            //~va8wI~
       if (!ulhlen)                                                //~va8wI~
    	*Ppplh=plh;      //null line is next top of join           //~va8wI~
       else                                                        //~va8wI~
    	*Ppplh=plhn;                                               //~v45xI~
      }                                                            //~va8wI~
    	return 1;                                                  //~v45xR~
    }                                                              //~v45xI~
//*ebc_setdbcstbl later                                            //~va50I~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v45xR~
        return UALLOC_FAILED;                                      //~v45xR~
    len=ulhlen-rlen;                                               //~v45xR~
    plh->ULHlen=len;                                               //~v45xR~
  if (plh->ULHflag6 & ULHF6EBCDBCSCONCAT2)	//dropped intermediate so//~va8wI~
  {                                                                //~va8wI~
    memcpy(plh->ULHdata,plh->ULHdata+rlen+1,(UINT)len);            //~va8wI~
    memcpy(plh->ULHdbcs,plh->ULHdbcs+rlen+1,(UINT)len);            //~va8wI~
  }                                                                //~va8wI~
  else                                                             //~va8wI~
  {                                                                //~va8wI~
    memcpy(plh->ULHdata,plh->ULHdata+rlen,(UINT)len);              //~v45xR~
    memcpy(plh->ULHdbcs,plh->ULHdbcs+rlen,(UINT)len);              //~v45xR~
  }                                                                //~va8wI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (Sswebcfile)                                                  //~va50I~
  {                                                                //~va50I~
  	if (swinsertsosi)   //dbcs split                               //~va8kI~
  	{                                                              //~va8kI~
    	memmove(plh->ULHdata+1,plh->ULHdata,(UINT)len);            //~va8kI~
    	memmove(plh->ULHdbcs+1,plh->ULHdbcs,(UINT)len);            //~va8kI~
    	*(plh->ULHdata)=CHAR_SO;                                   //~va8kI~
    	*(plh->ULHdbcs)=0;                                         //~va8kI~
		plh->ULHlen++;                                             //~va8kI~
    }                                                              //~va8kI~
	xeebc_setdbcstblplh(0,0/*pfh*/,plh,0/*ULHlen*/);               //~va50R~
  }                                                                //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  {                                                                //~va50I~
    btabclear(plh->ULHdata,plh->ULHdbcs,len,0,1);   //clear top of line tab//~v45xR~,//~v69BI~
    setsplitdbcserr(0,plh->ULHdbcs,len,0);  //chk top byte         //~v750I~
    if (tabsw)                                                     //~v45xR~
//      if (filetabexp(1,plh,offs,&rlen)==UALLOC_FAILED)  //tab re-expand(len update)//~v50FR~
        if (filetabexp(1,plh,0,&len)==UALLOC_FAILED)  //tab re-expand(len update)//~v50FI~
            return UALLOC_FAILED;                                  //~v45xR~
  }                                                                //~va50I~
    *Ppplh=plh;                                                    //~v45xR~
    return 1;                                                      //~v45xR~
}//filesplitjoin                                                   //~v45xR~
//**************************************************************** //~v74ZI~
// fcmdtflowjoin                                                   //~v74ZI~
// rc:PSTOP,UALLOC_FAILED,1:joined                                 //~v758I~
//**************************************************************** //~v74ZI~
int fcmdtflowjoin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v74ZI~
					UCHAR *Ppdelmstr,UCHAR *Pcontwk,int Popt,      //~v74ZI~
					int *Ppdonectr,int *Pperrctr)                  //~v74ZI~
{                                                                  //~v74ZI~
    PULINEH plh,plh0,plhn;                                         //~v74ZI~
    int   rlen,newlen,len,/*ulhlen,offs,*/contlen/*,addlen*/;          //~v75eR~
    UCHAR *pdata,*pdbcs;                                           //~v74ZI~
    int   rc=0,errsw;                                              //~v74ZR~
    int indentoffs=0,joinedlen=0,rc2=0/*,contleno*/;                   //~v75BR~
    int joinopt=FCSPL_TFJOIN1ST;                                   //~v75uI~
    PULINEH joinedplh=0,plhnext=0;                                 //~v75eR~
    int swinsertsosi,optild;                                       //~va8kI~
//*********************************                                //~v74ZI~
    plh0=plh=*Ppplh;                                               //~v74ZI~
    plhn=UGETQNEXT(plh);                                           //~v74ZI~
    pdata=Pcontwk;                                                 //~v74ZI~
    pdbcs=Pcontwk+Pwidth+1;                                        //~v74ZI~
//  ulhlen=plh->ULHlen;                                            //~v74ZI~
//gather data upto width                                           //~v74ZI~
	swinsertsosi=0;                                                //~va8kI~
    for (contlen=0,rlen=0;plh && plh!=Pplh2;plh=plhn)              //~v74ZR~
    {                                                              //~v74ZI~
		swinsertsosi=0;                                            //~va8kI~
		plhn=UGETQNEXT(plh);                                       //~v74ZI~
        if (plh->ULHtype!=ULHTDATA)                                //~v74ZI~
        	continue;                                              //~v74ZI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v74ZI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v74ZI~
                return rc;                                         //~v74ZI~
	    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v74ZI~
    		if (rc=lcmdincm(Ppcw,plh),rc)                          //~v74ZI~
        		return rc;                                         //~v74ZI~
//      contleno=contlen;                                          //~v758I~
		if (Popt & FCSPL_SPACE1)	//bnds is set                  //~v75cI~
            if (rc2=fcmdsplitspace1(Popt,Ppcw,plh,0),rc2)   //reduce space//~v75cI~
            	return rc2;                                        //~v75cI~
     	rc2=fcmdtflowjoinsub(Popt|joinopt,Ppdelmstr,plh,Pplh2,&indentoffs,Pwidth,pdata,pdbcs,&contlen,&len);//~v75eM~
		swinsertsosi=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SI for split ebc dbcs string//~va8kI~
		if (swinsertsosi)    //append SI for split ebc dbcs string //~va8kI~
        {                                                          //~va8kI~
			if (!(Sotheropt & SOTHO_APPENDSODONE))                 //~va8kI~
            {                                                      //~va8kI~
                *(pdata+contlen)=CHAR_SI;                          //~va8kR~
                *(pdbcs+contlen)=0;                                //~va8kR~
                contlen++;                                         //~va8kR~
            }                                                      //~va8kI~
        }                                                          //~va8kI~
        if (rc2>1 && rc2!=3)	//new paragraph                    //~v75eI~
			break;                                                 //~v75eI~
        joinedlen=len;                                             //~v75eM~
        joinedplh=plh;                                             //~v75eI~
        if (rc2==3)	//next joined line splittted                   //~v75eI~
			break;                                                 //~v75eI~
	    joinopt=0;           //drop JOIN1ST                        //~v75nI~
        if (contlen==Pwidth)                                       //~v74ZI~
        	break;                                                 //~v74ZI~
    }                                                              //~v74ZI~
//* insert splitted data                                           //~v75eI~
    if (rc2==3)	//join stop at splitted this line                  //~v75eR~
    {                                                              //~v75eI~
    	plh=joinedplh;                                             //~v75eI~
	    if (joinedlen<plh->ULHlen)                                 //~v75eI~
        {                                                          //~v75eI~
            rlen=plh->ULHlen-joinedlen;                            //~v75eI~
          if (Sswebcfile)                                          //~va8kI~
          {                                                        //~va8kI~
      		optild=0;                                              //~va8kI~
        	if (swinsertsosi)   //dbcs split                       //~va8kI~
        		optild|=FCILDEO_INSERT_SO;    //insert so at TOL   //~va8kI~
    		rc=fcmdisrtlinedbcsebcsosi(optild,Ppcw,plh,plh->ULHdata+joinedlen,plh->ULHdbcs+joinedlen,rlen);//~va8kR~
      	  }                                                        //~va8kI~
          else                                                     //~va8kI~
          {                                                        //~va8kI~
            chartabclear(plh->ULHdbcs+joinedlen,rlen);             //~v75eI~
            rc=fcmdisrtlinedbcs(Ppcw,plh,plh->ULHdata+joinedlen,plh->ULHdbcs+joinedlen,rlen);//~v75eI~
          }                                                        //~va8kI~
            if (rc)                                                //~v75eI~
                return rc;                                         //~v75eI~
            plhnext=UGETQNEXT(plh); //inserted                     //~v75eI~
        }                                                          //~v75eI~
        else		//paragraph change                             //~v75eI~
        	plhnext=plhn;                                          //~v75eR~
    }                                                              //~v75eI~
    else  	//fully included                                       //~v75eR~
    if (rc2>1)	//paragraph changed                                //~v75eI~
        plhnext=plh;                                               //~v75eI~
    else                                                           //~v75eI~
    if (!plh||plh==Pplh2)		//reached to EOF                   //~v75eI~
        plhnext=plh;                                               //~v75eI~
    else                        //width filled                     //~v75eI~
	    plhnext=plhn;                                              //~v75eR~
//                                                                 //~v75eI~
    plh=plh0;                                                      //~v74ZI~
//  errsw=fcmdsplitlen(Popt,pdata,pdbcs,Ppdelmstr,contlen,Pwidth,&newlen);//~v75eR~
    errsw=0;                                                       //~v75eI~
    newlen=contlen;                                                //~v75eI~
//update 1st line                                                  //~v74ZI~
//  offs=plh->ULHlen;                                              //~v74ZI~
    if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)      //expand buff//~v74ZI~
        return UALLOC_FAILED; /*4;*/                               //~v758R~
//*ebc_setdbcstbl later                                            //~va50I~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v74ZI~
        return UALLOC_FAILED;                                      //~v74ZI~
    if (errsw)                                                     //~v74ZI~
    {                                                              //~v74ZI~
        lcmdshifterr(plh,0,0);  //set reverse                      //~v74ZI~
        (*Pperrctr)++;                                             //~v74ZI~
    }                                                              //~v74ZI~
    plh->ULHlen=newlen;                                            //~v74ZI~
    memcpy(plh->ULHdata,pdata,(UINT)contlen);//from top(may be shifted)//~v74ZI~
    memcpy(plh->ULHdbcs,pdbcs,(UINT)contlen);                      //~v74ZI~
    if (fcmdplhpadspace(Popt,Ppcw,plh,Pwidth)==UALLOC_FAILED)  //for the case topline splitted delm or EOF//~v75eR~
        return UALLOC_FAILED;                                      //~v75eR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	XEEBC_setdbcstblplh(Sswebcfile,0/*pfh*/,plh);	//evaluate dbcstbl after join line//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//delete joind line                                                //~v74ZI~
    for (plhn=plh=UGETQNEXT(plh0);plh!=plhnext;plh=plhn)           //~v75eR~
    {                                                              //~v74ZI~
        plhn=UGETQNEXT(plh);                                       //~v74ZI~
        if (plh->ULHtype!=ULHTDATA)                                //~v74ZI~
            continue;                                              //~v74ZI~
//      ulhlen=plh->ULHlen;                                        //~v74ZI~
        if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//no followed  //~v74ZI~
        	(*Ppdonectr)++;                                        //~v74ZI~
        if (rc=lcmddel(Ppcw,plh,plh,1,0,1),rc)//1 line,no csr set,not from lcmd main//~v74ZI~
            return rc;                                             //~v74ZI~
    }                                                              //~v74ZI~
//update last plh having not joind remaining data                  //~v74ZI~
	plh=plhnext;                                                   //~v75eI~
    *Ppplh=plh;                                                    //~v74ZI~
    return 1;                                                      //~v74ZI~
}//fcmdtflowjoin                                                   //~v74ZI~//~va8vR~
//**************************************************************** //~v74ZM~
// fcmdtflowjoinsub                                                //~va8kR~
// get data from next plh to concat to tail                        //~v74ZM~
//*rc   :1:topline shifted,                                        //~v75eR~
//*     :3:stop concat by delm/space split or 1st line has no delm //~v75eI~
//*     :4:stop concat by no delm                                  //~v75eR~
//*     :32(PSTOP) 33(PNEW)                                        //~v75eI~
//*     :UALLOC_FAILED                                             //~v758I~
//**************************************************************** //~v74ZM~
int fcmdtflowjoinsub(int Popt,UCHAR *Ppdelmstr,PULINEH Pplh,PULINEH Pplh2,int *Ppindentoffs,int Pwidth,UCHAR *Pcontdata,UCHAR *Pcontdbcs,int *Ppcontlen,//~v75eR~
							int *Ppcopyedlen)                      //~v74ZM~
{                                                                  //~v74ZM~
	int rc=0,rc2,ulhlen,copyedlen=0,headcnt,tailcnt,rlen,contlen,netlen,splitlen;//~v74ZR~
    int linefilledsw,indentoffs/*newlen,width*/;                   //~v75eR~
    int opt;                                                       //~v75uI~
    UCHAR *pdbcs,*pdata,*pcontdata,*pcontdbcs;                     //~v74ZM~
    int shiftcnt;                                                  //~va8kI~
//*****************************                                    //~v74ZM~
	Sotheropt&=~(SOTHO_APPENDSO|SOTHO_APPENDSODONE);               //~va8kR~
    *Ppcopyedlen=0;                                                //~v758I~
    contlen=*Ppcontlen;                                            //~v74ZM~
    ulhlen=Pplh->ULHlen;                                           //~v74ZM~
    pdata=Pplh->ULHdata;                                           //~v74ZM~
    pdbcs=Pplh->ULHdbcs;                                           //~v74ZM~
	if (Popt & FCSPL_TFJOIN1ST)	//top of join                      //~v75eI~
    {                                                              //~v74ZI~
		rc2=fcmdtflowindentshift(Popt,Pplh,Pwidth,Pcontdata,Pcontdbcs,&contlen);//rc=1:shfted//~v74ZR~
        if (rc2)                                                   //~v758I~
        {                                                          //~v758I~
        	if (rc2==1)	//shifted                                  //~v758R~
        		rc=1;                                              //~v758R~
        	else                                                   //~v758R~
	        	return rc2;	//PSTOP/UALLOC_FAILED                  //~v758R~
        }                                                          //~v758I~
        shiftcnt=contlen-ulhlen;  //right shift count by indentation//~va8nR~
    	copyedlen=Pplh->ULHlen;	//may changed by shift             //~v758R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
      if (shiftcnt>0)   //space inserted at top by indentation     //~va8nI~
        tailcnt=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,Pcontdata+shiftcnt,Pcontdbcs+shiftcnt,contlen-shiftcnt);//~va8nR~
      else                                                         //~va8nI~
        tailcnt=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,Pcontdata,Pcontdbcs,contlen);//~va50I~
    #else                                                          //~va50I~
        tailcnt=(int)UTF_umemrspnc(Sswutf8file,Pcontdata,Pcontdbcs,' ',contlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        tailcnt=(int)umemrspnc(Pcontdata,' ',(UINT)contlen);                  //~v75eI~
#endif                                                             //~va20I~
        if (tailcnt>1)                                             //~v75eI~
        	contlen-=tailcnt-1; //shrink tail to concat next line  //~v75eI~
      if (shiftcnt>0)   //space inserted at top by indentation     //~va8nI~
      {                                                            //~va8nI~
        rc2=fcmdtflowsplitlen(Popt|FCSPL_TFTOPLINE,Pcontdata+shiftcnt,Pcontdbcs+shiftcnt,Ppdelmstr,contlen-shiftcnt,Pwidth,&splitlen,&linefilledsw);//~va8nR~
        splitlen+=shiftcnt;                                        //~va8nI~
      }                                                            //~va8nI~
      else                                                         //~va8nI~
        rc2=fcmdtflowsplitlen(Popt|FCSPL_TFTOPLINE,Pcontdata,Pcontdbcs,Ppdelmstr,contlen,Pwidth,&splitlen,&linefilledsw);
        if (rc2==1 || linefilledsw)    //not splitted or splited at word boundary//~v75eR~
        	rc=3;		//stop concat                              //~v75eR~
        if (linefilledsw)    //WORDKEPT/DELMFOUND                  //~v75eI~
        {                                                          //~va8kI~
            contlen=copyedlen=splitlen;                            //~v75eR~
          	copyedlen-=shiftcnt;                               //~va8kR~//~va8nR~
        }                                                          //~va8kI~
                                                                   //~va8kI~
    }                                                              //~v74ZI~
    else                                                           //~v74ZI~
    {                                                              //~v74ZI~
#ifdef UTF8UCS2                                                    //~va20I~
		rc2=fcmdtflowgetindent(Popt,Pplh,pdata,pdbcs,ulhlen,0);    //~va20I~
#else                                                              //~va20I~
		rc2=fcmdtflowgetindent(Popt,Pplh,pdata,ulhlen,0);          //~v751R~
#endif                                                             //~va20I~
      if (rc2==FCSPLRC_PSTOP||rc2==FCSPLRC_PNEW) //paragraph changed//~v758R~
      {                                                            //~v758R~
        copyedlen=0;                                               //~v758I~
        pcontdata=Pcontdata+contlen;                               //~v758I~
        pcontdbcs=Pcontdbcs+contlen;                               //~v758I~
        rlen=Pwidth-contlen;        //remaining space to be cleared//~v758I~
        rc=rc2;                                                    //~v758I~
      }                                                            //~v758R~
      else                                                         //~v758I~
      {                                                            //~v758I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      tailcnt=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,Pcontdata,Pcontdbcs,(UINT)contlen);//~va50I~//~vb2DR~
        tailcnt=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,Pcontdata,Pcontdbcs,contlen);//~vb2DI~
    #else                                                          //~va50I~
        tailcnt=(int)UTF_umemrspnc(Sswutf8file,Pcontdata,Pcontdbcs,' ',(UINT)contlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        tailcnt=(int)umemrspnc(Pcontdata,' ',(UINT)contlen);                  //~v74ZR~
#endif                                                             //~va20I~
        indentoffs=Sindentoffs;                                    //~v75eI~
       if (tailcnt==contlen && contlen<indentoffs)  //indentation by 2nd line//~v75eI~
       {                                                           //~v75eI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
       	memset(Pcontdata,Schspace,(UINT)indentoffs);               //~va50I~
    #else                                                          //~va50I~
       	memset(Pcontdata,' ',(UINT)indentoffs);                          //~v75eI~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
       	memset(Pcontdbcs,0,(UINT)indentoffs);                            //~v75eI~
        contlen=indentoffs;                                        //~v75eI~
       }                                                           //~v75eI~
       else                                                        //~v75eI~
       {                                                           //~v75eI~
        if (tailcnt>1)                                             //~v74ZI~
        	contlen-=tailcnt-1; //shrink tail of prev line         //~v74ZI~
       }                                                           //~v75eI~
        pcontdata=Pcontdata+contlen;                               //~v74ZI~
        pcontdbcs=Pcontdbcs+contlen;                               //~v74ZI~
        rlen=Pwidth-contlen;        //remaining space              //~v74ZM~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,ulhlen);//~va50I~
    #else                                                          //~va50I~
        headcnt=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',ulhlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        headcnt=(int)umemspnc(pdata,' ',(UINT)ulhlen);                        //~v74ZR~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        tailcnt=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,ulhlen);//~va50I~
    #else                                                          //~va50I~
        tailcnt=(int)UTF_umemrspnc(Sswutf8file,pdata,pdbcs,' ',ulhlen);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        tailcnt=(int)umemrspnc(pdata,' ',(UINT)ulhlen);                       //~v74ZR~
#endif                                                             //~va20I~
        netlen=ulhlen-headcnt-tailcnt;                             //~v74ZR~
        if (netlen<0) //all space                                  //~v74ZR~
            netlen=0;                                              //~v74ZR~
        copyedlen=0;                                               //~v74ZI~
        for (;;)                                                   //~v74ZR~
        {                                                          //~v74ZR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	if (!contlen||UCVEBCUTF_nespace(Sswebcfile,Sswutf8file,*(pcontdata-1),*(pcontdbcs-1)))	//no inter line space//~va50I~
    #else                                                          //~va50I~
        	if (!contlen||UTF_nespace(Sswutf8file,*(pcontdata-1),*(pcontdbcs-1)))	//no inter line space//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	if (!contlen||*(pcontdata-1)!=' ')	//no inter line space//~v75eR~
#endif                                                             //~va20I~
            {                                                      //~v74ZI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//          	*pcontdata++=Schspace;                             //~va50I~//~vb2CR~
            	*pcontdata++=(UCHAR)Schspace;                      //~vb2CI~
#else                                                              //~va50I~
            	*pcontdata++=' ';                                  //~v74ZI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                *pcontdbcs++=0;                                    //~v74ZI~
                contlen++;                                         //~v74ZI~
                rlen--;                                            //~v74ZI~
                if (!rlen)                                         //~v74ZI~
                {                                                  //~v76NI~
                    rc=4;   //no space,stop concat                 //~v76NI~
                	break;                                         //~v74ZI~
                }                                                  //~v76NI~
            }                                                      //~v74ZI~
            if (!netlen)                                           //~v74ZI~
            {                                                      //~v74ZI~
            	copyedlen=ulhlen;                                  //~v74ZI~
            	break;	//all space                                //~v74ZI~
            }                                                      //~v74ZI~
            pdata+=headcnt;                                        //~v74ZR~
            pdbcs+=headcnt;                                        //~v74ZR~
			if (contlen==indentoffs)                               //~v75uI~
            	opt=FCSPL_TFTOPLINE;	//ignore indentation space as delm//~v75uI~
            else                                                   //~v75uI~
            	opt=FCSPL_TFJOIN;		                           //~v75uI~
        	rc2=fcmdtflowsplitlen(Popt|opt,pdata,pdbcs,Ppdelmstr,netlen,rlen,&splitlen,&linefilledsw);//~v75uI~
        	if (rc2==1)    //not splitted or splited at word boundary//~v75eR~
            {                                                      //~v75eI~
        		rc=4;		//stop concat this line                //~v75eR~
            	copyedlen=0;                                       //~v75eM~
                break;                                             //~v75eM~
            }                                                      //~v75eI~
        	if (linefilledsw)    //not splitted or splited at word boundary//~v75eI~
        		rc=3;		//stop concat next line                //~v75eI~
            if (!linefilledsw && netlen<rlen)	//short rec,fully concatinated//~v75eR~
            	copyedlen=ulhlen;                                  //~v75eI~
            else                                                   //~v75eI~
	            copyedlen=headcnt+splitlen;                        //~v75eR~
            memcpy(pcontdata,pdata,(UINT)splitlen);                //~v74ZR~
            memcpy(pcontdbcs,pdbcs,(UINT)splitlen);                //~v74ZR~
            pcontdata+=splitlen;                                   //~v74ZR~
            pcontdbcs+=splitlen;                                   //~v74ZR~
            contlen+=splitlen;                                     //~v74ZR~
            rlen-=splitlen;                                        //~v74ZM~
	        break;                                                 //~v74ZI~
        }                                                          //~v74ZI~
     } //same paragraph                                            //~v75eR~
        if (rc) //nos space to cancat                              //~v74ZI~
        {                                                          //~v74ZI~
            if (rlen)                                              //~v74ZI~
            {                                                      //~v74ZI~
				if (Sotheropt & SOTHO_APPENDSO)    //append SI for split ebc dbcs string//~va8kI~
                {                                                  //~va8kI~
                    *pcontdata++=CHAR_SI;                          //~va8kI~
                    *pcontdbcs++=0;                                //~va8kI~
                    rlen--;                                        //~va8kI~
                    contlen++;                                     //~va8kI~
					Sotheropt|=SOTHO_APPENDSODONE;                 //~va8kI~
                }                                                  //~va8kI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                memset(pcontdata,Schspace,(UINT)rlen);             //~va50I~
#else                                                              //~va50I~
                memset(pcontdata,' ',(UINT)rlen);                        //~v74ZI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                memset(pcontdbcs,0  ,(UINT)rlen);                        //~v74ZI~
                contlen+=rlen;                                     //~v74ZR~
            }                                                      //~v74ZI~
        }                                                          //~v74ZI~
    }//top or 2nd line                                             //~v75eM~
    *Ppcontlen=contlen;                                            //~v74ZM~
    *Ppcopyedlen=copyedlen;                                        //~v74ZM~
    return rc;                                                     //~v74ZM~
}//fcmdtflowjoinsub                                                //~v74ZR~
//**************************************************************** //~v45xI~
// fcmdsplitlen                                                    //~v45xI~
//*get splt length considering tab/dbcs                            //~v45xI~
//*parm1 :cmd option                                               //~v45xI~
//*parm2 :pada                                                     //~v45xR~
//*parm3 :pdbcs                                                    //~v45xR~
//*parm4 :delmstr                                                  //~v45xR~
//*parm5 :datalen                                                  //~v45xR~
//*parm6 :width                                                    //~v45xR~
//*parm7 :&len                                                     //~v45xR~
//*return:rc: 0:split by delm,1:no delm,2:dbcs split by SBCS option//~v750R~
//*           4:dbcs could not be split,len was not changed        //~va8kI~
//**************************************************************** //~v45xI~
int fcmdsplitlen(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v45xR~
					int Pdatalen,int Pwidth,int *Ppsplitlen)       //~v45xR~
{                                                                  //~v45xI~
//  int rc=0,newlen;                                               //~v45xR~//~vaf9R~
    int rc=0,newlen=0;                                             //~vaf9I~
    UCHAR *pc;                                                     //~v45xI~
    int srchlen;                                                   //~v50AI~
    int delmstrlen;                                                //~v50BI~
    int spacelen;                                                  //~v74XI~
    int /*delmchksw,*/minwidth;                                    //~v75eR~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
    int splitctrl,splitctrr,opt=UCVEBC3O_CMPSO;                    //~va50R~
#endif                                                             //~vva1cR~//~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int srchlen2;                                                  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int rc2,optebsl;                                               //~va8kR~
    UCHAR *pctol;                                                  //~va8qI~
    int newleno;                                                   //~v@@@I~
//**************************                                       //~v45xI~
	Sotheropt&=~(SOTHO_APPENDSO|    //append SO for split ebc dbcs string//~va8kI~//~va8qR~
                  SOTHO_DELSI|    //delm matched on tol            //~v@@@I~
                  SOTHO_DELMONTOL);    //delm matched on tol       //~va8qR~
    minwidth=min(Pwidth,Pdatalen);	//len for the case delmchksw on//~v751R~
//  if (Pdatalen>Pwidth)                                           //~v751R~
//  if (Pdatalen>Pwidth)                                           //~v76KR~
    if (Pdatalen>Pwidth||Ppdelmstr)                                //~v76KR~
    {                                                              //~v45xI~
        if (Ppdelmstr)                                             //~v45xR~
        {                                                          //~v45xR~
	  		if (Popt & FCSPL_STRDELM) //string delemeter               //~v50BI~
        	{                                                          //~v50BI~
          		rc=1;	//not found id                                 //~v50BI~
//          	delmstrlen=(int)strlen(Ppdelmstr);                     //~va5gR~
            	delmstrlen=Sdelmstrlen;                                //~va5gI~
	  	 		if (Popt & FCSPL_TOL) //set delm to top of line        //~v50BI~
         		{                                                      //~v50BI~
	  	  			if (Popt & FCSPL_ALLWIDTH0)                        //~v50BI~
          			{                                                  //~v50BI~
	  	  		  		if (Popt & FCSPL_SPLITBNDS)	//search all delm  //~v76LI~
                    		newlen=minwidth;	//limit by margin/bnds     //~v76LI~
                  		else                                             //~v76LI~
            				newlen=Pdatalen;	//for the case delm not found//~v50BI~
#ifdef UTF8UCS2                                                    //~va20I~
//          			pc=UTF_umemmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,0/*delmstrdbcs*/,newlen,delmstrlen);//search from top//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            			pc=UCVEBCUTF_umemmem_opt(Sswebcfile,Sswutf8file,opt,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//search from top//~va50R~
    #else                                                          //~va50I~
            			pc=UTF_umemmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//search from top//~va5gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            			pc=umemmem(Ppdata,Ppdelmstr,(UINT)newlen,(UINT)delmstrlen);//search from top//~v50BI~
#endif                                                             //~va20I~
						pctol=pc;                                      //~va8qI~
                		if (pc)                                        //~v50BI~
                		{                                              //~v50BI~
            				srchlen=newlen-delmstrlen;                 //~v50BI~
                        	if (Sswebcfile)                            //~va8kI~
                        	{                                          //~va8kI~
                            	if (pc==Ppdata+1                       //~va8kI~//~va8qR~
                            	&&  *Ppdata==CHAR_SO                   //~va8kR~
                            	&&  *(Ppdbcs+1)==UDBCSCHK_DBCS1ST      //~va8kR~
                            	)	//dbcs match as SO+xx              //~va8kI~
                            		pc=Ppdata;	//serch not top        //~va8kR~
                        	}                                          //~va8kI~
                      		if (!(Sotheropt & SOTHO_JOIN))               //~va8kR~
                      		{                                            //~va8kI~
                    			if (pc==Ppdata	//match at top of line     //~v50BI~
            					&&  srchlen>0)                             //~v50BR~
#ifdef UTF8UCS2                                                    //~va20I~
//          						pc=UTF_umemmem(Sswutf8file,Ppdata+delmstrlen,Ppdbcs+delmstrlen,Ppdelmstr,0/*delmstrdbcs*/,srchlen,delmstrlen);//delm not found//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            						pc=UCVEBCUTF_umemmem_opt(Sswebcfile,Sswutf8file,opt,Ppdata+delmstrlen,Ppdbcs+delmstrlen,Ppdelmstr,Spdelmdbcs,srchlen,delmstrlen);//delm not found//~va50R~
    #else                                                          //~va50I~
            						pc=UTF_umemmem(Sswutf8file,Ppdata+delmstrlen,Ppdbcs+delmstrlen,Ppdelmstr,Spdelmdbcs,srchlen,delmstrlen);//delm not found//~va5gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            						pc=umemmem(Ppdata+delmstrlen,Ppdelmstr,(UINT)srchlen,(UINT)delmstrlen);//delm not found//~v50BR~
#endif                                                             //~va20I~
                      		}                                            //~va8kI~
                    	}                                              //~v50BI~
                		if (pc)                                        //~v50BR~
//              			if (pc!=Ppdata)                                //~v51cI~//~va8kR~
                			if (pc!=Ppdata                                 //~va8kI~
                    		||  (Sotheropt & SOTHO_JOIN)                   //~va8kR~
                    		)                                              //~va8kI~
                			{                                              //~v50BR~
//                    			newlen=(int)((ULONG)pc-(ULONG)Ppdata);     //~v50BR~//~vafkR~
                    			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata);//~vafkI~
                    			rc=0;                                      //~v50BR~
                			}                                              //~v50BR~
          			}                                                  //~v50BI~
          			else//TOL not width0                               //~v50BR~
          			{                                                  //~v50BI~
//            			newlen=Pwidth;                                 //~v751R~
              			newlen=minwidth;                               //~v751I~
//                  	srchlen=newlen+delmstrlen;                     //~v50BI~//~v@@@R~
                    	srchlen=newlen;    //no match at out of line//~v@@@R~
                    	srchlen=min(srchlen,Pdatalen);                 //~v50BI~
#ifdef UTF8UCS2                                                    //~va20I~
//                  	pc=UTF_umemrmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,0/*delmstrdbcs*/,srchlen,delmstrlen);//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    	pc=UCVEBCUTF_umemrmem_opt(Sswebcfile,Sswutf8file,opt,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,srchlen,delmstrlen);//~va50R~
    #else                                                          //~va50I~
                    	pc=UTF_umemrmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,srchlen,delmstrlen);//~va5gI~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    	pc=umemrmem(Ppdata,Ppdelmstr,(UINT)srchlen,(UINT)delmstrlen);//~v50BR~
#endif                                                             //~va20I~
                    	if (Sswebcfile)                                //~va8qI~
                    	{                                              //~va8qI~
                        	if (pc==Ppdata+1                           //~va8qI~
                        	&&  *Ppdata==CHAR_SO                       //~va8qI~
                        	&&  *(Ppdbcs+1)==UDBCSCHK_DBCS1ST          //~va8qI~
                        	)   //dbcs match as SO+xx                  //~va8qI~
                            	pc=Ppdata;  //serch not top            //~va8qI~
                    	}                                              //~va8qI~
                    	pctol=pc;                                      //~va8qI~
//          			if (pc && pc!=Ppdata)	//not top of line      //~v50BR~//~va8kR~
            			if (pc)                                        //~va8kI~
                    	if ((pc!=Ppdata)||(Sotheropt & SOTHO_JOIN)     //~va8kR~
                    	)                                              //~va8kI~
                    	{                                              //~v50BI~
//                			newlen=(int)((ULONG)pc-(ULONG)Ppdata);     //~v50BR~//~vafkR~
                			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata); //~vafkI~
                    		rc=0;                                      //~v50BR~
            			}                                              //~v50BI~
//                    	if (pc==Ppdata) //match at top of line       //~va8qR~
//                        	Sotheropt|=SOTHO_DELMONTOL;    //delm matched on tol//~va8qR~
          			}//not WIDTH0                                      //~v50BI~
                	if (rc && pctol==Ppdata)                           //~va8qI~
                	{                                                  //~va8qI~
						Sotheropt|=SOTHO_DELMONTOL;    //delm matched on tol//~va8qI~
		  		      if (!(Sotheropt & SOTHO_TOPLINETOL))         //~va8uR~
                      {                                            //~va8uI~
		  		       if (Sotheropt & SOTHO_JOIN)                 //~va8uI~
                       	rc=2,newlen=0;                             //~va8uI~
                       else                                        //~va8uI~
                		rc=0;                                          //~va8qI~
                      }                                            //~va8uI~
                	}                                                  //~va8qI~
         		}                                                      //~v50BI~
         		else   //strdelm & not TOL                             //~v50BR~
         		{                                                      //~v50BI~
	  	  			if (Popt & FCSPL_ALLWIDTH0)                        //~v50BI~
          			{                                                  //~v50BI~
	  	  		  		if (Popt & FCSPL_SPLITBNDS)	//search all delm  //~v76LI~
                    		newlen=minwidth;	//limit by margin/bnds     //~v76LI~
                  		else                                             //~v76LI~
            				newlen=Pdatalen;	//for the case delm not found//~v50BI~
//      				pc=umemmem(Ppdata,Ppdelmstr,(UINT)Pdatalen,(UINT)delmstrlen);//delm not found//~v76LR~
#ifdef UTF8UCS2                                                    //~va20I~
//      				pc=UTF_umemmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,0/*delmstrdbcs*/,newlen,delmstrlen);//delm not found//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        				pc=UCVEBCUTF_umemmem(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//delm not found//~va50I~
    #else                                                          //~va50I~
        				pc=UTF_umemmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//delm not found//~va5gR~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        				pc=umemmem(Ppdata,Ppdelmstr,(UINT)newlen,(UINT)delmstrlen);//delm not found//~v76LI~
#endif                                                             //~va20I~
            			if (pc)                                        //~v50BI~
                    	{                                              //~v50BI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
   		                	srchlen2=newlen;          //save for SI chk//~va50I~
#endif                                                             //~va50I~
//                			newlen=(int)((ULONG)pc-(ULONG)Ppdata)+delmstrlen;//~v50BI~//~vafkR~
                			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata)+delmstrlen;//~vafkI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					    	if (Sswebcfile)                            //~va50I~
                        	{                                          //~va50I~
                        		if (*(Spdelmdbcs+delmstrlen-1)==UDBCSCHK_DBCS2ND//~va50I~
                        		&&  (pc+delmstrlen<Ppdata+srchlen2 && *(pc+delmstrlen)==CHAR_SI)//~va50R~
                            	)                                      //~va50I~
                            		newlen++;                          //~va50I~
                        	}                                          //~va50I~
#endif                                                             //~va50I~
                			rc=0;                                      //~v50BI~
            			}                                              //~v50BI~
          			}                                                  //~v50BI~
          			else//not TOL not width0                           //~v50BR~
          			{                                                  //~v50BI~
//          			newlen=Pwidth;                                 //~v751R~
            			newlen=minwidth;                               //~v751I~
//          			pc=umemrmem(Ppdata,Ppdelmstr,(UINT)Pwidth,(UINT)delmstrlen);//~v751R~
#ifdef UTF8UCS2                                                    //~va20I~
//          			pc=UTF_umemrmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,0/*delmstrdbcs*/,newlen,delmstrlen);//~va5gR~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            			pc=UCVEBCUTF_umemrmem(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//~va50I~
    #else                                                          //~va50I~
            			pc=UTF_umemrmem(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen,delmstrlen);//~va5gI~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
            			pc=umemrmem(Ppdata,Ppdelmstr,(UINT)newlen,(UINT)delmstrlen);//~v751I~
#endif                                                             //~va20I~
            			if (pc)                                        //~v50BI~
                    	{                                              //~v50BI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    		srchlen2=newlen;	//save for SI chk      //~va50I~
#endif                                                             //~va50I~
//                			newlen=(int)((ULONG)pc-(ULONG)Ppdata)+delmstrlen;//~v50BI~//~vafkR~
                			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata)+delmstrlen;//~vafkI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					    	if (Sswebcfile)                            //~va50I~
                        	{                                          //~va50I~
                        		if (*(Spdelmdbcs+delmstrlen-1)==UDBCSCHK_DBCS2ND//~va50I~
                        		&&  (pc+delmstrlen<Ppdata+srchlen2 && *(pc+delmstrlen)==CHAR_SI)//~va50R~
                            	)                                      //~va50I~
                            		newlen++;                          //~va50I~
                        	}                                          //~va50I~
#endif                                                             //~va50I~
                			rc=0;                                      //~v50BI~
            			}                                              //~v50BI~
          			}                                                  //~v50BI~
         		}//not TOL option                                      //~v50BI~
        	}//str delm                                                //~v50BI~
//delm is chars                                                    //~v50BI~
        	else//char delm                                            //~v50BI~
        	{                                                          //~v50BI~
	  	 		if (Popt & FCSPL_TOL) //set delm to top of line           //~v50AI~
         		{                                                         //~v50AI~
          			rc=1;                                                    //~v50AI~
          			if (UCVEBCUTF_umemchr(Sswebcfile,Sswutf8file,Shandle,Ppdelmstr,Spdelmdbcs,*Ppdata,Sdelmstrlen))//~va8qR~
          				pctol=Ppdata;                                          //~va8qI~
          			else                                                     //~va8qI~
          				pctol=0;                                               //~va8qI~
         			if (!(pctol && Sotheropt & SOTHO_JOIN))                   //~va8kR~
         			{                                                         //~va8kI~
	  	  				if (Popt & FCSPL_ALLWIDTH0)                              //~v50AI~
          				{                                                        //~v50AI~
	  	   					if (Popt & FCSPL_SPLITBNDS)	//search all delm          //~v76LI~
            					newlen=minwidth;	//limit by margin/bnds             //~v76LI~
           					else                                                    //~v76LI~
            					newlen=Pdatalen;	//for the case delm not found      //~v50AI~
            				srchlen=newlen-1;                                      //~v50AI~
            				if (srchlen>0)                                         //~v50AI~
            				{                                                      //~v50AI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	  	      					if (UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*Ppdata,*Ppdbcs) && Popt & FCSPL_STRSPACE)//~va50I~
    #else                                                          //~va50I~
	  	      					if (UTF_eqspace(Sswutf8file,*Ppdata,*Ppdbcs) && Popt & FCSPL_STRSPACE)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	  	      					if (*Ppdata==' ' && Popt & FCSPL_STRSPACE)           //~v74XR~
#endif                                                             //~va20I~
              					{                                                    //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                					spacelen=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,Ppdata+1,Ppdbcs+1,srchlen);//~va50I~
    #else                                                          //~va50I~
                					spacelen=(int)UTF_umemspnc(Sswutf8file,Ppdata+1,Ppdbcs+1,' ',srchlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                					spacelen=(int)umemspnc(Ppdata+1,' ',(UINT)srchlen);           //~v74XI~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          						pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,Spdelmdbcs,srchlen-spacelen);//delm not found//~0512R~//~va79R~
            						pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,Spdelmdbcs,srchlen-spacelen);//delm not found//~va79I~
    #else                                                          //~va50I~
            						pc=UTF_umempbrk(Sswutf8file,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,srchlen-spacelen);//delm not found//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            						pc=umempbrk(Ppdata+1+spacelen,Ppdelmstr,(UINT)srchlen-spacelen);//delm not found//~v74XI~
#endif                                                             //~va20I~
              					}                                                    //~v74XI~
              					else                                                 //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          						pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata+1,Ppdbcs+1,Ppdelmstr,Spdelmdbcs,srchlen);//delm not found//~0512R~//~va79R~
            						pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata+1,Ppdbcs+1,Ppdelmstr,Spdelmdbcs,srchlen);//delm not found//~va79I~
    #else                                                          //~va50I~
            						pc=UTF_umempbrk(Sswutf8file,Ppdata+1,Ppdbcs+1,Ppdelmstr,srchlen);//delm not found//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            						pc=umempbrk(Ppdata+1,Ppdelmstr,(UINT)srchlen);//delm not found//~v50BR~
#endif                                                             //~va20I~
                				if (pc)                                            //~v50AI~
                				{                                                  //~v50AI~
//                    				newlen=(int)((ULONG)pc-(ULONG)Ppdata);         //~v50AI~//~vafkR~
                    				newlen=(int)((ULPTR)pc-(ULPTR)Ppdata);//~vafkI~
                    				rc=0;                                          //~v50AI~
                				}                                                  //~v50AI~
            				}                                                      //~v50AI~
          				}                                                        //~v50AI~
          				else//not width0                                         //~v50AI~
          				{                                                        //~v50AI~
//          				newlen=Pwidth;                                         //~v751R~
            				newlen=minwidth;                                       //~v751I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	  	   					if (UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*Ppdata,*Ppdbcs) && Popt & FCSPL_STRSPACE)//~va50I~
    #else                                                          //~va50I~
	  	   					if (UTF_eqspace(Sswutf8file,*Ppdata,*Ppdbcs) && Popt & FCSPL_STRSPACE)//~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
	  	   					if (*Ppdata==' ' && Popt & FCSPL_STRSPACE)              //~v74XI~
#endif                                                             //~va20I~
           					{                                                       //~v74XI~
            					srchlen=newlen-1;                                      //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            					spacelen=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,Ppdata+1,Ppdbcs+1,srchlen);//~va50R~
    #else                                                          //~va50I~
            					spacelen=(int)UTF_umemspnc(Sswutf8file,Ppdata+1,Ppdbcs+1,' ',srchlen);//~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
            					spacelen=(int)umemspnc(Ppdata+1,' ',(UINT)srchlen);               //~v74XI~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          					pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,Spdelmdbcs,srchlen-spacelen);//delm not found//~0512R~//~va79R~
            					pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,Spdelmdbcs,srchlen-spacelen);//delm not found//~va79I~
    #else                                                          //~va50I~
            					pc=UTF_umempbrk(Sswutf8file,Ppdata+1+spacelen,Ppdbcs+1+spacelen,Ppdelmstr,srchlen-spacelen);//delm not found//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
            					pc=umempbrk(Ppdata+1+spacelen,Ppdelmstr,(UINT)srchlen-spacelen);//delm not found//~v74XI~
#endif                                                             //~va20I~
           					}                                                       //~v74XI~
           					else                                                    //~v74XI~
#ifdef UTF8UCS2                                                    //~va5iI~
    #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50R~
//          					pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,(UINT)newlen);//~0512R~//~va79R~
//            					pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,(UINT)newlen);//~va79I~//~vb2DR~
              					pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen);//~vb2DI~
    #else                                                          //~va50R~
            					pc=UTF_umemrpbrk(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,(UINT)newlen);//~va5iR~
    #endif                                                         //~va50I~
#else                                                              //~va5iI~
            					pc=umemrpbrk(Ppdata,Ppdelmstr,(UINT)newlen);           //~v50BR~
#endif                                                             //~va5iI~
            				if (pc && pc!=Ppdata)                                  //~v50BR~
            				{                                                      //~v50BR~
//                				newlen=(int)((ULONG)pc-(ULONG)Ppdata);             //~v50BR~//~vafkR~
                				newlen=(int)((ULPTR)pc-(ULPTR)Ppdata);//~vafkI~
                				rc=0;                                              //~v50BR~
            				}                                                      //~v50AI~
          				}//not WIDTH0                                            //~v50AI~
         			}//tol match                                              //~va8kI~
          			if (rc && pctol==Ppdata)                                 //~va8qI~
          			{                                                        //~va8qI~
		  				Sotheropt|=SOTHO_DELMONTOL;    //delm matched on tol   //~va8qI~
		  		      if (!(Sotheropt & SOTHO_TOPLINETOL))         //~va8uR~
                      {                                            //~va8uI~
		  		       if (Sotheropt & SOTHO_JOIN)                 //~va8uI~
                       	rc=2,newlen=0;                             //~va8uI~
                       else                                        //~va8uI~
          				rc=0;                                                  //~va8qI~
                      }                                            //~va8uI~
          			}                                                        //~va8qI~
         		}                                                         //~v50AI~
         		else   //not TOL                                          //~v50AI~
         		{                                                         //~v50AI~
	  	  			if (Popt & FCSPL_ALLWIDTH0)//search 1st match                              //~v50zR~
          			{                                                        //~v50zR~
	  	   				if (Popt & FCSPL_SPLITBNDS)	//search all delm          //~v76LI~
            				newlen=minwidth;	//limit by margin/bnds             //~v76LI~
           				else                                                    //~v76LI~
            				newlen=Pdatalen;                                       //~v76LI~
//      				pc=umempbrk(Ppdata,Ppdelmstr,(UINT)Pdatalen);//delm not found//~v76LR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      				pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen);//delm not found//~0512R~//~va79R~
        				pc=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,newlen);//delm not found//~va79I~
    #else                                                          //~va50I~
        				pc=UTF_umempbrk(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,newlen);//delm not found//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
        				pc=umempbrk(Ppdata,Ppdelmstr,(UINT)newlen);//delm not found//~v76LI~
#endif                                                             //~va20I~
            			if (pc)                                                //~v50zR~
            			{                                                      //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	  	        			if (UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*pc,*XEUTF_PC2PCD(Ppdbcs,pc,Ppdata)) && Popt & FCSPL_STRSPACE)//~va50I~
    #else                                                          //~va50I~
	  	        			if (UTF_eqspace(Sswutf8file,*pc,*XEUTF_PC2PCD(Ppdbcs,pc,Ppdata)) && Popt & FCSPL_STRSPACE)//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
	  	        			if (*pc==' ' && Popt & FCSPL_STRSPACE)             //~v74XI~
#endif                                                             //~va20I~
                			{                                                  //~v74XI~
//                				srchlen=Pdatalen-(int)((ULONG)pc-(ULONG)Ppdata);    //~v74XI~//~vafkR~
                				srchlen=Pdatalen-(int)((ULPTR)pc-(ULPTR)Ppdata);//~vafkI~
                    			if (srchlen>1)                                 //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                					pc+=UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pc+1,XEUTF_PC2PCD(Ppdbcs,pc+1,Ppdata),(srchlen-1));//~va50I~
    #else                                                          //~va50I~
                					pc+=UTF_umemspnc(Sswutf8file,pc+1,XEUTF_PC2PCD(Ppdbcs,pc+1,Ppdata),' ',(srchlen-1));//~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                					pc+=umemspnc(pc+1,' ',(UINT)(srchlen-1));          //~v74XI~
#endif                                                             //~va20I~
                			}                                                  //~v74XI~
//                			newlen=(int)((ULONG)pc-(ULONG)Ppdata)+1;           //~v50zR~//~vafkR~
                			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata)+1;//~vafkI~
            			}                                                      //~v74XI~
            			else                                                   //~v50zR~
            			{                                                      //~v50zR~
//              			newlen=Pdatalen;                                   //~v76LR~
                			rc=1;                                              //~v50zR~
            			}                                                      //~v50zR~
          			}                                                        //~v50zR~
          			else                                                     //~v50zR~
//!WIDTH0                                                          //~0512I~
          			{                                                        //~v50zR~
//          			pc=umemrpbrk(Ppdata,Ppdelmstr,(UINT)Pwidth);           //~v751R~
#ifdef UTF8UCS2                                                    //~va5iI~
    #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          			pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,(UINT)minwidth);//~0512R~//~va79R~
//          			pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,(UINT)minwidth);//~va79I~//~vb2DR~
           		        pc=UCVEBCUTF_umemrpbrk_nonascii(Sswebcfile,Sswutf8file,Shandle,Ppdata,Ppdbcs,Ppdelmstr,Spdelmdbcs,minwidth);//~vb2DI~
    #else                                                          //~va50R~
            			pc=UTF_umemrpbrk(Sswutf8file,Ppdata,Ppdbcs,Ppdelmstr,(UINT)minwidth);//~va5iR~
    #endif                                                         //~va50I~
#else                                                              //~va5iI~
            			pc=umemrpbrk(Ppdata,Ppdelmstr,(UINT)minwidth);         //~v751I~
#endif                                                             //~va5iI~
            			if (pc)                                                //~v45xR~
            			{                                                      //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	  	        			if (UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*pc,*XEUTF_PC2PCD(Ppdbcs,pc,Ppdata)) && Popt & FCSPL_STRSPACE)//~va50I~
    #else                                                          //~va50I~
	  	        			if (UTF_eqspace(Sswutf8file,*pc,*XEUTF_PC2PCD(Ppdbcs,pc,Ppdata)) && Popt & FCSPL_STRSPACE)//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
	  	        			if (*pc==' ' && Popt & FCSPL_STRSPACE)             //~v74XI~
#endif                                                             //~va20I~
                			{                                                  //~v74XI~
//                				srchlen=Pdatalen-(int)((ULONG)pc-(ULONG)Ppdata);    //~v74XI~//~vafkR~
                				srchlen=Pdatalen-(int)((ULPTR)pc-(ULPTR)Ppdata);//~vafkI~
                    			if (srchlen>1)                                 //~v74XI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                					pc+=UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pc+1,XEUTF_PC2PCD(Ppdbcs,pc+1,Ppdata),(srchlen-1));//~va50I~
    #else                                                          //~va50I~
                					pc+=UTF_umemspnc(Sswutf8file,pc+1,XEUTF_PC2PCD(Ppdbcs,pc+1,Ppdata),' ',(srchlen-1));//~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                					pc+=umemspnc(pc+1,' ',(UINT)(srchlen-1));          //~v74XI~
#endif                                                             //~va20I~
                			}                                                  //~v74XI~
//                			newlen=(int)((ULONG)pc-(ULONG)Ppdata)+1;           //~v45xR~//~vafkR~
                			newlen=(int)((ULPTR)pc-(ULPTR)Ppdata)+1;//~vafkI~
            			}                                                      //~v74XI~
            			else                                                   //~v45xR~
            			{                                                      //~v45xR~
//              			newlen=Pwidth;                                     //~v751R~
                			newlen=minwidth;                                   //~v751I~
                			rc=1;                                              //~v45xR~
            			}                                                      //~v45xR~
          			}                                                        //~v50zR~
         		}//not TOL option                                         //~v50AI~
        	}//char delm                                               //~v50BI~
        }                                                          //~v45xR~
        else                                                       //~v45xR~
//no delm str                                                      //~v751I~
//      	if (Pwidth)                                              //~v751R~
        	if (minwidth)                                            //~v751I~
//          	newlen=Pwidth;                                         //~v751R~
            	newlen=minwidth;                                       //~v751I~
        	else  //no delm and no width                             //~v74YI~
          		newlen=Pdatalen;	//SPACE1 case                      //~v74YI~
        if (Sswebcfile && newlen>0)	//limit by width               //~va8kR~
        {                                                          //~va8kI~
        	optebsl=0;                                             //~va8kI~
			if (Sotheropt & SOTHO_JOIN)                            //~va8kR~
            	optebsl|=FCEBSLO_MIN0;                             //~va8kI~
    		if (Ppdelmstr && !rc && Popt & FCSPL_STRDELM)          //~va8kR~
    		  if (newlen<Pwidth)                                   //~v@@@I~
            	optebsl|=FCEBSLO_EXPAND;     //expandable within bnds range//~va8kI~
        	if (Sotheropt & SOTHO_IRB2NDOK)                        //~v@@@I~
            	optebsl|=FCEBSLO_IRB2NDOK;                         //~v@@@I~
            newleno=newlen;                                        //~v@@@I~
        	rc2=fcmdebcsplitlen(optebsl,Popt,Ppdata,Ppdbcs,Pdatalen,Pwidth,Ppdelmstr,&newlen);//~va8kR~
            if (rc2 & FCSPLRC_DELSI)                               //~v@@@I~
            {                                                      //~v@@@I~
            	rc2&=~FCSPLRC_DELSI;         //append so for split ebc dbcs string//~v@@@I~
                newlen++;                                          //~v@@@I~
				Sotheropt|=SOTHO_DELSI;    //append SO for split ebc dbcs string//~v@@@I~
            }                                                      //~v@@@I~
            if (rc2 & FCSPLRC_APPENDSO)         //append so for split ebc dbcs string//~va8kR~
            {                                                      //~va8kI~
            	rc2&=~FCSPLRC_APPENDSO;         //append so for split ebc dbcs string//~va8kR~
				Sotheropt|=SOTHO_APPENDSO;    //append SO for split ebc dbcs string//~va8kR~
            }                                                      //~va8kI~
//            if (rc2)        //dbcs split rc                        //~va8kI~//~v@@@R~
//            {                                                      //~va8kI~//~v@@@R~
////                if (!(      (rc2==4)                             //~va8kR~//~v@@@R~
////                         && (Sotheropt & SOTHO_EBCMIN0TOL)    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~//~v@@@R~
////                         && (Ppdelmstr)                          //~va8kR~//~v@@@R~
////                         && (Popt & FCSPL_TOL) //set delm to top of line//~va8kR~//~v@@@R~
////                     )                                           //~va8kR~//~v@@@R~
////                   )                                             //~va8kR~//~v@@@R~
//                    rc=rc2;     //keep rc=0/1 strdelm not found rc //~va8kR~//~v@@@R~
//            }                                                      //~va8kI~//~v@@@R~
//          if (!Ppdelmstr)                                        //~v@@@R~
//          if (!Ppdelmstr||rc2)                                   //~v@@@R~
            if (Ppdelmstr)                                         //~v@@@R~
            {                                                      //~v@@@I~
				if (rc==1)  //delm not found                       //~v@@@I~
                {                                                  //~v@@@I~
            		if (Pdatalen>Pwidth && newlen<Pwidth)          //~v@@@R~
                		rc=2;	//split to next line               //~v@@@R~
                }                                                  //~v@@@I~
                else    //delm found                               //~v@@@I~
                {                                                  //~v@@@I~
            		if (newlen<newleno) //by dbcs boundary         //~v@@@I~
                		rc=2;	//split to next line               //~v@@@I~
                }                                                  //~v@@@I~
            }                                                      //~v@@@I~
            else	//Pdatalen>Pwidth                              //~v@@@I~
            	if (newlen<Pwidth)                                 //~v@@@I~
                	rc=2;	//split to next line                   //~v@@@I~
        }                                                          //~va8kI~
        else                                                       //~va8kI~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
//      if (UDBCSCHK_DBCSNOTEND(*(Ppdbcs+newlen-1)))      //1st or pad//~vva1cR~//~va1cR~//~va8kR~
        if (newlen>0 && UDBCSCHK_DBCSNOTEND(*(Ppdbcs+newlen-1)))      //1st or pad//~vva1cR~//~va8kI~
#else                                                              //~vva1cR~//~va1cR~
        if (*(Ppdbcs+newlen-1)==DBCS1STCHAR)                       //~v45xR~
#endif                                                             //~vva1cR~//~va1cR~
        {                                                          //~v45xI~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
        	splitctrl=XESUB_DBCSSPLITCTR_L(Ppdbcs,newlen);	//left half//~vva1cR~//~va1cR~
        	splitctrr=XESUB_DBCSSPLITCTR_R(Ppdbcs+newlen,Pdatalen);	//righthalf//~vva1cR~//~va1cR~
#endif                                                             //~vva1cR~//~va1cR~
          	if (!(Popt & FCSPL_SBCS))                              //~v45xR~
            {                                                      //~v54YI~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
              	if (newlen<splitctrl+splitctrr)	//no space for 1 dbcs//~vva1cR~//~va1cR~
#else                                                              //~vva1cR~//~va1cR~
              	if (newlen==1)                                       //~v492I~
#endif                                                             //~vva1cR~//~va1cR~
              	{                                                    //~v492I~
               		if (!(Popt & FCSPL_MARGIN))	//keep max width       //~v74WI~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
              			newlen=splitctrl+splitctrr;	//1 dbcs               //~vva1cR~//~va1cR~
#else                                                              //~vva1cR~//~va1cR~
                		newlen=2;                                          //~v492R~
#endif                                                             //~vva1cR~//~va1cR~
         			if (Sotheropt & SOTHO_JOIN)                    //~va8rI~
                    {                                              //~va8rI~
                    	newlen=0;                                  //~va8rI~
                        rc=2;	//to next line                     //~va8rI~
                    }                                              //~va8rI~
                    else                                           //~va8rI~
                		rc=4;                                              //~v492R~
              	}                                                    //~v492I~
              	else                                                 //~v492I~
              	{                                                    //~v74WI~
                                                                   //~v74WI~
               		if (!(Popt & FCSPL_MARGIN)	//not bnds(end of line)//~v74WR~
               		||   (newlen<Pdatalen))  //dbcs split by concat(not by bnds)//~v74WR~
               		{                                                   //~v74WI~
                		if ((Popt & FCSPL_MARGIN))	//keep max width   //~v74WI~
                			rc=2;	//notify shift to next lign        //~v74WR~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
          	  			newlen-=splitctrl;                                 //~vva1cR~//~va1cR~
#else                                                              //~vva1cR~//~va1cR~
          	  			newlen--;                                          //~v45xR~
#endif                                                             //~vva1cR~//~va1cR~
               		}                                                   //~v74WI~
              	}                                                    //~v74WI~
            }//sbcs                                                //~v54YI~
            else                                                   //~v750I~
            {                                                      //~v750I~
               	if (Popt & FCSPL_SETDBCSERR)	//keep max width   //~v750R~
                {                                                  //~v750I~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
//  				memset(Ppdbcs+newlen-splitctrl,UDBCSCHK_HKDBCSERR,splitctrl+splitctrr);//~vva1cR~//~va1cR~//~vb2DR~
    				memset(Ppdbcs+newlen-splitctrl,UDBCSCHK_HKDBCSERR,(size_t)(splitctrl+splitctrr));//~vva1cR~//~vb2DI~
#else                                                              //~vva1cR~//~va1cR~
			        *(Ppdbcs+newlen-1)=UDBCSCHK_HKDBCSERR;         //~v750R~
               		if (newlen<Pdatalen)  //dbcs split by concat(not by bnds)//~v750I~
				        *(Ppdbcs+newlen)=UDBCSCHK_HKDBCSERR;       //~v750R~
#endif                                                             //~vva1cR~//~va1cR~
                }                                                  //~v750I~
                rc=2;                                              //~v750I~
            }                                                      //~v750I~
        }                                                          //~v45xI~
        else                                                       //~v45xR~
//          btabclear(Ppdata,Ppdbcs,Pdatalen,newlen,0);   //clear boundary tab//~v69tR~
            btabclear(Ppdata,Ppdbcs,Pdatalen,newlen,1);   //clear boundary tab,1:also right boundary//~v69tR~
    }                                                              //~v45xI~
    else                                                           //~v45xI~
    {                                                              //~va8kI~
//    Pdatalen<=Pwidth && !Ppdelmstr                               //~v@@@I~
    	newlen=Pdatalen;                                           //~v45xI~
        if (Sswebcfile && newlen>0)	//limit by width               //~va8kI~
        {                                                          //~va8kI~
        	optebsl=0;                                             //~va8kI~
    		if (Pdatalen<Pwidth)                                   //~va8kI~
        		optebsl=FCEBSLO_EXPAND;     //expandable within bnds range//~va8kR~
			if (Sotheropt & SOTHO_JOIN)                            //~va8kR~
            	optebsl|=FCEBSLO_MIN0;                             //~va8kI~
        	if (Sotheropt & SOTHO_IRB2NDOK)                        //~v@@@I~
            	optebsl|=FCEBSLO_IRB2NDOK;                         //~v@@@I~
        	rc2=fcmdebcsplitlen(optebsl,Popt,Ppdata,Ppdbcs,Pdatalen,Pwidth,Ppdelmstr,&newlen);//~va8kI~
            if (rc2 & FCSPLRC_DELSI)                               //~v@@@I~
            {                                                      //~v@@@I~
            	rc2&=~FCSPLRC_DELSI;         //append so for split ebc dbcs string//~v@@@I~
                newlen++;                                          //~v@@@I~
				Sotheropt|=SOTHO_DELSI;    //append SO for split ebc dbcs string//~v@@@I~
            }                                                      //~v@@@I~
            if (rc2 & FCSPLRC_APPENDSO)         //append so for split ebc dbcs string//~va8kI~
            {                                                      //~va8kI~
            	rc2&=~FCSPLRC_APPENDSO;         //append so for split ebc dbcs string//~va8kI~
				Sotheropt|=SOTHO_APPENDSO;    //append SO for split ebc dbcs string//~va8kI~
            }                                                      //~va8kI~
//          if (rc2)   	    //dbcs split rc                        //~va8kI~//~v@@@R~
//          	rc=rc2; 	//keep rc=0/1 strdelm not found rc     //~va8kI~//~v@@@R~
            if (newlen<Pdatalen)   	    //dbcs split rc            //~v@@@I~
            	rc=2;               //by dbcs split                //~v@@@I~
        }                                                          //~va8kI~
    }                                                              //~va8kI~
//  btabclear(Ppdata,Ppdbcs,Pdatalen,0,0);   //clear top of line tab//~v45xR~,//~v69BR~
    *Ppsplitlen=newlen;                                            //~v45xI~
    return rc;                                                     //~v45xI~
}//fcmdsplitlen                                                    //~v45xI~
//**************************************************************** //~v75kI~
// fcmdsplitbydelmbndseach                                         //~v75kI~
//*process tflow paragraph one by one                              //~v75kI~
//*return:rc                                                       //~v75kI~
//**************************************************************** //~v75kI~
int fcmdsplitbydelmbndseach(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v75kI~
						PULINEH Pplh1,PULINEH Pplh2,               //~v75kI~
                        int Pbndsoffs1,int Pbndsoffs2,             //~v75kR~
						UCHAR *Pcontwk,int Pcontwkwidth,int Pwidth,//~v75kI~
                        PULINEH *Ppplh1st,int *Ppdonectr,int *Pperrctr)//~v75kI~
{                                                                  //~v75kI~
    int   rc=0,rc2,maxparagno,paragno,donectr,errctr,errctrt=0,donectrt=0;//~v75kR~
    PULINEH plh1st,plh1,plh2;                                      //~v75kR~
//*********************************                                //~v75kI~
	maxparagno=Smaxparagno;                                        //~v75kR~
    plh2=Pplh1;                                                    //~v75kI~
    for (paragno=0;;paragno++)                                     //~v75kI~
    {                                                              //~v75kI~
    	if (maxparagno && paragno>=maxparagno)                     //~v75kR~
        	break;                                                 //~v75kI~
        plh1=plh2;                                                 //~v75kI~
        plh2=Pplh2;                                                //~v75kI~
		rc2=fcmdgetparagendplh(Popt,plh1,&plh2,1,Pbndsoffs1,Pbndsoffs2);	//get end of 1 paragraph//~v75kR~
		rc=fcmdsplitbydelmbnds(Popt,Ppcw,Ppfh,Ppdelmstr,plh1,plh2,Pcontwk,Pcontwkwidth,Pwidth,//~v75kI~
                        		&plh1st,&donectr,&errctr);         //~v75kR~
        errctrt+=errctr;                                           //~v75kI~
        donectrt+=donectr;                                         //~v75kR~
        if (!*Ppplh1st)                                            //~v75kR~
        	*Ppplh1st=plh1st;                                      //~v75kR~
        if (rc)                                                    //~v75kI~
        	break;                                                 //~v75kI~
        if (!rc2)	//plh2 not changed                             //~v75kI~
        	break;                                                 //~v75kI~
    }                                                              //~v75kI~
    *Ppdonectr=donectrt;                                           //~v75kR~
    *Pperrctr=errctrt;                                             //~v75kR~
    return rc;                                                     //~v75kI~
}//fcmdsplitbydelmbndseach                                         //~v75kI~
//**************************************************************** //~v74WI~
// fcmdsplitbydelmbnds                                             //~v74WI~
//*split when bnds set                                             //~v751R~
//*return:rc                                                       //~v74WI~
//**************************************************************** //~v74WI~
int fcmdsplitbydelmbnds(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v74WI~
						PULINEH Pplh1,PULINEH Pplh2,UCHAR *Pcontwk,int Pcontwkwidth,int Pwidth,//~v751R~
                        PULINEH *Ppplh1st,int *Ppdonectr,int *Pperrctr)//~v74WR~
{                                                                  //~v74WI~
    int   errctr=0,donectr=0,bndsoffs1,bndsoffs2,plhctrr,plhctrw,newlen;//~v74WR~
    int   ulhlen,rc,tgtlen,srcoffs/*,srcoffso*/,srclen,delmnotfoundsw; //~v758R~
    int len,nullsw;                                                //~v75nI~
    UQUEH qhbnds;                                                  //~v74WI~
    UCHAR *pdata/*,*pdbcs*/;                                           //~v74WR~
    UCHAR *pcontdata,*pcontdbcs;                                   //~v751I~
    PULINEH plh,plhs,plh1st=0,plhtmp,plhn=0;                         //~v75nR~
    int dbcsspliterr;                                              //~v74WI~
    int padlen;                                                    //~v758I~
    int updateskipsw;                                              //~v75LI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR *pdbcs;                                                  //~va20I~
#endif                                                             //~va20I~
//*********************************                                //~v74WI~
    pcontdata=Pcontwk;                                             //~v751R~
    pcontdbcs=Pcontwk+Pcontwkwidth;                                //~v751R~
	fcmdgetbnds(0,Ppfh,&bndsoffs1,&bndsoffs2);	//bnds is set      //~v74WI~
    srcoffs=0;                                                     //~v74WI~
	memset(&qhbnds,0,sizeof(qhbnds));                              //~v74WI~
    for (plh=plhs=Pplh1,plhctrw=0,plhctrr=0;plh && plh!=Pplh2;plh=plhn,plhctrw++)//~v75nR~
    {                                                              //~v74WI~
	    plhn=UGETQNEXT(plh);	//pre-get for delete case          //~v75nI~
        if (plh->ULHtype!=ULHTDATA)                                //~v74WI~
        	continue;                                              //~v74WI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v74WI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v74WI~
                return rc;                                         //~v74WI~
	    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v74WI~
    		if (rc=lcmdincm(Ppcw,plh),rc)                          //~v74WI~
        		return rc;                                         //~v74WI~
//      srcoffso=srcoffs;                                          //~v74WI~
        dbcsspliterr=0;                                            //~v74WI~
		fcmdebcchkdbcsconcatbndsupdate(Popt,plh,bndsoffs1,bndsoffs2,Pwidth);	//set to otheopt//~v@@@R~
        rc=fcmdsplitbndsgetsrc(Popt,Ppcw,Ppfh,Ppdelmstr,&plhs,Pplh2,Pwidth,//~v758R~
							bndsoffs1,bndsoffs2,Pcontwk,Pcontwkwidth,&plhctrr,&srcoffs,&srclen,&errctr,&qhbnds);//~v751R~
        if (rc & FCSPLRC_DBCSSPLIT)     //rc for bndsgetsrc        //~v74WI~
        {                                                          //~v74WI~
        	rc&=~FCSPLRC_DBCSSPLIT;     //rc for bndsgetsrc        //~v74WI~
            dbcsspliterr=1;                                        //~v74WI~
        }                                                          //~v74WI~
        delmnotfoundsw=0;                                          //~v74WI~
        if (rc==1)	//delm not found                               //~v74WI~
        {                                                          //~v74WI~
        	rc=0;                                                  //~v74WI~
            delmnotfoundsw=1;                                      //~v74WI~
        }                                                          //~v74WI~
        else                                                       //~v751I~
        if (rc==FCSPLRC_PSTOP)	//all paragraph processed          //~v751I~
        	rc=0;	//continue to fill space                       //~v751I~
        if (rc)                                                    //~v74WR~
        	break;                                                 //~v74WI~
        ulhlen=plh->ULHlen;                                        //~v74WI~
        tgtlen=0;                                                  //~v74WI~
        nullsw=0;                                                  //~v75nI~
        if (bndsoffs2)                                             //~v74WI~
        {                                                          //~v74WI~
            if (ulhlen>=bndsoffs2)   //oom exist                   //~v75mR~
            {                                                      //~v75mI~
                tgtlen=bndsoffs2-bndsoffs1;                        //~v74WR~
            }                                                      //~v75mI~
            else                                                   //~v74WR~
            if (ulhlen>bndsoffs1)   //margin data exist            //~v74WR~
                tgtlen=ulhlen-bndsoffs1;                           //~v74WR~
			if (!srclen)	//no data                              //~v75nI~
            {	//chk oom is all space                             //~v75nI~
				nullsw=1;                                          //~v75nI~
            	len=min(ulhlen,bndsoffs1);                         //~v75nI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (len && (int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,plh->ULHdata,plh->ULHdbcs,len)!=len)//~va50I~
    #else                                                          //~va50I~
                if (len && (int)UTF_umemspnc(Sswutf8file,plh->ULHdata,plh->ULHdbcs,' ',len)!=len)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (len && (int)umemspnc(plh->ULHdata,' ',(UINT)len)!=len)//~v75nR~
#endif                                                             //~va20I~
                	nullsw=0;	//do not delete                    //~v75nI~
                if (nullsw)                                        //~v75nR~
                {                                                  //~v75nI~
                    len=ulhlen-bndsoffs2;                          //~v75nI~
                    if (UCBITCHK(plh->ULHflag3,ULHF3SPFNUMOK))     //~v75nI~
	                    len-=SPFNUMFLDLEN;                         //~v75nI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    if (len>0 && (int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,plh->ULHdata+bndsoffs2,plh->ULHdbcs+bndsoffs2,len)!=len)//~va50I~
    #else                                                          //~va50I~
                    if (len>0 && (int)UTF_umemspnc(Sswutf8file,plh->ULHdata+bndsoffs2,plh->ULHdbcs+bndsoffs2,' ',len)!=len)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    if (len>0 && (int)umemspnc(plh->ULHdata+bndsoffs2,' ',(UINT)len)!=len)//~v75nR~
#endif                                                             //~va20I~
	                	nullsw=0;	//do not delete                //~v75nI~
                }                                                  //~v75nI~
            }                                                      //~v75nI~
            if (!nullsw)	//not the line to be deleted           //~v75nR~
            {                                                      //~v75nI~
                padlen=bndsoffs2-bndsoffs1-srclen;                 //~v75nI~
            	if (padlen>0)                                      //~v75nI~
                {                                                  //~v75nI~
                	if (Sswebcfile)                                //~v@@@I~
                    {                                              //~v@@@I~
                    	if (*(pcontdbcs+srclen-1)==UDBCSCHK_DBCS2ND)//~v@@@I~
                        {                                          //~v@@@I~
	                    	*(pcontdata+srclen)=CHAR_SI;           //~v@@@I~
	                    	*(pcontdbcs+srclen)=0;                 //~v@@@I~
                        	padlen--;                              //~v@@@I~
                            srclen++;                              //~v@@@I~
                        }                                          //~v@@@I~
                    }                                              //~v@@@I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                	memset(pcontdata+srclen,Schspace,(UINT)padlen);//~va50I~
#else                                                              //~va50I~
                	memset(pcontdata+srclen,' ',(UINT)padlen);     //~v75nI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                	memset(pcontdbcs+srclen,0,(UINT)padlen);       //~v75nI~
                    srclen+=padlen;                                //~v75nI~
                	if (Sswebcfile)                                //~v@@@I~
                    	if (padlen>0                               //~v@@@I~
                    	&&  ulhlen>bndsoffs2                       //~v@@@I~
                        &&  *(plh->ULHdbcs+bndsoffs2)==UDBCSCHK_DBCS1ST//~v@@@R~
                        )                                          //~v@@@I~
                			*(pcontdata+srclen-1)=CHAR_SO;         //~v@@@I~
                }                                                  //~v75nI~
            }                                                      //~v75nI~
        }                                                          //~v74WI~
        else                                                       //~v74WI~
        {                                                          //~v75nI~
            if (ulhlen>bndsoffs1)   //margin data exist            //~v74WI~
                tgtlen=ulhlen-bndsoffs1;                           //~v74WI~
            if (!srclen)    //no data                              //~v75nR~
            {                                                      //~v75nR~
                nullsw=1;                                          //~v75nR~
                len=ulhlen;                                        //~v75nR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (len && (int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,plh->ULHdata,plh->ULHdbcs,len)!=len)//~va50I~
    #else                                                          //~va50I~
                if (len && (int)UTF_umemspnc(Sswutf8file,plh->ULHdata,plh->ULHdbcs,' ',len)!=len)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (len && (int)umemspnc(plh->ULHdata,' ',(UINT)len)!=len)//~v75nR~
#endif                                                             //~va20I~
                    nullsw=0;   //do not delete                    //~v75nR~
            }                                                      //~v75nR~
        }                                                          //~v75nI~
//      donectr++;                                                 //~v75vR~
        donectr++;                                                 //~v75LI~
        updateskipsw=0;                                            //~v75LI~
        if (srclen==tgtlen)	//tgt==src                             //~v75mR~
        {                                                          //~v@@@I~
//       if (!srclen)                                              //~v75LR~
         if (srclen)                                               //~v75LI~
//*compare both data and dbcs                                      //~va20I~
          if (!memcmp(plh->ULHdata+bndsoffs1,pcontdata,(UINT)srclen)//~v751R~
          &&  !memcmp(plh->ULHdbcs+bndsoffs1,pcontdbcs,(UINT)srclen))//same update data//~v751R~
//      	continue;	                                           //~v75LR~
        	updateskipsw=1;                                        //~v75LI~
        }                                                          //~v@@@I~
//        else                                                     //~v@@@I~
//        if (srclen==tgtlen+2                                     //~v@@@I~
//        &&  *pcontdata==CHAR_SO && *(pcontdata+srclen-1)==CHAR_SI//~v@@@I~
//        )      //for full data                                   //~v@@@I~
//        {                                                        //~v@@@I~
//          if (!memcmp(plh->ULHdata+bndsoffs1,pcontdata+1,(UINT)tgtlen)//~v@@@I~
//          &&  !memcmp(plh->ULHdbcs+bndsoffs1,pcontdbcs+!,(UINT)tgtlen))//same update data//~v@@@I~
//            updateskipsw=1;                                      //~v@@@I~
//        }                                                        //~v@@@I~
      if (!updateskipsw)                                           //~v75LI~
      {                                                            //~v75LI~
	    if ((plhctrw+1)>plhctrr)//not data gotten                  //~v751I~
        {                                                          //~v74WI~
        	plhtmp=plh;                                            //~v74WI~
			rc=fcmdsplitbndsgetsrcplh(Popt,Ppcw,Ppfh,&plhtmp,Pplh2,Pwidth,bndsoffs1,bndsoffs2,0,&qhbnds,&errctr);//save data//~v75jI~
#ifdef UTF8SUPPH                                                   //~va17I~
        	if (rc==FCSPLRC_DBCSSPLIT)     //rc for bndsgetsrc     //~va17I~
        	{                                                      //~va17I~
        		rc=0;                                              //~va17I~
//          	dbcsspliterr=1;  //srcplh was already set temperr  //~va17I~//~v@@@R~
        	}                                                      //~va17I~
#endif                                                             //~va17I~
            if (rc)                                                //~v74WR~
            	break;                                             //~v74WI~
        }                                                          //~v74WI~
//      donectr++;                                                 //~v75LR~
	  if (nullsw)                                                  //~v75nI~
        rc=lcmddel(Ppcw,plh,plh,1,0,1);//1 line,no csr set,not from lcmd main//~v75nI~
      else                                                         //~v75nI~
      {                                                            //~v@@@I~
       if (Sotheropt&SOTHO_DELSI)                                  //~v@@@R~
        rc=fcmdsplitbndsupdate(Popt,Ppcw,Ppfh,plh,Pwidth,bndsoffs1,bndsoffs2,Pcontwk,Pcontwkwidth,srclen-1);//~v@@@I~
       else                                                        //~v@@@R~
        rc=fcmdsplitbndsupdate(Popt,Ppcw,Ppfh,plh,Pwidth,bndsoffs1,bndsoffs2,Pcontwk,Pcontwkwidth,srclen);//~v751R~
      }                                                            //~v@@@I~
        if (rc)                                                    //~v75nR~
        	break;                                                 //~v74WI~
      }                                                            //~v75LI~
	  if (!nullsw)	//not deleted                                  //~v75nI~
      {                                                            //~v75nI~
//      if (delmnotfoundsw)                                        //~v74WR~
        if (delmnotfoundsw||dbcsspliterr)                          //~v74WI~
	    {                                                          //~v74WI~
//  	    lcmdshifterr(plh,0,0);  //set reverse                  //~v75fR~
//      	errctr++;                                              //~v75fR~
            fcmdsettemperr(0,plh);                                 //~v75fI~
        }                                                          //~v74WI~
        if (!plh1st)                                               //~v74WR~
        	plh1st=plh;                                            //~v74WI~
      }                                                            //~v75nI~
    }                                                              //~v74WI~
//insert remaining data                                            //~v74WI~
    if (!plh)                                                      //~v74WI~
    	plh=UGETQEND(&Ppfh->UFHlineque);                           //~v74WR~
    plh=UGETQPREV(plh);	//insert after                             //~v74WI~
    pdata=Pcontwk;                                                 //~v74WR~
//  pdbcs=Pcontwk+Pcontwkwidth;                                    //~v751R~
#ifdef UTF8UCS2                                                    //~va20I~
	pdbcs=Pcontwk+Pcontwkwidth;                                    //~va20I~
#endif                                                             //~va20I~
	fcmdebcchkdbcsconcatbndsupdate(Popt,0/*plh*/,bndsoffs1,bndsoffs2,Pwidth);	//clear boundary status//~v@@@R~
    for (;;)                                                       //~v74WI~
    {                                                              //~v74WI~
        dbcsspliterr=0;                                            //~v74WI~
        rc=fcmdsplitbndsgetsrc(Popt|FCSPL_SRCPLHEND,Ppcw,Ppfh,Ppdelmstr,0,Pplh2,Pwidth,//~v758R~
							bndsoffs1,bndsoffs2,Pcontwk,Pcontwkwidth,&plhctrr,&srcoffs,&srclen,&errctr,&qhbnds);//~v751R~
        if (rc & FCSPLRC_DBCSSPLIT)     //rc for bndsgetsrc        //~v74WI~
        {                                                          //~v74WI~
        	rc&=~FCSPLRC_DBCSSPLIT;     //rc for bndsgetsrc        //~v74WI~
            dbcsspliterr=1;                                        //~v74WI~
        }                                                          //~v74WI~
        delmnotfoundsw=0;                                          //~v74WI~
        if (rc==1)	//delm not found                               //~v74WI~
        {                                                          //~v74WI~
        	rc=0;                                                  //~v74WI~
            delmnotfoundsw=1;                                      //~v74WI~
        }                                                          //~v74WI~
        if (rc)                                                    //~v74WI~
        	break;                                                 //~v74WI~
        if (!srclen)                                               //~v74WI~
        	break;                                                 //~v74WI~
        newlen=bndsoffs1+srclen;                                   //~v74WR~
        if (Pwidth>newlen)                                         //~v758I~
        {	                                                       //~v758I~
        	padlen=Pwidth-newlen;                                  //~v758I~
            newlen=Pwidth;                                         //~v758I~
        }                                                          //~v758I~
        else                                                       //~v758I~
	        padlen=0;                                              //~v758I~
#ifdef UTF8UCS2                                                    //~va20I~
//    if (Sswutf8file)                                             //~va20R~//~v@@@R~
      if (Sswutf8file||Sswebcfile)  //abend for ebc file           //~v@@@I~
    	rc=lcmdisrtwithlen(Ppcw,plh,1,LCIO_ALLOCDBCS,newlen);//allocate also plhdbcs//~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
    	rc=lcmdisrtwithlen(Ppcw,plh,1,0,newlen);                   //~v74WI~
        if (rc)                                                    //~v74WI~
        	break;                                                 //~v74WI~
        plh=UGETQNEXT(plh);	//isrted to be set err                 //~v@@@I~
//      if (delmnotfoundsw)                                        //~v74WR~
        if (delmnotfoundsw||dbcsspliterr)                          //~v74WI~
	    {                                                          //~v74WI~
//  	    lcmdshifterr(plh,0,0);  //set reverse                  //~v75fR~
//      	errctr++;                                              //~v75fR~
            fcmdsettemperr(0,plh);                                 //~v75fI~
        }                                                          //~v74WI~
//      plh=UGETQNEXT(plh);	//isrted                               //~v74WI~//~v@@@R~
        if (bndsoffs1)                                             //~v74WI~
        {                                                          //~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	memset(plh->ULHdata,Schspace,(UINT)bndsoffs1);         //~va50I~
#else                                                              //~va50I~
        	memset(plh->ULHdata,' ',(UINT)bndsoffs1);                    //~v74WI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//      	memset(plh->ULHdbcs,0  ,bndsoffs1);                    //~v74WR~
#ifdef UTF8UCS2                                                    //~va20I~
//*for non utf8 file dbcs is not allocated by lcmdisrtwithlen*     //~va20I~
	      	if (Sswutf8file)                                       //~va20R~
//  			memset(plh->ULHdbcs,0  ,bndsoffs1);                //~va20I~//~vb2DR~
    			memset(plh->ULHdbcs,0  ,(size_t)bndsoffs1);        //~vb2DI~
#endif                                                             //~va20I~
        }                                                          //~v74WI~
        memcpy(plh->ULHdata+bndsoffs1,pdata,(UINT)srclen);               //~v74WI~
//      memcpy(plh->ULHdbcs+bndsoffs1,pdbcs,srclen);               //~v74WR~
#ifdef UTF8UCS2                                                    //~va20I~
//    	if (Sswutf8file)                                           //~va20R~//~v@@@R~
      	if (Sswutf8file||Sswebcfile)                               //~v@@@I~
//    		memcpy(plh->ULHdbcs+bndsoffs1,pdbcs,srclen);           //~va20I~//~vb2DR~
      		memcpy(plh->ULHdbcs+bndsoffs1,pdbcs,(size_t)srclen);   //~vb2DI~
#endif                                                             //~va20I~
		if (padlen)                                                //~v758I~
        {                                                          //~va20I~
            if (Sswebcfile)                                        //~v@@@I~
            {                                                      //~v@@@I~
                if (*(pdbcs+srclen-1)==UDBCSCHK_DBCS2ND)           //~v@@@R~
                {                                                  //~v@@@I~
                    *(plh->ULHdata+bndsoffs1+srclen)=CHAR_SI;      //~v@@@R~
                    *(plh->ULHdbcs+bndsoffs1+srclen)=0;            //~v@@@R~
                    padlen--;                                      //~v@@@I~
                    srclen++;                                      //~v@@@I~
                }                                                  //~v@@@I~
            }                                                      //~v@@@I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        memset(plh->ULHdata+bndsoffs1+srclen,Schspace,(UINT)padlen);//dbcstbl will set at display//~va50I~
#else                                                              //~va50I~
	        memset(plh->ULHdata+bndsoffs1+srclen,' ',(UINT)padlen);//dbcstbl will set at display//~v758I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
//	  		if (Sswutf8file)                                       //~va20R~//~v@@@R~
  	  		if (Sswutf8file||Sswebcfile)                           //~v@@@I~
	        	memset(plh->ULHdbcs+bndsoffs1+srclen,0,(UINT)padlen);//~va20I~
#endif                                                             //~va20I~
        }                                                          //~va20I~
//      donectr++;                                                 //~v75vR~
    }                                                              //~v74WI~
    UQUFREE(&qhbnds);                                              //~v74WI~
    *Pperrctr=errctr;                                              //~v74WI~
    *Ppdonectr=donectr;                                            //~v74WI~
    *Ppplh1st=plh1st;                                              //~v74WI~
    return rc;                                                     //~v74WI~
}//filesplitbydelmbnds                                             //~v74WI~
//**************************************************************** //~v74WI~
// fcmdsplitbndsgetsrc                                             //~v74WI~
//*gather data in margin by bnds/margin setting                    //~v74WI~
//*return:rc:UALLOC_FAILED,1:delm not found,PSTOP(32)              //~v758R~
//*       0x80:dbcsspliterr                                        //~v74WI~
//**************************************************************** //~v74WI~
int fcmdsplitbndsgetsrc(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR *Ppdelmstr,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v758R~
							int Pbndsoffs1,int Pbndsoffs2,UCHAR *Pcontwk,int Pcontwkwidth,int *Ppplhctrr,int *Ppsrcoffs,int *Ppsrclen,int *Pperrctr,UQUEH *Ppqhbnds)//~v751R~
{                                                                  //~v74WI~
	int errctr,srcoffs,contlen,width,len,len2,tgtwidth,rc=0,linefilledsw,delmnotfoundsw=0;//~v74WR~
    int headcnt,indentoffs=0/*,rc2*/;                              //~v75uR~
    int dbcsspliterr=0;                                            //~v74WI~
    int dbcsspliterrplh=0;                                         //~v@@@I~
    UCHAR *pdata,*pdbcs,*pcontdata,*pcontdbcs;                     //~v74WR~
    PSPLITWK pspw;                                                 //~v74WI~
    int rcparag;                                                   //~v75iI~
    int swinsertsosi,optobdbcs;                                    //~va8kR~
    int len2split,linefilledswsplit;                               //~va8vR~
    PSPLITWK pspwsplit=0;                                          //~va8vI~
    int dropsosicnt,cutflag,swdropso,swdropendsi,swendconcat,swheadconcat,swinserttopso,widthsosi;               //~va8wI~//~v@@@R~
//******************************                                   //~v74WI~
//  Sotheropt&=~(SOTHO_BNDSCONTSETSO|SOTHO_BNDSCONTSETSI);	//parm to bndsupdate to join to boundary dbcs dropping sosi//~va8wR~//~v@@@R~
    srcoffs=*Ppsrcoffs;                                            //~v74WR~
    errctr=*Pperrctr;                                              //~v74WI~
    pcontdata=Pcontwk;                                             //~v74WI~
    pcontdbcs=Pcontwk+Pcontwkwidth;                                //~v751R~
    tgtwidth=Pwidth-Pbndsoffs1;                                    //~v74WI~
    for (contlen=0;;)                                              //~v74WI~
    {                                                              //~v74WI~
		pspw=UGETQTOP(Ppqhbnds);                                   //~v74WI~
        if (!pspw)                                                 //~v74WR~
        {                                                          //~v74WI~
			if (Popt & FCSPL_SRCPLHEND) //last insert phase        //~v74WI~
	        	break;                                             //~v74WI~
	    	rc=fcmdsplitbndsgetsrcplh(Popt,Ppcw,Ppfh,Ppplh,Pplh2,Pwidth,Pbndsoffs1,Pbndsoffs2,Ppplhctrr,Ppqhbnds,&errctr);//~v751R~
#ifdef UTF8SUPPH                                                   //~va17I~
        	if (rc==FCSPLRC_DBCSSPLIT)     //rc for bndsgetsrc     //~va17I~
        	{                                                      //~va17I~
        		rc=0;                                              //~va17I~
//          	dbcsspliterr=1;                                    //~va17I~//~v@@@R~
        	}                                                      //~va17I~
#endif                                                             //~va17I~
            if (rc)                                                //~v74WR~
            	break;                                             //~v74WI~
			pspw=UGETQTOP(Ppqhbnds);                               //~v74WI~
            srcoffs=0;                                             //~v74WI~
        }                                                          //~v74WI~
        if (!pspw)                                                 //~v74WI~
        	break;                                                 //~v74WI~
        if (srcoffs)    //left boundary already used               //~v@@@I~
	    	dbcsspliterrplh=(pspw->SPWflag & (SPWF_DBCSSPLITR));	//getsrcplh detected dbcs split//~v@@@R~
        else                                                       //~v@@@I~
	    	dbcsspliterrplh=(pspw->SPWflag & (SPWF_DBCSSPLITL|SPWF_DBCSSPLITR));	//getsrcplh detected dbcs split//~v@@@I~
        if (Popt & FCSPL_TFLOW)                                    //~v75iI~
        {                                                          //~v75iI~
            if (!(pspw->SPWflag & SPWF_PARAGCHKED))	//not yet paragraph chked//~v75iI~
            {                                                      //~v75iI~
	            pspw->SPWflag|=SPWF_PARAGCHKED;	//not yet paragraph chked//~v75iI~
                Sbndsheadcnt=pspw->SPWheadcnt;  //parm to fcmdtflowgetindent;//~v75iI~
                len=pspw->SPWlen;                                  //~v75iI~
#ifdef UTF8UCS2                                                    //~va20I~
//              rcparag=fcmdtflowgetindent((int)(Popt|FCSPL_SPWKPARAG),0,pspw->SPWdatadbcs,pspw->SPWdatadbcs+pspw->SPWlen,pspw->SPWlen,0);    //set Sindentoffs//~va20I~//~vb2DR~
                rcparag=fcmdtflowgetindent((int)((UINT)Popt|FCSPL_SPWKPARAG),0,pspw->SPWdatadbcs,pspw->SPWdatadbcs+pspw->SPWlen,pspw->SPWlen,0);    //set Sindentoffs//~vb2DI~
#else                                                              //~va20I~
                rcparag=fcmdtflowgetindent((int)(Popt|FCSPL_SPWKPARAG),0,pspw->SPWdatadbcs,pspw->SPWlen,0);    //set Sindentoffs//~v75iR~
#endif                                                             //~va20I~
                if (rcparag==FCSPLRC_PNEW)  //paragraph changed    //~v75iI~
                    pspw->SPWflag|=SPWF_PNEW;                      //~v75iI~
                else                                               //~v75iI~
                if (rcparag==FCSPLRC_PSTOP) //paragraph changed    //~v75iI~
                    pspw->SPWflag|=SPWF_PSTOP;                     //~v75iI~
            }                                                      //~v75iI~
        }                                                          //~v75iI~
      if (pspw->SPWflag & SPWF_PSTOP)	//indentation change       //~v758R~
      {                                                            //~v758R~
        if (contlen)                                               //~v758R~
	  		linefilledsw=1;	//set trailer space                    //~v758I~
        else                                                       //~v758I~
        {                                                          //~v758I~
			rc=FCSPLRC_PSTOP;                                      //~v758I~
            break;                                                 //~v758I~
        }                                                          //~v758I~
      }                                                            //~v758R~
      else                                                         //~v758I~
      if (pspw->SPWflag & SPWF_PNEW && contlen)	//indentation change//~v758I~
  		linefilledsw=1;	//set trailer space                        //~v758I~
      else                                                         //~v758I~
      {                                                            //~v758I~
        pdata=pspw->SPWdatadbcs+srcoffs;                           //~v74WI~
        pdbcs=pspw->SPWdatadbcs+pspw->SPWlen+srcoffs;              //~v74WI~
        len=pspw->SPWlen-srcoffs;                                  //~v74WI~
  		if (Popt & FCSPL_TFLOW)                                    //~v751I~
        {                                                          //~v751I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,(UINT)len);//~va50I~//~vb2DR~
        	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,len);//~vb2DI~
    #else                                                          //~va50I~
        	headcnt=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',(UINT)len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	headcnt=(int)umemspnc(pdata,' ',(UINT)len);                       //~v751R~
#endif                                                             //~va20I~
            pdata+=headcnt;                                        //~v751I~
            pdbcs+=headcnt;                                        //~v751I~
            srcoffs+=headcnt;                                      //~v751I~
            len-=headcnt;                                          //~v751I~
        }                                                          //~v751I~
//      else	//SPLIT cmd                                        //~va8wI~//~v@@@R~
//      {                                                          //~va8wI~//~v@@@R~
//          if (!contlen)	//top data in bnds                     //~va8wI~//~v@@@R~
//  	    	if (pspw->SPWflag & SPWF_SETSO)	//bnds data to is dbcssplit//~va8wR~//~v@@@R~
//              	Sotheropt|=SOTHO_BNDSCONTSETSO;                //~va8wR~//~v@@@R~
//      }                                                          //~va8wI~//~v@@@R~
		width=tgtwidth-contlen;                                    //~v74WR~
  		if (Popt & FCSPL_TFLOW)                                    //~v751R~
        {                                                          //~v751I~
            indentoffs=Sindentoffs;                                //~v751I~
        	if (!contlen)	//TOL                                  //~v751I~
            {                                                      //~v751I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                memset(pcontdata,Schspace,(UINT)indentoffs);       //~va50I~
#else                                                              //~va50I~
                memset(pcontdata,' ',(UINT)indentoffs);                  //~v751R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                memset(pcontdbcs,0  ,(UINT)indentoffs);                  //~v751R~
                contlen=indentoffs;                                //~v751R~
                width-=contlen;                                    //~v751I~
            }                                                      //~v751I~
            else                                                   //~v751I~
            {                                                      //~v75qI~
#ifdef UTF8UCS2                                                    //~va20I~
                if (width>2 && UTF_eq(Sswutf8file,*(pcontdata+contlen-1),*(pcontdbcs+contlen-1),SPECIALDELM1))//~va20R~
#else                                                              //~va20I~
                if (width>2 && *(pcontdata+contlen-1)==SPECIALDELM1)//~v75qI~
#endif                                                             //~va20I~
                {                                                  //~v75qI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                  *(pcontdata+contlen)=Schspace;                 //~va50I~//~vb2CR~
                    *(pcontdata+contlen)=(UCHAR)Schspace;          //~vb2CI~
#else                                                              //~va50I~
                    *(pcontdata+contlen)=' ';                      //~v75qI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    *(pcontdbcs+contlen)=0;                        //~v75qI~
                    contlen++;                                     //~v75qI~
                    width--;                                       //~v75qI~
                }                                                  //~v75qI~
                if (width>1)                                       //~v751I~
                {                                                  //~v751R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                  *(pcontdata+contlen)=Schspace;                 //~va50I~//~vb2CR~
                    *(pcontdata+contlen)=(UCHAR)Schspace;          //~vb2CI~
#else                                                              //~va50I~
                    *(pcontdata+contlen)=' ';                      //~v751R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    *(pcontdbcs+contlen)=0;                        //~v751R~
                    contlen++;                                     //~v751R~
                    width--;                                       //~v751R~
                }                                                  //~v751R~
            }                                                      //~v75qI~
			if (contlen>indentoffs)                                //~v75uI~
		        Popt|=FCSPL_TFJOIN;                                //~v75uI~
        }                                                          //~v751I~
		if (contlen>indentoffs)                                    //~va8sI~
			Sotheropt|=SOTHO_JOIN;	//parm to fcmdsplitlen;allow length=0//~va8kR~
//      swebcfileconcatdbcs=fcmdebcchkdbcsconcatbnds(Popt,pcontdata,pcontdbcs,contlen,swebcfileconcatdbcsso,pspw,srcoffs,tgtwidth);//~va8wI~//~v@@@R~
        dropsosicnt=fcmdebcchkdbcsconcatbnds(Popt,pcontdata,pcontdbcs,contlen,&cutflag,pspw,srcoffs,tgtwidth,-1/*splitlen*/);//~v@@@R~
//    	swinserttopso=(cutflag & FCEBCCF_INSERTSO)!=0;             //~v@@@R~
      	swinserttopso=0;        //so is already inserted when pspw data was split//~v@@@R~
//      swebcfileconcatdbcsso=(pspw->SPWflag & SPWF_DBCSSPLITR)!=0;//~va8wR~//~v@@@R~
		widthsosi=max(dropsosicnt-swinserttopso,0);                //~v@@@I~
//  	linefilledsw=fcmdsplitlenbnds(Popt,pdata,pdbcs,Ppdelmstr,len,width,&len2);//~v74WI~//~v@@@R~
    	linefilledsw=fcmdsplitlenbnds(Popt,pdata,pdbcs,Ppdelmstr,len,width+widthsosi,&len2);//~v@@@R~
        if (len2!=len)	//data split by width or delm              //~v@@@I~
	        dropsosicnt=fcmdebcchkdbcsconcatbnds(Popt,pcontdata,pcontdbcs,contlen,&cutflag,pspw,srcoffs,tgtwidth,len2);//reevaluate cutflag//~v@@@I~
		Sotheropt&=~SOTHO_JOIN;	//parm to fcmdsplitlen;allow length=0//~va8kR~
        if (linefilledsw & FCSPLRC_TFEBCSPLIT)         //tflow split long for ebcfile//~v@@@I~
        {                                                          //~v@@@I~
    		linefilledsw&=~FCSPLRC_TFEBCSPLIT;                     //~v@@@I~
            pspw->SPWflag|=SPWF_TFEBCSPLIT;                        //~v@@@I~
        }                                                          //~v@@@I~
        if (!linefilledsw && (pspw->SPWflag & SPWF_TFEBCSPLIT))    //~v@@@I~
        	linefilledsw=2;	//switch to next line                  //~v@@@I~
		swinsertsosi=(Sotheropt & SOTHO_APPENDSO)!=0;    //append SI for split ebc dbcs string//~va8kI~
//split cmd select last delm in the joined line                    //~va8vI~
  	    if (!(Popt & FCSPL_TFLOW)                                  //~va8vI~
        && Ppdelmstr                                               //~v@@@R~
        && !(Popt & FCSPL_NOWIDTH) 	//if width parm,search last delm matched//~v@@@I~
        && linefilledsw!=1		//delm not found,chk full concatlen//~v@@@I~
        && contlen  //data stacked                                 //~va8vI~
        && len>=(width+widthsosi) 		//split by width   //~va8vR~//~va8wR~//~v@@@R~
        )                                                          //~va8vI~
        {                                                          //~va8vI~
			Sotheropt|=SOTHO_SPLITJOINED;                          //~va8vI~
			linefilledswsplit=fcmdsplitlenbnds(Popt,pcontdata,pcontdbcs,Ppdelmstr,contlen,tgtwidth,&len2split);//~va8vR~
			Sotheropt&=~SOTHO_SPLITJOINED;                         //~va8vI~
			if (!(Sotheropt & SOTHO_DELMONTOL)     //delm matched on tol//~va8vR~
            &&  linefilledswsplit==1)    //delmfound               //~va8vR~
            {                                                      //~va8vI~
				pspwsplit=fcmdsplitbndsjoinedsplit(0,pcontdata,pcontdbcs,contlen,len2split);//~va8vI~//~v@@@R~
                contlen=len2split;                                 //~va8vI~
                len2=0;			//no copy                          //~va8vI~
                cutflag=0;                                         //~v@@@R~
                linefilledsw=1;                                    //~va8vI~
            }                                                      //~va8vI~
        }                                                          //~va8vI~
        delmnotfoundsw=(linefilledsw>=4);                          //~v74WR~
  		if (Popt & FCSPL_TFLOW && delmnotfoundsw)                  //~v751R~
        {                                                          //~v75BI~
  			if (contlen>indentoffs)	//concatination                //~v751I~
            {                                                      //~v75kI~
        		len2=0;	//shift to next line                       //~v751R~
                delmnotfoundsw=0;       //to set rc=0;             //~v75kI~
            }                                                      //~v75kI~
            else                    //top of line                  //~v751R~
            {                                                      //~v751I~
              if (!Sswebcfile)	//space required for sosi,split to next line like as split cmd//~v@@@I~
                len2=len;   //write full record                    //~v75uI~
            }                                                      //~v751I~
        }                                                          //~v75BI~
        len=len2;                                                  //~v74WI~
        swdropso=0;                                                //~v@@@I~
        swdropendsi=0;                                             //~v@@@I~
      	if (len && cutflag & FCEBCCF_TOPSO)                            //~va8wR~//~v@@@R~
      	{                                                          //~va8wR~
      		pdata++,pdbcs++,len--;                       //~va8wI~ //~v@@@R~
	        swdropso=1;                                            //~v@@@I~
      	}                                                          //~va8wR~
      	if (len && cutflag & FCEBCCF_INTSOSI)                      //~v@@@R~
      	{                                                          //~v@@@I~
      		contlen--,pdata++,pdbcs++,len--;                       //~v@@@I~
	        swdropso=1;                                            //~v@@@I~
      	}                                                          //~v@@@I~
      	if (len && cutflag & FCEBCCF_ENDSI)                        //~v@@@R~
      	{                                                          //~v@@@I~
      		len--;                                                 //~v@@@I~
	        swdropendsi=1;                                         //~v@@@I~
      	}                                                          //~v@@@I~
      	swendconcat=cutflag & FCEBCCF_ENDCONCAT;                   //~v@@@R~
      	swheadconcat=cutflag & FCEBCCF_HEADCONCAT;                 //~v@@@I~
        if (swinserttopso)                                         //~v@@@I~
        {                                                          //~v@@@I~
            *(pcontdata+contlen)=CHAR_SO;                          //~v@@@I~
            *(pcontdbcs+contlen)=0;                                //~v@@@I~
            contlen++;                                             //~v@@@I~
        }                                                          //~v@@@I~
        memcpy(pcontdata+contlen,pdata,(UINT)len);                       //~v74WR~
        memcpy(pcontdbcs+contlen,pdbcs,(UINT)len);                       //~v74WR~
        if (pdata+len<pspw->SPWdatadbcs+pspw->SPWlen)              //~v@@@I~
	    	dbcsspliterrplh&=~SPWF_DBCSSPLITR;	//not use right boundary split data//~v@@@M~
        if (len && dbcsspliterrplh)                                //~v@@@I~
        	dbcsspliterr|=1;                                       //~v@@@I~
        if (swinsertsosi)                                          //~va8kI~
        {                                                          //~va8kM~
            *(pcontdata+contlen+len)=CHAR_SI;                      //~va8kI~
            *(pcontdbcs+contlen+len)=0;                            //~va8kI~
        }                                                          //~va8kM~
        if (Popt & FCSPL_SPACE1)                                   //~v74YI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        if ((contlen>indentoffs && UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*(pcontdata+contlen-1),*(pcontdbcs+contlen-1)))//~va50I~
        &&  (len && UCVEBCUTF_eqspace(Sswebcfile,Sswutf8file,*pdata,*pdbcs)))	//concat at space//~va50I~
    #else                                                          //~va50I~
        if ((contlen>indentoffs && UTF_eqspace(Sswutf8file,*(pcontdata+contlen-1),*(pcontdbcs+contlen-1)))//~va20R~
        &&  (len && UTF_eqspace(Sswutf8file,*pdata,*pdbcs)))	//concat at space//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        if ((contlen>indentoffs && *(pcontdata+contlen-1)==' ')    //~v751R~
        &&  (len && *pdata==' '))	//concat at space              //~v74YR~
#endif                                                             //~va20I~
        {                                                          //~v74YI~
            contlen--;	//override previous end space              //~v74YI~
            len+=swinsertsosi;                                     //~va8kI~
            memcpy(pcontdata+contlen,pdata,(UINT)len);                   //~v74YR~
            memcpy(pcontdbcs+contlen,pdbcs,(UINT)len);                   //~v74YR~
            len-=swinsertsosi;                                     //~va8kI~
            linefilledsw&=~0x02;	//retry shifted split dbcs     //~v74YI~
        }                                                          //~v74YI~
	    if (!(Popt & FCSPL_SBCS))                                  //~v74WR~
        {                                                          //~va8kI~
//    	  if (!swebcfileconcatdbcs)                                //~va8wI~//~v@@@R~
//        {                                                        //~va8wI~//~v@@@R~
            optobdbcs=Sswebcfile|XESUBSDSO_NOSBCSIFEBC;   //no SBCS option for EBC file//~va8jI~//~va8kR~
//	    	if (!(Popt & FCSPL_TFLOW))                             //~v@@@R~
//          	optobdbcs|=XESUBSDSO_HALFCUTONLY;  //rep half cut only//~v@@@R~
            if (swheadconcat)                                      //~v@@@R~
            	optobdbcs|=XESUBSDSO_HALFCUTONLYL; //rep half cut only//~v@@@I~
            if (swendconcat||(cutflag & FCEBCCF_APPENDSI))   //concat dbcs at right boundary or short source end by dbcs2nd//~v@@@R~
            	optobdbcs|=XESUBSDSO_HALFCUTONLYR; //rep half cut only//~v@@@I~
        	dbcsspliterr|=                                          //~v74WI~//~v@@@R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~//~va5qM~
//	    	xesub_setdbcssplit(Sswebcfile,0/*plh*/,pcontdata+contlen,pcontdbcs+contlen,len,' ');//~va5qI~//~va8kR~
  	    	xesub_setdbcssplit(optobdbcs,0/*plh*/,pcontdata+contlen,pcontdbcs+contlen,len+swinsertsosi,' ');//~va8kR~
#else                                                              //~va5qI~
	    	setdbcssplit(pcontdata+contlen,pcontdbcs+contlen,len,' ');//~v74WR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5qM~
//        }                                                        //~va8wI~//~v@@@R~
        }                                                          //~va8kI~
        srcoffs+=len;                                              //~v74WI~
      	srcoffs+=swdropso+swdropendsi;//swebcfileconcatdbcs;                              //~va8wI~//~v@@@R~
//      if (swinsertsosi && srcoffs)                               //~va8kR~//~v@@@R~
        if (Sswebcfile                                             //~v@@@R~
        &&  srcoffs                                                //~v@@@I~
        &&  srcoffs<pspw->SPWlen                                   //~v@@@I~
        &&  *(pspw->SPWdatadbcs+pspw->SPWlen+srcoffs)==UDBCSCHK_DBCS1ST//~v@@@R~
        )                                                          //~v@@@I~
        {                                                          //~va8kI~
        	srcoffs--;                                             //~va8kI~
            *(pspw->SPWdatadbcs+srcoffs)=CHAR_SO;                  //~va8kI~
            *(pspw->SPWdatadbcs+pspw->SPWlen+srcoffs)=0;           //~va8kI~
        }                                                          //~va8kI~
        if (srcoffs==pspw->SPWlen)                                 //~v74WR~
        {                                                          //~v74WI~
	        pspw=UDEQ(UQUE_TOP,Ppqhbnds,0);                        //~v74WI~
    	    ufree(pspw);                                           //~v74WI~
            srcoffs=0;  //offset 0 of next top                     //~v74WI~
        }                                                          //~v74WI~
        contlen+=len;                                              //~v74WI~
        contlen+=swinsertsosi;                                     //~va8kI~
      }//! force new paragraph                                     //~v758I~
  		if ((Popt & FCSPL_TFLOW) && linefilledsw)                  //~v751R~
        {                                                          //~v751I~
        	if (contlen<tgtwidth)                                  //~v751I~
            {                                                      //~v751I~
            	len=tgtwidth-contlen;                              //~v751I~
#ifdef UTF8UCS2                                                    //~va50I~
	            memset(pcontdata+contlen,Schspace,(UINT)len);      //~va50I~
#else                                                              //~va50I~
	            memset(pcontdata+contlen,' ',(UINT)len);                 //~v751I~
#endif                                                             //~va50I~
    	        memset(pcontdbcs+contlen,0,(UINT)len);                   //~v751I~
                contlen+=len;                                      //~v751I~
                if (Sswebcfile)                                    //~v@@@I~
                    if (len>0  		//padlen                       //~v@@@I~
				  	&&  (Sotheropt & SOTHO_ORB1ST)	//rb is dbcs1st//~v@@@I~
                    )                                              //~v@@@I~
                		*(pcontdata+contlen-1)=CHAR_SO;            //~v@@@R~
            }                                                      //~v751I~
        }                                                          //~v751I~
        if (linefilledsw & 0x03)	//delm found or propagate last dbcs split to next line//~v74WR~
        	break;                                                 //~v74WI~
        if (contlen>=tgtwidth)  //">" is the case of long data     //~v751R~
        	break;                                                 //~v74WI~
    }                                                              //~v74WI~
    if (pspwsplit)                                                 //~va8vI~
	    UENQ(UQUE_TOP,Ppqhbnds,pspwsplit);	//split cmd joind split//~va8vI~
    *Pperrctr=errctr;                                              //~v74WI~
    *Ppsrclen=contlen;                                             //~v74WI~
    *Ppsrcoffs=srcoffs;                                            //~v74WI~
    if (!rc && delmnotfoundsw)                                     //~v74WI~
    	rc=1;                                                      //~v74WI~
    if (dbcsspliterr)                                              //~v74WI~
		rc|=FCSPLRC_DBCSSPLIT;     //rc for bndsgetsrc             //~v74WI~
    return rc;                                                     //~v74WI~
}//fcmdsplitbndsgetsrc                                             //~v74WI~
//**************************************************************** //~va8vI~
//*fcmdsplitbndsjoinedsplit                                        //~va8wI~
//*add pspw for split by delm for bnds joind line                  //~va8wI~
//**************************************************************** //~va8vI~
PSPLITWK fcmdsplitbndsjoinedsplit(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,//~va8vI~
					int Pdatalen,int Psplitlen)                    //~va8vI~
{                                                                  //~va8vI~
	int len,len2,swinsertso;                                     //~va8vI~//~v@@@R~
    UCHAR *pdata,*pdbcs;                                           //~va8vI~
    PSPLITWK pspw;                                                 //~va8vI~
//**************************                                       //~va8vI~
	len=Pdatalen-Psplitlen;                           //~va8vI~    //~v@@@R~
	swinsertso=Sswebcfile && len>0 && *(Ppdbcs+Psplitlen)==UDBCSCHK_DBCS1ST;//~v@@@R~
    len+=swinsertso;                                               //~v@@@I~
    len2=SPLITWKSZ+len+len; //data & dbcs and boundary so/si       //~va8vI~
    pspw=(PSPLITWK)umalloc((UINT)len2);                            //~va8vI~
    if (!pspw)                                                     //~va8vI~
    	return 0;                                                  //~va8vI~
    memset(pspw,0,SPLITWKSZ);                                      //~va8vI~
    pspw->SPWlen=len;                                              //~va8vI~
    pdata=pspw->SPWdatadbcs;                                       //~va8vI~
    pdbcs=pdata+len;                                               //~va8vI~
    if (swinsertso)                                              //~va8vI~//~v@@@R~
    	*pdata++=CHAR_SO,*pdbcs++=0;                               //~va8vR~
    len-=swinsertso;                                               //~v@@@I~
    memcpy(pdata,Ppdata+Psplitlen,(UINT)len);                      //~va8vI~//~v@@@R~
    memcpy(pdbcs,Ppdbcs+Psplitlen,(UINT)len);                      //~va8vI~
    return pspw;                                                   //~va8vI~
}//fcmdsplitbndsjoinedsplit                                        //~va8vI~
//**************************************************************** //~v74WM~
// fcmdsplitlenbnds                                                //~v74WM~
//*search delm in the range of min(width,datalen)                  //~v74WM~
//*return:rc:0: datalen<width                                      //~v751R~
//*          1: delm found,2:dbcs split shifted(line change),4:delm not found//~v751I~
//**************************************************************** //~v74WM~
int fcmdsplitlenbnds(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,UCHAR *Ppdelmstr,//~v74WM~
					int Pdatalen,int Pwidth,int *Ppsplitlen)       //~v74WM~
{                                                                  //~v74WM~
	int rc=0,rc2,newlen,width;                                     //~v74WI~
    int linefilledsw=0/*,rc3,tflen*/;                                //~v75eR~//~vaf8R~
    int swsplitbndsshort=0;                                        //~va8rI~
    int swtflowsplit=0;                                            //~v@@@I~
//**************************                                       //~v74WM~
	Sotheropt&=~SOTHO_APPENDSO;    //append SO for split ebc dbcs string//~va8kI~
	Sotheropt&=~SOTHO_SPLITBNDSSHORT;   //append SO for split ebc dbcs string//~va8vI~
  	if (Popt & FCSPL_TFLOW)                                        //~v75eI~
    {                                                              //~v75eI~
      if (Pdatalen<=0)                                             //~v75LI~
      {                                                            //~v75LI~
        rc2=0;                                                     //~v75LI~
        newlen=Pdatalen;                                           //~v75LI~
      }                                                            //~v75LI~
      else                                                         //~v75LI~
      {                                                            //~va8kI~
//        Sotheropt|=SOTHO_EBCMIN0TOL;    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~
//      rc2=fcmdtflowsplitlen(Popt,Ppdata,Ppdbcs,Ppdelmstr,Pdatalen,Pwidth,&newlen,&linefilledsw);//~v75eR~//~v@@@R~
        rc2=fcmdtflowsplitlen(Popt|FCSPL_SPLITBNDS,Ppdata,Ppdbcs,Ppdelmstr,Pdatalen,Pwidth,&newlen,&linefilledsw);//~v@@@I~
//        Sotheropt&=~SOTHO_EBCMIN0TOL;    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~
      }                                                            //~va8kI~
        if (rc2==1) //could not split                              //~v75eI~
        {                                                          //~v@@@I~
          if (Sswebcfile && !(Popt & FCSPL_TFJOIN))    //ebc long line at contlen>indentoffs//~v@@@R~
          	swtflowsplit=1;                                        //~v@@@I~
          else                                                     //~v@@@I~
        	rc=4;   //delm not found                               //~v75eI~
        }                                                          //~v@@@I~
        else                                                       //~v75eI~
    	    if (linefilledsw)	//delm found or split by space(after/berfore)//~v75eI~
        		rc=1;                                              //~v75eI~
        	else                                                   //~v75eI~
	        	rc=0;                                              //~v75eR~
      if (!swtflowsplit)                                           //~v@@@I~
      {                                                            //~v@@@I~
    	if (rc2==2)	//dbcs shifted to next line                    //~v75eI~
        	rc|=2;                                                 //~v75eI~
	    *Ppsplitlen=newlen;                                        //~v75eI~
    	return rc;                                                 //~v75eI~
      }                                                            //~v@@@I~
    }                                                              //~v75eI~
    if (Popt & FCSPL_ALLWIDTH0) 	//Pwidth is MAXLINEDATA for contwk//~v74WI~
        width=0;    //no right bnds set                            //~v74WI~
    else                                                           //~v74WI~
    {                                                              //~v76LI~
    	if (Popt & FCSPL_NOWIDTH) 	//Pwidth is by margin or bnds  //~v76LI~
            Popt|=(FCSPL_ALLWIDTH0|FCSPL_SPLITBNDS);               //~v76LR~
        else                                                       //~va8wR~//~v@@@R~
        {                                                          //~va8vI~//~va8wR~//~v@@@R~
//        if (Pdatalen<=Pwidth) 	//split & bnds & width parn & short rec//~va8rI~//~v@@@R~
          if (Pdatalen<Pwidth) 	//split & bnds & width parn & short rec,for eq case recalled for from contdata top//~v@@@I~
          {                                                        //~va8vI~
		   if (!(Sotheropt & SOTHO_SPLITJOINED))                   //~va8vI~
          	swsplitbndsshort=1;                                    //~va8rI~
          }                                                        //~va8vI~
//        else                                                     //~va8rR~
//          Sotheropt &= ~SOTHO_JOIN;		//SPLlit cmd search up to width if width!=0//~va8rR~
        }                                                          //~va8vI~//~va8wR~//~v@@@R~
        width=Pwidth;                                              //~v74WI~
    }                                                              //~v76LI~
  if (swsplitbndsshort)                                            //~va8rI~
  {                                                                //~va8rI~
    rc2=fcmdsplitlen(Popt,Ppdata,Ppdbcs,0/*delmstr*/,Pdatalen,width,&newlen); //chk ebc expand//~va8rI~
	Sotheropt|=SOTHO_SPLITBNDSSHORT;   //append SO for split ebc dbcs string//~va8vI~
  }                                                                //~va8rI~
  else                                                             //~va8rI~
  {                                                                //~va8rI~
//    Sotheropt|=SOTHO_EBCMIN0TOL;    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~
    if (Sotheropt & SOTHO_ORB1ST)                                  //~v@@@I~
        Sotheropt|=SOTHO_IRB2NDOK;                                 //~v@@@I~
    rc2=fcmdsplitlen(Popt,Ppdata,Ppdbcs,Ppdelmstr,Pdatalen,width,&newlen);//~v751R~
    Sotheropt&=~SOTHO_IRB2NDOK;                                    //~v@@@I~
//    Sotheropt&=~SOTHO_EBCMIN0TOL;    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~
//  if (Pdatalen>width && Ppdelmstr)                               //~v751R~
    if (Ppdelmstr)  //rc2 has meaning                              //~v751I~
    {                                                              //~v74WI~
        if (!rc2)		//delm found                               //~v74WI~
        	rc=1;                                                  //~v74WI~
        else                                                       //~v74WI~
        if (rc2==1)                                                //~v74WI~
        	rc=4;                                                  //~v74WI~
        else                                                       //~va8rI~
        if (rc2==4)                                                //~va8rI~
        	rc=4;                                                  //~va8rI~
    }                                                              //~v74WI~
    else                                                           //~va8rI~
        if (rc2==4)                                                //~va8rI~
        	rc=4;                                                  //~va8rR~
  }                                                                //~va8rI~
    if (swtflowsplit)                                              //~v@@@I~
        rc|=2|FCSPLRC_TFEBCSPLIT; //0x0400         //tflow split long for ebcfile//~v@@@R~
    else                                                           //~v@@@I~
    if (rc2==2)	//dbcs shifted to next line                        //~v74WI~
        rc|=2;                                                     //~v74WI~
    *Ppsplitlen=newlen;                                            //~v74WM~
    return rc;                                                     //~v74WM~
}//fcmdsplitlenbnds                                                //~v74WM~
//**************************************************************** //~v74WI~
// fcmdsplitbndsgetsrcplh                                          //~v751R~
//*gather data in margin by bnds/margin setting                    //~v74WI~
//*return:UALLOC_FAILED                                            //~v758R~
//**************************************************************** //~v74WI~
int fcmdsplitbndsgetsrcplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Pplh2,//~v758R~
							int Pwidth,int Pbndsoffs1,int Pbndsoffs2,int *Ppplhctrr,UQUEH *Ppqhbnds,int *Pperrctr)//~v751R~
{                                                                  //~v74WI~
	int plhctrr,len,len2,ulhlen,rc;                                //~v74WR~
    int delctr;                                                    //~v74YI~
    PULINEH plh;                                                   //~v74WI~
    PULINEH plho;                                                  //~v@@@I~
    PSPLITWK pspw;                                                 //~v74WI~
    UCHAR *pdata,*pdbcs;                                           //~v74WI~
    UCHAR *pc,*pcd;                                                //~va8kI~
    int headcnt,netlen/*,shiftcnt*/;                               //~v75iR~
    int /*rcparag,*/flag;                                          //~v75iR~
#ifdef UTF8SUPPH                                                   //~va17I~
    int dbcsspliterr=0;                                            //~va17R~
#endif                                                             //~va17I~
    int optobdbcs,addlen,swsetso,swsetsi;                          //~va8kR~
    int dbcsspliterrR;                                             //~va8wI~
    int optdbcs2=0;                                                  //~v@@@I~//~vaf9R~
//************************                                         //~v74WI~
    if (Ppplhctrr)		//need output                              //~v74WI~
	    plhctrr=*Ppplhctrr;                                        //~v74WI~
    else                                                           //~v74WI~
    	plhctrr=0;                                                 //~v74WI~
    for (plh=*Ppplh;plh && plh!=Pplh2;plh=UGETQNEXT(plh),plhctrr++)//~v74WR~
    {                                                              //~v74WI~
        if (plh->ULHtype!=ULHTDATA)                                //~v74WI~
        	continue;                                              //~v74WI~
        if (plh->ULHupctr>Soldupctr)  //updated(data saved)        //~v758R~
            continue;                                              //~v751I~
        if (!plh->ULHdbcs)  //not once displayed                   //~v74WI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v74WI~
                return rc;                                         //~v74WI~
        ulhlen=plh->ULHlen;                                        //~v74WI~
        if (ulhlen<=Pbndsoffs1)  //margin data exist               //~v74WI~
            len=0;                                                 //~v75jI~
        else                                                       //~v75jI~
        if (Pbndsoffs2)	//right boundary specified                 //~v74WR~
        {                                                          //~v74WI~
            if (ulhlen>=Pbndsoffs2)  //oom exist                   //~v75mR~
                len=Pbndsoffs2-Pbndsoffs1;                         //~v74WR~
            else                                                   //~v74WR~
                len=ulhlen-Pbndsoffs1;                             //~v74WR~
        }                                                          //~v74WI~
        else                                                       //~v74WI~
           len=ulhlen-Pbndsoffs1;                                  //~v74WI~
		flag=0;                                                    //~v758I~
        pc=plh->ULHdata+Pbndsoffs1;                                //~va8sI~
        pcd=plh->ULHdbcs+Pbndsoffs1;                               //~va8sI~
        if (!(Popt & FCSPL_SBCS))                                  //~va8sI~
        {                                                          //~va8sI~
            optobdbcs=Sswebcfile|XESUBSDSO_NOSBCSIFEBC|XESUBSDSO_GETSPLITCTR;//~va8sI~
            optdbcs2=0;                                            //~v@@@I~
        	if (ulhlen>=Pbndsoffs1 && Pbndsoffs1>0)  //margin data exist//~v@@@I~
            	if (*(pcd-1)==UDBCSCHK_DBCS2ND)                    //~v@@@I~
					optdbcs2|=XESUBSDSO_PREV2ND;                   //~v@@@R~
            if (ulhlen>Pbndsoffs2)  //oom exist                    //~v@@@I~
            	if (*(pcd+len)==UDBCSCHK_DBCS1ST)                  //~v@@@I~
					optdbcs2|=XESUBSDSO_NEXT1ST;                   //~v@@@R~
//	    	if (!(Popt & FCSPL_TFLOW))                             //~va8wI~//~v@@@R~
            	optobdbcs|=XESUBSDSO_HALFCUTONLY;  //rep half cut only//~va8wI~//~v@@@R~
            optobdbcs|=optdbcs2;                                   //~v@@@R~
//          dbcsspliterr=xesub_setdbcssplit(optobdbcs,0/*plh*/,pc,pcd,len,' ');//~va8sR~//~va8wR~
            dbcsspliterr=xesub_setdbcssplitib(optobdbcs,0/*plh*/,pc-Pbndsoffs1,pcd-Pbndsoffs1,len+Pbndsoffs1,Pbndsoffs1,' ');//~va8wI~//~v@@@R~
        }                                                          //~va8sI~
  	    if (Popt & FCSPL_TFLOW)                                    //~v751I~
        {                                                          //~v751R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,plh->ULHdata+Pbndsoffs1,plh->ULHdbcs+Pbndsoffs1,len);//~va50I~//~va8sR~
        	headcnt=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pc+dbcsspliterr,pcd+dbcsspliterr,len-dbcsspliterr)+dbcsspliterr;//~va8sR~
    #else                                                          //~va50I~
        	headcnt=(int)UTF_umemspnc(Sswutf8file,plh->ULHdata+Pbndsoffs1,plh->ULHdbcs+Pbndsoffs1,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	headcnt=(int)umemspnc(plh->ULHdata+Pbndsoffs1,' ',(UINT)len);     //~v75iM~
#endif                                                             //~va20I~
		    netlen=len-headcnt;                                    //~v75iM~
            if (netlen)                                            //~v75iI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  		    netlen-=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,plh->ULHdata+Pbndsoffs1,plh->ULHdbcs+Pbndsoffs1,len);//~va50I~//~va8sR~
    		    netlen-=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,pc+headcnt,pcd+headcnt,netlen);//~va8sI~
    #else                                                          //~va50I~
			    netlen-=(int)UTF_umemrspnc(Sswutf8file,plh->ULHdata+Pbndsoffs1,plh->ULHdbcs+Pbndsoffs1,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
			    netlen-=(int)umemrspnc(plh->ULHdata+Pbndsoffs1,' ',(UINT)len);//~v75iI~
#endif                                                             //~va20I~
            len=netlen;                                            //~v751I~
        }                                                          //~v751I~
        else                                                       //~v751I~
        	headcnt=0;                                             //~v751I~
//      len2=SPLITWKSZ+len+len;   //data & dbcs                    //~v74WI~//~va8kR~
        len2=SPLITWKSZ+len+len+4; //data & dbcs and boundary so/si //~va8kI~
        pspw=(PSPLITWK)umalloc((UINT)len2);                              //~v74WI~
        memset(pspw,0,SPLITWKSZ);                                  //~v74WI~
      	if (!(Popt & FCSPL_SBCS))                                  //~v@@@I~
        {                                                          //~v@@@I~
        	if (dbcsspliterr)                                      //~v@@@I~
	        	flag|=SPWF_DBCSSPLITL;                             //~v@@@I~
        }                                                          //~v@@@I~
      if (Sswebcfile && !(Popt & FCSPL_SBCS))                      //~va8kR~
      {                                                            //~va8kI~
//      if (dbcsspliterr)                                          //~va8wI~//~v@@@R~
//          flag|=SPWF_DBCSSPLITL;                                 //~va8wR~//~v@@@R~
        pc=plh->ULHdata+Pbndsoffs1+headcnt;                        //~va8kI~
        pcd=plh->ULHdbcs+Pbndsoffs1+headcnt;                       //~va8kI~
        swsetso=(len>=2 && *pcd==UDBCSCHK_DBCS1ST);                //~va8kI~
        swsetsi=(len>=2 && *(pcd+len-1)==UDBCSCHK_DBCS2ND);        //~va8kI~
        addlen=swsetso+swsetsi;                                    //~va8kI~
        pdata=pspw->SPWdatadbcs;                                   //~va8kI~
        pdbcs=pspw->SPWdatadbcs+len+addlen;                        //~va8kI~
        if (swsetso)                                               //~va8kI~
        {                                                          //~va8wI~
        	*pdata=CHAR_SO,*pdbcs=0;                               //~va8kI~
            flag|=SPWF_SETSO;                                      //~va8wI~
        }                                                          //~va8wI~
        memcpy(pdata+swsetso,pc,(UINT)len);                        //~va8kI~
        memcpy(pdbcs+swsetso,pcd,(UINT)len);                       //~va8kI~
        if (swsetsi)                                               //~va8kI~
        {                                                          //~va8wI~
        	*(pdata+swsetso+len)=CHAR_SI,*(pdbcs+swsetso+len)=0;   //~va8kI~
            flag|=SPWF_SETSI;                                      //~va8wI~
        }                                                          //~va8wI~
        len+=addlen;                                               //~va8kI~
      }                                                            //~va8kI~
      else                                                         //~va8kI~
      {                                                            //~va8kI~
        pdata=pspw->SPWdatadbcs;                                   //~v74WI~
        pdbcs=pspw->SPWdatadbcs+len;                               //~v74WI~
//      memcpy(pdata,plh->ULHdata+Pbndsoffs1,len);                 //~v751R~
//      memcpy(pdbcs,plh->ULHdbcs+Pbndsoffs1,len);                 //~v751R~
        memcpy(pdata,plh->ULHdata+Pbndsoffs1+headcnt,(UINT)len);         //~v751I~
        memcpy(pdbcs,plh->ULHdbcs+Pbndsoffs1+headcnt,(UINT)len);         //~v751I~
      }                                                            //~va8kI~
        if (Popt & FCSPL_SPACE1)                                   //~v74YI~
        {                                                          //~v74YI~
        	fcmdsplitspace1data(pdata,pdbcs,len,&delctr);          //~v74YR~
            if (delctr)                                            //~v74YI~
            {                                                      //~v74YI~
            	len-=delctr;                                       //~v74YI~
            	memcpy(pdbcs-delctr,pdbcs,(UINT)len);	//shift for SPWlen point dbcs//~v74YI~
                pdbcs-=delctr;	//required for setdbcssplit        //~va8rI~
            }                                                      //~v74YI~
      	}                                                          //~v74YI~
//      pspw->SPWlen=len;                                          //~v74YM~//~v@@@R~
        if (!(Popt & FCSPL_SBCS))                                  //~v74WI~
        {                                                          //~v74WI~
//#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~//~va8sR~
//            if (UDBCSCHK_DBCSNOT1ST(*pdbcs)             //pad or 2nd//~vva1cI~//~va1cR~//~va8sR~
//            ||  UDBCSCHK_DBCSNOTEND(*(pdbcs+len-1))     //1st or pad//~vva1cI~//~va1cR~//~va8sR~
//            )                                                      //~vva1cI~//~va1cR~//~va8sR~
//                dbcsspliterr=1;                                    //~va17I~//~va8sR~
//#else                                                              //~vva1cI~//~va1cR~//~va8sR~
//            if (*pdbcs==DBCS2NDCHAR || (*(pdbcs+len-1)==DBCS1STCHAR))//~v75fR~//~va8sR~
//                fcmdsettemperr(0,plh);                             //~v75fI~//~va8sR~
//#endif                                                             //~va17M~//~va8sR~
//        if (dbcsspliterr)                                        //~va8sR~//~va8wR~
//        {                                                        //~va8sI~//~va8wR~
            optobdbcs=Sswebcfile|XESUBSDSO_NOSBCSIFEBC;   //no SBCS option for EBC file//~va8kR~
            optobdbcs|=optdbcs2;                                   //~v@@@R~
//	    	if (!(Popt & FCSPL_TFLOW))                             //~va8wI~//~v@@@R~
//          	optobdbcs|=XEEBCSDSO_HALFCUTONLY;  //rep half cut only//~va8wI~//~v@@@R~
            dbcsspliterrR=                                         //~va8wR~
  	    	xesub_setdbcssplit(optobdbcs,0/*plh*/,pdata,pdbcs,len,' ');//~va8kR~
            if (dbcsspliterrR)                                     //~va8wR~
            {                                                      //~va8wI~
	        	flag|=SPWF_DBCSSPLITR;  //getsrcplh inserted SI at right boundary//~va8wR~
            	dbcsspliterr|=dbcsspliterrR;                       //~va8wR~
  	    		if (Sswebcfile && !(Popt & FCSPL_TFLOW))	//SPLit cmd,//~v@@@R~
                {                                                  //~v@@@I~
                	if (dbcsspliterrR & XEEBCSDSRC_REPSO)   //     //~v@@@R~
                    {                                              //~v@@@I~
//                  	memmove(pdbcs+2,pdbcs,len);                //~v@@@I~//~vb2DR~
                    	memmove(pdbcs+2,pdbcs,(size_t)len);        //~vb2DI~
//                  	memmove(pdata+1,pdata,len);                //~v@@@I~//~vb2DR~
                    	memmove(pdata+1,pdata,(size_t)len);        //~vb2DI~
//                      *pdata=Schspace;                           //~v@@@R~//~vb2CR~
                        *pdata=(UCHAR)Schspace;                    //~vb2CI~
                        pdbcs++;                                   //~v@@@I~
                        *pdbcs=0;                                  //~v@@@R~
                        len++;                                     //~v@@@I~
                    }                                              //~v@@@I~
                	if (dbcsspliterrR & XEEBCSDSRC_REPSI)   //     //~v@@@R~
                    {                                              //~v@@@I~
//                  	memmove(pdbcs+1,pdbcs,len);                //~v@@@I~//~vb2DR~
                    	memmove(pdbcs+1,pdbcs,(size_t)len);        //~vb2DI~
                        pdbcs++;                                   //~v@@@I~
//                      *(pdata+len)=Schspace;                     //~v@@@R~//~vb2CR~
                        *(pdata+len)=(UCHAR)Schspace;              //~vb2CI~
                        *(pdbcs+len)=0;                            //~v@@@R~
                        len++;                                     //~v@@@I~
                    }                                              //~v@@@I~
                }                                                  //~v@@@I~
            }                                                      //~va8wI~
//        }                                                        //~va8sI~//~va8wR~
        }                                                          //~v74WI~
        pspw->SPWlen=len;                                          //~v@@@I~
        pspw->SPWflag=flag;                                        //~v74WM~
        pspw->SPWheadcnt=headcnt;                                  //~v75iI~
        chartabclear(pdbcs,len);                                   //~v74WI~
        UENQ(UQUE_END,Ppqhbnds,pspw);                              //~v74WR~
        break;                                                     //~v74WI~
    }                                                              //~v74WI~
    plho=plh;                                                      //~v@@@I~
    if(plh && plh!=Pplh2)                                          //~v751R~
    {                                                              //~v74WI~
    	plh=UGETQNEXT(plh);	//read next                            //~v74WI~
        plhctrr++;                                                 //~v74WR~
    }                                                              //~v74WI~
    *Ppplh=plh;                                                    //~v74WI~
    if (Ppplhctrr)                                                 //~v74WM~
	    *Ppplhctrr=plhctrr;                                        //~v74WM~
#ifdef UTF8SUPPH                                                   //~va1qR~
    rc=0;                                                          //~va8wI~
    if (dbcsspliterr)                                              //~va17R~
    {                                                              //~v@@@I~
    	if (plho)                                                  //~v@@@I~
	    	fcmdsettemperr(Popt,plho);                             //~v@@@I~
		rc=FCSPLRC_DBCSSPLIT;     //rc for bndsgetsrc              //~va17I~
    }                                                              //~v@@@I~
#endif                                                             //~va1qI~
    return rc;                                                     //~v74WR~//~va8wR~
}//fcmdsplitbndsgetsrcplh                                          //~va8kR~
//**************************************************************** //~v74WI~
// fcmdsplitbydelmbndsgather                                       //~v74WI~
//*gather daat in margin by bnds/margin setting                    //~v74WI~
//*return:rc:UALLOC_FAILED                                         //~v75nR~
//**************************************************************** //~v74WI~
int fcmdsplitbndsupdate(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,     //~v74WR~
						PULINEH Pplh,int Pwidth,int Pbndsoffs1,int Pbndsoffs2,//~v74WI~
                        char *Pcontwk,int Pcontwkwidth,int Psrclen)//~v751R~
{                                                                  //~v74WI~
    int   newlen,len,ulhlen,rlen;                                  //~v75nR~
    UCHAR *pdata,*pdbcs,*plhdata,*plhdbcs;                         //~v74WR~
    UCHAR *pc,*pcd;                                                //~va8wI~
    int optobdbcs;                                                 //~va8kI~
    int /*swconcatdbcsL,swconcatdbcsR,*/srclen;                        //~va8wR~//~v@@@R~
//*********************************                                //~v74WI~
    ulhlen=Pplh->ULHlen;                                           //~v75nM~
    pdata=Pcontwk;                                                 //~v74WI~
    pdbcs=Pcontwk+Pcontwkwidth;                                    //~v751R~
//*ebc_setdbcstbl later                                            //~va50I~
    if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v74WI~
        return UALLOC_FAILED;                                      //~v74WI~
    newlen=ulhlen;                                                 //~v74WI~
	if (Pbndsoffs2)                                                //~v74WI~
    {                                                              //~v74WI~
    	if (ulhlen<Pbndsoffs2)                                     //~v74WI~
        	newlen=Pbndsoffs1+Psrclen;                             //~v74WI~
    }                                                              //~v74WI~
    else                                                           //~v74WI~
    {                                                              //~v74WI~
        newlen=Pbndsoffs1+Psrclen;                                 //~v74WI~
    }                                                              //~v74WI~
    if (ulhlen<newlen)                                             //~v74WR~
    {                                                              //~v74WI~
    	if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)      //expand buff//~v74WI~
        	return UALLOC_FAILED;                                  //~v74WI~
    }                                                              //~v74WI~
    plhdata=Pplh->ULHdata;                                         //~v74WR~
    plhdbcs=Pplh->ULHdbcs;                                         //~v74WR~
    newlen=ulhlen;                                                 //~v74WI~
    if (ulhlen<Pbndsoffs1)                                         //~v74WI~
    {                                                              //~v74WI~
    	if (Psrclen)                                               //~v74WI~
        {                                                          //~v74WI~
        	len=Pbndsoffs1-ulhlen;                                 //~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	memset(plhdata+ulhlen,Schspace,(UINT)len);             //~va50I~
#else                                                              //~va50I~
        	memset(plhdata+ulhlen,' ',(UINT)len);                        //~v74WI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
       		memset(plhdbcs+ulhlen,0,(UINT)len);                          //~v74WI~
            newlen=Pbndsoffs1;                                     //~v74WI~
        }                                                          //~v74WI~
//  	swconcatdbcsL=0;                                           //~va8wR~//~v@@@R~
    }                                                              //~v74WI~
    else                                                           //~v74WI~
    {                                                              //~va8wI~
    	newlen=Pbndsoffs1;                                         //~v74WI~
//  	swconcatdbcsL=(Sotheropt & SOTHO_BNDSCONTSETSO)  //bnds contdata top is dbcs split data//~va8wR~//~v@@@R~
//      			&& fcmdebcchkdbcsconcatbndsupdateL(Popt,plhdata,plhdbcs,Pbndsoffs1,pdata,pdbcs,Psrclen);//~v@@@I~
    }                                                              //~va8wI~
//  	swconcatdbcsR=(Pbndsoffs2 && ulhlen>Pbndsoffs2)  //oom exist//~va8wI~//~v@@@R~
//  				&& fcmdebcchkdbcsconcatbndsupdateR(Popt,pdata,pdbcs,Psrclen,Pbndsoffs2-Pbndsoffs1+swconcatdbcsL,plhdata+Pbndsoffs2,plhdbcs+Pbndsoffs2,ulhlen-Pbndsoffs2);//~va8wI~//~v@@@R~
//  srclen=Psrclen-swconcatdbcsL-swconcatdbcsR;                    //~va8wI~//~v@@@R~
    srclen=Psrclen;                                                //~v@@@I~
    pc=pdata;                                                      //~va8wI~
    pcd=pdbcs;                                                     //~va8wI~
//  if (swconcatdbcsL)                                             //~va8wR~//~v@@@R~
//      pc++,pcd++;                                                //~va8wI~//~v@@@R~
//      memcpy(plhdata+Pbndsoffs1,pdata,(UINT)Psrclen);                  //~v74WR~//~va8wR~
//      memcpy(plhdbcs+Pbndsoffs1,pdbcs,(UINT)Psrclen);                  //~v74WR~//~va8wR~
//      newlen=Pbndsoffs1+Psrclen;                                 //~v74WI~//~va8wR~
    memcpy(plhdata+Pbndsoffs1,pc,(UINT)srclen);                    //~va8wI~
    memcpy(plhdbcs+Pbndsoffs1,pcd,(UINT)srclen);                   //~va8wI~
    newlen=Pbndsoffs1+srclen;                                      //~va8wI~
                                                                   //~va8wI~
    if (Pbndsoffs2 && ulhlen>Pbndsoffs2)  //oom exist              //~v75nR~
    {                                                              //~v74WI~
	    newlen=ulhlen;                                             //~v74WI~
    }                                                              //~v74WI~
	Pplh->ULHlen=newlen;                                           //~v74WI~
    if (ulhlen>Pbndsoffs1)  //replaced                             //~v74WI~
    {                                                              //~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (Sswebcfile)                                              //~va50I~
      {                                                            //~va50I~
       if (!(Popt & FCSPL_SBCS))                                   //~va8kI~
       {                                                           //~va8kI~
        	if (Pbndsoffs2)                                        //~va8kI~
	        	rlen=min(newlen,Pbndsoffs2)-Pbndsoffs1;            //~va8kI~
            else                                                   //~va8kI~
	        	rlen=newlen-Pbndsoffs1;                            //~va8kI~
            optobdbcs=Sswebcfile|SOTDO_NOSBCSIFEBC;   //no SBCS option for EBC file//~va8kM~
//	    	if (!(Popt & FCSPL_TFLOW))	//SPLit cmd,               //~v@@@R~
            	optobdbcs|=SOTDO_NOSOSIDBCSCONCAT;   //allow DBCS string concatination w/o SOSI//~v@@@I~
        	setobtabdbcs(optobdbcs,0/*plh*/,plhdata,plhdbcs,newlen,Pbndsoffs1,rlen);//!ebc//~va8kM~
       }                                                           //~va8kI~
       else                                                        //~va8kI~
		xeebc_setdbcstblplh(0,Ppfh,Pplh,0/*ULHlen*/);              //~va50R~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      {                                                            //~va50I~
        if (!(Popt & FCSPL_SBCS))                                  //~v74WR~
        {                                                          //~v74WI~
        	if (Pbndsoffs2)                                        //~v74WR~
	        	rlen=min(newlen,Pbndsoffs2)-Pbndsoffs1;            //~v74WR~
            else                                                   //~v74WI~
	        	rlen=newlen-Pbndsoffs1;                            //~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5qI~
        	setobtabdbcs(0,0,plhdata,plhdbcs,newlen,Pbndsoffs1,rlen);//!ebc//~va5qI~
#else                                                              //~va5qI~
        	setobtabdbcs(plhdata,plhdbcs,newlen,Pbndsoffs1,rlen);  //~v74WR~
#endif //UTF8EBCD raw ebcdic file support                          //~va5qI~
        }                                                          //~v74WI~
        else                                                       //~v74WI~
//**SBCS option is rejected when utf8file                          //~va20I~
			filesetdbcstbl(plhdata,plhdbcs,newlen,FSDT_TABSAVE);   //~v74WR~
      }                                                            //~va50I~
    }                                                              //~v74WI~
    return 0;                                                      //~v74WI~
}//fcmdsplitbndsupdate                                             //~va50R~
#endif                                                             //~v50JI~
