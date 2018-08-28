//*CID://+vbk9R~:                               update#= 1413;     //~vbk9R~
//*************************************************************    //~v904I~
//* xeutf.c                                                        //~v904I~
//*************************************************************    //~v904I~
//vbk9:180614 (BUG)vhex line update use UTF_GETDDUCS1,it replace when unprintable//~vbk9I~
//vbk8:180613 show ucs value for errmsg "invalid UCS4 value"(vhex line update,makeucs)//~vbk8I~
//vbk5:180611 u/v key on vhex line;correct err msg                 //~vbk5I~
//vb4c:160730 display altch for also cmdline/errmsg                //~vb4cI~
//vb49:160729 display copyword(Alt+W) for also editr panel if not ebc file//~vb49I~
//vb2L:160314 (W32) display lang on top menu by ddfmt(for the case consolecp!=system cp,cpinfo is by system cp but display is by chcp code)//~vb2LI~
//vb2G:160229 update errmsg for make ucs on cpu8 vhex line         //~vb2GI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2y:160212 save xelch utf8 for errmsg                           //~vb2yI~
//vb2v:160207 display hex dump on conversion err msg               //~vb2vI~
//vb22:160109 (BUG)vhexline csr pos did not consider dbcs split at UFCleft//~vb22I~
//            Alt+g(jump charline<->vhexline) jump +1 posision.    //~vb22I~
//vb19:151222 (BUG)drawrename abend when f2dd err                  //~vb19I~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//~vb14I~
//vax0:140625 (BUG:Win)cut&paste malloc err(corrupted memory)      //~vax0I~
//vawE:140613 (BUG)paste UTF8/EBC data to bin file,dd2l was done(lcmd copy or paste line dose not translate)//~vawEI~
//vawz:140612 (BUG)renamesave destroy ts fld                       //~vawzI~
//vawj:140605 (BUG:LNX)paste to rename fld;when l2f to katakana ct is 3 byte CTUTF8,it should be chked at l2fbyct//~vawjI~
//vawi:140603 (BUG)utf8 file pso2offs;offset may be 2 or 3 byte    //~vawiI~
//vawg:140603 exe cmd should use UD string for cmd from cpu8 file  //~vawgI~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavn:140425 (BUG of vavj)setdbcstbl required for cmdline char edit for surrogae pair 4 dbcs//~vavnI~
//vauP:140320 (BUG)GB4:Ctl+W:U8+LC  GB4LC corruppted on cmdline    //~vauPI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vau5:140228 (BUG)like as vau0,C+w/A+w and A+Ins(paste to cmdline) colomn err for germany//~vau5I~
//vau2:140227 (BUG)u8 string on cmdline;corrupted display          //~vau2I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaaq:111231 (BUG)errmsg attr:green(utf8) position shifted by l2f //~vaaqI~
//vaak:111229 (Bug)va5j: if traslated l2u for cmdline,coloumn pos changes. csrright will split local dbcs and rep to space.//~vaakI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va8f:101003 (BUG)lcmd "=" fail by tab compare(l2dd drop tab attr)//~va8fI~
//va72:100801 LP64 wchar_t is 4byte on LP64                        //~va72I~
//va5F:100521 dd2u nullrep option for wxe                          //~va5FI~
//va5s:100514 display hdr line filename by dd fmt                  //~va5sI~
//va5q:100512 SPL/TFLOW cmd support sbcs utf8 delm char            //~va5qI~
//va5j:100510 dispaly cmdline by dd fmt(more printable than locale code for Ctl+w(copy word to cmd lien).//~va5jI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3F:100313 (BUG)err rejected that SS3/GB4 input on CPU8 file when not UTF8 env(by SCIM raw code mode)//~va3FI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va3f:100205 (BUG)makeucs("U") key dose not make when top is TAB( 0x09xx case)//~va3fR~
//va34:100131 (BUG)abend at UTRACE by invalid len parm             //~va34I~
//va20:091123 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//*************************************************************    //~v904I~
#ifdef W32                                                         //~v5n1M~//~vb2LI~
    #include <windows.h>                                           //~v5n1M~//~vb2LI~
#endif                                                             //~v5n1M~//~vb2LI~
#include <time.h>                                                  //~v904I~
#include <stdio.h>                                                 //~v904I~
#include <stddef.h>                                                //~v904I~
#include <stdlib.h>                                                //~v904I~
#include <ctype.h>                                                 //~v904I~
#include <string.h>                                                //~v904I~
//*************************************************************    //~v904I~
//*******************************************************          //~v904I~
#include <ulib.h>                                                  //~v904I~
#include <uerr.h>                                                  //~v904I~
#include <uque.h>                                                  //~v904I~
#include <udbcschk.h>                                              //~v904I~
#include <ustring.h>                                               //~v904I~
#include <ufile.h>                                                 //~v904I~
#include <utf.h>                                                   //~v904I~
#include <ucvucs.h>                                                //~v904I~
#include <ucvext.h>                                                //~vb2LI~
#include <ualloc.h>                                                //~v904I~
#include <utrace.h>                                                //~v904I~
#include <utf.h>                                                   //~va20I~
#include <utf22.h>                                                 //~va20I~
#include <ukbd.h>                                                  //~va3xI~
#include <ufilew.h>                                                //~vawgI~
#include <uedit2.h>                                                //~vb2vI~
                                                                   //~v904I~
#include "xe.h"                                                    //~v904I~
#include "xescr.h"                                                 //~v904I~
#include "xefile.h"                                                //~v904I~
#include "xefile22.h"                                              //~va20I~
#include "xechar.h"                                                //~va20M~
#include "xesub.h"                                                 //~v904I~
#include "xeutf.h"                                                 //~va20I~
#include "xeutf2.h"                                                //~va20I~
#include "xeerr.h"                                                 //~va20I~
#include "xesub2.h"                                                //~va20I~
#include "xefcmd23.h"                                              //~va20I~
#include "xefsubw.h"                                               //~vavnI~
                                                                   //~v904I~
//*******************************************************          //~va1CI~
int xeutf_getvhexoffs(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos,int *Pphexoffs);//~vawiI~
#define XEUTFGVXOO_NEXT      0x01 	//when split step to next ucs  //~vawiI~
//*******************************************************          //~va10I~
                                                                   //~va10I~
#ifdef UTF8UCS2                                                    //~va20R~
//**************************************************************** //~va00I~
//!xeutf_cvf2dd                                                    //~va20R~
//utf8->locale data conversion with dbcstbl setting                //~va00I~
//rc:0,01:cv done, 0x02:dbcs,0x04:conv err                         //~va00R~
//   UALLOC failed                                                 //~va20R~
//**************************************************************** //~va00I~
int xeutf_cvf2dd(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,UCHAR **Ppdbcs,int *Ppoutlen)//~va20R~//~va5sR~
{                                                                  //~va00I~
	int opt,lenucs,buffsz,rc2,rc=0;                                //~va20R~
    char *pdbcs,*pucs;                                             //~va20R~
//****************************                                     //~va00I~
	UTRACED("xeutf_cvf2dd",Pinp,Pinplen);                          //~va20R~
#ifdef UTF8UTF16                                                   //~vaw1I~
    lenucs=(Pinplen+1/*avoid len=0*/)*UWUCSSZ;                     //~vaw1I~
#else                                                              //~vaw1I~
//  lenucs=(Pinplen+1/*avoid len=0*/)*WUCSSZ;                      //~vb14R~
    lenucs=(Pinplen+1/*avoid len=0*/)*(int)WUCSSZ;                 //~vb14I~
#endif                                                             //~vaw1I~
    buffsz=lenucs*2;	//data dbcs                                //~va20I~
    if (Popt & XEUTFCVO_SETCT)	//set                              //~vb2yI~
	    buffsz+=lenucs;	//ct                                       //~vb2yI~
	pucs=xeutf_buffget(XEUTF_BUFF2,buffsz);                        //~va20R~
	UALLOCCHK(pucs,UALLOC_FAILED);                                 //~va20R~
    pdbcs=pucs+lenucs;                                             //~va20R~
    *Ppout=pucs;                                                   //~va20I~
    *Ppdbcs=pdbcs;                                                 //~va20I~
    opt=0;                                                         //~va20I~
    if (Popt & XEUTFCVO_SETTABCHAR)                                //~va8fI~
    	opt|=UTFCVO_SETTABCHAR;                                    //~va8fI~
	if (Popt & XEUTFCVO_OUTWIDTH)  //for f2dd output width limit   //~vaaqI~
    {                                                              //~vaaqI~
    	opt|=UTFCVO_OUTWIDTH;   //return chklen if ddlen overflow  //~vaaqI~
        lenucs=*Ppoutlen;                                          //~vaaqI~
		UTRACEP("xeutf_cvf2dd OUTWIDTH=%d,rc=%d\n",lenucs);        //~vaaqI~
    }                                                              //~vaaqI~
	rc2=utfcvf2dd(opt,Pinp,Pinplen,pucs,pdbcs,lenucs,Ppoutlen);    //~va20R~
    if (rc2 & (UTFCVFDRC_UTF8|UTFCVFDRC_UTF8UNP))                  //~va20R~
    	rc|=XEUTFF2LRC_UTF8;                                       //~va20I~
    if (rc2 & UTFCVFDRC_DBCS)                                      //~va20R~
    	rc|=XEUTFF2LRC_DBCS;                                       //~va20I~
    if (rc2 & UTFCVFDRC_UTF8ERR)//contains invalidutf8 code        //~va20R~
    	rc|=XEUTFF2LRC_ERR;                                        //~va20I~
  	if (opt & UTFCVO_OUTWIDTH && rc2 & UTFCVFDRC_OVF)            //~v6btR~//~vaaqR~
    {                                                              //~vaaqI~
    	rc|=XEUTFF2LRC_WIDTHOVF;                                   //~vaaqI~
		UTRACEP("xeutf_cvf2dd ovf by chklen=%d\n",*Ppoutlen);      //~vaaqI~
    }                                                              //~vaaqI~
	UTRACEP("xeutf_cvf2dd rc2=%d,rc=%d\n",rc2,rc);                 //~va20I~
    return rc;                                                     //~va00I~
}//xeutf_cvf2dd                                                    //~va20R~
//**************************************************************** //~vb2yI~
//!xeutf_cvf2dd                                                    //~vb2yI~
//utf8->locale data conversion with dbcstbl setting                //~vb2yI~
//rc:0:all asccii,1:cv f2dd,4:err                                  //~vb2yI~
//**************************************************************** //~vb2yI~
int xeutf_cvf2ddct(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,UCHAR **Ppdbcs,UCHAR **Ppct,int *Ppoutlen)//~vb2yR~
{                                                                  //~vb2yI~
	int opt,rc2,rc=0,ddlen,ii;                                     //~vb2yR~
//  char *pdddata0,*pdddbcs0,*pct,*pct0,*pcd;                      //~vb2yR~//~vb2DR~
    UCHAR *pdddata0,*pdddbcs0,*pct,*pct0,*pcd;                     //~vb2DI~
//****************************                                     //~vb2yI~
	UTRACED("inp u8",Pinp,Pinplen);                                //~vb2yI~
    opt=Popt|XEUTFCVO_SETCT;	//malloc ct after dbcs             //~vb2yI~
	rc2=xeutf_cvf2dd(opt,Pinp,Pinplen,&pdddata0,&pdddbcs0,&ddlen); //~vb2yR~
    pct0=pdddbcs0+ddlen;                                           //~vb2yR~
    if (rc2 & ~(XEUTFF2LRC_UTF8|XEUTFF2LRC_DBCS))	//             //~vb2yR~
    	rc=4;                                                      //~vb2yI~
    else                                                           //~vb2yI~
    {                                                              //~vb2yI~
	    if (!(rc2 & XEUTFF2LRC_UTF8)) //all ascii                  //~vb2yI~
        	memset(pct0,0,(size_t)ddlen);                          //~vb2yI~
        else                                                       //~vb2yI~
        {                                                          //~vb2yI~
        	for (pcd=pdddbcs0,pct=pct0,ii=0;ii<ddlen;ii++)         //~vb2yR~
            {                                                      //~vb2yI~
            	if (*pcd++)                                        //~vb2yI~
                	*pct++=XEUTFCT_UTF8;                           //~vb2yR~
                else                                               //~vb2yI~
                	*pct++=0;                                      //~vb2yR~
            }                                                      //~vb2yI~
            rc=XEUTFCT_UTF8;                                       //~vb2yI~
        }                                                          //~vb2yI~
    }                                                              //~vb2yI~
    *Ppout=pdddata0;                                               //~vb2yR~
    *Ppdbcs=pdddbcs0;                                              //~vb2yR~
    *Ppct=pct0;                                                    //~vb2yR~
    *Ppoutlen=ddlen;                                               //~vb2yI~
	UTRACEP("%s: rc=%d rc2=%d,ddlen=%d\n",UTT,rc,rc2,ddlen);       //~vb2yI~
	UTRACED("pdddata",pdddata0,ddlen);                             //~vb2yR~
	UTRACED("pdddbcs",pdddbcs0,ddlen);                             //~vb2yR~
	UTRACED("pct",pct0,ddlen);                                     //~vb2yR~
    return rc;                                                     //~vb2yI~
}//xeutf_cvf2ddct                                                  //~vb2yI~
//**************************************************************** //~vaakI~
//!xeutf_cvf2dd_padding                                            //~vaakI~
//insert padding when shirink for l2f                              //~vaakI~
//**************************************************************** //~vaakI~
int xeutf_cvf2dd_padding(int Popt,char *Pinp,int Pinplen,UCHAR *Pdbcs,UCHAR *Pcodetb,int Plclen,UCHAR **Ppout,UCHAR **Ppdbcs,int *Ppoutlen)//~vaakR~
{                                                                  //~vaakI~
	int opt,lenucs,buffsz,rc2,rc=0;                                //~vaakI~
    char *pdbcs,*pucs;                                             //~vaakI~
	UCHAR *pc,*pcd,*pct;                                           //~vaakR~
	int lclen=0,resleno,reslenlc,reslenu8,outlen=0,ch,u8len=0,ii,paddlen;//~vaakR~
//****************************                                     //~vaakI~
	UTRACED("xeutf_cvf2dd_padding inp u8",Pinp,Pinplen);           //~vaakR~
	UTRACED("xeutf_cvf2dd_padding inp dbcs",Pdbcs,Plclen);         //~vaakI~
	UTRACED("xeutf_cvf2dd_padding inp ct",Pcodetb,Plclen);         //~vaakI~
#ifdef UTF8UTF16                                                   //~vaw1I~
    lenucs=(Pinplen+1/*avoid len=0*/)*UWUCSSZ;                     //~vaw1I~
#else                                                              //~vaw1I~
//  lenucs=(Pinplen+1/*avoid len=0*/)*WUCSSZ;                      //~vb14R~
    lenucs=(Pinplen+1/*avoid len=0*/)*(int)WUCSSZ;                 //~vb14I~
#endif                                                             //~vaw1I~
    buffsz=lenucs*2;	//data dbcs                                //~vaakI~
	pucs=xeutf_buffget(XEUTF_BUFF2,buffsz);                        //~vaakI~
	UALLOCCHK(pucs,UALLOC_FAILED);                                 //~vaakI~
    pdbcs=pucs+lenucs;                                             //~vaakI~
    *Ppout=pucs;                                                   //~vaakI~
    *Ppdbcs=pdbcs;	//out dbcs                                     //~vaakR~
    opt=0;                                                         //~vaakI~
    if (Popt & XEUTFCVO_SETTABCHAR)                                //~vaakI~
    	opt|=UTFCVO_SETTABCHAR;                                    //~vaakI~
    for(pc=Pinp,reslenu8=Pinplen,pcd=Pdbcs,pct=Pcodetb,reslenlc=Plclen,resleno=lenucs;//~vaakR~
			reslenlc>0&&reslenu8>0&&resleno>0;                     //~vaakI~
            pc+=u8len,reslenu8-=u8len,pct+=lclen,pcd+=lclen,reslenlc-=lclen,pucs+=outlen,pdbcs+=outlen,resleno-=outlen//~vaakI~
		)                                                          //~vaakI~
    {                                                              //~vaakI~
    	ch=*pc;                                                    //~vaakI~
        u8len=UTF8CHARLEN(ch);                                     //~vaakI~
        if (!u8len)                                                //~vaakI~
        {                                                          //~vaakI~
    		rc=XEUTFF2LRC_ERR; //0x40                              //~vaakI~
            break;                                                 //~vaakI~
        }                                                          //~vaakI~
        if (u8len==1)	//ascii                                    //~vaakI~
        {                                                          //~vaakI~
//      	*pucs=ch;                                              //~vaakI~//~vb14R~
        	*pucs=(char)ch;                                        //~vb14I~
            *pdbcs=0;                                              //~vaakI~
            outlen=1;                                              //~vaakI~
            lclen=1;                                               //~vaakI~
            continue;                                              //~vaakI~
        }                                                          //~vaakI~
		rc2=utfcvf2dd(opt,pc,u8len,pucs,pdbcs,resleno,&outlen);    //~vaakI~
    	if (rc2 & (UTFCVFDRC_UTF8|UTFCVFDRC_UTF8UNP))              //~vaakI~
    		rc|=XEUTFF2LRC_UTF8;                                   //~vaakI~
    	if (rc2 & UTFCVFDRC_DBCS)                                  //~vaakI~
    		rc|=XEUTFF2LRC_DBCS;                                   //~vaakI~
    	if (rc2 & UTFCVFDRC_UTF8ERR)//contains invalidutf8 code    //~vaakI~
    		rc|=XEUTFF2LRC_ERR;                                    //~vaakR~
        if (!outlen)                                               //~vaakI~
        {                                                          //~vaakI~
    		rc=XEUTFF2LRC_ERR;                                     //~vaakI~
        	break;                                                 //~vaakI~
        }                                                          //~vaakI~
        if (*pct==XEUTFCT_UTF8)	//originally utf8                  //~vaakI~
        {                                                          //~vaakI~
        	lclen=outlen;                                          //~vaakI~
        }                                                          //~vaakI~
        else                                                       //~vaakI~
        {                                                          //~vaakI~
         	if(*pcd)                                               //~vaakI~
          		lclen=XESUB_DBCSSPLITCTR(pcd,reslenlc,0);          //~vaakI~
            else                                                   //~vaakI~
            	lclen=1;                                           //~vaakI~
            paddlen=lclen-outlen;                                  //~vaakI~
            if (paddlen>0)                                         //~vaakI~
            {                                                      //~vaakI~
                for (ii=0;ii<paddlen;ii++)                         //~vaakR~
                {                                                  //~vaakR~
                    *(pucs+outlen+ii)=UDBCSCHK_PADDINGCH;          //~vaakR~
                    *(pdbcs+outlen+ii)=UDBCSCHK_PADDINGID;         //~vaakR~
                    rc|=XEUTFF2LRC_L2FPADDING;                     //~vaakR~
                }                                                  //~vaakR~
                outlen+=paddlen;                                   //~vaakI~
            }                                                      //~vaakI~
        }                                                          //~vaakI~
    }//for                                                         //~vaakI~
//  outlen=(ULONG)pucs-(ULONG)*Ppout;                              //~vaakR~//~vafkR~
//  outlen=(ULPTR)pucs-(ULPTR)*Ppout;                              //~vb14R~
    outlen=(int)((ULPTR)pucs-(ULPTR)*Ppout);                       //~vb14I~
    *Ppoutlen=outlen;                                              //~vaakI~
	UTRACEP("xeutf_cvf2dd_padding rc=%d\n",rc);                    //~vaakR~
	UTRACED("xeutf_cvf2dd_padding outucs",*Ppout,outlen);          //~vaakR~
	UTRACED("xeutf_cvf2dd_padding outdbcs",*Ppdbcs,outlen);        //~vaakR~
    return rc;                                                     //~vaakI~
}//xeutf_cvf2dd                                                    //~vaakI~
//**************************************************               //~va20I~
//*get data pos corresponding to vhex pos                          //~va20R~
//*output pos is from record top                                   //~va20R~
//rc:4:pos=eol,8,out of range,1 split sbcs ucs,2:split 2byte ucs,3:dbcs 1t byte//~va20R~
//rc:-1 split sbcs ucs4,-2:split dbcs ucs4                         //~va3xI~
//**************************************************               //~va20I~
int xeutf_getvhexpos(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Poffs,int *Ppdatapos,int *Ppdbcsid)//~va20R~
{                                                                  //~va20I~
    PUFILEC pfc;                                                   //~va20I~
	UCHAR *pdata,*pdbcs;                                           //~va20I~
	int rc,pos,ulhlen,dbcsid,offs;                                 //~va20R~
//*******************************                                  //~va20I~
	pfc=Ppcw->UCWpfc;                                              //~va20I~
	pdata=Pplh->ULHdata;                                           //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    pos=pfc->UFCleft;                                              //~va20I~
    offs=Poffs;                                                    //~va20I~
    if (Popt & XEUTFGVXOO_RECOFFS)   //Poffs is not csr pos but recoffs//~va20I~
    	offs-=pos;	//parm to utfddoffs2pos                        //~va20I~
    ulhlen=Pplh->ULHlen;                                           //~va20I~
    rc=utfddoffs2pos(UTFDDO2PO_INITPOS,pdata,pdbcs,ulhlen,offs,&pos);//~va20R~
    UTRACEP("xeutf_getvhexpos:utfddoffs2pos returned rc=%d,offs=%d,pos=%d\n",rc,offs,pos);//~va20R~
    if (rc<4)                                                      //~va20I~
		dbcsid=(int)*(pdbcs+pos);                                  //~va20I~
    else                                                           //~va20I~
    	dbcsid=0;                                                  //~va20I~
    if (Ppdbcsid)                                                  //~va20I~
	    *Ppdbcsid=dbcsid;                                          //~va20R~
    if (rc==1)	//split                                            //~va20I~
    {                                                              //~va20I~
    	if (!UDBCSCHK_ISUCSSBCS(dbcsid))                           //~va20I~
        	rc=2;		//2byte dd                                 //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    if (rc==2)	//split ucs4 at between 1st/2nd and 3rd            //~va3xI~
    {                                                              //~va3xI~
    	if (!UDBCSCHK_ISUCSSBCS(dbcsid))                           //~va3xI~
        	rc=-2;		//2byte dd                                 //~va3xI~
        else                                                       //~va3xI~
        	rc=-1;		//sbcs                                     //~va3xI~
    }                                                              //~va3xI~
    else                                                           //~va3xI~
#endif                                                             //~va3xI~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    if (UDBCSCHK_DBCS1STU(dbcsid))                                 //~va3xI~
#else                                                              //~va3xI~
    if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                           //~va20I~
#endif                                                             //~va3xI~
    	rc=3;                                                      //~va20I~
    *Ppdatapos=pos;                                                //~va20M~
    return rc;                                                     //~va20I~
}//xeutf_getvhexpos                                                //~va20I~
//**************************************************               //~va20I~
//*get vhex mode data position                                     //~va20I~
//rc:8:Ppos is out of range,4:eol,1:dbcs ucs split,0:ok            //~va20I~
//**************************************************               //~va20I~
int xeutf_getvhexoffs(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos,int *Pphexoffs)//~va20I~
{                                                                  //~va20I~
	UCHAR *pdata,*pdbcs;                                           //~va20I~
	int rc,offs,ulhlen;                                            //~va20R~
    int opt=0;                                                     //~vawiI~
//*******************************                                  //~va20I~
    pdata=Pplh->ULHdata;                                           //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    ulhlen=Pplh->ULHlen;                                           //~va20I~
//  rc=utfddpos2offs(0,pdata,pdbcs,ulhlen,Ppos,&offs);//rc:1:ucs split//~va20R~//~vawiR~
	if (Popt & XEUTFGVXOO_NEXT) 	//when split step to next ucs  //~vawiI~
    	opt|=UTFDDP2OO_NEXT;                                       //~vawiI~
    rc=utfddpos2offs(opt,pdata,pdbcs,ulhlen,Ppos,&offs);//rc:1:ucs split//~vawiI~
    *Pphexoffs=offs;                                               //~va20I~
    return rc;                                                     //~va20I~
}//xeutf_getvhexoffs                                               //~va20I~
//**************************************************               //~va20I~
//*get plh vhex offset                                             //~va20I~
//rc:offs;if outof range,add distance                              //~va20I~
//**************************************************               //~va20I~
int xeutf_plhpos2offs(int Popt,PULINEH Pplh,int Ppos)              //~va20I~
{                                                                  //~va20I~
	UCHAR *pdata,*pdbcs;                                           //~va20I~
	int /*rc,*/offs,ulhlen;                                            //~va20I~//~vaa7R~
//*******************************                                  //~va20I~
    pdata=Pplh->ULHdata;                                           //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    ulhlen=Pplh->ULHlen;                                           //~va20I~
    /*rc=*/utfddpos2offs(0,pdata,pdbcs,ulhlen,Ppos,&offs);//rc:1:ucs split//~va20I~//~vaa7R~
    return offs;                                                   //~va20I~
}//xeutf_plhpos2offs                                               //~va20I~
//**************************************************               //~va20I~
//*get vhex mode data position                                     //~va20I~
//*pos->offs:output is offset from fcleft                          //~va20I~
//*pos<-offs:output is pos from fcleft                             //~va20I~
//*rc 8: out of range,4:eol                                        //~va20R~
//*for offs->pos  1 sbcs ucs split,2:dbcs ucs split                //~va20R~
//*for offs<-pos                   2 dbcs ucs split                //~va20I~
//**************************************************               //~va20I~
int xeutf_getvhexcsrpos(int Popt,int Pvhexpsdid,PUCLIENTWE Ppcw,PULINEH Pplh,int Pcsrpos,int *Ppdatapos,int *Pphexoffs)//~va20I~
{                                                                  //~va20I~
	PUFILEC pfc;                                                   //~va20I~
	int rc,fcleft,offs1,offs,offs2,pos,rc2;                        //~va20R~
    int opt=0;                                                     //~vawiI~
//*******************************                                  //~va20I~
    if (Popt & XEUTFGVXSPO_NEXT)   //get next ucs offs when split  //~vawiI~
        opt|=XEUTFGVXOO_NEXT; 	//when split step to next ucs      //~vawiI~
    pfc=Ppcw->UCWpfc;                                              //~va20I~
    fcleft=pfc->UFCleft;                                           //~va20I~
	if (!Pvhexpsdid)	//csr is on dataline,get xoffs             //~va20R~
    {                                                              //~va20I~
        if (fcleft)                                                //~va20I~
        {                                                          //~va20I~
//          rc=xeutf_getvhexoffs(0,Ppcw,Pplh,fcleft,&offs1);//rc=1:dbcs ucs split//~va20R~//~vawiR~
            rc=xeutf_getvhexoffs(opt,Ppcw,Pplh,fcleft,&offs1);//rc=1:dbcs ucs split//~vawiI~
            if (rc>8)                                              //~va20R~
                return rc;                                         //~va20R~
            if (rc==4)                                             //~va20R~
                if (Pcsrpos)                                       //~va20R~
                    return 8;                                      //~va20R~
            if (rc==1)	//dbcs split                               //~va20R~
            {                                                      //~va20I~
			   rc=2;   //dbcs split                                //~va20I~
//             offs1++;	//drop 1st byte;by XEUTFGVXOO_NEXT         //~va20I~//~vawiR~
			    if (!(Popt & XEUTFGVXSPO_NEXT))   //get next ucs offs when split//~vb22R~
                {                                                  //~vb22R~
                //* vhexdisplay display from 2nd byte also for UCS4(3 byte dd fmt)//~vb22I~
                	offs1++;                                       //~vb22R~
                }                                                  //~vb22R~
            }                                                      //~va20I~
        }                                                          //~va20I~
        else                                                       //~va20I~
        {                                                          //~va3fR~
            offs1=0;                                               //~va20I~
            rc=0;                                                  //~va3fR~
        }                                                          //~va3fR~
    	rc2=xeutf_getvhexoffs(opt,Ppcw,Pplh,fcleft+Pcsrpos,&offs2);//~vawiI~
        if (rc2==1)  //dbcs ucs split                              //~va20I~
        {                                                          //~va20I~
//          offs2++;                                               //~va20I~//~vawiR~
			if (!(Popt & XEUTFGVXSPO_NEXT))   //get next ucs offs when split//~vb22R~
            {                                                      //~vb22R~
            	offs2++;                                           //~vb22R~
            }                                                      //~vb22R~
            rc=2;                                                  //~va20I~
        }                                                          //~va20I~
        offs=offs2-offs1;                                          //~vb22I~
        if (Pphexoffs)                                             //~va20I~
//          *Pphexoffs=offs=offs2-offs1;                           //~va20R~//~vb22R~
            *Pphexoffs=offs;                                       //~vb22I~
        if (rc2>=4)                                                //~va20R~
        	return rc2;                                            //~va20R~
UTRACEP("getvhexcsrpos D2X Popt=%x,vhexpsdid=%x,csr=%d,offs=%d,offs1=%d,offs2=%d\n",Popt,Pvhexpsdid,Pcsrpos,offs,offs1,offs2);//~vb22R~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
		rc=xeutf_getvhexpos(0,Ppcw,Pplh,Pcsrpos,&pos,0/*dbcsid*/); //~va20R~
        if (Ppdatapos)                                             //~va20I~
	        *Ppdatapos=pos-fcleft;                                 //~va20R~
UTRACEP("getvhexcsrpos X2D Popt=%x,vhexpsdid=%x,csr=%d,pos=%d\n",Popt,Pvhexpsdid,Pcsrpos,pos);//~vb22I~
    }                                                              //~va20I~
    return rc;                                                     //~va20I~
}//xeutf_getvhexcsrpos                                             //~va20I~
//**************************************************               //~va20I~
//*get vhex span corresponding data csr pos                        //~va20I~
//*rc 8: out of range,4:eol                                        //~va20I~
//**************************************************               //~va20I~
int xeutf_getvhexcsrspan(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pcsrpos1,int Pcsrpos2,int *Pphexoffs,int *Pphexspan)//~va20I~
{                                                                  //~va20I~
	int rc,rc2,rc3,offs1,offs2,span;                               //~va20I~
    int opt=0;                                                     //~vawiI~
//*******************************                                  //~va20I~
	if (Popt & XEUTFGVXCSO_NEXT)    //next when ucs split          //~vawiI~
    	opt|=XEUTFGVXSPO_NEXT;    //get next ucs offs when split   //~vawiI~
//  rc2=xeutf_getvhexcsrpos(0,0/*pos->xoffs*/,Ppcw,Pplh,Pcsrpos1,0/*datapos*/,&offs1);//~va20I~//~vawiR~
//  rc3=xeutf_getvhexcsrpos(0,0/*pos->xoffs*/,Ppcw,Pplh,Pcsrpos2,0/*datapos*/,&offs2);//~va20I~//~vawiR~
    rc2=xeutf_getvhexcsrpos(opt,0/*pos->xoffs*/,Ppcw,Pplh,Pcsrpos1,0/*datapos*/,&offs1);//~vawiI~
    rc3=xeutf_getvhexcsrpos(opt,0/*pos->xoffs*/,Ppcw,Pplh,Pcsrpos2,0/*datapos*/,&offs2);//~vawiI~
    if (offs1>offs2)                                               //~va20I~
    	rc=8;                                                      //~va20I~
    else                                                           //~va20I~
    if (rc2>=4||rc3>=4)                                            //~va20I~
    	rc=4;                                                      //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
    	rc=0;                                                      //~va20I~
    }                                                              //~va20I~
    span=offs2-offs1;                                              //~va20I~
    if (Pphexoffs)                                                 //~va20I~
	    *Pphexoffs=offs1;                                          //~va20I~
    if (Pphexspan)                                                 //~va20I~
	    *Pphexspan=span;                                           //~va20I~
UTRACEP("getvhexcsrspan pos1=%d,pos2=%d,offs=%d,span=%d\n",Pcsrpos1,Pcsrpos2,offs1,span);//~va20R~
    return rc;                                                     //~va20I~
}//xeutf_getvhexcsrspan                                            //~va20I~
//**************************************************               //~va20I~
//*get vhex span corresponding data csr pos                        //~va20I~
//*rc 8: out of range,4:eol                                        //~va20I~
//**************************************************               //~va20I~
int xeutf_getdataspan(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos1,int Ppos2,int Pwidth,int *Pppos1,int *Pppos2)//~va20I~
{                                                                  //~va20I~
	PUFILEC pfc;                                                   //~va20I~
    char *pdata,*pdbcs;                                            //~va20I~
	int rc=0,rc2,fcleft,ulhlen,opt,pos1,pos2,ipos1,ipos2;          //~va20R~
//*******************************                                  //~va20I~
    pfc=Ppcw->UCWpfc;                                              //~va20I~
    fcleft=pfc->UFCleft;                                           //~va20I~
	pdata=Pplh->ULHdata;                                           //~va20R~
	pdbcs=Pplh->ULHdbcs;                                           //~va20R~
	ulhlen=Pplh->ULHlen;                                           //~va20I~
    ipos1=Ppos1;                                                   //~va20I~
    ipos2=Ppos2;                                                   //~va20I~
    if (Popt & XEUTFGDSO_CSRPOSIN)	//output by csr pos            //~va20R~
    {                                                              //~va20I~
    	if (ipos1>=0)                                              //~va20I~
        	ipos1+=fcleft;                                         //~va20I~
    	if (ipos2>=0)                                              //~va20I~
        	ipos2+=fcleft;                                         //~va20I~
    }                                                              //~va20I~
    opt=XESUBCDSO_INCLEFT|XESUBCDSO_INCRIGHT;	//include both boundary split//~va20I~
	rc2=xesub_adjustspan(opt,pdata,pdbcs,ulhlen,ipos1,ipos2,&pos1,&pos2);//~va20R~
    if (rc2 & 4) //left out of range                               //~va20I~
    {                                                              //~va20I~
    	pos1=-1;                                                   //~va20R~
        rc=4;                                                      //~va20I~
    }                                                              //~va20I~
//    else                                                         //~va20R~
//    if (rc2 & 8) //right out of range                            //~va20R~
//    {                                                            //~va20R~
//        pos2=ulhlen;                                             //~va20R~
//    }                                                            //~va20R~
    if (Popt & XEUTFGDSO_CSRPOSOUT)	//output by csr pos            //~va20R~
    {                                                              //~va20I~
        pos1-=fcleft;                                              //~va20I~
        if (pos1<0)                                                //~va20I~
        	pos1=-1;                                               //~va20R~
        if (Pwidth && pos1>Pwidth)                                 //~va20R~
        	pos1=Pwidth;                                           //~va20R~
        pos2-=fcleft;                                              //~va20I~
        if (pos2<0)                                                //~va20I~
        	pos2=-1;                                               //~va20R~
        if (Pwidth && pos2>Pwidth)                                 //~va20R~
        	pos2=Pwidth;                                           //~va20R~
    }                                                              //~va20I~
    if (Pppos1)                                                    //~va20I~
	    *Pppos1=pos1;                                              //~va20R~
    if (Pppos2)                                                    //~va20I~
	    *Pppos2=pos2;                                              //~va20R~
UTRACEP("getdataspan rc=%d,pos1=%d,pos2=%d,width=%d,out pos1=%d,pos2=%d\n",rc,Ppos1,Ppos2,Pwidth,pos1,pos2);//~va20I~
    return rc;                                                     //~va20I~
}//xeutf_getdataspan                                               //~va20I~
//**************************************************************** //~va20I~
// get csr position for vhex mode                                  //~va20R~
//*rc   : 0:normal , 4 out of range                                //~va20I~
//**************************************************************** //~va20I~
int xeutf_getvhexcsrposdbcs(int Popt,		//lineid type          //~va20R~
							PUCLIENTWE Ppcw,                       //~va20I~
							PULINEH Pplh,   //data,dbcs,chof       //~va20I~
							int Pleft,       //left most column    //~va20I~
							int Ppos,        //csr pos from left side//~va20I~
							int *Ppcharpos1, //dataline csr pos    //~va20R~
							int *Ppcharpos2, //dataline pos for dbcs//~va20I~
							int *Pphexpos)  //hex line pos         //~va20I~
{                                                                  //~va20I~
	PUFILEC pfc;                                                   //~va20I~
//	UCHAR *pcd;                                                    //~va20I~//~vaa7R~
    int len,/*offs,*/cpos1=-1,cpos2=-1,xpos=-1,rc=0,rc2,fcleft;        //~va20R~//~vaa7R~
//*****************                                                //~va20I~
//UTRACEP("filevhexgetcsrpos entry opt=%x,Pleft=%d,pos=%d\n",Popt,Pleft,Ppos);//~va20I~
    pfc=Ppcw->UCWpfc;                                              //~va20I~
    fcleft=pfc->UFCleft;                                           //~va20I~
    if (Ppcharpos1)                                                //~va20I~
	    *Ppcharpos1=cpos1;      //for err return                   //~va20I~
    if (Ppcharpos2)                                                //~va20I~
	    *Ppcharpos2=cpos2;                                         //~va20I~
    if (Pphexpos)                                                  //~va20I~
	    *Pphexpos=xpos;                                            //~va20I~
    if (Ppos<0)     //csr is on linenofld                          //~va20I~
        return 4;                                                  //~va20I~
//  pcd=Pplh->ULHdbcs;                                             //~va20I~//~vaa7R~
    len=Pplh->ULHlen;                                              //~va20I~
    if (Pleft>=len)                                                //~va20I~
        return 4;                                                  //~va20I~
	if (Popt & (USDF2VHEXLINE1|USDF2VHEXLINE2))	//csr on hex line  //~va20I~
    {                                                              //~va20I~
//      offs=Ppos;                                                 //~va20I~//~vaa7R~
		rc2=xeutf_getvhexpos(0,Ppcw,Pplh,Ppos,&cpos1,0/*pdbcsid*/);//offset in line//~va20R~
        if (rc2>=4)	//out of range                                 //~va20I~
            return 4;                                              //~va20I~
        if (rc2==1)	//split sbcs                                   //~va20I~
        {                                                          //~va20I~
        	cpos2=cpos1;                                           //~va20I~
        }                                                          //~va20I~
        else                                                       //~va20I~
        if (rc2==2)	//split dbcs                                   //~va20I~
        	cpos2=cpos1+1;  //getvhexpos return top byte position  //~va20I~
        else                                                       //~va20I~
        if (rc2==3)	//dbcs 1st byte                                //~va20I~
        	cpos2=cpos1+1;                                         //~va20I~
        else                                                       //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
        if (rc2==-1)	//split ucs4 sbcs                          //~va3xI~
        	cpos2=cpos1;                                           //~va3xI~
        else                                                       //~va3xI~
        if (rc2==-2)	//split dbcs                               //~va3xI~
        	cpos2=cpos1+1;  //getvhexpos return top byte position  //~va3xI~
        else                                                       //~va3xI~
#endif                                                             //~va3xI~
        	cpos2=cpos1;                                           //~va20I~
    }                                                              //~va20I~
    else	//csr is on char line,get hex offs                     //~va20R~
    {                                                              //~va20I~
		rc2=xeutf_getvhexcsrpos(0,0/*pos->offs*/,Ppcw,Pplh,Ppos,0/*pos*/,&xpos);//~va20I~
        if(rc2>=4)                                                 //~va20I~
        	return 4;                                              //~va20I~
    }                                                              //~va20I~
    if (Ppcharpos1)                                                //~va20I~
	    *Ppcharpos1=cpos1-fcleft;                                  //~va20R~
    if (Ppcharpos2)                                                //~va20I~
	    *Ppcharpos2=cpos2-fcleft;                                  //~va20R~
    if (Pphexpos)                                                  //~va20I~
	    *Pphexpos=xpos;                                            //~va20I~
UTRACEP("xeutf_vhexgetcsrposdbcs cpos1=%d,cpos2=%d,xpos=%d\n",cpos1,cpos2,xpos);//~va20I~
    return rc;                                                     //~va20I~
}//xeutf_getvhexcsrposdbcs                                         //~va20R~
//**************************************************               //~va20I~
//*make ucs from 2 byte char ascii/f2lerr                          //~va20I~
//rc:4:err, -n(pad len to be deleted)                                                         //~va20I~//~va3fR~
//   8:ucs4 overflow                                               //~va3xI~
//**************************************************               //~va20I~
#ifdef UTF8UTF16                                                   //~vaw1I~
int xeutf_charmakeucsvhexdd(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UWUCS *Ppucs)//~vaw1I~
#else                                                              //~vaw1I~
int xeutf_charmakeucsvhexdd(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,WUCS *Ppucs)//~va20I~
#endif                                                             //~vaw1I~
{                                                                  //~va20I~
#ifdef UTF8UTF16                                                   //~vaw1I~
	UWUCS ucs;                                                     //~vaw1I~
#else                                                              //~vaw1I~
	WUCS ucs;                                                      //~va20I~
#endif                                                             //~vaw1I~
    int dbcsid,high,low;                                           //~va20R~
    int delpadlen=0;                                               //~va3fR~
    UCHAR *pcd,*pcde;                                              //~va3fR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    int lowucs4;                                                   //~va3xI~
#endif                                                             //~va3xI~
//***********************::                                        //~va20I~
    if (Plen<=1)                                                   //~va20M~
    	return 4;                                                  //~va20M~
    pcde=Pdbcs+Plen;                                               //~va3fR~
	dbcsid=*Pdbcs;                                                 //~va20I~
//*never called for ebcfile                                        //~va5FI~
    if (dbcsid==TABCHAR)                                           //~va20R~
    {                                                              //~va3fR~
    	high=TABCHAR;                                              //~va20I~
    	for (pcd=Pdbcs+1;pcd<pcde;pcd++)                           //~va3fR~
        {                                                          //~va3fR~
        	if (*pcd!=UDBCSCHK_TABPADCHAR)                         //~va3fR~
                break;                                             //~va3fR~
            delpadlen++;                                           //~va3fR~
        }                                                          //~va3fR~
    }                                                              //~va3fR~
    else                                                           //~va20I~
    if (dbcsid && dbcsid!=UDBCSCHK_F2LERR)                         //~va20I~
    	return 4;                                                  //~va20R~
    else                                                           //~va20I~
    	high=*Pdata;                                               //~va20I~
//  dbcsid=*(Pdbcs+1);                                             //~va20I~//~va3fR~
    pcd=Pdbcs+1+delpadlen;                                         //~va3fR~
    if (pcd>=pcde)                                                 //~va3fR~
    	return 4;                                                  //~va3fR~
    dbcsid=*pcd;                                                   //~va3fR~
    if (dbcsid==TABCHAR)                                           //~va20R~
    {                                                              //~va3fR~
    	low=TABCHAR;                                               //~va20I~
    	for (pcd++;pcd<pcde;pcd++)                                 //~va3fR~
        {                                                          //~va3fR~
        	if (*pcd!=UDBCSCHK_TABPADCHAR)                         //~va3fR~
                break;                                             //~va3fR~
            delpadlen++;                                           //~va3fR~
        }                                                          //~va3fR~
    }                                                              //~va3fR~
    else                                                           //~va20I~
    if (dbcsid && dbcsid!=UDBCSCHK_F2LERR)                         //~va20I~
    	return 4;                                                  //~va20I~
    else                                                           //~va20I~
//  	low=*(Pdata+1);                                            //~va20I~//~va3fR~
    	low=*(Pdata+1+delpadlen);                                  //~va3fR~
    ucs=(high<<8)|low;                                             //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
  	if (Popt & XEUTFCMUVXDO_UCS4)                                  //~va3xI~
  	{                                                              //~va3xI~
        pcd=Pdbcs+2+delpadlen;                                     //~va3xR~
        if (pcd>=pcde)                                             //~va3xI~
            return 4;                                              //~va3xI~
        dbcsid=*pcd;                                               //~va3xI~
        if (dbcsid==TABCHAR)                                       //~va3xI~
        {                                                          //~va3xI~
            lowucs4=TABCHAR;                                       //~va3xI~
            for (pcd++;pcd<pcde;pcd++)                             //~va3xI~
            {                                                      //~va3xI~
                if (*pcd!=UDBCSCHK_TABPADCHAR)                     //~va3xI~
                    break;                                         //~va3xI~
                delpadlen++;                                       //~va3xI~
            }                                                      //~va3xI~
        }                                                          //~va3xI~
        else                                                       //~va3xI~
        if (dbcsid && dbcsid!=UDBCSCHK_F2LERR)                     //~va3xI~
            return 4;                                              //~va3xI~
        else                                                       //~va3xI~
            lowucs4=*(Pdata+2+delpadlen);                          //~va3xI~
        ucs=(ucs<<8)|lowucs4;                                      //~va3xI~
        if (ucs>UCS4_MAX)  //over 10ffff                           //~va3xR~
        {                                                          //~va3xI~
//          uerrmsg("invalid UCS4 value max is %06x",0,            //~va3xI~//~vbk8R~
//                   UCS4_MAX);                                    //~va3xI~//~vbk8R~
            uerrmsg("invalid UCS4 value(%06x) max is %06x",0,      //~vbk8I~
                     ucs,UCS4_MAX);                                //~vbk8I~
            return 8;                                              //~va3xR~
        }                                                          //~va3xI~
  	}//UCS4                                                        //~va3xI~
#endif                                                             //~va3xI~
    *Ppucs=ucs;                                                    //~va20I~
//  return 0;                                                      //~va20I~//~va3fR~
    return -delpadlen;                                             //~va3fR~
}//xeutf_charmakeucsvhexdd                                         //~va20I~
//**************************************************               //~va20I~
//*get vhex update new data for REP/INS mode                       //~va20R~
//rc:4:err,1:insert split ucs                                      //~va20R~
//**************************************************               //~va20I~
int xeutf_chargetvhexdd(int Popt,int Pvhexmode,PUCLIENTWE Ppcw,PULINEH Pplh,int Precoffs,//~va20R~
					UCHAR *Pdata,UCHAR *Pdbcs,int *Pplen,int *Ppdatapos)//~va20I~
{                                                                  //~va20I~
	UCHAR *keyindata,*pdata,*pdbcs,*pnewch=0;                      //~vaf9R~
	int keyindatalen,rc=0,mode,pos,rc2,oldvalue,ddlen,opt;         //~va20R~
    int dbcsid,ucssw=0,rlen,chszo=1,makeucssw;                     //~va20R~
    int delpadlen=0;                                               //~va3fR~
#ifdef UTF8UTF16                                                   //~vaw3I~
    UWUCS ucs,newucs=0;                                            //~vaw3I~
#else                                                              //~vaw3I~
    WUCS ucs,newucs=0;                                             //~vaf9R~
#endif                                                             //~vaw3I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    UCHAR ucsbe[4];                                                //~va3xI~
    int makeucssw4;                                                //~va3xI~
#else                                                              //~va3xI~
    UCHAR ucsbe[2];                                                //~va20I~
#endif                                                             //~va3xI~
//*******************************                                  //~va20I~
    opt=XEUTFGVXOO_RECOFFS;    //Poffs is not csr pos but recoffs  //~va20I~
	rc2=xeutf_getvhexpos(opt,Ppcw,Pplh,Precoffs,&pos,&dbcsid);     //~va20R~
	mode=Popt & 0xff;	//ins/rep                                  //~va20I~
	pdata=Pplh->ULHdata;                                           //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    rlen=Pplh->ULHlen-pos;                                         //~va20R~
    pdata+=pos;                                                    //~va20I~
    pdbcs+=pos;                                                    //~va20I~
    keyindata=Ppcw->UCWkeydata;                                    //~va20I~
    keyindatalen=Ppcw->UCWkeytype;                                 //~va20I~
    makeucssw=(keyindatalen==1 && toupper(*keyindata)==CHAR_MAKEUCS);//~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    makeucssw4=(keyindatalen==1 && toupper(*keyindata)==CHAR_MAKEUCS4);//~va3xI~
#endif                                                             //~va3xI~
    if (makeucssw)                                                 //~va20I~
    {                                                              //~va20I~
    	if (rc2<4 && rlen>1)                                       //~va20I~
        {                                                          //~va3fR~
        	rc2=xeutf_charmakeucsvhexdd(0,pdata,pdbcs,rlen,&newucs);//~va20I~
            if (rc2<0)                                             //~va3fR~
            {                                                      //~va3fR~
                delpadlen=-rc2;                                    //~va3fR~
                rc2=0;                                             //~va3fR~
            }                                                      //~va3fR~
        }                                                          //~va3fR~
        else                                                       //~va20I~
        	rc2=4;                                                 //~va20I~
        if (rc2)                                                   //~va20I~
//      	uerrmsg("invalid csr position for \"u\" key(MakeUcs) on hex line; valid only for ascii or error chars",0);//~va20I~//~va3xR~//~vb2GR~
//          uerrmsg("csr position err for \"u\" key(Make UCS2) on hex line; valid only on 2 column ascii or error chars",//~vb2GI~//~vbk5R~
//                  "\"u\"キー(UCS2 生成)は2桁\"?\"\x95\\示かASCII文字位置のヘキサ\x95\\示行でのみ入力できます");//~vb2GI~//~vbk5R~
            uerrmsg("csr position err for \"u\" key(Make UCS2) on hex line, length<2 or already part of unicode.",//~vbk5I~
                    "\"u\"キー(UCS2 生成)カー\x83\\ル位置エラー(残り１桁かすでに\x8d\\成済み)");//~vbk5R~
        ucssw=1;                                                   //~va20I~
        chszo=2;                                                   //~va20I~
        chszo+=delpadlen;       //add tab padding tobe deleted     //~va3fR~
        if (mode==CHAROPINS)    //insert mode                      //~va20I~
        {                                                          //~va20I~
        	mode=CHAROPREP;                                        //~va20I~
            rc|=XEUTF_VHEXRC_INSREP;//insert changed to rep        //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    if (makeucssw4)                                                //~va3xI~
    {                                                              //~va3xI~
    	if (rc2<4 && rlen>2)  //3byte for ucs4                     //~va3xI~
        {                                                          //~va3xI~
        	opt=XEUTFCMUVXDO_UCS4;                                 //~va3xI~
        	rc2=xeutf_charmakeucsvhexdd(opt,pdata,pdbcs,rlen,&newucs);//~va3xI~
            if (rc2<0)                                             //~va3xI~
            {                                                      //~va3xI~
                delpadlen=-rc2;                                    //~va3xI~
                rc2=0;                                             //~va3xI~
            }                                                      //~va3xI~
        }                                                          //~va3xI~
        else                                                       //~va3xI~
        	rc2=4;                                                 //~va3xI~
        if (rc2==8)     //rc=8 max ucs4 over,msg issued already    //~va3xR~
        	rc|=XEUTF_VHEXRC_ERR_UCS4;                             //~va3xI~
        else                                                       //~va3xI~
        if (rc2)     //rc=8 max ucs4 over,msg issued already       //~va3xI~
//      	uerrmsg("invalid csr position for \"%c\" key(Make UCS4) on hex line",0,//~va3xI~//~vb2GR~
//          uerrmsg("invalid csr position for \"%c\" key(Make UCS4) on hex line,valid on ly on 3 column \"?\" or ascii.",//~vb2GI~//~vbk5R~
//                  "\"%c\"キー(UCS4 生成)は3桁の\"?\"\x95\\示かASCII文字上でなればなりません",//~vb2GI~//~vbk5R~
            uerrmsg("csr position err for \"%c\" key(Make UCS4) on hex line, length<4 or already part of unicode.",//~vbk5I~
                    "\"%c\"キー(UCS4 生成)カー\x83\\ル位置エラー(残り<３桁かすでに\x8d\\成済み)",//~vbk5R~
    				CHAR_MAKEUCS4);                                //~va3xI~
        ucssw=-1;                                                  //~va3xI~
        if (mode==CHAROPINS)    //insert mode                      //~va3xI~
        {                                                          //~va3xI~
        	mode=CHAROPREP;                                        //~va3xI~
            rc|=XEUTF_VHEXRC_INSREP;//insert changed to rep        //~va3xI~
        }                                                          //~va3xI~
    }//makeucs4                                                    //~va3xR~
    else                                                           //~va3xI~
#endif                                                             //~va3xI~
    {                                                              //~va20I~
        pnewch=ucsbe;                                              //~va20R~
        if (rc2>4)  //out of range;                                //~va20R~
            oldvalue=-1;                                           //~va20R~
        else                                                       //~va20R~
        if (rc2==4)                                                //~va20R~
            oldvalue=0;                                            //~va20R~
        else                                                       //~va20R~
        {                                                          //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
            if (mode==CHAROPINS                                    //~va3xI~
            &&  (rc2==1||rc2==2||rc2==-1||rc2==-2)                 //~va3xI~
            )                                                      //~va3xI~
#else                                                              //~va3xI~
            if (mode==CHAROPINS && (rc2==1||rc2==2))    //insert split ucs//~va20R~
#endif                                                             //~va3xI~
            {                                                      //~va20R~
                mode=CHAROPREP;                                    //~va20R~
                rc|=XEUTF_VHEXRC_INSREP;//       0x01 //insert changed to rep because insert split ucs2//~va20R~
            }                                                      //~va20R~
            if (mode==CHAROPREP)                                   //~va20R~
            {                                                      //~va20R~
                ucssw=UDBCSCHK_ISUCSDBCST(dbcsid);                 //~va20R~
                if (ucssw)                                         //~va20R~
                {                                                  //~va20R~
                    if (!UDBCSCHK_ISUCSSBCS(dbcsid))               //~va20R~
                        chszo=2;        //old char is 2 column     //~va20R~
//                  ucs=UTF_GETDDUCS1(pdata,pdbcs,rlen);           //~va20R~//~vbk9R~
					ucs=utfdd2u1chsz(0,pdata,pdbcs,rlen,0/*chsz*/);//+vbk9R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                  if (UTF_ISUCS4(ucs))                             //~va3xI~
                  {//UCS4                                          //~va3xI~
                  	ucssw=-1;	//ucs4 id                          //~va3xI~
                    UTF_SETUCS4TOBESTR(ucs,ucsbe);                 //~va3xI~
                    if (rc2==1||rc2==2)   //split after 1st byte of ucs4//~va3xI~
                    {                                              //~va3xI~
                        pnewch=ucsbe+1;                            //~va3xI~
                        oldvalue=*pnewch;                          //~va3xI~
                    }                                              //~va3xI~
                    else                                           //~va3xI~
                    if (rc2==-1||rc2==-2)    //after 2nd byte of ucs4//~va3xR~
                    {                                              //~va3xI~
                        pnewch=ucsbe+2;                            //~va3xI~
                        oldvalue=*pnewch;                          //~va3xI~
                    }                                              //~va3xI~
                    else                                           //~va3xI~
                    {                                              //~va3xI~
                        pnewch=ucsbe;                              //~va3xI~
                        oldvalue=*pnewch;                          //~va3xI~
                    }                                              //~va3xI~
                  }//UCS4                                          //~va3xI~
                  else                                             //~va3xI~
#endif                                                             //~va3xI~
                  {//UCS2                                          //~va3xI~
//                  ucsbe[0]=ucs>>8;                               //~va20R~//~vb14R~
                    ucsbe[0]=(UCHAR)(ucs>>8);                      //~vb14I~
//                  ucsbe[1]=ucs & 0xff;  //low value              //~vb14R~
                    ucsbe[1]=(UCHAR)(ucs & 0xff);  //low value     //~vb14I~
                    if (rc2==1||rc2==2)    //split ucs             //~va20R~
                    {                                              //~va20R~
                        pnewch=ucsbe+1;                            //~va20R~
                        oldvalue=*pnewch;                          //~va20R~
                    }                                              //~va20R~
                    else                                           //~va20R~
                    {                                              //~va20R~
                        pnewch=ucsbe;                              //~va20R~
                        oldvalue=*pnewch;                          //~va20R~
                    }                                              //~va20R~
                  }//UCS2                                          //~va3xI~
                }                                                  //~va20R~
                else    //ascii of f2err                           //~va20R~
                {                                                  //~va20R~
                    oldvalue=*pdata;                               //~va20R~
//*never called for ebcfile                                        //~va5FI~
                    if (dbcsid==TABCHAR)                           //~va20I~
                        oldvalue=TABCHAR;                          //~va20I~
                }                                                  //~va20R~
            }                                                      //~va20R~
            else    //insert                                       //~va20R~
            {                                                      //~va20R~
                dbcsid=0;                                          //~va20I~
                oldvalue=0;                                        //~va20R~
                pnewch=ucsbe;                                      //~va20R~
            }                                                      //~va20R~
        }                                                          //~va20R~
//      rc2=filecharhexinput_v(keyindata,keyindatalen,oldvalue,mode,Pvhexmode,pnewch);//~va3TR~
        rc2=filecharhexinput_v(Ppcw,keyindata,keyindatalen,oldvalue,mode,Pvhexmode,pnewch);//~va3TI~
    }//not make ucs                                                //~va20I~
    ddlen=0;                                                       //~va34I~
    if (!rc2)                                                      //~va20R~
    {                                                              //~va20R~
        if (ucssw)	//rep ucs                                      //~va20R~
        {                                                          //~va20R~
        	if (!makeucssw)                                        //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
        	if (!makeucssw4)	//not make ucs4                    //~va3xI~
#endif                                                             //~va3xI~
            {                                                      //~va3xI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
			  if (ucssw<0)	//UCS4                                 //~va3xR~
	            newucs=UTF_GETUCS4FROMBESTR(ucsbe);                //~va3xI~
              else                                                 //~va3xI~
#endif                                                             //~va3xI~
	            newucs=(ucsbe[0]<<8)|ucsbe[1];                     //~va20R~
            }                                                      //~va3xI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
          if (newucs>UCS4_MAX)  //over 10ffff                      //~va3xI~
          {                                                        //~va3xI~
//          uerrmsg("invalid UCS4 value max is %06x",0,            //~va3xI~//~vbk8R~
//                   UCS4_MAX);                                    //~va3xI~//~vbk8R~
            uerrmsg("invalid UCS4 value(%06x) max is %06x",0,      //~vbk8I~
                     newucs,UCS4_MAX);                             //~vbk8I~
        	rc|=XEUTF_VHEXRC_ERR|XEUTF_VHEXRC_ERR_UCS4;//          0x80 //err//~va3xI~
          }                                                        //~va3xI~
          else                                                     //~va3xI~
#endif                                                             //~va3xI~
#ifdef UTF8UTF16                                                   //~vaw1I~
            utfcvu2dd1wUCS4(0,newucs,Pdata,Pdbcs,&ddlen);          //~vaw1R~
#else                                                              //~vaw1I~
            utfcvu2dd1(0,newucs,Pdata,Pdbcs,&ddlen);               //~va20R~
#endif                                                             //~vaw1I~
        }                                                          //~va20R~
        else                                                       //~va20R~
        {                                                          //~va20R~
            ddlen=1;                                               //~va20M~
            *Pdata=*pnewch;                                        //~va20I~
            if (dbcsid==TABCHAR)                                   //~va20I~
            	dbcsid=0;                                          //~va20I~
//          *Pdbcs=dbcsid; //keep ascii or f2l err                 //~va20I~//~vb14R~
            *Pdbcs=(UCHAR)dbcsid; //keep ascii or f2l err          //~vb14I~
            if (!dbcsid	//old is ascii                             //~va20I~
            &&  !UTF8ISASCII(*pnewch)                              //~va20I~
			)                                                      //~va20I~
            {                                                      //~va20I~
//#ifdef AAA                                                         //~va20I~//~vaw1R~
//                newucs=*pnewch;                                    //~va20I~//~vaw1R~
//                utfcvu2dd1(0,newucs,Pdata,Pdbcs,&ddlen);//chnage to ucs//~va20I~//~vaw1R~
//#else       //not geenarate ucs but err expecting make ucs later   //~va20I~//~vaw1R~
                *Pdbcs=UDBCSCHK_F2LERR;                            //~va20I~
//#endif                                                             //~va20I~//~vaw1R~
            }                                                      //~va20I~
                                                                   //~va20I~
        }                                                          //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
      if (makeucssw4)                                              //~va3xI~
      {                                                            //~va3xI~
		rc|=XEUTF_VHEXRC_UCS4;  //replace 3 byte                   //~va3xM~
        ddlen|=(delpadlen<<8);                                     //~va3xI~
      }                                                            //~va3xI~
      else                                                         //~va3xI~
#endif                                                             //~va3xI~
      {//not makeucs4                                              //~va3xI~
        if (chszo>2)   //over 2 if padding deleted                 //~va3fR~
			rc|=XEUTF_VHEXRC_D2S;//                                //~va3fR~
        else                                                       //~va3fR~
        if (ddlen==1)                                              //~va20I~
        {                                                          //~va20I~
        	if (chszo==2)                                          //~va20I~
		        rc|=XEUTF_VHEXRC_D2S;//                            //~va20I~
        }                                                          //~va20I~
        else                                                       //~va20I~
        {                                                          //~va20I~
        	if (chszo==1)                                          //~va20I~
		        rc|=XEUTF_VHEXRC_S2D;//                            //~va20I~
        }                                                          //~va20I~
      }//not makeucs4                                              //~va3xI~
    }                                                              //~va20R~
    else                                                           //~va20I~
        rc|=XEUTF_VHEXRC_ERR;//          0x80 //err                //~va20R~
    if (Ppdatapos)                                                 //~va20M~
    	*Ppdatapos=pos;                                            //~va20M~
    if (Pplen)                                                     //~va20I~
    	*Pplen=ddlen;                                              //~va20I~
//  UTRACEP("getvhexdd olducs=%04x,newucs=%04x,datalen=%d\n",ucs,newucs,ddlen);//~vaf9R~
    UTRACED("getvhexdd data",Pdata,ddlen);                         //~va20R~
    UTRACED("getvhexdd dbcs",Pdbcs,ddlen);                         //~va20R~
    return rc;                                                     //~va20I~
}//xeutf_chargetvhexdd                                             //~va20R~
//**************************************************               //~va20M~
//*get kbd input by ucs                                            //~va20M~
//rc:4:err,0:ascii,1:sbcs,2:dbcs                                   //~va20M~
//**************************************************               //~va20M~
int xeutf_chargetkbddd(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata,UCHAR *Pdbcs,int *Pplen)//~va20I~
{                                                                  //~va20M~
	UCHAR *keyindata;                                              //~va20M~
	int keyindatalen,opt,chklen,rc;                                //~va20M~
//  ULONG ucs;                                                     //~va20M~//~va72R~
    UWUCS ucs;                                                     //~va72I~
#ifdef UTF8UTF16                                                   //~vaw1I~
    UWUCS wucs;	//INT4                                             //~vaw1I~
#else                                                              //~vaw1I~
    WUCS wucs;                                                     //~va20I~
#endif                                                             //~vaw1I~
//*******************************                                  //~va20M~
	keyindata=Ppcw->UCWkeydata;                                    //~va20M~
	keyindatalen=Ppcw->UCWkeytype;                                 //~va20M~
    UTRACEP("getkbddd input localecode len=%d,%02x%02x\n",keyindatalen,*keyindata,*(keyindata+1));//~va20M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    if (keyindatalen==1 && UTF8ISASCII(*keyindata)                 //~va3xI~
        && !UCBITCHK(Ppcw->UCWnls,KBDNLS_F2L_ERR)                  //~va3xI~
    )                                                              //~va3xI~
#else                                                              //~va3xI~
    if (keyindatalen==1 && UTF8ISASCII(*keyindata))                //~va20R~
#endif                                                             //~va3xI~
    {                                                              //~va20I~
        *Pdata=*keyindata;                                         //~va20I~
        *Pdbcs=0;                                                  //~va20I~
        *Pplen=1;                                                  //~va20I~
    	rc=0;                                                      //~va20M~
    }                                                              //~va20I~
    else                                                           //~va20M~
    if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBD))                 //~v79RR//~va20I~
    {                                                              //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    	if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBDUCS4)) //3byte input                //~v79RR//~va3xI~
            wucs=UTF_GETUCS4FROMBESTR(keyindata);                  //~va3xI~
        else                                                       //~va3xI~
#endif                                                             //~va3xI~
        if (keyindatalen==2)    //2byte input                      //~va20I~
            wucs=UTF_GETUCSDBCS(keyindata);                        //~va20R~
        else                                                       //~va20I~
        	wucs=*keyindata;                                       //~va20R~
#ifdef UTF8UTF16                                                   //~vaw1I~
         utfcvu2dd1wUCS4(0,wucs,Pdata,Pdbcs,Pplen);                //~vaw1R~
#else                                                              //~vaw1I~
         utfcvu2dd1(0,wucs,Pdata,Pdbcs,Pplen);                     //~va20R~
#endif                                                             //~vaw1I~
         rc=UTF8ISASCII(wucs)==0;                                     //~vaf8I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20M~
    	rc=1;                                                      //~va20M~
        if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))  //kbdinput by utf8 str//~va20M~
        {                                                          //~va20M~
            keyindata=Ppcw->UCWkeydata_utf8str;                    //~va20M~
//          keyindatalen=strlen(keyindata);                        //~vb14R~
            keyindatalen=(int)strlen(keyindata);                   //~vb14I~
    		UTRACEP("getkbddd input is utf8str %s\n",keyindata);   //~va20M~
        }                                                          //~va20M~
        else                                                       //~va20M~
        {                                                          //~va20M~
#ifdef UTF8SUPPH                                                   //~va3FI~
    		if (Ppcw->UCWnls & KBDNLS_SS3)                         //~va3FI~
        		keyindatalen=UDBCSCHK_SS3SZ;                       //~va3FI~
    		else                                                   //~va3FI~
    		if (Ppcw->UCWnls & KBDNLS_GB4)                         //~va3FI~
        		keyindatalen=UDBCSCHK_GB4SZ;                       //~va3FI~
#endif                                                             //~va3FI~
            opt=XEUTFCVO_STRZ|XEUTFCVO_OUTPARM|XEUTFCVO_NOERRREP|XEUTFCVO_CPU8;//~va20M~
            if (xeutf_cvdata(opt,keyindata,keyindatalen,&keyindata,&keyindatalen))//~va20M~//~va5sR~
            {                                                      //~va20M~
            	int printlen;                                      //~vb2vR~
                char wkedit[9];                                    //~vb2vI~
            	uxdumpstr(UXDSO_OUTSTRZ,keyindata,keyindatalen,wkedit,(int)sizeof(wkedit),&printlen);//~vb2vR~
//              uerrmsg("Kbd char translation to UTF8 failed for \"%s\"",0,//~va20M~//~vb2vR~
//                          keyindata);                            //~va20M~//~vb2vR~
                uerrmsg("Kbd char translation to UTF8 failed for \"%s\"(0x%s)",0,//~vb2vI~
                            keyindata,wkedit);                     //~vb2vI~
                return 4;                                          //~va20M~
            }                                                      //~va20M~
        }                                                          //~va20M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
		if (uccvutf2ucs(UCVUCS_UCS4,keyindata,keyindatalen,&ucs,&chklen))//UCS2//~va3xI~
#else                                                              //~va3xI~
		if (uccvutf2ucs(0,keyindata,keyindatalen,&ucs,&chklen))//UCS2//~va20M~
#endif                                                             //~va3xI~
        {                                                          //~va20M~
            uerrmsg("Not supported unicode range UTF8 code(%s)",0, //~va20M~//~vb2vR~
                            keyindata);                            //~va20M~//~vb2vR~
        	return 4;                                              //~va20M~
        }                                                          //~va20M~
        if (utfcvf2dd(0,keyindata,keyindatalen,Pdata,Pdbcs,2,Pplen)>=UTFCVFDRC_ERR) //get dd fmt//~va20R~
        {                                                          //~va20R~
            uerrmsg("Not supported unicode range UTF8 code--(%s)",0,//~va20R~
                                keyindata);                        //~va20R~
            return 4;                                              //~va20R~
        }                                                          //~va20R~
    }                                                              //~va20M~
    if (rc)	//not ascii                                            //~va20M~
    	rc=*Pplen;	//sbcs or dbcs                                 //~va20M~
    UTRACEP("getkbddd rc=%d,len=%d,data=%02x%02x,dbcs=%02x%02x\n",rc,*Pplen,*Pdata,*(Pdata+1),*Pdbcs,*(Pdbcs+1));//~va20M~
    return rc;                                                     //~va20M~
}//xeutf_chargetkbddd                                              //~va20I~
//**************************************************               //~va20M~
//!from mixed string to dd str                                     //~va20M~
//chk cmdbuff at first to chk codetype                             //~va20I~
//**************************************************               //~va20M~
int xeutfgetddstr(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pddstr,int Pbuffsz,int *Ppddstrlen,UCHAR *Pdbcs)//~va20I~
{                                                                  //~va20M~
    UCHAR  *pddw,*pdbcsw,*plc,*pct,*pcd;                           //~va20I~//~va5sR~
    int opt,lclen,u8len,outlen,len;                                //~va20R~
    char wku8[MAXCOLUMN*UTF8_MAXCHARSZ];                           //~va20M~
    char wklc[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va20M~
//**************************************************               //~va20M~
	lclen=fcmdsearchoncmdbuff(0,Pstr,Pstrlen,&plc,&pct,&pcd);//search Gcvmdbuffu8//~va20M~
    if (lclen)	//string remains on cmd buff                       //~va20M~
    {                                                              //~va20M~
		if (xeutf_cvl2fbyct(0,Pstr,Pstrlen,pcd,pct,lclen,wku8,sizeof(wku8),&u8len)==UALLOC_FAILED)//~va20M~
        	return UALLOC_FAILED;                                  //~va20M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		if (Popt & XEUTFGDDS_SAVECT)                               //~va50I~
        {                                                          //~va50I~
	        opt=FCSCFEMO_SAVECT;                                   //~va50I~
	    	fcmd_savelcctforerrmsg(opt,0/*word1*/,Pstr,Pstrlen,&pct,&pcd,lclen);//~va50R~
        }                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va20M~
    else                                                           //~va20M~
    {                                                              //~va20M~
        opt=0;                                                     //~va20M~
		if (xeutf_getmixedstr(opt,Pstr,Pstrlen,wklc,0/*pdbcs*/,0/*codetype*/,sizeof(wklc),0/*outlclen*/,wku8,sizeof(wku8),&u8len)==UALLOC_FAILED)//~va20R~
        	return UALLOC_FAILED;                                  //~va20M~
    }                                                              //~va20M~
	if (xeutf_cvf2dd(0,wku8,u8len,&pddw,&pdbcsw,&outlen)>=4)       //~va20M~
    	return 4;                                                  //~va20R~
    len=min(Pbuffsz,outlen);                                       //~va20M~
    memcpy(Pddstr,pddw,(UINT)len);                                 //~va20M~
    memcpy(Pdbcs,pdbcsw,(UINT)len);                                //~va20M~
    if (Ppddstrlen)                                                //~va20I~
    	*Ppddstrlen=len;                                           //~va20I~
UTRACED("xeutfgetddstr inp",Pstr,Pstrlen);                         //~va20I~
UTRACED("xeutfgetddstr out ddstr",Pddstr,len);                     //~va20I~
UTRACED("xeutfgetddstr out dbcs",Pdbcs,len);                       //~va20I~
    return 0;                                                      //~va20M~
}//*xeutfgetddstr                                                  //~va20I~
//**************************************************               //~va5jI~
//!from mixed string to dd str using codetbl                       //~va5jI~
//rc:UALLOC_FAILED,8:err,4:cut,1:utf8 detected,2:dbcs detected                                                 //~va5jI~//~va5sR~
//**************************************************               //~va5jI~
int xeutfcvlf2dd(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pdbcs,UCHAR *Pcodetbl,int Plclen,//~va5jI~
					UCHAR **Ppdddata,UCHAR **Ppdddbcs,int Pbuffsz,int *Ppddstrlen)//~va5jR~
{                                                                  //~va5jI~
    UCHAR  *pddw,*pdbcsw;                                           //~va5jR~//~va5sR~
    int u8len,outlen,rc=0;                                         //~va5jR~
    char wku8[MAXCOLUMN*UTF8_MAXCHARSZ];                           //~va5jI~
    int opt=0;                                                     //~vawjI~
    int swerr=0;                                                   //~vb19I~
//**************************************************               //~va5jI~
	if (Popt & XEUTFLF2DO_CHKLCLENBYF2L)   //advance ct by the length of F2L outlen//~vawjI~
    	opt|=XEUTFL2FBCO_CHKLCLENBYF2L;   //advance ct by the length of F2L outlen//~vawjI~
//  if (xeutf_cvl2fbyct(0,Pstr,Pstrlen,Pdbcs,Pcodetbl,Plclen,wku8,sizeof(wku8),&u8len)==UALLOC_FAILED)//~va5jI~//~vawjR~
    if (xeutf_cvl2fbyct(opt,Pstr,Pstrlen,Pdbcs,Pcodetbl,Plclen,wku8,sizeof(wku8),&u8len)==UALLOC_FAILED)//~vawjI~
        return UALLOC_FAILED;                                      //~va5jI~
  if (Popt & XEUTFLF2DO_PADDING)                                   //~vaakI~
  {                                                                //~vaakI~
	if ((rc=xeutf_cvf2dd_padding(0,wku8,u8len,Pdbcs,Pcodetbl,Plclen,&pddw,&pdbcsw,&outlen)) & XEUTFF2LRC_ERR)//~vaakR~
//  	return 8;                                                  //~vaakI~//~vb19R~
    	swerr=1;    //set outbuff addr even when cv err            //~vb19I~
  }                                                                //~vaakI~
  else                                                             //~vaakI~
  {                                                                //~vaakI~
	if ((rc=xeutf_cvf2dd(0,wku8,u8len,&pddw,&pdbcsw,&outlen)) & XEUTFF2LRC_ERR)//~va5sR~
//  	return 8;                                                  //~va5jI~//~va5sR~//~vb19R~
    	swerr=1;    //set outbuff addr even when cv err            //~vb19I~
  }                                                                //~vaakI~
  if (swerr)                                                       //~vb19I~
    rc=8;                                                          //~vb19I~
  else                                                             //~vb19I~
  {                                                                //~vb19I~
    rc &= (XEUTFF2LRC_UTF8/*1*/|UTFCVFDRC_DBCS/*2*/) ;             //~va5sI~
    if (Pbuffsz && Pbuffsz<outlen)                                 //~va5jI~
    {                                                              //~va5jI~
    	outlen=Pbuffsz;                                            //~va5jI~
//      if (UDBCSCHK_DBCS2NDU(*(pdbcsw+outlen-1)))                 //~va5jI~//~va5sR~
        if (UDBCSCHK_DBCS2NDU(*(pdbcsw+outlen)))                   //~va5sI~
        	outlen--;                                              //~va5jI~
    	rc=4;	//cut rc                                           //~va5jI~//~va5sR~
    }                                                              //~va5jI~
  }                                                                //~vb19I~
    *Ppddstrlen=outlen;                                            //~va5jR~
    *Ppdddata=pddw;                                                //~va5jI~
    *Ppdddbcs=pdbcsw;                                              //~va5jI~
    return rc;                                                      //~va5jI~//~va5sR~
}//*xeutfcvlf2dd                                                   //~va5jI~
//**************************************************               //~vaaqI~
//!from mixed string to dd str using codetbl                       //~vaaqI~
//rc:UALLOC_FAILED,1:utf8 detected                                 //~vaaqR~
//**************************************************               //~vaaqI~
int xeutfcvlf2dd_updatect(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Pdbcs,UCHAR *Pcodetbl,int Plclen,//~vaaqI~
					UCHAR **Ppdddata,UCHAR **Ppdddbcs,int Pbuffsz,int *Ppddstrlen)//~vaaqI~
{                                                                  //~vaaqI~
    UCHAR  *pc,*pcd,*pddw,*pdbcsw,*pwkdddata,*pwkdddbcs,*pwkddct,*pct,*pdddata,*pdddbcs;//~vaaqR~
    UCHAR  *pddct;                                                 //~vaaqR~
    int u8len,outlen,rc=0,buffsz,resleno,reslenu8,reslenlc,lclen,ctlen;//~vaaqR~
    int opt,u8width,rc2;                                           //~vaaqR~
    int u8cvlen;                                                   //~vau2I~
//**************************************************               //~vaaqI~
    UTRACED("xeutfcvlf2dd_updatect inp",Pstr,Pstrlen);             //~vaaqI~
    UTRACED("xeutfcvlf2dd_updatect dbcs",Pdbcs,Plclen);            //~vaaqI~
    UTRACED("xeutfcvlf2dd_updatect ct",Pcodetbl,Plclen);           //~vaaqI~
	buffsz=Plclen*2;      //max dd char=2,data & dbcs              //~vaaqI~
    pwkdddata=xeutf_buffget(XEUTF_BUFFMIXWORD,buffsz*3);           //~vaaqI~
    pwkdddbcs=pwkdddata+buffsz;                                    //~vaaqI~
    pwkddct=pwkdddbcs+buffsz;                                      //~vaaqI~
//  resleno=buffsz;                                                //~vaaqR~
    resleno=min(buffsz,Pbuffsz);                                   //~vaaqI~
    opt=XEUTFCVO_OUTWIDTH;  //for f2dd output width limit          //~vaaqI~
	for (pc=Pstr,pcd=Pdbcs,pct=Pcodetbl,pddct=pwkddct,reslenu8=Pstrlen,reslenlc=Plclen,pdddata=pwkdddata,pdddbcs=pwkdddbcs;//~vaaqR~
    		reslenu8>0 && reslenlc>0 && resleno>0;                 //~vaaqI~
    )                                                              //~vaaqI~
    {                                                              //~vaaqI~
        if (*pct==XEUTFCT_LC)                                      //~vaaqI~
        {                                                          //~vaaqM~
	    	lclen=xeutf_strwidthlcbyct(0,pct,reslenlc);            //~vaaqM~
            if (!lclen)                                            //~vaaqI~
                break;                                             //~vaaqI~
            if (xeutfcvl2dd(0,pc,lclen,&pddw,&pdbcsw,&outlen)==UALLOC_FAILED)//~vaaqI~
                return UALLOC_FAILED;                              //~vaaqI~
    		rc|=XEUTFF2LRC_UTF8;	//ddfmt output                 //~vaaqI~
            outlen=min(outlen,resleno);                            //~vaaqI~
//          memcpy(pdddata,pddw,outlen);                           //~vb14R~
            memcpy(pdddata,pddw,(size_t)outlen);                   //~vb14I~
//          memcpy(pdddbcs,pdbcsw,outlen);                         //~vb14R~
            memcpy(pdddbcs,pdbcsw,(size_t)outlen);                 //~vb14I~
//          memset(pddct,XEUTFCT_LC,outlen);                       //~vb14R~
            memset(pddct,XEUTFCT_LC,(size_t)outlen);               //~vb14I~
            pdddata+=outlen;                                       //~vaaqI~
            pdddbcs+=outlen;                                       //~vaaqI~
            pddct+=outlen;                                         //~vaaqI~
            resleno-=outlen;                                       //~vaaqI~
            pc+=lclen;                                             //~vaaqI~
          if (Pdbcs)                                               //~vau2I~
            pcd+=lclen;                                            //~vaaqI~
            pct+=lclen;                                            //~vaaqI~
            reslenu8-=lclen;                                       //~vaaqI~
            reslenlc-=lclen;                                       //~vaaqI~
            continue;                                              //~vaaqI~
        }                                                          //~vaaqI~
//  	u8width=xeutf_strwidthu8byct(0,pct,reslenlc);              //~vaaqR~//~vau2R~
//    	xeutf_strlenu8byct(0,pc,reslenu8,pcd,pct,reslenlc,&u8cvlen,&u8width);//~vauPR~
      	xeutf_strlenu8byct(0,pc,reslenu8,NULL/*pcd*/,pct,reslenlc,&u8cvlen,&u8width);//no dbcs was set for utf8 part//~vauPI~
        if (!u8width)	//utf8 and ascii                           //~vaaqR~
        	break;                                                 //~vaaqI~
        outlen=u8width; //output column width                      //~vaaqR~
//      rc2=xeutf_cvf2dd(opt,pc,reslenu8,&pddw,&pdbcsw,&outlen);//untill detect locale dbcs//~vaaqR~//~vafkR~
//      rc2=xeutf_cvf2dd(opt,pc,u8width,&pddw,&pdbcsw,&outlen);//untill detect locale dbcs//~vafkI~//~vau2R~
        rc2=xeutf_cvf2dd(opt,pc,u8cvlen,&pddw,&pdbcsw,&outlen);//untill detect locale dbcs//~vau2I~
//      if (rc2 & XEUTFF2LRC_WIDTHOVF)                             //~vaaqR~//~vafkR~
        if (rc2 & (XEUTFF2LRC_WIDTHOVF|XEUTFF2LRC_ERR))            //~vafkI~
        {                                                          //~vaaqR~
            u8len=outlen;   //chklen by outwidth limit reached     //~vaaqR~
            outlen=u8width;                                        //~vaaqR~
        }                                                          //~vaaqR~
        else                                                       //~vaaqR~
        {                                                          //~vaaqR~
//          u8len=reslenu8; //all utf8 and ascii                   //~vaaqR~//~vafkR~
            u8len=u8width;                                         //~vafkI~
        }                                                          //~vaaqR~
    	rc|=rc2 & XEUTFF2LRC_UTF8;                                 //~vaaqI~
        outlen=min(outlen,resleno);                                //~vaaqR~
//      memcpy(pdddata,pddw,outlen);                               //~vb14R~
        memcpy(pdddata,pddw,(size_t)outlen);                       //~vb14I~
//      memcpy(pdddbcs,pdbcsw,outlen);                             //~vb14R~
        memcpy(pdddbcs,pdbcsw,(size_t)outlen);                     //~vb14I~
//      memcpy(pddct,pct,outlen);                                  //~vb14R~
        memcpy(pddct,pct,(size_t)outlen);                          //~vb14I~
        pdddata+=outlen;                                           //~vaaqR~
        pdddbcs+=outlen;                                           //~vaaqR~
        pddct+=outlen;                                             //~vaaqR~
        resleno-=outlen;                                           //~vaaqR~
//      pc+=u8len;                                                 //~vaaqR~//~vau2R~
        pc+=u8cvlen;                                               //~vau2R~
//      pct+=outlen;                                               //~vaaqR~//~vafkR~
        pct+=u8len;                                                //~vafkI~
//      pcd+=outlen;                                               //~vaaqR~//~vafkR~
      if (Pdbcs)                                                   //~vau2I~
        pcd+=u8len;                                                //~vafkI~
//      reslenu8-=u8len;                                           //~vaaqR~//~vawzR~
        reslenu8-=u8cvlen;                                         //~vawzI~
        reslenlc-=outlen;                                          //~vaaqR~
    }                                                              //~vaaqI~
//  outlen=(ULONG)pdddata-(ULONG)pwkdddata;                        //~vaaqI~//~vafkR~
//  outlen=(ULPTR)pdddata-(ULPTR)pwkdddata;                        //~vb14R~
    outlen=(int)((ULPTR)pdddata-(ULPTR)pwkdddata);                 //~vb14I~
    if (outlen && UDBCSCHK_DBCS1STU(*(pdddbcs-1)))                 //~vaaqI~
    {                                                              //~vaaqI~
    	*(pdddata-1)='.';                                          //~vaaqR~
    	*(pdddbcs-1)=0;                                            //~vaaqI~
        *(pddct-1)=0;                                              //~vaaqR~
    }                                                              //~vaaqI~
//  ctlen=(ULONG)pddct-(ULONG)pwkddct;                             //~vaaqI~//~vafkR~
//  ctlen=(ULPTR)pddct-(ULPTR)pwkddct;                             //~vb14R~
    ctlen=(int)((ULPTR)pddct-(ULPTR)pwkddct);                      //~vb14R~
    ctlen=min(ctlen,Plclen);                                       //~vaaqI~
    if (rc  & XEUTFF2LRC_UTF8)	//ddfmt                            //~vaaqI~
//      memcpy(Pcodetbl,pwkddct,ctlen);	//no change                //~vb14R~
        memcpy(Pcodetbl,pwkddct,(size_t)ctlen);	//no change        //~vb14I~
    *Ppddstrlen=outlen;                                            //~vaaqI~
    *Ppdddata=pwkdddata;                                           //~vaaqR~
    *Ppdddbcs=pwkdddbcs;                                           //~vaaqR~
    UTRACEP("xeutfcvlf2dd_updatect rc=%d,outlen=%d,ctlen=%d\n",rc,outlen,ctlen);//~vaaqR~
    UTRACED("xeutfcvlf2dd_updatect data",pwkdddata,outlen);        //~vaaqI~
    UTRACED("xeutfcvlf2dd_updatect dbcs",pwkdddbcs,outlen);        //~vaaqI~
    UTRACED("xeutfcvlf2dd_updatect ct",Pcodetbl,ctlen);            //~vaaqI~
    return rc;                                                     //~vaaqI~
}//xeutfcvlf2dd_updatect                                           //~vaaqR~
//**************************************************               //~va20I~
//!from mixed string to dd str for cmd                             //~va20R~
//**************************************************               //~va20I~
int xeutfcvl2fdd(int Popt,UCHAR *Pstr,int Pstrlen,                 //~va20R~
					UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,      //~va20I~
					UCHAR *Poutdd,UCHAR *Pdbcs,int Pddbuffsz,int *Ppddlen)//~va20I~
{                                                                  //~va20I~
    int opt,u8len,u8buffsz,ddlen;                                  //~va20R~
    char wku8[MAXCOLUMN*UTF8_MAXCHARSZ],*pu8;                      //~va20R~
    char wklc[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va20I~
//**************************************************               //~va20I~
    opt=0;                                                         //~va20I~
    if (Poutu8)                                                    //~va20I~
    {                                                              //~va20I~
    	pu8=Poutu8;                                                //~va20I~
        u8buffsz=Pu8buffsz;                                        //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
    	pu8=wku8;                                                  //~va20I~
        u8buffsz=sizeof(wku8);                                     //~va20I~
    }                                                              //~va20I~
	if (xeutf_getmixedstr(opt,Pstr,Pstrlen,wklc,0/*pdbcs*/,0/*codetype*/,sizeof(wklc),0/*outlclen*/,//~va20R~
			pu8,u8buffsz,&u8len)==UALLOC_FAILED)                   //~va20R~
        return UALLOC_FAILED;                                      //~va20I~
    if (Ppu8len)                                                   //~va20I~
    	*Ppu8len=u8len;                                            //~va20R~
    opt=0;                                                         //~va20I~
	utfcvf2dd(opt,pu8,u8len,Poutdd,Pdbcs,Pddbuffsz,&ddlen);        //~va20R~
    if (Ppddlen)                                                   //~va20I~
    	*Ppddlen=ddlen;                                            //~va20I~
UTRACED("xeutfcvl2fdd inp",Pstr,Pstrlen);                          //~va20R~
UTRACEDIFNZ("xeutfcvl2fdd out u8",Poutu8,u8len);                   //~va20R~
UTRACED("xeutfcvl2fdd out dd",Poutdd,ddlen);                       //~va20R~
UTRACED("xeutfcvl2fdd out dbcs",Pdbcs,ddlen);                      //~va20R~
    return 0;                                                      //~va20I~
}//*xeutfcvl2fdd                                                   //~va20R~
//**************************************************               //~va20I~
//!from mixed string to dd str for cmd                             //~va20I~
//rc:from xeutf_cvf2dd                                             //~va20I~
//**************************************************               //~va20I~
int xeutfcvl2dd(int Popt,UCHAR *Pdata,int Pdatalen,                //~va20I~
					UCHAR **Ppddstr,UCHAR **Ppdbcs,int *Ppddlen)   //~va20R~
{                                                                  //~va20I~
	UCHAR  *pdd,*pdbcs,*pu8;                                        //~va20R~//~va5sR~
    int ddlen,u8len,buffsz,rc=0,opt;                               //~va20R~
    UCHAR *pc,*pc0,ch;                                             //~vb4cR~
    int ii,swdbcs;                                                 //~vb4cR~
//**************************************************               //~va20I~
    buffsz=Pdatalen*UTF8_MAXCHARSZMAX+1;                           //~va20R~
    if (Popt & XEUTFCVL2DDO_ERRREP) //      0x01  //rep by '.' if l2f err//~vb4cI~
    	buffsz+=Pdatalen;                                          //~vb4cI~
	pu8=xeutf_buffget(XEUTF_BUFFDATA,buffsz);      //BUFF2 used by xeutf_cvf2dd//~va20R~
	UALLOCCHK(pu8,UALLOC_FAILED);                                  //~va20R~
    pc0=pu8+buffsz-Pdatalen;                                       //~vb4cI~
    opt=0;                                                         //~va20I~
    if (Popt & XEUTFCVL2DDO_ERRREP) //      0x01  //rep by '.' if l2f err//~vb14I~
    {                                                              //~vb14I~
	    opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                     //~vb14R~
        memcpy(pc0,Pdata,(size_t)Pdatalen);                        //~vb4cI~
        for (pc=pc0,ii=0;ii<Pdatalen;ii++,pc++)                    //~vb4cR~
        {                                                          //~vb4cI~
        	ch=*pc;                                                //~vb4cI~
            swdbcs=UDBCSCHK_ISDBCS1ST(ch);                         //~vb4cI~
        	if (  Gunpdispchartbl[ch]   	//unprintable          //~vb4cR~
#ifndef WXE //wxe adjust by setup dialog codepage                  //~vb4cI~
           	   || (ch>0x20 && !swdbcs && !UDBCSCHK_ISPRINT(*pc)) //unprintable by converter//~vb4cR~
#endif                                                             //~vb4cI~
        	)                                                      //~vb4cI~
            {                                                      //~vb4cI~
                UTRACEP("%s:reperr unprintable lc=%02x\n",UTT,*pc);//~vb4cI~
		    	*pc=XEUTF_ERRREPCH;                                //~vb4cI~
            }                                                      //~vb4cI~
            if (swdbcs)                                            //~vb4cI~
            	ii++,pc++;                                         //~vb4cI~
        }                                                          //~vb4cI~
    }                                                              //~vb14I~
    else                                                           //~vb4cI~
        pc0=Pdata;                                                 //~vb4cI~
//  utfcvl2f(opt,pu8,Pdata,0/*init offs*/,Pdatalen,0/*out choftbl*/,0/*out dbcstbl*/,0/*chklen*/,&u8len,0/*pcharcnt*/,0/*char width*/);//~va20R~//~vb4cR~
    utfcvl2f(opt,pu8,pc0,0/*init offs*/,Pdatalen,0/*out choftbl*/,0/*out dbcstbl*/,0/*chklen*/,&u8len,0/*pcharcnt*/,0/*char width*/);//~vb4cI~
    opt=0;                                                         //~va20I~
	rc=xeutf_cvf2dd(opt,pu8,u8len,&pdd,&pdbcs,&ddlen);             //~va20I~
    *Ppddstr=pdd;                                                  //~va20I~
    *Ppdbcs=pdbcs;                                                 //~va20R~
    *Ppddlen=ddlen;                                                //~va20I~
UTRACEP("xeutfcvl2dd rc=%d\n",rc);                                 //~va20R~
UTRACED("xeutfcvl2dd inp",Pdata,Pdatalen);                         //~va20R~
UTRACED("xeutfcvl2fdd inter pu8",pu8,u8len);                       //~va20I~
UTRACED("xeutfcvl2fdd out dd",pdd,ddlen);                          //~va20I~
UTRACED("xeutfcvl2fdd out dbcs",pdbcs,ddlen);                      //~va20R~
    return rc;                                                     //~va20I~
}//*xeutfcvl2dd                                                    //~va20I~
#ifdef W32                                                         //~vb2LI~
//**************************************************               //~vb2LI~
//locale code by system codepage(!=console cp when chcp was done)  //~vb2LI~
//rc:from xeutf_cvf2dd                                             //~vb2LI~
//**************************************************               //~vb2LI~
int xeutfcvl2dd_chcp(int Popt,UCHAR *Pdata,int Pdatalen,           //~vb2LI~
					UCHAR **Ppdddata,UCHAR **Ppdddbcs,int *Ppddlen)//~vb2LI~
{                                                                  //~vb2LI~
	UCHAR  *pdddata,*pdddbcs;                                      //~vb2LR~
    WUCS *pucs2;                                                   //~vb2LI~
    int ddlen,buffsz,buffsz2,rc2,opt,apiopt,ctr,lasterr;           //~vb2LR~
//**************************************************               //~vb2LI~
	UTRACED("input",Pdata,Pdatalen);                               //~v6BQI~//~vb2LI~
    buffsz2=(Pdatalen+1)*2;                                        //~vb2LI~
    buffsz=buffsz2*(1+1+WUCSSZ);  	//ucs2 and ddfmt data & dbcs   //~vb2LI~
	pdddata=xeutf_buffget(XEUTF_BUFFDATA,buffsz);      //BUFF2 used by xeutf_cvf2dd//~vb2LI~
	UALLOCCHK(pdddata,UALLOC_FAILED);                              //~vb2LR~
	pdddbcs=pdddata+buffsz2;                                       //~vb2LR~
	pucs2=(PWUCS)(void*)(pdddbcs+buffsz2);                         //~vb2LR~
    apiopt=MB_ERR_INVALID_CHARS;    //return err if invalid char;ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~v6BQI~//~vb2LI~
	ctr=uMultiByteToWideChar(0,0/*converter*/,apiopt,Pdata,Pdatalen,pucs2,(size_t)(buffsz2*WUCSSZ),&lasterr);//~v6BQI~//~vb2LI~
    if (ctr<=0)                                                    //~v6BQI~//~vb2LI~
    	return 4;                                                  //~v6BQI~//~vb2LI~
    opt=0;                                                         //~vb2LI~
	rc2=utf162dd(opt,pucs2,ctr,pdddata,pdddbcs,buffsz2,&ddlen);    //~vb2LI~
	if (rc2 & UTFCVFDRC_OVF)   //buffser overflow                    //~v6uaR~//~vb2LI~
    	return 8;                                                  //~vb2LI~
    *Ppdddata=pdddata;                                             //~vb2LI~
    *Ppdddbcs=pdddbcs;                                             //~vb2LI~
    *Ppddlen=ddlen;                                                //~vb2LI~
UTRACED("inter ucs2",pucs2,ctr*WUCSSZ);                            //~vb2LI~
UTRACED("out dddata",pdddata,ddlen);                               //~vb2LR~
UTRACED("out dddbcs",pdddbcs,ddlen);                               //~vb2LI~
    return 0;                                                      //~vb2LI~
}//*xeutfcvl2dd                                                    //~vb2LI~
//**************************************************               //~vb2LI~
//locale code by system codepage(!=console cp when chcp was done)  //~vb2LI~
//rc:from xeutf_cvf2dd                                             //~vb2LI~
//**************************************************               //~vb2LI~
int xeutfcvlchcp(int Popt,UCHAR *Pdata,int Pdatalen,UCHAR **Ppdata,UCHAR **Ppdbcs,int *Pplen)//~vb2LR~
{                                                                  //~vb2LI~
	UCHAR  *pc,*pcd;                                               //~vb2LI~
    WUCS *pucs2;                                                   //~vb2LI~
    int len,buffsz,buffsz2,apiopt,ctr,lasterr;                     //~vb2LI~
//**************************************************               //~vb2LI~
	UTRACED("input",Pdata,Pdatalen);                               //~vb2LI~
    buffsz2=(Pdatalen+1)*2;                                        //~vb2LI~
    buffsz=buffsz2*(1+1+WUCSSZ);  	//ucs2 and data & dbcs         //~vb2LI~
	pc=xeutf_buffget(XEUTF_BUFFDATA,buffsz);      //BUFF2 used by xeutf_cvf2dd//~vb2LI~
	UALLOCCHK(pc,UALLOC_FAILED);                                   //~vb2LI~
	pcd=pc+buffsz2;                                                //~vb2LI~
	pucs2=(PWUCS)(void*)(pcd+buffsz2);                             //~vb2LI~
    setdbcstbl(Pdata,pcd,Pdatalen);                                //~vb2LI~
    apiopt=MB_ERR_INVALID_CHARS;    //return err if invalid char;ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~vb2LI~
	ctr=uMultiByteToWideChar(0,0/*converter*/,apiopt,Pdata,Pdatalen,pucs2,(size_t)(buffsz2*WUCSSZ),&lasterr);//~vb2LI~
    if (ctr<=0)                                                    //~vb2LI~
    	return 4;                                                  //~vb2LI~
    apiopt=0;                                                      //~vb2LI~
	len=uWideCharToMultiByte(0,ugetcp()/*consoleCP*/,apiopt,pucs2,ctr,pc,(size_t)buffsz2,0/*defaultchar*/,0/*defaultused*/,&lasterr);//~vb2LR~
    if (len<=0)                                                    //~vb2LI~
    	return 4;                                                  //~vb2LI~
    *Ppdata=pc;                                                    //~vb2LR~
    *Ppdbcs=pcd;                                                   //~vb2LR~
    *Pplen=len;                                                    //~vb2LR~
UTRACED("inter ucs2",pucs2,ctr*WUCSSZ);                            //~vb2LI~
UTRACED("out data",pc,len);                                        //~vb2LI~
UTRACED("out dbcs",pcd,len);                                       //~vb2LI~
    return 0;                                                      //~vb2LI~
}//*xeutfcvlchcp                                                   //~vb2LI~
#endif                                                             //~vb2LI~
//**************************************************               //~va8fI~
//l2dd (keep tab(09) and tabpadding(20)) for lcmdcomp              //~va8fR~
//rc:from xeutf_cvf2dd                                             //~va8fI~
//**************************************************               //~va8fI~
int xeutfcvl2ddtab(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va8fI~
					UCHAR **Ppddstr,UCHAR **Ppdbcs,int *Ppddlen)   //~va8fI~
{                                                                  //~va8fI~
	UCHAR  *pdd,*pdbcs,*pu8;                                       //~va8fI~
    int ddlen,u8len,buffsz,rc=0,opt;                               //~va8fI~
//**************************************************               //~va8fI~
    buffsz=Pdatalen*UTF8_MAXCHARSZMAX+1;                           //~va8fI~
	pu8=xeutf_buffget(XEUTF_BUFFDATA,buffsz);      //BUFF2 used by xeutf_cvf2dd//~va8fI~
	UALLOCCHK(pu8,UALLOC_FAILED);                                  //~va8fI~
    opt=0;                                                         //~va8fI~
//  utfcvl2f(opt,pu8,Pdata,0/*init offs*/,Pdatalen,0/*out choftbl*/,0/*out dbcstbl*/,0/*chklen*/,&u8len,0/*pcharcnt*/,0/*char width*/);//~va8fI~
    utfcvl2ftab(opt,pu8,Pdata,Pdbcs,Pdatalen,0/*out dbcstbl*/,0/*chklen*/,&u8len,0/*pcharcnt*/,0/*char width*/);//~va8fR~
//  opt=0;                                                         //~va8fR~
    opt=(Popt & XEUTFCVO_SETTABCHAR);                              //~va8fR~
	rc=xeutf_cvf2dd(opt,pu8,u8len,&pdd,&pdbcs,&ddlen);             //~va8fI~
    *Ppddstr=pdd;                                                  //~va8fI~
    *Ppdbcs=pdbcs;                                                 //~va8fI~
    *Ppddlen=ddlen;                                                //~va8fI~
UTRACEP("xeutfcvl2dd rc=%d\n",rc);                                 //~va8fI~
UTRACED("xeutfcvl2dd inp",Pdata,Pdatalen);                         //~va8fI~
UTRACEDIFNZ("xeutfcvl2dd inp",Pdbcs,Pdatalen);                     //~va8fI~
UTRACED("xeutfcvl2fdd inter pu8",pu8,u8len);                       //~va8fI~
UTRACED("xeutfcvl2fdd out dd",pdd,ddlen);                          //~va8fI~
UTRACED("xeutfcvl2fdd out dbcs",pdbcs,ddlen);                      //~va8fI~
    return rc;                                                     //~va8fI~
}//*xeutfcvl2dd                                                    //~va8fI~
//**************************************************               //~va20I~
//!from dd to locale                                               //~va20R~
//rc:UALLOC_FAILED,RC of xeutfcvf2lc                               //~va20R~
//**************************************************               //~va20I~
int xeutfcvdd2l(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,   //~va20I~
					UCHAR **Pplcstr,int *Pplclen)                  //~va20I~
{                                                                  //~va20I~
	char  *plc,*pu8;                                               //~va20R~
    int lclen,u8len,buffszu8,buffszlc,opt,rc;                      //~va20R~
//**************************************************               //~va20I~
    buffszu8=Pdatalen*UTF8_MAXCHARSZMAX;                           //~va20I~
    buffszlc=Pdatalen*UTF8_F2LMAXRATE;                             //~va20I~
    if (Popt & XEUTFDD2LO_CRLF)                                    //~va20I~
	  	buffszlc+=2;                                               //~va20I~
	plc=xeutf_buffget(XEUTF_BUFFDATA,buffszu8+buffszlc+1);      //BUFF2 used by xeutf_cvf2dd//~va20R~
	UALLOCCHK(plc,UALLOC_FAILED);                                  //~va20I~
    pu8=plc+buffszlc;                                              //~va20I~
    opt=0;                                                         //~va20I~
	utfcvdd2f(opt,Pdata,Pdatalen,Pdbcs,pu8,buffszu8,&u8len,0/*outdbcs*/);//~va20R~
    if (!(Popt & XEUTFDD2LO_ERRRET))                               //~va20I~
	  	opt=XEUTFF2LCO_ERRREP;                                     //~va20R~
	rc=xeutfcvf2lc(opt,pu8,u8len,plc,0/*Pcodetypetbl*/,buffszlc,&lclen,0/*Ppchklen*/);//~va20R~
    *Pplcstr=plc;                                                  //~va20I~
    *Pplclen=lclen;                                                //~va20I~
UTRACEP("xeutfcvdd2l rc=%d\n",rc);                                 //~va20I~
UTRACED("xeutfcvdd2l inp dd",Pdata,Pdatalen);                      //~va20I~
UTRACED("xeutfcvdd2l inp dbcs",Pdbcs,Pdatalen);                    //~va20I~
UTRACED("xeutfcvdd2l inter pu8",pu8,u8len);                        //~va20I~
UTRACED("xeutfcvdd2l out lc",plc,lclen);                           //~va20I~
    return rc;                                                     //~va20I~
}//*xeutfcvdd2l                                                    //~va20I~
//**************************************************               //~va20I~
//!from dd str to locale and dbcs                                  //~va20R~
//rc:UALLOC_FAILED,RC of xeutfcvf2l                                //~va20I~
//**************************************************               //~va20I~
int xeutfcvdd2ldbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20I~
					UCHAR **Pplcstr,UCHAR **Ppdbcs,int *Pplclen)   //~va20I~
{                                                                  //~va20I~
	char  *plc,*pu8,*pdbcs;                                        //~va20R~
    int lclen,u8len,buffszu8,buffszlc,buffszdb,opt,rc;             //~va20I~
//**************************************************               //~va20I~
    buffszu8=Pdatalen*UTF8_MAXCHARSZMAX;                           //~va20I~
    buffszlc=Pdatalen*UTF8_F2LMAXRATE;                             //~va20I~
    buffszdb=Pdatalen*UTF8_F2LMAXRATE;                             //~va20I~
	plc=xeutf_buffget(XEUTF_BUFFDATA,buffszu8+buffszlc+buffszdb+1);      //BUFF2 used by xeutf_cvf2dd//~va20I~
	UALLOCCHK(plc,UALLOC_FAILED);                                  //~va20I~
    pu8=plc+buffszlc;                                              //~va20I~
    pdbcs=pu8+buffszu8;                                            //~va20R~
    opt=0;                                                         //~va20I~
	utfcvdd2f(opt,Pdata,Pdatalen,Pdbcs,pu8,buffszu8,&u8len,0/*outdbcs*/);//~va20R~
    opt=XEUTFF2LCO_ERRREP;                                         //~va20I~
	rc=xeutfcvf2lc(opt,pu8,u8len,plc,0/*Pcodetypetbl*/,buffszlc,&lclen,0/*Ppchklen*/);//~va20I~
    filesetdbcstbl(plc,pdbcs,lclen,0);                             //~va20R~
    *Pplcstr=plc;                                                  //~va20I~
    *Ppdbcs=pdbcs;                                                 //~va20R~
    *Pplclen=lclen;                                                //~va20I~
UTRACEP("xeutfcvdd2ldbcs rc=%d\n",rc);                             //~va20I~
UTRACED("xeutfcvdd2ldbcs inp dd",Pdata,Pdatalen);                  //~va20I~
UTRACED("xeutfcvdd2ldbcs inp dbcs",Pdbcs,Pdatalen);                //~va20I~
UTRACED("xeutfcvdd2ldbcs inter pu8",pu8,u8len);                    //~va20I~
UTRACED("xeutfcvdd2ldbcs out lc",plc,lclen);                       //~va20I~
UTRACED("xeutfcvdd2ldbcs out dbcs",pdbcs,lclen);                   //~va20R~
    return rc;                                                     //~va20I~
}//*xeutfcvdd2ldbcs                                                //~va20I~
//**************************************************               //~va20I~
//!from mixed string to dd str for cmd                             //~va20I~
//rc:UALLOC_FAILED,RC of utfcvdd2f                                 //~va20I~
//**************************************************               //~va20I~
int xeutfcvdd2f(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppu8,int *Ppu8len,UCHAR **Ppoutdbcs)//~va20R~
{                                                                  //~va20I~
	char  *pu8,*poutdbcs;                                          //~va20R~
//  int u8len,buffszu8,opt,rc2,rc=0,buffszdbcs;                    //~vaf8R~
    int u8len,buffszu8=0,opt,rc2,rc=0,buffszdbcs;                  //~vaf8I~
	char  *poutdbcs_modechng=0;                                    //~vawEI~
    int swsetdbcstbl_binfile;                                      //~vawEI~
//**************************************************               //~va20I~
	swsetdbcstbl_binfile=(Popt & XEUTFDD2FO_SETDBCSTBL);	//from xeutf_modechng,setdbcstbl for binfile//~vawER~
                                                                   //~vb49I~
	if (Ppu8)	//request output utf8,else get length only         //~va20I~
    {                                                              //~va20I~
        buffszu8=Pdatalen*UTF8_MAXCHARSZMAX;                       //~va20R~
        if (Popt & XEUTFDD2FO_OUTSTRZ) //   0x0002 //setdbcstbl as bin file//~vb49I~
        	buffszu8++;                                            //~vb49I~
        if (Ppoutdbcs)                                             //~va20I~
        {                                                          //~vawEI~
		  if (swsetdbcstbl_binfile)	//from xeutf_modechng,setdbcstbl for binfile//~vawEI~
        	buffszdbcs=buffszu8;	//setdbcstbl for output utf8   //~vawEI~
          else                                                     //~vawEI~
        	buffszdbcs=Pdatalen;                                   //~va20I~
        }                                                          //~vawEI~
        else                                                       //~va20I~
        	buffszdbcs=0;                                          //~va20I~
        pu8=xeutf_buffget(XEUTF_BUFFDATA,buffszu8+buffszdbcs+1);      //BUFF2 used by xeutf_cvf2dd//~va20R~
        UALLOCCHK(pu8,UALLOC_FAILED);                              //~va20R~
        if (Ppoutdbcs)                                             //~va20I~
        {                                                          //~vawEI~
        	poutdbcs=pu8+buffszu8;                                 //~va20I~
		  	if (swsetdbcstbl_binfile)	//from xeutf_modechng,setdbcstbl for binfile//~vawEI~
          	{                                                      //~vawEI~
        		poutdbcs_modechng=poutdbcs;                        //~vawEI~
	        	poutdbcs=0;		//no need to set dbcstbl from ddfmt at utfcvdd2f//~vawEI~
          	}                                                      //~vawEI~
        }                                                          //~vawEI~
        else                                                       //~va20I~
        	poutdbcs=0;                                            //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    	pu8=poutdbcs=0;	//calc length                              //~va20R~
    opt=Popt & XEUTFDD2FO_OPTMASK;  //option to utfcvdd2f          //~va20R~
    if (Popt & UTFDD2FO_ERRREP)                                    //~va20R~
        opt|=XEUTF_ERRREPCH_F2LFILE;                               //~va20R~
    if (Popt & XEUTFDD2FO_OUTSTRZ) //   0x0002 //setdbcstbl as bin file//~vb49I~
        opt|=UTFDD2FO_OUTSTRZ;     //   0x2000                     //~vb49I~
	rc2=utfcvdd2f(opt,Pdata,Pdatalen,Pdbcs,pu8,buffszu8,&u8len,poutdbcs);//~va20R~
	if (Ppu8)	//request output utf8,else get length only         //~va20I~
    	*Ppu8=pu8;                                                 //~va20R~
	if (Ppoutdbcs)	//request output utf8,else get length only     //~va20I~
    {                                                              //~vawEI~
	  if (swsetdbcstbl_binfile)	//from xeutf_modechng,setdbcstbl for binfile//~vawEI~
      {                                                            //~vawEI~
    	*Ppoutdbcs=poutdbcs_modechng;                              //~vawEI~
        filesetdbcstbl(pu8,poutdbcs_modechng,u8len,0/*opt*/);      //~vawEI~
      }                                                            //~vawEI~
      else                                                         //~vawEI~
    	*Ppoutdbcs=poutdbcs;                                       //~va20R~
    }                                                              //~vawEI~
    *Ppu8len=u8len;                                                //~va20I~
    if (rc2>=UTFDD2FRC_ERR)                                        //~va20I~
    	rc=4;                                                      //~va20I~
    return rc;                                                     //~va20I~
}//*xeutfcvdd2f                                                    //~va20I~
//**************************************************               //~va20M~
//!cv to utf8/locale from ddstr                                    //~va20R~
//*ret  :4:err,1:f2l errrep                                        //~va20R~
//**************************************************               //~va20M~
int xeutfcvdd2fl(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20R~
				UCHAR *Poutu8,int Pu8buffsz,int *Ppoutu8len,       //~va20I~
				UCHAR *Poutlc,UCHAR *Poutdbcs,UCHAR *Poutct,int Plcbuffsz,int *Ppoutlclen)//~va20R~
{                                                                  //~va20M~
    int opt,lclen,u8len,lcbuffsz,rc2,rc3,rc=0;                     //~va20R~
    char *plc,*pct;                                                //~va20I~
    char wklc[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va20M~
    char wkct[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va20M~
//**************************************************               //~va20M~
	rc2=utfcvdd2f(0,Pdata,Pdatalen,Pdbcs,Poutu8,Pu8buffsz-1,&u8len,0/*outdbcs*/);//~va20R~
    if (rc2>=UTFDD2FRC_ERR)                                        //~va20R~
    	return 4;                                                  //~va20M~
    *(Poutu8+u8len)=0;	//strz                                     //~va20M~
    if (Poutlc)                                                    //~va20I~
    {                                                              //~va20I~
    	plc=Poutlc;                                                //~va20R~
    	pct=Poutct;                                                //~va20I~
    	lcbuffsz=Plcbuffsz;                                        //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
    	plc=wklc;                                                  //~va20I~
        pct=wkct;                                                  //~va20I~
        lcbuffsz=sizeof(wklc);                                     //~va20I~
    }                                                              //~va20I~
    if (rc2 & UTFDD2FRC_UCS)                                       //~va20I~
    {                                                              //~va20I~
#ifdef AAA  //                                                     //~vau7R~
        opt=XEUTFF2LCO_ERRREP;                                     //~va20I~
		rc3=xeutfcvf2lc(opt,Poutu8,u8len,plc,pct,lcbuffsz,&lclen,0/*readlen*/);//~va20R~
		if (rc3>=XEUTFF2LCRC_ERR)                                  //~va20I~
        	return 4;	//buff overflow                            //~va20I~
        if (rc3 & XEUTFF2LCRC_UTF8ERR)	//f2l failed               //~va20I~
        	rc|=1;                                                 //~va20I~
        if (Popt & XEUTFDD2FLO_U8ERRMSG)//      0x01 //register utf8 code for errmsg//~va20R~
//          xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_WORD2,Poutu8,u8len,plc,pct,lclen);//~vau7R~
            xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_WORD2,Poutu8,u8len,plc,NULL/*Pdbcs*/,pct,lclen);//~vau7I~
        if (Poutdbcs)                                              //~va20I~
    		filesetdbcstbl(plc,Poutdbcs,lclen,0);                  //~va20I~
#else                                                              //~vau7R~
        opt=0;                                                     //~vau7R~
        rc3=xeutfcvdd2lc(opt,Pdata,Pdatalen,Pdbcs,plc,pct,lcbuffsz,&lclen);//~vau7R~
        if (rc3>=XEUTFDD2LCRC_ERR)                                 //~vau7R~
            return 4;   //buff overflow                            //~vau7R~
        if (rc3 & XEUTFDD2LCRC_UTF8ERR) //f2l failed               //~vau7R~
            rc|=1;                                                 //~vau7R~
        if (Popt & XEUTFDD2FLO_U8ERRMSG)//      0x01 //register utf8 code for errmsg//~vau7R~
        {                                                          //~vaubI~
//          xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_WORD2,Poutu8,u8len,plc,pct,lclen);//~vau7R~
            int opt2;                                              //~vaubI~
            opt2=Ppcw->UCWsplitid|XEUTFSLCFEO_WORD2;               //~vaubI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//FIXME test on WIN :FIXED                                                //~vavpI~//~vaw1R~
            opt2|=XEUTFSLCFEO_DDFMT;                               //~vaubI~
#endif                                                             //~vaubI~
            xeutf_savelcctforerrmsg(opt2,Poutu8,u8len,Pdata,Pdbcs,pct,lclen);//~vaubR~
        }                                                          //~vaubI~
        if (Poutdbcs)                                              //~vau7R~
        {                                                          //~vavnI~
#ifdef W32UNICODE                                                  //~vavnI~
            fsubw_setdbcstblDD(0,Pdata,Pdbcs,Pdatalen,Poutdbcs,lcbuffsz);//~vavnR~
#else                                                              //~vavnI~
            filesetdbcstbl(plc,Poutdbcs,lclen,0);                  //~vau7R~
#endif                                                             //~vavnI~
        }                                                          //~vavnI~
#endif                                                             //~vau7R~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
        lclen=u8len;                                               //~va20I~
    	if (Poutlc)                                                //~va20I~
        {                                                          //~va20I~
    		memcpy(plc,Poutu8,(UINT)u8len);                        //~va20I~
    		memset(pct,0,(UINT)u8len);                             //~va20I~
        }                                                          //~va20I~
        if (Poutdbcs)                                              //~va20I~
    		memset(Poutdbcs,0,(UINT)u8len);                        //~va20I~
    }                                                              //~va20I~
    if (Ppoutu8len)                                                //~va20M~
        *Ppoutu8len=u8len;                                         //~va20M~
    if (Ppoutlclen)                                                //~va20I~
        *Ppoutlclen=lclen;                                         //~va20I~
UTRACED("fcmdcvdd2fl inp data",Pdata,Pdatalen);                    //~va20R~
UTRACED("fcmdcvdd2fl inp dbcs",Pdbcs,Pdatalen);                    //~va20R~
UTRACEDIFNZ("fcmdcvdd2fl out",Poutu8,u8len);                       //~va20R~
UTRACEDIFNZ("fcmdcvdd2fl out",Poutlc,lclen);                       //~va20R~
    return rc;                                                     //~va20R~
}//*xeutfcvdd2fl                                                   //~va20R~
//**************************************************               //~va20I~
//!cv to dd/locale from utf8                                       //~va20I~
//*ret  :4:err,1:f2l errrep                                        //~va20R~
//**************************************************               //~va20I~
int xeutfcvf2ldd(int Popt,PUCLIENTWE Ppcw,UCHAR *Pu8,int Pu8len,   //~va20I~
				UCHAR *Poutdd,UCHAR *Pdbcs,int Pddbuffsz,int *Ppoutddlen,//~va20I~
				UCHAR *Poutlc,UCHAR *Poutct,int Plcbuffsz,int *Ppoutlclen)//~va20I~
{                                                                  //~va20I~
    int opt,rc2;                                                   //~va20R~
//**************************************************               //~va20I~
	opt=0;                                                         //~va20I~
	utfcvf2dd(opt,Pu8,Pu8len,Poutdd,Pdbcs,Pddbuffsz,Ppoutddlen);   //~va20R~
    opt=XEUTFF2LCO_ERRREP;                                         //~va20I~
	rc2=xeutfcvf2lc(opt,Pu8,Pu8len,Poutlc,Poutct,Plcbuffsz,Ppoutlclen,0/*readlen*/);//~va20R~
	if (rc2>=XEUTFF2LCRC_ERR)                                      //~va20I~
        return 4;	//buff overflow                                //~va20R~
	if (rc2 & XEUTFF2LCRC_UTF8ERR)	//f2l failed                   //~va20I~
    	return 1;                                                  //~va20I~
UTRACED("fcmdcvf2ldd inp data",Pu8,Pu8len);                        //~va20R~
UTRACEDIFNZ("fcmdcvf2ldd out lc",Poutlc,*Ppoutlclen);              //~va20R~
UTRACEDIFNZ("fcmdcvf2ldd out dd",Poutdd,*Ppoutddlen);              //~va20R~
UTRACEDIFNZ("fcmdcvf2ldd out dbcs",Pdbcs,*Ppoutddlen);             //~va20I~
    return 0;                                                      //~va20I~
}//*xeutfcvf2ldd                                                   //~va20I~
//**************************************************               //~va20I~
//cv to syntax chk data                                            //~va20I~
//(keep same column as screen display)                             //~va20I~
//**************************************************               //~va20I~
int xeutf_dd2syn(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppsyndata)//~va20R~
{                                                                  //~va20I~
    int buffsz,reslen,dbcsid;                                      //~va20R~
    char *psyn,*pc,*pcd;                                           //~va20R~
//**************************************************               //~va20I~
    buffsz=Pdatalen;                                               //~va20I~
	psyn=xeutf_buffget(XEUTF_BUFFDATA,buffsz+1);      //BUFF2 used by xeutf_cvf2dd//~va20I~
	UALLOCCHK(psyn,UALLOC_FAILED);                                 //~va20I~
    *Ppsyndata=psyn;                                               //~va20I~
    for (pc=Pdata,pcd=Pdbcs,reslen=Pdatalen;reslen>0;pc++,reslen--)//~va20R~
    {                                                              //~va20I~
    	dbcsid=*pcd++;                                             //~va20I~
//*!ebc                                                            //~va3TI~
    	if (UTF_ISASCIITABDBCS(dbcsid))	//ascii or tab/tab padding //~va20R~
        	*psyn++=*pc;                                           //~va20I~
        else                                                       //~va20I~
        	*psyn++=0xc0;	//one of not punctuation               //~va20I~
    }                                                              //~va20I~
    return 0;                                                      //~va20I~
}//*xeutf_dd2syn                                                   //~va20I~
//**************************************************               //~va20I~
//!from dd to utf16;from wxe_dbcstextcopyu                                             //~va20R~//~vaw1R~
//rc:UALLOC_FAILED,RC of utfdd2u(4 buff overflow)                  //~va20I~
//**************************************************               //~va20I~
int xeutfcvdd2u(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,WUCS **Ppucs,int *Ppucslen)//~va20I~
{                                                                  //~va20I~
    WUCS *pucs;                                                    //~va20I~
    int buffsz,rc,opt,ucsctr;                                      //~va20R~
//**************************************************               //~va20I~
//  buffsz=Pdatalen*WUCSSZ;                                        //~va20I~//~vawgR~
//  pucs=(WUCS*)xeutf_buffget(XEUTF_BUFFDATA,buffsz+1);            //~va20R~//~vawgR~
#ifdef W32UNICODE                                                  //~vawgI~
    buffsz=Pdatalen*2*WUCSSZ+1;	//for surrogate pair               //~vawgI~
#else                                                              //~vawgI~
//  buffsz=Pdatalen*WUCSSZ+1;                                      //~vb14R~
    buffsz=Pdatalen*(int)WUCSSZ+1;                                 //~vb14I~
#endif                                                             //~vawgI~
    pucs=(WUCS*)xeutf_buffget(XEUTF_BUFFDATA,buffsz);              //~vawgI~
	UALLOCCHK(pucs,UALLOC_FAILED);                                 //~va20R~
    opt=0;                                                         //~va20I~
    if (Popt & XEUTFDD2UO_NULLREP)                                 //~va5FI~
        opt|=UTFDD2UO_NULLREP|XEUTF_ERRREPCH_F2LFILE;              //~va5FI~
	rc=utfdd2u(opt,Pdata,Pdbcs,Pdatalen,pucs,buffsz,&ucsctr,0/*ucsctr sbcs*/,0/*ucsctr dbcs*/);//~va20R~
    *Ppucs=pucs;                                                   //~va20I~
//  *Ppucslen=ucsctr*WUCSSZ;                                       //~vb14R~
    *Ppucslen=ucsctr*(int)WUCSSZ;                                  //~vb14I~
    if (*Ppucslen<buffsz)                                          //~vawgI~
	    *(pucs+ucsctr)=0;	//strz                                 //~vawgI~
UTRACEP("xeutfcvdd2u rc=%d\n",rc);                                 //~va20I~
UTRACED("xeutfcvdd2u inp dd",Pdata,Pdatalen);                      //~va20I~
UTRACED("xeutfcvdd2u inp dbcs",Pdbcs,Pdatalen);                    //~va20I~
UTRACED("xeutfcvdd2u out ucs",pucs,ucsctr*(int)WUCSSZ);            //~vb14R~
    return rc;                                                     //~va20I~
}//xeutfcvdd2u                                                    //~va20I~//~vaw1R~
//**************************************************               //~va20I~
//!from ucs to dd for clipboard data(from wxe_cappaste)                               //~va20I~//~vaw1R~
//rc:UALLOC_FAILED,RC of utfu2dd                                   //~va20I~
//**************************************************               //~va20I~
int xeutfcvu2dd(int Popt,WUCS *Pucs,int Plen,char **Ppdata,char **Ppdbcs,int *Ppoutlen)//~va20I~
{                                                                  //~va20I~
    char *pdata,*pdbcs;                                            //~va20I~
    int buffsz,rc,opt,outlen;                                      //~va20R~
//**************************************************               //~va20I~
    buffsz=Plen*2;	//data and dbcs                                //~va20R~
	pdata=xeutf_buffget(XEUTF_BUFFDATA,buffsz+1);                  //~va20I~
	UALLOCCHK(pdata,UALLOC_FAILED);                                //~va20R~
    pdbcs=pdata+Plen;                                              //~va20R~
    opt=0;                                                         //~va20I~
#ifdef UTF8UTF16                                                   //~vaw1I~
//  rc=utf162dd(opt,Pucs,Plen,pdata,pdbcs,buffsz,&outlen);         //~vaw1I~//~vax0R~
    rc=utf162dd(opt,Pucs,sz2ctrW(Plen),pdata,pdbcs,buffsz,&outlen);//~vax0I~
#else                                                              //~vaw1I~
	rc=utfu2dd(opt,Pucs,Plen,pdata,pdbcs,buffsz,&outlen);          //~va20I~
#endif                                                             //~vaw1I~
    *Ppdata=pdata;                                                 //~va20I~
    *Ppdbcs=pdbcs;                                                 //~va20I~
    *Ppoutlen=outlen;                                              //~va20I~
UTRACEP("%s:rc=%d\n",UTT,rc);                                      //~vaw1I~
UTRACED("inp ucs",Pucs,Plen);                                      //~vaw1I~
UTRACED("out data",pdata,outlen);                                  //~vaw1I~
UTRACED("out dbcs",pdbcs,outlen);                                  //~vaw1I~
    return rc;                                                     //~va20I~
}//*xeutfcvdd2u                                                    //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416  //FIXME test surrogate:FIXED                    //~vaw1R~
//**************************************************               //~va3xI~
//chk ddfmt ucs4 is printable                                      //~va3xI~
//**************************************************               //~va3xI~
#ifdef UTF8UTF16                                                   //~vaw1I~
int xeutfddwidth4(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UWUCS *Ppucs,int *Ppwidth)//~vaw1I~
#else                                                              //~vaw1I~
int xeutfddwidth4(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,PWUCS Ppucs,int *Ppwidth)//~va3xR~
#endif                                                             //~vaw1I~
{                                                                  //~va3xI~
    int rc,opt,len,flag;                                           //~va3xI~
#ifdef UTF8UTF16                                                   //~vaw1I~
    UWUCS ucs;                                                     //~vaw1I~
#else                                                              //~vaw1I~
    WUCS ucs;                                                      //~va3xI~
#endif                                                             //~vaw1I~
//**************************************************               //~va3xI~
	ucs=UTF_GETUCSDBCSOVF(Pdata,Pdbcs);                            //~va3xI~
	opt=UTFWWO_APICHK4;                                            //~va3xI~
//  len=utfwcwidth(opt,ucs,&flag);                                 //~vb14R~
    len=utfwcwidth(opt,(ULONG)ucs,&flag);                          //~vb14I~
    if (Ppwidth)                                                   //~va3xI~
    	*Ppwidth=len;                                              //~va3xI~
    if (Ppucs)                                                     //~va3xI~
        *Ppucs=ucs;                                                //~va3xI~
    if (len<=0)                                                    //~va3xI~
    	rc=4;                                                      //~va3xI~
    else                                                           //~va3xI~
    	rc=0;                                                      //~va3xI~
UTRACEP("xeutfddwidth4 width=%d,ucs=%x\n",len,ucs);                //~va3xI~
    return rc;                                                     //~va3xI~
}//xeutfddwidth4                                                   //~va3xR~
#endif                                                             //~va3xI~
#endif //UTF8UCS2                                                  //~va20R~
//#ifdef AAA                                                         //~vaubI~//~vavpR~
////**************************************************               //~vaubI~//~vavpR~
////!cv to utf8/locale from ddstr with ct                            //~vaubI~//~vavpR~
////*ret  :4:err,1:f2l errrep                                        //~vaubI~//~vavpR~
////**************************************************               //~vaubI~//~vavpR~
//int xeutfcvdd2flbyct(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,UCHAR *Pddcode,int Pddlen,//~vaubI~//~vavpR~
//                UCHAR *Poutbuff,UCHAR *Poutbuffct,int Pbuffbuffsz,int *Ppoutlen)//~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//    int opt,chklen,wrtlen,outlen,reslen,resleno;                   //~vaubI~//~vavpR~
//    char *pc,*pcd,*pct,*pct2,*pcto;                                //~vaubI~//~vavpR~
//    char wklc[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~vaubI~//~vavpR~
//    char wkct[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~vaubI~//~vavpR~
////**************************************************               //~vaubI~//~vavpR~
//UTRACED("inp dddata",Pdddata,Pddlen);                              //~vaubI~//~vavpR~
//UTRACED("inp dddbcs",Pdddbcs,Pddlen);                              //~vaubI~//~vavpR~
//    for (pc=Pdddata,pcd=Pdddbcs,pct=Pddcode,pco=Poutbuff,reslen=Pddlen,resleno=Poutbuffsz,pcto=Poutbuffct;//~vaubI~//~vavpR~
//        reslen> && resleno>0;                                      //~vaubI~//~vavpR~
//        pc+=chklen;pco+=wrtlen,reslen-=chklen,resleno-=wrtlen)     //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        if (*pct==XEUTFCT_UTF8)                                    //~vaubI~//~vavpR~
//        {                                                          //~vaubI~//~vavpR~
//            for (pct2=pct;reslen>0;pct2++)                         //~vaubI~//~vavpR~
//                if (*pct2!=XEUTFCT_UTF8)                           //~vaubI~//~vavpR~
//                    break;                                         //~vaubI~//~vavpR~
//            chklen=PTRDIFF(pct2,pct);                              //~vaubI~//~vavpR~
//            opt=0;                                                 //~vaubI~//~vavpR~
//            utfcvdd2f(opt,pc,chklen,pcd,pco,resleno,&wrtlen,0/*outdbcs*/);//~vaubI~//~vavpR~
//            if (Poutbuffct)                                        //~vaubI~//~vavpR~
//            {                                                      //~vaubI~//~vavpR~
//                memxet(pcto,XEUTFCT_UTF8,wrtlen);                  //~vaubI~//~vavpR~
//                pcto+=wrtlen;                                      //~vaubI~//~vavpR~
//            }                                                      //~vaubI~//~vavpR~
//            continue;                                              //~vaubI~//~vavpR~
//        }                                                          //~vaubI~//~vavpR~
//        if (*pct==XEUTFCT_LC)                                      //~vaubI~//~vavpR~
//        {                                                          //~vaubI~//~vavpR~
//            for (pct2=pct;reslen>0;pct2++)                         //~vaubI~//~vavpR~
//                if (*pct2!=XEUTFCT_LC)                             //~vaubI~//~vavpR~
//                    break;                                         //~vaubI~//~vavpR~
//            chklen=PTRDIFF(pct2,pct);                              //~vaubI~//~vavpR~
//            opt=0;                                                 //~vaubI~//~vavpR~
//            utfcvdd2f(opt,pc,chklen,pcd,pco,resleno,&wrtlen,0/*outdbcs*/);//~vaubI~//~vavpR~
//            if (Poutbuffct)                                        //~vaubI~//~vavpR~
//            {                                                      //~vaubI~//~vavpR~
//                memxet(pcto,XEUTFCT_LC,wrtlen);                    //~vaubI~//~vavpR~
//                pcto+=wrtlen;                                      //~vaubI~//~vavpR~
//            }                                                      //~vaubI~//~vavpR~
//            continue;                                              //~vaubI~//~vavpR~
//        }                                                          //~vaubI~//~vavpR~
////*ascii                                                           //~vaubI~//~vavpR~
//        chklen=wrtlen=1;                                           //~vaubI~//~vavpR~
//        *pco=*pc;                                                  //~vaubI~//~vavpR~
//        if (Poutbuffct)                                            //~vaubI~//~vavpR~
//            *pcto++=XEUTFCT_ASCII;                                 //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    outlen=PTRDIFF(pco,Poutbuff);                                  //~vaubI~//~vavpR~
//    *Ppoutlen=outlen;                                              //~vaubI~//~vavpR~
//UTRACED("out mixe data",Poutbuff,outlen);                          //~vaubI~//~vavpR~
//UTRACED("out mixe ct",Poutbuffct,outlen);                          //~vaubI~//~vavpR~
//    return rc;                                                     //~vaubI~//~vavpR~
//}//*xeutfcvdd2fl                                                   //~vaubI~//~vavpR~
//#endif  //AAA                                                      //~vaubR~//~vavpR~
#ifdef W32UNICODE                                                  //~vawgI~
//**************************************************               //~vawgI~
//!cv to utf8/locale from ddstr with ct                            //~vawgI~
//*ret  :4:err                                                     //~vawgI~
//**************************************************               //~vawgI~
#ifdef AAA                                                         //~vawgI~
int xeutfcvDD2UD(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,UCHAR **Ppoutbuff,int *Ppoutlen)//~vawgR~
{                                                                  //~vawgI~
    int opt,udlen,rc2,udsz,ucslen;                                 //~vawgR~
    char *pud;                                                     //~vawgR~
    WUCS *pucs16;                                                  //~vawgI~
//**************************************************               //~vawgI~
UTRACED("inp dddata",Pdddata,Pddlen);                              //~vawgI~
UTRACED("inp dddbcs",Pdddbcs,Pddlen);                              //~vawgI~
	opt=0;                                                         //~vawgI~
	rc2=xeutfcvdd2u(opt,Pdddata,Pdddbcs,Pddlen,&pucs16,&ucslen);   //~vawgR~
    if (rc2)                                                       //~vawgI~
    	return 4;                                                  //~vawgI~
    udsz=(ucslen/2+1)+((ucslen/2)+1)*3+1;//max additional 3 for UD //~vawgI~
    pud=xeutf_buffget(XEUTF_BUFF3,udsz);                           //~vawgI~
    opt=UFCVO_NEW;	//set UD for subchar                           //~vawgM~
	rc2=ufilecvWC2UD(opt,pucs16,pud,udsz,&udlen,NULL/*Ppathtbl*/,0/*Ppathctr*/);//~vawgR~
    *Ppoutlen=udlen;                                               //~vawgI~
    *Ppoutbuff=pud;                                                //~vawgI~
UTRACED("out udd",pud,udlen);                                      //~vawgR~
	if (rc2>UDRC_ERR)                                              //~vawgI~
    	return 4;                                                  //~vawgI~
    return 0;                                                      //~vawgI~
#else                                                              //~vawgI~
int xeutfcvDD2UD(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,int Pbuffsz,UCHAR **Ppoutbuff,int *Ppoutlen)//~vawgI~
{                                                                  //~vawgI~
    int opt,udlen,rc2,udsz,u8len;                                  //~vawgI~
    char *pu8,*pud;                                                //~vawgR~
//**************************************************               //~vawgI~
UTRACED("inp dddata",Pdddata,Pddlen);                              //~vawgI~
UTRACED("inp dddbcs",Pdddbcs,Pddlen);                              //~vawgI~
	opt=0;                                                         //~vawgI~
	rc2=xeutfcvdd2f(opt,Pdddata,Pdddbcs,Pddlen,&pu8,&u8len,NULL/*Ppoutdbcs*/);//~vawgI~
    if (rc2)                                                       //~vawgI~
    	return 4;                                                  //~vawgI~
    udsz=Pbuffsz;//max additional 3 for UD                         //~vawgI~
    pud=xeutf_buffget(XEUTF_BUFF3,udsz);                           //~vawgI~
    opt=UFCVO_FNLC;	//cv to LC when f2l ok                         //~vawgR~
//  opt=UFCVO_ENCUTF8WC;       //enclose all utf8                  //~vawgR~
	rc2=ufilecvU82UDnopath(opt,pu8,u8len,pud,udsz,&udlen);//~v6u9R~//~vawgR~
    if (rc2>=UDRC_ERR)                                             //~vawgR~
    	return 4;                                                  //~vawgI~
    *Ppoutlen=udlen;                                               //~vawgI~
    *Ppoutbuff=pud;                                                //~vawgI~
UTRACED("out udd",pud,udlen);                                      //~vawgI~
    return 0;                                                      //~vawgI~
#endif                                                             //~vawgI~
}//*xeutfcvDD2UD                                                   //~vawgI~
#endif                                                             //~vawgI~
