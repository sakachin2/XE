//*CID://+v6uBR~:                             update#=   53;       //+v6uBR~
//*********************************************************************
//* utf.c                                                          //~7712I~
//* utf8 data manipulation:macro process                           //~7712R~
//*********************************************************************
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //+v6uBI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6ueI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v620:090506 merge UTF8 version                                   //~v620I~
//            for CJK and LANG=..UTF8, wctomb/mbtowc-->iconv/WinAPI//~v620I~
//v61i:071226 (UTF:BUG)shiftR missig memmove if tgt has no chof    //~v61iI~
//v61e:071221 (UTF:BUG)clear after shft to left by the reason of replace UTF8 char by ascii//~v61eI~
//v61c:071215 (UTF:BUG)UTCstrncpy BYOFFS case;offs and lenc mixed  //~v61dI~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v60m:071019 (UTF:LNX)default width table for ja_JP.eucJP         //~v60mI~
//v60f:071018 (UTF:LNX)chk by g_locale_from_utf8 when forced UTF8(-y8 under no utf8 env)//~v60fI~
//            to avoid screen corrupt at console mode              //~v60fI~
//v60a:070928 (UTF:WXE)                                            //~7930I~
//v600:070710 (UTF8)new typdef
//*********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
//*******************************************************
#include <ulib.h>
#include <ualloc.h>                                                //~7824I~
#include <uque.h>
#include <ucvucs.h>
#include <udbcschk.h>                                              //~7713I~
#include <utrace.h>
#include <uerr.h>
#include <ustring.h>                                               //~7728I~
#define GLOBAL_UTF        //define extern                          //~7712I~
#include <utf.h>
#include <utf2.h>
//*******************************************************
int UTCprepupdate(int Popt,PUTCHARS Ptgt,int Ppos,UCHAR *Psrcdata,UINT Psrclenc,UINT Psrclenutf);//~7824R~
//*******************************************************          //~7713I~
//*init utf env                                                    //~7713I~
//*******************************************************          //~7713I~
int  utf_init(int Popt)                                            //~7713I~
{                                                                  //~7713I~
//*********************************                                //~7713I~
//#ifdef UTF8UCS4                                                    //~v65cI~//+v6uBR~
#ifdef UTF8UCS416                                                  //+v6uBI~
    Gulibutfmode|=GULIBUTFUCS4;                                    //~v65cI~
#endif                                                             //~v65cI~
//#ifdef W32UNICODE                                                  //~v6ueI~//+v6uBR~
//    Gulibutfmode|=GULIBUTF_WINSURROGATE;    //always support surrogate pair//~v6ueI~//+v6uBR~
//#endif                                                             //~v6ueI~//+v6uBR~
#ifdef UTF8SUPPH                                                   //~v620M~
    if (Gudbcschk_flag & UDBCSCHK_UTF8)                            //~v620M~
    	Gulibutfmode|=GULIBUTFENV;		//LANG:UTF8                //~v620M~
#else                                                              //~v620M~
	if (Popt&UTFIO_RESET)                                          //~7713I~
    	Gulibutfmode=0;                                            //~7713I~
    else                                                           //~7713I~
    {                                                              //~7713I~
        udbcschkcp();   //dbcs flag set after chk console mode     //~7713R~
        if (Gudbcschk_flag & UDBCSCHK_UTF8)                        //~7713R~
            Gulibutfmode|=GULIBUTFENV;                             //~7713R~
        else                                                       //~7713I~
            Gulibutfmode=0;                                        //~7713I~
    }                                                              //~7713I~
	if (Popt&UTFIO_FORCE)                                          //~7A17M~
    {                                                              //~v60mI~
    	Gulibutfmode|=GULIBUTFFORCE;                               //~7A17M~
        if (Gudbcschk_flag & UDBCSCHK_EUC)  //original is EUC      //~v60mI~
    		Gulibutfmode|=GULIBUTFFROMEUC;  //chk charwidth table for EUC//~v60mI~
    }                                                              //~v60mI~
#ifdef LNX                                                         //~7A18I~
  #ifdef XXE                                                       //~7A18I~
  #else 		//console version only                             //~7A18I~
    if (!(Gulibutfmode & GULIBUTFENV)                              //~7A18I~
    &&   (Gulibutfmode & GULIBUTFFORCE))	//force to utf8 under no utf env//~v60fR~
    	Gulibutfmode|=GULIBUTFCHKBYCVL; //isprint by conversion chk to locale//~7A18I~
  #endif                                                           //~7A18I~
#endif                                                             //~7A18I~
#endif //UTF8SUPPH                                                 //~v620I~
    return UTF8MODE();                                             //~7713I~
}//utf_init                                                        //~7713I~
#ifdef UTF8SUPP                                                    //~v620I~
//*******************************************************
//*setup UTCHARS by data only
//*******************************************************
PUTCHARS UTCsetDs(int Popt,PUTCHARS Pptgt,UCHAR *Pdata,PCHOFTYPE Ppchof,int Pwidth) 	//tgt={src,0}//~7728R~
{
	int lenutf;                                                    //~v60rI~
//*********************************
    memset(Pptgt,0,sizeof(UTCHARS));                               //~7728I~
	Pptgt->data=Pdata;                                             //~7717R~
    Pptgt->chof=Ppchof;                                            //~7724I~
	Pptgt->lenc=Pwidth;                                            //~7717I~
    if (Popt & UTCO_CHOFGEN)	//setup req                        //~v60rI~
    {                                                              //~v60rI~
		Pptgt->lenc=0;		//to set new lenc                      //~v60rI~
        if (!(lenutf=Pwidth))                                      //~v60rI~
        	lenutf=(int)strlen(Pdata);                             //~v60rI~
		if (utfsetchofD(Popt|UTCO_BYLEN,      //parm len should be utflen//~v60rR~
						Pptgt,		//data and chof and lenc       //~v60rI~
						0,           //start column                //~v60rI~
						UTCDATA(Pptgt),   //data source            //~v60rI~
						0,           //optional data source start column//~v60rI~
						lenutf,        //lenutf or lenc            //~v60rR~
						0,               //setup column            //~v60rI~
                        0,	//outlenc                              //~v60rI~
						0))      //chked data lenutf               //~v60rR~
            Gutfrc=UTCRC_OUTR;                                     //~v60rI~
    }                                                              //~v60rI~
    return Pptgt;                                                  //~7716R~
}//UTCsetD
//*******************************************************          //~7914I~
//*setup UTCHARS by copy with position                             //~7914I~
//*******************************************************          //~7914I~
PUTCHARS UTCsetLs(int Popt,PUTCHARS Pptgt,PUTCHARS Ppsrc,int Ppos,int Plenc) 	//tgt=src,data+=pos//~7914I~
{                                                                  //~7914I~
	PUTCHARS putc;                                                 //~7914R~
//*********************************                                //~7914I~
	putc=UTCsets(Popt,Pptgt,Ppsrc,Ppos);                           //~7914R~
	UTCLENC(putc)=Plenc;                                           //~7914I~
    return putc;                                                   //~7914I~
}//UTCsetLs                                                        //~7914I~
//*******************************************************
//*setup UTCHARS by copy with position                             //~7712R~
//*******************************************************
PUTCHARS UTCsets(int Popt,PUTCHARS Pptgt,PUTCHARS Ppsrc,int Ppos) 	//tgt=src,data+=pos//~7716R~
{
	int offs,pos;                                                  //~7728R~
//*********************************
	memcpy(Pptgt,Ppsrc,UTCHARSSZ);	//copy                         //~7815R~
    if (!UTF8MODE())                                               //~7712I~
    {                                                              //~7806I~
        UTCDATA(Pptgt)+=Ppos;                                      //~7806R~
    	return Pptgt;                                              //~7716R~
    }                                                              //~7806I~
    if (Ppos)
    {
        if (!utfgetposoffs(Popt,Pptgt,Ppos,&pos,&offs))            //~7729R~
        {                                                          //~7728I~
            Pptgt->data+=offs;                                     //~7728R~
            Pptgt->cpos+=Ppos;                                     //~7728I~
        }                                                          //~7728I~
    }
    return Pptgt;                                                  //~7716R~
}//UTCsets                                                         //~7914R~
//*******************************************************          //~7712I~
//*setup UTCHARS by copy with position                             //~7712I~
//*******************************************************          //~7712I~
UCHAR *UTCincdec(int Popt,PUTCHARS Pputc,int Plen)                 //~7712I~
{                                                                  //~7712I~
	int offs,pos,rc;                                               //~7728R~
    UCHAR *retpc;                                                  //~7712I~
//*********************************                                //~7712I~
	retpc=Pputc->data;	//old addr                                 //~7713R~
    if (!UTF8MODE() ||!UTC_ISNORMALCHOF(Pputc))                    //~7729R~
    {                                                              //~7712I~
		Pputc->data+=Plen;	//old addr                             //~7713R~
	    if (!(Popt & UTCO_AFT))                                    //~7712I~
      		retpc=Pputc->data;                                     //~7713R~
        return retpc;                                              //~7712I~
    }                                                              //~7712I~
    if (Plen>0)	//inc                                              //~7728R~
    {                                                              //~7712R~
        if (rc=utfgetposoffs(Popt,Pputc,Plen,&pos,&offs),rc)       //~7729R~
            return retpc;                                          //~7728R~
        Pputc->data+=offs;                                         //~7713R~
        Pputc->cpos+=pos;;                                         //~7728I~
    }                                                              //~7712R~
    else                                                           //~7712R~
    if (Plen<0)	//inc                                              //~7728I~
    {                                                              //~7712R~
        utfbackoffset(Popt,Pputc,-Plen);                           //~7818R~
    }                                                              //~7712R~
    if (!(Popt & UTCO_AFT))                                        //~7712R~
        retpc=Pputc->data;                                         //~7713R~
    return retpc;                                                  //~7712I~
}//UTCincdec                                                       //~7712I~
//*******************************************************          //~7830I~
//*char set     *pc=ch                                             //~7830I~
//*******************************************************          //~7830I~
UCHAR *UTCeqincdecs(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,int Pcnt)//~7830R~
{                                                                  //~7830I~
//*********************************                                //~7830I~
	UTCeqs(Popt,Pputct,Ppost,Pputcs,Pposs);                        //~7830I~
    UTCincdec(Popt,Pputcs,Pcnt);                                   //~7830R~
    return UTCincdec(Popt,Pputct,Pcnt);                            //~7830R~
}//UTCeqincdecs                                                    //~7830I~
//*******************************************************
//*char set     *pct=*pcs                                          //~7724R~
//*******************************************************
int UTCeqs(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs)//~7729R~
{
//*********************************
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputct))                    //~7729R~
    {                                                              //~7712I~
		*(UTCDATA(Pputct)+Ppost)=*(UTCDATA(Pputcs)+Pposs);         //~7806R~
        return 0;                                                  //~7724R~
    }                                                              //~7712I~
	UTCmemcpys(Popt,Pputct,Ppost,Pputcs,Pposs,1);                  //~7724I~
    return 0;                                                      //~7724R~
}//UTCeqs
//*******************************************************          //~7726I~
//*get 1 utf char str                                              //~7726I~
//*return str utfen                                                //~7726I~
//*******************************************************          //~7726I~
int UTCeqDPs(int Popt,UCHAR *Pstr,PUTCHARS Pputc,int Ppos)         //~7726I~
{                                                                  //~7726I~
	int len,offs;                                                  //~7726I~
//*********************************                                //~7726I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputc))                     //~7729I~
    {                                                              //~7726I~
		*Pstr=*(UTCDATA(Pputc)+Ppos);                              //~7806R~
        return 1;                                                  //~7726I~
    }                                                              //~7726I~
	if (utfgetposoffscntlen(Popt,Pputc,Ppos,1,0,&offs,0,&len))     //~7729R~
    	return 0;                                                  //~7726I~
	memcpy(Pstr,UTCDATA(Pputc)+offs,(UINT)len);                    //~7726I~
    return len;                                                    //~7726I~
}//UTCeqDPs                                                        //~7726I~
//*******************************************************          //~7726I~
//*get 1 utf char str                                              //~7726I~
//*return str utfen                                                //~7726I~
//*******************************************************          //~7726I~
int UTCeqPDs(int Popt,PUTCHARS Pputc,int Ppos,UCHAR *Pstr)         //~7726I~
{                                                                  //~7726I~
    UTCHARS utch;                                                  //~7726I~
//*********************************                                //~7726I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputc))                     //~7729R~
    {                                                              //~7726I~
		*(UTCDATA(Pputc)+Ppos)=*Pstr;                              //~7806R~
        return 1;                                                  //~7726I~
    }                                                              //~7726I~
    UTCINITD(utch,Pstr);                                           //~7729R~
    UTCeqP0(Pputc,Ppos,&utch);                                     //~7726I~
    return 0;                                                      //~7726I~
}//UTCeqDPs                                                        //~7726I~
//*******************************************************          //~7724I~
//*char set     *pc=ch                                             //~7724I~
//*******************************************************          //~7724I~
int UTCeqcs(int Popt,PUTCHARS Pputc,int Ppos,int Pch)              //~7724I~
{                                                                  //~7724I~
    UTCHARS utch;                                                  //~7729I~
    CHOFTYPE  chof[2];                                             //~7824R~
//*********************************                                //~7724I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputc))                     //~7729R~
    {                                                              //~7724I~
		*(UTCDATA(Pputc)+Ppos)=Pch;                                //~7806R~
        return Pch;                                                //~7729R~
    }                                                              //~7724I~
    chof[0]=0,chof[1]=1;                                           //~7824R~
    UTCINITDCL(utch,(UCHAR*)(&Pch),chof,1);                        //~7824R~
    UTCmemcpys(Popt,Pputc,Ppos,&utch,0/*poss*/,1/*len*/);          //~7729R~
    return Pch;                                                    //~7729R~
}//UTCeqs                                                          //~7724I~
//*******************************************************          //~7725I~
//*char set     *pc=ch                                             //~7725I~
//*******************************************************          //~7725I~
UCHAR *UTCeqcincdecs(int Popt,PUTCHARS Pputc,int Ppos,int Pch,int Pcnt)//~7830R~
{                                                                  //~7725I~
//*********************************                                //~7725I~
	UTCeqcs(Popt,Pputc,Ppos,Pch);                                  //~7725R~
    return UTCincdec(Popt,Pputc,Pcnt);                             //~7830R~
}//UTCeqcas                                                        //~7725I~
//*******************************************************          //~7712I~
//*char comp    *pc==ch                                            //~7829R~
//*******************************************************          //~7712I~
int UTCeqeqcs(int Popt,PUTCHARS Pputc,int Ppos,int Pch)            //~7725R~
{                                                                  //~7712I~
    int rc,offs,pos;                                               //~7712I~
//*********************************                                //~7712I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputc))                     //~7729R~
    {                                                              //~7712I~
		return *(UTCDATA(Pputc)+Ppos)==Pch;                        //~7713R~
    }                                                              //~7712I~
	if (rc=utfgetposoffs(Popt,Pputc,Ppos,&pos,&offs),rc)           //~7729R~
    	return rc;                                                 //~7712I~
    return (*(Pputc->data+offs)==Pch);                             //~7713R~
}//UTCeqeqcs                                                       //~7829R~
//*******************************************************          //~7829I~
//*utf char comp    *pc1==*pc2                                     //~7829I~
//*ret 1:mach,0:unmatch                                            //~7829I~
//*******************************************************          //~7829I~
int UTCeqeqs(int Popt,PUTCHARS Ptgt,int Ptpos,PUTCHARS Psrc,int Pspos)//~7829I~
{                                                                  //~7829I~
    int ii,len1,len2;                                              //~7829R~
    UCHAR *pc1,*pc2;                                               //~7829I~
//*********************************                                //~7829I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Ptgt))                      //~7829I~
    {                                                              //~7829I~
    	pc1=UTCDATA(Ptgt)+Ptpos;                                   //~7829I~
        len1=1;                                                    //~7829I~
    }                                                              //~7829I~
    else                                                           //~7829I~
    {                                                              //~7829I~
    	pc1=UTC_POS2ADDR(Popt,Ptgt,Ptpos);                         //~7829I~
        len1=(int)((ULONG)UTC_POS2ADDR(Popt,Ptgt,Ptpos+1)-(ULONG)pc1);//~7829R~
    }                                                              //~7829I~
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Psrc))                      //~7829I~
    {                                                              //~7829I~
    	pc2=UTCDATA(Psrc)+Pspos;                                   //~7829I~
        len2=1;                                                    //~7829I~
    }                                                              //~7829I~
    else                                                           //~7829I~
    {                                                              //~7829I~
    	pc2=UTC_POS2ADDR(Popt,Psrc,Pspos);                         //~7829I~
        len2=(int)((ULONG)UTC_POS2ADDR(Popt,Psrc,Pspos+1)-(ULONG)pc2);//~7829R~
    }                                                              //~7829I~
    if (len1!=len2)                                                //~7829I~
    	return 0;                                                  //~7829I~
    for (ii=len1;ii>0;pc1++,pc2++,ii--)                            //~7829R~
    {                                                              //~7829I~
    	if (*pc1!=*pc2)                                            //~7829R~
        	return 0;                                              //~7829R~
    }                                                              //~7829I~
    return 1;                                                      //~7829R~
}//UTCeqeqs                                                        //~7829I~
//*******************************************************
//*memset
//*******************************************************
int UTCmemsets(int Popt,PUTCHARS Pputc,int Ppos,int Pch,UINT Plen) //~7712R~
{
    int offs,rc,initoffs,pos;                                      //~7830R~
    PCHOFTYPE pchof;                                               //~7801I~
//*********************************
    if (!UTF8MODE()||!UTC_ISNORMALCHOF(Pputc))                     //~7729R~
    {                                                              //~7712I~
		memset (UTCDATA(Pputc)+Ppos,Pch,Plen);                     //~7713R~
        return 0;                                                  //~7712I~
    }                                                              //~7712I~
	if ((rc=utfgetposoffs(Popt,Pputc,Ppos,&pos,&offs)))  //offset prom current data//~7918R~
    	return rc;                                                 //~7712I~
	UTCprepupdate(Popt,Pputc,pos," "/*dummy srcdata*/,Plen,Plen/*srclenutf*/);  //shift for shrink data//~7830R~
	memset(Pputc->data+offs,Pch,(UINT)Plen);                       //~7729R~
    pchof=Pputc->chof+Pputc->cpos;                                 //~7801I~
    if (Pputc->cpos+pos)	//tgt pos!=0                           //~7903I~
	    initoffs=*pchof;                                           //~7903R~
    else                                                           //~7903I~
    	initoffs=0;                                                //~7903R~
    pchof+=pos;                                                    //~7830R~
    initoffs+=offs;                                                //~7801I~
    UTC_CHOFSET(pchof,(int)Plen+1,initoffs)                        //~7801I~
    if (Popt & UTCO_EOL	//not cut remaining data                   //~7826I~
    ||  Pputc->lenc<(int)(Pputc->cpos+pos+Plen))                   //~7830R~
		Pputc->lenc=(int)(Pputc->cpos+pos+Plen);                   //~7830R~
    return rc;                                                     //~7712R~
}//UTCmemsets
//*******************************************************
//*memcpy
//*******************************************************
char *UTCmemcpys(int Popt,PUTCHARS Ptgt,int Ppost,PUTCHARS Psrc,int Pposs,UINT Plen)//~7728R~
{
    int srcoffs,srclenutf,tgtoffs,diff,opt=0,poss;                 //~7930R~
    int srcopt,srclenc;                                            //~v60rR~
#ifdef AAA                                                         //~7825I~
    int dbcssplitsw=0;                                             //~7825I~
#endif                                                             //~7825I~
    UCHAR *srcdata,*tgtdata;                                       //~7824R~
//  PCHOFTYPE srcchof,tgtchof,allocchof=0,oldchof;                 //~7824R~//~v6h7R~
    PCHOFTYPE srcchof,tgtchof,allocchof=0,oldchof=0;               //~v6h7I~
#define TEMPCHOFSZ     512                                         //~7824R~
    CHOFTYPE tempchof[TEMPCHOFSZ+1];                               //~7824R~
//*********************************
	if (Popt & UTCO_SHIFTL)                                        //~7830R~
    {                                                              //~7930I~
        poss=UTCCPOS(Psrc)+Pposs-UTCCPOS(Ptgt);		//pos by tgt base//~7930R~
		return UTCmemshifts(Popt,Ptgt,Ppost,poss,Plen);            //~7930I~
    }                                                              //~7930I~
	Gutfrc=0;                                                      //~7728I~
UTRACEP("UTCmemcpys opt=%x, TGT=%p,post=%d,chof=%p,lenc=%d,cpos=%d\n",Popt,Ptgt,Ppost,Ptgt->chof,Ptgt->lenc,Ptgt->cpos);//~v60rR~
UTRACEP("UTCmemcpys len=%d, SRC=%p,post=%d,chof=%p,lenc=%d,cpos=%d\n",Plen,Psrc,Pposs,Psrc->chof,Psrc->lenc,Psrc->cpos);//~v60rR~
	srcopt=Popt & (UTCO_EOLSTOP|UTCO_MAXWIDTH);	//effective only source data//~v60rR~
    Popt &=~srcopt;                                                //~v60rR~
	tgtdata=UTCDATA(Ptgt)+Ppost;                                   //~7728I~
	srcdata=UTCDATA(Psrc)+Pposs;                                   //~7728I~
    for(;;)                                                        //~7728I~
    {                                                              //~7728I~
    	if (!UTF8MODE())                                           //~7728I~
        {                                                          //~7728I~
			memcpy(tgtdata,srcdata,Plen);                          //~7728I~
            break;                                                 //~7728I~
        }                                                          //~7728I~
		if (utfgetposoffs(Popt,Ptgt,Ppost,0,&tgtoffs))  //offset from current data//~7806R~
        {                                                          //~7728I~
            Gutfrc=UTCRC_OUTR;                                     //~7728R~
    		break;                                                 //~7728I~
        }                                                          //~7728I~
        tgtdata=Ptgt->data+tgtoffs;                                //~7728I~
//  	if (!UTC_ISNORMALCHOF(Psrc))                               //~v60rR~
    	if (!UTC_ISVALIDCHOF(Psrc) //chof=0                        //~v60rR~
        &&   UTC_ISNORMALCHOF(Ptgt)	//target expect ascii(not utf8 mode)//~v60rR~
        &&   Popt & UTCO_CHOFGEN)                                  //~v60rR~
        {                                                          //~v60rI~
        	oldchof=UTCCHOF(Psrc);                                 //~7824R~
			opt=Popt & UTCO_BYLEN;	                               //~7830R~
        	if (Plen<=TEMPCHOFSZ)                                  //~7824I~
            {                                                      //~7824I~
				if (UTC_ISASCII(Psrc))                             //~7827I~
					opt|=UTCO_ASCII;                               //~7827I~
            	UTCCHOF(Psrc)=tempchof;                            //~7827M~
            }                                                      //~7824I~
        	else                                                   //~7824I~
				opt|=UTCO_ALLOCCHOF;                               //~7830R~
			if (utfsetchofD(opt,                                   //~7824R~
								Psrc,		//data and chof and lenc//~7824R~
								0,           //start column        //~7824R~
								UTCDATA(Psrc),   //data source     //~7729I~
								Pposs,           //optional data source start column//~7729I~
								Plen,            //lenutf or lenc  //~7729I~
								0,               //setup column    //~7729I~
                                &srcoffs,        //                //~7729I~
								&srclenutf))      //chked data lenutf//~7729R~
            {                                                      //~7729I~
	            Gutfrc=UTCRC_OUTR;                                 //~7729I~
            	break;                                             //~7729R~
            }                                                      //~7729I~
        }                                                          //~7728I~
        else                                                       //~7729I~
       {                                                           //~v60rI~
        if (utfgetposoffscntlen(srcopt,Psrc,Pposs,Plen,0,&srcoffs,&srclenc,&srclenutf))//~v60rR~
        {                                                          //~7728I~
            Gutfrc=UTCRC_OUTR;                                     //~7728R~
            break;                                                 //~7728I~
        }                                                          //~7728I~
        if (srcopt & UTCO_EOLSTOP)	//effective only source data   //~v60rI~
        {                                                          //~v60rI~
	        if (srcopt & UTCO_MAXWIDTH)	//effective only source data//~v60rI~
            	Plen=min((int)Plen,srclenc);                       //~v60rR~
            else                                                   //~v60rI~
	        	Plen=srclenc;                                      //~v60rR~
        }                                                          //~v60rI~
       }                                                           //~v60rI~
        srcdata=Psrc->data+srcoffs;                                //~7823M~
        if (!(Popt & UTCO_EOL))	//not cut remaining data           //~7821I~
        {                                                          //~7824I~
#ifdef AAA                                                         //~7830I~
            if (Ptgt->lenc>(int)(Ptgt->cpos+Ppost+Plen))           //~7824I~
            {                                                      //~7824I~
            	Gutfrc=0;                                          //~7824I~
            	UTC_POS2ADDR(0,Ptgt,Ppost+Plen);                   //~7824I~
            	dbcssplitsw=(Gutfrc==UTCRC_DBCSSPLIT);  //shift override dbcs 1st at end pos//~7824R~
            }                                                      //~7824I~
#endif                                                             //~7830M~
			diff=UTCprepupdate(Popt,Ptgt,Ppost,srcdata,Plen,srclenutf);//shift remaining part//~7824R~
            if (diff)	//tgt src overwrap                         //~7824I~
            {                                                      //~7831I~
            	srcdata+=diff;	//source shifted by overwrap       //~7824R~
                if (!srcoffs)         //if that is current top     //~7914R~
	                UTCDATA(Psrc)+=diff;    //reflection to caller //~7914R~
            }                                                      //~7831I~
        }                                                          //~7824I~
        memcpy(tgtdata,srcdata,(UINT)srclenutf);                   //~7728I~
#ifdef AAA                                                         //~7825I~
        if (dbcssplitsw)                                           //~7824I~
            if (!(Popt & UTCO_HEX))                                //~7825R~
	        	*(tgtdata+srclenutf)=' ';                          //~7825R~
#endif                                                             //~7825I~
    	if (UTC_ISNORMALCHOF(Ptgt))	//tgt has chof                 //~7729R~
        {                                                          //~7728I~
            tgtchof=Ptgt->chof+Ptgt->cpos+Ppost;                   //~7731I~
    	  if (!UTC_ISNORMALCHOF(Psrc)) //src chof=-1               //~v60rR~
          {                                                        //~v60rI~
            diff=tgtoffs;                                          //~v60rI~
            if (Ptgt->cpos && Ptgt->lenc>=Ptgt->cpos)              //~v60rI~
                diff+=*(Ptgt->chof+Ptgt->cpos);                    //~v60rI~
            if (Popt & UTCO_EOL     //cut remaining data           //~v60rI~
            ||  Ptgt->lenc<=(int)(Ptgt->cpos+Ppost+Plen))          //~v60rI~
            {                                                      //~v60rI~
                Ptgt->lenc=(int)(Ptgt->cpos+Ppost+Plen);           //~v60rI~
    	        UTC_CHOFSET(tgtchof,(int)Plen+1,diff)              //~v60rR~
            }                                                      //~v60rI~
            else                                                   //~v60rI~
            {                                                      //~v60rI~
    	        UTC_CHOFSET(tgtchof,(int)Plen,diff)                //~v60rR~
            }                                                      //~v60rI~
          }                                                        //~v60rI~
          else                                                     //~v60rI~
          {                                                        //~v60rI~
            srcchof=Psrc->chof+Psrc->cpos+Pposs;                   //~7824R~
            diff=-*srcchof+tgtoffs;                                //~7825R~
            if (Ptgt->cpos && Ptgt->lenc>=Ptgt->cpos)              //~7825R~
                diff+=*(Ptgt->chof+Ptgt->cpos);                    //~7825R~
            if (Popt & UTCO_EOL     //cut remaining data           //~7824R~
            ||  Ptgt->lenc<=(int)(Ptgt->cpos+Ppost+Plen))          //~7824R~
            {                                                      //~7824I~
                Ptgt->lenc=(int)(Ptgt->cpos+Ppost+Plen);           //~7824R~
    	        UTC_CHOFCPY(tgtchof,srcchof,Plen+1,diff)           //~7824I~
            }                                                      //~7824I~
            else                                                   //~7824I~
            {                                                      //~7824I~
    	        UTC_CHOFCPY(tgtchof,srcchof,Plen,diff)             //~7824I~
            }                                                      //~7824I~
          }//normal src chof                                       //~v60rI~
		}                                                          //~7728I~
        break;                                                     //~7728I~
    }                                                              //~7728I~
UTRACEP("UTCmemcpys rc=%d,ret=%p tgt lenc=%d,cpos=%d\n",Gutfrc,tgtdata,Ptgt->lenc,Ptgt->cpos);//~7728R~
    allocchof=UTCCHOF(Psrc);                                       //~7824I~
    if (allocchof==tempchof)                                       //~7824I~
    	UTCCHOF(Psrc)=oldchof;                                     //~7824I~
    else                                                           //~7824I~
		if (opt & UTCO_ALLOCCHOF)                                  //~7824I~
        {                                                          //~7824I~
        	if (allocchof)                                         //~7824I~
		    	ufree(allocchof);                                  //~7824R~
	    	UTCCHOF(Psrc)=oldchof;                                 //~7824I~
        }                                                          //~7824I~
    return tgtdata;                                                //~7728R~
}//UTCmemcpys
//*******************************************************          //~7729I~
//*prepare update                                                  //~7729I~
//* shift before data override                                     //~7729I~
//* rc:src data shift count if overwrapped                         //~7824I~
//*******************************************************          //~7729I~
int UTCprepupdate(int Popt,PUTCHARS Ptgt,int Ppos,UCHAR *Psrcdata,UINT Psrclenc,UINT Psrclenutf)//~7824R~
{                                                                  //~7729I~
    int cpos,tpos,endpos,lenutfr,lenc,endoffs,tgtoffs,diff,lencr,tgtlenutf,rc;//~7824R~
    int srcstartpos;                                               //~7824R~
    UCHAR *pdata0,*pshift,*pdataeol,*pdatat;                       //~7824R~
    PCHOFTYPE pchof,pchof0;                                        //~7729R~
//*********************************                                //~7729I~
UTRACEP("UTCprepupdate opt=%x, TGT=%p,chof=%p,lenc=%d,cpos=%d lenc=%d,lenutf=%d\n",Popt,Ptgt,Ptgt->chof,Ptgt->lenc,Ptgt->cpos,Ppos,Psrclenc,Psrclenutf);//~v61iR~
   	if (!UTC_ISNORMALCHOF(Ptgt))	//tgt has chof                 //~7729I~
    	return 0;                                                  //~7729I~
    cpos=Ptgt->cpos;                                               //~7729I~
    tpos=cpos+Ppos;                                                //~7729I~
    endpos=tpos+Psrclenc;                                          //~7729R~
    lenc=Ptgt->lenc;                                               //~7729I~
    lencr=lenc-endpos;                                             //~7729I~
    if (tpos<0 || lencr<=0)                                        //~7729I~
    	return 0;                                                  //~7729I~
    pchof0=Ptgt->chof;                                             //~7729R~
    tgtoffs=*(pchof0+tpos);                                        //~7729R~
    endoffs=*(pchof0+endpos);                                      //~7729R~
    lenutfr=*(pchof0+lenc)-endoffs;                                //~7729R~
    tgtlenutf=endoffs-tgtoffs;                                     //~7729I~
    diff=Psrclenutf-tgtlenutf;                                     //~7729R~
    pdata0=Ptgt->data-*(pchof0+cpos);                              //~7729R~
    pshift=pdata0+endoffs;	//shift start addr                     //~7824I~
#ifndef GGG                                                        //~7824I~
    pdataeol=pdata0+*(pchof0+lenc);	//end of line addr             //~7824I~
    pdatat=pdata0+tgtoffs;			//target start addr            //~7824R~
    rc=0;	                                                       //~7824I~
    if (Psrcdata>=pdatat && Psrcdata<pdataeol)	//src is shift     //~7824R~
    {                                                              //~7824I~
	    rc=diff;	//notify adjust src addr                       //~7824I~
    	if (Psrcdata<pshift)	//src and target overwrap          //~7824I~
    	{                                                          //~7824I~
            srcstartpos=UTC_OFFS2POS(0,Ptgt,(int)((ULONG)Psrcdata-(ULONG)UTCDATA(Ptgt)),0)+cpos;//src start pos in tgt data//~7831R~
    		lenutfr+=(int)((ULONG)pshift-(ULONG)Psrcdata);  //shift from src top//~7824I~
            lencr+=endpos-srcstartpos;                             //~7824R~
            endpos=srcstartpos;                                    //~7824I~
    		pshift=Psrcdata;                                       //~7824I~
    	}                                                          //~7824I~
    }                                                              //~7824I~
#endif                                                             //~7824I~
    if (diff>0)                                                    //~7729I~
    	memmove(pshift+diff,pshift,(UINT)lenutfr);                 //~7824R~
    else                                                           //~7729I~
    if (diff<0)                                                    //~7729I~
    {                                                              //~v61eI~
    	memcpy(pshift+diff,pshift,(UINT)lenutfr);                  //~7824R~
    	memset(pshift+diff+lenutfr,0,-diff);	//clear right end after shift to left//~v61eI~
    }                                                              //~v61eI~
    if (diff)                                                      //~7729I~
    {                                                              //~7729I~
    	pchof=pchof0+endpos;                                       //~7729R~
    	UTC_CHOFADJUST(pchof,lencr+1,diff)                         //~7729I~
    }                                                              //~7729I~
UTRACEP("UTCprepupdate diff=%d,lencr=%d\n",diff,lencr);            //~7729I~
    return rc;                                                     //~7824R~
}//UTCprepupdate                                                   //~7729I~
//*******************************************************          //~7823M~
//*shift left                                                      //~7823M~
//*(R-shift override prev data)                                    //~v61eI~
//*******************************************************          //~7823M~
char *UTCmemshifts(int Popt,PUTCHARS Ptgt,int Ppost,int Pposs,UINT Plen)//~7830R~
{                                                                  //~7823M~
    int srcoffs,srclenutf,tgtoffs,diff,lenr,lenrutf,offsr,offsclear,offstgt,tgtendpos;//~7830R~
    int distcnt,lenrc,tgtendoffs;                                  //~7830R~
    UCHAR *srcdata,*tgtdata;                                       //~7823M~
    PCHOFTYPE srcchof,tgtchof;                                     //~7823M~
//*********************************                                //~7823M~
	Gutfrc=0;                                                      //~7823M~
UTRACEP("UTCmemshift opt=%x, TGT=&p,post=%d,chof=%p,lenc=%d,cpos=%d\n",Popt,Ptgt,Ppost,Ptgt->chof,Ptgt->lenc,Ptgt->cpos);//~7823M~
UTRACEP("UTCmemshift len=%d, poss=%d\n",Plen,Pposs);               //~7823M~
	tgtdata=UTCDATA(Ptgt)+Ppost;    //addr for not utf8 mode       //~7829R~
	srcdata=UTCDATA(Ptgt)+Pposs;                                   //~7823M~
    for(;;)                                                        //~7823M~
    {                                                              //~7823M~
        distcnt=Ppost-Pposs;            //                         //~7831I~
        if (!distcnt)                                              //~7831I~
        	break;                                                 //~7831I~
        if (Popt & UTCO_SHIFTL)                                    //~7830I~
        {                                                          //~7830I~
            if (distcnt>0)                                         //~7831R~
                break;                                             //~7831I~
            if (!UTF8MODE())                                       //~7830R~
            {                                                      //~7830R~
                memcpy(tgtdata,srcdata,Plen);                      //~7830R~
                break;                                             //~7830R~
            }                                                      //~7830R~
            if (utfgetposoffs(Popt,Ptgt,Ppost,0,&tgtoffs))  //offset from current data//~7830R~
            {                                                      //~7830R~
                Gutfrc=UTCRC_OUTR;                                 //~7830R~
                break;                                             //~7830R~
            }                                                      //~7830R~
            tgtdata=Ptgt->data+tgtoffs;                            //~7830R~
            if (utfgetposoffscntlen(0,Ptgt,Pposs,Plen,0,&srcoffs,0,&srclenutf))//~7830R~
            {                                                      //~7830R~
                Gutfrc=UTCRC_OUTR;                                 //~7830R~
                break;                                             //~7830R~
            }                                                      //~7830R~
            srcdata=Ptgt->data+srcoffs;                            //~7830R~
            memcpy(tgtdata,srcdata,(UINT)srclenutf);               //~7830R~
            if (UTC_ISNORMALCHOF(Ptgt)) //tgt has chof             //~7830R~
            {                                                      //~7830R~
                lenr=Ptgt->lenc-(Ptgt->cpos+Pposs+Plen);    //into area//~7830R~
                lenrutf=UTC_WIDTH2SPAN(0,Ptgt,Pposs+Plen,Ptgt->lenc-Ptgt->cpos);//~7830R~
                tgtchof=Ptgt->chof+Ptgt->cpos+Ppost;               //~7830R~
                srcchof=Ptgt->chof+Ptgt->cpos+Pposs;               //~7830R~
                diff=-*srcchof+*tgtchof;                           //~7830R~
                UTC_CHOFCPY(tgtchof,srcchof,Plen+1,diff)           //~7830R~
                if (Popt & UTCO_EOL)    //cut remaining data       //~7830R~
                    Ptgt->lenc=(int)(Ptgt->cpos+Ppost+Plen);       //~7830R~
                else                                               //~7830R~
                {                                                  //~7830R~
                    distcnt=Pposs-Ppost;                           //~7830R~
                    memset(tgtdata+srclenutf,' ',(UINT)distcnt);   //~7830R~
                    tgtchof--;  //next of last UTC_CHOFCPY         //~7830R~
                    diff=*tgtchof;                                 //~7830R~
                    UTC_CHOFSET(tgtchof,distcnt,diff);             //~7830R~
                    diff=distcnt-(srcoffs-tgtoffs);                //~7830R~
                    if (diff<0) //residual to be shift             //~7830R~
                    {                                              //~7830R~
                        if (lenr>0)                                //~7830R~
                        {                                          //~7830R~
                            memcpy(srcdata+srclenutf+diff,srcdata+srclenutf,lenrutf);//~7830R~
                            UTC_CHOFADJUST(tgtchof,lenr+1,diff);   //~7830R~
                        }                                          //~7830R~
                    }                                              //~7830R~
                }//!EOL                                            //~7830R~
            }                                                      //~7830R~
        }//shiftL                                                  //~7830I~
        else    //shiftR                                           //~7830I~
        {                                                          //~7830I~
            if (distcnt<0)                                         //~7831I~
                break;                                             //~7831R~
            if (!UTF8MODE())                                       //~7830I~
            {                                                      //~7830I~
                memmove(tgtdata,srcdata,Plen);                     //~7830I~
                break;                                             //~7830I~
            }                                                      //~7830I~
            if (utfgetposoffs(Popt,Ptgt,Ppost,0,&tgtoffs))  //offset from current data//~7830I~
            {                                                      //~7830I~
                Gutfrc=UTCRC_OUTR;                                 //~7830I~
                break;                                             //~7830I~
            }                                                      //~7830I~
            tgtdata=Ptgt->data+tgtoffs;                            //~7830I~
            if (utfgetposoffscntlen(0,Ptgt,Pposs,Plen,0,&srcoffs,0,&srclenutf))//~7830I~
            {                                                      //~7830I~
                Gutfrc=UTCRC_OUTR;                                 //~7830I~
                break;                                             //~7830I~
            }                                                      //~7830I~
            srcdata=Ptgt->data+srcoffs;                            //~7830I~
            if (UTC_ISNORMALCHOF(Ptgt)) //tgt has chof(process remainig data)//~7830I~
            {                                                      //~7830I~
                offsclear=srcoffs;                                 //~7830I~
                offstgt=offsclear+distcnt;		//remaing area space clear//~7830I~
                offsr=offstgt+srclenutf;                           //~7830I~
                tgtendpos=Ppost+Plen;                              //~7830I~
                lenrc=UTCLENCCPOS(Ptgt)-tgtendpos;                 //~7830I~
                if (!(Popt & UTCO_EOL))    //cut remaining data    //~7830I~
                {                                                  //~7830I~
                    tgtendoffs=UTC_POS2OFFS(0,Ptgt,tgtendpos);     //~7830I~
                    lenrutf=UTCLENUTFCHOFFROMCPOS(Ptgt)-tgtendoffs;//~7830I~
                    if (lenrc>0)                                   //~7830I~
                    {                                              //~7830I~
                        if (offsr<tgtendoffs)                      //~7830I~
                            memcpy(UTCDATA(Ptgt)+offsr,UTCDATA(Ptgt)+tgtendoffs,(UINT)lenrutf);//~7830R~
                        else                                       //~7830I~
                        if (offsr>tgtendoffs)                      //~7830I~
                            memmove(UTCDATA(Ptgt)+offsr,UTCDATA(Ptgt)+tgtendoffs,(UINT)lenrutf);//~7830R~
                        diff=offsr-tgtendoffs;                     //~7830I~
                        if (diff)                                  //~7830I~
                        {                                          //~7830I~
                            srcchof=UTCCHOF(Ptgt)+UTCCPOS(Ptgt)+tgtendpos;//~7830I~
                            UTC_CHOFADJUST(srcchof,lenrc+1,diff)   //~7830R~
                        }                                          //~7830I~
                    }                                              //~7830I~
                }//not EOL                                         //~7830I~
            	memmove(UTCDATA(Ptgt)+offstgt,srcdata,(UINT)srclenutf);//~7830R~
                srcchof=UTCCHOF(Ptgt)+UTCCPOS(Ptgt)+Pposs;         //~7830I~
                tgtchof=UTCCHOF(Ptgt)+UTCCPOS(Ptgt)+Ppost;         //~7830I~
                diff=offstgt-srcoffs;                              //~7831R~
                UTC_CHOFMOVE(tgtchof,srcchof,Plen+1,diff);         //~7831R~
                memset(UTCDATA(Ptgt)+offsclear,' ',(UINT)distcnt); //~7830R~
                srcchof=UTCCHOF(Ptgt)+UTCCPOS(Ptgt)+Pposs;         //~7830I~
                diff=*srcchof;                                     //~7830I~
                UTC_CHOFSET(srcchof,distcnt,diff);                 //~7830R~
                if (Popt & UTCO_EOL || lenrc<0)    //cut remaining data//~7831R~
                    Ptgt->lenc=(int)(Ptgt->cpos+tgtendpos);        //~7830I~
            }                                                      //~7830I~
            else                                                   //~v61iI~
                memmove(tgtdata,srcdata,(UINT)srclenutf);          //~v61iI~
        }//shiftR                                                  //~7830I~
        break;                                                     //~7823M~
    }                                                              //~7823M~
UTRACEP("UTCmemcpys rc=%d,ret=%p tgt lenc=%d,cpos=%d\n",Gutfrc,tgtdata,Ptgt->lenc,Ptgt->cpos);//~7823M~
    return tgtdata;                                                //~7823M~
}//UTCmemshifts                                                    //~7830R~
//*******************************************************          //~7728I~
//*strncpy                                                         //~7728I~
//*******************************************************          //~7728I~
char *UTCstrncpys(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,UINT Plen)//~7728I~
{                                                                  //~7728I~
    int srcstrlen,lens,rlen;                                       //~7729R~
    int pos;                                                       //~v61dI~
    char *pc;                                                      //~7728I~
//*********************************                                //~7728I~
    if (!UTF8MODE() || (!UTC_ISNORMALCHOF(Pputct) && !UTC_ISNORMALCHOF(Pputcs)))//~7801R~
		return strncpy(UTCDATA(Pputct)+Ppost,UTCDATA(Pputcs)+Pposs,Plen);//~7728I~
    if (Popt & UTCO_EOLSTOP)	//sue chof                         //~v60rR~
    {                                                              //~v60rI~
		srcstrlen=UTCLENCCPOS(Pputcs);                             //~v60rI~
        Popt &=UTCO_EOLSTOP;	//used                             //~v60rR~
    }                                                              //~v60rI~
    else                                                           //~v60rI~
		srcstrlen=UTCstrlens(Popt,Pputcs,Pposs);                   //~v60rR~
    lens=min(srcstrlen,(int)Plen);                                 //~7729R~
	pc=UTCmemcpys(Popt,Pputct,Ppost,Pputcs,Pposs,lens);            //~7729R~
    rlen=Plen-lens;                                                //~7729R~
    if (rlen>0)                                                    //~7729R~
    {                                                              //~v61dI~
      if (Popt & UTCO_BYOFF) //Ppost is offset                     //~v61dR~
      {                                                            //~v61dI~
			if (utfgetposoffs(Popt,Pputct,Ppost,&pos,0))           //~v61dI~
            {	                                                   //~v61dI~
				UTCmemsets(Popt,Pputct,pos+lens,0,rlen);           //~v61dR~
            }                                                      //~v61dI~
      }                                                            //~v61dI~
      else                                                         //~v61dI~
		UTCmemsets(Popt,Pputct,Ppost+lens,0,rlen);                 //~7729R~
    }                                                              //~v61dI~
    return pc;                                                     //~7728I~
}//UTCstrncpys                                                     //~7728I~
//*******************************************************          //~7806I~
//*memcpy                                                          //~7806I~
//*******************************************************          //~7806I~
char *UTCmemmoves(int Popt,PUTCHARS Ptgt,int Ppost,int Pposs,UINT Plen)//~7806I~
{                                                                  //~7806I~
    int srcoffs,srclenutf,tgtoffs,diff,cpos,ovfcnt,lenc;           //~7806R~
    UCHAR *srcdata,*tgtdata;                                       //~7806I~
    PCHOFTYPE srcchof,tgtchof;                                     //~7806I~
//*********************************                                //~7806I~
	if (Popt & UTCO_SHIFTR)                                        //~7830I~
		return UTCmemshifts(Popt,Ptgt,Ppost,Pposs,Plen);           //~7830I~
	Gutfrc=0;                                                      //~7806I~
UTRACEP("UTCmemcpys opt=%x, TGT=&p,post=%d,poss=%d,chof=%p,lenc=%d,cpos=%d\n",Popt,Ptgt,Ppost,Pposs,Ptgt->chof,Ptgt->lenc,Ptgt->cpos);//~7806R~
	tgtdata=UTCDATA(Ptgt)+Ppost;                                   //~7806I~
	srcdata=UTCDATA(Ptgt)+Pposs;                                   //~7806R~
    cpos=Ptgt->cpos;                                               //~7806I~
	lenc=Ptgt->lenc;                                               //~7806I~
    for(;;)                                                        //~7806I~
    {                                                              //~7806I~
    	if (!UTF8MODE() || !UTC_ISNORMALCHOF(Ptgt))                //~7806I~
        {                                                          //~7806I~
			memmove(tgtdata,srcdata,Plen);                         //~7806I~
            break;                                                 //~7806I~
        }                                                          //~7806I~
        ovfcnt=Ppost-(lenc-cpos);                                  //~7806I~
        if (ovfcnt>0)                                              //~7806I~
        {                                                          //~7806I~
        	UTCmemsetP(Ptgt,lenc-cpos,' ',ovfcnt);                 //~7825R~
		    lenc=Ptgt->lenc;                                       //~7806I~
        }                                                          //~7806I~
		if (utfgetposoffs(Popt,Ptgt,Ppost,0,&tgtoffs))  //offset from current data//~7806I~
        {                                                          //~7806I~
            Gutfrc=UTCRC_OUTR;                                     //~7806I~
    		break;                                                 //~7806I~
        }                                                          //~7806I~
        tgtdata=Ptgt->data+tgtoffs;                                //~7806I~
        if (utfgetposoffscntlen(0,Ptgt,Pposs,Plen,0,&srcoffs,0,&srclenutf))//~7806I~
        {                                                          //~7806I~
            Gutfrc=UTCRC_OUTR;                                     //~7806I~
            break;                                                 //~7806I~
        }                                                          //~7806I~
        srcdata=Ptgt->data+srcoffs;                                //~7806R~
        memmove(tgtdata,srcdata,(UINT)srclenutf);                  //~7806I~
        tgtchof=Ptgt->chof+Ptgt->cpos+Ppost;                       //~7806I~
        srcchof=Ptgt->chof+Ptgt->cpos+Pposs;                       //~7806I~
        diff=tgtoffs-srcoffs;                                      //~7806I~
        UTC_CHOFMOVE(tgtchof,srcchof,Plen+1,diff)                  //~7806I~
        if (lenc<(int)(cpos+Ppost+Plen))                           //~7806I~
	    	Ptgt->lenc=(int)(cpos+Ppost+Plen);                     //~7806I~
        break;                                                     //~7806I~
    }                                                              //~7806I~
UTRACEP("UTCmemcmove rc=%d,ret=%p tgt lenc=%d,cpos=%d\n",Gutfrc,tgtdata,Ptgt->lenc,Ptgt->cpos);//~7806I~
    return tgtdata;                                                //~7806I~
}//UTCmemmoves                                                     //~7830R~
//*******************************************************          //~7716I~
//*memcpy                                                          //~7716I~
//*******************************************************          //~7716I~
char *UTCmemcpyDs(int Popt,PUTCHARS Pputct,int Ppost,void *Psrc,UINT Plen)//~7728R~
{                                                                  //~7716I~
	UTCHARS parmutc;                                               //~7728I~
//*********************************                                //~7716I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputct))                  //~7801I~
		return memcpy(UTCDATA(Pputct)+Ppost,Psrc,Plen);            //~7729R~
	UTCINITD(parmutc,Psrc);                                        //~7728I~
    if (Popt & UTCO_ASCII)                                         //~7729I~
    	parmutc.chof=UTCCHOFASCII;                                 //~7729R~
	return UTCmemcpys(Popt,Pputct,Ppost,&parmutc,0,Plen);          //~7728I~
}//UTCmemcpyDs                                                     //~7716I~
//*******************************************************          //~7728I~
//*strncpyD                                                        //~7728I~
//*******************************************************          //~7728I~
char *UTCstrncpyDs(int Popt,PUTCHARS Pputc,int Ppost,void *Psrc,UINT Plen)//~7728R~
{                                                                  //~7728I~
	UTCHARS parmutc;                                               //~7729I~
//*********************************                                //~7728I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7801I~
		return strncpy(UTCDATA(Pputc)+Ppost,Psrc,Plen);            //~7728R~
	UTCINITD(parmutc,Psrc);                                        //~7729I~
    if (Popt & UTCO_ASCII)                                         //~7729I~
    	parmutc.chof=UTCCHOFASCII;                                 //~7729R~
	return UTCstrncpys(Popt,Pputc,Ppost,&parmutc,0,Plen);          //~7729R~
}//UTCstrncpyDs                                                    //~7728I~
//*******************************************************
//*memcmp
//*******************************************************
int UTCmemcmps(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,UINT Plen)//~7712R~
{
    int lens,offss,lent,offst,rc,post,cntt,poss,len,cnts;          //~7716R~
    UCHAR *pdatat,*pdatas;                                         //~7712I~
//*********************************
    if (!UTF8MODE() || (!UTC_ISNORMALCHOF(Pputct) && !UTC_ISNORMALCHOF(Pputcs)))//~7801I~
    {                                                              //~7712I~
        if (Popt & UTCO_NOCASE)                                    //~7810I~
			return memicmp(UTCDATA(Pputct)+Ppost,UTCDATA(Pputcs)+Pposs,Plen);//~7810I~
		return memcmp(UTCDATA(Pputct)+Ppost,UTCDATA(Pputcs)+Pposs,Plen);//~7713R~
    }                                                              //~7712I~
	if (Plen<=0)
    	return 0;
	if (utfgetposoffscntlen(Popt,Pputct,Ppost,Plen,&post,&offst,&cntt,&lent))//~7729R~
        return 0;                                                  //~7712R~
	if (utfgetposoffscntlen(Popt,Pputcs,Pposs,Plen,&poss,&offss,&cnts,&lens))//~7729R~
        return 0;                                                  //~7712R~
    pdatat=Pputct->data+offst;                                     //~7713R~
    pdatas=Pputcs->data+offss;                                     //~7713R~
    len=min(lent,lens);                                            //~7712R~
    if (Popt & UTCO_NOCASE)                                        //~7810I~
	    rc=memicmp(pdatat,pdatas,(UINT)len);                       //~7810I~
    else                                                           //~7810I~
    	rc=memcmp(pdatat,pdatas,(UINT)len);                        //~7810R~
    if (rc)                                                        //~7712R~
        return rc;                                                 //~7712R~
    rc=lent-lens;                                                  //~7712R~
    return rc;
}//UTCmemcmps
//*******************************************************          //~7725I~
//*memcmp                                                          //~7725I~
//*******************************************************          //~7725I~
int UTCmemcmpDs(int Popt,PUTCHARS Pputct,int Ppos,UCHAR *Psrc,UINT Plen)//~7725R~
{                                                                  //~7725I~
	UTCHARS parmutc;                                               //~7729I~
//*********************************                                //~7725I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputct))                  //~7801I~
    {                                                              //~7725I~
		return memcmp(UTCDATA(Pputct)+Ppos,Psrc,Plen);             //~7725R~
    }                                                              //~7725I~
	UTCINITD(parmutc,Psrc);                                        //~7729I~
    if (Popt & UTCO_ASCII)                                         //~7729I~
    	parmutc.chof=UTCCHOFASCII;                                 //~7729R~
	return UTCmemcmps(Popt,Pputct,Ppos,&parmutc,0,Plen);           //~7729R~
}//UTCmemcmpDs                                                     //~7725I~
//*******************************************************          //~7726I~
//*strlen                                                          //~7726I~
//*******************************************************          //~7726I~
int UTCstrlens(int Popt,PUTCHARS Pputc,int Ppos)                   //~7728R~
{                                                                  //~7726I~
    int newcnt,newlenutf,len,pos,offs,maxcol=-1;                   //~7930R~
    int maxcnt,initoffs;                                           //~v60rI~
    PCHOFTYPE pchof;                                               //~v60rI~
    UCHAR *pdata;                                                  //~7726I~
//*********************************                                //~7726I~
	if (Popt & UTCO_BYADDR)	//source is not UTCHARS but UCHAR      //~7728I~
	    pdata=(UCHAR*)(ULONG)Pputc;                                //~7728R~
    else                                                           //~7728I~
	    pdata=UTCDATA(Pputc);                                      //~7728I~
    if (!UTF8MODE()||UTC_ISASCII(Pputc))                           //~7729I~
    	return strlen(pdata+Ppos);                                 //~7728I~
    pos=Ppos;                                                      //~v60rI~
	if (Ppos)                                                      //~7728I~
    {                                                              //~7728I~
		if (Popt & UTCO_MAXCOL)	//len to the col                   //~7826I~
        {                                                          //~7826I~
        	maxcol=Ppos;                                           //~7826R~
            offs=0;                                                //~7826I~
            pos=0;                                                 //~v60rI~
        }                                                          //~7826I~
    	else                                                       //~7826I~
		if (Popt & UTCO_BYADDR)	//source is not UTCHARS but UCHAR  //~7728I~
        	offs=Ppos;                                             //~7728I~
        else                                                       //~7728I~
			if (utfgetposoffs(Popt,Pputc,Ppos,&pos,&offs))         //~7729R~
        		return 0;                                          //~7728I~
    }                                                              //~7728I~
    else                                                           //~7728I~
    {                                                              //~7930I~
		if (Popt & UTCO_MAXCOL)	//len to the col                   //~7930I~
            return 0; //strlen=0                                   //~7930I~
    	offs=0;                                                    //~7728I~
        pos=0;                                                     //~v60rI~
    }                                                              //~7930I~
  if (!(Popt & UTCO_BYADDR)                                        //~v60rI~
  &&  UTC_ISNORMALCHOF(Pputc))                                     //~v60rI~
  {                                                                //~v60rI~
    	maxcnt=UTCLENCCPOS(Pputc);	//maxlenc from cpos            //~v60rI~
        if (maxcol>0)               //parm specified               //~v60rI~
        	maxcnt=min(maxcol,maxcnt);                             //~v60rI~
    	pchof=UTCCHOFCPOS(Pputc);                                  //~v60rI~
        initoffs=*pchof;                                           //~v60rI~
        maxcnt-=pos;                                               //~v60rI~
        pchof+=pos;                                                //~v60rI~
        pdata+=*pchof-initoffs;                                    //~v60rI~
        initoffs=*pchof;                                           //~v60rR~
        for (newcnt=0,newlenutf=0;newcnt<maxcnt;newcnt++,pchof++)  //~v60rR~
        {                                                          //~v60rI~
            newlenutf=*pchof-initoffs;                             //~v60rI~
            if (!*(pdata+newlenutf))	//null detected            //~v60rI~
            	break;                                             //~v60rI~
        }                                                          //~v60rI~
  }                                                                //~v60rI~
  else                                                             //~v60rI~
  {                                                                //~v60rI~
    pdata+=offs;                                                   //~7728I~
    len=strlen(pdata);                                             //~7728R~
	utfstrchkmbr2wc(Popt,pdata,len,0/*startpos*/,maxcol,-1/*maxlenutf*/,0/*chof*/,0/*initoffs*/,&newcnt,0,&newlenutf);//~7930R~
  }                                                                //~v60rI~
	if (Popt & UTCO_UTFLEN)	//len to the col                       //~7930I~
    	return newlenutf;                                          //~7930I~
    return newcnt;                                                 //~7726I~
}//UTCstrlens                                                      //~7726I~
//*******************************************************          //~7728I~
//*count column of utf string from base addr                       //~7729R~
//*******************************************************          //~7728I~
int UTCwidths(int Popt,PUTCHARS Pputc,int Ppos,PUTCHARS Pbase)     //~7729R~
{                                                                  //~7728I~
    int pos,diff;                                                  //~7729R~
    UCHAR *pdata;                                                  //~7729R~
//*********************************                                //~7728I~
	pdata=UTC_POS2ADDR(0,Pputc,Ppos);                              //~7729I~
    diff=(int)((ULONG)pdata-(ULONG)Pbase->data);                   //~7803R~
    if (!UTF8MODE()||UTC_ISASCII(Pputc))                           //~7729R~
    	return diff;                                               //~7728I~
	if (utfgetposoffs(UTCO_BYOFF,Pbase,diff,&pos,0))               //~7806R~
    	return 0;                                                  //~7728I~
    return pos;                                                    //~7729R~
}//UTCwidths                                                       //~7728I~
//*******************************************************          //~7803I~
//*count column of utf string from base addr                       //~7803I~
//*******************************************************          //~7803I~
int UTCwidthDs(int Popt,PUTCHARS Pputc,int Ppos,UCHAR *Pbase)      //~7803I~
{                                                                  //~7803I~
	UTCHARS base;                                                  //~7803I~
//*********************************                                //~7803I~
	UTCINITD(base,(UCHAR*)(ULONG)Pbase);                           //~7803I~
    return UTCwidths(Popt,Pputc,Ppos,&base);                       //~7803I~
}//UTCwidthDs                                                      //~7803I~
//*******************************************************          //~7728I~
//*memspnc                                                         //~7728I~
//*******************************************************          //~7728I~
int UTCumemspncs(int Popt,PUTCHARS Pputc,int Ppos,int Pch,UINT Plen)//~7728I~
{                                                                  //~7728I~
    int pos,offs,len,cnt;                                          //~7728R~
    UCHAR *pdata;                                                  //~7728I~
//*********************************                                //~7728I~
	pdata=UTCDATA(Pputc);                                          //~7728R~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7801R~
		return umemspnc(pdata+Ppos,(char)Pch,Plen);                //~7728R~
	if (utfgetposoffscntlen(Popt,Pputc,Ppos,Plen,&pos,&offs,&cnt,&len))//~7729R~
        return 0;                                                  //~7728I~
    pdata+=offs;                                                   //~7728I~
	return umemspnc(pdata,(char)Pch,len);                          //~7728R~
}//UTCumemspncs                                                    //~7728R~
//*******************************************************          //~7728I~
//*memspnc                                                         //~7728I~
//*******************************************************          //~7728I~
int UTCumemrspncs(int Popt,PUTCHARS Pputc,int Ppos,int Pch,UINT Plen)//~7728I~
{                                                                  //~7728I~
    int pos,offs,len,cnt;                                          //~7728I~
    UCHAR *pdata;                                                  //~7728I~
//*********************************                                //~7728I~
	pdata=UTCDATA(Pputc);                                          //~7728I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7801I~
		return umemrspnc(pdata+Ppos,(char)Pch,Plen);               //~7728I~
	if (utfgetposoffscntlen(Popt,Pputc,Ppos,Plen,&pos,&offs,&cnt,&len))//~7729R~
        return 0;                                                  //~7728I~
    pdata+=offs;                                                   //~7728I~
	return umemrspnc(pdata,(char)Pch,len);                         //~7728I~
}//UTCumemrspncs                                                   //~7728I~
//*******************************************************          //~7829I~
//*memspnc                                                         //~7829I~
//*******************************************************          //~7829I~
size_t UTCustrnspns(int Popt,PUTCHARS Pputc,int Ppos,char *Pstr,UINT Plen)//~7829I~
{                                                                  //~7829I~
    int pos,offs,len,cnt;                                          //~7829I~
    UCHAR *pdata;                                                  //~7829I~
//*********************************                                //~7829I~
	pdata=UTCDATA(Pputc);                                          //~7829I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7829I~
		return ustrnspn(pdata+Ppos,Pstr,Plen);                     //~7829I~
	if (utfgetposoffscntlen(Popt,Pputc,Ppos,Plen,&pos,&offs,&cnt,&len))//~7829I~
        return 0;                                                  //~7829I~
    pdata+=offs;                                                   //~7829I~
	return ustrnspn(pdata,Pstr,len);                               //~7829I~
}//UTCustrnspns                                                    //~7829I~
//*******************************************************          //~7728I~
//*memspnc                                                         //~7728I~
//*******************************************************          //~7728I~
char *UTCmemchrs(int Popt,PUTCHARS Pputc,int Ppos,int Pch,UINT Plen)//~7728R~
{                                                                  //~7728I~
    int pos,offs,len,cnt,diff;                                     //~7801R~
    UCHAR *pdata,*pcr;                                             //~7801R~
//*********************************                                //~7728I~
	pdata=UTCDATA(Pputc);                                          //~7801I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7801R~
    {                                                              //~7801I~
        if (Popt & UTCO_MEMR)                                      //~7902I~
			pcr=umemrchr(pdata+Ppos,(char)Pch,Plen);               //~7902R~
        else                                                       //~7902I~
			pcr=memchr(pdata+Ppos,Pch,Plen);                       //~7902R~
	    if (Popt & UTCO_UPDATE)                                    //~7801I~
			UTCDATA(Pputc)=pcr;                                    //~7801I~
        return pcr;                                                //~7801I~
    }                                                              //~7801I~
    if (utfgetposoffscntlen(Popt,Pputc,Ppos,Plen,&pos,&offs,&cnt,&len))//~7801R~
        return 0;                                                  //~7801R~
    pdata+=offs;                                                   //~7801R~
    if (Popt & UTCO_MEMR)                                          //~7902I~
	    pcr=umemrchr(pdata,(char)Pch,len);                         //~7902R~
    else                                                           //~7902I~
	    pcr=memchr(pdata,Pch,len);                                 //~7902R~
    if (Popt & UTCO_UPDATE)                                        //~7801I~
    {                                                              //~7801I~
    	if (!pcr)                                                  //~7801I~
			UTCDATA(Pputc)=pcr;                                    //~7801I~
        else                                                       //~7801I~
        {                                                          //~7801I~
    		diff=(int)((ULONG)pcr-(ULONG)pdata);                   //~7801R~
        	UTCincO(Pputc,offs+diff);                              //~7801R~
        }                                                          //~7801I~
    }                                                              //~7801I~
    return pcr;                                                    //~7801I~
}//UTCmemchrs                                                      //~7728I~
//*******************************************************          //~7728I~
//*memrspn                                                         //~7728I~
//*******************************************************          //~7728I~
int UTCumemrspns(int Popt,PUTCHARS Pputc,int Ppos,UCHAR *Pstr,UINT Plen)//~7728I~
{                                                                  //~7728I~
    int pos,offs,cnt,len;                                          //~7728R~
    UCHAR *pdata;                                                  //~7728I~
//*********************************                                //~7728I~
	pdata=UTCDATA(Pputc);                                          //~7728R~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputc))                   //~7801R~
		return umemrspn(pdata+Ppos,Pstr,Plen);                     //~7728R~
	if (utfgetposoffscntlen(Popt,Pputc,Ppos,Plen,&pos,&offs,&cnt,&len))//~7729R~
        return 0;                                                  //~7728I~
    pdata+=offs;                                                   //~7728I~
	return umemrspn(pdata,Pstr,len);                               //~7728I~
}//UTCmemrspns                                                     //~7728I~
//*******************************************************          //~v60rI~
//*set dbcs and chof (no err replace)                              //~v60rI~
//*rc:0x01:dbcs detected, 0x02:nonspace char detect,0x04:invalid utf8 detected//~v60rI~
//*******************************************************          //~v60rI~
int UTCsetdbcstbl(int Popt,PUTCHARS Pputc,UCHAR *Ppdbcs,UINT Plenutf)//~v60rI~
{                                                                  //~v60rI~
    int width,rc;                                                  //~v60rI~
    UCHAR *pdata;                                                  //~v60rI~
    PCHOFTYPE pchof;                                               //~v60rI~
//*********************************                                //~v60rI~
	pdata=UTCDATA(Pputc);                                          //~v60rI~
	pchof=UTCCHOF(Pputc);                                          //~v60rI~
    if (UTC_ISASCII(Pputc))                                        //~v60rR~
    {                                                              //~v60rI~
        memset(Ppdbcs,0,Plenutf);                                  //~v60rI~
		return 0;                                                  //~v60rR~
    }                                                              //~v60rI~
	rc=utfsetdbcstbl(Popt,pdata,Ppdbcs,pchof,Plenutf,&width,0/*charcnt*/);//~v60rR~
    UTCLENC(Pputc)=width;                                          //~v60rI~
    return rc;                                                     //~v60rI~
}//UTCmemrspns                                                     //~v60rI~
#endif // UTF8SUPP                                                 //~v620I~
