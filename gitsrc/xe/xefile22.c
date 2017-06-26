//*CID://+vb30R~:                             update#=  375;       //+vb30R~
//*************************************************************
//*xefile2.c  *                                                 //~v04dR~
//* hex mode                                                       //~v440R~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vb22:160109 (BUG)vhexline csr pos did not consider dbcs split at UFCleft//~vb22I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vajf:130807 xpr **;print hex part by ascii because cp930/cp939 differ for small letter//~vajfI~
//vaje:130807 (BUG)invalid print char whem "xpr **"for hhex scr with leftcol!=0//~vajeI~
//vaja:130804 (BUG)-xprint ebc 3line dump "xpr **",lower case letter is transleted to katakana,use upper//~vajaI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120608 (VC6)Bug found by C4701                              //~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7k:100821 (BUG)FWF cmd;getword fail on ebc file when delm str input is by utf8.//~va7kI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5a:100502 (BUG) FWF cmd,punctuation is not effebctive when multimute delm not found(1 byte delm case is ok)//~va5aI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va37:100205 issue warning for "u" key on non-utf8 file           //~va37I~
//va25:091210 (BUG)FWF dbcs punctuation position                   //~va25I~
//va24:091210 (BUG)FWF may match width delm string length          //~va24I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file22.c:vhexline display from dd fmt                //~va20I~
//                     wordget:puctuation chk for ddfmt            //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va0A:090721_add Japanese DBCS delimiter for searchword (A+],A+[) //~va0AI~
//v7av:090411 allow dbcs boundary char for FWF/FWB                 //~v7avI~
//v7au:090411 (BUG)of v7aq filegetwor delm parm=null from xecap    //~v7auI~
//v7aq:090314 FWF(getword) chk from not prev but current cursor position//~v7aqI~
//            and use standard puctuation if not found             //~v7aqI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v77h:071229 (BUG)h-hex display data csr reverse the pos of EOL id"|"//~v77hI~
//v773:071121*Ctrl+Tab for function that cursor jump between char and ehx part//~v773I~
//v74t:070221 C&P word-copy consider COB margin                    //~v74tI~
//v73n:070117 (BUG)hexmode edit cursor DEL on hex part should back 1 col if data is longer than width//~v73nI~
//v735:070104 support vhex line insert                             //~v735I~
//v70j:060802*(BUG)hex edit csr positioning err when ulhlen<fhwidth//~v70jI~
//v70h:060802*(BUG)/mh input 2nd byte is not 0 padding when added on end of file//~v70hI~
//v65b:050727 (BUG)vhex mode;skip tab(currently input avail but ignored)//~v65bI~
//v61w:050308 xprint on vhex mode                                  //~v61wI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v59v:041114 (BUG)hex disp mode:display char part column when csr is on hex part//~v59vR~
//v59u:041114 (BUG)hexinput:del cur pos if csr is on later half of byte//~v59vR~
//v59t:041114 hexinput:allow input at end of line                  //~v59vR~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v455:011208 (BUG)tab reple change hi-4bit+0(because tab is x20 on data fld)//~v455I~
//v44m:011204 option of upper/lower hex code display               //~v44mI~
//v446:011201 default cols data for hex edit                       //~v446I~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v444:011201 del on hex part                                      //~v444I~
//v443:011201 colr on data csr corresponding on csr on hex part    //~v443I~
//v442:011201 skip csr over hex intermidiate space                 //~v442I~
//v441:011130 edit   hex                                           //~v441I~
//v440:011125 browse hex                                           //~v440I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5318I~
#include <uedit2.h>                                                //~v440I~
#include <ustring.h>                                               //~v77EI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20I~
#include <utf22.h>                                                 //~va20I~
#include <utrace.h>                                                //~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefunc.h"
#include "xefile.h"
#include "xefile22.h"                                              //~v440I~
#include "xechar.h"                                                //~v440I~
#include "xeopt.h"                                                 //~v44mI~
#include "xeerr.h"                                                 //~v53cI~
#include "xefsub.h"                                                //~v61wI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub2.h"                                                //~va20R~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va5aI~
//*******************************************************
static int Shpose;                                                 //~v446R~
static int Sscrprint;                                              //~vajeI~
//*******************************************************          //~v445I~
//int filegethexpos(int Phpos,int Phpose,int Pdataoffs);           //~v773R~
//int filegetdatapos(int Phpos,int Phpose,int Poffs,int *Ppdpos,int Popt);//~v59uR~
//*******************************************************          //~vajaI~
int fileupper(char *Plower,int Plen)                               //~vajaI~
{                                                                  //~vajaI~
	int ii;                                                        //~vajaI~
    char *pc;                                                      //~vajaR~
//*********************                                            //~vajaI~
	for (ii=0,pc=Plower;ii<Plen;ii++,pc++)                         //~vajaI~
//  	*pc=toupper(*pc);                                          //~vaz8R~
    	*pc=(UCHAR)toupper(*pc);                                   //~vaz8I~
    return 0;                                                      //~vajaI~
}                                                                  //~vajaI~
//**************************************************************** //~v445I~
// filehexprint                                                    //~v445I~
//*set hex data for xprint **                                      //~v445I~
//*parm1:pcw                                                       //~v445I~
//*parm2:plh                                                       //~v445I~
//*rc   :total print line len                                      //~v445I~
//**************************************************************** //~v445I~
//int filehexprint(PUCLIENTWE Ppcw,PULINEH Pplh)                     //~v445I~//~va81R~
int filehexprint(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh)//~va81I~
{                                                                  //~v445I~
	int plhlen,hexcsr=0,datacsr=0,rlen;                            //~v445R~
    UCHAR *pc;                                                     //~v445I~
    UCHAR *pc0;                                                    //~va81I~
    int wlen;                                                      //~va81I~
//*************************                                        //~v445I~
	plhlen=Pplh->ULHlen;                                           //~v445I~
	pc0=                                                           //~va81I~
    pc=Gfilebuff+plhlen;                                           //~v445I~
	rlen=GFILEBUFFSZ*2-plhlen;                                     //~v445I~
    *pc++=' ';          //for eolid                                //~v445I~
    rlen--;                                                        //~v445I~
    UTRACEP("filehexprint opt=%x,rlen=%d\n",Popt,rlen);            //~vajaI~
    if (rlen)                                                      //~v445I~
    {                                                              //~va81I~
    	Sscrprint=1;                                               //~vajeI~
		filehexdisplay(Ppcw,pc,rlen,plhlen,Pplh,&hexcsr,&datacsr); //~v445R~
    	Sscrprint=0;                                               //~vajeI~
        if (Popt & FHPO_WXPEBC)                                    //~va81I~
        {                                                          //~va81I~
        	wlen=Shpose-plhlen;                                    //~va81R~
            UTRACED("filehexprint before a2b",pc0,wlen);           //~vajaM~
    		if (!UCBITCHK(Goptopt,GOPT_HEX_UPPER))                 //~vajaI~
    			fileupper(pc0,wlen);                               //~vajaI~
    		ucvebc_a2bfld(0,Ppfh->UFHhandle,pc0,pc0,wlen);         //~va81I~
            UTRACED("filehexprint after  a2b",pc0,wlen);           //~vajaI~
        }                                                          //~va81I~
    }                                                              //~va81I~
    else                                                           //~v445I~
    	Shpose=plhlen;                                             //~v445I~
    return Shpose;		//print lenght                             //~v445I~
}//filehexprint                                                    //~v445I~
//**************************************************************** //~v440I~
// filehexdisplay                                                  //~v440I~
//*set hex data for hex display mode                               //~v440I~
//*parm1:pcw                                                       //~v440I~
//*parm2:data addr on psd                                          //~v440I~
//*parm3:screen line residual len                                  //~v445R~
//*parm4:screen line data set len                                  //~v445R~
//*parm5:plh                                                       //~v445R~
//*parm6:input csr offs,output hex data pos correspondig to csr pos//~v445R~
//*parm7:output -1 or data pos correspondig to csr pos on hex part //~v445R~
//*rc   :none                                                      //~v440I~
//**************************************************************** //~v440I~
UCHAR *filehexdisplay(PUCLIENTWE Ppcw,UCHAR *Ppdata,int Preslen,   //~v440R~
		int Pdatalen,PULINEH Pplh,int *Phexcsr,int *Pdatacsr)      //~v443R~
{                                                                  //~v440I~
	PUFILEC pfc;                                                   //~v440I~
	PUFILEH pfh;                                                   //~v440I~
	UCHAR *phex,*phexe,*pdata,*pdata0,*pdbcs,*pdbcs0,*tabpos;      //~v440R~
    int   roffs,loffs,coffs,len,dpos,dpose,hpos,hpose,poss,pose;   //~v440R~
    int   ii,jj,oddsw,oddsw2,skiplen,csrx,hcsrx,hlen,rlen,dposc;   //~v443R~
    int   ulopt;                                                   //~v44mI~
    UCHAR hexdata[MAXCOLUMN*2]; //conv only display width          //~v440R~
    UCHAR srcdata[MAXCOLUMN]; //conv only display width            //~v440I~
//*****************                                                //~v440I~
	pfc=Ppcw->UCWpfc;                                              //~v440I~
	pfh=pfc->UFCpfh;                                               //~v440I~
  if (Sscrprint)                                                   //~vajeI~
    loffs=0;                                                       //~vajeI~
  else                                                             //~vajeI~
    loffs=pfc->UFCleft;             //left most column             //~v440R~
    coffs=loffs+Pdatalen+1;			//for EOL id                   //~v440R~
    roffs=coffs+Preslen;	//right most pos                       //~v440I~
	csrx=*Phexcsr;			//offset in filearea                   //~v440R~
    *Phexcsr=-1;			//once clear output                    //~v440M~
    *Pdatacsr=-1;			//once clear output                    //~v443I~
                                                                   //~v440I~
    filegethposrange(pfh,Pplh->ULHlen,&hpos,&hpose);//get hex area range//~v446R~
    Shpose=hpose;			//return to filehexprint               //~v445I~
    skiplen=hpos-coffs;		//len between last printed and top hex pos//~v440I~
    pdata0=Ppdata;                                                 //~v440I~
    if (skiplen>0)                                                 //~v440R~
    {                                                              //~v440I~
        memset(pdata0,' ',(UINT)skiplen);                          //~v455R~
    	pdata0+=skiplen;                                           //~v440I~
        coffs+=skiplen;                                            //~v440I~
    }                                                              //~v440I~
//chk wether hex pard is on screen                                 //~v440I~
	poss=max(coffs,hpos);                                          //~v440R~
    oddsw=filegetdatapos(hpos,hpose,poss,&dpos,0);//left most data pos//~v440R~
    if (dpos<0)	//window is right of hex area                      //~v440I~
    	return 0;                                                  //~v440I~
	pose=min(roffs,hpose);                                         //~v440R~
    oddsw2=filegetdatapos(hpos,hpose,pose,&dpose,0);//right most data pos//~v440I~
    if (dpose<0)	//window is left of hex area                   //~v440I~
    	return 0;                                                  //~v440I~
    if (csrx>=0)        //csr line                                 //~v443R~
    {                                                              //~v440I~
		csrx+=loffs;		//offset in ULHdata                    //~v440I~
        hcsrx=filegethexpos(hpos,hpose,csrx);                      //~v440R~
        if (hcsrx>=0)                                              //~v440R~
            *Phexcsr=hcsrx-loffs;   //cols in file area            //~v440R~
//  	if (filegetdatapos(hpos,hpose,csrx,&dposc,1)>=0//right most data pos//~v77hR~
    	if (csrx<hpose                          //avoid EOL id "|" //~v77hR~
    	&&  filegetdatapos(hpos,hpose,csrx,&dposc,1)>=0//right most data pos//~v77hI~
        &&  dposc>=0)                                              //~v443R~
            *Pdatacsr=dposc-loffs;   //cols in file area           //~v443I~
    }                                                              //~v440I~
//conv data                                                        //~v440I~
    len=dpose-dpos+oddsw2;                                         //~v440R~
    len=min(len,MAXCOLUMN); //conv only screen width               //~v441R~
//restore tabchar                                                  //~v440I~
    memcpy(srcdata,Pplh->ULHdata+dpos,(UINT)len);                  //~v455R~
    pdbcs=pdbcs0=Pplh->ULHdbcs+dpos;                               //~v440I~
    for (rlen=len;rlen;)                                           //~v440I~
    {                                                              //~v440I~
//*no TABCHAR on dbcstbl for ebcfile                               //~va5aI~
    	tabpos=memchr(pdbcs,TABCHAR,(UINT)rlen);                   //~v455R~
        if (!tabpos)                                               //~v440I~
        	break;                                                 //~v440I~
//      rlen=(int)((ULONG)tabpos-(ULONG)pdbcs0);                   //~v455R~//~vafkR~
        rlen=(int)((ULPTR)tabpos-(ULPTR)pdbcs0);                   //~vafkI~
        *(srcdata+rlen)=TABCHAR;                                   //~v440R~
        rlen=len-rlen-1;                                           //~v440R~
        pdbcs=tabpos+1;                                            //~v440I~
        if (!rlen)                                                 //~v440I~
        	break;                                                 //~v440I~
    }                                                              //~v440I~
    if (UCBITCHK(Goptopt,GOPT_HEX_UPPER))                          //~v44mI~
        ulopt=UBX_UPPER;                                           //~v44mI~
    else                                                           //~v44mI~
        ulopt=UBX_LOWER;                                           //~v44mI~
	ub2x(ulopt,hexdata,srcdata,len);                               //~v44mR~
    phex=hexdata+oddsw;                                            //~v440R~
    phexe=hexdata+len+len;                                         //~v441I~
    hlen=pose-poss;                                                //~v440I~
    for (ii=coffs-hpos,jj=0,pdata=pdata0;jj<hlen;ii++,jj++,pdata++)//~v440R~
    	if (ii%9!=8 && phex<phexe)                                 //~v445R~
          	*pdata=*phex++;                                        //~v445R~
        else                                                       //~v445I~
        	*pdata=' ';                                            //~v445R~
    return pdata0;                                                 //~v440R~
}//filehexdisplay                                                  //~v440I~
//**************************************************************** //~v441R~
// filecharhexinput                                                //~v441R~
//*set hex data to plhdata                                         //~v441R~
//*parm1:pcw                                                       //~v441R~
//*parm2:pfh                                                       //~v441R~
//*parm3:plh                                                       //~v441R~
//*parm4:input:current,output:next;cusor step count                //~v441R~
//*parm5:data offset                                               //~v441I~
//*parm6:operation code                                            //~v441R~
//*rc   :0:continue normal process,1:hex input accepted,           //~v441R~
//       4:protected,8:input data err(not hex digit)               //~v441R~
//**************************************************************** //~v441R~
int filecharhexinput(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,    //~v441R~
					int Pcsrpos,int *Ppdoffs,int Popcode)          //~v441R~
{                                                                  //~v441R~
    int   dpos,hpos,hpose,chi,cho;                                 //~v441R~
    int   oddsw,keyindatalen;                                      //~v442R~
    UCHAR *keyindata;                                              //~v441R~
    int shortsw;                                                   //~v70jI~
//*****************                                                //~v441R~
//csr pos chk                                                      //~v441R~
	keyindata=Ppcw->UCWkeydata;                                    //~v441R~
	keyindatalen=Ppcw->UCWkeytype;                                 //~v441R~
    shortsw=Pplh->ULHlen<Ppfh->UFHwidth;//if short no csr advance by data part char insert//~v70jI~
    filegethposrange(Ppfh,Pplh->ULHlen,&hpos,&hpose);//get hex area range//~v446R~
    if (Pcsrpos<hpos)                                              //~v441R~
    	return 0;	//continue to accept normal input              //~v441R~
    oddsw=filegetdatapos(hpos,hpose,Pcsrpos,&dpos,1);//left most data pos//~v441R~
    if (oddsw<0)	//csr on intermediate space                    //~v441R~
    	return 4;   //protected                                    //~v441R~
    if (dpos<0)		//csr outof range                              //~v444I~
    {                                                              //~v59cI~
  	  if (Popcode!=CHAROPDEL		//rep 2nd half                 //~v59cI~
      &&  Pcsrpos==hpose+1  	//may be after boundary space      //~v59cI~
      &&  filegetdatapos(hpos,hpose,Pcsrpos-1,&dpos,1)<0)//eol is boundary//~v59cI~
      	oddsw=0;                                                   //~v59cI~
      else                                                         //~v59cI~
    	return 4;   //protected                                    //~v444I~
    }                                                              //~v59cI~
    if (oddsw && Popcode==CHAROPINS)		//rep 2nd half         //~v441I~
		return FCHI_ODDINS;                                        //~v441R~
    *Ppdoffs=dpos;                                                 //~v444M~
  if (Popcode!=CHAROPDEL)		//rep 2nd half                     //~v444M~
  {                                                                //~v444M~
//hex code chk                                                     //~v441R~
	if (keyindatalen!=1)                                           //~v441R~
    	return 8;					//invalid data                 //~v441R~
    chi=toupper(*keyindata);                                       //~v441R~
    if (chi>='0' && chi<='9')                                      //~v441R~
		chi=chi-'0';                                               //~v441R~
	else                                                           //~v441R~
	if (chi>='A' && chi<='F')                                      //~v441R~
		chi=chi-'A'+10;                                            //~v441R~
    else	                                                       //~v441R~
    	return 8;					//invalid data                 //~v441R~
//get data                                                         //~v441R~
  if (dpos>=Pplh->ULHlen)                                          //~v70hR~
    cho=0;                                                         //~v70hI~
  else                                                             //~v70hI~
	cho=*(Pplh->ULHdata+dpos);                                     //~v441R~
                                                                   //~v70jI~
    if (oddsw)		//csr on later half byte                       //~v441R~
    {                                                              //~v441I~
//*no TABCHAR on dbcstbl for ebcfile                               //~va5aI~
		if (cho==' ' && (*(Pplh->ULHdbcs+dpos)==TABCHAR))          //~v455I~
        	cho=TABCHAR;                                           //~v455I~
    	cho=(cho & 0xf0)|chi;                                      //~v441R~
        if ((dpos%4)==3)	//                                     //~v441I~
        	Ppcw->UCWreason=UCWREASON_HEXSTEP;	//csr step over intermediate space//~v442R~
    }                                                              //~v441I~
    else                                                           //~v441R~
    	if (Popcode==CHAROPREP)		//rep 2nd half                 //~v441R~
        {                                                          //~v455I~
//*no TABCHAR on dbcstbl for ebcfile                               //~va5aI~
		    if (cho==' ' && (*(Pplh->ULHdbcs+dpos)==TABCHAR))      //~v455R~
        		cho=TABCHAR;                                       //~v455I~
	    	cho=(cho & 0x0f)|(chi<<4);                             //~v441R~
			if (dpos>=Pplh->ULHlen)	//insert at eol                //~v70jI~
            	if (!shortsw)                                      //~v70jI~
		        	Ppcw->UCWreason=UCWREASON_HEXSTEP;	//csr step more 1 column//~v70jI~
        }                                                          //~v455I~
        else                                                       //~v441R~
        {                                                          //~v442I~
	    	cho=(chi<<4);                                          //~v441R~
         if (!shortsw)                                             //~v70jI~
        	Ppcw->UCWreason=UCWREASON_HEXSTEP;	//csr step to odd byte//~v442I~
        }                                                          //~v442I~
    *Ppcw->UCWkeydata=(UCHAR)cho;                                //1 byte data//~v441R~
  }                                                                //~v444I~
  else  //DEL                                                      //~v73nI~
  {                                                                //~v73nI~
    if (Pplh->ULHlen>Ppfh->UFHwidth)	//if long hex part shift to left by DEL key//~v73nI~
		Ppcw->UCWreason=UCWREASON_HEXSTEPDEL;	//csr step more 1 column//~v73nR~
  }                                                                //~v73nI~
    return FCHI_HEX;                                               //~v442R~
}//filecharhexinput                                                //~v441R~
//**************************************************************** //~v440I~
// filegethposrange                                                //~v440R~
//*get hex area range                                              //~v440R~
//*parm1:pfh                                                       //~v440I~
//*parm2:data length                                               //~v446R~
//*parm3:top offset of hex part                                    //~v446I~
//*parm4:end offset of hex part                                    //~v446I~
//*rc   :len between end of data and top of hex area               //~v440R~
//**************************************************************** //~v440I~
int filegethposrange(PUFILEH Ppfh,int Pdatalen,int *Pptop,int *Ppend)//~v446R~
{                                                                  //~v440I~
    int  ulhlen,width,hpos,wordno,resbyte,hlen;                    //~v440R~
//*****************                                                //~v440I~
    ulhlen=Pdatalen;                                               //~v446R~
    width=Ppfh->UFHwidth;                                          //~v440I~
    if (ulhlen<width)                                              //~v440I~
    	hpos=width;                                                //~v440I~
    else                                                           //~v440I~
    	hpos=ulhlen;                                               //~v440I~
    hpos+=HEXMARGIN;                                               //~v440R~
    *Pptop=hpos;                                                   //~v440I~
    wordno=(int)((UINT)ulhlen>>2);                                 //~v455R~
    resbyte=ulhlen%4;                                              //~v440I~
    hlen=wordno*9+(resbyte<<1)-(resbyte==0);                       //~v440I~
    *Ppend=hpos+hlen;                                              //~v440I~
    return 0;                                                      //~v440R~
}//filegethposrange                                                //~v440R~
//**************************************************************** //~v440I~
// filegethexpos                                                   //~v440R~
//*get hex area column for data pos                                //~v440R~
//*parm1:hex part start offset                                     //~v440R~
//*parm2:hex part end   offset                                     //~v440I~
//*parm3:input offset in ULHdata                                   //~v440R~
//*rc   :return pos in hex part                                    //~v440I~
//**************************************************************** //~v440I~
int filegethexpos(int Phpos,int Phpose,int Pdataoffs)              //~v440I~
{                                                                  //~v440I~
    int  hpos,wordno,resbyte;                                      //~v440I~
//*****************                                                //~v440I~
    wordno=(int)((UINT)Pdataoffs>>2);                              //~v455R~
    resbyte=Pdataoffs%4;                                           //~v440I~
    hpos=wordno*9+resbyte+resbyte+Phpos;                           //~v440R~
    if (hpos>=Phpose)                                              //~v440R~
    	return -1;                                                 //~v440I~
    return hpos;                                                   //~v440I~
}//filegethexpos                                                   //~v440I~
//**************************************************************** //~v440I~
// filegetdatapos                                                  //~v440R~
//*get offset in data area for hex area offset                     //~v440R~
//*parm1:hex area top offset                                       //~v440I~
//*parm2:hex area end offset                                       //~v440I~
//*parm3:input offset in hex area                                  //~v440R~
//*parm4:output offset in line data                                //~v440I~
//*parm5:option to chk csr is on intermediate space                //~v440I~
//*rc   :1:byte split sw,-1:offs is on intermediate space sw       //~v440I~
//**************************************************************** //~v440I~
int filegetdatapos(int Phpos,int Phpose,int Poffs,int *Ppdpos,int Popt)//~v440I~
{                                                                  //~v440I~
    int hoffs,rem,wordno,rc;                                       //~v440I~
//*****************                                                //~v440I~
    *Ppdpos=-1;             //id of out of range                   //~v440I~
    if (Poffs>Phpose		//out of range                         //~v440R~
    ||  Poffs<Phpos)		                                       //~v440R~
        return 0;                                                  //~v440I~
    hoffs=Poffs-Phpos;                                             //~v440R~
    wordno=hoffs/9;                                                //~v440R~
    rem=hoffs%9;                                                   //~v440I~
    if (rem==8 && Popt==1)			//on intermediate space        //~v440I~
    	rc=-1;                                                     //~v440I~
    else                                                           //~v440I~
    	rc=rem%2;                                                  //~v440I~
//  *Ppdpos=(int)((wordno<<2)+((UINT)rem>>1));                     //~v455R~//+vb30R~
    *Ppdpos=((wordno<<2)+(rem>>1));                                //+vb30I~
    return rc;                                                     //~v440I~
}//filegetdatapos                                                  //~v440I~
//**************************************************************** //~v53cI~
// filegetword                                                     //~v53cI~
//*get offset in data area for hex area offset                     //~v53cI~
//*parm1:pcw                                                       //~v53cI~
//*parm2:outarea                                                   //~v53cI~
//*parm3:outarea len                                               //~v53cI~
//*rc   :word len or 0 if err                                      //~v53cI~
//**************************************************************** //~v53cI~
//int filegetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppos)        //~v77ER~
int filegetword(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppos,char *Pdelm)//~v77EI~
{                                                                  //~v53cI~
	PUFILEC pfc;                                                   //~v53cI~
	PUFILEH pfh;                                                   //~v53cI~
	PULINEH plh;                                                   //~v53cI~
	PUSCRD  psd;                                                   //~v53cI~
    char *pc,*pc0;   //word get area                               //~v53cR~
    char *pcd0,*pcd;                                               //~v77ER~
    int pos,pos1,ii,len,plhlen,margin,marginr,marginl;             //~v53cR~
    int posp,breaksw;                                              //~v7aqI~
    int mblen;                                                     //~v7avI~
    char *pcmb=NULL;                                                    //~v7avI~//~vafcR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,ddstrlen,dbcspunc,dbcsid;                       //~va20R~
  #ifdef UTF8UCS16                                                 //~vaw3I~
    UCHAR wkddstr[FGW_DELM_MAXLEN*4)];    //ddchar max=2 but for safety(previously sizeof(WUCS)=4 on linux//~vaw3I~
    UCHAR wkdddbcs[FGW_DELM_MAXLEN*4];                             //~vaw3I~
  #else                                                            //~vaw3I~
    UCHAR wkddstr[FGW_DELM_MAXLEN*sizeof(WUCS)];                   //~va20I~
    UCHAR wkdddbcs[FGW_DELM_MAXLEN*sizeof(WUCS)];                  //~va20I~
  #endif                                                           //~vaw3I~
    char *pcmbdbcs=NULL;                                                //~va7kI~//~vafcR~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************                                              //~v53cI~
    if (!CSRONFILEDATA(Ppcw))               //out of screen        //~v53cR~
    {                                                              //~v53cI~
  		errcsrpos();                                               //~v53cI~
        return 0;                                                  //~v53cI~
    }                                                              //~v53cI~
    psd=Ppcw->UCWpsd;                                              //~v53cI~
    psd+=Ppcw->UCWrcsry;                                           //~v53cI~
    plh=psd->USDbuffc;                                             //~v53cI~
    pfc=Ppcw->UCWpfc;                                              //~v53cI~
    pfh=pfc->UFCpfh;                                               //~v53cI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
    handle=pfh->UFHhandle;                                         //~va79I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+pfc->UFCleft;//target pos 1//~v53cI~
    pc0=plh->ULHdata+pos;                                          //~v53cI~
    pcd0=plh->ULHdbcs+pos;                                         //~v77ER~
    plhlen=plh->ULHlen;                                            //~v53cI~
    if (plh->ULHtype!=ULHTDATA                                     //~v53cI~
    ||  pos>=plhlen                                                //~v53cR~
//  ||  *pc0==' '||!*pc0)	//allow start/end from space           //~v77ER~
    )                                                              //~v77EI~
    {                                                              //~v53cM~
        errcsrpos();                                               //~v53cM~
        return 0;                                                  //~v53cM~
    }                                                              //~v53cM~
//margin chk                                                       //~v53cI~
    margin=pfh->UFHmergin;                                         //~v53cR~
    if (pos<margin)                                                //~v53cI~
    {                                                              //~v53cI~
    	marginr=min(margin,plhlen);                                //~v53cI~
		if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file         //~v74tI~
    	{                                                          //~v74tI~
    		if (pos>=0 && pos<SPFCOBNUMFLDLEN)                     //~v74tI~
        	{                                                      //~v74tI~
	        	errcsrpos();                                       //~v74tI~
        		return 0;                                          //~v74tI~
        	}                                                      //~v74tI~
	        marginl=SPFCOBNUMFLDLEN;                               //~v74tI~
    	}                                                          //~v74tI~
        else                                                       //~v74tI~
        marginl=0;                                                 //~v53cI~
    }                                                              //~v53cI~
    else                                                           //~v53cI~
    {                                                              //~v53cI~
    	marginl=margin;                                            //~v53cI~
	    marginr=plhlen;                                            //~v53cI~
    }                                                              //~v53cI~
#ifdef UTF8UCS2                                                    //~va20I~
 if (swutf8file)                                                   //~va20I~
 {                                                                 //~va20I~
//**************************                                       //~va5aR~
//*****swutf8file***********                                       //~va5aI~
//**************************                                       //~va5aI~
  if (Pdelm                                                        //~v7auI~//~va20I~
  &&  !*pcd0                       //not ucs but ascii             //~va20I~
  &&  Pdelm[1]==*pc0               //same as x of "(x" pattern parm//~v7auI~//~va20I~
  &&  Pdelm[0]==FGW_DELM_INCLUDE)  //include left boundary char    //~v7aqI~//~va20I~
  {                                                                //~v7aqI~//~va20I~
    pos1=pos;                                                      //~v7aqI~//~va20I~
  }                                                                //~v7aqI~//~va20I~
  else                                                             //~v7aqI~//~va20I~
  {                                                                //~v7aqI~//~va20I~
    if (Pdelm                                                      //~v7avI~//~va20I~
    &&  (Pdelm[0]==FGW_DELM_INCLUDEM || Pdelm[0]==FGW_DELM_EXCLUDEM)//~v7avI~//~va20I~
    )                                                              //~v7avI~//~va20I~
    {                                                              //~v7avI~//~va20I~
    	mblen=(int)(Pdelm[1]);                                     //~v7avI~//~va20I~
        pcmb=Pdelm+4;                                              //~v7avI~//~va20I~
        xeutfgetddstr(0,pcmb,mblen,wkddstr,sizeof(wkddstr),&ddstrlen,wkdddbcs);//~va20R~
        pcmb=wkddstr;                                              //~va20I~
        mblen=ddstrlen;                                            //~va20I~
    }                                                              //~v7avI~//~va20I~
    else                                                           //~v7avI~//~va20I~
    	mblen=0;                                                   //~v7avI~//~va20I~
  	posp=-1;	//not found id                                     //~v7aqI~//~va20I~
    pcd=pcd0-1;                                                    //~v77EI~//~va20I~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos-1,pc=pc0-1;ii>=marginl;ii--,pc--)                  //~v53cR~//~va20I~
    {                                                              //~v53cI~//~va20I~
    	breaksw=1;                                                 //~v7aqI~//~va20I~
        dbcsid=*pcd;                                               //~va20I~
        if (dbcsid==UDBCSCHK_F2LERR)                               //~va20R~
            break;                                                 //~va20I~
      if (!Pdelm                                                   //~v77EI~//~va20I~
      ||   Pdelm[0]==0)                                            //~v77EI~//~va20I~
      {                                                            //~v77EI~//~va20I~
        if (*pc==' '||!*pc)                                        //~v53cI~//~va20I~
          if (!UDBCSCHK_ISUCSDBCST(dbcsid))                        //~va20I~
            break;                                                 //~v53cI~//~va20I~
      }                                                            //~v77EI~//~va20I~
      else                                                         //~v77EI~//~va20I~
      if (Pdelm[0]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~//~va20I~
      {                                                            //~v77EI~//~va20I~
//        if (uispunct(0,*pc))  //space is not punct,so use uispunct //~v77ER~//~va20R~
//          if(*pcd!=DBCS2NDCHAR) //0x5c may be dbcs 2nd char of Japanese//~v77ER~//~va20R~
//            break;                                                 //~v77EI~//~va20R~
//#ifdef UTF8SUPPH                                                   //~va1qI~//~va20R~
//        if(*pcd==DBCS1STCHAR)                                      //~va0AR~//~va20R~
//            if (uispunctdbcs(0,pc))                                //~va0AI~//~va20R~
//                break;                                             //~va0AI~//~va20R~
//#endif                                                             //~va1qI~//~va20R~
      	if (dbcspunc=utfddispunct(0,pc,pcd,pos-ii),dbcspunc)       //~va20R~
        {                                                          //~va20I~
        	if (dbcspunc==2)                                       //~va20I~
	            ii++;   //back to after DBCS                       //~va20I~
            break;                                                 //~va20I~
        }                                                          //~va20I~
      }                                                            //~v77EI~//~va20I~
      else                                                         //~v77EI~//~va20I~
    {                                                              //~v7avI~//~va20I~
    	if (mblen)	//multibyte                                    //~v7avI~//~va20I~
        {                                                          //~v7avI~//~va20I~
            if (ii>=mblen-1                                        //~v7avR~//~va20I~
//          &&  !memcmp(pcmb,pc-mblen+1,(UINT)mblen))              //~v7avR~//~va20R~
            &&  !xesubddmemcmp(XESUBDDSCO_EQCHKONLY,pcmb,wkdddbcs,pc-mblen+1,pcd-mblen+1,mblen))//~va20R~
            {                                                      //~v7avI~//~va20I~
				if (Pdelm[0]==FGW_DELM_INCLUDEM)	//include      //~v7avI~//~va20I~
                	ii-=mblen;                                     //~v7avI~//~va20I~
                break;                                             //~v7avI~//~va20I~
            }                                                      //~v7avI~//~va20I~
        }                                                          //~v7avI~//~va20I~
        else                                                       //~va20R~
//    if (Pdelm[1]==*pc)                                           //~v77EI~//~va20R~
      if (Pdelm[1]==*pc && !*pcd)                                  //~va20I~
      {                                                            //~v77EI~//~va20I~
      	if (Pdelm[0]==FGW_DELM_INCLUDE)//include                   //~v77ER~//~va20I~
        	ii--;                                                  //~v77EI~//~va20I~
        break;                                                     //~v77EI~//~va20I~
      }                                                            //~v77EI~//~va20I~
//    else      //delm specified but not match                     //~v7aqI~//~va20I~//~va5aR~
      {                                                            //~v7aqI~//~va20I~
//    	if (uispunct(0,*pc))  //space is not punct                 //~v7aqI~//~va20I~//~va5aR~
//        	if(*pcd!=DBCS2NDCHAR)	//0x5c may be dbcs 2nd char of Japanese//~v7aqR~//~va20R~
//        	if(!*pcd)	//not part of dbcs/ucs                     //~va20M~//~va5aR~
      	if (dbcspunc=utfddispunct(0,pc,pcd,pos-ii),dbcspunc)       //~va5aI~
        {                                                          //~va5aI~
            	if (posp<0)                                        //~v7aqI~//~va20I~
                {                                                  //~va5aI~
                  if (dbcspunc==2)                                 //~va5aI~
    	        	posp=ii+1;    //punctuation pos                //~va5aI~
                  else                                             //~va5aI~
    	        	posp=ii;    //punctuation pos                  //~v7aqR~//~va20I~
                }                                                  //~va5aI~
        }                                                          //~va5aI~
      }                                                            //~v7aqI~//~va20I~
    }//!PUNCT                                                      //~v7avI~//~va20I~
    	breaksw=0;                                                 //~v7aqI~//~va20I~
      pcd--;                                                       //~v77EI~//~va20I~
    }                                                              //~v53cI~//~va20I~
    if (!breaksw	                                               //~v7aqI~//~va20I~
    &&   posp>=0)                                                  //~v7aqI~//~va20I~
    	ii=posp;                                                   //~v7aqI~//~va20I~
    pos1=ii+1;                                                     //~v53cI~//~va20I~
  }                                                                //~v7aqI~//~va20I~
//forward chk **************utf8                                   //~va20I~//~va50R~
  if (Pdelm                                                        //~v7auI~//~va20I~
  &&  !*pcd0                      //not UCS                        //~va20I~
  &&  Pdelm[3]==*pc0             //match with "x)" pattern parm    //~v7auI~//~va20I~
  &&  Pdelm[2]==FGW_DELM_INCLUDE)//include  right boundary         //~v7aqI~//~va20I~
  {                                                                //~v7aqI~//~va20I~
    len=pos+1-pos1;                                                //~v7aqI~//~va20I~
  }                                                                //~v7aqI~//~va20I~
  else                                                             //~v7aqI~//~va20I~
  {                                                                //~v7aqI~//~va20I~
    if (Pdelm                                                      //~v7avI~//~va20I~
    &&  (Pdelm[2]==FGW_DELM_INCLUDEM || Pdelm[2]==FGW_DELM_EXCLUDEM)//~v7avI~//~va20I~
    )                                                              //~v7avI~//~va20I~
    {                                                              //~v7avI~//~va20I~
    	mblen=(int)(Pdelm[3]);                                     //~v7avI~//~va20I~
        pcmb=Pdelm+4+FGW_DELM_MAXLEN;                              //~v7avI~//~va20I~
        xeutfgetddstr(0,pcmb,mblen,wkddstr,sizeof(wkddstr),&ddstrlen,wkdddbcs);//~va20R~
        pcmb=wkddstr;                                              //~va20I~
        mblen=ddstrlen;                                            //~va20I~
    }                                                              //~v7avI~//~va20I~
    else                                                           //~v7avI~//~va20I~
    	mblen=0;                                                   //~v7avI~//~va20I~
  	posp=-1;	//not found id                                     //~v7aqI~//~va20I~
    pcd=pcd0+1;                                                    //~v77EI~//~va20I~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos+1,pc=pc0+1;ii<marginr;ii++,pc++)                   //~v53cR~//~va20I~
    {                                                              //~v53cI~//~va20I~
    	breaksw=1;                                                 //~v7aqI~//~va20I~
        dbcsid=*pcd;                                               //~va20I~
      	if (dbcsid==UDBCSCHK_F2LERR)                               //~va20R~
        	break;                                                 //~va20I~
      if (!Pdelm                                                   //~v77EI~//~va20I~
      ||   Pdelm[2]==0)                                            //~v77ER~//~va20I~
      {                                                            //~v77EI~//~va20I~
      	                                                           //~va20I~
        if (*pc==' '||!*pc)                                        //~v53cI~//~va20I~
          if (!UDBCSCHK_ISUCSDBCST(dbcsid))                        //~va20I~
            break;                                                 //~v53cI~//~va20I~
      }                                                            //~v77EI~//~va20I~
      else                                                         //~v77EI~//~va20I~
      if (Pdelm[2]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~//~va20I~
      {                                                            //~v77EI~//~va20I~
//        if (uispunct(0,*pc))                                       //~v77ER~//~v7aqR~//~va20R~
//          if(*pcd!=DBCS2NDCHAR)                                    //~v77ER~//~va20R~
//                break;                                             //~v77ER~//~va20R~
//#ifdef UTF8SUPPH                                                   //~va1qI~//~va20R~
//        if(ii+1<marginr && *(pcd)==DBCS1STCHAR)                    //~va0AI~//~va20R~
//            if (uispunctdbcs(0,pc))                                //~va0AI~//~va20R~
//                break;                                             //~va0AI~//~va20R~
//#endif                                                             //~va1qI~//~va20R~
      	if (utfddispunct(0,pc,pcd,marginr-ii))                     //~va20I~
            break;                                                 //~va20I~
      }                                                            //~v77EI~//~va20I~
      else                                                         //~v77EI~//~va20I~
    {                                                              //~v7avI~//~va20I~
    	if (mblen)	//multibyte                                    //~v7avI~//~va20I~
        {                                                          //~v7avI~//~va20I~
            if (marginr-ii>=mblen                                  //~v7avI~//~va20I~
//          &&  !memcmp(pcmb,pc,(UINT)mblen))                      //~v7avI~//~va20R~
            &&  !xesubddmemcmp(XESUBDDSCO_EQCHKONLY,pcmb,wkdddbcs,pc,pcd,mblen))//~va20R~
            {                                                      //~v7avI~//~va20I~
				if (Pdelm[2]==FGW_DELM_INCLUDEM)	//include      //~v7avI~//~va20I~
                	ii+=mblen;                                     //~v7avI~//~va20I~
                break;                                             //~v7avI~//~va20I~
            }                                                      //~v7avI~//~va20I~
        }                                                          //~v7avI~//~va20I~
        else                                                       //~va20I~
//    if (Pdelm[3]==*pc)                                           //~v77EI~//~va20R~
      if (Pdelm[3]==*pc && !*pcd)                                  //~va20I~
      {                                                            //~v77EI~//~va20I~
      	if (Pdelm[2]==FGW_DELM_INCLUDE)//include                   //~v77ER~//~va20I~
        	ii++;                                                  //~v77EI~//~va20I~
        break;                                                     //~v77EI~//~va20I~
      }                                                            //~v77EI~//~va20I~
//    else      //delm specified but not match                     //~v7aqI~//~va20I~//~va5aR~
      {                                                            //~v7aqI~//~va20I~
//    	if (uispunct(0,*pc))                                       //~v7aqI~//~va20I~//~va5aR~
//        	if(*pcd!=DBCS2NDCHAR)                                  //~v7aqR~//~va20R~
//        	if(!*pcd)	//ascii                                    //~va20I~//~va5aR~
      	if (utfddispunct(0,pc,pcd,marginr-ii))                     //~va5aI~
        {                                                          //~va5aI~
            	if (posp<0)                                        //~v7aqI~//~va20I~
            		posp=ii;    //punctuation pos                  //~v7aqR~//~va20I~
        }                                                          //~va5aI~
      }                                                            //~v7aqI~//~va20I~
    }//!PUNCT                                                      //~v7avI~//~va20I~
    	breaksw=0;                                                 //~v7aqI~//~va20I~
      pcd++;                                                       //~v77EI~//~va20I~
    }                                                              //~v53cI~//~va20I~
    if (!breaksw                                                   //~v7aqI~//~va20I~
    &&   posp>=0)                                                  //~v7aqI~//~va20I~
    	ii=posp;                                                   //~v7aqI~//~va20I~
    len=ii-pos1;                                                   //~v53cR~//~va20I~
  }                                                                //~v7aqI~//~va20I~
 }//swutf8file                                                     //~va20I~
 else//!swutf8file                                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
 if (swebcfile)                                                    //~va50I~
 {                                                                 //~va50I~
//*************************                                        //~va5aI~
//*****swebcfile***********                                       //~va20I~//~va50I~
//*************************                                        //~va5aI~
  if (Pdelm                                                        //~v7auI~//~va20I~//~va50I~
  &&  !*pcd0                       //not ucs but ascii             //~va20I~//~va50I~
//&&  Pdelm[1]==*pc0               //same as x of "(x" pattern parm//~v7auI~//~va20I~//~va50R~
//&&  Pdelm[1]==EBC_B2A(*pc0)               //same as x of "(x" pattern parm//~va50I~//~va79R~
//&&  Pdelm[1]==UCVEBCH_B2A(handle,*pc0)               //same as x of "(x" pattern parm//~va79I~//~va7kR~
  &&  Pdelm[1]==*pc0               //same as x of "(x" pattern parm;fcmd24 set translated//~va7kI~
  &&  Pdelm[0]==FGW_DELM_INCLUDE)  //include left boundary char    //~v7aqI~//~va20I~//~va50I~
  {                                                                //~v7aqI~//~va20I~//~va50I~
    pos1=pos;                                                      //~v7aqI~//~va20I~//~va50I~
  }                                                                //~v7aqI~//~va20I~//~va50I~
  else                                                             //~v7aqI~//~va20I~//~va50I~
  {                                                                //~v7aqI~//~va20I~//~va50I~
    if (Pdelm                                                      //~v7avI~//~va20I~//~va50I~
    &&  (Pdelm[0]==FGW_DELM_INCLUDEM || Pdelm[0]==FGW_DELM_EXCLUDEM)//~v7avI~//~va20I~//~va50I~
    )                                                              //~v7avI~//~va20I~//~va50I~
    {                                                              //~v7avI~//~va20I~//~va50I~
//  	mblen=(int)(Pdelm[1]);                                     //~v7avI~//~va20I~//~va50I~//~va7kR~
//      pcmb=Pdelm+4;                                              //~v7avI~//~va20I~//~va50I~//~va7kR~
//        xeutfgetddstr(0,pcmb,mblen,wkddstr,sizeof(wkddstr),&ddstrlen,wkdddbcs);//~va20R~//~va50R~
//      xeebc_m2bsrchstr(0,pcmb,0/*pdbcs*/,mblen,wkddstr,wkdddbcs,sizeof(wkddstr),&ddstrlen);//~va5aR~//~va79R~
//      xeebc_m2bsrchstr(0,handle,pcmb,0/*pdbcs*/,mblen,wkddstr,wkdddbcs,sizeof(wkddstr),&ddstrlen);//~va79I~//~va7kR~
//      pcmb=wkddstr;                                              //~va20I~//~va5aR~//~va7kR~
//      mblen=ddstrlen;                                            //~va20I~//~va5aR~//~va7kR~
        pcmb=Pdelm+4+FGW_DELM_MAXLEN*2+1; //left boundary ebc data //~va7kI~
        mblen=(int)*(pcmb-1);                                      //~va7kI~
        pcmbdbcs=pcmb+FGW_DELM_MAXLEN;                             //~va7kI~
    }                                                              //~v7avI~//~va20I~//~va50I~
    else                                                           //~v7avI~//~va20I~//~va50I~
    	mblen=0;                                                   //~v7avI~//~va20I~//~va50I~
  	posp=-1;	//not found id                                     //~v7aqI~//~va20I~//~va50I~
    pcd=pcd0-1;                                                    //~v77EI~//~va20I~//~va50I~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos-1,pc=pc0-1;ii>=marginl;ii--,pc--)                  //~v53cR~//~va20I~//~va50I~
    {                                                              //~v53cI~//~va20I~//~va50I~
    	breaksw=1;                                                 //~v7aqI~//~va20I~//~va50I~
        dbcsid=*pcd;                                               //~va20I~//~va50I~
//        if (dbcsid==UDBCSCHK_F2LERR)                               //~va20R~//~va50R~
//            break;                                                 //~va20I~//~va50R~
      if (!Pdelm                                                   //~v77EI~//~va20I~//~va50I~
      ||   Pdelm[0]==0)                                            //~v77EI~//~va20I~//~va50I~
      {                                                            //~v77EI~//~va20I~//~va50I~
//      if (*pc==' '||!*pc)                                        //~v53cI~//~va20I~//~va50R~
        if (UCVEBC_ISSPACE(*pc,dbcsid)||!*pc)                      //~va50I~
//        if (!UDBCSCHK_ISUCSDBCST(dbcsid))                        //~va20I~//~va50R~
            break;                                                 //~v53cI~//~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
      else                                                         //~v77EI~//~va20I~//~va50I~
      if (Pdelm[0]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~//~va20I~//~va50I~
      {                                                            //~v77EI~//~va20I~//~va50I~
//    	if (dbcspunc=utfddispunct(0,pc,pcd,pos-ii),dbcspunc)       //~va20R~//~va50R~
//    	if (dbcspunc=UCVEBC_uispunct(pc,pcd,pos-ii),dbcspunc)  //no DBCS punct(DBCS enclosed by SO/SI)//~va50R~//~va79R~
      	if (dbcspunc=UCVEBC_uispunct(handle,pc,pcd,pos-ii),dbcspunc)  //no DBCS punct(DBCS enclosed by SO/SI)//~va79I~
        {                                                          //~va20I~//~va50I~
            if (dbcspunc==2)                                       //~va20I~//~va50R~
                ii++;   //back to after DBCS                       //~va20I~//~va50R~
            break;                                                 //~va20I~//~va50I~
        }                                                          //~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
      else                                                         //~v77EI~//~va20I~//~va50I~
    {                                                              //~v7avI~//~va20I~//~va50I~
    	if (mblen)	//multibyte                                    //~v7avI~//~va20I~//~va50I~
        {                                                          //~v7avI~//~va20I~//~va50I~
            if (ii>=mblen-1                                        //~v7avR~//~va20I~//~va50I~
//          &&  !xesubddmemcmp(XESUBDDSCO_EQCHKONLY,pcmb,wkdddbcs,pc-mblen+1,pcd-mblen+1,mblen))//~va20R~//~va50R~
//          &&  !xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,pc-mblen+1,pcd-mblen+1,pcmb,wkdddbcs,mblen))//~va5aR~//~va79R~
//          &&  !xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,handle,pc-mblen+1,pcd-mblen+1,pcmb,wkdddbcs,mblen))//~va79I~//~va7kR~
//          &&  !memcmp(pc-mblen+1,pcmb,mblen)                     //~va7kI~//+vb30R~
            &&  !memcmp(pc-mblen+1,pcmb,(size_t)mblen)             //+vb30I~
//          &&  !memcmp(pcd-mblen+1,pcmbdbcs,mblen))               //~va7kI~//+vb30R~
            &&  !memcmp(pcd-mblen+1,pcmbdbcs,(size_t)mblen))       //+vb30I~
            {                                                      //~v7avI~//~va20I~//~va50I~
				if (Pdelm[0]==FGW_DELM_INCLUDEM)	//include      //~v7avI~//~va20I~//~va50I~
                	ii-=mblen;                                     //~v7avI~//~va20I~//~va50I~
                break;                                             //~v7avI~//~va20I~//~va50I~
            }                                                      //~v7avI~//~va20I~//~va50I~
        }                                                          //~v7avI~//~va20I~//~va50I~
        else                                                       //~va20R~//~va50I~
//    if (Pdelm[1]==*pc && !*pcd)                                  //~va20I~//~va50R~
//    if (Pdelm[1]==EBC_B2A(*pc) && !dbcsid)                       //~va50I~//~va79R~
//    if (Pdelm[1]==UCVEBCH_B2A(handle,*pc) && !dbcsid)            //~va79I~//~va7kR~
      if (Pdelm[1]==*pc && !dbcsid)     //fcmd24 translated to ebc //~va7kI~
      {                                                            //~v77EI~//~va20I~//~va50I~
      	if (Pdelm[0]==FGW_DELM_INCLUDE)//include                   //~v77ER~//~va20I~//~va50I~
        	ii--;                                                  //~v77EI~//~va20I~//~va50I~
        break;                                                     //~v77EI~//~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
//    else      //delm specified but not match                     //~v7aqI~//~va20I~//~va50I~//~va5aR~
      {                                                            //~v7aqI~//~va20I~//~va50I~
//    	if (uispunct(0,*pc))  //space is not punct                 //~v7aqI~//~va20I~//~va50R~
//    	if (dbcspunc=UCVEBC_uispunct(pc,pcd,pos-ii),dbcspunc)  //no DBCS punct(DBCS enclosed by SO/SI)//~va5aI~//~va79R~
      	if (dbcspunc=UCVEBC_uispunct(handle,pc,pcd,pos-ii),dbcspunc)  //no DBCS punct(DBCS enclosed by SO/SI)//~va79I~
        {                                                          //~va5aI~
            if (posp<0)                                            //~va5aI~
            {                                                      //~va5aI~
                if (dbcspunc==2)                                   //~va5aI~
    	        	posp=ii+1;    //punctuation pos                //~va5aI~
                else                                               //~va5aI~
    	        	posp=ii;    //punctuation pos                  //~va5aI~
            }                                                      //~va5aI~
        }                                                          //~va5aI~
      }                                                            //~v7aqI~//~va20I~//~va50I~
    }//!PUNCT                                                      //~v7avI~//~va20I~//~va50I~
    	breaksw=0;                                                 //~v7aqI~//~va20I~//~va50I~
      pcd--;                                                       //~v77EI~//~va20I~//~va50I~
    }                                                              //~v53cI~//~va20I~//~va50I~
    if (!breaksw	                                               //~v7aqI~//~va20I~//~va50I~
    &&   posp>=0)                                                  //~v7aqI~//~va20I~//~va50I~
    	ii=posp;                                                   //~v7aqI~//~va20I~//~va50I~
    pos1=ii+1;                                                     //~v53cI~//~va20I~//~va50I~
  }                                                                //~v7aqI~//~va20I~//~va50I~
//ebc forward chk **************                                       //~va20I~//~va50I~
  if (Pdelm                                                        //~v7auI~//~va20I~//~va50I~
  &&  !*pcd0                      //not UCS                        //~va20I~//~va50I~
//&&  Pdelm[3]==*pc0             //match with "x)" pattern parm    //~v7auI~//~va20I~//~va50R~
//&&  Pdelm[3]==EBC_B2A(*pc0)             //match with "x)" pattern parm//~va50I~//~va79R~
//&&  Pdelm[3]==UCVEBCH_B2A(handle,*pc0)             //match with "x)" pattern parm//~va79I~//~va7kR~
  &&  Pdelm[3]==*pc0             //match with "x)" pattern parm;fc23 translated to ebc//~va7kI~
  &&  Pdelm[2]==FGW_DELM_INCLUDE)//include  right boundary         //~v7aqI~//~va20I~//~va50I~
  {                                                                //~v7aqI~//~va20I~//~va50I~
    len=pos+1-pos1;                                                //~v7aqI~//~va20I~//~va50I~
  }                                                                //~v7aqI~//~va20I~//~va50I~
  else                                                             //~v7aqI~//~va20I~//~va50I~
  {                                                                //~v7aqI~//~va20I~//~va50I~
    if (Pdelm                                                      //~v7avI~//~va20I~//~va50I~
    &&  (Pdelm[2]==FGW_DELM_INCLUDEM || Pdelm[2]==FGW_DELM_EXCLUDEM)//~v7avI~//~va20I~//~va50I~
    )                                                              //~v7avI~//~va20I~//~va50I~
    {                                                              //~v7avI~//~va20I~//~va50I~
//  	mblen=(int)(Pdelm[3]);                                     //~v7avI~//~va20I~//~va50I~//~va7kR~
//      pcmb=Pdelm+4+FGW_DELM_MAXLEN;                              //~v7avI~//~va20I~//~va50I~//~va7kR~
//        xeutfgetddstr(0,pcmb,mblen,wkddstr,sizeof(wkddstr),&ddstrlen,wkdddbcs);//~va20R~//~va50R~
//      xeebc_m2bsrchstr(0,pcmb,0/*pdbcs*/,mblen,wkddstr,wkdddbcs,sizeof(wkddstr),&ddstrlen);//~va5aR~//~va79R~
//      xeebc_m2bsrchstr(0,handle,pcmb,0/*pdbcs*/,mblen,wkddstr,wkdddbcs,sizeof(wkddstr),&ddstrlen);//~va79I~//~va7kR~
//      pcmb=wkddstr;                                              //~va20I~//~va5aR~//~va7kR~
//      mblen=ddstrlen;                                            //~va20I~//~va5aR~//~va7kR~
        pcmb=Pdelm+4+FGW_DELM_MAXLEN*2+1+FGW_DELM_MAXLEN*2+1; //left boundary ebc data//~va7kI~
        mblen=(int)*(pcmb-1);                                      //~va7kI~
        pcmbdbcs=pcmb+FGW_DELM_MAXLEN;                             //~va7kI~
    }                                                              //~v7avI~//~va20I~//~va50I~
    else                                                           //~v7avI~//~va20I~//~va50I~
    	mblen=0;                                                   //~v7avI~//~va20I~//~va50I~
  	posp=-1;	//not found id                                     //~v7aqI~//~va20I~//~va50I~
    pcd=pcd0+1;                                                    //~v77EI~//~va20I~//~va50I~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos+1,pc=pc0+1;ii<marginr;ii++,pc++)                   //~v53cR~//~va20I~//~va50I~
    {                                                              //~v53cI~//~va20I~//~va50I~
    	breaksw=1;                                                 //~v7aqI~//~va20I~//~va50I~
        dbcsid=*pcd;                                               //~va20I~//~va50I~
//        if (dbcsid==UDBCSCHK_F2LERR)                               //~va20R~//~va50R~
//            break;                                                 //~va20I~//~va50R~
      if (!Pdelm                                                   //~v77EI~//~va20I~//~va50I~
      ||   Pdelm[2]==0)                                            //~v77ER~//~va20I~//~va50I~
      {                                                            //~v77EI~//~va20I~//~va50I~
      	                                                           //~va20I~//~va50I~
//        if (*pc==' '||!*pc)                                        //~v53cI~//~va20I~//~va50R~
          if (UCVEBC_ISSPACE(*pc,dbcsid)||!*pc)                    //~va50I~
//          if (!UDBCSCHK_ISUCSDBCST(dbcsid))                        //~va20I~//~va50R~
            break;                                                 //~v53cI~//~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
      else                                                         //~v77EI~//~va20I~//~va50I~
      if (Pdelm[2]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~//~va20I~//~va50I~
      {                                                            //~v77EI~//~va20I~//~va50I~
//    	if (utfddispunct(0,pc,pcd,marginr-ii))                     //~va20I~//~va50R~
//    	if (UCVEBC_uispunct(pc,pcd,marginr-ii))  //no DBCS punct(DBCS enclosed by SO/SI)//~va50R~//~va79R~
      	if (UCVEBC_uispunct(handle,pc,pcd,marginr-ii))  //no DBCS punct(DBCS enclosed by SO/SI)//~va79I~
            break;                                                 //~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
      else                                                         //~v77EI~//~va20I~//~va50I~
    {                                                              //~v7avI~//~va20I~//~va50I~
    	if (mblen)	//multibyte                                    //~v7avI~//~va20I~//~va50I~
        {                                                          //~v7avI~//~va20I~//~va50I~
            if (marginr-ii>=mblen                                  //~v7avI~//~va20I~//~va50I~
//          &&  !xesubddmemcmp(XESUBDDSCO_EQCHKONLY,pcmb,wkdddbcs,pc,pcd,mblen))//~va20R~//~va50R~
//          &&  !xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,pc,pcd,pcmb,wkdddbcs,mblen))//~va5aR~//~va79R~
//          &&  !xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,handle,pc,pcd,pcmb,wkdddbcs,mblen))//~va79I~//~va7kR~
//          &&  !memcmp(pc,pcmb,mblen)                             //~va7kI~//+vb30R~
            &&  !memcmp(pc,pcmb,(size_t)mblen)                     //+vb30I~
//          &&  !memcmp(pcd,pcmbdbcs,mblen))                       //~va7kI~//+vb30R~
            &&  !memcmp(pcd,pcmbdbcs,(size_t)mblen))               //+vb30I~
            {                                                      //~v7avI~//~va20I~//~va50I~
				if (Pdelm[2]==FGW_DELM_INCLUDEM)	//include      //~v7avI~//~va20I~//~va50I~
                	ii+=mblen;                                     //~v7avI~//~va20I~//~va50I~
                break;                                             //~v7avI~//~va20I~//~va50I~
            }                                                      //~v7avI~//~va20I~//~va50I~
        }                                                          //~v7avI~//~va20I~//~va50I~
        else                                                       //~va20I~//~va50I~
//    if (Pdelm[3]==*pc && !*pcd)                                  //~va20I~//~va50R~
//    if (Pdelm[3]==EBC_B2A(*pc) && !dbcsid)                       //~va50I~//~va79R~
//    if (Pdelm[3]==UCVEBCH_B2A(handle,*pc) && !dbcsid)            //~va79I~//~va7kR~
      if (Pdelm[3]==*pc && !dbcsid)                                //~va7kI~
      {                                                            //~v77EI~//~va20I~//~va50I~
      	if (Pdelm[2]==FGW_DELM_INCLUDE)//include                   //~v77ER~//~va20I~//~va50I~
        	ii++;                                                  //~v77EI~//~va20I~//~va50I~
        break;                                                     //~v77EI~//~va20I~//~va50I~
      }                                                            //~v77EI~//~va20I~//~va50I~
//    else      //delm specified but not match                     //~v7aqI~//~va20I~//~va50I~//~va5aR~
      {                                                            //~v7aqI~//~va20I~//~va50I~
//    	if (uispunct(0,*pc))                                       //~v7aqI~//~va20I~//~va50R~
//    	if (UCVEBC_uispunct(pc,pcd,marginr-ii))  //no DBCS punct(DBCS enclosed by SO/SI)//~va5aI~//~va79R~
      	if (UCVEBC_uispunct(handle,pc,pcd,marginr-ii))  //no DBCS punct(DBCS enclosed by SO/SI)//~va79I~
        {                                                          //~va5aI~
//        	if(!*pcd)	//ascii                                    //~va20I~//~va50R~
            	if (posp<0)                                        //~v7aqI~//~va20I~//~va50I~
            		posp=ii;    //punctuation pos                  //~v7aqR~//~va20I~//~va50I~
        }                                                          //~va5aI~
      }                                                            //~v7aqI~//~va20I~//~va50I~
    }//!PUNCT                                                      //~v7avI~//~va20I~//~va50I~
    	breaksw=0;                                                 //~v7aqI~//~va20I~//~va50I~
      pcd++;                                                       //~v77EI~//~va20I~//~va50I~
    }                                                              //~v53cI~//~va20I~//~va50I~
    if (!breaksw                                                   //~v7aqI~//~va20I~//~va50I~
    &&   posp>=0)                                                  //~v7aqI~//~va20I~//~va50I~
    	ii=posp;                                                   //~v7aqI~//~va20I~//~va50I~
    len=ii-pos1;                                                   //~v53cR~//~va20I~//~va50I~
  }                                                                //~v7aqI~//~va20I~//~va50I~
 }                                                                 //~va50I~
 else//!ebc                                                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 {                                                                 //~va20I~
//*********not utf8/ebc file**************                             //~va20I~//~va50R~
//if (Pdelm[1]==*pc0               //same as x of "(x" pattern parm//~v7aqI~//~v7auR~
  if (Pdelm                                                        //~v7auI~
  &&  Pdelm[1]==*pc0               //same as x of "(x" pattern parm//~v7auI~
  &&  Pdelm[0]==FGW_DELM_INCLUDE)  //include left boundary char    //~v7aqI~
  {                                                                //~v7aqI~
    pos1=pos;                                                      //~v7aqI~
  }                                                                //~v7aqI~
  else                                                             //~v7aqI~
  {                                                                //~v7aqI~
    if (Pdelm                                                      //~v7avI~
    &&  (Pdelm[0]==FGW_DELM_INCLUDEM || Pdelm[0]==FGW_DELM_EXCLUDEM)//~v7avI~
    )                                                              //~v7avI~
    {                                                              //~v7avI~
    	mblen=(int)(Pdelm[1]);                                     //~v7avI~
        pcmb=Pdelm+4;                                              //~v7avI~
    }                                                              //~v7avI~
    else                                                           //~v7avI~
    	mblen=0;                                                   //~v7avI~
  	posp=-1;	//not found id                                     //~v7aqI~
    pcd=pcd0-1;                                                    //~v77EI~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos-1,pc=pc0-1;ii>=marginl;ii--,pc--)                  //~v53cR~
    {                                                              //~v53cI~
    	breaksw=1;                                                 //~v7aqI~
      if (!Pdelm                                                   //~v77EI~
      ||   Pdelm[0]==0)                                            //~v77EI~
      {                                                            //~v77EI~
        if (*pc==' '||!*pc)                                        //~v53cI~
            break;                                                 //~v53cI~
      }                                                            //~v77EI~
      else                                                         //~v77EI~
      if (Pdelm[0]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~
      {                                                            //~v77EI~
      	if (uispunct(0,*pc))  //space is not punct                 //~v77ER~
          if(*pcd!=DBCS2NDCHAR)	//0x5c may be dbcs 2nd char of Japanese//~v77ER~
            break;                                                 //~v77EI~
#ifdef UTF8SUPPH                                                   //~va1qI~
        if(*pcd==DBCS1STCHAR)                                      //~va0AR~
        	if (uispunctdbcs(0,pc))                                //~va0AI~
            {                                                      //~va25I~
                ii++;   //back to after DBCS                       //~va25I~
	            break;                                             //~va0AI~
            }                                                      //~va25I~
#endif                                                             //~va1qI~
      }                                                            //~v77EI~
      else                                                         //~v77EI~
    {                                                              //~v7avI~
    	if (mblen)	//multibyte                                    //~v7avI~
        {                                                          //~v7avI~
            if (ii>=mblen-1                                        //~v7avR~
            &&  !memcmp(pcmb,pc-mblen+1,(UINT)mblen))              //~v7avR~
            {                                                      //~v7avI~
				if (Pdelm[0]==FGW_DELM_INCLUDEM)	//include      //~v7avI~
                	ii-=mblen;                                     //~v7avI~
                break;                                             //~v7avI~
            }                                                      //~v7avI~
        }                                                          //~v7avI~
        else                                                       //~va24I~
      if (Pdelm[1]==*pc)                                           //~v77EI~
      {                                                            //~v77EI~
      	if (Pdelm[0]==FGW_DELM_INCLUDE)//include                   //~v77ER~
        	ii--;                                                  //~v77EI~
        break;                                                     //~v77EI~
      }                                                            //~v77EI~
//    else      //delm specified but not match                     //~v7aqI~//~va5aR~
      {                                                            //~v7aqI~
      	if (uispunct(0,*pc))  //space is not punct                 //~v7aqI~
          	if(*pcd!=DBCS2NDCHAR)	//0x5c may be dbcs 2nd char of Japanese//~v7aqR~
            	if (posp<0)                                        //~v7aqI~
    	        	posp=ii;    //punctuation pos                  //~v7aqR~
#ifdef UTF8SUPPH                                                   //~va5aI~
        if(*pcd==DBCS1STCHAR)                                      //~va5aI~
        	if (uispunctdbcs(0,pc))                                //~va5aI~
            {                                                      //~va5aI~
            	if (posp<0)                                        //~va5aI~
    	        	posp=ii+1;    //punctuation pos                //~va5aI~
            }                                                      //~va5aI~
#endif                                                             //~va5aI~
      }                                                            //~v7aqI~
    }//!PUNCT                                                      //~v7avI~
    	breaksw=0;                                                 //~v7aqI~
      pcd--;                                                       //~v77EI~
    }                                                              //~v53cI~
    if (!breaksw	                                               //~v7aqI~
    &&   posp>=0)                                                  //~v7aqI~
    	ii=posp;                                                   //~v7aqI~
    pos1=ii+1;                                                     //~v53cI~
  }                                                                //~v7aqI~
//**forward**                                                      //~va25I~
//if (Pdelm[3]==*pc0             //match with "x)" pattern parm    //~v7aqI~//~v7auR~
  if (Pdelm                                                        //~v7auI~
  &&  Pdelm[3]==*pc0             //match with "x)" pattern parm    //~v7auI~
  &&  Pdelm[2]==FGW_DELM_INCLUDE)//include  right boundary         //~v7aqI~
  {                                                                //~v7aqI~
    len=pos+1-pos1;                                                //~v7aqI~
  }                                                                //~v7aqI~
  else                                                             //~v7aqI~
  {                                                                //~v7aqI~
    if (Pdelm                                                      //~v7avI~
    &&  (Pdelm[2]==FGW_DELM_INCLUDEM || Pdelm[2]==FGW_DELM_EXCLUDEM)//~v7avI~
    )                                                              //~v7avI~
    {                                                              //~v7avI~
    	mblen=(int)(Pdelm[3]);                                     //~v7avI~
        pcmb=Pdelm+4+FGW_DELM_MAXLEN;                              //~v7avI~
    }                                                              //~v7avI~
    else                                                           //~v7avI~
    	mblen=0;                                                   //~v7avI~
  	posp=-1;	//not found id                                     //~v7aqI~
    pcd=pcd0+1;                                                    //~v77EI~
    breaksw=0;                                                     //~vafdI~
    for (ii=pos+1,pc=pc0+1;ii<marginr;ii++,pc++)                   //~v53cR~
    {                                                              //~v53cI~
    	breaksw=1;                                                 //~v7aqI~
      if (!Pdelm                                                   //~v77EI~
      ||   Pdelm[2]==0)                                            //~v77ER~
      {                                                            //~v77EI~
        if (*pc==' '||!*pc)                                        //~v53cI~
            break;                                                 //~v53cI~
      }                                                            //~v77EI~
      else                                                         //~v77EI~
      if (Pdelm[2]==FGW_DELM_PUNCT)//alphanumeric                  //~v77ER~
      {                                                            //~v77EI~
      	if (uispunct(0,*pc))                                       //~v77ER~//~v7aqR~
          if(*pcd!=DBCS2NDCHAR)                                    //~v77ER~
	            break;                                             //~v77ER~
#ifdef UTF8SUPPH                                                   //~va1qI~
        if(ii+1<marginr && *(pcd)==DBCS1STCHAR)                    //~va0AI~
        	if (uispunctdbcs(0,pc))                                //~va0AI~
	            break;                                             //~va0AI~
#endif                                                             //~va1qI~
      }                                                            //~v77EI~
      else                                                         //~v77EI~
    {                                                              //~v7avI~
    	if (mblen)	//multibyte                                    //~v7avI~
        {                                                          //~v7avI~
            if (marginr-ii>=mblen                                  //~v7avI~
            &&  !memcmp(pcmb,pc,(UINT)mblen))                      //~v7avI~
            {                                                      //~v7avI~
				if (Pdelm[2]==FGW_DELM_INCLUDEM)	//include      //~v7avI~
                	ii+=mblen;                                     //~v7avI~
                break;                                             //~v7avI~
            }                                                      //~v7avI~
        }                                                          //~v7avI~
        else                                                       //~va24I~
      if (Pdelm[3]==*pc)                                           //~v77EI~
      {                                                            //~v77EI~
      	if (Pdelm[2]==FGW_DELM_INCLUDE)//include                   //~v77ER~
        	ii++;                                                  //~v77EI~
        break;                                                     //~v77EI~
      }                                                            //~v77EI~
//    else      //delm specified but not match                     //~v7aqI~//~va5aR~
      {                                                            //~v7aqI~
      	if (uispunct(0,*pc))                                       //~v7aqI~
          	if(*pcd!=DBCS2NDCHAR)                                  //~v7aqR~
            	if (posp<0)                                        //~v7aqI~
            		posp=ii;    //punctuation pos                  //~v7aqR~
#ifdef UTF8SUPPH                                                   //~va5aI~
        if(ii+1<marginr && *(pcd)==DBCS1STCHAR)                    //~va5aI~
        	if (uispunctdbcs(0,pc))                                //~va5aI~
            {                                                      //~va5aI~
            	if (posp<0)                                        //~va5aI~
            		posp=ii;    //punctuation pos                  //~va5aI~
            }                                                      //~va5aI~
#endif                                                             //~va5aI~
      }                                                            //~v7aqI~
    }//!PUNCT                                                      //~v7avI~
    	breaksw=0;                                                 //~v7aqI~
      pcd++;                                                       //~v77EI~
    }                                                              //~v53cI~
    if (!breaksw                                                   //~v7aqI~
    &&   posp>=0)                                                  //~v7aqI~
    	ii=posp;                                                   //~v7aqI~
    len=ii-pos1;                                                   //~v53cR~
  }                                                                //~v7aqI~
 }//not utf8file                                                   //~va20I~
    *Ppplh=plh;                                                    //~v53cI~
    *Ppos=pos1;                                                    //~v53cR~
    return len;                                                    //~v53cI~
}//filegetword                                                     //~v53cI~
//**************************************************************** //~v59vI~
// filegetcsrdpos                                                  //~v59vI~
//*get offset in data area for hex area offset for drwa csr pos    //~v59vI~
//*opt:0:cur csr pos                                               //~v59vI~
//*dpos :output data part offset,-1:csr in data part,-2:intermediate or out of range//~v59vI~
//**************************************************************** //~v59vI~
int filegethexcsrdpos(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Ppdpos)//~v59vR~
{                                                                  //~v59vI~
	PUSCRD psd;                                                    //~v59vI~
	PUFILEC pfc;                                                   //~v59vI~
    PULINEH plh;                                                   //~v59vI~
    int hpos,hpose,cpos,oddsw;                                     //~v59vR~
//**********                                                       //~v59vI~
	*Ppdpos=-2;		//-2:no update csr pos info                    //~v59vI~
	if (!CSRONFILEDATA(Ppcw))                                      //~v59vR~
    	return -2;                                                 //~v59vI~
	pfc=Ppcw->UCWpfc;                                              //~v59vI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v59vI~
	plh=psd->USDbuffc;                                             //~v59vI~
	if (plh->ULHtype!=ULHTDATA)	//file data                        //~v59vM~
    	return -2;                                                 //~v59vM~
	filegethposrange(Ppfh,plh->ULHlen,&hpos,&hpose);//get hex area range//~v59vR~
	cpos=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;            //~v59vI~
    if (cpos<hpos)                                                 //~v59vI~
    {                                                              //~v59vI~
    	*Ppdpos=-1;		//in data part                             //~v59vI~
    	return -1;                                                 //~v59vI~
    }                                                              //~v59vI~
    if (cpos>hpose)		//outof range                              //~v59vI~
    	return -2;                                                 //~v59vI~
    oddsw=filegetdatapos(hpos,hpose,cpos,Ppdpos,1);//left most data pos//~v59vI~
    if (oddsw<0)	//intermediate space                           //~v59vI~
    	return -2;                                                 //~v59vI~
    return 0;                                                      //~v59vI~
}//filegethexcsrdpos                                               //~v59vI~
//**************************************************************** //~v61wI~
// filevhexprint                                                   //~v61wI~
//*for xpr ** cmd;write vhex line                                  //~v61wI~
//*parm2:plh after tab disply expand                               //~v61wI~
//*rc   :none                                                      //~v61wI~
//**************************************************************** //~v61wI~
//int filevhexprint(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Plinenowk,int Plinenosz)//~v61wI~//~va81R~
int filevhexprint(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Plinenowk,int Plinenosz)//~va81I~
{                                                                  //~v61wI~
	int  rc,len,wlen;                                              //~v61wR~
    UCHAR *pc,*pc0;                                                //~v61wI~
#ifdef UTF8UCS2                                                    //~va20I~
    int vhlen;	//hex line len                                     //~va20I~
#endif                                                             //~va20I~
//*************************                                        //~v61wI~
    pc=pc0=Gfilebuff;                                              //~v61wI~
    if (Plinenosz)                                                 //~v61wI~
    {                                                              //~v61wI~
    	memset(pc,' ',(UINT)(Plinenosz-1));                        //~v61wI~
        *(pc+Plinenosz-1)=*(Plinenowk+Plinenosz-1);                //~v61wR~
        pc+=Plinenosz;                                             //~v61wI~
    }                                                              //~v61wI~
    len=Pplh->ULHlen;                                              //~v61wI~
    wlen=len+Plinenosz;                                            //~v61wI~
#ifdef UTF8UCS2                                                    //~va20I~
	vhlen=MAXLINEDATA;	//sizeof Gfilebuff                         //~va20I~
	filevhexdisplay(USDF2VHEXLINE1,Pplh->ULHdata,Pplh->ULHdbcs,pc,0,len,&vhlen);//~va20I~
    wlen=vhlen+Plinenosz;	//hex line len                         //~va20I~
	if (Popt & FVHPO_WXPEBC)                                       //~va81I~
    {                                                              //~va81I~
    	if (!UCBITCHK(Goptopt,GOPT_HEX_UPPER))                     //~vajaR~
    		fileupper(pc0,wlen);                                   //~vajaR~
    	ucvebc_a2bfld(0,Ppfh->UFHhandle,pc0,pc0,wlen);             //~va81R~
//  	if (Plinenosz)                                             //~va81I~//~vajfR~
//      	*(pc0+Plinenosz-1)=*(Plinenowk+Plinenosz-1); //already m2b done//~va81I~//~vajfR~
    }                                                              //~va81I~
#else	                                                           //~va20I~
	filevhexdisplay(USDF2VHEXLINE1,Pplh->ULHdata,Pplh->ULHdbcs,pc,0,len);//~v61wI~
#endif                                                             //~va20I~
    if (rc=filewrite(Ppfh,pc0,(size_t)wlen),rc)                    //~v61wR~
        return rc;                                                 //~v61wI~
  if (Popt & FVHPO_WXPEBC)                                         //~va81I~
  {                                                                //~va81I~
    if (rc=filewrite(Ppfh,EBC_NL_STR,1),rc)                        //~va81I~
        return rc;                                                 //~va81I~
  }                                                                //~va81I~
  else                                                             //~va81I~
  {                                                                //~va81I~
    if (rc=filewrite(Ppfh,"\n",1),rc)                              //~v61wI~
        return rc;                                                 //~v61wI~
  }                                                                //~va81I~
#ifdef UTF8UCS2                                                    //~va20I~
	vhlen=MAXLINEDATA;	//sizeof Gfilebuff                         //~va20I~
	filevhexdisplay(USDF2VHEXLINE2,Pplh->ULHdata,Pplh->ULHdbcs,pc,0,len,&vhlen);//~va20I~
    wlen=vhlen+Plinenosz;	//hex line len                         //~va20I~
	if (Popt & FVHPO_WXPEBC)                                       //~va81I~
    {                                                              //~va81I~
    	if (!UCBITCHK(Goptopt,GOPT_HEX_UPPER))                     //~vajaI~
    		fileupper(pc0,wlen);                                   //~vajaI~
//  	ucvebc_a2bfld(0,Ppfh->UFHhandle,pc,pc,vhlen);              //~va81R~//~vajaR~
    	ucvebc_a2bfld(0,Ppfh->UFHhandle,pc,pc,wlen);               //~vajaI~
    }                                                              //~va81I~
#else                                                              //~va20I~
	filevhexdisplay(USDF2VHEXLINE2,Pplh->ULHdata,Pplh->ULHdbcs,pc,0,len);//~v61wI~
#endif                                                             //~va20I~
    if (rc=filewrite(Ppfh,pc0,(size_t)wlen),rc)                    //~v61wR~
        return rc;                                                 //~v61wI~
  if (Popt & FVHPO_WXPEBC)                                         //~va81I~
  {                                                                //~va81I~
    if (rc=filewrite(Ppfh,EBC_NL_STR,1),rc)                        //~va81I~
        return rc;                                                 //~va81I~
  }                                                                //~va81I~
  else                                                             //~va81I~
  {                                                                //~va81I~
    if (rc=filewrite(Ppfh,"\n",1),rc)                              //~v61wI~
        return rc;                                                 //~v61wI~
  }                                                                //~va81I~
    return Shpose;		//print lenght                             //~v61wI~
}//filevhexprint                                                   //~v61wI~
//**************************************************************** //~v60vI~
// filevhexdisplay                                                 //~v60vI~
//*set hex data for virtical hex display mode                      //~v60vI~
//*rc   :1:reached to output boundary                              //~va20R~
//**************************************************************** //~v60vI~
#ifdef UTF8UCS2                                                    //~va20I~
int filevhexdisplay(int Popt,UCHAR *Pplhdata,UCHAR *Pplhdbcs,UCHAR *Ppsddata,UCHAR *Ppsddbcs,int Plen,int *Ppbuffsz)//~va20I~
#else                                                              //~va20I~
UCHAR *filevhexdisplay(int Popt,UCHAR *Pplhdata,UCHAR *Pplhdbcs,UCHAR *Ppsddata,UCHAR *Ppsddbcs,int Plen)//~v60vR~
#endif                                                             //~va20I~
{                                                                  //~v60vI~
	UCHAR *pci,*pcd,*pco,*pce;                                     //~v60vI~
	UCHAR *pcdo;                                                   //~v65bI~
    int ch,vhex1sw,uppersw;                                        //~v60vR~
#ifdef UTF8UCS2                                                    //~va20I~
    ULONG ucs;                                                     //~va20I~
	UCHAR *pcoe;                                                   //~va20R~
    int chlow,buffsz,rc=0,outlen;                                  //~va20R~
//  #ifdef UTF8UCS4                                                //~va3xI~//~vaw1R~
	#ifdef UTF8UCS416                                              //~vaw1R~
	    int chmid4=-1,chlow4=-1;                                   //~va3xI~
    #endif                                                         //~va3xI~
#endif                                                             //~va20I~
//*****************                                                //~v60vI~
	vhex1sw=Popt & USDF2VHEXLINE1;	//1st line of virtical hex display line//~v60vR~
	uppersw=UCBITCHK(Goptopt,GOPT_HEX_UPPER);	//upper case hex digit//~v60vI~
    pci=Pplhdata;                                                  //~v60vI~
	pcd=Pplhdbcs;                                                  //~v60vI~
	pco=Ppsddata;                                                  //~v60vI~
	pcdo=Ppsddbcs;                                                 //~v65bI~
#ifdef UTF8UCS2                                                    //~va20I~
    buffsz=*Ppbuffsz;	//input:buffsz                             //~va20R~
    pcoe=pco+buffsz;                                               //~va20R~
    chlow=-1;                                                      //~va20R~
#endif                                                             //~va20I~
    if (UDBCSCHK_ISUCSOVF2ND(*pcd)) //f8(UDBCSCHK_UCS42) include 80(UDBCSCHK_SBCSUCSID),so chk before UDBCSCHK_ISUCSSBCS//~vb22I~
    {                                                              //~vb22I~
    //*print 2nd/3rd byte on vhex line                             //~vb22I~
//      ucs=UTF_GETUCSDBCSOVF(pci-1,pcd-1);                        //~vb22I~//+vb30R~
        ucs=(ULONG)UTF_GETUCSDBCSOVF(pci-1,pcd-1);                 //+vb30I~
//      ch=(UCHAR)((ucs&0xff0000)>>16);   //high value by bigendian//~vb22I~
        chmid4=(int)((ucs & 0xff00)>>8);    //middle by bigendian  //~vb22R~
        chlow4=(int)(ucs & 0xff);    //low by bigendian            //~vb22I~
    }                                                              //~vb22I~
//  for (pce=pci+Plen;pci<pce;pci++,pcd++,pco++)                   //~v65bR~
    for (pce=pci+Plen;pci<pce;pci++,pcd++,pco++,pcdo++)            //~v65bI~
    {                                                              //~v60vI~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (pco>=pcoe)                                             //~va20I~
        {                                                          //~va20I~
        	rc=1;                                                  //~va20I~
        	break;                                                 //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    	if (*pcd==TABPADCHAR)                                      //~v60vI~
        {                                                          //~v65bI~
        	*pco=' ';                                              //~v60vI~
            if (Ppsddbcs)                                          //~v65bI~
    	    	*pcdo=TABPADCHAR;                                  //~v65bI~
        }                                                          //~v65bI~
        else                                                       //~v60vI~
        {                                                          //~v60vI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va5aI~
            if (*pcd==TABCHAR)                                     //~v60vI~
            {                                                      //~v65bI~
                ch=TABCHAR;                                        //~v65bR~
                if (Ppsddbcs)                                      //~v65bI~
                	*pcdo=TABCHAR;                                 //~v65bI~
            }                                                      //~v65bI~
#ifdef UTF8UCS2                                                    //~va20I~
//  #ifdef UTF8UCS4                                                //~va3xI~//~vaw1R~
	#ifdef UTF8UCS416       //FIXME test surrogate:FIXED           //~vaw1R~
            else                                                   //~va3xI~
            if (UDBCSCHK_ISUCSOVF1ST(*pcd)) //dd fmt 1 byte ucs    //~va3xI~
            {                                                      //~va3xI~
            	if (pci+1<pce)                                     //~va3xI~
                {                                                  //~va3xI~
//                  ucs=UTF_GETUCSDBCSOVF(pci,pcd);                //~va3xR~//+vb30R~
                    ucs=(ULONG)UTF_GETUCSDBCSOVF(pci,pcd);         //+vb30I~
                    ch=(UCHAR)((ucs&0xff0000)>>16);   //high value by bigendian//~va3xI~
                    chmid4=(int)((ucs & 0xff00)>>8);    //low by bigendian//~va3xI~
                    chlow4=(int)(ucs & 0xff);    //low by bigendian//~va3xI~
            	}                                                  //~va3xI~
                else        //not the case                         //~va3xI~
                	ch=*pci;                                       //~va3xI~
                if (Ppsddbcs)                                      //~va3xI~
    	            *pcdo=0;                                       //~va3xI~
            }                                                      //~va3xI~
            else                                                   //~va3xI~
            if (chmid4>=0)                                         //~va3xI~
            {                                                      //~va3xI~
                ch=chmid4;                                         //~va3xR~
                chmid4=-1;                                         //~va3xR~
                if (Ppsddbcs)                                      //~va3xI~
                    *pcdo=0;                                       //~va3xI~
                pci--;		//dbcs column=2                        //~va3xI~
                pcd--;                                             //~va3xI~
            }                                                      //~va3xI~
            else                                                   //~va3xI~
            if (chlow4>=0)                                         //~va3xI~
            {                                                      //~va3xI~
                ch=chlow4;                                         //~va3xR~
                chlow4=-1;                                         //~va3xR~
                if (Ppsddbcs)                                      //~va3xI~
                    *pcdo=0;                                       //~va3xI~
            }                                                      //~va3xI~
    #endif                                                         //~va3xI~
			else                                                   //~va20I~
            if (chlow>=0)                                          //~va20I~
            {                                                      //~va20I~
                ch=chlow;                                          //~va20I~
                chlow=-1;                                          //~va20I~
                if (Ppsddbcs)                                      //~va20I~
                    *pcdo=0;                                       //~va20I~
            }                                                      //~va20I~
            else                                                   //~va20I~
            if (UDBCSCHK_ISUCSSBCS(*pcd)) //dd fmt 1 byte ucs      //~va20I~
            {                                                      //~va20I~
	        	ucs=UTF_GETUCSSBCS(pci,pcd);                       //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1R~
//*all sbcs is ucs2 for windows,but for unity                      //~vaw1R~
              if (ch=(UCHAR)((ucs&0xff0000)>>16),ch)   //high value by bigendian//~va3xR~
              {                                                    //~va3xI~
              	chmid4=(int)((ucs & 0xff00)>>8);    //low by bigendian//~va3xI~
                chlow4=(int)(ucs & 0xff);    //low by bigendian    //~va3xI~
              }                                                    //~va3xI~
              else                                                 //~va3xI~
#endif                                                             //~va3xI~
              {                                                    //~va3xI~
                ch=(UCHAR)((ucs&0xff00)>>8);   //high value by bigendian//~va20R~
                chlow=(int)(ucs & 0xff);	//low by bigendian     //~va20R~
              }                                                    //~va3xI~
                if (Ppsddbcs)                                      //~va20I~
    	            *pcdo=0;                                       //~va20R~
                pci--;     //exec twice                            //~va20I~
                pcd--;                                             //~va20I~
            }                                                      //~va20I~
#endif                                                             //~va20I~
            else                                                   //~v60vI~
            {                                                      //~v65bI~
	        	ch=*pci;                                           //~v60vI~
                if (Ppsddbcs)                                      //~v65bI~
    	            *pcdo=0;                                       //~v65bI~
            }                                                      //~v65bI~
        	if (vhex1sw)                                           //~v60vI~
            	ch=(int)((UINT)ch>>4);  	//1st 4 bit            //~v60vR~
            else                                                   //~v60vI~
            	ch=(int)(ch & 0x0f);    //2nd 4 bit                //~v60vR~
            if (ch>=10)                                            //~v60vI~
            {                                                      //~v60vI~
            	ch-=10;                                            //~v60vI~
			    if (uppersw)                                       //~v60vI~
	            	ch+='A';                                       //~v60vI~
                else                                               //~v60vI~
	            	ch+='a';                                       //~v60vI~
            }                                                      //~v60vI~
            else                                                   //~v60vI~
            	ch+='0';                                           //~v60vI~
            *pco=(UCHAR)ch;                                        //~v60vI~
        }                                                          //~v60vI~
    }//                                                            //~v60vI~
//  if (Ppsddbcs) //optional                                       //~v65bR~
//    memset(Ppsddbcs,0,(UINT)Plen);                               //~v65bR~
#ifdef UTF8UCS2                                                    //~va20I~
//	outlen=(int)((ULONG)pco-(ULONG)Ppsddata);	//return expand len//~va20I~//~vafkR~
	outlen=(int)((ULPTR)pco-(ULPTR)Ppsddata);	//return expand len//~vafkI~
    UTRACED("filevhexdisplay outdata",Ppsddata,outlen);            //~va20R~
	*Ppbuffsz=outlen;	//return expand len                        //~va20R~
    return rc;                                                     //~va20I~
#else                                                              //~va20I~
    return 0;                                                      //~v60vI~
#endif                                                             //~va20I~
}//filevhexdisplay                                                 //~v60vI~
//**************************************************************** //~v60vI~
// filecharhexinput_v                                              //~v60vI~
//*accept input on virtical hexline                                //~v60vR~
//       4:err                                                     //~v60vR~
//**************************************************************** //~v60vI~
//int filecharhexinput_v(UCHAR *Pkeyindata,int Pkeyindatalen,int Poldvalue,int Pmode,int Pvhexmode,UCHAR *Ppnewchar)//~va3TR~
int filecharhexinput_v(PUCLIENTWE Ppcw,UCHAR *Pkeyindata,int Pkeyindatalen,int Poldvalue,int Pmode,int Pvhexmode,UCHAR *Ppnewchar)//~va3TI~
{                                                                  //~v60vI~
    int   oldch,chi,cho;                                           //~v60vR~
//*****************                                                //~v60vI~
	if (Pkeyindatalen!=1)                                          //~v60vI~
    	return errnotvalidhexchar();                               //~v60vI~
    if (Poldvalue<0)	//over EOL                                 //~v60vR~
    	return errcsrpos();                                        //~v60vI~
    else                                                           //~v60vI~
    	oldch=Poldvalue;                                           //~v60vI~
    chi=toupper(*Pkeyindata);                                      //~v60vR~
    if (chi>='0' && chi<='9')                                      //~v60vI~
		chi=chi-'0';                                               //~v60vI~
	else                                                           //~v60vI~
	if (chi>='A' && chi<='F')                                      //~v60vI~
		chi=chi-'A'+10;                                            //~v60vI~
    else                                                           //~v60vI~
    {                                                              //~va37I~
        if (chi==CHAR_MAKEUCS)                                     //~va37I~
        {                                                          //~va37I~
        	uerrmsg("\"%c\" key(MakeUcs) is for UTF8 file only",0, //~va37I~
				CHAR_MAKEUCS);                                     //~va37R~
        	return 4;                                              //~va37R~
        }                                                          //~va37I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
        if (chi==CHAR_MAKEUCS4)                                    //~va3xI~
        {                                                          //~va3xI~
        	uerrmsg("\"%c\" key(MakeUcs4) is for UTF8 file only",0,//~va3xI~
				CHAR_MAKEUCS4);                                    //~va3xI~
        	return 4;                                              //~va3xI~
        }                                                          //~va3xI~
#endif                                                             //~va3xI~
    	return errnotvalidhexchar();                               //~v60vI~
    }                                                              //~va37I~
    if (Pmode==CHAROPREP)                                          //~v60vI~
    {                                                              //~v60vI~
        if (Pvhexmode & USDF2VHEXLINE1)  //input on 1st line       //~v60vR~
        {                                                          //~va3TI~
            cho=(oldch & 0x0f)|(chi<<4);                           //~v60vR~
	        Ppcw->UCWreason=UCWREASON_VHEX1STEP;	//for csr zigzag movement//~va3TI~
        }                                                          //~va3TI~
        else                                                       //~v60vI~
        {                                                          //~va3TI~
            cho=(oldch & 0xf0)|chi;                                //~v60vR~
	        Ppcw->UCWreason=UCWREASON_VHEX2STEP;	//for csr zigzag movement//~va3TI~
        }                                                          //~va3TI~
    }                                                              //~v60vI~
    else                                                           //~v60vI~
    if (Pmode==CHAROPINS)                                          //~v60vI~
    {                                                              //~v60vI~
//      uerrmsg("Insert avail on char display line",               //~v735R~
//      		"ï∂éö\x95\\é¶çsÇ≈ë}ì¸ÇµÇƒÇ≠ÇæÇ≥Ç¢");               //~v735R~
//      return 4;                                                  //~v735R~
        if (Pvhexmode & USDF2VHEXLINE1)  //input on 1st line       //~v735I~
        {                                                          //~va3TI~
            cho=(chi<<4);                                          //~v735I~
	        Ppcw->UCWreason=UCWREASON_VHEX1STEP;	//for csr zigzag movement//~va3TI~
        }                                                          //~va3TI~
        else                                                       //~v735I~
        {                                                          //~va3TI~
            cho=chi;                                               //~v735I~
	        Ppcw->UCWreason=UCWREASON_VHEX2STEP;	//for csr zigzag movement//~va3TI~
        }                                                          //~va3TI~
    }                                                              //~v60vI~
    else                                                           //~v60vI~
    	return 8;                                                  //~v60vI~
    *Ppnewchar=(UCHAR)cho;                                         //~v60vR~
    return 0;                                                      //~v60vR~
}//filecharhexinput_v                                              //~v60vR~
