//*CID://+vbBcR~:                             update#=  156;       //~vbBcR~
//*************************************************************
//* xeini2.c                                                    //~v04dR~
//************************************************************* //~v018I~
//vbBc:240910 support ebcidic cfg file cmdline parameter           //~vbBcI~
//vbv9:221124 add cid type apl for extension=.apl                  //~vbv9I~
//vb5b:160913 additional to vb54/vb56, DBCS space altch is changable by TAB cmd//~vb5bI~
//vb56:160904 write default ucs to xe.ini as comment of (E)/(J)Tab_disp_char//~vb56I~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vazd:150111 confirm large file open                              //~vazdI~
//vara:140213 change ini file terminal emulater cmd default comment//~varaI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//            EBCDIC_cfg parameter                                 //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            -char width can be modifyed by inifile option UnicodeTbl and UnicodeTbl_Console//~va20I~
//v793:080715 /Nrr option to reset RCT-newline                     //~v793I~
//v906:080601 (UTF8) unocode table specification by ini file       //~v906I~
//v78N:080521 (LNXCON)rctl support                                 //~v78NI~
//v76P:070922*(BUG)ini file parameter spell miss                   //~v76PI~
//v76t:070707 (Wine)try cmd /c for pause to create new session under wine for wxe//~v76tI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v765:070531 (LNX:BUG)support "Konsole" as one of X-terminal      //~v765I~
//            .enable to set terminal/shell pgm by ini file        //~v765I~
//v74N:070328 keep bnds parm for also filename                     //~v74NI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v52m:030903 add .java to cid groupe C(allow ext over 3 byte)     //~v52mI~
//v500:020827 wxe support                                          //~v500I~
//     020923 display transplation tbl for wxe                     //~v500I~
//v432:011013 (BUG)no numopt init missing for print cmd for lnn    //~v432I~
//v20G:001104 LINUX support:print cmd on ini for LINUX             //~v20GI~
//v13m:991031 no bell option support                               //~v13mI~
//v13g:991025 (BUG:WIN/DOS/GCC)xprint fail.(INI cmd write "(null)" to .ini)//~v13gI~
//v139:991023 (BUG) CID "//," is written on .ini,"//" is valid.but not serious problem.//~v139I~
//v0ih:980621 pfk cmd support(pfk table,add xefunc.h)              //~v0ihI~
//v0g0:971207 strstr is ambiguous for xprint cmdf compare          //~v0g0I~
//            default set on gbl(if printcmd!=0 set off)           //~v0g0I~
//v0fz:971201 print/xprint cmd on .ini for each os                 //~v0fzI~
//v0f1:971010 os2 new malloc dump logic;no need initial heap alloc //~v0f1I~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0a2:970705:allow 00 input                                       //~v0a2I~
//            valid ctl char tbl start from 0(also accept old version)//~v0a2I~
//v09X:970629:.ini tab display char parm                           //~v09UI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09UI~
//            accept ini parm                                      //~v09UI~
//v09F:970614:CID postfix support                                  //~v09FI~
//            .ini support postfix(ex. "//,??)                     //~v09FI~
//            (change CIDTBL fmt,cidfmt conatin only prefix and postfix)//~v09FI~
//v095:970405:DPMI version                                         //~v095I~
//            -not used variable                                   //~v095I~
//v07u:960916:chk printcmd string where xprint is used             //~v07uR~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v063I~
//v063:960217:sub shell prompt                                  //~v063I~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//            free opton from ini                               //~v05uI~
//v05a:951104:xprint cmd string by ini file                     //~v05aI~
//v051:951014:print dlcmd                                       //~v051I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v03n:950819:initial scroll option from xe.ini                //~v03nI~
//*v03h:950810:split from xeini.c                               //~v031I~
//*v031:950712:fixed cid variable apart from Scidtbl(alternative of v021)//~v031I~
//*v030:950709:dir proc avail flag on by 2nd line version id    //~v030I~
//*v021:950710:bug when no ini file(fixed CID process)          //~v021I~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~v01aI~
//*v018 950702:same ver/date to xe.ini and title msg            //~v018I~
//*            time edit by utimeedit                           //~v018I~
//*v015:950624 fixed cid parm                                   //~v01aI~
//*************************************************************
//*950603 write option except by cmd line parm(/yr etc)         //~v015I~
//*950528 customizable CID table                                //~5528I~
//*950527 UCBITCHK result the value not 1.                      //~5527I~
//*950506 Ctrl+char
//*950429 created
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <ualloc.h>
#include <uedit.h>                                              //~v018I~
#include <uproc.h>                                                 //~v0g0I~
#include <utrace.h>                                                //~v20GI~
#include <uftp.h>                                                  //~v76pI~
//#ifdef UTF8SUPP                                                    //~v906I~//~va20R~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf.h>                                                   //~v906I~
#endif                                                             //~v906I~
#ifdef LNX                                                         //~v78NI~
	#include <ukbdlnxc.h>                                          //~v78NI~
#endif                                                             //~v78NI~
#include <utf22.h>                                                 //~vb56I~

#include "xe.h"
#include "xescr.h"
#include "xeini.h"
#include "xeini2.h"                                             //~v031I~
#include "xefunc.h"                                                //~v0ihI~
#include "xekbd.h"                                              //~v031I~
#include "xefile.h"                                             //~5507I~
#include "xefile3.h"                                            //~v03nI~
#include "xefile4.h"                                            //~5528I~
#include "xefcmd23.h"                                              //~v74EI~
#include "xepan.h"                                              //~v03nI~
#include "xegbl.h"                                                 //~v76gI~
#include "xedlcmd.h"                                               //~v76gI~
#include "xedlcmd6.h"                                              //~v76gI~
#include "xedcmd2.h"                                               //~v76tI~
#include "xesub.h"                                                 //~v78NI~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
static UCHAR *Soptionid[]={
//  				"Tab_Skip",            //0                  //~v063R~
//    				"",                    //0                     //~v09UR~
    				"(J)Tab_disp_char",    //0                     //~v09UI~
 					"Command_Stack",       //1                  //~5528R~
//  				"Init_Heap_Block",     //2                     //~v0f1R~
    				"",                    //2                     //~v0f1I~
 					"Confirm_CANCEL",      //3                  //~5528R~
 					"Confirm_SAVE",        //4                  //~5528R~
 					"Confirm_UNDO",        //5                  //~5528R~
 					"Dump_When_Err",       //6                  //~5528R~
 					"R-Ctl_ENTER",         //7                  //~5528R~
//  				"Tab_Display",         //8                  //~v063R~
//  				"",                    //8                     //~v09UR~
    				"(E)Tab_disp_char",    //8                     //~v09UI~
 					"InsertLine_Indent",   //9                  //~5528R~
//  				"Add_Change_ID",       //10                 //~v063R~
//    				"",                    //10                    //~v09UR~
      				"DBCSspace_dispchar",  //10                    //~v09UR~
 					"Initial_Ins_Mode",    //11                 //~5528R~
 					"Box_Ins_Cursor",      //12                 //~5528R~
 					"EOF(^Z)_Write",       //13                 //~5528R~
 					"ASCII_only",          //14                 //~5528R~
 					"(J)Valid_Ctrl_char",  //15                 //~5528R~
 					"(E)Valid_Ctrl_char",  //16                 //~5528R~
 					"Change_ID_Type_C",    //17                 //~5528R~
 					"Change_ID_Type_ASM",  //18                 //~5528I~
 					"Change_ID_Type_DOC",  //19                 //~5528I~
 					"Change_ID_Type_4",    //20                 //~5528I~
 					"Change_ID_Type_5",    //21                 //~5528I~
 					"Change_ID_Type_6",    //22                 //~5528I~
 					"Change_ID_Type_7",    //23                 //~5528I~
 					"Change_ID_Type_8",    //24                 //~5528I~
 					"Change_ID_Type_9",    //25                 //~5528I~
 					"Fixed_CID_prefix",    //26                 //~v015I~
 					"Keyboard_Speed",      //27                 //~v01aI~
 					"Keyboard_Delay",      //28                 //~v01aI~
 					"Kbd_Speed_at_exit",   //29                 //~v01aI~
 					"Kbd_Delay_at_exit",   //30                 //~v01aI~
 					"DirList_Indent",      //31                 //~v03nI~
//  				"Scroll_Browse",       //32                 //~v063R~
//  				"Scroll_Edit",         //33                 //~v063R~
//  				"Scroll_DirList",      //34                 //~v063R~
    				"(J)Disp_trans_tbl",   //32                    //~v09UR~
    				"(E)Disp_trans_tbl",   //33                    //~v09UR~
    				"(J)Disp_trans_char",  //34                    //~v09UI~
 					"Print_Command",       //35                 //~v051I~
 					"XPrint_Command",      //36                 //~v05aI~
//  				"Undelete_option",     //37                 //~v063R~
    				"(E)Disp_trans_char",  //37                    //~v09UI~
 					"Sub_Shell_Init",      //38                 //~v063I~
 					"XPrint_Command_DOS",  //39                    //~v0fzI~
 					"XPrint_Command_GCC",  //40                    //~v0fzI~
 					"XPrint_Command_WIN",  //41                    //~v0fzI~
 					"XPrint_Command_OS2",  //42                    //~v0fzI~
 					"Print_Command_DOS",   //43                    //~v0fzI~
 					"Print_Command_GCC",   //44                    //~v0fzI~
 					"Print_Command_WIN",   //45                    //~v0fzI~
 					"Print_Command_OS2",   //46                    //~v0fzI~
 					"Beep",                //47                    //~v13mI~
 					"XPrint_Command_LNX",  //48                    //~v20GI~
 					"Print_Command_LNX",   //49                    //~v20GI~
    				"(J)Disp_tr_tb_wxe",   //50                    //~v500I~
    				"(E)Disp_tr_tb_wxe",   //51                    //~v500I~
 					"Bounds"          ,    //52                    //~v74ER~
 					"LNX_Subshell_xe",            //53             //~v765R~
 					"LNX_ShellTerm_gxe",      //54                 //~v765R~
 					"LNX_CmdTerm_gxe",        //55                 //~v765R~
 					"R-Ctl_NewLine",       //56                    //~v768I~
 					"CompareFile_Cmd",    //57                     //~v76gR~
 					"CompareDir_Cmd",     //58                     //~v76gR~
//  				"Search_Cmcd",        //59                     //~v76PR~
    				"Search_Cmd",         //59                     //~v76PI~
#ifndef AAA                                                        //~v76tI~
 					"WIN_Shell_wxe",      //60                     //~v76tR~
#endif                                                             //~v76tI~
#ifdef BBB                                                         //~v78NI~
 					"R-Ctl_String",      //61                      //~v78NI~
#else                                                              //~v78NI~
 					"LNX_Keymap",      //61  console version keymap file//~v78NI~
#endif                                                             //~v78NI~
 					"UnicodeTbl",        //62                      //~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
 					"UnicodeTbl_Console",  //63                    //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
 					XEEBC_INIFILEPARM,//64                         //~va50R~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
 					"LargeFileSize(MB)",        //65               //~vazdI~
                    0};
//*                       0,1,2,3,4,5,6,7,8,9,                  //~v015R~
static UCHAR Snonumopt[]={1,0,0,0,0,0,0,0,1,0,       //0x          //~v09UR~
                          1,0,0,0,0,0,0,0,0,0,       //1x          //~v09UR~
                          0,0,0,0,0,0,1,0,0,0,       //2x       //~v03nR~
                          0,0,1,1,1,1,1,1,1,1,       //3x          //~v0fzR~
                          1,1,1,1,1,1,1,0,1,1,       //4x          //~v500R~
//                        1,1                                      //~v765R~
                          1,1,1,1,1,1                //5x          //~v765R~
                          ,0                         //56          //~v768I~
                          ,1,1,1      //not numeric   //57,58,59   //~v76gR~
#ifndef AAA                                                        //~v76tI~
 					      ,1              //60                     //~v76tI~
#endif                                                             //~v76tI~
 					      ,1              //61                     //~v78NI~
 					      ,1              //62                     //~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
 					      ,1              //63                     //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
 					      ,1,      //64:no numeric parameter       //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
 					      0        //65:numeric parameter          //~vazdI~
                         };//no numeric value sw                //~v015R~
//static	char *Sxpcmd[5];//save for write                       //~v20GR~
//static	char *Spcmd[5];   //save for write                     //~v20GR~
#define MAX_PF_NO   6         //platform count                     //~v20GI~
static	char *Sxpcmd[MAX_PF_NO];//save for write                   //~v20GI~
static	char *Spcmd[MAX_PF_NO]; //save for write                   //~v20GI~
static  char *Slnxlshellpgmopt=0, //xe-console shell pgm for ">" cmd//~v765R~
			 *Slnxxtermshell=0, //gxe terminal for ">" cmd         //~v765R~
			 *Slnxxtermcmd=0; //gxe terminal for ">cmd" cmd        //~v765R~
#ifdef BBB                                                         //~v78NI~
#define MAX_RCTLSTR 4 //=FKT_MAX_STR                               //~v78NR~
static char *Sprctlstr[MAX_RCTLSTR];                               //~v78NR~
static int   Srctlstrno;                                           //~v78NI~
#else                                                              //~v78NI~
static char Skeymapfile[_MAX_PATH];                                //~v78NR~
#endif                                                             //~v78NI~
static  char *Sutftb=0; //unicodetbl                               //~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
static  char *Sutftbcons=0; //unicodetbl for console version       //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
static  char *Sebccfg=0; //unicodetbl for console version          //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
//*******************************************************          //~v0fzM~
void iniwcid(FILE *Pfh);                                        //~5528R~
int inircid(int Pindex,int Pcolumn,int Popdno,UCHAR *Ppopd);    //~5528I~
int inirfixcid(int Popdno,UCHAR *Ppopd);                        //~v015I~
int inirtranstbl(UCHAR *Ptranstbl,UCHAR *Pfisrtsw,UCHAR *Pdata);   //~v09UI~
int inirtranschar(UCHAR *Ptranschar,UCHAR *Pdata);                 //~v09UR~
int inirtabdispchar(UCHAR *Ptranschar,UCHAR *Pdata);               //~v09UI~
int inirbnds(UCHAR *Ppopd);                                        //~v74EI~
int iniwbnds(FILE* Pfh);                                           //~v74EI~
int inirctlstring(FILE* Ppfh,char *Pstring);                       //~v78NI~
//**************************************************               //~v0fzI~
//*ini2term                                                        //~v0fzI~
//* term proc(ufree),called from gblterm                           //~v0fzI~
//*parm :none                                                      //~v0fzI~
//*ret  :none                                                      //~v0fzI~
//**************************************************               //~v0fzI~
void ini2term(void)                                                //~v0fzR~
{                                                                  //~v0fzI~
	int ii;                                                        //~v0fzI~
    char *pc;                                                      //~v0fzI~
//*********************************                                //~v0fzI~
//  for (ii=0;ii<5;ii++)                                           //~v432R~
    for (ii=0;ii<MAX_PF_NO;ii++)                                   //~v432I~
    {                                                              //~v0fzI~
		if (pc=Sxpcmd[ii],pc)                                      //~v0fzI~
			ufree(pc);                                             //~v0fzI~
		if (pc=Spcmd[ii],pc)                                       //~v0fzI~
			ufree(pc);                                             //~v0fzI~
	}                                                              //~v0fzI~
    if ((pc=Slnxlshellpgmopt),pc)                                  //~v768R~
		ufree(pc);                                                 //~v765I~
    if ((pc=Slnxxtermshell),pc)                                    //~v768R~
		ufree(pc);                                                 //~v765I~
    if ((pc=Slnxxtermcmd),pc)                                      //~v768R~
		ufree(pc);                                                 //~v765I~
    if ((pc=Gcomparecmdf),pc)                                      //~v76gI~
		ufree(pc);                                                 //~v76gI~
    if ((pc=Gcomparecmdd),pc)                                      //~v76gI~
		ufree(pc);                                                 //~v76gI~
    if ((pc=Ggrepcmd),pc)                                          //~v76gI~
		ufree(pc);                                                 //~v76gI~
#ifndef AAA                                                        //~v76tI~
    if ((pc=Gdcmd2wxeshellcmd),pc)                                 //~v76tI~
		ufree(pc);                                                 //~v76tI~
#endif                                                             //~v76tI~
#ifdef BBB                                                         //~v78NI~
	for (ii=0;ii<Srctlstrno;ii++)                                  //~v78NI~
		UFREEIFNZ(Sprctlstr[ii]);                                  //~v78NI~
#endif                                                             //~v78NI~
	if (pc=Sutftb,pc)                                              //~v906I~
		ufree(pc);                                                 //~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
	UFREEIFNZ(Sutftbcons);                                         //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	UFREEIFNZ(Sebccfg);                                            //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
	return;                                                        //~v0fzI~
}                                                                  //~v0fzI~
//**************************************************
//*iniwother
//* write other parameter
//*parm1:output filename
//*parm2:output FILE *
//*parm3:section id string                                      //~v031I~
//*ret  :rc
//**************************************************
int iniwother(UCHAR *Pfilename,FILE *Pfh,UCHAR *Psectionid)     //~v031R~
{
	int ii,jj;                                                  //~5506R~
    int kk,transsw,transsw2;                                       //~v09UR~
    UCHAR transtbl[17];                                            //~v09UI~
    UCHAR ctlcharopt[33],*validchartbl,*pc1,*pc2;               //~5506I~
static UCHAR Snum3edit[]="\n %-18s=%3d  #(%3d)#%s";             //~v01aI~
//static UCHAR Scharedit[]="\n %-18s=%4s #(%s)#%s";                //~v095R~
static UCHAR Scharedit2[]="\n %-18s=\"%s\" #(\"%s\")#%s"; //print cmd//~v051I~
static UCHAR Shexedit[]="\n %-18s=%02X #(%02X)#%s";                //~v09UI~
static UCHAR Shexedit2[]="\n %-18s=%04X #(%04X)#%s";               //~v09UI~
	char *punpdisptbl[4];                                          //~v500R~
    int idx;                                                       //~v500I~
#ifdef LNX                                                         //~v765I~
//  char editwk1[256],editwk2[256];                                //~varaR~
#endif                                                             //~v765I~
//*********************************
    punpdisptbl[0]=Gunpdispchartblj;         //japanese            //~v500I~
	punpdisptbl[1]=Gunpdispchartble;         //english             //~v500I~
    punpdisptbl[2]=Gunpdispchartblj_wxe;         //wxe japanese    //~v500I~
	punpdisptbl[3]=Gunpdispchartble_wxe;         //wxe english     //~v500I~
	fprintf(Pfh,"\n##### Other parameter #################################################\n");
	fprintf(Pfh,"##### Format: Keyword  = value    #(default value)# comment           #\n");//~5502R~
	fprintf(Pfh,"#####    Keyword      : see .doc%39s\n","#");  //~5514R~
	fprintf(Pfh,"#####    value        : see comment%36s\n","#");//~5503R~
	fprintf(Pfh,"%s\n",Psectionid);                             //~v031R~

//  fprintf(Pfh,"\n %-18s=%3d  #(%3d)# Tab skip position\n",    //~v063R~
//  		Soptionid[0],Gfiletabskip,TABSKIPCOUNT);            //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%3d)# input command stack count\n",//~5502R~
			Soptionid[1],Gcmdmaxstack,CMDMAXSTACK);
//	fprintf(Pfh,"\n %-18s=%3d  #(%3d)# initial 64KB heap block count(OS/2 only)\n",//~v0f1R~
//			Soptionid[2],Ginitheap,INITIALHEAP);                   //~v0f1R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# Confirm when CANCEL file update\n",//~5502R~
			Soptionid[3],!UCBITCHK(Gopt,GOPTCANCELNOCONF),1);   //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# Confirm when replace file by SAVE\n",//~5502R~
			Soptionid[4],!UCBITCHK(Gopt,GOPTSAVENOCONF),1);     //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# Confirm when UNDO file update\n",//~5502R~
			Soptionid[5],!UCBITCHK(Gopt,GOPTUNDONOCONF),1);     //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# write dump when err detected\n",//~5502R~
			Soptionid[6],!UCBITCHK(Gopt,GOPTNOABENDIFERREXIT),1);//~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# use Right-Ctrl key as Enter\n",//~5502R~
			Soptionid[7],UCBITCHK(Gopt,GOPTRCTLENTER)!=0,0);    //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# use Right-Ctrl key as NewLine if %s=1\n",//~v768I~
//  		Soptionid[56],(Gotheropt & GOTHERO_RCTLNL)!=0,0,Soptionid[7]);//~v793R~
    		Soptionid[56],(Gotheropt & GOTHERO_SVOPTNL)!=0,0,Soptionid[7]);//~v793I~
    inirctlstring(Pfh,0);        //write                           //~v78NR~
//  fprintf(Pfh,"\n %-18s=%3d  #(%d)# Tab char display\n",      //~v063R~
//  		Soptionid[8],UCBITCHK(Gopt,GOPTTABDISPLAY)!=0,0);   //~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# indentation at line insert\n",//~5502R~
			Soptionid[9],!UCBITCHK(Gopt2,GOPT2LINOINDENT),1);   //~v063R~
//  fprintf(Pfh,"\n %-18s=%3d  #(%d)# add CID on updated line\n",//~v063R~
//  		Soptionid[10],!UCBITCHK(Gopt2,GOPT2NOCID),1);       //~v063R~
    iniwcid(Pfh);	//write cid tbl                             //~5528I~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# Initialy 0:Rep mode, 1:Ins mode \n",//~5503R~
			Soptionid[11],UCBITCHK(Gopt2,GOPT2INITINSMODE)!=0,0);//~v063R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# 0:Box Cursor if Rep mode, 1:if Ins mode\n",//~5503R~
			Soptionid[12],!UCBITCHK(Gopt2,GOPT2BOXREPCSR),1);   //~v063R~
	if (UCBITCHK(Gopt2,GOPT2EOFWRITE))                          //~v063R~
    	ii=1;                                                   //~5502I~
    else                                                        //~5502I~
		if (UCBITCHK(Gopt2,GOPT2EOFDROP))                       //~v063R~
        	ii=0;                                               //~5502I~
		else                                                    //~5502I~
			if (UCBITCHK(Gopt2,GOPT2EOFWIFNEW))                 //~v063R~
	        	ii=2;                                           //~5502R~
			else                                                //~5502I~
	        	ii=3;                                           //~5502I~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# 0:Drop EOF, 1:Write EOF", //~5503R~
			Soptionid[13],ii,3);                                //~5502I~
	fprintf(Pfh,"\n#%29s 2:Same as input(write for new file)","#");//~5505R~
	fprintf(Pfh,"\n#%29s 3:Same as input(not write for new file)\n","#");//~5505R~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# 0:Ctrl char input 0:accept, 1:reject\n",//~5506R~
			Soptionid[14],UCBITCHK(Gopt2,GOPT2REJECTCTLCHAR)!=0,0);//~v063R~
//beep                                                             //~v13mI~
	fprintf(Pfh,"\n %-18s=%3d  #(%d)# 0:Beep off, 1:Beep on\n",    //~v13mI~
			Soptionid[47],!UCBITCHK(Gopt4,GOPT4NOBEEP),1);         //~v13mI~
//unicode tbl file                                                 //~v906I~
//  fprintf(Pfh,Scharedit2,Soptionid[61],                          //~v906R~
    fprintf(Pfh,Scharedit2,Soptionid[62],                          //~v906I~
    			(Sutftb?Sutftb:""),                                //~v906I~
				"",                                                //~v906I~
            	" Unicode Codepoint File:SBCS/DBCS/Unprintable specification");//~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
    fprintf(Pfh,Scharedit2,Soptionid[63],                          //~va20I~
    			(Sutftbcons?Sutftbcons:""),                        //~va20I~
				"",                                                //~va20I~
            	" Unicode Codepoint File for console version");    //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    fprintf(Pfh,Scharedit2,Soptionid[64],                          //~va50I~
    			(Sebccfg?Sebccfg:""),                              //~va50I~
				XEEBC_DEFAULTCFGFILE,                              //~va50I~
            	" EBCDIC translation config filename");            //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
//ctl cahr                                                      //~5506I~
//  fprintf(Pfh,"\n#List of char   Ctrl+abcdefghijklmnopqrstuvwxyz[\\]6-\n");//~v0a2R~
    fprintf(Pfh,"\n#Valid Char Tbl(hex) 0123456789ABCDEF0123456789ABCDEF");//~v0a2R~
    fprintf(Pfh,"\n# Ctrl Key comb=Ctrl+2abcdefghijklmnopqrstuvwxyz[\\]6-\n");//~v0a2I~
	validchartbl=kbdgetchartbl(2);//japanese                    //~5506R~
    for (jj=0;jj<2;jj++)                                        //~5506I~
    {                                                           //~5506I~
//  	for (ii=1,pc1=ctlcharopt,pc2=validchartbl+1;ii<32;ii++,pc1++,pc2++)//~v0a2R~
    	for (ii=0,pc1=ctlcharopt,pc2=validchartbl;ii<32;ii++,pc1++,pc2++)//~v0a2R~
    		*pc1=(UCHAR)(*pc2+0x30);                                     //~5506I~
   		*pc1=0;                                                 //~5603R~
		fprintf(Pfh," %-18s= %s\n",                             //~5507R~
				Soptionid[15+jj],ctlcharopt);                   //~5506R~
		validchartbl=kbdgetchartbl(1);//english                 //~5506R~
    }                                                           //~5506I~
//Display translate tbl                                            //~v09UI~
	fprintf(Pfh,"\n#Display Trans Table      0123456789ABCDEF\n"); //~v09UR~
//  pc1=Gunpdispchartblj;         //japanese                       //~v500R~
//  for (jj=0;jj<2;jj++)                                           //~v500R~
    for (jj=0;jj<4;jj++)                                           //~v500I~
    {                                                              //~v09UI~
        if (jj<2)                                                  //~v500I~
            idx=32;                                                //~v500I~
        else                                                       //~v500I~
            idx=50-2;     //wxe                                    //~v500R~
		pc1=punpdisptbl[jj];                                       //~v500I~
    	transsw2=0;			//once write sw                        //~v09UI~
    	for (kk=0;kk<16;kk++)                                      //~v09UI~
        {                                                          //~v09UI~
        	transsw=0;                                             //~v09UI~
            pc2=transtbl;                                          //~v09UI~
        	for (ii=0;ii<16;ii++,pc1++,pc2++)                      //~v09UR~
            	if (*pc1)                                          //~v09UI~
                {                                                  //~v09UI~
                	*pc2='1';	                                   //~v09UI~
                    transsw=1;                                     //~v09UI~
                }                                                  //~v09UI~
                else                                               //~v09UI~
                	*pc2='0';	                                   //~v09UI~
			*pc2=0;		//delm                                     //~v09UI~
            if (transsw)                                           //~v09UI~
            {                                                      //~v09UI~
	    		fprintf(Pfh," %-18s= %X0 = %s\n",                  //~v09UI~
//  					Soptionid[32+jj],kk,transtbl);             //~v500R~
    					Soptionid[idx+jj],kk,transtbl);            //~v500I~
		    	transsw2=1;			//once write sw                //~v09UI~
			}                                                      //~v09UI~
        }                                                          //~v09UI~
        if (!transsw2)		//need a line for all 0                //~v09UI~
    		fprintf(Pfh," %-18s= %X0 = %s\n",                      //~v09UI~
//  					Soptionid[32+jj],0,transtbl);              //~v500R~
    					Soptionid[idx+jj],0,transtbl);             //~v500I~
//  	pc1=Gunpdispchartble;         //japanese                   //~v500R~
//      if (!jj)                                                   //~v500R~
        if (jj<3)	//not last                                     //~v500R~
			fprintf(Pfh,"\n");                                     //~v09UR~
    }                                                              //~v09UI~
//display trans char                                               //~v09UI~
	fprintf(Pfh,Shexedit,Soptionid[34],Gunpdispchar[2],UNPCHARDISPXJ,//~v09UI~
            " display char for Japanese mode un-displayable char");//~v09UR~
	fprintf(Pfh,". (FF means U-%04x)",utfgetvisiblealtch(UTFGVACO_UNP,DEFAULT_ALTCH));//~vb56I~
	fprintf(Pfh,Shexedit,Soptionid[37],Gunpdispchar[1],UNPCHARDISPXE,//~v09UI~
//          " display char for English  mode un-displayable char\n");//~vb56R~
            " display char for English  mode un-displayable char");//~vb56I~
	fprintf(Pfh,". (FF means U-%04x)\n",utfgetvisiblealtch(UTFGVACO_UNP,DEFAULT_ALTCH));//~vb56R~
//tab display char                                                 //~v09UI~
	ii=(Gtabdispchar[2]<<8)+Gtabdispchar[3];                       //~v09UI~
	jj=(TABCHARDISPX1J<<8)+TABCHARDISPX2J;                         //~v09UI~
	fprintf(Pfh,Shexedit2,Soptionid[0],ii,jj,                      //~v09UI~
            " Tab display char for Japanese mode");                //~v09UI~
	fprintf(Pfh,". (FFFF means U-%04x & U-%04x)",UTF22_TABALT1,UTF22_TABALT2);//~vb56R~
	ii=(Gtabdispchar[0]<<8)+Gtabdispchar[1];                       //~v09UI~
	jj=(TABCHARDISPX1E<<8)+TABCHARDISPX2E;                         //~v09UI~
	fprintf(Pfh,Shexedit2,Soptionid[8],ii,jj,                      //~v09UI~
            " Tab display char for English  mode");                //~v09UI~
	fprintf(Pfh,". (FFFF means U-%04x & U-%04x)",UTF22_TABALT1,UTF22_TABALT2);//~vb56R~
	fprintf(Pfh,"\n");                                             //~v09UI~
	fprintf(Pfh,Shexedit,Soptionid[10],Gunpdispchar[3],DBCSSPACEDISP,//~v09UI~
//          " DBCS space display char(Japanese mode only)");       //~v09UM~//~vb3qR~
//          " DBCS space display char(only for Codepoint:Japanese file)");//~vb5bR~
            " DBCS space display char");                           //~vb5bI~
	fprintf(Pfh,". (FF means U-%04x)",UTF22_DBCSSPACEALT);         //~vb5bI~
	fprintf(Pfh,"\n");                                             //~v09UI~
//kbd rate                                                      //~v01aI~
	fprintf(Pfh,Snum3edit,Soptionid[27],Gkbdspeed,KBDSPEED,     //~v01aI~
            " char count per second(2-->30)        ||v01a\n");  //~v01aR~
	fprintf(Pfh,Snum3edit+1,Soptionid[28],Gkbddelay,KBDDELAY,   //~v01aR~
            " milisecond (250-->1000)              ||v01a\n");  //~v01aR~
	fprintf(Pfh,Snum3edit+1,Soptionid[29],Gkbdspeed2,KBDSPEED,  //~v01aR~
            " Speed at exit editor (2-->30)        ||v01a\n");  //~v01aR~
	fprintf(Pfh,Snum3edit+1,Soptionid[30],Gkbddelay2,KBDDELAY,  //~v01aR~
            " Delay at exit editor (250-->1000)    ||v01a\n");  //~v01aR~
//dir list indentation                                          //~v03nI~
	fprintf(Pfh,Snum3edit,                                      //~v051R~
			Soptionid[31],UCBITCHK(Gopt3,GOPT3DIRLISTINDENT)!=0,1,//~v063R~
            " Directory List Indentation           ||v03n\n");  //~v03nR~
//dir list delete mode                                          //~v05uR~
//  fprintf(Pfh,Snum3edit,                                      //~v063R~
//  		Soptionid[37],                                      //~v063R~
//  		(Gopt3 & (GOPT3UNDELFREE|GOPT3UNDELLEAVE))/GOPT3UNDELFREE,//~v063R~
//  		GOPT3UNDELFREE/GOPT3UNDELFREE,                      //~v063R~
//          "(0:Off 1:On 2:Keep)                   ||v05u\n");  //~v063R~
//initial scroll                                                //~v03nI~
//  fprintf(Pfh,Scharedit,                                      //~v063R~
//  		Soptionid[32],                                      //~v063R~
//  		filegetscrollid(Ginitscroll[GSCROLLBROWSE]),        //~v063R~
//  		filegetscrollid(UPCSCROLLHALF),	//page              //~v063R~
//          " Initial Scroll Volume for BROWSE    ||v03n\n");   //~v063R~
//  fprintf(Pfh,Scharedit+1,                                    //~v063R~
//  		Soptionid[33],                                      //~v063R~
//  		filegetscrollid(Ginitscroll[GSCROLLEDIT]),          //~v063R~
//  		filegetscrollid(UPCSCROLLHALF),	//half              //~v063R~
//          " Initial Scroll Volume for EDIT      ||v03n\n");   //~v063R~
//  fprintf(Pfh,Scharedit+1,                                    //~v063R~
//  		Soptionid[34],                                      //~v063R~
//  		filegetscrollid(Ginitscroll[GSCROLLDIR]),           //~v063R~
//  		filegetscrollid(UPCSCROLLHALF),	//page              //~v063R~
//          " Initial Scroll Volume for DIRECTORY ||v03n\n");   //~v063R~
//xprint command                                                //~v05aI~
    if (!(pc1=Sxpcmd[0]))                                          //~v13gI~
    	pc1="";                                                    //~v13gI~
	fprintf(Pfh,Scharedit2,                                     //~v05aI~
			Soptionid[36],                                      //~v05aI~
//  		Gxprintcmd,                                            //~v0fzR~
//  		Sxpcmd[0],                                             //~v13gR~
    		pc1,                                                   //~v13gI~
			Gxprintcmd0,                                        //~v05aI~
//          " XP command ||v051\n");                               //~v0fzR~
            " XP command");                                        //~v0fzI~
//  for (ii=0;ii<4;ii++)                                           //~v20GR~
    for (ii=0;ii<MAX_PF_NO-1;ii++)                                 //~v20GI~
    {                                                              //~v0fzI~
    	if (!(pc1=Sxpcmd[1+ii]))                                   //~v0fzI~
    		pc1="";                                                //~v0fzI~
      if (ii>=MAX_PF_NO-2)                                         //~v20GI~
		fprintf(Pfh,Scharedit2,                                    //~v20GI~
				Soptionid[48],                                     //~v20GI~
    			pc1,                                               //~v20GI~
    			"",                                                //~v52mR~
            	" XP command");                                    //~v20GI~
      else                                                         //~v20GI~
		fprintf(Pfh,Scharedit2,                                    //~v0fzI~
				Soptionid[39+ii],                                  //~v0fzI~
    			pc1,                                               //~v0fzR~
				"",                                                //~v0fzI~
            	" XP command");                                    //~v0fzR~
	}                                                              //~v0fzI~
	fprintf(Pfh,"\n");                                             //~v0fzI~
//print command                                                 //~v051I~
//  if (!(pc1=Gprintcmd))                                          //~v0fzR~
    if (!(pc1=Spcmd[0]))                                           //~v0fzI~
    	pc1="";                                                    //~v0fzR~
	fprintf(Pfh,Scharedit2,                                     //~v051I~
			Soptionid[35],                                      //~v051I~
    		pc1,                                                   //~v0fzR~
			"",				//null default                      //~v051I~
//          " Print command string ||v051\n");                     //~v0fzR~
            " Print command string");                              //~v0fzI~
//  for (ii=0;ii<4;ii++)                                           //~v20GR~
    for (ii=0;ii<MAX_PF_NO-1;ii++)                                 //~v20GI~
    {                                                              //~v0fzI~
    	if (!(pc1=Spcmd[1+ii]))                                    //~v0fzI~
    		pc1="";                                                //~v0fzI~
      if (ii>=MAX_PF_NO-2)                                         //~v20GI~
		fprintf(Pfh,Scharedit2,                                    //~v20GI~
				Soptionid[49],                                     //~v20GI~
    			pc1,                                               //~v20GI~
				"",                                                //~v20GI~
                " Print command string");                          //~v20GI~
      else                                                         //~v20GI~
		fprintf(Pfh,Scharedit2,                                    //~v0fzI~
				Soptionid[43+ii],                                  //~v0fzI~
    			pc1,                                               //~v0fzR~
				"",                                                //~v0fzI~
                " Print command string");                          //~v0fzR~
    }                                                              //~v0fzI~
	fprintf(Pfh,"\n");                                             //~v0fzI~
                                                                   //~v0fzI~
//sub shell init cmd                                            //~v063I~
	fprintf(Pfh,Scharedit2,                                     //~v063I~
			Soptionid[38],                                      //~v063I~
			Gshellicmd,   //shell init cmd                      //~v063I~
			Gshellicmd0,                                        //~v063I~
            " sub shell init cmd||v063\n");                     //~v063I~
    pc1=(Slnxlshellpgmopt?Slnxlshellpgmopt:"");                    //~v765R~
	fprintf(Pfh,Scharedit2,                                        //~v765I~
			Soptionid[53],                                         //~v765I~
			pc1, //xe-console shell pgm for ">" cmd                //~v765R~
			"",      //no default                                  //~v765I~
            " xe(Linux-curses) shell pgm name for \">\" cmd. default=(dash?bash:sh)");//~v765R~
    pc1=(Slnxxtermshell?Slnxxtermshell:"");                        //~v765R~
	fprintf(Pfh,Scharedit2,                                        //~v765I~
			Soptionid[54],                                         //~v765I~
			pc1, //gxe terminal for ">" cmd                        //~v765R~
			"",      //no default                                  //~v765I~
            " gxe(Linux-gtk) sub terminal start cmd.\n");          //~v765R~
#ifdef LNX                                                         //~v765I~
//  ulnxxgettermpgmopt(XGTP_GETDEFAULT|1,0,editwk1); //0:case when open shell prompt//~varaR~
//  ulnxxgettermpgmopt(XGTP_GETDEFAULT|2,0,editwk2);               //~varaR~
//  fprintf(Pfh,"#                           # default is \"%s\" if found else \"%s\"",editwk1,editwk2);//~varaR~
    fprintf(Pfh,"#                           # default depends terminal emulator installed. See xee.txt");//~varaI~
#endif                                                             //~v765I~
    pc1=(Slnxxtermcmd?Slnxxtermcmd:"");                            //~v765R~
	fprintf(Pfh,Scharedit2,                                        //~v765I~
			Soptionid[55],                                         //~v765I~
			pc1, //gxe terminal for ">cmd" cmd                     //~v765R~
			"",      //no default                                  //~v765I~
            " gxe(Linux-gtk) string to process shell cmd.\n");     //~v765R~
#ifdef LNX                                                         //~v765I~
//  ulnxxgettermpgmopt(XGTP_GETDEFAULT|1,"",editwk1); //"":case when cmd execute//~varaR~
//  ulnxxgettermpgmopt(XGTP_GETDEFAULT|2,"",editwk2);              //~varaR~
//  fprintf(Pfh,"#                           # default is \"%s\" if found else \"%s\"",editwk1,editwk2);//~varaR~
    fprintf(Pfh,"#                           # default depends terminal emulator installed. See xee.txt");//~varaI~
#endif                                                             //~v765I~
	fprintf(Pfh,"\n");                                             //~v76gI~
    pc1=(Gcomparecmdf?Gcomparecmdf:"");                            //~v76gI~
	fprintf(Pfh,Scharedit2,                                        //~v76gI~
			Soptionid[57],                                         //~v76gI~
			pc1,                                                   //~v76gI~
			COMPARETOOL,      //no default                         //~v76gI~
            " File compare cmd.");                                 //~v76gR~
    pc1=(Gcomparecmdd?Gcomparecmdd:"");                            //~v76gI~
	fprintf(Pfh,Scharedit2,                                        //~v76gI~
			Soptionid[58],                                         //~v76gI~
			pc1,                                                   //~v76gI~
			COMPARETOOLDIR,      //no default                      //~v76gR~
            " Directory compare cmd.");                            //~v76gR~
    pc1=(Ggrepcmd?Ggrepcmd:"");                                    //~v76gI~
	fprintf(Pfh,Scharedit2,                                        //~v76gI~
			Soptionid[59],                                         //~v76gI~
			pc1,                                                   //~v76gI~
			GREPTOOL,      //no default                            //~v76gI~
            " String search cmd.\n");                              //~v76gI~
//*bounds                                                          //~v74ER~
    iniwbnds(Pfh);                                                 //~v74EM~
	fprintf(Pfh,Snum3edit,Soptionid[65],(int)(Glargefilesz/(1024*1024)),(int)(LARGEFILESZ/(1024*1024)),//~vazdI~
            " Size of large file to issue warning when open, 0 means no limit. ||vazd\n");//~vazdR~
	return 0;
}//iniwother

//**************************************************            //~5528I~
//*iniwcid                                                      //~5528I~
//* write cid tbl                                               //~5528I~
//*parm1:output file handle                                     //~5528I~
//*ret  :none                                                   //~5528I~
//**************************************************            //~5528I~
void iniwcid(FILE *Pfh)                                         //~5528R~
{                                                               //~5528I~
	CIDTBL *pcidtbl;	                                        //~5528I~
    int ii;                                                     //~5528I~
    UCHAR exttbl[CIDEXTTBLSZ],*pc;                                 //~v09FR~
    UCHAR postfixw[1+LINEPOSTFIXLEN+1];                            //~v09FR~
static UCHAR *Swcidfmt=" %-18s=%3d = \"%c%c%s\" = %s\n";           //~v09FR~
static UCHAR *SwcidfmtUnicode=" %-18s=%3d = u-%04x = %s\n";        //~vbv9I~
static UCHAR *Swfixcidfmt="\n %-18s= \"%s\"     # prefix ID of fixed CID(max 15byte)||v015\n";//~v031R~
//*********************************                             //~5528I~
	fprintf(Pfh,"\n#Change ID format specification table\n");   //~5528R~
	fprintf(Pfh,"##### Format: Type = start column=\"CID top 2 byte\"=extention list,...\n");//~5528R~//~5528R~

	fprintf(Pfh,"#####   To delete pre-defined entry,Set start column to 0\n");//~5528I~
	pcidtbl=filegetcidtbl();                                    //~5528I~
	for (ii=0;ii<MAXCIDTBL;pcidtbl++,ii++)                      //~5528R~
    {                                                           //~5528I~
    	*exttbl=0;                                              //~5528I~
        if (pcidtbl->CIDTid)                                    //~5528I~
        {                                                       //~5528I~
			pc=pcidtbl->CIDTexttbl;                             //~5528R~
        	while(*pc)                                          //~5528R~
        	{                                                   //~5528R~
        		strcat(exttbl,pc);                              //~5528R~
            	pc+=strlen(pc)+1;	                            //~5528R~
            	if (*pc)                                        //~5528R~
 		       		strcat(exttbl,",");                         //~5528R~
        	}                                                   //~5528R~
//          if (pcidtbl->CIDTcidfmt+2)                             //~v139R~
            if (*(pcidtbl->CIDTcidfmt+2))                          //~v139I~
            {	                                                   //~v09FI~
	            *postfixw=',';                                     //~v09FI~
                strcpy(postfixw+1,pcidtbl->CIDTcidfmt+LINEPREFIXLEN);//~v09FR~
			}                                                      //~v09FI~
            else                                                   //~v09FI~
	            *postfixw=0;                                       //~v09FI~
         if (pcidtbl->CIDTucs==0)                                  //~vbv9R~
			fprintf(Pfh,Swcidfmt,                                  //~vbv9I~
					Soptionid[ii+17],                              //~vbv9I~
					(int)pcidtbl->CIDTpos+1,                       //~vbv9I~
					*pcidtbl->CIDTcidfmt,                          //~vbv9I~
					*(pcidtbl->CIDTcidfmt+1),                      //~vbv9I~
                    postfixw,                                      //~vbv9I~
					exttbl);                                       //~vbv9I~
         else                                                      //~vbv9I~
			fprintf(Pfh,SwcidfmtUnicode,                               //~5528R~//~vbv9R~
					Soptionid[ii+17],                           //~5528R~
					(int)pcidtbl->CIDTpos+1,                    //~5528M~
					pcidtbl->CIDTucs,                              //~vbv9R~
					exttbl);                                    //~5528R~
		}	//used entry                                        //~5528I~
		else 	//free entry                                    //~5528I~
			fprintf(Pfh,Swcidfmt,                               //~5528I~
					Soptionid[ii+17],                           //~5528I~
					0,   		//column                        //~5528I~
					' ',        //CID 1                         //~5528R~
					' ',        //CID 2                         //~5528R~
                    "",                                            //~v09FI~
					" # You can use this entry");               //~5528I~
	}                                                           //~5528I~
//*last is for fix cid entry                                    //~v015I~
	fprintf(Pfh,Swfixcidfmt,                                    //~v015I~
				Soptionid[ii+17],                               //~v015I~
				Gfixcidid);                                     //~v031R~
	return;                                                     //~5528I~
}//iniwcid                                                      //~5528I~
                                                                //~5528I~
//**************************************************
//*inirother
//* other parameter section line process
//*parm1:parsed word number                                     //~v031R~
//*parm2:read area                                              //~v031I~
//*ret :rc
//**************************************************
int inirother(int Pwordno,UCHAR *Pbuff)                         //~v031R~
{
    UCHAR **ppc,*pc;                                            //~5506R~
    int ii,value,rc=0;                                          //~5528R~
    int jj;                                                        //~v0a2I~
	UCHAR *validchartbl;                                        //~5506I~
//static UCHAR Stranssw[2];   //trans table first time sw          //~v500R~
static UCHAR Stranssw[4];   //trans table first time sw            //~v500I~
    int defossw,saveindex; 		     //xprint/print cmd defaultsw  //~v0fzR~
#ifdef UTF8UCS2                                                    //~va20I~
	UCHAR fpath[_MAX_PATH];                                        //~va20I~
#endif                                                             //~va20I~
//*********************************
    if (Pwordno==1)	//no operand                                //~5501I~
    	return 4;                                               //~5501I~
	for (ppc=Soptionid,ii=0;*ppc;ppc++,ii++)
		if (!stricmp(Pbuff,*ppc))                               //~v031R~
        	break;
	if (!*ppc)	//not found
    	return 4;
//UTRACED("buff",Pbuff,60);                                        //~v432R~
    pc=Pbuff+strlen(Pbuff)+1;	//second word,value fld         //~v031R~
	if (!Snonumopt[ii])	//must numeric                          //~v015I~
	if (!ISNUMSTR(pc))
    	return 4;
	value=atoi(pc);
//UTRACEP("pc=%s,value=%d",pc,value);                              //~v432R~
	switch (ii)
    {
//  case 0:                                                     //~v063R~
//  	Gfiletabskip=value;                                     //~v063R~
//  	break;                                                  //~v063R~
    case 0:             //tabdisp jpn                              //~v09UI~
		rc=inirtabdispchar(&Gtabdispchar[2],pc);   //japanese mode tab1//~v09UI~
    	break;                                                     //~v09UI~
    case 1:
		Gcmdmaxstack=value;
    	break;
//  case 2:                                                        //~v0f1R~
//  	Ginitheap=value;                                           //~v0f1R~
//  	break;                                                     //~v0f1R~
    case 3:
    	if (value)
			UCBITOFF(Gopt,GOPTCANCELNOCONF);
		else
			UCBITON(Gopt,GOPTCANCELNOCONF);
    	break;
    case 4:
    	if (value)
			UCBITOFF(Gopt,GOPTSAVENOCONF);
		else
			UCBITON(Gopt,GOPTSAVENOCONF);                       //~5501R~
    	break;
    case 5:
    	if (value)
			UCBITOFF(Gopt,GOPTUNDONOCONF);
		else
			UCBITON(Gopt,GOPTUNDONOCONF);
    	break;
    case 6:
    	if (value)
			UCBITOFF(Gopt,GOPTNOABENDIFERREXIT);
		else
			UCBITON(Gopt,GOPTNOABENDIFERREXIT);
    	break;
    case 7:
    	if (value)
			UCBITON(Gopt,GOPTRCTLENTER);
		else
			UCBITOFF(Gopt,GOPTRCTLENTER);
    	break;
//  case 8:                                                     //~v063R~
//  	if (value)                                              //~v063R~
//  		UCBITON(Gopt,GOPTTABDISPLAY);                       //~v063R~
//  	else                                                    //~v063R~
//  		UCBITOFF(Gopt,GOPTTABDISPLAY);                      //~v063R~
//  	break;                                                  //~v063R~
    case 8:             //tabdisp eng                              //~v09UI~
		rc=inirtabdispchar(&Gtabdispchar[0],pc);   //english mode tab1//~v09UI~
    	break;                                                     //~v09UI~
    case 9:
    	if (value)
			UCBITOFF(Gopt2,GOPT2LINOINDENT);
		else
			UCBITON(Gopt2,GOPT2LINOINDENT);
    	break;
//  case 10:                                                    //~v063R~
//  	if (value)                                              //~v063R~
//  		UCBITOFF(Gopt2,GOPT2NOCID);                         //~v063R~
//  	else                                                    //~v063R~
//  		UCBITON(Gopt2,GOPT2NOCID);                          //~v063R~
//  	break;                                                  //~v063R~
    case 10: 		//dbcs space                                   //~v09UR~
		rc=inirtranschar(&Gunpdispchar[3],pc);   //japanese mode   //~v09UI~
    	break;                                                     //~v09UI~
    case 11:                                                    //~5502I~
    	if (value)                                              //~5502I~
        {                                                       //~5502I~
			UCBITON(Gopt2,GOPT2INITINSMODE);                    //~5502I~
			UCBITON(Gscrstatus,GSCRSINS);                       //~5502I~
        }                                                       //~5502I~
		else                                                    //~5502I~
        {                                                       //~5502I~
			UCBITOFF(Gopt2,GOPT2INITINSMODE);                   //~5502I~
			UCBITOFF(Gscrstatus,GSCRSINS);                      //~5502I~
        }                                                       //~5502I~
    	break;                                                  //~5502I~
    case 12:                                                    //~5502I~
    	if (value)                                              //~5502I~
			UCBITOFF(Gopt2,GOPT2BOXREPCSR);                     //~5502I~
		else                                                    //~5502I~
			UCBITON(Gopt2,GOPT2BOXREPCSR);                      //~5502I~
    	break;                                                  //~5502I~
    case 13:	//eof write option                              //~5502I~
    	switch (value)                                          //~5502I~
        {                                                       //~5502I~
        case 0:		//drop                                      //~5502I~
			UCBITON(Gopt2,GOPT2EOFDROP);                        //~5502I~
			UCBITOFF(Gopt2,GOPT2EOFWRITE);                      //~5502I~
            break;                                              //~5502I~
        case 1:		//force writew                              //~5502I~
			UCBITOFF(Gopt2,GOPT2EOFDROP);                       //~5502I~
			UCBITON(Gopt2,GOPT2EOFWRITE);                       //~5502I~
            break;                                              //~5502I~
        case 2:		//leave as input,write for new              //~5502I~
			UCBITOFF(Gopt2,GOPT2EOFDROP|GOPT2EOFWRITE);         //~5502I~
			UCBITON(Gopt2,GOPT2EOFWIFNEW);                      //~5502I~
            break;                                              //~5502I~
        default:		//leave as input,write for new          //~5502I~
			UCBITOFF(Gopt2,GOPT2EOFDROP|GOPT2EOFWRITE|GOPT2EOFWIFNEW);//~5502I~
            break;                                              //~5502I~
		}                                                       //~5502I~
    	break;                                                  //~5502I~
    case 14:                                                    //~5506R~
    	if (value)                                              //~5506I~
			UCBITON(Gopt2,GOPT2REJECTCTLCHAR);                  //~5506I~
		else                                                    //~5506I~
			UCBITOFF(Gopt2,GOPT2REJECTCTLCHAR);                 //~5506I~
    	break;                                                  //~5506I~
    case 15:	//ctl char japanese                             //~5506I~
//  	validchartbl=kbdgetchartbl(2);//japanese                   //~v0a2R~
//  	for (ii=1;ii<32;ii++,pc++)                                 //~v0a2R~
//  		if (*pc=='0')                                          //~v0a2R~
//  			*(validchartbl+ii)=0;                              //~v0a2R~
//          else                                                   //~v0a2R~
//  			*(validchartbl+ii)=1;                              //~v0a2R~
//  	break;                                                     //~v0a2R~
    case 16:	//ctl char english                              //~5506I~
        if (ii==15)                                                //~v0a2R~
            ii=2;                    //japanese                    //~v0a2I~
        else                                                       //~v0a2I~
            ii=1;                     //english                    //~v0a2R~
//  	validchartbl=kbdgetchartbl(1);//english                    //~v0a2R~
    	validchartbl=kbdgetchartbl(ii);//english                   //~v0a2I~
        jj=32-(int)strlen(pc);                                     //~v0a2I~
        if (jj<0 || jj>1)	                                       //~v0a2M~
        	return 4;                                              //~v0a2M~
//  	for (ii=1;ii<32;ii++,pc++)                                 //~v0a2R~
    	for (ii=jj;ii<32;ii++,pc++)                                //~v0a2I~
    		if (*pc=='0')                                       //~5506R~
				*(validchartbl+ii)=0;                           //~5506I~
            else                                                //~5506I~
				*(validchartbl+ii)=1;                           //~5506I~
    	break;                                                  //~5506I~
    case 17:	//change id table 1                             //~5528I~
    case 18:	//change id table 2                             //~5528I~
    case 19:	//change id table 3                             //~5528I~
    case 20:	//change id table 4                             //~5528I~
    case 21:	//change id table 5                             //~5528I~
    case 22:	//change id table 6                             //~5528I~
    case 23:	//change id table 7                             //~5528I~
    case 24:	//change id table 8                             //~5528I~
    case 25:	//change id table 9                             //~5528I~
		rc=inircid(ii-17,value,Pwordno-1,pc);                   //~5528I~
    	break;                                                  //~5528I~
    case 26:	//change id table 9                             //~v015I~
		rc=inirfixcid(Pwordno-1,pc);                            //~v015I~
    	break;                                                  //~v015I~
    case 27:    //kbd speed                                     //~v01aI~
		Gkbdspeed=value;                                        //~v01aI~
    	break;                                                  //~v01aI~
    case 28:    //kbd delay                                     //~v01aI~
		Gkbddelay=value;                                        //~v01aI~
    	break;                                                  //~v01aI~
    case 29:    //kbd speed at return                           //~v01aI~
		Gkbdspeed2=value;                                       //~v01aI~
    	break;                                                  //~v01aI~
    case 30:    //kbd delay at return                           //~v01aI~
		Gkbddelay2=value;                                       //~v01aI~
    	break;                                                  //~v01aI~
    case 31:    //dirlist indentation                           //~v03nI~
    	if (value)                                              //~v03nI~
			UCBITON(Gopt3,GOPT3DIRLISTINDENT);                  //~v03nI~
		else                                                    //~v03nI~
			UCBITOFF(Gopt3,GOPT3DIRLISTINDENT);                 //~v03nI~
    	break;                                                  //~v03nI~
//  case 32:    //scroll browse                                 //~v063R~
//  case 33:    //scroll edit                                   //~v063R~
//  case 34:    //scroll dir                                    //~v063R~
//  	if (!(value=filechkscrollopd(strupr(pc)))               //~v063R~
//      ||  value>9999)                                         //~v063R~
//      	return 4;					//invalid scroll id     //~v063R~
//      Ginitscroll[ii-32]=value;                               //~v063R~
//  	break;                                                  //~v063R~
    case 32:    //display translation tbl-J                        //~v09UI~
		rc=inirtranstbl(Gunpdispchartblj,Stranssw,pc);   //trans table first time sw//~v09UI~
	  	break;                                                     //~v09UI~
    case 33:    //display translation tbl-E                        //~v09UI~
		rc=inirtranstbl(Gunpdispchartble,Stranssw+1,pc);   //trans table first time sw//~v09UI~
	  	break;                                                     //~v09UI~
    case 50:    //display translation tbl-J for wxe                //~v500I~
		rc=inirtranstbl(Gunpdispchartblj_wxe,Stranssw+2,pc);   //trans table first time sw//~v500I~
	  	break;                                                     //~v500I~
    case 51:    //display translation tbl-E for wxe                //~v500I~
		rc=inirtranstbl(Gunpdispchartble_wxe,Stranssw+3,pc);   //trans table first time sw//~v500I~
	  	break;                                                     //~v500I~
    case 34:    //(J) trans char                                   //~v09UI~
		rc=inirtranschar(&Gunpdispchar[2],pc);   //japanese mode   //~v09UI~
	  	break;                                                     //~v09UI~
    case 35:    //print cmd                                     //~v051I~
    case 43:    //print cmd DOS                                    //~v0fzI~
    case 44:    //print cmd GCC                                    //~v0fzI~
    case 45:    //print cmd WIN                                    //~v0fzI~
    case 46:    //print cmd OS2                                    //~v0fzI~
    case 49:    //print cmd LNX                                    //~v20GI~
//UTRACEP(" case=%d",ii);                                          //~v432R~
        if (ii==35)                                                //~v0fzI~
        {                                                          //~v0fzI~
            saveindex=0;                                           //~v0fzI~
        	defossw=2;		//default                              //~v0fzI~
//      	UCBITON(Gprocstatus,GPROCSXPRINT);//first time set default//~v0g0R~
        }                                                          //~v0fzI~
        else                                                       //~v0fzI~
        {                                                          //~v0fzI~
#ifdef UNX                                                         //~v20GI~
            saveindex=5;    	                                   //~v20GI~
        	defossw=(ii==49);    //linux                           //~v20GI~
#else  //!UNX                                                      //~v20GI~
            saveindex=ii-42;	//1-->4                            //~v0fzI~
#ifdef DOS                                                         //~v0fzI~
    #ifdef DPMI                                                    //~v0fzI~
        	defossw=(ii==44);    //gcc                             //~v0fzR~
    #else                                                          //~v0fzI~
        	defossw=(ii==43);    //dos                             //~v0fzR~
    #endif                                                         //~v0fzI~
#else                                                              //~v0fzI~
    #ifdef W32                                                     //~v0fzI~
        	defossw=(ii==45);    //w95                             //~v0fzR~
    #else                                                          //~v0fzI~
        	defossw=(ii==46);    //os2                             //~v0fzR~
    #endif                                                         //~v0fzI~
#endif                                                             //~v0fzI~
#endif //!UNX                                                      //~v20GI~
		}//default chk                                             //~v0fzI~
        pc+=strspn(pc," ");                                        //~v07uI~
        if (ii=(int)strlen(pc),ii)              //cmd string len//~v051R~
        {                                                       //~v051I~
            Spcmd[saveindex]=umalloc((UINT)(ii+1));                //~v0fzI~
            strcpy(Spcmd[saveindex],pc);	//save for write       //~v0fzI~
          if ((defossw && !Gprintcmd)             	//first time   //~v0fzR~
          ||  defossw==1)				//specific os              //~v0fzI~
          {                                                        //~v0fzI~
            if (Gprintcmd)	//not first time                       //~v0fzR~
            	ufree(Gprintcmd);                                  //~v0fzR~
        	Gprintcmd=umalloc((UINT)(ii+1));	//free at gblterm//~v051R~
            strcpy(Gprintcmd,pc);			                    //~v051R~
//chk xprint used                                                  //~v07uI~
//          pc=strchr(Gxprintcmd0,'.');  //for ustrstri            //~v0g0R~
//          if (pc)                                                //~v0g0R~
//              *pc=0;  	//temporary                            //~v0g0R~
//          if (ustrstri(Gprintcmd,Gxprintcmd)                     //~v0g0R~
//          ||  ustrstri(Gprintcmd,Gxprintcmd0))                   //~v0g0R~
            if (ucmdnmcomp(Gprintcmd,Gxprintcmd0))//xprint used    //~v0g0R~
            	UCBITON(Gprocstatus,GPROCSXPRINT);//parm is xprint //~v0g0R~
            else                                                   //~v0g0R~
        		UCBITOFF(Gprocstatus,GPROCSXPRINT);                //~v0fzI~
//          if (pc)                                                //~v0g0R~
//              *pc='.';	//restore                              //~v0g0R~
          }                              //to be reset old         //~v0fzI~
    	}                                                       //~v051I~
//      else                                                       //~v0fzR~
//      	UCBITON(Gprocstatus,GPROCSXPRINT);                     //~v0fzR~
    	break;                                                  //~v051I~
    case 36:    //xprint cmd                                    //~v05aI~
    case 39:    //xprint cmd_DOS                                   //~v0fzI~
    case 40:    //xprint cmd_GCC                                   //~v0fzI~
    case 41:    //xprint cmd_WIN                                   //~v0fzI~
    case 42:    //xprint cmd_OS2                                   //~v0fzI~
    case 48:    //xprint cmd_LNX                                   //~v20GI~
        if (ii==36)                                                //~v0fzI~
        {                                                          //~v0fzI~
        	defossw=2;		//default                              //~v0fzI~
            saveindex=0;                                           //~v0fzI~
		}                                                          //~v0fzI~
        else                                                       //~v0fzI~
        {                                                          //~v0fzI~
#ifdef UNX                                                         //~v20GI~
            saveindex=5;                                           //~v20GI~
        	defossw=(ii==48);    //linux                           //~v20GI~
#else  //!UNX                                                      //~v20GI~
            saveindex=ii-38;	//1-->4                            //~v0fzI~
#ifdef DOS                                                         //~v0fzI~
    #ifdef DPMI                                                    //~v0fzI~
        	defossw=(ii==40);    //gcc                             //~v0fzR~
    #else                                                          //~v0fzI~
        	defossw=(ii==39);    //dos                             //~v0fzR~
    #endif                                                         //~v0fzI~
#else                                                              //~v0fzI~
    #ifdef W32                                                     //~v0fzI~
        	defossw=(ii==41);    //w95                             //~v0fzR~
    #else                                                          //~v0fzI~
        	defossw=(ii==42);    //os2                             //~v0fzR~
    #endif                                                         //~v0fzI~
#endif                                                             //~v0fzI~
#endif //!UNX                                                      //~v20GI~
		}//default chk                                             //~v0fzI~
        pc+=strspn(pc," ");     //skip space                       //~v07uI~
        if (ii=(int)strlen(pc),ii)              //cmd string len//~v05aI~
        {                                                       //~v05aI~
            Sxpcmd[saveindex]=umalloc((UINT)(ii+1));               //~v0fzI~
            strcpy(Sxpcmd[saveindex],pc);	//save for write       //~v0fzI~
          if ((defossw && Gxprintcmd==Gxprintcmd0)	//first time   //~v0fzR~
          ||  defossw==1)				//specific os              //~v0fzI~
          {                                                        //~v0fzI~
            if (Gxprintcmd!=Gxprintcmd0)	//not first time       //~v0fzI~
            	ufree(Gxprintcmd);                                 //~v0fzR~
        	Gxprintcmd=umalloc((UINT)(ii+1));	//free at gblterm//~v05aI~
            strcpy(Gxprintcmd,pc);                              //~v05aI~
          }                              //to be reset old         //~v0fzI~
    	}                                                       //~v05aI~
    	break;                                                  //~v05aI~
//  case 37:    //delete mode                                   //~v063R~
//  	switch (value)                                          //~v063R~
//      {                                                       //~v063R~
//      case 0:		//drop                                      //~v063R~
//  		UCBITOFF(Gopt3,GOPT3UNDELLEAVE|GOPT3UNDELFREE);     //~v063R~
//          break;                                              //~v063R~
//      case 1:		//free at term                              //~v063R~
//  		UCBITOFF(Gopt3,GOPT3UNDELLEAVE);                    //~v063R~
//  		UCBITON(Gopt3,GOPT3UNDELFREE);                      //~v063R~
//          break;                                              //~v063R~
//      case 2:		//leave at term                             //~v063R~
//  		UCBITON(Gopt3,GOPT3UNDELLEAVE);                     //~v063R~
//  		UCBITOFF(Gopt3,GOPT3UNDELFREE);                     //~v063R~
//          break;                                              //~v063R~
//      default:		//leave as input,write for new          //~v063R~
//      	return 4;					//invalid scroll id     //~v063R~
//  	}                                                       //~v063R~
//  	break;                                                  //~v063R~
    case 37:    //(E) trans char                                   //~v09UI~
		rc=inirtranschar(&Gunpdispchar[1],pc);   //eng mode        //~v09UR~
	  	break;                                                     //~v09UI~
    case 38:    //sub shell init                                //~v063I~
        if (ii=(int)strlen(pc),ii)              //cmd string len//~v063I~
        {                                                       //~v063I~
        	Gshellicmd=umalloc((UINT)(ii+1));	//free at gblterm//~v063I~
        	strcpy(Gshellicmd,pc);		//static area on xegbl.c//~v063I~
    	}                                                       //~v063I~
    	break;                                                  //~v063I~
    case 47:    //beep                                             //~v13mI~
        if (!value)			//beep=0                               //~v13mI~
    		UCBITON(Gopt4,GOPT4NOBEEP);                            //~v13mI~
    	break;                                                     //~v74EI~
    case 52:    //bounds                                           //~v74EI~
        rc=inirbnds(pc);                                           //~v74EI~
    	break;                                                     //~v74EI~
    case 53:    //xe shellpgm                                      //~v765I~
#ifdef LNX                                                         //~v765I~
        if (*pc)                                                   //~v765I~
        {                                                          //~v765I~
            Slnxlshellpgmopt=umalloc(strlen(pc)+1);                //~v765R~
            strcpy(Slnxlshellpgmopt,pc);                           //~v765R~
            ulnxlgetshellpgm(XGSP_SETDEFAULT,Slnxlshellpgmopt);    //~v765R~
        }                                                          //~v765I~
#endif                                                             //~v765I~
    	break;                                                     //~v765I~
    case 54:    //gxe term shell                                   //~v765I~
#ifdef LNX                                                         //~v765I~
        if (*pc)                                                   //~v765I~
        {                                                          //~v765I~
            Slnxxtermshell=umalloc(strlen(pc)+1);                  //~v765R~
            strcpy(Slnxxtermshell,pc);                             //~v765R~
            ulnxxgettermpgmopt(XGTP_SETDEFAULT,0,Slnxxtermshell);  //~v765R~
        }                                                          //~v765I~
#endif                                                             //~v765I~
    	break;                                                     //~v765I~
    case 55:    //gxe term cmd                                     //~v765R~
#ifdef LNX                                                         //~v765I~
        if (*pc)                                                   //~v765I~
        {                                                          //~v765I~
            Slnxxtermcmd=umalloc(strlen(pc)+1);                    //~v765R~
            strcpy(Slnxxtermcmd,pc);                               //~v765R~
            ulnxxgettermpgmopt(XGTP_SETDEFAULT,"",Slnxxtermcmd);   //~v765R~
        }                                                          //~v765I~
#endif                                                             //~v765I~
    	break;                                                     //~v765I~
    case 56:   	//RCTL_NEWLINE                                     //~v768I~
    	if (value)                                                 //~v768I~
//  		Gotheropt|=GOTHERO_RCTLNL;                             //~v793R~
    		Gotheropt|=(GOTHERO_RCTLNL|GOTHERO_SVOPTNL);           //~v793I~
		else                                                       //~v768I~
//			Gotheropt&=~GOTHERO_RCTLNL;                            //~v768I~//~vb2DR~
  			Gotheropt&=(ULONG)(~GOTHERO_RCTLNL);                   //~vb2DI~
    	break;                                                     //~v768I~
    case 57:   	//xfc                                              //~v76gR~
        if (*pc)                                                   //~v76gI~
        {                                                          //~v76gI~
        	if (Gcomparecmdf)                                      //~v76gI~
            	ufree(Gcomparecmdf);                               //~v76gR~
            Gcomparecmdf=umalloc(strlen(pc)+1);                    //~v76gI~
            strcpy(Gcomparecmdf,pc);                               //~v76gI~
        }                                                          //~v76gI~
    	break;                                                     //~v76gI~
    case 58:   	//xdc                                              //~v76gR~
        if (*pc)                                                   //~v76gI~
        {                                                          //~v76gI~
        	if (Gcomparecmdd)                                      //~v76gI~
            	ufree(Gcomparecmdd);                               //~v76gR~
            Gcomparecmdd=umalloc(strlen(pc)+1);                    //~v76gI~
            strcpy(Gcomparecmdd,pc);                               //~v76gI~
        }                                                          //~v76gI~
    	break;                                                     //~v76gI~
    case 59:   	//grep                                             //~v76gI~
        if (*pc)                                                   //~v76gI~
        {                                                          //~v76gI~
        	if (Ggrepcmd)                                          //~v76gI~
            	ufree(Ggrepcmd);                                   //~v76gI~
            Ggrepcmd=umalloc(strlen(pc)+1);                        //~v76gI~
            strcpy(Ggrepcmd,pc);                                   //~v76gI~
        }                                                          //~v76gI~
    	break;                                                     //~v76gI~
#ifndef AAA                                                        //~v76tI~
    case 60:    //xe shellpgm                                      //~v76tI~
#ifdef WXE                                                         //~v76tI~
        if (*pc)                                                   //~v76tI~
        {                                                          //~v76tI~
            Gdcmd2wxeshellcmd=umalloc(strlen(pc)+1);               //~v76tI~
            strcpy(Gdcmd2wxeshellcmd,pc);                          //~v76tI~
        }                                                          //~v76tI~
#endif                                                             //~v76tI~
    	break;                                                     //~v76tI~
#endif                                                             //~v76tI~
    case 61:    //RCTL string  for LNX:CON                         //~v78NI~
        if (*pc)                                                   //~v78NI~
            rc=inirctlstring(0,pc);                                //~v78NI~
    	break;                                                     //~v78NI~
    case 62:    //unicode tbl                                      //~v906I~
#ifdef UTF8SUPP                                                    //~v906I~
        if (*pc)                                                   //~v906I~
            utftbinit(pc);                                         //~v906I~
#endif                                                             //~v906I~
#ifdef UTF8UCS2
	#ifdef WXEXXE	//GUI version                                  //~va20I~
        if (*pc)                                                   //~va20I~
        {                                                          //~va20I~
	        filefullpath(fpath,pc,_MAX_PATH);                      //~va20I~
            utftbinit(fpath);                                      //~va20I~
        }                                                          //~va20I~
    #endif                                                         //~va20I~
#endif                                                             //~va20I~
        Sutftb=umalloc(strlen(pc)+1);                              //~v906I~
        strcpy(Sutftb,pc);                                         //~v906I~
    	break;                                                     //~v906I~
#ifdef UTF8UCS2                                                    //~va20I~
    case 63:    //unicode tbl                                      //~va20R~
	#ifndef WXEXXE	//console version                              //~va20I~
        if (*pc)                                                   //~va20I~
        {                                                          //~va20I~
	        filefullpath(fpath,pc,_MAX_PATH);                      //~va20I~
            utftbinit(fpath);                                      //~va20I~
        }                                                          //~va20I~
    #endif                                                         //~va20I~
        Sutftbcons=umalloc(strlen(pc)+1);                          //~va20I~
        strcpy(Sutftbcons,pc);                                     //~va20I~
    	break;                                                     //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    case 64:    //ebc cfg                                          //~va50I~
    	if (Gebcstat & GES_CLPCFG) //cmdline parm /ebccfg= was specified//+vbBcR~
        {                                                          //~vbBcI~
    		UTRACEP("%s:cmdline parm specified\n",UTT);            //+vbBcR~
        }                                                          //~vbBcI~
        else                                                       //~vbBcI~
        if (*pc)                                                   //~va50I~
        {                                                          //~vbBcI~
            if (xeebc_init(XEEBCIO_CFGFILE,pc))                    //~va50R~
            	rc=4;                                              //~va50I~
    		UTRACEP("%s:inifile cfg parm=%s\n",UTT,pc);            //~vbBcI~
        }                                                          //~vbBcI~
        Sebccfg=umalloc(strlen(pc)+1);                             //~va50I~
        strcpy(Sebccfg,pc);                                        //~va50I~
    	break;                                                     //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
    case 65:    //large file size                                  //~vazdI~
		Glargefilesz=value*1024*1024;                              //~vazdR~
    	break;                                                     //~vazdI~
	}//sw by word index                                         //~5506R~
//UTRACEP("ret=%d",rc);                                            //~v432R~
    return rc;                                                  //~5528R~
}//inirother
//**************************************************               //~vbv9I~
//*set unicode prefix by ddfmt                                     //~vbv9I~
//**************************************************               //~vbv9I~
int getUnicodePrefix(char *Popd,int Plen,CIDTBL *Ppcidtbl)         //~vbv9R~
{                                                                  //~vbv9I~
    ULONG ulucs;                                                   //~vbv9I~
    int len;                                                       //~vbv9I~
    UCHAR wkdata[8],wkdbcs[8];                                     //~vbv9I~
//*********************************                                //~vbv9I~
    UTRACEP("%s:Popd=%s,len=%d\n",UTT,Popd,Plen);                  //~vbv9R~
	if (ux2l(Popd+2,&ulucs))                                       //~vbv9I~
		return 4;                                                  //~vbv9I~
    Ppcidtbl->CIDTucs=(int)ulucs;                                  //~vbv9I~
    utfcvu2dd1(0,(WUCS)ulucs,wkdata,wkdbcs,&len);                  //~vbv9R~
    memcpy(Ppcidtbl->CIDTddfmt,wkdata,2);                          //~vbv9I~
    memcpy(Ppcidtbl->CIDTddfmt+2,wkdbcs,2);                        //~vbv9I~
    if (len==1)                                                    //~vbv9R~
    {	                                                           //~vbv9I~
    	*(Ppcidtbl->CIDTddfmt+1)=' ';                              //~vbv9R~
    	*(Ppcidtbl->CIDTddfmt+3)=0;                                //~vbv9R~
    }                                                              //~vbv9I~
//  UmemcpyZ(Ppcidtbl->CIDTcidfmt,Popd,(size_t)min(len,sizeof(Ppcidtbl->CIDTcidfmt)-1));	//CID//~vbv9R~
    len=min(len,(int)(sizeof(Ppcidtbl->CIDTcidfmt)-1));	//CID      //~vbv9R~
    UmemcpyZ(Ppcidtbl->CIDTcidfmt,Popd,(size_t)len);	//CID      //~vbv9I~
    UTRACED("cidtbl unicode from ini file",Ppcidtbl,sizeof(CIDTBL));//~vbv9R~
    return 0;                                                      //~vbv9I~
}                                                                  //~vbv9I~
//**************************************************            //~5528I~
//*inircid                                                      //~5528I~
//* cid table read                                              //~5528I~
//*parm1:type index(0-8)                                        //~5528I~
//*parm2:1 st operand value(start column)                       //~5528I~
//*parm3:operand no                                             //~5528I~
//*parm3:parsed operand addr                                    //~5528I~
//*ret :rc                                                      //~5528I~
//**************************************************            //~5528I~
int inircid(int Pindex,int Pcolumn,int Popdno,UCHAR *Ppopd)     //~5528I~
{                                                               //~5528I~
	CIDTBL *pcidtbl,*pcidtbl0;                                  //~5528I~
    UCHAR *pc,*opd;                                             //~5528I~
    int ii,wordno,len,tlen;                                     //~5528R~
//*********************************                             //~5528I~
	if (Pindex>=MAXCIDTBL)                                      //~5528R~
    	return 4;                                               //~5528I~
	if (!Pcolumn)                                               //~5528I~
    	return 0;			//reserved entry                    //~5528I~
	if (Popdno<3)			//at least column,CID,1 ext id      //~5528I~
    	return 4;                                               //~5528I~
	pcidtbl0=filegetcidtbl();                                   //~5528I~
	pcidtbl=pcidtbl0+Pindex;                                    //~5528I~
	opd=Ppopd+strlen(Ppopd)+1;	//CID char addr                 //~5528M~
    len=(int)strlen(opd);		//CID                           //~5528M~
    UTRACEP("%s:Pidx=%d,len=%d,opd=%s\n",UTT,Pindex,len,opd);      //~vbv9R~
  if (toupper(*opd)=='U' && *(opd+1)=='-')                         //~vbv9I~
  {                                                                //~vbv9I~
    ;                                                              //~vbv9I~
  }                                                                //~vbv9I~
  else                                                             //~vbv9I~
  {                                                                //~vbv9I~
//  if (len<1 || len>2)                                            //~v09FR~
    if (len<1 || len>(LINEPREFIXLEN+1+LINEPOSTFIXLEN))             //~v09FR~
    	return 4;                                               //~5528M~
    if (len>LINEPREFIXLEN)              //postfix specified        //~v09FI~
    	if (*(opd+LINEPREFIXLEN)!=',')	//delimiter chk            //~v09FI~
	    	return 4;                                              //~v09FI~
  }                                                                //~vbv9I~
    if (!memcmp(opd,"  ",LINEPREFIXLEN))                           //~v09FR~
    	return 4;                                               //~5528M~
    if (!pcidtbl->CIDTmalloc)	//duplicated                    //~5528I~
    {                                                           //~5528I~
//  	pc=pcidtbl->CIDTmalloc=UALLOCC(1,CIDTBLSZ+LINECIDLEN*2+2); //~v09FR~
    	pc=pcidtbl->CIDTmalloc=UALLOCC(1,CIDEXTTBLSZ+1);           //~v09FR~
		UALLOCCHK(pc,4);                                           //~v09FI~
//      strcpy(pc,pcidtbl0->CIDTcidfmt);	//copy prottype of CID //~v09FR~
//      memset(pc,' ',2);	//clear for 1 byte CID(prefix and max postfix//~v09FR~
//  	pcidtbl->CIDTcidfmt=pc;                                    //~v09FR~
//      pcidtbl->CIDTexttbl=pc+strlen(pc)+1;                       //~v09FR~
        pcidtbl->CIDTexttbl=pc;                                    //~v09FI~
	}                                                           //~5528I~
    pcidtbl->CIDTid=(UCHAR)(Pindex+1);                          //~5528R~
    pcidtbl->CIDTpos=(UCHAR)(Pcolumn-1);                        //~5528R~
  if (toupper(*opd)=='U' && *(opd+1)=='-')                         //~vbv9R~
  {                                                                //~vbv9I~
  	if (getUnicodePrefix(opd,len,pcidtbl))                         //~vbv9I~
    	return 4;                                                  //~vbv9I~
  }                                                                //~vbv9I~
  else                                                             //~vbv9I~
  {                                                                //~vbv9I~
    memset(pcidtbl->CIDTcidfmt,' ',2);//clear for 1 byte(ex. "! "),parse drop space//~v09FI~
    memcpy(pcidtbl->CIDTcidfmt,opd,(UINT)len);	//CID           //~5528R~
    if (len>LINEPREFIXLEN)              //postfix specified        //~v09FI~
	    strcpy(pcidtbl->CIDTcidfmt+LINEPREFIXLEN,opd+LINEPREFIXLEN+1);//~v09FR~
  }                                                                //~vbv9I~
    pc=pcidtbl->CIDTexttbl;                                     //~5528I~
    opd+=len+1;     //extention start                           //~5528R~
	uparse(opd,opd,&wordno,0,",");	//parse out string(accept cr/lf)//~5528R~
    for (ii=0,tlen=0;ii<wordno;ii++)                //~5528I~   //~5528R~
    {                                                           //~5528I~
    	len=(int)strlen(opd);                                   //~5528R~
//      if (len>3 || !len)                                         //~v52mR~
        if (!len)                                                  //~v52mI~
            return 4;                                           //~5528I~
    	len++;                                                  //~5528I~
    	if (tlen+len>CIDEXTTBLSZ)                                  //~v09FR~
        	return 4;		//overflow                          //~5528I~
    	strcpy(pc,opd);                                         //~5528I~
        pc+=len;                                                //~5528R~
        opd+=len;                                               //~5528R~
        tlen+=len;                                              //~5528I~
    }                                                           //~5528I~
    UTRACED("inircd exit cidtbl",pcidtbl,sizeof(CIDTBL));          //~vbv9I~
    UTRACEP("%s:inircd exit exttbl=%s\n",UTT,pcidtbl->CIDTexttbl); //~vbv9R~
    return 0;                                                   //~5528I~
}//inircid                                                      //~5528I~
                                                                //~5528I~
//**************************************************            //~v015I~
//*inirfixcid                                                   //~v015I~
//* cid table read                                              //~v015I~
//*parm1:1 st operand value(start column)                       //~v015I~
//*parm2:operand no                                             //~v015I~
//*parm3:parsed operand addr                                    //~v015I~
//*ret :rc                                                      //~v015I~
//**************************************************            //~v015I~
int inirfixcid(int Popdno,UCHAR *Ppopd)                         //~v015I~
{                                                               //~v015I~
//*********************************                             //~v015I~
	if (!Popdno)			//at least column,CID,1 ext id      //~v015I~
    	return 4;                                               //~v015I~
    if (strlen(Ppopd)>=sizeof(Gfixcidid))                       //~v031R~
    	return 4;                                               //~v031R~
	strcpy(Gfixcidid,Ppopd);	//copy prottype of CID          //~v031R~
    return 0;                                                   //~v015I~
}//inirfixcid                                                   //~v031R~
//**************************************************               //~v09UI~
//*inirtranstbl                                                    //~v09UI~
//* display trans table setup                                      //~v09UI~
//*parm1:tbl addr                                                  //~v09UI~
//*parm2:first time sw                                             //~v09UI~
//*parm3:input pob data ptr(2nd opd)                               //~v09UI~
//*ret :rc                                                         //~v09UI~
//**************************************************               //~v09UI~
int inirtranstbl(UCHAR *Ptranstbl,UCHAR *Pfirstsw,UCHAR *Pdata)    //~v09UR~
{                                                                  //~v09UI~
	USHORT usi;                                                    //~v09UR~
    int    pos;                                                    //~v09UI~
    int ii;                                                        //~v09UI~
    UCHAR *pc;                                                     //~v09UR~
    UCHAR transtbl[16];                                            //~v09UI~
//*********************************                                //~v09UI~
	if (ux2s(Pdata,&usi))                                          //~v09UR~
    	return 4;                                                  //~v09UI~
	if (usi & 0xff0f)                                              //~v09UR~
    	return 4;                                                  //~v09UI~
	pos=(int)(usi & 0xf0);                                         //~v09UR~
    pc=Pdata=Pdata+strlen(Pdata)+1;                                //~v09UI~
    if (strlen(Pdata)!=16)                                         //~v09UI~
    	return 4;                                                  //~v09UI~
	for (ii=0;ii<16;pc++,ii++)                                     //~v09UI~
    	if (*pc=='0')                                              //~v09UR~
        	transtbl[ii]=0;                                        //~v09UI~
		else                                                       //~v09UI~
    	if (*pc=='1')                                              //~v09UI~
        	transtbl[ii]=1;                                        //~v09UI~
		else                                                       //~v09UI~
    		return 4;                                              //~v09UI~
	if (!*Pfirstsw)                                                //~v09UR~
    {                                                              //~v09UI~
		*Pfirstsw=1;                                               //~v09UR~
        memset(Ptranstbl,0,256);	//clear	                       //~v09UR~
    }                                                              //~v09UI~
	memcpy(Ptranstbl+pos,transtbl,16);                             //~v09UR~
    return 0;                                                      //~v09UI~
}//inirtranstbl                                                    //~v09UI~
//**************************************************               //~v09UI~
//*inirtranschar                                                   //~v09UI~
//* display trans char(get 1 byte hex)                             //~v09UR~
//*parm1:output char addr                                          //~v09UI~
//*parm2:data addr                                                 //~v09UI~
//*ret :rc                                                         //~v09UI~
//**************************************************               //~v09UI~
int inirtranschar(UCHAR *Ptranschar,UCHAR *Pdata)                  //~v09UR~
{                                                                  //~v09UI~
	USHORT usi;                                                    //~v09UI~
//*********************************                                //~v09UI~
    if (strlen(Pdata)!=2)                                          //~v09UR~
    	return 4;                                                  //~v09UI~
	if (ux2s(Pdata,&usi))                                          //~v09UI~
    	return 4;                                                  //~v09UI~
	if (!usi                                                       //~v09UR~
    ||  (usi>='0' && usi<='9'))                                    //~v09UI~
    	return 4;                                                  //~v09UI~
	*Ptranschar=(UCHAR)usi;                                        //~v09UI~
    return 0;                                                      //~v09UI~
}//inirtranschar                                                   //~v09UR~
//**************************************************               //~v09UI~
//*inirtabdispchar                                                 //~v09UI~
//* display tab char(get 2byte hex)                                //~v09UI~
//*parm1:output char addr                                          //~v09UI~
//*parm2:data addr                                                 //~v09UI~
//*ret :rc                                                         //~v09UI~
//**************************************************               //~v09UI~
int inirtabdispchar(UCHAR *Ptranschar,UCHAR *Pdata)                //~v09UI~
{                                                                  //~v09UI~
	UCHAR hex2[2];                                                 //~v09UR~
//*********************************                                //~v09UI~
    if (strlen(Pdata)!=4)                                          //~v09UR~
    	return 4;                                                  //~v09UI~
	if (ugethex(Pdata,hex2,4)!=2)                                  //~v09UR~
    	return 4;                                                  //~v09UI~
	if (!hex2[0]                                                   //~v09UR~
    ||  (hex2[0]>='0' && hex2[0]<='9'))                            //~v09UR~
    	return 4;                                                  //~v09UI~
	if (!hex2[1]                                                   //~v09UI~
    ||  (hex2[1]>='0' && hex2[1]<='9'))                            //~v09UR~
    	return 4;                                                  //~v09UI~
	*Ptranschar=hex2[0];                                           //~v09UR~
	*(Ptranschar+1)=hex2[1];                                       //~v09UI~
    return 0;                                                      //~v09UI~
}//inirtabdispchar                                                 //~v09UI~
//**************************************************               //~v74EI~
//*inirbnds                                                        //~v74EI~
//* bounds parameter                                               //~v74EI~
//*parm:parsed operand                                             //~v74EI~
//*ret :rc                                                         //~v74EI~
//**************************************************               //~v74EI~
int inirbnds(UCHAR *Ppopd)                                         //~v74EI~
{                                                                  //~v74EI~
    char *popd,*pext,*pcol1,*pcol2;                                //~v74EI~
    int rc=0,len1,len2,col1,col2;                                  //~v74ER~
//*********************************                                //~v74EI~
    popd=Ppopd;                                                    //~v74EI~
    pext=popd;                                                     //~v74EI~
    popd+=strlen(popd)+1;                                          //~v74EI~
    pcol1=popd;                                                    //~v74EI~
    len1=(int)strlen(pcol1);                                       //~v768R~
    popd+=len1+1;                                                  //~v74EI~
    pcol2=popd;                                                    //~v74EI~
    len2=(int)strlen(pcol2);                                       //~v768R~
    if (unumlen(pcol1,0,len1)!=len1)                               //~v74EI~
    	rc=4;                                                      //~v74EI~
    else                                                           //~v74EI~
    if (unumlen(pcol2,0,len2)!=len2)                               //~v74ER~
    	rc=4;                                                      //~v74EI~
    else                                                           //~v74EI~
    {	                                                           //~v74EI~
		col1=atoi(pcol1);                                          //~v74ER~
		col2=atoi(pcol2);                                          //~v74EI~
        if (col1<0 || col2<0 || (col2 && col2<col1))               //~v74ER~
        	rc=4;                                                  //~v74EI~
        else                                                       //~v74EI~
			rc=fcmdbndstupdate(FCBND_ADD,pext,col1,col2);          //~v74EI~
    }                                                              //~v74EI~
    return rc;                                                     //~v74EI~
}//inirfixcid                                                      //~v74EI~
//**************************************************               //~v74EI~
//*iniwbnds                                                        //~v74EI~
//* bounds parameter write                                         //~v74EI~
//*parm:FILEH*                                                     //~v74EI~
//*ret :rc                                                         //~v74EI~
//**************************************************               //~v74EI~
int iniwbnds(FILE* Pfh)                                            //~v74EI~
{                                                                  //~v74EI~
	PBNDSTBL pbt;                                                  //~v74ER~
    int wctr=0;                                                    //~v74EI~
//*********************************                                //~v74EI~
                                                                   //~v74EI~
	fprintf(Pfh,"\n");                                             //~v74EI~
	fcmdbndstgettop(&pbt);                                         //~v74ER~
	for (;pbt;pbt=UGETQNEXT(pbt))                                  //~v74EI~
    {                                                              //~v74EI~
        if (pbt->BNDSTcol1==0 && pbt->BNDSTcol2==0)                //~v74EI~
        	continue;                                              //~v74EI~
        wctr++;                                                    //~v74EI~
//    if (pbt->BNDSTflag & BNDSTF_DIR)                             //~v74NR~
      if (pbt->BNDSTflag & (BNDSTF_DIR|BNDSTF_FILE))               //~v74NR~
		fprintf(Pfh,                                               //~v74EI~
				" %-18s= \"%s\" =%3d %3d  # default boundary for the file||v123\n",//~v74ER~
				Soptionid[52],                                     //~v74EI~
				pbt->BNDSTextname,pbt->BNDSTcol1,pbt->BNDSTcol2);  //~v74EI~
      else                                                         //~v74EI~
		fprintf(Pfh,                                               //~v74EI~
				" %-18s= .%-8s=%3d %3d  # default boundary for the file ||v123\n",//~v74ER~
				Soptionid[52],                                     //~v74EI~
				pbt->BNDSTextname,pbt->BNDSTcol1,pbt->BNDSTcol2);  //~v74ER~
    }                                                              //~v74EI~
	if (!wctr)                                                     //~v74EI~
		fprintf(Pfh,                                               //~v74EM~
				"#%-18s= .%-8s=%3d %3d  # default boundary for the file extension name(Sample)||v123\n",//~v74ER~
				Soptionid[52],                                     //~v74EM~
				"cob",7,72);                                       //~v74EM~
    return 0;                                                      //~v74ER~
}//iniwbnds                                                        //~v74EI~
//**************************************************               //~v78NI~
//*inirctlstring                                                   //~v78NI~
//* linux console version:rctl string setup by xmodmap             //~v78NI~
//*ret :rc                                                         //~v78NI~
//**************************************************               //~v78NI~
int inirctlstring(FILE *Pfh,char *Pstring)                         //~v78NI~
{                                                                  //~v78NI~
    int rc=0;                                                      //~v78NR~
#ifdef BBB                                                         //~v78NI~
    int ii,rc=0;                                                   //~v78NI~
    char *pc;                                                      //~v78NI~
#else                                                              //~v78NI~
#ifdef LNX                                                         //~v906I~
	#ifndef XXE                                                    //~v906I~
    char fpath[_MAX_PATH];                                         //~v78NI~
	#endif                                                         //~v906I~
#endif                                                             //~v906I~
#endif                                                             //~v78NI~
//*********************************                                //~v78NI~
	if (Pstring)    //read                                         //~v78NR~
    {                                                              //~v78NI~
#ifdef BBB                                                         //~v78NI~
        if (Srctlstrno==MAX_RCTLSTR)                               //~v78NI~
        {                                                          //~v78NI~
        	uerrmsg("%s overflow,max is %d",0,                     //~v78NI~
            		Soptionid[61],MAX_RCTLSTR);                    //~v78NI~
            return 0;       //use this errmsg                      //~v78NR~
        }                                                          //~v78NI~
        pc=umalloc(strlen(Pstring)+1);                             //~v78NR~
    	strcpy(pc,Pstring);                                        //~v78NR~
        Sprctlstr[Srctlstrno++]=pc;                                //~v78NR~
#endif                                                             //~v78NI~
#ifdef LNX                                                         //~v78NI~
	#ifndef XXE                                                    //~v78NI~
#ifdef BBB                                                         //~v78NI~
        ukbdlnxc_setrctlstr(0,pc);                                 //~v78NR~
#else                                                              //~v78NI~
		if (*Pstring)                                              //~v78NR~
        {                                                          //~v78NI~
            strcpy(Skeymapfile,Pstring);                           //~v78NI~
	        filefullpath(fpath,Skeymapfile,_MAX_PATH);             //~v78NR~
	        ukbdlnxc_chngttkey(UKBDLNXC_CTKINIT,fpath);            //~v78NR~
        }                                                          //~v78NI~
#endif                                                             //~v78NI~
    #endif                                                         //~v78NI~
#else                                                              //~v793I~
		;	//NULL for compiler warning                            //~v793I~
#endif                                                             //~v78NI~
    }                                                              //~v78NI~
    else            //write                                        //~v78NR~
    {                                                              //~v78NI~
#ifdef BBB                                                         //~v78NI~
		fprintf(Pfh,"\n### (Linux Console Version) Notify strings assigned to Right-Ctrl key by xmodmap cmd\n");//~v78NR~
        fprintf(Pfh,"###   after xmodmap cmd, check the string by xekbchk tool(up to max %d lines)\n",MAX_RCTLSTR);//~v78NI~
		fprintf(Pfh,"### %-18s=\\x8f\\xab\\xf2  ## this is hex notation sample(start char should be >=0x80)\n",Soptionid[61]);//~v78NR~
		fprintf(Pfh,"### %-18s=^[[28;2~      ## this is Esc string sample\n",Soptionid[61]);//~v78NR~
    	for (ii=0;ii<Srctlstrno;ii++)                              //~v78NI~
        {                                                          //~v78NI~
			fprintf(Pfh," %-18s=%s  ##\n",                         //~v78NR~
					Soptionid[61],Sprctlstr[ii]);                  //~v78NI~
        }                                                          //~v78NI~
#else                                                              //~v78NI~
		fprintf(Pfh,"\n %-18s=%s   ##(Linux Console Version Only) Keymap file to detect remapping by xmodmap cmd\n",//~v906R~
					Soptionid[61],(*Skeymapfile?Skeymapfile:"\"\""));//~v906R~
#endif                                                             //~v78NI~
    }                                                              //~v78NI~
    return rc;                                                     //~v78NI~
}//inirctlstring                                                   //~v78NI~
