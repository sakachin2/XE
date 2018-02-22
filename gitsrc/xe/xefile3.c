//*CID://+vbi3R~:                             update#=  151;       //~vbi3R~
//*************************************************************
//*xefile3.c*
//* execute key                                                 //~4C23R~
//* pgup/pgdn/pgleft/pgright/linetop/lineend/scroll 1line up/down//~5111R~
//* filetop/fileend                                             //~4C23I~
//*************************************************************
//vbi3:180211 supprt command history list                          //~vbi3I~
//vazp:150113 (BUG)scroll-right MAX crash when maxline<scrwidth    //~vazpI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3R:100322 (BUG)csr down at new dbcs by del key at EOL if GSCRSCSRDOWN ON//~va3RI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file3.c :jump csr between hex and char               //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v777:071204*EUC hankana chk(2byte but 1 column) hankana input not avail on rh9 but on fc5//~v777I~
//v773:071121*Ctrl+Tab for function that cursor jump between char and ehx part//~v773I~
//v76J:070907*(BUG)lineend-file abend by access EOL position       //~v76JI~
//v76B:070822*(BUG)line end move csr to dbcs 2nd formargined file  //~v76BI~
//v73n:070117 (BUG)hexmode edit cursor DEL on hex part should back 1 col if data is longer than width//~v73nI~
//v71v:061022 not fixed(PAGE) scroll type for =0.1/2/3             //~v71vI~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v698:060427 (BUG)scrolling dose not occur when hex 3line mode.   //~v698I~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v60i:050129 jump to next/prev line when csr is on non-data line of filearea//~v60iI~
//v56n:040405 keep cursor pos if not in the file area when pgup/pgdn/pgleft/pgright//~v56nI~
//v55C:040307 (WXE:BUG)pgright for spf file;set minus to UFCleft when screen is too wide//~v55CI~
//v55r:040228 (BUG)csr jump to home by pgup/pgdn when display line=1//~v55qI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v53K:031027 move csr to lineno-fld when csr is already tol       //~v53KI~
//v517:030412 keep csrpos when csr is on lineno field for pgleft/pgright key//~v517I~
//v446:011201 default cols data for hex edit                       //~v446I~
//v442:011201 skip csr over hex intermidiate space                 //~v442I~
//v440:011125 browse hex                                           //~v440I~
//v428:010923 (BUG)lineend:stop at margin top when curpos is on margin-1//~v428I~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v11Q:990904 keep csr pos when csr is on cols line for pgright/left//~v11QI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ek:970915 file_lineend;for cid on out of mergin file,stop once at mergin//~v0ekI~
//v0e4:970914 (BUG)endofline stop at col0 when all space line of no mergin file//~v0e4I~
//v0e1:970914 (BUG)pgright;err if scrollsz>lrecl for mergined file //~v0e1I~
//v0dv:970914 spf scroll for find/change cmd                       //~v0d7I~
//v0d7:970831 csr wrap(not pageshift) for 80 byte spf file         //~v0d7I~
//v0cz:970818 null cid //+NONE~R                                   //~v0czI~
//v0cy:970818 csr to end of mergin at once for mergin file by lineend key//~v0cyI~
//v0cx:970818 pgright max up to lrecl for spf file                 //~v0cxI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0b1:970723 (BUG)csr remain when pgright/pgleft                  //~v0b1I~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//v0an:970713 (BUG)if split line has tab,ULHlen over MAXLINEDATA.  //~v0anR~
//                 So lineend csr pos is invalid.And right-scroll  //~v0anI~
//                 is limmited by MAXLINEDATA.                     //~v0anR~
//                 Use MAXLINEDATA limit for a pg-right key.       //~v0anI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06c:960224:line end scroll displaying to first half                //~v06cI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v05A:951224:(BUG)ignored edit xe.ini(always written at term by storage//~v05AI~
//            value which is read at init).                     //~v05AI~
//            temporary set GPROCSINIUPDATE only when changed(v03n)//~v05AI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v03n:950819:initial scroll option from xe.ini                //~v03nI~
//*v033:950715:SCROLL cmd for dir list scroll                   //~v030I~
//*v030:950709:dir pgup/pgdn/filetop/fileend/lineup/linedown share with file//~v030I~
//*           :no csr move to hdr line                          //~v030I~
//*           :csr to lineno fld for dir(line up/down)          //~v030I~
//*v013 950624 find scroll size(export calc half scroll size func)//~v013R~
//************************************************************* //~5624I~
//950727 scroll max                                             //~5527I~
//950504 allow 1 line down/up when csr is on the cmd line       //~5505I~
//950204 scroll CSR                                             //~5204R~
//941219 no set change id for literal continue                  //~5204I~
//941219 scroll size cmd input                                  //~4C19I~
//941209 exec by Enter(CR) key                                  //~4C19I~
//941208 exec cmd also when range pending
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
    #ifdef OS2                                                     //~v69mI~
  		#define INCL_BASE                                          //~v69mI~
  		#include <os2.h>                                           //~v69mI~
	#endif                                                         //~v69mI~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <uparse.h>                                                //~v0b2R~
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                              //~v03nI~
#include <ustring.h>                                               //~v0czI~
#include <ukbd.h>                                                  //~v69mR~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~v773I~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
#include <utrace.h>                                                //~vazpI~
                                                                //~4C19I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile13.h"                                              //~v55CI~
#include "xefile2.h"
#include "xefile22.h"                                              //~v440I~
#include "xefile3.h"
#include "xefile4.h"                                            //~5130I~
#include "xelcmd.h"
#include "xefunc.h"
#include "xepan.h"                                              //~5318I~
#include "xefsub.h"                                             //~5318R~
#include "xesub.h"                                              //~5318I~
#include "xeopt.h"                                                 //~va3TI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
#include "xefcmd22.h"                                              //~v698I~
#include "xeerr.h"                                                 //~v773I~
#ifdef WXE                                                         //~v69mI~
	#include "wxexei.h"                                            //~v69mI~
#else                                                              //~v69mI~
	#ifdef XXE                                                     //~v69mI~
		#include "xxexei.h"                                        //~v69mI~
	#else                                                          //~v69mI~
		#ifdef LNX		//console version                          //~v69mI~
			#include "xemousel.h"                                  //~v69mI~
        #endif                                                     //~v69mI~
    #endif                                                         //~v69mI~
#endif                                                             //~v69mI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
//*******************************************************
#define MAXSCROLLID   4                                         //~v03nI~
static UCHAR *Sscrollid[MAXSCROLLID]={"PAGE","HALF","CSR","MAX"};//~v03nI~
static int Shalfbacksw=0;                                          //~v55qI~
//*******************************************************
int getscrollsz(PUCLIENTWE Ppcw,int Popt,int Pdest);            //~5204R~
int filepgdown(PUCLIENTWE Ppcw,int Pline);                      //~5423I~
int filepgright(PUCLIENTWE Ppcw,int Pscrollsz);                 //~5423I~
int filevhexstepline(PUCLIENTWE Ppcw,PUFILEC Ppfc,int Pstep);      //~v60vR~
//****************************************************************
// exec key for file panel
//*rc   :0
//****************************************************************
int func_exec_file(PUCLIENTWE Ppcw)
{
	PUFILEC  pfc;
	PUFILEH  pfh;
	int rc;
//****************************
//**scroll chk                                                  //~5527M~
	if (rc=filescrollchk(Ppcw),rc)                              //~5527M~
		return rc;                                              //~5527M~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
    UPCTRREQ(pfh);                                              //~5527I~
	UTRACEP("@@@1 %s:cmdlinectr=%d\n",UTT,pfh->UFHcmdlinectr);     //~vazpI~
	if (pfh->UFHcmdlinectr 			//cmd line exist            //~v03uR~
	&&  (!UCBITCHK(pfh->UFHflag2,UFHF2LCMDCOMP) || pfh->UFHpendctr))//~v03uR~
		if (rc=filelinecmd(Ppcw),rc<4)	//pending               //~5527R~
        	rc=0;						//no beep               //~5527I~
    UPCTRREQ(pfh);                                              //~5527I~
	return rc;                                                  //~5527R~
}//func_exec_file
//**********************************************************       //~v55qI~
//* page scrool                                                    //~v55qI~
//**********************************************************       //~v55qI~
//*page up **                                                      //~v55qI~
int filepguphalf(PUCLIENTWE Ppcw)                                  //~v55qI~
{                                                                  //~v55qI~
	int 	rc;                                                    //~v55qI~
//****************:                                                //~v55qI~
    Shalfbacksw=1;                                                 //~v55qI~
	rc=func_pgup_file(Ppcw);                                       //~v55qR~
    Shalfbacksw=0;                                                 //~v55qI~
    return rc;                                                     //~v55qI~
}//filepguphalf(PUCLIENTWE Ppcw)                                   //~v55qI~
//**********************************************************
//* page scrool 
//**********************************************************
//*page up **
int func_pgup_file(PUCLIENTWE Ppcw)
{
	int 	line,rc,step;                                       //~5204R~
	int 	stepvhex;                                              //~v60vI~
	PULINEH plh,plht;
	PUFILEH pfh;                                                //~5204R~
	PUFILEC pfc;
//****************:	
	if (rc=filescrollchk(Ppcw),rc)
		return rc;
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	plht=UGETQTOP(&pfh->UFHlineque);
	plh=(PULINEH)pfc->UFCcurtop;
  if (Shalfbacksw)                                                 //~v55qI~
	line=filehalfvscrollsz(Ppcw);                                  //~v55qI~
  else                                                             //~v55qI~
	line=getscrollsz(Ppcw,0,-1);	//0:virtical,-1:backward    //~5204R~
    if (line==-1)   //max                                       //~5527I~
		return func_filetop_file(Ppcw);                         //~5527I~
                                                                //~5527I~
	if (!(plh=getdisplayline(plh,-line,&step)))                 //~5204R~
		plh=plht;                                               //~5204I~
	if (plh==pfc->UFCcurtop)			//can not advanced      //~5204I~
		return 4;                                               //~5204I~
//*csr set
//  if (Ppcw->UCWrcsry>CMDLINENO                                   //~v11NR~
//  &&  Ppcw->UCWrcsry<Ppcw->UCWmaxline                            //~v11NR~
//    if (CSRONFILELINE(Ppcw)                                      //~v56nR~
////  &&  Ppcw->UCWrcsry+line<Ppcw->UCWheight)                     //~v56nR~
//    &&  Ppcw->UCWrcsry+line<=Ppcw->UCWheight)                    //~v56nR~
  if (CSRONFILELINE(Ppcw))                                         //~v56nI~
  {                                                                //~v56nI~
   if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                          //~v60vI~
   {                                                               //~v60vI~
   	stepvhex=filevhexstepline(Ppcw,pfc,-line);	//conv plh count to line count//~v60vI~
    if (Ppcw->UCWrcsry+stepvhex<=Ppcw->UCWheight)                  //~v60vI~
	{                                                              //~v60vI~
		Ppcw->UCWrcsry+=stepvhex;                                  //~v60vI~
    	if (Ppcw->UCWrcsry>=Ppcw->UCWheight)                       //~v60vI~
    		Ppcw->UCWrcsry=Ppcw->UCWheight-1;                      //~v60vI~
		csrloctogbl(Ppcw);  	//convert local to gbl csrpos      //~v60vI~
	}                                                              //~v60vI~
	else                                                           //~v60vI~
		csrhomepos(0);		//to cmd line                          //~v60vI~
   }                                                               //~v60vI~
   else                                                            //~v60vI~
   {                                                               //~v60vI~
    if (Ppcw->UCWrcsry+line<=Ppcw->UCWheight)                      //~v56nI~
	{
		Ppcw->UCWrcsry+=step;	//csr set to data fld           //~5204R~
    	if (Ppcw->UCWrcsry>=Ppcw->UCWheight)                       //~v55qI~
    		Ppcw->UCWrcsry=Ppcw->UCWheight-1;                      //~v55qI~
		csrloctogbl(Ppcw);  	//convert local to gbl csrpos   //~4C25R~
	}
	else
		csrhomepos(0);		//to cmd line 
   }//not vhex mode                                                //~v60vI~
  }                                                                //~v56nI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);
	pfc->UFCcurtop=plh;
	return 0;
}//pgup
                                                                //~4C23I~
//*page down ************************************************** //~5423I~
int func_pgdown_file(PUCLIENTWE Ppcw)                           //~5423I~
{                                                               //~5423I~
	int 	line,rc;                                            //~5423I~
//****************:	                                            //~5423I~
	if (rc=filescrollchk(Ppcw),rc)                              //~5423I~
		return rc;                                              //~5423I~
	line=getscrollsz(Ppcw,0,1);	//0:virtical,1:forward          //~5423I~
    if (line==-1)   //max                                       //~5527I~
		return func_fileend_file(Ppcw);                         //~5527I~
                                                                //~5527I~
	return filepgdown(Ppcw,line);                               //~5423I~
}//func_pgdown_file                                             //~5423I~
                                                                //~5423I~
int filepgdownhalf(PUCLIENTWE Ppcw)                             //~5423I~
{                                                               //~5423I~
	int 	line;                                               //~5423R~
//****************:	                                            //~5423I~
	line=filehalfvscrollsz(Ppcw);                               //~v013R~
    return filepgdown(Ppcw,line);                               //~5423I~
}//filepgdownhalf                                               //~5423I~
                                                                //~5423I~
//*page down ************************************************** //~4C23R~
int filepgdown(PUCLIENTWE Ppcw,int Pline)                       //~5423R~
{                                                               //~5204R~
	int 	step;                                               //~5423R~
	int 	stepvhex;                                              //~v60vI~
	PULINEH plh,plhe;
	PUFILEC pfc;
	PUFILEH pfh;                                                //~5204R~
//****************:	
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	plhe=UGETQEND(&pfh->UFHlineque);
	plh=(PULINEH)pfc->UFCcurtop;
	if (!(plh=getdisplayline(plh,Pline,&step)))                 //~5423R~
		plh=plhe;                                               //~5204I~
	if (plh==pfc->UFCcurtop)			//can not advanced      //~5204I~
		return 4;                                               //~5204I~
//*csr set
//  if (Ppcw->UCWrcsry>CMDLINENO                                   //~v11NR~
//  &&  Ppcw->UCWrcsry<Ppcw->UCWmaxline                            //~v11NR~
//  &&  Ppcw->UCWrcsry-Pline>CMDLINENO)                            //~v11NI~
//    if (CSRONFILELINE(Ppcw)                                      //~v56nR~
////  &&  Ppcw->UCWrcsry-Pline>=Ppcw->UCWfilehdrlineno)            //~v56nR~
//    &&  Ppcw->UCWrcsry+1-Pline>=Ppcw->UCWfilehdrlineno)          //~v56nR~
  if (CSRONFILELINE(Ppcw))                                         //~v56nI~
  {                                                                //~v56nI~
   if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                          //~v60vI~
   {                                                               //~v60vI~
   	stepvhex=filevhexstepline(Ppcw,pfc,Pline);	//conv plh count to line count//~v60vI~
    if (Ppcw->UCWrcsry+1-stepvhex>=Ppcw->UCWfilehdrlineno)         //~v60vI~
	{                                                              //~v60vI~
		Ppcw->UCWrcsry-=stepvhex;	//csr set to data fld          //~v60vI~
        if (Ppcw->UCWrcsry<Ppcw->UCWfilehdrlineno)	//csr set to data fld//~v60vI~
        	Ppcw->UCWrcsry=Ppcw->UCWfilehdrlineno;	//csr set to data fld//~v60vI~
		csrloctogbl(Ppcw);  	//convert local to gbl csrpos      //~v60vI~
	}                                                              //~v60vI~
	else                                                           //~v60vI~
		csrhomepos(0);		//to cmd line                          //~v60vI~
   }                                                               //~v60vI~
   else                                                            //~v60vI~
   {                                                               //~v60vI~
    if (Ppcw->UCWrcsry+1-Pline>=Ppcw->UCWfilehdrlineno)            //~v56nI~
	{
		Ppcw->UCWrcsry-=step;	//csr set to data fld           //~5204R~
        if (Ppcw->UCWrcsry<Ppcw->UCWfilehdrlineno)	//csr set to data fld//~v55qR~
        	Ppcw->UCWrcsry=Ppcw->UCWfilehdrlineno;	//csr set to data fld//~v55qR~
		csrloctogbl(Ppcw);  	//convert local to gbl csrpos   //~4C25I~
	}
	else
		csrhomepos(0);		//to cmd line 
   }//not vhex mode                                                //~v60vI~
  }                                                                //~v56nI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);
	pfc->UFCcurtop=plh;
	return 0;
}//filepgdown                                                      //~v60vR~
                                                                //~4C23I~
//*page left *************************************************  //~4C23R~
//**********************************************************       //~v55qI~
//* page scrool left half                                          //~v55qI~
//**********************************************************       //~v55qI~
//*page up **                                                      //~v55qI~
int filepglefthalf(PUCLIENTWE Ppcw)                                //~v55qI~
{                                                                  //~v55qI~
	int 	rc;                                                    //~v55qI~
//****************:                                                //~v55qI~
    Shalfbacksw=1;                                                 //~v55qI~
	rc=func_pgleft_file(Ppcw);                                     //~v55qR~
    Shalfbacksw=0;                                                 //~v55qI~
    return rc;                                                     //~v55qI~
}//filepglefthalf(PUCLIENTWE Ppcw)                                 //~v55qI~
int func_pgleft_file(PUCLIENTWE Ppcw)
{
	int scrollsz,rc,step;                                       //~4C19R~
	PUFILEC pfc;
//****************:	
	if (rc=filescrollchk(Ppcw),rc)
		return rc;
	pfc=Ppcw->UCWpfc;
  if (Shalfbacksw)                                                 //~v55qI~
	scrollsz=filehalfhscrollsz(Ppcw);                              //~v55qI~
  else                                                             //~v55qI~
  {                                                                //~v55qI~
	if (!(scrollsz=getscrollsz(Ppcw,1,-1)))	//1:horizontal,-1:backward//~5204R~
		return 4;
  }                                                                //~v55qI~
    if (scrollsz==-1)   //max                                   //~5527R~
    {                                                           //~5527I~
		if (pfc->UFCleft)                                       //~5527I~
		{                                                       //~5527I~
			pfc->UFCleft=0;                                     //~5527I~
			UCBITON(Ppcw->UCWflag,UCWFDRAW);                    //~5527I~
            rc=0;                                               //~5527R~
		}                                                       //~5527I~
        else                                                    //~5527I~
            rc=4;       //already max                           //~5527I~
		csrhomepos(0);		//to cmd line                       //~5527I~
        return rc;                                              //~5527I~
	}//max                                                      //~5527R~
                                                                //~5527I~
	if (!pfc->UFCleft)	//left most                             //~5527M~
		return 4;                                               //~5527M~
                                                                //~5527I~
	step=min(pfc->UFCleft,scrollsz);//1:horizontal              //~4C19R~
	pfc->UFCleft-=step;                                         //~4C19I~
//  if (Ppcw->UCWrcsrx>=Ppcw->UCWlinenosz     //on the field       //~v11NR~
//  &&  Ppcw->UCWrcsry<Ppcw->UCWmaxline                            //~v11NR~
//  &&  Ppcw->UCWrcsry>CMDLINENO)                                  //~v11NR~
//  if (CSRONFILEDATA(Ppcw))                                       //~v11QR~
    if (CSRONFILEDATA_COLS(Ppcw))                                  //~v11QI~
    {                                                              //~v56nI~
//  	if (Ppcw->UCWrcsrx+step<Ppcw->UCWwidth)                    //~v55qR~
    	if (Ppcw->UCWrcsrx+step<=Ppcw->UCWwidth)                   //~v55qI~
		{                                                       //~4C23R~
			Ppcw->UCWrcsrx+=step;                               //~4C23R~
    		if (Ppcw->UCWrcsrx>=Ppcw->UCWwidth)                    //~v55qI~
    			Ppcw->UCWrcsrx=Ppcw->UCWwidth-1;                   //~v55qI~
			csrloctogbl(Ppcw);  	//convert local to gbl csrpos//~4C25I~
		}                                                       //~4C23R~
		else                                                    //~4C23R~
			csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);	//to linenofld//~5223R~
//  else                                                           //~v56nR~
//    if (!CSRONFILELINE_COLS(Ppcw)) //not on linenosz fld         //~v56nR~
//  	csrhomepos(0);		//to cmd line                          //~v56nR~
    }                                                              //~v56nI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);
	return 0;
}//file_pgleft_file
                                                                //~5423I~
//*page right ************************************************* //~5423I~
int func_pgright_file(PUCLIENTWE Ppcw)                          //~5423I~
{                                                               //~5423I~
	int scrollsz,rc,ii,maxright;                                //~5527R~
    PULINEH plh;                                                //~5527I~
	PUFILEC pfc;                                                //~5527I~
	PUFILEH pfh;                                                   //~v0cxI~
//****************:	                                            //~5423I~
	if (rc=filescrollchk(Ppcw),rc)                              //~5423I~
		return rc;                                              //~5423I~
	if (!(scrollsz=getscrollsz(Ppcw,1,1)))	//1:horizontal,1:forward//~5423I~
		return 4;								//no data space //~5423I~
    if (scrollsz==-1)   //max                                   //~5527I~
    {                                                           //~5527I~
		pfc=Ppcw->UCWpfc;                                       //~5527R~
		pfh=pfc->UFCpfh;                                           //~v0cxI~
       	maxright=0;                                             //~5527R~
//      ii=Ppcw->UCWmaxline-FILEHDRLINENO;                         //~v11NR~
        ii=Ppcw->UCWmaxline-Ppcw->UCWfilehdrlineno;                //~v11NI~
		for (plh=pfc->UFCcurtop;plh;plh=UGETQNEXT(plh))         //~5527R~
		{                                                       //~5527R~
			if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))          //~5527R~
           		continue;                                       //~5527R~
           	ii--;                                               //~5527R~
            if (ii<0)                                           //~5527I~
            	break;                                          //~5527I~
			if (plh->ULHtype==ULHTDATA)                         //~5527R~
           		if (maxright<plh->ULHlen)                       //~5527R~
	           		maxright=plh->ULHlen;                       //~5527R~
		}                                                       //~5527R~
       	if (maxright)                                           //~5527R~
       	{                                                       //~5527R~
           	maxright=maxright-Ppcw->UCWwidth+Ppcw->UCWlinenosz+1;//~v069R~
	    	if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))             //~v0cxI~
            	maxright--;		//no last crlf                     //~v0cxI~
            if (maxright<0)                                        //~vazpI~
                maxright=0;                                        //~vazpI~
			if (maxright==pfc->UFCleft)                         //~5527R~
               	rc=4;	//no movement                           //~5527R~
            else                                                //~5527R~
            {                                                   //~5527R~
				pfc->UFCleft=maxright;                          //~5527R~
				UCBITON(Ppcw->UCWflag,UCWFDRAW);                //~5527R~
               	rc=0;                                           //~5527R~
            }                                                   //~5527R~
	    }                                                       //~5527R~
        else                                                    //~5527R~
           	rc=4;	//no data line                              //~5527R~
		csrhomepos(0);		//to cmd line                       //~5527I~
        return rc;                                              //~5527I~
	}//max                                                      //~5527I~
    return filepgright(Ppcw,scrollsz);                          //~5423I~
}//func_pgright_file                                            //~5423I~
                                                                //~4C23I~
//*************************************************************    //~v0d7I~
//*page right half ********************************************    //~v0d7R~
//*parm:pcw                                                        //~v0d7I~
//*retrn:rc                                                        //~v0d7I~
//*************************************************************    //~v0d7I~
int filepgrighthalf(PUCLIENTWE Ppcw)                            //~5423I~
{                                                               //~5423I~
	int scrollsz;                                               //~5423I~
//****************:	                                            //~5423I~
	scrollsz=filehalfhscrollsz(Ppcw);                           //~v013R~
    return filepgright(Ppcw,scrollsz);                          //~5423I~
}//func_pgright_file                                            //~5423I~
                                                                //~5423I~
//*page right *************************************************    //~v0d7I~
int filepgright(PUCLIENTWE Ppcw,int Pscrollsz)                  //~5423R~
{
	int 	step;                                                  //~v0anR~
  	int 	maxleft=0;                                               //~v0cxR~//~vaf9R~
	int rc=0;                                                      //~v0anI~
    int linenosz;                                               //~v069I~
    int lrecl;                                                     //~v0avR~
    int spfsw;                                                     //~v0cxI~
    int prevleft;                                                  //~v55CI~
	PUFILEC pfc;
	PUFILEH pfh;                                                   //~v0avR~
//****************:	
	pfc=Ppcw->UCWpfc;                                              //~v0avR~
	pfh=pfc->UFCpfh;                                               //~v0avR~
	linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
    lrecl=pfh->UFHlrecl;                                           //~v0avR~
//  maxleft=MAXLINEDATA-(Ppcw->UCWwidth-linenosz)+1;//for crlf     //~v0anR~
    spfsw=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK);                   //~v0cxI~
    if (spfsw)                                                     //~v0cxI~
    {                                                              //~v55CI~
        prevleft=pfc->UFCleft;				//save for fileinitialleft//~v55CI~
		fileinitialleft(pfc,pfh);       //get initial left cobol in ufcleft//~v55CI~
		maxleft=lrecl-(Ppcw->UCWwidth-linenosz);                   //~v0cxI~
        if (maxleft<pfc->UFCleft)                                  //~v55CI~
        	maxleft=pfc->UFCleft;                                  //~v55CI~
        pfc->UFCleft=prevleft;                                     //~v55CI~
    }                                                              //~v55CI~
    if (Pscrollsz>MAXLINEDATA)	//max size by a scroll key         //~v0e1R~
//  if (Pscrollsz>lrecl)	//max size by a scroll key             //~v0e1R~
    {	                                                           //~v0anI~
    	rc=4;                                                      //~v0anI~
    	Pscrollsz=MAXLINEDATA;                                     //~v0e1R~
//  	Pscrollsz=lrecl;                                           //~v0e1R~
    }                                                              //~v0anI~
//  if (pfc->UFCleft==maxleft)		//already rightmost            //~v0anR~
//  	return 4;                                                  //~v0anR~
  	if (spfsw)                                                     //~v0cxI~
//		if (pfc->UFCleft==maxleft)		//already rightmost        //~v55CR~
  		if (pfc->UFCleft>=maxleft)		//already rightmost        //~v55CI~
  			return 4;                                              //~v0cxI~
	step=-pfc->UFCleft;                                         //~4C19I~
//  pfc->UFCleft=min(pfc->UFCleft+Pscrollsz,maxleft);              //~v0anR~
  if (spfsw)                                                       //~v0cxI~
	pfc->UFCleft=min(pfc->UFCleft+Pscrollsz,maxleft);              //~v0cxI~
  else                                                             //~v0cxI~
    pfc->UFCleft=pfc->UFCleft+Pscrollsz;                           //~v0anI~
	step+=pfc->UFCleft;			//advaced size new-old          //~5104R~
//  if (Ppcw->UCWrcsrx>=linenosz //on the field                    //~v11NR~
//  &&  Ppcw->UCWrcsry<Ppcw->UCWmaxline                            //~v11NR~
//  &&  Ppcw->UCWrcsry>CMDLINENO)                                  //~v11NR~
//  if (CSRONFILEDATA(Ppcw))                                       //~v11QR~
    if (CSRONFILEDATA_COLS(Ppcw))                                  //~v11QI~
    {                                                              //~v56nI~
//  	if (Ppcw->UCWrcsrx-step>=linenosz)                         //~v55qR~
    	if (Ppcw->UCWrcsrx+1-step>=linenosz)                       //~v55qI~
		{                                                       //~4C23R~
			Ppcw->UCWrcsrx-=step;                               //~4C23R~
    		if (Ppcw->UCWrcsrx<linenosz)                           //~v55qR~
    			Ppcw->UCWrcsrx=linenosz;                           //~v55qR~
			csrloctogbl(Ppcw);  	//convert local to gbl csrpos//~4C25I~
		}                                                       //~4C23R~
		else                                                    //~4C23R~
			csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);	//to linenofld//~5223R~
//  else                                                           //~v56nR~
//    if (!CSRONFILELINE_COLS(Ppcw)) //not on linenosz fld         //~v56nR~
//  	csrhomepos(0);		//to cmd line                          //~v56nR~
    }                                                              //~v56nI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);
//	return 0;                                                      //~v0anR~
  	return rc;                                                     //~v0anI~
}//filepgright                                                  //~5423R~
                                                                //~4C23I~
//*line top ************************************************    //~4C23I~
int func_linetop_file(PUCLIENTWE Ppcw)                          //~4C23I~
{                                                               //~4C23I~
	PUFILEC pfc;                                                //~5527M~
//****************:	                                            //~4C23I~
	if (Ppcw->UCWrcsry<=CMDLINENO)                              //~5103R~
		return func_linetop_pan(Ppcw);                          //~4C23I~
	pfc=Ppcw->UCWpfc;                                           //~5527M~
  if (Ppcw->UCWfilehdrlineno==FILEHDRLINENO		//no cols exist    //~v11NI~
  ||  Ppcw->UCWrcsry>FILEHDRLINENO)	            //not on cols line //~v11NI~
	if (!(((PUSCRD)(Ppcw->UCWpsd)+Ppcw->UCWrcsry)->USDbuffc))   //~5527M~
//  	return 4;                                                  //~v60iR~
    	return func_prevtab_file(Ppcw);                            //~v60iI~
// 	if (!getscrollsz(Ppcw,1,-1))//right/left scrollsz,-1:backward  //~v11NR~
//  	return 4;                                                  //~v11NR~
	if (pfc->UFCleft)                                           //~5527M~
	{                                                           //~5527M~
		pfc->UFCleft=0;                                         //~5527M~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                        //~5527M~
	}                                                           //~5527M~
    else                                                           //~v53KI~
  		if (Ppcw->UCWrcsrx==Ppcw->UCWlinenosz                      //~v53KR~
  		&&  Ppcw->UCWrcsrx) //already top and lineno fld exist     //~v53KR~
			return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//top of linenofld//~v53KI~
	return csronthefld(Ppcw,Ppcw->UCWrcsry,1,0);//top of client fld//~5527M~
}//func_linetop_file                                            //~5527R~
                                                                //~4C23I~
//*line end ************************************************    //~4C23I~
int func_lineend_file(PUCLIENTWE Ppcw)                          //~4C23I~
{                                                               //~4C23I~
	int col,scrollsz,lrecl;                                        //~v0anR~
    int spflrecl;                                                  //~v0czI~
    int colc,mergin;                                               //~v0cyR~
    int colw;                                                      //~v0ekI~
    int spfsw;                                                     //~v0cyI~
    int maxleft=0;                                                   //~v0cyR~//~vaf9R~
    int linenosz;                                               //~v069I~
    int hextop,hexend;                                             //~v440I~
	PULINEH plh;                                                //~4C23I~
	PUFILEH pfh;                                                //~5225R~
	PUFILEC pfc;                                                //~5225I~
    int merginsw;                                                  //~v0ekI~
#ifdef UTF8UCS2                                                    //~va20I~
	PUSCRD  psd;                                                   //~va20I~
    int coldata=0,swutf8file;                                        //~va20R~//~vaf9R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//  int	rspn;                                                      //~v0czR~
//****************:	                                            //~4C23I~
	if (Ppcw->UCWrcsry<=CMDLINENO)                              //~5103R~
		return func_lineend_pan(Ppcw);                          //~4C23I~
                                                                //~4C23I~
	linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
    if (Ppcw->UCWwidth<=linenosz)   //no display wodth                //~v06cI~
		return 4;                                                     //~v06cI~
                                                                      //~v06cI~
	pfc=Ppcw->UCWpfc;                                           //~4C23I~
	if (!(plh=((PUSCRD)(Ppcw->UCWpsd)+Ppcw->UCWrcsry)->USDbuffc))//~4C24R~
    {                                                              //~v60iI~
//  	return 4;        //gauge or after EndOfFile                //~v60iR~
  		if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO	//cols exist   //~v60iI~
  		&&  Ppcw->UCWrcsry==FILEHDRLINENO)	        //on cols line //~v60iI~
        {                                                          //~v60vI~
            if (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz)	//same as linetop//~v60iI~
                return csronthefld(Ppcw,Ppcw->UCWrcsry,1,0);//top of linenofld//~v60iI~
            else                                                   //~v60iI~
                return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//top of linenofld//~v60iI~
        }                                                          //~v60vI~
    	return func_nexttab_file(Ppcw);                            //~v60iI~
    }                                                              //~v60iI~
    if (plh->ULHtype!=ULHTDATA)                                 //~5103I~
    {                                                              //~v60iI~
//  	return 4;                                                  //~v60iR~
  		if (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz)                      //~v60iI~
			return csronthefld(Ppcw,Ppcw->UCWrcsry,1,0);//top of linenofld//~v60iI~
        else                                                       //~v60iI~
			return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//top of linenofld//~v60iI~
    }                                                              //~v60iI~
	col=plh->ULHlen;                                            //~5130I~
    pfh=pfc->UFCpfh;                                            //~5225R~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~v0cyI~
    spfsw=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK);	//spf file     //~v0cyI~
    spflrecl=pfh->UFHlrecl;                                        //~v0czI~
 	colc=pfc->UFCleft+max(Ppcw->UCWrcsrx-linenosz,0); //recoff     //~v0cyI~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //binary file             //~v440I~
  {                                                                //~v440I~
  		if (UCBITCHK(pfh->UFHflag5,UFHF5HEX)) //hex mode           //~v440R~
            if (colc>=col) //csr on right of lrecl                 //~v440R~
            {                                                      //~v440I~
				filegethposrange(pfh,col,&hextop,&hexend);         //~v446R~
                col=hexend;                                        //~v440R~
            }                                                      //~v440I~
  }                                                                //~v440I~
  else      //text file                                            //~v440I~
  {                                                                //~v440I~
    mergin=pfh->UFHmergin;                                         //~v0czI~
	merginsw=UCBITCHK(pfh->UFHflag2,UFHF2MERGIN);    //mergin file //~v0ekI~
//    if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN))    //mergin file    //~v0czR~
//    {                                                            //~v0czR~
//        mergin=pfh->UFHmergin;                                   //~v0czR~
//        if (colc<mergin-1)  //in mergin                          //~v0czR~
//        {                                                        //~v0czR~
//            if (col>=mergin)                                     //~v0czR~
//            {                                                    //~v0czR~
//              rspn=(int)umemrspnc(plh->ULHdata,' ',(UINT)mergin);//~v0czR~
//              if (rspn)                                          //~v0czR~
//                col=mergin-rspn;                                 //~v0czR~
//              else                                               //~v0czR~
//                col=mergin-1;                                    //~v0czR~
//            }                                                    //~v0czR~
//        }                                                        //~v0czR~
//        else                                                     //~v0czR~
//            if (spfsw)                                           //~v0czR~
//                col--;          //end of record -1               //~v0czR~
//    }                                                            //~v0czR~
                                                                   //~v0cyI~
//    if (*(pfh->UFHcid))//have cid                                //~v0czR~
//    {                                                            //~v0czR~
//  	col=pfc->UFCleft+max(Ppcw->UCWrcsrx-linenosz,0); //recoff  //~v0cyR~
//        lrecl=filecidlrecl(plh,pfh);    //lrecl except cid       //~v0czR~
        lrecl=filecidlrecl3(plh,pfh);    //lrecl except cid,trailing space//~v0czI~
// 		if (col<lrecl)                                             //~v0cyR~
   		if (colc<lrecl)                                            //~v0cyI~
        {                                                          //~v0ekI~
//  		if (lrecl>=mergin && colc<mergin-1)                    //~v428R~
    		if (lrecl>=mergin)                                     //~v428I~
            {                                                      //~v428I~
    		if (colc<mergin-1)                                     //~v428I~
            {                                                      //~v0ekI~
            	col=mergin-1;                                      //~v0ekI~
				if (merginsw && pfh->UFHcidpos>=mergin)    //oom file//~v0ekI~
                {                                                  //~v0ekI~
//*for the case lrecl is on margin because CID on margin is invalid//~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            		colw=mergin-(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,mergin);//~va50I~
	#else                                                          //~va50I~
            		colw=mergin-(int)UTF_umemrspnc(swutf8file,plh->ULHdata,plh->ULHdbcs,' ',mergin);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            		colw=mergin-(int)umemrspnc(plh->ULHdata,' ',(UINT)mergin);//~v0ekR~
#endif                                                             //~va20I~
                    if (colc<colw)                                 //~v0ekI~
                    	col=colw;                                  //~v0ekR~
                }                                                  //~v0ekI~
            }                                                      //~v0ekI~
            }                                                      //~v428I~
            else                                                   //~v0ekI~
			col=lrecl;                                          //~5130I~
        }                                                          //~v0ekI~
//      else                                                       //~v0cyR~
//  		col=plh->ULHlen;                                       //~v0cyR~
        else                                                       //~v0czI~
			if (merginsw)    //mergin file                         //~v0ekR~
            {                                                      //~v0czI~
                if (col>=mergin)                                   //~v0czI~
                {                                                  //~v0czI~
            		if (colc<mergin-1)                             //~v0czR~
                		col=mergin-1;                              //~v0czR~
					else                                           //~v0czI~
                    	if (spfsw && col==spflrecl)                //~v0czR~
                        	col--;	//not crlf                     //~v0czI~
				}                                                  //~v0czI~
            }                                                      //~v0czI~
//          else                                                   //~v0e4R~
//  			col=lrecl;                                         //~v0e4R~
//    }                                                            //~v0czR~
//  if (plh->ULHdbcs && *(plh->ULHdbcs+col)==DBCS2NDCHAR)          //~v76JR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    if (plh->ULHdbcs && col<plh->ULHlen && UDBCSCHK_DBCSNOT1ST(*(plh->ULHdbcs+col)))	// pad or 2nd//~va1cR~
        col+=XESUB_DBCSSPLITCTR_R(plh->ULHdbcs+col,plh->ULHlen-col);//~va1cR~
#else                                                              //~va1cR~
    if (plh->ULHdbcs && col<plh->ULHlen && *(plh->ULHdbcs+col)==DBCS2NDCHAR)//~v76JR~
        col++;                                                     //~v76BI~
#endif                                                             //~va1cR~
  }//text file                                                     //~v440I~
#ifdef UTF8UCS2                                                    //~va20I~
	psd=(PUSCRD)(Ppcw->UCWpsd)+Ppcw->UCWrcsry;                     //~va20I~
    if (FILEUTF8MODE(pfh) && UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2)))	//vhexline//~va20I~
    {                                                              //~va20I~
    	coldata=col;	//column on data line                      //~va20I~
    	col=PLHPOS2OFFS(0,plh,col)-PLHPOS2OFFS(0,plh,pfc->UFCleft)+pfc->UFCleft;//on vhex line//~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
	if (col>=pfc->UFCleft                                       //~4C23I~
	&&  col-pfc->UFCleft<Ppcw->UCWwidth-linenosz)	//in curr window//~v069R~
		Ppcw->UCWrcsrx=col-pfc->UFCleft+linenosz;	//only move csr//~v069R~
	else								//page scrool           //~4C23I~
	{                                                           //~4C23I~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (FILEUTF8MODE(pfh) && UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2)))	//vhexline//~va20I~
    		col=coldata;	//column on data line                  //~va20I~
#endif                                                             //~va20I~
       	scrollsz=filehalfhscrollsz(Ppcw);//half size                  //~v06cR~
		if (!scrollsz)					//no window width       //~4C23I~
			return 4;                                           //~4C23I~
//  	maxleft=MAXLINEDATA-(Ppcw->UCWwidth-linenosz)+1;//for crlf //~v0anR~
        if (spfsw)                                                 //~v0cyI~
   		 	maxleft=pfh->UFHlrecl-(Ppcw->UCWwidth-linenosz);//no crlf//~v0cyI~
		if ((pfc->UFCleft=(col/scrollsz-1)*scrollsz)<0)               //~v06cR~
			pfc->UFCleft=0;                                           //~v06cI~
//  	if (pfc->UFCleft>=maxleft)                                 //~v0anR~
//  		pfc->UFCleft=maxleft;                                  //~v0anR~
        if (spfsw)                                                 //~v0cyI~
			if (pfc->UFCleft>=maxleft)                             //~v0cyI~
		  		pfc->UFCleft=maxleft;                              //~v0cyI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (FILEUTF8MODE(pfh) && UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2)))	//vhexline//~va20I~
      {                                                            //~va20I~
	    col=PLHPOS2OFFS(0,plh,coldata)-PLHPOS2OFFS(0,plh,pfc->UFCleft);//~va20I~
		if (col>=Ppcw->UCWwidth-linenosz)	//out of curr window   //~va20I~
        {                                                          //~va20I~
           	pfc->UFCleft+=scrollsz;                                //~va20I~
		    col=PLHPOS2OFFS(0,plh,coldata)-PLHPOS2OFFS(0,plh,pfc->UFCleft);//~va20I~
        }                                                          //~va20I~
		Ppcw->UCWrcsrx=col+linenosz;//pos from left                //~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
		Ppcw->UCWrcsrx=col-pfc->UFCleft+linenosz;//pos from left//~v069R~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                        //~4C23I~
	}                                                           //~4C23I~
	csrloctogbl(Ppcw);  	//convert local to gbl csrpos       //~4C25I~
	return 0;                                                   //~4C23I~
}//file_lineend_file                                            //~4C23I~
                                                                //~4C23I~
//**********************************************************  //~4C17I~
//* file top/end                                              //~4C17I~
//**********************************************************  //~4C17I~
//*file top *****************************                     //~4C17I~
int func_filetop_file(PUCLIENTWE Ppcw)                        //~4C17I~
{                                                             //~4C17I~
	PUFILEC pfc;                                                 //~4C17I~
	PUFILEH  pfh;                                                //~4C17I~
	PULINEH  plh;                                               //~5527R~
    int rc;                                                     //~5527I~
//****************:	                                          //~4C17I~
	pfc=Ppcw->UCWpfc;                                            //~4C17I~
	pfh=pfc->UFCpfh;                                             //~4C17I~
	if (pfc->UFCcurtop!=(plh=UGETQTOP(&pfh->UFHlineque)))       //~5527I~
	{                                                            //~4C17I~
		pfc->UFCcurtop=plh;                                         //~4C17I~
	    UCBITON(Ppcw->UCWflag,UCWFDRAW);                         //~4C17R~
        rc=0;                                                   //~5527I~
	}                                                            //~4C17I~
    else                                                        //~5527I~
    	rc=4;                                                   //~5527I~
//  if (plh->ULHtype==ULHTHDR                                   //~5527R~
//  &&  (plh=UGETQNEXT(plh),plh->ULHtype==ULHTHDR))             //~5527R~
		csrhomepos(0);		//to cmd line of cur pcw            //~5527I~
//  else                                                        //~5527R~
//  	filesetcsr(Ppcw,plh,1,0);	//data field,fldtop         //~5527R~
	return rc;                                                  //~5527R~
}//func_filetop_file                                          //~4C17I~
//*file end ***********************                           //~4C17I~
int func_fileend_file(PUCLIENTWE Ppcw)                        //~4C17I~
{                                                             //~4C17I~
	int ii,line,rc;                                             //~5527R~
	PULINEH plh,plht,plhe,plhcsr=0;                             //~5527R~
	PUFILEC pfc;                                                 //~4C17I~
	PUFILEH  pfh;                                                //~4C17I~
//****************:	                                          //~4C17I~
	pfc=Ppcw->UCWpfc;                                            //~4C17I~
	pfh=pfc->UFCpfh;                                             //~4C17I~
	plht=UGETQTOP(&pfh->UFHlineque);                             //~4C17I~
	plhe=UGETQEND(&pfh->UFHlineque);                             //~4C17I~
//  line=Ppcw->UCWheight-FILEHDRLINENO-1;                          //~v11NR~
    line=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno-1;                 //~v11NI~
  if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))	//hex 3 line mode      //~v698I~
  {                                                                //~v698I~
    line++;                                                        //~v698I~
  	plh=fcmdfindscrollvhexline(plhe,line,-line);                   //~v698R~
  }                                                                //~v698I~
  else                                                             //~v698I~
  {                                                                //~v698I~
	for (ii=0,plh=plhe;ii<line;plh=UGETQPREV(plh))               //~4C17R~
	{                                                            //~4C17I~
		if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                  //~4C17I~
			continue;                                                  //~4C17I~
        if (!plhcsr)	//csr line                              //~5527I~
        	if (plh->ULHtype!=ULHTHDR)                          //~5527I~
            	plhcsr=plh;                                     //~5527I~
                                                                //~5527I~
		if (plh==plht)                                              //~4C17I~
			break;                                                     //~4C17I~
		ii++;                                                       //~4C17I~
	}                                                            //~4C17I~
  }                                                                //~v698I~
//*csr set                                                    //~4C17I~
//  if (plhcsr)                                                 //~5527R~
//  	filesetcsr(Ppcw,plhcsr,1,0);	//data field,fldtop     //~5527R~
//  else                                                        //~5527R~
		csrhomepos(0);		//to cmd line                       //~5527R~
    if (pfc->UFCcurtop==plh)                                    //~5527I~
    	rc=4;                                                   //~5527I~
    else                                                        //~5527I~
    {                                                           //~5527I~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                        //~5527R~
		pfc->UFCcurtop=plh;                                     //~5527R~
    	rc=0;                                                   //~5527I~
    }                                                           //~5527I~
	return rc;                                                  //~5527R~
}//func_fileend_file                                          //~4C17R~
                                                                //~5111I~
//**********************************************************    //~5111I~
//*!scroll 1 line                                               //~v030R~
//**********************************************************    //~5111I~
//*backward *****************************                       //~5111R~
int func_lineup_file(PUCLIENTWE Ppcw)                           //~5111I~
{                                                               //~5111I~
	PUFILEC pfc;                                                //~5111I~
	PULINEH  plh,plh0;                                          //~v030R~
    int rc=0;                                                   //~v030I~
//****************:                                             //~5111I~
//  if (!CSRONFILELINE(Ppcw))                                   //~5505R~
//  	return 4;                                               //~5505R~
	pfc=Ppcw->UCWpfc;                                           //~5111I~
//  if (Ppcw->UCWmaxline<=FILEHDRLINENO)                           //~v11NR~
    if (Ppcw->UCWmaxline<=Ppcw->UCWfilehdrlineno)                  //~v11NI~
		return 4;                                               //~5111I~
    plh0=pfc->UFCcurtop;		//old top                       //~v030R~
    if (!(plh=getdisplayline(plh0,-1,0)))	//top is hdr        //~v030I~
		plh=plh0;                   //set to next data,later    //~v030R~
	else                                                        //~v030I~
    {                                                           //~v030I~
		pfc->UFCcurtop=plh;			//new csr line              //~v030I~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);//top changed           //~v030I~
	}                                                           //~v030I~
                                                                //~v030I~
    if (plh->ULHtype==ULHTHDR)		//prev is hdr               //~v030I~
    {                                                           //~v030I~
//  	if (Ppcw->UCWmaxline==FILEHDRLINENO+1))	//=3               //~v11NR~
		if (Ppcw->UCWmaxline==(Ppcw->UCWfilehdrlineno+1))	//=3   //~v11NI~
        	rc=4;					//hdr only                  //~v030R~
        else                                                    //~v030I~
        {                                                       //~v030I~
			plh=getdisplayline(plh,1,0);	//csr to next data  //~v030R~
	    	if (plh->ULHtype==ULHTHDR)		//next is also hdr(no data line)//~v030R~
        		rc=4;					//hdr only              //~v030R~
        }                                                       //~v030I~
	}                                                           //~v030I~
    if (rc)                                                     //~v030I~
		csrhomepos(0);		//to cmd line                       //~v030I~
	else                                                        //~v030I~
		filesetcsr(Ppcw,plh,(Ppcw->UCWtype==UCWTFILE),0);       //~v030R~
					//data field,fldtop(if dir fld 0)           //~v030I~
    if (pfc->UFCcurtop==plh0)                                   //~v030R~
    	rc=4;					//not scrolled                  //~v030R~
	return rc;                                                  //~v030R~
}//func_lineup_file	                                            //~5111I~
                                                                //~v030I~
//*forward *****************************                        //~5111I~
int func_linedown_file(PUCLIENTWE Ppcw)                         //~5111I~
{                                                               //~5111I~
	PUFILEC pfc;                                                //~5111I~
	PULINEH  plh,plhw;                                          //~v030R~
//****************:                                             //~5111I~
//  if (!CSRONFILELINE(Ppcw))                                   //~5505R~
//  	return 4;                                               //~5505R~
	pfc=Ppcw->UCWpfc;                                           //~5111I~
//  if (Ppcw->UCWmaxline<=FILEHDRLINENO)                           //~v11NR~
    if (Ppcw->UCWmaxline<=Ppcw->UCWfilehdrlineno)                  //~v11NI~
		return 4;                                               //~5111I~
    if (!(plh=getdisplayline(pfc->UFCcurtop,1,0)))//end of file //~5204R~
		return 4;                                               //~5111I~
	pfc->UFCcurtop=plh;                                         //~5111I~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);                            //~5111I~
	plh=(Ppcw->UCWpsd+Ppcw->UCWmaxline-1)->USDbuffc;            //~5111I~
    if (!UGETQNEXT(plh))	//=last display is hdr              //~v030R~
    {                                                           //~5111I~
		if (plh==pfc->UFCcurtop) //=new top is last hdr line    //~v030R~
        {                                                       //~v030I~
			csrhomepos(0);		//to cmd line                   //~v030I~
			return 4;			//only 1 line                   //~5111I~
		}                                                       //~v030I~
    	plh=getdisplayline(plh,-1,0);	//=last data line       //~v030R~
    }                                                           //~5111I~
    else    	//last displayed is data line                   //~v030R~
    {                                                           //~v030I~
    	plhw=getdisplayline(plh,1,0);	//=next of last displayed//~v030R~
	    if (plhw->ULHtype!=ULHTHDR)		//next is also hdr(no data line)//~v030R~
        	plh=plhw;			//csr on the next fld           //~v030I~
	}                                                           //~v030I~
	filesetcsr(Ppcw,plh,(Ppcw->UCWtype==UCWTFILE),0);	//data field,fld top//~v030R~
	return 0;                                                   //~5111I~
}//file_linedown_file	                                        //~5111I~
                                                                //~5111I~
//****************************************************************
// filescrollchk
//*chk scroll input
//*parm PUCLIENTWE
//*rc   :0,4(err)
//****************************************************************
int filescrollchk(PUCLIENTWE Ppcw)
{
	PUPANELC ppc;
	PUSCRD   psd;
	UCHAR wk[10];
//****************************
	ppc=Ppcw->UCWppc;
//**scroll input
	if (!UCBITCHK(ppc->UPCflag,UPCFSCROLLINPUT))//scroll input at xechar//~5527R~
		return 0;
	UCBITOFF(ppc->UPCflag,UPCFSCROLLERR);
	psd=Ppcw->UCWpsd;
	psd++;
	getfldinput(Ppcw,CMDLINENO,1,wk);	//row 1.fld 1(scroll data fld)
	if (filesetscrollsz(Ppcw,wk))		//operand err           //~v033I~
		{
			csronthefld(Ppcw,CMDLINENO,1,0);	//set cursor to fld top//~5223R~
			UCBITON(ppc->UPCflag,UPCFSCROLLERR);
			UCBITON(psd->USDflag2,USDF2DRAW);
			return 4;
		}
	UCBITOFF(ppc->UPCflag,UPCFSCROLLINPUT);	//accepted
	return 0;		//process cmd input
}//filescrollchk                                                //~4C24R~
                                                                //~4C24I~
//***********************************************
//*get scroll size ******************************
//*parm1: client work element                  *
//*parm2: 0:up/down 1:right/left                                //~4C23R~
//*parm3: destination(back/forward) used for csrscroll mode        //~v55qI~
//*return:scroll size                                           //~5527I~
//***********************************************
int getscrollsz(PUCLIENTWE Ppcw,int Popt,int Pdest)             //~5204R~
{
	int scrollsz,csrx,csry,opdno,szwk;                          //~v030R~
    int linenosz;                                               //~v069I~
	char *wkbuff;                                               //~5504R~
    PUFILEC pfc;                                                   //~v60vI~
    int vhexplhctr,vhexplhctrcsr=0;                                  //~v60vI~//~vaf9R~
//****************************
#if defined(WXEXXE)|| defined(LNX)		//wxe and gxe and linux console//~v69mI~
    if (Gwxestat & GWXES_SCROLLBYMOUSE)  //scroll by mouse         //~v69mI~
    {                                                              //~v69mI~
    	Gwxestat&=~GWXES_SCROLLBYMOUSE;  //processed               //~v69mI~
        return Gwxescrollctr;           //                         //~v69mI~
    }                                                              //~v69mI~
#endif                                                             //~v69mI~
	linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
	scrollsz=((PUPANELC)Ppcw->UCWppc)->UPCscroll;               //~5204M~
//  if (getfldinput(Ppcw,CMDLINENO,0,wkbuff))	//input on cmdline//~5504R~
    if ((wkbuff=Ppcw->UCWparm),wkbuff) //input on cmdline set by funccall//~5504I~
	{                                                           //~4C19I~
		strupr(wkbuff);                                         //~v030R~
        uparse(wkbuff,wkbuff,&opdno,0,","); //parse out,accept cr/lf//~5430R~
        if (opdno==1)	//single operand                        //~5307R~
		{                                                       //~4C19I~
			if (szwk=filechkscrollopd(wkbuff),szwk)             //~v033R~
			{                                                   //~4C23I~
				scrollsz=szwk;                                  //~v033R~
				setflddata(Ppcw,CMDLINENO,0,"");	//clear cmd data//~5204I~
			}                                                   //~4C23I~
		}                                                       //~4C19I~
	}//cmd line input                                           //~5204R~
                                                                //~5204I~
	if (Popt)			//right/left                            //~5204I~
	{                                                           //~5204I~
		if (Ppcw->UCWwidth<=linenosz)	//no client area        //~v069R~
			return 0;						//can not scroll    //~5204I~
		switch(scrollsz)                                        //~5204R~
		{                                                       //~5204R~
		case UPCSCROLLPAGE:     //browse default                //~5204R~
			scrollsz=Ppcw->UCWwidth-linenosz;                   //~v069R~
			break;                                              //~5204R~
		case UPCSCROLLHALF:		//edit default                  //~5204R~
			scrollsz=filehalfhscrollsz(Ppcw);                   //~v013R~
			break;                                              //~5204I~
		case UPCSCROLLCSR:                                      //~5204R~
            if (Ppcw->UCWrcsry<FILEHDRLINENO)                   //~5204I~
                csrx=0;                                         //~5204I~
            else                                                //~5204I~
				csrx=Ppcw->UCWrcsrx;                            //~5204I~
			if (Pdest>0)	//forward destination               //~5204R~
				if (csrx<=linenosz)                             //~v069R~
					scrollsz=Ppcw->UCWwidth-linenosz;           //~v069R~
				else                                            //~5204R~
					scrollsz=csrx-linenosz+1;                   //~v069R~
			else  			//backward                          //~5204R~
				if (csrx>=(Ppcw->UCWwidth-1) || csrx<linenosz)  //~v069R~
					scrollsz=Ppcw->UCWwidth-linenosz;           //~v069R~
				else                                            //~5204R~
					scrollsz=Ppcw->UCWwidth-csrx;               //~5204R~
			if (Ppcw->UCWwidth>linenosz+1)                      //~v069R~
				scrollsz--;                                     //~5204I~
			break;                                              //~5204R~
		case UPCSCROLLMAX:		//max                           //~5527I~
			scrollsz=-1;          //id of max                   //~5527I~
			break;                                              //~5527I~
		}//sw by scroll sz                                      //~5204R~
	}//left/right	                                            //~5204I~
	else	//up/down                                           //~5204I~
	{                                                           //~5204I~
//  	if (Ppcw->UCWheight<=FILEHDRLINENO)                        //~v11NR~
    	if (Ppcw->UCWheight<=Ppcw->UCWfilehdrlineno)               //~v11NI~
			return 0;						//can not scroll    //~5204I~
        pfc=Ppcw->UCWpfc;                                          //~v60vI~
        if (pfc && UCBITCHK(pfc->UFCflag2,UFCF2VHEX))              //~v60vI~
        {                                                          //~v60vI~
            vhexplhctr=pfc->UFCvhexplhctr;                         //~v60vR~
            vhexplhctrcsr=pfc->UFCvhexplhctrcsr;                   //~v60vR~
        }                                                          //~v60vI~
        else                                                       //~v60vI~
            vhexplhctr=-1;	//id of no vhex mode                   //~v60vI~
		switch(scrollsz)                                        //~5204I~
		{                                                       //~5204I~
		case UPCSCROLLPAGE:     //browse default                //~5204I~
//  		scrollsz=Ppcw->UCWheight-FILEHDRLINENO;                //~v11NR~
          if (vhexplhctr>=0)       //vhex mode                     //~v60vI~
          {                                                        //~v60vI~
			scrollsz=vhexplhctr;//all of displayed plh count       //~v60vI~
			if (Pdest>0)	//pgdn                                 //~v60vI~
            {                                                      //~v60vI~
	            if (scrollsz>1)                                    //~v60vI~
                	if (UCBITCHK(pfc->UFCflag2,UFCF2VHEXINCOMP))//last line not full 3 line//~v60vI~
                    	scrollsz--;		//redraw last line         //~v60vI~
            }                                                      //~v60vI~
          }                                                        //~v60vI~
          else                                                     //~v60vI~
    		scrollsz=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;       //~v11NI~
			break;                                              //~5204I~
		case UPCSCROLLHALF:		//edit default                  //~5204I~
			scrollsz=filehalfvscrollsz(Ppcw);                   //~v013R~
			break;                                              //~5204I~
		case UPCSCROLLCSR:                                      //~5204I~
			csry=min(Ppcw->UCWrcsry,Ppcw->UCWmaxline-1);        //~5204R~
			if (Pdest>0)	//forward destination               //~5204I~
//  			if (csry<=FILEHDRLINENO)                           //~v11NR~
    			if (csry<=Ppcw->UCWfilehdrlineno)   //on 1st line or up//~v11NI~
                {                                                  //~v60vI~
//  				scrollsz=Ppcw->UCWheight-FILEHDRLINENO;        //~v11NR~
          		  if (vhexplhctr>=0)       //vhex mode             //~v60vI~
					scrollsz=vhexplhctr;//all of displayed plh count//~v60vI~
                  else                                             //~v60vI~
					scrollsz=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;//1 page scroll//~v11NI~
                }                                                  //~v60vI~
				else                                            //~5204I~
                {                                                  //~v60vI~
//  				scrollsz=csry-FILEHDRLINENO+1;                 //~v11NR~
          		  if (vhexplhctr>=0)       //pgdn vhex mode        //~v60vR~
                  {                                                //~v60vI~
	          		  if (vhexplhctrcsr)       //vhex mode         //~v60vI~
    					scrollsz=vhexplhctrcsr+1;                  //~v60vR~
                      else                                         //~v60vI~
    					scrollsz=vhexplhctr;                       //~v60vI~
                  }                                                //~v60vI~
                  else                                             //~v60vI~
    				scrollsz=csry-Ppcw->UCWfilehdrlineno+1;//move csr line to top//~v11NI~
                }                                                  //~v60vI~
			else  			//backward                          //~5204I~
//  			if (csry>=(Ppcw->UCWheight-1) || csry<FILEHDRLINENO)//~v11NR~
				if (csry>=(Ppcw->UCWheight-1) || csry<Ppcw->UCWfilehdrlineno)//on cmdline//~v11NI~
                {                                                  //~v60vI~
//  				scrollsz=Ppcw->UCWheight-FILEHDRLINENO;        //~v11NR~
          		  if (vhexplhctr>=0)       //vhex mode             //~v60vI~
					scrollsz=vhexplhctr;//all of displayed plh count//~v60vI~
                  else                                             //~v60vI~
					scrollsz=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;//1 page scroll//~v11NI~
                }                                                  //~v60vI~
				else                                            //~5204I~
                {                                                  //~v60vI~
          		  if (vhexplhctr>=0)       //pgup vhex mode        //~v60vR~
                  {                                                //~v60vI~
	          		  if (vhexplhctrcsr)       //vhex mode         //~v60vI~
    					scrollsz=vhexplhctr-vhexplhctrcsr;         //~v60vR~
                      else                                         //~v60vI~
    					scrollsz=vhexplhctr;                       //~v60vI~
                  }                                                //~v60vI~
                  else                                             //~v60vI~
					scrollsz=Ppcw->UCWheight-csry;              //~5204I~
                }                                                  //~v60vI~
//  		if (Ppcw->UCWheight>FILEHDRLINENO+1)                   //~v11NR~
          if (vhexplhctr>=0)       //vhex mode                     //~v60vI~
          {                                                        //~v60vI~
          	if (vhexplhctr>1)                                      //~v60vI~
				scrollsz--;                                        //~v60vI~
          }                                                        //~v60vI~
          else                                                     //~v60vI~
          {                                                        //~v60vI~
			if (Ppcw->UCWheight>Ppcw->UCWfilehdrlineno+1)   //over 2 line//~v11NI~
				scrollsz--;                                     //~5204I~
          }                                                        //~v60vI~
			break;                                              //~5204I~
		case UPCSCROLLMAX:		//max                           //~5527I~
			scrollsz=-1;          //id of max                   //~5527I~
			break;                                              //~5527I~
		}//by scroll sz                                         //~5204I~
	}//up/down                                                  //~5204I~
	return scrollsz;
}//getscrollsz                                                  //~5527R~
                                                                //~v030I~
//***********************************************               //~v033R~
//filechkscrollopd                                              //~v033I~
//*chk scroll operand value                                     //~v033R~
//*parm1 : opd addr(must Upper char)                            //~v033R~
//*return: scrollsz,0 if err                                    //~v033R~
//***********************************************               //~v033R~
int filechkscrollopd(UCHAR *Popd)                               //~v033R~
{                                                               //~v033R~
	int scrollsz;                                               //~v033R~
//****************************                                  //~v033R~
	if (!strcmp(Popd,"P")||!strcmp(Popd,Sscrollid[0]))          //~v03nR~
		scrollsz=UPCSCROLLPAGE;                                 //~v033R~
	else                                                        //~v033R~
		if (!strcmp(Popd,"H")||!strcmp(Popd,Sscrollid[1]))      //~v03nR~
			scrollsz=UPCSCROLLHALF;                             //~v033R~
		else                                                    //~v033R~
			if (!strcmp(Popd,"C")||!strcmp(Popd,Sscrollid[2]))  //~v03nR~
				scrollsz=UPCSCROLLCSR;                          //~v033R~
			else                                                //~v033R~
				if (!strcmp(Popd,"M")||!strcmp(Popd,Sscrollid[3]))//~v03nR~
					scrollsz=UPCSCROLLMAX;                      //~v033R~
				else                                            //~v033R~
					if (strspn(Popd,"0123456789")==strlen(Popd)) //all numeric//~v033R~
						scrollsz=atoi(Popd);                    //~v033R~
                    else                                        //~v033R~
						scrollsz=0;                             //~v033R~
	return scrollsz;                                            //~v033R~
}//filechkscrollopd                                             //~v033R~
                                                                //~v033I~
//***********************************************               //~v033I~
//*filesetscrollsz                                              //~v033I~
//*set scroll size field                                        //~v033I~
//*parm1 : pcw                                                  //~v033I~
//*parm2 : opd addr                                             //~v033I~
//*return: rc(4:opd err,0 value)                                //~v033I~
//***********************************************               //~v033I~
int filesetscrollsz(PUCLIENTWE Ppcw,UCHAR *Popd)                //~v033I~
{                                                               //~v033I~
	PUPANELC ppc;                                               //~v033I~
	PUFILEC  pfc;                                                  //~v0ifI~
	PUFILEH  pfh;                                                  //~v0ifI~
	int scrollsz,indx;                                             //~v440R~
    int kfsw;                                                      //~v0ifI~
    UCHAR wk[8];                                                //~v033I~
//****************************                                  //~v033I~
	ppc=Ppcw->UCWppc;                                           //~v033I~
	switch(toupper(*Popd))                                      //~v033I~
	{                                                           //~v033I~
	case 'P':                                                   //~v033I~
		ppc->UPCscroll=UPCSCROLLPAGE;                           //~v033I~
		setflddata(Ppcw,1,1,Sscrollid[0]);                      //~v03nR~
		break;                                                  //~v033I~
	case 'H':                                                   //~v033I~
		ppc->UPCscroll=UPCSCROLLHALF;                           //~v033I~
		setflddata(Ppcw,1,1,Sscrollid[1]);                      //~v03nR~
		break;                                                  //~v033I~
	case 'C':                                                   //~v033I~
		ppc->UPCscroll=UPCSCROLLCSR ;                           //~v033I~
		setflddata(Ppcw,1,1,Sscrollid[2]);                      //~v03nR~
		break;                                                  //~v033I~
	case 'M':                                                   //~v033I~
		ppc->UPCscroll=UPCSCROLLMAX ;                           //~v033I~
		setflddata(Ppcw,1,1,Sscrollid[3]);                      //~v03nR~
		break;                                                  //~v033I~
	default:                                                    //~v033I~
		scrollsz=atoi(Popd);                                    //~v033R~
		if (scrollsz<=0)                                        //~v033R~
			return 4;                                           //~v033I~
		ppc->UPCscroll=(int)scrollsz;                           //~v033I~
		sprintf(wk,"%d",scrollsz);                              //~v033I~
		setflddata(Ppcw,1,1,wk);                                //~v033I~
		break;                                                  //~v033I~
	}                                                           //~v033I~
//efective for all later and at restart(written to ini at term) //~v03nI~
    kfsw=0;                                                        //~v0ifI~
    switch(Ppcw->UCWtype)                                       //~v03nI~
    {                                                           //~v03nI~
    case UCWTFILE:      //browse/edit                           //~v03nI~
      if (Ppcw->UCWmenuopt==PANMOCMD)                                 //~v06yR~
	    	indx=GSCROLLCMD;                                       //~v440R~
      else                                                      //~v06cI~
      {                                                            //~v0ifI~
//      if (UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE)) //~v0ifR~
        pfc=Ppcw->UCWpfc;                                          //~v0ifI~
        pfh=pfc->UFCpfh;                                           //~v0ifI~
   		kfsw=(pfh->UFHtype==UFHTKFI);	//ke func ini file         //~v0ifI~
   	  	if (kfsw)                                                  //~v71vI~
	    	indx=GSCROLLFKT;                                       //~v71vM~
        else                                                       //~v71vI~
        if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v0ifI~
	    	indx=GSCROLLBROWSE;                                    //~v440R~
        else                                                    //~v03nI~
	    	indx=GSCROLLEDIT;                                      //~v440R~
      }//cmdresult or else                                         //~v0ifI~
		break;                                                  //~v03nI~
    case UCWTDIR :      //browse/edit                           //~v03nI~
    	indx=GSCROLLDIR;                                           //~v440R~
		break;                                                  //~v03nI~
	default:                                                    //~v05AI~
    	indx=0;                                                    //~v440R~
    }                                                           //~v03nI~
	if (Ginitscroll[indx]!=ppc->UPCscroll)                         //~v440R~
    {                                                           //~v05AI~
//    if (!kfsw)                                                   //~v71vR~
		Ginitscroll[indx]=ppc->UPCscroll;                          //~v440R~
//  	UCBITON(Gprocstatus,GPROCSINIUPDATE);//need write ini at term//~v065R~
    }                                                           //~v05AI~
    return 0;                                                   //~v033I~
}//filesetscrollsz                                              //~v033I~
                                                                //~v033I~
//***********************************************               //~v03nI~
//*filegetscrollid                                              //~v03nI~
//*get string scroll from id number                             //~v03nI~
//*parm1 : id number                                            //~v03nI~
//*return: string addr                                          //~v03nI~
//***********************************************               //~v03nI~
UCHAR *filegetscrollid(int Pscrollid)                           //~v03nI~
{                                                               //~v03nI~
//****************************                                  //~v03nI~
	if (Pscrollid>=0 || Pscrollid < -MAXSCROLLID)               //~v03nI~
    	return uitoa10(Pscrollid);                              //~v03nR~
	return Sscrollid[-Pscrollid-1];                             //~v03nI~
}//filegetscrollid                                              //~v03nR~
                                                                //~v03nI~
//***********************************************               //~5423I~
//*get horizontal half scroll size **************               //~5423I~
//*parm1: client work element                   *               //~5423I~
//*return:scrollsz                                              //~5423I~
//***********************************************               //~5423I~
int filehalfhscrollsz(PUCLIENTWE Ppcw)                          //~v013R~
{                                                               //~5423I~
	int scrollsz;                                               //~5423I~
//****************************                                  //~5423I~
	if (!(scrollsz=(Ppcw->UCWwidth-Ppcw->UCWlinenosz)/2))       //~v069R~
		scrollsz=1;                                             //~5423I~
    return scrollsz;                                            //~5423I~
}//filehalfhscrollsz                                            //~v013R~
                                                                //~5423I~
//***********************************************               //~5423I~
//*get virtical half scroll size   **************               //~5423I~
//*parm1: client work element                   *               //~5423I~
//***********************************************               //~5423I~
int filehalfvscrollsz(PUCLIENTWE Ppcw)                          //~v013R~
{                                                               //~5423I~
	PUFILEC pfc;                                                   //~v60vI~
	int scrollsz;                                               //~5423I~
//****************************                                  //~5423I~
    pfc=Ppcw->UCWpfc;                                              //~v60vI~
  if (pfc && UCBITCHK(pfc->UFCflag2,UFCF2VHEX))	//vhex mode        //~v60vI~
  {                                                                //~v60vI~
  	if (!(scrollsz=pfc->UFCvhexplhctr/2))                          //~v60vI~
    	scrollsz=1;                                                //~v60vI~
  }                                                                //~v60vI~
  else                                                             //~v60vI~
  {                                                                //~v60vI~
//  if (!(scrollsz=(Ppcw->UCWheight-FILEHDRLINENO)/2))             //~v11NR~
    if (!(scrollsz=(Ppcw->UCWheight-Ppcw->UCWfilehdrlineno)/2))    //~v11NI~
		scrollsz=1;                                             //~5423I~
  }                                                                //~v60vI~
	return scrollsz;                                            //~5423I~
}//filehalfvscrollsz                                            //~v013R~
                                                                //~5423I~
//**************************************************            //~5423M~
//* csr move acording CSD option using UCWkeytype               //~5423R~
//* parm1:pcw                                                   //~5423M~
//**************************************************            //~5423M~
int filecharcsr(PUCLIENTWE Ppcw)                                //~5423R~
{                                                               //~5423M~
//  int 	rc;                                                    //~va3TR~
    int 	rc=0;                                                  //~va3TI~
	int 	hexskip;                                               //~v442I~
    int vhexcsr=0;                                                 //~va3TR~
    PUFILEH pfh;                                                   //~v0d7I~
//****************************                                  //~5423M~
//  if (UCBITCHK(Gscrstatus,GSCRSCSRDOWN))                         //~va3RR~
	if (Gotherstatus & GOTHERS_CHLPOPUP)//CommandHistoryList popup at return from funccall,UCWreason is not avail becaquse Ppcw may be freeed//+vbi3R~
    {                                                              //~vbi3I~
    	return 0;	//pcw will be freed                            //~vbi3I~
    }                                                              //~vbi3I~
	if (Ppcw->UCWreason==UCWREASON_CHLSPLIT)	//free current command history list pfh+pcw at return to funccall//~vbi3I~
    {                                                              //~vbi3I~
    	return 0;	//no csr move                                  //~vbi3I~
    }                                                              //~vbi3I~
	if (Ppcw->UCWreason==UCWREASON_CHLNOSPLIT)	//free current command history list pfh+pcw at return to funccall//~vbi3I~
    {                                                              //~vbi3I~
    	return 0;	//no csr move                                  //~vbi3I~
    }                                                              //~vbi3I~
    if (Goptopt3 & GOPT3_VHEXCSRZIGZAG)                            //~va3TI~
    {                                                              //~va3TI~
      	if (Ppcw->UCWreason==UCWREASON_VHEX1STEP)                  //~va3TI~
	    	vhexcsr=1;                                             //~va3TR~
      	else                                                       //~va3TI~
		if (Ppcw->UCWreason==UCWREASON_VHEX2STEP)                  //~va3TI~
	    	vhexcsr=2;                                             //~va3TI~
    }                                                              //~va3TI~
    if (UCBITCHK(Gscrstatus,GSCRSCSRDOWN)                          //~va3RI~
    &&  Ppcw->UCWreason!=UCWREASON_HEXSTEPDEL	//del at EOL creted new dbcs//~va3RI~
    &&  Ppcw->UCWreason!=UCWREASON_DELEOLGB4	//del at EOL on GB4 Env//~va3RI~
    &&  !vhexcsr                                                   //~va3TI~
    )                                                              //~va3RI~
    {                                                           //~5423M~
    	if (Ppcw->UCWrcsry+1==Ppcw->UCWheight)                  //~5423M~
        	rc=filepgdownhalf(Ppcw);                            //~5423R~
		else                                                    //~5423M~
        	rc=0;		//call func_right                       //~5423M~
        if (!rc)                                                //~5423M~
			csrchardown(Ppcw);		//cursor move after draw    //~5423R~
	}                                                           //~5423M~
	else                                                        //~5423M~
    {                                                           //~5423M~
      if (Ppcw->UCWreason==UCWREASON_HEXSTEPDEL)	//del of long line hex part//~v73nR~
      {                                                            //~v73nI~
    	if (Ppcw->UCWrcsrx>Ppcw->UCWlinenosz)                      //~v73nI~
          csronthefld(Ppcw,Ppcw->UCWrcsry,0,Ppcw->UCWrcsrx-1);     //~v73nI~
      }                                                            //~v73nI~
      else                                                         //~va3TI~
      if (vhexcsr==1	//zigzag mode at upper vhex                //~va3TR~
      &&  Ppcw->UCWrcsry+1<Ppcw->UCWheight)                        //~va3TI~
      {                                                            //~va3TI~
		csrchardown(Ppcw);		//cursor move after draw           //~va3TI~
      }                                                            //~va3TI~
      else                                                         //~v73nI~
      {                                                            //~v73nI~
    	hexskip=(Ppcw->UCWreason==UCWREASON_HEXSTEP);              //~v442I~
    	if (Ppcw->UCWreason==UCWREASON_CSRBYKEYTYPE)               //~v777I~
            hexskip=0;                                             //~v777I~
        if (vhexcsr==2)	//zigzag mode at lower vhex                //~va3TI~
            hexskip=0;                                             //~va3TI~
//  	if (Ppcw->UCWrcsrx+Ppcw->UCWkeytype>=Ppcw->UCWwidth)       //~v442R~
    	if (Ppcw->UCWrcsrx+Ppcw->UCWkeytype+hexskip>=Ppcw->UCWwidth)//~v442R~
        {                                                          //~v0d7I~
          pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                   //~v0d7I~
          if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK)                //~v0d7I~
          &&  pfh->UFHlrecl==STDSPFLRECL)                          //~v0d7I~
            rc=0;                                                  //~v0d7I~
          else                                                     //~v0d7I~
        	rc=filepgrighthalf(Ppcw);                           //~5423R~
		}                                                          //~v0d7I~
		else                                                    //~5423M~
        	rc=0;		//call func_right                       //~5423M~
        if (!rc)                                                //~5423M~
        {                                                          //~v55qI~
          if (vhexcsr==2)	//zigzag mode at lower vhex            //~va3TI~
          {                                                        //~va3TI~
            csronthefld(Ppcw,Ppcw->UCWrcsry-1,0,Ppcw->UCWrcsrx);	//1line up//~va3TI~
		    csrcharright(Ppcw);//cursor move after draw(for dbcs consideration)//~va3TI~
          }                                                        //~va3TI~
          else                                                     //~va3TI~
          if (hexskip)                                             //~v442R~
          	csronthefld(Ppcw,Ppcw->UCWrcsry,0,Ppcw->UCWrcsrx+2);   //~v442R~
          else                                                     //~v442I~
    	  if (Ppcw->UCWreason==UCWREASON_CSRBYKEYTYPE)             //~v777I~
          {                                                        //~v777I~
          	csronthefld(Ppcw,Ppcw->UCWrcsry,0,Ppcw->UCWrcsrx+Ppcw->UCWkeytype-1);//~v777I~
			csrcharright(Ppcw);//cursor move after draw(for dbcs consideration)//~v777I~
          }                                                        //~v777I~
          else                                                     //~v777I~
			csrcharright(Ppcw);//cursor move after draw         //~5423R~
        }                                                          //~v55qI~
      }                                                            //~v73nI~
	}                                                           //~5423M~
	return rc;                                                  //~5423M~
}//filecharcsr                                                     //~va3RR~
//**************************************************               //~v60vI~
//* count step line by plh step count                              //~v60vI~
//* parm1:pcw                                                      //~v60vI~
//**************************************************               //~v60vI~
int filevhexstepline(PUCLIENTWE Ppcw,PUFILEC Ppfc,int Pstep)       //~v60vR~
{                                                                  //~v60vI~
	PULINEH plh;                                                   //~v60vI~
    int step=0,maxstep,ii;                                         //~v60vR~
//****************************                                     //~v60vI~
	plh=Ppfc->UFCcurtop;                                           //~v60vR~
	maxstep=Ppfc->UFCvhexplhctr;                                   //~v60vR~
    if (Pstep>0)	//pgdn                                         //~v60vR~
    {                                                              //~v60vI~
    	for (ii=min(Pstep,maxstep);ii>0 && plh;ii--,plh=UGETQNEXT(plh))//~v60vR~
        {                                                          //~v60vI~
        	if (plh->ULHtype==ULHTDATA)                            //~v60vI~
            	step+=3;                                           //~v60vI~
            else                                                   //~v60vI~
            	step++;                                            //~v60vI~
        }                                                          //~v60vI~
    }                                                              //~v60vI~
    else	//pgup                                                 //~v60vR~
    if (Pstep<0)                                                   //~v60vR~
    {                                                              //~v60vI~
    	for (ii=min(-Pstep,maxstep);ii>0 && (plh=UGETQPREV(plh),plh);ii--)//~v60vR~
        {                                                          //~v60vI~
        	if (plh->ULHtype==ULHTDATA)                            //~v60vI~
            	step+=3;                                           //~v60vI~
            else                                                   //~v60vI~
            	step++;                                            //~v60vI~
        }                                                          //~v60vI~
    }                                                              //~v60vI~
	return step;                                                   //~v60vI~
}//filevhexstep                                                    //~v60vI~
//**************************************************               //~v773I~
//* cursor jump between data and hex/vhex part                     //~v773I~
//* parm1:pcw                                                      //~v773I~
//**************************************************               //~v773I~
int func_jumpcharhex_file(PUCLIENTWE Ppcw)                         //~v773I~
{                                                                  //~v773I~
	PUSCRD 	 psd;                                                  //~v773R~
	PULINEH  plh;                                                  //~v773I~
	PUFILEC  pfc;                                                  //~v773I~
	PUFILEH  pfh;                                                  //~v773I~
    char *pdbcs;                                                   //~v773I~
    int hpos,hpose,ulhlen,linenosz,csrx,csry,vhexpsdid;            //~v773R~
    int vhexmode,hhexmode,newcsrx,newcsry,newrecoffs,recoffs,scrollsz;//~v773R~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitctr;                                                  //~va1cR~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swu8file,posc,offsx;                                       //~va20R~
#endif                                                             //~va20I~
//****************************                                     //~v773I~
	if (!CSRONFILELINE(Ppcw))                                      //~v773R~
		return errcsrpos();                                        //~v773R~
	pfc=Ppcw->UCWpfc;                                              //~v773I~
	pfh=pfc->UFCpfh;                                               //~v773I~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v773I~
	plh=psd->USDbuffc;                                             //~v773I~
	if (plh->ULHtype!=ULHTDATA)                                    //~v773I~
		return errcsrpos();                                        //~v773R~
#ifdef UTF8UCS2                                                    //~va20I~
    swu8file=FILEUTF8MODE(pfh);                                    //~va20R~
#endif                                                             //~va20I~
    hhexmode=UCBITCHK(pfh->UFHflag5,UFHF5HEX);                     //~v773I~
    vhexmode=UCBITCHK(pfc->UFCflag2,UFCF2VHEX);                    //~v773I~
    if (!hhexmode && !vhexmode)                                    //~v773I~
    {                                                              //~v773I~
    	uerrmsg("Effective only when Hex part is displayed",       //~v773I~
                "Hex•”\x95\\Ž¦‚ÌŽž‚É‚Ì‚Ý—LŒø");                    //~v773I~
        return 4;                                                  //~v773I~
    }                                                              //~v773I~
//**                                                               //~v773I~
    pdbcs=plh->ULHdbcs;                                            //~v773I~
    ulhlen=plh->ULHlen;                                            //~v773I~
    linenosz=Ppcw->UCWlinenosz;                                    //~v773I~
    csrx=Ppcw->UCWrcsrx;                                           //~v773I~
    newcsry=csry=Ppcw->UCWrcsry;                                   //~v773I~
    newrecoffs=recoffs=pfc->UFCleft+max(0,csrx-linenosz);   //current col//~v773R~
    vhexpsdid=UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2));//vhex display hex line sw//~v773I~
    if (hhexmode && !vhexpsdid)	//on char line of hhexmode         //~v773R~
    {                                                              //~v773I~
        filegethposrange(pfh,ulhlen,&hpos,&hpose);	//get hex area column range//~v773I~
        if (recoffs<hpos)	//csr is on data part                  //~v773I~
        	newrecoffs=filegethexpos(hpos,hpose,max(0,min(recoffs,ulhlen-1)));//~v773R~
        else	//csr is on hex part                               //~v773I~
        {                                                          //~v773I~
    		if (recoffs>=hpose)	//hhex out of rec                  //~v773I~
				newrecoffs=max(ulhlen-1,0);                        //~v773R~
            else                                                   //~v773I~
				filegetdatapos(hpos,hpose,recoffs,&newrecoffs,0 /*opt:0:next char if on intermediate space*/);//~v773R~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (UDBCSCHK_DBCSNOT1ST(*(pdbcs+newrecoffs)))	//not 1st of dbcs//~va1cR~
            	if (newrecoffs>0)                                  //~va1cR~
	            {                                                  //~va1cR~
			        splitctr=XESUB_DBCSSPLITCTR_L(pdbcs,newrecoffs);//~va1cR~
                  if (newrecoffs>=splitctr)                        //~va1cR~
	            	newrecoffs-=splitctr;                          //~va1cR~
    	        }                                                  //~va1cR~
#else                                                              //~va1cR~
            if (*(pdbcs+newrecoffs)==DBCS2NDCHAR)                  //~v773I~
            	if (newrecoffs>0)                                  //~v773I~
	            	newrecoffs--;                                  //~v773R~
#endif                                                             //~va1cR~
        	if (vhexmode)                                          //~v773I~
            	newcsry++;                                         //~v773I~
        }                                                          //~v773I~
    }                                                              //~v773I~
    else	//vhexmode                                             //~v773I~
    {                                                              //~v773I~
    	if (recoffs>=ulhlen)	//vhex out of rec                  //~v773I~
			newrecoffs=max(ulhlen-1,0);                            //~v773R~
        if (vhexpsdid)                                             //~v773R~
        {                                                          //~v773I~
        	newcsry--;                                             //~v773M~
        	if (vhexpsdid==USDF2VHEXLINE2)                         //~v773R~
	        	newcsry--;                                         //~v773I~
        }                                                          //~v773I~
        else                                                       //~v773R~
        	newcsry++;                                             //~v773R~
#ifdef UTF8UCS2                                                    //~va20I~
		if (swu8file)	//dd fmt                                   //~va20I~
        {                                                          //~va20I~
        	xeutf_getvhexcsrpos(0,vhexpsdid,Ppcw,plh,csrx-linenosz,&posc,&offsx);//~va20I~
            if (vhexpsdid)	//csr is on vhex line                  //~va20I~
            {                                                      //~va20I~
            	recoffs=newrecoffs=posc+pfc->UFCleft;              //~va20R~
                newcsrx=posc+linenosz;                             //~va20I~
            }                                                      //~va20I~
            else	//data to vhex jump                            //~va20R~
            {                                                      //~va20I~
            	newcsrx=offsx+linenosz;                            //~va20I~
        		if (newcsrx>=Ppcw->UCWwidth)                       //~va20I~
                {                                                  //~va20I~
		        	scrollsz=filehalfhscrollsz(Ppcw);//half scroll size//~va20I~
					pfc->UFCleft+=scrollsz;                        //~va20I~
		        	xeutf_getvhexcsrpos(0,vhexpsdid,Ppcw,plh,csrx-linenosz-scrollsz,&posc,&offsx);//~va20I~
	            	newcsrx=offsx+linenosz;                        //~va20I~
					UCBITON(Ppcw->UCWflag,UCWFDRAW);               //~va20I~
                }                                                  //~va20I~
            }                                                      //~va20I~
	        Ppcw->UCWrcsrx=newcsrx;                                //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (UDBCSCHK_DBCSNOT1ST(*(pdbcs+newrecoffs)))              //~va1cR~
			newrecoffs-=XESUB_DBCSSPLITCTR_L(pdbcs,newrecoffs);    //~va1cR~
#else                                                              //~va1cR~
        if (*(pdbcs+newrecoffs)==DBCS2NDCHAR)                      //~v773I~
            newrecoffs--;                                          //~v773I~
#endif                                                             //~va1cR~
    }                                                              //~v773I~
    if (newcsry!=csry)  //vhexmode                                 //~v773I~
    {                                                              //~v773I~
    	if (newcsry>=Ppcw->UCWheight)                              //~v773R~
        {                                                          //~v773I~
			filepgdown(Ppcw,1);	//1line down                       //~v773R~
            newcsry=Ppcw->UCWrcsry+1;    //pgdown reduce csry      //~v773R~
			UCBITON(Ppcw->UCWflag,UCWFDRAW);                       //~v773I~
        }                                                          //~v773I~
        Ppcw->UCWrcsry=newcsry;                                    //~v773I~
    }                                                              //~v773I~
    if (newrecoffs!=recoffs)  //hhexmode jump                      //~v773I~
    {                                                              //~v773I~
    	newcsrx=newrecoffs-pfc->UFCleft+linenosz;                  //~v773R~
        if (newcsrx<linenosz||newcsrx>=Ppcw->UCWwidth)             //~v773R~
        {                                                          //~v773I~
        	scrollsz=filehalfhscrollsz(Ppcw);//half scroll size    //~v773I~
			pfc->UFCleft=max(0,(newrecoffs/scrollsz)*scrollsz-scrollsz);//~v773R~
	    	newcsrx=newrecoffs-pfc->UFCleft+linenosz;              //~v773R~
			UCBITON(Ppcw->UCWflag,UCWFDRAW);                       //~v773I~
        }                                                          //~v773I~
        Ppcw->UCWrcsrx=newcsrx;                                    //~v773I~
    }                                                              //~v773I~
	csrloctogbl(Ppcw);  //set gbl pos                              //~v773I~
	return 0;                                                      //~v773I~
}//func_jumpcharhex_file                                           //~v773I~
