//*CID://+v70kR~:                              update#=  803;      //+v70kR~
//**************************************************
//*DBCS first byte chk
//*parm :char to be checked
//*     :if 0,return 1 if dbcs environment exist                   //~v024I~
//*rc   :0-not DBCS first byte,1:DBCS first byte
//**************************************************
//v70k:200802 (ARM:BUG)uerrmsg always english mode                 //+v70kI~
//v70g:200715 (BUG)utfcvl2f retrns err when wcwidth=0 and output char same as input. it should set utf8 even width=0//~v70gI~
//v705:200616 ARM compiler warning;conditionally not initialized   //~v705I~
//vbmk:180813 (XE)for test,try mk_wcwidth_cjk(ambiguous:Wide DBCS) for visibility chk. use /YJ option//~vbmkI~
//v6Wv:180807 (W32:Bug) console version on chcp=50221, utfcvf2l output string is over MACMBCSLEN by esc seq such as "Esc$B!)"//~v6WvI~
//v6Hv:170127 (Lnx:BUG)crush by mem not alloc at term(Sxprintcmd was destroyed by Slocale at udbcschk.c by long locale when export LANG=C//~v6HvI~
//v6C5:160404 correct english msg "Warining"--"Warning"            //~v6C5I~
//v6BQ:160314 (W32)for top menu lang name disply,translate sys codepage to console codepage//~v6BQI~
//v6BG:131217 udbcschk_localeisdbcs is not never called            //~v6BGI~
//v6BE:160306 (W32)dbcstbl by Scodepage considering chcp           //~v6BEI~
//v6BB:160306 W32:set Gudbcschk_flag to UDBCSCHK_LANGMB4 when chcp:54936 on win console for udbcschk_getmblen//~v6BBI~
//v6BA:160303 W32:wcstombs and mbrtowc dose not support surrogate pair,use WIdeChar<-->Multibute api//~v6BAI~
//v6Bw:160227 no need to cv to surrogate on LNX                    //~v6BwI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6x5:150108 ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu     //~v6x5I~
//v6uQ:140606 unprintable for 0x00-0xff when local icumode;apply not icu by iswprint because print to scr is by ucs at uviom//~v6uQI~
//v6uP:140606 (BUG)printable chk coding err,isprint was ignored,iswprint only ;this may have no effect//~v6uPI~
//v6uh:140501 (Win:UNICODE) between UID,it is not DBCS             //~v6uhI~
//v6t2:140318 Warning if console codepage=65001(UTF8)              //~v6t2I~
//v6r0:131215 (ARM)warning strict aliasing                         //~v6r0I~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6he:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v6heI~
//v6hc:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(copile optio -Ox is required also)//~v6hcI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6fa:120424 (Axe) delete "Warning setlocale failed" msg, always faile for Android//~v6faI~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f5:120419 option to use ICU as B2M/M2B local converter         //~v6f5I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0R~
//v69f:100819 (BUG:W32)setlocale may return null if invalid code page was set//~v69fI~
//v699:100808 (BUG)display null as local env when /C option used   //~v699I~
//v696:100807 (WXE:BUG)reports from dsk1;mkwcwidth_cjk was applied for not DBCS env//~v696I~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v68g:100712 (BUG)env may .utf8(not only utf-8)                   //~v68gI~
//v680:100616 (LNX:BUG)sbcsid overflow msg by utility              //~v680I~
//v66D:100604 indicate not by outchar but by rc that SUBCHAR was set//~v66DI~
//v66u:100531 (Win:BUG)mb2ebc use mbrtowc to chk mblen, it should be output//~v66uI~
//v66n:100529 (LNX:BUG)m2b set errrep(no need to chk unprintable at ucs level but ebc level,more printable)//~v66nI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v646:100114 (BUG)setdbcstbl setfull err rep dose not set err to all byte//~v646I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v638:091117 (UTF8)skip setlocale errmsg for other than xe        //~v638I~
//v637:091117 (UTF8:BUG)on console,safe to mot use dbcs mode       //~v637I~
//v636:091117 (UTF8)utf8 errchar write back original code          //~v636I~
//v633:091115 (UTF8:LNX:BUG) setlocale "ko_kr.UHC" fail like as v62W//~v633I~
//            ignore setlocale err when parm specified,warning msg only.//~v633I~
//v62X:091107_compchkm                                             //~v62XI~
//v62W:091103_(BUG)setlocale fail when env has utf8 only. accept as no dbcs env.//~v62WI~
//            eg) At Ubuntu910 installed by lang=English, "locale -a" shows "en_US.UTF8" only, there is no "en_US"//~v62WI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62R:091015_(BUG)Slocaledbcstbl dbcsid is not set when locale=ECU-JP(not utf8)//~v62RI~
//v62P:091013_missing set UDBCSCHK_DBCSLANG flag if Windows        //~v62PI~
//v62M:091014_(LNX:BUG)It should back to original locale after setup unprintable//~v62MI~
//v62G:091005_(BUG)for isprint func;utfcvu2lany1mb is always success. isprint should be used//~v62GI~
//                 but for isprint setlocale should be issued for -Cparameter. v62F is now meaningless.//~v62GR~
//v62F:091005_(BUG)pass codepage/hiconv before utfisprint is called through utfcvu2lany1mb that use Spconverters initialized//~v62FI~
//v62A:091003_(WIN:BUG) should use wide API if console codepage is not same as system default.(Screen corruption)//~v62AI~
//v62z:091002_(WIN:BUG) missing to set Scodepage when SBCS         //~v62zI~
//v62y:091002_(WIN:BUG) DBCSJ should be clear if /C parameter specified//~v62yI~
//v62w:091002_(WIN:BUG)on C(J)K console,kbd input is utf8,but usaly do by locale mode//~v62wI~
//v62u:091011_(WIN:BUG) displayed default locale on top menu is not of dosprompt codepage setting//~v62uI~
//v62p:090916!add udbcschk_pos2offs                                //~v62pI~
//v627:090719 use setlocale when not UTF8(avoid dup req,reissue of setlocale(,"") reset to default locale)//~v627I~
//v624:090712 compile err on Z390(reported by Dirk@...de)          //~v624I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            mb len by dbcstbl                                    //~v620I~
//            force utf8->locale option(gnome:utf8,env:locale case)//~v620I~
//                       converter init for utf8 by wcinit call if no locare parm//~v620I~
//v5nE:090413 (BUG)rc chk miss for udbcschk_chklocale              //~v5nEI~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nv:081108 udbcschk may called before wcinit                    //~v5nvI~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5nk:081029 (LNX)use iswprint for >=0x80 for iso8859 on xxx.utf8 //~v5nkI~
//v5nj:081029 (LNX)set unprintable for also >=0x80 (Gpdbcstbl even if DBCS 1st)//~v5njI~
//v5na:080929 split udbcschk.c to udbcsck2.c                       //~v5naI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8R~
//v5n5:080907 GB18030(CP-54936) Windows CPinfo has no defined leadbyte//~v5n5I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mN:080803*accept PC98 gaiji                                    //~v5mNI~
//v61q:080126 (UTF)option to ignore dbcs other than euc for not utf8 support version//~v61qI~
//v61h:071225 (UTF:BUG)display err for locale file under UTF8 env  //~v61hI~
//v61g:071222 (UTF)locale<-->utf8 conversion support               //~v61gI~
//v61b:071205 (UTF:LNX)support locale other than EUC               //~v61bI~
//v61f:071126 (LNX)hankana(e8+xx) kbd input chk                    //~v61fI~
//v618:071201 (UTF)udirlist support sort by name by utf8           //~v618I~
//v614:071117 (UTF)EUC<->UTF8 conversion support                   //~v614I~
//v60e:071017 (UTF)add utfcve2f(euc to utf8)                       //~v60eI~
//v60a:070928 (UTF:WXE)                                            //~v60aI~
//v609:070918 (UTF:LNX)                                            //~v609I~
//v600:070717 sync by precompile with no /DUTF8SUPP option and xfc tool//~v600I~
//v5if:060620 (LNX:UTF)recomendation is not getenv("LANG") but setlocale(LC_ALL,"")//~v5ifI~
//v5i9:060601 (LNX:FC5)support UTF8 for other than japanese        //~v5i9I~
//v5i7:060601 (LNX:FC5)utf8 not yet supported but set no EUC flag but set utf8 flag//~v5i7I~
//v5g7:050613 (XXE)xxe support;no ttychk required for xxe,use LANG only//~v5g7I~
//v5ad:040105 support TZ=hhmm and DBCS=EUC/SJIS                    //~v582I~
//v582:030808 (LNX)under X;kterm/gterm(rh9)support EUC dbcs        //~v582I~
//v57p:030118 (AIX)display all ms932 char                          //~v57pI~
//v57f:021229 (BUG)last esc(B create invalid sjis                  //~v57fI~
//v57e:021228 sjis-->jis conv support                              //~v57eI~
//v57d:021228 sjis<->euc conv contline support                     //~v57dI~
//v570:021205 (WXE)get codepage by WIN API                         //~v570I~
//v570:020824 wxe support                                          //~v570I~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v560:020619 jis decoding support                                 //~v560I~
//v550:020413 string len change by euc<->sjis conv;consider for tabid on dbcstbl//~v550I~
//v549:020409 tabkeep should keep also tabexp id                   //~v549I~
//            (set sbcs when !noclear or dbcs1/2)                  //~v549I~
//v548:020406 (BUG)EUC hankaku-katakana(x8e+sjis-katakana) should drop x8e//~v548I~
//            when euc-->sjis with no zenkaku conv option          //~v548I~
//v513:011211 dbcs combination chk for AIX                         //~v513I~
//v512:011208 v511 for AIX                                         //~v513R~
//v511:011208 (BUG)no clear should be for tab only                 //~v511I~
//v50Y:011202 no clear option of ueucchk                           //~v50YI~
//v50b:010324 LINUX:ajust after merge                              //~v50bI~
//v40v:010122 AIX support:sjis chk(allow up to 2nd level kanji)    //~v40vI~
//v40o:001128 AIX support:DBCS 1stbyte/2nd byte split process required//~v40oI~
//v39P:010121 LINUX support:for xsub set sbcs even if euc when tty(not pty)//~v39PI~
//v39N:010121 LINUX support:jis X 208 chk(jis tbl chk)             //~v39NI~
//v39H:010120 LINUX support:drop undefined from jis range          //~v39HI~
//v39G:010114 LINUX support:under kon,chk max jis kanji <=0x7424 for SW3.5//~v39GI~
//v39F:010114 LINUX support:under kon,set unprintable when sbcs>=0x80 for screen stability//~v39FI~
//v39D:010114 LINUX support:dbcs err chk to avoid screen destroy unker kon//~v39DI~
//v39C:010114 LINUX support:rtn to clear dbcs tbl for force english even if euc//~v39CI~
//v39z:010113 LINUX support:dbcschk by euc code                    //~v39xI~
//v39x:010113 LINUX support:euc conversion(from jconv by  Ken R. Lunde)//~v39xI~
//v39k:001202 LINUX support:ujis chk for unprintable char          //~v39kI~
//v326 000813:LINUX support(DBCS code)                             //~v326R~
//v198:980926 parm may better be uusigned int for sjis to jis conv func//~v198I~
//v166:980426 (BUG)codepage 942(japan SAA) is also japanese on os2 //~v166I~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v140:980110 (W32)codepage 437 support(japanese=932)              //~v140I~
//                 GetCPInfo return system  default,use GetConsolCP for each consol//~v140I~
//v122:971124 add usjis2jis(shift jis to jis)                      //~v122I~
//v061:970208:(BUG)OS/2 only UDBCS table returned by DosQueryDBCSEnv length shortage//~v061I~
//            destroy naighborhood(for ex swsw3 for xprint)        //~v061I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -dos memory reff by DPMI func                        //~v053I~
//v051:961204:dbcs 2nd byte chk function                           //~v051I~
//v024 960901:dosquerydbcsenv-->udosquerydbcsenv                   //~v024R~
//            because dosquerydbcsenv need /NOI for link parm,     //~v024I~
//            or it must be declare as static.                     //~v024I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//**************************************************               //~v022I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v39PI~
	#include <unistd.h>                                            //~v39PI~
#else                                                              //~v609I~
//  #ifdef UTF8SUPP                                                //~v5mQR~
    #if defined(W32)||defined(LNX)                                 //~v5mQR~
		#include <locale.h>                                        //~v609I~
	#endif                                                         //~v609I~
#endif                                                             //~v39PI~
//*************************************************************
#ifdef UNX                                                         //~v326R~
	#ifdef LNX                                                     //~v582I~
#if !(defined(ARM) && defined(XXE))                                //~v6a0R~
//  #ifndef NOCURSES                                               //~v6j0R~
    #ifndef NOCURSES                                               //~v6k0R~
        #include <term.h>                                          //~v582I~
    #endif                                                         //~v6k0R~
//  #endif                                                         //~v6j0R~
#endif //ARMXXE                                                    //~v6a0I~
        #include <locale.h>                                        //~v5ifI~
      #ifdef UTF8SUPPH                                             //~v62XI~
       #ifndef ARM                                                 //~v6a0R~
	    #include <langinfo.h>                                      //~v62WI~
       #endif                                                      //~v6a0R~
      #endif                                                       //~v62XI~
//    #ifdef UTF8SUPP                                              //~v5mQR~
        #include <wchar.h>                                         //~v61bI~
		#include <iconv.h>                                         //~v5n8I~
		#include <wctype.h>                                        //~v5nkI~
//    #endif                                                       //~v5mQR~
    #endif                                                         //~v582R~
#else        //!LINUX                                              //~v326I~
#ifdef DOS
	#include <dos.h>
#else
    #ifdef W32                                                     //~v022I~
    	#include <windows.h>                                       //~v022I~
    	#include <wchar.h>                                         //~v5mQI~
      #ifdef WXE                                                   //~v570I~
    	#include <winnls.h>                                        //~v570I~
      #endif                                                       //~v570I~
    #else                                                          //~v022I~
	    #define INCL_BASE                                          //~v022R~
    	#include <os2.h>                                           //~v022R~
	#endif                                                         //~v022I~
#endif
#endif     //!UNX                                                  //~v326I~
//*************************************************************
#include <ulib.h>
#include <uerr.h>
#define UDBCSCHK_GBLDEF                                            //~v39kI~
#include <udbcschk.h>
#include <ustring.h>
#ifdef DPMI					//DPMI version                         //~v053I~
	#include <udpmisub.h>                                          //~v053I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
#include <utrace.h>                                                //~v57eI~
#ifndef DOSDOS                                                     //~v57pI~
	#include <ucvucs.h>                                            //~v57pI~
#endif                                                             //~v57pI~
#ifdef WCSUPP                                                      //~v5n8I~
	#include <ukbd.h>                                              //~v5n8I~
	#include <uvio.h>                                              //~v5n8I~
	#include <ucvebc.h>                                            //~v62UR~
	#include <ucvext.h>                                            //~v5n8I~
	#include <ucvext2.h>                                           //~v5n8I~
#endif                                                             //~v5n8I~
#ifdef UNX                                                         //~v582R~
	#include <ukbdl.h>                                             //~v582I~
#endif                                                             //~v582I~
                                                                   //~v5i9I~
#include <utf.h>                                                   //~v5i9I~
#ifdef UTF8UCS2                                                    //~v640I~
	#include <utf2.h>                                              //~v6a0I~
	#include <utf22.h>                                             //~v640I~
#endif                                                             //~v640I~
#include <ulibarm.h>                                               //~v6a0I~
#include <ufile.h>                                                 //~v6uhI~
#include <ufilew.h>                                                //~v6uhI~
//*******************************************************          //~v024I~
#define MAX_LEADBYTE_PAIR  8                                       //~v5n8I~
#ifdef UNX                                                         //~v39PI~
  #ifndef XXE                                                      //~v6a0I~
	int udbcschktty(void);                                         //~v39PI~
  #endif //XXE                                                     //~v6a0I~
//#ifdef UTF8SUPP                                                  //~v5mQR~
//  int udbcschk_locale_topbyte(UCHAR Pchar);                      //~v5mQR~
//#endif                                                           //~v5mQR~
#endif                                                             //~v39PI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
#ifdef LNX                                                         //~v61bR~
	int Sdbcschk_hkopt;                                            //~v61bI~
#endif                                                             //~v61bI~
#endif                                                             //~v61bI~
//*******************************************************          //~v39xI~
static	UCHAR *Sdbcsenv=NULL;                                      //~v024M~
static	char   Sdbcstbl[256];	                                   //~v024I~
        UCHAR  *Gpdbcstbl=Sdbcstbl;                                //~v5n8R~
static int Scodepage=0;                                            //~v5n8I~
#ifdef W32                                                         //~v62zI~
static int Scodepage2=0;                                           //~v62zI~
#endif                                                             //~v62zI~
#ifdef WCSUPP                                                      //~v5mQI~
//*******************************************************          //~v5mQI~
#ifdef LNX                                                         //~v5n8R~
//static UCHAR Slocaledbcstbl[256];                                //~v62UR~
//       UCHAR  *Gplocaledbcstbl=Slocaledbcstbl;                   //~v62UR~
static iconv_t Sconverters[2];     //to,from,dbcs starter          //~v5n8R~
#else                                                              //~v62UR~
//     UCHAR  *Gplocaledbcstbl=Sdbcstbl;                           //~v62UR~
#endif                                                             //~v5n8I~
static UCHAR Sleadbyte[MAX_LEADBYTE_PAIR*2];                       //~v5n8I~
static int Swcinitsw=0;                                            //~v5n8I~
//static int Scodepage=0;                                          //~v5n8R~
static UCHAR Scharset[MAXLOCALESZ];                                //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v627I~
    static int 	Smb2ndmblen;	//parm to udbcschk_mb2nd           //~v627I~
#endif                                                             //~v627I~
#ifdef W32                                                         //~v6BAI~
    CPINFOEX   Scpinfo;                                            //~v6BAI~
#endif                                                             //~v6BAI~
//*******************************************************          //~v5n8I~
//int udbcschk_wclocaleinit(int Popt,char *Pplocale);                //~v5n8I~//~v6f3R~
int udbcschk_wclocaleinit(int Popt,int Pdbcschkrc,char *Pplocale); //~v6f3I~
int udbcschk_wclocalereset(int Popt,char *Pplocale);               //~v5n8I~
int udbcschk_chklocale(int Popt,UCHAR *Pplocale,ULONG *Ppconverters);//~v5n8I~
int udbcschk_setdbcstype(int Popt,char *Plocale,ULONG Phiconv);    //~v62UR~
#ifdef LNX                                                         //~v6x5I~
int udbcschk_icugetlocalconverter(int Popt,char *Pplocale,ULONG *Ppconverter);//~v6f3R~
#endif                                                             //~v6x5I~
//*******************************************************          //~v5n8I~
//*********************** udbcschkcp()-rc * _WCDBCS * _EUC *_DBCSJ * _UTF8J * _UTF8CJK//~v5n8R~
//* Linux   EUC+UTF8           0            1         0     0        1        1//~v5n8R~
//*         EUC                1            0         1     1        0        0//~v5n8R~
//*         -cEUC              0            1         0     0        0        0//~v5n8R~
//*         Other DBCS+UTF8    0            1         0     0        0        1//~v5n8R~
//*         Other DBCS         0            1         0     0        0        0//~v5n8R~
//* Windows SJIS               1            0         0     1      //~v5n8R~
//*         -c932              0            1         0     0      //~v5n8R~
//*         Other DBCS         0            1         0     0      //~v5n8R~
//*******************************************************          //~v5n8I~
//*******************************************************          //~v5mQI~
//* DBCS other than Japanese env init                              //~v5mQI~
//* rc 1:japanese,2:other DBCS, 0:sbcs                             //~v5n8I~
//*******************************************************          //~v5mQI~
int udbcschk_wcinit(int Popt,char *Pplocale)                       //~v5n8R~
{                                                                  //~v5mQI~
//    setlocale(LC_ALL,"");       //for wcrtomb etc                //~v5n8R~
//    if (Popt & UDCWCIO_WCDBCSCHK)  //                            //~v5n8R~
//    {                                                            //~v5n8R~
//        if (udbcschk_getdbcs1st(0,Slocaledbcstbl))               //~v5n8R~
//            Gudbcschk_flag|=UDBCSCHK_WCDBCS;                     //~v5n8R~
//    }                                                            //~v5n8R~
//    return 0;                                                    //~v5n8R~
	int rc=0,opt;                                                  //~v5n8R~
	UCHAR locale[MAXLOCALESZ];                                     //~v5n8I~
    static int S1stsw;                                             //~v6f3I~
//**********************************                               //~v5n8I~
    if (!S1stsw)                                                   //~v6f3I~
    {                                                              //~v6f3I~
    	S1stsw=1;                                                  //~v6f3I~
    	udbcschk_setlocale(0,LC_ALL,0/*set system default*/);//required fot ICU getdefaultname//~v6f3I~
    }                                                              //~v6f3I~
    UTRACEP("udbcschk_wcinit opt=%x\n",Popt);                      //~v6b9I~
	if (Popt & UDCWCIO_UTF8VERSION)                                //~v5n8R~
    	Gudbcschk_flag|=UDBCSCHK_UTF8VER;                          //~v5n8R~
	if (Popt & UDCWCIO_BEFOREINIT)                                 //~v5nvI~
    {                                                              //~v5nvI~
    	Gudbcschk_flag|=UDBCSCHK_BEFOREINIT;	//force english before wcinit complete//~v5nvI~
        return 0;                                                  //~v5nvI~
    }                                                              //~v5nvI~
    Gudbcschk_flag&=~UDBCSCHK_BEFOREINIT;	//wcinit called        //~v5nvI~
	if (Popt & UDCWCIO_CJK)                                        //~vbmkI~
		Gulibutfmode|=GULIBUTF_CJK; //          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
#ifdef LNX                                                         //~v637I~
  #ifndef XXE   //console version                                  //~v637I~
	if (udbcschktty())                                             //~v637I~
	    Gudbcschk_flag|=UDBCSCHK_TTYCONS;	//on console           //~v637I~
  #endif                                                           //~v637I~
#endif                                                             //~v637I~
	if (!(Popt & UDCWCIO_INTERNAL))                                //~v638I~
	    Gudbcschk_flag|=UDBCSCHK_EXPLICIT;  //caller is xe,acb     //~v638I~
	if (Popt & UDCWCIO_RESETLOCALE)                                //~v5n8I~
    {                                                              //~v5n8I~
//* RESETLOCALE:currrently no user                                 //~v6f3I~
        Swcinitsw=1;                                               //~v5n8I~
        udbcschkcp();    //                                        //~v5nvI~
        if (udbcschk_wclocalereset(Popt,Pplocale))                 //~v5n8I~
        	return 8;                                              //~v5n8I~
    }                                                              //~v5n8I~
    else                                                           //~v5n8I~
    {                                                              //~v5n8I~
		if (Popt & UDCWCIO_FORCELOCALE)                            //~v5n8I~
    	{                                                          //~v5n8I~
//* from xe when -C option specified                               //~v6f3I~
        	Swcinitsw=1;                                           //~v5n8I~
	        udbcschkcp();    //                                    //~v5nvI~
        	if (udbcschk_wclocalereset(Popt,Pplocale))	//set Scodepage,Senv//~v5n8I~
        		return 8;                                          //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62GI~
            utfcvlocaleinit(0,Pplocale);//converter init for utf2 by defaultlocale//~v620I~//~v62FR~//~v62GR~
#endif                                                             //~v62GI~
    	}                                                          //~v5n8I~
        else                                                       //~v5n8I~
        if (!Swcinitsw)                                            //~v5n8R~
        {                                                          //~v5n8R~
//  		if (Popt & UDCWCIO_FORCELOCALE)                        //~v627I~//~v624R~
//      		utfforcelocale(Popt,Pplocale);	//notifiy charset change//~v627I~//~v624R~
UTRACEP("wcinit sw=%x opt=%x,locale=%s\n",Swcinitsw,Popt,Pplocale);//~v627R~
            Swcinitsw=1;                                           //~v5n8M~
   		  if (Popt & UDCWCIO_LOCALICU)	//use ICU for localconverter//~v6f3I~
            ucvext_setdefaultlocale(0,locale);                     //~v6f3R~
          else                                                     //~v6f3I~
            UstrncpyZ(locale,utfcvsetdefaultlocale(),MAXLOCALESZ); //~v5n8I~
            if (ustrstri(locale,LOCALEID_UTF8)||ustrstri(locale,LOCALEID_UTF_8))//~v62WI~
            	Gudbcschk_flag|=UDBCSCHK_LANGUTF8;                 //~v62WI~
            if (Pplocale)                                          //~v5n8I~
	            UstrncpyZ(Pplocale,locale,MAXLOCALESZ);            //~v5n8I~
            rc=udbcschkcp();    //                                 //~v5n8R~
//          udbcschk_wclocaleinit(rc,locale);                      //~v5n8R~//~v6f3R~
            udbcschk_wclocaleinit(Popt,rc,locale);                 //~v6f3I~
#ifdef UTF8SUPPH                                                   //~v62GI~
            utfcvlocaleinit(UTFCLIO_DEFAULTCHK,locale);//converter init for utf2 by defaultlocale//~v620I~//~v62FR~//~v62GR~
#endif                                                             //~v62GI~
        }//initsw                                                  //~v5n8R~
    }                                                              //~v5n8I~
    UTRACEP("udbcschk_wcinit rc=%d, udbcschkflag=%08x\n",rc,Gudbcschk_flag);//~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62UR~
    if (!UDBCSCHK_ISDBCS())                                        //~v62UR~
    	Popt &= ~UDCWCIO_DBCSREAD;	//ignore DBCS read             //~v62UR~
#endif                                                             //~v62UR~
#ifdef LNX                                                         //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62UR~
 	opt=Popt;                                                      //~v62UR~
#else                                                              //~v62UR~
	opt=0;                                                         //~v5n8I~
#endif                                                             //~v62UR~
	if (Gudbcschk_flag & UDBCSCHK_UTF8)      //locale is UTF8      //~v5n8R~
        opt=Popt|UDCWCIO_KBDUTF8;                                  //~v5n8I~
    if (UDBCSCHK_ISWCDBCS())                 //CJK                 //~v5n8R~
        opt|=UDCWCIO_WCDBCS;                                       //~v5n8I~
    ukbdl_wcinit(opt,(ULONG)Sconverters,Scharset);   //read unicode mode//~v5n8R~
#ifndef XSUB                                                       //~v6j0I~
    uvio_wcinit(opt,(ULONG)Sconverters);   //uvio unicode mode     //~v5n8R~
#endif                                                             //~v6j0I~
#else                                                              //~v5n8I~
	if (Popt & UDCWCIO_FORCEWIDE                                   //~v5n8M~
    ||  Gudbcschk_flag & UDBCSCHK_CONSCP //ConsoleCP!=SYSTEM Default//~v62AI~
    ||	 UDBCSCHK_ISWCDBCS())                                      //~v5n8M~
    {                                                              //~v5n8M~
		Gudbcschk_flag|=UDBCSCHK_WINUTF8;//  0x020000  //windows kbd input by wide api//~v62wI~
        opt=Popt|UDCWCIO_WIDEAPI;       //use Widechar API         //~v5n8M~
	    ukbd_wcinit(opt,Scodepage);   //read unicode mode          //~v5n8R~
#ifndef XSUB                                                       //~v6j0I~
	    uvio_wcinit(opt,Scodepage);   //uvio unicode mode          //~v5n8R~
#endif                                                             //~v6j0I~
    }                                                              //~v5n8M~
#endif                                                             //~v5n8M~
#ifdef UTF8SUPPH                                                   //~v620I~
    utf_init(0);                                                   //~v620I~
#endif                                                             //~v620I~
    udbcschk_setlocale(0,LC_ALL,0/*set system default*/);	//back to original is required for vio(when /c specified,isprint is not for the cp)//~v62UR~
#ifdef UTF8UCS2                                                    //~v640M~
  if ((Gudbcschk_flag & UDBCSCHK_EXPLICIT))  //caller is xe,acb    //~v680I~
  {                                                                //~v6b9I~
    UTRACEP("udbcschk_wcinit call utfucsmapinit\n");               //~v6b9I~
	utfucsmapinit(0);    //after setlocale to system default for wcwidth()//~v640I~
  }                                                                //~v6b9I~
#endif                                                             //~v640M~
    UTRACEP("udbcschk_wcinit rc=%d, udbcschkflag=%08x,system locale=%s\n",rc,Gudbcschk_flag,setlocale(LC_ALL,NULL));//~v62MI~
    UTRACEP("wcinit last locale=%s\n",setlocale(LC_ALL,NULL));     //~v62UR~
    return rc;                                                     //~v5n8I~
}//udbcschk_wcinit                                                 //~v5mQI~
//*******************************************************          //~v5n8I~
//* return base(local) converter                                   //~v6f5R~
//*******************************************************          //~v5n8I~
//int udbcschk_getbaseconverter(int Popt,ULONG *Ppconverters,UCHAR **Pppdbcstbl)//~v5n8R~//~v6hhR~
int udbcschk_getbaseconverter(int Popt,ULPTR *Ppconverters,UCHAR **Pppdbcstbl)//~v6hhI~
{                                                                  //~v5n8I~
	int rc=0;                                                      //~v5n8I~
    UCHAR *pdbcstbl;                                               //~v5n8I~
//**********************************                               //~v5n8I~
#ifdef W32                                                         //~v5n8I~
	*Ppconverters=Scodepage;                                       //~v5n8R~
#else                                                              //~v5n8I~
	if (Sconverters[0])                                            //~v5n8R~
		*Ppconverters=(ULONG)Sconverters;                          //~v5n8R~
    else                                                           //~v5n8I~
    	rc=4;                                                      //~v5n8I~
#endif                                                             //~v5n8I~
//#ifdef LNX                                                       //~v62UR~
//    if (Gudbcschk_flag & UDBCSCHK_UTF8CJK)    //utf8 of dbcs lang//~v62UR~
//        pdbcstbl=Slocaledbcstbl;                                 //~v62UR~
//    else                                                         //~v62UR~
//#endif                                                           //~v62UR~
        pdbcstbl=Sdbcstbl;                                         //~v5n8I~
    if (Pppdbcstbl)                                                //~v5n8I~
    {                                                              //~v6f5I~
	  if (Popt & UDCGBC_CHARSET)        //get not dbcstb but charset//~v6f5I~
    	*Pppdbcstbl=Scharset;                                      //~v6f5I~
      else                                                         //~v6f5I~
    	*Pppdbcstbl=pdbcstbl;                                      //~v5n8I~
    }                                                              //~v6f5I~
    return rc;                                                     //~v5n8I~
}//udbcschk_getbaseconverter                                       //~v5n8R~
//*******************************************************          //~v5n8I~
//* setup unprintable char map for 0x00->0x7f                      //~v5n8I~
//*******************************************************          //~v5n8I~
int udbcschk_setunprintable(int Popt,UCHAR *Pctypetbl)             //~v5n8R~
{                                                                  //~v5n8I~
	int rc=0,ii;                                                   //~v5n8R~
    UCHAR *pc;                                                     //~v5n8I~
#ifdef LNX                                                         //~v6r0I~
    iconv_t *pconverters;                                          //~v6r0R~
    ULONG *pul;                                                    //~v6r0R~
#endif //LNX                                                       //~v6r0M~
//**********************************                               //~v5n8I~
//  for (ii=0,pc=Pctypetbl;ii<0x80;ii++,pc++)                      //~v5n8R~//~v5njR~
    for (ii=0,pc=Pctypetbl;ii<256;ii++,pc++)                       //~v5njI~
    {                                                              //~v5n8I~
#ifdef LNX                                                         //~v5ntI~
//      if (ii==SS3 && UDBCSCHK_ISEUCJ())   //prefix of 2nd level KANJI(EUC-JP)//~v5ntI~//~v62UR~
        if (ISSS3(ii))   //prefix of 2nd level for EUC (JP or KR)  //~v62UR~
        {                                                          //~v5ntI~
         	*pc=*pc|UDBCSCHK_TYPESS3;	//printable but processed at uviom//~v5ntR~
            continue;                                              //~v5ntR~
        }                                                          //~v5ntI~
#endif //LNX                                                       //~v5ntI~
		if (!isprint(ii))                                          //~v5n8I~
      {//!isprint                                                  //~v6uPI~
//#ifndef AAA                                                        //~v62GI~//~v6uQR~
#ifdef WCSUPP                                                      //~v5nkI~
#ifdef LNX                                                         //~v5nkI~
//#ifndef AAA                                                        //~v62zR~//~v6uQR~
//  	if (!iswprint(ii)                                          //~v5nkR~//~v6f3R~
//  	if (!(UDBCSCHK_IS_LOCALICU() ? ucvext_icuisprint(0,(ULONG)Sconverters[0],ii) : iswprint(ii))//~v6f3R~//~v6f7R~
// 		if (!(UDBCSCHK_IS_LOCALICU() ? ucvext_icuisprint(0,(ULONG*)(ULONG)Sconverters,ii) : utfisprint(0,(ULONG)ii))//~v6f7R~//~v6f3R~//~v6r0R~
        pconverters=Sconverters;                                   //~v6r0R~
        pul=(ULONG*)(ULONG)pconverters;                            //~v6r0R~
//  	if (!iswprint((WUCS)ii))                                   //~v6uQR~//~v6BkR~
    	if (!iswprint((wint_t)ii))                                 //~v6BkR~
        if (!(UDBCSCHK_IS_LOCALICU() ? ucvext_icuisprint(0,pul,ii) : utfisprint(0,(ULONG)ii))//~v6r0M~
//#else                                                              //~v62zI~//~v6uQR~
//        if (!utfisprint(0,(ULONG)ii)                               //~v62zR~//~v6uQR~
//#endif                                                             //~v62zI~//~v6uQR~
#else                                                              //~v5nkI~
//  	if (!iswprint((WUCS)ii)                                    //~v5nkI~//~v6BkR~
    	if (!iswprint((wint_t)ii)                                  //~v6BkR~
#endif                                                             //~v5nkI~
#endif                                                             //~v5nkI~
//#endif//AAA                                                             //~v62GI~//~v6uQR~
		)                                                          //~v5nkI~
        {                                                          //~v5n8I~
        	rc++;                                                  //~v5n8I~
//        	*pc=UDBCSCHK_TYPEUNP;	//dbcs id=1                    //~v5n8I~//~v5njR~
         	*pc=*pc|UDBCSCHK_TYPEUNP;	//dbcs id=1,unp=2          //~v5njI~
        }                                                          //~v5n8I~
      }//!isprint                                                  //~v6uPI~
UTRACEP("setupprintable ii=%x, rc=%d,isprint=%x,iswprint=%d\n",ii,rc,isprint(ii),iswprint((wint_t)ii));//~v62zI~//~v62FR~//~v6a0R~//~v6f3R~//~v6BkR~
    }                                                              //~v5n8I~
	Gudbcschk_flag|=UDBCSCHK_UNPTBL;//   0x040000  //SBCS unprintable table was set//~v62GI~
UTRACEP("setunprintable by locale=%s\n",setlocale(LC_ALL,NULL));   //~v62UR~
UTRACED("dbcstbl",Pctypetbl,256);                                  //~v62UR~
    return rc;                                                     //~v5n8I~
}//udbcschk_setunprintable                                         //~v5n8I~
//*******************************************************          //~v5n8I~
//* locale init                                                    //~v5n8I~
//*******************************************************          //~v5n8I~
//int udbcschk_wclocaleinit(int Popt,char *Pplocale)                 //~v5n8I~//~v6f3R~
int udbcschk_wclocaleinit(int Popt,int Pdbcschkrc,char *Pplocale)  //~v6f3I~
{                                                                  //~v5n8I~
	int rc=0;                                                      //~v5n8R~
#ifdef LNX                                                         //~v5n8I~
    ULONG phiconv=(ULONG)Sconverters;                              //~v5n8I~
#endif                                                             //~v5n8I~
//**********************************                               //~v5n8I~
//if (Popt)   //udbcschk rc=1(Japanese(not Utf8))                  //~v5n8R~//~v6f3R~
  if (Pdbcschkrc)   //udbcschk rc=1(Japanese(not Utf8))            //~v6f3I~
  {                                                                //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
   if ((Popt & UDCWCIO_LOCALICU)	//use ICU for localconverter   //~v6f3R~
   && !udbcschk_icugetlocalconverter(0,Pplocale,(ULONG*)phiconv))  //~v6f3R~
   {                                                               //~v6f3I~
    memset(Sdbcstbl,0,sizeof(Sdbcstbl));                           //~v6f3R~
    *Sleadbyte=0;                                                  //~v6f3I~
	ucvext_icugetstarter(UCEIO_LOCALICU|UCEIO_OPENED,*(ULONG*)phiconv,Sdbcstbl);//~v6f3I~
	udbcschk_getlinuxleadbyte(0,Sdbcstbl,Sleadbyte);               //~v6f3I~
   }                                                               //~v6f3I~
   else                                                            //~v6f3I~
   {                                                               //~v6f3I~
	if (ucvext_iconvgetconverter(0,Pplocale,&phiconv))             //~v5n8I~
    	uerrexit("iconv failed for Locale:%s",0,                   //~v5n8I~
        			Pplocale);                                     //~v5n8I~
	ucvext_iconvgetstarter(0,phiconv,Sdbcstbl,Sleadbyte);//reset by iconv//~v62UR~
   }                                                               //~v6f3I~
//  Gplocaledbcstbl=Sdbcstbl;	//no need for UTF8                 //~v62UR~
    Sdbcsenv=Sleadbyte;                                            //~v62UR~
	udbcschk_setdbcstype(0,Pplocale,phiconv);                      //~v62UR~
                                                                   //~v62UR~
#endif                                                             //~v5n8I~
//  utfcvlocaleinit(UTFCLIO_DEFAULTCHK,Pplocale);//pass Scodepage/Sconverter (through callback og getbaseconverter)//~v62FR~//~v62GR~
    udbcschk_setunprintable(0,Sdbcstbl);                           //~v5n8I~
//#ifdef LNX                                                       //~v62UR~
////  memcpy(Slocaledbcstbl,Sdbcstbl,128);    //copy unprintable   //~v62UR~
//    memcpy(Slocaledbcstbl,Sdbcstbl,256);    //copy unprintable and DBCS starter//~v62UR~
//#endif                                                           //~v62UR~
    Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                             //~v62UR~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
  {                                                                //~v5n8I~
#ifdef LNX                                                         //~v5n8M~
//  udbcschk_wclocalereset(Popt,Pplocale);                         //~v5n8R~//~v62GR~
//  udbcschk_wclocalereset(0,Pplocale);    //Popt & 0x01 is rc of udbcschkcp(japanese)//~v62GI~//~v6f3R~
    udbcschk_wclocalereset(Popt,Pplocale); //Popt of wcinit        //~v6f3I~
#else                                                              //~v5n8I~
	udbcschk_setdbcstype(0,Pplocale,(ULONG)Scodepage);//set MB4    //~v6BBI~
    udbcschk_setunprintable(0,Sdbcstbl);                           //~v62GI~
	if (Sdbcsenv && *Sdbcsenv)                                     //~v5n8R~
    {                                                              //~v62GI~
		Gudbcschk_flag|=UDBCSCHK_WCDBCS;                           //~v5n8R~
        Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                         //~v62PI~
    	UTRACED("udbcschk_wclocaleinit dbcsenv",Sdbcsenv,2);       //~v62GI~
    }                                                              //~v62GI~
#endif                                                             //~v5n8I~
  }                                                                //~v5n8I~
    UTRACEP("udbcschk_wclocaleinit rc=%d, udbcschkflag=%08x,system locale=%s\n",rc,Gudbcschk_flag,setlocale(LC_ALL,NULL));//~v62MI~
    UTRACED("udbcschk_wclocaleinit dbcstbl",Sdbcstbl,256);         //~v62GI~
    return rc;                                                     //~v5n8I~
}//udbcschk_wclocaleinit                                           //~v5n8I~
//*******************************************************          //~v5n8I~
//* locale reset                                                   //~v5n8R~
//* exit if err                                                    //~v5n8I~
//*******************************************************          //~v5n8I~
int udbcschk_wclocalereset(int Popt,char *Pplocale)                //~v5n8I~
{                                                                  //~v5n8I~
	int rc=0,dbcssw;                                               //~v5n8R~
    UCHAR dbcs1st[256];                                            //~v5n8M~
	UCHAR leadbyte[MAX_LEADBYTE_PAIR*2];                           //~v5n8I~
    ULONG phiconv;                                                 //~v5n8M~
	ULONG cp;                                                      //~v5n8M~
#ifdef UTF8SUPPH                                                   //~v62GI~
	UCHAR parmlocale[MAXLOCALESZ],*pc;                             //~v62GR~
//  int rc2;                                                       //~v62GI~//~v6b9R~
#endif                                                             //~v62GI~
#ifdef LNX                                                         //~v5n8I~
    iconv_t converters[2];                                         //~v5n8R~
#endif                                                             //~v5n8I~
//**********************************                               //~v5n8I~
    UTRACEP("udbcschk_wclocalereset opt=%x,locale=%s\n",Popt,Pplocale);//~v62GI~
#ifdef UTF8SUPPH                                                   //~v62GI~
    UstrncpyZ(parmlocale,Pplocale,MAXLOCALESZ);	//save originale  for setlocale with country//~v62GR~
	if (Popt & UDCWCIO_FORCELOCALE) //with /C parm                 //~v62GR~
    {                                                              //~v62GI~
    	pc=strchr(Pplocale,'.');    //with country.codepage pattern//~v62GI~
        if (pc)                                                    //~v62GI~
        	strcpy(Pplocale,pc+1); 	//drop country for iconv/wincp //~v62GR~
    }                                                              //~v62GI~
#endif                                                             //~v62GI~
	                                                               //~v62GI~
#ifdef LNX                                                         //~v5n8I~
    phiconv=(ULONG)converters;                                     //~v5n8I~
#else                                                              //~v5n8I~
#endif                                                             //~v5n8I~
//  if (udbcschk_chklocale(Popt,Pplocale,&phiconv)<0)              //~v5n8R~//~v5nER~
    if (udbcschk_chklocale(Popt,Pplocale,&phiconv))                //~v5nEI~
    {                                                              //~v5n8I~
//  	uerrexit("Locale parameter:%s is invalid",0,               //~v620I~
    	uerrexit("Charset parameter:%s is invalid",0,               //~v5n8I~//~v624R~
        			Pplocale);                                     //~v5n8I~
    }                                                              //~v5n8I~
  if (!(Gudbcschk_flag & UDBCSCHK_LANGUTF8))                       //~v62WR~
	udbcschk_setdbcstype(0,Pplocale,phiconv);                      //~v62UR~
#ifdef LNX                                                         //~v5n8I~
    dbcssw=0;                                                      //~v62WI~
  if (!(Gudbcschk_flag & UDBCSCHK_LANGUTF8))                       //~v62WR~
  {                                                                //~v62WI~
//  if ((dbcssw=ucvext_iconvgetstarter(0,phiconv,dbcs1st,leadbyte)))//~v5n8I~//~v6f3R~
	if (UDBCSCHK_IS_LOCALICU())                                    //~v6f3R~
    {                                                              //~v6f3I~
		if (ucvext_icugetstarter(UCEIO_LOCALICU|UCEIO_OPENED,*(ULONG*)phiconv,dbcs1st))//~v6f3R~
        {                                                          //~v6f3I~
        	memset(dbcs1st,0,sizeof(dbcs1st));                     //~v6f3I~
            *leadbyte=0;                                           //~v6f3I~
        }                                                          //~v6f3I~
        else                                                       //~v6f3I~
			dbcssw=udbcschk_getlinuxleadbyte(0,dbcs1st,leadbyte)>0; //leadbyte ctr//~v6f3R~
    }                                                              //~v6f3I~
    else                                                           //~v6f3I~
    	dbcssw=ucvext_iconvgetstarter(0,phiconv,dbcs1st,leadbyte); //~v6f3I~
    if (dbcssw)                                                    //~v6f3I~
    {                                                              //~v5n8I~
        if (Gudbcschk_flag & UDBCSCHK_UTF8)      //locale is not UTF8 but may be Chinese or Korea//~v5n8R~
        {                                                          //~v5n8R~
//          memcpy(Slocaledbcstbl,dbcs1st,256);                    //~v62UR~
            memcpy(Sdbcstbl+128,dbcs1st+128,128);                  //~v62UR~
//          *leadbyte=0;                                           //~v62UR~
            Gudbcschk_flag|=UDBCSCHK_UTF8CJK;                      //~v5n8R~
        }                                                          //~v5n8R~
        else                                                       //~v5n8R~
        {                                                          //~v5n8R~
            memcpy(Sdbcstbl+128,dbcs1st+128,128);                  //~v5n8R~
            Gudbcschk_flag&=~UDBCSCHK_UTF8CJK;                     //~v5n8I~
//          Gplocaledbcstbl=Sdbcstbl;	//no need for UTF8         //~v62UR~
        }                                                          //~v5n8R~
    }                                                              //~v5n8R~
    cp=437;                                                        //~v5nvI~
    if (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J))            //~v5nvI~
    {                                                              //~v5nvI~
        if (!ustrstri(Pplocale,"EUC") || !ustrstri(Pplocale,"JP")) //~v5nvR~
        {                                                          //~v5nvI~
			Gudbcschk_flag &=~(UDBCSCHK_EUC|UDBCSCHK_UTF8J|UDBCSCHK_DBCSJ);//~v5nvR~
			Gudbcschk_flag |=UDBCSCHK_FORCENONJ;                   //~v5nvR~
        }                                                          //~v5nvI~
        else                                                       //~v5nvI~
			Gudbcschk_flag |=UDBCSCHK_FORCEUCJ;                    //~v5nvI~
    }                                                              //~v5nvI~
    else                                                           //~v5nvI~
    {                                                              //~v5nvI~
        if (ustrstri(Pplocale,"EUC") && ustrstri(Pplocale,"JP"))   //~v5nvR~
        {                                                          //~v5nvI~
			Gudbcschk_flag |=UDBCSCHK_FORCEUCJ;                    //~v5nvI~
#ifdef ARM            	                                           //+v70kI~
			if (Gudbcschk_flag & UDBCSCHK_UTF8)                    //+v70kI~
            {                                                      //+v70kI~
				Gudbcschk_flag |=UDBCSCHK_UTF8J;                   //+v70kI~
				Gudbcschk_flag &=~UDBCSCHK_UTF8E;                  //+v70kI~
            }                                                      //+v70kI~
#endif                                                             //+v70kI~
        }                                                          //~v5nvI~
    }                                                              //~v5nvI~
    memcpy(Sleadbyte,leadbyte,sizeof(Sleadbyte));                  //~v5n8I~
  }                                                                //~v62WI~
  else                                                             //~v705I~
    cp=437;     //Scodepage is not unsed on LNX                    //~v705I~
                                                                   //~v705I~
    memcpy(Sconverters,converters,sizeof(Sconverters));            //~v5n8I~
    UTRACED("converters",Sconverters,sizeof(Sconverters));         //~v5n8R~
//  cp=437;                                                        //~v5n8I~//~v5nvR~
#else                                                              //~v5n8I~
	cp=phiconv;                                                    //~v5n8R~
	if ((dbcssw=udbcschk_getstarter(0,cp,dbcs1st,leadbyte))<0)     //~v5n8I~
    	return 4;                                                  //~v5n8I~
    memcpy(Sleadbyte,leadbyte,sizeof(Sleadbyte));                  //~v5n8R~
	memcpy(Sdbcstbl+128,dbcs1st+128,128);                          //~v5n8R~
	Gudbcschk_flag &=~(UDBCSCHK_DBCSJ|UDBCSCHK_MS932);             //~v62yI~
#endif                                                             //~v5n8I~
    Sdbcsenv=Sleadbyte;                                            //~v5n8I~
//  Scodepage=cp;                                                  //~v5n8I~//~v6BkR~
    Scodepage=(int)cp;                                             //~v6BkI~
    UTRACEP("udbcschk_wclocalereset Scodepage=%d\n",Scodepage);    //~v62yI~
    UstrncpyZ(Scharset,Pplocale,MAXLOCALESZ);                      //~v5n8I~
    if (dbcssw)                                                    //~v5n8I~
    {                                                              //~v62PI~
       Gudbcschk_flag|=UDBCSCHK_WCDBCS;                            //~v5n8I~
       Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                          //~v62PI~
UTRACEP("wcdbcs\n");                                               //~v62PI~
    }                                                              //~v62PI~
    else                                                           //~v5n8I~
    {                                                              //~v696I~
       Gudbcschk_flag&=~UDBCSCHK_WCDBCS;                           //~v5n8I~
       Gudbcschk_flag&=~UDBCSCHK_DBCSLANG;                         //~v696I~
    }                                                              //~v696I~
#ifdef UTF8SUPPH                                                   //~v62FI~
//  utfcvlocaleinit(0,Pplocale);//pass Scodepage/Sconverter (through callback og getbaseconverter)//~v62FI~//~v62GR~
	if (Popt & UDCWCIO_FORCELOCALE)                                //~v62GI~
    {                                                              //~v633I~
        /*rc2=*/utfcvsetparmlocale(0,parmlocale);   //rc=0 if p1==0               //~v62GR~//~v6b9R~
    }                                                              //~v633I~
#endif                                                             //~v62FI~
    udbcschk_setunprintable(0,Sdbcstbl);                           //~v5n8I~
//#ifdef UTF8SUPPH                                                 //~v62MR~
//    if (Popt & UDCWCIO_FORCELOCALE)                              //~v62MR~
//        if (!rc2)            //setlocale done                    //~v62MR~
//            utfcvsetparmlocale(0,0/*reset locale*/);             //~v62MR~
//#endif                                                           //~v62MR~
//#ifdef LNX                                                       //~v62UR~
//    memcpy(Slocaledbcstbl,Sdbcstbl,128);    //copy unprintable   //~v62UR~
//#endif                                                           //~v62UR~
    UTRACEP("udbcschk_wclocalereset rc=%d, cp=%d,udbcschkflag=%08x\n",rc,cp,Gudbcschk_flag);//~v5n8R~
    UTRACED("udbcstbl",Sdbcstbl,256);                              //~v5n8I~
    UTRACED("readbyte",Sleadbyte,sizeof(Sleadbyte));               //~v62UR~
    return rc;                                                     //~v5n8I~
}//udbcschk_wclocalereset                                          //~v5n8R~
//**************************************************************** //~v5n8I~
// udbcschk_localechk                                              //~v5n8I~
//ret:4: err, 8:utf                                                //~v5n8I~
//**************************************************************** //~v5n8I~
int udbcschk_chklocale(int Popt,UCHAR *Pplocale,ULONG *Ppconverters)//~v5n8I~
{                                                                  //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
    char *pc;                                                      //~v5n8I~
#else                                                              //~v5n8I~
	ULONG cp=0;                                                    //~v5n8I~
    CPINFOEX   cpinfo;                                             //~v5n8I~
#endif                                                             //~v5n8I~
//****************************                                     //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
    if (pc=strchr(Pplocale,'.'),pc)   //codeset info               //~v5n8I~
    {                                                              //~v5n8I~
    	if (ustrstri(pc,"UTF"))        //not encoding specified    //~v5n8I~
        	return 8;                                              //~v5n8I~
    }                                                              //~v5n8I~
   if (!(Popt & UDCWCIO_LOCALICU) //use ICU for localconverter     //~v6f3R~
   || udbcschk_icugetlocalconverter(Popt,Pplocale,*(ULONG**)(ULONG)Ppconverters))//~v6f3R~
   {                                                               //~v6f3I~
	if (ucvext_iconvgetconverter(0,Pplocale,Ppconverters))         //~v5n8I~
    	return 4;                                                  //~v5n8I~
   }                                                               //~v6f3I~
#else                                                              //~v5n8I~
	if (ucvext_getwincodepage(0,Pplocale,&cp))                     //~v5n8R~
    	return 4;                                                  //~v5n8I~
    if (cp==CP_UTF8)	//not supported                            //~v5n8M~
    	return 8;                                                  //~v5n8I~
    *Ppconverters=cp;                                              //~v5n8R~
	if (!udbcschk_getcpinfo(0,cp,&cpinfo))                         //~v5n8R~
    	UstrncpyZ(Pplocale,cpinfo.CodePageName,MAXLOCALESZ);       //~v5n8R~
#endif                                                             //~v5n8I~
    return 0;                                                      //~v5n8I~
}//udbcschk_chklocale                                              //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
//*******************************************************          //~v5n8I~
//* get leadbyte from dbcs 1stbyte tbl                             //~v5n8I~
//* return redbyte ctr                                             //~v5n8I~
//*******************************************************          //~v5n8I~
int udbcschk_getlinuxleadbyte(int Popt,UCHAR *Pdbcs1st,UCHAR *Pleadbyte)//~v5n8I~
{                                                                  //~v5n8I~
	int ii,startsw,leadbytectr=0;                                  //~v5n8R~
//**********************************                               //~v5n8I~
	memset(Pleadbyte,0,MAX_LEADBYTE_PAIR*2);                       //~v5n8I~
    for (startsw=0,ii=0x80;ii<256;ii++)                            //~v5n8I~
    {                                                              //~v5n8I~
        if (Pdbcs1st[ii])	//dbcs 1st byte                        //~v5n8I~
        {                                                          //~v5n8I~
            if (startsw)                                           //~v5n8I~
            {                                                      //~v5n8I~
	            Pleadbyte[leadbytectr*2+1]=(UCHAR)ii;              //~v5n8I~
                continue;                                          //~v5n8I~
            }                                                      //~v5n8I~
            if (leadbytectr>=MAX_LEADBYTE_PAIR)                    //~v5n8R~
                return 0;	//OVERFLOW                             //~v5n8R~
            Pleadbyte[leadbytectr*2]=(UCHAR)ii;                    //~v5n8I~
            Pleadbyte[leadbytectr*2+1]=(UCHAR)ii;                  //~v5n8I~
            startsw=1;                                             //~v5n8I~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
        {                                                          //~v5n8I~
        	if (startsw)                                           //~v5n8I~
            {                                                      //~v5n8I~
            	startsw=0;                                         //~v5n8I~
            	leadbytectr++;                                     //~v5n8I~
            }                                                      //~v5n8I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    if (startsw)      //end by dbcs                                //~v5n8I~
    {                                                              //~v5n8I~
	    Pleadbyte[leadbytectr*2+1]=0xff;                           //~v5n8I~
    	leadbytectr++;                                             //~v5n8I~
    }                                                              //~v5n8I~
    UTRACED("LNX leadbyte",Pleadbyte,MAX_LEADBYTE_PAIR*2);         //~v5n8I~
    return leadbytectr;                                            //~v5n8R~
}//udbcschk_getlinuxleadbyte                                       //~v5n8R~
#endif   //LNX                                                     //~v5n8I~
#endif                                                             //~v5mQI~
//*******************************************************
int udbcschk(UCHAR Pchar)
{
//**********************
	UCHAR *pc;
	int i;
//**********************
    if (Gudbcschk_flag & UDBCSCHK_BEFOREINIT)	//force english before wcinit complete//~v5nvI~
    	return 0;		//not dbcs                                 //~v5nvI~
	if (!Sdbcsenv)
	{
		Sdbcsenv=udosquerydbcsenv();                               //~v024R~

		for (pc=Sdbcsenv;*pc;pc+=2)
		{
			for (i=*pc;i<=*(pc+1);i++)
//  			Sdbcstbl[i]=1;	//DBC                              //~v5n8R~
    			Sdbcstbl[i]=UDBCSCHK_TYPEDBCS;	//dbcs id=1        //~v5n8I~
        	Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                     //~v62PI~
		}
	}
//#ifdef UTF8SUPP                                                  //~v5mQR~
#ifdef WCSUPP                                                      //~v5mQI~
#ifdef LNX                                                         //~v61bI~
  if (UDBCSCHK_ISUTF8VERSION())                                    //~v5n8R~
  {                                                                //~v5n8I~
    if (                                                           //~v61bR~
        (Gudbcschk_flag & UDBCSCHK_EUC)==0                         //~v61bR~
    &&  (Gulibutfmode & GULIBUTFFROMEUC)==0                        //~v61bR~
//  && !(Gudbcschk_flag & UDBCSCHK_NODBCS)                         //~v5n8R~
       )                                                           //~v61bI~
    {                                                              //~v61bI~
        if (                                                       //~v61bR~
            Gudbcschk_flag & UDBCSCHK_DBCSLANG                     //~v61bI~
        ||  (Sdbcschk_hkopt & UDBCSCHKO_FORCELOCALE)	//under UTF8 chk by locale for HEX kbd input//~v61bI~
           )                                                       //~v61bI~
			return udbcschk_locale_topbyte(Pchar);                 //~v61bM~
        else                                                       //~v61bI~
        	return 0;                                              //~v61bM~
    }                                                              //~v61bI~
  }                                                                //~v5n8I~
//  else  //not UTF8 version                                       //~v62UR~
//  {                                                              //~v62UR~
////      if (Sdbcschk_hkopt & UDBCSCHKO_FORCELOCALE) //under UTF8 chk by locale for HEX kbd input//~v62UR~
////      {                                                        //~v62UR~
//            if (Gudbcschk_flag & UDBCSCHK_UTF8CJK)  //UTF8 but base is DBCS//~v62UR~
//            {                                                    //~v62UR~
////              UTRACEP("udbcschk Slocaldbcstbl %02x=%d\n",Pchar,(int)Slocaledbcstbl[Pchar]);   //dbcs id=1//~v62UR~
//                return (int)(Slocaledbcstbl[Pchar]&UDBCSCHK_TYPEDBCS);//~v62UR~
//            }                                                    //~v62UR~
////      }                                                        //~v62UR~
//  }                                                              //~v62UR~
#endif                                                             //~v61bI~
#endif                                                             //~v61bI~
//  UTRACEP("udbcschk Sdbcstbl %02x=%d\n",Pchar,(int)Sdbcstbl[Pchar]);	//dbcs id=1//~v620R~
//  return (int)Sdbcstbl[Pchar];	//dbcs id=1                    //~v5n8R~
    return (int)(Sdbcstbl[Pchar]&UDBCSCHK_TYPEDBCS);	//dbcs id=1//~v5n8I~
}//dbcschk	
//*******************************************************          //~v61fI~
//*additionaly chk EUC code hankaku kaktakana                      //~v61fI~
//*rc=0:SBCS,0x20:DBCS,0x10:HANKANA,0x01:HANKANA(err by option)    //~v61fI~
//*******************************************************          //~v61fI~
int udbcschk_hk(int Popt,UCHAR Pchar)                              //~v61fI~
{                                                                  //~v61fI~
    int rc;                                                        //~v61bI~
//**********************                                           //~v61fI~
#ifdef LNX                                                         //~v61fI~
	if (Pchar==SS2                                                 //~v61fI~
    &&  (                                                          //~v61fR~
            Gudbcschk_flag & UDBCSCHK_EUC                          //~v61fI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//       || Gulibutfmode & GULIBUTFFROMEUC                         //~v5n8R~
    	 || Gudbcschk_flag & UDBCSCHK_UTF8J                        //~v5n8I~
#endif                                                             //~v61fI~
        )                                                          //~v61fI~
       )                                                           //~v61fI~
    {                                                              //~v61fI~
    	if (Popt & UDBCSCHK_EUCHKERR)                              //~v61fR~
        	return UDBCSCHK_RC_HANKANAERR;                         //~v61fI~
        return UDBCSCHK_RC_HANKANAFOUND;                           //~v61fI~
    }                                                              //~v61fI~
#endif                                                             //~v61fI~
#ifdef LNX                                                         //~v5ntI~
//  if (Pchar==SS3 && UDBCSCHK_ISEUCJ())   //prefix of 2nd level KANJI(EUC-JP)//~v62UR~
    if (ISSS3(Pchar))   //prefix of 2nd level KANJI(EUC-JP)        //~v62UR~
    {                                                              //~v5ntI~
    	if (Popt & UDBCSCHK_EUCHKERR)    //if rc set req           //~v5ntI~
        	return UDBCSCHK_RC_SS3;      //0x80                    //~v5ntI~
        return 0;		//SBCS(proceesed at uviom)                 //~v5ntR~
    }                                                              //~v5ntI~
#endif //LNX                                                       //~v5ntI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	#ifdef LNX                                                     //~v61bI~
	Sdbcschk_hkopt=Popt;                                           //~v61bI~
    #endif                                                         //~v61bI~
#endif                                                             //~v61bI~
	rc=udbcschk(Pchar);                                            //~v61bR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	#ifdef LNX                                                     //~v61bI~
	Sdbcschk_hkopt=0;                                              //~v61bI~
    #endif                                                         //~v61bI~
#endif                                                             //~v61bI~
    return rc;                                                     //~v61bI~
}//dbcschk_hk                                                      //~v61fI~
#ifdef UTF8SUPPH                                                   //~v620I~
//**************************************************               //~v620I~
//*get mb char len by top byte to pass length to iconv             //~v620I~
//**************************************************               //~v620I~
//int udbcschk_getmblen(int Popt,UCHAR *Ppc)                       //~v62UR~
int udbcschk_getmblen(int Popt,UCHAR *Ppc,int Plen,int *Pplen)     //~v62UR~
{                                                                  //~v620I~
    int len=1;                                                     //~v620I~
    int rc=UDCGMLRC_CHTYPESBCS;                                    //~v62UR~
    UCHAR ch,cht;                                                  //~v620I~
//*******************                                              //~v620I~
	ch=*Ppc;                                                       //~v620I~
    if (ch>=0x80)                                                  //~v620I~
    {                                                              //~v620I~
//#ifdef LNX                                                       //~v62UR~
//      if (Gudbcschk_flag & UDBCSCHK_UTF8CJK)  //UTF8 but base is DBCS//~v62UR~
//      	cht=Slocaldbcstbl[ch];                                 //~v620~//~v62UR~
//      else                                                       //~v62UR~
//#endif                                                           //~v62UR~
//      	cht=Sdbcstbl[ch];                                      //~v62UR~
//      cht=Gplocaledbcstbl[ch];                                   //~v62UR~
      	cht=Sdbcstbl[ch];                                          //~v62UR~
#ifdef LNX                                                         //~v620I~
//      if (UDBCSCHK_ISEUCJ())    //euc(/+utf8)                    //~v62UR~
        if (Gudbcschk_flag & UDBCSCHK_LANGEUC)  //SS2 and SS3 defined//~v62UR~
        {                                                          //~v620I~
            if (ch==SS2)            //hankaku katakana             //~v620I~
            {                                                      //~v62UR~
                len=2;                                             //~v620I~
                rc=UDCGMLRC_CHTYPESS2;                             //~v62UR~
            }                                                      //~v62UR~
            else                                                   //~v620I~
            if (ch==SS3)                                           //~v620I~
            {                                                      //~v62UR~
                len=3;                                             //~v620I~
                rc=UDCGMLRC_CHTYPESS3;                             //~v62UR~
            }                                                      //~v62UR~
            else                                                   //~v620I~
	        if (cht & UDBCSCHK_TYPEDBCS)                           //~v620I~
            {                                                      //~v62UR~
    	        len=2;                                             //~v620I~
                rc=UDCGMLRC_CHTYPEDBCS;                            //~v62UR~
            }                                                      //~v62UR~
        }                                                          //~v620I~
        else                                                       //~v620I~
#endif                                                             //~v620I~
        if (cht & UDBCSCHK_TYPEDBCS)                               //~v620I~
        {                                                          //~v62UR~
        	if (UDBCSCHK_ISGB4STR(Ppc,Plen))                       //~v62UR~
            {                                                      //~v62UR~
            	len=4;                                             //~v62UR~
                rc=UDCGMLRC_CHTYPEDBCS4;                           //~v62UR~
            }                                                      //~v62UR~
            else                                                   //~v62UR~
        	if (UDBCSCHK_ISGB41STHALF(Ppc,Plen)) //chk by 2 byte   //~v62UR~
            {                                                      //~v62UR~
            	len=4;                                             //~v62UR~
                rc=UDCGMLRC_CHTYPEDBCS4;                           //~v62UR~
            }                                                      //~v62UR~
            else                                                   //~v62UR~
            {                                                      //~v62UR~
            	len=2;                                             //~v62UR~
                rc=UDCGMLRC_CHTYPEDBCS;                            //~v62UR~
            }                                                      //~v62UR~
        }                                                          //~v62UR~
    }                                                              //~v620I~
//  return len;                                                    //~v62UR~
    if (len>Plen)                                                  //~v62UR~
    	rc|=UDCGMLRC_ERRSHORT;                                     //~v62UR~
    if (rc>=UDCGMLRC_ERR)                                          //~v62UR~
        if (Popt & UDCGMLO_LEN1IFERR)                              //~v62UR~
            len=1;                                                 //~v62UR~
    if (Pplen)                                                     //~v62UR~
        *Pplen=len;                                                //~v62UR~
    return rc;                                                     //~v62UR~
}//udbcschk_getmblen                                               //~v620I~
//*******************************************************          //~v627I~
//*dbcschk 2nd byte with line length parm                          //~v627I~
//*under the condition                                             //~v627I~
//*  1st byte 1s DBCS lead byte,2nd byte is accesible              //~v627I~
//*parm :addr of 1st byte                                          //~v627I~
//*rc=0:sbcs,1:dbcs,4:err                                          //~v627I~
//*******************************************************          //~v627I~
int udbcschk_mblen(int Popt,ULONG Pconverter,UCHAR *Ppmbs,int Plen,int *Ppmblen)//~v627I~
{                                                                  //~v627I~
    int rc,mblen;                                                  //~v627R~
//**********************                                           //~v627I~
    UTRACED("udbcschk_mblen",Ppmbs,Plen);                          //~v627I~
//  mblen=udbcschk_getmblen(0,Ppmbs);                              //~v62UR~
    udbcschk_getmblen(0,Ppmbs,Plen,&mblen);                        //~v62UR~
    *Ppmblen=mblen;                                                //~v627I~
    if (mblen==1)                                                  //~v627I~
    	rc=0; //no dbcs;                                           //~v627R~
    else                                                           //~v627I~
    if (mblen>Plen)	//invalid dbcs                                 //~v627I~
    	rc=4;                                                      //~v627R~
    else                                                           //~v627I~
    {                                                              //~v627I~
    	Smb2ndmblen=mblen;	//parm to udbcschk_mb2nd               //~v627R~
		rc=udbcschk_mb2nd(Popt,Pconverter,Ppmbs);                  //~v627R~
    	Smb2ndmblen=0;	//parm to udbcschk_mb2nd                   //~v627R~
    	if (rc)	//valid dbcs                                       //~v627R~
    		rc=1;                                                  //~v627R~
        else                                                       //~v627I~
        	rc=4;                                                  //~v627I~
    }                                                              //~v627I~
    return rc;	//err dbcs                                         //~v627R~
//  UTRACEP("udbcschk_mblen rc=%d,mblen=%d\n",rc,mblen);           //~v627I~//~v6heR~
}//udbcschk_mblen                                                  //~v627I~
#endif //UTF8SUPPH                                                 //~v620I~
//#ifdef UTF8SUPP                                                  //~v5mQR~
#ifdef WCSUPP    //wide char support                               //~v5mQI~
//*******************************************************          //~v5n8I~
//*dbcschk 2nd byte                                                //~v5n8I~
//*under the condition                                             //~v5n8I~
//*  1st byte 1s DBCS lead byte,2nd byte is accesible              //~v5n8R~
//*parm :addr of 1st byte                                          //~v5n8I~
//*rc=1:ok,0:err                                                   //~v5n8R~
//*******************************************************          //~v5n8I~
int udbcschk_mb2nd(int Popt,ULONG Pconverter,UCHAR *Ppmbs)         //~v5n8I~
{                                                                  //~v5n8I~
    int rc;                                                        //~v5n8I~
//  WUCS wkucs[MAX_MBCSLEN];                                       //~v5n8I~//~v6BjR~
    UWUCS wkucs[MAX_MBCSLEN];                                      //~v6BjI~
#ifdef LNX                                                         //~v5n8I~
	char *pci,*pco;                                                //~v5n8I~
//  int ilen,olen;                                                 //~v624R~
    size_t ilen,olen;                                              //~v624I~
	iconv_t cp;                                                    //~v5n8I~
	int opt,chklen;                                                //~v6f3I~
#else                                                              //~v5n8I~
	int opt,chklen;                                                //~v5n8I~
    ULONG cp;                                                      //~v5n8I~
#endif                                                             //~v5n8I~
    int gb4sw=0;                                                   //~v62UR~
//**********************                                           //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
	if (!(cp=(iconv_t)Pconverter))                                 //~v5n8R~
    	cp=Sconverters[HICONV_CPTO];                               //~v5n8I~
    pci=Ppmbs;                                                     //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v627I~
  if (Smb2ndmblen)                                                 //~v627I~
  {                                                                //~v62UR~
//  ilen=Smb2ndmblen;	//parm to udbcschk_mb2nd                   //~v627I~//~v6BkR~
    ilen=(size_t)Smb2ndmblen;	//parm to udbcschk_mb2nd           //~v6BkI~
    if (ilen==4)                                                   //~v62UR~
      gb4sw=1;                                                     //~v62UR~
  }                                                                //~v62UR~
  else                                                             //~v627I~
#endif                                                             //~v627I~
  {                                                                //~v62UR~
    ilen=2;                                                        //~v5n8I~
    if (UDBCSCHK_ISGB42ND(*(pci+1)))                               //~v62UR~
    {                                                              //~v62UR~
      ilen=4;                                                      //~v62UR~
      gb4sw=1;                                                     //~v62UR~
    }                                                              //~v62UR~
  }                                                                //~v62UR~
    pco=(UCHAR*)(ULONG)wkucs;                                      //~v5n8R~
    olen=sizeof(wkucs);                                            //~v5n8R~
  if (UDBCSCHK_IS_LOCALICU())                                      //~v6f3I~
  {                                                                //~v6f3I~
	opt=UCVEXTO_SETSUBCHRC;                                        //~v6f3I~
//  rc=ucvext_icumb2ucs1(opt,(ULONG)cp,pci,ilen,&chklen,(UWUCS*)(ULONG)wkucs);//~v6f3R~//~v6BkR~
    rc=ucvext_icumb2ucs1(opt,(ULONG)cp,pci,(int)ilen,&chklen,(UWUCS*)(ULONG)wkucs);//~v6BkI~
    UTRACED("mb2nd inp",pci,(int)ilen);                                 //~v6f3I~//~v6BkR~
    UTRACEP("mb2nd icumb2ucs1 rc=%d,chklen=&d,outucs=%x\n",rc,chklen,wkucs[0]);//~v6f3I~
  }                                                                //~v6f3I~
  else                                                             //~v6f3I~
  {                                                                //~v6f3I~
//  rc=iconv(cp,ICONV_PCTYPE(&pci),&ilen,&pco,&olen);              //~v5n8R~//~v5nDR~
//  rc=iconv(cp,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v5nDI~//~v6BkR~
    rc=(int)iconv(cp,ICONV_PCTYPE(&pci),ICONV_SZTYPE(&ilen),&pco,ICONV_SZTYPE(&olen));//~v6BkI~
    UTRACEP("mb2nd iconv rc=%d,ilen=%d,olen=%d,outareasz=%d\n",rc,ilen,olen,sizeof(wkucs));//~v62UR~
    UTRACED("mb2nd inp",Ppmbs,2+2*gb4sw);                          //~v62UR~
    UTRACED("mb2nd out ucs",wkucs,sizeof(wkucs));                  //~v62UR~
  }                                                                //~v6f3I~
                                                                   //~v62UR~
#else                                                              //~v5n8I~
	if (!(cp=Pconverter))                                          //~v5n8I~
    	cp=Scodepage;                                              //~v5n8I~
    opt=UCVUCS_MBDBCS;                                             //~v5n8I~
	rc=ucvext_wincp2ucs1(opt,cp,Ppmbs,2,wkucs,&chklen);            //~v5n8I~
#endif                                                             //~v5n8I~
	if (rc)      	//err                                          //~v5n8I~
    	return 0;   //not valid                                    //~v5n8I~
    if (gb4sw)                                                     //~v62UR~
        return 4;                                                  //~v62UR~
    return 1;                                                      //~v5n8R~
}//udbcschk_mb2nd                                                   //~v5n8I~//~v62AR~
//*******************************************************          //~v62UR~
//*locale code char validity chk                                   //~v62UR~
//*len:exact char size                                             //~v62UR~
//*rc=1:ok,0:err                                                   //~v62UR~
//*******************************************************          //~v62UR~
int udbcschk_isvalidmbchar(int Popt,UCHAR *Ppmbs,int Plen)         //~v62UR~
{                                                                  //~v62UR~
    int rc,chklen,opt;                                             //~v62UR~
    ULONG cp;                                                      //~v62UR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6BjR~
//    WUCS   usucs;                                                  //~v65cI~//~v6BjR~
//#else                                                              //~v65cI~//~v6BjR~
//    USHORT usucs;                                                  //~v62UR~//~v6BjR~
//#endif                                                             //~v65cI~//~v6BjR~
//#ifdef LNX                                                         //~v6hhI~//~v6BjR~
	UWUCS  ucs4;                                                   //~v6f3I~
//#endif                                                             //~v6hhI~//~v6BjR~
//**********************                                           //~v62UR~
#ifdef LNX                                                         //~v62UR~
    cp=(ULONG)Sconverters;                                         //~v62UR~
#else                                                              //~v62UR~
    cp=(ULONG)Scodepage;                                           //~v62UR~
#endif    	                                                       //~v62UR~
#ifdef LNX                                                         //~v6hhI~
  if (UDBCSCHK_IS_LOCALICU())	//local is ICU                     //~v6f3I~
  {                                                                //~v6f3I~
	opt=UCVEXTO_SETSUBCHRC;                                        //~v6f3I~
	rc=ucvext_icumb2ucs1(opt,*(ULONG*)cp,Ppmbs,Plen,&chklen,&ucs4);//~v6f3R~
  }                                                                //~v6f3I~
  else                                                             //~v6f3I~
#endif                                                             //~v6hhI~
  {                                                                //~v6f3I~
	opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v62UR~
//  rc=ucvext_iconvlocal2ucs1(opt,cp,Ppmbs,Plen,&chklen,&usucs);//chk also by reverse conv//~v62UR~//~v6BjR~
    rc=ucvext_iconvlocal2ucs1(opt,cp,Ppmbs,Plen,&chklen,&ucs4);//chk also by reverse conv//~v6BjI~
  }                                                                //~v6f3I~
	if (rc)      	//err                                          //~v62UR~
    	return 0;   //not valid                                    //~v62UR~
    if (chklen!=Plen)                                              //~v62UR~
    	return 0;   //translated as not one char                   //~v62UR~
    return 1;                                                      //~v62UR~
}//udbcschk_isvalidmbchar                                          //~v62UR~
//#ifdef LNX                                                       //~v5mQR~
//*******************************************************          //~v61bI~
//*dbcs top byte char chk for locale other than euc on Linux       //~v5mQI~
//*ret :0:sbcs,1:dbcs,2:err                                        //~v61bR~
//*******************************************************          //~v61bI~
int udbcschk_locale_topbyte(UCHAR Pchar)                           //~v61bI~
{                                                                  //~v61bI~
//  wchar_t wc;                                                    //~v61bI~//~v6a0R~
#ifdef W32                                                         //~v6BEM~
//  UWUCS uwucs;                                                   //~v6BEM~//~v6BAR~
#else                                                              //~v6BEI~
    UWCHART wc;                                                    //~v6a0I~
#endif                                                             //~v6BEM~
    mbstate_t mbs;                                                 //~v61bI~
    size_t rc;                                                     //~v61bI~
    UCHAR wk[2];                                                   //~v61bI~
//**********************                                           //~v61bI~
#ifdef LNX                                                         //~v5mQI~
//  if (UTF8MODEENV())                                             //~v61gR~
//  if (UTF8MODEICONV())                                           //~v5n0R~
    if (UDBCSCHK_IS_LOCALICU())                                 //~v6f0R~//~v6f3I~
    {                                                              //~v6f3I~
	    return (Sdbcstbl[Pchar] & UDBCSCHK_TYPEDBCS)!=0;           //~v6f3I~
    }                                                              //~v6f3I~
#ifdef UTF8SUPPH                                                   //~v620I~
    if (UTF8MODEICONV())                                           //~v620I~
#else                                                              //~v620I~
    if (UTF8MODEICONVLOCALEINIT())                                 //~v5n0I~
#endif                                                             //~v620I~
//  	return utfcviconvdbcschk_topbyte(0,Pchar);	//using iconv  //~v61hR~
    	return utfcviconvdbcschk_topbyte(0,Pchar,0/*out utfstr*/,0/*out utflen*/);	//using iconv//~v61hI~
#endif                                                             //~v5mQI~
	if (UTF8ISASCII(Pchar))                                        //~v61bR~
    	return 0;                                                  //~v61bI~
	memset(&mbs,0,sizeof(mbs));                                    //~v61bI~
    wk[0]=Pchar;                                                   //~v61bI~
    wk[1]=0;                                                       //~v61bI~
#ifdef W32                                                         //~v6BEI~
	rc=(size_t)(udbcschk_isleadbyte(Pchar) ? -2 : 0); //using Scodepage           //~v6BEI~//~v6BAR~
#else                                                              //~v6BEI~
    rc=mbrtowc(&wc,wk,1,&mbs);                                     //~v61bR~
#endif                                                             //~v6BEM~//~v6BAM~
UTRACEP("udbcschk_local_topbyte mbrtowc %02x rc=%d\n",Pchar,rc);   //~v5n8I~
    if (rc==(size_t)-2)	//inmatuared dbcs                          //~v61bI~
    	return 1;		//dbcs byte1                               //~v61bI~
//  if (rc==(size_t)-1)	//invalid                                  //~v5mQR~
//  	return 2;		//to be set err on dbcs tbl                //~v5mQR~
    return 0;                                                      //~v61bI~
}//udbcschk_locale_topbyte                                         //~v61bI~
#ifdef AAA                                                         //~v6BGI~
//*******************************************************          //~v61bI~
//*chk locale has dbcs?                                            //~v61bI~
//*ret :0:NO,1:YES                                                 //~v61bI~
//*******************************************************          //~v61bI~
int udbcschk_localeisdbcs(void)                                    //~v61bI~
{                                                                  //~v61bI~
    int ii;                                                        //~v61bI~
//**********************                                           //~v61bI~
	for (ii=0x80;ii<=0xff;ii++)                                    //~v61bI~
		if (udbcschk_locale_topbyte((UCHAR)ii))                    //~v61bI~
        {                                                          //~v61bI~
        	Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                     //~v61bI~
        	return 1;                                              //~v61bI~
        }                                                          //~v61bI~
    Gudbcschk_flag&=~UDBCSCHK_DBCSLANG;                            //~v61bI~
    return 0;                                                      //~v61bI~
}//udbcschk_localeisdbcs                                           //~v61bI~
#endif                                                             //~v6BGI~
//*******************************************************          //~v5mQI~
//*setup dbcs 1st byte flag table for locale                       //~v5mQR~
//*ret :0:NODBCS,1:DBCS                                            //~v5mQR~
//*******************************************************          //~v5mQI~
int udbcschk_getdbcs1st(int Popt,char *Ppflags)                    //~v5mQI~
{                                                                  //~v5mQI~
    int ii,dbcssw=0;                                               //~v5mQI~
    char *pc;                                                      //~v5mQI~
//**********************                                           //~v5mQI~
	memset(Ppflags,0,0x80);                                        //~v5mQI~
	for (ii=0x80,pc=Ppflags+0x80;ii<=0xff;ii++,pc++)               //~v5mQI~
    {                                                              //~v5mQI~
		if (udbcschk_locale_topbyte((UCHAR)ii))                    //~v5mQI~
        {                                                          //~v5mQI~
        	dbcssw=1;                                              //~v5mQI~
//      	*pc=0x01;                                              //~v5n8R~
        	*pc=UDBCSCHK_TYPEDBCS;	//dbcs id=1                    //~v5n8I~
        }                                                          //~v5mQI~
        else                                                       //~v5mQI~
        	*pc=0x00;                                              //~v5mQI~
    }                                                              //~v5mQI~
    if (dbcssw)                                                    //~v5mQI~
        Gudbcschk_flag|=UDBCSCHK_DBCSLANG;                         //~v5mQI~
    else                                                           //~v5mQI~
    	Gudbcschk_flag&=~UDBCSCHK_DBCSLANG;                        //~v5mQI~
    UTRACED("dbcstbl",Ppflags,256);                                //~v6BAR~
    return dbcssw;                                                 //~v5mQR~
}//udbcschk_getdbcs1st                                             //~v5mQI~
//*******************************************************          //~v5mQI~
//*setup dbcs 1st byte flag table                                  //~v5mQI~
//*ret :0:NO,1:YES                                                 //~v5mQI~
//*******************************************************          //~v5mQI~
int udbcschk_ismbdbcs1st(int Popt,UCHAR Pch)                       //~v5mQI~
{                                                                  //~v5mQI~
static int Ssw1st=0;                                               //~v5mQI~
static char Smbdbcs1st[256];                                       //~v5mQI~
//**********************                                           //~v5mQI~
	if (!Ssw1st)                                                   //~v5mQI~
    {                                                              //~v5mQI~
        Ssw1st=1;                                                  //~v5mQI~
		udbcschk_getdbcs1st(Popt,Smbdbcs1st);                      //~v5mQI~
UTRACED("udbcschk dbcs1st map",Smbdbcs1st,256);                    //~v5mQI~
    }                                                              //~v5mQI~
UTRACEP("udbcschk_ismbdbcs1st ch=%02x,dbcssw=%d\n",Pch,Smbdbcs1st[Pch]);//~v5mQI~
    return Smbdbcs1st[Pch];                                        //~v5mQI~
}//udbcschk_ismbdbcs1st                                            //~v5mQI~
//*******************************************************          //~v61bI~
//*dbcs chk for locale other tab euc on Linux(1 char only)         //~v61bI~
//*ret :0:sbcs,1:dbcs                                              //~v61bI~
//*******************************************************          //~v61bI~
//int udbcschk_locale1(UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs)//~v61bR~//~v66nR~
int udbcschk_locale1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs)//~v66nI~
{                                                                  //~v61bI~
//  wchar_t wc;                                                    //~v61bI~//~v6a0R~
#ifdef LNX                                                         //~v6BAI~
    UWCHART wc=0;                                                    //~v6a0I~//~v6h6R~
#else                                                              //~v6BAI~
    UWUCS   wc=0;                                                  //~v6BAI~
#endif                                                             //~v6BAI~
#ifdef LNX                                                         //~v6BAI~
    mbstate_t mbs;                                                 //~v61bI~
#endif                                                             //~v6BAI~
    size_t cvrc=0;                                                   //~v61bI~//~v6h6R~
    ULONG ucs;                                                     //~v61bI~
//#ifdef LNX                                                         //~v6f3I~//~v6BAR~
    UWUCS ucs4;                                                    //~v6f3I~
//#endif                                                             //~v6f3I~//~v6BAR~
    int rc=UDBCSCHK_SBCS,readlen=1,width;                          //~v61bR~
#ifdef LNX                                                         //~v6BAI~
    int ii;                                                        //~v62UR~
#endif                                                             //~v6BAI~
//**********************                                           //~v61bI~
	ucs=*Pstr;                                                     //~v61bI~
	if (!UTF8ISASCII(*Pstr))                                       //~v61bR~
    {                                                              //~v61bI~
#ifdef LNX                                                         //~v5mQI~
    	if (UDBCSCHK_IS_LOCALICU())                                //~v6f3I~
        {                                                          //~v6f0R~//~v6f3I~
//			cvrc=(size_t)ucvext_locale1ICU(0,*(ULONG*)(ULONG)Sconverters,Pstr,Plen,&readlen,&ucs4);//~v6f0R~//~v6hcR~
  			cvrc=(size_t)ucvext_locale1ICU(0,(ULONG)Sconverters[HICONV_CPTO],Pstr,Plen,&readlen,&ucs4);//~v6hcR~
            wc=ucs4;                                                //~v6f0R~//~v6f3I~
            if (!cvrc)                                             //~v6f0R~//~v6f3I~
            {                                                      //~v6f0R~//~v6f3I~
UTRACED("UDBCSCHK_LOCALE1 data",Pstr,readlen);                     //~v6f0R~//~v6f3I~
//            	cvrc=readlen;	//1 or 2                           //~v6f0R~//~v6f3I~//~v6BkR~
              	cvrc=(size_t)readlen;	//1 or 2                   //~v6BkI~
            }                                                      //~v6f0R~//~v6f3I~
        }                                                          //~v6f0R~//~v6f3I~
        else                                                       //~v6f0R~//~v6f3I~
//  	if (UTF8MODEENV())                                         //~v61gR~
//  	if (UTF8MODEICONV())                                       //~v5n0R~
#ifdef UTF8SUPPH                                                   //~v620I~
    	if (UTF8MODEICONV())                                       //~v620I~
#else                                                              //~v620I~
    	if (UTF8MODEICONVLOCALEINIT())                             //~v5n0I~
#endif                                                             //~v620I~
        {                                                          //~v61hI~
//  		cvrc=(size_t)utfcviconvdbcschk1(0,Pstr,Plen,&readlen); //~v61hR~
			cvrc=(size_t)utfcviconvdbcschk1(0,Pstr,Plen,&readlen,&ucs);//~v62UR~
UTRACEP("UDBCSCHK_LOCALE1 utf MBRTOWC RC=%d,err=%d,mbs=%02x,len=%d,wc=%04x,readlen=%d\n",cvrc,errno,*Pstr,Plen,ucs,readlen);//~v62UR~
//          wc=ucs;                                                //~v61hI~//~v6BkR~
            wc=(UWCHART)ucs;                                       //~v6BkR~
            if (!cvrc)                                             //~v61hI~
            {                                                      //~v62UR~
UTRACED("UDBCSCHK_LOCALE1 data",Pstr,readlen);                     //~v62UR~
//          	cvrc=readlen;	//1 or 2                           //~v61hI~//~v6BkR~
            	cvrc=(size_t)readlen;	//1 or 2                   //~v6BkI~
            }                                                      //~v62UR~
        }                                                          //~v61hI~
        else                                                       //~v61bI~
#endif                                                             //~v5mQI~
        {                                                          //~v61bI~
#ifdef W32                                                         //~v6BAI~
		  cvrc=(size_t)umbtowcW(Popt,Pstr,Plen,&ucs4);             //~v6BAR~
          wc=ucs4;                                                 //~v6BAI~
          readlen=cvrc;                                            //~v6BAI~
#else                                                              //~v6BAI~
          for (ii=1;ii<=min(Plen,MAX_MBCSLENLC);ii++)    //1-->4 byte locale code chk//~v62UR~
          {                                                        //~v62UR~
        	memset(&mbs,0,sizeof(mbs));                            //~v61bR~
//      	cvrc=mbrtowc(&wc,Pstr,Plen,&mbs);                      //~v62UR~
//      	cvrc=mbrtowc(&wc,Pstr,ii,&mbs);                        //~v62UR~//~v6BkR~
        	cvrc=(size_t)mbrtowc(&wc,Pstr,(size_t)ii,&mbs);        //~v6BkR~
UTRACEP("UDBCSCHK_LOCALE1 mbr MBRTOWC RC=%d,err=%d,mbs=%02x,len=%d,wc=%04x\n",cvrc,errno,*Pstr,ii,wc);//~v62UR~
UTRACED("UDBCSCHK_LOCALE1 data",Pstr,ii);                          //~v62UR~
UTRACED("UDBCSCHK_LOCALE1 mbs ",&mbs,sizeof(mbs));                 //~v62UR~
        	if (cvrc!=(size_t)-2)   //inmatuared dbcs(setlocale required for this RC)//~v62UR~
                break;                                             //~v62UR~
          }                                                        //~v62UR~
          readlen=ii;   //set mblen read                           //~v66uR~
#endif                                                             //~v6BAI~
        }                                                          //~v61bI~
        if (cvrc==(size_t)-2)   //inmatuared dbcs                  //~v61bI~
            rc=UDBCSCHK_HKDBCSERR;  // 'e'                         //~v61bI~
        else                                                       //~v61bI~
        if (cvrc==(size_t)-1)       //invalid dbcs                 //~v61bI~
            rc=UDBCSCHK_HKDBCSERR;  // 'e'                         //~v61bI~
        else                                                       //~v61bI~
        {                                                          //~v61bI~
          if (Popt & UDCL1O_NOCHKWIDTH)                            //~v66nI~
//        	ucs=wc;                                                //~v66nR~//~v6BkR~
          	ucs=(ULONG)wc;                                         //~v6BkI~
          else                                                     //~v66nI~
          {                                                        //~v66nI~
//          width=utfwcwidth(wc);   //!!! wcwidth requires "setlocal" call before//~v62UR~
//          width=utfwcwidth(0,wc,0/*wdbcs flag*/);   //!!! wcwidth requires "setlocal" call before//~v62UR~//~v6BkR~
            width=utfwcwidth(0,(ULONG)wc,0/*wdbcs flag*/);   //!!! wcwidth requires "setlocal" call before//~v6BkI~
UTRACEP("DBCSCHK_LOCALE1 width=%d\n",width);                       //~v62UR~
//          ucs=wc;                                                //~v61bI~//~v6BkR~
            ucs=(ULONG)wc;                                         //~v6BkI~
            switch (width)                                         //~v61bI~
            {                                                      //~v61bI~
            case 0:                                                //~v61bI~
                rc=UDBCSCHK_NONSPACE;    //'0'                     //~v61bI~
            	break;                                             //~v61bI~
            case 1:		//sbcs                                     //~v61bI~
	            readlen=(int)cvrc;                                 //~v61bI~
                if (readlen>1)	//multibyte but display width=1    //~v62UR~
    	            rc=UDBCSCHK_DBCS1ST;    //'1'                  //~v62UR~
            	break;                                             //~v61bI~
            case 2:     //dbcs                                     //~v61bI~
	            readlen=(int)cvrc;                                 //~v61bI~
              if (readlen>1)	//multibyte but display width=1    //~v62UR~
                rc=UDBCSCHK_DBCS1ST;    //'1'                      //~v61bI~
            	break;                                             //~v61bI~
            default:    //err                                      //~v61bI~
	            rc=UDBCSCHK_HKDBCSERR;  // 'e'                     //~v61bI~
            }                                                      //~v61bI~
          }//!nochk width                                          //~v66nI~
        }                                                          //~v61bI~
    }                                                              //~v61bI~
    if (Ppreadlen)                                                 //~v61bI~
    	*Ppreadlen=readlen;                                        //~v61bI~
    if (Ppucs)                                                     //~v61bI~
    	*Ppucs=ucs;                                                //~v61bI~
    UTRACEP("udbcschk_locale1 rc=%x,opt=%x,ucs=%x,readlen=%d,mb1=%x\n",rc,Popt,ucs,readlen,*Pstr);//~v66nI~//~v66DR~
    return rc;		//dbcs byte1                                   //~v61bI~
}//udbcschk_locale1                                                //~v61bI~
//*******************************************************          //~v5mQI~
//*mb to wc                                                        //~v5mQI~
//*ret :0:sbcs,1:dbcs, 4:err                                       //~v5mQI~
//*     3:reverse chk err                                          //~v66DI~
//*******************************************************          //~v5mQI~
#ifdef UTF8UCS4                                                    //~v65cI~
int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,WUCS *Ppucs)//~v65cR~
#else                                                              //~v65cI~
//int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,USHORT *Ppucs)//~v5mQI~//~v6BjR~
int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs)//~v6BjI~
#endif                                                             //~v65cI~
{                                                                  //~v5mQI~
	int rc=0,readlen;                                              //~v5mQI~
    ULONG  ulucs;                                                  //~v5mQI~
    int opt=0;                                                     //~v66nI~
    UCHAR wkmbs[MAX_MBCSLEN];                                      //~v66DI~
    int mblen,rc2;                                                 //~v66DI~
//**********************                                           //~v5mQI~
//  rc=udbcschk_locale1(Pstr,Plen,&readlen,&ulucs);                //~v5mQI~//~v66nR~
	if (Popt & UDCM2U1O_A2E)                                       //~v66nI~
    	opt|=UDCL1O_NOCHKWIDTH;                                    //~v66nI~
    rc=udbcschk_locale1(opt,Pstr,Plen,&readlen,&ulucs);            //~v66nI~
    switch(rc)                                                     //~v5mQI~
    {                                                              //~v5mQI~
    case UDBCSCHK_SBCS:                                            //~v5mQI~
    	rc=0;                                                      //~v5mQI~
        break;                                                     //~v5mQI~
    case UDBCSCHK_DBCS1ST:                                         //~v5mQI~
        rc=1;                                                      //~v5mQI~
        break;                                                     //~v5mQI~
    case UDBCSCHK_NONSPACE:    //'0'                               //~v70gI~
//*     keep readlen                                               //~v70gI~
    	rc=0;                  //no err                            //~v70gI~
        break;                                                     //~v70gI~
    default:                                                       //~v5mQI~
    	readlen=1;                                                 //~v5mQI~
        rc=4;                                                      //~v5mQI~
    }                                                              //~v5mQI~
    if (Ppreadlen)                                                 //~v5mQI~
    	*Ppreadlen=readlen;                                        //~v5mQI~
    if (Ppucs)                                                     //~v5mQI~
//  	*Ppucs=(USHORT)ulucs;                                      //~v5mQI~//~v692R~
//  	*Ppucs=(WUCS)ulucs;                                        //~v692I~//~v6BAR~
    	*Ppucs=(UWUCS)ulucs;                                       //~v6BAI~
    if (rc<=1 && (Popt & UDCM2U1O_BACKCHK))                        //~v66DR~
    {                                                              //~v66DI~
//		rc2=udbcschk_ucs2mb1(0,(USHORT)ulucs,wkmbs,&mblen);        //~v66DI~//~v692R~
//  	rc2=udbcschk_ucs2mb1(0,(WUCS)ulucs,wkmbs,&mblen);          //~v692I~//~v6BjR~
    	rc2=udbcschk_ucs2mb1(0,(UWUCS)ulucs,wkmbs,&mblen);         //~v6BjI~
        if (rc2 || mblen!=readlen || memcmp(wkmbs,Pstr,(UINT)mblen))//~v66DI~
        	rc=3;                                                  //~v66DI~
    }                                                              //~v66DI~
UTRACEP("udbcschk_mb2ucs rc=%d,%02x%02x,ucs=%04x\n",rc,*Pstr,(Plen>1?*(Pstr+1):0),ulucs);//~v5n1R~
    return rc;                                                     //~v5mQI~
}//udbcschk_mb2ucs1                                                //~v5mQI~
//*******************************************************          //~v5mQI~
//*1 wc to mb                                                      //~v5mQI~
//*ret :0:sbcs,1:dbcs                                              //~v5mQI~
//*     3:reverse chk err                                          //~v66DI~
//*******************************************************          //~v5mQI~
//int udbcschk_ucs2mb1(int Popt,USHORT Pucs,UCHAR *Pmbs,int *Ppoutlen)//~v5mQI~//~v692R~
//int udbcschk_ucs2mb1(int Popt,WUCS Pucs,UCHAR *Pmbs,int *Ppoutlen) //~v692I~//~v6BjR~
int udbcschk_ucs2mb1(int Popt,UWUCS/*ucs4*/ Pucs,UCHAR *Pmbs,int *Ppoutlen)//~v6BjI~
{                                                                  //~v5mQI~
	int rc,len;                                                    //~v5mQI~
    int opt,rc2,readlen;                                           //~v66DI~
//  wchar_t wc;                                                    //~v5mQI~//~v6a0R~
//  UWCHART wc;                                                    //~v6a0I~//~v6BjR~
#ifdef W32                                                         //~v6BAI~
#else                                                              //~v6BAI~
    UWCHART wc[3];                                                 //~v6BjI~
#endif                                                             //~v6BAI~
//  mbstate_t mbs;                                                 //~v5mQI~//~v6BjR~
    char wkmbs[MAX_MBCSLENLC+1];                                   //~v6BjI~
//  WUCS wucs;                                                     //~v66DI~//~v6BjR~
    UWUCS wucs;                                                    //~v6BjI~
//#ifdef W32                                                         //~v6BwI~//~v6BAR~
//    int utf16ctr;                                                  //~v6BjI~//~v6BAR~
//#endif                                                             //~v6BwI~//~v6BAR~
//**********************                                           //~v5mQI~
//  wc=Pucs;                                                       //~v5mQI~//~v6BjR~
#ifdef W32                                                         //~v6BwI~
//  UCS4_TO_UTF16(Pucs,wc,&utf16ctr);                              //~v6BjR~//~v6BAR~
//  wc[utf16ctr]=0;	//wc terminater                                //~v6BjI~//~v6BAR~
    wucs=Pucs;                                                     //~v6BAI~
#else                                                              //~v6BwI~
    wc[0]=Pucs;                                                    //~v6BwI~
    wc[1]=0;                                                       //~v6BwI~
#endif                                                             //~v6BwI~
//  memset(&mbs,0,sizeof(mbs));                                    //~v5mQI~//~v6BjR~
    *Pmbs=0;                                                       //~v5mQI~
//  len=(int)wcrtomb(Pmbs,wc,&mbs);   //                           //~v5mQI~//~v6BjR~
#ifdef W32                                                         //~v6BAI~
    len=uwctombW(0,wucs,wkmbs);   //                               //~v6BAR~
UTRACEP("udbcschk_ucs2mb1 uwctombW Pucs=%04x,mblen=%d mbs=%02x,%02x,%02x,%02x\n",Pucs,len,*wkmbs,len>1?*(wkmbs+1):0,len>2?*(wkmbs+2):0,len>3?*(wkmbs+3):0);//~v6BAR~//~v70gR~
#else                                                              //~v6BAI~
    len=(int)wcstombs(wkmbs,wc,sizeof(wkmbs));   //                //~v6BjI~
UTRACEP("udbcschk_ucs2mb1 wcrtomb Pucs=%04x,wc[0]=%04x,len=%d mbs=%02x,%02x\n",Pucs,wc[0],len,*Pmbs,*(Pmbs+1));//~v5mQR~//~v66DR~//~v6BwR~//~v70gR~
#endif                                                             //~v6BAM~
    if (len>0)                                                     //~v5mQI~
    {                                                              //~v6BjI~
    	memcpy(Pmbs,wkmbs,(size_t)len);                            //~v6BjI~
    	rc=0;                                                      //~v5mQI~
    }                                                              //~v6BjI~
    else                                                           //~v5mQI~
    	rc=4;                                                      //~v5mQI~
    if (Ppoutlen)                                                  //~v5mQI~
    	*Ppoutlen=len;                                             //~v5mQI~
    if (!rc && (Popt & UDCU2M1O_BACKCHK))                          //~v66DI~
    {                                                              //~v66DI~
		opt=UDCM2U1O_A2E;                                          //~v66DI~
		rc2=udbcschk_mb2ucs1(opt,Pmbs,len,&readlen,&wucs);         //~v66DI~
//      if (rc2 || len!=readlen || wucs!=(WUCS)Pucs)               //~v66DI~//~v6BjR~
        if (rc2 || len!=readlen || wucs!=Pucs)                     //~v6BjI~
        	rc=3;                                                  //~v66DI~
    }                                                              //~v66DI~
//  UTRACEP("udbcschk_ucs2mb1 rc=%d,ucs=%x,wucs=%x,mbs=%x\n",rc,Pucs,wucs,*Pmbs);//~v66DR~//~v6h6R~
    return rc;                                                     //~v5mQI~
}//udbcschk_ucs2mb1                                                //~v5mQI~
//#endif //LNX                                                     //~v5mQR~
#endif                                                             //~v5i9I~
//*******************************************************          //~v39CI~
//*force english mode                                              //~v39CI~
//*parm:none                                                       //~v39CI~
//*******************************************************          //~v39CI~
void udbcschk_forceenglish(void)                                   //~v39CI~
{                                                                  //~v39CI~
	char *pc,*pce;                                                 //~v5njI~
//****************                                                 //~v5njI~
//  memset(Sdbcstbl,0,sizeof(Sdbcstbl));                           //~v5n8R~
//  memset(Sdbcstbl+128,0,128);                                    //~v5n8I~//~v5njR~
	for (pc=Sdbcstbl+128,pce=pc+128;pc<pce;pc++)                   //~v5njR~
    	*pc=(char)(*pc & ~UDBCSCHK_TYPEDBCS);                      //~v5nvR~
	return;                                                        //~v39CI~
}//udbcschk_forceenglish(void)                                     //~v39CI~
//*******************************************************          //~v150I~
//*chk dbcsenvtable and codepage *                                 //~v150I~
//*parm:none                                                       //~v150I~
//*rc  :0:no dbcstbl or codepage is not 932 nor 942                //~v166R~
//*    :1:dbctbl and cp eq 932 or 942                              //~v166R~
//*******************************************************          //~v150I~
int udbcschkcp(void)                                               //~v150I~
{                                                                  //~v150I~
//#ifndef WXE                                                      //~v570R~
    int cp;                                                        //~v166I~
//#endif                                                           //~v570R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//  static int Scodepage=0;                                        //~v5n8R~
//#endif                                                           //~v5n8R~
//**********************                                           //~v150I~
#ifdef WCSUPP                                                      //~v5n8I~
	if (!Swcinitsw)                                                //~v5n8I~
//		return udbcschk_wcinit(0,0);                               //~v5n8R~//~v638R~
  		return udbcschk_wcinit(UDCWCIO_INTERNAL,0);                //~v638I~
#endif                                                             //~v5n8I~
	if (!udbcsenv())                                               //~v150I~
    {                                                              //~v62zI~
#ifdef W32                                                         //~v62zI~
    	if (!Scodepage)                                            //~v62zI~
    		Scodepage=Scodepage2;	//udosquerydbcsenv may set     //~v62zI~
    UTRACEP("udbcschkcp after udbcsenv Scodepage=%d\n",Scodepage); //~v62zI~
#endif                                                             //~v62zI~
      if (!(Gudbcschk_flag & UDBCSCHK_UTF8))	//not utf8(utf8 return null dbcstbl but dbcs chk required)//~v5i7I~
    	return 0;                                                  //~v150I~
    }                                                              //~v62zI~
//  if (ugetcp()!=932)                                             //~v166R~
//#ifndef WXE                                                      //~v570R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
  if (!(cp=Scodepage))                                             //~v60eI~
  {                                                                //~v60eI~
//#endif                                                           //~v5n8R~
    cp=ugetcp();                                                   //~v166I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
    Scodepage=cp;                                                  //~v60eI~
    UTRACEP("udbcschkcp Scodepage=%d\n",Scodepage);                //~v62yI~
  }                                                                //~v60eI~
//#endif                                                           //~v5n8R~
  if (cp!=943) //943:OS/2 superset of CP932 & SJIS                 //~v5n8I~
    if (cp!=932 && cp !=942)                                       //~v166I~
    	return 0;		    //english mode under japnaese env      //~v150I~
//#endif                                                           //~v570R~
    if (cp==932)                                                   //~v57pI~
    {                                                              //~v5n8I~
    	if (!(Gudbcschk_flag & UDBCSCHK_EUC))	//not euc          //~v57pI~
    	if (!(Gudbcschk_flag & UDBCSCHK_UTF8))	//not utf8         //~v5i7R~
    		Gudbcschk_flag|=UDBCSCHK_MS932;	//ms932 chk            //~v57pI~
    }                                                              //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
  #ifdef W32	                                                   //~v5n8I~
  #ifndef WXE                                                      //~v5n8I~
    if (Gudbcschk_flag & UDBCSCHK_CONSCP)//ConsoleCP!=SYSTEM Default//~v5n8R~
        return 0;   //not Japanese special, but one of CJK         //~v5n8M~
  #endif                                                           //~v5n8I~
  #endif                                                           //~v5n8I~
    if (Gudbcschk_flag & UDBCSCHK_WCDBCS)//932 by FORCELOCALE      //~v5n8I~
        return 0;   //not Japanese special, but one of CJK         //~v5n8I~
#endif                                                             //~v5n8I~
    if (!(Gudbcschk_flag & UDBCSCHK_UTF8))	//not utf8             //~v5n8I~
        Gudbcschk_flag|=UDBCSCHK_DBCSJ; //Japanese special(SJIS/EUC)//~v5n8I~
	return 1;           	//full japanese                        //~v150I~
}//udbcschkcp                                                      //~v150I~
//#ifndef WXE                                                      //~v570R~
//*******************************************************          //~v150I~
//*get codepage                                                    //~v150I~
//*parm:none                                                       //~v150I~
//*rc  :code page                                                  //~v150I~
//*******************************************************          //~v150I~
int ugetcp(void)                                                   //~v150I~
{                                                                  //~v150I~
#ifdef UNX                                                         //~v326R~
    UCHAR *plang;                                                  //~v326I~
#else        //!LINUX                                              //~v326I~
#ifdef DOS  					//v7.0a                            //~v150I~
	union REGS	 reg;                                              //~v150I~
#else							//v7.0a                            //~v150I~
	#ifdef W32                                                     //~v150I~
//    #ifdef WXE                                                   //~v5n8R~
        int rc;                                                    //~v570I~
      	char cpgetwk[16];                                          //~v570I~
//    #endif                                                       //~v5n8R~
        int cpsys;                                                 //~v5n8R~
      #ifndef WXE                                                  //~v5n8I~
        int cpcon;                                                 //~v5n8M~
      #endif                                                       //~v5n8I~
	#else                                                          //~v150I~
        ULONG cplist[8];                                           //~v150I~
        ULONG cpsize;                                              //~v150I~
		APIRET apiret;                                             //~v150I~
	#endif							//v7.0a                        //~v150I~
#endif							//v7.0a                            //~v150I~
#endif		//!UNX                                                 //~v326R~
//**********************                                           //~v150I~
#ifdef UNX                                                         //~v326R~
  #ifdef LNX                                                       //~v5ifI~
// #ifdef UTF8SUPP                                                 //~v5n8R~
#ifdef UTF8SUPPH	                                               //~v627I~
	if (!(plang=udbcschk_setlocale(0,LC_ALL,"")))                  //~v627R~
#else                                                              //~v627I~
	if (!(plang=setlocale(LC_ALL,"")))                             //~v5ifI~
#endif                                                             //~v627I~
// #else                                                           //~v5n8R~
//  if (!(plang=getenv("LANG")))                                   //~v5n8R~
// #endif                                                          //~v5n8R~
  #else                                                            //~v5ifI~
	if (!(plang=getenv("LANG")))                                   //~v326I~
  #endif                                                           //~v5ifI~
    	return 437;                                                //~v326I~
//  if (!ustrstri(plang,"JP"))                                     //~v40oR~
    if (!strstr(plang,"Ja_JP")) //!SJIS                            //~v39kR~
  {//!sjis                                                         //~v582I~
    if (strstr(plang,"ja_JP")) //!EUC                              //~v39kR~
    {                                                              //~v39kI~
//#ifdef AAA //already set at dosquery<-udbcsenv<-udbcschkcp       //~v5n8R~
//      if (strstr(plang,"UTF-8")) //utf8                          //~v5n8R~
//      {                                                          //~v5n8R~
//        Gudbcschk_flag|=UDBCSCHK_UTF8;                           //~v5n8R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//        Gudbcschk_flag|=UDBCSCHK_UTF8J;                          //~v5n8R~
//#endif                                                           //~v5n8R~
//      }                                                          //~v5n8R~
//      else                                                       //~v5n8R~
//        Gudbcschk_flag|=UDBCSCHK_EUC;                            //~v5n8R~
//#endif                                                           //~v5n8R~
#ifdef LNX                                                         //~v39kI~
  #ifndef XXE                                                      //~v5g7I~
//  	return 437;                                                //~v39xR~
      if (udbcschktty())    //tty(not pty) /dev/tty_               //~v39PI~
    	return 437;                                                //~v39PI~
      else                  //pty          /dev/ttyp               //~v39PI~
   #endif   //!XXE                                                 //~v5n8I~
	  if (Gudbcschk_flag & UDBCSCHK_UTF8)                          //~v5n8I~
    	return 437;		//later chk defaultlang                    //~v5n8I~
      else                                                         //~v5n8I~
    	return 932; 				//japanese                     //~v39xI~
// #endif   //!XXE                                                 //~v5n8R~
#endif                                                             //~v39kI~
    }                                                              //~v39kI~
    else							//EUC                          //~v39kI~
    {                                                              //~v5i9I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef LNX                                                         //~v5i9I~
  #ifndef XXE                                                      //~v5i9I~
      if (udbcschktty())    //tty(not pty) /dev/tty_               //~v5i9I~
    	return 437;           //ignore utf when console mode       //~v5i9I~
   #endif   //!XXE                                                 //~v5i9I~
#endif                                                             //~v5i9I~
//#ifdef AAA //already set at dosquery<-udbcsenv<-udbcschkcp       //~v5n8R~
//        if (strstr(plang,"UTF-8")) //utf8                        //~v5n8R~
//            Gudbcschk_flag|=(UDBCSCHK_UTF8|UDBCSCHK_UTF8E); //not japanese but utf(multibyte char)//~v5n8R~
//#endif                                                           //~v5n8R~
//#endif                                                           //~v5n8R~
    	return 437;                                                //~v326I~
    }                                                              //~v5i9I~
  }//!sjis                                                         //~v582I~
    return 932;                                                    //~v326I~
#else        //!LINUX                                              //~v326I~
#ifdef DOS  					//v7.0a                            //~v150I~
    memset(&reg,0,sizeof(reg));                                    //~v150I~
    reg.x.ax=0x6601;				  //get DBCS vector            //~v150I~
	#ifdef DPMI					//DPMI version                     //~v150I~
    	udpmiint86(0x21,&reg,&reg); //DS:SI point dbcs tbl         //~v150I~
  	#else                       //not DPMI                         //~v150I~
    	intdos(&reg,&reg);                                         //~v150I~
    #endif                                                         //~v150I~
    return reg.x.bx;        //global code page(DX:system code page)//~v150I~
#else                                                              //~v150I~
	#ifdef W32                                                     //~v150I~
//    #ifdef WXE                                                   //~v5n8R~
	    rc=GetLocaleInfo(LOCALE_SYSTEM_DEFAULT,                    //~v570I~
						LOCALE_NOUSEROVERRIDE|                     //~v62yR~
						LOCALE_IDEFAULTANSICODEPAGE,//   0x00001004   // default ansi code page//~v62yI~
		     			cpgetwk,sizeof(cpgetwk));                  //~v570I~
UTRACEP("GetLocaleInfo rc=%d,err=%d,ret=%s\n",rc,GetLastError(),cpgetwk);//~v62yR~
        if (!rc)	//number of byte outout to buff                //~v570I~
        	return 0;                                              //~v570I~
//      return atoi(cpgetwk);                                      //~v5n8R~
//    #else                                                        //~v5n8R~
//  	return (int)GetConsoleCP();                                //~v5n8R~
//    #endif                                                       //~v5n8R~
      cpsys=atoi(cpgetwk);                                         //~v5n8I~
      #ifndef WXE                                                  //~v5n8I~
		cpcon=(int)GetConsoleCP();                                 //~v5n8I~
        if (cpcon==CP_UTF8)  //65001                               //~v6t2R~
			uerrmsg("Cosole codepage:%d(UTF8) is not supported.(xe is supporting utf8 encoded file)",0,//~v6t2R~
					 CP_UTF8);                                     //~v6t2I~
                                                                   //~v6t2I~
	UTRACEP("consoleCP=%d,GetLocaleInfo=%d\n",GetConsoleCP(),cpsys);                      //~v5n8M~//~v62uR~
        if (cpcon!=cpsys)                                          //~v5n8I~
        {                                                          //~v5n8I~
        	cpsys=cpcon;                                           //~v5n8I~
            Gudbcschk_flag|=UDBCSCHK_CONSCP;    //consoleCP!=SYSTEM default//~v5n8I~
        }                                                          //~v5n8I~
      #endif                                                       //~v5n8I~
      return cpsys;	                                               //~v5n8I~
	#else                                                          //~v150I~
        apiret=DosQueryCp(sizeof(cplist),cplist,&cpsize);          //~v150I~
		if (apiret)                                                //~v150I~
			uerrexit("DosQueryCp failed,rc=%d",                    //~v150R~
					 "DosQueryCp API‚ÌŽ¸”s(r.c=%d)",               //~v150R~
					 apiret);                                      //~v150I~
		return (int)cplist[0];                                     //~v150R~
    #endif                                                         //~v150I~
#endif                                                             //~v150I~
#endif		//!UNX                                                 //~v326R~
}//ugetcp                                                          //~v150I~
#ifdef W32                                                         //~v5n1M~
//*************************************************************************//~v5n1M~
//*get codepage info                                               //~v5n1M~
//*************************************************************************//~v5n1M~
int udbcschk_getcpinfo(int Popt,ULONG Pcp,void *Ppinfo)            //~v5n1I~
{                                                                  //~v5n1M~
    int rc=0,flg=0;                                                //~v5n1M~
    LPCPINFOEX   pinfo;                                            //~v5n1M~
static char Sgb18030_leadbyte[2]={0x81,0xfe};                      //~v5n5I~
//**********************                                           //~v5n1M~
UTRACEP("getcpinfo cp=%ld\n",Pcp);                                 //~v5n1M~
	pinfo=(LPCPINFOEX)Ppinfo;                                      //~v5n1M~
    if (!GetCPInfoEx(Pcp,flg,pinfo))                               //~v5n1M~
    	rc=4;                                                      //~v5n1M~
    if (!pinfo->LeadByte[0])                                       //~v5n5I~
    	if (Pcp==CP_GB18030)                                       //~v5n5I~
        {                                                          //~v5n5I~
			UTRACED("cpinfo for gb18030 \n",pinfo,sizeof(CPINFOEX));//~v5n5I~
        	memcpy(pinfo->LeadByte,Sgb18030_leadbyte,sizeof(Sgb18030_leadbyte));//~v5n5I~
        }                                                          //~v5n5I~
UTRACED("cpinfo",pinfo,sizeof(CPINFOEX));                        //~v5n1M~//~v65cR~
UTRACEP("cpinfo rc=%d,lasterr=%d\n",rc,GetLastError());            //~v5n1R~
	memcpy(&Scpinfo,pinfo,sizeof(Scpinfo));  //for leadbyte chk    //~v6BAR~
    return rc;                                                     //~v5n1M~
}//udbcschk_getcpinfo                                              //~v5n1I~
#endif    //W32                                                    //~v5n1M~
#ifdef W32                                                         //~v5n1I~
//*************************************************************************//~v5n1I~
//*get codepage type                                               //~v5n1I~
//*return maxcharlength                                            //~v5n1I~
//*************************************************************************//~v5n1I~
int udbcschk_getcodepagetype(int Popt,ULONG Pcp)                   //~v5n1I~
{                                                                  //~v5n1I~
    int rc=0;                                                      //~v5n8R~
    CPINFOEX   info;                                               //~v5n1I~
//**********************                                           //~v5n1I~
UTRACEP("getcodepagetype cp=%ld\n",Pcp);                           //~v5n1I~
	if (udbcschk_getcpinfo(Popt,Pcp,&info))                        //~v5n1I~
    	rc=-1;                                                     //~v5n1R~
    else                                                           //~v5n0I~
	    rc=info.MaxCharSize;                                       //~v5n0R~
UTRACEP("getcodepagetype rc=%d\n",rc);                             //~v5n1I~
    return rc;                                                     //~v5n1I~
}//udbcschk_getcodepagetype                                        //~v5n1I~
#endif    //W32                                                    //~v5n1I~
#ifdef W32                                                         //~v5n0I~
//*************************************************************************//~v5n0I~
//*get codepage subchar                                            //~v5n0I~
//* out:sbcs by MB and unicode                                     //~v5n0R~
//*************************************************************************//~v5n0I~
int udbcschk_getsubch(int Popt,ULONG Pcp,int *Ppsubchsbcs,int *Ppsubchdbcs)//~v5n0I~
{                                                                  //~v5n0I~
    int rc=0,subchd=0,subchs=0;                                    //~v5n0I~
    CPINFOEX   info;                                               //~v5n0I~
//**********************                                           //~v5n0I~
UTRACEP("getsubch cp=%ld\n",Pcp);                                  //~v5n0I~
	if (udbcschk_getcpinfo(Popt,Pcp,&info))                        //~v5n0I~
    	rc=-1;                                                     //~v5n0I~
    else                                                           //~v5n0I~
    {                                                              //~v5n0I~
	    subchs=info.DefaultChar[0];                                //~v5n0I~
	    subchd=info.UnicodeDefaultChar;                            //~v5n0I~
    }                                                              //~v5n0I~
    if (Ppsubchdbcs)                                               //~v5n0I~
    	*Ppsubchdbcs=subchd;                                       //~v5n0I~
    if (Ppsubchsbcs)                                               //~v5n0I~
    	*Ppsubchsbcs=subchs;                                       //~v5n0I~
UTRACEP("getsubch rc=%d sbcs=%04x,ucs=%04x\n",rc,subchs,subchd);  //~v5n0I~//~v65cR~
    return rc;                                                     //~v5n0I~
}//udbcschk_getsubch                                               //~v5n0I~
#endif    //W32                                                    //~v5n0I~
#ifdef W32                                                         //~v5n1I~
//*************************************************************************//~v5n1I~
//*setup DBCS lead byte tbl                                        //~v5n1I~
//*return 1:mbcs(leard byte),0:no lead byte,-1:err                 //~v5n0R~
//*************************************************************************//~v5n1I~
int udbcschk_getstarter(int Popt,ULONG Pcp,UCHAR *Pflags,UCHAR *Pleadbyte)//~v5n8R~
{                                                                  //~v5n1I~
    int ii,jj,dbcssw;                                              //~v5n8R~
    CPINFOEX   info;                                               //~v5n1I~
    UCHAR *pc;                                                     //~v5n1I~
//**********************                                           //~v5n1I~
UTRACEP("getstarter cp=%ld\n",Pcp);                                //~v5n1I~
	if (udbcschk_getcpinfo(Popt,Pcp,&info))                        //~v5n1I~
    	return -1;                                                 //~v5n0R~
    pc=info.LeadByte;                                              //~v5n1I~
    dbcssw=*pc!=0;                                                 //~v5n0I~
    if (Pflags)                                                    //~v5n1I~
    {                                                              //~v5n1I~
        memset(Pflags,0,256);                                      //~v5n0I~
		for (jj=0;jj<MAX_LEADBYTES && *pc;jj++,pc+=2)              //~v5n1I~
		{                                                          //~v5n1I~
			for (ii=*pc;ii<=*(pc+1);ii++)                          //~v5n1I~
				Pflags[ii]=1;	//DBCS                             //~v5n1I~
		}                                                          //~v5n1I~
UTRACED("getstarter dbcstbl",Pflags,256);                          //~v5n1I~
    }                                                              //~v5n1I~
    if (Pleadbyte)                                                 //~v5n1I~
    {                                                              //~v5n1I~
		memcpy(Pleadbyte,info.LeadByte,MAX_LEADBYTES);             //~v5n8R~
UTRACED("getstarter leadbyte",Pleadbyte,MAX_LEADBYTES);            //~v5n1R~
    }                                                              //~v5n1I~
    return dbcssw;                                                 //~v5n0R~
}//udbcschk_getstarter                                             //~v5n1I~
#endif    //W32                                                    //~v5n1I~
//#endif	//!WXE                                                 //~v570R~
//*******************************************************          //~v024I~
//*udbcsenv*                                                       //~v024I~
//*return 256 byte table : x00-sbcs x01:dbcs first byte            //~v024I~
//*       null if no dbcs env                                      //~v024I~
//*******************************************************          //~v024I~
char *udbcsenv(void)                                               //~v024I~
{                                                                  //~v024I~
//**********************                                           //~v024I~
	udbcschk(0);		//create static table                      //~v024I~
	if (*Sdbcsenv)                                                 //~v024I~
    	return Sdbcstbl;                                           //~v024I~
	return 0;                                                      //~v024I~
}//udbcsenv                                                        //~v024I~
                                                                   //~v024I~
//**************************************************
//*get DBCS first byte range tbl
//**************************************************
UCHAR *udosquerydbcsenv(void)                                      //~v024R~
{
#ifdef UNX                                                         //~v326R~
  #ifdef LNX                                                       //~v39xI~
	static UCHAR Seuc[]={0xa1,0xfe,0,0};//a1-fe euc dbcs 1st/2nd byte//~v39xI~
  #else                                                            //~v39xI~
    static UCHAR Sdefaulttbl[]={0x81,0x9f,0xe0,0xfc,0,0};          //~v326I~
  #endif                                                           //~v39xI~
    static UCHAR Snulltbl[]={0,0};                                 //~v326I~
    UCHAR *plang;                                                  //~v326I~
#else        //!LINUX                                              //~v326I~
#ifdef DOS  					//v7.0a
	union REGS	 reg;
	struct SREGS sreg;
  #ifdef DPMI					//DPMI version                     //~v053I~
    static UCHAR Sdbcsvector[16];                                  //~v053R~
  #else                       //not DPMI                           //~v053I~
	unsigned char far **fpc;
	USHORT fpi[2];
  #endif                      //DPMI or not                        //~v053M~
#else							//v7.0a
	#ifdef W32                                                     //~v022I~
//static CPINFO cpi;                                               //~v5n8R~
static CPINFOEX cpi;                                               //~v5n8I~
//        UINT   cpno;                                             //~v150R~
        BOOL   success;                                            //~v022I~
        int    cpno;                                               //~v5n8I~
	#else                                                          //~v022I~
//static	UCHAR  dbcstbl[8];                                     //~v061R~
static	UCHAR  dbcstbl[12];                                        //~v061I~
	COUNTRYCODE countrycode={0,0}; 
	APIRET apiret;
	#endif							//v7.0a                        //~v022I~
#endif							//v7.0a
#endif				//!LINUX                                       //~v326I~
//*********************
#ifdef UNX                                                         //~v326R~
  #ifdef LNX                                                       //~v5ifI~
// #ifdef UTF8SUPP                                                 //~v5n8R~
#ifdef UTF8SUPPH                                                   //~v627I~
//	if (!(plang=udbcschk_setlocale(0,LC_ALL,"")))                  //~v62MR~
    if (!(plang=udbcschk_setlocale(UDCSLO_GETENV,LC_ALL,"")))      //~v62MI~
#else                                                              //~v627I~
	if (!(plang=setlocale(LC_ALL,"")))                             //~v5ifI~
#endif                                                             //~v627I~
// #else                                                           //~v5n8R~
//  if (!(plang=getenv("LANG")))                                   //~v5n8R~
// #endif                                                          //~v5n8R~
  #else                                                            //~v5ifI~
	if (!(plang=getenv("LANG")))                                   //~v326I~
  #endif                                                           //~v5ifI~
    	return Snulltbl;                                           //~v326R~
//  if (!ustrstri(plang,"JP"))                                     //~v40oR~
    if (!strstr(plang,"Ja_JP")) 	//SJIS                         //~v39kR~
  {//!sjis                                                         //~v582I~
    if (strstr(plang,"ja_JP")) 	//EUC                              //~v39kR~
    {                                                              //~v39kI~
//    if (strstr(plang,"UTF-8")) //utf8                            //~v68gR~
      if (ustrstri(plang,LOCALEID_UTF_8) //utf-8                   //~v68gR~
      ||  ustrstri(plang,LOCALEID_UTF8)) //utf8                    //~v68gR~
      {                                                            //~v5i9I~
    	Gudbcschk_flag|=UDBCSCHK_UTF8;                             //~v5i7I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8R~
    	Gudbcschk_flag|=UDBCSCHK_UTF8J;                            //~v5i9I~
#endif                                                             //~v600I~
      }                                                            //~v5i9I~
      else                                                         //~v5i7I~
    	Gudbcschk_flag|=UDBCSCHK_EUC;                              //~v39xR~
#ifdef LNX                                                         //~v39kI~
    	if (Gudbcschk_flag&UDBCSCHK_UTF8)                          //~v5i7I~
	    	return Snulltbl;	//cannot determined by 1st byte    //~v5i7I~
//  	return Snulltbl;                                           //~v39xR~
    	return Seuc;                                               //~v39xI~
#endif                                                             //~v39kI~
    }                                                              //~v39kI~
    else                                                           //~v39kI~
    {//!sjis & !euc                                                //~v5i9I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8R~
//    	if (strstr(plang,"UTF-8")) //utf8                          //~v68gR~
        if (ustrstri(plang,LOCALEID_UTF_8) //utf-8                 //~v68gI~
        ||  ustrstri(plang,LOCALEID_UTF8)) //utf8                  //~v68gI~
    		Gudbcschk_flag|=(UDBCSCHK_UTF8|UDBCSCHK_UTF8E);        //~v5i9M~
#endif                                                             //~v600I~
    	return Snulltbl;                                           //~v326I~
    }                                                              //~v5i9I~
  }//!sjis                                                         //~v582I~
//  return Sdefaulttbl;                                            //~v326I~
	#ifdef LNX	                                                   //~v40oI~
    	return Snulltbl;                                           //~v39kR~
	#else                                                          //~v40oI~
		return Sdefaulttbl;                                        //~v40oI~
    #endif                                                         //~v40oI~
#else        //!LINUX                                              //~v326I~
#ifdef DOS  
    memset(&reg,0,sizeof(reg));                                    //~v053I~
    memset(&sreg,0,sizeof(sreg));                                  //~v053I~
    reg.x.ax=0x6300;				  //get DBCS vector
  #ifdef DPMI					//DPMI version                     //~v053M~
    udpmiint86s(0x21,&reg,&reg,&sreg); //DS:SI point dbcs tbl      //~v053R~
    udpmidosmemget(Sdbcsvector,(int)sreg.ds,(int)reg.x.si,sizeof(Sdbcsvector));//~v053R~
    return Sdbcsvector;                                            //~v053M~
  #else                       //not DPMI                           //~v053M~
    intdosx(&reg,&reg,&sreg);	
 	fpi[0]=reg.x.si;					//DS:SI=vector tbl addr
 	fpi[1]=sreg.ds;						//DS:SI=vector tbl addr
	fpc=(unsigned char far **)(void*)fpi;			//as far ptr
	return *fpc;
  #endif                      //DPMI or not                        //~v053I~
#else
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP  //Win and Linux                                     //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v627I~
//	udbcschk_setlocale(0,LC_ALL,"");   //require for iswprint()    //~v62MR~
#else                                                              //~v627I~
	setlocale(LC_ALL,"");   //require for iswprint()               //~v609R~
#endif                                                             //~v627I~
#endif                                                             //~v609R~
	#ifdef W32                                                     //~v022I~
    	cpno=ugetcp();                                             //~v5n8I~
        Scodepage2=cpno;		//for udbcschkcp SBCS env          //~v62zR~
//  	success=GetCPInfo(CP_ACP,&cpi);                            //~v5n8R~
		success=(udbcschk_getcpinfo(0,cpno,&cpi)==0);              //~v5n8I~
    	if (!success)                  	//false                    //~v022R~
    		uerrexit("GetCPInfo failed",0);                        //~v022R~
//        cpno=GetConsoleCP();                                     //~v150R~
//        if (cpno!=932)                                           //~v150R~
//            memset(&cpi,0,sizeof(cpi));                          //~v150R~
    	return cpi.LeadByte;                                       //~v022I~
	#else                                                          //~v022I~
	apiret=DosQueryDBCSEnv(12,&countrycode,dbcstbl);
	if (apiret)
		uerrexit("DosQueryDBCSEnv failed,rc=%d",
				 "DosQueryDBCSEnv API‚ÌŽ¸”s(r.c=%d)",
				 apiret);
	return dbcstbl;
	#endif	                                                       //~v022I~
#endif	
#endif       //!LINUX                                              //~v326I~
}//querydbcsenv
                                                                   //~v051I~
//*******************************************************          //~v051I~
//*udbcschk2                                                       //~v051R~
//* dbcs check of specified offset of char on the string           //~v051R~
//* parm1 :buffer                                                  //~v051I~
//* parm2 :char offset                                             //~v051I~
//* return:0:no dbcs,1:dbcs 1st byte,2:dbcs 2nd byte               //~v051R~
//******************************************************           //~v051I~
int udbcschk2(char *Pbuff,int Poffs)                               //~v051R~
{                                                                  //~v051I~
	char *pc,*pc2;                                                 //~v051R~
    int  dbcstype=0;                                                 //~v051I~
//*********************************                                //~v051I~
	pc2=Pbuff+Poffs+1;	//end addr                                 //~v051R~
	for (pc=Pbuff;pc<pc2;pc++)                                     //~v051R~
    {                                                              //~v051I~
//		if ((dbcstype=udbcschk(*pc)),dbcstype)	//dbcs 1st byte    //~v61fR~
    	if ((dbcstype=udbcschk_hk(0,*pc)),dbcstype)	//dbcs 1st byte//~v61fR~
    		pc++;                                                  //~v051I~
	}                                                              //~v051I~
    if (pc!=pc2)	//it is 1st byte        (1st)|next             //~v051R~
    	return 1;                                                  //~v051I~
    if (dbcstype)	//  1st,(2nd)|                                 //~v051I~
    	return 2;                                                  //~v051I~
	else                                                           //~v051I~
		return 0;	//  any,(sbcs)|                                //~v051R~
}//udbcschk2                                                       //~v051R~
//*******************************************************          //~v620I~
//*udbcschk_pos2offs                                               //~v620I~
//* get offset from column position if all is valid utf8 string    //~v62pR~
//* else by dbcs chk                                               //~v62pR~
//* return:0:no dbcs,1:dbcs 1st byte,2:dbcs 2nd byte               //~v62pI~
//*        3:utf8 split,4:out of range,8 parm err                  //~v62pI~
//******************************************************           //~v620I~
int udbcschk_pos2offs(int Popt,char *Pbuff,int Plen,int Ppos,int *Ppoffs)//~v62pR~
{                                                                  //~v620I~
    int  ucscnt,len,utf8len,rc=0,offs;                               //~v62pR~//~v6h6R~
//*********************************                                //~v620I~
	if (!(len=Plen))                                               //~v62pI~
//  	len=strlen(Pbuff);                                         //~v62pI~//~v6BkR~
    	len=(int)strlen(Pbuff);                                    //~v6BkI~
    utf8len=utfgetutf8strlen(0,Pbuff,len,&ucscnt);                 //~v62pI~
    if (utf8len!=len)	//not valid utf8 string                    //~v62pI~
    {                                                              //~v62pI~
        offs=Ppos;                                                 //~v62pR~
    	if (len<Ppos)                                              //~v62pR~
        	return 4;                                              //~v62pI~
    	if (len>Ppos)                                              //~v62pR~
        {                                                          //~v62pI~
			rc=udbcschk2(Pbuff,Ppos);                              //~v62pR~
        	if (rc==2)	//dbcs split                               //~v62pR~
            	offs--;                                            //~v62pI~
        }                                                          //~v62pI~
        *Ppoffs=offs;                                              //~v62pI~
        return rc;                                                 //~v62pI~
    }                                                              //~v62pI~
    if (Popt & UDCPOO_LIMIT_UCSCOUNT)                              //~v62pI~
    {                                                              //~v62pI~
    	offs=len;                                                  //~v62pI~
        if (ucscnt<Ppos)                                           //~v62pI~
            return 4;                                              //~v62pI~
        if (ucscnt>Ppos)                                           //~v62pI~
        {                                                          //~v62pI~
        	ucscnt=Ppos;                                           //~v62pI~
		    offs=utfgetutf8strlen(UGU8LO_LIMIT_UCSCOUNT,Pbuff,len,&ucscnt);//~v62pI~
        }                                                          //~v62pI~
        *Ppoffs=offs;                                              //~v62pI~
        return 0;                                                  //~v62pI~
    }                                                              //~v62pI~
//limit by strlen ***                                              //~v62pI~
    offs=len;                                                      //~v62pI~
    if (len<Ppos)                                                  //~v62pI~
        return 4;                                                  //~v62pI~
    rc=0;                                                          //~v62pI~
    if (len>Ppos)                                                  //~v62pI~
    {                                                              //~v62pI~
        len=Ppos;                                                  //~v62pI~
        offs=utfgetutf8strlen(0,Pbuff,len,&ucscnt);                //~v62pR~
        if (offs<len)   //split utf8 code                          //~v62pI~
            rc=3;                                                  //~v62pI~
    }                                                              //~v62pI~
    *Ppoffs=offs;                                                  //~v62pI~
    return rc;                                                     //~v62pI~
}//udbcschk_pos2offs                                               //~v62pR~
#ifdef W32UNICODE                                                  //~v6uhI~
//*******************************************************          //~v6uhI~
//*dbcs tbl output ,no dbcs between UID                            //~v6uhI~
//*******************************************************          //~v6uhI~
int usetdbcstblW(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)    //~v6uhI~
{                                                                  //~v6uhI~
    int reslen,rc=0,len,lenud;                                     //~v6uhI~
    char *pc,*pc2,*pc3,*pcd;                                       //~v6uhI~
//***************                                                  //~v6uhI~
	for (pc=Ppdata,pcd=Ppdbcs,reslen=Plen;reslen;)                 //~v6uhR~
    {                                                              //~v6uhI~
    	lenud=0;                                                   //~v6uhI~
        pc2=memchr(pc,UD_NOTLC,reslen);                            //~v6uhI~
        if (pc2)                                                   //~v6uhI~
        {                                                          //~v6uhI~
            len=PTRDIFF(pc2,pc);                                   //~v6uhI~
	        pc3=memchr(pc2+1,UD_NOTLC,reslen-1);                   //~v6uhI~
            if (pc3)                                               //~v6uhI~
	            lenud=PTRDIFF(pc3,pc2)+1;                          //~v6uhI~
            else   //pair err                                      //~v6uhR~
            {                                                      //~v6uhI~
                pc++;   //avoid loop                               //~v6uhI~
                *pcd++=0;                                          //~v6uhI~
            	len=--reslen;                                      //~v6uhR~
            }                                                      //~v6uhI~
        }                                                          //~v6uhI~
        else                                                       //~v6uhI~
            len=reslen;                                            //~v6uhI~
        if (len)                                                   //~v6uhI~
        {                                                          //~v6uhI~
        	rc|=usetdbcstbl(Popt,pc,pcd,len);                      //~v6uhR~
            pc+=len;                                               //~v6uhI~
            pcd+=len;                                              //~v6uhI~
            reslen-=len;                                           //~v6uhI~
        }                                                          //~v6uhI~
        if (lenud)                                                 //~v6uhI~
        {                                                          //~v6uhI~
        	memset(pcd,0,lenud);                                   //~v6uhI~
            pc+=lenud;                                             //~v6uhI~
            pcd+=lenud;                                            //~v6uhI~
            reslen-=lenud;                                         //~v6uhI~
        }                                                          //~v6uhI~
    }                                                              //~v6uhI~
    return rc;                                                     //~v6uhI~
}//usetdbcstblW                                                    //~v6uhI~
#endif	//W32UNICODE                                               //~v6uhI~
//*******************************************************          //~v56xI~
//*dbcs tbl output                                                 //~v56xI~
//*******************************************************          //~v56xI~
int usetdbcstbl(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)     //~v56xR~
{                                                                  //~v56xI~
    int ii,rc=0;                                                   //~v56xR~
//***************                                                  //~v56xI~
#ifdef W32UNICODE                                                  //~v6uhI~
    if (memchr(Ppdata,UD_NOTLC,Plen))                              //~v6uhR~
        return usetdbcstblW(Popt,Ppdata,Ppdbcs,Plen);              //~v6uhI~
#endif                                                             //~v6uhI~
    switch(Popt & USDT_CODE_TYPE)                                  //~v56xI~
    {                                                              //~v56xI~
    case USDT_CODE_SJISX208:                                       //~v56xI~
    	usjischk(Ppdata,Plen,Ppdbcs,0,0);                          //~v56xI~
    	break;                                                     //~v56xI~
    case USDT_CODE_EUC:                                            //~v56xI~
#ifdef WCSUPP                                                      //~v5n8I~
//    	if (UDBCSCHK_ISWCDBCS())	//CJK                          //~v62UR~
      	if (UDBCSCHK_DBCSCVEXT())	//CJK                          //~v62UR~
        {                                                          //~v5n8I~
			usetdbcstblmb(0,Ppdata,Ppdbcs,Plen);                   //~v5n8R~
	    	break;                                                 //~v5n8I~
        }                                                          //~v5n8I~
#endif                                                             //~v5n8I~
    	ueucchk(Ppdata,Plen,Ppdbcs,0,0);                           //~v56xR~
    	break;                                                     //~v56xI~
    case USDT_CODE_SJIS:                                           //~v56xI~
#ifdef WCSUPP                                                      //~v5n8I~
//    	if (UDBCSCHK_ISWCDBCS())	//CJK                          //~v62UR~
      	if (UDBCSCHK_DBCSCVEXT())	//CJK                          //~v62UR~
        {                                                          //~v5n8I~
			usetdbcstblmb(0,Ppdata,Ppdbcs,Plen);                   //~v5n8I~
	    	break;                                                 //~v5n8I~
        }                                                          //~v5n8I~
#endif                                                             //~v5n8I~
        for (ii=0;ii<Plen;ii++,Ppdata++,Ppdbcs++)                  //~v56xR~
        {                                                          //~v56xR~
            if (SJIS1(*Ppdata))	//1st byte range chk only          //~v56xR~
            {                                                      //~v56xR~
//sjis                                                             //~v62UR~
                *Ppdbcs++=UDBCSCHK_DBCS1ST;                        //~v56xR~
                if (ii<(Plen-1))                                   //~v56xI~
                	*Ppdbcs  =UDBCSCHK_DBCS2ND;                    //~v56xR~
                Ppdata++;                                          //~v56xR~
                ii++;                                              //~v56xR~
            }                                                      //~v56xR~
            else                                                   //~v56xR~
                *Ppdbcs=0;                                         //~v56xR~
        }                                                          //~v56xR~
    	break;                                                     //~v56xI~
    case USDT_CODE_SJIS2:                                          //~v56xI~
#ifdef WCSUPP                                                      //~v5n8I~
      	if (UDBCSCHK_ISWCDBCS())	//CJK                          //~v5n8I~
        {                                                          //~v5n8I~
			usetdbcstblmb(USDTMO_CHK2ND,Ppdata,Ppdbcs,Plen);       //~v5n8R~
	    	break;                                                 //~v5n8I~
        }                                                          //~v5n8I~
#endif                                                             //~v5n8I~
        for (ii=0;ii<Plen;ii++,Ppdata++,Ppdbcs++)                  //~v56xI~
        {                                                          //~v56xI~
            if (SJIS1(*Ppdata)	//1st byte range chk only          //~v56xI~
            && ii<(Plen-1)                                         //~v56xI~
            &&  SJIS2(*(Ppdata+1)))	//1st byte range chk only      //~v5n8R~
            {                                                      //~v56xI~
//sjis                                                             //~v62UR~
                *Ppdbcs++=UDBCSCHK_DBCS1ST;                        //~v56xR~
                *Ppdbcs  =UDBCSCHK_DBCS2ND;                        //~v56xR~
                Ppdata++;                                          //~v56xI~
                ii++;                                              //~v56xI~
            }                                                      //~v56xI~
            else                                                   //~v56xI~
                *Ppdbcs=0;                                         //~v56xI~
        }                                                          //~v56xI~
    	break;                                                     //~v56xI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
    case USDT_CODE_UTF8:                                           //~v60aI~
    	utfsetdbcstbl(0,Ppdata,Ppdbcs,0/*no chof*/,Plen,0,0);      //~v618R~
    	break;                                                     //~v60aI~
    case USDT_CODE_ANY:                                            //~v62UR~
		usetdbcstblmb(USDTMO_CHK2ND,Ppdata,Ppdbcs,Plen);           //~v62UR~
    	break;                                                     //~v62UR~
#endif                                                             //~v60aI~
    default:                                                       //~v56xI~
        rc=16;                                                     //~v56xI~
    }//code type                                                   //~v56xI~
    return rc;                                                     //~v56xR~
}//usetdbcstbl                                                     //~v56xR~
#ifdef WCSUPP                                                      //~v5n8I~
//*******************************************************          //~v5n8I~
//*dbcs tbl output other than Japanese                             //~v5n8I~
//*******************************************************          //~v5n8I~
int usetdbcstblmb(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)   //~v5n8I~
{                                                                  //~v5n8I~
    int rc=0;                                                      //~v62UR~
    int reslen,mblen,tabkeepsw,consolesw;                          //~v62UR~
    UCHAR *pc,*pcd,ch;                                             //~v62UR~
//***************                                                  //~v5n8I~
	if (!Swcinitsw)                                                //~v62UR~
    {                                                              //~v62UR~
    	if (!(Gudbcschk_flag & UDBCSCHK_BEFOREINIT))	//force english before wcinit for xe//~v62UR~
//  		udbcschk_wcinit(0,0);                                  //~v62UR~//~v638R~
  		    udbcschk_wcinit(UDCWCIO_INTERNAL,0);                   //~v638I~
    }                                                              //~v62UR~
    tabkeepsw=Popt & USDTMO_TABKEEP;                               //~v62UR~
    consolesw=Popt & USDTMO_CONSOLE;     //not X black full screen //~v62UR~
  if (UDBCSCHK_ISDBCS())                                           //~v62UR~
  {                                                                //~v62UR~
//  for (ii=0;ii<Plen;ii++,Ppdata++,Ppdbcs++)                      //~v62UR~
    for (reslen=Plen,pc=Ppdata,pcd=Ppdbcs;reslen>0;reslen-=mblen,pc+=mblen,pcd+=mblen)//~v62UR~
    {                                                              //~v5n8I~
        ch=*pc;                                                    //~v62UR~
        mblen=1;                                                   //~v62UR~
        if (tabkeepsw)                                             //~v62UR~
        {                                                          //~v62UR~
            if (*pcd==UDBCSCHK_F2LERR)                             //~v636I~
                continue;                                          //~v636I~
            if (*pcd==UDBCSCHK_DBCS1ST                             //~v62UR~
            ||  *pcd==UDBCSCHK_DBCSPAD                             //~v62UR~
            ||  *pcd==UDBCSCHK_DBCS2ND                             //~v62UR~
            )                                                      //~v62UR~
	        	*pcd=0;     //once clear set later if dbcs         //~v62UR~
        }                                                          //~v62UR~
        else                                                       //~v62UR~
	        *pcd=0;     //clear also tab and tab padding           //~v62UR~
        if (consolesw)                                             //~v62UR~
        	continue;	//all sbcs                                 //~v62UR~
//      if (udbcschk(*Ppdata))                                     //~v62UR~
        if (ch>=0x80 && UDBCSCHK_ISDBCS1ST(ch))                    //~v62UR~
        {                                                          //~v5n8I~
            mblen=2;                                               //~v62UR~
        	if (ISSS3(ch))	//EUC 8fxxxx                           //~v62UR~
                mblen=3;                                           //~v62UR~
            else                                                   //~v62UR~
            if (UDBCSCHK_ISGB41STHALF(pc,reslen))                  //~v62UR~
                mblen=4;                                           //~v62UR~
//      	if (ii<(Plen-1))                                       //~v62UR~
        	if (reslen>=mblen)                                     //~v62UR~
            {                                                      //~v5n8I~
        		if (tabkeepsw                                      //~v636I~
            	&&  memchr(pcd+1,UDBCSCHK_F2LERR,(UINT)(mblen-1))  //~v636I~
                )                                                  //~v636I~
                {                                                  //~v636I~
	                mblen=1;   //chk restart from next             //~v636I~
    	            *pcd=UDBCSCHK_HKDBCSERR;                       //~v636I~
                    rc|=UDBCSCHK_RC_DBCSERR;//      0x02	//err dbcs//~v636I~
                }                                                  //~v636I~
                else                                               //~v636I~
		  		if (!(Popt & USDTMO_CHK2ND)      //NO 1st+2nd byte pair chk//~v5n8I~
//	      		||    WCMB2ND(0,(Ppdata+1))	//2nd byte ok          //~v62UR~
  	      		||    udbcschk_isvalidmbchar(0,pc,mblen)	//validity chk//~v62UR~
          		)                                                  //~v5n8I~
          		{                                                  //~v5n8I~
//          		*Ppdbcs++=UDBCSCHK_DBCS1ST;                    //~v62UR~
//              	*Ppdbcs  =UDBCSCHK_DBCS2ND;                    //~v62UR~
//  	            Ppdata++;                                      //~v62UR~
//      		    ii++;                                          //~v62UR~
					*pcd=UDBCSCHK_DBCS1ST;                         //~v62UR~
					*(pcd+1)=UDBCSCHK_DBCS2ND;                     //~v62UR~
                    rc|=UDBCSCHK_RC_DBCSFOUND;//    0x20	//dbcs found//~v62UR~
                    if (mblen>2)                                   //~v62UR~
                    {	                                           //~v62UR~
                        if (mblen==3) //SS3                        //~v62UR~
                        {                                          //~v62UR~
							*(pcd+1)=UDBCSCHK_DBCSPAD;             //~v62UR~
							*(pcd+2)=UDBCSCHK_DBCS2ND;             //~v62UR~
                            rc|=UDBCSCHK_RC_SS3;    //1d2 pattern  //~v62UR~
                        }                                          //~v62UR~
                        else                                       //~v62UR~
                        {                                          //~v62UR~
							*(pcd+1)=UDBCSCHK_DBCSPAD;             //~v62UR~
							*(pcd+2)=UDBCSCHK_DBCSPAD;             //~v62UR~
							*(pcd+3)=UDBCSCHK_DBCS2ND;             //~v62UR~
                            rc|=UDBCSCHK_RC_GB4; //1dd2 pattern    //~v62UR~
                        }                                          //~v62UR~
                    }//SS3 or GB4                                  //~v62UR~
            	}                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v62UR~
//  	            *Ppdbcs=UDBCSCHK_HKDBCSERR;                    //~v62UR~
                  if (Popt & USDTMO_SETERRFULL) //set err to all bte//~v62UR~
    	            memset(pcd,UDBCSCHK_HKDBCSERR,(UINT)mblen);    //~v62UR~
                  else                                             //~v62UR~
                  {                                                //~v62UR~
	                mblen=1;   //chk restart from next             //~v62UR~
    	            *pcd=UDBCSCHK_HKDBCSERR;                       //~v62UR~
                  }                                                //~v62UR~
                    rc|=UDBCSCHK_RC_DBCSERR;//      0x02	//err dbcs//~v62UR~
                }                                                  //~v62UR~
            }                                                      //~v5n8I~
            else                                                   //~v5n8I~
            {                                                      //~v5n8I~
                mblen=1;   //chk restart from next                 //~v62UR~
				if (Popt & (USDTMO_SPLITERR|USDTMO_CHK2ND))        //~v5n8R~
                {                                                  //~v62UR~
//  	            *Ppdbcs=UDBCSCHK_HKDBCSERR;                    //~v62UR~
                  if (Popt & USDTMO_SETERRFULL) //set err to all bte//~v62UR~
                  {                                                //~v62UR~
//                  	mblen=reslen;                                  //~v62UR~//~v636R~
//                   	mblen=min(reslen,mblen);                       //~v636I~//~v646R~
                    	mblen=reslen;                              //~v646I~
    	            memset(pcd,UDBCSCHK_HKDBCSERR,(UINT)mblen);    //~v62UR~
                  }                                                //~v62UR~
                  else                                             //~v62UR~
    	            *pcd=UDBCSCHK_HKDBCSERR;                       //~v62UR~
                    rc|=UDBCSCHK_RC_DBCSSPLIT;//    0x40	//last byte is dbcs split//~v62UR~
                }                                                  //~v62UR~
//              else                                               //~v62UR~
//              {                                                  //~v62UR~
//  				if (Popt & USDTMO_SPLITSBCS)                   //~v62UR~
//		            	*Ppdbcs=UDBCSCHK_SBCS;     //0             //~v62UR~
//              }                                                  //~v62UR~
            }                                                      //~v5n8I~
        }                                                          //~v5n8I~
//      else                                                       //~v62UR~
//          *Ppdbcs=0;                                             //~v62UR~
    }                                                              //~v5n8I~
  }                                                                //~v62UR~
  else                                                             //~v62UR~
//  memset(Ppdbcs,0,Plen);                                         //~v62UR~//~v6BkR~
    memset(Ppdbcs,0,(size_t)Plen);                                 //~v6BkI~
//UTRACEP("usetdbcstblmb opt=%x,udbcschk_flag=%x,rc=%x\n",Popt,Gudbcschk_flag,rc);//~v62UR~//~v6k0R~
//UTRACED("usetdbcstblmb in  data",Ppdata,Plen);                     //~v62UR~//~v6k0R~
//UTRACED("usetdbcstblmb out dbcstbl",Ppdbcs,Plen);                  //~v62UR~//~v6k0R~
    return rc;                                                     //~v5n8I~
}//usetdbcstblmb                                                   //~v5n8I~
#endif	//WCSUPP                                                   //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v627I~
//*******************************************************          //~v627I~
//*issue setlocale only once                                       //~v627I~
//*if Plocale=0 ,back to ""                                        //~v627I~
//*******************************************************          //~v627I~
char *udbcschk_setlocale(int Popt,int Ptype,char *Plocale)         //~v627R~
{                                                                  //~v627I~
	static UCHAR Slocale[MAXLOCALESZ+1];                           //~v62UR~
	static UCHAR Slocaleenv[MAXLOCALESZ+1];                        //~v62UR~
    char  *pc,*penv;                                               //~v627R~
    char  *pc2;                                                    //~v6HvI~
//***************                                                  //~v627I~
    if (!Plocale)                                                  //~v627I~
    {                                                              //~v627I~
		pc=setlocale(Ptype,"");                                    //~v627R~
      if (pc)                                                      //~v69fI~
	    strncpy(Slocale,pc,MAXLOCALESZ);                           //~v627R~
#ifdef ARM                                                         //~v6a0I~
      else                                                         //~v6a0I~
      {                                                            //~v6f7I~
//    	strcpy(Slocale,ulibarm_getlocale());                       //~v6HvR~
      	strncpy(Slocale,ulibarm_getlocale(),MAXLOCALESZ);          //~v6HvI~
		pc=setlocale(Ptype,Slocale);    //@@@@test                 //~v6f7I~
      }                                                            //~v6f7I~
#endif                                                             //~v6a0I~
		pc2=strchr(Slocale,';'); //may be a fmt of "LC_CTYPE="C;LC_NUMERIC=..."//~v6HvI~
        if (pc2)                                                   //~v6HvI~
        	*pc2=0;                                                //~v6HvI~
		pc2=strchr(Slocale,'=');                                   //~v6HvI~
        if (pc2)                                                   //~v6HvI~
        	strcpy(Slocale,pc2+1);                                 //~v6HvI~
		if (!*Slocaleenv)                                          //~v6f3I~
        	strcpy(Slocaleenv,Slocale);	//save env for the case UDCSLO_GETENV//~v6f3I~
    }                                                              //~v627I~
    else                                                           //~v627I~
    {                                                              //~v627I~
    	if (*Plocale)                                              //~v627I~
        {                                                          //~v627I~
        	if (!*Slocaleenv)	//not once issued                  //~v699I~
            {                                                      //~v699I~
				pc=setlocale(Ptype,"");                            //~v699I~
                if (pc)                                            //~v699I~
	            	strncpy(Slocaleenv,pc,MAXLOCALESZ);            //~v699I~
            }                                                      //~v699I~
#ifdef LNX                                                         //~v62WI~
#ifndef ARM                                                        //~v6a0R~
UTRACEP("nl_langinfo=%s before setlocale %s\n",nl_langinfo(CODESET),Plocale);//~v62WI~
#endif                                                             //~v6a0R~
#endif                                                             //~v62WI~
			pc=setlocale(Ptype,Plocale);                           //~v627R~
UTRACEP("setlocale rc=%s\n",pc);                                   //~v62WI~
#ifdef LNX                                                         //~v62WI~
#ifndef ARM                                                        //~v6a0R~
UTRACEP("nl_langinfo=%s before setlocale %s\n",nl_langinfo(CODESET),Plocale);//~v62WI~
#endif                                                             //~v6a0R~
#endif                                                             //~v62WI~
            if (!pc)                                               //~v627I~
            {                                                      //~v62WI~
              	if (Popt & UDCSLO_CHKBASE)                         //~v62WI~
                	return 0;       //retry by caller              //~v62WI~
              	if (Popt & UDCSLO_CHKPARM) //from utfcvsetparmlocale//~v633I~
                {                                                  //~v633I~
#ifndef ARM   //setlocale fail for android                         //~v6faR~
//  	        	uerrmsg("Warining:setlocale failed for (%s),but charset is used as converter",0,//~v633R~//~v6C5R~
    	        	uerrmsg("Warning:setlocale failed for (%s),but charset is used as converter",0,//~v6C5I~
			                Plocale);                              //~v633I~
#endif                                                             //~v6faR~
                	return 0;       //retry by caller              //~v633I~
                }                                                  //~v633I~
            	uerrexit("Invalid localecode(%s)",0,               //~v627I~
			                Plocale);                              //~v627I~
            }                                                      //~v62WI~
            strncpy(Slocale,pc,MAXLOCALESZ);                       //~v627R~
        }                                                          //~v627I~
        else                                                       //~v627I~
        {                                                          //~v627I~
        	if (!*Slocale)	//not once issued                      //~v627I~
            {                                                      //~v627I~
				pc=setlocale(Ptype,"");                            //~v627R~
#ifdef ARM                                                         //~v6a0I~
      			if (!pc)                                           //~v6a0I~
      				pc=ulibarm_getlocale();                        //~v6a0I~
#endif                                                             //~v6a0I~
                if (!pc)                                           //~v627I~
                {                                                  //~v627I~
					penv=getenv("LANG");                           //~v627I~
                    strcpy(Slocale,"UTF-8");    //avoid recursive call from uerrexit//~v627I~
                    uerrexit("setlocale failed, check LANG environment setting(%s)",0,//~v627I~
                    			penv);                             //~v627I~
                }                                                  //~v627I~
	            strncpy(Slocale,pc,MAXLOCALESZ);                   //~v627R~
	            strncpy(Slocaleenv,pc,MAXLOCALESZ);                //~v62MI~
            }                                                      //~v627I~
        }                                                          //~v627I~
    }                                                              //~v627I~
    UTRACEP("udbcschk_setlocale parm=%s,out=%s,env=%s\n",Plocale,Slocale,Slocaleenv);//~v62MI~
    if (Popt & UDCSLO_GETENV)                                      //~v62MR~
    	return Slocaleenv;                                         //~v62MI~
	return Slocale;                                                //~v627I~
}//udbcschk_setlocale                                              //~v627I~
#ifdef W32                                                         //~v62uI~
//*******************************************************          //~v62uI~
//*udbcschk_wingetdefaultcp                                        //~v62uI~
//*return codepage no;-1 if failed                                 //~v62uI~
//******************************************************           //~v62uI~
int udbcschk_wingetdefaultcp(int Popt,char *Pplocale)              //~v62uI~
{                                                                  //~v62uI~
	CPINFOEX cpi;                                                  //~v62uI~
    int cpno,success;                                              //~v62uI~
//**************                                                   //~v62uI~
    cpno=ugetcp();                                                 //~v62uI~
	success=(udbcschk_getcpinfo(0,cpno,&cpi)==0);                  //~v62uI~
    if (!success)                  	//false                        //~v62uI~
    	return -1;                                                 //~v62uI~
    UstrncpyZ(Pplocale,cpi.CodePageName,MAXLOCALESZ);              //~v62uI~
    return cpno;                                                   //~v62uI~
}//udbcschk_wingetdefaultcp                                        //~v62uI~
#endif                                                             //~v62uI~
//*******************************************************          //~v62UR~
//*chk dbcs lang type                                              //~v62UR~
//******************************************************           //~v62UR~
int udbcschk_setdbcstype(int Popt,char *Pplocale,ULONG Phiconv)    //~v62UR~
{                                                                  //~v62UR~
#ifdef LNX  //i could not test windows Gb18030                     //~v62UR~
	char testgb18030mb[]={0x81,0x30,0x81,0x30};                    //~v62UR~
#ifdef UTF8UCS4                                                    //~v65cI~
	WUCS   usucs;                                                  //~v65cI~
	UWUCS  ucs4;                                                   //~v6f3I~
#else                                                              //~v65cI~
	USHORT usucs;                                                  //~v62UR~
#endif                                                             //~v65cI~
    int opt, chklen,rc2,chsz;                                      //~v62UR~
#else                                                              //~v6BBI~
	int cp;                                                        //~v6BBI~
#endif                                                             //~v62UR~
//**********************                                           //~v62UR~
	UTRACEP("%s:opt=%x,Phiconv=%p,Scodepage=%d\n",UTT,Popt,Phiconv,Scodepage);//~v6BBR~
    if (ustrstri(Pplocale,LANGEUCID))                              //~v62UR~
        Gudbcschk_flag|=UDBCSCHK_LANGEUC;   //for ss2/ss3 chk      //~v62UR~
#ifdef LNX	//i could not test windows Gb18030                     //~v62UR~
	chklen=4;                                                      //~v62UR~
	opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v62UR~
  if (UDBCSCHK_IS_LOCALICU())                                      //~v6f3R~
	rc2=ucvext_icumb2ucs1(UCVEXTO_SETSUBCHRC,*(ULONG*)Phiconv,testgb18030mb,chklen,&chsz,&ucs4);//~v6f3R~
  else                                                             //~v6f3I~
	rc2=ucvext_iconvlocal2ucs1(opt,Phiconv,testgb18030mb,chklen,&chsz,&usucs);//~v62UR~
    if (!rc2 && chsz==4)                                           //~v62UR~
        Gudbcschk_flag|=UDBCSCHK_LANGMB4;   //4 byte dbcs          //~v62UR~
#else                                                              //~v6BBI~
	cp=(int)Phiconv;                                               //~v6BBI~
    if (cp==CP_GB18030)                                            //~v6BBI~
        Gudbcschk_flag|=UDBCSCHK_LANGMB4;   //4 byte dbcs          //~v6BBI~
#endif                                                             //~v62UR~
    return 0;                                                      //~v62UR~
}//udbcschk_setdbcstype                                            //~v62UR~
                                                                   //~v6f3I~
#ifdef LNX                                                         //~v6f3I~
//*******************************************************          //~v6f3I~
//*setup ICU converter for localecode                              //~v6f3I~
//*Pphiconv:iconv_t(=void*)[2];                                    //~v6f3R~
//******************************************************           //~v6f3I~
int udbcschk_icugetlocalconverter(int Popt,char *Pplocale,ULONG *Ppconverters)//~v6f3R~
{                                                                  //~v6f3I~
//  ULONG converter,*pconverters;                                  //~v6f3R~//~v6f7R~
    int rc;                                                        //~v6f3I~
//********************                                             //~v6f3I~
	rc=ucvext_icumbinit(UCEIO_LOCALICU,Pplocale,Ppconverters);       //~v6f3R~//~v6f7R~
//  pconverters=Ppconverters;                                      //~v6f3R~//~v6f7R~
//  pconverters[0]=converter;                                      //~v6f3R~//~v6f7R~
//  pconverters[1]=converter;                                      //~v6f3I~//~v6f7R~
	if (!rc)                                                       //~v6f3R~
    	Gudbcschk_flag|=UDBCSCHK_LOCALICU;                         //~v6f3R~
    UTRACEP("udbcschk_icugetlocalconverter rc=%d,udbcschk_flag=%x\n",rc,Gudbcschk_flag);//~v6faI~
    UTRACED("udbcschk_icugetlocalconverter converters",Ppconverters,sizeof(ULONG)*2);//~v6f3R~//~v6f7R~
    return rc;                                                     //~v6f3R~
}//udbcschk_icugetlocalconverter                                   //~v6f3R~
#endif                                                             //~v6f3I~
#endif                                                             //~v627I~
#ifdef W32                                                         //~v6BAI~
//****************************************************************************************//~v6BAM~
//*chk leadbyte on CPINFOEX                                        //~v6BAI~
//*rc:-1:leadbyte not defined,1:leadbyte,0:not leadbyte            //~v6BAI~
//****************************************************************************************//~v6BAM~
int udbcschk_chkcpinfo(int Pcp,char Pch)                           //~v6BAI~
{                                                                  //~v6BAM~
	int rc=0,ii;                                                   //~v6BAI~
    CPINFOEX   info;                                               //~v6BAI~
    BYTE *pc;                                                      //~v6BAI~
//******************                                               //~v6BAM~
	if ((UINT)Pcp!=Scpinfo.CodePage)                               //~v6BAR~
		udbcschk_getcpinfo(0,Pcp,&info);                           //~v6BAI~
    if (Scpinfo.LeadByte[0])	//defined                          //~v6BAR~
    {                                                              //~v6BAI~
	    for (ii=0,pc=Scpinfo.LeadByte;ii<MAX_LEADBYTES;ii+=2,pc+=2)//~v6BAI~
    	{                                                          //~v6BAI~
        	if (!*pc)                                              //~v6BAI~
            	break;                                             //~v6BAI~
        	if (Pch>=*pc && Pch<=*(pc+1))                          //~v6BAI~
        	{                                                      //~v6BAI~
            	rc=1;                                              //~v6BAI~
            	break;                                             //~v6BAI~
        	}                                                      //~v6BAI~
    	}                                                          //~v6BAI~
    }                                                              //~v6BAI~
    else                                                           //~v6BAI~
    	rc=-1;                                                     //~v6BAI~
	UTRACEP("%s:cp=%d,ch=%02x,rc=%d\n",UTT,Pcp,Pch,rc);            //~v6BAI~
    return rc;                                                     //~v6BAM~
}//udbcschk_chkcpinfo                                              //~v6BAI~
//****************************************************************************************//~v6BAM~
//*ucs<-mb using current cp                                        //~v6BAM~
//*rc:1 if lead byte                                               //~v6BAM~
//****************************************************************************************//~v6BAM~
int udbcschk_isleadbyte(char Pch)                                  //~v6BAI~
{                                                                  //~v6BAM~
    int rc,opt,lasterr;                                            //~v6BAI~
    UWUCS uwucs;                                                   //~v6BAI~
    int cp;                                                        //~v6BAM~
    char mbs[2];                                                   //~v6BAI~
//******************                                               //~v6BAM~
	if (cp=Scodepage,!cp)                                          //~v6BAM~
    	cp=ugetcp();                                               //~v6BAM~
	rc=udbcschk_chkcpinfo(cp,Pch);                                 //~v6BAI~
    if (rc<0)	//no leadbyte defined on CPINFOEX                  //~v6BAI~
    {                                                              //~v6BAM~
    	opt=0;                                                     //~v6BAM~
    	uwucs=0;    //to chk update                                //~v6BAM~
        mbs[0]=Pch;                                                //~v6BAI~
    	ucvext_MB2WC(opt,(ULONG)cp,mbs,1,&uwucs,0/*pmblen*/,&lasterr);//~v6BAI~
    	if (lasterr==ERROR_NO_UNICODE_TRANSLATION   //1113         //~v6BAM~
    	&&  !uwucs) //no output                                    //~v6BAM~
        	rc=1;  //inmature                                      //~v6BAM~
        else                                                       //~v6BAI~
        	rc=0;                                                  //~v6BAI~
		UTRACEP("%s:cp=%d,ch=%02x,rc=%d,uwucs=%04x\n",UTT,cp,Pch,rc,uwucs);//~v6BAI~
    }                                                              //~v6BAI~
    return rc;                                                     //~v6BAM~
}//umbtowcW                                                        //~v6BAM~
//****************************************************************************************//~v6BAI~
//*ucs->mb using current cp                                        //~v6BAI~
//*Popt:UCVUCS_SETSUBCHRC                                          //~v6BAI~
//*rc:-1 if err else mblen                                         //~v6BAR~
//****************************************************************************************//~v6BAI~
int uwctombW(int Popt,UWUCS Pucs,char *Pmbs)                       //~v6BAR~
{                                                                  //~v6BAI~
    int rc,mblen=0,opt,rc2;                                        //~v6BAR~
	char wkmbs[MAX_MBCSLEN];                                       //~v6BAI~
    WUCS ucs2[2];    //                                            //~v6BAI~
    int utf16ctr;                                                  //~v6BAI~
    int cp;                                                        //~v6BAI~
//******************                                               //~v6BAI~
  if (Popt & UW2MWO_NOBESTFIT) //        0x01                      //~v6C5I~
  	opt=0;                                                         //~v6C5I~
  else                                                             //~v6C5I~
	opt=UCVUCS_BESTFIT/*to match with wctomb*/|UCVUCS_SETSUBCHRC/*to get errrepflag!=0*/;//~v6BAR~
  	if (Popt & UW2MWO_SUBCHRC)                                     //~v6C5I~
		opt|=UCVUCS_SETSUBCHRC; //*to get errrepflag!=0            //~v6C5I~
    UCS4_TO_UTF16(Pucs,ucs2,&utf16ctr);                            //~v6BAI~
    if (cp=Scodepage,!cp)                                          //~v6BAI~
    	cp=ugetcp();                                               //~v6BAI~
    rc2=ucvext_winucs2cp(opt,(ULONG)cp,ucs2,utf16ctr,wkmbs,(int)sizeof(wkmbs),&mblen);	//UCVEXTRC_SUBCH or GetLastError//~v6BAR~
    UTRACEP("%s:ucs=%04x,mblen=%d,rc2=%d,mb=%02x-%02x-%02x\n",UTT,Pucs,mblen,rc2,wkmbs[0],mblen>1?wkmbs[1]:0,mblen>2?wkmbs[2]:0);//~v6C5R~
    if (rc2)                                                       //~v6BAR~
    	rc=-1;                                                     //~v6BAM~
    else                                                           //~v6BAI~
    	rc=mblen;                                                  //~v6BAM~
    if (mblen)                                                     //~v6BAI~
    	memcpy(Pmbs,wkmbs,(size_t)mblen);                          //~v6BAI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6C5R~
    return rc;                                                     //~v6BAI~
}//uwctombW                                                        //~v6BAR~
//****************************************************************************************//~v6BAI~
//*ucs<-mb using current cp                                        //~v6BAI~
//*rc:-1 or mblen                                                  //~v6BAR~
//*(rc:-2 is not returned, mbrtowc can do it)                      //~v6BAI~
//****************************************************************************************//~v6BAI~
int umbtowcW(int Popt,char *Pmbs,int Pinplen,UWUCS *Ppucs)         //~v6BAR~
{                                                                  //~v6BAI~
    int rc=0,rc2,opt,lasterr;                                      //~v6BAR~
    UWUCS uwucs=0;                                                 //~v6BAR~
    int cp;                                                        //~v6BAI~
    int mblen;                                                     //~v6BAR~
//******************                                               //~v6BAI~
    if (!*Pmbs)   //same spec as mbtowc for null string            //~v6BAI~
    {                                                              //~v6BAI~
        *Ppucs=0;                                                  //~v6BAI~
        rc=0;                                                      //~v6BAI~
    }                                                              //~v6BAI~
    else                                                           //~v6BAI~
    {                                                              //~v6BAI~
        opt=0;                                                     //~v6BAR~
	    if (cp=Scodepage,!cp)                                      //~v6BAI~
    		cp=ugetcp();                                           //~v6BAI~
        uwucs=0;	//to chk update                                //~v6BAI~
        rc2=ucvext_MB2WC(opt,(ULONG)cp,Pmbs,Pinplen,&uwucs,&mblen,&lasterr);//rc=12:reverse err//~v6BAR~
        if (rc2)                                                   //~v6BAI~
            rc=-1;                                                 //~v6BAI~
        if (!rc)                                                   //~v6BAI~
            rc=mblen;                                              //~v6BAR~
        *Ppucs=uwucs;                                              //~v6BAI~
    UTRACEP("%s:rc2=%d,rc=%d,mblen=%d,uwucs=%04x\n",UTT,rc2,rc,mblen,uwucs);//~v6BAI~
    }                                                              //~v6BAI~
    return rc;                                                     //~v6BAI~
}//umbtowcW                                                        //~v6BAR~
//****************************************************************************************//~v6BQI~
//*translate localecode by console cp                              //~v6BQI~
//*rc:0 cv done,1:not done                                         //~v6BQI~
//****************************************************************************************//~v6BQI~
int udbcschk_lcbychcp(int Popt,char *Psrc,char *Ptgt,int Pbuffsz)  //~v6BQI~
{                                                                  //~v6BQI~
	int ctr,apiopt,srclen,lasterr;                                 //~v6BQI~
    WUCS wkucs[256];                                               //~v6BQI~
//******************                                               //~v6BQI~
	UTRACEP("%s:src=%s\n",UTT,Psrc);                               //~v6BQI~
	if (!(Gudbcschk_flag & UDBCSCHK_CONSCP))    //consoleCP==SYSTEM default//~v6BQR~
    	return 1;                                                  //~v6BQI~
    apiopt=MB_ERR_INVALID_CHARS;    //return err if invalid char;ERROR_NO_UNICODE_TRANSLATION:1113 with count=0//~v6BQI~
    srclen=(int)strlen(Psrc);                                      //~v6BQI~
	ctr=uMultiByteToWideChar(0,0/*converter*/,apiopt,Psrc,srclen,wkucs,sizeof(wkucs),&lasterr);//~v6BQI~
    if (ctr<=0)                                                    //~v6BQI~
    	return 1;                                                  //~v6BQI~
    apiopt=0;                                                      //~v6BQI~
	ctr=uWideCharToMultiByte(0,Scodepage,apiopt,wkucs,ctr,Ptgt,(size_t)Pbuffsz,0/*Pdefaultchars*/,0/*Ppdefaultused*/,&lasterr);//~v6BQR~
    if (ctr<=0)                                                    //~v6BQI~
    	return 1;                                                  //~v6BQI~
	UTRACEP("%s:cv done tgt=%s\n",UTT,Ptgt);                       //~v6BQI~
    return 0;                                                      //~v6BQI~
}//udbcschk_lcbychcp                                               //~v6BQI~
//****************************************************************************************//~v6WvI~
int udbcschk_getcp(void)                                           //~v6WvI~
{                                                                  //~v6WvI~
	return Scodepage;                                              //~v6WvI~
}//udbcschk_getcp                                                  //~v6WvI~
#endif  //W32                                                      //~v6BAI~
