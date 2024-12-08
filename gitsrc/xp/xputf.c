//*CID://+v997R~:                              update#=  266;      //~v997R~
//***********************************************************      //~v928I~
//* xputf.c : utf8 sub                                             //~v928I~
//***********************************************************      //~v928I~
//v997:160309 v9.32 (LNX)compiler warning                          //~v997I~
//v994:160308 v9.32 W32 compiler warning                           //~v994I~
//v97B:131117 (BUG)-mxu && R/V lineno up when dbcs split by dumpwidth//~v97BI~
//v97A:131117 (BUG)-mtxu && -nn split dbcs was printed by utf8code //~v97AI~
//v97z:131117 (BUG)-mxu && -mr did not fold when utf8 was split    //~v97zI~
//v97s:131111 (BUG of v96t)utf8 n8 prints 2nd byte only on vhexline//~v97sI~
//v97q:131110 (BUG)when utf8 file hhex dump,split utf8 code was printted to next line.//~v97qI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//v96t:130804 (BUG)"mtxu /Rxx /n8" loop                            //~v96tI~
//120629 v968 VC2010:LP64 support                                  //~v968I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//101004 v960 option of hex dump by ucs/utf8 for utf8 (/Y8,/N8)    //~v960I~
//100924 v958 (BUG)vhex print invalid hexdigit if utf8 string split at eol//~v958I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//*************************************************************    //~v928I~
#include <time.h>                                                  //~v928I~
#include <stdio.h>                                                 //~v928I~
#include <stdlib.h>                                                //~v928I~
#include <ctype.h>                                                 //~v928I~
#include <string.h>                                                //~v928I~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
	#include <wchar.h>                                             //~v92nR~
#endif                                                             //~v92nI~
                                                                   //~v928I~
#include <ulib.h>                                                  //~v928I~
#include <ufile.h>                                                 //~v928I~
#include <uerr.h>                                                  //~v928I~
#include <ucvucs.h>                                                //~v928I~
#include <udbcschk.h>                                              //~v928I~
#include <utf.h>                                                   //~v928I~
#include <utrace.h>                                                //~v92nI~
//*********************************************************************//~v928I~
#include  "xp.h"                                                   //~v928I~
#include  "xpinp.h"                                                //~v928I~
                                                                   //~v928I~
#define GLOBAL_XPUTF                                               //~v928R~
#include  "xputf.h"                                                //~v928I~
//*********************************************************************//~v928I~
#define EUC_SS2 0x8e                                               //~v92nI~
#define EUC_SS3 0x8f                                               //~v92nI~
//*********************************************************************//~v92nI~
extern int prntyp;                                                 //~v928I~
extern int keisenconvsw;                                           //~v928I~
extern int dumpmode;                                               //~v928I~
extern int dbcsenv;                                                //~v928R~
extern int  despagesw;       //descending page print sw v5.3a      //~v92dI~
extern int recordsz;       	//input record length                  //~v96tI~
extern int hexdump;       	//hhex dump                            //~v97qI~
extern int dumpwidth;       	//hexdump 1 line dump width	v6.7a  //~v831I~//~v97qI~
//*********************************************************************//~v928I~
static char Sremaindata[8];                                        //~v928R~
static int  Sremaindatalen=0;  //chars in Sutfchars                //~v928R~
static int  Ssplitutf8strlen=0;                                    //~v97qI~
//*********************************************************************//~v928I~
//*init utf8 file read status                                      //~v928I~
//*********************************************************************//~v928I~
int xputf_open(int Popt)                                           //~v928I~
{                                                                  //~v928I~
	if (prntyp!=PRINTER_WIN && !UCBITCHK(swsw4,SW4OUTFILE))        //~v928R~
#ifdef LNX                                                         //~v92nI~
    #ifndef GXP //console version,print by locale                  //~v92nI~
	  if (prntyp!=PRINTER_IBM)	//default                          //~v92nI~
    #endif                                                         //~v92nI~
#endif                                                             //~v92nI~
    	uerrexit("UTF-8 print supports only for printer-type:w(Windows) or output to file",0);//~v928R~
	if (keisenconvsw)                                              //~v928I~
    	uerrexit("UTF-8 print confilicts with %cK option",0,       //~v928R~
						CMDFLAG_PREFIX);                           //~v928I~
	if (despagesw)                                                 //~v92dI~
//  	uerrexit("UTF-8 print confilicts with %cYp(ReversepagePrint) option",0,//~v92dI~//~v96tR~
    	uerrexit("UTF-8 print dose not support %cYp(ReversePagePrint) option.",0,//~v96tI~
						CMDFLAG_PREFIX);                           //~v92dI~
  	if (UCBITCHK(swsw3,SW3FORM2P))                                 //~v928I~
    	uerrexit("Use %cY2 for 2sheet/page print when print UTF-8 encoded file",0,//~v928R~
						CMDFLAG_PREFIX);                           //~v928I~
  	if (dumpmode==2)                                               //~v928I~
    	uerrexit("UTF-8 print confilicts with skim dump(%cMdn) option",0,//~v928R~
						CMDFLAG_PREFIX);                           //~v928I~
#ifdef W32                                                         //~v92dM~
    if (dbcsenv)                                                   //~v928I~
        Gudbcschk_flag|=UDBCSCHK_UTF8|UDBCSCHK_UTF8J;              //~v928M~
    else                                                           //~v928I~
        Gudbcschk_flag|=UDBCSCHK_UTF8|UDBCSCHK_UTF8E;              //~v928M~
    uerrsetopt2(GBL_UERR2_NOCONV,0);                               //~v928R~
#endif                                                             //~v92dI~
	Sremaindatalen=0;                                              //~v92dM~
    return 0;                                                      //~v928I~
}                                                                  //~v928I~
//*********************************************************************//~v928I~
//*ret 1 byte char                                                 //~v928I~
//*********************************************************************//~v928I~
int xputf_getinputfrombuff(long *Ppfpos)                           //~v928R~
{                                                                  //~v928I~
	int ch;                                                        //~v928I~
//***************************:                                     //~v928I~
	if (!Sremaindatalen)                                           //~v928I~
    {                                                              //~v928I~
    	ch=getinput();                                             //~v928R~
        *Ppfpos=readcount;                                         //~v928I~
        return ch;                                                 //~v928I~
    }                                                              //~v928I~
    ch=*Sremaindata;                                               //~v928I~
    if (--Sremaindatalen)                                          //~v928I~
//    	memcpy(Sremaindata,Sremaindata+1,Sremaindatalen);	//shift to top//~v928I~//~v997R~
      	memcpy(Sremaindata,Sremaindata+1,(size_t)Sremaindatalen);	//shift to top//~v997I~
    *Ppfpos=readcount-Sremaindatalen;                              //~v928I~
    return ch;                                                     //~v928I~
}//xputf_getinputfrombuff                                          //~v928I~
//*********************************************************************//~v928I~
//*restore pre-read err byte                                       //~v928I~
//*********************************************************************//~v928I~
int xputf_putinputtobuff(UCHAR *Pdata,int Plen)                    //~v928I~
{                                                                  //~v928I~
//***************************:                                     //~v928I~
	if (Sremaindatalen)                                            //~v928I~
    	memmove(Sremaindata+Plen,Sremaindata,(UINT)Sremaindatalen);//~v928R~
//  memcpy(Sremaindata,Pdata,Plen);                                //~v928I~//~v997R~
    memcpy(Sremaindata,Pdata,(size_t)Plen);                        //~v997I~
    Sremaindatalen+=Plen;                                          //~v928I~
    return Sremaindatalen;                                         //~v928R~
}//xputf_putinputtobuff                                            //~v96tR~
//*********************************************************************//~v928I~
//*utf8 char string input                                          //~v928I~
//chartype: 0:unprintable,1:ascii,2:dbcs,3:sbcs                    //~v928I~
//          5:force eol                                            //~v960I~
//dbcssw2:4:dbcs split,1:not split dbcs                            //~v928I~
//*ret 1 byte char                                                 //~v928I~
//*********************************************************************//~v928I~
int xputf_getinput(int Popt,int Prescol,char *Putfstr,int *Pputfstrlen,int *Ppucs,int *Ppchartype,int *Ppdbcssw,long *Ppreadcnt)//~v928R~
{                                                                  //~v928I~
	int chartype=0;	//unprintable                                  //~v928R~
	int dbcssw=0;	//sbcs                                         //~v928I~
//  ULONG ucs;	//sbcs                                             //~v928R~//~v950R~
    UWUCS ucs;	//sbcs                                             //~v950I~
//  int readc,chlen,ch,ii,readlen,utfstrlen=0,remainsw=0,opt;      //~v928R~//~v965R~
    int readc,chlen,ch=0,ii,readlen,utfstrlen=0,remainsw=0,opt;    //~v965I~
    long fpos;                                                     //~v928I~
    UCHAR *pc,utfstr[8];                                           //~v928R~
    int ucslen=1,swucsdumpmode;                                    //~v960R~
    int sweol=0,sweolprint=0;                                      //~v96tR~
    int swhhex;                                                    //~v97qI~
//*******************************                                  //~v928I~
    swucsdumpmode=(Gxpotheropt & GOO_VHEXBYUCS);                   //~v960I~
    swhhex=hexdump;	//hhexdump                                     //~v97qI~
	pc=utfstr;                                                     //~v928R~
	for (;;)                                                       //~v928I~
    {                                                              //~v928I~
    	ucs=readc=xputf_getinputfrombuff(&fpos);                   //~v928R~
        if (readc==XPGIRC_VLEN0)                                   //~v96tI~
        {                                                          //~v97AI~
            ucslen=0;                                              //~v97AI~
        	break;                                                 //~v96tI~
        }                                                          //~v97AI~
    	if (vfmt && GoffsV<recordszVEOL && GoffsV>=recordszV0)  //eolprint//~v96tM~
            sweolprint=1;                                          //~v96tM~
//      UTRACEP("xputf_getinput vfmt=%d,GoffsV=%d,recordszVEOL=%d,recordszV0=%d,sweolprint=%d,dumpwidth=%d\n",//~v97qR~//~v97AR~
//                              vfmt,GoffsV,recordszVEOL,recordszV0,sweolprint,dumpwidth);//~v97qR~//~v97AR~
        GoffsV++;                                                  //~v96tR~
        *pc++=(UCHAR)readc;                                        //~v928I~
        if (readc==EOF)                                            //~v928M~
        	break;                                                 //~v928M~
        if (Ssplitutf8strlen)                                      //~v97qI~
        {                                                          //~v97qI~
            remainsw=5;                                            //~v97qI~
            break;                                                 //~v97qR~
        }                                                          //~v97qI~
	    chlen=UTF8CHARLEN(readc);                                  //~v928I~
//      UTRACEP("xputf_getinput fpos=%x,readc=%x,rescol=%d,chlen=%d,eoloffs=%d\n",fpos,readc,Prescol,chlen,GeoloffsV);//~v968I~//~v96tR~//~v97AR~
        if (!chlen)		//err utf                                  //~v928I~
        {                                                          //~v96tI~
            remainsw=1;	//put unprintable                          //~v96tI~
        	break;                                                 //~v928I~
        }                                                          //~v96tI~
        if (chlen==1)	//ascii                                    //~v928I~
        {                                                          //~v928I~
        	chartype=1;	//ascii                                    //~v928I~
        	break;      //retrn                                    //~v928I~
        }                                                          //~v928I~
                                                                   //~v97qI~
    if (!recordsz && !vfmt)                                        //~v97qR~
    {                                                              //~v97zI~
      if (!swucsdumpmode)                                          //~v960R~
      {                                                            //~v960I~
        if (Popt & XPUTFO_BIN && chlen>Prescol)	//record size limit//~v928I~
        {                                                          //~v97qI~
        if (swhhex)	//hhexdump                                     //~v97qR~
        	remainsw=4;        //hexdump utf8code was split by hhex linewidth//~v97qI~
        else                                                       //~v97qI~
        {                                                          //~v96tI~
        	remainsw=3;                                            //~v96tI~
        	break;	//unprintable                                  //~v928I~
        }                                                          //~v96tI~
        }                                                          //~v97qI~
      }                                                            //~v960I~
    }                                                              //~v97zI~
    else                                                           //~v97zI~
    {                                                              //~v97zI~
        if (swhhex)	//hhexdump                                     //~v97zI~
        	if (chlen>Prescol)	//dumpwidth                        //~v97zI~
        		remainsw=6;        //hexdump utf8code was split by hhex linewidth//~v97zR~
    }                                                              //~v97zI~
        for (ii=1;ii<chlen;ii++)                                   //~v928I~
        {                                                          //~v928I~
    		if (recordsz && !(fpos%recordsz))                      //~v96tI~
            {                                                      //~v96tI~
            	remainsw=1;                                        //~v96tI~
            	break;                                             //~v96tI~
            }                                                      //~v96tI~
            else                                                   //~v96tI~
    		if (vhexdump==2 && !(Prescol-ii)) //recordmode vhex    //~v97qR~
            {                                                      //~v97qI~
      		  if (!swucsdumpmode)                                  //~v97AI~
              {                                                    //~v97AI~
            	remainsw=1;                                        //~v97qI~
            	break;                                             //~v97qI~
              }                                                    //~v97AI~
            }                                                      //~v97qI~
            else                                                   //~v97qI~
    		if (vfmt && GoffsV==recordszVEOL)                      //~v96tR~
            {                                                      //~v96tI~
            	remainsw=1;                                        //~v96tI~
            	break;                                             //~v96tI~
            }                                                      //~v96tI~
            else                                                   //~v97qI~
    		if (vhexdump==3 && !(Prescol-ii)) //vfmt vhex Prescol=dumpwidth-netcol on dympbuff//~v97qR~
            {                                                      //~v97qI~
      		  if (!swucsdumpmode)                                  //~v97AI~
              {                                                    //~v97AI~
            	remainsw=1;                                        //~v97qI~
            	break;                                             //~v97qI~
              }                                                    //~v97AI~
            }                                                      //~v97qI~
        	ch=xputf_getinputfrombuff(&fpos);                      //~v928R~
            if (ch==EOF)                                           //~v928I~
            {                                                      //~v928I~
            	remainsw=1;                                        //~v928I~
            	break;                                             //~v928I~
            }                                                      //~v928I~
            GoffsV++;                                              //~v96tI~
          	*pc++=(UCHAR)ch;                                       //~v928I~
            if (ch==0x0a)                                          //~v958M~
            {                                                      //~v958M~
            	remainsw=1;                                        //~v958M~
            	break;                                             //~v958M~
            }                                                      //~v958M~
        }                                                          //~v928I~
        if (ch==EOF)                                               //~v928I~
        	break;                                                 //~v928I~
        if (ch==0x0a)                                              //~v958I~
        	break;                                                 //~v958I~
#ifdef W32                                                         //~v928I~
		opt=0;		//windows TextOutW support USHORT wide char only//~v928I~
#else                                                              //~v928I~
		opt=UCVUCS_UCS4;                                           //~v928I~
#endif                                                             //~v928I~
//  	if (uccvutf2ucs(opt,utfstr,chlen,&ucs,&readlen))	//invalid utf//~v928R~//~v997R~
    	if (uccvutf2ucs((ULONG)opt,utfstr,chlen,&ucs,&readlen))	//invalid utf//~v997I~
        {                                                          //~v928I~
            remainsw=1;                                            //~v928I~
        	break;                                                 //~v928I~
        }                                                          //~v928I~
//    if (vhexdump>1)                                              //~v96tI~//~v97sR~
      if (vhexdump>1||textmodevhexsw)                              //~v97sI~
        if (swucsdumpmode)                                         //~v960I~
        {                                                          //~v960I~
            if ((ucs>>16))                                         //~v960I~
                ucslen=3;                                          //~v960I~
            else                                                   //~v960I~
            if ((ucs>>8))                                          //~v960I~
                ucslen=2;                                          //~v960I~
            if (ucslen>Prescol)                                    //~v960I~
            {                                                      //~v960I~
                remainsw=2;                                        //~v960I~
                break;                                             //~v960I~
            }                                                      //~v960I~
        }                                                          //~v960I~
        if (remainsw!=4)	//display utf8code on hex part of hhex dump and code was split by linewidth//~v97qI~
        {                                                          //~v97qI~
//      if (utfiswide(0,ucs))                                      //~v928I~//~v997R~
        if (utfiswide(0,(ULONG)ucs))                               //~v997I~
        {                                                          //~v928I~
            chartype=2;                                            //~v928I~
	        if (!(Popt & XPUTFO_BIN) && Prescol==1)	//record size limit//~v928I~
            	dbcssw=4;	//dbcs split at EOL                    //~v928I~
            else                                                   //~v928I~
            	dbcssw=1;   //dbcs not split                       //~v928I~
        }                                                          //~v928I~
        else                                                       //~v928I~
//* chartype==3:sbcs                                               //~v96tI~
            chartype=3;                                            //~v928I~
        }                                                          //~v97qI~
        break;                                                     //~v928I~
    }//infinite loop                                               //~v928I~
//  utfstrlen=(ULONG)pc-(ULONG)utfstr;                             //~v928I~//~v968R~
//  utfstrlen=(ULPTR)pc-(ULPTR)utfstr;                             //~v968I~//~v997R~
    utfstrlen=PTRDIFF(pc,utfstr);                                  //~v997I~
//  UTRACEP("xputf_getinput ucs=%x,remainsw=%d,ucslen=%d,utfstrlen=%d,dbcssw=%d\n",ucs,remainsw,ucslen,utfstrlen,dbcssw);//~v968I~//~v96tR~//~v97AR~
    if (remainsw==6)  //reached to linewidth by ucs code R or V    //~v97zI~
    {                                                              //~v97zI~
        fpos-=utfstrlen-1;                                         //~v97zI~
        GoffsV-=utfstrlen-1;                                       //~v97zI~
	    xputf_putinputtobuff(utfstr+1,utfstrlen-1);                //~v97zI~
        utfstrlen=1;                                               //~v97zI~
	    *Putfstr=*utfstr;                                          //~v97zI~
        chartype=0;                                                //~v97zI~
	    UTRACEP("xeutf_getinput hhexsplit VR readc=%x\n",readc);   //~v97zI~
    }                                                              //~v97zI~
    else                                                           //~v97zI~
    if (remainsw==3)  //reached to linewidth by ucs code           //~v96tI~
    {                                                              //~v96tI~
        fpos-=utfstrlen;                                           //~v96tI~
        GoffsV-=utfstrlen;                                         //~v96tR~
        xputf_putinputtobuff(utfstr,utfstrlen);                    //~v96tI~
//      *utfstr=ucs=readc=' ';                                     //~v96tI~//~v994R~
        *utfstr=(UCHAR)(ucs=readc=' ');                            //~v994I~
        chartype=6; //force eol                                    //~v96tI~
        utfstrlen=1;                                               //~v96tI~
    }                                                              //~v96tI~
    else                                                           //~v96tI~
    if (remainsw==4||remainsw==5)  //hhex,split utf8               //~v97qR~
    {                                                              //~v97qI~
    	if (remainsw==4)                                           //~v97qR~
        {                                                          //~v97qI~
        	fpos-=utfstrlen-1;                                     //~v97qI~
        	GoffsV-=utfstrlen-1;                                   //~v97qI~
	        xputf_putinputtobuff(utfstr+1,utfstrlen-1);            //~v97qI~
        	Ssplitutf8strlen=utfstrlen-1;                          //~v97qR~
	        UTRACEP("xeutf_getinput hhexsplit readc=%x\n",readc);  //~v97qI~
        }                                                          //~v97qI~
        else                                                       //~v97qI~
        {                                                          //~v97qI~
        	Ssplitutf8strlen--;                                    //~v97qI~
//      	*utfstr=readc;                                         //~v97qR~//~v994R~
        	*utfstr=(UCHAR)readc;                                  //~v994I~
            chartype=0; //unprintable                              //~v97qI~
	        UTRACEP("xeutf_getinput hhexsplit readc next=%x\n",readc);//~v97qI~
        }                                                          //~v97qI~
          if (Prescol==1)                                            //~v97qI~
              chartype=7; //force eol as unprintable                 //~v97qI~
          else                                                       //~v97qI~
	        chartype=0; //unprintable                              //~v97qI~
        utfstrlen=1;                                               //~v97qI~
	    *Putfstr=*utfstr;                                          //~v97qI~
    }                                                              //~v97qI~
    else                                                           //~v97qI~
    if (remainsw)                                                  //~v928I~
    {                                                              //~v928I~
      if (remainsw==2)  //reached to linewidth by ucs code         //~v960I~
      {                                                            //~v960I~
        fpos-=utfstrlen;                                           //~v960I~
        GoffsV-=utfstrlen;                                         //~v96tI~
        xputf_putinputtobuff(utfstr,utfstrlen);                    //~v960I~
//      *utfstr=ucs=readc=' ';                                     //~v960R~//~v994R~
        *utfstr=(UCHAR)(ucs=readc=' ');                            //~v994I~
        chartype=5; //ascii                                        //~v960R~
      }                                                            //~v960I~
      else                                                         //~v960I~
      {                                                            //~v960I~
    	fpos-=utfstrlen-1;                                         //~v928I~
    	GoffsV-=utfstrlen-1;                                       //~v96tI~
		xputf_putinputtobuff(utfstr+1,utfstrlen-1);                //~v928I~
      }                                                            //~v960I~
    	utfstrlen=1;	//return 1 byte unprintable                //~v928R~
	    *Putfstr=*utfstr;                                          //~v958I~
        UTRACEP("xputf_getinput remainsw on fpos=%x,utfstrlen=%d\n",fpos,utfstrlen);//~v968I~
    }                                                              //~v928I~
    else                                                           //~v928I~
    if (readc!=XPGIRC_VLEN0)                                       //~v97AI~
    {                                                              //~v960I~
        if (swucsdumpmode)                                         //~v960I~
      	{                                                          //~v960I~
        	if (ucslen==3)                                         //~v960R~
            	UUL32BESTR(ucs,utfstr);                            //~v960I~
            else                                                   //~v960I~
        	if (ucslen==2)                                         //~v960R~
            	UUS2BESTR(ucs,utfstr);                             //~v960I~
            else                                                   //~v960I~
//          	*utfstr=ucs;                                       //~v960I~//~v994R~
            	*utfstr=(UCHAR)ucs;                                //~v994I~
            utfstrlen=ucslen;                                      //~v960I~
      	}                                                          //~v960I~
	    memcpy(Putfstr,utfstr,(UINT)utfstrlen);                    //~v928I~
    }                                                              //~v960I~
    *Pputfstrlen=utfstrlen;                                        //~v928I~
    *Ppucs=ucs;                                                    //~v928I~
    *Ppchartype=chartype;                                          //~v928I~
    *Ppdbcssw=dbcssw;                                              //~v928I~
    if (recordsz && !(fpos%recordsz))                              //~v96tI~
		sweol=1;	//                                             //~v96tI~
    else                                                           //~v96tI~
    if (vfmt && GoffsV==recordszVEOL)                              //~v96tR~
		sweol=1;	//                                             //~v96tI~
    if (sweol)                                                     //~v96tI~
    	fpos=0;	//next is top of record                            //~v96tI~
    if (sweolprint)                                                //~v96tR~
	    Geolprintcol++;                                            //~v96tR~
    else                                                           //~v96tI~
	    Geolprintcol=0;                                            //~v96tR~
    *Ppreadcnt=fpos;                                               //~v928I~
//UTRACEP("xputf_getinut Prescol=%d,dbcssw=%d,ucs=%04x,chartype=%d,fpos=x%x,GoffsV=x%x,utfstrlen=%d\n",Prescol,dbcssw,ucs,chartype,fpos,GoffsV,utfstrlen);          //~v92nI~//~v960R~//~v96tR~//~v97qR~//~v97AR~
    return readc;                                                  //~v928I~
}//xputf_getinput                                                  //~v928I~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
//****************************************************************************//~v92nI~
//write line into console                                          //~v92nI~
//parm1:text addr                                                  //~v92nI~
//parm2:text len                                                   //~v92nI~
//****************************************************************************//~v92nI~
int utf_fwrite(char *Pbuff,unsigned long Plen,FILE *Ppfh)          //~v92nR~
{                                                                  //~v92nI~
    int writelen,len,ii,rc;                                        //~v92nR~
//  USHORT  *pucs;                                                 //~v92nR~//~v950R~
    WUCS    *pucs;                                                 //~v950I~
	wchar_t wc;                                                    //~v92nR~
    char mbbuff[MAXLINEWIDTH*UTF8_MAXCHARSZMAX],repch='?',*pc;     //~v92nI~
    mbstate_t mbstate;                                             //~v92nI~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
    int ss3errchk;                                                 //~v92nI~
#endif                                                             //~v92nI~
#ifdef CCC                                                         //~v92nR~
    int lastlen=0,lastch=0;                                        //~v92nI~
#endif                                                             //~v92nI~
//********************************                                 //~v92nI~
UTRACED("wc2mb ucs",Pbuff,(int)Plen);                                   //~v92nI~//~v997R~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
	ss3errchk=(Gudbcschk_flag & UDBCSCHK_EUC) && !UCBITCHK(swsw4,SW4SS3);//rep ss3 to ?//~v92nI~
#endif                                                             //~v92nI~
//	pucs=(USHORT*)(ULONG)Pbuff;                                    //~v92nR~//~v950R~
  	pucs=(WUCS*)(ULONG)Pbuff;                                      //~v950I~
//  len=Plen/sizeof(USHORT);                                       //~v92nI~//~v950R~
//  len=Plen/WUCSSZ;                                               //~v950I~//~v997R~
    len=(int)Plen/WUCSSZ;                                          //~v997I~
    memset(&mbstate,0,sizeof(mbstate_t));                          //~v92nR~
    for (ii=0,pc=mbbuff;ii<len;ii++,pucs++)                        //~v92nI~
    {                                                              //~v92nI~
        wc=(wchar_t)*pucs;                                         //~v92nR~
#ifdef CCC                                                         //~v92nI~
			lastch=wc;                                             //~v92nI~
#endif                                                             //~v92nI~
        if (!wc)                                                   //~v92nI~
        {                                                          //~v92nI~
        	*pc++=repch;                                           //~v92nI~
#ifdef CCC                                                         //~v92nI~
			lastlen=-1;                                            //~v92nI~
#endif                                                             //~v92nI~
        }                                                          //~v92nI~
        else                                                       //~v92nI~
        {                                                          //~v92nI~
UTRACED("before mbstate",&mbstate,sizeof(mbstate));                //~v92nR~
//    		writelen=wcrtomb(pc,wc,&mbstate);                      //~v92nR~
//    		writelen=wcrtomb(pc,wc,0);                             //~v92nI~//~v997R~
      		writelen=(int)wcrtomb(pc,wc,0);                        //~v997I~
#ifdef CCC                                                         //~v92nI~
			llastlen=writelen;                                     //~v92nI~
#endif                                                             //~v92nI~
UTRACEP("wc=%x,writelen=%d\n",wc,writelen);                        //~v92nI~
            if (writelen<0)                                        //~v92nI~
            {                                                      //~v92nI~
            	*pc++=repch;                                       //~v92nI~
		    	memset(&mbstate,0,sizeof(mbstate_t));              //~v92nR~
            }                                                      //~v92nI~
            else                                                   //~v92nI~
            {                                                      //~v92nI~
UTRACED("wcrtomb",pc,writelen);                                    //~v92nI~
UTRACED("after mbstate",&mbstate,sizeof(mbstate));                 //~v92nR~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
				if (ss3errchk                                      //~v92nI~
				&&  (writelen==3 && *pc==EUC_SS3)                  //~v92nR~
                   )                                               //~v92nI~
                {                                                  //~v92nI~
                	if (utfiswide(0,(ULONG)wc))                    //~v92nI~
                    	*pc++=repch;                               //~v92nR~
                	*pc++=repch;                                   //~v92nR~
                }                                                  //~v92nI~
                else                                               //~v92nI~
#endif                                                             //~v92nI~
        	    	pc+=writelen;                                  //~v92nR~
            }                                                      //~v92nI~
        }                                                          //~v92nI~
    }                                                              //~v92nI~
#ifdef CCC                                                         //~v92nI~
	if (lastlen>2 && lastch==0x0a)                                 //~v92nI~
    {                                                              //~v92nI~
		llastlen=writelen;                                         //~v92nI~
    }                                                              //~v92nI~
#endif                                                             //~v92nI~
    writelen=(int)((ULONG)pc-(ULONG)mbbuff);                       //~v92nI~
UTRACED("wc2mb",mbbuff,writelen);                                  //~v92nI~
    if (writelen==fwrite(mbbuff,1,(UINT)writelen,Ppfh))            //~v92nR~
//  	rc=Plen;                                                   //~v92nR~//~v997R~
    	rc=(int)Plen;                                              //~v997I~
    else                                                           //~v92nI~
    	rc=-1;                                                     //~v92nI~
    return rc; //err                                               //~v92nR~
}//lnx_putline                                                     //~v92nI~
#endif                                                             //~v92nI~
#ifdef GTKPRINT                                                    //~v97mI~
//****************************************************************************//~v97mI~
//rc=0:utf8 code found,1:all ascii:utf8 err,                       //~v97mI~
//****************************************************************************//~v97mI~
int xputf_f2u(char *Pputf8,int Putf8len,WUCS* Ppucs,int *Ppucsctr,int *Ppwidth)//~v97mR~
{                                                                  //~v97mI~
	int opt,rc=0,rc2,readlen;                                      //~v97mR~
//*******************************                                  //~v97mI~
	UTRACED("xputf_f2u inp",Pputf8,Putf8len);                      //~v97mR~
	opt=0;                                                         //~v97mI~
	rc2=utfcvf2u(opt,Ppucs,Pputf8,NULL/*Ppchof*/,NULL/*Ppdbcs*/,0/*Pinitoffs*/,Putf8len,&readlen,Ppucsctr,Ppwidth);//~v97mI~
	UTRACEP("xputf_f2u utfcvf2u rc=%d\n",rc2);                     //~v97mR~
	UTRACED("xputf_f2u out",Ppucs,*Ppucsctr*(int)sizeof(WUCS));         //~v97mI~//+v997R~
    if (rc2 & ~(UTFF2U_SBCS|UTFF2U_DBCS))                          //~v97mR~
    	rc=4;                                                      //~v97mI~
    else                                                           //~v97mI~
    if (*Ppucsctr==Putf8len)	//all ascii	                       //~v97mI~
    	rc=1;                                                      //~v97mI~
	UTRACEP("xputf_f2u rc=%d,ucsctr=%d,width=%d\n",rc,*Ppucsctr,*Ppwidth);//~v97mI~
    return rc;                                                     //~v97mI~
}//xputf_f2u                                                       //~v97mI~
#endif                                                             //~v97mI~
