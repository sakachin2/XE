//*CID://+v6HiR~:                                   update#=  698; //~v6HiR~
//***********************************************************************
//v6Hi:170118 (Win:BUG)buff overflow was not checked               //~v6HiI~
//v6E1:160718 (W32)WideCharToMultiByte dose not set err            //~v6E1I~
//            cv F8F0->a0,F8F1->fd,F8F2->fe,F8F3->ff and it is reversible//~v6E1I~
//            not by v6E0 but chk reversible by MB_ERR_INVALID_CHARS//~v6E1I~
//v6BI:160307 WideCharToMultiByter returns 87(ERROR_INVALID_PARAMETER) for other than GB18030, set NULL to ereeflag parm//~v6BII~
//v6BH:160307 MultiByteToWideChar returns 1004(ERROR_INVALID_FLAGS) for other than GB18030, codepage type sbcs may cause it.//~v6BHI~
//v6BF:160306 (WIN:BUG)WideCharToMultibyte parm err(lasterr=87) if opt!=0 for GB18030//~v6BFI~//~v6BHR~
//v6BA:160303 W32:wcstombs and mbrtowc dose not support surrogate pair,use WIdeChar<-->Multibute api//~v6BAI~//~v6BHM~
//v6By:160212 (W32)compiler warning at w7                          //~v6ByI~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bs:160222 (W32)MultiByteToWideChar fail by 1004(ERROR_INVALID_FLAGS) for GB18030 and dose not indicate err (rplace by "?")//~v6BsI~
//v6Br:160222 (W32)support GB18030(4byte dbcs) by ucvext_iconvlocal2ucs1//~v6BrI~
//v6Bq:160222 (W32;Bug)UCVUCS_LOCALCV is off from ucvext_iconvucs2ebc1,on from ucvext_iconvucs2local1.//~v6BqI~
//v6Bp:160222 (W32)WideCharToMultibyte return bytectr=0 for surrogate pair under CP:GB18030(cp:54936)//~v6BpI~
//v6Bo:160221 (W32)MultiByteToWideChar return ucsctr>1 when surrogate,it is not error(case of ebc2ucs)//~v6BoI~
//v6Bn:160221 (W32)confirm Spcfg!=NULL to avoid 0c4                //~v6BnI~
//v6Bm:160221 (W32)WideCharToMultibyte set 2 subchar for surrogate pair;UCVUCS_SETSUBCHRC was not returned for surrogate pair//~v6BmI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6x8:150110 (warning C4244) not about ULPTR                      //~v6x8I~
//v6xa:150111 more easy err msg for windows codepage err,add "try icu"//~v6xaI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uM:140606 (LNX:BUG)F2L/U2L trans 0xff>=.. 0x=>80 to hankaku katakana is iconv BUG?,back trans is ffxx for han-kana//~v6uMI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6ueI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6r4:131221 (WIN:BUG)did not cv utf8 to sarrogate pair           //~v6r4I~
//v6r3:131221 (WIN:BUG)Assetion;used uninitialized variable        //~v6r3I~
//v6r2:131217 (WIN:BUG)ucvext_wincp2ucss requires LE/BE option when converter=CP_UTF8;prepare for the case windows codepage=UTF8//~v6r2I~
//v6r1:131217 (WIN:BUG)WideCharToMultibyte parm err(lasterr=87) if last 2 parm(defaultchar,usedDefaultchar) is not null.//~v6r1I~
//v6m2:130725 (BUG)EBC2ASC_IBM(x20) and UCVEXTO_TOUTF8 conflict occured//~v6m2I~
//            xprint ucvebc3_b2m translate to utf8 when no cfg found(default IBM option)//~v6m2I~
//            IBM/NEC is for the case of using internal mapp       //~v6m2I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning(C4057)                           //~v6hdI~
//v6h8:120609 (BUG)by chk c4701 warning by VC6(used uninitialized variable)//~v6h8I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6fr:120506 (BUG)avoid xcv core when -f:/t: is missing for m2m   //~v6frI~
//v6fq:120506 (Win:BUG)WideCharToMultiByte faile if flag is WC_NO_BEST_FIT_CHARS(0x400)  for UTF8//~v6fqI~
//v6f6:120420 suport M2M by ICU for xcv                            //~v6f6I~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v6bg:111210 (WIN:BUG) -f:utf8 of M2M was ignored(evaluated as locale)//~v6bgI~
//v6bf:111209 errmsg when a2af codepage err                        //~v6bfI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v69u:100903 b2b support for xcv(a2a is not proper for dbcs converter because dbcsstarter is null for ebc)//~v69uI~
//v69g:100819 (W32)list available codepage if "/C?" option specified//~v69gI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v66Y:100614 (LNX)dbcsenv for local converter to allow b2m output is dbcs//~v66YI~
//v66V:100613 (LNX:BUG)iconv returm rc=0 with outlen=0 for 0x0e    //~v66VI~
//v66Q:100612 (BUG)windows ucs2cp set "?"(SBCS) for DBCS-ucs       //~v66QI~
//v66N:100611 ebc-b9->u178 is err if reverse chk,allow not reversible for b2u//~v66NI~
//            this is 1:n but not the case of subchar.             //~v66NI~
//v66D:100604 indicate SUBCHAR was set by rc                       //~v66DI~
//v66A:100602 hankana is 2byte byt ebc sbcs                        //~v66AI~
//v66t:100531 (Win:BUG)better to use pre-comosite char(not 2 byte but 1 byte for such as E-umlaut)//~v66tI~
//            translation fail if compositechk on sometimes        //~v66tI~
//v66j:100528 (BUG of UCS4 support) not changed USHORT to WUCS for ebcdic conversion//~v66jI~
//v65j:100327 (WinCons)MultiByteToWideChar fail by GetLastError=1004(invalid flag) when opt!=0 for GB18030(CP50935);tested chcp 50935 on dos prompt//~v65jI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v632:091114 (UTF8:WIN:BUG) WideCharToMultiByte return without errrep flag for ucs 0xc0.//~v630I~
//            NO_BEST_FIT_CHARS is compile err,it require WINVER>=500, but flag 0x400 is effective//~v630I~
//v630:091113 (UTF8:WIN:BUG)no err return when valid utf but f2l err.//~v630I~
//            no need to winucs2cp1 like as linux iconv, this is 1 char function//~v630I~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62N:091013_(LNX:BUG)l2f1 should chk only 1 char(iconv translate multiple. 4byte dbcs may translated to 2 dbcs by another iconv handle)//~v62NI~
//v62E:091003_(WIN)f2l support err ret for WideToMultiByte          //~v62EI~//~v62NR~
//v624:090712 compile err on Z390(reported by Dirk@...de)          //~v624I~
//v621:090511 add ucvext_a2ainit                                   //~v621I~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5n8I~
//v5n9:080916 duplicated errmsg for win codepage                   //~v5n9I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n7:080913*(Lnx)support UTF8 /f: of m2m                         //~v5n7I~
//v5n6:080913 (Win:BUG)WideCharToMultibyte fail when errch parm specified//~v5n5I~
//v5n5:080907 GB18030(CP-54936) Windows CPinfo has no defined leadbyte//~v5n5I~
//v5n3:080904 cv cmd m2m support                                   //~v5n3I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5mT:080817 EBCS translation for linux using iconv               //~v5mTI~
//***********************************************************************
//* ucvext2.c                                                      //~v5mTR~
//* ebc conversion using iconv                                     //~v5mTR~
//***********************************************************************
//#if defined(LNX)                                                 //~v5n1R~
#if defined(W32) || defined(LNX)                                   //~v5n1I~
//***********************************************************************
#ifdef W32                                                         //~v5n1M~
    #include <windows.h>                                           //~v5n1M~
    #include <winnls.h>                                            //~v5n1M~
    #include <wchar.h>                                             //~v6BsI~
#endif                                                             //~v5n1M~

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef LNX                                                         //~v5n1I~
#include <iconv.h>                                                 //~v5mTI~
#else                                                              //~v5n1I~
    typedef unsigned long iconv_t;                                 //~v5n1R~
#endif                                                             //~v5n1I~
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
#include <ustring.h>
#include <ucvucs.h>                                                //~v5n3I~
#include <ucvebc.h>
#include <ucvext.h>
#include <ucvebc4.h>                                               //~v69gI~
#include <ucvext2.h>                                               //~v5mTI~
#include <ufile.h>
#include <ufile5.h>                                                //~v5n1I~
#include <ufemsg.h>
#include <utrace.h>
#include <utf.h>                                                   //~v5n3I~
#include <utf22.h>                                                 //~v6BjI~
//*******************************************************
#ifdef UTF8UCS4                                                    //~v65cI~
    #ifdef BIGENDIAN                                               //~v65cI~
		#define  ENCODING_UCS2  "UCS-4BE"                          //~v65cI~
    #else                                                          //~v65cI~
		#define  ENCODING_UCS2  "UCS-4LE"                          //~v65cI~
    #endif                                                         //~v65cI~
	#define  ENCODING_UCS2_2    "UCS-4"                            //~v6a0I~
#else                                                              //~v65cI~
#define  ENCODING_UCS2  "UCS2"                                     //~v5mTR~
#endif                                                             //~v65cI~
#define  ENCODING_UTF8  "UTF8"                                     //~v5n6I~
#define  ENCODING_UTF_8 "UTF-8"                                    //~v5n6I~
#define  HICONV_TOUCS       0     //index                          //~v5n1R~
#define  HICONV_FROMUCS     1     //index                          //~v5n1R~
                                                                   //~v5mtI~
//*******************************************************          //~v5mTI~
#ifdef W32                                                         //~v6E1I~
int uWideCharToMultiByte_reversechk(int Popt,ULONG Pconverter,int Papiopt,WUCS/*int2*/*Ppucs,int Pucsctr,UCHAR *Ppmbs,int *Ppmbctr,char *Pdefaultchars,int *Ppdefaultused,int *Pplasterr);//~v6E1R~
#endif                                                             //~v6E1I~
//*******************************************************          //~v5n1I~
static PUCVEXTCFG Spcfg;                                           //~v5mTI~
static int        Sextflag;                                        //~v5mTR~
static UCVUCS_FERR *Serrcbfunc;                                    //~v5n3I~
//*******************************************************          //~v6BHI~
//*************************************************************************//~v5mTI~
//*init                                                            //~v5mTI~
//*************************************************************************//~v5mTI~
int ucvext_iconvmapinit(int Popt,int Pextflag,PUCVEXTCFG Ppcfg)    //~v5mTR~
{                                                                  //~v5mTI~
//********************                                             //~v5mTI~
	Spcfg=Ppcfg;                                                   //~v5mTI~
	Sextflag=Pextflag;                                             //~v5mTR~
    UTRACED("ucvext2 cfg",Ppcfg,UCVEXTCFGSZ);                      //~v66NI~
    return 0;                                                      //~v5mTI~
}//ucvext_iconvmapinit                                             //~v5mTI~
#ifdef W32                                                         //~v5n1I~
//*************************************************************************//~v5n1I~
//*check windows codepage                                          //~v5n1I~
//*************************************************************************//~v5n1I~
int ucvext_getwincodepage(int Popt,char *Pcharset,ULONG *Pcp)      //~v5n1I~
{                                                                  //~v5n1I~
	ULONG cp;                                                      //~v5n1R~
    int len,rc;                                                    //~v5n1I~
    CPINFOEXW  info;                                               //~v5n1I~
//**********************                                           //~v5n1I~
UTRACEP("codepage=%s\n",Pcharset);                                 //~v5n1I~
  if (!stricmp(Pcharset,ENCODING_UTF8)                             //~v5n6I~
  ||  !stricmp(Pcharset,ENCODING_UTF_8)                            //~v5n6I~
  )                                                                //~v5n6I~
  {                                                                //~v5n6I~
  	cp=CP_UTF8;                                                    //~v5n6I~
	rc=udbcschk_getcpinfo(0,cp,&info);                             //~v5n6I~
  }                                                                //~v5n6I~
  else                                                             //~v5n6I~
  {                                                                //~v5n6I~
	len=strlen(Pcharset);                                          //~v5n1I~
	if (unumlen(Pcharset,0/*digit*/,len)!=len)	//allnumeric       //~v5n1I~
    {                                                              //~v5n1I~
//  	uerrmsg("Codepage parameter err(%s)",0,                    //~v5n9R~
//      		Pcharset);                                         //~v5n9R~
        cp=0;                                                      //~v5n1I~
        rc=4;                                                      //~v5n1I~
    }                                                              //~v5n1I~
    else                                                           //~v5n1I~
    {                                                              //~v5n1I~
    	cp=(ULONG)atoi(Pcharset);                                  //~v5n1R~
		rc=udbcschk_getcpinfo(0,cp,&info);                         //~v5n1R~
    }                                                              //~v5n1I~
  }                                                                //~v5n6I~
    if (rc)                                                        //~v5n1I~
    {                                                              //~v5n1I~
//  	uerrmsg("Invalid Codepage:%s",0,                           //~v5n1R~//~v69cR~
    	uerrmsg("Invalid Windows Codepage:%s",0,                   //~v69cI~
        		Pcharset);                                         //~v5n1R~
        if (Popt & EBC2ASC_WINCPLIST)                              //~v5n1I~
			ucvext_listwincp(CP_INSTALLED);                        //~v5n1I~
        else                                                       //~v69gR~
            if (!strcmp(Pcharset,"?"))                             //~v69gR~
				ucvext_listwincp(CP_INSTALLED);                    //~v69gR~
            else                                                   //~v6xaI~
		    	uerrmsgcat(" (\"ICU\" option is required for ICU converter).",//~v6xaI~
		    	           " (ICUコンバータ名 の場合は \"ICU\" オプションが必要です)");//~v6x8R~
        rc=UCVEXTRC_ERRMSGISSUED;                                  //~v69cR~
    }                                                              //~v5n1I~
    *Pcp=cp;                                                       //~v5n1I~
UTRACEP("codepage ret %ld\n",cp);                                  //~v5n1I~
    return rc;                                                     //~v5n1R~
}//ucvext_getwincodepage                                           //~v5n1I~
#endif //W32                                                       //~v5n1I~
//*************************************************************************
//*get dbcs starter of local converter                             //~v5mTR~
//*rc 1:mbcs lang                                                  //~v5mTI~
//*************************************************************************
//int ucvext_iconvgetstarter(int Popt,ULONG Pconverter,UCHAR *Pflags)//~v5n8R~
//int ucvext_iconvgetstarter(int Popt,ULONG Pconverter,UCHAR *Pflags,UCHAR *Ppleadbyte)//~v6x5R~
int ucvext_iconvgetstarter(int Popt,ULPTR Pconverter,UCHAR *Pflags,UCHAR *Ppleadbyte)//~v6x5I~
{
#ifdef LNX                                                         //~v5n1I~
//  int ii,ilen,olen,dbcssw=0,iconvrc;                             //~v5mTR~//~v624R~
    int ii,dbcssw=0,iconvrc;                                       //~v624I~
    size_t ilen,olen;                                              //~v624I~
    iconv_t hiconv,*phiconv;                                       //~v5mTR~
    char wki[2],wko[MAX_MBCSLEN],*pci,*pco;                        //~v5mTI~
    UCHAR *pc;                                                     //~v5mTI~
//**********************                                           //~v5mTI~
	phiconv=(iconv_t*)Pconverter;	//2 iconv_t output area        //~v5mTR~
	hiconv=phiconv[HICONV_TOUCS];                                  //~v5mTI~
	memset(Pflags,0,0x80);                                         //~v5mTR~
UTRACEP("iconv converter=%p\n",hiconv);                            //~v5mTI~
	for (ii=0x80,pc=Pflags+0x80;ii<=0xff;ii++,pc++)                //~v5mTR~
    {                                                              //~v5mTI~
		wki[0]=(char)ii;                                           //~v5mTI~
        pci=wki;                                                   //~v5mTR~
        pco=wko;                                                   //~v5mTI~
    	ilen=1;                                                    //~v5mTR~
    	olen=sizeof(wko);                                          //~v5mTI~
//  	iconvrc=(int)iconv(hiconv,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);//~v5n8R~//~v5ntR~
    	iconvrc=(int)iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5ntI~
//UTRACEP("iconv dbcstbl hiconv=%x,%02x ilen=%d rc=%d,errno=%d\n",hiconv,wki[0],ilen,iconvrc,errno);//~v6a0R~
    	if (iconvrc<0                                              //~v5mTR~
        && errno==EINVAL)	//correspond to rc=-2 from mbr2wc      //~v5mtR~
        {                                                          //~v5mTI~
        	dbcssw=1;                                              //~v5mTI~
        	*pc=0x01;                                              //~v5mTI~
        }                                                          //~v5mTI~
        else                                                       //~v5mTI~
        	*pc=0x00;                                              //~v5mTI~
    }                                                              //~v5mTI~
UTRACED("dbcstbl",Pflags,256);                                     //~v5mTI~
	if (Ppleadbyte)                                                //~v5n8I~
    {                                                              //~v5n8I~
    	if (dbcssw)                                                //~v5n8I~
			udbcschk_getlinuxleadbyte(0,Pflags,Ppleadbyte);        //~v5n8R~
        else                                                       //~v5n8I~
        	*Ppleadbyte=0;                                         //~v5n8I~
    }                                                              //~v5n8I~
    return dbcssw;                                                 //~v5mTI~
#else //W32                                                        //~v5n1I~
// 	return udbcschk_getstarter(0,Pconverter,Pflags,0/*output lead bytes array*/);//~v5n8R~
//	return udbcschk_getstarter(0,Pconverter,Pflags,Ppleadbyte);    //~v6x5R~
  	return udbcschk_getstarter(0,(ULONG)Pconverter,Pflags,Ppleadbyte);  //Pconverter is windows cp//~v6x5I~
#endif                                                             //~v5n1M~
}//ucvext_iconvgetstarter                                          //~v5mTR~
//*************************************************************************//~v5n1M~
//*get converter type (SBCS,DBCS,MBCS...)                          //~v5n1M~
//*rc:-1:unsupported,0:sbcs,1:dbcs,2:MBCS                          //~v5n1M~
//*************************************************************************//~v5n1M~
//int ucvext_iconvgetconvertertype(int Popt,ULONG Pconverter,int *Pptype)//~v6x5R~
int ucvext_iconvgetconvertertype(int Popt,ULPTR Pconverter,int *Pptype)//~v6x5I~
{                                                                  //~v5n1M~
#ifdef LNX                                                         //~v5n1I~
	UTRACEP("getconvertertype %s\n",Pconverter);                   //~v5n7I~
    if (Pconverter)                                                //~v5n7I~
  		if (!stricmp((char*)Pconverter,ENCODING_UTF8)              //~v5n7R~
  		||  !stricmp((char*)Pconverter,ENCODING_UTF_8)             //~v5n7R~
  		)                                                          //~v5n7R~
        {                                                          //~v5n7I~
        	UTRACEP("converter type UTF8\n");                      //~v5n7I~
			return  UCEIRC_UTF8; //multibyte but no dbcs leadbyte  //~v5n7R~
        }                                                          //~v5n7I~
	return  UCEIRC_MBCS; //try craete starter map                  //~v5n1I~
#else                                                              //~v5n1I~
    int rc,rc2;                                                    //~v5n1M~
//***********************                                          //~v5n1M~
//  rc2=udbcschk_getcodepagetype(0,Pconverter);                    //~v6x5R~
    rc2=udbcschk_getcodepagetype(0,(ULONG)Pconverter/*codepage*/); //~v6x5I~
    if (rc2==1)                                                    //~v5n1M~
        rc=UCEIRC_SBCS;                                            //~v5n1M~
    else                                                           //~v5n1M~
    if (rc2>1)                                                     //~v5n1M~
        rc=UCEIRC_MBCS;                                            //~v5n1M~
    else                                                           //~v5n1M~
        rc=-1;                                                     //~v5n1M~
    return rc;                                                     //~v5n1M~
#endif                                                             //~v5n1I~
}//ucvext_iconvgetconvertertype                                    //~v5n1M~
//*************************************************************************
//*get 2 iconv handle                                              //~v5mTR~
//*rc 4:err,0:ok                                                   //~v5mTR~
//*************************************************************************
//int ucvext_iconvgetconverter(int Popt,UCHAR *Pcharset,ULONG *Ppconverter)//~v5mTR~//~v6hhR~
int ucvext_iconvgetconverter(int Popt,UCHAR *Pcharset,ULPTR *Ppconverter)//~v6hhI~
{
	int rc=0;                                                      //~v5mTI~
    iconv_t hiconv;                                                //~v5n1R~
#ifdef LNX                                                         //~v5n1I~
    iconv_t *phiconv;                                              //~v5n1I~
#else                                                              //~v69gI~
    int rc2;                                                       //~v69gM~
#endif                                                             //~v5n1I~
//***********************
UTRACEP("iconvopen charset=%s\n",Pcharset);                        //~v5mTI~
#ifdef LNX                                                         //~v5n1I~
	phiconv=(iconv_t*)(ULONG)*Ppconverter;	//2 iconv_t output area//~v5mTI~
	hiconv=iconv_open(ENCODING_UCS2/*to*/,Pcharset/*from*/);       //~v5mTR~
UTRACEP("ucvext_iconvgetconverster iconvopen to %s from %s ,rc=%x\n",ENCODING_UCS2,Pcharset,hiconv);//~v65cR~
    if (hiconv==(iconv_t)(-1))                                     //~v6a0I~
    {                                                              //~v6a0I~
		hiconv=iconv_open(ENCODING_UCS2_2/*to*/,Pcharset/*from*/); //~v6a0I~
UTRACEP("ucvext_iconvgetconverster iconvopen to %s from %s ,rc=%x\n",ENCODING_UCS2_2,Pcharset,hiconv);//~v6a0I~
	}                                                              //~v6a0I~
    if (hiconv==(iconv_t)(-1))                                     //~v5mTI~
    {                                                              //~v5mTI~
    	uerrmsg("iconv_open failed(rc=%d) for %s to %s. ",0,         //~v5mTI~//~v6frR~
        			errno,Pcharset,ENCODING_UCS2);                 //~v5mTI~
//      rc=4;                                                      //~v5mTI~//~v69cR~
      	rc=UCVEXTRC_ERRMSGISSUED;                                  //~v69cR~
    }                                                              //~v5mTI~
    else                                                           //~v5mTI~
    {                                                              //~v5mTI~
    	phiconv[HICONV_TOUCS]=hiconv;                              //~v5mTR~
		hiconv=iconv_open(Pcharset,ENCODING_UCS2);                 //~v5mTI~
UTRACEP("ucvext_iconvgetconverster iconvopen from %s to %s ,rc=%x\n",ENCODING_UCS2,Pcharset,hiconv);//~v624R~//~v65cR~
    	if (hiconv==(iconv_t)(-1))                                 //~v6a0I~
    	{                                                          //~v6a0I~
			hiconv=iconv_open(Pcharset,ENCODING_UCS2_2);           //~v6a0I~
UTRACEP("ucvext_iconvgetconverster iconvopen from %s to %s ,rc=%x\n",ENCODING_UCS2_2,Pcharset,hiconv);//~v6a0I~
		}                                                          //~v6a0I~
        if (hiconv==(iconv_t)(-1))                                 //~v5mTI~
        {                                                          //~v5mTI~
            uerrmsg("iconv_open failed(rc=%d) for %s from %s. ",0,   //~v5mTI~//~v6frR~
                        errno,Pcharset,ENCODING_UCS2);             //~v5mTI~
//          rc=4;                                                  //~v5mTI~//~v69cR~
      		rc=UCVEXTRC_ERRMSGISSUED;                              //~v69cR~
        }                                                          //~v5mTI~
        else                                                       //~v5mTI~
        {                                                          //~v5mTI~
    		phiconv[HICONV_FROMUCS]=hiconv;                        //~v5mTR~
            *Ppconverter=(ULONG)phiconv;                           //~v5mTI~
        }                                                          //~v5mTI~
    }                                                              //~v5mTI~
UTRACED("iconv_t",phiconv,8);                                      //~v5mTI~
#else                                                              //~v5n1M~
//  if (!ucvext_getwincodepage(Popt,Pcharset,&hiconv))             //~v5n1M~//~v69cR~
    if (!(rc2=ucvext_getwincodepage(Popt,Pcharset,&hiconv)))       //~v69cR~
		*Ppconverter=hiconv;                                       //~v5n1M~
    else                                                           //~v5n1M~
      if (rc2==UCVEXTRC_ERRMSGISSUED)                              //~v69cR~
      	rc=rc2;                                                    //~v69cR~
      else                                                         //~v69cR~
    	rc=4;                                                      //~v5n1M~
#endif                                                             //~v5n1M~
    return rc;
}//ucvext_iconvgetconverter                                        //~v5mTR~
//*************************************************************************//~v5n1I~
//*get converter for a2a and dbcs flag                             //~v5n1I~
//*parm:converters:cvto,cvfrom,dbcstbl for cpfrom                  //~v5mtI~
//*ret 1:dbcs codepage                                             //~v5n1I~
//*************************************************************************//~v5n1I~
//int ucvext_iconvgetparmconverter(int Popt,char *Pcpfrom,char *Pcpto,ULONG *Ppconverters)//~v5n1R~//~v6hhR~
int ucvext_iconvgetparmconverter(int Popt,char *Pcpfrom,char *Pcpto,ULPTR *Ppconverters)//~v6hhI~
{                                                                  //~v5n1I~
	UCHAR *pflags;                                                 //~v5n1R~
    char *pcpfrom,*pcpto;                                          //~v5n3I~
    int dbcssw;                                                    //~v5n1I~
//**********************                                           //~v5n1I~
	if (!Pcpfrom || !*Pcpfrom)                                     //~v5n3I~
    	pcpfrom=0;                                                 //~v5n3I~
    else                                                           //~v5n3I~
        pcpfrom=Pcpfrom;                                           //~v5n3I~
	if (!Pcpto || !*Pcpto)                                         //~v5n3I~
    	pcpto=0;                                                   //~v5n3I~
    else                                                           //~v5n3I~
        pcpto=Pcpto;                                               //~v5n3I~
    if (!pcpfrom && !pcpto)                                        //~v5n3I~
    {                                                              //~v5n3I~
#ifdef UTF8SUPPH                                                   //~v621I~
      if (!(Popt & UCVEXTO_FROMUTF8))                              //~v621I~
      {                                                            //~v621I~
#endif                                                             //~v621I~
    	uerrmsg("%cF:codepage or %cT:codepage option is require for M2M",0,//~v5n3I~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~v5n3I~
        return 8;                                                  //~v5n3I~
#ifdef UTF8SUPPH                                                   //~v621I~
      }                                                            //~v621I~
#endif                                                             //~v621I~
    }                                                              //~v5n3I~
#ifdef W32                                                         //~v5n3I~
	if (!pcpfrom)                                                  //~v5n3I~
    	pcpfrom="0"; //CP_ACP                                      //~v5n3I~
	if (!pcpto)                                                    //~v5n3I~
    	pcpto="0"; //CP_ACP                                        //~v5n3I~
#else                                                              //~v5n3I~
	if (!pcpfrom)                                                  //~v5n3I~
    {                                                              //~v5n3I~
		pcpfrom=utfcvsetdefaultlocale();                           //~v5n3I~
        uerrmsg("current default is f:%s",0,                       //~v5n3I~
                pcpfrom);                                          //~v5n3I~
    }                                                              //~v5n3I~
	if (!pcpto)                                                    //~v5n3I~
    {                                                              //~v5n3I~
		pcpto=utfcvsetdefaultlocale();                             //~v5n3I~
        uerrmsg("current default is t:%s",0,                       //~v5n3I~
                pcpto);                                            //~v5n3I~
    }                                                              //~v5n3I~
#endif                                                             //~v5n3I~
	if (ucvext_iconvgetconverter(Popt,pcpto,Ppconverters+HICONV_CPTO))//~v5n3R~
    	return 8;                                                  //~v5n1M~
	if (ucvext_iconvgetconverter(Popt,pcpfrom,Ppconverters+HICONV_CPFROM))//~v5n3R~
    	return 8;                                                  //~v5n1M~
    pflags=(UCHAR*)(*(Ppconverters+HICONV_DBCSSTARTER));           //~v5n1R~
#ifdef LNX                                                         //~v5n1I~
UTRACED("iconv_t cpto",Ppconverters[HICONV_CPTO],8);               //~v5mtM~
UTRACED("iconv_t cpfrom",Ppconverters[HICONV_CPFROM],8);           //~v5mtM~
#ifdef UTF8SUPPH                                                   //~v621I~
 if (Popt & UCVEXTO_FROMUTF8)                                      //~v621I~
	dbcssw=0;                                                      //~v621I~
 else                                                              //~v621I~
#endif                                                             //~v621I~
//if (ucvext_iconvgetconvertertype(0,(ULONG)pcpfrom,0)==UCEIRC_UTF8)//~v6x5R~
  if (ucvext_iconvgetconvertertype(0,(ULPTR)pcpfrom,0)==UCEIRC_UTF8)//~v6x5R~
	dbcssw=0;                                                      //~v5n7I~
  else                                                             //~v5n7I~
	dbcssw=ucvext_iconvgetstarter(Popt,Ppconverters[HICONV_CPFROM],pflags,0/*out lead byte*/);//~v5n8R~
#else                                                              //~v5n1I~
UTRACEP("iconv_t cpto=%p",Ppconverters[HICONV_CPTO]);              //~v5mtI~
UTRACEP("iconv_t cpfrom=%p",Ppconverters[HICONV_CPFROM]);          //~v5mtI~
// 	dbcssw=udbcschk_getstarter(Popt,*(Ppconverters+HICONV_CPFROM),pflags,0/*output lead bytes array*/);//~v6x5R~
   	dbcssw=udbcschk_getstarter(Popt,(ULONG)(*(Ppconverters+HICONV_CPFROM))/*codepage*/,pflags,0/*output lead bytes array*/);//~v6x5I~
//*dbcssw=0 for UTF8                                               //~v6bgI~
  if (Ppconverters[HICONV_FROMUCS]!=CP_UTF8)                       //~v5n6I~
//  if (!dbcssw && udbcschk_getcodepagetype(0,Ppconverters[HICONV_CPFROM])>1)//~v6x5R~
    if (!dbcssw && udbcschk_getcodepagetype(0,(ULONG)(Ppconverters[HICONV_CPFROM]/*codepage*/))>1)//~v6x5I~
    {                                                              //~v5n1I~
    	uerrmsg("%d is not supported as source charset(Multibyte but not MBCS)",0,Ppconverters[HICONV_FROMUCS]);//~v5n3R~
        return 8;                                                  //~v5n1I~
    }                                                              //~v5n1I~
#endif                                                             //~v5n1I~
UTRACEP("iconv starter dbcssw=%d\n",dbcssw);                       //~v5n1I~
UTRACED("iconv starter",pflags,256);                               //~v5n1I~
	if (!dbcssw)                                                   //~v5n1I~
    	*(Ppconverters+HICONV_DBCSSTARTER)=0;                      //~v5n1R~
    return dbcssw;                                                 //~v5n1I~
}//ucvext_iconvgetparmconverter                                    //~v5n1R~
#ifdef W32                                                         //~v5n1M~
//*************************************************************************//~v5n1M~
//*translate by win API                                            //~v5n1M~
//* inplen=1/2 for SBCS/DBCS, strlen for UTF8                      //~v5n6R~
//* windows codepage to ucs                                        //~v5n6I~
//* rc:0 or 4,-3:setsubch                                          //~v5n8I~//~v66DR~
//*************************************************************************//~v5n1M~
//int ucvext_wincp2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs,int *Ppchklen)//~v5n1M~//~v6BjR~
int ucvext_wincp2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs,int *Ppchklen)//~v6BjI~
{                                                                  //~v5n1M~
	int ctr,rc=0,opt,chklen=1;                                     //~v5n1M~
    int cvlen;                                                     //~v62NI~
    int swrevchk;                                                  //~v66NI~
    USHORT wkucs[MAX_MBCSLEN];                                     //~v5n1M~
//  ULONG ucs;                                                     //~v5n6I~//~v6hdR~
    UWUCS ucs;                                                     //~v6hdI~
    UWUCS ucs4;                                                    //~v6BjI~
    USHORT usucs;                                                  //~v66NI~
	char wkmbs[MAX_MBCSLEN];                                       //~v62NI~
    int lasterr;                                                   //~v6BHI~
//*********************                                            //~v5n1M~
    UTRACEP("wincp2ucs1 cv=%d,opt=%x,inplen=%d data=%02x%02x%02x\n",Pconverter,Popt,Pinplen,*Ppebc,(Pinplen>1?*(Ppebc+1):0),(Pinplen>2?*(Ppebc+2):0));//~v5n6I~//~v62ER~
    cvlen=min(Pinplen,MAX_MBCSLEN);                                //~v62NI~
  if (Pconverter==CP_UTF8)                                         //~v5n6I~
  {                                                                //~v5n6I~
//  if (uccvutf2ucs(0,Ppebc,Pinplen,&ucs,&chklen))                 //~v5n6I~//~v62NR~
    if (uccvutf2ucs(0,Ppebc,cvlen,&ucs,&chklen))                   //~v62NI~
    {                                                              //~v5n6I~
    	rc=4;                                                      //~v5n6I~
        chklen=1;                                                  //~v5n6I~
//      wkucs[0]=UCVERRUCS;	//2byte ffff                           //~v6r3I~//~v6BjR~
        ucs4=UCVERRUCS;	//2byte ffff                               //~v6BjI~
    }                                                              //~v5n6I~
    else                                                           //~v5n6I~
//      wkucs[0]=(USHORT)ucs;                                      //~v5n6I~//~v6BjR~
        ucs4=ucs;                                                  //~v6BjI~
  }                                                                //~v5n6I~
  else                                                             //~v5n6I~
  {                                                                //~v5n6I~
    wkucs[0]=UCVERRUCS;	//for the case ctr=0                       //~v6BjI~
//   if (Pconverter==CP_GB18030                                      //~v65jR~//~v6BHR~
//   )                                                               //~v65jR~//~v6BHR~
//    opt=0;                      //err INVALID flag(1004) if PRECOMOSIT(default) or INVALID_CHAR flag for GB18030//~v65jR~//~v6BHR~
//   else                                                            //~v65jR~//~v6BHR~
    opt=MB_PRECOMPOSED          //output compose char              //~v5n1M~
      | MB_ERR_INVALID_CHARS    //return err if invalid char       //~v5n1M~
                                //ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~v5n1M~
      ;                                                            //~v5n1M~
//  ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,Pinplen,wkucs,sizeof(wkucs)/sizeof(wkucs[0]));//~v5n6R~//~v62NR~
//  ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs)/sizeof(wkucs[0]));//~v62NI~//~v6BHR~
    ctr=uMultiByteToWideChar(0,Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs),&lasterr);//~v6BHR~
    UTRACEP("%s:uMultibyteToWideChar cp=%d,mb=%02x,len=%d,ctr=%d,ucs=%04x,lasterr=%d\n",UTT,Pconverter,*Ppebc,cvlen,ctr,wkucs[0],lasterr);//~v66DI~//~v6BjR~//~v6BFR~//~v6BHR~
    ucs4=(UWUCS)wkucs[0];                                          //~v6BjI~
    if (IS_UTF16_PAIR(ucs4,wkucs[1]))                              //~v6BjI~
        ucs4=UTF16_TO_UCS4(ucs4,wkucs[1]);                         //~v6BjI~
	if (!ctr)                                                      //~v5n1R~
    {                                                              //~v5n1M~
    	UTRACEP("ERR win2ucs %02x%02x lasterr=%d,opt=%x\n",*Ppebc,(Pinplen>1?*(Ppebc+1):0),GetLastError(),opt);//~v5n1R~//~v65cR~
    	rc=4;                                                      //~v5n1M~
        if (Popt & UCVUCS_SETSUBCHRC)                              //~v66DI~
        {                                                          //~v66DI~
    		opt=0;  //allow set default char for invalid mbstr     //~v66DI~
//  	    ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs)/sizeof(wkucs[0]));//~v66DI~//~v6BHR~
		    ctr=uMultiByteToWideChar(0,Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs),&lasterr);//~v6BHR~
            if (ctr)                                               //~v66DI~
            	rc=UCVEXTRC_SUBCH;                                 //~v66DI~
	    	UTRACEP("ERR win2ucs not ERRINVALID ctr=%d,rc=%d,lasterr=%d,ucs=%x\n",ctr,rc,GetLastError(),wkucs);//~v66DI~
        }                                                          //~v66DI~
    }                                                              //~v5n1M~
//#ifdef AAA	//dbcs len is not fixed to 2 byte                                                         //~v62EI~//~v62NR~
    else                                                           //~v62EI~
    {                                                              //~v62EI~
    	UTRACED("OK  win2ucs out",wkucs,sizeof(wkucs));            //~v65cI~
      if (ctr>1                  //multiple ucs output             //~v69cI~
//    &&  Popt & UCVUCS_MBDBCS1  //err if translated count>1       //~v69cI~//~v6BoR~
//*        UCVUCS_MBDBCS1:from iconvebc2ucs1                       //~v6BjI~
      && !(ctr==2 && UTF_ISUCS4(ucs4)) //surrogate is OK but ctr>1 means invalid mbs len parameter//~v6BoI~
      )                                                            //~v69cI~
      {                                                            //~v69cI~
        if (Popt & UCVUCS_SETSUBCHRC)                              //~v69cI~
            rc=UCVEXTRC_SUBCH;                                     //~v69cI~
        else                                                       //~v69cI~
        if (Popt & UCVUCS_MBDBCS1)  //err if translated count>1    //~v6BoI~
            rc=UCVUCSRC_NOTMBDBCS1;  //ebc2ucs;requested MBDBCS1 but translated not to 1 ucs//~v69cI~
        else                                                       //~v6BoI~
        	rc=4;                                                  //~v6BoI~
        UTRACEP("EBC DBCS err out ucs=%x,rc=%d\n",wkucs[0],rc);    //~v69cI~
      }                                                            //~v69cI~
      else                                                         //~v69cI~
      {                                                            //~v69cI~
        swrevchk=0;                                                //~v66NI~
    	if (Popt & UCVUCS_SETSUBCHRC)                              //~v66NI~
        {                                                          //~v66NI~
    		if (!(Popt & UCVUCS_LOCALCV))	//ebc2ucs              //~v66NI~
            {                                                      //~v66NI~
        		usucs=wkucs[0];                                    //~v66NI~
        		if (usucs)                                         //~v66NR~
                  if (Spcfg)                                       //~v6BnI~
                    if (usucs==Spcfg->UCECsubchardefaultucsdbcs    //~v66NI~
                    || usucs==Spcfg->UCECsubchardefaultucssbcs  //CPINFO subchar//~v66NR~
                    )                                              //~v66NR~
                        swrevchk=1; //reversechk                   //~v66NR~
            }                                                      //~v66NI~
        }                                                          //~v66NI~
//    	UTRACEP("subcharchk win2ucs ucs=%x,revchk=%d\n",usucs,swrevchk);//~v66NI~//~v6h7R~
//  char wkmbs[MAX_MBCSLEN];                                       //~v62EM~//~v62NR~
//  	if (Ppchklen)	//cv ok and chklen return required         //~v62EI~//~v66DR~
    	if (Ppchklen	//cv ok and chklen return required         //~v66DI~
//  	||  Popt & UCVUCS_SETSUBCHRC)    //1:n but may not be subchar//~v66DR~//~v66NR~
		||  swrevchk                                               //~v66NI~
        )                                                          //~v66NR~
 	   	{                                                          //~v62EI~
//  		if (ucvext_winucs2cp1(0,Pconverter,wkucs[0],wkmbs,&chklen)>1)	//1:dbcs,get mb len//~v62ER~//~v6BjR~
    		if (ucvext_winucs2cp1(0,Pconverter,ucs4,wkmbs,&chklen)>1)	//1:dbcs,get mb len//~v6BjI~
                rc=8;                                              //~v62NI~
            else                                                   //~v62NI~
//          if (!chklen || memcmp(wkmbs,Ppebc,(UINT)chklen))	//reverse err//~v62NI~//~v6BrR~
            if (!chklen                                            //~v6BrI~
            ||   chklen>cvlen/*api convert beyond cvlen ig GB18030*///~v6BrI~
            ||   memcmp(wkmbs,Ppebc,(UINT)chklen))	//reverse err  //~v6BrI~
                rc=12;                                             //~v62NI~
		    UTRACEP("wincp2ucs1 backchk by winucs2cp1 rc%d ctr=%d,chklen=%d mb=%02x%02x\n",rc,ctr,chklen,*wkmbs,*(wkmbs+1));//~v62EI~//~v62NR~//~v66NR~
            if (rc)                                                //~v62NI~
            {                                                      //~v66NI~
              	if (swrevchk)	//request return subchar was set   //~v66NI~
            		rc=UCVEXTRC_SUBCH;                             //~v66NI~
            	chklen=1;                                          //~v62NI~
            }                                                      //~v66NI~
        }                                                          //~v62EI~
      }//MBDBCS1                                                   //~v69cI~
    }                                                              //~v62EI~
//#endif                                                             //~v62EI~//~v62NR~
#ifdef AAA                                                         //~v62NI~
//  chklen=1+((Popt & EBC2ASC_STAT_SO)!=0);                        //~v5n8R~
    chklen=1+((Popt & UCVUCS_MBDBCS)!=0);                          //~v5n8R~
    chklen=min(Pinplen,chklen);                                    //~v5n1I~
#endif                                                             //~v62NI~
  }                                                                //~v5n6I~
    if (Ppchklen)                                                  //~v5n1M~
	    *Ppchklen=chklen;                                          //~v5n1M~
//  *Ppucs=wkucs[0];                                               //~v5n1I~//~v6BjR~
    *Ppucs=ucs4;                                                   //~v6BjI~
    UTRACEP("wincp2ucs1 rc=%d,chklen=%d,ucs=%x,data1=%x\n",rc,chklen,ucs4,*Ppebc);//~v5n1R~//~v62ER~//~v66tR~//~v6BjR~
    return rc;                                                     //~v5n1M~
}//ucvext_wincp2ucs1                                               //~v5n1M~
//*************************************************************************//~v6BAI~
//*translate by win API MultiByteToWideChar                        //~v6BAI~
//* windows codepage to ucs                                        //~v6BAI~
//* rc:0 or 4 err,8 reverse err when mble output required          //~v6BAR~
//*************************************************************************//~v6BAI~
int ucvext_MB2WC(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs,int *Ppmblen,int *Pplasterr)//~v6BAR~
{                                                                  //~v6BAI~
	int ctr,rc=0,rc2,opt;                                          //~v6BAR~
    int cvlen,mblen=0;                                             //~v6BAR~
    WUCS wkucs[MAX_MBCSLEN];                                       //~v6BAR~
    UWUCS ucs;                                                     //~v6BAI~
    int lasterr=0;                                                 //~v6BAR~
	char wkmbs[MAX_MBCSLEN];                                       //~v6BAI~
//*********************                                            //~v6BAI~
    UTRACEP("wincp2ucs1 cv=%d,opt=%x,inplen=%d data=%02x%02x%02x\n",Pconverter,Popt,Pinplen,*Ppebc,(Pinplen>1?*(Ppebc+1):0),(Pinplen>2?*(Ppebc+2):0));//~v6BAI~
    cvlen=min(Pinplen,MAX_MBCSLEN);                                //~v6BAI~
  	if (Pconverter==CP_UTF8)                                       //~v6BAI~
  	{                                                              //~v6BAI~
    	if (uccvutf2ucs(0,Ppebc,cvlen,&ucs,&mblen))                //~v6BAR~
    	{                                                          //~v6BAI~
            lasterr=ERROR_NO_UNICODE_TRANSLATION;	//1113         //~v6BAI~
    		rc=4;                                                  //~v6BAR~
        	ucs=0;                                                 //~v6BAI~
            ctr=0;	//ucsctr                                       //~v6BAR~
    	}                                                          //~v6BAI~
        else                                                       //~v6BAI~
            ctr=1;                                                 //~v6BAI~
    	UTRACEP("%s:MultibyteToWideChar CP_UTF8 cp=%d,mb=%02x-%02x,len=%d,ctr=%d,ucs=%x,lasterr=%d,mblen=%d\n",UTT,Pconverter,*Ppebc,(Pinplen>1?*(Ppebc+1):0),Pinplen,ctr,lasterr,mblen);//~v6BAI~
  	}                                                              //~v6BAI~
  	else                                                           //~v6BAI~
  	{                                                              //~v6BAI~
    	wkucs[0]=0;                                                //~v6BAI~
//      if (Pconverter==CP_GB18030)                                //~v6BAI~//~v6BHR~
//          opt=0;                      //err INVALID flag(1004) if PRECOMOSIT(default) or INVALID_CHAR flag for GB18030//~v6BHR~
//      else                                                       //~v6BAI~//~v6BHR~
            opt=MB_PRECOMPOSED          //output compose char      //~v6BAI~
                | MB_ERR_INVALID_CHARS;    //return err if invalid char//~v6BAI~
//      ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs)/sizeof(wkucs[0]));//~v6BAI~//~v6BHR~
//      lasterr=GetLastError();                                    //~v6BAI~//~v6BHR~
		ctr=uMultiByteToWideChar(0,Pconverter,opt,Ppebc,cvlen,wkucs,sizeof(wkucs),&lasterr);//~v6BHR~
    	if (IS_UTF16_PAIR(wkucs[0],wkucs[1]))                      //~v6BAI~
        	ucs=UTF16_TO_UCS4(wkucs[0],wkucs[1]);                  //~v6BAR~
        else                                                       //~v6BAI~
	    	ucs=(UWUCS)wkucs[0];                                   //~v6BAI~
		if (!ctr)                                                  //~v6BAI~
    		rc=4;                                                  //~v6BAI~
        else                                                       //~v6BAI~
        if (Ppmblen)	//mblen output required                    //~v6BAI~
        {                                                          //~v6BAI~
    		rc2=ucvext_winucs2cp1(0,Pconverter,ucs,wkmbs,&mblen);  //~v6BAI~
            if (rc2 && rc2!=1)//sbcs or dbcs	                   //~v6BAR~
            	rc=12;   //reverse err                             //~v6BAI~
            else                                                   //~v6BAI~
            if (!mblen                                             //~v6BAI~
            ||   mblen>cvlen/*api convert beyond cvlen ig GB18030*///~v6BAI~
            ||   memcmp(wkmbs,Ppebc,(size_t)mblen))	//reverse err  //~v6BAI~
                rc=12;                                             //~v6BAI~
        }                                                          //~v6BAI~
    	UTRACEP("%s:MultibyteToWideChar rc=%d,opt=%x,cp=%d,mb=%02x-%02x,len=%d,ctr=%d,ucs=%x,lasterr=%d,mblen=%d\n",UTT,rc,opt,Pconverter,*Ppebc,(Pinplen>1?*(Ppebc+1):0),cvlen,ctr,wkucs[0],lasterr,mblen);//~v6BAR~
    }                                                              //~v6BAI~
    *Ppucs=ucs;                                                    //~v6BAI~
    if (Pplasterr)                                                 //~v6BAI~
    	*Pplasterr=lasterr;                                        //~v6BAI~
    if (Ppmblen)                                                   //~v6BAI~
    	*Ppmblen=mblen;                                            //~v6BAI~
    return rc;                                                     //~v6BAI~
}//ucvext_MB2WC                                                    //~v6BAR~
//*************************************************************************//~v5n8I~
//*translate by win API                                            //~v5n8I~
//*!!! required Popt:UCVUCS_LE on/off when converter=CP_UTF8 !!!   //~v6r1I~
//* string translation                                             //~v5n8I~
//* if repch specified,replace err(need dbcs parm)                 //~v5n8I~
//* output:ucsctr                                                  //~v5n8I~
//* rc:4:err,2:err replaced,8:ovf                                         //~v66DR~//~v6HiR~
//*************************************************************************//~v5n8I~
int ucvext_wincp2ucss(int Popt,ULONG Pconverter,UCHAR *Ppmbs,UCHAR *Ppdbcs,int Pinplen,WUCS *Ppucs,int Poutbufflen,int *Ppoutctr)//~v5n8R~
{                                                                  //~v5n8I~
    int ctr,rc,opt=0,opt2,chklen=1,repch,errctr,outlen,ii,dbcssw,len;//~v5n8R~
    int rc2;                                                       //~v66DI~
    UCHAR *pc,*pcd;                                                //~v5n8I~
//  WUCS ucs,*pucs,*pucse;                                         //~v5n8R~//~v6BjR~
    WUCS *pucs,*pucse;                                             //~v6BjI~
    UWUCS ucs4;                                                    //~v6BjI~
    int utf16ctr;                                                  //~v6BjI~
    int reslen;                                                    //~v6BsI~
    int lasterr;                                                   //~v6BHI~
//*********************                                            //~v5n8I~
    UTRACEP("win 2ucss cv=%d,opt=%x\n",Pconverter,Popt);           //~v5n8I~
    UTRACED("win 2ucss mb",Ppmbs,Pinplen);                         //~v5n8I~
    repch=Popt & UCVUCS_ERRCH;                                     //~v5n8I~
//*MultiByteToWideChar dose not support UTF8 and UTF7              //~v6r2I~
  	if (Pconverter==CP_UTF8)                                       //~v5n8R~
    {                                                              //~v5n8I~
//        Gulibutfmode|=GULIBUTF_WINSURROGATE;// 0x00800000  //parm to uccvutf2ucs; set surrogate pare for ucs4(>0x10000)//~v6r4I~//~v6ueR~
//		rc=ucvsutf2ucs(0/*errfunc*/,Popt,Ppmbs,Pinplen,(UCHAR*)(ULONG)Ppucs,Poutbufflen,&chklen,&outlen,&errctr);//~v5n8R~//~v6hhR~
//  	rc=ucvsutf2ucs(0/*errfunc*/,Popt,Ppmbs,Pinplen,(UCHAR*)(ULPTR)Ppucs,Poutbufflen,&chklen,&outlen,&errctr);//~v6r2R~
    	rc=ucvsutf2ucs(0/*errfunc*/,Popt|UCVUCS_LE,Ppmbs,Pinplen,(UCHAR*)(ULPTR)Ppucs,Poutbufflen,&chklen,&outlen,&errctr);//~v6r2I~
//        Gulibutfmode&=~GULIBUTF_WINSURROGATE;// 0x00800000  //parm to uccvutf2ucs; set surrogate pare for ucs4(>0x10000)//~v6r4I~//~v6ueR~
        ctr=outlen/sizeof(USHORT);                                 //~v5n8I~
    }                                                              //~v5n8I~
  	else                                                           //~v5n8R~
  	{                                                              //~v5n8R~
//    if (Pconverter==CP_GB18030                                   //~v65jR~//~v6BHR~
//    )                                                            //~v65jR~//~v6BHR~
//      opt=0;                                                     //~v65jR~//~v6BHR~
//      //* MB_ERR_INVALID_CHARS also cause last err=1004(ERROR_INVALID_FLAGS)//~v6BrR~//~v6BHR~
//    else                                                         //~v65jR~//~v6BHR~
//    {                                                            //~v65jR~//~v6BHR~
    	opt=MB_PRECOMPOSED;			//output compose char          //~v5n8R~
    	if (Popt & UCVUCS_ERRSTOP||repch)                          //~v5n8I~
        	opt|=MB_ERR_INVALID_CHARS;    //return err if invalid char;ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~v5n8I~
//    }                                                            //~v65jR~//~v6BHR~
//  	ctr=MultiByteToWideChar(Pconverter,opt,Ppmbs,Pinplen,Ppucs,Poutbufflen/WUCSSZ);//~v5n8R~//~v6BHR~
		ctr=uMultiByteToWideChar(0,Pconverter,opt,Ppmbs,Pinplen,Ppucs,Poutbufflen,&lasterr);//~v6BHR~
//    if (opt & MB_ERR_INVALID_CHARS)    //return err if invalid char;ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~v6BsI~//~v6BIR~
//      rc=(ctr==0);                                               //~v5n8I~//~v6BIR~
//    else                                                         //~v6BsI~//~v6BIR~
//    	rc=(memchrW(Ppucs,L'?',ctr)!=0);                           //~v6BsI~//~v6BIR~
      	if (lasterr!=0)    //by MB_ERR_INVALID_CHARS               //~v6BII~
        	rc=4;                                                  //~v6BII~
    	else                                                       //~v6BII~
			rc=(memchrW(Ppucs,L'?',ctr)!=0)?1:0;                   //~v6BII~
        UTRACEP("%s:rc=%d,converter=%d,opt=%d,ctr=%d,lasterr=%d\n",UTT,rc,Pconverter,opt,ctr,GetLastError());//~v6BrI~//~v6BIR~
    }                                                              //~v5n8I~
	if (rc)                                                        //~v5n8R~
    {                                                              //~v5n8R~
        if (rc==1)  //"?" may not be case of err replace           //~v6BII~
            rc=0;                                                  //~v6BII~
        UTRACEP("wincp2ucss ERR inplen=%d,buffsz=%d\n",Pinplen,Poutbufflen/WUCSSZ);//~v65cI~
        if (!repch) //no errstop and no repch                      //~v5n8R~
//          rc=4;                                                  //~v5n8R~//~v6BIR~
            repch='?';                                             //~v6BII~
//      else                                                       //~v5n8I~//~v6BIR~
        {                                                          //~v5n8I~
        	pucse=Ppucs+Poutbufflen/WUCSSZ;                        //~v5n8R~
            for (pc=Ppmbs,ii=0,pcd=Ppdbcs,pucs=Ppucs;ii<Pinplen;)  //~v5n8I~
            {                                                      //~v6BsI~
//            {   if (pcd                                            //~v5n8I~//~v6BsR~
//                &&  *pcd==UDBCSCHK_DBCS1ST                         //~v5n8I~//~v6BsR~
//                &&  ii+1<Pinplen && *(pcd+1)==UDBCSCHK_DBCS2ND     //~v5n8R~//~v6BsR~
//                )                                                  //~v5n8I~//~v6BsR~
//                {                                                  //~v5n8I~//~v6BsR~
////                  opt2=Popt|UCVUCS_MBDBCS;                       //~v5n8I~//~v66DR~//~v6BsR~
//                    opt2=UCVUCS_MBDBCS; //no EBC2ASC opt to wincp2ucs1//~v66DI~//~v6BsR~
//                    dbcssw=1;                                      //~v5n8R~//~v6BsR~
//                    len=2;                                         //~v5n8I~//~v6BsR~
//                }                                                  //~v5n8I~//~v6BsR~
//                else                                               //~v5n8I~//~v6BsR~
//                {                                                  //~v5n8I~//~v6BsR~
//                  opt2=Popt;                                     //~v5n8I~//~v66DR~
                    opt2=0;             //no EBC2ASC opt to wincp2ucs1//~v66DI~
                    dbcssw=0;                                      //~v5n8R~
                    len=1;                                         //~v5n8I~
//                }                                                  //~v5n8I~//~v6BsR~
                    reslen=Pinplen-ii;                             //~v6BsI~
                  	if (pcd                                        //~v6BsI~
                  	&&  *pcd==UDBCSCHK_DBCS1ST)                    //~v6BsI~
                  	{                                              //~v6BsI~
				      	if (Pconverter==CP_GB18030                 //~v6BsI~
						&&  UDBCSCHK_DBCSPAD_ISGB4(pcd,reslen))    //~v6BsI~
                        {                                          //~v6BsI~
							opt2=UCVUCS_MBDBCS; //no EBC2ASC opt to wincp2ucs1//~v6BsI~
                    		dbcssw=1;                              //~v6BsI~
                    		len=4;                                 //~v6BsI~
                        }                                          //~v6BsI~
				      	if (reslen>=2                              //~v6BsI~
						&&  *(pcd+1)==UDBCSCHK_DBCS2ND)            //~v6BsI~
                        {                                          //~v6BsI~
							opt2=UCVUCS_MBDBCS; //no EBC2ASC opt to wincp2ucs1//~v6BsI~
                    		dbcssw=1;                              //~v6BsI~
                    		len=2;                                 //~v6BsI~
                        }                                          //~v6BsI~
                                                                   //~v6BsI~
                  	}                                              //~v6BsI~
                    if (!pcd)                                      //~v6BsI~
                    {                                              //~v6BsI~
				      	if (reslen>=2                              //~v6BsI~
						&&  UDBCSCHK_ISDBCS1ST(*pc))               //~v6BsR~
                        {                                          //~v6BsI~
							opt2=UCVUCS_MBDBCS; //no EBC2ASC opt to wincp2ucs1//~v6BsI~
                    		dbcssw=1;                              //~v6BsI~
				      		if (Pconverter==CP_GB18030             //~v6BsI~
							&&  reslen>=4                          //~v6BsI~
                        	&&  UDBCSCHK_ISGB42ND(*(pc+1)) //not UDBCSCHK_ISGB4(pc),same as setdbcstblmb,try even 3rd/4th byte is invalid//~v6BsI~
                        	)                                      //~v6BsI~
                    			len=4;                             //~v6BsI~
                        	else                                   //~v6BsI~
                    			len=2;                             //~v6BsR~
                        }                                          //~v6BsM~
                    }                                              //~v6BsI~
			  	if (Pconverter==CP_UTF8)                           //~v5n8I~
                	len=Pinplen-ii;                                //~v5n8R~
        		if (Popt & EBC2ASC_EXT_SETSUBCHRC)                 //~v66DI~
        			opt2|=UCVUCS_SETSUBCHRC;                       //~v66DI~
//              if (ucvext_wincp2ucs1(opt2,Pconverter,pc,len,&ucs,&chklen))//~v5n8I~//~v66DR~
//              rc2=ucvext_wincp2ucs1(opt2,Pconverter,pc,len,&ucs,&chklen);//~v66DI~//~v6BjR~
                rc2=ucvext_wincp2ucs1(opt2,Pconverter,pc,len,&ucs4,&chklen);//~v6BjI~
                if (rc2)                                           //~v66DI~
                {                                                  //~v5n8I~
                    rc=2;   //rep occured                          //~v5n8I~
                  if (rc2!=UCVEXTRC_SUBCH)//leave wincp default char//~v66DI~
                  {                                                //~v66DI~
                  	if (pucs>=pucse)                               //~v6HiI~
                    {                                              //~v6HiI~
                    	rc=8;                                      //~v6HiI~
                        break;                                     //~v6HiI~
                    }                                              //~v6HiI~
//                  *pucs++=repch;                                 //~v6x8R~
                    *pucs++=(WUCS)repch;                           //~v6x8I~
                    if (dbcssw)                                    //~v5n8I~
                      if (chklen>1)                                //~v6BsI~
                      {                                            //~v6HiI~
                  		if (pucs>=pucse)                           //~v6HiI~
                    	{                                          //~v6HiI~
                    		rc=8;                                  //~v6HiI~
                        	break;                                 //~v6HiI~
                    	}                                          //~v6HiI~
//                      *pucs++=repch;                             //~v6x8R~
                        *pucs++=(WUCS)repch;                       //~v6x8I~
                      }                                            //~v6HiI~
                  }                                                //~v66DI~
                }                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v6BjI~
                    if (UTF_ISUCS4(ucs4))                          //+v6HiR~
                    {                                              //~v6HiI~
                        if (pucs+1>=pucse)                         //~v6HiI~
                        {                                          //~v6HiI~
                            rc=8;                                  //~v6HiI~
                            break;                                 //~v6HiI~
                        }                                          //~v6HiI~
                    }                                              //~v6HiI~
                    else                                           //~v6HiI~
                        if (pucs>=pucse)                           //~v6HiI~
                        {                                          //~v6HiI~
                            rc=8;                                  //~v6HiI~
                            break;                                 //~v6HiI~
                        }                                          //~v6HiI~
                                                                   //~v6HiI~
//              	*pucs++=ucs;                                   //~v5n8I~//~v6BjR~
                  	UCS4_TO_UTF16(ucs4,pucs,&utf16ctr);            //~v6BjR~
                    pucs+=utf16ctr;                                //~v6BjR~
                }                                                  //~v6BjI~
                pc+=chklen;                                        //~v5n8I~
                if (pcd)                                           //~v5n8I~
                    pcd+=chklen;                                   //~v5n8R~
                ii+=chklen;                                        //~v5n8I~
            }                                                      //~v5n8I~
//          ctr=((ULONG)pucs-(ULONG)Ppucs)/sizeof(USHORT);         //~v5n8I~//~v6hhR~
//          ctr=((ULPTR)pucs-(ULPTR)Ppucs)/sizeof(USHORT);         //~v6hhI~//~v6ByR~
            ctr=(int)(((ULPTR)pucs-(ULPTR)Ppucs)/sizeof(USHORT));  //~v6ByI~
        }                                                          //~v5n8I~
  	}                                                              //~v5n8R~
    *Ppoutctr=ctr;                                                 //~v5n8R~
    UTRACEP("win 2ucss rc=%d,outctr=%d\n",rc,ctr);                 //~v5n8R~
    return rc;                                                     //~v5n8I~
}//ucvext_wincp2ucss                                               //~v5n8R~
#endif //W32                                                       //~v5n1M~
//*************************************************************************
//*translate by iconv converter                                    //~v5mTR~
//* ebc to ucs
//*rc:-3:subchar was set                                           //~v66DI~
//*************************************************************************
//int ucvext_iconvebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs)//~v66DR~
//int ucvext_iconvebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs)//~v6x5R~
//int ucvext_iconvebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs)//~v6x5I~//~v6BjR~
int ucvext_iconvebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs)//~v6BjR~
{
#ifdef LNX                                                         //~v5mtI~
    iconv_t *phiconv,hiconv;                                       //~v5mTI~
	char *pco;                                                     //~v5mtR~
#ifdef UTF8UCS4                                                    //~v66jI~
	WUCS   wkucs[2];                                               //~v66jI~
#else                                                              //~v66jI~
	USHORT wkucs[2];                                               //~v5mTI~
#endif                                                             //~v66jI~
//  int olen;                                                      //~v5mtR~//~v624R~
    size_t olen;                                                   //~v624I~
    size_t rciconv;                                                //~v5mTI~
    int rc=0;                                                      //~v5n8I~
    int outlen;                                                    //~v66VI~
#else                                                              //~v5n8I~
    int optw;                                                      //~v5n8I~
#endif                                                             //~v5mtI~
	char wkebc[4],*pci;                                            //~v5mtI~
//  int ilen;                                                      //~v5n8R~//~v624R~
    size_t ilen;                                                   //~v624I~
//***************************
    if (Popt & EBC2ASC_STAT_SO && Pinplen>1)                       //~v5mTI~
    {                                                              //~v5mTI~
        wkebc[0]=CHAR_SO;                                          //~v5mTI~
        wkebc[1]=*Ppebc;                                           //~v5mTI~
        wkebc[2]=*(Ppebc+1);                                       //~v5mTI~
        wkebc[3]=CHAR_SI;                                          //~v5mTI~
        ilen=4;                                                    //~v5mTI~
    }                                                              //~v5mTI~
    else                                                           //~v5mTI~
    {                                                              //~v5mTI~
        wkebc[0]=*Ppebc;                                           //~v5mTR~
        wkebc[1]=0;                                                //~v66tI~
        ilen=1;                                                    //~v5mTI~
    }                                                              //~v5mTI~
    pci=wkebc;                                                     //~v5mTI~
#ifdef LNX                                                         //~v5mtM~
#ifdef UTF8UCS4                                                    //~v66jI~
    olen=sizeof(WUCS);                                             //~v66jI~
#else                                                              //~v66jI~
    olen=2;                                                        //~v5mtM~
#endif                                                             //~v66jI~
    pco=(char*)(ULONG)wkucs;                                       //~v5mTI~
	phiconv=(iconv_t*)Pconverter;                                  //~v5mtM~
    hiconv=phiconv[HICONV_TOUCS];                                  //~v5mtM~
//  outlen=olen;                                                   //~v66VI~//~v6BkR~
    outlen=(int)olen;                                              //~v6BkI~
    UTRACEP("ucvext_iconvebc2ucs iconv hiconv=%p,inp=%02x%02x%02x%02x,ilen=%d,olen=%d\n",hiconv,wkebc[0],wkebc[1],wkebc[2],wkebc[3],ilen,olen);//~v5n7R~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);     //~v5n8R~//~v5ntR~
    rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5ntI~
//  outlen-=olen;                                                  //~v66VI~//~v6BkR~
    outlen-=(int)olen;                                             //~v6BkI~
    UTRACEP("ucvext_iconvebc2ucs iconv rc=%d,ilen=%d,olen=%d,outlen=%d\n",rciconv,ilen,olen,outlen);//~v66VR~
//	if (rciconv==(size_t)-1)                                       //~v66VR~
  	if (rciconv==(size_t)-1||!outlen)                              //~v66VI~
	{                                                              //~v5mTI~
//*dbcs trans by sbcs converter way faile by out area shortage     //~v69cI~
		UTRACEP("ERR iconvebc2ucs1 err=%d,tempclose\n",errno);               //~v5mTI~//~v66jI~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//if not,all folollowing ger errno=22?//~v66jI~
		rc=4;                                                      //~v5mTI~
	}                                                              //~v5mTI~
    else                                                           //~v5mTI~
    {                                                              //~v5mTI~
        *Ppucs=wkucs[0];                                           //~v5mTI~
      	if (rciconv==1)    //not reversive trans count             //~v66DI~
      	{                                                          //~v66DI~
		    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                     //~v66DI~
				rc=UCVEXTRC_SUBCH;                                 //~v66DI~
      	}                                                          //~v66DI~
    }                                                              //~v5mTI~
    UTRACEP("ucvext_iconvebc2ucs rc=%d,ucs=%04x\n",rc,wkucs[0]);   //~v5mTR~
    return rc;
#else                                                              //~v5n1M~
    if (Popt & EBC2ASC_STAT_SO)                                    //~v5n8I~
//  	optw=UCVUCS_MBDBCS;                                        //~v5n8R~//~v69cR~
    	optw=UCVUCS_MBDBCS|UCVUCS_MBDBCS1;   //err if translated count>1//~v69cI~
    else                                                           //~v5n8I~
    	optw=0;                                                    //~v5n8I~
    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                             //~v66DI~
    	optw|=UCVUCS_SETSUBCHRC;                                   //~v66DI~
//  return ucvext_wincp2ucs1(optw/*Popt*/,Pconverter,pci,ilen,Ppucs,0/*out chklen*/);//~v6x5R~
    return ucvext_wincp2ucs1(optw/*Popt*/,(ULONG)Pconverter/*codepage*/,pci,ilen,Ppucs,0/*out chklen*/);//~v6x5I~
#endif                                                             //~v5n1M~
}//ucvext_iconvebc2ucs1                                            //~v5mTR~
//*************************************************************************
//*translate by iconv converter                                    //~v5mTR~
//* local to ucs
//rc :UCEICL2U1ORC_DBCSSPLIT           -11                         //~v62UI~
//    -3:subchar was set                                           //~v66DI~
//*************************************************************************
#ifdef UTF8UCS4                                                    //~v65cI~
//int ucvext_iconvlocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs)//~v6x5R~
int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs)//~v6x5I~
#else                                                              //~v65cI~
//int ucvext_iconvlocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs)//~v6x5R~
//int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs)//~v6x5I~//~v6BjR~
int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS/*int4*/*Ppucs)//~v6BjI~
#endif                                                             //~v65cI~
{
//  WUCS wkucs[MAX_MBCSLEN];                                       //~v5n8R~//~v6BjR~
    UWUCS wkucs[MAX_MBCSLEN];                                      //~v6BjI~
//  int rc=0,ilen,olen,chklen=1;                                   //~v5n1R~//~v624R~
    int rc=0,chklen=1;                                             //~v624I~
    size_t ilen,olen;                                              //~v624I~
	char *pci,*pco;                                                //~v5mTI~
#ifdef LNX                                                         //~v5n1M~
    iconv_t *phiconv,hiconv;                                       //~v5mtM~
    size_t rciconv;                                                //~v5mTI~
//  int ilen0,olen0,ocnt;                                          //~v5n1I~//~v624R~
//  size_t ilen0,olen0,ocnt;                                       //~v62NR~
    size_t ilen0,olen0;                                            //~v62NI~
//    char wkmbs[MAX_MBCSLEN];                                       //~v5n1R~//~v66DR~
//  ULONG ucs;                                                     //~v5n7I~//~v691R~
    UWUCS ucs;                                                     //~v691I~
#else                                                              //~v5n8I~
	int optw;                                                      //~v5n8I~
#endif                                                             //~v5n1I~
#ifdef UTF8SUPPH                                                   //~v62EI~
	#ifndef LNX                                                    //~v6b9I~
        int mbcssw=0;                                              //~v62EI~
    #endif                                                         //~v6b9I~
    #ifdef LNX                                                     //~v62UI~
	    int dbcssplitsw;                                           //~v62UR~
//  	int ocnt;                                                  //~v62UI~//~v6b9R~
    #endif                                                         //~v62UI~
#endif                                                             //~v62EI~
#ifdef UTF8UCS4                                                    //~v65cI~
	int opt;                                                       //~v65cI~
#endif                                                             //~v65cI~
//***************************
    UTRACEP("ucvext_iconvlocal2ucs len=%d,mbs=%02x%02x\n",Pinplen,*Ppmbs,(Pinplen>1?*(Ppmbs+1):0));//~v5mTI~//~v6m2R~//~v6BjR~
//  olen=MAX_MBCSLEN*sizeof(wkucs[0]);                             //~v5n1R~//~v66DR~
    olen=sizeof(wkucs[0]);  //accept 1 output only                 //~v66DI~
    if ((Popt & EBC2ASC_PARMUCVEXT)   //other bit have to be test by UCVEXTO_xxx//~v5ntR~
    &&  (Popt & UCVEXTO_CHARLEN))     //len parm is for one char(for 3 byte euc char)//~v5ntI~
    {                                                              //~v62EI~
//  	ilen=min(MAX_MBCSLEN,Pinplen);     //2byte except GB18030  //~v5ntI~//~v6BkR~
    	ilen=(size_t)min(MAX_MBCSLEN,Pinplen);     //2byte except GB18030//~v6BkI~
#ifdef UTF8SUPPH                                                   //~v62EI~
	#ifndef LNX                                                    //~v6b9I~
        mbcssw=(ilen>1);                                           //~v62EI~
    #endif                                                         //~v6b9I~
#endif                                                             //~v62EI~
    }                                                              //~v62EI~
    else                                                           //~v5ntI~
    if (Popt & EBC2ASC_STAT_SO)  //source is dbcs                  //~v5mTI~
    {                                                              //~v62UR~
#ifdef UTF8SUPPH                                                   //~v62UR~
#ifdef AAA                                                         //~v62UI~
      if (Popt & EBC2ASC_PARMUCVEXT)   //from a2as , consider >2 byte dbcs for STAT_SO flag//~v62UR~
      {                                                            //~v62UR~
      	udbcschk_getmblen(0,Ppmbs,Pinplen,&ilen);                  //~v62UR~
        chklen=ilen;                                               //~v62UI~
        if ((int)ilen>Pinplen && (Popt & EBC2ASC_LNCONT))          //~v62UR~
        {                                                          //~v62UI~
  			if (Ppchklen)                                          //~v62UI~
    			*Ppchklen=chklen;                                  //~v62UI~
        	return 2;                                              //~v62UR~
        }                                                          //~v62UI~
        ilen=chklen=min((int)ilen,Pinplen);                        //~v62UR~
      }                                                            //~v62UR~
      else                                                         //~v62UR~
#endif                                                             //~v62UI~
	#ifdef LNX                                                     //~v62UI~
	  if (Pinplen>1 && UDBCSCHK_ISGB42ND(*(Ppmbs+1)))              //~v66AI~
//  	ilen=min(4,Pinplen);     //4byte GB18030                   //~v66AR~//~v6BkR~
    	ilen=(size_t)min(4,Pinplen);     //4byte GB18030           //~v6BkI~
      else                       //!GB4                            //~v66AI~
	  if (MAYBESS3(*Ppmbs))		//no envchk                        //~v66AI~
//  	ilen=min(3,Pinplen);     //EUC 3fxxxx                      //~v66AI~//~v6BkR~
    	ilen=(size_t)min(3,Pinplen);     //EUC 3fxxxx              //~v6BkI~
      else                       //!GB4                            //~v66AI~
//  	ilen=min(2,Pinplen);     //2byte except GB18030            //~v66AI~//~v6BkR~
    	ilen=(size_t)min(2,Pinplen);     //2byte except GB18030    //~v6BkI~
    #else                                                          //~v62UI~
	  if (Pconverter==CP_GB18030                                   //~v6BrM~
      &&  Pinplen>=4                                               //~v6BrR~
      &&  UDBCSCHK_ISGB4(Ppmbs)                                    //~v6BrM~
      )                                                            //~v6BrI~
    	ilen=4;                                                    //~v6BrM~
      else                                                         //~v6BrM~
    	ilen=min(2,Pinplen);     //2byte except GB18030            //~v62UI~
    #endif                                                         //~v62UI~
#else                                                              //~v62UI~
    	ilen=min(2,Pinplen);     //2byte except GB18030            //~v5n1R~
#endif                                                             //~v62UM~
    }                                                              //~v62UR~
    else                                                           //~v5mTI~
    	ilen=1;                                                    //~v5mTI~
    pci=Ppmbs;                                                     //~v5mTI~
//  pco=(char*)(ULONG)wkucs;                                       //~v5mTI~//~v6hhR~
    pco=(char*)(ULPTR)wkucs;                                       //~v6hhI~
#ifdef LNX                                                         //~v5n1M~
//if (Popt & EBC2ASC_FROMUTF8)                                     //~v5n8R~
  if (Popt & UCVEXTO_FROMUTF8)                                     //~v5n8I~
  {                                                                //~v5n7I~
#ifdef UTF8UCS4                                                    //~v65cI~
	opt=UCVUCS_UCS4; //accept ucs4                                 //~v65cI~
//  if (uccvutf2ucs(opt,pci,Pinplen,&ucs,&chklen))                 //~v65cI~//~v6BkR~
    if (uccvutf2ucs((ULONG)opt,pci,Pinplen,&ucs,&chklen))          //~v6BkI~
#else                                                              //~v65cI~
	if (uccvutf2ucs(0,pci,Pinplen,&ucs,&chklen))                   //~v5n7I~
#endif                                                             //~v65cI~
    {                                                              //~v5n7I~
    	rc=4;                                                      //~v5n7I~
        chklen=1;                                                  //~v5n7I~
    }                                                              //~v5n7I~
    else                                                           //~v5n7I~
//      wkucs[0]=(USHORT)ucs;                                      //~v5n7I~//~v692R~
        wkucs[0]=(WUCS)ucs;                                        //~v692R~
  }                                                                //~v5n7I~
  else                                                             //~v5n7I~
  {                                                                //~v5n7I~
	phiconv=(iconv_t*)Pconverter;                                  //~v5mtM~
    hiconv=phiconv[HICONV_TOUCS];                                  //~v5mtM~
	ilen0=ilen;                                                    //~v5n1I~
	olen0=olen;                                                    //~v5n1I~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);     //~v5n8R~//~v5ntR~
    rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5ntI~
#ifdef UTF8SUPPH                                                   //~v62UI~
    dbcssplitsw=(rciconv==(size_t)-1 && errno==EINVAL);   //correspond to rc=-2 from mbr2wc//~v62UR~
#endif                                                             //~v62UI~
//    UTRACEP("iconvlocal2ucs rciconv=%d,hiconv=%x,ilen=%d,olen=%d\n",rciconv,hiconv,ilen,olen);//~v62NR~//~v6m2R~
//    UTRACED("iconvlocal2ucs out",wkucs,4);                         //~v65cI~//~v6m2R~
//  if (rciconv==(size_t)-1)                                       //~v5mTI~//~v62NR~
    if (olen==olen0)                                               //~v62NI~
	{                                                              //~v5mTI~
		UTRACEP("ERR iconvlocal2ucs1 err=%d\n",errno);             //~v5mTI~
#ifdef UTF8SUPPH                                                   //~v62UI~
      if (dbcssplitsw)                                             //~v62UI~
		rc=UCEICL2U1ORC_DBCSSPLIT;//           -11                 //~v62UI~
      else                                                         //~v62UI~
#endif                                                             //~v62UI~
		rc=4;                                                      //~v5mTI~
	}                                                              //~v5mTI~
    else                                                           //~v5n1I~
    {                                                              //~v5n1I~
//      chklen=ilen0-ilen;                                         //~v5n1I~//~v62NR~
//  	ocnt=(olen0-olen)/sizeof(wkucs[0]);		//ucs count        //~v5n1I~//~v62NR~
//      if (ocnt>0)                                                //~v5n1I~//~v62NR~
//        if (Ppchklen)	//readlen output required                  //~v5n8I~//~v62NR~
//  		rc=ucvext_iconvucs2local1(Popt,Pconverter,wkucs[0],wkmbs,&chklen);//get chklen for 1 ucs//~v5n8R~
#ifdef UTF8SUPPH                                                   //~v62UI~
//      chklen=ilen0-ilen;                                         //~v62UI~//~v6BkR~
        chklen=(int)(ilen0-ilen);                                  //~v6BkI~
//  	ocnt=(olen0-olen)/sizeof(wkucs[0]);		//ucs count        //~v62UI~//~v6b9R~
//        UTRACEP("iconvlocal2ucs chklen=%d,ocnt=%d\n",chklen,/*ocnt*/(olen0-olen)/sizeof(wkucs[0])); //~v62UI~//~v6b9R~//~v6m2R~
//    if (rciconv||ocnt>1)    //get input string for 1 ucs         //~v62UR~//~v66DR~
#endif                                                             //~v62UI~
//    {                                                            //~v62UI~//~v66DR~
//  		rc=ucvext_iconvucs2local1((Popt&~UCVEXTO_TOUTF8),Pconverter,wkucs[0],wkmbs,&chklen);//get chklen for 1 ucs//~v5n8I~//~v66DR~
//      if (rc>1 || !chklen || memcmp(wkmbs,Ppmbs,chklen))         //~v62NR~//~v66DR~
//      	rc=8;                                                  //~v62NI~//~v66DR~
//      UTRACEP("iconvlocal2ucs reverse chk rc=%d,chklen=%d\n",rc,chklen);//~v62NI~//~v66DR~
//    }                                                            //~v62UI~//~v66DR~
      if (rciconv)    //not reversivele                            //~v66DI~
		    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                     //~v66DI~
				rc=UCVEXTRC_SUBCH;                                 //~v66DI~
    }                                                              //~v5n1I~
  }                                                                //~v5n7I~
#else                                                              //~v5n1R~
    if (Pconverter==CP_UTF8)                                       //~v5n6I~
    	ilen=Pinplen;                                              //~v5n6I~
    if (Popt & EBC2ASC_STAT_SO)                                    //~v5n8I~
    	optw=UCVUCS_MBDBCS;                                        //~v5n8R~
    else                                                           //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62EI~
      if (mbcssw)	//CHARLEN specified DBCS                       //~v62EI~
    	optw=UCVUCS_MBDBCS;	//request return chklen=2              //~v62EI~
      else                                                         //~v62EI~
#endif                                                             //~v62EI~
//  	optw=0;                                                    //~v5n8I~//~v66NR~
	optw=UCVUCS_LOCALCV;                                           //~v66NI~
    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                             //~v66DI~
    	optw|=UCVUCS_SETSUBCHRC;                                   //~v66DI~
//  rc=ucvext_wincp2ucs1(optw/*Popt*/,Pconverter,Ppmbs,ilen,wkucs,&chklen);//~v6x5R~
//  rc=ucvext_wincp2ucs1(optw/*Popt*/,(ULONG)Pconverter/*codepge*/,Ppmbs,ilen,wkucs,&chklen);//~v6x5I~//~v6BjR~
    rc=ucvext_wincp2ucs1(optw/*Popt*/,(ULONG)Pconverter/*codepge*/,Ppmbs,ilen,wkucs/*UCS4[]*/,&chklen);//~v6BjR~
#endif                                                             //~v5n1I~
	if (!rc)                                                       //~v5n1I~
        *Ppucs=wkucs[0];                                           //~v5mTI~
    else                                                           //~v66DI~
	if (rc==UCVEXTRC_SUBCH)                                        //~v66DI~
        *Ppucs=wkucs[0];                                           //~v66DI~
//#ifdef AAA                                                         //~v62NI~//~v66DR~
//    else                                                           //~v5n1I~//~v66DR~
//        chklen=1+((Popt & EBC2ASC_STAT_SO)!=0);                    //~v5n1I~//~v66DR~
//#endif                                                             //~v62NI~//~v66DR~
  if (Ppchklen)                                                    //~v5n8I~
    *Ppchklen=chklen;                                              //~v5mTI~
//    UTRACEP("ucvext_iconvlocal2ucs rc=%d,readlen=%d,ucs=%04x\n",rc,chklen,*Ppucs);//~v5mTR~//~v6m2R~
    return rc;
}//ucvext_iconvlocal2ucs1                                          //~v5mTR~
//*************************************************************************
//*translate by icu converter
//* ucs to ebc
//* rc: 1:dbcs
//    -3:subchar was set                                           //~v66DI~
//*************************************************************************
//int ucvext_iconvucs2ebc1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v5mTR~//~v692R~
//int ucvext_iconvucs2ebc1(int Popt,ULONG Pconverter,WUCS Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6x5R~
//int ucvext_iconvucs2ebc1(int Popt,ULPTR Pconverter,WUCS Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6x5I~//~v6BjR~
int ucvext_iconvucs2ebc1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppebc,int *Ppoutlen)//~v6BjI~
{                                                                  //~v5mTI~
    int rc=0,len;                                                  //~v5n1R~
	char wkebc[8]; 	//mex ebc dbcs is 4 for chinese                //~v5n1R~
#ifdef W32                                                         //~v66DI~
    int opt,rc2;                                                   //~v66DI~
#endif                                                             //~v66DI~
#ifdef LNX                                                         //~v5n1M~
//  int ilen,olen;                                                 //~v5n1I~//~v624R~
    size_t ilen,olen;                                              //~v624I~
	char *pci,*pco,*pco0; 	//mex ebc dbcs is 4 for chinese        //~v5n1R~
    iconv_t *phiconv,hiconv;                                       //~v5mTI~
#ifdef UTF8UCS4                                                    //~v66jI~
  	WUCS   wkucs[2];                                               //~v66jI~
#else                                                              //~v66jI~
	USHORT wkucs[2];                                               //~v5mTI~
#endif                                                             //~v66jI~
    size_t rciconv;                                                //~v5mTI~
//***************************
	phiconv=(iconv_t*)Pconverter;                                  //~v5mTR~
    hiconv=phiconv[HICONV_FROMUCS];                                //~v5mTI~
    wkucs[0]=Pucs;                                                 //~v5mTI~
#ifdef UTF8UCS4                                                    //~v66jI~
    ilen=sizeof(WUCS);                                             //~v66jI~
#else                                                              //~v66jI~
    ilen=2;                                                        //~v5mTR~
#endif                                                             //~v66jI~
    olen=sizeof(wkebc);                                            //~v5mTI~
    pci=(char*)(ULONG)wkucs;                                       //~v5mTR~
    pco=pco0=wkebc;                                                //~v5mTI~
    UTRACEP("ucvext_iconvucs2ebc1 hiconv=%p,ucs=%04x\n",hiconv,Pucs);//~v5mTI~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);     //~v5n8R~//~v5ntR~
    rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5ntI~
    UTRACEP("ucvext_iconvucs2ebc1 iconv rc=%d ilen=%d,olen=%d\n",rciconv,ilen,olen);//~v5mTR~
    UTRACED("ucvext_iconvucs2ebc1 iconv out",wkebc,sizeof(wkebc)); //~v5mTI~
	if (rciconv==(size_t)-1)                                       //~v5mTI~
	{                                                              //~v5mTI~
		UTRACEP("ERR iconvucs2ebc1 err=%d,tempclose\n",errno);               //~v5mTI~//~v66jR~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//if not,all folollowing ger errno=22?//~v66jI~
		rc=4;                                                      //~v5mTI~
	}                                                              //~v5mTI~
    else                                                           //~v5n1I~
    {                                                              //~v66DI~
    	len=(int)((ULONG)pco-(ULONG)pco0);                         //~v5n1M~
      	if (rciconv==1)    //not reversive trans count             //~v66DI~
      	{                                                          //~v66DI~
		    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                     //~v66DI~
				rc=UCVEXTRC_SUBCH;                                 //~v66DI~
      	}                                                          //~v66DI~
    }                                                              //~v66DI~
#else                                                              //~v5n1M~
//  if (ucvext_winucs2cp1(0/*Popt*/,Pconverter,Pucs,wkebc,&len)>1) //~v5n8R~//~v66DR~
    opt=0;                                                         //~v66DI~
    if (Popt & EBC2ASC_EXT_SETSUBCHRC)                             //~v66DI~
    	opt|=UCVUCS_SETSUBCHRC;                                    //~v66DI~
//  rc2=ucvext_winucs2cp1(opt,Pconverter,Pucs,wkebc,&len);         //~v6x5R~
    rc2=ucvext_winucs2cp1(opt,(ULONG)Pconverter/*codepage*/,Pucs,wkebc,&len);//~v6x5I~//~v6BjR~
    if (rc2>1)                                                     //~v66DI~
		rc=4;                                                      //~v5n1M~
    else                                                           //~v66DI~
    if (rc2==UCVEXTRC_SUBCH)                                       //~v66DR~
    	rc=rc2;	//rcsubch                                          //~v66DI~
#endif                                                             //~v5n1M~
//  if (!rc)                                                       //~v66DR~
    if (!rc||rc==UCVEXTRC_SUBCH)                                   //~v66DI~
    {                                                              //~v5mTI~
        if (len==3 && wkebc[0]==CHAR_SO)                           //~v5mTR~
        {                                                          //~v5mTI~
        	len--;                                                 //~v5mTI~
	        memcpy(Ppebc,wkebc+1,(UINT)len);                       //~v5mTR~
        }                                                          //~v5mTI~
        else	                                                   //~v5mTI~
        	memcpy(Ppebc,wkebc,(UINT)len);                         //~v5mTR~
        *Ppoutlen=len;                                             //~v5mTI~
    UTRACED("ucvext_iconvucs2ebc1 out",Ppebc,len);                 //~v5mTR~
    }                                                              //~v5mTI~
    return rc;
}//ucvext_iconvucs2ebc1                                            //~v5mTR~
#ifdef W32                                                         //~v5n1I~
//*************************************************************************//~v5n1M~
//*translate by win API                                            //~v5n1M~
//* ucs to windows codepage                                        //~v5n1M~
//* rc=1:dbcs,-3:subchar was set                                   //~v5n1M~//~v66DR~
//*************************************************************************//~v5n1M~
//int ucvext_winucs2cp1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v5n1M~//~v6BjR~
int ucvext_winucs2cp1(int Popt,ULONG Pconverter,UWUCS/*int4*/Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6BjI~
{                                                                  //~v5n1M~
	int ctr,rc=0,opt;                                              //~v5n5R~
    UCHAR wkmbs[8];                                                //~v5n1M~
    BOOL errrepflag;                                               //~v62EI~
    WUCS ucs2[2];                                                  //~v6BjR~
    int utf16ctr;                                                  //~v6BjI~
    BOOL *perrrepflag;                                             //~v6BpR~
    int lasterr;                                                   //~v6BII~
//*********************                                            //~v5n1M~
    UTRACEP("winucs2cp1 win fromucs1 opt=%x,ucs=%x,cv=%p\n",Popt,Pucs,Pconverter);//~v5n1R~//~v624R~//~v6BjR~
  	if (Pconverter==CP_UTF8)	//to utf8                          //~v6fqI~
    {                                                              //~v6fqI~
		ctr=uccvucs2utf((ULONG)Pucs,Ppmbs);                        //~v6fqI~
    	if (!ctr)                                                  //~v6fqI~
      		rc=4;                                                  //~v6fqI~
        *Ppoutlen=ctr;                                             //~v6fqI~
        return rc;                                                 //~v6fqI~
    }                                                              //~v6fqI~
    UCS4_TO_UTF16(Pucs,ucs2,&utf16ctr);                            //~v6BjR~
    UTRACEP("%s:surrogate for %x=(%x,%x),ctr=%d\n",UTT,Pucs,ucs2[0],(utf16ctr==2?ucs2[1]:0),utf16ctr);//~v6BjR~//~v6BkR~
#ifdef AAA                                                         //~v66tR~
  if (Pconverter==CP_UTF8||Pconverter==CP_UTF7)                    //~v5n6R~
  	opt=0;                                                         //~v5n6R~
  else                                                             //~v5n6R~
    opt=WC_COMPOSITECHECK			//output compose char          //~v5n1M~
      ;                                                            //~v5n1M~
//  opt|=WC_NO_BEST_FIT_CHARS;       //ver>=0500                   //~v630R~
    opt|=0x400;//WC_NO_BEST_FIT_CHARS;       //ver>=0500           //~v630R~
#else                                                              //~v66tM~
  	opt=0; //ex. Wincp-20294,err(no=183) if COMPOSITECHK on for 0xb9(EBC)<--u-0178//~v66tM~
    opt|=0x400;//WC_NO_BEST_FIT_CHARS;       //ver>=0500           //~v66DI~
#endif                                                             //~v66tM~
//  ctr=WideCharToMultiByte(Pconverter,opt,&Pucs,1,wkmbs,sizeof(wkmbs),0/*errrep*/,&errchused);//~v5n5R~
//  ctr=WideCharToMultiByte(Pconverter,opt,&Pucs,1,wkmbs,sizeof(wkmbs),0/*errrep*/,0);//~v5n5I~//~v62ER~
    perrrepflag=&errrepflag;                                       //~v6BpR~
//  if (Pconverter==CP_GB18030                                       //~v65jI~//~v6BIR~
//  )                                                                //~v65jI~//~v6BIR~
//  {                                                                //~v6BpR~//~v6BIR~
//    opt=0;                                                         //~v65cI~//~v6BIR~
//    perrrepflag=0;                                                 //~v6BpR~//~v6BIR~
//  }                                                                //~v6BpR~//~v6BIR~
//    errrepflag=0;                                                  //~v62ER~//~v6BIR~
//  ctr=WideCharToMultiByte(Pconverter,opt,&Pucs,1,wkmbs,sizeof(wkmbs),0/*subchar*/,&errrepflag);//~v62EI~//~v6BjR~
//  ctr=WideCharToMultiByte(Pconverter,opt,ucs2,utf16ctr,wkmbs,sizeof(wkmbs),0/*subchar*/,&errrepflag);//~v6BjI~//~v6BpR~
//  ctr=WideCharToMultiByte(Pconverter,opt,ucs2,utf16ctr,wkmbs,sizeof(wkmbs),0/*subchar*/,perrrepflag);//~v6BpR~//~v6BIR~
    ctr=uWideCharToMultiByte(0,Pconverter,opt,ucs2,utf16ctr,wkmbs,sizeof(wkmbs),0/*subchar*/,&errrepflag,&lasterr);//~v6BIR~
    UTRACEP("%s: converter=%d,ucs=%x,opt=%x,ctr=%d,errflag=%x,lasterr=%d\n",UTT,Pconverter,Pucs,opt,ctr,errrepflag,lasterr);//~v630R~//~v65cR~//~v6BpR~//~v6BHR~//~v6BIR~
    UTRACED("out wkmbs",wkmbs,ctr);                                //~v630I~
    if (errrepflag)                     //replaced by subchar      //~v62ER~
//  	if (Popt & UCVEXTO_PARMUCVEXT   //not EBC2ASC              //~v62EI~//~v630R~
//  	&&  Popt & UCVEXTO_ERRRET)  //return if err detected for ucvext_iconvucs2local1 =EBC2ASC_SOSI//~v62EI~//~v630R~
    {                                                              //~v66DI~
		if (Popt & UCVUCS_MBDBCS)                                  //~v66QR~
        {                                                          //~v66QI~
            if (ctr==1)//sbcs output                               //~v66QI~
            {                                                      //~v66QR~
//              if (Popt & UCVUCS_LOCALCV                          //~v66QR~//~v6BqR~
                if (!(Popt & UCVUCS_LOCALCV) //not from ucvext_iconvucs2local1//~v6BqI~
                &&  Spcfg                                          //~v6BnI~
                &&  *wkmbs==Spcfg->UCECsubchardefaultmblocal)      //~v66QR~
                    ctr=0;                                         //~v66QR~
            }                                                      //~v66QR~
        }                                                          //~v66QI~
//      if (!(Popt & UCVUCS_SETSUBCHRC)||ctr>1)                    //~v66DI~//~v6BmR~
        if (!(Popt & UCVUCS_SETSUBCHRC))                           //~v6BmI~
        	ctr=0;		//return with err                          //~v62EI~
        else                                                       //~v6BmI~
            if (ctr>1)                                             //~v6BmI~
            	ctr=1;	//output 1 subchar                         //~v6BmI~
                                                                   //~v6BmI~
    }                                                              //~v66DI~
	if (!ctr)                                                      //~v5n1M~
    {                                                              //~v5n1M~
    	UTRACEP("%s:ERR ucs=%04x,lasterr=%d,errrepflag=%d\n",UTT,Pucs,GetLastError(),errrepflag);//~v5n1M~//~v62ER~//~v6BHR~
    	*Ppoutlen=ctr;                                             //~v6BII~
    	rc=4;                                                      //~v5n1M~
    }                                                              //~v5n1M~
    else                                                           //~v5n1M~
    {                                                              //~v5n1M~
    	*Ppoutlen=ctr;                                             //~v5n1M~
        if (ctr>1)                                                 //~v5n1M~
        {                                                          //~v5n1M~
            memcpy(Ppmbs,wkmbs,(UINT)ctr);                         //~v5n1M~
        	rc=1;                                                  //~v5n1M~
        }                                                          //~v5n1M~
        else                                                       //~v5n1M~
            *Ppmbs=*wkmbs;                                         //~v5n1M~
	    if (errrepflag)                     //replaced by subchar  //~v66DI~
    		rc=UCVEXTRC_SUBCH;                                     //~v66DI~
    }                                                              //~v5n1M~
    UTRACEP("winucs2cp1 fromucs1 rc=%d\n",rc);                            //~v5n1M~//~v624R~
    UTRACED("winucs2cp1 fromucs1",Ppmbs,ctr);                             //~v5n1M~//~v624R~
    return rc;                                                     //~v5n1M~
}//ucvext_winucs2cp1                                               //~v5n1M~
//*************************************************************************//~v6k4I~
//*translate at once by win API                                    //~v6k4I~
//* ucs to windows codepage                                        //~v6k4I~
//* rc=-3(RC_SUBCH):errrep occured,else GetLastError()             //~v6k4I~
//*************************************************************************//~v6k4I~
int ucvext_winucs2cp(int Popt,ULONG Pconverter,USHORT *Ppucs,int Pucsctr,UCHAR *Ppmbs,int Pbuffsz,int *Ppoutlen)//~v6k4I~
{                                                                  //~v6k4I~
	int bytectr,rc=0,opt;                                          //~v6k4I~
    BOOL errrepflag=FALSE;	//set true when set subchar            //~v6k4I~
//  BOOL *perrrepflag;                                             //~v6BFR~//~v6BIR~
    int lasterr;                                                   //~v6BII~
    int wctmbopt=0;                                                //~v6E1I~
//*********************                                            //~v6k4I~
    UTRACEP("winucs2cp win fromucs opt=%x,cv=%x,buffsz=%d\n",Popt,Pconverter,Pbuffsz);//~v6k4I~
    UTRACED("winucs2cp input",Ppucs,Pucsctr*2);                    //~v6k4I~
  	opt=0; //ex. Wincp-20294,err(no=183) if COMPOSITECHK on for 0xb9(EBC)<--u-0178//~v6k4I~
  if (Pconverter!=CP_UTF8)                                         //~v6r1I~
  {                                                                //~v6r1I~
//  opt|=WC_COMPOSITECHECK; 		//output composed char         //~v6k4R~//~v6E1R~
   if (!(Popt & UCVUCS_BESTFIT))                                   //~v6u0I~//~v6u9I~
    opt|=0x0400;//WC_NO_BEST_FIT_CHARS;       //0x0400 ver>=0500   //~v6k4R~
  }                                                                //~v6r1I~
//  if (Pconverter==CP_GB18030                                     //~v6k4I~
//  )                                                              //~v6k4I~
//    opt=0;                                                       //~v6k4I~
//  perrrepflag=&errrepflag;                                       //~v6BFR~//~v6BIR~
//	if (Pconverter==CP_GB18030)                                    //~v6BFR~//~v6BIR~
//	{                                                              //~v6BFI~//~v6BIR~
//  	opt=0;                                                     //~v6BFI~//~v6BIR~
//      perrrepflag=NULL;                                          //~v6BFR~//~v6BIR~
//	}                                                              //~v6BFI~//~v6BIR~
//    if (Popt & UCVUCS_SETSUBCHRC)                                //~v6E1R~
//        wctmbopt|=UWCTMBO_SETSUBCHRC;//      0x01  //reverse chk //~v6E1R~
  if (Pconverter==CP_UTF8)                                         //~v6r1I~
//  bytectr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,NULL/*default used*/);//~v6r1I~//~v6BIR~
    bytectr=uWideCharToMultiByte(0,Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,NULL/*default used*/,&lasterr);//~v6BII~
  else                                                             //~v6r1I~
//  bytectr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,&errrepflag);//~v6k4I~//~v6BFR~
//  bytectr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,perrrepflag);//~v6BFI~//~v6BIR~
//  bytectr=uWideCharToMultiByte(0,Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,&errrepflag,&lasterr);//~v6BIR~//~v6E1R~
    bytectr=uWideCharToMultiByte(wctmbopt,Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,NULL/*subchar*/,&errrepflag,&lasterr);//~v6E1R~
    UTRACEP("WideCharToMultiByte ucsctr=%d,cp=%d,buffsz=%d,opt=%x,ouctr=%d,errflag=%x,lasterr=%d\n",Pucsctr,Pconverter,Pbuffsz,opt,bytectr,errrepflag,lasterr);//~v6r1R~//~v6BFR~//~v6BIR~
    UTRACED("outmbs",Ppmbs,bytectr);                               //~v6k4R~
    if (!bytectr)   //cv err                                       //~v6k4R~
//  	rc=GetLastError();                                         //~v6k4I~//~v6E1R~
    	rc=lasterr;                                                //~v6E1I~
    else                                                           //~v6k4I~
    {                                                              //~v6k4I~
   		if (errrepflag)    //replaced by subchar                   //~v6k4I~
			if (Popt & UCVUCS_SETSUBCHRC)                          //~v6k4I~
	    		rc=UCVEXTRC_SUBCH;                                 //~v6k4I~
    }                                                              //~v6k4I~
    *Ppoutlen=bytectr;                                             //~v6k4I~
                                                                   //~v6k4I~
    UTRACEP("winucs2cp fromucs rc=%d,outctr=%d\n",rc,bytectr);     //~v6k4R~
    return rc;                                                     //~v6k4I~
}//ucvext_winucs2cp                                                //~v6k4I~
#endif //W32                                                       //~v5n1I~
//*************************************************************************
//*translate by icu converter
//* ucs to local
//rc:-3:subchar was set                                            //~v66DI~
//*************************************************************************
#ifdef UTF8UCS4                                                    //~v65cI~
//int ucvext_iconvucs2local1(int Popt,ULONG Pconverter,WUCS   Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6x5R~
int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,WUCS   Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6x5I~
#else                                                              //~v65cI~
//int ucvext_iconvucs2local1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6x5R~
//int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6x5I~//~v6BjR~
int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen)//~v6BjI~
#endif                                                             //~v65cI~
{
#ifdef W32                                                         //~v66DI~
	int opt,rc2;                                                   //~v66DI~
#endif                                                             //~v66DI~
	char wkmbs[8]; 	//mex ebc dbcs is 4 for chinese                //~v5n1R~
    int rc=0,len;                                                  //~v5n1R~
#ifdef LNX                                                         //~v5mtM~
    iconv_t *phiconv,hiconv;                                       //~v5n1M~
	char *pci,*pco,*pco0;                                          //~v5n1I~
//  int ilen,olen;                                                 //~v5n1I~//~v624R~
    size_t ilen,olen;                                              //~v624I~
#ifdef UTF8UCS4                                                    //~v65cI~
  	WUCS   wkucs[2];                                               //~v65cI~
#else                                                              //~v65cI~
//    USHORT wkucs[2];                                               //~v5mTI~//~v6BjR~
#endif                                                             //~v65cI~
    size_t rciconv;                                                //~v5mTI~
#endif                                                             //~v5n1I~
//***************************
//if (Popt & UCVEXTO_TOUTF8)	//to UTF8                          //~v5n8R~//~v6m2R~
  if (UCVEXT_TOUTF8_CHKON())	//to UTF8                          //~v6m2I~
  {                                                                //~v5n8I~
//	len=uccvucs2utf((ULONG)Pucs,wkmbs);                            //~v5n8R~//~v6BkR~
  	len=uccvucs2utf((UWUCS)Pucs,wkmbs);                            //~v6BkI~
//    UTRACEP("ucvext_iconvucs2local  ucs2utf ucs=%x,len=%d\n",Pucs,len);//~v6k4I~//~v6m2R~
    if (!len)                                                      //~v5n8I~
      	rc=4;                                                      //~v5n8I~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
  {                                                                //~v5n8I~
#ifdef LNX                                                         //~v5mtM~
	phiconv=(iconv_t*)Pconverter;                                  //~v5mTR~
    hiconv=phiconv[HICONV_FROMUCS];                                //~v5mTI~
    wkucs[0]=Pucs;                                                 //~v5mTI~
#ifdef UTF8UCS2                                                    //~v65cI~
    ilen=sizeof(wkucs[0]);                                         //~v65cI~
#else                                                              //~v65cI~
    ilen=2;                                                        //~v5mTR~
#endif                                                             //~v65cI~
    olen=sizeof(wkmbs);                                            //~v5mTI~
    pci=(char*)(ULONG)wkucs;                                       //~v5mTR~
    pco=pco0=wkmbs;                                                //~v5mTI~
//    UTRACEP("ucvext_iconvucs2local hiconv=%p,ucs=%04x\n",hiconv,Pucs);//~v5mTI~//~v6m2R~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);     //~v5n8R~//~v5ntR~
    rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5ntI~
//    UTRACEP("ucvext_iconvucs2local hiconv=%x,iconv rc=%d ilen=%d,olen=%d\n",hiconv,rciconv,ilen,olen);//~v62NR~//~v6m2R~
//    UTRACED("ucvext_iconvucs2local",wkmbs,sizeof(wkmbs));          //~v5mtR~//~v6m2R~
    	len=(int)((ULONG)pco-(ULONG)pco0);                         //~v6uMI~
	if (!rciconv && UCS_IS80FF(Pucs) && len>2)                     //~v6uMI~
    {                                                              //~v6uMI~
		UTRACED("%s:ERR iconv IS80FF to EUC ucs=%x\n",UTT,Pucs);   //~v6uMI~
		UTRACED("ERR iconv IS80FF to EUC",pco0,len);               //~v6uMI~
		rc=4;                                                      //~v6uMI~
    }                                                              //~v6uMI~
    else                                                           //~v6uMI~
	if (rciconv==(size_t)-1)                                       //~v5mTI~
	{                                                              //~v5mTI~
		UTRACEP("ERR iconvucs2local1 err=%d\n",errno);             //~v5mTI~
		rc=4;                                                      //~v5mTI~
	}                                                              //~v5mTI~
    else                                                           //~v5n1I~
    {                                                              //~v66DI~
//  	len=(int)((ULONG)pco-(ULONG)pco0);                         //~v5n1M~//~v6uMR~
      	if (rciconv==1)    //not reversive trans count             //~v66DI~
      	{                                                          //~v66DI~
        	if (Popt & EBC2ASC_EXT_SETSUBCHRC)                     //~v66DI~
				rc=UCVEXTRC_SUBCH;                                 //~v66DI~
      	}                                                          //~v66DI~
    }                                                              //~v66DI~
#else                                                              //~v5n1M~
//  if (ucvext_winucs2cp1(0/*Popt*/,Pconverter,Pucs,wkmbs,&len)>1) //~v5n8R~//~v62ER~
//  if (ucvext_winucs2cp1(Popt/*errret*/,Pconverter,Pucs,wkmbs,&len)>1)//~v62EI~//~v66DR~
//  opt=0;                                                         //~v66DI~//~v66QR~
	opt=UCVUCS_LOCALCV; //chk local subchar                        //~v66QI~
  if (Popt & EBC2ASC_STAT_SO)                                      //~v66QI~
    opt|=UCVUCS_MBDBCS;                                            //~v66QI~
 if (Popt & EBC2ASC_EXT_SETSUBCHRC)                            //~v66DI~//~v66QR~
    	opt|=UCVUCS_SETSUBCHRC;                                    //~v66DI~
//  rc2=ucvext_winucs2cp1(opt,Pconverter,Pucs,wkmbs,&len);         //~v6x5R~
    rc2=ucvext_winucs2cp1(opt,(ULONG)Pconverter/*codepage*/,Pucs,wkmbs,&len);//~v6x5I~
    if (rc2>1)                                                     //~v66DI~
		rc=4;                                                      //~v5n1M~
    else                                                           //~v66DI~
    if (rc2==UCVEXTRC_SUBCH)                                       //~v66DR~
    	rc=rc2;	//rcsubch                                          //~v66DI~
#endif                                                             //~v5n1M~
  }//to utf                                                        //~v5n8I~
//  if (!rc)                                                       //~v66DR~
    if (!rc||rc==UCVEXTRC_SUBCH)                                   //~v66DI~
    {                                                              //~v5mTI~
        memcpy(Ppmbs,wkmbs,(UINT)len);                             //~v5mTI~
        *Ppoutlen=len;                                             //~v5mTI~
    }                                                              //~v5mTI~
    return rc;
}//ucvext_iconvucs2local1                                          //~v5mTR~
#ifdef W32                                                         //~v5mtI~
//*************************************************************************//~v5mtI~
//*get subchar by unicode(CPFROM) and mb(CPTO)                     //~v5mtI~
//* any to any                                                     //~v5mtI~
//*************************************************************************//~v5mtI~
int ucvext_getsubch(int Popt,ULONG Pcpfrom,ULONG Pcpto,int *Ppsbcsf,int *Ppdbcsf,int *Ppsbcst,int *Ppdbcst)//~v5mtI~
{                                                                  //~v5mtI~
static ULONG Scpfrom,Scpto;                                        //~v5mtI~
static int Ssubchucs_from,Ssubchmb_from,Ssubchsbcs_to,Ssubchdbcs_to;//~v5mtR~
	char wkmbs[MAX_MBCSLEN];                                       //~v5mtI~
    int outlen,rc2,subchucs_to,dbcsf,sbcsf,dbcst,sbcst;            //~v5mtR~
//**********************                                           //~v5mtI~
    if (Scpfrom!=Pcpfrom)                                          //~v5mtI~
    {                                                              //~v5mtI~
        Scpfrom=Pcpfrom;                                           //~v5mtI~
        udbcschk_getsubch(0,Scpfrom,&Ssubchmb_from,&Ssubchucs_from);//~v5mtI~
    }                                                              //~v5mtI~
    if (Scpto!=Pcpto)                                              //~v5mtI~
    {                                                              //~v5mtI~
        Scpto=Pcpto;                                               //~v5mtI~
        udbcschk_getsubch(0,Pcpto,&Ssubchsbcs_to,&subchucs_to);    //~v5mtI~
//  	rc2=ucvext_winucs2cp1(0,Pcpto,(USHORT)subchucs_to,wkmbs,&outlen);//~v5mtR~//~v6BjR~
    	rc2=ucvext_winucs2cp1(0,Pcpto,(UWUCS)subchucs_to,wkmbs,&outlen);//~v6BjI~
        Ssubchdbcs_to=0;                                           //~v5mtI~
        if (!rc2)                                                  //~v5mtI~
        	if (outlen>1)                                          //~v5mtI~
            	Ssubchdbcs_to=wkmbs[0]<<8|wkmbs[1];                //~v5mtI~
    }                                                              //~v5mtI~
    if (Ssubchucs_from & 0xff00)                                   //~v5mtI~
    {                                                              //~v5mtI~
        dbcsf=Ssubchucs_from;                                      //~v5mtI~
        sbcsf=Ssubchmb_from;                                       //~v5mtI~
    }                                                              //~v5mtI~
    else                                                           //~v5mtI~
    {                                                              //~v5mtI~
        dbcsf=UDBCSCHK_SUBCHAR_DBCS;                               //~v5mtI~
        sbcsf=Ssubchucs_from;                                      //~v5mtI~
    }                                                              //~v5mtI~
    dbcst=Ssubchdbcs_to;                                           //~v5mtI~
    sbcst=Ssubchsbcs_to;                                           //~v5mtI~
    if (Ppsbcsf)                                                   //~v5mtI~
    	*Ppsbcsf=sbcsf;                                            //~v5mtI~
    if (Ppdbcsf)                                                   //~v5mtI~
    	*Ppdbcsf=dbcsf;                                            //~v5mtR~
    if (Ppsbcst)                                                   //~v5mtI~
    	*Ppsbcst=sbcst;                                            //~v5mtR~
    if (Ppdbcst)                                                   //~v5mtI~
    	*Ppdbcst=dbcst;                                            //~v5mtR~
UTRACEP("getsubch from=%04x,%04x,to=%04x,%04x\n",sbcsf,dbcsf,sbcst,dbcst);//~v5mtI~
	return 0;                                                      //~v5mtI~
}//ucvext_getsubch                                                 //~v5mtI~
#endif                                                             //~v5mtI~
//*************************************************************************//~v5n1I~
//*translate by iconv/winapi                                       //~v5n1I~
//* any to any                                                     //~v5n1I~
//*   should return from end of func(Gpdbcstbl/Gudbcschk_flag is temporary modified)//~v62UI~
//*************************************************************************//~v5n1I~
//int ucvext_iconva2as(int Popt,ULONG *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,int Perrrep,int *Pprepctr)//~v5n3R~//~v6hhR~
int ucvext_iconva2as(int Popt,ULPTR *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,int Perrrep,int *Pprepctr)//~v6hhI~
{                                                                  //~v5n1I~
//  int rc=0,outlen,reslen,repch,repchdbcs,repchdbcs1,repchdbcs2,chklen,rc2,opt,dbcssw;//~v5n1R~//~v6h7R~
    int rc=0,outlen=0,reslen,repch,repchdbcs,repchdbcs1,repchdbcs2,chklen,rc2,opt,dbcssw;//~v6h7I~
    UCHAR *pci,*pco,*pce,*pcoe;                                    //~v5n8R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6BjR~
//    WUCS   wkucs[2];                                               //~v65cI~//~v6BjR~
//#else                                                              //~v65cI~//~v6BjR~
//    USHORT wkucs[2];                                               //~v5mtR~//~v6BjR~
//#endif                                                             //~v65cI~//~v6BjR~
    UWUCS   wkucs[2];	//ucs4                                     //~v6BjI~
    int subchdbcs='?',subchsbcs='?',subch;                                 //~v5mtI~//~v6h7R~
    UCHAR *pdbcsstarter;                                           //~v5n1I~
    iconv_t hiconv_from,hiconv_to;                                 //~v5mtR~
    int repctr=0,errrepsw,readlen;                                 //~v5n3I~
#ifdef UTF8SUPPH                                                   //~v62UI~
#ifdef AAA                                                         //~v62UI~
    char *sv_pdbcst;                                               //~v62UR~
    int   sv_udbcschk_flag;                                        //~v62UR~
#endif                                                             //~v62UI~
	int mblen;                                                     //~v62UI~
#endif                                                             //~v62UI~
//***************************                                      //~v5n1I~
UTRACEP("input a2a errrep=%x,opt=%x\n",Perrrep,Popt);              //~v5n7R~
UTRACED("input",Pinp,Pinplen);                                     //~v5n1I~
    hiconv_to=(iconv_t)Pconverters[HICONV_CPTO];                   //~v5mtI~
    hiconv_from=(iconv_t)Pconverters[HICONV_CPFROM];               //~v5mtI~
    pdbcsstarter=(UCHAR*)Pconverters[HICONV_DBCSSTARTER];          //~v5mtR~
    UTRACED("a2as dbcsstarter",pdbcsstarter,256);                  //~v66YI~
#ifdef UTF8SUPPH                                                   //~v62UI~
#ifdef AAA                                                         //~v62UI~
    sv_pdbcst=Gpdbcstbl;	//save untip a2a end                   //~v62UI~
    sv_udbcschk_flag=Gudbcschk_flag;                               //~v62UI~
    if (pdbcsstarter)                                              //~v62UI~
	    Gpdbcstbl=pdbcsstarter;	//save untip a2a end               //~v62UI~
    if (Popt & UCVEXTO_FROMEUC)                                    //~v62UR~
	    Gudbcschk_flag|=UDBCSCHK_LANGEUC;	//for ISSS3()          //~v62UI~
    else                                                           //~v62UI~
	    Gudbcschk_flag&=~UDBCSCHK_LANGEUC;	//for ISSS3()          //~v62UI~
    if (Popt & UCVEXTO_FROMGB4)                                    //~v62UR~
	    Gudbcschk_flag|=UDBCSCHK_LANGMB4;	//for ISSS3()          //~v62UR~
    else                                                           //~v62UI~
	    Gudbcschk_flag&=~UDBCSCHK_LANGMB4;	//for ISSS3()          //~v62UR~
#endif                                                             //~v62UI~
    opt=Popt&~EBC2ASC_STAT_SO;  //source is dbcs                   //~v62UI~
    opt|=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN;   //consider >2 byte dbcs for STAT_SO flag//~v62UI~
#endif                                                             //~v62UI~
	repch=(Perrrep & 0xff);                                        //~v5mtI~
    repchdbcs=Perrrep>>8;                                          //~v5mtM~
#ifdef LNX                                                         //~v5mtM~
    subchdbcs='?';                                                 //~v5n7I~
    subchsbcs='?';                                                 //~v5n7I~
#else                                                              //~v5mtM~
    if (!Perrrep)                                                  //~v5mtI~
		ucvext_getsubch(0,hiconv_from,hiconv_to,&subchsbcs,&subchdbcs,&repch,&repchdbcs);//~v5mtR~
#endif                                                             //~v5mtM~
    repchdbcs2=repchdbcs & 0xff;                                   //~v5mtM~
    repchdbcs1=repchdbcs>>8;                                       //~v5mtM~
	for (pci=Pinp,pce=pci+Pinplen,pco=Pout,pcoe=pco+Poutbuffsz;pci<pce;pci+=chklen)//~v5n8R~
    {                                                              //~v5n1I~
    	if (pco>=pcoe)                                             //~v5n8I~
        {                                                          //~v5n8I~
        	rc=8;                                                  //~v5n8I~
            break;                                                 //~v5n8I~
        }                                                          //~v5n8I~
//    	reslen=(int)((ULONG)pce-(ULONG)pci);                       //~v5n1I~//~v6hhR~
    	reslen=(int)((ULPTR)pce-(ULPTR)pci);                       //~v6hhI~
        dbcssw=0;                                                  //~v6h8I~
#ifdef UTF8SUPPH                                                   //~v62UI~
#ifdef W32                                                         //~v6bgI~
	  if (hiconv_from==CP_UTF8)     //UCVEXTO_FROMUTF8 is for linux only(for windows utf is by "UTF8" or CP_UTF8:65001)//~v6bgI~
        mblen=UTF8CHARLENERR1(*pci);                               //~v6bgI~
      else                                                         //~v6bgI~
#endif                                                             //~v6bgI~
      if (Popt & UCVEXTO_FROMUTF8)                                 //~v62UI~
        mblen=UTF8CHARLENERR1(*pci);                               //~v62UI~
      else                                                         //~v62UI~
#endif                                                             //~v62UI~
      {                                                            //~v62UI~
    	dbcssw=(pdbcsstarter && (pdbcsstarter[*pci] & UDBCSCHK_TYPEDBCS));//~v5n8R~
    	if (dbcssw)                                                //~v5n1I~
        {                                                          //~v5n3I~
#ifdef UTF8SUPPH                                                   //~v62UM~
			if (MAYBESS3(*pci))                                    //~v62UI~
            	mblen=UDBCSCHK_SS3SZ;                              //~v62UI~
            else                                                   //~v62UI~
			if (reslen>1 && UDBCSCHK_ISGB42ND(*(pci+1)))           //~v62UR~
            	mblen=UDBCSCHK_GB4SZ;                              //~v62UI~
            else                                                   //~v62UI~
            	mblen=UDBCSCHK_DBCSSZ;                             //~v62UI~
            mblen=min(reslen,mblen);                               //~v62UI~
#else                                                              //~v62UI~
    		opt=Popt|EBC2ASC_STAT_SO;  //source is dbcs            //~v5n1I~
#endif                                                             //~v62UM~
            if (reslen==1)                                         //~v5n3I~//~v62UR~
            	if (Popt & EBC2ASC_LNCONT)  //continue line        //~v5n3I~//~v62UR~
                	break;                                         //~v5n3I~//~v62UR~
        }                                                          //~v5n3I~
	    else                                                       //~v5n1I~
#ifdef UTF8SUPPH                                                   //~v62UI~
			mblen=1;                                               //~v62UI~
#else                                                              //~v62UI~
    		opt=Popt&~EBC2ASC_STAT_SO;  //source is dbcs           //~v5n1I~
#endif                                                             //~v62UI~
	  }                                                            //~v62UI~
        errrepsw=0;                                                //~v5n3I~
#ifdef UTF8SUPPH                                                   //~v62UI~
        rc2=ucvext_iconvlocal2ucs1(opt,(ULONG)hiconv_from,pci,mblen,&chklen,wkucs);//~v62UI~
#else                                                              //~v62UI~
        rc2=ucvext_iconvlocal2ucs1(opt,(ULONG)hiconv_from,pci,reslen,&chklen,wkucs);//~v5mtR~
#endif                                                             //~v62UI~
#ifdef UTF8SUPPH                                                   //~v62UR~
        if (rc2==UCEICL2U1ORC_DBCSSPLIT	//           -11           //~v62UR~
 		&&  Popt & EBC2ASC_LNCONT) //continue line                 //~v62UI~
        	break;	//if EBC2ASC_LNCONT returns chklen as required len with err rc//~v62UR~
        if (rc2)    //no byte translation success                  //~v62UI~
            chklen=mblen;   //err for all input byte               //~v62UI~
#endif                                                             //~v62UR~
        if (!rc2                                                   //~v5mtI~
        ||  !Perrrep    //no repchar specified                     //~v5mtI~
        )                                                          //~v5mtI~
        {                                                          //~v5mtI~
        	if (rc2)                                               //~v5mtI~
            {                                                      //~v5mtI~
		    	if (dbcssw)                                        //~v5mtI~
        	    	subch=subchdbcs;                               //~v5mtR~
                else                                               //~v5mtI~
        	    	subch=subchsbcs;                               //~v5mtI~
//              wkucs[0]=subch;                                    //~v6x8R~
#ifdef UTF8UCS4                                                    //~v6x8I~
                wkucs[0]=(WUCS)subch;                              //~v6x8I~
#else                                                              //~v6x8I~
//              wkucs[0]=(USHORT)subch;                            //~v6x8I~//~v6BjR~
                wkucs[0]=(UWUCS)subch;                             //~v6BjI~
#endif                                                             //~v6x8I~
	        	errrepsw=1;                                        //~v5n3I~
UTRACEP("ERR set subch ucs=%04x\n",subch);                         //~v5mtR~
			}                                                      //~v5mtI~
            rc2=ucvext_iconvucs2local1(Popt,(ULONG)hiconv_to,wkucs[0],pco,&outlen);//~v5mtR~
#ifdef UTF8SUPPH                                                   //~v62UI~
#else                                                              //~v62UI~
            if (!rc2 && dbcssw && outlen==1)                       //~v5mtI~
                rc2=4;                                             //~v5mtR~
#endif                                                             //~v62UI~
        }                                                          //~v5mtI~
        if (rc2)                                                   //~v5n1I~
        {                                                          //~v5n1I~
	        errrepsw=1;                                            //~v5n3I~
//UTRACEP("ERR a2as dbcssw=%d,ucs=%04x errrep=%x,pci=%02x\n",dbcssw,wkucs[0],Perrrep,*pci);//~v5n1I~//~v6h7R~
            if (dbcssw)                                            //~v5n1M~
            {                                                      //~v5n1I~
            	if (repchdbcs)                                     //~v5n1I~
                {                                                  //~v5n1I~
//              	*pco++=repchdbcs1;                             //~v6x8R~
                	*pco++=(UCHAR)repchdbcs1;                      //~v6x8I~
//              	*pco++=repchdbcs2;                             //~v6x8R~
                	*pco++=(UCHAR)repchdbcs2;                      //~v6x8I~
                }                                                  //~v5n1I~
                else                                               //~v5n1I~
                {                                                  //~v5n1I~
//              	*pco++=repch;                                  //~v6x8R~
                	*pco++=(UCHAR)repch;                           //~v6x8I~
//              	*pco++=repch;                                  //~v6x8R~
                	*pco++=(UCHAR)repch;                           //~v6x8I~
#ifdef UTF8SUPPH                                                   //~v62UI~
                	if (chklen>UDBCSCHK_DBCSSZ)                    //~v62UI~
//                  	*pco++=repch;                              //~v6x8R~
                    	*pco++=(UCHAR)repch;                       //~v6x8I~
                	if (chklen==UDBCSCHK_GB4SZ)                    //~v62UI~
//                  	*pco++=repch;                              //~v6x8R~
                    	*pco++=(UCHAR)repch;                       //~v6x8I~
#endif                                                             //~v62UI~
                }                                                  //~v5n1I~
#ifdef UTF8SUPPH                                                   //~v62UI~
#else                                                              //~v62UI~
                chklen=2;                                          //~v5n1I~
#endif                                                             //~v62UI~
            }                                                      //~v5n1I~
            else                                                   //~v5n1I~
            {                                                      //~v5n1I~
        		chklen=1;                                          //~v5n1R~
//          	*pco++=repch;                                      //~v6x8R~
            	*pco++=(UCHAR)repch;                               //~v6x8I~
            }                                                      //~v5n1I~
        }                                                          //~v5n1I~
        else                                                       //~v5n1I~
        {                                                          //~v5n1I~
        	pco+=outlen;                                           //~v5n1I~
        }                                                          //~v5n1I~
        if (errrepsw)                                              //~v5n3I~
        {                                                          //~v5n3I~
	        repctr++;                                              //~v5n3I~
        	if (Serrcbfunc)                                        //~v5n3I~
//	            Serrcbfunc(UCVUCS_CONVERR,Pinplen-reslen,(int)((ULONG)pco-(ULONG)Pout-chklen),Pinp,chklen);//~v5n3R~//~v6hhR~
//              Serrcbfunc(UCVUCS_CONVERR,Pinplen-reslen,(int)((ULPTR)pco-(ULPTR)Pout-chklen),Pinp,chklen);//~v6hhI~//~v6BkR~
                Serrcbfunc(UCVUCS_CONVERR,Pinplen-reslen,PTRDIFF(pco,Pout)-chklen,Pinp,chklen);//~v6BkI~
        }                                                          //~v5n3I~
    }                                                              //~v5n1I~
//  outlen=(int)((ULONG)pco-(ULONG)Pout);                          //~v5n1I~//~v6hhR~
    outlen=(int)((ULPTR)pco-(ULPTR)Pout);                          //~v6hhI~
//  readlen=(int)((ULONG)pci-(ULONG)Pinp);                         //~v5n3I~//~v6hhR~
    readlen=(int)((ULPTR)pci-(ULPTR)Pinp);                         //~v6hhI~
    if (Ppoutlen)                                                  //~v5n1I~
        *Ppoutlen=outlen;                                          //~v5n1I~
    if (Pprepctr)                                                  //~v5n3I~
        *Pprepctr=repctr;                                          //~v5n3I~
    if (Ppreadlen)                                                 //~v5n3I~
        *Ppreadlen=readlen;                                        //~v5n3I~
    if (Serrcbfunc)                                                //~v5n3I~
	    Serrcbfunc(0,readlen,outlen,Pinp,0);                       //~v5n3R~
#ifdef UTF8SUPPH                                                   //~v62UI~
#ifdef AAA                                                         //~v62UI~
    Gpdbcstbl=sv_pdbcst;	//save untip a2a end                   //~v62UI~
    Gudbcschk_flag=sv_udbcschk_flag;                               //~v62UI~
#endif                                                             //~v62UI~
#endif                                                             //~v62UI~
UTRACEP("iconv a2a rc=%d,chklen=%d,errctr=%d,outlen=%d\n",rc,readlen,repctr,outlen);//~v5n3R~
UTRACED("output a2a",Pout,outlen);                                 //~v5n1I~
    return rc;                                                     //~v5n1I~
}//ucvext_iconva2as                                                //~v5n1I~
//*************************************************************************//~v69uR~
//*translate by iconv/winapi                                       //~v69uR~
//* ebc to ebc                                                     //~v69uR~
//*************************************************************************//~v69uR~
//int ucvext_iconvb2bs(int Popt,ULONG *Pconverters,UCHAR *Pinp,int Pinplen,//~v69uR~//~v6hhR~
int ucvext_iconvb2bs(int Popt,ULPTR *Pconverters,UCHAR *Pinp,int Pinplen,//~v6hhI~
					UCHAR *Poutebc,UCHAR *Poutdbcs,UCHAR *Poutu8,int Poutbuffsz,int *Ppoutebclen,int *Ppoutu8len)//~v69uR~
{                                                                  //~v69uR~
    int rc=0,outebclen,u8len,opt;                                  //~v69uR~
    int  handle_from,handle_to;                                    //~v69uR~
//***************************                                      //~v69uR~
UTRACEP("input b2b opt=%x\n",Popt);                                //~v69uR~
UTRACED("input",Pinp,Pinplen);                                     //~v69uR~
    handle_to=(int)Pconverters[HICONV_CPTO];                       //~v69uR~
    handle_from=(int)Pconverters[HICONV_CPFROM];                   //~v69uR~
    opt=UCVEBC3O_B2F|UCVEBC3O_CVCTL|UCVEBC3O_ERRREP|UCVEBC3O_DBCSUCSOK;//~v69uR~
    if (UCVEBCH_HANDLE_ISDBCSCV(handle_from)                       //~v69uR~
    &&  UCVEBCH_HANDLE_ISDBCSCV(handle_to))                        //~v69uR~
    	opt|=UCVEBC3O_DROPSOSI|UCVEBC3O_SOSICMDO;                  //~v69uR~
    rc|=ucvebc3_b2dd(opt,handle_from,Pinp,Pinplen,Poutu8,0/*outdbcs*/,Poutbuffsz,&u8len);//~v69uR~
	opt=UCVEBC3O_CVCTL|UCVEBC3O_SOSIINS|UCVEBC3O_SETF2LERR;        //~v69uR~
	rc|=ucvebc3_f2b(opt,handle_to,Poutu8,u8len,Poutebc,Poutdbcs,Poutbuffsz,&outebclen);//~v69uR~
    *Ppoutebclen=outebclen;                                        //~v69uR~
    if (Ppoutu8len)                                                //~v69uR~
        *Ppoutu8len=u8len;                                         //~v69uR~
UTRACEP("iconv b2b rc=%d,outebclen=%d\n",rc,outebclen);            //~v69uR~
UTRACED("output b2b",Poutebc,outebclen);                           //~v69uR~
    return rc;                                                     //~v69uR~
}//ucvext_iconvb2bs                                                //~v69uR~
//*************************************************************************//~v5n1I~
//*translate any to any by iconv/win api                           //~v5n1I~
//* Plen:LRECL for fixed input record or max linelen               //~v5n1I~
//*************************************************************************//~v5n1I~
int ucvext_iconva2af(int Popt,char *Pcpfrom,char *Pcpto,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep)//~v5n1I~
{                                                                  //~v5n1I~
//  int rc=0,readlen,writelen,mbslen,opt,swfixed,lrecl;            //~v690R~
    int rc=0,writelen,mbslen,opt,swfixed,lrecl;                    //~v690I~
    UINT readlen;                                                  //~v690I~
    int obuffsz;                                                   //~v5n3I~
    FILE *fhi,*fho;                                                //~v5n1I~
    char *pbuff,*pbuff2;                                           //~v5n1I~
    char *pbuff3=NULL,*pbuff4=NULL;                                          //~v69uR~//~v6h7R~
//  ULONG pconverters[3];                                          //~v6f6R~
//  ULONG pconverters[7];                                          //~v6f6I~//~v6hhR~
    ULPTR pconverters[7];                                          //~v6hhI~
#ifdef LNX                                                         //~v5mtI~
	ULONG pconvcpto[2],pconvcpfrom[2];	//0:TOUCS,1:FROMUCS        //~v5mtI~
#endif                                                             //~v5mtI~
    UCHAR dbcsflag[256];                                           //~v5n1I~
    int handle;                                                    //~v69uR~
    int rc2;                                                       //~v6frI~
//***************************                                      //~v5n1I~
UTRACEP("a2af opt=%x,inp=%s out=%s,repch=%08x\n",Popt,Pinpfilename,Poutfilename,Perrrep);//~v5n1R~//~v69uR~//~v6b9R~
  if (Popt & UCVEXTO_B2B)                                          //~v69uR~
  {                                                                //~v69uR~
    opt=UCVEBCCHO_CHKEBCCP;                                        //~v69uR~
	if (ucvebc4_createhandle(opt,Pcpfrom,&handle))	//cfg converte //~v69uR~
    {                                                              //~v6bfI~
        if (!Pcpfrom || !*Pcpfrom)                                 //~v6bfI~
        	uerrmsg("Missing B2B \"From\" codepage",0);            //~v6bfI~
        else                                                       //~v6bfI~
        if (!strcmp(Pcpfrom,"?")||!strcmp(Pcpto,"?"))              //~v6bfR~
	        ucvext_icuenumcvname(0,0,0);                           //~v6bfI~
        else                                                       //~v6bfI~
        	uerrmsg("invalid B2B \"From\" codepage(%s)",0,         //~v6bfR~
        				Pcpfrom);                                  //~v6bfR~
    	return 8;                                                  //~v69uR~
    }                                                              //~v6bfI~
    pconverters[HICONV_CPFROM]=(ULONG)handle;                      //~v69uR~
	if (ucvebc4_createhandle(opt,Pcpto,&handle))	//cfg converte //~v69uR~
    {                                                              //~v6bfI~
        if (!Pcpto || !*Pcpto)                                     //~v6bfI~
        	uerrmsg("Missing B2B \"To\" codepage",0);              //~v6bfI~
        else                                                       //~v6bfI~
        if (!strcmp(Pcpfrom,"?")||!strcmp(Pcpto,"?"))              //~v6bfI~
	        ucvext_icuenumcvname(0,0,0);                           //~v6bfI~
        else                                                       //~v6bfI~
	        uerrmsg("invalid B2B \"To\" codepage(%s)",0,           //~v6bfR~
        			Pcpto);                                        //~v6bfI~
    	return 8;                                                  //~v69uR~
    }                                                              //~v6bfI~
    pconverters[HICONV_CPTO]=(ULONG)handle;                        //~v69uR~
  }                                                                //~v69uR~
  else                                                             //~v69uR~
  {                                                                //~v69uR~
   if (Popt & UCVEXTO_MBICU)                                       //~v6f6I~
   {                                                               //~v6f6I~
        rc2=                                                       //~v6frI~
		ucvext_icua2ainit(0,Pcpfrom,Pcpto,dbcsflag,&opt,pconverters);//set pconverters[7],cv,dbcs,subch,close handle//~v6f6I~
        if (rc2)                                                   //~v6frI~
            return rc2;                                            //~v6frI~
   }                                                               //~v6f6I~
   else                                                            //~v6f6I~
   {                                                               //~v6f6I~
#ifdef LNX                                                         //~v5mtI~
	pconverters[HICONV_CPTO]=(ULONG)pconvcpto;	//parm to iconv getconverter//~v5mtI~
	pconverters[HICONV_CPFROM]=(ULONG)pconvcpfrom;	//parm to iconv getconverter//~v5mtI~
  	if (ucvext_iconvgetconvertertype(0,(ULONG)Pcpfrom,0)==UCEIRC_UTF8)//~v5n7R~
//  	Popt|=EBC2ASC_FROMUTF8;                                    //~v5n8R~
    	Popt|=UCVEXTO_FROMUTF8;                                    //~v5n8I~
#endif                                                             //~v5mtI~
//	pconverters[HICONV_DBCSSTARTER]=(ULONG)dbcsflag;	//parm to iconv getconverter//~v5n1R~//~v6hhR~
	pconverters[HICONV_DBCSSTARTER]=(ULPTR)dbcsflag;	//parm to iconv getconverter//~v6hhI~
    UTRACED("a2af dbcsflag",dbcsflag,256);                         //~v66YI~
	if (ucvext_iconvgetparmconverter(Popt,Pcpfrom,Pcpto,pconverters)>1)//~v5n1R~
    	return 8;                                                  //~v5n1I~
    UTRACED("a2af dbcsflag after getconv",dbcsflag,256);           //~v66YI~
   }                                                               //~v6f6I~
  }                                                                //~v69uR~
    swfixed=(Popt & EBC2ASC_FIXEDLRECL);                           //~v5n1I~
	fhi=fopen(Pinpfilename,"rb");                                  //~v5n1I~
    if (!fhi)                                                      //~v5n1I~
    	return ufileapierr("fopen",Pinpfilename,errno);            //~v5n1I~
    if (Poutfilename)                                              //~v5n1I~
    {                                                              //~v5n1I~
        fho=fopen(Poutfilename,"wb");                              //~v5n1I~
        if (!fho)                                                  //~v5n1I~
        {                                                          //~v5n1I~
	        fclose(fhi);                                           //~v5n1I~
            return ufileapierr("fopen",Poutfilename,errno);        //~v5n1I~
        }                                                          //~v5n1I~
    }                                                              //~v5n1I~
    else                                                           //~v5n1I~
    {                                                              //~v68hI~
#ifdef UNX                                                         //~v68hI~
#else                                                              //~v68hI~
        setmode(1,O_BINARY);    //binary mode                      //~v68hI~
#endif                                                             //~v68hI~
    	fho=stdout;                                                //~v5n1I~
    }                                                              //~v68hI~
    if (!(lrecl=Plen))                                             //~v5n1I~
    {                                                              //~v5n1I~
        if (swfixed)                                               //~v5n1I~
    		lrecl=EBC_DEFAULT_LRECL;                               //~v5n1I~
        else                                                       //~v5n1I~
    		lrecl=MB_MAXLINELEN;                                   //~v5n1I~
    }                                                              //~v5n1I~
    obuffsz=lrecl*MAX_MBCSLEN;                                     //~v5n3I~
    pbuff=umalloc((UINT)(lrecl+obuffsz));                          //~v5n3R~
    UALLOCCHK(pbuff,UALLOC_FAILED);                                //~v5n1I~
    pbuff2=pbuff+lrecl;            //mbs                           //~v5n1I~
    if (Popt & UCVEXTO_B2B)                                        //~v69uR~
    {                                                              //~v69uR~
    	pbuff3=umalloc((UINT)obuffsz*2);                           //~v69uR~
    	UALLOCCHK(pbuff3,UALLOC_FAILED);//outu8                    //~v69uR~
        pbuff4=pbuff3+obuffsz;	//outdbcs                          //~v69uR~
    }                                                              //~v69uR~
    if (!swfixed)//text mode transfer                              //~v5n1I~
    {                                                              //~v5n1I~
    	opt=UFGETS_PC|UFGETS_UNIX;                                 //~v5n1I~
    	ufgetsinit(opt,0/*buffsz:default*/,0/*binrate*/,0/*lrecl of bin file*/);//~v5n1I~
    }                                                              //~v5n1I~
    for (;;)                                                       //~v5n1I~
    {                                                              //~v5n1I~
        if (swfixed)                                               //~v5n1I~
        {                                                          //~v5n1I~
//  		readlen=fread(pbuff,1,lrecl,fhi);                      //~v5n1I~//~v6BkR~
//  		readlen=fread(pbuff,1,(size_t)lrecl,fhi);              //~v6BkI~//~v6BxR~
    		readlen=(UINT)fread(pbuff,1,(size_t)lrecl,fhi);        //~v6BxI~
        	if (!readlen)                                          //~v5n1I~
        		break;                                             //~v5n1I~
//          if (readlen<lrecl)                                     //~v690R~
            if (readlen<(UINT)lrecl)                               //~v690I~
//          	memset(pbuff+readlen,' ',(UINT)(lrecl-readlen));   //~v5n1I~//~v6BkR~
            	memset(pbuff+readlen,' ',(size_t)lrecl-readlen);   //~v6BkI~
        }                                                          //~v5n1I~
        else                                                       //~v5n1I~
        {                                                          //~v5n1I~
//  		if (ufgets(pbuff,lrecl,fhi,&readlen,0))                //~v5n1I~//~v6BkR~
    		if (ufgets(pbuff,(UINT)lrecl,fhi,&readlen,0))          //~v6BkI~
        		break;                                             //~v5n1I~
        }                                                          //~v5n1I~
      if (Popt & UCVEXTO_B2B)                                      //~v69uR~
//  	rc|=ucvext_iconvb2bs(Popt,pconverters,pbuff,readlen,pbuff2/*outebc*/,pbuff4/*dbcs*/,pbuff3/*outu8*/,obuffsz,&mbslen,0/*u8len*/);//~v69uR~//~v6BkR~
    	rc|=ucvext_iconvb2bs(Popt,pconverters,pbuff,(int)readlen,pbuff2/*outebc*/,pbuff4/*dbcs*/,pbuff3/*outu8*/,obuffsz,&mbslen,0/*u8len*/);//~v6BkI~
      else                                                         //~v69uR~
      if (Popt & UCVEXTO_MBICU)                                    //~v6f4I~
//      rc=ucvext_icua2as(Popt,pconverters,pbuff,0/*dbcs*/,readlen,pbuff2,obuffsz,0/*chklen*/,&mbslen,0,Perrrep,0/*repctr*/);//~v6f4R~//~v6BkR~
        rc=ucvext_icua2as(Popt,pconverters,pbuff,0/*dbcs*/,(int)readlen,pbuff2,obuffsz,0/*chklen*/,&mbslen,0,Perrrep,0/*repctr*/);//~v6BkI~
      else                                                         //~v6f4I~
//  	rc|=ucvext_iconva2as(Popt,pconverters,pbuff,0/*dbcs*/,readlen,pbuff2,obuffsz,0,&mbslen,Perrrep,0/*repctr out*/);//~v5n3R~//~v6BkR~
    	rc|=ucvext_iconva2as(Popt,pconverters,pbuff,0/*dbcs*/,(int)readlen,pbuff2,obuffsz,0,&mbslen,Perrrep,0/*repctr out*/);//~v6BkI~
UTRACEP("ret a2as/b2bs rc=%d outlen=%d\n",rc,mbslen);                                 //~v5n1I~//~v6b9R~
        if (mbslen)                                                //~v5n1I~
        {                                                          //~v5n1I~
//      	writelen=fwrite(pbuff2,1,mbslen,fho);                  //~v5n1I~//~v6BkR~
        	writelen=(int)fwrite(pbuff2,1,(size_t)mbslen,fho);     //~v6BkI~
            if (writelen!=mbslen)                                  //~v5n1I~
		    	return ufileapierr("fwrite",Poutfilename,errno);   //~v5n1I~
        }                                                          //~v5n1I~
        if (Popt & EBC2ASC_SETEOL)                                 //~v5n1I~
        	fwrite("\n",1,1,fho);                                  //~v5n1I~
    }                                                              //~v5n1I~
    ufree(pbuff);                                                  //~v5n1I~
	fclose(fhi);                                                   //~v5mtI~
    if (!(Popt & UCVEXTO_B2B))                                     //~v6f6I~
      	if (Popt & UCVEXTO_MBICU)                                  //~v6f6I~
			ucvext_icua2aterm(0,pconverters);	//close hanlde     //~v6f6I~
    if (Poutfilename)                                              //~v5mtI~
		fclose(fho);                                               //~v5mtR~
    return rc;                                                     //~v5n1I~
}//ucvext_iconva2af                                                //~v5mtR~
#ifdef UTF8SUPPH                                                   //~v621I~
//*************************************************************************//~v621I~
//*init to use ucvext_a2as                                         //~v621I~
//*Pcpfrom:cv from(current if 0)                                   //~v621I~
//*Pcpto  :cv to  (current if 0)                                   //~v621I~
//*Ppbcsflag:output dbcs leadbyte flag[256]                        //~v621R~
//*Ppopt:FROMUTF8 is conditionaly ORed                             //~v621I~
//*Ppconverter:converter output ULONG[3](win) ULONG[7](lnx)        //~v621I~
//*************************************************************************//~v621I~
//int ucvext_iconva2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULONG *Pconverters)//~v621I~//~v6hhR~
int ucvext_iconva2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULPTR *Pconverters)//~v6hhI~
{                                                                  //~v621I~
    int opt;                                                       //~v621R~
//  ULONG *pconverters;                                            //~v621I~//~v6hhR~
    ULPTR *pconverters;                                            //~v6hhI~
//***************************                                      //~v621I~
	if (Popt & UCVEXTO_MBICU)                                      //~v6bgI~//~v6f4I~
    	return ucvext_icua2ainit(Popt,Pcpfrom,Pcpto,Pdbcsflag,Ppopt,Pconverters);//~v6bgI~//~v6f4R~
	opt=Popt;                                                      //~v621I~
    pconverters=Pconverters;                                       //~v621R~
#ifdef LNX                                                         //~v621I~
	pconverters[HICONV_CPTO]=(ULONG)(pconverters+3);	//parm to iconv getconverter//~v621R~
	pconverters[HICONV_CPFROM]=(ULONG)(pconverters+3+2);	//parm to iconv getconverter//~v621R~
    if (!(Popt & UCVEXTO_FROMUTF8))                                //~v621I~
  		if (ucvext_iconvgetconvertertype(0,(ULONG)Pcpfrom,0)==UCEIRC_UTF8)//~v621R~
    		opt|=UCVEXTO_FROMUTF8;                                 //~v621R~
#endif                                                             //~v621I~
//	pconverters[HICONV_DBCSSTARTER]=(ULONG)Pdbcsflag;	//parm to iconv getconverter//~v621I~//~v6hhR~
	pconverters[HICONV_DBCSSTARTER]=(ULPTR)Pdbcsflag;	//parm to iconv getconverter//~v6hhI~
	if (ucvext_iconvgetparmconverter(opt,Pcpfrom,Pcpto,pconverters)>1)//~v621I~
    	return 8;                                                  //~v621I~
#ifdef AAA                                                         //~v62UI~
    if (Pcpfrom)                                                   //~v62UR~
    {                                                              //~v62UI~
		if (ustrstri(Pcpfrom,"EUC"))                               //~v62UI~
        opt|=UCVEXTO_FROMEUC;                                      //~v62UI~
    	if (ustrstri(Pcpfrom,"GB18030"))                           //~v62UR~
	        opt|=UCVEXTO_FROMGB4;                                  //~v62UR~
    }                                                              //~v62UI~
#endif                                                             //~v62UI~
    *Ppopt=opt;                                                    //~v621I~
    return 0;                                                      //~v621R~
}//ucvext_iconva2ainit                                             //~v621I~
#endif                                                             //~v621I~
//**************************************************************** //~v5n3I~
//	m2m by iconv/win API(cont line support for xe)                 //~v5n3R~
//**************************************************************** //~v5n3I~
//int ucvext_iconva2acont(ULONG *Pconverters,UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v5n3R~//~v6hhR~
int ucvext_iconva2acont(ULPTR *Pconverters,UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v6hhI~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz,int Perrrep)//~v5n3R~
{                                                                  //~v5n3I~
	int len,rc,rcs=0,rct=0,readlen,reslen=0,outlen,chklen;         //~v5n3I~
    int lineendid;                                                 //~v5n3I~
    int totrep=0,repctr;                                           //~v5n3I~
    char *pinp,*pout;                                              //~v5n3I~
//*******************************                                  //~v5n3I~
	Serrcbfunc=Pferr;	//parm to ucvext_iconva2as                 //~v5n3I~
	pinp=Pibuff;                                                   //~v5n3I~
	pout=Pobuff;                                                   //~v5n3I~
    for (;;)                                                       //~v5n3I~
    {                                                              //~v5n3I~
	    rc=Pfread(pinp+reslen,Pibuffsz-reslen,&readlen);           //~v5n3I~
        lineendid=0;                                               //~v5n3I~
      	if (rc!=1)                                                 //~v5n3I~
        {                                                          //~v5n3I~
        	if (rc)                                                //~v5n3I~
        		break;                                             //~v5n3I~
            else                                                   //~v5n3I~
            	lineendid=EBC2ASC_LNCONT;                          //~v5n3I~
        }                                                          //~v5n3I~
    	len=readlen+reslen;                                        //~v5n3I~
      if (Popt & UCVEXTO_MBICU)                                    //~v6f4I~
//      rcs=ucvext_icua2as(Popt|lineendid,Pconverters,pinp,0,len,pout,Pobuffsz,&chklen,&outlen,(ULONG)Pferr,Perrrep,&repctr);//~v6f4R~//~v6hhR~
//      rcs=ucvext_icua2as(Popt|lineendid,Pconverters,pinp,0,len,pout,Pobuffsz,&chklen,&outlen,(ULPTR)Pferr,Perrrep,&repctr);//~v6hhI~//~v6BkR~
        rcs=ucvext_icua2as((int)Popt|lineendid,Pconverters,pinp,0,len,pout,Pobuffsz,&chklen,&outlen,(ULPTR)Pferr,Perrrep,&repctr);//~v6BkI~
      else                                                         //~v6f4I~
//      rcs=ucvext_iconva2as(Popt|lineendid,Pconverters,pinp,0,len,pout,Pobuffsz,&chklen,&outlen,Perrrep,&repctr);//~v5n3R~//~v6BkR~
        rcs=ucvext_iconva2as((int)Popt|lineendid,Pconverters,pinp,0,len,pout,Pobuffsz,&chklen,&outlen,Perrrep,&repctr);//~v6BkI~
        totrep+=repctr;                                            //~v5n3I~
        rct|=rcs;                                                  //~v5n3I~
		Pfwrite(Pobuff,outlen);                                    //~v5n3I~
        reslen=len-chklen;                                         //~v5n3I~
        if (reslen)                                                //~v5n3I~
	        memcpy(pinp,pinp+chklen,(UINT)reslen);                 //~v5n3I~
    }//for                                                         //~v5n3I~
    if (Popt & UCVEXTO_MBICU)                                      //~v6f4I~
//      rcs=ucvext_icua2aterm(Popt,Pconverters);                   //~v6f4R~//~v6BkR~
        rcs=ucvext_icua2aterm((int)Popt,Pconverters);              //~v6BkI~
    rct&=~UCVUCS_LENERR;                                           //~v5n3I~
	Serrcbfunc=0;                                                  //~v5n3I~
    return rct;                                                    //~v5n3I~
}//ucvext_iconva2acont                                             //~v5n3R~
#ifdef W32                                                         //~v5n1I~
//**************************************************************************//~v5n1I~
//*list windows code page **************************************************//~v5n1I~
//**************************************************************************//~v5n1I~
BOOL CALLBACK ucvext_listcpcbfunc(char *Pcpstr)                    //~v5n1I~
{                                                                  //~v5n1I~
    ULONG cp;                                                      //~v5n1I~
    CPINFOEX   info;                                               //~v5n1I~
    char *ctype;                                                   //~v5n1I~
//****************                                                 //~v5n1I~
    cp=atol(Pcpstr);                                               //~v5n1R~
    if (GetCPInfoEx(cp,0,&info))                                   //~v5n1R~
    {                                                              //~v5n1I~
    	if (info.LeadByte[0])                                      //~v5n1I~
        	ctype="MBCS";                                          //~v5n1I~
        else                                                       //~v5n1I~
        if (cp==CP_GB18030)                                        //~v5n5I~
        	ctype="Mbcs";                                          //~v5n5I~
        else                                                       //~v5n5I~
        	ctype="sbcs";                                          //~v5n1R~
		printf("%s (MaxCharSize=%d) : %s\n",ctype,info.MaxCharSize,info.CodePageName);//~v5n1R~
    }                                                              //~v5n1I~
    else                                                           //~v5n1I~
		printf("                     No Info(%d) for cp=%d\n",GetLastError(),cp);//~v5n1R~
    return 1;   //continue enum                                    //~v5n1R~
}                                                                  //~v5n1I~
//**************************************************************************//~v5n1I~
//*list windows code page **************************************************//~v5n1I~
//*opt 1:CP_INSTALLED , 2:CP_SUPPORTED                             //~v5n1I~
//**************************************************************************//~v5n1I~
int ucvext_listwincp(int Popt)                                     //~v5n1I~
{                                                                  //~v5n1I~
	int rc;                                                        //~v5n1I~
    CODEPAGE_ENUMPROC cbfunc=&ucvext_listcpcbfunc;                 //~v5n1I~
//**********************                                           //~v5n1I~
	rc=EnumSystemCodePages(cbfunc,Popt);                           //~v5n1I~
    if (rc)                                                        //~v5n1I~
    	rc=0;                                                      //~v5n1I~
    else                                                           //~v5n1I~
    	rc=GetLastError();                                         //~v5n1I~
    return rc;                                                     //~v5n1I~
}//ucvext_listwincp                                                //~v5n1I~
#endif                                                             //~v5n1I~
#endif //W32||LNX                                                  //~v5n1R~
#ifdef W32                                                         //~v6BHI~
//**************************************************************************//~v6BHI~
//*Wrapper of MultiByteToWideChar                                  //~v6BHI~
//*Ppucs may be NULL                                               //~v6E1I~
//**************************************************************************//~v6BHI~
int uMultiByteToWideChar(int Popt,ULONG Pconverter,int Papiopt,char *Ppebc,int Pinplen,WUCS/*ucs2*/ *Ppucs,size_t Pbuffsz,int *Pplasterr)//~v6BHR~
{                                                                  //~v6BHI~
	int lasterr=0,ctr,opt;                                         //~v6BHR~
static int Scodepage_invalidflags;                                 //~v6BHI~
//*****************                                                //~v6BHI~
    UTRACEP("%s:Popt=%x,apiopt=%x inplen=%d,cp=%d,Scodepage_invalidflags=%d\n",UTT,Popt,Papiopt,Pinplen,Pconverter,Scodepage_invalidflags);//~v6BHR~
	opt=Papiopt;                                                   //~v6BHI~
// 	if (Pconverter==CP_GB18030                                     //~v6BHR~
// 	||  !(Gudbcschk_flag & UDBCSCHK_DBCSLANG)                      //~v6BHR~
// 	)                                                              //~v6BHR~
    if ((int)Pconverter==Scodepage_invalidflags)                   //~v6BHI~
		opt=0;                      //err INVALID flag(1004) if PRECOMOSIT(default) or INVALID_CHAR flag for GB18030//~v6BHI~
    ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,Pinplen,Ppucs,Pbuffsz/WUCSSZ);//~v6BHR~
    if (!ctr)                                                      //~v6BHI~
	    lasterr=GetLastError();                                    //~v6BHR~
    UTRACEP("%s:MultibyteToWideChar opt=%x,cp=%d,mb=%02x,len=%d,ctr=%d,ucs=%x,lasterr=%d\n",UTT,opt,Pconverter,*Ppebc,Pinplen,ctr,Ppucs?*Ppucs:0,lasterr);//~v6BHR~//~v6E1R~
    if (lasterr==ERROR_INVALID_FLAGS)                              //~v6BHR~
    {                                                              //~v6BHI~
    	if ((int)Pconverter!=Scodepage_invalidflags)               //~v6BHI~
        {                                                          //~v6BHI~
            Scodepage_invalidflags=(int)Pconverter;                //~v6BHI~
            opt=0;                                                 //~v6BHR~
            lasterr=0;                                             //~v6BHI~
            ctr=MultiByteToWideChar(Pconverter,opt,Ppebc,Pinplen,Ppucs,Pbuffsz/WUCSSZ);//~v6BHR~
            if (!ctr)                                              //~v6BHI~
	            lasterr=GetLastError();                            //~v6BHR~
            UTRACEP("%s:Retry MultibyteToWideChar opt=%x,cp=%d,mb=%02x,len=%d,ctr=%d,ucs=%x,lasterr=%d\n",UTT,opt,Pconverter,*Ppebc,Pinplen,ctr,Ppucs?*Ppucs:0,lasterr);//~v6BHR~//~v6E1R~
        }                                                          //~v6BHI~
    }                                                              //~v6BHI~
    if (Pplasterr)                                                 //~v6BHI~
	    *Pplasterr=lasterr;                                        //~v6BHI~
    return ctr;                                                    //~v6BHI~
}//uMultiByteToWideChar                                            //~v6BHI~
//**************************************************************************//~v6BII~
//*Wrapper of WideCharToMultiByte                                  //~v6BII~
//**************************************************************************//~v6BII~
int uWideCharToMultiByte(int Popt,ULONG Pconverter,int Papiopt,WUCS/*int2*/*Ppucs,int Pucsctr,UCHAR *Ppmbs,size_t Pbuffsz,char *Pdefaultchars,int *Ppdefaultused,int *Pplasterr)//~v6BIR~
{                                                                  //~v6BII~
	int lasterr=0,ctr,opt;                                         //~v6BIR~
	BOOL *pdefaultused;                                            //~v6BII~
    char *pdefaultchars;                                           //~v6BII~
static int Scodepage_invalidflags;                                 //~v6BII~
static int Scodepage_invalidparameter;                             //~v6BII~
	BOOL defused=0;                                                //~v6E1I~
//*****************                                                //~v6BII~
	UTRACEP("%s:converter=%d,apiopt=%x,psubchar=%p,perrflag=%p\n",UTT,Pconverter,Papiopt,Pdefaultchars,Ppdefaultused);//~v6BIR~
	opt=Papiopt;                                                   //~v6BII~
    if ((int)Pconverter==Scodepage_invalidflags)                   //~v6BII~
		opt=0;                      //err INVALID flag(1004) if PRECOMOSIT(default) or INVALID_CHAR flag for GB18030//~v6BII~
    if (Ppdefaultused)                                             //~v6BIR~
    	*Ppdefaultused=FALSE;                                      //~v6BIR~
    pdefaultchars=Pdefaultchars;                                   //~v6BII~
    pdefaultused=Ppdefaultused;                                    //~v6BII~
    if ((int)Pconverter==Scodepage_invalidflags)                   //~v6BII~
    {                                                              //~v6BII~
		pdefaultchars=NULL;                                        //~v6BII~
		pdefaultused=NULL;                                         //~v6BII~
    }                                                              //~v6BII~
    ctr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,pdefaultchars,pdefaultused);//~v6BII~
    if (!ctr)                                                      //~v6BII~
	    lasterr=GetLastError();                                    //~v6BII~
	UTRACEP("%s:WideCharToMultibyte converter=%d,ucs=%04x-%04x,opt=%x,out mb ctr=%d,pdefaultchars=%p,pdefaultused=%p,defaultused=%x,Lasterr=%d\n",UTT,Pconverter,Ppucs[0],Pucsctr>1?Ppucs[1]:0,opt,ctr,pdefaultchars,pdefaultused,pdefaultused?*pdefaultused:0,GetLastError());//~v6BIR~//~v6E1R~
    UTRACED("out wkmbs",Ppmbs,ctr);                                //~v6BII~
    if (lasterr==ERROR_INVALID_PARAMETER)                          //~v6BIM~
    {                                                              //~v6BIM~
    	if ((int)Pconverter!=Scodepage_invalidflags)               //~v6BIM~
        {                                                          //~v6BIM~
            Scodepage_invalidparameter=(int)Pconverter;            //~v6BIM~
            if (pdefaultchars||pdefaultused)                       //~v6BIM~
            {                                                      //~v6BIM~
				pdefaultchars=NULL;                                //~v6BIM~
				pdefaultused=NULL;                                 //~v6BIM~
    			lasterr=0;                                         //~v6BII~
	    		ctr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,pdefaultchars,pdefaultused);//~v6BII~
        		if (!ctr)                                          //~v6BII~
	        		lasterr=GetLastError();                        //~v6BII~
	    		UTRACEP("%s:INVALID_PARM Retry WideCharToMultibyte converter=%d,ucs=%04x-%04x,opt=%x,out mb ctr=%d,pdefaultchars=%p,pdefaultused=%p,defaultused=%x,lasterr=%d\n",UTT,Pconverter,Ppucs[0],Pucsctr>1?Ppucs[1]:0,opt,ctr,pdefaultchars,pdefaultused,pdefaultused?*pdefaultused:0,lasterr);//~v6BII~
	    		UTRACED("Retry out wkmbs",Ppmbs,ctr);              //~v6BII~
            }                                                      //~v6BIM~
        }                                                          //~v6BIM~
    }                                                              //~v6BIM~
    if (lasterr==ERROR_INVALID_FLAGS)                              //~v6BII~
    {                                                              //~v6BII~
    	if ((int)Pconverter!=Scodepage_invalidflags)               //~v6BII~
        {                                                          //~v6BII~
            Scodepage_invalidflags=(int)Pconverter;                //~v6BII~
            if (opt)                                               //~v6BII~
            {                                                      //~v6BII~
            	opt=0;                                             //~v6BII~
		    	lasterr=0;                                         //~v6BII~
	   			ctr=WideCharToMultiByte(Pconverter,opt,Ppucs,Pucsctr,Ppmbs,Pbuffsz,pdefaultchars,pdefaultused);//~v6BII~
        		if (!ctr)                                          //~v6BII~
	        		lasterr=GetLastError();                        //~v6BII~
	    		UTRACEP("%s:INVALID_FLAG Retry WideCharToMultibyte converter=%d,ucs=%04x-%04x,opt=%x,out mb ctr=%d,pdefaultchars=%p,pdefaultused=%p,defaultused=%x,lasterr=%d\n",UTT,Pconverter,Ppucs[0],Pucsctr>1?Ppucs[1]:0,opt,ctr,pdefaultchars,pdefaultused,pdefaultused?*pdefaultused:0,lasterr);//~v6BII~
	    		UTRACED("Retry out wkmbs",Ppmbs,ctr);              //~v6BII~
            }                                                      //~v6BII~
        }                                                          //~v6BII~
    }                                                              //~v6BII~
  	if (Pconverter!=CP_UTF8)                                       //~v6E1R~
    {                                                              //~v6E1I~
      	if (pdefaultused && !*pdefaultused)                        //~v6E1R~
        {                                                          //~v6E1I~
//          if (!lasterr && Popt & UWCTMBO_SETSUBCHRC)//0x01: valid but reversechk required//~v6E1R~
            if (!lasterr && !(Popt & UWCTMBO_REVERSECHK))	//valid but reversechk required//~v6E1I~
            {                                                      //~v6E1R~
                opt=MB_ERR_INVALID_CHARS;                          //~v6E1R~
                defused=uWideCharToMultiByte_reversechk(Popt,Pconverter,Papiopt,Ppucs,Pucsctr,Ppmbs,&ctr,Pdefaultchars,Ppdefaultused,&lasterr);//~v6E1R~
                if (Ppdefaultused)                                 //~v6E1R~
                    *Ppdefaultused=defused;                        //~v6E1R~
                UTRACEP("%s:reverse chk defused=%d,lasterr=%d\n",UTT,defused,lasterr);//~v6E1R~
            }                                                      //~v6E1R~
        }                                                          //~v6E1I~
    }                                                              //~v6E1I~
    if (Pplasterr)                                                 //~v6BII~
	    *Pplasterr=lasterr;                                        //~v6BII~
    return ctr;                                                    //~v6BII~
}//uWideCharToMultiByte                                            //~v6BIR~
//**************************************************************************//~v6E1I~
//*reverse chk 1 by 1                                              //~v6E1I~
//*rc:errrep occured                                               //~v6E1I~
//**************************************************************************//~v6E1I~
int uWideCharToMultiByte_reversechk(int Popt,ULONG Pconverter,int Papiopt,WUCS/*int2*/*Ppucs,int Pucsctr,UCHAR *Ppmbs,int *Ppmbctr,char *Pdefaultchars,int *Ppdefaultused,int *Pplasterr)//~v6E1R~
{                                                                  //~v6E1I~
	int defused=0,lasterr=0,defch,mbctr,mbctr0,opt,optapi,ii,ucsctr;//~v6E1R~
    int swsurrogate,flag,wcwidth,shiftlen;                         //~v6E1I~
	WUCS *pucs;                                                    //~v6E1R~
    UWUCS ucs4;                                                    //~v6E1I~
    UCHAR *pmbs,*pmbse,wkmbs[8];                                   //~v6E1I~
//*********************	                                           //~v6E1I~
	if (Pdefaultchars)                                             //~v6E1I~
    	defch=*Pdefaultchars;                                      //~v6E1I~
    else                                                           //~v6E1I~
    	defch='?';                                                 //~v6E1R~
    optapi=MB_ERR_INVALID_CHARS;                                   //~v6E1R~
    opt=Popt | UWCTMBO_REVERSECHK;//avoid recursive loop           //~v6E1R~
    mbctr0=*Ppmbctr;                                               //~v6E1I~
	for (pucs=Ppucs,pmbs=Ppmbs,pmbse=pmbs+mbctr0,ii=0;ii<Pucsctr && pmbs<pmbse;pucs++,pmbs+=mbctr,ii++)//~v6E1R~
    {                                                              //~v6E1I~
        ucs4=*pucs;                                                //~v6E1I~
    	mbctr=1;                                                   //~v6E1I~
    	if (UTF8ISASCII(ucs4))                                     //~v6E1R~
        	continue;                                              //~v6E1I~
        swsurrogate=IS_UTF16_HIGH(ucs4);                           //~v6E1I~
        ucsctr=1+swsurrogate;                                      //~v6E1I~
		mbctr=uWideCharToMultiByte(opt,Pconverter,Papiopt,pucs,ucsctr,wkmbs,sizeof(wkmbs),Pdefaultchars,Ppdefaultused,&lasterr);//~v6E1R~
        if (mbctr==0)        //protect loop,may not occuer         //~v6E1R~
        	continue;                                              //~v6E1I~
		uMultiByteToWideChar(0,Pconverter,optapi,pmbs,mbctr,NULL/*outucs*/,0/*ucsbuffsz*/,&lasterr);//~v6E1R~
        if (!lasterr)	//cv err                                   //~v6E1R~
        	continue;                                              //~v6E1I~
		UTRACEP("%s:M2W lasterr=%d mbsctr=%d,mbs=%02x-%02x,ucs=%04x\n",UTT,lasterr,mbctr,*pmbs,mbctr>1?*(pmbs+1):0,*pucs);//~v6E1R~
    	opt|=UTFWWO_UTF8UCS2;                                      //~v6E1I~
        if (swsurrogate)                                           //~v6E1I~
        	ucs4=UTF16_TO_UCS4(*pucs,*(pucs+1));                   //~v6E1I~
    	wcwidth=utfwcwidth(opt,ucs4,&flag);                        //~v6E1I~
        defused=1;                                                 //~v6E1I~
		UTRACEP("%s:M2W ucs4=%04x, mblen=%d,wcwidth=%d\n",UTT,ucs4,mbctr,wcwidth);//~v6E1R~
        if (wcwidth==2)                                            //~v6E1I~
		{                                                          //~v6E1I~
        	if (mbctr==1)                                          //~v6E1I~
            {                                                      //~v6E1I~
            	shiftlen=PTRDIFF(pmbse,pmbs);                      //~v6E1R~
                memmove(pmbs+1,pmbs,shiftlen);                     //~v6E1I~
                pmbse++;                                           //~v6E1I~
                mbctr=2;                                           //~v6E1I~
            }                                                      //~v6E1I~
			if (!utf_setsubchar_dbcs(0,pmbs))	//not set dbcs errrep//~v6E1I~
            {                                                      //~v6E1I~
		    	*(pmbs)=(UCHAR)defch;                              //~v6E1R~
		    	*(pmbs+1)=(UCHAR)defch;                            //~v6E1R~
            }                                                      //~v6E1I~
        }                                                          //~v6E1I~
        else                                                       //~v6E1I~
        {                                                          //~v6E1I~
        	if (mbctr==2)                                          //~v6E1I~
            {                                                      //~v6E1I~
            	shiftlen=PTRDIFF(pmbse,pmbs+1);                    //~v6E1I~
                memcpy(pmbs,pmbs+1,shiftlen);                      //~v6E1R~
                pmbse--;                                           //~v6E1I~
                mbctr=1;                                           //~v6E1I~
            }                                                      //~v6E1I~
		    *(pmbs)=(UCHAR)defch;                                  //~v6E1R~
        }                                                          //~v6E1I~
    }                                                              //~v6E1I~
    mbctr=PTRDIFF(pmbse,Ppmbs);                                    //~v6E1I~
    *Ppmbctr=mbctr;                                                //~v6E1I~
	UTRACED("mbs",Ppmbs,mbctr);                                    //~v6E1R~
	UTRACEP("%s:rc=defused=%d\n",UTT,defused);                     //~v6E1R~
    return defused;                                                //~v6E1R~
}//uWideCharToMultiByte_reversechk                                 //~v6E1I~
#endif                                                             //~v6BHI~
