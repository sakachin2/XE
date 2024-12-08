//*CID://+vbd5R~:                              update#=  168;      //~vbd5R~
//*************************************************************
//*xelcmd2.c                                                    //~v04dR~
//* each line cmd process
//************************************************************* //~v019I~
//vbd5:171118 (BUG)ULHFBLOCK was reset when selectall after undo because EndOfLine ULHlinenor was not recovered.//~vbd5I~
//            ULHlinenor is checked at caplinechk->lineseqchk and ULHlinenor is value of set at cappaste(linumsuffix).//~vbd5I~
//vb88:170216 stop lcmd "i" continue mode by cut&paste             //~vb88I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vag5:120821 redundant logic                                      //~vag5I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2e:091229 (BUG)may access beyond malloc when spf insert line   //~va2eI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v78Y:080708 del last inserted line if null                       //~v78YI~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v75K:070509 (BUG)TFLOW internam commandid is displayed           //~v75KR~
//v75b:070419 lcmd TS support                                      //~v75bI~
//v75a:070419 lcmd TFn/":"/";" support                             //~v75aR~
//v74M:070328 lcmd lower support                                   //~v74MI~
//v724:061118 (BUG)ABEND by join lcmd;access of deleted line cause ABEND//~v724R~
//v69L:060713 cap(CAPS LOCK On) support;add "U" lcmd(uppercase translation)//~v69LI~
//v680:060301 chng default to s=0 from  s=1 for r line cmd when only b specified//~v680I~
//v67Z:060228 "r" lcmd:support n parameter of xn,b.s patern as repeat count//~v67ZI~
//v67Y:060228 (BUG)"d" lcmd ABEND when dn,b.s reached to EOF;also for x//~v67YI~
//v66f:051021 (BUG)A+F9 abend when A+F7 on same excludeline and pos1>pos2//~v66fI~
//v631:050426 (BUG)exclude line hdr line count is displayed as 0 after Save cmd(ulhlinenow!=0)//~v631I~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v61b:050213 accept minus -a parm of x *= (same search) previously rejected by "-a -b range err"//~v61bI~
//v54X:040201 del nx all performance tuning                        //~v54XI~
//v54G:040121 (BUG)abend when curtop xline is deleted              //~v54BI~
//v54B:040120 exclude logic performance up for "(i)x all" cmd      //~v54bI~
//v531:030913 (BUG)del stopped at 7fff for large file              //~v531I~
//v530:030912 (BUG)malloc err not chked(DRO,X etc cmd abended)     //~v530I~
//v50u:030113 (BUG)lcmd result msg for RRn,b.s                     //~v50uI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v50s:030112 lcmd II support  IIn,b.s n:isrt lineno,b bandle,s:skip//~v50sI~
//v50r:030112 lcmd spec chng;In,b.s b:isrt lineno-->isrt for b line bundle//~v50rI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v498:020617 XX cmd support .a .b                                 //~v498I~
//v45A:011222 (BUG)not  maintained split flag when split line partialy deleted//~v45AI~
//v42i:011002 set spfnum at save for suffix overflow line to avoid line update flag(*u search)//~v42iI~
//v42b:010924 cobol isert indentation tp after num fld             //~v42bI~
//v42a:010924 warning "renum required" when suffix ovf for spf file//~v42aI~
//v41t:010902 incm performance up for find all att all excluded    //~v41tI~
//v41k:010820 add XR command(reverse excluded line)                //~v41kI~
//v41i:010817 excluded line comment chnage for sortable after drop x rep//~v41iI~
//v40X:010722 cannot set 72-80 by v40W because lrecl=72;use lcmdisrtwithlen//~v40XI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//v181:001111 (BUG)errornus result msg(skip/bandle count) of lcmd comment//~v181I~
//v17b:000501 (BUG)lcmd repeat msg for join,missing l for JJl,m.n  //~v17bI~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v170:000422 (BUG)double sum top remain previous sum line as err  //~v170I~
//v164:000411 (BUG)previos exclude line is undoed when exclude lcmd is over//~v64uI~
//            the previous excluded line.                          //~v64uI~
//v11u:990813 hidden line reset by reset x cmd                     //~v11uI~
//v10i:990221 exclude line count display by 6 char(<--5)           //~v10iI~
//v0k0:980919 (BUG)miss line re-display for f/y lcmd when excluded is top line//~v0k0I~
//v0ib:980530 v0i9 cotinued for other than file copy(move lcmddelbs to hdr)//~v0ibI~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7R~
//v0i6:980512 count/range support for Y lcmd                       //~v0i6I~
//v0i0:980429 lcmd skip/bandle support(DEL/REP/ISRT/EXCLUDE/INCF/INCL)//~v0i0R~
//v0hz:980412 EXCLUDE/IEXCLUDE cmd support                         //~v0hzR~
//v0hv:980410 (BUG)delete line between excluded remain 2 excluded line//~v0hvI~
//v0hf:980130 performance tuning                                   //~v0hfI~
//            draw only after deleted/inserted/exclude/include line//~v0hfI~
//v0cv:970818 (BUG)renum suffix(exclude line lineno must same as next)//~v0cvI~
//v0cu:970814 renumsuffix maxintval is 100 for spf file            //~v0cuI~
//v0bk:970727 copy out from splitline is also split if multiple    //~v0bkI~
//            (reverse v0bc)                                       //~v0bkI~
//v0bi:970727 (BUG)for line isrt csr pos when indent requested,csr move to//~v0biI~
//                 home when indent pos is out of page.move to line top.//~v0biI~
//v0bh:970727 chk all space for line isrt csr pos when indent requested//~v0bhI~
//v0b5:970725 move lcmdshift to lcmd4.c                            //~v0b5I~
//v0b3:970723 clear tab when shift,it is easy to expectate.        //~v0b3I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//           -move lcmdtabshift->filetabshift(file4.c)             //~v0avI~
//v0at:970719 (BUG)chk missed for range lcmd has different repeat number//~v0atI~
//v0as:970719 general comment command(+)                           //~v0asI~
//v0ar:970719 (BUG)lcmd Dn on end of file line cause abend,also Cn on end//~v0arI~
//v0aq:970719 add lcmd //(c comment out)                           //~v0aqI~
//v0aj:970712 also for copyed line about v0af                      //~v0ajI~
//v0ag:970712 same lineno for split line of copyed after last line //~v0agI~
//v0af:970712 insert line into split line is also in the line      //~v0afI~
//v095:970405:DPMI version                                         //~v095I~
//            -not used variable                                   //~v095I~
//            -printf format chk                                   //~v095I~
//v08p:961201:lcmd '<' dose not add padding space now,because trailing space//~v08pI~
//            add more cid to after the space                      //~v08pI~
//v07v:960916:(BUG)">" cause storage destroy                       //~v07vI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07vI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07vI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07f:960701:(BUG)if next adjacent excluded line with linecmd x is deleted//~v07fI~
//                 as a result of x line cmd,abend at undoprep because//~v07fI~
//                 it is not on lineq anymore(it is dequed).       //~v07fI~
//                 -->avoid delete leaving 2 adjacent excluded line.//~v07fI~
//v06m:960317:csr pos on x line for F/L lcmd,on next line for X lcmd//~v06mI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~v057I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v019:950702:cid cut by source file cid attribute not but dest file//~v019I~
//*************************************************************
//*950528 more free(free data of exclude displayline)
//*950521 shift with csr(block del or space block insert)       //~5521R~
//*950520 insert indent after CID only line                     //~5521I~
//*950226 treate 1 line for all excluded line                   //~5226R~
//*950104 set traler/X line lineno                              //~5226I~
//*950103 tab ajust at shift                                    //~5104I~
//*941219 reset UFCcurstop when deleted it                      //~5103I~
//************************************************************* //~4C19I~
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>                                         	//~v04dR~
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
#include <ustring.h>                                            //~5223I~
#include <ufile.h>                                              //~5318I~
#include <ufile5.h>                                                //+vbd5I~
#include <utrace.h>                                              //~v07vR~//~vaz0R~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
                                                                //~5223I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0cuI~
#include "xefile2.h"                                               //~v0avI~
#include "xefile4.h"                                            //~4C23I~
#include "xefile6.h"                                               //~v0avI~
#include "xeundo.h"
#include "xelcmd.h"
#include "xelcmd2.h" 
#include "xelcmd3.h" 
#include "xelcmd4.h"                                               //~v0aqI~
#include "xelcmd5.h"                                               //~v62JI~
#include "xefcmd4.h"                                               //~v75aI~
#include "xecap.h"                                              //~5128I~
#include "xefsub.h"                                             //~5318I~
#include "xesub.h"                                              //~5318I~
#include "xechar.h"                                                //~v0avI~
#include "xefunc.h"                                                //~v78SI~
//*******************************************************
//static UCHAR Sxlinenoedit[]="%05d";                              //~v095R~
static UCHAR Sexcludeld[]="-------- line excluded ";               //~v10iR~
static UCHAR Ssameid[]="-- Same as above ";                        //~v40pI~
static UCHAR Sxecludelh[]="-------|";
static UCHAR Sisrtcsrsw=0;                                         //~v54BR~
static int   Sinsrtlen=0;                                          //~v40XI~
static UCHAR Ssamesw;		//exclude by "same as above"           //~v40pI~
static int Sfromxall2sw=0;                                         //~v54BR~
static int Skbdinpctr;                                             //~v78YI~
//*******************************************************
//int lcmdincall(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat);//~v41kR~
//int lcmdincf(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pcsropt);//~v498R~
int lcmdincl(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat);
int typeexclude(PUCLIENTWE Ppcw,PULINEH Pplh);
PULINEH alloclhx(void);
//int lcmddelxline(PUCLIENTWE Ppcw,PULINEH Pplh);                  //~v9@8R~
int lcmdrepbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,         //~v0i0I~
				int Prepeat,int Pbandle,int Pskip,ULCMD *Pplc);    //~v0i0I~
//int lcmdisrtbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip);//~v50sR~
int lcmdisrtbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip,int Pisrtline);//~v50sR~
int lcmdisrtrange(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v50sR~
int lcmdexcbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v0i0I~
int lcmdincfbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip);//~v0i0I~
int lcmdinclbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip);//~v0i0I~
//****************************************************************
// singlecmd
// process no pair cmd
//*rc   :0
//****************************************************************
int lcmdsingle(PUCLIENTWE Ppcw,ULCMD *Pplc)
{
	ULCMD   *plcr;
	PULINEH plh1,plh2;
	PUFILEH pfh;                                                   //~v8@2I~
	int repeat,rc,repeats;                                      //~5103R~
	int bandle,skip;                                               //~v0i0I~
    int tabskip;                                                   //~v8@2I~
//*******************
	plcr=Pplc->ULCplcrange;	//range pair
	if (plcr)
	{
		plh2=Pplc->ULCplh;                                         //~v0asM~
		plh1=plcr->ULCplh;                                         //~v0asM~
      if (UCBITCHK(Pplc->ULCflag2,ULCF2STRREP))	//not rep is used as string//~v0asR~
      {                                                            //~v181I~
      	repeat=1;				//for only initialize variable     //~v0asI~
        skip=bandle=0;          //no use                           //~v181I~
      }                                                            //~v181I~
      else                                                         //~v0asI~
      {                                                            //~v0asI~
//  	if (!Pplc->ULCrepeat && !plcr->ULCrepeat                   //~v0atR~
    	if (Pplc->ULCrepeat && plcr->ULCrepeat                     //~v0atI~
		&&   Pplc->ULCrepeat != plcr->ULCrepeat)
			return 4;
		repeat=max(Pplc->ULCrepeat,plcr->ULCrepeat);
		bandle=max(Pplc->ULCband,plcr->ULCband);                   //~v0i0I~
		skip  =max(Pplc->ULCskip  ,plcr->ULCskip);                 //~v0i0I~
      }                                                            //~v0asI~
	}
	else
	{
		plh1=plh2=Pplc->ULCplh;
		repeat=Pplc->ULCrepeat;
		bandle=Pplc->ULCband;                                      //~v0i0I~
		skip  =Pplc->ULCskip;                                      //~v0i0I~
	}
    if (skip || bandle)                                            //~v0i7I~
    {                                                              //~v0i7I~
		if (!bandle)                                               //~v0i7I~
	      if (!UCBITCHK(Pplc->ULCflag3,ULCF3CNT0))                 //~v75aI~
        	bandle=1;	//default                                  //~v0i7I~
                                                                   //~v680I~
	  if (Pplc->ULCcmd!=ULCCMDREP)                                 //~v680I~
      {                                                            //~v680I~
		if (!skip)                                                 //~v0i7I~
	      if (!UCBITCHK(Pplc->ULCflag3,ULCF3CNT0))                 //~v75aI~
        	skip=1;     //default                                  //~v0i7I~
      }                                                            //~v680I~
	}                                                              //~v0i7I~
//  if (bandle)                                                    //~v75KR~
    if (bandle>0)   //-1 for TF                                    //~v75KR~
    {                                                              //~v530I~
        if (plcr)                                                  //~v0i7I~
//  	  if (Pplc->ULCcmd=='J' && repeat>1)                       //~v50uR~
		  if (repeat>1)                                            //~v50uR~
            uerrmsg("%c%c%d,%d.%d",0,                              //~v17bI~
                Pplc->ULCcmd,Pplc->ULCcmd,repeat,bandle,skip);     //~v17bR~
          else                                                     //~v17bI~
            uerrmsg("%c%c,%d.%d",0,                                //~v0i7I~
                Pplc->ULCcmd,                                      //~v0i7I~
                Pplc->ULCcmd,                                      //~v0i7I~
                bandle,skip);                                      //~v0i7I~
        else                                                       //~v0i7I~
            uerrmsg("%c%d,%d.%d",0,                                //~v0i7I~
                Pplc->ULCcmd,                                      //~v0i7I~
                repeat,                                            //~v0i7I~
                bandle,skip);                                      //~v0i7I~
    }                                                              //~v530I~
	repeats=repeat;                                             //~5103I~
	if (!repeat)                                                //~5103I~
	  if (!UCBITCHK(Pplc->ULCflag3,ULCF3CNT0))                     //~v75aI~
		repeat=1;                                               //~5103I~
    pfh=UGETPFH(plh1);                                             //~v8@2I~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
	switch(Pplc->ULCcmd)
	{
	case 'I':
     if (plcr)                                                     //~v50sI~
	  rc=lcmdisrtrange(Ppcw,plh1,plh2,repeat,bandle,skip);	//with indent req//~v50sI~
     else                                                          //~v50sI~
      if (bandle)   // rr/n.m specified,range type only            //~v0i0I~
//  	rc=lcmdisrtbs(Ppcw,plh1,repeat,bandle,skip);	//with indent req//~v50sR~
    	rc=lcmdisrtbs(Ppcw,plh1,repeat,bandle,skip,1);	//with indent req,1 line isrt//~v50sI~
      else                                                         //~v0i0I~
//  	rc=lcmdisrt(Ppcw,plh1,repeat,1);	//with indent req      //~v78SR~
    	rc=lcmdisrt(Ppcw,plh1,repeat,LCIO_INDENT|LCIO_CONT);	//with indent req//~v78SI~
		break;
	case 'R':
      if (bandle)   // rr/n.m specified,range type only            //~v0i0I~
		rc=lcmdrepbs(Ppcw,plh1,plh2,repeat,bandle,skip,Pplc);      //~v0i0R~
      else                                                         //~v0i0I~
		rc=lcmdrep(Ppcw,plh1,plh2,repeat,Pplc);
		break;
	case 'D':
      if (bandle)   // /n.m specified                              //~v0i0R~
		rc=lcmddelbs(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v0i0R~
      else                                                         //~v0i0R~
		rc=lcmddel(Ppcw,plh1,plh2,repeat,1,0);                  //~v057R~
			    //csr set at next of del,entered from lcmdmain  //~v057I~
		break;
	case 'X':
      if (bandle)   // /n.m specified                              //~v0i0I~
		rc=lcmdexcbs(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v0i0I~
      else                                                         //~v0i0I~
		rc=lcmdexc(Ppcw,plh1,plh2,repeat);
		lcmdexcludedmsg(0,pfh);                                    //~vb86I~
		break;
	case 'Y':                                                   //~5226R~
		rc=lcmdincall(Ppcw,plh1,plh2,repeat);                      //~v11uR~
		break;
	case 'F':                                                   //~5226I~
      if (bandle)   // /n.m specified                              //~v0i6I~
		rc=lcmdincfbs(Ppcw,plh1,repeat,bandle,skip);               //~v0i6I~
      else                                                         //~v0i6I~
		rc=lcmdincf(Ppcw,plh1,repeat,1);                           //~v0i6R~
		break;                                                  //~5226I~
	case 'L':
      if (bandle)   // /n.m specified                              //~v0i0I~
		rc=lcmdinclbs(Ppcw,plh1,repeat,bandle,skip);               //~v0i0I~
      else                                                         //~v0i0I~
		rc=lcmdincl(Ppcw,plh1,repeat);
		break;
	case '/':                                                      //~v0aqI~
      if (bandle)   // /n.m specified                              //~v0i0I~
		rc=lcmdcombs(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v0i0R~
      else                                                         //~v0i0I~
		rc=lcmdcom(Ppcw,plh1,plh2,repeat,"//");	//lcmd4            //~v0aqR~
		break;                                                     //~v0aqI~
	case ULCCMDCOMM:                                               //~v0asI~
		rc=lcmdgcom(Ppcw,plh1,plh2);	//lcmd4                    //~v0asI~
		break;                                                     //~v0asI~
	case ULCCMDTSSTR:                                              //~v75bI~
	case 'S':                   //split                            //~v0i7I~
		rc=lcmdsplit(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v0i7R~
		break;                                                     //~v0i7I~
	case 'J':                   //split                            //~v0i7I~
		rc=lcmdjoin(Ppcw,plh1,plh2,repeat,bandle,skip);            //~v0i7R~
		break;                                                     //~v0i7I~
	case ULCCMDEXEC:                   //execute                   //~v62JI~
		rc=lcmdexec(Ppcw,plh1,plh2,0);                             //~v62JR~
		break;                                                     //~v62JI~
	case ULCCMDUPPER:                  //execute                   //~v69LI~
		rc=lcmdupper(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v69LR~
		break;                                                     //~v69LI~
	case ULCCMDLOWER:                  //execute                   //~v74MI~
		rc=lcmdlower(Ppcw,plh1,plh2,repeat,bandle,skip);           //~v74MI~
		break;                                                     //~v74MI~
	case ULCCMDTFLOW:                  //":"                       //~v75aR~
	case ULCCMDTFLOWKW:                //";"                       //~v75aR~
	case ULCCMDTFLOWSTR:               //"TF"                      //~v75aR~
		rc=fcmdtflowlcmd(Ppcw,Pplc->ULCcmd,plh1,plh2,repeat,bandle,skip);//~v75aI~
		break;                                                     //~v75aI~
	default:	//'('  or  ')'  or '<'  or  '>'
		if (!repeats)                                           //~5103I~
//  		repeats=max(1,Gfiletabskip);                           //~v8@2R~
    		repeats=max(1,tabskip);                                //~v8@2I~
      if (bandle)   // /n.m specified                              //~v0i0I~
		rc=lcmdshiftbs(Ppcw,plh1,plh2,repeats,Pplc->ULCcmd,bandle,skip);//~v0i0I~
      else                                                         //~v0i0I~
		rc=lcmdshift(Ppcw,plh1,plh2,repeats,Pplc->ULCcmd);      //~5103R~
		break;
	}//switch by cmd
                                                                   //~v0i7I~
	return rc;	
}//single cmd
//**************************************************************** //~v40XI~
// lcmdisrt                                                        //~v40XI~
// line insert                                                     //~v40XI~
// parm1:pcw                                                       //~v40XI~
// parm2:plh to be insterted after                                 //~v40XI~
// parm3:insert count                                              //~v40XI~
// parm4:indent req                                                //~v40XI~
//*rc   :0 or UALLOC_FAILED                                        //~v40XI~
//**************************************************************** //~v40XI~
int lcmdisrtwithlen(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pindentopt,int Plen)//~v40XI~
{                                                                  //~v40XI~
	int rc;                                                        //~v40XI~
#ifdef UTF8UCS2                                                    //~va20I~
    int dbcssw;                                                    //~va20I~
    PULINEH plh;                                                   //~va20I~
#endif                                                             //~va20I~
//*****************                                                //~v40XI~
#ifdef UTF8UCS2                                                    //~va20I~
    dbcssw=Pindentopt & LCIO_ALLOCDBCS;  //for lcmdisrtwithlen;allocate plhdbcs//~va20R~
    Pindentopt &= ~LCIO_ALLOCDBCS;                                 //~va20R~
#endif                                                             //~va20I~
	Sinsrtlen=Plen;                                                //~v40XI~
	rc=lcmdisrt(Ppcw,Pplh,Prepeat,Pindentopt);                     //~v40XR~
	Sinsrtlen=0;                                                   //~v40XI~
#ifdef UTF8UCS2                                                    //~va20I~
    if (!rc && dbcssw)                                             //~va20I~
    {                                                              //~va20I~
        plh=UGETQNEXT(Pplh);      //inserted                       //~va20I~
		plh->ULHdbcs=UALLOCC(1,(UINT)plh->ULHbufflen);             //~va20I~
		UALLOCCHK(plh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~va20I~
	}                                                              //~va20I~
#endif                                                             //~va20I~
    return rc;                                                     //~v40XI~
}//lcmdisrtwithlen                                                 //~v40XI~
//**************************************************************** //~v78SI~
// lcmdisrtcont                                                    //~v78SI~
//       continue lcmd isrt when csr is on tha last isrted line    //~v78SI~
//*rc   :0 or UALLOC_FAILED                                        //~v78SI~
//**************************************************************** //~v78SI~
int lcmdisrtcont(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)            //~v78SI~
{                                                                  //~v78SI~
	PUSCRD psd;                                                    //~v78SI~
	PULINEH plhisrt,plhcsr;                                        //~v78SR~
	int rc,yy;                                                     //~v78SR~
//*****************                                                //~v78SI~
	plhisrt=Ppfh->UFHplhlcmdi;                                     //~v78SI~
    if (!plhisrt)                                                  //~v78SI~
    	return 0;                                                  //~v78SI~
	yy=Ppcw->UCWrcsry;                                             //~v78SR~
	psd=Ppcw->UCWpsd+yy;                                           //~v78SI~
	plhcsr=psd->USDbuffc;  //plh on cursor                         //~v78SI~
    if (!CSRONFILEDATA(Ppcw)//csr is out of line                   //~v78SR~
    ||  plhcsr!=plhisrt     //csr is out the insrted               //~v78SR~
//  ||  !plhisrt->ULHlen    //no data                              //~v78YR~
       )                                                           //~v78SI~
    {                                                              //~v78SI~
		Ppfh->UFHplhlcmdi=0;                                       //~v78SI~
        return 0;                                                  //~v78SI~
    }                                                              //~v78SI~
    if (!plhisrt->ULHlen)    //plhcsr==plhisrt and                 //~v78YI~
    {                                                              //~v78YI~
		Ppfh->UFHplhlcmdi=0;                                       //~v78YI~
        rc=0;                                                      //~v78YI~
        if (Gkbdinpctr==Skbdinpctr+1)                              //~v78YI~
        {                                                          //~v78YI~
			UPCTRREQ(Ppfh);//next time updatectr up                //~v78YI~
			rc=lcmddel(Ppcw,plhisrt,plhisrt,1,1,1);//1line del,csr set to next line//~v78YI~
	        UPCTRREQ(Ppfh);//next time updatectr up                //~v78YI~
        }                                                          //~v78YI~
        return rc;                                                 //~v78YI~
    }                                                              //~v78YI~
//  rc=lcmdisrt(Ppcw,plhisrt,1/*repeat count*/,LCIO_INDENT|LCIO_CONT);//~v78SR~//~vb88R~
    rc=lcmdisrt(Ppcw,plhisrt,1/*repeat count*/,LCIO_INDENT|LCIO_CONT|LCIO_CONT2);//~vb88I~
    Skbdinpctr=Gkbdinpctr;                                         //~v78YI~
    if (!rc)                                                       //~v78SI~
    	if (yy+1==Ppcw->UCWmaxline) //bottom of screen             //~v78SR~
			rc=func_linedown_file(Ppcw);                           //~v78SR~
    return rc;                                                     //~v78SI~
}//lcmdisrtcont                                                    //~v78SI~
//****************************************************************
// lcmdisrt                                                     //~4C29R~
// line insert
// parm1:pcw                                                    //~4C29I~
// parm2:plh to be insterted after                              //~4C29I~
// parm3:insert count                                           //~4C29I~
// parm4:indent req                                             //~5223I~
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int lcmdisrt(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pindentopt)//~5223R~
{
	int i,offs=0,fldno=1;                                       //~v04dR~
    int nocidlen;                                                  //~v0bhI~
	PUFILEC pfc;                                                //~5223I~
	PUFILEH pfh;                                                   //~v42bI~
	PULINEH plh,plhprev,plhnext,plh1st=0;
    int optother;                                                  //~v78SI~
//  int splitsw;                                                   //~v0ajR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************
	optother=Pindentopt & ~LCIO_INDENT; //option other than indent //~v78SR~
	Pindentopt &=LCIO_INDENT; //option indent                      //~v78SI~
    if (!UGETQNEXT(Pplh))   //on last hdr line                  //~4C22I~
        Pplh=UGETQPREV(Pplh);   //assume I on prev line         //~4C22I~
  if (Prepeat<0)     	//called from lcmd 'S'                     //~v0i7I~
  	Prepeat=-Prepeat;                                              //~v0i7I~
  else                                                             //~v0i7I~
    if (Pplh->ULHtype==ULHTEXCLUDE)                             //~5111R~
    {                                                           //~5111I~
		Pplh=getdisplayline(Pplh,1,0);	//next display line     //~5204R~
        Pplh=UGETQPREV(Pplh);   //assume I on prev line         //~5111I~
    }                                                           //~5111I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	plhprev=Pplh;
	plhnext=UGETQNEXT(Pplh);
//  splitsw=UCBITCHK(plhprev->ULHflag2,ULHF2SPLIT1);//has continued line//~v0ajR~
	for (i=0;i<Prepeat;i++)
	{
//  	plh=filealloclh(ULHTDATA,0);                               //~v40XR~
    	plh=filealloclh(ULHTDATA,Sinsrtlen);                       //~v40XI~
        UALLOCCHK(plh,UALLOC_FAILED);                           //~v04dR~
		plh->ULHlinenor=Pplh->ULHlinenor;
//      if (splitsw)                                               //~v0ajR~
//  		UCBITON(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);//intermediate line//~v0ajR~
		UENQENT(UQUE_AFT,plhprev,plh);	
		if (!plh1st)
			plh1st=plh;
		plhprev=plh;
	}//loop by repeat count
	if (lcmdrenumsuffix(Ppcw,Pplh,plhnext,Prepeat,0)==UALLOC_FAILED)//~v04dR~
    	return UALLOC_FAILED;                                   //~v04dI~
//  filesetmultdraw(Ppcw);	//all client draw of same file         //~v0hfR~
    filesetdrawstart(Ppcw,plh1st,DRAW_MULT|DRAW_ISRT);	//redraw from next of del,all client of same file//~v0hfR~
	pfc=Ppcw->UCWpfc;                                           //~5223I~
	pfh=pfc->UFCpfh;                                               //~v42bI~
    if ((optother & LCIO_CONT) && plhprev!=Pplh) //inserted last   //~v78SR~
    {                                                              //~vb88I~
    	pfh->UFHplhlcmdi=plhprev;         //last inserted by lcmd "I"//~v78SR~
    	pfh->UFHplhlcmdi_upundoctr=pfh->UFHupundoctr+((optother & LCIO_CONT2)==0)/*1st time only add 1*/;    //last inserted by lcmd "I"//~vb88R~
    }                                                              //~vb88I~
	if (Pindentopt && !UCBITCHK(Gopt2,GOPT2LINOINDENT))         //~5223I~
	{                                                           //~5223I~
        nocidlen=                                                  //~v0bhI~
		offs=filecidlrecl(Pplh,UGETPFH(Pplh));                  //~5520R~
     if (UCBITCHK(pfh->UFHflag5,UFHF5COB))  //cobol                //~v42bR~
//  	offs=SPFCOBNUMFLDLEN+(int)ustrnspn(Pplh->ULHdata+SPFCOBNUMFLDLEN," ",(UINT)offs-SPFCOBNUMFLDLEN);//~v42bI~//~va2eR~
     {                                                             //~va2eI~
    	if (offs>SPFCOBNUMFLDLEN)                                  //~va2eI~
#ifdef UTF8UCS2                                                    //~va20I~
    		offs=SPFCOBNUMFLDLEN                                   //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50R~
                +(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,Pplh->ULHdata+SPFCOBNUMFLDLEN,Pplh->ULHdbcs+SPFCOBNUMFLDLEN,offs-SPFCOBNUMFLDLEN);//~va50R~
	#else                                                          //~va50R~
                +(int)UTF_ustrnspn(swutf8file,Pplh->ULHdata+SPFCOBNUMFLDLEN,Pplh->ULHdbcs+SPFCOBNUMFLDLEN," ",offs-SPFCOBNUMFLDLEN);//~va20I~
  	#endif //UTF8EBCD raw ebcdic file support                      //~va50R~
#else                                                              //~va20I~
    		offs=SPFCOBNUMFLDLEN+(int)ustrnspn(Pplh->ULHdata+SPFCOBNUMFLDLEN," ",(UINT)offs-SPFCOBNUMFLDLEN);//~va2eI~
#endif                                                             //~va20I~
        else                                                       //~va2eI~
    		offs=SPFCOBNUMFLDLEN;                                  //~va2eI~
     }                                                             //~va2eI~
     else                                                          //~v42bI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
		offs=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,offs);//~va50I~
	#else                                                          //~va50I~
		offs=(int)UTF_ustrnspn(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs," ",offs);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
		offs=(int)ustrnspn(Pplh->ULHdata," ",(UINT)offs);       //~5520I~
#endif                                                             //~va20I~
      if (offs==nocidlen)                                          //~v0bhI~
        offs=0;                                                    //~v0bhI~
      else                                                         //~v0bhI~
		offs=offs-pfc->UFCleft;                                 //~5520I~
        if (offs<0)                                             //~5223I~
        {                                                       //~5223I~
    		offs=0;                                             //~5223I~
            fldno=0;	                                        //~5223I~
        }                                                       //~5223I~
        else                                                       //~v0biI~
            if (offs>=Ppcw->UCWwidth-Ppcw->UCWlinenosz)            //~v0biI~
    		    offs=0;                                            //~v0biI~
	}                                                           //~5223I~
//no indent                                                        //~v42bI~
    else                                                        //~5223I~
	{                                                              //~v42bI~
      if (UCBITCHK(pfh->UFHflag5,UFHF5COB))  //cobol               //~v42bI~
      {                                                            //~v42bI~
		if (pfc->UFCleft>SPFCOBNUMFLDLEN)                          //~v42bI~
            fldno=0;                                               //~v42bI~
      }                                                            //~v42bI~
	  else                                                         //~v42bI~
		if (pfc->UFCleft)                                       //~5223I~
            fldno=0;	                                        //~5223I~
	}                                                              //~v42bI~
  if (!Sisrtcsrsw)	                                               //~v0i0I~
	filesetcsr(Ppcw,plh1st,fldno,offs);	//csr set to offs in data fld//~5223R~
	return 0;	
}//lcmdisrt
                                                                //~5226I~
//**************************************************************** //~v0i0I~
// lcmdisrtbs                                                      //~v0i0I~
// line insert with bandle.skip                                    //~v0i0I~
// parm1:pcw                                                       //~v0i0I~
// parm2:plh to be insterted after                                 //~v0i0I~
// parm3:repeat count                                              //~v50sR~
// parm4:bandle                                                    //~v0i0I~
// parm5:skip                                                      //~v0i0I~
// parm6:isrt count                                                //~v50sI~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
//int lcmdisrtbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip)//~v50sR~
int lcmdisrtbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip,int Pisrtline)//~v50sR~
{                                                                  //~v0i0I~
	PULINEH plh,plh2;                                              //~v0i0R~
	PULINEH plh3=0;    //skip is always >=1                        //~vaf9R~
	int ii,rc;                                                     //~v0i0R~
    int jj;                                                        //~v50rI~
//*****************                                                //~v0i0I~
	rc=0;                                                          //~v0i0I~
    plh=Pplh;                                                      //~v0i0I~
    for (ii=0;ii<Prepeat;ii++)                                     //~v0i0I~
    {                                                              //~v0i0I~
//      if (lcmdgetplhrange(&plh,&plh2,Pskip+1)==8)    //get next insert pos//~v50rR~
//      {                                                          //~v50rR~
//          if (!ii)         //start line reached to eol           //~v50rR~
//              rc=8;                                              //~v50rR~
//          break;                                                 //~v50rR~
//  	}                                                          //~v50rR~
//  	rc=lcmdisrt(Ppcw,plh,Pbandle,1);	//with indent req      //~v50rR~
      if (Pskip)                                                   //~v50sI~
		plh3=getdisplayline(plh,Pbandle+Pskip,0); 	//skip s line  //~v50sR~
      for (plh2=0,jj=Pbandle;jj;plh=plh2)                          //~v50rR~
      {                                                            //~v50rR~
			if (!(plh2=getdisplayline(plh,1,0)))	//1 line after //~v50rR~
            	break;                                             //~v50rI~
			if (plh->ULHtype==ULHTHDR)		//no delete when hdr line//~v50rI~
            	continue;                                          //~v50rI~
            jj--;                                                  //~v50rI~
//  		rc=lcmdisrt(Ppcw,plh,1,1);	//with indent req          //~v50sR~
    		rc=lcmdisrt(Ppcw,plh,Pisrtline,1);	//with indent req  //~v50sI~
            if (rc)                                                //~v50rI~
            	break;                                             //~v50rI~
        Sisrtcsrsw=1;	//bypass csr set                           //~v0i0I~
      }                                                            //~v50rI~
        if (rc)                                                    //~v0i0I~
    		break;                                                 //~v0i0R~
        if (!plh3)                                                 //~v50sI~
        	break;                                                 //~v50sI~
        plh=plh3;                                                  //~v50sI~
    }                                                              //~v0i0I~
    Sisrtcsrsw=0;                                                  //~v0i0I~
	return rc;                                                     //~v0i0R~
}//lcmdisrtbs                                                      //~v0i0I~
//**************************************************************** //~v50sI~
// lcmdisrtbsrange                                                 //~v50sI~
// line insert with bandle.skip                                    //~v50sI~
// parm1:pcw                                                       //~v50sI~
// parm2:plh1                                                      //~v50sR~
// parm3:plh2                                                      //~v50sI~
// parm4:repeat count(=isrt line no)                               //~v50sR~
// parm5:bandle                                                    //~v50sR~
// parm6:skip                                                      //~v50sR~
//*rc   :0 or UALLOC_FAILED                                        //~v50sI~
//**************************************************************** //~v50sI~
int lcmdisrtrange(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip)//~v50sR~
{                                                                  //~v50sI~
	PULINEH plh,plh2,plh3;                                         //~v50sI~
	int jj,rc,bandle;                                              //~v50sR~
//*****************                                                //~v50sI~
	rc=0;                                                          //~v50sI~
    plh=Pplh1;		//start plh                                    //~v50sI~
    bandle=Pbandle;                                                //~v50sI~
    if (!bandle)                                                   //~v50sI~
    	bandle=-1;                                                 //~v50sR~
    for (;;)                                                       //~v50sI~
    {                                                              //~v50sI~
      	for (plh2=0,jj=bandle;jj;plh=plh2)                         //~v50sR~
      	{                                                          //~v50sI~
			if (!(plh2=getdisplayline(plh,1,0)))	//1 line after for skip start//~v50sI~
            	break;                                             //~v50sI~
			if (plh->ULHtype==ULHTHDR)		//no delete when hdr line//~v50sI~
            	continue;                                          //~v50sI~
            jj--;                                                  //~v50sI~
    		rc=lcmdisrt(Ppcw,plh,Prepeat,1);	//with indent req  //~v50sI~
            if (rc)                                                //~v50sI~
            	break;                                             //~v50sI~
        	Sisrtcsrsw=1;	//bypass csr set                       //~v50sI~
            if (plh==Pplh2)                                        //~v50sI~
            	break;                                             //~v50sI~
      	}                                                          //~v50sI~
        if (rc)                                                    //~v50sI~
    		break;                                                 //~v50sI~
        if (!plh2)                                                 //~v50sI~
        	break;                                                 //~v50sI~
        if (plh==Pplh2)                                            //~v50sI~
        	break;                                                 //~v50sI~
      	if (Pskip)                                                 //~v50sI~
        {                                                          //~v50sI~
        	if (lcmdgetplhrange2(&plh2,&plh3,Pplh2,Pskip)==8)    //skip s line//~v50sI~
        		break;	//already eol                              //~v50sI~
            if (plh3==Pplh2)         //reached to Pplh2            //~v50sI~
            	break;                                             //~v50sI~
            plh=plh3;                                              //~v50sI~
        }                                                          //~v50sI~
    }//range                                                       //~v50sI~
    Sisrtcsrsw=0;                                                  //~v50sI~
	return rc;                                                     //~v50sI~
}//lcmdisrtrange                                                   //~v50sI~
//****************************************************************//~5226M~
// lcmdrepeat                                                   //~5226M~
// process repeat cmd                                           //~v04dR~
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************//~5226M~
int lcmdrep(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc)//~5226M~
{                                                               //~5226M~
//*****************                                             //~5226M~
	if (Pplh2->ULHtype==ULHTEXCLUDE	&&  Pplh1==Pplh2)//excluded line only//~5226R~
    {                                                           //~5226I~
		if (undoprep(Ppcw,Pplh2,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
		Pplh2->ULHlinenow*=(Prepeat+1);	//excluded line count   //~5226I~
		lcmdeditxline(Pplh2);                                   //~5226I~
		if (!(Pplh2=getdisplayline(Pplh2,1,0)))	//1 line after  //~5226I~
			Pplh2=UGETQEND(&UGETPFH(Pplh2)->UFHlineque);//over end of line//~5226I~
        Pplh2=UGETQPREV(Pplh2);	//last  excluded                //~5226I~
        Pplh1=UGETQNEXT(Pplh1);	//first excluded                //~5226I~
	}                                                           //~5226I~
	Pplc->ULCrepeat=Prepeat;	//repeat at destination         //~5226R~
	return lcmdcopy(Ppcw,Pplh1,Pplh2,1,Pplc);//copy after plh2  //~5226R~
}//lcmdrep                                                      //~5226M~
                                                                //~5226M~
//**************************************************************** //~v0i0I~
// lcmdrepeatbs                                                    //~v0i0I~
// process repeat cmd with bandle.skip                             //~v0i0I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdrepbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,         //~v0i0I~
				int Prepeat,int Pbandle,int Pskip,ULCMD *Pplc)     //~v0i0R~
{                                                                  //~v0i0I~
	PULINEH plh,plh2,plh3=0,plhstop,plhold;                        //~vaf9R~
    int sw1,rc;                                                    //~v0i0I~
    int rc2=0;                                                     //~vaf9R~
    int ii;                                                        //~v67ZI~
//*****************                                                //~v0i0I~
    plhstop=Pplh2;                                                 //~v0i0I~
    plh=Pplh1;                                                     //~v0i0I~
    plhold=Pplc->ULCplh;                                           //~v0i0I~
    rc=0;                                                          //~v0i0I~
  if (Pplh1==Pplh2)	//count type dn/l.m                            //~v67ZI~
  {                                                                //~v67ZI~
    plhstop=0;                                                     //~v67ZI~
    for (ii=0;ii<Prepeat;ii++)                                     //~v67ZI~
    {                                                              //~v67ZI~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v67ZI~
        {                                                          //~v67ZI~
            if (!ii)         //start line reached to eol           //~v67ZR~
                rc=8;                                              //~v67ZI~
            break;                                                 //~v67ZI~
        }                                                          //~v67ZI~
        if (plh2!=plhstop)                                         //~v67ZI~
        {                                                          //~v680I~
          if (Pskip)                                               //~v680I~
	        rc2=lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);//last of skip line//~v67ZI~
          else                                                     //~v680I~
	        rc2=lcmdgetplhrange2(&plh2,&plh3,plhstop,2);//next bandle top//~v680I~
        }                                                          //~v680I~
		Pplc->ULCplh=plh2;                                         //~v67ZI~
		rc=lcmdrep(Ppcw,plh,plh2,1,Pplc);	//repeat count=1,treate Prepeat as loop count//~v67ZI~
        if (rc || rc2==8)                                          //~v67ZI~
    		break;                                                 //~v67ZI~
      if (Pskip)                                                   //~v680I~
      {                                                            //~v680I~
	    if (lcmdgetplhrange2(&plh3,&plh,plhstop,2)==8)//next of skip lines//~v67ZI~
        	break;                                                 //~v67ZI~
      }                                                            //~v680I~
      else                                                         //~v680I~
      	plh=plh3;                                                  //~v680I~
    }                                                              //~v67ZI~
  } //rn,b.s                                                       //~v67ZI~
  else                                                             //~v67ZI~
  {                                                                //~v67ZI~
    for (sw1=0;;)                                                  //~v0i0R~
    {                                                              //~v0i0I~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v0i0R~
        {                                                          //~v530I~
            if (sw1)         //start line reached to eol           //~v0i0R~
                break;                                             //~v0i0R~
            else            //first time eol                       //~v0i0R~
            {                                                      //~v0i0R~
                rc=8;                                              //~v0i0R~
                break;                                             //~v0i0R~
            }                                                      //~v0i0R~
        }                                                          //~v530I~
		sw1=1;                                                     //~v0i0I~
        if (plh2!=plhstop)                                         //~v0i0I~
        {                                                          //~v680I~
          if (Pskip)                                               //~v680I~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);//next of skip lines//~v0i0R~
          else                                                     //~v680I~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,2);//next the bandle//~v680I~
        }                                                          //~v680I~
		Pplc->ULCplh=plh2;                                         //~v0i0I~
		rc=lcmdrep(Ppcw,plh,plh2,Prepeat,Pplc);                    //~v0i0R~
        if (rc)                                                    //~v0i0I~
    		break;                                                 //~v0i0R~
        if (plh2==plhstop || plh3==plhstop)                        //~v0i0R~
        	break;                                                 //~v0i0I~
      if (Pskip)                                                   //~v680I~
	    lcmdgetplhrange2(&plh3,&plh,plhstop,2);//next of skip lines//~v0i0I~
      else       	//already plh3 is next bandle top              //~v680I~
      	plh=plh3;                                                  //~v680I~
    }                                                              //~v0i0I~
  }//rr-rrn,b.s                                                    //~v67ZI~
    Pplc->ULCplh=plhold;                                           //~v0i0I~
	return rc;                                                     //~v0i0R~
}//lcmdrepbs                                                       //~v0i0I~
                                                                   //~v0i0I~
//**************************************************************** //~v0i0I~
//!lcmddelbs                                                       //~v0i0R~
// 	line delete for Dn/l.m type                                    //~v0i0I~
//*parm1:pcw                                                       //~v0i0R~
//*parm2:start ULINEH                                              //~v0i0I~
//*parm3:start ULINEH                                              //~v0i0I~
//*parm4:repaet count                                              //~v0i0R~
//*parm5:bandle                                                    //~v0i0R~
//*parm6:skip                                                      //~v0i0R~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmddelbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip)//~v0i0R~
{                                                                  //~v0i0I~
	PULINEH plh,plh2,plh3=0,plhstop;                               //~vaf9R~
	int ii,rc,repeat;                                              //~v0i0R~
    int csropt=1;                                                  //~v0i0I~
    int rc2=0;                                                     //~v67YM~
//*****************                                                //~v0i0I~
	if (Pplh1==Pplh2)	//count type dn/l.m                        //~v0i0I~
    {                                                              //~v0i0I~
    	repeat=Prepeat;                                            //~v0i0M~
    	plhstop=0;                                                 //~v0i0I~
	}                                                              //~v0i0I~
    else                                                           //~v0i0I~
    {                                                              //~v0i0I~
//  	repeat=0x7fff;                                             //~v531R~
    	repeat=MAX_INT_VAL;                                        //~v531R~
    	plhstop=Pplh2;                                             //~v0i0I~
	}                                                              //~v0i0I~
    plh=Pplh1;                                                     //~v0i0R~
    for (ii=0;ii<repeat;ii++)                                      //~v0i0R~
    {                                                              //~v0i0R~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v0i0R~
        {                                                          //~v530I~
            if (ii)         //start line reached to eol            //~v0i0R~
                break;                                             //~v0i0R~
            else            //first time eol                       //~v0i0R~
                return 8;                                          //~v0i0R~
        }                                                          //~v530I~
        if (plh2!=plhstop)                                         //~v0i0I~
          rc2=                                                     //~v67YM~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);//next del start//~v0i0R~
		rc=lcmddel(Ppcw,plh,plh2,1,csropt,0);                      //~v0i0R~
        if (rc)                                                    //~v0i0I~
    	        return rc;                                         //~v0i0I~
        if (rc2==8) //skip operation reached to EOF                //~v67YM~
            break;                                                 //~v67YM~
        csropt=0;                                                  //~v0i0R~
        if (plh2==plhstop || plh3==plhstop)                        //~v0i0R~
            break;                                                 //~v0i0I~
        rc2=                                                       //~v67YI~
	    lcmdgetplhrange2(&plh3,&plh,plhstop,2);//next del start    //~v0i0I~
        if (rc2==8) //skip operation reached to EOF                //~v67YI~
            break;                                                 //~v67YI~
    }                                                              //~v0i0R~
	return 0;                                                      //~v0i0I~
}//lcmddelbs                                                       //~v0i0R~
                                                                   //~v0i0I~
//****************************************************************//~5226M~
//!lcmddel                                                      //~v057R~
// 	line delete                                                 //~5226M~
//*parm1:start ULINEH                                           //~5226M~
//*parm2:end   ULINEH                                           //~5226M~
//*parm3:repaet count                                           //~5226M~
//*parm4:csr set option(1:set after deleted, 0:no set(for move))//~5226M~
//*parm5:entry status 0:from lcmdmain,1:cap/shift+del/del CR etc//~v057I~
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************//~5226M~
int lcmddel(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v057R~
            int Pcsropt,int Pnotlcmdmain)                       //~v057I~
{                                                               //~5226M~
	PUFILEH pfh;                                                //~5226M~
	PUFILEC pfce,pfcb0=0,pfcb1=0;                                  //~vaf9R~
//  PULINEH plh,plhn,plhlast,plhcurtope,plhcurtopb0=0,plhcurtopb1=0;//~vaf9R~
    PULINEH plh,plhn,plhlast=0,plhcurtope,plhcurtopb0=0,plhcurtopb1=0;//~vaf9I~
	PULINEH plhprev=0;		//prev of first deleted                //~v0hvI~
	int excludesw,delctr=0,rc;                                     //~v0hzR~
	int deltopswe=0,deltopswb0=0,deltopswb1=0;                  //~5226M~
	int splitflag1=0,splitflag2=0,splitflag1r=0;                   //~vaf9R~
    int bydelnxsw;                                                 //~v54XI~
//*****************                                             //~5226M~
    if (Pnotlcmdmain & LCDEL_BYDELNXALL)	//do editxline later   //~v54XI~
    {                                                              //~v54XI~
		Pnotlcmdmain &= ~LCDEL_BYDELNXALL;	//do editxline later   //~v54XI~
        bydelnxsw=1;                                               //~v54XI~
    }                                                              //~v54XI~
    else                                                           //~v54XI~
        bydelnxsw=0;                                               //~v54XI~
	pfh=UGETPFH(Pplh1);                                         //~5226M~
	if (pfh->UFHbrowsepcw[0])                                   //~5226M~
		plhcurtopb0=(pfcb0=pfh->UFHbrowsepcw[0]->UCWpfc)->UFCcurtop;//~5226M~
	if (pfh->UFHbrowsepcw[1])                                   //~5226M~
		plhcurtopb1=(pfcb1=pfh->UFHbrowsepcw[1]->UCWpfc)->UFCcurtop;//~5226M~
	plhcurtope=(pfce=Ppcw->UCWpfc)->UFCcurtop;                  //~5226M~
//*convert cont type to range type                              //~5226I~
	if (Pplh1==Pplh2)	//Dnn count type                        //~5226R~
        if (lcmdgetplhrange(&Pplh1,&Pplh2,Prepeat)==8)             //~v0arR~
        	return 4;                                              //~v0arI~
//*del range                                                    //~5226I~
	excludesw=0;                                                //~5226R~
    rc=0;                                                       //~v04dI~
	for (plh=Pplh1;plh;)                                        //~5226R~
	{                                                           //~5226R~
		if (excludesw)                                          //~5226R~
			if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))         //~5226R~
				break;                                          //~5226R~
		plhn=UGETQNEXT(plh);                                    //~5226R~
		if (plh->ULHtype!=ULHTHDR)		//no delete when hdr line//~5226R~
		{                                                       //~5226R~
	  		if (Gcappcw==Ppcw)                                  //~5423I~
    			if (plh==Gcapplh1 || plh==Gcapplh2)             //~5423I~
    				capreset(1);//reset plh                     //~5423I~
            if (Gcalcpcw==Ppcw)                                    //~v170I~
                if (plh==Gcalcplh1 || plh==Gcalcplh2)              //~v170I~
                    capresetcalc(Ppcw);//clear block define        //~v170I~
            if (Pnotlcmdmain)	//not from lcmdmain                //~v11uR~
            {                                                      //~v11uR~
				if (UCBITCHK(plh->ULHflag,ULHFLINECMD))	//remain not processed lcmd//~v057I~
                {                                               //~v057I~
//                    UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);//for undo//~v0hzR~
//                    for(ii=pfh->UFHcmdlinectr-1;ii>=0;ii--)      //~v0hzR~
//                        if (pfh->UFHcmdline[ii]==plh)            //~v0hzR~
//                        {                                        //~v0hzR~
//                            pfh->UFHcmdline[ii]=0;               //~v0hzR~
//                            break;                               //~v0hzR~
//                        }                                        //~v0hzR~
					lcmdclearlcmd(pfh,plh);                        //~v0hzI~
				}                                               //~v057I~
            }//not from lcmdmain                                   //~v11uR~
            splitflag2=UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);//last//~v45AI~
            if (!plhprev)                                          //~v0hvI~
            {                                                      //~v45AI~
            	plhprev=UGETQPREV(plh);		//prev of first deleted//~v0hvI~
            	splitflag1=(splitflag2 & ULHF2SPLIT2); //followed  //~v45AI~
	            splitflag1r=(splitflag2 & ULHF2SPLIT1); //has follower?//~v45AI~
            }                                                      //~v45AI~
            else                                                   //~v45AI~
	            splitflag1r&=(splitflag2 & ULHF2SPLIT1);    //yet,has follower//~v45AI~
			if (rc=undoupdate(Ppcw,plh,UUHTDEL),rc)//deq and prep for undo//~v04dR~
//          	break;	//UALLOC_FAILED                            //~v530R~
  		      	return UALLOC_FAILED;                              //~v530I~
			delctr++;                                           //~5226R~
			if (plh==plhcurtope)		//cur top deleted       //~5226R~
				deltopswe=1;		//deleted sw                //~5226R~
			if (plh==plhcurtopb0)		//cur top deleted       //~5226R~
				deltopswb0=1;		//deleted sw                //~5226R~
			if (plh==plhcurtopb1)		//cur top deleted       //~5226R~
				deltopswb1=1;		//deleted sw                //~5226R~
			plhlast=plhn;			//next of deleted           //~5226R~
		}                                                       //~5226R~
		if (plh==Pplh2)                                         //~5226R~
			if (!(excludesw=(Pplh2->ULHtype==ULHTEXCLUDE)))     //~5226R~
				break;                                          //~5226R~
		plh=plhn;                                               //~5226R~
	}//by range                                                 //~5226R~
                                                                //~5226I~
    if(rc)                                                         //~v530I~
        return rc;                                                 //~v530I~
	if (!delctr)                                                //~5226M~
		return 4;                                               //~5226M~
    if (splitflag1)	//top is follower                              //~v45AI~
    {                                                              //~v45AI~
		if (!splitflag1r)    //not split continuing                //~v45AI~
        {                                                          //~v45AI~
            if (rc=undoupdate(Ppcw,plhprev,UUHTCUTOFF),rc)//save splitflag//~v45AR~
                return rc;  //UALLOC_FAILED                        //~v45AI~
            UCBITOFF(plhprev->ULHflag2,ULHF2SPLIT1);//no follower  //~v45AR~
            if (splitflag2 & ULHF2SPLIT1)    //cont to next        //~v45AI~
            {                                                      //~v45AI~
                if (rc=undoupdate(Ppcw,plhlast,UUHTCUTOFF),rc)//save split flag//~v45AI~
                    return rc;  //UALLOC_FAILED                    //~v45AI~
                UCBITOFF(plhlast->ULHflag2,ULHF2SPLIT2);//not followed//~v45AI~
            }                                                      //~v45AI~
        }                                                          //~v45AI~
    }                                                              //~v45AI~
    else	//top is not follower                                  //~v45AI~
    	if (splitflag2 & ULHF2SPLIT1)    //cont to next            //~v45AI~
    	{                                                          //~v45AI~
        	if (rc=undoupdate(Ppcw,plhlast,UUHTCUTOFF),rc)//save split flag//~v45AI~
            	return rc;  //UALLOC_FAILED                        //~v45AI~
        	UCBITOFF(plhlast->ULHflag2,ULHF2SPLIT2);//not followed //~v45AR~
    	}                                                          //~v45AI~
	if (UCBITCHK(plhprev->ULHflag2,ULHF2EXCLUDED))	//del from after excluded//~v0hvI~
		if (plhlast->ULHtype==ULHTEXCLUDE)	//del all between excluded//~v0hvI~
        {                                                          //~v0hvI~
			if (!*plhlast->ULHlinecmd)	//next has no lcmd,if has cannot delete//~v0hvI~
    	    {                                                      //~v0hvI~
//prepare for plhlast deleted                                      //~v0hvI~
				if (plhlast==plhcurtope)		//cur top deleted  //~v0hvR~
					deltopswe=1;		//deleted sw               //~v0hvR~
				if (plhlast==plhcurtopb0)		//cur top deleted  //~v0hvR~
					deltopswb0=1;		//deleted sw               //~v0hvR~
				if (plhlast==plhcurtopb1)		//cur top deleted  //~v0hvR~
					deltopswb1=1;		//deleted sw               //~v0hvR~
//update xline on prev xclude                                      //~v0hvI~
        	  if (!bydelnxsw)//do editxline later at filedrop      //~v54XI~
              {                                                    //~v54XI~
				while(plhprev->ULHtype!=ULHTEXCLUDE)               //~v0hvR~
					plhprev=UGETQPREV(plhprev); 	//prev EX line //~v0hvR~
				if (undoprep(Ppcw,plhprev,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v0hvR~
        			return UALLOC_FAILED;                          //~v0hvR~
				plhprev->ULHlinenow+=plhlast->ULHlinenow;		//excluded line count//~v0hvR~
				lcmdeditxline(plhprev);                            //~v0hvR~
              }                                                    //~v54XI~
//del next exclude                                                 //~v0hvI~
				if (lcmddelxline(Ppcw,plhlast)==UALLOC_FAILED)     //~v0hvR~
	        		return UALLOC_FAILED;                          //~v0hvR~
            	plhlast=plhprev;		//disple prev EX line      //~v0hvR~
      		}	//next has no lcmd                                 //~v0hvR~
        }                                                          //~v0hvI~
//  filesetmultdraw(Ppcw);	//all client draw of same file         //~v0hfR~
    filesetdrawstart(Ppcw,plhlast,DRAW_MULT);	//redraw from next of del,all client of same file//~v0hfR~
	if (Pcsropt)		//not called from move                  //~5226M~
		filesetcsr(Ppcw,plhlast,0,0);	//csr set to data fld,fldtop//~5226M~
	if (deltopswe)		//cur top deleted                       //~5226M~
		pfce->UFCcurtop=plhlast;                                //~5226M~
	if (deltopswb0)		//cur top deleted                       //~5226M~
		pfcb0->UFCcurtop=plhlast;                               //~5226M~
	if (deltopswb1)		//cur top deleted                       //~5226M~
		pfcb1->UFCcurtop=plhlast;                               //~5226M~
	return 0;	                                                //~5226M~
}//lcmddel                                                      //~5226M~
                                                                //~5226I~
//**************************************************************** //~v11uI~
// lcmdresetx                                                      //~v11uI~
// reset all excluded                                              //~v11uI~
//*rc   :0                                                         //~v11uI~
//**************************************************************** //~v11uI~
int lcmdresetx(PUCLIENTWE Ppcw)                                    //~v11uI~
{                                                                  //~v11uI~
    PULINEH plhs,plhe;                                             //~v11uI~
	PUFILEH pfh;                                                   //~v11uI~
//*****************                                                //~v11uI~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v11uI~
	plhs=UGETQTOP(&pfh->UFHlineque);                               //~v11uI~
	plhe=UGETQEND(&pfh->UFHlineque);                               //~v11uI~
	return lcmdincall(Ppcw,plhs,plhe,0);//repeat=0--range type     //~v11uR~
}//lcmdresetx                                                      //~v11uI~
                                                                   //~v11uI~
//****************************************************************//~5226I~
// lcmdincall                                                   //~5226I~
// include all excluded                                         //~5226I~
//*rc   :0  2:no unexclude line 4:line err                         //~v11uR~
//****************************************************************//~5226I~
int lcmdincall(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat)//~v11uR~
{                                                               //~5226I~
	int rc=0,repeat,csropt=1;                                      //~vaf8R~
    int unxctr=0;                                                  //~v11uI~
    PULINEH plh,plhn;                                              //~v0i6R~
//*****************                                             //~5226I~
  if (Pplh1==Pplh2)	//Yn type                                      //~v11uI~
  {                                                                //~v11uI~
	if (Pplh1->ULHtype!=ULHTEXCLUDE)                               //~v0i6R~
		return 4;                                               //~5226I~
	if (Pplh2->ULHtype!=ULHTEXCLUDE)                               //~v0i6I~
		return 4;                                                  //~v0i6I~
  }                                                                //~v11uI~
	if (Pplh1==Pplh2)	//Yn type                                  //~v0i6I~
		for (plh=Pplh1,repeat=Prepeat;repeat && plh;plh=UGETQNEXT(plh))//~v0i6I~
        {                                                          //~v0i6I~
			if (plh->ULHtype==ULHTEXCLUDE)                         //~v0i6I~
            {                                                      //~v0i6I~
            	repeat--;                                          //~v0i6I~
                plhn=UGETQNEXT(plh);	//for del xline	           //~v0i6I~
				if (rc=lcmdincf(Ppcw,plh,(int)plh->ULHlinenow,csropt),rc)//~v0i6R~
        	    	break;                                         //~v0i6I~
            	unxctr++;                                          //~v11uI~
                plh=plhn;                                          //~v0i6R~
                csropt=0;                                          //~v0i6R~
			}                                                      //~v0i6I~
        }                                                          //~v0i6I~
	else                //yy type                                  //~v0i6I~
		for (plh=Pplh1;plh;plh=UGETQNEXT(plh))                     //~v0i6I~
		{                                                          //~v0i6I~
			if (plh->ULHtype==ULHTEXCLUDE)                         //~v0i6I~
            {                                                      //~v0i6I~
                plhn=UGETQNEXT(plh);	//for del xline            //~v0i6I~
				if (rc=lcmdincf(Ppcw,plh,(int)plh->ULHlinenow,csropt),rc)//~v0i6R~
        	    	break;                                         //~v0i6I~
            	unxctr++;                                          //~v11uI~
	            if (plh==Pplh2)                                    //~v0i6I~
    	        	break;                                         //~v0i6I~
                plh=plhn;                                          //~v0i6M~
                csropt=0;                                          //~v0i6I~
			}                                                      //~v0i6I~
            if (plh==Pplh2) //for the case last is not on xhdr line//~v11uI~
                break;                                             //~v11uI~
		}//by range                                                //~v0i6I~
	if (!rc && !unxctr)                                            //~v11uR~
    	rc=2;			//tell no line unexcluded                  //~v11uR~
	return rc;                                                     //~v0i6I~
}//lcmdincall                                                   //~5226I~
                                                                //~5226I~
//****************************************************************
// lcmdincf
// include first("F" linecmd)
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int lcmdincf(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pcsropt) //~v0i6R~
{
	PULINEH plh,plhx,plhc;                                      //~v06mR~
	long i,line;
    int rc=0;                                                   //~v04dI~
//*****************
	if (Pplh->ULHtype!=ULHTEXCLUDE)
		return 4;
	plhx=alloclhx();			//allocate exclude display line //~v04dI~
    UALLOCCHK(plhx,UALLOC_FAILED);                              //~v04dI~
	line=Pplh->ULHlinenow;		//excluded line count
	plh=UGETQNEXT(Pplh);
    plhc=plh;					//csr plh                       //~v06mI~
    filesetdrawstart(Ppcw,plh,DRAW_ISRT);	//redraw exclude hdr or revailed//~v0hfI~
	for (i=0;i<Prepeat && line;i++,line--)
	{
		if ((rc=undoprep(Ppcw,plh,UUHTXOFF))==UALLOC_FAILED)//flag off and prepare for undo//~v04dR~
//      	break;                                                 //~v530R~
  		    return UALLOC_FAILED;                                  //~v530I~
		plh=UGETQNEXT(plh);	
	}//loop by repeat count
	if (line)	//more 
	{
//  	plhx=alloclhx();			//allocate exclude display line//~v04dR~
		UENQENT(UQUE_BEF,plh,plhx);//previous next of EX line
		plhx->ULHlinenow=line;		//excluded line count
		lcmdeditxline(plhx);
		if (undoprep(Ppcw,plhx,UUHTISRT)==UALLOC_FAILED)//prepare for undo insert//~v04dR~
        	rc=UALLOC_FAILED;                                   //~v04dI~
		plhc=plhx;      		//csr plh                       //~v06mI~
	}
    else                                                        //~v04dI~
        filefreeplh(plhx,1);  //no more need(free data and plh) //~v04dI~
  if (Pcsropt)	                                                   //~v0i6I~
	filesetcsr(Ppcw,plhc,0,0);	//csr set to lineno fld,fldtop  //~v06mI~
	if (!rc)                                                    //~v04dI~
		if (lcmddelxline(Ppcw,Pplh)==UALLOC_FAILED)//last operation for avoid undo csr pos//~v04dR~
			rc=UALLOC_FAILED;                                   //~v04dI~
//  UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full redraw              //~v0hfR~
	return rc;	                                                //~v04dR~
}//lcmdincf
                                                                //~5226I~
//**************************************************************** //~v0i0R~
// lcmdincfbs                                                      //~v0i0R~
// include first("F" linecmd)                                      //~v0i0R~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0R~
//**************************************************************** //~v0i0R~
int lcmdincfbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip)//~v0i0R~
{                                                                  //~v0i0R~
    PULINEH plh,plhx,plhc;                                         //~v0i0R~
    long ii,jj,line;                                               //~v0i0R~
//*****************                                                //~v0i0R~
    if (Pplh->ULHtype!=ULHTEXCLUDE)                                //~v0i0R~
        return 4;                                                  //~v0i0R~
    line=Pplh->ULHlinenow;      //excluded line count              //~v0i0R~
    plh=UGETQNEXT(Pplh);                                           //~v0i0R~
    plhc=plh;                   //csr plh                          //~v0i0R~
    if (lcmddelxline(Ppcw,Pplh)==UALLOC_FAILED)//last operation for avoid undo csr pos//~v0i0R~
        return UALLOC_FAILED;                                      //~v0i0R~
    filesetdrawstart(Ppcw,plh,DRAW_ISRT);   //redraw exclude hdr or revailed//~v0i0R~
    for (ii=0;ii<Prepeat;ii++)                                     //~v0i0R~
    {                                                              //~v0i0R~
        for (jj=Pbandle;jj && line;jj--,line--) //revaile          //~v0i0R~
        {                                                          //~v0i0R~
            if (undoprep(Ppcw,plh,UUHTXOFF)==UALLOC_FAILED)//flag off and prepare for undo//~v0i0R~
                return UALLOC_FAILED;                              //~v0i0R~
            plh=UGETQNEXT(plh);                                    //~v0i0R~
        }                                                          //~v0i0R~
        if (line)                                                  //~v0i0R~
        {                                                          //~v0i0R~
            plhx=alloclhx();            //allocate exclude display line//~v0i0R~
            UALLOCCHK(plhx,UALLOC_FAILED);                         //~v0i0R~
            UENQENT(UQUE_BEF,plh,plhx);//previous next of EX line  //~v0i0R~
            if (ii<Prepeat-1 && line>(long)Pskip)                  //~v0i0R~
            {                                                      //~v0i0R~
                plhx->ULHlinenow=(long)Pskip;       //excluded line count//~v0i0R~
                line=line-Pskip;                                   //~v0i0R~
                for (jj=Pskip;jj;jj--)                             //~v0i0R~
                    plh=UGETQNEXT(plh);                            //~v0i0R~
            }                                                      //~v0i0R~
            else                                                   //~v0i0R~
            {                                                      //~v0i0R~
                plhx->ULHlinenow=line;      //excluded line count  //~v0i0R~
                line=0;                                            //~v0i0R~
            }                                                      //~v0i0R~
            lcmdeditxline(plhx);                                   //~v0i0R~
            if (undoprep(Ppcw,plhx,UUHTISRT)==UALLOC_FAILED)//prepare for undo insert//~v0i0R~
                return UALLOC_FAILED;                              //~v0i0R~
        }                                                          //~v0i0R~
        if (!line)                                                 //~v0i0R~
            break;                                                 //~v0i0R~
    }//loop by repeat count                                        //~v0i0R~
    filesetcsr(Ppcw,plhc,0,0);  //csr set to lineno fld,fldtop     //~v0i0R~
    return 0;                                                      //~v0i0R~
}//lcmdincfbs                                                      //~v0i0R~
                                                                   //~v0i0R~
//****************************************************************
// lcmdincl
// include last("L" linecmd)
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int lcmdincl(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat)
{
	PULINEH plh,plhc;                                           //~v06mR~
	long i,line,iline;
    int rc=0;                                                   //~v04dI~
//*****************
	if (Pplh->ULHtype!=ULHTEXCLUDE)
		return 4;
	plh=UGETQNEXT(Pplh);
	line=max(0,(int)Pplh->ULHlinenow-Prepeat);	//stay as excluded
	for (i=0;i<line;i++)
		plh=UGETQNEXT(plh);		//skip first half line
	plhc=plh;					//csr plh                       //~v06mI~
	iline=min(Prepeat,(int)Pplh->ULHlinenow);	//include ctr
	for (i=0;i<iline;i++)
	{
		if ((rc=undoprep(Ppcw,plh,UUHTXOFF))==UALLOC_FAILED)//flag off and prepare for undo//~v04dR~
//      	break;                                                 //~v530R~
  		    return UALLOC_FAILED;                                  //~v530I~
		plh=UGETQNEXT(plh);	
	}//loop by repeat count
	if (line)	//more 
	{
		if (undoprep(Ppcw,Pplh,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v04dR~
        	rc=UALLOC_FAILED;                                   //~v04dI~
		Pplh->ULHlinenow=line;		//excluded line count
		lcmdeditxline(Pplh);
		plhc=Pplh;					//csr plh                   //~v06mI~
	}	
	else
		if (lcmddelxline(Ppcw,Pplh)==UALLOC_FAILED)             //~v04dR~
        	rc=UALLOC_FAILED;                                   //~v04dI~
	filesetcsr(Ppcw,plhc,0,0);	//top line displayed,fldtop     //~v06mR~
//  UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full redraw              //~v0hfR~
    filesetdrawstart(Ppcw,plhc,DRAW_ISRT);	//redraw from ecxhdr or revailed line//~v0hfI~
	return rc;	                                                //~v04dR~
}//lcmdincl
                                                                   //~v0i0I~
//**************************************************************** //~v0i0I~
// lcmdinclbs                                                      //~v0i0I~
// include last("L" linecmd)                                       //~v0i0I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdinclbs(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pbandle,int Pskip)//~v0i0I~
{                                                                  //~v0i0I~
	PULINEH plh,plhc=0,plhx;                                       //~vaf9R~
	long line,linew;                                               //~v0i0R~
    int ii,jj;                                                     //~v0i0R~
//*****************                                                //~v0i0I~
	if (Pplh->ULHtype!=ULHTEXCLUDE)                                //~v0i0I~
		return 4;                                                  //~v0i0I~
	line=Pplh->ULHlinenow;	//excluded lineno                      //~v0i0I~
	for (plh=Pplh,linew=0;linew<line;linew++)                      //~v0i0R~
		plh=UGETQNEXT(plh);		//last excluded line               //~v0i0I~
    for (ii=0;ii<Prepeat;ii++)                                     //~v0i0I~
    {                                                              //~v0i0I~
		for (jj=Pbandle;jj && line;jj--,line--)                    //~v0i0I~
		{                                                          //~v0i0I~
        	plhc=plh;                                              //~v0i0I~
			if (undoprep(Ppcw,plh,UUHTXOFF)==UALLOC_FAILED)//flag off and prepare for undo//~v0i0R~
				return UALLOC_FAILED;                              //~v0i0I~
			plh=UGETQPREV(plh);                                    //~v0i0I~
		}//                                                        //~v0i0I~
        if (!line || ii>=Prepeat-1)                                //~v0i0R~
        	break;                                                 //~v0i0I~
		linew=line;                                                //~v0i0I~
		for (jj=0;jj<Pskip && linew;jj++,linew--)                  //~v0i0I~
			plh=UGETQPREV(plh);                                    //~v0i0I~
        if (!linew)                                                //~v0i0I~
        	break;                                                 //~v0i0I~
        plhx=alloclhx();            //allocate exclude display line//~v0i0I~
        UALLOCCHK(plhx,UALLOC_FAILED);                             //~v0i0I~
        UENQENT(UQUE_AFT,plh,plhx);//previous next of EX line      //~v0i0R~
		plhx->ULHlinenow=jj;	//excluded lineno                  //~v0i0I~
        lcmdeditxline(plhx);                                       //~v0i0I~
        if (undoprep(Ppcw,plhx,UUHTISRT)==UALLOC_FAILED)//prepare for undo insert//~v0i0I~
			return UALLOC_FAILED;                                  //~v0i0I~
		line=linew;                                                //~v0i0I~
    }                                                              //~v0i0I~
	if (line)	//more                                             //~v0i0I~
	{                                                              //~v0i0I~
		if (undoprep(Ppcw,Pplh,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v0i0I~
        	return UALLOC_FAILED;                                  //~v0i0R~
		Pplh->ULHlinenow=line;		//excluded line count          //~v0i0I~
		lcmdeditxline(Pplh);                                       //~v0i0I~
        plhc=Pplh;                                                 //~v0i0I~
	}                                                              //~v0i0I~
	else                                                           //~v0i0I~
		if (lcmddelxline(Ppcw,Pplh)==UALLOC_FAILED)                //~v0i0I~
			return UALLOC_FAILED;                                  //~v0i0I~
	filesetcsr(Ppcw,plhc,0,0);	//top line displayed,fldtop        //~v0i0I~
    filesetdrawstart(Ppcw,plhc,DRAW_ISRT);	//redraw from ecxhdr or revailed line//~v0i0I~
	return 0;                                                      //~v0i0R~
}//lcmdinclbs                                                      //~v0i0I~
                                                                   //~v0i0I~
//****************************************************************
//!lcmdincm                                                     //~v04dR~
// include middle point excluded(called from FIND cmd)
//*rc   :0 or UALLOC_FAILED if storage shortage                 //~v04dR~
//****************************************************************
int lcmdincm(PUCLIENTWE Ppcw,PULINEH Pplh)
{
	PULINEH plhx,plh;
	long line;
	long oldxline;                                                 //~v41tI~
    int rc=0;                                                   //~v04dI~
//*****************
//*chk prev line
	plhx=alloclhx();			//allocate exclude display line //~v04dI~
    UALLOCCHK(plhx,UALLOC_FAILED);                              //~v04dI~
	for (line=0,plh=Pplh;
		 UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);
		 plh=UGETQPREV(plh))
		line++;
    oldxline=plh->ULHlinenow;  //save curr exc lineno              //~v41tI~
	if (line==1)
    {                                                           //~v04dI~
		if (lcmddelxline(Ppcw,plh)==UALLOC_FAILED)              //~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
	}                                                           //~v04dI~
	else
	{
		if (undoprep(Ppcw,plh,UUHTXLINENO)==UALLOC_FAILED)//save old excluded lineno//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
		plh->ULHlinenow=line-1;	//excluded line count
		lcmdeditxline(plh);
	}
//*chk following line
//  for (line=0,plh=Pplh;                                          //~v41tR~
//  	 plh && UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);             //~v41tR~
//  	 plh=UGETQNEXT(plh))                                       //~v41tR~
//  	line++;                                                    //~v41tR~
    line=oldxline-line+1; //new exc line after the line            //~v41tI~
	if (line!=1)
	{
//  	plhx=alloclhx();			//allocate exclude display line//~v04dR~
		plhx->ULHlinenow=line-1;	//excluded line count
		UENQENT(UQUE_AFT,Pplh,plhx);//enq plhx
		lcmdeditxline(plhx);		//lineno edit
		if (undoprep(Ppcw,plhx,UUHTISRT)==UALLOC_FAILED)//prepare for undo insert//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
	}
    else                                                        //~v04dI~
        filefreeplh(plhx,1);  //no more need(free data and plh) //~v04dI~
	rc=undoprep(Ppcw,Pplh,UUHTXOFF);//flag off and prepare for undo//~v04dR~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full redraw
	return rc;	                                                //~v04dR~
}//lcmdincm                                                     //~5118R~
                                                                //~5223I~
//**************************************************************** //~v0i0I~
//!lcmdexcbs                                                       //~v0i0I~
// 	line exclude for (XX)Xn/l.m type                               //~v0i0I~
//*parm1:pcw                                                       //~v0i0I~
//*parm2:start ULINEH                                              //~v0i0I~
//*parm3:start ULINEH                                              //~v0i0I~
//*parm4:repaet count                                              //~v0i0I~
//*parm5:bandle                                                    //~v0i0I~
//*parm6:skip                                                      //~v0i0I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdexcbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip)//~v0i0I~
{                                                                  //~v0i0I~
	PULINEH plh,plh2,plh3=0,plhstop;                               //~vaf9R~
	int ii,rc,repeat;                                              //~v0i0I~
    int rc2=0;                                                     //~v67YI~
//*****************                                                //~v0i0I~
	if (Pplh1==Pplh2)	//count type dn/l.m                        //~v0i0I~
    {                                                              //~v0i0I~
    	repeat=Prepeat;                                            //~v0i0I~
    	plhstop=0;                                                 //~v0i0I~
	}                                                              //~v0i0I~
    else                                                           //~v0i0I~
    {                                                              //~v0i0I~
//  	repeat=0x7fff;                                             //~v531R~
    	repeat=MAX_INT_VAL;                                        //~v531R~
    	plhstop=Pplh2;                                             //~v0i0I~
	}                                                              //~v0i0I~
    plh=Pplh1;                                                     //~v0i0I~
    for (ii=0;ii<repeat;ii++)                                      //~v0i0I~
    {                                                              //~v0i0I~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v0i0R~
        {                                                          //~v530I~
            if (ii)         //start line reached to eol            //~v0i0I~
                break;                                             //~v0i0I~
            else            //first time eol                       //~v0i0I~
                return 8;                                          //~v0i0I~
        }                                                          //~v530I~
        if (plh2!=plhstop)  //reached to range end                 //~v0i0I~
          rc2=                                                     //~v67YI~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);         //~v0i0R~
		rc=lcmdexc(Ppcw,plh,plh2,1);                               //~v0i0R~
        if (rc)                                                    //~v0i0I~
    	        return rc;                                         //~v0i0I~
        if (rc2==8) //skip operation reached to EOF                //~v67YI~
            break;                                                 //~v67YI~
        if (plh2==plhstop || plh3==plhstop)                        //~v0i0R~
            break;                                                 //~v0i0I~
        rc2=                                                       //~v67YI~
	    lcmdgetplhrange2(&plh3,&plh,plhstop,2);                    //~v0i0I~
        if (rc2==8) //skip operation reached to EOF                //~v67YI~
            break;                                                 //~v67YI~
    }                                                              //~v0i0I~
	return 0;                                                      //~v0i0I~
}//lcmdexcbs                                                       //~v0i0I~
                                                                   //~v0i0I~
//**************************************************************** //~v40pI~
// lcmdexcsame                                                     //~v40pI~
// line exclude by "x all=" cmd                                    //~v40pI~
//*parm1:pcw                                                       //~v40pI~
//*parm2:plh from                                                  //~v40pI~
//*parm3:plh to                                                    //~v40pI~
//*rc   :0  , 4 no new excluded , UALLOC_FAILED                    //~v40pI~
//**************************************************************** //~v40pI~
int lcmdexcsame(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)       //~v40pI~
{                                                                  //~v40pI~
	int rc;                                                        //~v40pI~
//*****************                                                //~v40pI~
	Ssamesw=1;                                                     //~v40pI~
	rc=lcmdexc(Ppcw,Pplh1,Pplh2,0);                                //~v40pR~
	Ssamesw=0;                                                     //~v40pI~
    return rc;                                                     //~v40pI~
}//lcmdexcsame                                                     //~v40pI~
//**************************************************************** //~v54BR~
// lcmdexcfromxall                                                 //~v54BR~
// line exclude req from "(i)x all" cmd  2nd match                 //~v54BR~
//*rc   :0  , 4 no new excluded , UALLOC_FAILED                    //~v54BR~
//**************************************************************** //~v54BR~
int lcmdexcfromxall2(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)  //~v54BR~
{                                                                  //~v54BR~
	PUFILEH pfh;                                                   //~v54BR~
	PULINEH plhs,plh,plhx;                                         //~v54BR~
    int rc;                                                        //~v54BR~
    LONG    xline=0;                                               //~v54BR~
//*****************                                                //~v54BR~
	if (Pplh1) 	//each exclude req                                 //~v54BR~
    {                                                              //~v54BR~
        Sfromxall2sw=1;                                            //~v54BR~
        rc=lcmdexc(Ppcw,Pplh1,Pplh2,0);     //0:second call from find cmd//~v54BR~
        Sfromxall2sw=0;                                            //~v54BR~
    	return rc;                                                 //~v54BR~
    }                                                              //~v54BR~
//last call,ajust exlude count                                     //~v54BR~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v54BR~
	plhs=UGETQTOP(&pfh->UFHlineque);                               //~v54BR~
    for (plhx=0,plh=plhs;plh;plh=UGETQNEXT(plh))                   //~v54BR~
    {                                                              //~v54BR~
        if (plh->ULHtype==ULHTEXCLUDE)                             //~v54BR~
        {                                                          //~v54BR~
            plhx=plh;                                              //~v54BR~
            continue;                                              //~v54BR~
        }                                                          //~v54BR~
        if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))  //not yet excluded//~v54BR~
        {                                                          //~v54BR~
        	xline++;                                               //~v54BR~
            continue;                                              //~v54BR~
        }                                                          //~v54BR~
        if (plhx)                                                  //~v54BR~
        {                                                          //~v54BR~
//      	if (plh->ULHlinenow!=xline)                            //~v631R~
        	if (plhx->ULHlinenow!=xline)                           //~v631I~
            {                                                      //~v54BR~
				rc=undoprep(Ppcw,plhx,UUHTXLINENO);//save excluded lineno//~v54BR~
				plhx->ULHlinenow=xline;	//excluded line count      //~v54BR~
                lcmdeditxline(plhx);                               //~v54BR~
			    filesetdrawstart(Ppcw,plhx,0);	//redraw from ecxhdr (del type)//~v54BR~
        		UCBITOFF(plhx->ULHflag4,ULHF4XSAMEHDR);	//reset prev hdr//~v54BR~
            }                                                      //~v54BR~
        	xline=0;                                               //~v54BR~
            plhx=0;	//exclude groupe ended                         //~v631I~
        }                                                          //~v54BR~
	}//for                                                         //~v54BR~
    return 0;                                                      //~v54BR~
}//lcmdexcfromxall2                                                //~v54BR~
//****************************************************************
// lcmdexc
// line exclude
//*parm1:pcw                                                       //~v0hzI~
//*parm2:plh from                                                  //~v0hzI~
//*parm3:plh to                                                    //~v0hzI~
//*parm4:count(0 if called from fcmd2 exclude at 2nd of all)       //~v0hzR~
//*rc   :0  , 4 no new excluded , UALLOC_FAILED                 //~v04dR~
//****************************************************************
int lcmdexc(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat)
{
	PULINEH plh,plhx,plhp,plhn;
	long i,line=0;
    int rc=0;                                                   //~v04dI~
    int x2sw=0,repeat;                                             //~v0hzI~
    long xline;                                                    //~v40pI~
//*****************
    plhx=alloclhx();        //prepare plhx                      //~v04dI~
    UALLOCCHK(plhx,UALLOC_FAILED);                              //~v04dI~
	if (!(plhp=UGETQPREV(Pplh1)))		//previous of range1    //~4C23R~
		plhp=Pplh1;      //top of file  line                    //~4C23I~
//*exclude process
	if (Pplh1==Pplh2)	//Xnnn type
	{					//exclude data line just the repeat number
    	if (!(repeat=Prepeat))                                     //~v0hzI~
        {                                                          //~v0hzI~
        	repeat=1;                                              //~v0hzI~
            x2sw=1;                                                //~v0hzI~
        }                                                          //~v0hzI~
		for (i=0,plh=Pplh1;i<repeat && plh;plh=UGETQNEXT(plh))     //~v0hzR~
		{
			if (rc=typeexclude(Ppcw,plh),rc)	//counted dataline//~v04dR~
			{
            	if (rc==UALLOC_FAILED)                          //~v04dI~
//              	break;                                         //~v530R~
    		    	return UALLOC_FAILED;                          //~v530I~
				line++;
				i++;
			}
		}
		plhn=plh;
	}
	else
	{
		for (plh=Pplh1;plh;plh=UGETQNEXT(plh))
		{
			rc=typeexclude(Ppcw,plh);                           //~v04dR~
            if (rc==UALLOC_FAILED)                              //~v04dI~
//             	break;                                             //~v530R~
   		    	return UALLOC_FAILED;                              //~v530I~
			line+=rc;                                           //~v04dI~
			if (plh==Pplh2)
				break;
		}//by range
		plhn=UGETQNEXT(Pplh2);
	}
    if (!line)                                                  //~4C22I~
    {                                                           //~v04dI~
        filefreeplh(plhx,1);  //no more need(free data and plh) //~v04dI~
        return 4;                                               //~4C22I~
    }                                                           //~v04dI~
//*display line setup                                           //~4C22I~
//  plhx=alloclhx();                                            //~v04dR~
//*count following excluded
	for(;plhn && UCBITCHK(plhn->ULHflag2,ULHF2EXCLUDED);plhn=UGETQNEXT(plhn))
		line++;
//*conbine next excluded group
	xline=line;		//line now excluded                            //~v40pI~
	if (plhn
	&&  (plhn->ULHtype==ULHTEXCLUDE))	//next is excluded
	{
    	if (!*plhn->ULHlinecmd)			//next line has line cmd input//~v07fI~
        {                                                          //~v07fI~
		line+=plhn->ULHlinenow;			//all in one
		if (lcmddelxline(Ppcw,plhn)==UALLOC_FAILED)             //~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
		for(i=plhn->ULHlinenow;i>=0 && plhn;i--)                //~v06mI~
			plhn=UGETQNEXT(plhn);                               //~v06mI~
        }                                                          //~v07fI~
	}
	if (UCBITCHK(plhp->ULHflag2,ULHF2EXCLUDED))	//continue from prev
	{
		filefreeplh(plhx,1);	//data and plh
      if (Sfromxall2sw)		//frm x all                            //~v54BR~
      {                                                            //~v54BR~
      	plhx=0;                                                    //~v54BR~
        rc=0;                                                      //~v54BR~
      }                                                            //~v54BR~
      else                                                         //~v54BR~
      {                                                            //~v54BR~
		while(plhp->ULHtype!=ULHTEXCLUDE)
			plhp=UGETQPREV(plhp);
		rc=undoprep(Ppcw,plhp,UUHTXLINENO);//save excluded lineno//~v04dR~
		plhp->ULHlinenow+=line;	//excluded line count
        UCBITOFF(plhp->ULHflag4,ULHF4XSAMEHDR);	//reset prev hdr   //~v40pI~
		plhx=plhp;
      }//not from x all                                            //~v54BR~
	}
	else
	if (plhp->ULHtype==ULHTEXCLUDE) //prev is exclude hdr(may occur when called from find cmd)//~v61bI~
	{                                                              //~v61bI~
//*  "X *=" cmd with -a/-b option searches in excluded line,so prev line may exlude header line//~vag5I~
		filefreeplh(plhx,1);	//data and plh                     //~v61bI~
		rc=undoprep(Ppcw,plhp,UUHTXLINENO);//save excluded lineno  //~v61bI~
		plhp->ULHlinenow=line;	//excluded line count              //~v61bI~
       if (!Ssamesw                                                //~v61bI~
//     ||  !UCBITCHK(plhp->ULHflag4,ULHF4XSAMEHDR))	//continued "same as above"//~v61bI~//~vag5R~
       )                                                           //~vag5I~
        UCBITOFF(plhp->ULHflag4,ULHF4XSAMEHDR);	//reset prev hdr   //~v61bI~
		plhx=plhp;                                                 //~v61bI~
	}                                                              //~v61bI~
	else                                                           //~v61bI~
	{
		plhx->ULHlinenow=line;	//excluded line count
        if (line==xline)	//not combined next X                  //~v40pI~
        	if (Ssamesw)		//exclude by "x ALL=" cmd          //~v40pI~
        		UCBITON(plhx->ULHflag4,ULHF4XSAMEHDR);	//display "same as above"//~v40pR~
		UENQENT(UQUE_AFT,plhp,plhx);
		rc=undoprep(Ppcw,plhx,UUHTISRT);//prep EXCLUDE line undo//~v04dR~
	}
    if (rc)                                                        //~v530I~
   		return UALLOC_FAILED;                                      //~v530I~
  if (plhx) //not from x all 2nd call                              //~v54BR~
  {                                                                //~v54BR~
	lcmdeditxline(plhx);
    filesetdrawstart(Ppcw,plhx,0);	//redraw from ecxhdr (del type)//~v0hfM~
    if (plhn)                                                   //~v06mI~
    	plhx=plhn;				//csr line                      //~v06mI~
  if (!x2sw)                                                       //~v0hzI~
	filesetcsr(Ppcw,plhx,0,0);	//csr set to data fld,fldtop    //~5223R~
  }//plhx                                                          //~v54BR~
//  UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full redraw              //~v0hfR~
	return rc;	                                                //~v04dR~
}//lcmdexc
                                                                //~v04dI~
//****************************************************************
// alloclhx
//* setup exclude display line
//*rc   :plh or 0 if storage shortage                           //~v04dR~
//****************************************************************
PULINEH alloclhx(void)
{
	PULINEH plhx;
	UCHAR *pc;
//***************
	plhx=filealloclh(ULHTEXCLUDE,MAXCOLUMN);
    UALLOCCHK(plhx,0);	//return 0 if storage shortage          //~v04dI~
	pc=plhx->ULHdata;
	memset(pc,'-',MAXCOLUMN);
	memcpy(pc,Sexcludeld,sizeof(Sexcludeld)-1);	//except last null
	memcpy(plhx->ULHlineno,Sxecludelh,ULHLINENOSZ);
	return plhx;
}//alloclhx
//****************************************************************
// typeexclude
//* line exclude by each type
//* parm1:pcw
//* parm2:plh
//*rc   :0-not excluded  1:excluded or UALLOC_FAILED            //~v04dR~
//****************************************************************
int typeexclude(PUCLIENTWE Ppcw,PULINEH Pplh)
{
	int rc=0;                                                      //~vaf9R~
//***************
	switch (Pplh->ULHtype)
	{
	case ULHTEXCLUDE:
		rc=0;
		if (lcmddelxline(Ppcw,Pplh)==UALLOC_FAILED)             //~v04dI~
        	rc=UALLOC_FAILED;                                   //~v04dI~
		break;
	case ULHTDATA:
		rc=1;
	  if (!UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))	//not yet excluded//~v64uI~
		if (undoprep(Ppcw,Pplh,UUHTXON)==UALLOC_FAILED)//flag on and prep excluded line undo//~v04dR~
        	rc=UALLOC_FAILED;                                   //~v04dI~
		break;
	case ULHTHDR:                                               //~4C22R~
		rc=0;                                                   //~4C22I~
		break;                                                  //~4C22I~
	}
	return rc;
}//typeexclude
                                                                //~5103I~
//****************************************************************
// lcmdrenumsuffix                                              //~v019R~
//   re-numbering suffix under same ULHlinenor
//*parm1:pcw
//*parm2:previous PULINEH of inserted
//*parm3:next PULINEH of inserted
//*parm4:insert count
//*parm5:move mode sw                                           //~5131I~
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int lcmdrenumsuffix(PUCLIENTWE Ppcw,PULINEH Pplhprev,PULINEH Pplhnext,//~v04dR~
					int Pcount,int Pmovesw)                     //~5131I~
{
#define MAXINTV 10000
static int Spower[4]={1,10,100,1000};
	int maxintv,intv=0,suffix=0;                                   //~vaf9R~
	int i,notlastsw;                                     //~4C22R~
    int splitno;                                                   //~v0agI~
    LONG lineno;                                                //~4C22I~
	PULINEH plh;
	PUFILEH pfh;
    int splitsw;                                                   //~v0ajI~
    int spfsw,spfreclen,rc,lenerrsw;                               //~v42iR~
    int prevexcludesw=0;                                           //~v0cuI~
    int spfnumupdsw;    //number ovf for spf                       //~v42aI~
//  ULONG offs;                                                    //~vaz0R~
    FILESZT offs;                                                  //~vaz0I~
//****************
	pfh=UGETPFH(Pplhprev);
  spfsw=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK);                     //~v0cuR~
  if (spfsw)                                                       //~v0cuI~
    maxintv=SPFNUMMAXSUF+1;                                        //~v0cuR~
  else                                                             //~v0cuI~
	if (UGETQCTR(&pfh->UFHlineque)>=MAXINTV)
		maxintv=100;                                               //~v0cuR~
	else
		maxintv=1000;	
	notlastsw=(UGETQNEXT(Pplhnext)!=0);    //not last           //~4C23R~
	if (notlastsw)                                              //~4C22I~
    {                                                           //~4C22I~
		if (Pplhprev->ULHlinenor==Pplhnext->ULHlinenor)
			maxintv=min(Pplhnext->ULHsuffix-Pplhprev->ULHsuffix,maxintv);
		else
			if (Pplhprev->ULHlinenor+1==Pplhnext->ULHlinenor)
				maxintv=maxintv-Pplhprev->ULHsuffix;
		intv=max(1,maxintv/(Pcount+1));	                        //~4C22R~
		for (i=0;intv;i++)	//get power of 10                   //~4C22R~
			intv/=10;                                           //~4C22R~
		intv=Spower[i-1];		//incerement                    //~4C22R~
		suffix=Pplhprev->ULHsuffix;                             //~4C22R~
		lineno=Pplhprev->ULHlinenor;                               //~v0cuI~
    }                                                           //~4C22I~
	else                                                        //~4C22I~
      	lineno=((PULINEH)UGETQPREV(Pplhnext))->ULHlinenor;      //~4C22R~
                                                                   //~v178I~
	if (UGETQPREV(Pplhprev)==0)     //after top hdr                //~v178R~
    	offs  =Pplhnext->ULHoffs;       //file offset              //~v178I~
    else                                                           //~v178I~
    	offs  =Pplhprev->ULHoffs;       //file offset              //~v178R~
                                                                   //~v178I~
    splitno=0;                                                     //~v0agI~
    splitsw=UCBITCHK(Pplhprev->ULHflag2,ULHF2SPLIT1);//has continued line//~v0ajI~
    plh=UGETQNEXT(Pplhprev);                                       //~v0bkI~
    UCBITOFF(plh->ULHflag2,ULHF2SPLIT2);//has no prev line of copyline//~v0bkI~
    plh=UGETQPREV(Pplhnext);                                       //~v0bkI~
    UCBITOFF(plh->ULHflag2,ULHF2SPLIT1);//has no follower of opyline//~v0bkI~
                                                                   //~v178I~
	for (plh=Pplhprev;(plh=UGETQNEXT(plh))!=Pplhnext;)
	{
		if (Pmovesw)//line move                                 //~5131R~
        {                                                       //~5131I~
			if (!plh->ULHupctr)//not updated line move          //~5131I~
       			UCBITON(plh->ULHflag,ULHFMOVE); //result of move lcmd//~5131R~
		}                                                       //~5131I~
		else								//copy or insert    //~5131I~
            UCBITOFF(plh->ULHflag,ULHFMOVE); //reset move       //~5131I~
	  	if (plh->ULHtype==ULHTDATA)                             //~5128R~
	  	{                                                       //~5128R~
            if (splitsw)                                           //~v0ajI~
        		UCBITON(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);//intermediate line//~v0ajI~
			if (notlastsw)                                      //~4C22I~
            {                                                      //~v0cuI~
//  			plh->ULHsuffix=(suffix+=intv);                     //~v0cuR~
    			suffix+=intv;                                      //~v0cuI~
                if (spfsw)                                         //~v0cuR~
                {                                                  //~v0cuI~
                	if (suffix>SPFNUMMAXSUF)                       //~v0cuI~
                    {                                              //~v0cuI~
						++lineno;	//linenoup                     //~v0cuR~
	    				suffix=1;                   //zero is for not isrt//~v0cuI~
                    }                                              //~v0cuI~
    				plh->ULHsuffix=suffix;           //suffix clear//~v0cuR~
					plh->ULHlinenor=lineno;	//linenoup             //~v0cuI~
                }                                                  //~v0cuI~
                else                                               //~v0cuI~
    				plh->ULHsuffix=suffix;                         //~v0cuI~
            }                                                      //~v0cuI~
			else                                                //~4C22I~
            {                                                      //~v0agI~
//  			plh->ULHlinenor=++lineno;                          //~v0agR~
                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))           //~v0agI~
                    plh->ULHsuffix=++splitno;                      //~v0agI~
                else                                               //~v0agI~
                {                                                  //~v0agI~
                    ++lineno;                                      //~v0agI~
                    splitno=0;                                     //~v0agI~
				}                                                  //~v0agI~
    			plh->ULHlinenor=lineno;                            //~v0agI~
            }                                                      //~v0agI~
//        	if (*pfh->UFHcid)   //have cid                      //~v019R~
//              if (!UCBITCHK(plh->ULHflag,ULHFMOVE)) //result of move lcmd//~v019R~
//  				plh->ULHlen=filecidlrecl(plh,pfh);          //~v019R~
            plh->ULHoffs=offs;       //file offset                 //~v178I~
//          plh->ULHeolid=(UCHAR)fsubseteolid(pfh,plh,0);	//no eol string required,get len only//~v50tR~
            plh->ULHeolidid=(UCHAR)fsubseteolid(pfh,plh,0);	//no eol string required,get len only//~v50tI~
            plh->ULHeolid=(UCHAR)(EOLID2LEN(plh->ULHeolidid));     //~v50uR~
		}                                                       //~5128I~
		else         //excluded line                            //~5128I~
	  	{                                                       //~5128I~
			if (notlastsw)                                      //~5128I~
            {                                                      //~v0cvI~
				plh->ULHsuffix=suffix+intv; 	//same as nextline//~5128I~
                if (spfsw)                                         //~v0cvI~
                    if (plh->ULHsuffix>SPFNUMMAXSUF)               //~v0cvI~
                    {                                              //~v0cvI~
                        plh->ULHsuffix=1;                          //~v0cvI~
                        plh->ULHlinenor++;                         //~v0cvR~
                    }                                              //~v0cvI~
            }                                                      //~v0cvI~
			else                                                //~5128I~
				plh->ULHlinenor=lineno+1;		//sanme as next line//~5128I~
		}                                                       //~5128I~

		if (undoupdate(Ppcw,plh,UUHTISRT)==UALLOC_FAILED)//prep undo for data line insrt//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
	}
	if (notlastsw)                                              //~5104I~
//*if step overflow step by 1
      if (spfsw)                                                   //~v0cuI~
      {                                                            //~v0cuI~
      	spfreclen=pfh->UFHlrecl;                                   //~v0cvR~
        spfnumupdsw=0;  //number ovf for spf                       //~v42aI~
		for (;plh;plh=UGETQNEXT(plh))                              //~v0cuI~
		{                                                          //~v0cuI~
        	if (!prevexcludesw)	//if prev exclude,same as exclude  //~v0cuI~
            {                                                      //~v0cuI~
                suffix++;                                          //~v0cuR~
                if (suffix>SPFNUMMAXSUF)                           //~v0cuR~
                {                                                  //~v0cuR~
                    ++lineno;   //linenoup                         //~v0cuR~
                    suffix=1;                   //zero is for not isrt//~v0cuR~
                }                                                  //~v0cuR~
            }                                                      //~v0cuI~
			if (plh->ULHlinenor>lineno)                            //~v0cuI~
            	break;                                             //~v0cuI~
			if (plh->ULHlinenor==lineno)                           //~v0cuI~
				if (plh->ULHsuffix>suffix)                         //~v0cuI~
					break;                                         //~v0cuI~
        	spfnumupdsw=1;  //number ovf for spf                   //~v42aI~
            lenerrsw=(plh->ULHlen!=spfreclen);                     //~v42iR~
            if (lenerrsw)	//no need to set spf num               //~v42iR~
				rc=undoprep(Ppcw,plh,UUHTXSUFFIX);                 //~v0cuI~
            else                                                   //~v42iR~
//  			rc=undoupdate(Ppcw,plh,UUHTRENUM);//set spfnum     //~v42iR~
				rc=undoprep(Ppcw,plh,UUHTXSUFFIX2);	//renum at save//~v42iI~
            if (rc)                                                //~v0cuI~
            	return rc;                                         //~v0cuR~
			plh->ULHlinenor=lineno;                                //~v0cuI~
			plh->ULHsuffix=suffix;                                 //~v0cuI~
		  	if (plh->ULHtype==ULHTEXCLUDE)                         //~v0cuI~
            	prevexcludesw=1;                                   //~v0cuI~
            else                                                   //~v0cuI~
            {                                                      //~v0cuI~
            	prevexcludesw=0;                                   //~v0cuI~
//  	        if (!lenerrsw)	//no need to set spf num           //~v42iR~
//      	    	filesetspfnum(pfh,plh,plh->ULHdata,plh->ULHdbcs,1);//~v42iR~
			}                                                      //~v0cuI~
		}                                                          //~v0cuI~
//*end of spf plh loop                                             //~v42aI~
        if (spfnumupdsw)  //number ovf for spf                     //~v42aI~
            uerrmsg("Line number suffix overflow.",                //~v42aI~
            		"行番号枝番溢れ");                             //~v42aI~
	  }                                                            //~v0cuI~
      else                                                         //~v0cuI~
		for (;plh;plh=UGETQNEXT(plh))                           //~5104R~
		{                                                       //~5104R~
//  		if (plh->ULHtype!=ULHTDATA)                            //~v0cvR~
//  			continue;                                          //~v0cvR~
          if (!prevexcludesw)	//if prev exclude,same as exclude  //~v0cvI~
			suffix++;                                           //~5104R~
			if (plh->ULHlinenor!=Pplhprev->ULHlinenor           //~5104R~
			||  plh->ULHsuffix>suffix)                          //~5104R~
				break;                                          //~5104R~
			if (undoprep(Ppcw,plh,UUHTXSUFFIX)==UALLOC_FAILED)	//save suffix for prep undo//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
			plh->ULHsuffix=suffix;                              //~5104R~
                                                                   //~v0cvI~
		  	if (plh->ULHtype==ULHTEXCLUDE)                         //~v0cvI~
            	prevexcludesw=1;                                   //~v0cvI~
            else                                                   //~v0cvI~
            	prevexcludesw=0;                                   //~v0cvI~
		}                                                       //~5104R~
	else                                                        //~5104I~
    {                                                              //~vbd5I~
		if (undoprep(Ppcw,Pplhnext,UUHTXSUFFIX)==UALLOC_FAILED)	//save suffix for prep undo//~vbd5I~
            return UALLOC_FAILED;                                  //~vbd5I~
		Pplhnext->ULHlinenor=++lineno;	//last hdr line         //~5104I~
    }                                                              //~vbd5I~
	return 0;                                                   //~v04dR~
}//lcmdrenumsuffix
//****************************************************************
// lcmdeditxline
//   edit excluded line
//*parm1:PULINEH of exclude display line
//*rc   :0
//****************************************************************
void lcmdeditxline(PULINEH Pplh)
{
	PULINEH plhn;                                               //~5128I~
    UCHAR   *pc;                                                   //~v10iI~
    UCHAR   wkc[16];                                               //~v10iI~
    int     len;                                                   //~v41iR~
//****************
//  sprintf(Pplh->ULHdata+2,"%05ld",Pplh->ULHlinenow);             //~v10iI~
//  *(Pplh->ULHdata+2+5)=' ';                                      //~v10iI~
//  len=sprintf(wkc," %ld",Pplh->ULHlinenow);                      //~v41iR~
    len=sprintf(wkc,"-%7ld",Pplh->ULHlinenow);                     //~v41iI~
//  offs=8-len;                                                    //~v41iR~
//  if (offs<0)                                                    //~v41iR~
//      offs=0;                                                    //~v41iR~
	pc=Pplh->ULHdata;                                              //~v10iI~
//  memset(pc,'-',8);                                              //~v41iR~
//  memcpy(pc+offs,wkc,(UINT)len);                                 //~v41iR~
    memcpy(pc,wkc,(UINT)len);                                      //~v41iI~
    if (UCBITCHK(Pplh->ULHflag4,ULHF4XSAMEHDR))	//display "same as above"//~v40pI~
		memcpy(pc+sizeof(Sexcludeld),Ssameid,sizeof(Ssameid)-1);	//except last null//~v40pI~
    else                                                           //~v40pI~
		memset(pc+sizeof(Sexcludeld),'-',sizeof(Ssameid)-1);	//except last null//~v40pI~
	Pplh->ULHlinenor=(plhn=UGETQNEXT(Pplh))->ULHlinenor;//of excluded line//~5128R~
	Pplh->ULHsuffix=plhn->ULHsuffix;	//for seq chk at cap    //~5128R~
    UCBITON(Pplh->ULHflag,ULHFDRAW); //redraw                      //~v0hfI~
	return;
}//lcmdeditxline
                                                                //~5105I~
//****************************************************************//~5105I~
// lcmddelxline                                                 //~5105I~
//   delete exclude display line                                //~5105I~
//*parm1:pcw                                                    //~5105I~
//*parm2:PULINEH of exclude display line                        //~5105I~
//*rc   :0 not current top changed, 4:current top deleted then changed//~5105I~
//****************************************************************//~5105I~
int lcmddelxline(PUCLIENTWE Ppcw,PULINEH Pplh)                  //~5105I~
{                                                               //~5105I~
//****************                                              //~5105I~
    lcmddelresetcurtop(Ppcw,Pplh);                                 //~v54GI~
	if (undoprep(Ppcw,Pplh,UUHTDEL)==UALLOC_FAILED)//deq and enq to uuh//~v04dR~
    	return UALLOC_FAILED;                                   //~v04dI~
//  if (Pplh==((PUFILEC)Ppcw->UCWpfc)->UFCcurtop)	//cur top delete//~v54GR~
//  {                                                              //~v54GR~
//      filesetfulldraw(Ppcw);//set full draw and clear drawstartplh//~v54GR~
//  	((PUFILEC)Ppcw->UCWpfc)->UFCcurtop=getdisplayline(Pplh,-1,0);//~v54GR~
//  	return 4;                                                  //~v54GR~
//  }                                                              //~v54GR~
	return 0;                                                   //~5105I~
}//lcmddelxline                                                 //~5105I~
//**************************************************************** //~v54GI~
// lcmddelresetcurtop                                              //~v54GI~
//   mainterans ufccurtop if curtop is deleted                     //~v54GI~
//*parm1:pcw                                                       //~v54GI~
//*parm2:PULINEH deleted                                           //~v54GI~
//*rc   :0                                                         //~v54GI~
//**************************************************************** //~v54GI~
int lcmddelresetcurtop(PUCLIENTWE Ppcw,PULINEH Pplh)               //~v54GI~
{                                                                  //~v54GI~
    PULINEH plhprev;                                               //~v54GI~
    PUFILEC pfc;                                                   //~v54GI~
    PUFILEH pfh;                                                   //~v54GI~
    PUCLIENTWE pcw;                                                //~v54GI~
//****************                                                 //~v54GI~
    xefsubresetcsrplh(0,Pplh);  //reset UFCcsrplh if it point delete line//~v66fI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v54GI~
//  plhprev=getdisplayline(Pplh,-1,0);	//-1:line stepback,0:no step line count output//~v54XR~
    plhprev=0;                                                     //~v54XI~
                                                                   //~v54GI~
	pcw=pfh->UFHbrowsepcw[0];                                      //~v54GI~
    if (pcw)                                                       //~v54GI~
    {                                                              //~v54GI~
		pfc=pcw->UCWpfc;                                           //~v54GI~
    	if (pfc->UFCcurtop==Pplh)                                  //~v54GI~
        {                                                          //~v54GI~
        	if (!plhprev)                                          //~v54XI~
				plhprev=getdisplayline(Pplh,-1,0);	//-1:line stepback,0:no step line count output//~v54XI~
			pfc->UFCcurtop=plhprev;                                //~v54GI~
        	UCBITON(pcw->UCWflag,UCWFDRAW);                        //~v54GI~
        }                                                          //~v54GI~
    }                                                              //~v54GI~
                                                                   //~v54GI~
	pcw=pfh->UFHbrowsepcw[1];                                      //~v54GI~
    if (pcw)                                                       //~v54GI~
    {                                                              //~v54GI~
		pfc=pcw->UCWpfc;                                           //~v54GI~
    	if (pfc->UFCcurtop==Pplh)                                  //~v54GI~
        {                                                          //~v54GI~
        	if (!plhprev)                                          //~v54XI~
				plhprev=getdisplayline(Pplh,-1,0);	//-1:line stepback,0:no step line count output//~v54XI~
			pfc->UFCcurtop=plhprev;                                //~v54GI~
        	UCBITON(pcw->UCWflag,UCWFDRAW);                        //~v54GI~
        }                                                          //~v54GI~
    }                                                              //~v54GI~
                                                                   //~v54GI~
	pcw=pfh->UFHeditpcw;                                           //~v54GI~
    if (pcw)                                                       //~v54GI~
    {                                                              //~v54GI~
		pfc=pcw->UCWpfc;                                           //~v54GI~
    	if (pfc->UFCcurtop==Pplh)                                  //~v54GI~
        {                                                          //~v54GI~
        	if (!plhprev)                                          //~v54XI~
				plhprev=getdisplayline(Pplh,-1,0);	//-1:line stepback,0:no step line count output//~v54XI~
			pfc->UFCcurtop=plhprev;                                //~v54GI~
        	UCBITON(pcw->UCWflag,UCWFDRAW);                        //~v54GI~
        }                                                          //~v54GI~
    }                                                              //~v54GI~
	return 0;                                                      //~v54GI~
}//lcmddelresetcurtop                                              //~v54GI~
//****************************************************************//~5226I~
// lcmdgetplhrange                                              //~5226I~
//   conv count type to range type                              //~5226I~
//*parm1:plh1                                                   //~5226I~
//*parm2:plh2                                                   //~5226I~
//*parm3:lineno                                                 //~5226I~
//*retrn:0:ok, 4:warning(plh1 is changed because it is hdr)     //~5226I~
//*            8:no line(cmd on end of file line)                  //~v0arI~
//****************************************************************//~5226I~
int lcmdgetplhrange(PULINEH *Ppplh1,PULINEH *Ppplh2,int Prepeat)//~5226I~
{                                                               //~5226I~
    int rc;                                                     //~5226I~
    PULINEH plhn;                                                  //~v0arI~
//************************                                      //~5226R~
	if ((*Ppplh1)->ULHtype==ULHTHDR)                            //~5226I~
    {                                                           //~5226I~
//    	*Ppplh1=UGETQNEXT(*Ppplh1);                                //~v0arR~
        if (!(plhn=UGETQNEXT(*Ppplh1)))                            //~v0arR~
        	return 8;                                              //~v0arI~
        *Ppplh1=plhn;                                              //~v0arI~
    	rc=4;                                                   //~5226I~
	}                                                           //~5226I~
	else                                                        //~5226I~
    	rc=0;                                                   //~5226I~
	if (Prepeat==1)		//one                                   //~5226I~
    	*Ppplh2=*Ppplh1;                                        //~5226I~
    else                                                        //~5226I~
		if (!(*Ppplh2=getdisplayline(*Ppplh1,Prepeat-1,0)))	//nth line after//~5226I~
			*Ppplh2=UGETQEND(&UGETPFH(*Ppplh1)->UFHlineque);//over end of line//~5226I~
	return rc;                                                  //~5226I~
}//lcmdgetplhrange                                              //~5226I~
                                                                   //~v0i0I~
//**************************************************************** //~v0i0I~
// lcmdgetplhrange2                                                //~v0i0I~
//   conv count type to range type with stopper                    //~v0i0I~
//*parm1:plh1                                                      //~v0i0I~
//*parm2:plh2                                                      //~v0i0I~
//*parm3:plhstop                                                   //~v0i0I~
//*parm4:lineno                                                    //~v0i0I~
//*retrn:0:ok, 4:warning(plh1 is changed because it is hdr)        //~v0i0I~
//*            8:no line(cmd on end of file line)                  //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdgetplhrange2(PULINEH *Ppplh1,PULINEH *Ppplh2,PULINEH Pplhstop,int Prepeat)//~v0i0I~
{                                                                  //~v0i0I~
    int rc;                                                        //~v0i0I~
    PULINEH plhn;                                                  //~v0i0I~
//************************                                         //~v0i0I~
	if ((*Ppplh1)->ULHtype==ULHTHDR)                               //~v0i0I~
    {                                                              //~v0i0I~
        if (!(plhn=UGETQNEXT(*Ppplh1)))                            //~v0i0I~
        	return 8;                                              //~v0i0I~
        *Ppplh1=plhn;                                              //~v0i0I~
    	rc=4;                                                      //~v0i0I~
	}                                                              //~v0i0I~
	else                                                           //~v0i0I~
    	rc=0;                                                      //~v0i0I~
	if (Prepeat==1)		//one                                      //~v0i0I~
    	*Ppplh2=*Ppplh1;                                           //~v0i0I~
    else                                                           //~v0i0I~
		if (!(*Ppplh2=getdisplayline2(*Ppplh1,Prepeat-1,Pplhstop,0)))	//nth line after//~v0i0R~
			*Ppplh2=UGETQEND(&UGETPFH(*Ppplh1)->UFHlineque);//over end of line//~v0i0I~
	return rc;                                                     //~v0i0I~
}//lcmdgetplhrange2                                                //~v0i0I~
                                                                   //~v0i7I~
//**************************************************************** //~v0hzI~
// lcmdclearcmd                                                    //~v0hzI~
//   clear registered cmd by the reason of del line or exclude cmd //~v181R~
//*parm1:pfh                                                       //~v0hzI~
//*parm2:plh                                                       //~v0hzI~
//*retrn:0:ok, 4:no cmd 8:not registered                           //~v0hzI~
//**************************************************************** //~v0hzI~
int lcmdclearlcmd(PUFILEH Ppfh,PULINEH Pplh)                       //~v0hzI~
{                                                                  //~v0hzI~
	int ii;                                                        //~v0hzI~
//************************                                         //~v0hzI~
	UTRACEP("@@@1 %s:at entry flag=x%x\n",UTT,Pplh->ULHflag);      //~vaz0R~
	if (!UCBITCHK(Pplh->ULHflag,ULHFLINECMD))	//remain not processed lcmd//~v0hzI~
    	return 4;                                                  //~v0hzI~
	UCBITOFF(Pplh->ULHflag,ULHFLINECMD|ULHFLCMDERR);//for undo     //~v0hzI~
	UTRACEP("@@@1 %s:reset flag=x%x, cmd ctr=%d\n",UTT,Pplh->ULHflag,Ppfh->UFHcmdlinectr);//~vaz0R~
	for (ii=Ppfh->UFHcmdlinectr-1;ii>=0;ii--)                      //~v0hzI~
  		if (Ppfh->UFHcmdline[ii]==Pplh)                            //~v0hzI~
        {                                                          //~v0hzI~
			UTRACEP("@@@1 %s:clear cmd=%c,ii=%d\n",UTT,*Pplh->ULHlinecmd,ii);//~vaz0R~
            lcmdclearlcmdplc(Pplh); //clear also Slcmd to protect deleted lcmd process//~v723I~
        	Ppfh->UFHcmdline[ii]=0;                                //~v0hzI~
			UCBITON(Pplh->ULHflag,ULHFDRAW);	//redraw           //~v49bI~
            memset(Pplh->ULHlinecmd,0,sizeof(Pplh->ULHlinecmd));   //~v0hzI~
            break;                                                 //~v0hzI~
    	}                                                          //~v0hzI~
    if (ii>=0)                                                     //~v0hzI~
   		return 0;                                                  //~v0hzI~
	return 8;                                                      //~v0hzI~
}//lcmdclearlcmd                                                   //~v0hzI~
//**************************************************************** //~vb86I~
int lcmdexcludedmsg(int Popt,PUFILEH Ppfh)                         //~vb86R~
{                                                                  //~vb86I~
    int ii,ctr=0;                                                  //~vb86I~
    PULINEH plh;                                                   //~vb86I~
    size_t sz;                                                     //~vb86I~
//**********************                                           //~vb86I~
    for(ii=Ppfh->UFHcmdlinectr-1;ii>=0;ii--)                       //~vb86R~
    {                                                              //~vb86I~
     	plh=Ppfh->UFHcmdline[ii];                                  //~vb86R~
        if (!plh)                                                  //~vb86I~
        	continue;                                              //~vb86I~
    	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                 //~vb86R~
        {                                                          //~vb86M~
            sz=umemspnc(plh->ULHlinecmd,0,sizeof(plh->ULHlinecmd));//~vb86I~
            if (sz!=sizeof(plh->ULHlinecmd)                        //~vb86I~
            &&  toupper(*(plh->ULHlinecmd+sz))!=ULCCMDEXCLUDE      //~vb86I~
            )                                                      //~vb86M~
            {                                                      //~vb86M~
                ctr++;                                             //~vb86I~
                UTRACEP("%s:excluded lcmd=%s,linenor=%d,ctr=%d\n",UTT,plh->ULHlinecmd,plh->ULHlinenor,ctr);//~vb86I~
            }                                                      //~vb86M~
        }                                                          //~vb86M~
    }                                                              //~vb86I~
	if (ctr)                                                       //~vb86R~
    {                                                              //~vb86I~
    	UTRACEP("%s:opt=%x,ctr=%d\n",UTT,Popt,ctr);                //~vb86I~
     	if (!(Popt & LCXMO_NOMSG))                                 //~vb86I~
        {                                                          //~vb88I~
            if (Popt & LCXMO_MSGCAT)                               //~vb86R~
                uerrmsgcat(" ; Excluded lines contains %d line-cmds.",//~vb86R~
                        " ,非\x95\\示部に %d 行の行コマンドがあります",//~vb86R~//~vb88R~
                        ctr);                                      //~vb86R~
            else                                                   //~vb86R~
                uerrmsg("Excluded lines contains %d line-cmds.",   //~vb86R~
                        "非\x95\\示部に %d 行の行コマンドがあります",  //~vb86R~//~vb88R~
                        ctr);                                      //~vb86R~
        }                                                          //~vb88I~
    }                                                              //~vb86I~
    return ctr;                                                    //~vb86I~
}//lcmdexcludedmsg                                                 //~vb86I~
