//*CID://+vb30R~:                             update#=  413;       //+vb30R~
//*************************************************************
//*xefcmd4.c*
//**file cmd:SORT,COL,SPLIT,JOIN                                   //~v47iR~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va8i:101011 bnds sort;add SBCS option for BNDS sort without dbcs consideration(err for utf8 file)//~va8iI~
//va8h:101010 bnds sort;set space to split dbcs except dbcs continued case//~va8hI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3P:100320 utf8 file sort dbcs split option;D[S|I|X] space/include/exclude//~va3PI~
//va3N:100320 (BUG)sort of utf8 file;invalid sort when nocase option//~va3NI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd4.c :memcmp for dd fmt                           //~va20I~
//va0p:090906 notfoundmsg+geterrmsg->nomsg for filefind of colsalloc to avoid prev msg disappear//~va0pI~
//v78r:080326*profile function                                     //~v78rI~
//v75F:070508 (BUG of v61a)cols type is reset to default after S+F11 twice(off+on)//~v75FI~
//            force to default only when operand specified(not toggle case)//~v75FI~
//v75C:070501 JOIN:drop trailer space of 2nd line if FIXED lrecl   //~v75CI~
//v74U:070407*(BUG)"SPL width delmstr" case:some line is not splitted(after short line contains delm)//~v74UI~
//v74T:070404*(BUG)TAB clear when join when width specified for the same record length//~v74TI~
//v74S:070402*(BUG)SPL tail;rep split dbcs by space if not SBCS option//~v74SI~
//v74R:070402 (BUG)SPL exp generate longer than width for the line with tab and not yet displayed one.//~v74RI~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v74C:070225 (BUG) ABEND col cmd when type is over 3 char(max is 7)//~v74CI~
//            fcmd4.c                                              //~v74CI~
//v74B:070225 (LNX:BUG)ini file process fail by EOL type for the file Windows created.//~v74BI~
//            chk other fgets process                              //~v74BI~
//v74y:070223 new option to set COLS ON as default  "COLS ON ALL"  //~v74yI~
//v69C:060612 (BUG)at save tab is replaced by space after sort cmd //~v69CI~
//v69B:060612 (BUG)at save tab is replaced by space after spl cmd  //~v69BI~
//v69t:060601 (BUG)on binary opened file,split cmd replace tab to space.//~v69tI~
//            for text,keep tab as possible                        //~v69tI~
//v62Q:050419 errmsg for split width is over MAXLINEDATA           //~v62QI~
//v62H:050413 exe cmd label support                                //~v62HI~
//v62E:050407 sort cmd:numeric sort support(minus consideration)   //~v62EI~
//v61a:050212 gauge for the bin file with lineno xoff should be same as text file//~v61aI~
//v617:050212 mergin set required for continue protection attr     //~v617I~
//v60t:050130 set default split type to "ALL"                      //~v60tI~
//v60s:050130 support display width change without close current opened by split cmd for bin file//~v60sI~
//v582:040822 (BUG)../ and ..\ is treated as label for rep/cre/app cmd//~v582I~
//v581:040822 sort cmd;display moved count to update errmsg line   //~v581I~
//v57y:040605 (BUG)./ and .\ is treated as label for rep/cre/app cmd//~v57yI~
//v571:040421 sort cmd;support cont line file                      //~v571I~
//v55J:040316 join cmd;add bandle,skip option                      //~v55JI~
//v54Y:040201 "cre/rep/sav/app" support -xall -nxall .a .b         //~v54YI~
//v53N:031029 SPLit cmd;tail cut by width parm                     //~v53NI~
//v51G:030726 CV cmd;add support label operand(fcmdsortabrange-->fcmdabrange)//~v51GI~
//v51c:030510 (BUG)SPLit cmd loop if delm is already top when tol option specified//~v51cI~
//v50J:030126 (DOS)no SORT/SPLIT/JOIN cmd support for memory       //~v50JI~
//v50F:030201 (BUG)split cont;plhlen set err(data expanded ileagaly)//~v50FI~
//v50E:030201 (BUG)split cont loop when width=0                    //~v50EI~
//v50B:030125 spl cmd;string delm by "delm string"(char delm by 'delm chars')//~v50BI~
//v50A:030125 spl cmd;delmeter on top of line option(TOL)          //~v50AI~
//v50z:030125 accept width=0 when split all;aplit all line of any length by delm.//~v492I~
//v492:020616 (BUG)loop when width=1 and 1st byte is DBCS          //~v492I~
//v491:020616 SPLIT cmd;err chk to delm string should be enclosed by quate.//~v491I~
//v490:020616 SPLIT cmd mutualy exclusive parm chk                 //~v490I~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//v470:020202 assume 80 for expand width for spf file              //~v470I~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd
//v44d:011203 tab for hexdisplay                                   //~v44dI~
//v44b:011202 tab stop at intermediate space                       //~v44bI~
//v447:011201 (BUG)abend when cols type over 3 byte                //~v447I~
//v446:011201 default cols data for hex edit                       //~v446I~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21r:010211 tabstop id on gauge                                  //~v21rI~
//v21e:010106 LINUX support:small letter filename                  //~v21eI~
//v19E:000904 LINUX support(like XE!UNDEL-->XE_UNDEL; ! has mean to bash)//~v19EI~
//v17j:000513 count msg for sort dupchk                            //~v17jI~
//v17e:000501 SORT for also excluded.By NX option,sort displayed line only.//~v17eI~
//v17d:000501 Add break search option to SORT cmd                  //~v17dR~
//v172:000422 add dupkey chk option to SORT                        //~v172I~
//v166:000414 sort cmd key count=0 err chk                         //~v166I~
//v165:000414 (BUG)label err msg not displayed(sort cmd)           //~v165I~
//v153:000314 MAX Sort line ctr up except for DOS                  //~v153I~
//v131:990908 (BUG)SORT seq chk err when 2 sort field specified.   //~v131I~
//v11N:990829 COL cmd support                                      //~v11NI~
//v11d:990703 (BUG) but no actual effect(sort cmd). '&' shoud be '&&'//~v11dR~
//v112:990606 (BUG)SORT cmd faile;filechktabdbcs return 4 when no tab//~v112I~
//v111:990606 SORT cmd help                                        //~v111I~
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
#include <utf22.h>                                                 //~va3PI~
#include <ucvebc.h>                                                //~va50I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"        //filesetcsr                           //~v17dR~
#include "xefile22.h"        //filesetcsr                          //~v446I~
#include "xefile6.h"		//tab
#include "xefcmd2.h"		                                       //~v47iR~
#include "xefcmd22.h"		//fcmdlabelerr
#include "xefcmd3.h"                                               //~v165I~
#include "xefcmd4.h"
#include "xefcmd6.h"                                               //~v51GI~
#include "xeerr.h"
#include "xelcmd.h"
#include "xelcmd2.h"                                               //~v45xI~
#include "xelcmd4.h"                                               //~v172I~
#include "xeundo.h"
#include "xesub.h"                                                 //~v11NI~
#include "xefsub.h"                                                //~v47iI~
#include "xefunc.h"                                                //~v17eI~
#include "xecalc2.h"                                               //~v62EI~
#include "xechar12.h"                                              //~v74EI~
#include "xechar2.h"                                               //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub2.h"                                                //~va20I~
#endif                                                             //~va20I~
//*******************************************************
#define MAXSORTKEYNO  5
#if defined(DOS) && !defined(DPMI)                                 //~v153I~
#define MAXSORTLINE   32767
#else                                                              //~v153I~
#define MAXSORTLINE   0xffffff		//actualy infinite             //~v153I~
#endif                                                             //~v153I~
#define MAXLABEL 2
#define SOPT_REV     1      //reverse seq sort                     //~v10II~
#define SOPT_CASE    2      //case sensitive compare               //~v10II~
#define SOPT_NUMERIC 4      //numeric compare                      //~v62EI~
#define SOPT_SPLITDBCSSPACE   0x10                                 //~va3PI~
#define SOPT_SPLITDBCSINCLUDE 0x20                                 //~va3PI~
#define SOPT_SPLITDBCSEXCLUDE 0x40                                 //~va3PI~
#define SOPT_SBCS             0x80                                 //~va8iI~
#ifdef UNX                                                         //~v21eR~
	#define COLS_FNAME       "xe_col_"  //default cols type        //~v21eI~
#else                                                              //~v21eI~
#define COLS_FNAME       "XE!COL!"  //default cols type            //~v21eR~
#endif                                                             //~v21eI~
#define DEFAULT_COLSTYPE "col"  //default cols type                //~v21eR~
#define DEFAULT_COLSTYPEB "colb"  //default cols type for bin file //~v446R~
#define DEFAULT_COLSTYPEH "colx"  //default cols type for bin file //~v446I~
#define HEX_INTSPACE   '_';                                        //~v44dI~
//****************************************************************
typedef struct _SORTWK {
						UCHAR   *SWdata;    //plh and data ptr     //~v10IR~
						UCHAR   *SWdbcs;    //plh and data ptr     //~v10II~
                        int      SWflag;   //keep tabchk/tabfound flag//~v69CI~
                        int      SWseq;    //lineno and dbcs ptr   //~v10II~
                        int      SWbufflen;                        //~v10II~
                        int      SWlen;                            //~v10II~
                        struct _SORTWK *SWpswcont;   //swk of cont 2nd line//~v571I~
                        char    *SWsvdatadbcs;  //save data/dbcs for bounds sort//~v74EI~
                        int      SWcontctr;     //swk cont following line count//~v571I~
                       } SORTWK,*PSORTWK;
#define SORTWKSZ (sizeof(SORTWK))
//****************************************************************
//static UCHAR Slabold[MAXLABEL][ULHLINENOSZ+1];//to bell once at changed//~v165R~
static  int   Skeypost[MAXSORTKEYNO*3];                            //~v10IR~
static  int   Skeyctr;
static  int   Sdupchkno;	//key dup chk key position             //~v172I~
static  int   Sbreakchkno;  //key break chk key position           //~v17dR~
static  int   Smatchkeycnt=0;	//matched key count                //~v44dR~
static  int   Ssortnxid;	//not excluded only sort sw            //~v17eI~
static  int   Ssortnbid;	//ignore bounds parm                   //~v74EI~
static  int   Smaxkeypos=0;	//for contline keypos chk              //~v571I~
#ifdef UTF8UCS2                                                    //~va20I~
static  int   Ssortu8;                                             //~va20I~
static  int Ssortothopt;                                           //~va3PR~
#endif                                                             //~va20I~
//****************************************************************
int fcmdsortopdchk(PUCLIENTWE Ppcw,UCHAR Pplabt[][ULHLINENOSZ+1],
					int *Ppkeyoffslen,int *Pplabctr,int *Ppkeytctr);
//int fcmdsortgetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Pplabt[][ULHLINENOSZ+1],//~v51GR~
//                        int Plabctr,PULINEH *Ppplhs,PULINEH *Ppplhe);//~v51GR~
int fcmdsortproc(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplhs,PULINEH Pplhe);
int sortlinecomp(const void *ent1,const void *ent2);
int fcmdcolalloc(PUFILEC Ppfc,UCHAR *Ptype);                       //~v11NI~
int fcmdsortbndsupdate(PUCLIENTWE Ppcw,PULINEH Pplh,PSORTWK Ppswk0,PSORTWK Ppswk,int Pseqno,int Pbndsoffs1,int Pbndsoffs2);//~v74ER~
//****************************************************************
// sort on optional label range
//*rc   :0
//****************************************************************
int func_sort(PUCLIENTWE Ppcw)
{
#ifdef DOSDOS                                                      //~v50JI~
    return errnotsupported("SORt","DOS version");                  //~v50JI~
#else                                                              //~v50JI~
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1];//label opd from/to
    PUFILEH pfh;
    PULINEH plhs,plhe;
    PUFILEC pfc;                                                   //~v10IR~
    int rc,labctr;
//*********************************
	pfc=Ppcw->UCWpfc;                                              //~v10II~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v10II~
		return errbrowsemode();                                    //~v10II~
	pfh=pfc->UFCpfh;                                               //~v10IR~
    if (pfh->UFHtype==UFHTKFI)	//menu opt file                    //~v10II~
    	return 4;                                                  //~v10II~
	if (!Ppcw->UCWparm)		//operand
    {                                                              //~v111I~
//      return errmissing();                                       //~v111R~
//      uerrmsg("SOR column1[-col2][/[B][C][D][I][R]] [2nd-key [3rd]...] [NX] [.lab1 .lab2]",0);//~v62ER~
//      uerrmsg("SOR column1[-col2][/[B][C][D][I][N][R]] [2nd-key [3rd]...] [NX] [.lab1 .lab2]",0);//~v74ER~
#ifdef UTF8UCS2                                                    //~va3PI~
//      uerrmsg("SOR column1[-col2][/[B][C][D][I][N][R]] [2nd-key [3rd]...] [NX] [NB] [D[S|I|X] [.lab1 .lab2]",0);//~va3PI~//~va8iR~
        uerrmsg("SOR column1[-col2][/[B][C][D][I][N][R]] [2nd-key [3rd]...] [NX] [NB] [D[S|I|X] [SBCS] [.lab1 .lab2]",0);//~va8iI~
#else                                                              //~va3PI~
        uerrmsg("SOR column1[-col2][/[B][C][D][I][N][R]] [2nd-key [3rd]...] [NX] [NB] [.lab1 .lab2]",0);//~v74EI~
#endif                                                             //~va3PI~
        return 0;                                                  //~v111I~
    }                                                              //~v111I~
	memset(labt,0,sizeof(labt));		//for null term
	Ssortnxid=0;                                                   //~v17eM~
	Ssortnbid=0;                                                   //~v74EI~
	if (fcmdsortopdchk(Ppcw,labt,&Skeypost[0],&labctr,&Skeyctr))   //~v10IR~
    	return 4;
    if (FILEUTF8MODE(pfh))                                         //~va8iI~
    {                                                              //~va8iI~
        if (Ssortothopt & SOPT_SBCS)                               //~va8iI~
        {                                                          //~va8iI~
            uerrmsg("SBCS option is invalid for utf8 file",0);     //~va8iI~
        	return 4;                                              //~va8iI~
        }                                                          //~va8iI~
    }                                                              //~va8iI~
//  if (rc=fcmdsortgetabrange(Ppcw,pfh,labt,labctr,&plhs,&plhe),rc)//~v51GR~
    if (rc=fcmdgetabrange(Ppcw,pfh,labt,labctr,&plhs,&plhe,0),rc)  //~v51GI~
    	return rc;	//may 1:no bell                                //~v10IR~
    if (UCBITCHK(plhs->ULHflag2,ULHF2SPLIT2))   //2nd of split     //~v571R~
    {                                                              //~v571I~
    	uerrmsg("SORT start label is on the middle of split line.",//~v571R~
        		"SORT 開始行ラベルが分割行の途中です。");          //~v571R~
        return 4;                                                  //~v571I~
    }                                                              //~v571I~
    while(UCBITCHK(plhe->ULHflag2,ULHF2SPLIT1))   //end line is splitted//~v571I~
    	plhe=UGETQNEXT(plhe);                                      //~v571I~
	rc=fcmdsortproc(Ppcw,pfh,plhs,plhe);                           //~v10IR~
    return rc;                                                     //~v10IR~
#endif                                                             //~v50JI~
}//func_sort
#ifdef DOSDOS                                                      //~v50JI~
#else                                                              //~v50JI~
//****************************************************************
//!fcmdsortopdchk
//  SORT n-m[/[r][c][i] ... (max5) [.lab1 .lab2]                   //~v10II~
//* parm1 :pcw
//* parm2 :label output
//* parm3 :key range output
//* parm4 :label ctr
//* parm5 :key ctr
//* return:rc
//****************************************************************
int fcmdsortopdchk(PUCLIENTWE Ppcw,UCHAR Pplabt[][ULHLINENOSZ+1],
					int *Ppkeyoffslen,int *Pplabctr,int *Ppkeyctr)
{
    char *popd,*plabt,*pc,*popdn;                                  //~v10IR~
    int labctr=0,keyctr=0,keypos,keylen,opt;                       //~v10IR~
    int *pkey,opdno,ii,rc;                                         //~v10IR~
    int maxkeypos=0;                                               //~v571I~
	long pos1,pos2;                                                //~v10II~
//*********************************
    Sdupchkno=0;        //up to this,dup key err                   //~v172I~
    Sbreakchkno=0;      //up to this,no break key                  //~v17dR~
    opdno=Ppcw->UCWopdno;           //funccmd created already
    popd=Ppcw->UCWopdpot;
    pkey=Ppkeyoffslen;
    plabt=&Pplabt[0][0];
#ifdef UTF8UCS2                                                    //~va3PI~
	Ssortothopt=0;                                                 //~va3PR~
#endif                                                             //~va3PI~
	for (ii=0;ii<opdno;ii++)
	{
    	popdn=popd+strlen(popd)+1;   //next opd addr               //~v10IR~
        if (*popd==ULCCMDLABEL)  //lebel specified
        {
            if (labctr==MAXLABEL)
                return fcmdlabelerr("Too many");
            strncpy(plabt,popd,ULHLINENOSZ);
            plabt+=ULHLINENOSZ+1;
            labctr++;
		}
        else                                                       //~v17eI~
        if (!stricmp(popd,"NX"))  //NX onlysw                      //~v17eI~
			Ssortnxid=1;                                           //~v17eI~
        else
        if (!stricmp(popd,"NB"))  //ignore bnds                    //~v74EI~
			Ssortnbid=1;                                           //~v74EI~
        else                                                       //~v74EI~
#ifdef UTF8UCS2                                                    //~va3PI~
        if (!stricmp(popd,"SBCS"))  //ignore bnds                  //~va8iI~
        	Ssortothopt|=SOPT_SBCS;                                //~va8iI~
        else                                                       //~va8iI~
        if (toupper(*popd)=='D')                                   //~va3PR~
        {                                                          //~va3PI~
        	switch(toupper(*(popd+1)))                             //~va3PI~
            {                                                      //~va3PI~
            case 'S':                                              //~va3PI~
                Ssortothopt|=SOPT_SPLITDBCSSPACE;                  //~va3PR~
            	break;                                             //~va3PI~
            case 'I':                                              //~va3PI~
                Ssortothopt|=SOPT_SPLITDBCSINCLUDE;                //~va3PR~
            	break;                                             //~va3PI~
            case 'X':                                              //~va3PI~
                Ssortothopt|=SOPT_SPLITDBCSEXCLUDE;                //~va3PR~
            	break;                                             //~va3PI~
            default:                                               //~va3PI~
                return errinvalid(popd);                           //~va3PI~
            }                                                      //~va3PI~
        }                                                          //~va3PI~
        else                                                       //~va3PI~
#endif                                                             //~va3PI~
        {
            if (keyctr==MAXSORTKEYNO)                              //~v10IR~
                return errtoomany();
            keyctr++;                                              //~v10IM~
			pc=strchr(popd,'/');	//search option specification  //~v10II~
            opt=SOPT_CASE;                                         //~v10IR~
            if (pc)                                                //~v10II~
                for (*pc++=0;*pc;pc++)                             //~v10II~
                {                                                  //~v10II~
	                switch(toupper(*pc))                           //~v10IR~
                    {                                              //~v10II~
                    case 'N':		//reverse                      //~v62EI~
                    	opt|=SOPT_NUMERIC;                         //~v62ER~
                    	break;                                     //~v62EI~
                    case 'R':		//reverse                      //~v10II~
                    	opt|=SOPT_REV;                             //~v10II~
                    	break;                                     //~v10IR~
                    case 'C':		//case sensitive               //~v10II~
                    	opt|=SOPT_CASE;                            //~v10II~
                    	break;                                     //~v10IR~
                    case 'I':		//case sensitive               //~v10II~
                    	opt&=~SOPT_CASE;                           //~v10II~
                    	break;                                     //~v10IR~
                    case 'D':		//dup chk                      //~v172I~
                    	Sdupchkno=keyctr;   //up to this,dup key err//~v172I~
                    	break;                                     //~v172I~
                    case 'B':		//break chk                    //~v17dR~
                    	Sbreakchkno=keyctr;   //up to this,break chk//~v17dR~
                    	break;                                     //~v17dR~
					default:                                       //~v10IR~
                		return errinvalid(pc);                     //~v10II~
                    }                                              //~v10II~
				}//all option                                      //~v10II~
			rc=ugetnumrange(popd,&pos1,&pos2);                     //~v10II~
            if (rc>1)                                              //~v10IR~
                return errinvalid(popd);
            keypos=(int)pos1-1;                                    //~v10II~
            if (keypos<0 || keypos>=MAXLINEDATA)                   //~v10II~
                return errinvalid(popd);                           //~v10IM~
			if (rc)			//- used                               //~v10II~
            	if (pos2)	//2 value                              //~v10II~
                {                                                  //~v10II~
                	if ((keylen=(int)pos2-keypos)<0)               //~v10II~
		                return errinvalid(popd);                   //~v10II~
				}                                                  //~v10II~
                else                                               //~v10II~
                	keylen=MAXLINEDATA;                            //~v10II~
            else			//no - used                            //~v10II~
            	keylen=1;                                          //~v10II~
            maxkeypos=max(maxkeypos,(keypos+keylen));              //~v571R~
            *pkey++=keypos;                                        //~v10IR~
            *pkey++=keylen;                                        //~v10II~
            *pkey++=opt;                                           //~v10II~
        }//not label                                               //~v10IR~
        popd=popdn;                                                //~v10IR~
	}//opdno loop
//  if (labctr & labctr!=MAXLABEL)                                 //~v11dR~
    if (labctr && (labctr!=MAXLABEL))                              //~v11dI~
        return fcmdlabelerr("label count=0 or 2");
    if (!keyctr)                                                   //~v166I~
    {                                                              //~v166I~
        uerrmsg("No sort-key position",                            //~v166I~
                "整列キーの指定いなし");                           //~v166I~
		return 4;                                                  //~v166I~
    }                                                              //~v166I~
    Smaxkeypos=maxkeypos;                                          //~v571I~
	*Ppkeyctr=keyctr;                                              //~v10IR~
	*Pplabctr=labctr;
    return 0;
}//fcmdsortopdchk                                                  //~v11dR~
////****************************************************************//~v51GR~
////!fcmdsortgetabrange                                            //~v51GR~
////* get line range from label                                    //~v51GR~
////*parm1 :pcw                                                    //~v51GR~
////*parm2 :pfh                                                    //~v51GR~
////*parm3 :labt                                                   //~v51GR~
////*parm4 :labtctr(!=0)                                           //~v51GR~
////*parm5 :output strat plh                                       //~v51GR~
////*parm6 :output end plh                                         //~v51GR~
////*rc   :0:ok,1:lab not found 2nd time,4:notfound 1st time or label err//~v51GR~
////****************************************************************//~v51GR~
//int fcmdsortgetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Pplabt[][ULHLINENOSZ+1],//~v51GR~
//                        int Plabctr,PULINEH *Ppplhs,PULINEH *Ppplhe)//~v51GR~
//{                                                                //~v51GR~
//    PULINEH plht[MAXLABEL],plh1,plh2;                            //~v51GR~
////    int sortseq[MAXLABEL];                                     //~v51GR~
////    int ii;                                                    //~v51GR~
////    UCHAR editwk[ULHLINENOSZ+32];                              //~v51GR~
//    int rc;                                                      //~v51GR~
////***************                                                //~v51GR~
//    rc=fcmdgetlabelrange(Ppfh,Plabctr,Pplabt,plht,0);//not drop cmd//~v51GR~
//    if (!Plabctr)                                                //~v51GR~
//    {                                                            //~v51GR~
////        Slabold[0][0]=0;                                       //~v51GR~
//        plh1=UGETQTOP(&Ppfh->UFHlineque);//search from first     //~v51GR~
//        plh2=UGETQEND(&Ppfh->UFHlineque);//search from first     //~v51GR~
//    }                                                            //~v51GR~
//    else                                                         //~v51GR~
//    {                                                            //~v51GR~
////        if (lcmdgetabplh(Ppfh,MAXLABEL,Pplabt,plht,sortseq))   //~v51GR~
////        {                                                      //~v51GR~
////            for (ii=0;ii<MAXLABEL;ii++)                        //~v51GR~
////                if (!sortseq[ii])   //0 if label not found     //~v51GR~
////                    break;                                     //~v51GR~
////            strcpy(editwk,Pplabt[ii]);                         //~v51GR~
////            strcat(editwk," not found");                       //~v51GR~
////            if (memcmp(Pplabt,Slabold,sizeof(Slabold)))        //~v51GR~
////            {                                                  //~v51GR~
////                memcpy(Slabold,Pplabt,sizeof(Slabold));//save err label//~v51GR~
////                return 4;                                      //~v51GR~
////            }                                                  //~v51GR~
////            return 1;    //no bell,no home ctr move            //~v51GR~
////        }                                                      //~v51GR~
////        Slabold[0][0]=0;                                       //~v51GR~
//////set which is start and end                                   //~v51GR~
////        if (sortseq[0]<sortseq[1])                             //~v51GR~
////        {                                                      //~v51GR~
//            plh1=plht[0];                                        //~v51GR~
//            plh2=plht[1];                                        //~v51GR~
////        }                                                      //~v51GR~
////        else                                                   //~v51GR~
////        {                                                      //~v51GR~
////            plh1=plht[1];                                      //~v51GR~
////            plh2=plht[0];                                      //~v51GR~
////        }                                                      //~v51GR~
//    }                                                            //~v51GR~
//    *Ppplhs=plh1;                                                //~v51GR~
//    *Ppplhe=plh2;                                                //~v51GR~
////    return 0;       //has label                                //~v51GR~
//    if (rc==2)      //2 for no bell by fcmdgetlabelrange         //~v51GR~
//        rc=1;                                                    //~v51GR~
//    return rc;       //has label                                 //~v51GR~
//}//fcmdsetabrange                                                //~v51GR~
//****************************************************************
// sort not excluded line
//*renumber line number and free undo stack
//*parm1 :pcw
//*parm2 :pfh
//*parm3 :start plh
//*parm4 :end   plh
//*return:rc
//****************************************************************
int fcmdsortproc(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe)
{
	PSORTWK pswk,pswk0;
	PSORTWK pswkc,pswkt=0;//cont line part                         //~v571R~
	PULINEH plh,csrplh=0;                                          //~v17dR~
    int linectr,sortedsw;                                          //~v10IR~
    int rc;                                                        //~v10IR~
    int duperr=0,sortcnt=0;                                        //~v17jR~
    int breakfound=0;                                              //~v17dR~
    int contctr=0,ii;                                              //~v571R~
    int updatectr=0;                                               //~v581I~
    UCHAR *data;
//  int bndsoffs1,bndsoffs2,bndssw=0;                              //~v74EI~//~vaf9R~
    int bndsoffs1=0,bndsoffs2=0,bndssw=0;                          //~vaf9I~
//*********************************
//count line
	plh=Pplhs;
    linectr=0;
    if (!Ssortnbid)                                                //~v74EI~
    {                                                              //~v74EI~
	    bndsoffs1=Ppfh->UFHbndscol1-1;                             //~v74ER~
	    bndsoffs2=Ppfh->UFHbndscol2;                               //~v74ER~
        if (bndsoffs1>=0 || bndsoffs2>0)                           //~v74EI~
        	bndssw=1;                                              //~v74EI~
    }                                                              //~v74EI~
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))
	{
        if (plh->ULHtype==ULHTDATA)
        {
//            if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2)) //~v571R~
//            {                                                    //~v571R~
//                uerrmsg("Cannot sort file with split line",      //~v571R~
//                        "分割行のあるファイルはSORTできません"); //~v571R~
//                return 4;                                        //~v571R~
//            }                                                    //~v571R~
			if (bndssw)                                            //~v74EI~
                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2))//~v74EI~
                {                                                  //~v74EI~
                    uerrmsg("Specify NB option for the file with split line",//~v74EI~
                            "分割行のあるファイルはNBオプションが必要です");//~v74EI~
                    return 4;                                      //~v74EI~
                }                                                  //~v74EI~
            if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))//continued line//~v571I~
            {                                                      //~v571I~
            	if (Ssortnxid)	// nx option                       //~v571R~
                {                                                  //~v571I~
                    uerrmsg("Cannot sort file with split line by NX option.",//~v571I~
                            "分割行のあるファイルはNXオプションSORTできません");//~v571I~
                    return 4;                                      //~v571I~
                }                                                  //~v571I~
                contctr++;                                         //~v571I~
            }                                                      //~v571I~
            else                                                   //~v571I~
			if (!Ssortnxid || !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))//~v17eR~
            {                                                      //~v54YI~
            	if (linectr==MAXSORTLINE)
                {
	            	uerrmsg("Too many line(>%d) to sort",          //~v10IR~
                			"行数>%d はSORTできません",            //~v10IR~
							MAXSORTLINE);
					return 4;
                }
                else
	            	linectr++;
            }//sortnxid                                            //~v54YI~
		}
        if (plh==Pplhe)
        	break;
	}//
    if (linectr<2)
    {
        uerrmsg("No line to be sorted",
                "対象行<=1");                                      //~v10IR~
        return 4;
    }
#ifdef UTF8UCS2                                                    //~va20I~
    Ssortu8=FILEUTF8MODE(Ppfh);	//parm to linecomp                 //~va20I~
#endif                                                             //~va20I~
//alloc sort work
//  pswk0=pswk=umalloc((UINT)(SORTWKSZ*linectr));                  //~v571R~
//  pswk0=pswk=umalloc((UINT)(SORTWKSZ*(linectr+contctr)));        //~v571I~//+vb30R~
    pswk0=pswk=umalloc(SORTWKSZ*(size_t)(linectr+contctr));        //+vb30I~
    pswkc=pswk0+linectr;	//contline swk top                     //~v571R~
    UALLOCCHK(pswk,UALLOC_FAILED);
	plh=Pplhs;
    linectr=0;
    rc=0;
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))
	{
        if (plh->ULHtype==ULHTDATA)
        {
		    if (!plh->ULHdbcs)  //not once displayed
        		if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len
            		break;
            rc=0;    	                                           //~v571I~
			if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))//2nd line     //~v571I~
            {                                                      //~v571I~
            	pswkc->SWseq=linectr;	//top line reverse index   //~v571R~
            	pswkc->SWdata=plh->ULHdata;                        //~v571I~
            	pswkc->SWdbcs=plh->ULHdbcs;                        //~v571I~
            	pswkc->SWflag=plh->ULHflag2;	//top line reverse index//~v69CI~
            	pswkc->SWbufflen=plh->ULHbufflen;                  //~v571I~
            	pswkc->SWlen=plh->ULHlen;                          //~v571I~
                if (!pswkt->SWpswcont)                             //~v571R~
                	pswkt->SWpswcont=pswkc;                        //~v571R~
                pswkt->SWcontctr++;                                //~v571R~
            	pswkc++;                                           //~v571I~
            }//2nd line                                            //~v571I~
            else                                                   //~v571I~
			if (!Ssortnxid || !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))//~v17eR~
            {
                if (plh->ULHlen<Smaxkeypos)//cont top should contain key//~v571I~
                    if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//splitted to next line//~v571R~
                    {                                              //~v571R~
                        uerrmsg("key postion is beyond 1st line length(line %d).",//~v571R~
                                "キー指定が分割行の1行目の長さを超えています(%d行目)",//~v571R~
                                    plh->ULHlinenor);              //~v571R~
                        rc=4;                                      //~v571R~
                        break;                                     //~v571R~
                    }                                              //~v571R~
            	pswk->SWseq=++linectr;                             //~v10IR~
            	pswk->SWdata=plh->ULHdata;                         //~v10IR~
            	pswk->SWdbcs=plh->ULHdbcs;                         //~v10II~
            	pswk->SWflag=plh->ULHflag2;	//top line reverse index//~v69CR~
            	pswk->SWbufflen=plh->ULHbufflen;                   //~v10II~
            	pswk->SWlen=plh->ULHlen;                           //~v10II~
	            pswk->SWpswcont=0;	//id of no cont line           //~v571I~
	            pswk->SWcontctr=0;                                 //~v571I~
//	            pswk->SWsvdatadbcs=(char*)-1;   //need save data   //~v74EI~//~vafkR~
	            pswk->SWsvdatadbcs=(char*)(ULPTR)-1;   //need save data//~vafkI~
                pswkt=pswk;	//for 2nd of cont line process         //~v571I~
            	pswk++;                                            //~v10II~
			}
		}
        if (plh==Pplhe)
        	break;
	}//
//  if (rc)                                                        //~v112R~
//  if (rc==UALLOC_FAILED)//expand data len                        //~v571R~
    if (rc)                                                        //~v571I~
    {
    	ufree(pswk0);
    	return rc;
    }
//sort
  	qsort(pswk0,(UINT)linectr,SORTWKSZ,sortlinecomp);
//exchange data/dbcs by sort order
    UPCTRREQ(Ppfh);         //write at save
	pswk=pswk0;
	plh=Pplhs;
    sortedsw=0;                                                    //~v10II~
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))
	{
        if (plh->ULHtype==ULHTDATA)
        {
            pswkc=pswk->SWpswcont;  //cont 2nd line top            //~v571I~
            contctr=pswk->SWcontctr;                               //~v571I~
			if (!Ssortnxid || !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))//~v17eR~
            {
            	sortcnt++;                                         //~v17jI~
            	data=pswk->SWdata;                                 //~v10IR~
            	if (plh->ULHdata!=data)	//seq changed
                {
					if ((rc=undoupdate(Ppcw,plh,UUHTREP))==UALLOC_FAILED)	//prepare undo and update process
    	        		break;
                  if (bndssw)                                      //~v74EI~
                  {                                                //~v74EI~
					if ((rc=fcmdsortbndsupdate(Ppcw,plh,pswk0,pswk,sortcnt,bndsoffs1,bndsoffs2))==UALLOC_FAILED)	//prepare undo and update process//~v74ER~
    	        		break;                                     //~v74EI~
                  }                                                //~v74EI~
                  else                                             //~v74EI~
                  {                                                //~v74EI~
            		plh->ULHdata   =data;                          //~v10IR~
            		plh->ULHdbcs   =pswk->SWdbcs;                  //~v10IR~
            		plh->ULHbufflen=pswk->SWbufflen;               //~v10II~
            		plh->ULHlen    =pswk->SWlen;                   //~v10II~
                    if (pswkc)                                     //~v571I~
                        UCBITON(plh->ULHflag2,ULHF2SPLIT1);//splitted to next line//~v571R~
                    else                                           //~v571I~
                        UCBITOFF(plh->ULHflag2,ULHF2SPLIT1);       //~v571I~
                    UCBITOFF(plh->ULHflag2,ULHF2SPLIT2); //not 2nd //~v571I~
                    UCBITOFF(plh->ULHflag2,(ULHF2TABCHKED|ULHF2TABFOUND)); //not 2nd//~v69CI~
                    UCBITON(plh->ULHflag2,(pswk->SWflag &(ULHF2TABCHKED|ULHF2TABFOUND))); //not 2nd//~v69CI~
                  }                                                //~v74EI~
                                                                   //~v69CI~
                    sortedsw=1;                                    //~v10II~
                    updatectr++;                                   //~v581I~
                }
//dupkey chk/break chk                                             //~v17dR~
                if (Sdupchkno||Sbreakchkno)  //dupkey/keybreak chk option//~v17dR~
                    if (pswk!=pswk0)    //not first entry          //~v172I~
                	{                                              //~v172I~
  						rc=sortlinecomp(pswk-1,pswk);              //~v172I~
                      if (Sdupchkno)  //dupkey chk option          //~v17dR~
                        if (!rc||Smatchkeycnt>=Sdupchkno)//        //~v172I~
                        {                                          //~v172I~
                        	duperr++;                              //~v17jR~
							lcmdshifterr(plh,0,&csrplh);//no exclude line highlight//~v17dR~
						}                                          //~v172I~
                	  if (Sbreakchkno)  //keybreak chk option      //~v17dR~
                       if (Smatchkeycnt>=0)                        //~v17jR~
                        if (Smatchkeycnt<Sbreakchkno)//            //~v17dR~
                        {                                          //~v17dR~
                        	breakfound++;                          //~v17jR~
							lcmdshifterr(plh,0,&csrplh);//no exclude line highlight//~v17dR~
						}                                          //~v17dR~
                	}                                              //~v172I~
                pswk++;                                            //~v10II~
			}//displayed                                           //~v10IR~
            if (pswkc)	//split line                               //~v571R~
            {                                                      //~v571I~
            	for (ii=contctr;ii>0;ii--)                         //~v571I~
                {                                                  //~v571I~
                	plh=UGETQNEXT(plh);                            //~v571I~
			        if (plh->ULHtype==ULHTDATA)                    //~v571I~
        			{                                              //~v571I~
                        data=pswkc->SWdata;                        //~v571I~
                        if (plh->ULHdata!=data) //seq changed      //~v571I~
                        {                                          //~v571I~
                            if ((rc=undoupdate(Ppcw,plh,UUHTREP))==UALLOC_FAILED)   //prepare undo and update process//~v571I~
                                break;                             //~v571I~
                            plh->ULHdata   =data;                  //~v571I~
                            plh->ULHdbcs   =pswkc->SWdbcs;         //~v571I~
                            plh->ULHbufflen=pswkc->SWbufflen;      //~v571I~
                            plh->ULHlen    =pswkc->SWlen;          //~v571I~
							UCBITON(plh->ULHflag2,ULHF2SPLIT2);//2nd of splitted//~v571R~
			                if (ii!=1)	//not last                 //~v571I~
								UCBITON(plh->ULHflag2,ULHF2SPLIT1);//has next//~v571R~
                			else                                   //~v571I~
								UCBITOFF(plh->ULHflag2,ULHF2SPLIT1);//~v571R~
		                    UCBITOFF(plh->ULHflag2,(ULHF2TABCHKED|ULHF2TABFOUND)); //not 2nd//~v69CI~
		                    UCBITON(plh->ULHflag2,(pswkc->SWflag &(ULHF2TABCHKED|ULHF2TABFOUND))); //not 2nd//~v69CR~
                            sortedsw=1;                            //~v571I~
                        }//data changed                            //~v571R~
                        pswkc++;                                   //~v571I~
                    }//data line                                   //~v571R~
                }//all 2nd line of split                           //~v571R~
            }//cont line                                           //~v571I~
		}//ULHTDATA                                                //~v10IR~
        if (plh==Pplhe)
        	break;
	}//all plh                                                     //~v10IR~
    if (rc==UALLOC_FAILED)//expand data len                        //~v112I~
    {                                                              //~v112I~
    	ufree(pswk0);                                              //~v112I~
    	return rc;                                                 //~v112I~
    }                                                              //~v112I~
    if (sortedsw)                                                  //~v10II~
    {                                                              //~v581I~
    	UPCTRREQ(Ppfh);         //write at save                    //~v10IR~
    	uerrmsg("%d line(s) moved",                                //~v581I~
        		"%d 行を移動",                                     //~v581I~
				updatectr);                                        //~v581I~
    }                                                              //~v581I~
    else                                                           //~v10II~
    	uerrmsg("Already sorted",                                  //~v10II~
        		"既に整列済み");                                   //~v10II~
    ufree(pswk0);                                                  //~v10II~
    if (csrplh)                                                    //~v17dR~
		filesetcsr(Ppcw,csrplh,0,0);	//fldno=0,offs=0           //~v17dR~
	if (duperr)                                                    //~v172I~
    	uerrmsg("Duplicated Key %d of %d",                         //~v17jR~
        		"キーの重複 %d / %d 件",                           //~v17jR~
				duperr,sortcnt);                                   //~v17jI~
    else                                                           //~v17dR~
	if (breakfound)                                                //~v17dR~
    	uerrmsg("Keybreak found %d of %d",                         //~v17jR~
        		"キーブレークあり %d / %d 回",                     //~v17jR~
				breakfound,sortcnt);                               //~v17jI~
	return 0;
}//filesortproc
//**********************************************************************//~v74EI~
//!sort update width bnds                                          //~v74EI~
//seqno:sortwk current position after sort(start from 1)           //~v74EI~
//**********************************************************************//~v74EI~
int fcmdsortbndsupdate(PUCLIENTWE Ppcw,PULINEH Pplh,PSORTWK Ppswk0,PSORTWK Ppswk,int Pseqno,int Pbndsoffs1,int Pbndsoffs2)//~v74ER~
{                                                                  //~v74EI~
    PSORTWK pswksave;                                              //~v74EI~
    char *pc,*pcd,*savedata=NULL;                                       //~v74ER~//~vaf9R~
//  int     srclen,tgtlen,len,savelen,copylen,rc,savesw=0,width;   //~v74ER~//~vaf9R~
    int     srclen,tgtlen,len,savelen=0,copylen,rc,savesw=0,width; //~vaf9I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    int optcap2;                                                   //~va8hI~
//*****************                                                //~v74EI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//	if (Ppswk->SWsvdatadbcs==(char*)-1)	//save required            //~v74ER~//~vafkR~
	if (Ppswk->SWsvdatadbcs==(char*)(ULPTR)-1)	//save required    //~vafkI~
    {                                                              //~v74EI~
	    tgtlen=Pplh->ULHlen;                                       //~v74EI~
    	if (Pbndsoffs1<tgtlen)	//target has bnds data             //~v74EI~
        {                                                          //~v74EI~
            if (Pbndsoffs2 && Pbndsoffs2<tgtlen)                   //~v74EI~
    	        savelen=Pbndsoffs2-Pbndsoffs1;                     //~v74ER~
            else                                                   //~v74EI~
            	savelen=tgtlen-Pbndsoffs1;                         //~v74EI~
	        len=savelen+savelen;                                   //~v74ER~
    	    savedata=umalloc((UINT)len);                                 //~v74EI~
        	UALLOCCHK(savedata,UALLOC_FAILED);                     //~v74EI~
	        pc=savedata;                                           //~v74EI~
    	    pcd=savedata+savelen;                                  //~v74EI~
            memcpy(pc,Pplh->ULHdata+Pbndsoffs1,(UINT)savelen);     //~v74EI~
            memcpy(pcd,Pplh->ULHdbcs+Pbndsoffs1,(UINT)savelen);    //~v74EI~
            chartabclear(pcd,savelen);	//clear all tab            //~v74EI~
          if (!(Ssortothopt & SOPT_SBCS))                          //~va8iI~
          {                                                        //~va8iI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			xesub_setdbcssplit(swebcfile,0/*plh*/,pc,pcd,savelen,' ');//~va50I~
#else                                                              //~va50I~
			setdbcssplit(pc,pcd,savelen,' ');                      //~v74EI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          }                                                        //~va8iI~
        }                                                          //~v74EI~
        else                                                       //~v74EI~
        {                                                          //~v74EI~
            savelen=0;                                             //~v74EI~
            savedata=0;                                            //~v74EI~
        }                                                          //~v74EI~
        savesw=1;                                                  //~v74EI~
    }                                                              //~v74EI~
    pswksave=Ppswk0+Ppswk->SWseq-1;                                //~v74EI~
//	if (pswksave->SWsvdatadbcs==(char*)-1)	//source line not replaced//~v74EI~//~vafkR~
	if (pswksave->SWsvdatadbcs==(char*)(ULPTR)-1)	//source line not replaced//~vafkI~
    {                                                              //~v74EI~
        srclen=Ppswk->SWlen;                                       //~v74EI~
        if (Pbndsoffs1<srclen) //source has bnds data              //~v74EI~
        {                                                          //~v74EI~
            if (Pbndsoffs2 && Pbndsoffs2<srclen)                   //~v74ER~
                copylen=Pbndsoffs2-Pbndsoffs1;                     //~v74EI~
            else                                                   //~v74EI~
                copylen=srclen-Pbndsoffs1;                         //~v74EI~
            pc=Ppswk->SWdata+Pbndsoffs1;                           //~v74ER~
            pcd=Ppswk->SWdbcs+Pbndsoffs1;                          //~v74ER~
            UCBITON(Pplh->ULHflag2,(Ppswk->SWflag &(ULHF2TABCHKED|ULHF2TABFOUND))); //not 2nd//~v74EI~
//          if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_NOREV,pc,pcd,copylen,Pplh,Pbndsoffs1))>1) //block replace//~v74ER~//~va8hR~
            optcap2=CHAROPBREP|CHARCAP2_NOREV;                     //~va8hI~
          	if (swebcfile)                                         //~va8hI~
            	optcap2|=CHARCAP2_EBCBNDSSORT;		//dbcssplit process for bnds sort//~va8hR~
            if (Ssortothopt & SOPT_SBCS)                           //~va8iI~
            	optcap2|=CHARCAP2_SBCS;		//dbcssplit process for bnds sort//~va8iI~
            if ((rc=charcap2(Ppcw,optcap2,pc,pcd,copylen,Pplh,Pbndsoffs1))>1) //block replace//~va8hI~
                return rc;      //top 1 byte                       //~v74EI~
            chartabclear(Pplh->ULHdbcs+Pbndsoffs1,copylen);	//clear all tab//~v74ER~
          if (!(Ssortothopt & SOPT_SBCS))                          //~va8iI~
          {                                                        //~va8iI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*setdbcstbl will be done at charcap2                             //~va50I~
			xesub_setdbcssplit(swebcfile,0/*plh*/,Pplh->ULHdata+Pbndsoffs1,Pplh->ULHdbcs+Pbndsoffs1,copylen,' ');//~va50I~
#else                                                              //~va50I~
			setdbcssplit(Pplh->ULHdata+Pbndsoffs1,Pplh->ULHdbcs+Pbndsoffs1,copylen,' ');//~v74ER~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          }                                                        //~va8iI~
        }                                                          //~v74EI~
        else                                                       //~v74EI~
        	copylen=0;                                             //~v74EI~
		pswksave->SWsvdatadbcs=0;	//no need to save data         //~v74EI~
    }                                                              //~v74EI~
    else					//SWdata is saved then replaced        //~v74EI~
    {                                                              //~v74EI~
        copylen=pswksave->SWlen;                                   //~v74ER~
    	if (copylen)	//data save(data exist in bnds range)      //~v74ER~
        {                                                          //~v74EI~
        	pc=pswksave->SWsvdatadbcs;                             //~v74ER~
        	pcd=pc+copylen;                                        //~v74ER~
//  		rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_NOREV,pc,pcd,copylen,Pplh,Pbndsoffs1);//~v74ER~//~va8hR~
            optcap2=CHAROPBREP|CHARCAP2_NOREV;                     //~va8hI~
          	if (swebcfile)                                         //~va8hI~
            	optcap2|=CHARCAP2_EBCBNDSSORT;		//dbcssplit process for bnds sort//~va8hR~
            if (Ssortothopt & SOPT_SBCS)                           //~va8iI~
            	optcap2|=CHARCAP2_SBCS;		//dbcssplit process for bnds sort//~va8iI~
    		rc=charcap2(Ppcw,optcap2,pc,pcd,copylen,Pplh,Pbndsoffs1);//~va8hI~
            ufree(pc);                                             //~v74EI~
        	pswksave->SWsvdatadbcs=0;                              //~v74ER~
        	pswksave->SWlen=0;                                     //~v74EI~
			if (rc>1) //block replace                              //~v74EI~
				return rc;      //top 1 byte                       //~v74EI~
        }                                                          //~v74EI~
    }                                                              //~v74EI~
    if (savesw)                                                    //~v74EI~
    {                                                              //~v74EI~
        Ppswk->SWsvdatadbcs=savedata;                              //~v74EI~
        Ppswk->SWlen=savelen;                                      //~v74EI~
    }                                                              //~v74EI~
    tgtlen=Pplh->ULHlen;                                           //~v74EI~
    if (tgtlen>Pbndsoffs1)                                         //~v74EI~
    {                                                              //~v74EI~
        if (!Pbndsoffs2 || tgtlen<Pbndsoffs2)                      //~v74ER~
            Pplh->ULHlen=Pbndsoffs1+copylen;                       //~v74EI~
        else                                                       //~v74EI~
        {                                                          //~v74EI~
        	width=Pbndsoffs2-Pbndsoffs1;                           //~v74EI~
        	if (copylen<width)                                     //~v74EI~
            {                                                      //~v74EI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            	UCVEBC_memset_space(swebcfile,Pplh->ULHdata+Pbndsoffs1+copylen,(UINT)(width-copylen));//~va50I~
#else                                                              //~va50I~
            	memset(Pplh->ULHdata+Pbndsoffs1+copylen,' ',(UINT)(width-copylen));//~v74EI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            	memset(Pplh->ULHdbcs+Pbndsoffs1+copylen,0,(UINT)(width-copylen));//~v74EI~
            }                                                      //~v74EI~
        }                                                          //~v74EI~
     }                                                             //~v74EI~
            	                                                   //~v74EI~
    return 0;                                                      //~v74EI~
}//fcmdsortbndsupdate                                              //~v74EI~
//**********************************************************************//~va3PI~
//!sortddcmp                                                       //~va3PI~
//adjust dbcs split                                                //~va3PI~
//**********************************************************************//~va3PI~
int sortddcmp(int Poptddcmp,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Pkeypos,int Pcomplen,int Plen1,int Plen2)//~va3PR~
{                                                                  //~va3PI~
	int rc,optddcmp;                                               //~va3PR~
//*************************                                        //~va3PI~
	optddcmp=Poptddcmp;                                            //~va3PI~
    if (Ssortothopt & SOPT_SPLITDBCSEXCLUDE)                       //~va3PR~
        optddcmp|=UTFDDCMPO_SPLITEXC;                              //~va3PI~
    else                                                           //~va3PI~
    if (Ssortothopt & SOPT_SPLITDBCSINCLUDE)                       //~va3PR~
    {                                                              //~va3PI~
        if (Pkeypos)                                               //~va3PI~
            optddcmp|=UTFDDCMPO_SPLITINC0;                         //~va3PR~
        if (Plen1>Pcomplen)                                        //~va3PI~
        	optddcmp|=UTFDDCMPO_SPLITINC1;	//long data1           //~va3PI~
        if (Plen2>Pcomplen)                                        //~va3PI~
        	optddcmp|=UTFDDCMPO_SPLITINC2;  //long data2           //~va3PI~
    }                                                              //~va3PI~
    else                                                           //~va3PI~
	    optddcmp|=UTFDDCMPO_SPLITSPACE;                            //~va3PI~
	rc=xesubddmemcmp(optddcmp,Pdata1+Pkeypos,Pdbcs1+Pkeypos,Pdata2+Pkeypos,Pdbcs2+Pkeypos,Pcomplen);//~va3PI~
    return rc;                                                     //~va3PI~
}//sortddcmp                                                       //~va3PI~
//**********************************************************************
//!sortlinecomp
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int sortlinecomp(const void *ent1,const void *ent2)
{
	int rc,rc1,rc2,reslen1,reslen2,minreslen,complen;              //~v10IR~
    PSORTWK pswk1,pswk2;                                           //~v10IR~
    int     len1,len2,*pkey,keypos,ii,keylen,opt;                  //~v10IR~
    UCHAR   *data1,*data2;
    int getnumrc1,getnumrc2,datatype=0;                            //~v62ER~
//  long    lvt1[4],lvt2[4];                                       //~v62EI~//~vafkR~
    SLPTR   lvt1[4],lvt2[4];                                       //~vafkI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR   *dbcs1,*dbcs2;                                         //~va20I~
    int optddcmp;                                                  //~va20I~
#endif                                                             //~va20I~
//*****************
    Smatchkeycnt=-1;	//samekey pos(1 start)                     //~v17jR~
//	pswk1=(PSORTWK)(ULONG)ent1;                                    //~v54YR~//~vafkR~
	pswk1=(PSORTWK)(ULPTR)ent1;                                    //~vafkI~
//	pswk2=(PSORTWK)(ULONG)ent2;                                    //~v54YR~//~vafkR~
  	pswk2=(PSORTWK)(ULPTR)ent2;                                    //~vafkI~
    data1=pswk1->SWdata;                                           //~v10IR~
    data2=pswk2->SWdata;                                           //~v10II~
#ifdef UTF8UCS2                                                    //~va20I~
    dbcs1=pswk1->SWdbcs;                                           //~va20I~
    dbcs2=pswk2->SWdbcs;                                           //~va20I~
#endif                                                             //~va20I~
    len1=pswk1->SWlen;                                             //~v10IR~
    len2=pswk2->SWlen;                                             //~v10II~
    pkey=&Skeypost[0];
    for (ii=0;ii<Skeyctr;ii++)                                     //~v10IR~
    {
    	keypos=*pkey++;
    	keylen=*pkey++;
    	opt   =*pkey++;                                            //~v10II~
    	if (opt &SOPT_REV)                                         //~v10II~
        {	                                                       //~v10II~
        	rc1=1;		//when 1<2,reverse rc		               //~v10II~
            rc2=-1;     //when 1>2 reverse rc                      //~v10II~
        }                                                          //~v10II~
        else                                                       //~v10II~
        {                                                          //~v10II~
        	rc1=-1;		//when 1<2                                 //~v10II~
            rc2=1;       //when 1>2                                //~v10IR~
        }                                                          //~v10II~
		reslen1=len1-keypos;                                       //~v10IM~
		reslen2=len2-keypos;                                       //~v10IM~
                                                                   //~v17jI~
        if (reslen2>0)                                             //~v17jI~
    		Smatchkeycnt=ii;	//id of compared but may break     //~v17jI~
                                                                   //~v17jI~
    	if (reslen1<=0)     //1 is short                           //~v10IR~
        {                                                          //~v54YI~
        	if (reslen2>0) //2 is in range                         //~v10IR~
            	return rc1;	//1<2                                  //~v10IR~
            else            //both short
            	continue;
        }//reslen1                                                 //~v54YI~
//1 is in range
        if (reslen2<=0) //2 is short                               //~v10IR~
            return  rc2;  //1>2                                    //~v10IR~
//both is in range
      if (opt & SOPT_NUMERIC)                                      //~v62EI~
      {                                                            //~v62EI~
        complen=min(reslen1,keylen);                               //~v62EI~
#ifdef UTF8UCS2                                                    //~va20I~
//*no handle required for numeric data(digit is common for all ebcdic translater)//~va50I~
//  	getnumrc1=tc_getlinedata(0,&datatype,data1+keypos,dbcs1+keypos,complen,lvt1);//~va20I~//~va79R~
    	getnumrc1=tc_getlinedata(0,0/*handle*/,&datatype,data1+keypos,dbcs1+keypos,complen,lvt1);//~va79I~
#else                                                              //~va20I~
		getnumrc1=tc_getlinedata(0,&datatype,data1+keypos,complen,lvt1);//~v62ER~
#endif                                                             //~va20I~
        complen=min(reslen2,keylen);                               //~v62EI~
#ifdef UTF8UCS2                                                    //~va20I~
//  	getnumrc2=tc_getlinedata(0,&datatype,data2+keypos,data2+keypos,complen,lvt2);//~va20I~//~va79R~
    	getnumrc2=tc_getlinedata(0,0/*handle*/,&datatype,data2+keypos,data2+keypos,complen,lvt2);//~va79I~
#else                                                              //~va20I~
		getnumrc2=tc_getlinedata(0,&datatype,data2+keypos,complen,lvt2);//~v62ER~
#endif                                                             //~va20I~
    	if (getnumrc1)     //1 numeric err                         //~v62EI~
        {                                                          //~v62EI~
        	if (!getnumrc2) //1 err,2 numeric ok                   //~v62ER~
            	return -1;	//err1,always top                      //~v62EI~
            else            //both err                             //~v62EI~
            	continue;	//later lineno chk                     //~v62ER~
        }//1 numeric err                                           //~v62EI~
        if (getnumrc2) //2 numeric err                             //~v62EI~
            return  1;  	//1>2                                  //~v62ER~
        opt=0;		//no overflow                                  //~v62EI~
		rc=ucalc_binop(opt,'?',lvt1,lvt2);                         //~v62EI~
        if (!rc)                                                   //~v62EI~
        {                                                          //~v62EI~
            Smatchkeycnt=ii+1;                                     //~v62EI~
            continue;                                              //~v62EI~
        }                                                          //~v62EI~
      }                                                            //~v62EI~
      else  //string compare                                       //~v62EI~
      {                                                            //~v62EI~
        minreslen=min(reslen1,reslen2);
        complen=min(minreslen,keylen);
//      data1+=keypos;                                             //~v131R~
//      data2+=keypos;                                             //~v131R~
#ifdef UTF8UCS2                                                    //~va20I~
      if (Ssortu8)	//utf8 file sort                               //~va20I~
      {                                                            //~va20I~
        optddcmp=XESUBDDSCO_HIGHLOW;                               //~va20I~
        if (!(opt & SOPT_CASE))                                    //~va20I~
//      	optddcmp=XESUBDDSCO_NOCASE;                            //~va3NR~
        	optddcmp|=XESUBDDSCO_NOCASE;                           //~va3NI~
//  	rc=xesubddmemcmp(optddcmp,data1+keypos,dbcs1+keypos,data2+keypos,dbcs2+keypos,complen);//~va3PR~
    	rc=sortddcmp(optddcmp,data1,dbcs1,data2,dbcs2,keypos,complen,reslen1,reslen2);//~va3PR~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
      {                                                            //~va20I~
        if (opt & SOPT_CASE)                                       //~v10IR~
//      	rc=memcmp(data1,data2,(UINT)complen);                  //~v131R~
        	rc=memcmp(data1+keypos,data2+keypos,(UINT)complen);    //~v131I~
        else
//      	rc=memicmp(data1,data2,(UINT)complen);                 //~v131R~
        	rc=memicmp(data1+keypos,data2+keypos,(UINT)complen);   //~v131I~
      }                                                            //~va20I~
        if (!rc)                                                   //~v10IR~
        {                                                          //~v10II~
	        if (complen==keylen)                                   //~v10II~
            {                                                      //~v172I~
            	Smatchkeycnt=ii+1;                                 //~v172I~
    	    	continue;                                          //~v10II~
			}                                                      //~v172I~
	        rc=(reslen1-reslen2);                                  //~v10II~
		}                                                          //~v10II~
      }//string compare                                            //~v62EI~
        if (rc)                                                    //~v10II~
        {                                                          //~v10II~
        	if (rc1>0)	//reverse                                  //~v10II~
            	rc=-rc;                                            //~v10II~
        	return rc;                                             //~v10IM~
		}                                                          //~v10II~
        Smatchkeycnt=ii+1;      //short but same len and value case//~v172I~
    }//all key                                                     //~v10IR~
//all key comp rc=0
    return pswk1->SWseq -  pswk2->SWseq;                           //~v10IR~
}//sortlinecomp
#endif                                                             //~v50JI~
//**************************************************************** //~v11NI~
// display column gauge                                            //~v11NI~
//*rc                                                              //~v11NI~
//**************************************************************** //~v11NI~
int func_col(PUCLIENTWE Ppcw)                                      //~v11NI~
{                                                                  //~v11NI~
#define COLS_SET_DEFAULT   "ALL"                                   //~v74yI~
    PUFILEC pfc;                                                   //~v11NI~
    PUFILEH pfh;                                                   //~v78rI~
    UCHAR  parmtype[MAXCOLSTYPNM+1],*pfctype,*pnewtype,*pc;        //~v447R~
    int rc,fhlno,fhlnon,opdno,ii;                                  //~v11NI~
//*********************************                                //~v11NI~
	pfc=Ppcw->UCWpfc;                                              //~v11NI~
    pfh=pfc->UFCpfh;                                               //~v78rR~
    fhlno=Ppcw->UCWfilehdrlineno;                                  //~v11NI~
    pfctype=pfc->UFCcolstype;                                      //~v11NI~
                                                                   //~v11NI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v11NI~
    pc=Ppcw->UCWopdpot;                                            //~v11NI~
    if (pc && *pc=='?')                                            //~v74yR~
    {                                                              //~v74yI~
    	uerrmsg("COL [on|off] [ALL|type]",0);                      //~v74yI~
        return 0;                                                  //~v74yI~
    }                                                              //~v74yI~
    if (opdno>2)                                                   //~v11NI~
    	return errtoomany();                                       //~v11NI~
//operand chk                                                      //~v11NI~
	parmtype[0]=0;				//id of type input                 //~v11NR~
    fhlnon=0;					//id of on/off                     //~v11NI~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v11NI~
	{                                                              //~v11NI~
    	if (!stricmp(pc,"ON"))                                     //~v11NI~
        	fhlnon=FILEHDRLINENO+1;                                //~v11NR~
        else                                                       //~v11NI~
    	if (!stricmp(pc,"OFF"))                                    //~v11NI~
        	fhlnon=FILEHDRLINENO;                                  //~v11NR~
        else                                                       //~v11NI~
        	if (parmtype[0])                                       //~v11NI~
                return errinvalid(pc);                             //~v11NI~
            else                                                   //~v11NI~
            {                                                      //~v11NI~
    			if (strlen(pc)>MAXCOLSTYPNM)                       //~v447R~
    			{                                                  //~v447I~
    				uerrmsg("too long COL type name(max=%d)",      //~v447I~
        					"COL タイプ名が長すぎる(最大%d)",      //~v447I~
                			MAXCOLSTYPNM);                         //~v447I~
        			return 4;                                      //~v447I~
			    }                                                  //~v447I~
            	strncpy(parmtype,pc,MAXCOLSTYPNM);                 //~v447R~
                parmtype[MAXCOLSTYPNM]=0;                          //~v447R~
			}                                                      //~v11NI~
	}//by opdno                                                    //~v11NI~
    if (!fhlnon)		//no ON or OFF                             //~v11NI~
    {                                                              //~v54YI~
    	if (parmtype[0])	//type change req,off->on,on-->on      //~v11NR~
            fhlnon=FILEHDRLINENO+1;             //toggle to on     //~v11NI~
        else                                                       //~v11NI~
            if (fhlno==FILEHDRLINENO)                              //~v11NI~
                fhlnon=FILEHDRLINENO+1;             //toggle to on //~v11NI~
            else                                                   //~v11NI~
                fhlnon=FILEHDRLINENO;                              //~v11NI~
    }//fhlnon                                                      //~v54YI~
  if (!stricmp(parmtype,COLS_SET_DEFAULT))                         //~v74yI~
  {                                                                //~v74yI~
                                                                   //~v74yI~
    if (fhlnon>FILEHDRLINENO)   //on                               //~v74yI~
    {                                                              //~v74yI~
    	UCBITON(Gopt5,GOPT5COLSON);                                //~v74yI~
        pc="ON";                                                   //~v74yI~
    }                                                              //~v74yI~
    else                                                           //~v74yI~
    {                                                              //~v74yI~
    	UCBITOFF(Gopt5,GOPT5COLSON);                               //~v74yI~
        pc="OFF";                                                  //~v74yI~
    }                                                              //~v74yI~
    uerrmsg("From next time all files are opened by \"COLS %s\".", //~v74yI~
        	"次に開くファイルから全て\"COL %s\"になります。",      //~v74yI~
            pc);                                                   //~v74yI~
  }                                                                //~v74yI~
  else                                                             //~v74yI~
  {                                                                //~v74yI~
//change process                                                   //~v11NI~
    if (fhlnon>FILEHDRLINENO)   //cols data required               //~v11NI~
    {                                                              //~v11NI~
        pnewtype=0;                                                //~v11NR~
        if (parmtype[0])        //type change req                  //~v11NR~
            if (*pfctype)       //already set                      //~v11NR~
            {                                                      //~v11NR~
//file may changed if (stricmp(pfctype,parmtype))  //changed       //~v21rR~
                    pnewtype=parmtype;                             //~v11NR~
            }                                                      //~v11NR~
            else                                //1st time         //~v11NR~
                pnewtype=parmtype;                                 //~v11NR~
        else                                                       //~v11NR~
        {                                                          //~v75FI~
//          if (!*pfctype)      //not currently set;               //~v61aR~
//                               xline option may changed ,do always//~v61aI~
            if (opdno) //ON operand specified(force to default)    //~v75FR~
//              pnewtype=(UCHAR*)(-1);              //default alloc//~v11NR~//~vafkR~
                pnewtype=(UCHAR*)(ULPTR)(-1);              //default alloc//~vafkI~
            else       //no operand                                //~v75FI~
            	if (!*pfctype || !UCBITCHK(pfc->UFCflag2,UFCF2NOTDEFCOLS))	//current is default//~v75FR~
//	                pnewtype=(UCHAR*)(-1);              //re-set defaul for the case xline option changed//~v75FI~//~vafkR~
	                pnewtype=(UCHAR*)(ULPTR)(-1);              //re-set defaul for the case xline option changed//~vafkI~
        }                                                          //~v75FI~
        if (pnewtype)                                              //~v11NR~
            if ((rc=fcmdcolalloc(pfc,pnewtype))!=0)                //~v11NR~
                return rc;                                         //~v11NR~
    }                                                              //~v11NI~
    else                                                           //~v11NI~
    	if (parmtype[0])	//type with off                        //~v11NI~
        {                                                          //~v11NI~
            uerrmsg("type(%s) is invalid with OFF",0,              //~v11NR~
                    parmtype);                                     //~v11NI~
            return 4;                                              //~v11NI~
        }                                                          //~v11NI~
	fcmdprofupdaterecord(FPURO_COLS,pfh->UFHfilename,              //~v78rR~
            				(UCBITCHK(pfc->UFCflag2,UFCF2NOTDEFCOLS)?pfc->UFCcolstype:0),//~v78rI~
							(fhlnon>FILEHDRLINENO),0/*intval2*/);  //~v78rI~
    Ppcw->UCWfilehdrlineno=fhlnon;		//update                   //~v11NI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);	//after curtop changed chk //~v11NR~
 }                                                                 //~v74yI~
    return 0;                                                      //~v11NI~
}//func_col                                                       //~v11NI~//~va50R~
//**************************************************************** //~v11NI~
// free cols data                                                  //~v11NI~
//*rc                                                              //~v11NI~
//**************************************************************** //~v11NI~
void fcmdcolfree(PUFILEC Ppfc)                                     //~v11NR~
{                                                                  //~v11NI~
//*********************************                                //~v11NI~
	if (Ppfc->UFCcolsdata)                                         //~v11NR~
		ufree(Ppfc->UFCcolsdata);                                  //~v11NI~
	Ppfc->UFCcolsdata=0;                                           //~v11NI~
	Ppfc->UFCcolstype[0]=0;                                        //~v11NI~
    return;                                                        //~v11NI~
}//fcmdcolfree                                                     //~v11NI~
//**************************************************************** //~v11NI~
// alloc cols data                                                 //~v11NI~
//*parm1:pfc                                                       //~v11NI~
//*parm2:3 byte cols type addr,-1 for default                      //~v11NI~
//*rc  :0 or UALLOC_FAILED or 4 open err                           //~v11NR~
//**************************************************************** //~v11NI~
int fcmdcolalloc(PUFILEC Ppfc,UCHAR *Ptype)                        //~v11NI~
{                                                                  //~v11NI~
static UCHAR *Sgaugepat="....+....1";                              //~v11NR~
static UCHAR *Sgaugepatb="........+.......";                       //~v446R~
static UCHAR *Sgaugepath=". . . . ";                               //~v446R~
    PUFILEH pfh;                                                   //~v446I~
	FILE          *fh;                                             //~v11NR~
	FILEFINDBUF3  fstat3;                                          //~v11NI~
//	UCHAR fpath[_MAX_PATH],fnm[16],*colsdata,*pc;                  //~v74CR~
  	UCHAR fpath[_MAX_PATH],fnm[13+MAXCOLSTYPNM],*colsdata,*pc;     //~v74CR~
    UCHAR wk[8],*ptypenm;                                          //~v11NR~
    UCHAR *pc2;                                                    //~v21rI~
    int ii,jj,len,rc,sz,len2=0,wlen,dlen;                          //~v45xR~
    int areasz,tscnt;                                              //~v21rR~
    int htop,hend=0,width;                                           //~v446I~//~vafcR~
#define TAB_STOP_CHAR   '*'                                        //~v21rI~
#define MAX_TABSTOP    ((MAX_HEXBIN_WIDTH/4)+2) // 20              //~v44bR~
    int tabstoppos[MAX_TABSTOP+1];  //count and positions          //~v21rI~
    int opt;                                                       //~va0pI~
//*********************************                                //~v11NI~
    pfh=Ppfc->UFCpfh;                                              //~v446I~
//	if (Ptype==(UCHAR*)(-1))	//default                          //~v11NI~//~vafkR~
	if (Ptype==(UCHAR*)(ULPTR)(-1))	//default                      //~vafkI~
    {                                                              //~v75FI~
      if (UCBITCHK(pfh->UFHflag4,UFHF4BIN)) //bin file             //~v446I~
       if (UCBITCHK(pfh->UFHflag5,UFHF5HEX)) //bin file            //~v446I~
		ptypenm=DEFAULT_COLSTYPEH;				//default alloc    //~v446I~
       else                                                        //~v446I~
        if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                  //~v61aI~
		ptypenm=DEFAULT_COLSTYPEB;				//default alloc    //~v446I~
        else                                                       //~v61aI~
		ptypenm=DEFAULT_COLSTYPE;				//default alloc    //~v61aI~
      else                                                         //~v446I~
        if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                  //~v61aI~
		ptypenm=DEFAULT_COLSTYPEB;				//default alloc    //~v61aI~
        else                                                       //~v61aI~
		ptypenm=DEFAULT_COLSTYPE;				//default alloc    //~v11NI~
    	UCBITOFF(Ppfc->UFCflag2,UFCF2NOTDEFCOLS);	//reset not default//~v75FR~
    }                                                              //~v75FI~
    else                                                           //~v11NI~
    {                                                              //~v75FI~
    	ptypenm=Ptype;                                             //~v11NI~
    	UCBITON(Ppfc->UFCflag2,UFCF2NOTDEFCOLS);	//set not default//~v75FR~
    }                                                              //~v75FI~
//search file                                                      //~v11NI~
	sprintf(fnm,"::%s.%s",COLS_FNAME,ptypenm);                     //~v11NR~
//	if (Ptype==(UCHAR*)(-1))	//default                          //~va0pR~//~vafkR~
	if (Ptype==(UCHAR*)(ULPTR)(-1))	//default                      //~vafkI~
        opt=FFNONFMSG;  //issue no notfound msg                    //~va0pR~
    else                                                           //~va0pI~
		opt=FFMSG;      //issue err msg                            //~va0pR~
//	if ((rc=filefind(fnm,fpath,&fstat3,FFMSG))!=0)                 //~va0pR~
  	if ((rc=filefind(fnm,fpath,&fstat3,opt))!=0)                   //~va0pI~
    {                                                              //~v11NI~
//		if (Ptype!=(UCHAR*)(-1))	//default                      //~v11NI~//~vafkR~
		if (Ptype!=(UCHAR*)(ULPTR)(-1))	//default                  //~vafkI~
        	return 4;                                              //~v11NI~
//      ugeterrmsg();   //clear errmsg                             //~va0pR~
    	len=MAXLINEDATA+1;                                         //~v11NR~
	}                                                              //~v11NI~
    else                                                           //~v11NI~
    {                                                              //~v11NI~
		len=(int)fstat3.cbFile;                                    //~v11NR~
    	if (len>MAXLINEDATA)                                       //~v11NR~
    		len=MAXLINEDATA;                                       //~v11NR~
	}                                                              //~v11NI~
//alloc line data                                                  //~v11NM~
//  colsdata=umalloc((UINT)len);                                   //~v21rR~
//  areasz=len+sizeof(tabstoppos)+1;//tabstop data after cols data //~v21rI~//+vb30R~
    areasz=len+(int)sizeof(tabstoppos)+1;//tabstop data after cols data//+vb30I~
    colsdata=umalloc((UINT)areasz);//tabstop data after cols data  //~v21rI~
    UALLOCCHK(colsdata,UALLOC_FAILED);                             //~v11NI~
    memset(colsdata,0,(UINT)areasz);                               //~v40bR~
//read cols data                                                   //~v11NI~
	if (rc)			//file not found                               //~v11NI~
    {                                                              //~v446I~
//    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN)) //bin file             //~v61aR~
      if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                    //~v61aR~
      {                                                            //~v446I~
      	width=pfh->UFHwidth;                                       //~v446I~
      	if (UCBITCHK(pfh->UFHflag5,UFHF5HEX)) //hex display        //~v446I~
			filegethposrange(pfh,width,&htop,&hend);               //~v446I~
        else                                                       //~v446I~
        	htop=0;                                                //~v446I~
        if (htop)		//hex disply                               //~v446I~
        	dlen=min(width,len);                                   //~v446I~
        else                                                       //~v446I~
        	dlen=len;                                              //~v446R~
        wlen=16;                                                   //~v446I~
        for (pc=colsdata,ii=0;ii<dlen;ii+=len2,pc+=len2)           //~v446I~
        {                                                          //~v446I~
        	len2=min(wlen,dlen-ii);                                //~v446I~
        	memcpy(pc,Sgaugepatb,(UINT)len2);                      //~v45xR~
            sprintf(wk,"%04X",ii);                                 //~v446R~
            *pc=*(wk+2);                                           //~v446I~
        }                                                          //~v446I~
        if (htop && htop<len)	//hex display has space            //~v446I~
        {                                                          //~v446I~
//        	len2=(int)(htop-((ULONG)pc-(ULONG)colsdata));	//written len//~v45xR~//~vafkR~
//      	len2=(int)(htop-((ULPTR)pc-(ULPTR)colsdata));	//written len//~vafkI~//+vb30R~
        	len2=htop-PTRDIFF(pc,colsdata);	//written len          //+vb30I~
            if (len2)                                              //~v44bI~
            {                                                      //~v44bI~
//*cols line is not data line,no need to tarns to ebc              //~va50I~
            	memset(pc,' ',(UINT)len2);                         //~v45xR~
//              *(pc+len2-1)=TAB_STOP_CHAR;                        //~v44dR~
                *(pc+len2-1)=HEX_INTSPACE;                         //~v44dI~
            }                                                      //~v44bI~
            hend=min(len,hend);                                    //~v446I~
            dlen=hend-htop;                                        //~v446I~
            wlen=8;                                                //~v446I~
            for (pc+=len2,ii=0,jj=0;ii<dlen;jj+=wlen)              //~v446I~
            {                                                      //~v446I~
                len2=min(wlen,dlen-ii);                            //~v446I~
                if (len2>=2)                                       //~v446R~
                {                                                  //~v446I~
                    memcpy(pc,Sgaugepath,(UINT)len2);              //~v45xR~
                    sprintf(wk,"%04X",(UINT)jj>>1);                //~v44dR~
                    *pc=*(wk+2);                                   //~v446R~
                    *(pc+1)=*(wk+3);                               //~v446I~
                }//len>2                                           //~v446M~
                pc+=len2;                                          //~v446R~
                ii+=len2;                                          //~v446R~
                if (ii<dlen)                                       //~v446R~
                {                                                  //~v446R~
//                  *pc++=TAB_STOP_CHAR;                           //~v44dR~
                    *pc++=HEX_INTSPACE;                            //~v44dI~
                    ii++;                                          //~v446R~
                }                                                  //~v446R~
            }                                                      //~v446I~
//          len=(int)((ULONG)pc-(ULONG)colsdata);  //colsdatalen   //~v45xR~//~vafkR~
            len=(int)((ULPTR)pc-(ULPTR)colsdata);  //colsdatalen   //~vafkI~
        }//hex part space                                          //~v446I~
      }                                                            //~v446I~
      else	//text file                                            //~v446I~
        for (pc=colsdata,ii=0;ii<len;ii+=10,pc+=10)                //~v11NI~
        {                                                          //~v11NI~
        	memcpy(pc,Sgaugepat,10);                               //~v11NI~
            sz=sprintf(wk,"%d",ii/10+1);                           //~v11NI~
            memcpy(pc+10-sz,wk,(UINT)sz);                          //~v11NR~
        }                                                          //~v11NI~
    }                                                              //~v446I~
    else                                                           //~v11NI~
    {                                                              //~v11NI~
        if (!(fh=fileopen(fpath,"r")))                             //~v571R~
        {                                                          //~v11NR~
            ufree(colsdata);                                       //~v11NR~
            return 4;                                              //~v11NR~
        }                                                          //~v11NR~
        if (!fgets(colsdata,len,fh))//null if error/ eof           //~v11NR~
        {                                                          //~v11NR~
            uerrmsg("%s COL data read faileed",0,                  //~v11NR~
                    fnm);                                          //~v11NR~
            ufree(colsdata);                                       //~v11NR~
            return 4;                                              //~v11NR~
        }                                                          //~v11NR~
        if ((pc=memchr(colsdata,'\n',(UINT)len))!=0)               //~v11NR~
        {                                                          //~v74BI~
        	*pc=0;                                                 //~v11NI~
            if (pc>colsdata && *(pc-1)=='\r')                      //~v74BI~
	        	*(pc-1)=0;                                         //~v74BI~
        }                                                          //~v74BI~
        len=(int)strlen(colsdata);                                 //~v11NR~
        fileclose(fpath,fh);                                       //~v571R~
    }//default or file                                             //~v44bI~
        for (tscnt=0,pc=colsdata;;)                                //~v21rI~
        {                                                          //~v21rI~
        	if (!(pc2=strchr(pc,TAB_STOP_CHAR)))                   //~v21rR~
            	break;                                             //~v21rI~
            if (tscnt>=MAX_TABSTOP)                                //~v21rI~
            {                                                      //~v21rI~
                uerrmsg("tab stop pos over max(%d) is ignored",0,  //~v21rI~
                        MAX_TABSTOP);                              //~v21rI~
            	break;                                             //~v21rM~
            }                                                      //~v21rI~
            tscnt++;                                               //~v21rI~
//          tabstoppos[tscnt]=(int)((ULONG)pc2-(ULONG)colsdata);   //~v21rI~//~vafkR~
            tabstoppos[tscnt]=(int)((ULPTR)pc2-(ULPTR)colsdata);   //~vafkI~
            pc=pc2+1;                                              //~v21rI~
        }                                                          //~v21rI~
        tabstoppos[0]=tscnt;                                       //~v21rI~
//      memcpy(colsdata+len+1,tabstoppos,(UINT)((tscnt+1)*sizeof(int)));//~v40bR~//+vb30R~
        memcpy(colsdata+len+1,tabstoppos,(size_t)(tscnt+1)*sizeof(int));//+vb30I~
//  }//default or file                                             //~v44bR~
//save to pfc                                                      //~v11NI~
    fcmdcolfree(Ppfc);	//free if previous exist                   //~v11NR~
	strncpy(Ppfc->UFCcolstype,ptypenm,MAXCOLSTYPNM);               //~v447R~
	Ppfc->UFCcolsdatalen=len;                                      //~v11NI~
	Ppfc->UFCcolsdata=colsdata;                                    //~v11NI~
    return 0;                                                      //~v11NI~
}//fcmdcolalloc                                                    //~v11NI~
//**************************************************************** //~v74yI~
// initial cols option process(called from fileregist)             //~v74yI~
// ret:1:initial col set ok,4:err                                  //~v74yI~
//**************************************************************** //~v74yI~
int fcmdinitialcols(PUCLIENTWE Ppcw,PUFILEC Ppfc,PUFILEH Ppfh)     //~v74yR~
{                                                                  //~v74yI~
    UCHAR *pcolstype;                                              //~v78rR~
    int profcols=0;                                                //~v78rR~
//*********************************                                //~v74yI~
    if (Ppfh->UFHprofile & FPURO_COLS)  //profile cols on          //~v78rI~
    {                                                              //~v78rI~
  		if (Ppfh->UFHprofile & FPURO_COLSDEF)  //profile cols on   //~v78rI~
//          pcolstype=(UCHAR*)(-1);                                //~v78rI~//~vafkR~
            pcolstype=(UCHAR*)(ULPTR)(-1);                         //~vafkI~
        else                                                       //~v78rI~
    	if (*Ppfh->UFHcolstype)                                    //~v78rR~
    		pcolstype=Ppfh->UFHcolstype;                           //~v78rR~
        else                                                       //~v78rR~
//          pcolstype=(UCHAR*)(-1);                                //~v78rR~//~vafkR~
            pcolstype=(UCHAR*)(ULPTR)(-1);                         //~vafkI~
		if (fcmdcolalloc(Ppfc,pcolstype))                          //~v78rR~
    		return 4;                                              //~v78rR~
        profcols=1;                                                //~v78rR~
    }                                                              //~v78rI~
  if (!profcols)                                                   //~v78rI~
  {                                                                //~v78rI~
    if (!UCBITCHK(Gopt5,GOPT5COLSON))                              //~v74yI~
    	return 0;                                                  //~v74yI~
//	if (fcmdcolalloc(Ppfc,(UCHAR*)-1))                             //~v74yR~//~vafkR~
	if (fcmdcolalloc(Ppfc,(UCHAR*)(ULPTR)-1))                      //~vafkI~
    	return 4;                                                  //~v74yI~
  }                                                                //~v78rI~
    Ppcw->UCWfilehdrlineno=FILEHDRLINENO+1;                        //~v74yI~
    return 1;                                                      //~v74yI~
}//fcmdinitialcols                                                 //~v74yI~
//**************************************************************** //~v45xI~
// fcmdgetlabparm                                                  //~v45xI~
// process label parm only                                         //~v45xI~
//parm1:pcw                                                        //~v45xI~
//parm2:pfh or 0 if pfh from pcw                                   //~v62HI~
//parm3:start plh                                                  //~v62HR~
//parm4:end plh(if opt=0) or next of endplh(if opt=1)              //~v62HR~
//      2 chk split line                                           //~v45xI~
//parm5:opt                                                        //~v62HR~
//*rc   :0                                                         //~v45xI~
//**************************************************************** //~v45xI~
//int fcmdgetlabparm(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Popt)//~v62HR~
int fcmdgetlabparm(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh1,PULINEH *Ppplh2,int Popt)//~v62HI~
{                                                                  //~v45xI~
#define MAXLABEL 2                                                 //~v45xI~
    PUFILEH pfh;                                                   //~v45xI~
    PULINEH labplh[2];                                             //~v45xI~
    UPODELMTBL *podt;                                              //~v45xI~
    char *pc;                                                      //~v45xI~
    int  opdno,ii,labtctr=0,rc;                                    //~v45xI~
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1],*plabt;//label opd from/to //~v45xI~
//*********************************                                //~v45xI~
  if (!(pfh=Ppfh))                                                 //~v62HI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v45xI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v45xI~
    plabt=&labt[0][0];                                             //~v45xI~
    pc=Ppcw->UCWopdpot;                                            //~v45xI~
    podt=Ppcw->UCWopddelmt;                                        //~v45xI~
    for (ii=0;ii<opdno;ii++)                                       //~v45xI~
    {                                                              //~v45xI~
        if (*pc==ULCCMDLABEL   //lebel specified                   //~v45xR~
//      &&  (*(pc+1)!='/'&&*(pc+1)!='\\')                          //~v582R~
        &&  (*(pc+1)!='/'&&*(pc+1)!='\\'&&*(pc+1)!=ULCCMDLABEL)    //~v582R~
        &&  !podt->upoquate)        //not in quate                 //~v45xI~
        {                                                          //~v45xI~
            if (labtctr==MAXLABEL)                                 //~v45xI~
                return fcmdlabelerr("Too many");                   //~v45xI~
            strncpy(plabt,pc,ULHLINENOSZ);                         //~v45xI~
            plabt+=ULHLINENOSZ+1;                                  //~v45xI~
            labtctr++;                                             //~v45xI~
        }                                                          //~v45xI~
        pc+=strlen(pc)+1;                                          //~v45xI~
        podt++;                                                    //~v45xI~
    }                                                              //~v45xI~
    rc=0;                                                          //~v45xI~
	if (labtctr)                                                   //~v45xI~
    {                                                              //~v45xI~
        if (labtctr!=MAXLABEL)                                     //~v45xI~
            return fcmdlabelerr("Need From and To");               //~v45xI~
    	rc=fcmdgetlabelrange(pfh,labtctr,labt,labplh,(Popt & FCGLP_NEXTPLH));//~v45xR~
        *Ppplh1=labplh[0];                                         //~v45xI~
        *Ppplh2=labplh[1];                                         //~v45xI~
        if (!rc)                                                   //~v45xI~
            if (Popt & FCGLP_SPLITCHK)   //chk if label is on spli line//~v45xR~
            {                                                      //~v45xR~
                if (UCBITCHK((*Ppplh1)->ULHflag2,ULHF2SPLIT2)) //top is followed//~v45xR~
                {                                                  //~v45xR~
                    uerrmsg("start the range by top of splitlines",//~v45xR~
                            "分割行はその先頭行から範囲指定してください。");//~v45xR~
                    return 4;                                      //~v45xR~
                }                                                  //~v45xR~
                if (UCBITCHK((*Ppplh2)->ULHflag2,ULHF2SPLIT2)) //next is followed//~v45xR~
                {                                                  //~v45xR~
                    uerrmsg("end the range by last of splitlines", //~v45xR~
                            "分割行はその末尾行までを範囲指定してください。");//~v45xR~
                    return 4;                                      //~v45xR~
                }                                                  //~v45xR~
            }//chk option                                          //~v45xR~
    }                                                              //~v45xI~
    else                                                           //~v45xI~
    {                                                              //~v45xI~
      if (Popt & FCGLP_0IFNOLAB)     //set 0 if no label is detected//~v54YI~
      {                                                            //~v54YI~
        *Ppplh1=0;                                                 //~v54YI~
        *Ppplh2=0;                                                 //~v54YI~
      }                                                            //~v54YI~
      else                                                         //~v54YI~
      {                                                            //~v54YI~
        *Ppplh1=UGETQTOP(&pfh->UFHlineque);//search from first     //~v45xR~
        *Ppplh2=UGETQEND(&pfh->UFHlineque);//search from first     //~v45xR~
      }                                                            //~v54YI~
    }                                                              //~v45xI~
    return rc;                                                     //~v45xI~
}//fcmdgetlabparm                                                  //~v45xI~
