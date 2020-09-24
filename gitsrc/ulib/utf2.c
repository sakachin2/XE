//*CID://+v70gR~:                              update#= 1111;      //~v70gR~
//*********************************************************************//~7712I~
//utf2.c                                                           //~7716R~
//* utf8 data manipulation:process using chof                      //~7712I~
//*********************************************************************//~7712I~
//v70g:200715 (BUG)utfcvl2f retrns err when wcwidth=0 and output char same as input. it should set utf8 even width=0//~v70gI~
//v70f:200715 (BUG)utcctr2offs have to consider 3/4 byte dbcs      //~v70fI~
//v70e:200715 (LNX,Axe)Axe use icu as local converter and icu can translate u-00a4 to 8fa2f0(3 byte locale code)//~v70eI~
//            utfpos2offs called from charfldeditu8 because curcol<enndcol. utfpos2offs have to count 1d2(dbcstbl)//~v70eI~
//v702:200615 ARM compiler warning                                 //~v702I~
//v6Vj:180617 xe:vbkb:180618                                       //~v6VjI~
//            uvbka but cs4(ddfmtlen=2) and errrep(lclen=1) cause err; xeutf_cvf2dd-->utfcvf2dd  may change ddlen=2 to lclen=1, it append 1  slag byte to filename//~v6VjI~
//            pancmdlf2dd-->xeutf_cvf2dd(lclen=1 of byte one "?")-->utfcvf2dd:lclen short because ddlen=2//~v6VjI~
//            set dbcs "?" for errrep of ddlen=2 at utfcvf2dd      //~v6VjI~
//v6T4:180217 f2l option to set dbcs "?" for f2l err               //~v6T4I~
//v6C6:160404 (Bug)tracing uninitialized area                      //~v6C6I~
//v6BA:160303 W32:wcstombs and mbrtowc dose not support surrogate pair,use WIdeChar<-->Multibute api//~v6BAI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uR:140606 utfcvl2fany1 cv only one utf8 char(if ascii return 1 byte)//~v6uRI~
//v6uM:140606 (LNX:BUG)F2L/U2L trans 0xff>=.. 0x=>80 to hankaku katakana is iconv BUG?,back trans is ffxx for han-kana//~v6uMI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6ueI~
//v6t3:140320 (BUG)GB4 l2f translation err if asciiret flag on(getmixedword)//~v6t3I~
//v6s0:140212 (LNX:BUG)crash on xterm(also on green console) when eucjp filename by utf8 code exists.//~v6s0I~
//            TTYCONS on-->Slocale=iso8859-->utfcvl2fany:iconv rc!=-1-->utfcvf2u set dbcs over input length(0x80-->c280 2byte)//~v6s0I~
//v6hK:120917 delete unused function; utfgetutf8str                //~v6hKI~
//v6hJ:120915 (BUG)utfcvl2fany ignore ASCIIRET request(so getmisxstring treate utf8 string after locale string)//~v6hJI~
//v6hG:120915 utfcvl2f;option to limit by outbuff size             //~v6hGI~
//v6hn:120703 (BUG:Linux localICU mode(-Yi)utfcvl2f should pass 1 mb length to udbcschk_locale1//~v6hnI~
//            (xe EUCJP errmsg is corrupted)                       //~v6hnI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6ha:120612 (BUG)FC5:avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h4:120606 (WTL)vs2010exp stop if used uninitialized variable   //~v6h4I~
//v6h5:120606 (WTL)Bug found by vs2010exp(used uninitialized variable)//~v6h5I~
//v6fk:120429 setlocale("ko_KR.UHC") fail, add EUC-KR              //~v6fkI~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6df:120218 add validateutf8str for Axe(NewStringUTF function cause SIGSEGV when invalid utf8 char contained)//~v6dfI~
//v6bs:111230 add "get ucsctr of ddfmt" for cmdline shrink         //~v6bsI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6b5:110829 utfcvf2u:no need to chk printable as locale code     //~v6b5I~
//v6b4:110814 set output when iconv_open failed to avoid infinite loop//~v6b4I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0R~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v68q:100723 "en_US iso8859 node defined err" msg to console only+v68qI~//~v68qI~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v66n:100529 (LNX:BUG)m2b set errrep(no need to chk unprintable at ucs level but ebc level,more printable)//~v66nI~
//v66e:100522 set dbcs errrep to f2l/dd2l for mixedstrupdate(rep to sbcs "?" will loose dbcsid on dbcstbl)//~v66eI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v645:091218 add f2u for wxe c&p                                  //~v645I~
//v644:091218 f2l errrep by utfwcwidth when f2u is ok(to keep column width)//~v644I~
//v638:091117 (UTF8)skip setlocale errmsg for other than xe        //~v638I~
//v637:091117 (UTF8:BUG)on console,safe to mot use dbcs mode;use iso88591//~v637I~
//v634:091115 (UTF8:BUG) selevt "UHC"/"GB18030" as default if env is UTF8//~v633I~
//            utf2.c udbcschk.c utf.h                              //~v633I~
//v633:091115 (UTF8:LNX:BUG) setlocale "ko_kr.UHC" fail like as v62W//~v633I~
//            ignore setlocale err when parm specified,warning msg only.//~v633I~
//v62W:091103_(BUG)setlocale fail when env has utf8 only. accept as no dbcs env.//~v62WI~
//            i isvaliduntu910 installed by lang=English, "locale -a" shows "en_US.UTF8" only, there is no "en_US"//~v62WI~//~v6dfR~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62Q:091014_(BUG)on Windows,f2l use utf2sjis(internal cv tbl) but l2f use wincp2ucs//~v62QI~
//            unify to external converter because trans err case is fewer,and also fo LNX.//~v62QI~
//v62P:091013_missing set UDBCSCHK_DBCSLANG flag if Windows        //~v62PI~
//v62N:091013_(LNX:BUG)l2f1 should chk only 1 char(iconv translate multiple. 4byte dbcs may translated to 2 dbcs by another iconv handle)//~v62NI~
//v62M:091014_(LNX:BUG)It should back to original locale after setup unprintable//~v62MI~
//v62J:091008_ASCIIRET support for ucvsutf2sjis<-f2l               //~v62JI~
//v62G:091005_(BUG)for isprint func;utfcvu2lany1mb is always success. isprint should be used//~v62GI~
//                 but for isprint setlocale should be issued for -Cparameter. v62F is now meaningless.//~v62GI~
//v62E:091003_(WIN)f2l support errret for WideToMultiByte          //~v62EI~
//v62D:091003_f2l support errret for also sjis                     //~v62DI~
//v62x:091002_(WIN:BUG)on C(J)K console, wctomb is invalid when console cp!=system codepage//~v62xI~
//v62v:091011_(LNX:BUG) default locale chk fail by intermediate "." of zh_CN.GB18030//~v62vI~//~v62tR~
//v62u:091011_(WIN:BUG) displayed default locale on top menu is not of dosprompt codepage setting//~v62uI~
//v62t:090930!utfret option for utfcvl2f                           //~v62tR~
//v62s:090926!(BUG of V625)couldnot chk ascii if iconv rc=-1       //~v62sI~
//v62p:090916!add udbcschk_pos2offs                                //~v62pI~
//v62k:090912=(BUG)errchk level(rc of utfisvalidutf8 at utfgetutf8str)//~v62kI~
//v62j:090907 UTF8SUPP-->UTF8SUPPH for common to xe and wxe(wxe compiled by vc6;uncoditional for LNX because xxe use ulibxxe)//~v62jI~
//v62h:090823 mbtowc:check by reverse conversion for err ucs 30fb  //~v62hI~
//v62f:090811 ucvssutf2sjis:option to advanse 1 byte for conversion err//~v62fI~
//v62e:090810 (BUG) utfcvf2l;offs is not initialized               //~v62eI~
//v627:090719 use setlocale when not UTF8(avoid dup req,reissue of setlocale(,"") reset to default locale)//~v627I~
//v626:090718 use GB18030>GBK>GB2312 fo zh_CN                      //~v626I~
//v625:090718 (BUG)utf string was cut when not DBCS env            //~v625I~
//v624:090712 compile err on Z390(reported by Dirk@...de)          //~v627I~
//v623:090621 (BUG)utfcvf2l missing to set chklen                  //~v623I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            for CJK and LANG=..UTF8, wctomb/mbtowc-->iconv/WinAPI//~v620I~
//            add utfgetutf8strlen                                 //~v620R~
//            add utfsplitchk                                      //~v620I~
//            pos2offs using codetype                              //~v62kI~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nf:081011*(UTF:BUG)UTCO_DBCSBACK option process err for utfstrchkmbr2wc//~v5nfR~
//v5ne:081011 (XXE)draw ime cursor                                 //~v5neR~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v61u:080802 (UTF)utfcvf2l for windows wsing wctomb (setlocale required)//~v61uI~
//v5m0:080125 warning when install to debian4                      //~v5m0I~
//v61p:080126 (UTF:BUG)xc ABEND when locale code err               //~v61pI~
//v61m:080105 (UTF:BUG)ascii-stop rc is ignore                     //~v61mI~
//v61j:071229 (UTF:BUG)e2f out length set err                      //~v61jI~
//v61h:071225 (UTF:BUG)display err for locale file under UTF8 env  //~v61hI~
//v61g:071222 (UTF)locale<-->utf8 conversion support               //~v61gI~
//v61b:071205 (UTF:LNX)support locale other than EUC               //~v61bI~
//v61a:071205 (UTF)dbcstbl support of utfgetutf8str                //~v61aI~
//v618:071201 (UTF)udirlist support sort by name by utf8           //~v618I~
//v617:071130 (UTF)utfchk 1 byte char                              //~v617I~
//v616:071129 (UTF)l2f is wrapper to e2f                           //~v616I~
//v612:071113 (UTF)utfcvl2f optionaly return char width            //~v612I~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v60p:071021 (UTF)display by ' '+nonspace char for charwidth=0    //~v60pI~
//v60k:071019 (UTF:LNX)not printable(all byte are displayed as unprintable) and width<0(1 unpritable) is not same//~v60kI~
//v60e:071017 (UTF)add utfcve2f(euc to utf8)                       //~v60eI~
//v60d:071016 (UTF)add utfcvl2f(locale to utf8)                    //~v60dI~
//v60a:070928 (UTF:WXE)                                            //~v60aI~
//v600:070710 (UTF8)new typdef                                     //~7712I~
//*********************************************************************//~7712I~
#include <stdio.h>                                                 //~7712I~
#include <stdlib.h>                                                //~7712I~
#include <ctype.h>                                                 //~7712I~
#include <string.h>                                                //~7712I~
#include <errno.h>                                                 //~7712I~
#ifdef LNX                                                         //~7712I~
	#include <iconv.h>                                             //~v61bI~
    #define __USE_XOPEN                                            //~7712I~
    #include <wchar.h>                                             //~7712I~
  #ifndef ARM                                                      //~v6a0I~
    #include <langinfo.h>                                          //~v61bI~
  #endif                                                           //~v6a0I~
#endif                                                             //~7712I~
#include <locale.h>                                                //~v61bI~
//*******************************************************          //~7712I~
#include <ulib.h>                                                  //~7712I~
#include <ualloc.h>                                                //~7824I~
#include <udbcschk.h>                                              //~v60aI~
#include <uque.h>                                                  //~7712I~
#include <ucvucs.h>                                                //~7712I~
#include <utf.h>                                                   //~7712I~
#include <ustring.h>                                               //~v61bI~
#include <utrace.h>                                                //~7712I~
#include <uerr.h>                                                  //~7712I~
#include <utf.h>                                                   //~7712I~
#include <utf2.h>                                                  //~7712I~
#include <uproc.h>                                                 //~v61bI~
#include <ufile.h>                                                 //~v61bI~
#include <ufile4.h>                                                //~v61bI~
#ifdef UTF8SUPPH                                                   //~v620I~
	#include <ucvebc.h>                                            //~v620I~
	#include <ucvext.h>                                            //~v620I~
#endif                                                             //~v620I~
#ifdef UTF8UCS2                                                    //~v644I~
	#include <utf22.h>                                             //~v644I~
#endif                                                             //~v644I~
//**************************************************               //~v61bI~
#define PARMCHK_UTF    "UTF"      //env charset check              //~v627I~
//#define LOCALEID_UTF8  "UTF8"      //iconv parm                  //~v62WR~
#define GETLOCALECMD   "locale -a"   //cmd to listup available codeset//~v61bI~
//**************************************************               //~7801M~
#ifdef UTF8SUPPH                                                   //~v620I~
static                                                             //~v627I~
    UCHAR *Sdbcstbl;		//basr locale even if locale:UTF8      //~v620I~
static                                                             //~v627I~
//  ULONG  Spconverters;    //ptr to Sconverters[TOUCS,FROMUCS]    //~v620R~//~v6hhR~
    ULPTR  Spconverters;    //ptr to Sconverters[TOUCS,FROMUCS]    //~v6hhI~
	#ifdef W32                                                     //~v620I~
		static int Scodepage;                                      //~v620I~
	#endif                                                         //~v620I~
//    static char Sparmcharset[MAXLOCALESZ];                         //~v627I~//~v624R~
#endif                                                             //~v620I~
//#ifdef UTF8SUPP                                                    //~v5n8I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
#ifdef LNX                                                         //~v61bI~
static                                                             //~v627I~
	iconv_t Shiconvl2f=0,Shiconvf2l=0;                             //~v61bR~
static                                                             //~v627I~
    char Slocale[MAXLOCALESZ];                                     //~v61bI~
#endif                                                             //~v61bI~
static int Sswgeticu=0;                                            //~v6f3I~
//**************************************************               //~v61bI~
#ifdef LNX                                                         //~v61bI~
	int utfcvlocaleopen(int Popt,char *Pplocale,iconv_t *Pphiconv);//~v61bR~
	int utfcvlocaleclose(int Popt,iconv_t Phiconv);                //~v61bR~
	int utfgetcharset(char *Pplocale,char *Ppcodeset);             //~v61bR~
	int utfgetstrlenHK(int Popt,char *Pu8,int Plen);               //~v6uMI~
#endif                                                             //~v61bI~
//int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,wchar_t *Ppucs);//~v62UR~
//char *utfcvsetdefaultlocale(void);                               //~v5n0R~
int utfcvlocaleinitICU(int Popt,char *Pplocale);                   //~v6f3I~
int utflocalechkICU(int Popt,char *Pplocale);                      //~v6f3I~
#endif //UTF8SUPPH                                                 //~v6hhR~
#ifdef UTF8SUPPH                                                   //~v620I~
//**************************************************               //~v62hI~
//chk conv err by reverse conv                                     //~v62hI~
//ret :mblen or 0/-1 if err                                        //~v62hI~
//**************************************************               //~v62hI~
//int umbtowc(wchar_t *Ppucs,char *Pinp,int Pinplen)                 //~v62hI~//~v6a0R~
//int umbtowc(UWCHART *Ppucs,char *Pinp,int Pinplen)                 //~v6a0I~//~v6BjR~
int umbtowc(UWUCS *Ppucs,char *Pinp,int Pinplen)                   //~v6BjI~
{                                                                  //~v62hI~
//  wchar_t ucs;                                                   //~v62hI~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
#ifdef W32                                                         //~v6BjI~
  #ifdef AAA                                                       //~v6BAI~
	UWCHART ucs2s[2];                                              //~v6BjI~
    int utf16ctr=1;                                                //~v6BjR~
  #endif                                                           //~v6BAI~
#endif                                                             //~v6BjI~
    UWUCS ucs;                                                     //~v6BjI~
#ifdef W32
    int chklen;                                                    //~v6BAI~
#else                                                              //~v6BAI~
    int chklen,mblen;                                              //~v62hI~
    char mb[MAX_MBCSLEN+1];                                          //~v62hR~//~v62xR~
#endif
#ifdef ARM  //mbtowc is noy supported yet                          //~v6a0I~
//  mbstate_t mbs;                                                 //~v6a0I~//~v702R~
#endif                                                             //~v6a0I~
//*******************************                                  //~v62hI~
    UTRACED("inp",Pinp,Pinplen);                                   //~v6BkI~
#ifdef W32                                                         //~v6BjI~
  #ifdef AAA                                                       //~v6BAI~
    chklen=mbtowc(ucs2s,Pinp,Pinplen);                             //~v6BjI~
    if (chklen>0)                                                  //~v6BjI~
    {                                                              //~v6BjI~
        ucs=ucs2s[0];                                              //~v6BjI~
        if (IS_UTF16_PAIR(ucs,ucs2s[1]))                           //~v6BjR~
        {                                                          //~v6BjI~
            ucs=UTF16_TO_UCS4(ucs,ucs2s[1]);                       //~v6BjI~
            utf16ctr=2;                                            //~v6BjI~
        }                                                          //~v6BjI~
    }                                                              //~v6BjI~
  #else  //!AAA                                                    //~v6BAI~
	chklen=umbtowcW(0,Pinp,Pinplen,Ppucs);                         //~v6BAR~
    ucs=*Ppucs;                                                    //~v6BAR~
UTRACEP("%s:(W32) umbtowcW ucs=%04x,rc=%d\n",UTT,ucs,chklen);      //~v6BAR~
  #endif                                                           //~v6BAI~
#else                                                              //~v6BjI~
//  chklen=mbtowc(&ucs,Pinp,Pinplen);                              //~v62hI~//~v6BkR~
    chklen=mbtowc(&ucs,Pinp,(size_t)Pinplen);                      //~v6BkI~
UTRACEP("%s:(LNX) mbtowc ucs=%x,chklen=%d\n",UTT,ucs,chklen);//~v62xR~  //~v6BkR~//~v6BAI~
#endif                                                             //~v6BjI~
    if (chklen<=0)                                                 //~v62hI~
    	return chklen;                                             //~v62hI~
#ifdef W32                                                         //~v6BjI~
  #ifdef AAA	//umbtowc did reversechk                           //~v6BAI~
    if (utf16ctr==2)   //ucs4,use surrogateH+L                     //~v6BjR~
    {                                                              //~v6BjI~
        mblen=wcstombs(mb,ucs2s,2);                                //~v6BjR~
        UTRACEP("%s:Win UCS4=%x,surrogate=(%x,%x),mbstr=%s\n",UTT,ucs,ucs2s[0],ucs2s[1],Pinp);//~v6BjR~
    }                                                              //~v6BjI~
    else                                                           //~v6BjI~
		mblen=wctomb(mb,(UWCHART)ucs);                             //~v6BjI~
  #endif                                                           //~v6BAI~
#else                                                              //~v6BjI~
	mblen=wctomb(mb,ucs);                                          //~v62hI~
#endif                                                             //~v6BjI~
#ifdef W32                                                         //~v6BAI~
#else                                                              //~v6BAI~
UTRACEP("umbtowc wctomb mblen=%d,mb=%x\n",mblen,*mb);              //~v62xR~
    if (mblen!=chklen                                              //~v62hI~
    ||  memcmp(mb,Pinp,(UINT)mblen))                               //~v62hI~
    {                                                              //~v6BAI~
	    *Ppucs=ucs;                                                //~v6BAI~
    	return -1;		//err                                      //~v62hI~
    }                                                              //~v6BAI~
#endif                                                             //~v6BAI~
    *Ppucs=ucs;                                                    //~v62hI~
UTRACEP("umbtowc ret chklen=%d\n",chklen);                         //~v62xI~
    return chklen;                                                 //~v62hI~
}//umbtowc                                                         //~v62hI~
//**************************************************               //~v620I~
//get offset on utfstr corresponding to locale string column       //~v620I~
//Pcodetype:optional input                                         //~v62kI~
//rc:4:Ppos is out of range,1:dbcs split,0:ok                      //~v620I~
//**************************************************               //~v620I~
int utfpos2offs(int Popt,char *Putf8,char *Pdbcs,char *Pcodetype,int Ppos,int Putf8len,int *Ppoffs)//~v62kR~
{                                                                  //~v620I~
    int ii,ch,utf8chsz=0,utf8len,utf8offs,reslen,rc;               //~v6h4R~
    char *pc,*pdbcs,*pct;                                          //~v62kR~
    char lastdbcs=0;                                               //~v70eI~
//****************************                                     //~v620I~
    if (!(utf8len=Putf8len))                                       //~v620I~
	    utf8len=(int)strlen(Putf8);                                //~v620I~
    UTRACED("utfpos2offs utf8",Putf8,Putf8len);                    //~v702I~
    UTRACED("utfpos2offs pdbcs",Pdbcs,Ppos);                       //~v702I~
    UTRACED("utfpos2offs codetb",Pcodetype,Ppos);                  //~v702I~
    pct=Pcodetype;                                                 //~v62kI~
    for (pc=Putf8,pdbcs=Pdbcs,ii=0,utf8offs=0,reslen=utf8len;ii<Ppos && reslen>0;ii++,pdbcs++)//~v620I~
    {                                                              //~v620I~
//      UTRACEP("%s:ii=%d,offs=%d,pos=%d,reslen=%d,dbcs=%x,utf8=%x\n",UTT,ii,utf8offs,Ppos,reslen,*pdbcs,*pc);//~v702R~
        if (pct)                                                   //~v62kI~
        {                                                          //~v62kI~
        	if (*pct!=UTFCT_UTF8)                                  //~v62kI~
            {                                                      //~v62kI~
                utf8chsz=1;                                        //~v62kI~
            	pc++;                                              //~v62kI~
                utf8offs++;                                        //~v62kI~
                reslen--;                                          //~v62kI~
                pct++;                                             //~v62kI~
                continue;                                          //~v62kI~
            }                                                      //~v62kI~
            pct++;                                                 //~v62kI~
        }                                                          //~v62kI~
    	if (*pdbcs==UDBCSCHK_DBCSPAD)                              //~v62UR~
        	continue;                                              //~v62UR~
    	if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~v620R~
        	continue;                                              //~v620I~
        lastdbcs=*pdbcs;                                           //~v70eI~
    	ch=*pc;                                                    //~v620I~
    	utf8chsz=UTF8CHARLENERR1(ch);	//next if invalid utf8     //~v620I~
    	pc+=utf8chsz;                                              //~v620I~
        utf8offs+=utf8chsz;                                        //~v620I~
        reslen-=utf8chsz;                                          //~v620I~
    }                                                              //~v620I~
UTRACEP("%s:lastdbcs=%c,ii=%d,Ppos=%d\n",UTT,lastdbcs,ii,Ppos);    //~v70eI~
    if (lastdbcs==UDBCSCHK_DBCS1ST)                                //~v70eR~
        for (;ii<Ppos;ii++,pdbcs++)                                //~v70eI~
        {                                                          //~v70eI~
            if (*pdbcs!=UDBCSCHK_DBCSPAD && *pdbcs!=UDBCSCHK_DBCS2ND)//~v70eI~
                break;                                             //~v70eI~
        }                                                          //~v70eI~
    if (ii<Ppos)   //out of range                                  //~v620I~
        rc=4;                                                      //~v620I~
    else                                                           //~v620I~
//      if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~v62UR~
        if (*pdbcs==UDBCSCHK_DBCS2ND                               //~v62UR~
    	||  *pdbcs==UDBCSCHK_DBCSPAD)                              //~v62UR~
        {                                                          //~v620I~
        	rc=1;                                                  //~v620I~
            utf8offs-=utf8chsz;                                    //~v620I~
        }                                                          //~v620I~
        else                                                       //~v620I~
        	rc=0;                                                  //~v620I~
    *Ppoffs=utf8offs;                                              //~v620I~
UTRACEP("utfpos2offs rc=%d,pos=%d,offs=%d\n",rc,Ppos,utf8offs);    //~v62kI~
UTRACED("pu8",Putf8,utf8len);                                      //~v62kI~
UTRACED("pdbcs",Pdbcs,Ppos);                                       //~v62kI~
UTRACED("pct",Pcodetype,Ppos);                                     //~v62kI~
    return rc;                                                     //~v620I~
}//utfpos2offs                                                     //~v620I~
//**************************************************               //~v6bsI~
//get offset on utfstr corresponding to char count                 //~v6bsI~
//dbcs is not ddfmt                                                //~v6bsI~
//rc:4:out of range                                                //~v6bsI~
//**************************************************               //~v6bsI~
int utfctr2offs(int Popt,char *Putf8,char *Pdbcs,char *Pcodetype,int Ppos,int Putf8len,int *Ppoffs,int *Ppwidth)//~v6bsR~
{                                                                  //~v6bsI~
    int ii,utf8chsz,utf8len,reslen,rc=0,dbcsid;                    //~v6bsR~
    char *pc,*pcd,*pct;                                            //~v6bsI~
//****************************                                     //~v6bsI~
    if (!(utf8len=Putf8len))                                       //~v6bsI~
	    utf8len=(int)strlen(Putf8);                                //~v6bsI~
    pct=Pcodetype;                                                 //~v6bsI~
    for (pc=Putf8,pcd=Pdbcs,ii=0,reslen=utf8len;ii<Ppos && reslen>0;ii++)//~v6bsI~
    {                                                              //~v6bsI~
UTRACEP("%s:ii=%d,Ppos=%d,pc=x%x,dbcs=%c,ct=%p=x%x\n",UTT,ii,Ppos,*pc,*pcd,pct,*pct);//~v70eR~
        dbcsid=*pcd;                                               //~v6bsI~
        if (*pct!=UTFCT_UTF8)                                      //~v6bsI~
        {                                                          //~v6bsI~
            pc++;                                                  //~v6bsI~
            pcd++;                                                 //~v6bsI~
            pct++;                                                 //~v6bsI~
            reslen--;                                              //~v6bsI~
            if (dbcsid==UDBCSCHK_DBCS1ST)                          //~v6bsI~
            {                                                      //~v6bsI~
                for (;reslen>0;pc++,pcd++,pct++,reslen--)          //~v6bsI~
                	if (!UDBCSCHK_DBCSNOT1ST(*pcd))                //~v6bsI~
                    	break;                                     //~v6bsI~
            }                                                      //~v6bsI~
        }                                                          //~v6bsI~
        else	//utf8                                             //~v6bsI~
        {                                                          //~v6bsI~
	    	utf8chsz=UTF8CHARLENERR1(*pc);	//next if invalid utf8 //~v6bsI~
            pc+=utf8chsz;                                          //~v6bsI~
            pcd++;                                                 //~v6bsI~
            pct++;                                                 //~v6bsR~
            reslen-=utf8chsz;                                      //~v6bsI~
            if (dbcsid==UDBCSCHK_DBCS1ST)                          //~v6bsR~
            {                                                      //~v6bsI~
              while(UDBCSCHK_DBCSNOT1ST(*pcd))                     //~v70fR~
              {                                                    //~v70fR~
            	pcd++;                                             //~v6bsI~
                pct++;                                             //~v6bsR~
              }                                                    //~v70fR~
            }                                                      //~v6bsI~
//#ifdef W32UNICODE //surrogate pair is 4 "?"                      //~v6ueR~
//            else                                                 //~v6ueR~
//            if (utf8chsz>=4)    //>0x10000 is surrogate pair, occupy 4 column//~v6ueR~
//            {                                                    //~v6ueR~
//                ii++;       //Ppos counted 2 for surrogate pair at utfddgetucsctr//~v6ueR~
//                pcd+=3;                                          //~v6ueR~
//                pct+=3;                                          //~v6ueR~
//            }                                                    //~v6ueR~
//#endif                                                           //~v6ueR~
        }                                                          //~v6bsI~
    }                                                              //~v6bsI~
//UTRACEP("%s:loop out ii=%d,Ppos=%d,pc=x%x,dbcs=%c,ct=%p=x%x\n",UTT,ii,Ppos,*pc,*pcd,pct,*pct);//~v70eR~//~v70fR~
    if (ii<Ppos)   //out of range                                  //~v6bsI~
        rc=4;                                                      //~v6bsI~
//  *Ppoffs=(ULONG)pc-(ULONG)Putf8;                                //~v6bsI~//~v6hhR~
//  *Ppoffs=(ULPTR)pc-(ULPTR)Putf8;                                //~v6hhI~//~v6BkR~
    *Ppoffs=PTRDIFF(pc,Putf8);                                     //~v6BkI~
//  *Ppwidth=(ULONG)pct-(ULONG)Pcodetype;                          //~v6bsI~//~v6hhR~
//  *Ppwidth=(ULPTR)pct-(ULPTR)Pcodetype;                          //~v6hhI~//~v6BkR~
    *Ppwidth=PTRDIFF(pct,Pcodetype);                               //~v6BkI~
UTRACEP("utfctr2offs rc=%d,pos=%d,offs=%d,width=%d\n",rc,Ppos,*Ppoffs,*Ppwidth);//~v6bsR~
UTRACED("pu8",Putf8,utf8len);                                      //~v6bsI~
UTRACED("pdbcs",Pdbcs,Ppos);                                       //~v6bsI~
UTRACED("pct",Pcodetype,Ppos);                                     //~v6bsI~
    return rc;                                                     //~v6bsI~
}//utfctr2offs                                                     //~v6bsI~
#endif                                                             //~v620R~
#ifdef UTF8SUPP                                                    //~v620I~
//**************************************************               //~v61bI~
//*get offset of column considering current top pos                //~7801M~
//*return:ret offset from cpos,-1:no chof setup,-2:outof range     //~7801M~
//**************************************************               //~7801M~
int utfpos2offschof(int Popt,PUTCHARS Pputcs,int Ppos)             //~7801M~
{                                                                  //~7801M~
    CHOFTYPE *pchof;                                               //~7801M~
    UCHAR *pdata;                                                  //~7801M~
    int rc,width,ch,chlen,pos,coffs,rc2;                           //~7824R~
//***************                                                  //~7801M~
    Gutfrc=0;	//to allow minus offset returns                    //~7827I~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputcs))                  //~7806I~
        return Ppos;                                               //~7806I~
	pdata=Pputcs->data;                                            //~7801M~
	width=Pputcs->lenc;                                            //~7801M~
	pchof=Pputcs->chof;                                            //~7801M~
    pos=Pputcs->cpos+Ppos;                                         //~7801M~
    if (pos<0)                                                     //~7801M~
        rc=Gutfrc=UTCRC_OUTR;                                      //~7827R~
    else                                                           //~7806M~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputcs))                  //~7806I~
		rc=Ppos;                                                   //~7806M~
    else                                                           //~7801M~
    if (pos>width)                                                 //~7801M~
    {                                                              //~v60rI~
		coffs=*(pchof+Pputcs->cpos);                               //~v618I~
    	if (Popt & UTCO_EOLSTOP)                                   //~v60rM~
        {                                                          //~v618I~
	        Gutfrc=UTCRC_EOLSTOP;                                  //~v618R~
	        rc=*(pchof+width)-coffs;                               //~v618R~
        }                                                          //~v618I~
        else                                                       //~v60rM~
        if (!(Popt & UTCO_ERRBEYOND))                              //~7828R~
	        rc=*(pchof+width)+pos-width-coffs;                     //~v618R~
        else                                                       //~7801M~
	        rc=Gutfrc=UTCRC_OUTR;                                  //~7827R~
    }                                                              //~v60rI~
    else                                                           //~7801M~
    {                                                              //~7801M~
		coffs=*(pchof+Pputcs->cpos);                               //~7829I~
        rc=*(pchof+pos)-coffs;                                     //~7829I~
        if (pos)	//not tgt top                                  //~7829R~
        {                                                          //~7801M~
            if (pos<width)                                         //~7806I~
            {                                                      //~7806I~
                ch=*(pdata+rc);                                    //~7806R~
                chlen=UTF8CHARLEN(ch);                             //~7806R~
                if (!chlen) //not top byte                         //~7806R~
                {                                                  //~7806R~
                    rc2=*(pchof+pos-1)-coffs;                      //~7824I~
    	            ch=*(pdata+rc2);                               //~7824I~
	                chlen=UTF8CHARLEN(ch);                         //~7824I~
                    if (chlen==rc-rc2+1)	//dbcs                 //~7824I~
                    {                                              //~7824I~
                    	if (Ppos && (Popt & UTCO_DBCSBACK))        //~7824R~
                        {                                          //~v618I~
                        	Gutfrc=UTCRC_DBCSBACK;                 //~v618I~
                        	rc=rc2;                                //~7824R~
                        }                                          //~v618I~
                    	else                                       //~7824R~
                    		if (pos+1<=width && (Popt & UTCO_DBCSNEXT))//~7824R~
                        		rc=*(pchof+pos+1)-coffs;           //~7824R~
                    	else                                       //~7824R~
                        	Gutfrc=UTCRC_DBCSSPLIT;                //~7824R~
                    }                                              //~7824I~
                    else                                           //~7824I~
                        Gutfrc=UTCRC_ERRUTFCHAR;                   //~7824I~
                }                                                  //~7806R~
            }                                                      //~7806I~
        }                                                          //~7801M~
    }                                                              //~7801M~
//UTRACEP("utfpos2offs pos=%d,rc(offs)=%d width=%d\n",Ppos,rc,width);//~v60eR~
	if (Gutfrc<0)                                                  //~7827R~
    	if (Popt & UTCO2_ERR0)                                     //~7801M~
        	rc=0;                                                  //~7801M~
    return rc;                                                     //~7801M~
}//utfpos2offschof                                                 //~7801M~
//**************************************************               //~7801M~
//*search column of offset considering curent top                  //~7801M~
//*byte offs: if offs<lenutf return offs-*pos,else lenutf-offs(minus)//~7801M~
//*return:ret pos from cpos,-1:no chof setup,-2:outof range        //~7801M~
//**************************************************               //~7801M~
int utfoffs2poschof(int Popt,PUTCHARS Pputcs,int Poffs,int *Ppbyteoffs)//~7801M~
{                                                                  //~7801M~
    CHOFTYPE *pchof;                                               //~7801M~
//  int rc,ii,lenc,lenutf,byteoffso=0,byteoffs,offs0,cpos;         //~7801M~//~v6h4R~
    int rc,ii,lenc,lenutf,byteoffso=0,byteoffs=0,offs0,cpos;       //~v6h4I~
//***************                                                  //~7801M~
    Gutfrc=0;	//to allow minus offset returns                    //~v618I~
    if (Ppbyteoffs)                                                //~7801M~
    	*Ppbyteoffs=0;                                             //~7801M~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputcs))                  //~7801M~
		return Poffs;                                              //~7801M~
	lenc=UTCLENC(Pputcs);                                          //~7801M~
	cpos=UTCCPOS(Pputcs);                                          //~7801M~
    pchof=UTCCHOF(Pputcs);                                         //~7801M~
    offs0=*(pchof+cpos);                                           //~7801M~
	lenutf=*(pchof+lenc)-offs0;	//len after cpos                   //~7801M~
    if (Poffs<0) //out of set len                                  //~7801M~
    	rc=UTCRC_OUTR;                                             //~7801M~
    else                                                           //~7801M~
    if (Poffs>lenutf) //out of set len                             //~7801M~
    {                                                              //~7801M~
    	if (Popt & UTCO_EOLSTOP)                                   //~7801M~
        {                                                          //~7801M~
	        Gutfrc=UTCRC_EOLSTOP;                                  //~v618I~
	    	rc=lenc;                                               //~7801M~
    		if (!(Popt & UTCO_NOBEYONDCNT))                        //~7816R~
	            if (Ppbyteoffs)                                    //~7809R~
    	        	*Ppbyteoffs=lenc-Poffs;                        //~7809R~
        }                                                          //~7801M~
        else                                                       //~7801M~
    	if (!(Popt & UTCO_ERRBEYOND))                              //~7828I~
        {                                                          //~7828M~
	    	rc=lenc+Poffs-lenutf;                                  //~7828M~
    		if (!(Popt & UTCO_NOBEYONDCNT))                        //~7828M~
	            if (Ppbyteoffs)                                    //~7828M~
    	        	*Ppbyteoffs=lenc-Poffs;	 //beyond id           //~7828M~
        }                                                          //~7828M~
        else                                                       //~7828M~
	    	rc=UTCRC_OUTR;                                         //~7801M~
    }                                                              //~7801M~
    else                                                           //~7801M~
    {                                                              //~7801M~
	    pchof+=cpos;                                               //~7801I~
        for (ii=0;ii<=lenc;ii++,pchof++)                           //~7801M~
        {                                                          //~7801M~
        	byteoffs=Poffs-(*pchof-offs0);                         //~7801M~
            if (!byteoffs)                                         //~7801M~
                break;                                             //~7801M~
            if (byteoffs<0)                                        //~7801M~
            {                                                      //~7801M~
                ii--;                                              //~7801M~
                byteoffs=byteoffso;                                //~7801M~
                break;                                             //~7801M~
            }                                                      //~7801M~
            byteoffso=byteoffs;                                    //~7801M~
        }                                                          //~7801M~
        if (ii>lenc && byteoffs)                                   //~7801M~
        	rc=UTCRC_OUTR;                                         //~7801M~
        else                                                       //~7801M~
        {                                                          //~7801M~
	        rc=ii;                                                 //~7801M~
		    if (Ppbyteoffs)                                        //~7801M~
    			*Ppbyteoffs=byteoffs;                              //~7801M~
        }                                                          //~7801M~
    }                                                              //~7801M~
//UTRACEP("utfoffs2pos offs=%d,rc(pos)=%d,byteoffs=%d lenc=%d,lenutf=%d\n",Poffs,rc,byteoffs,lenc,lenutf);//~7801M~//~v6h4R~
	if (rc<0)                                                      //~7801M~
    	if (Popt & UTCO2_ERR0)                                     //~7801M~
        	rc=0;                                                  //~7801M~
    return rc;                                                     //~7801M~
}//utfoffs2poschof                                                 //~7801M~
//**************************************************               //~7801M~
//*get offset of column considering current top pos                //~7801M~
//*return:ret offset,-1:no chof setup,-2:outof range               //~7801M~
//**************************************************               //~7801M~
int utfisdbcssplit(int Popt,PUTCHARS Pputcs,int Ppos)              //~7801M~
{                                                                  //~7801M~
    CHOFTYPE *pchof;                                               //~7801M~
    UCHAR *pdata;                                                  //~7801M~
    int width,ch,chlen,chlenbychof,offsp,pos;                      //~7801M~
//***************                                                  //~7801M~
	pdata=Pputcs->data;                                            //~7801M~
	width=Pputcs->lenc;                                            //~7801M~
	pchof=Pputcs->chof;                                            //~7801M~
    if (!UTF8MODE() || !UTC_ISNORMALCHOF(Pputcs))                  //~7806I~
		return 0;		//unkown                                   //~7806R~
    pos=Pputcs->cpos+Ppos;                                         //~7801M~
    if (pos<=0)                                                    //~7801M~
		return 0;		//unknown                                  //~7801M~
    if (pos>=width)                                                //~7801M~
		return 0;		//unknown                                  //~7806R~
    offsp=*(pchof+pos-1);                                          //~7801M~
    ch=*(pdata+offsp);                                             //~7801M~
    chlen=UTF8CHARLEN(ch);                                         //~7801M~
    if (chlen<=1)	//invalid utf or ascii                         //~7801M~
    	return 0;	//not split                                    //~7801M~
    chlenbychof=*(pchof+pos)-offsp;                                //~7801M~
    if (chlen>chlenbychof)                                         //~7801M~
    	return 1;                                                  //~7801M~
    return 0;                                                      //~7801M~
}//utfisdbcssplit                                                  //~7801M~
//**************************************************               //~7712I~
//*data address subtruction by col or len                          //~7818R~
//*ret rc                                                          //~7729I~
//**************************************************               //~7712I~
int utfbackoffset(int Popt,PUTCHARS Pputc,int Plen)                //~7712I~
{                                                                  //~7712I~
//	int rc=0,cpos,backstep,newpos;                                 //~7818R~//~v6h4R~
  	int rc=0,cpos,backstep,newpos=0;                               //~v6h4I~
    PCHOFTYPE pchof;                                               //~7728I~
//*******************                                              //~7712I~
    if (!UTF8MODE())                                               //~7806I~
        backstep=Plen;                                             //~7806I~
    else                                                           //~7806I~
	if (UTC_ISASCII(Pputc))	//chof setup                           //~7728R~
        backstep=Plen;                                             //~7729R~
    else                                                           //~7728I~
	if (!UTC_ISVALIDCHOF(Pputc))	//chof setup                   //~7728I~
        backstep=Plen;                                             //~7729R~
    else                                                           //~7728I~
    {                                                              //~7712I~
    	pchof=Pputc->chof;                                         //~7728I~
    	cpos=Pputc->cpos;                                          //~7728I~
        backstep=*(pchof+cpos);                                    //~7729R~
        if (Popt & UTCO_BYOFF)                                     //~7818I~
        {                                                          //~7818I~
        	if (backstep>=Plen)                                    //~7818I~
            {                                                      //~7818I~
        		backstep-=Plen;                                    //~7818I~
                Pputc->cpos=0;                                     //~7818I~
				rc=utfoffs2poschof(Popt,Pputc,backstep,0);         //~7818R~
                if (rc>=0)                                         //~7818I~
            		newpos=rc;                                     //~7818I~
            }                                                      //~7818I~
        	else                                                   //~7818I~
        		rc=UTCRC_OUTR;                                     //~7818I~
        }                                                          //~7818I~
        else                                                       //~7818I~
        {                                                          //~7818I~
        	if (cpos>=Plen)                                        //~7818R~
            {                                                      //~7818I~
            	newpos=cpos-Plen;                                  //~7818I~
        		backstep-=*(pchof+newpos);                         //~7818R~
            }                                                      //~7818I~
        	else                                                   //~7818R~
        		rc=UTCRC_OUTR;                                     //~7818R~
        }                                                          //~7818I~
    }                                                              //~7728I~
    if (!rc)                                                       //~7818I~
    {                                                              //~7818I~
		Pputc->data-=backstep;                                     //~7818I~
    	Pputc->cpos=newpos;                                        //~7818I~
    }                                                              //~7818I~
    return rc;                                                     //~7712I~
}//utfbackoffset                                                   //~7712I~
//*******************************************************          //~7712M~
//*get pos and offset(consider current pos)                        //~7712M~
//*rc:4 out of range                                               //~7712M~
//*******************************************************          //~7712M~
int utfgetposoffs(int Popt,PUTCHARS Pputchs,int Pposoff,int *Pppos,int *Ppoffs)//~7729R~
{                                                                  //~7712M~
    int rc=0,offs,pos,byteoffs=0;                                  //~7712M~
//*********************************                                //~7712M~
    if (!UTF8MODE()||UTC_ISASCII(Pputchs))                         //~7806I~
    {                                                              //~7728I~
        pos=offs=Pposoff;                                          //~7728I~
    }                                                              //~7728I~
    else                                                           //~7728I~
	if (UTC_ISVALIDCHOF(Pputchs))                                  //~7713R~
    {                                                              //~7712M~
		if (Popt & UTCO_BYOFF)                                     //~7729R~
        {                                                          //~7729M~
        	offs=Pposoff;                                          //~7729M~
        	pos=utfoffs2poschof(Popt,Pputchs,offs,&byteoffs);      //~7729M~
    		if (Gutfrc==UTCRC_EOLSTOP)                             //~v618I~
            	offs=utfpos2offschof(0,Pputchs,pos);               //~v618I~
            else                                                   //~v618I~
            if (pos<0)                                             //~7729M~
            	rc=4;                                              //~7729M~
        }                                                          //~7729M~
        else                                                       //~7729M~
        {                                                          //~7712M~
        	pos=Pposoff;                                           //~7712M~
        	offs=utfpos2offschof(Popt,Pputchs,pos);                //~7716R~
    		if (Gutfrc==UTCRC_EOLSTOP)                             //~v618R~
	        	pos=utfoffs2poschof(0,Pputchs,offs,0);             //~v618I~
            else                                                   //~v618I~
            if (offs<0 && offs==Gutfrc)//allow minus offset        //~7827R~
            	rc=4;                                              //~7712M~
        }                                                          //~7712M~
    }                                                              //~7712M~
    else                                                           //~7712M~
	  if (Popt & UTCO_CHOFGEN)                                     //~v60rR~
		rc=utfgetposoffsmbr2wc(Popt,Pputchs,Pposoff,&pos,&offs);   //~7801R~
      else                                                         //~v60rI~
      	pos=offs=Pposoff;                                          //~v60rR~
    if (Ppoffs)                                                    //~7712M~
		*Ppoffs=offs;                                              //~7712M~
    if (Pppos)                                                     //~7712M~
		*Pppos=pos;                                                //~7712M~
    return rc;                                                     //~7712M~
}//utfgetposoffs                                                   //~7712M~
//*******************************************************          //~7712M~
//*get pos/offset/cnt/len                                          //~7712R~
//*rc:4 out of range                                               //~7712M~
//*******************************************************          //~7712M~
int utfgetposoffscntlen(int Popt,PUTCHARS Pputch,int Pposoffs,int Pcntlen,int *Pppos,int *Ppoffs,int *Ppcnt,int *Pplen)//~7729R~
{                                                                  //~7712M~
    int rc=0,opt;                                                  //~7712M~
    int pos1,offs1,pos2,offs2,posoffs;                             //~7712R~
//*********************************                                //~7712M~
	if (rc=utfgetposoffs(Popt,Pputch,Pposoffs,&pos1,&offs1),rc)//0:byteoffs//~7729R~
    	return rc;                                                 //~7712M~
    if (Pppos)                                                     //~7712I~
    	*Pppos=pos1;                                               //~7712I~
    if (Ppoffs)                                                    //~7712I~
    	*Ppoffs=offs1;                                             //~7712I~
    opt=UTC_OPTCOL2POS(Popt);                                      //~7712R~
    posoffs=(opt & UTCO_BYOFF)?offs1:pos1;                         //~7729R~
    posoffs+=Pcntlen;                                              //~7712I~
    if (Popt & UTCO_MAXWIDTH)                                      //~v618R~
    	opt|=UTCO_DBCSBACK;                                        //~v618I~
	if (rc=utfgetposoffs(opt,Pputch,posoffs,&pos2,&offs2),rc)//to avoid call mbrtowc when no pos chk requred//~7729R~
    	return rc;                                                 //~7712M~
    if (Gutfrc==UTCRC_DBCSBACK)	//right end split dbcs             //~v618I~
    	offs2++;	//include only top byte                        //~v618I~
    if (Ppcnt)                                                     //~v618R~
    	*Ppcnt=pos2-pos1;                                          //~7712R~
    if (Pplen)                                                     //~v618R~
    	*Pplen=offs2-offs1;                                        //~7712R~
    return 0;                                                      //~7712M~
}//utfgetposoffscntlen                                             //~7712M~
//*******************************************************          //~7712M~
//*get pos/off using mbrtowc under the condition chof not yet set  //~7712M~
//*******************************************************          //~7712M~
int utfgetposoffsmbr2wc(int Popt,PUTCHARS Pputcs,int Pposoff,int *Pppos,int *Ppoffs)//~7729R~
{                                                                  //~7712M~
    UCHAR *pdata;                                                  //~7712M~
    int len=MAX_INT_VAL,offs,cnt,rc;                               //~7729R~
//**********************                                           //~7712M~
    pdata=Pputcs->data;                                            //~7713R~
	if (!(Popt & UTCO_BYOFF))                                      //~7729R~
    {                                                              //~7712M~
    	cnt=Pposoff;                                               //~7712M~
        offs=-1;                                                   //~7712M~
    }                                                              //~7712M~
    else                                                           //~7712M~
    {                                                              //~7712M~
    	offs=Pposoff;                                              //~7712M~
    	cnt=-1;            //no cnt limit                          //~7712M~
        if (!Pppos && (Popt & UTCO_NOBYTEOFFS))	//no pos output required//~7712R~
        {                                                          //~7712M~
        	if (Ppoffs)                                            //~7712M~
            	*Ppoffs=Pposoff;                                   //~7712M~
            return 0;                                              //~7712M~
        }                                                          //~7712M~
    }                                                              //~7712M~
	rc=utfstrchkmbr2wc(0,pdata,len,0,cnt,offs,0,0,Pppos,0,Ppoffs); //~7729R~
    return rc;                                                     //~7712M~
}//utfgetposoffmbr2wc                                              //~7712M~
//*******************************************************          //~7712M~
//*chof (re)setup after set data                                   //~7729R~
//**Pplenc:input maxcol when UTCO_MAXCOL                           //~7805I~
//*ret rc                                                          //~7729I~
//*******************************************************          //~7712M~
int utfsetchof(int Popt,                                           //~7729R~
				PUTCHARS Pputc,		//data and chof and lenc       //~7729I~
				int Ppos,           //start column                 //~7729R~
				int Plen,           //lenutf or lenc               //~7729R~
				int *Pplenc,        //setup column                 //~7729R~
				int *Pplenutf)      //chked data lenutf            //~7729R~
{                                                                  //~7712M~
	PCHOFTYPE pchof;                                               //~7712I~
    UCHAR *pdata;                                                  //~7729R~
    int rc,initoffs,width,len,lenr,charcnt,pos,cpos,chklen,maxcol,lenutf;//~7729R~
    int diff,newcnt,oldoffs,newoffs;                               //~7801I~
//**********************************                               //~7712M~
	if (!UTC_ISVALIDCHOF(Pputc))                                   //~7729I~
    	return UTCRC_NOCHOF;                                       //~7729I~
	if (UTC_ISASCII(Pputc))                                        //~7729I~
    	return 0;                                                  //~7729I~
	pdata=Pputc->data;                                             //~7713R~
	pchof=Pputc->chof;                                             //~7713R~
	cpos=Pputc->cpos;                                              //~7729I~
    width=Pputc->lenc;                                             //~7713R~
    pos=Ppos+cpos;                                                 //~7729I~
    if (pos<0||pos>width)                                          //~7729R~
        return UTCRC_OUTR;                                         //~7728R~
    len=Plen;                                                      //~7712I~
    if (width>0)	//once set                                     //~7729R~
    {                                                              //~7712I~
	    initoffs=*(pchof+pos);                                     //~7729M~
	    if (Plen==1 && pos<width && *(pchof+pos+1)==initoffs+1)	//no utf replace//~7729R~
    		return 0;		//for performance (ascii char 1 byte replace case)//~7729R~
	    if (Popt & UTCO_BYLEN)	//parm plen is utflen              //~7729I~
        {                                                          //~7729I~
	    	lenr=*(pchof+width)-initoffs;                          //~7729R~
        	if (len<lenr)                                          //~7729I~
	        	if (!(Popt & UTCO_SETEOS))	//keep previouse string after replaced//~7729I~
    	    		len=lenr;                                      //~7729I~
        }                                                          //~7729I~
        else                                                       //~7729I~
        {                                                          //~7729I~
        	lenr=width-pos;                                        //~7729I~
        	if (len<lenr)                                          //~7729I~
	        	if (!(Popt & UTCO_SETEOS))	//keep previouse string after replaced//~7729I~
    	    		len=lenr;                                      //~7729I~
        }                                                          //~7729I~
    }                                                              //~7712I~
    else                                                           //~7712I~
    {                                                              //~7729I~
        initoffs=0;                                                //~7729R~
    }                                                              //~7729I~
                                                                   //~7729I~
    if (Popt & UTCO_BYLEN)  //parm plen is utflen                  //~7729I~
    {                                                              //~7729I~
        lenutf=len;                                                //~7729I~
    	if (Popt & UTCO_MAXCOL)  //maxcol specified                //~7826R~
	        maxcol=*Pplenc;                                        //~7805I~
        else                                                       //~7805I~
	        maxcol=-1;                                             //~7805R~
    }                                                              //~7729I~
    else                                                           //~7729I~
    {                                                              //~7729I~
        lenutf=MAX_INT_VAL;                                        //~7729R~
        maxcol=len;                                                //~7729I~
    }                                                              //~7729I~
    pchof+=pos;                                                    //~7801I~
	rc=utfsetchofmbr2wc(Popt|UTCO_KEEPRB,   //to get old offset    //~7801R~
						pdata+initoffs,                            //~7801I~
						lenutf, //data utflen                      //~7729R~
						0, /*skipcol*/                             //~7729R~
						maxcol, /*maxcol*/                         //~7729R~
						-1, /*maxlen*/                             //~7729R~
						pchof,                                     //~7801R~
						initoffs,	//initoffs                     //~7729R~
						&charcnt,                                  //~7729R~
                        0,			//out startoffs                //~7729I~
						&chklen);                                  //~7729R~
    if (rc<0)                                                      //~7712I~
    	return rc;                                                 //~7712I~
                                                                   //~7801I~
    oldoffs=*(pchof+charcnt);                                      //~7801I~
    *(pchof+charcnt)=newoffs=initoffs+chklen;                      //~7801I~
    newcnt=pos+charcnt;                                            //~7801I~
    if (newcnt>=Pputc->lenc)                                       //~7801I~
	    Pputc->lenc=newcnt;                                        //~7801I~
    else                                                           //~7801I~
    {                                                              //~7801I~
    	pchof+=charcnt;                                            //~7801I~
        diff=newoffs-oldoffs;                                      //~7801I~
        UTC_CHOFADJUST(pchof,Pputc->lenc-newcnt+1,diff)            //~7801I~
    }                                                              //~7801I~
                                                                   //~7801I~
    if (Pplenc)                                                    //~7729I~
        *Pplenc=charcnt;                                           //~7729I~
    if (Pplenutf)                                                  //~7729I~
    	*Pplenutf=chklen;                                          //~7729R~
    return rc;                                                     //~7712I~
}//utfsetchof                                                      //~7712R~
//*******************************************************          //~7729I~
//*chof setup by external data                                     //~7729I~
//*ret rc                                                          //~7729I~
//*******************************************************          //~7729I~
int utfsetchofD(int Popt,                                          //~7729I~
				PUTCHARS Pputc,		//data and chof and lenc       //~7729I~
				int Ppost,           //start column                //~7729I~
				UCHAR *Psrc,            //optional data source     //~7729R~
				int Pposs,           //optional data source start column//~7729I~
				int Plen,            //lenutf or lenc              //~7729I~
				int *Pplenc,         //setup column                //~7729I~
				int *Ppskiplen,      //utflen correspond to Pposs  //~7729I~
				int *Pplenutf)       //chked data lenutf           //~7729I~
{                                                                  //~7729I~
	PCHOFTYPE pchof;                                               //~7729I~
    int rc,initoffs,width,charcnt,pos,chklen,maxcol,lenutf,skiplen;//~7729R~
    int oldoffs,newoffs,newcnt,diff;                               //~7801R~
//**********************************                               //~7729I~
    if (Pplenc)                                                    //~7827I~
        *Pplenc=Plen;                                              //~7827I~
    if (Pplenutf)                                                  //~7827I~
    	*Pplenutf=Plen;                                            //~7827I~
    if (Ppskiplen)                                                 //~7827I~
    	*Ppskiplen=Pposs;                                          //~7827I~
	if (!UTC_ISVALIDCHOF(Pputc))                                   //~7729I~
    {                                                              //~7824I~
        if (!(Popt & UTCO_ALLOCCHOF))                              //~7824I~
	    	return UTCRC_NOCHOF;                                   //~7824I~
        pchof=(PCHOFTYPE)umalloc((Plen+1)*CHOFSZ);                 //~7824R~
        if (!pchof)                                                //~7824I~
	    	return UTCRC_NOCHOF;                                   //~7824I~
        UTCCHOF(Pputc)=pchof;                                      //~7824I~
        UTCLENC(Pputc)=0;                                          //~7824I~
        UTCCPOS(Pputc)=0;                                          //~7824I~
    }                                                              //~7824I~
    else                                                           //~7824I~
	if (UTC_ISASCII(Pputc))                                        //~7827R~
    {                                                              //~7824I~
        if (!(Popt & UTCO_ALLOCCHOF))                              //~7824I~
	    	return 0;                                              //~7824R~
        pchof=(PCHOFTYPE)umalloc(Plen+1);                          //~7824I~
        if (!pchof)                                                //~7824I~
	    	return UTCRC_NOCHOF;                                   //~7824I~
        UTCCHOF(Pputc)=pchof;                                      //~7824I~
        UTC_CHOFSET(pchof,Plen+1,0)                                //~7824I~
        UTCLENC(Pputc)=Plen;                                       //~7824I~
        UTCCPOS(Pputc)=0;                                          //~7824I~
	    return 0;                                                  //~7824I~
    }                                                              //~7824I~
	if (Popt & UTCO_ASCII)                                         //~7827I~
    {                                                              //~7827I~
        pchof=UTCCHOF(Pputc);                                      //~7827I~
        UTC_CHOFSET(pchof,Plen+1,0)                                //~7827I~
        UTCLENC(Pputc)=Plen;                                       //~7827I~
        UTCCPOS(Pputc)=0;                                          //~7827I~
	    return 0;                                                  //~7827I~
    }                                                              //~7827I~
    pos=Pputc->cpos+Ppost;                                         //~7729R~
    width=Pputc->lenc;                                             //~7729I~
    if (pos<0||pos>width)                                          //~7729I~
        return UTCRC_OUTR;                                         //~7729I~
	pchof=Pputc->chof+pos;                                         //~7729I~
    if (width>0)	//chof already setup                           //~7729I~
		initoffs=*pchof;                                           //~7729I~
    else                                                           //~7729I~
    	initoffs=0;                                                //~7729I~
	if (Popt & UTCO_BYLEN)	//parm plen is utflen                  //~7729I~
    {                                                              //~7729I~
    	lenutf=Plen;                                               //~7729I~
        maxcol=-1;                                                 //~7729I~
    }                                                              //~7729I~
    else                                                           //~7729I~
    {                                                              //~7729I~
    	lenutf=MAX_INT_VAL;                                        //~7729R~
        maxcol=Plen;                                               //~7729I~
    }                                                              //~7729I~
	rc=utfsetchofmbr2wc(Popt|UTCO_KEEPRB,                          //~7801R~
							Psrc,                                  //~7801I~
							lenutf, //data utflen                  //~7729I~
							Pposs, /*skipcol*/                     //~7729I~
							maxcol, /*maxcol*/                     //~7729I~
							-1, /*maxlen*/                         //~7729I~
							pchof,                                 //~7729I~
							initoffs,	//initoffs                 //~7729I~
							&charcnt,                              //~7729I~
							&skiplen,                              //~7729I~
							&chklen);                              //~7729I~
    if (rc<0)                                                      //~7729I~
    	return rc;                                                 //~7729I~
    oldoffs=*(pchof+charcnt);                                      //~7801I~
    *(pchof+charcnt)=newoffs=initoffs+chklen;                      //~7801I~
    newcnt=pos+charcnt;                                            //~7801I~
    if (newcnt>=Pputc->lenc)                                       //~7801I~
	    Pputc->lenc=newcnt;                                        //~7801I~
    else                                                           //~7801I~
    {                                                              //~7801I~
    	pchof+=charcnt;                                            //~7801I~
        diff=newoffs-oldoffs;                                      //~7801I~
        UTC_CHOFADJUST(pchof,Pputc->lenc-newcnt+1,diff)            //~7801I~
    }                                                              //~7801I~
    if (Pplenc)                                                    //~7729I~
        *Pplenc=charcnt;                                           //~7729I~
    if (Pplenutf)                                                  //~7729I~
    	*Pplenutf=chklen;                                          //~7729R~
    if (Ppskiplen)                                                 //~7729I~
    	*Ppskiplen=skiplen;                                        //~7729I~
    return rc;                                                     //~7729I~
}//utfsetchofD                                                     //~7729I~
//*******************************************************          //~7712M~
//*setup chof                                                      //~7729R~
//*******************************************************          //~7712M~
int utfsetchofmbr2wc(int Popt,                                     //~7729R~
                    UCHAR *Pdata,          //data addr             //~7729I~
                    int Plenutf,           //data length           //~7729I~
                    int Pstartpos,         //skip column           //~7729I~
                    int Pmaxcol,           //right boundary column from Pstartpos(-1:no limit)//~7729I~
                    int Pmaxlenutf,        //right boundary by length from Pstartpos(-1:no limit)//~7729I~
                    PCHOFTYPE Ppchof,      //output:chof top(0 if no chof set)//~7729I~
                    int Pinitoffs,         //offsetvalue for top of Pchof//~7729I~
                    int *Ppcharcnt,        //output:charcnt        //~7729I~
                    int *Ppstartoffs,      //output:offset corresponding to Pstartpos//~7729I~
                    int *Pplenutf)         //output:chked data length after Pstartoffs//~7729I~
{                                                                  //~7712M~
	int rc,newcnt,newlen,skiplen;                                  //~7729R~
//***************                                                  //~7712M~
UTRACEP("utfsetchofmb2wc Pdata=%p,datalen=%d,startpos=%d,maxcol=%d,maxlen=%d,chof=%p,initoffs=%d\n",Pdata,Plenutf,Pstartpos,Pmaxcol,Pmaxlenutf,Ppchof,Pinitoffs);//~7730R~
//UTRACED("utfsetchofmb2wc Pdata",Pdata,Plenutf);                  //~7730R~
	rc=utfstrchkmbr2wc(Popt,Pdata,Plenutf,Pstartpos,Pmaxcol,Pmaxlenutf,Ppchof,Pinitoffs,&newcnt,&skiplen,&newlen);         //output:chked data length//~7730R~
    if (Ppcharcnt)                                                 //~7729R~
    	*Ppcharcnt=newcnt;                                         //~7729R~
    if (Pplenutf)                                                  //~7729I~
    	*Pplenutf=newlen;                                          //~7729I~
    if (Ppstartoffs)                                               //~7729I~
    	*Ppstartoffs=skiplen;                                      //~7729R~
UTRACEP("utfsetchofmbr2wc rc=%d,newcnt=%d,skiplen=%d,newlen=%d\n",rc,newcnt,skiplen,newlen);//~7730R~
UTRACED("utfsetchofmbr2wc Pchof",Ppchof,newcnt);                   //~7730R~
    return rc;                                                     //~7712M~
}//utfsetchofmbr2wc                                                //~7729R~
#endif //UTF8SUPP                                                  //~v5ncI~
#ifdef WCSUPP                                                      //~v5ncI~
//*******************************************************          //~7729I~
//*utf strchk by mbrtowc                                           //~7729I~
//* assign 1 column for each for invalid/inmatured utf char        //~7729I~
//* rc:errutf/dbcssplit                                            //~7729I~
//*******************************************************          //~7729I~
int utfstrchkmbr2wc(int Popt,                                      //~7729I~
                    UCHAR *Pdata,          //data addr             //~7729I~
                    int Plenutf,           //data length           //~7729I~
                    int Pstartpos,         //skip column           //~7729I~
                    int Pmaxcol,           //right boundary column from Pstartpos(-1:no limit)//~7729I~
                    int Pmaxlenutf,        //right boundary by length from Pstartpos(-1:no limit)//~7729I~
                    PCHOFTYPE Ppchof,      //output:chof top(0 if no chof set)//~7729R~
                    int Pinitoffs,         //offsetvalue for top of Pchof//~7729I~
                    int *Ppcharcnt,        //output:charcnt        //~7729R~
                    int *Ppstartoffs,      //output:offset corresponding to Pstartpos//~7729R~
                    int *Pplenutf)         //output:chked data length after Pstartoffs//~7729I~
{                                                                  //~7729I~
    ULONG ucs;                                                     //~7729I~
    UCHAR *pdata;                                                  //~7729I~
    int offs0=0,offs,rc=0,rescnt,newcnt,charwidth,reslen,chklen;   //~7729R~
    int swstrz,swerrutfrc,reslenlimit;                             //~7731R~
    PCHOFTYPE pchof;                                               //~7729I~
//***************                                                  //~7729I~
UTRACED("utfstrchkbymbrtowcsub --> Pdata",Pdata,Plenutf);          //~7731R~
    swstrz=Popt & UTCO_STRZ;                                       //~7729I~
    swerrutfrc=Popt & UTCO_SETERRUTFRC;                            //~7729I~
    rescnt=MAX_INT_VAL;                                            //~7729R~
    reslenlimit=MAX_INT_VAL;	//chked after startpos             //~7731R~
                                                                   //~7729I~
	for (pdata=Pdata,reslen=Plenutf,newcnt=0,offs=0,pchof=Ppchof   //~7729R~
         ;reslen>0                                                 //~7731R~
		 ;reslen-=chklen,reslenlimit-=chklen,rescnt-=charwidth,    //~7731R~
          pdata+=chklen,offs+=chklen,newcnt+=charwidth)            //~7729I~
    {                                                              //~7729I~
        if (newcnt==Pstartpos)                                     //~7729I~
        {                                                          //~7729I~
		    if (Pmaxcol>=0)                                        //~7729I~
    			rescnt=Pmaxcol;                                    //~7729I~
		    if (Pmaxlenutf>=0)                                     //~7729I~
    			reslenlimit=Pmaxlenutf;                            //~7731R~
            offs0=offs;                                            //~7729I~
            offs=0;                                                //~7729I~
        }                                                          //~7729I~
        if (rescnt<=0 || reslenlimit<=0)                           //~7731I~
        	break;                                                 //~7731I~
    	if (swstrz && !*pdata)                                     //~7729M~
        	break;                                                 //~7729M~
		chklen=min(reslen,reslenlimit);                            //~7731R~
//UTRACEP("setdbcstbl_utf reslen=%d,availlen=%d,chklen=%d\n",reslen,availlen,chklen);//~7729I~
        if (Popt & UTCO_ASCII 	//data is all ascii                //~7801I~
		||  !UTF8_ISTOPBYTE(*pdata))                               //~7801R~
        {                                                          //~7729I~
            chklen=1;                                              //~7729I~
            charwidth=1;                                           //~7729I~
        }                                                          //~7729I~
        else                                                       //~7729I~
#ifdef UTF8SUPPH                                                   //~v62UR~
      	if (utfmb2wc(Popt,pdata,chklen,&ucs,&chklen,&charwidth))   //~v62UR~
#else                                                              //~v62UR~
      	if (utfmb2wc(0,pdata,chklen,&ucs,&chklen,&charwidth))      //~7924R~
#endif                                                             //~v62UR~
        {                                                          //~7729I~
            if (swerrutfrc)                                        //~7729I~
	            rc|=UTCRC_ERRUTFCHAR;                              //~7729I~
            chklen=1;                                              //~7729I~
            charwidth=1;                                           //~7729I~
        }                                                          //~7729I~
        else                                                       //~7729I~
        {                                                          //~7729I~
        	if (!charwidth)                                        //~v60pI~
            {                                                      //~v60pI~
            	charwidth=1;	//occupy 1 column on pchof         //~v60pI~
            }                                                      //~v60pI~
            else                                                   //~v60pI~
            if (charwidth==2)                                      //~7729I~
            {                                                      //~v62UR~
				if (rescnt==1                                      //~7729I~
            	||  newcnt+1==Pstartpos)                           //~7729R~
                {                                                  //~7729I~
                    if (swerrutfrc)                                //~7729I~
                        rc|=UTCRC_DBCSSPLIT;  //count overflow     //~7729I~
                	if (Popt & UTCO_DBCSBACK                       //~7805I~
//		            &&  newcnt+1==Pstartpos) 	//right boundary dbcs split//~v5nfR~
  		            &&  !(newcnt+1==Pstartpos)) 	//right boundary dbcs split//~v5nfR~
						break;                                     //~7805I~
                    charwidth=1;                                   //~7729I~
                    chklen=1;                                      //~7729I~
                }                                                  //~7729I~
            }//dbcs                                                //~v62UR~
#ifdef UTF8SUPPH                                                   //~v62UR~
            else                                                   //~v62UR~
            if (charwidth>UDBCSCHK_DBCSSZ) //dbcs 3,4 byte         //~v62UR~
            {                                                      //~v62UR~
				if (rescnt<charwidth       //cut before dbcs split //~v62UR~
            	||  (newcnt<Pstartpos && newcnt+charwidth>Pstartpos))//~v62UR~
                {                                                  //~v62UR~
                    if (swerrutfrc)                                //~v62UR~
                        rc|=UTCRC_DBCSSPLIT;  //count overflow     //~v62UR~
                	if (Popt & UTCO_DBCSBACK                       //~v62UR~
  		            &&  !(newcnt<Pstartpos && newcnt+charwidth>Pstartpos))//~v62UR~
						break;                                     //~v62UR~
                    charwidth=1;                                   //~v62UR~
                    chklen=1;                                      //~v62UR~
                }                                                  //~v62UR~
            }//dbcs                                                //~v62UR~
#endif                                                             //~v62UR~
        }                                                          //~7729I~
        if (Ppchof)	//output required                              //~7729R~
        {                                                          //~7820I~
//          *pchof++=offs+Pinitoffs;                               //~7729R~//~v6BiR~
            *pchof++=(CHOFTYPE)(offs+Pinitoffs);                   //~v6BiI~
            if (charwidth==2)                                      //~7820I~
//          	*pchof++=offs+chklen-1+Pinitoffs;                  //~7820I~//~v6BiR~
            	*pchof++=(CHOFTYPE)(offs+chklen-1+Pinitoffs);      //~v6BiI~
        }                                                          //~7820I~
    }                                                              //~7729I~
    if (Ppchof)	//output required                                  //~7729R~
        if (!(Popt & UTCO_KEEPRB))	//not keep right boundary      //~7801I~
//          *pchof++=offs+Pinitoffs;                               //~7801R~//~v6BiR~
            *pchof++=(CHOFTYPE)(offs+Pinitoffs);                   //~v6BiI~
    if (Ppcharcnt)                                                 //~7729I~
    	*Ppcharcnt=newcnt;                                         //~7729R~
    if (Ppstartoffs)                                               //~7729I~
    	*Ppstartoffs=offs0;                                        //~7729I~
    if (Pplenutf)                                                  //~7729M~
    	*Pplenutf=offs;                                            //~7729M~
UTRACEP("utfstrchkmbr2wc rc=%d,newcnt=%d,startoffs=%d,chklen=%d\n",rc,newcnt,offs0,offs);//~7729R~
    return rc;                                                     //~7729I~
}//utfstrchkmbr2wc                                                 //~7729I~
//*******************************************************          //~v60aI~
//*convert utf8string to ucs string                                //~v60aI~
//*pdbcs:char width tbl                                            //~v60aI~
//*replace invalid utf char by "."                                 //~v60aI~
//*******************************************************          //~v60aI~
//int utfcvf2u(int Popt,USHORT *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Ppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth)//~v61bR~//~v692R~
//int utfcvf2u(int Popt,WUCS *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Ppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth)//~v692I~//~v6BjR~
int utfcvf2u(int Popt,UWUCS *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Ppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth)//~v6BjI~
{                                                                  //~v60aI~
    ULONG ucs;                                                     //~v60aI~
    int rc2,chklen,charwidth,rc=0,width=0,ucscnt,reslen,errretsw,readlen;//~v618R~
//  USHORT *puc,wkpuc[4];                                          //~v60dR~//~v692R~
//  WUCS *puc,wkpuc[4];                                            //~v692I~//~v6BjR~
    UWUCS *puc,wkpuc[4];                                           //~v6BjI~
    UCHAR *pc,*pce,repch='.',*pdbcs;                               //~v60aR~
    PCHOFTYPE pchof;                                               //~v618I~
    int offs;                                                      //~v61bR~
    int dbcsid;                                                    //~v61aI~
    int opt;                                                       //~v6b5I~
//****************************                                     //~v60aI~
	offs=Pinitoffs;                                                //~v61bI~
    puc=Ppoutc;                                                    //~v60aI~
    if (!puc)                                                      //~v60dI~
    	puc=wkpuc;                                                 //~v60dI~
    pc=Ppdata;                                                     //~v60aI~
    pce=Ppdata+Putflen;                                            //~v60aI~
	errretsw=(Popt & UTFCVO_ERRRET);                               //~v61bR~
    pchof=Ppchof;                                                  //~v618I~
    for (ucscnt=0,pdbcs=Ppdbcs;pc<pce;pc+=chklen,ucscnt++,puc++)   //~v60aR~
    {                                                              //~v60aI~
//      reslen=(ULONG)pce-(ULONG)pc;                               //~v60aI~//~v6hhR~
//      reslen=(ULPTR)pce-(ULPTR)pc;                               //~v6hhI~//~v6BkR~
        reslen=PTRDIFF(pce,pc);                                    //~v6BkI~
		if ((Popt & UTFCVO_ASCIIRET)  //allow last char cut by length//~v61bR~
        &&  UTF8ISASCII(*pc)                                       //~v618I~
           )                                                       //~v618I~
        {                                                          //~v618I~
            rc|=UTFF2U_ASCII;                                      //~v618I~
            break;                                                 //~v618I~
        }                                                          //~v618I~
        dbcsid=UDBCSCHK_SBCS;                                      //~v61aI~
//      if (!pc)                                                   //~v618R~
        if (!*pc)                                                  //~v618I~
        {                                                          //~v60aI~
//          *puc=repch;   //required to clear(override) prev image //~v60aI~//~v6BjR~
            *puc=(UWUCS)repch;   //required to clear(override) prev image//~v6BjI~
            charwidth=1;                                           //~v60aI~
            chklen=1;                                              //~v60aI~
            rc2=UTFF2U_ERRS|UTFF2U_ERRRC;                          //~v60dR~
            dbcsid=UDBCSCHK_HKDBCSERR;                             //~v61aI~
        }                                                          //~v60aI~
        else                                                       //~v60aI~
        {                                                          //~v60aI~
            opt=UTCO_NOCHKLOCALE;                                  //~v6b5R~
//          if (utfmb2wc(0,pc,reslen,&ucs,&chklen,&charwidth))     //~v60aI~//~v6b5R~
            if (utfmb2wc(opt,pc,reslen,&ucs,&chklen,&charwidth))   //~v6b5I~
            {                                                      //~v60aI~
				if (Popt & UTFCVO_EOLSPLITOK)  //allow last char cut by length//~v61bR~
                	if (reslen<UTF8CHARLEN(*pc))                   //~v60rI~
                    	break;                                     //~v60rI~
//  	        *puc=repch;                                        //~v60aI~//~v6BjR~
    	        *puc=(UWUCS)repch;                                 //~v6BjI~
                charwidth=1;                                       //~v60aI~
              if (chklen<=0)//advance utf8 char readlen even when charwidth<=0//~v6s0I~
                chklen=1;                                          //~v60aI~
	            rc2=UTFF2U_ERRU|UTFF2U_ERRRC;                      //~v60dR~
	            dbcsid=UDBCSCHK_HKDBCSERR;                         //~v61aI~
            }                                                      //~v60aI~
            else                                                   //~v60aI~
            {                                                      //~v60aI~
                if (charwidth<0)       //utfmb2wc return 1 if wcwidth<0//~v60pR~
                {                                                  //~v60aI~
	            	rc2=UTFF2U_ERRP|UTFF2U_ERRRC;                  //~v60dR~
                    charwidth=1;                                   //~v60pI~
		            dbcsid=UDBCSCHK_HKDBCSERR;                     //~v61aI~
                }                                                  //~v60aI~
                else                                               //~v60aI~
                if (charwidth==0)       //ignore nonspacing char   //~v60aR~
                {                                                  //~v60aI~
	            	rc2=UTFF2U_ERR0;                               //~v60aI~
                    charwidth=1;                                   //~v60pI~
		            dbcsid=UDBCSCHK_NONSPACE;                      //~v61aI~
                }                                                  //~v60aI~
                else                                               //~v60aI~
//              if (charwidth==2)       //ignore nonspacing char   //~v62UR~
                if (charwidth>1)       //mutibyte                  //~v62UR~
                {                                                  //~v61aI~
	            	rc2=UTFF2U_DBCS;                               //~v60aI~
		            dbcsid=UDBCSCHK_DBCS1ST;                       //~v61aI~
                }                                                  //~v61aI~
                else                                               //~v60aI~
	            	rc2=UTFF2U_SBCS;                               //~v60aI~
//              *puc=(USHORT)ucs;                                  //~v60aI~//~v692R~
//              *puc=(WUCS)ucs;                                    //~v692I~//~v6BjR~
                *puc=(UWUCS)ucs;                                   //~v6BjI~
            }                                                      //~v60aI~
        }                                                          //~v60aI~
        width+=charwidth;                                          //~v60aI~
        if (Ppdbcs)                                                //~v60aI~
        {                                                          //~v61aI~
//      	*pdbcs++=(UCHAR)rc2;                                   //~v61aR~
        	*pdbcs++=(UCHAR)dbcsid;                                //~v61aI~
//          if (charwidth==2)                                      //~v62UR~
            if (charwidth>1)                                       //~v62UR~
            {                                                      //~v62UR~
                UDBCSCHK_DBCSPAD_SETADVANCE(pdbcs,charwidth);      //~v62UR~
            	*pdbcs++=UDBCSCHK_DBCS2ND;                         //~v61aI~
            }                                                      //~v62UR~
        }                                                          //~v61aI~
        if (Ppchof)	//pchof output requested                       //~v618I~
        {                                                          //~v618I~
//      	*pchof++=offs;                                         //~v618I~//~v6BiR~
        	*pchof++=(CHOFTYPE)offs;                               //~v6BiI~
//          if (charwidth==2)       //ignore nonspacing char       //~v62UR~
            if (charwidth>1)       //ignore nonspacing char        //~v62UR~
//          	*pchof++=(offs+chklen-1);                          //~v618I~//~v6BiR~
            	*pchof++=(CHOFTYPE)(offs+chklen-1);                //~v6BiI~
            offs+=chklen;                                          //~v618I~
        }                                                          //~v618I~
        rc|=rc2;                                                   //~v60aR~
        if (!Ppoutc)	//no output requested(chk only)            //~v60dR~
        	puc--;                                                 //~v60dI~
        if (errretsw && (rc & UTFF2U_ERRRC))	//errchk only      //~v60dI~
        	break;                                                 //~v60dI~
    }                                                              //~v60aI~
    if (Ppchof)	//pchof output requested                           //~v618I~
//      *pchof++=offs;                                             //~v618I~//~v6BiR~
        *pchof++=(CHOFTYPE)offs;                                   //~v6BiI~
    if (Ppucscnt)                                                  //~v60aI~
	    *Ppucscnt=ucscnt;                                          //~v60aI~
//  readlen=(int)((ULONG)pc-(ULONG)Ppdata);                        //~v618I~//~v6hhR~
    readlen=(int)((ULPTR)pc-(ULPTR)Ppdata);                        //~v6hhI~
    if (Ppreadlen)                                                 //~v618I~
	    *Ppreadlen=readlen;                                        //~v618I~
    if (Ppwidth)                                                   //~v60aI~
	    *Ppwidth=width;                                            //~v60aI~
    return rc;                                                     //~v60aI~
}//utfcvf2u                                                        //~v60aI~
#ifdef UTF8SUPPH                                                   //~v62tI~
//*************************************************************    //~v62tI~
//*evaluate utf8 if l2f failed                                     //~v62tI~
//*called from xeutf_getmixedstr but it is old logic and discarded //~v6t3I~
//*************************************************************    //~v62tI~
int utfcvl2fmix(int Popt,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v62tI~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v62tI~
{                                                                  //~v62tI~
	int rc,rc2,srchutf8sw,chklen,chklen2,reslen,outlen,outlen2=0;  //~v62tR~
    int utf8chsz;                                                  //~v62tR~
    char *pci,*utf8pc=0,*utf8pce,*pcerr,*pcerrchk;                 //~v62tR~
    char wkutf8[UTF8_MAXCHARSZMAX+1];                              //~v62tI~
//**********************                                           //~v62tI~
	rc=utfcvl2f(Popt,Poututf8,Pinp,Pinitoffs,Pinplen,              //~v62tI~
			Pchof,Pdbcs,&chklen,&outlen,Ppcharcnt,Ppcharwidth);    //~v62tI~
UTRACEP("utfcvl2fmix l2f rc=%d,chklen=%d,outlen=%d\n",rc,chklen,outlen);//~v62tR~
	srchutf8sw=(Popt & UTFCVO_UTF8RET) && (rc==UTFCVRC_ERRSTOP);   //~v62tR~
    if (srchutf8sw)                                                //~v62tI~
    {                                                              //~v62tI~
        pcerr=Pinp+chklen;                                         //~v62tI~
        pcerrchk=pcerr;                                            //~v62tI~
    	if (Popt & UTFCVO_ASCIIRET)  //return by ascii              //~v62vI~//~v62tR~
        	if (chklen+1==Pinplen//err by last 1 byte;it is not ascii//~v62tI~
            ||  *(pcerr+1)<'0'    //dbcs 2nd byte is >"0"(4byte dbcs,>" " for 2byte dbcs)//~v62tR~
            )                                                      //~v62tI~
                pcerrchk-=2;           //2 byte dbcs before error may part of utf8//~v62vI~//~v62tR~
        for (pci=Pinp,reslen=Pinplen;pci<pcerr;pci+=chklen2,reslen-=chklen2)//~v62tR~
        {                                                          //~v62tI~
            if (UTF8ISASCII(*pci)) //mey not occur if ASCIIRET     //~v62tI~
            {                                                      //~v62tI~
                chklen2=1;                                         //~v62tI~
                continue;                                          //~v62tI~
            }                                                      //~v62tI~
            if (utfcvf2l1(0,pci,reslen,&utf8chsz))  //valid utf8 corresponding to a locale code//~v62tR~
            {                                                      //~v62tI~
                utf8pc=pci;                                        //~v62tI~
                utf8pce=pci+utf8chsz;                              //~v62tI~
UTRACEP("utfcvl2fmix f2l1 utf8chsz=%d,pci=%p,pce=%p,pcerrchk=%p\n",utf8chsz,pci,utf8pce,pcerrchk);//~v62tR~
                if (utf8pce>pcerrchk)  //last valid utf8           //~v62tR~
                {                                                  //~v62tI~
                    rc=UTFCVRC_UTF8RET;                            //~v62tI~
                    break;                                         //~v62tI~
                }                                                  //~v62tI~
            }                                                      //~v62tI~
//          chklen2=udbcschk_getmblen(0,pci);                      //~v62UR~
            udbcschk_getmblen(0,pci,reslen,&chklen2);              //~v62UR~
            if (chklen2>reslen)                                    //~v62tI~
                break;      //err                                  //~v62tI~
            rc2=utfcvl2f(Popt,wkutf8,pci,0/*Pinitoffs*/,chklen2,   //~v62tR~
                        0/*Pchof*/,0/*Pdbcs*/,&chklen2,&utf8chsz,0/*Ppcharcnt*/,0/*Ppcharwidth*/);//~v62tR~
UTRACEP("utfcvl2fmix l2f rc2=%d,chklen=%d\n",rc2,chklen2);         //~v62tI~
            if (rc2>=UTFCVRC_ERR)                                  //~v62tR~
                break;                                             //~v62tI~
            outlen2+=utf8chsz;                                     //~v62tR~
        }                                                          //~v62tI~
        if (rc==UTFCVRC_UTF8RET)                                   //~v62tI~
        {                                                          //~v62tI~
        	outlen=outlen2;                                        //~v62tI~
//          chklen=(int)((ULONG)utf8pc-(ULONG)Pinp);               //~v62tI~//~v6hhR~
            chklen=(int)((ULPTR)utf8pc-(ULPTR)Pinp);               //~v6hhI~
        }                                                          //~v62tI~
    }                                                              //~v62tI~
    if (Ppchklen)                                                  //~v62tI~
    	*Ppchklen=chklen;                                          //~v62tI~
    if (Ppoutlen)                                                  //~v62tI~
    	*Ppoutlen=outlen;                                          //~v62tR~
UTRACEP("utfcvl2fmix return rc=%d,chklen=%d,outlen=%d\n",rc,chklen,outlen);//~v62tR~
UTRACED("utfcvl2fmix inp",Pinp,Pinplen);                           //~v62tI~
UTRACED("utfcvl2fmix out",Poututf8,outlen);                        //~v62tI~
    return rc;                                                     //~v62tI~
}//utfcvl2fmix                                                     //~v62tI~
#endif                                                             //~v62tI~
//*************************************************************    //~v60dM~
//*string conversion locale to utf8                                //~v60dM~
//*rc:8:stop at invalid input char,4:err char detected,1:all ascii //~v616R~
//*************************************************************    //~v60dM~
int utfcvl2f(int Popt,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v61bR~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v61bI~
{                                                                  //~v60dM~
	int charcnt=0,chklen,rc=0,reslen,len;                          //~v61bR~
    int asciisw=1,readlen,offs,tcharwidth,outlen;                  //~v61bR~
//  wchar_t ucs;                                                   //~v60dR~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
    UWUCS   ucs;                                                   //~v6BjI~
    char *pc,*pco,repch,dbcschksw;                                 //~v61bR~
    int dbcscnt=0;                                                 //~v612R~
    PCHOFTYPE pchof;                                               //~v61bI~
    char *pdbcs;                                                   //~v61bI~
//#ifdef UTF8SUPPH                                                 //~v620R~
//    int opt;                                                     //~v620R~
//#endif                                                           //~v620R~
#ifdef UTF8SUPPH                                                   //~v620I~
#ifdef LNX                                                         //~v61bI~
    int udbcschkrc;                                                //~v61bI~
    ULONG ulucs;                                                   //~v5ncI~
    int mblen;                                                     //~v6hnI~
#else                                                              //~v620I~
//  USHORT usucs;                                                  //~v620R~
#endif                                                             //~v61bI~
#endif                                                             //~v620I~
	int outbuffsz=0;                                                  //~v6hGI~
    char *pcoe,wkutf8[UTF8_MAXCHARSZMAX];                          //~v6hGI~
#ifdef W32                                                         //~v6uBI~
    int rc2;                                                       //~v6unI~
#endif                                                             //~v6uBI~
#ifdef W32UNICODE                                                  //~v6uBI~
    int opt;                                                       //~v6unI~
#endif                                                             //~v6uBI~
//**********************                                           //~v60dM~
UTRACEP("%s: opt=%x\n",UTT,Popt);                                  //~v6x5I~
UTRACED("utfl2f inp",Pinp,Pinplen);                                //~v60dI~//~v6x5M~
#ifdef LNX                                                         //~v616I~
// #ifdef AAA //force use iconv                                      //~v62QI~//~v6f3R~
//  #ifdef UTF8SUPPH                                                 //~v620I~//~v6f3R~
//    if (UDBCSCHK_ISDBCSJ())     //Japanese(EUC and EUC+UTF8)       //~v620I~//~v6f3R~
//  #else                                                            //~v620I~//~v6f3R~
//    if (UDBCSCHK_ISUTF8J())                                        //~v616I~//~v6f3R~
//  #endif                                                           //~v620I~//~v6f3R~
//        return utfcve2f(Popt,Poututf8,Pinp,Pinitoffs,Pinplen,      //~v61bR~//~v6f3R~
//                    Pchof,Pdbcs,Ppchklen,Ppoutlen,Ppcharcnt,Ppcharwidth);//~v61bI~//~v6f3R~
//    else                                                           //~v61bI~//~v6f3R~
// #endif                                                            //~v62QI~//~v6f3R~
//      if (Gulibutfmode & GULIBUTFENV)                            //~v61gR~
      if (!UDBCSCHK_IS_LOCALICU())                                 //~v6f3I~
        if (UTF8MODEICONV())                                       //~v61gI~
        {                                                          //~v61bI~
			rc=utfcvl2fany(Popt,0/*localecode:usepreviously set*/,Poututf8,Pinp,Pinitoffs,Pinplen,//~v61bR~
			                    Pchof,Pdbcs,Ppchklen,Ppoutlen,Ppcharcnt,Ppcharwidth);//~v61bR~
//          if (rc<UTFCVRC_SEVERR)                                 //~v61bI~//~v620R~
//          	return rc;                                         //~v61bI~//~v620R~
//          rc=0;	//continue by mbrtowc                          //~v61bI~//~v620R~
            return rc;                                             //~v620I~
        }                                                          //~v61bI~
#endif                                                             //~v616I~
	if (Popt & UTFCVO_BUFFSZPARM) //outbuff size parm specified    //~v6hGI~
    	outbuffsz=*Ppoutlen;                                       //~v6hGR~
    pcoe=Poututf8+outbuffsz;                                       //~v6hGR~
//  repch=(Popt & UTFCVO_REPCH)>>8;                                //~v61bR~//~v6BkR~
    repch=(char)((Popt & UTFCVO_REPCH)>>8);                        //~v6BkI~
	offs=Pinitoffs;                                                //~v61bI~
    pdbcs=Pdbcs;                                                   //~v61bI~
    pchof=Pchof;                                                   //~v61bI~
    dbcschksw=(Ppcharwidth||Pchof||Pdbcs);	//requested            //~v61bI~
	for (reslen=Pinplen,pc=Pinp,pco=Poututf8;reslen>0;reslen-=chklen,pc+=chklen,charcnt++)//~v60dM~
    {                                                              //~v60dM~
      	if (*pc<128)                                               //~v60rI~
      	{                                                          //~v60rI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v61bR~
            {	                                                   //~v618I~
    			rc|=UTFCVRC_ASCIIRET;                              //~v61bR~
            	break;                                             //~v618I~
            }                                                      //~v618I~
            if (outbuffsz && pco>=pcoe)                            //~v6hGI~
            {	                                                   //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                       //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
        	chklen=1;                                              //~v60rI~
            *pco++=*pc;                                            //~v60rI~
            if (Pchof)                                             //~v61bI~
//              *pchof++=offs;                                     //~v61bI~//~v6BiR~
                *pchof++=(CHOFTYPE)offs;                           //~v6BiI~
            if (Pdbcs)                                             //~v61bI~
	            *pdbcs++=UDBCSCHK_SBCS;                            //~v61bI~
            offs++;                                                //~v61bI~
            continue;                                              //~v60rI~
      	}                                                          //~v60rI~
        asciisw=0;                                                 //~v60rI~
//#ifdef UTF8SUPPH                                                 //~v620R~
//        chklen=udbcschk_getmblen(0,pc);                          //~v620R~
//        chklen=min(chklen,reslen);                               //~v620R~
//        opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v620R~
//        if (ucvext_iconvlocal2ucs1(opt,(ULONG)Spconverters,pc,chklen,0/*chklen output*/,&usucs))//~v620R~
//            chklen=-1;                                           //~v620R~
//        ucs=(wchar_t)usucs;                                      //~v620R~
//#else                                                            //~v620R~
#ifdef W32                                                         //~v61bR~
#ifdef UTF8SUPPH                                                   //~v62hI~
//  	chklen=umbtowc(&ucs,pc,reslen);                            //~v62hI~//~v62xR~
//  	chklen=utfcvl2uany1mb(0,pc,reslen,&ucs);                //~v62xR~//~v62ER~//~v6unR~
		opt=0;                                                     //~v6unI~
#ifdef W32UNICODE                                                  //~v6unI~
        opt=Popt;	//ALLOWSUBCH                                   //~v6unI~
#endif                                                             //~v6unI~
    	chklen=utfcvl2uany1mb(opt,pc,reslen,&ucs,&rc2);            //~v6unR~
#else                                                              //~v62hI~
    	chklen=mbtowc(&ucs,pc,reslen);                             //~v60dM~
#endif                                                             //~v62hI~
        if (!chklen) //input is null                               //~v60dM~
        {                                                          //~v60dM~
        	if (Popt & UTFCVO_STRZ)                                //~v61bR~
            	break;                                             //~v60dM~
            if (outbuffsz && pco>=pcoe)                            //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
            chklen=1;                                              //~v60dM~
            *pco++=0;                                              //~v60dM~
        }                                                          //~v60dM~
#ifndef UTF8SUPPH	//utfcvl2uany do reverse chk                   //~v62UR~
        else                                                       //~v60dM~
        if (chklen>0)                                              //~v61bI~
        {                                                          //~v61bI~
            if (dbcschksw)	//requested                            //~v61bI~
            {                                                      //~v61bI~
//          	if (utfwcwidth(ucs)<=0)                            //~v61bR~//+v70gR~
            	if (utfwcwidth(ucs)<0)                             //+v70gI~
            		chklen=-1;	//err                              //~v61bI~
            }                                                      //~v61bI~
        }                                                          //~v61bI~
#endif                                                             //~v62UR~
#else                                                              //~v61bM~
//  	chklen=mbrtowc(&ucs,pc,reslen,NULL);                       //~v61bI~
        if (!pc && (Popt & UTFCVO_STRZ))                           //~v61bI~
            break;                                                 //~v61bI~
//  	udbcschkrc=udbcschk_locale1(pc,reslen,0/*readlen*/,&ucs);  //~v5ncR~
//    	udbcschkrc=udbcschk_locale1(pc,reslen,&chklen,&ulucs);     //~v66nR~
//    	udbcschkrc=udbcschk_locale1(0,pc,reslen,&chklen,&ulucs);   //~v6hnR~
    	udbcschk_getmblen(0,pc,reslen,&mblen);                     //~v6hnR~
		mblen=min(mblen,reslen);                                   //~v6hnI~
      	udbcschkrc=udbcschk_locale1(0,pc,mblen,&chklen,&ulucs);    //~v6hnI~
//      ucs=(wchar_t)ulucs;                                        //~v5ncI~//~v6a0R~
//      ucs=(UWCHART)ulucs;                                        //~v6a0I~//~v6BjR~
        ucs=(UWUCS)ulucs;                                          //~v6BjI~
        if (udbcschkrc==UDBCSCHK_DBCS1ST)                          //~v61bI~
//      	chklen=2;                                              //~v62UR~
        	;                                                      //~v62UR~
        else                                                       //~v61bI~
        if (udbcschkrc==UDBCSCHK_SBCS)                             //~v61bI~
        	chklen=1;                                              //~v61bI~
        else                                                       //~v70gI~
        if (udbcschkrc==UDBCSCHK_NONSPACE)    //'0'                //~v70gI~
        {                                                          //~v70gI~
			if (Popt & UTFCVO_WIDTH0RC)                            //~v70gI~
	            rc|=UTFCVRC_WIDTH0;	//keep chklen of udbcschk_locale1//~v70gI~
        }                                                          //~v70gI~
        else                                                       //~v61bI~
        	chklen=-1;	//set err                                  //~v61bI~
#endif                                                             //~v61bM~
//#endif  //UTF8SUPPH                                              //~v620R~
        if (chklen<0) //conversion failed                          //~v60dM~//~v6VjR~
        {                                                          //~v60dM~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v61bR~
            {                                                      //~v60dM~
            	rc=UTFCVRC_ERRSTOP;     //8                        //~v61bR~
            	break;                                             //~v60dM~
            }                                                      //~v60dM~
            if (outbuffsz && pco>=pcoe)                            //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
        	if (Popt & UTFCVO_ERRREP)  //replace err               //~v61bR~
	            *pco++=repch;                                      //~v60dM~
            else                                                   //~v60dM~
	            *pco++=*pc;                                        //~v60dM~
            rc|=UTFCVRC_ERR;         //4                           //~v61bR~
            chklen=1;                                              //~v60dM~
            if (Pchof)                                             //~v61bI~
//              *pchof++=offs;                                     //~v61bI~//~v6BiR~
                *pchof++=(CHOFTYPE)offs;                           //~v6BiI~
            if (Pdbcs)                                             //~v61bI~
	            *pdbcs++=UDBCSCHK_HKDBCSERR;                       //~v61bI~
            offs++;                                                //~v61bI~
        }                                                          //~v60dM~
        else                                                       //~v60dM~
        {                                                          //~v60dM~
//        	len=uccvucs2utf((ULONG)ucs,pco);                       //~v6hGR~
//        	len=uccvucs2utf((ULONG)ucs,wkutf8);                    //~v6hGI~//~v6BkR~
          	len=uccvucs2utf((UWUCS)ucs,wkutf8);                    //~v6BkI~
            if (outbuffsz && pco+len>pcoe)                         //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
//          memcpy(pco,wkutf8,len);                                //~v6hGR~//~v6BkR~
            memcpy(pco,wkutf8,(size_t)len);                        //~v6BkI~
            pco+=len;                                              //~v60dM~
            if (dbcschksw)	//requested                            //~v61bR~
            {                                                      //~v612I~
//          	if (chklen==2)                                     //~v62UR~
            	if (chklen>1)                                      //~v62UR~
                {                                                  //~v61bI~
                	dbcscnt++;                                     //~v612I~
            		if (Pchof)                                     //~v61bI~
                    {                                              //~v61bI~
//              		*pchof++=offs;                             //~v61bI~//~v6BiR~
                		*pchof++=(CHOFTYPE)offs;                   //~v6BiI~
//              		*pchof++=offs+len-1;                       //~v61bI~//~v6BiR~
                		*pchof++=(CHOFTYPE)(offs+len-1);           //~v6BiI~
                    }                                              //~v61bI~
            		if (Pdbcs)                                     //~v61bI~
                    {                                              //~v61bI~
	            		*pdbcs++=UDBCSCHK_DBCS1ST;                 //~v61bI~
    		            UDBCSCHK_DBCSPAD_SETADVANCE(pdbcs,chklen); //~v62UR~
	            		*pdbcs++=UDBCSCHK_DBCS2ND;                 //~v61bI~
                    }                                              //~v61bI~
                }                                                  //~v61bI~
                else                                               //~v61bI~
                {                                                  //~v61bI~
            		if (Pchof)                                     //~v61bI~
//              		*pchof++=offs;                             //~v61bI~//~v6BiR~
                		*pchof++=(CHOFTYPE)offs;                   //~v6BiI~
            		if (Pdbcs)                                     //~v61bI~
	            		*pdbcs++=UDBCSCHK_SBCS;                    //~v61bI~
                }                                                  //~v61bI~
            }                                                      //~v612I~
            offs+=len;                                             //~v61bI~
        }                                                          //~v60dM~
    }                                                              //~v60dM~
    if (Pchof)                                                     //~v61bI~
//  	*pchof++=offs;                                             //~v61bI~//~v6BiR~
    	*pchof++=(CHOFTYPE)offs;                                   //~v6BiI~
//	readlen=(int)((ULONG)pc-(ULONG)Pinp);                          //~v618I~//~v6hhR~
	readlen=(int)((ULPTR)pc-(ULPTR)Pinp);                          //~v6hhI~
//	outlen=(int)((ULONG)pco-(ULONG)Poututf8);                      //~v61bI~//~v6hhR~
	outlen=(int)((ULPTR)pco-(ULPTR)Poututf8);                      //~v6hhI~
    if (Ppchklen)                                                  //~v618I~
	    *Ppchklen=readlen;                                         //~v618I~
    if (Ppoutlen)                                                  //~v60dM~
	    *Ppoutlen=outlen;                                          //~v61bR~
    if (Ppcharcnt)                                                 //~v60dM~
	    *Ppcharcnt=charcnt;                                        //~v60dM~
    tcharwidth=charcnt+dbcscnt;                                    //~v61bR~
    if (Ppcharwidth)	//requested                                //~v612I~
    	*Ppcharwidth=tcharwidth;                                   //~v61bR~
    if (asciisw && !rc)                                            //~v60rI~
    	rc=UTFCVRC_ALLASCII;                                       //~v61bR~
UTRACEP("utfl2f rc=%d chklen=%d,outlen=%d\n",rc,readlen,outlen);   //~v62tI~
UTRACED("utfl2f out",Poututf8,outlen);                             //~v61hR~
UTRACEDIFNZ("utfl2f chof",Pchof,(tcharwidth+1)*2);                 //~v61bR~
UTRACEDIFNZ("utfl2f dbcs",Pdbcs,tcharwidth);                       //~v61bR~
    return rc;                                                     //~v60dM~
}//utfcvl2f                                                        //~v60dM~
//*************************************************************    //~v692I~
//*string conversion locale to utf8 (tab->09 , tab padding->20)    //~v692I~
//*rc:8:stop at invalid input char,4:err char detected,1:all ascii //~v692I~
//*************************************************************    //~v692I~
int utfcvl2ftab(int Popt,char *Poututf8,char *Pinp,char *Pinpdbcs,int Pinplen,//~v692I~
			char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v692I~
{                                                                  //~v692I~
	char *pci,*pcie,*pco,*pcoe,*pcd,*pcin,*pcon;                   //~v692R~
	int rc,outlen=0,leno,leni;                                     //~v692R~
//**********************                                           //~v692I~
	rc=utfcvl2f(Popt,Poututf8,Pinp,0/*initoffs*/,Pinplen,0/*choffs*/,Pdbcs,Ppchklen,&outlen,Ppcharcnt,Ppcharwidth);//~v692I~
    if (Ppoutlen)                                                  //~v692I~
    	*Ppoutlen=outlen;                                          //~v692I~
    pci=Pinp;                                                      //~v692I~
    pcie=pci+Pinplen;                                              //~v692I~
    pco=Poututf8;                                                  //~v692R~
    pcoe=pco+outlen;                                               //~v692I~
    for (;;)                                                       //~v692I~
    {                                                              //~v692I~
//    	leno=(ULONG)pcoe-(ULONG)pco;                               //~v692I~//~v6hhR~
//  	leno=(ULPTR)pcoe-(ULPTR)pco;                               //~v6hhI~//~v6BkR~
    	leno=PTRDIFF(pcoe,pco);                                    //~v6BkI~
        if (leno<=0)                                               //~v692I~
        	break;                                                 //~v692I~
//  	pcon=memchr(pco,' ',leno);                                 //~v692I~//~v6BkR~
    	pcon=memchr(pco,' ',(size_t)leno);                         //~v6BkI~
        if (!pcon)                                                 //~v692I~
        	break;                                                 //~v692I~
//    	leni=(ULONG)pcie-(ULONG)pci;                               //~v692I~//~v6hhR~
//  	leni=(ULPTR)pcie-(ULPTR)pci;                               //~v6hhI~//~v6BkR~
    	leni=PTRDIFF(pcie,pci);                                    //~v6BkI~
        if (leni<=0)                                               //~v692I~
        	break;                                                 //~v692I~
//  	pcin=memchr(pci,' ',leni);                                 //~v692I~//~v6BkR~
    	pcin=memchr(pci,' ',(size_t)leni);                         //~v6BkI~
        if (!pcin)                                                 //~v692I~
        	break;                                                 //~v692I~
        pcd=UTF_PC2PCD(Pinpdbcs,pcin,Pinp);                        //~v692I~
        if (*pcd==UDBCSCHK_TABCHAR)                                //~v692R~
            *pcon=UDBCSCHK_TABCHAR;                                //~v692R~
        pci=pcin+1;                                                //~v692I~
        pco=pcon+1;                                                //~v692I~
    }                                                              //~v692I~
    return rc;                                                     //~v692I~
}//utfcvl2ftab                                                     //~v692I~
#ifdef UTF8UCS2                                                    //~v645I~
#ifdef AAA //no user,using UWCHART                                 //~v6uBI~
//*************************************************************    //~v645I~
//*string conversion locale to ucs2                                //~v645I~
//*rc:8:stop at invalid input char,4:err char detected,1:all ascii //~v645I~
//*************************************************************    //~v645I~
int utfcvl2u(int Popt,char *Pinp,int Pinplen,char *Poutbuff,char *Pdbcs,int Poutbuffsz,int *Ppoutlen)//~v645R~
{                                                                  //~v645I~
	int chklen,rc=0,reslen;                                        //~v645R~
    int asciisw=1,/*readlen,*/outlen,maxucs,ucsctr=0,ii;               //~v645R~//~v6b9R~
//  wchar_t ucs,*pwucs;                                            //~v645R~//~v6a0R~
    UWCHART ucs,*pwucs;                                            //~v6a0I~
    char *pc,repch,*pcd;                                           //~v645R~
//**********************                                           //~v645I~
	repch=(Popt & UTFCVO_REPCH)>>8;                                //~v645I~
    maxucs=Poutbuffsz/sizeof(WUCS);                                //~v645I~
//  for (reslen=Pinplen,pc=Pinp,pwucs=(wchar_t*)(ULONG)Poutbuff,pcd=Pdbcs;//~v645R~//~v6a0R~
//  for (reslen=Pinplen,pc=Pinp,pwucs=(UWCHART*)(ULONG)Poutbuff,pcd=Pdbcs;//~v6a0I~//~v6hhR~
    for (reslen=Pinplen,pc=Pinp,pwucs=(UWCHART*)(ULPTR)Poutbuff,pcd=Pdbcs;//~v6hhI~
			reslen>0;                                              //~v645I~
			reslen-=chklen,pc+=chklen,ucsctr++)                    //~v645I~
    {                                                              //~v645I~
    	if (ucsctr>=maxucs)                                        //~v645I~
        {                                                          //~v645I~
            rc=UTFCVRC_ERROVF;                                     //~v645I~
            break;                                                 //~v645I~
        }                                                          //~v645I~
      	if (UTF8ISASCII(*pc))                                      //~v645R~
      	{                                                          //~v645I~
        	chklen=1;                                              //~v645I~
            if (Poutbuff)                                          //~v645I~
	            *pwucs++=(WUCS)(*pc);                              //~v645R~
            if (Pdbcs)                                             //~v645I~
	            *pcd++=0;	//sbcs                                 //~v645I~
            continue;                                              //~v645I~
      	}                                                          //~v645I~
        asciisw=0;                                                 //~v645I~
//  	chklen=utfcvl2uany1mb(0,pc,reslen,&ucs);  //ucvext_iconvlocal2ucs(iconv/wincolocal2ucs)//~v645R~//~v6unR~
    	chklen=utfcvl2uany1mb(0,pc,reslen,&ucs,NULL/*rc*/);  //ucvext_iconvlocal2ucs(iconv/wincolocal2ucs)//~v6unI~
        if (!chklen) //input is null                               //~v645I~
        {                                                          //~v645I~
            chklen=1;                                              //~v645I~
            if (Poutbuff)                                          //~v645I~
	            *pwucs++=0;                                        //~v645R~
            if (Pdbcs)                                             //~v645I~
	            *pcd++=UDBCSCHK_HKDBCSERR;                         //~v645I~
        }                                                          //~v645I~
        if (chklen<0) //conversion failed                          //~v645I~
        {                                                          //~v645I~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v645I~
            {                                                      //~v645I~
            	rc=UTFCVRC_ERRSTOP;     //8                        //~v645I~
            	break;                                             //~v645I~
            }                                                      //~v645I~
            if (Poutbuff)                                          //~v645I~
            {                                                      //~v645I~
                                                                   //~v645I~
        		if (Popt & UTFCVO_ERRREP)  //replace err           //~v645R~
	            	*pwucs++=repch;                                //~v645R~
            	else                                               //~v645R~
	            	*pwucs++=(WUCS)*pc;                            //~v645R~
            }                                                      //~v645I~
            if (Pdbcs)                                             //~v645I~
	            *pcd++=UDBCSCHK_HKDBCSERR;                         //~v645I~
            rc|=UTFCVRC_ERR;         //4                           //~v645I~
            chklen=1;                                              //~v645I~
        }                                                          //~v645I~
        else                                                       //~v645I~
        {                                                          //~v645I~
            if (Poutbuff)                                          //~v645I~
        		*pwucs++=ucs;                                      //~v645R~
            if (Pdbcs)                                             //~v645I~
            {                                                      //~v645I~
            	if (chklen==1)                                     //~v645I~
		            *pcd++=0;                                      //~v645I~
                else                                               //~v645I~
                {                                                  //~v645I~
	            	*pcd++=UDBCSCHK_DBCS1ST;                       //~v645I~
                    for (ii=1;ii<chklen-1;ii++)                    //~v645I~
                    	*pcd++=UDBCSCHK_DBCSPAD;                   //~v645I~
	            	*pcd++=UDBCSCHK_DBCS2ND;                       //~v645I~
                }                                                  //~v645I~
            }                                                      //~v645I~
        }                                                          //~v645I~
    }                                                              //~v645I~
//  if (reslen>0)                                                  //~v645I~//~v6b9R~
//  readlen=(int)((ULONG)pc-(ULONG)Pinp);                          //~v645I~//~v6b9R~
	outlen=ucsctr*sizeof(WUCS);                                    //~v645R~
    if (Ppoutlen)                                                  //~v645I~
	    *Ppoutlen=outlen;                                          //~v645I~
    if (asciisw && !rc)                                            //~v645I~
    	rc=UTFCVRC_ALLASCII;                                       //~v645I~
UTRACEP("utfl2u rc=%d chklen=%d,outlen=%d\n",rc,/*readlen*/(int)((ULPTR)pc-(ULPTR)Pinp),outlen);   //~v645R~//~v6b9R~//~v6hhR~
UTRACED("utfl2f inp",Pinp,Pinplen);                                //~v645I~
UTRACEDIFNZ("utfl2f out",Poutbuff,outlen);                         //~v645I~
UTRACEDIFNZ("utfl2f dbcs out",Pdbcs,Pinplen);                      //~v645I~
    return rc;                                                     //~v645I~
}//utfcvl2u                                                        //~v645I~
#endif //AAA //no user,using UWCHART                               //~v6uBI~
#endif                                                             //~v645I~
#endif  //WCSUPP                                                   //~v5ncI~
#ifdef UTF8SUPP                                                    //~v5ncI~
//*************************************************************    //~v60eI~
//*string conversion euc to utf8                                   //~v60eI~
//*rc:0x04:err found,0x02:dbcs,3:kana                              //~v616R~
//*************************************************************    //~v60eI~
int utfcve2f(int Popt,char *Poututf8,char *Pinpeuc,int Pinitoffs,int Pinplen,//~v61bR~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v61bR~
{                                                                  //~v60eI~
//	int tcharwidth=0,charwidth,charcnt=0,chklen,rc=0,rc2,rc3,reslen,len,readlen;//~v61bR~//~v6h4R~
  	int tcharwidth=0,charwidth,charcnt=0,chklen,rc=0,rc2,rc3,reslen,len=0,readlen;//~v6h4I~
    int offs;                                                      //~v61bI~
    UINT sjis;                                                     //~v60eI~
    char *pc,*pco,repch,dbcs[2];                                   //~v60eR~
    PCHOFTYPE pchof;                                               //~v61bI~
    char *pdbcs;                                                   //~v61bI~
#ifdef UTF8SUPPH                                                   //~v620I~
    int asciisw=1;                                                 //~v620I~
#endif                                                             //~v620I~
//**********************                                           //~v60eI~
	offs=Pinitoffs;                                                //~v61bI~
    pdbcs=Pdbcs;                                                   //~v61bI~
    pchof=Pchof;                                                   //~v61bI~
	repch=(Popt & UTFCVO_REPCH)>>8;                                //~v61bR~
	for (reslen=Pinplen,pc=Pinpeuc,pco=Poututf8;reslen>0;reslen-=chklen,pc+=chklen,charcnt++,tcharwidth+=charwidth)//~v616R~
    {                                                              //~v60eI~
        chklen=1;                                                  //~v60eI~
        charwidth=1;                                               //~v616R~
        if (*pc<0x80)                                              //~v60eR~
        {                                                          //~v60eI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v61bR~
            {                                                      //~v618I~
    			rc|=UTFCVRC_ASCIIRET;                              //~v61bR~
            	break;                                             //~v618I~
            }                                                      //~v618I~
        	*pco++=*pc;	                                           //~v60eI~
            if (Pchof)                                             //~v61bI~
	            *pchof++=offs;                                     //~v61bI~
            if (Pdbcs)                                             //~v61bI~
	            *pdbcs++=UDBCSCHK_SBCS;                            //~v61bI~
            offs++;                                                //~v61bI~
            continue;                                              //~v60eI~
        }                                                          //~v60eI~
#ifdef UTF8SUPPH                                                   //~v620I~
        asciisw=0;                                                 //~v620I~
#endif                                                             //~v620I~
		rc2=ueuc2shift1(0,pc,reslen,&sjis,dbcs);//mo dbcs out      //~v60eR~
        rc3=0;                                                     //~v60eR~
        switch(rc2)                                                //~v60eI~
        {                                                          //~v60eI~
        case UDBCSCHK_RC_DBCSFOUND:                                //~v60eR~
        	chklen=2;                                              //~v60eI~
            charwidth=2;                                           //~v616R~
            rc|=UTFCVRC_DBCS;         //dbcs found                 //~v61bR~
        	break;                                                 //~v60eI~
        case UDBCSCHK_RC_HANKANAFOUND:                             //~v60eR~
        	chklen=2;                                              //~v60eI~
            rc|=UTFCVRC_KANA;         //hankaku katakana found     //~v61bR~
        	break;                                                 //~v60eI~
        case 0:                       //sbcs                       //~v60eI~
        	break;                                                 //~v60eI~
        default:                                                   //~v60eI~
        	rc3=UTFCVRC_ERR;                                       //~v61bR~
        }                                                          //~v60eI~
        if (!rc3)                                                  //~v60eR~
        	rc3=uccvsjis2utf(0,sjis,pco,&len);                     //~v60eR~
//UTRACEP("sjis2utf rc3=%d,sjis=%x,utflen=%d\n",rc3,sjis,len);       //~v60eI~//~v6h4R~
        if (rc3)                                                   //~v60eR~
        {                                                          //~v60eI~
            rc|=UTFCVRC_ERR;                                       //~v61bR~
			if (Popt & UTFCVO_ERRRET)                              //~v61bR~
            {                                                      //~v616I~
	            rc=UTFCVRC_ERRSTOP;                                //~v61bR~
	        	break;                                             //~v60eR~
            }                                                      //~v616I~
			if (Popt & UTFCVO_ERRREP)                              //~v61bR~
	            *pco++=repch;                                      //~v60eR~
            else                                                   //~v60eI~
            {	                                                   //~v60eI~
            	memcpy(pco,pc,(UINT)chklen);                       //~v60eI~
                pco+=chklen;                                       //~v60eI~
            }                                                      //~v60eI~
            if (Pdbcs)                                             //~v61bI~
	            *pdbcs++=UDBCSCHK_HKDBCSERR;                       //~v61bI~
            if (Pchof)                                             //~v61bI~
            	*pchof=offs;                                       //~v61bI~
            offs++;                                                //~v61bI~
        }                                                          //~v60eI~
        else	//valid utf8                                       //~v61bR~
        {                                                          //~v61bI~
        	pco+=len;                                              //~v60eI~
            if (rc2==UDBCSCHK_RC_DBCSFOUND)                        //~v61bI~
            {                                                      //~v61bI~
                if (Pdbcs)                                         //~v61bI~
                {                                                  //~v61bI~
//euc2shift dose not chk SS3                                       //~v62UR~
                    *pdbcs++=UDBCSCHK_DBCS1ST;                     //~v61bI~
                    *pdbcs++=UDBCSCHK_DBCS2ND;                     //~v61bI~
                }                                                  //~v61bI~
                if (Pchof)                                         //~v61bR~
                {                                                  //~v61bI~
                    *pchof++=offs;                                 //~v61bI~
                    *pchof++=offs+len-1;                           //~v61bI~
                }                                                  //~v61bI~
            }                                                      //~v61bI~
            else                                                   //~v61bI~
            {                                                      //~v61bI~
                if (Pdbcs)                                         //~v61bI~
                    *pdbcs++=UDBCSCHK_SBCS;                        //~v61bI~
                if (Pchof)                                         //~v61bR~
                    *pchof++=offs;                                 //~v61bI~
            }                                                      //~v61bI~
            offs+=len;                                             //~v61bI~
        }                                                          //~v61bI~
    }                                                              //~v60eI~
	readlen=(int)((ULONG)pc-(ULONG)Pinpeuc);                       //~v618I~
    if (Ppchklen)                                                  //~v618I~
	    *Ppchklen=readlen;                                         //~v618I~
    offs-=Pinitoffs;                                               //~v61jI~
    if (Ppoutlen)                                                  //~v60eI~
	    *Ppoutlen=offs;                                            //~v61bR~
    if (Ppcharcnt)                                                 //~v60eI~
	    *Ppcharcnt=charcnt;                                        //~v616R~
    if (Ppcharwidth)                                               //~v616I~
	    *Ppcharwidth=tcharwidth;                                   //~v616R~
#ifdef UTF8SUPPH                                                   //~v620I~
    if (asciisw && !rc)                                            //~v620I~
    	rc=UTFCVRC_ALLASCII;                                       //~v620I~
#endif                                                             //~v620I~
UTRACED("utfe2f inp",Pinpeuc,Pinplen);                             //~v60eR~
UTRACED("utfe2f out",Poututf8,offs);                               //~v61bR~
UTRACEDIFNZ("utfe2f chof",Pchof,(tcharwidth+1)*2);                 //~v61bI~
UTRACEDIFNZ("utfe2f dbcs",Pdbcs,tcharwidth);                       //~v61bI~
UTRACEP("utfe2f rc=%d,charcnt=%d,charwidth=%d,outlen=%d\n",rc,charcnt,tcharwidth,offs);//~v61bR~
    return rc;                                                     //~v60eI~
}//utfcve2f                                                        //~v60eR~
#endif  //UTF8SUPP                                                 //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
//*******************************************************          //~v60aI~
//*setdbcstbl                                                      //~v618R~
//*ignore err utf(no replace invalid string)                       //~v60aI~
//*rc:0x01:dbcs detected, 0x02:nonspace char detect,0x04:invalid utf8 detected//~v618R~
//*******************************************************          //~v60aI~
int utfsetdbcstbl(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,PCHOFTYPE Ppchof,int Putflen,int *Ppwidth,int *Ppucscnt)//~v618R~
{                                                                  //~v60aI~
    ULONG ucs;                                                     //~v60aI~
    int dbcsid,chklen,charwidth,rc=0,width=0,ucscnt,reslen;        //~v60aR~
    UCHAR *pc,*pce,*pdbcs;                                         //~v60aR~
    PCHOFTYPE pchof;                                               //~v618I~
    int offs=0;                                                    //~v618I~
//****************************                                     //~v60aI~
    pc=Ppdata;                                                     //~v60aI~
    pce=Ppdata+Putflen;                                            //~v60aI~
    pchof=Ppchof;                                                  //~v618I~
    for (ucscnt=0,pdbcs=Ppdbcs;pc<pce;pc+=chklen,ucscnt++)         //~v60aI~
    {                                                              //~v60aI~
//      reslen=(ULONG)pce-(ULONG)pc;                               //~v60aI~//~v6hhR~
//      reslen=(ULPTR)pce-(ULPTR)pc;                               //~v6hhI~//~v6BkR~
        reslen=PTRDIFF(pce,pc);                                    //~v6BkI~
        dbcsid=UDBCSCHK_SBCS;                                      //~v60aI~
        charwidth=1;                                               //~v60aI~
        if (!pc)                                                   //~v60aI~
            chklen=1;                                              //~v60aI~
        else                                                       //~v60aI~
        if (utfmb2wc(0,pc,reslen,&ucs,&chklen,&charwidth))         //~v60aI~
        {                                                          //~v60aI~
            chklen=1;                                              //~v60kI~
            dbcsid=UDBCSCHK_HKDBCSERR;                             //~v60aI~
            rc|=UTFSDTRC_ERRUTF;                                   //~v618R~
        }                                                          //~v60aI~
        else                                                       //~v60aI~
        {                                                          //~v60aI~
            if (charwidth<0)       //dosenot occur                 //~v60pR~
            {                                                      //~v60aI~
	            rc|=UTFSDTRC_ERRUTF;                               //~v618I~
                dbcsid=UDBCSCHK_HKDBCSERR;                         //~v60aI~
                charwidth=1;                                       //~v60pI~
            }                                                      //~v60aI~
            else                                                   //~v60aI~
            if (charwidth==0)       //ignore nonspacing char       //~v60aI~
            {                                                      //~v60aI~
	            rc|=UTFSDTRC_NONSPACE;                             //~v618I~
                dbcsid=UDBCSCHK_NONSPACE;                          //~v60aI~
                charwidth=1;                                       //~v60pI~
            }                                                      //~v60aI~
            else                                                   //~v60aI~
//          if (charwidth==2)       //ignore nonspacing char       //~v62UR~
            if (charwidth>1)       //multibyte 2->4                //~v62UR~
            {                                                      //~v60aI~
	            rc|=UTFSDTRC_DBCS;                                 //~v618I~
                if (Ppdbcs)                                        //~v618I~
                {                                                  //~v62UR~
    	            *pdbcs++=UDBCSCHK_DBCS1ST;                     //~v618R~
  		            UDBCSCHK_DBCSPAD_SETADVANCE(pdbcs,charwidth);  //~v62UR~
                }                                                  //~v62UR~
                dbcsid=UDBCSCHK_DBCS2ND;                           //~v60aI~
            }                                                      //~v60aI~
        }                                                          //~v60aI~
        width+=charwidth;                                          //~v60aI~
        if (Ppdbcs)                                                //~v618I~
//      	*pdbcs++=dbcsid;                                       //~v618R~//~v6BiR~
        	*pdbcs++=(UCHAR)dbcsid;                                //~v6BiI~
        if (Ppchof)                                                //~v618I~
        {	                                                       //~v618I~
//      	*pchof++=offs;                                         //~v618R~//~v6BiR~
        	*pchof++=(CHOFTYPE)offs;                               //~v6BiI~
//          if (charwidth==2)       //ignore nonspacing char       //~v62UR~
            if (charwidth>1)       //multibyte                     //~v62UR~
//          	*pchof++=offs+chklen-1;                            //~v618I~//~v6BiR~
            	*pchof++=(CHOFTYPE)(offs+chklen-1);                //~v6BiI~
            offs+=chklen;                                          //~v618I~
        }                                                          //~v618I~
    }                                                              //~v60aI~
    if (Ppchof)                                                    //~v618I~
//      *pchof++=offs; 	//end addr                                 //~v618R~//~v6BiR~
        *pchof++=(CHOFTYPE)offs; 	//end addr                     //~v6BiI~
    if (Ppucscnt)                                                  //~v60aI~
	    *Ppucscnt=ucscnt;                                          //~v60aI~
    if (Ppwidth)                                                   //~v60aI~
	    *Ppwidth=width;                                            //~v60aI~
    return rc;                                                     //~v60aR~
}//utfsetdbcstbl                                                   //~v60aI~
//*******************************************************          //~v60dI~
//*utfisvalidutf8                                                  //~v60dI~
//*chk utf8 string validity                                        //~v60dI~
//*rc:1:valid,2:all ascii,3:break at ascii by request              //~v618R~
//*******************************************************          //~v60dI~
//int utfisvalidutf8(int Popt,char *Pstr,int Plen)                 //~v612R~
int utfisvalidutf8(int Popt,char *Pstr,int Plen,char *Ppdbcs,PCHOFTYPE Ppchof,int *Ppreadlen,int *Ppcharcnt,int *Ppcharwidth)//~v618R~
{                                                                  //~v60dI~
    int opt,len,rc;                                                //~v60dI~
    int ucscnt;                                                    //~v60rI~
//****************************                                     //~v60dI~
	opt=Popt|UTFCVO_ERRRET;                                        //~v61bR~
  if (!(len=Plen))                                                 //~v60rI~
//  len=strlen(Pstr);                                              //~v60dI~//~v6BkR~
    len=(int)strlen(Pstr);                                         //~v6BkI~
//  rc=utfcvf2u(opt,0/*outucs*/,Pstr,0/*dbcs*/,len,&ucscnt,0/*out column width*/);//~v612R~
    rc=utfcvf2u(opt,0/*outucs*/,Pstr,Ppchof,Ppdbcs,0/*initoffs*/,len,Ppreadlen,&ucscnt,Ppcharwidth);//~v61bR~
    if (Ppcharcnt)                                                 //~v612I~
    	*Ppcharcnt=ucscnt;                                         //~v612I~
UTRACEP("utfisvalidutf8 rc=%d\n",rc);                              //~v60dI~
    if (rc & UTFF2U_ERRRC)	//err                                  //~v60dR~
    	return 0;                                                  //~v60dI~
//  if (rc==UTFF2U_ASCII)	//break at ascii                       //~v61mR~
    if (rc & UTFF2U_ASCII)	//break at ascii                       //~v61mR~
    	return UTFIVURC_ASCIIRET;      //3                         //~v618R~
    if (len==ucscnt)                                               //~v60rI~
    	return 2;	//all ascii                                    //~v60rI~
    return 1;                                                      //~v60dI~
}//utfisvalidutf8                                                  //~v60dI~
//*******************************************************          //~v5neR~
//*get string width(not char count) for utf8 string                //~v5neR~
//*right boundary cut option avail                                 //~v5neR~
//*err char is counted as 1                                        //~v5neR~
//*rc:of utfcvf2u                                                  //~v5neR~
//*******************************************************          //~v5neR~
int utfgetstrwidth(int Popt,char *Pstr,int Plen,int *Ppcharwidth,int *Pplenutf)//~v5neR~
{                                                                  //~v5neR~
    int len,rc,maxcol;                                             //~v5neR~
//****************************                                     //~v5neR~
  	if (!(len=Plen))                                               //~v5neR~
//  	len=strlen(Pstr);                                          //~v5neR~//~v6BkR~
    	len=(int)strlen(Pstr);                                     //~v6BkI~
    if (Popt & UTCO_MAXCOL)                                        //~v5neR~
    	maxcol=*Ppcharwidth;	//limit right boundary             //~v5neR~
    else                                                           //~v5neR~
        maxcol=-1;              //no limit                         //~v5neR~
	rc=utfstrchkmbr2wc(Popt,    //UTCO_DBCSBACK etc                //~v5neR~
                          Pstr,          //data addr               //~v5neR~
                          len,             //data length           //~v5neR~
                          0,               //skip column           //~v5neR~
                          maxcol,          //right boundary column from Pstartpos(-1:no limit)//~v5neR~
                          -1,  //maxlenutf  //right boundary by length from Pstartpos(-1:no limit)//~v5neR~
                          0, //PCHOFTYPE Ppchof,      //output:chof top(0 if no chof set)//~v5neR~
                          0, //Pinitoffs,         //offsetvalue for top of Pchof//~v5neR~
                          Ppcharwidth, //Ppcharcnt,        //output:charcnt//~v5neR~
                          0, //*Ppstartoffs,      //output:offset corresponding to Pstartpos//~v5neR~
                          Pplenutf); //*Pplenutf         //output:chked data length after Pstartoffs//~v5neR~
UTRACEP("utfstrwidth rc=%d\n",rc);                                 //~v5neR~
    return rc;                                                     //~v5neR~
}//utfgetstrwidth                                                  //~v5neR~
//*******************************************************          //~v617I~
//*utfisvalidutf8char                                              //~v617I~
//*chk utf8 char validity                                          //~v617I~
//*rc:1:ascii,2:utf8,0:err                                         //~v617I~
//*******************************************************          //~v617I~
int utfisvalidutf8char(int Popt,char *Pstr,int Plen,int *Ppchklen,int *Ppcharwidth)//~v617R~
{                                                                  //~v617I~
    int ch,chsz,rc;                                                //~v617R~
    int ucscnt;                                                    //~v617I~
//****************************                                     //~v617I~
    ch=*Pstr;                                                      //~v617I~
	chsz=UTF8CHARLEN(ch);                                          //~v617R~
    if (Plen<chsz)                                                 //~v617I~
    	return 0;	//err short str                                //~v617I~
    if (!chsz)                                                     //~v617I~
    	return 0;	//err invalid top byte                         //~v617I~
    if (chsz==1)	//not ascii                                    //~v617R~
    	rc=1;                                                      //~v617I~
    else                                                           //~v617I~
    {	                                                           //~v617I~
    	rc=utfcvf2u(0/*opt*/,0/*outucs*/,Pstr,0/*chof*/,0/*dbcs*/,0/*initoffs*/,chsz,0/*readlen*/,&ucscnt,Ppcharwidth);//~v61bR~
    	if (rc & UTFF2U_ERRRC)	//err                              //~v617R~
    		return 0;                                              //~v617R~
        rc=2;                                                      //~v617I~
    }                                                              //~v617I~
    if (Ppchklen)                                                  //~v617I~
    	*Ppchklen=chsz;                                            //~v617I~
    return rc;                                                     //~v617R~
}//utfisvalidutf8char                                              //~v618R~
//*******************************************************          //~v6dfI~
//*utfvalidatesting                                                //~v6dfI~
//*repl err utf8 char                                              //~v6dfI~
//*rc                                                              //~v6dfI~
//*******************************************************          //~v6dfI~
int utfstrvalidate(int Popt,char *Pstr,int Plen,int Perrch,int *Ppokctr,int *Pprepctr)//~v6dfI~
{                                                                  //~v6dfI~
    int errch,rc=0,rc2,chklen,reslen,opt,repctr=0,okctr=0;         //~v6dfI~
    char *pc;                                                      //~v6dfI~
    UWUCS ucs;                                                     //~v6dfI~
//****************************                                     //~v6dfI~
	if (Plen)                                                      //~v6dfI~
    	reslen=Plen;                                               //~v6dfI~
    else                                                           //~v6dfI~
//  	reslen=strlen(Pstr);                                       //~v6dfI~//~v6BkR~
    	reslen=(int)strlen(Pstr);                                  //~v6BkI~
    if (Perrch)                                                    //~v6dfI~
    	errch=Perrch;                                              //~v6dfI~
    else                                                           //~v6dfI~
    	errch='.';                                                 //~v6dfI~
    opt=UCVUCS_UCS4;                                               //~v6dfI~
	for (pc=Pstr;reslen>0;)                                        //~v6dfI~
    {                                                              //~v6dfI~
//  	rc2=uccvutf2ucs(opt,pc,reslen,&ucs,&chklen);               //~v6dfI~//~v6BkR~
    	rc2=uccvutf2ucs((ULONG)opt,pc,reslen,&ucs,&chklen);        //~v6BkI~
        if (rc2)                                                   //~v6dfI~
        {                                                          //~v6dfI~
//      	*pc=errch;                                             //~v6dfI~//~v6BiR~
        	*pc=(char)errch;                                       //~v6BiI~
            chklen=1;                                              //~v6dfI~
            repctr++;                                              //~v6dfI~
            rc=4;                                                  //~v6dfI~
        }                                                          //~v6dfI~
        else                                                       //~v6dfI~
            okctr++;                                               //~v6dfR~
        reslen-=chklen;                                            //~v6dfI~
        pc+=chklen;                                                //~v6dfI~
    }                                                              //~v6dfI~
    if (Ppokctr)                                                   //~v6dfI~
        *Ppokctr=okctr;                                            //~v6dfI~
    if (Pprepctr)                                                  //~v6dfI~
        *Pprepctr=repctr;                                          //~v6dfI~
    return rc;                                                     //~v6dfI~
}//utfstrvalidate                                                  //~v6dfI~
#ifdef UTF8SUPPH                                                   //~v62jI~
//*******************************************************          //~v617I~//~v620I~
//*utfgetutf8strlen                                                //~v620I~
//*count utf8 string length                                        //~v620I~
//*ret len                                                         //~v620I~
//*******************************************************          //~v620I~
int utfgetutf8strlen(int Popt,char *Pstr,int Plen,int *Ppcharcnt)  //~v620I~
{                                                                  //~v620I~
    int chsz,rc,ucscnt=0,reslen,len;                               //~v620R~
    char *pc;                                                      //~v620I~
    ULONG wc;                                                      //~v62pR~
#ifdef UTF8SUPPH                                                   //~v62pI~
    int ucscntlimit=0;                                             //~v6h4R~
#endif                                                             //~v62pI~
//****************************                                     //~v620I~
	if (!(len=Plen))                                               //~v620I~
//  	len=strlen(Pstr);                                          //~v620I~//~v6BkR~
    	len=(int)strlen(Pstr);                                     //~v6BkI~
    if (Popt & UGU8LO_LIMIT_UCSCOUNT)                              //~v62pI~
    	ucscntlimit=*Ppcharcnt;                                    //~v62pI~
	for (reslen=len,pc=Pstr;reslen>0;pc+=chsz,reslen-=chsz,ucscnt++)//~v620I~
    {                                                              //~v620I~
    	if (Popt & UGU8LO_LIMIT_UCSCOUNT)                          //~v62pI~
        	if (ucscnt>=ucscntlimit)                               //~v62pI~
            	break;                                             //~v62pI~
    	if (UTF8ISASCII(*pc))                                               //~v617I~//~v620R~
        {                                                          //~v620I~
            if (Popt & UTFCVO_ASCIIRET)                            //~v620I~
                break;                                             //~v620I~
            chsz=1;                                                //~v620I~
        }                                                          //~v620I~
        else                                                       //~v620I~
        {                                                          //~v620I~
#ifdef AAA                                                         //~v62pR~
			rc=utfisvalidutf8char(UTFF2U_ERRRC,pc,reslen,&chsz,0/*charwidth*/);//~v617R~//~v620R~
        	if (!rc)	//err                                      //~v62pR~
#else       //for performance format chk only,no conversion to locale//~v62pR~
	    	rc=utfgetwc(pc,reslen,&wc,&chsz);   //utf8->ucs2/ucs4  //~v62pR~
        	if (rc)	//err                                          //~v62pR~
#endif                                                             //~v62pM~
        		break;                                             //~v620I~
        }                                                          //~v620I~
    }                                                              //~v620I~
    if (Ppcharcnt)                                                 //~v620I~
    	*Ppcharcnt=ucscnt;                                         //~v620I~
UTRACEP("utfgetutf8strlen rc=%d,ucscnt=%d\n",(int)((ULPTR)pc-(ULPTR)Pstr),ucscnt);//~v62tI~//~v6hhR~
//  return (int)((ULONG)pc-(ULONG)Pstr);                           //~v620I~//~v6hhR~
    return (int)((ULPTR)pc-(ULPTR)Pstr);                           //~v6hhI~
}//utfgetutf8strlen                                                //~v620I~
//*******************************************************          //~v620I~
//*utfsplitchk                                                     //~v620I~
//*chk utf8string split at eol                                     //~v620I~
//*ret rc:4:contains invalid utf8                                  //~v620I~
//*******************************************************          //~v620I~
int utfsplitchk(int Popt,char *Pstr,int Plen,int *Pputf8len,int *Pperrctr)//~v620R~
{                                                                  //~v620I~
    int chsz,ucscnt=0,reslen,len,rc=0,errctr=0;                    //~v620R~
    char *pc;                                                      //~v620I~
//****************************                                     //~v620I~
	if (!(len=Plen))                                               //~v620I~
//  	len=strlen(Pstr);                                          //~v620I~//~v6BkR~
    	len=(int)strlen(Pstr);                                     //~v6BkI~
	for (reslen=len,pc=Pstr;reslen>0;pc+=chsz,reslen-=chsz,ucscnt++)//~v620I~
    {                                                              //~v620I~
    	if (UTF8ISASCII(*pc))                                      //~v620I~
            chsz=1;                                                //~v620I~
        else                                                       //~v620I~
        {                                                          //~v620I~
			chsz=UTF8CHARLEN(*pc);                                 //~v620I~
            if (chsz>reslen)                                       //~v620I~
            	break;                                             //~v620I~
			rc=utfisvalidutf8char(UTFF2U_ERRRC,pc,reslen,&chsz,0/*charwidth*/);//~v620I~
        	if (!rc)	//err                                      //~v620I~
            {                                                      //~v620I~
            	errctr++;                                          //~v620I~
            	chsz=1;                                            //~v620I~
                rc=4;                                              //~v620I~
            }                                                      //~v620I~
        }                                                          //~v620I~
    }                                                              //~v620I~
    if (Pputf8len)                                                 //~v620R~
    	*Pputf8len=len-reslen;                                     //~v620I~
    if (Pperrctr)                                                  //~v620R~
    	*Pperrctr=errctr;                                          //~v620I~
    return rc;                                                     //~v620I~
}//utfsplitchk                                                     //~v620I~
#endif                                                             //~v62jI~
#ifdef AAA                                                         //~v6hKI~
//**************************************************************** //~v618I~
//!utfgetutf8str                                                   //~v618I~
//convert string to utf8 string                                    //~v618I~
//opt:0xff00:replace char                                          //~v618I~
//datalen:do strlen if 0                                           //~v618I~
//ret:0:all ascii,1:all valid utf8,2:locale conversion successs,4:conv err detected//~v618I~
//**************************************************************** //~v618I~
int utfgetutf8str(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Ppdbcs,PCHOFTYPE Ppchof,int *Ppreadlen,int *Pputflen,int *Ppcharwidth)//~v618R~
{                                                                  //~v618I~
    int len,rc,utflen,charwidth,repch,opt=0;                       //~v618R~
    int readlen;                                                   //~v61mI~
//****************************                                     //~v618I~
UTRACEP("utfgetutf8str\n");                                        //~v618I~
	repch=Popt & UTFGUSO_REPCH;                                    //~v618I~
  	if (!(len=Pdatalen))                                           //~v618I~
		len=strlen(Pstr);                                          //~v618I~
	if (Popt & UTFGUSO_EOLSPLIT)	//  0x0002    //allow insufficiant at end of line//~v618I~
		opt=UTFCVO_EOLSPLITOK;  //allow last char cut by length(fldwidth)//~v61bR~
	if (Popt & UTFGUSO_ASCIIRET)   //  0x0002    //allow insufficiant at end of line//~v618I~
		opt|=UTFCVO_ASCIIRET;                                      //~v61bR~
//	if (rc=utfisvalidutf8(opt,Pstr,len,Ppdbcs,Ppchof,Ppreadlen,0,Ppcharwidth),rc)//~v61mR~
  	rc=utfisvalidutf8(opt,Pstr,len,Ppdbcs,Ppchof,&readlen,0,Ppcharwidth);//~v61mI~
    if (Ppreadlen)                                                 //~v61mI~
        *Ppreadlen=readlen;                                        //~v61mI~
  	if (rc)                                                        //~v61mI~
    {                                                              //~v618I~
		UTRACEP("utfgetutf8strvalid ascii/utf8 rc=%d\n",rc);       //~v618I~
    	if (Pputflen)                                              //~v618I~
//  		*Pputflen=len;                                         //~v61mR~
    		*Pputflen=readlen;	//!=len if ascii break             //~v61mI~
    	if (rc==2)	//all ascii                                    //~v618I~
	    	return UTFGUSRC_ALLASCII;                              //~v618R~
#ifdef UTF8SUPPH                                                   //~v620I~
		if (Popt & UTFGUSO_CVF2L) //convert utf8 to locale codepage//~v620R~
        {                                                          //~v620I~
			utfcvf2l(0,Poutbuff,Pstr,len,                          //~v620R~
							Ppreadlen,&utflen/*locale outlen*/,Ppcharwidth);//~v620R~
			if (Popt & UTFGUSO_OUTSTRZ)                                    //~v618I~//~v620I~
        		*(Poutbuff+utflen)=0;                                      //~v618I~//~v620I~
    		if (Pputflen)                                                  //~v618I~//~v620I~
    			*Pputflen=utflen; //locale len                                         //~v618I~//~v620I~
        }                                                          //~v620I~
#endif                                                             //~v620M~
    	if (rc==UTFIVURC_ASCIIRET)	//detected ascii               //~v618R~
			return UTFGUSRC_ASCIIRETU8;                            //~v618R~
	    return UTFGUSRC_ALLUTF8;                                   //~v618R~
    }                                                              //~v618I~
#ifdef UTF8SUPPH                                                   //~v62jI~
  if (Popt & UTFGUSO_NOL2F) //bypass cv locale to utf8             //~v620R~
  	rc=UTFGUSRC_LCOK;                                              //~v620I~
  else                                                             //~v620I~
#endif                                                             //~v62jI~
  {                                                                //~v620I~
    opt=0;                                                         //~v618I~
    if (repch)                                                     //~v618I~
		opt|=(UTFCVO_ERRREP|repch);                                //~v61bR~
	if (Popt & UTFGUSO_ASCIIRET)   //  0x0002    //allow insufficiant at end of line//~v618I~
		opt|=UTFCVO_ASCIIRET;                                      //~v61bR~
    rc=utfcvl2f(opt,Poutbuff,Pstr,0/*initoffs*/,len,Ppchof,Ppdbcs,Ppreadlen,&utflen,0/*charcnt*/,&charwidth);	//conv to utf8,get charwidth//~v61bR~
//  if (rc>UTFCVRC_ERR)                                            //~v61bR~//~v62kR~
    if (rc>=UTFCVRC_ERR)                                           //~v62kI~
    {                                                              //~v620I~
    	rc=UTFGUSRC_LCERR;	//       4                             //~v618I~
#ifdef UTF8SUPPH                                                   //~v62jI~
        charwidth=len;                                             //~v620I~
        utflen=len;                                                //~v620I~
#endif                                                             //~v62jI~
    }                                                              //~v620I~
    else                                                           //~v618I~
    {                                                              //~v618R~
      if (rc==UTFCVRC_ASCIIRET)	//detected ascii                   //~v61bR~
	  	rc|=UTFGUSRC_ASCIIRETLC;                                   //~v618I~
      else                                                         //~v618I~
		rc=UTFGUSRC_LCOK;    //locale conversion                   //~v618R~
    }                                                              //~v618I~
    if (Ppchof||Ppdbcs||Ppcharwidth	//setup requested              //~v61bR~
    ||  Popt & UTFGUSO_NOLOCALEDBCSTB)	//bypass req               //~v61aI~
		utfsetdbcstbl(0,Poutbuff,Ppdbcs,Ppchof,utflen,&charwidth,0);//~v618I~
	if (Popt & UTFGUSO_OUTSTRZ)                                    //~v618I~
        *(Poutbuff+utflen)=0;                                      //~v618I~
    if (Ppcharwidth)                                               //~v618I~
    	*Ppcharwidth=charwidth;                                    //~v618I~
    if (Pputflen)                                                  //~v618I~
    	*Pputflen=utflen;                                          //~v618I~
	UTRACED("Poutbuff",Poutbuff,utflen);                           //~v618I~//~v620M~
  }                                                                //~v620M~
	UTRACEP("utfgetutf8str rc=%d\n",rc);                           //~v618I~
    return rc;                                                     //~v618I~
}//utfgetutf8str                                                   //~v618I~
#endif          //AAA                                              //~v6hKI~
#ifdef LNX                                                         //~v61bI~//~v62tR~
//**************************************************************** //~v61bI~
//!utfcvl2fany                                                     //~v61bR~
//locale->utf8 conversion by iconv                                 //~v61bR~
//ret:4 err                                                        //~v61bI~
//**************************************************************** //~v61bI~
int utfcvl2fany(int Popt,char *Pplocale,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v61bR~
			PCHOFTYPE Pchof,char *Pdbcs,                           //~v61bI~
			int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v61bI~
{                                                                  //~v61bI~
    iconv_t hiconv;                                                //~v61bI~
    char *pci,*pco,*pco2,/**pci2,*/*pdbcs;                         //~v626R~
    int rc,rciconv,reslen,outreslen,outmax=0x7fff,repch,charwidth=0,charcnt=0,ucscnt,writelen,readlen;//~v61bR~
//  int outreslen2,/*ii,*/asciisw,convlen,width,convlen2,dbcschksw,offs,utflen;//~v624R~
    int            /*ii,*/asciisw,convlen,width,         dbcschksw,offs,utflen;//~v624R~
//  int outreslen2,convlen2;                                       //~v624R~//~v690R~
    size_t outreslen2,convlen2;                                    //~v690I~
    PCHOFTYPE pchof;                                               //~v61bI~
//#ifndef UTF8SUPPH                                                  //~v626I~//~v62sR~
    int ii;                                                        //~v626I~
    char *pci2/*,*pc*/;                                                //~v626I~//~v62sR~
//#endif                                                             //~v626I~//~v62sR~
#ifdef UTF8SUPPH                                                   //~v62sI~
    int asciidelmsw;                                               //~v62sI~
#endif                                                             //~v62sI~
	int outbuffsz=0,swovf=0;                                       //~v6hGI~
    char *pcoe;                                                    //~v6hGR~
//****************************                                     //~v61bI~
	if (utfcvlocaleopen(UTFCVO_2UTF,Pplocale,&hiconv))             //~v61bR~
    {                                                              //~v6b4I~
        if (Ppchklen)                                              //~v6b4I~
            *Ppchklen=1;                                           //~v6b4I~
        if (Ppoutlen)                                              //~v6b4I~
            *Ppoutlen=1;                                           //~v6b4I~
        if (Ppcharcnt)                                             //~v6b4I~
            *Ppcharcnt=1;                                          //~v6b4I~
        if (Ppcharwidth)    //requested                            //~v6b4I~
            *Ppcharwidth=1;                                        //~v6b4I~
        *Poututf8='?';                                             //~v6b4I~
    	return UTFCVRC_SEVERR;                                     //~v61bR~
    }                                                              //~v6b4I~
    asciisw=1;		//reset when non ascii found                   //~v62sI~
    rc=0;                                                          //~v62sI~
	repch=(Popt & UTFCVO_REPCH)>>8;                                //~v61bR~
  if (Popt & UTFCVO_BUFFSZPARM) //outbuff size parm specified      //~v6hGI~
  	outreslen=outbuffsz=*Ppoutlen;                                 //~v6hGI~
  else                                                             //~v6hGI~
    outreslen=outmax;                                              //~v61bI~
    pcoe=Poututf8+outbuffsz;                                       //~v6hGM~
    dbcschksw=(Ppcharcnt||Ppcharwidth||Pdbcs||Pchof); //required count char/width//~v61bR~
//#ifdef UTF8SUPPH    //chk asciiret at utfcvf2u                     //~v625I~//~v62sR~
//    if (Popt & UTFCVO_ASCIIRET)                                    //~v625I~//~v62sR~
//        dbcschksw=1;                                               //~v625I~//~v62sR~
//#endif                                                             //~v625I~//~v62sR~
    pdbcs=Pdbcs;                                                   //~v61bI~
    pchof=Pchof;                                                   //~v61bI~
    offs=Pinitoffs;                                                //~v61bI~
	for (reslen=Pinplen,pci=Pinp,pco=Poututf8;reslen>0;)           //~v61bR~
    {                                                              //~v61bI~
      	if (UTF8ISASCII(*pci))                                     //~v61bR~
      	{                                                          //~v61bI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v61bR~
            {                                                      //~v61bI~
    			rc|=UTFCVRC_ASCIIRET;                              //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
            if (outbuffsz && pco>=pcoe)                            //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
            *pco++=*pci++;                                         //~v61bR~
            reslen--;                                              //~v61bI~
            outreslen--;                                           //~v61bI~
            charcnt++;                                             //~v61bI~
            charwidth++;                                           //~v61bI~
            if (Pchof)                                             //~v61bI~
//              *pchof++=offs;                                     //~v61bR~//~v6BkR~
                *pchof++=(USHORT)offs;                             //~v6BkI~
            if (Pdbcs)                                             //~v61bI~
                *pdbcs++=UDBCSCHK_SBCS;                            //~v61bI~
            offs++;                                                //~v61bI~
            continue;                                              //~v61bI~
      	}                                                          //~v61bI~
        asciisw=0;                                                 //~v61bI~
#ifdef UTF8SUPPH                                                   //~v62sI~
        asciidelmsw=0;                                             //~v62sI~
#endif                                                             //~v62sI~
//#ifndef UTF8SUPPH   //chk asciiret at utfcvf2u                     //~v625I~//~v62sR~
		if (Popt & UTFCVO_ASCIIRET)                                //~v61bR~
        {                                                          //~v61bI~
        	for (ii=reslen,pci2=pci;ii>0;ii--,pci2++)              //~v61bR~
            {                                                      //~v6t3I~
            	if (ii>=4 && UDBCSCHK_ISGB4(pci2))                 //~v6t3I~
                {                                                  //~v6t3I~
                	ii-=3;                                         //~v6t3I~
                    pci2+=3;                                       //~v6t3I~
                }                                                  //~v6t3I~
                else	                                           //~v6t3I~
        		if (UTF8ISASCII(*pci2))                            //~v61bR~
            		break;                                         //~v61bI~
            }                                                      //~v6t3I~
	        convlen=reslen-ii;	                                   //~v61bI~
#ifdef UTF8SUPPH                                                   //~v62sI~
			if (ii>0)	//not end of line                          //~v62sI~
            {                                                      //~v62sI~
            	asciidelmsw=1;                                     //~v62sI~
            	convlen++;	//chk including last ascii             //~v62sI~
            }                                                      //~v62sI~
#endif                                                             //~v62sI~
        }                                                          //~v61bI~
        else                                                       //~v61bI~
//#endif                                                             //~v625I~//~v62sR~
        	convlen=reslen;                                        //~v61bI~
//      convlen2=convlen;                                          //~v61bI~//~v6BkR~
        convlen2=(size_t)convlen;                                  //~v6BkI~
//      outreslen2=outreslen;                                      //~v61bI~//~v6BkR~
        outreslen2=(size_t)outreslen;                              //~v6BkI~
        pco2=pco;                                                  //~v61bI~
        UTRACED("utfcvl2fany iconv inp",pci,convlen);              //~v6hKI~
//      rciconv=iconv(hiconv,&pci,&convlen2,&pco,&outreslen2);     //~v5ncI~
//      rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&convlen2,&pco,&outreslen2);//~v5ncR~//~v5nDR~
//      rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen2),&pco,ICONV_SZTYPE(&outreslen2));//~v5nDI~//~v6BkR~
        rciconv=(int)iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen2),&pco,ICONV_SZTYPE(&outreslen2));//~v6BkI~
//      UTRACEP("utfcvl2fany iconv rc=%d,err=%d,ilen=%d->%d,olen=%d->%d,in=%p->%p,out=%p->%p\n",rciconv,errno,convlen,convlen2,outreslen,outreslen2,pci2,pci,pco2,pco);//~v690I~//~v6h9R~//~v6hKR~//~v6s0R~
        if (rciconv==-1 && errno==E2BIG)	//out overflow         //~v6hGI~
        	swovf=1;                                               //~v6hGI~
//      readlen=convlen-convlen2;                                  //~v61bR~//~v6BkR~
        readlen=convlen-(int)convlen2;                             //~v6BkI~
//      writelen=outreslen-outreslen2;                             //~v61bI~//~v6BkR~
        writelen=outreslen-(int)outreslen2;                        //~v6BkI~
        UTRACED("utfcvl2fany iconv out",pco2,writelen);            //~v6hKR~
        reslen-=readlen;                                           //~v61bI~
//      outreslen=outreslen2;                                      //~v61bI~//~v6BkR~
        outreslen=(int)outreslen2;                                 //~v6BkI~
#ifdef UTF8SUPPH                                                   //~v62sI~
		if (asciidelmsw)	//chk asciiret                         //~v62sI~
        {                                                          //~v62sI~
        	if (writelen && UTF8ISASCII(*(pco-1)))	//back ascii then break next//~v62sR~
            {                                                      //~v62sI~
            	readlen--;                                         //~v62sI~
                writelen--;                                        //~v62sI~
                reslen++;                                          //~v62sI~
                outreslen++;                                       //~v62sI~
                pci--;                                             //~v62sI~
                pco--;                                             //~v62sI~
            }                                                      //~v62sI~
        }                                                          //~v62sI~
#endif                                                             //~v62sI~
        if (writelen && dbcschksw) //required count char/width     //~v61bR~
        {                                                          //~v61bI~
//#ifdef UTF8SUPPH                                                   //~v625I~//~v62sR~
//            utfcvf2u(Popt/*asciiret*/,0/*outucs*/,pco2,pchof,pdbcs,offs,writelen,&utflen,&ucscnt,&width);//~v625I~//~v62sR~
//#else                                                              //~v625I~//~v62sR~
            utfcvf2u(0,0/*outucs*/,pco2,pchof,pdbcs,offs,writelen,&utflen,&ucscnt,&width);//~v61bR~
            UTRACEP("utfcvl2fany utfcvf2u utflen=%d,ucscnt=%d,width=%d\n",utflen,ucscnt,width);//~v6hKI~
            UTRACED("utfcvl2fany utfcvf2u inp utf8",pco2,writelen);//~v6hKI~
            UTRACED("utfcvl2fany utfcvf2u pdbcs",pdbcs,width);     //~v6hKI~
//#endif                                                             //~v625M~//~v62sR~
            charwidth+=width;                                      //~v61bI~
            charcnt+=ucscnt;                                       //~v61bI~
            offs+=utflen;                                          //~v61bI~
#ifdef UTF8SUPPH                                                   //~v62sI~
            writelen=utflen;                                       //~v62sI~
#endif                                                             //~v62sI~
            if (Pchof)                                             //~v61bI~
            	pchof+=width;                                      //~v61bI~
            if (Pdbcs)                                             //~v61bI~
            	pdbcs+=width;                                      //~v61bI~
        }                                                          //~v61bI~
#ifdef UTF8SUPPH                                                   //~v625I~
        else                                                       //~v625I~
        {                                                          //~v625I~
            offs+=writelen;                                        //~v625I~
        }                                                          //~v625I~
#endif                                                             //~v625I~
        if (rciconv==(size_t)-1)	//conv err                     //~v61bR~
        {                                                          //~v61bI~
        	if (swovf)                                             //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF; //without set DBCSERR          //~v6hGR~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v61bR~
            {                                                      //~v61bI~
            	rc=UTFCVRC_ERRSTOP;     //8                        //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
            if (outbuffsz && pco>=pcoe)                            //~v6hGI~
            {                                                      //~v6hGI~
            	rc|=UTFCVRC_ERROVF;                                //~v6hGI~
            	break;                                             //~v6hGI~
            }                                                      //~v6hGI~
        	if (Popt & UTFCVO_ERRREP)  //replace err               //~v61bR~
//              *pco++=repch;                                      //~v61bI~//~v6BkR~
                *pco++=(char)repch;                                //~v6BkI~
            else                                                   //~v61bI~
	            *pco++=*pci;                                       //~v61bR~
            rc|=UTFCVRC_ERR;         //4                           //~v61bR~
            pci++;                                                 //~v61bR~
            reslen--;                                              //~v61bI~
            outreslen--;                                           //~v61bI~
            charcnt++;                                             //~v61bI~
            charwidth++;                                           //~v61bI~
            if (Pchof)                                             //~v61bI~
//          	*pchof++=offs;                                     //~v61bR~//~v6BkR~
            	*pchof++=(USHORT)offs;                             //~v6BkI~
            if (Pdbcs)                                             //~v61bI~
            	*pdbcs++=UDBCSCHK_HKDBCSERR;                       //~v61bR~
            offs++;                                                //~v61bI~
        }                                                          //~v61bI~
		if (asciidelmsw)	//chk asciiret                         //~v6hJI~
        {                                                          //~v6hJI~
    		rc|=UTFCVRC_ASCIIRET;                                  //~v6hJI~
            break;                                                 //~v6hJI~
        }                                                          //~v6hJI~
    }                                                              //~v61bI~
	utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gR~
    if (Pchof)                                                     //~v61bI~
//  	*pchof=offs;                                               //~v61bI~//~v6BkR~
    	*pchof=(USHORT)offs;                                       //~v6BkI~
	readlen=(int)((ULONG)pci-(ULONG)Pinp);                         //~v61bR~
    if (Ppchklen)                                                  //~v61bI~
	    *Ppchklen=readlen;                                         //~v61bI~
    if (Ppoutlen)                                                  //~v61bI~
	    *Ppoutlen=offs-Pinitoffs;                                  //~v61hR~
    if (Ppcharcnt)                                                 //~v61bI~
	    *Ppcharcnt=charcnt;                                        //~v61bI~
    if (Ppcharwidth)	//requested                                //~v61bI~
    	*Ppcharwidth=charwidth;                                    //~v61bR~
    if (asciisw && !rc)                                            //~v61bI~
    	rc=UTFCVRC_ALLASCII;                                       //~v61bR~
UTRACED("utfl2f inp",Pinp,Pinplen);                                //~v61bI~
UTRACED("utfl2f out",Poututf8,offs);                               //~v61bR~
UTRACEDIFNZ("utfl2f chof",Pchof,(charwidth+1)*2);                  //~v61bI~
UTRACEDIFNZ("utfl2f dbcs",Pdbcs,charwidth);                        //~v61bI~
//  return 0;                                                      //~v61bI~//~v62sR~
    return rc;                                                     //~v62sI~
}//utfcvl2fany                                                     //~v61bR~
#endif                                                             //~v61uI~
//*************************************************************    //~v62tI~
//*chek one utf char validity                                      //~v62tI~
//*ret :0 invalid,1:ascii,2:valid cv to locale                     //~v62tR~
//*************************************************************    //~v62tI~
int utfcvf2l1(int Popt,char *Pinp,int Plen,int *Ppchklen)          //~v62tR~
{                                                                  //~v62tI~
	char wklc[MAX_MBCSLEN],*pc,*pce;                               //~v62tR~
    int utfchsz,chklen,outlen,rc=0,opt;                            //~v62tR~
//**********************                                           //~v62tI~
	opt=UTFCVO_ERRRET;                                             //~v62tI~
    for (pc=Pinp,pce=pc+Plen;pc<pce;)                              //~v62tI~
    {                                                              //~v62tI~
        utfchsz=UTF8CHARLEN(*pc);                                  //~v62tR~
        if (!utfchsz|| utfchsz>Plen)                               //~v62tR~
        	break;                                                 //~v62tI~
        if (utfchsz==1)	//ascii                                    //~v62tR~
        	rc|=1;                                                 //~v62tI~
        else                                                       //~v62tI~
        {                                                          //~v62tI~
        	if (utfcvf2l(opt,wklc,Pinp,utfchsz,&chklen,&outlen,0/*char width*/))//cv err//~v62tR~
            	break;                                             //~v62tI~
            rc|=2;                                                 //~v62tI~
        }                                                          //~v62tI~
        pc+=utfchsz;                                               //~v62tM~
        if (!(Popt & UTFCVF2L1O_MULT))                             //~v62tI~
        	break;                                                 //~v62tI~
    }                                                              //~v62tI~
    if (Ppchklen)                                                  //~v62tI~
//      *Ppchklen=(int)((ULONG)pc-(ULONG)Pinp);                    //~v62tI~//~v6hhR~
        *Ppchklen=(int)((ULPTR)pc-(ULPTR)Pinp);                    //~v6hhI~
    return rc;                                                     //~v62tR~
}//utfcvf2l1                                                       //~v62tI~
//*************************************************************    //~v61bI~
//*string conversion locale from utf8                              //~v6uBR~
//errrep for ucs4 on w32                                           //~v6uBI~
                                                                   //~v6uBI~
//*rc:0x200:stop at invalid input char,0x0100:err char detected,1:all ascii//~v6ueR~
//*************************************************************    //~v61bI~
int utfcvf2l(int Popt,char *Pout,char *Pinp,int Pinplen,           //~v61bR~
			int *Ppchklen,int *Ppoutlen,int *Ppcharwidth)          //~v61bR~
{                                                                  //~v61bI~
//  int charcnt=0,chklen,rc=0,reslen,len;                          //~v6h4R~
    int charcnt=0,chklen,rc=0,reslen,len=0;                        //~v6h4I~
//  int asciisw=1,readlen,offs,charwidth,rcutf;                    //~v6h5R~
    int asciisw=1,readlen,offs,charwidth=0,rcutf;                  //~v6h5I~
#ifdef AAA                                                         //~v62QI~
	int opt,errctr;                                                //~v62QI~
#endif                                                             //~v62QI~
//  wchar_t ucs;                                                   //~v61bI~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
    ULONG   ucs4;                                                  //~v5m0I~
    char *pc,*pco,repch,dbcschksw;                                 //~v61bI~
#ifdef UTF8UCS2                                                    //~v644I~
    int errchsz=0;                                                 //~v6h4R~
#endif                                                             //~v644I~
//**********************                                           //~v61bI~
UTRACEP("utfcvf2l entry inplen=%d\n",Pinplen);                     //~v62tI~
//#ifdef AAA                                                         //~v62QI~//~v6f3R~
//#ifdef UTF8SUPPH                                                   //~v620I~//~v6f3R~
//    if (UDBCSCHK_ISDBCSJ())     //Japanese(EUC and EUC+UTF8)       //~v620I~//~v6f3R~
//#else                                                              //~v620I~//~v6f3R~
//    if (UDBCSCHK_ISUTF8J())                                        //~v61bI~//~v6f3R~
//#endif                                                             //~v620I~//~v6f3R~
//    {                                                              //~v61bI~//~v6f3R~
//#ifdef LNX                                                         //~v61bI~//~v6f3R~
//        opt=UCVUCS_EUC|UCVUCS_NOERRMSG;                            //~v61bI~//~v6f3R~
//#else                                                              //~v61bI~//~v6f3R~
//        opt=UCVUCS_NOERRMSG;                                       //~v61bI~//~v6f3R~
//#endif                                                             //~v61bI~//~v6f3R~
//#ifdef UTF8SUPPH                                                   //~v620I~//~v6f3R~
//        opt|=UCVUCS_RETALLA;    //chk allascii                     //~v620I~//~v6f3R~
//        if (Popt & UTFCVO_ERRREP)  //replace err                   //~v620I~//~v6f3R~
//        {                                                          //~v620I~//~v6f3R~
//            repch=(Popt & UTFCVO_REPCH)>>8;                        //~v620I~//~v6f3R~
//            opt|=repch;                     //rep by errch         //~v620I~//~v6f3R~
//        }                                                          //~v620I~//~v6f3R~
//        else                                                       //~v62DI~//~v6f3R~
//        if (Popt & UTFCVO_ERRRET)  //err returnr                   //~v62DI~//~v6f3R~
//            opt|=UCVUCS_ERRSTOP;    //return if err                //~v62DI~//~v6f3R~
//        else                                                       //~v62DI~//~v6f3R~
//        opt|=UCVUCS_UTFERR1;                                       //~v62fI~//~v6f3R~
//        if (Popt & UTFCVO_ASCIIRET)  //err returnr                 //~v62JI~//~v6f3R~
//            opt|=UCVUCS_ASCIIRET;                                  //~v62JI~//~v6f3R~
//#endif                                                             //~v620I~//~v6f3R~
//        len=Pinplen;                                               //~v61uI~//~v6f3R~
//        rc=ucvsutf2sjis(0/*errfunc*/,opt,Pinp,len,Pout,MAX_INT_VAL,&chklen,&charwidth,&errctr);//~v61bR~//~v6f3R~
//        if (Ppchklen)                                                  //~v61bI~//~v623I~//~v6f3R~
//            *Ppchklen=chklen;                                         //~v61bI~//~v623I~//~v6f3R~
//        if (Ppoutlen)   //requested                                //~v61bI~//~v6f3R~
//            *Ppoutlen=charwidth;                                   //~v61bR~//~v6f3R~
//        if (Ppcharwidth)    //requested                            //~v61bI~//~v6f3R~
//            *Ppcharwidth=charwidth;                                //~v61bR~//~v6f3R~
//        if (rc==UCVUCS_ALLASCII)                                   //~v620R~//~v6f3R~
//            rc=UTFCVRC_ALLASCII;                                   //~v620I~//~v6f3R~
//        else                                                       //~v62fI~//~v6f3R~
//        if (rc==UCVUCSRC_ASCII) //by ASCIIRET option               //~v62JI~//~v6f3R~
//            rc=UTFCVRC_ASCIIRET;                                   //~v62JI~//~v6f3R~
//        else                                                       //~v62JI~//~v6f3R~
//        if (rc)                                                    //~v62fI~//~v6f3R~
//            rc=UTFCVRC_ERR;                                        //~v62fI~//~v6f3R~
//        return rc;                                                 //~v61bI~//~v6f3R~
//    }                                                              //~v61bI~//~v6f3R~
//#endif                                                             //~v62QI~//~v6f3R~
#ifdef LNX                                                         //~v61bI~
//#ifdef AAA                                                         //~v62QI~//~v6f3R~
//    else                                                           //~v61bI~//~v6f3R~
//#endif                                                             //~v62QI~//~v6f3R~
//      if (Gulibutfmode & GULIBUTFENV)	//env is utf8              //~v61gR~
	  if (!UDBCSCHK_IS_LOCALICU())	//env is utf8 but use ICU as local converter//~v6f5I~//~v6f3I~
        if (UTF8MODEICONV())	//env is utf8                      //~v61gI~
        {                                                          //~v61bI~
			rc=utfcvf2lany(Popt,0/*localecode:usepreviously set*/,Pout,Pinp,Pinplen,//~v61bR~
			                    Ppchklen,Ppoutlen,0/*charcnt*/,Ppcharwidth);//~v61bR~
//          if (rc<UTFCVRC_SEVERR)                                 //~v61bI~//~v620R~
//          	return rc;                                         //~v61bI~//~v620R~
//          rc=0;	//continue by wctombr                          //~v61bI~//~v620R~
            return rc;                                             //~v620I~
        }                                                          //~v61bI~
#endif                                                             //~v61bI~
//	repch=(Popt & UTFCVO_REPCH)>>8;                                //~v61bR~//~v6BkR~
  	repch=(char)((Popt & UTFCVO_REPCH)>>8);                        //~v6BkI~
    dbcschksw=(Ppcharwidth!=0);	//requested                        //~v61bR~
#ifdef UTF8SUPPH                                                   //~v62eR~
    offs=0;                                                        //~v62eI~
#endif                                                             //~v62eI~
	for (reslen=Pinplen,pc=Pinp,pco=Pout;reslen>0;reslen-=chklen,pc+=chklen,charcnt++)//~v61bI~
    {                                                              //~v61bI~
    	if (!*pc)                                                  //~v61bI~
        	if (Popt & UTFCVO_STRZ)                                //~v61bR~
            	break;                                             //~v61bI~
      	if (UTF8ISASCII(*pc))                                      //~v61bI~
      	{                                                          //~v61bI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v61bR~
            {                                                      //~v61bI~
    			rc|=UTFCVRC_ASCIIRET;                              //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
        	chklen=1;                                              //~v61bI~
            charwidth++;                                           //~v61bI~
            *pco++=*pc;                                            //~v61bI~
            offs++;                                                //~v61bI~
            continue;                                              //~v61bI~
      	}                                                          //~v61bI~
        asciisw=0;                                                 //~v61bI~
//      rcutf=utfgetwc(pc,reslen,&ucs,&chklen);                    //~v5m0R~
        rcutf=utfgetwc(pc,reslen,&ucs4,&chklen);                   //~v5m0I~
//      ucs=(wchar_t)ucs4;                                         //~v5m0I~//~v6a0R~
//      ucs=(UWCHART)ucs4;                                         //~v6a0I~//~v6BjR~
#ifdef W32UNICODE                                                  //~v6ueM~
	  errchsz=0;                                                   //~v6ueM~
//      if (!rcutf && ucs4>UTF_UCS2MAX)   //ucs4 id surrogateH+L     //~v6ueM~//~v6BjR~
//      {                                                            //~v6ueM~//~v6BjR~
//        len=-1; //err id                                           //~v6ueM~//~v6BjR~
////      errchsz=4;  //dd2lc put 4 "?"                              //~v6ueM~//~v6uBR~//~v6BjR~
//        errchsz=2;  //dd2lc put 2 "?" for ovf                      //~v6uBI~//~v6BjR~
//      }                                                            //~v6ueM~//~v6BjR~
//      else                                                         //~v6ueM~//~v6BjR~
#endif                                                             //~v6ueM~
//      {                                                            //~v6ueM~//~v6BjR~
UTRACEP("utfcvf2l utfgetwc rc=%d,ucs4=%04x,chklen=%d\n",rcutf,ucs4,chklen);//~v62vI~//~v6t3R~//~v6ueR~//~v6BjR~
UTRACED("utfcvf2l utfgetwc",pc,chklen);                            //~v6t3I~
        if (!rcutf)                                                //~v61bI~
        {                                                          //~v620I~
#ifdef UTF8SUPPH                                                 //~v620R~//~v62xR~
//          if (ucvext_iconvucs2local1(0,Spconverters,ucs,pco,&len))//~v620R~//~v62xR~
//  		if (utfcvu2lany1mb(0,ucs,pco,&len))                    //~v62xI~//~v62ER~
//  		if (utfcvu2lany1mb(Popt,ucs,pco,&len))                 //~v62EI~//~v6BjR~
    		if (utfcvu2lany1mb(Popt,(UWUCS)ucs4,pco,&len))         //~v6BjI~
//*under the condition ucs4 is ucs2                                //~v6uBI~
            {                                                      //~v644I~
	          	len=-1;                                          //~v620R~//~v62xR~
#ifdef UTF8UCS2                                                    //~v644I~
				errchsz=0;                                         //~v644I~
                utfgetwcw(UTFGWCWO_INPUTUCS,pc,0/*len*/,&ucs4,0/*chklen*/,&errchsz);//~v644R~
#endif                                                             //~v644I~
            }                                                      //~v644I~
#else                                                            //~v620R~//~v62xR~
	    	len=wctomb(pco,ucs);                                   //~v61bI~
UTRACEP("utfcvf2l wctomb len=%d, out=%02x%02x%02x\n",len,*pco,(chklen>1?*(pco+1):0),(chklen>2?*(pco+2):0));//~v62vI~
#endif                                                           //~v620R~//~v62xR~
        }                                                          //~v620I~
//      }//!surrogate pair                                           //~v6ueI~//~v6BjR~
        if (rcutf||len<=0) //utf8 err                              //~v61bI~
        {                                                          //~v61bI~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v61bR~
            {                                                      //~v61bI~
            	rc=UTFCVRC_ERRSTOP;     //8                        //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
//#ifdef W32UNICODE                                                  //~v6ueI~//~v6uBR~
//          if (errchsz==4    //ucs4 id surrogateH+L                 //~v6ueI~//~v6uBR~
//          &&  Popt & UTFCVO_ERRREP)  //replace err                 //~v6ueR~//~v6uBR~
//          {                                                        //~v6ueI~//~v6uBR~
//             *pco++=repch;                                         //~v6ueI~//~v6uBR~
//             *pco++=repch;                                         //~v6ueI~//~v6uBR~
//             utf_setsubchar_dbcs(0,pco-2);  //set dbcs errrep if avail//~v6ueI~//~v6uBR~
//             *pco++=repch;     //for surrogate Low                 //~v6ueI~//~v6uBR~
//             *pco++=repch;                                         //~v6ueI~//~v6uBR~
//             utf_setsubchar_dbcs(0,pco-2);  //set dbcs errrep if avail//~v6ueI~//~v6uBR~
//             charwidth+=4;                                         //~v6ueI~//~v6uBR~
//             offs+=4;                                              //~v6ueR~//~v6uBR~
//             rc|=UTFCVRC_ERR;         //4                          //~v6ueI~//~v6uBR~
//          }                                                        //~v6ueI~//~v6uBR~
//          else                                                     //~v6ueI~//~v6uBR~
//#endif                                                             //~v6ueI~//~v6uBR~
          {                                                        //~v6ueI~
        	if (Popt & UTFCVO_ERRREP)  //replace err               //~v61bR~
	            *pco++=repch;                                      //~v61bI~
            else                                                   //~v61bI~
	            *pco++=*pc;                                        //~v61bI~
            rc|=UTFCVRC_ERR;         //4                           //~v61bR~
#ifdef UTF8UCS2                                                    //~v644I~
          if (!rcutf	//f2u ok                                   //~v644R~
          &&  (Popt & UTFCVO_ERRREP)  //replace err                //~v644I~
          )                                                        //~v644I~
          {                                                        //~v644I~
//*get ddlen to errchsz fo also combining(width=0) char            //~v6VjI~
//          if (errchsz<0 && Popt & UTFCVO_ERRREPDBCS)  //set dbcs subchar//~v6T4I~//~v6VjR~
            {                                                      //~v6T4I~
            	UCHAR wkdd[8],wkdddbcs[8];                         //~v6T4I~
            //**********************  	                           //~v6T4I~
				utfcvf2dd(0,pc,chklen,wkdd,wkdddbcs,(int)sizeof(wkdd),&errchsz);//~v6T4I~
            }                                                      //~v6T4I~
          	if (errchsz==2)	//u2l err ucs is dbcs                  //~v644R~
            {                                                      //~v644I~
	            *pco++=repch;                                      //~v644I~
				utf_setsubchar_dbcs(0,pco-2);	//set dbcs errrep if avail//~v66eI~
                charwidth++;                                       //~v66eI~
                offs++;                                            //~v644I~
            }                                                      //~v644I~
          }                                                        //~v644I~
          else                                                     //~v644I~
#endif                                                             //~v644I~
            chklen=1;                                              //~v61bI~
            offs++;                                                //~v61bI~
            charwidth++;                                           //~v66eI~
                                                                   //~v6ueI~
          }//errchsz!=4                                            //~v6ueI~
        }                                                          //~v61bI~
        else                                                       //~v61bI~
        {                                                          //~v61bI~
            pco+=len;                                              //~v61bI~
            offs+=len;                                             //~v61bI~
            if (dbcschksw)	//requested                            //~v61bI~
            {                                                      //~v61bI~
//          	if (utfiswide(0,ucs))                              //~v5m0R~
//          	if (utfiswide(0,(ULONG)ucs))                       //~v5m0R~//~v6BjR~
            	if (utfiswide(0,(ULONG)ucs4))                      //~v6BjI~
//*under the condition ucs is ucs2(len<0 for ucs4)                 //~v6uBI~
                	charwidth+=2;                                  //~v61bI~
                else                                               //~v61bI~
                	charwidth++;                                   //~v61bI~
            }                                                      //~v61bI~
        }                                                          //~v61bI~
    }                                                              //~v61bI~
//	readlen=(int)((ULONG)pc-(ULONG)Pinp);                          //~v61bI~//~v6hhR~
	readlen=(int)((ULPTR)pc-(ULPTR)Pinp);                          //~v6hhI~
    if (Ppchklen)                                                  //~v61bI~
	    *Ppchklen=readlen;                                         //~v61bI~
    if (Ppoutlen)                                                  //~v61bI~
	    *Ppoutlen=offs;                                            //~v61bI~
    if (Ppcharwidth)	//requested                                //~v61bI~
    	*Ppcharwidth=charwidth;                                    //~v61bI~
    if (asciisw && !rc)                                            //~v61bI~
    	rc=UTFCVRC_ALLASCII;                                       //~v61bR~
UTRACED("utff2l inp",Pinp,Pinplen);                                //~v61bR~
UTRACED("utff2l out",Pout,offs);                                   //~v61bR~
    return rc;                                                     //~v61bI~
}//utfcvf2l                                                         //~v61bI~//~v620R~
#ifdef LNX                                                         //~v61uI~
//**************************************************************** //~v61bI~
//!utfcvf2lany:LNX && !LOCALICU()                                  //~v6uMR~
//locale<-utf8 conversion by iconv                                 //~v61bI~
//rc:err                                                           //~v61gR~
//**************************************************************** //~v61bI~
int utfcvf2lany(int Popt,char *Pplocale,char *Pout,char *Pinp,int Pinplen,//~v61bI~
			int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth)//~v61bI~
{                                                                  //~v61bI~
    iconv_t hiconv;                                                //~v61bI~
    char *pci,*pco,*pci2;                                          //~v61bR~
//  int rc=0,rciconv,reslen,outreslen,outmax=0x7fff,repch,charwidth,charcnt,ucscnt,writelen,readlen;//~v61bI~//~v62tR~//~v6haR~
    int rc=0,rciconv,reslen,outreslen,outmax=0x7fff,repch,charwidth=0,charcnt=0,ucscnt,writelen,readlen;//~v6haR~
//  int outreslen2,ii,asciisw,convlen,width,convlen2,outlen;       //~v624R~
    int /*ii,*/asciisw,convlen,width,outlen;                       //~v6uMR~
    size_t outreslen2,convlen2;                                    //~v624R~
#ifdef UTF8UCS2                                                    //~v644I~
	int utfchsz;                                                   //~v644I~
	ULONG ucs;                                                     //~v644I~
#endif                                                             //~v644I~
	int swhankana;                                                 //~v6uMI~
//****************************                                     //~v61bI~
	if (utfcvlocaleopen(0/*fromUTF8*/,Pplocale,&hiconv))           //~v61bI~
    {                                                              //~v6b4I~
        if (Ppchklen)                                              //~v6b4I~
            *Ppchklen=1;                                           //~v6b4I~
        if (Ppoutlen)                                              //~v6b4I~
            *Ppoutlen=1;                                           //~v6b4I~
        if (Ppcharcnt)                                             //~v6b4I~
            *Ppcharcnt=1;                                          //~v6b4I~
        if (Ppcharwidth)    //requested                            //~v6b4I~
            *Ppcharwidth=1;                                        //~v6b4I~
        *Pout='?';                                                 //~v6b4I~
    	return UTFCVRC_SEVERR;                                     //~v61bI~
    }                                                              //~v6b4I~
	repch=(Popt & UTFCVO_REPCH)>>8;                                //~v61bR~
    outreslen=outmax;                                              //~v61bI~
	for (reslen=Pinplen,pci=Pinp,pco=Pout;reslen>0;)               //~v61bI~
    {                                                              //~v61bI~
      	if (UTF8ISASCII(*pci))                                     //~v61bI~
      	{                                                          //~v61bI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v61bR~
            {                                                      //~v61bI~
    			rc|=UTFCVRC_ASCIIRET;                              //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
            *pco++=*pci++;                                         //~v61bI~
            reslen--;                                              //~v61bI~
            outreslen--;                                           //~v61bI~
            charcnt++;                                             //~v61bI~
            charwidth++;                                           //~v61bI~
            continue;                                              //~v61bI~
      	}                                                          //~v61bI~
        asciisw=0;                                                 //~v61bI~
        swhankana=0;                                               //~v6uMI~
	  if (UTF8_IS80FF(*pci))	//0x80<-->0xff                     //~v6uMI~
      {                                                            //~v6uMI~
      	swhankana=1;                                               //~v6uMI~
        convlen=2;                                                 //~v6uMI~
      }                                                            //~v6uMI~
      else                                                         //~v6uMI~
      {                                                            //~v6uMI~
//        if (Popt & UTFCVO_ASCIIRET)                              //~v6uMR~
//        {                                                        //~v6uMR~
//            for (ii=reslen,pci2=pci;ii>0;ii--,pci2++)            //~v6uMR~
//                if (UTF8ISASCII(*pci2))                          //~v6uMR~
//                    break;                                       //~v6uMR~
//            convlen=reslen-ii;                                   //~v6uMR~
//        }                                                        //~v6uMR~
//        else                                                     //~v6uMR~
//            convlen=reslen;                                      //~v6uMR~
		convlen=utfgetstrlenHK(Popt,pci,reslen);                   //~v6uMI~
      }                                                            //~v6uMI~
//      convlen2=convlen;                                          //~v61bI~//~v6BkR~
        convlen2=(size_t)convlen;                                  //~v6BkI~
//      outreslen2=outreslen;                                      //~v61bI~//~v6BkR~
        outreslen2=(size_t)outreslen;                              //~v6BkI~
        pci2=pci;                                                  //~v61bI~
//      rciconv=iconv(hiconv,&pci,&convlen2,&pco,&outreslen2);     //~v5ncI~
//      rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&convlen2,&pco,&outreslen2);//~v5ncR~//~v5nDR~
//      rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen2),&pco,ICONV_SZTYPE(&outreslen2));//~v5nDI~//~v6BkR~
        rciconv=(int)iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen2),&pco,ICONV_SZTYPE(&outreslen2));//~v6BkI~
//      readlen=convlen-convlen2;                                  //~v61bI~//~v6BkR~
        readlen=convlen-(int)convlen2;                             //~v6BkI~
//      writelen=outreslen-outreslen2;                             //~v61bI~//~v6BkR~
        writelen=outreslen-(int)outreslen2;                        //~v6BkI~
UTRACEP("utff2lany rciconv=%d\n",rciconv);                         //~v62tI~//~v6uMM~
UTRACED("utff2lany iconvin",pci-readlen,readlen);                  //~v62tI~//~v6uMM~
UTRACED("utff2lany iconvout",pco-writelen,writelen);               //~v62tI~//~v6uMM~
        if (swhankana && !rciconv && writelen>2)                   //~v6uMM~
        {                                                          //~v6uMM~
        	rciconv=-1;                                            //~v6uMM~
            pco-=writelen;                                         //~v6uMI~
            pci-=readlen;                                          //~v6uMI~
//          outreslen2=outreslen;//ignore 3 byte output            //~v6uMM~//~v6BkR~
            outreslen2=(size_t)outreslen;//ignore 3 byte output    //~v6BkI~
            writelen=0;                                            //~v6uMM~
            readlen=0;                                             //~v6uMI~
            swhankana=2;                                           //~v6uMM~
        }                                                          //~v6uMM~
        reslen-=readlen;                                           //~v61bI~
//      outreslen=outreslen2;                                      //~v61bI~//~v6BkR~
        outreslen=(int)outreslen2;                                 //~v6BkI~
        if (writelen && (Ppcharcnt||Ppcharwidth)) //required count char/width//~v61bI~
        {                                                          //~v61bI~
            utfcvf2u(0,0/*outucs*/,pci2,0/*chof*/,0/*dbcs*/,0/*initoffs*/,readlen,0/*readlen*/,&ucscnt,&width);//~v61bR~
            charwidth+=width;                                      //~v61bI~
            charcnt+=ucscnt;                                       //~v61bI~
        }                                                          //~v61bI~
        if (rciconv==(size_t)-1)	//conv err                     //~v61bI~
        {                                                          //~v61bI~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v61bR~
            {                                                      //~v61bI~
            	rc=UTFCVRC_ERRSTOP;     //8                        //~v61bR~
            	break;                                             //~v61bI~
            }                                                      //~v61bI~
        	if (Popt & UTFCVO_ERRREP)  //replace err               //~v61bR~
            {                                                      //~v644I~
//              *pco++=repch;                                      //~v61bI~//~v6BkR~
                *pco++=(char)repch;                                //~v6BkI~
#ifdef UTF8UCS2                                                    //~v644I~
                if (!utfgetwcw(0,pci,reslen,&ucs,&utfchsz,&width)) //~v644R~
                {                                                  //~v644I~
                	if (width==2)	//dbcs                         //~v644R~
                    {                                              //~v644I~
//                  	*pco++=repch;                              //~v644I~//~v6BkR~
                    	*pco++=(char)repch;                        //~v6BkI~
						utf_setsubchar_dbcs(0,pco-2);	//set dbcs errrep if avail//~v66eI~
                        outreslen--;                               //~v644I~
                        charwidth++;                               //~v644I~
                    }                                              //~v644I~
                    pci+=(utfchsz-1);                              //~v644I~
                    reslen-=(utfchsz-1);                           //~v644I~
                }                                                  //~v644I~
#endif                                                             //~v644I~
			}                                                      //~v644I~
            else                                                   //~v61bI~
	            *pco++=*pci;                                       //~v61bI~
            rc|=UTFCVRC_ERR;         //4                           //~v61bR~
            pci++;                                                 //~v61bI~
            reslen--;                                              //~v61bI~
            outreslen--;                                           //~v61bI~
            charcnt++;                                             //~v61bI~
            charwidth++;                                           //~v61bI~
        }                                                          //~v61bI~
    }                                                              //~v61bI~
	utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gR~
	outlen=(int)((ULONG)pco-(ULONG)Pout);                          //~v61bI~
	readlen=(int)((ULONG)pci-(ULONG)Pinp);                         //~v61bI~
    if (Ppchklen)                                                  //~v61bI~
	    *Ppchklen=readlen;                                         //~v61bI~
    if (Ppoutlen)                                                  //~v61bI~
	    *Ppoutlen=outlen;                                          //~v61bI~
    if (Ppcharcnt)                                                 //~v61bI~
	    *Ppcharcnt=charcnt;                                        //~v61bI~
    if (Ppcharwidth)	//requested                                //~v61bI~
    	*Ppcharwidth=charwidth;                                    //~v61bI~
    if (asciisw && !rc)                                            //~v61bI~
    	rc=UTFCVRC_ALLASCII;                                       //~v61bR~
UTRACEP("utff2lany rc=%d\n",rc);                                //~v61bR~//~v62tR~
UTRACED("utff2l inp",Pinp,Pinplen);                                //~v62tI~
UTRACED("utff2l out",Pout,outlen);                                 //~v61bR~
    return rc;                                                      //~v61bI~//~v62tR~
}//utfcvf2lany                                                     //~v61bI~
#endif //LNX                                                       //~v61bI~
//**************************************************************** //~v61gM~
//!utfcvl2fany1                                                    //~v61gR~
//locale->utf8 conversion by iconv                                 //~v61gM~
//Warning:trans all input char(not only 1 char)                    //~v62NI~
//**************************************************************** //~v61gM~
//int utfcvl2fany1(int Popt,char *Pplocale,ULONG *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v61gM~//~v6hhR~
int utfcvl2fany1(int Popt,char *Pplocale,ULPTR *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6hhI~
			int *Ppchklen,int *Ppoutlen)                           //~v61gM~
{                                                                  //~v61gM~
#ifdef W32                                                         //~v61gI~
	return utfcvl2fany1mb(Popt,Poututf8,Poutbufflen,Pinp,Pinplen,Ppchklen,Ppoutlen);//~v61gR~
#else                                                              //~v61gI~
    iconv_t hiconv;                                                //~v61gM~
    char *pci,*pco;                                                //~v61gM~
//  int rc=0,readlen=1,outmax,writelen=1,rciconv,reslen,outreslen; //~v624R~
    int rc=0,readlen=1,outmax,writelen=1,/*rciconv,*/reslen;           //~v624R~//~v6b9R~
//  int convlen,rcerrno;                                           //~v624R~
    int rcerrno;                                                   //~v624R~
    size_t convlen,outreslen;                                      //~v624R~
//****************************                                     //~v61gM~
    if (!UTF8MODEICONV())	//env is not utf8,use mb2wc api        //~v61gR~
    {                                                              //~v61gI~
    	if (Pphandle)                                              //~v61gI~
        	*Pphandle=0;	//notify !UTF8ENV                      //~v61gI~
		return utfcvl2fany1mb(Popt,Poututf8,Poutbufflen,Pinp,Pinplen,Ppchklen,Ppoutlen);//~v61gR~
    }                                                              //~v61gI~
	if (Pphandle && *Pphandle)                                     //~v61gM~
    	hiconv=*(iconv_t*)Pphandle;                                //~v61gM~
    else                                                           //~v61gM~
    {                                                              //~v61gM~
		if (utfcvlocaleopen(UTFCVO_2UTF,Pplocale,&hiconv))         //~v61gM~
        {                                                          //~v6b4I~
            if (Ppchklen)                                          //~v6b4I~
                *Ppchklen=1;                                       //~v6b4I~
            if (Ppoutlen)                                          //~v6b4I~
                *Ppoutlen=1;                                       //~v6b4I~
            *Poututf8='?';                                         //~v6b4I~
    		return UTFCVRC_SEVERR;                                 //~v61gM~
        }                                                          //~v6b4I~
        if (Pphandle)                                              //~v61gM~
        	*Pphandle=(ULONG)hiconv;                               //~v61gM~
    }                                                              //~v61gM~
	reslen=Pinplen;                                                //~v61gM~
	outmax=Poutbufflen;                                            //~v61gM~
	pci=Pinp;                                                      //~v61gM~
	pco=Poututf8;                                                  //~v61gM~
//  convlen=reslen;                                                //~v61gM~//~v6BkR~
    convlen=(size_t)reslen;                                        //~v6BkI~
//  outreslen=outmax;                                              //~v61gM~//~v6BkR~
    outreslen=(size_t)outmax;                                      //~v6BkI~
//  rciconv=iconv(hiconv,&pci,&convlen,&pco,&outreslen);           //~v5ncI~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&convlen,&pco,&outreslen);//~v5ncR~//~v5nDR~
    /*rciconv=*/iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen),&pco,ICONV_SZTYPE(&outreslen));//~v5nDI~//~v6b9R~
    rcerrno=errno;                                                 //~v61gM~
//  if (rciconv==(size_t)-1)    //conv err                         //~v61gM~//~v62NR~
    if (outreslen==outmax)    //no translation                     //~v62NR~
    {                                                              //~v61gM~
        if (rcerrno==E2BIG)   //output buff shortage               //~v61gM~
            rc=UTFCVRC_ERROVF;                                     //~v61gM~
        else                                                       //~v61gM~
            rc=UTFCVRC_ERRSTOP;                                    //~v61gM~
    }                                                              //~v61gM~
//  readlen=reslen-convlen;                                        //~v61gM~//~v6BkR~
    readlen=reslen-(int)convlen;                                   //~v6BkI~
//  writelen=outmax-outreslen;                                     //~v61gM~//~v6BkR~
    writelen=outmax-(int)outreslen;                                //~v6BkI~
    if (Popt & UTFCVO_TCLOSE)                                      //~v61gM~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gM~
    if (Ppchklen)                                                  //~v61gM~
	    *Ppchklen=readlen;                                         //~v61gM~
    if (Ppoutlen)                                                  //~v61gM~
	    *Ppoutlen=writelen;                                        //~v61gM~
    return rc;                                                     //~v61gM~
#endif	//LNX                                                      //~v61gI~
}//utfcvl2fany1                                                    //~v61gM~
//**************************************************************** //~v61gI~
//!utfcvl2fany1mb                                                  //~v61gI~
//locale->utf8 conversion by mb2wc                                 //~v61gI~
//ret:ovf,errstop sev err                                          //~v61gI~
//**************************************************************** //~v61gI~
int utfcvl2fany1mb(int Popt,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v61gI~
			int *Ppchklen,int *Ppoutlen)                           //~v61gI~
{                                                                  //~v61gI~
//  int chklen,rc=0,outlen;                                        //~v6h4R~
    int chklen=0,rc=0,outlen=0;                                    //~v6h4I~
//  wchar_t ucs;                                                   //~v61gI~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
    UWUCS   ucs;                                                   //~v6BjI~
    char utfwk[UTF8_MAXCHARSZMAX];                                 //~v61gR~
//#ifdef UTF8SUPPH                                                 //~v620R~
//    int udbcschkrc,opt;                                          //~v620R~
//    USHORT usucs;                                                //~v620R~
//#endif                                                           //~v620R~
//**********************                                           //~v61gI~
	if (UTF8ISASCII(*Pinp))                                        //~v61gI~
    {                                                              //~v61gI~
	    if (Poutbufflen<1)                                         //~v61gI~
    		rc=UTFCVRC_ERROVF;                                     //~v61gI~
        else                                                       //~v61gI~
        {                                                          //~v61gI~
        	*Poututf8=*Pinp;                                       //~v61gI~
	      	chklen=1;                                              //~v61gI~
    	    outlen=1;                                              //~v61gI~
        }                                                          //~v61gI~
    }                                                              //~v61gI~
    else                                                           //~v61gI~
    {                                                              //~v61gI~
//#ifdef UTF8SUPPH                                                 //~v620R~
//        chklen=udbcschk_getmblen(0,Pinp);                        //~v620R~
//        chklen=min(chklen,Pinplen);                              //~v620R~
//        opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v620R~
//        udbcschkrc=ucvext_iconvlocal2ucs1(opt,(ULONG)Spconverters,Pinp,chklen,0/*chklen output*/,&usucs);//~v620R~
//        if (udbcschkrc)                                          //~v620R~
//            chklen=-1;                                           //~v620R~
//        ucs=(wchar_t)usucs;                                      //~v620R~
//#else                                                            //~v620R~
#ifdef UTF8SUPPH                                                   //~v62hI~
//  	chklen=umbtowc(&ucs,Pinp,Pinplen);                         //~v62hI~//~v62xR~
//  	chklen=utfcvl2uany1mb(0,Pinp,Pinplen,&ucs);                //~v62xR~//~v6unR~
    	chklen=utfcvl2uany1mb(0,Pinp,Pinplen,&ucs,NULL/*rc*/);     //~v6unI~
#else                                                              //~v62hI~
    	chklen=mbtowc(&ucs,Pinp,Pinplen);                          //~v61gI~
#endif                                                             //~v62hI~
//#endif                                                           //~v620R~
	    if (chklen<=0)                                             //~v61gI~
    		rc=UTFCVRC_ERRSTOP;                                    //~v61gI~
        else                                                       //~v61gI~
        {                                                          //~v61gI~
//      	outlen=uccvucs2utf((ULONG)ucs,utfwk);                  //~v61gI~//~v6BkR~
        	outlen=uccvucs2utf((UWUCS)ucs,utfwk);                  //~v6BkI~
    		if (outlen>Poutbufflen)                                //~v61gI~
    			rc=UTFCVRC_ERROVF;                                 //~v61gI~
    		else                                                   //~v61gI~
            	memcpy(Poututf8,utfwk,(UINT)outlen);               //~v61gR~
        }                                                          //~v61gI~
    }                                                              //~v61gI~
    if (rc)                                                        //~v61gI~
    	chklen=outlen=0;                                           //~v61gI~
    if (Ppchklen)                                                  //~v61gI~
	    *Ppchklen=chklen;                                          //~v61gI~
    if (Ppoutlen)                                                  //~v61gI~
	    *Ppoutlen=outlen;                                          //~v61gI~
    return rc;                                                     //~v61gI~
}//utfcvl2fany1mb                                                  //~v61gI~
#ifdef UTF8SUPPH                                                   //~v62xI~
//**************************************************************** //~v62xI~
//!utfcvl2uany1mb                                                  //~v62xI~
//locale->ucs  conversion by mb2wc                                 //~v62xI~
//return chklen,<=0 if err                                         //~v62xI~
//rc:subchrc or 4                                                  //~v6unI~
//**************************************************************** //~v62xI~//~v6a0R~
//int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,wchar_t *Ppucs) //~v62xI~//~v6a0R~
//int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,UWCHART *Ppucs,int *Pprc) //~v6a0I~//~v6unR~//~v6BjR~
int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,UWUCS *Ppucs,int *Pprc)//~v6BjI~
{                                                                  //~v62xI~
	int chklen;                                                    //~v62xR~
//  wchar_t ucs;                                                   //~v62xI~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
    UWUCS   ucs;                                                   //~v6BjI~
	int udbcschkrc,opt;                                            //~v62xI~
	UWUCS  ucs4;                                                   //~v6f3M~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6BjR~
//    WUCS   usucs;                                                  //~v65cI~//~v6BjR~
//#else                                                              //~v65cI~//~v6BjR~
//    USHORT usucs;                                                  //~v62xI~//~v6BjR~
//#endif                                                             //~v65cI~//~v6BjR~
	int rc=0;                                                      //~v6unI~
//**********************                                           //~v62xI~
UTRACEP("utfcvl2uany1mb inp=%x,len=%x,Sconverters=%p\n",*Pinp,Pinplen,Spconverters);//~v62xI~
	if (UTF8ISASCII(*Pinp))                                        //~v62xI~
    {                                                              //~v62xI~
//  	ucs=(wchar_t)*Pinp;                                        //~v62xI~//~v6a0R~
//  	ucs=(UWCHART)*Pinp;                                        //~v6a0I~//~v6BjR~
    	ucs=(UWUCS)*Pinp;                                          //~v6BjI~
	    chklen=1;                                                  //~v62xI~
    }                                                              //~v62xI~
    else                                                           //~v62xI~
    {                                                              //~v62xI~
        if (!Spconverters)                                         //~v62xR~
        {                                                          //~v62xI~
    		chklen=umbtowc(&ucs,Pinp,Pinplen);                     //~v62xI~
		}                                                          //~v62xI~
        else                                                       //~v62xI~
        {                                                          //~v62xI~
//  		chklen=udbcschk_getmblen(0,Pinp);                      //~v62UR~
    		udbcschk_getmblen(0,Pinp,Pinplen,&chklen);             //~v62UR~
			chklen=min(chklen,Pinplen);                            //~v62xI~
          if (UDBCSCHK_IS_LOCALICU())                              //~v6f3R~
          {                                                        //~v6f3I~
			opt=0;                                                 //~v6f3I~
//  		udbcschkrc=ucvext_icumb2ucs1(opt,*(ULONG*)Spconverters,Pinp,chklen,0/*chklen output*/,&ucs4);//~v6f3R~//~v6hhR~
    		udbcschkrc=ucvext_icumb2ucs1(opt,*(ULPTR*)Spconverters,Pinp,chklen,0/*chklen output*/,&ucs4);//~v6hhI~
//          usucs=ucs4;                                            //~v6f3I~//~v6BjR~
            ucs=ucs4;                                              //~v6BjI~
          }                                                        //~v6f3I~
          else                                                     //~v6f3I~
          {                                                        //~v6f3I~
			opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v62xI~
#ifdef W32UNICODE                                                  //~v6unR~
            if (Popt & UTFCVO_ALLOWSUBCH)                          //~v6unR~
				opt|=EBC2ASC_EXT_SETSUBCHRC;                       //~v6unR~
#endif                                                             //~v6unR~
//  		udbcschkrc=ucvext_iconvlocal2ucs1(opt,(ULONG)Spconverters,Pinp,chklen,0/*chklen output*/,&usucs);//~v62xI~//~v6hhR~
//  		udbcschkrc=ucvext_iconvlocal2ucs1(opt,(ULPTR)Spconverters,Pinp,chklen,0/*chklen output*/,&usucs);//~v6hhI~//~v6BjR~
    		udbcschkrc=ucvext_iconvlocal2ucs1(opt,(ULPTR)Spconverters,Pinp,chklen,0/*chklen output*/,&ucs4);//~v6BjR~
          }                                                        //~v6f3I~
#ifdef W32UNICODE                                                  //~v6unI~
    	  if (udbcschkrc==UCVEXTRC_SUBCH)                          //~v6unI~
    	  	rc=UCVEXTRC_SUBCH;                                     //~v6unI~
          else                                                     //~v6unI~
#endif                                                             //~v6unI~
			if (udbcschkrc)                                        //~v62xI~
            {                                                      //~v6unI~
				chklen=-1;                                         //~v62xI~
                rc=4;                                              //~v6unI~
            }                                                      //~v6unI~
//			ucs=(wchar_t)usucs;                                    //~v62xI~//~v6a0R~
//			ucs=(UWCHART)usucs;                                    //~v6a0I~//~v6BjR~
  			ucs=ucs4;                                              //~v6BjI~
		}                                                          //~v62xI~
    }                                                              //~v62xI~
    *Ppucs=ucs;                                                    //~v62xI~
UTRACEP("utfcvl2uany1mb rc=chklen=%d,ucs=%04x\n",chklen,ucs);      //~v66nI~
	if (Pprc)                                                      //~v6unI~
    	*Pprc=rc;                                                  //~v6unI~
    return chklen;                                                 //~v62xI~
}//utfcvl2uany1mb                                                  //~v62xI~
#endif                                                             //~v62xI~
//**************************************************************** //~v61gM~
//!utfcvf2lany1   using iconv                                      //~v61gR~
//locale<-utf8 conversion by iconv                                 //~v61gM~
//Warning:do translation not only 1 char but all                   //~v62NI~
//rc:err                                                           //~v61gM~
//**************************************************************** //~v61gM~
//int utfcvf2lany1(int Popt,char *Pplocale,ULONG *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5R~
int utfcvf2lany1(int Popt,char *Pplocale,ULPTR *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5I~
			int *Ppchklen,int *Ppoutlen)                           //~v61gM~
{                                                                  //~v61gM~
#ifdef W32                                                         //~v61gI~
	return utfcvf2lany1mb(Popt,Pout,Poutbufflen,Pinp,Pinplen,Ppchklen,Ppoutlen);//~v61gI~
#else                                                              //~v61gI~
    iconv_t hiconv;                                                //~v61gM~
    char *pci,*pco;                                                //~v61gM~
//  int rc=0,readlen=1,writelen=1,rciconv,reslen,outreslen,outmax=0x7fff;//~v624R~
    int rc=0,readlen=1,writelen=1,/*rciconv,*/reslen,outmax=0x7fff;    //~v624R~//~v6b9R~
//  int convlen,rcerrno;                                           //~v624R~
    int rcerrno;                                                   //~v624R~
    size_t outreslen,convlen;                                      //~v624R~
    int utf8chsz,rciconv,convlensv;                                //~v6uRI~
    int swhankana;                                                 //~v6uMI~
//****************************                                     //~v61gM~
    UTRACED("inp",Pinp,Pinplen);                                   //~v6uMI~
#ifdef UTF8SUPPH                                                   //~v620I~
  if (UTF8ISASCII(*Pinp))                                          //~v620I~
  {                                                                //~v620I~
	    if (Poutbufflen<1)                                         //~v620I~
    		rc=UTFCVRC_ERROVF;                                     //~v620I~
        else                                                       //~v620I~
        {                                                          //~v620I~
        	*Pout=*Pinp;                                           //~v620R~
	      	readlen=1;                                             //~v620R~
    	    writelen=1;                                            //~v620R~
        }                                                          //~v620I~
  }                                                                //~v620I~
  else                                                             //~v620I~
  {                                                                //~v620I~
#endif                                                             //~v620I~
    if (!UTF8MODEICONV())	//env is not utf8,use mb2wc api        //~v61gR~
    {                                                              //~v61gI~
    	if (Pphandle)                                              //~v61gI~
        	*Pphandle=0;	//notify !UTF8ENV                      //~v61gI~
		return utfcvf2lany1mb(Popt,Pout,Poutbufflen,Pinp,Pinplen,Ppchklen,Ppoutlen);//~v61gI~
    }                                                              //~v61gI~
	if (Pphandle && *Pphandle)                                     //~v61gM~
    	hiconv=*(iconv_t*)Pphandle;                                //~v61gM~
    else                                                           //~v61gM~
    {                                                              //~v61gM~
		if (utfcvlocaleopen(0/*fromUTF8*/,Pplocale,&hiconv))       //~v61gM~
        {                                                          //~v6b4I~
            if (Ppchklen)                                          //~v6b4I~
                *Ppchklen=1;                                       //~v6b4I~
            if (Ppoutlen)                                          //~v6b4I~
                *Ppoutlen=1;                                       //~v6b4I~
            *Pout='?';                                             //~v6b4I~
    		return UTFCVRC_SEVERR;                                 //~v61gM~
        }                                                          //~v6b4I~
        if (Pphandle)                                              //~v61gM~
        	*Pphandle=(ULONG)hiconv;                               //~v61gM~
    }                                                              //~v61gM~
	pci=Pinp;                                                      //~v61gM~
	pco=Pout;                                                      //~v61gM~
    outmax=Poutbufflen;                                            //~v61gM~
//  outreslen=outmax;                                              //~v61gM~//~v6BkR~
    outreslen=(size_t)outmax;                                      //~v6BkI~
    reslen=Pinplen;                                                //~v61gM~
//  convlen=reslen;                                                //~v61gM~//~v6BkR~
    convlen=(size_t)reslen;                                        //~v6BkI~
    utf8chsz=UTF8CHARLENERR1(*pci); //1 if err utf8                //~v6uRM~
//  convlen=min(convlen,utf8chsz);                                 //~v6uRM~//~v6BkR~
    convlen=min(convlen,(size_t)utf8chsz);                         //~v6BkR~
	swhankana=(convlen==2 && UTF8_IS80FF(*pci));	//0x80<-->0xff //~v6uMI~
//  convlensv=convlen;                                             //~v6uRI~//~v6BkR~
    convlensv=(int)convlen;                                        //~v6BkI~
//  rciconv=iconv(hiconv,&pci,&convlen,&pco,&outreslen);           //~v5ncI~
//  rciconv=iconv(hiconv,ICONV_PCTYPE(&pci),&convlen,&pco,&outreslen);//~v5ncR~//~v5nDR~
  rciconv=                                                         //~v6uRM~
//  /*rciconv=*/iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen),&pco,ICONV_SZTYPE(&outreslen));//~v5nDI~//~v6b9R~//~v6BkR~
    /*rciconv=*/(int)iconv(hiconv,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&convlen),&pco,ICONV_SZTYPE(&outreslen));//~v6BkI~
    rcerrno=errno;                                                 //~v61gM~
//  if (rciconv==(size_t)-1)    //conv err                         //~v61gM~//~v62NR~
    if (outreslen==outmax)    //conv err                           //~v62NI~
    {                                                              //~v61gM~
        if (rcerrno==E2BIG)   //output buff shortage               //~v61gM~
            rc=UTFCVRC_ERROVF;                                     //~v61gM~
        else                                                       //~v61gM~
            rc=UTFCVRC_ERRSTOP;                                    //~v61gM~
    }                                                              //~v61gM~
//  readlen=reslen-convlen;                                        //~v61gM~//~v6uRR~
//  readlen=convlensv-convlen;                                     //~v6uRI~//~v6BkR~
    readlen=convlensv-(int)convlen;                                //~v6BkI~
//  writelen=outmax-outreslen;                                     //~v61gM~//~v6BkR~
    writelen=outmax-(int)outreslen;                                //~v6BkI~
    UTRACEP("%s:rciconv=%d,readlen=%d,writelen=%d\n",UTT,rciconv,readlen,writelen);//~v6uMR~
    if (swhankana && (rciconv || writelen>2))                      //~v6uMR~
    {                                                              //~v6uMM~
    	readlen=2;                                                 //~v6uMI~
        writelen=0;                                                //~v6uMI~
        rc=UTFCVRC_ERR;		//ucvsutf2mb set rep char              //~v6uMM~
    }                                                              //~v6uMM~
#ifdef UTF8SUPPH                                                   //~v620I~
  }                                                                //~v620I~
#endif                                                             //~v620I~
    if (Popt & UTFCVO_TCLOSE)                                      //~v61gM~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gM~
    if (Ppchklen)                                                  //~v61gM~
	    *Ppchklen=readlen;                                         //~v61gM~
    if (Ppoutlen)                                                  //~v61gM~
	    *Ppoutlen=writelen;                                        //~v61gM~
    return rc;                                                     //~v61gM~
#endif //LNX                                                       //~v61gI~
}//utfcvf2lany1                                                    //~v61gM~
//**************************************************************** //~v61gI~
//!utfcvf2lany1                                                    //~v61gI~
//locale<-utf8 conversion by wc2mb                                 //~v61gI~
//rc:err                                                           //~v61gI~
//**************************************************************** //~v61gI~
int utfcvf2lany1mb(int Popt,char *Poutmb,int Poutbufflen,char *Pinp,int Pinplen,//~v61gR~
			int *Ppchklen,int *Ppoutlen)                           //~v61gI~
{                                                                  //~v61gI~
//	int chklen,rc=0,outlen,rcutf;                                  //~v6h4R~
  	int chklen=0,rc=0,outlen=0,rcutf;                              //~v6h4I~
    ULONG   ucs4;                                                  //~v61gR~
//  wchar_t ucs;                                                   //~v61gI~//~v6a0R~
//  UWCHART ucs;                                                   //~v6a0I~//~v6BjR~
    char mbwk[8];                                                  //~v61gR~
//**********************                                           //~v61gI~
	if (UTF8ISASCII(*Pinp))                                        //~v61gI~
    {                                                              //~v61gI~
	    if (Poutbufflen<1)                                         //~v61gI~
    		rc=UTFCVRC_ERROVF;                                     //~v61gI~
        else                                                       //~v61gI~
        {                                                          //~v61gI~
        	*Poutmb=*Pinp;                                         //~v61gR~
	      	chklen=1;                                              //~v61gI~
    	    outlen=1;                                              //~v61gI~
        }                                                          //~v61gI~
    }                                                              //~v61gI~
    else                                                           //~v61gI~
    {                                                              //~v61gI~
        rcutf=utfgetwc(Pinp,Pinplen,&ucs4,&chklen);                //~v61gR~
        if (rcutf)                                                 //~v61gI~
            rc=UTFCVRC_ERRSTOP;     //8                            //~v61gI~
        else                                                       //~v61gI~
        {                                                          //~v61gI~
//        	ucs=(wchar_t)ucs4;                                     //~v61gR~//~v6a0R~
//        	ucs=(UWCHART)ucs4;                                     //~v6a0I~//~v6BjR~
#ifdef UTF8SUPPH                                                 //~v620R~//~v62xR~
//          if (ucvext_iconvucs2local1(0,Spconverters,ucs,mbwk,&outlen))//~v620R~//~v62xR~
//  		if (utfcvu2lany1mb(0,ucs,mbwk,&outlen))                //~v62xI~//~v6BjR~
    		if (utfcvu2lany1mb(0,(UWUCS)ucs4,mbwk,&outlen))        //~v6BjI~
                outlen=-1;                                       //~v620R~//~v62xR~
#else                                                            //~v620R~//~v62xR~
	    	outlen=wctomb(mbwk,ucs);                               //~v61gR~
#endif                                                           //~v620R~//~v62xR~
            if (outlen<=0)                                         //~v61gI~
	            rc=UTFCVRC_ERRSTOP;     //8                        //~v61gI~
            else                                                   //~v61gI~
		    if (Poutbufflen<outlen)                                //~v61gI~
    			rc=UTFCVRC_ERROVF;                                 //~v61gI~
            else                                                   //~v61gI~
            	memcpy(Poutmb,mbwk,(UINT)outlen);                  //~v61gR~
        }                                                          //~v61gI~
    }                                                              //~v61gI~
    if (rc)                                                        //~v61gI~
    	chklen=outlen=0;                                           //~v61gI~
    if (Ppchklen)                                                  //~v61gI~
	    *Ppchklen=chklen;                                          //~v61gI~
    if (Ppoutlen)                                                  //~v61gI~
	    *Ppoutlen=outlen;                                          //~v61gR~
    return rc;                                                     //~v61gI~
}//utfcvf2lany1mb                                                  //~v61gI~
#endif  //WCSUPP                                                   //~v5n8I~
//#ifdef UTF8SUPP                                                    //~v5n8I~//~v620R~
#ifdef UTF8SUPPH                                                   //~v620I~
//**************************************************************** //~v620I~
//!utfcvu2lany1                                                    //~v620I~
//ucs->locale                                                      //~v620I~
//rc:err                                                           //~v620I~
//**************************************************************** //~v620I~
//int utfcvu2lany1mb(int Popt,wchar_t Pucs,UCHAR *Pmbstr,int *Ppmbstrlen)//~v620I~//~v6a0R~
//int utfcvu2lany1mb(int Popt,UWCHART Pucs,UCHAR *Pmbstr,int *Ppmbstrlen)//~v6a0I~//~v6BjR~
int utfcvu2lany1mb(int Popt,UWUCS/*UINT4*/Pucs,UCHAR *Pmbstr,int *Ppmbstrlen)//~v6BjI~
{                                                                  //~v620I~
	int rc=0;                                                      //~v620I~
    int mblen;                                                     //~v62xI~
    int opt;                                                       //~v62EI~
    UWUCS ucs4;                                                    //~v6f3I~
//#ifdef W32                                                         //~v6BjI~//~v6BAR~
//    UWCHART wkutf16[2];                                            //~v6BjI~//~v6BAR~
//    int utf16ctr;                                                  //~v6BjI~//~v6BAR~
//#endif                                                             //~v6BjI~//~v6BAR~
//**********************                                           //~v620I~
    UTRACEP("%s:ucs=%x\n",UTT,Pucs);                               //~v6uMI~
	if (Pucs<0x80)                                                 //~v620I~
    {                                                              //~v620I~
	    *Pmbstr=(UCHAR)Pucs;                                       //~v620R~
    	*Ppmbstrlen=1;                                             //~v620I~
    }                                                              //~v620I~
    else                                                           //~v620I~
    {                                                              //~v620I~
    	if (!Spconverters)	//without wcinit                       //~v62xR~
        {                                                          //~v62xI~
#ifdef W32                                                         //~v6BjI~
//            if (Pucs>UTF_UCS2MAX)   //ucs4,use surrogateH+L        //~v6BjI~//~v6BAR~
//            {                                                      //~v6BjI~//~v6BAR~
//                UCS4_TO_UTF16(Pucs,wkutf16,&utf16ctr);             //~v6BjI~//~v6BAR~
//                mblen=wcstombs(Pmbstr,wkutf16,utf16ctr);           //~v6BjR~//~v6BAR~
//                UTRACEP("%s:Win UCS4=%x,surrogate=(%x,%x),mbstr=%s\n",UTT,Pucs,wkutf16[0],wkutf16[1],Pmbstr);//~v6BjR~//~v6BAR~
//            }                                                      //~v6BjI~//~v6BAR~
//            else                                                   //~v6BjI~//~v6BAR~
//                mblen=wctomb(Pmbstr,(UWCHART)Pucs);                //~v6BjI~//~v6BAR~
			mblen=uwctombW(0,Pucs,Pmbstr);                         //~v6BAI~
#else                                                              //~v6BjI~
	    	mblen=wctomb(Pmbstr,Pucs);                             //~v62xI~
#endif                                                             //~v6BjI~
            *Ppmbstrlen=mblen;                                     //~v62xI~
            if (mblen<=0)                                          //~v62xI~
	        	rc=4;                                              //~v62xI~
        }                                                          //~v62xI~
        else                                                       //~v62xI~
        if (UDBCSCHK_IS_LOCALICU())	//Spconverters is ICU          //~v6f3I~
        {                                                          //~v6f3I~
        	opt=UCVEXTO_SETSUBCHRC;                                                 //~v6f3I~//~v6f7R~
            ucs4=Pucs;                                             //~v6f3R~
//  		if (ucvext_icuucs2mb1(opt,*(ULONG*)Spconverters,ucs4,Pmbstr,Ppmbstrlen))//~v6f3R~//~v6f7R~
//  		if (ucvext_icuucs2mb1(opt,(ULONG*)Spconverters,ucs4,Pmbstr,Ppmbstrlen))//~v6f7I~//~v6hhR~
    		if (ucvext_icuucs2mb1(opt,(ULPTR*)Spconverters,ucs4,Pmbstr,Ppmbstrlen))//~v6hhI~
        	{                                                      //~v6f3I~
        		rc=4;                                              //~v6f3I~
        	}                                                      //~v6f3I~
        }                                                          //~v6f3I~
        else                                                       //~v6f3I~
        {                                                          //~v62EI~
        	opt=UCVEXTO_PARMUCVEXT;	//not EBC2ASC option           //~v62EI~
        	if (Popt & UTFCVO_ERRRET)  //return if err             //~v62EI~
	        	opt|=UCVEXTO_ERRRET;	//return if err            //~v62EI~
                                                                   //~v62EI~
//  	if (ucvext_iconvucs2local1(0,Spconverters,Pucs,Pmbstr,Ppmbstrlen))//~v620R~//~v62ER~
    	if (ucvext_iconvucs2local1(opt,Spconverters,Pucs,Pmbstr,Ppmbstrlen))//~v62EI~
        {                                                          //~v620I~
        	rc=4;                                                  //~v620I~
        }                                                          //~v620I~
        }                                                          //~v62EI~
    }                                                              //~v620I~
    UTRACEDCOND(!rc,"mbstr",Pmbstr,*Ppmbstrlen);                   //~v6uMR~
    return rc;                                                     //~v620I~
}//utfcvu2lany1mb                                                  //~v620I~
//**************************************************************** //~v61bI~
// utfcvlocaleinit                                                 //~v61bR~
// save locale code for l2f/f2l                                    //~v61bI~
//ret:4 err ,8:iconv open err                                      //~v61pR~
//**************************************************************** //~v61bI~
int utfcvlocaleinit(int Popt,char *Pplocale)                       //~v61bI~
{                                                                  //~v61bI~
    int rc=0;                                                      //~v61bI~
#ifdef LNX                                                         //~v5m0I~
    int rc2;                                                       //~v61pI~
#endif                                                             //~v5m0I~
//	ULONG phconv;                                                  //~v620I~//~v6hhR~
	ULPTR phconv;                                                  //~v6hhI~
//****************************                                     //~v61bI~
#ifdef LNX                                                         //~v6f3I~
	if (UDBCSCHK_IS_LOCALICU())                                    //~v6f3I~
    {                                                              //~v6f3I~
		return utfcvlocaleinitICU(Popt,Pplocale);//Pplocaled is filled at udbcschk by ucvext_setdefaultlocale//~v6f3R~
    }                                                              //~v6f3I~
#endif                                                             //~v6f3I~
  	if ((Popt & UTFCLIO_DEFAULTCHK))     //call from xeutf_init    //~v61bR~
    	strcpy(Pplocale,utfcvsetdefaultlocale());                  //~v61bR~
    udbcschk_getbaseconverter(0,&phconv,&Sdbcstbl);  //{codepage|toucs+fromucs},dbcs leadbyte tbl//~v620R~
    #ifdef W32                                                     //~v620I~
    	Scodepage=(int)phconv;                                     //~v620R~
//      Spconverters=(ULONG)Scodepage;                             //~v620I~//~v6hhR~
        Spconverters=(ULPTR)Scodepage;                             //~v6hhI~
UTRACEP("utfcvlocaleinit Scodepage=%d,locale=%s\n",Scodepage,Pplocale);//~v62xI~
    #else                                                          //~v620I~
        Spconverters=(ULONG)phconv;//udbcschk_getbaseconverter output//~v620R~
    #endif                                                         //~v620I~
#ifdef LNX                                                         //~v61bI~
	if (Shiconvl2f)                                                //~v61bI~
    {                                                              //~v61bI~
		utfcvlocaleclose(0,Shiconvl2f);                            //~v61bI~
        Shiconvl2f=0;                                              //~v61bI~
    }                                                              //~v61bI~
	if (Shiconvf2l)                                                //~v61bI~
    {                                                              //~v61bI~
		utfcvlocaleclose(0,Shiconvf2l);                            //~v61bI~
        Shiconvf2l=0;                                              //~v61bI~
    }                                                              //~v61bI~
	strncpy(Slocale,Pplocale,MAXLOCALESZ-1);                       //~v61bI~
//  if (UTF8MODEENV())                                             //~v61gR~
#ifndef UTF8SUPPH          //force to use iconv                    //~v620I~
    if (UTF8MODEICONV())                                           //~v61gR~
#endif                                                             //~v620I~
    {                                                              //~v61bI~
        if (!*Slocale)                                             //~v61bI~
		  	if (!(Popt & UTFCLIO_DEFAULTCHK))     //call from xeutf_init//~v61bI~
	            strcpy(Slocale,utfcvsetdefaultlocale());           //~v61bR~
        if (*Slocale)                                              //~v61bR~
        {                                                          //~v61bI~
            if ((Popt & UTFCLIO_DEFAULTMSG))     //call by A+u     //~v61bR~
                uerrmsg("\"%s\" is selected as LOCALE codeset,use \"opt mode\" cmd if not preferable",0,//~v61bR~
                        Slocale);                                  //~v61bR~
            rc2=                                                   //~v61pI~
			utfcvlocaleopen(UTFCVO_2UTF,Slocale,0/*out handle*/);  //~v61bI~
            if (rc2)                                               //~v61pI~
                rc=8;                                              //~v61pI~
            rc2=                                                   //~v61pI~
			utfcvlocaleopen(0 /*F2L*/,Slocale,0/*out handle*/);    //~v61bI~
            if (rc2)                                               //~v61pI~
                rc=8;                                              //~v61pI~
        }                                                          //~v61bR~
        else                                                       //~v61bI~
        {                                                          //~v61bI~
	        uerrmsg("Set LOCALE by \"opt mode\" cmd if you want to use locale code conversion",0);//~v61bR~
        	rc=4;                                                  //~v61bR~
        }                                                          //~v61bI~
//      utfcvlocaleopen(UTFCVO_2UTF,Slocale,0/*out handle*/);      //~v61pR~
//      utfcvlocaleopen(0 /*F2L*/,Slocale,0/*out handle*/);        //~v61pR~
    }                                                              //~v61bI~
//#ifdef UTF8SUPP                                                   //~v620I~//~v62jR~
 #ifdef UTF8SUPPH                                                  //~v62jI~
  if (!rc)                                                         //~v61pR~
  {                                                                //~v5n0I~
    Gulibutfmode|=GULIBLOCALEINIT;                                 //~v5n0R~
#ifdef UTF8SUPPH                                                   //~v620I~
    UTF8SETICONV();   //force to use iconv for conversion          //~v620R~
#endif                                                             //~v620I~
//  udbcschk_localeisdbcs(); //UDBCSCHK_LANGEBCS was set already at udbcschk//~v62PR~
  }                                                                //~v5n0I~
 #endif  //UTF8SUPPH                                               //~v6hhR~
#endif                                                             //~v61bI~
    return rc;                                                     //~v61bR~
}//utfcvlocaleinit                                                 //~v61bR~
#endif                                                             //~v5n8I~
#if defined(UTF8SUPP) || defined(WCSUPP)                           //~v5n8I~
//#ifdef UTF8SUPPH                                                   //~v627I~//~v624R~
////**************************************************************** //~v627I~//~v624R~
//// utfforcelocale (notify parameter)                               //~v627R~//~v624R~
////**************************************************************** //~v627I~//~v624R~
//int utfforcelocale(int Popt,char *Pcharset)                        //~v627I~//~v624R~
//{                                                                  //~v627I~//~v624R~
////****************************                                     //~v627I~//~v624R~
//    if (ustrstri(Pcharset,PARMCHK_UTF))        //not encoding specified//~v627R~//~v624R~
//    {                                                              //~v627I~//~v624R~
//        uerrexit("Invalid codeset parm(%s)",0,                     //~v627R~//~v624R~
//                    Pcharset);                                     //~v627I~//~v624R~
//    }                                                              //~v627I~//~v624R~
//    strncpy(Sparmcharset,Pcharset,sizeof(Sparmcharset));           //~v627R~//~v624R~
//    return 0;                                                      //~v627I~//~v624R~
//}//utfforcelocale                                                  //~v627I~//~v624R~
////**************************************************************** //~v627I~//~v624R~
//// utfforcelocale                                                  //~v627R~//~v624R~
////  issue setlocale by parm charset                                //~v627I~//~v624R~
////**************************************************************** //~v627I~//~v624R~
//int utfforcelocale2(int Popt,char *Pcharset)                       //~v627I~//~v624R~
//{                                                                  //~v627I~//~v624R~
//    int len;                                                       //~v627R~//~v624R~
//    char *pc,*pc2;                                                 //~v627I~//~v624R~
//    char wklocale[MAXLOCALESZ];                                    //~v627I~//~v624R~
////****************************                                     //~v627I~//~v624R~
//    pc=udbcschk_setlocale(0,LC_ALL,"");                            //~v627I~//~v624R~
//    if (pc2=strchr(pc,'.'),pc2)  //codeset info                    //~v627R~//~v624R~
//    {                                                              //~v627I~//~v624R~
//        if (ustrstri(pc2,PARMCHK_UTF))        //not encoding specified//~v627R~//~v624R~
//        {                                                          //~v627I~//~v624R~
//            if (utflocalechk(0,Sparmcharset))                      //~v627I~//~v624R~
//                uerrexit("Invalid codeset parm(%s)",0,             //~v627R~//~v624R~
//                            Sparmcharset);                         //~v627I~//~v624R~
//            *wklocale=0;    //bypasss issue setlocale              //~v627I~//~v624R~
//        }                                                          //~v627I~//~v624R~
//        else                                                       //~v627I~//~v624R~
//        {                                                          //~v627I~//~v624R~
//            len=(int)((ULONG)pc2-(ULONG)pc)+1;                     //~v627R~//~v624R~
//            memcpy(wklocale,pc,(UINT)len);                         //~v627R~//~v624R~
//            strcpy(wklocale+len,Sparmcharset);                     //~v627R~//~v624R~
//        }                                                          //~v627I~//~v624R~
//    }                                                              //~v627I~//~v624R~
//    else                                                           //~v627I~//~v624R~
//        sprintf(wklocale,"%s.%s",pc,Sparmcharset);                 //~v627I~//~v624R~
//    if (*wklocale)                                                 //~v627I~//~v624R~
//        pc=udbcschk_setlocale(0,LC_ALL,wklocale);                  //~v627R~//~v624R~
//    strcpy(Pcharset,Sparmcharset);                                 //~v627I~//~v624R~
//    UTRACEP("utfforcelocale2 charset=%s,locale=%s:%s\n",Pcharset,wklocale,pc);//~v627I~//~v624R~
//    return 0;                                                      //~v627I~//~v624R~
//}//utfforcelocale2                                                 //~v627I~//~v624R~
//#endif                                                             //~v627I~//~v624R~
//**************************************************************** //~v61bI~
// utfsetcvdefaultlocale                                             //~v61bI~//~v62GR~
//ret:4 err                                                        //~v61bI~
//**************************************************************** //~v61bI~
char *utfcvsetdefaultlocale(void)                                  //~v61bI~
{                                                                  //~v61bI~
static char Sdefaultcharset[MAXLOCALESZ];                          //~v61bI~
#ifdef LNX                                                         //~v5ncI~
  #ifndef UTF8SUPPH   //abend when retun 0;                        //~v6b9I~
	int rc=0;                                                      //~v61bR~
  #endif                                                           //~v6b9I~
#endif                                                             //~v5ncI~
    char *pctype;                                                  //~v61bR~
    char charset[MAXLOCALESZ]={0};                                 //~v61bI~
    char locale[MAXLOCALESZ];                                      //~v61bI~
#ifdef LNX                                                         //~v61bI~
    char *pc;                                                      //~v61bI~
	int len;                                                       //~v61bI~
#endif                                                             //~v61bI~
#ifdef UTF8SUPPH                                                   //~v626I~
    #ifdef AAA                                                     //~v626I~
    char *plocale;                                                 //~v626I~
    #endif                                                         //~v626I~
#endif                                                             //~v626I~
//****************************                                     //~v61bI~
	if (*Sdefaultcharset)                                          //~v61bI~
    	return Sdefaultcharset;                                    //~v61bI~
    charset[MAXLOCALESZ-1]=0;                                      //~v61bI~
    locale[MAXLOCALESZ-1]=0;                                       //~v61bI~
#ifdef LNX                                                         //~v61bM~
    for (;;)                                                       //~v61bI~
    {                                                              //~v61bI~
//#ifdef UTF8SUPPH                                                   //~v626I~//~v624R~
//        if (*Sparmcharset)  //charset parm specified               //~v627I~//~v624R~
//        {                                                          //~v627I~//~v624R~
//            utfforcelocale2(0,charset);                            //~v627I~//~v624R~
//            break;                                                 //~v627I~//~v624R~
//        }                                                          //~v627I~//~v624R~
//#endif                                                             //~v627I~//~v624R~
#ifdef UTF8SUPPH                                                   //~v627I~
//      udbcschk_setlocale(0,LC_CTYPE,"");                         //~v627I~//~v62vR~
#else                                                              //~v627I~
        setlocale(LC_CTYPE,"");                                    //~v5n8I~
#endif                                                             //~v627M~
#ifndef UTF8SUPPH  //no need                                       //~v627I~
        pctype=nl_langinfo(CODESET);                               //~v61bR~
        if (!ustrstri(pctype,PARMCHK_UTF))        //not encoding specified//~v627R~
        {                                                          //~v61bR~
            strncpy(charset,pctype,sizeof(charset)-1); //codeset from locale//~v61bI~
            if (!utflocalechk(0,charset))                          //~v61bI~
            	break;	//use this                                 //~v61bI~
        }                                                          //~v61bR~
#endif                                                             //~v627I~
#ifdef UTF8SUPPH                                                   //~v627I~
        pctype=udbcschk_setlocale(0,LC_CTYPE,"");                  //~v627I~
#else                                                              //~v627I~
        pctype=setlocale(LC_CTYPE,"");                             //~v61bR~
#endif                                                             //~v627I~
        if (pc=strchr(pctype,'.'),pc)   //codeset info             //~v61bR~
        {                                                          //~v61bR~
            if (!ustrstri(pc,PARMCHK_UTF))        //not encoding specified//~v627R~
            {                                                      //~v61bI~
#ifdef UTF8SUPPH                                                   //~v62vI~
                strncpy(charset,pc+1,sizeof(charset)-1); //codeset from locale//~v62vI~
#else                                                              //~v62vI~
                strncpy(charset,pc,sizeof(charset)-1); //codeset from locale//~v61bR~
#endif                                                             //~v62vI~
	            if (!utflocalechk(0,charset))                      //~v61bI~
	            	break;	//use this                             //~v61bI~
            }                                                      //~v61bI~
//          len=(ULONG)pc-(ULONG)pctype;                           //~v61bR~//~v6BkR~
            len=PTRDIFF(pc,pctype);                                //~v6BkI~
        }                                                          //~v61bR~
        else                                                       //~v61bR~
//          len=strlen(pctype);                                    //~v61bR~//~v6BkR~
            len=(int)strlen(pctype);                               //~v6BkI~
        len=min(len,MAXLOCALESZ-1);                                //~v61bR~
        memcpy(locale,pctype,(UINT)len);                           //~v61bR~
        *(locale+len)=0;                                           //~v61bR~
#ifndef UTF8SUPPH   //abend when retun 0;                          //~v6b9I~
		rc=                                                        //~v6b9I~
#endif                                                             //~v6b9I~
        /*rc=*/utfgetcharset(locale,charset);                          //~v61bR~//~v6b9R~
#ifndef UTF8SUPPH   //abend when retun 0;                          //~v627I~
        if (rc)                                                    //~v61bR~
            return 0;                                              //~v61bR~
#endif                                                             //~v627I~
        break;                                                     //~v61bI~
    }                                                              //~v61bI~
#else                                                              //~v61bI~
#ifdef UTF8SUPPH                                                   //~v627I~
    pctype=udbcschk_setlocale(0,LC_CTYPE,"");                      //~v627I~
    if (udbcschk_wingetdefaultcp(0,locale)>0)                      //~v62uR~
    	pctype=locale;                                             //~v62uI~
#else                                                              //~v627I~
    pctype=setlocale(LC_CTYPE,"");                                 //~v61bI~
#endif                                                             //~v627I~
    strncpy(charset,pctype,MAXLOCALESZ-1);                         //~v61bR~
#endif                                                             //~v61bI~
	strncpy(Sdefaultcharset,charset,MAXLOCALESZ-1);                //~v61bR~
    UTRACEP("utfcvsetdefaultlocale ret %s\n",Sdefaultcharset);     //~v627I~
    return Sdefaultcharset;                                        //~v61bR~
}//utfcvsetdefaultlocale                                           //~v61bR~
//**************************************************************** //~v62GI~
// utfcvsetparmlocale                                              //~v6f3R~
//ret: 0:setlocale done, bypassed or err                           //~v62GI~
//**************************************************************** //~v62GI~
int utfcvsetparmlocale(int Popt,char *Plocale)                     //~v62GI~
{                                                                  //~v62GI~
	int rc=4;                                                      //~v62GI~
    char *pctype,*pcc,*pc;                                         //~v62GR~
    char parmlocale[MAXLOCALESZ];                                  //~v62GI~
    char setloc[MAXLOCALESZ*2];                                    //~v62GI~
//****************************                                     //~v62GI~
    UTRACEP("utfcvsetparmlocale entry locale=%s\n",Plocale);       //~v62GI~
    setloc[0]=0;                                                   //~v6C6I~
	if (!Plocale)	//reset req                                    //~v62GI~
    {                                                              //~v62GI~
//  	setlocale(LC_CTYPE,"");                                    //~v62GI~//~v62MR~
    	udbcschk_setlocale(0,LC_CTYPE,0/*reset to system default*/);//~v62MI~
        return 0;                                                  //~v62GI~
    }                                                              //~v62GI~
    for (;;)                                                       //~v62GI~
    {                                                              //~v62GI~
        pcc=Plocale;                                               //~v62GI~
    	pc=strchr(pcc,'.');                                        //~v62GR~
        if (!pc)	//parm is codepage only                        //~v62GR~
        {                                                          //~v62GI~
#ifdef LNX                                                         //~v62GM~
        	pctype=udbcschk_setlocale(0,LC_CTYPE,"");              //~v62GI~
        	if (pc=strchr(pctype,'.'),pc)   //codeset info         //~v62GI~
	        	UmemcpyZ(parmlocale,pctype,(ULONG)pc-(ULONG)pctype);//~v62GR~
            else			//windows accept ".cp" pattern         //~v62GI~
            	break;                                             //~v62GI~
#else                                                              //~v62GI~
            *parmlocale=0;			//windows accept ".cp" pattern //~v62GR~
//#ifndef CCC	//not effective ;setlocale returns null            //~v65cR~
//            if (atoi(pcc)==CP_GB18030)                           //~v65cR~
//                strcpy(parmlocale,"chinese-simplified_chn");     //~v65cR~
//#endif                                                           //~v65cR~
#endif                                                             //~v62GI~
	        sprintf(setloc,"%s.%s",parmlocale,pcc);                //~v62GI~
            pcc=setloc;                                            //~v62GI~
        }                                                          //~v62GI~
#ifdef UTF8SUPPH                                                   //~v62WI~
    	pctype=udbcschk_setlocale(UDCSLO_CHKPARM,LC_CTYPE,pcc);    //~v62WI~
      if (!pctype)                                                 //~v633I~
      {                                                            //~v633I~
        rc=1;          //setlocale failed                          //~v633I~
        Gulibutfmode|=GULIBSETLOCALERR;  //setlocale failed        //~v633I~
      }                                                            //~v633I~
      else                                                         //~v633I~
#else                                                              //~v62WI~
    	pctype=udbcschk_setlocale(0,LC_CTYPE,pcc);                 //~v62GR~
#endif                                                             //~v62WI~
        rc=0;                                                      //~v62GI~
    	UTRACEP("utfcvsetparmlocale %s, ret %s\n",setloc,pctype);  //~v62GR~
        break;                                                     //~v62GI~
    }                                                              //~v62GI~
    return rc;                                                     //~v62GI~
}//utfcvsetparmlocale                                              //~v62GI~
#endif //if defined(UTF8SUPP) || defined(WCSUPP)                   //~v5n8I~
//#ifdef UTF8SUPP                                                    //~v5n8I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
#ifdef LNX                                                         //~v61bM~
//#ifdef AAA                                                         //~v61mI~//~v6a0R~
////*********************************************************************//~v61bI~//~v6a0R~
////* get available encoding using locale cmd                        //~v61bR~//~v6a0R~
////(gnome-terminal use his own gconf info but)                      //~v61bR~//~v6a0R~
////ret :rc;                                                         //~v61bI~//~v6a0R~
////*********************************************************************//~v61bI~//~v6a0R~
//int utfgetcharset(char *Pplocale,char *Ppcodeset)                  //~v61bR~//~v6a0R~
//{                                                                  //~v61bI~//~v6a0R~
//#define PSRECSZ     512                                            //~v61bI~//~v6a0R~
//    char psrec[PSRECSZ+1];                                         //~v61bI~//~v6a0R~
//    char tempfnm[32];                                              //~v61bR~//~v6a0R~
//    char pscmd[128],*pc;                                           //~v61bR~//~v6a0R~
//    int len,lclen;                                                 //~v61bR~//~v6a0R~
//    FILE *fh;                                                      //~v61bI~//~v6a0R~
//    char charset[MAXLOCALESZ];                                     //~v61bR~//~v6a0R~
////************************                                         //~v61bI~//~v6a0R~
//    utempnam("/tmp","xelocale_",tempfnm);                          //~v61bI~//~v6a0R~
//    sprintf(pscmd,"locale -a >%s",tempfnm);     //default          //~v61bI~//~v6a0R~
//    sprintf(pscmd,"%s >%s",GETLOCALECMD,tempfnm);                  //~v61bI~//~v6a0R~
//    if (usystem2(UPROC_NOOKMSG,pscmd))                             //~v61bI~//~v6a0R~
//        return 4;                                                  //~v61bI~//~v6a0R~
//    fh=fopen(tempfnm,"r");                                         //~v61bI~//~v6a0R~
//    if (!fh)                                                       //~v61bI~//~v6a0R~
//    {                                                              //~v61bI~//~v6a0R~
//        uerrmsg("%s open failed\n",0,                              //~v61bI~//~v6a0R~
//                tempfnm);                                          //~v61bI~//~v6a0R~
//        return 4;                                                  //~v61bI~//~v6a0R~
//    }                                                              //~v61bI~//~v6a0R~
////read header rec                                                  //~v61bI~//~v6a0R~
//    lclen=strlen(Pplocale); //language_country                     //~v61bI~//~v6a0R~
//    *Ppcodeset=0;                                                  //~v61bR~//~v6a0R~
//    while(fgets(psrec,PSRECSZ,fh))                                 //~v61bI~//~v6a0R~
//    {                                                              //~v61bI~//~v6a0R~
//        len=strlen(psrec);                                         //~v61bR~//~v6a0R~
//        if (*(psrec+len-1)=='\n')                                  //~v61bI~//~v6a0R~
//        {                                                          //~v61bI~//~v6a0R~
//            len--;                                                 //~v61bI~//~v6a0R~
//            *(psrec+len)=0;                                        //~v61bR~//~v6a0R~
//        }                                                          //~v61bI~//~v6a0R~
//        if (len>lclen                                              //~v61bI~//~v6a0R~
//        &&  !memicmp(Pplocale,psrec,(UINT)lclen)                   //~v61bR~//~v6a0R~
//           )                                                       //~v61bI~//~v6a0R~
//        {                                                          //~v61bI~//~v6a0R~
//            pc=psrec+lclen;                                        //~v61bI~//~v6a0R~
//            *charset=0;                                            //~v61bI~//~v6a0R~
//            charset[MAXLOCALESZ-1]=0;                              //~v61bR~//~v6a0R~
//            if (!*pc||*pc=='@')      //no codeset specified        //~v61bR~//~v6a0R~
//                strncpy(charset,psrec,MAXLOCALESZ-1);              //~v61bR~//~v6a0R~
//            else                                                   //~v61bI~//~v6a0R~
//            if (*pc=='.' && !ustrstri(pc+1,PARMCHK_UTF))    //not utf//~v627R~//~v6a0R~
//                strncpy(charset,pc+1,MAXLOCALESZ-1);               //~v61bR~//~v6a0R~
//            if (*charset)                                          //~v61bI~//~v6a0R~
//                if (!utflocalechk(0,charset))                      //~v61bI~//~v6a0R~
//                    memcpy(Ppcodeset,charset,MAXLOCALESZ);         //~v61bI~//~v6a0R~
//        }                                                          //~v61bI~//~v6a0R~
//    }                                                              //~v61bI~//~v6a0R~
//    fclose(fh);                                                    //~v61bM~//~v6a0R~
//    unlink(tempfnm);    //del temp file                            //~v61mI~//~v6a0R~
//    if (!*Ppcodeset)                                               //~v61bR~//~v6a0R~
//        return 4;                                                  //~v61bI~//~v6a0R~
//    return 0;                                                      //~v61bI~//~v6a0R~
//}//utfgetcharset                                                   //~v61bR~//~v6a0R~
//#else                                                              //~v61mI~//~v6a0R~
#ifdef UTF8SUPPH                                                   //~v627I~
//*********************************************************************//~v627I~
//* search preferable codeset                                      //~v627I~
//ret :rc; 1:not same as nlinfo,-1:env is utf8 no need to setlocale//~v627I~
//*********************************************************************//~v627I~
int utfgetcharset_std(char *Pplocale,char *Ppcodeset)              //~v627I~
{                                                                  //~v627I~
//  char *pctype;                                                  //~v627I~//~v634R~//~v68qR~
#ifndef NOTRACE                                                    //~v6b9I~
    char *pctype=0;       //init for UTRACE                        //~v68qI~
#endif                                                             //~v6b9I~
    char *pzhcncs[]={"GB18030","GBK","GB2312",0};                  //~v627I~
//  char *pkokrcs[]={"UHC",0};  //unified hangul code              //~v634I~//~v6fkR~
    char *pkokrcs[]={"UHC","EUC-KR",0};  //unified hangul code     //~v6fkI~
    char *pjajpcs[]={"eucjp",0};  //unified hangul code            //~v634I~
    char *pconscs[]={ISO88591,"C",0};//when on green console       //~v637R~
    char **ppc=0;                                                  //~v627I~
    char *pc;                                                      //~v634I~
    int rc=0;                                                      //~v627I~
    char charset[MAXLOCALESZ];                                     //~v627I~//~v634R~
//************************                                         //~v627I~
    UTRACEP("utfgetcharset_std in locale=%s\n",Pplocale);          //~v627R~
	if (Gudbcschk_flag & UDBCSCHK_TTYCONS)	//on console           //~v637I~
    {                                                              //~v637I~
    	for (ppc=pconscs;*ppc;ppc++)                               //~v637R~
			if (!utflocalechk(0,*ppc))  //iconv supported          //~v637I~
            	break;                                             //~v637I~
    }                                                              //~v637I~
    else                                                           //~v637I~
    if (!stricmp(Pplocale,LANG_ZHCN)) //simple chinese              //~v627I~//~v634R~
    {                                                              //~v627I~
    	for (ppc=pzhcncs;*ppc;ppc++)                               //~v627I~
			if (!utflocalechk(0,*ppc))  //iconv supported          //~v627I~
            	break;                                             //~v627I~
    }                                                              //~v627I~
    else                                                           //~v634I~
    if (!stricmp(Pplocale,LANG_KOKR)) //korean                     //~v634R~
    {                                                              //~v634I~
    	for (ppc=pkokrcs;*ppc;ppc++)                               //~v634I~
			if (!utflocalechk(0,*ppc))  //iconv supported          //~v634I~
            	break;                                             //~v634I~
    }                                                              //~v634I~
    else                                                           //~v634I~
    if (!stricmp(Pplocale,LANG_JAJP)) //japanese                   //~v634R~
    {                                                              //~v634I~
    	for (ppc=pjajpcs;*ppc;ppc++)                               //~v634R~
			if (!utflocalechk(0,*ppc))  //iconv supported          //~v634I~
            	break;                                             //~v634I~
    }                                                              //~v634I~
    if (ppc && *ppc)                                               //~v627R~
    {                                                              //~v627I~
		strncpy(Ppcodeset,*ppc,MAXLOCALESZ-1);                     //~v627I~
#ifndef NOTRACE                                                    //~v6b9I~
    	pctype=nl_langinfo(CODESET);                               //~v627I~
#endif                                                             //~v6b9I~
//  	if (strcmp(pctype,Ppcodeset))                              //~v627I~//~v634R~
//      {                                                          //~v627I~//~v634R~
//      	if (ustrstri(pctype,PARMCHK_UTF))        //env is utf8 //~v627R~//~v634R~
//          	rc=-1;                                             //~v627I~//~v634R~
//          else                                                   //~v627I~//~v634R~
//          {                                                      //~v627I~//~v634R~
            	rc=1;                                              //~v634I~
                sprintf(charset,"%s.%s",Pplocale,Ppcodeset);       //~v627R~
//      		udbcschk_setlocale(0,LC_CTYPE,charset);	//set langauge without codeset//~v627R~//~v634R~
    			pc=udbcschk_setlocale(UDCSLO_CHKBASE,LC_CTYPE,charset);	//set langauge without codeset//~v634I~
 UTRACEP("utfgetcharset_std setlocale for %s is %s\n",charset,pc); //~v634I~
                if (!pc)                                           //~v6fkI~
                    if (!strcmp(Ppcodeset,"UHC"))	               //~v6fkR~
                    {                                              //~v6fkI~
//		                sprintf(charset,"%s.%s",Pplocale,"EUC-KR");//~v6fkR~
  		                sprintf(charset,"%s",Pplocale);            //~v6fkR~
    					pc=udbcschk_setlocale(UDCSLO_CHKBASE,LC_CTYPE,charset);	//for wcwidth etc//~v6fkI~
 UTRACEP("utfgetcharset_std setlocale for %s is %s\n",charset,pc); //~v6fkI~
                    }                                              //~v6fkI~
    			if (!pc)    //setlocale failed with localecode only//~v634I~
                {                                                  //~v634I~
    				Gulibutfmode|=GULIBSETLOCALERR;  //setlocale failed//~v634I~
                    rc=2;                                          //~v634I~
                }                                                  //~v634I~
//          }                                                      //~v627I~//~v634R~
//      }                                                          //~v627I~//~v634R~
    }                                                              //~v627I~
#ifndef ARM                                                        //~v6a0I~
 UTRACEP("utfgetcharset_std rc=%d,locale=%s,codeset=%s,nllang=%s\n",rc,Pplocale,Ppcodeset,pctype);//~v627I~//~v634R~
#endif                                                             //~v6a0I~
 	return rc;                                                     //~v627I~
}//utfgetcharset_std                                               //~v627I~
#endif                                                             //~v627I~
//*********************************************************************//~v61mI~
//* get available encoding using api                               //~v62GR~
//* get Native charset by setlocale with localecode dropping UTF-8 charset//~v62GI~
//(gnome-terminal use his own gconf info but)                      //~v61mI~
//ret :rc;        1:need setlocale,-1:env is utf8                  //~v627R~
//*********************************************************************//~v61mI~
int utfgetcharset(char *Pplocale,char *Ppcodeset)                  //~v61mI~
{                                                                  //~v61mI~
    char *pctype;                                                  //~v61mI~
#ifdef UTF8SUPPH                                                   //~v62WI~
	char  lcgeneral[MAXLOCALESZ],*pc;                              //~v62WR~
#endif                                                             //~v62WI~
	int ii;                                                        //~v68qI~
    char *iso8859alias[]={"ISO-8859-1","ISO8859-1","ISO_8859-1","ISO_8859_1"};//~v68qI~
//************************                                         //~v61mI~
    UTRACEP("utfgetcharset locale=%s\n",Pplocale);                 //~v627I~
//#ifdef UTF8SUPPH                                                   //~v626I~//~v62GR~
//  if (utfgetcharset_std(Pplocale,Ppcodeset))                     //~v627R~//~v62GR~
//      return 0;                                                  //~v627R~//~v62GR~
//#endif                                                             //~v626I~//~v62GR~
#ifdef UTF8SUPPH                                                   //~v634I~
  	if (utfgetcharset_std(Pplocale,Ppcodeset))	//prefered charset avail//~v634I~
        return 0;                                                  //~v634I~
#endif                                                             //~v634I~
#ifdef UTF8SUPPH                                                   //~v627I~
//  udbcschk_setlocale(0,LC_CTYPE,Pplocale);	//set langauge without codeset//~v627I~//~v62WR~
    pc=                                                            //~v62WI~
    udbcschk_setlocale(UDCSLO_CHKBASE,LC_CTYPE,Pplocale);	//set langauge without codeset//~v62WI~
    if (!pc)    //setlocale failed with localecode only            //~v62WI~
    {                                                              //~v62WI~
        sprintf(lcgeneral,"%s.%s",Pplocale,ISO88591);              //~v62WI~
	    pc=udbcschk_setlocale(UDCSLO_CHKBASE,LC_CTYPE,lcgeneral);	//set langauge without codeset//~v62WI~
        if (!pc)                                                   //~v68qI~
        {                                                          //~v68qI~
        	for (ii=0;ii<sizeof(iso8859alias)/sizeof(char*);ii++)  //~v68qI~
            {                                                      //~v68qI~
	        	sprintf(lcgeneral,"%s.%s",Pplocale,iso8859alias[ii]);//~v68qI~
	    		pc=udbcschk_setlocale(UDCSLO_CHKBASE,LC_CTYPE,lcgeneral);	//set langauge without codeset//~v68qI~
                if (pc)                                            //~v68qI~
                	break;                                         //~v68qI~
            }                                                      //~v68qI~
        }                                                          //~v68qI~
        if (pc)                                                    //~v62WI~
        {                                                          //~v638I~
	        sprintf(lcgeneral,"%s.%s",Pplocale,ISO88591);          //~v68qI~
          if (Gudbcschk_flag & UDBCSCHK_EXPLICIT) //skip for xsub  //~v638R~
        	uerrmsg("setlocale failed for %s, assumed %s",0,       //~v62WI~
            			Pplocale,lcgeneral);                       //~v62WI~
        }                                                          //~v638I~
        else                                                       //~v633I~
    	    Gulibutfmode|=GULIBSETLOCALERR;  //setlocale failed    //~v633I~
    }                                                              //~v62WI~
#else                                                              //~v627I~
    setlocale(LC_CTYPE,Pplocale);	//set langauge without codeset //~v61mI~
#endif                                                             //~v627I~
    pctype=nl_langinfo(CODESET);                                   //~v61mI~
  if (ustrstri(pctype,LOCALEID_UTF8)||ustrstri(pctype,LOCALEID_UTF_8))//~v62WI~
  {                                                                //~v62WI~
   if (Gudbcschk_flag & UDBCSCHK_EXPLICIT) //skip for xsub         //~v638R~
//  uerrmsg("\"locale -a\" has only UTF8 entry for %s, assumed %s as base encoding",0,//~v62WR~//~v68qR~
//  printf("Warning:\"locale -a\" shows UTF8 entry only for %s, assumed %s as base encoding",//~v6a0R~
//  printf("Warning:\"locale -a\" shows UTF8 entry only for %s, assumed %s as base encoding\n",//~v6a0R~
    printf("Warning:Langinfo shows UTF8(locale:%s), assumed %s as base encoding\n",//~v6a0I~
            Pplocale,ISO88591);                                    //~v62WR~
    strcpy(Ppcodeset,ISO88591);                                    //~v62WI~
  }                                                                //~v62WI~
  else                                                             //~v62WI~
    strncpy(Ppcodeset,pctype,MAXLOCALESZ-1);                       //~v61mI~
#ifdef UTF8SUPPH                                                   //~v627I~
//  udbcschk_setlocale(0,LC_CTYPE,0/*issue setlocale("")*/);//retore to original UTF8     //~v627R~//~v62GR~//~v62MR~
#else                                                              //~v627I~
    setlocale(LC_CTYPE,"");			//reset to env-var             //~v61mI~
#endif                                                             //~v627I~
 UTRACEP("utfgetcharset other out locale=%s,codeset=%s\n",Pplocale,Ppcodeset);//~v627I~
    return 0;                                                      //~v61mI~
}//utfgetcharset                                                   //~v6a0R~
//#endif AAA                                                         //~v61mI~//~v6a0R~
//**************************************************************** //~v61bM~
//!utflocalechk                                                    //~v61bM~
//chk validity locale codeid                                       //~v61bM~
//ret:4 err                                                        //~v61bM~
//**************************************************************** //~v61bM~
int utflocalechk(int Popt,char *Pplocale)                          //~v61bM~
{                                                                  //~v61bM~
    iconv_t hiconv;                                                //~v61bM~
//****************************                                     //~v61bM~
	if (Sswgeticu)                                                 //~v6f3I~
    	return utflocalechkICU(Popt,Pplocale);                     //~v6f3I~
#ifdef ARM                                                         //~v6a0I~
	hiconv=iconv_open(Pplocale,LOCALEID_UTF_8); //iconv-v1.13.1,   //~v6a0R~
#else                                                              //~v6a0I~
	hiconv=iconv_open(Pplocale,LOCALEID_UTF8);                     //~v61bM~
#endif                                                             //~v6a0I~
UTRACEP("utflocalechk iconvopen from UTF8 to %s ,rc=%x,errno=%d\n",Pplocale,hiconv,errno);//~v624I~//~v62vR~//~v6K8R~
    if (hiconv==(iconv_t)-1)                                       //~v61bM~
    	return 4;                                                  //~v61bM~
	utfcvlocaleclose(0,hiconv);                                    //~v61bI~
    return 0;                                                      //~v61bM~
}//utflocalechk                                                    //~v61bM~
//**************************************************************** //~v61bI~
// utfcvl2fanyopen(int Popt,char *Pplocale)                        //~v61bI~
//ret:4 err                                                        //~v61bI~
//**************************************************************** //~v61bI~
int utfcvlocaleopen(int Popt,char *Pplocale,iconv_t *Pphiconv)     //~v61bI~
{                                                                  //~v61bI~
    iconv_t hiconv;                                                //~v61bI~
    char *plocale;                                                 //~v61bI~
//****************************                                     //~v61bI~
UTRACEP("iconvopen opt=%x,locale=%s handle=%x,%x\n",Popt,Pplocale,Shiconvl2f,Shiconvf2l);//~v61bI~//~v62vR~
	if (!(plocale=Pplocale))                                       //~v61bI~
    	plocale=Slocale;                                           //~v61bI~
    if (Popt & UTFCVO_2UTF)	//locale to utf8                       //~v61bR~
    {                                                              //~v61bI~
    	if (!(hiconv=Shiconvl2f))                                  //~v61bI~
#ifdef ARM                                                         //~v6a0I~
			hiconv=iconv_open(LOCALEID_UTF_8/*to*/,plocale/*from*/);//~v6a0I~
#else                                                              //~v6a0I~
			hiconv=iconv_open(LOCALEID_UTF8/*to*/,plocale/*from*/);//~v61bI~
			UTRACEP("%s:%s to %s\n",UTT,plocale,LOCALEID_UTF8);    //~v6uBI~
#endif                                                             //~v6a0I~
    }                                                              //~v61bI~
    else                                                           //~v61bI~
    {                                                              //~v61bI~
    	if (!(hiconv=Shiconvf2l))                                  //~v61bI~
#ifdef ARM                                                         //~v6a0I~
			hiconv=iconv_open(plocale,LOCALEID_UTF_8);             //~v6a0I~
#else                                                              //~v6a0I~
			hiconv=iconv_open(plocale,LOCALEID_UTF8);              //~v61bI~
			UTRACEP("%s:%s to %s\n",UTT,LOCALEID_UTF8,plocale);    //~v6uBI~
#endif                                                             //~v6a0I~
    }                                                              //~v61bI~
UTRACEP("iconvopen out,handle=%x\n",hiconv);                      //~v61bR~//~v62vR~
    if (hiconv==(iconv_t)-1)                                       //~v61bI~
    {                                                              //~v61bI~
    	return errno;                                              //~v61bR~
    }                                                              //~v61bI~
    if (Pphiconv)                                                  //~v61bI~
	    *Pphiconv=hiconv;                                          //~v61bR~
    if (Popt & UTFCVO_2UTF)	//locale to utf8                       //~v61bR~
    	Shiconvl2f=hiconv;                                         //~v61bI~
    else                                                           //~v61bI~
    	Shiconvf2l=hiconv;                                         //~v61bI~
    return 0;                                                      //~v61bI~
}//utfcvlocaleopen                                                 //~v61bI~
//**************************************************************** //~v61bI~
// utfcvlocaleclose                                                //~v61bR~
//ret:4 err                                                        //~v61bI~
//**************************************************************** //~v61bI~
int utfcvlocaleclose(int Popt,iconv_t Phiconv)                     //~v61bI~
{                                                                  //~v61bI~
//****************************                                     //~v61bI~
	return iconv_close(Phiconv);                                   //~v61bI~
}//utfcvlocaleclose                                                //~v61bI~
//**************************************************************** //~v61bI~
// utfcvlocaletclose(temporary close:reset pointer)                //~v61bR~
// reset static ptr;                                               //~v61bI~
//**************************************************************** //~v61bI~
int utfcvlocaletclose(int Popt,ULONG Phiconv)                      //~v61gR~
{                                                                  //~v61bI~
//****************************                                     //~v61bI~
//  return iconv((iconv_t)Phiconv,0,0,0,0);                        //~v61gR~//~v6BkR~
    return (int)iconv((iconv_t)Phiconv,0,0,0,0);                   //~v6BkI~
}//utfcvlocaletclose                                               //~v61bI~
//**************************************************************** //~v61bI~
// chk char is lead byte of dbcs using iconv(ENV=UTF8)             //~v61bR~
// reset static ptr;                                               //~v61bI~
//**************************************************************** //~v61bI~
//int utfcviconvdbcschk_topbyte(int Popt,UCHAR Pchar)              //~v61hR~
int utfcviconvdbcschk_topbyte(int Popt,UCHAR Pchar,UCHAR *Pputf,int *Pputflen)//~v61hI~
{                                                                  //~v61bI~
//	int ilen,olen;                                                 //~v624R~
  	size_t ilen,olen;                                              //~v624R~
    char wki[2],wko[UTF8_MAXCHARSZMAX],*pci,*pco;                  //~v61bR~
//****************************                                     //~v61bI~
	if (UTF8ISASCII(Pchar))                                        //~v61bI~
    {                                                              //~v61hI~
    	if (Pputflen)                                              //~v61hI~
        	*Pputflen=1;                                           //~v61hI~
        if (Pputf)                                                 //~v61hI~
        	*Pputf=Pchar;                                          //~v61hI~
    	return 0;                                                  //~v61bI~
    }                                                              //~v61hI~
	wki[0]=Pchar;                                                  //~v61bI~
    pci=wki;                                                       //~v61bI~
    pco=wko;                                                       //~v61bI~
    ilen=1;                                                        //~v61bI~
    olen=sizeof(wko);                                              //~v61bI~
//  if ((int)iconv(Shiconvl2f,&pci,&ilen,&pco,&olen)<0)            //~v5ncI~
//  if ((int)iconv(Shiconvl2f,ICONV_PCTYPE(&pci),&ilen,&pco,&olen)<0)//~v5ncR~//~v5nDR~
    if ((int)iconv(Shiconvl2f,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen))<0)//~v5nDI~
    {                                                              //~v61bI~
    	if (errno==EINVAL)	//correspond to rc=-2 from mbr2wc      //~v61bI~
        	return 2;                                              //~v61bI~
        else                                                       //~v61bI~
        	return 1;                                              //~v61bI~
    }                                                              //~v61bI~
    else                                                           //~v61hI~
    {                                                              //~v61hI~
    	olen=sizeof(wko)-olen;                                     //~v61hI~
    	if (Pputflen)                                              //~v61hI~
//      	*Pputflen=olen;                                        //~v61hI~//~v6BkR~
        	*Pputflen=(int)olen;                                   //~v6BkI~
        if (Pputf)                                                 //~v61hI~
        	memcpy(Pputf,wko,(UINT)olen);                          //~v61hI~
    }                                                              //~v61hI~
	return 0;                                                      //~v61bI~
}//utfcvlocaledbcschk_topbyte                                      //~v61bI~
//**************************************************************** //~v61bI~
// chk char is dbcs  using iconv(ENV=UTF8)                         //~v61bI~
// rc:-1:err,0 ok, readlen=2 for dbcs or 3(SS3 of EUC) or 4(GB18040)//~v62UR~
//**************************************************************** //~v61bI~
//int utfcviconvdbcschk1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen)//~v61hR~
int utfcviconvdbcschk1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs)//~v61hR~
{                                                                  //~v61bI~
//	int readlen=1,rc=0,ilen,olen;                                  //~v624R~
  	int readlen=1,rc=0;                                            //~v624R~
  	int iilen,iolen,rc2;                                           //~v690I~
	size_t ilen,olen;                                              //~v624R~
    char wko[UTF8_MAXCHARSZMAX],*pci,*pco;                         //~v61bR~
    int chklen,rcutf;                                              //~v61hI~
//****************************                                     //~v61bI~
//  if (utfcviconvdbcschk_topbyte(Popt,*Pstr))	//dbcs             //~v61hR~
//  if (utfcviconvdbcschk_topbyte(Popt,*Pstr,wko,&olen))	//dbcs //~v61hI~//~v690R~
    rc2=utfcviconvdbcschk_topbyte(Popt,*Pstr,wko,&iolen);	//dbcs //~v690I~
    olen=(size_t)iolen;                                            //~v690I~
    if (rc2)                                                       //~v690I~
    {                                                              //~v61bI~
    	if (Plen==1)                                               //~v61bI~
        	rc=-1;	//err                                          //~v61bI~
        else                                                       //~v61bI~
        {                                                          //~v61bI~
	    	pci=Pstr;                                              //~v61bI~
   		 	pco=wko;                                               //~v61bI~
//        	ilen=2;                                                //~v62UR~
//        	udbcschk_getmblen(UDCGMLO_LEN1IFERR,Pstr,Plen,&ilen);  //~v62UR~//~v690R~
          	udbcschk_getmblen(UDCGMLO_LEN1IFERR,Pstr,Plen,&iilen); //~v690I~
    		ilen=(size_t)iilen;                                    //~v690I~
    		olen=sizeof(wko);                                      //~v61bI~
//  		if ((int)iconv(Shiconvl2f,&pci,&ilen,&pco,&olen)<0)	//invalid sbcs//~v5ncI~
//  		if ((int)iconv(Shiconvl2f,ICONV_PCTYPE(&pci),&ilen,&pco,&olen)<0)	//invalid sbcs//~v5ncR~//~v5nDR~
    		if ((int)iconv(Shiconvl2f,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen))<0)	//invalid sbcs//~v5nDI~
            	rc=-1;                                             //~v61bI~
            else                                                   //~v61bI~
            {                                                      //~v61hI~
		    	olen=sizeof(wko)-olen;                             //~v61hI~
//            	readlen=2;                                         //~v62UR~
              	readlen=(int)((ULONG)pci-(ULONG)Pstr);             //~v62UR~
            }                                                      //~v61hI~
        }                                                          //~v61bI~
    }                                                              //~v61bI~
    if (Ppucs)                                                     //~v61hR~
    {                                                              //~v61hI~
//      rcutf=utfgetwc(wko,olen,Ppucs,&chklen);                    //~v61hI~//~v6BkR~
        rcutf=utfgetwc(wko,(int)olen,Ppucs,&chklen);               //~v6BkI~
        if (rcutf)                                                 //~v61hI~
            rc=-1;                                                 //~v61hI~
    }                                                              //~v61hI~
    if (Ppreadlen)                                                 //~v61hR~
    	*Ppreadlen=readlen;                                        //~v61hR~
	return rc;                                                     //~v61bI~
}//utfcviconvdbcschk1                                              //~v61bI~
#endif  //LNX                                                      //~v61bR~
#ifdef LNX                                                         //~v6f3I~
//**************************************************************** //~v6f3I~
// utfcvlocaleinitICU                                              //~v6f3I~
// get converter set by udbcschk                                   //~v6f3I~
//ret:4 err ,8:iconv open err                                      //~v6f3I~
//**************************************************************** //~v6f3I~
int utfcvlocaleinitICU(int Popt,char *Pplocale)                    //~v6f3I~
{                                                                  //~v6f3I~
    int rc=0;                                                      //~v6f3I~
	ULONG phconv;                                                  //~v6f3I~
//****************************                                     //~v6f3I~
// 	if ((Popt & UTFCLIO_DEFAULTCHK))     //call from xeutf_init    //~v6f3R~
//    	strcpy(Pplocale,utfcvsetdefaultlocale()); //default was set by ICU//~v6f3R~
    udbcschk_getbaseconverter(0,&phconv,&Sdbcstbl);  //{codepage|toucs+fromucs},dbcs leadbyte tbl//~v6f3I~
//  Spconverters=(ULONG)phconv;//udbcschk_getbaseconverter output  //~v6f3I~//~v6hhR~
    Spconverters=(ULPTR)phconv;//udbcschk_getbaseconverter output  //~v6hhI~
	strncpy(Slocale,Pplocale,MAXLOCALESZ-1);                       //~v6f3I~
    return rc;                                                     //~v6f3I~
}//utfcvlocaleinitICU                                              //~v6f3I~
#endif  //LNX                                                      //~v6f3I~
//**************************************************************** //~v6f3I~
//!utfcvf2lany1ICU                                                 //~v6f3I~
//local<-utf8   using local ICU converter                          //~v6f3I~
//Warning:do translation only 1 char                               //~v6f3I~
//rc:UTFCVRC_ERRSTO/UTFCV_BUFFOVF                                  //~v6f3R~
//**************************************************************** //~v6f3I~
//int utfcvf2lany1ICU(int Popt,char *Pplocale,ULONG *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5R~
int utfcvf2lany1ICU(int Popt,char *Pplocale,ULPTR *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5I~
			int *Ppchklen,int *Ppoutlen)                           //~v6f3I~
{                                                                  //~v6f3I~
//  ULONG /*pconverter,*/pconverters;                                  //~v6f3R~//~v6f7R~//~v6hhR~
    ULPTR /*pconverter,*/pconverters;                              //~v6hhI~
    int rc=0,readlen=1,writelen=1,opt;                                 //~v6f3R~//~v6f7R~
//****************************                                     //~v6f3I~
    UTRACED("utfcvf2lany1ICU in",Pinp,Pinplen);                    //~v6f3R~
    if (UTF8ISASCII(*Pinp))                                        //~v6f3I~
    {                                                              //~v6f3I~
		if (Poutbufflen<1)                                         //~v6f3I~
    		rc=UTFCVRC_ERROVF;                                     //~v6f3I~
        else                                                       //~v6f3I~
        	*Pout=*Pinp;                                           //~v6f3I~
    }                                                              //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
        if (Pphandle && *Pphandle)                                 //~v6f3I~
//          pconverter=*Pphandle;                                  //~v6f3I~//~v6f7R~
            pconverters=*Pphandle;                                 //~v6f7I~
        else                                                       //~v6f3I~
        {                                                          //~v6f3I~
            udbcschk_getbaseconverter(0,&pconverters,0);           //~v6f3R~
//          pconverter=*(ULONG*)pconverters;                       //~v6f3R~//~v6f7R~
            if (Pphandle)                                          //~v6f3I~
//              *Pphandle=pconverter;                              //~v6f3I~//~v6f7R~
                *Pphandle=pconverters;                             //~v6f7I~
        }                                                          //~v6f3I~
        opt=UCVEXTO_SETSUBCHRC;                                    //~v6f7R~
//      rc=ucvext_icuutf2mb1(opt,(ULONG*)pconverters,Pinp,Pinplen,Pout,Poutbufflen,&readlen,&writelen);//~v6f3R~//~v6f7R~//~v6hhR~
        rc=ucvext_icuutf2mb1(opt,(ULPTR*)pconverters,Pinp,Pinplen,Pout,Poutbufflen,&readlen,&writelen);//~v6hhI~
        if (rc)                                                    //~v6f3I~
        {                                                          //~v6f3I~
	        if (rc==UCVEXTRC_BUFFOVF)                              //~v6f3I~
        		rc=UTFCVRC_ERROVF;                                //~v6f3I~//~v6f7R~
    	    else                                                   //~v6f3I~
        		rc=UTFCVRC_ERRSTOP;                                //~v6f3I~
//          readlen=0;		//for ucvmb2utf                        //~v6f7I~//~v6fkR~
//          writelen=0;                                            //~v6f7I~//~v6fkR~
        }                                                          //~v6f3I~
    }                                                              //~v6f3I~
    if (Ppchklen)                                                  //~v6f3I~
	    *Ppchklen=readlen;                                         //~v6f3I~
    if (Ppoutlen)                                                  //~v6f3I~
	    *Ppoutlen=writelen;                                        //~v6f3I~
    UTRACEP("utfcvf2lany1ICU rc=%d\n");                            //~v6f3R~
    UTRACED("utfcvf2lany1ICU out",Pout,writelen);                  //~v6f3R~
    return rc;                                                     //~v6f3I~
}//utfcvf2lany1ICU                                                 //~v6f3I~
//**************************************************************** //~v6f3I~
//!utfcvl2fany1ICU                                                 //~v6f3I~
//locale->utf8 conversion using ICU(from ucvsmb2utf)               //~v6f3R~
//* rc:UTFCV_BUFFOVF/UTFCV_ERRSTOP                                 //~v6f3I~
//**************************************************************** //~v6f3I~
//int utfcvl2fany1ICU(int Popt,char *Pplocale,ULONG *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6f3I~//~v6hhR~
int utfcvl2fany1ICU(int Popt,char *Pplocale,ULPTR *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6hhI~
			int *Ppchklen,int *Ppoutlen)                           //~v6f3I~
{                                                                  //~v6f3I~
    int rc=0,readlen=1,writelen=1;                                 //~v6f3R~
//  ULONG convdbcs[2],pconverters,pconverter;                      //~v6f3R~//~v6hhR~
    ULPTR convdbcs[2],pconverters,pconverter;                      //~v6hhI~
static UCHAR *Spdbcstbl;                                           //~v6f3I~
//****************************                                     //~v6f3I~
    UTRACED("utfcvl2fany1ICU in",Pinp,Pinplen);                    //~v6f3I~
    if (UTF8ISASCII(*Pinp))                                        //~v6f3I~
    {                                                              //~v6f3I~
		if (Poutbufflen<1)                                         //~v6f3I~
    		rc=UTFCVRC_ERROVF;                                     //~v6f3I~
        else                                                       //~v6f3I~
        	*Poututf8=*Pinp;                                       //~v6f3R~
    }                                                              //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
        if (Pphandle && *Pphandle)                                 //~v6f3I~
            pconverter=*Pphandle;                                  //~v6f3I~
        else                                                       //~v6f3I~
        {                                                          //~v6f3I~
            udbcschk_getbaseconverter(0,&pconverters,&Spdbcstbl);  //~v6f3R~
//          pconverter=*(ULONG*)pconverters;                       //~v6x5R~
            pconverter=*(ULPTR*)pconverters;                       //~v6x5I~
            if (Pphandle)                                          //~v6f3I~
                *Pphandle=pconverter;                              //~v6f3I~
        }                                                          //~v6f3I~
        convdbcs[0]=pconverter;                                    //~v6f3I~
//      convdbcs[1]=(ULONG)Spdbcstbl;                              //~v6f3R~//~v6hhR~
        convdbcs[1]=(ULPTR)Spdbcstbl;                              //~v6hhI~
		rc=ucvext_icumb2utf1(UCVEXTO_SETSUBCHRC,convdbcs,Pinp,Pinplen,Poututf8,Poutbufflen,&readlen,&writelen);//~v6f3R~//~v6f7R~
        if (rc)                                                    //~v6f3I~
        {                                                          //~v6f3I~
	        if (rc==UCVEXTRC_BUFFOVF)                              //~v6f3I~
        		rc=UTFCVRC_ERROVF;                                //~v6f3I~//~v6f7R~
    	    else                                                   //~v6f3I~
        		rc=UTFCVRC_ERRSTOP;                                //~v6f3I~
            readlen=0;		//for ucvmb2utf                        //~v6f7I~
            writelen=0;                                            //~v6f7I~
        }                                                          //~v6f3I~
    }                                                              //~v6f3I~
    if (Ppchklen)                                                  //~v6f3I~
	    *Ppchklen=readlen;                                         //~v6f3I~
    if (Ppoutlen)                                                  //~v6f3I~
	    *Ppoutlen=writelen;                                        //~v6f3I~
    UTRACEP("utfcvl2fany1ICU rc=%d,readlen=%d\n",rc,readlen);      //~v6f3I~
    UTRACED("utfcvl2fany1ICU out",Poututf8,writelen);              //~v6f3I~
    return rc;                                                     //~v6f3I~
}//utfcvl2fany1ICU                                                 //~v6f3R~
//**************************************************************** //~v6f3I~
// utfsetcvdefaultlocaleICU                                        //~v6f3I~
//ret:4 err                                                        //~v6f3I~
//**************************************************************** //~v6f3I~
char *utfcvsetdefaultlocaleICU(int Popt)                           //~v6f3I~
{                                                                  //~v6f3I~
	char *pc;                                                      //~v6f3I~
//******************                                               //~v6f3I~
	Sswgeticu=1;  //for utflocalechk                               //~v6f3I~
	pc=utfcvsetdefaultlocale();                                    //~v6f3I~
	Sswgeticu=0;                                                   //~v6f3I~
    UTRACEP("utfcvsetdefaultlocaleICU ret=%s\n",pc);               //~v6f3I~
    return pc;                                                     //~v6f3I~
}//utfcvsetdefaultlocaleICU                                        //~v6f3I~
//**************************************************************** //~v6f3I~
//!utflocalechkICU                                                 //~v6f3I~
//chk validity locale codeid                                       //~v6f3I~
//ret:4 err                                                        //~v6f3I~
//**************************************************************** //~v6f3I~
int utflocalechkICU(int Popt,char *Pplocale)                       //~v6f3I~
{                                                                  //~v6f3I~
//  ULONG pcv;                                                     //~v6f3I~//~v6hhR~
    ULPTR pcv;                                                     //~v6hhI~
    int rc;                                                        //~v6f3I~
//****************************                                     //~v6f3I~
	if (ucvext_icugetmbconverter(0,Pplocale,&pcv))                 //~v6f3I~
    	rc=4;                                                      //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f7I~
    	rc=0;                                                      //~v6f3I~
		ucvext_icuclose(0,pcv);                                        //~v6f3I~//~v6f7R~
    }                                                              //~v6f7I~
    UTRACEP("utflocalechkICU rc=%d,charset=%s\n",Pplocale);        //~v6f3I~
    return rc;                                                     //~v6f3I~
}//utflocalechkICU                                                 //~v6f3I~
#endif  //UTF8SUPPH                                                //~v6hhR~
#ifdef LNX                                                         //~v6uMI~
//**************************************************************** //~v6uMI~
//get utf8 strlen except ascii/c2xx/c3xx                           //~v6uMI~
//**************************************************************** //~v6uMI~
int utfgetstrlenHK(int Popt,char *Pu8,int Plen)                    //~v6uMI~
{                                                                  //~v6uMI~
	char *pc;                                                      //~v6uMI~
    int ii,ch,u8len;                                               //~v6uMI~
//*************************                                        //~v6uMI~
    UTRACED("pu8",Pu8,Plen);                                       //~v6uMI~
    for (ii=Plen,pc=Pu8;ii>0;ii--,pc++)                            //~v6uMI~
    {                                                              //~v6uMI~
    	ch=*pc;                                                    //~v6uMI~
        if (UTF8ISASCII(ch))                                       //~v6uMR~
        {                                                          //~v6uMI~
			if (Popt & UTFCVO_ASCIIRET)                            //~v6uMI~
	            break;                                             //~v6uMI~
        }                                                          //~v6uMI~
        else                                                       //~v6uMI~
	  	if (UTF8_IS80FF(ch))	//0x80<-->0xff                     //~v6uMI~
	            break;                                             //~v6uMI~
    }                                                              //~v6uMI~
	u8len=PTRDIFF(pc,Pu8);                                         //~v6uMI~
    UTRACEP("%s:u8len=%d\n",UTT,u8len);                            //~v6uMI~
    return u8len;                                                  //~v6uMI~
}//utfgetstrlenHK                                                  //~v6uMI~
#endif                                                             //~v6uMI~
