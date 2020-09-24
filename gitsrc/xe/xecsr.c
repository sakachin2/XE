//*CID://+vaw1R~:                             update#=   88;       //~vaw1R~
//************************************************************* //~5225I~
// xecsr.c ***                                                  //~v05TR~
//*************************************************************
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vafu:120630 (Win:console) change cursor hight 10%-->15% for visibility up//~vafuI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va3p:100218 (BUG)missing update dbcstbl for vsplitline           //~va3pI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69e:060519 chk scroll-lock on status for up/down arrow key to scroll up/down//~v69eI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v64i:050619 (LNX)xxe support;scr width                           //~v64iI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v500:020827 wxe support                                          //~v500I~
//v45c:011209 (BUG)errmsg may override DBCS filename on hdr line   //~v45cI~
//v44k:011204 (BUG)hex corsor line is invalid for the case setcsr is called//~v44kI~
//v40N:010712 AIX support:clear dbcs on end of page because        //~v40NR~
//            aix curses insert x08 before and after last byte,it may split dbcs//~v40NR~
//v306:001124 AIX support:csr move by screen write;so always csr write for ins/del key etc//~v306I~
//v19o:000916 LINUX support(csr type height level:0-->2)           //~v19oI~
//v17c:000501 No beep for Homekey when already home                //~v17cI~
//v140:000115 it is noisy, so no beep when current client screen changed//~v140I~
//v13c:991023 csrhome when csr is 1st line by csrrestore           //~v137I~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v11R:990904 skip cols line when tab/prevtab csr move             //~v11RI~
//v0jr:980723 call scrdisp for mult cmd because active screen may change//~v0jrI~
//v0jl:980723 no rc set when already home for home func            //~v0jlI~
//v0jj:980723 POS cmd relative offset support,no err evenif out of range//~v0jlI~
//v0j2:980720 POS cmd for fn-cmd key                               //~v0j2I~
//v09W:970628:(BUG)csr restore by DBCS/TAB yet active after nextline//~v09WI~
//            (1)up set savepos because dbcs 2nd byte              //~v09WI~
//            (2)enter move csr to top of line                     //~v09WI~
//            (3)up move csr to prev saved pos                     //~v09WI~
//            -also bug when wrap case                             //~v09WI~
//v09K:970622:change char define value on dbcs tbl                 //~v09KI~
//v09s:970523:(BUG)force csr write after child shell               //~v09sI~
//            (csrwrite bypass write if position not changed)      //~v09sI~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//            (BUG:W95)csr max hight is 99 not 100                 //~v09lI~
//v08g:961106:split uvio to uvio and uvio2                         //~v08gI~
//v08d:961104:(W95)performance up                                  //~v08dI~
//            csr write only when csr pos changed                  //~v08dI~
//v085:961024:W95 VC                                               //~v085I~
//            cursor hight(win is percent value(0-->100)           //~v085I~
//v078:960608:(BUG)panlinetopfld rc(=-1) is not checked;           //~v078I~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v05X:960203:for dos start/end is not pell but number 0-->7    //~v05XI~
//v05T:960131:change csr height for normal to higher            //~v05TI~
//v05w:951203:find cmd for dir list(add csrset option=FROMLEFT) //~v05wI~
//*v032:950712:UFLD for each ppc(use USDpfld)                   //~v032I~
//*v020:950611:dir support(bug of nextline)                     //~5611I~
//*    :950611:display only fld definition                      //~5611I~
//*    :950701:csr set req bit (UCW-->Gprocstatus)              //~5701I~
//************************************************************* //~5611I~
//*950514 bug;tab rtn when csr is over maxline                  //~5514I~
//*950502 bug;csr move to home when browse                      //~5505I~
//*950502 initial Ins mode,Ins Csr type option                  //~5502I~
//*950225 cursor step down                                      //~5225R~
//*941204 maxlineno by UPClineno                                //~5225I~
//*       next-;ine to lineno fld
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <uvio.h>
#include <uvio2.h>                                                 //~v08gI~
#include <ufile.h>                                              //~5318R~
#include <utrace.h>                                                //~v069I~
#include <uedit.h>                                                 //~v0j2I~
#include <ukbd.h>                                                  //~v69bI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~va1cR~
#endif                                                             //~va1qI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v09lI~
#include "xecsr.h"
#include "xefunc.h"
#include "xefile.h"
#include "xefile3.h"                                               //~v55qI~
#include "xefsub.h"                                                //~v69eI~
#include "xepan.h"
#include "xeerr.h"                                                 //~v0j2I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
//#ifdef WXE                                                       //~v69iR~
//    #include "wxexei.h"                                          //~v69iR~
//#endif //!WXE                                                    //~v69iR~
//#ifdef XXE                                                       //~v69iR~
//    #include "xxexei.h"                                          //~v69iR~
//#endif //!WXE                                                    //~v69iR~
//*******************************************************
int csrtopleft(PUCLIENTWE Ppcw);                                //~4C25I~
PUFLD csrfldchksub(PUCLIENTWE Ppcw,int Prow,int Pfldno);        //~4C24R~
UFLDE *srchprevfld(PUSCRD Ppsd,int Ppos);
int csrlastpos(int Pclientid);
int prevposchk(void);
//***********************************************
static  int Sprevposx=0;			//DBCS csr backed sw           //~v60vR~
static  int Skbdinpctr=0; 		//pos saved timing                 //~v60vR~
static  VIOCURSORINFO Scursortypesave;
static  USHORT  Scsrtype[10][2];
static int oldx,oldy;                                              //~v09sR~
static  int Sntotl;			//parm to func_next_tab_pan to skip next_line//~v137I~
static int Sscrollonmsgsw=0;                                       //~v69bI~
//****************************************************************
// cursor init
//****************************************************************
void csrinit(int Pcharh)
{
    int typen,typei;                                            //~5502I~
//*********************                                         //~v05XI~
//* cursor type  table
    if (UCBITCHK(Gopt2,GOPT2BOXREPCSR))  //mox csr for rep mode //~5502I~
    {                                                           //~5502I~
		typen=CSRTYPINS;                                        //~5502I~
		typei=CSRTYPNOR;                                        //~5502I~
    }                                                           //~5502I~
    else 		//box for Ins                                   //~5502I~
    {                                                           //~5502I~
		typen=CSRTYPNOR;                                        //~5502I~
		typei=CSRTYPINS;                                        //~5502I~
    }                                                           //~5502I~
#ifdef UNX                                                         //~v19oI~
	Scsrtype[typen]		[1]	=2;                                    //~v19oI~
	Scsrtype[typen]		[0]	=2;                                    //~v19oI~
	Scsrtype[CSRTYPREV]	[1]	=2;                                    //~v19oI~
	Scsrtype[CSRTYPREV]	[0]	=0;   	//100% (not supported changed to normal)//~v19oI~
	Scsrtype[typei]		[1]	=2;                                    //~v19oI~
	Scsrtype[typei]		[0]	=1;                                    //~v19oI~
	Scsrtype[CSRTYPNON]	[1]	=0;                                    //~v19oI~
	Scsrtype[CSRTYPNON]	[0]	=0;  //0% by dos manual                //~v19oI~
#else //!UNX                                                       //~v19oI~
#ifdef DOS                                                         //~v085R~
	Scsrtype[typen]		[1]	=7;                                 //~v05XI~
	Scsrtype[typen]		[0]	=6;                                 //~v05XI~
	Scsrtype[CSRTYPREV]	[1]	=7;                                 //~v05XI~
	Scsrtype[CSRTYPREV]	[0]	=0;                	//100%          //~v05XI~
	Scsrtype[typei]		[1]	=7;                                 //~v05XI~
	Scsrtype[typei]		[0]	=4;                                 //~v05XI~
	Scsrtype[CSRTYPNON]	[1]	=0;                                 //~v05XI~
//	Scsrtype[CSRTYPNON]	[0]	=0;                 //0%               //~v085R~
	Scsrtype[CSRTYPNON]	[0]	=0x20;  //0% by dos manual             //~v085I~
#else                                                           //~v05XI~
	#ifdef W32                                                     //~v085I~
#ifdef WXE                                                         //~va3xI~//~vafuR~
    	Scsrtype[typen]		[0]	=10;		//10% underline        //~v085I~
#else                                                              //~va3xI~
    	Scsrtype[typen]		[0]	=15;		//15% underline        //~va3xI~//~vafuR~
#endif                                                             //~va3xI~
//  	Scsrtype[CSRTYPREV]	[0]	=100;      	//100% box             //~v09lR~
    	Scsrtype[CSRTYPREV]	[0]	=99;       	//100% box             //~v09lI~
    	Scsrtype[typei]		[0]	=50;		//50% box              //~v085I~
    	Scsrtype[CSRTYPNON]	[0]	=0;			//0% by dos manual     //~v085I~
	#else                                                          //~v085I~
	Scsrtype[typen]		[1]	=(USHORT)(Pcharh-1);                //~5502R~
	Scsrtype[typen]		[0]	=(USHORT)(Pcharh-Pcharh*1/10-1-1);	//10%//~v05TR~
	Scsrtype[CSRTYPREV]	[1]	=(USHORT)(Pcharh-1);                //~5502R~
	Scsrtype[CSRTYPREV]	[0]	=0;                	//100%          //~5502R~
	Scsrtype[typei]		[1]	=(USHORT)(Pcharh-1);                //~5502R~
	Scsrtype[typei]		[0]	=(USHORT)(Pcharh-Pcharh*5/10-1);//50%S//~5502R~
	Scsrtype[CSRTYPNON]	[1]	=0;                                 //~5502R~
	Scsrtype[CSRTYPNON]	[0]	=0;                 //0%            //~5502R~
	#endif                                                         //~v085I~
#endif                                                          //~v05XI~
#endif//!UNX                                                       //~v19oI~
    uviogetcurtype(&Scursortypesave);
#ifdef UNX                                                         //~v19oI~
    if (!Scursortypesave.yStart && !Scursortypesave.cEnd)//curses initily 0//~v19oI~
    {                                                              //~v19oI~
    	Scursortypesave.yStart=2;                                  //~v19oI~
		Scursortypesave.cEnd=2;		//set visble for at return     //~v19oI~
    }                                                              //~v19oI~
#endif                                                             //~v19oI~
    if (UCBITCHK(Gscrstatus,GSCRSINS))  //ins mode at start     //~5502I~
		csrchangetype(CSRTYPINS);						//set csr type//~v05XR~
    else                                                        //~5502I~
		csrchangetype(CSRTYPNOR);						//set csr type//~v05XR~
}//csrinit
//****************************************************************
// cursor term
//****************************************************************
void csrterm(void)
{
    uviosetcurtype(&Scursortypesave);
	return;
}//csrterm

//****************************************************************
//write cursor
// param : none
//****************************************************************
int csrwrite(PUCLIENTWE Ppcw)
{
//  static int x,y;                                                //~v09sR~
//*************************
#ifndef UNX                                                        //~v306R~
  if (oldx!=Gcsrposx || oldy!=Gcsrposy)                            //~v09sR~
  {                                                                //~v08dR~
#endif                                                             //~v306I~
	oldx=Gcsrposx;                                                 //~v09sR~
	oldy=Gcsrposy;                                                 //~v09sR~
	return (int)uviosetcurpos((USHORT)Gcsrposy,(USHORT)Gcsrposx);
#ifndef UNX                                                        //~v306R~
  }                                                                //~v08dR~
  return 0;                                                        //~v60vM~
#endif                                                             //~v306I~
}//csrwrite

//**************************************************************** //~v09sI~
//csrforcewritereq                                                 //~v09sI~
// force csrwrite to issue uviosetcurpos by changing old pos       //~v09sI~
// param : none                                                    //~v09sI~
// return none                                                     //~v09sI~
//**************************************************************** //~v09sI~
void csrforcewritereq(void)                                        //~v09sR~
{                                                                  //~v09sI~
//*************************                                        //~v09sI~
  oldx=oldy=-1;		//change old pos                               //~v09sR~
  return ;                                                         //~v09sI~
}//csrforcewritereq                                                //~v09sI~
                                                                   //~v09sI~
//****************************************************************
// csrsetdbcstbl
//*set grobal dbcs tbl from line dbcs tbl
//*parm1:data co-ord x on full screen
//*parm2:data co-ord y on full screen
//*parm3:data area
//*parm4:line dbcs tbl
//*parm5:line dbcs tbl len(for cell,cell count)                 //~5204R~
//*parm6:cell option  1:cell  0:char
//*rc   :none
//****************************************************************
void csrsetdbcstbl(int Px,int Py,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pcellopt)
{
	int len;
#ifdef UTF8SUPPH                                                   //~va1cR~
	int opt,ii,ctr;                                                //~va1cR~
	UCHAR *pdbcs;                                                  //~va3pI~
#endif                                                             //~va1cR~
//****************************
//  UTRACED("csrsetdbcstbl data",Pdata,Plen);                      //~va3xI~//~vafuR~
//  UTRACED("csrsetdbcstbl dbcs",Pdbcs,Plen);                      //~va3xI~//~vafuR~
	len=csrsetdbcstbl2(Px,Py,Pdbcs,Plen);
#ifdef UTF8SUPPH                                                   //~va1cR~
//*effective when screen vsplit                                    //~va1cR~
	pdbcs=Gscrdbcstbl+Gscrbuffwidth*Py+Px;                         //~va3pI~
    if (Pcellopt)                                                  //~va1cR~
    {                                                              //~va1cR~
		ctr=XESUB_DBCSSPLITCTR_R(Pdbcs,Plen);                      //~va1cR~
        for (ii=0;ii<ctr;ii++)                                     //~va1cR~
        {                                                          //~va1cR~
//  		*(Pdata+((len+ii)<<1))='.';                            //~va3pR~
    		*(Pdata+((ii)<<1))='.';                                //~va3pR~
            *(pdbcs+ii)=0;                                         //~va3pR~
        }                                                          //~va1cR~
		ctr=XESUB_DBCSSPLITCTR_L(Pdbcs,Plen);                      //~va1cR~
        for (ii=1;ii<=ctr;ii++)                                    //~va1cR~
        {                                                          //~va1cR~
			*(Pdata+((len-ii)<<1))='.';                            //~va1cR~
            *(pdbcs+len-ii)=0;                                     //~va3pI~
        }                                                          //~va1cR~
    }                                                              //~va1cR~
    else                                                           //~va1cR~
    {                                                              //~va1cR~
#ifdef AAA                                                         //~va3pI~
		opt=XESUBCDSO_LEFT|XESUBCDSO_REPDATAONLY;                  //~va1cR~
		xesub_cleardbcssplit(opt,Pdata,Pdbcs,Plen,'.');            //~va1cR~
		opt=XESUBCDSO_RIGHT|XESUBCDSO_REPDATAONLY;                 //~va1cR~
		xesub_cleardbcssplit(opt,Pdata,Pdbcs,len,'.');             //~va1cR~
#else                                                              //~va3pI~
		opt=XESUBCDSO_LEFT;                                        //~va3pI~
		xesub_cleardbcssplit(opt,Pdata,pdbcs,Plen,'.');   //left boundary up to Plen//~va3pI~
		opt=XESUBCDSO_RIGHT;                                       //~va3pI~
		xesub_cleardbcssplit(opt,Pdata,pdbcs,len,'.');    //right boundary back from len//~va3pR~
#endif                                                             //~va3pI~
    }                                                              //~va1cR~
#else                                                              //~va1cR~
	if (*Pdbcs==DBCS2NDCHAR)	//start from second byte        //~5103R~
		*Pdata='.';
	if (*(Pdbcs+len-1)==DBCS1STCHAR)	//end at first byte     //~5103R~
    {                                                              //~v55qI~
        if (Pcellopt)                                           //~5204I~
			*(Pdata+len+len-2)='.';                             //~5204I~
        else                                                    //~5204I~
			*(Pdata+len-1)='.';                                 //~5204R~
    }                                                              //~v55qI~
#endif                                                             //~va1cR~
#ifdef AIX                                                         //~v40NR~
    else                                                           //~v40NR~
//  end of page is DBCS case                                       //~v40NR~
    	if (*(Pdbcs+len-1)==DBCS2NDCHAR)	//end at 2nd   byte    //~v40NR~
            if (Px+len==Gscrwidth && Py==Gscrheight-1)	//end of page//~v40NR~
            	if (Pcellopt)                                      //~v40NR~
                {                                                  //~v40NR~
    				*(Pdata+len+len-2)='.';                        //~v40NR~
                    if (len>=2)                                    //~v40NR~
    					*(Pdata+len+len-4)='.';                    //~v40NR~
                }                                                  //~v40NR~
        		else                                               //~v40NR~
                {                                                  //~v40NR~
	    			*(Pdata+len-1)='.';                            //~v40NR~
                    if (len>=2)                                    //~v40NR~
	    				*(Pdata+len-2)='.';                        //~v40NR~
                }                                                  //~v40NR~
//  end of page is DBCS+SBCS case                                  //~v40NR~
    if (len>=2 && *(Pdbcs+len-2)==DBCS2NDCHAR)  //end at 2nd   byte//~v40NR~
        if (Px+len==Gscrwidth && Py==Gscrheight-1)  //end of page  //~v40NR~
            if (Pcellopt)                                          //~v40NR~
            {                                                      //~v40NR~
                *(Pdata+len+len-4)='.';                            //~v40NR~
                if (len>=3)                                        //~v40NR~
                    *(Pdata+len+len-6)='.';                        //~v40NR~
            }                                                      //~v40NR~
            else                                                   //~v40NR~
            {                                                      //~v40NR~
                *(Pdata+len-2)='.';                                //~v40NR~
                if (len>=3)                                        //~v40NR~
                    *(Pdata+len-3)='.';                            //~v40NR~
            }                                                      //~v40NR~
#endif                                                             //~v40NR~
	return ;
}//csrsetdbcstbl                                                   //~vafuR~

//****************************************************************
// csrsetdbcstbl2
//*set grobal dbcs tbl from line dbcs tbl 
//          for next func_right after line data update
//*parm1:data co-ord x on full screen
//*parm2:data co-ord y on full screen
//*parm3:line dbcs tbl
//*parm4:dbcs tbl len
//*rc   :copyed len
//****************************************************************
int csrsetdbcstbl2(int Px,int Py,UCHAR *Pdbcs,int Plen)
{
	UCHAR *ptbl;
	int len;
//****************************
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	ptbl=Gscrdbcstbl+Gscrbuffwidth*Py+Px;                          //~v500I~
#else                                                              //~v500I~
	ptbl=Gscrdbcstbl+Gscrwidth*Py+Px;
#endif                                                             //~v500I~
	len=min(Plen,Gscrwidth-Px);	//limit by line length
	memcpy(ptbl,Pdbcs,(UINT)len);
    UTRACEP("csrsetdbcstbl2 x=%d,y=%d\n",Px,Py);                   //~va3xI~
    UTRACED("csrsetdbcstbl2 dbcs",ptbl,len);                       //~va3xI~
	return len;
}//setgbldbcstbl2
//**************************************************************** //~v45cI~
// csrresetobdbcs                                                  //~v45cI~
//*reset boundary dbcs                                             //~v45cI~
//*parm1:dest;1:next byte,0:prev byte                              //~v45cR~
//*parm2:absolute csr posx                                         //~v45cI~
//*parm3:absolute csr posy                                         //~v45cR~
//*rc   :1:reset occured                                           //~v45cI~
//**************************************************************** //~v45cI~
int  csrresetobdbcs(int Pdest,int Px,int Py)                       //~v45cR~
{                                                                  //~v45cI~
	char *pdbcs;                                                   //~v45cI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	int	opt,len,ctr;                                               //~va1cR~
#endif                                                             //~va1cR~
//****************************                                     //~v45cI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	pdbcs=Gscrdbcstbl+Gscrbuffwidth*Py+Px;                         //~v500I~
#else                                                              //~v500I~
	pdbcs=Gscrdbcstbl+Gscrwidth*Py+Px;                             //~v45cI~
#endif                                                             //~v500I~
    if (Pdest)    //next byte                                      //~v45cI~
    {                                                              //~v45cI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	#ifdef WXEXXE                                                  //~va1cR~
		len=Gscrbuffwidth-Px;                                      //~va1cR~
    #else                                                          //~va1cR~
		len=Gscrwidth-Px;                                          //~va1cR~
    #endif                                                         //~va1cR~
		opt=XESUBCDSO_LEFT;                                        //~va1cR~
		ctr=xesub_cleardbcssplit(opt,0/*Pdata*/,pdbcs,len,0/*repdata*/);//~va1cR~
        return ctr;                                                //~va1cR~
#else                                                              //~va1cR~
		if (*pdbcs!=DBCS2NDCHAR)                                   //~v45cR~
    		return 0;                                              //~v45cR~
#endif                                                             //~va1cR~
    }                                                              //~v45cI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	opt=XESUBCDSO_RIGHT;                                           //~va1cR~
	ctr=xesub_cleardbcssplit(opt,0/*Pdata*/,pdbcs-Px,Px,0/*repdata*/);//~va1cR~
    return ctr;                                                    //~va1cR~
#else                                                              //~va1cR~
    else                 //prev byte                               //~v45cI~
		if (*pdbcs!=DBCS1STCHAR)                                   //~v45cI~
    		return 0;                                              //~v45cI~
    *pdbcs=0;		//sbcsid                                       //~v45cI~
	return 1;                                                      //~v45cI~
#endif                                                             //~va1cR~
}//csrresetobdbcs                                                  //~v45cI~
//****************************************************************
// csrcleardbcstbl
//*set dbcs tbl clear
//*parm1:data co-ord x
//*parm2:data co-ord y
//*parm3:data len
//*rc   :none
//****************************************************************
void csrcleardbcstbl(int Px,int Py,int Plen)
{
//****************************
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	memset(Gscrdbcstbl+Gscrbuffwidth*Py+Px,0,(UINT)Plen);          //~v500I~
#else                                                              //~v500I~
	memset(Gscrdbcstbl+Gscrwidth*Py+Px,0,(UINT)Plen);
#endif                                                             //~v500I~
	return;
}

//****************************************************************
// csrchangetype
//*change cursor type
//*parm :cursor type
//*rc   :0
//****************************************************************
int csrchangetype(int Pcsrtype)
{
	VIOCURSORINFO ci;
//****************************
	ci=Scursortypesave;
	ci.yStart = Scsrtype[Pcsrtype][0];
	ci.cEnd   = Scsrtype[Pcsrtype][1];
    uviosetcurtype(&ci);                                        //~v05XR~
	return 0;                                                   //~v05XR~
}//csrchangetype

//**************************************************************** //~v09lI~
// csrsetwait                                                      //~v09lI~
//*change cursor type to indicate wait a minute                    //~v09lI~
//*parm1:req type 1:set wait,0:reset wait                          //~v09lI~
//*rc   :0 processed,4:already that status                         //~v09lI~
//**************************************************************** //~v09lI~
int csrsetwait(int Preqtype)                                       //~v09lI~
{                                                                  //~v09lI~
static char Swaitmode=0;                                           //~v60vR~
//****************************                                     //~v09lI~
	if ((char)Preqtype==Swaitmode)                                 //~v09lI~
    	return 4;                                                  //~v09lI~
	Swaitmode=(char)Preqtype;                                      //~v09lI~
    if (Swaitmode)                                                 //~v09lI~
		csrchangetype(CSRTYPREV);                                  //~v09lI~
    else                                                           //~v09lI~
    	scrcsrtyperestore();                                       //~v09lR~
	return 0;                                                      //~v09lI~
}//csrsetwait                                                      //~v09lI~
                                                                   //~v09lI~
//****************************************************************
// csrhomepos
//*move cursor to first field of the panel
//*parm :clientid--- 0:current client home position
//*                 -1:another client home position
//*rc   :0,4(home position is hidden)
//****************************************************************
int csrhomepos(int Pclientid)
{
	PUFLD pfl;
	int i,j,maxrow;                                             //~5611R~
	PUPANELD ppd;
	PUSCRD   psd;
	PUCLIENTWE pcw;
//****************************
	if (!(pcw=scrgetcw(Pclientid)))	//get client work
		return 4;
	maxrow=pcw->UCWmaxline;
	for (i=0,psd=pcw->UCWpsd;i<maxrow;i++,psd++)
	{
		if (!(ppd=psd->USDppd))
			return 4;			//end of definition  line
		if (ppd->UPDprottype!=USDF2PROT                         //~5611R~
		&&  ppd->UPDprottype!=USDF2PROTONLY)	//v020          //~5611I~
			break;
	}
	if (i==maxrow)
		return csrtopleft(pcw);                                 //~4C25R~
	pfl=psd->USDpfld;                                           //~v032R~
    j=panlinetopfld(pfl);	//not protected fld                 //~5611I~
    if (j<0                                                        //~v078I~
	||  pcw->UCWwidth<=pfl->UFLentry[j].UFLstart)                  //~v078R~
		return csrtopleft(pcw);                                 //~4C25R~
	pcw->UCWrcsrx=pfl->UFLentry[j].UFLstart;                    //~5611R~
	pcw->UCWrcsry=i;
	csrloctogbl(pcw);   //convert local pos to gbl csr pos      //~4C25R~
	return 0;
}//csrhomepos

//****************************************************************
// csrtopleft                                                   //~4C25R~
//*move cursor to top-left(0,0)                                 //~4C25R~
//*parm :clientwe                                               //~4C25R~
//*rc   :4                                                      //~4C25R~
//****************************************************************
int csrtopleft(PUCLIENTWE Ppcw)                                 //~4C25R~
{                                                               //~4C25I~
	Ppcw->UCWrcsrx=0;                                           //~4C25R~
	Ppcw->UCWrcsry=0;                                           //~4C25R~
	csrloctogbl(Ppcw);   //convert local pos to gbl csr pos     //~4C25R~
	return 4;                                                   //~4C25I~
}//csrtopleft                                                   //~4C25R~
                                                                //~4C25I~
//****************************************************************//~4C25I~
// csrlastpos                                                   //~4C25I~
//*move cursor to last field of the panel                       //~4C25I~
//*parm :clientid--- 0:current client home position             //~4C25I~
//*                 -1:another client home position             //~4C25I~
//*rc   :0,4(last position is hidden)                           //~4C25I~
//****************************************************************//~4C25I~
int csrlastpos(int Pclientid)                                   //~4C25I~
{
	int i,maxrow,width;
	UFLDE *pfle=0;
	PUSCRD   psd;
	PUCLIENTWE pcw;
//****************************
	if (!(pcw=scrgetcw(Pclientid)))	//get client work
		return 4;
	maxrow=pcw->UCWmaxline;
	width=pcw->UCWwidth;		//client width
	for (i=maxrow-1,psd=pcw->UCWpsd+maxrow-1;i>=0;i--,psd--)
	{
		if (pfle=srchprevfld(psd,width),pfle)
			break;
	}
	if (!pfle)
		return 4;
	pcw->UCWrcsrx=pfle->UFLstart;
	pcw->UCWrcsry=i;
	csrloctogbl(pcw);   //convert local pos to gbl csr pos      //~4C25I~
	return 0;
}//csrlastpos

//****************************************************************
// csronthefld                                                  //~5223R~
//*move cursor to specified field top(if parm err moce to cmd line)
//*parm1:PUCLIENTWE
//*parm2:relative ROW(start from 0)
//*parm3:fieldno on the row(start from 0),-1 for from left      //~v05wI~
//*parm4:offset in the fld                                      //~5223I~
//*rc   :0
//****************************************************************
int csronthefld(PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs)  //~5223R~
{
	PUFLD pfl;
//****************************
	UTRACEP("%s:row=%d,fldno=%d,offs=%d\n",UTT,Prow,Pfldno,Poffs);//~vaw1I~
	if (Pfldno==FROMLEFT)                                       //~v05wI~
		Ppcw->UCWrcsrx=Poffs;                                   //~v05wI~
    else                                                        //~v05wI~
    if (Ppcw->UCWtype==UCWTFILE                                 //~5505R~
    &&  UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE)   //~5505R~
    &&	Pfldno==1)                                              //~5505R~
		Ppcw->UCWrcsrx=Ppcw->UCWlinenosz+Poffs;                 //~v069R~
    else                                                        //~5505I~
    {                                                           //~5505I~
		if (!(pfl=csrfldchksub(Ppcw,Prow,Pfldno)))              //~5505R~
			return csrhomepos(0);	//move csr to 1st fld of current active//~5505R~
		Ppcw->UCWrcsrx=pfl->UFLentry[Pfldno].UFLstart+Poffs;    //~5505R~
    }                                                           //~5505I~
	Ppcw->UCWrcsry=Prow;
	csrrestore(Ppcw);   //chk range and convert local pos to gbl csr pos//~4C25I~
	return 0;
}//csronthefld                                                  //~5223R~

//**************************************************************** //~v44kI~
// csronthefldchk                                                  //~v44kI~
//*chk csr position validity                                       //~v44kI~
//*parm1:PUCLIENTWE                                                //~v44kI~
//*parm2:relative ROW(start from 0)                                //~v44kI~
//*parm3:fieldno on the row(start from 0),-1 for from left         //~v44kI~
//*parm4:offset in the fld                                         //~v44kI~
//*rc   :0                                                         //~v44kI~
//**************************************************************** //~v44kI~
int csronthefldchk(PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs)  //~v44kI~
{                                                                  //~v44kI~
	PUFLD pfl;                                                     //~v44kI~
    int csrx;                                                      //~v44kI~
//****************************                                     //~v44kI~
	if (Pfldno==FROMLEFT)                                          //~v44kI~
		csrx=Poffs;                                                //~v44kI~
    else                                                           //~v44kI~
    if (Ppcw->UCWtype==UCWTFILE                                    //~v44kI~
    &&  UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE)      //~v44kI~
    &&	Pfldno==1)                                                 //~v44kI~
		csrx=Ppcw->UCWlinenosz+Poffs;                              //~v44kI~
    else                                                           //~v44kI~
    {                                                              //~v44kI~
		if (!(pfl=csrfldchksub(Ppcw,Prow,Pfldno)))                 //~v44kI~
			return -1;		//out of area                          //~v44kI~
		csrx=pfl->UFLentry[Pfldno].UFLstart+Poffs;                 //~v44kI~
    }                                                              //~v44kI~
    if (csrx>=Ppcw->UCWwidth)                                      //~v44kI~
    	return -1;                                                 //~v44kI~
	return csrx;                                                   //~v44kR~
}//csronthefldchk                                                  //~v44kI~
//****************************************************************//~4C23I~
// csrfldchksub                                                 //~5318R~
//*move cursor to specified field                               //~4C23I~
//*parm1:PUCLIENTWE                                             //~4C23I~
//*parm2:relative ROW(start from 0)                             //~4C23I~
//*parm3:fieldno on the row(start from 0)                       //~4C23I~
//*rc   :PUFLDE or 0(req move to home)                          //~4C23I~
//****************************************************************//~4C23I~
PUFLD csrfldchksub(PUCLIENTWE Ppcw,int Prow,int Pfldno)         //~4C23I~
{                                                               //~4C23I~
	int maxrow;                                                 //~4C23I~
	PUFLD pfl;                                                  //~4C23I~
	PUPANELD ppd;                                               //~4C23I~
	PUSCRD   psd;                                               //~4C23I~
//****************************                                  //~4C23I~
	psd=Ppcw->UCWpsd;			//USCRD                         //~4C23I~
	maxrow=Ppcw->UCWmaxline;                                    //~4C23I~
	if (Prow>=maxrow)	//parm err                              //~4C23I~
		return 0;	//move csr to 1st fld of current active     //~4C23I~
	psd+=Prow;                                                  //~4C23I~
	ppd=psd->USDppd;			//UPANELD                       //~4C23I~
	if (ppd->UPDprottype==USDF2PROT                             //~5611R~
	||	ppd->UPDprottype==USDF2PROTONLY)	//v020              //~5611I~
		return 0;	//move csr to 1st fld of current active     //~4C23I~
                                                                //~4C23I~
	pfl=psd->USDpfld;                                           //~v032I~
	if (Pfldno>=pfl->UFLctr)                                    //~4C23I~
		return 0;	//move csr to 1st fld of current active     //~4C23I~
	return pfl;                                                 //~4C23I~
}//csrfldchksub                                                 //~4C23I~
                                                                //~4C23I~
//****************************************************************
// csrrestore:chk range and convert local pos to global csr pos //~4C25R~
// parm : UCLIENTWE
//****************************************************************
int csrrestore(PUCLIENTWE Ppcw)                                 //~4C25R~
{
//********************
	if (Ppcw->UCWwidth<=Ppcw->UCWrcsrx                          //~4C25I~
	||  Ppcw->UCWrcsry==0                                          //~v137I~
	||  Ppcw->UCWheight<=Ppcw->UCWrcsry)                        //~4C25I~
		return csrhomepos(0); //move csr to top fld          //~4C25I~
                                                                //~4C25I~
	csrloctogbl(Ppcw);	//convert local to gbl csr pos          //~4C25R~
	return 0;                                                   //~4C25R~
}//csrloctogbl                                                  //~4C25R~

//****************************************************************//~4C25I~
// csrloctogbl:convert local pos to global csr pos              //~4C25I~
// parm : UCLIENTWE                                             //~4C25I~
//****************************************************************//~4C25I~
void csrloctogbl(PUCLIENTWE Ppcw)                               //~4C25I~
{                                                               //~4C25I~
//********************                                          //~4C25I~
	UCBITON(Gprocstatus,GPROCSCSRSET);//chek at func_exec_pan for next_line//~v020R~
	Gcsrposx=Ppcw->UCWorgx+Ppcw->UCWrcsrx;                      //~4C25I~
	Gcsrposy=Ppcw->UCWorgy+Ppcw->UCWrcsry;                      //~4C25I~
	return;                                                     //~4C25I~
}//csrloctogbl                                                  //~4C25I~
                                                                //~4C25I~
//****************************************************************
// cursor move functions
//****************************************************************
int func_up(PUCLIENTWE Ppcw)
{
	int rc=0;
    PUFILEC pfc;                                                   //~v55qI~
    PUFILEH pfh;                                                   //~v55qI~
    PULINEH plh;                                                   //~v55qI~
	PUSCRD  psd;                                                   //~v69eI~
//***************
    if (Ppcw->UCWkeyshift & KBDSTF_SCROLLLOCK_ON)                  //~v69eR~
    {                                                              //~v69eI~
        if (Ppcw->UCWtype==UCWTFILE    //filescr                   //~v69eI~
        ||  Ppcw->UCWtype==UCWTDIR)    //filescr                   //~v69eI~
        {                                                          //~v69eI~
            pfc=Ppcw->UCWpfc;                                      //~v69eI~
   			if (CSRONFILEDATA(Ppcw))                               //~v69eI~
            {                                                      //~v69eI~
				psd=Ppcw->UCWpsd;                                  //~v69eI~
                psd+=Ppcw->UCWfilehdrlineno;//top lin              //~v69eI~
				plh=psd->USDbuffc;                                 //~v69eI~
                if (plh && (plh=getdisplayline(plh,-1,0))!=0)      //~v69eI~
                {                                                  //~v69eI~
    	            if (Sscrollonmsgsw!=3)                         //~v69eI~
        	        {                                              //~v69eI~
            	        Sscrollonmsgsw=3;                          //~v69eI~
                	    uerrmsg("ScrollLock ON",0);                //~v69eI~
                	}                                              //~v69eI~
                	pfc->UFCcurtop=plh;                            //~v69eI~
		        	UCBITON(Ppcw->UCWflag,UCWFDRAW);               //~v69eI~
			        return 0;                                      //~v69eI~
                }                                                  //~v69eI~
            }                                                      //~v69eI~
        }                                                          //~v69eI~
    }                                                              //~v69eI~
    Sscrollonmsgsw=0;                                              //~v69bI~
    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL)) //csr scroll mode          //~v55qI~
    {                                                              //~v55qI~
        if (Ppcw->UCWtype==UCWTFILE    //filescr                   //~v55qI~
        ||  Ppcw->UCWtype==UCWTDIR)    //filescr                   //~v55qI~
        {                                                          //~v55qI~
    		if (Ppcw->UCWrcsry==Ppcw->UCWfilehdrlineno             //~v55qI~
		    &&  Ppcw->UCWrcsrx>=(int)Ppcw->UCWlinenosz)            //~v55qI~
            {                                                      //~v55qI~
            	pfc=Ppcw->UCWpfc;                                  //~v55qI~
            	pfh=pfc->UFCpfh;                                   //~v55qI~
				plh=UGETQTOP(&pfh->UFHlineque);                    //~v55qR~
            	if (plh!=pfc->UFCcurtop)                           //~v55qR~
		        	return filepguphalf(Ppcw);                     //~v55qI~
            }                                                      //~v55qI~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
	if (--Gcsrposy<0)
	{
		Gcsrposy=Gscrheight-1;
//  	func_left(Ppcw);                                           //~v09WR~
        if (Sprevposx)                                             //~v09WI~
            Sprevposx--;                                           //~v09WR~
        else                                                       //~v09WI~
        	if (--Gcsrposx<0)                                      //~v09WI~
            	Gcsrposx=Gscrwidth-1;                              //~v09WR~
//  	Gcsrposy=Gscrheight-1;                                     //~v09WM~
      	rc=1;	                                                   //~v09WR~
	}
    rc+=prevposchk();                                              //~v09WR~
	return rc;
}//func_up
//**********************
int func_down(PUCLIENTWE Ppcw)
{
	int rc=0;
    int maxline;                                                   //~v55qI~
    PUFILEC pfc;                                                   //~v69eI~
    PUFILEH pfh;                                                   //~v55qI~
    PULINEH plh;                                                   //~v55qR~
	PUSCRD  psd;                                                   //~v55qI~
//***************
    if (Ppcw->UCWkeyshift & KBDSTF_SCROLLLOCK_ON)                  //~v69eR~
    {                                                              //~v69eI~
        if (Ppcw->UCWtype==UCWTFILE    //filescr                   //~v69eI~
        ||  Ppcw->UCWtype==UCWTDIR)    //filescr                   //~v69eI~
        {                                                          //~v69eI~
            pfc=Ppcw->UCWpfc;                                      //~v69eI~
   			if (CSRONFILEDATA(Ppcw))                               //~v69eR~
            {                                                      //~v69eI~
				psd=Ppcw->UCWpsd;                                  //~v69eI~
                psd+=Ppcw->UCWfilehdrlineno;//top lin              //~v69eI~
				plh=psd->USDbuffc;                                 //~v69eI~
                if (plh && (plh=getdisplayline(plh,1,0))!=0)       //~v69eI~
                {                                                  //~v69eI~
    	            if (Sscrollonmsgsw!=4)                         //~v69eI~
        	        {                                              //~v69eI~
            	        Sscrollonmsgsw=4;                          //~v69eI~
                	    uerrmsg("ScrollLock ON",0);                //~v69eI~
                	}                                              //~v69eI~
                	pfc->UFCcurtop=plh;                            //~v69eI~
		        	UCBITON(Ppcw->UCWflag,UCWFDRAW);               //~v69eI~
			        return 0;                                      //~v69eI~
                }                                                  //~v69eI~
            }                                                      //~v69eI~
        }                                                          //~v69eI~
    }                                                              //~v69eI~
    Sscrollonmsgsw=0;                                              //~v69eM~
    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL)) //csr scroll mode          //~v55qI~
    {                                                              //~v55qI~
        if (Ppcw->UCWtype==UCWTFILE    //filescr                   //~v55qI~
        ||  Ppcw->UCWtype==UCWTDIR)    //filescr                   //~v55qI~
        {                                                          //~v55qI~
    		maxline=Ppcw->UCWmaxline-1;                            //~v55qR~
    		if (Ppcw->UCWrcsry==maxline //csr is on the last line  //~v55qR~
            &&  maxline==Ppcw->UCWheight-1	//filled by line       //~v55qI~
		    &&  Ppcw->UCWrcsrx>=(int)Ppcw->UCWlinenosz)            //~v55qI~
            {                                                      //~v55qI~
				psd=Ppcw->UCWpsd;                                  //~v55qI~
                psd+=maxline;                                      //~v55qI~
                pfh=UGETPFHFROMPCW(Ppcw);                          //~v55qI~
				plh=psd->USDbuffc;                                 //~v55qI~
            	if (plh!=(PULINEH)UGETQEND(&pfh->UFHlineque))      //~v55qR~
		        	return filepgdownhalf(Ppcw);                   //~v55qI~
            }                                                      //~v55qI~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
	if (++Gcsrposy>=Gscrheight)
	{
		Gcsrposy=0;
//  	func_right(Ppcw);                                          //~v09WR~
        if (Sprevposx)                                             //~v09WI~
        {                                                          //~v09WI~
            if (++Sprevposx>=Gscrwidth)                            //~v09WI~
            {                                                      //~v09WI~
            	Sprevposx=0;    //may mean no prev pos but...      //~v09WI~
            	Gcsrposx=0;     //nead also to leftmost            //~v09WI~
            }                                                      //~v09WI~
		}                                                          //~v09WI~
        else                                                       //~v09WI~
        	if (++Gcsrposx>=Gscrwidth)                             //~v09WI~
        		Gcsrposx=0;                                        //~v09WI~
//  	Gcsrposy=0;                                                //~v09WR~
      	rc=1;	                                                   //~v09WR~
//      UTRACEP(" wrap Gposx=%d,Gposy=%d,Sprevposx=%d\n",Gcsrposx,Gcsrposy,Sprevposx);//~v09WR~
	}
    rc+=prevposchk();                                              //~v09WR~
//  UTRACEP("after prevposchk  Gposx=%d,Gposy=%d,Sprevposx=%d\n",Gcsrposx,Gcsrposy,Sprevposx);//~v09WR~
//  UTRACED("dbcs tbl",Gscrdbcstbl+Gcsrposy*Gscrwidth,Gscrwidth);  //~v09WR~
	return rc;
}//func_down
                                                                //~5423I~
//************************************************************  //~5423I~
//*set request to csr down after draw(after set dbcstbl)        //~5423I~
//*parm:pcw                                                     //~5423I~
//*ret :none                                                    //~5423I~
//************************************************************  //~5423I~
void csrchardown(PUCLIENTWE Ppcw)                               //~5423I~
{                                                               //~5423I~
//***************                                               //~5423I~
	UCBITON(Gprocstatus,GPROCSCSRDOWN);                         //~5423R~
	return ;                                                    //~5423I~
}//csrchardown                                                  //~5505R~
                                                                //~5423I~
//********************
int func_left(PUCLIENTWE Ppcw)
{
	int rc=0;
	UCHAR uc;
    PUFILEC pfc;                                                   //~v55qI~
    int scrollctr=1;                                               //~v69bI~
//***************
    if (Ppcw && Ppcw->UCWkeyshift & KBDSTF_SCROLLLOCK_ON)          //~v69bR~
    {                                                              //~v69bI~
        if (Ppcw->UCWtype==UCWTFILE)    //filescr                  //~v69bR~
        {                                                          //~v69bI~
            pfc=Ppcw->UCWpfc;                                      //~v69bI~
    		if (CSRONFILEDATA(Ppcw)                                //~v69bI~
    		&&  pfc->UFCleft)                                      //~v69bI~
            {                                                      //~v69bI~
//#ifdef WXEXXE                                                    //~v69iR~
//                if (Gwxestat & GWXES_MOUSEHSCROLL)  //scroll by mouse//~v69iR~
//                    scrollctr=Gwxescrollctr;                     //~v69iR~
//                else    //no msg when by mouse                   //~v69iR~
//#endif                                                           //~v69iR~
                if (Sscrollonmsgsw!=1)                             //~v69bR~
                {                                                  //~v69bI~
                    Sscrollonmsgsw=1;                              //~v69bR~
                    uerrmsg("ScrollLock ON",0);                    //~v69bI~
                }                                                  //~v69bI~
                pfc->UFCleft=max(0,pfc->UFCleft-scrollctr);        //~v69bR~
		        UCBITON(Ppcw->UCWflag,UCWFDRAW);                   //~v69bI~
		        return 0;                                          //~v69bI~
            }                                                      //~v69bI~
        }                                                          //~v69bI~
    }                                                              //~v69bI~
    Sscrollonmsgsw=0;                                              //~v69bR~
    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL)) //csr scroll mode          //~v55qI~
    {                                                              //~v55qI~
        if (Ppcw && Ppcw->UCWtype==UCWTFILE)    //filescr          //~v55qR~
        {                                                          //~v55qI~
            pfc=Ppcw->UCWpfc;                                      //~v55qI~
    		if ((Ppcw->UCWrcsry>CMDLINENO && Ppcw->UCWrcsry<Ppcw->UCWmaxline)//~v55qI~
    		&&  Ppcw->UCWrcsrx==Ppcw->UCWlinenosz                  //~v55qR~
            &&  pfc->UFCleft)                                      //~v55qR~
		        return filepglefthalf(Ppcw);                       //~v55qR~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
	if (--Gcsrposx<0)
	{
		Gcsrposx=Gscrwidth-1;
      if (Ppcw)  //safety                                          //~v69bI~
		func_up(Ppcw);
		Gcsrposx=Gscrwidth-1;
		rc=1;	
	}
#ifdef UTF8SUPPH                                                   //~va1cR~
#ifdef WXEXXE                                                      //~va1cR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc))//~va1cR~
#else                                                              //~va1cR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc))//~va1cR~
#endif                                                             //~va1cR~
#else //!UTF8SUPPH                                                 //~va1cR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx])==DBCS2NDCHAR//~v500I~
#else                                                              //~v500I~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx])==DBCS2NDCHAR//~5103R~
#endif                                                             //~v500I~
#endif //!UTF8SUPPH                                                //~va1cR~
			||uc==TABPADCHAR)//second byte/tab
		rc+=func_left(0);
//  if (Ppcw)	//by cursor key but by reason dbcs/tab             //~v09WR~
//  	Sprevposx=0;                                               //~v09WR~
	return rc;
}//csrchardown                                                     //~v69eR~
//********************
int func_right(PUCLIENTWE Ppcw)
{
    PUFILEC pfc;                                                   //~v69bI~
	int rc=0;
	UCHAR uc;
    int scrollctr=1;                                               //~v69bI~
//***************
    if (Ppcw && Ppcw->UCWkeyshift & KBDSTF_SCROLLLOCK_ON)          //~v69bI~
    {                                                              //~v69bI~
        if (Ppcw->UCWtype==UCWTFILE)    //filescr                  //~v69bI~
        {                                                          //~v69bI~
            pfc=Ppcw->UCWpfc;                                      //~v69bI~
    		if (CSRONFILEDATA(Ppcw))                               //~v69bI~
            {                                                      //~v69bI~
                if (pfc->UFCleft<MAXLINEDATA-Ppcw->UCWwidth)       //~v69bI~
                {                                                  //~v69bI~
//#ifdef WXEXXE                                                    //~v69iR~
//                    if (Gwxestat & GWXES_MOUSEHSCROLL)  //scroll by mouse//~v69iR~
//                        scrollctr=Gwxescrollctr;                 //~v69iR~
//                    else                                         //~v69iR~
//#endif                                                           //~v69iR~
    	            if (Sscrollonmsgsw!=2)                         //~v69bR~
        	        {                                              //~v69bI~
            	        Sscrollonmsgsw=2;                          //~v69bR~
                	    uerrmsg("ScrollLock ON",0);                //~v69bI~
                	}                                              //~v69bI~
                	pfc->UFCleft+=scrollctr;                       //~v69bR~
		        	UCBITON(Ppcw->UCWflag,UCWFDRAW);               //~v69bR~
                }                                                  //~v69bI~
		        return 0;                                          //~v69bI~
            }                                                      //~v69bI~
        }                                                          //~v69bI~
    }                                                              //~v69bI~
    Sscrollonmsgsw=0;                                              //~v69bR~
    if (UCBITCHK(Gopt5,GOPT5CSRSCROLL)) //csr scroll mode          //~v55qI~
    {                                                              //~v55qI~
        if (Ppcw && Ppcw->UCWtype==UCWTFILE)    //not tab skip filescr//~v55qR~
        {                                                          //~v55qI~
    		if ((Ppcw->UCWrcsry>CMDLINENO && Ppcw->UCWrcsry<Ppcw->UCWmaxline)//~v55qR~
    		&&  Ppcw->UCWrcsrx==Ppcw->UCWwidth-1)                  //~v55qR~
		        return filepgrighthalf(Ppcw);                      //~v55qI~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
	if (++Gcsrposx>=Gscrwidth)
	{
		Gcsrposx=0;
      if (Ppcw)  //safety                                          //~v69bI~
		func_down(Ppcw);
		Gcsrposx=0;
		rc=1;	
	}
#ifdef UTF8SUPPH                                                   //~va1cR~
#ifdef WXEXXE                                                      //~va1cR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc))//~va1cR~
#else                                                              //~va1cR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc))//~va1cR~
#endif                                                             //~va1cR~
#else //!UTF8SUPPH                                                 //~va1cR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx])==DBCS2NDCHAR//~v500I~
#else                                                              //~v500I~
	while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx])==DBCS2NDCHAR//~5103R~
#endif                                                             //~v500I~
#endif //!UTF8SUPPH                                                //~va1cR~
			||uc==TABPADCHAR)//second byte/tab
		rc+=func_right(0);
//  if (Ppcw)	//by cursor key but by reason dbcs/tab             //~v09WR~
//  	Sprevposx=0;                                               //~v09WR~
	return rc;
}//func_right

//************************************************************  //~5423I~
//*set request to csr right after draw(after set dbcstbl)       //~5423I~
//*parm:pcw                                                     //~5423I~
//*ret :none                                                    //~5423I~
//************************************************************  //~5423I~
void csrcharright(PUCLIENTWE Ppcw)                              //~5423I~
{                                                               //~5423I~
//***************                                               //~5423I~
	UTRACEP("%s",UTT);                                             //~vaw1I~
	UCBITON(Gprocstatus,GPROCSCSRRIGHT);                        //~5423I~
	return ;                                                    //~5423I~
}//csrcharright                                                 //~5423I~
                                                                //~5423I~
//****************************************************************
// consider previous x-pos shift by dbcs/tab
//****************************************************************
int prevposchk(void)
{ 
#ifdef UTF8SUPPH                                                   //~va1cR~
	UCHAR uc;                                                      //~va1cR~
#endif                                                             //~va1cR~
	int rc=0;
//**************************
	if (Sprevposx 		//shift occuer previously                  //~v09WR~
    &&  Gkbdinpctr==(Skbdinpctr+1)) //continued operation          //~v09WI~
	{
		Gcsrposx=Sprevposx;
//#ifdef WXE                                                       //~v64iR~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
#ifdef UTF8UCS416       //FIXME test surrogate:FIXED               //~vaw1R~
	#ifdef WXEXXE                                                  //~va3xR~
		switch (UDBCSCHK_TEMPDBCSID(Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx]))//~va3xR~
	#else                                                          //~va3xR~
		switch (UDBCSCHK_TEMPDBCSID(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]))//~va3xR~
	#endif                                                         //~va3xR~
#else                                                              //~va3xR~
#ifdef WXEXXE                                                      //~v64iR~
		switch (Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx])      //~v500I~
#else                                                              //~v500I~
		switch (Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx])
#endif                                                             //~v500I~
#endif                                                             //~va3xR~
		{
//  	case 0:			//sbcs                                     //~v09WR~
//  		Sprevposx=0;                                           //~v09WR~
//  		break;                                                 //~v09WR~
//  	case 2:			//dbcs second byte                         //~v09KR~
    	case DBCS2NDCHAR:			//dbcs second byte             //~v09KI~
#ifdef UTF8SUPPH        	                                       //~va1cR~
    	case UDBCSCHK_DBCSPAD:			//dbcs second byte         //~va1cR~
    #ifdef UTF8UCS2                                                //~va20I~
    	case UDBCSCHK_DBCS2NDUCS_CASE()://ucs 2nd byte             //~va20I~
    #endif                                                         //~va20I~
	#ifdef WXEXXE                                                  //~va1cR~
    		while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc)))//~va1cR~
	#else                                                          //~va1cR~
    		while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc)))//~va1cR~
	#endif                                                         //~va1cR~
				rc=func_left(0);                                   //~va1cR~
#else                                                              //~va1cR~
			rc=func_left(0);
#endif                                                             //~va1cR~
            Skbdinpctr=Gkbdinpctr;  //continue save pos effective  //~v09WI~
			break;
//  	case 3:			//tab skip byte                            //~v09KR~
    	case TABPADCHAR:			//tab skip byte                //~v09KI~
//  		while(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]==3)     //~v09KR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    		while(Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx]==TABPADCHAR)//~v500I~
#else                                                              //~v500I~
    		while(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]==TABPADCHAR)//~v09KI~
#endif                                                             //~v500I~
				if (rc=func_left(0),rc)
					break;
            Skbdinpctr=Gkbdinpctr;  //continue save pos effective  //~v09WI~
			break;
    	default:			//sbcs                                 //~v09WI~
    		Sprevposx=0;                                           //~v09WI~
    		break;                                                 //~v09WI~
		}//switch
	}
	else	//no previous shift
    {                                                              //~v09WI~
  		Sprevposx=0;	//for the case kbd inpctr                  //~v09WI~
//#ifdef WXE                                                       //~v64iR~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
#ifdef UTF8UCS416       //FIXME test surrogate :FIXED              //~vaw1R~
	#ifdef WXEXXE                                                  //~va3xR~
		switch (UDBCSCHK_TEMPDBCSID(Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx]))//~va3xR~
	#else                                                          //~va3xR~
		switch (UDBCSCHK_TEMPDBCSID(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]))//~va3xR~
	#endif                                                         //~va3xR~
#else                                                              //~va3xR~
#ifdef WXEXXE                                                      //~v64iR~
		switch (Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx])      //~v500I~
#else                                                              //~v500I~
		switch (Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx])
#endif                                                             //~v500I~
#endif                                                             //~va3xR~
		{
//  	case 2:			//dbcs second byte                         //~v09KR~
    	case DBCS2NDCHAR:			//dbcs second byte             //~v09KI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	case UDBCSCHK_DBCSPAD:			//dbcs second byte         //~va1cR~
    #ifdef UTF8UCS2                                                //~va20I~
    	case UDBCSCHK_DBCS2NDUCS_CASE()://ucs 2nd byte             //~va20I~
    #endif                                                         //~va20I~
#endif                                                             //~va1cR~
			Sprevposx=Gcsrposx;	//save cur posx
            Skbdinpctr=Gkbdinpctr;  //for continue chk             //~v09WI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	#ifdef WXEXXE                                                  //~va1cR~
    		while((uc=Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc)))//~va1cR~
	#else                                                          //~va1cR~
    		while((uc=Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx],UDBCSCHK_DBCSNOT1ST(uc)))//~va1cR~
	#endif                                                         //~va1cR~
				rc=func_left(0);                                   //~va1cR~
#else                                                              //~va1cR~
			rc=func_left(0);
#endif                                                             //~va1cR~
			break;
//  	case 3:			//tab skip byte                            //~v09KR~
    	case TABPADCHAR:			//tab skip byte                //~v09KI~
			Sprevposx=Gcsrposx;	//save cur posx
            Skbdinpctr=Gkbdinpctr;  //for continue chk             //~v09WI~
//  		while(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]==3)     //~v09KR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    		while(Gscrdbcstbl[Gcsrposy*Gscrbuffwidth+Gcsrposx]==TABPADCHAR)//~v500I~
#else                                                              //~v500I~
    		while(Gscrdbcstbl[Gcsrposy*Gscrwidth+Gcsrposx]==TABPADCHAR)//~v09KI~
#endif                                                             //~v500I~
				if (rc=func_left(0),rc)
					break;
			break;
		}//switch
	}                                                              //~v09WI~
	return rc;
}//prevposchk
//*******************************************************
//*func_home
//*move cursor to top of client screen,
//*  if already move to another client home position
//*******************************************************
int func_home(PUCLIENTWE Ppcw)
{
	int x,y,rc;
//***************
    Sscrollonmsgsw=0;                                              //~v69bI~
	x=Gcsrposx;		//save current to chk change
	y=Gcsrposy;		//save current to chk change
	rc=csrhomepos(0);	//move csr to 1st fld of current active
	if (x==Gcsrposx && y==Gcsrposy) //not changed               //~4C31R~
    {                                                              //~v55qI~
		if (UCBITCHK(Gscrstatus,GSCRSSPLITV|GSCRSSPLITH))
			rc=csrhomepos(-1);//move to 1st fld of another client screen
		else
        {                                                          //~v0jlR~
//          if (Ppcw->UCWkeytype!=UCWKTCMD)   //cmd input          //~v17cR~
//            return 4;                                            //~v17cR~
          rc=0;                                                    //~v0jlR~
        }                                                          //~v0jlR~
    }                                                              //~v55qI~
	return rc;
}//func_right

//****************************************************************
// func_nextline
//*move cursor to top field of next line regardless client boundary
//*parm1:PUCLIENTWE
//*rc   :0  4:rounded to first, 8:active screen changed         //~5514R~
//****************************************************************
int func_nextline(PUCLIENTWE Ppcw)
{
	PUFLD pfl=0;                                                   //~v19oR~
	PUPANELD ppd=0;                                                //~v19oR~
	PUSCRD   psd;
	int i,x,y,width,fldno=0,maxrow;                                //~v19oR~
//****************************
    Sscrollonmsgsw=0;                                              //~v69bI~
	psd=Ppcw->UCWpsd;			//USCRD
	width=Ppcw->UCWwidth;			//client width
	y=Ppcw->UCWrcsry+1;			//search start
	maxrow=Ppcw->UCWmaxline;
	for (i=y,psd+=y;i<maxrow;i++,psd++)
	{
		ppd=0;							//for chk end of line
		if (!(psd->USDbuffc))			//no line data
//			break;                                              //~5611R~
 			continue;					//may exist having buffc//~5611I~
		ppd=psd->USDppd;				//UPANELD
		if (ppd->UPDprottype==USDF2PROT                         //~5611R~
		||  ppd->UPDprottype==USDF2PROTONLY)                    //~5611I~
			continue;
        if (UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2)))    //vhex mode hex line//~v60vI~
			continue;                                              //~v60vI~
		pfl=psd->USDpfld;                                       //~v032I~
	    fldno=panlinetopfld(pfl);	//not protected fld         //~5611I~
        if (fldno<0)                                               //~v078R~
            continue;                                              //~v078I~
//a1c@test                                                         //~v069I~//~va1cR~
//  UTRACEP("row=%d,fldno=%d\n",i,fldno);                          //~v078R~
//  UTRACED("pfl",pfl,256);                                        //~v078R~
//  UTRACED("pflde",&(pfl->UFLentry[fldno].UFLstart),16);   //on screen width//~v078R~
//a1c@test                                                         //~v069I~//~va1cR~
		if (pfl->UFLentry[fldno].UFLstart<width)	//on screen width
			break;
	}
	if (ppd && i<maxrow)
	{
		Ppcw->UCWrcsrx=pfl->UFLentry[fldno].UFLstart;
		Ppcw->UCWrcsry=i;
		csrloctogbl(Ppcw);	//convert local pos to global csr pos//~4C25R~
		return 0;
	}
	if (!csrhomepos(-1))	//move to 1st fld of another client screen
//  	return 8;                                                  //~v140R~
    	return 0;                                                  //~v140I~
    x=Ppcw->UCWrcsrx;                                           //~5514I~
    y=Ppcw->UCWrcsry;                                           //~5514I~
	csrhomepos(0);			//home of myself 
    if (x!=Ppcw->UCWrcsrx || y!=Ppcw->UCWrcsry)	//pos changed   //~5514I~
		if (y<Ppcw->UCWmaxline)	//back around                   //~5514I~
//      	return 4;                                              //~v140R~
	    	return 0;                                              //~v140I~
	return 0;
}//func_nextline

//****************************************************************
// func_prevline                                                //~5514R~
//*move cursor to last field of prev line regardless client boundary
//*parm1:PUCLIENTWE
//*rc   :0 , 4:rounded to last, 8:active screen changed         //~5514R~
//****************************************************************
int func_prevline(PUCLIENTWE Ppcw)
{
	UFLDE *pfle=0;
	PUSCRD   psd;
	int i,x,y,width;                                            //~5514R~
//****************************
	psd=Ppcw->UCWpsd;			//USCRD
	width=Ppcw->UCWwidth;			//client width
	if ((y=Ppcw->UCWrcsry-1)<Ppcw->UCWmaxline)	//search start  //~5514R~
    {                                                           //~5514I~
    	pfle=0;	//init for when usdbuffc=0                         //~v11RI~
		for (i=y,psd+=y;i>=0;i--,psd--)                         //~5514R~
        {                                                          //~v11RI~
			if (!(psd->USDbuffc))			//no line data         //~v11RI~
 				continue;					//may exist having buffc//~v11RI~
        	if (UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2)))    //vhex mode hex line//~v60vI~
				continue;                                          //~v60vI~
			if (pfle=srchprevfld(psd,width),pfle)               //~5514R~
				break;                                          //~5514R~
		}                                                          //~v11RI~
		if (pfle)                                               //~5514R~
		{	//search last fld in the window                     //~5514R~
			Ppcw->UCWrcsry=i;                                   //~5514R~
			Ppcw->UCWrcsrx=pfle->UFLstart;                      //~5514R~
			csrloctogbl(Ppcw);	//convert local pos to global csr pos//~5514R~
			return 0;                                           //~5514R~
		}                                                       //~5514R~
		if (!csrlastpos(-1))	//move to 1st fld of another client screen//~5514R~
			return 8;       //id of active changed              //~5514R~
	}//on the range                                             //~5514I~
    x=Ppcw->UCWrcsrx;                                           //~5514I~
    y=Ppcw->UCWrcsry;                                           //~5514I~
	csrlastpos(0);			//home of myself 
    if (x!=Ppcw->UCWrcsrx || y!=Ppcw->UCWrcsry)	//pos changed   //~5514I~
		if (y<Ppcw->UCWmaxline)	//back around                   //~5514I~
	    	return 4;                                           //~5514R~
	return 0;                                                   //~5514R~
}//func_prevline

//**************************************************************** //~v137I~
// csrnexttaboftheline                                             //~v137I~
//*call func_nexttab_pan(bypass nextline if no field in the line)  //~v137I~
//*parm1:PUCLIENTWE                                                //~v137I~
//*rc   :0:next tab found in the same line,4:not found             //~v137I~
//**************************************************************** //~v137I~
int csrnexttaboftheline(PUCLIENTWE Ppcw)                           //~v137I~
{                                                                  //~v137I~
	int rc;                                                        //~v137I~
//****************************                                     //~v137I~
	Sntotl=1;			//parm to func_next_tab_pan to skip next_line//~v137I~
	rc=func_nexttab_pan(Ppcw);                                     //~v137I~
	Sntotl=0;                                                      //~v137I~
    return rc;                                                     //~v137I~
}//csrnexttaboftheline                                             //~v137I~
//****************************************************************
// func_nexttab_pan
//*move cursor to next field regardless client boundary
//*parm1:PUCLIENTWE
//*rc   :0
//****************************************************************
int func_nexttab_pan(PUCLIENTWE Ppcw)
{
	PUFLD pfl;
	PUPANELD ppd;
	PUSCRD   psd;
	int i,j,x;
//****************************
	psd=Ppcw->UCWpsd;			//USCRD
	x=Ppcw->UCWrcsrx;			//current pos
//search on the line
    if (Ppcw->UCWrcsry<Ppcw->UCWmaxline)	//on the line range //~5514R~
    {                                                           //~5514I~
		psd+=Ppcw->UCWrcsry;			//UPANELD               //~5514R~
		ppd=psd->USDppd;				//UPANELD               //~5514R~
		if (ppd->UPDprottype!=USDF2PROT                         //~5611R~
		&&  (psd->USDbuffc)     		//no cols line             //~v11RI~
		&&  ppd->UPDprottype!=USDF2PROTONLY)                    //~5611I~
		{                                                       //~5514R~
			pfl=psd->USDpfld;                                   //~v032I~
//a1c@test                                                         //~v069I~//~va1cR~
//  UTRACEP("row=%d,col=%d",Ppcw->UCWrcsry,Ppcw->UCWrcsrx);        //~v078R~
//  UTRACED("pfl",pfl,256);                                        //~v078R~
//a1c@test                                                         //~v069I~//~va1cR~
			if (UCBITCHK(psd->USDflag2,USDF2PROTFHDR))          //~5514R~
				j=1;                                            //~5514R~
			else                                                //~5514R~
				j=pfl->UFLctr;                                  //~5514R~
			for (i=0;i<j;i++)                                   //~5514R~
			{                                                   //~5514R~
				if (!UCBITCHK(pfl->UFLentry[i].UFLflag,UFLEFPROT))//v020//~5611I~
				if (pfl->UFLentry[i].UFLstart > x)              //~5514R~
					break;                                      //~5514R~
			}                                                   //~5514R~
			if (i<j)                                            //~5514R~
				if (pfl->UFLentry[i].UFLstart < Ppcw->UCWwidth) //~5514R~
				{                                               //~5514R~
					Ppcw->UCWrcsrx=pfl->UFLentry[i].UFLstart;   //~5514R~
					csrloctogbl(Ppcw);	//convert local pos to global csr pos//~5514R~
					return 0;                                   //~5514R~
				}                                               //~5514R~
//a1c@test                                                         //~v069I~//~va1cR~
//  UTRACEP("goto nextline fldno=%d,max=%d",i,j);                  //~v078R~
//a1c@test                                                         //~v069I~//~va1cR~
		}//not protected                                        //~5514R~
	}//under maxline                                            //~5514I~
	if (Sntotl)			//parm to func_next_tab_pan to skip next_line//~v137I~
    	return 4;                                                  //~v137I~
	return func_nextline(Ppcw);			//next line
}//func_nexttab_pan

//****************************************************************
// func_prevtab_pan                                             //~5514R~
//*move cursor to previous field regardless client boundary
//*parm1:PUCLIENTWE
//*rc   :0
//****************************************************************
int func_prevtab_pan(PUCLIENTWE Ppcw)                           //~5514R~
{
	PUCLIENTWE pcw;                                             //~5514I~
	UFLDE *pfle;
	PUSCRD   psd;
    int rc;                                                     //~5514I~
//****************************
    if (Ppcw->UCWrcsry<Ppcw->UCWmaxline)    //on the range      //~5514R~
    {                                                           //~5514I~
		psd=Ppcw->UCWpsd;			//USCRD                     //~5514R~
//  	pfle=srchprevfld(psd+Ppcw->UCWrcsry,Ppcw->UCWrcsrx);       //~v11RR~
    	psd+=Ppcw->UCWrcsry;		//the line                     //~v11RI~
     if (psd->USDbuffc)     		//no cols line                 //~v11RI~
     {                                                             //~v11RI~
    	pfle=srchprevfld(psd,Ppcw->UCWrcsrx);                      //~v11RI~
		if (pfle)                                               //~5514R~
		{                                                       //~5514R~
			Ppcw->UCWrcsrx=pfle->UFLstart;                      //~5514R~
			csrloctogbl(Ppcw);	//convert local pos to global csr pos//~5514R~
			return 0;                                           //~5514R~
		}                                                       //~5514R~
      }//not cols line                                             //~v11RI~
	}//on the range                                             //~5514I~
	if (rc=func_prevline(Ppcw),rc)	//round to another pcw last line//~5514R~
    {                                                           //~5514I~
    	if (rc==8)                                              //~5514I~
			pcw=scrgetcw(-1);		//get another client work   //~5514R~
        else                                                    //~5514I~
        	pcw=Ppcw;                                           //~5514I~
    	if (pcw->UCWtype==UCWTFILE)                             //~5514I~
			if (CSRONFILEDATA(pcw))		//on data(prev or last line)//~5514I~
			{                                                   //~5514I~
        		pcw->UCWrcsrx=pcw->UCWwidth;                    //~5514I~
				func_prevtab_file(pcw);                         //~5514I~
        	}                                                   //~5514I~
    }                                                           //~5514I~
	return rc;                                                  //~5514I~
}//func_prevtab_pan                                             //~5514R~

//****************************************************************
// srchprevfld                                                  //~4C25R~
//*search last field of line displayed
//*parm1:USCRD
//*parm2:current pos
//*ret  :UFLDE ptr,0 if not displayed
//****************************************************************
UFLDE *srchprevfld(PUSCRD Ppsd,int Ppos)
{
	PUFLD pfl;
	PUPANELD ppd;
	int i,j;
//****************
	if (!(ppd=Ppsd->USDppd))			//UPANELD
		return 0;
	if (ppd->UPDprottype==USDF2PROT                             //~5611R~
	||  ppd->UPDprottype==USDF2PROTONLY)                        //~5611I~
		return 0;
	pfl=Ppsd->USDpfld;                                          //~v032R~
	if (UCBITCHK(Ppsd->USDflag2,USDF2PROTFHDR))
		j=0;
	else
		j=pfl->UFLctr-1;
	for (i=j;i>=0;i--)
	{
		if (!UCBITCHK(pfl->UFLentry[i].UFLflag,UFLEFPROT))//v020//~5611I~
		if (pfl->UFLentry[i].UFLstart < Ppos) 
			return pfl->UFLentry+i;
	}
	return 0;
}//srchprevfld                                                  //~5611R~
                                                                //~5225I~
//****************************************************************//~5225I~
// func_csrstep                                                 //~5225I~
//*toggle csr step direction                                    //~5225I~
//*parm1:PUCLIENTWE                                             //~5225I~
//*rc   :0                                                      //~5225I~
//****************************************************************//~5225I~
int func_csrstep(PUCLIENTWE Ppcw)                               //~5225I~
{                                                               //~5225I~
    UCHAR *pc;                                                  //~5225I~
//****************************                                  //~5225I~
	if (Ppcw->UCWkeytype==UCWKTCMD	//cmd input                 //~5225I~
 	&&  (pc=Ppcw->UCWparm,pc))				//parm exist	   	//~5225R~
    {                                                           //~5225I~
		if (!strcmp(strupr(pc),"ON"))                           //~5225I~
			UCBITON(Gscrstatus,GSCRSCSRDOWN);//stepdown mode    //~5225I~
        else                                                    //~5225I~
			if (!strcmp(strupr(pc),"OFF"))                      //~5225I~
				UCBITOFF(Gscrstatus,GSCRSCSRDOWN);//stepright mode//~5225I~
            else                                                //~5225I~
            {                                                   //~5225I~
				uerrmsg("Specify On/Off operand,toggle if no operand",//~5225I~
						"オペランドに ON/OFF を指定して下さい,無指定は反転");//+vaw1I~
				return 4;                                       //~5225I~
        	}                                                   //~5225I~
    }                                                           //~5225I~
    else                                                        //~5225I~
		UCBITXOR(Gscrstatus,GSCRSCSRDOWN);	//reverse csr down  //~5225R~
                                                                //~5225I~
	if (UCBITCHK(Gscrstatus,GSCRSSPLITH|GSCRSSPLITV))	//split //~5423I~
       UCBITON(scrgetcw(-1)->UCWpsd->USDflag2,USDF2DRAW);//redraw hdr for =///~5423R~
                                                                //~5423I~
	if (UCBITCHK(Gscrstatus,GSCRSCSRDOWN))                      //~5225R~
    	uerrmsg("Now,Cursor mode is step-to-down",              //~5225I~
    			"縦書きモードに設定");                             //+vaw1I~
	else                                                        //~5225I~
    	uerrmsg("Now,Cursor mode is step-to-right",             //~5225I~
    			"横書きモードに設定");                             //+vaw1I~
	return 0;                                                   //~5225I~
}//func_csrstep                                                 //~5225I~
                                                                //~5225I~
//**************************************************************** //~v0j2I~
// func_pos_pan                                                    //~v0j2I~
//*move csr                                                        //~v0j2I~
//*parm1:PUCLIENTWE                                                //~v0j2I~
//*rc   :0                                                         //~v0j2I~
//**************************************************************** //~v0j2I~
int func_pos_pan(PUCLIENTWE Ppcw)                                  //~v0j2I~
{                                                                  //~v0j2I~
    UCHAR *pc;                                                     //~v0j2I~
    int pos[2],posw;                                               //~v0j2I~
    int opdno,ii,len;                                              //~v0j2R~
    int sign;                                                      //~v0jjI~
//****************************                                     //~v0j2I~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v0j2I~
    pc=Ppcw->UCWopdpot;                                            //~v0j2I~
    if (opdno>2)                                                   //~v0j2I~
        return errtoomany();                                       //~v0j2I~
    if (opdno<1)                                                   //~v0j2R~
        return errmissing();                                       //~v0j2I~
    pos[1]=Gcsrposx;        //default                              //~v0j2I~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v0j2I~
	{                                                              //~v0j2I~
        if (!*pc)                                                  //~v0j2I~
			pos[ii]=0;                                             //~v0j2I~
        else                                                       //~v0j2I~
        {                                                          //~v0j2I~
        	len=(int)strlen(pc);                                   //~v0j2R~
            if (*pc=='+')                                          //~v0jjI~
                sign=1;                                            //~v0jjR~
            else                                                   //~v0jjI~
	            if (*pc=='-')                                      //~v0jjI~
    	            sign=-1;                                       //~v0jjR~
        	    else                                               //~v0jjI~
            	    sign=0;                                        //~v0jjI~
            if (sign)                                              //~v0jjI~
            {                                                      //~v0jjI~
                len--;                                             //~v0jjI~
                pc++;                                              //~v0jjI~
            }                                                      //~v0jjI~
        	if (unumlen(pc,0,len)!=len)	//numeric err              //~v0j2I~
	            return errinvalid(pc);                             //~v0j2I~
            posw=atoi(pc);                                         //~v0j2I~
            if (!ii)                                               //~v0j2I~
            {                                                      //~v0j2I~
    	        if (sign>0)                                        //~v0jjI~
        	        posw+=Gcsrposy;                                //~v0jjI~
                else                                               //~v0jjI~
    	        	if (sign<0)                                    //~v0jjI~
        	        	posw=Gcsrposy-posw;                        //~v0jjI~
//  			if (posw<0 || posw>=Gscrheight)                    //~v0jjR~
//  	            return errinvalid(pc);                         //~v0jjR~
				if (posw>=Gscrheight)                              //~v0jjI~
					posw=Gscrheight-1;                             //~v0jjI~
    			if (posw<0)                                        //~v0jjI~
                    posw=0;                                        //~v0jjI~
                pos[0]=posw;                                       //~v0j2I~
            }                                                      //~v0j2I~
            else                                                   //~v0j2I~
            {                                                      //~v0j2I~
    	        if (sign>0)                                        //~v0jjI~
        	        posw+=Gcsrposx;                                //~v0jjI~
                else                                               //~v0jjI~
    	        	if (sign<0)                                    //~v0jjI~
        	        	posw=Gcsrposx-posw;                        //~v0jjI~
//  			if (posw<0 || posw>=Gscrwidth)                     //~v0jjR~
//  	            return errinvalid(pc);                         //~v0jjR~
				if (posw>=Gscrwidth)                               //~v0jjI~
					posw=Gscrwidth-1;                              //~v0jjI~
    			if (posw<0)                                        //~v0jjI~
                    posw=0;                                        //~v0jjI~
                pos[1]=posw;                                       //~v0j2I~
            }                                                      //~v0j2I~
        }                                                          //~v0j2I~
	}//loop by operand no                                          //~v0j2I~
	Gcsrposy=pos[0];                                               //~v0j2I~
	Gcsrposx=pos[1];                                               //~v0j2I~
//  scrdisp();      //active screen chnge chk                      //~v0jrR~
	return 0;                                                      //~v0j2I~
}//func_pos_pan                                                    //~v0j2I~
