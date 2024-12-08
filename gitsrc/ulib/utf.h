//*CID://+v7bBR~:                             update#=  663;       //~v7bBR~
//*********************************************************************//~v600I~
//* utf8 data manipulation                                         //~v600I~
//*********************************************************************//~v600I~
//v7bB:240420 special for zwj(u-200d/zwnj(u-200c) of width=0       //~v7bBI~
//vbzz:240311 arrange vbz3,vbzp:/Yv and vbzy:YL to /Gv[L]          //~vbzzI~
//vbzy:240310 /YL, optionally ambiguous chk for language by performance reason.//~vbzyI~
//vbzu:240302 add test option to notrace while mapinit for performance. (del prev option /Yn/Nn to winNT option)//~vbzuI~
//v7ac:240229 (WINCON)on Windows Console,Font Mincho, confused ambiguous char display when /Yv; try write ambiguous char 1 by 1//~v7acI~//~vbzzR~
//v7a9:240226 UTF_GETUTF8STR(Pucs,Pwku8,Plen) --> U2FCHAR(Pucs)    //~v7a9I~
//v7a7:240226 (W32 console)for /Yv,evaluate griph width for ambiguous using DrawTextW(not GetTextExtentPointW,GetCharWidth32,GetABCWidthsW)//~v7a7I~
//v7a5:240225 add mb to ucs                                        //~v7a5I~
//v7a4:240225 cv mb to ucs was missing.                            //~v7a4I~
//v7a0:240221 W32:console; adjusting ambiguous required for ex Åú..hide next char if width=1)//~v7a0I~
//v79E:240209 LNX:like v79C, no tbl reference for xe/gxe.          //~v79EI~
//            xe;-Nv:ambigous is all width=2, -Yv:ambiguous is all width=1//~v79EI~
//vbzj:240202 Test option /UUxxxx; set unicode for debug breaking at utfwcwidthsub.//~vbzjI~
//vbzj:240202 Test option /UUxxxx; set unicode for debug breaking. //~vbzjI~
//v79h:240128 (LNX)new combining char from web                     //~v79hI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//v796:240118 W32:try to chk cursor step for cpu8 file.            //~v796I~
//            Adjust culumn width by uftwcwidth for cursor width is single column to avoid column string move by cursor position//~v796I~
//v70g:200715 (BUG)utfcvl2f retrns err when wcwidth=0 and output char same as input. it should set utf8 even width=0//~v70gI~
//v6X0:180813 combining require 2 cell when split such as u309a    //~v6XOI~
//vbmk:180813 (XE)for test,try mk_wcwidth_cjk(ambiguous:Wide DBCS) for visibility chk. use /YJ option//~vbmkI~
//v6Wm:180724 utfwcwidth return len=1 for Category "Cf"(wcwidth=0)  if ucs<ENTNO(2 if ucs>=ENTNO).//~v6WmI~
//            determin combining for ucs>=ENTNOv should not use wcwidth==0 but combining definition//~v6WmI~
//v6Wk:180723 (gxe)ambiguous(width=2) for gxe                      //~v6WkI~
//v6Wi:180722 u+ad(Soft Hyphen) is wcwidth=0,bu combineprocess A0+ad show on 2 col. trate it as utfwcwidth=1 (unicode category Cf:Format)//~v6WiI~
//v6W9:180708 dbcs combining char such as u309a(u306f+u309a) exists.//~v6W9I~
//v6Vb:180612 add isSpacingCombiningmark                           //~v6VbI~
//v6V7:180606 do not modify by wcwidth api,acept it only for return by mk_wcwidth//~v6V7I~
//v6V4:180531 apply mk_wcwidth also for ucs4(>=map entry)          //~v6V4I~
//v6V1:180518 char width adjust to ubuntu 17.10(kernel 4.13.0)     //~v6V1I~
//v6T4:180217 f2l option to set dbcs "?" for f2l err               //~v6T4I~
//v6K8:170331 (LNX)ubuntu lts uerrexit at udbcschk_wclocalereset after udbcschk_chklocale//~v6K8I~
//            because iconv_open failed for "eucjp", iconv --list show "EUCJP".//~v6K8I~
//            cause is libiconv114 was installed to /usr/local for Axe//~v6K8I~
//            uninstall it by /home3/androidndk/Project/Aiconv114  //~v6K8I~
//            and for safety iso88591 to ISO8859-1                 //~v6K8I~
//v6Ek:160806 (W32)for xe:b4j(OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay))//~v6EkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6B9:160121 (LNX)new ufullpathCP function to chk optionally filesystem iocharset  convert to utf8 from locale code//~v6B9I~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4))//~v6ueI~
//v6r4:131221 (WIN:BUG)did not cv utf8 to sarrogate pair           //~v6r4I~
//v6hH:120915 (BUG) dbcstbl is all sbcs(utfcvl2f)                  //~v6hHI~
//v6hG:120915 utfcvl2f;option to limit by outbuff size             //~v6hGI~
//v6hs:120713 (Lnx)drop UTF8SUPP from Makefile                     //~v6hsI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6c5:120121 (Axe)no mk_wcwidth,completeley depends to wcwwidth(Java getTextWidths)(but allow adjust by parameter file)//~v6c5I~
//v6bt:111230 utfcvf2dd:add option to return chklen if reached outwidth//~v6btI~
//v6b5:110829 utfcvf2u:no need to chk printable as locale code     //~v6b5I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v69z:101003 l2ddtab(chk dbcstbl for tab)                         //~v69zI~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//            ebc2ucs may be ok by USHORT ucs(icu def is USHORT),but change it.//~v692I~
//v67Z:100615 (LNX)sbcsid overflowed at ub9(ue000-u8ff private area is assigbed as sbcs)//~v67ZI~
//            remap should reassign for overflowed ucs             //~v67ZI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v650:100121 print width=0                                        //~v650I~
//v645:091218 add f2u for wxe c&p                                  //~v645I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v633:091115 (UTF8:LNX:BUG) setlocale "ko_kr.UHC" fail like as v62W//~v633M~
//            ignore setlocale err when parm specified,warning msg only.//~v633M~
//v62X:091107_compchkm                                             //~v62XI~
//v62W:091103_(BUG)setlocale fail when env has utf8 only. accept as no dbcs env.//~v62WI~
//            eg) At Ubuntu910 installed by lang=English, "locale -a" shows "en_US.UTF8" only, there is no "en_US"//~v62WI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62G:091005_(BUG)for isprint func;utfcvu2lany1mb is always success. isprint should be used//~v62GI~
//                 but for isprint setlocale should be issued for -Cparameter. v62F is now meaningless.//~v62GI~
//v62t:090930!utfret option for utfcvl2f                           //~v62tI~
//v62p:090916!add udbcschk_pos2offs                                //~v62pI~
//v62j:090907 UTF8SUPP-->UTF8SUPPH for common to xe and wxe(wxe compiled by vc6;uncoditional for LNX because xxe use ulibxxe)//~v62jI~
//v627:090719 use setlocale when not UTF8(avoid dup req,reissue of setlocale(,"") reset to default locale)//~v627I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            conv utf8filename on udirlist to locale code         //~v620R~
//            add utfgetutfstrlen                                  //~v620I~
//            add utfsplitchk                                      //~v620I~
//            pos2offs using codetype                              //~v620I~
//v5nq:081105*move UTF8ISASCII to ulibdef.h                        //~v5nqI~
//v5np:081105*for compchk at xe                                    //~v5npI~
//v5ne:081011 (XXE)draw ime cursor                                 //~v5neR~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n4:080906 (UTF8)compchk                                        //~v5n4I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v61r:080214 (UTF:BUG)UTC_CHOFCPY\UTC_CHOFMOVE dose not increse offset when diff=0//~v61hI~
//v61h:071225 (UTF:BUG)display err for locale file under UTF8 env  //~v61hI~
//v61g:071222 (UTF)locale<-->utf8 conversion support               //~v61gI~
//v61f:071222 (UTF:BUG)UTCinca/UTCdeca miss to pass UTCO_AFT       //~v61fI~
//v61b:071205 (UTF:LNX)support locale other than EUC               //~v61bI~
//v61a:071205 (UTF)dbcstbl support of utfgetutf8str                //~v61aI~
//v618:071201 (UTF)udirlist support sort by name by utf8           //~v618I~
//v617:071130 (UTF)utfchk 1 byte char                              //~v617I~
//v616:071129 (UTF)l2f is wrapper to e2f                           //~v616I~
//v612:071113 (UTF)utfcvl2f optionaly return char width            //~v612I~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v60m:071019 (UTF:LNX)default width table for ja_JP.eucJP         //~v60mI~
//v60f:071018 (UTF:LNX)chk by g_locale_from_utf8 when forced UTF8(-y8 under no utf8 env)//~v60fI~
//            to avoid screen corrupt at console mode              //~v60fI~
//v60d:071016 (UTF)add utfcvl2f(locale to utf8)                    //~v60dI~
//v60a:070928 (UTF:WXE)                                            //~v60aI~
//v600:070710 (UTF8)new typdef                                     //~v600I~
//*********************************************************************//~v600I~
//************************************************                 //~v600I~
#define UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1M~
//************************************************                 //~v600I~
#define ZWNJ   0x200c                                              //~v7bBM~
#define ZWJ    0x200d                                              //~v7bBM~
#define UTF_ISZWNJ(ucs) (ucs==ZWNJ)                                //+v7bBR~
#define UTF_ISZWJ(ucs)  (ucs==ZWJ)                                 //+v7bBR~
#define UTF_ISZWJZWNJ(ucs) (UTF_ISZWNJ(ucs) || UTF_ISZWJ(ucs))     //+v7bBR~
//#ifdef UTF8SUPP                                                    //~v60aI~//~v650R~
#ifdef UTF8SUPPH                                                   //~v650I~
#ifdef __cplusplus                                                 //~v60aI~
extern  "C"                                                        //~v60aI~
{                                                                  //~v60aI~
#endif                                                             //~v60aI~
#endif                                                             //~v60aI~
#ifdef UTF8SUPP                                                    //~v600I~
//assign char/utf-char                                             //~v600R~
    int     UTCeqs(int Popt,PUTCHARS Ptgt,int Ppost,PUTCHARS Psrc,int Pposs);	//*(data1+pos1)=*(data2+pos2)//~v600I~
    int     UTCeqcs(int Popt,PUTCHARS Ptgt,int Ppos,int Pch);	                //*(data+pos)=ch//~v600R~
    int     UTCeqDPs(int Popt,UCHAR *Ptgt,PUTCHARS Psrc,int Ppos);	                //*(data+pos)=ch//~v600I~
    int     UTCeqPDs(int Popt,PUTCHARS Ptgt,int Ppos,UCHAR *Psrc);	                //*(data+pos)=ch//~v600I~
    UCHAR  *UTCeqcincdecs(int Popt,PUTCHARS Ptgt,int Ppos,int Pch,int Pcnt);	//*data++=ch//~v600R~
	UCHAR  *UTCeqincdecs(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,int Pcnt);//~v600R~
    #define UTCeq0C(Ptgt,Pch)                UTCeqcs(0,Ptgt,0,Pch) //~v600R~
    #define UTCeq0Cinca(Ptgt,Pch)            UTCeqcincdecs(UTCO_AFT,Ptgt,0,Pch,1)//~v600R~
    #define UTCeq0Cdeca(Ptgt,Pch)            UTCeqcincdecs(UTCO_AFT,Ptgt,0,Pch,-1)//~v600I~
    #define UTCeqPC(Ptgt,Ppos,Pch)           UTCeqcs(0,Ptgt,Ppos,Pch)//~v600R~
    #define UTCeqMPC(Ptgt,Ppos,Pch)          UTCeqcs(0,Ptgt,-Ppos,Pch)//~v600I~
    #define UTCeq00(Ptgt,Psrc)               UTCeqs(0,Ptgt,0,Psrc,0)//~v600R~
    #define UTCeq00inca(Ptgt,Psrc)           UTCeqincdecs(UTCO_AFT,Ptgt,0,Psrc,0,1)//~v600R~
    #define UTCeq00deca(Ptgt,Psrc)           UTCeqincdecs(UTCO_AFT,Ptgt,0,Psrc,0,-1)//~v600I~
    #define UTCeqPP(Ptgt,Ppost,Psrc,Pposs)   UTCeqs(0,Ptgt,Ppost,Psrc,Pposs)//~v600R~
    #define UTCeqP0(Ptgt,Ppost,Psrc)         UTCeqs(0,Ptgt,Ppost,Psrc,0)//~v600R~
    #define UTCeqP0inca(Ptgt,Ppost,Psrc)     UTCeqincdecs(UTCO_AFT,Ptgt,Ppost,Psrc,0,1)//~v600I~
    #define UTCeqDP(Ptgt,Psrc,Ppos)          UTCeqDPs(0,Ptgt,Psrc,Ppos)//~v600R~
    #define UTCeqD0(Ptgt,Psrc)               UTCeqDPs(0,Ptgt,Psrc,0)//~v600R~
    #define UTCeqD0inca(Ptgt,Psrc)           Ptgt+=UTCeqDPs(UTCO_AFT,Ptgt,Psrc,0)//~v600R~
    #define UTCeqPD(Ptgt,Ppos,Psrc)          UTCeqPDs(0,Ptgt,Ppos,Psrc)//~v600R~
                                                                   //~v600I~
                                                                   //~v600I~
    #define UTC_ADDR2OFFS(Paddr,Putch)       (int)((ULONG)Paddr-(ULONG)UTCDATA(Putch))//~v600I~
    #define UTC_ADDR2POS(Paddr,Putch,byteoffs)        UTC_OFFS2POS(0,Putch,UTC_ADDR2OFFS(Paddr,Putch),byteoffs)//~v600R~
//calc colum by offset                                             //~v600I~
	int  UTCwidths(int Popt,PUTCHARS Ptgt,int Ppost,PUTCHARS Pbase);//~v600R~
	int  UTCwidthDs(int Popt,PUTCHARS Ptgt,int Ppost,UCHAR *Pbase);//~v600I~
    #define UTCwidth00(Ptgt,Psrc)             UTCwidths(0,Ptgt,0,Psrc)//~v600R~
    #define UTCwidth0D(Ptgt,Paddr)            UTCwidthDs(0,Ptgt,0,Paddr)//~v600I~
//strlen                                                           //~v600R~
	int  UTCstrlens(int Popt,PUTCHARS Ptgt,int Ppos);              //~v600R~
	#define  UTCstrlen0(Ptgt)                 UTCstrlens(0,Ptgt,0) //~v600R~
	#define  UTCstrlenP(Ptgt,Ppos)            UTCstrlens(0,Ptgt,Ppos)//~v600R~
	#define  UTCstrlenD(Ptgt)                 UTCstrlens(UTCO_BYADDR,(PUTCHARS)(ULONG)(Ptgt),0)//~v600I~
	#define  UTCstrlenCHOF(Ptgt)              UTCLENCCPOS(Ptgt)    //~v600R~
//memchr                                                           //~v600I~
	char *UTCmemchrs(int Popt,PUTCHARS Ptgt,int Ppos,int Pch,UINT Plen);//~v600R~
	#define  UTCmemchr0(Ptgt,Pch,Plen)       UTCmemchrs(0,Ptgt,0,Pch,Plen)//~v600I~
	#define  UTCmemchr0update(Ptgt,Pch,Plen) UTCmemchrs(UTCO_UPDATE,Ptgt,0,Pch,Plen)//~v600I~
	#define  UTCmemchrP(Ptgt,Ppos,Pch,Plen)  UTCmemchrs(0,Ptgt,Ppos,Pch,Plen)//~v600I~
//memset                                                           //~v600I~
	int  UTCmemsets(int Popt,PUTCHARS Ptgt,int Ptpos,int Pch,UINT Plen);//~v600I~
	#define UTCmemset0(Ptgt,Pch,Plen)        UTCmemsets(0,Ptgt,0,Pch,Plen)//~v600R~
	#define UTCmemsetE0(Ptgt,Pch,Plen)       UTCmemsets(UTCO_EOL,Ptgt,0,Pch,Plen)//~v600I~
	#define UTCmemsetP(Ptgt,Ppos,Pch,Plen)   UTCmemsets(0,Ptgt,Ppos,Pch,Plen)//~v600R~
	#define UTCmemsetEP(Ptgt,Ppos,Pch,Plen)  UTCmemsets(UTCO_EOL,Ptgt,Ppos,Pch,Plen)//~v600I~
	#define UTCmemsetA(Ptgt,Paddr,Pch,Plen)  UTCmemsets(UTCO_BYOFF,Ptgt,UTC_ADDR2OFFS(Paddr,Ptgt),Pch,Plen)//~v600R~
//memcpy                                                           //~v600R~
	char *UTCmemcpys(int Popt,PUTCHARS Ptgt,int Ptpos,PUTCHARS Psrc,int Pspos,UINT Plen);//~v600R~
	char *UTCmemcpyDs(int Popt,PUTCHARS Ptgt,int Ptpos,void *Psrc,UINT Plen);//~v600R~
	#define UTCmemcpyPD(Ptgt,Ptpos,Psrc,Plen)         UTCmemcpyDs(0,Ptgt,Ptpos,Psrc,Plen)//~v600R~
	#define UTCmemcpyPUD(Ptgt,Ptpos,Psrc,Plen)        UTCmemcpyDs(UTCO_CHOFGEN,Ptgt,Ptpos,Psrc,Plen)//~v60rI~
	#define UTCmemcpyPAD(Ptgt,Ptpos,Psrc,Plen)        UTCmemcpyDs(UTCO_ASCII,Ptgt,Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpy00(Ptgt,Psrc,Plen)               UTCmemcpys(0,Ptgt,0,Psrc,0,Plen)//~v600R~
	#define UTCmemcpyM00(Ptgt,Psrc,Plen)              UTCmemcpys(UTCO_EOLSTOP|UTCO_MAXWIDTH,Ptgt,0,Psrc,0,Plen)//~v618R~
	#define UTCmemcpy0P(Ptgt,Psrc,Pspos,Plen)         UTCmemcpys(0,Ptgt,0,Psrc,Pspos,Plen)//~v600R~
	#define UTCmemcpyPP(Ptgt,Ptpos,Psrc,Pspos,Plen)   UTCmemcpys(0,Ptgt,Ptpos,Psrc,Pspos,Plen)//~v600R~
	#define UTCmemcpyP0(Ptgt,Ptpos,Psrc,Plen)         UTCmemcpys(0,Ptgt,Ptpos,Psrc,0,Plen)//~v600I~
	#define UTCmemcpyMP0(Ptgt,Ptpos,Psrc,Plen)        UTCmemcpys(UTCO_EOLSTOP|UTCO_MAXWIDTH,Ptgt,Ptpos,Psrc,0,Plen)//~v618R~
	#define UTCmemcpy0D(Ptgt,Psrc,Plen)               UTCmemcpyDs(0,Ptgt,0,Psrc,Plen)//~v600R~
	#define UTCmemcpy0AD(Ptgt,Psrc,Plen)              UTCmemcpyDs(UTCO_ASCII,Ptgt,0,Psrc,Plen)//~v600I~
	#define UTCmemcpyAD(Ptgt,Paddr,Psrc,Plen)         UTCmemcpyDs(UTCO_BYOFF,Ptgt,UTC_ADDR2OFFS(Paddr,Ptgt),Psrc,Plen)//~v600R~
	#define UTCmemcpyEPP(Ptgt,Ptpos,Psrc,Pspos,Plen)  UTCmemcpys(UTCO_EOL,Ptgt,Ptpos,Psrc,Pspos,Plen)//~v600R~
	#define UTCmemcpyE00(Ptgt,Psrc,Plen)              UTCmemcpys(UTCO_EOL,Ptgt,0,Psrc,0,Plen)//~v600I~
	#define UTCmemcpyE0P(Ptgt,Psrc,Pspos,Plen)        UTCmemcpys(UTCO_EOL,Ptgt,0,Psrc,Pspos,Plen)//~v600I~
	#define UTCmemcpyEP0(Ptgt,Ptpos,Psrc,Plen)        UTCmemcpys(UTCO_EOL,Ptgt,Ptpos,Psrc,0,Plen)//~v600I~
	#define UTCmemcpyE0AD(Ptgt,Psrc,Plen)             UTCmemcpyDs(UTCO_ASCII|UTCO_EOL,Ptgt,0,Psrc,Plen)//~v600I~
	#define UTCmemcpyLSP0(Ptgt,Ptpos,Psrc,Plen)       UTCmemcpys(UTCO_SHIFTL,Ptgt,Ptpos,Psrc,0,Plen)//~v600R~
	#define UTCmemcpyLS0P(Ptgt,Psrc,Pspos,Plen)       UTCmemcpys(UTCO_SHIFTL,Ptgt,0,Psrc,Pspos,Plen)//~v600I~
	#define UTCmemcpyLSPP(Ptgt,Ptpos,Psrc,Pspos,Plen) UTCmemcpys(UTCO_SHIFTL,Ptgt,Ptpos,Psrc,Pspos,Plen)//~v600I~
//memmove                                                          //~v600R~
	char   *UTCmemmoves(int Popt,PUTCHARS Ptgt,int Ptpos,int Pspos,UINT Plen);//~v600R~
	#define UTCmemmovePP(Ptgt,Ptpos,Psrc,Pspos,Plen)   UTCmemmoves(0,Ptgt,Ptpos,Pspos,Plen)//~v600R~
	#define UTCmemmoveP0(Ptgt,Ptpos,Psrc,Plen)         UTCmemmoves(0,Ptgt,Ptpos,0,Plen)//~v600R~
	#define UTCmemmove00(Ptgt,Psrc,Plen)               UTCmemmoves(0,Ptgt,0,UTCCPOS(Psrc)-UTCCPOS(Ptgt),Plen)//~v600I~
	#define UTCmemmoveRSP0(Ptgt,Ptpos,Psrc,Plen)       UTCmemmoves(UTCO_SHIFTR,Ptgt,Ptpos,UTCCPOS(Psrc)-UTCCPOS(Ptgt),Plen)//~v600I~
//memshift                                                         //~v600R~
	char   *UTCmemshifts(int Popt,PUTCHARS Ptgt,int Ptpos,int Pspos,UINT Plen);//~v600R~
	#define UTCmemshiftL0P(Ptgt,Pspos,Plen)            UTCmemshifts(UTCO_SHIFTL,Ptgt,0,Pspos,Plen)//~v612R~
	#define UTCmemshiftLPP(Ptgt,Ptpos,Pspos,Plen)      UTCmemshifts(UTCO_SHIFTL,Ptgt,Ptpos,Pspos,Plen)//~v612R~
	#define UTCmemshiftLP0(Ptgt,Ptpos,Plen)            UTCmemshifts(UTCO_SHIFTL,Ptgt,Ptpos,0,Plen)//~v612R~
	#define UTCmemshiftLE0P(Ptgt,Pspos,Plen)           UTCmemshifts(UTCO_EOL|UTCO_SHIFTL,Ptgt,0,Pspos,Plen)//~v617R~
	#define UTCmemshiftLEPP(Ptgt,Ptpos,Pspos,Plen)     UTCmemshifts(UTCO_EOL|UTCO_SHIFTL,Ptgt,Ptpos,Pspos,Plen)//~v617R~
	#define UTCmemshiftRP0(Ptgt,Ptpos,Plen)            UTCmemshifts(UTCO_SHIFTR,Ptgt,Ptpos,0,Plen)//~v612R~
	#define UTCmemshiftRPP(Ptgt,Ptpos,Pspos,Plen)      UTCmemshifts(UTCO_SHIFTR,Ptgt,Ptpos,Pspos,Plen)//~v612R~
//strncpy                                                          //~v600I~
	char *UTCstrncpys(int Popt,PUTCHARS Ptgt,int Ptpos,PUTCHARS Psrc,int Pspos,UINT Plen);//~v600R~
	char *UTCstrncpyDs(int Popt,PUTCHARS Ptgt,int Ptpos,void *Psrc,UINT Plen);//~v600R~
	#define UTCstrncpyPP(Ptgt,Ptpos,Psrc,Pspos,Plen)      UTCstrncpys(0,Ptgt,Ptpos,Psrc,Pspos,Plen)//~v600R~
	#define UTCstrncpy0P(Ptgt,Psrc,Pspos,Plen)            UTCstrncpys(0,Ptgt,0,Psrc,Pspos,Plen)//~v600R~
	#define UTCstrncpy00(Ptgt,Psrc,Plen)                  UTCstrncpys(0,Ptgt,0,Psrc,0,Plen)//~v600I~
	#define UTCstrncpyP0(Ptgt,Ptpos,Psrc,Plen)            UTCstrncpys(0,Ptgt,Ptpos,Psrc,0,Plen)//~v600R~
	#define UTCstrncpyMP0(Ptgt,Ptpos,Psrc,Plen)           UTCstrncpys(UTCO_EOLSTOP|UTCO_MAXWIDTH,Ptgt,Ptpos,Psrc,0,Plen)//~v618R~
	#define UTCstrncpyPD(Ptgt,Ptpos,Psrc,Plen)            UTCstrncpyDs(0,Ptgt,Ptpos,Psrc,Plen)//~v600R~
	#define UTCstrncpy0D(Ptgt,Psrc,Plen)                  UTCstrncpyDs(0,Ptgt,0,Psrc,Plen)//~v600R~
	#define UTCstrncpyAD(Ptgt,Paddr,Psrc,Plen)            UTCstrncpyDs(UTCO_BYOFF,Ptgt,UTC_ADDR2OFFS(Paddr,Ptgt),Psrc,Plen)//~v600R~
	#define UTCstrncpyUAD(Ptgt,Paddr,Psrc,Plen)           UTCstrncpyDs(UTCO_BYOFF|UTCO_CHOFGEN,Ptgt,UTC_ADDR2OFFS(Paddr,Ptgt),Psrc,Plen)//~v61bI~
//memcmp                                                           //~v600I~
	int  UTCmemcmps(int Popt,PUTCHARS Ptgt,int Ptoff,PUTCHARS Psrc,int Psoff,UINT Plen);//~v600I~
	int  UTCmemcmpDs(int Popt,PUTCHARS Ptgt,int Ptpos,UCHAR * Psrc,UINT Plen);//~v600I~
	#define UTCmemcmp0D(Ptgt,Psrc,Plen)               UTCmemcmpDs(0,Ptgt,0,Psrc,Plen)//~v600R~
	#define UTCmemcmpPD(Ptgt,Ppos,Psrc,Plen)          UTCmemcmpDs(0,Ptgt,Ppos,Psrc,Plen)//~v600R~
	#define UTCmemcmpPAD(Ptgt,Ppos,Psrc,Plen)         UTCmemcmpDs(UTCO_ASCII,Ptgt,Ppos,Psrc,Plen)//~v61bI~
	#define UTCmemcmpPP(Ptgt,Ppost,Psrc,Pposs,Plen)   UTCmemcmps(0,Ptgt,Ppost,Psrc,Pposs,Plen)//~v600I~
	#define UTCmemcmp00(Ptgt,Psrc,Plen)               UTCmemcmps(0,Ptgt,0,Psrc,0,Plen)//~v600I~
	#define UTCmemcmpP0(Ptgt,Ppost,Psrc,Plen)         UTCmemcmps(0,Ptgt,Ppost,Psrc,0,Plen)//~v600I~
	#define UTCmemicmpPP(Ptgt,Ppost,Psrc,Pposs,Plen)  UTCmemcmps(UTCO_NOCASE,Ptgt,Ppost,Psrc,Pposs,Plen)//~v600I~
	#define UTCmemicmpP0(Ptgt,Ppost,Psrc,Plen)        UTCmemcmps(UTCO_NOCASE,Ptgt,Ppost,Psrc,0,Plen)//~v600I~
                                                                   //~v600I~
//addr inc/dec                                                     //~v600I~
    UCHAR  *UTCincdec(int Popt,PUTCHARS Pputcs,int Pcnt);          //~v600I~
    #define UTCinc(name,cnt)         UTCincdec(0,name,cnt)         //~v600R~
    #define UTCincO(name,offs)       UTCincdec(UTCO_BYOFF,name,offs)//~v600R~
    #define UTCinca(name)            UTCincdec(UTCO_AFT,name,1)    //~v61fR~
    #define UTCdeca(name)            UTCincdec(UTCO_AFT,name,-1)   //~v61fR~
    #define UTCdec(name,cnt)         UTCincdec(0,name,-cnt)        //~v600R~
                                                                   //~v600I~
//set structure                                                    //~v600I~
    PUTCHARS UTCsets(int Popt,PUTCHARS Pptgt,PUTCHARS Psrc,int Ppos);	//tgt=src,data+=pos//~v600I~
    PUTCHARS UTCsetLs(int Popt,PUTCHARS Pptgt,PUTCHARS Psrc,int Ppos,int Plenc);//~v600I~
    PUTCHARS UTCsetDs(int Popt,PUTCHARS Pptgt,UCHAR *Pdata,PCHOFTYPE Ppchof,int Pwidth);//~v600R~
    #define  UTCsetD(Ptgt,Pdata)                           UTCsetDs(0,Ptgt,Pdata,0,0)//~v600R~
    #define  UTCsetDC(Ptgt,Pdata,Pchof)                    UTCsetDs(0,Ptgt,Pdata,Pchof,0)//~v600R~
    #define  UTCsetDAL(Ptgt,Pdata,Pwidth)                  UTCsetDs(0,Ptgt,Pdata,UTCCHOFASCII,Pwidth)//~v60aR~
    #define  UTCsetDCL(Ptgt,Pdata,Pchof,Pwidth)            UTCsetDs(0,Ptgt,Pdata,Pchof,Pwidth)//~v600I~
    #define  UTCsetUDCL(Ptgt,Pdata,Pchof,Pwidth)           UTCsetDs(UTCO_CHOFGEN,Ptgt,Pdata,Pchof,Pwidth)//~v612R~
    #define  UTCset0(Ptgt,Psrc)                            UTCsets(0,Ptgt,Psrc,0)//~v600I~
    #define  UTCsetP(Ptgt,Psrc,Ppos)                       UTCsets(0,Ptgt,Psrc,Ppos)//~v600I~
    #define  UTCsetPL(Ptgt,Psrc,Ppos,Plenc)                UTCsetLs(0,Ptgt,Psrc,Ppos,Plenc)//~v600I~
    #define  UTCsetMP(Ptgt,Psrc,Ppos)                      UTCsets(0,Ptgt,Psrc,-Ppos)//~v600I~
//  #define  UTCreset(Ptgt)                                UTCresets(0,Ptgt)//~v600R~
                                                                   //~v600I~
//char comp                                                        //~v600I~
	int     UTCeqeqcs(int Popt,PUTCHARS Ptgt,int Ppos,int Pch);    //~v600I~
	#define UTCeqeq0C(Ptgt,Pch)              UTCeqeqcs(0,Ptgt,0,Pch)//~v600I~
	#define UTCeqeqPC(Ptgt,Ppos,Pch)         UTCeqeqcs(0,Ptgt,Ppos,Pch)//~v600I~
	#define UTCeqeqMPC(Ptgt,Ppos,Pch)        UTCeqeqcs(0,Ptgt,-Ppos,Pch)//~v600I~
	#define UTCnoteqPC(Ptgt,Ppos,Pch)        !UTCeqeqcs(0,Ptgt,Ppos,Pch)//~v600I~
	#define UTCnoteq0C(Ptgt,Pch)             !UTCeqeqcs(0,Ptgt,0,Pch)//~v600R~
	#define UTCnoteqMPC(Ptgt,Ppos,Pch)       !UTCeqeqcs(0,Ptgt,-Ppos,Pch)//~v600I~
                                                                   //~v600I~
	int     UTCeqeqs(int Popt,PUTCHARS Ptgt,int Ptpos,PUTCHARS Psrc,int Pspos);//~v600I~
	#define UTCeqeq00(Ptgt,Psrc)             UTCeqeqcs(0,Ptgt,0,Psrc,0)//~v600I~
	#define UTCnoteq00(Ptgt,Psrc)            !UTCeqeqs(0,Ptgt,0,Psrc,0)//~v600R~
//char get                                                         //~v600I~
	#define UTCgetPC(Ptgt,Ppos)              *(UTCDATA(Ptgt)+UTC_POS2OFFS(0,Ptgt,Ppos))//~v600R~
//ulib ustring                                                     //~v600M~
//umemspnc                                                         //~v600M~
    int  UTCumemspncs(int Popt,PUTCHARS Putchs,int Ppos,int Pch,UINT Plen);//~v600R~
    #define  UTCumemspncP(Psrc,Ppos,Pch,Plen)  UTCumemspncs(0,Psrc,Ppos,Pch,Plen)//~v600R~
    #define  UTCumemspnc0(Psrc,Pch,Plen)       UTCumemspncs(0,Psrc,0,Pch,Plen)//~v600R~
//umemrchr                                                         //~v600I~
    #define  UTCumemrchrP(Psrc,Ppos,Pch,Plen)    UTCmemchrs(UTCO_MEMR,Psrc,Ppos,Pch,Plen)//~v600I~
    #define  UTCumemrchr0(Psrc,Pch,Plen)         UTCmemchrs(UTCO_MEMR,Psrc,0,Pch,Plen)//~v600I~
//umemrspn                                                         //~v600I~
    int      UTCumemrspns(int Popt,PUTCHARS Putchs,int Ppos,UCHAR *Pstr,UINT Plen);//~v600I~
    #define  UTCumemrspnP(Psrc,Ppos,Pstr,Plen)   UTCumemrspns(0,Psrc,Ppos,Pstr,Plen)//~v600R~
    #define  UTCumemrspn0(Psrc,Pstr,Plen)        UTCumemrspns(0,Psrc,0,Pstr,Plen)//~v600R~
//umemrspnc                                                        //~v600R~
    int      UTCumemrspncs(int Popt,PUTCHARS Putchs,int Ppos,int Pch,UINT Plen);//~v600I~
    #define  UTCumemrspncP(Psrc,Ppos,Pch,Plen)    UTCumemrspncs(0,Psrc,Ppos,Pch,Plen)//~v600R~
    #define  UTCumemrspnc0(Psrc,Pch,Plen)         UTCumemrspncs(0,Psrc,0,Pch,Plen)//~v600R~
//ustrnspn                                                         //~v600I~
    size_t   UTCustrnspns(int Popt,PUTCHARS Putchs,int Ppos,char *Psrc,UINT Plen);//~v600I~
    #define  UTCustrnspnP(Ptgt,Ppos,Psrc,Plen)    UTCustrnspns(0,Ptgt,Ppos,Psrc,Plen)//~v600R~
    #define  UTCustrnspn0(Ptgt,Psrc,Plen)         UTCustrnspns(0,Ptgt,0,Psrc,Plen)//~v600R~
//******************************************************************************//~v600R~
#else     //!UTF8                                                  //~v600R~
//******************************************************************************//~v600I~
//assign char/utf-char                                             //~v600I~
    #define UTCeq0C(Ptgt,Pch)                *Ptgt=Pch             //~v600I~
    #define UTCeq0Cinca(Ptgt,Pch)            *Ptgt++=Pch           //~v600I~
    #define UTCeq0Cdeca(Ptgt,Pch)            *Ptgt--=Pch           //~v600I~
    #define UTCeqPC(Ptgt,Ppos,Pch)           *(Ptgt+Ppos)=Pch      //~v600I~
    #define UTCeqMPC(Ptgt,Ppos,Pch)          *(Ptgt-Ppos)=Pch      //~v600I~
    #define UTCeq00(Ptgt,Psrc)               *Ptgt=*Psrc           //~v600I~
    #define UTCeq00inca(Ptgt,Psrc)           *Ptgt++=*Psrc++       //~v600I~
    #define UTCeq00deca(Ptgt,Psrc)           *Ptgt--=*Psrc--       //~v600I~
    #define UTCeqPP(Ptgt,Ppost,Psrc,Pposs)   *(Ptgt+Ppost)=*(Psrc+Pposs)//~v600I~
    #define UTCeqP0(Ptgt,Ppost,Psrc)         *(Ptgt+Ppost)=*Psrc   //~v600I~
    #define UTCeqP0inca(Ptgt,Ppost,Psrc)     *(Ptgt+Ppost)=*Psrc++ //~v600I~
    #define UTCeqDP(Ptgt,Psrc,Ppos)          *Ptgt=*(Psrc+Ppos)    //~v600I~
    #define UTCeqD0(Ptgt,Psrc)               *Ptgt=*Psrc           //~v600I~
    #define UTCeqD0inca(Ptgt,Psrc)           *Ptgt++=*Psrc         //~v600I~
    #define UTCeqPD(Ptgt,Ppos,Psrc)          *(Ptgt+Ppos)=*Psrc    //~v600I~
                                                                   //~v600I~
    #define UTC_ADDR2OFFS(Paddr,Putch)         (ULONG)Paddr-(ULONG)UTCDATA(Putch)//~v600R~
    #define UTC_ADDR2POS(Paddr,Putch,byteoffs) UTC_ADDR2OFFS(Paddr,Putch)//~v600R~
//calc colum by offset                                             //~v600I~
    #define UTCwidth00(Ptgt,Psrc)             (ULONG)Ptgt-(ULONG)Psrc//~v600I~
    #define UTCwidth0D(Ptgt,Paddr)            (ULONG)Ptgt-(ULONG)Paddr//~v600I~
//strlen                                                           //~v600I~
	#define  UTCstrlen0(Ptgt)                 strlen(Ptgt)         //~v600I~
	#define  UTCstrlenP(Ptgt,Ppos)            strlen(Ptgt+Ppos)    //~v600I~
	#define  UTCstrlenD(Ptgt)                 strlen(Ptgt)         //~v600I~
	#define  UTCstrlenCHOF(Ptgt)              strlen(Ptgt)         //~v600I~
//memchr                                                           //~v600I~
	#define  UTCmemchr0(Ptgt,Pch,Plen)        memchr(Ptgt,Pch,Plen)//~v600I~
	#define  UTCmemchr0update(Ptgt,Pch,Plen)  Ptgt=memchr(Ptgt,Pch,Plen)//~v600R~
	#define  UTCmemchrP(Ptgt,Ppos,Pch,Plen)   memchr(Ptgt+Ppos,Pch,Plen)//~v600R~
//memset                                                           //~v600I~
	#define UTCmemset0(Ptgt,Pch,Plen)         memset(Ptgt,Pch,Plen)//~v600R~
	#define UTCmemsetE0(Ptgt,Pch,Plen)        memset(Ptgt,Pch,Plen)//~v600I~
	#define UTCmemsetP(Ptgt,Ppos,Pch,Plen)    memset(Ptgt+Ppos,Pch,Plen)//~v600I~
	#define UTCmemsetEP(Ptgt,Ppos,Pch,Plen)   memset(Ptgt+Ppos,Pch,Plen)//~v600I~
	#define UTCmemsetA(Ptgt,Paddr,Pch,Plen)   memset(Paddr,Pch,Plen)//~v600I~
//memcpy                                                           //~v600I~
	#define UTCmemcpyPD(Ptgt,Ptpos,Psrc,Plen)         memcpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpyPUD(Ptgt,Ptpos,Psrc,Plen)        memcpy(Ptgt+Ptpos,Psrc,Plen)//~v60rI~
	#define UTCmemcpyPAD(Ptgt,Ptpos,Psrc,Plen)        memcpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpy00(Ptgt,Psrc,Plen)               memcpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcpyM00(Ptgt,Psrc,Plen)              memcpy(Ptgt,Psrc,Plen)//~v618I~
	#define UTCmemcpy0P(Ptgt,Psrc,Pspos,Plen)         memcpy(Ptgt,Psrc+Pspos,Plen)//~v600I~
	#define UTCmemcpyPP(Ptgt,Ptpos,Psrc,Pspos,Plen)   memcpy(Ptgt+Ptpos,Psrc+Pspos,Plen)//~v600I~
	#define UTCmemcpyP0(Ptgt,Ptpos,Psrc,Plen)         memcpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpyMP0(Ptgt,Ptpos,Psrc,Plen)        memcpy(Ptgt+Ptpos,Psrc,Plen)//~v618I~
	#define UTCmemcpy0D(Ptgt,Psrc,Plen)               memcpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcpy0AD(Ptgt,Psrc,Plen)              memcpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcpyAD(Ptgt,Paddr,Psrc,Plen)         memcpy(Paddr,Psrc,Plen)//~v600I~
	#define UTCmemcpyEPP(Ptgt,Ptpos,Psrc,Pspos,Plen)  memcpy(Ptgt+Ptpos,Psrc+Pspos,Plen)//~v600I~
	#define UTCmemcpyE00(Ptgt,Psrc,Plen)              memcpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcpyE0P(Ptgt,Psrc,Pspos,Plen)        memcpy(Ptgt,Psrc+Pspos,Plen)//~v600I~
	#define UTCmemcpyEP0(Ptgt,Ptpos,Psrc,Plen)        memcpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpyE0AD(Ptgt,Psrc,Plen)             memcpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcpyLSP0(Ptgt,Ptpos,Psrc,Plen)       memcpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemcpyLS0P(Ptgt,Psrc,Pspos,Plen)       memcpy(Ptgt,Psrc+Pspos,Plen)//~v600I~
	#define UTCmemcpyLSPP(Ptgt,Ptpos,Psrc,Pspos,Plen) memcpy(Ptgt+Ptpos,Psrc+Pspos,Plen)//~v600I~
//memmove                                                          //~v600R~
	#define UTCmemmovePP(Ptgt,Ptpos,Psrc,Pspos,Plen)  memmove(Ptgt+Ptpos,Psrc+Pspos,Plen)//~v600R~
	#define UTCmemmoveP0(Ptgt,Ptpos,Psrc,Plen)        memmove(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCmemmove00(Ptgt,Psrc,Plen)              memmove(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemmoveRSP0(Ptgt,Ptpos,Psrc,Plen)      memmove(Ptgt+Ptpos,Psrc,Plen)//~v600R~
	#define UTCmemshiftRP0(Ptgt,Ptpos,Plen)           memmove(Ptgt+Ptpos,Ptgt,Plen)//~v612I~
	#define UTCmemshiftRPP(Ptgt,Ptpos,Pspos,Plen)     memmove(Ptgt+Ptpos,Ptgt+Pspos,Plen)//~v612I~
//memshiftL                                                        //~v600I~
	#define UTCmemshiftL0P(Ptgt,Pspos,Plen)           memcpy(Ptgt,Ptgt+Pspos,Plen)//~v600I~
	#define UTCmemshiftLPP(Ptgt,Ptpos,Pspos,Plen)     memcpy(Ptgt+Ptpos,Ptgt+Pspos,Plen)//~v600I~
	#define UTCmemshiftLP0(Ptgt,Ptpos,Plen)           memcpy(Ptgt+Ptpos,Ptgt,Plen)//~v600I~
	#define UTCmemshiftLE0P(Ptgt,Pspos,Plen)          memcpy(Ptgt,Ptgt+Pspos,Plen)//~v600I~
	#define UTCmemshiftLEPP(Ptgt,Ptpos,Pspos,Plen)    memcpy(Ptgt+Ptpos,Ptgt+Pspos,Plen)//~v600R~
//strncpy                                                          //~v600I~
	#define UTCstrncpyPP(Ptgt,Ptpos,Psrc,Pspos,Plen)  strncpy(Ptgt+Ptpos,Psrc+Pspos,Plen)//~v600I~
	#define UTCstrncpy0P(Ptgt,Psrc,Pspos,Plen)        strncpy(Ptgt,Psrc+Pspos,Plen)//~v600I~
	#define UTCstrncpy00(Ptgt,Psrc,Plen)              strncpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCstrncpyP0(Ptgt,Ptpos,Psrc,Plen)        strncpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCstrncpyMP0(Ptgt,Ptpos,Psrc,Plen)       strncpy(Ptgt+Ptpos,Psrc,Plen)//~v618I~
	#define UTCstrncpyPD(Ptgt,Ptpos,Psrc,Plen)        strncpy(Ptgt+Ptpos,Psrc,Plen)//~v600I~
	#define UTCstrncpy0D(Ptgt,Psrc,Plen)              strncpy(Ptgt,Psrc,Plen)//~v600I~
	#define UTCstrncpyAD(Ptgt,Paddr,Psrc,Plen)        strncpy(Paddr,Psrc,Plen)//~v600I~
	#define UTCstrncpyUAD(Ptgt,Paddr,Psrc,Plen)       strncpy(Paddr,Psrc,Plen)//~v61hI~
//memcmp                                                           //~v600I~
	#define UTCmemcmp0D(Ptgt,Psrc,Plen)               memcmp(Ptgt,Psrc,Plen)//~v600I~
	#define UTCmemcmpPD(Ptgt,Ppos,Psrc,Plen)          memcmp(Ptgt+Ppos,Psrc,Plen)//~v600R~
	#define UTCmemcmpPAD(Ptgt,Ppos,Psrc,Plen)         memcmp(Ptgt+Ppos,Psrc,Plen)//~v61hI~
	#define UTCmemcmpPP(Ptgt,Ppost,Psrc,Pposs,Plen)   memcmp(Ptgt+Ppost,Psrc+Pposs,Plen)//~v600I~
	#define UTCmemcmp00(Ptgt,Psrc,Plen)               memcmp(Ptgt,Psrc,Plen)//~v600R~
	#define UTCmemcmpP0(Ptgt,Ppost,Psrc,Plen)         memcmp(Ptgt+Ppost,Psrc,Plen)//~v600I~
	#define UTCmemicmpPP(Ptgt,Ppost,Psrc,Pposs,Plen)  memicmp(Ptgt+Ppost,Psrc+Pposs,Plen)//~v600I~
	#define UTCmemicmpP0(Ptgt,Ppost,Psrc,Plen)        memicmp(Ptgt+Ppost,Psrc,Plen)//~v600R~
                                                                   //~v600I~
//addr inc/dec                                                     //~v600I~
    #define UTCinc(name,cnt)                          name+=cnt    //~v600I~
    #define UTCincO(name,offs)                        name+=cnt    //~v600I~
    #define UTCinca(name)                             name++       //~v600I~
    #define UTCdeca(name)                             name--       //~v600I~
    #define UTCdec(name,cnt)                          name-=cnt    //~v600I~
                                                                   //~v600I~
//set structure                                                    //~v600I~
    #define  UTCsetD(Ptgt,Pdata)                      Ptgt=Pdata   //~v600I~
    #define  UTCsetDC(Ptgt,Pdata,Pchof)               Ptgt=Pdata   //~v600I~
    #define  UTCsetDAL(Ptgt,Pdata,Pwidth)             Ptgt=Pdata   //~v60aR~
    #define  UTCsetDCL(Ptgt,Pdata,Pchof,Pwidth)       Ptgt=Pdata   //~v600I~
    #define  UTCset0(Ptgt,Psrc)                       Ptgt=Psrc    //~v600I~
    #define  UTCsetP(Ptgt,Psrc,Ppos)                  Ptgt=Psrc+Ppos//~v600I~
    #define  UTCsetPL(Ptgt,Psrc,Ppos,Plenc)           Ptgt=Psrc+Ppos//~v600R~
    #define  UTCsetMP(Ptgt,Psrc,Ppos)                 Ptgt=Psrc-Ppos//~v600I~
                                                                   //~v600I~
//char comp                                                        //~v600I~
	#define UTCeqeq0C(Ptgt,Pch)                       *Ptgt==Pch   //~v600I~
	#define UTCeqeqPC(Ptgt,Ppos,Pch)                  *(Ptgt+Ppos)==Pch//~v600I~
	#define UTCeqeqMPC(Ptgt,Ppos,Pch)                 *(Ptgt-Ppos)==Pch//~v600R~
	#define UTCnoteqPC(Ptgt,Ppos,Pch)                 *(Ptgt+Ppos)!=Pch//~v600I~
	#define UTCnoteq0C(Ptgt,Pch)                      *Ptgt!=Pch   //~v600R~
	#define UTCnoteqMPC(Ptgt,Ppos,Pch)                *(Ptgt-Ppos)!=Pch//~v600I~
                                                                   //~v600I~
	#define UTCeqeq00(Ptgt,Psrc)                      *Ptgt==*Psrc //~v600I~
	#define UTCnoteq00(Ptgt,Psrc)                     *Ptgt!=*Psrc //~v600I~
//char get                                                         //~v600I~
	#define UTCgetPC(Ptgt,Ppos)                       *(Ptgt+Ppos) //~v600I~
//ulib ustring                                                     //~v600I~
//umemspnc                                                         //~v600I~
    #define  UTCumemspncP(Psrc,Ppos,Pch,Plen)         umemspnc(Psrc+Ppos,Pch,Plen)//~v600R~
    #define  UTCumemspnc0(Psrc,Pch,Plen)              umemspnc(Psrc,Pch,Plen)//~v600I~
//umemrchr                                                         //~v600I~
    #define  UTCumemrchrP(Psrc,Ppos,Pch,Plen)         umemrchr(Psrc+Ppos,Pch,Plen)//~v600I~
    #define  UTCumemrchr0(Psrc,Pch,Plen)              umemrchr(Psrc,Pch,Plen)//~v600I~
//umemrspn                                                         //~v600I~
    #define  UTCumemrspnP(Psrc,Ppos,Pstr,Plen)        umemrspn(Psrc+Ppos,Pstr,Plen)//~v600R~
    #define  UTCumemrspn0(Psrc,Pstr,Plen)             umemrspn(Psrc,Pstr,Plen)//~v600R~
//umemrspnc                                                        //~v600I~
    #define  UTCumemrspncP(Psrc,Ppos,Pch,Plen)        umemrspnc(Psrc+Ppos,Pch,Plen)//~v600R~
    #define  UTCumemrspnc0(Psrc,Pch,Plen)             umemrspnc(Psrc,Pch,Plen)//~v600R~
//ustrnspn                                                         //~v600I~
    #define  UTCustrnspnP(Ptgt,Ppos,Psrc,Plen)        ustrnspn(Ptgt+Ppos,Psrc,Plen)//~v600I~
    #define  UTCustrnspn0(Ptgt,Psrc,Plen)             ustrnspn(Ptgt,Psrc,Plen)//~v600I~
//******************************************************************************//~v600I~
#endif    //!UTF8                                                  //~v600R~
//******************************************************************************//~v600I~
//******************************************************************************//~v600I~
                                                                   //~v600I~
//#define UTF8ISASCII(ch)  ((ch)<128)                                //~v600I~//~v5nqR~
                                                                   //~v600I~
#ifdef UTF8SUPP                                                    //~v61bM~
#define  UTC_EXPLENBYREP(width)                 ((width)*(UTF8_MAXCHARSZ-1))     //max expand len by char replace//~v600R~
                                                                   //~v600I~
#define  UTC_POS2OFFS(Popt,Pputc,pos)           utfpos2offschof(Popt,Pputc,pos)//~v600R~
#define  UTC_POS2OFFSM(Pputc,pos,offs)          utfgetposoff(0,Pputc,pos,0,offs)//~v600I~
#define  UTC_POS2OFFSD(Popt,Psrc,pos)           UTCstrlens(Popt|UTCO_BYADDR|UTCO_MAXCOL|UTCO_UTFLEN,(PUTCHARS)(ULONG)(Psrc),pos)//~v60aR~
#define  UTC_POS2ADDR(Popt,Pputc,pos)           (Pputc->data+utfpos2offschof(Popt,Pputc,pos))//~v600R~
#define  UTC_POS2ADDROP(Popt,Pputc,pos)         (Pputc->data+utfpos2offschof(Popt,Pputc,pos))//~v600R~
#define  UTC_CHARLENBYCHOF(Pputc,pos)           (UTCOFFSCHOFFROMCPOS(Pputc,pos+1)-UTCOFFSCHOFFROMCPOS(Pputc,pos))//~v600I~
#define  UTC_SPAN2WIDTH(Popt,Pputc,offs1,offs2,byteoffs1,byteoffs2) \
                                                (UTC_OFFS2POS(Popt,Pputc,offs2,byteoffs2)-UTC_OFFS2POS(Popt,Pputc,offs1,byteoffs1))//~v600R~
#define  UTC_WIDTH2SPAN(Popt,Pputc,pos1,pos2) \
                                                (UTC_POS2OFFS(Popt,Pputc,pos2)-UTC_POS2OFFS(Popt,Pputc,pos1))//~v600R~
#define  UTC_OFFS2POS(Popt,Pputc,offs,byteoffs) utfoffs2poschof(Popt,Pputc,offs,byteoffs)//~v600R~
#define  UTC_OFFS2POSM(Pputc,offs,pos)          utfgetposoff(0,Pputc,offs,pos,0)//~v600I~
#define  UTC_GETCHOFVALUEEXP(Pputc,Ppos)  ( Pputc->cpos+Ppos==0                     \
                                        ? 0                                     \
                                        : (Pputc->cpos+Ppos <= Pputc->lenc      \
                                           ? *(Pputc->chof+Pputc->cpos+Ppos)    \
                                           : *(Pputc->chof+Pputc->lenc)+Ppos+Pputc->cpos-Pputc->lenc   \
                                          )      \
                                      )                            //~v600I~
                                                                   //~v600I~
#define UTC_SETUPCHOFP(Pputc,Ppos,Plen,Pplenc,Pplenutf) \
				utfsetchof(0,Pputc,Ppos,Plen,Pplenc,Pplenutf)      //~v600I~
#define UTC_SETUPCHOFO(Pputc,Ppos,Plen,Pplenc,Pplenutf) \
				utfsetchof(UTCO_BYLEN,Pputc,Ppos,Plen,Pplenc,Pplenutf)//~v600I~
#define UTC_SETUPCHOFOP(Pputc,Ppos,Plen,Pplenc,Pplenutf) \
				utfsetchof(UTCO_BYLEN|UTCO_MAXCOL,Pputc,Ppos,Plen,Pplenc,Pplenutf)//~v600I~
#define  UTC_CHOFCPY(tgt,src,cnt,diff)          \
		{                                       \
        	int iii;                            \
        	if (diff)                           \
                for (iii=(cnt);iii>0;iii--)     \
                {                               \
                    *tgt++=*src++ + (diff);     \
                }                               \
            else                                \
            {                                   \
            	memcpy(tgt,src,(cnt)*CHOFSZ);   \
                tgt+=(cnt);                     \
                src+=(cnt);                     \
            }                                   \
        }                                                          //~v600R~
#define  UTC_CHOFMOVE(tgt,src,cnt,diff)         \
		{                                       \
        	int iii;                            \
        	if (diff)                           \
                for (iii=(cnt)-1;iii>=0;iii--)  \
                {                               \
                    *(tgt+iii)=*(src+iii) + (diff);\
                }                               \
            else                                \
            {                                   \
            	memmove(tgt,src,(cnt)*CHOFSZ);  \
                tgt+=(cnt);                     \
                src+=(cnt);                     \
            }                                   \
        }                                                          //~v600I~
#define  UTC_CHOFSET(tgt,cnt,diff) \
		{                                \
        	int iii;                      \
			for (iii=0;iii<(cnt);iii++)       \
		    	*tgt++=diff+iii;          \
        }                                                          //~v600I~
#define  UTC_CHOFADJUST(tgt,cnt,diff) \
		{                                \
        	int iii;                      \
			for (iii=0;iii<(cnt);iii++)       \
		    	*tgt+++=diff;          \
        }                                                          //~v600I~
//******************************************************************************//~v600I~
#else	//!UTF8                                                    //~v600I~
//******************************************************************************//~v600I~
	#define  UTC_EXPLENBYREP(width)                 width          //~v600R~
	#define  UTC_POS2OFFS(Popt,Pputc,pos)           pos            //~v600I~
	#define  UTC_POS2OFFSM(Pputc,pos,offs)          pos            //~v600I~
	#define  UTC_POS2OFFSD(Popt,Psrc,pos)           pos            //~v60aR~
	#define  UTC_OFFS2POS(Popt,Pputc,offs,byteoffs) offs           //~v600I~
	#define  UTC_SPAN2WIDTH(Popt,Pputc,offs1,offs2,byteoffs1,byteoffs2) offs2-offs1//~v600R~
	#define  UTC_WIDTH2SPAN(Popt,Pputc,pos1,pos2)   pos2-pos1      //~v600I~
	#define  UTC_POS2ADDR(Popt,Pputc,pos)           Pputc+pos      //~v600I~
	#define  UTC_POS2ADDROP(Popt,Pputc,pos)         Pputc pos      //~v60aR~
	#define  UTC_OFFS2POSM(Pputc,offs,pos)          offs           //~v600I~
//******************************************************************************//~v600I~
#endif   //UTF8SUPP                                                //~v600R~
//******************************************************************************//~v600I~
//**************************************************************************
//**************************************************************************
//**************************************************************************
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8R~
//**************************************************************************//~v600I~
	#define UTCO_BYLEN            0x01	     //pos parm is column  //~v600R~
	#define UTCO_BYOFF            0x02        //len parm is column //~v600R~
	#define UTCO_CHOFGEN          0x04        //getposoff by mbr2wc if chof==0//~v60rR~
	#define UTCO_BYADDR           0x10        //len parm is column //~v600I~
	#define UTCO_SETEOS           0x20        //update len/width after operation//~v600R~
	#define UTCO_STRZ           0x0100       //data is strz        //~v600R~
	#define UTCO_NOBYTEOFFS     0x0200       //if the offset split utfchar,count column for each byte,if off return byteoffs//~v600R~
	#define UTCO_SETERRUTFRC    0x0400       //set rc when err utf detected at chof set//~v600R~
	#define UTCO_AFT            0x0800       //set rc when err utf detected at chof set//~v600R~
	#define UTCO_ASCII          0x1000       //data source is ascii only(UTCsetDA)//~v600R~
	#define UTCO_ERRBEYOND      0x2000       //err if pos is out of bound//~v600R~
	#define UTCO_EOLSTOP        0x4000       //offs<->pos ;return end pos/offs when offs>lenutf/pos>width//~v60rR~
                                             //strncpy/memcpy:upto srclenc by chof//~v618I~
	#define UTCO_BEYOND2        0x8000       //for right boundary of posoffscntlen//~v600I~
	#define UTCO_MAXWIDTH     0x010000       //target width limit by len parm//~v618I~
	#define UTCO_DBCSBACK     0x020000       //offs->pos ;return end pos when offs>lenutf//~v600R~
	#define UTCO_DBCSBACKOFFS 0x040000       //offs->pos ;no backstep but return offset//~v600I~
	#define UTCO_DBCSNEXT     0x080000       //offs->pos ;return end pos when offs>lenutf//~v600R~
	#define UTCO_UPDATE       0x100000       //memchar update cpos //~v600R~
//  #define UTCO_COLUMNCOUNT  0x100000       //utfmbr2wc returns not byte count but display column count//~v62UR~//~v6hHR~
	#define UTCO_KEEPRB       0x200000       //set chof;dont set next entry of right boundary//~v600R~
	#define UTCO_MAXCOL       0x400000       //set chof;max column limit//~v600R~
	#define UTCO_NOBEYONDCNT  0x800000       //dont set overflow cnt to byteoffset when over lrecl//~v600R~
	#define UTCO_NOCASE     0x01000000       //case insensitive compare//~v600R~
	#define UTCO_EOL        0x02000000       //memcpy;end of line(update lenc)//~v600I~
	#define UTCO_ALLOCCHOF  0x04000000       //malloc chof if not yet set//~v600I~
	#define UTCO_HEX        0x08000000       //no replace split dbcs 2nd byte by space//~v600R~
	#define UTCO_SHIFTL     0x10000000       //no replace split dbcs 2nd byte by space//~v600I~
	#define UTCO_SHIFTR     0x20000000       //no replace split dbcs 2nd byte by space//~v600I~
	#define UTCO_MEMR       0x20000000       //reverse search      //~v600I~
	#define UTCO_NOCHKLOCALE 0x40000000 //utfcvf2u->utfmb2wc no need chk locale code is printable//~v6b5I~
	#define UTCO_UTFLEN     0x80000000       //return utflen for UTCstrlens//~v60aI~
                                                                   //~v600R~
	#define UTCRC_NOCHOF     -1                                    //~v600R~
	#define UTCRC_OUTR       -2                                    //~v600R~
	#define UTCRC_EOLSTOP    -3                                    //~v618I~
	#define UTCRC_TGTASCII    1                                    //~v600R~
	#define UTCRC_DBCSSPLIT  0x01                                  //~v600M~
	#define UTCRC_ERRUTFCHAR 0x02                                  //~v600M~
	#define UTCRC_DBCSBACK   0x04  //pos2offs:offset is top of dbcs split//~v618R~
	#define UTCRC_DBCSNEXT   0x08  //pos2offs:offset is of next of dbcs//~v618I~
	#define UTCRC_NOENV      0x20 //not utf8 environment           //~v618I~
#endif //WCSUPP                                                    //~v5n8R~
#if defined(UTF8SUPP) || (defined(WCSUPP) && defined(UTF8SUPPH))		//for xe use utf rtn//~v5n4R~
	#ifdef  GLOBAL_UTF                                             //~v600M~
  		#define EXT_UTF                                            //~v600M~
  		#define INIT_UTF(value) =value                             //~v600M~
	#else                                                          //~v600M~
  		#define EXT_UTF extern                                     //~v600M~
  		#define INIT_UTF(value)                                    //~v600M~
	#endif                                                         //~v600M~
    #define UTF8MODE()   (Gulibutfmode & GULIBUTFMODEMASK)         //~v60rR~
    #define UTF8MODEENV()   (Gulibutfmode & GULIBUTFENV)   //env codeset is .UTF-8//~v61bI~
    #define UTF8MODEICONV()   ((Gulibutfmode & (GULIBUTFENV|GULIBMBICONV))!=0)   //use iconv for conversion//~v61gI~
    #define UTF8MODEICONVLOCALEINIT()   (UTF8MODEICONV() && (Gulibutfmode & GULIBLOCALEINIT))   //use iconv for conversion//~v5n0R~
    #define UTF8SETICONV()    Gulibutfmode|=GULIBMBICONV     //use iconv for conversion//~v61gI~
//*****************                                                //~v600M~
	EXT_UTF int GambigWidth;	//utfwcwidthsub rc , parm to apichk//~vbzzR~
	EXT_UTF ULONG GutfTestUcs;                                     //~vbzjR~
	EXT_UTF WUCS Gutfcombaltch;                                    //~v6EkR~
	EXT_UTF int Gutfrc;                                            //~v600I~
	EXT_UTF int Gulibutfmode;                                      //~v600M~
	#define GULIBUTFENV   0x01     //by env  var                   //~v600I~
	#define GULIBUTFFORCE 0x02     //force for test                //~v600I~
	#define GULIBUTFMODEMASK 0x00ff  //kbd input may utf8          //~v60rI~
	#define GULIBUTFCHKBYCVL 0x0100  //utf printable chk by conversion to locale//~v60fR~
	#define GULIBUTFFROMEUC  0x0200  //forced to utf from EUC      //~v60mI~
	#define GULIBMBICONV     0x0400  //forced to use iconv under not UTF8 env//~v61gI~
	#define GULIBLOCALEINIT  0x0800  //iconv init end              //~v5n0I~
	#define GULIBSETLOCALERR 0x1000  //setlocale failed for locale.charset//~v633I~
    #define GULIBUTFMODE_NOTRACEMAPINIT 0x2000 //Test option of skipping utrace while mapinit//~vbzuI~
    #define GULIBUTFMODE_AMBIGLANG      0x4000 //chk glyph width fo ambiguous_langs//~vbzyI~
#ifdef UTF8UCS2                                                    //~v640I~
	#define GULIBSETUCS2MAP  0x010000  //map for utfwcwidth was initialized//~v640I~
	#define GULIBUTFCOMBINE  0x020000  //combine mode for combining diacritical marks(u-0300->u036f)//~v650I~
	#define GULIBUTFLIGATURE 0x040000  //ligature mode             //~v650I~
    #define UTF_COMBINEMODE() (Gulibutfmode & GULIBUTFCOMBINE)     //~v650I~
    #define UTF_COMBINEMODE_NP() (Gulibutfmode & GULIBUTFCOMBINE_NP)//~v6EkI~
    #define UTF_LIGATUREMODE() (Gulibutfmode & GULIBUTFLIGATURE)   //~v650I~
    #define UTF_SET_LIGATUREMODE() (Gulibutfmode|=GULIBUTFLIGATURE)//~v650I~
    #define UTF_RESET_LIGATUREMODE() (Gulibutfmode&=~GULIBUTFLIGATURE)//~v650I~
//#ifdef UTF8UCS4                                                  //~v65cI~//~v6uBR~
  #ifdef UTF8UCS416                                                //~v6uBI~
	#define GULIBUTFUCS4     0x080000  //ucs4 support              //~v65cI~
    #define UTF_UCS4MODE() ((Gulibutfmide & GULIBUTFUCS4)!=0)      //~v65cR~
  #endif                                                           //~v65cI~
	#define GULIBUTFSBCSIDOVF    0x00100000  //mapinit SBCSid overflow//~v67ZM~
	#define GULIBUTFSBCSIDREMAP  0x00200000  //mapinit SBCSid overflow//~v67ZM~
	#define GULIBUTF_JAVAWCWIDTH 0x00400000  //char width(sbcs or dbcs) determined not by mk_wcwidth() but by Java wcwidth()//~v6c5R~
#endif                                                             //~v640I~
//  #define GULIBUTF_WINSURROGATE 0x00800000  //parm to uccvutf2ucs; set surrogate pare for ucs4(>0x10000)//~v6r4I~//~v6uBR~
    #define GULIBUTF_NOFPATHCONV  0x00800000  //bypass iocharset check for ufullpathCP//~v6B9I~
	#define GULIBUTFCOMBINE_NP    0x01000000  //altch mode         //~v6EkI~
	#define GULIBUTFAPIWIDTH0     0x02000000  //accept wcwidth()=0 for not on utf4:combine tbl//~v6V1I~
	#define GULIBUTF_CJK          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
#ifdef W32                                                         //~v796I~
  #ifndef WXE                                                      //~v796I~
	#define GULIBUTF_APICHK_CSR   0x08000000  //utfwcwidth chr cursor step//~v796I~
  #else                                                            //~vbz4I~
	#define GULIBUTF_APICHK_CSR   0x08000000  //utfwcwidth chk cursor step//~vbz4R~
	#define GULIBUTF_APICHK_CSR2  0x10000000  //utfwcwidth chk cursor after HDC//~vbz4I~
  #endif                                                           //~v796I~
#else                                                              //~vbz5I~
//#ifdef XXE                                                       //~vbz5I~//~v79ER~
	#define GULIBUTF_APICHK_CSR   0x08000000  //utfwcwidth chk cursor step//~vbz5I~
	#define GULIBUTF_APICHK_CSR2  0x10000000  //utfwcwidth chk cursor after HDC//~vbz5I~
//#endif                                                           //~vbz5I~//~v79ER~
#endif                                                             //~v796I~
	#define GULIBUTF_ADJUST_TBL   0x20000000  //width adjust by tbl//~vbzjI~
	#define GULIBUTF_CSRSTEP      0x40000000  //width by cursor step//~v7a7I~
#define UTF_ADJUSTMODE()     ((Gulibutfmode & GULIBUTF_ADJUST_TBL)!=0)  //adjust char display width by table definition//~vbzjI~
#define UTF_ADJUSTMODE_ON()     Gulibutfmode |= GULIBUTF_ADJUST_TBL//~v7a0I~
#define UTF_ADJUSTMODE_OFF()     Gulibutfmode &= ~GULIBUTF_ADJUST_TBL//~v7a0I~
#define UTF_AMBIG2CELLMODE() ((Gulibutfmode & GULIBUTF_APICHK_CSR)==0)  //draw ambiguous by 2 cell if csrchk off//~vbzjI~
//**************************************************************************//~v600I~
	#define UTF_INIT(opt) utf_init(opt);                           //~v600I~
	int  utf_init(int Popt);                                       //~v600I~
	#define UTFIO_FORCE      0x01                                  //~v600I~
	#define UTFIO_RESET      0x02                                  //~v600I~
	#define UTFIO_FORCE_ENG  0x04                                  //~v60aI~
#endif //WCSUPP                                                    //~v5n0I~
#ifdef UTF8SUPPH                                                   //~v620I~
	#define UTFCT_UTF8       0x01  //codetype:utf8                 //~v620I~
	#define UTFCT_UTF8SUBC   0x04  //codetype:utf8                 //~v6r4I~
	int utfpos2offs(int Popt,char *Putf8,char *Pdbcs,char *Pcodetype,int Ppos,int Putf8len,int *Ppoffs);//~v620R~
#endif                                                             //~v620I~
#ifdef UTF8SUPP                                                    //~v5n0I~
//******************************************************           //~v600M~
int utfpos2offschof(int Popt,PUTCHARS Pputcs,int Ppos);            //~v600I~
#define UTCO2_ERR0   0x01    // return 0 if err                    //~v600R~
//******************************************************           //~v600I~
int utfoffs2poschof(int Popt,PUTCHARS Pputcs,int Poffs,int *Ppbyteoffs);//~v600I~
//******************************************************           //~v600I~
int utfisdbcssplit(int Popt,PUTCHARS Pputcs,int Ppso);             //~v600I~
//******************************************************           //~v600I~
#endif   //UTF8SUPP                                                //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
    #ifndef COMPCHKXE_NOUTF8      //-DCOMPCHKXE_NOUTF8 at xeu if not UTF8SUPP//~v5npR~
int utfiswide(int Popt,ULONG Pucs);                                //~v600I~
//******************************************************           //~v600I~
int utfisprint(int Popt,ULONG Pucs);                               //~v600I~
//******************************************************           //~v600I~
int utfmb2wc(int Popt,UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Ppreadlen,int *Ppwidth);//~v600R~
//******************************************************           //~v600I~
#ifndef UTF8SUPPH                                                  //~v62XR~
int utfwcwidth(ULONG Pucs);                                      //~v62UR~//~v62XR~
#else                                                              //~v62XI~
int utfwcwidth(int Popt,ULONG Pucs,int *Ppflag);                   //~v62UR~
int utfwcwidthNoMap(int Popt,ULONG Pucs,int *Ppflag);              //~v6V4I~
#ifdef UTF8UCS2                                                    //~v640I~
	#define UTFWWO_APILAST   0x01     //use api at last            //~v640R~
	#define UTFWWO_NOCJKU    0x02     //user adjust tbl            //~v640R~
	#define UTFWWO_NOMKCJK   0x04     //no use mk_wcwidth_cjk      //~v640R~
	#define UTFWWO_NOMK      0x08     //no use mk_wcwidth,mk_wcwidth_cjk//~v640R~
	#define UTFWWO_NOJ       0x10     //no use japanese tbl for euc/sjis//~v640R~
    #define UTFWWO_UTF8UCS2  0x20     //for utf8 ucs2 full support //~v640I~
    #define UTFWWO_NOMAPUSE  0x40     //no map use                 //~v640I~
    #define UTFWWO_APICHK    0x80     //set rc if len!=wcwidth     //~v640I~
	#define UTFWWO_APIONLY   0x0100   //use api only               //~v640I~
	#define UTFWWO_APICHK4   0x0200   //set unprintable by wcwidth for ucs4//~v65cI~
	#define UTFWWO_ADJSBCS   0x0400   //to avoid sbcstbl overflow,chk dbcs tbl after unprintable chk by wcwidth//~v6c5R~
	#define UTFWWO_APIW0     0x0800   //for ARM ignore mkwidth when wcwidth()=0//~v6c5I~
	#define UTFWWO_MK_WCWIDTH 0x1000   //by mk_wcwidth() adjustable by wcwidth()//~v6V7I~
	#define UTFWWO_MK_AMBIGUOUS 0x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6V7I~
//	#define UTFWWO_MK_COMB      0x4000   //defined as combining char at utf4.c//~v6W9I~//~v6WmR~
	#define UTFWWO_FORMAT       0x8000   //defined as Format    char at utf4.c//~v6WiI~
#endif                                                             //~v640I~
#endif                                                             //~v62XI~
#define UTFWWF_F2C1     0x80   //WideSBCS; font width=2,distance to next column=1//~v62UR~//~v640R~
#define UTFWWF_F1C1     0x40   //NarrowDBCS;multibyte but,font width=1,curses width=1//~v62UR~//~v640R~
#define UTFWWF_AMBDBCS  0x20   //ambiguous mbcslen=2 and glyph width=2//~v7acI~
#define UTFWWF_WIDTH0   0x08   //wcwidth=0                         //~v650I~
//#ifdef UTF8UCS4                                                    //~v65cR~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
#define UTFWWF_SBCSOVF  0x04   //sbcsid tbl overflow sbcsUCS or UCS over 0x00040000//~v65cI~
#endif                                                             //~v65cI~
//#define UTFWWF_FLAGMASK 0xffffffcc   //1100.1100                   //~v62UR~//~v6V7R~
#define UTFWWF_FLAGMASK      0x00ffffcc   //1100.1100              //~v6V7I~
#define UTFWWF_SCM           0x00001000   //unicode:Spacing Combining Mark//~v6VbI~
#define UTFWWF_SBCSF         0x00002000   //ignore wcwidth()=2 and force width=1//~v6WkI~
#define UTFWWF_COMB          0x00004000   //defined combining char //~v6WmI~
#define UTFWWF_COMB2SCM      0x00008000   //combining but trate as SCM//~v6XOI~
#define UTFWWF_RC_MK_WCWIDTH 0x01000000   //datatype by mk_wcwidth //~v6V7I~
//#define UTFWWF_RC_MK_COMB    0x02000000   //defied as combining    //~v6W9I~//~v6WmR~
#define UTFWWF_RC_FORMAT     0x04000000   //category Cf            //~v6WiI~
#define UTFWWF_RC_AMBIGLANG  0x08000000   //found on ambiguous_langs tbl//~vbzzR~
#define UTFWWF_RC_MASK       0xff000000                            //~v6V7I~
#define UTFWWF_LENMASK  0x03         //0000.0011                   //~v62UR~
    #endif //COMPCHKXE_NOUTF8                                      //~v5npR~
#endif //WCSUPP                                                    //~v5n0I~
#ifdef UTF8SUPP                                                    //~v5n0I~
//******************************************************           //~v600M~
int utfsetchof(int Popt,                                           //~v600M~
				PUTCHARS Pputc,		//data and chof and lenc       //~v600M~
				int Ppos,           //start column                 //~v600M~
				int Plen,           //lenutf or lenc               //~v600M~
				int *Pplenc,        //setup column                 //~v600M~
				int *Pplenutf);      //chked data lenutf           //~v600M~
//******************************************************           //~v60aI~
int UTCsetdbcstbl(int Popt,PUTCHARS Pputc,UCHAR *Ppdbcs,UINT Plenutf);//~v618I~
//******************************************************           //~v618I~
#endif   //UTF8SUPP                                                //~v5n8I~
#ifdef WCSUPP                                                      //~v5n8I~
    #ifndef COMPCHKXE_NOUTF8      //-DCOMPCHKXE_NOUTF8 at xeu if not UTF8SUPP//~v5npI~
int utfsetdbcstbl(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,PCHOFTYPE Ppchof,int Putflen,int *Ppwidth,int *Ppucscnt);//~v618R~
#define UTFSDTRC_DBCS     0x01     //dbcs detected                 //~v618I~
#define UTFSDTRC_NONSPACE 0x02     //nonspace char detected        //~v618I~
#define UTFSDTRC_ERRUTF   0x04     //invalid utf8  detected        //~v618I~
    #endif //COMPCHKXE_NOUTF8                                      //~v5npR~
#endif //WCSUPP                                                    //~v5n8I~
//#ifdef UTF8SUPP                                                    //~v5n8I~//~v640R~
#ifdef UTF8UCS2                                                    //~v640I~//~v650R~
//******************************************************           //~v600I~
int utftbinit(char *Ppfnm);                                        //~v600I~
//******************************************************           //~v600I~
int utftbterm(void);                                               //~v600I~
#endif                                                             //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8R~
//*******************************************************************//~v600R~
#define UTFCVO_EOLSPLITOK      0x01  //allow last char cut by length//~v61bR~
#define UTFCVO_ASCIIRET        0x02      //return if ascii detected//~v61bR~
#define UTFCVO_STRZ            0x04                                //~v61bR~
#define UTFCVO_ERRRET          0x08                                //~v61bR~
#define UTFCVO_ERRREP          0x10                                //~v61bR~
#define UTFCVO_2UTF            0x20          //locale to utf8(open opetion)//~v61gR~
#define UTFCVO_TCLOSE          0x40          //close required      //~v61gI~
#define UTFCVO_UTF8RET         0x80          //return utf8 detected with l2f err//~v62tR~
#define UTFCVO_REPCH         0xff00                                //~v61bI~
#define UTFCVO_SETTABCHAR  0x010000          //set dbcstbl for tabchar//~v69zI~
#define UTFCVO_OUTWIDTH    0x020000          //f2dd;return chklen if outarea overflow//~v6btI~
#define UTFCVO_BUFFSZPARM  0x040000          //outlen parm contains outbuff size to protect buff overflow//~v6hGI~
#define UTFCVO_CHKLCWIDTH  0x080000          //chk ddwidth and lcwidth,if err rep by errch//~v6t1I~
#define UTFCVO_ERRREPDBCS  0x100000          //set dbcs subchar for f2l err//~v6T4I~
//#ifdef W32                                                         //~v6ueI~//~v6uBR~
//#define UTFCVO_UCS4W       0x100000          //parm type is WUCS but data is ULONG//~v6ueI~//~v6uBR~
//#endif                                                             //~v6ueI~//~v6uBR~
#ifdef W32UNICODE                                                  //~v6unI~
#define UTFCVO_ALLOWSUBCH  0x200000          //continue even if rep to subch//~v6unR~
#endif                                                             //~v6unI~
#define UTFCVO_WIDTH0RC    0x400000          //notify on rcif width0//~v70gI~
                                                                   //~v61bM~
#define UTFCVRC_ALLASCII 0x01         //dbcs found                 //~v61bI~
#define UTFCVRC_DBCS     0x02         //dbcs found                 //~v61bI~
#define UTFCVRC_KANA     0x04         //EUC hankana found          //~v61bI~
#define UTFCVRC_ASCIIRET 0x08         //EUC hankana found          //~v61bI~
#define UTFCVRC_UTF8RET  0x10         //EUC hankana found          //~v62tI~
#define UTFCVRC_WIDTH0   0x20         //contains Width=0 char      //~v70gI~
//#define UTFCVRC_ERR      0x10         //err                      //~v62tR~
//#define UTFCVRC_ERRSTOP  0x20         //err                      //~v62tR~
//#define UTFCVRC_ERROVF   0x40         //outbuff ovf(for any1)    //~v62tR~
#define UTFCVRC_ERR      0x0100        //err                       //~v62tI~
#define UTFCVRC_ERRSTOP  0x0200        //err                       //~v62tI~
#define UTFCVRC_ERROVF   0x0400        //outbuff ovf(for any1)     //~v62tI~
#define UTFCVRC_SEVERR   0x1000       //sevear err(dont use return info)//~v61bI~
//*******************************************************************//~v61bI~
    #ifndef COMPCHKXE_NOUTF8      //-DCOMPCHKXE_NOUTF8 at xeu if not UTF8SUPP//~v5npI~
//int utfcvf2u(int Popt,USHORT *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Pppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth);//~v61bR~//~v692R~
//int utfcvf2u(int Popt,WUCS *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Pppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth);//~v692I~//~v6BjR~
int utfcvf2u(int Popt,UWUCS *Ppoutc,UCHAR *Ppdata,PCHOFTYPE Pppchof,UCHAR *Ppdbcs,int Pinitoffs,int Putflen,int *Ppreadlen,int *Ppucscnt,int *Ppwidth);//~v6BjI~
#define UTFF2U_SBCS 0x01         //return code                     //~v61bM~
#define UTFF2U_DBCS 0x02                                           //~v61bM~
#define UTFF2U_ASCII 0x04         //stop by ascii chk              //~v61bM~
#define UTFF2U_ERRP 0x80         //utf8 err char,replaced by repch //~v61bM~
#define UTFF2U_ERRU 0x40         //utf8 err char,replaced by repch //~v61bM~
#define UTFF2U_ERRS 0x20         //sbcs replaced by repch          //~v61bM~
#define UTFF2U_ERR0 0x10         //width=0                         //~v61bM~
#define UTFF2U_ERRRC 0x0100      //some err                        //~v61bR~
//*******************************************************************//~v61bI~
#ifdef UTF8SUPPH                                                   //~v62XI~
int utfcvf2l1(int Popt,char *Pinp,int Plen,int *Ppchklen);         //~v62tR~
#define UTFCVF2L1O_MULT       0x01      //search up to end         //~v62tI~
#endif                                                             //~v62XI~
//*******************************************************************//~v62tI~
int utfcvf2l(int Popt,char *Pout,char *Pinp,int Pinplen,           //~v61bR~
			int *Ppchklen,int *Ppoutlen,int *Ppcharwidth);         //~v61bR~
//*******************************************************************//~v60dM~
int utfcvl2f(int Popt,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v61bI~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v61bI~
#ifdef UTF8UCS2                                                    //~v645I~
//#ifdef AAA //no user                                               //~v6uBI~//~v7a4R~
int utfcvl2u(int Popt,char *Pinp,int Pinplen,char *Poutbuff,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~v645R~
//#endif  //AAA                                                      //~v6uBI~//~v7a4R~
#endif                                                             //~v645I~
#ifdef W32                                                         //~v7a5I~
int utfcvu2lmb(ULONG Popt,UWCHART *Pibuff,int Pinpctr,UCHAR *Pobuff,int Pobufflen,//~v7a5R~
				int *Ppchkctr,int *Ppoutlen,int *Pprepctr);        //~v7a5R~
#endif                                                             //~v7a5I~
int utfcvl2ftab(int Popt,char *Poututf8,char *Pinp,char *Pinpdbcs,int Pinplen,//~v69zI~
			char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v69zI~
#ifdef UTF8SUPPH                                                   //~v62tI~
//*******************************************************************//~v62tI~
int utfcvl2fmix(int Popt,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v62tI~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v62tR~
#endif                                                             //~v60dI~//~v62tR~
//*******************************************************************//~v61bI~
int utfcvl2fany(int Popt,char *Pplocale,char *Poututf8,char *Pinp,int Pinitoffs,int Pinplen,//~v61bR~
			PCHOFTYPE Pchof,char *Pdbcs,                           //~v61bI~
			int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v61bI~
//*******************************************************************//~v61gI~
//int utfcvl2fany1(int Popt,char *Pplocale,ULONG *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v61gR~//~v6hhR~
int utfcvl2fany1(int Popt,char *Pplocale,ULPTR *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6hhI~
			int *Ppchklen,int *Ppoutlen);                          //~v61gI~
//*******************************************************************//~v61bI~
int utfcvf2lany(int Popt,char *Pplocale,char *Pout,char *Pinp,int Pinplen,//~v61bI~
			int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v61bI~
//*******************************************************************//~v61gI~
//int utfcvf2lany1(int Popt,char *Pplocale,ULONG *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5R~
int utfcvf2lany1(int Popt,char *Pplocale,ULPTR *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5I~
			int *Ppchklen,int *Ppoutlen);                          //~v61gI~
//*******************************************************************//~v60dM~
int utfcve2f(int Popt,char *Poututf8,char *Pinpeuc,int Pinitoffs,int Pinplen,//~v61bI~
			PCHOFTYPE Pchof,char *Pdbcs,int *Ppchklen,int *Ppoutlen,int *Ppcharcnt,int *Ppcharwidth);//~v61bI~
//*******************************************************************//~v60dI~
//int utfisvalidutf8(int Popt,char *Pstr,int Plen);                //~v612R~
int utfisvalidutf8(int Popt,char *Pstr,int Plen,char *Ppdbcs,PCHOFTYPE Ppchof,int *Ppreadlen,int *Ppcharcnt,int *Ppcharwidth);//~v618R~
#define UTFIVURC_VALIDUTF    1         //valid utf and ascii       //~v618I~//~v6r4R~
#define UTFIVURC_ALLASCII    2         //all ascii                 //~v618I~
#define UTFIVURC_ASCIIRET    3         //breaked by ascii deetcted //~v618I~
//*******************************************************************//~v5neR~
int utfgetstrwidth(int Popt,char *Pstr,int Plen,int *Ppcharwidth,int *Pplenutf);//~v5neR~
//*******************************************************************//~v618I~
int utfisvalidutf8char(int Popt,char *Pstr,int Plen,int *Ppchklen,int *Ppcharwidth);//~v617I~
//*******************************************************************//~v618I~
int utfgetutf8str(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Ppdbcs,PCHOFTYPE Ppchof,int *Ppreadlen,int *Pputflen,int *Ppcharwidth);//~v618R~
#define UTFGUSO_REPCH     0xff00                                   //~v618I~
#define UTFGUSO_OUTSTRZ   0x0001    //set strz for output when conversion occured//~v618R~
#define UTFGUSO_EOLSPLIT  0x0002    //allow insufficiant at end of line//~v618I~
#define UTFGUSO_ASCIIRET  0x0004    //break reached to ascii       //~v618I~
#define UTFGUSO_NOLOCALEDBCSTB 0x0008 //no need to dbcstb set for locale str//~v61aR~
#ifdef UTF8SUPPH                                                   //~v620I~
#define UTFGUSO_CVF2L          0x0010 //convert utf8 to locale codepage//~v620R~
#define UTFGUSO_NOL2F          0x0020 //no conversion locale to utf8//~v620I~
#endif                                                             //~v620I~
                                                                   //~v618I~
#define UTFGUSRC_ALLASCII    0                                     //~v618I~
#define UTFGUSRC_ALLUTF8     1                                     //~v618I~
#define UTFGUSRC_LCOK        2                                     //~v618I~
#define UTFGUSRC_ASCIIRETU8  4                                     //~v618R~
#define UTFGUSRC_ASCIIRETLC  8                                     //~v618I~
#define UTFGUSRC_LCERR      20                                     //~v618R~
//*******************************************************************//~v5neR~//~v620I~
#ifdef UTF8SUPPH                                                   //~v620I~
	int utfgetutf8strlen(int Popt,char *Pstr,int Plen,int *Ppcharcnt);//~v620I~
    #define UGU8LO_LIMIT_UCSCOUNT       0x01  //get offset by ucscount//~v62pI~
	int utfsplitchk(int Popt,char *Pstr,int Plen,int *Putf8len,int *Pperrctr);//~v620I~
#endif                                                             //~v620I~
//**************************************************************** //~v61aI~
int utfcvl2fany1mb(int Popt,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v61gI~
			int *Ppchklen,int *Ppoutlen);                          //~v61gI~
//**************************************************************** //~v61gI~
int utfcvf2lany1mb(int Popt,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v61gI~
			int *Ppchklen,int *Ppoutlen);                          //~v61gI~
    #endif //COMPCHKXE_NOUTF8                                      //~v5npR~
#endif                                                             //~v5n0I~
#if defined(UTF8SUPP) || (defined(WCSUPP) && defined(UTF8SUPPH))		//for xe use utf rtn//~v5n4I~
//**************************************************************** //~v61bI~
	int utfcvlocaleinit(int Popt,char *Pplocale);                  //~v61bI~
	#define UTFCLIO_INI               0x01 //set from ini file     //~v61bR~
	#define UTFCLIO_NULLCHKONLY       0x02 //no close handle       //~v61bI~
	#define UTFCLIO_DEFAULTCHK        0x04 //at xeutf_init,set default//~v61bI~
	#define UTFCLIO_DEFAULTMSG        0x08 //display default       //~v61bI~
#endif //WCSUPP                                                    //~v5n0I~
#ifdef UTF8SUPPH  		//for xe use utf rtn                       //~v620I~
//  int utfcvu2lany1mb(int Popt,wchar_t Pucs,UCHAR *Pmbstr,int *Ppmbstrlen);//~v620I~//~v6a0R~
//  int utfcvu2lany1mb(int Popt,UWCHART Pucs,UCHAR *Pmbstr,int *Ppmbstrlen);//~v6a0I~//~v6BjR~
    int utfcvu2lany1mb(int Popt,UWUCS/*UINT4*/Pucs,UCHAR *Pmbstr,int *Ppmbstrlen);//~v6BjI~
#endif                                                             //~v620I~
#ifdef UTF8SUPPH                                                   //~v6hsI~
	#ifdef LNX                                                     //~v6hsI~
		int utflocalechk(int Popt,char *Pplocale);                 //~v6hsI~
		int utfcviconvdbcschk_topbyte(int Popt,UCHAR Pchar,UCHAR *Pputf,int *Pputflen);//~v6hsI~
		int utfcviconvdbcschk1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs);//~v6hsI~
		int utfcvlocaletclose(int Popt,ULONG Phiconv);             //~v6hsI~
	#endif                                                         //~v6hsI~
#endif                                                             //~v6hsI~
                                                                   //~v6hsI~
#ifdef UTF8SUPP                                                    //~v5n0I~
#ifdef LNX                                                         //~v61bM~
//*******************************************************************//~v61bM~
	int utflocalechk(int Popt,char *Pplocale);                     //~v61bR~
//*******************************************************************//~v61bI~
//  int utfcviconvdbcschk_topbyte(int Popt,UCHAR Pchar);           //~v61hR~
	int utfcviconvdbcschk_topbyte(int Popt,UCHAR Pchar,UCHAR *Pputf,int *Pputflen);//~v61hI~
//*******************************************************************//~v61bI~
//  int utfcviconvdbcschk1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen);//~v61hR~
	int utfcviconvdbcschk1(int Popt,UCHAR *Pstr,int Plen,int *Ppreadlen,ULONG *Ppucs);//~v61hI~
//*******************************************************************//~v61gI~
	int utfcvlocaletclose(int Popt,ULONG Phiconv);                 //~v61gR~
#endif                                                             //~v61bR~
//*******************************************************************//~v61aI~
#else //!UTF8                                                      //~v600I~
//*******************************************************************
#if defined(UTF8SUPP) || (defined(WCSUPP) && defined(UTF8SUPPH))		//for xe use utf rtn//~v5n4I~
#else                                                              //~v5n0I~
	#define UTF_INIT(opt)                                          //~v600I~
#endif                                                             //~v5n0I~
//**************************************************************************//~v600I~
//**************************************************************************//~v60aM~
#endif //!UTF8                                                     //~v600I~
#if defined(UTF8SUPP) || (defined(WCSUPP) && defined(UTF8SUPPH))		//for xe use utf rtn//~v5n4I~
	char *utfcvsetdefaultlocale(void);                             //~v5n0I~
  #ifdef UTF8SUPPH                                                 //~v62jI~
	int utfforcelocale(int Popt,char *Pcharset);                   //~v627I~
	int utfcvsetparmlocale(int Popt,char *Plocale);                //~v62GI~
//	int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,wchar_t *Ppucs);//~v62UR~//~v6a0R~
//	int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,UWCHART *Ppucs);//~v6a0I~//~v6unR~
//	int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,UWCHART *Ppucs,int *Pprc);//~v6unI~//~v6BjR~
  	int utfcvl2uany1mb(int Popt,char *Pinp,int Pinplen,UWUCS *Ppucs,int *Pprc);//~v6BjI~
  #endif                                                           //~v62jI~
#define LOCALEID_UTF8   "UTF8"      //iconv parm                   //~v62WI~
#define LOCALEID_UTF_8  "UTF-8"      //iconv parm                  //~v62WI~
#ifdef ARM                                                         //~v6a0I~
	#define ISO88591       "ISO8859-1"                             //~v6a0I~
#else                                                              //~v6a0I~
//#define ISO88591       "iso88591"                                  //~v62WM~//~v6K8R~
	#define ISO88591       "ISO8859-1"                             //~v6K8I~
#endif                                                             //~v6a0I~
  #ifdef UTF8UCS2                                                  //~v640I~
	int utfcvf2dd(int Popt,UCHAR *Ppdata,int Plen,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen);//~v640R~
    #define UTFCVFDRC_UTF8     0x01   //found utf8 code            //~v640R~
    #define UTFCVFDRC_DBCS     0x02   //found dbcs                 //~v640I~
    #define UTFCVFDRC_UTF8UNP  0x04   //unprintable utf(width<=0)  //~v640I~
    #define UTFCVFDRC_UTF8ERR  0x08   //invalid utf8 char,kept value//~v640I~
    #define UTFCVFDRC_ERR      0x10   //err level                  //~v640I~
	#define UTFCVFDRC_OVF      0x20   //buffser overflow           //~v640R~
  #endif                                                           //~v640I~
#endif //WCSUPP                                                    //~v5n0I~
#define  UTF_GETUTF8STR(Pucs,Pwku8,Plen) (Plen=uccvucs2utf((UWUCS)(Pucs),Pwku8),Pwku8[Plen]=0,Pwku8)//~v79hR~
#ifndef NOTRACE                                                    //~v79EI~
#define  UTF_GETUTF8STR_TRACE(Pucs,Pwku8,Plen) UTF_GETUTF8STR(Pucs,Pwku8,Plen)//~v79EI~
#else                                                              //~v79EI~
#define  UTF_GETUTF8STR_TRACE(Pucs,Pwku8,Plen) "UTF_GETUTF8STR_TRACE:NOTRACE"//~v79ER~
#endif                                                             //~v79EI~
//*******************************************************************//~v60dI~
//#ifdef UTF8SUPP                                                    //~v60aI~//~v650R~
#ifdef UTF8SUPPH                                                   //~v650I~
#ifdef __cplusplus                                                 //~v60aI~
}                                                                  //~v60aI~
#endif                                                             //~v60aI~
#endif                                                             //~v60aI~
