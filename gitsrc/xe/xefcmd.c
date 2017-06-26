//*CID://+vb5bR~:                             update#=  324;       //~vb5bR~
//*************************************************************
//*xefcmd.c*
//**file cmd Save/Replace/Create/Tab/Copy/Move/Locate/Append       //~v0iaR~
//*************************************************************
//vb5b:160913 additional to vb54, DBCS space altch is changable by TAB cmd//~vb5bI~
//vb58:160911 TAB dispchar default was backed to 21be & 21c0,so change example of help msg//~vb58I~
//vb54:160903 TAB cmd new option to set altch; TAB {on|off} [altch1 [altch2]]//~vb54I~
//vb2z:160212 LNX compiler warning                                 //~vb2zI~
//vazv:150114 add help msg for locate whe reached to EOF           //~vazvR~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vajp:130815 (BUG)errornours translation when copy ebc into a file with diffrent CP as profile//~vajpI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaf4:120604 (XXE) for vaf2,gtk has no prompt option,always confirm existing//~vaf4I~
//vaf2:120603 (WXE:BUG) menu:saveas issues replace confirmation for not existing file//~vaf2I~
//            MFC FileDialog issue ovrride warning as default.     //~vaf2I~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va7u:100823 EBC:handle support to file input(Copy/Move/Paste)    //~va7uI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va6Q:100722 Fxx+/MxR is output lrecl for end/save/rep.. input lrecl for copy cmd//~va6QI~
//va6H:100719 (BUG) /Mx option rejected for Rep/Save..             //~va6HI~
//va6D:100719 EBC eol 0x15 support                                 //~va6DR~
//va6k:100622 COPY cmd considers priofile RECORD mode              //~va6kI~//~va6DR~
//va6h:100622 support x2B translatione even for BIN mode           //~va6hI~//~va6DR~
//va6g:100621 save profile of ::CB2CPxx for PASte cmd, PAste cmd support -S{i|r|d} option//~va6gI~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va6e:100620 (BUG)copy with CPEB tran only 1st line               //~va6eI~
//va65:100617 write lrecl to profile by REP cmd if the file is record mode//~va65I~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err coed.//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va35:100203 (BUG)move cmd:source file was deleted even if copy operation stopped by translation err//~va35I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd.c  :c&p data(support CF_UNICODETEXT)            //~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          save CPxx to profile                                   //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00R~
//          assume IE if copy target is IE                         //~va00I~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v789:080302 (BUG:LNX)ABEND pas cmd(abend at string constant update,windows allow it)//~v789I~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//            CUT accept same option as rep(x,nx,.lab). Paste tgt is a and B only(No O/P support)//~v783I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v713:060916 deleay file exist chk until after parameter chk for perforamance in remote file case.//~v713I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v69P:060713 Locate command label support                         //~v69PI~
//v66i:051023 (WXE)C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66iI~
//v64o:050624 (LNX)xxe support;cut & paste                         //~v64oI~
//v62t:050330 tc;wildcard rename support for -ooutfile             //~v62tI~
//v60j:050129 (BUG)csr pos is invalid for pair/same search after tabctr changed//~v60jI~
//            same thing is for all filechktabdbcs user;so reset at tabctr change time//~v60jI~
//v59V:041207 wildcard member is for rename(ufileeditname) for output filename//~v59VI~
//            (SAV,CRE,REP,APP)                                    //~v59VR~
//v59U:041207 display fullpath filename on "file in open" msg of save/rep/cre cmd//~v59UI~
//v58k:040918 (BUG)locate cmd abend for partial file edit if line parm is before the 1/2 line of top//~v58kI~
//v57P:040620 cre/rep/app change deault to ALL when with labal range parm//~v57PI~
//v57z:040605 (BUG)rep/cre/app csr jump to home when label err     //~v57zI~
//v57y:040605 (BUG)./ and .\ is treated as label for rep/cre/app cmd//~v57yI~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v54Y:040201 "cre/rep/sav/app" support -xall -nxall .a .b         //~v54YI~
//v54F:040121 (BUG)hex mode locate need not to change curtop       //~v54FI~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v50q:030111 (BUG)cv+renum+locate,locate faile if expanded offset without C option//~v50qI~
//v50n:030103 (BUG)save "" cause err filename                      //~v50nI~
//v50m:030102 accept tab cmd on any screen                         //~v50mI~
//v500:021012 (WXE)unconditional save for wxe cmd(menu select)     //~v500I~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v49j:020807 (BUG)ufileeditname dbcs support                      //~v49jI~
//v49f:020706 wild card member name support for save/repl/create/apend cmd//~v49fI~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v47T:020406 eol-id change option for cre/rep/app/sav/end cmd     //~v47TI~
//v47q:020313 wild card filename support for copy/move edit cmd    //~v47qR~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v20V:001124 (BUG)english mode errmsg(alreadt TAB ON should be OFF)//~v20VI~
//v13d:991023 *\ support for filecmd(save/repl/create/append/copy/move/ini)//~v13dI~
//v11f:990711 (BUG) Lcate fail for last line when offset-line mode //~v11fI~
//v11c:990630 help for Locate cmd                                  //~v11cI~
//v11a:990619 locate cmd default Base by lineno fmt                //~v11aI~
//v116:990612 locate by hex offset;use line offset at read if not especialy//~v116I~
//            option specified else use search on current update status(",c" option)//~v116I~
//            And support ",C" option for lineno locate cmd        //~v116I~
//v114:990612 erase "specify copy dest" msg after successfull completion//~v114I~
//v10Z:990606 allow Locate X command for text file also            //~v10ZI~
//v10W:990605 support Locate by hex offset for binary file         //~v10WI~
//v10N:990502 support record width of binary by optbin             //~v10NI~
//v107:981213 use new opt of ufgetsinit for binary chk(del filechkbin)//~v107I~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0hJ:980418 support "tab clear" cmd                              //~v0hJI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0ba:970726 split xefile,xefile12(save)                          //~v0baI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0ahI~
//v0ah:970712 (BUG)locate cmd locate to first of lineno(lowest suffix)//~v0ahI~
//v0ab:970712:write by binaly mode                                 //~v0abI~
//v0aa:970707:default write mode set from read mode                //~v0aaI~
//v09Y:970629:file NULL(0x00) support                              //~v09kI~
//            filegetline parm changed                       fcmd  //~v09kI~
//v09k:970518:assume "a"fter input when linectr==0 for COPY/MOVE cmd//~v09kI~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v08o:961124:(BUG)on loaded err msg for save cmd when same file name opd//~v08oI~
//v08h:961107:too many operand chk for save/repl/create            //~v08hI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -REPL/CREATE after line range closed               //~v06lI~
//v06i:960310:support REPl/CREate file by ALt+l for no line-no display mode//~v06iI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v05s:951126:MOVE edit command                                 //~v05sI~
//v05p:951126:COPY/MOVE command under except edit/browse screen //~v05pI~
//v04f:951005:dummy plc for copy comand remain on pvlcmd and the back//~v04fI~
//            to UFHcmdline by otherclient(FCMD del only UFHcmdline)//~v04fI~
//            when enter key from other screen.                 //~v04fI~
//            (no save dummy and no need delsh)                 //~v04fI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v033:950715:SCROLL cmd for dir list scroll(err msg by xeerr.c)//~v033I~
//*v020:950611:dir support(move End/Cancel to xefile.c)         //~v020I~
//************************************************************* //~v020I~
//*950610 v011:fullpath err when workdir                        //~5610I~
//************************************************************* //~5610I~
//*950603 write ini when tab option change                      //~5603R~
//*950128 filename operand for save cmd                         //~5225I~
//*941207 cancel confirm                                        //~5128I~
//*941204 func_cancel
//*941120 func_save
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
#ifdef UTF8SUPPH                                                   //~va1qM~
#ifdef LNX                                                         //~va1cR~
	#define _XOPEN_SOURCE_EXTENDED		//ncurses define           //~va1cR~
	#include <ucurses.h>	         //v1.3 add                    //~va1cR~
#endif                                                             //~va1cR~
#ifdef W32                                                         //~va1cI~
	#include <windows.h>                                           //~va1cI~
#endif                                                             //~va1cI~
#endif                                                             //~va1qI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <ufile.h>                                              //~5318I~
#include <ufile5.h>                                                //~v09YI~
#include <uparse.h>                                                //~v0ahR~
#include <uedit.h>                                                 //~v10WI~
#include <uftp.h>                                                  //~v576R~
#include <ufemsg.h>                                                //~v713R~
#include <uviom.h>                                                 //~va1cR~
#include <ustring.h>                                               //~va6gI~
#include <utrace.h>                                                //~vazvI~
#include <utf22.h>                                                 //~vb54I~
                                                                   //~v10WI~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0baI~
#include "xefile13.h"                                              //~v500I~
#include "xefile14.h"                                              //~v54dI~
#include "xefile2.h"                                               //~v10WI~
#include "xefile3.h"                                               //~v10WI~
#include "xefile4.h"                                            //~5225I~
#include "xefile5.h"                                               //~v47TI~
#include "xefile6.h"                                               //~v0hJR~
#include "xefcmd.h"
#include "xefcmd22.h"                                              //~v10WI~
#include "xefcmd6.h"                                               //~v8@2I~
#include "xefunc.h"
#include "xelcmd.h"
#include "xelcmd2.h"                                            //~4C29I~
#include "xelcmd3.h"
#include "xedir.h"                                              //~v05sR~
#include "xedcmd.h"                                             //~v05sI~
#include "xesub.h"                                              //~5318I~
#include "xecap.h"                                              //~v06lI~
#include "xeerr.h"                                              //~v033I~
#ifdef WXE                                                         //~v500I~
	#include "wxexei.h"                                            //~v500I~
#endif                                                             //~v500I~
#ifdef XXE                                                         //~v64oI~
	#include "xxexei.h"                                            //~v64oI~
#endif                                                             //~v64oI~
#ifdef FTPSUPP                                                     //~v576I~
	#include "xeftp.h"                                             //~v576I~
	#include "xetso.h"                                           //~v70zI~
#endif                                                             //~v576I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xefcmd2.h"                                           //~va1GI~
	#include "xeopt.h"                                             //~va00I~
	#include "xeutf.h"                                             //~va00I~
#endif                                                             //~va00I~
//*******************************************************
static 	FILE *Scopyhfile;	//copycmd handle
static 	UCHAR Scopyfilename[_MAX_PATH];	//copycmd handle        //~5122R~
static  long  Scopylineno;
static  ULINEH Slh;         //for file copy/repl/create with lcmd//~5122I~
static 	UCHAR Sfcmdid;        //for fcmdoutrange,save fcmd id(rep/cre/app)//~v0iaI~
//static 	UCHAR Sfuncid;       //org func id                     //~vaz8R~
static 	int Sfuncid;       //org func id                           //~vaz8I~
static 	int Sreplsw;          //for fcmdoutrange,save fcmd id(rep/cre/app)//~v713I~
#ifdef UTF8SUPPH                                                   //~va00I~
	static 	int Scopyopt;     //copy conversion option             //~va00I~
	static 	int Scopyoptlrecl;     //copy conversion option        //~va6kI~
    static int Sswclosesource;                                     //~va35I~
#endif                                                             //~va00I~
//****************************************************************//~5122I~
int fcmdcalllcmd(PUCLIENTWE Ppcw,UCHAR *Pfilename,UCHAR Prepcre);//~v06lR~
//int addslh(PUCLIENTWE Ppcw);                                     //~v500R~
int addifline0(PUCLIENTWE Ppcw,PUFILEC Ppfc,PULINEH *Ppplh);       //~v09kI~
//int delslh(PUCLIENTWE Ppcw);                                  //~v04fR~
//int fcmdoutfnmedit(PUCLIENTWE Ppcw,UCHAR *Pwildfnm,UCHAR *Pfpath);//~v62tR~
int fcmdfilefind2(char *Pfilename,int Pcmdid,int *Pprepsw);        //~v713R~
int fcmdfilefind(char *Pfilename,int *Pprepsw);                    //~v713I~
//****************************************************************
// func_save_file
//*save command
//*ret  :rc                                                     //~5128R~
//****************************************************************
int func_save_file(PUCLIENTWE Ppcw)
{
	PUFILEC pfc;
	PUFILEH pfh;                                                //~5128I~
	PUFILEH pfhsrch;                                               //~v08oI~
	PULINEH plh1,plh2;                                             //~v54YR~
	UCHAR *filename;                                            //~5128I~
//  int opdno;                                                     //~v47TR~
	UCHAR  fpath[_MAX_PATH];                                       //~v576R~
    int saveopt;                                                   //~va6QI~
//*********************************
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;                                            //~5128I~
//  if (filename=Ppcw->UCWparm,filename)	//operand exist        //~v47TR~
//  if (filesaveoptionchk(Ppcw,pfh,0,&filename))                   //~v54YR~
//  if (filesaveoptionchk(Ppcw,pfh,0,&filename,&plh1,&plh2))       //~v54YR~//~va65R~
//  if (filesaveoptionchk(Ppcw,pfh,0,&filename,&plh1,&plh2,0))     //~va65I~//~va6QR~
    if (filesaveoptionchk(Ppcw,pfh,&saveopt,&filename,&plh1,&plh2,0))//~va6QI~
    	return 4;                                                  //~v47TR~
//  if (plh1)                                                      //~v57yR~
//  {                                                              //~v57yR~
//  	uerrmsg("label is not supported for save cmd",             //~v57yR~
//      		"SAVEコマンドでラベルは使えません");               //~v57yR~
//      return 4;                                                  //~v57yR~
//  }                                                              //~v57yR~
    if (filename && !*filename)                                    //~v50nR~
    	filename=0;                                                //~v50nI~
    if (filename)	//filename operand exist                       //~v47TI~
    {                                                              //~v08hI~
//  	UPARSERC(filename,filename,&opdno,0,",");	//parse out string(accept cr/lf)//~v47TR~
//      if (opdno>1)                                               //~v47TR~
//      	return errtoomany();                                   //~v47TR~
    	if (strcmp(filename,"*"))                               //~5128R~
        {                                                          //~v08oI~
//  		if (filesrchpfh(filename,fullpath,&pfhsrch)            //~v13dR~
            if (fcmdoutfnmedit(Ppcw,filename,fpath))               //~v59VI~
                return 4;                                          //~v59VI~
//  		if (filesrchpfh2(Ppcw,filename,fpath,&pfhsrch)         //~v59VR~
    		if (filesrchpfh(fpath,0,&pfhsrch)                      //~v59VR~
			||  pfhsrch!=pfh)                                      //~v08oI~
			return fcmdfileout(Ppcw,0);	//0:save with filename opd//~5128R~
        }                                                          //~v08oI~
    }                                                              //~v08hI~
  	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode          //~v08oR~
//	{                                                              //~v114R~
//		uerrmsg("Now Browse mode",                                 //~v095R~
//				"現在は \x95\\示モードです");                      //~v114R~
//		return 4;                                                  //~v114R~
//	}                                                              //~v114R~
		return errbrowsemode();                                    //~v114I~
    if (saveopt & (FSOC_RETLRECL|FSOC_EOL_OPT))	//no /Fxx and no eol chng//~va6QR~
    {                                                              //~va6QI~
        uerrmsg("/M and /F option is invalid for SAVe cmd to itself. Use END cmd.",//~va6QR~
                "/M と /F オプションは 自身のファイルのSAVeでは使用できません,END コマンドを使用してください");//~va6QR~
        return 4;                                                  //~va6QI~
    }                                                              //~va6QI~
//  return filesave(0,pfh,0,0,0);//save cmd,plh1=plh2=0            //~v445R~
    return filesave(Ppcw,0,pfh,0,0,0);//save cmd,plh1=plh2=0       //~v445R~
}//func_save_file

//****************************************************************//~5128I~
// func_repl_file                                               //~5128I~
//*repl command                                                 //~5128I~
//*ret  :rc                                                     //~5128I~
//****************************************************************//~5128I~
int func_repl_file(PUCLIENTWE Ppcw)                             //~5128I~
{                                                               //~5128I~
//*********************************                             //~5128I~
	return fcmdfileout(Ppcw,1);	//1:repl                        //~5128I~
}//func_repl_file                                               //~5128I~
//**************************************************************** //~v783R~
// func_cut                                                        //~v783R~
//**************************************************************** //~v783R~
int func_cut_file(PUCLIENTWE Ppcw)                                 //~v783R~
{                                                                  //~v783R~
//*********************************                                //~v783R~
    return fcmdfileout(Ppcw,FCMDFOCUT); //4:cut                    //~v783R~
}//func_cut_file                                                   //~v783R~
//****************************************************************//~5128I~
// func_create_file                                             //~5128I~
//*create command                                               //~5128I~
//*ret  :rc                                                     //~5128I~
//****************************************************************//~5128I~
int func_create_file(PUCLIENTWE Ppcw)                           //~5128I~
{                                                               //~5128I~
//*********************************                             //~5128I~
	return fcmdfileout(Ppcw,2);	//2:create cmd                  //~5128I~
}//func_create_file                                             //~5128I~
                                                                //~5128I~
//**************************************************************** //~v0iaI~
// func_append_file                                                //~v0iaR~
//*append command                                                  //~v0iaR~
//*ret  :rc                                                        //~v0iaI~
//**************************************************************** //~v0iaI~
int func_append_file(PUCLIENTWE Ppcw)                              //~v0iaR~
{                                                                  //~v0iaI~
//*********************************                                //~v0iaI~
	return fcmdfileout(Ppcw,3);	//3:append cmd                     //~v0iaR~
}//func_create_file                                                //~v0iaI~
                                                                   //~v0iaI~
//****************************************************************//~5128I~
// fcmdfileout                                                  //~5128I~
//*file output for Save with filename operand/Reple/Create      //~5128I~
//*parm1 :pcw                                                   //~5128I~
//*parm2 :function  0:save, 1:replace, 2:create                 //~5128I~
//*rc   :0                                                      //~5128I~
//****************************************************************//~5128I~
int fcmdfileout(PUCLIENTWE Ppcw,int Pfunc)                      //~5128I~
{                                                               //~5128I~
	PUFILEC pfc;                                                //~5128I~
	PUFILEH pfh;                                                //~5128I~
	PULINEH plh1,plh2;  //label range                              //~v54YR~
	int rc,replsw=0;                                              //~5128I~//~vafcR~
    int saveopt;                                                   //~v54YI~
	UCHAR *filename;                                            //~5128I~
	UCHAR  fpath[_MAX_PATH];                                       //~v576R~
    int opt;                                                       //~va65I~
    int lreclparm;                                                 //~va65I~
//  FILEFINDBUF3 fstat3;     				//output from DosFindxxxx//~v713R~
//  int opdno;                                                     //~v47TR~
//#ifdef FTPSUPP                                                   //~v713R~
//    PUFTPHOST puftph;                                            //~v713R~
//#endif                                                           //~v713R~
//*********************************                             //~5128I~
	pfc=Ppcw->UCWpfc;                                           //~5128I~
	pfh=pfc->UFCpfh;                                            //~5128I~
//  if (filesaveoptionchk(Ppcw,pfh,0,&filename))                   //~v54YR~
//  if (filesaveoptionchk(Ppcw,pfh,&saveopt,&filename))//chk -xall/-nxall option//~v54YR~
//  if (filesaveoptionchk(Ppcw,pfh,&saveopt,&filename,&plh1,&plh2))//chk -xall/-nxall option//~v57yR~
//  if (rc=filesaveoptionchk(Ppcw,pfh,&saveopt,&filename,&plh1,&plh2),rc)//chk -xall/-nxall option//~v57yM~//~va65R~
    if (rc=filesaveoptionchk(Ppcw,pfh,&saveopt,&filename,&plh1,&plh2,&lreclparm),rc)//chk -xall/-nxall option//~va65R~
    {                                                              //~v57zR~
        if (rc==2)                                                 //~v57zR~
            return 1;   //label err                                //~v57zR~
    	return 4;                                                  //~v47TI~
    }                                                              //~v57zR~
//  if (!(filename=Ppcw->UCWparm))	//operand not exist            //~v47TR~
    if (!filename)	//filename operand exist                       //~v47TR~
    {                                                              //~v54YI~
//  	return errmissing();                                       //~v54YR~
//      uerrmsg("{CRE|REP|APP} filename [ {x | nx} [ {all | .lab1 .lab2} ]",0);//~v57PR~
#ifdef UTF8SUPPH                                                   //~va00I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] [ %s | %s | %s ] [%s] .lab1 .lab2 ]",//~va50R~//~va6cR~
//      uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] [ %s | %s | %s ] [%s] [-S{r|i|d}] .lab1 .lab2 ]",//~va6cI~//~va6DR~
//      uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] [ %s | %s | %s ] [%s] [/M{P|U|M|E|R}] [/Fn[-m]] [-S{r|i|d}] .lab1 .lab2 ]",//~va6DI~//~va7tR~
        uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] [ %s | %s | %s[:converter] ] [%s] [/M{P|U|M|E|R}] [/Fn[-m]] [-S{r|i|d}] .lab1 .lab2 ]",//~va7tI~
					0,                                             //~va50I~
                    MODE_UTF8,MODE_LOCALE,MODE_EBC,MODE_IE);       //~va50R~
    #else                                                          //~va50I~
        uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] [ %s | %s ] .lab1 .lab2 ]",//~va00I~
					0,                                             //~va00I~
                    MODE_UTF8,MODE_LOCALE);                        //~va00I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va00I~
        uerrmsg("{CRE|REP|APP} filename [ [x | nx | all] .lab1 .lab2 ]",0);//~v57PI~
#endif                                                             //~va00I~
    	return 4;                                                  //~v54YI~
    }                                                              //~v54YI~
//  UPARSERC(filename,filename,&opdno,0,",");	//parse out string(accept cr/lf)//~v47TR~
//  if (opdno>1)                                                   //~v47TR~
//  	return errtoomany();                                       //~v47TR~
//  if ((rc=filesrchpfh(filename,fullpath,0))>4)//no pfh           //~v13dR~
    if (fcmdoutfnmedit(Ppcw,filename,fpath))                       //~v59VI~
        return 4;                                                  //~v59VI~
//  if ((rc=filesrchpfh2(Ppcw,filename,fpath,0))>4)//no pfh        //~v59VR~
    if ((rc=filesrchpfh(fpath,0,0))>4)//no pfh                     //~v59VI~
			return rc;     	//path err                          //~5128I~
	if (!rc)	//found                                         //~5128I~
	{                          		//found                     //~5128I~
		uerrmsg("%s is on load",                                //~5128I~
				"%s はロード中です",                            //~5128I~
//  			filename);                                         //~v59UR~
    			fpath);                                            //~v59UI~
		return 4;                                               //~5128I~
   	}                                                           //~5128I~
//  if (WILDCARD(fpath))                                           //~v59VR~
//  	ufileeditname(pfh->UFHfilename,fullpath,fullpath);    //src,patern,output//~v49jR~
//  	ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,pfh->UFHfilename,fpath,fpath);    //src,patern,output//~v59VR~
	filename=fpath;	//by full pth name                             //~v576R~
//  if ((rc=filefind(filename,0,&fstat3,FFMSG))>4)//no need fpath  //~v70zR~
//#ifdef FTPSUPP                                                     //~v70zI~,//~v713R~
//    uftpisremote(filename,&puftph); //remote hostname prefix exist //~v70zI~,//~v713R~
//    if (UFTPHISTSO(puftph))                                        //~v70zI~,//~v713R~
//        rc=xe3270ifilefindcopy(FFMSG,puftph,filename,0,&fstat3);    //0:localfilename output//+v70zR~,//~v713R~
//    else                                                           //~v70zI~,//~v713R~
//#endif                                                             //~v70zI~,//~v713R~
//        rc=filefind(filename,0,&fstat3,FFMSG);                     //~v70zI~,//~v713R~
//    if (rc>4)//no need fpath                                       //~v70zI~,//~v713R~
//        return rc;                                              //~5128I~,//~v713R~
//    replsw=!rc;                                                 //~5128I~,//~v713R~
    pfc->UFCpendfcmd=0;                                         //~v06iI~
    Sreplsw=-1;  //set by fcmdoutrange                             //~v713I~
    Sfuncid=Pfunc;                                                 //~vaj0I~
	switch(Pfunc)                                               //~5128I~
	{                                                           //~5128I~
	case 0:			//save                                      //~5128I~
//#ifdef WXE                                                       //~v64oR~
#ifdef WXEXXE                                                      //~v64oI~
	#ifndef XXE		//xxe issue no prompt when replace,chk existing//~vaf4I~
      replsw=0;     //WXE uncoditionaly replace(Filedialog confirmed override)//~vaf2R~
  	  if (!(Gwxestat & GWXES_CMD))	//not cmd from wxe menu        //~v500I~
    #endif                                                         //~vaf4I~
#endif                                                             //~v500I~
		if (rc=fcmdfilefind(filename,&replsw),rc)                  //~v713R~
        	return rc;                                             //~v713I~
		if (replsw)		//file already exeist                   //~5128I~
			if (!scrconfirmchk(GSCRCONFSAVE))	//not yet confirmed//~5128I~
			{                                                   //~5128I~
				uerrmsg("Replace %s?,Esc to reset",             //~5128I~
						"%s を置換しますか ?, Escで取消",       //~5128I~
						filename);                              //~5128I~
				return 4;                                       //~5128I~
			}                                                   //~5128I~
//		rc=filesave(0,pfh,0,0,filename);//save cmd,plh1=plh2=0     //~v445R~
  		rc=filesave(Ppcw,0,pfh,0,0,filename);//save cmd,plh1=plh2=0//~v445I~
		break;                                                  //~5128I~
	case 1:			//replace                                   //~5128I~
	case FCMDFOCUT:			//4:cut                                //~v783R~
      if (saveopt & (FSOC_XALL|FSOC_NXALL))                        //~v54YI~
      {                                                            //~v713I~
		if (rc=fcmdfilefind(filename,&replsw),rc)                  //~v713I~
        	return rc;                                             //~v713I~
  		rc=filesave(Ppcw,FSENDSW_END,pfh,plh1,plh2,filename);//close after write//~v54YR~
      }                                                            //~v713I~
      else                                                         //~v54YI~
      {                                                            //~v54YI~
		rc=fcmdcalllcmd(Ppcw,filename,FCMDFOREP);                        //~5128R~~//~v06lR~
    	if (pfc->UFCpendfcmd)                                   //~v06iI~
            pfc->UFCpendfcmd=FCMDFOREP;                         //~v06iI~
      }                                                            //~v54YI~
		break;                                                  //~5128I~
	case 2:			//create                                    //~5128I~
//        if (replsw)     //file already exeist                   //~5128I~,//~v713R~
//        {                                                       //~5128I~,//~v713R~
//            uerrmsg("%s is already exist",                      //~5128I~,//~v713R~
//                    "%s は既に存在しています",                  //~5128R~,//~v713R~
//                    filename);                                  //~5128I~,//~v713R~
//            return 4;                                           //~5128I~,//~v713R~
//        }                                                       //~5128I~,//~v713R~
      if (saveopt & (FSOC_XALL|FSOC_NXALL))                        //~v54YI~
      {                                                            //~v713I~
		if (rc=fcmdfilefind(filename,&replsw),rc)                  //~v713R~
        	return rc;                                             //~v713I~
        if (replsw)     //file already exeist                   //~5128I~,//~v713I~
        	return ufileexist(filename,4);                         //~v713I~
  		rc=filesave(Ppcw,FSENDSW_END,pfh,plh1,plh2,filename);//close after write//~v54YR~
      }                                                            //~v713I~
      else                                                         //~v54YI~
      {                                                            //~v54YI~
		rc=fcmdcalllcmd(Ppcw,filename,FCMDFOCRE);                        //~5128R~~//~v06lR~
    	if (pfc->UFCpendfcmd)                                   //~v06iI~
            pfc->UFCpendfcmd=FCMDFOCRE;                         //~v06iI~
      }                                                            //~v54YI~
		break;                                                  //~5128I~
	case FCMDFOAPP:			//3:append                             //~v0iaR~
      if (saveopt & (FSOC_XALL|FSOC_NXALL))                        //~v54YI~
      {                                                            //~v713I~
		if (rc=fcmdfilefind(filename,&replsw),rc)                  //~v713I~
        	return rc;                                             //~v713I~
  		rc=filesave(Ppcw,FSENDSW_APPEND,pfh,plh1,plh2,filename);//append then close after write//~v54YR~
      }                                                            //~v713I~
      else                                                         //~v54YI~
      {                                                            //~v54YI~
		rc=fcmdcalllcmd(Ppcw,filename,FCMDFOAPP);                        //~5128R~~//~v0iaI~
    	if (pfc->UFCpendfcmd)                                      //~v0iaI~
            pfc->UFCpendfcmd=FCMDFOAPP;                            //~v0iaI~
      }                                                            //~v54YI~
		break;                                                     //~v0iaI~
	}//sw by func                                               //~5128I~
                                                                //~5128I~
    if (Sreplsw!=-1)  //set by fcmdoutrange                        //~v713I~
    	replsw=Sreplsw;                                            //~v713R~
	if (!rc)	//sccess                                        //~5128I~
    {                                                              //~v54dI~
	  if (Pfunc==FCMDFOCUT)     //cut cmd                          //~v783R~
		uerrmsg("saved to the 2nd Clipboard",                      //~v783R~
					"第二クリップボードに複写");                   //~v783R~
      else                                                         //~v783R~
      {                                                            //~v783R~
		if (replsw)                                             //~5128I~
          if (Pfunc==FCMDFOAPP)                                    //~v0iaI~
			uerrmsg("appended to %s",                              //~v0iaI~
					"%s に追加しました",                           //~v0iaI~
					filename);                                     //~v0iaI~
          else                                                     //~v0iaI~
			uerrmsg("%s was replaced",                          //~5128I~
					"%s を置換しました",                        //~5128I~
					filename);                                  //~5128I~
		else                                                    //~5128I~
			uerrmsg("%s was created",                           //~5128I~
					"%s を作成しました",                        //~5128I~
					filename);                                  //~5128I~
      }                                                            //~va6gI~
#ifdef UTF8SUPPH                                                   //~va00I~
//  	fileupdateprofilesave(0,Ppcw,pfh,saveopt,filename);        //~va00R~//~va65R~
       	if (replsw && Pfunc==FCMDFOAPP)                            //~va65R~
            opt=0;              //no update profile for APP cmd    //~va65I~
        else                                                       //~va65I~
        	opt=FUPO_FCMD;       //update recordmode/lrecl         //~va65M~
        if (!(saveopt & (FSOC_RETLRECL|FSOC_EOL_OPT))	//no /Fxx and no eol chng//~va6QR~
//      &&   UCBITCHK(pfh->UFHflag10,UFHF10RECORD)                 //~va6QI~//~vaj0R~
        )                                                          //~va6QI~
        {                                                          //~vaj0I~
          if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD))               //~vaj0I~
        	lreclparm=(pfh->UFHlrecl<<16)|pfh->UFHmergin;          //~va6QR~
          else                                                     //~vaj0I~
          if (UCBITCHK(pfh->UFHflag13,UFHF13RV))                   //~vaj0R~
        	lreclparm=pfh->UFHvfmt;                                //~vaj0I~
        }                                                          //~vaj0I~
//  	fileupdateprofilesave(opt,Ppcw,pfh,saveopt,filename);      //~va65R~
	  if (Pfunc!=FCMDFOCUT) //for CUT, update profile from filesave//~vaj0R~
    	fileupdateprofilesave(opt,Ppcw,pfh,saveopt,filename,lreclparm);//~va65I~
#endif                                                             //~va00I~
//    }                                                            //~v783R~//~va6gR~
    }                                                              //~v54dI~
	return rc;                                                  //~5128R~
}//fcmdfileout                                                  //~5128I~
//**************************************************************** //~v713I~
// fcmdfilefind                                                    //~v713I~
//* file exist chk for save/cre/rep/app                            //~v713I~
//*ret  :rc                                                        //~v713I~
//**************************************************************** //~v713I~
int fcmdfilefind(char *Pfilename,int *Pprepsw)                     //~v713I~
{                                                                  //~v713I~
//#ifdef FTPSUPP                                                   //~v716R~
//    PUFTPHOST puftph;                                            //~v716R~
//#endif                                                           //~v716R~
	int rc;                                                        //~v713I~
	FILEFINDBUF3 fstat3;     				//output from DosFindxxxx//~v713I~
//****************************                                     //~v713I~
//#ifdef FTPSUPP                                                     //~v713I~,//~v716R~
//    uftpisremote(Pfilename,&puftph); //remote hostname prefix exist//~v713I~,//~v716R~
//    if (UFTPHISTSO(puftph))                                        //~v713I~,//~v716R~
//        rc=xetsofilefindcopy(FFMSG,puftph,Pfilename,0,&fstat3); //0:localfile//name output//~v713I~,//~v716R~
//    else                                                           //~v713I~,//~v716R~
//#endif                                                             //~v713I~,//~v716R~
//    	rc=filefind(Pfilename,0,&fstat3,FFMSG);                    //~v713R~//~va00R~
      	rc=filefind(Pfilename,0,&fstat3,FFNONFMSG);                //~va00I~
    if (rc>4)//no need fpath                                       //~v713I~
		return rc;                                                 //~v713I~
	*Pprepsw=!rc;                                                  //~v713R~
    return 0;                                                      //~v713I~
}//fcmdfilefind                                                    //~v713I~
//**************************************************************** //~v713I~
// fcmdfilefind                                                    //~v713I~
//* called from fcmdoutrange/fcmdoutrangebs before save            //~v713I~
//*ret  :rc                                                        //~v713I~
//**************************************************************** //~v713I~
int fcmdfilefind2(char *Pfilename,int Pcmdid,int *Pprepsw)         //~v713R~
{                                                                  //~v713I~
	int rc;                                                        //~v713R~
//***************************                                      //~v713I~
	if (rc=fcmdfilefind(Pfilename,Pprepsw),rc)                     //~v713R~
    	return rc;                                                 //~v713I~
    if (Pcmdid==FCMDFOCRE && *Pprepsw)	//create and exist         //~v713R~
        	return ufileexist(Pfilename,4);                        //~v713R~
    return 0;                                                      //~v713I~
}//fcmdfilefind2                                                   //~v713I~
//**************************************************************** //~v59VI~
// fcmdoutfnmedit                                                  //~v59VI~
//* edit output filename(fill wildpath,rep wildmemb patern)        //~v59VI~
//*parm2:fullpath file name                                        //~v59VI~
//*parm3:pending cmd id for call capfcmdi3                         //~v59VI~
//*ret  :rc                                                        //~v59VI~
//**************************************************************** //~v59VI~
int fcmdoutfnmedit(PUCLIENTWE Ppcw,UCHAR *Pwildfnm,UCHAR *Pfpath)  //~v59VI~
{                                                                  //~v59VI~
	PUFILEC pfc;                                                   //~v59VI~
	PUFILEH pfh;                                                   //~v59VI~
	UCHAR  *pc,fpath[_MAX_PATH];                                   //~v59VI~
//***************                                                  //~v59VI~
	pfc=Ppcw->UCWpfc;                                              //~v59VI~
	pfh=pfc->UFCpfh;                                               //~v59VI~
	Gsubgblopt|=XESUB_GBLOPT_WILDPATH;	//expand wildcard path     //~v59VI~
    pc=dcmdfullpath(Ppcw,fpath,Pwildfnm);	//expand wild card if exist//~v59VI~
	Gsubgblopt&=~XESUB_GBLOPT_WILDPATH;//clear for later req       //~v59VI~
    if (!pc)                                                       //~v59VI~
    	return 16;                                                 //~v59VI~
    if (WILDCARD(fpath))                                           //~v59VI~
    	ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,pfh->UFHfilename,fpath,fpath);    //src,patern,output//~v59VI~
    strcpy(Pfpath,fpath);                                          //~v59VI~
    return 0;                                                      //~v59VI~
}//fcmdoutfnmedit                                                  //~v59VI~
//****************************************************************//~5128I~
// fcmdcalllcmd                                                 //~5128R~
//* get source line for repl/create cmd                         //~5128I~
//*parm1:pcw                                                    //~5128I~
//*parm2:fullpath file name                                     //~5128I~
//*parm3:pending cmd id for call capfcmdi3                         //~v0iaR~
//*ret  :rc                                                     //~5128I~
//****************************************************************//~5128I~
int fcmdcalllcmd(PUCLIENTWE Ppcw,UCHAR *Pfilename,UCHAR Prepcre)//~v06lR~
{                                                               //~5128I~
	int rc;                                                     //~5128I~
//***************                                               //~5128I~
	ugeterrmsg();	//clear file not found msg                  //~5129I~
	strcpy(Scopyfilename,Pfilename);//parm to fcmdoutrange      //~5128I~
	fcmdaddslh(Ppcw);                                              //~v500R~
    strcpy(Slh.ULHlinecmd,"A");	//destination cmd               //~5128I~
    Sfcmdid=Prepcre;                //rep/cre/app                  //~v0iaI~
	rc=filelinecmd(Ppcw);	//lcmdcopy callback fcmdoutrange    //~5128I~
    Sfcmdid=0;						//used                         //~v0iaI~
    if (rc==1)                                                  //~v06iI~
    {                                                           //~v06lI~
        rc=capfcmdi3(Ppcw,Prepcre);	//line pending              //~v06lR~
		if (rc==1)                                              //~v06lI~
//  	uerrmsg("Specify line range",                              //~v57PR~
//  			"複写元の範囲を指定して下さい");                   //~v57PR~
		  	uerrmsg("Specify line range, or option x or nx.",      //~v57PI~
  					"複写元の範囲か、x あるいは nx オプションを指定して下さい。");//~v57PI~
    }                                                           //~v06lI~
//	delslh(Ppcw);                                               //~v04fR~
	return rc;                                                  //~5128I~
}//fcmdcalllcmd                                                 //~5128R~
                                                                //~5128I~
//****************************************************************//~5128I~
// fcmdoutrange                                                 //~5128I~
//* pass output range start/stop plh for create/repl cmd        //~5128I~
//*rc   :0                                                      //~5128I~
//****************************************************************//~5128I~
int fcmdoutrange(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)   //~5128I~
{                                                               //~5128I~
	int endsw;                                                     //~v0iaI~
	int rc;                                                        //~v713I~
//***************                                               //~5128I~
	if (rc=fcmdfilefind2(Scopyfilename,Sfcmdid,&Sreplsw),rc)       //~v713R~
    	return rc;                                                 //~v713I~
    if (Sfcmdid==FCMDFOAPP)                                        //~v0iaI~
    	endsw=FSENDSW_APPEND;//append id                           //~v0iaR~
	else                                                           //~v0iaI~
    	endsw=0;		//save cmd not PF3(end)                    //~v0iaI~
    if (Sfuncid==FCMDFOCUT)                                        //~vaj0R~
    	endsw|=FSENDSW_CUT;//copy to CB2                           //~vaj0I~
//  return filesave(0,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~v0iaR~
//  return filesave(endsw,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~v445R~
    return filesave(Ppcw,endsw,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~v445I~
}//fcmdoutrange                                                 //~5128I~
                                                                //~5128I~
//**************************************************************** //~v0iaI~
// fcmdoutrangebs                                                  //~v0iaI~
//* pass output range start/stop plh for create/repl cmd           //~v0iaI~
//* for bandle used case                                           //~v0iaI~
//*parm1:pcw                                                       //~v0iaI~
//*parm2:start plh                                                 //~v0iaI~
//*parm3:end   plh                                                 //~v0iaI~
//*rc   :0                                                         //~v0iaI~
//**************************************************************** //~v0iaI~
int fcmdoutrangebs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)    //~v0iaR~
{                                                                  //~v0iaI~
	int rc;                                                        //~v713I~
	int endsw;                                                     //~vaj0I~
//*************************                                        //~v713I~
	if (rc=fcmdfilefind2(Scopyfilename,Sfcmdid,&Sreplsw),rc)       //~v713R~
    	return rc;                                                 //~v713I~
    endsw=FSENDSW_BANDLE;                                          //~vaj0I~
//  return filesave(FSENDSW_BANDLE,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~v445R~
//  return filesave(Ppcw,FSENDSW_BANDLE,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~v445I~//~vaj0R~
    endsw=FSENDSW_BANDLE;                                          //~vaj0I~
    if (Sfuncid==FCMDFOCUT)                                        //~vaj0R~
    	endsw|=FSENDSW_CUT;//copy to CB2                           //~vaj0I~
    return filesave(Ppcw,endsw,UGETPFH(Pplh1),Pplh1,Pplh2,Scopyfilename);//save cmd,plh1=plh2=0//~vaj0I~
}//fcmdoutrangebs                                                  //~v0iaR~
                                                                   //~v0iaI~
//**************************************************************** //~vb54I~
void  fcmddisptabaltch(void)                                       //~vb54I~
{                                                                  //~vb54I~
	char wkaltch[2][32],*pc1,*pc2;                                 //~vb54I~
    int ucs1,ucs2;                                                 //~vb54I~
    int ucs3;                                                      //~vb5bI~
	char wkaltchdbcsspace[32],*pc3;                                //~vb5bI~
//**************                                                   //~vb54I~
    pc1=wkaltch[0];                                                //~vb54I~
    if (Gfiletabdisp1==DEFAULT_ALTCH                               //~vb54I~
    &&  (ucs1=utfgetvisiblealtch(UTFGVACO_TAB,DEFAULT_ALTCH),ucs1>0))//~vb54R~
    	sprintf(pc1,"U%02x",ucs1);                                 //~vb54I~
    else                                                           //~vb54I~
    	sprintf(pc1,"%c(0x%02x)",Gfiletabdisp1,Gfiletabdisp1);     //~vb54R~
    pc2=wkaltch[1];                                                //~vb54I~
    if (Gfiletabdisp2==DEFAULT_ALTCH                               //~vb54I~
    &&  (ucs2=utfgetvisiblealtch(UTFGVACO_TABPAD,DEFAULT_ALTCH),ucs2>0))//~vb54R~
    	sprintf(pc2,"U%02x",ucs2);                                 //~vb54I~
    else                                                           //~vb54I~
    	sprintf(pc2,"%c(0x%02x)",Gfiletabdisp2,Gfiletabdisp2);     //~vb54R~
    pc3=wkaltchdbcsspace;                                          //~vb5bR~
    if (Gunpdispchar[3]==DEFAULT_ALTCH                             //~vb5bI~
    &&  (ucs3=utfgetvisiblealtch(UTFGVACO_DBCSSPACE,DEFAULT_ALTCH),ucs3>0))//~vb5bI~
    	sprintf(pc3,"U%02x",ucs3);                                 //~vb5bI~
    else                                                           //~vb5bI~
    	sprintf(pc3,"%c(0x%02x)",Gunpdispchar[3],Gunpdispchar[3]); //~vb5bI~
//  uerrmsgcat("; altch=%s-%s",                                    //~vb5bR~
//  			"; タブ\x95\\示文字=%s-%s",                        //~vb5bR~
//      		pc1,pc2);                                          //~vb5bR~
    uerrmsgcat("; altch Tab=%s-%s,DBCSspace=%s",                   //~vb5bR~
    			"; タブ文字=%s-%s,DBCS空白文字=%s",                //~vb5bR~
        		pc1,pc2,pc3);                                      //~vb5bI~
}//fcmddisptabaltch                                                //~vb54I~
//**************************************************************** //~vb54I~
int fcmdgetaltchUCS(char *Popd)                                    //~vb54I~
{                                                                  //~vb54I~
	ULONG ucs1,ucs2;                                               //~vb54R~
    char *pc,*pc2,wkopd[32];                                       //~vb54I~
    int swucs1=0,swucs2=0;                                         //~vb54R~
    char *pc3;                                                     //~vb5bI~
	ULONG ucs3=0;                                                  //~vb5bI~
    int swucs3=0;                                                  //~vb5bI~
//**************                                                   //~vb54I~
	strncpy(wkopd,Popd,sizeof(wkopd));                             //~vb54R~
    wkopd[sizeof(wkopd)-1]=0;                                      //~vb54I~
	pc=wkopd;                                                      //~vb54I~
    if (toupper(*pc)!='U')                                         //~vb54I~
    	return 4;                                                  //~vb54I~
    pc++;                                                          //~vb54I~
    if (*pc=='-')                                                  //~vb54R~
    	pc++;                                                      //~vb54I~
    pc2=strchr(pc,'-');                                            //~vb54I~
    if (pc2)                                                       //~vb54I~
	    *pc2++=0;                                                  //~vb54I~
    if (ux2l(pc,&ucs1))                                            //~vb54R~
    	return 4;                                                  //~vb54I~
    if (pc2)                                                       //~vb54I~
    {                                                              //~vb54I~
    	pc=pc2;                                                    //~vb54I~
    	if (toupper(*pc)=='U')                                     //~vb54I~
    		pc++;                                                  //~vb54I~
    	if (*pc=='-')                                              //~vb54R~
    		pc++;                                                  //~vb54I~
	    pc3=strchr(pc,'-');                                        //~vb5bI~
    	if (pc3)                                                   //~vb5bI~
	    	*pc3++=0;                                              //~vb5bI~
	    if (ux2l(pc,&ucs2))                                        //~vb54R~
    		return 4;                                              //~vb54I~
//*dbcsspace                                                       //~vb5bI~
        if (pc3)                                                   //~vb5bI~
        {                                                          //~vb5bI~
	    	pc=pc3;                                                //~vb5bI~
    		if (toupper(*pc)=='U')                                 //~vb5bI~
    			pc++;                                              //~vb5bI~
    		if (*pc=='-')                                          //~vb5bI~
    			pc++;                                              //~vb5bI~
		    if (ux2l(pc,&ucs3))                                    //~vb5bI~
    			return 4;                                          //~vb5bI~
        }                                                          //~vb5bI~
    }                                                              //~vb54I~
    else                                                           //~vb54I~
    	ucs2=0;                                                    //~vb54I~
    if (ucs1 && ucs1<0x100)                                        //~vb54I~
	{                                                              //~vb54I~
        swucs1=1;                                                  //~vb54I~
//      Gfiletabdisp1=(UCHAR)(Gopttabaltch[0]=(int)ucs1);          //~vb5bR~
    }                                                              //~vb54I~
    else                                                           //~vb54I~
    if (ucs1>=0x100)                                               //~vb54I~
	{                                                              //~vb54I~
		if (utfsetvisiblealtch(UTFGVACO_TAB,(int)ucs1))            //~vb54R~
        	return 4;                                              //~vb54M~
        swucs1=2;                                                  //~vb54I~
//      Gopttabaltch[0]=(int)ucs1;                                 //~vb5bR~
//  	Gfiletabdisp1=DEFAULT_ALTCH;//0xff                         //~vb5bR~
    }                                                              //~vb54I~
    if (ucs2 && ucs2<0x100)                                        //~vb5bR~
	{                                                              //~vb54I~
        swucs2=1;                                                  //~vb54I~
//      Gfiletabdisp2=(UCHAR)(Gopttabaltch[1]=(int)ucs2);          //~vb5bR~
    }                                                              //~vb54I~
    else                                                           //~vb54I~
    if (ucs2>=0x100)                                               //~vb5bR~
	{                                                              //~vb54I~
		if (utfsetvisiblealtch(UTFGVACO_TABPAD,(int)ucs2))         //~vb54R~
        	return 4;                                              //~vb54M~
        swucs2=2;                                                  //~vb54I~
//      Gopttabaltch[1]=(int)ucs2;                                 //~vb5bR~
//  	Gfiletabdisp2=DEFAULT_ALTCH;//0xff                         //~vb5bR~
    }                                                              //~vb54I~
//*dbcsspace                                                       //~vb5bI~
    if (ucs3 && ucs3<0x100)                                        //~vb5bI~
	{                                                              //~vb5bI~
        swucs3=1;                                                  //~vb5bI~
    }                                                              //~vb5bI~
    else                                                           //~vb5bI~
    if (ucs3>=0x100)                                               //~vb5bI~
	{                                                              //~vb5bI~
		if (utfsetvisiblealtch(UTFGVACO_DBCSSPACE,(int)ucs3))      //~vb5bI~
        	return 4;                                              //~vb5bI~
        swucs3=2;                                                  //~vb5bI~
    }                                                              //~vb5bI~
    if (swucs1==1)                                                 //~vb54I~
	    Gfiletabdisp1=(UCHAR)(Gopttabaltch[0]=(int)ucs1);          //~vb54R~
    else                                                           //~vb54I~
    if (swucs1==2)                                                 //~vb54I~
	{                                                              //~vb54I~
	    Gopttabaltch[0]=(int)ucs1;                                 //~vb54R~
		Gfiletabdisp1=DEFAULT_ALTCH;//0xff                         //~vb54I~
    }                                                              //~vb54I~
    if (swucs2==1)                                                 //~vb54I~
	    Gfiletabdisp2=(UCHAR)(Gopttabaltch[1]=(int)ucs2);          //~vb54R~
    else                                                           //~vb54I~
    if (swucs2==2)                                                 //~vb54I~
	{                                                              //~vb54I~
	    Gopttabaltch[1]=(int)ucs2;                                 //~vb54R~
		Gfiletabdisp2=DEFAULT_ALTCH;//0xff                         //~vb54I~
    }                                                              //~vb54I~
    if (swucs3==1)                                                 //~vb5bI~
	    Gunpdispchar[3]=(UCHAR)(Gopttabaltch[2]=(int)ucs3);        //~vb5bI~
    else                                                           //~vb5bI~
    if (swucs3==2)                                                 //~vb5bI~
	{                                                              //~vb5bI~
	    Gopttabaltch[2]=(int)ucs2;                                 //~vb5bI~
		Gunpdispchar[3]=DEFAULT_ALTCH;//0xff                       //~vb5bI~
    }                                                              //~vb5bI~
    UTRACEP("%s:opd=%s,opttabaltch=%02x-%02x-%02x,Gfiletabdisp=%04x-%04x-%04x\n",UTT,Popd,Gopttabaltch[0],Gopttabaltch[1],Gopttabaltch[2],Gfiletabdisp1,Gfiletabdisp2,Gunpdispchar[3]);//~vb5bR~
    return 0;                                                      //~vb54I~
}//fcmdgetaltchUCS                                                 //~vb54I~
//**************************************************************** //~vb54I~
int  fcmdgettabaltch(int Popt,PUCLIENTWE Ppcw,char *Popd)          //~vb54R~
{                                                                  //~vb54I~
	int len;                                                       //~vb54I~
    UCHAR olddbcsspacealt;                                         //~vb5bI~
//**************                                                   //~vb54I~
    if (Ppcw->UCWopdno<=1)                                         //~vb54I~
    	return 0;                                                  //~vb54I~
    olddbcsspacealt=Gunpdispchar[3];	//update chk               //~vb5bI~
	len=(int)strlen(Popd);                                         //~vb54I~
    switch(len)                                                    //~vb54I~
    {                                                              //~vb54I~
    case 0:                                                        //~vb54I~
    	return 0;                                                  //~vb54I~
    case 1:                                                        //~vb54I~
        if (*Popd=='0')                                            //~vb54I~
        {                                                          //~vb54I~
	    	Gopttabaltch[0]=0;                                     //~vb54R~
		    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)         //~vb54I~
    			Gfiletabdisp1=Gtabdispchar[2];//jpn1               //~vb54I~
            else                                                   //~vb54I~
		    	Gfiletabdisp1=Gtabdispchar[0];//eng1               //~vb54I~
            if (Gfiletabdisp1==DEFAULT_ALTCH)                      //~vb54I~
				if (utfsetvisiblealtch(UTFGVACO_TAB,UTF22_TABALT1))//~vb54R~
		        	return 4;                                      //~vb54I~
        }                                                          //~vb54I~
        else                                                       //~vb54I~
	    	Gfiletabdisp1=(UCHAR)(Gopttabaltch[0]=*Popd);          //~vb54R~
        break;                                                     //~vb54I~
    case 2:                                                        //~vb54I~
        if (*Popd=='0')                                            //~vb54I~
        {                                                          //~vb54I~
	    	Gopttabaltch[0]=0;                                     //~vb54R~
		    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)         //~vb54I~
    			Gfiletabdisp1=Gtabdispchar[2];//jpn1               //~vb54I~
            else                                                   //~vb54I~
		    	Gfiletabdisp1=Gtabdispchar[0];//eng1               //~vb54I~
            if (Gfiletabdisp1==DEFAULT_ALTCH)                      //~vb54I~
				if (utfsetvisiblealtch(UTFGVACO_TAB,UTF22_TABALT1))//~vb54R~
		        	return 4;                                      //~vb54I~
        }                                                          //~vb54I~
        else                                                       //~vb54I~
    		Gfiletabdisp1=(UCHAR)(Gopttabaltch[0]=*Popd);          //~vb54R~
        if (*(Popd+1)=='0')                                        //~vb54I~
        {                                                          //~vb54I~
	    	Gopttabaltch[1]=0;                                     //~vb54R~
		    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)         //~vb54I~
    			Gfiletabdisp2=Gtabdispchar[3];//jpn2               //~vb54R~
            else                                                   //~vb54I~
		    	Gfiletabdisp2=Gtabdispchar[1];//eng2               //~vb54R~
            if (Gfiletabdisp2==DEFAULT_ALTCH)                      //~vb54I~
				if (utfsetvisiblealtch(UTFGVACO_TABPAD,UTF22_TABALT2))//~vb54R~
		        	return 4;                                      //~vb54I~
        }                                                          //~vb54I~
        else                                                       //~vb54I~
    		Gfiletabdisp2=(UCHAR)(Gopttabaltch[1]=*(Popd+1));      //~vb54R~
        break;                                                     //~vb54I~
    case 3:                                                        //~vb5bI~
        if (*Popd=='0')                                            //~vb5bI~
        {                                                          //~vb5bI~
	    	Gopttabaltch[0]=0;                                     //~vb5bI~
		    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)         //~vb5bI~
    			Gfiletabdisp1=Gtabdispchar[2];//jpn1               //~vb5bI~
            else                                                   //~vb5bI~
		    	Gfiletabdisp1=Gtabdispchar[0];//eng1               //~vb5bI~
            if (Gfiletabdisp1==DEFAULT_ALTCH)                      //~vb5bI~
				if (utfsetvisiblealtch(UTFGVACO_TAB,UTF22_TABALT1))//~vb5bI~
		        	return 4;                                      //~vb5bI~
        }                                                          //~vb5bI~
        else                                                       //~vb5bI~
    		Gfiletabdisp1=(UCHAR)(Gopttabaltch[0]=*Popd);          //~vb5bI~
        if (*(Popd+1)=='0')                                        //~vb5bI~
        {                                                          //~vb5bI~
	    	Gopttabaltch[1]=0;                                     //~vb5bI~
		    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)         //~vb5bI~
    			Gfiletabdisp2=Gtabdispchar[3];//jpn2               //~vb5bI~
            else                                                   //~vb5bI~
		    	Gfiletabdisp2=Gtabdispchar[1];//eng2               //~vb5bI~
            if (Gfiletabdisp2==DEFAULT_ALTCH)                      //~vb5bI~
				if (utfsetvisiblealtch(UTFGVACO_TABPAD,UTF22_TABALT2))//~vb5bI~
		        	return 4;                                      //~vb5bI~
        }                                                          //~vb5bI~
        else                                                       //~vb5bI~
    		Gfiletabdisp2=(UCHAR)(Gopttabaltch[1]=*(Popd+1));      //~vb5bI~
        if (*(Popd+2)=='0')                                        //~vb5bI~
        {                                                          //~vb5bI~
	    	Gopttabaltch[2]=0;                                     //~vb5bI~
	    	Gunpdispchar[3]=Gunpdispchar3_after_inigetopt;         //+vb5bR~
            if (Gunpdispchar[3]==DEFAULT_ALTCH)                    //~vb5bI~
				if (utfsetvisiblealtch(UTFGVACO_DBCSSPACE,UTF22_DBCSSPACEALT))//~vb5bR~
		        	return 4;                                      //~vb5bI~
        }                                                          //~vb5bI~
        else                                                       //~vb5bI~
    		Gunpdispchar[3]=(UCHAR)(Gopttabaltch[2]=*(Popd+2));    //~vb5bI~
        break;                                                     //~vb5bI~
    default:                                                       //~vb54I~
        if (fcmdgetaltchUCS(Popd))                                 //~vb54I~
        {                                                          //~vb54I~
            if (!ugeterrmsg2())                                    //~vb54I~
//  			uerrmsg("operand err(%s), specify altch by 2byte ASCII character or 2 unicode(Uxxxx-yyyy).",//~vb5bR~
//  					"エラー(%s), altch(タブ\x95\\示文字)は２桁の文字か２ユニコード(U-xxxx-yyyy)で指定してください",//~vb5bR~
    			uerrmsg("operand err(%s), specify altch for TAB [and DBCSspace] by 2 or 3 ASCII or unicode(Uxxxx-yyyy[-zzzz]) char.",//~vb5bI~
    					"エラー(%s), タブ/DBCS空白\x95\\示文字は２-３ ASCII文字かユニコード(U-xxxx-yyyy[-zzzz])で指定してください",//~vb5bI~
                		Popd);                                     //~vb54R~
	    	return 4;                                              //~vb54I~
        }                                                          //~vb54I~
    }                                                              //~vb54I~
    if (olddbcsspacealt!=Gunpdispchar[3])	//DBCS spacealt updated//~vb5bI~
    	uviom_setopt2(UVIOMO2_NOTIFY_DBCSSPACEALT,Gunpdispchar+3); //~vb5bR~
    return 1;                                                      //~vb54I~
}//fcmdgettabaltch                                                 //~vb54I~
//****************************************************************
// func_tabctr_file
//*set tab skip count
//*rc   :0
//****************************************************************
int func_tabctr_file(PUCLIENTWE Ppcw)
{
	int   tabctr;
	UCHAR *pc;
    PUFILEC pfc;                                                   //~v50mR~
    PUFILEH pfh;                                                   //~v8@2I~
    int defaultsw=0;                                               //~v8@2R~
    int rc2;                                                       //~vb54I~
//*********************************
	pc=Ppcw->UCWparm;		//operand
	if (!pc)
	{
//  	uerrmsg("Missing on/off/clear or Tab Column(now %d) operand",//~v8@2R~
//  			"on/off/clear 又は桁数(現在は %d)を指定して下さい",//~v8@2R~
//  	uerrmsg("TAB { on| off | clear | =default | nn [asdefault] }; current 'nn default' is %d.",//~vb54R~
//  	        "TAB { on| off | clear | =default | nn [asdefault] }; 'nn default' の現在値は %d.",//~vb54R~
//  	uerrmsg("TAB { on [altch] | off | clear | =default | nn [asdefault] } (altch:ex. \":;\", u21be-21c0.); current 'nn default' is %d.",//~vb58R~
//  	        "TAB { on [altch] | off | clear | =default | nn [asdefault] } (altchの例. \":;\", u21be-21c0.); 'nn default' の現在値は %d.",//~vb58R~
    	uerrmsg("TAB { on [altch] | off | clear | =default | nn [asdefault] } (altch:ex. \":;\", u25b8-25b9.); current 'nn default' is %d.",//~vb58I~
    	        "TAB { on [altch] | off | clear | =default | nn [asdefault] } (altchの例. \":;\", u25b8-25b9.); 'nn default' の現在値は %d.",//~vb58I~
				Gfiletabskip);
//  	return 4;                                                  //~v50mR~
    	return 0;                                                  //~v50mI~
	}
    pc=Ppcw->UCWopdpot;                                            //~v8@2R~
	if (!strcmp(strupr(pc),"ON"))
	{
    	rc2=fcmdgettabaltch(0,Ppcw,pc+strlen(pc)+1);	//get altch to Gopttabaltch//~vb54R~
        if (rc2>1)                                                 //~vb54I~
        	return rc2;                                            //~vb54I~
      if (!rc2)	//no altch operand                                 //~vb54I~
    	if (UCBITCHK(Gopt,GOPTTABDISPLAY))	//on before         //~5603R~
        {                                                       //~5603I~
			uerrmsg("Already tab display ON",                   //~5603I~
//  				"タブ表示モ－ドは既にONです");                 //~v095R~
    				"タブ\x95\\示モ－ドは既にONです");             //~v095R~
            fcmddisptabaltch();        	                           //~vb54I~
			return 4;                                           //~5603I~
        }                                                       //~5603I~
                                                                //~5603I~
//  	UCBITON(Gprocstatus,GPROCSINIUPDATE);//need write ini at term//~v065R~
    	UCBITON(Giniopt,GOPTTABDISPLAY);                 
		UCBITON(Gopt,GOPTTABDISPLAY);                           //~5603I~
#ifdef UTF8SUPPH                                                   //~va1cR~
	    uviom_setopt2(UVIOMO2_PADON,0/*optch*/);                   //~va1cR~
#endif                                                             //~va1cR~
		scrfulldraw(Ppcw);
		uerrmsg("Set to Tab-Display Mode",
//  			"タブ表示モ－ドに設定");                           //~v095R~
    			"タブ\x95\\示モ－ドに設定");                       //~v095R~
        fcmddisptabaltch();                                        //~vb54I~
		return 0;
	}
	if (!strcmp(strupr(pc),"OFF"))
	{
    	if (!UCBITCHK(Gopt,GOPTTABDISPLAY))	//off before        //~5603R~
        {                                                       //~5603I~
//  		uerrmsg("Already tab display ON",                      //~v20VR~
    		uerrmsg("Already tab display OFF",                     //~v20VI~
//  				"タブ表示モ－ドは既にOFFです");                //~v095R~
    				"タブ\x95\\示モ－ドは既にOFFです");            //~v095R~
			return 4;                                           //~5603I~
        }                                                       //~5603I~
//  	UCBITON(Gprocstatus,GPROCSINIUPDATE);//need write ini at term//~v065R~
    	UCBITOFF(Giniopt,GOPTTABDISPLAY);                    
		UCBITOFF(Gopt,GOPTTABDISPLAY);                          //~5603I~
#ifdef UTF8SUPPH                                                   //~va1cR~
	    uviom_setopt2(UVIOMO2_PADOFF,0/*optch*/);                  //~va1cR~
#endif                                                             //~va1cR~
		scrfulldraw(Ppcw);
		uerrmsg("Set to Non-Tab-Display Mode",
//				"タブ非表示モ－ドに設定");                         //~v095R~
  				"タブ非\x95\\示モ－ドに設定");                     //~v095R~
		return 0;
	}
//tab clear                                                        //~v0hJI~
	if (!strcmp(strupr(pc),"CLEAR"))                               //~v0hJI~
    {                                                              //~v50mI~
        if (Ppcw->UCWtype!=UCWTFILE)                               //~v50mI~
        	return errscrtype("tab clear");                        //~v50mI~
	    pfc=Ppcw->UCWpfc;                                          //~v50mI~
  		if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode      //~v50mI~
			return errbrowsemode();                                //~v50mI~
    	return filetabclearall(Ppcw);                              //~v0hJI~
    }                                                              //~v50mI~
                                                                   //~v8@2I~
  if (!strcmp(strupr(pc),"=DEFAULT"))                              //~v8@2R~
  {                                                                //~v8@2I~
    tabctr=0;                                                      //~v8@2R~
  }                                                                //~v8@2I~
  else                                                             //~v8@2I~
  {                                                                //~v8@2I~
	tabctr=atoi(pc);
	if (!ISNUMSTR(pc))
	{
//  	uerrmsg("Specify correct Tab column(Now %d) or ON/OFF",    //~v8@2R~
//  			"正しいタブ桁数(現在は %d) 又は ON/OFF を指定して下さい",//~v8@2R~
//  			Gfiletabskip);                                     //~v8@2R~
//  	return 4;                                                  //~v8@2R~
        return errinvalid(pc);                                     //~v8@2I~
	}
    if (tabctr>TABCTRMAX)                                          //~v0bbR~
	{                                                              //~v0bbI~
		uerrmsg("Max tab column is %d",                            //~v0bbI~
				"タブ桁数の最大は %d",                             //~v0bbI~
				TABCTRMAX);                                        //~v0bbR~
		return 4;                                                  //~v0bbI~
	}                                                              //~v0bbI~
    if (Ppcw->UCWopdno>1)                                          //~v8@2I~
    {                                                              //~v8@2I~
        pc=pc+strlen(pc)+1;                                        //~v8@2I~
		if (strcmp(strupr(pc),"ASDEFAULT"))                        //~v8@2R~
	        return errinvalid(pc);                                 //~v8@2I~
        defaultsw=1;                                               //~v8@2I~
    }                                                              //~v8@2I~
  }                                                                //~v8@2I~
  if (defaultsw)                                                   //~v8@2M~
  {                                                                //~v8@2M~
	if (tabctr==Gfiletabskip)
	{
		uerrmsg("Tab Column is same as pevious value",
				"桁数は前と同じです");
		return 4;
	}
	Gfiletabskip=tabctr;
    Ginifiletabskip=tabctr;                                
//  UCBITON(Gprocstatus,GPROCSINIUPDATE);   //need write ini at term//~v065R~
//  if (fileresettabctr()==UALLOC_FAILED)//reset plh once tabchked //~v8@2R~
    if (fileresettabctr(0,0,tabctr)==UALLOC_FAILED)//reset plh once tabchked//~v8@2R~
    	return UALLOC_FAILED;                                      //~v60jI~
	fileresetfindctr();//reset findctr to reset reverse         //~5223R~
  }                                                                //~v8@2I~
  else                                                             //~v8@2I~
  {                                                                //~v8@2I~
    if (Ppcw->UCWtype!=UCWTFILE)                                   //~v8@2I~
        return errscrtype("tab counter of the file");              //~v8@2I~
	pfc=Ppcw->UCWpfc;                                              //~v8@2I~
    pfh=pfc->UFCpfh;                                               //~v8@2I~
	fcmdprofupdaterecord(FPURO_TABCTR,pfh->UFHfilename,0,tabctr,0);//~v8@2R~
	if (fileresettabctr(0,pfh,tabctr)==UALLOC_FAILED)//reset plh once tabchked//~v8@2R~
    	return UALLOC_FAILED;                                      //~v8@2I~
  }                                                                //~v8@2I~
	scrfulldraw(Ppcw);
	if (tabctr)
      if (defaultsw)                                               //~v8@2I~
		uerrmsg("Default Tab Column was set to %d",                //~v8@2I~
				"省略値タブ桁が %d に変更されました",tabctr);      //~v8@2I~
      else                                                         //~v8@2I~
		uerrmsg("Tab Column was set to %d",
				"タブ桁が %d に変更されました",tabctr);
	else
      if (defaultsw)                                               //~v8@2I~
		uerrmsg("Tab is now inhibit to input",
				"タブ桁入力が禁止になりました");
      else                                                         //~v8@2I~
		uerrmsg("Tabctr was reset to default",                     //~v8@2I~
				"タブ桁が省略値にリセットされました");             //~v8@2I~
	return 0;
}//func_tabctr_file

#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// fcmdcopyoptchk                                                  //~va00I~
//**************************************************************** //~va00I~
int fcmdcopyoptchk(PUCLIENTWE Ppcw,int *Ppcopyopt)                 //~va00I~
{                                                                  //~va00I~
    PUFILEC pfc;                                                   //~va00I~
    PUFILEH pfh;                                                   //~va00I~
    int ii,opdno,copyopt=0;                                        //~va00I~
    UCHAR *pc;                                                     //~va00I~
    UCHAR *pc2;                                                    //~va6cI~
    int opt;                                                       //~va6cI~
    FUNCTBL *pft;                                                  //~va6gI~
    int swpaste;                                                   //~va6gI~
    UFILEH wkufh;                                                  //~va6hI~
    long setflag;                                                  //~va6hI~
    char *pfnm;                                                    //~va6hI~
    int lrecl;                                                     //~va6HI~
    int copysrclrecl;                                              //~va6QI~
    int handle;                                                    //~va7uI~
//*********************************                                //~va00I~
    pft=Ppcw->UCWpfunct;                                           //~va6gI~
    swpaste=(pft->FTfuncid==FUNCID_PASTE);                         //~va6gI~
    pfc=Ppcw->UCWpfc;                                              //~va00I~
    pfh=pfc->UFCpfh;                                               //~va00I~
	pc=Ppcw->UCWopdpot;                                            //~va00I~
	opdno=Ppcw->UCWopdno;                                          //~va00I~
    Scopyoptlrecl=0;                                               //~va6HI~
    if (swpaste)                                                   //~va6gI~
    {                                                              //~va6gI~
		ii=0;                                                      //~va6gI~
        pfnm=CUTCMD_2NDCBFNM;                                      //~va6hI~
    }                                                              //~va6gI~
    else                                                           //~va6gI~
    {                                                              //~va6gI~
        pfnm=pc;                                                   //~va6hI~
		ii=1;                                                      //~va6gI~
		pc+=strlen(pc)+1;                                          //~va6gI~
    }                                                              //~va6gI~
    handle=-1;                                                     //~vajpI~
	if (!fcmdprofgetprofilebyfilename(0,Ppcw,pfnm,&wkufh,&setflag))//~va6hR~
    {                                                              //~va6hI~
		if (UCBITCHK(wkufh.UFHflag10,UFHF10EBC))                //~va50I~//~va6hI~
        {                                                          //~va7uI~
        	copyopt|=FSOC_CPEB;                                    //~va6hI~
            if (setflag & FPURO_CVNAME) //handle was set           //~va7uI~
            {                                                      //~va7uI~
                handle=wkufh.UFHhandle; // handle from profile     //~va7uR~
//              copyopt|=FSOC_EBCHANDLEP|FSOC_SETHANDLE(handle);   //~va7uI~//~vajpR~
            }                                                      //~va7uI~
        }                                                          //~va7uI~
        else                                                       //~va6hI~
	    if (UCBITCHK(wkufh.UFHflag8,UFHF8UTF8))                 //~va50I~//~va57R~//~va6hI~
        	copyopt|=FSOC_CPU8;                                    //~va6hI~
        else                                                       //~va6hI~
//  	if (setflag & FPURO_CP)	//cp                               //~va6hR~
        	copyopt|=FSOC_CPLC;                                    //~va6hI~
	    if (UCBITCHK(wkufh.UFHflag10,UFHF10RECORD))                //~va6kR~
        {                                                          //~va6kI~
    		copyopt|=FSOC_EOL_RECORD;	//read copy source by record mode//~va6kI~
            Scopyoptlrecl=wkufh.UFHlrecl;                          //~va6kR~
        }                                                          //~va6kI~
        else                                                       //~vaj0I~
	    if (UCBITCHK(wkufh.UFHflag13,UFHF13RV))                    //~vaj0I~
        {                                                          //~vaj0I~
    		copyopt|=FSOC_EOL_RECORDV;	//read copy source by recfm=V//~vaj0I~
            Scopyoptlrecl=wkufh.UFHvfmt;                           //~vaj0I~
        }                                                          //~vaj0I~
    }                                                              //~va6hI~
    else                                                           //~va6hI~
        copyopt|=FSOC_CPLC;                                        //~va6hI~
//  for (ii=1;pc+=strlen(pc)+1,ii<opdno;ii++)                      //~va00I~//~va6gI~
    copysrclrecl=0;                                                //~va6QI~
    for (;ii<opdno;ii++,pc+=strlen(pc)+1)                          //~va6gI~
    {                                                              //~va00I~
    	pc2=pc;                                                    //~va6cI~
//      opt=FSOCCO_COPY;                                           //~va6cI~//~va6HR~
        opt=FSOCCO_COPY|FSOCCO_GETLRECL;                           //~va6HI~
       	if (CMDFLAGCHK(*pc,1/*2nd parm*/)) // '-' or 2nd '/'       //~va6cI~
        {                                                          //~va6cI~
        	opt|=FSOCCO_CMDFLAG;                                   //~va6cI~
        	pc2++;                                                 //~va6cI~
        }                                                          //~va6cI~
//  	if (filesaveoptionchkcp(FSOCCO_COPY,Ppcw,pfh,pc,&copyopt)) //~va00R~//~va6cR~
//  	if (filesaveoptionchkcp(opt,Ppcw,pfh,pc2,&copyopt))        //~va6cI~//~va6HR~
		lrecl=0;                                                   //~va6HI~
    	if (filesaveoptionchkcp(opt,Ppcw,pfh,pc2,&copyopt,&lrecl)) //~va6HI~
        	return 4;                                              //~va00R~
        if (lrecl && (copyopt & FSOC_RETLRECL))                    //~va6HI~
        	copysrclrecl=lrecl>>16;    //lrecl+margin             //~va6HR~//~va6QR~
        else                                                       //~vaj0I~
        if (lrecl && (copyopt & FSOC_RETLRECLV))                   //~vaj0I~
        	copysrclrecl=lrecl;    //vfmt                          //~vaj0I~
    }                                                              //~va00I~
    if (copysrclrecl)                                              //~va6QI~
    {                                                              //~va6DI~
		if (copyopt & FSOC_EOL_RECORD)                             //~va6QI~
        	Scopyoptlrecl=copysrclrecl;    //lrecl+margin          //~va6QI~
        else                                                       //~vaj0I~
		if (copyopt & FSOC_EOL_RECORDV)                            //~vaj0I~
        	Scopyoptlrecl=copysrclrecl;    //lrecl+margin          //~vaj0I~
        else                                                       //~va6QI~
        {                                                          //~va6QI~
        	uerrmsg("/F option is for the case copy source is RecordMode",//~va6QI~
            		"/F オプションはコピー元がレコードモードの時に指定");//~va6QI~
            return 4;                                              //~va6QI~
        }                                                          //~va6QI~
    }                                                              //~va6DI~
    if (!(copyopt & FSOC_EBCHANDLEP))	//no cpeb parm             //~vajpI~
    	if (handle>=0)	//from profile                             //~vajpI~
			copyopt|=FSOC_EBCHANDLEP|FSOC_SETHANDLE(handle); //copy source handle//~vajpI~
    *Ppcopyopt=copyopt;                                            //~va00I~
    return 0;                                                      //~va00I~
}//fcmdcopyoptchk                                                  //~va00I~
#endif                                                             //~va00I~
//****************************************************************
// func_copy_file
//*copy command
//*rc   :0
//****************************************************************
int func_copy_file(PUCLIENTWE Ppcw)
{
	int rc;
	UCHAR *pc;                                                  //~v05pI~
    int  opdno;                                                 //~v05pI~
    int movesw;                                                 //~v06hI~
    PUFILEC pfc;                                                //~v06hI~
    PULINEH plh;                                                   //~v09kI~
    FUNCTBL *pft;                                               //~v06hI~
    int setupafter;                                                //~v09kI~
#ifdef UTF8SUPPH                                                   //~va00I~
    PUFILEH pfh;                                                   //~va00I~
    int copyopt=0;                                                 //~va00R~
#endif                                                             //~va00I~
//*********************************
    Scopyopt=0;              //clear for mouse cap paste copy to ::cb//~va5yI~
    pft=Ppcw->UCWpfunct;                                        //~v06hI~
    pfc=Ppcw->UCWpfc;                                           //~v06hM~
    movesw=(pft->FTfuncid==FUNCID_MOVE || pfc->UFCpendfcmd==ULCCMDMOVE);//~v06hR~
    pfc->UFCpendfcmd=0;	//once clear pend cmd                   //~v06hR~
	if (!(pc=Ppcw->UCWparm))                                    //~v05pR~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//  	uerrmsg("COPy/MOVe copy-source-filename [ [%s [%s]] | %s | %s ]",//~va50I~//~va6cR~
//  	uerrmsg("COPy/MOVe copy-source-filename [ [%s [%s]] | %s | %s ] [-S{r|i|d}] ",//~va6cI~//~va6DR~
    	uerrmsg("COPy/MOVe copy-source-filename [ [%s [%s]] | %s | %s ] [/M{T|P|U|M|E|R}] [/Fnn] [-S{r|i|d}] ",//~va6DR~
        		0,                                                 //~va50I~
                MODE_UTF8,MODE_IE,MODE_LOCALE,MODE_EBC);           //~va50I~
    #else                                                          //~va50I~
		uerrmsg("COPy/MOVe copy-source-filename [ [%s [%s]] | %s]",//~va00R~
        		0,                                                 //~va00I~
                MODE_UTF8,MODE_IE,MODE_LOCALE);                    //~va00R~
	#endif                                                         //~va50I~
        return 4;                                                  //~va00I~
#else                                                              //~va00I~
		return errmissing();                                    //~v033I~
#endif                                                             //~va00I~
    }                                                              //~va00I~
	UPARSERC(pc,pc,&opdno,0,",");	//parse out string(accept cr/lf)//~v05pI~
//  if (opdno>1)    //paste has no oprand ,to chk profile     //~v05pI~//~va6hR~
    if (opdno>1    //chk profile even when no option specified     //~va6hR~
    ||  (   opdno==1            //copy ::so by grep cmd,           //~va6hR~
         && (   pft->FTfuncid==FUNCID_PASTE                        //~va6hI~
             || pft->FTfuncid==FUNCID_COPY                         //~va6hI~
             || pft->FTfuncid==FUNCID_MOVE                         //~va6hI~
            )                                                      //~va6hI~
        )                                                          //~va6hI~
    )                                                              //~va6hI~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
        if (fcmdcopyoptchk(Ppcw,&copyopt))  //CPU8 and IE          //~va00R~
            return 4;                                              //~va00I~
#else                                                              //~va00I~
    	return errtoomany();                                    //~v05pI~
#endif                                                             //~va00I~
    }                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
    Scopyopt=copyopt;                                              //~va00I~
#endif                                                             //~va00I~
//  if (!ufullpath(Scopyfilename,Ppcw->UCWparm,_MAX_PATH))//fullpath name//~5610R~
//  if (!filefullpath(Scopyfilename,Ppcw->UCWparm,_MAX_PATH))      //~v13dR~
//  if (!dcmdfullpath(Ppcw,Scopyfilename,Ppcw->UCWparm))           //~v47qR~
	Gsubgblopt|=XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB;	//expand wildcard path//~v47qR~
    rc=(dcmdfullpath(Ppcw,Scopyfilename,Ppcw->UCWparm)!=0);        //~v47qR~
	Gsubgblopt&=~(XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB);//clear for later req//~v47qR~
    if (!rc)                                                       //~v47qR~
		rc=16;                                                  //~5504R~
    else                                                        //~5504I~
    {                                                           //~5504I~
        setupafter=addifline0(Ppcw,pfc,&plh); //add "a"fter cmd if file has no line.//~v09kI~
		fcmdaddslh(Ppcw);		                                   //~v500R~
		Scopyhfile=0;			//for fcmdgetcopyline open      //~5504R~
    	strcpy(Slh.ULHlinecmd,"C");	//sim copy cmd              //~5504R~
		rc=filelinecmd(Ppcw);	//lcmdcopy callback fcmdgetcopyline//~5504R~
        if (setupafter)         //after lcmd added                 //~v09kI~
		    UCBITOFF(plh->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v09kI~
//		delslh(Ppcw);                                           //~v04fR~
                                                                //~5504I~
		if (rc==1)                                              //~5504R~
			uerrmsg("Specify destination",                      //~5504R~
					"複写先を指定して下さい");                  //~5504R~
        else                                                       //~v114I~
			scrclearmsg(Ppcw);                                     //~v114I~
    	if (movesw && pfc->UFCpendfcmd)                         //~v06hR~
			pfc->UFCpendfcmd=ULCCMDMOVE;                        //~v06hR~
	}                                                           //~5504I~
#ifdef UTF8SUPPH                                                   //~va00I~
    pfh=pfc->UFCpfh;                                               //~va00I~
	if (UCBITCHK(pfh->UFHflag10,UFHF10UTF8COPYERR))                //~va00I~
    {                                                              //~va00I~
		UCBITOFF(pfh->UFHflag10,UFHF10UTF8COPYERR);                //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (Scopyopt & FSOC_ERRREPEBC)	// "IE" forced for ebc file//~va50I~
        {                                                          //~va50I~
//      	uerrmsgcat("Translation err on copy source file, try \"F *e\" to search the err line.",//~va50I~//~va6cR~
//          			"複写元で変換エラー, エラー行は \"F *e\" で探せます");//~va50I~//~va6cR~
        	uerrmsgcat("Translation err on copy source file, try \"F *e\" or \"F *ec\" to search the err line.",//~va6cI~
            			"複写元で変換エラー, エラー行は \"F *e\" や \"F *ec\" で探せます");//~va6cI~
        }                                                          //~va50I~
        else                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        if (Scopyopt & FSOC_ERRREP	// "IE" option                 //~va00R~
    	||  UCBITCHK(pfh->UFHflag10,UFHF10UTF8IE)  //copy target was not specified as IE//~va00R~
        )                                                          //~va00I~
	      if (Gutfmode2 & GUM2_KEEPIFCVERR)   //cv err byte is kept untranslated//~va1EI~
        	uerrmsgcat("Copy source contains invalid UTF8 code. Error chars are shown by '%c' (byte code is kept), try \"F *e\" or \"F %s\" to search it.",//~va1ER~//~va1GR~
            			"複写元でUTF8変換エラー、バイトコードはそのまま、'%c' で\x95\\示。\"F *e\" か \"F %s\" で探せます",//~va1ER~//~va1GR~
                         XEUTF_ERRREPCH_F2LFILE,SRCHIDS_UTF8ECH);  //~va1GI~
          else                                                     //~va1EI~
        	uerrmsgcat("Copy source has invalid UTF8 code(replaced to '%c'), try \"F *e\" or \"F %s\" to search it.",//~va00R~//~va1GR~
            			"複写元でUTF8変換エラー('%c'に置換), \"F *e\" か \"F %s\" で探せます",//~va00I~//~va1GR~
                         XEUTF_ERRREPCH_F2LFILE,SRCHIDS_UTF8ECH);                  //~va00I~//~va1GR~
        else                                                       //~va00I~
        {                                                          //~va35I~
        	uerrmsgcat("Copy source has invalid UTF8 code, copy terminated. Use %s option to ignore err",//~va00I~
//          			"複写元でUTF8変換エラー, %s 指定でエラーを無視します",//~va00I~//~va1ER~
            			"複写停止(UTF8変換エラー), %s 指定でエラーを無視します",//~va1EI~
                    MODE_IE);                                      //~va00I~
            rc=4;	//bypass to delete source                      //~va35I~
        }                                                          //~va35I~
    }                                                              //~va00I~
    if (Scopyhfile)	//not yet closed                               //~va35I~
    {                                                              //~va35I~
        Sswclosesource=1;                                          //~va35I~
		fcmdgetcopyline(Ppcw,0/*Ppplh*/);                          //~va35I~
        Sswclosesource=0;                                          //~va35I~
    }                                                              //~va35I~
#endif                                                             //~va00I~
    if (!rc && movesw)                                          //~v06hR~
    	rc=dcmd_xdelete(Ppcw);                                  //~v05sI~
                                                                //~v05sI~
	funcopdpostp(Ppcw,rc);	//operand post process by rc        //~5504I~
    Scopyopt=0;              //clear for mouse cap paste copy to ::cb//~va5yI~
	return rc;
}//func_copy_file
//**************************************************************** //~v783R~
// func_paste_file                                                 //~v783R~
//*rc   :0                                                         //~v783R~
//**************************************************************** //~v783R~
int func_paste_file(PUCLIENTWE Ppcw)                               //~v783R~
{                                                                  //~v783R~
	int rc;                                                        //~v783R~
    char fpath[_MAX_PATH];                                         //~v789I~
    char *pc;                                                      //~va6gI~
    int opdlen,offs;                                               //~va6gI~
//*******************                                              //~v783R~
//  Ppcw->UCWparm=CUTCMD_2NDCBFNM;                                 //~v789R~
    strcpy(fpath,CUTCMD_2NDCBFNM);                                 //~v789I~
	pc=Ppcw->UCWparm;                                              //~va6gI~
    if (pc)   //more opd exist (CPxx,-S)                           //~va6gI~
    {                                                              //~va6gI~
//    	opdlen=strlen(pc);                                         //~va6gI~//~vb2zR~
      	opdlen=(int)strlen(pc);                                    //~vb2zI~
//      offs=strlen(fpath);                                        //~va6gI~//~vb2zR~
        offs=(int)strlen(fpath);                                   //~vb2zI~
        opdlen=min(opdlen,(int)sizeof(fpath)-offs-4);              //~va6gI~
        *(fpath+offs)=' ';                                         //~va6gI~
//      UmemcpyZ(fpath+offs+1,pc,opdlen);                          //~va6gI~//~vb2zR~
        UmemcpyZ(fpath+offs+1,pc,(size_t)opdlen);                  //~vb2zI~
    }                                                              //~va6gI~
    Ppcw->UCWparm=fpath;                                           //~v789I~
	rc=func_copy_file(Ppcw);                                       //~v783R~
	return rc;                                                     //~v783R~
}//func_paste_file                                                 //~v783R~
//**************************************************************** //~v09kI~
// addifline0                                                      //~v09kI~
//*setup "a"fter line cmd if file has no data line                 //~v09kI~
//*parm1:pcw                                                       //~v09kI~
//*parm2:pfc                                                       //~v09kI~
//*parm3:output lcmd setup plh                                     //~v09kI~
//*rc   :0:not set,1:setupped after lcmd                           //~v09kI~
//**************************************************************** //~v09kI~
int addifline0(PUCLIENTWE Ppcw,PUFILEC Ppfc,PULINEH *Ppplh)        //~v09kI~
{                                                                  //~v09kI~
	PUFILEH pfh;                                                   //~v09kI~
	PULINEH plh;                                                   //~v09kI~
//*********************************                                //~v09kI~
	pfh=Ppfc->UFCpfh;                                              //~v09kI~
	*Ppplh=plh=UGETQTOP(&pfh->UFHlineque);                         //~v09kI~
    if (!plh                                                       //~v09kI~
	||   UGETQCTR(&pfh->UFHlineque)>2   //data line exist          //~v09kR~
    ||   pfh->UFHcmdlinectr)	//any lcmd input                   //~v09kI~
    	return 0;                                                  //~v09kI~
	capfcmdi(Ppcw,plh,0);        	//register lcmd                //~v09kI~
    *plh->ULHlinecmd=ULCCMDAFTER;                                  //~v09kI~
    return 1;                                                      //~v09kI~
}//addifline0                                                      //~v09kI~
                                                                   //~v09kI~
//****************************************************************//~5122I~
// fcmdaddslh                                                      //~v500R~
//*add static ULINEH for file lcmd                              //~5122R~
//*parm1:pcw                                                    //~5122I~
//*rc   :cmd lineno except static ULINEH                        //~5122I~
//****************************************************************//~5122I~
int fcmdaddslh(PUCLIENTWE Ppcw)                                    //~v500R~
{                                                               //~5122I~
	PUFILEH pfh;                                                //~v03uI~
	int cmdno;                                                  //~5122R~
//*********************************                             //~5122I~
    Slh.ULHtype=ULHTDMYLCMD;	//dummy lh                      //~5122I~
    Slh.ULHlinenor=0x7fffffff;	//last member for lcmd sort     //~5122I~
	pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                        //~v03uI~
	cmdno=pfh->UFHcmdlinectr;                                   //~v03uR~
	pfh->UFHcmdline[pfh->UFHcmdlinectr++]=&Slh;	//save cmd line //~v03uR~
	UTRACEP("@@@1 %s:add %c cmd,cmdlinectr=%d\n",UTT,*Slh.ULHlinecmd,pfh->UFHcmdlinectr);//~vazvR~
	return cmdno;                                               //~5122I~
}//fcmdaddslh                                                      //~v500R~
                                                                //~5122I~
//****************************************************************//~5122I~
// delslh                                                       //~5122I~
//*del static ULINEH                                            //~5122I~
//*parm1:pcw                                                    //~5122I~
//*rc   :cmd lineno except static ULINEH                        //~5122I~
//****************************************************************//~5122I~
//int delslh(PUCLIENTWE Ppcw)                                   //~v04fR~
//{                                                             //~v04fR~
//	PUFILEH pfh;                                                //~v04fR~
//	int cmdno;                                                  //~v04fR~
//*********************************                             //~5122I~
//	pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                        //~v04fR~
//	cmdno=pfh->UFHcmdlinectr;                                   //~v04fR~
//	if (cmdno &&                                                //~v04fR~
//		pfh->UFHcmdline[cmdno-1]==&Slh)	//save cmd line         //~v04fR~
//		pfh->UFHcmdlinectr=--cmdno;                             //~v04fR~
//	return cmdno;                                               //~v04fR~
//}//delslh                                                     //~v04fR~
                                                                //~5122I~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// fcmdcvf2l                                                       //~va00I~
//*translate utf8 copy source to locale codepage                   //~va00I~
//rc:UALLOC_FAILED,4:f2l err                                       //~va00I~
//**************************************************************** //~va00I~
int fcmdcvf2l(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh)  //~va00I~
{                                                                  //~va00I~
	int rc=0,rc2;                                                  //~va00I~
//**************                                                   //~va00I~
  if (Popt & FCCVF2LO_BIN)    //no translation lcmd option         //~va7xR~
    Scopyopt|=FSOC_BIN;                                            //~va7xR~
  else  //not binary mode                                          //~va7xR~
  {                                                                //~va7xI~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va00R~
      if (!PFH_ISEBC(Ppfh))//target is ebc                         //~va6hI~
    	return 0;                                                  //~va00I~
    if (FILEUTF8MODE(Ppfh))//target is not utf8                    //~va00R~
    {                                                              //~va00I~
		if (Scopyopt & FSOC_CPLC)  //parm cplc                     //~va00R~
	        UCBITON(Pplh->ULHflag5,ULHF5COPYCVL2F); //no conversion//~va00R~
      //else call cvf2lsetdbcs                                     //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(Ppfh))//target is ebc                            //~va50I~
    {                                                              //~va50I~
        Scopyopt|=FSOC_ERRREP|FSOC_ERRREPEBC;  // force errrep     //~va50R~
		if (Scopyopt & FSOC_CPU8)  //parm cpu8                     //~va50I~
	        UCBITON(Pplh->ULHflag5,ULHF5COPYCVF2L); //call cvf2lsetdbcs//~va50I~
        else                                                       //~va50I~
		if (Scopyopt & FSOC_CPLC)  //parm cplc                     //~va50I~
	        UCBITON(Pplh->ULHflag5,ULHF5COPYCVL2F); //no conversion//~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    {                                                              //~va00I~
		if (Scopyopt & FSOC_CPU8)  //parm cpu8                     //~va00R~
	        UCBITON(Pplh->ULHflag5,ULHF5COPYCVF2L); //call cvf2lsetdbcs//~va00I~
      //else call setdbcs                                          //~va00I~
    }                                                              //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	if (Scopyopt & FSOC_CPEB)  //parm cplc                         //~va50R~
    {                                                              //~va50I~
//      Scopyopt=FSOC_ERRREPEBC;  // simple errmsg                 //~va50I~//~va6eR~
        Scopyopt|=FSOC_ERRREPEBC;  // simple errmsg                //~va6eI~
	    UCBITON(Pplh->ULHflag5,ULHF5COPYCVB2); //source is ebcdic  //~va50M~
    }                                                              //~va50I~
  }//not binary mode                                               //~va7xI~
	UCBITON(Pplh->ULHflag5,ULHF5COPYCMD); //source is ebcdic       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
//  rc2=filechktabdbcs(Pplh);   //translate and expand at init for find cmd//~va00R~//~va6cR~
    rc2=filechktabdbcs2(FCTDO_COPYFILE,Scopyopt,Pplh);   //translate and expand at init for find cmd//~va6cI~
    UCBITOFF(Pplh->ULHflag5,ULHF5COPYCVF2L|ULHF5COPYCVL2F); //used //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	UCBITOFF(Pplh->ULHflag5,ULHF5COPYCVB2|ULHF5COPYCMD); //source is ebcdic//~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (rc2==UALLOC_FAILED)                                        //~va00I~
        return rc2;                                                //~va00I~
    if (UCBITCHK(Pplh->ULHflag5,ULHF5LOADCVERR)) //f2l err         //~va00I~
    {                                                              //~va00I~
		UCBITON(Ppfh->UFHflag10,UFHF10UTF8COPYERR);                //~va00I~
    	if (!(Scopyopt & FSOC_ERRREP))	//no "IE" option           //~va00R~
    	if (!UCBITCHK(Ppfh->UFHflag10,UFHF10UTF8IE))  //copy target was not specified as IE//~va00I~
	    if (!(UBITCHKALL(Scopyopt,FSOC_CPEB|FSOC_ERRREPEBC))) //!(b2x and rep ebc err)//~va6cI~
        	rc=4;	//stop copy operation                          //~va00R~
    }                                                              //~va00I~
    return rc;                                                     //~va00I~
}//fcmdcvf2l                                                       //~va00I~
#endif                                                             //~va00I~
//****************************************************************
// fcmdgetcopyline
//*read file record and return plh
//*parm 1:pcw
//*parm 2:plh ptr
//*rc   :0(ok),-1(eof),8(io err)
//****************************************************************
int fcmdgetcopyline(PUCLIENTWE Ppcw,PULINEH* Ppplh)
{
	int rc;                                                     //~5122I~
	FILEFINDBUF3 fstat3;     				//output from DosFindxxxx//~5617I~
    PUFILEC pfc;                                                   //~v09YR~
    PUFILEH pfh;                                                   //~v09YR~
    int readbinsw=0;                                                 //~v09YR~//~vaf9R~
#ifdef UNX                                                         //~v48cI~
    UCHAR  mdosalias[UFHALIASSZ];                                  //~v48cI~
#endif                                                             //~v48cI~
#ifdef FTPSUPP                                                     //~v576I~
	static UCHAR  Stempwdfnm[_MAX_PATH];                           //~v576I~
#endif                                                             //~v576I~
    int binopt;                                                    //~va6kI~
//*********************************                             //~5122I~
    pfc=Ppcw->UCWpfc;                                              //~v09YR~
    pfh=pfc->UFCpfh;                                               //~v09YR~
  if (!Sswclosesource)	//close at err                             //~va35I~
  {                                                                //~va35I~
//#ifdef WXE                                                       //~v64oR~
#ifdef WXEXXE                                                      //~v64oI~
  if ((Gwxestat & GWXES_MOUSECAPPASTE))		//flag for xecap,req callback//~v500I~
    return fcmdgetwincbdata(pfh,Ppplh);	//call wxe                 //~v500I~
#endif                                                             //~v500I~
    readbinsw=(UCBITCHK(pfh->UFHflag3,UFHF3RBIN)!=0)*FILE_OPEN_BIN;//~v0abR~
    if (!Scopyhfile)                                            //~5122I~
	{                                                           //~5122I~
//  	if (rc=filefindopen(Scopyfilename,&fstat3,UFCFBROWSE,&Scopyhfile,FFMSG),rc)//~v09YR~
#ifdef UNX                                                         //~v48cI~
//  	if (rc=filefindopen(Scopyfilename,&fstat3,UFCFBROWSE+readbinsw,&Scopyhfile,FFMSG,mdosalias),rc)//~v576R~
        *Stempwdfnm=0;//req temp local filename for remote file    //~v576I~
    	if (rc=filefindopen(Scopyfilename,&fstat3,UFCFBROWSE+readbinsw,&Scopyhfile,FFMSG,mdosalias,Stempwdfnm),rc)//~v576I~
#else                                                              //~v48cI~
	#ifdef FTPSUPP                                                 //~v576I~
        *Stempwdfnm=0;//req temp local filename for remote file    //~v576I~
    	if (rc=filefindopen(Scopyfilename,&fstat3,UFCFBROWSE+readbinsw,&Scopyhfile,FFMSG,Stempwdfnm),rc)//get localfilename if remote//~v576I~
    #else                                                          //~v576I~
    	if (rc=filefindopen(Scopyfilename,&fstat3,UFCFBROWSE+readbinsw,&Scopyhfile,FFMSG),rc)//~v09YI~
    #endif                                                         //~v576I~
#endif                                                             //~v48cI~
			return rc;		//sim eof                           //~5122I~
		Scopylineno=0;			//for fcmdgetcopyline           //~5122I~
        if (readbinsw)                                             //~v09YI~
        {                                                          //~va6kI~
            binopt=0;                                              //~va6kI~
			if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))//bin if target is bin//~va6kI~
				binopt|=UFGETS_BIN;                                //~va6kI~
        	if (Scopyopt & FSOC_CPU8)                              //~va6kI~
	         	binopt|=UFGETS_UTF8;   //utf8 encoding             //~va6kI~
            else                                                   //~va6kI~
        	if (Scopyopt & FSOC_CPEB)                              //~va6kI~
            {                                                      //~va6DI~
	        	binopt|=UFGETS_EBC;   //ebcdic encoding binchk     //~va6kI~
        		if (!(Scopyopt & FSOC_EOL_NOTEBC))                 //~va6DI~
		        	binopt|=UFGETS_EBCEOL;   //eolid is 0x15       //~va6DI~
            }//allow ebc EOL for not ebc file
            if (Scopyopt & FSOC_EOL_EBC)                           //~va6HI~
            	binopt|=UFGETS_EBCEOL;	//read as ebc file         //~va6HR~
            else                                                   //~va6HI~
        	if (Scopyopt & FSOC_EOL_MAC)                           //~va6HM~
                binopt|=UFGETS_MAC;                                //~va6HM~
            else                                                   //~va6HM~
        	if (Scopyopt & (FSOC_EOL_UNIX|FSOC_EOL_PC))            //~va6HM~
            {                                                      //~va6HM~
        		if (Scopyopt & FSOC_EOL_UNIX)                      //~va6HM~
                	binopt|=UFGETS_UNIX;                           //~va6HM~
        		if (Scopyopt & FSOC_EOL_PC)                        //~va6HM~
                	binopt|=UFGETS_PC;                             //~va6HM~
            }                                                      //~va6HM~
            else                                                   //~va6HM~
            if (Scopyopt & FSOC_EOL_RECORD)                        //~va6kI~
            {                                                      //~va6HI~
            	binopt|=UFGETS_RECORD;	//record mode,split by LRECL//~va6kI~
    			if (!Scopyoptlrecl)	//not by profile               //~va6HI~
    				Scopyoptlrecl=STDSPFLRECL;	//default 80       //~va6HI~
            }                                                      //~va6HI~
            else                                                   //~va6HI~
            if (Scopyopt & FSOC_EOL_RECORDV)                       //~vaj0I~
            {                                                      //~vaj0I~
    			if (!Scopyoptlrecl)	//not by profile               //~vaj0I~
    				Scopyoptlrecl=UFGETS_VFMT_DEFAULT;	//rdw      //~vaj0I~
				binopt|=setufgetsoptVparm2(Scopyoptlrecl);	//f14	//~vaj0I~
            }                                                      //~vaj0I~
            else                                                   //~vaj0I~
            if (UCBITCHK(pfh->UFHflag6,UFHF6RTEXTMAC))             //~va6HI~
                binopt|=UFGETS_MAC;                                //~va6HI~
            else                                                   //~va6HI~
            {                                                      //~va6HI~
            	if (UCBITCHK(pfh->UFHflag3,UFHF3RTEXTPC))          //~va6HI~
                	binopt|=UFGETS_PC;                             //~va6HI~
            	if (UCBITCHK(pfh->UFHflag3,UFHF3RTEXTUNIX))        //~va6HI~
                	binopt|=UFGETS_UNIX;                           //~va6HI~
            }                                                      //~va6HI~
//          ufgetsinit(UFGETS_PC*(UCBITCHK(pfh->UFHflag3,UFHF3RTEXTPC)!=0)//~v09YR~//~va6HR~
            ufgetsinit(                                            //~va6HR~
//  				   +UFGETS_BIN*(UCBITCHK(pfh->UFHflag4,UFHF4BIN)!=0)//bin if target is bin//~v107I~//~va6kR~
//                     +binopt                                     //~va6kR~//~va6HR~
                        binopt,                                    //~va6HI~
//                     +UFGETS_MAC*(UCBITCHK(pfh->UFHflag6,UFHF6RTEXTMAC)!=0)//~v47XI~//~va6HR~
//                     +UFGETS_UNIX*(UCBITCHK(pfh->UFHflag3,UFHF3RTEXTUNIX)!=0),//~v09YR~//~va6HR~
//                     0,0);//	default buffsize,default bin rate  //~v10NR~
                       0,0,0);//default buffsize,default bin rate,no optbin width//~v10NI~
        }                                                          //~va6kI~
	}                                                           //~5122I~
	Scopylineno++;			//for err msg
  }//close at err                                                  //~va35I~
//  if (rc=filegetline(Scopyfilename,Scopyhfile,Scopylineno,Ppplh,readbinsw,pfh),rc==-1)//~v107R~//~va35R~
	rc=0;                                                          //~va35I~
  	if (Sswclosesource	//close at err                             //~va35I~
//  || (rc=filegetline(Scopyfilename,Scopyhfile,Scopylineno,Ppplh,readbinsw,pfh),rc==-1)//~va35I~//~va6kR~
    || (rc=filegetline_copysrc(0,Scopyfilename,Scopyhfile,Scopylineno,Ppplh,readbinsw,pfh,Scopyopt,Scopyoptlrecl),rc==-1)//~va6kI~
    )                                                              //~va35I~
	{                                                           //~5122I~
		fileclose(Scopyfilename,Scopyhfile);                    //~5122I~
    	Scopyhfile=0;                                           //~5122I~
#ifdef FTPSUPP                                                     //~v576I~
    	if (uftpisremote(Scopyfilename,0)) //tempdir created       //~v576I~
		    rc+=xeftpdelwd(0,Stempwdfnm);//del parent (temp)dir    //~v576R~
#endif                                                             //~v576I~
 	}                                                           //~5122I~
	return rc;                                                  //~5122I~
}//fcmdgetcopyline
//#ifdef WXE                                                       //~v64oR~
#ifdef WXEXXE                                                      //~v64oI~
//**************************************************************** //~v500I~
//!fcmdgetwincbdata                                                //~v500I~
//*get windows cb data from wxe                                    //~v500I~
//*rc   :0 or UALLOC_FAILED,-1:eof                                 //~v500I~
//**************************************************************** //~v500I~
int fcmdgetwincbdata(PUFILEH Ppfh,PULINEH *Ppplh)                  //~v500I~
{                                                                  //~v500I~
	PULINEH plh;                                                   //~v500I~
    int  rc,linewidth,len,splitsw,linectr,eolid,lineoffs;          //~v500R~
    char *pc;                                                      //~v500I~
#ifdef UTF8UCS2                                                    //~va20I~
    char *pcds,*pcdt;                                              //~va20I~
#endif                                                             //~va20I~
//*********************                                            //~v500I~
    if (!(linewidth=Ppfh->UFHwidth))                               //~v500I~
        linewidth=MAXLINEDATA;                                     //~v500I~
//  rc=wxe_cappastecallback(linewidth,&pc,0,&len,&splitsw,&linectr,&eolid,&lineoffs);//~v50tR~
#ifdef UTF8UCS2                                                    //~va20I~
    rc=wxe_cappastecallback(Ppfh,linewidth,&pc,&pcds/*return null when locale data*/,&len,&splitsw,&linectr,&eolid,&lineoffs);//~va20R~
#else                                                              //~va20I~
    rc=wxe_cappastecallback(Ppfh,linewidth,&pc,0,&len,&splitsw,&linectr,&eolid,&lineoffs);//~v50tI~
#endif                                                             //~va20I~
    if (rc)                                                        //~v500I~
    	return rc;                                                 //~v500I~
	plh=filealloclh(ULHTDATA,len);                                 //~v500I~
    if (!plh)                                                      //~v500I~
		filelinemallocerr(linectr);                                //~v500R~
    UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage    //~v500I~
	plh->ULHlinenor=linectr;                                       //~v500I~
	plh->ULHoffs=lineoffs;                                         //~v500I~
//  plh->ULHeolid=(UCHAR)eolid;                                    //~v50tR~
    plh->ULHeolidid=(UCHAR)eolid;	//id itself                    //~v50tI~
    plh->ULHeolid=(UCHAR)EOLID2LEN(eolid);                         //~v50tR~
    if (!eolid)                                                    //~v66iI~
		UCBITON(plh->ULHflag4,ULHF4NOEOL);//skip write eol at save //~v66iI~
	memcpy(plh->ULHdata,pc,(UINT)len);                             //~v500I~
#ifdef UTF8UCS2                                                    //~va20I~
	if (pcds)	//clipboard is unicode data                        //~va20I~
    {                                                              //~va20I~
		pcdt=UALLOCM((UINT)(plh->ULHbufflen));	//new dbcs tbl buff//~va20I~
	    UALLOCCHK(pcdt,UALLOC_FAILED);                             //~va20I~
		memcpy(pcdt,pcds,(UINT)len);                               //~va20I~
		plh->ULHdbcs=pcdt;				//new addr                 //~va20R~
    }                                                              //~va20I~
#endif                                                             //~va20I~
	UCBITON(plh->ULHflag2,splitsw);                                //~v500I~
	*Ppplh=plh;                                                    //~v500I~
	return 0;                                                      //~v500I~
}//fcmdgetwincbdata                                                //~v500I~
#endif                                                             //~v500I~

//****************************************************************//~4C29I~
//!func_locate_file                                             //~v04dR~
//*copy command                                                 //~4C29I~
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************//~4C29I~
int func_locate_file(PUCLIENTWE Ppcw)                           //~4C29I~
{                                                               //~4C29I~
	PULINEH plh,plhp,plh0,plh00,plhe;                              //~v116R~
	PUFILEC pfc;                                                //~4C29I~
	PUFILEH pfh;                                                   //~v10WI~
	long lineno=0,linenowk;                                          //~v116R~//~vafcR~
    int destsw;                                                 //~4C29I~
    int rc=0;                                                   //~v04dI~
    UCHAR *pc,*pc2;                                                //~v116R~
//  ULONG offs,offsp=0,prevoffs,elinepos;                            //~v11fR~//~vaz0R~
    FILESZT offs,offsp=0,prevoffs,elinepos;                        //~vaz0I~
    int   pos,width,scrollsz;                                      //~v10WR~
    int   hexsw=0;                                                 //~v10WI~
    int   len;                                                     //~v10ZI~
    int   opdno,cursw=0;                                           //~v116R~
    int   prefixchr;                                               //~v11aI~
    UCHAR labt[2][ULHLINENOSZ+1];                                  //~v69PR~
    PULINEH plht[2];                                               //~v69PI~
    int sortseq[2];                                                //~v69PI~
//*********************************                             //~4C29I~
    pfc=Ppcw->UCWpfc;                                              //~v11aI~
    pfh=pfc->UFCpfh;                                               //~v11aI~
    opdno=Ppcw->UCWopdno;                                          //~v116M~
    pc=Ppcw->UCWopdpot;       //parse out operand                  //~v116I~
//  if (!(pc=Ppcw->UCWparm))		//no operand                   //~v116R~
    if (!opdno)		//no operand                                   //~v116I~
    {                                                              //~v11cI~
//  	return errmissing();                                       //~v11cR~
//  	uerrmsg("L [L | O]xxxx [C] ;  L:lineno,O:Offset,C:by Current Update status",0);//~v69PR~
    	uerrmsg("L { [L|O]xxxx [C] | .label }  ;  L:lineno,O:Offset,C:by Current Update status, .label:you left",0);//~v69PI~
        return 0;                                                  //~v11cI~
    }                                                              //~v11cI~
    if (opdno>2)                                                   //~v116I~
    	return errtoomany();                                       //~v116I~
    else                                                           //~v116I~
      	if (opdno==2)                                              //~v116I~
      	{                                                          //~v116I~
      		pc2=pc+strlen(pc)+1;                                   //~v116I~
      		if (*pc2!='C' && *pc2!='c')                            //~v116I~
        		return errinvalid(pc2);                            //~v116I~
      		cursw=1;                                               //~v116I~
      	}                                                          //~v116I~
    prefixchr=toupper(*pc);                                        //~v11aI~
    switch(prefixchr)                                              //~v11aI~
    {                                                              //~v11aI~
    case 'L':                                                      //~v11aI~
        hexsw=0;                                                   //~v11aI~
        pc++;                                                      //~v11aI~
    	break;                                                     //~v11aI~
    case 'O':                                                      //~v11aI~
        hexsw=1;                                                   //~v11aI~
        pc++;                                                      //~v11aI~
    	break;                                                     //~v11aI~
    case ULCCMDLABEL:                                              //~v69PI~
        len=(int)strlen(pc+1);                                     //~v69PI~
    	if (len>ULHLINENOSZ)                                       //~v69PR~
        {	                                                       //~v69PI~
        	uerrmsg("%s is invalid.(too long label)",              //~v69PI~
                    "%s は行ラベルとして長すぎる",                 //~v69PI~
                     pc);                                          //~v69PI~
            return 4;                                              //~v69PI~
        }                                                          //~v69PI~
        if (len==unumlen(pc+1,0,len))    //all numeric,avoid line search at lcmdgetabplh//~v69PI~
        {                                                          //~v69PI~
        	uerrmsg("%s is invalid(all numeric)",                  //~v69PI~
                    "全桁数字のラベルはLOCateコマンドでは無効(%s)",//~v69PI~
                     pc);                                          //~v69PI~
            return 4;                                              //~v69PI~
        }                                                          //~v69PI~
        strcpy(labt[0],pc);                                        //~v69PR~
    	break;                                                     //~v69PI~
    default:                                                       //~v11aI~
    	hexsw=UCBITCHK(pfh->UFHflag4,UFHF4XLINENO);                //~v11aR~
    }                                                              //~v11aI~
 	if (prefixchr==ULCCMDLABEL)                                    //~v69PI~
 	{                                                              //~v69PI~
		rc=lcmdgetabplh(pfh,1,labt,plht,sortseq);//no paired label //~v69PI~
        switch(rc)                                                 //~v69PI~
        {                                                          //~v69PI~
        case 4://not found                                         //~v69PI~
        	uerrmsg("%s is not found",                             //~v69PI~
                    "%s が見つかりません",                         //~v69PI~
                     pc);                                          //~v69PI~
            return 4;                                              //~v69PI~
//          break;                                                 //~v69PR~
        case 5://duplicated label                                  //~v69PI~
        	uerrmsg("%s is duplicated. This is last of duplcated.",//~v69PR~
                    "%s は重複定義。この行がその最後",             //~v69PR~
                     pc);                                          //~v69PI~
            rc=4;                                                  //~v69PI~
            break;                                                 //~v69PI~
        default:                                                   //~v69PI~
        	rc=0;                                                  //~v69PI~
        }                                                          //~v69PI~
        plh=plht[0];                                               //~v69PI~
		fcmdscrollpage(Ppcw,plh);			//page up/down         //~v69PI~
		filesetcsr(Ppcw,plh,0,0);//csr set to lineno fld           //~v69PI~
        return rc;                                                 //~v69PI~
    }                                                              //~v69PI~
  if (hexsw)                                                       //~v11aI~
  {                                                                //~v11aI~
//   if (ux2l(pc,&offsp))          //hex err                       //~vaz0R~
     if (ux2FILESZ(pc,&offsp))          //hex err                  //~vaz0I~
     	return errinvalid(pc);                                     //~v11aI~
  }                                                                //~v11aI~
  else                                                             //~v11aI~
	if (!ISNUMSTR(pc))		//numeric err                          //~v10WR~
    {                                                              //~v10WI~
//    hexsw=(*pc=='x' || *pc=='X');	//hex notation                 //~v11aR~
//    if (!hexsw					//not hex notation             //~v11aR~
//    || ux2l(pc+1,&offsp))          //hex err                     //~v11aR~
        return errinvalid(pc);                                     //~v10WR~
	}                                                              //~v10WI~
    else                                                           //~v10WI~
    {                                                              //~v116I~
	lineno=atol(pc);                                               //~v10WR~
        if (!lineno)                                               //~v116I~
	        return errinvalid(pc);                                 //~v116I~
    }                                                              //~v116I~
//chk pending cmd                                               //~4C29I~
//  pfc=Ppcw->UCWpfc;                                              //~v11aR~
//  pfh=pfc->UFCpfh;                                               //~v11aR~
	plh=pfc->UFCcurtop;                                         //~4C29I~
	plh00=UGETQTOP(&pfh->UFHlineque);//search from top             //~v116R~
	plh0=UGETQNEXT(plh00);//search from top                        //~v116I~
	plhe=UGETQEND(&pfc->UFCpfh->UFHlineque);//set to top           //~v116I~
//    if (hexsw)                                                   //~v10ZR~
//        if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN))                   //~v10ZR~
//        {                                                        //~v10ZR~
//            uerrmsg("Locate by hex is only for binary file",     //~v10ZR~
//                    "ヘキサ指定の位置付はバイナリーファイルのみ");//~v10ZR~
//            return 4;                                            //~v10ZR~
//        }                                                        //~v10ZR~
	while(plh && plh->ULHtype!=ULHTDATA) //search data line     //~4C29R~
		plh=UGETQNEXT(plh);                                     //~4C29I~
	if (!plh)                           //not found             //~4C29I~
	{                                                           //~4C29I~
		plh=pfc->UFCcurtop;                                     //~4C29I~
		while(plh && plh->ULHtype!=ULHTDATA)//search backward   //~4C29R~
			plh=UGETQPREV(plh);                                 //~4C29I~
		if (!plh)		                                        //~4C30R~
		{                                                       //~4C30R~
			uerrmsg("No data line",                             //~4C30R~
					"データ行がありません");                    //~4C30R~
			return 4;                                           //~4C30R~
		}                                                       //~4C30R~
	}                                                           //~4C30I~
  if (hexsw)                                                       //~v10WI~
  {                                                                //~v10WI~
   if (cursw)               //offset in current update status      //~v116I~
   {                                                               //~v116I~
   	plh=plh0;				//search from top                      //~v116I~
//  offs=(ULONG)pfh->UFHslinepos;                                  //~vaz0R~
    offs=pfh->UFHslinepos;                                         //~vaz0I~
    prevoffs=0;                                                    //~v116I~
    while(plh)              //search forward                       //~v10WI~
    {                                                              //~v10WI~
        if (plh->ULHtype==ULHTDATA)                                //~v10WR~
        {                                                          //~v10WI~
//          offs+=plh->ULHlen;                                     //~v10ZR~
            offs+=plh->ULHlen+plh->ULHeolid;                       //~v50qR~
            if (offs>offsp)	//in this line                         //~v10WI~
            {                                                      //~v116I~
            	if (!prevoffs)                                     //~v116I~
                	plh=plh00;                                     //~v116I~
                else                                               //~v116I~
            		offs=prevoffs;                                 //~v116R~
	            break;                                             //~v10WR~
            }                                                      //~v116I~
            prevoffs=offs;                                         //~v116M~
        }                                                          //~v10WI~
        plh=UGETQNEXT(plh);                                        //~v10WI~
    }                                                              //~v10WI~
    if (!plh)   //after last data line                             //~v116I~
        plh=plhe;                                                  //~v116I~
   }//from current update status                                   //~v116I~
   else	//by offset at read                                        //~v116I~
   {                                                               //~v116I~
	destsw=0;                                                      //~v116I~
    offs=plh->ULHoffs;		//current offs                         //~v116I~
    if (!offs)				//(inserted line or 1st line)          //~v116I~
    	plh=plh0;   		//from top                             //~v116R~
    else                                                           //~v116I~
    {                                                              //~v54dI~
		if (offsp<=offs)                                           //~v116I~
        {                                                          //~v54dI~
			if (offsp<(offs>>1))	//middle of prev part          //~v116R~
				plh=plh0;			//search from top              //~v116I~
			else                                                   //~v116I~
	        	destsw=1;			//backword search from curtop  //~v116I~
        }                                                          //~v54dI~
    }                                                              //~v54dI~
	if (destsw)	            //back from current plh                //~v116I~
	{                                                              //~v116I~
		while(plh)              //search backward                  //~v116I~
    	{                                                          //~v116I~
			if (plh->ULHtype==ULHTDATA)                            //~v116I~
            {                                                      //~v116I~
				offs=plh->ULHoffs;                                 //~v116I~
                if (offs)       //initial line                     //~v116I~
                {                                                  //~v116I~
					if (offsp>=offs)                               //~v116I~
                    	break;                                     //~v116I~
				}                                                  //~v116I~
                else    		//may inserted                     //~v116I~
            		if (!UCBITCHK(plh->ULHflag,ULHFMOVE) && !UCBITCHK(plh->ULHflag2,ULHF2INSERT))//~v116R~
                    	break;		//initial offset 0             //~v116I~
			}                                                      //~v116I~
			plh=UGETQPREV(plh);                                    //~v116I~
		}                                                          //~v116I~
        if (!plh)                                                  //~v116I~
        	plh=plh00;                                             //~v116I~
	}//backward search                                             //~v116I~
	else	//forward search                                       //~v116I~
	{                                                              //~v116I~
    	plhp=0;                                                    //~v116I~
		while(plh)				//search forward                   //~v116I~
    	{                                                          //~v116I~
			if (plh->ULHtype==ULHTDATA)                            //~v116I~
            {                                                      //~v116I~
				offs=plh->ULHoffs;                                 //~v116I~
                if (offs)       //initial line                     //~v116I~
                {                                                  //~v116I~
					if (offsp==offs)                               //~v116R~
                    	break;                                     //~v116I~
                    else                                           //~v116I~
						if (offsp<offs)                            //~v116I~
                    	{                                          //~v116I~
                            if (!plhp)                             //~v116I~
                                plh=plh00;                         //~v116I~
                            else                                   //~v116I~
                            {                                      //~v116I~
                        		plh=plhp;	//prev line            //~v116R~
        						offs=plh->ULHoffs;                 //~v116R~
							}                                      //~v116I~
                    		break;                                 //~v116I~
                    	}                                          //~v116I~
                    plhp=plh;	//prev line                        //~v116I~
				}                                                  //~v116I~
                else    		//may inserted                     //~v116I~
            		if (!UCBITCHK(plh->ULHflag,ULHFMOVE) && !UCBITCHK(plh->ULHflag2,ULHF2INSERT))//~v116R~
                    	plhp=plh;                                  //~v116I~
			}                                                      //~v116I~
			plh=UGETQNEXT(plh);                                    //~v116I~
		}                                                          //~v116I~
        if (!plh)                                                  //~v116I~
        {                                                          //~v54dI~
//          if (plhp && offsp<(ULONG)pfh->UFHelinepos)             //~v11fR~
//          	plh=plhp;                                          //~v11fR~
            if (plhp)                                              //~v11fI~
            {                                                      //~v11fI~
//  			if (!(elinepos=(ULONG)pfh->UFHelinepos))           //~vaz0R~
    			if (!(elinepos=pfh->UFHelinepos))                  //~vaz0I~
//              	elinepos=pfh->UFHsize;                         //~v50qR~
                	elinepos=plhp->ULHoffs+plhp->ULHlen+plhp->ULHeolid;//~v50qR~
				if (offsp<elinepos)                                //~v11fR~
            		plh=plhp;                                      //~v11fI~
                else                                               //~v11fI~
        			plh=plhe;                                      //~v11fI~
			}                                                      //~v11fI~
            else                                                   //~v116I~
        		plh=plhe;                                          //~v116R~
            if (plh==plhe)                                         //~vazvR~
            {                                                      //~vazvR~
    			if (pfh->UFHupctr)	//same as saved                //~vazvR~
					uerrmsg("Use \"C\" option like as \"L xxxx C\" to locate by updated lines status.\n",//~vazvR~
					        "更新後の状態での位置付けは \"L xxxx C\" のように \"C\" を指定する");//~vazvR~
            }                                                      //~vazvR~
        }                                                          //~v54dI~
	}//by dest                                                     //~v116I~
   }//by offset at read                                            //~v116I~
//    if (!plh)                                                    //~v116R~
//    {                                                            //~v116R~
//        uerrmsg("EOF pos is %08X",                               //~v116R~
//                "EOF位置は%08X",                                 //~v116R~
//                offs);                                           //~v116R~
//        return 4;                                                //~v116R~
//    }                                                            //~v116R~
//set csr and scroll left/right if requred                         //~v10WI~
	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                     //~v10WI~
    {                                                              //~v10WI~
		rc=lcmdincm(Ppcw,plh);	//display excluded line            //~v10WI~
//  	pfc->UFCcurtop=plh;                                        //~v54FR~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                           //~v10WI~
    }                                                              //~v10WI~
//  else                                                           //~v54FR~
		fcmdscrollpage(Ppcw,plh);			//page up/down         //~v10WI~
                                                                   //~v116I~
   if (plh->ULHtype==ULHTDATA)                                     //~v116I~
   {                                                               //~v116I~
//  pos=(int)(plh->ULHlen-(offs-offsp));    //locate pos           //~v10ZR~
    len=plh->ULHlen;                                               //~v10ZI~
//  pos=(int)(len+plh->ULHeolid-(offs-offsp));    //locate pos     //~v116R~
    pos=(int)(offsp-offs);    //locate pos                         //~v116R~
    if (pos>len)                                                   //~v10ZI~
        pos=len;                                                   //~v10ZI~
	width=Ppcw->UCWwidth-Ppcw->UCWlinenosz;                        //~v10WI~
	if (pos<pfc->UFCleft                                           //~v10WI~
	|| 	pos>=pfc->UFCleft+width)                                   //~v10WI~
	{                                                              //~v10WI~
        scrollsz=filehalfhscrollsz(Ppcw);//half scroll size        //~v10WI~
		pfc->UFCleft=max(0,(pos/scrollsz)*scrollsz-scrollsz);      //~v10WI~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                           //~v10WI~
    }                                                              //~v10WI~
	filesetcsr(Ppcw,plh,1,pos-pfc->UFCleft);//csr set              //~v10WI~
   }//dataline                                                     //~v116I~
   else                                                            //~v116I~
	filesetcsr(Ppcw,plh,0,0);//csr set                             //~v116I~
//excluded line display                                            //~v10WI~
  }     //hexsw                                                    //~v10WI~
//**********  by lineno **************                             //~v116I~
  else	//by decimal                                               //~v10WI~
  {                                                                //~v10WI~
   if (cursw)               //offset in current update status      //~v116I~
   {                                                               //~v116I~
   	plh=plh0;				//search from top                      //~v116I~
    linenowk=pfh->UFHsline;                                        //~v116R~
    if (!linenowk)          //inserted line                        //~v116I~
    	linenowk=1;	                                               //~v116I~
    while(plh)              //search forward                       //~v116I~
    {                                                              //~v116I~
        if (plh->ULHtype==ULHTDATA)                                //~v116I~
        {                                                          //~v116I~
        	if (lineno<linenowk)                                   //~v116I~
            {                                                      //~v116I~
            	plh=plh00;                                         //~v116I~
                break;                                             //~v116I~
			}                                                      //~v116I~
            else                                                   //~v116I~
            	if (lineno==linenowk)	//in this line             //~v116R~
	            	break;                                         //~v116R~
            linenowk++;                                            //~v116I~
        }                                                          //~v116I~
        plh=UGETQNEXT(plh);                                        //~v116I~
    }                                                              //~v116I~
    if (!plh)   //after last data line                             //~v116I~
        plh=plhe;                                                  //~v116R~
   }//from current update status                                   //~v116I~
   else	//by offset at read                                        //~v116I~
   {                                                               //~v116I~
    destsw=0;                                                   //~4C30I~
//  if (lineno<plh->ULHlinenor)                                    //~v0ahR~
    if (lineno<=plh->ULHlinenor)                                   //~v0ahI~
    {                                                              //~v54dI~
		if (lineno<plh->ULHlinenor/2)                           //~4C30R~
//  		plh=UGETQTOP(&pfc->UFCpfh->UFHlineque);//search from top//~v116R~
    		plh=plh0;                                              //~v116I~
		else                                                    //~4C30I~
	        destsw=1;		//backword search                   //~4C30R~
    }                                                              //~v54dI~
	if (destsw)	            //back from current plh             //~4C30R~
	{                                                           //~4C29I~
		plhp=0;                                                 //~4C29I~
		while(plh)              //search backward               //~4C29I~
    	{                                                       //~4C29I~
			if (plh->ULHtype==ULHTDATA && lineno>=plh->ULHlinenor)//~4C29I~
			{                                                   //~4C29I~
				if (lineno>plh->ULHlinenor)                     //~4C29I~
					break;                                      //~4C29I~
				plhp=plh;                                       //~4C29I~
			}                                                   //~4C29I~
			plh=UGETQPREV(plh);                                 //~4C29R~
		}                                                       //~4C29I~
		if (plhp)   	//once founf                            //~4C29I~
			plh=plhp;                                           //~4C29I~
        else                                                    //~4C29I~
            if (!plh)   //before first data line                //~4C29I~
//  			plh=UGETQTOP(&pfc->UFCpfh->UFHlineque);//set to top//~v116R~
    			plh=plh00;                                         //~v116I~
	}//backward search                                          //~4C29I~
	else                                                        //~4C29I~
	{                                                           //~4C29I~
		plhp=0;                 //initialize required              //~v58kI~
		while(plh)				//search forward                //~4C29R~
    	{                                                       //~4C29I~
			if (plh->ULHtype==ULHTDATA && lineno<=plh->ULHlinenor)//~4C29I~
			{                                                   //~4C29I~
				if (lineno<plh->ULHlinenor)                     //~4C29I~
                {                                                  //~v116I~
					plh=plhp;                                   //~4C29R~
                    if (!plh)                                      //~v116I~
                        plh=plh00;  //top hdr                      //~v116I~
                }                                                  //~v116I~
				break;                                          //~4C29I~
			}                                                   //~4C29I~
			plhp=plh;                                           //~4C29I~
			plh=UGETQNEXT(plh);                                 //~4C29R~
		}                                                       //~4C29I~
        if (!plh)   //after last data line                      //~4C29I~
//  		plh=UGETQPREV(UGETQEND(&pfc->UFCpfh->UFHlineque));//set to top//~v116R~
    		plh=plhe;                                              //~v116I~
	}                                                           //~4C29I~
   }//by current or initial lineno                                 //~v116I~
                                                                //~4C29I~
	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                  //~4C29I~
		rc=lcmdincm(Ppcw,plh);	//display excluded line         //~v04dR~
//  pfc->UFCcurtop=plh;                                            //~v116R~
//excluded line display                                         //~4C29I~
//  UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v116R~
	fcmdscrollpage(Ppcw,plh);			//page up/down             //~v116I~
	filesetcsr(Ppcw,plh,0,0);//csr set to lineno fld               //~v116R~
  }//by decimal                                                    //~v10WM~
	return rc;                                                  //~v04dR~
}//func_locate_file                                             //~4C29I~
                                                                //~4C29I~
