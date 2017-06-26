//*CID://+vb87R~:                             update#=   80;       //+vb87R~
//*************************************************************
//*xelcmd.c                                                     //~v03wR~
//**file line cmd
//*************************************************************
//vb87:170216 inactivate lcmd on excluded line                     //~vb87I~
//vb84:170215 (BUG)line of status ULHFLINECMD on but not on UFHliencmd[], the line cmd input is ignored//~vb84I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vah0:130331 (Bug)re-evaluate of pending lcmd of other client requred.//~vah0I~
//            crash when pendig lmd line was deleted and not entered yet//~vah0I~
//            then enter on other split line                       //~vah0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va07:090628 add copy cid option to Copy lcmd(AI/BI)              //~va07I~
//v77v:080117*xuerpchk(uerrmsg parameter chk)                      //~v77vI~
//v75b:070419 lcmd TS support                                      //~v75bI~
//v75a:070419 lcmd TFn/":"/";" support                             //~v75aR~
//v74M:070328 lcmd lower support                                   //~v74MI~
//v724:061118 (BUG)ABEND by join lcmd;access of deleted line cause ABEND//~v724R~
//v69W:060720 one more RESet level;to clear label lcmd use "RES L" or 3 times continuous Esc key press.//~v69WI~
//v69L:060713 cap(CAPS LOCK On) support;add "U" lcmd(uppercase translation)//~v69LI~
//v69K:060712*acccept line cmd max repeat over 9999 for del only   //~v69KI~
//v67Z:060228 "r" lcmd:support n parameter of xn,b.s patern as repeat count//~v67ZI~
//v67X:060228 "y" lcmd:reject n of yy-yy(previously ignored)       //~v67XI~
//v67T:060226 (BUG)paste line cmd;pp-pp,b.s type ignore s count only at first loop//~v67TI~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v58s:040923 niche option for copy edit cmd(n:override target line by not space char of src line)//~v58sI~
//v54A:040119 ++ lcmd flug definition err(bundle,skip is not supported)//~v54AI~
//v50s:030112 lcmd II support  IIn,b.s n:isrt lineno,b bandle,s:skip//~v50sI~
//v47c:020223 chk duplicated label on lineno column.               //~v47cI~
//v41f:010804 change lcmd spec;<,> reduce intermediate space to one space//~v41fI~
//            keep old <,> as [,]                                  //~v41fI~
//v156:000403 join lcmd option to join n lines(jjl,m.n fmt)        //~v156I~
//v11q:990726 errmsg when csrpos err for shift+enter(split line) to chk shift lcmd err bug//~v11qI~
//            (drop v11n trace)                                    //~v11qI~
//v11n:990720 set debug trace for find cmd/shift lcmd beep         //~v11nI~
//v11l:990718 allow label by lineno .nnnn not when hex-lineno mode //~v11lI~
//v118:990613 reset errline by esc*2 or reset cmd                  //~v118I~
//v0k3:981011 "=" lcmd(compare line)                               //~v0k3I~
//v0id:980607 (BUG)abend at reset when lcmd line deleted           //~v0idI~
//v0i9:980526 lcmd bandle/skip support for pair cmd("C","M","A","B","P","P")//~v0i9I~
//v0i7:980520 split/join line cmd('S'/'J') support                 //~v0i7R~
//v0i6:980512 count/range support for Y lcmd                       //~v0i6I~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0hG:980418 (BUG)label on EXCLUDE line disappear when word found on excluded//~v0hGI~
//            so prohibit label on EXCLUDE line.                   //~v0hGI~
//v0hy:980411 csr pos on err not pending                           //~v0hyI~
//v0hx:980410 label lcmd support for find etc.                     //~v0hxI~
//            alternative of v0hk and  v0hw is not needed anymore. //~v0hxI~
//v0hw:980410 (BUG)need allow A/B lcmd for also browsw for FIND line range support//~v0hwI~
//                 but need protect copy into etc by another method.//~v0hwI~
//v0ho:980221 range support for on/pase pos cmd                    //~v0hoI~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//v0hk:980214 support line range by A/B for find/change all cmd    //~v0hkI~
//            (fcmd2 split to fcmd2a as include file)              //~v0hkI~
//v0as:970719 general comment command(+)                           //~v0asI~
//v0aq:970719 add lcmd //(c comment out)                           //~v0aqI~
//v097:970413:(BUG)edit avail on display screen when same file is opened//~v097I~
//            on other size of screen with edit mode.              //~v097I~
//            lcmd.c                                               //~v097I~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -include/exclude/include last/include first        //~v06lI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v06d:960309:collect line cmd by full length for internal plc(COPY/REPL/CRE)//~v06dI~
//v069:960224:linenosz changeable for edit/browse(err when linenosz<=1)//~v069R~
//v055:951014:(BUG)abend when delete lcmd input line by Shist+Del key//~v055I~
//            because pfh->UFHcmdline remain point deleted line.//~v055I~
//v04f:951005:dummy plc for copy comand remain on pvlcmd and the back//~v04fI~
//            to UFHcmdline by otherclient(FCMD del only UFHcmdline)//~v04fI~
//            when enter key from other screen.                 //~v04fI~
//            (no save dummy and no need delsh)                 //~v04fI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v049:950924:lcmd repeat max chk to avoid swapper full         //~v049I~
//v03x:950902:addr err lcmd to pend cmd to always set err       //~v03wI~
//            if not,err lcnmd hiddden by page scroll           //~v03wI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//950428 bug under Dos,reduceing long to int miss sign          //~5428I~
//950310 allow repl/create for brosw screen                     //~5311R~
//950226 'Y':display all excluded                               //~5311I~
//950114 bug when other client UFCcurtop deleted by MOVE(scr not creared)//~5226I~
//941208 return 2 when range pending                            //~5114I~
//       if rc<4 continue cmd process(FIND ETC)
//*************************************************************
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
#include <ualloc.h>                                                //~v11nM~
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                                 //~v11lI~
#include <utrace.h>                                              //~v11qR~//~vah0R~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xepan.h"
#include "xefile.h"
#include "xefile2.h"
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd3.h"
#include "xelcmd5.h"                                               //~v0k3I~
#include "xefunc.h"
#include "xeerr.h"                                              //~v03wI~
//*******************************************************
#define MAXREPEAT 9999		//max repeat count                  //~v049I~
#define REPDELM1   ','      //for bandle.skip                      //~v0i0R~
#define REPDELM2   '.'      //for bandle.skip                      //~v0i0R~
//#define NULLINIT1    0,0,0,0,0,0,0                               //~v75aR~
#define NULLINIT1    0,"",0,0,0,0,0,0,0   //flag3,rsv,index,repeat,skip,bandle,splitid,plh,range//~v75aI~
#define NULLINIT2      "",0,0,0,0,0,0,0   //flag3,rsv,index,repeat,skip,bandle,splitid,plh,range//~v75aI~
//*******************************************************       //~v049I~
static ULCMD Scmdlist[]={
//  			{'O',ULCTPOSCMD},				//on(rep mode override)//~v0hoR~
    			{'O',ULCTPOSCMD, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},				//on(rep mode override)//~v0i9R~
//  			{'P',ULCTPOSCMD},				//paste(insert mode override)//~v0hoR~
    			{'P',ULCTPOSCMD, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},				//paste(insert mode override)//~v0i9R~
    			{ULCCMDNICHE,ULCTPOSCMD, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},		//niche(rep by source line non space char)//~v58sI~
//  			{ULCCMDAFTER,ULCTPOSCMD,ULCFBROWSE},				//after//~v0hxR~
    			{ULCCMDAFTER,ULCTPOSCMD,0,0,NULLINIT1},				//after    //~v0i9R~
//  			{ULCCMDBEFORE,ULCTPOSCMD,ULCFBROWSE},				//before//~v0hxR~
				{ULCCMDBEFORE,ULCTPOSCMD,0,0,NULLINIT1},				//before   //~v0i9R~
				{ULCCMDCOPY,ULCTNEEDPOS,ULCFRANGE|ULCFRGNOREP|ULCFBROWSE,0,NULLINIT1},//copy//~v0i9R~
				{ULCCMDMOVE,ULCTNEEDPOS,ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//move//~v0i9R~
				{'(',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//cut shift//~v0i0R~
				{')',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//cut shift//~v0i0R~
				{'<',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//shift//~v0i0R~
				{'>',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//shift//~v0i0R~
				{'[',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//shift//~v41fI~
				{']',ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//shift//~v41fI~
				{ULCCMDTFLOW,ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP,           0,            ULCF3CNT0,NULLINIT2},	//TFLOW/":"//~v75aR~
				{ULCCMDTFLOWKW,ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP,           0,            ULCF3CNT0,NULLINIT2},	//TFLOW/":"//~v75aR~
				{ULCCMDTFLOWSTR,ULCTNOPAIR,      0,ULCF2NOSKIP|ULCF2NOBAND ,ULCF3CNT0,NULLINIT2},	//TFLOW/":"//~v75aR~
//  			{'R',ULCTNOPAIR, ULCFRANGE},	//repeat           //~v0hoR~
//  			{ULCCMDREP,ULCTNOPAIR, ULCFRANGE,ULCF2NOCNTSB,NULLINIT1},	//repeat//~v67ZR~
    			{ULCCMDREP,ULCTNOPAIR, ULCFRANGE,0           ,NULLINIT1},	//repeat//~v67ZI~
				{'D',ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//delete
				{'/',ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//c comment//~v0i0R~
				{'S',ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//split//~v0i7I~
				{ULCCMDTSSTR,ULCTNOPAIR,0,0,NULLINIT1},	//TS(split)//~v75bR~
//  			{'J',ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP},	//split//~v156R~
    			{'J',ULCTNOPAIR, ULCFRANGE,0,NULLINIT1},	//join,rep count use n-line join//~v47jR~
//  			{ULCCMDCOMM,ULCTNOPAIR, ULCFRANGE, ULCF2STRREP,ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},	//general comment//~v54AR~
    			{ULCCMDCOMM,ULCTNOPAIR, ULCFRANGE, ULCF2STRREP|ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},	//general comment//~v54AI~
				{ULCCMDEXCLUDE,ULCTNOPAIR, ULCFRANGE|ULCFRGNOREP|ULCFBROWSE,0,NULLINIT1},	//exclude//~v54AR~
//  			{ULCCMDINCLUDE,ULCTNOPAIR, ULCFBROWSE|ULCFRANGE,ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},//diaply all excluded//~v67XR~
    			{ULCCMDINCLUDE,ULCTNOPAIR, ULCFBROWSE|ULCFRANGE|ULCFRGNOREP,ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},//diaply all excluded//~v67XI~
				{ULCCMDINCF,ULCTNOPAIR, ULCFBROWSE,0,NULLINIT1},  	//first    //~v0i0R~
				{ULCCMDINCL,ULCTNOPAIR, ULCFBROWSE,0,NULLINIT1},  	//last     //~v0i0R~
//  			{'I',ULCTNOPAIR},			//insert               //~v50sR~
    			{'I',ULCTNOPAIR, ULCFRANGE,0,NULLINIT1},			//insert,allow II//~v50sI~
				{ULCCMDLABEL,ULCTLABEL,0,ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},				//insert//~v0i0R~
				{'=',ULCTSAMEPAIR,ULCFRANGE|ULCFRGNOREP|ULCFBROWSE,0,NULLINIT1},////~v0k3I~
				{ULCCMDEXEC,ULCTNOPAIR,ULCFBROWSE|ULCFRANGE|ULCFRGNOREP,ULCF2STRREP|ULCF2NOSKIP|ULCF2NOBAND,NULLINIT1},	//delete//~v62JR~
				{ULCCMDUPPER,ULCTNOPAIR,ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//upper case translation//~v69LR~
				{ULCCMDLOWER,ULCTNOPAIR,ULCFRANGE|ULCFRGNOREP,0,NULLINIT1},	//lower case translation//~v74MI~
				{0,0,0,0,NULLINIT1}};				//terminator
static	ULCMD Slcmd[MAXCMDLINE];	//result of line cmd inmput
static	int   Scmdno;           	//cmd count
static	PULINEH Scsrplh;		//latest err plh                   //~v0hyI~
//**************
void lcmdhelp(void);                                               //~v41fI~
int otherclient(PUCLIENTWE Ppcwc,PUCLIENTWE Ppcwo);
int savependlcmd(PUCLIENTWE Ppcw,ULCMD *Pplc,int Pctr);
int callsingle(PUCLIENTWE Ppcw,ULCMD *Pplc);
int callpair(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd);
int callpairs(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd);          //~v0k3I~
int resultset(int Prc,ULCMD *Pplcc,ULCMD *Pplcd);
int lcmdproc(PUCLIENTWE Ppcw);
int getlinecmd(int Pbrowseid,PULINEH Pplh,ULCMD *Pplcmd,int Plinenosz);//~v069R~
int lcmderr(PULINEH Pplh);				//errlcmd interface        //~v0hyR~
//****************************************************************
// linecmd process
//*rc   :0
//****************************************************************
int filelinecmd(PUCLIENTWE Ppcw)
{
	PUFILEC pfc;
	PUFILEH pfh;                                                //~v03uI~
	PULINEH plh;
	ULCMD   *plc;
	int i,rc,delctr=0;                                          //~v055R~
    int linenosz;                                               //~v069I~
//********************	
    linenosz=Ppcw->UCWlinenosz;                                 //~v069R~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;                                            //~v03uI~
//first format chk
	Scmdno=pfh->UFHcmdlinectr;                                  //~v03uR~
	UTRACEP("@@@1 %s:cmdlinectr=%d\n",UTT,pfh->UFHcmdlinectr);     //~vah0I~
	Scsrplh=0;		//latest err plh                               //~v0hyI~
	for (i=0,plc=Slcmd;i<Scmdno;i++,plc++)
	{
		plh=pfh->UFHcmdline[i];                                 //~v03uR~
        if (!plh)	//deleted by shft+Del                       //~v055I~
        {                                                       //~v055I~
        	delctr++;                                           //~v055I~
            plc--;                                              //~v055I~
        	continue;                                           //~v055I~
		}                                                       //~v055I~
		if (getlinecmd(UCBITCHK(pfc->UFCflag,UFCFBROWSE),plh,plc,linenosz))//~v069R~
        {                                                          //~v11nI~
//  		UTRACEP("getlinecmd err:cmdid=%c\n",plc->ULCcmd);      //~v11qR~
			resultset(4,plc,0);
		}                                                          //~v11nI~
        UTRACEP("@@@1 %s:i=%d/%d ULHlinecmd=%s\n",UTT,i,Scmdno,plh->ULHlinecmd);//~vah0R~
		plc->ULCplh=plh;                                        //~5311M~
		plc->ULCindex=i;
		plc->ULCsplitid=Ppcw->UCWsplitid;	//chk at lcmdmove   //~5114I~
	}
    Scmdno-=delctr;	//deleted                                   //~v055I~
  	qsort(Slcmd,(UINT)Scmdno,sizeof(ULCMD),lcmdlinenocomp); //sort by lineno//~v0hxR~
	lcmdproc(Ppcw);
//*copy pending lcmd to malloc area for file copy cmd etc
	rc=savependlcmd(Ppcw,Slcmd,Scmdno);

	if (rc==1)		//commnad pending 
		rc=max(rc,otherclient(Ppcw,scrgetcw(-1)));//process both client
//  if (linenosz<=ULHLINENOSZ1)                                       //~v06dR~
//  {                                                                 //~v06dR~
//  	uerrmsg("Line number must be displayed",                      //~v06dR~
//  			"行番号表示が必要です");                              //~v06dR~
//  	rc=4;                                                         //~v06dR~
//  }                                                                 //~v06dR~
	if (rc>=4)		//cmd err
    {	                                                           //~v0hyI~
    	if (!Scsrplh)                                              //~v0hyI~
        	Scsrplh=pfh->UFHcmdline[0];                            //~v0hyR~
//  	filesetcsr(Ppcw,pfh->UFHcmdline[0],0,0);//top line of err/pend,fldtop//~v0hyR~
    	filesetcsr(Ppcw,Scsrplh,0,0);//last err line               //~v0hyI~
//      UTRACEP("filelinecmd:rc=%d\n",rc);                         //~v11qR~
	}                                                              //~v0hyI~
//  else                                                        //~5122R~
//  	rc=0;                                                   //~5122R~
	return rc;
}//filelinecmd
	
//****************************************************************
// savependlcmd
//*save pending lcmd
//*parm1  :PUFILEC tobe saved
//*parm2  :process completed ULCMD start addr
//*parm3  :ULCMD count
//*rc   :
//****************************************************************
int savependlcmd(PUCLIENTWE Ppcw,ULCMD *Pplc,int Pctr)
{
	PUFILEC pfc;
	PUFILEH pfh;                                                //~v03uI~
	PULINEH plh;
	ULCMD   *plcpend,*plc;
	int i,j,rc;
    int erractsw=0;		//err plh active                           //~v0hyI~
//*********************	
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;                                            //~v03uI~
	if (!pfh->UFHpvlcmd)	//first time                        //~v03uR~
    {                                                           //~v04dI~
		pfh->UFHpvlcmd=UALLOCM(ULCMDSZ*MAXCMDLINE);             //~v04dR~
        UALLOCCHK(pfh->UFHpvlcmd,8);    //return if malloc err  //~v04dI~
    }                                                           //~v04dI~
	plcpend=pfh->UFHpvlcmd;	//pending cmd ULCMD save area       //~v03uR~
	pfh->UFHpendctr=0;				//clear pending lcmd        //~v03uR~
	rc=0;
	for (i=0,j=0,plc=Pplc;i<Pctr;i++,plc++)
	{
		plh=plc->ULCplh;
        if (!plh)               //deleted line                     //~v724R~
            continue;                                              //~v724R~
		UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line
      if (plc->ULCtype!=ULCTLABEL)                                 //~v0hxI~
		if (UCBITCHK(plc->ULCflag,ULCFCOMP)                     //~v06hR~
    	||  UCBITCHK(plh->ULHflag3,ULHF3TEMPLCMD)) //by xecap Alt+a//~v06hI~
		{
            UTRACEP("@@@1 %s:COMP or TEMPLCMD reset ULHFLINECMD ULHlinecmd=%s,ULHflag=%x,ULHflah3=%x\n",UTT,plh->ULHlinecmd,plh->ULHflag,plh->ULHflag3);//~vah0M~
			UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);
			memset(plh->ULHlinecmd,0,ULHLINENOSZ);
			continue;
		}
    if (!UCBITCHK(plc->ULCflag3,ULCF3PEND_EXC))                    //~vb87I~
    {                                                              //~vb87I~
		UCBITON(plh->ULHflag,ULHFLCMDERR);		//for csr set at xefile2
      if (plc->ULCtype!=ULCTLABEL)                                 //~v0hxI~
      {                             //not label                    //~v0hxI~
    	if (UCBITCHK(plc->ULCflag,ULCFPEND|ULCFRPEND))          //~v03wR~
    	{                                                       //~v03wR~
			if (UCBITCHK(plc->ULCflag,ULCFRPEND))
				rc=max(2,rc);
			else
				rc=max(1,rc);
		}
		else
			rc=4;
        if (plh->ULHtype==ULHTDMYLCMD)                          //~v04fM~
        {                                                       //~v06hI~
            pfc->UFCpendfcmd=plc->ULCcmd;                       //~v06hI~
            continue;                                           //~v04fM~
        }                                                       //~v06hI~
      }                             //not label                    //~v0hxI~
    }                                                              //~vb87I~
		pfh->UFHpendctr++;				//countup pending lcmd  //~v04fM~
		plc->ULCsplitid=Ppcw->UCWsplitid;	//chk at lcmdmove   //~v04fM~
		memcpy(plcpend++,plc,ULCMDSZ);	//save for file cmd proc//~v04fM~
		pfh->UFHcmdline[j++]=plh;                               //~v03uR~
        UTRACEP("@@@1 %s:pending cmd jj=%d,plhlinecmd=%s\n",UTT,j,plh->ULHlinecmd);//~vah0R~
        if (plh==Scsrplh)                                          //~v0hyI~
        	erractsw=1;                                            //~v0hyI~
	}
	pfh->UFHcmdlinectr=j;                                       //~v03uR~
    UTRACEP("@@@1 %s:UFHcmdlinectr=%d\n",UTT,j);                   //~vah0R~
	UCBITON(pfh->UFHflag2,UFHF2LCMDCOMP); //processed           //~v03uR~
    if (!erractsw)                                                 //~v0hyI~
    	Scsrplh=0;			//no set csr                           //~v0hyI~
	return rc;
}//savependlcmd
//**************************************************************** //~vah0I~
//*save pending lcmd on other client                               //~vah0I~
//*return newpendctr                                               //~vah0I~
//**************************************************************** //~vah0I~
int savependlcmd_other(PUCLIENTWE Ppcw)                            //~vah0I~
{                                                                  //~vah0I~
	PUFILEC pfc;                                                   //~vah0I~
	PUFILEH pfh;                                                   //~vah0I~
	PULINEH plh,*pplh;                                             //~vah0I~
	ULCMD   *plc,*newplc;                                          //~vah0I~
	int ii,jj,pendctr,cmdlinectr,newpendctr;                       //~vah0R~
//*********************                                            //~vah0I~
	pfc=Ppcw->UCWpfc;                                              //~vah0I~
	pfh=pfc->UFCpfh;                                               //~vah0I~
	pendctr=pfh->UFHpendctr;				//clear pending lcmd   //~vah0I~
    if (!pendctr)                                                  //~vah0I~
    	return 0;                                                  //~vah0R~
	newplc=plc=(ULCMD*)pfh->UFHpvlcmd;	//!=null because pndctr!=0 //~vah0I~
    cmdlinectr=pfh->UFHcmdlinectr;                                 //~vah0I~
    UTRACEP("@@@1 %s:UFHcmdlinectr=%d\n",UTT,cmdlinectr);          //~vah0R~
    pplh=pfh->UFHcmdline;                                          //~vah0I~
    newpendctr=0;                                                  //~vah0I~
	for (ii=0;ii<pendctr;ii++,plc++)                               //~vah0I~
	{                                                              //~vah0I~
		plh=plc->ULCplh;                                           //~vah0I~
        if (!plh)               //deleted line                     //~vah0I~
            continue;                                              //~vah0I~
        for (jj=0;jj<cmdlinectr;jj++)                              //~vah0I~
        	if (plh==pplh[jj])                                     //~vah0I~
            	break;                                             //~vah0I~
        if (jj>=cmdlinectr)    //deleted                           //~vah0I~
        	continue;                                              //~vah0I~
		memcpy(newplc,plc,ULCMDSZ);	//save for file cmd proc       //~vah0I~
        newpendctr++;                                              //~vah0I~
	    UTRACEP("@@@1 %s:newpendctr=%d\n",UTT,newpendctr);         //~vah0R~
	    UTRACED("@@@1 newplc",newplc,ULCMDSZ);                     //~vah0I~
        newplc++;                                                  //~vah0I~
	}                                                              //~vah0I~
	pfh->UFHpendctr=newpendctr;				//clear pending lcmd   //~vah0I~
	return newpendctr;                                             //~vah0I~
}//savependlcmd_other                                              //~vah0I~
                                                                   //~v0hmI~
//**************************************************************** //~v0hmI~
// lcmdreset                                                       //~v0hmI~
//*clear pending lcmd by reset key                                 //~v0hmI~
//*parm1  :pcw                                                     //~v0hmI~
//*parm2  :pfh                                                     //~v0hmI~
//*rc     :reset cmdno                                             //~v0hmI~
//**************************************************************** //~v0hmI~
//int lcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh)                      //~v69WR~
int lcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt)               //~v69WI~
{                                                                  //~v0hmI~
	int ii,cmdno;                                                  //~v0hmI~
    int lcmdleft=0,resetctr=0;                                     //~v69WR~
    PULINEH plh,*pplh;                                             //~v0hmI~
//*********************                                            //~v0hmI~
	Ppfh->UFHpendctr=0;				//clear pending lcmd           //~v0hmI~
	cmdno=Ppfh->UFHcmdlinectr;                                     //~v0hmR~
	UTRACEP("@@@1 %s:cmdlinectr=%d\n",UTT,Ppfh->UFHcmdlinectr);    //~vah0I~
	pplh=Ppfh->UFHcmdline;                                         //~v0hmI~
	for (ii=0;ii<cmdno;ii++,pplh++)                                //~v0hmI~
    {                                                              //~v0hmI~
		plh=*pplh;                                                 //~v0hmI~
        if (!plh)                                                  //~v0idI~
            continue;                                              //~v0idI~
        if (!(Popt & LCMDRESETLABEL)                               //~v69WI~
        &&   *plh->ULHlinecmd==ULCCMDLABEL)                        //~v69WR~
        {                                                          //~v69WI~
        	lcmdleft++;                                            //~v69WI~
		    UTRACEP("@@@1 %s:LABEL lcmdleft=%d\n",UTT,lcmdleft);   //~vah0R~
        	continue;                                              //~v69WR~
        }                                                          //~v69WI~
        *pplh=0;                                                   //~v69WI~
        resetctr++;                                                //~v69WI~
		UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line      //~v0hmI~
        UTRACEP("@@@1 %s:before reset ULHFLINECMD ulhflag=%x,ULHlinecmd=%s\n",UTT,plh->ULHflag,plh->ULHlinecmd);//~vah0I~
		UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);            //~v0hmI~
		memset(plh->ULHlinecmd,0,ULHLINENOSZ);                     //~v0hmI~
	}                                                              //~v0hmI~
  if (!lcmdleft)                                                   //~v69WI~
  {                                                                //~v69WI~
	Ppfh->UFHcmdlinectr=0;                                         //~v0hmR~
	UCBITON(Ppfh->UFHflag2,UFHF2LCMDCOMP); //processed             //~v0hmR~
	UTRACEP("@@@1 %s:lcmdleft ctr=%d\n",UTT,lcmdleft);             //~vah0R~
  }                                                                //~v69WI~
//reset ULHF3ERRLINE                                               //~v118I~
    for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v118I~
		if (UCBITCHK(plh->ULHflag3,ULHF3ERRLINE))                  //~v118I~
        {	                                                       //~v118I~
			UCBITOFF(plh->ULHflag3,ULHF3ERRLINE);                  //~v118I~
			UCBITON(plh->ULHflag,ULHFDRAW);                        //~v118I~
        }                                                          //~v118I~
//  return cmdno;                                                  //~v69WR~
    return resetctr;                                               //~v69WI~
}//lcmdreset                                                       //~v0hmI~
//****************************************************************
// otherclient
//*process lcmd paired with other client 
//*rc   :0
//****************************************************************
int otherclient(PUCLIENTWE Ppcwc,PUCLIENTWE Ppcwo)
{
	PUFILEH pfhc,pfho;                                          //~v03uR~
	ULCMD   *plc,*plco;
    int newpendctr;                                                //~vah0I~
	int rc;                                                     //~v03wR~
//*********************	
	if (!Ppcwo || Ppcwo->UCWtype!=UCWTFILE)
		return 0;		//no split status or not file client
	pfhc=((PUFILEC)Ppcwc->UCWpfc)->UFCpfh;	//my client .       //~v03uR~
	pfho=((PUFILEC)Ppcwo->UCWpfc)->UFCpfh;	//other client .    //~v03uR~
    if (pfhc==pfho)    //same file                              //~v03uI~
		return 0;		//no need process                       //~v03uI~
	if (!UCBITCHK(pfho->UFHflag2,UFHF2LCMDCOMP) //not yet processed//~v03uR~
	||  !pfho->UFHpendctr)	//no pending commnad line           //~v03uR~
    {                                                              //~vb84I~
	    if (!UCBITCHK(pfho->UFHflag2,UFHF2LCMDCOMP) //not yet processed//~vb84I~
		&& pfho->UFHcmdlinectr)                                    //~vb84I~
			uerrmsg("Pending line cmd on another screen, Enter-key is required there.",//~vb84I~
					"もう一方の画面に未評価の行コマンドがあります、そちらでも実行キー入力が必要です");//~vb84R~
		return 0;	//need change active client and process
    }                                                              //~vb84I~
    newpendctr=savependlcmd_other(Ppcwo);                          //~vah0I~
    if (!newpendctr)                                               //~vah0I~
		return 0;	//need change active client and process        //~vah0I~
//*combine 2 pending commnad
	plc=Slcmd;
//	memcpy(plc,pfhc->UFHpvlcmd,(UINT)ULCMDSZ*pfhc->UFHpendctr); //~v03uR~//~vb30R~
  	memcpy(plc,pfhc->UFHpvlcmd,ULCMDSZ*(size_t)pfhc->UFHpendctr);  //~vb30I~
    UTRACED("@@@1 Slcmd",plc,(int)ULCMDSZ*pfhc->UFHpendctr);            //~vah0I~//~vb30R~
	plco=plc+=pfhc->UFHpendctr;	//for other current             //~v03uR~
//  memcpy(plc,pfho->UFHpvlcmd,(UINT)ULCMDSZ*pfho->UFHpendctr);//other//~v03uR~//~vb30R~
    memcpy(plc,pfho->UFHpvlcmd,ULCMDSZ*(size_t)pfho->UFHpendctr);//other//~vb30I~
    UTRACED("@@@1 for other client",plc,(int)ULCMDSZ*pfho->UFHpendctr); //~vah0I~//~vb30R~
	Scmdno=pfhc->UFHpendctr+pfho->UFHpendctr;                   //~v03uR~
    UTRACEP("@@@1 %s:Scmdno=%d\n",UTT,Scmdno);                     //~vah0I~
//  if (pfhc->UFCpfh==pfco->UFCpfh)	//same file                 //~v03uR~
//    	qsort(Slcmd,(UINT)Scmdno,sizeof(ULCMD),lcmdlinenocomp);//sort//~v0hxR~
	lcmdproc(Ppcwc);
	scrfulldraw(Ppcwc);                                         //~5126I~
	if ((rc=savependlcmd(Ppcwo,plco,pfho->UFHpendctr))>=4)      //~v03wR~
		uerrmsg("Error on another screen",                      //~v03wI~
				"もう一方の画面に誤りあり");                    //~v03wI~
	rc=max(rc,savependlcmd(Ppcwc,Slcmd,pfhc->UFHpendctr));      //~v03uR~
	return rc;
}//otherclient
//**************************************************************** //~v724R~
// lcmdclearcmdplc                                                 //~v724R~
//   clear registered cmd by the reason of del line or exclude cmd //~v724R~
//*parm1:plh                                                       //~v724R~
//*rc 0:cleared,4:not found plh                                    //~v724R~
//**************************************************************** //~v724R~
int lcmdclearlcmdplc(PULINEH Pplh)                                 //~v724R~
{                                                                  //~v724R~
	int ii,rc=4;                                                   //~v724R~
	ULCMD   *plc;                                                  //~v724R~
//************************                                         //~v724R~
	for (ii=0;ii<Scmdno;ii++)                                      //~v724R~
	{                                                              //~v724R~
		plc=Slcmd+ii;                                              //~v724R~
		if (plc->ULCplh==Pplh)                                     //~v724R~
        {                                                          //~v724R~
			plc->ULCplh=0;                                         //~v724R~
            rc=0;                                                  //~v724R~
        }                                                          //~v724R~
    }                                                              //~v724R~
	return rc;                                                     //~v724R~
}//lcmdclearlcmdplc                                                //~v724R~
//****************************************************************
// linecmd process
//*rc   :0
//****************************************************************
int lcmdproc(PUCLIENTWE Ppcw)
{
	ULCMD   *plc,*plcn=0,*plcp=0,*plcr=0;
	ULCMD   *plcs=0;                                               //~v0k3I~
	int i;
    int rc;                                                        //~v0k3I~
    PULINEH plh;                                                   //~vb87I~
//*********************	
	for (i=0;i<Scmdno;i++)
	{
		plc=Slcmd+i;
//  	if (!(plc->ULCplh))	//deleted                              //~v724R~//~vb87R~
    	if (!(plh=plc->ULCplh))	//deleted                          //~vb87I~
			continue;                                              //~v724R~
        if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//ignore excuded//~vb87I~
        {                                                          //~vb87I~
			UCBITON(plc->ULCflag3,ULCF3PEND_EXC);                  //~vb87R~
			continue;                                              //~vb87I~
        }                                                          //~vb87I~
		if (UCBITCHK(plc->ULCflag,ULCFERR))	//already err detected
			continue;
		if (UCBITCHK(plc->ULCflag,ULCFRANGEREQ))	//2 byte cmd
		{
			if (!plcr)	//range not yet started
			{
				plcr=plc;		//range start
				continue;		//process next cmd
			}
			plcr->ULCplcrange=plc;
			plc ->ULCplcrange=plcr;

			if (plcr->ULCcmd!=plc->ULCcmd)//not same cmd
				return resultset(4,plc,0);
			plcr=0;
		}//range cmd

		switch(plc->ULCtype)	//pair cmd?
		{
		case ULCTNOPAIR:
			if (callsingle(Ppcw,plc))
				return 4;
			break;
		case ULCTPOSCMD:	//pair cmd dest
			if (plcr)		//range pending
  				return resultset(1,plcr,plc);  //1:avoid csr fix on err//~5129R~
			if (plcn)
			{
				if (callpair(Ppcw,plcn,plc))	//need and pos cmd
					return 4;
				plcn=0;
			}
			else
            {                                                   //~5315I~
                if (plcp)                                       //~5315I~
                {                                                  //~v0hkI~
//  				return resultset(4,plc,0);                     //~v0hkR~
//    				resultset(1,plcp,0);  //set pending and continue//~v0hxR~
    				return resultset(4,plc,0);                     //~v0hxI~
				}                                                  //~v0hkI~
				plcp=plc;
			}                                                   //~5315I~
			break;
		case ULCTNEEDPOS:	//pair cmd
			if (plcr)		//range pending
	  			return resultset(1,plcr,plc);   //rc=1 move csr //~5129R~
			if (plcp)	//pos cmd already detected
			{
				if (callpair(Ppcw,plc,plcp))	//need and pos cmd
					return 4;
				plcp=0;	//pos cmd processed
			}
			else		//not yet pos cmd found
				plcn=plc;	//for next pos cmd
			break;
		case ULCTSAMEPAIR:	//pair with same cmd                   //~v0k3I~
			if (plcr)		//range pending                        //~v0k3I~
  				return resultset(1,plcr,plc);  //1:avoid csr fix on err//~v0k3I~
			if (plcs)                                              //~v0k3I~
			{                                                      //~v0k3I~
//                if ( plcs->ULCplcrange && !plc->ULCplcrange      //~v0k3R~
//                ||  !plcs->ULCplcrange &&  plc->ULCplcrange)     //~v0k3R~
//                    return resultset(4,plc,plcs);   //range and not range//~v0k3R~
				if (rc=callpairs(Ppcw,plcs,plc),rc)	//need same pair//~v0k3R~
					return rc;                                     //~v0k3R~
				plcs=0;                                            //~v0k3I~
			}                                                      //~v0k3I~
			else                                                   //~v0k3I~
				plcs=plc;                                          //~v0k3I~
			break;                                                 //~v0k3I~
		}//switch by type
	}//all line cmd
	if (plcr)		//range pendisg
		UCBITON(plcr->ULCflag,ULCFRPEND);

	if (plcp)
    {                                                              //~v0hoI~
		UCBITON(plcp->ULCflag,ULCFPEND);
		if (plcr=plcp->ULCplcrange,plcr)	//range pair exist     //~v0hoI~
			UCBITON(plcr->ULCflag,ULCFPEND);//to save entry        //~v0hoI~
    }                                                              //~v0hoI~
	if (plcn)		//pos cmd not found(need cmd ptr pending)
	{
		UCBITON(plcn->ULCflag,ULCFPEND);
		if (plcr=plcn->ULCplcrange,plcr)	//range pair exist
			UCBITON(plcr->ULCflag,ULCFPEND);//to save entry
	}
	if (plcs)		//paendin "="                                  //~v0k3I~
	{                                                              //~v0k3I~
		UCBITON(plcs->ULCflag,ULCFPEND);                           //~v0k3I~
		if (plcr=plcs->ULCplcrange,plcr)	//range pair exist     //~v0k3I~
			UCBITON(plcr->ULCflag,ULCFPEND);//to save entry        //~v0k3I~
	}                                                              //~v0k3I~

	return 0;	
}//lcmdproc
//********************************************************************
//*call lcmdsingle
//********************************************************************
int callsingle(PUCLIENTWE Ppcw,ULCMD *Pplc)
{
	int rc=0;
//*************
	if (Pplc->ULCcmd)		//not null cmd
		rc=lcmdsingle(Ppcw,Pplc);
//  if (rc>=4)                                                     //~v11qR~
//  	UTRACEP("single lcmd:rc=%d,cmdid=%c\n",rc,Pplc->ULCcmd);   //~v11qR~
	return resultset(rc,Pplc,0);
}//callsingle
//********************************************************************
//*call lcmdpair
//********************************************************************
int callpair(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd)
{
	int rc;
//  PUFILEH pfh;                                                   //~v0hxR~
//*************
//    pfh=UGETPFH(Pplcd->ULCplh);                                  //~v0hxR~
//  if (!pfh->UFHeditpcw) //not opened by edit                     //~v0hxR~
//    rc=errbrowsemode();                                          //~v0hxR~
//  else                                                           //~v0hxR~
	rc=lcmdpair(Ppcw,Pplcc,Pplcd);
//  if (rc>=4)                                                     //~v11qR~
//  	UTRACEP("pair lcmd:rc=%d,cmdid=%c+%c\n",rc,Pplcc->ULCcmd,Pplcd->ULCcmd);//~v11qR~
	return resultset(rc,Pplcc,Pplcd);
}//callpair

//********************************************************************//~v0k3I~
//*call lcmdpair with same cmdid                                   //~v0k3I~
//********************************************************************//~v0k3I~
int callpairs(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd)           //~v0k3I~
{                                                                  //~v0k3I~
	int rc;                                                        //~v0k3I~
//*************                                                    //~v0k3I~
	rc=lcmdpairs(Ppcw,Pplcc,Pplcd);                                //~v0k3I~
	return resultset(rc,Pplcc,Pplcd);                              //~v0k3I~
}//callpairs                                                       //~v0k3I~
                                                                   //~v0k3I~
//********************************************************************
//*cmd process result chk
//*parm1:rc
//*parm2:singlecmd
//*parm3:pair dest cmd
//*retrn:same as input r.c
//********************************************************************
int resultset(int Prc,ULCMD *Pplcc,ULCMD *Pplcd)
{	
	ULCMD *plcr;
	UCHAR result;                                               //~5129I~
//*************
	plcr=Pplcc->ULCplcrange;
	switch(Prc)                                                 //~5129I~
	{                                                           //~5129I~
	case 0:                                                     //~5129I~
		result=ULCFCOMP;                                        //~5129I~
		break;                                                  //~5129I~
	case 1:                                                     //~5129I~
		result=ULCFPEND;                                        //~5129I~
		break;                                                  //~5129I~
	default:                                                    //~5129I~
		result=ULCFERR;                                         //~5129I~
		break;                                                  //~5129I~
	}                                                           //~5129I~
	UCBITON(Pplcc->ULCflag,result);                             //~5129R~
	if (plcr)                                                   //~5129R~
		UCBITON(plcr->ULCflag,result);                          //~5129R~
	if (Pplcd)                                                  //~5129R~
    {                                                              //~v0hoI~
		UCBITON(Pplcd->ULCflag,result);                         //~5129R~
		plcr=Pplcd->ULCplcrange;                                   //~v0hoI~
        if (plcr)       //dest is range                            //~v0hoI~
			UCBITON(plcr->ULCflag,result);                         //~v0hoI~
    }                                                              //~v0hoI~
	return Prc;
}//resultset
//********************************************************************
//*getlinecmd
//* get line cmd text(drop preceding space) and return length
//* parm1 :pcw
//* parm2 :plh                                                  //~5311R~
//* parm3 :ULCMD structure addr
//* retrn :0:ok,4 err cmd
//********************************************************************
int getlinecmd(int Pbrowseid,PULINEH Pplh,ULCMD *Pplcmd,int Plinenosz)//~v069R~
{
//  PUCLIENTWE pcw;                                             //~v03uI~,//~v097R~
	int i,j,cmdlen,repeat=0;
    int kk,ll,bssw1=0,bssw2=0,bandle=0,skip=0;                     //~v75aR~
    int cidopt=0;                                                  //~va07I~
    int swbinmode=0;                                               //~va7xI~
	UCHAR cmdid;
	UCHAR *pc,*inplcmd;                                         //~5311R~
	UCHAR *pcls;		//last space pos;                          //~v0hxI~
	ULCMD *plc;
	UCHAR wk[ULHLINENOSZ];
	UCHAR wk1[ULHLINENOSZ];                                        //~v0i0I~
	UCHAR wk2[ULHLINENOSZ];                                        //~v0i0I~
//*****************

    inplcmd=Pplh->ULHlinecmd;                                   //~5311I~
	memset(Pplcmd,0,sizeof(ULCMD));
//  if (Plinenosz<=ULHLINENOSZ1)	//no input avail                  //~v06dR~
//  	return 0;		//same as cmdlen=0                            //~v06dR~
//drop preceding space
	for (i=0,pc=inplcmd;i<ULHLINENOSZ-1;i++,pc++)                     //~v06dR~
		if (*pc!=' ')
			break;
//get command verb
	strncpy(inplcmd,pc,ULHLINENOSZ);                            //~5311R~
	pc=inplcmd;						//new top                   //~5311R~
    pcls=0;                                                        //~v0hxI~
	for (cmdlen=0;i<ULHLINENOSZ-1;i++,pc++)                           //~v06dR~
	{
		if (!*pc)
			break;
		if (*pc==' ')
        {                                                          //~v0hxI~
        	if (!pcls)                                             //~v0hxI~
            	pcls=pc;		//trailing space start             //~v0hxI~
			continue;
		}                                                          //~v0hxI~
        pcls=0;					//prev space is intermediate       //~v0hxR~
      if (*inplcmd!=ULCCMDLABEL)        //not label cmd            //~v0hxI~
//  	if (*pc>='0' && *pc<='9')                                  //~v0i0R~
    	if ((*pc>='0' && *pc<='9')                                 //~v0i0R~
        ||  (*pc==REPDELM1 && cmdlen>=1)                           //~v0i0R~
        ||  (*pc==REPDELM2 && cmdlen>=1))                          //~v0i0R~
		{
			repeat=1;
			break;
		}
		wk[cmdlen++]=(UCHAR)toupper(*pc);
	}
	if (!cmdlen)
		return 0;
	wk[cmdlen]=0;                                                  //~va07I~
    if (pcls)                                                      //~v0hxI~
		*pcls=0;		//drop trailing space for label compare    //~v0hxR~
//  if (cmdlen!=1)                                                 //~v0asR~
//  	if (cmdlen!=2 || wk[0]!=wk[1])                             //~v0asR~
//  		return lcmderr(Pplh);				//cmd err          //~v0hyR~
//chk command verb
  	if  (wk[0]==ULCCMDAFTER||wk[0]==ULCCMDBEFORE)                  //~va7xI~
  	{                                                              //~va7xI~
  		if (wk[1]==ULCCMDBIN)         //"AB","BB"                  //~va7xI~
    		swbinmode=1;                                           //~va7xI~
  	}                                                              //~va7xI~
  	else                                                           //~va7xI~
  	if  (wk[0]=='=')                                               //~va7xR~
  	{                                                              //~va7xI~
  		if (wk[1]==ULCCMDBIN)         //"=B"                       //~va7xI~
    		swbinmode=1;                                           //~va7xI~
        else                                                       //~va7xI~
  		if (wk[1]=='=' && wk[2]==ULCCMDBIN)         //"==B"        //~va7xI~
    		swbinmode=2;                                           //~va7xI~
  	}                                                              //~va7xI~
    if (swbinmode)                                                 //~va7xI~
    {                                                              //~va7xI~
    	cmdlen--;		//drop "B"inmode                           //~va7xR~
    	strcpy(wk+swbinmode,wk+swbinmode+1);                       //~va7xI~
    }                                                              //~va7xI~
  if (wk[0]=='T' && wk[1]=='F')                                    //~v75aR~
  {                                                                //~v75aI~
  	cmdid=ULCCMDTFLOWSTR;                                          //~v75aI~
    cmdlen=1;		//single cmd                                   //~v75aI~
  }                                                                //~v75aI~
  else                                                             //~v75aI~
  if (wk[0]=='T' && wk[1]=='S')                                    //~v75bI~
  {                                                                //~v75bI~
  	cmdid=ULCCMDTSSTR;                                             //~v75bI~
    cmdlen=1;		//single cmd                                   //~v75bI~
  }                                                                //~v75bI~
  else                                                             //~v75bI~
  if (wk[1]==ULCCMDCIDOPT                                          //~va07R~
  &&  (wk[0]==ULCCMDAFTER || wk[0]==ULCCMDBEFORE)                  //~va07I~
  )                                                                //~va07I~
  {                                                                //~va07I~
    cmdlen--;		//single cmd                                   //~va07I~
    strcpy(wk+1,wk+2);                                             //~va07R~
    cidopt=1;                                                      //~va07I~
	cmdid=wk[0];                                                   //~va07I~
  }                                                                //~va07I~
  else                                                             //~va07I~
	cmdid=wk[0];
	for(plc=Scmdlist;plc->ULCcmd;plc++)
		if (cmdid==plc->ULCcmd)
			break;
	if (!plc->ULCcmd)
    {                                                              //~v41fI~
//  	return lcmderr(Pplh);				//cmd err              //~v41fR~
    	lcmderr(Pplh);				//cmd err                      //~v41fI~
    	lcmdhelp();				//display valid cmd                //~v41fR~
        return 4;                                                  //~v41fI~
    }                                                              //~v41fI~
                                                                   //~v0asI~
  if (plc->ULCtype==ULCTLABEL)	//label                            //~v0hxI~
  {                                                                //~v0hxI~
    if (cmdlen==1)                  //no label                     //~v0hxI~
        return lcmderr(Pplh);				//cmd err              //~v0hyR~
    if (Pplh->ULHtype==ULHTEXCLUDE) //exclude hdr                  //~v0hGI~
    {                                                              //~v0hGI~
        lcmderr(Pplh);				//set csr                      //~v0hGI~
  		uerrmsg("Label not avail on excluded line",                //~v0hGI~
//				"非表示行にラベルは設定不可です");                 //~v0hGI~
    			"非\x95\\示行にラベルは設定不可です");             //~v0hGI~
		return 4;                                                  //~v0hGI~
    }                                                              //~v0hGI~
  }                                                                //~v0hxI~
  else                                                             //~v0hxI~
  {         //not label                                            //~v0hxI~
	if (UCBITCHK(plc->ULCflag2,ULCF2STRREP))	//rep is used as string//~v0asI~
    {                                                              //~v0asI~
    	if (cmdlen>=2)                                             //~v0asI~
        {                                                          //~v54AI~
			if (wk[0]==wk[1])                                      //~v0asI~
        		cmdlen=2;                                          //~v0asR~
			else                                                   //~v0asI~
            	cmdlen=1;                                          //~v0asI~
        }                                                          //~v54AI~
    	repeat=0;					//deny numeric repeat          //~v0asI~
	}                                                              //~v0asI~
    else                                                           //~v0asI~
        if (cmdlen!=1)                                             //~v0asI~
        	if (cmdlen!=2 || wk[0]!=wk[1])                         //~v0asI~
        		return lcmderr(Pplh);				//cmd err      //~v0hyR~
	
	if (Pbrowseid)
		if (!UCBITCHK(plc->ULCflag,ULCFBROWSE)	//not allowed at brosw//~5311R~
		&&  Pplh->ULHtype!=ULHTDMYLCMD)	//not dummy plh for repl/create cmd//~5311R~
		{
//  		if (!(pcw=scrgetcw(-1)) //other client not exist    //~v03uR~,//~v097R~
//          ||  pcw!=UGETPFH(Pplh)->UFHeditpcw)                 //~v03uI~,//~v097I~
//          {                                                   //~v03uI~,//~v097R~
//  			uerrmsg("Now Browse mode",                         //~v0hwR~
//  					"現在は 表示モードです");                  //~v095R~
//  					"現在は \x95\\示モードです");              //~v0hwR~
//  			return 4;                                          //~v0hwR~
                return errbrowsemode();                            //~v0hwI~
//          }                                                   //~v03uI~,//~v097R~
		}
  }         //not label                                            //~v0hxI~
	*Pplcmd=*plc;	//output
    if (cidopt)                                                    //~va07I~
		UCBITON(Pplcmd->ULCflag3,ULCF3CID);	//copy also cid        //~va07I~
    if (swbinmode)                                                 //~va7xI~
		UCBITON(Pplcmd->ULCflag3,ULCF3BIN);	//copy also cid        //~va7xI~

  if (plc->ULCtype!=ULCTLABEL)	//label                            //~v0hxI~
  {                                                                //~v0hxI~
	if (cmdlen==2)
    {                                                              //~v54AI~
		if (UCBITCHK(plc->ULCflag,ULCFRANGE))	//can be range
			UCBITON(Pplcmd->ULCflag,ULCFRANGEREQ);	//range req
		else
			return lcmderr(Pplh);				//cmd err          //~v0hyR~
    }//cmdlen=2                                                    //~v54AI~
//get repeat num

		if (repeat)	//number specified
	{	
		if (UCBITCHK(Pplcmd->ULCflag2,ULCF2NOREP))	//no count allowed//~5226I~
			return lcmderr(Pplh);				//cmd err          //~v0hyR~
        kk=0;                                                      //~v0i0I~
        ll=0;                                                      //~v0i0I~
//      bssw1=0;bssw2=0;                                           //~v75aR~
		for (j=0;i<ULHLINENOSZ-1;i++,pc++)                            //~v06dR~
		{
			if (!*pc || *pc==' ')
				break;
			if (*pc==REPDELM1)                                     //~v0i0I~
            {                                                      //~v0i0I~
            	if (bssw1)                                         //~v0i0R~
					return lcmderr(Pplh);				//cmd err  //~v0i0I~
            	bssw1=1;                                           //~v0i0I~
                continue;                                          //~v0i0I~
			}                                                      //~v0i0I~
            else                                                   //~v0i0I~
                if (*pc==REPDELM2)                                 //~v0i0I~
                {                                                  //~v0i0I~
                    if (bssw2)                                     //~v0i0I~
                        return lcmderr(Pplh);               //cmd err//~v0i0I~
                    bssw2=1;                                       //~v0i0I~
                    continue;                                      //~v0i0I~
                }                                                  //~v0i0I~
                else                                               //~v0i0I~
			if (*pc<'0' || *pc>'9')
				return lcmderr(Pplh);				//cmd err      //~v0hyR~
            if (bssw2)                                             //~v0i0I~
            	wk2[ll++]=*pc;                                     //~v0i0R~
            else                                                   //~v0i0I~
	            if (bssw1)                                         //~v0i0I~
    	        	wk1[kk++]=*pc;                                 //~v0i0R~
                else                                               //~v0i0I~
			wk[j++]=*pc;
		}
		wk[j]=0;
		wk1[kk]=0;                                                 //~v0i0I~
		wk2[ll]=0;                                                 //~v0i0I~
		repeat=atoi(wk);
		bandle=atoi(wk1);                                          //~v0i0R~
		skip=atoi(wk2);                                            //~v0i0I~
	}
	if (repeat && cmdlen==2)
		if (UCBITCHK(Pplcmd->ULCflag,ULCFRGNOREP))	//no rep when range
			return lcmderr(Pplh);				//cmd err          //~v0hyR~
//for pair edst cmd,should chk both enthtry,so move to lcmd3       //~v67TI~
//    if (!repeat)        //reset to 1 if 0 for dest cmd           //~v67TR~
//        if (Pplcmd->ULCtype==ULCTPOSCMD)                         //~v67TR~
//          if (!bandle)              //keep 0 for copy if bandle!=0//~v67TR~
//            repeat=1;                                            //~v67TR~
    if (repeat>MAXREPEAT)                                       //~v049I~
    {                                                           //~v049I~
#ifdef DOSDOS                                                      //~v69KI~
		uerrmsg("Max count is %d",                              //~v049I~
				"最大値は %d",                                  //~v049I~
				MAXREPEAT);                                     //~v049I~
		return 4;                                               //~v049I~
#else                                                              //~v69KI~
//		if (plc->ULCcmd!='D')	//delete cmd                       //~v69LR~
  		if (plc->ULCcmd!=ULCCMDUPPER	//delete cmd               //~v69LI~
  		&&  plc->ULCcmd!=ULCCMDLOWER    //lower  cmd               //~v74MI~
  		&&  plc->ULCcmd!=ULCCMDDELETE)  //delete cmd               //~v69LI~
        {                                                          //~v69KI~
//            uerrmsg("Max count is %d except for Delete cmd.",    //~v69LR~
//                    "Del コマンド以外の最大値は %d",             //~v69LR~
//          uerrmsg("Max count is %d except for Del/Upper cmd.",   //~v74MR~
//                  "Del/Upper コマンド以外の最大値は %d",         //~v74MR~
            uerrmsg("Max count is %d except for Del/Upper/Lower cmd.",//~v74MI~
                    "Del/Upper/Lower コマンド以外の最大値は %d",   //~v74MI~
					MAXREPEAT);                                    //~v69KI~
			return 4;                                              //~v69KI~
        }                                                          //~v69KI~
#endif                                                             //~v69KI~
	}                                                           //~v049I~
    if (skip || bandle)                                            //~v47jR~
    {                                                              //~v0i0I~
		if (UCBITCHK(Pplcmd->ULCflag2,ULCF2NOSKIP|ULCF2NOBAND))    //~v0i0R~
			return lcmderr(Pplh);				//cmd err          //~v0i0R~
		if (!UCBITCHK(Pplcmd->ULCflag,ULCFRANGEREQ))	//not range req//~v0i0I~
			if (UCBITCHK(Pplcmd->ULCflag2,ULCF2NOCNTSB))           //~v0i0R~
				return lcmderr(Pplh);				//cmd err      //~v0i0I~
	}                                                              //~v0i0I~
	if (UCBITCHK(plc->ULCflag3,ULCF3CNT0))	//allow 0 as specified value//~v75aR~
    {	                                                           //~v75aI~
    	if (!bssw1)                                                //~v75aI~
        	bandle=-1;  // not specified id                        //~v75aR~
    	if (!bssw2)                                                //~v75aI~
        	skip=-1;                                               //~v75aI~
    }                                                              //~v75aI~
	Pplcmd->ULCrepeat=repeat;
	Pplcmd->ULCband=bandle;                                        //~v0i0I~
	Pplcmd->ULCskip=skip;                                          //~v0i0I~
  }         //not label                                            //~v0hxI~
	return 0;
}//getlinecmd
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int lcmdlinenocomp(const void *Pent1,const void *Pent2)            //~v0hxR~
{
	long rc;
	PULINEH plh1,plh2;
//*****************
//	plh1=((ULCMD*)(ULONG)Pent1)->ULCplh;                           //~v54AR~//~vafkR~
	plh1=((ULCMD*)(ULPTR)Pent1)->ULCplh;                           //~vafkI~
//	plh2=((ULCMD*)(ULONG)Pent2)->ULCplh;                           //~v54AR~//~vafkR~
  	plh2=((ULCMD*)(ULPTR)Pent2)->ULCplh;                           //~vafkI~
	if (plh1->ULHtype==ULHTEXCLUDE)
		plh1=UGETQNEXT(plh1);
	if (plh2->ULHtype==ULHTEXCLUDE)
		plh2=UGETQNEXT(plh2);
	rc=plh1->ULHlinenor - plh2->ULHlinenor;
    if (rc<0)                                                   //~5428R~
        return -1;                                              //~5428I~
    else                                                        //~5428R~
    	if (rc>0)                                               //~5428I~
            return  1;                                          //~5428I~
	return (plh1->ULHsuffix - plh2->ULHsuffix);
}//lcmdlinenocomp                                                  //~v0hxR~
                                                                //~5223I~
//*******************************************************       //~5223I~
//* setup dummy ULCMD                                           //~5223I~
//*******************************************************       //~5223I~
ULCMD *lcmdgetdummyplc(PUCLIENTWE Ppcw,UCHAR Plcmd)             //~5223I~
{                                                               //~5223I~
static ULCMD  Sulcmd;                                           //~5223I~
//*************                                                 //~5223I~
	memset(&Sulcmd,0,sizeof(ULCMD));	//null clear            //~5223I~
	Sulcmd.ULCcmd=Plcmd;                                        //~5223I~
	Sulcmd.ULCtype=ULCTPOSCMD;                                  //~5223I~
	Sulcmd.ULCrepeat=1;                                         //~5223I~
	Sulcmd.ULCsplitid=Ppcw->UCWsplitid;                         //~5223I~
    return &Sulcmd;                                             //~5223I~
}                                                               //~5223I~
                                                                //~5223I~
////*******************************************************        //~v0hxR~
////* check "A"/"B" for find/change cmd range specification        //~v0hxR~
////*parm1:pfh                                                     //~v0hxR~
////*parm2:input:curr plc index,0 for first call                   //~v0hxR~
////*parm3:optional output plh ptr                                 //~v0hxR~
////*ret  :0:no range remain,1:indexed ULCMD is for 'A',2 for 'B'  //~v0hxR~
////*      if index==0 return -4:sequence err, -8:other cmd mixed  //~v0hxR~
////*******************************************************        //~v0hxR~
//int lcmdgetabplh(PUFILEH Ppfh,int Ppendindex,PULINEH *Ppplh)     //~v0hxR~
//{                                                                //~v0hxR~
//    ULCMD   *plcpend,*plcpend0;                                  //~v0hxR~
//    int pendctr,pendctr0,rangesw,rangectr,mixsw=0;               //~v0hxR~
////*************                                                  //~v0hxR~
//    if (Ppfh)                                                    //~v0hxR~
//    {                                                            //~v0hxR~
//        plcpend0=Ppfh->UFHpvlcmd;   //pending cmd ULCMD save area//~v0hxR~
//        pendctr0=Ppfh->UFHpendctr;      //no of pending          //~v0hxR~
//    }                                                            //~v0hxR~
//    else                                                         //~v0hxR~
//    {                                                            //~v0hxR~
//        plcpend0=Slcmd;         //pending cmd ULCMD save area    //~v0hxR~
//        pendctr0=Scmdno;        //no of pending                  //~v0hxR~
//    }                                                            //~v0hxR~
//    if (!Ppendindex)        //first time call                    //~v0hxR~
//    {                                                            //~v0hxR~
//        plcpend=plcpend0;                                        //~v0hxR~
//        pendctr=pendctr0;                                        //~v0hxR~
//        rangectr=0;                       //default not found    //~v0hxR~
//        for (rangesw=0;pendctr;pendctr--,plcpend++)              //~v0hxR~
//        {                                                        //~v0hxR~
//            if (plcpend->ULCcmd==ULCCMDAFTER)                    //~v0hxR~
//            {                                                    //~v0hxR~
//                if (rangesw)    //'A' --> 'A'                    //~v0hxR~
//                    return -4;                                   //~v0hxR~
//                rangesw=1;      //range start                    //~v0hxR~
//            }                                                    //~v0hxR~
//            else                                                 //~v0hxR~
//                if (plcpend->ULCcmd==ULCCMDBEFORE)               //~v0hxR~
//                {                                                //~v0hxR~
//                    if (rangesw)        //range started          //~v0hxR~
//                    {                                            //~v0hxR~
//                        rangesw=0;      //range end              //~v0hxR~
//                        rangectr++;           //range ctr        //~v0hxR~
//                    }                                            //~v0hxR~
//                    else                                         //~v0hxR~
//                        if (rangectr)                            //~v0hxR~
//                            return -4;  //'B'-->'B'              //~v0hxR~
//                        else            //first 'B'              //~v0hxR~
//                            rangectr++;           //range ctr    //~v0hxR~
//                }                                                //~v0hxR~
//                else                                             //~v0hxR~
//                    mixsw=1;                                     //~v0hxR~
//        }//pendctr loop                                          //~v0hxR~
//        if (rangesw)                                             //~v0hxR~
//            rangectr++;                                          //~v0hxR~
//        if (!rangectr)                                           //~v0hxR~
//            return 0;               //no range                   //~v0hxR~
//        if (mixsw)      //range and other pending                //~v0hxR~
//            return -8;                                           //~v0hxR~
//    }//first call                                                //~v0hxR~
//    if (Ppendindex>=pendctr0)   //reached to last                //~v0hxR~
//        return 0;   //ended                                      //~v0hxR~
//    plcpend=plcpend0+Ppendindex;                                 //~v0hxR~
//    if (Ppplh)                                                   //~v0hxR~
//        *Ppplh=plcpend->ULCplh;                                  //~v0hxR~
//    if (plcpend->ULCcmd==ULCCMDAFTER)                            //~v0hxR~
//        return 1;          //'A' cmd                             //~v0hxR~
//    return 2;              //'B' cmd                             //~v0hxR~
//}//lcmdgetabplh                                                  //~v0hxR~
                                                                   //~v0hxI~
//*******************************************************          //~v0hxI~
//* check label of find/change line range operand                  //~v0hxI~
//*parm1:pfh                                                       //~v0hxI~
//*parm2:entry no                                                  //~v0hxI~
//*parm3:label table                                               //~v0hxI~
//*parm4:output plh tbl                                            //~v0hxI~
//*parm5:plh seq on pend table(sorted by lineno)                   //~v0hyI~
//*ret  :0 ok 4:not found entry exist                              //~v0hxI~
//*******************************************************          //~v0hxI~
int lcmdgetabplh(PUFILEH Ppfh,int Pentno,                          //~v0hyR~
				UCHAR Plabtbl[][ULHLINENOSZ+1],PULINEH Pplht[],int Psortseq[])//~v0hyI~
{                                                                  //~v0hxI~
    ULCMD   *plcpend,*plcpend0;                                    //~v0hxI~
    int pendctr,pendctr0,ii;                                       //~v0hxR~
    int foundctr;                                                  //~v47cI~
    UCHAR *plab;                                                   //~v0hxI~
    PULINEH plh,plho;                                              //~v11lR~
    int len,linenoctr,swapsw;                                      //~v11lI~
    LONG lineno[2],linenow;                                        //~v11lR~
//*************                                                    //~v0hxI~
//init clear to chk all ok                                         //~v0hxI~
    plcpend0=Ppfh->UFHpvlcmd;   //pending cmd ULCMD save area      //~v0hxI~
    pendctr0=Ppfh->UFHpendctr;      //no of pending                //~v0hxI~
    linenoctr=0;                                                   //~v11lI~
    for (ii=0;ii<Pentno;ii++)                                      //~v0hxI~
    {                                                              //~v0hxI~
//      plab=(UCHAR*)(Plabtbl+ii);                                 //~v54AR~
        plab=(UCHAR*)(Plabtbl[ii]);                                //~v54AI~
        Psortseq[ii]=0;		//  id of not found                    //~v0hxR~
        foundctr=0;                                                //~v47cI~
    	for (plcpend=plcpend0,pendctr=pendctr0;pendctr;pendctr--,plcpend++)//~v0hxR~
    	{                                                          //~v0hxI~
        	if (plcpend->ULCcmd==ULCCMDLABEL)                      //~v0hxI~
        	{                                                      //~v0hxI~
        		plh=plcpend->ULCplh;                               //~v0hxI~
              if (plh)                                             //~v724R~
        		if (!stricmp(plab,plh->ULHlinecmd))                //~v0hxI~
                {                                                  //~v0hxI~
           			 Pplht[ii]=plh;                                //~v0hxI~
                     Psortseq[ii]=-pendctr;		//ascending        //~v0hyI~
//                   break;                                        //~v47cR~
                     foundctr++;                                   //~v47cI~
                     if (foundctr>1)                               //~v47cI~
                     	Psortseq[ii]=0;		//ascending            //~v47cI~
				}                                                  //~v0hxI~
            }//label                                               //~v0hxI~
        }//pend cmd loop                                           //~v0hxI~
//      if (!pendctr)	//not found                                //~v47cR~
        if (!foundctr)	//not found                                //~v47cI~
        {                                                          //~v11lI~
        	linenow=0;                                             //~v11lI~
            if (ii<2 && !UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))    //~v11lR~
            {                                                      //~v11lI~
            	plab++;                                            //~v11lI~
            	len=(int)strlen(plab);                             //~v11lR~
            	if (len==unumlen(plab,0,len))    //all numeric     //~v11lI~
            	{                                                  //~v11lI~
                	lineno[ii]=linenow=atol(plab);                 //~v11lI~
                    linenoctr+=(ii+1)<<1;   //2:opd1,4:opd2,6:opd1 && opd2//~v11lI~
            	}                                                  //~v11lI~
            }                                                      //~v11lI~
          if (!linenow)                                            //~v11lI~
        	return 4;                                              //~v0hxI~
        }                                                          //~v11lI~
        else                                                       //~v47cI~
        if (foundctr!=1)                                           //~v47cI~
        	return 5;                                              //~v47cR~
    }//loop by entryno                                             //~v0hxI~
    if (linenoctr)	//lab by lineno                                //~v11lI~
    {                                                              //~v11lI~
    	if (linenoctr!=6)                                          //~v11lI~
        	return 4;			//both must be lineno              //~v11lI~
		swapsw=0;                                                  //~v11lI~
        if ((linenow=lineno[0])>lineno[1])                         //~v11lI~
        {                                                          //~v11lI~
        	swapsw=1;                                              //~v11lI~
        	linenow=lineno[1];                                     //~v11lI~
        	lineno[1]=lineno[0];                                   //~v11lI~
        	lineno[0]=linenow;                                     //~v11lI~
		}                                                          //~v11lI~
		plh=UGETQTOP(&Ppfh->UFHlineque);//search from top          //~v11lI~
        for (;plh;plh=UGETQNEXT(plh))                              //~v11lI~
			if (plh->ULHtype==ULHTDATA && linenow<=plh->ULHlinenor)//~v11lI~
            	break;                                             //~v11lI~
		if (!plh)                                                  //~v11lI~
        	return 4;                                              //~v11lI~
		if (swapsw)                                                //~v11lI~
        	Pplht[1]=plh;                                          //~v11lI~
        else                                                       //~v11lI~
        	Pplht[0]=plh;                                          //~v11lI~
	    linenow=lineno[1];                                         //~v11lI~
        for (plho=plh;plh;plh=UGETQNEXT(plh))                      //~v11lI~
			if (plh->ULHtype==ULHTDATA)                            //~v11lI~
            {                                                      //~v11lI~
			 	if (linenow<plh->ULHlinenor)                       //~v11lI~
            		break;                                         //~v11lI~
                plho=plh;                                          //~v11lI~
			}                                                      //~v11lI~
		if (swapsw)                                                //~v11lI~
        {                                                          //~v11lI~
            Psortseq[0]=1;		//descending                       //~v11lI~
        	Pplht[0]=plho;                                         //~v11lI~
		}                                                          //~v11lI~
        else                                                       //~v11lI~
        {                                                          //~v11lI~
            Psortseq[1]=1;		//ascending                        //~v11lI~
        	Pplht[1]=plho;                                         //~v11lI~
		}                                                          //~v11lI~
    }                                                              //~v11lI~
    return 0;		//all found                                    //~v0hxI~
}//lcmdgetabplh                                                    //~v0hxI~
                                                                   //~v0hyI~
//*******************************************************          //~v0hyI~
//* save err plh for csr set                                       //~v0hyI~
//*parm1:plh                                                       //~v0hyI~
//*ret  :rc 4                                                      //~v0hyI~
//*******************************************************          //~v0hyI~
int lcmderr(PULINEH Pplh)                                          //~v0hyI~
{                                                                  //~v0hyI~
    if (!Scsrplh)	                                               //~v0hyI~
		Scsrplh=Pplh;	//1st err                                  //~v0hyR~
    return errlcmd();		//err msg                              //~v0hyI~
}//lcmderr                                                         //~v0hyI~
//*******************************************************          //~v41fI~
//* save err plh for csr set                                       //~v41fI~
//*parm1:plh                                                       //~v41fI~
//*ret  :rc 4                                                      //~v41fI~
//*******************************************************          //~v41fI~
void lcmdhelp(void)                                                //~v41fI~
{                                                                  //~v41fI~
//  uerrmsg("\"abcdfijlmoprsxy<>()[]./+=#\"",0);                   //~v74MR~
//  uerrmsg("\"abcdfijlmoprsuxy<>()[]./+=#_\"",0);                 //~v75aR~
//  uerrmsg("\"abcdfijlmoprsuxy<>()[]./+=#_%c%c %s\"",0,           //~v77vR~
    uerrmsg("\"abcdfijlmoprsuxy<>()[]./+=#_%c%c %s %s\"",0,        //~v77vI~
					ULCCMDTFLOW,ULCCMDTFLOWKW,                     //~v75aR~
					ULCCMDTFLOWSTRID,                              //~v75bR~
					ULCCMDTSSTRID);                                //~v75bI~
    return;                                                        //~v41fI~
}//lcmderr                                                         //~v41fI~
