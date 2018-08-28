//*CID://+vbkcR~:                             update#=  627;       //~vbkcR~
//*************************************************************
//*xepan2.c
//*   filename list process
//*************************************************************
//vbkc:180619 (BUG)panutil collapse sddata by setting sdlen(width*2)=USDcell size//~vbkcI~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb4g:160804 like vb3d,set hdr attr not to the char but to pathname to draw at uviom by Ligature same as dir member//~vb4gR~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vawf:140602 dlcmd "."(set current dir) send UD fmt to =1/=2 panel,it should be strip.//~vawfI~
//vavx:140428 strip uid from U3Lfnm                                //~vavxI~
//vavt:140428 strip uid from UFHfilenamedddata                     //~vavtI~
//vavq:140426 (Bug of vaub)memory leak                             //~vavqI~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vaum:140313 (BUG)same as vau2,occurs on retrieve cmd over session//~vaumI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va70:000701 LP64 option support                                  //~va70I~
//va5t:100515 display filenamelist by dd fmt                       //~va5tI~
//va5r:100512 (BUG)cmd stack u8 codetype will be lost when f2l err //~va5rI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va1BI~
//va1B:091112 (UTF8)hdrline codetype ftrom cmd buff if avail       //~va1BI~
//va1A:091112 (UTF8)for filenamelist lcmd;cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1AI~
//va1y:091111_(UTF8)like as cmd string,stack filename list with lc //~va1yR~
//va1w:061111 (BUG)"S" cmd on filename list drop option parameter  //~va1wR~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0E:090725!accept utf8 input on =3.14 option line(utfg string search)//~va0tI~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v78j:080312 (WXE)ABEND by push x on right top of window          //~v78jI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76n:070628 scroll size support for =2/=1 panel                  //~v76nI~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v71d:061006 (BUG)filenamelsit "S" cmd generate subcmdid=0(truncated cmd)err//~v71dI~
//v64v:050708 (LNX)openwith support                                //~v64vI~
//v61v:050306 (BUG)select shpuld follow previous cmd               //~v61vI~
//v61u:050306 (BUG)redraw required for space lcmd on filename list //~v61fI~
//v61r:050302 keep edit or browse id on filename queue             //~v61rI~
//v61p:050301 support filename list delete lcmd('D')               //~v61pI~
//v61k:050301 (BUG of v61c)abend may occur when filenamelist filename length on//~v61kI~
//            xe!save! is contain strz char.                       //~v61kR~
//v61f:050226 space lcmd on filename list;drop parm and set on cmd line//~v61fI~
//v61d:050222 support pgtop/pglast for filename list               //~v61dI~
//v61c:050221 set open parm to filename list to reopen by same option//~v61cI~
//            lcmd "3" means bin browse/edit                       //~v61cR~
//v56f:040404 finenamelist page overrun by pgdn when enq count is just multiple of pagesize//~v56fI~
//v56d:040403 set csr to top of filename list when wakeup          //~v56dI~
//v55V:040321 (WIN)filename list ! lcmd(openwith) support          //~v55VI~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v55w:040302 driveid list missed by v557                          //~v55wI~
//v55m:040218 (BUG)filename list;filename select should consider multipage//~v55mI~
//v557:040203 filename list multi-page support                     //~v557I~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v53v:031005 (BUG)filename list line is not reversed for lower line.//~v53vI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v51P:030727 (BUG)filename is cut if screen width is narrow when select on filename list scr//~v51PI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v508:021109 (BUG)menu file list stack,filename compare by case insensitive for not unix//~v508I~
//v500:021109 (WXE)maxline is not same as xe                       //~v500I~
//v500:021109 (WXE)xe maxline over flow(UPCline[ii]) abend caused by wxe//~v500I~
//v44p:011205 cobol cmd support                                    //~v44pI~
//            c:cob-seqno,k:cob-space,i:spfcob-seqno,j:spfcob-space,n:spf//~v44pI~
//v44n:011205 Hex suppot(h:by menuopt,H:opposit of menu opt)       //~v44nI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v216:001202 file name list;chance to modify e/b cmd for enter key.//~v216I~
//v20y:001028 new function:filename selection on menu 1/2 name list
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
  #ifdef OS2                                                       //~v76pI~
	#define INCL_DOSDEVIOCTL                                       //~v76pI~
	#define INCL_BASE                                              //~v76pI~
	#include <os2.h>                                               //~v76pI~
  #endif                                                           //~v76pI~
#endif
#ifdef W32                                                         //~vb4fI~
	#include <windows.h>                                           //~vb4fI~
#endif                                                             //~vb4fI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <ustring.h>                                               //~v61cI~
#include <utrace.h>
#include <uparse.h>                                                //~v76nI~
#include <ukbd.h>                                                  //~v76nI~
#include <uftp.h>                                                  //~v76pI~
#ifndef UNX                                                        //~v54vI~
	#include <udos2.h>                                             //~v54vI~
#endif                                                             //~v54vI~
#ifdef UTF8SUPPH                                                   //~va0tR~
	#include <utf.h>                                               //~va0tI~
#endif                                                             //~va0tI~
#include <ufilew.h>                                                //~vavpI~
#include <utf22.h>                                                 //~vavxI~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4gI~
#include <uviom.h>                                                 //~vb4fI~

#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v216I~
#include "xecsr.h"
#include "xefunc.h"
#include "xefunc2.h"                                               //~v216I~
#include "xefile.h"
#include "xefile2.h"                                               //~va1BI~
#include "xefile3.h"                                               //~v76nI~
#include "xepan.h"
#include "xepan2.h"
#define XEPAN22_GLOBAL	//define global in the xepan22.h           //~v557I~
#include "xepan22.h"
#include "xesub.h"
#include "xeerr.h"                                                 //~v53cI~
#include "xedlcmd.h"                                               //~v55VI~
#include "xedlcmd6.h"                                              //~v55VI~
#ifdef WXE                                                         //~v76nI~
	#include "wxexei.h"                                            //~v76nI~
#else                                                              //~v76nI~
	#ifdef XXE                                                     //~v76nI~
		#include "xxexei.h"                                        //~v76nI~
	#else                                                          //~v76nI~
		#ifdef LNX		//console version                          //~v76nI~
			#include "xemousel.h"                                  //~v76nI~
        #endif                                                     //~v76nI~
    #endif                                                         //~v76nI~
#endif                                                             //~v76nI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                             //~va00I~
	#include "xeutf2.h"                                            //~va5tI~
#endif                                                             //~va00I~
#include "xefsubw.h"                                               //~vavpI~
//****************************************************************
#ifdef UTF8SUPPH                                                   //~va00I~
#define UP300DFNMSZ    (_MAX_PATH+1)                               //~va00I~
//#define UP300DCTSZ     _MAX_PATH		//for fullpathname         //~va00R~
#endif	//UTF8SUPPH                                                //~va00I~
//****************************************************************
#define LCMDID  "_"                                                //~v20yI~
#define LCMDIDCH '_'                                               //~v61cI~
#define LCMDIDDELCH 'D'        //delete entry lcmd                 //~v61pR~
static UQUEH 		Sfnstack;  //filename stack que
static int Supdatelistsw=0;       //list updated                   //~v44nR~
static int Sspacelcmd=0;	       //put cmd by space lcmd         //~v61fI~
//static UCHAR Scmdtbl[]="best12hHnNcCkKiIjJ";                     //~v55VR~
//static UCHAR Scmdtbl[]="best12hHnNcCkKiIjJ!";                    //~v61cR~
//static UCHAR Scmdtbl[]="best123hHnNcCkKiIjJ!(Space)";            //~v61pR~
static UCHAR Scmdtbl[]="best123hHnNcCkKiIjJ!(Space)d";             //~v61pI~
#ifdef UTF8SUPPH                                                   //~va1yI~
    static int Scmdbuffoffsfnmp;        //filename parameter position//~va1yI~
    static int Scmdbuffoffsinfpath;      //parm fnm position infpath//~va1yR~
    static int Scmdbufflenu8;        //filename parameter len by utf8//~va1yI~
    static int Scmdbufflenlc;        //filename parameter len by locale code//~va1yI~
    static PUFILEH Sstackpfh;                                      //~va1BI~
#endif                                                             //~va1yI~
#ifdef W32UNICODE   //offsinfpath is not valid when UD sign was appended//~vavpI~
    static int SswlastUD;   //copy last UD                         //~vavpI~
#endif                                                             //~vavpI~
//****************************************************************
//void pan300addentry(UCHAR *Pfnm,int Pfnmlen,int Pinitsw);        //~v55VR~
int pan300lcmderr(UCHAR *Pcmdtbl);
int panbecmdcall(PUCLIENTWE Ppcw,UCHAR Pcmdid);                    //~v44nI~
int panbrowsecmdchk(PUCLIENTWE Ppcw,UCHAR Pcmdid);                 //~v44nI~
//int pan300getfnm(int Pyy,UCHAR *Pout);                           //~v55UR~
int pan300csrreset(PUCLIENTWE Ppcw);                               //~v56dI~
//int pan300getlcmdfromfuncid(int Pfuncid,int Pbrowsesw);          //~v61rR~
int pan300getlcmdfromfuncid(int Pfuncid,int *Ppbrowsesw);          //~v61rI~
int pan300editfpath(PUCLIENTWE Ppcw,UCHAR *Pfpath,int Plcmd,UCHAR *Poutcmdstr);//~v61cI~
int pan300editcmd(PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pcmdstr);  //~v61cR~
#ifdef UTF8SUPPH                                                   //~va1rI~
int pan300editcmd_utf8(int Popt,PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pcmdstr,int Poffs,char *Pcmdlc,char *Pcmdct,int *Pplenlc);//~va1rI~
#define P3ECU8O_NOOPTION     0x01 //drop option parm               //~va1AR~
#endif                                                             //~va1rI~
int pan300getbecmd(PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pbecmd);  //~v61uR~
PUP300LIST pan300getpsc(int Pyy);                                  //~v61cR~
int pan300delentry(PUCLIENTWE Ppcw,PUP300LIST Ppsc);               //~v61pI~
int pan300getscrollsz(PUCLIENTWE Ppcw,int Popt,int Pdest);         //~v76nI~
int pan300scrollsetcsr(PUCLIENTWE Ppcw,int Poldtop,int Pnewtop,int Poldyy);//~v76nR~
#ifdef UTF8SUPPH                                                   //~va00I~
    int pan300wakeup1(PUCLIENTWE Ppcw,PUPANELC Pppc);              //~va00I~
	int pan300fnmattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUP300LIST Ppsc,int Prow);//~va00I~
#ifdef EEE                                                         //~va0tI~
	int pansetfld_l2f(int Popt,PUCLIENTWE Ppcw,PUPANELL Ppupl,int Pfldno,char *Pdata,int *Pputf8len);//~va00R~
#endif                                                             //~va0tI~
#endif                                                             //~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	void setpscddname(PUP300LIST Ppsc,int Pddlen,char *Pdddata,char *Pdddbcs,char *Pddcode);//~vaubR~
#endif                                                             //~vaubI~
//**************************************************************** //~v76mI~
//* draw filename list                                             //~v76mI~
//**************************************************************** //~v76mI~
int pan300init(PUCLIENTWE Ppcw)                                    //~v76mI~
{                                                                  //~v76mI~
	return panfnlsetuppfh(Ppcw,&Sfnstack);                         //~v76mI~
}//pan300init                                                      //~v76mI~
//**************************************************************** //~vaubI~
void ufreepsc(PUP300LIST Ppsc)                                     //~vaubI~
{                                                                  //~vaubI~
//#ifdef LNX                                                         //~vaumI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	UFREEIFNZ(Ppsc->U3Ldddata);                                    //~vaubR~
    UTRACEP("U3L-get Psc=%p,dddata=%p\n",Ppsc,Ppsc->U3Ldddata);    //~vavpI~
#endif                                                             //~vaumI~
	ufree(Ppsc);                                                   //~vaubI~
}//ufreepsc                                                        //~vaubI~
//****************************************************************
//* draw filename list
//****************************************************************
int pan300selectline(PUCLIENTWE Ppcw)
{
	int yy,ii,maxline;
    int curpageend;                                                //~v557I~
    PUPANELC ppc;		//pannel buff
    ULONG fld2mask=0x40000000;
//************************************
	yy=Ppcw->UCWrcsry;		//  cursor line
#ifndef UNX                                                        //~v54vI~
//driveid list                                                     //~v54vI~
    if (yy==PANL300DRIVE)                                          //~v54vI~
    	pan300drawdid(Ppcw);                                       //~v54vI~
#endif                                                             //~v54vI~
//  maxline=PANL300LISTTOP+UGETQCTR(&Sfnstack);	//enq counter      //~vb31R~
    maxline=PANL300LISTTOP+(int)UGETQCTR(&Sfnstack);	//enq counter//~vb31I~
    curpageend=maxline-Ppcw->UCWtopfnlist;   //current topline entryno//~v557R~
//#ifdef WXE                                                       //~v557R~
////  maxline=min(maxline,Gscrbuffheight-PANL300LISTTOP);//overflow//~v557R~
//    maxline=min(maxline,Gscrbuffheight);//overflow               //~v557R~
//#else                                                            //~v557R~
////  maxline=min(maxline,Gscrheight-PANL300LISTTOP);//overflow    //~v557R~
//    maxline=min(maxline,Gscrheight);//overflow                   //~v557R~
//#endif                                                           //~v557R~
	maxline=Ppcw->UCWheight;//scr height                           //~v557I~
//set reverse on/off
    ppc=Ppcw->UCWppc;
    for (ii=PANL300LISTTOP;ii<maxline;ii++)
    {                                                              //~v557I~
//        if (ppc->UPCline[ii].UPLerrflag & fld2mask)              //~v557R~
//        {                                                        //~v557R~
//            if (ii!=yy)                                          //~v557R~
//                panflderr(Ppcw,ii,PANL300NAME,PANFERESET);  //reset err reverse//~v557R~
//        }                                                        //~v557R~
//        else                                                     //~v557R~
//            if (ii==yy)                                          //~v557R~
//            {                                                    //~v557R~
//                panflderr(Ppcw,yy,PANL300NAME,PANFESET);    //set err reverse on cur csr//~v557R~
//                csronthefld(Ppcw,yy,PANL300LCMD,0);   //move csr to lcmd fld//~v557R~
//            }                                                    //~v557R~
        if (ii==yy && yy<curpageend)                               //~v557I~
        {                                                          //~v557I~
            panflderr(Ppcw,yy,PANL300NAME,PANFESET);    //set err reverse on cur csr//~v557I~
            csronthefld(Ppcw,yy,PANL300LCMD,0);   //move csr to lcmd fld//~v557I~
        }                                                          //~v557I~
        else                                                       //~v557I~
            if (ppc->UPCline[ii].UPLerrflag & fld2mask)            //~v557I~
                panflderr(Ppcw,ii,PANL300NAME,PANFERESET);  //reset err reverse//~v557I~
    }                                                              //~v557I~
	return 0;
}//pan300selectline                                                //~v76mR~
//****************************************************************
//* setup filename list
//****************************************************************
int pan300updatelist(PUCLIENTWE Ppcw,int Pwakeupsw)
{
    int ii,yy;                                                     //~v20yR~
    int maxline;                                                   //~v500I~
	PUP300LIST psc;			//stack entry
	PUPANELC ppc;                                                  //~v20yI~
	PUFLD    pfld;                                                 //~v20yI~
    int startline,redrawsw,stackctr,endline;                       //~v557R~
#ifndef UNX                                                        //~v54vI~
    char didlist[32];                                              //~v54vR~
    int didno;                                                     //~v54vM~
#ifdef AAA                                                         //~v54vI~
	char didwk[2],*pc;                                             //~v54vI~
#else                                                              //~v54vI~
    char outlist[64],*pco,*pc;                                     //~v54vI~
#endif                                                             //~v54vI~
#endif                                                             //~v54vI~
    char pageno[20];                                               //~v557R~
//  char fpathcmd[_MAX_PATH+MAXCOLUMN];                            //~v61cI~//~va5tR~
    char fpathcmd[(_MAX_PATH+MAXCOLUMN)*2];                        //~va5tI~
    char lcmdid[2];                                                //~v61cM~
    int cmdlen;                                                    //~va5tI~
//************************************
    if (Ppcw->UCWheight!=Ppcw->UCWoldheight)                       //~v557I~
    {                                                              //~v557I~
    	Ppcw->UCWoldheight=Ppcw->UCWheight;                        //~v557I~
        redrawsw=1;                                                //~v557I~
    }                                                              //~v557I~
    else                                                           //~v557I~
        redrawsw=Supdatelistsw;                                    //~v557I~
//  if (Supdatelistsw || Pwakeupsw)       //list updated           //~v557R~
    if (redrawsw || Pwakeupsw)       //list updated                //~v557I~
    {
		ppc=Ppcw->UCWppc;			//client panel control         //~v20yI~
#ifdef UTF8SUPPH                                                   //~va00I~
		if (!ppc->UPCpandata)	//1st time to be init pandata      //~va00I~
        	pan300wakeup1(Ppcw,ppc);                               //~va00I~
#endif                                                             //~va00I~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full draw
#ifndef UNX                                                        //~v54vI~
        if (Pwakeupsw)                                             //~v54vI~
        {                                                          //~v54vI~
        	memset(didlist,0,sizeof(didlist));                     //~v54vR~
            didno=ugetdriveidlist(-1,didlist);    //get driveid list//~v54vI~
#ifdef AAA                                                         //~v54vI~
            didwk[1]=0;                                            //~v54vR~
            for (ii=0,pc=didlist;ii<26;ii++,pc++)                  //~v54vR~
            {                                                      //~v54vI~
            	didwk[0]=*pc;                                      //~v54vI~
    			setflddata(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST+ii,didwk);//~v54vR~
            }                                                      //~v54vI~
#else                                                              //~v54vI~
            for (ii=0,pc=didlist,pco=outlist;ii<didno;ii++,pc++)   //~v54vI~
            {                                                      //~v54vI~
            	*pco++=*pc;                                        //~v54vI~
            	*pco++=' ';                                        //~v54vI~
            }                                                      //~v54vI~
            *pco=0;                                                //~v54vI~
//  		setflddata(Ppcw,PANL300DRIVE,0,outlist);               //~v55wR~
    		setflddata(Ppcw,PANL300DRIVE,1,outlist);               //~v55wI~
#endif                                                             //~v54vI~
        }                                                          //~v54vI~
#endif                                                             //~v54vI~
//#ifdef WXE                                                       //~v557R~
//        maxline=Gscrbuffheight-PANL300LISTTOP;//overflow         //~v557R~
//#else                                                            //~v557R~
//        maxline=Gscrheight-PANL300LISTTOP;//overflow             //~v557R~
//#endif                                                           //~v557R~
		maxline=Ppcw->UCWheight-PANL300LISTTOP;                    //~v557I~
        maxline=max(0,maxline); //avoid display "start>end"        //~v76nI~
		startline=Ppcw->UCWtopfnlist;                              //~v557M~
//  	stackctr=UGETQCTR(&Sfnstack);                              //~v557I~//~vb31R~
    	stackctr=(int)UGETQCTR(&Sfnstack);                         //~vb31I~
        endline=startline+maxline;                                 //~v557I~
        endline=min(endline,stackctr);                             //~v557I~
      if (endline)                                                 //~v61pI~
		sprintf(pageno,"%d - %d of %d",startline+1,endline,stackctr);//~v557R~
      else                                                         //~v61pI~
		sprintf(pageno,"%d - %d of %d",0,endline,stackctr);        //~v61pI~
    	setflddata(Ppcw,PANL300PAGENO,0,pageno);                   //~v557R~
        if (maxline<=0)                                            //~v557I~
        	return 0;                                              //~v557I~
//  	for (ii=0,psc=UGETQTOP(&Sfnstack);psc;ii++,psc=UGETQNEXT(psc))//all entry//~v500R~
//  	for (ii=0,psc=UGETQTOP(&Sfnstack);ii<maxline && psc;ii++,psc=UGETQNEXT(psc))//all entry//~v557R~
    	for (ii=0,psc=UGETQTOP(&Sfnstack);ii<startline && psc;ii++)//all entry//~v557I~
    		psc=UGETQNEXT(psc);		//skip prev page               //~v557I~
//  	for (ii=0;ii<maxline && psc;ii++,psc=UGETQNEXT(psc))//all entry//~v557R~
    	for (ii=0;ii<maxline;ii++)//all entry                      //~v557I~
        {                                                          //~v20yI~
    		yy=PANL300LISTTOP+ii;                                  //~v20yI~
			pfld=ppc->UPCline[yy].UPLpfld;                         //~v20yI~
          if (psc)                                                 //~v557I~
          {                                                        //~v557I~
            UTRACEP("pan300updatelist pscfnmlen=%d,net=%d,fnm=%s\n",psc->U3Lfnmlen,psc->U3Lnetfnmlen,psc->U3Lfnm);//~vaubI~
			UCBITOFF(pfld->UFLentry[PANL300LCMD].UFLflag,UFLEFPROT);//~v20yI~
//  	    setflddata(Ppcw,yy,PANL300LCMD,LCMDID);//clear input   //~v61cR~
//  		setflddata(Ppcw,yy,PANL300NAME,psc->U3Lfnm);           //~v61cR~
#ifdef UTF8SUPPH                                                   //~va00I~
            psc->U3Lflag|=U3LFDRAW;     //parm to pan300editcmd    //~va00I~
#endif                                                             //~va00I~
           cmdlen=                                                 //~va5tM~
			pan300editcmd(Ppcw,psc,fpathcmd);                      //~v61cR~
//  		lcmdid[0]=(char)(psc->U3Lflag & U3LFCMDMASK);          //~v61rR~
			lcmdid[0]=(char)pan300getbecmd(Ppcw,psc,0);            //~v61vR~
            lcmdid[1]=0;                                           //~v61cI~
    	    setflddata(Ppcw,yy,PANL300LCMD,lcmdid);//clear input   //~v61cI~
	      if (psc->U3Lflag & U3LFDRAWDD)    //editcmd at drawing by dd fmt//~va5tR~
          {                                                        //~va5tI~
		    psc->U3Lflag &= ~U3LFDRAWDD;    //editcmd at drawing by dd fmt//~va5tR~
#ifdef W32UNICODE                                                  //~vavpI~
    		fsubw_setflddatadd(0,Ppcw,yy,PANL300NAME,fpathcmd,fpathcmd+cmdlen+1,cmdlen);//~vavpI~
#else                                                              //~vavpI~
    		setflddatadd(0,Ppcw,yy,PANL300NAME,fpathcmd,fpathcmd+cmdlen+1,cmdlen);//~va5tR~
#endif                                                             //~vavpI~
            UTRACED("setflddatadd cmd",fpathcmd,cmdlen);           //~vaubI~
            UTRACED("setflddatadd dbcs",fpathcmd+cmdlen+1,cmdlen); //~vaubI~
          }                                                        //~va5tI~
          else                                                     //~va5tI~
          {                                                        //~vaubI~
    		setflddata(Ppcw,yy,PANL300NAME,fpathcmd);              //~v61cI~
            UTRACED("setflddata cmd",fpathcmd,(int)strlen(fpathcmd));   //~vaubI~//~vb30R~
          }                                                        //~vaubI~
    	    psc=UGETQNEXT(psc);//all entry                         //~v557I~
          }                                                        //~v557I~
          else                                                     //~v557I~
          {                                                        //~v557I~
			UCBITON(pfld->UFLentry[PANL300LCMD].UFLflag,UFLEFPROT);//~v557I~
		    setflddata(Ppcw,yy,PANL300LCMD," ");//clear input      //~v557I~
    		setflddata(Ppcw,yy,PANL300NAME," ");                   //~v557I~
          }                                                        //~v557I~
        }                                                          //~v20yI~
    }
	Supdatelistsw=0;       //ppc updated
	pan300selectline(Ppcw);//set reverse
	return 0;
}//pan300updatelist                                                //~v557R~
#ifdef UTF8SUPPH                                                    //~v90rI~//~va00R~
//**************************************************************** //~v90rI~//~va00I~
//* setup psd                                                      //~v90rI~//~va00I~
//**************************************************************** //~v90rI~//~va00I~
int pan300attr(PUCLIENTWE Ppcw,int Prow,PUSCRD Ppsd)               //~v90rI~//~va00I~
{                                                                  //~v90rI~//~va00I~
	PUP300LIST psc;                                              //~v90rR~//~va00R~
    PUPANELC ppc;		//pannel buff                              //~va00I~
    PUPANELL pupl;                                                 //~va00I~
    char *pct;                                                     //~va00R~
    int fnmlen;                                                    //~va00I~
//************************************                             //~v90rI~//~va00I~
    if (Prow>=PANL300LISTTOP)                                      //~v90rI~//~va00I~
    {                                                              //~v90rI~//~va00I~
	    if (!(psc=pan300getpsc(Prow+Ppcw->UCWtopfnlist)))          //~v90rI~//~va00I~
    		return 0;                                              //~v90rI~//~va00I~
    	if (psc->U3Lflag & U3LFF2L)//utf8 coed contained           //~va00R~
        	pan300fnmattr(Ppcw,Ppsd,psc,Prow);                     //~v90rR~//~va00I~
    }                                                              //~v90rI~//~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
	    ppc=Ppcw->UCWppc;                                          //~va00I~
        pupl=ppc->UPCline+Prow;                                    //~va00I~
        pct=pupl->UPLcodetype;                                     //~va00R~
        if (pupl->UPLflags & UPLFUTF8)	//utf8 code                //~va00R~
        {                                                          //~va00I~
//  	    fnmlen=pupl->UPLctlen;                                 //~va00I~
        	fnmlen=(int)strlen(pupl->UPLbuff);                     //~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
			panutillf2dd(0,Ppcw,pupl,Ppsd,Prow,0/*fldno*/,fnmlen); //~vaubR~
#endif                                                             //~vaubI~
			pansetfnmattr(Ppcw,Ppsd,Prow,0/*fldno*/,pct,fnmlen);   //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
    return 0;                                                      //~v90rI~//~va00I~
}//pan300attr                                                      //~v90rI~//~va00I~
//**************************************************************** //~va00I~
// set drawing attr to filename list entry                         //~va00I~
//**************************************************************** //~va00I~
int pan300fnmattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUP300LIST Ppsc,int Prow)//~va00I~
{                                                                  //~va00I~
	char *pct;                                                     //~va00I~
    int netfnmlen;                                                 //~va00I~
//*****************                                                //~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	pct=Ppsc->U3Lddcode;                                           //~vaubI~
	netfnmlen=Ppsc->U3Lddlen;                                      //~vaubI~
	pansetfnmattr(Ppcw,Ppsd,Prow,PANL300NAME,pct,netfnmlen);       //~vaubI~
#else                                                              //~vaubI~
	pct=Ppsc->U3Lcodetype;                                         //~va00I~
	netfnmlen=Ppsc->U3Lnetfnmlenbylc;                              //~va00I~
  if (Ppsc->U3Lflag & U3LFSPACEEMBEDED)    //quotation ppreceding  //~va1AR~
	pansetfnmattr(Ppcw,Ppsd,Prow,PANL300NAME,pct-1,netfnmlen+1);   //~va1AI~
  else                                                             //~va1AI~
	pansetfnmattr(Ppcw,Ppsd,Prow,PANL300NAME,pct,netfnmlen);       //~va00I~
#endif                                                             //~vaubI~
    return 0;                                                      //~va00I~
}//pan300fnmattr                                                   //~va00I~
//**************************************************************** //~va00I~
// set drawing attr of filename line                               //~va00I~
//**************************************************************** //~va00I~
int pansetfnmattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow,int Pfldid,char *Pcodetype,int Plclen)//~va00R~
{                                                                  //~va00I~
	UFLDE  *pfle;                                                  //~va00I~
	char nattr,nattrutf8,*pattr,*pct,fgutf8;                       //~va00I~
    int len,ii,sdlen,fldoffs,fldlen,fldend,fnmend,netfnmlen;       //~va00I~
	char *pct2,*pattr2,*pc2,ct,*psddata,attr2;                     //~vb4gR~
    int jj,len0,len2;                                              //~vb4gR~
    int pospath;                                                   //~vbkcR~
//*****************                                                //~va00I~
	UTRACEP("%s:fldid=%x,row=%d,lclen=%d\n",UTT,Pfldid,Prow,Plclen);//~vb4gR~
//  Ppsd->USDuvioo=UVIOO_FORCELIGATURE|UVIOO_COMBINE;              //~vb4gR~
    Ppsd->USDuvioo=UVIOO_COMBINE;                                  //~vb4gI~
	pfle=getuflde(Ppcw,Prow,Pfldid);                               //~va00I~
    fldoffs=pfle->UFLstart;                                        //~va00I~
    fldend=pfle->UFLend;                                           //~va00I~
    fldlen=fldend-fldoffs;                                         //~va00I~
                                                                   //~va00I~
    pct=Pcodetype;                                                 //~va00R~
//  if (((PUPANELC)Ppcw->UCWppc)->UPCid!=PANFNAME                  //~va00R~
//  ||  Prow<PANL300LISTTOP)  //pct is U3Lcodetype                 //~va00R~
//  	pct+=fldoffs;                                              //~va00R~
    netfnmlen=Plclen;                                              //~va00I~
                                                                   //~va00I~
    sdlen=Ppsd->USDlen;                                            //~va00I~
    nattr=Ppsd->USDnattr;                                          //~va00I~
	fgutf8=XEUTF_FG_UTF8;                                          //~va00I~
	pattr=Ppsd->USDcell;                                           //~va00I~
    psddata=Ppsd->USDdata;                                         //~vb4gI~
    UTRACED("USDdata",psddata,sdlen);                              //~vb4gR~
    UTRACED("USDcell",pattr,sdlen);                              //~vbi3I~//~vbkcR~
    UTRACED("pct",pct,netfnmlen);                                  //~vb4gI~
    if (Ppsd->USDflag==USDFCELLSTR)	//err attr set                 //~va00I~
    {                                                              //~va00I~
    	pattr+=fldoffs+fldoffs+1;                                  //~va00I~
        len=sdlen/2-fldoffs;                                       //~va00I~
        len=min(len,fldlen);                                       //~va00I~
        len=min(len,netfnmlen);                                    //~va00I~
        len0=len;                                                  //~vb4gI~
        pospath=len0;                                              //~vbkcR~
		for (;len>0;len--,pattr+=2)     //char+attr                //~va00I~
        {                                                          //~va00I~
	       	if (*pct++==XEUTFCT_UTF8)                              //~va00R~
            {                                                      //~vb4gI~
//         		*pattr=(*pattr & 0xf0) | fgutf8;  //fg+bg	set green//~va00R~//~vb30R~
           		*pattr=(char)((*pattr & 0xf0) | fgutf8);  //fg+bg	set green//~vb30I~
                attr2=*pattr;	                                   //~vb4gI~
//              for (len2=len+1,pct2=pct-2,pattr2=pattr-2,pc2=psddata+fldoffs+len0-len-1;len2<=len0;len2--,pct2--,pattr2-=2,pc2--)//~vb4gR~//~vbkcR~
                for (len2=len+1,pct2=pct-2,pattr2=pattr-2,pc2=psddata+fldoffs+len0-len-1;len2<=pospath;len2++,pct2--,pattr2-=2,pc2--)//~vbkcR~
                {                                                  //~vb4gI~
                    if (*pct2)                                     //~vb4gI~
                        break;                                     //~vb4gI~
                    if (*pc2==DIR_SEPC||*pc2==FTP_DIR_SEPC||*pc2==FTP_REMOTEID)//~vb4gI~
                        break;                                     //~vb4gI~
	           		*pattr2=attr2;                                 //~vb4gR~
                }                                                  //~vb4gI~
                for (len--,pattr+=2,pc2=psddata+fldoffs+len0-len;len>0;len--,pattr+=2,pc2++)//~vb4gR~
                {                                                  //~vb4gI~
                    ct=*pct++;                                     //~vb4gI~
                    if (ct && ct!=XEUTFCT_UTF8) //locale dbcs      //~vb4gI~
                        break;                                     //~vb4gI~
                    if (!ct && (*pc2==DIR_SEPC||*pc2==FTP_DIR_SEPC))//~vb4gI~
                    {                                              //~vbkcI~
                    	pospath=len-1;                             //~vbkcR~
                        break;                                     //~vb4gI~
                    }                                              //~vbkcI~
                    *pattr=attr2;                                  //~vb4gR~
                }                                                  //~vb4gI~
            }                                                      //~vb4gI~
        }                                                          //~va00I~
    UTRACED("out reverse SDcell",Ppsd->USDcell,len0*2);      //~vb4gR~//+vbkcR~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        sdlen/=2;   //sdlen=byte length to cell count              //~vbkcI~
    	Ppsd->USDflag=USDFCELLSTR3;	//USDdata and USDcell          //~va00I~
//dup   Ppsd->USDuvioo=UVIOO_LIGATURE|UVIOO_COMBINE;               //~vb4fI~
    	pattr++;                                                   //~va00I~
        fnmend=fldoffs+netfnmlen;                                  //~va00I~
//      nattrutf8=(nattr & 0xf0) | fgutf8;  //fg+bg	set green      //~va00I~//~vb30R~
        nattrutf8=(char)((nattr & 0xf0) | fgutf8);  //fg+bg	set green//~vb30I~
		for (ii=0;ii<sdlen;ii++,pattr+=2)     //char+attr          //~va00I~
        {                                                          //~va00I~
        	if (ii>=fldoffs && ii<fnmend)                          //~va00I~
            {                                                      //~va00I~
	        	if (*pct++==XEUTFCT_UTF8)                          //~va00I~
                {                                                  //~vb4gI~
            		*pattr=nattrutf8;                              //~va00I~
                    for (jj=ii-1,pct2=pct-2,pattr2=pattr-2,pc2=psddata+ii-1;jj>=fldoffs;jj--,pct2--,pattr2-=2,pc2--)//~vb4gR~
                    {                                              //~vb4gI~
                    	if (*pct2)                                 //~vb4gI~
                        	break;                                 //~vb4gI~
                    	if (*pc2==DIR_SEPC||*pc2==FTP_DIR_SEPC||*pc2==FTP_REMOTEID)//~vb4gR~
                        	break;                                 //~vb4gI~
                        *pattr2=nattrutf8;                         //~vb4gI~
                    }                                              //~vb4gI~
                    for (ii++,pattr+=2,pc2=psddata+ii;ii<fnmend;ii++,pattr+=2,pc2++)//~vb4gR~
                    {                                              //~vb4gI~
                    	ct=*pct++;                                 //~vb4gI~
                    	if (ct && ct!=XEUTFCT_UTF8)	//locale dbcs  //~vb4gI~
                        {                                          //~vb4gI~
	    		        	*pattr=nattr;                          //~vb4gI~
                        	break;                                 //~vb4gI~
                        }                                          //~vb4gI~
                    	if (!ct && (*pc2==DIR_SEPC||*pc2==FTP_DIR_SEPC))//~vb4gI~
                        {                                          //~vb4gI~
	    		        	*pattr=nattr;                          //~vb4gI~
                        	break;                                 //~vb4gI~
                        }                                          //~vb4gI~
                        *pattr=nattrutf8;                          //~vb4gI~
                    }                                              //~vb4gI~
                }                                                  //~vb4gI~
                else                                               //~va00I~
	            	*pattr=nattr;                                  //~va00I~
            }                                                      //~va00I~
            else                                                   //~va00I~
            	*pattr=nattr;                                      //~va00I~
        }                                                          //~va00I~
    UTRACED("out SDcell",Ppsd->USDcell,sdlen*2);                    //~vb4gI~//+vbkcR~
    }                                                              //~va00I~
    return 0;                                                      //~va00I~
}//pansetfnmattr                                                   //~va00I~
#endif  //UTF8SUPPH                                                           //~v90rI~//~va00R~
//**************************************************************** //~v61fI~
//* get display lcmd                                               //~v61fI~
//* parm3:optional browse/edit cmd string                          //~v61uI~
//*ret cmdid                                                       //~v61fI~
//**************************************************************** //~v61fI~
int pan300getbecmd(PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pbecmd)   //~v61uR~
{                                                                  //~v61fI~
    int browsesw,lcmd,lcmdupper,lcmdlower;                         //~v61fI~
    int cmdid,subcmdid;                                            //~v61uI~
//************************************                             //~v61fI~
    if (Ppcw->UCWmenuopt==PANMOBROWSE)                             //~v61fI~
    {                                                              //~v61uI~
        browsesw=1;                                                //~v61fI~
        cmdid='b';                                                 //~v61uI~
    }                                                              //~v61uI~
    else                                                           //~v61fI~
    {                                                              //~v61uI~
        browsesw=0;                                                //~v61fI~
        cmdid='e';                                                 //~v61uI~
    }                                                              //~v61uI~
    lcmd=(Ppsc->U3Lflag & U3LFCMDMASK);                            //~v61fR~
    if (!lcmd)                                                     //~v61fI~
    {                                                              //~v61uI~
        lcmd=LCMDIDCH;                                             //~v61fI~
        subcmdid=0;                                                //~v61uI~
    }                                                              //~v61uI~
    else                                                           //~v61fI~
    {                                                              //~v61fI~
        lcmdupper=toupper(lcmd);                                   //~v61fI~
        lcmdlower=tolower(lcmd);                                   //~v61fI~
        if (lcmdlower=='b')//bin                                   //~v61fI~
        {                                                          //~v61uI~
            if (lcmd==lcmdlower)    //browse                       //~v61fI~
            {                                                      //~v61uI~
                lcmd='1';                                          //~v61fI~
                cmdid='b';                                         //~v61uI~
            }                                                      //~v61uI~
            else                    //edit                         //~v61fI~
            {                                                      //~v61uI~
                lcmd='2';                                          //~v61fI~
                cmdid='e';                                         //~v61uI~
            }                                                      //~v61uI~
            subcmdid='b';   //bin                                  //~v61uI~
        }                                                          //~v61uI~
        else                                                       //~v61fI~
        {                                                          //~v61uI~
          if (lcmdlower!=lcmdupper)                                //~v75HI~
          {                                                        //~v75HI~
            if (lcmd==lcmdupper)    //upper,edit cmd               //~v61uR~
            {                                                      //~v61uR~
                if (!browsesw)      //edit                         //~v61uR~
                    lcmd=lcmdlower; //lower mean edit under edit scr//~v61uR~
                cmdid='e';                                         //~v61uI~
            }                                                      //~v61uR~
            else        //lower,browse cmd                         //~v61uR~
            {                                                      //~v61uR~
                if (!browsesw)      //edit                         //~v61uR~
                    lcmd=lcmdupper; //upper mean edit under browse scr//~v61uR~
                cmdid='b';                                         //~v61uI~
            }                                                      //~v61uR~
          }//upper!=lower                                          //~v75HI~
            subcmdid=lcmdlower;                                    //~v61uI~
        }                                                          //~v61uI~
    }                                                              //~v61fI~
    if (Pbecmd)                                                    //~v61uI~
    {                                                              //~v61uI~
        *Pbecmd=(char)cmdid;                                       //~v61uI~
        *(Pbecmd+1)=(char)subcmdid;                                //~v61uI~
        *(Pbecmd+2)=0;                                             //~v61uI~
    }                                                              //~v61uI~
    return lcmd;                                                   //~v61fI~
}//pan300getbecmd                                                  //~v61uR~
#ifdef UTF8SUPPH                                                   //~va1rI~
//**************************************************************** //~va1rI~
//* edit cmd string                                                //~va1rI~
//*   enclose by quote is filename has space                       //~va1rI~
//*   append cmd parm if used at original cmd                      //~va1rI~
//*ret cmd string len                                              //~va1rI~
//**************************************************************** //~va1rI~
int pan300editcmd_utf8(int Popt,PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pcmdu8,int Poffs,//~va1rI~
						char *Pcmdlc,char *Pcmdct,int *Pplclen)    //~va1rR~
{                                                                  //~va1rI~
	char *pfnm;                                                    //~va1rR~
	char *plc,*pct;                                                //~va1BI~
    int lencmd,lencmdlc,spacesw,offs,lenlc,lenu8,appendlen;        //~va1rR~
//************************************                             //~va1rI~
	pfnm=Pcmdu8+Poffs;                                             //~va1rI~
	lencmd=pan300editcmd(Ppcw,Ppsc,pfnm);	                       //~va1rI~
	spacesw=(Ppsc->U3Lflag & U3LFSPACEEMBEDED)!=0;                 //~va1BR~
    offs=Poffs+spacesw;                                            //~va1rI~
    memcpy(Pcmdlc,Pcmdu8,(UINT)offs);   //copy cmdid               //~va1rI~
    lenlc=Ppsc->U3Lnetfnmlenbylc;                                  //~va1rI~
    UmemcpyZ(Pcmdlc+offs,Ppsc->U3Lfnmbylc,(UINT)lenlc);              //~va1rR~//~va1AR~
    memset(Pcmdct,0,(UINT)offs);                                   //~va1rI~
    memcpy(Pcmdct+offs,Ppsc->U3Lcodetype,(UINT)lenlc);             //~va1rI~
    plc=Pcmdlc+offs+lenlc;                                         //~va1BI~
    pct=Pcmdct+offs+lenlc;                                         //~va1BI~
    if (spacesw)                                                   //~va1BI~
    {                                                              //~va1BI~
    	*plc++=*pfnm;   //same quotatuion as start                 //~va1BI~
    	*plc=0;                                                    //~va1BR~
        *pct++=0;                                                  //~va1BI~
    }                                                              //~va1BI~
  if (Popt & P3ECU8O_NOOPTION)   //drop option parm                //~va1AI~
	appendlen=0;                                                   //~va1AI~//~va1BR~
  else                                                             //~va1AI~
  {                                                                //~va1AI~
    lenu8=Ppsc->U3Lnetfnmlen;                                      //~va1rI~//~va1AM~
    appendlen=lencmd-lenu8-spacesw-spacesw;		//postfix len              //~va1rI~//~va1AM~//~va1BR~
    UmemcpyZ(plc,pfnm+lencmd-appendlen,(UINT)appendlen);//~va1rR~//~va1AM~//~va1BR~
    memset(pct,0,(UINT)appendlen);                   //~va1rR~//~va1AM~//~va1BR~
  }                                                                //~va1AI~
//  lencmdlc=(ULONG)plc-(ULONG)Pcmdlc+appendlen;                   //~va1BR~//~vafkR~
//  lencmdlc=(ULPTR)plc-(ULPTR)Pcmdlc+appendlen;                   //~vafkI~//~vb2FR~
    lencmdlc=PTRDIFF(plc,Pcmdlc)+appendlen;                        //~vb2FI~
    if (Pplclen)                                                   //~va1rI~
    	*Pplclen=lencmdlc;                                         //~va1rR~
    return lencmd;                                                 //~va1rI~
}//pan300editcmd_utf8                                              //~va1rI~
//**************************************************************** //~va5tM~
//pan300lf2dd                                                      //~vaubR~
//conv to mixed string to dd fmt for filename hdr line             //~va5tM~
//rc:1 ddfmt set,0:no utf8 code                                    //~va5tI~
//**************************************************************** //~va5tM~
int pan300lf2dd(int Popt,PUP300LIST Ppsc,char *Pdatalc,char *Pdbcs)//~va5tM~
{                                                                  //~va5tM~
    int outlen;                                                    //~vaubI~
	UCHAR *pdddbcs;                                                //~vaubI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
#else                                                              //~vaubI~
	UCHAR *pct,*pu8,*plc,*pdddata;                                 //~vaubR~
    int lenu8,lenlc,rc;                                            //~vaubR~
#endif                                                             //~vaubI~
//*****************************                                    //~va5tM~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
	outlen=Ppsc->U3Lddlen;                                         //~vaubI~
  	pdddbcs=Ppsc->U3Ldddbcs;                                       //~vaubI~
#else                                                              //~vaubI~
  {                                                                //~vaubI~
    lenu8=Ppsc->U3Lnetfnmlen;                                      //~va5tM~
    pu8=Ppsc->U3Lfnm;	//filename                                 //~va5tM~
    lenlc=Ppsc->U3Lnetfnmlenbylc;                                  //~va5tM~
    plc=Ppsc->U3Lfnmbylc;	//filename by locale code              //~va5tM~
    pct=Ppsc->U3Lcodetype;                                         //~va5tM~
    setdbcstbl(plc,Pdbcs,lenlc);                                   //~va5tM~
	if ((rc=xeutfcvlf2dd(0,pu8,lenu8,0/*pdbcs*/,pct,lenlc,&pdddata,&pdddbcs,lenlc,&outlen))>4)//~va5tR~
    	return 4;                                                  //~va5tM~
    if (!(rc & XEUTFF2LRC_UTF8))  //not utf8 code detected         //~va5tR~
    	return 0;                                                  //~va5tI~
  }                                                                //~vaubI~
	memcpy(Pdatalc,pdddata,outlen);   //ddstr                      //~va5tM~
#endif                                                             //~vaubM~
//  memcpy(Pdbcs,pdddbcs,outlen);   //ddstr                        //~va5tM~//~vb30R~
    memcpy(Pdbcs,pdddbcs,(size_t)outlen);   //ddstr                //~vb30I~
	UTRACED("pan300lf2dd Pdbcs",Pdbcs,outlen);                     //~vaubI~
	Ppsc->U3Lflag|=U3LFDRAWDD;    //editcmd at drawing by dd fmt   //~va5tR~
    return 1;                                                      //~va5tR~
}//pan300lf2dd                                                     //~va5tR~
#endif                                                             //~va1rI~
//**************************************************************** //~v61cI~
//* edit cmd string                                                //~v61cR~
//*   enclose by quote is filename has space                       //~v61cI~
//*   append cmd parm if used at original cmd                      //~v61cI~
//*ret cmd string len                                              //~v61cI~
//**************************************************************** //~v61cI~
int pan300editcmd(PUCLIENTWE Ppcw,PUP300LIST Ppsc,char *Pcmdstr)   //~v61cR~
{                                                                  //~v61cI~
	char *pc,*pco;                                                 //~v61cR~
    int len;                                                       //~v61cR~
#ifdef UTF8SUPPH                                                   //~va00I~
	int netfnmlen;                                                 //~va00I~
    char *pdbcs;                                                   //~va5tI~
    int swddfmt=0,fnmoffs=0;                                       //~va5tR~
#endif                                                             //~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    int fnmcopylen;                                                //~vaubI~
    char *fnmcopysrc;                                              //~vaubI~
#endif                                                             //~vaubI~
//************************************                             //~v61cI~
#ifdef UTF8SUPPH                                                   //~va00I~
	if (!(Ppsc->U3Lflag & U3LFUTF8CHKED))	//1st time to display  //~va00R~
    {                                                              //~va00I~
		pan300editcmdf2l(0,Ppsc);                                  //~va00I~
    }                                                              //~va00I~
  if (Ppsc->U3Lflag & U3LFDRAW)     //for drawing                  //~va00I~
  {                                                                //~va00I~
  	Ppsc->U3Lflag &=~U3LFDRAW;                                     //~va00I~
    pc=Ppsc->U3Lfnmbylc;	//filename by locale code              //~va00R~
    netfnmlen=Ppsc->U3Lnetfnmlenbylc;                              //~va00I~
//#ifdef LNX   //ddfmt even if lc                                    //~vaubM~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    fnmcopylen=Ppsc->U3Lddlen;                                     //~vaubI~
    fnmcopysrc=Ppsc->U3Ldddata;                                    //~vaubI~
#else                                                              //~vaubM~
	if (Ppsc->U3Lflag & U3LFF2L)	//translated to locale code    //~va5tI~
#endif                                                             //~vaubM~
    	swddfmt=1;   //output ddfmt if contains utf8 code          //~va5tI~
  }                                                                //~va00I~
  else                                                             //~va00I~
  {                                                                //~va00I~
    netfnmlen=Ppsc->U3Lnetfnmlen;                                  //~va00I~
#endif                                                             //~va00I~
    pc=Ppsc->U3Lfnm;	//filename                                 //~v61cR~
//#ifdef LNX   //ddfmt even if lc                                    //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    fnmcopylen=netfnmlen;                                          //~vaubI~
    fnmcopysrc=pc;                                                 //~vaubI~
#endif                                                             //~vaubI~
#ifdef UTF8SUPPH                                                   //~va00I~
  }                                                                //~va00I~
#endif                                                             //~va00I~
    pco=Pcmdstr;                                                   //~v61cI~
    if (Ppsc->U3Lflag & (U3LFPARM|U3LFSPACEEMBEDED))               //~v61cR~
    {                                                              //~v61cI~
#ifdef UTF8SUPPH                                                   //~va00I~
    	len=netfnmlen;                                             //~va00I~
#else                                                              //~va00I~
    	len=Ppsc->U3Lnetfnmlen;                                    //~v61cI~
#endif                                                             //~va00I~
	    if (Ppsc->U3Lflag & U3LFSPACEEMBEDED)                      //~v61cR~
        	*pco++='\"';                                           //~v61cI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//      memcpy(pco,fnmcopysrc,fnmcopylen);                         //~vaubR~//~vb30R~
        memcpy(pco,fnmcopysrc,(size_t)fnmcopylen);                 //~vb30I~
#else                                                              //~vaubI~
        memcpy(pco,pc,(UINT)len);                                  //~v61cI~
#endif                                                             //~vaubI~
//      fnmoffs=(ULONG)pco-(ULONG)Pcmdstr;                         //~va5tI~//~vafkR~
//      fnmoffs=(ULPTR)pco-(ULPTR)Pcmdstr;                         //~vafkI~//~vb2FR~
        fnmoffs=PTRDIFF(pco,Pcmdstr);                              //~vb2FI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	    pco+=fnmcopylen;                                           //~vaubR~
#else                                                              //~vaubI~
        pco+=len;                                                  //~v61cI~
#endif                                                             //~vaubI~
        pc+=len+1;	//input pos                                    //~v61cI~
	    if (Ppsc->U3Lflag & U3LFSPACEEMBEDED)                      //~v61cR~
        	*pco++='\"';                                           //~v61cI~
	    if (Ppsc->U3Lflag & U3LFPARM)                              //~v61cI~
        {                                                          //~v61cI~
          if (!Sspacelcmd) //spce cmd drop parm                    //~v61fI~
          {                                                        //~v61fI~
            *pco++=' ';                                            //~v61cI~
        	len=(int)strlen(pc);                                   //~v61cI~
        	memcpy(pco,pc,(UINT)len);                              //~v61cI~
            pco+=len;                                              //~v61cI~
          }                                                        //~v61fI~
        }                                                          //~v61cI~
        *pco=0;                                                    //~v61cI~
		UTRACED("pan300editcmd out with patrm",Pcmdstr,PTRDIFF(pco,Pcmdstr));//~vaubI~
    }                                                              //~v61cI~
    else                                                           //~v61cI~
    {                                                              //~vaubI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//      UmemcpyZ(pco,fnmcopysrc,fnmcopylen);                       //~vaubR~//~vb30R~
        UmemcpyZ(pco,fnmcopysrc,(size_t)fnmcopylen);               //~vb30I~
        pco+=fnmcopylen;                                           //~vaubR~
		UTRACED("pan300editcmd out",Pcmdstr,PTRDIFF(pco,Pcmdstr)); //~vaubR~
#else                                                              //~vaubI~
    	strcpy(pco,pc);                                            //~v61cR~
#endif                                                             //~vaubI~
    }                                                              //~vaubI~
//  return (int)strlen(Pcmdstr);                                   //~v61cR~//~va5tR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    len=PTRDIFF(pco,Pcmdstr);                                      //~vaubI~
#else                                                              //~vaubI~
    len=(int)strlen(Pcmdstr);                                      //~va5tI~
#endif                                                             //~vaubM~
    if (swddfmt)                                                   //~va5tI~
    {                                                              //~va5tI~
    	pdbcs=Pcmdstr+len+1;                                       //~va5tI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//      memset(pdbcs,0,len);                                       //~vaubI~//~vb30R~
        memset(pdbcs,0,(size_t)len);                               //~vb30I~
#endif                                                             //~vaubI~
        pdbcs+=fnmoffs;                                            //~va5tR~
        pc=Pcmdstr+fnmoffs;                                        //~va5tR~
		pan300lf2dd(0,Ppsc,pc,pdbcs);                              //~va5tR~
    }                                                              //~va5tI~
	UTRACEP("pan300editcmd return len=%d\n",len);                  //~vaubI~
    return len;                                                    //~va5tI~
}//pan300editcmd                                                   //~v61cR~
#ifndef UNX                                                        //~v54vI~
//**************************************************************** //~v54vI~
//* draw drivid list                                               //~v54vI~
//**************************************************************** //~v54vI~
int pan300drawdid(PUCLIENTWE Ppcw)                                 //~v54vI~
{                                                                  //~v54vI~
#ifdef AAA                                                         //~v54vI~
    PUPANELC ppc;		//pannel buff                              //~v54vM~
	PUSCRD psd;                                                    //~v54vI~
    UFLDE  *pfle;                                                  //~v54vR~
    int xx,fldno,did,offs,oldfldno,ii;                             //~v54vR~
    char drvid[4];                                                 //~v54vR~
    ULONG errflg,bitmask;                                          //~v54vR~
//************************************                             //~v54vI~
	psd=Ppcw->UCWpsd+PANL300DRIVE;                                 //~v54vM~
	ppc=Ppcw->UCWppc;			//client panel control             //~v54vI~
    errflg=ppc->UPCline[PANL300DRIVE].UPLerrflag;	//prev value   //~v54vI~
    bitmask=(0x80000000>>PANF300DRIVEIDLIST);                      //~v54vR~
    for (ii=0,oldfldno=-1;ii<26;ii++)   //chk prev driveid fldno   //~v54vR~
    {                                                              //~v54vI~
        if (errflg & bitmask)                                      //~v54vR~
        {                                                          //~v54vI~
        	oldfldno=ii;                                           //~v54vI~
            break;                                                 //~v54vI~
        }                                                          //~v54vI~
        bitmask>>=1;                                               //~v54vI~
    }                                                              //~v54vI~
    pfle=(UFLDE*)getuflde(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST);   //~v54vM~
	UCBITON(psd->USDflag2,USDF2DRAW);                              //~v54vM~
    xx=Ppcw->UCWrcsrx;      //  cursor line                        //~v54vM~
    offs=xx-pfle->UFLstart;                                        //~v54vM~
    did=0;                                                         //~v54vI~
    if (offs>=-1 && offs<26*2) //cs is in driveid list fld         //~v54vR~
    {                                                              //~v54vI~
        fldno=(offs+1)/2;                                          //~v54vI~
        if (offs%2)	//in between fld                               //~v54vI~
        	if(fldno==oldfldno)                                    //~v54vI~
            	fldno--;                                           //~v54vI~
        if (fldno>=0)                                              //~v54vI~
        {                                                          //~v54vI~
	    	getfldinput(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST+fldno,drvid);//~v54vR~
    		did=*drvid;                                            //~v54vR~
        }                                                          //~v54vI~
    }                                                              //~v54vI~
    ppc->UPCline[PANL300DRIVE].UPLerrflag=0;	//all clear        //~v54vI~
    if (did)	//on drive id fld                                  //~v54vI~
    {                                                              //~v54vI~
		panflderr(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST+fldno,PANFESET);	//set err reverse on cur csr//~v54vI~
        if (offs%2)                                                //~v54vI~
    		csronthefld(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST+fldno,0);   //move csr to lcmd fld//~v54vI~
    }                                                              //~v54vI~
#else                                                              //~v54vI~
	PUSCRD psd;                                                    //~v54vI~
    UFLDE  *pfle;                                                  //~v54vI~
    int xx,offs,datalen;                                           //~v54vR~
    char didlist[64],did;                                          //~v54vR~
//************************************                             //~v54vI~
	psd=Ppcw->UCWpsd+PANL300DRIVE;                                 //~v54vI~
    pfle=(UFLDE*)getuflde(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST);   //~v54vI~
    datalen=getfldinput(Ppcw,PANL300DRIVE,PANF300DRIVEIDLIST,didlist);//~v54vR~
    xx=Ppcw->UCWrcsrx;      //  cursor line                        //~v54vI~
    offs=xx-pfle->UFLstart;                                        //~v54vI~
    if (!(offs>=0 && offs<datalen))                                //~v54vR~
    	return 0;                                                  //~v54vI~
    did=*(didlist+offs);                                           //~v54vI~
    if (did==' ')                                                  //~v54vI~
    	return 0;                                                  //~v54vI~
//  panflderr(Ppcw,PANL300DRIVE,PANF300DRIVEID,PANFESET);	//set err reverse on cur csr//~v54vR~
    didlist[0]=did;                                                //~v54vI~
    didlist[1]=0;                                                  //~v54vI~
    datalen=setflddata(Ppcw,PANL300DRIVE,PANF300DRIVEID,didlist);  //~v54vR~
	UCBITON(psd->USDflag2,USDF2DRAW);                              //~v54vM~
    pan300setcpath(Ppcw,did);                                      //~v54vR~
	psd=Ppcw->UCWpsd+PANL300CURRENT;                               //~v54vI~
	UCBITON(psd->USDflag2,USDF2DRAW);                              //~v54vI~
#endif                                                             //~v54vI~
	return did;                                                    //~v54vR~
}//pan300drawdid                                                   //~v54vI~
#endif                                                             //~v54vI~
#ifdef UTF8SUPPH                                                   //~va1yI~
//**************************************************               //~va1yI~
//*pan300stackchkcmdbuff                                           //~va1yI~
//*chk part of fpathname remains on Gcmdbuff                       //~va1yI~
// if remains get kbd input codetbl                                //~va1yI~
//output offset and lclen to static area                           //~va1yI~
//rc:0 mot utf8,1:utf8 code remains on cmdbuff,3(optional):remains but not utf8//~vavcI~
//**************************************************               //~va1yI~
int pan300stackchkcmdbuff(int Popt,char *Pfpath)                   //~va1yI~
{                                                                  //~va1yI~
	char *pc,*pc2;                                                 //~va1yR~
    int lenu8,lenfpath,offsinfpath,offsfnmp,lenlc;                 //~va1yI~
    int opt;                                                       //~va5rI~
#ifdef W32UNICODE   //offsinfpath is not valid when UD sign was appended//~vavpI~
    int swlastUD=0;                                                //~vavpR~
#endif                                                             //~vavpI~
//**************************************************               //~va1yI~
//get filename on cmd buff                                         //~va1yI~
	pc=strchr(Gcmdbuffu8,' ');                                     //~va1yR~
    if (!pc)                                                       //~va1yI~
    	return 0;                                                  //~va1yI~
    pc+=strspn(pc," ");                                            //~va1yI~
    if (*pc=='\"')                                                 //~va1yI~
    {                                                              //~va1yI~
        pc++;                                                      //~va1yI~
        pc2=strchr(pc,'\"');                                       //~va1yI~
        if (!pc2)                                                  //~va1yI~
        	return 0;                                              //~va1yI~
//      lenu8=(int)((ULONG)pc2-(ULONG)pc);                         //~va1yR~//~vafkR~
        lenu8=(int)((ULPTR)pc2-(ULPTR)pc);                         //~vafkI~
    }                                                              //~va1yI~
    else                                                           //~va1yI~
    {                                                              //~va1yI~
        pc2=strchr(pc,' ');                                        //~va1yI~
        if (!pc2)                                                  //~va1yR~
            lenu8=(int)strlen(pc);                                 //~va1yI~
        else                                                       //~va1yI~
//        	lenu8=(int)((ULONG)pc2-(ULONG)pc);                     //~va1yR~//~vafkR~
        	lenu8=(int)((ULPTR)pc2-(ULPTR)pc);                     //~vafkI~
    }                                                              //~va1yI~
 if (!(Popt & P3SCCBO_CHKFULLPARMFNAME))//no preceding ascii chk   //~vavaR~
    for (;lenu8>0;pc++,lenu8--)   //for skip compre preceding ..\ etc//~va1yI~
        if (!UTF8ISASCII(*pc))                                     //~va1yI~
            break;                                                 //~va1yI~
//*                                                                //~va1yI~
//  offsfnmp=(int)((ULONG)pc-(ULONG)Gcmdbuffu8);                   //~va1yR~//~vafkR~
    offsfnmp=(int)((ULPTR)pc-(ULPTR)Gcmdbuffu8);                   //~vafkI~
	lenfpath=(int)strlen(Pfpath);                                  //~va1yI~
    offsinfpath=lenfpath-lenu8;                                    //~va1yI~
    if (offsinfpath<0                                      //fnm is tail of fpath usualy//~va1yI~
    ||  memcmp(Pfpath+offsinfpath,pc,(UINT)lenu8)    //fail if ..\ etc used//~va1yI~
    )                                                              //~va1yI~
    {                                                              //~vavpI~
#ifdef W32UNICODE   //offsinfpath is not valid when UD sign was appended//~vavcI~//~vavpM~
      if (offsinfpath>0                                      //fnm is tail of fpath usualy//~vavpR~
      &&  *(Pfpath+lenfpath-1)==UD_NOTLC                           //~vavpR~
      &&  !memcmp(Pfpath+offsinfpath-1,pc,(UINT)lenu8)    //fail if ..\ etc used//~vavpR~
      )                                                            //~vavpI~
      {                                                            //~vavpI~
      	swlastUD=1;                                                //~vavpR~
        offsinfpath--;  //shift 1 to low addr                      //~vavpI~
      }                                                            //~vavpI~
      else                                                         //~vavpI~
#endif                                                           //~vavcI~//~vavpI~
    	return 0;	//that cmd is not for edit cmd of this file	   //~va1yI~
    }                                                              //~vavpI~
	if (!memcmp(Gcmdbuffu8+offsfnmp,Gcmdbufflc+offsfnmp,(UINT)lenu8))	//no utf8 code//~va1yI~
    {                                                              //~vavcI~
    	if (Popt & P3SCCBO_RCIFLC)             //set rc=3 if U8=LC //~vavcI~
        	return 3;                                              //~vavcI~
    	return 0;                                                  //~va1yR~
    }                                                              //~vavcI~
//  if (xeutf_memcmpu8lc(XEUTFMC8LO_CHKLCLEN,Gcmdbuffu8+offsfnmp,lenu8,Gcmdbufflc+offsfnmp,Gcmdbufflclen-offsfnmp,&lenlc))//~va5rR~
    opt=XEUTFMC8LO_CHKLCLEN|XEUTFMC8LO_ALLOWREPCH;  //accept repch "?" as valid for cmd retrieve chk//~va5rI~
#ifdef LNX                                                         //~vaumI~
	opt|=XEUTFMC8LO_DDWREPCH;	//f2l err ok                       //~vaumI~
#endif                                                             //~vaumI~
    if (xeutf_memcmpu8lc(opt,Gcmdbuffu8+offsfnmp,lenu8,Gcmdbufflc+offsfnmp,Gcmdbufflclen-offsfnmp,&lenlc))//~va5rI~
    	return 0;		//lclen gent fail                          //~va1yI~
    Scmdbuffoffsfnmp=offsfnmp;        //filename parameter position//~va1yI~
    Scmdbuffoffsinfpath=offsinfpath;      //parm fnm position infpath//~va1yI~
    Scmdbufflenu8=lenu8;        //filename parameter len by utf8   //~va1yI~
    Scmdbufflenlc=lenlc;        //filename parameter len by locale code//~va1yI~
#ifdef W32UNICODE   //offsinfpath is not valid when UD sign was appended//~vavpI~
    SswlastUD=swlastUD;                                            //~vavpI~
#endif                                                             //~vavpI~
    return 1;	//codetbl gotten from Gcmdbuffct                   //~va1yI~
}//pan300stackchkcmdbuff                                           //~va1yI~
//**************************************************               //~va1yI~
//int pan300stacksetctfromcmdbuff(int Popt,PUP300LIST Ppsc)        //~va1BI~
//int pan300stacksetctfromcmdbuffsub(int Popt,char *Ppu8,char *Pplc,char *Ppct,int Pbuffsz)//~vaubR~
int pan300stacksetctfromcmdbuffsub(int Popt,char *Ppu8,char *Pplc,char *Ppct,int Pbuffsz,//~vaubI~
    		char *Pdddata,char *Pdddbcs,char *Pddcode,int Pddbuffsz,int *Ppddlen)//~vaubR~
{                                                                  //~va1yI~
	char *plc,*pct,*pwklc,*pwkct,*pwklc0,*pwkct0,*pu8;             //~va1yR~
//  char wkfpathlc[2][_MAX_PATH*UTF8_F2LMAXRATE];                  //~va1yR~//~vav9R~
//  char wkfpathct[2][_MAX_PATH*UTF8_F2LMAXRATE];                  //~va1yR~//~vav9R~
    char wkfpathlc[2][_MAX_PATHF2L];                               //~vav9I~
    char wkfpathct[2][_MAX_PATHF2L];                               //~vav9I~
    int /*lenfpath,*/offsinfpath,offsfnmp,lenlc1,lenlc;                //~va1yR~//~vaa7R~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
	int ddlen=0,ddlen2;                                            //~vaubI~
#endif                                                             //~vaubI~
//**************************************************               //~va1yI~
    offsinfpath=Scmdbuffoffsinfpath;                               //~va1yR~
    offsfnmp=Scmdbuffoffsfnmp;                                     //~va1yI~
    lenlc=Scmdbufflenlc;                                           //~va1yI~
                                                                   //~va1yI~
//  pu8=Ppsc->U3Lfnm;                                              //~va1yI~//~va1BR~
    pu8=Ppu8;                                                      //~va1BI~
//  lenfpath=(int)strlen(pu8);                                     //~va1yR~//~vaa7R~
	pwklc=pwklc0=wkfpathlc[1];	 //accum wk                        //~va1yI~
	pwkct=pwkct0=wkfpathct[1];                                     //~va1yI~
//*getlocalecode for the part before parm fname                    //~vavaI~
    if (offsinfpath)                                               //~va1yR~
    {                                                              //~va1yI~
        plc=wkfpathlc[0];       //locale                           //~va1yI~
        pct=wkfpathct[0];   //codetype                             //~va1yI~
//      xeutf_getlocalepathname(XEUTFGLPNO_STRZ,pu8,offsinfpath,plc,pct,sizeof(wkfpathlc[0]),&lenlc1);//~vauaR~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
     if (Pdddbcs)                                                  //~vaubI~
     {                                                             //~vaubI~
        int opt=XEUTFGLPNO_STRZ|XEUTFGLPNO_LCWIDTHBYDDWIDTH;       //~vaubR~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME fullpath?:==NO,NOT FIXED                                   //~vavcI~//~vavxR~
        if (uftpisremote(pu8,NULL))                                //~vavcI~
        	opt|=XEUTFGLPNO_REMOTE;                                //~vavcI~
#endif                                                             //~vavcI~
        xeutf_getlocalepathname(opt,pu8,offsinfpath,plc,pct,sizeof(wkfpathlc[0]),&lenlc1,Pdddata,Pdddbcs,Pddcode,Pddbuffsz,&ddlen);//~vaubR~
     }                                                             //~vaubI~
     else                                                          //~vaubI~
#endif                                                             //~vaubI~
        xeutf_getlocalepathname(XEUTFGLPNO_STRZ,pu8,offsinfpath,plc,pct,sizeof(wkfpathlc[0]),&lenlc1,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vauaI~
        memcpy(pwklc,plc,(UINT)lenlc1);                            //~va1yI~
        memcpy(pwkct,pct,(UINT)lenlc1);                            //~va1yI~
        pwklc+=lenlc1;                                             //~va1yI~
        pwkct+=lenlc1;                                             //~va1yI~
    }                                                              //~va1yI~
    else                                                           //~va1yI~
    	lenlc1=0;                                                  //~va1yI~
                                                                   //~va1yI~
    memcpy(pwklc,Gcmdbufflc+offsfnmp,(UINT)lenlc);                 //~va1yR~
    memcpy(pwkct,Gcmdbuffct+offsfnmp,(UINT)lenlc);                 //~va1yR~
#ifdef W32UNICODE   //offsinfpath is not valid when UD sign was appended//~vavpI~
    if (SswlastUD)                                                 //~vavpI~
    {                                                              //~vavpI~
	    *(pwklc+lenlc)=UD_NOTLC;;                                  //~vavpI~
        *(pwkct+lenlc)=0;                                          //~vavpI~
        lenlc++;                                                   //~vavpI~
    }                                                              //~vavpI~
#endif                                                             //~vavpI~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
    if (Pdddbcs)                                                   //~vaubI~
    {                                                              //~vaubI~
        int opt,offs;                                              //~vaumR~
		opt=XEUTFCVLF2DAO_CHKERRREP;	//chk valid err rep(already adjusted)//~vaumI~
        offs=offsinfpath;                                          //~vaubI~
//      xeutfcvlf2ddAdjust(opt,pu8+offs,strlen(pu8+offs),pwkct,lenlc,//~vaumR~
//      xeutfcvlf2ddAdjust(opt,pu8+offs,strlen(pu8+offs),pwklc,pwkct,lenlc,//~vaumI~//~vb30R~
        xeutfcvlf2ddAdjust(opt,pu8+offs,(int)strlen(pu8+offs),pwklc,pwkct,lenlc,//~vb30I~
        				Pdddata+ddlen,Pdddbcs+ddlen,Pddcode+ddlen,Pddbuffsz-ddlen,&ddlen2);//~vaubI~
        *Ppddlen=ddlen+ddlen2;                                     //~vaubR~
        UTRACED("dddata",Pdddata,*Ppddlen);                        //~vaubR~
        UTRACED("dddbcs",Pdddbcs,*Ppddlen);                        //~vaubR~
        UTRACED("ct    ",Pddcode,*Ppddlen);                        //~vaubR~
    }                                                              //~vaubI~
#endif                                                             //~vaubI~
    pwklc+=lenlc;                                                  //~va1yI~
    pwkct+=lenlc;                                                  //~va1yI~
    lenlc+=lenlc1;                                                 //~va1yI~
//* update psc                                                     //~va1yI~
//    plc=Ppsc->U3Lfnmbylc;       //locale                           //~va1yI~//~va1BR~
//    pct=Ppsc->U3Lcodetype;      //codetype                         //~va1yI~//~va1BR~
//    UmemcpyZ(plc,pwklc0,lenlc);                                    //~va1yR~//~va1BR~
//    memcpy(pct,pwkct0,lenlc);                                      //~va1yI~//~va1BR~
//    Ppsc->U3Lflag|=U3LFF2L; //translated to locale code            //~va1yI~//~va1BR~
//    Ppsc->U3Lnetfnmlenbylc=lenlc;                                  //~va1yI~//~va1BR~
    lenlc=min(Pbuffsz,lenlc);                                      //~va1BI~
//  UmemcpyZ(Pplc,pwklc0,lenlc);                                   //~va1BI~//~vb30R~
    UmemcpyZ(Pplc,pwklc0,(size_t)lenlc);                           //~vb30I~
//  memcpy(Ppct,pwkct0,lenlc);                                     //~va1BI~//~vb30R~
    memcpy(Ppct,pwkct0,(size_t)lenlc);                             //~vb30I~
    return lenlc;                                                  //~va1yI~
}//pan300stacksetctfromcmdbuffsub                                     //~va1yI~//~va1BR~
//**************************************************               //~va1BI~
//*pan300stacksetctfromcmdbuff                                     //~va1BR~
//*set lc/ct of psc from cmdbuff(set to pfh at wakeup fom fileregist)//~va1BR~
// return lenlc                                                    //~va1BI~
//**************************************************               //~va1BI~
int pan300stacksetctfromcmdbuff(int Popt,PUP300LIST Ppsc)          //~va1BI~
{                                                                  //~va1BI~
	char *plc,*pct/*,*pu8*/;                                           //~va1BR~//~vaa7R~
    int buffsz,lenlc;                                              //~va1BR~
    PUFILEH pfh;                                                   //~va1BI~
//**************************************************               //~va1BI~
    pfh=Sstackpfh; //parm to pan300stacksetctfromcmdbuff           //~va1BI~
//  pu8=Ppsc->U3Lfnm;                                              //~va1BI~//~vaa7R~
	plc=Ppsc->U3Lfnmbylc;		//locale                           //~va1BI~
	pct=Ppsc->U3Lcodetype;  	//codetype                         //~va1BI~
    buffsz=Ppsc->U3Lfnmlen*UTF8_F2LMAXRATE;                        //~va1BI~
//  lenlc=pan300stacksetctfromcmdbuffsub(Popt,pu8,plc,pct,buffsz); //~va1BR~
    lenlc=pfh->UFHfilenamebylclen;                                 //~va1BI~
    lenlc=min(buffsz-1,lenlc);                                     //~va1BR~
    memcpy(plc,pfh->UFHfilenamebylc,(UINT)(lenlc+1));              //~va1BR~
    memcpy(pct,pfh->UFHfilenamecodetype,(UINT)lenlc);              //~va1BR~
	Ppsc->U3Lflag|=U3LFF2L;	//translated to locale code            //~va1BI~
	Ppsc->U3Lnetfnmlenbylc=lenlc;                                  //~va1BI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	setpscddname(Ppsc,pfh->UFHfilenameddlen,pfh->UFHfilenamedddata,pfh->UFHfilenamedddbcs,pfh->UFHfilenameddct);//~vaubR~
#endif                                                             //~vaubI~
    return lenlc;                                                  //~va1BI~
}//pan300stacksetctfromcmdbuff                                     //~va1BI~
#endif                                                             //~va1yI~
//**************************************************
//*pan300stack
//*stack filename
//*parm1:string addr
//*parm2:string len
//*ret  :none
//**************************************************
//void pan300stack(PUCLIENTWE Ppcw,PUFILEH Ppfh)                   //~v61cR~
void pan300stack(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUCLIENTWE Pcmdpcw)  //~v61cR~
{
    FUNCTBL *pft;	//FUNKTBL ptr                                  //~v61cI~
    PUFILEC  pfc;                                                  //~v61cI~
	char *pc;
	char fpathcmd[_MAX_PATH+MAXCOLUMN];                            //~v61cR~
#ifdef W32UNICODE                                                  //~vavxI~
	char wkcmdstrip[_MAX_PATH+MAXCOLUMN];                          //~vavxR~
#endif                                                             //~vavxI~
    int opt;                                                       //~v557I~
    int lcmd=0,browsesw=0,len;                                     //~v61cR~
//**************************************************
    switch(Ppfh->UFHtype)
    {
    case UFHTCLIPBOARD:          //clipboard file in work dir
    case UFHTKFI      :          //key func ini file in work dir
    case UFHTSTDOUT   :          //first opened as cmd stdout
    case UFHTTEMPWK   :          //TEMP work for partial edit etc
    case UFHTTEMPWK2  :          //TEMP work for filenamelist find support//~v76mI~
    case UFHTCMDHIST  :          //TEMP work for filenamelist find support//~vbi3I~
        return;
    }
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13CB2))                       //~vaj0I~
    	return;                                                    //~vaj0I~
    if (Pcmdpcw)                                                   //~v61cM~
    {                                                              //~v61cM~
      	pft=Pcmdpcw->UCWpfunct;                                    //~v61cM~
      	if (pft)   //::cb etc,internaly called function has no pfunct//~v61cM~
      	{                                                          //~v61cM~
          	pfc=Pcmdpcw->UCWpfc;    //                             //~v61cM~
          	if (pfc)                                               //~v61cM~
              	browsesw=UCBITCHK(pfc->UFCflag,UFCFBROWSE)!=0;     //~v61cM~
//        	lcmd=pan300getlcmdfromfuncid(pft->FTfuncid,browsesw);  //~v61rR~
          	lcmd=pan300getlcmdfromfuncid(pft->FTfuncid,&browsesw); //~v61rI~
      	}                                                          //~v61cM~
  	}                                                              //~v61cM~
	pc=Ppfh->UFHfilename;
    if (len=pan300editfpath(Pcmdpcw,pc,lcmd,fpathcmd),len)//rep fnm of cmd string by fpath//~v61cR~
        pc=fpathcmd;    //quataion embedded or otherparm exist     //~v61cI~
    else                                                           //~v61cI~
    	len=(int)strlen(pc);                                       //~v61vR~
#ifdef W32UNICODE                                                  //~vavxI~
	if (memchr(pc,UD_NOTLC,len))                                   //~vavxI~
    {                                                              //~vavxI~
	    fsubw_stripUDCT(0,pc,len,wkcmdstrip,sizeof(wkcmdstrip),NULL/*ct*/,0/*sizeof(ct)*/,&len);//~vavxR~
        pc=wkcmdstrip;                                             //~vavxR~
    }                                                              //~vavxI~
#endif                                                             //~vavxI~
//  pan300addentry(pc,(int)strlen(pc),0);	//not init             //~v557R~
	if (FILEISREMOTE(Ppfh))                                        //~v557R~
    	opt=PAN300AEO_REMOTE;                                      //~v557I~
    else                                                           //~v557I~
    	opt=0;                                                     //~v557I~
//  pan300addentry(pc,(int)strlen(pc),opt);	//not init             //~v61cR~
    if (browsesw)                                                  //~v61rI~
        opt|=PAN300AEO_BROWSE;                                     //~v61rI~
    else                                                           //~v61rI~
        opt|=PAN300AEO_EDIT;                                       //~v61rI~
#ifdef UTF8SUPPH                                                   //~va1yI~
//  if (pan300stackchkcmdbuff(0,pc))	//locale name remains on cmd buff//~va1yI~//~va1BR~
    if (Ppfh->UFHfilenamebylclen>0)	//locale name remains on cmd buff//~va1BI~
    {                                                              //~va1BI~
        opt|=PAN300AEO_SETCT;                                      //~va1yI~
        Sstackpfh=Ppfh; //parm to pan300stacksetctfromcmdbuff      //~va1BI~
    }                                                              //~va1BI~
#endif                                                             //~va1yI~
    pan300addentry(pc,len,opt);	//not init                         //~v61cI~
    return;
}//pan300stack
//**************************************************               //~v61cI~
//*pan300editfpath                                                 //~v61cI~
//*rep filename in cmd string by fpath                             //~v61cI~
//*ret  :output string len,0:parm is (not quatation embedded)filename only//~v61cR~
//**************************************************               //~v61cI~
int pan300editfpath(PUCLIENTWE Ppcw,UCHAR *Pfpath,int Plcmd,UCHAR *Poutcmdstr)//~v61cR~
{                                                                  //~v61cI~
    int ii,opdno,len;                                              //~v61cR~
    UCHAR *pc,*pcout;                                              //~v61cR~
//*******************                                              //~v61cI~
	if (Ppcw)           //fileregist                               //~v61cR~
        opdno=Ppcw->UCWopdno;                                      //~v61cR~
    else                //dirregist                                //~v61cR~
        opdno=0;                                                   //~v61cM~
    if (opdno<=1 && !Plcmd)	//no special cmd and no other option   //~v61cR~
    	return 0;                                                  //~v61cI~
    pcout=Poutcmdstr;                                              //~v61cI~
    len=(int)strlen(Pfpath);                                       //~v61cR~
    memcpy(pcout,Pfpath,(UINT)len);                                //~v61cI~
    pcout+=len;                                                    //~v61cI~
    *pcout++=0;		//filename terminater                          //~v61cI~
	if (opdno>1)	//Ppcw!=0(not dir)                             //~v61cR~
    {                                                              //~v61cI~
        pc=Ppcw->UCWopdpot;                                        //~v61cR~
        for (ii=0;ii<opdno;ii++,pc+=len+1)                         //~v61cR~
        {                                                          //~v61cR~
        	len=(int)strlen(pc);                                   //~v61vR~
            if (ii>0)                                              //~v61cR~
            {                                                      //~v61cI~
            	if (ii>1)                                          //~v61cI~
			        *pcout++=' ';                                  //~v61cR~
                memcpy(pcout,pc,(UINT)len);                        //~v61cR~
                pcout+=len;                                        //~v61cI~
            }                                                      //~v61cI~
        }                                                          //~v61cR~
    }                                                              //~v61cI~
    *pcout++=0;                                                    //~v61cI~
    *pcout++=(UCHAR)Plcmd;                                         //~v61cR~
    *pcout=0;                                                      //~v61cI~
//  return (int)((ULONG)pcout-(ULONG)Poutcmdstr);		//edit required//~v61vR~//~vafkR~
    return (int)((ULPTR)pcout-(ULPTR)Poutcmdstr);		//edit required//~vafkI~
}//pan300editfpath                                                 //~v61cI~
#ifdef UTF8SUPPH                                                   //~va1yI~
//**************************************************               //~va1yI~
//*pan300chklcentry                                                //~va1yI~
//*update previous top entry lc name by read entry                 //~va1yI~
//*rc:1:this entry is lc entry of prev utf8 entry                  //~va1yI~
//**************************************************               //~va1yI~
int pan300chklcentry(int Popt,char *Preadfnm,int Preadlen)         //~va1yI~
{                                                                  //~va1yI~
	PUP300LIST psc;			//stack entry                          //~va1yI~
    char *pu8,*pct;                                                //~va1yR~
    int lenlc,lenu8,readparmlen,parmlen,buffsz,fnmlen;             //~va1yR~
    int opt;                                                       //~va5rI~
//*****************                                                //~va1yI~
	psc=UGETQTOP(&Sfnstack);                                       //~va1yI~
    if (!psc)                                                      //~va1yI~
    	return 0;                                                  //~va1yI~
    UTRACEP("U3L pan300chkentry prevpsc=%s\n",psc->U3Lfnm);        //~vavpR~
    UTRACED("U3L read",Preadfnm,Preadlen);                         //~vavpR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	if (Preadlen>2 && *Preadfnm==U3LDDFMTNAMEID && *(Preadfnm+1)==U3LDDFMTNAMEID)//~vaubR~
    {                                                              //~vaubI~
    	int ddlen;                                                 //~vaubI~
    	if (psc->U3Lddlen)                                         //~vaubI~
        {                                                          //~vaubI~
        	UTRACEP("U3L rc=1 ERR ddfmtname sequence for %s\n",psc->U3Lfnm);//~vavpR~
        	UTRACED("ERR ddfmtname",Preadfnm,Preadlen);            //~vaubI~
	    	return 1;	//ignore this entry                        //~vaubR~
        }                                                          //~vaubI~
        ddlen=(Preadlen-2)/3;                                      //~vaubR~
	    setpscddname(psc,ddlen,Preadfnm+2/*dddata*/,Preadfnm+2+ddlen/*dddbcs*/,Preadfnm+2+ddlen*2/*ddcode*/);//~vaubR~
    	UTRACEP("U3L rc=1;ddlen=%d\n",ddlen);                      //~vavpR~
    	return 1;  //updated previous entry , ignore this entry    //~vaubI~
    }                                                              //~vaubI~
#endif                                                             //~vaubR~
    if (psc->U3Lflag & U3LFF2L)	//alread set lc                    //~va1yI~
    {                                                              //~vavpI~
    	UTRACEP("U3L rc=0;already set lc\n");                      //~vavpI~
    	return 0;                                                  //~va1yI~
    }                                                              //~vavpI~
    pu8=psc->U3Lfnm;                                               //~va1yI~
    pct=psc->U3Lcodetype;                                          //~va1yI~
    lenu8=psc->U3Lnetfnmlen;                                       //~va1yI~
    lenlc=(int)ustrnlen(Preadfnm,(UINT)Preadlen);                  //~va1yR~
    fnmlen=psc->U3Lfnmlen;                                         //~va1yI~
    buffsz=fnmlen*UTF8_F2LMAXRATE;                                 //~va1yI~
//  if (xeutf_setctbyu8lc(0,pu8,lenu8,Preadfnm,lenlc,pct,buffsz))	//unmatch//~va5rR~
	opt=XEUTFSCBULO_ALLOWREPCH; //accept repch "?" as valid for cmd retrieve chk//~va5rI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    if (xeutf_setctbyu8lc(opt,pu8,lenu8,Preadfnm,lenlc,pct,buffsz)>1)   //detected '?' means replaced f2l err//~vaubI~
#else                                                              //~vaubI~
    if (xeutf_setctbyu8lc(opt,pu8,lenu8,Preadfnm,lenlc,pct,buffsz))	//unmatch//~va5rI~
#endif                                                             //~vaubI~
	{                                                              //~vavpI~
    	UTRACEP("U3L rc=0;setctbyu8lc rc!=0\n");                   //~vavpI~
    	return 0;                                                  //~va1yI~
    }                                                              //~vavpI~
    parmlen=fnmlen-lenu8;	//parm len,-1:drop for lcmd            //~va1yR~
    readparmlen=Preadlen-lenlc;                                    //~va1yI~
    if (parmlen<readparmlen		//u8 entry may contain lcmd        //~va1yR~
    ||  *(psc->U3Lfnm+lenu8+readparmlen)!=0	//parm size not same   //~va1yI~
    ||  memicmp(Preadfnm+lenlc,psc->U3Lfnm+lenu8,(UINT)readparmlen) //not same parm//~va1yR~
    )                                                              //~va1yI~
    {                                                              //~vavpI~
    	UTRACEP("U3L rc=0;unmatch\n");                             //~vavpI~
    	return 0;                                                  //~va1yI~
    }                                                              //~vavpI~
    psc->U3Lflag |=(U3LFF2L|U3LFUTF8CHKED);	//1st time to display  //~va1yR~
    psc->U3Lnetfnmlenbylc=lenlc;                                   //~va1yI~
//  UmemcpyZ(psc->U3Lfnmbylc,Preadfnm,Preadlen);                   //~va1yR~//~vb30R~
    UmemcpyZ(psc->U3Lfnmbylc,Preadfnm,(size_t)Preadlen);           //~vb30I~
    UTRACEP("U3L rc=1 fnmbylc=%s\n",psc->U3Lfnmbylc);              //~vavpR~
    return 1;                                                      //~va1yI~
}//pan300chklcentry                                                //~va1yI~
#endif                                                             //~va1yI~
//**************************************************
//*pan300addentry
//*stack filename,keep max entry count
//*parm1:string addr
//*parm2:string len
//*parm3:initialize at ini3(screen height is not yet initialized)
//*ret  :none
//**************************************************
void pan300addentry(UCHAR *Pfnm,int Pfnmlen,int Pinitsw)
{
	PUP300LIST psc;			//stack entry
#ifdef W32                                                         //~v557I~
    int remotesw;                                                  //~v61rR~
#endif                                                             //~v557I~
    int compsw;                                                    //~v61rI~
	int len,lcmd;                                                  //~v61rR~
   	int reslen,len2,flag=0;                                        //~v61kI~
    char *pc;                                                      //~v61cI~
//**************************************************
    if (!Pfnmlen)   //emptry enter
        return;
#ifdef W32                                                         //~v557I~
    remotesw=Pinitsw & PAN300AEO_REMOTE;                           //~v557I~
#endif                                                             //~v557I~
	for (psc=UGETQTOP(&Sfnstack);psc;psc=UGETQNEXT(psc))//chk same string
    {
//#ifdef W32                                                         //~v557 ~//~v61rR~
//        len=min(Pfnmlen,psc->U3Lfnmlen);                         //~v61rR~
//        if (remotesw)                                            //~v61rR~
////          compsw=memcmp(Pfnm,psc->U3Lfnm,(UINT)Pfnmlen);  //same text//~v61rR~
//            compsw=memcmp(Pfnm,psc->U3Lfnm,(UINT)len);  //same text//~v61rR~
//        else                                                     //~v61rR~
//        {                                                        //~v61rR~
////          compsw=memicmp(Pfnm,psc->U3Lfnm,(UINT)Pfnmlen); //same text//~v61rR~
//            len2=psc->U3Lnetfnmlen;                              //~v61rR~
//          if (len2 < len)                                        //~v61rR~
//          {                                                      //~v61rR~
//            compsw=memicmp(Pfnm,psc->U3Lfnm,(UINT)len2) //same text//~v61rR~
//                 ||memcmp(Pfnm+len2,psc->U3Lfnm+len2,(UINT)(len-len2)); //same text//~v61rR~
//          }                                                      //~v61rR~
//          else                                                   //~v61rR~
//            compsw=memicmp(Pfnm,psc->U3Lfnm,(UINT)len); //same text//~v61rR~
//        }                                                        //~v61rR~
//#endif                                                           //~v61rR~
//        if (Pfnmlen==psc->U3Lfnmlen                              //~v61rR~
//#ifdef UNX                                                       //~v61rR~
//        &&  !memcmp(Pfnm,psc->U3Lfnm,(UINT)Pfnmlen))    //same text//~v61rR~
//#else                                                            //~v61rR~
//  #ifdef W32                                                     //~v61rR~
//        &&  !compsw)    //same text                              //~v61rR~
//  #else                                                          //~v61rR~
//        &&  !memicmp(Pfnm,psc->U3Lfnm,(UINT)Pfnmlen))   //same text//~v61rR~
//  #endif                                                         //~v61rR~
//#endif                                                           //~v61rR~
        if (Pfnmlen!=psc->U3Lfnmlen)	//len not same             //~v61rI~
            continue;                                              //~v61rI~
        len=psc->U3Lnetfnmlen;                                     //~v61rI~
        len2=(int)ustrnlen(Pfnm,(UINT)Pfnmlen);                    //~v61vR~
        if (len!=len2)		//filename len not same                //~v61rI~
            continue;                                              //~v61rI~
#ifdef W32                                                         //~v557 ~//~v61rI~
        if (remotesw)                                              //~v61rI~
            compsw=memcmp(Pfnm,psc->U3Lfnm,(UINT)len);  //same text//~v61rI~
        else                                                       //~v61rI~
            compsw=memicmp(Pfnm,psc->U3Lfnm,(UINT)len); //same text//~v61rI~
#else                                                              //~v61rI~
        compsw=memcmp(Pfnm,psc->U3Lfnm,(UINT)len);  //same text    //~v61rI~
#endif                                                             //~v61rI~
        if (compsw)			//filename compare                     //~v61rI~
            continue;                                              //~v61rI~
        if (len==Pfnmlen)   //no parm                              //~v61rI~
			break;
        if (!memicmp(Pfnm+len,psc->U3Lfnm+len,(UINT)(Pfnmlen-len))) //same parm//~v61vR~
			break;                                                 //~v61rI~
    }
	if (psc)	//found
    {                                                              //~v61rI~
		UDEQ(UQUE_ENT,&Sfnstack,psc);	//deq to re-enq
        lcmd=psc->U3Lflag & U3LFCMDMASK;                           //~v61rI~
        if (lcmd)                                                  //~v61rI~
        {                                                          //~v61rI~
	        if (Pinitsw & PAN300AEO_BROWSE)                        //~v61rI~
            	lcmd=tolower(lcmd);                                //~v61rI~
	        if (Pinitsw & PAN300AEO_EDIT)                          //~v61rI~
            	lcmd=toupper(lcmd);                                //~v61rI~
	  		psc->U3Lflag=(psc->U3Lflag & ~U3LFCMDMASK)|lcmd;       //~v61rI~
       		*(psc->U3Lfnm+psc->U3Lfnmlen-1)=(char)lcmd;	//update for write at term//~v61rR~
        }                                                          //~v61rI~
    }                                                              //~v61rI~
	else		//not found
	{
#ifdef UTF8SUPPH                                                   //~va00I~
//  	psc=UALLOCM((UINT)(UP300LISTSZ+Pfnmlen*3+1));	//orgname,bylocale,codetype//~va1cR~
//  	psc=UALLOCM((UINT)(UP300LISTSZ+Pfnmlen*(1+UTF8_F2LMAXRATE+UTF8_F2LMAXRATE)+2));	//orgname,bylocale,codetype//~va1cR~//~va1AR~
//  	psc=UcALLOC((UINT)(UP300LISTSZ+Pfnmlen*(1+UTF8_F2LMAXRATE+UTF8_F2LMAXRATE)+2));	//orgname,bylocale,codetype//~va1AI~//~vb30R~
    	psc=UcALLOC((size_t)((int)UP300LISTSZ+Pfnmlen*(1+UTF8_F2LMAXRATE+UTF8_F2LMAXRATE)+2));	//orgname,bylocale,codetype//~vb30I~
#else                                                              //~va00I~
    	psc=UALLOCM((UINT)(UP300LISTSZ+Pfnmlen));                  //~v61cR~
#endif                                                             //~va00I~
        if (psc)
        {
        	memset(psc,0,UP300LISTSZ);
       		memcpy(psc->U3Lfnm,Pfnm,(UINT)Pfnmlen);
        	*(psc->U3Lfnm+Pfnmlen)=0;//for setflddata strncpy
#ifdef UTF8SUPPH                                                   //~va00I~
//        	psc->U3Lcodetype=(char*)((ULONG)(psc->U3Lfnm)+Pfnmlen+1);//~va00I~//~vafkR~
//      	psc->U3Lcodetype=(char*)((ULPTR)(psc->U3Lfnm)+Pfnmlen+1);//~vafkI~//~vb30R~
        	psc->U3Lcodetype=(char*)((ULPTR)(psc->U3Lfnm)+(ULPTR)Pfnmlen+1);//~vb30I~
//        	psc->U3Lfnmbylc=psc->U3Lcodetype+Pfnmlen;  //area for by locale code//~va1cR~
          	psc->U3Lfnmbylc=psc->U3Lcodetype+Pfnmlen*UTF8_F2LMAXRATE;  //area for by locale code//~va1cR~
#endif                                                             //~va00I~
        	psc->U3Lfnmlen=Pfnmlen;
//      	psc->U3Lnetfnmlen=len=(int)ustrnlen(Pfnm,Pfnmlen);	//without other parm//~v61kR~
        	psc->U3Lnetfnmlen=Pfnmlen;                             //~v61kI~
        	len=(int)ustrnlen(Pfnm,(UINT)Pfnmlen);	//without other parm//~v61vR~
//          if (len<Pfnmlen) //parm or special cmd exist           //~v61kR~
            if (len+3<=Pfnmlen) //fnmstrz+parm+parmstrz+lcmd       //~v61kR~
            {                                                      //~v61cI~
            	pc=Pfnm+len+1;	//parm position                    //~v61cI~
                reslen=Pfnmlen-len-1;                              //~v61kI~
                if (*pc)                                           //~v61cI~
                {                                                  //~v61cI~
//  	        	psc->U3Lflag|=U3LFPARM;                        //~v61kR~
    	        	flag|=U3LFPARM;                                //~v61kI~
//              	pc+=strlen(pc);	//lcmd pos                     //~v61kR~
                }                                                  //~v61cI~
//              pc++;                                              //~v61kR~
//          	psc->U3Lflag|=*pc;                                 //~v61kR~
                len2=(int)ustrnlen(pc,(UINT)reslen);	//lcmd pos //~v61vR~
                if (len2+2==reslen)			//cmd contain          //~v61kR~
                {                                                  //~v61kI~
  		        	psc->U3Lflag=flag|*(pc+len2+1);                //~v61kI~
        			psc->U3Lnetfnmlen=len;                         //~v61kI~
                }                                                  //~v61kI~
            }                                                      //~v61cI~
            if (memchr(Pfnm,' ',(UINT)len))                        //~v61cR~
	        	psc->U3Lflag|=U3LFSPACEEMBEDED;                    //~v61cI~
        }
	}//not found
    if (psc)
    {                                                              //~v76mR~
#ifdef UTF8SUPPH                                                   //~va1yI~
        if (Pinitsw & PAN300AEO_SETCT)	//set locale code from cmdbuff//~va1yR~
			pan300editcmdf2l(P3EF2LO_SETCT,psc);                   //~va1yI~
#endif                                                             //~va1yI~
		UENQ(UQUE_TOP,&Sfnstack,psc);	//enq to top
        panfnlupdatepfh(PANFIND_ENQ,psc);                          //~v76mR~
    }                                                              //~v76mR~
//*chk max entry
//  if (!Pinitsw)                                                  //~v557R~
//  if (!(Pinitsw & PAN300AEO_INIT))                               //~v76mR~
//#ifdef WXE                                                       //~v557R~
//        if (UGETQCTR(&Sfnstack)>Gscrbuffheight-PANL300LISTTOP)//overflow//~v557R~
//#else                                                            //~v557R~
//        if (UGETQCTR(&Sfnstack)>Gscrheight-PANL300LISTTOP)//overflow//~v557R~
//#endif                                                           //~v557R~
        if (UGETQCTR(&Sfnstack)>Gmaxfnmlist)//overflow             //~v557I~
        {
            psc=UDEQ(UQUE_END,&Sfnstack,0); //deq oldest
        	panfnlupdatepfh(PANFIND_DEQ,psc);                      //~v76mR~
//          ufree(psc);                                            //~vaubR~
            ufreepsc(psc);                                         //~vaubI~
        }
	Supdatelistsw=1;       //request ppc update
	return;
}//pan300addentry
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// translate filename to locale code                               //~va1BR~
//**************************************************************** //~va00I~
int pan300editcmdf2l(int Popt,PUP300LIST Ppsc)                     //~va00I~
{                                                                  //~va00I~
	int rc2,lenutf8,lenlc;                                         //~va00I~
	char *pu8,*plc,*pct;                                           //~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	int ddlen;                                                     //~vaubI~
    char wkdddata[_MAX_PATH*2],wkdddbcs[_MAX_PATH*2],wkddcode[_MAX_PATH*2];//~vaubI~
#endif                                                             //~vaubI~
//************************                                         //~va00I~
	pu8=Ppsc->U3Lfnm;		//by locale or utf8                    //~va00I~
	plc=Ppsc->U3Lfnmbylc;		//locale                           //~va00I~
	pct=Ppsc->U3Lcodetype;  	//codetype                         //~va00I~
    Ppsc->U3Lnetfnmlenbylc=lenutf8=Ppsc->U3Lnetfnmlen;             //~va00R~
//  rc2=xeutf_getlocalestrm(XEUTFGLSMO_STRZ,pu8,lenutf8,plc,pct,Ppsc->U3Lfnmlen+1,&lenlc);//~va00R~
#ifdef UTF8SUPPH                                                   //~va1yI~
  if (Popt & P3EF2LO_SETCT)                                        //~va1yI~
  {                                                                //~va1yI~
	pan300stacksetctfromcmdbuff(0,Ppsc);                           //~va1yR~
  }                                                                //~va1yI~
  else                                                             //~va1yI~
#endif                                                             //~va1yI~
  {                                                                //~va1yI~
//  rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ,pu8,lenutf8,plc,pct,Ppsc->U3Lfnmlen+1,&lenlc);//~vauaR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//FIXME:FIXED no path,by SETCT,CHKED                               //~vavaI~//~vawfR~
   {                                                               //~vaubI~
    int opt=XEUTFGLPNO_STRZ|XEUTFGLPNO_LCWIDTHBYDDWIDTH;           //~vaubI~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME fullpath?:FIXED                                            //~vavcI~//~vavxR~
    if (uftpisremote(pu8,NULL))                                    //~vavcI~
        opt|=XEUTFGLPNO_REMOTE;                                    //~vavcI~
#endif                                                             //~vavcI~
    rc2=xeutf_getlocalepathname(opt,pu8,lenutf8,plc,pct,Ppsc->U3Lfnmlen+1,&lenlc,wkdddata,wkdddbcs,wkddcode,sizeof(wkdddata),&ddlen);//~vaubR~
   }                                                               //~vaubI~
    setpscddname(Ppsc,ddlen,wkdddata,wkdddbcs,wkddcode);           //~vaubR~
#else                                                              //~vaubI~
    rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ,pu8,lenutf8,plc,pct,Ppsc->U3Lfnmlen+1,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vauaI~
#endif                                                             //~vaubI~
    if (rc2 & XEUTFGU8MRC_UTF8)		//input contains utf8 code     //~va00I~
    {                                                              //~va00I~
		Ppsc->U3Lflag|=U3LFF2L;	//translated to locale code        //~va00I~
		Ppsc->U3Lnetfnmlenbylc=lenlc;                              //~va00I~
    }                                                              //~va00I~
  }                                                                //~va1yI~
	if (Ppsc->U3Lflag & U3LFPARM)            //cmd parm            //~va00I~
    	strcpy(plc+Ppsc->U3Lnetfnmlenbylc+1,pu8+Ppsc->U3Lnetfnmlen+1);//~va00R~
	Ppsc->U3Lflag|=U3LFUTF8CHKED;	//1st time to display          //~va00R~
    return 0;                                                      //~va00I~
}//pan300editcmdf2l                                                //~va00I~
//**************************************************************** //~va00I~
// transplate codetype utf8<-->locale                              //~va00R~
//return locale code length                                        //~va00I~
//**************************************************************** //~va00I~
int pan300setflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00R~
{                                                                  //~va00R~
	PUPANELC ppc;                                                  //~va00I~
	PUPANELL pupl;                                                 //~va00R~
	int lenlc;                                                     //~va00R~
//  char *pdata,wkcv[_MAX_PATH+1];                                 //~va1cR~
//  char *pdata,wkcv[_MAX_PATH*UTF8_F2LMAXRATE+1];                 //~va1cR~//~vav9R~
    char *pdata,wkcv[_MAX_PATHF2L+1];                              //~vav9I~
//************************                                         //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pdata=Pdata;	//null for PANL300FILENAME,PANL300DIR          //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
    switch(Prow)                                                   //~va00I~
    {                                                              //~va00I~
#ifdef EEE	//no need to l2f,charfldeditu8 do it                   //~va0tI~
    case PANL300FILENAME:  //input fld filename                    //~va00I~
    case PANL300DIR:       //input fld directory                   //~va00I~
        lenlc=pansetfld_l2f(0,Ppcw,pupl,Pfldno,pdata,0/*utf8len*/);//~va00R~
//      pupl->UPLctlen=lenlc;                                      //~va00R~
#endif                                                             //~va0tI~
        break;                                                     //~va00I~
    case PANL300CURRENT:  //prot fld current dir,by utf8           //~va00I~
		if (pansetfld_f2l(0,pupl,0,Pdata,wkcv,sizeof(wkcv),&lenlc))	//f2l done//~va00R~
            pdata=wkcv;                       //set SDbuff by locale code//~va00I~
        break;                                                     //~va00I~
    }                                                              //~va00I~
#ifdef CCC                                                         //~va0tI~
    if (pdata)	//set to plbuff required                           //~va00I~
    {                                                              //~va00I~
        UCBITON(Ppcw->UCWflag2,UCWF2SETFLD);    //avoid recursive call//~va00R~
#endif                                                             //~va0tI~
        lenlc=setflddata(Ppcw,Prow,Pfldno,pdata); //set locale code to UPLdata//~va00R~
#ifdef CCC                                                         //~va0tI~
        UCBITOFF(Ppcw->UCWflag2,UCWF2SETFLD);                      //~va00R~
    }                                                              //~va00I~
#endif                                                             //~va0tI~
    return lenlc;                                                  //~va00R~
}//pan300setflddata_utf8                                           //~va00R~
//**************************************************************** //~va00I~
// update fld                                                      //~va00I~
//**************************************************************** //~va00I~
int pan300fldupdate_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,int Ppos,UCHAR *Pdata,int Pdatalen,char *Pdbcs)//~va00I~
{                                                                  //~va00I~
	PUPANELC ppc;                                                  //~va00I~
	PUPANELL pupl;                                                 //~va00I~
	int fldlen,/*tgtutf8len,*/tgtlen,srcutf8len,opt,rc2;               //~va00R~//~vaa7R~
    char srcutf8[UPCCMDFLDWKSZ];                                   //~va00I~
    char srccodetype[UPCCMDFLDWKSZ];                               //~va00I~
	char *ptgtutf8,*ptgtcodetype;                                  //~va00R~
	UCHAR *flddata,*flddbcs;                                       //~va00I~
//************************                                         //~va00I~
    if (!(fldlen=getfldpos(Ppcw,Prow,Pfldno,&flddata,&flddbcs)))   //no dbcs parm//~va00I~
        return -1;              //fld top addr                     //~va00I~
    opt=XEUTFMSUO_STRZ|XEUTFMSUO_SETUTF8RC;                        //~va00R~
    if (Popt & P3FU8O_INS)                                         //~va00I~
        opt|=XEUTFMSUO_INS;                                        //~va00I~
    if (!getfldutf8(Ppcw,Prow,Pfldno,&ptgtutf8,&ptgtcodetype)) //field has utf8/codetype buff//~va00I~
    {                                                              //~va00I~
//      tgtutf8len=-1;  //strlen at mixedstrupdate                 //~va00I~//~vaa7R~
        *srcutf8=0;     //setup src utf8/codetype                  //~va00I~
        srcutf8len=0;                                              //~va00I~
        tgtlen=(int)strlen(flddata);                               //~va00I~
        ppc=Ppcw->UCWppc;                                          //~va00I~
        pupl=ppc->UPCline+Prow;                                    //~va00I~
#ifdef UTF8UCS2                                                    //~va1BR~
     if (Popt & P3FU8O_SETCT2)	//pass lc by Gcmdbuff,parm is utf8 str//~va1BR~
        rc2=xeutf_mixedstrupdate(opt,flddata,ptgtutf8,ptgtcodetype,flddbcs,tgtlen,0/*&(pupl->UPLctlen)*/,0/*out utf8len*/,//~va1BR~
                        Ppos,fldlen,                               //~va1BR~
						Gcmdbufflc,Pdata,Gcmdbuffct,Pdbcs,Gcmdbufflclen,Pdatalen,sizeof(Gcmdbuffu8)/*not used when srcu8 prepared*/);//~va1BR~
     else                                                          //~va1BR~
#endif                                                             //~va1BR~
        rc2=xeutf_mixedstrupdate(opt,flddata,ptgtutf8,ptgtcodetype,flddbcs,tgtlen,0/*&(pupl->UPLctlen)*/,0/*out utf8len*/,//~va00R~
                        Ppos,fldlen,                               //~va00R~
                        Pdata,srcutf8,srccodetype,Pdbcs,Pdatalen,srcutf8len,sizeof(srcutf8));//~va00R~
		if (rc2==XEUTFMSURC_UTF8)		//target contains utf8 coed//~va00R~
	    	pupl->UPLflags|=UPLFUTF8;                              //~va00R~
    	else                                                       //~va00R~
//      	pupl->UPLflags&=~UPLFUTF8;                             //~va00R~//~vb30R~
        	pupl->UPLflags&=~(ULONG)UPLFUTF8;                      //~vb30I~
    }                                                              //~va00I~
    return 0;                                                      //~va00I~
}//pan300fldupdate_utf8                                            //~va00I~
#ifdef AAA                                                         //~va00I~
//**************************************************************** //~va00I~
// get fld data addr(filename,dir,current)                         //~va00I~
// fldno: if -1 return top utf8                                    //~va00I~
//**************************************************************** //~va00I~
UCHAR *pan300getfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00I~
{                                                                  //~va00I~
	PUPANELC ppc;                                                  //~va00I~
	PUPANELL pupl;                                                 //~va00R~
    char *pu8;                                                     //~va00I~
//  UFLDE  *pfle;                                                  //~va00R~
//************************                                         //~va00I~
    if (UCBITCHK(Ppcw->UCWflag2,UCWF2SETFLD))	//from setflddata_utf8//~va00I~
		return Pdata;                                              //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
    pu8=pupl->UPLbuffbyutf8;                                       //~va00R~
    if (pupl->UPLflags & UPLFUTF8)	//utf8 code                    //~va00I~
    {                                                              //~va00I~
//      if (Pfldno<0)                                              //~va00R~
//          return pu8;                                            //~va00R~
//  	pfle=getuflde(Ppcw,Prow,Pfldno);                           //~va00R~
	    return pu8/*+pfle->UFLstart*/;                             //~va00R~
    }                                                              //~va00I~
    return Pdata;                                                  //~va00R~
}//pan300getfldpos_utf8                                            //~va00I~
#endif //AAA                                                       //~va00I~
#endif                                                             //~va00I~
//**************************************************               //~v61pI~
//*pan300delentry                                                  //~v61pI~
//*ret  :rc                                                        //~v61pI~
//**************************************************               //~v61pI~
int pan300delentry(PUCLIENTWE Ppcw,PUP300LIST Ppsc)                //~v61pI~
{                                                                  //~v61pI~
	int oldtop,offs;                                               //~v61pR~
//**************************************************               //~v61pI~
	if (!Ppsc)                                                     //~v61pI~
    	return 4;                                                  //~v61pI~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v61pR~
    offs=Ppcw->UCWrcsry-PANL300LISTTOP;                            //~v61pM~
	UDEQ(UQUE_ENT,&Sfnstack,Ppsc);	//deq to re-enq                //~v61pM~
    panfnlupdatepfh(PANFIND_DEQ,Ppsc);                             //~v76mR~
//  ufree(Ppsc);                                                   //~vaubR~
    ufreepsc(Ppsc);                                                //~vaubI~
    if (!offs)	//del top                                          //~v61pI~
        if (oldtop)                                                //~v61pI~
			return func_pgup_pan(Ppcw);                            //~v61pR~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v61pI~
	Supdatelistsw=1;       //request ppc update                    //~v61pI~
	return 0;                                                      //~v61pI~
}//pan300delentry                                                  //~v61pI~
//**************************************************
//*pan300freestack
//*free stack input cmd for retrieve
//*parm:none
//*ret  :none
//**************************************************
void pan300freestack(void)
{
	PUP300LIST psc,pscw;			//stack cmd
//**************************************************
	for (psc=UGETQTOP(&Sfnstack);psc;)//all entry
    {
		pscw=UGETQNEXT(psc);	//get next addr before free
//  	ufree(psc);                                                //~vaubR~
    	ufreepsc(psc);                                             //~vaubI~
		psc=pscw;
	}
//  panfnlfreepfh();                                               //~v78jR~
	return;
}//pan300freestack
//**************************************************
//*pan300wstack
//*write filename stack on XE!SAVE!
//*parm:FILE*
//*ret  :rc
//**************************************************
int pan300wstack(FILE *Pfh)
{
	PUP300LIST psc;			//stack cmd
    int ii=0;
//  long wkint;                                                    //~va70R~
    INT4 wkint;                                                    //~va70I~
#ifdef UTF8SUPPH                                                   //~va1yI~
	int lcctr=0;                                                   //~va1yI~
#endif                                                             //~va1yI~
//**************************************************
//  ii=UGETQCTR(&Sfnstack);                                        //~vb31R~
    ii=(int)UGETQCTR(&Sfnstack);                                   //~vb31I~
//  wkint=(long)ii;                                                //~va70R~
    wkint=(INT4)ii;                                                //~va70I~
#ifdef UTF8SUPPH                                                   //~va1yI~
    for (psc=UGETQEND(&Sfnstack);psc;psc=UGETQPREV(psc))//chk same string//~va1yI~
    {                                                              //~va1yI~
        if (psc->U3Lflag & U3LFF2L)                                //~va1yI~
        	lcctr++;                                               //~va1yI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
        if (psc->U3Lddlen)	//wrte ddfmt                           //~vaubI~
        	lcctr++;                                               //~vaubI~
#endif                                                             //~vaubI~
    }                                                              //~va1yI~
	wkint=wkint+lcctr;                                             //~va1yI~
#endif                                                             //~va1yI~
  	if (!fwrite(&wkint,sizeof(wkint),1,Pfh))
    	return 8;	//written count
    for (psc=UGETQEND(&Sfnstack);psc;psc=UGETQPREV(psc))//chk same string
    {
//    	wkint=(long)psc->U3Lfnmlen;                                //~va70R~
      	wkint=(INT4)psc->U3Lfnmlen;                                //~va70I~
	  	if (!fwrite(&wkint,sizeof(wkint),1,Pfh))
	    	return 8;	//written count
	  	if (!fwrite(psc->U3Lfnm,(UINT)psc->U3Lfnmlen,1,Pfh))
	    	return 8;	//written count
        UTRACED("pan300wstack fnm",psc->U3Lfnm,wkint);             //~vaubI~
#ifdef UTF8SUPPH                                                   //~va1yI~
        if (psc->U3Lflag & U3LFF2L)                                //~va1yI~
        {                                                          //~va1yI~
//    		wkint=(long)psc->U3Lnetfnmlenbylc;                     //~va1yR~//~va70R~
      		wkint=(INT4)(psc->U3Lnetfnmlenbylc);                   //~va70I~
	    	if (psc->U3Lflag & U3LFPARM)                           //~va1yI~
//    			wkint=wkint+1+strlen(psc->U3Lfnmbylc+psc->U3Lnetfnmlenbylc+1);	//add parm len,-1:drop lcmd//~va1yR~//~vb30R~
      			wkint=wkint+1+(int)strlen(psc->U3Lfnmbylc+psc->U3Lnetfnmlenbylc+1);	//add parm len,-1:drop lcmd//~vb30I~
	  		if (!fwrite(&wkint,sizeof(wkint),1,Pfh))               //~va1yI~
	    		return 8;	//written count                        //~va1yI~
	  		if (!fwrite(psc->U3Lfnmbylc,(UINT)wkint,1,Pfh))        //~va1yI~
	    		return 8;	//written count                        //~va1yI~
            UTRACED("pan300wstack fnmlc",psc->U3Lfnmbylc,wkint);   //~vaubI~
        }                                                          //~va1yI~
#endif                                                             //~va1yI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
        if (psc->U3Lddlen)	//wrte ddfmt                           //~vaubI~
        {                                                          //~vaubI~
        	char ddfmtid[2]={U3LDDFMTNAMEID,U3LDDFMTNAMEID};       //~vaubR~
//      		wkint=(INT4)(sizeof(ddfmtid)+psc->U3Lddlen*3);         //~vaubR~//~vb30R~
        		wkint=(INT4)((int)sizeof(ddfmtid)+psc->U3Lddlen*3);//~vb30I~
	  		if (!fwrite(&wkint,sizeof(wkint),1,Pfh))               //~vaubI~
	    		return 8;	//written count                        //~vaubI~
	  		if (!fwrite(ddfmtid,sizeof(ddfmtid),1,Pfh))            //~vaubR~
	    		return 8;	//written count                        //~vaubI~
	  		if (!fwrite(psc->U3Ldddata,(UINT)wkint-sizeof(ddfmtid),1,Pfh))//~vaubR~
	    		return 8;	//written count                        //~vaubI~
            UTRACED("pan300wstack ddfmt",psc->U3Ldddata,wkint-(int)sizeof(ddfmtid));//~vaubR~//~vb30R~
        }                                                          //~vaubI~
#endif                                                             //~vaubR~
	}
	return 0;
}//pan300wstack
//**************************************************
//*pan300rstack
//*read  stack from XE!SAVE!
//*parm:FILE*
//*ret  :rc
//**************************************************
int pan300rstack(FILE *Pfh)
{
	char *pc;
//  long wkint;                                                    //~va70R~
    INT4 wkint;                                                    //~va70I~
    int ii=0;
    int cmdlen;
//**************************************************
  	if (!fread(&wkint,sizeof(wkint),1,Pfh))
    	return 8;	//written count
	ii=(int)wkint;
    for (;ii;ii--)
    {
	  	if (!fread(&wkint,sizeof(wkint),1,Pfh))
            return 8;
		cmdlen=(int)wkint;
    	pc=UALLOCM((UINT)(cmdlen));
        UTRACEP("%s:cmdlen=%d\n",UTT,cmdlen);                      //~vbi3I~
	    UALLOCCHK(pc,UALLOC_FAILED);
	  	if (!fread(pc,(UINT)cmdlen,1,Pfh))
        {
            ufree(pc);
            return 8;
        }
        UTRACED("rstack",pc,cmdlen);                               //~vbi3I~
#ifdef UTF8SUPPH                                                   //~va1yI~
	  if (!pan300chklcentry(0,pc,cmdlen))	//lc entry, updated previous//~va1yI~
#endif                                                             //~va1yI~
		pan300addentry(pc,cmdlen,1);	//initsw
        ufree(pc);
    }
	return 0;
}//pan300rstack
//**********************************************************************
//* enter on filename list
//* parm 1:pcw
//* ret   :rc
//**********************************************************************
int pan300execlist(PUCLIENTWE Ppcw)
{
//  UCHAR beid[4];		//browse/edit id                           //~v216R~
//  UCHAR beid[MAXCOLUMN],*fnm;		//browse/edit cmd edit work    //~v51PR~
//  UCHAR beid[_MAX_PATH+8],*fnm;		//browse/edit cmd edit work//~v61cR~
    UCHAR beid[_MAX_PATH+MAXCOLUMN],*fnm;		//browse/edit cmd edit work//~v61cI~
#ifdef UTF8SUPPH                                                   //~va1rI~
//  UCHAR beidlc[_MAX_PATH*UTF8_F2LMAXRATE+MAXCOLUMN];             //~va1rI~//~vav9R~
//  UCHAR beidct[_MAX_PATH*UTF8_F2LMAXRATE+MAXCOLUMN];             //~va1rI~//~vav9R~
    UCHAR beidlc[_MAX_PATHF2L+MAXCOLUMN];                          //~vav9I~
    UCHAR beidct[_MAX_PATHF2L+MAXCOLUMN];                          //~vav9I~
    int lenlc;                                                     //~va1rI~
#endif                                                             //~va1rR~
    int   len,datalen,yy,pos;                                      //~v216I~
	PUP300LIST psc;			//stack cmd                            //~v61cI~
//#ifdef W32UNICODE                                                //~vavxR~
//    UCHAR beidstrip[_MAX_PATH+MAXCOLUMN];                        //~vavxR~
//    UCHAR beidlcstrip[_MAX_PATHF2L+MAXCOLUMN];                   //~vavxR~
//#endif                                                           //~vavxR~
//*****************
	if (Ppcw->UCWrcsry>=PANL300LISTTOP+UGETQCTR(&Sfnstack))	//enq counter//~v20yI~
    	return 0;                                                  //~v20yI~
    if ((pos=((UFLDE*)getuflde(Ppcw,CMDLINENO,0))->UFLstart)>=Ppcw->UCWwidth)//~v216I~
		return 4;	//no display width                             //~v216I~
    yy=Ppcw->UCWrcsry;                                             //~v216I~
    if (!(psc=pan300getpsc(yy+Ppcw->UCWtopfnlist)))                //~v61cI~
    	return 0;                                                  //~v61cI~
//  if (Ppcw->UCWmenuopt==PANMOBROWSE)                             //~v61uR~
//  	beid[0]='b';                                               //~v61uR~
//  else                                                           //~v61uR~
//  	beid[0]='e';                                               //~v61uR~
//  beid[1]=0;                                                     //~v216R~
//  subcmd=tolower(psc->U3Lflag & U3LFCMDMASK);                    //~v61uR~
//  if (subcmd)                                                    //~v61uR~
//  {                                                              //~v61uR~
//    beid[1]=(UCHAR)subcmd;                                       //~v61uR~
//    beid[2]=' ';                                                 //~v61uR~
//    fnm=beid+3;                                                  //~v61uR~
//    len=3;                                                       //~v61uR~
//  }                                                              //~v61uR~
//  else                                                           //~v61uR~
//  {                                                              //~v61uR~
//    beid[1]=' ';                                                 //~v61uR~
////  return pan300felcmd(Ppcw,beid,0);   //full event             //~v61uR~
//    fnm=beid+2;                                                  //~v61uR~
//    len=2;                                                       //~v61uR~
//  }                                                              //~v61uR~
	pan300getbecmd(Ppcw,psc,beid);                                 //~v61uR~
    len=(int)strlen(beid);                                         //~v61uR~
    fnm=beid+len;                                                  //~v61uI~
    *fnm++=' ';                                                    //~v61uI~
    len++;                                                         //~v61uI~
//  *fnm='"';                                                      //~v61cR~
//  getfldinput(Ppcw,yy,PANL300NAME,fnm+1);                        //~v51PR~
//  len=(int)strlen(fnm);                                          //~v51PI~
//  len=pan300getfnm(yy,fnm+1);                                    //~v55mR~
//  len=pan300getfnm(yy+Ppcw->UCWtopfnlist,fnm+1);                 //~v61cR~
//  if (!len)                                                      //~v61cR~
//  	return 0;                                                  //~v61cR~
//  len++;                                                         //~v61cR~
//  *(fnm+len++)='"';                                              //~v61cR~
//  *(fnm+len)=0;                                                  //~v61cR~
//  len+=2;		//'b '                                             //~v61cR~
#ifdef UTF8SUPPH                                                   //~va1rI~
	len+=pan300editcmd_utf8(0,Ppcw,psc,beid,len,beidlc,beidct,&lenlc);//~va1rI~
//#ifdef W32UNICODE                                                //~vavxR~
//  if (memchr(beid,UD_NOTLC,len))                                 //~vavxR~
//  {                                                              //~vavxR~
//    char * _plc;                                                 //~vavxR~
////  fsubw_stripUDCT(0,beid,len,beidstrip,sizeof(beidstrip),beidct,sizeof(beidct),&len);//~vavxR~
//    fsubw_stripUDCT(0,beid,len,beidstrip,sizeof(beidstrip),NULL/*beidct*/,0/*sizeof(beidct)*/,&len);//~vavxR~
//    if (memchr(beidlc,UD_NOTLC,lenlc))                           //~vavxR~
//    {                                                            //~vavxR~
//        fsubw_stripUDCT(0,beidlc,lenlc,beidlcstrip,sizeof(beidlcstrip),beidct,sizeof(beidct),&lenlc);//~vavxR~
//        _plc=beidlcstrip;                                        //~vavxR~
//    }                                                            //~vavxR~
//    else                                                         //~vavxR~
//        _plc=beidlc;                                             //~vavxR~
//    funcsetlongcmd_utf8(Ppcw,0,beidstrip,len,_plc,lenlc,beidct,&datalen);   //no execute,le by strlen//~vavxR~
//  }                                                              //~vavxR~
//  else                                                           //~vavxR~
//#endif                                                           //~vavxR~
	funcsetlongcmd_utf8(Ppcw,0,beid,len,beidlc,lenlc,beidct,&datalen);	//no execute,le by strlen//~va1rI~
#else                                                              //~va1rI~
	len+=pan300editcmd(Ppcw,psc,fnm);                              //~v61cI~
	funcsetlongcmd(Ppcw,0,beid,len,&datalen);	//no execute,le by strlen//~v216I~
#endif                                                             //~va1rI~
                                                                   //~v216I~
    scrclearmsg(Ppcw);                                             //~v216I~
    Ppcw->UCWrcsry=CMDLINENO;                                      //~v216I~
    Ppcw->UCWrcsrx=pos+datalen;                                    //~v216I~
    csrrestore(Ppcw);   //set csr to end of cmd line               //~v216I~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);         //~v216I~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err             //~v216I~
    return 0;                                                      //~v216I~
}//pan300execlist                                                  //~v61cR~
//**********************************************************************//~v557I~
//* paging                                                         //~v557I~
//**********************************************************************//~v557I~
int func_pgup_pan(PUCLIENTWE Ppcw)                                 //~v557I~
{                                                                  //~v557I~
    int line,oldtop,newtop,oldyy;                                  //~v76nR~
//*****************                                                //~v557I~
	if (((PUPANELC)Ppcw->UCWppc)->UPCid!=PANFNAME)                 //~v557I~
		return  errscrtype("PageScroll");                          //~v557I~
//  pgsz=Ppcw->UCWheight-PANL300LISTTOP;                           //~v76nR~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v557I~
    oldyy=Ppcw->UCWrcsry;       //UCWrcsry may change by getscrollsz//~v76nI~
//  if (!oldtop)                                                   //~v76nR~
//  	return 0;                                                  //~v76nR~
//  newtop=oldtop-pgsz;                                            //~v76nR~
	line=pan300getscrollsz(Ppcw,0,-1);	//0:virtical,-1:backward   //~v76nI~
    if (!oldtop)        //after clear cmd                          //~v76nI~
    	return 4;                                                  //~v76nM~
    if (line==-1)   //max                                          //~v76nI~
		newtop=0;                                                  //~v76nI~
    else                                                           //~v76nI~
        newtop=oldtop-line;                                        //~v76nR~
    if (newtop<0)	//enq counter                                  //~v557I~
    	newtop=0;                                                  //~v557I~
    pan300scrollsetcsr(Ppcw,oldtop,newtop,oldyy);                  //~v76nR~
    Ppcw->UCWtopfnlist=newtop;                                     //~v557I~
    Ppcw->UCWoldheight=-1;  //filename list redraw req             //~v557I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v557I~
    return 0;                                                      //~v557I~
}//func_pgup_pan                                                   //~v557I~
//**********************************************************************//~v557I~
//* paging                                                         //~v557I~
//**********************************************************************//~v557I~
int func_pgdown_pan(PUCLIENTWE Ppcw)                               //~v557I~
{                                                                  //~v557I~
    int line,oldtop,newtop;                                        //~v76nR~
    int oldyy;                                                     //~v76nI~
//*****************                                                //~v557I~
	if (((PUPANELC)Ppcw->UCWppc)->UPCid!=PANFNAME)                 //~v557I~
	    errscrtype("PageScroll");                                  //~v557I~
//  pgsz=Ppcw->UCWheight-PANL300LISTTOP;                           //~v76nR~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v557I~
    oldyy=Ppcw->UCWrcsry;       //UCWrcsry may change by getscrollsz//~v76nI~
//  newtop=oldtop+pgsz;                                            //~v76nR~
	line=pan300getscrollsz(Ppcw,0,1);	//0:virtical,1:forward     //~v76nR~
    if (line==-1)   //max                                          //~v76nI~
		return func_pgend_pan(Ppcw);                               //~v76nR~
    newtop=oldtop+line;                                            //~v76nR~
//  if (newtop>UGETQCTR(&Sfnstack))	//enq counter                  //~v56fR~
    if (newtop>=UGETQCTR(&Sfnstack))	//enq counter              //~v56fI~
//  	return 0;                                                  //~v76nR~
    	return 4;                                                  //~v76nI~
    pan300scrollsetcsr(Ppcw,oldtop,newtop,oldyy);                  //~v76nR~
    Ppcw->UCWtopfnlist=newtop;                                     //~v557I~
    Ppcw->UCWoldheight=-1;  //filename list redraw req             //~v557I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v557I~
    return 0;                                                      //~v557I~
}//func_pgdown_pan                                                 //~v557I~
//**********************************************************************//~v61dI~
//* paging to toppage                                              //~v61dI~
//**********************************************************************//~v61dI~
int func_pgtop_pan(PUCLIENTWE Ppcw)                                //~v61dI~
{                                                                  //~v61dI~
    int oldtop,newtop;                                             //~v61dI~
    int oldyy;                                                     //~v76nI~
//*****************                                                //~v61dI~
	if (((PUPANELC)Ppcw->UCWppc)->UPCid!=PANFNAME)                 //~v61dI~
		return  errscrtype("PageScroll");                          //~v61dI~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v61dI~
    oldyy=Ppcw->UCWrcsry;       //UCWrcsry may change by getscrollsz//~v76nI~
    if (!oldtop)                                                   //~v61dI~
    	return 0;                                                  //~v61dI~
    newtop=0;                                                      //~v61dI~
    pan300scrollsetcsr(Ppcw,oldtop,newtop,oldyy);                  //~v76nR~
    Ppcw->UCWtopfnlist=newtop;                                     //~v61dI~
    Ppcw->UCWoldheight=-1;  //filename list redraw req             //~v61dI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v61dI~
    return 0;                                                      //~v61dI~
}//func_pgtop_pan                                                  //~v61dI~
//**********************************************************************//~v61dI~
//* paging  to endpage                                             //~v61dI~
//**********************************************************************//~v61dI~
int func_pgend_pan(PUCLIENTWE Ppcw)                                //~v61dI~
{                                                                  //~v61dI~
    int pgsz,oldtop,newtop;                                        //~v61dR~
    int oldyy;                                                     //~v76nI~
//*****************                                                //~v61dI~
	if (((PUPANELC)Ppcw->UCWppc)->UPCid!=PANFNAME)                 //~v61dI~
	    errscrtype("PageScroll");                                  //~v61dI~
    pgsz=Ppcw->UCWheight-PANL300LISTTOP;                           //~v61dI~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v61dI~
    oldyy=Ppcw->UCWrcsry;       //UCWrcsry may change by getscrollsz//~v76nI~
//  newtop=UGETQCTR(&Sfnstack)-pgsz;                               //~v61dI~//~vb31R~
    newtop=(int)UGETQCTR(&Sfnstack)-pgsz;                          //~vb31I~
    if (newtop<=oldtop)	//enq counter                              //~v61dI~
    	return 0;                                                  //~v61dI~
    pan300scrollsetcsr(Ppcw,oldtop,newtop,oldyy);                  //~v76nR~
    Ppcw->UCWtopfnlist=newtop;                                     //~v61dI~
    Ppcw->UCWoldheight=-1;  //filename list redraw req             //~v61dI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v61dI~
    return 0;                                                      //~v61dI~
}//func_pgend_pan                                                  //~v61dI~
//**********************************************************************//~v76mI~
//* paging                                                         //~v76mI~
//**********************************************************************//~v76mI~
int pan300locatepage(PUCLIENTWE Ppcw,int Plinetop,int Plinecsr)    //~v76mR~
{                                                                  //~v76mI~
    int pgsz,oldtop,newtop,yy;                                     //~v76mR~
//*****************                                                //~v76mI~
    pgsz=Ppcw->UCWheight-PANL300LISTTOP;                           //~v76mI~
    oldtop=Ppcw->UCWtopfnlist;                                     //~v76mI~
    newtop=Plinetop;                                               //~v76mR~
    if (newtop!=oldtop)                                            //~v76mM~
    {                                                              //~v76mM~
	    Ppcw->UCWtopfnlist=newtop;                                 //~v76mI~
    	Ppcw->UCWoldheight=-1;  //filename list redraw req         //~v76mI~
	    UCBITON(Ppcw->UCWflag,UCWFDRAW);                           //~v76mI~
    }                                                              //~v76mM~
    yy=Plinecsr-Plinetop;                                          //~v76mR~
    if (yy<0||yy>pgsz)                                             //~v76mI~
    	yy=0;                                                      //~v76mI~
    yy+=PANL300LISTTOP;                                            //~v76mR~
    csronthefld(Ppcw,yy,PANL300LCMD,0);                            //~v76mI~
    return 0;                                                      //~v76mI~
}//pan300locatepage                                                //~v76nR~
//**********************************************************************//~v61cI~
//* get psc for the cursor line                                    //~v61cI~
//* parm 1:rows+page top entry no                                  //~v61cI~
//* parm 2:out data                                                //~v61cI~
//* ret   :filename len                                            //~v61cI~
//**********************************************************************//~v61cI~
PUP300LIST pan300getpsc(int Pyy)                                   //~v61cR~
{                                                                  //~v61cI~
    int ii;                                                        //~v61cR~
	PUP300LIST psc;			//stack entry                          //~v61cI~
//*****************                                                //~v61cI~
	psc=UGETQTOP(&Sfnstack);//chk same string                      //~v61cI~
    for (ii=Pyy-PANL300LISTTOP;ii>0 && psc;ii--)                   //~v61cI~
		psc=UGETQNEXT(psc);//chk same string                       //~v61cI~
    return psc;                                                    //~v61cI~
}//pan300getpsc                                                    //~v61cI~
//**********************************************************************//~v51PI~
//* get fineleme on th curser                                      //~v51PI~
//* parm 1:rows+page top entry no                                  //~v55mR~
//* parm 2:out data                                                //~v51PI~
//* ret   :filename len                                            //~v51PI~
//**********************************************************************//~v51PI~
int pan300getfnm(int Pyy,UCHAR *Pout)                              //~v51PI~
{                                                                  //~v51PI~
    int ii,len;                                                    //~v51PI~
	PUP300LIST psc;			//stack entry                          //~v51PM~
//*****************                                                //~v51PI~
	psc=UGETQTOP(&Sfnstack);//chk same string                      //~v51PI~
    for (ii=Pyy-PANL300LISTTOP;ii>0 && psc;ii--)                   //~v51PI~
		psc=UGETQNEXT(psc);//chk same string                       //~v51PI~
    if (!psc)                                                      //~v51PI~
    	return 0;                                                  //~v51PI~
//  len=psc->U3Lfnmlen;                                            //~v61cR~
//  memcpy(Pout,psc->U3Lfnm,(UINT)len);                            //~v61cR~
//  *(Pout+len)=0;  //null term                                    //~v61cR~
    strcpy(Pout,psc->U3Lfnm);                                      //~v61cI~
    len=psc->U3Lnetfnmlen;                                         //~v61cI~
    return len;                                                    //~v51PI~
}//pan300getfnm                                                    //~v51PI~
//**********************************************************************
//* line cmd field event(full/clear)
//* parm 1:pcw
//* parm 2:data
//* parm 3:event id(0:full/1:clear)
//* ret   :rc
//**********************************************************************
int pan300felcmd(PUCLIENTWE Ppcw,UCHAR *Pdata,int Peventid)
{
//  UCHAR fnm[_MAX_PATH+4];                                        //~v61cR~
    UCHAR fnm[_MAX_PATH+MAXCOLUMN];                                //~v61cI~
	PUSCRD psd;                                                    //~v61fI~
	int yy,len,rc;                                                 //~v44nR~
	PUP300LIST psc;			//stack cmd                            //~v61cI~
    int cmdid=0,subcmdid,subcmdid0,netfnmlen;                        //~v61cR~//~vafcR~
    char lcmdid[2];                                                //~v61fR~
    char becmd[4];                                                 //~v61vR~
#ifdef UTF8SUPPH                                                   //~va1AR~
//  UCHAR beidlc[_MAX_PATH*UTF8_F2LMAXRATE+MAXCOLUMN];             //~va1AR~//~vav9R~
//  UCHAR beidct[_MAX_PATH*UTF8_F2LMAXRATE+MAXCOLUMN];             //~va1AR~//~vav9R~
    UCHAR beidlc[_MAX_PATHF2L+MAXCOLUMN];                          //~vav9I~
    UCHAR beidct[_MAX_PATHF2L+MAXCOLUMN];                          //~vav9I~
    int lenlc,opt;                                                 //~va1AR~
#endif                                                             //~va1AR~
//*****************
    yy=Ppcw->UCWrcsry;
    if (!(psc=pan300getpsc(yy+Ppcw->UCWtopfnlist)))                //~v61fM~
    	return 0;                                                  //~v61fM~
	if (Peventid)	//field clear event
    {
//  	panflderr(Ppcw,yy,PANL300LCMD,PANFERESET);	//set err reverse on cur csr//~v61fR~
    	setflddata(Ppcw,yy,PANL300LCMD,LCMDID);//clear input       //~v61fR~
//      return 0;                                                  //~v61fR~
        if (Ppcw->UCWkeytype==UCWKTSBCS && Ppcw->UCWkeydata[0]==' ')//space cmd//~v61fR~
        {                                                          //~v61fI~
            Sspacelcmd=1;                                          //~v61fR~
            rc=pan300execlist(Ppcw);                               //~v61fR~
            Sspacelcmd=0;                                          //~v61fR~
			psd=Ppcw->UCWpsd+yy;                                   //~v61fI~
			lcmdid[0]=(char)pan300getbecmd(Ppcw,psc,0);            //~v61vR~
            lcmdid[1]=0;                                           //~v61fI~
		    setflddata(Ppcw,yy,PANL300LCMD,lcmdid);//clear input   //~v61fI~
			UCBITON(psd->USDflag2,USDF2DRAW);	//redraw           //~v61fI~
        }                                                          //~v61fI~
        else                                                       //~v61fI~
        	rc=0;                                                  //~v61fI~
        return rc;                                                 //~v61fI~
	}
    csronthefld(Ppcw,yy,PANL300LCMD,0);   //for when next wakeup
//  *fnm='"';                                                      //~v61cR~
//  getfldinput(Ppcw,yy,PANL300NAME,fnm+1);                        //~v51PR~
//  len=(int)strlen(fnm);                                          //~v51PR~
//  len=pan300getfnm(yy+Ppcw->UCWtopfnlist,fnm+1);                 //~v61cR~
//  if (!len)                                                      //~v61cR~
//  	return 0;                                                  //~v61cR~
//  len++;                                                         //~v61cR~
//  *(fnm+len++)='"';                                              //~v61cR~
//  *(fnm+len)=0;                                                  //~v61cR~
    subcmdid0=subcmdid=psc->U3Lflag & U3LFCMDMASK;                 //~v61cR~
    if (!subcmdid)                                                 //~v61cI~
    	subcmdid=' ';                                              //~v61cI~
//  Ppcw->UCWparm=fnm;                                             //~v61cR~
    rc=0;                                                          //~v61cR~
    switch(toupper(*Pdata))
    {
    case 'B':
//  	rc=func_browse_file2(Ppcw,0);	//filename only            //~v61cR~
        cmdid='b';                                                 //~v61cI~
    	break;
    case 'E':
//  	rc=func_edit_file2(Ppcw,0);	//parm is file name only       //~v61cR~
        cmdid='e';                                                 //~v61cI~
    	break;
    case UDLCCMD_EDITF80: //"8"                                    //~v75HI~
		subcmdid=UDLCCMD_EDITF80;                                  //~v75HI~
    	if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v75HI~
    	    cmdid='b';                                             //~v75HI~
        else                                                       //~v75HI~
    	    cmdid='e';                                             //~v75HI~
    	break;                                                     //~v75HI~
    case U3LFCMDBINLCMD://'0'                                      //~v61cI~
//  	strcpy(fnm+len," /Mb");	//binary option                    //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='b';		//binary                               //~v61cI~
    	if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v61cI~
    	    cmdid='b';                                             //~v61cI~
        else                                                       //~v61cI~
    	    cmdid='e';                                             //~v61cI~
    	break;                                                     //~v61cI~
    case '1':
//  	strcpy(fnm+len," /Mb");	//binary option                    //~v61cR~
//  	rc=func_browse_file2(Ppcw,1);	//filename only            //~v61cR~
		subcmdid='b';		//binary                               //~v61cI~
        cmdid='b';			//browse                               //~v61cI~
    	break;
    case '2':
//  	strcpy(fnm+len," /Mb");	//binary option                    //~v61cR~
//  	rc=func_edit_file2(Ppcw,1);	//filename with option /Mb     //~v61cR~
		subcmdid='b';		//binary                               //~v61cI~
        cmdid='e';			//edit                                 //~v61cI~
    	break;
    case 'C':                                                      //~v44pI~
    case 'L':                                                      //~v44pI~
//  	strcpy(fnm+len," /Mc");	//cobol with seqno                 //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='c';		//cobol                                //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44pI~
    case 'H':                                                      //~v44nI~
//  	strcpy(fnm+len," /Mh");	//hex display option               //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='h';		//cobol                                //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44nI~
    case 'I':                                                      //~v44pI~
//  	strcpy(fnm+len," /Mcn");	//spf cobol with seqno         //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='i';		//cobolnum                             //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44pI~
    case 'J':                                                      //~v44pI~
//  	strcpy(fnm+len," /Mkn");	//spf cobol with space         //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='j';		//cobol2 num                           //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44pI~
    case 'K':                                                      //~v44pI~
//  	strcpy(fnm+len," /Mk");	    //cobol with space             //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='k';		//cobolw                               //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44pI~
    case 'N':                                                      //~v44pI~
//  	strcpy(fnm+len," /Mn");	    //spf                          //~v61cR~
//  	rc=panbecmdcall(Ppcw,*Pdata);                              //~v61cR~
		subcmdid='n';		//cobolw                               //~v61cI~
        cmdid=panbrowsecmdchk(Ppcw,*Pdata)?'b':'e';                //~v61cI~
    	break;                                                     //~v44pI~
    case 'S':                                                      //~v216I~
//        if (Ppcw->UCWmenuopt==PANMOBROWSE)                       //~v61vR~
////          rc=func_browse_file2(Ppcw,0);   //filename only      //~v61vR~
//            cmdid='b';      //browse                             //~v61vR~
//        else                                                     //~v61vR~
////          rc=func_edit_file2(Ppcw,0); //parm is file name only //~v61vR~
//            cmdid='e';      //edit                               //~v61vR~
		pan300getbecmd(Ppcw,psc,becmd);                            //~v61vR~
		cmdid=*becmd;                                              //~v61vR~
		subcmdid=*(becmd+1);                                       //~v61vR~
        if (!subcmdid)                                             //~v71dI~
        {                                                          //~va1wI~
            subcmdid=' ';                                          //~v71dI~
            subcmdid0=' '; //avoid parm drop                       //~va1wI~
        }                                                          //~va1wI~
    	break;                                                     //~v61vR~
    case 'T':                                                      //~v50GI~
//  	strcpy(fnm+len," /Mt");	//binary option                    //~v61cR~
		subcmdid='t';		//text                                 //~v61cI~
    	if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v50GI~
//  		rc=func_browse_file2(Ppcw,1);	//1:opd exist          //~v61cR~
        	cmdid='b';		//browse                               //~v61cI~
        else                                                       //~v50GI~
//  		rc=func_edit_file2(Ppcw,1);	//1:opd exist              //~v61cR~
        	cmdid='e';		//edit                                 //~v61cI~
    	break;                                                     //~v50GI~
//#ifdef W32                                                       //~v64vR~
#if defined(W32) || defined(LNX)                                   //~v64vI~
    case '!':                                                      //~v55VI~
//  	*(fnm+len-1)=0;		//drop quote                           //~v61cR~
//  	rc=dlcmdopenwithsub(Ppcw,fnm+1);	//binary option        //~v61cR~
    	rc=dlcmdopenwithsub(Ppcw,psc->U3Lfnm);//filename only      //~v61cI~
    	break;                                                     //~v55VI~
#endif                                                             //~v55VI~
    case LCMDIDDELCH:     //delete entry                           //~v61pR~
    	return pan300delentry(Ppcw,psc);//psc is freed             //~v61pR~
    default:
        panflderr(Ppcw,yy,PANL300LCMD,PANFESET);    //set err reverse on cur csr
        return pan300lcmderr(Scmdtbl);
    }
    if (*Pdata!='!')	//edit/browse cmd                          //~v61cI~
    {                                                              //~v61cI~
    	fnm[0]=(UCHAR)cmdid;                                              //~v61cI~
    	fnm[1]=(UCHAR)subcmdid;                                           //~v61cI~
    	fnm[2]=' ';                                                //~v61cI~
#ifdef UTF8SUPPH                                                   //~va1AR~
		opt=0;                                                     //~va1AR~
		if (subcmdid && subcmdid!=subcmdid0)	//subcmd changed   //~va1AR~
			opt=P3ECU8O_NOOPTION;   //drop option parm             //~va1AR~
		len=pan300editcmd_utf8(opt,Ppcw,psc,fnm,3,beidlc,beidct,&lenlc);//~va1AR~
#else                                                              //~va1AR~
		len=pan300editcmd(Ppcw,psc,fnm+3);	//set filename and other parm//~v61cI~
#endif                                                             //~va1AR~
		if (subcmdid && subcmdid!=subcmdid0)	//subcmd changed   //~v61cR~
        {                                                          //~v61cI~
        	netfnmlen=psc->U3Lnetfnmlen;                           //~v61cR~
		    if (psc->U3Lflag & U3LFSPACEEMBEDED)                   //~v61cI~
        		netfnmlen+=2;                   //with quatation   //~v61cI~
            *(fnm+netfnmlen+3)=0;		//drop other parm          //~v61cR~
            len=netfnmlen;                                         //~v61cI~
        }                                                          //~v61cI~
#ifdef UTF8SUPPH                                                   //~va1AR~
		funcsetlongcmd_utf8(Ppcw,FSLCO_EXECUTE/*=1*/,fnm,len+3,beidlc,lenlc,beidct,0/*output datalen*/);//~va1AR~
#else                                                              //~va1AR~
		funcsetlongcmd(Ppcw,1,fnm,len+3,0);	//1:execute,0:no output cmdlen//~v61cI~
#endif                                                             //~va1AR~
    }                                                              //~v61cI~
    setflddata(Ppcw,yy,PANL300LCMD,LCMDID);//clear input           //~v20yR~
//  Ppcw->UCWparm=0;        //worked                               //~v61cR~
    if (!rc)                                                       //~v61cR~
    	pan300csrreset(Ppcw);                                      //~v61cR~
    return rc;					//ignore,next tab
}//pan300felcmd
//**********************************************************************//~v61cI~
//* get lcmd verb from becmdopt saved in stack cmd string          //~v61cI~
//* ret   :lcmd verb                                               //~v61cI~
//**********************************************************************//~v61cI~
//int pan300getlcmdfromfuncid(int Pfuncid,int Pbrowsesw)           //~v61rR~
int pan300getlcmdfromfuncid(int Pfuncid,int *Ppbrowsesw)           //~v61rI~
{                                                                  //~v61cI~
    char lcmd=0;                                                   //~v61cI~
    int browsesw;                                                  //~v61rI~
//*****************                                                //~v61cI~
	browsesw=*Ppbrowsesw;                                          //~v61rI~
    switch(Pfuncid)                                                //~v61cI~
    {                                                              //~v61cI~
    case FUNCID_BROWSETEXT:                                        //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='t';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITTEXT:                                          //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='T';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTTEXT:                                        //~v61cI~
       if (browsesw)                                               //~v61rR~
        lcmd='t';                                                  //~v61cR~
       else                                                        //~v61rI~
        lcmd='T';                                                  //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSEBIN:                                         //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='b';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITBIN:                                           //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='B';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTBIN:                                         //~v61cI~
       if (browsesw)                                               //~v61rR~
        lcmd='b';                                                  //~v61rR~
       else                                                        //~v61rI~
        lcmd='B';                                                  //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSEHEX:                                         //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='h';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITHEX:                                           //~v61cI~
    	browsesw=0;                                                //~v61rI~
        lcmd='H';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTHEX:                                         //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='h';                                              //~v61cR~
        else                                                       //~v61rI~
            lcmd='H';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSESPF:                                         //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='n';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITSPF:                                           //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='N';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTSPF:                                         //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='n';                                              //~v61cR~
        else                                                       //~v61rI~
            lcmd='N';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSESPFCOB:                                      //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='c';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITSPFCOB:                                        //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='C';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTSPFCOB:                                      //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='c';                                              //~v61cR~
        else                                                       //~v61rI~
            lcmd='C';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSESPFCOBNUM:                                   //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='i';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITSPFCOBNUM:                                     //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='I';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTSPFCOBNUM:                                   //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='i';                                              //~v61cI~
        else                                                       //~v61rI~
            lcmd='I';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSESPFCOB2:                                     //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='k';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITSPFCOB2:                                       //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='K';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTSPFCOB2:                                     //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='k';                                              //~v61cR~
        else                                                       //~v61rI~
            lcmd='K';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSESPFCOB2NUM:                                  //~v61cI~
    	browsesw=1;                                                //~v61rI~
        lcmd='j';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_EDITSPFCOB2NUM:                                    //~v61rM~
    	browsesw=0;                                                //~v61rI~
        lcmd='J';                                                  //~v61rI~
        break;                                                     //~v61rI~
    case FUNCID_SELECTSPFCOB2NUM:                                  //~v61cI~
        if (browsesw)                                              //~v61rR~
            lcmd='j';                                              //~v61cR~
        else                                                       //~v61rI~
            lcmd='J';                                              //~v61rI~
        break;                                                     //~v61cI~
    case FUNCID_BROWSEF80:                                         //~v75HI~
    	browsesw=1;                                                //~v75HI~
        lcmd=UDLCCMD_EDITF80;                                      //~v75HI~
        break;                                                     //~v75HI~
    case FUNCID_EDITF80:                                           //~v75HI~
    	browsesw=0;                                                //~v75HI~
        lcmd=UDLCCMD_EDITF80;                                      //~v75HI~
        break;                                                     //~v75HI~
    case FUNCID_SELECTF80:                                         //~v75HI~
        lcmd=UDLCCMD_EDITF80;                                      //~v75HI~
        break;                                                     //~v75HI~
    }                                                              //~v61cI~
    *Ppbrowsesw=browsesw;                                          //~v61rR~
    return lcmd;                                                   //~v61cI~
}//pan300getlcmdfromfuncid                                         //~v61cI~
//**************************************************************** //~v56dI~
// pan300csrreset                                                  //~v56dI~
//*set cursor to topline of 1st page                               //~v76mR~
//*parm 1:pcw                                                      //~v56dI~
//*rc    :1:browse,0:edit                                          //~v56dI~
//**************************************************************** //~v56dI~
int pan300csrreset(PUCLIENTWE Ppcw)                                //~v56dI~
{                                                                  //~v56dI~
//************************                                         //~v56dI~
    Ppcw->UCWtopfnlist=0;   //top page                             //~v56dI~
    csronthefld(Ppcw,PANL300LISTTOP,PANL300LCMD,0);                //~v56dI~
    return 0;                                                      //~v56dI~
}//pan300csrreset                                                  //~v56dI~
//**************************************************************** //~v44nI~
// panbecmdcall                                                    //~v44nI~
//*call browse/editcmd by lower/upper case                         //~v44nI~
//*parm 1:pcw                                                      //~v44nI~
//*parm 2:cmd code                                                 //~v44nI~
//*rc    :1:browse,0:edit                                          //~v44nI~
//**************************************************************** //~v44nI~
int panbecmdcall(PUCLIENTWE Ppcw,UCHAR Pcmdid)                     //~v44nI~
{                                                                  //~v44nI~
	int browsesw,rc;                                               //~v44nI~
//************************                                         //~v44nI~
    browsesw=panbrowsecmdchk(Ppcw,Pcmdid);                         //~v44nR~
    if (browsesw)                                                  //~v44nI~
        rc=func_browse_file2(Ppcw,1);   //with option              //~v44nI~
    else                                                           //~v44nI~
        rc=func_edit_file2(Ppcw,1); //with option parm             //~v44nI~
    return rc;                                                     //~v44nI~
}//panbecmdcall                                                    //~v44nI~
//**************************************************************** //~v44nI~
// panbrowsecmdchk                                                 //~v44nI~
//*determin browse or edit by menu opt and cmd upper/lower case    //~v44nI~
//*parm 1:pcw                                                      //~v44nI~
//*parm 2:cmd code                                                 //~v44nI~
//*rc    :1:browse,0:edit                                          //~v44nI~
//**************************************************************** //~v44nI~
int panbrowsecmdchk(PUCLIENTWE Ppcw,UCHAR Pcmdid)                  //~v44nI~
{                                                                  //~v44nI~
	int browsesw;                                                  //~v44nI~
//**********************                                           //~v44nI~
	if (toupper(Pcmdid)==(int)Pcmdid)	//upper :opposit           //~v44nR~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v44nI~
            browsesw=0;                                            //~v44nI~
        else                                                       //~v44nI~
            browsesw=1;                                            //~v44nI~
    else    //lower   :allow menu opt                              //~v44nI~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v44nR~
            browsesw=1;                                            //~v44nI~
        else                                                       //~v44nI~
            browsesw=0;                                            //~v44nI~
    return browsesw;                                               //~v44nI~
}//panbrowsecmdchk                                                 //~v44nI~
//**************************************************************** //~v53cI~
//* draw filename list                                             //~v53cI~
//**************************************************************** //~v53cI~
int pan300getword(PUCLIENTWE Ppcw,char *Pword,int Plen)            //~v53cI~
{                                                                  //~v53cI~
	int yy,len;                                                    //~v53cR~
    UCHAR fnmwk[_MAX_PATH];                                        //~v53cI~
//************************************                             //~v53cI~
	yy=Ppcw->UCWrcsry;		//  cursor line                        //~v53cI~
//othe line                                                        //~v53cI~
    switch(yy)                                                     //~v53cI~
    {                                                              //~v53cI~
    case PANL300FILENAME:  //filename  lineno                      //~v53cI~
    case PANL300DIR:        //directory lineno                     //~v53cI~
    case PANL300CURRENT:  //current dir lineno                     //~v53cI~
#ifndef UNX                                                        //~v53cI~
	case PANL300DRIVE:		//driveid   lineno                     //~v53cI~
#endif                                                             //~v53cI~
#ifdef UTF8SUPPH                                                   //~va00I~
	    len=BYUTF8_getfldinput(0,Ppcw,yy,0/*fldno*/,fnmwk);        //~va00R~
#else                                                              //~va00I~
		len=getfldinput(Ppcw,yy,0,fnmwk);//directory name          //~v53cI~
#endif                                                             //~va00I~
    	break;                                                     //~v53cI~
    default:                                                       //~v53cI~
	    if (yy>=PANL300LISTTOP)                                    //~v53cI~
            len=pan300getfnm(yy+Ppcw->UCWtopfnlist,fnmwk);         //~v55mR~
        else                                                       //~v53cI~
        {                                                          //~v53cI~
	        errcsrpos();                                           //~v53cR~
            return 0;                                              //~v53cI~
        }                                                          //~v53cI~
    }//switch                                                      //~v53cI~
    if (len)                                                       //~v53cI~
        if (len>Plen)                                              //~v53cI~
        {                                                          //~v53cI~
            errtoolong();                                          //~v53cI~
            len=0;                                                 //~v53cI~
        }                                                          //~v53cI~
        else                                                       //~v53cI~
            memcpy(Pword,fnmwk,(UINT)len);                         //~v53cI~
    else                                                           //~v53cI~
    	uerrmsg("Line has no data",0);                             //~v53cR~
    return len;                                                    //~v53cI~
}//pan300getword                                                   //~v53cI~
//***********************************************                  //~v76nI~
//*get scroll size ******************************                  //~v76nI~
//*return:scroll size                                              //~v76nI~
//***********************************************                  //~v76nI~
int pan300getscrollsz(PUCLIENTWE Ppcw,int Popt,int Pdest)          //~v76nI~
{                                                                  //~v76nI~
	int scrollsz,csry,opdno,szwk;                                  //~v76nR~
	char *wkbuff;                                                  //~v76nI~
    int startline,endline,pgsz;                                    //~v76nR~
//****************************                                     //~v76nI~
#if defined(WXEXXE)|| defined(LNX)		//wxe and gxe and linux console//~v76nI~
    if (Gwxestat & GWXES_SCROLLBYMOUSE)  //scroll by mouse         //~v76nI~
    {                                                              //~v76nI~
    	Gwxestat&=~GWXES_SCROLLBYMOUSE;  //processed               //~v76nI~
        return Gwxescrollctr;           //                         //~v76nI~
    }                                                              //~v76nI~
#endif                                                             //~v76nI~
	scrollsz=UPCSCROLLPAGE;	//when no operand                      //~v76nI~
    startline=PANL300LISTTOP;                                      //~v76nI~
    endline=Ppcw->UCWmaxline-1;                                    //~v76nI~
    pgsz=Ppcw->UCWheight-startline;                                //~v76nI~
    if ((wkbuff=Ppcw->UCWparm),wkbuff) //input on cmdline set by funccall//~v76nI~
	{                                                              //~v76nI~
		strupr(wkbuff);                                            //~v76nI~
        uparse(wkbuff,wkbuff,&opdno,0,","); //parse out,accept cr/lf//~v76nI~
        if (opdno==1)	//single operand                           //~v76nI~
		{                                                          //~v76nI~
			if (szwk=filechkscrollopd(wkbuff),szwk)                //~v76nI~
            {                                                      //~v76nI~
				scrollsz=szwk;                                     //~v76nI~
//  			setflddata(Ppcw,CMDLINENO,0,"");	//clear cmd data//~v76nR~
//              csronthefld(Ppcw,CMDLINENO,0,0);   //move csr to lcmd fld//~v76nR~
            }                                                      //~v76nI~
		}                                                          //~v76nI~
	}//cmd line input                                              //~v76nI~
                                                                   //~v76nI~
    	if (pgsz<=0)                                               //~v76nI~
			return 0;						//can not scroll       //~v76nI~
		switch(scrollsz)                                           //~v76nI~
		{                                                          //~v76nI~
		case UPCSCROLLPAGE:     //browse default                   //~v76nI~
    		scrollsz=pgsz;                                         //~v76nI~
			break;                                                 //~v76nI~
		case UPCSCROLLHALF:		//edit default                     //~v76nI~
			scrollsz=max(pgsz/2,1);                                //~v76nI~
			break;                                                 //~v76nI~
		case UPCSCROLLCSR:                                         //~v76nI~
			csry=min(Ppcw->UCWrcsry,endline);                      //~v76nI~
			if (Pdest>0)	//forward destination                  //~v76nI~
    			if (csry<=startline)   //on 1st line or up         //~v76nI~
					scrollsz=pgsz;//1 page scroll                  //~v76nI~
				else                                               //~v76nI~
    				scrollsz=csry-startline+1;//move csr line to top//~v76nR~
			else  			//backward                             //~v76nI~
				if (csry>=endline || csry<startline)//on cmdline   //~v76nI~
					scrollsz=pgsz;//1 page scroll                  //~v76nI~
				else                                               //~v76nI~
					scrollsz=Ppcw->UCWheight-csry;                 //~v76nR~
			if (Ppcw->UCWheight>startline+1)   //over 2 line       //~v76nI~
				scrollsz--;                                        //~v76nI~
			break;                                                 //~v76nI~
		case UPCSCROLLMAX:		//max                              //~v76nI~
			scrollsz=-1;          //id of max                      //~v76nI~
			break;                                                 //~v76nI~
		}//by scroll sz                                            //~v76nI~
	return scrollsz;                                               //~v76nI~
}//pan300getscrollsz                                               //~v76nI~
//**********************************************************************//~v76nI~
//*set csr after scroll                                            //~v76nI~
//**********************************************************************//~v76nI~
int pan300scrollsetcsr(PUCLIENTWE Ppcw,int Poldtop,int Pnewtop,int Poldyy)//~v76nR~
{                                                                  //~v76nI~
    int yy,startline,endline;                                      //~v76nR~
//*****************                                                //~v76nI~
	yy=Poldyy;                                                     //~v76nR~
    startline=PANL300LISTTOP;                                      //~v76nI~
    endline=Ppcw->UCWmaxline-1;                                    //~v76nI~
    if (yy<startline || yy>endline)                                //~v76nR~
    	return 0;                                                  //~v76nI~
    yy+=Poldtop-Pnewtop;	//yy on newtop                         //~v76nR~
    if (yy<startline)                                              //~v76nI~
    	yy=startline;                                              //~v76nI~
    else                                                           //~v76nI~
    if (yy>endline)                                                //~v76nI~
    	yy=endline;                                                //~v76nI~
    csronthefld(Ppcw,yy,PANL300LCMD,0);                            //~v76nI~
    return 0;                                                      //~v76nI~
}//pan300scrollsetcsr                                              //~v76nI~
//****************************************************************
// dlcverberr
//*err msg for verb err
//*parm  :none
//*rc    :4
//****************************************************************
int pan300lcmderr(UCHAR *Pcmdtbl)
{
//*********************
	uerrmsg("Invalid,Use one of \"%s\"",
			"–³ŒøƒRƒ}ƒ“ƒh(\"%s\")",
            Pcmdtbl);
	return 4;
}//pan300lcmderr
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// get locale filename from utf8 fld data                          //~va00I~
//rc: 1:f2l done                                                   //~va00I~
//**************************************************************** //~va00I~
int pansetfld_f2l(int Popt,PUPANELL Ppupl,int Pfldno,char *Pdata,char *Pdatabylc,int Poutbuffsz,int *Ppoutlen)//~va00R~
{                                                                  //~va00I~
	int inplen,lenlc,rc=0;                                         //~va00R~
    char *pct,*pu8;                                                //~va00I~
//  UFLDE *pfle;                                                   //~va00R~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	int opt;                                                       //~vaubI~
#endif                                                             //~vaubI~
//************************                                         //~va00I~
//  inplen=strlen(Pdata);                                          //~va00M~//~vb30R~
    inplen=(int)strlen(Pdata);                                     //~vb30I~
//  pfle=&((Ppupl->UPLpfld)->UFLentry[Pfldno]);     //UFLD ptr     //~va00R~
//  offs=pfle->UFLstart;                                           //~va00R~
    pct=Ppupl->UPLcodetype/*+offs*/;                               //~va00R~
    pu8=Ppupl->UPLbuffbyutf8/*+offs*/;                             //~va00R~
//  if (xeutf_getlocalestrm(XEUTFGLSMO_STRZ,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc) & XEUTFGU8MRC_UTF8)//~va00R~
//  if (xeutf_getlocalepathname(XEUTFGLPNO_STRZ,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc) & XEUTFGU8MRC_UTF8)//~vauaR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//FIXME  win?:FIXED                                                     //~vavaI~//~vavcR~//~vawfR~
    opt=XEUTFGLPNO_STRZ|XEUTFGLPNO_LCWIDTHBYDDWIDTH;               //~vaubI~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME fullpath?   :FIXED                                         //~vavcI~//~vavxR~
    if (uftpisremote(Pdata,NULL))                                  //~vavcI~
        opt|=XEUTFGLPNO_REMOTE;                                    //~vavcI~
#endif                                                             //~vavcI~
    if (xeutf_getlocalepathname(opt,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/) & XEUTFGU8MRC_UTF8)//~vaubI~
#else                                                              //~vaubI~
    if (xeutf_getlocalepathname(XEUTFGLPNO_STRZ,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/) & XEUTFGU8MRC_UTF8)//~vauaI~
#endif                                                             //~vaubI~
    {                                                              //~va00I~
    	Ppupl->UPLflags|=UPLFUTF8;	//utf8 code                    //~va00I~
#ifdef W32UNICODE                                                  //~vawfI~
	  if (memchr(Pdatabylc,UD_NOTLC,lenlc))	//drop space from ct of UD str//~vawfI~
      {                                                            //~vawfI~
      	fsubw_stripUDCT(0,Pdatabylc,lenlc,Pdatabylc,lenlc,pct,lenlc,&lenlc);//~vawfI~
        fsubw_stripUDCT(0,Pdata,inplen,pu8,inplen,NULL/*outct*/,0/*outctsz*/,&inplen);//~vawfI~
      }                                                            //~vawfI~
      else                                                         //~vawfI~
#endif                                                             //~vawfI~
      {                                                            //~vawfI~
        memcpy(pu8,Pdata,(UINT)inplen+1); //save utf8              //~va00I~
      }                                                            //~vawfI~
//      Ppupl->UPLctlen=lenlc;                                     //~va00R~
        rc=1;                                                      //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
//  	Ppupl->UPLflags&=~UPLFUTF8;	//no utf8 code                 //~va00I~//~vb30R~
    	Ppupl->UPLflags&=~(ULONG)UPLFUTF8;	//no utf8 code         //~vb30I~
        memcpy(pu8,Pdata,(UINT)inplen+1); //save locale            //~va00R~
//          Ppupl->UPLctlen=inplen;  //set ascii/locale data for long filename upto _MAX_PATH//~va00R~
    }                                                              //~va00I~
    if (Ppoutlen)                                                  //~va00I~
        *Ppoutlen=lenlc;                                           //~va00I~
    return rc;                                                     //~va00I~
}//pansetfld_f2l                                                   //~va00R~
//#ifdef EEE  //by charfldeditu8                                     //~va0tR~//~vavpR~
////*******************************************************          //~va00M~//~vavpR~
////*save kbdinput under UTF8 env by utf8code                        //~va00M~//~vavpR~
////*return locale code len                                          //~va00M~//~vavpR~
////*******************************************************          //~va00M~//~vavpR~
//int pansetfld_l2f(int Popt,PUCLIENTWE Ppcw,PUPANELL Ppupl,int Pfldno,char *Pdata,int *Pputf8len)//~va00R~//~vavpR~
//{                                                                  //~va00M~//~vavpR~
//    UFLD    *pfl;                                                  //~va00M~//~vavpR~
//    char *pdata,*pct,*pu8,*pdbcs;                                  //~va00R~//~vavpR~
////  char wk[_MAX_PATH+80];                                         //~va1cR~//~vavpR~
////  char wk[_MAX_PATH*UTF8_MAXCHARSZMAX];                          //~va1cR~//~vav9R~//~vavpR~
//    char wk[_MAX_PATHU8];                                          //~vav9I~//~vavpR~
//    int inplen,fldoffs,opt,rc2;                                    //~va00R~//~vavpR~
////************************                                         //~va00M~//~vavpR~
//    pfl=Ppupl->UPLpfld;     //UFLD ptr                             //~va00R~//~vavpR~
//    fldoffs=pfl->UFLentry[0].UFLstart; //field addr                //~va00M~//~vavpR~
//    pdata=Ppupl->UPLbuff+fldoffs;                                  //~va00R~//~vavpR~
//    pdbcs=Ppupl->UPLdbcs+fldoffs;      //dbcs tbl                  //~va00R~//~vavpR~
//    pu8=Ppupl->UPLbuffbyutf8/*+fldoffs*/;       //UPLbuffbyutf8    //~va00R~//~vavpR~
//    pct=Ppupl->UPLcodetype/*+fldoffs*/;    //UPLcodetype           //~va00R~//~vavpR~
//    if (!Pdata) //from char pan                                    //~va00I~//~vavpR~
//    {                                                              //~va00I~//~vavpR~
//        inplen=(int)strlen(pdata);                                 //~va00I~//~vavpR~
//        opt=XEUTFCVO_SETCT;  //setup utf8/codetype even when no utf8 contains//~va00R~//~vavpR~
//        rc2=                                                       //~va00I~//~vavpR~
//        xeutf_fldl2f(opt,pdata,pdbcs,wk,inplen,pct,pu8,Pputf8len); //~va00R~//~vavpR~
//    }                                                              //~va00I~//~vavpR~
//    else     //from captofld                                       //~va00I~//~vavpR~
//    {                                                              //~va00I~//~vavpR~
//        inplen=(int)strlen(Pdata);                                 //~va00I~//~vavpR~
//        setdbcstbl(Pdata,pdbcs,inplen);                            //~va00I~//~vavpR~
//        opt=XEUTFCVO_SETCT;  //setup utf8/codetype even when no utf8 contains//~va00R~//~vavpR~
//        rc2=                                                       //~va00I~//~vavpR~
//        xeutf_fldl2f(opt,Pdata,pdbcs,wk,inplen,pct,pu8,Pputf8len); //~va00R~//~vavpR~
//    }                                                              //~va00I~//~vavpR~
//    if (rc2==XEUTFILRC_UTF8)                                       //~va00I~//~vavpR~
//        Ppupl->UPLflags|=UPLFUTF8;  //utf8 code                    //~va00R~//~vavpR~
//    else                                                           //~va00I~//~vavpR~
//        Ppupl->UPLflags&=~UPLFUTF8; //utf8 code                    //~va00I~//~vavpR~
//    return inplen;                                                 //~va00M~//~vavpR~
//}//pansetfld_l2f                                                   //~va00R~//~vavpR~
//#endif  //EEE                                                      //~vaubR~//~vavpR~
//**************************************************************** //~va00I~
// setup utf8 buff                                                 //~va00R~
//*rc    :UALLOC_FAILED                                            //~va00R~
//**************************************************************** //~va00I~
int pan300wakeup1(PUCLIENTWE Ppcw,PUPANELC Pppc)                   //~va00I~
{                                                                  //~va00I~
	char *pc;                                                      //~va00I~
//  UFLDE  *pfle;                                                  //~va00I~//~va0tR~
	PUPANELL   pupl,pupl0;                                         //~va00R~
//  int fldoffs,len,fnmbufflen;                                    //~va00I~//~va0tR~
    int len,fnmbufflen;                                            //~va0tI~
//*********************                                            //~va00I~
//  pfle=getuflde(Ppcw,PANLUGOPT,PANLUDATAFLD);                    //~va00I~//~va0tR~
//  fldoffs=pfle->UFLstart;                                        //~va00I~//~va0tR~
	fnmbufflen=UPLBUFF2SZ;                                         //~va00R~
	len=(fnmbufflen+fnmbufflen)*3;  //(utf8+codetype)*(fnm,dir,cpath)//~va00R~
//  pc=UcALLOC(len);                                               //~va00I~//~vb30R~
    pc=UcALLOC((size_t)len);                                       //~vb30I~
    UALLOCCHK(pc,UALLOC_FAILED);                                   //~va00I~
    Pppc->UPCpandata=pc; //ufree addr                              //~va00I~
	pupl0=Pppc->UPCline;                                           //~va00R~
	pupl=pupl0+PANL300FILENAME;                                    //~va00I~
    pupl->UPLbuffbyutf8=pc;                                        //~va00I~
    pc+=fnmbufflen;                                                //~va00R~
    pupl->UPLcodetype=pc;                                          //~va00I~
    pc+=fnmbufflen;                                                //~va00I~
	pupl=pupl0+PANL300DIR;                                         //~va00R~
    pupl->UPLbuffbyutf8=pc;                                        //~va00I~
    pc+=fnmbufflen;                                                //~va00I~
    pupl->UPLcodetype=pc;                                          //~va00I~
    pc+=fnmbufflen;                                                //~va00I~
	pupl=pupl0+PANL300CURRENT;                                     //~va00R~
    pupl->UPLbuffbyutf8=pc;                                        //~va00I~
    pc+=fnmbufflen;                                                //~va00I~
    pupl->UPLcodetype=pc;                                          //~va00I~
    pc+=fnmbufflen;                                                //~va00I~
    return 0;                                                      //~va00I~
}//pan300wakeup1                                                   //~va00I~
#endif	//UTF8SUPPH                                                //~va00R~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//***********************************************************************//~vaubI~
void setpscddname(PUP300LIST Ppsc,int Pddlen,char *Pdddata,char *Pdddbcs,char *Pddcode)//~vaubR~
{                                                                  //~vaubI~
	char *pc;                                                      //~vaubR~
    char *pcold,*pcdold;                                           //~vavqI~
    int lenold;                                                    //~vavqI~
//***********************                                          //~vaubI~
    if (!Pddlen)                                                   //~vaubI~
        return;                                                    //~vaubI~
    pcold=Ppsc->U3Ldddata;                                         //~vavqI~
    pcdold=Ppsc->U3Ldddbcs;                                        //~vavqI~
    lenold=Ppsc->U3Lddlen;                                         //~vavqI~
    if (pcold                                                      //~vavqI~
    &&  Pddlen==lenold                                             //~vavqI~
#ifdef W32UNICODE                                                  //~vavxI~
    &&  !utfddicmp(0,Pdddata,Pdddbcs,pcold,pcdold,lenold)          //~vavxR~
#else                                                              //~vavxI~
//  &&  !memcmp(Pdddata,pcold,lenold)                              //~vavqI~//~vb30R~
    &&  !memcmp(Pdddata,pcold,(size_t)lenold)                      //~vb30I~
//  &&  !memcmp(Pdddbcs,pcdold,lenold)                             //~vavqI~//~vb30R~
    &&  !memcmp(Pdddbcs,pcdold,(size_t)lenold)                     //~vb30I~
#endif                                                             //~vavxI~
    )                                                              //~vavqI~
    {                                                              //~vavqI~
	    UTRACEP("U3L-get already set same value\n");               //~vavqI~
    	return;                                                    //~vavqI~
    }                                                              //~vavqI~
    if (pcold)                                                     //~vavpI~
    {                                                              //~vavpI~
//FIXME change to free() after test comp:FIXED                           //~vavpI~//~vawfR~
//        uerrmsg("ddstring replacing for old=%s\n",0,               //~vavxR~//~vawfR~
//                    pcold);                                        //~vavxR~//~vawfR~
        ufree(pcold);                                              //~vavxR~
    }                                                              //~vavpI~
//  pc=umalloc(Pddlen*3);                                          //~vaubI~//~vb30R~
    pc=umalloc((size_t)Pddlen*3);                                  //~vb30I~
    UTRACEP("U3L-get Ppsc=%p,pc=%p,len=%d,dddata=%s\n",Ppsc,pc,Pddlen,Pdddata);//~vavpI~
    if (!pc)                                                       //~vaubI~
    	return;                                                    //~vaubI~
    Ppsc->U3Lddlen=Pddlen;                                         //~vaubI~
    Ppsc->U3Ldddata=pc;                                            //~vaubI~
    Ppsc->U3Ldddbcs=pc+Pddlen;                                     //~vaubI~
    Ppsc->U3Lddcode=pc+Pddlen+Pddlen;                              //~vaubI~
//  memcpy(pc,Pdddata,Pddlen);                                     //~vaubI~//~vb30R~
    memcpy(pc,Pdddata,(size_t)Pddlen);                             //~vb30I~
//  memcpy(pc+Pddlen,Pdddbcs,Pddlen);                              //~vaubI~//~vb30R~
    memcpy(pc+Pddlen,Pdddbcs,(size_t)Pddlen);                      //~vb30I~
//  memcpy(pc+Pddlen+Pddlen,Pddcode,Pddlen);                       //~vaubI~//~vb30R~
    memcpy(pc+Pddlen+Pddlen,Pddcode,(size_t)Pddlen);               //~vb30I~
}//setpscddname                                                    //~vaubI~
#endif                                                             //~vaubI~
