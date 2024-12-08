//*CID://+vbn0R~:                             update#=  264;       //~vbn0R~
//*************************************************************
//*xecalc3.c
//* table calc(TC/TCN cmd)
//*************************************************************
//vbn1:180901 tc fmt, numeric is err as delm char, it may disturb when "N" option specified//~vbn0I~
//vbn0:180901 addtiotional to vbmr,accept unicode specification \uxxxx//~vbn0I~
//vbmu:180723 TC fmt,support dbcs outdelm string                   //~vbmuI~
//vbmt:180723 additional to vbmr, \t requires special chk (data=" " and dbcs="\t")//~vbmsI~
//vbms:180727 (BUG)TC fmt, S(optput delm) option process err(invalid split)//~vbmsI~
//vbmr:180723 accept \x,\t as TC fmt delmstr                       //~vbmrI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5p:100512 TC FMT cmd;support sbcs utf8 delm char               //~va5pI~
//va5f:100510 (BUG) TC FMT "N" option dose not work                //~va5fI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2a:091223 (BUG)tc fmt;update sw on but not updated by tab      //~va2aI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            calc2.c :utfddmemspnc etc                            //~va20I~
//v79r:080902 (BUG)TC FMT;"P" option ignored with "L" option       //~v79rI~
//v74D:070313*(BUG by v66v)tc fmt cmd;invalid delm set when "N" option//~v74DI~
//v66v:051211 (BUG)tc fmt;delm drop when delm continued            //~v66vI~
//v66d:051020 (BUG)tc fmt;parm err for D";"-->accept 'D";"' fmt    //~v66cI~
//v66c:051011 (BUG)tc fmt with compress option cut last byte       //~v62VI~
//v62V:050421 TC FMT;header insert change by V62U                  //~v62VI~
//v62U:050419 TC FMT;"N" is now search numeric and align at the numeric field//~v62UI~
//v62T:050419 TC FMT;"C" and "N" is now independent                //~v62TI~
//v62S:050419 (BUG)TC FMT;"C" option field may have last delm      //~v62SI~
//v62R:050419 (BUG)TC FMT;"C" option miss following field          //~v62RI~
//v62K:050416 TC FMT;change -S(space len) to -S[R][seps](output delimiter)//~v62KR~
//v62D:050403 (BUG)tc cmd;tc fmt;ABEND when -q and -d              //~v62DI~
//v62z:050402 tc fmt;mx fld 62-->99(2 digit hdr fldno)             //~v62zI~
//v62y:050402 tc fmt;multiple delm char specification support      //~v62yI~
//v62w:050402 tc fmt:ignore previously created tc header           //~v62wI~
//v62r:050327 tc fmt;"-q" means pos single and double quote        //~v62rI~
//v62q:050327 tc fmt;non fmt field field no count err when intermediate space=1//~v62qI~
//v62p:050325 tc_getnumrange is moved to uedit.c                   //~v62pI~
//v62g:050315 tc fmt o option to specify overflow fldno            //~v62gR~
//            ex). no:n is non fmt fld; o only: all no fmt; r o: fmt fldno=1 only//~v62gR~
//v59P:041127 tc fmt;type 'F' is no more meaningfull               //~v59PI~
//v597:041103 tc fmt cmd:change decimal point align to optional    //~v597I~
//v58x:041003 tc fmt cmd:allign by decimal point for numeric data if right align//~v58xI~
//v580:040822 TC fmt;quotation consideration. tc fmt q[d][s]       //~v580I~
//v57Z:040822 TC;fmt left/right align;2nd option without fldno is ignored//~v57ZI~
//            last "l" of "tc fmt r 2l l".                         //~v57ZI~
//            TC;doc update for align ment                         //~v57ZI~
//            default is "r";                                      //~v57ZI~
//            Without fldno,it applyed to each and last option is up to fldno next optiolast field.//~v57ZI~
//            With fldno,option is applied to the fld and other fld is not alinged.//~v57ZI~
//            ex) for 5 fld;                                       //~v57ZI~
//               tc fmt                ==> r r r r r               //~v57ZI~
//               tc fmt  r l r         ==> r l r r r               //~v57ZI~
//               tc fmt  r 3l          ==> r r l r r               //~v57ZI~
//               tc fmt  r 3l l        ==> r r l l l               //~v57ZI~
//               tc fmt  3r            ==> - - r - -               //~v57ZI~
//v53y:031011 TC FMT;allow -d"," or  -d" " fmt parm                //~v53yI~
//v522:030817 (BUG)TC FMT;splitted file cannot expand. so reject if NX line//~v522I~
//v520:030817 (BUG)tc fmt d' ' is rejected,because it is splitted to "d'" and "'"//~v520I~
//v51F:030726 (BUG)tc fmt c;c option ignored                       //~v51FI~
//v51x:030623 tc fmt:nonum concat option for each fld              //~v51xR~
//v51t:030615 tc nonum fld compact(numcomp option);allow minus num value;chng numonly-->num;//~v51tR~
//v51p:030530 allow any seperator /Cx                              //~v51pI~
//v51o:030530 num operand for TC cmd(arnage num fld only)          //~v51oI~
//v431:011010 TC cmd csv support                                   //~v431I~
//v42o:011006 help for TC cmd field spec                           //~v42oI~
//v42l:011005 (BUG)tc fmt missing space delm when "F" used         //~v42lI~
//v42k:011005 (BUG)tc fmt cut record.                              //~v42kI~
//v40R:010720 TC fld# parm support                                 //~v40RI~
//v40M:010716 fmt fld specification option for tc fmt cmd          //~v40MR~
//v19D:000925 LINUX support(command flag prefix is mainly '-')     //~v19DI~
//v17f:000501 change TCN to TC and NX option.                      //~v17fI~
//v168:000418 add table format function to TC/TCN cmd              //~v168I~
//            TC[N] fmt [[fldno]{R|L}]                             //~v168I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>                                                 //~vbn0I~

#ifdef DOS
#else
	#ifdef W32
//  	#include <windows.h>
	#else
//    #define INCL_BASE
//    #include <os2.h>
	#endif
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>
#include <uparse.h>
#include <ucalc.h>                                                 //~v58xI~
#include <ucalc2.h>                                                //~v51oI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include <utf.h>                                               //~va20R~
	#include <utf22.h>                                             //~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
#include <uedit2.h>                                                //~vbmrI~
#include <utrace.h>                                                //~vbmtI~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile6.h"
#include "xefunc.h"
#include "xeundo.h"
#include "xechar2.h"
#include "xecalc2.h"
#include "xecalc3.h"
#include "xelcmd.h"
#include "xelcmd2.h"                                               //~v62wI~
#include "xefcmd.h"
#include "xefcmd22.h"
#include "xefcmd3.h"
#include "xeerr.h"
#include "xesub.h"                                                 //~vbmuI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xesub2.h"                                            //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//#define MAXFIELD (sizeof(Sfldid)-1)                              //~v62zR~
#define MAXFIELD 99 //WARNING:if change to 3 digit change isrthdr  //~v62zR~
#define MAXLABEL 2
#define TOPSPACELEN        1                                       //~v40RR~
//#define DEFAULT_SPACELEN   2                                     //~v62KR~
#define DEFAULT_SPACELEN   1                                       //~v62KI~
#define FMTFLAG_FMT       0x80                                     //~v51xR~
#define FMTFLAG_NUMONLY   0x40                                     //~v51xI~
#define FMTFLAG_COMPRESS  0x20                                     //~v51xI~
#define FMTFLAG_LEFTALIGN 0x10                                     //~v51xI~
#define FMTFLAG_RIGHTALIGN 0x08                                    //~v51xI~
#define FMTFLAG_POINTALIGN 0x04 //right align ajusted by decimal pint//~v597I~
#define FMTFLAG_OVERFLOW   0x02 //no fmt                           //~v62gR~

#define PARM_NXSW          0
#define PARM_MAXFLDNO      1
#define PARM_MAXDATALEN    2
#define PARM_SPACELEN      3
#define PARM_HDRSW         4                                       //~v40RI~
#define PARM_TBLSZ         5                                       //~v40RR~
#define PARM_SETHDR      0x01                                      //~v51oI~
#define PARM_DQUOTE      0x02    //chk double quotation            //~v580I~
#define PARM_SQUOTE      0x04    //chk single quotation            //~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
#define PARM_UTF8FILE    0x08    //for endaddrquotation            //~va20R~
#endif                                                             //~va20R~
//#define PARM_NUMONLY     0x02                                    //~v51xR~
//#define PARM_COMPRESS    0x04                                    //~v51xR~
#define RC_DELMSPACE_CHK  -11        //should me minus             //~v520I~
                                                                   //~v51oI~
#define CHAR_DQ          '\"'    //double quote                    //~va50I~
#define CHAR_SQ          '\''    //single quote                    //~va50I~
//*******************************************************
//static char Sfldid[]="123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";//~v62zR~
//static char Sdelm;                                               //~v62yR~
static char Sdelmstr[32];                                          //~v62yR~
static char Soutdelmstr[32];                                       //~v62KR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5pI~
static char Sdelmstrdbcs[32];                                      //~va5pI~
static char Soutdelmstrdbcs[32];                                   //~va5pI~
static int Sdelmstrlen,Soutdelmstrlen;                             //~va5pI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5pI~
static int  Snumonlysw=0;                                          //~v51oI~
static int  Sswrepdelm=0;                                          //~v62KI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	static int Sswebcfile,Schspace,SchDQ,SchSQ,Schminus,Schplus;   //~va50R~
	static int Sswutf8file;                                        //~va5pI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	static int Sswtabdelm;                                         //~vbmsI~
//*******************************************************
//int tc_fmtopdchk(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Pplabplh,char *Paligntbl,//~v51xR~
int tc_fmtopdchk(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Pplabplh,     //~v51xI~
					char *Pfmtfldtbl);                             //~v40MR~
//int tc_fmtopdchk2(char *Popd,char *Pfmt,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw);//~v51xR~
//int tc_fmtopdchk2(char *Popd,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw);//~v57ZR~
int tc_fmtopdchk2(char *Popd,int *Plastpos,int *Pnextpos,char *Pfmtfldtbl,int *Ppfmtfldsw);//~v57ZI~
int tc_fmtopdchk3(char *Popd,int *Pparm);
//int tc_fmtmain(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Plabplh,char *Pfmttbl,//~v51xR~
int tc_fmtmain(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Plabplh,        //~v51xI~
				char *Pfmtfldtbl);                                 //~v40MR~
int tc_getplh(int Psw1st,PULINEH *Ppplh,PULINEH Pendplh,int *Pparm);
//int tc_chkfieldwidth(PULINEH Pplh,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,//~v580R~
int tc_chkfieldwidth(int *Pparm,PULINEH Pplh,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,//~v580R~
    					int *Pmaxlrecl,char *Pfmtfldtbl);          //~v51tR~
//char *tc_chknonfmtfieldwidth(char *Prec,int Preclen,char *Pfmtfldtbl,int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw);//~v580R~
#ifdef UTF8UCS2                                                    //~va20I~
char *tc_chknonfmtfieldwidth(int *Pparm,PULINEH Pplh,char *Prec,char *Pdbcs,int Preclen,char *Pfmtfldtbl,int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw);//~va20R~
#else                                                              //~va20I~
char *tc_chknonfmtfieldwidth(int *Pparm,char *Prec,int Preclen,char *Pfmtfldtbl,int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw);//~v580I~
#endif                                                             //~va20I~
int tc_fmtdata(PUCLIENTWE Ppcw,PULINEH Pplh,int *Pparm,
//  		int *Pfmttb,char *Paligntb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs);//~v51tR~
//  		int *Pfmttb,char *Paligntb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs,char *Pcwdata,char *Pcwdbcs);//~v51xR~
    		int *Pfmttb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs,char *Pcwdata,char *Pcwdbcs);//~v51xI~
//int tc_isrthdr(PUCLIENTWE Ppcw,PULINEH Pplh,int *Pparm,          //~v62wR~
int tc_isrthdr(PUCLIENTWE Ppcw,PULINEH Pplholdhdr,PULINEH Pplh,int *Pparm,//~v62wI~
//			int *Pfmttb,char *Pwdata);                             //~v62VR~
			int *Pfmttb,char *Pwdata,char *Pfmtfldtbl);            //~v62VR~
//char *tc_getfieldendaddr(char *Prec,int Preclen);                //~v51tR~
//char *tc_getfieldendaddr(char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen);//~v51xR~
//char *tc_getfieldendaddr(char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag);//~v580R~
//char *tc_getfieldendaddr(int *Pparm,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag);//~v58xR~
//char *tc_getfieldendaddr(int *Pparm,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,LONG *Pnumval);//~v62UR~
#ifdef UTF8UCS2                                                    //~va20I~
//char *tc_getfieldendaddr(int *Pparm,PULINEH Pplh,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,LONG *Pnumval,//~va20I~//~vafkR~
char *tc_getfieldendaddr(int *Pparm,PULINEH Pplh,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,SLPTR *Pnumval,//~vafkI~
						int *Ppnumlen,char **Ppnumfld);            //~va20I~
#else                                                              //~va20I~
//char *tc_getfieldendaddr(int *Pparm,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,LONG *Pnumval,//~v62UI~//~vafkR~
char *tc_getfieldendaddr(int *Pparm,char *Prec,char *Pdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,SLPTR *Pnumval,//~vafkI~
						int *Ppnumlen,char **Ppnumfld);            //~v62UI~
#endif                                                             //~va20I~
//char *tc_getfieldendaddrquote(char *Prec,int Preclen,char Pdelm,char *Pdelmaddr,int Popt);//~v62yR~
#ifdef UTF8UCS2                                                    //~va20R~
//char *tc_getfieldendaddrquote(char *Prec,char *Pdbcs,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt);//~va20R~//~va79R~
char *tc_getfieldendaddrquote(int Phandle,char *Prec,char *Pdbcs,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt);//~va79I~
#else                                                              //~va20R~
char *tc_getfieldendaddrquote(char *Prec,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt);//~v62yR~
#endif                                                             //~va20R~
int tc_ishdrline(PULINEH Pplh);                                    //~v62wI~
int chkhexdelm(void);                                              //~vbmrI~
char *xecalc3_umempbrk_nonascii_TABCHK(int Popt,int Pswebcfile,int Pswutf8file,int Phandle,char *Pdata,char *Pdbcs,char *Pdelmstr,char *Pdelmstrdbcs,int Plen);//~vbmtR~
#define MPBRKTABCHKO_TABFOUND      0x01                            //~vbmtI~
int xecalc3_tabchkDelmstr(char *Pdelmstr,char *Pdelmstrdbcs,int Plen,char *Pdelmstrout,char *Pdelmstrdbcsout,int *Ppoutlen);//~vbmtI~
int chkhexdelmU2DD(void);                                          //~vbn0I~
int xecalc3_delmstrchk(void);                                      //~vbn0I~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int tc_format(PUCLIENTWE Ppcw)                                     //~v17fR~
{
	PUFILEC pfc;
    int rc;
    int parmtb[PARM_TBLSZ];
    PULINEH labplht[2];
//  char aligntbl[MAXFIELD/8+1];                                   //~v51xR~
//  char fmtfldtbl[MAXFIELD/8+1];                                  //~v51xR~
//  char fmtfldtbl[MAXFIELD+1];                                    //~v58xR~
//  char fmtfldtbl[MAXFIELD*3+1]; //up digit and over up digit count//~v62UR~
    char fmtfldtbl[MAXFIELD*4+1];                                  //~v62UI~
               //fieldlen,up digit,over up digit count,numonly field last num fieldlen//~v62UI~
//*********************************
    pfc=Ppcw->UCWpfc;
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))
		return errbrowsemode();

	labplht[0]=0;		//id of no label;
//  memset(aligntbl,0,sizeof(aligntbl));    //right justify        //~v51xR~
    memset(fmtfldtbl,0,sizeof(fmtfldtbl));    //right justify      //~v40MR~
//  if ((rc=tc_fmtopdchk(Ppcw,parmtb,labplht,aligntbl,fmtfldtbl)),rc)//~v51xR~
    if ((rc=tc_fmtopdchk(Ppcw,parmtb,labplht,fmtfldtbl)),rc)       //~v51xI~
    {
    	if (rc==-1)
        	return 0;		//help
    	return rc;                      //err
	}
//  Snumonlysw=parmtb[PARM_HDRSW]&PARM_NUMONLY;                    //~v51tR~
//    if (parmtb[PARM_HDRSW] & PARM_NUMONLY)                       //~v51xR~
//        if (parmtb[PARM_HDRSW] & PARM_COMPRESS)                  //~v51xR~
//            Snumonlysw=-1;                                       //~v51xR~
//        else                                                     //~v51xR~
//            Snumonlysw=1;                                        //~v51xR~
//    else                                                         //~v51xR~
//        Snumonlysw=0;                                            //~v51xR~
//  rc=tc_fmtmain(Ppcw,parmtb,labplht,aligntbl,fmtfldtbl);         //~v51xR~
    rc=tc_fmtmain(Ppcw,parmtb,labplht,fmtfldtbl);                  //~v51xI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);	//redraw
    return rc;
}//tc_main
//****************************************************************
// calc fmt opd chk
//*rc   :0
//****************************************************************
//int tc_fmtopdchk(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Pplabplh,char *Paligntbl,//~v51xR~
int tc_fmtopdchk(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Pplabplh,     //~v51xI~
					char *Pfmtfldtbl)                              //~v40MR~
{
	PUFILEH pfh;
    char *popd,*pc;
    int  opdno,ii,labtctr=0,rc,lastpos=0;
    int  nextpos=0;                                                //~v57ZI~
    int  fmtfldsw=0;                                               //~v40MR~
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1],*plabt;//label opd from/to
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5pI~
    int opt2,ddlen;                                                //~va5pR~
    int handle;                                                    //~va79I~
	UCHAR delmddstr[sizeof(Sdelmstr)];                             //~va5pI~
	UCHAR delmdbcs[sizeof(Sdelmstr)];                              //~va5pI~
#endif                                                             //~va5pI~
	int swutf2dd=0;                                                //~vbn0I~
//*********************************
//  Sdelm=' ';          //default seperator                        //~v62yR~
    Sswrepdelm=0;                                                  //~v62KI~
//*cv oudelmstr later                                              //~va50I~
    strcpy(Soutdelmstr," ");                                       //~v62KR~
//*cv later                                                        //~va50I~
    strcpy(Sdelmstr," ");          //default seperator             //~v62yR~
    pfh=UGETPFHFROMPCW(Ppcw);
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	Sswebcfile=PFH_ISEBC(pfh);                                     //~va50I~
	Sswutf8file=FILEUTF8MODE(pfh);                                 //~va5pI~
    handle=pfh->UFHhandle;                                         //~va79I~
    if (Sswebcfile)                                                //~va50R~
    {                                                              //~va50R~
        Schspace=CHAR_EBC_SPACE;                                   //~va50R~
//      SchSQ=EBC_A2B(CHAR_SQ);                                    //~va50I~//~va79R~
        SchSQ=UCVEBCH_A2B(handle,CHAR_SQ);                         //~va79I~
//      SchDQ=EBC_A2B(CHAR_DQ);                                    //~va50I~//~va79R~
        SchDQ=UCVEBCH_A2B(handle,CHAR_DQ);                         //~va79I~
//      Schminus=EBC_A2B('-');                                     //~va50I~//~va79R~
        Schminus=UCVEBCH_A2B(handle,'-');                          //~va79I~
//      Schplus=EBC_A2B('+');                                      //~va50I~//~va79R~
        Schplus=UCVEBCH_A2B(handle,'+');                           //~va79I~
    }                                                              //~va50R~
    else                                                           //~va50R~
    {                                                              //~va50R~
        Schspace=' ';                                              //~va50R~
        SchSQ=CHAR_SQ;                                             //~va50I~
        SchDQ=CHAR_DQ;                                             //~va50I~
        Schminus='-';                                              //~va50I~
        Schplus='+';                                               //~va50I~
    }                                                              //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    memset(Pparm,0,sizeof(int)*PARM_TBLSZ);
//  Pparm[PARM_NXSW]=Pnxsw;                                        //~v17fR~
    Pparm[PARM_SPACELEN]=DEFAULT_SPACELEN;
    Pparm[PARM_MAXFLDNO]=MAXFIELD;  	//default last fld         //~v40MR~

    opdno=Ppcw->UCWopdno;           //funccmd created already
    popd=Ppcw->UCWopdpot;
    UPARSERC(Ppcw->UCWparm,popd,&opdno,UPARSEALLOWFLAG,",");   //re-parse for -d","//~v53yI~
    plabt=&labt[0][0];
    pc=popd;
    pc+=strlen(pc)+1;		//skip 1st opd(fmt)
    opdno--;
    for (ii=0;ii<opdno;ii++)
    {
        if (*pc==ULCCMDLABEL)  //lebel specified
        {
            if (labtctr==MAXLABEL)
                return fcmdlabelerr("Too many");
            strncpy(plabt,pc,ULHLINENOSZ);
            plabt+=ULHLINENOSZ+1;
            labtctr++;
        }
        else
//      	if (rc=tc_fmtopdchk2(pc,Paligntbl,&lastpos,Pfmtfldtbl,&fmtfldsw),rc)//~v51xR~
//        	if (rc=tc_fmtopdchk2(pc,&lastpos,Pfmtfldtbl,&fmtfldsw),rc)//~v57ZR~
        	if (rc=tc_fmtopdchk2(pc,&lastpos,&nextpos,Pfmtfldtbl,&fmtfldsw),rc)//~v57ZI~
            {
            	if (rc>0)
	            	return errinvalid(pc);
        		if (rc=tc_fmtopdchk3(pc,Pparm),rc)
                {
                    if (rc>0)
	            		return errinvalid(pc);
                    if (rc==RC_DELMSPACE_CHK)                      //~v520I~
                    {                                              //~v520I~
                    	if ((ii+1)<opdno)                          //~v520I~
                        {                                          //~v520I~
                        	if (*(pc+3)==*(pc+1))   //d' ' is splitted//~v520R~
                            {                                      //~v520I~
                            	if (*(pc+4))  //bug:d' ' sn-->  d' and 'sn//~v520R~
                                {                                  //~v520R~
                            		*(pc+2)=*(pc+3);               //~v520I~
                            		*(pc+3)=0;                     //~v520I~
								}                                  //~v520I~
                                else                               //~v520I~
                                {                                  //~v520I~
                                	pc+=3;                         //~v520R~
                                	ii++;   //skip next opd        //~v520R~
                                }                                  //~v520I~
//      						Sdelm=' ';                         //~v62yR~
//*cv later                                                        //~va50I~
        						strcpy(Sdelmstr," ");              //~v62yR~
                                rc=0;                              //~v520I~
                            }                                      //~v520I~
                        }                                          //~v520I~
                        if (rc)	//not valid yet                    //~v520I~
		            		return errinvalid(pc);                 //~v520I~
                    }                                              //~v520I~
                  if (rc)	//space not accepted                   //~v520I~
                    return rc;
                }

			}
        pc+=strlen(pc)+1;
    }
    if (!fmtfldsw)	//not "F" specified                            //~v40MR~
    {                                                              //~v51xI~
//  	memset(Pfmtfldtbl,0xff,MAXFIELD/8+1);	//fmt all fld      //~v51xR~
        for (ii=0,pc=Pfmtfldtbl;ii<MAXFIELD;ii++,pc++)             //~v51xI~
        	if (!*pc)                                              //~v51xI~
            	*pc=FMTFLAG_FMT;   //fmt all fld                   //~v51xI~
    }                                                              //~v51xI~
    else                                                           //~v40MR~
    	Pparm[PARM_MAXFLDNO]=lastpos;		//last fmt fld         //~v40MR~
                                                                   //~v40MR~
	rc=0;
	if (labtctr)
    {
        if (labtctr!=MAXLABEL)
            return fcmdlabelerr("Need From and To");
    	rc=fcmdgetlabelrange(pfh,labtctr,labt,Pplabplh,0);//not drop cmd
    }
//  Pparm[PARM_SPACELEN]+=(Sswrepdelm==0);	//keep input delm column//~v62KI~//~vbmsR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//    if (Sswebcfile)                                              //~va5pR~
//    {                                                            //~va5pR~
//        ucvebc_a2bfld(0,Sdelmstr,Sdelmstr,strlen(Sdelmstr));     //~va5pR~
//        ucvebc_a2bfld(0,Soutdelmstr,Soutdelmstr,strlen(Soutdelmstr));//~va5pR~
//    }                                                            //~va5pR~
    if (Sswutf8file)                                               //~vbn0I~
    {                                                              //~vbn0I~
    	int rc2;                                                   //~vbn0I~
    //******************                                           //~vbn0I~
    	rc2=chkhexdelmU2DD();                                      //~vbn0I~
        if (rc2>1)                                                 //~vbn0I~
        	return 4;                                              //~vbn0I~
	    Pparm[PARM_SPACELEN]=Soutdelmstrlen;                       //~vbn0I~
    	Pparm[PARM_SPACELEN]+=(Sswrepdelm==0);	//keep input delm column//~vbn0I~
        swutf2dd=1;	//converted to dd fmt                          //~vbn0R~
    }                                                              //~vbn0I~
    else                                                           //~vbn0I~
    if (chkhexdelm())                                              //~vbmrI~
    	return 4;                                                  //~vbmrI~
  if (!swutf2dd)	//not yet 2dd                                  //~vbn0I~
  {                                                                //~vbn0I~
//  Sdelmstrlen=strlen(Sdelmstr);                                  //~va5pI~//~vb30R~
    Sdelmstrlen=(int)strlen(Sdelmstr);                             //~vb30I~
//  Soutdelmstrlen=strlen(Soutdelmstr);                            //~va5pI~//~vb30R~
    Soutdelmstrlen=(int)strlen(Soutdelmstr);                       //~vb30I~
    Pparm[PARM_SPACELEN]=Soutdelmstrlen;                           //~vbmsR~
    Pparm[PARM_SPACELEN]+=(Sswrepdelm==0);	//keep input delm column//~vbmsI~
    if (Sswutf8file||Sswebcfile)                                   //~va5pI~
    {                                                              //~va5pI~
    	opt2=XEEBCM2DEO_SAVECT|XEEBCM2DEO_ERRMSG;                  //~va5pI~
        rc=xeebc_m2ddebc(opt2,pfh,Sdelmstr,Sdelmstrlen,delmddstr,delmdbcs,sizeof(delmddstr),&ddlen);//~va5pI~
        if (rc)                                                    //~va5pI~
        	return 4;                                              //~va5pI~
        if (!utfddissbcsstr(0,delmddstr,delmdbcs,ddlen))           //~va5pI~
        {	                                                       //~va5pI~
        	uerrmsg("DBCS(%s) is not supported as delimiter",0,    //~va5pR~//~vbn0R~
            		Sdelmstr);                                     //~va5pI~
        	return 4;                                              //~va5pI~
        }                                                          //~va5pI~
        memcpy(Sdelmstr,delmddstr,(UINT)ddlen);                    //~va5pI~
        memcpy(Sdelmstrdbcs,delmdbcs,(UINT)ddlen);                 //~va5pR~
        Sdelmstrlen=ddlen;                                         //~va5pI~
        rc=xeebc_m2ddebc(opt2,pfh,Soutdelmstr,Soutdelmstrlen,delmddstr,delmdbcs,sizeof(delmddstr),&ddlen);//~va5pI~
        if (rc)                                                    //~va5pI~
        	return 4;                                              //~va5pI~
        memcpy(Soutdelmstr,delmddstr,(UINT)ddlen);                 //~va5pI~
        memcpy(Soutdelmstrdbcs,delmdbcs,(UINT)ddlen);              //~va5pR~
        Soutdelmstrlen=ddlen;                                      //~va5pI~
    }                                                              //~va5pI~
    else                                                           //~vbmuI~
    {                                                              //~vbmuI~
    	setdbcstbl(Soutdelmstr,Soutdelmstrdbcs,Soutdelmstrlen);    //~vbmuI~
    }                                                              //~vbmuI~
  }                                                                //~vbn0I~
  	if (xecalc3_delmstrchk())                                      //~vbn0R~
    	return 4;                                                  //~vbn0I~
    if (Sswtabdelm)                                                //~vbmtI~
    {                                                              //~vbmtI~
		xecalc3_tabchkDelmstr(Sdelmstr,Sdelmstrdbcs,Sdelmstrlen,delmddstr,delmdbcs,&ddlen);//~vbmtR~
        UmemcpyZ(Sdelmstr,delmddstr,(UINT)ddlen);                  //~vbmtI~
        UmemcpyZ(Sdelmstrdbcs,delmdbcs,(UINT)ddlen);               //~vbmtI~
        Sdelmstrlen=ddlen;                                         //~vbmtI~
    }                                                              //~vbmtI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return rc;
}//tc_fmtopdchk
//****************************************************************
// calc fmt opd chk
//*rc   :0  ,4,-1(may other option)
//****************************************************************
//int tc_fmtopdchk2(char *Popd,char *Pfmt,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw)//~v51xR~
//int tc_fmtopdchk2(char *Popd,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw)//~v57ZR~
int tc_fmtopdchk2(char *Popd,int *Plastpos,int *Pnextpos,char *Pfmtfldtbl,int *Ppfmtfldsw)//~v57ZR~
{
    char *pc2,ch;
    int  ii,bytepos,numcnt,bit;                                    //~v51xR~
    int  pos1,pos2;
    int fmtbit;                                                    //~v51xI~
    char ch2;                                                      //~v62TI~
    int resetnumsw=0,resetpasw=0;                                  //~v62UI~
//*********************************
    pos1=pos2=0;
    if (*Popd>='0' && *Popd<='9')	//fldno
    {
//      if ((numcnt=tc_getnumrange(Popd,&pos1,&pos2,&pc2))>1||!pos1)    //num err//~v62pR~
        if ((numcnt=ugetnumrange3(Popd,&pos1,&pos2,&pc2))>1||!pos1)    //num err//~v62pI~
            return 4;
        if (pos1>MAXFIELD||pos2>MAXFIELD)
            return 4;
        pos1--;
        if (numcnt)
            pos2=pos1+1;
    	if (*Plastpos<pos2)     //                                 //~v57ZR~
        	*Plastpos=pos2;
        *Pnextpos=pos2;         //restart fldno from this          //~v57ZI~
	}
    else
        pc2=Popd;
//fmt tbl left align bit set
  fmtbit=FMTFLAG_FMT;                                              //~v51xI~
  for (;*pc2;pc2++)                                                //~v40MR~
  {                                                                //~v40MR~
//	fmtbit=FMTFLAG_FMT;                                            //~v51xR~
	switch(toupper(*pc2))
    {
    case 'A':                                                      //~v62UI~
    	resetnumsw=1;                                              //~v62UI~
    	break;                                                     //~v62UI~
    case 'F':                                                      //~v42oR~
//  	*Ppfmtfldsw=1;                                             //~v51FR~
    	break;                                                     //~v40MR~
    case 'O':  //overflow                                          //~v62gR~
		fmtbit|=FMTFLAG_OVERFLOW;                                  //~v62gR~
		fmtbit|=FMTFLAG_LEFTALIGN;                                 //~v62gI~
		fmtbit&=~FMTFLAG_RIGHTALIGN;                               //~v62gI~
		fmtbit&=~FMTFLAG_POINTALIGN;                               //~v62gI~
    	break;                                                     //~v62gI~
    case 'N':                                                      //~v51xI~
    	resetpasw=1;		//reset "P"                            //~v62UI~
		fmtbit|=FMTFLAG_NUMONLY;                                   //~v51xI~
    	break;                                                     //~v51xI~
    case 'C':                                                      //~v51xI~
//  	fmtbit|=(FMTFLAG_NUMONLY|FMTFLAG_COMPRESS);                //~v62TR~
    	fmtbit|=(FMTFLAG_COMPRESS); //no mean of numric            //~v62TI~
        Snumonlysw=1;                                              //~v51xI~
    	break;                                                     //~v51xI~
	case 'R':
//  	leftbit=0;                                                 //~v51xR~
		fmtbit|=FMTFLAG_RIGHTALIGN;                                //~v51xI~
		fmtbit&=~FMTFLAG_LEFTALIGN;                                //~v51xI~
		fmtbit&=~FMTFLAG_POINTALIGN;                               //~v597I~
    	break;
	case 'P':                                                      //~v597I~
		fmtbit|=FMTFLAG_POINTALIGN;                                //~v597I~
		fmtbit&=~(FMTFLAG_LEFTALIGN|FMTFLAG_RIGHTALIGN);           //~v597I~
    	break;                                                     //~v597I~
	case 'L':
//  	leftbit=1;                                                 //~v51xR~
		fmtbit|=FMTFLAG_LEFTALIGN;                                 //~v51xI~
		fmtbit&=~FMTFLAG_RIGHTALIGN;                               //~v51xI~
		fmtbit&=~FMTFLAG_POINTALIGN;                               //~v597I~
    	break;
	default:
    	if (pos2)	//after digit
			return 4;
        return -1;		//top byte,chk other option 
    }
  }                                                                //~v40MR~
//    if (*(pc2+1))                                                //~v40MR~
//        return 4;                                                //~v40MR~
  	*Ppfmtfldsw=1;                                                 //~v51FI~
    if (!pos2)	//no fld no specified
    {
//  	pos1=*Plastpos;                                            //~v57ZR~
    	pos1=*Pnextpos;                                            //~v57ZI~
//  	*Plastpos=                                                 //~v62gR~
//  	pos2=MAXFIELD;                                             //~v62gR~
	    if (fmtbit & FMTFLAG_OVERFLOW)                             //~v62gR~
			pos2=pos1+1;      //treate as not overflow fld but last field//~v62gR~
        else                                                       //~v62gI~
			pos2=MAXFIELD;                                         //~v62gI~
    	*Plastpos=pos2;                                            //~v62gI~
        *Pnextpos=*Pnextpos+1;  // for "r r l r l" etc             //~v57ZI~
	}
    else	//may be priviously set max                            //~v62gI~
    {                                                              //~v62gI~
	    if (fmtbit & FMTFLAG_OVERFLOW)                             //~v62gR~
	    	*Plastpos=pos2;	//pos2 is next                         //~v62gR~
    }                                                              //~v62gI~
	if (fmtbit & FMTFLAG_POINTALIGN                                //~v62UI~
	&&  fmtbit & FMTFLAG_NUMONLY)                                  //~v62UI~
    {                                                              //~v62UI~
        uerrmsg("\"P\" and \"N\" is mutualy exclusive.",0);        //~v62UI~
        return 4;                                                  //~v62UI~
    }                                                              //~v62UI~
//  if (pos1||pos2!=MAXFIELD)                                      //~v51FR~
        for (ii=pos1;ii<pos2;ii++)
        {
//          bytepos=ii/8;                                          //~v51xR~
//          ch=*(Pfmt+bytepos);                                    //~v51xR~
//          bit=(0x80>>(ii%8));                                    //~v51xR~
//          if (leftbit)                                           //~v51xR~
//              ch=(UCHAR)(ch | bit);                              //~v51xR~
//          else                                                   //~v51xR~
//              ch=(UCHAR)(ch & ~bit);                             //~v51xR~
//          *(Pfmt+bytepos)=ch;                                    //~v51xR~
            bytepos=ii;                                            //~v51xR~
            ch=*(Pfmtfldtbl+bytepos);                              //~v40MR~
            ch2=(char)(ch&(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN));	//prev effect//~v62TR~
//          ch&=~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN);//drop once align bit//~v57ZI~
//          ch=(char)(ch&~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN));//drop once align bit//~v597R~
            ch=(char)(ch&~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN|FMTFLAG_POINTALIGN));//drop once align bit//~v597I~
            if (resetnumsw)                                        //~v62UI~
                ch=(char)(ch&~(FMTFLAG_NUMONLY|FMTFLAG_COMPRESS));//now compress required if you want more//~v62VR~
            if (resetpasw)                                         //~v62UI~
                ch=(char)(ch&~(FMTFLAG_POINTALIGN));//reset point align//~v62VR~
            bit=fmtbit;                                            //~v51xI~
            if (!(bit &  (FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN)))	//no align parm//~v62TI~
            	bit|=ch2;                                          //~v62TI~
            ch=(UCHAR)(ch | bit);		//field used               //~v40MR~
            *(Pfmtfldtbl+bytepos)=ch;                              //~v40MR~
        }
//  else                                                           //~v51xR~
//      if (leftbit)                                               //~v51xR~
//  		memset(Pfmt,0xff,MAXFIELD/8+1);                        //~v51xR~
//      else                                                       //~v51xR~
//  		memset(Pfmt,0,MAXFIELD/8+1);                           //~v51xR~
	return 0;
}//tc_fmtopdchk2
//****************************************************************
// calc fmt opd chk
//*rc   :0  ,4, -1 for help
//****************************************************************
int tc_fmtopdchk3(char *Popd,int *Pparm)
{
    char *pc;
    char *pc2;                                                     //~v580I~
    char *popd;                                                    //~v66dI~
//  int  intp;                                                     //~v62KR~
	int len;                                                       //~v62KI~
    int opdno;                                                     //~v66dI~
//*********************************
	pc=Popd;
//  if (*pc=='/')                                                  //~v19DR~
    if (*pc==CMDFLAG_PREFIX || *pc==CMDFLAG_PREFIX2)               //~v19DI~
    	pc++;
    if (!stricmp(pc,"NX"))                                         //~v17fR~
    {                                                              //~v17fI~
        Pparm[PARM_NXSW]=1;                                        //~v17fI~
        return 0;                                                  //~v17fI~
    }                                                              //~v17fI~
////  if (!stricmp(pc,"NUMONLY"))                                  //~v51xR~
//    if (!stricmp(pc,"NUM"))                                      //~v51xR~
//    {                                                            //~v51xR~
//        Pparm[PARM_HDRSW]|=PARM_NUMONLY;                         //~v51xR~
//        return 0;                                                //~v51xR~
//    }                                                            //~v51xR~
//    if (!stricmp(pc,"NUMCOMP"))                                  //~v51xR~
//    {                                                            //~v51xR~
//        Pparm[PARM_HDRSW]|=(PARM_NUMONLY|PARM_COMPRESS);         //~v51xR~
//        return 0;                                                //~v51xR~
//    }                                                            //~v51xR~
	switch(toupper(*pc))
    {
//  case 'C':                                                      //~v51FR~
    case 'D':                                                      //~v51FI~
      if (!*(pc+1))                                                //~v51pI~
//      Sdelm=',';          //csv fmt                              //~v62yR~
        strcpy(Sdelmstr,",");          //csv fmt                   //~v62yR~
      else                                                         //~v51pI~
      {                                                            //~v51FI~
        if (*(pc+1)=='\''||*(pc+1)=='"')                           //~v51FI~
        {                                                          //~v520I~
            pc++;                                                  //~v51FI~
            if (!*(pc+1))                                          //~v520R~
                return RC_DELMSPACE_CHK;                           //~v520I~
//          strncpy(Sdelmstr,pc+1,sizeof(Sdelmstr)-1);      //any seperator//~v66dR~
//          if (*(Sdelmstr+strlen(Sdelmstr)-1)==*pc)               //~v66dR~
//          	*(Sdelmstr+strlen(Sdelmstr)-1)=0;                  //~v66dR~
            popd=umalloc(strlen(pc)+1);                            //~v66dI~
    		if (uparse(pc,popd,&opdno,0,",")||opdno!=1)   //re-parse for -d";"//~v66dR~
            {                                                      //~v66dI~
            	ufree(popd);                                       //~v66dI~
                return 4;                                          //~v66dI~
            }                                                      //~v66dI~
            strncpy(Sdelmstr,popd,sizeof(Sdelmstr)-1);      //any seperator//~v66dI~
            ufree(popd);                                           //~v66dI~
            if (!strlen(Sdelmstr))                                 //~v62yR~
            	return 4;                                          //~v62yI~
            return 0;                                              //~v62yI~
        }                                                          //~v520I~
//      Sdelm=*(pc+1);      //any seperator                        //~v62yR~
        strncpy(Sdelmstr,pc+1,sizeof(Sdelmstr)-1);      //any seperator//~v62yR~
      }                                                            //~v51FI~
    	break;                                                     //~v431I~
	case 'H':                                                      //~v40RI~
//      Pparm[PARM_HDRSW]=1;                                       //~v51oR~
        Pparm[PARM_HDRSW]|=PARM_SETHDR;                            //~v51oI~
    	break;                                                     //~v40RI~
	case 'Q':                                                      //~v580I~
    	pc2=pc+1;                                                  //~v580R~
        if (!*pc2)                                                 //~v580R~
        {                                                          //~v62rI~
		    Pparm[PARM_HDRSW]|=(PARM_DQUOTE|PARM_SQUOTE);          //~v62rI~
        }                                                          //~v62rI~
    	for (;*pc2;pc2++)                                          //~v580I~
        {                                                          //~v580I~
        	switch(toupper(*pc2))                                  //~v580I~
            {                                                      //~v580I~
            case 'D':                                              //~v580I~
		        Pparm[PARM_HDRSW]|=PARM_DQUOTE;                    //~v580I~
                break;	                                           //~v580I~
            case 'S':                                              //~v580I~
		        Pparm[PARM_HDRSW]|=PARM_SQUOTE;                    //~v580I~
                break;                                             //~v580I~
            default:                                               //~v580I~
                return 4;                                          //~v580I~
            }                                                      //~v580I~
        }                                                          //~v580I~
    	break;                                                     //~v580I~
	case 'S':
//  	intp=atoi(pc+1);                                           //~v62KR~
//      if (!intp)                                                 //~v62KR~
//      	return 4;                                              //~v62KR~
//      Pparm[PARM_SPACELEN]=intp;                                 //~v62KR~
        pc++;                                                      //~v62KI~
        if (toupper(*pc)=='R')                                     //~v62KI~
        {                                                          //~v62KI~
        	Sswrepdelm=1;                                          //~v62KI~
            pc++;                                                  //~v62KI~
        }                                                          //~v62KI~
        if (*pc)	//delm specified                               //~v62KI~
        {                                                          //~v62KI~
        	len=(int)strlen(pc);                                   //~v62KR~
//          len=min(len,sizeof(Soutdelmstr)-1);                    //~v62KI~//~vb30R~
            len=min(len,(int)sizeof(Soutdelmstr)-1);               //~vb30I~
        	if (*pc=='"')                                          //~v62KI~
//          	memcpy(Soutdelmstr,pc+1,(UINT)(len-2));            //~v62KR~//~vbmsR~
            	UmemcpyZ(Soutdelmstr,pc+1,(UINT)(len-2));          //~vbmsR~
            else                                                   //~v62KI~
//          	memcpy(Soutdelmstr,pc,(UINT)len);                  //~v62KI~//~vbmsR~
            	UmemcpyZ(Soutdelmstr,pc,(UINT)len);                //~vbmsR~
//          *(Soutdelmstr+len)=0;                                  //~v62KI~//~vbmsR~
        }                                                          //~v62KI~
        else                                                       //~v62KI~
        	if (!Sswrepdelm)	// -S only                         //~v62KR~
            	return 4;                                          //~v62KI~
        Pparm[PARM_SPACELEN]=(int)strlen(Soutdelmstr);             //~v62KR~
    	break;
	case '?':
    	tc_helpfmt();
        return -1;
	default:
        return 4;
    }
	return 0;
}//tc_fmtopdchk3
//****************************************************************
// 1 table calc
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
//int tc_fmtmain(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Plabplh,char *Paligntb,//~v51xR~
int tc_fmtmain(PUCLIENTWE Ppcw,int *Pparm,PULINEH *Plabplh,        //~v51xI~
					char *Pfmtfldtbl)                              //~v40MR~
{
	PUFILEH pfht;
	PULINEH plh,plht1,plht2;
	PULINEH plhhdr;                                                //~v62wI~
	int     parmmaxfldno,maxfldno=0,*pfldtb,sw1strec,rc,ii,len,maxlrecl=0;//~v40MR~
	int     upno;                                                  //~v58xI~
    long   recno=0,dataovf=0,upctr=0;
    char   *pwdata,*pwdbcs;
    char   *pcwdata=0,*pcwdbcs=0;	//compress work                //~v51tI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5pI~
    int opt;                                                       //~va5pI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5pI~
//*********************************
    pfht=UGETPFHFROMPCW(Ppcw);
    if (*Plabplh)
    {
		plht1=*Plabplh;
		plht2=*(Plabplh+1);
        plhhdr=UGETQPREV(plht1);                                   //~v62wI~
        if (!tc_ishdrline(plhhdr))	//prev is not hdr              //~v62wR~
        {                                                          //~v62DI~
	        if (tc_ishdrline(plht1))	//top is hdr               //~v62wI~
            {                                                      //~v62wI~
	            plhhdr=plht1;         	//skip old hdr             //~v62wI~
	            plht1=UGETQNEXT(plht1);//                          //~v62wI~
            }                                                      //~v62wI~
            else                                                   //~v62wI~
            	plhhdr=0;                                          //~v62wI~
        }                                                          //~v62DI~
    }
    else
    {
		plht1=UGETQTOP(&pfht->UFHlineque);
		plht2=UGETQEND(&pfht->UFHlineque);
        plht1=UGETQNEXT(plht1);                                    //~v62wI~
        if (tc_ishdrline(plht1))	//top is hdr                   //~v62wI~
        {                                                          //~v62wI~
            plhhdr=plht1;         //del old hdr when -h option     //~v62wI~
            plht1=UGETQNEXT(plht1);                                //~v62wI~
        }                                                          //~v62wI~
        else                                                       //~v62wI~
		    plhhdr=0;       //isrt                                 //~v62wI~
    }
//chk field width 
//  pfldtb=malloc(sizeof(int)*(MAXFIELD+1));	//top is for ovf   //~v51xR~
    pfldtb=umalloc(sizeof(int)*(MAXFIELD+1));	//top is for ovf   //~v51xI~
    UALLOCCHK(pfldtb,UALLOC_FAILED);
    memset(pfldtb,0,(sizeof(int)*(MAXFIELD+1)));

	UPCTRREQ(pfht);	//end of a shot

	parmmaxfldno=Pparm[PARM_MAXFLDNO];		//max for fmt fld only //~v40MR~
    for (plh=plht1,sw1strec=1;;sw1strec=0)
    {
    	if (rc=tc_getplh(sw1strec,&plh,plht2,Pparm),rc)
        	break;
		if (UCBITCHK(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2)))     //~v522I~
        {                                                          //~v522I~
        	uerrmsg("split line detected,use NX option after esxcluded those line",//~v522I~
            		"分割行がある時は非\x95\\示化してNXオプションを使用。");//~v522I~
        	return 4;                                              //~v522I~
        }                                                          //~v522I~
//  	tc_chkfieldwidth(plh,pfldtb,parmmaxfldno,&maxfldno,&maxlrecl,Pfmtfldtbl);	//actual max fldno//~v580R~
    	tc_chkfieldwidth(Pparm,plh,pfldtb,parmmaxfldno,&maxfldno,&maxlrecl,Pfmtfldtbl);	//actual max fldno//~v580I~
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;
    Pparm[PARM_MAXFLDNO]=maxfldno;
//editwork
//  len=maxfldno*Pparm[PARM_SPACELEN]+TOPSPACELEN+TCHDR_LINEID_TRAILERSZ;//~v42oR~
//  len=(maxfldno+1)*Pparm[PARM_SPACELEN]+TOPSPACELEN+TCHDR_LINEID_TRAILERSZ;//~v62UR~
//  len=(maxfldno+maxfldno+1)*(Pparm[PARM_SPACELEN]+1)+TOPSPACELEN+TCHDR_LINEID_TRAILERSZ;//~v62UI~//~vb30R~
    len=(maxfldno+maxfldno+1)*((int)Pparm[PARM_SPACELEN]+1)+TOPSPACELEN+(int)TCHDR_LINEID_TRAILERSZ;//~vb30R~
	for (ii=0;ii<=maxfldno;ii++)
    {                                                              //~v58xI~
        if (ii>0)                                                  //~v58xI~
        {                                                          //~v58xI~
        	upno=Pfmtfldtbl[ii-1+MAXFIELD];	//digit count from "." //~v58xR~
            if (upno)                                              //~v58xI~
            {                                                      //~v58xI~
	        	upno+=Pfmtfldtbl[ii-1+MAXFIELD+MAXFIELD];	//over up digit and "."//~v58xI~
                if (upno>pfldtb[ii])                               //~v58xI~
	 		   		pfldtb[ii]=upno;	//if up exist,pfldtbl is digit count of over digit//~v58xR~
            }                                                      //~v58xI~
        	len+=Pfmtfldtbl[ii-1+MAXFIELD+MAXFIELD+MAXFIELD]+Pparm[PARM_SPACELEN]+1;//numonly field numlen//~v62UI~
        }                                                          //~v58xI~
    	len+=pfldtb[ii];
    }                                                              //~v58xI~
	if (len<maxlrecl)	
    	len=maxlrecl;   	//space padding
    Pparm[PARM_MAXDATALEN]=len;
//  pwdata=malloc((UINT)len);                                      //~v51xR~
    pwdata=umalloc((UINT)len);                                     //~v51xI~
    UALLOCCHK(pwdata,UALLOC_FAILED);
//  pwdbcs=malloc((UINT)len);                                      //~v51xR~
    pwdbcs=umalloc((UINT)len);                                     //~v51xI~
    UALLOCCHK(pwdbcs,UALLOC_FAILED);
//  if (Snumonlysw<0)                                              //~v51xR~
    if (Snumonlysw)                                                //~v51xI~
    {                                                              //~v51tI~
//      pcwdata=malloc((UINT)len);        //nonum fld compaction work//~v51xR~
        pcwdata=umalloc((UINT)len);        //nonum fld compaction work//~v51xI~
        UALLOCCHK(pcwdata,UALLOC_FAILED);                          //~v51tI~
//      pcwdbcs=malloc((UINT)len);                                 //~v51xR~
        pcwdbcs=umalloc((UINT)len);                                //~v51xI~
        UALLOCCHK(pcwdbcs,UALLOC_FAILED);                          //~v51tI~
    }                                                              //~v51tI~
                                                                   //~v40RI~
    for (plh=plht1,sw1strec=1;;sw1strec=0)
    {
    	if (tc_getplh(sw1strec,&plh,plht2,Pparm))
        	break;
        recno++;
//  	if (rc=tc_fmtdata(Ppcw,plh,Pparm,pfldtb,Paligntb,Pfmtfldtbl,pwdata,pwdbcs),rc)//~v51tR~
//  	if (rc=tc_fmtdata(Ppcw,plh,Pparm,pfldtb,Paligntb,Pfmtfldtbl,pwdata,pwdbcs,pcwdata,pcwdbcs),rc)//~v51xR~
    	if (rc=tc_fmtdata(Ppcw,plh,Pparm,pfldtb,Pfmtfldtbl,pwdata,pwdbcs,pcwdata,pcwdbcs),rc)//~v51xI~
        {
        	if (rc>4)
            	break;
			if (rc==1)	//updated
            	upctr++;
            else
            {
				tc_setplherr(plh);                	
        		dataovf++;
            }
		}
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;
    if (pcwdata)                                                   //~v51xI~
    {                                                              //~v51xI~
        ufree(pcwdata);                                            //~v51xI~
        ufree(pcwdbcs);                                            //~v51xI~
    }                                                              //~v51xI~
                                                                   //~v40RI~
//  if (Pparm[PARM_HDRSW])	//insert hdr line                      //~v51oR~
    if (Pparm[PARM_HDRSW] & PARM_SETHDR)	//insert hdr line      //~v51oI~
    {                                                              //~v40RI~
//  	rc=tc_isrthdr(Ppcw,plht1,Pparm,pfldtb,pwdata);             //~v62wR~
//  	rc=tc_isrthdr(Ppcw,plhhdr,plht1,Pparm,pfldtb,pwdata);      //~v62VR~
    	rc=tc_isrthdr(Ppcw,plhhdr,plht1,Pparm,pfldtb,pwdata,Pfmtfldtbl);//~v62VI~
		if (rc==UALLOC_FAILED)                                     //~v40RI~
    		return rc;                                             //~v40RI~
    }                                                              //~v40RI~
                                                                   //~v40RM~
    ufree(pwdata);                                                 //~v51xI~
    ufree(pwdbcs);                                                 //~v51xI~
    ufree(pfldtb);                                                 //~v51xI~
    UPCTRREQ(pfht); //end of a shot
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5pI~
	opt=0;                                                         //~va5pI~
    xeerrmsg(opt,4,XEERMPTS_CMDSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR,//~va5pR~
		"%s:total %ld, updated=%ld,outovf=%ld",0,                  //~va5pI~
        Ppcw->UCWparm,recno,upctr,dataovf);                        //~va5pI~
#else                                                              //~va5pI~
    uerrmsg("%s:total %ld, updated=%ld,outovf=%ld",0,
        Ppcw->UCWparm,recno,upctr,dataovf);
#endif //UTF8EBCD raw ebcdic file support                          //~va5pI~
//  return dataovf;                                                //~vb31R~
    return (int)dataovf;                                           //~vb31I~
}//tc_fmtmain
//****************************************************************
// get valid plh
//*rc   :-1:eof or 4 err or UALLOC_FAILED
//****************************************************************
int tc_getplh(int Psw1st,PULINEH *Ppplh,PULINEH Pendplh,int *Pparm)
{
	PULINEH plh;
    int nxsw;
//*********************************
	nxsw=Pparm[PARM_NXSW];
    plh=*Ppplh;
    if (!Psw1st)
    {                                                              //~v580I~
    	if (plh==Pendplh)	
        	return -1;		//eof
        else
    		plh=UGETQNEXT(plh);
    }                                                              //~v580I~

    for (;plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype==ULHTDATA)
        {
            if (!nxsw
            ||  !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
            {
                if (!plh->ULHdbcs)
                    if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len
                        return UALLOC_FAILED;
                break;
            }//target
        }//data
    	if (plh==Pendplh)
        	return -1;	//eof
	}
    if (!plh)
    	return -1;
    *Ppplh=plh;		//update for next call
    return 0;
}//tc_getplh
//****************************************************************
// check field width secperated by tab/space(tab is already expanded)
//*ret :0, 1:over maxfld
//****************************************************************
//int tc_chkfieldwidth(PULINEH Pplh,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,//~v580R~
int tc_chkfieldwidth(int *Pparm,PULINEH Pplh,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,//~v580R~
    					int *Pmaxlrecl,char *Pfmtfldtbl)           //~v51tR~
{
    int len,rc=0,fldno,ovflen=0,rlen;                     //~v40MR~
    int nofmtsw,netlen;                                            //~v431I~
    char  *pc,*pce,*pcw;                                           //~v40MR~
    int complen;                                                   //~v51tR~
    int upno;                                                      //~v58xI~
//  LONG wklv[4];                                                  //~v58xI~//~vafkR~
    SLPTR wklv[4];                                                 //~vafkI~
    char prevdelm=0,curdelm;                                       //~v62yR~
    char  *pcwnum;                                                 //~v62UI~
	int numonlynumlen,fmtflag;                                     //~v62UI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
    char *pdbcs0,*pdata0,*pcd;                                     //~va20I~
#endif                                                             //~va20I~
//****************************************
//  maxfldno=*Pmaxfldno;                                           //~v40MR~
	pc=Pplh->ULHdata;
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
	pdata0=Pplh->ULHdata;                                          //~va20I~
	pdbcs0=Pplh->ULHdbcs;                                          //~va20I~
#endif                                                             //~va20I~
    rlen=Pplh->ULHlen;
    if (rlen>*Pmaxlrecl)
    	*Pmaxlrecl=rlen;	//work len
    pce=pc+rlen;
//  for (fldno=0;pc<pce;)                                          //~v431R~
    for (fldno=0;;)                                                //~v431I~
    {
#ifdef UTF8UCS2                                                    //~va20R~
//		pcd=pdbcs0+((ULONG)pc-(ULONG)pdata0);                      //~va20I~//~vafkR~
		pcd=pdbcs0+((ULPTR)pc-(ULPTR)pdata0);                      //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	len=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd,rlen);//~va50R~
    #else                                                          //~va50I~
    	len=(int)UTF_UMEMSPNC(swutf8file,pc,pcd,' ',rlen);         //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	len=(int)umemspnc(pc,' ',(UINT)rlen);
#endif                                                             //~va20I~
        pc+=len;
        rlen-=len;
        if (rlen<=0)
//        if (!fldno || Sdelm==' ')//all space or space after delm=' '//~v62yR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (!fldno || prevdelm==Schspace)//all space or space after delm=' '//~va50I~
#else                                                              //~va50I~
          if (!fldno || prevdelm==' ')//all space or space after delm=' '//~v62yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        	break;
        if (fldno>=Pparmmaxfldno)                                  //~v40MR~
		{
//         	ovflen=(int)((ULONG)pce-(ULONG)pc);                    //~vafkR~
         	ovflen=(int)((ULPTR)pce-(ULPTR)pc);                    //~vafkI~
            if (Pfmttb[0]<ovflen)
    			Pfmttb[0]=ovflen;		//update max len of the field
        	break;
		}
        fmtflag=Pfmtfldtbl[fldno];                                 //~v62UI~
        fldno++;
//      pcw=memchr(pc,' ',(UINT)rlen);                             //~v431R~
//      pcw=memchr(pc,Sdelm,(UINT)rlen);                           //~v51oR~
//      pcw=tc_getfieldendaddr(pc,rlen);                           //~v51tR~
//      pcw=tc_getfieldendaddr(pc,0,rlen,0,0,&complen);            //~v51xR~
//      pcw=tc_getfieldendaddr(pc,0,rlen,0,0,&complen,(int)Pfmtfldtbl[fldno-1]);//~v580R~
//      pcw=tc_getfieldendaddr(Pparm,pc,0,rlen,0,0,&complen,(int)Pfmtfldtbl[fldno-1]);//~v58xR~
//      pcw=tc_getfieldendaddr(Pparm,pc,0,rlen,0,0,&complen,(int)Pfmtfldtbl[fldno-1],wklv);//~v62UR~
#ifdef UTF8UCS2                                                    //~va20I~
//		pcd=pdbcs0+((ULONG)pc-(ULONG)pdata0);                      //~va20I~//~vafkR~
		pcd=pdbcs0+((ULPTR)pc-(ULPTR)pdata0);                      //~vafkI~
        pcw=tc_getfieldendaddr(Pparm,Pplh,pc,pcd,rlen,0/*wkdata*/,0/*wkdbcs*/,&complen,(int)Pfmtfldtbl[fldno-1],wklv,//~va20R~
                                &numonlynumlen,&pcwnum);           //~va20I~
#else                                                              //~va20I~
        pcw=tc_getfieldendaddr(Pparm,pc,0,rlen,0,0,&complen,(int)Pfmtfldtbl[fldno-1],wklv,//~v62UI~
                                &numonlynumlen,&pcwnum);           //~v62UI~
#endif                                                             //~va20I~
        nofmtsw=0;                                                 //~v431I~
        if (pcw)
        {                                                          //~v40MR~
//        	len=(int)((ULONG)pcw-(ULONG)pc);                       //~v40MR~//~vafkR~
        	len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~vafkI~
//  		pcw=tc_chknonfmtfieldwidth(pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~v580R~
#ifdef UTF8UCS2                                                    //~va20I~
//			pcd=pdbcs0+((ULONG)pcw-(ULONG)pdata0);                 //~va20I~//~vafkR~
			pcd=pdbcs0+((ULPTR)pcw-(ULPTR)pdata0);                 //~vafkI~
    		pcw=tc_chknonfmtfieldwidth(Pparm,Pplh,pcw,pcd,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~va20R~
#else                                                              //~va20I~
    		pcw=tc_chknonfmtfieldwidth(Pparm,pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~v580I~
#endif                                                             //~va20I~
            if (nofmtsw)	//no fmt fields                        //~v51tI~
            	complen=len;	//no compress                      //~v51tR~
        }                                                          //~v40MR~
        else
        	len=rlen;
//      if (Snumonlysw>=0)	//not compress mode                    //~v51xR~
//      if (!(Pfmtfldtbl[fldno-1] & FMTFLAG_COMPRESS))	//not compress mode//~v62UR~
        if (!(fmtflag & FMTFLAG_COMPRESS))	//not compress mode    //~v62UI~
        	complen=len;                                           //~v51tI~
        	                                                       //~v51tI~
		if (pcw)                                                   //~v62yI~
        {                                                          //~v74DI~
//        if (len)                                                 //~v74DR~
        	curdelm=*pcw;                                          //~v62yR~
//        else          //numonly field has no preceding non-num fields//~v74DR~
//          curdelm=' ';                                           //~v74DR~
          if (!len && numonlynumlen)	//numeric only fld len=0   //~v74DI~
            curdelm=*(pcwnum+numonlynumlen);                       //~v74DR~
        }                                                          //~v74DI~
        else                                                       //~v62yI~
        	curdelm=0;                                             //~v62yI~
//      if ((Pfmtfldtbl[fldno-1] & FMTFLAG_COMPRESS))	//not compress mode//~v62UR~
        if ((fmtflag & FMTFLAG_COMPRESS))	//not compress mode    //~v62UI~
        	netlen=complen;                                        //~v62RI~
        else                                                       //~v62RI~
//      if (!nofmtsw && Sdelm!=' ')                                //~v62yR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (!nofmtsw && curdelm!=Schspace)	//del space before delm//~va50I~
#else                                                              //~va50I~
        if (!nofmtsw && curdelm!=' ')	//del space before delm    //~v62yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        {                                                          //~va20I~
//      	netlen=len-(int)umemrspnc(pc,' ',(UINT)len);//cut last space//~v51tR~
#ifdef UTF8UCS2                                                    //~va20I~
//			pcd=pdbcs0+((ULONG)pc-(ULONG)pdata0);                  //~va20I~//~vafkR~
			pcd=pdbcs0+((ULPTR)pc-(ULPTR)pdata0);                  //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	netlen=complen-(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd,complen);//cut last space//~va50R~
    #else                                                          //~va50I~
        	netlen=complen-(int)UTF_UMEMRSPNC(swutf8file,pc,pcd,' ',complen);//cut last space//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	netlen=complen-(int)umemrspnc(pc,' ',(UINT)complen);//cut last space//~v51tR~
#endif                                                             //~va20I~
        }                                                          //~va20I~
        else                                                       //~v431I~
//      	netlen=len;                                            //~v51tR~
        	netlen=complen;                                        //~v51tI~
//      if (Pfmttb[fldno]<len)                                     //~v431R~
//      	Pfmttb[fldno]=len;		//update max len of the field  //~v431R~
        if (wklv[1]!=-1)	//fld is numeric                       //~v58xM~
        {                                                          //~v58xM~
//        if (Pfmtfldtbl[fldno-1] & FMTFLAG_POINTALIGN)	//not compress mode//~v62UR~
          if (fmtflag & FMTFLAG_POINTALIGN)	//not compress mode    //~v62UI~
          {                                                        //~v597I~
        	upno=wklv[1]&UCALC_UPMASK;	//underpoint digit count   //~v58xM~
            if (upno)                                              //~v58xI~
            {                                                      //~v58xI~
            	upno++;		//for "."                              //~v58xI~
        		if (Pfmtfldtbl[fldno+MAXFIELD-1]<upno)             //~v58xR~
        			Pfmtfldtbl[fldno+MAXFIELD-1]=(char)upno;       //~v58xI~
            }                                                      //~v58xI~
           	upno=netlen-upno;	//digit over up                    //~v58xR~
        	if (Pfmtfldtbl[fldno+MAXFIELD+MAXFIELD-1]<upno)        //~v58xR~
        		Pfmtfldtbl[fldno+MAXFIELD+MAXFIELD-1]=(char)upno;  //~v58xR~
          }//point align                                           //~v597I~
        }                                                          //~v58xM~
        if (Pfmttb[fldno]<netlen)                                  //~v431I~
        	Pfmttb[fldno]=netlen;		//update max len of the field//~v431I~
        if ((fmtflag & FMTFLAG_NUMONLY))	//not compress mode    //~v62UI~
        {                                                          //~v62UI~
        	if (Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD]<numonlynumlen)//~v62UI~
        		Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD]=(char)numonlynumlen;//~v62UI~
            if (numonlynumlen)	//num field found                  //~v62UI~
            {                                                      //~v62UI~
            	pcw=pcwnum+numonlynumlen;                          //~v62UI~
//        		len=(int)((ULONG)pcw-(ULONG)pc);                   //~v62UI~//~vafkR~
        		len=(int)((ULPTR)pcw-(ULPTR)pc);                   //~vafkI~
                if (len>=rlen)                                     //~v62UI~
                	pcw=0;                                         //~v62UI~
                else                                               //~v62UI~
	                curdelm=*pcw;                                  //~v62UI~
            }                                                      //~v62UI~
            else                                                   //~v62UI~
            	pcw=0;	//eol break                                //~v62UI~
        }                                                          //~v62UI~
        rlen-=len;
        if (!pcw)
        	break;
        prevdelm=curdelm;                                          //~v62yI~
		pc=pcw;
        pc++;           //skip seperator                           //~v431I~
        rlen--;                                                    //~v431I~
	}
    if (fldno>*Pmaxfldno)
    	*Pmaxfldno=fldno;
    return rc;
}//tc_chkfieldwidth
//**************************************************************** //~v51oI~
// search end addr of a field                                      //~v51oI~
//        (zmax 2**64=18,446,744,073,709,551,616)                  //~v51oI~
//p1:fld addr                                                      //~v51oI~
//p2:record residual len                                           //~v51oI~
//*ret :fld end addr                                               //~v51oI~
//**************************************************************** //~v51oI~
//char *tc_getfieldendaddr(char *Prec,int Preclen)                 //~v51tR~
//char *tc_getfieldendaddr(char *Prec,char *Ppdbcs,int Preclen,char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen)//~v51xR~
//char *tc_getfieldendaddr(char *Prec,char *Ppdbcs,int Preclen,    //~v580R~
#ifdef UTF8UCS2                                                    //~va20I~
char *tc_getfieldendaddr(int *Pparm,PULINEH Pplh,char *Prec,char *Ppdbcs,int Preclen,//~va20I~
#else                                                              //~va20I~
char *tc_getfieldendaddr(int *Pparm,char *Prec,char *Ppdbcs,int Preclen,//~v580I~
#endif                                                             //~va20I~
//  					char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag)//~v58xR~
//  					char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,LONG *Pnumval)//~v62UR~
//  					char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,LONG *Pnumval,//~v62UI~//~vafkR~
    					char *Ppcwdata,char *Ppcwdbcs,int *Ppcomplen,int Pfmtflag,SLPTR *Pnumval,//~vafkI~
    					int *Ppnumlen,char **Ppnumfld)             //~v62UI~
{                                                                  //~v51oI~
	char *pc,*pcw,*prevend=0;                                      //~v51oR~
    int len,rlen;                                                  //~v51oI~
    char numwk[64];                                                //~v51oI~
//  ULONG dwwk[2];                                                 //~v580R~
//  LONG dwwk[2];                                                  //~v58xR~
//  int totcomp=0,complen,taillen,offs,numsw;                      //~v51tR~//~vaf9R~
    int totcomp=0,complen,taillen,offs,numsw=0;                    //~vaf9I~
    int qchksw;                                                    //~v580I~
    char *pcwdata,*pcwdbcs,*pcomp,*pcwdelm=0;                      //~v51tR~
    char curdelm;                                                  //~v62yI~
    int rc;                                                        //~v58xI~
    int nonumcontsw=0;                                             //~v62SI~
    int numchksw;                                                  //~v62TI~
	char *pnumfld=NULL; //caller use this only when *Pnumlen!=0                                                //~v62UR~//~vaf9R~
    int numonlynumlen=0;                                           //~v62UR~
#ifdef UTF8UCS2                                                    //~va20I~
	char *pcd;                                                     //~va20I~
	int swutf8file,qchksw2;                                        //~va20R~
    int handle;                                                    //~va79I~
#endif                                                             //~va20I~
//*****************************                                    //~v51oI~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
#endif                                                             //~va20I~
	numchksw=!(Pfmtflag & FMTFLAG_COMPRESS) //no compress          //~v62TI~
	  	   || (Pfmtflag & FMTFLAG_NUMONLY);	//search num field     //~v62TI~
	Pnumval[1]=-1;	//id of not numeric                            //~v58xI~
	pc=Prec;                                                       //~v51oI~
    rlen=Preclen;                                                  //~v51oI~
    pcwdata=Ppcwdata;                                              //~v51tR~
    pcwdbcs=Ppcwdbcs;                                              //~v51tI~
    qchksw=Pparm[PARM_HDRSW]&(PARM_SQUOTE|PARM_DQUOTE);     //chk quotation//~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
	qchksw2=PARM_UTF8FILE*(swutf8file!=0);                         //~va20R~
#endif                                                             //~va20R~
    for (;rlen>0;)                                                 //~v51oR~
    {                                                              //~v51oI~
#ifdef UTF8UCS2                                                    //~va20I~
//		pcd=Ppdbcs+((ULONG)pc-(ULONG)Prec);                        //~va20R~//~vafkR~
		pcd=Ppdbcs+((ULPTR)pc-(ULPTR)Prec);                        //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	len=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd,rlen);//~va50R~
    #else                                                          //~va50I~
    	len=(int)UTF_UMEMSPNC(swutf8file,pc,pcd,' ',rlen);         //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        len=(int)umemspnc(pc,' ',(UINT)rlen);                      //~v51oI~
#endif                                                             //~va20I~
        pc+=len;                                                   //~v51oI~
        rlen-=len;                                                 //~v51oI~
#ifdef UTF8UCS2                                                    //~va20M~
//		pcd=Ppdbcs+((ULONG)pc-(ULONG)Prec);                        //~va20M~//~vafkR~
		pcd=Ppdbcs+((ULPTR)pc-(ULPTR)Prec);                        //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      pcwdelm=pcw=UCVEBCUTF_umempbrk(Sswebcfile,swutf8file,pc,pcd,Sdelmstr,rlen);//~va5pR~
//      pcwdelm=pcw=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,swutf8file,pc,pcd,Sdelmstr,Sdelmstrdbcs,rlen);//~va5pI~//~va79R~
//      pcwdelm=pcw=UCVEBCUTF_umempbrk_nonascii(Sswebcfile,swutf8file,handle,pc,pcd,Sdelmstr,Sdelmstrdbcs,rlen);//~va79I~//~vbmtR~
        pcwdelm=pcw=xecalc3_umempbrk_nonascii_TABCHK(Sswtabdelm ?  MPBRKTABCHKO_TABFOUND :0,Sswebcfile,swutf8file,handle,pc,pcd,Sdelmstr,Sdelmstrdbcs,rlen);//~vbmtR~
#define MPBRKTABCHKO_TABFOUND      0x01                            //~vbmtI~
    #else                                                          //~va50I~
        pcwdelm=pcw=UTF_UMEMPBRK(swutf8file,pc,pcd,Sdelmstr,rlen); //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20M~
        pcwdelm=                                                   //~v51tI~
//      pcw=memchr(pc,Sdelm,(UINT)rlen);                           //~v62yR~
        pcw=umempbrk(pc,Sdelmstr,(UINT)rlen);                      //~v62yI~
#endif                                                             //~va20I~
//chk quotation                                                    //~v580I~
        if (qchksw)                                                //~v580I~
//      	pcwdelm=pcw=tc_getfieldendaddrquote(pc,rlen,Sdelm,pcw,qchksw);//~v62yR~
#ifdef UTF8UCS2                                                    //~va20R~
//      	pcwdelm=pcw=tc_getfieldendaddrquote(pc,pcd,rlen,Sdelmstr,pcw,qchksw|qchksw2/*utf8 option*/);//~va20R~//~va79R~
        	pcwdelm=pcw=tc_getfieldendaddrquote(handle,pc,pcd,rlen,Sdelmstr,pcw,qchksw|qchksw2/*utf8 option*/);//~va79I~
#else                                                              //~va20R~
        	pcwdelm=pcw=tc_getfieldendaddrquote(pc,rlen,Sdelmstr,pcw,qchksw);//~v62yI~
#endif                                                             //~va20R~
        if (pcw)                                                   //~v51tI~
        {                                                          //~v62yI~
//        	len=(int)((ULONG)pcw-(ULONG)pc);   //fld len                  //~v51tI~//~vafkR~
        	len=(int)((ULPTR)pcw-(ULPTR)pc);   //fld len           //~vafkI~
            curdelm=*pcw;                                          //~v62yI~
        }                                                          //~v62yI~
        else                                                       //~v51tI~
        {                                                          //~v62yI~
            len=rlen;    //continue for remining prevend           //~v51tI~
            curdelm=0;                                             //~v62yI~
        }                                                          //~v62yI~
//      if (!Snumonlysw)	//not num only                         //~v51xR~
//      if (!(Pfmtflag&FMTFLAG_NUMONLY))	//not num only         //~v58xR~
//      	break;                                                 //~v58xR~
//      if (!pcw)                                                  //~v51tR~
//          pcw=pc+rlen;    //continue for remining prevend        //~v51tR~
//      len=(ULONG)pcw-(ULONG)pc;   //fld len                      //~v51tR~
        pcw=pc+len;                                                //~v51tR~
        rlen-=len+1;                                               //~v51oI~
//      if (Sdelm!=' ')                                            //~v62yR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (curdelm!=Schspace)	//chk spacelen before delm         //~va50I~
#else                                                              //~va50I~
        if (curdelm!=' ')	//chk spacelen before delm             //~v62yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        {                                                          //~v51tI~
//          len-=(int)umemrspnc(pc,' ',(UINT)len);                 //~v51tR~
#ifdef UTF8UCS2                                                    //~va20I~
			pcd=XEUTF_PC2PCD(Ppdbcs,pc,Prec);                      //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            taillen=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd,len);//~va50R~
    #else                                                          //~va50I~
            taillen=(int)UTF_UMEMSPNC(swutf8file,pc,pcd,' ',len);  //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            taillen=(int)umemrspnc(pc,' ',(UINT)len);              //~v51tI~
#endif                                                             //~va20I~
            len-=taillen;                                          //~v51tI~
        }                                                          //~v51tI~
        pcomp=pc;	//compress data top                            //~v51tI~
        complen=len;                                               //~v51tI~
        numsw=0;                                                   //~v51tI~
	  if (!(Pfmtflag & FMTFLAG_OVERFLOW))	//not overflow fld specification//~v62gI~
      {                                                            //~v62gI~
		  if (numchksw)                                            //~v62TI~
          {                                                        //~v62TI~
#ifdef UTF8UCS2                                                    //~va20I~
	   pcd=XEUTF_PC2PCD(Ppdbcs,pc,Prec);                           //~va20I~
//     if (swutf8file                                              //~va5fR~
//     &&  utfddisasciistr(0,pc,pcd,len)                           //~va5fR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
       if ((!swutf8file && !Sswebcfile)                            //~va50R~
       ||  UWHICH(Sswebcfile,                                      //~va50R~
//                UCVEBC_isasciistr(pc,pcd,len),                   //~va50I~//~va79R~
                  UCVEBC_isasciistr(handle,pc,pcd,len),            //~va79I~
                  utfddisasciistr(0,pc,pcd,len)                    //~va50I~
                 )                                                 //~va50I~
#else                                                              //~va50I~
       if (!swutf8file                                             //~va5fI~
       ||  utfddisasciistr(0,pc,pcd,len)                           //~va5fI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
       )                                                           //~va20I~
#endif                                                             //~va20I~
       {                                                           //~va20I~
          	pnumfld=pc;                                            //~v62UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (*pc==Schminus||*pc==Schplus)                           //~va50I~
#else                                                              //~va50I~
        if (*pc=='-'||*pc=='+')                                    //~v51tI~
#endif                                                             //~va50I~
        {                                                          //~v51tI~
        	pc++;                                                  //~v51tI~
            len--;                                                 //~v51tI~
        }                                                          //~v51tI~
        if (len<sizeof(numwk))                                     //~v51oI~
        {                                                          //~v51oI~
            memcpy(numwk,pc,(UINT)len);                            //~v51oI~
            *(numwk+len)=0;                                        //~v51oI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	    UCVEBC_b2afld(Sswebcfile,numwk,len);                   //~va50R~//~va79R~
    	    UCVEBC_b2afld(Sswebcfile,handle,numwk,len);            //~va79I~
#endif                                                             //~va50I~
//          if (ucalc_ld2dw(numwk,dwwk)<4)	//allow Z fmt and underpoint//~v58xR~
            rc=bc_getld(GETLD_DWUP,numwk,Pnumval);	//0:word,1:dword,else err//~v58xR~
            if (rc>=4)                                             //~v58xI~
		        rc=ucalc_gettimevalue(numwk,0,Pnumval);   //by strlen//~v58xI~
            if (rc<4)                                              //~v58xI~
            {                                                      //~v51oR~
//                if (prevend)    //prev iouly chked non numeric fld//~v62UR~
//                {                                                //~v62UR~
//                    Pnumval[1]=-1;  //after non numeric          //~v62UR~
////                  pcw=prevend;    //return prev nun numric fld end addr//~v62UR~
//                    pcwdelm=prevend;    //return prev nun numric fld end addr//~v62UR~
//                    numsw=-1;       //next is numfld             //~v62UR~
//                    totcomp--;      //drop last delm             //~v62UR~
//                }                                                //~v62UR~
////              break;                                           //~v62UR~
//                else                                             //~v62UR~
                	numsw=1; 	//first is num fld                 //~v51tR~
            }                                                      //~v51oR~
        }                                                          //~v51oI~
       }//ascii chk                                                //~va20I~
          }//numchksw                                              //~v62TI~
	  }//not overflow fld specification                            //~v62gI~
//      if (numsw>=0)   //not num or strat is num                  //~v62UR~
//      {                                                          //~v62UR~
//          if (pcwdata)	//compress req from tc_fmtdata         //~v51xR~
            if (pcwdata 	//after  malloc                        //~v51xI~
            &&  Pfmtflag & FMTFLAG_COMPRESS)	//compress req from tc_fmtdata//~v51xR~
            {                                                      //~v51tI~
//              offs=(int)((ULONG)pcomp-(ULONG)Prec);                     //~v51tR~//~vafkR~
                offs=(int)((ULPTR)pcomp-(ULPTR)Prec);              //~vafkI~
                memcpy(pcwdata,pcomp,(UINT)(complen));             //~v51tR~
                memcpy(pcwdbcs,Ppdbcs+offs,(UINT)(complen));       //~v51tR~
                pcwdata+=complen;                                  //~v51tR~
                pcwdbcs+=complen;                                  //~v51tR~
            }                                                      //~v51tI~
	        totcomp+=complen;                                      //~v51tI~
//      }//bumsw>=0                                                //~v62UR~
	  if (!(Pfmtflag & FMTFLAG_OVERFLOW))	//not overflow fld specification//~v62gI~
      {                                                            //~v62gI~
	   if (numchksw) //!compress or numonly                        //~v62TI~
       {                                                           //~v62TI~
        if (!(Pfmtflag&FMTFLAG_NUMONLY))	//not num only         //~v58xI~
        	break;                                                 //~v58xI~
        if (numsw)                                                 //~v51tM~
        {              //NUMONLY field detected num field          //~v62UI~
            if (prevend)                                           //~v62UI~
            {                                                      //~v62UI~
                pcwdelm=prevend;    //cut by non numeric field     //~v62UI~
                totcomp--;          //for delm                     //~v62UI~
            }                                                      //~v62UI~
            else                                                   //~v62UI~
                pcwdelm=Prec;       //cut by non numeric field,fldlen=0//~v62UI~
            numonlynumlen=complen; //NUMONLY field numlen          //~v62UI~
            totcomp-=complen;      //compressed len                //~v62UI~
            break;                                                 //~v51tM~
        }//numsw                                                   //~v62UI~
       }//numchksw                                                 //~v62TI~
	  }//not overflow fld specification                            //~v62gI~
        prevend=pcw;                                               //~v51oR~
        pc=pcw+1;                                                  //~v51oI~
    	nonumcontsw=0;  //sw only for last field is required       //~v66cR~
    	if (rlen>0)   	//not end of rec                           //~v51tI~
        {                                                          //~v51tI~
//      	if (pcwdata)	//compress req from tc_fmtdata         //~v51xR~
        	if (pcwdata 	//after malloc                         //~v51xI~
            &&  Pfmtflag & FMTFLAG_COMPRESS)	//compress req from tc_fmtdata//~v51xR~
            {                                                      //~v51tI~
//          	*pcwdata++=Sdelm;                                  //~v62yR~
            	*pcwdata++=curdelm; //detected delm char           //~v62yI~
                *pcwdbcs++=0;                                      //~v51tI~
			}                                                      //~v51tI~
            totcomp++;  //for intermediate delm                    //~v51tI~
    		nonumcontsw=1;  //intermediate space added             //~v62SI~
        }                                                          //~v51tI~
    }//until eol                                                   //~v51oI~
    if (!numsw && nonumcontsw)//end by not numeric and intermediate delm space len added//~v62SI~
    	totcomp--;                                                 //~v62SI~
    if (Ppnumlen)                                                  //~v62UI~
	    *Ppnumlen=numonlynumlen;   //numeric fld len for numonly field//~v62UI~
    if (Ppnumfld)                                                  //~v62UI~
    	*Ppnumfld=pnumfld;	//num fld addr                         //~v62UI~
    if (Ppcomplen)                                                 //~v51tI~
	    *Ppcomplen=totcomp;                                        //~v51tR~
//  return pcw; 	//next fld top addr                            //~v51tR~
    return pcwdelm; 	//next fld top addr                        //~v51tI~
}//tc_getfieldendaddr                                              //~v51oI~
//**************************************************************** //~v580I~
// get field end addr with quotation consideration                 //~v580I~
//p1:fld start addr                                                //~v580I~
//p2:record len                                                    //~v580I~
//p3:delm                                                          //~v580I~
//p4:addr of delm detected or 0 if no delm found                   //~v580I~
//p5:qchk option                                                   //~v580I~
//*ret :fld end addr or 0 if no delm found                         //~v580I~
//**************************************************************** //~v580I~
//char *tc_getfieldendaddrquote(char *Prec,int Preclen,char Pdelm,char *Pdelmaddr,int Popt)//~v62yR~
#ifdef UTF8UCS2                                                    //~va20R~
//char *tc_getfieldendaddrquote(char *Prec,char *Pdbcs,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt)//~va20R~//~va79R~
char *tc_getfieldendaddrquote(int Phandle,char *Prec,char *Pdbcs,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt)//~va79I~
#else                                                              //~va20R~
char *tc_getfieldendaddrquote(char *Prec,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt)//~v62yI~
#endif                                                             //~va20R~
{                                                                  //~v580I~
//#define CHAR_DQ          '\"'    //double quote                  //~va50R~
//#define CHAR_SQ          '\''    //single quote                  //~va50R~
	char *pcs,*pcdq,*pcsq,*pc,*pce;                                //~v580I~
    int chkdq,chksq,swinquote,fldlen,delm;                         //~v580R~
#ifdef UTF8UCS2                                                    //~va20R~
	char *pcd;                                                     //~va20R~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20R~
//*************************                                        //~v580I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=(Popt & PARM_UTF8FILE);                             //~va20I~
#endif                                                             //~va20R~
    pce=Prec+Preclen;  	//record end addr                          //~v580I~
    if (Pdelmaddr)                                                 //~v580I~
//    	fldlen=(int)((ULONG)Pdelmaddr-(ULONG)Prec);   //fld len           //~v580I~//~vafkR~
    	fldlen=(int)((ULPTR)Pdelmaddr-(ULPTR)Prec);   //fld len    //~vafkI~
    else                                                           //~v580I~
    	fldlen=Preclen;                                            //~v580I~
	if ((chkdq=Popt&PARM_DQUOTE),chkdq)     //'\"' chk             //~v580R~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	pcdq=UCVEBCUTF_umemchr(Sswebcfile,swutf8file,Prec,Pdbcs,SchDQ,fldlen);//~va50R~//~va79R~
    	pcdq=UCVEBCUTF_umemchr(Sswebcfile,swutf8file,Phandle,Prec,Pdbcs,SchDQ,fldlen);//~va79R~
    #else                                                          //~va50I~
		pcdq=UTF_memchr(swutf8file,Prec,Pdbcs,CHAR_DQ,fldlen);     //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
		pcdq=memchr(Prec,CHAR_DQ,(UINT)fldlen);                    //~v580R~
#endif                                                             //~va20R~
    else                                                           //~v580I~
    	pcdq=0;                                                    //~v580R~
	if ((chksq=Popt&PARM_SQUOTE),chksq)     //'\"' chk             //~v580R~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	pcsq=UCVEBCUTF_umemchr(Sswebcfile,swutf8file,Prec,Pdbcs,SchSQ,fldlen);//~va50R~//~va79R~
    	pcsq=UCVEBCUTF_umemchr(Sswebcfile,swutf8file,Phandle,Prec,Pdbcs,SchSQ,fldlen);//~va79R~
    #else                                                          //~va50I~
		pcsq=UTF_memchr(swutf8file,Prec,Pdbcs,CHAR_SQ,fldlen);     //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
		pcsq=memchr(Prec,CHAR_SQ,(UINT)fldlen);                    //~v580R~
#endif                                                             //~va20R~
    else                                                           //~v580I~
    	pcsq=0;                                                    //~v580R~
    if (!pcdq && !pcsq)                                            //~v580I~
//  	return Prec+fldlen;	//no quote before delm                 //~v62DR~
    	return Pdelmaddr;	//no delm addr changed                 //~v62DI~
	if (pcdq && pcsq)                                              //~v580I~
        if (pcdq<pcsq)                                             //~v580R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            delm=SchDQ;                                            //~va50I~
#else                                                              //~va50I~
            delm=CHAR_DQ;                                          //~v580R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        else                                                       //~v580I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            delm=SchSQ;                                            //~va50I~
#else                                                              //~va50I~
            delm=CHAR_SQ;                                          //~v580R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    else                                                           //~v580I~
        if (pcdq)                                                  //~v580I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            delm=SchDQ;                                            //~va50I~
#else                                                              //~va50I~
            delm=CHAR_DQ;                                          //~v580I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        else                                                       //~v580I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          	delm=SchSQ;                                            //~va50I~
#else                                                              //~va50I~
          	delm=CHAR_SQ;                                          //~v580I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (delm==SchDQ)                                               //~va50I~
#else                                                              //~va50I~
    if (delm==CHAR_DQ)                                             //~v580I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	pcs=pcdq;                                                  //~v580I~
    else                                                           //~v580I~
    	pcs=pcsq;                                                  //~v580I~
//search end of quatation                                          //~v580M~
    swinquote=1;                                                   //~v580I~
    for (pc=pcs+1;pc<pce;pc++)                                     //~v580I~
    {                                                              //~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
//		pcd=Pdbcs+(ULONG)pc-(ULONG)Prec;                           //~va20R~//~vafkR~
		pcd=Pdbcs+(ULPTR)pc-(ULPTR)Prec;                           //~vafkI~
#endif                                                             //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (UCVEBCUTF_eqascii(Sswebcfile,swutf8file,*pc,*pcd,delm))//~va50R~
    #else                                                          //~va50I~
    	if (UTF_eq(swutf8file,*pc,*pcd,delm))                      //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
    	if (*pc==delm)                                             //~v580I~
#endif                                                             //~va20R~
        {                                                          //~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	if (pc+1<pce && UCVEBCUTF_eqascii(Sswebcfile,swutf8file,*(pc+1),*(pcd+1),delm))	//(cotinuous)//~va50R~
    #else                                                          //~va50I~
        	if (pc+1<pce && UTF_eq(swutf8file,*(pc+1),*(pcd+1),delm))	//(cotinuous)//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
        	if (pc+1<pce && *(pc+1)==delm)	//""(cotinuous)        //~v580R~
#endif                                                             //~va20R~
            {                                                      //~v580I~
            	pc++;                                              //~v580I~
                continue;                                          //~v580I~
            }                                                      //~v580I~
            swinquote^=1;                                          //~v580I~
        }                                                          //~v580I~
        else                                                       //~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      if (UCVEBCUTF_eqascii_b2a(Sswebcfile,swutf8file,*pc,*pcd,'\\'))//~va50R~//~va79R~
        if (UCVEBCUTF_eqascii_b2a(Sswebcfile,swutf8file,Phandle,*pc,*pcd,'\\'))//~va79R~
    #else                                                          //~va50I~
        if (UTF_eq(swutf8file,*pc,*pcd,'\\'))                      //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
        if (*pc=='\\')                                             //~v580I~
#endif                                                             //~va20R~
        {                                                          //~v580I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	if (pc+1<pce && UCVEBCUTF_eqascii(Sswebcfile,swutf8file,*(pc+1),*(pcd+1),delm))	//\"(escape)//~va50R~
    #else                                                          //~va50I~
        	if (pc+1<pce && UTF_eq(swutf8file,*(pc+1),*(pcd+1),delm))	//\"(escape)//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
        	if (pc+1<pce && *(pc+1)==delm)	//\"(escape)           //~v580R~
#endif                                                             //~va20R~
            {                                                      //~v580I~
            	pc++;                                              //~v580I~
                continue;                                          //~v580I~
            }                                                      //~v580I~
        }                                                          //~v580I~
        else                                                       //~v580I~
        {                                                          //~v62yI~
//      if (*pc==Pdelm)                                            //~v62yR~
        	if (!swinquote)	//not in quote                         //~v580I~
            {                                                      //~va5pI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5pI~
            if (swutf8file)                                        //~va5pI~
            {                                                      //~va5pI~
              if (utfddmemchr_nonascii(0,Pdelmstr,Sdelmstrdbcs,*pc,*pcd,Sdelmstrlen))	//one of delm char//~va5pI~
	        	break;                                             //~va5pI~
            }                                                      //~va5pI~
            else                                                   //~va5pI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5pI~
            {                                                      //~va5pI~
#ifdef UTF8UCS2                                                    //~va20R~
             if (!*pcd)	//ascii                                    //~va20R~
#endif                                                             //~va20R~
              if (strchr(Pdelmstr,*pc))	//one of delm char         //~v62yI~
	        	break;                                             //~v580I~
            }//!utf8file                                           //~va5pI~
            }//!in quote                                           //~va5pI~
        }                                                          //~v62yI~
    }                                                              //~v580I~
    if (pc>=pce)                                                   //~v580I~
    	return 0;                                                  //~v580I~
    return pc;                                                     //~v580I~
}//tc_getfieldendaddrquote                                         //~v580I~
//**************************************************************** //~v40MR~
// calc fld width of non fmt fld                                   //~v40MR~
//p1:fld end(' ') addr                                             //~v40MR~
//p2:record residual len(from fld end)                             //~v40MR~
//p3:fmtfld tbl                                                    //~v40MR~
//p4:input:current fldno, output:last fldno for non fmt fld        //~v40MR~
//p5:input:current fld len, output:concat len when non fmt fld     //~v40MR~
//*ret :fld end addr                                               //~v40MR~
//**************************************************************** //~v40MR~
//char *tc_chknonfmtfieldwidth(char *Prec,int Preclen,char *Pfmtfldtbl,//~v580R~
#ifdef UTF8UCS2                                                    //~va20I~
char *tc_chknonfmtfieldwidth(int *Pparm,PULINEH Pplh,char *Prec,char *Pdbcs,int Preclen,char *Pfmtfldtbl,//~va20R~
#else                                                              //~va20I~
char *tc_chknonfmtfieldwidth(int *Pparm,char *Prec,int Preclen,char *Pfmtfldtbl,//~v580R~
#endif                                                             //~va20I~
							int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw)//~v51tR~
{                                                                  //~v40MR~
//  int ii,bytepos,ch,bit,fldno,rlen,len,idxlast,nofmtsw=0;//~v40MR~//~vaf9R~
    int ii,bytepos,ch,bit,fldno,rlen,len,idxlast=0,nofmtsw=0;      //~vaf9I~
    char  *pc,*rec,*pclast;                                        //~v40MR~
//  LONG wklv[4];                                                  //~v58xI~//~vafkR~
    SLPTR wklv[4];                                                 //~vafkI~
#ifdef UTF8UCS2                                                    //~va20I~
	char *pcd;                                                     //~va20I~
#endif                                                             //~va20I~
//****************************************                         //~v40MR~
//calc non fmt fld concatinated len                                //~v40MR~
    fldno=*Ppfldno;                                                //~v40MR~
	rlen=Preclen;                                                  //~v40MR~
    pc=Prec+1;  //for 1st loop skip delm                           //~v62qI~
	rec=Prec;                                                      //~v40MR~
    pclast=rec;			//last end of fld space addr               //~v40MR~
    for (ii=fldno;;ii++)                               //~v40MR~
    {                                                              //~v40MR~
//      bytepos=(ii-1)/8;		                                   //~v51xR~
        bytepos=(ii-1);                                            //~v51xR~
        ch=*(Pfmtfldtbl+bytepos);                                  //~v40MR~
//      bit=(0x80>>((ii-1)%8));                                    //~v51xR~
        bit=FMTFLAG_FMT;                                           //~v51xR~
        if ((ch & bit))     //use this fld                         //~v40MR~
            break;                                                 //~v40MR~
        nofmtsw=1;                                                 //~v40MR~
        pclast=rec;                                                //~v40MR~
        idxlast=ii;                                                //~v40MR~
        if (!rec)                                                  //~v40MR~
        	break;                                                 //~v40MR~
   		rec=pc;         //for 2nd loop delm advanced               //~v62qI~
//        len=(int)umemspnc(rec,' ',(UINT)rlen);                   //~v51oR~
//        rec+=len;                                                //~v51oR~
//        rlen-=len;                                               //~v51oR~
////      pc=memchr(rec,' ',(UINT)rlen);                           //~v51oR~
//        pc=memchr(rec,Sdelm,(UINT)rlen);                         //~v51oR~
//  	pc=tc_getfieldendaddr(rec,rlen);                           //~v51tR~
//  	pc=tc_getfieldendaddr(rec,0,rlen,0,0,0);                   //~v51xR~
//  	pc=tc_getfieldendaddr(rec,0,rlen,0,0,0,ch);                //~v580R~
//  	pc=tc_getfieldendaddr(Pparm,rec,0,rlen,0,0,0,ch);          //~v58xR~
//  	pc=tc_getfieldendaddr(Pparm,rec,0,rlen,0,0,0,ch,wklv);     //~v62UR~
#ifdef UTF8UCS2                                                    //~va20I~
//		pcd=Pdbcs+((ULONG)rec-(ULONG)Prec);                        //~va20I~//~vafkR~
		pcd=Pdbcs+((ULPTR)rec-(ULPTR)Prec);                        //~vafkI~
    	pc=tc_getfieldendaddr(Pparm,Pplh,rec,pcd,rlen,0/*wkdata*/,0/*wkdbcs*/,0/*complen*/,ch,wklv,0,0);//~va20R~
#else                                                              //~va20I~
    	pc=tc_getfieldendaddr(Pparm,rec,0,rlen,0,0,0,ch,wklv,0,0); //~v62UI~
#endif                                                             //~va20I~
        if (pc)                                                    //~v40MR~
//	        len=(int)((ULONG)pc-(ULONG)rec);                       //~v40MR~//~vafkR~
	        len=(int)((ULPTR)pc-(ULPTR)rec);                       //~vafkI~
        else                                                       //~v40MR~
        	len=rlen;                                              //~v40MR~
        rec=pc;                                                    //~v40MR~
        rlen-=len;                                                 //~v40MR~
        if (pc)                                                    //~v431I~
        {                                                          //~v431I~
        	pc++;           //skip seperator                       //~v431I~
        	rlen--;                                                //~v431I~
        }                                                          //~v431I~
    }                                                              //~v40MR~
    if (pclast!=Prec)                                              //~v40MR~
    {                                                              //~v40MR~
        if (pclast)                                                //~v40MR~
//	        *Ppfldlen+=(int)((ULONG)pclast-(ULONG)Prec);           //~v40MR~//~vafkR~
	        *Ppfldlen+=(int)((ULPTR)pclast-(ULPTR)Prec);           //~vafkI~
        else                                                       //~v40MR~
        	*Ppfldlen+=Preclen;                                    //~v40MR~
    	*Ppfldno=idxlast;                                          //~v40MR~
    }                                                              //~v40MR~
    if (Ppnofmtsw)                                                 //~v40MR~
    	*Ppnofmtsw=nofmtsw;                                        //~v40MR~
    return pclast;                                                 //~v40MR~
}//tc_chknonfmtfieldwidth                                          //~v40MR~
//****************************************************************
// expand data by align specification
//*ret :0, 1:updated,4:over maxfld
//****************************************************************
int tc_fmtdata(PUCLIENTWE Ppcw,PULINEH Pplh,int *Pparm,
//  		int *Pfmttb,char *Paligntb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs)//~v51tR~
//  		int *Pfmttb,char *Paligntb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs,char *Ppcwdata,char *Ppcwdbcs)//~v51xR~
    		int *Pfmttb,char *Pfmtfldtbl,char *Pwdata,char *Pwdbcs,char *Ppcwdata,char *Ppcwdbcs)//~v51xI~
{
    int len,rc=0,rlen,capopt,fldno,leftalign,fldlen,newlen,wdatalen,spacelen;
    char  *pdata,*pc,*pcw,*pdbcs,*pcd,*wdata,*wdbcs;               //~v431R~
    int   rlen0,updsw=0,maxfldno,nofmtsw;                          //~v40MR~
    int   netlen,lastsw;                                           //~v431R~
    int   upno,upno2;                                              //~v58xR~
    int   uplen;                                                   //~v79rI~
    char *pflddata,*pflddbcs;                                      //~v51tI~
    int complen;                                                   //~v51tR~
    int ch;                                                        //~v51xI~
    char prevdelm=0,curdelm;	//detected delm	                   //~v62yR~
    char prevdelmdbcs=0,curdelmdbcs;	//detected delm            //~vbn0I~
//  LONG wklv[4];                                                  //~v58xI~//~vafkR~
    SLPTR wklv[4];                                                 //~vafkI~
    int maxnumonlynumlen,numonlynumlen,len2;                       //~v62UI~
    char *pnumfld;                                                 //~v62UI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
    int handle;                                                    //~va79I~
    char *pcd2;                                                    //~va20R~
#endif                                                             //~va20I~
//****************************************
	maxfldno=Pparm[PARM_MAXFLDNO];                                 //~v40MR~
	wdatalen=Pparm[PARM_MAXDATALEN];
	spacelen=Pparm[PARM_SPACELEN];
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    memset(Pwdata,Schspace,(UINT)wdatalen);                        //~va50I~
#else                                                              //~va50I~
    memset(Pwdata,' ',(UINT)wdatalen);
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    memset(Pwdbcs,0,(UINT)wdatalen);
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
#endif                                                             //~va20I~

	capopt=CHARCAP2_OVFCUT|CHAROPBREP|CHARCAP2_NOREV;

//  if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))                    //~va2aR~
//  {                                                              //~va2aR~
//  	updsw=1;                                                   //~va2aR~
//  	if (rc=undoupdate(Ppcw,Pplh,UUHTREP),rc)	//prepare undo and update process//~va2aR~
//          	return rc;                                         //~va2aR~
//  }                                                              //~va2aR~
//  else                                                           //~va2aR~
    	capopt|=CHARCAP2_UNDO;

	pc=pdata=Pplh->ULHdata;
	pdbcs=Pplh->ULHdbcs;
    rlen=rlen0=Pplh->ULHlen;
//  pce=pc+rlen;                                                   //~v431R~
    wdata=Pwdata+TOPSPACELEN;                                      //~v40RR~
    wdbcs=Pwdbcs+TOPSPACELEN;                                      //~v40RR~
//  for (fldno=0;pc<pce;)                                          //~v431R~
    for (fldno=0;;)                                                //~v431I~
    {
        lastsw=0;                                                  //~v431I~
#ifdef UTF8UCS2                                                    //~va20I~
//      pcd2=pdbcs+((ULONG)pc-(ULONG)pdata);                       //~va20R~//~vafkR~
        pcd2=pdbcs+((ULPTR)pc-(ULPTR)pdata);                       //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	len=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd2,rlen);//~va50R~
    #else                                                          //~va50I~
    	len=(int)UTF_UMEMSPNC(swutf8file,pc,pcd2,' ',rlen);        //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	len=(int)umemspnc(pc,' ',(UINT)rlen);
#endif                                                             //~va20I~
        pc+=len;
        rlen-=len;
        if (rlen<=0)
//        if (!fldno || Sdelm==' ')//all space or space after delm=' '//~v62yR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (!fldno || prevdelm==Schspace)//all space or space after delm=' '//~va50I~
#else                                                              //~va50I~
          if (!fldno || prevdelm==' ')//all space or space after delm=' '//~v62yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        	break;
//alignment chk
//      if (*(Paligntb+fldno/8) & (0x80>>(fldno%8)))               //~v51xR~
//      	leftalign=1;                                           //~v51xR~
//      else                                                       //~v51xR~
//      	leftalign=0;                                           //~v51xR~

        if (fldno>=maxfldno)                                       //~v40MR~
        {                                                          //~v431I~
        	lastsw=1;                                              //~v431I~
        	break;
        }                                                          //~v431I~
//      pcd=pdbcs+((ULONG)pc-(ULONG)pdata);                        //~v51tI~//~vafkR~
        pcd=pdbcs+((ULPTR)pc-(ULPTR)pdata);                        //~vafkI~

        fldno++;
        fldlen=Pfmttb[fldno];
//      pcw=memchr(pc,' ',(UINT)rlen);                             //~v431R~
//      pcw=memchr(pc,Sdelm,(UINT)rlen);                           //~v51oR~
//      pcw=tc_getfieldendaddr(pc,rlen);                           //~v51tR~
//      pcw=tc_getfieldendaddr(pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen);//~v51xR~
        ch=Pfmtfldtbl[fldno-1];                                    //~v51xI~
        if (ch & FMTFLAG_LEFTALIGN)                                //~v51xI~
        	leftalign=1;                                           //~v51xI~
        else                                                       //~v51xI~
        	leftalign=0;                                           //~v51xI~
        maxnumonlynumlen=Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD];//~v62UI~
//      pcw=tc_getfieldendaddr(pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen,ch);//~v580R~
//      pcw=tc_getfieldendaddr(Pparm,pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen,ch);//~v58xR~
//      pcw=tc_getfieldendaddr(Pparm,pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen,ch,wklv);//~v62UR~
#ifdef UTF8UCS2                                                    //~va20I~
        pcw=tc_getfieldendaddr(Pparm,Pplh,pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen,ch,wklv,//~va20I~
#else                                                              //~va20I~
        pcw=tc_getfieldendaddr(Pparm,pc,pcd,rlen,Ppcwdata,Ppcwdbcs,&complen,ch,wklv,//~v62UI~
#endif                                                             //~va20I~
        						&numonlynumlen,&pnumfld);          //~v62UR~
        nofmtsw=0;                                                 //~v58xI~
        if (pcw)
        {                                                          //~v40MR~
//	        len=(int)((ULONG)pcw-(ULONG)pc);                       //~vafkR~
	        len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~vafkI~
//  		pcw=tc_chknonfmtfieldwidth(pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~v580R~
#ifdef UTF8UCS2                                                    //~va20I~
//	        pcd2=pdbcs+((ULONG)pcw-(ULONG)pdata);                  //~va20I~//~vafkR~
	        pcd2=pdbcs+((ULPTR)pcw-(ULPTR)pdata);                  //~vafkI~
    		pcw=tc_chknonfmtfieldwidth(Pparm,Pplh,pcw,pcd2,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~va20R~
#else                                                              //~va20I~
    		pcw=tc_chknonfmtfieldwidth(Pparm,pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);//~v580I~
#endif                                                             //~va20I~
            fldlen=Pfmttb[fldno];                                  //~v40MR~
            if (nofmtsw)    //  	no fmt field left align        //~v40MR~
            {                                                      //~v51tI~
	        	leftalign=1;                                       //~v40MR~
                complen=len;                                       //~v51tI~
            }                                                      //~v51tI~
        }                                                          //~v40MR~
        else
        	len=rlen;
//      if (Snumonlysw>=0)	//not compress mode                    //~v51xR~
        if (!(ch & FMTFLAG_COMPRESS))	//not compress mode        //~v51xI~
        	complen=len;                                           //~v51tI~
		if (pcw)                                                   //~v62yI~
        {                                                          //~v74DI~
//        if (len)                                                 //~v66vR~
		  {                                                        //~vbn0I~
        	curdelm=*pcw;                                          //~v62yR~
	        curdelmdbcs=*(pdbcs+PTRDIFF(pcw,pdata));               //~vbn0I~
          }                                                        //~vbn0I~
//        else          //numonly field has no preceding non-num fields//~v66vR~
//          curdelm=' ';                                           //~v66vR~
          if (!len && numonlynumlen)	//numeric only fld len=0   //~v74DI~
          {                                                        //~vbn0I~
           if ((pnumfld+numonlynumlen)>=(pdata+rlen))              //~vbn0I~
           {                                                       //~vbn0I~
            curdelm=0;                                             //~vbn0I~
	        curdelmdbcs=0;                                         //~vbn0I~
           }                                                       //~vbn0I~
           else                                                    //~vbn0I~
           {                                                       //~vbn0I~
            curdelm=*(pnumfld+numonlynumlen);                      //~v74DI~
	        curdelmdbcs=*(pdbcs+PTRDIFF(pnumfld+numonlynumlen,pdata));//~vbn0I~
           }                                                       //~vbn0I~
          }                                                        //~vbn0I~
        }                                                          //~v74DI~
        else                                                       //~v62yI~
        {                                                          //~vbn0I~
        	curdelm=0;                                             //~v62yI~
	        curdelmdbcs=0;                                         //~vbn0I~
        }                                                          //~vbn0I~
        if ((ch & FMTFLAG_COMPRESS))	//not compress mode        //~v62RI~
        	netlen=complen;                                        //~v62RI~
        else                                                       //~v62RI~
//      if (!nofmtsw && Sdelm!=' ')                                //~v62yR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (!nofmtsw && curdelm!=Schspace)                         //~va50I~
#else                                                              //~va50I~
        if (!nofmtsw && curdelm!=' ')                              //~v62yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        {                                                          //~va20I~
//      	netlen=len-(int)umemrspnc(pc,' ',(UINT)len);//cut last space//~v51tR~
#ifdef UTF8UCS2                                                    //~va20I~
//	       pcd2=pdbcs+((ULONG)pc-(ULONG)pdata);                   //~va20I~//~vafkR~
	       pcd2=pdbcs+((ULPTR)pc-(ULPTR)pdata);                    //~vafkI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	netlen=complen-(int)UCVEBCUTF_umemspnc_space(Sswebcfile,swutf8file,pc,pcd,complen);//cut last space//~va50R~
    #else                                                          //~va50I~
        	netlen=complen-(int)UTF_UMEMRSPNC(swutf8file,pc,pcd,' ',complen);//cut last space//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	netlen=complen-(int)umemrspnc(pc,' ',(UINT)complen);//cut last space//~v51tR~
#endif                                                             //~va20I~
        }                                                          //~va20I~
        else                                                       //~v431M~
//      	netlen=len;                                            //~v51tR~
        	netlen=complen;                                        //~v51tI~
//      pcd=pdbcs+((ULONG)pc-(ULONG)pdata);                        //~v51tR~
        if (fldno>1)                                               //~v431R~
        {                                                          //~v62yI~
//        	*wdata=Sdelm;                                          //~v62yR~
          	if (prevdelm)                                          //~v62yR~
            {                                                      //~v62KI~
              if (Sswrepdelm)	//not del input delm               //~v62KI~
              {                                                    //~vbmuI~
          	    memcpy(wdata,Soutdelmstr,(UINT)spacelen);          //~v62KR~
          	    memcpy(wdbcs,Soutdelmstrdbcs,(UINT)spacelen);      //~vbmuI~
              }                                                    //~vbmuI~
              else                                                 //~v62KI~
              {                                                    //~v62KI~
          		*wdata=prevdelm;                                   //~v62yR~
          		*wdbcs=prevdelmdbcs;                               //~vbn0I~
	          	memcpy(wdata+1,Soutdelmstr,(UINT)(spacelen-1));    //~v62KR~
          	    memcpy(wdbcs+1,Soutdelmstrdbcs,(UINT)(spacelen-1));//~vbmuI~
              }                                                    //~v62KI~
            }                                                      //~v62KI~
        }                                                          //~v62yI~
        wdata+=spacelen;		//next pos                         //~v40RI~
        wdbcs+=spacelen;		//next pos                         //~v40RI~
//  	if (Ppcwdata) 	//compressmode                             //~v51xR~
        if (ch & FMTFLAG_COMPRESS)	//compress mode                //~v51xI~
        {                                                          //~v51tI~
        	pflddata=Ppcwdata;                                     //~v51tR~
        	pflddbcs=Ppcwdbcs;                                     //~v51tR~
        }                                                          //~v51tI~
        else                                                       //~v51tI~
        {                                                          //~v51tI~
        	pflddata=pc;                                           //~v51tR~
        	pflddbcs=pcd;                                          //~v51tR~
        }                                                          //~v51tI~
        if (wklv[1]!=-1)	//fld is numeric                       //~v79rI~
        	uplen=Pfmtfldtbl[fldno-1+MAXFIELD];  //field has underpoint in some line//~v79rI~
        else                                                       //~v79rI~
        	uplen=0;                                               //~v79rI~
        		                                                   //~v51tI~
//      if (leftalign)                                             //~v79rR~
        if (leftalign && !uplen)                                   //~v79rI~
        {
//      	memcpy(wdata,pc,(UINT)len);                            //~v431R~
//      	memcpy(wdbcs,pcd,(UINT)len);                           //~v431R~
//      	memcpy(wdata,pc,(UINT)netlen);                         //~v51tR~
//      	memcpy(wdbcs,pcd,(UINT)netlen);                        //~v51tR~
        	memcpy(wdata,pflddata,(UINT)netlen);                   //~v51tR~
        	memcpy(wdbcs,pflddbcs,(UINT)netlen);                   //~v51tR~
		}
        else
        {
//      	memcpy(wdata+fldlen-len,pc,(UINT)len);                 //~v431R~
//      	memcpy(wdbcs+fldlen-len,pcd,(UINT)len);                //~v431R~
//      	memcpy(wdata+fldlen-netlen,pc,(UINT)netlen);           //~v51tR~
//      	memcpy(wdbcs+fldlen-netlen,pcd,(UINT)netlen);          //~v51tR~
          	if (wklv[1]!=-1)	//fld is numeric                   //~v58xR~
          	{                                                      //~v58xR~
        		upno=Pfmtfldtbl[fldno-1+MAXFIELD];  //field has underpoint in some line//~v58xR~
            	if (upno)      //digit count of ".xxx"             //~v58xR~
            	{                                                  //~v58xI~
        			upno2=(wklv[1]&UCALC_UPMASK);	//paddin space for underpoint digit count//~v58xI~
            		if (upno2)                                     //~v58xR~
                    {                                              //~v58xI~
                    	upno2++;                                   //~v58xI~
            			upno-=upno2;                               //~v58xR~
                        if (upno<0)                                //~v58xI~
                        	upno=0;		//for safety               //~v58xI~
                    }                                              //~v58xI~
                }                                                  //~v58xI~
          	}                                                      //~v58xR~
          	else                                                   //~v58xR~
        		upno=0;                                            //~v58xR~
//      	memcpy(wdata+fldlen-netlen,pflddata,(UINT)netlen);     //~v58xR~
//      	memcpy(wdbcs+fldlen-netlen,pflddbcs,(UINT)netlen);     //~v58xR~
        	memcpy(wdata+fldlen-netlen-upno,pflddata,(UINT)netlen);//~v58xI~
        	memcpy(wdbcs+fldlen-netlen-upno,pflddbcs,(UINT)netlen);//~v58xR~
		}
//      wdata+=fldlen+spacelen;		//next pos                     //~v40RR~
//      wdbcs+=fldlen+spacelen;		//next pos                     //~v40RR~
        wdata+=fldlen;		//next pos                             //~v40RI~
        wdbcs+=fldlen;		//next pos                             //~v40RI~
        if (ch & FMTFLAG_NUMONLY && maxnumonlynumlen 	//num only field exist//~v62UR~
        && numonlynumlen)   //num data exit                        //~v62UI~
        {                                                          //~v62UI~
            if (fldlen)  //nonum field exist                       //~v62UI~
            {                                                      //~v62UI~
              	if (!curdelm)	//not end with nonum fld           //~v62UR~
                {                                                  //~vbn0I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//              	curdelm=Schspace;                              //~vaz8R~
                	curdelm=(UCHAR)Schspace;                       //~vaz8I~
                	curdelmdbcs=0;                                 //~vbn0I~
#else                                                              //~va50I~
                	curdelm=' ';                                   //~v62UI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				}                                                  //~vbn0I~
                if (Sswrepdelm)                                    //~v62UR~
                {                                                  //~vbn0I~
                    memcpy(wdata,Soutdelmstr,(UINT)spacelen);      //~v62UR~
                    memcpy(wdbcs,Soutdelmstrdbcs,(UINT)spacelen);  //~vbn0I~
                }                                                  //~vbn0I~
                else                                               //~v62UR~
                {                                                  //~v62UR~
                    *wdata=curdelm;                                //~v62UR~
                    *wdbcs=curdelmdbcs;                            //~vbn0I~
                    memcpy(wdata+1,Soutdelmstr,(UINT)(spacelen-1));//~v62UR~
                    memcpy(wdbcs+1,Soutdelmstrdbcs,(UINT)(spacelen-1));//~vbn0I~
                }                                                  //~v62UR~
                wdata+=spacelen;                                   //~v62UR~
                wdbcs+=spacelen;                                   //~v62UI~
            }                                                      //~v62UI~
        	len2=maxnumonlynumlen-numonlynumlen;                   //~v62UI~
            if (len2>0)                                            //~v62UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                memset(wdata,Schspace,(UINT)len2);  //right justified//~va50I~
#else                                                              //~va50I~
                memset(wdata,' ',(UINT)len2);  //right justified   //~v62UI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            memcpy(wdata+len2,pnumfld,(UINT)numonlynumlen);        //~v62UR~
            wdata+=maxnumonlynumlen;                               //~v62UR~
            wdbcs+=maxnumonlynumlen;                               //~v62UI~
            pcw=pnumfld+numonlynumlen;                             //~v62UR~
//          len=(int)((ULONG)pcw-(ULONG)pc);                       //~v62UR~//~vafkR~
            len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~vafkI~
            if (len>=rlen)                                         //~v62UR~
                pcw=0;                                             //~v62UR~
            else                                                   //~v62UR~
            {                                                      //~vbn0I~
                curdelm=*pcw;                                      //~v62UR~
                curdelmdbcs=*(pdbcs+PTRDIFF(pcw,pdata));           //~vbn0I~
            }                                                      //~vbn0I~
        }                                                          //~v62UI~
        rlen-=len;
        if (!pcw)
        	break;
        prevdelm=curdelm;                                          //~v62yR~
        prevdelmdbcs=curdelmdbcs;                                  //~vbn0I~
		pc=pcw;
        pc++;                                                      //~v431I~
        rlen--;                                                    //~v431I~
	}
//  if (fldno>=maxfldno)    //remain data                          //~v431R~
    if (lastsw)             //remain data                          //~v431I~
    {
//      wdata+=fldlen;		//next pos                             //~v42oR~
//      wdbcs+=fldlen;		//next pos                             //~v42oR~
//      if (fldno>1)                                               //~v62yR~
        if (fldno>=1)                                              //~v62yI~
        {                                                          //~v62yI~
//      	*wdata=Sdelm;                                          //~v62yR~
	        if (prevdelm)                                          //~v62yR~
            {                                                      //~v62KI~
              if (Sswrepdelm)	//not del input delm               //~v62KI~
              {                                                    //~vbn0I~
          	    memcpy(wdata,Soutdelmstr,(UINT)spacelen);          //~v62KR~
          	    memcpy(wdbcs,Soutdelmstrdbcs,(UINT)spacelen);      //~vbn0I~
              }                                                    //~vbn0I~
              else                                                 //~v62KI~
              {                                                    //~v62KI~
    			*wdata=prevdelm;                                   //~v62yR~
    			*wdbcs=prevdelmdbcs;                               //~vbn0I~
	          	memcpy(wdata+1,Soutdelmstr,(UINT)(spacelen-1));    //~v62KR~
	          	memcpy(wdbcs+1,Soutdelmstrdbcs,(UINT)(spacelen-1));//~vbn0I~
              }                                                    //~v62KI~
            }                                                      //~v62KI~
        }                                                          //~v62yI~
        wdata+=spacelen;		//next pos                         //~v42oI~
        wdbcs+=spacelen;		//next pos                         //~v42oI~
        memcpy(wdata,pc,(UINT)rlen);
//      pcd=pdbcs+((ULONG)pc-(ULONG)pdata);                        //~vafkR~
        pcd=pdbcs+((ULPTR)pc-(ULPTR)pdata);                        //~vafkI~
        memcpy(wdbcs,pcd,(UINT)rlen);
        wdata+=rlen;
    }
//  else                                                           //~v42kR~
//  	wdata-=spacelen;                                           //~v42kR~
//  newlen=(int)((ULONG)wdata-(ULONG)Pwdata);                      //~vafkR~
    newlen=(int)((ULPTR)wdata-(ULPTR)Pwdata);                      //~vafkI~
    if (newlen<rlen0)
        newlen=rlen0;       //clear up to eol
    if (newlen>rlen0
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  ||  XESUB_EBCUTF8_memcmpeq(Sswebcfile,swutf8file,Pwdata,Pwdbcs,pdata,pdbcs,(UINT)newlen))//~va50R~//~va79R~
//  ||  XESUB_EBCUTF8_memcmpeq(Sswebcfile,swutf8file,handle,Pwdata,Pwdbcs,pdata,pdbcs,(UINT)newlen))//~va79I~//~vb30R~
    ||  XESUB_EBCUTF8_memcmpeq(Sswebcfile,swutf8file,handle,Pwdata,Pwdbcs,pdata,pdbcs,newlen))//~vb30I~
  #else                                                            //~va50I~
    ||  XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,Pwdata,Pwdbcs,pdata,pdbcs,(UINT)newlen))//~va20I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    ||  memcmp(Pwdata,pdata,(UINT)newlen))
#endif                                                             //~va20I~
    {
    	updsw=1;
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		if (Sswebcfile)                                            //~va50R~
        	capopt|=CHARCAP2_SRCEB;                                //~va50I~
#endif                                                             //~va50I~
		if (rc=charcap2(Ppcw,capopt,Pwdata,Pwdbcs,newlen,Pplh,0),rc)
 		{
        	if (rc==UALLOC_FAILED)
            	return rc;
    		return 4;		//ovf
        }
	}
    return updsw;
}//tc_fmtdata
//**************************************************************** //~v40RI~
// insert hdr line                                                 //~v40RI~
//*ret :rc                                                         //~v40RI~
//**************************************************************** //~v40RI~
//int tc_isrthdr(PUCLIENTWE Ppcw,PULINEH Pplh,int *Pparm,          //~v62wR~
int tc_isrthdr(PUCLIENTWE Ppcw,PULINEH Pplholdhdr,PULINEH Pplh,int *Pparm,//~v62wI~
//			int *Pfmttb,char *Pwdata)                              //~v62VR~
			int *Pfmttb,char *Pwdata,char *Pfmtfldtbl)             //~v62VR~
{                                                                  //~v40RI~
    int rc=0,fldno,fldlen,newlen,wdatalen,spacelen;                //~v40RR~
    int len;                                                       //~v62KI~
    char  *wdata;                                                  //~v40RR~
    int   maxfldno;                                                //~v40RR~
    PULINEH plhprev;                                               //~v40RI~
    int maxnumonlynumlen,ch;                                       //~v62VI~
//****************************************                         //~v40RI~
	maxfldno=Pparm[PARM_MAXFLDNO];                                 //~v40RI~
	wdatalen=Pparm[PARM_MAXDATALEN];                               //~v40RI~
	spacelen=Pparm[PARM_SPACELEN];                                 //~v40RI~
    wdata=Pwdata;                                                  //~v40RI~
//* cv later                                                       //~va50I~
    memset(wdata,' ',(UINT)wdatalen);                              //~v40RR~
//edit hdr line                                                    //~v40RI~
    *wdata=TCHDR_LINEID;                                           //~v40RR~
    wdata=Pwdata+TOPSPACELEN;                                      //~v40RI~
    for (fldno=1;fldno<=maxfldno;fldno++)                          //~v40RR~
    {                                                              //~v40RI~
                                                                   //~v40RI~
        *wdata=TCHDR_FLDSEPID;                                     //~v40RR~
//      if (spacelen)                                              //~v62zR~
//          memset(wdata+1,TCHDR_FLDSEPCONTID,(UINT)(spacelen-1)); //~v62zR~
//      wdata+=spacelen;		//next pos                         //~v62zR~
        fldlen=Pfmttb[fldno];                                      //~v40RI~
        maxnumonlynumlen=Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD];//~v62VI~
        ch=Pfmtfldtbl[fldno-1];                                    //~v62VI~
        if (ch & FMTFLAG_NUMONLY && maxnumonlynumlen) 	//num only field exist//~v62VI~
        {                                                          //~v62VI~
            if (fldlen)                                            //~v62VI~
            	fldlen+=spacelen;                                  //~v62VI~
			fldlen+=maxnumonlynumlen;                              //~v62VR~
        }                                                          //~v62VI~
//      if (!fldlen)                                               //~v62KR~
//      	for (fldno++;fldno<maxfldno;fldno++)                   //~v62zR~
//      	for (;fldno<maxfldno;fldno++)                          //~v62KR~
//          {                                                      //~v62KR~
//          	if ((fldlen=Pfmttb[fldno])!=0)                     //~v62KR~
//              	break;                                         //~v62KR~
//              if (spacelen>1 && fldno<10)                        //~v62zR~
//   	       		*(wdata+1)='0'+fldno;                          //~v62zR~
//  		    wdata+=spacelen;		//next pos                 //~v62zR~
//  		    *wdata=TCHDR_FLDSEPID;                             //~v62zR~
//          }                                                      //~v62KR~
        if (fldlen)                                                //~v40RR~
        {                                                          //~v40RI~
//      	*wdata=Sfldid[fldno-1];                                //~v62zR~
//      	memset(wdata+1,TCHDR_FLDCONTID,(UINT)(fldlen-1));      //~v62zI~
            len=fldlen+spacelen-1;  //space after FLDSEPID         //~v62KI~
            if (fldno<10)                                          //~v62zI~
            {                                                      //~v62zI~
//              if (spacelen>1)                                    //~v62KR~
                if (len>0)                                         //~v62KI~
                {                                                  //~v62KI~
     	       		*(wdata+1)=(char)('0'+fldno);                  //~v62DR~
// 		     	memset(wdata+2,TCHDR_FLDCONTID,(UINT)fldlen);      //~v62KR~
                	if (--len>0)                                   //~v62KI~
   		     			memset(wdata+2,TCHDR_FLDCONTID,(UINT)len); //~v62KI~
                }                                                  //~v62KI~
            }                                                      //~v62zI~
            else                                                   //~v62zI~
            {                                                      //~v62zI~
//              if (spacelen>1)                                    //~v62KR~
				if (len>1)                                         //~v62KR~
                {                                                  //~v62KI~
            		*(wdata+1)=(char)('0'+(fldno/10)%10);          //~v62DR~
            	*(wdata+2)=(char)('0'+(fldno%10));                 //~v62DR~
// 		     	memset(wdata+3,TCHDR_FLDCONTID,(UINT)(fldlen-1));  //~v62KR~
					len-=2;                                        //~v62KI~
                    if (len>0)                                     //~v62KI~
   		     		memset(wdata+3,TCHDR_FLDCONTID,(UINT)len);     //~v62KI~
                }                                                  //~v62KI~
            }                                                      //~v62zI~
//  	    wdata+=spacelen;		//next pos                     //~v62KR~
//  	    wdata+=fldlen;		//next pos                         //~v62KR~
        }                                                          //~v40RI~
//      wdata+=spacelen;		//next pos                         //~v62zR~
//      wdata+=fldlen;		//next pos                             //~v62zR~
        wdata+=spacelen;		//next pos                         //~v62KI~
  	    wdata+=fldlen;		//next pos                             //~v62KI~
	}                                                              //~v40RI~
    strcpy(wdata,TCHDR_LINEID_TRAILER);                            //~v40RI~
    wdata+=TCHDR_LINEID_TRAILERSZ;                                 //~v40RR~
// newlen=(int)((ULONG)wdata-(ULONG)Pwdata);                      //~v40RI~//~vafkR~
   newlen=(int)((ULPTR)wdata-(ULPTR)Pwdata);                       //~vafkI~
  	if (Pplholdhdr)	//replace old                                  //~v62wI~
    	if ((rc=lcmddel(Ppcw,Pplholdhdr,Pplholdhdr,1,0,1))!=0)//1line del,no csr set to next line//~v62wI~
    		return rc;                          //undo prepaired   //~v62wI~
    plhprev=UGETQPREV(Pplh);                                       //~v40RI~
    if (!plhprev)       //top hdr                                  //~v40RI~
        plhprev=Pplh;                                              //~v40RI~
//*fcmdisrtline do a2b                                             //~va50I~
    rc=fcmdisrtline(Ppcw,plhprev,Pwdata,newlen);                   //~v40RI~
    return rc;                                                     //~v40RI~
}//tc_isrthdr                                                      //~v40RI~
//**************************************************************** //~v62wI~
// header line chk                                                 //~v62wI~
//*ret :rc                                                         //~v62wI~
//**************************************************************** //~v62wI~
int tc_ishdrline(PULINEH Pplh)                                     //~v62wI~
{                                                                  //~v62wI~
    int len;                                                       //~v62wI~
    char  *pdata;                                                  //~v62wI~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20R~
    int handle;                                                    //~va79R~
    char *pdbcs;                                                   //~va20I~
#endif                                                             //~va20I~
//****************************************                         //~v62wI~
    if (!(len=Pplh->ULHlen))                                       //~v62wR~
    	return 0;                                                  //~v62wI~
    pdata=Pplh->ULHdata;                                           //~v62wR~
#ifdef UTF8UCS2                                                    //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20R~
	swutf8file=PLHUTF8MODE(Pplh);                                  //~va20R~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  if (UCVEBCUTF_neascii_b2a(Sswebcfile,swutf8file,*pdata,*pdbcs,TCHDR_LINEID))//~va50R~//~va79R~
    if (UCVEBCUTF_neascii_b2a(Sswebcfile,swutf8file,handle,*pdata,*pdbcs,TCHDR_LINEID))//~va79I~
  #else                                                            //~va50I~
    if (UTF_ne(swutf8file,*pdata,*pdbcs,TCHDR_LINEID))             //~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (*pdata!=TCHDR_LINEID)                                      //~v62wI~
#endif                                                             //~va20I~
    	return 0;                                                  //~v62wI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  if (!XESUB_EBCUTF8_umemmem_bandl(Sswebcfile,swutf8file,pdata,pdbcs,TCHDR_LINEID_TRAILER,len,TCHDR_LINEID_TRAILERSZ))//~va50R~//~va79R~
    if (!XESUB_EBCUTF8_umemmem_bandl(Sswebcfile,swutf8file,handle,pdata,pdbcs,TCHDR_LINEID_TRAILER,len,TCHDR_LINEID_TRAILERSZ))//~va79I~
  #else                                                            //~va50I~
    if (!UTF_umemmem(swutf8file,pdata,pdbcs,TCHDR_LINEID_TRAILER,0/*keydbcs*/,len,TCHDR_LINEID_TRAILERSZ))//~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (!umemmem(pdata,TCHDR_LINEID_TRAILER,(UINT)len,TCHDR_LINEID_TRAILERSZ))//~v62wR~
#endif                                                             //~va20I~
    	return 0;                                                  //~v62wI~
    return 1;	//header line                                      //~v62wI~
}//tc_ishdrline                                                    //~v62wI~
//**************************************************************** //~v40RI~
// chk fldno in hdrline                                            //~v40RI~//~va20R~
//*ret :rc                                                         //~v40RI~
//**************************************************************** //~v40RI~
int *tc_chkhdr(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH* Pplabplh)     //~v40RR~
{                                                                  //~v40RI~
    PULINEH plh;                                                   //~v40RI~
    int rc=0,fldno,ofldno=0,len,start;                             //~v62zR~
    char  *pdata,*pdata0,*pce;                                     //~v40RR~
static int Sfldtb[MAXFIELD+2];		//top is max fld last id end of fld//~v40RI~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va50R~
    char *pdbcs;                                                   //~va50I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,ebclen,opt,rc2;                                  //~va50R~
    int handle;                                                    //~va79I~
    UCHAR *pebc;                                                    //~va50M~//~va5pR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************                         //~v40RI~
	plh=*Pplabplh;			//label plh                            //~v40RI~
    if (plh)                                                       //~v40RI~
    	plh=UGETQPREV(plh);		//prev of label plh                //~v40RI~
    else                                                           //~v40RI~
    {                                                              //~v40RI~
    	plh=UGETQTOP(&Ppfh->UFHlineque);                           //~v40RR~
    	plh=UGETQNEXT(plh);                                        //~v40RI~
    }                                                              //~v40RI~
    if (!plh)                                                      //~v40RI~
    	return 0;                                                  //~v40RI~
    if (!(len=plh->ULHlen))                                        //~v40RI~
    	return 0;                                                  //~v40RI~
    pdata=pdata0=plh->ULHdata;                                     //~v40RI~
#ifdef UTF8UCS2                                                    //~va20I~
    pdbcs=plh->ULHdbcs;                                            //~va20R~
	swutf8file=PLHUTF8MODE(plh);                                   //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(plh);                                      //~va50I~
    handle=UGETPFH(plh)->UFHhandle;                                //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  if (UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,*pdata,*pdbcs,TCHDR_LINEID))//~va50I~//~va79R~
    if (UCVEBCUTF_neascii_b2a(swebcfile,swutf8file,handle,*pdata,*pdbcs,TCHDR_LINEID))//~va79I~
  #else                                                            //~va50I~
    if (UTF_ne(swutf8file,*pdata,*pdbcs,TCHDR_LINEID))             //~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (*pdata!=TCHDR_LINEID)                                      //~v40RR~
#endif                                                             //~va20I~
    	return 0;                                                  //~v40RI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  if (!(pce=XESUB_EBCUTF8_umemmem_bandl(swutf8file,swebcfile,pdata,pdbcs,TCHDR_LINEID_TRAILER,len,TCHDR_LINEID_TRAILERSZ)))//~va50R~//~va79R~
    if (!(pce=XESUB_EBCUTF8_umemmem_bandl(swutf8file,swebcfile,handle,pdata,pdbcs,TCHDR_LINEID_TRAILER,len,TCHDR_LINEID_TRAILERSZ)))//~va79I~
  #else                                                            //~va50I~
    if (!(pce=UTF_umemmem(swutf8file,pdata,pdbcs,TCHDR_LINEID_TRAILER,0/*keydbcs*/,len,TCHDR_LINEID_TRAILERSZ)))//~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (!(pce=umemmem(pdata,TCHDR_LINEID_TRAILER,(UINT)len,TCHDR_LINEID_TRAILERSZ)))//~v40RR~
#endif                                                             //~va20I~
    	return 0;                                                  //~v40RI~
#ifdef UTF8UCS2                                                    //~va20I~
  if (swutf8file                                                   //~va20R~
//&&  !utfddisasciistr(0,pdata,pdbcs,(ULONG)pce-(ULONG)pdata))     //~va20R~//~vafkR~
//&&  !utfddisasciistr(0,pdata,pdbcs,(ULPTR)pce-(ULPTR)pdata))     //~vaz8R~
  &&  !utfddisasciistr(0,pdata,pdbcs,(int)((ULPTR)pce-(ULPTR)pdata)))//~vaz8I~
    rc=4;                                                          //~va20I~
  else                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (swebcfile                                                    //~va50I~
//&&  (ebclen=(ULONG)pce-(ULONG)pdata,                             //~va50I~//~vafkR~
//&&  (ebclen=(ULPTR)pce-(ULPTR)pdata,                             //~vaz8R~
  &&  (ebclen=(int)((ULPTR)pce-(ULPTR)pdata),                      //~vaz8I~
       !ucvebc_issbcsstr(0,pdbcs,ebclen))                          //~va50I~
  )                                                                //~va50I~
    rc=4;                                                          //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20I~
  {                                                                //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	if (swebcfile)                                                 //~va50I~
    {                                                              //~va50I~
    	opt=XEEBCO_BIN;                                            //~va50I~
//  	rc2=xeebc_b2msetdbcs(opt,pdata,pdbcs,ebclen,&pebc,0/*outdbcs*/,&ebclen);//~va50I~//~va79R~
    	rc2=xeebc_b2msetdbcs(opt,handle,pdata,pdbcs,ebclen,&pebc,0/*outdbcs*/,&ebclen);//~va79I~
//      if (rc==UALLOC_FAILED)                                     //~va50R~//~vaa7R~
        if (rc2==UALLOC_FAILED)                                    //~vaa7I~
//	        return (int*)-1;                                       //~va50I~//~vafkR~
	        return (int*)(ULPTR)-1;                                //~vafkI~
        pdata=pebc;                                                //~va50I~
        pce=pdata+ebclen;                                          //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    memset(Sfldtb,0,sizeof(Sfldtb));                               //~v40RR~
    for (fldno=0,ofldno=-1,start=0,pdata++;pdata<pce;pdata++)      //~v40RR~
    {                                                              //~v40RI~
    	fldno=*pdata;                                              //~v40RI~
        if (fldno==TCHDR_FLDSEPID)                                 //~v40RM~
        {                                                          //~v40RM~
        	if (!start)                                            //~v40RM~
//            	start=(int)((ULONG)pdata-(ULONG)pdata0);           //~v62zR~//~vafkR~
            	start=(int)((ULPTR)pdata-(ULPTR)pdata0);           //~vafkI~
            continue;                                              //~v40RM~
        }                                                          //~v40RM~
        else                                                       //~v40RM~
        if (fldno==TCHDR_FLDCONTID)                                //~v40RM~
            continue;                                              //~v40RM~
//      if (fldno==TCHDR_FLDSEPCONTID)                             //~v62zR~
//          continue;                                              //~v62zR~
//      else                                                       //~v62zR~
    	if (fldno>='1' && fldno<='9')                              //~v40RR~
        {                                                          //~v62zI~
        	fldno=fldno-'0';                                       //~v40RI~
            if (pdata+1<pce && *(pdata+1)>='0' && *(pdata+1)<='9') //~v62zI~
            {                                                      //~v62zI~
            	pdata++;                                           //~v62zI~
            	fldno=fldno*10+*pdata-'0';                         //~v62zR~
            }                                                      //~v62zI~
        }                                                          //~v62zI~
        else                                                       //~v62zI~
//!after b2a                                                       //~va50I~
    	if (fldno==' '                                             //~v62zR~
        &&  ((pdata+1<pce && *(pdata+1)==TCHDR_FLDSEPID) || pdata+1==pce))//~v62zI~
        	fldno=ofldno+1;                                        //~v62zI~
//      else                                                       //~v62zR~
//  	if (fldno>='A' && fldno<='Z')                              //~v62zR~
//      	fldno=fldno-'A'+10;                                    //~v62zR~
//      else                                                       //~v62zR~
//  	if (fldno>='a' && fldno<='z')                              //~v62zR~
//      	fldno=fldno-'a'+36;                                    //~v62zR~
        else                                                       //~v40RI~
        {                                                          //~v40RI~
        	rc=4;                                                  //~v40RI~
            break;                                                 //~v40RI~
        }                                                          //~v40RI~
        if (fldno<=ofldno)                                         //~v40RI~
        {                                                          //~v40RI~
        	rc=4;                                                  //~v40RI~
            break;                                                 //~v40RI~
        }                                                          //~v40RI~
        Sfldtb[fldno]=start;                                       //~v40RI~
        start=0;                                                   //~v40RI~
        ofldno=fldno;                                              //~v40RI~
    }//data loop                                                   //~v40RI~
  }//ascii                                                         //~va20I~
    if (rc)                                                        //~v40RI~
    {                                                              //~v40RI~
    	uerrmsg("TC header line(lineno=%ld) format err",           //~v40RI~
        		"TC フィールド定義行(%ld 行目)の形式エラー",       //~v40RI~
                	plh->ULHlinenor);                              //~v40RI~
//      return (int*)-1;                                           //~v40RR~//~vafkR~
        return (int*)(ULPTR)-1;                                    //~vafkI~
    }                                                              //~v40RI~
//  Sfldtb[ofldno+1]=(int)((ULONG)pce-(ULONG)pdata0);                     //~v40RR~//~vafkR~
    Sfldtb[ofldno+1]=(int)((ULPTR)pce-(ULPTR)pdata0);              //~vafkI~
    Sfldtb[0]=ofldno;                                              //~v40RR~
    return Sfldtb;                                                 //~v40RI~
}//tc_chkhdr                                                       //~v62zR~
//****************************************************************
// hel for fmt
//*ret :0
//****************************************************************
int tc_helpfmt(void)
{
//  uerrmsg("TC fmt [[fieldno[-fieldno]]{R|L}[F] ...] [NX] [Sn] [H] [C] [.lab1 .lab2]",0);//~v51oR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]]{R|L}[F] ...] [NX] [Sn] [H] [C[x]] [NUMONLY] [.lab1 .lab2]",0);//~v51tR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]]{R|L}[F] ...] [NX] [Sn] [H] [C[x]] [NUM | NUMCOMP] [.lab1 .lab2]",0);//~v51xR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][R|L][F][N|C] ...] [NX] [Sn] [H] [C[x]] [.lab1 .lab2]",0);//~v51FR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][R|L][F][N|C] ...] [NX] [Sn] [H] [D['x']] [.lab1 .lab2]",0);//~v580R~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][R|L][F][N|C] ...] [NX] [Sn] [H] [D['x']] Q[d][s] [.lab1 .lab2]",0);//~v59PR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][R|L|P][N|C] ...] [NX] [Sn] [H] [D['x']] Q[d][s] [.lab1 .lab2]",0);//~v62gR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][o][R|L|P][N|C] ...] [NX] [Sn] [H] [D['x']] Q[d][s] [.lab1 .lab2]",0);//~v62KR~
//  uerrmsg("TC fmt [[fieldno[-fieldno]][o][R|L|P][N|C] ...] [NX] [S[R][outdelmstr]] [H] [D[inpdelms]] Q[d][s] [.lab1 .lab2]",0);//~v62UR~
    uerrmsg("TC fmt [[fieldno[-fieldno]][O][R|L|P][N|A][C] ...] [NX] [S[R][outdelmstr]] [H] [D[inpdelms]] Q[d][s] [.lab1 .lab2]",0);//~v62UI~
    return 0;
}//tc_helpfmt
//*******************************************************          //~vbmrI~
//*replace hex notation                                            //~vbmrI~
//*rc=4 fmt err or contains null                                   //~vbmrI~
//*******************************************************          //~vbmrI~
int chkhexdelm(void)                                               //~vbmrI~
{                                                                  //~vbmrI~
	char wk1[sizeof(Sdelmstr)];                                    //~vbmrI~
	char wk2[sizeof(Soutdelmstr)];                                 //~vbmrI~
    int len1,len2,opt,rc1,rc2,rc;                                  //~vbmrI~
//***************************************                          //~vbmrI~
	opt=UEERO_NULLERR|UEERO_MSG;	//err if x00                   //~vbmrR~
    Sswtabdelm=0;                                                  //~vbmsI~
	rc1=ueditescrep(opt,Sdelmstr,(int)strlen(Sdelmstr),wk1,sizeof(wk1),&len1);//~vbmrR~
    if (rc1==1)                                                    //~vbmrI~
    {                                                              //~vbmsI~
    	UmemcpyZ(Sdelmstr,wk1,(size_t)len1);                       //~vbmrR~
        Sswtabdelm=memchr(Sdelmstr,TABCHAR,(size_t)len1)!=0;          //~vbmsI~//~vbmtR~
    }                                                              //~vbmsI~
	rc2=ueditescrep(opt,Soutdelmstr,(int)strlen(Soutdelmstr),wk2,sizeof(wk2),&len2);//~vbmrR~
    if (rc2==1)                                                    //~vbmrI~
    {                                                              //~vbmtI~
//  	UmemcpyZ(Sdelmstr,wk2,(size_t)len2);                       //~vbmrR~//~vbmsR~
       	if (memchr(wk2,TABCHAR,(size_t)len2))                      //~vbmtI~
        {                                                          //~vbmtI~
            uerrmsg("error:\"%s\", TAB(\\t=0x09) is invalid for S option(output delm string)",0,//~vbmtR~
	            	Soutdelmstr);                                  //~vbmtR~
       		rc2=4;                                                 //~vbmtM~
        }                                                          //~vbmtI~
    	UmemcpyZ(Soutdelmstr,wk2,(size_t)len2);                    //~vbmsI~
    }                                                              //~vbmtI~
    rc=(rc1>1)+(rc2>1);                                            //~vbmrR~
    return rc;                                                     //~vbmrI~
}//chkhexdelm                                                      //~vbmrI~
//*******************************************************          //~vbn0I~
//*replace hex notation                                            //~vbn0I~
//*rc=4 fmt err or contains null                                   //~vbn0I~
//*rc=1 unicode specified                                          //~vbn0I~
//*******************************************************          //~vbn0I~
int chkhexdelmU2DDsub(int Popt,char *Ppch,int Plen,int *Ppucs,int *Ppucsctr)//~vbn0I~
{                                                                  //~vbn0I~
	char *pc,*pc0,*pc2=0;                                          //~vbn0R~
	char wkc[sizeof(Sdelmstr)];                                    //~vbn0I~
	char wkc2[sizeof(Sdelmstr)];                                   //~vbn0I~
	int  wku[sizeof(Sdelmstr)],ucs;                                //~vbn0I~
    int ii,lenc,opt,rc1,ucsctr,reslen,outlen,numlen,hexlen,swerr=0,cvlen,rc=0;//~vbn0R~
//***************************************                          //~vbn0I~
	opt=UEERO_NULLERR|UEERO_MSG;	//err if x00                   //~vbn0I~
	for (pc0=pc=Ppch,ucsctr=0,reslen=Plen;reslen>0;)               //~vbn0I~
    {                                                              //~vbn0I~
		pc2=memchr(pc,'\\',(size_t)reslen);                        //+vbn0R~
        if (!pc2)                                                  //~vbn0I~
        	break;                                                 //~vbn0I~
        lenc=PTRDIFF(pc2,pc);                                      //~vbn0I~
        if (!(reslen-lenc>2 && toupper(*(pc2+1))=='U'))            //~vbn0I~
        {                                                          //~vbn0I~
        	pc=pc2+1;                                              //~vbn0I~
            reslen-=lenc+1;                                        //~vbn0I~
            continue;                                              //~vbn0I~
        }                                                          //~vbn0I~
		cvlen=PTRDIFF(pc2,pc0);                                    //~vbn0R~
        if (cvlen)                                                 //~vbn0I~
        {                                                          //~vbn0I~
			rc1=ueditescrep(opt,pc0,cvlen,wkc,sizeof(wkc),&outlen);//~vbn0R~
        	if (rc1>1)                                             //~vbn0R~
            	return 4;                                          //~vbn0R~
        	for (ii=0;ii<outlen;ii++)                              //~vbn0R~
            	wku[ucsctr++]=wkc[ii];                             //~vbn0R~
        }                                                          //~vbn0I~
        pc2+=2; 	//next of "U"                                  //~vbn0I~
        reslen-=lenc+2;                                            //~vbn0R~
        numlen=unumlen(pc2,UNUMLEN_HEX,reslen);                    //~vbn0I~
        if (numlen>7 ||numlen<2)                                   //~vbn0I~
        {                                                          //~vbn0I~
        	swerr=1;                                               //~vbn0I~
        	break;                                                 //~vbn0I~
        }                                                          //~vbn0I~
        if (numlen%2)                                              //~vbn0I~
        {                                                          //~vbn0I~
        	*wkc2='0';                                             //~vbn0I~
            memcpy(wkc2+1,pc2,(size_t)numlen);                     //~vbn0I~
			hexlen=ugethex(wkc2,wkc,numlen+1);                     //~vbn0I~
        }                                                          //~vbn0I~
        else                                                       //~vbn0I~
    		hexlen=ugethex(pc2,wkc,numlen);                        //~vbn0I~
        if (hexlen<0)                                              //~vbn0I~
        {                                                          //~vbn0I~
        	swerr=1;                                               //~vbn0I~
            break;                                                 //~vbn0I~
        }                                                          //~vbn0I~
        for (ii=0,ucs=0;ii<hexlen;ii++)                            //~vbn0I~
        	ucs=(ucs<<8)+wkc[ii];                                  //~vbn0I~
        wku[ucsctr++]=ucs;                                         //~vbn0R~
        pc0=pc=pc2+numlen;                                         //~vbn0I~
        reslen-=numlen;                                            //~vbn0I~
        rc=1;                                                      //~vbn0I~
    }                                                              //~vbn0I~
    if (swerr)                                             //~v6Y0I~//~vbn0I~
    {                                                      //~v6Y0I~//~vbn0I~
    	uerrmsg("Unicode notation error(%s)",          //~v6Y0I~   //~vbn0I~
                    "ユニコード指定エラー(%s)",            //~v6Y0I~//~vbn0I~
                    pc2);                                  //~v6Y0I~//~vbn0I~
        return 4;                                              //~v6Y0I~//~vbn0I~
    }                                                      //~v6Y0I~//~vbn0I~
    reslen=Plen-PTRDIFF(pc0,Ppch);                                 //~vbn0I~
    if (reslen>0)                                                  //~vbn0I~
    {                                                              //~vbn0I~
        rc1=ueditescrep(opt,pc0,reslen,wkc,sizeof(wkc),&outlen);   //~vbn0R~
        if (rc1>1)                                                 //~vbn0R~
            return 4;                                              //~vbn0I~
        for (ii=0;ii<outlen;ii++)                                  //~vbn0R~
            wku[ucsctr++]=wkc[ii];                                 //~vbn0I~
    }                                                              //~vbn0I~
    memcpy(Ppucs,wku,(size_t)ucsctr*sizeof(int));                  //+vbn0R~
    *Ppucsctr=ucsctr;                                              //~vbn0I~
    return rc;                                                     //~vbn0R~
}//chkhexdelmU2DDsub                                               //~vbn0I~
//*******************************************************          //~vbn0I~
int calc3_unicodeerr(char *Pparm)                                  //~vbn0I~
{                                                                  //~vbn0I~
    uerrmsg("%s contains invalid unicode specification(Only printable SBCS is available)",0,Pparm);//~vbn0R~
    return 4;                                                      //~vbn0I~
}                                                                  //~vbn0I~
int calc3_unicodeerr2(char *Pparm)                                 //~vbn0I~
{                                                                  //~vbn0I~
    uerrmsg("%s contains invalid unicode specification(specify dbcs by \\u___ format)",0,Pparm);//~vbn0R~
    return 4;                                                      //~vbn0I~
}                                                                  //~vbn0I~
//*******************************************************          //~vbn0I~
//*replace hex notation                                            //~vbn0I~
//*rc=4 fmt err or contains null                                   //~vbn0I~
//*******************************************************          //~vbn0I~
int chkhexdelmU2DD(void)                                           //~vbn0I~
{                                                                  //~vbn0I~
	int  wku1[sizeof(Sdelmstr)];                                   //~vbn0I~
	int  wku2[sizeof(Sdelmstr)];                                   //~vbn0I~
	char wkdddata[sizeof(Sdelmstr)];                               //~vbn0I~
	char wkdddbcs[sizeof(Sdelmstr)];                               //~vbn0I~
    int ucsctr1,ucsctr2,rc,ddctr;                                  //~vbn0R~
//***************************************                          //~vbn0I~
	rc=chkhexdelmU2DDsub(0,Sdelmstr,(int)strlen(Sdelmstr),wku1,&ucsctr1);//+vbn0R~
    if (rc>1)                                                      //~vbn0R~
    	return 4;                                                  //~vbn0I~
	rc=chkhexdelmU2DDsub(0,Soutdelmstr,(int)strlen(Soutdelmstr),wku2,&ucsctr2);//+vbn0R~
    if (rc>1)                                                      //~vbn0R~
    	return 4;                                                  //~vbn0I~
    if (UmemchrW4((UWUCS*)wku2,TABCHAR,(size_t)ucsctr2))           //~vbn0R~
    {                                                              //~vbn0I~
        uerrmsg("error:\"%s\", TAB(\\t=0x09) is invalid for S option(output delm string)",0,//~vbn0I~
	            Soutdelmstr);                                      //~vbn0I~
    	return 4;                                                  //~vbn0I~
    }                                                              //~vbn0I~
    rc=utfcvu2dd(0,wku1,ucsctr1,wkdddata,wkdddbcs,(int)sizeof(wkdddata),&ddctr);//~vbn0R~
    if (ddctr!=ucsctr1)	//dbcs or unprintable                      //~vbn0R~
		return calc3_unicodeerr(Sdelmstr);                         //~vbn0I~
    UmemcpyZ(Sdelmstr,wkdddata,(size_t)ddctr);                     //~vbn0R~
    UmemcpyZ(Sdelmstrdbcs,wkdddbcs,(size_t)ddctr);                 //~vbn0R~
    Sdelmstrlen=ddctr;                                             //~vbn0R~
    rc=utfcvu2dd(0,wku2,ucsctr2,wkdddata,wkdddbcs,(int)sizeof(wkdddata),&ddctr);//~vbn0R~
    if (rc>=UTFCVFDRC_UTF8UNP) //allow dbcs by \u fmt              //~vbn0R~
	  	return calc3_unicodeerr2(Soutdelmstr);                     //~vbn0R~
	rc=0;	//ignore unprintable,err,                              //~vbn0I~
    UmemcpyZ(Soutdelmstr,wkdddata,(size_t)ddctr);                  //~vbn0R~
    UmemcpyZ(Soutdelmstrdbcs,wkdddbcs,(size_t)ddctr);              //~vbn0R~
    Soutdelmstrlen=ddctr;                                          //~vbn0R~
    Sswtabdelm=UmemchrW4((UWUCS*)wku1,TABCHAR,(size_t)Sdelmstrlen)!=0;//~vbn0R~
    UTRACED("Sdelmstr",Sdelmstr,Sdelmstrlen);                      //~vbn0I~
    UTRACED("Sdelmstrdbcs",Sdelmstrdbcs,Sdelmstrlen);              //~vbn0I~
    UTRACED("Soutdelmstr",Soutdelmstr,Sdelmstrlen);                //~vbn0I~
    UTRACED("Soutdelmstrdbcs",Soutdelmstrdbcs,Sdelmstrlen);        //~vbn0I~
    UTRACEP("%s:Sswtabdelm=%d\n",UTT,Sswtabdelm);                  //~vbn0I~
    return rc;                                                     //~vbn0I~
}//chkhexdelmU2DD                                                  //~vbn0I~
//*************************************************************************//~vbmtI~
//*consider delmstring contains tab char (it is space on plhdata)  //~vbmtI~
//*************************************************************************//~vbmtI~
int xecalc3_tabchkDelmstr(char *Pdelmstr,char *Pdelmstrdbcs,int Plen,char *Pdelmstrout,char *Pdelmstrdbcsout,int *Ppoutlen)//~vbmtI~
{                                                                  //~vbmtI~
    int delmstrlen,swtabfound=0,ii,delmstrlendroptab=0;            //~vbmtR~
    char *pc,*pcd,*pco,*pcdo;                                      //~vbmtI~
//***************************************                          //~vbmtI~
	delmstrlen=(int)strlen(Pdelmstr);                              //~vbmtI~
    UTRACED("Pdelmster",Pdelmstr,delmstrlen);                      //~vbmtI~
    UTRACED("Pdelmsterdbcs",Pdelmstrdbcs,delmstrlen);              //~vbmtI~
	for (pc=Pdelmstr,pcd=Pdelmstrdbcs,ii=0,pco=Pdelmstrout,pcdo=Pdelmstrdbcsout;ii<delmstrlen;pc++,pcd++,ii++)//~vbmtI~
    {                                                              //~vbmtI~
    	swtabfound=0;                                              //~vbmtI~
    	if (*pc==TABCHAR)   //on delmstr                           //~vbmtI~
        {                                                          //~vbmtI~
        	if (*pcd==0)                                           //~vbmtR~
        		swtabfound=1; //delmstr contains tab               //~vbmtI~
        }                                                          //~vbmtI~
        if (!swtabfound)                //drop tab from delmstr    //~vbmtI~
        {                                                          //~vbmtI~
        	*pco++=*pc;                                            //~vbmtI~
        	*pcdo++=*pcd;                                          //~vbmtI~
            delmstrlendroptab++;                                   //~vbmtI~
        }                                                          //~vbmtI~
    }                                                              //~vbmtI~
    *Ppoutlen=delmstrlendroptab;                                   //~vbmtI~
    UTRACED("Pdelmsterout",Pdelmstrout,delmstrlendroptab);         //~vbmtI~
    UTRACED("Pdelmsterdbcsout",Pdelmstrdbcsout,delmstrlendroptab); //~vbmtI~
    return swtabfound;                                             //~vbmtI~
}//xecalc3_tabchkDelmstr                                           //~vbmtI~
//*************************************************************************//~vbmtR~
//*consider delmstring contains tab char (it is space on plhdata)  //~vbmtR~
//*************************************************************************//~vbmtI~
char *xecalc3_umempbrk_nonascii_TABCHK(int Popt,int Pswebcfile,int Pswutf8file,int Phandle,char *Pdata,char *Pdbcs,char *Pdelmstr,char *Pdelmstrdbcs,int Plen)//~vbmtR~
{
    int delmstrlen,pos,swtabfound=0;                               //~vbmtR~
    char *pc,*pcd,*pdata;                                          //~vbmtR~
//***************************************
	delmstrlen=(int)strlen(Pdelmstr);                              //~vbmtR~
    UTRACED("Pdelmster",Pdelmstr,delmstrlen);                      //~vbmtI~
    UTRACED("Pdelmsterdbcs",Pdelmstrdbcs,delmstrlen);              //~vbmtI~
    if (!(Popt & MPBRKTABCHKO_TABFOUND))                           //~vbmtR~
    {                                                              //~vbmtI~
		pdata=UCVEBCUTF_umempbrk_nonascii(Pswebcfile,Pswutf8file,Phandle,Pdata,Pdbcs,Pdelmstr,Pdelmstrdbcs,Plen);//~vbmtR~
    }                                                              //~vbmtI~
    else                                                           //~vbmtI~
    {                                                              //~vbmtI~
	    swtabfound=0;                                              //~vbmtI~
        pcd=memchr(Pdbcs,TABCHAR,(size_t)Plen);                            //~vbmtI~//~vbmuR~
        pos=Plen;                                                  //~vbmtI~
        if (pcd)   //tab found                                     //~vbmtI~
        {                                                          //~vbmtI~
            pos=PTRDIFF(pcd,Pdbcs);                                //~vbmtI~
            pc=Pdata+pos;                                          //~vbmtI~
            if (*pc==' ')                                          //~vbmtI~
                swtabfound=1; //delmstr contains tab               //~vbmtI~
        }                                                          //~vbmtI~
        if (swtabfound)                                            //~vbmtI~
        {                                                          //~vbmtI~
        	if (!delmstrlen) //no delm except tab                  //~vbmtI~
                pdata=Pdata+pos;                                   //~vbmtR~
            else                                                   //~vbmtI~
            {                                                      //~vbmtI~
            	pdata=UCVEBCUTF_umempbrk_nonascii(Pswebcfile,Pswutf8file,Phandle,Pdata,Pdbcs,Pdelmstr,Pdelmstrdbcs,pos-1);//~vbmtR~
            	if (!pdata)                                        //~vbmtR~
                	pdata=Pdata+pos;                               //~vbmtR~
            }                                                      //~vbmtI~
        }                                                          //~vbmtI~
        else                                                       //~vbmtI~
            pdata=UCVEBCUTF_umempbrk_nonascii(Pswebcfile,Pswutf8file,Phandle,Pdata,Pdbcs,Pdelmstr,Pdelmstrdbcs,Plen);//~vbmtR~
    }                                                              //~vbmtI~
    UTRACEP("%s:%p=x%02x,swtabfound=%d\n",UTT,pdata,pdata?*pdata:0,swtabfound);//~vbmtR~
    return pdata;                                                  //~vbmtR~
}//xecalc3_umempbrk_nonascii_TABCHK                                //~vbmtI~
//*************************************************************************//~vbn0I~
int xecalc3_delmstrchk(void)                                       //~vbn0I~
{                                                                  //~vbn0I~
	int ii;                                                        //~vbn0I~
//**********************************                               //~vbn0I~
	for (ii=0;ii<Sdelmstrlen;ii++)                                 //~vbn0I~
    	if (Sdelmstr[ii]>='0' && Sdelmstr[ii]<='9' && Sdelmstrdbcs[ii]==0)//~vbn0I~
        {                                                          //~vbn0I~
        	uerrmsg("Digit is invalid as field Delimiter",0);      //~vbn0R~
            return 4;                                              //~vbn0I~
        }                                                          //~vbn0I~
    return 0;                                                      //~vbn0I~
}                                                                  //~vbn0I~
