//*CID://+vaarR~:          update#= 6                              //~vaarR~
//************************************************************* //~4C23I~
//*xepan3.c                                                     //~4C23I~
//*lineend,linetop,nextvalue,prevvalue                             //~v07fI~
//************************************************************* //~4C23I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//v60h:050129 accept linetop/lineend on protected fld as prevtab/nexttab//~v60hI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07f:960701:if field is protected when nextvalue/prevvalue,move csr there.//~v07fI~
//v07a:960615:allow dup key assign to differrent function for only on of assigned key//~v07aI~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//*v03b:950730:zenkaku err msg for lineno,scroll fld etc        //~v03bI~
//*v039:950728:bug,setflddata need set dbcstbl also(getfldpos parm chng)//~v039I~
//*v020:950616:dir support(fldprotchk return pfld)              //~v020I~
//************************************************************* //~v020I~
#include <time.h>                                               //~4C23I~
#include <stdio.h>                                              //~4C23I~
#include <stddef.h>                                             //~4C23I~
#include <stdlib.h>                                             //~4C23I~
#include <ctype.h>                                              //~4C23I~
#include <string.h>                                             //~4C23I~
                                                                //~4C23I~
#ifdef DOS                                                      //~4C23I~
#else                                                           //~4C23I~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif                                                          //~4C23I~
//*******************************************************       //~4C23I~
#include <ulib.h>                                               //~4C23I~
#include <uerr.h>                                               //~4C23I~
#include <uque.h>                                               //~4C23I~
#include <ualloc.h>                                             //~4C23I~
#include <ufile.h>                                              //~5318I~
#include <utrace.h>                                                //~v07aI~
                                                                //~5318I~
#include "xe.h"                                                 //~4C23I~
#include "xescr.h"                                              //~4C23I~
#include "xecsr.h"                                              //~4C23I~
#include "xefile.h"                                             //~4C23I~
#include "xefunc.h"                                             //~4C23I~
#include "xepan.h"                                              //~4C23I~
#include "xepan2.h"                                                //~v07aI~
#include "xepan3.h"                                             //~4C23I~
#include "xesub.h"                                             //~4C23I~
//****************************************************************//~4C23I~
int panfldvalue(PUCLIENTWE Ppcw,int Popt);                         //~v07aI~
//****************************************************************//~4C23I~
//* linetop/lineend                                             //~4C23I~
//****************************************************************//~4C23I~
int func_linetop_pan(PUCLIENTWE Ppcw)                           //~4C23I~
{                                                               //~4C23I~
	int pfli;                                                   //~4C23R~
//***************************                                   //~4C23I~
	if ((pfli=fldprotchk(Ppcw,FPC_NODBCSCHK,0))<0)//no pfld req //~v03bR~
//  	return 4;                   	//protected                //~v60hR~
    	return func_prevtab_pan(Ppcw);  //jump to prev field       //~v60hI~
	return csronthefld(Ppcw,Ppcw->UCWrcsry,pfli,0);             //~5223R~
}                                                               //~4C23I~
int func_lineend_pan(PUCLIENTWE Ppcw)                           //~4C23I~
{                                                               //~4C23I~
	int pfli;                                                   //~4C23I~
    int row,len,pos;                                            //~5318I~
    UFLDE *pflde;                                               //~5318I~
    UCHAR *pc;                                                  //~5318I~
	PUSCRD psd;                                                    //~vaarI~
//***************************                                   //~4C23I~
	if ((pfli=fldprotchk(Ppcw,FPC_NODBCSCHK,0))<0)	//field no  //~v03bR~
//  	return 4;                   	//protected                //~v60hR~
    	return func_nexttab_pan(Ppcw);  //jump to next field       //~v60hI~
    row=Ppcw->UCWrcsry;                                         //~5318I~
    pflde=getuflde(Ppcw,row,pfli);                              //~5318I~
    getfldpos(Ppcw,row,pfli,&pc,0);                             //~v039R~
  if (row==CMDLINENO                                               //~vaarI~
  &&  UCBITCHK(Ppcw->UCWflag2,UCWF2CMDLINEDD)                      //~vaarR~
  )                                                                //~vaarI~
  {                                                                //~vaarI~
	psd=Ppcw->UCWpsd;                                              //~vaarI~
    psd+=CMDLINENO;                                                //~vaarI~
    len=psd->USDddfldlen;                                          //~vaarI~
  }                                                                //~vaarI~
  else                                                             //~vaarI~
    len=(int)strlen(pc);                                        //~5318R~
    if (pflde->UFLstart+len>Ppcw->UCWrcsrx)                     //~5318I~
    	pos=pflde->UFLstart+len;                                //~5318I~
    else                                                        //~5318I~
    	pos=pflde->UFLend-1;                                    //~5318I~
	Ppcw->UCWrcsrx=min(Ppcw->UCWwidth-1,pos);                   //~5318I~
	csrrestore(Ppcw);   //chk range and convert local pos to gbl csr pos//~5318I~
	return 0;                                                   //~5318R~
}                                                               //~4C23I~
//**************************************************************** //~v07aI~
//* field value upd/down and execute enter                         //~v07aI~
//**************************************************************** //~v07aI~
int func_nextvalue_pan(PUCLIENTWE Ppcw)                            //~v07aI~
{                                                                  //~v07aI~
	return panfldvalue(Ppcw,1);	//next value                       //~v07aI~
}//func_nextvalue_pan                                              //~v07aI~
//***************************                                      //~v07aI~
int func_prevvalue_pan(PUCLIENTWE Ppcw)                            //~v07aI~
{                                                                  //~v07aI~
	return panfldvalue(Ppcw,-1);//prev value                       //~v07aI~
}//func_prevvalue_pan                                              //~v07aI~
//**************************************************************** //~v07aI~
//* field value upd/down and execute enter                         //~v07aI~
//* parm1:pcw                                                      //~v07aI~
//* parm2:destination, 1(next) or -1(prev)                         //~v07aI~
//* return rc;                                                     //~v07aI~
//**************************************************************** //~v07aI~
int panfldvalue(PUCLIENTWE Ppcw,int Pdest)                         //~v07aI~
{                                                                  //~v07aI~
	int fli,rgb,ii,rc;                                             //~v07aR~
    UCHAR colno[16];                                               //~v07aI~
    UCHAR wk[4];	//RGB edit work                                //~v07aI~
	UCHAR colindex;                                                //~v07aI~
//***************************                                      //~v07aI~
    UTRACEP("panfldvalue dest=%d\n",Pdest);                        //~vaarI~
	if (((PUPANELC)(Ppcw->UCWppc))->UPCid!=PANOPTCOLOR)            //~v07aI~
		return funcinvalidkey(Ppcw);                               //~v07aI~
    if (Ppcw->UCWrcsry!=PANL10COL 	//not RGB input line           //~v07fR~
	||  (fli=fldprotchk(Ppcw,FPC_NODBCSCHK,0))<=0)//no pfld req,proto or black//~v07fR~
    {                                                              //~vaarI~
//  	UTRACEP("panfldvalue set csronthefld fli=%d,rcsry=%d,PANL10COL=%d\n",fli,Ppcw->UCWrcsry,PANL10COL);//+vaarR~
		return csronthefld(Ppcw,PANL10COL,1,0);	//move csr to next of black//~v07fI~
    }                                                              //~vaarI~
//set RGB value                                                    //~v07aI~
    colindex=pangetrgbix(Ppcw,PANL10COL,fli);                      //~v07aR~
    if (colindex==ERVALUE||colindex==NOVALUE)                      //~v07aR~
	    colindex=pangetrgbix(Ppcw,PANL10COLC,fli);	//current index value//~v07aR~
	rgb=panixtorgb(colindex,wk);                                   //~v07aR~
	rgb+=Pdest;			//up sequence by B, G and then R           //~v07aI~
    if (!rgb)       	//wrap to black                            //~v07aI~
    	rgb=63;			//0011 1111,round to high white            //~v07aI~
	else	                                                       //~v07aI~
	    if (rgb==64)     //over max                                //~v07aR~
	    	rgb=1;		//0000 0001,start from dark blue           //~v07aI~
    colindex=(UCHAR)panrgbtoix(rgb);	//index value              //~v07aR~
	for (ii=0;ii<16;ii++)                                          //~v07aI~
		colno[ii]=0xff;	//init by no color change                  //~v07aI~
	colno[fli]=colindex;		//color change                     //~v07aI~
                                                                   //~v07aI~
//UTRACEP("colindex=%d,fli=%d,rgb=%d\n",colindex,fli,rgb);         //~v07aR~
//UTRACED("colno",colno,sizeof(colno));                            //~v07aR~
	rc=scrsetpallette(colno);   //viosetstate and set Gpallette if success//~v07aI~
//UTRACED("colno",colno,sizeof(colno));                            //~v07aR~
    if (rc)                                                        //~v07aI~
    	return rc;                                                 //~v07aI~
	rgb=panixtorgb(colindex,wk);     //edit new RGB                //~v07aR~
    setflddata(Ppcw,PANL10COL,fli,wk);                             //~v07aI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full draw                //~v07aI~
	return 0;                                                      //~v07aI~
}//panfldvalue                                                     //~v07aI~
                                                                   //~v07aI~
//**************************************************               //~v07aI~
//*paninvalidfld                                                   //~v07aI~
//*parm1: client work element                                      //~v07aI~
//*rc   :4                                                         //~v07aI~
//**************************************************               //~v07aI~
int  paninvalidfld(PUCLIENTWE Ppcw)                                //~v07aI~
{                                                                  //~v07aI~
//************************************                             //~v07aI~
	uerrmsg("Undefined key on this field",                         //~v07aI~
		    "この欄でこのキーは使用できません");                   //~v07aI~
	return 4;                                                      //~v07aI~
}//paninvalidfld                                                   //~v07aI~
