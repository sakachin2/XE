//*CID://+vb2DR~:                             update#=   67;       //+vb2DR~
//*************************************************************
//*xechar12.c                                                      //~va1qR~
//*utf8 char input edit for cmdline,panutil etc                    //~va1qI~
//*************************************************************
//vb2D:160221 LNX compiler warning                                 //+vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaan:111230 another way of vaak;column positioning by ddfmt(USDdata and USDdbcs)//~vaanI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7a:100813 (BUG)codetbl clear overwrap to utf8 data on dir list rename field//~va7aR~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//                      GUM2_KBDU2L,GUM2_KBDL2U-->GUM2_KBDUTF8 on/off//~va10I~
//va0X:091007_(XXE)kbd generate always locale and utf8             //~va0XI~
//va0W:091007!(BUG)dir locate consider "2U" mode                   //~va0WI~
//va0N:091002!(WIN:BUG) C(J)K console kbd input is utf8,treate as locale code//~va0NI~
//va0x:090920!kbd mode change(A+u)                                 //~va0tR~
//va0t:970921 split char12 from char                               //~va0tR~
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
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>                                              //~5318I~
#ifdef UTF8SUPPH                                                   //~va1qR~
#include <ustring.h>                                               //~va0tR~
#include <udbcschk.h>                                              //~va0tR~
#include <utf.h>                                                   //~va0tR~
#include <ukbd.h>                                                  //~va1cR~
#include <utrace.h>                                                //~va0tR~
#include <utf2.h>                                                  //~vaanR~
#include <utf22.h>                                                 //~vaanI~
#endif                                                             //~va1qR~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0dhI~
#include "xechar.h"                                             //~5124I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xechar12.h"                                              //~va0tR~
#include "xescr2.h"                                                //~va0tR~
#include "xeerr.h"                                                 //~va0tR~
#include "xepan.h"                                                 //~va0tR~
#include "xesub.h"                                                 //~va0tR~
#include "xesub2.h"                                                //~va1cR~
#include "xegbl.h"                                                 //~va0tR~
#include "xeutf.h"                                                 //~va0tR~
#endif                                                             //~va1qI~
//*******************************************************
//*******************************************************       //~v04dI~
//**************************************************            //~v020I~
//*charfieldfullerr                                             //~v020I~
//* errmsg for field full                                       //~v020I~
//*parm  :none                                                  //~v020I~
//*return:4                                                     //~v020I~
//**************************************************            //~v020I~
int charfieldfullerr(void)                                      //~v020I~
{                                                               //~v020I~
//****************************                                  //~v020I~
	uerrmsg("Field Full",                                       //~v020I~
			"€–ž");                                            //~v020I~
	return 4;                                                   //~v020I~
}//charfieldfull                                                //~v020I~
                                                                //~v020I~
//**************************************************            //~5125I~
//*chartabclear                                                 //~5125I~
//* reset tab to space                                          //~5125I~
//*parm1  :dbcs tbl                                             //~5125I~
//*parm2  :len                                                  //~5125I~
//*return:none                                                  //~5125I~
//**************************************************            //~5125I~
void chartabclear(UCHAR *Pdbcs,int Plen)                        //~5125I~
{                                                               //~5125I~
#ifdef UTF8UCS2                                                    //~va1qI~
	UCHAR *pdbcs,*pdbcsn;                                          //~va1qI~
	int reslen,chklen;                                             //~va1qI~
//****************************                                     //~va1qI~
	for (reslen=Plen,pdbcs=Pdbcs;reslen>0;)                        //~va1qI~
    {                                                              //~va1qI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va3KI~
//  	pdbcsn=memchr(pdbcs,TABCHAR,reslen);                       //~va1qI~//+vb2DR~
    	pdbcsn=memchr(pdbcs,TABCHAR,(size_t)reslen);               //+vb2DI~
        if (!pdbcsn)                                               //~va1qI~
        	break;                                                 //~va1qI~
//      chklen=(int)((ULONG)pdbcsn-(ULONG)pdbcs);                  //~va1qI~//~vafkR~
        chklen=(int)((ULPTR)pdbcsn-(ULPTR)pdbcs);                  //~vafkI~
        reslen-=chklen;                                            //~va1qI~
        *pdbcsn++=0;                                               //~va1qI~
        reslen--;                                                  //~va1qI~
		for (;reslen>0;reslen--,pdbcsn++)                          //~va1qR~
        {                                                          //~va1qI~
			if (*pdbcsn!=TABPADCHAR)                               //~va1qR~
                break;                                             //~va1qI~
			*pdbcsn=0;                                             //~va1qR~
        }                                                          //~va1qI~
        pdbcs=pdbcsn;                                              //~va1qI~
    }                                                              //~va1qI~
	for (reslen=Plen,pdbcs=Pdbcs;reslen>0;)                        //~va1qI~
    {                                                              //~va1qI~
//  	pdbcsn=memchr(pdbcs,TABPADCHAR,reslen);                    //~va1qI~//+vb2DR~
    	pdbcsn=memchr(pdbcs,TABPADCHAR,(size_t)reslen);            //+vb2DI~
        if (!pdbcsn)                                               //~va1qI~
        	break;                                                 //~va1qI~
//      chklen=(int)((ULONG)pdbcsn-(ULONG)pdbcs);                  //~va1qI~//~vafkR~
        chklen=(int)((ULPTR)pdbcsn-(ULPTR)pdbcs);                  //~vafkI~
        reslen-=chklen;                                            //~va1qI~
        *pdbcsn++=0;                                               //~va1qI~
        reslen--;                                                  //~va1qI~
		for (;reslen>0;reslen--,pdbcsn++)                          //~va1qI~
        {                                                          //~va1qI~
			if (*pdbcsn!=TABPADCHAR)                               //~va1qI~
                break;                                             //~va1qI~
			*pdbcsn=0;                                             //~va1qI~
        }                                                          //~va1qI~
        pdbcs=pdbcsn;                                              //~va1qI~
    }                                                              //~va1qI~
#else                                                              //~va1qI~
	int ii;	                                                    //~5125I~
//****************************                                  //~5125I~
	for (ii=0;ii<Plen;ii++,Pdbcs++)                             //~5125R~
		if (*Pdbcs==TABCHAR || *Pdbcs==TABPADCHAR)              //~5125I~
			*Pdbcs=0;                                           //~5125I~
#endif                                                             //~va1qI~
	return;                                                     //~5125I~
}//chartabclear                                                 //~5125I~
                                                                   //~v09jI~
//**************************************************               //~v09jI~
//*charcleartabdbcs                                                //~v09jI~
//* clear dbcs tbl of tab                                          //~v09jI~
//*parm1  :dbcs tbl                                                //~v09jI~
//*return :reset length                                            //~v09jI~
//**************************************************               //~v09jI~
int charcleartabdbcs(UCHAR *Pdbcs)                                 //~v09jI~
{                                                                  //~v09jI~
	int ii;                                                        //~v09jI~
//****************************                                     //~v09jI~
	for (ii=0;;ii++)                                               //~v09jR~
    {                                                              //~v09jI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va3KI~
		if (*Pdbcs==TABCHAR)                                       //~v09jI~
        {                                                          //~v09jI~
            if (ii)         //continued tab                        //~v09jI~
                break;                                             //~v09jI~
        }                                                          //~v09jI~
        else                                                       //~v09jI~
			if (*Pdbcs!=TABPADCHAR)                                //~v09jI~
            	break;                                             //~v09jI~
		*Pdbcs++=0;                                                //~v09jI~
	}                                                              //~v09jI~
	return ii;                                                     //~v09jI~
}//charcleartabdbcs                                                //~v09jI~
                                                                   //~v09jI~
//**************************************************               //~v09jI~
//*chargettablen                                                   //~v09jI~
//* get tab length on dbcs tbl                                     //~v09jI~
//*parm1  :dbcs tbl                                                //~v09jI~
//*return :tab length                                              //~v09jI~
//**************************************************               //~v09jI~
int chargettablen(UCHAR *Pdbcs)                                    //~v09jI~
{                                                                  //~v09jI~
	int ii;                                                        //~v09jI~
//****************************                                     //~v09jI~
	for (ii=0;;ii++,Pdbcs++)                                       //~v09jI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va3KI~
		if (*Pdbcs==TABCHAR)                                       //~v09jR~
        {                                                          //~v09jI~
            if (ii)         //continued tab                        //~v09jI~
                break;                                             //~v09jI~
        }                                                          //~v09jI~
        else                                                       //~v09jI~
			if (*Pdbcs!=TABPADCHAR)                                //~v09jI~
            	break;                                             //~v09jI~
	return ii;                                                     //~v09jI~
}//chargettablen                                                   //~v09jI~
                                                                   
#ifdef UTF8SUPPH                                                   
//**************************************************               //~va0WI~
//*getutf kbd input                                                //~va0WI~
//rc:4:err,1:codetype=UTF8                                         //~va0WI~
//**************************************************               //~va0WI~
int chargetkbdutf8(int Popt,PUCLIENTWE Ppcw,UCHAR **Pputf8,int *Pputf8len,int *Ppcodetype)//~va0WI~
{                                                                  //~va0WI~
	UCHAR *keyindata,*keyindata_utf8;                              //~va0WI~
	int keyindatalen,keyindatalen_utf8,kbdct,opt;                  //~va0WI~
//*******************************                                  //~va0WI~
	keyindata_utf8=keyindata=Ppcw->UCWkeydata;                     //~va0WI~
//  keyindatalen_utf8=keyindatalen=Ppcw->UCWkeytype;               //~va1cR~
    if (Popt & CFEUO_LENPARM)                                      //~va1cR~
		keyindatalen=*Pputf8len;                                   //~va1cR~
    else                                                           //~va1cR~
		keyindatalen=Ppcw->UCWkeytype;                             //~va1cR~
	keyindatalen_utf8=keyindatalen;                                //~va1cR~
                                                                   //~va1cR~
    if (keyindatalen==1)                                       //~va0tR~//~va0NI~//~va0XI~
        kbdct=XEUTFCT_ASCII;                                   //~va0tR~//~va0NI~//~va0XI~
    else                                                       //~va0tR~//~va0NI~//~va0XI~
        kbdct=XEUTFCT_LC;                                      //~va0tR~//~va0NI~//~va0XI~
#ifdef OLDA10                                                      //~va10I~
#ifdef W32                                                         //~va0NI~//~va0WI~
    if (Gutfmode2 &  GUM2_WINKBDUTF8)     //kbd input is utf8 for the case wcdbcs and console cp!=system//~va0NI~//~va0WI~
    {                                                              //~va0NI~//~va0WI~
		if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))	//utf8 str is already setup//~va0NI~//~va0WI~
       	{                                                          //~va0NI~//~va0WI~
			if (Gutfmode2 &  GUM2_KBDL2U)      //for windows;no u2l but l2u or not//~va0NI~//~va0WI~
            {                                                      //~va0NI~//~va0WI~
    			keyindata_utf8=Ppcw->UCWkeydata_utf8str;           //~va0NI~//~va0WI~
    			keyindatalen_utf8=strlen(keyindata_utf8);          //~va0NI~//~va0WI~
        		kbdct=XEUTFCT_UTF8;                                //~va0NI~//~va0WI~
            }                                                      //~va0NI~//~va0WI~
       	}                                                          //~va0NI~//~va0WI~
    }                                                              //~va0NI~//~va0WI~
    else                                                           //~va0NI~//~va0WI~
#endif                                                             //~va0NI~//~va0WI~
#ifdef XXE  //always with utf8 string                              //~va0XI~
    if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))  //utf8 str is already setup//~va0XI~
    {                                                              //~va0XI~
        if (Gutfmode2 &  GUM2_KBDL2U      //for windows;no u2l but l2u or not//~va0XI~
        ||  (XEUTF8MODE_ENV() && !(Gutfmode2 &  GUM2_KBDU2L))      //for windows;no u2l but l2u or not//~va0XR~
        )                                                          //~va0XI~
        {                                                          //~va0XI~
            keyindata_utf8=Ppcw->UCWkeydata_utf8str;               //~va0XI~
            keyindatalen_utf8=strlen(keyindata_utf8);              //~va0XI~
            kbdct=XEUTFCT_UTF8;                                    //~va0XI~
        }                                                          //~va0XI~
    }                                                              //~va0XI~
    else                                                           //~va0XI~
#endif                                                             //~va0XI~
	if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR)	//kbdinput by utf8 str//~va0tR~//~va0xR~//~va0WI~
    && !(Gutfmode2 &  GUM2_KBDU2L)      //not kbd f2l              //~va0xI~//~va0WI~
    )                                                              //~va0xI~//~va0WI~
    {                                                              //~va0tR~//~va0WI~
    	keyindata_utf8=Ppcw->UCWkeydata_utf8str;                   //~va0tR~//~va0WI~
    	keyindatalen_utf8=strlen(keyindata_utf8);                  //~va0tR~//~va0WI~
        kbdct=XEUTFCT_UTF8;                                        //~va0tR~//~va0WI~
    }                                                              //~va0tR~//~va0WI~
    else                                                           //~va0tR~//~va0WI~
    {                                                              //~va0tR~//~va0WI~
      	if (Gutfmode2 &  GUM2_KBDL2U      //kbd l2f                  //~va0xR~//~va0WI~
      	&&  *keyindata>=0x80)                                        //~va0xI~//~va0WI~
      	{                                                            //~va0xI~//~va0WI~
	   		if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))	//utf8 str is already setup//~va0NI~//~va0WI~
       		{                                                           //~va0NI~//~va0WI~
    			keyindata_utf8=Ppcw->UCWkeydata_utf8str;                   //~va0NI~//~va0WI~
    			keyindatalen_utf8=strlen(keyindata_utf8);                  //~va0NI~//~va0WI~
       		}                                                           //~va0NI~//~va0WI~
       		else   //l2f rewuired                                       //~va0NI~//~va0WI~
       		{                                                           //~va0NI~//~va0WI~
        		opt=XEUTFCVO_STRZ|XEUTFCVO_OUTPARM|XEUTFCVO_NOERRREP|XEUTFCVO_CPU8;                                         //~va0xI~//~va0WR~
    			keyindata_utf8=Ppcw->UCWkeydata_utf8str;                   //~va0xI~//~va0WI~
//  			if (!xeutf_islocalestr(opt,keyindata,keyindatalen,(char **)(&keyindata_utf8),&keyindatalen_utf8))//~va0xR~//~va0WR~
    			if (xeutf_cvdata(opt,keyindata,keyindatalen,(char **)(&keyindata_utf8),&keyindatalen_utf8))//~va0WI~
	    		{                                                          //~va0xI~//~va0WI~
    	    		uerrmsg("translation to UTF8 failed for \"%s\"",0,     //~va0xI~//~va0WI~
        	        		    keyindata);                                //~va0xI~//~va0WI~
            		return 4;                                              //~va0xI~//~va0WI~
        		}                                                          //~va0xI~//~va0WI~
       		}//no utf8 kbdinput                                         //~va0NR~//~va0WI~
        	kbdct=XEUTFCT_UTF8;                                        //~va0xI~//~va0WI~
      	}                                                            //~va0xI~//~va0WI~
    }                                                              //~va0tR~//~va0WI~
#else   //NEWA10                                                   //~va10I~
#ifdef UTF8UCS2                                                    //~va3KI~
  if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBD)                         //~va3KI~
  &&  UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR)                        //~va3KI~
  )	//hex unicode input                                            //~va3KI~
  {                                                                //~va3KI~
    if (!UTF8ISASCII(*(Ppcw->UCWkeydata_utf8str)))                 //~va3KR~
    {                                                              //~va3KI~
    	keyindata_utf8=Ppcw->UCWkeydata_utf8str;                   //~va3KI~
//  	keyindatalen_utf8=strlen(keyindata_utf8);                  //~va3KI~//+vb2DR~
    	keyindatalen_utf8=(int)strlen(keyindata_utf8);             //+vb2DI~
        kbdct=XEUTFCT_UTF8;                                        //~va3KI~
    }                                                              //~va3KI~
  }                                                                //~va3KI~
  else                                                             //~va3KI~
#endif                                                             //~va3KI~
  {                                                                //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
//*KBDNLS_F2L_ERR is set at ukbdl_readutf8(LNX only),but for unity//~vafkI~//~vaw1R~
	if (Gutfmode2 &  GUM2_KBDUTF8     //treate as utf8             //~va3xI~
    ||  UCBITCHK(Ppcw->UCWnls,KBDNLS_F2L_ERR)                      //~va3xR~
    )                                                              //~va3xI~
#else     //accept f2l err utf8                                    //~va3xR~
	if (Gutfmode2 &  GUM2_KBDUTF8)      //treate as utf8           //~va10I~
#endif                                                             //~va3xI~
    {                                                              //~va3xI~
//    if (!UTF8ISASCII(*keyindata))                                  //~va10I~//~va3xR~
    if (!UTF8ISASCII(*keyindata) || UCBITCHK(Ppcw->UCWnls,KBDNLS_F2L_ERR))//~va3xI~
    {                                                              //~va10I~
		if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))  //kbdinput by utf8 str//~va10R~
    	{                                                          //~va10I~
    		keyindata_utf8=Ppcw->UCWkeydata_utf8str;               //~va10I~
//  		keyindatalen_utf8=strlen(keyindata_utf8);              //~va10I~//+vb2DR~
    		keyindatalen_utf8=(int)strlen(keyindata_utf8);         //+vb2DI~
        }                                                          //~va10I~
        else                                                       //~va10I~
        {                                                          //~va10I~
        	opt=XEUTFCVO_STRZ|XEUTFCVO_OUTPARM|XEUTFCVO_NOERRREP|XEUTFCVO_CPU8;//~va10I~
    		keyindata_utf8=Ppcw->UCWkeydata_utf8str;               //~va10I~
    		if (xeutf_cvdata(opt,keyindata,keyindatalen,&keyindata_utf8,&keyindatalen_utf8))//~va10I~//~va3KR~
	    	{                                                      //~va10I~
    	    	uerrmsg("translation to UTF8 failed for \"%s\"",0, //~va10I~
        	       		    keyindata);                            //~va10I~
            	return 4;                                          //~va10I~
        	}                                                      //~va10I~
        }                                                          //~va10I~
        kbdct=XEUTFCT_UTF8;                                        //~va10I~
    }                                                              //~va10I~
    }//A+U or f2l err                                              //~va3xR~
  }//not HEX unicode                                               //~va3KI~
#endif //NEWA10                                                    //~va10I~
    if (Pputf8)                                                    //~va0WI~
	    *Pputf8=keyindata_utf8;                                    //~va0WR~
    if (Pputf8len)                                                 //~va0WI~
	    *Pputf8len=keyindatalen_utf8;                              //~va0WR~
    if (Ppcodetype)                                                //~va0WI~
	    *Ppcodetype=kbdct;                                         //~va0WR~
    UTRACEP("charfldeditu8 codetype=%d\n",kbdct);                  //~va0XI~
    return (kbdct==XEUTFCT_UTF8);                                  //~va0WI~
}//chargetkbdutf8                                                  //~va0WI~
//**************************************************               
//*char field input process                                        
//*parm 1:opt+00+mode; mode 0:rep 1:insert 2:del 3:erase eof       //~va0tR~
//*parm 2:input and output buff                                    
//*parm 3:dbcs attr tbl                                            
//*parm 4:by utf8 string                                           //~va0tR~
//*parm 5:codetype for locale/utf8 mixed string                    //~va0tR~
//*parm 6:current cursor column                                    //~va0tR~
//*parm 7:buffer start column                                      //~va0tR~
//*parm 8:buffer end column                                        //~va0tR~
//*parm 9:buffer alloc size                                        //~va0tR~
//*parm10:Ppcw                                                     //~va0tR~
//*return:0:ok  ,4:buff overflow                                   
//**************************************************               
int charfldeditu8(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,              //+va0tR//~va0tR~
				UCHAR *Pbuffutf8,UCHAR *Pcodetype,                 //~va0tR~
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,int Pbuffszu8,//~va0tR~
				PUCLIENTWE Ppcw,void* /*PUPANELL*/ Ppupl)                   //~4C27R~//~va0tR~
{                                                                  
static UCHAR Sdbcsid[2]={DBCS1STCHAR,DBCS2NDCHAR};                 //~v09KI~
static UCHAR Sdbcsidss3[]=UDBCSCHK_DBCSIDSTRSS3;                   //~va1cR~
static UCHAR Sdbcsidgb4[]=UDBCSCHK_DBCSIDSTRGB4;                   //~va1cR~
	UCHAR *pc,*pcd;                                             //~5506R~
	UCHAR *keyindata,*keyindata_utf8,*pcu,*pct,*pc0,*pcd0,*pct0,*pcu0;                                           //~4C27I~//~va0tR~
	int len,addlen,keyindatalen,keyindatalen_utf8,/*opt0,*/tgtlenu8,offsu8,lenr,lenl,lenru8;//~va0tR~//~vaa7R~
    int addlen2,offsu8next=0,lenlc,kbdct;                                     //~v7a0R~//~va0tR~//~vaf9R~
//  PUPANELC ppc;                                                  //~va0tR~//~vaa7R~
    PUPANELL pupl;                                                 //~va0tR~
#ifdef LNX                                                         //~v777I
    int hankanasw=0;                                               //~v777I
#endif                                                             //~v777I
	int rc2,u8pos,ddstrlen,opt0;                                   //~vaanR~
    int paddlen;                                                   //~vaarI~
//****************************                                     
//  ppc=Ppcw->UCWppc;                                              //~va0tR~//~vaa7R~
     pupl=(PUPANELL)Ppupl;                                          //~va0tR~
    if (pupl)                                                      //~va0tR~
		pupl->UPLflags|=UPLFUTF8;   //display atty by codetbl      //~va0tR~
//  opt0=Pmode;                  //cmdline,panutil,..              //~va0tR~//~vaa7R~
    opt0=Pmode;                  //cmdline,panutil,..              //~vaanI~
    Pmode&=CFEO_OPCODEMASK;    //opcode mask(rep,ins,del,...)      //~va0tR~
	keyindata=Ppcw->UCWkeydata;                                 //~4C27I~
	keyindatalen=Ppcw->UCWkeytype;                              //~4C27I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    if (Ppcw->UCWnls & KBDNLS_SS3)                                 //~va1cR~
        keyindatalen=UDBCSCHK_SS3SZ;                               //~va1cR~
    else                                                           //~va1cR~
    if (Ppcw->UCWnls & KBDNLS_GB4)                                 //~va1cR~
        keyindatalen=UDBCSCHK_GB4SZ;                               //~va1cR~
#endif                                                             //~va1cR~
    keyindata_utf8=keyindata;                                      //~va0NI~
    keyindatalen_utf8=keyindatalen;                                //~va0NI~
//  if (keyindatalen==1)                                       //~va0tR~//~va0NI~//~va0XR~
        kbdct=XEUTFCT_ASCII;                                   //~va0tR~//~va0NI~
//  else                                                       //~va0tR~//~va0NI~//~va0XR~
//      kbdct=XEUTFCT_LC;                                      //~va0tR~//~va0NI~//~va0XR~
  if (Pmode==CHAROPREP||Pmode==CHAROPINS)                          //~va0xI~
  {                                                                //~va0xI~
	if (chargetkbdutf8(CFEUO_LENPARM,Ppcw,&keyindata_utf8,&keyindatalen_utf8,&kbdct)>1)//~va1cR~
            return 4;                                              //~va0WI~
#ifdef LNX                                                         //~v777I
    if (*keyindata==SS2 && keyindatalen==2) //EUC hankana          //~v777R
    	hankanasw=XE_ISDBCSKONJ(); //Japanese under kon            //~v79zI
#endif                                                             //~v777I
  }//rep/ins                                                       //~va0xI~
  else                                                             //~va0xI~
  {                                                                //~va0xI~
    kbdct=0;                                                       //~va0xI~
  }                                                                //~va0xI~
UTRACEP("charfldeditu8 kbdct=%x,ucwflag2=%x,gutfmode=%x,keyindatalen=%d,keyindatalenutf8=%d\n",kbdct,Ppcw->UCWflag2,Gutfmode2,keyindatalen,keyindatalen_utf8);//~va0xM~//~va0NR~
UTRACEP("keyindata=%x,keyindata_utf8=%x\n",*keyindata,*keyindata_utf8);//~va0NI~
//	pc=Pbuff+Pcurcol;                                              //~vaanR~
//	pcd=Pdbcs+Pcurcol;                                             //~vaanR~
                                                                   //~va0tR~
    pc0=Pbuff+Pstartcol;                                           //~va0tR~
    pcd0=Pdbcs+Pstartcol;                                          //~va0tR~
    pcu0=Pbuffutf8; //use from top                                 //~va0tR~
    pct0=Pcodetype;                                                //~va0tR~
//  tgtlenu8=ustrnlen(pcu0,Pbuffszu8);                             //~vaanI~//+vb2DR~
    tgtlenu8=(int)ustrnlen(pcu0,(UINT)Pbuffszu8);                  //+vb2DI~
    if (opt0 & CFEO_OPTCMDLINE)     //mixed fld update                             //~va0tI//~vaanR~
    {                                                              //~vaanM~
		rc2=cmdlinepos2offs(0,Ppcw,pcu0,pcd0,pct0,Pstartcol,Pcurcol,tgtlenu8,&offsu8,&ddstrlen,&u8pos,&paddlen);//~vaanR~//~vaarR~
		if (rc2>=0)	//ddfmt                                        //~vaanM~
        {                                                          //~vaanM~
UTRACEP("cmdlinepos2offs curcol=%d-->%d\n",Pcurcol,u8pos+Pstartcol);//~vaanR~
        	Pcurcol=u8pos+Pstartcol;                               //~vaanR~
        }                                                          //~vaanM~
    }                                                              //~vaanM~
  	pc=Pbuff+Pcurcol;                                              //~vaanI~
  	pcd=Pdbcs+Pcurcol;                                             //~vaanI~
    pct=Pcodetype+Pcurcol-Pstartcol;                               //~va0tR~
    lenr=Pendcol-Pcurcol;	//righthand of cursor                  //~va0tR~
    lenl=Pcurcol-Pstartcol;	//lefthand of cursor                   //~va0tR~
    lenlc=Pendcol-Pstartcol;	//lefthand of cursor               //~va0tR~
//  tgtlenu8=ustrnlen(pcu0,Pbuffszu8);                             //~va0tR~//~vaanR~
UTRACED("plc",pc0,(int)strlen(pc0));                                    //~va0tR~//+vb2DR~
UTRACED("pdbcs",pcd0,(int)strlen(pc0));                                 //~va0tR~//+vb2DR~
UTRACED("pct",pct0,(int)strlen(pc0));                                   //~va0tR~//+vb2DR~
UTRACED("pu8",pcu0,tgtlenu8);                                      //~va0tR~
    if (lenr>0)	//                                                 //~va0tR~
    {                                                              //~va0tR~
		if (utfpos2offs(0,pcu0,pcd0,pct0,lenl,tgtlenu8,&offsu8)>1) //~va0tR~
        	return 4;                                              //~va0tR~
    }                                                              //~va0tR~
    else                                                           //~va0tR~
    	offsu8=tgtlenu8-lenr;	//expand by space                  //~va0tR~
    pcu=pcu0+offsu8; //curcol utf8 pos                             //~va0tR~
//-------------                                                    //~va0tR~
	switch(Pmode)                                                  
	{                                                              
//**rep                                                            //~va0tR~
	case CHAROPREP:	//rep                                          
		if ((Pcurcol+keyindatalen)>=Pbuffend)                   //~v020R~
		{                                                       //~5127I~
			if ((Pcurcol+keyindatalen)>Pbuffend)                //~v020I~
				return charfieldfullerr();                      //~v020R~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~
		}                                                       //~5127I~
		if ((len=-lenr)>=0)	//out of reclen         //~5507R~      //~va0tR~
        {                                                          //~v7a0I
 			addlen=len+keyindatalen;	//after cur col            //~va0tR~
          if (len)                                                 //~va0tR~
          {                                                        //~va0tR~
            memset(Pbuff+Pendcol,' ',(UINT)len); //set before chk tab is replaced//~v7a0I
            memset(Pdbcs+Pendcol,0,(UINT)len);  //result of shorten record//~5507I~//~v7a0I
//          memset(Pcodetype+Pendcol,0,(UINT)len);  //fill codetype//~va7aR~
            memset(pct-len,0,(UINT)len);  //fill codetype          //~va7aR~
            memset(pcu-len,' ',(UINT)len); 			//expand utf8 str//~va0tR~
          }                                                        //~va0tR~
        }                                                          //~v7a0I
        else                                                    //~5506I~
        {                                                          //~v7a0I
			addlen=Pcurcol+keyindatalen-Pendcol;                   //~va0tR~
        	xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
            pcu=pcu0+offsu8;                                       //~va0tR~
            if (addlen<0)	//fully ovaerwrap                      //~va0tR~
        		xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl+keyindatalen,&tgtlenu8,&offsu8next);	//len and pos may changed by dbcs split//~va0tR~
        }                                                          //~v7a0I
		if (keyindatalen==2)                                    //~4C27R~
		{                                                          
			memcpy(pc,keyindata,2);                               //~4C27R~//~va0tR~
#ifdef LNX                                                         //~v777I
		  if (hankanasw)                                           //~v777I
          {                                                        //~v777I
    #ifdef CURSESW                                                 //~v7a2R
			UMOVSW(pcd,Sdbcsid);                                   //~v7a2I//~va0tR~
    #else                                                          //~v7a2I
           	*(pcd+1)=*pcd=UDBCSCHK_HKDBCSERR;                      //~v777I
	        Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column//~v777I
    #endif                                                         //~v7a2I
          }                                                        //~v777I
          else                                                     //~v777I
#endif                                                             //~v777I
			UMOVSW(pcd,Sdbcsid);                                   //~va0tR~
//          *pct=kbdct;                                            //~va0tR~//~vb2CR~
            *pct=(UCHAR)kbdct;                                     //~vb2CI~
//          *(pct+1)=kbdct;                                        //~va0tR~//~vb2CR~
            *(pct+1)=(UCHAR)kbdct;                                 //~vb2CI~
		}                                                          
		else                                                       
		if (keyindatalen>UDBCSCHK_DBCSSZ)                          //~va1cR~
		{                                                          //~va1cR~
			memcpy(pc,keyindata,(UINT)keyindatalen);               //~va1cR~
		  	if (keyindatalen==UDBCSCHK_SS3SZ)                      //~va1cR~
				memcpy(pcd,Sdbcsidss3,UDBCSCHK_SS3SZ);                                   //~v7a2I//~va1cR~
            else                                                   //~va1cR~
				memcpy(pcd,Sdbcsidgb4,UDBCSCHK_GB4SZ);                                   //~v7a2I//~va1cR~
            memset(pct,kbdct,(UINT)keyindatalen);                  //~va1cR~
		}                                                          //~va1cR~
		else                                                       //~va1cR~
		{                                                          
				*pc=*keyindata;                                 //~5507R~//~va0tR~
				*pcd=0;		//sbcs                              //~5507R~
//              *pct=kbdct;                                        //~va0tR~//~vb2CR~
                *pct=(UCHAR)kbdct;                                 //~vb2CI~
		}                                                          
        if (addlen<0)		//fully overwarp                       //~va0tR~
        {                                                          //~va0tR~
        	len=offsu8next-offsu8;                                 //~va0tR~
            lenru8=tgtlenu8-offsu8next;                            //~va0tR~
            if (len>keyindatalen_utf8)	//shirink                  //~va0tR~
            {                                                      //~va0tR~
            	memcpy(pcu+keyindatalen_utf8,pcu+len,(UINT)lenru8);//~va0tR~
            	len-=keyindatalen_utf8;	//shirink len              //~va0tR~
            	memset(pcu0+tgtlenu8-len,0,(UINT)len);             //~va0tR~
            }                                                      //~va0tR~
            else                                                   //~va0tR~
            if (len<keyindatalen_utf8)  //expand                   //~va0tR~
            	memmove(pcu+keyindatalen_utf8,pcu+len,(UINT)lenru8);//~va0tR~
        }                                                          //~va0tR~
        else                                                       //~va0tR~
	        *(pcu+keyindatalen_utf8)=0;	//strz                     //~va0tR~
        memcpy(pcu,keyindata_utf8,(UINT)keyindatalen_utf8);        //~va0tR~
		break;                                                     
//**ins                                                            //~va0tR~
	case CHAROPINS:	//isrt                                         
		if ((len=lenr)<0)                                          //~va0tR~
			len=0;                                                 
                                                                   
		if ((Pcurcol+keyindatalen+len)>=Pbuffend)               //~v020R~
		{                                                       //~5127I~
			if ((Pcurcol+keyindatalen+len)>Pbuffend)            //~v067I~
				return charfieldfullerr();                      //~v067R~
            if (!len)                                           //~v067I~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~
		}                                                       //~5127I~
		if (len)                                                   
		{                                                          
        	xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
            pcu=pcu0+offsu8;                                       //~va0tR~
            lenru8=tgtlenu8-offsu8;                                //~va0tR~
            if (tgtlenu8+lenru8>Pbuffszu8)                         //~va0tR~
            	return 4;                                          //~va0tR~
			memmove(pc+keyindatalen,pc,(UINT)len);//shift to right//~4C27R~
			memmove(pcd+keyindatalen,pcd,(UINT)len);            //~4C27R~
			memmove(pct+keyindatalen,pct,(UINT)len);               //~va0tR~
			memmove(pcu+keyindatalen_utf8,pcu,(UINT)lenru8+1);	//width last NULL//~va0tR~
		}                                                          
		addlen=keyindatalen;                                    //~4C27R~
		if (keyindatalen==2)                                    //~4C27R~
		{                                                          
			UMOVSW(pc,keyindata);                                  //~va0tR~
#ifdef LNX                                                         //~v777I
		  if (hankanasw)                                           //~v777I
          {                                                        //~v777I
    #ifdef CURSESW                                                 //~v7a2R
			memcpy(pcd,Sdbcsid,2);                                   //~v7a2I//~va0tR~
    #else                                                          //~v7a2I
           	*(pcd+1)=*pcd=UDBCSCHK_HKDBCSERR;                      //~v777I
	        Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column//~v777I
    #endif                                                         //~v7a2I
          }                                                        //~v777I
          else                                                     //~v777I
#endif                                                             //~v777I
			UMOVSW(pcd,Sdbcsid);                                   //~va0tR~
//          *pct=kbdct;                                            //~va0tR~//~vb2CR~
            *pct=(UCHAR)kbdct;                                     //~vb2CI~
//          *(pct+1)=kbdct;                                        //~va0tR~//~vb2CR~
            *(pct+1)=(UCHAR)kbdct;                                 //~vb2CI~
		}                                                          
		else                                                       
		if (keyindatalen>UDBCSCHK_DBCSSZ)                          //~va1cR~
		{                                                          //~va1cR~
			memcpy(pc,keyindata,(UINT)keyindatalen);               //~va1cR~
		  	if (keyindatalen==UDBCSCHK_SS3SZ)                      //~va1cR~
				memcpy(pcd,Sdbcsidss3,UDBCSCHK_SS3SZ);                                   //~v7a2I//~va1cR~
            else                                                   //~va1cR~
				memcpy(pcd,Sdbcsidgb4,UDBCSCHK_GB4SZ);                                   //~v7a2I//~va1cR~
            memset(pct,kbdct,(UINT)keyindatalen);                  //~va1cR~
		}                                                          //~va1cR~
		else                                                       //~va1cR~
		{                                                          
				*pc=*keyindata;                                 //~5102R~
				*pcd=0;		//sbcs                              //~5102R~
//              *pct=kbdct;                                        //~va0tR~//~vb2CR~
                *pct=(UCHAR)kbdct;                                 //~vb2CI~
		}                                                          
        if ((addlen2=-lenr)>0)    //out of reclen         //~5507I~//~v7a0I//~va0tR~
        {                                                       //~5507M~//~v7a0I
            memset(Pbuff+Pendcol,' ',(UINT)addlen2);                //~5507I~//~v7a0I
            memset(Pdbcs+Pendcol,0,(UINT)addlen2);  //result of shorten record//~5507I~//~v7a0I
            memset(pct0+lenlc,0,(UINT)addlen2);  //result of shorten record//~5507I~//~v7a0I//~va0tR~
            memset(pcu-addlen2,' ',(UINT)addlen2);  //fill intermediate space//~va0tR~
        }                                                       //~5507M~//~v7a0I
        if (addlen2>=0)     //outof src rec                        //~va0tR~
	        *(pcu+keyindatalen_utf8)=0;   	//strz                 //~va0tR~
        memcpy(pcu,keyindata_utf8,(UINT)keyindatalen_utf8);        //~va0tR~
		break;                                                     
//**del                                                            //~va0tR~
	case CHAROPDEL:	//del                                          
			if (Pcurcol>=Pendcol)                               //~5104I~
				return 4;                                       //~5104I~
			if (*pcd==DBCS1STCHAR)                              //~5104R~
//  		    keyindatalen=2;                                    //~va1cR~
			    keyindatalen=1+xesub_cleardbcssplit(XESUBCDSO_LEFT|XESUBCDSO_GETCTR,0/*data*/,pcd+1,Pendcol-Pcurcol-1,0/*repct*/);//~va1cR~
			else                                                //~5104R~
				    keyindatalen=1;                             //~5104R~
        	xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
            pcu=pcu0+offsu8;                                       //~va0tR~
			len=lenr-keyindatalen;                   //~5104R~     //~va0tR~
            if (len>0)	//intermediate                             //~va0tR~
            {                                                      //~va0tR~
				if (utfpos2offs(0,pcu0,pcd0,pct0,lenl+keyindatalen,tgtlenu8,&offsu8next)>1)//~va0tR~
	        		return 4;                                      //~va0tR~
            }                                                      //~va0tR~
            else	//last char                                    //~va0tR~
            	offsu8next=tgtlenu8;                               //~va0tR~
			keyindatalen_utf8=offsu8next-offsu8;                   //~va0tR~
			lenru8=tgtlenu8-offsu8-keyindatalen_utf8;              //~va0tR~
			memcpy(pc,pc+keyindatalen,(UINT)len);               //~5104R~
			memcpy(pcd,pcd+keyindatalen,(UINT)len);             //~5104R~
			memcpy(pct,pct+keyindatalen,(UINT)len);                //~va0tR~
			memcpy(pcu,pcu+keyindatalen_utf8,(UINT)lenru8);        //~va0tR~
			addlen=-keyindatalen;                               //~5104R~
			memset(pc+len,0,(UINT)keyindatalen);                //~4C27R~
			memset(pcd+len,0,(UINT)keyindatalen);               //~4C27R~
			memset(pct+len,0,(UINT)keyindatalen);                  //~va0tR~
			memset(pcu+lenru8,0,(UINT)keyindatalen_utf8);          //~va0tR~
		break;                                                     
//**eol                                                            //~va0tR~
	case CHAROPEEOL:	//erase eof(trunc line)                 //~5111R~
		if (lenr<=0)                                               //~va0tR~
			return 4;                                              
		keyindatalen=Pendcol-Pcurcol;                           //~4C27R~
        xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
        pcu=pcu0+offsu8;                                           //~va0tR~
		addlen=-keyindatalen;                                   //~4C27R~
			memset(pc,0,(UINT)keyindatalen);                    //~4C27R~
			memset(pcd,0,(UINT)keyindatalen);                   //~4C27R~
			memset(pct,0,(UINT)keyindatalen);                      //~va0tR~
			memset(pcu,0,(UINT)(tgtlenu8-offsu8));                 //~va0tR~
		break;                                                     
//**etl                                                            //~va0tR~
	case CHAROPETOL:	//erase tof(top of line)                //~5102R~
		if (Pcurcol<=Pstartcol)//startcol>0 when box cut        //~5506R~
			return 4;                                           //~4C25I~
        if (Pstartcol>Pendcol)                                     //~v66gI~//~va0tR~
            Pstartcol=Pendcol;                                     //~v66gI~//~va0tR~
        if (lenr<=0)                                       //~v0doR~//~va0tR~
		{                                                       //~4C29I~
			pc=Pbuff+Pendcol;                                   //~4C29I~
			pcd=Pdbcs+Pendcol;                                  //~4C29I~
			pct=pct0+lenlc;                                        //~va0tR~
            pcu=pcu0+tgtlenu8;                                     //~va0tR~
            keyindatalen_utf8=tgtlenu8;                            //~va0tR~
            len=0;                                                 //~va0tR~
		}                                                       //~4C29I~
        else                                                       //~va0tR~
        {                                                          //~va0tR~
        	xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
        	pcu=pcu0+offsu8;                                       //~va0tR~
            keyindatalen_utf8=offsu8;                              //~va0tR~
			len=lenr;                                              //~va0tR~
        }                                                          //~va0tR~
		addlen=Pstartcol-Pcurcol;    	//all cut               //~4C29I~
        if (len)                                                   //~va0tR~
        {                                                          //~va0tR~
			memcpy(pc0,pc,(UINT)len);               //~5503I~      //~va0tR~
			memcpy(pcd0,pcd,(UINT)len);              //~5503I~     //~va0tR~
			memcpy(pct0,pct,(UINT)len);                            //~va0tR~
			memcpy(pcu0,pcu,(UINT)(tgtlenu8-offsu8));              //~va0tR~
        }                                                          //~va0tR~
			memset(Pbuff+Pendcol+addlen,0,(UINT)(-addlen));     //~4C29I~//~va0tR~
			memset(Pdbcs+Pendcol+addlen,0,(UINT)(-addlen));     //~4C29I~//~va0tR~
			memset(pct0+Pendcol-Pstartcol+addlen,0,(UINT)(-addlen));//~va0tR~
			memset(pcu0+tgtlenu8-keyindatalen_utf8,0,(UINT)keyindatalen_utf8);//~va0tR~
		break;                                                  //~4C25I~
//**ctl                                                            //~va0tR~
	case CHAROPCTOL:	//clear tol(top of line)                //~5111I~
		if (Pcurcol<=Pstartcol)                                 //~5111I~
			return 4;                                           //~5111I~
        if (Pcurcol>Pendcol)                                    //~5513M~
        {                                                          //~va0tR~
			Pcurcol=Pendcol;    	//all cut                   //~5513M~
            pcu=pcu0+tgtlenu8;                                     //~va0tR~
            keyindatalen_utf8=tgtlenu8;                            //~va0tR~
        }                                                          //~va0tR~
        else                                                       //~va0tR~
        {                                                          //~va0tR~
        	xeutf_dbcssplit(0,pc0,pcu0,pct0,pcd0,lenl,&tgtlenu8,&offsu8);	//len and pos may changed by dbcs split//~va0tR~
        	pcu=pcu0+offsu8;                                       //~va0tR~
            keyindatalen_utf8=offsu8;                              //~va0tR~
        }                                                          //~va0tR~
		len=Pcurcol-Pstartcol;                                  //~5513M~
		memset(pc0,' ',(UINT)len);                  //~5111I~      //~va0tR~
		memset(pcd0,0,(UINT)len);                    //~5111I~     //~va0tR~
		memset(pct0,0,(UINT)len);                                  //~va0tR~
		memset(pcu0,' ',(UINT)keyindatalen_utf8);                  //~va0tR~
		break;                                                  //~5111I~
	}//switch by mode                                              
#ifdef FFF                                                         //~va0tR~
    if (kbdct==XEUTFCT_UTF8)	//utf8 input                       //~va0tR~
	{                                                              //~va0tR~
    	if (opt0 & CFEO_OPTCMDLINE)     //mixed fld update                             //~va0tI//~va0tR~
			UCBITON(ppc->UPCflag,UPCFCMDUTF8);  //cmdline contains utf8 code//~va0tR~
    }                                                              //~va0tR~
#endif                                                             //~va0tR~
//----------                                                       //~va0tR~
	scrclearconfirmmsg();	//clear confirmation msg               
UTRACED("OUT plc",pc0,(int)strlen(pc0));                                //~va0tR~//+vb2DR~
UTRACED("OUT pdbcs",pcd0,(int)strlen(pc0));                             //~va0tR~//+vb2DR~
UTRACED("OUT pct",pct0,(int)strlen(pc0));                               //~va0tR~//+vb2DR~
UTRACED("OUT pu8",pcu0,(int)strlen(pcu0));                                  //~va0tR~//~va0NR~//+vb2DR~
	return 0;                                                      
}//charfldeditu8                                                  //+va0tR//~va0tR~
//**************************************************               //~vaanM~
//get offset in UPCcmddatabyutf8 for cursor positioning using USDdata/USDdbcs(DDfmt)//~vaanM~
//rc -1:no ddfmt                                                   //~vaanM~
//**************************************************               //~vaanM~
int cmdlinepos2offs(int Popt,PUCLIENTWE Ppcw,UCHAR *Pputf8,UCHAR *Ppdbcs,UCHAR *Pcodetb,int Pstartcol,int Pcurcol,int Pu8len,//~vaanM~
		int *Ppu8offs,int *Ppddlen,int *Ppwidth,int *Ppaddlen)                   //~vaanM~//~vaarR~
{                                                                  //~vaanM~
	PUSCRD psd;                                                    //~vaanM~
    int rc,ucslen,offsu8,ucsctr,width;                             //~vaanM~
    char *dddbcs;                                                  //~vaanM~
    int pos,paddlen;                                               //~vaarI~
//*******************                                              //~vaanM~
	psd=Ppcw->UCWpsd+CMDLINENO;                                    //~vaanM~
    UTRACEP("cmdlinepos2offs psd=%p,flag3=%d\n",psd,psd->USDflag3);//~vaanM~
//  if (!(psd->USDflag3 & USDF3DDFMT))                             //~vaanM~//~vaarR~
	if (!UCBITCHK(Ppcw->UCWflag2,UCWF2CMDLINEDD))                  //~vaarI~
    	return -1;                                                 //~vaanM~
	dddbcs=psd->USDdbcs+Pstartcol;                                 //~vaanM~
    ucslen=psd->USDddfldlen;                                       //~vaanM~
    pos=Pcurcol-Pstartcol;                                         //~vaarI~
    if (pos>ucslen)                                                //~vaarI~
    	paddlen=pos-ucslen;                                        //~vaarI~
    else                                                           //~vaarI~
    	paddlen=0;                                                 //~vaarI~
//    pfl=psd->USDpfld;                                            //~vaanM~
//    fldwidth=pfld->UFLentry[0].UFLend-pfld->UFLentry[0].UFLstart;//~vaanM~
    rc=utfddgetucsctr(0,dddbcs,ucslen,Pcurcol-Pstartcol,&ucsctr);  //~vaanM~
    if (rc>1)	//ddfmt err                                        //~vaanM~
    	return -1;                                                 //~vaanM~
	utfctr2offs(0,Pputf8,Ppdbcs,Pcodetb,ucsctr,Pu8len,&offsu8,&width);//~vaanM~//~vaarR~
    *Ppu8offs=offsu8;                                              //~vaanM~
    *Ppddlen=ucslen;                                               //~vaanM~
    *Ppwidth=width+paddlen;                                                //~vaanM~//~vaarR~
    *Ppaddlen=paddlen;                                             //~vaarI~
    UTRACEP("cmdlinepos2offs pos=%d,ddlen=%d,u8offs=%d,width=%d,paddlen=%d\n",Pcurcol,ucslen,offsu8,width,paddlen);//~vaanM~//~vaarR~
    return rc;                                                     //~vaanM~
}//cmdlinepos2offs                                                 //~vaanM~
                                                                   //~v0avI~
#endif //UTF8SUPPH                                              //~va00I//+va0tI
