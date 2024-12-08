//CID://+vag4R~: update#=   59;                                    //+vag4R~
//*************************************************************
//*xelcmd3.c*
//* line cmd copy/move                                          //~5114R~
//*************************************************************
//vag4:120814 (BUG)UFHF2SPFNUMERR flag is cleared by undo for the file contains another errline//+vag4I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7B:100829 avoid warning msg "COPYOFF" for ::cb                 //~va7BI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            lcmd3.c :translation when linecopy                   //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va14:091023_(BUG)f2lerr at 1st line of copy cpu8 file into, miss set end of line draw flag//~va14I~
//va07:090628 add copy cid option to Copy lcmd(AI/BI)              //~va07I~
//va02:090525 CID copyon/copyoff(lcmd copy CID option)             //~va02I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//v79q:080901 (BUG)CMDECHO flag should be cleared (line copy)      //~v79qI~
//v794:080722 (VC8)valiable initiated chk                          //~v794I~
//            lcmd3.c : no actual effect(cunter up but not used later)//~v794I~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v74J:070325*(BUG of v74E)block paste limited by bnds setting     //~v74JI~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v681:060301 (BUG)default s=0(it should be s=1) for copy/move target when b!=0//~v681I~
//v67W:060227 copy p/o.n:offset allow when cursor is on 2nd destination line//~v67WI~
//v67U:060226 (BUG)paste line cmd;pp-pp,b.s type,last remaining bandle count err when wrap source//~v67UI~
//v67S:060226 (BUG)paste line cmd;pp-pp,b.s type ignore ,b.s count //~v67SI~
//v67R:060226 (BUG)paste line cmd;pn.s type ignore s count         //~v67RI~
//v67Q:060225 (BUG)paste line cmd;pn type dose not stop at input eof//~v67QI~
//v67P:060225 (BUG)paste line cmd ABEND when destination line reached to eof//~v67PI~
//v58s:040923 niche option for copy edit cmd(n:override target line by not space char of src line)//~v58sI~
//v530:030912 (BUG)malloc err not chked(DRO,X etc cmd abended)     //~v530I~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v113:990612 (BUG)copy file after cmd abend when into spf file(not yet pfh set before enq)//~v113I~
//                 from v1.02                                      //~v113I~
//v10H:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v10HI~
//v0iq:980702 (BUG)spf flag reset bug at ulhcopyno; effect?        //~v0iqI~
//v0ip:980702 (BUG of v0i9:bandle/skip support)                    //~v0ipI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0ib:980530 v0i9 cotinued for other tjan file copy               //~v0ibI~
//v0i9:980526 lcmd bandle/skip support for pair cmd("C","M","A","B","P","P")//~v0h9I~
//            copy file An,l.m  : n times (l,m) pair               //~v0i9I~
//            copy file An,0.m  : n times (full line,m) pair       //~v0i9I~
//            copy file A,l.m  : (l,m) pair until eof              //~v0i9I~
//v0hO:980426 (BUG of v0hA) copy inter 2 file may reject by line overlap//~v0hOI~
//v0hL:980419 (BUG) of v0hs:if copy file not found,errmsg is override by as "null file"//~v0hLI~
//v0hB:980418 (BUG)of v0hB.a+c faile.dest shoud chk between start and stop//~v0hBI~
//v0hA:980413 (BUG)copy lcmd loop when dest is included in Cn range//~v0hAI~
//            chk and err return if dest is contained range for copy/move//~v0hAI~
//v0hs:980410 err msg when null file copy into                     //~v0hsI~
//v0ho:980221 range support for on/pase pos cmd                    //~v0hoI~
//v0hf:980130 performance tuning                                   //~v0hfI~
//            draw only after deleted/inserted/exclude/include/copy/rep line//~v0hfI~
//v0eI:970927 margin and copy on/paste                             //~v0eII~
//            for SPFERR/SPFOK file;oom update prohibit            //~v0eII~
//            for mergined file;avail over mergin line if not protected//~v0eII~
//v0eo:970920 tab expand and clear when copy into spf file         //~v0eoI~
//            if expanded at display,overflow to num fld.but not invalid spf line.//~v0eoI~
//v0ef:970915 return copylen not contlen for new reclen;           //~v0efI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0dl:970831 (BUG) of v0dg;for rep/cre cmd dest ulh is dummy,has no pfh//~v0dlI~
//v0di:970907 undo unit for EEOL,ETOL,CTOL                         //~v0diI~
//v0dg:970831 chk valid spf record for nomal copy                  //~v0dgI~
//v0df:970831 (BUG)cid not set if cont exist.(see also v0d3)       //~v0dfI~
//v0d9:970831 valid if ulhlen<mergin for file copy into            //~v0d9I~
//v0d8:970831 allow err line copy into spf file                    //~v0d8I~
//v0d2:970818 cut long line by mergin if copy file into spf file   //~v0d2I~
//v0d1:970818 (BUG)copy ON/PASTE position if csr is on lineno-fld and UFCleft!=0//~v0d1I~
//v0ch:970810 line-copy copy full line except cid regardless mergin//~v0chI~
//v0bk:970727 copy out from splitline is also split if multiple    //~v0bkI~
//            (reverse v0bc)                                       //~v0bkI~
//v0bg:970727 mergin err notify to cap to protect err msg override //~v0bgI~
//v0bc:970726 (BUG)a line copy from aplit lines remain split line attr//~v0bcI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//v0az:970720 errline reverse display                              //~v0azI~
//v0ar:970719 (BUG)lcmd Dn on end of file line cause abend,also Cn on end//~v0arI~
//v0a8:970706:allow cmd input line copy(lineno atrr and last is input)//~v0a8I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06P:960427:(BUG)of v06M,line split also caused hi-litened       //~v06NI~
//            called from xechar2 'B'(before) option,clear flag at init.//~v06NI~
//v06N:960424:(BUG)DOS /Os(storage optimize) bug for max(0,int-UCHAR)//~v06NI~
//v06M:960424:hi-lighten insert line by cut and paste              //~v06MI~
//v06u:960406:cmd so screen:lineno color for input cmd echo line      //~v06uI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~v057I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v019:950702:cid cut by source file cid attribute not but dest file//~v019I~
//************************************************************* //~v019I~
//950315 protect copy file On/Paste(because pfh not created)    //~5315R~
//950114 bug when other client UFCcurtop deleted by MOVE(scr not creared)//~5315I~
//************************************************************* //~5114I~
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <utrace.h>                                                //~v06MI~
#include <uedit.h>                                                 //~v0d2I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"                                              //~5213I~
#include "xecsr.h"                                              //~5213M~
#include "xefile.h"
#include "xefile12.h"                                              //~v0d2I~
#include "xefile2.h"
#include "xefile4.h"                                            //~v019I~
#include "xefile6.h"                                               //~v0eoI~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd3.h"
#include "xelcmd4.h"		//lcmdshifterr                         //~v0avI~
#include "xefcmd.h"
#include "xeundo.h"
#include "xechar.h"                                                //~v0avI~
#include "xechar2.h"                                            //~5211I~
#include "xefsub.h"                                                //~v0hoI~
#include "xeerr.h"                                                 //~v417I~
#include "xesyn.h"                                                 //~v780I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xeopt.h"                                                 //~va02I~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub.h"                                                 //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
//*******************************************************
static int Smovesw;                                             //~5131I~
static int Sbandle1,Sbandle2,Sskip2,Sskip1,Sbssw1,Sbssw2,Srepeat2; //~v0i9R~
//*******************************************************          //~v0avI~
int lcmdmove(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc);
PULINEH linecopy(PULINEH Pplh,PULINEH Pplhdest,long Plineno);   //~5211I~
PULINEH ulhcopy(PULINEH Pplh);
int lcmdover(PUCLIENTWE Ppcw,int Popid,PULINEH Pplh,PULINEH *Ppplhdest,int Poffs);//~5211I~
int lcmdeolerr(void);                                              //~v0i9I~
void lcmdclearselected(PULINEH Pplh1,PULINEH Pplh2);               //~v0ibI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int lcmdcvddandl(int Popt,PUFILEH Ppfh,PULINEH Pplh,PUFILEH Ppfhs,PULINEH Pplhs,int *Ppcidchksw);//~va50R~
#else                                                              //~va50I~
int lcmdcvddandl(int Popt,PUFILEH Ppfh,PULINEH Pplh);              //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#define       LCCVO_SRCU8   0x01	//copy source is utf8 file     //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define       LCCVO_SRCEBC  0x02	//copy source is utf8 file     //~va50I~
#define       LCCVO_COPYCID 0x04	//copy source CID              //~va50I~
#define       LCCVO_BIN     0x08	//copy w/o translation         //~va7xI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20I~
//****************************************************************
// paircmd
// process pair cmd(copy/move) 
//*rc   :0
//****************************************************************
int lcmdpair(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd)
{
	PUCLIENTWE pcw;                                             //~5114R~
	ULCMD   *plcr;                                              //~5114I~
	ULCMD   *plcdr;                                                //~v67SI~
	PULINEH plh1,plh2;
	int repeat,rc=0;                                               //~vaf9R~
//*******************
//repeat
    Sbssw1=0;   	//no bandle/skip used                          //~v0i9R~
    Sbssw2=0;                                                      //~v0i9R~
	plcr=Pplcc->ULCplcrange;	//range pair
	if (plcr)
	{
		plh2=Pplcc->ULCplh;
		plh1=plcr->ULCplh;
		Sbandle1=max(Pplcc->ULCband,plcr->ULCband);                //~v0i9R~
		Sskip1  =max(Pplcc->ULCskip,plcr->ULCskip);                //~v0i9R~
	}
	else
	{
		plcr=Pplcc;
		plh1=plh2=Pplcc->ULCplh;
		Sbandle1=Pplcc->ULCband;                                   //~v0i9R~
		Sskip1  =Pplcc->ULCskip;                                   //~v0i9R~
	}
    if (Sskip1 || Sbandle1)                                        //~v0i9R~
    {                                                              //~v0i9R~
    	Sbssw1=1;                                                  //~v0i9R~
		if (!Sbandle1)                                             //~v0i9R~
        	Sbandle1=1;		//default for source                   //~v0i9R~
		if (!Sskip1)                                               //~v0i9R~
        	Sskip1=1;     	//default for source                   //~v0i9R~
	}                                                              //~v0i9R~
	Sbandle2=Pplcd->ULCband;                                       //~v0i9R~
	Sskip2  =Pplcd->ULCskip;                                       //~v0i9R~
	Srepeat2=Pplcd->ULCrepeat;                                     //~v0i9I~
	plcdr=Pplcd->ULCplcrange;	//range pair of target             //~v67SI~
	if (plcdr)				//target range pair contains n,b,s     //~v67SI~
	{                                                              //~v67SI~
    	if (Sbandle2<plcdr->ULCband)                               //~v67SI~
			Sbandle2=plcdr->ULCband;                               //~v67SI~
    	if (Sskip2  <plcdr->ULCskip)                               //~v67SR~
			Sskip2  =plcdr->ULCskip;                               //~v67SI~
    	if (Srepeat2<plcdr->ULCrepeat)                             //~v67SR~
			Srepeat2=plcdr->ULCrepeat;                             //~v67SI~
    }                                                              //~v67SI~
    if (!Srepeat2)                                                 //~v0i9I~
		Pplcd->ULCrepeat=1;		//moved from lcmd,set after get 0 value//~v0i9I~
                                                                   //~v0i9I~
    if (Sbandle1 || Sbandle2 || Sskip2)                            //~v0i9R~
    {                                                              //~v58sI~
        if (plcr)                                                  //~v0i9R~
            uerrmsg("%c%c,%d.%d - %c%d,%d.%d",0,                   //~v0i9R~
                Pplcc->ULCcmd,                                     //~v0i9R~
                Pplcc->ULCcmd,                                     //~v0i9R~
                Sbandle1,Sskip1,                                   //~v0i9R~
                Pplcd->ULCcmd,                                     //~v0i9R~
                Srepeat2,                                          //~v0i9R~
                Sbandle2,Sskip2);                                  //~v0i9R~
        else                                                       //~v0i9R~
            uerrmsg("%c%d,%d.%d",0,                                //~v0i9R~
                Pplcc->ULCcmd,                                     //~v0i9R~
                Pplcc->ULCrepeat,                                  //~v0i9R~
                Sbandle1,Sskip1);                                  //~v10HR~
    }//                                                            //~v58sI~
    if (Sbandle2 || Sskip2)                                        //~v0i9R~
    {                                                              //~v0i9R~
    	if (Sbandle2)	//it can be 0                              //~v0ibR~
	    	Sbssw2=1;                                              //~v0i9R~
        else                                                       //~v0i9I~
	    	Sbssw2=2;                                              //~v0i9I~
//      if (!Sskip1)                                               //~v681R~
//      	Sskip1=1;     	//default for target                   //~v681R~
        if (!Sskip2)                                               //~v681I~
        	Sskip2=1;     	//default for target                   //~v681I~
	}                                                              //~v0i9R~
	if (!(repeat=Pplcc->ULCrepeat))	//range count.
		repeat=1;
	switch(Pplcc->ULCcmd)
	{
	case 'C':
		rc=lcmdcopy(Ppcw,plh1,plh2,repeat,Pplcd);
		break;
	case 'M':
        pcw=scrgetcw(Pplcc->ULCsplitid+1);   //pcw of M cmd     //~5114I~
		rc=lcmdmove(pcw,plh1,plh2,repeat,Pplcd);                //~5114R~
		break;
	}//switch by cmd
    Sbssw1=0;   	//clear for direct call to lcmdcopy            //~v0ibI~
    Sbssw2=0;                                                      //~v0ibI~
	return rc;
}//lcmdpair
//****************************************************************
// lcmdmove
// process pair cmd(copy/move) 
//*rc   :0
//****************************************************************
int lcmdmove(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc)
{
	int rc;
//*************************
    Smovesw=1;  //parm for renumsuffix                          //~5131I~
	rc=lcmdcopy(Ppcw,Pplh1,Pplh2,Prepeat,Pplc);                 //~5131R~
    Smovesw=0;  //for renumsuffix                               //~5131I~
	if (rc)                                                     //~5131I~
		return rc;
    if (Sbssw1)                                                    //~v0ibI~
	    rc=lcmddelbs(Ppcw,Pplh1,Pplh2,Prepeat,Sbandle1,Sskip1);    //~v0ibI~
    else                                                           //~v0ibI~
	    rc=lcmddel(Ppcw,Pplh1,Pplh2,Prepeat,0,0);                  //~v0ibR~
					//bypass set csr,enterd from lcmd main      //~v057I~
	return rc;                                                     //~v0ibI~
}//lcmdmove
                                                                //~5126I~
//****************************************************************
// lcmdcopy
// process copy cmd(called from move and repeat)
//  parm1:PUCLIENTWE
//  parm2:range1 PULINEH
//  parm3:range2 PULINEH
//  parm4:range count
//  parm5:destination ULCMD
//*rc   :0
//****************************************************************
int lcmdcopy(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc)
{
	PUFILEH pfh;                                                //~v019I~
	PUFILEH pfhd=0;                                                //~vaf9R~
    PULINEH plhe=0;                                                //~v0d8I~
    PULINEH plhbandprev=0,plhbandnext=0;                               //~v0i9I~//~vaf9R~
    PULINEH plhdeststop=0;  //for ranged ON/PASTE stopper          //~v0hoI~
    PULINEH plhdeststoporg=0;  //for csr pos chk                   //~v67WI~
//  PULINEH plh,plhdest,plhfirst,plhnext,plhstop,plh1=0,plh2;      //~vaf8R~
//  PULINEH plh,plhdest=0,plhfirst,plhnext,plhstop,plh1=0,plh2;    //~vaf9R~
    PULINEH plh,plhdest=0,plhfirst=0,plhnext=0,plhstop,plh1=0,plh2=0;//~vaf9R~
    ULCMD *plc;                                                    //~v0hoI~
    int destbreaksw=0;  //reached to dest range for ranged ON/PASTE//~v0hoI~
	int  ii,excludesw,repeat,rc=0,copyctr=0,copyfilesw;           //~5226R~//~vaf9R~
//  int opid,overoffs,overopid,insbycapsw=0;                       //~vaf9R~
    int opid,overoffs=0,overopid=0,insbycapsw=0;                   //~vaf9I~
	long lineno=0;                                                 //~vaf9R~
//  int copyctr2;                                                  //~v794R~
    int copyctr2=0;                                                //~v794I~
    int spfsw2=0;                                                    //~v0eoI~//~vaf9R~
//    int merginerrsw=0,mergin;                                    //~vaf9R~
      int merginerrsw=0,mergin=0;                                  //~vaf9I~
    int cidlen,topcidpos=0,lastcidpos,copylen;                       //~v0efR~//~vaf9R~
    int bandle;                                                    //~v0i9I~
    int bandle1;                                                   //~v0ibR~
    int skip;                                                      //~v0ibI~
    int rangepastesw=0;                                            //~v67QI~
    int errmergin=0;                                                 //~v74EI~//~vaf9R~
    int lcmdoverlcmdid=CHAROPLCMD;                                 //~v74JI~
#ifdef UTF8SUPPH                                                   //~va00I~//~va1qM~
static int Soptopt2=-1;                                            //~va02I~
	int optopt2;                                                   //~va02I~
	int filereadctr=0;                                             //~va00I~
	int f2lerrsw=0;                                                //~va14I~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
    int rc2,cverrctr=0,optcvddandl=0;                              //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int cidchksw;                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    int swbinmode,optcvf2l;                                        //~va7xR~
//****************
//*get destination line
    UCBITOFF(Pplc->ULCflag2,ULCF2MERGINERR);	//once reset       //~v0bgI~
    swbinmode=UCBITCHK(Pplc->ULCflag3,ULCF3BIN);	//binmode copy //~va7xI~
	plh=Pplc->ULCplh;			//destination(after/before/on)
    plc=Pplc->ULCplcrange; //range pair of dest                    //~v0hoI~
    if (plc                                                        //~v0hoR~
	&&  (plc->ULCcmd=='O'                                          //~v0hoR~
	   ||plc->ULCcmd==ULCCMDNICHE //rep by source non-space        //~v58sI~
	   ||plc->ULCcmd=='P')                                         //~v0hoI~
       )                                                           //~v0hoI~
    {                                                              //~v0hoI~
        rangepastesw=1;                                            //~v67QI~
        plhdeststop=plh;                                           //~v0hoI~
        plhdeststoporg=plh;                                        //~v67WI~
        plh=plc->ULCplh;    //input plc is last half of pair       //~v0hoI~
        plhdeststop=getdisplayline(plhdeststop,1,0);//next line    //~v0hoR~
        if (!plhdeststop)                                          //~v0hoI~
        {                                                          //~v0hoI~
            pfh=UGETPFH(plh);          //dest pfh                  //~v0hoI~
        	plhdeststop=UGETQEND(&pfh->UFHlineque);                //~v0hoI~
		}                                                          //~v0hoI~
    }                                                              //~v0hoI~
	repeat=Pplc->ULCrepeat;		//repeat on destination
	if (opid=(plh->ULHtype==ULHTDMYLCMD),opid)    //repl/creat cmd//~5211R~
		plh1=0;	//strat plh first sw                            //~5129I~
    else        //normal line  cmd                              //~5129I~
    {                                                           //~5129I~
		if (plh->ULHtype==ULHTEXCLUDE                           //~5129R~
		&&  (Pplc->ULCcmd=='A'||  Pplc->ULCcmd=='R'))           //~5226R~
		{						//After ON X line               //~5129R~
			for (;;)                                            //~5129R~
			{                                                   //~5129R~
				if (!(plh=UGETQNEXT(plh)))                      //~5129R~
					break;                                      //~5129R~
				if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~5129R~
					break;                                      //~5129R~
				plhdest=plh;                                    //~5211R~
			}                                                   //~5129R~
		}                                                       //~5129R~
		else	//not after on X                                //~5129R~
		{                                                       //~5129R~
			switch(Pplc->ULCcmd)                                //~5211R~
			{                                                   //~5211I~
			case 'B':	//before                                //~5211I~
				if (!(plhdest=UGETQPREV(plh)))                  //~5211R~
					plhdest=plh;                                //~5211R~
				break;                                          //~5211R~
			case 'O':       //copy on                           //~5211R~
			case 'P': 		//paste                             //~5211I~
			case ULCCMDNICHE:	//niche                            //~v58sI~
				if (plh->ULHtype==ULHTHDR)                      //~5211M~
                {                                                  //~v0hoI~
                    plh=UGETQNEXT(plh);                            //~v0hoR~
                    if (!plh)       //last                         //~v0hoI~
					return 4;                                   //~5211M~
                }                                                  //~v0hoI~
                if (Ppcw->UCWrcsry<Ppcw->UCWmaxline             //~5213R~
//  			&&	(Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc==plh)//on the dest line//~v67WR~
    			&&	(  ((Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc==plh)//on the dest line//~v67WI~
    			     ||(plhdeststop!=0 && (Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc==plhdeststoporg)//on the dest line//~v67WI~
                    ))                                             //~v67WI~
                {                                                  //~v06NI~
					overoffs=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;     //~v06NR~
                    if (overoffs<0)                                //~v06NR~
                    	overoffs=0;                                //~v06NR~
                    else                                           //~v0d1I~
					overoffs+=((PUFILEC)Ppcw->UCWpfc)->UFCleft;    //~v06NR~
				}                                                  //~v06NI~
				else                                            //~5213I~
					overoffs=0;                                 //~5213I~
                    pfhd=UGETPFH(plh);          //dest pfh         //~v0bgI~
                    mergin=pfhd->UFHmergin;     //dest mergin      //~v0bgI~
                if (overoffs>=mergin)                              //~v0avI~
//                if (UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR)//spf file//~v417R~
//                ||  (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN)        //~v417R~
//                     && !UCBITCHK(pfhd->UFHflag3,UFHF3OOMNOPROT)))//prot mergin file//~v417I~
//              	return charmerginerr(mergin);                  //~v417I~
                  	if (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN)       //~v417R~
                  	&& !UCBITCHK(pfhd->UFHflag3,UFHF3OOMNOPROT))//prot mergin file//~v417R~
                		return errprotected();                     //~v417R~
//UTRACEI("lcmdcopy overoffs",overoffs);                           //~v06NR~
                                                                   //~v06MI~
				plhdest=plh;                                    //~5211M~
				opid=2;	//2:copy ON,3:PASTE                     //~5211R~
				if (Pplc->ULCcmd=='O')                          //~5211I~
					overopid=CHAROPON;                          //~5211I~
                else                                               //~v58sI~
				if (Pplc->ULCcmd==ULCCMDNICHE)                     //~v58sR~
					overopid=CHAROPNICHE;                          //~v58sI~
                else                                            //~5211I~
					if (UCBITCHK(Pplc->ULCflag2,ULCF2CAPREP))//from cap//~5219I~
                    {                                              //~v74JI~
						overopid=CHAROPBREP;                    //~5219I~
                        lcmdoverlcmdid=0;   //not lcmd but C&P (ignore bnds setting)//~v74JI~
                    }                                              //~v74JI~
					else                                        //~5219I~
						if (UCBITCHK(Pplc->ULCflag2,ULCF2CAPINS))//from cap//~5219I~
                        {                                          //~v74JI~
							overopid=CHAROPBINS;                //~5219I~
    	                    lcmdoverlcmdid=0;   //not lcmd but C&P (ignore bnds setting)//~v74JI~
                        }                                          //~v74JI~
						else				//cmd input         //~5219I~
                		    if (UCBITCHK(Gscrstatus,GSCRSINS))  //~5219R~
								overopid=CHAROPBINS;            //~5219R~
							else				                //~5219R~
								overopid=CHAROPBREP;            //~5219R~
				break;                                          //~5211M~
			default:        //'A' or 'R'                        //~5226R~
				insbycapsw=UCBITCHK(Pplc->ULCflag2,ULCF2CAPINS);   //~v06MI~
				if (!(plhdest=UGETQNEXT(plh)))                  //~5211R~
					plhdest=UGETQPREV(plh);                     //~5211R~
				else                                            //~5129R~
					plhdest=plh;                                //~5211R~
				break;                                          //~5211I~
			}//sw by dest cmd                                   //~5211R~
		}//not after X                                          //~5211R~
		plhfirst=plhdest;	//save for later renum              //~5211R~
		plhnext=UGETQNEXT(plhdest);		//for renum suffix      //~5211R~
		lineno=plhfirst->ULHlinenor;	//save for later renum  //~5129R~
    }   //normal lcmd                                           //~5129I~
//*copy after destination                                       //~5129I~
    copyfilesw=0;                                               //~5226I~
	if (Pplh1==Pplh2)		//count type                        //~5226I~
    {                                                              //~v58sI~
		if (Pplh1->ULHtype==ULHTDMYLCMD) //called from fcmdcopy //~5226I~
        {                                                       //~5315I~
			if (opid)	//reject on/paste                       //~5504R~
            {                                                   //~5504I~
				uerrmsg("not supported file copy On/Pase",      //~5504I~
						"ファイル複写はOn/Pasteできません");    //~5504I~
				return 4;                                       //~5315I~
            }                                                   //~5504I~
        	copyfilesw=1;                                       //~5226I~
		}                                                       //~5315I~
		else	//lcmd                                          //~5226I~
        {                                                          //~v0hAI~
          if (Sbssw1)   //source has bandle/skip                   //~v0ibI~
          {                                                        //~v0ibI~
	        if (lcmdgetplhrange(&Pplh1,&Pplh2,                     //~v0ibR~
					Prepeat*Sbandle1+(Prepeat-1)*Sskip1)==8)//search stopline with bandle/skip//~v0ibI~
            	return 4;                                          //~v0ibI~
          }                                                        //~v0ibI~
          else                                                     //~v0ibI~
	        if (lcmdgetplhrange(&Pplh1,&Pplh2,Prepeat)==8)         //~v0arR~
            	return 4;                                          //~v0arI~
		}                                                          //~v0hAI~
    }//plh1=plh2                                                   //~v58sI~
//*copy after destination                                       //~5226I~
    bandle=Sbandle2;    //initial;for wrap case,set only once      //~v67UI~
	for (ii=0;ii<repeat;ii++)                                   //~5226R~
	{
		if (copyfilesw) //called from fcmdcopy                  //~5226R~
		{                                                       //~5226R~
            pfhd=UGETPFH(plhdest);          //dest pfh             //~v0d2I~
            if (swbinmode)                                         //~va7xI~
            {                                                      //~va7xI~
                if (FILEUTF8MODE(pfhd))                            //~va7xR~
                {                                                  //~va7xI~
                    errnotsupported("Binary mode copy","into UTF8 file");//~va7xR~
                    return 4;                                      //~va7xR~
                }                                                  //~va7xI~
            }                                                      //~va7xI~
//          spfsw=UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK);//copy into spf file//~v417R~
            spfsw2=UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//copy into spf file//~v0eoI~
            mergin=pfhd->UFHmergin;                                //~v0d9R~
            bandle=Sbandle2;                                       //~v0i9I~
            if (Sbssw2==2)   //copy ntimes l line by skip m        //~v0i9I~
            {                                                      //~v0i9I~
                plhbandprev=plhdest;                               //~v0i9I~
                plhbandnext=getdisplayline(plhdest,1,0);           //~v0i9I~
                copyctr2=0;                                        //~v0i9I~
            }                                                      //~v0i9I~
			for (Prepeat=0;;Prepeat++)		//until eof         //~5226R~
			{                                                   //~5226R~
                if (Sbssw2==1)       //copy ntimes l line by skip m//~v0i9I~
                    if (bandle==Sbandle2)	//1st dest             //~v0i9R~
                    {                                              //~v0i9I~
                    	plhbandprev=plhdest;                       //~v0i9I~
                    	plhbandnext=getdisplayline(plhdest,1,0);   //~v0i9I~
                    }                                              //~v0i9I~
				if (rc=fcmdgetcopyline(Ppcw,&plh),rc)           //~5315R~
				{                                               //~5226R~
					if (rc==-1)	//eof                           //~5226R~
						rc=0;                                   //~5226R~
					break;                                      //~5226R~
				}                                               //~5226R~
				plh->ULHlinenor=lineno;                         //~5315R~
    			UENQENT(UQUE_AFT,plhdest,plh);//need enq before filechktabdbcs//~v113I~
#ifdef UTF8SUPPH                                                   //~va00I~
				filereadctr++;                                     //~va00I~
                optcvf2l=0;                                        //~va7xR~
                if (swbinmode)                                     //~va7xI~
                	optcvf2l|=FCCVF2LO_BIN;                        //~va7xR~
//              if (fcmdcvf2l(0,Ppcw,pfhd,plh))  //after enq to pfh//~va20R~//~va7xR~
                if (fcmdcvf2l(optcvf2l,Ppcw,pfhd,plh))  //after enq to pfh//~va7xI~
//  				break;    //f2l err                            //~va00R~//~va14R~
    				f2lerrsw=1;//f2l err                           //~va14I~
#endif                                                             //~va00I~
                if (spfsw2)                                        //~v0eoI~
                {                                                  //~v0eoI~
                    if (!plh->ULHdbcs)  //not once displayed       //~v0eoI~
                    {                                              //~v113I~
                        if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v0eoI~
//                          break;                                 //~v530R~
                            return UALLOC_FAILED;                  //~v530I~
                        rc=0;   //make sure for rc=4 from filechktabdbcs//~v113I~
                    }                                              //~v113I~
		            filetabclear(plh);//tab clear                  //~v0eoI~
				}                                                  //~v0eoI~
//              if (spfsw)                                         //~v417R~
                if (spfsw2) //spf err or ok                        //~v417I~
                {                                                  //~v0eoI~
                  if (plh->ULHlen>mergin)                          //~v0d9I~
                  {                                                //~v58sI~
//  				if (fileisvalidspfline(pfhd,plh,0))//no update line spfok flag//~v0eoR~
    				if (fileisvalidspfline(pfhd,plh,1))//update line spfok flag//~v0eoI~
                        plh->ULHlen=mergin; //drop spf no          //~v0d9R~
                    else        //valid copy line                  //~v0d2M~
                    {                                              //~v0d2M~
//                      filefreeplh(plh,1);//free also entry       //~v0d8R~
				        filesetlineerr(plh);                       //~v0d8I~
                        plhe=plh;                                  //~v0d8R~
//                      break;                                     //~v0d8R~
                    }                                              //~v0d2M~
                  }//ulhlen                                        //~v58sI~
				}                                                  //~v0eoI~
//  			UENQENT(UQUE_AFT,plhdest,plh);//copy               //~v113R~
				copyctr++;                                      //~5315R~
				copyctr2++;		//when bandle=0,for each dest repeat//~v0i9I~
				plhdest=plh;                                    //~5315R~
                if (Sbssw2==1)       //copy ntimes l line by skip m//~v0i9I~
                    if (!(--bandle))    //bandle copyed            //~v0i9I~
                    {                                              //~v0i9I~
						rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,Sbandle2,Smovesw);//~v0i9I~
                        bandle=Sbandle2;     //next copy bandle    //~v0i9M~
                        if (rc)                                    //~v0i9I~
                        	break;                                 //~v0i9I~
                        if (!(--Srepeat2))	//if 0 at first,until eof//~v0i9I~
                        	break;                                 //~v0i9I~
						plhdest=getdisplayline(plhbandnext,Sskip2,0);//next isrt after//~v0i9I~
                        if (!plhdest)                              //~v0i9I~
                        {                                          //~v0i9M~
                            lcmdeolerr();                          //~v0i9M~
                            break;                                 //~v0i9M~
                        }                                          //~v0i9M~
                        plhdest=UGETQPREV(plhdest);                //~v0i9R~
						lineno=plhdest->ULHlinenor;	//save for later renum//~v0i9I~
                    }                                              //~v0i9I~
//          	if (rc)                                            //~v0ipR~
//              	break;                                         //~v0ipR~
#ifdef UTF8SUPPH                                                   //~va1qI~
                if (f2lerrsw)                                      //~va14I~
                	break;                                         //~va14I~
#endif                                                             //~va1qI~
			}//until eof                                        //~5226R~
            if (rc==UALLOC_FAILED)  //exit ii loop                 //~v0eoI~
//              break;                                             //~v530I~
                return UALLOC_FAILED;                              //~v530I~
#ifdef UTF8SUPPH                                                   //~va1qI~
            if (f2lerrsw)                                          //~va14I~
            	break;                                             //~va14I~
#endif                                                             //~va1qI~
            if (Sbssw2==1)       //copy ntimes l line by skip m    //~v0i9I~
            {                                                      //~v0i9I~
            	if (Sbandle2!=bandle)	//last bundle not comp by eof//~v0i9I~
					rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,Sbandle2-bandle,Smovesw);//~v0i9I~
                break;                                             //~v0i9R~
            }                                                      //~v0i9I~
            if (Sbssw2==2)       //copy ntimes all line by skip m  //~v0i9R~
            {                                                      //~v0i9I~
				rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,copyctr2,Smovesw);//~v0i9I~
                if (rc)                                            //~v0i9I~
                	break;                                         //~v0i9I~
				plhdest=getdisplayline(plhbandnext,Sskip2,0);//next isrt after//~v0i9I~
                if (!plhdest)                                      //~v0i9R~
                {                                                  //~v0i9I~
                    lcmdeolerr();                                  //~v0i9R~
                    break;                                         //~v0i9I~
                }                                                  //~v0i9I~
                plhdest=UGETQPREV(plhdest);//advance 1 for last EXCLUDE line//~v0i9R~
                lineno=plhdest->ULHlinenor; //save for later renum //~v0i9I~
            }                                                      //~v0i9I~
		}	//copy file                                         //~5226R~
//****** lcmd *************************************************    //~v0ibI~
		else	//lcmd                                          //~5226R~
		{
			excludesw=0;
			plhstop=Pplh2;                                      //~4C23I~
			if (!UGETQNEXT(plhstop))	//end of file           //~4C23R~
				plhstop=UGETQPREV(plhstop);//stop at before     //~4C23I~
			rc=0;	//for copy on                               //~5211I~
            pfh=UGETPFH(Pplh1);                                 //~v019I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			if (PFH_ISEBC(pfh))                                    //~va50I~
            	optcvddandl=LCCVO_SRCEBC;                          //~va50I~
            else                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
			if (FILEUTF8MODE(pfh))                                 //~va20I~
            	optcvddandl=LCCVO_SRCU8;                           //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            if (UCBITCHK(Pplc->ULCflag3,ULCF3CID))                 //~va50I~
            	optcvddandl|=LCCVO_COPYCID;                        //~va50R~
            cidchksw=0;                                            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		  if (opid!=1)//not dummy lh for repl/cre                  //~v0dlR~
          {                                                        //~v0dlI~
            pfhd=UGETPFH(plhdest);          //dest pfh             //~v0dgI~
            if (swbinmode)                                         //~va7xM~
            {                                                      //~va7xI~
                if (optcvddandl & LCCVO_SRCU8                      //~va7xI~
                ||  FILEUTF8MODE(pfhd)                             //~va7xI~
                )                                                  //~va7xI~
                {                                                  //~va7xI~
                    errnotsupported("Binary mode copy","UTF8 file");//~va7xR~
                    return 1;   //treate as pendig to keep alive   //~va7xI~
                }                                                  //~va7xI~
            	optcvddandl|=LCCVO_BIN; //no translation           //~va7xM~
            }                                                      //~va7xI~
//          spfsw=UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK);//copy into spf file//~v417R~
            spfsw2=UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//copy into spf file//~v0eoI~
            mergin=pfhd->UFHmergin;                                //~v0dgI~
           if (pfh==pfhd)           //same file                    //~v0hOI~
          	if (lineseqchk(plhdest,plhstop)<0 //plhdest<plhstop    //~v0hBR~
            &&  lineseqchk(plhdest,Pplh1)>=0)                      //~v0hBI~
            {                                                      //~v0hBI~
				uerrmsg("Source and dest line is overlap",         //~v0hBI~
						"複写元と複写先が重複");                   //~v0hBI~
            	return 4;                                          //~v0hAI~
            }                                                      //~v0hBI~
		  }	                                                       //~v0dlI~
//*target plh setup for full copy                                  //~v0ibI~
            if (Sbssw2==1)   //copy ntimes l line by skip m        //~v0ibI~
            {                                                      //~v0ibI~
                plhbandprev=plhdest;                               //~v0ibI~
                plhbandnext=getdisplayline(plhdest,1,0);           //~v0ibI~
            }                                                      //~v0ibI~
//          bandle=Sbandle2;                                       //~v67UR~
            if (Sbssw2==2)   //copy ntimes full by skip m          //~v0ibR~
            	if (!opid)		//normal copy                      //~v0ibI~
                {                                                  //~v0ibI~
                    plhbandprev=plhdest;                           //~v0ibI~
                    plhbandnext=getdisplayline(plhdest,1,0);       //~v0ibI~
                    copyctr2=0;                                    //~v0ibI~
                }                                                  //~v0ibI~
//*source plh setup                                                //~v0ibI~
          	bandle1=Sbandle1;		//source bandle                //~v0ibI~
//*                                                                //~v0ibI~
			for (plh=Pplh1;plh;plh=UGETQNEXT(plh))              //~4C23R~
			{
//*source plh chk vs bandl/skip                                    //~v0ibI~
        		if (Sbssw1)   //source has bandle/skip             //~v0ibI~
                {                                                  //~v0ibI~
					if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))    //~v0ibI~
                    {                                              //~v0ibI~
                        bandle1--;                                 //~v0ibI~
                        if (bandle1<0)	//on skip line             //~v0ibI~
                        {                                          //~v0ibI~
                        	if (Sskip1>1)                          //~v0ibR~
                            {                                      //~v0ibI~
                            	plh=getdisplayline2(plh,Sskip1-1,plhstop,0);//~v0ibR~
                                if (!plh)                          //~v0ibI~
                                	break;                         //~v0ibI~
                            }//skipped skipno                      //~v0ibI~
                            if (plh==plhstop)                      //~v0ibI~
                                break;                             //~v0ibI~
                            plh=getdisplayline(plh,1,0);//1st of bandle//~v0ibI~
                            if (!plh)                              //~v0ibI~
                                break;                             //~v0ibI~
                            bandle1=Sbandle1-1;                    //~v0ibI~
                        }//reached to next skip line               //~v0ibI~
					}//display line                                //~v0ibR~
				}//source has bandle                               //~v0ibR~
//*dest plh setup  for bandle copy                                 //~v0ibI~
                if (Sbssw2==1)       //copy ntimes l line by skip m//~v0ibI~
                {                                                  //~v0ibI~
					if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))    //~v0ibI~
                        bandle--;                                  //~v0ibI~
                    if (bandle<0)	//bandle already copyed        //~v0ibI~
                    {                                              //~v0ibI~
                        bandle=Sbandle2;     //next copy bandle    //~v0ibR~
	                	if (!opid)  //normal copy                  //~v0ibI~
                        {                                          //~v0ibI~
                            rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,Sbandle2,Smovesw);//~v0ibI~
                            if (rc)                                //~v0ibI~
                                break;                             //~v0ibI~
                            if (!(--Srepeat2))  //if 0 at first,until eof//~v0ibI~
                                break;                             //~v0ibI~
                            plhdest=getdisplayline(plhbandnext,Sskip2,0);//next isrt after//~v0ibI~
                            if (!plhdest)                          //~v0ibI~
                            {                                      //~v0ibI~
                                lcmdeolerr();                      //~v0ibI~
                                break;                             //~v0ibI~
                            }                                      //~v0ibI~
                            plhbandnext=plhdest;                   //~v0ibI~
                            plhdest=UGETQPREV(plhdest);            //~v0ibI~
                            lineno=plhdest->ULHlinenor; //save for later renum//~v0ibM~
                            plhbandprev=plhdest;                   //~v0ibI~
                        }//normal copy                             //~v0ibI~
                        else    //opid==2                          //~v0ibI~
                        {                                          //~v0ibI~
                            if (!(--Srepeat2))  //if 0 at first,until eof//~v0ibI~
                                break;                             //~v0ibI~
                            skip=Sskip2;                           //~v0ibI~
							if (UCBITCHK(plhdest->ULHflag2,ULHF2EXCLUDED))//~v0ibR~
                            	skip++;                            //~v0ibI~
                            plhdest=getdisplayline2(plhdest,skip,plhdeststop,0);//next isrt after//~v0ibR~
                            if (!plhdest)                          //~v0ibI~
                            {                                      //~v0ibI~
                                lcmdeolerr();                      //~v0ibI~
                                break;                             //~v0ibI~
                            }                                      //~v0ibI~
                            if (plhdest==plhdeststop)	//reached to PP/OO end range//~v0ibI~
                            {                                      //~v67SI~
    	                    	destbreaksw=1;                     //~v67SI~
                            	break;                             //~v0ibI~
                            }                                      //~v67SI~
                        }//opid==2                                 //~v0ibI~
                        bandle--;   //1st line                     //~v0ibI~
					}//a bandle end                                //~v0ibI~
				}//n time bandle copy                              //~v0ibI~
//*last excluded line process                                      //~v0ibI~
				if (excludesw)
					if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
						break;
				if (plh->ULHtype!=ULHTHDR)	//top of data or end of data//~4C22R~
				{
					switch(opid)	//operation id              //~5211I~
					{                                           //~5211I~
                    case 0:	//normal cmd                        //~5211I~
						plhdest=linecopy(plh,plhdest,lineno);   //~5211I~
                        if (!plhdest)	//storage shortage      //~v04dI~
                        {                                       //~v04dI~
//                      	rc=UALLOC_FAILED;  //roop exit sw      //~v530R~
//                          break;	//switch exit                  //~v530R~
                			return UALLOC_FAILED;                  //~v530I~
                        }                                       //~v04dI~
						if (plh->ULHtype==ULHTDATA)	//not EXCLUDE hdr//~v019M~
                        {                                          //~v06MI~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
							rc2=lcmdcvddandl(optcvddandl,pfhd,plhdest,pfh,plh,&cidchksw);//~va50R~
#else                                                              //~va50I~
							rc2=lcmdcvddandl(optcvddandl,pfhd,plhdest);//~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                            if (rc2==UALLOC_FAILED)                //~va20I~
                				return UALLOC_FAILED;              //~va20I~
                            if (rc2)                               //~va20I~
                            	cverrctr++;                        //~va20I~
                            if (spfsw2)                            //~v0eoR~
                            {                                      //~v0eoI~
                                if (!plhdest->ULHdbcs)  //not once displayed//~v0eoR~
                                {                                  //~v113I~
                                    if ((rc=filechktabdbcs(plhdest))==UALLOC_FAILED)//expand data len//~v0eoR~
//                                      break;                     //~v530R~
        			        			return UALLOC_FAILED;      //~v530I~
			                        rc=0;   //make sure for rc=4 from filechktabdbcs//~v113I~
                                }                                  //~v113I~
                                filetabclear(plhdest);//tab clear  //~v0eoR~
							}                                      //~v0eoI~
#ifdef UTF8SUPPH                                                   //~va1qI~
                            optopt2=(int)UCBITCHK(Goptopt2,GOPT2_CIDCOPY);//~va02I~
                          if (UCBITCHK(Pplc->ULCflag3,ULCF3CID))   //~va07I~
                            optopt2=1;                             //~va07I~
                          else                                     //~va07I~
                            if (optopt2!=Soptopt2)                 //~va02R~
                            {                                      //~va02I~
                             if (pfhd->UFHtype!=UFHTCLIPBOARD)     //~va7BR~
                             {                                     //~va7xI~
#ifdef UTF8UCS2                                                    //~va20I~
				        	  if (*pfh->UFHcid)   //have cid       //~va20I~
#endif                                                             //~va20I~
                              {                                    //~va20I~
                            	Soptopt2=optopt2;                  //~va02I~
                                uerrmsg("line copy under %s option(See CID cmd help)",0,//~va02R~
                                		(optopt2?"COPYON":"COPYOFF"));//~va02I~//~va07R~
                              }                                    //~va20I~
                             }                                     //~va7BR~
                            }                                      //~va02I~
#endif                                                             //~va1qI~
				        	if (*pfh->UFHcid)   //have cid      //~v019M~
					            if (!Smovesw) //result of move lcmd//~v0dfR~
//  					  				plhdest->ULHlen=filecidlrecl(plh,pfh);//~v0chR~
//    					  				plhdest->ULHlen=filecidlrecl2(plh,pfh);//~v0dfR~
								{                                  //~v0dfI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
           						 if (!cidchksw)	//copy locale,utf8-->ebc,cid copy option chked//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
                                 {//!cidchksw                      //~va50I~
#ifdef UTF8SUPPH                                                   //~va1qI~
                                  if (optopt2)                     //~va02R~
                                  {                                //~va02I~
                                    copylen=plh->ULHlen;           //~va02I~
                                    cidlen=0;                      //~va02I~
                                  }                                //~va02I~
                                  else                             //~va02I~
#endif                                                             //~va1qI~
                                    cidlen=filegetcidlenc(plh,pfh,0,//lrecl=0//~v0efR~
													      &topcidpos,&lastcidpos,&copylen);//no topcidpos//~v0efR~
//                                    if (contlen)                 //~v0efR~
//                                        plhdest->ULHlen=pfh->UFHmergin;//~v0efR~
//                                    else                         //~v0efR~
//                                        plhdest->ULHlen=lrecl;   //~v0efR~
                                    plhdest->ULHlen=copylen;       //~v0efI~
#ifdef UTF8SUPPH                                                   //~va1qI~
                                  if (cidlen)                      //~va02I~
#endif                                                             //~va1qI~
                                  {                                //~va02I~
                                    memset(plhdest->ULHdata+topcidpos,' ',(UINT)cidlen);//~v0dfI~
                                    if (plhdest->ULHdbcs)          //~v0dfR~
	                                    memset(plhdest->ULHdbcs+topcidpos,0,(UINT)cidlen);//~v0dfI~
                                  }                                //~va02I~
                                 }//!cidchksw                      //~va50I~
                                }                                  //~v0dfI~
                        	if (insbycapsw)	//cap insert line      //~v06MM~
                            	charcaprev(plhdest,0,plhdest->ULHlen);	//reverse//~v06MI~
//  		                if (spfsw)                             //~v417R~
    		                if (spfsw2)                            //~v417I~
            					if (plhdest->ULHlen>mergin)        //~v417R~
                                {                                  //~v58sI~
									if (fileisvalidspfline(pfhd,plhdest,0))//no update spf flag//~v0duR~
                                        plhdest->ULHlen=mergin; //drop spf no//~v0dgI~
                                    else        //valid copy line  //~v0dgI~
                                    {                              //~v0dgI~
                                        filesetlineerr(plhdest);   //~v0dgI~
                                        plhe=plhdest;              //~v0dgI~
                                    }                              //~v0dgI~
                                }//margin                          //~v58sI~
						}                                          //~v06MI~
						copyctr++;                              //~5226I~
						copyctr2++;                                //~v0ibI~
						break;                                  //~5211I~
					case 1:	//repl/create cmd                   //~5211I~
                       	if (plh1)                               //~5128I~
							plh2=plh;	//last                  //~5128I~
						else                                    //~5128I~
							plh1=plh2=plh;	//top and last      //~5311R~
                        if (Sbssw1) //bandle used                  //~v0ibI~
                            UCBITON(plh->ULHflag4,ULHF4SELECTED);  //~v0ibI~
						copyctr++;                              //~5226M~
						break;                                  //~5211I~
                    case 2:	//copy ON                           //~5211I~
						if (plh->ULHtype==ULHTDATA)	//not EXCLUDE hdr//~5226R~
                        {                                          //~v58sI~
//  						if (!(rc=lcmdover(Ppcw,overopid,plh,&plhdest,overoffs)))//~v74JR~
    						if (!(rc=lcmdover(Ppcw,overopid|lcmdoverlcmdid,plh,&plhdest,overoffs)))//~v74JI~
								copyctr++;                      //~5226I~
                            else                                   //~v0avI~
                                if (rc==16) //mergin err           //~v0avI~
                                {                                  //~v0avI~
                                    rc=0;	//continue process     //~v0avI~
                                    merginerrsw=1;                 //~v0avI~
                                    errmergin=mergin;              //~v74EI~
                                    if (pfhd->UFHbndscol2>0)       //~v74ER~
                                    	errmergin=pfhd->UFHbndscol2;//~v74ER~
                                }                                  //~v0avI~
                        }//ULHTDATA                                //~v58sI~
						if (plhdest==plhdeststop)                  //~v0hoI~
                        	destbreaksw=1;                         //~v0hoI~
						break;                                  //~5211I~
					}//sw by operation id                       //~5211R~
                    if (destbreaksw)                               //~v0hoI~
                    	break;                                     //~v0hoI~
					if (rc)	//no copy on destination            //~5211I~
						break;                                  //~5211I~
				}
				if (plh==plhstop)                               //~4C23R~
                {                                                  //~v58sI~
					if (plh->ULHtype!=ULHTEXCLUDE)
						break;
					else
						excludesw=1;
                }//plhstop                                         //~v58sI~
			}//until ph2
            if (rc==UALLOC_FAILED)  //exit ii loop              //~v04dI~
//              break;                                             //~v530R~
        		return UALLOC_FAILED;                              //~v530I~
//*******************                                              //~v0ibI~
            if (Sbssw2==1)       //copy ntimes l line by skip m    //~v0ibI~
            {                                                      //~v0ibI~
                if (!opid)      //normal copy                      //~v0ibI~
                {                                                  //~v0ibI~
                    if (Sbandle2!=bandle)   //last bundle not comp by eof//~v0ibI~
                        rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,Sbandle2-bandle,Smovesw);//~v0ibI~
                    break;                                         //~v0ibI~
                }                                                  //~v0ibI~
                else                                               //~v67QI~
                {                                                  //~v67QI~
					if (!rangepastesw)   //pp-pp/oo-oo type        //~v67QR~
    	                break;                                     //~v67QI~
                }                                                  //~v67QI~
            }//ntimes line copy                                    //~v0ibI~
            if (Sbssw2==2)       //copy ntimes all line by skip m  //~v0ibI~
            {                                                      //~v0ibI~
                if (!opid)      //normal copy                      //~v0ibI~
                {                                                  //~v0ibI~
                    rc=lcmdrenumsuffix(Ppcw,plhbandprev,plhbandnext,copyctr2,Smovesw);//~v0ibI~
                    if (rc)                                        //~v0ibI~
                        break;                                     //~v0ibI~
                    plhdest=getdisplayline(plhbandnext,Sskip2,0);//next isrt after//~v0ibI~
                    if (!plhdest)                                  //~v0ibI~
                    {                                              //~v0ibI~
                        lcmdeolerr();                              //~v0ibI~
                        break;                                     //~v0ibI~
                    }                                              //~v0ibI~
                    plhdest=UGETQPREV(plhdest);//advance 1 for last EXCLUDE line//~v0ibI~
                    lineno=plhdest->ULHlinenor; //save for later renum//~v0ibI~
                }//normal copy                                     //~v0ibI~
                else        // paste(p,o,n)                        //~v67RI~
                {                                                  //~v67RI~
                    plhdest=getdisplayline2(plhdest,Sskip2,plhdeststop,0);//next isrt after//~v67SR~
                    if (!plhdest)                                  //~v67RI~
                    {                                              //~v67RI~
                        lcmdeolerr();                              //~v67RI~
                        break;                                     //~v67RI~
                    }                                              //~v67RI~
                    if (plhdest==plhdeststop)   //reached to PP/OO end range//~v67SI~
                    {                                              //~v67SI~
        				destbreaksw=1;	//ranged ON/PASTE          //~v67SI~
                        break;                                     //~v67SI~
                    }                                              //~v67SI~
                }//normal copy                                     //~v67RI~
            }//dest bandle=0                                       //~v0ibI~
//*******************                                              //~v0ibI~
		}//lcmd                                                 //~5315R~
        if (destbreaksw)	//ranged ON/PASTE                      //~v0hoI~
            break;                                                 //~v0hoI~
        if (!plhdest)	    //ON/PASTE destination reached to EOF  //~v67PI~
            break;                                                 //~v67PI~
		if (plhdeststop)	//range stop,not count                 //~v0hoI~
        	ii--;			//infinite count                       //~v0hoR~
	}//loop by ii=repeat count                                  //~5226R~
                                                                   //~v530I~
    if (rc==UALLOC_FAILED)  //exit ii loop                         //~v530I~
        return UALLOC_FAILED;                                      //~v530I~
                                                                //~5226I~
    if (merginerrsw)                                               //~v0avI~
    {                                                              //~v0avI~
        UCBITON(Pplc->ULCflag2,ULCF2MERGINERR);                    //~v0bgI~
//      charmaxovererr(mergin);                                    //~v74ER~
        charmaxovererr(errmergin);                                 //~v74EI~
		if (copyctr)//some success some err                        //~v0eII~
        	ubell();                                               //~v0eIR~
    }                                                              //~v0avI~
	if (!copyctr)                                               //~4C23I~
    {                                                              //~v0hsI~
		if (copyfilesw) //called from fcmdcopy                     //~v0hsI~
          if (!rc) 		//eof                                      //~v0hLI~
#ifdef UTF8SUPPH                                                   //~va00I~
           if (!filereadctr)                                       //~va00I~
#endif                                                             //~va00I~
        	uerrmsg("It's NULL file",                              //~v0hsI~
            	    "それは空ファイルです");                       //~v0hsI~
    	return 4;                                               //~4C23I~
    }                                                              //~v0hsI~
    if (plhe)                                                      //~v0d8I~
    {                                                              //~v0d8I~
      if (UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK))	//valid spf file//+vag4I~
      {                                                            //+vag4I~
        UCBITOFF(pfhd->UFHflag2,UFHF2SPFNUMOK);//copy into spf file//~v0d8I~
        UCBITON(pfhd->UFHflag2,UFHF2SPFNUMERR);//copy into spf file//~v0diI~
      	rc=undoprep(Ppcw,plhe,UUHTSPFERR);	//set spf err          //~v0d8I~
        if (rc)                                                    //~v0d8I~
        	return rc;                                             //~v0d8I~
      }                                                            //+vag4I~
        uerrmsg("Invalid line for Numbered-Line-File",             //~v0d8I~
                "行番号付ファイルとしてに正しくない行がありました");//~v0d8I~
        ubell();                                                   //~v0d8I~
    }                                                              //~v0d8I~
#ifdef UTF8SUPPH                                                   //~va1qI~
    if (f2lerrsw)                                                  //~va14I~
    {                                                              //~va14I~
        ubell();                                                   //~va14I~
    }                                                              //~va14I~
#endif                                                             //~va1qI~
    switch(opid)                                                //~5213I~
    {                                                           //~5213I~
    case 0:                                                     //~5213I~
//    if (!copyfilesw || !Sbssw2)       //copy ntimes l line by skip m//~v0ibR~
      if (!Sbssw2)       //dest has bandle/skip                    //~v0ibI~
		rc=lcmdrenumsuffix(Ppcw,plhfirst,plhnext,copyctr,Smovesw);//~v04dR~
   		if (Ppcw->UCWsplitid==Gscrcurclient)   //cur client     //~5213I~
			filesetcsr(Ppcw,(PULINEH)UGETQNEXT(plhfirst),0,0);	//set csr,fldtop//~5223R~
// 		filesetmultdraw(Ppcw);	//all client draw of same file     //~v0hfR~
    	filesetdrawstart(Ppcw,plhfirst,DRAW_MULT|DRAW_ISRT);	//redraw from inserted,all client of same file//~v0hfI~
        break;                                                  //~5213I~
    case 1:                                                     //~5213I~
      if (Sbssw1)                                                  //~v0ibI~
      {                                                            //~v0ibI~
        rc=fcmdoutrangebs(Ppcw,plh1,plh2);	//call save2           //~v0ibR~
        lcmdclearselected(plh1,plh2);                              //~v0ibI~
      }                                                            //~v0ibI~
      else                                                         //~v0ibI~
		rc=fcmdoutrange(Ppcw,plh1,plh2);                        //~5213M~
        break;                                                  //~5213I~
    case 2:                                                     //~5213I~
   		if (Ppcw->UCWsplitid==Gscrcurclient)   //cur client     //~5211I~
        {                                                          //~v58sI~
            if (overoffs)                                       //~5213R~
				csrloctogbl(Ppcw);	//csr set req flag for avoid next_line//~5213I~
            else                                                //~5213I~
				filesetcsr(Ppcw,plhfirst,1,0);	//to client fld,fldtop//~5223R~
                                                                //~5213I~
        }//curclient                                               //~v58sI~
// 		filesetmultdraw(Ppcw);	//all client draw of same file     //~v0hfR~
    	filesetdrawstart(Ppcw,plhfirst,DRAW_MULT|DRAW_ISRT);	//redraw from (may)inserted,all client of same file//~v0hfI~
        rc=0;                                                   //~5213I~
        break;                                                  //~5213I~
	}                                                           //~5213I~
#ifdef UTF8UCS2                                                    //~va20I~
    if (cverrctr)                                                  //~va20I~
    {                                                              //~va20I~
        uerrmsg("Translation err count=%d",                        //~va20I~
                "変換エラー %d件",                                 //~va20I~
                cverrctr);                                         //~va20I~
        ubell();                                                   //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
	return rc;                                                  //~5213R~
}//lcmdcopy
                                                                //~5126I~
//**************************************************************** //~v0ibI~
//!lcmdclearselected                                               //~v0ibI~
//  clear ULHF4SELECTED                                            //~v0ibI~
//*parm 1:start plh                                                //~v0ibI~
//*parm 2:end plh                                                  //~v0ibI~
//*return:none                                                     //~v0ibI~
//**************************************************************** //~v0ibI~
void lcmdclearselected(PULINEH Pplh1,PULINEH Pplh2)                //~v0ibI~
{                                                                  //~v0ibI~
	PULINEH plh;                                                   //~v0ibI~
//**************                                                   //~v0ibI~
	for (plh=Pplh1;plh;plh=UGETQNEXT(plh))                         //~v0ibR~
    {	                                                           //~v0ibI~
    	UCBITOFF(plh->ULHflag4,ULHF4SELECTED);                     //~v0ibR~
        if (plh==Pplh2)                                            //~v0ibI~
        	break;                                                 //~v0ibI~
    }                                                              //~v0ibI~
    return;                                                        //~v0ibI~
}//lcmdclearselected                                               //~v0ibI~
                                                                   //~v0ibI~
//****************************************************************//~5211I~
//!linecopy                                                     //~v04dR~
//  copy ULINEH and enq                                         //~5211I~
//*parm 1:source ulh                                            //~5211I~
//*parm 2:plh enq after                                         //~5211I~
//*parm 3:lineno to be set to new line                          //~5211I~
//*return:inserted ulh or 0 if storage shortage                 //~v04dR~
//****************************************************************//~5211I~
PULINEH linecopy(PULINEH Pplh,PULINEH Pplhdest,long Plineno)    //~5211I~
{                                                               //~5211I~
	PULINEH plhc;                                               //~5211I~
//**************                                                //~5211I~
	plhc=ulhcopy(Pplh);                                         //~5211I~
    UALLOCCHK(plhc,0);	//return if storage shortage            //~v04dR~
	plhc->ULHlinenor=Plineno;                                   //~5211I~
	UENQENT(UQUE_AFT,Pplhdest,plhc);//copy                      //~5211I~
	return plhc;	                                            //~5211R~
}//linecopy                                                     //~5211I~
                                                                //~5211I~
//****************************************************************
//*ulhcopy                                                      //~v04dR~
//  copy ULINEH
//*rc   :plh or 0 if storage shortage                           //~v04dR~
//****************************************************************
PULINEH ulhcopy(PULINEH Pplh)
{
	PULINEH plh;
	UCHAR *pc;
	int bufflen;
//****************
	plh=UALLOCM(ULINEHSZ);                                      //~v04dR~
    UALLOCCHK(plh,0);   //return 0 if storage shortage          //~v04dI~
	memcpy(plh,Pplh,sizeof(ULINEH));
	memset(&plh->ULHqelem,0,sizeof(plh->ULHqelem));
	memset(plh->ULHlinecmd,0,sizeof(plh->ULHlinecmd));
    IFDEF_SYNSUPP(                                                 //~v780I~
			plh->ULHci=0;                                          //~v780I~
            SYN_INVALIDATE_PLH(plh);                               //~v780I~
			)                                                      //~v780I~
	pc=plh->ULHdata=UALLOCM((UINT)(bufflen=plh->ULHbufflen));   //~v04dR~
    if (!pc)                                                    //~v04dI~
    {                                                           //~v04dI~
        ufree(plh);                                             //~v04dI~
        return 0;                                               //~v04dI~
    }                                                           //~v04dI~
	memcpy(pc,Pplh->ULHdata,(UINT)bufflen);
	UCBITOFF(plh->ULHflag,                                      //~5423R~
		ULHFLINECMD | ULHFLCMDERR | ULHFCURFOUND | ULHFBLOCK | ULHFCURCAP);//~5423R~
//  UCBITOFF(plh->ULHflag2,ULHF2MFOUND);                           //~v0bcR~
//  UCBITOFF(plh->ULHflag2,ULHF2MFOUND|ULHF2SPLIT1|ULHF2SPLIT2);   //~v0bkR~
    UCBITOFF(plh->ULHflag2,ULHF2MFOUND);                           //~v0bkI~
//  UCBITOFF(plh->ULHflag3,ULHF3CMDECHO);                 //+v06uR~,//~v0a8R~
    UCBITOFF(plh->ULHflag3,ULHF3ERRLINE);                 //+v06uR~,//~v0azI~
//  UCBITOFF(Pplh->ULHflag3,ULHF3SPFNUMOK|ULHF3SPFNUMERR);//need chk next//~v0iqR~
//  UCBITOFF(plh->ULHflag3,ULHF3SPFNUMOK|ULHF3SPFNUMERR);//need chk next//~v79qR~
    UCBITOFF(plh->ULHflag3,ULHF3SPFNUMOK|ULHF3SPFNUMERR|ULHF3CMDECHO);//need chk next//~v79qI~
    UCBITOFF(plh->ULHflag4,ULHF4PROTLINE);	//protected(change line attr)//~v0ioR~
	plh->ULHrevctr=0;                                           //~5422R~
	/*plh->ULHrevoffs=*/plh->ULHrevoffs=0;                          //~5422R~//~vaa7R~
	if (pc=Pplh->ULHdbcs,pc)
    {                                                           //~v04dI~
		if (!(plh->ULHdbcs=UALLOCM((UINT)bufflen)))             //~v04dI~
    	{                                                       //~v04dI~
        	ufree(plh->ULHdata);                                //~v04dI~
        	ufree(plh);                                         //~v04dI~
        	return 0;                                           //~v04dI~
    	}                                                       //~v04dI~
		memcpy(plh->ULHdbcs,pc,(UINT)bufflen);                  //~v04dR~
    }                                                           //~v04dI~
	return plh;
}//ulhcopy
                                                                //~5211I~
//****************************************************************//~5211I~
// lcmdover                                                     //~5211R~
// line override to destination line(overide avail on excluded line)//~5211I~
//*parm 1:pcw                                                   //~5211I~
//*parm 2:operation id                                          //~5211I~
//*parm 3:source ulh                                            //~5211R~
//*parm 4:ptr to destination plh,at return next destination     //~5211R~
//*parm 5:override position                                     //~5211R~
//*return:rc 0 4 16(mergin err) UALLOC_FAILED                      //~v0avR~
//****************************************************************//~5211I~
int lcmdover(PUCLIENTWE Ppcw,int Popid,PULINEH Pplh,PULINEH *Ppplhdest,int Poffs)//~5211R~
{                                                               //~5211I~
static PULINEH Splhx;	//exclude hdr line                         //~v0avM~
	PULINEH plhd;                                               //~5211I~
    int rc;                                                        //~v0avI~
//**************                                                //~5211I~
	for (plhd=*Ppplhdest;plhd;plhd=UGETQNEXT(plhd))             //~5211R~
    {                                                              //~v0avI~
    	if (plhd->ULHtype==ULHTEXCLUDE)      //no delete when hdr line//~v0avI~
			Splhx=plhd;                     //for lcmdshifterr     //~v0avI~
		if (plhd->ULHtype==ULHTDATA)                            //~5211R~
			break;                                              //~5211I~
	}                                                              //~v0avI~
	if (!plhd)                                                  //~5211I~
		return 4;                                               //~5211I~
//  if ((rc=charcap(Ppcw,Popid,Pplh,plhd,Poffs))==UALLOC_FAILED)   //~v74ER~
//  if ((rc=charcap(Ppcw,Popid | CHAROPLCMD,Pplh,plhd,Poffs))==UALLOC_FAILED)//~v74JR~
    if ((rc=charcap(Ppcw,Popid,Pplh,plhd,Poffs))==UALLOC_FAILED)   //~v74JI~
		return UALLOC_FAILED;                                   //~v04dI~
    if (rc==16)                                                    //~v0avI~
		lcmdshifterr(plhd,Splhx,0);                                //~v0avI~
	*Ppplhdest=UGETQNEXT(plhd);                                 //~5211R~
	return rc;	                                                   //~v0avR~
}//lcmdover                                                     //~5211R~
//**************************************************************** //~va7xI~
//!setdbcstbl for binmode copy(ebc and locale only,utf8 is rejected already)//~va7xR~
//*return:UALLOC_FAILED                                            //~va7xI~
//**************************************************************** //~va7xI~
int lcmdsetdbcstblbin(int Popt,PUFILEH Ppfh,PULINEH Pplh)          //~va7xI~
{                                                                  //~va7xI~
	int rc,len,swebcfile;                                          //~va7xR~
    UCHAR *pc,*pcd;                                                //~va7xR~
//**************                                                   //~va7xI~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va7xM~
	pc=Pplh->ULHdata;                                              //~va7xI~
	pcd=Pplh->ULHdbcs;                                             //~va7xI~
	len=Pplh->ULHlen;                                              //~va7xI~
	if (swebcfile                                                  //~va7xI~
    &&  !(Popt & LCCVO_SRCEBC)  //m2b                              //~va7xI~
    &&  pcd                                                        //~va7xI~
    )                                                              //~va7xI~
    {                                                              //~va7xI~
		len-=sub_restoretabdroppad(0,pc,pcd,len);                  //~va7xI~
		Pplh->ULHlen=len;                                          //~va7xI~
    }                                                              //~va7xI~
    if (!swebcfile)	//locale file                                  //~va7xI~
    {                                                              //~va7xI~
    	if (pcd)	//ebc dbcstbl copyed                           //~va7xI~
    		filesetdbcstbl(pc,pcd,len,0);//no chk tab              //~va7xI~
    }                                                              //~va7xI~
    UCBITOFF(Pplh->ULHflag2,(ULHF2TABCHKED|ULHF2TABFOUND)); //(re)init dbcstbl//~va7xR~
    rc=filechktabdbcs(Pplh);                                       //~va7xR~
    UALLOCCHKRC(rc);   //return 0 if storage shortage              //~va7xR~
    return 0;                                                      //~va7xI~
}//lcmdsetdbcstblbin                                               //~va7xR~
#ifdef UTF8UCS2                                                    //~va7xI~
//**************************************************************** //~va20I~
//!line translation between utf8 file and non utf8 file            //~va20I~
//*return:UALLOC_FAILED,4:cv err                                   //~va20R~
//**************************************************************** //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int lcmdcvddandl(int Popt,PUFILEH Ppfh,PULINEH Pplh,PUFILEH Ppfhs,PULINEH Pplhs,int *Ppcidchksw)//~va50R~
#else                                                              //~va50I~
int lcmdcvddandl(int Popt,PUFILEH Ppfh,PULINEH Pplh)               //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                                  //~va20I~
	int rc,opt;                                                    //~va20R~
    int topcidpos,lastcidpos,copylen=0;                            //~va50R~
//**************                                                   //~va20I~
    *Ppcidchksw=0;                                                 //~va50I~
    if (FILEUTF8MODE(Ppfh))//target is not utf8                    //~va20I~
    {                                                              //~va20I~
		if ((Popt & LCCVO_SRCU8))  //source is cpu8                //~va20R~
        	return 0;                                              //~va20I~
        opt=FCVACO_L2DD;                                           //~va20R~
    }                                                              //~va20I~
    else                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(Ppfh))     //tgt is ebc                          //~va50I~
    {                                                              //~va50I~
  		if (UCBITCHK(Ppfhs->UFHflag4,UFHF4BIN))                    //~va50M~
        	return 0;                                              //~va50M~
        if ( Smovesw  //result of move lcmd                        //~va50R~
        ||  (!*Ppfhs->UFHcid)   //src have no cid                  //~va50R~
        ||  (  (Popt & LCCVO_COPYCID)                              //~va50R~
             ||(UCBITCHK(Goptopt2,GOPT2_CIDCOPY))                  //~va50R~
            )//copy cid option                                     //~va50R~
        )                                                          //~va50R~
    		*Ppcidchksw=1;                                         //~va50I~
        else                                                       //~va50R~
        {                                                          //~va50R~
            filegetcidlenc(Pplhs,Ppfhs,0,//outlrecl=0              //~va50R~
                    &topcidpos,&lastcidpos,&copylen);//no topcidpos//~va50R~
            Pplh->ULHlen=copylen;	//update ebc file length before translation//~va50R~
    		*Ppcidchksw=2;                                         //~va50I~
        }                                                          //~va50R~
		if (Popt & LCCVO_SRCEBC)  //source is not ebc              //~va50I~
        {                                                          //~va79I~
          if (Ppfh->UFHhandle==Ppfhs->UFHhandle)                   //~va79I~
        	return 0;                                              //~va50I~
        }                                                          //~va79I~
		if (Popt & LCCVO_SRCU8)  //source is not cpu8              //~va50I~
        	opt=FCVACO_DD2L;     //src is utf8                     //~va50R~
        else                                                       //~va50I~
        	opt=FCVACO_L2DD;     //src is locale                   //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    {                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (!(Popt & LCCVO_SRCEBC))  //source is not ebc             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		if (!(Popt & LCCVO_SRCU8))  //source is not cpu8           //~va20R~
        	return 0;                                              //~va20I~
        opt=FCVACO_DD2L;                                           //~va20R~
    }                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	if (Popt & LCCVO_SRCEBC)  //source is not ebc                  //~va50I~
    {                                                              //~va50I~
  		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))	//tgt bin file     //~va50I~
        	return 0;                                              //~va50I~
        opt|=FCVACO_B2;     //copy cmd id                          //~va50M~
    }                                                              //~va50I~
	if (Popt & LCCVO_BIN)  //source is cpu8                        //~va7xM~
		return lcmdsetdbcstblbin(Popt,Ppfh,Pplh);                  //~va7xM~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
//  rc=filecvaftercopy(opt,Ppfh,Pplh);                             //~va20I~//~va79R~
    rc=filecvaftercopy(opt,Ppfh,Pplh,Ppfhs);	//pass source plh for handle//~va79R~
    return rc;                                                     //~va20I~
}//lcmdcvddandl                                                    //~va50R~
#endif //UTF8UCS2                                                  //~va20I~
//**************************************************************** //~v0i9I~
// lcmeolerr                                                       //~v0i9I~
// skip line overed END line                                       //~v0i9I~
//**************************************************************** //~v0i9I~
int lcmdeolerr(void)                                               //~v0i9I~
{                                                                  //~v0i9I~
	uerrmsg("Copy stopped by END OF FILE line",                    //~v0i9I~
			"複写が END OF FILE により中断しました");              //~v0i9I~
	return 4;                                                      //~v0i9I~
}                                                                  //~v0i9I~
