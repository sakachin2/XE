//*CID://+vbkdR~:                             update#=  139;       //~vbkdR~
//*************************************************************
//*xepan2.c                                                     //~v034R~
//*   end/cancel/exec/field full/pan000/pan300                  //~v020I~
//************************************************************* //~5610I~
//vbkd:180619 like vbj1 cpu8 option to =3.12                       //~vbkdI~
//vb88:170216 stop lcmd "i" continue mode by cut&paste             //~vb88I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vagA:120918 rc chk for ufullpath                                 //~vagAI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va3A:100309 (WINCON:BUG)"RGB value cannot be changed" err at enter on color panel//~va3AI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v8@i:080619 TSO:"=6.TSOxx" support                               //~v8@iI~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v78F:080503 (LNX:BUG)console version issue errmsg "RGB color cannot be changed" issued//~v78FI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v77L:080206 (BUG)EXE cmd ABEND when "END" cmd closed all panel   //~v772I~
//v772:071121*(BUG)filenamelist curdir is not updated just after cd(.) cmd on dirlist//~v772I~
//v771:071120*(W32:BUG)csr always move to last fld when "Enter"    //~v771I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v684:060322 (BUG)for space containing path,dbl click faile on fine name list dir/curdir line//~v684I~
//v678:051227 opt option "RETTOL":return to top of line by return key//~v678I~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v659:050727 (BUG)color pallette change,space clear after once changed temporary is no effect//~v659I~
//            restore from saved at entry                          //~v659I~
//v64s:050630 (XXE)xxe support;(BUG)palette no 8 was drawn same as bg color//~v64sI~
//v64j:050621 (LNX)xxe support;color setting panel(opt 0) col8-15 is highlight(paleetteno is 08 on)//~v64jI~
//v61r:050302 keep edit or browse id on filename queue             //~v61rI~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v54j:040105 (FTP)use ROOTDIR3(remote root support) for ROOTDIR2  //~v54jI~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v20u:001022 LINUX support(drop drive line from filename panel)   //~v20uI~
//v20r:001015 protect color value input when color change not avail//~v20rI~
//v20p:001015 LINUX support(color panel max color=8)               //~v20pI~
//v19B:000924 LINUX support(uninit var warning)                    //~v19BI~
//v19A:000924 (BUG)no beep for pallette change under Windows       //~v19AI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v0jr:980723 call scrdisp for mult cmd because active screen may change//~v0jrI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0j1:980720 concatinated cmd for opt screen(hsp;6;.. rejected. hsp;=6;.. accepted)//~v0j1I~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0iu:980717 cmd compare by strcpy not by memcpy because i and iii is dup//~v0iuI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0hl:980215 (BUG)v09m BUT,after err msg beep only condition need clear//~v0hlI~
//            err msg line.                                        //~v0hlI~
//v0hb:980126 (BUG)when END retuen after error input on pall no    //~v0hbI~
//            no input field value (internaly set 255) is save on opt.//~v0hbI~
//            At next restart time pallette no 255 is used.        //~v0hbI~
//v0ft:971109 allow a\"b c" for filename input                     //~v0ftI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0a8:970706:allow cmd input line copy(lineno atrr and last is input)//~v0a8I~
//v09m:970518:pre-chk missing dest lcmd for copy/move on edit screen//~v09mI~
//            for rapid csr movement                               //~v09mI~
//v095:970405:DPMI version                                         //~v095I~
//            -type chk char * and UCHAR *                         //~v095I~
//v08n:961123:(BUG)when no dir name on filename pannel,set numm filename//~v08nI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v087:961027:when the case RGB value cannot be changed,cursor and err field hiright//~v087I~
//            is on current value field.                           //~v087I~
//v085:961024:W95 VC                                               //~v085I~
//            pan2   :pallette change not avail                    //~v085I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07o:960714:(BUG)filename panel,if dir input is g: it become g:\    --//~v54jR~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v684R~
//v07d:960624:long cmd input at cmd result screen last line        //~v07dI~
//v07a:960615:allow dup key assign to differrent function for only on of assigned key//~v07aI~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v079:960610:color option-2                                       //~v079I~
//            .(BUG)blackout when exit after display menu 0 without no enter//~v079I~
//            .(BUG)cahnge not avail msg even if no input on pallette color//~v079I~
//            .reverse color change req field if window mode err   //~v079I~
//            .(BUG)field full err when insert mode                //~v079I~
//v075:960608:color option                                         //~v075I~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v04h:951007:retrive re-design,same as doskey(no wrap around)  //~v04hI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v044:950918:process cmd at first when both dir lcmd and cmd are used//~v044I~
//*v034:950715:use func_char_pan for dir(field event for dir list)//~v034I~
//*v030:950709:dir2(call exec_dir)                              //~v030I~
//*v020:950610 dir support                                      //~v020R~
//*     950616 field full detect                                //~v020R~
//*     950616 fldprotchk return pfld                           //~v020I~
//*     950628 init csr on filename input fld for pan300        //~v020I~
//*     950628 fld err set only when data input exist           //~v020I~
//*     950701 fld clear detect                                 //~v020I~
//*     950701 csr set chk by gbl                               //~v020I~
//*     950707 csr pos on the end of data for dir name          //~v020I~
//*     950708 change dir support                               //~v020I~
//************************************************************* //~5610I~
//*************************************************************
//*950527 csrhome at func_cmd to avoid to loss vsplit csr pos   //~5527I~
//*950504 comd line input on UCWparm by funccall                //~5504I~
//*950114 retrieve cmd                                          //~5114R~
//*941224 dont exec nextline(current pcw change at xescr after current is set)//~5114I~
//************************************************************* //~4C24I~
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
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>                                              //~5318I~
#include <utrace.h>                                                //~v075I~
#include <uparse.h>                                                //~v0b2R~
#include <uftp.h>                                                  //~v54jI~
#include <u3270.h>                                                 //~v717I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefunc2.h"                                            //~5114I~
#include "xefunct.h"                                            //~5424I~
#include "xepan.h"
#include "xepan2.h"
#include "xefile.h"                                             //~v020I~
#include "xefile13.h" 	//filefnquate                              //~v0ftI~
#include "xefile2.h" 	//filesetcsr                               //~v678I~
#include "xefile7.h" 	//filefk                                   //~v0ifI~
#include "xesub.h"                                                 //~v74xM~
#include "xepan22.h"                                               //~v20yM~
#include "xedir.h"                                              //~v020I~
#include "xedlcmd.h"                                            //~v034I~
#include "xedlcmd6.h"                                              //~v76gI~
#include "xedcmd2.h"                                               //~v07dI~
#include "xelcmd.h"                                                //~v78SR~
#include "xelcmd2.h"                                               //~v78SR~
#include "xegbl.h"                                                 //~v20pI~
#include "xeopt.h"                                                 //~v678I~
#include "xeerr.h"                                                 //~v76mI~
#include "xeundo.h"                                                //~v780I~
#include "xesyn.h"                                                 //~v780I~
#include "xetso.h"                                                 //~v8@iI~
//**************************************************************** //~v075I~
//****************************************************************
static char Sattrtbl[COLOR_COUNT*2];                               //~v075R~
static UCHAR Spallassigntbl[PAL_MAXENTRY*2];                       //~v075I~
static char Spallette[16];                                         //~v075I~
static int Soptdone=0;                                             //~v54jR~
//**************************************************************** //~v075I~
int panfunc000(PUCLIENTWE Ppcw,UCHAR *Pcmd);
int putexitcmd(int Pfuncid,UCHAR *Pcmd);                        //~5224I~
int panopt(PUCLIENTWE Ppcw);                                       //~v075I~
int pancallfname(UCHAR Pmenuid,UCHAR *Phdrstring);              //~5611R~
int panfe300(PUCLIENTWE Ppcw,PUFLD Ppfld,UCHAR *Pdata,int Peventid);//~v020I~
int panexec300(PUCLIENTWE Ppcw);                                //~v020I~
int panexecolor(PUCLIENTWE Ppcw);                                  //~v075I~
UCHAR getpalno(PUCLIENTWE Ppcw,int Prow,int Pfldno);               //~v075R~
int panfiletol(PUCLIENTWE Ppcw);                                   //~v678I~
#ifndef UNX                                                        //~va00I~
int pan300setdirline(PUCLIENTWE Ppcw,char *Ppath);                 //~v684I~
#endif                                                             //~va00I~
//int pansend(int Popt,PUCLIENTWE Ppcw);                           //~v76mR~
int panfind(PUCLIENTWE Ppcw,int Popt);                             //~v76mI~
//****************************************************************
//* end command
//****************************************************************
int func_end_pan(PUCLIENTWE Ppcw)
{
//************************************                             //~v075I~
    if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~v77LR~
    	return funcerrexecmdinprog();                              //~v77LR~
	if (((PUPANELC)(Ppcw->UCWppc))->UPCid==PANOPTCOLOR)            //~v075I~
    {                                                              //~v075I~
    	memcpy(Gpallassigntbl,Spallassigntbl,sizeof(Spallassigntbl));//input//~v075R~
    	memcpy(Gattrtbl,Sattrtbl,sizeof(Sattrtbl));//created from Spallassigntbl input//~v075I~
	}                                                              //~v075I~
	if (!panpopup(Ppcw))	//no stacked client
		return -1;			//quit
	return 0;
}
//****************************************************************//~4C25I~
//* cancel command                                              //~4C25I~
//****************************************************************//~4C25I~
int func_cancel_pan(PUCLIENTWE Ppcw)                            //~4C25I~
{                                                               //~4C25I~
    int rc=0;                                                      //~v075I~
//************************************                             //~v075I~
	if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~v77LR~
    	return funcerrexecmdinprog();                              //~v77LR~
	if (((PUPANELC)(Ppcw->UCWppc))->UPCid==PANOPTCOLOR)//mut be restore//~v075I~
	  if (!UCBITCHK(Gscrstatus,GSCRSEXTSG)) //bypass reset at termination//~v085I~
	    rc=scrsetpallette(Spallette);//saved at opt,change pallette and set to Gpallette//~v075I~
	if (!panpopup(Ppcw))	//no stacked client                 //~4C25I~
		return -1;			//quit                              //~4C25I~
	return rc;                                                     //~v075R~
}//func_cancel_pan                                                 //~v085R~
//****************************************************************
//* exec key for panel
//****************************************************************
int func_exec_pan(PUCLIENTWE Ppcw)
{
	UCHAR *cmd;                                                 //~5504R~
	int rc=0;                                                      //~v19BR~
  	PUSCRD psd;
  	PUSCRD psd0;                                                   //~v0hlI~
    PUFILEC pfc;                                                   //~v0a8I~
    PUFILEH pfh;                                                   //~v0a8I~
    PULINEH plhlcmdi;                                              //~v78SI~
    int lcmdctr;                                                   //~v0a8I~
    int csroneditsw=0;                                             //~v678I~
    int plhlcmdi_upundoctr;                                        //~vb88I~
//************************************
	UCBITOFF(Gprocstatus,GPROCSCSRSET);                         //~v020I~
//  UCBITON((psd=Ppcw->UCWpsd)->USDflag2,USDF2DRAW);//draw hdr line for clear errmsg//~4C24I~,//~v09mR~
    psd0=                                                          //~v0hlI~
    psd=Ppcw->UCWpsd;                                              //~v09mI~
  	if (UCBITCHK(Ppcw->UCWflag,UCWFCMDERR))//previous cmd err
  	{
  		UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err
  		++psd;								//cmd line
  		UCBITON(psd->USDflag2,USDF2DRAW);   //req re-draw for clear
  	}
// 	if (getfldpos(Ppcw,CMDLINENO,0,&pc),*pc)//data on cmd fld(may be space)//~5504R~
 	if (cmd=Ppcw->UCWparm,cmd)//data on cmd fld(may be space)   //~5504I~
	{
//  	len=getfldinput(Ppcw,CMDLINENO,0,cmd);                  //~5504R~
		setflddata(Ppcw,CMDLINENO,0,"");//may set later at func_cmd//~5224R~
//  	if (len)                                                //~5504R~
	}
  	else                                                        //~5504R~
    	cmd="";                                                 //~5504R~
//  funccmdstack(cmd,(int)strlen(cmd));	//save for retrieve        //~v670R~
#ifdef UTF8SUPPH                                                   //~va1rI~
    funccmdstack_utf8(FCSO_SETCT,cmd,(int)strlen(cmd),Ppcw->UCWseqno);	//save for retrieve  width codetbl//~va1rI~
#else                                                              //~va1rI~
    funccmdstack(cmd,(int)strlen(cmd),Ppcw->UCWseqno);	//save for retrieve//~v670I~
#endif                                                             //~va1rI~
   	if (*cmd)                                                   //~5527R~
    	if (Ppcw->UCWrcsry==CMDLINENO)                          //~5527R~
        {                                                       //~5527I~
            Ppcw->UCWvsplitx=Gcsrposx; //save for vsplit cmd    //~5527I~
        	csrhomepos(0);	//move csr to 1st fld of current active//~5527R~
        }                                                       //~5527I~
	
	switch(((PUPANELC)Ppcw->UCWppc)->UPCid)
	{
	case PANTOPMENU:
		if (rc=panfunc000(Ppcw,cmd),rc)
			return rc;
		break;
	case PANOPTCOLOR:		//color option                         //~v075I~
   		if (!*cmd)                                                 //~v075I~
			rc=panexecolor(Ppcw);                                  //~v075I~
        else                                                       //~v075I~
            rc=0;                                                  //~v075I~
		strcpy(Gcmdbuff,cmd);                                      //~v075I~
		break;                                                     //~v075I~
	case PANFBROWSE:
		rc=func_exec_file(Ppcw);		
		strcpy(Gcmdbuff,cmd);
		break;
	case PANFEDIT  :
        pfc=Ppcw->UCWpfc;                                          //~v0a8R~
		pfh=pfc->UFCpfh;                                           //~v0a8I~
		lcmdctr=pfh->UFHcmdlinectr; 			//cmd line exist   //~v0a8I~
	    UTRACEP("@@@1 %s:cmdlinectr=%d\n",UTT,pfh->UFHcmdlinectr); //~vagAI~
		plhlcmdi=pfh->UFHplhlcmdi; 			//before execute lcmd  //~v78SR~
		plhlcmdi_upundoctr=pfh->UFHplhlcmdi_upundoctr;             //~vb88I~
		rc=func_exec_file(Ppcw);		
		strcpy(Gcmdbuff,cmd);
        if (Ppcw->UCWmenuopt==PANMOCMD                             //~v07dI~
	    &&  !lcmdctr                                               //~v0a8I~
        &&  !rc && !*Gcmdbuff)                                     //~v07dI~
        	rc=dcmdlongcmd(Ppcw);		//chk last line cmd input  //~v07dR~
        if (Ppcw->UCWlinenosz)			//num on(cmdresult may be 0//~v678I~
	        csroneditsw=CSRONFILEDATA(Ppcw);	//csr on edit area before func_nextline//~v678R~
        if (!UCBITCHK(Goptopt2,GOPT2_NOCONTINS))                   //~v78SR~
        {                                                          //~v78SI~
        	if (plhlcmdi)	//previously inserted                  //~v78SI~
                if (pfh->UFHplhlcmdi==plhlcmdi)   //not new isrt   //~v78SR~
                {                                                  //~v78SR~
                    if (!rc                                        //~v78SR~
                    &&  !*Gcmdbuff                                 //~v78SR~
                    &&  plhlcmdi_upundoctr==pfh->UFHupundoctr      //~vb88R~
                    &&  !pfh->UFHpendctr                           //~v78SR~
                    )                                              //~v78SR~
                        rc=lcmdisrtcont(0,Ppcw,pfh);               //~v78SR~
                    else                                           //~v78SR~
                        pfh->UFHplhlcmdi=0;                        //~v78SR~
                }                                                  //~v78SR~
        }                                                          //~v78SI~
#ifdef SYNSUPP                                                     //~v780I~
        if (!rc && !*Gcmdbuff)                                     //~v780I~
    	    xesynexecenter(0,Ppcw,pfh);                            //~v780R~
#endif                                                             //~v780I~
		break;
	case PANFNAME  :		//filename                          //~5611I~
   		if (!*cmd)                                              //~v020I~
			rc=panexec300(Ppcw);		                        //~v020R~
        else                                                    //~v020I~
            rc=0;                                               //~v020I~
		strcpy(Gcmdbuff,cmd);                                   //~v020I~
		break;                                                  //~5611I~
	case PANDIR    :		//dir list                          //~v030I~
   		if (!*cmd)                                              //~v044I~
			rc=func_exec_dir(Ppcw);		                        //~v044R~
        else                                                    //~v044I~
            rc=0;                                               //~v044I~
      if (Ppcw->UCWreason==UCWRCMDSET)                             //~v75JI~
      {                                                            //~v75JI~
      	Ppcw->UCWreason=0;                                         //~v75JR~
        if (*cmd)                                                  //~v75JR~
        {                                                          //~v75JI~
        	strcat(Gcmdbuff,";");                                  //~v75JI~
        	strcat(Gcmdbuff,cmd);                                  //~v75JI~
        }                                                          //~v75JI~
      }                                                            //~v75JI~
      else                                                         //~v75JI~
		strcpy(Gcmdbuff,cmd);                                   //~v030I~
		break;                                                  //~v030I~
	case PANUCOMP  :		//compare                              //~v76gI~
   		if (!*cmd)                                                 //~v76gI~
        {                                                          //+vbkdI~
			rc=pancompexec(Ppcw);                                  //~v76gR~
        	if (*Gcmdbuff)                                         //+vbkdI~
            	cmd=Gcmdbuff; //cmd to edit redirectfile           //+vbkdI~
        }                                                          //+vbkdI~
        else                                                       //~v76gI~
            rc=0;                                                  //~v76gI~
        strcpy(Gcmdbuff,cmd); //comare set cmd "edit redirect file" //~v76gR~
		break;                                                     //~v76gI~
	case PANUGREP  :		//grep                                 //~v76gI~
   		if (!*cmd)                                                 //~v76gI~
			rc=pangrepexec(Ppcw);                                  //~v76gR~
        else                                                       //~v76gI~
            rc=0;                                                  //~v76gI~
        strcpy(Gcmdbuff,cmd);                                      //~v76gR~
		break;                                                     //~v76gI~
	}
	if (!rc && !*Gcmdbuff	//rc==0,no cmd input residual       //~4C24R~
	&&  !UCBITCHK(Gprocstatus,GPROCSCSRSET))                    //~v020R~
    {                                                              //~v678I~
			rc=func_nextline(Ppcw);                             //~4C24R~
        if (Goptopt & GOPT_RETTOL   //set csr to 1st col           //~v678I~
        &&	csroneditsw)                                           //~v678R~
            panfiletol(Ppcw);                                      //~v678I~
    }                                                              //~v678I~
    if (rc && rc!=1)	//for beep but no errmsg case,clear old msg//~v0hlI~
	    UCBITON(psd0->USDflag2,USDF2DRAW);//draw hdr line for clear errmsg//~4C24I~,//~v0hlI~
	return rc;
}//func_exec_pan
//**************************************************************** //~v76gI~
//* RESET cmd or Esc twice                                         //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panreset(PUCLIENTWE Ppcw)                                      //~v76gI~
{                                                                  //~v76gI~
	PUPANELC ppc;                                                  //~v76gI~
//*****************                                                //~v76gI~
	ppc=Ppcw->UCWppc;                                              //~v76gI~
	switch(ppc->UPCid)                                             //~v76gI~
    {                                                              //~v76gI~
	case PANUCOMP  :		//compare                              //~v76gI~
	case PANUGREP  :		//grep                                 //~v76gI~
    	panutilreset(0,Ppcw,ppc->UPCid);                           //~v76gI~
		break;                                                     //~v76gI~
    }                                                              //~v76gI~
    return 0;                                                      //~v76gI~
}//panreset                                                        //~v76gR~
//**************************************************************** //~v76gI~
//* send/recv filename insert mode by dns                          //~v76gI~
//**************************************************************** //~v76gI~
int func_sendins_pan(PUCLIENTWE Ppcw)                              //~v76gI~
{                                                                  //~v76gI~
	return dlcmdsenddnd(PANSENDO_INS,Ppcw);                        //~v76gI~
}//func_senins_pan                                                 //~v76gI~
//**************************************************************** //~v76gI~
//* send/recv filename replace mode by dns                         //~v76gI~
//**************************************************************** //~v76gI~
int func_sendrep_pan(PUCLIENTWE Ppcw)                              //~v76gI~
{                                                                  //~v76gI~
	return dlcmdsenddnd(PANSENDO_REP,Ppcw);                        //~v76gI~
}//func_senrep_pan                                                 //~v76gI~
//**************************************************************** //~v76mI~
//!func_find_pan                                                   //~v76mI~
//*case sensitive search                                           //~v76mI~
//*ret  :rc                                                        //~v76mI~
//**************************************************************** //~v76mI~
int func_find_pan(PUCLIENTWE Ppcw)                                 //~v76mI~
{                                                                  //~v76mI~
	return panfind(Ppcw,0);//0:find,case,forward                   //~v76mR~
}//func_find_pan                                                   //~v76mI~
//**************************************************************** //~v76mI~
//!func_ifind_pan                                                  //~v76mI~
//*case insensitive search                                         //~v76mI~
//*ret  :rc                                                        //~v76mI~
//**************************************************************** //~v76mI~
int func_ifind_pan(PUCLIENTWE Ppcw)                                //~v76mI~
{                                                                  //~v76mI~
	return panfind(Ppcw,PANFIND_ICASE);                            //~v76mR~
}//func_ifind_pan                                                  //~v76mI~
//**************************************************************** //~v76gI~
//* send/recv filename insert mode                                 //~v76gI~
//**************************************************************** //~v76gI~
int func_rfind_pan(PUCLIENTWE Ppcw)                                //~v76gR~
{                                                                  //~v76gI~
	return panfind(Ppcw,PANFIND_RFIND);                            //~v76mI~
//  return pansend(PANSENDO_REP,Ppcw);                             //~v76mR~
}//func_rfind_pan                                                  //~v76mR~
//**************************************************************** //~v76mI~
//* send/recv filename insert mode                                 //~v76mI~
//**************************************************************** //~v76mI~
int func_revrfind_pan(PUCLIENTWE Ppcw)                             //~v76mI~
{                                                                  //~v76mI~
	return panfind(Ppcw,PANFIND_RFIND|PANFIND_REV);                //~v76mI~
}//func_revrfind_pan                                               //~v76mI~
////****************************************************************//~v76mR~
////* find:open dir for util panel                                 //~v76mR~
////* retrn:rc                                                     //~v76mR~
////****************************************************************//~v76mR~
//int pansend(int Popt,PUCLIENTWE Ppcw)                            //~v76mR~
//{                                                                //~v76mR~
//    PUPANELC ppc;                                                //~v76mR~
//    int rc;                                                      //~v76mR~
////*****************                                              //~v76mR~
//    ppc=Ppcw->UCWppc;                                            //~v76mR~
//    switch(ppc->UPCid)                                           //~v76mR~
//    {                                                            //~v76mR~
//    case PANUCOMP  :        //compare                            //~v76mR~
//    case PANUGREP  :        //grep                               //~v76mR~
//        rc=panutilfind(Popt,Ppcw,ppc->UPCid);                    //~v76mR~
//        break;                                                   //~v76mR~
//    default:                                                     //~v76mR~
//        rc=funcinvalidkey(Ppcw);                                 //~v76mR~
//    }                                                            //~v76mR~
//    return rc;                                                   //~v76mR~
//}//pansend                                                       //~v76mR~
//**************************************************************** //~v76mI~
//* find:open dir for util panel                                   //~v76mI~
//* retrn:rc                                                       //~v76mI~
//**************************************************************** //~v76mI~
int panfind(PUCLIENTWE Ppcw,int Popt)                              //~v76mI~
{                                                                  //~v76mI~
	PUPANELC ppc;                                                  //~v76mI~
//  int rc,scrtypeerr=1;                                           //~vaf9R~
    int rc=0,scrtypeerr=1;                                         //~vaf9I~
//*****************                                                //~v76mI~
	ppc=Ppcw->UCWppc;                                              //~v76mI~
	switch(ppc->UPCid)                                             //~v76mI~
    {                                                              //~v76mI~
	case PANFNAME  :		//grep                                 //~v76mI~
    	scrtypeerr=0;                                              //~v76mI~
    	rc=panfnlfind(Popt,Ppcw);                                  //~v76mI~
		break;                                                     //~v76mI~
	case PANUCOMP  :		//compare                              //~v76mI~
	case PANUGREP  :		//grep                                 //~v76mI~
		if (Ppcw->UCWkeytype!=UCWKTCMD	//func key                 //~v76mI~
    	&&  (Popt & PANFIND_RFIND)                                 //~v76mR~
    	&&  !(Popt & PANFIND_REV))                                 //~v76mI~
        {                                                          //~v76mI~
	    	scrtypeerr=0;                                          //~v76mI~
    		rc=panutilfind(Popt,Ppcw,ppc->UPCid);                  //~v76mI~
        }                                                          //~v76mI~
		break;                                                     //~v76mI~
    }                                                              //~v76mI~
	if (scrtypeerr)                                                //~v76mI~
    {                                                              //~v76mI~
		if (Ppcw->UCWkeytype==UCWKTCMD)	//cmd                      //~v76mI~
		    rc=errscrtype(((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);	//reset Execute to cmd processor//~v76mR~
        else                                                       //~v76mI~
        	rc=funcinvalidkey(Ppcw);                               //~v76mI~
    }                                                              //~v76mI~
    return rc;                                                     //~v76mI~
}//panrfind                                                        //~v76mI~
//**************************************************************** //~v678I~
//* csr set to top of line of edit panel                           //~v678I~
//**************************************************************** //~v678I~
int panfiletol(PUCLIENTWE Ppcw)                                    //~v678I~
{                                                                  //~v678I~
    PULINEH plh;                                                   //~v678I~
    PUFILEH pfh;                                                   //~v678I~
	PUSCRD psd;                                                    //~v678I~
//*******************                                              //~v678I~
    if (!CSRONFILELINE(Ppcw))	//not file lne data                //~v678I~
    	return 0;                                                  //~v678I~
	psd=Ppcw->UCWpsd;		//hdr line                             //~v678I~
    psd+=Ppcw->UCWrcsry;                                           //~v678I~
    plh=psd->USDbuffc;                                             //~v678R~
    if (!plh)                                                      //~v678I~
    	return 0;                                                  //~v678I~
    pfh=UGETPFH(plh);                                              //~v678I~
    if (plh->ULHtype==ULHTHDR)                                     //~v678R~
    	return 0;                                                  //~v678I~
   	if (pfh->UFHtype==UFHTKFI)	//ke func ini file                 //~v678I~
    	func_nexttab_file(Ppcw);                                   //~v678R~
    else                                                           //~v678I~
    	filesetcsr(Ppcw,plh,1,0);                                  //~v678R~
    return 1;                                                      //~v678I~
}//panfiletol                                                      //~v678I~
//****************************************************************//~v020I~
//* field full/clear event (from xefunc2/xechar)                //~v020R~
//* parm1:pcw                                                   //~v020I~
//* parm2:event id(full/cleared)                                //~v020I~
//*ret :rc                                                      //~v020I~
//****************************************************************//~v020I~
int panfieldevent(PUCLIENTWE Ppcw,int Peventid)                 //~v020R~
{                                                               //~v020I~
	int rc=0,pfli;                                              //~v020I~
    PUFLD  pfld;                                                //~v020I~
	char wkbuff[MAXCOLUMN];                                     //~v020I~
//************************************                          //~v020I~
	if ((pfli=fldprotchk(Ppcw,FPC_NODBCSCHK,&pfld))<0)          //~v020R~
		return 4;	//internal login err                        //~v020I~
	if (!getfldinput(Ppcw,Ppcw->UCWrcsry,pfli,wkbuff))//input data//~v020I~
		Peventid=PFE_CLEAR;//all space                          //~v020R~
	switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                     //~v020I~
	{                                                           //~v020I~
	case PANTOPMENU:                                            //~v020I~
		break;                                                  //~v020I~
	case PANFBROWSE:                                            //~v020I~
		break;                                                  //~v020I~
	case PANFEDIT  :                                            //~v020I~
		break;                                                  //~v020I~
	case PANFNAME  :		//filename                          //~v020I~
    	rc=panfe300(Ppcw,pfld,wkbuff,Peventid);	//field full process//~v020R~
		break;                                                  //~v020I~
	case PANDIR   :		//dir list                              //~v034R~
    	rc=dlcmdfe(Ppcw,&pfld->UFLentry[pfli],wkbuff,Peventid);	//field full process//~v034R~
		break;                                                  //~v034I~
	}                                                           //~v020I~
	return rc;                                                  //~v020I~
}//panfieldevent                                                //~v034R~
                                                                //~v020I~
//**************************************************************** //~v0j1I~
//* panel 000 option process for concatinated cmd string           //~v0j1I~
//* parm1:pcw                                                      //~v0j1I~
//* parm2:cmd string                                               //~v0j1I~
//* parm3:rc of called func                                        //~v0j1I~
//* ret  :1:1st cmd is valid option and executed,0:not valid option//~v0j1I~
//**************************************************************** //~v0j1I~
int panfunc000optchk(PUCLIENTWE Ppcw,UCHAR *Pcmd,int *Prc)         //~v0j1I~
{                                                                  //~v0j1I~
    int rc;                                                        //~v0j1I~
//****************                                                 //~v0j1I~
	rc=panfunc000(Ppcw,Pcmd);                                      //~v0j1R~
    *Prc=rc;                                                       //~v0j1I~
    if (Soptdone)			//set next cmd string                  //~v0j1R~
    {                                                              //~v0j1I~
        if (!rc)                                                   //~v0j1M~
			setflddata(Ppcw,CMDLINENO,0,"");//clear on top menu    //~v0j1M~
    }                                                              //~v0j1I~
    else                    //not set next cmd string              //~v0j1I~
	    *Gcmdbuff=0;		//ignore panfunc000 output             //~v0j1R~
    return Soptdone;                                               //~v0j1R~
}//panfunc000optchk                                                //~v0j1I~
//****************************************************************
//* panel 000 option process
//****************************************************************
int panfunc000(PUCLIENTWE Ppcw,UCHAR *Pcmd)
{
	UCHAR cmd[MAXCOLUMN+1];                                        //~v0imR~
    int rc=0;                                                   //~v04dI~
//****************
	Soptdone=0;			//info to panfunc000optchk                 //~v0j1I~
	if (!*Pcmd)
		return 0;                                               //~5224R~
	if (getcmdstr(Pcmd,cmd)!=1)                                 //~5224R~
	{
        if (!strcmp(cmd,PANMOPARM_COLOR))                          //~v0ifR~
        	*cmd=PANMOPARM;                                        //~v0ifI~
        else                                                       //~v0ifI~
	        if (!strcmp(cmd,PANMOPARM_KCMD))                       //~v0jaR~
        		*cmd=PANMOPARMFK_KCMD;	//func key                 //~v0jaR~
            else                                                   //~v0imI~
	        if (!strcmp(cmd,PANMOPARM_KLIST))                      //~v0jaR~
        		*cmd=PANMOPARMFK_KLIST;	//func key                 //~v0jaR~
            else                                                   //~v0ioI~
	        if (!strcmp(cmd,PANMOPARM_FKEY))                       //~v0jaR~
        		*cmd=PANMOPARMFK_FKEY;	//func key                 //~v0jaR~
//          else                                                   //~v0iwR~
//          if (!strcmp(cmd,PANMOPARM_FKEY4))                      //~v0iwR~
//      		*cmd=PANMOPARMFK4;	//func key                     //~v0iwR~
            else                                                   //~v76gI~
            if (!strcmp(cmd,PANMOPARM_UCOMP))                      //~v76gI~
        		*cmd=PANMOPARM_UCOMPID;	//func key                 //~v76gI~
            else                                                   //~v76gI~
            if (!strcmp(cmd,PANMOPARM_UGREP))                      //~v76gI~
        		*cmd=PANMOPARM_UGREPID;	//func key                 //~v76gI~
            else                                                   //~v0ioI~
            {                                                      //~v0ifI~
#ifdef FTPSUPP                                                     //~v8@iI~
                if (*Pcmd==PANMOCMD && *(Pcmd+1)=='.' )            //~v8@iR~
                {                                                  //~v8@iI~
                    rc=xetsorsh6(0,Gcmdbuff,Pcmd);//set "6;tso TSOxxx logon" cmd for tso destination//~v8@iI~
                    if (rc>=0)            //0:valid tso rsh,else err,-1:continue process//~v8@iI~
                    	return rc;                                 //~v8@iI~
                }                                                  //~v8@iI~
#endif                                                             //~v8@iI~
		strcpy(Gcmdbuff,Pcmd);	//set cmd string after option
		return 0;
        	}                                                      //~v0ifI~
	}
	Soptdone=1;			//info to panfunc000optchk                 //~v0j1I~
	switch(toupper(*cmd))                                       //~5224R~
	{
	case PANMOPARM:                                                //~v075R~
//  	uerrmsg("Available soon","近日公開");                      //~v075R~
        rc=panopt(Ppcw);                                           //~v075I~
		break;
	case PANMOPARMFK_KCMD:		//key cmd                          //~v0jaR~
        rc=filefk(Ppcw,FILEFK_OPTKCMD);                            //~v0jaR~
		break;                                                     //~v0ifI~
	case PANMOPARMFK_FKEY:		//func and key                     //~v0jaM~
        rc=filefk(Ppcw,FILEFK_OPTFKEY);                            //~v0jaI~
		break;                                                     //~v0imI~
	case PANMOPARMFK_KLIST:		//key and func                     //~v0jaM~
        rc=filefk(Ppcw,FILEFK_OPTKLIST);                           //~v0jaI~
		break;                                                     //~v0ioI~
//  case PANMOPARMFK4:		//func and key                         //~v0iwR~
//      rc=filefk(Ppcw,FILEFK_OPT05);                              //~v0iwR~
//  	break;                                                     //~v0iwR~
	case PANMOBROWSE:                                           //~5611R~
    	rc=pancallfname(PANMOBROWSE,"BROWSE");                  //~v04dR~
		break;
	case PANMOEDIT:                                             //~5611R~
    	rc=pancallfname(PANMOEDIT,"EDIT--");                    //~v04dR~
		break;
//@ case PANMOFILE:                                             //~v020R~
//@ 	pancallfname(PANMOFILE,"FILE--");                       //~v020R~
//@ 	break;                                                  //~v020R~
    case PANMOPARM_UCOMPID:                                        //~v76gI~
    	pancomp(Ppcw);                                             //~v76gI~
    	break;                                                     //~v76gI~
    case PANMOPARM_UGREPID:                                        //~v76gR~
    	pangrep(Ppcw);                                             //~v76gI~
    	break;                                                     //~v76gI~
	case PANMOCMD:                                              //~v06nR~
    	rc=fileeditso(Ppcw);//first edit screen                       //~v06tR~
		break;
	case 'X':                                                   //~5224I~
    	return putexitcmd(FUNCID_EXIT,Pcmd);                    //~5224R~
	case 'R':                                                   //~5503R~
    	return putexitcmd(FUNCID_TERM,Pcmd);                    //~5224R~
	case 'Q':                                                   //~5224R~
    	return putexitcmd(FUNCID_QUIT,Pcmd);                    //~5224R~
	default:
		Soptdone=0;			//info to panfunc000optchk             //~v0j1I~
		strcpy(Gcmdbuff,Pcmd);	//set cmd string after option
		return 0;
	}//by first option char
	getnextcmd(Pcmd,Gcmdbuff);	//set cmd string after option
    if (!rc)                                                       //~v0j1R~
        if (*Gcmdbuff)                                             //~v0j1R~
    		scrdisp();                                             //~v0j1R~
	return rc;                                                  //~v04dR~
}//panfunc000
                                                                //~5224I~
//****************************************************************//~5224I~
//* put exit cmd text to cmd buff                               //~5224I~
//* parm :funcid                                                //~5224I~
//* retrn:rc                                                    //~5224I~
//****************************************************************//~5224I~
int putexitcmd(int Pfuncid,UCHAR *Pcmd)                         //~5224R~
{                                                               //~5224I~
	FUNCTBL *pft;	                                            //~5224I~
    int cmdlen;                                                    //~v0iuI~
//*****************                                             //~5224I~
	getnextcmd(Pcmd,Gcmdbuff);	//get next cmd string after option//~5224I~
	if (!(pft=functblsrch(Pfuncid)))                            //~5224I~
    	return 4;                                               //~5224I~
//  memmove(Gcmdbuff+pft->FTcmdlen+1,Gcmdbuff,strlen(Gcmdbuff)+1);//set cmd string after option//~v0iuR~
//  memcpy(Gcmdbuff,pft->FTcmd,(UINT)pft->FTcmdlen);	//insert cmd//~v0iuR~
//  *(Gcmdbuff+pft->FTcmdlen)=';';	//delm                         //~v0iuR~
	cmdlen=(int)strlen(pft->FTcmd);                                //~v0iuI~
    memmove(Gcmdbuff+cmdlen+1,Gcmdbuff,strlen(Gcmdbuff)+1);//set cmd string after option//~v0iuI~
    memcpy(Gcmdbuff,pft->FTcmd,(UINT)cmdlen);	//insert cmd       //~v0iuI~
    *(Gcmdbuff+cmdlen)=';';	//delm                                 //~v0iuI~
    return 0;                                                   //~5224I~
}//putexitcmd                                                   //~5224I~
                                                                //~5610I~
//****************************************************************//~5610I~
//* display file name input panel  v020                         //~5611R~
//* parm1 :funcid(1:browse,2:edit,3:filer)                      //~5611R~
//* parm2 :header string                                        //~5611I~
//* retrn:rc                                                    //~5610I~
//****************************************************************//~5610I~
int pancallfname(UCHAR Pmenuid,UCHAR *Phdrstring)               //~5611I~
{                                                               //~5610I~
	PUCLIENTWE pcw;                                             //~5611I~
//*****************                                             //~5610I~
    pcw=panregist(PANFNAME);		//top menu setup;           //~5611R~
    UALLOCCHK(pcw,8);               //return if storage shortage//~v04dI~
    pcw->UCWmenuopt=Pmenuid;		//save original function    //~5611I~
    setflddata(pcw,0,0,Phdrstring);                             //~5611R~
//  csronthefld(pcw,PANL300FILENAME,0,0);   //filename fld         //~v76mR~
	UCBITON(pcw->UCWflag,UCWFWAKEUP);//call pan300updatelist after menuopt setup//~v61rR~
    return 0;                                                   //~5610I~
}//pancallfname                                                 //~v020R~
                                                                //~5610I~
//****************************************************************//~v020I~
//* pandraw300                                                  //~v020I~
//* set draw data of filename entry panel                       //~v020I~
//* parm1 :pcw                                                  //~v020I~
//* retrn:rc                                                    //~v020I~
//****************************************************************//~v020I~
void pandraw300(PUCLIENTWE Ppcw)                                //~v020I~
{                                                               //~v020I~
    UCHAR curdir[_MAX_PATH];                                    //~v020I~
    UCHAR encpath[_MAX_PATH];                                      //~v684I~
    int rc;                                                        //~v684I~
    char *pc;                                                      //~vagAI~
//*****************                                             //~v020I~
	if (UCBITCHK((Ppcw->UCWpsd+PANL300CURRENT)->USDflag2,USDF2DRAW))//~v020I~
    {                                                           //~v020I~
//  	ufullpath(curdir,".\\",_MAX_PATH);//cur dir get            //~v19aR~
      pc=                                                          //~vagAI~
    	ufullpath(curdir,"." DIR_SEPS,_MAX_PATH);//cur dir get     //~v19aI~
        if (!pc)                                                   //~vagAI~
            return;                                                //~vagAI~
        rc=uparsein(curdir,encpath,sizeof(encpath),0,'\"');        //~v684I~
        if (rc==1||rc==2)	//space containing)                    //~v684I~
        	strcpy(curdir,encpath);                                //~v684I~
#ifdef UTF8SUPPH                                                   //~va00R~
	    BYUTF8_pansetflddata(0,Ppcw,PANL300CURRENT,0,curdir);      //~va00R~
#else                                                              //~va00R~
	    setflddata(Ppcw,PANL300CURRENT,0,curdir);               //~v020I~
#endif                                                             //~va00R~
    }                                                           //~v020I~
  if (Ppcw==scrgetcw(0))	//active client                    //~v557I~,//~v772I~
	pan300updatelist(Ppcw,0);//update filename list on ppc         //~v20yR~
    return;                                                     //~v020I~
}//pandraw300                                                   //~v020I~
                                                                //~v020I~
//****************************************************************//~v020I~
//* field full for filename panel                               //~v020I~
//* parm1 :pcw                                                  //~v020I~
//* parm2 :line                                                 //~v020I~
//* parm3 :field no                                             //~v020I~
//* parm4 :data                                                 //~v020I~
//* parm5 :eventid                                              //~v020I~
//* retrn:rc                                                    //~v020I~
//****************************************************************//~v020I~
int panfe300(PUCLIENTWE Ppcw,PUFLD Ppfld,UCHAR *Pdata,int Peventid)//~v020R~
{                                                               //~v020I~
#ifdef UNX                                                         //~v20uI~
#else  //!UNX                                                      //~v20uI~
    UCHAR curdir[_MAX_PATH];                                    //~v020I~
#endif //!UNX                                                      //~v20uI~
//*****************                                             //~v020I~
#ifdef UNX                                                         //~v20uI~
#else  //!UNX                                                      //~v20uI~
	if (Ppcw->UCWrcsry==PANL300DRIVE)                           //~v020R~
    {                                                           //~v020I~
    	if (Peventid==PFE_FULL)                                 //~v020R~
        {                                                       //~v020I~
    		*(Pdata+1)=':';                                     //~v020R~
    		*(Pdata+2)=0;                                       //~v020R~
			if (!ufullpath(curdir,Pdata,_MAX_PATH))//path err   //~v020R~
        	{                                                   //~v020R~
        		panflderr(Ppcw,PANL300DRIVE,0,PANFESET);//set err reverse//~v020R~
    			uerrmsg("Drive letter error",                   //~v020R~
						"未定義ドライブ");                      //~v020R~
            	return 4;	                                    //~v020R~
        	}                                                   //~v020R~
//          if (*(curdir+strlen(curdir)-1)!='\\')                  //~v07lR~
            if (PATHLEN(curdir)!=(int)strlen(curdir))              //~v07lI~
//              strcat(curdir,"\\");                               //~v19aR~
                strcat(curdir,DIR_SEPS);                           //~v19aI~
		    csronthefld(Ppcw,PANL300DIR,0,(int)strlen(curdir)); //~v020R~
        }                                                       //~v020I~
        else	//field clear or space clear                    //~v020I~
        {                                                       //~v020I~
		    csronthefld(Ppcw,PANL300DRIVE,0,0);   //filename fld//~v020I~
        	*curdir=0;	//clear                                 //~v020I~
        }                                                       //~v020I~
//      setflddata(Ppcw,PANL300DIR,0,curdir);                      //~v684R~
        pan300setdirline(Ppcw,curdir);                             //~v684I~
		panflderr(Ppcw,PANL300DIR,0,PANFERESET);//reset err both//~v020I~
    }                                                           //~v020I~
#endif //!UNX                                                      //~v20uI~
	if (Ppcw->UCWrcsry>=PANL300LISTTOP)                            //~v20yI~
		pan300felcmd(Ppcw,Pdata,Peventid);                         //~v20yR~
    return 0;                                                   //~v020R~
}//panfe300                                                     //~v020R~
#ifndef UNX                                                        //~v54vI~
//**************************************************************** //~v54vI~
//* set curdir of the drive by cursor move on driveidlist          //~v54vI~
//* retrn:rc                                                       //~v54vI~
//**************************************************************** //~v54vI~
int pan300setcpath(PUCLIENTWE Ppcw,char Pdriveid)                  //~v54vI~
{                                                                  //~v54vI~
    UCHAR curdir[_MAX_PATH];                                       //~v54vI~
    char  did[4];                                                  //~v54vI~
//*****************                                                //~v54vI~
    did[0]=Pdriveid;                                               //~v54vI~
    did[1]=':';                                                    //~v54vI~
    did[2]=0;                                                      //~v54vI~
	if (!ufullpath(curdir,did,_MAX_PATH))//path err                //~v54vI~
    	return 4;                                                  //~v54vI~
//  setflddata(Ppcw,PANL300DIR,0,curdir);                          //~v684R~
    pan300setdirline(Ppcw,curdir);                                 //~v684I~
    return 0;                                                      //~v54vI~
}//pan300setcpath                                                  //~v54vI~
#endif //!UNX                                                      //~v54vI~
#ifndef UNX                                                        //~va00R~
//**************************************************************** //~va00R~
//**************************************************************** //~va00R~
//**************************************************************** //~va00R~
int pan300setdirline(PUCLIENTWE Ppcw,char *Ppath)                  //~v684I~
{                                                                  //~v684I~
    UCHAR encpath[_MAX_PATH];                                      //~v684I~
    int rc;                                                        //~v684I~
//*****************                                                //~v684I~
	rc=uparsein(Ppath,encpath,sizeof(encpath),0,'\"');             //~v684I~
    if (rc==1||rc==2)	//space containing)                        //~v684I~
		setflddata(Ppcw,PANL300DIR,0,encpath);                     //~v684I~
    else                                                           //~v684I~
		setflddata(Ppcw,PANL300DIR,0,Ppath);                       //~v684R~
    return rc;                                                     //~v684I~
}//pan300setdirline                                                //~v684I~
#endif //!UNX                                                      //~va00R~
//****************************************************************//~v020I~
//* exec on file name panel                                     //~v020I~
//* parm1 :pcw                                                  //~v020I~
//* retrn:rc                                                    //~v020I~
//****************************************************************//~v020I~
int panexec300(PUCLIENTWE Ppcw)                                 //~v020I~
{                                                               //~v020I~
//  UCHAR wkbuff[MAXCOLUMN];                                       //~v095R~
    UCHAR wkbuff[_MAX_PATH+MAXCOLUMN];                             //~v095I~
    UCHAR wkbuff2[MAXCOLUMN];                                      //~v095R~
    int len,len2,rc;                                            //~v020R~
    int conpos;                                                    //~v07oI~
    int quatesw=0;                                                 //~v095R~
    char *pc,*pco;                                                 //~v095R~
    int opdno=0,ii;                                                  //~v095R~//~vafcR~
#define QUATE '\"'                                                 //~v095I~
#ifdef FTPSUPP                                                     //~v717I~
    PUFTPHOST puftph=0,puftph2=0;                                  //~v717I~
    int tsosw=0;                                                   //~v717R~
#endif                                                             //~v717I~
//*****************                                             //~v020I~
#ifdef UTF8SUPPH                                                   //~va00R~
	len=BYUTF8_getfldinput(0,Ppcw,PANL300DIR,0,wkbuff);//directory name//~va00R~
#else                                                              //~va00R~
	len=getfldinput(Ppcw,PANL300DIR,0,wkbuff);//directory name  //~v020I~
#endif                                                             //~va00R~
//  if (len && *(wkbuff+len-1)!='\\')                              //~v07lR~
//  	*(wkbuff+len++)='\\';                                      //~v07oR~
	rc=0;                                                          //~v095I~
  if (len)                                                         //~v08nI~
  {                                                                //~v095I~
#ifdef FTPSUPP                                                     //~v717I~
    uftpisremote(wkbuff,&puftph);                                  //~v717I~
    tsosw=UFTPHISTSO(puftph);                                      //~v717I~
   if (tsosw)                                                      //~v717I~
   {                                                               //~v717I~
   	conpos=len+1;                                                  //~v717I~
   }                                                               //~v717I~
   else                                                            //~v717I~
   {                                                               //~v717I~
#endif                                                             //~v717I~
    filefnquate(wkbuff);     //quatation change                    //~v0ftI~
  	quatesw=(*wkbuff==QUATE);                                      //~v095I~
  	rc=uparse(wkbuff,wkbuff,&opdno,0,0);	//drop quate           //~v095R~
    if (opdno>1)                                                   //~v095I~
    {                                                              //~va00R~
#ifdef UTF8SUPPH                                                   //~va00R~
        uerrmsg("Invalid Dir name",0);                             //~v8@iR~
#endif                                                             //~va00R~
        rc=4;                                                      //~v095I~
    }                                                              //~v8@iI~
	len=(int)strlen(wkbuff);			//                         //~v095R~
    if (PATHLEN(wkbuff)!=len)   //last is not '\'                  //~v08nR~
    	conpos=len+1;             //pos padding '\\'               //~v07oI~
    else                                                           //~v07oI~
    	conpos=len;                                                //~v07oI~
#ifdef FTPSUPP                                                     //~v717I~
   }//!tsosw                                                       //~v717I~
#endif                                                             //~v717I~
  }	                                                               //~v095I~
  else                                                             //~v08nI~
    conpos=0;                                                      //~v08nI~
#ifdef UTF8SUPPH                                                   //~va00R~
	len2=BYUTF8_getfldinput(0,Ppcw,PANL300FILENAME,0,wkbuff+conpos);//concat filename//~va00R~
#else                                                              //~va00R~
	len2=getfldinput(Ppcw,PANL300FILENAME,0,wkbuff+conpos);//concat filename//~v07oR~
#endif                                                             //~va00R~
	if (len2)                                                      //~v095I~
    {                                                              //~v095I~
#ifdef FTPSUPP                                                     //~v717I~
    	uftpisremote(wkbuff+conpos,&puftph2);                      //~v717I~
    	tsosw|=UFTPHISTSO(puftph2);                                //~v717I~
      if (tsosw)                                                   //~v717R~
        opdno=1;                                                   //~v717I~
      else                                                         //~v717I~
      {                                                            //~v717I~
#endif                                                             //~v717I~
	    filefnquate(wkbuff+conpos);     //quatation change         //~v0ftI~
    	memcpy(wkbuff2,wkbuff+conpos,(UINT)(len2+1));	//save filename name//~v095R~
    	quatesw+=(*wkbuff2==QUATE);                                //~v095R~
      	rc+=uparse(wkbuff2,wkbuff2,&opdno,0,0);	//drop quate       //~v095R~
    	len2=(int)strlen(wkbuff2);			//file name len        //~v095R~
    	memcpy(wkbuff+conpos,wkbuff2,(UINT)(len2+1));	//save filename name//~v095R~
#ifdef FTPSUPP                                                     //~v717I~
      }                                                            //~v717R~
#endif                                                             //~v717I~
    }                                                              //~v095I~
    if (!(len+len2))                                            //~v020R~
    {                                                              //~v54jI~
//  	return 0;                                                  //~v20yR~
		if (Ppcw->UCWrcsry>=PANL300LISTTOP)                        //~v20yI~
    		return pan300execlist(Ppcw);                           //~v20yR~
        else                                                       //~v20yI~
		  	return 0;                                              //~v20yI~
    }                                                              //~v54jI~
	if (len && len2)	//need concat                              //~v07oI~
    {                                                              //~v717I~
//  	*(wkbuff+conpos-1)='\\';                                   //~v19aR~
#ifdef FTPSUPP                                                     //~v717I~
      if (tsosw)                                                   //~v717I~
      	u3270concatfilename(0,wkbuff,wkbuff+conpos,wkbuff);        //~v717R~
      else                                                         //~v717I~
#endif                                                             //~v717I~
    	*(wkbuff+conpos-1)=DIR_SEPC;                               //~v19aI~
    }                                                              //~v717I~
	Ppcw->UCWparm=wkbuff;                                       //~v020I~
    if (len2)	//filename input                                //~v020I~
	    panflderr(Ppcw,PANL300FILENAME,0,PANFERESET);//reset err both//~v020R~
    if (len)	//dir input                                     //~v020I~
 	   panflderr(Ppcw,PANL300DIR,0,PANFERESET);//reset err both fld//~v020R~
  if (!rc)                                                         //~v095I~
  {                                                                //~v095I~
    len=(int)strlen(wkbuff);                                    //~v020R~
#ifdef FTPSUPP                                                     //~v717R~
   if (!tsosw)                                                     //~v717I~
   {                                                               //~v717I~
#endif                                                             //~v717I~
//  if (*(wkbuff+len-1)=='\\')                                     //~v07lR~
    if (PATHLEN(wkbuff)==len)   //last is '\'                      //~v07lI~
#ifdef UNX                                                         //~v19aI~
//      if (!ROOTDIR(wkbuff))//not root                            //~v40AR~
//      if (!ROOTDIR2(wkbuff))//not root                           //~v54jR~
        if (!ROOTDIR3(wkbuff))//not root                           //~v54jI~
#else   //!UNX                                                     //~v19aI~
        if (len>1 && *(wkbuff+len-2)!=':')//not root            //~v020I~
#endif  //!UNX                                                     //~v19aI~
        {                                                          //~v095I~
		    *(wkbuff+len-1)=0;	//drop last                     //~v020R~
            len--;                                                 //~v095I~
		}                                                          //~v095I~
#ifdef FTPSUPP                                                     //~v717R~
   }	//!tso                                                     //~v717I~
#endif                                                             //~v717I~
    if(quatesw)                                                    //~v095I~
    {                                                              //~v095I~
    	memmove(wkbuff+1,wkbuff,(UINT)len);	                       //~v095R~
        len++;                                                     //~v095I~
        *wkbuff=QUATE;                                             //~v095I~
        *(wkbuff+len++)=QUATE;                                     //~v095I~
        *(wkbuff+len)=0;                                           //~v095I~
    }                                                              //~v095M~
    if (len2 && opdno>1)    //other opd specified                  //~v095R~
    {                                                              //~v095R~
    	pc=wkbuff2+strlen(wkbuff2)+1;                              //~v095R~
        pco=wkbuff+len;                                            //~v095R~
        for (ii=opdno-1;ii;ii--)                                   //~v095R~
        {	                                                       //~v095R~
        	*pco++=' ';                                            //~v095R~
            len2=(int)strlen(pc);                                  //~v095R~
            memcpy(pco,pc,(UINT)len2);                             //~v095R~
            pco+=len2;                                             //~v095R~
            pc+=(len2+1);                                          //~v095R~
        }                                                          //~v095R~
        *pco=0; //last null                                        //~v095I~
    }                                                              //~v095R~
    switch(Ppcw->UCWmenuopt)                                    //~v020R~
    {                                                           //~v020I~
    case PANMOBROWSE:                                           //~v020I~
        csronthefld(Ppcw,PANL300FILENAME,0,0);   //for when next wakeup//~v020R~
    	rc=func_browse_file2(Ppcw,1);	//may additional opd       //~v08lR~
    	break;                                                  //~v020I~
    case PANMOEDIT:                                             //~v020I~
        csronthefld(Ppcw,PANL300FILENAME,0,0);   //for when next wakeup//~v020R~
    	rc=func_edit_file2(Ppcw,1);     //may additional opd       //~v08lR~
    	break;                                                  //~v020I~
    case PANMOFILE:                                             //~v020I~
    	rc=4;                                                   //~v020I~
    	break;                                                  //~v020I~
    }                                                           //~v020R~
  }//rc=0                                                          //~v095I~
	if (rc)                                                     //~v020I~
    {                                                           //~v020M~
    	panflderr(Ppcw,PANL300DIR,0,PANFESET);//set err reverse //~v020M~
    	panflderr(Ppcw,PANL300FILENAME,0,PANFESET);//set csr    //~v020I~
	}                                                           //~v020M~
    return rc;                                                  //~v020R~
}//panexec300                                                   //~v020I~
                                                                   //~v075I~
//**************************************************************** //~v075M~
//* color option panel                                             //~v075M~
//* parm1 :pcw                                                     //~v075M~
//* retrn:rc                                                       //~v075M~
//**************************************************************** //~v075M~
int panopt(PUCLIENTWE Ppcw)                                        //~v075M~
{                                                                  //~v075M~
	PUCLIENTWE pcw;                                                //~v075M~
//*****************                                                //~v075M~
    pcw=panregist(PANOPTCOLOR);		//color option                 //~v075M~
    UALLOCCHK(pcw,8);               //return if storage shortage   //~v075M~
    memcpy(Sattrtbl,Gattrtbl,sizeof(Sattrtbl));	//initial attr     //~v075M~
    memcpy(Spallassigntbl,Gpallassigntbl,sizeof(Spallassigntbl));//input//~v079I~
    memcpy(Spallette,Gpallette,sizeof(Spallette));	//restore if cancel//~v075I~
    return 0;                                                      //~v075M~
}//panopt                                                          //~v075M~
                                                                   //~v075M~
//**************************************************************** //~v075M~
//* panattr10                                                      //~v075M~
//* set cell attr for OPT COLOR panel                              //~v075M~
//* parm1 :pcw                                                     //~v075M~
//* parm2 :line no                                                 //~v075M~
//* parm3 :ppsd                                                    //~v075M~
//* retrn:rc                                                       //~v075M~
//**************************************************************** //~v075M~
void panattr10(PUCLIENTWE Ppcw,int Prow,PUSCRD Ppsd)               //~v075M~
{                                                                  //~v075M~
	UFLDE  *pfle;                                                  //~v075M~
	UFLD    *pfl;                                                  //~v075I~
	char color1=0,color1r=0,color2=0,color2r=0;                    //~v19BR~
	UCHAR *pc,*pce;                                                //~v095R~
    int ii,jj,len1=7,len2=8,fldlen;                                //~v079R~
//*****************                                                //~v075M~
//@@@@ test                                                        //~v075I~
//  pfl=((PUPANELC)(Ppcw->UCWppc))->UPCline[Prow].UPLpfld; //ufld  //~v075R~
//  UTRACEP("row=%d",Prow);                                        //~v075R~
//  UTRACED("pfl",pfl,256);                                        //~v075R~
//@@@@                                                             //~v075I~
	if (Prow<PANL10PAL || Prow>PANL10COL)//<pallette no start||>color input line//~v079I~
    	return;                                                    //~v079I~
	pfl=((PUPANELC)(Ppcw->UCWppc))->UPCline[Prow].UPLpfld; //ufld  //~v079R~
    pfle=pfl->UFLentry;		//first entry                          //~v079I~
	if (Prow==PANL10COLS	//color sample                         //~v079R~
	||  Prow==PANL10COL)	//color value input line               //~v079I~
    {                                                              //~v075I~
		len1=pfl->UFLentry[0].UFLend-pfl->UFLentry[0].UFLstart;    //~v079I~
        for (ii=0;ii<16;ii++,pfle++)                               //~v075R~
        {                                                          //~v075I~
			pc=Ppsd->USDcell+pfle->UFLstart*2+1;                   //~v075I~
#ifdef UNX                                                         //~v20pI~
            if (ii>=MAX_COLOR || Gmaxcolor==2)  //highlight or mono color//~v20pR~
//  	    	color1r=(char)(((ii-MAX_COLOR)<<4)+ii);	//FG hilight//~v20pR~
#ifdef XXE                                                         //~v64sR~
              if (ii==MAX_COLOR)                                   //~v64sR~
                color1r=(char)(ii<<4);  //not bg color but black   //~v64sR~
              else                                                 //~v64sR~
#endif                                                             //~v64sR~
    	    	color1r=(char)ii;	//FG hilight                   //~v20pI~
            else                                                   //~v20pI~
#endif //UNX                                                       //~v20pI~
		    color1r=(char)(ii<<4);	//BG only                      //~v075R~
		    for (len2=len1;len2;len2--,pc+=2)                      //~v075I~
            {                                                      //~v079I~
				if (Prow==PANL10COL)	//color value input line   //~v079I~
                {                                                  //~v079I~
#ifdef UNX                                                         //~v20pM~
            	  if (ii<MAX_COLOR)  //normal color                //~v20pI~
#endif //UNX                                                       //~v20pM~
                	if (!*(pc-1))                                  //~v079I~
                    {                                              //~v079I~
                    	*(pc-1)=NOINPUT;                           //~v079I~
                      if (UCBITCHK(pfle->UFLflag,UFLEFPROT))       //~v20rR~
                    	*pc=Gattrtbl[COLOR_FRAME];                 //~v20rI~
                      else                                         //~v20rI~
                    	*pc=Gattrtbl[COLOR_DLINCMD];               //~v079R~
                    }                                              //~v079I~
				}                                                  //~v079I~
                else                                               //~v079I~
#ifdef UNX                                                         //~v20pI~
				{                                                  //~v20pI~
			    	*pc=color1r;                                   //~v20pI~
                    if (color1r & 0x07)	//has fg value             //~v20pI~
                    {                                              //~v54jI~
                        if (ii>=MAX_COLOR)                         //~v20pI~
                        {                                          //~v64jI~
#ifdef XXE                                                         //~v64jM~
//			    			*pc=0x80|(color1r<<4);  //bg color available//~v64jR~//~vb30R~
  			    			*pc=(UCHAR)(0x80|(color1r<<4));  //bg color available//~vb30I~
#else                                                              //~v64jI~
                            *(pc-1)='H';        //fg char          //~v20pI~
#endif                                                             //~v64jI~
                        }                                          //~v64jI~
                        else                                       //~v20pI~
                        if (Gmaxcolor==2)       //mono color       //~v20pI~
                            *(pc-1)='N';        //fg char          //~v20rR~
                    }                                              //~v54jI~
                }                                                  //~v20pI~
#else  //!UNX                                                      //~v20pI~
			    	*pc=color1r;                                   //~v079R~
#endif //!UNX                                                      //~v20pI~
			}                                                      //~v079I~
        }                                                          //~v075I~
    	return;                                                    //~v075I~
    }                                                              //~v075I~
	if (Prow>PANL10PALEND)	//pallete no only after this           //~v079R~
    	return;                                                    //~v075I~
    for (ii=0;ii<2;ii++,pfle++)                                    //~v079I~
    {                                                              //~v079I~
		pc=Ppsd->USDcell+pfle->UFLstart*2;                         //~v079I~
	    for (jj=0;jj<2;jj++,pc+=2)                                 //~v079I~
    	{                                                          //~v079I~
		    if (!*pc)                                              //~v079I~
    		{                                                      //~v079I~
    			*pc=NOINPUT;                                       //~v079I~
        		*(pc+1)=Gattrtbl[COLOR_DLINCMD];                   //~v079R~
			}                                                      //~v079I~
		}                                                          //~v079I~
    }                                                              //~v079I~
    if (!(fldlen=getfldpos(Ppcw,Prow,PANF10PALSAMP,&pc,0))) //no dbcs out//~v095R~
    	return;		//no sample field                              //~v075M~
//attr of sample                                                   //~v079I~
    pfle=pfl->UFLentry;		//restore first entry                  //~v079I~
    pfle+=PANF10PALSAMP;                                           //~v079I~
	ii=(int)strlen(pc);                                            //~v075M~
    fldlen=min(ii,fldlen);                                         //~v075M~
	pfle=getuflde(Ppcw,Prow,PANF10PALSAMP);                        //~v075M~
	pc=Ppsd->USDcell+pfle->UFLstart*2+1;                           //~v075M~
    pce=pc+(fldlen<<1);                                            //~v075M~
                                                                   //~v075M~
	switch(Prow)                                                   //~v075M~
    {                                                              //~v075M~
    case PANL10PALTI:	//title                                    //~v075R~
    	color1 =                                                   //~v075I~
    	color1r=                                                   //~v075I~
    	color2 =Sattrtbl[COLOR_TITLE];                             //~v075R~
    	color2r=Sattrtbl[COLOR_TITLE_R];                           //~v075R~
        len2=4;                                                    //~v075I~
    	break;                                                     //~v075I~
    case PANL10PALFR:	//frame                                    //~v075M~
    	color1 =                                                   //~v075M~
    	color1r=                                                   //~v075M~
    	color2 =Sattrtbl[COLOR_FRAME];                             //~v075M~
    	color2r=Sattrtbl[COLOR_FRAME_R];                           //~v075M~
        len1=3;                                                    //~v075M~
        len2=7;                                                    //~v075R~
    	break;                                                     //~v075M~
    case PANL10PALBL:	//browse lineno line                       //~v075M~
    	color1 =Sattrtbl[COLOR_BLINENO];                           //~v075M~
    	color1r=Sattrtbl[COLOR_BLINENO_R];                         //~v075M~
    	color2 =Sattrtbl[COLOR_BCLIENT];                           //~v075M~
    	color2r=Sattrtbl[COLOR_BCLIENT_R];                         //~v075M~
    	break;                                                     //~v075M~
	case PANL10PALEL:	//edit   lineno line                       //~v075M~
    	color1 =Sattrtbl[COLOR_ELINENO];                           //~v075M~
    	color1r=Sattrtbl[COLOR_ELINENO_R];                         //~v075M~
    	color2 =Sattrtbl[COLOR_ECLIENT];                           //~v075M~
    	color2r=Sattrtbl[COLOR_ECLIENT_R];                         //~v075M~
    	break;                                                     //~v075M~
	case PANL10PALDL:	//dirlist line                             //~v075M~
    	*pc=Sattrtbl[COLOR_DLINCMD];                               //~v075M~
        pc+=2;                                                     //~v075M~
        len1=6;                                                    //~v075M~
    	color1 =Sattrtbl[COLOR_DLINENO];                           //~v075M~
    	color1r=Sattrtbl[COLOR_DLINENO_R];                         //~v075M~
    	color2 =Sattrtbl[COLOR_DCLIENT];                           //~v075M~
    	color2r=Sattrtbl[COLOR_DCLIENT_R];                         //~v075M~
    	break;                                                     //~v075M~
	case PANL10PALCL:	//cmdout lineno line                       //~v075M~
    	len1=14;                                                   //~v075M~
        len2=0;                                                    //~v075M~
    	color1 =Sattrtbl[COLOR_CLINENO];                           //~v075M~
    	color1r=Sattrtbl[COLOR_CLINENO_R];                         //~v075M~
    	color2 =Sattrtbl[COLOR_CLINENO];                           //~v075M~
    	color2r=Sattrtbl[COLOR_CLINENO_R];                         //~v075M~
    	break;                                                     //~v075M~
	case PANL10PALCR:	//cmdout result line                       //~v075M~
    	color1 =Sattrtbl[COLOR_CCLIENT];                           //~v075M~
    	color1r=Sattrtbl[COLOR_CCLIENT_R];                         //~v075M~
    	color2 =Sattrtbl[COLOR_CCLIENT];                           //~v075M~
    	color2r=Sattrtbl[COLOR_CCLIENT_R];                         //~v075M~
    	break;                                                     //~v075M~
	}                                                              //~v075M~
	if (Prow==PANL10PALCR)	//cmdout result line                   //~v079R~
	    *pc=color1;                                                //~v079I~
    else                                                           //~v079I~
	    *pc=color1r;                                               //~v079R~
    for (ii=0,pc+=2;ii<len1;ii++,pc+=2)                            //~v075M~
    	*pc=color1;                                                //~v075M~
    for (ii=0;ii<len2;ii++,pc+=2)                                  //~v075M~
    	*pc=color2r;                                               //~v075M~
    for (;pc<pce;pc+=2)                                            //~v075M~
    	*pc=color2;                                                //~v075M~
    return;                                                        //~v075M~
}//panattr10                                                       //~v075M~
                                                                   //~v075I~
//**************************************************************** //~v075I~
//* exec on file name panel                                        //~v075I~
//* parm1 :pcw                                                     //~v075I~
//* retrn:rc                                                       //~v075I~
//**************************************************************** //~v075I~
int panexecolor(PUCLIENTWE Ppcw)                                   //~v075I~
{                                                                  //~v075I~
	UCHAR no;                                                      //~v075R~
    UCHAR colno[16];                                               //~v075I~
    UCHAR *pc;                                                     //~v075R~
    int ii,err=0,colinputsw=0,rc;                                  //~v079R~
    int jj;                                                        //~v0hbI~
//*****************                                                //~v075I~
	for (ii=0;ii<PAL_MAXENTRY;ii++)                                //~v075I~
    {                                                              //~v075I~
        no=getpalno(Ppcw,ii+PANL10PAL,PANF10PALFG);                //~v075R~
        jj=ii<<1;                                                  //~v0hbI~
        if (no==ERVALUE)                                           //~v075I~
        	err=1;                                                 //~v075R~
//      Spallassigntbl[ii<<1]=no;                                  //~v0hbI~
		else                                                       //~v0hbR~
  			if (no==NOVALUE)       //specified                     //~v0hbI~
				Spallassigntbl[jj]=Gpallassigntbl[jj];      //     //~v0hbI~
       		else                                                   //~v0hbI~
          		Spallassigntbl[jj]=no;                             //~v0hbR~
        no=getpalno(Ppcw,ii+PANL10PAL,PANF10PALBG);                //~v075R~
        jj++;                                                      //~v0hbI~
        if (no==ERVALUE)                                           //~v075R~
        	err=1;                                                 //~v075R~
//  	Spallassigntbl[(ii<<1)+1]=no;                              //~v0hbI~
		else                                                       //~v0hbI~
			if (no==NOVALUE)       //specified                     //~v0hbI~
				Spallassigntbl[jj]=Gpallassigntbl[jj];      //     //~v0hbI~
        	else                                                   //~v0hbI~
				Spallassigntbl[jj]=no;                             //~v0hbI~
    }                                                              //~v075I~
//color value get                                                  //~v075I~
    for (ii=0;ii<16;ii++)                                          //~v78FR~
    {                                                              //~v075I~
      if (ii>=MAX_COLOR)                                           //~v78FI~
        no=NOVALUE;                                                //~v78FI~
      else                                                         //~v78FI~
        no=pangetrgbix(Ppcw,PANL10COL,ii);                         //~v07aR~
        if (no==ERVALUE)                                           //~v075R~
        	err=1;                                                 //~v075R~
        else                                                       //~v075I~
        {                                                          //~v079I~
//      	if (no==NOVALUE)         //no input                    //~v78FR~
//          	if (Gpallette[ii]!=Spallette[ii])	//once chaged  //~v78FR~
//              	no=Spallette[ii];	//restore at entry to color panel//~v78FR~
	        colno[ii]=no;                                          //~v075I~
        	if (no==NOVALUE)         //no input                    //~v78FI~
            	if (Gpallette[ii]!=Spallette[ii])	//once chaged  //~v78FI~
                	colno[ii]=Spallette[ii];	//restore at entry to color panel//~v78FI~
        	if (no!=NOVALUE         //no input                     //~v079R~
            &&  no!=Gpallette[ii])  //not changed                  //~v079I~
            	colinputsw=1;                                      //~v079I~
        }                                                          //~v079I~
    }                                                              //~v075I~
    if (err)                                                       //~v075I~
    	return 4;                                                  //~v075I~
//fill not specified entry by previous value                       //~v075I~
	for (ii=0,pc=Spallassigntbl;ii<PAL_MAXENTRY;ii++,pc++)         //~v075R~
    {                                                              //~v075I~
//        if (*pc==NOVALUE)       //not specified                  //~v0hbR~
//            *pc=Gpallassigntbl[ii<<1];      //                   //~v0hbR~
		pc++;                                                      //~v075I~
//        if ((no=*pc)==NOVALUE)       //not specified             //~v0hbR~
//        {                                                        //~v0hbR~
//            *pc=Gpallassigntbl[(ii<<1)+1];      //               //~v0hbR~
//        }                                                        //~v0hbR~
        no=*pc;                 //not specified                    //~v0hbI~
		if (*pc==*(pc-1))                                          //~v075I~
	    {                                                          //~v075I~
        	if (no==NOVALUE)	//BG  has no value                 //~v075R~
            	no=PANF10PALFG;                                    //~v075R~
			else                                                   //~v075I~
            	no=PANF10PALBG;                                    //~v075R~
	    	panflderr(Ppcw,ii+PANL10PAL,no,PANFESET);              //~v075R~
	    	err=1;                                                 //~v075I~
	    	uerrmsg("BG is same as FG",                            //~v075I~
					"BG が FG と同じです");                        //~v075I~
	    }                                                          //~v075I~
    }                                                              //~v075I~
//    if (err)                                                     //~v0hbR~
//        return 4;                                                //~v0hbR~
    scrsetattrtbl(Sattrtbl,Spallassigntbl);                        //~v075R~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full draw                //~v075M~
//#ifdef W32                                                       //~v19AR~
//#else                                                            //~v19AR~
#ifdef WINCON                                                      //~va3AI~
    rc=0;                                                          //~va3AI~
#else                                                              //~va3AI~
    if (colinputsw)                                                //~v079I~
	    rc=scrsetpallette(colno);   //viosetstate and set Gpallette if success//~v079R~
	else                                                           //~v079I~
    {                                                              //~v78FI~
//#endif                                                           //~v19AR~
    	rc=0;                                                      //~v079I~
    memcpy(Gpallette,colno,16);                                    //~v64sI~
    }                                                              //~v78FI~
#endif                                                             //~va3AI~
    if (err)                                                       //~v0hbI~
        rc+=4;                                                     //~v0hbI~
    return rc;                                                     //~v075R~
}//panexecolor                                                     //~v075I~
                                                                   //~v075I~
//**************************************************************** //~v075I~
//* get FG/BG value                                                //~v075I~
//* parm1 :char input                                              //~v075I~
//* parm2 :posy                                                    //~v075I~
//* parm3 :fldno                                                   //~v075I~
//* retrn :int  value -1 if err,-2 if no value                     //~v075I~
//**************************************************************** //~v075I~
UCHAR getpalno(PUCLIENTWE Ppcw,int Prow,int Pfldno)                //~v075R~
{                                                                  //~v075I~
	UCHAR wk[4];                                                   //~v075R~
    int no;                                                        //~v075I~
//*******************                                              //~v075I~
	getfldinput(Ppcw,Prow,Pfldno,wk);//drop pre/post space         //~v075R~
	if (!*wk)                                                      //~v075I~
    {                                                              //~v079I~
        setflddata(Ppcw,Prow,Pfldno,wk);    //clear then brawse _  //~v079I~
    	return NOVALUE;                                            //~v075I~
    }                                                              //~v079I~
    if (*wk<'0'                                                    //~v075I~
    ||  *wk>'9'                                                    //~v075I~
    ||  (*(wk+1) && (*(wk+1)<'0' || *(wk+1)>'9')))                 //~v075R~
    	no=ERVALUE;                                                //~v075I~
	else                                                           //~v075I~
    {                                                              //~v075I~
    	no=atoi(wk);                                               //~v075I~
        if (no>=16)                                                //~v075I~
        	no=ERVALUE;                                            //~v075I~
    }                                                              //~v075I~
    if (no==ERVALUE)                                               //~v075I~
    	panflderr(Ppcw,Prow,Pfldno,PANFESET);                      //~v075I~
	return (UCHAR)no;                                              //~v075I~
}//getpalno                                                        //~v075I~
                                                                   //~v075I~
//**************************************************************** //~v075I~
//* get RGB input                                                  //~v075I~
//* parm1 :char input                                              //~v075I~
//* parm2 :posy                                                    //~v075I~
//* parm3 :fldno                                                   //~v075I~
//* retrn :int  value -1 if err,-2 if no value                     //~v075I~
//**************************************************************** //~v075I~
UCHAR pangetrgbix(PUCLIENTWE Ppcw,int Prow,int Pfldno)             //~v07aR~
{                                                                  //~v075I~
	UCHAR wk[4];                                                   //~v075I~
    int no,winerr=0;                                               //~v079R~
//*******************                                              //~v079R~
	getfldinput(Ppcw,Prow,Pfldno,wk);//drop pre/post space         //~v075I~
    if (!*wk)                                                      //~v079I~
    {                                                              //~v079I~
        setflddata(Ppcw,Prow,Pfldno,wk);    //clear then brawse _  //~v079I~
	    return NOVALUE;                                            //~v079I~
	}                                                              //~v079I~
    if ((strlen(wk)!=3)                                            //~v079R~
    ||  (wk[0]<'0' || wk[0]>'3')                                   //~v079R~
    ||  (wk[1]<'0' || wk[1]>'3')                                   //~v075I~
    ||  (wk[2]<'0' || wk[2]>'3'))                                  //~v075I~
    	no=ERVALUE;                                                //~v075R~
    else                                                           //~v075I~
    {                                                              //~v075I~
    	no=panrgbtoix (((wk[0]&0x03)<<4)                           //~v07aR~
        	  		 +((wk[1]&0x03)<<2)                            //~v075R~
				     +((wk[2]&0x03)   ));                          //~v075R~
		if (!no && Pfldno)	//ercept pallette 0                    //~v075R~
        	no=ERVALUE;                                            //~v075I~
        else                                                       //~v079I~
			if (no 	//value specified(and not fld 0)               //~v079R~
			&&	UCBITCHK(Gscrstatus,GSCRSEXTSG))//bypass reset at termination//~v079I~
	        	winerr=1;                                          //~v079R~
                                                                   //~v079I~
	}                                                              //~v075I~
    if (no==ERVALUE                                                //~v079R~
	||  winerr)                                                    //~v079I~
    	if (Prow==PANL10COL)	//color input line                 //~v087I~
	    if (!(((UFLDE*)getuflde(Ppcw,Prow,Pfldno))->UFLflag & UFLEFPROT))		//not protected//~v771R~
    	panflderr(Ppcw,Prow,Pfldno,PANFESET);                      //~v075I~
    return (UCHAR)no;                                              //~v075I~
}//pangetrgbix                                                     //~v07aR~
                                                                   //~v075I~
//**************************************************************** //~v075I~
//* convert color index to RGB value                               //~v075I~
//* parm1 :color index                                             //~v075I~
//* parm2 :output char RGB                                         //~v075I~
//* retrn :output int  RGB(6 bit)                                  //~v075I~
//**************************************************************** //~v075I~
int panixtorgb(int Pindex,char *Prgb)                              //~v07aR~
{                                                                  //~v075I~
    int vr,vg,vb;                                                  //~v075R~
//*******************                                              //~v075I~
//get RGB value from 6 bit index (Rl Gl  Bl Rh Gh Bh)              //~v075I~
	vr=(int)(((UINT)(Pindex&0x04)>>1)+((UINT)(Pindex&0x20)>>5));	//l. .h..	red//~v61rR~
	vg=(int)((      (Pindex&0x02)   )+((UINT)(Pindex&0x10)>>4));	//.l ..h.	green//~v61rR~
//  vb=(int)((      (Pindex&0x01)<<1)+((UINT)(Pindex&0x08)>>3));	//.. l..h	blue//~v61rR~//~vb30R~
    vb=(int)(((UINT)(Pindex&0x01)<<1)+((UINT)(Pindex&0x08)>>3));	//.. l..h	blue//~vb30I~
  	sprintf(Prgb,"%d%d%d",vr,vg,vb);                               //~v075I~
    return (vr<<4)+(vg<<2)+vb;                                     //~v075I~
}//panixtorgb                                                      //~v07aR~
                                                                   //~v075I~
//**************************************************************** //~v075I~
//* conv int rgb to int color index                                //~v07aI~
//* parm1 :int  RGB(6 bit)                                         //~v075I~
//* retrn :color index(0-63)                                       //~v075I~
//**************************************************************** //~v075I~
int panrgbtoix(int Prgb)                                           //~v07aR~
{                                                                  //~v075I~
//get 6 bit index (Rl Gl  Bl Rh Gh Bh)                             //~v075I~
// from  6bit RGB (Rh Rl  Gh Gl Bh Bl)                             //~v075I~
	return (int)(((UINT)(Prgb&0x20)>>3)                            //~v61rR~
//		+	(      (Prgb&0x10)<<1)                                 //~v54jR~//~vb30R~
  		+	((UINT)(Prgb&0x10)<<1)                                 //~vb30I~
		+	((UINT)(Prgb&0x08)>>2)                                 //~v54jR~
//		+	(      (Prgb&0x04)<<2)                                 //~v54jR~//~vb30R~
  		+	((UINT)(Prgb&0x04)<<2)                                 //~vb30I~
		+	((UINT)(Prgb&0x02)>>1)                                 //~v54jR~
//		+	(      (Prgb&0x01)<<3));                               //~v54jR~//~vb30R~
  		+	((UINT)(Prgb&0x01)<<3));                               //~vb30I~
}//panrgbtoix                                                      //~v07aR~
