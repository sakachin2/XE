//*CID://+v721R~:                             update#=  443;       //+v721R~
//**************************************************
//v721:201212 Drop -Nm option                                      //+v721I~
//v720:201211 (BUG)LNX Console;-Nm option did not work(DBCS chk is done)//~v720I~
//vbmk:180813 (XE)for test,try mk_wcwidth_cjk(ambiguous:Wide DBCS) for visibility chk. use /YJ option//~v6WvI~
//v6Wv:180807 (W32:Bug) console version on chcp=50221, utfcvf2l output string is over MACMBCSLEN by esc seq such as "Esc$B!)"//~v6WvI~
//v6Hk:170120 (BUG by 6G0) u-c1 is displayed as "A"(best fit) when noligatutre mode;apply 6G0 for only dbcs//~v6HkI~
//v6Da:160611 (LNX)on dirlist Non printable ucs was dispalyed as sbcs ucs//~v6DaI~
//v6BZ:160327 roundup width0 boundary to dbcsid=xx00 to avoid incresing testcase by change of UDBCSCHK_ISUCSWIDTH0//~v6BZI~
//v6BY:160326 not fixed width0 ucs boundary                        //~v6BYI~
//v6BQ:160314 (W32)for top menu lang name disply,translate sys codepage to console codepage//~v6BQI~
//v6BG:131217 udbcschk_localeisdbcs is not never called            //~v6BGI~
//v6BC:160306 W32:iswprint support BMP(ucs2) only                  //~v6BCI~
//v6BA:160303 W32:wcstombs and mbrtowc dose not support surrogate pair,use WIdeChar<-->Multibute api//~v6BAI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f5:120419 option to use ICU as B2M/M2B local converter         //~v6f3I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6btI~
//v6bt:120102 add "get ucsctr of ddfmt" for cmdline shrink-#2      //~v6btI~
//v6br:111229 (Bug)ucs padding id for l2f shrink case(display only)//~v69rI~
//v69b:100808 sbcsid overflow;fix of v69a; expand start point from 0x__30-->0x__21 for sbcsid//~v69bI~
//v69a:100808 sbcsid overflow;temporary(HHH) expand to 6800-->6c00; target is assigning from >0x__20//~v69aI~
//            current status by /c850 width0=6c00->6fe4(x1b remains),sbcs:0100-->6bed(x12 remains)//~v69aI~
//            Lnx reduce by chking wcwidth=-1,Win has no wcwidth and iswprint redule large number containing actualy printable//~v69aI~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v68d:100625 (BUG)confused UCS WIDTH0 and UC4                     //~v68dI~
//v682:100616 reduce width0 sbcs range of ucs map tbl(overflow at ub9)//~v682I~
//v66X:100614 (LNX)CN-EBCDIC(CP935) is 2 byte dbcs only but local may be 4 byte dbcs for under GB18030(ex.u-81-x81308131)//~v66XI~
//v66D:100604 indicate not by outchar but by rc that SUBCHAR was set//~v66DI~
//v66n:100529 (LNX:BUG)m2b set errrep(no need to chk unprintable at ucs level but ebc level,more printable)//~v660I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v650:100121 print width=0                                        //~v650I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v638:091117 (UTF8)skip setlocale errmsg for other than xe        //~v638I~
//v637:091117 (UTF8:BUG)on console,safe to mot use dbcs mode       //~v637I~
//v636:091117 (UTF8)utf8 errchar write back original code          //~v636I~
//v62X:091107_compchkm                                             //~v62XI~
//v62W:091103_(BUG)setlocale fail when env has utf8 only. accept as no dbcs env.//~v62WI~
//            eg) At Ubuntu910 installed by lang=English, "locale -a" shows "en_US.UTF8" only, there is no "en_US"//~v62WI~
//v62V:091102_a2a GB180 & EUC consideration                        //~v62VI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62M:091013_(LNX:BUG)It should back to original locale after setup unprintable//~v62MI~
//v62G:091005_(BUG)for isprint func;utfcvu2lany1mb is always success. isprint should be used//~v62GI~
//                 but for isprint setlocale should be issued for -Cparameter. v62F is now meaningless.//~v62GI~
//v62w:091002_(WIN:BUG)on C(J)K console,kbd input is utf8,but usaly do by locale mode//~v62wI~
//v62u:091011_(WIN:BUG) displayed default locale on top menu is not of dosprompt codepage setting//~v62uI~
//v62p:090916!add udbcschk_pos2offs                                //~v62pI~
//v627:090719 use setlocale when not UTF8(avoid dup req,reissue of setlocale(,"") reset to default locale)//~v627I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            force utf8->locale option(gnome:utf8,env:locale case)//~v620I~
//            for CJK and LANG=..UTF8, wctomb/mbtowc-->iconv/WinAPI//~v620I~
//            "/" after utf8 was detected as dbcs 2nd byte         //~v620I~
//v5nv:081108 udbcschk may called before wcinit                    //~v5nvI~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8R~
//v5n5:080907 GB18030(CP-54936) Windows CPinfo has no defined leadbyte//~v5n5I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v61q:080126 (UTF)option to ignore dbcs other than euc for not utf8 support version//~v61qI~
//v61b:071205 (UTF:LNX)support locale other than EUC               //~v61bI~
//v61f:071126 (LNX)hankana(e8+xx) kbd input chk                    //~v61fI~
//v614:071117 (UTF)EUC<->UTF8 conversion support                   //~v614I~
//v60e:071017 (UTF)add utfcve2f(euc to utf8)                       //~v60eI~
//v60a:070928 (UTF:WXE)                                            //~v60aI~
//v600:070717 sync by precompile with no /DUTF8SUPP option and xfc tool//~v600I~
//v5i9:060601 (LNX:FC5)support UTF8 for other than japanese        //~v5i9I~
//v5i7:060601 (LNX:FC5)utf8 not yet supported but set no EUC flag but set utf8 flag//~v5i7I~
//v57p:030118 (AIX)display all ms932 char                          //~v57pI~
//v57e:021228 sjis-->jis conv support                              //~v57eI~
//v57d:021228 sjis<->euc conv contline support                     //~v57dI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v560:020619 jis decoding support                                 //~v560I~
//v551:020413 kana hankaku-->zenkaku conv only(no dbcs conv)       //~v551I~
//v550:020413 string len change by euc<->sjis conv;consider for tabid on dbcstbl//~v550I~
//v513:011211 dbcs combination chk for AIX                         //~v513I~
//v511:011208 (BUG)no clear should be for tab only                 //~v511I~
//v50Y:011202 no clear option of ueucchk                           //~v50YI~
//v40v:010122 AIX support:sjis chk(allow up to 2nd level kanji)    //~v40vI~
//v39H:010120 LINUX support:drop undefined from jis range          //~v39HI~
//v39F:010114 LINUX support:under kon,set unprintable when sbcs>=0x80 for screen stability//~v39FI~
//v39D:010114 LINUX support:dbcs err chk to avoid screen destroy unker kon//~v39DI~
//v39C:010114 LINUX support:rtn to clear dbcs tbl for force english even if euc//~v39CI~
//v39z:010113 LINUX support:dbcschk by euc code                    //~v39zI~
//v39x:010113 LINUX support:euc conversion(from jconv by  Ken R. Lunde)//~v39xI~
//v39k:001202 LINUX support:ujis chk for unprintable char          //~v198I~
//v198:980926 parm may better be uusigned int for sjis to jis conv func//~v198I~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v051:961204:dbcs 2nd byte chk function                           //~v050I~
//v024:960831:udbcschk return dbcs env if parm is 0                //~v024I~
//**************************************************               //~v39kR~
#ifdef UDBCSCHK_GBLDEF                                             //~v39kR~
    int Gudbcschk_flag;                                            //~v39kR~
  	int Gudbcschk_width0top; //start of width0 sbcsid              //~v6BYR~
#else                                                              //~v39kR~
    extern int Gudbcschk_flag;                                     //~v39kR~
  	extern int Gudbcschk_width0top;                                //~v6BYI~
    extern UCHAR *Gpdbcstbl;                                       //~v5n8I~
#ifndef UTF8SUPPH                                                  //~v62XI~
  #ifdef LNX                                                       //~v62UR~//~v62XR~
    extern UCHAR *Gplocaledbcstbl;   //for UTF8 base               //~v62UR~//~v62XR~
  #endif                                                           //~v62UR~//~v62XR~
#endif                                                             //~v62XI~
#endif                                                             //~v39kR~
#define UDBCSCHK_TYPEDBCS     0x01     //DBCS Lead byte            //~v5n8I~
#define UDBCSCHK_TYPEUNP      0x02     //unprintable ascii(00->7f) //~v5n8I~
#define UDBCSCHK_TYPESS3      0x04     //EUC SS3 prefix(0x8f)      //~v5ntI~
//#define UDBCSCHK_MBLEN(Sdbcscbl,ch)    ((Sdbcscbl[(int)(unsigned char)(ch)]) & UDBCSCHK_TYPEDBCS ? 2:1)//~v62UR~
#define UDBCSCHK_ISPRINT(ch)    ((Gpdbcstbl[(int)(unsigned char)(ch)]) & UDBCSCHK_TYPEUNP ? 0:1)//~v62UR~
#define UDBCSCHK_ISDBCS1ST(ch)    ((Gpdbcstbl[(int)(unsigned char)(ch)]) & UDBCSCHK_TYPEDBCS ? 1:0)//~v62UR~
#define UDBCSCHK_IS_LEADBYTE(pdbcstb,ch)   ((pdbcstb[(int)(unsigned char)(ch)]) & UDBCSCHK_TYPEDBCS ? 1:0)//~v6btI~
#define UDBCSCHK_ISGB42ND(ch) ( ((ch)>='0') && ((ch)<='9') )       //~v62UR~
#define UDBCSCHK_ISGB42NDENV(ch) ( \
						 		     (UDBCSCHK_ISGB4ENV()) \
								 &&  (UDBCSCHK_ISGB42ND(ch)) \
                                 )                                 //~v62UR~
#define UDBCSCHK_ISGB4(pc)  (       UDBCSCHK_ISDBCS1ST(*(pc)) \
                                 && UDBCSCHK_ISGB42ND(*((pc)+1)) \
                                 && UDBCSCHK_ISDBCS1ST(*((pc)+2)) \
                                 && UDBCSCHK_ISGB42ND(*((pc)+3)) \
                            ) //(0x81-0xfe)+(0x30-0x39)+(0x81-0xfe)+(0x30-0x39)//~v62UR~
#define UDBCSCHK_ISGB4STR(pc,len)  (((len)>=4) \
						 		    && (UDBCSCHK_ISGB4ENV()) \
                                    && (UDBCSCHK_ISGB4(pc)) \
                                   )                               //~v62UR~
#define UDBCSCHK_ISGB41STHALF(pc,len)  (((len)>=2) /*gb4 1st half 2 byte*/ \
						 		    && UDBCSCHK_ISGB4ENV() \
                                    && UDBCSCHK_ISDBCS1ST(*(pc)) \
                                    && UDBCSCHK_ISGB42ND(*((pc)+1)) \
                                   )                               //~v62UR~
                                                                   //~v5n8I~
#define UDBCSCHK_EUC       0x01                                    //~v39zR~
#define UDBCSCHK_MS932     0x02     //full ms932 display           //~v57pI~
#define UDBCSCHK_UTF8      0x04     //utf-8 for linux              //~v600R~
//#ifdef UTF8SUPP                                                  //~v5n0R~
//#ifdef WCSUPP                                                    //~v5n8R~
#define UDBCSCHK_UTF8J     0x08     //utf-8 of japanese for linux  //~v600R~
#define UDBCSCHK_UTF8E     0x10     //utf-8 of other than ja_JP for linux//~v600R~
//#endif                                                           //~v5n8R~
#ifdef WCSUPP                                                      //~v5mQI~
#define UDBCSCHK_DBCSLANG  0x20     //local lang has dbcs          //~v61bR~
#ifdef LNX                                                         //~v62UR~
	#define  UDBCSCHK_DBCSCVEXT()   (Gudbcschk_flag & UDBCSCHK_DBCSLANG)//~v62UR~
#else                                                              //~v62UR~
//  #define  UDBCSCHK_DBCSCVEXT()   UDBCSCHK_ISWCDBCS()            //~v62UR~
	#define  UDBCSCHK_DBCSCVEXT()   (Gudbcschk_flag & UDBCSCHK_DBCSLANG)//~v62UR~
#endif                                                             //~v62UR~
#endif                                                             //~v600I~
//#define UDBCSCHK_NODBCS    0x40     //no dbcs mode other than EUC//~v5n8R~
#ifdef WCSUPP                                                      //~v5mQI~
    #define  UDBCSCHK_USEICU     0x0100  //Windows version use icu for EBCSDIC translation//~v5mQR~
	#define  UDBCSCHK_ISICU()    (Gudbcschk_flag & UDBCSCHK_USEICU)//~v5mQI~
	#define  UDBCSCHK_SETUSEICU()  Gudbcschk_flag|=UDBCSCHK_USEICU //~v5mQI~
#endif                                                             //~v5n8M~
	#define  UDBCSCHK_WCDBCS     0x0200  //kbd and scr I/O by unicode//~v5n8R~
	#define  UDBCSCHK_UTF8CJK    0x0400  //LANG is UTF8,default locale is CJK DBCS//~v5n8R~
	#define  UDBCSCHK_DBCSJ      0x0800  //LANG is EUC or SJIS     //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
	#define  UDBCSCHK_CONSCP     0x1000  //ConsoleCP is not same as SYSTEM DEFAULT CP//~v5n8R~
	#define  UDBCSCHK_UTF8VER    0x2000  //UTF8 version xe  UTF8SUPP but not UTF8SUPPH//~v62MR~
	#define  UDBCSCHK_ISUTF8VERSION() (Gudbcschk_flag & UDBCSCHK_UTF8VER)//~v5n8I~
	#define  UDBCSCHK_ISWCDBCS() (Gudbcschk_flag & UDBCSCHK_WCDBCS)//~v5mQR~
#endif                                                             //~v5ntI~
	#define  UDBCSCHK_BEFOREINIT 0x4000  //wait until wcinit       //~v5nvI~
#ifdef WCSUPP                                                      //~v5ntI~
	#define  UDBCSCHK_FORCENONJ  0x8000  //Japanese reset by -C option//~v5nvI~
	#define  UDBCSCHK_FORCEUCJ 0x010000  //force EUC-JP by -C option//~v5nvI~//~v5ntR~
	#define  UDBCSCHK_WINUTF8  0x020000  //windows kbd input by wide api//~v62wI~
	#define  UDBCSCHK_UNPTBL   0x040000  //SBCS unprintable table was set//~v62GI~
	#define  UDBCSCHK_LANGEUC  0x080000  //EUC,JP/KR etc           //~v62UR~
	#define  UDBCSCHK_LANGMB4  0x100000  //4 byte DBCS lang(GB18030)//~v62UR~
	#define  UDBCSCHK_ISGB4ENV() (Gudbcschk_flag & UDBCSCHK_LANGMB4)//~v62UR~
	#define  UDBCSCHK_LANGUTF8 0x200000  //setlocale failed to locale code because missing other than UTF8//~v62WI~
	#define  UDBCSCHK_TTYCONS  0x400000  //on console(tty)         //~v637I~
	#define  UDBCSCHK_EXPLICIT 0x800000  //not internal setup req  //~v638I~
#endif                                                             //~v5n8I~
#ifdef UTF8EBCD                                                    //~v660I~//~v65cI~
	#define  UDBCSCHK_EXTDBCS  0x01000000  //External converter support DBCS//~v65cI~
	#define  UDBCSCHK_ISDBCSCV()    (Gudbcschk_flag & UDBCSCHK_EXTDBCS)//~v65cI~
	#define  UDBCSCHK_SETDBCSCV()    Gudbcschk_flag|=UDBCSCHK_EXTDBCS//~v65cI~
#endif                                                             //~v660I~//~v65cI~
//  #define  UDBCSCHK_ISDBCS()  (Gudbcschk_flag & (UDBCSCHK_WCDBCS|UDBCSCHK_DBCSJ))//native J(SJIS/EUC) or CJK//~v62UR~
    #define  UDBCSCHK_ISDBCS()  (Gudbcschk_flag & UDBCSCHK_DBCSLANG)//~v62UR~
	#define  UDBCSCHK_ISDBCSJ()  (Gudbcschk_flag & (UDBCSCHK_DBCSJ|UDBCSCHK_UTF8J))//native J(SJIS/EUC) or UTF8J//~v5ntI~
	#define  UDBCSCHK_ISDBCSJ_LOCAL()  (Gudbcschk_flag & (UDBCSCHK_DBCSJ))//native J(SJIS/EUC)//~v620I~
#ifdef LNX                                                         //~v5ntI~
	#define  UDBCSCHK_ISEUCJ()   (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J|UDBCSCHK_FORCEUCJ))//native J(SJIS/EUC) or UTF8J or force by -CEUC-JP//~v5nvI~//~v5ntR~
#endif                                                             //~v5ntI~
	#define  UDBCSCHK_LOCALICU   0x02000000  //use ICU for LOCAL converter//~v6f3R~
	#define  UDBCSCHK_IS_LOCALICU() (Gudbcschk_flag & UDBCSCHK_LOCALICU)//~v6f3R~
//  #define  UDBCSCHK_KBDNOUTF8  0x04000000  //-Nm option on UTF8 env//~v720R~//+v721R~
                                                                   //~v6f3R~
#ifdef WCSUPP                                                      //~v5n8I~
                                                                   //~v5n8I~
	#define  WCMB1ST(A) (UDBCSCHK_ISWCDBCS()? udbcschk(A) : 0)     //~v5n8I~
	#ifdef LNX                                                     //~v5n8I~
		#define  WCMB1ST_J(A) (UDBCSCHK_ISWCDBCS()? udbcschk((unsigned char)(A)) : ISEUC((A)))//~v5n8I~
		#define  WCMB1ST_HK(Popt,A) (UDBCSCHK_ISWCDBCS()? udbcschk_hk(Popt,(unsigned char)(A)) : ISEUC((A)))//~v5n8I~
		#define  WCMB2ND(Popt,P2nd) (UDBCSCHK_ISWCDBCS()? udbcschk_mb2nd(Popt,0,(P2nd)-1) : ISEUC(*(P2nd)))//~v5n8I~
    #else                                                          //~v5n8I~
		#define  WCMB1ST_J(A) (UDBCSCHK_ISWCDBCS()? udbcschk((unsigned char)(A)) : SJIS1((A)))//~v5n8I~
		#define  WCMB1ST_HK(Popt,A) (UDBCSCHK_ISWCDBCS()? udbcschk_hk(Popt,(unsigned char)(A)) : SJIS1((A)))//~v5n8I~
		#define  WCMB2ND(Popt,P2nd) (UDBCSCHK_ISWCDBCS()? udbcschk_mb2nd(Popt,0,(P2nd)-1) : SJIS2(*(P2nd)))//~v5n8I~
    #endif                                                         //~v5n8I~
#else                                                              //~v5n8I~
	#define  WCMB1ST(A)         0                                  //~v5n8I~
	#ifdef LNX                                                     //~v5n8I~
		#define  WCMB1ST_J(A)         ISEUC((A))                   //~v5n8I~
		#define  WCMB1ST_HK(A)        ISEUC((A))                   //~v5n8I~
    #else                                                          //~v5n8I~
		#define  WCMB1ST_J(A)         SJIS1((A))                   //~v5n8I~
		#define  WCMB1ST_HK(A)        SJIS1((A))                   //~v5n8I~
    #endif                                                         //~v5n8I~
	#define  WCMB2ND(Popt,P2nd)       SJIS2(*(P2nd))               //~v5n8R~
#endif                                                             //~v5mQI~
                                                                   //~v5i9I~
#define UDBCSCHK_ISUTF8()  (Gudbcschk_flag & UDBCSCHK_UTF8)        //~v5i9R~
#define UDBCSCHK_ISUTF8J() (Gudbcschk_flag & UDBCSCHK_UTF8J)       //~v5i9R~
#define UDBCSCHK_ISUTF8E() (Gudbcschk_flag & UDBCSCHK_UTF8E)       //~v5i9R~
                                                                   //~v39xI~
#define SS2         0x8e					//hankaku katakana escape code//~v39xI~
#define SS3         0x8f					//2 byte dbcs 0x8f+xxyy(2nd level kanji)//~v5ntI~
#define MAYBESS3(A)    ((A)==SS3)		//no envchk                //~v62VI~
#define ISSS3(A)    ((A)==SS3 && (Gudbcschk_flag & UDBCSCHK_LANGEUC))//~v62UR~
#define ISSS3STR(pc,len)  (  /*3 byte EUC SS3 str*/   \
						 ISSS3(*(pc))                  \
                      && (len)>=3                      \
                      && UDBCSCHK_ISDBCS1ST(*((pc)+1)) \
                      && UDBCSCHK_ISDBCS1ST(*((pc)+2)) \
                      )                                            //~v62UR~
#define ISSS2(A)    ((A)==SS2 && (Gudbcschk_flag & UDBCSCHK_LANGEUC))//~v62UR~
#define HANKATA(A)  (A >=0xa1 && A <=0xdf)  //hankaku katakana range//~v39xI~
#define ISEUC(A)    (A >=0xa1 && A <=0xfe)                         //~v39xI~
#define SJIS1(A)    ((A >=0x81 && A <=0x9f) || (A >=0xe0 && A <=0xfc))//sjis 1st byte//~v39xI~
#define SJIS2(A)    (A >=0x40 && A <=0xfc)   //sjis 2nd byte       //~v39xI~
#define SJIS88START 0x9f                                           //~v39HI~
#define SJISX208(A) ((A >=0x8140 && A <=0x84fc) \
                   ||(A >=0x889f && A <=0x9ffc) \
                   ||(A >=0xe040 && A <=0xeafc))//JIS X 208        //~v39HI~
#define JIS1(A)     ((A >=0x21 && A <=0x28) || (A >=0x30 && A <=0x74)) //JIS X 208//~v39HI~
#define JIS2(A)     (A >=0x21 && A <=0x7e) //JIS X 208             //~v39HI~
//#define UDBCSCHK_DBCS2ND_MIN  0x40   //dbcs 2nd is upper of 0x40 //~v62UR~
#define UDBCSCHK_DBCS2ND_ENDMIN 0x40   //min value for *dbcst='2'(for GB18030 ,end of string is 'd' width data '0'->'9'//~v62UR~
#define UDBCSCHK_DBCS2ND_MIN() \
						(UDBCSCHK_ISGB4ENV() ? 0x30 : 0x40)  //dbcs 2nd byte minimum//~v62UR~
                                                                   //~v620I~
#define UDBCSCHK_DBCS1ST     '1'     //on dbcs tbl                 //~v39xI~
#define UDBCSCHK_DBCS2ND     '2'     //on dbcs tbl                 //~v39xI~
#define UDBCSCHK_DBCSPAD     'd'     //dbcs padding  for for GB4 1dd2//~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
#define UDBCSCHK_TABCHAR    0x09     //tab char                    //~v640I~
#define UDBCSCHK_TABPADCHAR  '3'                                   //~v640I~
#define UC_DBCSSPACE    0x3000 //dbcs space by unicode             //~v640I~
#endif                                                             //~v640I~
#define UDBCSCHK_DBCSIDSTRGB4  {UDBCSCHK_DBCS1ST,UDBCSCHK_DBCSPAD,UDBCSCHK_DBCSPAD,UDBCSCHK_DBCS2ND}//~v62UR~
#define UDBCSCHK_DBCSIDSTRSS3  {UDBCSCHK_DBCS1ST,UDBCSCHK_DBCSPAD,UDBCSCHK_DBCS2ND}//~v62UR~
#define UDBCSCHK_DBCSIDSTR     {UDBCSCHK_DBCS1ST,UDBCSCHK_DBCS2ND} //~v62UR~
                                                                   //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
	#define UDBCSCHK_UCSIDS     0x21      //calls DDucs fmt        //~v640R~
	#define UDBCSCHK_NPUCS1     0x21   //"!" width<=0  ucs upper   //~v640I~
	#define UDBCSCHK_NPUCS2     0x22   //""" width<=0  ucs lower   //~v640I~
	#define UDBCSCHK_WSBCSUCS1  0x23   //"#" sbcs of wcwidth=2 upper//~v640I~
	#define UDBCSCHK_WSBCSUCS2  0x24   //"$" sbcs of wcwidth=2 lower//~v640I~
	#define UDBCSCHK_NDBCSUCS1  0x25   //"%" sbcs of wcwidth=2 upper//~v640R~
	#define UDBCSCHK_NDBCSUCS2  0x26   //"&" sbcs of wcwidth=2 lower//~v640R~
	#define UDBCSCHK_DBCS1STUCS 0x28   //"("calls DDucs fmt        //~v640I~
	#define UDBCSCHK_DBCS2NDUCS 0x29   //')'                       //~v640I~
	#define UDBCSCHK_ERRREPCH_NPUCS      ':'      //unplitable char rep by tabdisplay//~v6DaI~
	#define UDBCSCHK_ERRREPCH_NPUCSW     ';'                       //~v6DaI~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS1STOVF 0x2a   // dummy for switch statement//~v65cI~
	#define UDBCSCHK_DBCS2NDOVF 0x2b   // dummy for switch statement//~v65cI~
#endif                                                             //~v65cI~
	#define UDBCSCHK_PADDINGID  UDBCSCHK_DBCSPAD // "d" padding ucs for ddfmt//~v69rR~
	#define UDBCSCHK_PADDINGCH  ' '                                //~v69rI~
	                                   //remains "'",  "*"         //~v640R~
	#define UDBCSCHK_UCSIDE     0x2f   //calls DDucs fmt           //~v640R~
	#define UDBCSCHK_SBCSUCSID  0x80  //1000-0000 0000-0000 max 4fff current about 40e9//~v650R~
#ifdef WWW    //width0 if >=Gudbcschk_width0top                    //~v6BYM~
#else                                                              //~v6BYM~
//  #define UDBCSCHK_SBCSUCSID_END    (UDBCSCHK_UCS4MASK-1) //0xef, 1110.xxxx, 1111.xxxx is for ucs4//~v6BYI~//~v6BZR~
#endif  //WWW                                                      //~v6BYM~
//  #define UDBCSCHK_SBCSIDMASK 0xf0  //1111-0000                  //~v650R~//~v68dR~
    #define UDBCSCHK_SBCSIDMASK 0xf8  //1111-1000  start of width 0 sbcsid is e8,fx is ucs4//~v68dI~
//	#define UDBCSCHK_WIDTH0ID   0xe0  //1110-yyyy zzzz-zzzz downword from max 6fff//~v682R~
#ifdef WWW    //width0 if >=Gudbcschk_width0top                    //~v6BYI~
  	#define UDBCSCHK_WIDTH0ID   0xe8  //sbcsid for width0 >=6800   //~v682R~
#else                                                              //~v6BZI~
  	#define UDBCSCHK_WIDTH0ID   ((char)((Gudbcschk_width0top>>8)|UDBCSCHK_SBCSUCSID))  //sbcsid for width0//~v6BZR~
#endif  //WWW                                                      //~v6BYI~
  	#define UDBCSCHK_SBCSIDWRAP 0x21  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~
//#ifdef LNX  //HHH                                                  //~v69aR~//~v69bR~
#ifdef WWW        //not fixed width0 start ,replace to Global variable//~v6BYI~
  	#define UDBCSCHK_WIDTH0TOP  0x6800//sbcsid for width0          //~v69aI~
#endif //WWW                                                       //~v6BYI~
//#else                                                              //~v69aI~//~v69bR~
//    #define UDBCSCHK_WIDTH0TOP  0x6c00//sbcsid for width0          //~v69aR~//~v69bR~
//    #define UDBCSCHK_WIDTH0IDM2 0x04  //sbcsid for width0 >=6c00   //~v69aM~//~v69bR~
//#endif                                                             //~v69aR~//~v69bR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_UCS4MASK   0xf8  //1111-1000                  //~v65cI~
	#define UDBCSCHK_UCS4       0xf0  //ucs over 0x0002.0000 or sbcsid overflow//~v65cR~
	#define UDBCSCHK_UCS41      0xf0  //1111-00pq yyyy-yyyy   1 0    f    f    f    f      //ucs4//~v65cI~
	#define UDBCSCHK_UCS42      0xf8  //1111-1rrr zzzz-zzzz   p qrrr yyyy-yyyy zzzz-zzzz//~v65cR~
	#define UDBCSCHK_UCS4MASK1  0x03  //for pq                     //~v65cI~
	#define UDBCSCHK_UCS4MASK2  0x07  //for rrr                    //~v65cI~
//  #define UDBCSCHK_ISOVF(dbcsid) (((dbcsid)&UDBCSCHK_SBCSIDMASK)==UDBCSCHK_UCS4)//~v65cI~//~v68dR~
    #define UDBCSCHK_ISOVF(dbcsid) (((dbcsid)&UDBCSCHK_UCS4)==UDBCSCHK_UCS4)  //f0(1st) or f8(2nd)//~v68dI~
    #define UDBCSCHK_ISUCSOVF1ST(dbcsid) (((dbcsid)&UDBCSCHK_UCS4MASK)==UDBCSCHK_UCS41)//~v65cR~
    #define UDBCSCHK_ISUCSOVF2ND(dbcsid) (((dbcsid)&UDBCSCHK_UCS4MASK)==UDBCSCHK_UCS42)//~v65cR~
    #define UDBCSCHK_TEMPDBCSID(dbcsid) (UDBCSCHK_ISUCSOVF1ST(dbcsid) \
                                          ? UDBCSCHK_DBCS1STOVF       \
                                          : (UDBCSCHK_ISUCSOVF2ND(dbcsid) \
                                             ? UDBCSCHK_DBCS2NDOVF     \
                                             : dbcsid                  \
                                            )                          \
                                        )                          //~v65cI~
#endif                                                             //~v65cI~
                                                                   //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS1STUCS_CASE() \
		     UDBCSCHK_DBCS1STUCS:      \
		case UDBCSCHK_NPUCS1:          \
		case UDBCSCHK_NDBCSUCS1:       \
		case UDBCSCHK_WSBCSUCS1:       \
		case UDBCSCHK_DBCS1STOVF                                   //~v65cI~
                                                                   //~v65cI~
	#define UDBCSCHK_DBCS2NDUCS_CASE() \
		     UDBCSCHK_DBCS2NDUCS:      \
		case UDBCSCHK_NPUCS2:          \
		case UDBCSCHK_NDBCSUCS2:       \
		case UDBCSCHK_WSBCSUCS2:       \
		case UDBCSCHK_DBCS2NDOVF                                   //~v65cI~
#else                                                              //~v65cI~
	#define UDBCSCHK_DBCS1STUCS_CASE() \
		     UDBCSCHK_DBCS1STUCS:      \
		case UDBCSCHK_NPUCS1:          \
		case UDBCSCHK_NDBCSUCS1:       \
		case UDBCSCHK_WSBCSUCS1                                    //~v640I~
    			                                                   //~v640I~
	#define UDBCSCHK_DBCS2NDUCS_CASE() \
		     UDBCSCHK_DBCS2NDUCS:      \
		case UDBCSCHK_NPUCS2:          \
		case UDBCSCHK_NDBCSUCS2:       \
		case UDBCSCHK_WSBCSUCS2                                    //~v640I~
#endif                                                             //~v65cI~
                                                                   //~v640I~
	#define UDBCSCHK_DBCS1STUCS2(dbcsid) \
    	          	  ((dbcsid)==UDBCSCHK_DBCS1STUCS) /*dbcs ucs2 1st*///~v640R~
	#define UDBCSCHK_DBCS2NDUCS2(dbcsid) \
    	          	  ((dbcsid)==UDBCSCHK_DBCS2NDUCS) /*dbcs ucs2 1st*///~v640R~
	#define UDBCSCHK_ISUCSNP1ST(dbcsid) \
    	          	  ((dbcsid)==UDBCSCHK_NPUCS1)                  //~v640R~
	#define UDBCSCHK_ISUCSNP2ND(dbcsid) \
    	          	  ((dbcsid)==UDBCSCHK_NPUCS2)                  //~v640R~
	#define UDBCSCHK_ISUCSNP(dbcsid) \
					(  UDBCSCHK_ISUCSNP1ST(dbcsid) \
					 ||UDBCSCHK_ISUCSNP2ND(dbcsid) \
                    )                                              //~v640I~
	#define UDBCSCHK_ISUCS_DBCS1STN(dbcsid) /*narrow dbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_NDBCSUCS1)               //~v640R~
	#define UDBCSCHK_ISUCS_DBCS1STW(dbcsid) /*narrow dbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_WSBCSUCS1)               //~v640R~
	#define UDBCSCHK_ISUCS_DBCS2NDN(dbcsid) /*narrow dbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_NDBCSUCS2)               //~v640I~
	#define UDBCSCHK_ISUCS_DBCS2NDW(dbcsid) /*narrow dbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_WSBCSUCS2)               //~v640I~
	#define UDBCSCHK_DBCS1STUCS2NW(dbcsid) \
						( UDBCSCHK_DBCS1STUCS2(dbcsid) /*wide dbcs*/ \
						||UDBCSCHK_ISUCS_DBCS1STN(dbcsid) /*narrow*/   \
						||UDBCSCHK_ISUCS_DBCS1STW(dbcsid) /*wide sbcs*/\
                        )                                          //~v640I~
	#define UDBCSCHK_DBCS1STUCS2NWP(dbcsid) \
						( UDBCSCHK_DBCS1STUCS2NW(dbcsid)  \
						||UDBCSCHK_ISUCSNP1ST(dbcsid) /*not printable*/\
                        )                                          //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cR~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS1STUCS2NWO(dbcsid) \
						( UDBCSCHK_DBCS1STUCS2NW(dbcsid)  \
						||UDBCSCHK_ISUCSOVF1ST(dbcsid) /*ucs4*/\
                        )                                          //~v65cI~
	#define UDBCSCHK_DBCS1STUCS2NWPO(dbcsid) \
						( UDBCSCHK_DBCS1STUCS2NWP(dbcsid)  \
						||UDBCSCHK_ISUCSOVF1ST(dbcsid) /*ucs4*/\
                        )                                          //~v65cI~
#endif                                                             //~v65cI~
	#define UDBCSCHK_ISUCSDBCS2NDN(dbcsid) /*narrow dbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_NDBCSUCS2)               //~v640R~
	#define UDBCSCHK_ISUCSDBCS2NDW(pdbcs) /*wide sbcs*/ \
    	          	  ((dbcsid)==UDBCSCHK_WSBCSUCS2)               //~v640R~
	#define UDBCSCHK_DBCS2NDUCS2NW(dbcsid) \
						( UDBCSCHK_DBCS2NDUCS2(dbcsid) /*wide dbcs*/ \
						||UDBCSCHK_ISUCS_DBCS2NDN(dbcsid) /*narrow*/   \
						||UDBCSCHK_ISUCS_DBCS2NDW(dbcsid) /*wide sbcs*/\
                        )                                          //~v640I~
	#define UDBCSCHK_DBCS2NDUCS2NWP(dbcsid) \
						( UDBCSCHK_DBCS2NDUCS2NW(dbcsid)  \
						||UDBCSCHK_ISUCSNP2ND(dbcsid) /*not printable*/\
                        )                                          //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS2NDUCS2NWO(dbcsid) \
						( UDBCSCHK_DBCS2NDUCS2NW(dbcsid)  \
						||UDBCSCHK_ISUCSOVF2ND(dbcsid) /*ucs4*/\
                        )                                          //~v65cI~
	#define UDBCSCHK_DBCS2NDUCS2NWPO(dbcsid) \
						( UDBCSCHK_DBCS2NDUCS2NWP(dbcsid)  \
						||UDBCSCHK_ISUCSOVF2ND(dbcsid) /*ucs4*/\
                        )                                          //~v65cI~
	#define UDBCSCHK_ISUCS2SBCS(dbcsid) \
    	         ((dbcsid) & UDBCSCHK_SBCSUCSID)                   //~v65cI~
	#define UDBCSCHK_ISUCSSBCS(dbcsid) \
    	       (     UDBCSCHK_ISUCS2SBCS(dbcsid) \
                 && !UDBCSCHK_ISOVF(dbcsid)      \
               )                                                   //~v65cI~
#else                                                              //~v65cI~
	#define UDBCSCHK_ISUCSSBCS(dbcsid) \
    	         ((dbcsid) & UDBCSCHK_SBCSUCSID)                   //~v640R~
#endif                                                             //~v65cI~
//#ifdef LNX //HHH                                                   //~v69aR~//~v69bR~
#ifdef WWW                                                         //~v6BYI~
	#define UDBCSCHK_ISUCSWIDTH0(dbcsid) \
      	         (((dbcsid) & UDBCSCHK_SBCSIDMASK)==UDBCSCHK_WIDTH0ID)  //&f8==xe8//~v68dR~
#else                                                              //~v6BYI~
//    #define UDBCSCHK_ISUCSWIDTH0(dbcsid)                         //~v6BZR~
//                 (  ((dbcsid) & UDBCSCHK_SBCSIDMASK)>=UDBCSCHK_SBCSUCSID//~v6BZR~
//                 && ((dbcsid) & UDBCSCHK_SBCSIDMASK)<=UDBCSCHK_SBCSUCSID_END//~v6BZR~
//                 ) //80xx to efff, f0xx is ucs41                 //~v6BYR~
    #define UDBCSCHK_ISUCSWIDTH0(dbcsid) \
                 (  ((dbcsid) >= UDBCSCHK_WIDTH0ID) /*Gudbcschk_width0top>>8*/ \
                 && ((dbcsid) < UDBCSCHK_UCS41)     /*0xf0*/                  \
                 )                                                 //~v6BZI~
#endif                                                             //~v6BYI~
//#else                                                              //~v69aR~//~v69bR~
//    #define UDBCSCHK_ISUCSWIDTH0(dbcsid)                         //~v69bR~
//             (                                                   //~v69bR~
//                 (((dbcsid) & UDBCSCHK_SBCSIDMASK)==UDBCSCHK_WIDTH0ID)  /*&f8==xe8*///~v69bR~
//             &&                                                  //~v69bR~
//                 ((dbcsid) & UDBCSCHK_WIDTH0IDM2)   /*0xec*/     //~v69bR~
//             )                                                     //~v69aR~//~v69bR~
//#endif                                                             //~v69aR~//~v69bR~
//    	         (((dbcsid) & UDBCSCHK_WIDTH0ID)==UDBCSCHK_WIDTH0ID)//~v68dI~
//  	         (((dbcsid) & UDBCSCHK_SBCSIDMASK)==UDBCSCHK_WIDTH0ID)//~v682R~
	#define UDBCSCHK_ISUCSSBCSER(dbcsid) /*sbcs and err byte*/\
				(UDBCSCHK_ISUCSSBCS(dbcsid) \
    	         ||((dbcsid)==UDBCSCHK_F2LERR) \
                )                                                  //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_ISUCS2DBCS(dbcsid) /*ucs dbcs(except ucs sbcs)*/\
    		(\
              (((dbcsid)>=UDBCSCHK_UCSIDS) && ((dbcsid)<=UDBCSCHK_UCSIDE))\
            )                                                      //~v65cI~
	#define UDBCSCHK_ISUCSDBCS(dbcsid) /*ucs dbcs or ucs4*/\
            (    UDBCSCHK_ISUCS2DBCS(dbcsid) \
              || UDBCSCHK_ISOVF(dbcsid)      \
            )                                                      //~v65cI~
#else                                                              //~v65cI~
	#define UDBCSCHK_ISUCSDBCS(dbcsid) /*ucs dbcs(except ucs sbcs)*/\
    		(\
              (((dbcsid)>=UDBCSCHK_UCSIDS) && ((dbcsid)<=UDBCSCHK_UCSIDE))\
            )                                                      //~v640M~
#endif                                                             //~v65cI~
	#define UDBCSCHK_ISUCSDBCST(dbcsid) /*ucs sbcs and dbcs*/\
    		(\
				UDBCSCHK_ISUCSSBCS(dbcsid) \
			||  UDBCSCHK_ISUCSDBCS(dbcsid) \
            )                                                      //~v640I~
	#define UDBCSCHK_ISCOMPOSED(dbcsid) /*ucs sbcs/dbcs and locale code dbcs*/\
    		(\
				UDBCSCHK_ISUCSDBCST(dbcsid) /*ucs2 on dd fmt*/\
			  ||UDBCSCHK_DBCSCOLS(dbcsid)   /*dbcs parts on locale code line*/\
            )                                                      //~v640I~
	#define UDBCSCHK_ISCOMPOSEDDBCS(dbcsid) /*ucs dbcs(except sbcs) and locale dbcs*/\
    		(\
				UDBCSCHK_ISUCSDBCS(dbcsid) /*ucs2 on dd fmt*/\
			  ||UDBCSCHK_DBCSCOLS(dbcsid)   /*dbcs parts on locale code line*/\
            )                                                      //~v640I~
#endif                                                             //~v640R~
                                                                   //~v640I~
#define UDBCSCHK_DBCSPAD_SETADVANCE(pdbcs,width) /*set dbcs padding on dbcstbl*/ \
		{\
		 	if ((width)>2) *pdbcs++=UDBCSCHK_DBCSPAD; /*SS3*/ \
			if ((width)>3) *pdbcs++=UDBCSCHK_DBCSPAD; /*GB18030*/ \
        }                                                          //~v62UR~
#define UDBCSCHK_DBCSPAD_ISGB4(pdbcs,reslen) /*chk dbcs tbl for GB18030 4 byte dbcs*/ \
		 	(    (reslen)>=4 \
			  && (*((pdbcs)+1)==UDBCSCHK_DBCSPAD) \
			  && (*((pdbcs)+2)==UDBCSCHK_DBCSPAD) \
			  && (*((pdbcs)+3)==UDBCSCHK_DBCS2ND) \
            )                                                      //~v62UR~
#define UDBCSCHK_DBCSPAD_SS3(pdbcs,reslen) /*chk dbcs tbl for SS3 of EUC*/ \
		 	(    (reslen)>=3 \
			  && (*((pdbcs)+1)==UDBCSCHK_DBCSPAD) \
			  && (*((pdbcs)+2)==UDBCSCHK_DBCS2ND) \
            )                                                      //~v62UR~
#define UDBCSCHK_DBCSCOLS(pc)  /*dbcs column */ \
        (    (pc)==UDBCSCHK_DBCS1ST                     \
          || (pc)==UDBCSCHK_DBCS2ND                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
        )                                                          //~v62UR~
#ifdef UTF8UCS2                                                    //~v640R~
	#define UDBCSCHK_DBCSNOT1ST_L(pc)  /*dbcs parts but not top;locale code*/ \
        (    (pc)==UDBCSCHK_DBCS2ND                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
        )                                                          //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS1STU    UDBCSCHK_DBCS1STUCS2NWPO          //~v65cI~
#else                                                              //~v65cI~
	#define UDBCSCHK_DBCS1STU    UDBCSCHK_DBCS1STUCS2NWP           //~v640R~
#endif                                                             //~v65cI~
#ifdef UTF8EBCD                                                    //~v660I~
	#define UDBCSCHK_DBCS1STL(dbcsid)  \
        (    (dbcsid)==UDBCSCHK_DBCS1ST                 \
        )                                                          //~v660I~
#endif                                                             //~v660I~
	#define UDBCSCHK_DBCS1STLU(dbcsid)  \
        (    (dbcsid)==UDBCSCHK_DBCS1ST                 \
          || UDBCSCHK_DBCS1STU(dbcsid)                \
        )                                                          //~v640M~
//#ifdef UTF8UCS4                                                  //~v65cI~//~v6uBR~
  #ifdef UTF8UCS416                                                //~v6uBI~
	#define UDBCSCHK_DBCSNOT1ST(dbcsid)  /*dbcs parts but not top*/ \
        (    UDBCSCHK_DBCSNOT1ST_L(dbcsid)                   \
          || UDBCSCHK_DBCS2NDU(dbcsid)                    \
        )                                                          //~v65cI~
  #else                                                            //~v65cI~
	#define UDBCSCHK_DBCSNOT1ST(dbcsid)  /*dbcs parts but not top*/ \
        (    UDBCSCHK_DBCSNOT1ST_L(dbcsid)                   \
          || UDBCSCHK_DBCS2NDUCS2NWP(dbcsid)                    \
        )                                                          //~v640M~
  #endif                                                           //~v65cI~
#else                                                              //~v640I~
#define UDBCSCHK_DBCSNOT1ST(pc)  /*dbcs parts but not top*/ \
        (    (pc)==UDBCSCHK_DBCS2ND                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
        )                                                          //~v62UR~
#endif                                                             //~v640I~
#ifdef UTF8UCS2                                                    //~v640R~
	#define UDBCSCHK_DBCSNOTEND_L(pc)  /*dbcs parts but not end;locale code*/ \
        (    (pc)==UDBCSCHK_DBCS1ST                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
        )                                                          //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UDBCSCHK_DBCS2NDU    UDBCSCHK_DBCS2NDUCS2NWPO          //~v65cI~
#else                                                              //~v65cI~
	#define UDBCSCHK_DBCS2NDU    UDBCSCHK_DBCS2NDUCS2NWP           //~v640R~
#endif                                                             //~v65cI~
#ifdef UTF8EBCD                                                    //~v660I~
	#define UDBCSCHK_DBCS2NDL(dbcsid)  \
        (    (dbcsid)==UDBCSCHK_DBCS2ND                 \
        )                                                          //~v660I~
#endif                                                             //~v660I~
	#define UDBCSCHK_DBCS2NDLU(dbcsid)  /*dbcs parts but not top*/ \
        (    (dbcsid)==UDBCSCHK_DBCS2ND                 \
          || UDBCSCHK_DBCS2NDU(dbcsid)                    \
        )                                                          //~v640I~
//#ifdef UTF8UCS4                                                  //~v65cI~//~v6uBR~
  #ifdef UTF8UCS416                                                //~v6uBI~
	#define UDBCSCHK_DBCSNOTEND(dbcsid)  /*dbcs parts but not end*/ \
        (    UDBCSCHK_DBCSNOTEND_L(dbcsid)   /*locale code*/     \
          || UDBCSCHK_DBCS1STU(dbcsid)                    \
        )                                                          //~v65cI~
  #else                                                            //~v65cI~
	#define UDBCSCHK_DBCSNOTEND(dbcsid)  /*dbcs parts but not end*/ \
        (    UDBCSCHK_DBCSNOTEND_L(dbcsid)   /*locale code*/     \
          || UDBCSCHK_DBCS1STUCS2NWP(dbcsid)                    \
        )                                                          //~v640M~
  #endif                                                           //~v65cI~
#else                                                              //~v640I~
#define UDBCSCHK_DBCSNOTEND(pc)  /*dbcs parts but not end*/ \
        (    (pc)==UDBCSCHK_DBCS1ST                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
        )                                                          //~v62UR~
#endif                                                             //~v640I~
#define UDBCSCHK_DBCSCHARS(pc)  /*dbcs parts            */ \
        (    (pc)==UDBCSCHK_DBCS1ST                     \
          || (pc)==UDBCSCHK_DBCSPAD                     \
          || (pc)==UDBCSCHK_DBCS2ND                     \
        )                                                          //~v62UR~
#define UDBCSCHK_PCD_MBCHSZ(pcd,reslen) /* pcd==dbcs1st is confirmed */ \
        (  reslen>1 && UDBCSCHK_DBCS2NDL(*((pcd)+1))       \
           ? UDBCSCHK_DBCSSZ                                \
           :  ( reslen>2 && UDBCSCHK_DBCS2NDL(*((pcd)+2))  \
                ? UDBCSCHK_SS3SZ                            \
                :  ( reslen>3 && UDBCSCHK_DBCS2NDL(*((pcd)+3))  \
                     ? UDBCSCHK_GB4SZ                           \
                     : 1   /*err*/                                \
                   )  \
              )       \
        )                                                          //~v66XI~
#define UDBCSCHK_DBCSSZ      2       //normal dbcs size            //~v62UR~
#define UDBCSCHK_SS3SZ       3       //mb strlen                   //~v62UR~
#define UDBCSCHK_GB4SZ       4       //mb strlen                   //~v62UR~
#define UDBCSCHK_NONSPACE    '0'     //nonspacing character        //~v5i9I~
#define UDBCSCHK_TAB         '\t'    //tab id on dbcs tbl          //~v511I~
#define UDBCSCHK_HK1         'h'     //hankaku katakana prefix of euc//~v39xI~
#define UDBCSCHK_HK2         'k'     //hankaku katakana code of euc//~v39xI~
#define UDBCSCHK_HKDBCSERR   'e'     //2 byte code conbination err //~v39DI~
#define UDBCSCHK_F2LERR      'f'     //f2l trans err char          //~v636I~
#define UDBCSCHK_SBCS         0      //on dbcs tbl                 //~v39xI~
#define UDBCSCHK_EUCHKCONV     0x01	//hankaku katakana conv to zenkaku katakana//~v39xI~
#define UDBCSCHK_ASCIISBCS     0x02	//sbcs is valid when <0x80     //~v39FR~
#define UDBCSCHK_EUCHKERR      0x04	//set unprintable hankaku katakana//~v39FI~
#define UDBCSCHK_NOCLEAR       0x08	//no set sbcs id on dbcs tbl   //~v50YI~
#define UDBCSCHK_ERRDBCSCHK    0x10	//chk dbcs 2 byte combination  //~v513I~
#define UDBCSCHK_KANAONLY      0x20	//kana hankaku-->zenkaku conv only//~v551I~
#define UDBCSCHK_CONTLINE      0x40	//return rc if last byte is dbcs split//~v57dI~
#define UDBCSCHK_RC0IFNOERR    0x80	//return 0 if no error(no dbcs or hankana rc)//~v614I~
#define UDBCSCHK_JISMODE      0x3f00 //jis mode for next of contline//~v57eR~
//                               see  following CT_xxxx            //~v5n8I~
#define UDBCSCHK_HKDBCS       0x4000 //treat EUC hankaku katakana as DBCS//~v5n8I~
#define UDBCSCHK_SS3ERR       0x8000 //no 2nd level KANJ support(ignore SS3)//~v5ntI~
#define UDBCSCHK_RC_HANKANAERR   0x01	//hankaku katakana err     //~v550I~
#define UDBCSCHK_RC_DBCSERR      0x02	//err dbcs                 //~v550I~
#define UDBCSCHK_RC_ASCIIERR     0x04	//sbcs>=0x'80'             //~v550I~
#define UDBCSCHK_RC_HANKANAFOUND 0x10	//hankaku katakana found   //~v550I~
#define UDBCSCHK_RC_DBCSFOUND    0x20	//dbcs found               //~v550I~
#define UDBCSCHK_RC_DBCSSPLIT    0x40	//last byte is dbcs split  //~v57dI~
#define UDBCSCHK_RC_SS3          0x80	//hankaku katakana found   //~v5ntI~
#define UDBCSCHK_RC_GB4        0x0100	//4byte dbcs found         //~v62UR~
#define UDBCSCHK_RC_JISSPLIT   0xc000	//jis split residual len mask//~v57eR~
#define UDBCSCHK_RC_JISSPLITSHIFT  14 	//jis split residual len mask//~v57eR~
#define UDBCSCHK_RC_JISMODE    0x3f00 //continued jis mode         //~v57eR~
#define UDBCSCHK_RC_JISMODESHIFT    8 	//jis mode shift bit       //~v57dI~
#define UDBCSCHK_SUBCHAR_DBCS 0xfffd                               //~v5mQR~
#define UDBCSCHK_SUBCHAR_SBCS 0x001a                               //~v5mQI~
#define CT_SBCS     0x10                                           //~v57eM~
#define CT_DBCS     0x20                                           //~v57eM~
#define CT_JIS78     (CT_DBCS+0)                                   //~v57eM~
#define CT_JIS83     (CT_DBCS+1)                                   //~v57eM~
#define CT_JIS90     (CT_DBCS+2)                                   //~v57eM~
#define CT_ASCII     (CT_SBCS+0)                                   //~v57eM~
#define CT_ROMAN     (CT_SBCS+1)   //jis x0201 roman(diff \ and ~ with ascii)//~v57eM~
#define CT_ROMAN7    (CT_SBCS+2)   //so,si change to katakana      //~v57eM~
#define CT_KATAKANA  (CT_SBCS+3)                                   //~v57eM~
                                                                   //~v5n5I~
#define CP_GB18030     54936      //simple chinese                 //~v5n5M~
//**************************************************               //~v198I~
#ifdef __cplusplus                                                 //~2818I~//~v640I~
extern  "C"                                                        //~2818I~//~v640I~
{                                                                  //~2818I~//~v640I~
#endif                                                             //~2818I~//~v640I~
//**************************************************               //~v640I~
int  udbcschk(unsigned char);
#ifdef UTF8SUPPH                                                   //~v620I~
//	int udbcschk_getmblen(int Popt,UCHAR *Ppc);                    //~v62UR~
int udbcschk_getmblen(int Popt,UCHAR *Ppc,int Plen,int *Pplen);    //~v62UR~
#define UDCGMLO_LEN1IFERR     0x01        //set len=1 if err       //~v62UR~
#define UDCGMLRC_CHTYPEMASK   0x00ff      //                       //~v62UR~
#define UDCGMLRC_CHTYPESS2    SS2                                  //~v62UR~
#define UDCGMLRC_CHTYPESS3    SS3                                  //~v62UR~
#define UDCGMLRC_CHTYPESBCS   0                                    //~v62UR~
#define UDCGMLRC_CHTYPEDBCS   UDBCSCHK_DBCS1ST                     //~v62UR~
#define UDCGMLRC_CHTYPEDBCS4  '4'                                  //~v62UR~
#define UDCGMLRC_ERR          0x0100      //err if rc over this value//~v62UR~
#define UDCGMLRC_ERRSHORT     0x0200                               //~v62UR~
#endif                                                             //~v620I~
//**************************************************               //~v61bI~
//#ifdef UTF8SUPP                                                  //~v5mQR~
#ifdef WCSUPP                                                      //~v5mQI~
  #ifdef AAA                                                       //~v6BGI~
int udbcschk_localeisdbcs(void);                                   //~v61bI~
  #endif                                                           //~v6BGI~
                                                                   //~v5mQI~
	int udbcschk_wcinit(int Popt,char *Plocale);                   //~v5n8R~
//  #define UDCWCIO_WCDBCSCHK           0x01     //support DBCS other than Japanese//~v5n8R~
    #define UDCWCIO_WIDEAPI             0x01     //use Widechar version API//~v5n8I~
    #define UDCWCIO_UTF8VERSION         0x02     //xe version is utf8 version//~v5n8R~
    #define UDCWCIO_KBDUNICODE          0x04     //kbdread returns unicode//~v5n8R~
    #define UDCWCIO_KBDMBS              0x08     //kbdread returns unicode//~v5n8I~
    #define UDCWCIO_FORCEWIDE           0x10     //force unicode for kbd and vio//~v5n8R~
    #define UDCWCIO_KBDUTF8             0x20     //kbdread is utf8 //~v5n8I~
    #define UDCWCIO_WCDBCS              0x40     //env is UTF8     //~v5n8R~
    #define UDCWCIO_KBDNOUTF8           0x80     //cmdline option kbdread utf8 byte by byte//~v5n8I~
    #define UDCWCIO_RESETLOCALE       0x0100     //reset locale codepage//~v5n8I~
    #define UDCWCIO_FORCELOCALE       0x0200     //by locale parm  //~v5n8I~
    #define UDCWCIO_VIOCLEARDBCS      0x0400     //linux clear dbcs line mode//~v5n8I~
    #define UDCWCIO_VIOFROMUTF8       0x0800     //vio source is utf8 string(for xekbchk)//~v5n8I~
    #define UDCWCIO_BEFOREINIT        0x1000     //force english until wcinit//~v5nvI~
    #define UDCWCIO_KBDFORCEUTF8      0x2000     //conv kbdinput from utf8 to locale//~v620R~
    #define UDCWCIO_DBCSREAD          0x4000     //mode to return dbcs at once//~v62UR~
    #define UDCWCIO_INTERNAL          0x8000     //internal call   //~v638I~
    #define UDCWCIO_XEACB           0x010000     //for xeacb,write unprintable ucs as is//~v640I~
    #define UDCWCIO_LOCALICU        0x020000     //use ICU as local converter//~v6f3R~
    #define UDCWCIO_CJK             0x040000     //force mk_wcwidth_cjk//~v6WvI~
                                                                   //~v5mQI~
	int udbcschk_ismbdbcs1st(int Popt,UCHAR Pch);                  //~v5mQI~
	int udbcschk_getdbcs1st(int Popt,char *Ppflags);               //~v5mQI~
//	#define UDBCSCHK_ISDBCS1ST(ch) (udbcschk_ismbdbcs1st(0,ch)!=0) //byte is candidate of dbcs 1st byte//~v62UR~
  	#define UDBCSCHK_ISMBDBCS1ST(ch) (udbcschk_ismbdbcs1st(0,ch)!=0) //byte is candidate of dbcs 1st byte//~v62UR~
#ifdef UTF8UCS4                                                    //~v65cI~
	int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,WUCS *Ppucs);//~v65cI~
    #define UDCM2U1O_A2E      0x01      //for locale to ebc translation//~v66nR~
#else                                                              //~v65cI~
//  int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,USHORT *Ppucs);//~v5mQI~//~v6BjR~
    int udbcschk_mb2ucs1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs);//~v6BjR~
    #define UDCM2U1O_A2E      0x01      //for locale to ebc translation//~v66nI~
#endif                                                             //~v65cI~
    #define UDCM2U1O_BACKCHK  0x02      //reverse chk              //~v66DI~
//  int udbcschk_ucs2mb1(int Popt,USHORT Pucs,UCHAR *Pmbs,int *Ppchklen);//~v5mQI~//~v692R~
//  int udbcschk_ucs2mb1(int Popt,WUCS Pucs,UCHAR *Pmbs,int *Ppchklen);//~v692I~//~v6BjR~
    int udbcschk_ucs2mb1(int Popt,UWUCS/*ucs4*/Pucs,UCHAR *Pmbs,int *Ppchklen);//~v6BjI~
    #define UDCU2M1O_BACKCHK  0x04      //reverse chk              //~v66DI~
	int udbcschk_mb2nd(int Popt,ULONG Pconverter,UCHAR *Ppmbs);    //~v5n8I~
                                                                   //~v5n8I~
#endif                                                             //~v61bI~
#define LANGEUCID  "EUC"                                           //~v62UR~//~v62VM~
#define LANGGB4ID  "GB18030"                                       //~v62VI~
//**************************************************               //~v61fI~
int udbcschk_hk(int Popt,UCHAR Pchar);                             //~v61fI~
#define UDBCSCHKO_FORCELOCALE   0x01  //chk by iconv under UTF8ENV for hexkbd on LOCALE file//~v61bI~
//**************************************************               //~v5i9I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//int udbcschk_utf(UCHAR *Pstr,int Plen,int *Pputflen);            //~v5n8R~
//#endif                                                           //~v5n8R~
//  #ifdef LNX                                                     //~v5mQR~
#ifdef WCSUPP                                                      //~v5mQI~
		int udbcschk_locale_topbyte(UCHAR Pchar);                  //~v61bI~
//		int udbcschk_locale1(UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs);//~v66nR~
  		int udbcschk_locale1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs);//~v66nR~
        #define UDCL1O_NOCHKWIDTH 0x01                             //~v66nR~
//  #endif                                                         //~v5mQR~
#endif                                                             //~v600I~
#ifdef W32                                                         //~v6BCI~
	#define ISWPRINT(uwucs)  (!UTF_ISUCS4(uwucs) && iswprint((wint_t)uwucs))//~v6BCR~
#else                                                              //~v6BCI~
	#define ISWPRINT(uwucs)  (iswprint((wint_t)uwucs))             //~v6BCI~
#endif                                                             //~v6BCI~
//**************************************************               //~v39CI~
void udbcschk_forceenglish(void);                                  //~v39CI~
//**************************************************               //~v150I~
int udbcschkcp(void);                                              //~v150I~
//*******************************************************          //~v150I~
int ugetcp(void);                                                  //~v150R~
#ifdef W32                                                         //~v5n1I~
//*******************************************************          //~v5n1I~
int udbcschk_getcpinfo(int Popt,ULONG Pcp,void *Ppinfo);           //~v5n1I~
int udbcschk_getcodepagetype(int Popt,ULONG Pcp);                  //~v5n1I~
int udbcschk_getstarter(int Popt,ULONG Pcp,UCHAR *Pflags,UCHAR *Pleadbyte);//~v5n1I~
int udbcschk_getsubch(int Popt,ULONG Pcp,int *Ppsubchsbcs,int *Ppsubchdbcs);//~v5n1I~
#endif                                                             //~v5n1I~
//*******************************************************          //~v024I~
char *udbcsenv(void);                                              //~v024I~
//**************************************************               //~v024I~
UCHAR *udosquerydbcsenv(void);                                     //~v024I~
//*******************************************************          //~v051I~
int udbcschk2(char *Pbuff,int Poffs);                              //~v051I~
//*******************************************************          //~v051I~
unsigned int usjis2jis(unsigned int Psjis);                        //~v198R~
//*******************************************************          //~v39xI~
unsigned int ujis2sjis(unsigned int Pjis);                         //~v39xI~
//*******************************************************          //~v560I~
int ustrsjis2jis(int Popt,unsigned char *Psjisstr,int Plen,unsigned char *Pjis,int *Poutlen);//~v57eI~
//*******************************************************          //~v57eI~
int ustrjis2sjis(int Popt,UCHAR *Pjisstr,int Plen,UCHAR *Poutstr,int *Poutlen);//~v560I~
//*******************************************************          //~v39xI~
//int usjischk(unsigned char *Psjis,int Plen,unsigned char *Pdbcs,int Popt);//~v550R~
int usjischk(unsigned char *Psjis,int Plen,                        //~v550I~
				unsigned char *Pdbcs,int *Poutlen,int Popt);       //~v550I~
//*******************************************************          //~v40vI~
//int ushift2euc(unsigned char *Psjis,int Plen,unsigned char *Peuc,//~v550R~
//				unsigned char *Pdbcs,int Popt);                    //~v550R~
int ushift2euc(unsigned char *Psjis,unsigned char *Pdbcsi,int Plen,//~v550I~
				unsigned char *Peuc,unsigned char *Pdbcs,int *Poutlen,int Popt);//~v550R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//*******************************************************          //~v614I~
int ushift2euc1(int Popt,int Psjis,int *Peuc);                     //~v614I~
#endif                                                             //~v614I~
//*******************************************************          //~v57pI~
int ushift2euccount(unsigned char *Psjis,int Plen,int *Poutlen,int Popt);//~v57pI~
//*******************************************************          //~v39xI~
//int ueuc2shift(unsigned char *Peuc,int Plen,unsigned char *Psjis,//~v550R~
//				unsigned char *Pdbcs,int Popt);                    //~v550R~
int ueuc2shift(unsigned char *Peuc,unsigned char *Pdbcsi,int Plen,//~v550R~
				unsigned char *Psjis,unsigned char *Pdbcs,int *Poutlen,int Popt);//~v550R~
//*******************************************************          //~v614I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
int ueuc2shift1c(int Popt,int Peuc,int* Ppsjis);                   //~v614R~
#endif                                                             //~v614I~
//*******************************************************          //~v60eI~
int ueuc2shift1(int Popt,unsigned char *Peuc,int Plen,unsigned int *Ppsjis,unsigned char *Pdbcs);//~v614R~
//*******************************************************          //~v39DI~
//int ueucchk(unsigned char *Peuc,int Plen,unsigned char *Pdbcs,int Popt);//~v550R~
int ueucchk(unsigned char *Peuc,int Plen,                          //~v550I~
			unsigned char *Pdbcs,int *Phankanactr,int Popt);       //~v550I~
//*******************************************************          //~v56xI~
int usetdbcstbl(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);    //~v56xR~
#define USDT_CODE_TYPE        0x0f                                 //~v56xI~
#define USDT_CODE_EUC         0x01                                 //~v56xI~
#define USDT_CODE_SJIS        0x02  //chk 1st byte only            //~v56xR~
#define USDT_CODE_SJIS2       0x03  //chk 2nd byte also            //~v56xI~
#define USDT_CODE_SJISX208    0x04                                 //~v56xR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	#define USDT_CODE_UTF8    0x05                                 //~v60aI~
	#define USDT_CODE_ANY     0x06                                 //~v62UR~
#endif                                                             //~v60aI~
#ifdef UNX                                                         //~v56xI~
	#ifdef LNX                                                     //~v56xI~
//  	#define USDT_CODE_DEFAULT  USDT_CODE_EUC                   //~v62UR~
    	#define USDT_CODE_DEFAULT  USDT_CODE_ANY    //dbcstbl      //~v62UR~
    #else                                                          //~v56xI~
		#define USDT_CODE_DEFAULT  USDT_CODE_SJIS2  //aix          //~v56xR~
    #endif                                                         //~v56xI~
#else                                                              //~v56xI~
   #ifdef W32                                                      //~v62UR~
	#define USDT_CODE_DEFAULT  USDT_CODE_ANY        //dbcstbl      //~v62UR~
   #else                                                           //~v62UR~
	#define USDT_CODE_DEFAULT  USDT_CODE_SJIS2      //dos          //~v56xR~
   #endif                                                          //~v62UR~
#endif                                                             //~v56xI~
#ifdef WCSUPP                                                      //~v5n8I~
//*******************************************************          //~v5n8I~
int usetdbcstblmb(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);  //~v5n8I~
#define USDTMO_SPLITERR       0x01       //set err when last dbcs split//~v5n8I~
#define USDTMO_SPLITSBCS      0x02       //set SBCS when last dbcs split//~v5n8I~
#define USDTMO_CHK2ND         0x04       //1st+2nd byte pair chk   //~v5n8I~
#define USDTMO_SETERRFULL     0x08       //set err not only 1 byte but by mblen//~v62UR~
#define USDTMO_TABKEEP        0x80       //dont clear tab and tabexpand//~v62UR~
#define USDTMO_CONSOLE      0x0100       //linux on console(all sbcs)//~v62UR~
//*******************************************************          //~v5n8I~
//int udbcschk_getbaseconverter(int Popt,ULONG *Ppconverters,UCHAR **Pppdbcstbl);//~v5n8I~//~v6hhR~
int udbcschk_getbaseconverter(int Popt,ULPTR *Ppconverters,UCHAR **Pppdbcstbl);//~v6hhI~
#define UDCGBC_CHARSET  0x01        //get not dbcstb but charset   //~v6f5I~
#endif                                                             //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
	int udbcschk_getlinuxleadbyte(int Popt,UCHAR *Pdbcs1st,UCHAR *Pleadbyte);//~v5n8M~
	int udbcschk_srchSS2(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~v6btI~
#endif                                                             //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v627I~
//*******************************************************          //~v62pI~
	char *udbcschk_setlocale(int Popt,int Ptype,char *Plocale);    //~v627R~
    #define UDCSLO_CHKBASE      0x01    //chk default lang of the locale dropping UTF8//~v62WR~
    #define UDCSLO_CHKPARM      0x02    //user specified locale chk//~v62WR~
    #define UDCSLO_NOMSG        0x04    //skip errmsg issue        //~v638I~
//*******************************************************          //~v62uI~
	int udbcschk_wingetdefaultcp(int Popt,char *Pplocale);         //~v62uI~
	#define UDCSLO_GETENV         0x01   //get initial value for environment chk//~v62MI~
//*******************************************************          //~v62pI~
	int udbcschk_pos2offs(int Popt,char *Pbuff,int Plen,int Ppos,int *Pppos);//~v62pI~
	#define UDCPOO_LIMIT_UCSCOUNT 0x01   //pos by ucs count        //~v62pI~
#endif                                                             //~v627I~
#ifdef __cplusplus                                                 //~2818I~//~v640I~
}                                                                  //~2818I~//~v640I~
#endif                                                             //~2818I~//~v640I~
#ifdef W32                                                         //~v6BAI~
//************************************************************************************//~v6BAI~
int uwctombW(int Popt,UWUCS Pucs,char *Pmbs);                      //~v6BAR~
#define UW2MWO_NOBESTFIT        0x01   //not output bestfit char   //~v6HkR~
#define UW2MWO_SUBCHRC          0x02   //set rc suchar rep occured //~v6HkI~
//************************************************************************************//~v6BAI~
int umbtowcW(int Popt,char *Pmbs,int Pinplen,UWUCS *Ppucs);        //~v6BAI~
//************************************************************************************//~v6BAI~
int udbcschk_isleadbyte(char Pch);                                 //~v6BAR~
//************************************************************************************//~v6BQI~
int udbcschk_lcbychcp(int Popt,char *Psrc,char *Ptgt,int Pbuffsz); //~v6BQI~
//************************************************************************************//~v6WvI~
int udbcschk_getcp(void);                                          //~v6WvI~
#endif  //W32                                                      //~v6BAI~
