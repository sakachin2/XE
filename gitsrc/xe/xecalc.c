//CID://+vb98R~:                                                   //+vb98R~
//*************************************************************
//*xecalc.c
//* basic calc
//*************************************************************
//vb98:170316 XBC help;missing help of [R]:put result to cmdline   //+vb98I~
//v606:041228 xbc cmd:support $n                                   //~v606I~
//v51y:030704 xbc:option to set result output to cmd input line to continued operation//~v51yI~
//v50H:030126 (DOS)no XBC cmd support for memory                   //~v50HI~
//v50y:030125 (BUG)missing otype=L of xbc help msg                 //~v50yI~
//v415:010728 change BC --> XBC(basic calc)                        //~v415I~
//v17i:000513 move BC cmd to ulib for utility XBC                  //~v17iI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32
//  	#include <windows.h>
	#else
//    #define INCL_BASE
//    #include <os2.h>
	#endif
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <ucalc.h>                                                 //~v17iI~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefunc.h"
#include "xecalc.h"
#include "xeerr.h"                                                 //~v50HI~
#include "xesub.h"                                                 //~v51yI~
#include "xecsr.h"                                                 //~v51yI~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int func_bc(PUCLIENTWE Ppcw)
{
#ifdef DOSDOS                                                      //~v51yI~
#else                                                              //~v51yI~
    UCHAR resultstr[64];                                           //~v51yI~
    int rc;                                                        //~v51yI~
    int ii,delm;                                                   //~v606R~
    UCHAR *pc,*pco,resultall[(UCALC_MAXRESULTLEN+4)*UCALC_MAXRESULTNO];//~v606I~
#endif                                                             //~v51yI~
//*********************************
#ifdef DOSDOS                                                      //~v50HI~
    return errnotsupported("XBC","DOS version");                   //~v50HI~
#else                                                              //~v50HR~
	if (!Ppcw->UCWparm)		//no operand                           //~v17iI~
    {                                                              //~v17iI~
//      uerrmsg("XBC {decno|Xhexno|Ooctno} [{+|-|*|!|/|%%|<|>|&|||^} opd2] [/{X|O|D|U|Z}]",0);//~v50yR~
//      uerrmsg("XBC {decno|Xhexno|Ooctno} [{+|-|*|!|/|%%|<|>|&|||^} opd2] [/{X|O|D|U|Z|L}]",0);//~v51yR~
//      uerrmsg("XBC {decno|Xhexno|Ooctno} [{+|-|*|!|/|%%|<|>|&|||^} opd2] [/{X|O|D|U|Z|L}] [R]",0);//~v606R~
//      uerrmsg("XBC {L$|$n|[$n=]{decno|Xhexno|Ooctno} [{+|-|*|!|/|%%|<|>|&|||^} opd2] [/{X|O|D|U|Z|L}] [Vn[R]]}",0);//~v606R~//+vb98R~
        uerrmsg("XBC {L$|$n|[$n=]{decno|Xhexno|Ooctno} [{+|-|*|!|/|%%|<|>|&|||^} opd2] [/{X|O|D|U|Z|L}] [Vn[R]] [R]}",0);//+vb98I~
        return 0;                                                  //~v17iI~
    }                                                              //~v17iI~
    if (!memicmp(Ppcw->UCWparm,"L$",2))	//list $n                  //~v606I~
    {                                                              //~v606I~
    	pco=resultall;                                             //~v606I~
        delm=' ';                                                  //~v606R~
        for (ii=0;ii<UCALC_MAXRESULTNO;ii++)                       //~v606I~
        {                                                          //~v606I~
            pc=Gucalc_result[ii];                                  //~v606I~
            if (*pc)                                               //~v606I~
                pco+=sprintf(pco,"%c$%d=%s",delm,ii,pc);           //~v606R~
            delm=',';                                              //~v606R~
        }                                                          //~v606I~
        if (pco==resultall)                                        //~v606I~
            uerrmsg("No entry to list",0);                         //~v606I~
        else                                                       //~v606I~
        	uerrmsg(resultall,0);                                  //~v606I~
        return 0;                                                  //~v606I~
    }                                                              //~v606I~
//  return ucalc_bcmain(Ppcw->UCWparm);                            //~v51yR~
    rc=ucalc_bcmain(Ppcw->UCWparm,resultstr+4);                    //~v51yI~
    if (!rc && *(resultstr+4))                                     //~v51yR~
    {                                                              //~v51yI~
    	memcpy(resultstr,"XBC ",4);                                //~v51yI~
    	setflddata(Ppcw,CMDLINENO,0,resultstr);//0:fldno           //~v51yR~
        csronthefld(Ppcw,CMDLINENO,0,(int)strlen(resultstr));//move csr to end of line//~v606R~
        rc=RC3LEAVECMDLINE;       //to bypass cmdline cleared      //~v51yR~
    }                                                              //~v51yI~
	return rc;                                                     //~v51yI~
#endif                                                             //~v50HI~
}//func_bc
