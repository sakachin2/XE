//*CID://+v6BjR~:                                   update#=  729; //~v6BjR~
//***********************************************************************
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bs:160222 (BUG)ucvext_icuebc2ucs get U_BUFFER_OVERFLOW_ERROR for 0efcfc0f at ucvext_setupsubch when cp932(cp930 is ok)//~v6BsI~
//            cp930 is ok because ucvext_icuucs2ebc returns 0efefe0f.//~v6BsI~
//            So subchar chk is not effective and could not return rc=-3(subchar)//~v6BsI~
//            The reason is cp932 is not ebcdic;                   //~v6BsI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uN:140606 (BUG)icu dose not always subchar1 when subchar and subchar1 was defined. chk 0x1a myself//~v6uNI~
//v6hA:120822 (BUG)EBC handle subchar was not used for subcharchk  //~v6hAI~//~v6hhI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6he:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v6heI~
//v6h8:120609 (BUG)by chk c4701 warning by VC6(used uninitialized variable)//~v6h8I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6fp:120506 (BUG)ICU subchar len for pconverters                 //~v6fpI~
//v6fo:120506 (BUG)ICU fromUchar set null terminator               //~v6foI~
//v6fn:120503 ICU m2u returns U_STRING_NOT_TERMINATED_WARNING(output 2 ucs and colud not set null terminator)//~v6fnI~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6bj:111212 for XCV;F2B/B2F support                              //~v6b9I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v69s:100903 (BUG)xcv m2m trans to utf8(v66k but a2a calls not icuucs2local1 but iconvucvs2local1)//~v69sI~
//v69p:100902 (EBC)for xcv:handle support                          //~v69pI~
//v69d:100815 split ucvext                                         //~v69dI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//***********************************************************************
//* ucvext12.c                                                     //~v69dR~
//* ebc conversion using ICU
//***********************************************************************
#if defined(W32) || defined(LNX)
//***********************************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef W32                                                         //~v68hI~
    #include <io.h>     //setmode                                  //~v68hI~
    #include <fcntl.h>     //setmode                               //~v68hI~
#endif                                                             //~v68hI~

#include <ulib.h>
#include <ualloc.h>
#include <uedit.h>
#include <uparse.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uproc.h>
#include <ustring.h>
#include <ucvucs.h>                                                //~v5n3I~
#include <ucvebc.h>
#include <ucvebc2.h>
#include <ucvext.h>
#include <ucvext2.h>                                               //~v5mTR~
#include <ucvebc4.h>                                               //~v69cR~
#include <ufile.h>
#include <ufile5.h>
#include <ufemsg.h>
#include <utrace.h>
#include <uicu.h>
#include <utf.h>                                                   //~v5n0I~
#include <utf22.h>                                                 //~v66VI~
#include <ucvext12.h>                                              //~v69dI~
//*******************************************************
//#define UTRACEP printf //@@@@test                                //~v6b9R~
//redefine of ucvext.c                                             //~v69dI~
#define ICU_INITCHK(rc)  if (!IS_ICULIBOPENED()) 	return rc              //~v66hI~//~v69dR~
#define UCVEXT_ISDBCS1ST(Popt,ch) ucvext_isdbcs1st(Popt,ch)        //~v69dI~
//*******************************************************          //~v69dI~
static ICUFUNC_TOUCS    Spfunctoucs;                               //~v69dR~
static ICUFUNC_FROMUCS  Spfuncfromucs;                             //~v69dR~
static PUCVEXTCFG Spcfg;                                           //~v69dI~
static int        Sextflag;                                        //~v69dI~
static USHORT Ssubchardbcs=UDBCSCHK_SUBCHAR_DBCS;                  //~v69dI~
static USHORT Ssubcharsbcs=UDBCSCHK_SUBCHAR_SBCS;                  //~v69dI~
static UCHAR  Ssubcharlocalsbcs=CHAR_ASCII_ERR;	//3f"?"            //~v69dI~
static UCHAR *Ssubcharlocaldbcs;                                   //~v69dR~
static UCHAR  Ssubcharebcsbcs=CHAR_EBC_ERR;     //6f               //~v69dI~
static UCHAR *Ssubcharebcdbcs;       //ebc dbcs space              //~v69dR~
static int    Ssubcharebcdbcslen,Ssubcharlocaldbcslen;             //~v69dI~
static int Shandle;                                                //~v69cR~
//*************************************************************************//~v6hhI~
//int ucvext_icusubcharchk_handle(int Popt,int Phandle,WUCS Pucs,UCHAR *Pstr,int Plen);//~v6hhI~//~v6BjR~
int ucvext_icusubcharchk_handle(int Popt,int Phandle,UWUCS/*ucs4*/ Pucs,UCHAR *Pstr,int Plen);//~v6BjI~
//*************************************************************************//~v69dI~
//*init                                                            //~v69dI~
//*************************************************************************//~v69dI~
int ucvext12_init(int Popt,int Pextflag,PUCVEXTCFG Ppcfg,void **Pfuncs)//~v69dR~
{                                                                  //~v69dI~
//********************                                             //~v69dI~
	Spcfg=Ppcfg;                                                   //~v69dI~
	Sextflag=Pextflag;                                             //~v69dI~
    Spfunctoucs=(ICUFUNC_TOUCS)Pfuncs[0];                          //~v69dR~
    Spfuncfromucs=(ICUFUNC_FROMUCS)Pfuncs[1];                      //~v69dR~
    UTRACED("ucvext2 cfg",Ppcfg,UCVEXTCFGSZ);                      //~v69dI~
	if (Ppcfg->UCECsubcharsbcs)                                    //~v69dI~
		Ssubcharsbcs=Ppcfg->UCECsubcharsbcs;                       //~v69dI~
	if (Ppcfg->UCECsubchardbcs)                                    //~v69dI~
		Ssubcharsbcs=Ppcfg->UCECsubchardbcs;                       //~v69dI~
    Ssubcharlocalsbcs=Ppcfg->UCECsubcharlocalsbcs;                 //~v69dI~
    Ssubcharebcsbcs=Ppcfg->UCECsubcharebcsbcs;                     //~v69dI~
	Ssubcharlocaldbcs=Ppcfg->UCECsubcharlocaldbcs;                 //~v69dR~
	Ssubcharebcdbcs=Ppcfg->UCECsubcharebcdbcs;                     //~v69dR~
//  Ssubcharlocaldbcslen=strlen(Ssubcharlocaldbcs);                //~v69dR~//~v6BkR~
    Ssubcharlocaldbcslen=(int)strlen(Ssubcharlocaldbcs);           //~v6BkI~
//  Ssubcharebcdbcslen=strlen(Ssubcharebcdbcs);                    //~v69dR~//~v6BkR~
    Ssubcharebcdbcslen=(int)strlen(Ssubcharebcdbcs);               //~v6BkI~
    UTRACEP("getconverter subchar dbcs=%x,sbcs=%x\n",Ssubchardbcs,Ssubcharsbcs);//~v69dI~
    UTRACEP("getconverter subcharebc dbcs=%02x%02x,sbcs=%02x\n",*Ssubcharebcdbcs,*(Ssubcharebcdbcs+1),Ssubcharebcsbcs);//~v69dR~
    UTRACEP("getconverter subcharlocal dbcs=%02x%02x,sbcs=%02x\n",*Ssubcharlocaldbcs,*(Ssubcharlocaldbcs+1),Ssubcharlocalsbcs);//~v69dR~
    return 0;                                                      //~v69dI~
}//ucvext12_init                                                   //~v69dI~
//*************************************************************************
//*translate by icu converter
//* ebc to ucs
//* rc:-3:subchar was set,4:err                                    //~v66DI~
//*************************************************************************
//int ucvext_icuebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs)//~v66CR~
//int ucvext_icuebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs)//~v66CI~//~v6hhR~
//int ucvext_icuebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs)//~v6hhI~//~v6BjR~
int ucvext_icuebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs)//~v6BjI~
{
//#ifdef W32                                                       //~v5n2R~
    ICUFUNC_TOUCS   api;
	UErrorCode err=U_ZERO_ERROR;
    UConverter *converter;                                         //~v5mTM~
	char wkebc[4];
//  USHORT wkucs[2];                                               //~v6BsR~
    USHORT wkucs[8];   //may set null terminator                   //~v6BsR~
    int len;                                                       //~v5mTR~
//#endif                                                           //~v5n2R~
    int rc=0;                                                      //~v5mTI~
    int dbcssw;                                                    //~v66DI~
    int swsurrogate;                                               //~v6BjR~
//***************************
UTRACEP("ebc2ucs1 opt=%x,converter=%x,inplen=%d\n",Popt,Pconverter,Pinplen);//~v5mYR~
	if (!Pconverter)                                               //~v681I~
    	return 4;                                                  //~v681I~
//#ifdef W32                                                       //~v5n2R~
  if (IS_ICUMODE())                                                //~v5n1R~
  {                                                                //~v5n2I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
    api=Spfunctoucs;  //ucnv_toUChars;
    converter=(UConverter*)Pconverter;
//  if (Popt & EBC2ASC_STAT_SO)                                    //~v5mYR~
    if (Popt & EBC2ASC_STAT_SO && Pinplen>1)                       //~v5mYI~
    {
        wkebc[0]=CHAR_SO;
        wkebc[1]=*Ppebc;
        wkebc[2]=*(Ppebc+1);
        wkebc[3]=CHAR_SI;
        wkucs[1]=0; //forIS_UTF16_PAIR                             //~v6BjI~
//      len=(*api)(converter,wkucs,2,wkebc,4,&err);                //~v6BkR~
//      len=(int)(*api)(converter,wkucs,2,wkebc,4,&err);           //~v6BkI~//~v6BsR~
        len=(int)(*api)(converter,wkucs,(int)(sizeof(wkucs)/sizeof(USHORT)),wkebc,4,&err);//~v6BsI~
        dbcssw=1;                                                  //~v66DI~
    }
    else
    {
        wkebc[1]=*Ppebc;
        wkebc[2]=0;
//      len=(*api)(converter,wkucs,2,wkebc+1,1,&err);              //~v6BkR~
//      len=(int)(*api)(converter,wkucs,2,wkebc+1,1,&err);         //~v6BkI~//~v6BsR~
        len=(int)(*api)(converter,wkucs,(int)(sizeof(wkucs)/sizeof(USHORT)),wkebc+1,1,&err);//~v6BsR~
//len is ucs count                                                 //~v66NI~
        dbcssw=0;                                                  //~v66DI~
    }
//  if (U_FAILURE(err))                                            //~v66JR~
//  if (!len || U_FAILURE(err))                                    //~v66JI~//~v6fnR~
//  if (len!=1 || U_FAILURE(err))                                  //~v6fnI~//~v6BjR~
    swsurrogate=!U_FAILURE(err) && len==2 && IS_UTF16_PAIR(wkucs[0],wkucs[1]);//~v6BjI~
                                                                   //~v6BjI~
    if ((len!=1 && !swsurrogate) || U_FAILURE(err))                //~v6BjR~
	{
		UTRACEP("ERR ebc2ucs1 err=%08x=%s\n",(UINT)err,ucvext_icuuerrname(err));
		rc=4;
	}
    else
    {                                                              //~v66DI~
        *Ppucs=wkucs[0];
        if (swsurrogate)                                           //~v6BjR~
        	*Ppucs=UTF16_TO_UCS4(wkucs[0],wkucs[1]);               //~v6BjI~
        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66DR~//~v66NR~
//      	rc=ucvext_icusubcharchk(UCVEXTISCO_B2U,*Ppucs,wkebc+1,1+dbcssw);//~v66DI~//~v66NR~//~v6hhI~
        	rc=ucvext_icusubcharchk_handle(UCVEXTISCO_B2U,Shandle,*Ppucs,wkebc+1,1+dbcssw);//~v6hhI~
    }                                                              //~v66DI~
  }                                                                //~v5n2I~
//#else //W32                                                      //~v5n2R~
  else                                                             //~v5n2I~
	rc=ucvext_iconvebc2ucs1(Popt,Pconverter,Ppebc,Pinplen,Ppucs);  //~v5mTR~
//#endif                                                           //~v5n2R~
    UTRACEP("ebc2ucs1 rc=%x,in=%02x%02x,out=%04x\n",rc,*Ppebc,(Pinplen>1?*(Ppebc+1):0),*Ppucs);//~v5mTR~
    return rc;
}//ucvext_icuebc2ucs1
//*************************************************************************
//*translate by icu converter
//* local to ucs
//* rc:-3:subchar was set,4:err                                    //~v66DI~
//*    -11:dbcs split(rc from iconvlocal2ucs1)                     //~v66TI~
//*************************************************************************
#ifdef UTF8UCS4                                                    //~v65cI~
int ucvext_iculocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs)//~v65cI~
#else                                                              //~v65cI~
//int ucvext_iculocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs)//~v6hhR~
//int ucvext_iculocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs)//~v6hhI~//~v6BjR~
int ucvext_iculocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS/*ucs4*/*Ppucs)//~v6BjI~
#endif                                                             //~v65cI~
{
//#ifdef W32                                                       //~v5n2R~
    ICUFUNC_TOUCS   api;
	UErrorCode err=U_ZERO_ERROR;
    UConverter *converter;                                         //~v5mTM~
//  USHORT wkucs[2];                                               //~v5mTR~//~v6fnR~
	USHORT wkucs[8];                                               //~v6fnI~
    int ucsctr;                                                    //~v6fnI~
    int inplen,chklen;                                             //~v5mTR~
//#endif                                                           //~v5n2R~
    int rc=0;                                                      //~v5mTI~
    int opt;                                                       //~v66nI~
//***************************
UTRACEP("local2ucs1 opt=%x,converter=%x len=%d\n",Popt,Pconverter,Pinplen);
    if (!(Popt & EBC2ASC_LOCALCV))	//local converter
    {                                                              //~v66nI~
//        return udbcschk_mb2ucs1(Popt,Ppmbs,Pinplen,Ppchklen,Ppucs);//~v66nR~
        opt=UDCM2U1O_A2E;       //for locale to ebc                //~v66nR~
//        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66FI~//~v66KR~
//            opt|=UDCM2U1O_BACKCHK; //trans back chk,ret 3 if rev chk err//~v66FR~//~v66KR~
        rc=udbcschk_mb2ucs1(opt,Ppmbs,Pinplen,Ppchklen,Ppucs);     //~v66nI~
        return rc;                                                 //~v66nI~
    }                                                              //~v66nI~
//#ifdef W32                                                       //~v5n2R~
//if (IS_ICUMODE())                                                //~v5n1R~//~v66KR~
//if (IS_ICULOCALMODE())                                           //~v66KR~//~v6f3R~
  if (IS_ICULOCALMODE_OR_MBLOCAL()) //by ebcmap or -Yi             //~v6f3R~
  {                                                                //~v5n2I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
    api=Spfunctoucs;  //ucnv_toUChars;
    converter=(UConverter*)Pconverter;
    if (Popt & EBC2ASC_STAT_SO)  //source is dbcs
    {                                                              //~v66BI~
#ifdef LNX                                                         //~v66BI~
	  if (Pinplen>1 && UDBCSCHK_ISGB42ND(*(Ppmbs+1)))              //~v66BI~
    	inplen=min(4,Pinplen);     //4byte GB18030                 //~v66BI~
      else                       //!GB4                            //~v66BI~
	  if (MAYBESS3(*Ppmbs))		//no envchk                        //~v66BI~
    	inplen=min(3,Pinplen);     //EUC 3fxxxx                    //~v66BI~
      else                       //!GB4                            //~v66BI~
#endif                                                             //~v66BI~
    	inplen=min(2,Pinplen);
    }                                                              //~v66BI~
    else
    	inplen=1;
//  (*api)(converter,wkucs,2,Ppmbs,inplen,&err);                   //~v5mTR~//~v6fnR~
//  ucsctr=(*api)(converter,wkucs,sizeof(wkucs)/sizeof(wkucs[0]),Ppmbs,inplen,&err);//~v6fnR~//~v6BkR~
    ucsctr=(int)(*api)(converter,wkucs,sizeof(wkucs)/sizeof(wkucs[0]),Ppmbs,(UINT)inplen,&err);//~v6BkI~
//  if (U_FAILURE(err))                                            //~v6fnR~
    if (U_FAILURE(err)                                             //~v6fnR~
//  ||  ucsctr!=1		//sbcs subch 1a and next sbcs              //~v6fnI~//~v6BjR~
    ||  (ucsctr!=1 && ucsctr!=2)		//sbcs subch 1a and next sbcs//~v6BjI~
    )                                                              //~v6fnI~
	{
        chklen=1+((Popt & EBC2ASC_STAT_SO)!=0);//source is sbcs    //~v5mTR~
		rc=4;
		UTRACEP("ERR local2ucs1 chklen=%d,err=%08x=%s\n",chklen,(UINT)err,ucvext_icuuerrname(err));//~v6fnI~
	}
    else
    {
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6BjR~
//        *Ppucs=(WUCS)wkucs[0];                                     //~v65cI~//~v6BjR~
//#else                                                              //~v65cI~//~v6BjR~
//        *Ppucs=wkucs[0];                                         //~v6BjR~
//#endif                                                             //~v65cI~//~v6BjR~
		if (ucsctr==1)                                             //~v6BjI~
        	*Ppucs=(UWUCS)wkucs[0];                                //~v6BjI~
        else                                                       //~v6BjI~
        	*Ppucs=UTF16_TO_UCS4(wkucs[0],wkucs[1]);               //~v6BjI~
        chklen=inplen;
//currently no path because local converter is not ICU             //~v66NI~
        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66DR~
//      	rc=ucvext_icusubcharchk(UCVEXTISCO_L2U,*Ppucs,Ppmbs,inplen);//~v66DI~//~v6hhR~
        	rc=ucvext_icusubcharchk_handle(UCVEXTISCO_L2U,Shandle,*Ppucs,Ppmbs,inplen);//~v6hhI~
    }
  if (Ppchklen)                                                    //~v66DI~
    *Ppchklen=chklen;
    UTRACEP("local2ucs1 rc=%x,inplen=%d,in=%02x%02x,chklen=%d,outucs=%04x\n",rc,inplen,*Ppmbs,*(Ppmbs+1),chklen,wkucs[0]);//~v5mTM~
    UTRACED("local2ucs1 wkucs",wkucs,sizeof(wkucs));               //~v5mTM~
  }                                                                //~v5n2I~
//#else    //W32                                                   //~v5n2R~
  else                                                             //~v5n2I~
	rc=ucvext_iconvlocal2ucs1(Popt,Pconverter,Ppmbs,Pinplen,Ppchklen,Ppucs);//~v5mTI~
//#endif                                                           //~v5n2R~
    return rc;
}//ucvext_iculocal2ucs1
//*************************************************************************
//*translate by icu converter
//* ucs to ebc
//* rc: 1:dbcs, -2:hanakaku kana,-3:subchar was set,4 :err                                   //~v66AR~//~v66DR~//~v66NR~
//*************************************************************************
//int ucvext_icuucs2ebc1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6hhR~
//int ucvext_icuucs2ebc1(int Popt,ULPTR Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6hhI~//~v6BjR~
int ucvext_icuucs2ebc1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6BjI~
{
//#ifdef W32                                                       //~v5n2R~
    ICUFUNC_FROMUCS   api;
	UErrorCode err=U_ZERO_ERROR;
    UConverter *converter;                                         //~v5mTM~
	USHORT wkucs[2];
//#endif                                                           //~v5n2R~
	char wkebc[8]; 	//mex ebc dbcs is 4 for chinese                //~v5mTM~
    int rc=0,len;
    int swsubch=0,rc2;                                             //~v66DR~
    int utf16ctr;                                                  //~v6BjI~
//***************************
UTRACEP("icuucs2ebc1 converter=%p,opt=%x\n",Pconverter,Popt);      //~v681R~
#ifdef UTF8EBCD                                                    //~v660I~
    *Ppoutlen=0; //for the case of err                             //~v660I~
#endif                                                             //~v660I~
	if (!Pconverter)                                               //~v681I~
    	return 4;                                                  //~v681I~
//#ifdef W32                                                       //~v5n2R~
  if (IS_ICUMODE())                                                //~v5n1R~
  {                                                                //~v5n2I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
    api=Spfuncfromucs;  //ucnv_fromUChars;
    converter=(UConverter*)Pconverter;
//  wkucs[0]=Pucs;                                                 //~v6BjR~
    UCS4_TO_UTF16(Pucs,wkucs,&utf16ctr);                           //~v6BjI~
//  len=(*api)(converter,wkebc,sizeof(wkebc),wkucs,1,&err);        //~v6BjR~
//  len=(*api)(converter,wkebc,sizeof(wkebc),wkucs,utf16ctr,&err); //~v6BjI~//~v6BkR~
    len=(int)(*api)(converter,wkebc,sizeof(wkebc),wkucs,(UINT)utf16ctr,&err);//~v6BkI~
    UTRACEP("ICUucs2ebc1 rc=%x,in=%04x,outlen=%d,out=%02x%02x%02x%02x\n",rc,Pucs,len,wkebc[0],wkebc[1],wkebc[2],wkebc[3]);//~v66rI~
//  if (U_FAILURE(err))                                            //~v66JR~
    if (!len || U_FAILURE(err))                                    //~v66JI~
	{
		UTRACEP("ERR ucs2ebc1 err=%08x=%s\n",(UINT)err,ucvext_icuuerrname(err));
		rc=4;
	}
    else                                                           //~v66DI~
    {                                                              //~v66DI~
        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66DI~//~v66NR~
//      	swsubch=ucvext_icusubcharchk(UCVEXTISCO_U2B,Pucs,wkebc,len);//~v66DR~//~v6hhR~
        	swsubch=ucvext_icusubcharchk_handle(UCVEXTISCO_U2B,Shandle,Pucs,wkebc,len);//~v6hhI~
    }//fromUChar ok                                                //~v66DI~
  }                                                                //~v5n2I~
//#else //W32                                                      //~v5n2R~
  else                                                             //~v5n2I~
  {                                                                //~v5n2I~
//  if (ucvext_iconvucs2ebc1(Popt,Pconverter,Pucs,wkebc,&len)>1) //1:dbcs//~v5mTR~//~v66DR~
    rc2=ucvext_iconvucs2ebc1(Popt,Pconverter,Pucs,wkebc,&len);     //~v66DI~
    if (rc2>1) //1:dbcs                                            //~v66DI~
    {                                                              //~v5mTI~
		rc=4;                                                      //~v5mTI~
    }                                                              //~v5mTI~
    else                                                           //~v66DI~
    {                                                              //~v66DI~
        if (rc2==UCVEXTRC_SUBCH)                                   //~v66DI~
        	swsubch=rc2;                                           //~v66DI~
    }                                                              //~v66DI~
  }                                                                //~v5n2I~
//#endif                                                           //~v5n2R~
//  else                                                           //~v5n2R~
	if (!rc)                                                       //~v5n2I~
    {
    	if (len>0)
        {
        	if (len>2 && *wkebc==CHAR_SO && *(wkebc+len-1)==CHAR_SI)
            {
                len-=2;
            	memcpy(Ppebc,wkebc+1,(UINT)len);
                rc=1;
            }
            else
        	if (len==2 && *wkebc==CHAR_SI)	//terminated dbcs and set sbcs?//~v66AI~
            {                                                      //~v66AI~
                len=1;                                             //~v66AI~
            	*Ppebc=wkebc[1];                                   //~v66AR~
            }                                                      //~v66AI~
            else                                                   //~v66AI~
            {
        		memcpy(Ppebc,wkebc,(UINT)len);
            }                                                      //~v66AI~
		    	if (Popt & EBC2ASC_STAT_SO)	//in so status
            {                                                      //~v66AI~
                  if (len!=2)                                      //~v5mTI~
//                	rc=4;                                          //~v66AR~
                  	rc=UCVEXTRC_HANKANA;	//-2                   //~v66AR~
            }
        }
        *Ppoutlen=len;
    }
    if (swsubch)                                                   //~v66DI~
    	rc=swsubch;                                                //~v66DI~
    UTRACEP("ucs2ebc1 rc=%x,in=%04x,outlen=%d,out=%02x%02x%02x%02x\n",rc,Pucs,len,wkebc[0],wkebc[1],wkebc[2],wkebc[3]);
    return rc;
}//ucvext_icuucs2ebc1
//*************************************************************************
//*translate by icu converter
//* ucs to local
//* rc: 1:dbcs,-3:subchar was set                                  //~v66DR~
//*************************************************************************
//int ucvext_icuucs2local1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6hhR~
int ucvext_icuucs2local1(int Popt,ULPTR Pconverter,UWUCS/*ucs4*/Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6hhI~//~v6BjR~
{
//#ifdef W32                                                       //~v5n2R~
    ICUFUNC_FROMUCS   api;
	UErrorCode err=U_ZERO_ERROR;
    UConverter *converter;                                         //~v5mTM~
    USHORT wkucs[2];                                               //~v5mTM~
//#endif                                                           //~v5n2R~
	char wkmbs[8]; 	//mex ebc dbcs is 4 for chinese
    int rc=0,len;
    int opt;                                                       //~v66kR~
    int swsubch=0,rc2;                                             //~v66DR~
    int ucsctr;                                                    //~v6BjR~
//***************************
UTRACEP("ucvext_icuucs2local1 Popt=x%x,converter=%p\n",Popt,Pconverter);         //~v6hhR~//+v6BjR~
    if (!(Popt & EBC2ASC_LOCALCV))	//local converter
    {                                                              //~v66FI~
//  	return udbcschk_ucs2mb1(Popt,Pucs,Ppmbs,Ppoutlen);         //~v66FR~
        opt=0;                                                     //~v66FI~
//        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66FI~//~v66KR~
//            opt|=UDCU2M1O_BACKCHK; //trans back chk,ret 3 if rev chk err//~v66FI~//~v66KR~
    	rc=udbcschk_ucs2mb1(opt,Pucs,Ppmbs,Ppoutlen);              //~v66FI~
        return rc;                                                 //~v66FI~
    }                                                              //~v66FI~
//#ifdef W32                                                       //~v5n2R~
//if (IS_ICUMODE())                                                //~v5n1R~//~v66KR~
//if (IS_ICULOCALMODE())                                           //~v66KI~//~v6f3R~
  if (IS_ICULOCALMODE_OR_MBLOCAL()) //by ebcmap or -Yi             //~v6f3R~
  {                                                                //~v5n2I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
    api=Spfuncfromucs;  //ucnv_fromUChars;
    converter=(UConverter*)Pconverter;
                                                                   //~v6BjI~
    UCS4_TO_UTF16(Pucs,wkucs,&ucsctr);                             //~v6BjI~
                                                                   //~v6BjI~
    UTRACEP("%s:surrogate for ctr=%d,%x=(%x,%x)\n",UTT,Pucs,ucsctr,wkucs[0],wkucs[1]);//~v6BjR~
//  len=(*api)(converter,wkmbs,sizeof(wkmbs),wkucs,1,&err);        //~v6BjR~
//  len=(*api)(converter,wkmbs,sizeof(wkmbs),wkucs,ucsctr,&err);   //~v6BjI~//~v6BkR~
    len=(int)(*api)(converter,wkmbs,sizeof(wkmbs),wkucs,(UINT)ucsctr,&err);//~v6BkI~
	UTRACEP("ucvext_icuucs2local1 icuconverter=%p,len=%d,ucs=%x\n",converter,len,Pucs);//~v6hhI~
//  if (!U_FAILURE(err))                                           //~v66JR~
	if (!len || U_FAILURE(err))                                    //~v66JI~
	{
		UTRACEP("ucs2local1 ERR=%08x=%s\n",(UINT)err,ucvext_icuuerrname(err));
		rc=4;
	}
    else                                                           //~v66DI~
    {                                                              //~v66DI~
//currently no path because local converter is not ICU             //~v66NI~
        if (Popt & EBC2ASC_EXT_SETSUBCHRC)                         //~v66DI~
//      	swsubch=ucvext_icusubcharchk(UCVEXTISCO_U2L,Pucs,wkmbs,len);//~v66DR~//~v6hhR~
        	swsubch=ucvext_icusubcharchk_handle(UCVEXTISCO_U2L,Shandle,Pucs,wkmbs,len);//~v6hhR~
    }                                                              //~v66DI~
  }                                                                //~v5n2I~
//#else //W32                                                      //~v5n2R~
  else                                                             //~v5n2I~
  {                                                                //~v5n2I~
//	opt=0;                                                         //~v66kM~//~v66KR~
//	opt=(Popt & ~UCVEXTO_TOUTF8);   //pass subchrc request         //~v66KR~//~v69sR~
  	opt=Popt;   //pass subchrc request,TOUTF8==EBC2ASC_NEC         //~v69sI~
#ifdef UTF8UCS4                                                    //~v65cI~
//  if (ucvext_iconvucs2local1(Popt,Pconverter,(WUCS)Pucs,wkmbs,&len))//~v65cI~//~v66kR~
//  if (ucvext_iconvucs2local1(opt,Pconverter,(WUCS)Pucs,wkmbs,&len))//~v66kR~//~v66DR~
    rc2=ucvext_iconvucs2local1(opt,Pconverter,(WUCS)Pucs,wkmbs,&len);//~v66DI~
#else                                                              //~v65cI~
//  if (ucvext_iconvucs2local1(Popt,Pconverter,Pucs,wkmbs,&len))   //~v5mTR~//~v66kR~
    rc2=ucvext_iconvucs2local1(opt,Pconverter,Pucs,wkmbs,&len);    //~v66kI~//~v66DR~
#endif                                                             //~v65cI~
    if (rc2)                                                       //~v66DM~
	{                                                              //~v5mTI~
      if (rc2==UCVEXTRC_SUBCH)                                     //~v66DR~
        swsubch=rc2;                                               //~v66DI~
      else                                                         //~v66DI~
		rc=4;                                                      //~v5mTI~
	}                                                              //~v5mTI~
  }                                                                //~v5n2I~
//#endif                                                           //~v5n2R~
//  else                                                           //~v5n2R~
	if (!rc)                                                       //~v5n2I~
    {
    	if (len>1)
        {
        	rc=1;
//      	memcpy(Ppmbs,wkmbs,len);                               //~v6BkR~
        	memcpy(Ppmbs,wkmbs,(size_t)len);                       //~v6BkI~
        }
        else
        	*Ppmbs=wkmbs[0];
        *Ppoutlen=len;
    }
    if (swsubch)                                                   //~v66DI~
    	rc=swsubch;                                                //~v66DI~
    UTRACEP("ucvext_icuucs2local1 rc=%x,in=%x,outlen=%d,out=%02x%02x%02x%02x\n",rc,Pucs,len,wkmbs[0],wkmbs[1],wkmbs[2],wkmbs[3]);//~v6hhR~//~v6BjR~
    return rc;
}//ucvext_icuucs2local1
#ifdef AAA                                                         //~v6BjI~
//*************************************************************************//~v660I~
//*translate by icu converter  ucs->local without converter parameter//~v660I~
//*************************************************************************//~v660I~
int ucvext_icuucs2local1wocv(int Popt,WUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v660I~
{                                                                  //~v660I~
    int rc=0,opt0;                                                 //~v660R~
//  ULONG cvdbcs,cvsbcs,mapsbcs,mapcsbcs;                          //~v660I~//~v6hhR~
    ULPTR cvdbcs,cvsbcs,mapsbcs,mapcsbcs;                          //~v6hhI~
//***************************                                      //~v660I~
	ucvext_getparmconverter(Popt,0/*onverter*/,&cvdbcs,&cvsbcs,&mapsbcs,&mapcsbcs,&opt0);//~v660I~
	rc=ucvext_icuucs2local1(opt0,mapsbcs,(USHORT)Pucs,Ppmbs,Ppoutlen);//~v660R~
    UTRACEP("ucs2local1wocv rc=%x,cv=%lx,in=%04x,outlen=%d,out=%02x\n",rc,mapsbcs,Pucs,*Ppoutlen,*Ppmbs);//~v660R~//~v6b9R~
    return rc;                                                     //~v660I~
}//ucvext_icuucs2local1wocv                                        //~v660I~
#endif                                                             //~v6BjI~
//*************************************************************************
//*translate by icu converter
//* 1 ebc to mb
//* rc:1:errrep                                                    //~v66DI~
//*************************************************************************
//int ucvext_icuebc2mb1(int Popt,ULONG Pconverter,ULONG Psbcsmap,ULONG Psbcsmapc,UCHAR *Ppebc,int Pinplen,UCHAR *Pmbs,int *Ppoutlen,int Perrrep)//~v6hhR~
int ucvext_icuebc2mb1(int Popt,ULPTR Pconverter,ULPTR Psbcsmap,ULPTR Psbcsmapc,UCHAR *Ppebc,int Pinplen,UCHAR *Pmbs,int *Ppoutlen,int Perrrep)//~v6hhR~
{
    int rc=0,errrep,outlen=0;
//  USHORT ucs[2];                                                 //~v66CR~
//  WUCS   ucs[2];                                                 //~v66CI~//~v6BjR~
    UWUCS  ucs4;                                                   //~v6BjI~
    UCHAR *psbcsmap,*psbcsmapc,ch;
    int swsubch=0,rc2;                                             //~v66DI~
//***************************
    psbcsmap=(UCHAR*)Psbcsmap;
    psbcsmapc=(UCHAR*)Psbcsmapc;
    UTRACEP("ucvext_ebc2mb1 opt=%x ebc1=%02x,inplen=%d,Perrrep=%x,map=%p,mapc=%p\n",Popt,*Ppebc,Pinplen,Perrrep,psbcsmap,psbcsmapc);//~v6f7R~
    if ( (Popt & (EBC2ASC_SBCSMAPC))	//special code point
    &&  !(Popt & EBC2ASC_STAT_SO)  //source is sbcs
    &&   psbcsmapc                  //may be not by-directional
    &&   (ch=psbcsmapc[*Ppebc]))  //source is sbcs
    {
        outlen=1;
        *Pmbs=ch;
UTRACEP("ebc2mbs1 by SBCSMAPC/SBCSMAPA2A %02x->%02x\n",*Ppebc,*Pmbs);
    }
    else
    if ( (Popt & (EBC2ASC_SBCSMAP|EBC2ASC_SBCSMAPA2A))	//special code point
    &&  !(Popt & EBC2ASC_STAT_SO)  //source is sbcs
    &&   psbcsmap                  //may be not by-directional
    )
    {
        outlen=1;
        *Pmbs=*(psbcsmap+*Ppebc);
UTRACEP("ebc2mbs1 by SBCSMAP/SBCSMAPA2A %02x->%02x\n",*Ppebc,*Pmbs);
    }
    else
    {
//      rc=ucvext_icuebc2ucs1(Popt,Pconverter,Ppebc,Pinplen,ucs);  //~v5mYR~//~v6BjR~
        rc=ucvext_icuebc2ucs1(Popt,Pconverter,Ppebc,Pinplen,&ucs4);//~v6BjI~
        if (rc==UCVEXTRC_SUBCH)                                    //~v66DR~
        {                                                          //~v66DI~
        	swsubch=rc;                                            //~v66DI~
        	rc=0;                                                  //~v66DI~
        }                                                          //~v66DI~
        if (!rc)
        {                                                          //~v66DI~
//      	if (ucvext_icuucs2local1(Popt,Psbcsmap,ucs[0],Pmbs,&outlen)>1)//~v66DR~
//      	rc2=ucvext_icuucs2local1(Popt,Psbcsmap,ucs[0],Pmbs,&outlen);//~v66DI~//~v6BjR~
        	rc2=ucvext_icuucs2local1(Popt,Psbcsmap,ucs4,Pmbs,&outlen);//~v6BjR~
            if (rc2>1)                                             //~v66DI~
            	rc=4;
            else                                                   //~v66DI~
            	if (rc2==UCVEXTRC_SUBCH)                           //~v66DR~
                	swsubch=rc2;                                   //~v66DI~
        }                                                          //~v66DI~
        if (!rc)
        {
         	if (*Pmbs==0x0a && outlen==1)
            {
				if (Sextflag & SEXTF_REPLF)
                	rc=4;		//output subchar
            }
            else
         	if (outlen>1 && !(Popt & EBC2ASC_STAT_SO)) //sbcs output is multibyte
            {
				if (Sextflag & SEXTF_NOS2D)
                	rc=4;		//output subchar
                else                                               //~v66FI~
         		if (!(Popt & EBC2ASC_DBCS)) //-SBCS option         //~v66FI~
                {                                                  //~v66WI~
				  if (!(Sextflag & SEXTF_DBCSSTART))   //dbcs start byte saved for local converter//~v66WI~
                	rc=4;		//output subchar                   //~v66FI~
                }                                                  //~v66WI~
            }
            else                                                   //~v66xI~
            if (*Ppebc<CHAR_EBC_SPACE && !(Popt & EBC2ASC_CTL)) //ANK option//~v66xI~
                rc=4;		//output subchar                       //~v66xI~
            if (swsubch)                                           //~v66DI~
            {                                                      //~v69cI~
              if (!Shandle)	//if handle>0,no cfg subchar will be set//~v69cI~
	            if ((Popt & EBC2ASC_STAT_SO) ? (Ssubchardbcs!=UDBCSCHK_SUBCHAR_DBCS) : (Ssubcharsbcs!=UDBCSCHK_SUBCHAR_SBCS))//~v66CR~
    	        	rc=4;	//replace by cfg parm sub char         //~v66CR~
            }                                                      //~v69cI~
        }
        if (rc)
        {
            if (Popt & EBC2ASC_STAT_SO)
            {
        		if (errrep=(Perrrep>>8),errrep)	//by locale code
                {
		            *Pmbs=(UCHAR)(errrep>>8),*(Pmbs+1)=(UCHAR)(errrep&0xff);
                    outlen=2;
                }
                else
                {
//              	UTRACEP("Subchar dbcs=%x,sbcs=%x\n",Ssubchardbcs,Ssubcharsbcs);//~v5n3I~//~v66TR~//~v69cR~
//                    if (ucvext_icuucs2local1(Popt,Psbcsmap,Ssubchardbcs,Pmbs,&outlen)>1)//~v66CR~
//                    {                                            //~v66CR~
//                        *Pmbs=*Ppebc,*(Pmbs+1)=*(Ppebc+1);       //~v66CR~
//                        outlen=2;                                //~v66CR~
//                    }                                            //~v66CR~
                    if (!swsubch)	//replaced by converter native subchar//~v66CI~
                    {                                              //~v66CI~
                        if (!(outlen=Ssubcharlocaldbcslen))        //~v66TI~
                        	outlen=2;                              //~v66TI~
//                  	memcpy(Pmbs,Ssubcharlocaldbcs,outlen);     //~v66TR~//~v6BkR~
                    	memcpy(Pmbs,Ssubcharlocaldbcs,(size_t)outlen);//~v6BkI~
                    }                                              //~v66CI~
                }
                UTRACEP("ERRREP DBCS ebc2mb ebc=%02x%02x, mb=%02x%02x\n",*Ppebc,*(Ppebc+1),*Pmbs,*(Pmbs+1));
            }
            else    //sbcs
            {
        		if (errrep=(Perrrep&0xff),errrep)	//by locale code
                {
		            *Pmbs=(UCHAR)errrep;
                    outlen=1;
                }
                else
                {
//                    if (ucvext_icuucs2local1(Popt,Psbcsmap,Ssubcharsbcs,Pmbs,&outlen)>1)//~v66CR~
//                    {                                            //~v66CR~
//                        *Pmbs=*Ppebc;                            //~v66CR~
//                        outlen=1;                                //~v66CR~
//                    }                                            //~v66CR~
                  	if (!swsubch)	//replaced by converter native subchar//~v66CI~
                    {                                              //~v66CI~
                        *Pmbs=Ssubcharlocalsbcs;                   //~v66CR~
                        outlen=1;                                  //~v66CI~
                  	}//!native subchar                             //~v66CR~
                }
                UTRACEP("ERRREP SBCS ebc2mb ebc=%02x, mb=%02x\n",*Ppebc,*Pmbs);
            }//sbcs
            rc=EBC2ASC_RC_ERRREP;// 0x01
        }//rc
    }
	*Ppoutlen=outlen;
    if (!rc && swsubch)                                            //~v66DI~
    	rc=EBC2ASC_RC_ERRREP;// 0x01                               //~v66DR~
    UTRACEP("ebc2mb1 rc=%x,in=%02x%02x,outlen=%d,out=%02x%02x\n",rc,*Ppebc,(Pinplen>1?*(Ppebc+1):0),outlen,Pmbs[0],Pmbs[1]);//~v5n1I~
    UTRACED("ebc2mb1 out",Pmbs,outlen);                            //~v66WI~
    return rc;
}//ucvext_icuebc2mb1
//*************************************************************************
//*translate by icu converter
//* 1 mb to ebc
//* rc:-2:hankana,1 errrep                                         //~v66DR~
//*************************************************************************
//int ucvext_icumb2ebc1(int Popt,ULONG Pconverter,ULONG Psbcsmap,ULONG Psbcsmapc,UCHAR *Ppmbs,int Pinplen,UCHAR *Ppebc,int *Ppchklen,int *Ppoutlen,int Perrrep)//~v6hhR~
int ucvext_icumb2ebc1(int Popt,ULPTR Pconverter,ULPTR Psbcsmap,ULPTR Psbcsmapc,UCHAR *Ppmbs,int Pinplen,UCHAR *Ppebc,int *Ppchklen,int *Ppoutlen,int Perrrep)//~v6hhR~
{
    int rc=0,rc2,errrep,outlen=0,chklen;
    UCHAR *psbcsmap,*psbcsmapc,ch;
#ifdef UTF8UCS4                                                    //~v65cI~
    WUCS   ucs=0;                                                    //~v65cI~//~v6h6R~
#else                                                              //~v65cI~
//  USHORT ucs=0;                                                  //~v6h6R~//~v6BjR~
    UWUCS ucs=0;                                                   //~v6BjI~
#endif                                                             //~v65cI~
 	int rc3,swhankana=0;                                           //~v66AR~
    int swsubch=0;                                                 //~v66DI~
//***************************
    psbcsmap=(UCHAR*)Psbcsmap;
    psbcsmapc=(UCHAR*)Psbcsmapc;
    UTRACEP("ucvext_icumb2ebc1 opt=%x,converetr=%p,inplen=%d,errrep=%x,sbcsmap=%p,sbcsmapc=%p\n",Pconverter,Popt,Pinplen,Perrrep,psbcsmap,psbcsmapc);//~v6bjR~
    if ( (Popt & (EBC2ASC_SBCSMAPC))	//sbcs by user mapping
    &&  !(Popt & EBC2ASC_STAT_SO)  //source is sbcs
    &&   psbcsmapc                  //may be not by-directional
    &&   (ch=psbcsmapc[*Ppmbs]))  //source is sbcs
    {
        outlen=chklen=1;
        *Ppebc=ch;
UTRACEP("mb2ebc1 by SBCSMAPC/A2A %02x->%02x\n",*Ppmbs,*Ppebc);
    }
    else
    if ( (Popt & (EBC2ASC_SBCSMAP|EBC2ASC_SBCSMAPA2A))	//sbcs by user mapping
    &&  !(Popt & EBC2ASC_STAT_SO)
    &&   psbcsmap                  //may be not by-directional
	)  //source is sbcs
    {
        outlen=chklen=1;
        *Ppebc=*(psbcsmap+*Ppmbs);
UTRACEP("mb2ebc1 by SBCSMAP/ABCSMAPA2A %02x->%02x\n",*Ppmbs,*Ppebc);
    }
    else
    {
      if (*Ppmbs<' ' && !(Popt & EBC2ASC_CTL)) //ANK option        //~v66xR~
      {                                                            //~v66xI~
        chklen=1;                                                  //~v66xI~
       	rc2=4;		//output subchar                               //~v66xI~
      }                                                            //~v66xI~
      else                                                         //~v66xI~
        rc2=ucvext_iculocal2ucs1(Popt,Psbcsmap,Ppmbs,Pinplen,&chklen,&ucs);
        if (rc2>1)  //1:dbcs
            rc=4;
        else
        if (rc2==UCVEXTRC_SUBCH)                                   //~v66DI~
        {                                                          //~v66DI~
        	swsubch=rc;                                            //~v66DI~
        	rc=0;                                                  //~v66DI~
        }                                                          //~v66DI~
        else                                                       //~v66DI~
        if (rc2)                                                   //~v66TI~
            rc=4;                                                  //~v66TI~
        else                                                       //~v66TI~
            rc=0;
        if (!rc)
        {
//          if (ucvext_icuucs2ebc1(Popt,Pconverter,ucs,Ppebc,&outlen)>1)//~v66AR~
            if ((rc3=ucvext_icuucs2ebc1(Popt,Pconverter,ucs,Ppebc,&outlen))>1)//~v66AR~
                rc=4;
            else                                                   //~v66AI~
            	if (rc3==UCVEXTRC_HANKANA)                         //~v66AR~
                	swhankana=1;                                   //~v66AI~
                else                                               //~v66DI~
        		if (rc3==UCVEXTRC_SUBCH)                           //~v66DI~
		        	swsubch=rc3;                                   //~v66DI~
	        if (swsubch)                                           //~v66CR~
            {                                                      //~v69cI~
              if (!Shandle)	//if handle>0,no cfg subchar will be set//~v69cI~
    	        if ((Popt & EBC2ASC_STAT_SO) ? (Ssubchardbcs!=UDBCSCHK_SUBCHAR_DBCS) : (Ssubcharsbcs!=UDBCSCHK_SUBCHAR_SBCS))//~v66CR~
        	    	rc=4;	//replace by cfg parm sub char         //~v66CR~
            }                                                      //~v69cI~
        }
        if (rc)
        {
            if (Popt & EBC2ASC_STAT_SO)
            {
        		if (errrep=(Perrrep>>8),errrep)	//by locale code
                {
		            *Ppebc=(UCHAR)(errrep>>8),*(Ppebc+1)=(UCHAR)(errrep&0xff);
                    outlen=2;
                }
                else
                {
//              	UTRACEP("Subchardbcs=%x,Subcharsbcs=%x\n",Ssubchardbcs,Ssubcharsbcs);//~v66AR~//~v69cR~
//                    if (ucvext_icuucs2ebc1(Popt,Pconverter,Ssubchardbcs,Ppebc,&outlen)>1)//~v66CR~
//                    {                                            //~v66CR~
//                        *Ppebc=*Ppmbs,*(Ppebc+1)=*(Ppmbs+1);     //~v66CR~
//                        outlen=2;                                //~v66CR~
//                    }                                            //~v66CR~
                  	if (!swsubch)                                  //~v66CI~
                    {                                              //~v66CI~
//                      memcpy(Ppebc,Ssubcharebcdbcs,Ssubcharebcdbcslen);//~v66CR~//~v69cR~
//                      outlen=Ssubcharebcdbcslen;                 //~v66CR~//~v69cR~
                        outlen=UCVEBCH_subcharebcdbcslen(Shandle); //~v69cI~
                        memcpy(Ppebc,UCVEBCH_subcharebcdbcs(Shandle),(UINT)outlen);//~v69cI~
                    }                                              //~v66CI~
                                                                   //~v66CI~
                }
                UTRACEP("ERRREP DBCS mb2ebc ebc=%02x%02x, mb=%02x%02x\n",*Ppebc,*(Ppebc+1),*Ppmbs,*(Ppmbs+1));
            }
            else    //sbcs
            {
        		if (errrep=(Perrrep&0xff),errrep)	//by locale code
                {
		            *Ppebc=(UCHAR)errrep;
                    outlen=1;
                }
                else
                {
//                    if (ucvext_icuucs2ebc1(Popt,Pconverter,Ssubcharsbcs,Ppebc,&outlen)>1)//~v66CR~
//                    {                                            //~v66CR~
//                        *Ppebc=*Ppmbs;                           //~v66CR~
//                        outlen=1;                                //~v66CR~
//                    }                                            //~v66CR~
                  	if (!swsubch)                                  //~v66CI~
                    {                                              //~v66CI~
//                      *Ppebc=Ssubcharebcsbcs;                    //~v66CR~//~v69cR~
                        *Ppebc=UCVEBCH_subcharebcsbcs(Shandle);    //~v69cI~
                        outlen=1;                                  //~v66CI~
                    }                                              //~v66CI~
                }
                UTRACEP("ERRREP SBCS mb2ebc ebc=%02x, mb=%02x\n",*Ppebc,*Ppmbs);
            }//sbcs
            rc=EBC2ASC_RC_ERRREP;// 0x01
        }//rc
    }//not by map
	*Ppoutlen=outlen;
	*Ppchklen=chklen;
  if (!rc)                                                         //~v66DI~
  {                                                                //~v66DI~
    if (swhankana)                                                 //~v66AI~
    	rc=UCVEXTRC_HANKANA;	//-2                               //~v66AR~
    else                                                           //~v66DI~
    if (swsubch)                                                   //~v66DI~
        rc=EBC2ASC_RC_ERRREP;// 0x01                               //~v66DI~
  }                                                                //~v66DI~
    UTRACEP("mb2ebc1 rc=%x,chklen=%d,outlen=%d\n",rc,chklen,outlen);
    UTRACED("chked",Ppmbs,chklen);
    UTRACED("out  ",Ppebc,outlen);
    return rc;
}//ucvext_icumb2ebc1
//*************************************************************************//~v69cR~
//*translate by icu converter                                      //~v69cR~
//* ebc string to mb string                                        //~v69cR~
//*************************************************************************//~v69cR~
int ucvext_icuebc2mbs_handle(int Popt,int Phandle,UCHAR *Ppebc,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pmbs,int *Ppoutlen,int Perrrep)//~v69cR~
{                                                                  //~v69cR~
	int rc;                                                        //~v69cR~
//********************                                             //~v69cR~
    Shandle=Phandle;                                               //~v69cR~
	rc=ucvext_icuebc2mbs(Popt,0/*converters*/,Ppebc,Ppdbcs,Pinplen,Pmbs,Ppoutlen,Perrrep);//~v69cR~
    Shandle=0;                                                     //~v69cR~
    return rc;                                                     //~v69cR~
}//ucvext_icuebc2mbs_handle                                        //~v69cR~
//*************************************************************************
//*translate by icu converter
//* ebc string to mb string
//*************************************************************************
//int ucvext_icuebc2mbs(int Popt,ULONG *Pconverters,UCHAR *Ppebc,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pmbs,int *Ppoutlen,int Perrrep)//~v5mTR~//~v6hhR~
int ucvext_icuebc2mbs(int Popt,ULPTR *Pconverters,UCHAR *Ppebc,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pmbs,int *Ppoutlen,int Perrrep)//~v6hhI~
{
    int rc=0,len,opt=0,dbcssw=0,outlen=0,opt0,reslen;
    int socontsw;                                                  //~v66iI~
    UCHAR *pci,*pco,*pce;
//  ULONG cvdbcs,cvsbcs,cv2ucs,mapsbcs,mapcsbcs;                   //~v6hhR~
    ULPTR cvdbcs,cvsbcs,cv2ucs,mapsbcs,mapcsbcs;                   //~v6hhI~
//***************************
    socontsw=(Popt & EBC2ASC_SOCONT);                              //~v66iR~
  if (Shandle)                                                     //~v69cR~
	ucvebc4_getparmconverter(Popt,Shandle,&cvdbcs,&cvsbcs,&mapsbcs,&mapcsbcs,&opt0);//~v69cR~
  else                                                             //~v69cR~
	ucvext_getparmconverter(Popt,Pconverters,&cvdbcs,&cvsbcs,&mapsbcs,&mapcsbcs,&opt0);
UTRACEP("input ebc=%p, inplen=%d, errrep=%x\n",Ppebc,Pinplen,Perrrep);//~v66KR~
  if (socontsw)                                                    //~v66NI~
    cv2ucs=cvdbcs;      //start by DBCS                            //~v66NI~
  else                                                             //~v66NI~
    cv2ucs=cvsbcs;      //assume start by SBCS
    opt=opt0;
	for (pci=Ppebc,pce=pci+Pinplen,pco=Pmbs;pci<pce;pci++)
    {
UTRACEP("ucvext_icuebc2mbs byte=%02x\n",*pci);                     //~v6f7R~
    	if (opt0 & EBC2ASC_DBCS)
        {
            if (*pci==CHAR_SO)
            {
                opt|=EBC2ASC_STAT_SO;
                cv2ucs=cvdbcs;
                dbcssw=1;
    	     if (opt0 & EBC2ASC_SOSI) //rep so/si by spce(default) //~v5mVI~
                *pco++=' ';      //rep SO by space
                continue;
            }
            else                                                   //~v66iI~
            if (socontsw)                                          //~v66iI~
                dbcssw=1;                                          //~v66iI~
            if (*pci==CHAR_SI)
            {
            	socontsw=0;                                        //~v66iI~
                opt&=~EBC2ASC_STAT_SO;
                cv2ucs=cvsbcs;
                dbcssw=0;
    	     if (opt0 & EBC2ASC_SOSI) //rep so/si by spce(default) //~v5mVI~
                *pco++=' ';      //rep SI by space
                continue;
            }
        }
//		reslen=(int)((ULONG)pce-(ULONG)pci);                       //~v6hhR~
		reslen=(int)((ULPTR)pce-(ULPTR)pci);                       //~v6hhI~
UTRACEP("ebc2mbs dbcssw=%d,reslen=%d\n",dbcssw,reslen);
        if (reslen==1)
        {
            if (opt & EBC2ASC_STAT_SO)
            {
        		opt&=~EBC2ASC_STAT_SO;
	            rc|=EBC2ASC_RC_HALFBYTE;
            }
            dbcssw=0;
        }
		rc|=ucvext_icuebc2mb1(opt,cv2ucs,mapsbcs,mapcsbcs,pci,reslen,pco,&len,Perrrep);
        pco+=len;
        pci+=dbcssw;
    }
//  outlen=(int)((ULONG)pco-(ULONG)Pmbs);                          //~v6hhR~
    outlen=(int)((ULPTR)pco-(ULPTR)Pmbs);                          //~v6hhI~
    if (Ppoutlen)
        *Ppoutlen=outlen;
UTRACEP("ebc2mbs rc=%d\n",rc);
UTRACED("ucvext_icuebc2mbs output mbs",Pmbs,outlen);               //~v6f7R~
    return rc;
}//ucvext_icuebc2mbs                                               //~v66nR~
//****************************************************************
//*ebc<--mbcs  string conv
//*parm 3:Pout:output area;if 0 no output set(return output length)
//*ret :0x01:err rep occured,0x02:set SI failed,0x04:last is 1st byte of dbcs
//****************************************************************
//int ucvext_icumb2ebcdbcs(int Popt,ULONG Pconverter,ULONG Plocalconverter,UCHAR *Pinp,UCHAR *Pout,//~v6x5R~
int ucvext_icumb2ebcdbcs(int Popt,ULPTR Pconverter,ULPTR Plocalconverter,UCHAR *Pinp,UCHAR *Pout,//~v6x5I~
			int Pinplen,int *Pchklen,int *Poutlen,int *Ppexplen,int Prepchar)
{
	char *pi,*po,*pie,*poo,*pos;                                   //~v5mWR~
    int rc=0,mbdbcs,dbcssw=0,len,chklen,outlen,opt;
    int reslen,explen=0;
    int lrecl,lrecl0,fixsw,rlen,setsoopt;                          //~v5mWR~
    int rc2,swhankana=0,ebclen;                                    //~v66AR~
    char wkebc[4];                                                 //~v66AI~
//**************************
	lrecl=*Poutlen&0xffff;    //residual len when DBCS start       //~v5mWI~
//  lrecl0=*Poutlen>>16;      //lrecl                              //~v5mWI~//~v66BR~
//  lrecl0=((UINT)*Poutlen)>>16;      //lrecl                      //~v66BI~//~v6BkR~
    lrecl0=(int)(((UINT)*Poutlen)>>16);      //lrecl               //~v6BkI~
UTRACEP("icumb2dbcs len=%d, inp=%02x,lrecl=%d,lrecl0=%d,errrep=%x\n",Pinplen,*Pinp,lrecl,lrecl0,Prepchar);//~v5mWR~
	fixsw=(Popt & EBC2ASC_FIXEDLRECL) && (lrecl0!=0);              //~v5mWR~
	pi=Pinp;
	po=Pout;
    pos=po;   //record start pos                                   //~v5mWI~
    pie=pi+Pinplen;	//end addr
    if ((Popt & EBC2ASC_SOCONT)
    &&  (Popt & EBC2ASC_BUFTOP)) //dbcs continued from prev line
    	dbcssw=1;	//set SI
    for (;pi<pie;)
    {
    	mbdbcs=(int)*pi;
    UTRACEP("asc2ebcdbcs pi=%pmpie=%p,dbcssw=%d,dbcs=%x%x\n",pi,pie,dbcssw,mbdbcs,*(pi+1));//~v5mWR~
//      if (!SJIS1(mbdbcs))	//dbcs 1st byte
    	if (!UCVEXT_ISDBCS1ST(Popt,((UCHAR)mbdbcs))) //dbcs 1st byte
        	break;
        if (pi+1==pie)
        {
            rc|=EBC2ASC_RC_HALFBYTE;
        	break;
        }
//      pi++;
//      mbdbcs=(mbdbcs<<8)+(int)*pi++;
//      ebc=ucvext2_s2e(Popt,(USHORT)mbdbcs);
//		reslen=(int)((ULONG)pie-(ULONG)pi);                        //~v66AI~//~v6hhR~
  		reslen=(int)((ULPTR)pie-(ULPTR)pi);                        //~v6hhR~
        opt=Popt|EBC2ASC_STAT_SO;                                  //~v66AI~
		rc2=ucvext_icumb2ebc1(opt,Pconverter,Plocalconverter/*map*/,0/*mapc*/,pi,reslen,wkebc,&chklen,&ebclen,Prepchar);//~v66AR~
        if (rc2==UCVEXTRC_HANKANA)                                 //~v66AR~
        {                                                          //~v66AI~
        	swhankana=1;                                           //~v66AI~
        	pi+=chklen;                                            //~v66AI~
        	break;                                                 //~v66AI~
        }                                                          //~v66AI~
        if (rc2==EBC2ASC_RC_ERRREP)                                //~v683I~
        	rc|=EBC2ASC_RC_ERRREP;                                 //~v683I~
		poo=po;		//pos before insert 1 ebc                      //~v5mWR~
        if (!dbcssw)
        {
        	dbcssw=1;
            setsoopt=Popt;                                         //~v5mWI~
            if (po==pos && fixsw && lrecl==lrecl0)                 //~v5mWI~
	            setsoopt|=EBC2ASC_BUFTOP;	//insert SO            //~v5mWI~
            rc|=ucvebc2_setso(setsoopt,pi,po,Pinplen,&outlen);     //~v5mWR~
            po+=outlen;
            if (!outlen)                                           //~v5mWR~
                poo--;  //start of SO(replace previous space)      //~v5mWM~
//          else                                                   //~v5mWI~
//          	explen++;                                          //~v5mWR~
    UTRACEP("asc2ebcdbcs setso outlen=%d\n",outlen);               //~v5mWI~
        }//1st dbcs
//		reslen=(int)((ULONG)pie-(ULONG)pi);                        //~v66AR~
//      opt=Popt|EBC2ASC_STAT_SO;                                  //~v66AR~
//  	ucvext_icumb2ebc1(opt,Pconverter,Plocalconverter/*map*/,0/*mapc*/,pi,reslen,po,&chklen,&outlen,Prepchar);//~v66AR~
        outlen=ebclen;                                             //~v66AI~
        memcpy(po,wkebc,(UINT)outlen);                             //~v66AI~
        pi+=chklen;
        po+=outlen;
        if (fixsw) //lrecl specified                               //~v5mWR~
        {                                                          //~v5mWI~
//        	rlen=lrecl-((ULONG)po-(ULONG)pos);                     //~v5mWI~//~v6hhR~
//      	rlen=lrecl-((ULPTR)po-(ULPTR)pos);                     //~v6hhI~//~v6BkR~
        	rlen=lrecl-PTRDIFF(po,pos);                            //~v6BkI~
    UTRACEP("asc2ebcdbcs pos=%p,poo=%p:%02x,lrecl=%d,rlen=%d\n",pos,poo,*poo,lrecl,rlen);//~v5mWR~
            if (rlen<1)	//overflow or no space to inser SI         //~v5mWI~
            {                                                      //~v5mWI~
//	        	rlen=(int)((ULONG)po-(ULONG)poo); 	//currect output len//~v5mWI~//~v6hhR~
	        	rlen=(int)((ULPTR)po-(ULPTR)poo); 	//currect output len//~v6hhI~
                po=pos+lrecl;                                      //~v5mWI~
                if (*poo!=CHAR_SO)                                 //~v5mWI~
                {                                                  //~v5mYI~
                	memmove(po+1,poo,(UINT)rlen);                  //~v5mYR~
                	*po++=CHAR_SO;                                 //~v5mYM~
                }                                                  //~v5mYI~
                else                                               //~v5mYI~
    	            memmove(po,poo,(UINT)rlen);                    //~v5mYI~
                po+=rlen;                                          //~v5mWI~
//	        	rlen=lrecl-((ULONG)poo-(ULONG)pos);                //~v5mWI~//~v6hhR~
//          	rlen=lrecl-((ULPTR)poo-(ULPTR)pos);                //~v6hhI~//~v6BkR~
            	rlen=lrecl-PTRDIFF(poo,pos);                       //~v6BkI~
                if (*poo==CHAR_SO)                                 //~v5mWI~
                	memset(poo,CHAR_EBC_SPACE,(UINT)rlen);	//fill space//~v5mWI~
                else                                               //~v5mWI~
                {	                                               //~v5mWI~
                	*poo++=CHAR_SI;                                //~v5mYR~
                    rlen--;                                        //~v5mWI~
                    if (rlen>0)                                    //~v5mWI~
	                	memset(poo,CHAR_EBC_SPACE,(UINT)rlen);	//fill space//~v5mWI~
                }                                                  //~v5mWI~
UTRACED("after shift",pos,PTRDIFF(po,pos));               //~v5mWI~//~v6hhR~//~v6BkR~
                pos+=lrecl;                                        //~v5mWI~
            	lrecl=lrecl0;	//new split line by lrecl          //~v5mWI~
            }                                                      //~v5mWI~
        }                                                          //~v5mWI~
    }
    if (dbcssw)
    {
    	rc|=EBC2ASC_RC_DBCSFOUND; //dbcs found
      	if (Popt & (EBC2ASC_SOSI | EBC2ASC_SOSIOS))//SOSI SET OPTION
      	{
       		if ((Popt & EBC2ASC_LNCONT)
	   		&&  (pi==pie || rc & EBC2ASC_RC_HALFBYTE))	//line continued to next
       			rc|=EBC2ASC_RC_SIPEND;
       		else	//line not continued to next line
            {
//				len=(int)((ULONG)pie-(ULONG)pi);                   //~v6hhR~
				len=(int)((ULPTR)pie-(ULPTR)pi);                   //~v6hhI~
				rc|=ucvebc2_setsi(Popt,pi,po,len,&chklen,&outlen);
    UTRACEP("mb2ebcdbcs setsi chklen=%d,outlen=%d,rc=%x,*pi=%02x\n",chklen,outlen,rc,*pi);//~v5mWR~
                pi+=chklen;
                po+=outlen;
//              if (!chklen) //SI inserted                         //~v5mWR~
//  	        	explen++;                                      //~v5mWR~
            }
      	}//SOSI SET OPTION
    }
    if (swhankana)                                                 //~v66AI~
    {                                                              //~v66AI~
    	rc|=EBC2ASC_RC_HANKANA; //dbcs found                       //~v66AI~
        *po++=*wkebc;   //output 1 byte;                           //~v66AI~
    }                                                              //~v66AI~
//  *Pchklen=(int)((ULONG)pi-(ULONG)Pinp);                         //~v6hhR~
    *Pchklen=(int)((ULPTR)pi-(ULPTR)Pinp);                         //~v6hhI~
//  *Poutlen=(int)((ULONG)po-(ULONG)Pout);                         //~v6hhR~
    *Poutlen=(int)((ULPTR)po-(ULPTR)Pout);                         //~v6hhI~
    if ((explen=*Poutlen-*Pchklen)<0)                              //~v5mWI~
    	explen=0;                                                  //~v5mWI~
    if (Ppexplen)
	    *Ppexplen=explen;
UTRACEP("RET mb2ebcdbcs rc=%d,explen=%d\n",rc,explen);             //~v5mWR~
    return rc;
}//ucvext_icumb2ebcdbcs
//**************************************************************** //~v69cR~
//*ebc<--mbc string by ICU                                         //~v69cR~
//*ret :rc:UDBCSCHK_RC_DBCSFOUND|DBCSCHK_RC_DBCSSPLIT|UDBCSCHK_RC_DBCSERR//~v69cR~
//**************************************************************** //~v69cR~
int ucvext_icumb2ebcs_handle(int Popt,int Phandle,UCHAR *Pibuff,UCHAR *Ppdbcs,int Plen,//~v69cR~
					UCHAR *Pobuff,int *Ppoutlen,int Prepchar)      //~v69cR~
{                                                                  //~v69cR~
	int rc;                                                        //~v69cR~
//********************                                             //~v69cR~
    Shandle=Phandle;                                               //~v69cR~
	rc=ucvext_icumb2ebcs(Popt,0/*converters*/,Pibuff,Ppdbcs,Plen,Pobuff,Ppoutlen,Prepchar);//~v69cR~
    Shandle=0;                                                     //~v69cR~
    return rc;                                                     //~v69cR~
}//ucvext_icumb2ebcs_handle                                        //~v69cR~
//****************************************************************
//*ebc<--mbc string by ICU
//*ret :rc:UDBCSCHK_RC_DBCSFOUND|DBCSCHK_RC_DBCSSPLIT|UDBCSCHK_RC_DBCSERR
//****************************************************************
//int ucvext_icumb2ebcs(int Popt,ULONG *Pconverters,UCHAR *Pibuff,UCHAR *Ppdbcs,int Plen,//~v6hhR~
int ucvext_icumb2ebcs(int Popt,ULPTR *Pconverters,UCHAR *Pibuff,UCHAR *Ppdbcs,int Plen,//~v6hhI~
					UCHAR *Pobuff,int *Ppoutlen,int Prepchar)
{
	UCHAR *pci,*pco,*pce;
//  int crlfsw;                                                    //~v6b9R~
    UCHAR chi;
    UCHAR *pdbcs,tabid;
//  ULONG cvsbcs,cvdbcs,mapsbcs,mapcsbcs;                          //~v6hhR~
    ULPTR cvsbcs,cvdbcs,mapsbcs,mapcsbcs;                          //~v6hhI~
//  ULONG cvu2b;                                                   //~v6x5R~
    ULPTR cvu2b;                                                   //~v6x5I~
    int   skiplen=0;
    int reslen,dbcschklen,dbcsoutlen,outlen;
    int sbcschklen,sbcsoutlen;
    int topsw=EBC2ASC_BUFTOP;
    int rc=0,rc2,opt0;
    int explen=0,explen1;
    int lrecl;                                                     //~v5mWR~
//  int swhankana=0;                                               //~v66AI~//~v6b9R~
    int swlocaldbcs;                                               //~v66WI~
//********************
    lrecl=*Ppoutlen;   //input LRECL when EBC2ASC_FIXEDLRECL is on //~v5mWI~
UTRACEP("icumb2ebcs opt=%x,inplen=%d,lrecl=%d,repch=%x\n",Popt,Plen,lrecl,Prepchar);//~v66BI~
UTRACED("icumb2ebcs input",Pibuff,Plen);
  if (Shandle)                                                     //~v69cR~
	ucvebc4_getparmconverter(Popt,Shandle,&cvdbcs,&cvsbcs,&mapsbcs,&mapcsbcs,&opt0);//~v69cR~
  else                                                             //~v69cR~
	ucvext_getparmconverter(Popt,Pconverters,&cvdbcs,&cvsbcs,&mapsbcs,&mapcsbcs,&opt0);
    if (opt0 & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert
    	opt0|=EBC2ASC_SOSIOS;        //override boundary space if avail
//  pcvt=Stbla2e;
//  crlfsw=opt0 & EBC2ASC_CRLF;                                    //~v6b9R~
//  ctlsw=Popt & EBC2ASC_CTL;
    pdbcs=Ppdbcs;
    swlocaldbcs=(opt0 & EBC2ASC_DBCS)||(Sextflag & SEXTF_DBCSSTART);   //ebc converter dosenot support dbcs but local dbcs will be translated to ebc sbcs(hankan ,gb4 4 byte etc)//~v66WI~
	if (cvdbcs)                                                    //~v66WI~
    	cvu2b=cvdbcs;                                              //~v66WI~
    else                                                           //~v66WI~
    	cvu2b=cvsbcs;	//localdbcs ebc sbcs case                  //~v66WI~
    for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;topsw=0)
    {
    	chi=*pci;
//      reslen=(int)((ULONG)pce-(ULONG)pci);                       //~v6hhR~
        reslen=(int)((ULPTR)pce-(ULPTR)pci);                       //~v6hhI~
//      if (opt0 & EBC2ASC_DBCS)  //dbcs conv                      //~v66WR~
        if (swlocaldbcs)  //dbcs conv                              //~v66WI~
        if ((topsw && opt0 & EBC2ASC_SOCONT)	//top of continued line of SO pending
//  	||  SJIS1(chi))	//dbcs 1st byte
    	||  UCVEXT_ISDBCS1ST(opt0,chi) //dbcs 1st byte
    	)
        {
			if (lrecl)                                             //~v5mWM~
//	            dbcsoutlen=lrecl-((ULONG)pco-(ULONG)Pobuff)%lrecl; //optionaly insert SI at EOL by LRECL//~v5mWM~//~v6hhR~
//              dbcsoutlen=lrecl-((ULPTR)pco-(ULPTR)Pobuff)%lrecl; //optionaly insert SI at EOL by LRECL//~v6hhI~//~v6BkR~
                dbcsoutlen=lrecl-PTRDIFF(pco,Pobuff)%lrecl; //optionaly insert SI at EOL by LRECL//~v6BkI~
            else                                                   //~v5mWM~
	            dbcsoutlen=0;                                      //~v5mWM~
//          dbcsoutlen|=((UINT)lrecl<<16);                         //~v5mWR~//~v6BkR~
            dbcsoutlen|=(int)((UINT)lrecl<<16);                    //~v6BkI~
            rc2=
//          ucvext2_strs2e(Popt|topsw,pci,pco,reslen,&dbcschklen,&dbcsoutlen,dbcsrepchar);
//          ucvext_icumb2ebcdbcs(opt0|topsw,cvdbcs,mapsbcs/*local converter*/,pci,pco,reslen,&dbcschklen,&dbcsoutlen,&explen1,Prepchar);//~v66WR~
            ucvext_icumb2ebcdbcs(opt0|topsw,cvu2b,mapsbcs/*local converter*/,pci,pco,reslen,&dbcschklen,&dbcsoutlen,&explen1,Prepchar);//~v66WI~
//          swhankana=rc2 & EBC2ASC_RC_HANKANA;    //last terminateed by hankana//~v66AR~//~v6b9R~
            pci+=dbcschklen;
	        if (Ppdbcs)
            	pdbcs+=dbcschklen;
            pco+=dbcsoutlen;
//          explen+=(dbcsoutlen-dbcschklen);	//expand len by SO/SI insert
			explen+=explen1;
            UTRACEP("mb2ebcs explen1=%d,explen=%d\n",explen1,explen);//~v5mPI~
            rc|=rc2;
	   		if (opt0 & EBC2ASC_LNCONT		//cont line  end by dbcs split
	   		&&  rc2 & EBC2ASC_RC_HALFBYTE)
            	break;
          if (dbcschklen) //dbcs detected
            continue;
        }
        if (Ppdbcs)
        {
	    	tabid=*pdbcs;
            if (tabid==UDBCSCHK_TAB)
            	chi=UDBCSCHK_TAB;
            else
            	if (chi==' ' && tabid!=0)	//tab cont
                {
				    if (opt0 & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert
                    	if (explen)
                        	explen--;
                	skiplen++;
                    pci++;                                         //~v5mPI~
                	continue;
                }
        }
        if (chi==' ')
        {
            UTRACEP("mb2ebcs explen=%d,pco-1=%02x\n",explen,*(pco-1));//~v5mPI~
            if (opt0 & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert
                if (explen)
                {
                	if (*(pco-1)==CHAR_SI||*(pco-1)==CHAR_EBC_SPACE) //keep word delm
                    {
                    	explen--;
                        pci++;                                     //~v5mPI~
            			continue;               //drop input space until expanded len by SO/SI insert
                    }
            	}
        }
//  	if (ctlsw
//  	&& chi<sizeof(Stblctla2e)     //ctl char(<x20 and 7f)
//  	&& (ctlc=Stblctla2e[chi])!=0xff)       //corresponding ebc defined
//      {
//      	*pco++=ctlc;
//          continue;
//      }
//  	if (crlfsw)
//      {
//      	if (chi=='\n')
//          {
//          	*pco++=EBC_NL;
//              continue;
//          }
//          else
//      	if (chi=='\r')
//          {
//          	*pco++=EBC_CR;
//              continue;
//          }
//      }
//		cho=pcvt[chi];
//      if (!cho)
//      	cho=(UCHAR)Prepchar;
// 		*pco++=cho;
        rc|=ucvext_icumb2ebc1(opt0,cvsbcs,mapsbcs,mapcsbcs,pci,1,pco,&sbcschklen,&sbcsoutlen,Prepchar);
        pci+=sbcschklen;
        if (Ppdbcs)
        	pdbcs+=sbcschklen;
        pco+=sbcsoutlen;
    }
//	outlen=(int)((ULONG)pco-(ULONG)Pobuff);                        //~v6hhR~
	outlen=(int)((ULPTR)pco-(ULPTR)Pobuff);                        //~v6hhI~
    if (Ppoutlen)
		*Ppoutlen=outlen;
UTRACEP("icumb2ebcs rc=%d,outlen=%d\n",rc,outlen);
UTRACED("icumb2ebcs output",Pobuff,outlen);
    return rc;
}//ucvext_icumb2ebcs
//*************************************************************************
//*translate by icu converter
//* ebc file to mb file
//*************************************************************************
//int ucvext_icuebc2mbf(int Popt,ULONG *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v5mWR~//~v68hR~
//int ucvext_icuebc2mbf(int Popt,int Pmiscopt,ULONG *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v68hI~//~v6hhR~
int ucvext_icuebc2mbf(int Popt,int Pmiscopt,ULPTR *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v6hhI~
{
//  int rc=0,readlen,writelen,mbslen,opt,swfixed,cvopt,lrecl;      //~v690R~
    int rc=0,writelen,mbslen,opt,swfixed,cvopt,lrecl;              //~v690I~
    UINT readlen;                                                  //~v690I~
    FILE *fhi,*fho;
    char *pbuff,*pbuff2;
//  ULONG pconverters[4];                                          //~v6hhR~
    ULPTR pconverters[4];                                          //~v6hhI~
    int handle;                                                    //~v69pI~
//***************************
    swfixed=(Popt & EBC2ASC_FIXEDLRECL);                           //~v5mWI~
	fhi=fopen(Pinpfilename,"rb");
    if (!fhi)
    	return ufileapierr("fopen",Pinpfilename,errno);
    if (Poutfilename)                                              //~v5mWI~
    {                                                              //~v5mWI~
        fho=fopen(Poutfilename,"wb");                              //~v5mWR~
        if (!fho)                                                  //~v5mWR~
        {                                                          //~v5mWI~
	        fclose(fhi);                                           //~v5mWI~
            return ufileapierr("fopen",Poutfilename,errno);        //~v5mWR~
        }                                                          //~v5mWI~
    }                                                              //~v5mWI~
    else                                                           //~v5mWI~
    {                                                              //~v68hI~
#ifdef UNX                                                         //~v68hI~
#else                                                              //~v68hI~
        setmode(1,O_BINARY);    //binary mode                      //~v68hR~
#endif                                                             //~v68hI~
    	fho=stdout;                                                //~v5mWI~
    }                                                              //~v68hI~
    if (!(lrecl=Plen))                                             //~v5mWR~
    {                                                              //~v5mTI~
        if (swfixed)                                               //~v5n1I~
    		lrecl=EBC_DEFAULT_LRECL;                               //~v5n1R~
        else                                                       //~v5n1I~
    		lrecl=MB_MAXLINELEN;                                   //~v5n1I~
    }                                                              //~v5mTI~
  if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC                        //~v6b9I~
    pbuff=umalloc((UINT)lrecl*3);  //ebc                           //~v6b9I~
  else                                                             //~v6b9I~
    pbuff=umalloc((UINT)lrecl*(MAX_MBCSLEN+1));  //ebc                           //~v5mWR~//~v6b9R~
    UALLOCCHK(pbuff,UALLOC_FAILED);
    pbuff2=pbuff+lrecl;            //mbs                           //~v5mWR~
    cvopt=Popt;                                                    //~v5mWR~
//  if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC                    //~v6b9I~//~v6bjR~
//      cvopt|=EBC2ASC_EXT_TOUTF8;	//UCVEXTO_TOUTF8               //~v6b9R~//~v6bjR~
    handle=0;                                                      //~v6bjI~
  if (Pmiscopt & MISC_HANDLE)	//ebc handle parameter             //~v69pR~
  {                                                                //~v69pI~
// 	handle=(int)(ULONG)Pconverters;                                //~v69pR~//~v6hhR~
 	handle=(int)(ULPTR)Pconverters;                                //~v6hhI~
    if (UCVEBCH_HANDLE_ISDBCSCV(handle))                           //~v69pI~
        cvopt|=EBC2ASC_DBCS;    //dbcs trans                       //~v69pI~
  }                                                                //~v69pI~
  else                                                             //~v69pI~
  {                                                                //~v69pI~
	if (ucvext_openparmconverter(cvopt,Pconverters,pconverters,&cvopt))//~v5mWR~
    	return 8;                                                  //~v5mWR~
  }                                                                //~v69pI~
    if (!swfixed)//text mode transfer                              //~v5mWI~
    {                                                              //~v5mWI~
//  	opt=UFGETS_PC|UFGETS_UNIX;                                 //~v5mWI~//~v68hR~
        opt=ucvebc_chkeolopt(UCVEBCCEO_FGETSOPT,&Popt,Pmiscopt);   //~v68hR~
    	ufgetsinit(opt,0/*buffsz:default*/,0/*binrate*/,0/*lrecl of bin file*/);//~v5mWI~
    }                                                              //~v5mWI~
    for (;;)
    {
        if (swfixed)                                               //~v5mWI~
        {                                                          //~v5mWI~
//  		readlen=fread(pbuff,1,lrecl,fhi);                      //~v5mWR~//~v6BkR~
    		readlen=(UINT)fread(pbuff,1,(size_t)lrecl,fhi);              //~v6BkI~//~v6BjR~//~v6BxR~
        	if (!readlen)                                          //~v5mWR~
        		break;                                             //~v5mWR~
//          if (readlen<lrecl)                                     //~v690R~
            if (readlen<(UINT)lrecl)                               //~v690I~
//          	memset(pbuff+readlen,' ',(UINT)(lrecl-readlen));   //~v5mWR~//~v6BkR~
            	memset(pbuff+readlen,' ',(size_t)((UINT)lrecl-readlen));//~v6BkR~
        }                                                          //~v5mWI~
        else                                                       //~v5mWI~
        {                                                          //~v5mWI~
//			if (ufgets(pbuff,lrecl,fhi,&readlen,0))                //~v5mWR~//~v6BkR~
  			if (ufgets(pbuff,(UINT)lrecl,fhi,&readlen,0))          //~v6BkI~
        		break;                                             //~v5mWI~
        }                                                          //~v5mWI~
  	  if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC                    //~v6bjI~
//		rc|=ucvebc3_b2f(0,cvopt,handle,pbuff,readlen,pbuff2,0/*outdbcs*/,lrecl*MAX_MBCSLEN,&mbslen);//~v6bjR~//~v6BkR~
  		rc|=ucvebc3_b2f(0,cvopt,handle,pbuff,(int)readlen,pbuff2,0/*outdbcs*/,lrecl*MAX_MBCSLEN,&mbslen);//~v6BkI~
      else                                                         //~v6bjI~
      if (Pmiscopt & MISC_HANDLE)	//ebc handle parameter         //~v69pI~
//		rc|=ucvext_icuebc2mbs_handle(cvopt,handle,pbuff,0/*dbcs*/,readlen,pbuff2,&mbslen,Perrrep);//~v69pI~//~v6BkR~
  		rc|=ucvext_icuebc2mbs_handle(cvopt,handle,pbuff,0/*dbcs*/,(int)readlen,pbuff2,&mbslen,Perrrep);//~v6BkI~
      else                                                         //~v69pI~
//  	rc|=ucvext_icuebc2mbs(cvopt,pconverters,pbuff,0/*dbcs*/,readlen,pbuff2,&mbslen,Perrrep);//~v5mWR~//~v6BkR~
    	rc|=ucvext_icuebc2mbs(cvopt,pconverters,pbuff,0/*dbcs*/,(int)readlen,pbuff2,&mbslen,Perrrep);//~v6BkI~
        if (mbslen)
        {
//      	writelen=fwrite(pbuff2,1,mbslen,fho);                  //~v6BkR~
        	writelen=(int)fwrite(pbuff2,1,(size_t)mbslen,fho);     //~v6BkI~
            if (writelen!=mbslen)
		    	return ufileapierr("fwrite",Poutfilename,errno);
        }
        if (Popt & EBC2ASC_SETEOL)                                 //~v5mYI~
#ifdef UNX                                                         //~v68hI~
        	fwrite("\n",1,1,fho);                                  //~v5mYR~
#else                                                              //~v68hI~
            fwrite("\r\n",1,2,fho);                                //~v68hI~
#endif                                                             //~v68hI~
    }
    ufree(pbuff);
	fclose(fhi);                                                   //~v5n1I~
    if (Poutfilename)                                              //~v5n1I~
		fclose(fho);                                               //~v5n1I~
    return rc;
}//ucvext_icuebc2mbf
//*************************************************************************
//*translate by icu converter
//* ebc file to mb file
//* pmaxlinelen: maxlinelen(2byte)+lrecl(2byte)                    //~v5mWR~
//*************************************************************************
//int ucvext_icumb2ebcf(int Popt,ULONG *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v5mWR~//~v68hR~
//int ucvext_icumb2ebcf(int Popt,int Pmiscopt,ULONG *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v68hI~//~v6hhR~
int ucvext_icumb2ebcf(int Popt,int Pmiscopt,ULPTR *Pconverters,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v6hhI~
{
//  int rc=0,readlen,writelen,ebclen,opt,swfixed,swnumstd,shiftlen,lrecl,cvopt,spacelen,reslen;//~v690R~
    int rc=0,writelen,ebclen,opt,swfixed,swnumstd,shiftlen,lrecl,cvopt,spacelen,reslen;//~v690I~
    UINT readlen;                                                  //~v690I~
    int maxlinelen,numoksw;                                        //~v5mWR~
    int outbuffsz;                                                 //~v6b9I~
    FILE *fhi,*fho;
    char *pbuff,*pbuff2,*pc,*pc0;                                  //~v5mWR~
//  ULONG pconverters[4];                                          //~v6hhR~
    ULPTR pconverters[4];                                          //~v6hhI~
    int handle;                                                    //~v69pI~
    char *pbuff3=NULL;                                                  //~v6bjI~//~v6h6R~
//***************************
UTRACEP("mb2ebcf opt=%08x\n",Popt);                                //~v5mWR~
    opt=ucvebc_chkeolopt(UCVEBCCEO_FGETSOPT,&Popt,Pmiscopt);       //~v68hR~
    swfixed=(Popt & EBC2ASC_FIXEDLRECL);                           //~v5mWI~
    swnumstd=(Popt & EBC2ASC_NUMSTD);                              //~v5mWI~
    lrecl=Plen&0xffff;                                             //~v5mWR~
//  maxlinelen=(UINT)Plen>>16;                                     //~v5mWR~//~v6BkR~
    maxlinelen=(int)((UINT)Plen>>16);                              //~v6BkI~
//  opt=UFGETS_PC|UFGETS_UNIX;                                     //~v68hR~
    ufgetsinit(opt,0/*buffsz:default*/,0/*binrate*/,0/*lrecl of bin file*/);
	fhi=fopen(Pinpfilename,"rb");
    if (!fhi)
    	return ufileapierr("fopen",Pinpfilename,errno);
    if (Poutfilename)                                              //~v5mWI~
    {                                                              //~v5mWI~
        fho=fopen(Poutfilename,"wb");                              //~v5mWR~
        if (!fho)                                                  //~v5mWR~
        {                                                          //~v5mWI~
	        fclose(fhi);                                           //~v5mWI~
            return ufileapierr("fopen",Poutfilename,errno);        //~v5mWR~
        }                                                          //~v5mWI~
    }                                                              //~v5mWI~
    else                                                           //~v5mWI~
    {                                                              //~v68hI~
#ifdef UNX                                                         //~v68hI~
#else                                                              //~v68hI~
        setmode(1,O_BINARY);    //binary mode                      //~v68hR~
#endif                                                             //~v68hI~
    	fho=stdout;                                                //~v5mWI~
    }                                                              //~v68hI~
    if (!maxlinelen)                                               //~v5mWR~
    	maxlinelen=MB_MAXLINELEN;                                  //~v5mWI~
    if (swfixed)                                                   //~v5mWR~
        if (!lrecl)                                                //~v5mWI~
        	lrecl=EBC_DEFAULT_LRECL;        //80                   //~v5mWI~
  if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC dbcstb required        //~v6bjI~
    pbuff=umalloc((UINT)maxlinelen*5);  //1+2(outdata)+2(outdbcs)  //~v6bjI~
  else                                                             //~v6bjI~
    pbuff=umalloc((UINT)maxlinelen*3);  //mbs                      //~v5mWR~
    UALLOCCHK(pbuff,UALLOC_FAILED);
    pbuff2=pbuff+maxlinelen;            //ebc                      //~v5mWR~
    outbuffsz=maxlinelen*2;                                        //~v6b9I~
  if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC dbcstb required        //~v6bjI~
    pbuff3=pbuff2+outbuffsz;            //ebc                      //~v6bjI~
    cvopt=Popt;                                                    //~v5mWR~
    handle=0;                                                      //~v6bjI~
  if (Pmiscopt & MISC_HANDLE)	//ebc handle parameter             //~v69pR~
  {                                                                //~v69pI~
// 	handle=(int)(ULONG)Pconverters;                                //~v69pR~//~v6hhR~
  	handle=(int)(ULPTR)Pconverters;                                //~v6hhI~
    if (UCVEBCH_HANDLE_ISDBCSCV(handle))                           //~v69pI~
        cvopt|=EBC2ASC_DBCS;    //dbcs trans                       //~v69pI~
  }                                                                //~v69pI~
  else                                                             //~v69pI~
  {                                                                //~v69pI~
	if (ucvext_openparmconverter(cvopt,Pconverters,pconverters,&cvopt))//~v5mWR~
    	return 8;                                                  //~v5mWR~
  }                                                                //~v69pI~
UTRACEP("Popt=%08x,opt=%08x\n",Popt,opt);
    for (;;)
    {
//		if (ufgets(pbuff,maxlinelen,fhi,&readlen,0))               //~v5mWR~//~v6BkR~
  		if (ufgets(pbuff,(UINT)maxlinelen,fhi,&readlen,0))         //~v6BkI~
        	break;
        ebclen=lrecl;        //input to mb2ebc,insert SI at EOL by LRECL//~v5mWI~
      if (Pmiscopt & MISC_UTF8)	//utf8->EBCIDIC                    //~v6bjR~
//  	rc|=ucvebc3_f2bcmd(0,cvopt,handle,pbuff,readlen,pbuff2,pbuff3/*outdbcs*/,outbuffsz,&ebclen);//~v6bjR~//~v6BkR~
    	rc|=ucvebc3_f2bcmd(0,cvopt,handle,pbuff,(int)readlen,pbuff2,pbuff3/*outdbcs*/,outbuffsz,&ebclen);//~v6BkI~
      else                                                         //~v6bjR~
      if (Pmiscopt & MISC_HANDLE)	//ebc handle parameter         //~v69pI~
//  	rc|=ucvext_icumb2ebcs_handle(cvopt,handle,pbuff,0/*dbcs*/,readlen,pbuff2,&ebclen,Perrrep);//~v69pI~//~v6BkR~
    	rc|=ucvext_icumb2ebcs_handle(cvopt,handle,pbuff,0/*dbcs*/,(int)readlen,pbuff2,&ebclen,Perrrep);//~v6BkI~
      else                                                         //~v69pI~
//  	rc|=ucvext_icumb2ebcs(cvopt,pconverters,pbuff,0/*dbcs*/,readlen,pbuff2,&ebclen,Perrrep);//~v5mWR~//~v6BkR~
    	rc|=ucvext_icumb2ebcs(cvopt,pconverters,pbuff,0/*dbcs*/,(int)readlen,pbuff2,&ebclen,Perrrep);//~v6BkI~
        numoksw=0;                                                 //~v5mWI~
        if (swfixed)                                               //~v5mWI~
        {                                                          //~v5mWI~
            if (ebclen!=lrecl && swnumstd)   //short/long record with of NUMSTD member//~v5mWI~
            {                                                      //~v5mWI~
                pc=pbuff+readlen-SPFNUMFLDLEN;                     //~v5mWR~
                if (unumlen(pc,0/*opt*/,SPFNUMFLDLEN)==SPFNUMFLDLEN)//8 byte valid numeric//~v5mWI~
                {                                                  //~v5mWI~
                	numoksw=1;                                     //~v5mWI~
                    pc=pc0=pbuff2+ebclen-SPFNUMFLDLEN;             //~v5mWR~
                    if (ebclen>lrecl)   //long record              //~v5mWR~
                    {                                              //~v5mWI~
                        shiftlen=min(ebclen-lrecl,SPFNUMFLDLEN);   //~v5mWR~
                        for (spacelen=0,pc--;*pc==CHAR_EBC_SPACE && spacelen<shiftlen;pc--)//~v5mWI~
                            spacelen++;                            //~v5mWI~
                        if (spacelen)                              //~v5mWI~
                        {                                          //~v5mWI~
                            memcpy(pc0-spacelen,pc0,SPFNUMFLDLEN); //~v5mWI~
                            ebclen-=spacelen;                      //~v5mWR~
                        }                                          //~v5mWI~
                    }                                              //~v5mWI~
                    else                        //short record     //~v5mWI~
                    {                                              //~v5mWI~
                        spacelen=lrecl-ebclen;                     //~v5mWR~
                        memmove(pc0+spacelen,pc0,SPFNUMFLDLEN);    //~v5mWI~
//                      memset(pc0,CHAR_EBC_SPACE,spacelen);       //~v5mWI~//~v6BkR~
                        memset(pc0,CHAR_EBC_SPACE,(size_t)spacelen);//~v6BkI~
                        ebclen+=spacelen;                          //~v5mWR~
                    }                                              //~v5mWI~
                }                                                  //~v5mWI~
            }                                                      //~v5mWI~
            if (numoksw && ebclen>lrecl && ebclen-SPFNUMFLDLEN<=lrecl)//~v5mWR~
            {                                                      //~v5mWR~
                UTRACED("local2ebc EBC expanded",pbuff2,ebclen);   //~v5mWR~
                ebclen=lrecl;                                      //~v5mWR~
            }                                                      //~v5mWR~
            for (reslen=ebclen,pc=pbuff2;reslen>0;reslen-=lrecl,pc+=lrecl)//~v5mWR~
            {                                                      //~v5mWI~
                if (reslen<lrecl)                                  //~v5mWI~
                    memset(pc+reslen,CHAR_EBC_SPACE,(UINT)(lrecl-reslen));//~v5mWR~
//              writelen=fwrite(pc,1,(UINT)lrecl,fho);             //~v5mWI~//~v6BkR~
                writelen=(int)fwrite(pc,1,(UINT)lrecl,fho);        //~v6BkI~
UTRACED("ebc write",pc,lrecl);                                     //~v5mWI~
                if (Popt & EBC2ASC_SETEOL)                         //~v5mYI~
                {                                                  //~v68hI~
                  if (Pmiscopt & MISC_ASCEOL)                      //~v68hI~
#ifdef UNX                                                         //~v68hI~
        			fwrite("\n",1,1,fho);                          //~v5mYI~
#else                                                              //~v68hI~
                    fwrite("\r\n",1,2,fho);                        //~v68hI~
#endif                                                             //~v68hI~
                  else                                             //~v68hI~
                  	fwrite(EBC_NL_STR,1,1,fho);                    //~v68hI~
                }                                                  //~v68hI~
                if (writelen<lrecl)                                //~v5mWI~
                    break;                                         //~v5mWI~
            }                                                      //~v5mWI~
        }                                                          //~v5mWI~
        else                                                       //~v5mWI~
        {                                                          //~v5mWI~
        	if (ebclen)                                            //~v5mWI~
            {                                                      //~v5mWI~
//      		writelen=fwrite(pbuff2,1,ebclen,fho);              //~v5mWR~//~v6BkR~
        		writelen=(int)fwrite(pbuff2,1,(size_t)ebclen,fho); //~v6BkI~
            	if (writelen!=ebclen)                              //~v5mWR~
		    		return ufileapierr("fwrite",Poutfilename,errno);//~v5mWR~
            }                                                      //~v5mWI~
            if (Popt & EBC2ASC_SETEOL)                             //~v5mYI~
            {                                                      //~v68jI~
              if (Pmiscopt & MISC_ASCEOL)                          //~v68hI~
#ifdef UNX                                                         //~v68hI~
        		fwrite("\n",1,1,fho);                              //~v5mYR~
#else                                                              //~v68hI~
                fwrite("\r\n",1,2,fho);                            //~v68hI~
#endif                                                             //~v68hI~
              else                                                 //~v68hI~
               	fwrite(EBC_NL_STR,1,1,fho);                        //~v68hI~
            }                                                      //~v68jI~
        }
    }
	fclose(fhi);                                                   //~v5n1I~
    if (Poutfilename)	//not stdout                               //~v5n1I~
		fclose(fho);                                               //~v5n1I~
    return rc;
}//ucvext_icumb2ebcf
//*************************************************************************//~v6f3I~
//*translate by icu converter                                      //~v6f3I~
//* local to ucs                                                   //~v6f3I~
//* rc:-3:subchar was set,-11:dbcssplit, 4:err                     //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icumb2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS *Ppucs)//~v6f3I~//~v6hhR~
int ucvext_icumb2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS *Ppucs)//~v6hhI~
{                                                                  //~v6f3I~
    ICUFUNC_TOUCS   api;                                           //~v6f3I~
	UErrorCode err=U_ZERO_ERROR;                                   //~v6f3I~
    UConverter *converter;                                         //~v6f3I~
    UChar wkutf16[2],utf16h,utf16l;                                //~v6f3I~
    int chklen=0;                                                    //~v6f3I~//~v6h7R~
    int rc=0;                                                      //~v6f3I~
//***************************                                      //~v6f3I~
UTRACEP("ucvext_icumb2ucs1 opt=%x,converter=%x len=%d,mb=%02x\n",Popt,Pconverter,Pinplen,*Ppmbs);//~v6f3I~
UTRACED("ucvext_icumb2ucs1 Ppmbcs",Ppmbs,Pinplen);                //~v6BjI~
    if (UTF8ISASCII(*Ppmbs))                                       //~v6f3I~
    {                                                              //~v6f3I~
        *Ppchklen=1;                                               //~v6f3I~
        *Ppucs=*Ppmbs;                                             //~v6f3I~
        return 0;                                                  //~v6f3I~
    }                                                              //~v6f3I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3I~
    api=Spfunctoucs;  //ucnv_toUChars;                             //~v6f3I~
    converter=(UConverter*)Pconverter;                             //~v6f3I~
    wkutf16[1]=0;                                                  //~v6f3I~
//  (*api)(converter,wkutf16,sizeof(wkutf16)/sizeof(UChar),Ppmbs,Pinplen,&err);  //~v6f3I~//~v6fnR~//~v6BkR~
    (*api)(converter,wkutf16,sizeof(wkutf16)/sizeof(UChar),Ppmbs,(UINT)Pinplen,&err);//~v6BkI~
    //*0x1a of 0xfffd is put for not defined code point            //~v6f3I~
	if (U_FAILURE(err))                                            //~v6f3I~
	{                                                              //~v6f3I~
//      ucvext_icureset(0,(ULONG)converter);                       //~v6f3R~//~v6hhR~
        ucvext_icureset(0,(ULPTR)converter);                       //~v6hhI~
		UTRACEP("icumb2ucs1 ERR=%08x=%s\n",(UINT)err,ucvext_icuuerrname(err));//~v6f3I~//~v6BjR~
        if (err==U_TRUNCATED_CHAR_FOUND)                           //~v6f3I~
			rc=UCEICL2U1ORC_DBCSSPLIT;//           -11             //~v6f3I~
        else                                                       //~v6f3I~
			rc=4;                                                  //~v6f3I~
	}                                                              //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
    	utf16h=wkutf16[0];                                         //~v6f3I~
    	utf16l=wkutf16[1];                                         //~v6f3I~
    	if (IS_UTF16_PAIR(utf16h,utf16l))                          //~v6f3I~
//          *Ppucs=(WUCS)UTF16_TO_UCS4(utf16h,utf16l);             //~v6f3I~//~v6BjR~
            *Ppucs=(UWUCS)UTF16_TO_UCS4(utf16h,utf16l);            //~v6BjI~
        else                                                       //~v6f3I~
//          *Ppucs=(WUCS)utf16h;                                   //~v6f3I~//~v6BjR~
            *Ppucs=(UWUCS)utf16h;                                  //~v6BjI~
        chklen=Pinplen;                                            //~v6f3I~
        if (Popt & UCVEXTO_SETSUBCHRC)                             //~v6f3I~
        	if (*Ppucs==UDBCSCHK_SUBCHAR_DBCS||*Ppucs==UDBCSCHK_SUBCHAR_SBCS)//~v6f3R~
            	rc=UCVEXTRC_SUBCH;                                 //~v6f3I~
    }                                                              //~v6f3I~
  	if (Ppchklen)                                                  //~v6f3I~
    	*Ppchklen=chklen;                                          //~v6f3I~
//  UTRACEP("icumb2ucs1 rc=%x,inplen=%d,in=%02x%02x,chklen=%d,outucs=%04x\n",rc,Pinplen,*Ppmbs,*(Ppmbs+1),chklen,*Ppucs);//~v6f3I~//~v6h7R~
    return rc;                                                     //~v6f3I~
}//ucvext_icumb2ucs1                                               //~v6f3I~
//*************************************************************************//~v6f3R~
//*translate by icu converter                                      //~v6f3R~
//* ucs to mb                                                      //~v6f3R~
//* Pconverters:ptr list to UConvertsers* and Subchar*             //~v6f4I~
//* rc: err                                                        //~v6f3R~
//*************************************************************************//~v6f3R~
//int ucvext_icuucs2mb1(int Popt,ULONG Pconverter,UWUCS Pucs,char *Ppmbs,int *Ppoutlen)//~v6f3R~//~v6f4R~
//int ucvext_icuucs2mb1(int Popt,ULONG *Pconverters,UWUCS Pucs,char *Ppmbs,int *Ppoutlen)//~v6f4I~//~v6hhR~
int ucvext_icuucs2mb1(int Popt,ULPTR *Pconverters,UWUCS Pucs,char *Ppmbs,int *Ppoutlen)//~v6hhI~
{                                                                  //~v6f3R~
    ICUFUNC_FROMUCS   api;                                         //~v6f3R~
	UErrorCode err=U_ZERO_ERROR;                                   //~v6f3R~
    UConverter *converter;                                         //~v6f3R~
	UChar wkutf16[2];                                              //~v6f3R~
    int rc=0,len,utf16ctr;                                         //~v6f3R~
    char mbs[MAX_MBCSLEN];                                         //~v6foI~
//***************************                                      //~v6f3R~
UTRACEP("icuucs2mb1 opt=%x,ucs=%04x\n",Popt,Pucs);//~v6f3R~       //~v6f4R~//~v6f7R~
UTRACED("icuucs2mb1 converter",Pconverters,2*sizeof(ULONG));      //~v6f4I~//~v6f7R~
    if (UTF8ISASCII(Pucs))                                         //~v6f3R~
    {                                                              //~v6f3R~
//      *Ppmbs=Pucs;                                               //~v6f3R~//~v6BiR~
        *Ppmbs=(UCHAR)Pucs;                                        //~v6BiI~
        *Ppoutlen=1;                                               //~v6f3R~
        return 0;                                                  //~v6f3R~
    }                                                              //~v6f3R~
	ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3R~
    UCS4_TO_UTF16(Pucs,wkutf16,&utf16ctr);                         //~v6f3R~
    api=Spfuncfromucs;  //ucnv_fromUChars;                         //~v6f3R~
//  converter=(UConverter*)Pconverter;                             //~v6f3R~//~v6f7R~
    converter=(UConverter*)Pconverters[ICULCPL_CONVERTER];         //~v6f7R~
	UTRACEP("%s:converter=%p\n",UTT,converter);                    //~v6BjI~
//  len=(*api)(converter,Ppmbs,MAX_MBCSLEN,wkutf16,utf16ctr,&err); //~v6f3R~//~v6foR~
//  len=(*api)(converter,mbs,MAX_MBCSLEN,wkutf16,utf16ctr,&err);   //~v6foI~//~v6BkR~
    len=(int)(*api)(converter,mbs,MAX_MBCSLEN,wkutf16,(UINT)utf16ctr,&err);//~v6BkI~
    //subchar1 or subchar is set for not defined codepoint         //~v6f3R~
    if (U_FAILURE(err))                                            //~v6f3R~
	{                                                              //~v6f3R~
//      ucvext_icureset(0,(ULONG)converter);                       //~v6f3R~//~v6hhR~
        ucvext_icureset(0,(ULPTR)converter);                       //~v6hhI~
		UTRACEP("ERR ucs2ebc1 err=%08x=%s\n",(UINT)err,ucvext_icuuerrname(err));//~v6f3R~
		rc=4;                                                      //~v6f3R~
	}                                                              //~v6f3R~
    else                                                           //~v6f3R~
    {                                                              //~v6f4I~
    	*Ppoutlen=len;                                             //~v6f3R~
//      memcpy(Ppmbs,mbs,len);                                     //~v6foI~//~v6BkR~
        memcpy(Ppmbs,mbs,(size_t)len);                             //~v6BkI~
        if (Popt & UCVEXTO_SETSUBCHRC)                             //~v6f7R~
        {                                                          //~v6uNI~
			UTRACEP("%s:subch=%s\n",UTT,(char*)Pconverters[ICULCPL_SUBCH]);//~v6BjI~
//        	if (!strcmp(Ppmbs,(char*)Pconverters[ICULCPL_SUBCH]))  //~v6f7R~//~v6fpR~
          	if (!memcmp(Ppmbs,(char*)Pconverters[ICULCPL_SUBCH],strlen((char*)Pconverters[ICULCPL_SUBCH])))//~v6foI~//~v6fpR~
            	rc=UCVEXTRC_SUBCH;                                 //~v6f7R~
            else                                                   //~v6uNI~
            if (len==1 && *mbs==CHAR_UCS_SUB    //0x1a             //~v6uNR~
            && Pucs!=CHAR_UCS_SUB)                                 //~v6uNI~
//*FIXME :test on win                                              //~v6uNI~
            	rc=UCVEXTRC_SUBCH;                                 //~v6uNI~
        }                                                          //~v6uNI~
    }                                                              //~v6f4I~
    UTRACEP("ucvext_icuucs2mb1 rc=%x\n",rc);                       //~v6f3R~
    UTRACED("ucvext_icuucs2mb1 out=",Ppmbs,len);                   //~v6f3R~
    return rc;                                                     //~v6f3R~
}//ucvext_icuucs2mb1                                               //~v6f3R~
//*************************************************************************//~v6f1I~//~v6f3I~
//*translate by icu converter                                      //~v6f1I~//~v6f3I~
//* utf to locale(from utfcvf2lany1ICU)                                                  //~v6f3I~//~v6f4R~
//* rc:4(UCVEXTRC_ERR)-3(UCVEXTRC_BUFFOVF)                         //~v6f4R~
//*************************************************************************//~v6f1I~//~v6f3I~
//int ucvext_icuutf2mb1(int Popt,ULONG Pconverter,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen)//~v6f1R~//~v6f3I~//~v6f7R~
//int ucvext_icuutf2mb1(int Popt,ULONG *Pconverters,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen)//~v6f7I~//~v6hhR~
int ucvext_icuutf2mb1(int Popt,ULPTR *Pconverters,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen)//~v6hhI~
{                                                                  //~v6f1I~//~v6f3I~
    int chklen,outlen;                     //~v6f1R~               //~v6f3I~
    UCHAR *pci,*pco;                                               //~v6f1I~//~v6f3I~
    UINT ch;                                                       //~v6f1I~//~v6f3I~
    UWUCS ucs;                                                      //~v6f1R~//~v6f3I~
    int rc=0,rc2;                                                  //~v6f1I~//~v6f3I~
    int opt;                                                       //~v6f1I~//~v6f3I~
    char mbs[MAX_MBCSLEN];                                         //~v6f3I~
//***************************                                      //~v6f1I~//~v6f3I~
UTRACEP("ucvext_icuutf2mb1 opt=%x\n",Popt);//~v6f1I~//~v6f3I~      //~v6f7R~
UTRACEP("ucvext_icuutf2mb1",Pconverters,2*sizeof(ULONG));          //~v6f7I~
UTRACED("ucvext_icuutf2mb1 inp utf8",Pputf8,Pinplen);              //~v6f3I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f1I~//~v6f3I~
    pci=Pputf8;                                                    //~v6f3R~
    pco=Ppmbs;                                                     //~v6f3R~
    opt=UCVUCS_UCS4|Popt;//subchrc                                               //~v6f1I~//~v6f3I~//~v6f7R~
    ch=*pci;                                                       //~v6f3I~
    if (UTF8ISASCII(ch))    //chof setup                       //~v6f1R~//~v6f3I~
    {                                                          //~v6f1I~//~v6f3I~
        chklen=1;                                              //~v6f1I~//~v6f3I~
//      *pco=ch;                                               //~v6f1I~//~v6f3I~//~v6BiR~
        *pco=(UCHAR)ch;                                            //~v6BiI~
        outlen=1;                                              //~v6f1R~//~v6f3I~
    }                                                          //~v6f1I~//~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
//      if (uccvutf2ucs(opt,pci,Pinplen,&ucs,&chklen))              //~v6f1I~//~v6f3I~//~v6BkR~
        if (uccvutf2ucs((ULONG)opt,pci,Pinplen,&ucs,&chklen))      //~v6BkI~
        {                                                          //~v6f1I~//~v6f3I~
            rc=UCVEXTRC_ERR;                                       //~v6f4I~
        	chklen=1;                                              //~v6foI~
            outlen=1;                                              //~v6foI~
//          *pco=ch;                                               //~v6foI~//~v6BiR~
            *pco=(UCHAR)ch;                                        //~v6BiI~
        }                                                          //~v6f1I~//~v6f3I~
        else                                                       //~v6f4I~
        {                                                          //~v6f4I~
        	rc2=ucvext_icuucs2mb1(opt,Pconverters,ucs,mbs,&outlen);       //~v6f1I~//~v6f3I~//~v6f4R~//~v6f7R~//~v6foR~
            if (rc2)                                               //~v6f4R~
            	rc=UCVEXTRC_ERR;                                    //~v6f4R~//~v6f7R~
            else                                                   //~v6f4I~
            if (outlen>Pbuffsz)                                        //~v6f3R~//~v6f4R~
            	rc=UTFCVRC_ERROVF;                                 //~v6f4I~
            else                                                   //~v6f4I~
//              memcpy(pco,mbs,outlen);                                //~v6f3I~//~v6f4R~//~v6BkR~
                memcpy(pco,mbs,(size_t)outlen);                    //~v6BkI~
            if (rc)                                                //~v6foI~
            {                                                      //~v6foI~
            	outlen=1;                                          //~v6foI~
	        	*pco='?';                                          //~v6foI~
            }                                                      //~v6foI~
        }                                                          //~v6f4I~
    }                                                              //~v6f1I~//~v6f3I~
    *Ppreadlen=chklen;                                             //~v6f3I~
    *Ppoutlen=outlen;                                              //~v6f3I~
UTRACEP("ucvext_icuutf2mb1 rc=%d,chklen=%d,outlen=%d\n",rc,chklen,outlen);//~v6f3I~
UTRACED("ucvext_icuutf2mb1 out mbs",Ppmbs,outlen);                 //~v6f3I~
    return rc;                                                     //~v6f1I~//~v6f3I~
}//ucvext_icuutf2mb1                                               //~v6f3R~
//*************************************************************************//~v6f3I~
//*translate by icu converter                                      //~v6f3I~
//* local to ucs  (from utfcvl2fany1ICU)                           //~v6f3I~//~v6f4R~
//* rc:4(UCVEXTRC_ERR)-3(UCVEXTRC_BUFFOVF)                         //~v6f4I~
//*************************************************************************//~v6f3I~
//int ucvext_icumb2utf1(int Popt,ULONG *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int *Ppreadlen,int *Ppoutlen)//~v6f3I~//~v6hhR~
int ucvext_icumb2utf1(int Popt,ULPTR *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int *Ppreadlen,int *Ppoutlen)//~v6hhI~
{                                                                  //~v6f3I~
//  ULONG converter;                                               //~v6x5R~
    ULPTR converter;                                               //~v6x5I~
    int chklen,outlen=0,mblen;                                       //~v6f3R~//~v6h6R~
    UCHAR *pci,*pco,*pdbcstb;                                      //~v6f3I~
    UINT ch;                                                       //~v6f3I~
    UWUCS ucs;                                                     //~v6f3I~
    int rc=0,rc2;                                                  //~v6f3R~
    char wkutf[MAX_MBCSLEN];                                       //~v6f3I~
//***************************                                      //~v6f3I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3I~
    converter=Pconverters[0];                                      //~v6f3I~
    pdbcstb=(UCHAR*)Pconverters[1];                                //~v6f3I~
UTRACEP("ucvext_icumb2utf1 opt=%x,converter=%x dbcstb=%p\n",Popt,converter,pdbcstb);//~v6f3I~
UTRACED("ucvext_icumb2utf1 mbs",Ppmbs,Pinplen);                    //~v6f3I~
    pci=Ppmbs;                                                     //~v6f3I~
    pco=Pputf8;                                                    //~v6f3I~
    ch=*pci;                                                       //~v6f3I~
    if (UTF8ISASCII(ch))    //chof setup                           //~v6f3I~
    {                                                              //~v6f3I~
        chklen=1;                                                  //~v6f3I~
//      *pco=ch;                                                   //~v6f3I~//~v6BiR~
        *pco=(UCHAR)ch;                                            //~v6BiI~
        outlen=1;                                                  //~v6f3I~
    }                                                              //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
        if (pdbcstb && !UDBCSCHK_IS_LEADBYTE(pdbcstb,ch))          //~v6f3I~
        	mblen=1;                                               //~v6f3I~
        else                                                       //~v6f3I~
        	udbcschk_getmblen(UDCGMLO_LEN1IFERR,pci,Pinplen,&mblen);//~v6f3R~
        rc2=ucvext_icumb2ucs1(Popt,converter,pci,mblen,&chklen,&ucs);//~v6f3I~
        if (rc2)                                                   //~v6f3I~
        {                                                          //~v6f3I~
            rc=rc2;                                                //~v6f4R~
        }                                                          //~v6f3I~
        else                                                       //~v6f3I~
        {                                                          //~v6f3I~
        	outlen=uccvucs2utf(ucs,wkutf);                         //~v6f3I~
            if (outlen>Pbuffsz)                                    //~v6f3I~
            	rc=UCVEXTRC_BUFFOVF;                               //~v6f3I~
            else                                                   //~v6f3I~
//          	memcpy(pco,wkutf,outlen);                          //~v6f3I~//~v6BkR~
            	memcpy(pco,wkutf,(size_t)outlen);                  //~v6BkI~
        }                                                          //~v6f3I~
        if (rc)                                                    //~v6f4I~
        {                                                          //~v6f4I~
        	chklen=1;                                              //~v6f4I~
            outlen=1;                                              //~v6f4I~
//          *pco=ch;                                               //~v6f4I~//~v6BiR~
            *pco=(UCHAR)ch;                                        //~v6BiI~
        }                                                          //~v6f4I~
    }                                                              //~v6f3I~
    if (Ppoutlen)                                                  //~v6f3I~
    	*Ppoutlen=outlen;                                          //~v6f3I~
    if (Ppreadlen)                                                 //~v6f3I~
    	*Ppreadlen=chklen;                                         //~v6f3I~
UTRACEP("ucvext_icumb2utf rc=%d,readlen=%d,repctr=%d\n",rc,chklen,outlen);//~v6f3I~
UTRACED("ucvext_icumb2utf out utf8",Pputf8,outlen);                //~v6f3I~
    return rc;                                                     //~v6f3I~
}//ucvext_icumb2utf1                                               //~v6f3I~
//*************************************************************************//~v6f3I~
//*translate by icu converter                                      //~v6f3I~
//* local to ucs(from uerrfprintfutf/jnig.c:gconvert_with_iconv)                                                   //~v6f3I~//~v6f4R~//~v6f7R~
//* rc:2 detected invalid code,1:subchar set                       //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icumb2utf(int Popt,ULONG *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int Prepch,//~v6f3R~//~v6hhR~
int ucvext_icumb2utf(int Popt,ULPTR *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int Prepch,//~v6hhI~
	int *Ppreadlen,int *Ppoutlen,int *Pprepctr)                    //~v6f3R~
{                                                                  //~v6f3I~
//  ULONG converter;                                               //~v6x5R~
    ULPTR converter;                                               //~v6x5I~
    int chklen,reslen,outreslen,outlen,mblen,readlen;              //~v6f3R~
    UCHAR *pci,*pco,*pdbcstb;                                      //~v6f3R~
    UINT ch;                                                       //~v6f3I~
    UWUCS ucs;                                                     //~v6f3I~
    int rc=0,rc2,repch,repctr=0;                                   //~v6f3R~
//***************************                                      //~v6f3I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3I~
    converter=Pconverters[0];                                      //~v6f3R~
    pdbcstb=(UCHAR*)Pconverters[1];                                //~v6f3I~
UTRACEP("ucvext_icumb2utf opt=%x,converter=%x dbcstb=%p\n",Popt,converter,pdbcstb);//~v6f3I~
UTRACED("ucvext_icumb2utf mbs",Ppmbs,Pinplen);                     //~v6f3I~
    repch=Prepch?Prepch:CHAR_ASCII_ERR;                            //~v6f3I~
    for (reslen=Pinplen,outreslen=Pbuffsz,pci=Ppmbs,pco=Pputf8;reslen>0 && outreslen>0;outreslen-=outlen,reslen-=chklen,pci+=chklen,pco+=outlen)//~v6f3R~
    {                                                              //~v6f3I~
    	ch=*pci;                                                   //~v6f3I~
		if (UTF8ISASCII(ch))	//chof setup                       //~v6f3I~
        {                                                          //~v6f3I~
        	chklen=1;                                              //~v6f3I~
//          *pco=ch;                                               //~v6f3I~//~v6BiR~
            *pco=(UCHAR)ch;                                        //~v6BiI~
            outlen=1;                                              //~v6f3I~
            continue;                                              //~v6f3I~
        }                                                          //~v6f3I~
        if (pdbcstb && !UDBCSCHK_IS_LEADBYTE(pdbcstb,ch))          //~v6f3R~
        	mblen=1;                                               //~v6f3I~
        else                                                       //~v6f3I~
        	udbcschk_getmblen(UDCGMLO_LEN1IFERR,pci,reslen,&mblen);//~v6f3R~
        rc2=ucvext_icumb2ucs1(Popt,converter,pci,mblen,&chklen,&ucs);//~v6f3R~
        if (rc2>1)  //invalid                                      //~v6f3I~
        {                                                          //~v6f3I~
            chklen=1;                                              //~v6f3I~
//          *pco=repch,CHAR_ASCII_ERR;                             //~v6f3R~//~v6BiR~
            *pco=(UCHAR)repch;                                     //~v6BiI~
            outlen=1;                                              //~v6f3I~
            repctr++;                                              //~v6f3I~
            rc|=4;                                                 //~v6f3I~
        }                                                          //~v6f3I~
        else                                                       //~v6f3I~
        {                                                          //~v6f3I~
        	if (rc2==1)                                            //~v6f3I~
            	rc|=1;                                             //~v6f3I~
        	outlen=uccvucs2utf(ucs,pco);                           //~v6f3I~
        }                                                          //~v6f3I~
    }                                                              //~v6f3I~
//  readlen=(ULONG)pci-(ULONG)Ppmbs;                               //~v6f3I~//~v6hhR~
//  readlen=(ULPTR)pci-(ULPTR)Ppmbs;                               //~v6hhI~//~v6BkR~
    readlen=PTRDIFF(pci,Ppmbs);                                    //~v6BkI~
    if (Ppreadlen)                                                 //~v6f3I~
    	*Ppreadlen=readlen;                                        //~v6f3R~
//  outlen=(ULONG)pco-(ULONG)Pputf8;                               //~v6f3I~//~v6hhR~
//  outlen=(ULPTR)pco-(ULPTR)Pputf8;                               //~v6hhI~//~v6BkR~
    outlen=PTRDIFF(pco,Pputf8);                                    //~v6BkI~
    if (Ppoutlen)                                                  //~v6f3I~
    	*Ppoutlen=outlen;                                          //~v6f3R~
    if (Pprepctr)                                                  //~v6f3I~
    	*Pprepctr=repctr;                                          //~v6f3I~
UTRACEP("ucvext_icumb2utf rc=%d,readlen=%d,repctr=%d\n",rc,readlen,repctr);//~v6f3R~
UTRACED("ucvext_icumb2utf out utf8",Pputf8,outlen);                //~v6f3R~
    return rc;                                                     //~v6f3I~
}//ucvext_icumb2utf                                                //~v6f3I~
//*************************************************************************//~v6f3I~
//*printable chk by ICU                                            //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icuisprint(int Popt,ULONG Pconverter,int Pucs)          //~v6f3I~//~v6f4R~
//int ucvext_icuisprint(int Popt,ULONG *Pconverters,int Pucs)        //~v6f4I~//~v6hhR~
int ucvext_icuisprint(int Popt,ULPTR *Pconverters,int Pucs)        //~v6hhI~
{                                                                  //~v6f3I~
//  int rc=1,rc2,chklen,outlen,opt;                                    //~v6f3I~//~v6f7R~//~v6foR~
    int rc=1,rc2,chklen;                                           //~v6foI~
//  char mbs1[1],mbs2[1];                                          //~v6f3I~//~v6foR~
    char mbs1[1];                                                  //~v6foR~
    UWUCS ucs;                                                     //~v6f3I~
//***********************                                          //~v6f3I~
    *mbs1=(char)Pucs;                                              //~v6f3I~
    rc2=ucvext_icumb2ucs1(0,Pconverters[ICULCPL_CONVERTER],mbs1,1,&chklen,&ucs);       //~v6f3R~//~v6f7R~
    if (rc2||chklen!=1)                                            //~v6f3I~
    	rc=0;	//unprintable                                      //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
//  	rc2=ucvext_icuucs2mb1(0,Pconverter,ucs,mbs2,&outlen);      //~v6f3R~//~v6f7R~
//  	opt=UCVEXTO_SETSUBCHRC;                                    //~v6f7R~//~v6foR~
//  	rc2=ucvext_icuucs2mb1(opt,Pconverters,ucs,mbs2,&outlen);   //~v6f7R~//~v6foR~
//      if (rc2||outlen!=1||*mbs2!=*mbs1)                          //~v6f3I~//~v6foR~
        if (ucs==UDBCSCHK_SUBCHAR_SBCS)                            //~v6foI~
        	rc=0;                                                  //~v6f3I~
    }                                                              //~v6f3I~
    UTRACEP("ucvext_icuisprint opt=%x,ucs=%x,rc=%d,converter=%x\n",Popt,Pucs,rc,Pconverters);//~v6fnR~
    return rc;                                                     //~v6f3I~
}//ucvext_icuisprint                                               //~v6f3I~
//**************************************************************** //~v6f3I~
// chk char is dbcs  using ICU                                     //~v6f3I~
//ret -2:inmatured dbcs,-1:invalid dbcs                            //~v6f7I~
//**************************************************************** //~v6f3I~
//int ucvext_locale1ICU(int Popt,ULONG Pconverter,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs)//~v6f3I~//~v6hhR~
int ucvext_locale1ICU(int Popt,ULPTR Pconverter,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs)//~v6hhI~
{                                                                  //~v6f3I~
  	int readlen=1,rc=0,rc2;                                        //~v6f3I~
    UWUCS ucs=0;                                                     //~v6f3I~//~v6h6R~
//****************************                                     //~v6f3I~
    rc2=udbcschk_locale_topbyte(*Pstr);	//leadbyte?	               //~v6f3I~
    if (rc2)                                                       //~v6f3I~
    {                                                              //~v6f3I~
    	if (Plen==1)                                               //~v6f3I~
        	rc=-2;	//inmatured                                    //~v6f7R~
        else                                                       //~v6f3I~
        {                                                          //~v6f7I~
	    	if (ucvext_icumb2ucs1(UCVEXTO_SETSUBCHRC,Pconverter,Pstr,Plen,&readlen,&ucs))//~v6f7R~
            	rc=-1;                                             //~v6f7I~
        }                                                          //~v6f7I~
    }                                                              //~v6f3I~
    if (Ppucs)                                                     //~v6f3I~
        *Ppucs=ucs;                                                //~v6f3I~
    if (Ppreadlen)                                                 //~v6f3I~
    	*Ppreadlen=readlen;                                        //~v6f3I~
	return rc;                                                     //~v6f3I~
}//ucvext_locale1ICU                                               //~v6f3I~
//*************************************************************************//~v6f4I~
//*get converter for a2a and dbcs flag                             //~v6f4I~
//*parm:converters:cvto,cvfrom,dbcstbl for cpfrom                  //~v6f4I~
//*ret 1:dbcs codepage,4 err                                       //~v6f4R~
//*************************************************************************//~v6f4I~
//int ucvext_getparmconvertermbICU(int Popt,char *Pcpfrom,char *Pcpto,ULONG *Ppconverters)//~v6f4R~//~v6hhR~
int ucvext_getparmconvertermbICU(int Popt,char *Pcpfrom,char *Pcpto,ULPTR *Ppconverters)//~v6hhI~
{                                                                  //~v6f4I~
    char *pcpfrom,*pcpto;                                          //~v6f4R~
#ifdef LNX                                                         //~v6heI~
    UCHAR *pdbcstb,*parmdbcstb;                                    //~v6f4R~
#else                                                              //~v6heI~
    UCHAR *parmdbcstb;                                             //~v6heI~
#endif                                                             //~v6heI~
    int dbcssw,ctype,subchsz,opt;                                  //~v6f4R~
#ifdef LNX                                                         //~v6heI~
    ULONG cvfrom,cvto,pconverters;                                 //~v6f4R~
#else                                                              //~v6heI~
//  ULONG cvfrom,cvto;                                             //~v6heI~//~v6hhR~
    ULPTR cvfrom,cvto;                                             //~v6hhI~
#endif                                                             //~v6heI~
    char subch[4];                                                 //~v6f4I~
    int swopenedf=0,swopenedt=0;                                   //~v6f4R~
//**********************                                           //~v6f4I~
	parmdbcstb=(UCHAR*)Ppconverters[HICONV_DBCSSTARTER];           //~v6f4R~
    memset(parmdbcstb,0,256);                                      //~v6f4I~
	if (!Pcpfrom || !*Pcpfrom)                                     //~v6f4I~
    	pcpfrom=0;                                                 //~v6f4I~
    else                                                           //~v6f4I~
        pcpfrom=Pcpfrom;                                           //~v6f4I~
	if (!Pcpto || !*Pcpto)                                         //~v6f4I~
    	pcpto=0;                                                   //~v6f4I~
    else                                                           //~v6f4I~
        pcpto=Pcpto;                                               //~v6f4I~
    if (!pcpfrom && !pcpto)                                        //~v6f4I~
    {                                                              //~v6f4I~
    	uerrmsg("%cF:codepage or %cT:codepage option is require for M2M",0,//~v6f4I~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~v6f4I~
        return 8;                                                  //~v6f4I~
    }                                                              //~v6f4I~
	if (!pcpfrom)                                                  //~v6f4I~
    {                                                              //~v6f4I~
#ifdef LNX                                                         //~v6f4I~
	  if (!UDBCSCHK_IS_LOCALICU() || udbcschk_getbaseconverter(0,&pconverters,&pdbcstb))//~v6f4R~
#endif                                                             //~v6f4I~
      {                                                            //~v6f4I~
    	uerrmsg("%cF:codepage option is require for M2M with ICU option",0,//~v6f4I~
			CMDFLAG_PREFIX);                                       //~v6f4I~
        return 8;                                                  //~v6f4I~
      }                                                            //~v6f4I~
#ifdef LNX                                                         //~v6heI~
      cvfrom=*(ULONG*)pconverters;                                 //~v6f4R~
      swopenedf=1;                                                 //~v6f4R~
  	  dbcssw=(ucvext_icugetconvertertype(UCEIO_OPENED,cvfrom,&ctype)==UCEIRC_MBCS);//~v6f4I~
      memcpy(parmdbcstb,pdbcstb,256);                              //~v6f4I~
#endif                                                             //~v6heI~
    }                                                              //~v6f4I~
    else                                                           //~v6f4I~
    {                                                              //~v6f4I~
		if (ucvext_icugetmbconverter(Popt,pcpfrom,&cvfrom))        //~v6f4I~
    		return 8;                                              //~v6f4I~
//		dbcssw=(ucvext_icugetconvertertype(UCEIO_OPENED,(ULONG)cvfrom,&ctype)==UCEIRC_MBCS);//~v6x5R~
  		dbcssw=(ucvext_icugetconvertertype(UCEIO_OPENED,cvfrom,&ctype)==UCEIRC_MBCS);//2nd parm prototype is ULPTR//~v6x5I~
  		if (ctype==UCNV_UTF8)                                      //~v6f4I~
    		dbcssw=0;                                              //~v6f4I~
  		else                                                       //~v6f4I~
        {                                                          //~v6f4I~
			opt=UCEIO_OPENED|UCEIO_MBICU;                          //~v6f4R~
			if (ucvext_icugetstarter(opt,cvfrom,parmdbcstb))//err  //~v6f4I~
    			dbcssw=0;                                          //~v6f4I~
        }                                                          //~v6f4I~
    }                                                              //~v6f4I~
	if (!pcpto)                                                    //~v6f4I~
    {                                                              //~v6f4I~
#ifdef LNX                                                         //~v6f4I~
	  if (!UDBCSCHK_IS_LOCALICU() || udbcschk_getbaseconverter(0,&pconverters,0/*pdbcstb*/))//~v6f4R~
#endif                                                             //~v6f4I~
      {                                                            //~v6f4I~
    	uerrmsg("%cT:codepage option is require for M2M with ICU option",0,//~v6f4I~
			CMDFLAG_PREFIX);                                       //~v6f4I~
        if (swopenedf)                                             //~v6f4R~
            ucvext_icuclose(0,cvfrom);                             //~v6f4I~
        return 8;                                                  //~v6f4I~
      }                                                            //~v6f4I~
#ifdef LNX                                                         //~v6heI~
      cvto=*(ULONG*)pconverters;                                   //~v6f4R~
#endif                                                             //~v6heI~
    }                                                              //~v6f4I~
    else                                                           //~v6f4I~
    {                                                              //~v6f4I~
		if (ucvext_icugetmbconverter(Popt,pcpto,&cvto))            //~v6f4I~
        {                                                          //~v6f4I~
        	if (swopenedf)                                         //~v6f4R~
            	ucvext_icuclose(0,cvfrom);                         //~v6f4I~
    		return 8;                                              //~v6f4R~
        }                                                          //~v6f4I~
      swopenedt=1;                                                 //~v6f4R~
    }                                                              //~v6f4I~
	Ppconverters[HICONV_CPTO]=cvto;                                //~v6f4I~
	Ppconverters[HICONV_CPFROM]=cvfrom;                            //~v6f4I~
UTRACEP("ucvext_getparmconvertermbICU to=%x,from=%x\n",cvto,cvfrom);//~v6f4R~
	subchsz=sizeof(subch);                                         //~v6f4I~
	if (!ucvext_icugetsubchars(UCEIO_OPENED,cvto,subch,&subchsz))  //~v6f4R~
//  	UmemcpyZ((char*)(Ppconverters+HICONV_SUBCHTO),subch,subchsz);//~v6f4R~//~v6BkR~
    	UmemcpyZ((char*)(Ppconverters+HICONV_SUBCHTO),subch,(size_t)subchsz);//~v6BkI~
    else                                                           //~v6f4I~
    	strcpy((char*)(Ppconverters+HICONV_SUBCHTO),"?");          //~v6f4I~
	if (!ucvext_icugetsubchars(UCEIO_OPENED,cvfrom,subch,&subchsz))//~v6f4R~
//    	UmemcpyZ((char*)(Ppconverters+HICONV_SUBCHFROM),subch,subchsz);//~v6f4R~//~v6BkR~
      	UmemcpyZ((char*)(Ppconverters+HICONV_SUBCHFROM),subch,(size_t)subchsz);//~v6BkI~
    else                                                           //~v6f4I~
    	strcpy((char*)(Ppconverters+HICONV_SUBCHFROM),"?");        //~v6f4I~
//  Ppconverters[HICONV_CLOSETO]=swopenedt;                        //~v6f4I~//~v6BkR~
    Ppconverters[HICONV_CLOSETO]=(ULPTR)swopenedt;                 //~v6BkI~
//  Ppconverters[HICONV_CLOSEFROM]=swopenedf;                      //~v6f4I~//~v6BkR~
    Ppconverters[HICONV_CLOSEFROM]=(ULPTR)swopenedf;               //~v6BkI~
UTRACED("ucvext_getparmconveretrmbICU starter",parmdbcstb,256);    //~v6f4R~
    return dbcssw;                                                 //~v6f4I~
}//ucvext_getparmconvertermbICU                                    //~v6f4R~
//*************************************************************************//~v6f4I~
//*init to use ucvext_a2as by ICU                                  //~v6f4I~
//*Pcpfrom:cv from(current if 0)                                   //~v6f4I~
//*Pcpto  :cv to  (current if 0)                                   //~v6f4I~
//*Ppbcsflag:output dbcs leadbyte flag[256]                        //~v6f4I~
//*Ppopt:FROMUTF8 is conditionaly ORed                             //~v6f4I~
//*Ppconverter:converter output ULONG[7]                           //~v6f4I~
//*************************************************************************//~v6f4I~
//int ucvext_icua2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULONG *Pconverters)//~v6f4I~//~v6hhR~
int ucvext_icua2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULPTR *Pconverters)//~v6hhI~
{                                                                  //~v6f4I~
    int opt,ctype;                                                 //~v6f4I~
//  ULONG *pconverters;                                            //~v6f4I~//~v6hhR~
    ULPTR *pconverters;                                            //~v6hhI~
//***************************                                      //~v6f4I~
	ucvext_icumbinit(UCEIMIO_ENVINIT,0/*Pcharset*/,0/*Ppconverter*/);//~v6f4R~
	opt=Popt;                                                      //~v6f4R~
    pconverters=Pconverters;                                       //~v6f4I~
//	pconverters[HICONV_DBCSSTARTER]=(ULONG)Pdbcsflag;	//[3]:parm to iconv getconverter//~v6f4I~//~v6hhR~
	pconverters[HICONV_DBCSSTARTER]=(ULPTR)Pdbcsflag;	//[3]:parm to iconv getconverter//~v6hhI~
	if (ucvext_getparmconvertermbICU(opt,Pcpfrom,Pcpto,pconverters)>1)//~v6f4R~
    	return 8;                                                  //~v6f4I~
  	ucvext_icugetconvertertype(UCEIO_OPENED,pconverters[HICONV_CPFROM],&ctype); //[1]//~v6f4I~
  	if (ctype==UCNV_UTF8)                                          //~v6f4I~
    	opt|=UCVEXTO_FROMUTF8;                                     //~v6f4I~
    *Ppopt=opt;                                                    //~v6f4I~
    UTRACEP("ucvext_icua2ainit opt in=%x,out=%x\n",Popt,opt);      //~v6f4I~
    UTRACED("out converter",Pconverters,7*sizeof(ULONG));          //~v6f4I~
    return 0;                                                      //~v6f4I~
}//ucvext_icua2ainit                                               //~v6f4I~
//*************************************************************************//~v6f4I~
//*close a2a ICU converter                                         //~v6f4I~
//*************************************************************************//~v6f4I~
//int ucvext_icua2aterm(int Popt,ULONG *Ppconverters)                //~v6f4R~//~v6hhR~
int ucvext_icua2aterm(int Popt,ULPTR *Ppconverters)                //~v6hhI~
{                                                                  //~v6f4I~
//***************************                                      //~v6f4I~
	if (Ppconverters[HICONV_CLOSETO])                              //~v6f4R~
    	ucvext_icuclose(0,Ppconverters[HICONV_CPTO]);              //~v6f4R~
	if (Ppconverters[HICONV_CLOSEFROM])                            //~v6f4R~
    	ucvext_icuclose(0,Ppconverters[HICONV_CPFROM]);            //~v6f4R~
    UTRACED("ucvext_icua2aterm opt converters",Ppconverters,7*sizeof(ULONG));//~v6f4I~
    return 0;                                                      //~v6f4I~
}//ucvext_icua2ainit                                               //~v6f4I~
//*************************************************************************//~v6f4I~
//*translate by ICU for M2M                                        //~v6f4I~
//*   should return from end of func(Gpdbcstbl/Gudbcschk_flag is temporary modified)//~v6f4I~
//*************************************************************************//~v6f4I~
//int ucvext_icua2as(int Popt,ULONG *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,ULONG Pferr,int Perrrep,int *Pprepctr)//~v6f4R~//~v6hhR~
int ucvext_icua2as(int Popt,ULPTR *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,ULPTR Pferr,int Perrrep,int *Pprepctr)//~v6hhR~
{                                                                  //~v6f4I~
	UCVUCS_FERR *errcbfunc;                                        //~v6f4I~
//  int rc=0,outlen,reslen,repch,repchdbcs,repchdbcs1,repchdbcs2,chklen,rc2,opt,dbcssw;//~v6f4I~//~v6h7R~
    int rc=0,outlen=0,reslen,repch,repchdbcs,repchdbcs1,repchdbcs2,chklen,rc2,opt,dbcssw;//~v6h7I~
    UCHAR *pci,*pco,*pce,*pcoe;                                    //~v6f4I~
    UWUCS   wkucs[2];                                              //~v6f4I~
    UCHAR *pdbcsstarter;                                           //~v6f4I~
//  ULONG hiconv_from,hiconv_to;                                   //~v6f4I~//~v6hhR~
    ULPTR hiconv_from,hiconv_to;                                   //~v6hhI~
    int repctr=0,errrepsw,readlen,ch;                              //~v6f4R~
	int mblen;                                                     //~v6f4I~
    char *subch;                                                   //~v6f4I~
//  ULONG pconverters[2];                                          //~v6f4I~//~v6foR~//~v6fpR~//~v6hhR~
    ULPTR pconverters[2];                                          //~v6hhI~
//    ULONG pconverters[3];                                          //~v6foI~//~v6fpR~
//***************************                                      //~v6f4I~
UTRACEP("ucvext_icua2as errrep=%x,opt=%x\n",Perrrep,Popt);         //~v6f4I~
UTRACED("ucvext_icui2as input",Pinp,Pinplen);                      //~v6f4I~
	errcbfunc=(UCVUCS_FERR *)Pferr;                                //~v6f4I~
    hiconv_to=Pconverters[HICONV_CPTO];         //[0]              //~v6f4R~
    hiconv_from=Pconverters[HICONV_CPFROM];     //[1]              //~v6f4R~
    pdbcsstarter=(UCHAR*)Pconverters[HICONV_DBCSSTARTER];//[2]     //~v6f4R~
UTRACED("ucvext_icua2as dbcsstarter",pdbcsstarter,256);            //~v6f4I~
    opt=Popt&~EBC2ASC_STAT_SO;  //source is dbcs                   //~v6f4I~
    opt|=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN;   //consider >2 byte dbcs for STAT_SO flag//~v6f4I~
	opt|=UCVEXTO_SETSUBCHRC;                                       //~v6f4I~
	repch=(Perrrep & 0xff);                                        //~v6f4I~
    repchdbcs=Perrrep>>8;                                          //~v6f4I~
    subch=(char*)(Pconverters+HICONV_SUBCHTO);                     //~v6f4I~
    if (!repch)                                                    //~v6f4I~
    {                                                              //~v6f4I~
        repch='?';                                                 //~v6f4I~
		if (*subch && !*(subch+1))	//sbcs subchar defined         //~v6f4I~
    		repch=*subch;                                          //~v6f4I~
    }                                                              //~v6f4I~
    if (!repchdbcs)                                                //~v6f4I~
    {                                                              //~v6f4I~
		if (*subch && *(subch+1))                                            //~v6f4I~//~v6f7R~
    		repchdbcs=(*subch<<8)+*(subch+1);                      //~v6f4I~
        else                                                       //~v6f4I~
    		repchdbcs=(*subch<<8)+*(subch);                        //~v6f7I~
    }                                                              //~v6f4I~
    repchdbcs2=repchdbcs & 0xff;                                   //~v6f4I~
    repchdbcs1=repchdbcs>>8;                                       //~v6f4I~
	for (pci=Pinp,pce=pci+Pinplen,pco=Pout,pcoe=pco+Poutbuffsz;pci<pce;pci+=chklen)//~v6f4I~
    {                                                              //~v6f4I~
    	if (pco>=pcoe)                                             //~v6f4I~
        {                                                          //~v6f4I~
        	rc=8;                                                  //~v6f4I~
            break;                                                 //~v6f4I~
        }                                                          //~v6f4I~
    	ch=*pci;                                                   //~v6f4I~
		if (UTF8ISASCII(ch))	//chof setup                       //~v6f4I~
        {                                                          //~v6f4I~
        	chklen=1;                                              //~v6f4I~
//      	*pco++=ch;                                             //~v6f4I~//~v6BiR~
        	*pco++=(UCHAR)ch;                                      //~v6BiI~
            continue;                                              //~v6f4I~
        }                                                          //~v6f4I~
//    	reslen=(int)((ULONG)pce-(ULONG)pci);                       //~v6f4I~//~v6hhR~
    	reslen=(int)((ULPTR)pce-(ULPTR)pci);                       //~v6hhI~
      dbcssw=0;                                                    //~v6h8I~
      if (Popt & UCVEXTO_FROMUTF8)                                 //~v6f4I~
        mblen=UTF8CHARLENERR1(*pci);                               //~v6f4I~
      else                                                         //~v6f4I~
      {                                                            //~v6f4I~
    	dbcssw=(pdbcsstarter && (pdbcsstarter[*pci] & UDBCSCHK_TYPEDBCS));//~v6f4I~
    	if (dbcssw)                                                //~v6f4I~
        {                                                          //~v6f4I~
			if (MAYBESS3(*pci))                                    //~v6f4I~
            	mblen=UDBCSCHK_SS3SZ;                              //~v6f4I~
            else                                                   //~v6f4I~
			if (reslen>1 && UDBCSCHK_ISGB42ND(*(pci+1)))           //~v6f4I~
            	mblen=UDBCSCHK_GB4SZ;                              //~v6f4I~
            else                                                   //~v6f4I~
            	mblen=UDBCSCHK_DBCSSZ;                             //~v6f4I~
            mblen=min(reslen,mblen);                               //~v6f4I~
            if (reslen==1)                                         //~v6f4I~
            	if (Popt & EBC2ASC_LNCONT)  //continue line        //~v6f4I~
                	break;                                         //~v6f4I~
        }                                                          //~v6f4I~
	    else                                                       //~v6f4I~
			mblen=1;                                               //~v6f4I~
	  }                                                            //~v6f4I~
        errrepsw=0;                                                //~v6f4I~
		rc2=ucvext_icumb2ucs1(opt,hiconv_from,pci,mblen,&chklen,wkucs);//~v6f4R~
        //*0x1a of 0xfffd is put for not defined code point        //~v6f4I~
        if (rc2==UCEICL2U1ORC_DBCSSPLIT	//           -11           //~v6f4I~
 		&&  Popt & EBC2ASC_LNCONT) //continue line                 //~v6f4I~
        	break;	//if EBC2ASC_LNCONT returns chklen as required len with err rc//~v6f4I~
        if (rc2)    //no byte translation success                  //~v6f4I~
        {                                                          //~v6f4I~
            chklen=mblen;   //err for all input byte               //~v6f4I~
            errrepsw=1;                                            //~v6f4I~
//          if (mblen==1)                                          //~v6f4I~//~v6f7R~
//          	if (repch)                                         //~v6f4I~//~v6f7R~
//              	wkucs[0]=repch;//ascii                         //~v6f4I~//~v6f7R~
//              else                                               //~v6f4I~//~v6f7R~
//              	wkucs[0]=UDBCSCHK_SUBCHAR_SBCS;                //~v6f4I~//~v6f7R~
//          else                                                   //~v6f4I~//~v6f7R~
//              wkucs[0]=UDBCSCHK_SUBCHAR_DBCS;                    //~v6f4I~//~v6f7R~
        }                                                          //~v6f4I~
//      rc2=ucvext_icuucs2mb1(opt,hiconv_to,wkucs[0],pco,&outlen); //~v6f4R~
		pconverters[ICULCPL_CONVERTER]=hiconv_to;                  //~v6f4I~
//		pconverters[ICULCPL_SUBCH]=(ULONG)(Pconverters+HICONV_SUBCHFROM);//~v6f4I~//~v6f7R~//~v6hhR~
		pconverters[ICULCPL_SUBCH]=(ULPTR)(Pconverters+HICONV_SUBCHFROM);//~v6hhI~
//  	pconverters[ICULCPL_SUBCHLEN]=strlen((char*)Pconverters[ICULCPL_SUBCH]);//~v6foI~//~v6fpR~
      if (!rc2)                                                    //~v6f7I~
        rc2=ucvext_icuucs2mb1(opt,pconverters,wkucs[0],pco,&outlen);//~v6f4I~//~v6f7R~
        //*subchar1 subchar is set for not defined codepoint       //~v6f4I~
//      if (!rc2 && dbcssw && outlen==1)  hankana sjis is 1 byte   //~v6f4R~
//        	rc2=4;                                                 //~v6f4R~
        if (rc2)                                                   //~v6f4I~
        {                                                          //~v6f4I~
        	errrepsw=1;                                            //~v6f4I~
//UTRACEP("ERR icua2as dbcssw=%d,ucs=%04x errrep=%x,pci=%02x\n",dbcssw,wkucs[0],Perrrep,*pci);//~v6f4I~//~v6h7R~
            if (dbcssw)                                            //~v6f4I~
            {                                                      //~v6f4I~
            	if (repchdbcs)                                     //~v6f4I~
                {                                                  //~v6f4I~
//              	*pco++=repchdbcs1;                             //~v6f4I~//~v6BiR~
                	*pco++=(UCHAR)repchdbcs1;                      //~v6BiI~
//              	*pco++=repchdbcs2;                             //~v6f4I~//~v6BiR~
                	*pco++=(UCHAR)repchdbcs2;                      //~v6BiI~
                }                                                  //~v6f4I~
                else                                               //~v6f4I~
                {                                                  //~v6f4I~
//              	*pco++=repch;                                  //~v6f4I~//~v6BiR~
                	*pco++=(UCHAR)repch;                           //~v6BiI~
//              	*pco++=repch;                                  //~v6f4I~//~v6BiR~
                	*pco++=(UCHAR)repch;                           //~v6BiI~
                	if (chklen>UDBCSCHK_DBCSSZ)                    //~v6f4I~
//                  	*pco++=repch;                              //~v6f4I~//~v6BiR~
                    	*pco++=(UCHAR)repch;                       //~v6BiI~
                	if (chklen==UDBCSCHK_GB4SZ)                    //~v6f4I~
//                  	*pco++=repch;                              //~v6f4I~//~v6BiR~
                    	*pco++=(UCHAR)repch;                       //~v6BiI~
                }                                                  //~v6f4I~
            }                                                      //~v6f4I~
            else                                                   //~v6f4I~
            {                                                      //~v6f4I~
        		chklen=1;                                          //~v6f4I~
//          	*pco++=repch;                                      //~v6f4I~//~v6BiR~
            	*pco++=(UCHAR)repch;                               //~v6BiI~
            }                                                      //~v6f4I~
        }                                                          //~v6f4I~
        else                                                       //~v6f4I~
        {                                                          //~v6f4I~
        	pco+=outlen;                                           //~v6f4I~
        }                                                          //~v6f4I~
        if (errrepsw)                                              //~v6f4I~
        {                                                          //~v6f4I~
	        repctr++;                                              //~v6f4I~
        	if (errcbfunc)                                         //~v6f4R~
//	            errcbfunc(UCVUCS_CONVERR,Pinplen-reslen,(int)((ULONG)pco-(ULONG)Pout-chklen),Pinp,chklen);//~v6f4R~//~v6hhR~
//	            errcbfunc(UCVUCS_CONVERR,Pinplen-reslen,(int)((ULPTR)pco-(ULPTR)Pout-chklen),Pinp,chklen);//~v6hhI~//~v6BkR~
  	            errcbfunc(UCVUCS_CONVERR,Pinplen-reslen,PTRDIFF(pco,Pout)-chklen,Pinp,chklen);//~v6BkI~
        }                                                          //~v6f4I~
    }                                                              //~v6f4I~
//  outlen=(int)((ULONG)pco-(ULONG)Pout);                          //~v6f4I~//~v6hhR~
    outlen=(int)((ULPTR)pco-(ULPTR)Pout);                          //~v6hhI~
//  readlen=(int)((ULONG)pci-(ULONG)Pinp);                         //~v6f4I~//~v6hhR~
    readlen=(int)((ULPTR)pci-(ULPTR)Pinp);                         //~v6hhI~
    if (Ppoutlen)                                                  //~v6f4I~
        *Ppoutlen=outlen;                                          //~v6f4I~
    if (Pprepctr)                                                  //~v6f4I~
        *Pprepctr=repctr;                                          //~v6f4I~
    if (Ppreadlen)                                                 //~v6f4I~
        *Ppreadlen=readlen;                                        //~v6f4I~
    if (errcbfunc)                                                 //~v6f4R~
	    errcbfunc(0,readlen,outlen,Pinp,0);                        //~v6f4R~
UTRACEP("ucvext_icua2as rc=%d,chklen=%d,errctr=%d,outlen=%d\n",rc,readlen,repctr,outlen);//~v6f4I~
UTRACED("ucvext_icua2as out",Pout,outlen);                         //~v6f4I~
    return rc;                                                     //~v6f4I~
}//ucvext_icua2as                                                  //~v6f4I~
//*****************************************************************************//~v6hhI~
//*interface to ucvext_icusubcharchk with handle                   //~v6hhI~
//*****************************************************************************//~v6hhI~
//int ucvext_icusubcharchk_handle(int Popt,int Phandle,WUCS Pucs,UCHAR *Pstr,int Plen)//~v6hhI~//~v6BjR~
int ucvext_icusubcharchk_handle(int Popt,int Phandle,UWUCS/*ucs4*/ Pucs,UCHAR *Pstr,int Plen)//~v6BjI~
{                                                                  //~v6hhI~
	int opt;                                                       //~v6hhI~
//********************                                             //~v6hhI~
	opt=Popt|(Phandle<<UCVEXTISCO_HANDLEMASKSHIFT);                //~v6hhI~
	return ucvext_icusubcharchk(opt,Pucs,Pstr,Plen);               //~v6hhR~
}                                                                  //~v6hhI~
#endif //WIN/LNX
