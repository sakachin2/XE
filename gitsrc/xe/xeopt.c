//*CID://+vb2tR~:                             update#=  244;       //~vb2tR~
//*************************************************************
//*xeopt.c
//* option cmd
//*************************************************************
//vb2t:160206 (LNX)err msg for "opt lfn"                           //~vb2tI~
//vb27:160115 (BUG)Gotheropt is ULONG,it should be used ULBITON/OFF/CHK//~vb27I~
//van9:131202 Issue warning to recover RCTL enter off-->on(if on "opt rctl ON" could not be enter)//~van9I~
//van1:131127 (BUG)undelete off cmd result english msgs is not "off" but "on"//~van1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va47:100401 va46 for LNX                                         //~va47I~
//va3s:100219 simple split mode like as windows. single write combining char when split mode.//~va3sI~
//            visibility depends to curses. user select split or combine mode.//~va3sI~
//            shadow is another option by opt cmd                  //~va3sI~
//va06:090628 (BUG:LNX)correct help msg of OPT cmd(add [KEEP])     //~va06I~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v78N:080521 (LNXCON)rctl support                                 //~v78NI~
//v78t:080327*CAP on abend on dirlist panel                        //~v78tI~
//v78r:080326 profile function                                     //~v78rI~
//v77v:080117*xuerpchk(uerrmsg parameter chk)                      //~v77vI~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v736:070106*opt cmd help msg correct                             //~v736I~
//v72N:061214 CAPS:cmdline caps option "cap on/off cmd" to set caps optio to same as file contents option//~v72NI~
//v71L:061104 CAP option save and apply as default or apply TSO only//~v71LI~
//v70m:060811 (!LNX Cons)change graph key input by Shift key not by opt linech on/off//~v70mI~
//            (For LNX console:if opt linech on,use 1st and acssetup if that is 1 byte,if off use 2nd)//~v70mI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69N:060713 (BUG)opt cmdlog,opt rettol coding err(already off not chked)//~v69NI~
//v69M:060713 (LNX)Change line drawing char effectiveness to optional. OPT LINECHAR [on|off]//~v69MI~
//                 (no code in iso8859 but in old IBM-PC Extended Char Set(ECS) only)//~v69MI~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v678:051227 opt option "RETTOL":return to top of line by return key//~v678I~
//v64t:050704 (XXE)xxe support;RCTL support                        //~v64tI~
//v645:050617 OPT DELZ ON/OFF;option to prohibit dlcmd z/0;default is on//~v645R~
//v62G:050412 cmdlog function                                      //~v62GI~
//v62m:050321 opt und cmd;chng help msg(add keep option)           //~v62mI~
//v619:050212 change cont-line termibnater 0x1f-->"-"              //~v619I~
//v60m:050129 display different id from eolid for contline terminater.//~v60mI~
//v59X:041211 (BUG)uerrmsg support max 10 parameter                //~v59XI~
//v584:040823 cap option not to copy to ::cb when cap-delete for performance up for large file//~v584I~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v54T:040125 RESET option for opt 7bit                            //~v54SI~
//v54S:040125 add opt cmd:beep on/off                              //~v54SI~
//v51D:030719 (LNX)RedHat9 <0x20 is not displayed normaly          //~v51DI~
//v500:020928 (WXE)Font:Terminal(app932.fon) allow same unprintable char for ctl char//~v500I~
//v500:020827 wxe support                                          //~v500I~
//     020923 eolid                                                //~v500I~
//v47N:020330 (UNX)mdos is option;set on of by opt dos cmd         //~v47NI~
//v47d:020223 opt eol char on/off;end of line char and attr specification cmd//~v47dI~
//v44q:011205 help msg                                             //~v44qI~
//v44m:011204 option of upper/lower hex code display               //~v44mI~
//v43z:011124 7bit dump mode initial value is on for AIX           //~v43zI~
//v43y:011122 7bit dump mode                                       //~v43yI~
//v10j:990320 display current option before errchk for opt LFN cmd //~v10jI~
//v0jc:980721 W95-->WIN                                            //~v0jcI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0fw:971116 (GCC:BUG)need force chk use_lfn when change env var LFN//~v0fwI~
//                     change n to y                               //~v0fwI~
//v0f0:971010 long filename support                                //~v0f0I~
//            win95 alias dir list option(OPT LFN cmd)             //~v0f0R~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v095:970405:DPMI version                                         //~v095I~
//            -structure init type chk(0 for char arry is err)     //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//v05B:960104:Option commnad
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#ifdef W32                                                         //~vb2tI~
    #include <windows.h>                                           //~vb2tI~
#endif                                                             //~vb2tI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile3.h>
#include <ufile4.h> 	//ufileisvfat                              //~v0f0I~
#include <uparse.h>                                                //~v0b2R~
#include <udbcschk.h>                                              //~vb2tI~
#define UVIOMDEFONLY	//for uviom.h                              //+vb2tI~
#include <uviom.h>                                                 //~vb2tI~

#include "xe.h"
#include "xescr.h"
#include "xefunc.h"
#include "xeerr.h"
#include "xegbl.h"                                                 //~v47dI~
#include "xekbd.h"                                                 //~v55cI~
#include "xefunc2.h"                                               //~v62GI~
#include "xefile.h"                                                //~v69JI~
#include "xesub.h"                                                 //~v74xM~
#include "xefunct.h"                                               //~v705I~
#include "xefcmd6.h"                                               //~v78rI~
#include "xeutf.h"                                                 //~vb2tI~
#define XEOPT_GLOBAL        //create extern symbol                 //~v768M~
#include "xeopt.h"                                                 //~v768M~
//****************************************************************
#define CONTINS "INS_LINE"                                         //~v78SI~
#define OPTCOMB "COMBINE"                                          //~va3sI~
//****************************************************************
static UOPTWTBL  Soptwtbl[]=
{
	{"UND"    ,opt_undel,	0,1,0,0},                              //~v43yR~
//#ifdef UNX                                                         //~v678I~//~vb2tR~
//    {"???"    ,0        ,   0,1,0,0},                              //~v678I~//~vb2tR~
//#else                                                              //~v678I~//~vb2tR~
	{"LFN"    ,opt_fat  ,	0,1,0,0},                              //~v43yR~
//#endif                                                             //~v678I~//~vb2tR~
#ifdef UNX                                                         //~v678I~
	{"???"    ,0         ,	0,1,0,0},                              //~v678I~
#else                                                              //~v678I~
	{"PLFN"   ,opt_pfat  ,	0,1,0,0},                              //~v43yR~
#endif                                                             //~v678I~
	{"ASCII"  ,opt_7bit  ,	0,1,0,0},                              //~v43yR~
	{"HEX"    ,opt_hex   ,	0,1,0,0},                              //~v44mI~
	{"EOL"    ,opt_eol   ,	0,2,0,0},//verb,min opdno,max opdno,flag//~v47dR~
#ifdef UNX                                                         //~v47NI~
	{"FD"     ,opt_fd    ,	0,1,0,0},                              //~v47NI~
#else                                                              //~v55cI~
//  {"RCTL"   ,opt_rctl  ,	0,1,0,0},   //no6                      //~v678R~
    {"???"    ,0         ,	0,1,0,0},   //no6                      //~v678I~
#endif                                                             //~v47NI~
	{"BEEP"   ,opt_beep  ,	0,1,0,0},                              //~v54SM~
	{"CCFUNC" ,opt_ccfunc,	0,1,0,0},                              //~v55jR~
	{"FREECSR",opt_freecsr,	0,1,0,0},                              //~v55qI~
	{"CBSAVE" ,opt_cbcopy ,	0,1,0,0},   //#10                      //~v584R~
	{"FOLD"   ,opt_eolcont, 0,2,0,0},   //#11                      //~v60mR~
	{"CMDLOG" ,opt_cmdlog , 0,1,0,0},   //#12                      //~v62GI~
	{"DELZ"   ,opt_delz   , 0,1,0,0},   //#13                      //~v645I~
#ifdef UNX                                                         //~v678I~
  #ifdef XXE                                                       //~v678R~
	{"RCTL"   ,opt_rctl  ,	0,1,0,0},   //#14                      //~v64tI~
  #else                                                            //~v678I~
//	{"???"    ,0         ,	0,1,0,0},   //#14                      //~v768R~
	{"RCTL"   ,opt_rctl  ,	0,1,0,0},   //#14                      //~v768I~
  #endif                                                           //~v678R~
#else                                                              //~v678I~
	{"RCTL"   ,opt_rctl  ,	0,1,0,0},   //#14                      //~v678I~
#endif                                                             //~v678I~
	{"RETTOL" ,opt_rettol , 0,1,0,0},   //#15                      //~v678I~
//#if defined(LNX) && !defined(XXE)                                //~v69XR~
//#ifdef LNX                                                       //~v705R~
	{"LINECH" ,opt_acs   ,	0,1,0,0},   //#16                      //~v69NR~
//#else                                                            //~v705R~
//    {"???"    ,0         ,	0,1,0,0},   //no#16                //~v705R~
//#endif                                                           //~v705R~
//    0		//stopper                                              //~v095R~
    {"???"    ,0         ,	0,1,0,0},   //#17 for opt_mode(UTF)    //~v78SI~
	{CONTINS ,opt_contins, 0,1,0,0},   //#18                       //~v78SR~
	{OPTCMD_COMBINE  ,opt_combine, 0,2,0,0},   //#19               //~va3sR~
	{OPTCMD_LIGATURE ,opt_ligature, 0,1,0,0},   //#20              //~va3sI~
      {"",0,0,0,0,0}		//stopper                              //~v43yR~
};
#if !defined(W32) && !defined(DPMI)                                //~v0g1I~
	int opterrwinonly(void);                                       //~v0jcI~
#else                                                              //~v0g1I~
#endif                                                             //~v43yM~
    static UCHAR *Swordtblfat="OFF\0ON\0";                         //~v0g1I~
#define STR_OFF  Swordtblfat                                       //~v47NI~
#define STR_ON   (Swordtblfat+4)                                   //~v47NI~
#define STR_RESET  "RESET"                                         //~v54SI~
                                                                   //~v60mI~
static int Sssweolcont=0;                                          //~v60mI~
//**************************************************************** //~v44qI~
//int optoffonchk(char *Pparm,int Popt);                           //~va3sR~
//#define OPTOFC_ERRMSG    0x01                                    //~va3sR~
//#define OPTOFC_RESETCHK  0x02                                    //~va3sR~
int opthelp(void);                                                 //~v44qI~
//****************************************************************
//!func_opt
//* option commnad
//*parm1:pcw(UCWparm:operand)
//*retrn:rc
//****************************************************************
int func_opt(PUCLIENTWE Ppcw)
{
//********************

	UCHAR *popd=0,*pcmd;                                           //~vaf9R~
	UOPTWTBL *pot;
	int cmdlen=0,opdno;                                            //~vaf9R~
//************************************
	if (pcmd=Ppcw->UCWparm,pcmd)
    {                                                              //~v54SI~
		if (popd=strpbrk(pcmd," ,"),popd)		//search delm
		{
//			cmdlen=(int)((ULONG)popd-(ULONG)pcmd);	//option id len//~vafkR~
			cmdlen=(int)((ULPTR)popd-(ULPTR)pcmd);	//option id len//~vafkI~
			*popd++=0;					//cut out option id
			popd+=strspn(popd," ");		//search non space,opd pos
		}
    	else
    		cmdlen=(int)strlen(pcmd);
    }//                                                            //~v54SI~
	if (!pcmd || !cmdlen)
//  	return errmissing();                                       //~v44qR~
    	return opthelp();                                          //~v44qI~

//*search func table by cmd string ***
	for (pot=Soptwtbl;*pot->UOWcmd;pot++)	//all dcnd entry
		if (!memicmp(pcmd,pot->UOWcmd,3))
			break;

	if (!*pot->UOWcmd)		//not found
		return errinvalid(pcmd);
	if (!pot->UOWfunc)   	//not found                            //~v678I~
		return errinvalid(pcmd);                                   //~v678I~

//*operand chk
	if (popd)
    {
		UPARSERC(popd,popd,&opdno,0,",");	//parse out string(accept cr/lf)
	}
	else
    	opdno=0;
 	if (opdno < pot->UOWminopd)	//operand needed
		return errmissing();
 	if (opdno > pot->UOWmaxopd)	//operand needed
		return errtoomany();

//*operand chk
	Ppcw->UCWparm=popd;		//parsed operand
	return pot->UOWfunc(Ppcw,pot,opdno);
}//func_dos

//****************************************************************
//!opt_undel
//* delete option set
//*parm1:pcw(UCWparm:operand)
//*retrn:rc
//****************************************************************
int opt_undel(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)
{
    int opid,ii;
    UCHAR *pc;
static UCHAR *Swordtbl="OFF\0ON\0KEEP\0";
//*********************************
	if (!(pc=Ppcw->UCWparm))
    {
    	opid=(Gopt3 & (GOPT3UNDELFREE|GOPT3UNDELLEAVE))/GOPT3UNDELFREE;//~v064R~
        for (ii=0,pc=Swordtbl;ii<opid;ii++)
        	pc+=strlen(pc)+1;
		uerrmsg("Current Undelete option is %s.",
				"現在のUndeleteオプションは %s です",
				pc);
		return 0;
    }
	switch(opid=wordtblisrch(pc,Swordtbl),opid)
    {
	case 0:	//err
        return errinvalid(pc);
	case 1:	//off
    	if (!UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))
            return erralready();
    	UCBITOFF(Gopt3,   GOPT3UNDELFREE|GOPT3UNDELLEAVE);
//  	UCBITOFF(Giniopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE);      //~v064R~
//		uerrmsg("Delete is now undeletable",                       //~van1R~
  		uerrmsg("Delete is now not undeletable",                   //~van1I~
				"以降のDeleteはUndelete出来ません");
        break;
	case 2:	//on
    	if (UCBITCHK(Gopt3,GOPT3UNDELFREE))
            return erralready();
    	UCBITON (Gopt3,   GOPT3UNDELFREE);
//  	UCBITON (Giniopt3,GOPT3UNDELFREE);                      //~v064R~
    	UCBITOFF(Gopt3,   GOPT3UNDELLEAVE);
//  	UCBITOFF(Giniopt3,GOPT3UNDELLEAVE);                     //~v064R~
		uerrmsg("Now Undelete available(not Keep mode)",
//				"Undeleteが使用可能になりました(非保存モード)");   //~v07sR~
  				"Undeleteが使用可\x94\\になりました(非保存モード)");//~v07sI~
        break;
	case 3:	//keep
    	if (UCBITCHK(Gopt3,GOPT3UNDELLEAVE))
            return erralready();
    	UCBITOFF(Gopt3,   GOPT3UNDELFREE);
//  	UCBITOFF(Giniopt3,GOPT3UNDELFREE);                      //~v064R~
    	UCBITON (Gopt3,   GOPT3UNDELLEAVE);
//  	UCBITON (Giniopt3,GOPT3UNDELLEAVE);                     //~v064R~
		uerrmsg("Now Undelete available(Keep mode)",
//				"Undeleteが使用可能になりました(保存モード)");     //~v07sR~
  				"Undeleteが使用可\x94\\になりました(保存モード)"); //~v07sI~
        break;
	}//opd

//  UCBITON(Gprocstatus,GPROCSINIUPDATE);   //need write ini at term//~v065R~
	return 0;
}//opt_undel
                                                                   //~v0f0I~
//**************************************************************** //~v645I~
//!opt_undel                                                       //~v645I~
//* delete option set                                              //~v645I~
//*parm1:pcw(UCWparm:operand)                                      //~v645I~
//*retrn:rc                                                        //~v645I~
//**************************************************************** //~v645I~
int opt_delz(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v645I~
{                                                                  //~v645I~
    int opid;                                                      //~v645R~
    UCHAR *pc;                                                     //~v645I~
static UCHAR *Swordtbl="OFF\0ON\0";                                //~v645R~
//*********************************                                //~v645I~
	if (!(pc=Ppcw->UCWparm))                                       //~v645I~
    {                             //off                            //~v645I~
        pc=Swordtbl;                                               //~v645I~
    	if (!(Gopt5 & GOPT5DLCZOFF))                               //~v645I~
        	pc+=strlen(pc)+1;	//on                               //~v645I~
		uerrmsg("Current z/0 line cmd avail option is %s.",        //~v645I~
				"現在の z/0 行コマンド使用オプションは %s です",   //~v645I~
				pc);                                               //~v645I~
		return 0;                                                  //~v645I~
    }                                                              //~v645I~
	switch(opid=wordtblisrch(pc,Swordtbl),opid)                    //~v645I~
    {                                                              //~v645I~
	case 0:	//err                                                  //~v645I~
        return errinvalid(pc);                                     //~v645I~
	case 1:	//off                                                  //~v645I~
    	if (UCBITCHK(Gopt5,GOPT5DLCZOFF))                          //~v645R~
            return erralready();                                   //~v645I~
    	UCBITON(Gopt5,GOPT5DLCZOFF);    //set off                  //~v645R~
		uerrmsg("line cmd z/0 is not available now",               //~v645I~
				"以降の行コマンド z/0 は使用出来ません");          //~v645I~
        break;                                                     //~v645I~
	case 2:	//on                                                   //~v645I~
    	if (!UCBITCHK(Gopt5,GOPT5DLCZOFF))  //not off/conf         //~v645R~
            return erralready();                                   //~v645I~
    	UCBITOFF(Gopt5,GOPT5DLCZOFF);  //reset conf                //~v645R~
		uerrmsg("line cmd z/0 is available now",                   //~v645R~
				"以降の行コマンド z/0 は使用可\x94\\です");        //~v645R~
        break;                                                     //~v645I~
	}//opd                                                         //~v645I~
	return 0;                                                      //~v645I~
}//opt_delz                                                        //~v645I~
                                                                   //~v645I~
//**************************************************************** //~v0f0I~
//!opt_fat                                                         //~v0f0I~
//* win95 dir list vy 8.3 filename(alias)                          //~v0f0I~
//*parm1:pcw(UCWparm:operand)                                      //~v0f0I~
//*parm2:pot                                                       //~v0f0I~
//*parm3:opd no                                                    //~v0f0I~
//*retrn:rc                                                        //~v0f0I~
//**************************************************************** //~v0f0I~
int opt_fat(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)             //~v0f0I~
{                                                                  //~v0f0I~
#if !defined(W32) && !defined(DPMI)                                //~v0f0I~
#else                                                              //~v0f0I~
//  static UCHAR *Swordtblfat="OFF\0ON\0";                         //~v0g1R~
    int opid;                                                      //~v0f0R~
    UCHAR *pc;                                                     //~v0f0I~
#endif                                                             //~v0f0I~
//*********************************                                //~v0f0I~
#if !defined(W32) && !defined(DPMI)                                //~v0f0I~
//  uerrmsg("Avail under Window95 only",                           //~v0jcR~
//  		"Windows95でのみ有効です");                            //~v0jcR~
//  return 4;                                                      //~v0jcR~
    return opterrwinonly();                                        //~v0jcI~
#else                                                              //~v0f0I~
//  if (!ufileisvfat(ISVFAT_ERRMSG))	//err msg if not vfat	   //~v10jR~
//  	return 4;                                                  //~v10jR~
	if (!(pc=Ppcw->UCWparm))                                       //~v0f0I~
    {                                                              //~v0f0I~
        pc=Swordtblfat;                                            //~v0f0R~
    	if (!UCBITCHK(Gopt3,GOPT3W95ALIAS))	//if alias on          //~v0f0R~
        	pc+=strlen(pc)+1;                                      //~v0f0I~
		uerrmsg("Current dir-list option is LFN %s.",              //~v0f0R~
//  			"現在のディレクトリー表示オプションは LFN %sです", //~v0f0R~
    			"現在のディレクトリー\x95\\示オプションは LFN %sです",//~v0f0I~
				pc);                                               //~v0f0I~
		return 0;                                                  //~v0f0I~
    }                                                              //~v0f0I~
    if (!ufileisvfat(ISVFAT_ERRMSG))	//err msg if not vfat      //~v10jI~
    	return 4;                                                  //~v10jI~
	switch(opid=wordtblisrch(pc,Swordtblfat),opid)                 //~v0f0R~
    {                                                              //~v0f0I~
	case 0:	//err                                                  //~v0f0I~
        return errinvalid(pc);                                     //~v0f0I~
	case 1:	//off                                                  //~v0f0I~
    	if (UCBITCHK(Gopt3,GOPT3W95ALIAS))                         //~v0f0R~
            return erralready();                                   //~v0f0I~
    	UCBITON(Gopt3,GOPT3W95ALIAS);                              //~v0f0R~
		uerrmsg("Next time,dir list is by short file name",        //~v0f0I~
//  			"次からディレクトリー表示は短縮前を使用します");   //~v0f0R~
    			"次からディレクトリー\x95\\示は短縮前を使用します");//~v0f0I~
        break;                                                     //~v0f0I~
	case 2:	//on                                                   //~v0f0I~
    	if (!UCBITCHK(Gopt3,GOPT3W95ALIAS))                        //~v0f0R~
            return erralready();                                   //~v0f0I~
    	UCBITOFF(Gopt3,GOPT3W95ALIAS);                             //~v0f0R~
		uerrmsg("Next time,dir list is by long file name",         //~v0f0I~
//  			"次からディレクトリー表示は長いファイル名を使用します");//~v0f0R~
    			"次からディレクトリー\x95\\示は長いファイル名を使用します");//~v0f0I~
        break;                                                     //~v0f0I~
	}//opd                                                         //~v0f0I~
	return 0;                                                      //~v0f0I~
#endif                                                             //~v0f0I~
}//opt_fat                                                         //~v0f0I~
                                                                   //~v0g1I~
//**************************************************************** //~v0g1I~
//!opt_pfat                                                        //~v0g1I~
//* win95/gcc xprint parm lfn yes/no                               //~v0g1I~
//*parm1:pcw(UCWparm:operand)                                      //~v0g1I~
//*parm2:pot                                                       //~v0g1I~
//*parm3:opd no                                                    //~v0g1I~
//*retrn:rc                                                        //~v0g1I~
//**************************************************************** //~v0g1I~
int opt_pfat(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v0g1I~
{                                                                  //~v0g1I~
#if !defined(W32) && !defined(DPMI)                                //~v0g1I~
#else                                                              //~v0g1I~
    int opid;                                                      //~v0g1I~
    UCHAR *pc;                                                     //~v0g1I~
#endif                                                             //~v0g1I~
//*********************************                                //~v0g1I~
#if !defined(W32) && !defined(DPMI)                                //~v0g1I~
//  uerrmsg("Avail under Window95 only",                           //~v0jcR~
//  		"Windows95でのみ有効です");                            //~v0jcR~
//  return 4;                                                      //~v0jcR~
    return opterrwinonly();                                        //~v0jcI~
#else                                                              //~v0g1I~
    if (!ufileisvfat(ISVFAT_ERRMSG))	//err msg if not vfat      //~v0g1I~
    	return 4;                                                  //~v0g1I~
	if (!(pc=Ppcw->UCWparm))                                       //~v0g1I~
    {                                                              //~v0g1I~
        pc=Swordtblfat;                                            //~v0g1I~
    	if (!UCBITCHK(Gopt4,GOPT4W95ALIASP))	//if alias on      //~v0g1I~
        	pc+=strlen(pc)+1;                                      //~v0g1I~
		uerrmsg("Current print line cmd parm option is LFN %s.",   //~v0g1R~
    			"現在のPrint行コマンドパラメータオプションは LFN %sです",//~v0g1I~
				pc);                                               //~v0g1I~
		return 0;                                                  //~v0g1I~
    }                                                              //~v0g1I~
	switch(opid=wordtblisrch(pc,Swordtblfat),opid)                 //~v0g1I~
    {                                                              //~v0g1I~
	case 0:	//err                                                  //~v0g1I~
        return errinvalid(pc);                                     //~v0g1I~
	case 1:	//off                                                  //~v0g1I~
    	if (UCBITCHK(Gopt4,GOPT4W95ALIASP))                        //~v0g1I~
            return erralready();                                   //~v0g1I~
    	UCBITON(Gopt4,GOPT4W95ALIASP);                             //~v0g1I~
		uerrmsg("Parm is by short filename for print line command",//~v0g1I~
    			"Print行コマンドパラメータは短縮名を使用します");  //~v0g1I~
        break;                                                     //~v0g1I~
	case 2:	//on                                                   //~v0g1I~
    	if (!UCBITCHK(Gopt4,GOPT4W95ALIASP))                       //~v0g1I~
            return erralready();                                   //~v0g1I~
    	UCBITOFF(Gopt4,GOPT4W95ALIASP);                            //~v0g1I~
		uerrmsg("Parm is by long filename for print line command", //~v0g1I~
    			"Print行コマンドパラメータは長いファイル名を使用します");//~v0g1I~
        break;                                                     //~v0g1I~
	}//opd                                                         //~v0g1I~
	return 0;                                                      //~v0g1I~
#endif                                                             //~v0g1I~
}//opt_pfat                                                        //~v0g1I~
//**************************************************************** //~v43yI~
//!opt_7bit                                                        //~v43yI~
//* binary file 7bit dump mode                                     //~v43yI~
//*parm1:pcw(UCWparm:operand)                                      //~v43yI~
//*parm2:pot                                                       //~v43yI~
//*parm3:opd no                                                    //~v43yI~
//*retrn:rc                                                        //~v43yI~
//**************************************************************** //~v43yI~
int opt_7bit(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v43yR~
{                                                                  //~v43yI~
    int opid;                                                      //~v43yI~
    UCHAR *pc;                                                     //~v54SR~
//*********************************                                //~v43yI~
	if (!(pc=Ppcw->UCWparm))                                       //~v43yI~
    {                                                              //~v43yI~
        pc=Swordtblfat;                                            //~v43yI~
    	if (UCBITCHK(Gopt4,GOPT47BIT))	//if alias on              //~v43yR~
        	pc+=strlen(pc)+1;                                      //~v43yI~
		uerrmsg("Binary file display mode is ASCII %s.",           //~v54SR~
    			"バイナりーファイル\x95\\示モードはASCII %s。",    //~v54SR~
				pc);                                               //~v54SR~
		return 0;                                                  //~v43yI~
    }                                                              //~v43yI~
	if (!stricmp(pc,STR_RESET))                                    //~v54SI~
    {                                                              //~v54SI~
    	if (UCBITCHK(Gopt4,GOPT47BITCMD))	//once cmd enterd,ignore default from here//~v54SI~
        {                                                          //~v54SI~
    		UCBITOFF(Gopt4,GOPT47BITCMD); //use ini file at next restart//~v54SI~
			uerrmsg("ini file ASCII option will be efective at next session.",//~v54SI~
    				"ASCIIオプションは次回から ini ファイルの指定が有効になります。");//~v54SI~
        }                                                          //~v54SI~
        else                                                       //~v54SI~
			uerrmsg("ini file ASCII option is already in effective status.",//~v54SI~
    				"ASCIIオプションは既に ini ファイルの指定が有効な状態です。");//~v54SI~
        return 0;                                                  //~v54SI~
    }                                                              //~v54SI~
	switch(opid=wordtblisrch(pc,Swordtblfat),opid)                 //~v43yI~
    {                                                              //~v43yI~
	case 0:	//err                                                  //~v43yI~
        return errinvalid(pc);                                     //~v43yI~
	case 1:	//off                                                  //~v43yI~
    	if (!UCBITCHK(Gopt4,GOPT47BIT))	//if ASCII off             //~v43yR~
            return erralready();                                   //~v43yI~
    	UCBITOFF(Gopt4,GOPT47BIT);                                 //~v43yR~
        pc=Swordtblfat;                                            //~v43yI~
        break;                                                     //~v43yI~
	case 2:	//on                                                   //~v43yI~
    	if (UCBITCHK(Gopt4,GOPT47BIT))	//if ASCII off             //~v43yR~
            return erralready();                                   //~v43yI~
    	UCBITON(Gopt4,GOPT47BIT);                                  //~v43yR~
        pc=Swordtblfat;                                            //~v43yI~
        pc+=strlen(pc)+1;                                          //~v43yM~
        break;                                                     //~v43yI~
	}//opd                                                         //~v43yI~
    UCBITON(Gopt4,GOPT47BITCMD);	//once cmd enterd,ignore default from here//~v43zI~
    scrfulldraw(Ppcw);                                             //~v43yI~
    uerrmsg("Binary file display mode is set to ASCII %s",         //~v43yI~
            "バイナりーファイル\x95\\示モードはASCII %s にしました。",//~v43yR~
            pc);                                                   //~v43yI~
	return 0;                                                      //~v43yI~
}//opt_7bit                                                        //~v43yI~
//**************************************************************** //~v44mI~
//!opt_hex                                                         //~v44mI~
//* hex digit case option                                          //~v44mI~
//*parm1:pcw(UCWparm:operand)                                      //~v44mI~
//*parm2:pot                                                       //~v44mI~
//*parm3:opd no                                                    //~v44mI~
//*retrn:rc                                                        //~v44mI~
//**************************************************************** //~v44mI~
int opt_hex(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)             //~v44mI~
{                                                                  //~v44mI~
    UCHAR *pc;                                                     //~v44mI~
static char *Shexmode[2]={"UpperCase","LowerCase"};                //~v44mR~
//*********************************                                //~v44mI~
	if (!(pc=Ppcw->UCWparm))                                       //~v44mI~
    {                                                              //~v44mI~
    	if (UCBITCHK(Goptopt,GOPT_HEX_UPPER))	//if alias on      //~v44mI~
        	pc=Shexmode[0];                                        //~v44mI~
        else                                                       //~v44mI~
        	pc=Shexmode[1];                                        //~v44mI~
		uerrmsg("HexDigit option is %s",                           //~v44mI~
    			"Hex文字オプションは %s",                          //~v44mI~
				pc);                                               //~v44mI~
		return 0;                                                  //~v44mI~
    }                                                              //~v44mI~
	switch(toupper(*pc))                                           //~v44mI~
    {                                                              //~v44mI~
	case 'U':	//err                                              //~v44mI~
    	UCBITON(Goptopt,GOPT_HEX_UPPER);                           //~v44mI~
        pc=Shexmode[0];                                            //~v44mI~
        break;                                                     //~v44mI~
	case 'L':	//err                                              //~v44mI~
    	UCBITOFF(Goptopt,GOPT_HEX_UPPER);                          //~v44mI~
        pc=Shexmode[1];                                            //~v44mI~
        break;                                                     //~v44mI~
	case 2:	//on                                                   //~v44mI~
    default:                                                       //~v44mI~
        return errinvalid(pc);                                     //~v44mI~
	}//opd                                                         //~v44mI~
    scrfulldraw(Ppcw);                                             //~v44mI~
    uerrmsg("HexDigit option set to %s",                           //~v44mI~
    		"Hex文字オプションは %s に設定",                       //~v44mI~
            pc);                                                   //~v44mI~
	return 0;                                                      //~v44mI~
}//opt_hex                                                         //~v44mI~
#ifdef UNX                                                         //~v47NI~
//**************************************************************** //~v47NI~
//!opt_fd                                                          //~v47NI~
//* mdos disk option                                               //~v47NI~
//*parm1:pcw(UCWparm:operand)                                      //~v47NI~
//*parm2:pot                                                       //~v47NI~
//*parm3:opd no                                                    //~v47NI~
//*retrn:rc                                                        //~v47NI~
//**************************************************************** //~v47NI~
int opt_fd(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)              //~v47NI~
{                                                                  //~v47NI~
    UCHAR *pc;                                                     //~v47NI~
    int rc;                                                        //~v47NR~
//*********************************                                //~v47NI~
	if (!(pc=Ppcw->UCWparm))                                       //~v47NI~
    {                                                              //~v47NI~
    	if (UCBITCHK(Gufile_opt,GFILEOPT_LNXMTOOL))	//mdos disk support//~v47NI~
        	pc=STR_ON;                                             //~v47NI~
        else                                                       //~v47NI~
        	pc=STR_OFF;                                            //~v47NI~
		uerrmsg("FloppyDisk option is %s",                         //~v47NI~
    			"フロッピーディスクオプションは %s",               //~v47NI~
				pc);                                               //~v47NI~
		return 0;                                                  //~v47NI~
    }                                                              //~v47NI~
	rc=optoffonchk(pc,1);	//msg issue                            //~v47NR~
    if (rc>1)                                                      //~v47NI~
    	return rc;                                                 //~v47NI~
    if (rc)	//on                                                   //~v47NI~
    {                                                              //~v47NI~
    	if (UCBITCHK(Gufile_opt,GFILEOPT_LNXMTOOL))	//mdos disk support//~v47NI~
            return erralready();                                   //~v47NI~
    	UCBITON(Gufile_opt,GFILEOPT_LNXMTOOL);	//mdos disk support//~v47NI~
        pc=STR_ON;                                                 //~v47NI~
    }else                                                          //~v47NI~
    {                                                              //~v47NI~
    	if (!UCBITCHK(Gufile_opt,GFILEOPT_LNXMTOOL))	//mdos disk support//~v47NI~
            return erralready();                                   //~v47NI~
    	UCBITOFF(Gufile_opt,GFILEOPT_LNXMTOOL);	//mdos disk support//~v47NI~
        pc=STR_OFF;                                                //~v47NI~
	}//opd                                                         //~v47NI~
	uerrmsg("FloppyDisk option is set to %s",                      //~v47NI~
    		"フロッピーディスクオプションを %sに設定",             //~v47NI~
            pc);                                                   //~v47NI~
	return 0;                                                      //~v47NI~
}//opt_fd                                                          //~v47NR~
//#else                                                            //~v64tR~
#endif                                                             //~v64tI~
//#if !defined(UNX) || defined(XXE)                                //~v768R~
//**************************************************************** //~v55cI~
//!opt_rctl                                                        //~v55cI~
//* RCTL use option                                                //~v55cI~
//*parm1:pcw(UCWparm:operand)                                      //~v55cI~
//*parm2:pot                                                       //~v55cI~
//*parm3:opd no                                                    //~v55cI~
//*retrn:rc                                                        //~v55cI~
//**************************************************************** //~v55cI~
int opt_rctl(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v55cI~
{                                                                  //~v55cI~
//#if defined(UNX) && !defined(XXE)                                //~v78NR~
//  return errnotsupported("OPT RCTL","Unix Console Version");     //~v78NR~
#ifdef AIX                                                         //~v78NI~
    return errnotsupported("OPT RCTL","AIX");                      //~v78NI~
#endif                                                             //~v768R~
    UCHAR *pc;                                                     //~v55cI~
    int rc;                                                        //~v55cI~
//*********************************                                //~v55cI~
	if (!(pc=Ppcw->UCWparm))                                       //~v55cI~
    {                                                              //~v55cI~
	    if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter    //~v55cI~
        	pc=STR_ON;                                             //~v55cI~
        else                                                       //~v55cI~
        	pc=STR_OFF;                                            //~v55cI~
		uerrmsg("Right-Ctrl Key option is %s",                     //~v55cI~
    			"右Ctrlキーオプションは %s",                       //~v55cI~
				pc);                                               //~v55cI~
	    if (Gotheropt & GOTHERO_RCTLNL)   //use RCTL as enter      //~v768I~
        	pc=STR_ON;                                             //~v768I~
        else                                                       //~v768I~
        	pc=STR_OFF;                                            //~v768I~
		uerrmsgcat(" (NewLine option is %s)",                      //~v768I~
    			" (NewLineオプションは %s)",                       //~v768R~
				pc);                                               //~v768I~
		return 0;                                                  //~v55cI~
    }                                                              //~v55cI~
	rc=optoffonchk(pc,1);	//msg issue                            //~v55cI~
    if (rc>1)                                                      //~v55cI~
    	return rc;                                                 //~v55cI~
    UCBITON(Gopt4,GOPT4RCTLCMD);    //to be write to inifile       //~v55cI~
    if (rc)	//on                                                   //~v55cI~
    {                                                              //~v55cI~
	    if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter    //~v55cI~
            return erralready();                                   //~v55cI~
	    UCBITON(Gopt,GOPTRCTLENTER);   //use RCTL as enter         //~v55cI~
#ifdef XXE                                                         //~v64tR~
    	funcchngeenter(1);	//change ENTER key to cr from execute+cr//~v64tI~
#else                                                              //~v64tI~
//#ifndef UNX                                                      //~v78NR~
#ifndef AIX                                                        //~v78NI~
        kbdchngstatus(1);   //tell to kbdproc                      //~v55cI~
    	funcchngeenter(1);	//change ENTER key to cr from execute+cr//~v55cR~
#endif                                                             //~v55cI~
#endif                                                             //~v64tI~
        pc=STR_ON;                                                 //~v55cI~
    }else                                                          //~v55cI~
    {                                                              //~v55cI~
	    if (!UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter   //~v55cI~
//		  if (!UCBITCHK(Gotheropt,GOTHERO_RCTLOFFCL))  //Right Ctrl off by cmdline parm//~vb27R~
  		  if (!ULBITCHK(Gotheropt,GOTHERO_RCTLOFFCL))  //Right Ctrl off by cmdline parm//~vb27I~
            return erralready();                                   //~v55cI~
	    UCBITOFF(Gopt,GOPTRCTLENTER);   //use RCTL as enter        //~v55cI~
#ifdef XXE                                                         //~v64tR~
    	funcchngeenter(0);		//change ENTER key from cr to execute+cr//~v64tI~
#else                                                              //~v64tI~
//#ifndef UNX                                                      //~v78NR~
#ifndef AIX                                                        //~v78NI~
        kbdchngstatus(0);                                          //~v55cI~
    	funcchngeenter(0);		//change ENTER key from cr to execute+cr//~v55cR~
#endif                                                             //~v55cI~
#endif                                                             //~v64tI~
        pc=STR_OFF;                                                //~v55cI~
	}//opd                                                         //~v55cI~
  if (pc==STR_ON)                                                  //~van9I~
    uerrmsg("Right-Ctrl Key option is set to %s(Restart with %cNr option and entrer cmd to set OFF,when no Enter key available!).",//~van9R~
            "右Ctrlキーオプションを %s に設定(使えるEnterキーが無くなった場合は %cNr オプションで再スターとしてOFFに再設定してください) ",//~van9I~
            pc,CMDFLAG_PREFIX);                                    //~van9R~
  else                                                             //~van9I~
    uerrmsg("Right-Ctrl Key option is set to %s.",                 //~v55cI~
            "右Ctrlキーオプションを %s に設定。",                  //~v55cI~
            pc);                                                   //~v55cI~
    if (Gotheropt & GOTHERO_RCTLNL)   //use RCTL as enter          //~v768I~
        pc=STR_ON;                                                 //~v768I~
    else                                                           //~v768I~
        pc=STR_OFF;                                                //~v768I~
    uerrmsgcat(" (NewLine option is %s)",                          //~v768I~
            " (NewLineオプションは %s)",                           //~v768I~
            pc);                                                   //~v768I~
	return 0;                                                      //~v55cI~
}//opt_rctl                                                        //~v55cI~
//#endif                                                           //~v768R~
//**************************************************************** //~v55jI~
//!opt_ccfunc                                                      //~v55jR~
//* ctl char function use                                          //~v55jI~
//*parm1:pcw(UCWparm:operand)                                      //~v55jI~
//*parm2:pot                                                       //~v55jI~
//*parm3:opd no                                                    //~v55jI~
//*retrn:rc                                                        //~v55jI~
//**************************************************************** //~v55jI~
int opt_ccfunc(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)          //~v55jR~
{                                                                  //~v55jI~
    UCHAR *pc;                                                     //~v55jI~
    int rc;                                                        //~v55jI~
//*********************************                                //~v55jI~
	if (!(pc=Ppcw->UCWparm))                                       //~v55jI~
    {                                                              //~v55jI~
	    if (UCBITCHK(Gopt5,GOPT5NOCTLCHARFUNC))   //use RCTL as enter//~v55jI~
        	pc=STR_OFF;                                            //~v55jI~
        else                                                       //~v55jI~
        	pc=STR_ON;                                             //~v55jI~
		uerrmsg("CtrlCharFunction option is %s",                   //~v55jI~
    			"Ctrl+文字キー機\x94\\割当オプションは %s",        //~v55jR~
				pc);                                               //~v55jI~
		return 0;                                                  //~v55jI~
    }                                                              //~v55jI~
	rc=optoffonchk(pc,1);	//msg issue                            //~v55jI~
    if (rc>1)                                                      //~v55jI~
    	return rc;                                                 //~v55jI~
    if (rc)	//on                                                   //~v55jI~
    {                                                              //~v55jI~
	    if (!UCBITCHK(Gopt5,GOPT5NOCTLCHARFUNC))   //use RCTL as enter//~v55jI~
            return erralready();                                   //~v55jI~
	    UCBITOFF(Gopt5,GOPT5NOCTLCHARFUNC);   //use RCTL as enter  //~v55jI~
        pc=STR_ON;                                                 //~v55jI~
    }else                                                          //~v55jI~
    {                                                              //~v55jI~
	    if (UCBITCHK(Gopt5,GOPT5NOCTLCHARFUNC))   //use RCTL as enter//~v55jI~
            return erralready();                                   //~v55jI~
	    UCBITON(Gopt5,GOPT5NOCTLCHARFUNC);   //use RCTL as enter   //~v55jI~
        pc=STR_OFF;                                                //~v55jI~
	}//opd                                                         //~v55jI~
    uerrmsg("CtrlCharFunction option is set to %s.",               //~v55jI~
            "Ctrl+文字キー機\x94\\を %s に設定",                   //~v55jR~
            pc);                                                   //~v55jI~
	return 0;                                                      //~v55jI~
}//opt_ccfunc                                                      //~v55jR~
//**************************************************************** //~v55qI~
//!opt_freecsr                                                     //~v55qI~
//* scroll by csr move option                                      //~v55qI~
//*parm1:pcw(UCWparm:operand)                                      //~v55qI~
//*parm2:pot                                                       //~v55qI~
//*parm3:opd no                                                    //~v55qI~
//*retrn:rc                                                        //~v55qI~
//**************************************************************** //~v55qI~
int opt_freecsr(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)         //~v55qI~
{                                                                  //~v55qI~
    UCHAR *pc;                                                     //~v55qI~
    int rc;                                                        //~v55qI~
//*********************************                                //~v55qI~
	if (!(pc=Ppcw->UCWparm))                                       //~v55qI~
    {                                                              //~v55qI~
	    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL))   //scroll by csr      //~v55qI~
        	pc=STR_OFF;                                            //~v55qI~
        else                                                       //~v55qI~
        	pc=STR_ON;                                             //~v55qI~
		uerrmsg("Free cursor mode option is %s",                   //~v55qI~
    			"フリーカー\x83\\ルモードオプションは %s",         //~v55qR~
				pc);                                               //~v55qI~
		return 0;                                                  //~v55qI~
    }                                                              //~v55qI~
	rc=optoffonchk(pc,1);	//msg issue                            //~v55qI~
    if (rc>1)                                                      //~v55qI~
    	return rc;                                                 //~v55qI~
    if (rc)	//on                                                   //~v55qI~
    {                                                              //~v55qI~
	    if (!UCBITCHK(Gopt5,GOPT5CSRSCROLL))   //use RCTL as enter //~v55qI~
            return erralready();                                   //~v55qI~
	    UCBITOFF(Gopt5,GOPT5CSRSCROLL);   //use RCTL as enter      //~v55qI~
        pc=STR_ON;                                                 //~v55qI~
    }else                                                          //~v55qI~
    {                                                              //~v55qI~
	    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL))   //use RCTL as enter  //~v55qI~
            return erralready();                                   //~v55qI~
	    UCBITON(Gopt5,GOPT5CSRSCROLL);   //use RCTL as enter       //~v55qI~
        pc=STR_OFF;                                                //~v55qI~
	}//opd                                                         //~v55qI~
	uerrmsg("Free cursor mode option is set to %s",                //~v55qI~
    		"フリーカー\x83\\ルモードオプションを %s に設定。",    //~v55qR~
            pc);                                                   //~v55qI~
	return 0;                                                      //~v55qI~
}//opt_freecsr                                                     //~v55qI~
//**************************************************************** //~v584I~
//!opt_cbcopy                                                      //~v584I~
//* option to copy to clipboad when cut and paste                  //~v584I~
//*parm1:pcw(UCWparm:operand)                                      //~v584I~
//*parm2:pot                                                       //~v584I~
//*parm3:opd no                                                    //~v584I~
//*retrn:rc                                                        //~v584I~
//**************************************************************** //~v584I~
int opt_cbcopy(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)          //~v584I~
{                                                                  //~v584I~
    UCHAR *pc;                                                     //~v584I~
    int rc;                                                        //~v584I~
//*********************************                                //~v584I~
	if (!(pc=Ppcw->UCWparm))                                       //~v584I~
    {                                                              //~v584I~
	    if (UCBITCHK(Gopt5,GOPT5CBNOCOPY))   //skip copy to cb when cap-del//~v584R~
        	pc=STR_OFF;                                            //~v584I~
        else                                                       //~v584I~
        	pc=STR_ON;                                             //~v584I~
        uerrmsg("Cut & Paste:Save del data to ::CB option is %s.", //~v584R~
                "削除データの ::CB 保存 オプションは %s",          //~v584R~
                pc);                                               //~v584I~
		return 0;                                                  //~v584I~
    }                                                              //~v584I~
	rc=optoffonchk(pc,1);	//msg issue                            //~v584I~
    if (rc>1)                                                      //~v584I~
    	return rc;                                                 //~v584I~
    if (rc)	//on                                                   //~v584I~
    {                                                              //~v584I~
	    if (!UCBITCHK(Gopt5,GOPT5CBNOCOPY))   //skip copy to cb    //~v584R~
            return erralready();                                   //~v584I~
	    UCBITOFF(Gopt5,GOPT5CBNOCOPY);   //do copy                 //~v584R~
        pc=STR_ON;                                                 //~v584I~
    }else                                                          //~v584I~
    {                                                              //~v584I~
	    if (UCBITCHK(Gopt5,GOPT5CBNOCOPY))   //skip                //~v584R~
            return erralready();                                   //~v584I~
	    UCBITON(Gopt5,GOPT5CBNOCOPY);   //skip                     //~v584R~
        pc=STR_OFF;                                                //~v584I~
	}//opd                                                         //~v584I~
    uerrmsg("Cut & Paste:Save del data to ::CB option is set to %s.",//~v584R~
            "削除データの ::CB 保存 オプションを %s に設定。",     //~v584R~
            pc);                                                   //~v584I~
	return 0;                                                      //~v584I~
}//opt_cbcopy                                                      //~v584I~
//**************************************************************** //~v54SI~
//!opt_beep                                                        //~v54SI~
//* mdos disk option                                               //~v54SI~
//*parm1:pcw(UCWparm:operand)                                      //~v54SI~
//*parm2:pot                                                       //~v54SI~
//*parm3:opd no                                                    //~v54SI~
//*retrn:rc                                                        //~v54SI~
//**************************************************************** //~v54SI~
int opt_beep(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v54SI~
{                                                                  //~v54SI~
    UCHAR *pc;                                                     //~v54SR~
    int rc;                                                        //~v54SI~
//*********************************                                //~v54SI~
	if (!(pc=Ppcw->UCWparm))                                       //~v54SI~
    {                                                              //~v54SI~
    	if (UCBITCHK(Gopt4,GOPT4NOBEEP))   //beep if nobeep is off //~v54SI~
        	pc=STR_OFF;                                            //~v54SI~
        else                                                       //~v54SI~
        	pc=STR_ON;                                             //~v54SI~
		uerrmsg("Beep option is %s.",                              //~v54SR~
    			"ビ－プオプションは %s。",                         //~v54SR~
				pc);                                               //~v54SI~
		return 0;                                                  //~v54SI~
    }                                                              //~v54SI~
	rc=optoffonchk(pc,OPTOFC_ERRMSG|OPTOFC_RESETCHK);              //~v54SR~
    if (rc>1)                                                      //~v54SI~
    	return rc;                                                 //~v54SI~
    if (rc==-1)                                                    //~v54SI~
    {                                                              //~v54SI~
    	if(UCBITCHK(Gopt4,GOPT4NOBEEPCMD)) //use ini file at next restart//~v54SR~
        {                                                          //~v54SI~
    		UCBITOFF(Gopt4,GOPT4NOBEEPCMD); //use ini file at next restart//~v54SI~
			uerrmsg("ini file beep option will be efective at next session.",//~v54SR~
    				"ビ－プオプションは次回から ini ファイルの指定が有効になります。");//~v54SR~
        }                                                          //~v54SI~
        else                                                       //~v54SI~
			uerrmsg("ini file beep option is already in effective status.",//~v54SR~
    				"ビ－プオプションは既に ini ファイルの指定が有効な状態です。");//~v54SI~
        return 0;                                                  //~v54SI~
    }                                                              //~v54SI~
    if (rc)	//on                                                   //~v54SI~
    {                                                              //~v54SI~
    	if (!UCBITCHK(Gopt4,GOPT4NOBEEP))   //beep if nobeep is off//~v54SI~
            return erralready();                                   //~v54SI~
    	UCBITOFF(Gopt4,GOPT4NOBEEP);   //beep on                   //~v54SI~
    	UCBITON(Gopt4,GOPT4NOBEEPCMD); //ignore ini file setting from here//~v54SI~
	    ubell_init(1);   //beep;                                   //~v54SI~
        pc=STR_ON;                                                 //~v54SI~
    }                                                              //~v54SI~
	else   //off                                                   //~v54SI~
    {                                                              //~v54SI~
    	if (UCBITCHK(Gopt4,GOPT4NOBEEP))   //beep if nobeep is off //~v54SI~
            return erralready();                                   //~v54SI~
    	UCBITON(Gopt4,GOPT4NOBEEP);   //beep on                    //~v54SI~
    	UCBITON(Gopt4,GOPT4NOBEEPCMD); //ignore ini file setting from here//~v54SI~
	    ubell_init(0);   //no beep;                                //~v54SI~
        pc=STR_OFF;                                                //~v54SI~
	}//opd                                                         //~v54SI~
	uerrmsg("Beep option is set to %s",                            //~v54SI~
    		"ビープオプションを %sに設定",                         //~v54SI~
            pc);                                                   //~v54SI~
	return 0;                                                      //~v54SI~
}//opt_beep                                                        //~v54SI~
//**************************************************************** //~v62GI~
//!opt_cmdlog                                                      //~v62GI~
//**************************************************************** //~v62GI~
int opt_cmdlog(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)          //~v62GI~
{                                                                  //~v62GI~
    UCHAR *pc;                                                     //~v62GI~
    int rc;                                                        //~v62GI~
//*********************************                                //~v62GI~
	if (!(pc=Ppcw->UCWparm))                                       //~v62GI~
    {                                                              //~v62GI~
    	if (UCBITCHK(Goptopt,GOPT_CMDLOG))   //beep if nobeep is off//~v62GI~
        	pc=STR_ON;                                             //~v62GI~
        else                                                       //~v62GI~
        	pc=STR_OFF;                                            //~v62GI~
		uerrmsg("CmdLog option is now %s.",                        //~v62GI~
    			"コマンドログプオプションは現在 %s。",             //~v62GI~
				pc);                                               //~v62GI~
		return 0;                                                  //~v62GI~
    }                                                              //~v62GI~
	rc=optoffonchk(pc,OPTOFC_ERRMSG);                              //~v62GI~
    if (rc>1)                                                      //~v62GI~
    	return rc;                                                 //~v62GI~
    if (rc)	//on                                                   //~v62GI~
    {                                                              //~v62GI~
    	if(UCBITCHK(Goptopt,GOPT_CMDLOG))                          //~v62GI~
            return erralready();                                   //~v62GI~
    	UCBITON(Goptopt,GOPT_CMDLOG);                              //~v62GI~
        if (rc=funccmdlog(0,FCMDLOG_OPEN),rc)    //open cmdlog     //~v62GR~
            return rc;                                             //~v62GI~
        pc=STR_ON;                                                 //~v62GI~
    }                                                              //~v62GI~
	else   //off                                                   //~v62GI~
    {                                                              //~v62GI~
//  	if(UCBITCHK(!Goptopt,GOPT_CMDLOG))                         //~v69NR~
    	if(!UCBITCHK(Goptopt,GOPT_CMDLOG))                         //~v69NI~
            return erralready();                                   //~v62GI~
        if (rc=funccmdlog(0,FCMDLOG_CLOSE),rc)    //close cmdlog   //~v62GR~
            return rc;                                             //~v62GI~
    	UCBITOFF(Goptopt,GOPT_CMDLOG);                             //~v62GI~
        pc=STR_OFF;                                                //~v62GI~
	}//opd                                                         //~v62GI~
	uerrmsg("CmdLog option is set to %s",                          //~v62GI~
    		"コマンドログオプションを %sに設定",                   //~v62GI~
            pc);                                                   //~v62GI~
	return 0;                                                      //~v62GI~
}//opt_cmdlog                                                      //~v62GI~
//**************************************************************** //~v678I~
//!opt_rettol                                                      //~v678I~
//**************************************************************** //~v678I~
int opt_rettol(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)          //~v678I~
{                                                                  //~v678I~
    UCHAR *pc;                                                     //~v678I~
    int rc;                                                        //~v678I~
//*********************************                                //~v678I~
	if (!(pc=Ppcw->UCWparm))                                       //~v678I~
    {                                                              //~v678I~
    	if (UCBITCHK(Goptopt,GOPT_RETTOL))   //beep if nobeep is off//~v678I~
        	pc=STR_ON;                                             //~v678I~
        else                                                       //~v678I~
        	pc=STR_OFF;                                            //~v678I~
		uerrmsg("ReturnToTOL option is now %s.",                   //~v678I~
    			"改行キーでカー\x83\\ルをTopOfLineに戻すプオプションは現在 %s。",//~v678R~
				pc);                                               //~v678I~
		return 0;                                                  //~v678I~
    }                                                              //~v678I~
	rc=optoffonchk(pc,OPTOFC_ERRMSG);                              //~v678I~
    if (rc>1)                                                      //~v678I~
    	return rc;                                                 //~v678I~
    if (rc)	//on                                                   //~v678I~
    {                                                              //~v678I~
    	if(UCBITCHK(Goptopt,GOPT_RETTOL))                          //~v678I~
            return erralready();                                   //~v678I~
    	UCBITON(Goptopt,GOPT_RETTOL);                              //~v678I~
        pc=STR_ON;                                                 //~v678I~
    }                                                              //~v678I~
	else   //off                                                   //~v678I~
    {                                                              //~v678I~
//  	if(UCBITCHK(!Goptopt,GOPT_RETTOL))                         //~v69NR~
    	if(!UCBITCHK(Goptopt,GOPT_RETTOL))                         //~v69NI~
            return erralready();                                   //~v678I~
    	UCBITOFF(Goptopt,GOPT_RETTOL);                             //~v678I~
        pc=STR_OFF;                                                //~v678I~
	}//opd                                                         //~v678I~
	uerrmsg("ReturToTOL option is set to %s",                      //~v678I~
    		"改行キーでカー\x83\\ルをTopOfLineに戻すプオプションを %sに設定",//~v678R~
            pc);                                                   //~v678I~
	return 0;                                                      //~v678I~
}//opt_rettol                                                      //~v678I~
//**************************************************************** //~v78SI~
//!opt_contins                                                     //~v78SI~
//**************************************************************** //~v78SI~
int opt_contins(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)         //~v78SI~
{                                                                  //~v78SI~
    UCHAR *pc;                                                     //~v78SI~
    int rc;                                                        //~v78SI~
//*********************************                                //~v78SI~
	if (!(pc=Ppcw->UCWparm))                                       //~v78SI~
    {                                                              //~v78SI~
    	if (!UCBITCHK(Goptopt2,GOPT2_NOCONTINS))   //beep if nobeep is off//~v78SI~
        	pc=STR_ON;                                             //~v78SI~
        else                                                       //~v78SI~
        	pc=STR_OFF;                                            //~v78SI~
		uerrmsg("%s(Continued Insert line after line cmd \"I\") option is now %s.",//~v78SR~
    			"%s(行コマンド\"I\"の継続)オプションは現在 %s。",  //~v78SR~
				CONTINS,pc);                                       //~v78SI~
		return 0;                                                  //~v78SI~
    }                                                              //~v78SI~
	rc=optoffonchk(pc,OPTOFC_ERRMSG);                              //~v78SI~
    if (rc>1)                                                      //~v78SI~
    	return rc;                                                 //~v78SI~
    if (rc)	//on                                                   //~v78SI~
    {                                                              //~v78SI~
    	if(!UCBITCHK(Goptopt2,GOPT2_NOCONTINS))                    //~v78SI~
            return erralready();                                   //~v78SI~
    	UCBITOFF(Goptopt2,GOPT2_NOCONTINS);                        //~v78SI~
        pc=STR_ON;                                                 //~v78SI~
    }                                                              //~v78SI~
	else   //off                                                   //~v78SI~
    {                                                              //~v78SI~
    	if(UCBITCHK(Goptopt2,GOPT2_NOCONTINS))                     //~v78SI~
            return erralready();                                   //~v78SI~
    	UCBITON(Goptopt2,GOPT2_NOCONTINS);                         //~v78SR~
        pc=STR_OFF;                                                //~v78SI~
	}//opd                                                         //~v78SI~
    uerrmsg("%s(Continued Insert line after line cmd \"I\") option is set to %s.",//~v78SR~
            "%s(行コマンド\"I\"の継続)オプションを %s に設定",     //~v78SR~
            CONTINS,pc);                                           //~v78SI~
	return 0;                                                      //~v78SI~
}//opt_contins                                                     //~v78SR~
//**************************************************************** //~v47NI~
//!optoffonchk                                                     //~v47NI~
//* OFF/ON operandchk                                              //~v47NI~
//*parm1:operand                                                   //~v47NI~
//*parm2:err msg option                                            //~v47NI~
//*retrn:rc:0:off, 1:on, 4:err                                     //~v47NI~
//**************************************************************** //~v47NI~
int optoffonchk(char *Pparm,int Popt)                              //~v47NR~
{                                                                  //~v47NI~
    int rc;                                                        //~v47NI~
//**************                                                   //~v47NI~
	if (!stricmp(Pparm,STR_OFF))                                   //~v47NI~
        rc=0;                                                      //~v47NI~
    else                                                           //~v47NI~
	if (!stricmp(Pparm,STR_ON))                                    //~v47NI~
        rc=1;                                                      //~v47NI~
    else                                                           //~v47NI~
    if ((Popt & OPTOFC_RESETCHK)                                   //~v54SI~
	&&  !stricmp(Pparm,STR_RESET))                                 //~v54SI~
        rc=-1;                                                     //~v54SI~
    else                                                           //~v54SI~
//  	if (Popt)                                                  //~v54SR~
    	if (Popt & OPTOFC_ERRMSG)                                  //~v54SI~
	        return errinvalid(Pparm);                              //~v47NR~
        else                                                       //~v47NI~
        	rc=4;                                                  //~v47NI~
    return rc;                                                     //~v47NI~
}//optoffonchk                                                     //~v47NI~
//**************************************************************** //~v47dI~
//!opt_eol                                                         //~v47dI~
//* eol char specification                                         //~v47dI~
//*parm1:pcw(UCWparm:operand)                                      //~v47dI~
//*parm2:pot                                                       //~v47dI~
//*parm3:opd no                                                    //~v47dI~
//*retrn:rc                                                        //~v47dI~
//**************************************************************** //~v47dI~
int opt_eol(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)             //~v47dI~
{                                                                  //~v47dI~
    UCHAR *pc;                                                     //~v47dR~
    UINT  eolchar;                                                 //~v47dI~
    int   opdno,ii,opid;                                           //~v47dI~
//*********************************                                //~v47dI~
	if (!Ppcw->UCWparm)                                            //~v47dI~
    {                                                              //~v47dI~
	  if (Sssweolcont)                                             //~v60mI~
		uerrmsg("opt fold { \" \" | fodid-char | 0xXX | default} [ON|OFF]",0);//~v60mI~
      else                                                         //~v60mI~
		uerrmsg("opt eol { \" \" | eol-char | 0xXX | default} [ON|OFF]",0);//~v47dR~
		return 0;                                                  //~v47dI~
    }                                                              //~v47dI~
    opdno=Ppcw->UCWopdno-1;           //funccmd created already    //~v47dR~
    pc=Ppcw->UCWopdpot;                                            //~v47dR~
    pc+=strlen(pc)+1;                                              //~v47dR~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v47dI~
	{                                                              //~v47dI~
        switch(opid=wordtblisrch(pc,Swordtblfat),opid)             //~v47dI~
        {                                                          //~v47dI~
        case 0: //eol char                                         //~v47dI~
        	eolchar=*pc;                                           //~v47dI~
        	if (eolchar!=' ')                                      //~v47dI~
            {                                                      //~v54SI~
	            if (!stricmp(pc,"default"))                        //~v47dR~
    	        	eolchar=0;                                     //~v47dR~
        	    else                                               //~v47dR~
        		if (!eolchar)                                      //~v47dR~
            		eolchar=' ';                                   //~v47dR~
            	else                                               //~v47dR~
            	if (toupper(*pc)=='X')                             //~v47dR~
            		sscanf(pc+1,"%2x",&eolchar);                   //~v47dR~
            	else                                               //~v47dR~
				if (*pc=='0' && toupper(*(pc+1))=='X')             //~v47dR~
	            	sscanf(pc+2,"%2x",&eolchar);                   //~v47dR~
            }//                                                    //~v54SI~
	      if (Sssweolcont)                                         //~v60mI~
          {                                                        //~v60mI~
            Gopteolcont=(UCHAR)eolchar;                            //~v60mI~
			optsetdisplayeolcontid();	//setup display char       //~v60mI~
          }                                                        //~v60mI~
          else                                                     //~v60mI~
          {                                                        //~v60mI~
            Gopteol=(UCHAR)eolchar;                                //~v47dR~
			optsetdisplayeolid();	//setup display char           //~v47dI~
          }                                                        //~v60mI~
            break;                                                 //~v47dI~
        case 1: //off                                              //~v47dI~
            if (UCBITCHK(Goptopt,GOPT_EOL_ATTROFF))//if ASCII off  //~v47dI~
                return erralready();                               //~v47dI~
            UCBITOFF(Goptopt,GOPT_EOL_ATTRON); //no set attr for eolid//~v47dR~
            UCBITON(Goptopt,GOPT_EOL_ATTROFF); //explicitly off    //~v47dI~
            pc=Swordtblfat;                                        //~v47dI~
            break;                                                 //~v47dI~
        case 2: //on                                               //~v47dI~
            if (UCBITCHK(Goptopt,GOPT_EOL_ATTRON)) //set attr for eolid//~v47dR~
                return erralready();                               //~v47dI~
            UCBITON(Goptopt,GOPT_EOL_ATTRON); //set attr for eolid //~v47dR~
            UCBITOFF(Goptopt,GOPT_EOL_ATTROFF); //set attr for eolid//~v47dI~
            pc=Swordtblfat;                                        //~v47dI~
            pc+=strlen(pc)+1;                                      //~v47dI~
            break;                                                 //~v47dI~
        }//opd                                                     //~v47dI~
	}//loop by operand no                                          //~v47dI~
    scrfulldraw(Ppcw);                                             //~v47dI~
    if (UCBITCHK(Goptopt,GOPT_EOL_ATTRON)) //if ASCII off          //~v47dI~
    	pc=Swordtblfat+strlen(Swordtblfat)+1;                      //~v47dR~
    else                                                           //~v47dI~
    	pc=Swordtblfat;                                            //~v47dI~
  if (Sssweolcont)                                                 //~v60mI~
    uerrmsg("Set FodID char to %c,Set char-attr %s",               //~v60mI~
    		"行折り返しID文字を %c に設定,\x95\\示属性区別=%s",    //~v60mI~
            Gopteolcont2,pc);                                      //~v60mI~
  else                                                             //~v60mI~
    uerrmsg("Set EndOfLine char to %c (0x%02x),Set char-attr %s",  //~va47R~
    		"行末ID文字を %c (0x%02x) に設定,\x95\\示属性区別=%s", //~va47R~
            Gopteol2,                                              //~va47R~
            Gopteol2,pc);                                          //~v47dR~
	return 0;                                                      //~v47dI~
}//opt_eol                                                         //~v47dI~
//**************************************************************** //~v60mI~
//!opt_eolcont                                                     //~v60mI~
//* contline fold id char specification                            //~v60mI~
//*retrn:rc                                                        //~v60mI~
//**************************************************************** //~v60mI~
int opt_eolcont(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)         //~v60mI~
{                                                                  //~v60mI~
    int   rc;                                                      //~v60mR~
//*********************************                                //~v60mI~
	Sssweolcont=1;                                                 //~v60mI~
    rc=opt_eol(Ppcw,Ppot,Popdno);                                  //~v60mR~
	Sssweolcont=0;                                                 //~v60mI~
	return rc;                                                     //~v60mR~
}//opt_eolcont                                                     //~v60mI~
//**************************************************************** //~v47dI~
void optsetdisplayeolid(void)                                      //~v47NR~
{                                                                  //~v47dI~
#define PRINTABLE_EOLID '_'                                        //~v47dI~
#ifdef UNX                                                         //~v47dI~
  #ifdef LNX                                                       //~v47dI~
//  #define EOLID  0x1d                                            //~v51DR~
//  #define EOLID  PRINTABLE_EOLID                                 //~va47R~
	#define EOLID  0x1b                                            //~va47I~
  #else                                                            //~v47dI~
	#define EOLID  PRINTABLE_EOLID                                 //~v47dI~
  #endif                                                           //~v47dI~
#else                                                              //~v47dI~
//#ifdef WXE                                                       //~v500R~
//  #define EOLID  PRINTABLE_EOLID                                 //~v500R~
//#else                                                            //~v500R~
	#define EOLID  0x1b                                            //~v47dI~
//#endif                                                           //~v500R~
#endif                                                             //~v47dI~
	int eolid=EOLID;		//change by many line isrt             //~v47dI~
//********************                                             //~v47dI~
	if (Gopteol)                                                   //~v47dR~
    	Gopteol2=Gopteol;                                          //~v47dR~
    else	//default                                              //~v47dI~
    {                                                              //~v47dI~
#ifdef UNX                                                         //~v47dI~
    #ifndef LNX                                                    //~va47I~
    	if (Gunxflag & GUNX_KON)         //may be kon              //~v47dR~
        	eolid=PRINTABLE_EOLID;                                 //~v47dR~
    #endif                                                         //~va47I~
#endif                                                             //~v47dI~
    	Gopteol2=(UCHAR)eolid;	//default eolid                    //~v47NR~
	}                                                              //~v47dI~
    return;                                                        //~v47dR~
}//optsetdisplayeolid                                              //~v47dR~
//**************************************************************** //~v60mI~
void optsetdisplayeolcontid(void)                                  //~v60mI~
{                                                                  //~v60mI~
#define PRINTABLE_EOLCONTID '_'                                    //~v60mI~
#ifdef UNX                                                         //~v60mI~
//  #define EOLCONTID  PRINTABLE_EOLCONTID                         //~v619R~
    #define EOLCONTID  '|'                                         //~v619I~
#else                                                              //~v60mI~
//  #define EOLCONTID  0x1f                                        //~v619R~
    #define EOLCONTID  '|'                                         //~v619I~
#endif                                                             //~v60mI~
	int eolcontid=EOLCONTID;		//change by many line isrt     //~v60mR~
//********************                                             //~v60mI~
	if (Gopteolcont)                                               //~v60mI~
    	Gopteolcont2=Gopteolcont;                                  //~v60mI~
    else	//default                                              //~v60mI~
    {                                                              //~v60mI~
#ifdef UNX                                                         //~v60mI~
    	if (Gunxflag & GUNX_KON)         //may be kon              //~v60mI~
        	eolcontid=PRINTABLE_EOLID;                             //~v60mI~
#endif                                                             //~v60mI~
    	Gopteolcont2=(UCHAR)eolcontid;	//default eolid            //~v60mI~
	}                                                              //~v60mI~
    return;                                                        //~v60mI~
}//optsetdisplayeolcontid                                          //~v60mI~
#if !defined(W32) && !defined(DPMI)                                //~v0jcI~
//**************************************************************** //~v0jcI~
//!opterrwinonly                                                   //~v0jcI~
//* err msg windows only                                           //~v0jcI~
//*parm1:none                                                      //~v0jcI~
//*retrn:rc                                                        //~v0jcI~
//**************************************************************** //~v0jcI~
int opterrwinonly(void)                                            //~v0jcI~
{                                                                  //~v0jcI~
    uerrmsg("Avail under Windows only",                            //~v0jcR~
    		"Windowsでのみ有効です");                              //~v0jcR~
    return 4;                                                      //~v0jcI~
}//opterrwinonly                                                   //~v0jcI~
#endif                                                             //~v0jcI~
//**************************************************************** //~v69JI~
//!opt_caps                                                        //~v69JI~
//*retrn:rc                                                        //~v69JI~
//**************************************************************** //~v69JI~
int func_capslock(PUCLIENTWE Ppcw)                                 //~v69JI~
{                                                                  //~v69JI~
	PUFILEH pfh;                                                   //~v69JI~
    UCHAR *pc;                                                     //~v69JR~
    UCHAR *pc2;                                                    //~v71LI~
    int rc;                                                        //~v69JR~
    int opdno,funcid=0;                                            //~v71LR~
    char *valf,*valt,*vald,*funcstr="This File";                   //~v71LR~
    char *valc;                                                    //~v72NI~
    int profsw=-1;                                                 //~v78rI~
    PUFILEH pfhdir;                                                //~v78rI~
    int resetsw=0;                                                 //~v78rI~
    char *pext=0;                                                  //~vaf9R~
//*********************************                                //~v69JI~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~v71LI~
	    pfh=UGETPFHFROMPCW(Ppcw);                                  //~v71LR~
    else                                                           //~v71LI~
        pfh=0;                                                     //~v71LI~
    if (Ppcw->UCWtype==UCWTDIR)                                    //~v78rI~
	    pfhdir=UGETPFHFROMPCW(Ppcw);                               //~v78rI~
    else                                                           //~v78rI~
	    pfhdir=0;                                                  //~v78rI~
    pc=Ppcw->UCWopdpot;                                            //~v71LI~
    opdno=Ppcw->UCWopdno;                                          //~v71LI~
    if (opdno>=2)                                                  //~v71LI~
    {                                                              //~v71LI~
        pc2=pc+strlen(pc)+1;     //2nd opd                         //~v71LI~
        if (!stricmp(pc2,"DEFAULT"))                               //~v71LI~
        {                                                          //~v71LI~
            funcid=1;                                              //~v71LI~
            funcstr="Default except TSO File";                     //~v71LR~
        }                                                          //~v71LI~
        else                                                       //~v71LI~
        if (!stricmp(pc2,"TSO"))                                   //~v71LI~
        {                                                          //~v71LI~
            funcid=2;                                              //~v71LI~
            funcstr="TSO File";                                    //~v71LR~
        }                                                          //~v71LI~
        else                                                       //~v71LI~
        if (!stricmp(pc2,"CMD"))                                   //~v72NI~
        {                                                          //~v72NI~
            funcid=3;                                              //~v72NI~
            funcstr="CMD option";                                  //~v72NI~
        }                                                          //~v72NI~
        else                                                       //~v72NI~
        if (!stricmp(pc2,"EXT"))                                   //~v78rI~
        {                                                          //~v78rI~
            funcid=4;                                              //~v78rI~
            funcstr="EXT option";                                  //~v78rI~
            if (!pfh)                                              //~v78rI~
        		return errscrtype("CAP with EXT option");          //~v78rI~
            if (!(pext=strrchr(pfh->UFHfilename+pfh->UFHpathlen,'.')))//~v78rI~
				return fcmdproferrnoext(pfh->UFHfilename);         //~v78rI~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
			return errinvalid(pc2);                                //~v71LI~
    }                                                              //~v71LI~
//  if (Ppcw->UCWtype!=UCWTFILE)                                   //~v71LR~
    if ((!pfh && !pc)	//no operand on not file panel             //~v71LI~
    ||  (pc && *pc=='?')) //operand is "?"                         //~v71LR~
    {                                                              //~v69JI~
//      uerrmsg("CAP [on|off] (toggle if operand missing; available on file panel only)",//~v71LR~
//  				"CAP [on|off] (オペランド無しは反転;ファイル画面でのみ有効)");//~v71LR~
     	if (pfh)                                                   //~v71LI~
	        if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))               //~v71LR~
    	        valf=STR_ON;                                       //~v71LR~
        	else                                                   //~v71LR~
            	valf=STR_OFF;                                      //~v71LR~
        else                                                       //~v71LI~
        	valf="?";                                              //~v71LI~
        if (UCBITCHK(Goptopt,GOPT_CAPLOCK_TSO))                    //~v71LI~
            valt=STR_ON;                                           //~v71LI~
        else                                                       //~v71LI~
            valt=STR_OFF;                                          //~v71LR~
        if (UCBITCHK(Goptopt,GOPT_CAPLOCK_DEFAULT))                //~v71LI~
            vald=STR_ON;                                           //~v71LI~
        else                                                       //~v71LI~
            vald=STR_OFF;                                          //~v71LR~
        if (UCBITCHK(Goptopt,GOPT_CAPLOCK_CMD))                    //~v72NI~
            valc=STR_ON;                                           //~v72NI~
        else                                                       //~v72NI~
            valc=STR_OFF;                                          //~v72NI~
//      uerrmsg("CAP [on|off] [default|tso] (toggle if operand missing),"//~v72NR~
//      		"current value:This File=%s,TSO Default=%s,Other Default=%s",//~v72NR~
//  			"CAP [on|off] [default|tso] (オペランド無しは反転),"//~v72NR~
//              "現在値:このファイル=%s,TSO 省略値=%s,その他ファイル省略値=%s",//~v72NI~
//                 valf,valt,vald);                                //~v72NI~
//      uerrmsg("CAP [on|off] [default|tso|cmd] (toggle if operand missing),"//~v78rR~
        uerrmsg("CAP [on|off|reset] [default|tso|cmd|ext] (toggle if operand missing),"//~v78rI~
        		"current value:This File=%s,TSO Default=%s,Other Default=%s,CMD option=%s",//~v72NI~
    			"CAP [on|off|reset] [default|tso|cmd|ext] (オペランド無しは反転),"//~v78rR~
                "現在値:このファイル=%s,TSO 省略値=%s,その他ファイル省略値=%s,CMDオプション=%s",//~v72NR~
                   valf,valt,vald,valc);                           //~v72NR~
		return 4;                                                  //~v69JI~
    }                                                              //~v69JI~
//  pfh=UGETPFHFROMPCW(Ppcw);                                      //~v71LR~
//  if (!(pc=Ppcw->UCWparm))                                       //~v71LR~
    if (!pc)                                                       //~v71LI~
    {                                                              //~v69JI~
    	if (!pfh)                                                  //~v78tR~
        	return errscrtype("CAP on/off");                       //~v78tR~
        if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))//toggle sw if no operand//~v69JR~
        {                                                          //~v69JI~
            UCBITOFF(pfh->UFHflag8,UFHF8CAPSON);                   //~v69JR~
            pc=STR_OFF;                                            //~v69JI~
            profsw=0;                                              //~v78rI~
        }                                                          //~v69JI~
        else                                                       //~v69JR~
        {                                                          //~v69JI~
            UCBITON(pfh->UFHflag8,UFHF8CAPSON);                    //~v69JR~
            pc=STR_ON;                                             //~v69JI~
            profsw=1;                                              //~v78rI~
        }                                                          //~v69JI~
    }                                                              //~v69JI~
    else                                                           //~v69JI~
    {                                                              //~v69JI~
//      pc=Ppcw->UCWopdpot;                                        //~v71LR~
//      rc=optoffonchk(pc,1);   //msg issue                        //~v78rR~
        rc=optoffonchk(pc,OPTOFC_RESETCHK|OPTOFC_ERRMSG);          //~v78rI~
        if (rc<0)	//reset                                        //~v78rI~
        {                                                          //~v78rI~
        	rc=0;                                                  //~v78rI~
            resetsw=1;                                             //~v78rI~
        }                                                          //~v78rI~
        if (rc>1)                                                  //~v69JR~
            return rc;                                             //~v69JR~
        if (rc) //on                                               //~v69JR~
        {                                                          //~v69JR~
          switch(funcid)                                           //~v71LI~
          {                                                        //~v71LI~
          case 0:                                                  //~v71LI~
          case 4:    //ext                                         //~v78rI~
           if (pfhdir)	//dir                                      //~v78rR~
            pfh=pfhdir; //parm to profile                          //~v78rI~
           else                                                    //~v78rI~
           {                                                       //~v78rI~
	    	if (!pfh)                                              //~v78tI~
//  	    	return errscrtype("CAP on/off");                   //~v78rR~
    	    	return errscrtype("CAP on/off/reset");             //~v78rI~
            if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))               //~v69JR~
              if (funcid==0)	//this file                        //~v78rI~
                return erralready();                               //~v69JR~
            UCBITON(pfh->UFHflag8,UFHF8CAPSON);                    //~v69JR~
          }                                                        //~v78rI~
            profsw=1;                                              //~v78rI~
            break;                                                 //~v71LI~
          case 1: //default                                        //~v71LI~
            if (UCBITCHK(Goptopt,GOPT_CAPLOCK_DEFAULT))            //~v71LI~
                return erralready();                               //~v71LI~
            UCBITON(Goptopt,GOPT_CAPLOCK_DEFAULT);                 //~v71LI~
            break;                                                 //~v71LI~
          case 2: //tso                                            //~v71LI~
            if (UCBITCHK(Goptopt,GOPT_CAPLOCK_TSO))                //~v71LI~
                return erralready();                               //~v71LI~
            UCBITON(Goptopt,GOPT_CAPLOCK_TSO);                     //~v71LI~
            break;                                                 //~v71LI~
          case 3: //cmd                                            //~v72NI~
            if (UCBITCHK(Goptopt,GOPT_CAPLOCK_CMD))                //~v72NI~
                return erralready();                               //~v72NI~
            UCBITON(Goptopt,GOPT_CAPLOCK_CMD);                     //~v72NI~
            break;                                                 //~v72NI~
          }                                                        //~v71LI~
            pc=STR_ON;                                             //~v69JR~
        }                                                          //~v71LR~
        else                                                       //~v71LI~
        {                                                          //~v69JR~
          switch(funcid)                                           //~v71LI~
          {                                                        //~v71LI~
          case 0:                                                  //~v71LI~
          case 4:    //ext                                         //~v78rI~
           if (pfhdir)	//dir                                      //~v78rI~
            pfh=pfhdir; //parm to profile                          //~v78rI~
           else                                                    //~v78rI~
           {                                                       //~v78rI~
	    	if (!pfh)                                              //~v78tI~
//  	    	return errscrtype("CAP on/off");                   //~v78rR~
              if (!pfhdir)                                         //~v78rI~
    	    	return errscrtype("CAP on/off/reset");             //~v78rI~
            if (!UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))              //~v69JR~
              if (funcid==0 && !resetsw)	//this file and not reset//~v78rR~
                return erralready();                               //~v71LI~
            UCBITOFF(pfh->UFHflag8,UFHF8CAPSON);                   //~v69JR~
           }                                                       //~v78rI~
          if (resetsw)                                             //~v78rI~
            profsw=2;                                              //~v78rR~
          else                                                     //~v78rI~
            profsw=0;                                              //~v78rI~
            break;                                                 //~v71LI~
          case 1: //default                                        //~v71LI~
            if (!UCBITCHK(Goptopt,GOPT_CAPLOCK_DEFAULT))           //~v71LI~
                return erralready();                               //~v71LI~
            UCBITOFF(Goptopt,GOPT_CAPLOCK_DEFAULT);                //~v71LI~
            break;                                                 //~v71LI~
          case 2: //tso                                            //~v71LI~
            if (!UCBITCHK(Goptopt,GOPT_CAPLOCK_TSO))               //~v71LI~
                return erralready();                               //~v71LI~
            UCBITOFF(Goptopt,GOPT_CAPLOCK_TSO);                    //~v71LI~
            break;                                                 //~v71LI~
          case 3: //cmd                                            //~v72NI~
            if (!UCBITCHK(Goptopt,GOPT_CAPLOCK_CMD))               //~v72NI~
                return erralready();                               //~v72NI~
            UCBITOFF(Goptopt,GOPT_CAPLOCK_CMD);                    //~v72NI~
            break;                                                 //~v72NI~
          }                                                        //~v71LI~
            pc=STR_OFF;                                            //~v69JR~
        }                                                          //~v69JR~
                                                                   //~v71LI~
    }                                                              //~v69JI~
//  uerrmsg("This file CapsLock option is Now %s",                 //~v71LR~
//          "このファイルの CapsLock オプションを %s に設定",      //~v71LR~
//          pc);                                                   //~v71LR~
  if (pfh==pfhdir)                                                 //~v78rI~
    uerrmsg("CapsLock option default for this directory is Now %s",0,//~v78rI~
    		pc);                                                   //~v78rI~
  else                                                             //~v78rI~
    uerrmsg("CapsLock option is Now %s for %s",0,                  //~v71LI~
    		pc,funcstr);                                           //~v71LI~
    if (profsw>=0)                                                 //~v78rI~
    {                                                              //~v78rI~
      if (funcid==4)    //ext option                               //~v78rR~
		fcmdprofupdaterecord(FPURO_CAPS,pext,0/*strval*/,profsw,0);//~v78rI~
      else                                                         //~v78rI~
		fcmdprofupdaterecord(FPURO_CAPS,pfh->UFHfilename,0/*strval*/,profsw,0);//~v78rI~
    }                                                              //~v78rI~
	return 0;                                                      //~v69JI~
}//func_capslock                                                   //~v69JI~
//#if defined(LNX) && !defined(XXE)                                //~v69XR~
//#ifdef LNX                                                       //~v705R~
//**************************************************************** //~v69MI~
//!opt_rettol                                                      //~v69MI~
//**************************************************************** //~v69MI~
int opt_acs(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)             //~v69MI~
{                                                                  //~v69MI~
    UCHAR *pc;                                                     //~v69MI~
    int rc;                                                        //~v69MI~
//*********************************                                //~v69MI~
	if (!(pc=Ppcw->UCWparm))    //no parm,toggle status            //~v705R~
    {                                                              //~v69MI~
#if defined(LNX) && !defined(XXE)                                  //~v70mI~
    	if (UCBITCHK(Gopt5,GOPT5ACS))   //no use line drawing acs func//~v70mR~
        	pc=STR_ON;                                             //~v70mR~
        else                                                       //~v70mR~
        	pc=STR_OFF;                                            //~v70mR~
//        uerrmsg("Line Drawing Character display status is %s.",  //~v705R~
//                "罫線文字\x95\\示状況は %s",                     //~v705R~
//                pc);                                             //~v705R~
//        return 0;                                                //~v705R~
		uerrmsg("OPT LINECH {ON | OFF | RELOAD | filename} ;(current status=%s)",0,//~v70mR~
        			pc);                                           //~v70mI~
#else                                                              //~v70mI~
		uerrmsg("OPT LINECH {RELOAD | filename}",0);               //~v70mI~
#endif                                                             //~v70mM~
        return 0;                                                  //~v70mI~
    }                                                              //~v69MI~
//  rc=optoffonchk(pc,OPTOFC_ERRMSG);                              //~v705R~
    rc=optoffonchk(pc,0);   //no err msg                           //~v705I~
    if (rc>1)                                                      //~v69MI~
    {                                                              //~v705I~
		rc=funct2init(1,pc);                                       //~v705I~
        if (rc==1)                                                 //~v705I~
        {                                                          //~v705I~
            rc=0;                                                  //~v705I~
	    	scrfulldraw(Ppcw);                                     //~v705I~
        }                                                          //~v705I~
        else                                                       //~v705I~
        	rc=4;                                                  //~v705I~
    	return rc;                                                 //~v705R~
    }                                                              //~v705I~
#if defined(LNX) && !defined(XXE)                                  //~v70mM~
    if (rc)	//on                                                   //~v69MI~
    {                                                              //~v69MI~
    	if(UCBITCHK(Gopt5,GOPT5ACS))                               //~v69NR~
            return erralready();                                   //~v69MI~
    	UCBITON(Gopt5,GOPT5ACS);                                   //~v69NR~
		scracssetup(Gopt5 & GOPT5ACS);	//now acs mode             //~v69NR~
        pc=STR_ON;                                                 //~v69MI~
    }                                                              //~v69MI~
	else   //off                                                   //~v69MI~
    {                                                              //~v69MI~
    	if(!UCBITCHK(Gopt5,GOPT5ACS))                              //~v69NR~
            return erralready();                                   //~v69MI~
    	UCBITOFF(Gopt5,GOPT5ACS);                                  //~v69NR~
		scracssetup(Gopt5 & GOPT5ACS);	//now no acs mode          //~v69NR~
        pc=STR_OFF;                                                //~v69MI~
	}//opd                                                         //~v69MI~
    scrfulldraw(Ppcw);                                             //~v69MI~
	uerrmsg("Line Drawing Character option is set to %s",          //~v69NR~
            "罫線文字\x95\\示を %s に設定",                        //~v705R~
            pc);                                                   //~v69MI~
#else                                                              //~v70mI~
	uerrmsg("On/Off option is for Linux Console version only",     //~v70mI~
//          "On/OffオプションはLinuxコン\x83\\ール版用です",       //~v77vR~
            "On/OffオプションはLinuxコン\x83\\ール版用です");      //~v77vI~
//          pc);                                                   //~v77vR~
#endif                                                             //~v70mI~
	return 0;                                                      //~v69MI~
}//opt_acs                                                         //~v69MI~
//#endif                                                           //~v705R~
//**************************************************************** //~v44qI~
//!opthelp                                                         //~v44qI~
//* help msg                                                       //~v44qI~
//*parm1:none                                                      //~v44qI~
//*retrn:rc                                                        //~v44qI~
//**************************************************************** //~v44qI~
int opthelp(void)                                                  //~v44qI~
{                                                                  //~v44qI~
    char options[256];                                             //~v59XI~
    char options2[256];                                            //~v678I~
//********************                                             //~v59XI~
#ifdef UNX                                                         //~v678I~
//#if defined(LNX) && !defined(XXE)                                //~v69XR~
//#ifdef LNX                                                       //~v705R~
//  sprintf(options,"%s | %s | %s",                                //~v705R~
//  		Soptwtbl[0].UOWcmd,                                    //~v705R~
//  		Soptwtbl[3].UOWcmd,                                    //~v705R~
//			Soptwtbl[16].UOWcmd);                                  //~v705R~
//#else                                                            //~v705R~
    sprintf(options,"%s | %s",                                     //~v678I~
			Soptwtbl[0].UOWcmd,                                    //~v678I~
			Soptwtbl[3].UOWcmd);                                   //~v678I~
//#endif                                                           //~v705R~
#else                                                              //~v678I~
    sprintf(options,"%s | %s | %s | %s",                           //~v59XI~
			Soptwtbl[0].UOWcmd,                                    //~v59XI~
			Soptwtbl[1].UOWcmd,                                    //~v59XI~
			Soptwtbl[2].UOWcmd,                                    //~v59XI~
			Soptwtbl[3].UOWcmd);                                   //~v59XI~
#endif                                                             //~v678I~
//  sprintf(options2,"%s | %s | %s | %s | %s | %s %s", //for uerrmsg parm count limit//~v705R~
//  sprintf(options2,"%s | %s | %s [filename | %s] ... Hit Esc Key\n | %s | %s | %s | %s %s", //for uerrmsg parm count limit//~v736R~
//  sprintf(options2,"%s | %s | %s [filename | %s] ... Hit Esc Key\n | %s | %s | %s | %s | %s", //for uerrmsg parm count limit//~v78SR~
    sprintf(options2,"%s | %s | %s [filename | %s] ... Hit Esc Key\n | %s | %s | %s | %s | %s | %s", //for uerrmsg parm count limit//~v78SI~
			Soptwtbl[7].UOWcmd, //beep                             //~v678I~
			Soptwtbl[8].UOWcmd, //ctlcfunc                         //~v678I~
			Soptwtbl[16].UOWcmd,FUNCT_RELOAD,//linech              //~v705R~
			Soptwtbl[9].UOWcmd, //freecsr                          //~v678I~
			Soptwtbl[10].UOWcmd, //cbcopy                          //~v678I~
			Soptwtbl[12].UOWcmd, //cmdlog                          //~v678I~
			Soptwtbl[15].UOWcmd, //rettol                          //~v678I~
#ifdef UTF8UCS2                                                    //~va3sI~
			CONTINS " | " OPTCMD_COMBINE  " | " OPTCMD_LIGATURE,   //~va3sI~
#else                                                              //~va3sI~
			CONTINS,             //contins                         //~v78SI~
#endif                                                             //~va3sI~
			Soptwtbl[13].UOWcmd); //delz                           //~v678I~
#ifdef UNX                                                         //~v47NI~
  #ifdef XXE                                                       //~v64tI~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v678R~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~va06R~
    uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",//~va06I~
    		0,                                                     //~v64tI~
    		options,     //0,1,2,3                                 //~v64tI~
			Soptwtbl[6].UOWcmd,	//fd                               //~v64tI~
			Soptwtbl[4].UOWcmd,                                    //~v64tI~
//  		Soptwtbl[7].UOWcmd, //beep                             //~v678R~
//  		Soptwtbl[8].UOWcmd, //ctlcfunc                         //~v678R~
//  		Soptwtbl[9].UOWcmd, //freecsr                          //~v678R~
//  		Soptwtbl[10].UOWcmd, //cbcopy                          //~v678R~
//  		Soptwtbl[12].UOWcmd, //cmdlog                          //~v678R~
//  		Soptwtbl[13].UOWcmd, //delz                            //~v678R~
            options2,  //7,8,9,10,12,13                            //~v678I~
			Soptwtbl[14].UOWcmd, //rctl                            //~v64tI~
			Soptwtbl[11].UOWcmd, //foldID                          //~v64tI~
			Soptwtbl[5].UOWcmd);                                   //~v64tI~
  #else                                                            //~v64tI~
//  uerrmsg("opt { %s | %s | %s | %s | %s | %s [Upper|Lower] | %s eol-char} [ON|OFF]",//~v54SR~
//  uerrmsg("opt { %s | %s | %s | %s | %s | %s [Upper|Lower] | %s eol-char} [ON|OFF|RESET]",//~v54SR~
//  uerrmsg("opt { %s | %s | %s | %s | %s | %s [Upper|Lower] | %s | %s eol-char} [ON|OFF|RESET]",//~v55jR~
//  uerrmsg("opt { %s | %s | %s | %s | %s | %s [Upper|Lower] | %s | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v584R~
//  uerrmsg("opt { %s | %s | %s | %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v59XR~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v60mR~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v62GR~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v645R~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v678R~
//  uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v678I~//~va06R~
    uerrmsg("opt { %s | %s | %s [Upper|Lower] | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",//~va06I~
    		0,                                                     //~v47NI~
//  		Soptwtbl[0].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[1].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[2].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[3].UOWcmd,                                    //~v59XR~
    		options,     //0,1,2,3                                 //~v59XI~
			Soptwtbl[6].UOWcmd,                                    //~v47NI~
			Soptwtbl[4].UOWcmd,                                    //~v47NI~
//  		Soptwtbl[7].UOWcmd, //beep                             //~v678R~
//  		Soptwtbl[8].UOWcmd, //ctlcfunc                         //~v678R~
//  		Soptwtbl[9].UOWcmd, //freecsr                          //~v678R~
//  		Soptwtbl[10].UOWcmd, //cbcopy                          //~v678R~
//  		Soptwtbl[12].UOWcmd, //cmdlog                          //~v678R~
//  		Soptwtbl[13].UOWcmd, //delz                            //~v678R~
            options2,  //7,8,9,10,12,13                            //~v678I~
			Soptwtbl[11].UOWcmd, //foldID                          //~v60mI~
			Soptwtbl[5].UOWcmd);                                   //~v47NI~
  #endif //!XXE                                                    //~v64tI~
#else                                                              //~v47NI~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s eol-char} [ON|OFF]",//~v54SR~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s eol-char} [ON|OFF|RESET]",//~v54SR~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s | %s eol-char} [ON|OFF|RESET]",//~v55cR~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v55jR~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v584R~
//  uerrmsg("opt { %s | %s | %s | %s | %s [Upper|Lower] | %s | %s | %s | %s | | %s | %s eol-char} [ON|OFF|RESET]",//~v59XR~
//  uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s eol-char} [ON|OFF|RESET]",//~v60mR~
//  uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET]",//~v62mR~
//  uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",//~v62GR~
//  uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",//~v645R~
//  uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s | %s | %s | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",//~v678R~
    uerrmsg("opt { %s | %s [Upper|Lower] | %s | %s | %s fold-Id | %s eol-Id } [ON|OFF|RESET|KEEP]",
    		0,                                                     //~v44qI~
//  		Soptwtbl[0].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[1].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[2].UOWcmd,                                    //~v59XR~
//  		Soptwtbl[3].UOWcmd,                                    //~v59XR~
    		options,     //0,1,2,3                                 //~v59XI~
			Soptwtbl[4].UOWcmd,                                    //~v47dR~
//  		Soptwtbl[6].UOWcmd, //beep                             //~v678R~
    		Soptwtbl[14].UOWcmd, //RCTL                            //~v678I~
//  		Soptwtbl[7].UOWcmd, //beep                             //~v678R~
//  		Soptwtbl[8].UOWcmd, //ctlcfunc                         //~v678R~
//  		Soptwtbl[9].UOWcmd, //freecsr                          //~v678R~
//  		Soptwtbl[10].UOWcmd, //cbcopy                          //~v678R~
//  		Soptwtbl[12].UOWcmd, //cmdlog                          //~v678R~
//  		Soptwtbl[13].UOWcmd, //delz                            //~v678R~
            options2,  //7,8,9,10,12,13                            //~v678I~
			Soptwtbl[11].UOWcmd, //foldID                          //~v60mI~
			Soptwtbl[5].UOWcmd);                                   //~v47dI~
#endif                                                             //~v47NI~
//  return 4;                                                      //~v705R~
    return 0;                                                      //~v705I~
}//opthelp                                                         //~v44qI~
