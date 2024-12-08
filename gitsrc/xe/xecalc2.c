//*CID://+vba6R~:                                   update#=  111; //~vb30R~//+vba6R~
//*************************************************************
//*xecalc2.c
//* table calc(TC cmd)                                             //~va50R~
//*************************************************************
//vba6:170716 (Bug)tc calc err when opdtype=x(requires word clear) //+vba6I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafg:120616 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafgI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7c:100817 (BUG)TC =const;set so/si was missing for DBCS        //~va7cI~
//va7a:100817 split xecalc2.c                                      //~va7aI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//va5N:100524 (BUG)TC a="const" stop margin overflow at linedatacopy//~va5NI~
//va5c:100507 (BUG) incorrect errmsg when string constant specified for not string operation//~va5cI~
//va5b:100507 (BUG) tc cmd copy const have to be translated to dd fmt for utf8 file//~va5bI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2d:091228 (BUG)missing clear Sconstvalue                       //~va2dI~
//va2b:091223 (BUG)TC ~; allow short field                         //~va2bI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v77i:080103*(BUG) more over v76C(a=b fail for "=" line(a="b" is ok by v76C)//~v77iI~
//v76D:070827*(BUG)TC a=b(copy) fail by missing operand column whe label specified//~v76DI~
//v76C:070827*(BUG)TC a=b(copy) faile for tha data start with "="  //~v76CI~
//v74P:070325 BNDS support for "=" lcmd                            //~v74PI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v62L:050416 (BUG)TC;when using fldno,last fieldno rejected       //~v62LI~
//v62F:050408 disply output file name when wildcard used           //~v62FI~
//v62E:050407 sort cmd:numeric sort support(minus consideration)   //~v62EI~
//v62C:050403 (BUG)tc cmd;for ":fldno" specification fieldno err errmsg issued for the fld just before non fmt field//~v62CI~
//v62A:050402 (BUG)tc fmt;field start by 2 space byt 1st may delm when delm is not space//~v62AI~
//            so calc fail when delm is not space                  //~v62AI~
//v62z:050402 tc fmt;mx fld 62-->99(2 digit hdr fldno)             //~v62zI~
//v62v:050402 (BUG)tc;VnnR is not effective for divide(no vnn parm to ucalc)//~v62vI~
//v62u:050330 tc;set 1(true) or 0(false) to resut of ==(compare).  //~v62uI~
//v62t:050330 tc;wildcard rename support for -ooutfile             //~v62tI~
//v62s:050330 tc;issue outfile open errmsg                         //~v62sI~
//v62p:050325 tc_getnumrange is moved to uedit.c for v62o          //~v62pI~
//v605:041221 tc cmd:compare numeric when data type is specified   //~v605I~
//            (string compare only when no data type specified)    //~v605I~
//v604:041221 tc cmd:copy numeric when data type is specified      //~v604I~
//            (string copy only when no data type specified)       //~v604I~
//v602:041219 tc cmd:reject const except string for ==(compare)    //~v602I~
//v601:041219 tc cmd:accept numeric const copy opd3=opd2           //~v601I~
//v59S:041201 (BUG)conv err when t:opd3=t:opd2 for time stamp data //~v59SI~
//v59k:041113 tc cmd;support constant string compare               //~v59kI~
//v59j:041113 (BUG)tc cmd;string constant specification change     //~v59jI~
//v59i:041113 (BUG)tc cmd;err when constant is time data type      //~v59iI~
//v590:041026 tc cmd:support opd3=opd1==opd2;set compare result    //~v590I~
//v58z:041009 tc cmd:sumline file output option                    //~v58zI~
//v58y:041009 tc cmd:sumline positioning ajust                     //~v58yI~
//v58w:041003 tc cmd:accept opd1:Time and opd2:seconds for "~"(count)//~v58wI~
//            opd1 type 'T' is required for time compare,else string compare//~v58wI~
//            for opd1 type 'T',opd2 may be no-type('T' or 'D' by input data)//~v58wI~
//v58v:040928 tc cmd:output precision and round option [Vn][R].    //~v58vI~
//v58a:040828 tc cmd:for != breakkey summary,accept short record with keypos is out of line.//~v58aR~
//v589:040828 (BUG)tc cmd:null is inserted in summ line for short line with not fully breakekey//~v589I~
//v587:040823 TC cmd;add COUNTEQ:option to countup when starttime==endtime//~v587I~
//v57Y:040822 TC;dwordup support for other than ft1                //~v57YI~
//v57X:040822 (BUG)underpoint is diplayed for result(ucalc support dword-up)//~v57XI~
//v57W:040813 (BUG)TC cmd;dword calc time parm                     //~v57WI~
//v57Q:040620 (BUG)TC cmd;sum key is overridden by summary data    //~v57QI~
//v57J:040613 dword underpoint support                             //~v57JI~
//v57H:040612 (BUG)tc cmd;no err set if one of two opd is valid for 2 opd type//~v57HI~
//v57C:040606 use dword multiply to avoid overflow when output datatype!=X//~v57CI~
//            (chk too large underpoint data)                      //~v57CI~
//v57A:040605 (BUG)tc average calc miss when skip count!=0         //~v57xI~
//            (tc_calc devide parm changed to dword(see v53C))     //~v57xI~
//v57x:040605 (BUG)TC cmd loop when sum with ! break key and after option//~v57xI~
//v56z:040416 TC cmd;support copy operation,ins/rep/lj option      //~v56zI~
//            t:opd3=t:opd2 [INS]                                  //~v56zI~
//            opd3=opd2 [INS] [RJUST]                              //~v56zR~
//v54L:040121 (BUG)fldno id(:) is always required by const support //~v54LI~
//v54K:040121 (BUG)constant data typen is ignore                   //~v54JI~
//v54J:040121 count only option for sum with key/count break       //~v54JI~
//v54D:040120 expand TC cmd key max length  32-->256               //~v54DI~
//v53M:031029 TC cmd;set space separator for summ line for tc fmt and excep input//~v53MI~
//v53J:031027 TC cmd;const operand support for 2nd operand         //~v53JI~
//v53E:031018 TC cmd;reset previous err line                       //~v53EI~
//v53D:031018 TC cmd;support not sorted key  fld+[/key[>|!|<][/grade]]//~v53DR~
//v53C:031018 (BUG)by ulib-v50C(ucalc support underpoint divide),divide should be 3-long data//~v53CI~
//            ->TC cmd grade calc miss                             //~v53CI~
//v535:030920 TC cmd;change "+-" --> "~"                           //~v535I~
//v534:030920 (BUG)TC cmd;fmt err for 3 opd type to use 2 cap opd  //~v534I~
//v533:030917 TC +-;count record count in the time range           //~v533I~
//v52k:030903 tc cmd;help msg for compare                          //~v52kI~
//v52h:030831 DOSlink err                                          //~v52kR~
//v52g:030830 subttal set even if valid recno=0(not err msg "no valid record")//~v52gI~
//v52f:030830 (BUG)tc cmd:total line corrupted                     //~v52fI~
//v529:030823 tc:err when conv type=Y(allow specification UZ also) //~v529I~
//v51n:030530 long decimal/dword hex support for TC cmd            //~v51nI~
//v51m:030530 conversion support for TC cmd(O,X,T,D,Z,U,Y=UZ,L)    //~v529R~
//v51j:030530 expand max data len 16-->17 for tc cmd               //~v51jI~
//v51i:030530 (BUG)rejected "opd1="(set block as 1st opd)          //~v51iI~
//v50E:030126 (DOS)no TC cmd support for memory                    //~v50EI~
//v506:021019 add "set" option for renum cmd;set num fld on specified colomn//~v506I~
//v497:020617 TC cmd new operation "=="(sting compare)             //~v497I~
//v47K:020330 allow comma for decimal(no z specified)              //~v47KI~
//v47J:020330 (BUG of V474)ii not initialized                      //~v47JI~
//v476:020203 (BUG)TC cmd;invalid get line x-data when space preceding//~v476I~
//v475:020203 (BUG)linedata type chk missing for X/O               //~v475I~
//v474:020203 allow output Z fmt of output of TC cmd               //~v474I~
//v473:020203 0 padding option of TC cmd:Zero                      //~v473I~
//v435:011017 ignore tchdr for calc                                //~v435I~
//v434:011017 chng help of tc cmd                                  //~v434I~
//v42o:011006 help for TC cmd field spec                           //~v42oI~
//v41d:010804 (BUG)no errmsg when no label on linecmd              //~v41dI~
//v40R:010720 TC fld# parm support( [type]:[_]fldno[f] or [type]fldno[f]//~v40RI~
//v40q:010609 (BUG)tab char appear on tc cmd result set fld(need clear dbcs addr)//~v40qI~
//v17i:000513 move BC cmd to ulib for utility XBC                  //~v17iI~
//v17h:000513 TC cmd:2 line range support.                         //~v17hI~
//v17f:000501 change TCN to TC and NX option.                      //~v17fI~
//v170:000422 (BUG)double sum top remain previous sum line as err  //~v170I~
//v168:000418 add table format function to TC/TCN cmd              //~v168I~
//            TC[N] fmt [[fldno]{R|L}]                             //~v168I~
//v155:000318 numeric calc func(NEW)
//  TC[N] expression [options]
//        expression:[{oprand1|operand3]opcode[oprand2][{/breakkey|//count}]
//        operand   :[type]column1-column2
//        opcode:+ :display summary,data count,average,min,max,err field count
//                  sub-summary is set to the field starting with '=' if edit mode
//               +/:insert sub summary by key or count
//                  +/c1-c2[/[type]grade] by key break of col1-col2;
//                         diff is gradiation of num key value
//               +//:+//n  sub summary by each n fields.
//               = :save first opd box info
//               /x:data type conversion                           //~v51mI~
//                  (Double Alt+F7 after block close is alternative)
//               ++:replace opd fields by summary of up to the field
//               --:replace opd fields by differrence from previous field
//               +=:replace opd1 fields by opd1+opd2 value
//               -=:replace opd1 fields by opd1-opd2 value
//               *=:replace opd1 fields by opd1*opd2 value
//               /=:replace opd1 fields by opd1/opd2 value
//               %=:replace opd1 fields by opd1%opd2 value
//               (for decimal devide,precision 1 1 up)
//        breakkey  :[type]column1-column2[/grade]
//        type     :
//               X :field value is Hex digit
//               O :field value is Oct digit
//               D :field value is decimal digit
//               T :field value is Timestamp(hh:mm:ss.xxx or hhmmss.xxx fmt)
//               if missing,'T' for time format else 'D'.
//        grade    :breake when key value reached to multiple of grade value.
//        count     :summary break on each n lines.
//        option    :aft|bef|top|end|las   summary line insert position
//                  :ave|minmax|maxmin|amm|mmx   display summary and others
//                  :ign                   ignore intermediate summline id("=")
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
#include <ucalc.h>                                                 //~v17iI~
#include <ucalc2.h>                                                //~v51mI~
#ifdef UTF8UCS2                                                    //~va20R~
#include <utf22.h>                                                 //~va20R~
#include <utrace.h>                                                //~va20R~
#endif                                                             //~va20R~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
//#include "xefile6.h"                                             //~va7aR~
//#include "xefunc.h"                                              //~va7aR~
//#include "xeundo.h"                                              //~va7aR~
#include "xecap.h"
//#include "xecalc.h"                                              //~va7aR~
#include "xecalc2.h"
#include "xecalc21.h"                                              //~va7aI~
#include "xecalc3.h"                                               //~v168I~
#include "xeerr.h"
//#include "xechar2.h"                                             //~va7aR~
#include "xelcmd.h"
//#include "xelcmd2.h"                                             //~va7aR~
#include "xelcmd4.h"
//#include "xelcmd5.h"                                               //~v497I~//~va7aR~
//#include "xefcmd.h"                                                //~v62tI~//~va7aR~
#include "xefcmd22.h"		//fcmdlabelerr
#include "xefcmd3.h"		//fcmdgetlabelrange
//#include "xedir.h"      //fcmdgetlabelrange                        //~v58zI~//~va7aR~
//#include "xedcmd.h"                                                //~v58zI~//~va7aR~
//#include "xesub.h"                                               //~va7aR~
#include "xesub2.h"                                                //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
//#include "xesub2.h"                                                //~va20R~//~va7aR~
#include "xeutf2.h"                                                //~va20R~
#endif                                                             //~va20R~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//static int    Spadd0sw=0;                                          //~v473I~//~va7aR~
//static long   Sconstvalue[3];   //constant value                 //~v57JR~
//static long   Sconstvalue[4];   //constant value                   //~v57JI~//~vafkR~
static SLPTR    Sconstvalue[4];   //constant value                 //~vafkI~
static int    Sconstdatatype;   //constant value                   //~v54JI~
static char  *Sconstaddr=0;       //constant addr for ft2count     //~v53JR~
static int    Sconstlen=0;        //constant len  for ft2count     //~v53JR~
//static int    Sft2insmode=0;                                       //~v56zI~//~va7aR~
static int    S1sterr=0;			//err line reset ctl           //~v57HI~
//static int   *Sparm;                                               //~v62vI~//~va70R~
static XECALCPARM *Sparm;                                          //~va70I~
//*******************************************************
////****************************************************************//~v17fR~
//// calclator for all line                                        //~v17fR~
////*rc   :                                                        //~v17fR~
////****************************************************************//~v17fR~
//int func_tc(PUCLIENTWE Ppcw)                                     //~v17fR~
//{                                                                //~v17fR~
////*********************************                              //~v17fR~
//    return tc_main(Ppcw);                                        //~v17fR~
//}//func_tc                                                       //~v17fR~
////****************************************************************//~v17fR~
//// calclator for displayed line only                             //~v17fR~
////*rc   :                                                        //~v17fR~
////****************************************************************//~v17fR~
//int func_tcnx(PUCLIENTWE Ppcw)                                   //~v17fR~
//{                                                                //~v17fR~
//    int rc;                                                      //~v17fR~
////*********************************                              //~v17fR~
//    Snxsw=1;                                                     //~v17fR~
//    rc=tc_main(Ppcw);                                            //~v17fR~
//    Snxsw=0;                                                     //~v17fR~
//    return rc;                                                   //~v17fR~
//}//func_tcnx                                                     //~v17fR~
//****************************************************************
// double click ALT+F7;execute "TC ="
//*rc   :
//****************************************************************
int tc_blocksave(PUCLIENTWE Ppcw)
{
	int rc;
//*********************************
    rc=cap_savecalcinfo(Ppcw,0,0,0,0);
    return rc;
}//func_tcnx
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
//int tc_main(PUCLIENTWE Ppcw)                                     //~v17fR~
int func_tc(PUCLIENTWE Ppcw)                                       //~v17fI~
{
#ifdef DOSDOS                                                      //~v50EI~
    return errnotsupported("TC","DOS version");                    //~v50ER~
#else                                                              //~v50EI~
	PUFILEC pfc;
    int rc,functype;
//  int parmtb[PARM_TBLSZ];                                        //~va70R~
    XECALCPARM parmtb[PARM_TBLSZ];                                 //~va70I~
    PULINEH labplht[MAXLABEL];                                     //~v17hR~
    UCHAR *ppout,wkpot[MAXCOLUMN+1];                               //~v59kR~
    PUPODELMTBL pupod;                                             //~v59jI~
//*********************************
	if (!Ppcw->UCWparm)		//operand
    	return tc_help0();                                         //~v168I~
    if (!strcmp(Ppcw->UCWopdpot,"?"))                              //~v168I~
        return tc_help(Ppcw);                                      //~v168I~
                                                                   //~v168I~
    if (!stricmp(Ppcw->UCWopdpot,CMDID_FMT))                       //~v168R~
        return tc_format(Ppcw);                                    //~v17fR~
    Ppcw->UCWopdpot=ppout=wkpot;	//parseout area ptr            //~v59jI~
    pupod=Ppcw->UCWopddelmt;	//delm tbl addr                    //~v59jI~
    if ((rc=uparse2(Ppcw->UCWparm,&pupod,&ppout,&(Ppcw->UCWopdno), //~v59jR~
    		UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2|UPARSEQUOTEDELM,","))>=4)//parse ="xxx"//~v59jI~
    	return rc;			//umalloc failed                       //~v59jI~
	memset(labplht,0,sizeof(labplht));		//id of no label;      //~v17hR~
	if ((rc=tc_opdchk(Ppcw,&functype,parmtb,labplht)),rc)
    	return rc;                      //err
    Sparm=parmtb;		//parm to tc_calc                          //~v62vR~
	S1sterr=0;			//err line reset ctl                       //~v57HI~
    pfc=Ppcw->UCWpfc;
    if (functype & CALC_FT1)
    {
        if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))
        {                                                          //~v533I~
            if (functype==CALC_SUM)
            {
                if (parmtb[PARM_BREAKTYPE])      //ctl break specified
                {
                    uerrmsg("Summary-key is not avail on browse mode",
                            "\x95\\示モードでサマリーキー指定できません");
                    return 4;
                }
                if (parmtb[PARM_OPTION] & PARM_SUMISRT_MASK)      //ctl break specified
                {
                    uerrmsg("Browse mode dose no allow Summary line insert",
                            "\x95\\示モードでサマリーキー挿入位置指定できません");
                    return 4;
                }
            }
            else
				return errbrowsemode();
        }                                                          //~v533I~
		rc=tc_ft1(Ppcw,functype,parmtb,labplht);
    }
    else
    {                                                              //~v533I~
      if (functype==CALC_COUNT)                                    //~v533R~
		rc=tc_ft2count(Ppcw,functype,parmtb,labplht);              //~v533I~
      else                                                         //~v533I~
		rc=tc_ft2(Ppcw,functype,parmtb,labplht);
    }                                                              //~v533I~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);	//redraw
    if (rc==1)
    {
    	rc=0;
        ubell();
    }
    return rc;
#endif                                                             //~v50EI~
}//tc_main
#ifndef DOSDOS                                                     //~v50EI~
//**************************************************************** //~v168I~
// calc opd chk                                                    //~v168I~
//*rc   :0                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_help(PUCLIENTWE Ppcw)                                       //~v168I~
{                                                                  //~v168I~
    int  opdno;                                                    //~v168I~
	char *pc;                                                      //~v168I~
//*********************************                                //~v168I~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v168I~
    pc=Ppcw->UCWopdpot;                                            //~v168I~
    pc+=strlen(pc)+1;		//skip 1st opd(fmt)                    //~v168I~
    opdno--;                                                       //~v168I~
    if (!opdno)                                                    //~v168I~
    	return tc_help0();                                         //~v168R~
    if (!stricmp(pc,CMDID_FMT))                                    //~v168I~
    	return tc_helpfmt();                                       //~v168I~
    if (!stricmp(pc,"SUM"))                                        //~v168R~
    	return tc_helpsum();                                       //~v168I~
    if (*pc=='1' && !*(pc+1))                                      //~v168I~
    	return tc_help1();                                         //~v168I~
    if (*pc=='2' && !*(pc+1))                                      //~v168I~
    	return tc_help2();                                         //~v168I~
    if (*pc=='3' && !*(pc+1))                                      //~v168I~
    	return tc_help3();                                         //~v168I~
    if (!stricmp(pc,CMDID_OPD))                                    //~v42oI~
    	return tc_helpf();                                         //~v42oI~
    return tc_help0();                                             //~v168R~
}//tc_help                                                         //~v168I~
//****************************************************************
// calc opd chk
//*rc   :0
//****************************************************************
//int tc_opdchk(PUCLIENTWE Ppcw,int *Pfunctype,int *Pparm,PULINEH *Pplabplh)//~va70R~
int tc_opdchk(PUCLIENTWE Ppcw,int *Pfunctype,XECALCPARM *Pparm,PULINEH *Pplabplh)//~va70I~
{
	PUFILEH pfh;
    UPODELMTBL *podt;                                              //~v56zI~
    char *popd,*pc,*pc2,*pckey=NULL;                                    //~v40RR~//~vafcR~
    char *pco;                                                     //~v56zI~
    char *strconst=0;                                              //~v56zI~
    char *strconstparm;                                            //~v59kI~
    int opt;                                                       //~v56zI~
    int  opdno,ii,ch,opcdlen,labtctr=0,rc;
	int  functype,cdatatype,gdatatype;
    int  pos1,pos2;                                                //~v40RR~
    int breakeqsw;                                                 //~v53DI~
//  long wkl[3];                                                   //~v57JR~
//  long wkl[4];                                                   //~v57JI~//~vafkR~
    SLPTR wkl[4];                                                  //~vafkI~
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1],*plabt;//label opd from/to
//static char *Sopcode="+-*/%=";                                   //~v535R~
static char *Sopcode="+-*/%=~";                                    //~v535I~
//*********************************
    Sconstdatatype=0; 			//returned by getplhvalue          //~va2dI~
	memset(Sconstvalue,0,sizeof(Sconstvalue));                     //~va2dI~
//	Spadd0sw=0;                                                    //~v473I~//~va7aR~
    pfh=UGETPFHFROMPCW(Ppcw);
//  memset(Pparm,0,sizeof(int)*PARM_TBLSZ);                        //~va70R~
    memset(Pparm,0,sizeof(XECALCPARM)*PARM_TBLSZ);                 //~va70R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  Pparm[PARM_EBC_HANDLE]=pfh->UFHhandle;                         //~va79I~//~vb30R~
    Pparm[PARM_EBC_HANDLE]=(XECALCPARM)pfh->UFHhandle;             //~vb30R~
    if (PFH_ISEBC(pfh))                                            //~va50R~
    {                                                              //~va79I~
    	Pparm[PARM_OPTION]|=PARM_EBCFILE;	//implicit parm        //~va50I~
    }                                                              //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va5bI~
    if (FILEUTF8MODE(pfh))                                         //~va5bI~
    	Pparm[PARM_OPTION]|=PARM_UTF8FILE;	//implicit parm        //~va5bI~
#endif                                                             //~va5bI~
    opdno=Ppcw->UCWopdno;           //funccmd created already
    popd=Ppcw->UCWopdpot;
    podt=Ppcw->UCWopddelmt;	//1st opd delm tbl,assume it is search word//~v56zI~
    plabt=&labt[0][0];
    for (ii=0,pc=popd;ii<opdno;ii++)
    {
        if (ii) //after 2nd opd
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
        	if (ii==1 && podt->upoquate)  // string const?         //~v56zR~
            	strconst=pc;                                       //~v56zI~
            else                                                   //~v56zI~
            if (tc_opdchk2(pc,Pparm))
    			return errinvalid(pc);
        }
        pc+=strlen(pc)+1;
        podt++;                                                    //~v56zI~
    }
//  Spadd0sw=Pparm[PARM_OPTION]&PARM_PADD0;	//0 padding option     //~v473I~//~va7aR~
//parm1 process
//*opd1
    pc=popd;
    ch=*pc;
    if (!strchr(Sopcode,ch))	//1st byte is not opcode
    {
//  	if (tc_getopd(pc,Pparm+PARM_DATATYPE1,&pc))                //~v53JR~
      if (!memcmp(pc,CALC_COUNTONLY,3))  //"1+/"  	//1st opd to count line by break key//~v54JI~
      {                                                            //~v54JI~
      	Pparm[PARM_DATATYPE1]='D';		//decimal                  //~v54JI~
      	Pparm[PARM_OPD1POS1]=1;			//value 1                  //~v54JR~
//    	Pparm[PARM_OPD1POS2]=TC_CONSTSPECID;//id of constant value //~v54JR~//~vafgR~
      	Pparm[PARM_OPD1POS2]=(ULONG)TC_CONSTSPECID;//id of constant value//~vafgI~
        Sconstvalue[0]=1;				//value                    //~v54JI~
        Sconstvalue[1]=0;				//not dword                //~v54JI~
        Sconstvalue[2]=0;				//nor underpoint           //~v54JI~
        Sconstdatatype='D'; 			//returned by getplhvalue  //~v54JR~
      	pc++;	//step to operation +                              //~v54JI~
      }                                                            //~v54JI~
      else                                                         //~v54JI~
//  	if (tc_getopd(0,pc,Pparm+PARM_DATATYPE1,&pc))//0:constant not allowed//~v59kR~
    	if (tc_getopd(0,pc,0,Pparm+PARM_DATATYPE1,&pc))//0:constant not allowed//~v59kI~
        	return 4;
    }
//*opcode
	functype=0;		//err id
    opcdlen=(int)strspn(pc,Sopcode);	//len of cocode
    if (opcdlen>=2)                                                //~v534R~
    {                                                              //~v534I~
        if (*pc=='=' && *(pc+1)!='=')                              //~v534I~
        	opcdlen=1;   //3 opd calc and 1/2 may be by cap        //~v534I~
    }                                                              //~v534I~
    switch(opcdlen)
    {
    case 0:
        uerrmsg("Operation code required",                         //~v40RI~
                "演算子がありません。");                           //~v40RI~
		return 4;                                                  //~v40RR~
    case 1:
        switch(*pc)
        {
        case '=':
        	pc++;
        	if (!*pc)
            {
              if (!(pc+1==strconst))	//strconst not followed    //~v59kR~
              {                                                    //~v59jI~
            	functype=CALC_TARGET;
                pc--;                                              //~v51iI~
                break;
              }                                                    //~v59jI~
			}
//opd3=opd1 op opd2 fmt chk
            if (!Pparm[PARM_OPD1POS2]) 	//opd1 is target
            	return errinvalid(pc);
//          memcpy(Pparm+PARM_DATATYPE3,Pparm+PARM_DATATYPE1,3*sizeof(int));//~va70R~
            memcpy(Pparm+PARM_DATATYPE3,Pparm+PARM_DATATYPE1,3*sizeof(XECALCPARM));//~va70I~
//          memset(Pparm+PARM_DATATYPE1,0,3*sizeof(int));          //~va70R~
            memset(Pparm+PARM_DATATYPE1,0,3*sizeof(XECALCPARM));   //~va70I~
//        if (!strchr(Sopcode,(int)(*pc)))	//1st byte is not opcode//~v59kR~
          if (!*pc||!strchr(Sopcode,(int)(*pc)))	//=" or 1st byte is not opcode//~v59kR~
          {                                                        //~v534I~
//  		if (tc_getopd(pc,Pparm+PARM_DATATYPE1,&pc)) //after  opd3=//~v53JR~
//  		if (tc_getopd(0,pc,Pparm+PARM_DATATYPE1,&pc)) //after  opd3=,0:constant is err//~v56zR~
            pco=pc;                                                //~v56zI~
//  		if (tc_getopd(2,pc,Pparm+PARM_DATATYPE1,&pc)) //after  opd3=,1:constant is ok//~v59kR~
    		if (tc_getopd(2,pc,strconst,Pparm+PARM_DATATYPE1,&pc)) //after  opd3=,1:constant is ok//~v59kI~
        		return 4;
            if (*pc)    //opd2 exist                               //~v56zR~
            {                                                      //~v56zI~
            	if (*(Pparm+PARM_OPD1POS2)==TC_CONSTSPECID)	//constant//~v56zI~
                	return errinvalid(pco);	//opd1 should not be constant//~v56zI~
            }                                                      //~v56zI~
            else                                                   //~v56zI~
            {                                                      //~v56zI~
//                if (*(Pparm+PARM_OPD1POS2)==TC_CONSTSPECID) //constant//~v59kR~
//                {                                                //~v59kR~
//                    if (Sconstdatatype==CALC_STRINGCONST)        //~v59kR~
//                    {                                            //~v59kR~
//                        if (!Sconstlen) //opd3=@ "opd2 const" fmt//~v59kR~
//                        {                                        //~v59kR~
//                            if (strconst)   // string const specified//~v59kR~
//                            {                                    //~v59kR~
//                                Sconstaddr=strconst;             //~v59kR~
//                                Sconstlen=(int)strlen(strconst); //~v59kR~
////                              strconst=0; //accepted           //~v59kR~
//                            }                                    //~v59kR~
//                            else                                 //~v59kR~
//                            {                                    //~v59kR~
//                                uerrmsg("string constant operand missing",0);//~v59kR~
//                                return 4;                        //~v59kR~
//                            }                                    //~v59kR~
//                        }//Sconstlen                             //~v59kR~
//                        strconst=0; //accepted                   //~v59kR~
//                    }                                            //~v59kR~
//                    Sconstvalue[0]=(long)Sconstaddr;             //~v59kR~
//                    Sconstvalue[2]=Sconstlen;                    //~v59kR~
//                    Sconstdatatype=CALC_STRINGDATA;              //~v59kR~
//                }                                                //~v59kR~
				functype=CALC_COPY;                                //~v56zI~
//              memcpy(Pparm+PARM_DATATYPE2,Pparm+PARM_DATATYPE1,3*sizeof(int));//set to operand1//~v56zI~//~va70R~
                memcpy(Pparm+PARM_DATATYPE2,Pparm+PARM_DATATYPE1,3*sizeof(XECALCPARM));//set to operand1//~va70I~
//  	        memset(Pparm+PARM_DATATYPE1,0,3*sizeof(int));	//clear operand 1//~v56zI~//~va70R~
    	        memset(Pparm+PARM_DATATYPE1,0,3*sizeof(XECALCPARM));	//clear operand 1//~va70I~
                opcdlen=0;                                         //~v56zI~
                break;                                             //~v56zI~
            }                                                      //~v56zI~
          }                                                        //~v534I~
//          if (!Pparm[PARM_OPD1POS2]) 	//opd1 is should be specified//~v534R~
//          	return errinvalid(pc);                             //~v534R~
            ch=*pc;
//        if (ch=='+' && *(pc+1)=='-')  //count                    //~v535R~
//        {                                                        //~v535R~
//          functype=CALC_COUNT;                                   //~v535R~
//          pc+=2;                                                 //~v535R~
//        }                                                        //~v535R~
//        else                                                     //~v535R~
//        {                                                        //~v535R~
//  		if (ch=='='||!strchr(Sopcode,ch))	//1st byte is not opcode//~v590R~
    		if (ch==CALC_COMP)                                     //~v590I~
            {                                                      //~v590I~
            	if (*(pc+1)==CALC_COMP)	//"=="                     //~v590I~
                	pc++;	//skip "=="                            //~v590I~
                else                                               //~v590I~
              		return errinvalid(pc);                         //~v590I~
            }                                                      //~v590I~
            else                                                   //~v590I~
			  if (!strchr(Sopcode,ch))	//1st byte is not opcode   //~v590I~
            	return errinvalid(pc);
            functype=ch;
            pc++;
//        }                                                        //~v535R~
//  		if (tc_getopd(pc,Pparm+PARM_DATATYPE2,&pc))            //~v53JR~
//  		if (tc_getopd(1,pc,Pparm+PARM_DATATYPE2,&pc))//1:accept const value//~v59kR~
    		if (functype==CALC_COMP)                               //~v59kM~
            	strconstparm=strconst;                             //~v59kI~
            else                                                   //~v59kI~
            	strconstparm=0;                                    //~v59kI~
    		if (tc_getopd(2,pc,strconstparm,Pparm+PARM_DATATYPE2,&pc))//1:accept const value//~v59kR~
        		return 4;
//          if (!Pparm[PARM_OPD2POS2]) 	//opd2 is should be specified//~v534R~
//          	return errinvalid(pc);                             //~v534R~
            if (*pc)
            	return errinvalid(pc);
            break;
        case '+':
            functype=CALC_SUM;
            break;
        case '/':	//conversion "fld1/x" fmt                      //~v51mI~
            functype=CALC_CONV;                                    //~v51mR~
            ch=toupper(*(pc+1));                                   //~v51mR~
            if (ch=='U' && toupper(*(pc+2))=='Z')                  //~v529I~
            {                                                      //~v529I~
                ch='Y';     //internal id                          //~v529I~
                pc++;       //2byte skip                           //~v529I~
            }                                                      //~v529I~
            else                                                   //~v529I~
            if (ch!='Y')     //allow also 'Y'                      //~v529I~
			if (ch!='L')                                           //~v51mI~
				if (!(ch=tc_chkdatatype(ch)))                      //~v51mI~
					return errinvalid(pc);                         //~v51mR~
//          *(Pparm+PARM_KEYDATATYPE)=ch;  //target conversion type//~v51mI~//~vb30R~
            *(Pparm+PARM_KEYDATATYPE)=(XECALCPARM)ch;  //target conversion type//~vb30I~
            pc++;	//to chk next is null                          //~v51mM~
            break;                                                 //~v51mI~
        }
    	break;
    case 2:
    	if (*(pc+1)=='=')
        {
	    	if (strchr(Sopcode,*pc))
                functype=*pc;
		}
        else
        if (!memcmp(pc,"++",2))
            functype=CALC_ACUM;
        else
        if (!memcmp(pc,"--",2))
	        functype=CALC_DIF;
        else
        if (!memcmp(pc,"+/",2))
            functype=CALC_SUM;	//with key break
//      else                                                       //~v535R~
//      if (!memcmp(pc,"+-",2))                                    //~v535R~
//          functype=CALC_COUNT;//count record                     //~v535R~
        break;
    case 3:
        if (!memcmp(pc,"+//",3))
            functype=CALC_SUM;	//with count key break
//      else                                                       //~v535R~
//      if (!memcmp(pc,"+-=",3))                                   //~v535R~
//          functype=CALC_COUNT;	//with count key break         //~v535R~
        break;
	}//opcodelen
	if (!functype)
    	return errinvalid(pc);
//  *Pfunctype=functype;                                           //~v56zR~

	pc+=opcdlen;
    switch(functype)
    {
    case CALC_TARGET:
    case CALC_ACUM:
    case CALC_DIF:
    case CALC_CONV:                                                //~v51mI~
        if (*pc)
    		return errinvalid(pc);	//no opd2 required
        break;
    case CALC_COPY:		//opd1=opd2 fmt                            //~v56zI~
        break;                                                     //~v56zI~
    case CALC_SUM:
    	switch(opcdlen)
        {
        case 1:		//"+"
			if (*pc)
	    		return errinvalid(pc);	//no opd2 required
            break;
    	case 2:		//"+/tcc-cc/value"
//key datatype
	    	cdatatype=0;
            ch=*pc;
          if (ch!=TCHDR_FLDSEPID)                                  //~v40RR~
    		if (!(ch>='0' && ch<='9'))	//not numeric
        	{
				if (!(cdatatype=tc_chkdatatype(ch)))
					errinvalid(pc);
            	pc++;
			}
//          *(Pparm+PARM_KEYDATATYPE)=cdatatype;   //distance      //~vb30R~
            *(Pparm+PARM_KEYDATATYPE)=(XECALCPARM)cdatatype;   //distance//~vb30I~
//key column
//      	if (tc_getnumrange(pc,&pos1,&pos2,&pc2)                //~v40RR~
        	if (tc_getnumrange_f(pc,&pos1,&pos2,&pc2))             //~v40RR~
//  		||  (pos2-pos1)>MAXKEYLEN)								//2 opd only//~v40RR~
    			return errinvalid(pc);
            pckey=pc;		//for later err msg                    //~v40RR~
            *(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEY;  //subsum by key
//          *(Pparm+PARM_KEYCOL1)=(int)pos1-1;     //offset        //~vb30R~
            *(Pparm+PARM_KEYCOL1)=((XECALCPARM)pos1-1);     //offset//~vb30I~
//          *(Pparm+PARM_KEYCOL2)=(int)pos2;   //next offset       //~vb30R~
            *(Pparm+PARM_KEYCOL2)=(XECALCPARM)pos2;   //next offset//~vb30I~
            breakeqsw=1;    //default ascending key                //~v53DI~
            switch(*pc2)                                           //~v53DI~
            {                                                      //~v53DI~
            case '!':                                              //~v53DR~
            	breakeqsw=0;                                       //~v53DI~
            	*(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEY_EQ;  //subsum by key//~v53DI~
            	pc2++;                                             //~v53DI~
                break;                                             //~v53DI~
            case '<':                                              //~v53DR~
            	breakeqsw=-1;                                      //~v53DI~
            	*(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEY_LT;  //subsum by key//~v53DI~
            	pc2++;                                             //~v53DI~
                break;                                             //~v53DI~
            case '>':   //default accending key                    //~v53DR~
            	pc2++;                                             //~v53DI~
                break;                                             //~v53DI~
          	}                                                      //~v53DI~
            pc=pc2;
//key value
            if (*pc)
            {
            	if (*pc!='/')
    				return errinvalid(pc);
            	pc++;			//value
	    		gdatatype=0;
            	ch=*pc;
    			if (!(ch>='0' && ch<='9'))	//not numeric
        		{
					if (!(gdatatype=tc_chkdatatype(ch))
					||  gdatatype=='T')
						errinvalid(pc);

					pc++;
				}
                memset(wkl,0,sizeof(wkl));                         //+vba6R~
//      		if (tc_getlinedata(&gdatatype,pc,(int)strlen(pc),wkl)  //key value//~v57JR~
#ifdef UTF8UCS2                                                    //~va20R~
//*!ebc,cmd string                                                 //~va50I~
//      		if (tc_getlinedata(0,&gdatatype,pc,0/*dbcs*/,(int)strlen(pc),wkl)  //key value//~va20R~//~va79R~
        		if (tc_getlinedata(0,0/*handle*/,&gdatatype,pc,0/*dbcs*/,(int)strlen(pc),wkl)  //key value//~va79I~
#else                                                              //~va20R~
        		if (tc_getlinedata(0,&gdatatype,pc,(int)strlen(pc),wkl)  //key value//~v57JI~
#endif                                                             //~va20R~
				||  wkl[1])
	    			return errinvalid(pc);	//no opd2 required
              switch(breakeqsw)                                    //~v53DI~
              {                                                    //~v53DI~
              case 0:                                              //~v53DI~
                *(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEYGRP_EQ;  //subsum by key equal(not assecding)//~v53DI~
                break;                                             //~v53DI~
              case -1:                                             //~v53DI~
                *(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEYGRP_LT;  //subsum by key equal(not assecding)//~v53DI~
                break;                                             //~v53DI~
              default:                                             //~v53DI~
                *(Pparm+PARM_BREAKTYPE)=PARM_BREAK_KEYGRP;  //subsum by key
              }                                                    //~v53DI~
//              *(Pparm+PARM_KEYBREAKVALUE)=(int)wkl[0];           //~vb30R~
                *(Pparm+PARM_KEYBREAKVALUE)=(XECALCPARM)wkl[0];    //~vb30I~
            }//key value
            break;
    	case 3:		//"+//nn"
//count
//      	if (tc_getnumrange(pc,&pos1,&pos2,&pc2)!=1             //~v62pR~
        	if (ugetnumrange3(pc,&pos1,&pos2,&pc2)!=1              //~v62pI~
			||  *pc2!=0)								//1 opd only
	    		return errinvalid(pc);	//no opd2 required
            *(Pparm+PARM_BREAKTYPE)=PARM_BREAK_COUNT;		//subsum by count
//          *(Pparm+PARM_COUNT)=pos1;                              //~vb30R~
            *(Pparm+PARM_COUNT)=(XECALCPARM)pos1;                  //~vb30I~
            break;
        }// +/
        break;
	default:		//2 operand type
        if (!Pparm[PARM_OPD3POS2])	//	not 3 opd type
        {
//  		if (tc_getopd(pc,Pparm+PARM_DATATYPE2,&pc))            //~v53JR~
//  		if (tc_getopd(1,pc,Pparm+PARM_DATATYPE2,&pc))//1:accept const value//~v59kR~
    		if (functype==CALC_COMP)                               //~v59kI~
            	strconstparm=strconst;                             //~v59kI~
            else                                                   //~v59kI~
            	strconstparm=0;                                    //~v59kI~
    		if (tc_getopd(2,pc,strconstparm,Pparm+PARM_DATATYPE2,&pc))//1:accept const value//~v59kR~
    	    	return 4;
            if (*(Pparm+PARM_OPD2POS2)==TC_CONSTSPECID)	//constant //~v59kR~
            {                                                      //~v59kI~
             	if (Sconstdatatype==CALC_STRINGCONST)              //~v59kI~
                {                                                  //~v59kI~
//                  Sconstvalue[0]=(long)Sconstaddr;               //~v59kI~//~vafkR~
                    Sconstvalue[0]=(SLPTR)Sconstaddr;              //~vafkI~
                    Sconstvalue[2]=Sconstlen;                      //~v59kI~
                    Sconstdatatype=CALC_STRINGDATA;                //~v59kI~
                }                                                  //~v59kI~
            }                                                      //~v59kI~
            if (*pc)
            	return errinvalid(pc);
		}
    }//opd len
    if (functype!=CALC_SUM)
    {
    	if (*(Pparm+PARM_OUTFNM) )                                 //~v58zI~
        {                                                          //~v58zI~
            uerrmsg("-O option is for summary operation only.",    //~v58zI~
                    "-O(ファイル出力オプション)は\"+\"(合計)のときのみ");//~v58zI~
    		return 4;                                              //~v58zI~
        }                                                          //~v58zI~
    	if (*(Pparm+PARM_OPTION) & PARM_SUMISRT_MASK)
        {
            uerrmsg("Insert option is only for \"+\"(summary)",
                    "挿入位置指定は\"+\"(合計)のときのみ");
    		return 4;
        }
    	if (*(Pparm+PARM_OPTION) & (PARM_SUMISRT_AVE|PARM_SUMISRT_MM))
        {
            uerrmsg("Average/Min/Max is only for \"+\"(summary)",
                    "平均/最大/最小指定は\"+\"(合計)のときのみ");
    		return 4;
        }
    	if (!(*(Pparm+PARM_OPTION) & PARM_SUMISRT_IGNORE))	//no ignore//~v17hI~
    		*(Pparm+PARM_OPTION)|=PARM_SUMISRT_SUMERR;	//treate as err//~v17hI~
    }
//  opt=*(Pparm+PARM_OPTION);                                      //~vaz8R~
    opt=(int)(*(Pparm+PARM_OPTION));                               //~vaz8I~
    if (opt & PARM_INS)	//insert option                            //~v56zI~
    {                                                              //~v56zI~
    	if (functype!=CALC_COPY    //Not opd3=opd2 operation       //~v56zI~
        &&  !*(Pparm+PARM_OPD3POS2))//Not opd3=opd1 op opd2 fmt    //~v56zI~
        {                                                          //~v56zI~
            uerrmsg("INS option is valid for opd3=[opd1 op ]opd2 format.",//~v56zI~
                    "INS オプションはopd3=[opd1 op ]opd2 で使用。");//~v56zI~
    		return 4;                                              //~v56zI~
        }                                                          //~v56zI~
    }                                                              //~v56zI~
    if (functype==CALC_COPY)   //Not opd3=opd2 operation           //~v56zI~
    {                                                              //~v56zI~
      if (*(Pparm+PARM_OPD2POS2)==TC_CONSTSPECID) 	//constant 2nd opd//~v601R~
      	if (Sconstdatatype==CALC_STRINGDATA)	                   //~v601R~
        	*(Pparm+PARM_DATATYPE3)=CALC_STRINGDATA;               //~v601I~
        else                                                       //~v601I~
    		functype=CALC_COPYCV;   //t:opd3=t:opd2 operation      //~v601I~
      else                                                         //~v601I~
        if ((*(Pparm+PARM_DATATYPE3)||*(Pparm+PARM_DATATYPE2))     //~v56zR~
//      &&  (*(Pparm+PARM_DATATYPE3)!=*(Pparm+PARM_DATATYPE2)))    //~v604R~
           )                                                       //~v604I~
    		functype=CALC_COPYCV;   //t:opd3=t:opd2 operation      //~v56zR~
        else                                                       //~v56zI~
        {                                                          //~v56zI~
        	*(Pparm+PARM_DATATYPE3)=CALC_STRINGDATA;               //~v56zI~
        	*(Pparm+PARM_DATATYPE2)=CALC_STRINGDATA;               //~v56zI~
        }                                                          //~v56zI~
    }//COPY                                                        //~v56zI~
    if (functype==CALC_COMP)                                       //~v605I~
    {                                                              //~v605I~
      	if (*(Pparm+PARM_OPD2POS2)==TC_CONSTSPECID) 	//constant 2nd opd//~v605I~
        {                                                          //~v605I~
      		if (Sconstdatatype==CALC_STRINGDATA)                   //~v605I~
            {                                                      //~v605I~
                if (*(Pparm+PARM_DATATYPE1)==CALC_STRINGDATA)      //~v605R~
                {                                                  //~v605I~
                	uerrmsg("compare datatype unmatch",            //~v605I~
                    	    "比較できないデータタイプ");           //~v605I~
                	return 4;                                      //~v605I~
                }                                                  //~v605I~
                else                                               //~v605I~
                {                                                  //~v605I~
                	*(Pparm+PARM_DATATYPE1)=CALC_STRINGDATA;       //~v605I~
		        	*(Pparm+PARM_DATATYPE2)=CALC_STRINGDATA;       //~v605I~
                }                                                  //~v605I~
            }                                                      //~v605I~
        }                                                          //~v605I~
        else                                                       //~v605I~
        {                                                          //~v605I~
	        if (!*(Pparm+PARM_DATATYPE1) && !*(Pparm+PARM_DATATYPE2))//default string comp//~v605I~
            {                                                      //~v605I~
                *(Pparm+PARM_DATATYPE1)=CALC_STRINGDATA;           //~v605I~
                *(Pparm+PARM_DATATYPE2)=CALC_STRINGDATA;           //~v605I~
            }                                                      //~v605I~
        }                                                          //~v605I~
    }//CALC_COMP                                                   //~v605I~
//  if (opt & (PARM_COPYRJUST|PARM_COPYREP))	//REP/LJ option    //~v56zR~
    if (opt & PARM_COPYRJUST)	//REP/LJ option                    //~v56zI~
    {                                                              //~v56zI~
    	if (functype!=CALC_COPY)    //Not opd3=opd2 operation      //~v56zI~
        {                                                          //~v56zI~
//          uerrmsg("REP,RJ option is valid for opd3=opd2 format with no data conversion.",//~v56zR~
//                  "REP,RJ オプションは変換のないopd3=opd2形式で使用。");//~v56zR~
            uerrmsg("RJ option is valid for opd3=opd2 format with no data conversion.",//~v56zI~
                    "RJ オプションは変換のないopd3=opd2形式で使用。");//~v56zI~
    		return 4;                                              //~v56zI~
        }                                                          //~v56zI~
//      if (opt & PARM_COPYRJUST                                   //~v56zR~
//      &&  opt & PARM_COPYREP)                                    //~v56zR~
//      {                                                          //~v56zR~
//          uerrmsg("REP and RJ option is mutualy exclusive.",     //~v56zR~
//                  "REPとRJ オプションは矛盾します。");           //~v56zR~
//  		return 4;                                              //~v56zR~
//      }                                                          //~v56zR~
    }                                                              //~v56zI~
	rc=0;
	if (labtctr)
    {
      if (functype!=CALC_COPY)    //Not opd3=opd2 operation(no operand1)//~v76DI~
		if (!Pparm[PARM_OPD1POS2])
        {
            uerrmsg("Label is avail only when operand by column",
                    "ラベル指定はオペランドがカラム指定のとき有効");
    		return 4;
        }
        if (labtctr!=2 && labtctr!=MAXLABEL)                       //~v17hR~
            return fcmdlabelerr("Need From and To");
    	rc=fcmdgetlabelrange(pfh,2,labt,Pplabplh,0);//not drop cmd //~v17hR~
        if (!rc)                                                   //~v17hI~
        	if (labtctr==MAXLABEL)	//2 set                        //~v17hR~
		    	rc=fcmdgetlabelrange(pfh,2,labt+2,Pplabplh+2,0);//not drop cmd//~v17hR~
        if (rc)                                                    //~v41dI~
            return rc;                                             //~v41dI~
    }
    if (rc=tc_fldnochk(Ppcw,pfh,Pparm,Pplabplh),rc)                //~v40RR~
    	return rc;                                                 //~v40RI~
    if (*(Pparm+PARM_KEYCOL2)-*(Pparm+PARM_KEYCOL1)>MAXKEYLEN)								//2 opd only//~v40RR~
    {                                                              //~v40RI~
    	uerrmsg("Too long key field %s(max=%d)",                   //~v40RI~
        		"キーフィールド(%s) が長すぎる(max %d)",           //~v40RI~
                pckey,MAXKEYLEN);	                               //~v40RI~
    	return 4;                                                  //~v40RR~
    }                                                              //~v40RI~
//    if (functype==CALC_COMP)                                     //~v605R~
//    {                                                            //~v605R~
//        if (!*(Pparm+PARM_DATATYPE1) && !*(Pparm+PARM_DATATYPE2))//string comp//~v605R~
//        {                                                        //~v605R~
//            if (*(Pparm+PARM_OPD2POS2)==TC_CONSTSPECID)          //~v605R~
//              if (Sconstdatatype==CALC_STRINGDATA)               //~v605R~
//                opd2len=Sconstlen;                               //~v605R~
//              else                                               //~v605R~
//                opd2len=-1;                                      //~v605R~
//            else                                                 //~v605R~
//                opd2len=*(Pparm+PARM_OPD2POS2)-*(Pparm+PARM_OPD2POS1);//~v605R~
//            if ((*(Pparm+PARM_OPD1POS2)-*(Pparm+PARM_OPD1POS1))  //~v605R~
////              !=(*(Pparm+PARM_OPD2POS2)-*(Pparm+PARM_OPD2POS1)))//~v605R~
//                !=opd2len)                                       //~v605R~
//            {                                                    //~v605R~
//                uerrmsg("field length is not same for string compare",//~v605R~
//                        "文字列比較のフィールド長が異なる");     //~v605R~
//                return 4;                                        //~v605R~
//            }                                                    //~v605R~
//        }                                                        //~v605R~
//    }                                                            //~v605R~
//    if (strconst)   //string const "const value" specified for not copy operation//~v59kR~
//    {                                                            //~v59kR~
//        uerrmsg("\"%s\" is invalid",0,                           //~v59kR~
//                strconst);                                       //~v59kR~
//        return 4;                                                //~v59kR~
//    }                                                            //~v59kR~
    if (strconst)   //string const "const value" specified for not copy operation//~va5cI~
    {                                                              //~va5cI~
      if (functype!=CALC_COPY    //Not opd3=opd2 operation(no operand1)//~va5cI~
      &&  functype!=CALC_COMP    //Not opd3=opd2 operation(no operand1)//~va5cI~
      )                                                            //~va5cI~
      {                                                            //~va5cI~
        uerrmsg("string constant(\"%s\") is invalid in this case.",0,//~va5cR~
                strconst);                                         //~va5cI~
        return 4;                                                  //~va5cI~
      }                                                            //~va5cI~
    }                                                              //~va5cI~
    Pparm[PARM_CONSTVALUE]=(XECALCPARM)Sconstvalue;                //~va7aR~
    Pparm[PARM_CONSTDATATYPE]=(XECALCPARM)Sconstdatatype;          //~va7aR~
    Pparm[PARM_CONSTADDR]=(XECALCPARM)Sconstaddr;                  //~va7aR~
    Pparm[PARM_CONSTLEN]=(XECALCPARM)Sconstlen;                    //~va7aR~
    *Pfunctype=functype;                                           //~v56zI~
    return rc;
}//tc_opdchk
//*******************************************************          //~v40RI~
//*tc_fldnochk                                                     //~v40RI~
//* get datatype and column inf from txx-yy                        //~v40RI~
//* parm1 :string                                                  //~v40RI~
//* parm2 :output int array(datatype,star-pos,end-pos)             //~v40RI~
//* parm3 :stopped addr                                            //~v40RI~
//* return:0, 4:err                                                //~v40RI~
//******************************************************           //~v40RI~
//int tc_fldnochk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pparm,PULINEH *Pplabplh)//~v40RI~//~va70R~
int tc_fldnochk(PUCLIENTWE Ppcw,PUFILEH Ppfh,XECALCPARM *Pparm,PULINEH *Pplabplh)//~va70I~
{                                                                  //~v40RI~
//	int  fldno,*pfldtb,parmidx,rc=0,ii;                            //~v40RR~//~vaf9R~
  	int  fldno=0,*pfldtb,parmidx,rc=0,ii;                          //~vaf9R~
    int jj;                                                        //~v62CR~
static int Sopdparmno[]={PARM_OPD1POS1,PARM_OPD2POS1,PARM_OPD3POS1,PARM_KEYCOL1};//~v40RI~
//*******************                                              //~v40RI~
	if (!(*(Pparm+PARM_OPD1POS2)==TC_FLDNOSPECID)                  //~v40RR~
	&&  !(*(Pparm+PARM_OPD2POS2)==TC_FLDNOSPECID)                  //~v40RR~
	&&  !(*(Pparm+PARM_OPD3POS2)==TC_FLDNOSPECID)                  //~v40RR~
	&&  !(*(Pparm+PARM_KEYCOL2)==TC_FLDNOSPECID))                  //~v40RR~
        return 0;   //no fldno specification                       //~v40RI~
	pfldtb=tc_chkhdr(Ppcw,Ppfh,Pplabplh);	//field offset tbl     //~v40RR~
    if (!pfldtb)                                                   //~v40RI~
    {                                                              //~v40RI~
    	uerrmsg("No Field definition hdr line,Use \"TC FMT H\".",  //~v40RI~
        		"フィールド定義行なし、\"TC FMT H\"で設定要");     //~v40RI~
    	return 4;                                                  //~v40RI~
    }                                                              //~v40RI~
//  if (pfldtb==(int*)-1)                                          //~v40RI~//~vafkR~
    if (pfldtb==(int*)(ULPTR)-1)                                   //~vafkI~
    	return 4;                                                  //~v40RI~
    for (ii=0;ii<4;ii++)                                           //~v40RI~
    {                                                              //~v40RI~
    	parmidx=Sopdparmno[ii];                                    //~v40RR~
//  	fldno=(*(Pparm+parmidx)+1);	//it was changed to offset column//~vaz8R~
    	fldno=(int)(*(Pparm+parmidx)+1);	//it was changed to offset column//~vaz8I~
    	if (*(Pparm+parmidx+1)==TC_FLDNOSPECID)                    //~v40RR~
    	{                                                          //~v40RI~
        	if (fldno>pfldtb[0])    //top is max fldno             //~v40RI~
            {                                                      //~v40RI~
            	rc=4;                                              //~v40RI~
        		break;                                             //~v40RI~
            }                                                      //~v40RI~
//  		*(Pparm+parmidx)=pfldtb[fldno];	//start offset         //~v62AR~
//  		*(Pparm+parmidx)=pfldtb[fldno]+1;	//start offset,it is delm position//~v62AI~//~vb30R~
    		*(Pparm+parmidx)=(XECALCPARM)pfldtb[fldno]+1;	//start offset,it is delm position//~vb30I~
//  		*(Pparm+parmidx+1)=pfldtb[fldno+1];                    //~v62CI~
//          for (jj=fldno+1;jj<=pfldtb[0];jj++)                    //~v62LR~
            for (jj=fldno+1;jj<=pfldtb[0]+1;jj++)                  //~v62LI~
            	if (pfldtb[jj])                                    //~v62CI~
                {                                                  //~v62CI~
//					*(Pparm+parmidx+1)=pfldtb[jj];                 //~v62CI~//~vb30R~
  					*(Pparm+parmidx+1)=(XECALCPARM)pfldtb[jj];     //~vb30I~
                    break;                                         //~v62CI~
                }                                                  //~v62CI~
//        	if (jj>pfldtb[0])    //top is max fldno                //~v62LR~
        	if (jj>pfldtb[0]+1)    //top is max fldno              //~v62LI~
            {                                                      //~v62CI~
            	rc=4;                                              //~v62CI~
        		break;                                             //~v62CI~
            }                                                      //~v62CI~
        }                                                          //~v40RI~
    }                                                              //~v40RI~
    if (rc)                                                        //~v40RI~
    {                                                              //~v40RI~
		uerrmsg("field(%d) number specification err",              //~v40RI~
    			"フィールド番号(%d)指定エラー",                    //~v40RI~
            		fldno);                                        //~v40RR~
    }                                                              //~v40RI~
    return rc;                                                     //~v40RI~
}//tc_fldnochk                                                     //~v40RI~
//*******************************************************          //~vafkI~
//*******************************************************
//*tc_getopd
//* get datatype and column inf from txx-yy
//* parm1 :string
//* parm2 :output int array(datatype,star-pos,end-pos)
//* parm3 :stopped addr
//* return:0, 4:err
//******************************************************
//int tc_getopd(char *Pstr,int *Pparm,char **Pnext)                //~v53JR~
//int tc_getopd(int Pallowconstsw,char *Pstr,int *Pparm,char **Pnext)//~v59kR~
//int tc_getopd(int Pallowconstsw,char *Pstr,char *Pstrconst,int *Pparm,char **Pnext)//~v59kI~//~va70R~
int tc_getopd(int Pallowconstsw,char *Pstr,char *Pstrconst,XECALCPARM *Pparm,char **Pnext)//~va70I~
{
	int rc,datatype=0,datatyped;                                   //~v53JI~
	int  ch,pos1,pos2;
    char *pc,*pc2;
//*******************
    Pallowconstsw&=~CALC_STRINGQUOTE;	//used                     //~v59jI~
	pc=Pstr;
    if (*pc)
    {
     ch=*pc;                                                       //~v56zR~
     if (ch==CALC_STRINGCONST)   //string constant id              //~v56zI~
     {                                                             //~v56zI~
         if (Pallowconstsw!=2)                                     //~v56zR~
             return errinvalid(pc);                                //~v56zI~
         pc++;                                                     //~v56zI~
         if (!*pc)                                                 //~v59kI~
         {                                                         //~v59kI~
         	if (pc+1==Pstrconst)	// @"xxx" or @ "xxx" fmt       //~v59kR~
         		pc++;                                              //~v59kR~
            else                                                   //~v59kI~
            {                                                      //~v59kI~
            	uerrmsg("string constant operand missing",0);      //~v59kI~
                return 4;                                          //~v59kI~
            }                                                      //~v59kI~
         }                                                         //~v59kI~
         Sconstaddr=pc;      //for ft2count                        //~v56zI~
         Sconstlen=(int)strlen(pc);  //for ft2count                //~v56zI~
         Sconstdatatype=ch;                                        //~v56zI~
         pc+=Sconstlen;                                            //~v56zI~
         pos1=1;                                                   //~v56zI~
         pos2=TC_CONSTSPECID;                                      //~v56zI~
//       *(Pparm+1)=pos1-1;  //opd datatype                        //~v56zI~//~vb30R~
         *(Pparm+1)=(XECALCPARM)pos1-1;  //opd datatype            //~vb30I~
//       *(Pparm+2)=pos2;  //opd datatype                          //~v56zI~//~vb30R~
         *(Pparm+2)=(XECALCPARM)pos2;  //opd datatype              //~vb30I~
//      Sconstvalue[0]=(long)Sconstaddr;                           //~v59kI~//~vafkR~
        Sconstvalue[0]=(SLPTR)Sconstaddr;                          //~vafkI~
        Sconstvalue[2]=Sconstlen;                                  //~v59kI~
        Sconstdatatype=CALC_STRINGDATA;                            //~v59kI~
     }                                                             //~v56zI~
     else                                                          //~v56zI~
     {//not string const                                           //~v56zI~
      if (ch!=TCHDR_FLDSEPID)                                      //~v40RR~
        if (!(ch>='0' && ch<='9'))  //not numeric
        {
//          if (!(Pparm[0]=tc_chkdatatype(ch)))                    //~vb30R~
            if (!(Pparm[0]=(XECALCPARM)tc_chkdatatype(ch)))        //~vb30I~
                return errinvalid(pc);
            datatype=ch;                                           //~v53JI~
            ch=*(++pc);
        }
      	if (ch==TCHDR_FLDSEPID                                     //~v40RR~
        ||  (ch>='0' && ch<='9'))   //not numeric                  //~v40RR~
        {
//          if (tc_getnumrange(pc,&pos1,&pos2,&pc2))//opd col      //~v40RR~
            if (tc_getnumrange_f(pc,&pos1,&pos2,&pc2))//opd col    //~v40RR~
            {                                                      //~v53JI~
            	if (Pallowconstsw)	//constant value allowed       //~v53JI~
                {                                                  //~v53JI~
                	pc=Pstr;		//chk datatype by bc_getvalue  //~v54JI~
                    Sconstlen=(int)strlen(pc);	//for ft2count     //~v53JI~
                    Sconstaddr=pc;		//for ft2count             //~v53JI~
                    pc2=pc+Sconstlen;	//const should be last value//~v53JI~
//              	rc=bc_getvalue(pc,Sconstvalue,&datatype,&datatyped);//~v57JR~
                	rc=bc_getvalue(0,pc,Sconstvalue,&datatype,&datatyped);//0:no dwordup//~v57JI~
                    if (!rc)                                       //~v53JI~
                    {                                              //~v53JI~
                    	pos1=1;                                    //~v53JI~
                    	pos2=TC_CONSTSPECID;	                   //~v53JR~
        				Sconstdatatype=datatype; 			//returned by getplhvalue//~v54JI~
                    }                                              //~v53JI~
                }                                                  //~v53JI~
                else                                               //~v53JI~
                	rc=4;	//err id                               //~v53JI~
              if (rc)                                              //~v53JI~
                return errinvalid(pc);
            }                                                      //~v53JI~
//          *(Pparm+1)=pos1-1;  //opd datatype                     //~vb30R~
            *(Pparm+1)=(XECALCPARM)pos1-1;  //opd datatype         //~vb30I~
//          *(Pparm+2)=pos2;  //opd datatype                       //~vb30R~
            *(Pparm+2)=(XECALCPARM)pos2;  //opd datatype           //~vb30I~
            pc=pc2;
        }
     }//not string const                                           //~v56zI~
    }
    else	//!*pc                                                 //~v59kI~
    {                                                              //~v59kI~
    	if (pc+1==Pstrconst)	                                   //~v59kI~
        {                                                          //~v59kI~
            if (!Pallowconstsw)                                    //~v59kI~
                return errinvalid(pc);                             //~v59kI~
            pc++;                                                  //~v59kI~
            Sconstaddr=pc;      //for ft2count                     //~v59kI~
            Sconstlen=(int)strlen(pc);  //for ft2count             //~v59kI~
//          Sconstdatatype=CALC_STRINGCONST;                       //~v601R~
            Sconstdatatype=CALC_STRINGDATA;                        //~v601I~
            pc+=Sconstlen;                                         //~v59kI~
            pos1=1;                                                //~v59kI~
            pos2=TC_CONSTSPECID;                                   //~v59kI~
//          *(Pparm+1)=pos1-1;  //opd datatype                     //~v59kI~//~vb30R~
            *(Pparm+1)=(XECALCPARM)pos1-1;  //opd datatype         //~vb30I~
//          *(Pparm+2)=pos2;  //opd datatype                       //~v59kI~//~vb30R~
            *(Pparm+2)=(XECALCPARM)pos2;  //opd datatype           //~vb30I~
//          Sconstvalue[0]=(long)Sconstaddr;                       //~v59kI~//~vafkR~
            Sconstvalue[0]=(SLPTR)Sconstaddr;                      //~vafkI~
            Sconstvalue[2]=Sconstlen;                              //~v59kI~
//          Sconstdatatype=CALC_STRINGDATA;                        //~v601R~
        }//next is strconst enclosed by quote                      //~v59kI~
    }                                                              //~v59kI~
    *Pnext=pc;
    return 0;
}//tc_getopd
//*******************************************************          //~v40RI~
//*tc_getnumrange_f                                                //~v40RI~
//* get start/end value from nnn-mmm format (nnn<mmm)              //~v40RI~
//* OR nnnF (fld number specification)                             //~v40RI~
//* parm1 :string                                                  //~v40RI~
//* parm2 :start field column value                                //~v40RI~
//* parm3 :end   field column vlue                                 //~v40RI~
//* parm4 :next analyze addr                                       //~v40RR~
//* return:0, 1(delmctr=1 (not fldno)) 2(end<start) or 4           //~v40RI~
//******************************************************           //~v40RI~
int tc_getnumrange_f(char *Pstr,int *Pstart,int *Pend,char **Ppcend)//~v40RR~
{                                                                  //~v40RI~
	int rc,fldno;                                                  //~v40RR~
    char *pc;                                                      //~v40RI~
//******************                                               //~v40RI~
	pc=Pstr;                                                       //~v40RI~
    if (*pc==TCHDR_FLDSEPID)	//one of field specification id    //~v40RR~
    {                                                              //~v40RI~
    	pc++;                                                      //~v40RI~
    	while(*pc==TCHDR_FLDSEPCONTID)	//of spacelen              //~v40RI~
        	pc++;                                                  //~v40RI~
        if (*pc>='1' && *pc<='9')	//not numeric                  //~v40RI~
        {                                                          //~v62zI~
        	fldno=*pc-'0';                                         //~v40RI~
            if (*(pc+1)>='0' && *(pc+1)<='9')                      //~v62zI~
            {                                                      //~v62zI~
                pc++;                                              //~v62zI~
                fldno=fldno*10+*pc-'0';                            //~v62zI~
            }                                                      //~v62zI~
        }                                                          //~v62zI~
        else                                                       //~v40RI~
//      if (*pc>='A' && *pc<='Z')	//not numeric                  //~v62zR~
//      	fldno=*pc-'A'+10;                                      //~v62zR~
//      else                                                       //~v62zR~
//      if (*pc>='a' && *pc<='z')	//not numeric                  //~v62zR~
//      	fldno=*pc-'a'+36;                                      //~v62zR~
//      else                                                       //~v62zR~
        	return errinvalid(Pstr);                               //~v40RI~
        pc++;                                                      //~v40RI~
//      if (toupper(*pc)==TCFLDNUMID)                              //~v54LR~
//          pc++;                                                  //~v54LR~
    	*Ppcend=pc;                                                //~v40RR~
        *Pstart=fldno;                                             //~v40RI~
    }                                                              //~v40RI~
    else                                                           //~v40RI~
    {                                                              //~v40RI~
//      rc=tc_getnumrange(pc,Pstart,Pend,Ppcend);                  //~v62pR~
        rc=ugetnumrange3(pc,Pstart,Pend,Ppcend);                   //~v62pI~
//      if (rc!=1)                                                 //~v54LR~
//          return rc;                                             //~v54LR~
//      if (toupper(**Ppcend)!=TCFLDNUMID)                         //~v54LR~
        	return rc;                                             //~v40RI~
//      *Ppcend=*Ppcend+1;                                         //~v54LR~
//      fldno=*Pstart;                                             //~v54LR~
    }                                                              //~v40RI~
    if (!fldno)                                                    //~v40RI~
        return errinvalid(Pstr);                                   //~v40RI~
    *Pend=TC_FLDNOSPECID;                                          //~v40RI~
    return 0;                                                      //~v40RI~
}//tc_getnumrange_f                                                //~v40RI~
#endif                                                             //~v50EI~
#ifndef DOSDOS                                                     //~v50EI~
//****************************************************************
// calc opd chk
// ctlbreak:[0]:type [1]:col1 or count [2]:col2 [3]:datatype [4]-[6]:break value
//*rc   :0 or 4
//****************************************************************
//int tc_opdchk2(char *Popd2,int *Pparm)                           //~va70R~
int tc_opdchk2(char *Popd2,XECALCPARM *Pparm)                      //~va70I~
{
	char *pc;
    int opt;
    int vprec,vround;                                              //~v58vR~
//*********************************
	pc=Popd2;
    if (*pc=='-'||*pc=='/')
    {                                                              //~v58zI~
    	pc++;
        switch(toupper(*pc))                                       //~v58zI~
        {                                                          //~v58zI~
        case 'O':	//outfilename                                  //~v58zI~
        	pc++;                                                  //~v58zI~
        	if (!*pc)                                              //~v58zI~
            	return 4;                                          //~v58zI~
//  	    Pparm[PARM_OUTFNM]=(int)(ULONG)pc;                     //~v59kR~//~vafkR~
    	    Pparm[PARM_OUTFNM]=(XECALCPARM)pc;                     //~vafkI~
    		return 0;                                              //~v58zI~
        }                                                          //~v58zI~
    }                                                              //~v58zI~
                                                                   //~v17fI~
    if (!stricmp(pc,"NX"))                                         //~v17fR~
    {                                                              //~v17fI~
    	Pparm[PARM_NXSW]=1;                                        //~v17fI~
    	return 0;                                                  //~v17fI~
    }                                                              //~v17fI~
    if (toupper(*pc)=='V')	//VnR                                  //~v58vI~
    {                                                              //~v58vI~
        if (ucalc_chkvrparm(pc,&vprec,&vround,0))                  //~v58vI~
        	return 4;                                              //~v58vI~
        opt=0;                                                     //~v58vI~
        if (vround)                                                //~v58vI~
        	opt|=PARM_ROUND;                                       //~v58vI~
        if (vprec!=-1)                                             //~v58vI~
            opt|=PARM_VPREC;                                       //~v58vR~
//		Pparm[PARM_PRECNO]=vprec;                                  //~v58vR~//~vb30R~
  		Pparm[PARM_PRECNO]=(XECALCPARM)vprec;                      //~vb30I~
//  	Pparm[PARM_OPTION]|=opt;                                   //~v58vI~//~vb30R~
    	Pparm[PARM_OPTION]|=(XECALCPARM)opt;                       //~vb30I~
        return 0;                                                  //~v58vI~
    }                                                              //~v58vI~
//  if (strlen(pc)<3)                                              //~v56zR~
    if (strlen(pc)<2)                                              //~v56zI~
    	return 4;

    opt=0;
    if (!memicmp(pc,"Zero",3))                                     //~v473R~
    	opt=PARM_PADD0;				//zero padding for result      //~v473I~
	else                                                           //~v473I~
    if (!memicmp(pc,"TOP",3))
    	opt=PARM_SUMISRT_TOP;
	else
    if (!memicmp(pc,"LASt",3))
    	opt=PARM_SUMISRT_LAST;
	else
    if (!memicmp(pc,"END",3))
    	opt=PARM_SUMISRT_LAST;
	else
    if (!memicmp(pc,"AFTer",3))
    	opt=PARM_SUMISRT_AFTER;
	else
    if (!memicmp(pc,"BEFore",3))
    	opt=PARM_SUMISRT_BEFORE;
	else
    if (!memicmp(pc,"IGNore",3))
    	opt=PARM_SUMISRT_IGNORE;
	else
    if (!memicmp(pc,"AVErage",3))
    	opt=PARM_SUMISRT_AVE;
	else
    if (!memicmp(pc,"MMX",3))
    	opt=PARM_SUMISRT_MM;
	else
    if (!memicmp(pc,"MINMAX",3))
    	opt=PARM_SUMISRT_MM;
	else
    if (!memicmp(pc,"MAXMIN",3))
    	opt=PARM_SUMISRT_MM;
	else
    if (!memicmp(pc,"AMM",3))
    	opt=PARM_SUMISRT_AVE|PARM_SUMISRT_MM;
	else
    if (!memicmp(pc,"INS",3))                                      //~v56zI~
    	opt=PARM_INS;                                              //~v56zI~
	else                                                           //~v56zI~
//  if (!memicmp(pc,"REP",3))                                      //~v56zR~
//  	opt=PARM_COPYREP;                                          //~v56zR~
//  else                                                           //~v56zR~
    if (!memicmp(pc,"COUNTEQ",7))                                  //~v587I~
    	opt=PARM_COUNTEQ;                                          //~v587I~
    else                                                           //~v587I~
    if (!memicmp(pc,"RJ",2))                                       //~v56zI~
    	opt=PARM_COPYRJUST;                                        //~v56zI~
	else                                                           //~v56zI~
    if (!memicmp(pc,"TF",2))                                       //~v62uI~
    	opt=PARM_TRUEFALSE;     //set 1 if equal,0 if unequal for ==(compare)//~v62uI~
	else                                                           //~v62uI~
    if (!memicmp(pc,"FT",2))                                       //~v62uI~
		opt=PARM_FALSETRUE;     //set 0 if equal,1 if unequal for ==(compare)//~v62uR~
	else                                                           //~v62uI~
    	return 4;
//  Pparm[PARM_OPTION]|=opt;                                       //~vb30R~
    Pparm[PARM_OPTION]|=(XECALCPARM)opt;                           //~vb30I~
    return 0;
}//tc_opdchk2
//****************************************************************
// chk conversion type
//*ret  :uppercase datatype
//****************************************************************
int tc_chkdatatype(int Pdatatype)
{
	int datatype;
//*********************
    datatype=toupper(Pdatatype);
    switch(datatype)
    {
    case 'O':
    case 'X':
    case 'T':
    case 'D':
    case 'Z':                                                      //~v474I~
    case 'U':       //unsigned                                     //~v51nI~
//  case 'Y':       //unsigned Z (UZ)                              //~v529R~
        break;
    default:
    	return 0;
    }
    return datatype;
}//tc_chkdatatype
#endif                                                             //~v52hR~
//****************************************************************
// set line rr
//*ret :1
//****************************************************************
int tc_setplherr(PULINEH Pplh)
{
    if (!S1sterr)                                                  //~v57HI~
    {                                                              //~v57HI~
    	S1sterr=1;                                                 //~v57HI~
        Glcmd4errctr++;	//set to plh by lcmdshifterr               //~v57HR~
    }                                                              //~v57HI~
	lcmdshifterr(Pplh,0,0);//no exclude line highlight,no output 1st err line
    return 1;
}//tc_setplherr(PULINEH Pplh)
#ifndef DOSDOS                                                     //~v52hR~
//**************************************************
//*doble long calc
//* for *,/,%  opd2 is single
//* ret :rc     1:for comapre err
//**************************************************
//int tc_calc(int Ptimeconvopt,int Pdatatype,int Pope,long *Popd1,long *Popd2)//~vafkR~
int tc_calc(int Ptimeconvopt,int Pdatatype,int Pope,SLPTR *Popd1,SLPTR *Popd2)//~vafkR~
{
	int opt;
    int len,len1,len2,rc;                                          //~v497I~
    int ajustopt;                                                  //~v62vR~
#ifdef UTF8UCS2                                                    //~va20R~
    char *pdbcs1,*pdbcs2;                                          //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************
//  handle=Sparm[PARM_EBC_HANDLE];                                 //~vaz8R~
    handle=(int)Sparm[PARM_EBC_HANDLE];                            //~vaz8I~
    if (Pdatatype==CALC_STRINGDATA)//string compare                //~v497I~
    {                                                              //~v497I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	swebcfile=(Sparm[PARM_OPTION] & PARM_EBCFILE);	//implicit parm//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        len1=(int)Popd1[2];                                        //~v497I~
        len2=(int)Popd2[2];                                        //~v497I~
        len=min(len1,len2);                                        //~v497I~
#ifdef UTF8UCS2                                                    //~va20R~
      	pdbcs1=(char*)Popd1[TC_PDBCS];                             //~va20R~
      	pdbcs2=(char*)Popd2[TC_PDBCS];                             //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      rc=XESUB_memcmp_ebcdd(swebcfile,(pdbcs1 && pdbcs2)/*utf8 file*/,XESUBDDSCO_HIGHLOW,(char*)Popd1[0],pdbcs1,(char*)Popd2[0],pdbcs2,len);//~va50I~//~va79R~
        rc=XESUB_memcmp_ebcdd(swebcfile,(pdbcs1 && pdbcs2)/*utf8 file*/,handle,XESUBDDSCO_HIGHLOW,(char*)Popd1[0],pdbcs1,(char*)Popd2[0],pdbcs2,len);//~va79I~
    #else                                                          //~va50I~
        rc=XESUB_DDMEMCMP((pdbcs1 && pdbcs2)/*utf8 file*/,XESUBDDSCO_HIGHLOW,(char*)Popd1[0],pdbcs1,(char*)Popd2[0],pdbcs2,len);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        rc=memcmp((void*)Popd1[0],(void*)Popd2[0],(UINT)len);      //~v497R~
#endif                                                             //~va20M~
        if (!rc)                                                   //~v497I~
        {                                                          //~v533I~
        	if (len<len1)                                          //~v497I~
            	rc=1;                                              //~v497I~
            else                                                   //~v497I~
        	if (len<len2)                                          //~v497I~
            	rc=-1;                                             //~v497I~
        }                                                          //~v533I~
        return rc;                                                 //~v497I~
    }                                                              //~v497I~
    if (Ptimeconvopt||Pdatatype=='T')
    {                                                              //~v62vI~
        if (Pope=='/')                                             //~v62vI~
        {                                                          //~v62vI~
            if (Sparm[PARM_OPTION] & PARM_ROUND)                   //~v62vI~
                Ptimeconvopt|=CALC_TIME_DIVPREC;   //round up      //~v62vR~
            if (Sparm[PARM_OPTION] & PARM_VPREC     //vnn parm     //~v62vR~
            &&  Sparm[PARM_PRECNO])//input opd precision change    //~v62vI~
            {                                                      //~v62vI~
                ajustopt=0;     //no prec_down, no round           //~v62vI~
//              ucalc_vrajust(ajustopt,Popd1,Sparm[PARM_PRECNO]);//input opd precision change//~vaz8R~
                ucalc_vrajust(ajustopt,Popd1,(int)Sparm[PARM_PRECNO]);//input opd precision change//~vaz8I~
            }                                                      //~v62vI~
        }                                                          //~v62vI~
        return ucalc_time(CALC_TIME_SETSIGN|Ptimeconvopt,Pope,Popd1,Popd2);//~v17iR~
    }                                                              //~v62vI~
//  if (Pdatatype=='D'                                             //~v57JR~
//  ||  Pdatatype=='Z')                                            //~v57JR~
//      opt=CALC_SIGNED;                                           //~v57JR~
//  else                                                           //~v57JR~
        opt=0;
    if (Pope==CALC_COMP)                                           //~v497I~
    	Pope='?';                                                  //~v497I~
//  return ucalc_binop(opt,Pope,Popd1,Popd2);                      //~v57CR~
//  if (Pope=='*' && !Popd1[1] 	//word multiply                    //~v57YR~
//  &&  (Pdatatype=='D'||Pdatatype=='Z'))                          //~v57YR~
//  {                                                              //~v57YR~
//  	Popd1[2]=Popd1[0];                                         //~v57YR~
//  	Popd1[1]=UCALC_DWORDID;                                    //~v57YR~
//  	Popd1[0]=0;                                                //~v57YR~
//  }                                                              //~v57YR~
    opt|=CALC_DWORDUP;	//allow overflow to dword                  //~v57YI~
    if (Pope=='/')                                                 //~v62vI~
    {                                                              //~v62vI~
    	if (Sparm[PARM_OPTION] & PARM_ROUND)                       //~v62vR~
		    opt|=CALC_DIV_PRECUP;	//round value                  //~v62vI~
    	if (Sparm[PARM_OPTION] & PARM_VPREC 	//vnn parm         //~v62vR~
		&&  Sparm[PARM_PRECNO])//input opd precision change        //~v62vI~
        {                                                          //~v62vI~
        	ajustopt=0;		//no prec_down, no round               //~v62vI~
//  		ucalc_vrajust(ajustopt,Popd1,Sparm[PARM_PRECNO]);//input opd precision change//~vaz8R~
    		ucalc_vrajust(ajustopt,Popd1,(int)Sparm[PARM_PRECNO]);//input opd precision change//~vaz8I~
        }                                                          //~v62vI~
    }                                                              //~v62vI~
	rc=ucalc_binop(opt,Pope,Popd1,Popd2);                          //~v57CI~
    return rc;                                                     //~v57CI~
}//tc_calc
//**************************************************               //~va50I~
//*rc   :4                                                         //~va50I~
//**************************************************               //~va50I~
//int	calc_m2bconststr(int Popt,int *Pparm,long *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz)//~va5bR~//~va70R~
//int	calc_m2bconststr(int Popt,XECALCPARM *Pparm,long *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz)//~va70I~//~vafkR~
int	calc_m2bconststr(int Popt,XECALCPARM *Pparm,SLPTR *Plvts,UCHAR *Pebc,UCHAR *Pdbcs,int Pbuffsz)//~vafkI~
{                                                                  //~va50I~
	int ebclen,len,rc2,opt;                                        //~va50I~
    UCHAR *pebc,*pdbcs,*pstr;                                      //~va50I~
    int handle;                                                    //~va79I~
//******************                                               //~va50I~
    opt=0;                                                         //~va50I~
    pstr=(UCHAR*)Plvts[0];                                         //~va50R~
//  len=Plvts[2];                                                  //~vaz8R~
    len=(int)Plvts[2];                                             //~vaz8I~
//  handle=Sparm[PARM_EBC_HANDLE];                                 //~vaz8R~
	handle=(int)Sparm[PARM_EBC_HANDLE];                            //~vaz8I~
  if (Pparm[PARM_OPTION] & PARM_EBCFILE) //ebcfile                 //~va5bR~
  {                                                                //~va5bI~
  	opt=XEEBCO_SOSICMDI;	//insert SOSI                          //~va7cR~
//  rc2=xeebc_m2bsetdbcs(opt,pstr,0/*dbcs*/,len,&pebc,&pdbcs,&ebclen);//~va50I~//~va79R~
    rc2=xeebc_m2bsetdbcs(opt,handle,pstr,0/*dbcs*/,len,&pebc,&pdbcs,&ebclen);//~va79I~
    UALLOCCHKRC(rc2);                                              //~va50I~
    if (ebclen>Pbuffsz)                                            //~va50I~
    	return 8;                                                  //~va50I~
    memcpy(Pebc,pebc,(UINT)ebclen);                                //~va50I~
    memcpy(Pdbcs,pdbcs,(UINT)ebclen);                              //~va50I~
  }                                                                //~va5bI~
  else                                                             //~va5bI~
  if (Pparm[PARM_OPTION] & PARM_UTF8FILE) //ebcfile                //~va5bI~
  {                                                                //~va5bI~
  	rc2=xeutfgetddstr(opt,pstr,len,Pebc,Pbuffsz,&ebclen,Pdbcs);    //~va5bI~
    UALLOCCHKRC(rc2);                                              //~va5bI~
  }                                                                //~va5bI~
  else                                                             //~va5bI~
  	return 4;                                                      //~va5bI~
//  Plvts[0]=(LONG)Pebc;                                           //~va50R~//~vafkR~
    Plvts[0]=(SLPTR)Pebc;                                          //~vafkI~
    Plvts[2]=ebclen;                                               //~va50I~
//  Plvts[TC_PDBCS]=(LONG)Pdbcs;                                   //~va50R~//~vafkR~
    Plvts[TC_PDBCS]=(SLPTR)Pdbcs;                                  //~vafkI~
    return 0;	//translated                                       //~va50I~
}//calc_m2bconststr                                                //~va50I~
//**************************************************
//*rc   :4
//**************************************************
int  tcerrdatawidth(void)
{
	uerrmsg("Too large data width(>%d)",
		    "長すぎるデータ(>%d)",
            MAX_DATA_WIDTH);
	return 4;
}//tcerrdatawidth
//****************************************************************
// no valid record err msg
//*rc   :4
//****************************************************************
int tcerrnorec(long Precno,long Pdataerrno,long Pkeyerrno)
{
    uerrmsg("No valid record in total %ld lines;er=%ld,keyer=%ld.",0,
    			Precno,Pdataerrno,Pkeyerrno);
	return 4;
}//tcerrnorec
//**************************************************************** //~v58wI~
int tcerrinvalidforcount(void)                                     //~v58wR~
{                                                                  //~v58wI~
	uerrmsg("for ~(count alive record),use no datatype(string compare) or 'T'(timestamp).",//~v58wI~
		    "~(存続カウント)操作のデータタイプは'T'(時刻)か指定無(文字列比較)のみ。");//~v58wI~
	return 4;                                                      //~v58wI~
}//tcerrinvalidfotcount                                            //~v58wI~
//**************************************************************** //~v168I~
// 1st help                                                        //~v168I~
//*rc   :4                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_help0(void)                                                 //~v168I~
{                                                                  //~v168I~
    uerrmsg("TC ? { 1 | SUM | 2 | 3 | FMT | FLD}",0);              //~v42oR~
    return 0;                                                      //~v168I~
}//tc_help0                                                        //~v168I~
//**************************************************************** //~v168I~
// help for 1 opd                                                  //~v168I~
//*rc   :4                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_help1(void)                                                 //~v168I~
{                                                                  //~v168I~
//  uerrmsg("TC fld{ ++ | -- | = } [NX] [Zero] [.lab1 .lab2]",0);  //~v51mR~
//  uerrmsg("TC fld{ ++ | -- | = | /datatype} [NX] [Zero] [.lab1 .lab2]",0);//~v58vR~
    uerrmsg("TC fld{ ++ | -- | = | /datatype} [NX] [Zero] [V[n][R]] [.lab1 .lab2]",0);//~v58vI~
    return 0;                                                      //~v168I~
}//tc_help1                                                        //~v168R~
//**************************************************************** //~v168I~
// help for 1 opd                                                  //~v168I~
//*rc   :4                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_helpsum(void)                                               //~v168I~
{                                                                  //~v168I~
//  uerrmsg("TC [fld]+[{/key[/grade] | //cnt}] [bef|aft|top|end|ign|amm|ave|max|NX] [Zero] [.lab1 .lab2]",0);//~v53DR~
//  uerrmsg("TC [fld]+[{/key[>|!|<][/grade] | //cnt}] [bef|aft|top|end|ign|amm|ave|max|NX] [Zero] [.lab1 .lab2]",0);//~v58vR~
//  uerrmsg("TC [fld]+[{/key[>|!|<][/grade] | //cnt}] [bef|aft|top|end|ign|amm|ave|max|NX] [Zero] [V[n][R]] [.lab1 .lab2]",0);//~v58zR~
    uerrmsg("TC [fld]+[{/key[>|!|<][/grade] | //cnt}] [bef|aft|top|end|ign|amm|ave|max|NX] [Zero] [V[n][R]] [-Ofilename] [.lab1 .lab2]",0);//~v58zR~
    return 0;                                                      //~v168I~
}//tc_helpsum                                                      //~v168R~
//**************************************************************** //~v168I~
// help for 2 opd                                                  //~v168R~
//*rc   :4                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_help2(void)                                                 //~v168I~
{                                                                  //~v168I~
//  uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=}[fld2] [NX] [Zero] [.lab1 .lab2]",0);//~v52kR~
//  uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=|==}[fld2] [NX] [Zero] [.lab1 .lab2]",0);//~v535R~
//  uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=|~=|==}[fld2] [NX] [Zero] [.lab1 .lab2]",0);//~v56zR~
//  uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=|~=|==|=}[fld2] [NX] [Zero] [INS] [RJ] [.lab1 .lab2]",0);//~v587R~
//  uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=|~=|==|=}[fld2] [NX] [Zero] [INS] [RJ] [CountEQ] [.lab1 .lab2]",0);//~v58vR~
    uerrmsg("TC [fld1]{+=|-=|*=|/=|%%=|~=|==|=}[fld2] [NX] [Zero] [V[n][R]] [INS] [RJ] [CountEQ] [.lab1 .lab2]",0);//~v58vI~
    return 0;                                                      //~v168I~
}//tc_help2                                                        //~v168R~
//**************************************************************** //~v168I~
// help for 3 opd                                                  //~v168I~
//*rc   :4                                                         //~v168I~
//**************************************************************** //~v168I~
int tc_help3(void)                                                 //~v168I~
{                                                                  //~v168I~
//  uerrmsg("TC fld3=fld1{+|-|*|/|%%}f2 [NX] [Zero] [.lab1 .lab2]",0);//~v535R~
//  uerrmsg("TC fld3=fld1{+|-|*|/|%%|~}fld2 [NX] [Zero] [.lab1 .lab2]",0);//~v56zR~
//  uerrmsg("TC fld3=fld1{+|-|*|/|%%|~}fld2 [NX] [Zero] [INS] [.lab1 .lab2]",0);//~v587R~
//  uerrmsg("TC fld3=fld1{+|-|*|/|%%|~}fld2 [NX] [Zero] [INS] [CountEQ] [.lab1 .lab2]",0);//~v58vR~
//  uerrmsg("TC fld3=fld1{+|-|*|/|%%|~}fld2 [NX] [Zero] [V[n][R]] [INS] [CountEQ] [.lab1 .lab2]",0);//~v62uR~
    uerrmsg("TC fld3=fld1{+|-|*|/|%%|~}fld2 [NX] [TF|FT] [Zero] [V[n][R]] [INS] [CountEQ] [.lab1 .lab2]",0);//~v62uI~
    return 0;                                                      //~v168I~
}//tc_help3                                                        //~v168I~
//**************************************************************** //~v42oI~
// help for field                                                  //~v42oI~
//*rc   :4                                                         //~v42oI~
//**************************************************************** //~v42oI~
int tc_helpf(void)                                                 //~v42oI~
{                                                                  //~v42oI~
//  uerrmsg("\"[type]col1-col2\" or \"[type]:fldno\" as fldno:0-9,a-z",0);//~v56zR~
//  uerrmsg("[type]col1-col2 | \"[type]:fldno\" as fldno:0-9,a-z | =@cont-string | =@ \"const string\"",0);//~v59jR~
//  uerrmsg("[type]col1-col2 | \"[type]:fldno\" as fldno:0-9,a-z | \"const string\"",0);//~v62zR~
    uerrmsg("[type]col1-col2 | \"[type]:fldno\" as fldno:1-99 | \"const string\"",0);//~v62zI~
    return 0;                                                      //~v42oI~
}//tc_helpf                                                        //~v42oI~
#endif                                                             //~v50EI~
