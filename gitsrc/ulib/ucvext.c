//*CID://+v7dSR~:                                   update#= 1332; //~v7dSR~
//***********************************************************************
//v7dS:241115 errmsg for DBCS_CHARSET name if it is not DBCS by icu ebc2ucs1//~v7dSI~
//vbBt:241114 add /ebc;defaultmapeuro                              //~vbBtI~
//vbBs:241114 del vbB9(process cp931(cp300+cp037)) because m2b from sjis generates 0e0f dbcs word for byte of sjis 1st byte whichi is byte of iso-8859.//~vbBsI~
//v7dQ:241110 ebc tblmode;subchar is '6f'(ebc "?"), adjust it of icu converter 3f(subch):u-001a. for DBCS fefe(U-fffd)//~v7dQI~
//v7dP:241109 ccsid-1140(cp037+Euro) support by "SBCS_CHARSET DefaulMapEuro"(1027/290 is already ebc-E1->20ac)//~v7dPI~
//v7dM:241106 ebcmb; use not iconv but wcrstombs for ecs2local;==> but it cv to utf8. set some subchar.//~v7dMI~
//v7dK:241105 dprecate subchar_sbcs/dbcs; It is not effective for handle>0.//~v7dKI~
//v7dJ:241104 dispaly sbcs cvname on hdr line if it is not dbcs cvname//~v7dJI~
//v7dF:241103 EBC2ASC; NEC is dup with EXT_SETSUBCHRC(0x10), EXT_SUBCHRC to 0x100000(OPENDCV) that is chked but not set//~v7dFI~
//v7dv:241019 accept E2A/A2E when converter is internal tbl        //~v7dvI~
//v7du:241019 accept ucs2 for E2A by Uxxxx                         //~v7duI~
//v7dt:241019 deprecate s3270 ebc conv, so del A2F/F2A option      //~v7dsI~
//v7ds:241018 A2E/E2A option ignored when defaultmap               //~v7dsI~
//v7dr:241018 reject DEfaultMap when using external converter      //~v7drI~
//v7dn:241007 following v7dk, delete cp037 and use DefaultMap only //~v7dnI~
//v7dm:241006 delete EBC2ASC_BASE option, then use the value as SBCSMAP037 for CP037 without DBCS//~v7dmI~
//v7dk:241006 regard DefaultMap as CP037 without DBCS               //~v7dkI~//~v7drR~
//vbBg:241006 ebcfile header line;set cvname cp037-internal        //~vbBgI~
//v7di:241004 (Bug)CP037 tbl adjust b2u was not used by EBC2ASC_EXT flag on//~v7diR~
//v7dh:240928 Windows:apply default datadir c:\windows\Globalization\ICU//~v7dhI~
//vbBd:240923 change cp931(not exist in icu) to CP939L(cp300+cp037)//~vvBdI~
//v7dg:240922 display EBCDIC_STATEFUL for icu converter list       //~v7dgI~
//v7df:240922 (Bug of vbBc)when converter=1(ICU), no dbcs transplation for cp93x//~v7dfI~
//v7de:240922 (Win:Bug) display "uconv not found" to stderr. Stderr was not catched on windows.//~v7deI~
//vbBc:240910 support ebcidic cfg file cmdline parameter           //~vbBcI~
//v7dc:240909 correct set_internal_cp037(allow SBCS=DefaultMap only when no SJISOPT and no DBCSCHARSET)//~v7dcI~
//v7d9:240901 b2m depends current local codepag; Adjust ebc2asc table by local converter.//~v7d9I~
//vbB9:240824 add cp931(cp300+cp037)                               //~v7d9I~
//v7d8:240823 DefaultMap is cp037; but it is not effective when env=JP//~v7d8I~
//vbB8:240823 change ebc option parm /EBC[:]{kana|eng|Latin|CP930|CP939|CP037}//~vbB8I~
//v7d7:240820 Default EBC-->ASCII tbl, use when "converter=0" and "SBCSMAP DefaultMap"//~v7d7I~
//v7d6:240820 update cp037 map by web info                         //~v7d5I~
//v7d5:240819 add SJIS_OPT=Base (SBCS=CP037 DP94 version,DBCS=CP300)//~v7d5I~
//vbB6:240818 add cmdline parm for ext_eng(ext_kana is default)    //~vbB6I~
//vbB4:240816 EBC cmd;display ebc cfg status                       //~vbB4I~
//v7d3:240816 UCECF_OPENERR flag missing when chcp=437(cp037)      //~v7d3I~
//v7d2:240811 ICU GetProcAddress u_setDataDirectory failes windows11//~v7d2I~
//v77X:230709 ARM;Android9(api28);xcv fails ctr cvname return 0,set env ICU_DATA//~v77XI~
//v77W:230709 ARM;Android9(api28);xcv fails to dlopen libicuuc by  //~v77WI~
//				dlopen opt=0x4,libicuuc.so handle=0x0,err=dlopen failed: library "libicuuc.so" wasn't loaded and RTLD_NOLOAD prevented it//~v77WI~
//				try RTLD_NOW                                       //~v77WI~
//v77P:230630 (BUG)icudata search, default is not searched.        //~v77PI~
//v77N:230630 icu lib search for also xcv                          //~v77NI~
//v77E:230621 ARM;uconv --version failes by "uconv not found". It is not required by chking dllname//~v77EI~
//v77n:230430 ARM:ICU library is loaded by dlopen without specific dir//~v77nI~
//v775:230328 try /system/apex/com.android.i18n                    //~v774I~
//v774:230328 try for libicu if libicuuc is not fond(libicu is available from Android12:Api31 foi icu4c)//~v774I~
//v773:230328 try for libicu lib64 then lib                        //~v773I~
//v772:230328 GetProcAddress(dlsym) failed for u_errName by errno=10( It is by icuuc not found). from Android7(Api24) library changed from com.ibm.icu to android.icu)//~v772I~
//v70d:200625 setenv for icu should be append mode                 //~v70dI~
//v702:200615 ARM compiler warning                                 //~v702I~
//v6S1:180129 (Ubuntu 17.10:gcc7.2)Lnx warning iswprint is not defined(wctype.h required)//~v6S1I~
//v6M5:170825 for xcv,xprint;create EBC cfg by uconv output        //~v6M5I~
//v6M4:170825 try get icu version by uconv cmd if ICU_DLL_SUFFIX,ICU_API_SUFFIX both are not specified//~v6M4I~
//v6M3:170824 (Lnx) putenv to LD_LIRARY_PATH is not effective(loader chk it at pgm startup and ignore putenv after startup)//~v6M3I~
//v6M2:170824 (Bug)v6M0 faile if path is multiple devided by ";"/":"//~v6M2I~
//v6M1:170812 (Bug)invalid name format at ucvext_getarmso(err at end of string chk of PATH env var)//~v6M1I~
//v6M0:170808 err "LoadLibrary failed for icuucxx"-=>loaddll using ICU_DATA param//~v6M0I~
//v6L5:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//~v6L5I~
//v6By:160212 (W32)compiler warning at w7                          //~v6ByI~
//v6Bt:160225 ICU api:ebc2ucs may return fffd for also sbcs if subchar1 was not defined//~v6BtI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6z0:150529 by xuerpck(uerrmsg parmchk)                          //~v6z0I~
//v6x8:150110 (warning C4244) not about ULPTR                      //~v6x8I~
//v6x9:150111 xeebc.map duplicate parameter chk for CONVERTER      //~v6x9I~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6n0:130816 compiler warning;set but not used                    //~v6n0I~
//v6m3:130726 for xprint, support -ICU without CFG parm file       //~v6m3I~
//v6hA:120822 (BUG)EBC handle subchar was not used for subcharchk  //~v6hAI~
//v6hz:120822 (Win:BUG)SsubcharICUebcxxx was not set when SBCS is default cp037 internal map//~v6hzI~
//v6hy:120822 (BUG)if duplicated SBCS_CHARSET on xeebc.map,use icu is reset even CONVERTER=1;//~v6hyI~
//            at windows udbcschk_getsubchar is called for sbcs charset and it fails remaining subchar is null;//~v6hyI~
//v6hx:120822 (BUG)u2b returns err for DBCS(ucvext_icusubcharchk returns UCVEXTRC_SUBCH)//~v6hxI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6g4:120512 ICU api suffix for 4.2 is also 4_2 like as 4.0(4_2)  //~v6g4I~
//v6g3:120511 Windows default libpath is by GetSystemDirectory/GetWindowsDirectory//~v6g3I~
//v6g2:120509 (BUG)setenv LD_LIBRARY_PATH programatically is not effective,spefify absolute path-->not effective because it refers icudata(requires LD_LIBRARY_PATH)//~v6g2I~
//v6fp:120506 (BUG)ICU subchar len for pconverters                 //~v6fpI~
//v6fm:120430 putenv if getenv(LD_LIBRARY_PATH) is null            //~v6fmI~
//v6fk:120429 setlocale("ko_KR.UHC") fail, add EUC-KR              //~v6fkI~
//v6fj:120428 avoid crash at open ebc file if dlopen failed        //~v6fjI~
//v6fg:120427 (BUG)-Ni(default) and -CGB18040;utf std char search is done(calls set_locale ja_JP.eucjp),//~v6fgI~
//            so wcwidth returns unprintable at uviom              //~v6fgI~
//v6ff:120427 (BUG)crash when "edit ebcfile" if ebcmap is use_converter but converter is not specified//~v6fdI~
//v6fd:120427 (BUG)should not use external converetr when ebcmap:converter=0//~v6fdI~
//v6fc:120427 serach dll for also ebcdic(xeemc.map)                //~v6fcI~
//v6fb:120427 (BUG)std lib dir is not lib64                        //~v6fbI~
//v6f9:120423 (Axe)default locale by locale.getDefault().toString()+"."+Charset.defaultCharset(="UTF-8")//~v6f9I~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f5:120419 option to use ICU as B2M/M2B local converter         //~v6f5I~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6c4:120121 xcv b2m traslation is invalid; if local converter is not set use mbr2wc(this is not implimented on ARM)//~v6c4I~
//v6c3:120120 u_setDataDirectory is not effective on android3/4?; try udata_setFileAcess//~v6c3I~
//v6c2:120120 use internal map cp37 if sbcs converter init failed  //~v6c2I~
//v6c0:120120 (Axe:BUG) icu data dir(/system/usr/icu) was not set.==>converter init failed for other than on com.xe.Axe/files/icu//~v6c0I~
//v6bu:120105 change default internal map cp37 to cp37,swaplfnl(0x15:0x0a)(=Android default)//~v6buI~
//v6bq:111221 icu additional directory name should be icudtxxl     //~v6bqI~
//v6bp:111214 putenv/setenv is not effective for ICU dll;use u_setDataDirectory()//~v6bqI~
//v6bn:111214 add ICU_DATA parameter to xeebc.map                  //~v6bnI~
//v6bm:111214 for xcv;-ICU option alternative for -mf:mapfile      //~v6bmI~
//v6bh:111210 for XCV;serach ICU lib when no -mf: parm             //~v6bhI~
//v6be:111209 (BUG)v6b3 but cp037 was ignored then s3270 table was used(xcv m2b fail by converter==null)//~v6beI~
//v6bd:111209 change default map to cp37(contains ctl char) from c3270ftp when not xe3270//~v6bdI~
//v6bc:111208 (BUG)ucvext12 was called from setupsubch before ucvext12_init//~v6bcI~
//v6ba:111208 (ARM)icu support                                     //~v6baI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6b3:110712 avoid uerrexit when ebcdic converter not found;use internal mapping//~v6b3I~
//v6b2:110712 abend when getconverter failed(uerrexit parm missing)//~v6b2I~
//v69x:100909 keep openerr status to be chked from xe              //~v69xI~
//v69v:100905 avoid CP37 duplicated assign cfg and cmd             //~v69vI~
//v69h:100820 (BUG)cfg SOSI option was ignored when converter=0 on Japanese env.//~v69hI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v69d:100815 split ucvext                                         //~v69dI~
//v68j:100719 (BUG)m2b delete DBCS by outlen=0 of m2b if the cp has no dbcs errepch(ex cp37)//~v68jI~
//v68i:100716 (BUG)when CONVERTER=0, CP47 is used on Japanese Windows env//~v68iI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v68c:100623 set default when cfg parm err                        //~v68cI~
//v685:100619 try "?" as ebc dbcs subchar fr CN
//v683:100616 (BUG) ICU subchar chk was not considered for laeding SO.//~v683I~
//v681:100616 (BUG)crash when converter parm err                   //~v681I~
//v66Y:100614 (LNX)dbcsenv for local converter to allow b2m output is dbcs//~v66WI~
//v66W:100613 (LNX)GB18030 returns 4byte char for ufffd-->8431a437,skip it as subchar//~v66WI~
//v66V:100613 (LNX)could not get subchar by u-fffd if iconv        //~v66VI~
//            set default ebc 4040, local u-3000                   //~v66VI~
//v66T:100613 (LNX:BUG)dbcs split rc was not chked for m2b         //~v66TI~
//v66S:100613 (LNX)use iconv even when env is not utf8. by the reason of v66K.//~v66TR~
//v66P:100612 (BUG)sbcs trans err when invalid SBCS converter specified//~v66NI~
//v66N:100611 ebc-b9->u178 is err if reverse chk,allow not reversible for b2u//~v66NI~
//v66K:100610 allow non reversible translation(wctombr/mbetowc between "A"-umlaut and "A" under japanese,//~v66KI~
//            because ebc-5b-->u-a5-->sjis-5c-->u05c is one of the case (backslash and yen sign)//~v66KI~
//v66J:100610 (BUG)icu return len=,err=0 for 0x0e/0x0f             //~v66JI~
//v66F:100609 err if sbcs->dbcs for b2m when -SBCS option specified(cfg option SUBCHARS2D is also set err)//~v66FI~
//v66D:100604 indicate not by outchar but by rc that SUBCHAR was set//~v66DI~
//v66C:100604 use converters native subchar if no subchar was specified on cfg//~v66CI~
//v66B:100604 ICU converter may support SS3(3byte dbcs) or GB4     //~v66BI~
//v66A:100602 hankana is 2byte byt ebc sbcs                        //~v66AI~
//v66x:100602 for cv cmd:apply -SBCS,ANK option from cmd option    //~v66xI~
//v66w:100601 (LNX)set default local converter if env is utf8 when set default by cv=0 r cfg fine not found//~v66wI~
//v66r:100530 add fallback option for icu.  2 ucs<-->1 mb case, mb->normal and fallback pattern//~v66rI~
//v66q:100530 set default cp037 mapping but real default converter(256 mapping tbl will be initialized at init)//~v66qI~
//v66n:100529 (LNX:BUG)m2b set errrep(no need to chk unprintable at ucs level but ebc level,more printable)//~v66nI~
//v66k:100528 (LNX:BUG)b2l invalid translation when LOCAL_CHARSET on ebc.cfg//~v66kR~
//            UCVEXTO_TOUTU8 and EBC1ASC_DBCS(0x100) is batting    //~v66kR~
//v66i:100527 (BUG called from ebc3)SOCONT is not considered       //~v66iI~
//v66h:100523 (BUG)abend if icu mode(cfg:converter=1) with no charset in dbcs/sbcs/local.//~v66hI~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n3:080904 cv cmd m2m support                                   //~v5n3I~
//v5n2:080824 Linux ICU spoort                                     //~v5n2I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v5mY:080821 SETEOL option to write EOL for m2b s2b a2b           //~v5mYR~
//v5mW:080819 xcv cmd support                                      //~v5mWI~
//v5mV:080819 DBCS upload SOSI option                              //~v5mVR~
//v5mU:080818 CP930/CP939 EBCS translation option support(IBM/NEC/NEW/OLD)//~v5mUI~
//v5mT:080817 EBCS translation for linux using iconv               //~v5mTI~
//v5mP:080805 EBC translation by ICU for 3270
//***********************************************************************
//* ucvext.c
//* ebc conversion using ICU
//***********************************************************************
#if defined(W32) || defined(LNX)
//***********************************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef W32                                                         //~v68hI~
    #include <windows.h>     //setenv                                   //~v68hI~//~v6bnR~
    #include <io.h>     //setmode                                  //~v6bnI~
    #include <fcntl.h>     //setmode                               //~v68hI~
#else                                                              //~v7duI~
    #include <ctype.h>     //setmode                               //~v7duI~
#endif                                                             //~v68hI~
#if defined(W32)||defined(LNX)                                     //~v6f3I~
	#include <locale.h>                                            //~v6f3I~
#endif                                                             //~v6f3I~
//#ifdef ARMXXE                                                      //~v775I~//~v77NR~
#ifdef ARM                                                         //~v77NI~
	#include <dlfcn.h>                                             //~v775I~
#endif                                                             //~v775I~

#include <ulib.h>
#include <ualloc.h>
#include <uedit.h>
#include <uparse.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uproc.h>
#include <ustring.h>
#include <ucvucs.h>                                                //~v5n3I~
#include <ucvext.h>                                                //~v7d9I~
#include <ucvebc.h>
#include <ucvebc2.h>
//#include <ucvext.h>                                              //~v7d9R~
#include <ucvext2.h>                                               //~v5mTR~
#include <ucvebc4.h>                                               //~v69cM~
#include <ufile.h>
#ifdef ARM                                                         //~v6bqI~
#include <ufile2l.h>                                               //~v6bqR~
#endif                                                             //~v6bqI~
#include <ufile3.h>                                                //~v6bqI~
#include <ufile5.h>
#include <ufemsg.h>
#include <utrace.h>
#include <uicu.h>
#include <ucvext12.h>                                              //~v69dM~
#include <utf.h>                                                   //~v5n0I~
#include <utf2.h>                                                  //~v6f3I~
#include <utf22.h>                                                 //~v66VI~
#include <udos2.h>                                                 //~v6bnI~
//#ifdef ARMXXE                                                      //~v77nI~//~v77NR~
//#include <dlfcn.h>                                               //~v77NR~
//#endif                                                             //~v77nI~//~v77NR~
//*******************************************************
#ifdef LNX                                                         //~v6baI~
    #define ENV_SEPC  ':'                                          //~v6bnI~
    #define ENV_SEPS  ":"                                          //~v6bnI~
  	#ifdef ARM                                                     //~v6baR~
//		#define ICULIBDIR   "/system/lib"                          //~v6baR~//~v773R~
//  	#define ICULIBDIR   "/system/lib64:/system/lib"            //~v773I~//~v774R~
    	#define ICULIBDIR    \
"/system/lib64"\
":/system/lib64/arm64"\
":/apex/com.android.runtime/lib64" /*dragon touch android10:api29*/\
":/system/apex/com.android.i18n/lib64" /*teclast Android12:api31*/\
":/system/lib"\
":/system/apex/com.android.i18n/lib"                               //~v774I~
		#define ICUDATADIR  "/system/usr/icu"                      //~v6baR~
  	#else                                                          //~v6baI~
// 		#ifdef ULIB64                                              //~v6baI~//~v6fbR~
   		#ifndef ULIB64                                             //~v6fbI~
			#define ICULIBDIR   "/usr/local/lib:/usr/lib"          //~v6baI~
   		#else                                                      //~v6baI~
			#define ICULIBDIR   "/usr/local/lib64:/usr/lib64"      //~v6baI~
   		#endif                                                     //~v6baI~
		#define ICUDATADIR  ""                                     //~v6bmR~
  	#endif                                                         //~v6baI~
//	#define DEFAULT_EBC  "ibm-37" No User                                  //~v6baI~//~v7d7R~
    static char *Sicudatadir=ICUDATADIR;                           //~v6baI~
    static char *Siculibdir=ICULIBDIR;                             //~v6baI~
#else                                                              //~v6bnI~
    static char *Sicudatadir=ICU_DATADIR_DEFAULT_WINDOWS;          //~v7dhI~
    #define ENV_SEPC  ';'                                          //~v6bnI~
    #define ENV_SEPS  ";"                                          //~v6bnI~
#endif                                                             //~v6baI~//~v6bmR~
#define TEST_GETDIR                                                //~v6c3I~
//definition file
#define UCVEXTCFGPARM_CSDBCS      "DBCS_CHARSET"
#define UCVEXTCFGPARM_CSSBCS      "SBCS_CHARSET"
#define UCVEXTCFGPARM_CSLOCAL     "LOCAL_CHARSET"
#define UCVEXTCFGPARM_CSSBCSDEF   "DefaultMap"
#define UCVEXTCFGPARM_CSSBCSDEF_EURO "DefaultMapEuro"              //~v7dPR~
#define UCVEXTCFGPARM_MAPE2A      "MAP_E2A"
#define UCVEXTCFGPARM_MAPA2E      "MAP_A2E"
#define UCVEXTCFGPARM_MAPF2A      "MAP_F2A"                        //~v7dsR~
#define UCVEXTCFGPARM_MAPA2F      "MAP_A2F"                        //~v7dsR~
#define UCVEXTCFGPARM_DLL         "ICU_DLL_SUFFIX"
#define UCVEXTCFGPARM_API         "ICU_API_SUFFIX"
#define UCVEXTCFGPARM_EXT         "CONVERTER"                      //~v5n1I~
#define UCVEXTCFGPARM_SUBCHARD    "SUBCHAR_DBCS"               
#define UCVEXTCFGPARM_SUBCHARS    "SUBCHAR_SBCS"               
#define UCVEXTCFGPARM_REPLF       "SUBCHAR_0A"
#define UCVEXTCFGPARM_NOS2D       "SUBCHAR_S2D"
#define UCVEXTCFGPARM_SJISOPT     "SJIS_OPT"                       //~v5mUI~
#define UCVEXTCFGPARM_SOSIA2E     "SOSI_A2E"                       //~v5mVI~
#define UCVEXTCFGPARM_SOSIE2A     "SOSI_E2A"                       //~v5mVI~
#define UCVEXTCFGPARM_ICUDATA     "ICU_DATA"                       //~v6bnI~

//#ifdef W32                                                       //~v5n2R~
#define ICU_DATAENVNAME        "ICU_DATA"                          //~v6bnI~
#ifdef ARM                                                         //~v772R~
	#define ICU_DLLNAME2       "icu"     //libicu by android.icu from android7(API24)//~v772R~
#endif                                                             //~v772I~
#define ICU_DLLNAME            "icuuc"
#define ICU_DLLNAME2           "icu"                               //~v774I~
#define ICU_DATANAME           "icudt"                             //~v6baI~
#define ICUAPINAME_SETDATADIR  "u_setDataDirectory"                //~v6bpI~
#ifdef TEST_GETDIR                                                 //~v6c3I~
#define ICUAPINAME_GETDATADIR  "u_getDataDirectory"                //~v6c3I~
#ifdef ARM                                                         //~v6c3I~
#define ICUAPINAME_FILEACCESS  "udata_setFileAccess"               //~v6c3I~
#endif                                                             //~v6c3I~
#endif                                                             //~v6c3I~
#define ICUAPINAME_OPEN        "ucnv_open"
#define ICUAPINAME_CLOSE       "ucnv_close"                        //~v6f4I~
#define ICUAPINAME_RESET       "ucnv_reset"                        //~v6f3I~
#define ICUAPINAME_TOUCS       "ucnv_toUChars"
#define ICUAPINAME_FROMUCS     "ucnv_fromUChars"
#define ICUAPINAME_ENUMCTR     "ucnv_countAvailable"
#define ICUAPINAME_ENUMNAME    "ucnv_getAvailableName"
#define ICUAPINAME_ENUMCTRA    "ucnv_countAliases"
#define ICUAPINAME_ENUMNAMEA   "ucnv_getAlias"
#define ICUAPINAME_OPENALLNAME "ucnv_openAllNames"
#define ICUAPINAME_GETDEFNAME  "ucnv_getDefaultName"
#define ICUAPINAME_GETTYPE     "ucnv_getType"
#define ICUAPINAME_GETNAME     "ucnv_getName"                      //~v6f3I~
#define ICUAPINAME_GETSUBCHARS "ucnv_getSubstChars"
#define ICUAPINAME_SETSUBCHARS "ucnv_setSubstChars"
#define ICUAPINAME_GETSTARTER  "ucnv_getStarters"
#define ICUAPINAME_SETFALLBACK "ucnv_setFallback"                  //~v66rR~
#define ICUAPINAME_USESFALLBACK "ucnv_usesFallback"                //~v66rI~
#define ICUAPINAME_VERSION      "ucnv_version"                     //~v77EI~

#define ICUAPINAME_ENUMNEXT    "uenum_next"
#define ICUAPINAME_ENUMCLOSE   "uenum_close"
#define ICUAPINAME_UERRNAME    "u_errorName"
typedef UConverter *(*ICUFUNC_OPEN)(const char *converterName,UErrorCode *err);
typedef void (*ICUFUNC_CLOSE)(UConverter *Pcnv);                   //~v6f4I~
typedef void (*ICUFUNC_RESET)(UConverter *Pcnv);                   //~v6f3I~
//typedef UINT (*ICUFUNC_TOUCS)(UConverter *Pcnv,USHORT *Pdest,UINT Pdestlen,char *Psrc,UINT Psrclen,UErrorCode *PerrorCode);//~v69dR~
//typedef UINT (*ICUFUNC_FROMUCS)(UConverter *Pcnv,char *Pdest,UINT Pdestlen,USHORT *Psrc,UINT Psrclen,UErrorCode *pErrorCode);//~v69dR~
typedef char *(*ICUFUNC_GETDEFNAME)(void);
typedef UConverterType (*ICUFUNC_GETTYPE)(UConverter *Pcnv);
typedef void (*ICUFUNC_GETSUBCHARS)(UConverter *Pcnv,char *Psubchars,char *Poutlen,UErrorCode *Perr);
typedef void (*ICUFUNC_SETSUBCHARS)(UConverter *Pcnv,char *Psubchars,char Plen,UErrorCode *Perr);
typedef void (*ICUFUNC_GETSTARTER)(UConverter *Pcnv,UBool Pstarters[256],UErrorCode *Perr);

typedef UINT (*ICUFUNC_ENUMCTR)(void);
typedef char *(*ICUFUNC_ENUMNAME)(UINT Pidx);
typedef USHORT (*ICUFUNC_ENUMCTRA)(char *Palias,UErrorCode *Perr);
typedef char  *(*ICUFUNC_ENUMNAMEA)(char *Palias,USHORT Pidx,UErrorCode *Perr);
typedef UEnumeration *(*ICUFUNC_OPENALLNAME)(UErrorCode *pErrorCode);
typedef char*(*ICUFUNC_ENUMNEXT)(UEnumeration* en,UINT *Pplen,UErrorCode* status);
typedef void (*ICUFUNC_ENUMCLOSE)(UEnumeration* en);
typedef char *(*ICUFUNC_UERRNAME)(UErrorCode Perr);
typedef char *(*ICUFUNC_GETNAME)(UConverter *Pconverter,UErrorCode *Perr);//~v6f3I~
//typedef char *(*ICUFUNC_SETDATADIR)(char *);                       //~v6bpI~//~v6c3R~
typedef void *(*ICUFUNC_SETDATADIR)(char *);                       //~v6c3I~
#ifdef TEST_GETDIR                                                 //~v6c3I~
typedef char *(*ICUFUNC_GETDATADIR)(void);                         //~v6c3I~
#ifdef ARM                                                         //~v6c3I~
typedef void  (*ICUFUNC_FILEACCESS)(UDataFileAccess access,UErrorCode *status);//~v6c3I~
#endif                                                             //~v6c3I~
#endif                                                             //~v6c3I~
typedef void (*ICUFUNC_SETFALLBACK)(UConverter *Pcnv,UBool Pfbon); //~v66rR~
typedef UBool(*ICUFUNC_USESFALLBACK)(UConverter *Pcnv);            //~v66rI~
typedef int (*ICUFUNC_VERSION)(void);                              //~v77EI~
//static ULONG            Shiculib=0;                              //~v6baR~
static DLHANDLE           Shiculib=0;                              //~v6baI~
//#define ICU_INITCHK(rc)  if (!Shiculib) 	return rc              //~v5n1R~
//#define ICU_INITCHK(rc)  if (!Shiculib && !(Sextflag & SEXTF_ICU)) 	return rc//~v5n1I~//~v66hR~
#define ICU_INITCHK(rc)  if (!Shiculib) 	return rc              //~v66hI~
static char             Sicuapisuffix[16];
static ICUFUNC_UERRNAME Spfuncuerrname=0;
static ICUFUNC_SETDATADIR Spfuncsetdatadir=0;                      //~v6bpR~
#ifdef TEST_GETDIR                                                 //~v6c3I~
static ICUFUNC_GETDATADIR Spfuncgetdatadir=0;                      //~v6c3I~
#ifdef ARM                                                         //~v6c3I~
static ICUFUNC_FILEACCESS Spfuncfileaccess=0;                      //~v6c3I~
#endif                                                             //~v6c3I~
#endif                                                             //~v6c3I~
static ICUFUNC_OPEN     Spfuncopen    =0;
static ICUFUNC_CLOSE    Spfuncclose   =0;                          //~v6f4I~
static ICUFUNC_RESET    Spfuncreset   =0;                          //~v6f3I~
static ICUFUNC_TOUCS    Spfunctoucs   =0;
static ICUFUNC_FROMUCS  Spfuncfromucs =0;
static ICUFUNC_SETFALLBACK   Spfuncsetfallback   =0;               //~v66rR~
static ICUFUNC_USESFALLBACK   Spfuncusesfallback   =0;             //~v66rI~
static ICUFUNC_GETSUBCHARS Spfuncgetsubchars=0;                    //~v6f2I~//~v6f3I~
static ICUFUNC_SETSUBCHARS Spfuncsetsubchars=0;                    //~v6f3I~
static ICUFUNC_GETNAME  Spfuncgetname=0;                           //~v6f3I~
static ICUFUNC_GETSTARTER Spfuncgetstarter=0;                      //~v6f3I~
static ICUFUNC_GETDEFNAME Spfuncgetdefname=0;                      //~v6f7I~
//static ICUFUNC_VERSION    Spfuncversion=0;                       //~v77ER~
//#else   //LNX                                                    //~v5n2R~
//	#define ICU_INITCHK(rc)  //nop                                 //~v5n2R~
//#endif //W32                                                     //~v5n2R~
//static ULONG            SpebcDBCSconverter=0;                    //~v6x5R~
//static ULONG            SpebcSBCSconverter=0;                    //~v6x5R~
//static ULONG            Splocalconverter=0;                      //~v6x5R~
static ULPTR            SpebcDBCSconverter=0;                      //~v6x5I~
static ULPTR            SpebcSBCSconverter=0;                      //~v6x5I~
static ULPTR            Splocalconverter=0;                        //~v6x5I~
                                                                   //~v6x5I~
static int Sextflag;
//*mbcs dbcs1st byte tbl
static char             Sstartermap[256];
#define UCVEXT_ISDBCS1ST(Popt,ch) (\
		/*  ((Popt & EBC2ASC_LOCALCV) && (Sextflag & SEXTF_DBCSSTART)) */\
		    ((Sextflag & SEXTF_DBCSSTART)) \
             ? Sstartermap[ch]!=0      \
          /*   : UDBCSCHK_ISDBCS1ST(ch) */ \
               : UDBCSCHK_ISMBDBCS1ST(ch)  /*by another codepage V62U*/  \
             )
//#define UTRACEP printf                                           //~v6baR~//~v6bnR~//~v6bpR~
//#define SPFNUMFLDLEN 8                                             //~v5mWI~//~v69dR~
//*************************************************************************
//from s3270:table.c   iso-8859-1  ****************************************
#define EBC2ASC \
/*00*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*08*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*10*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*18*/	0x20, 0x20, 0x20, 0x20, 0x2a, 0x20, 0x3b, 0x20, \
/*20*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*28*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*30*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*38*/	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, \
/*40*/	0x20, 0x20, 0xe2, 0xe4, 0xe0, 0xe1, 0xe3, 0xe5, \
/*48*/	0xe7, 0xf1, 0xa2, 0x2e, 0x3c, 0x28, 0x2b, 0x7c, \
/*50*/	0x26, 0xe9, 0xea, 0xeb, 0xe8, 0xed, 0xee, 0xef, \
/*58*/	0xec, 0xdf, 0x21, 0x24, 0x2a, 0x29, 0x3b, 0xac, \
/*60*/	0x2d, 0x2f, 0xc2, 0xc4, 0xc0, 0xc1, 0xc3, 0xc5, \
/*68*/	0xc7, 0xd1, 0xa6, 0x2c, 0x25, 0x5f, 0x3e, 0x3f, \
/*70*/	0xf8, 0xc9, 0xca, 0xcb, 0xc8, 0xcd, 0xce, 0xcf, \
/*78*/	0xcc, 0x60, 0x3a, 0x23, 0x40, 0x27, 0x3d, 0x22, \
/*80*/	0xd8, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, \
/*88*/	0x68, 0x69, 0xab, 0xbb, 0xf0, 0xfd, 0xfe, 0xb1, \
/*90*/	0xb0, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, \
/*98*/	0x71, 0x72, 0xaa, 0xba, 0xe6, 0xb8, 0xc6, 0xa4, \
/*a0*/	0xb5, 0x7e, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, \
/*a8*/	0x79, 0x7a, 0xa1, 0xbf, 0xd0, 0xdd, 0xde, 0xae, \
/*b0*/	0x5e, 0xa3, 0xa5, 0xb7, 0xa9, 0xa7, 0xb6, 0xbc, \
/*b8*/	0xbd, 0xbe, 0x5b, 0x5d, 0xaf, 0xa8, 0xb4, 0xd7, \
/*c0*/	0x7b, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, \
/*c8*/	0x48, 0x49, 0xad, 0xf4, 0xf6, 0xf2, 0xf3, 0xf5, \
/*d0*/	0x7d, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, \
/*d8*/	0x51, 0x52, 0xb9, 0xfb, 0xfc, 0xf9, 0xfa, 0xff, \
/*e0*/	0x5c, 0xf7, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, \
/*e8*/	0x59, 0x5a, 0xb2, 0xd4, 0xd6, 0xd2, 0xd3, 0xd5, \
/*f0*/	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, \
/*f8*/	0x38, 0x39, 0xb3, 0xdb, 0xdc, 0xd9, 0xda, 0x20
#define ASC2EBC \
/*00*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*08*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*10*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*18*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*20*/  0x40, 0x5a, 0x7f, 0x7b, 0x5b, 0x6c, 0x50, 0x7d, \
/*28*/  0x4d, 0x5d, 0x5c, 0x4e, 0x6b, 0x60, 0x4b, 0x61, \
/*30*/  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, \
/*38*/  0xf8, 0xf9, 0x7a, 0x5e, 0x4c, 0x7e, 0x6e, 0x6f, \
/*40*/  0x7c, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, \
/*48*/  0xc8, 0xc9, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, \
/*50*/  0xd7, 0xd8, 0xd9, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, \
/*58*/  0xe7, 0xe8, 0xe9, 0xba, 0xe0, 0xbb, 0xb0, 0x6d, \
/*60*/  0x79, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, \
/*68*/  0x88, 0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, \
/*70*/  0x97, 0x98, 0x99, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, \
/*78*/  0xa7, 0xa8, 0xa9, 0xc0, 0x4f, 0xd0, 0xa1, 0x00, \
/*80*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*88*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*90*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*98*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
/*a0*/  0x41, 0xaa, 0x4a, 0xb1, 0x9f, 0xb2, 0x6a, 0xb5, \
/*a8*/  0xbd, 0xb4, 0x9a, 0x8a, 0x5f, 0xca, 0xaf, 0xbc, \
/*b0*/  0x90, 0x8f, 0xea, 0xfa, 0xbe, 0xa0, 0xb6, 0xb3, \
/*b8*/  0x9d, 0xda, 0x9b, 0x8b, 0xb7, 0xb8, 0xb9, 0xab, \
/*c0*/  0x64, 0x65, 0x62, 0x66, 0x63, 0x67, 0x9e, 0x68, \
/*c8*/  0x74, 0x71, 0x72, 0x73, 0x78, 0x75, 0x76, 0x77, \
/*d0*/  0xac, 0x69, 0xed, 0xee, 0xeb, 0xef, 0xec, 0xbf, \
/*d8*/  0x80, 0xfd, 0xfe, 0xfb, 0xfc, 0xad, 0xae, 0x59, \
/*e0*/  0x44, 0x45, 0x42, 0x46, 0x43, 0x47, 0x9c, 0x48, \
/*e8*/  0x54, 0x51, 0x52, 0x53, 0x58, 0x55, 0x56, 0x57, \
/*f0*/  0x8c, 0x49, 0xcd, 0xce, 0xcb, 0xcf, 0xcc, 0xe1, \
/*f8*/  0x70, 0xdd, 0xde, 0xdb, 0xdc, 0x8d, 0x8e, 0xdf
//******************
static UCHAR Sebc2asc0[256] = { EBC2ASC };
static UCHAR Sasc2ebc0[256] = { ASC2EBC };
#ifdef AAA                                                         //~v5mTI~
static UCHAR Sebc2asc[256];
static UCHAR Sasc2ebc[256];
#endif                                                             //~v5mTI~
#ifdef UTF8EBCD                                                    //~v660I~
//Default ebcdic->ascii                                            //~v7d7R~
#ifdef AAA
static UCHAR Sebc2ascii[256] ={    //IBM default                   //~v7d7R~
 0x00,0x01,0x02,0x03,0xCF,0x09,0xD3,0x7F,0xD4,0xD5,0xC3,0x0B,0x0C,0x0D,0x0E,0x0F, //00//~v7d7R~
 0x10,0x11,0x12,0x13,0xC7,0xB4,0x08,0xC9,0x18,0x19,0xCC,0xCD,0x83,0x1D,0xD2,0x1F, //10//~v7d7R~
 0x81,0x82,0x1C,0x84,0x86,0x0A,0x17,0x1B,0x89,0x91,0x92,0x95,0xA2,0x05,0x06,0x07, //20//~v7d7R~
 0xE0,0xEE,0x16,0xE5,0xD0,0x1E,0xEA,0x04,0x8A,0xF6,0xC6,0xC2,0x14,0x15,0xC1,0x1A, //30//~v7d7R~
 0x20,0xA6,0xE1,0x80,0xEB,0x90,0x9F,0xE2,0xAB,0x8B,0x9B,0x2E,0x3C,0x28,0x2B,0x7C, //40//~v7d7R~
 0x26,0xA9,0xAA,0x9C,0xDB,0xA5,0x99,0xE3,0xA8,0x9E,0x21,0x24,0x2A,0x29,0x3B,0x5E, //50//~v7d7R~
 0x2D,0x2F,0xDF,0xDC,0x9A,0xDD,0xDE,0x98,0x9D,0xAC,0xBA,0x2C,0x25,0x5F,0x3E,0x3F, //60//~v7d7R~
 0xD7,0x88,0x94,0xB0,0xB1,0xB2,0xFC,0xD6,0xFB,0x60,0x3A,0x23,0x40,0x27,0x3D,0x22, //70//~v7d7R~
 0xF8,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x96,0xA4,0xF3,0xAF,0xAE,0xC5, //80//~v7d7R~
 0x8C,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x97,0x87,0xCE,0x93,0xF1,0xFE, //90//~v7d7R~
 0xC8,0x7E,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0xEF,0xC0,0xDA,0x5B,0xF2,0xF9, //A0//~v7d7R~
 0xB5,0xB6,0xFD,0xB7,0xB8,0xB9,0xE6,0xBB,0xBC,0xBD,0x8D,0xD9,0xBF,0x5D,0xD8,0xC4, //B0//~v7d7R~
 0x7B,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0xCB,0xCA,0xBE,0xE8,0xEC,0xED, //C0//~v7d7R~
 0x7D,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0xA1,0xAD,0xF5,0xF4,0xA3,0x8F, //D0//~v7d7R~
 0x5C,0xE7,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0xA0,0x85,0x8E,0xE9,0xE4,0xD1, //E0//~v7d7R~
 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0xB3,0xF7,0xF0,0xFA,0xA7,0xFF  //F0//~v7d7R~
};//                                                               //~v7d7R~
#endif //AAA
// x00,x01,x02,x03,Ï,x09,Ó,x7f,Ô,Õ,Ã,x0b,x0c,x0d,x0e,x0f            00//~v7d7R~
// x10,x11,x12,x13,Ç,´,x08,É,x18,x19,Ì,Í,x83,x1d,Ò,x1f              10//~v7d7R~
// x81,x82,x1c,x84,x86,x0a,x17,,x89,x91,x92,x95,¢,x05,x06,x07      20//~v7d7R~
// xe0,xee,x16,xe5,Ð,x1e,xea,x04,x8a,xf6,Æ,Â,x14,x15,Á,x1a          30//~v7d7R~
//  ,¦,xe1,x80,xeb,x90,x9f,xe2,«,x8b,x9b,.,<,(,+,|                  40//~v7d7R~
// &,©,ª,x9c,Û,¥,x99,xe3,¨,x9e,!,$,*,),;,^                          50//~v7d7R~
// -,/,ß,Ü,x9a,Ý,Þ,x98,x9d,¬,º,,,%,_,>,?                            60//~v7d7R~
// ×,x88,x94,°,±,²,xfc,Ö,xfb,`,:,#,@,',=,"                          70//~v7d7R~
// xf8,a,b,c,d,e,f,g,h,i,x96,¤,xf3,¯,®,Å                            80//~v7d7R~
// x8c,j,k,l,m,n,o,p,q,r,x97,x87,Î,x93,xf1,xfe                      90//~v7d7R~
// È,~,s,t,u,v,w,x,y,z,xef,À,Ú,[,xf2,xf9                            a0//~v7d7R~
// µ,¶,fd,·,¸,¹,xe6,»,¼,½,x8d,Ù,¿,],Ø,Ä                             b0//~v7d7R~
// {,A,B,C,D,E,F,G,H,I,Ë,Ê,¾,xe8,xec,xed                            c0//~v7d7R~
// },J,K,L,M,N,O,P,Q,R,¡,­,xf5,xf4,£,x8f                            d0//~v7d7R~
// \,e7,S,T,U,V,W,X,Y,Z,a0,x85,x8e,xe9,xe4,Ñ                        e0//~v7d7R~
// 0,1,2,3,4,5,6,7,8,9,³,xf7,xf0,xfa,§,xff                          f0//~v7d7R~
                                                                   //~v7d7R~
//#ifdef BBB  //use real converter CP037                             //~v66qI~//~v6b3R~
//*************************************************************************//~v660I~
//CCSID 036  **from Wiki 2010/04/13*****************               //~v660I~
///*10*/  0x10, 0x11, 0x12, 0x13, 0x00, 0x85, 0x08, 0x00,          //~v6buM~
///*20*/  0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x17, 0x1b,          //~v6buM~
//#define EBC2ASC037                                               //~vbBcR~
///*00    0x00, 0x01, 0x02, 0x03, 0x00, 0x09, 0x00, 0x7f, */       //~vbBcR~
///*00*/  0x00, 0x01, 0x02, 0x03, 0x9c, 0x09, 0x86, 0x7f,          //~vbBcR~
///*08    0x00, 0x00, 0x00, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, */       //~vbBcR~
///*08*/  0x97, 0x8d, 0x8e, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,          //~vbBcR~
///*10    0x10, 0x11, 0x12, 0x13, 0x00, 0x0a, 0x08, 0x00, */       //~vbBcR~
///*10*/  0x10, 0x11, 0x12, 0x13, 0x9d, 0x85, 0x08, 0x87,          //~vbBcR~
///*18    0x18, 0x19, 0x00, 0x00, 0x1c, 0x1d, 0x1e, 0x1f, */       //~vbBcR~
///*18*/  0x18, 0x19, 0x92, 0x8f, 0x1c, 0x1d, 0x1e, 0x1f,          //~vbBcR~
///*20    0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x17, 0x1b, */       //~vbBcR~
///*20*/  0x80, 0x81, 0x82, 0x83, 0x84, 0x0a, 0x17, 0x1b,          //~vbBcR~
///*28    0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x06, 0x07, */       //~vbBcR~
///*28*/  0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x05, 0x06, 0x07,          //~vbBcR~
///*30    0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x04, */       //~vbBcR~
///*30*/  0x90, 0x91, 0x16, 0x93, 0x94, 0x95, 0x96, 0x04,          //~vbBcR~
///*38    0x00, 0x00, 0x00, 0x00, 0x14, 0x15, 0x00, 0x1a, */       //~vbBcR~
///*38*/  0x98, 0x99, 0x9a, 0x9b, 0x14, 0x15, 0x9e, 0x1a,          //~vbBcR~
///*40*/  0x20, 0xa0, 0xe2, 0xe4, 0xe0, 0xe1, 0xe3, 0xe5,          //~vbBcR~
///*48*/  0xe7, 0xf1, 0xa2, 0x2e, 0x3c, 0x28, 0x2b, 0x7c,          //~vbBcR~
///*50*/  0x26, 0xe9, 0xea, 0xeb, 0xe8, 0xed, 0xee, 0xef,          //~vbBcR~
///*58*/  0xec, 0xdf, 0x21, 0x24, 0x2a, 0x29, 0x3b, 0xac,          //~vbBcR~
///*60*/  0x2d, 0x2f, 0xc2, 0xc4, 0xc0, 0xc1, 0xc3, 0xc5,          //~vbBcR~
///*68*/  0xc7, 0xd1, 0xa6, 0x2c, 0x25, 0x5f, 0x3e, 0x3f,          //~vbBcR~
///*70*/  0xf8, 0xc9, 0xca, 0xcb, 0xc8, 0xcd, 0xce, 0xcf,          //~vbBcR~
///*78*/  0xcc, 0x60, 0x3a, 0x23, 0x40, 0x27, 0x3d, 0x22,          //~vbBcR~
///*80*/  0xd8, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,          //~vbBcR~
///*88*/  0x68, 0x69, 0xab, 0xbb, 0xf0, 0xfd, 0xfe, 0xb1,          //~vbBcR~
///*90*/  0xb0, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,          //~vbBcR~
///*98*/  0x71, 0x72, 0xaa, 0xba, 0xe6, 0xb8, 0xc6, 0xa4,          //~vbBcR~
///*a0*/  0xb5, 0x7e, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,          //~vbBcR~
///*a8*/  0x79, 0x7a, 0xa1, 0xbf, 0xd0, 0xdd, 0xde, 0xae,          //~vbBcR~
///*b0*/  0x5e, 0xa3, 0xa5, 0xb7, 0xa9, 0xa7, 0xb6, 0xbc,          //~vbBcR~
///*b8*/  0xbd, 0xbe, 0x5b, 0x5d, 0xaf, 0xa8, 0xb4, 0xd7,          //~vbBcR~
///*c0*/  0x7b, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,          //~vbBcR~
///*c8*/  0x48, 0x49, 0xad, 0xf4, 0xf6, 0xf2, 0xf3, 0xf5,          //~vbBcR~
///*d0*/  0x7d, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,          //~vbBcR~
///*d8*/  0x51, 0x52, 0xb9, 0xfb, 0xfc, 0xf9, 0xfa, 0xff,          //~vbBcR~
///*e0*/  0x5c, 0xf7, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,          //~vbBcR~
///*e8*/  0x59, 0x5a, 0xb2, 0xd4, 0xd6, 0xd2, 0xd3, 0xd5,          //~vbBcR~
///*f0*/  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,          //~vbBcR~
///*f8    0x38, 0x39, 0xb3, 0xdb, 0xdc, 0xd9, 0xda, 0x00  */       //~vbBcR~
///*f8*/  0x38, 0x39, 0xb3, 0xdb, 0xdc, 0xd9, 0xda, 0x9f             //~v7d6R~//~v7d9R~
//******************                                               //~v660I~
//static UCHAR Sebc2asc037[256] = { EBC2ASC037 };                    //~v660I~//~v7d9R~
static UCHAR Sebc2asc037[256] = {                                  //~v7d9I~
///*00*/0x00, 0x01, 0x02, 0x03, 0x9c, 0x09, 0x86, 0x7f,            //~v7d9R~
/*00*/  0x00, 0x01, 0x02, 0x03, '.' , 0x09, '.' , 0x7f,            //~v7d9I~
///*08*/0x97, 0x8d, 0x8e, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,            //~v7d9R~
/*08*/  '.' , '.' , '.' , 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,            //~v7d9I~
///*10*/0x10, 0x11, 0x12, 0x13, 0x9d, 0x85, 0x08, 0x87,            //~v7d9R~
/*10*/  0x10, 0x11, 0x12, 0x13, '.' , '.' , 0x08, '.' ,            //~v7d9I~
///*18*/0x18, 0x19, 0x92, 0x8f, 0x1c, 0x1d, 0x1e, 0x1f,            //~v7d9R~
/*18*/  0x18, 0x19, '.' , '.' , 0x1c, 0x1d, 0x1e, 0x1f,            //~v7d9I~
///*20*/0x80, 0x81, 0x82, 0x83, 0x84, 0x0a, 0x17, 0x1b,            //~v7d9R~
/*20*/  '.' , '.' , '.' , '.' , '.' , 0x0a, 0x17, 0x1b,            //~v7d9I~
///*28*/0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x05, 0x06, 0x07,            //~v7d9R~
/*28*/  '.' , '.' , '.' , '.' , '.' , 0x05, 0x06, 0x07,            //~v7d9I~
///*30*/0x90, 0x91, 0x16, 0x93, 0x94, 0x95, 0x96, 0x04,            //~v7d9R~
/*30*/  '.' , '.' , 0x16, '.' , '.' , '.' , '.' , 0x04,            //~v7d9I~
///*38*/0x98, 0x99, 0x9a, 0x9b, 0x14, 0x15, 0x9e, 0x1a,            //~v7d9R~
/*38*/  '.' , '.' , '.' , '.' , 0x14, 0x15, '.' , 0x1a,            //~v7d9I~
/*40*/  0x20, 0xff, 0x83, 0x84, 0x85, 0xa0, '.' , 0x86,            //~v7d9R~
/*48*/  0x87, 0xa4, 0x9b, 0x2e, 0x3c, 0x28, 0x2b, 0x7c,            //~v7d9I~
/*50*/  0x26, 0x82, 0x88, 0x89, 0x8a, 0xa1, 0x8c, 0x8b,            //~v7d9I~
/*58*/  0x8d, 0xe1, 0x21, 0x24, 0x2a, 0x29, 0x3b, 0xaa,            //~v7d9R~
/*60*/  0x2d, 0x2f, '.' , 0x8e, '.' , '.' , '.' , 0x8f,            //~v7d9I~
/*68*/  0x80, 0xa5, '.' , 0x2c, 0x25, 0x5f, 0x3e, 0x3f,            //~v7d9I~
/*70*/  '.' , 0x90, '.' , '.' , '.' , '.' , '.' , '.' ,            //~v7d9I~
/*78*/  '.' , 0x60, 0x3a, 0x23, 0x40, 0x27, 0x3d, 0x22,            //~v7d9I~
/*80*/  '.' , 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,            //~v7d9I~
/*88*/  0x68, 0x69, 0xae, 0xaf, '.' , '.' , '.' , 0xf1,            //~v7d9I~
/*90*/  0xf8, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,            //~v7d9I~
/*98*/  0x71, 0x72, 0xa6, 0xa7, 0x91, '.' , 0x92, '.' ,            //~v7d9I~
/*a0*/  0xe6, 0x7e, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,            //~v7d9I~
/*a8*/  0x79, 0x7a, 0xad, 0xa8, '.' , '.' , '.' , '.' ,            //~v7d9I~
/*b0*/  0x5e, 0x9c, 0x9d, 0xfa, '.' , '.' , '.' , 0xac,            //~v7d9I~
/*b8*/  0xab, '.' , 0x5b, 0x5d, '.' , '.' , '.' , '.' ,            //~v7d9I~
/*c0*/  0x7b, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,            //~v7d9I~
/*c8*/  0x48, 0x49, '.' , 0x93, 0x94, 0x95, 0xa2, '.' ,            //~v7d9I~
/*d0*/  0x7d, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,            //~v7d9I~
/*d8*/  0x51, 0x52, '.' , 0x96, 0x81, 0x97, 0xa3, 0x98,            //~v7d9I~
/*e0*/  0x5c, 0xf6, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,            //~v7d9I~
/*e8*/  0x59, 0x5a, 0xfd, '.' , 0x99, '.' , '.' , '.' ,            //~v7d9I~
/*f0*/  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,            //~v7d9I~
/*f8*/  0x38, 0x39, '.' , '.' , 0x9a, '.' , '.' , 0x2e             //~v7d9I~
};                                                                 //~v7d9I~
static UCHAR Sasc2ebc037[256];                                     //~v660I~
//#else                                                              //~v66qI~//~v6b3R~
	#ifdef W32                                                     //~v66qI~
//  	#define  EBC_DEFAULT_CP      "037"                         //~v66qI~//~v69vR~
    	#define  EBC_DEFAULT_CP      "37"                          //~v69vI~
    #else                                                          //~v66qI~
    	#define  EBC_DEFAULT_CP      "CP037"                       //~v66qI~
    #endif                                                         //~v66qI~
//#endif //BBB                                                       //~v66qI~//~v6b3R~
#endif                                                             //~v660I~
                                                                   //~v660I~
//static ULONG Ssbcsmap_a2e=(ULONG)Sasc2ebc0,Ssbcsmap_e2a=(ULONG)Sebc2asc0;//~v6hhR~
static ULPTR Ssbcsmap_a2e=(ULPTR)Sasc2ebc0,Ssbcsmap_e2a=(ULPTR)Sebc2asc0;//~v6hhI~
//static ULONG Ssbcsmap_a2eC,Ssbcsmap_e2aC;                        //~v6hhR~
static ULPTR Ssbcsmap_a2eC,Ssbcsmap_e2aC;                          //~v6hhI~
//static ULONG Ssbcsmap_a2f,Ssbcsmap_f2a;                          //~v6hhR~
static ULPTR Ssbcsmap_a2f,Ssbcsmap_f2a;                            //~v6hhI~
static USHORT Ssubchardbcs=UDBCSCHK_SUBCHAR_DBCS;
static USHORT Ssubcharsbcs=UDBCSCHK_SUBCHAR_SBCS;
static UCHAR  Ssubcharlocalsbcs=CHAR_ASCII_ERR;	//3f"?"            //~v66CI~
static UCHAR  Ssubcharlocaldbcs[MAX_MBCSLEN];                      //~v66CI~
//static UCHAR  Ssubcharebcsbcs=CHAR_EBC_ERR;     //6f               //~v66CI~//~v7dQR~
static UCHAR  Ssubcharebcsbcs=CHAR_EBC_SUB;       //3f             //~v7dQI~
static UCHAR  Ssubcharebcdbcs[MAX_MBCSLEN];       //ebc dbcs space //~v66CI~
static int    Ssubcharebcdbcslen,Ssubcharlocaldbcslen;             //~v66CR~
//*icu subchar reversechk                                          //~v66DI~
static UCHAR SsubcharICUlocalSbcs,SsubcharICUebcSbcs;              //~v66DI~
static UCHAR SsubcharICUlocalDbcs[MAX_MBCSLEN];                    //~v66DI~
static UCHAR SsubcharICUebcDbcs[MAX_MBCSLEN];                      //~v66DI~
static UCHAR SsubcharICUmblocal[MAX_MBCSLEN+1];                    //~v6f7R~
static int SsubcharICUlocalDbcslen,SsubcharICUebcDbcslen;          //~v66DR~
static PUCVEXTCFG Spcfg;	//for enumconverter                    //~v6baI~
static char Sdllfpath[_MAX_PATH];                                  //~v6g2I~
static char *Sicudataparm=0;                                       //~v6M0I~
#ifdef ARM                                                         //~v774I~
	static int swNewICU4C;                                         //~v774I~
#endif                                                             //~v774I~
//#ifdef ARMXXE                                                      //~v77nI~//~v77NR~
#ifdef ARM                                                         //~v77NI~
	static char Sicusoname[32];                                    //~v77nI~
#endif                                                             //~v77nI~
//*************************************************************************
#ifdef UTF8EBCD                                                    //~v660I~
int ucvext_mapinitsetdefault(int Popt,PUCVEXTCFG Ppcfg);           //~v660I~
int ucvext_setdefaultlocalcv(int Popt,PUCVEXTCFG Ppcfg);           //~v66wI~
int ucvext_setupsubch(int Popt,PUCVEXTCFG Ppcfg);                  //~v66DI~
//int ucvext_icusubcharchk(int Popt,WUCS Pucs,UCHAR *Pstr,int Plen); //~v66DI~//~v69dR~
//#define UCVEXTISCO_MASK         0x0f                               //~v66DR~//~v69dR~
//#define UCVEXTISCO_U2B         0x01                                //~v66DR~//~v69dR~
//#define UCVEXTISCO_U2L         0x02                                //~v66DR~//~v69dR~
//#define UCVEXTISCO_B2U         0x03                                //~v66DR~//~v69dR~
//#define UCVEXTISCO_L2U         0x04                                //~v66DR~//~v69dR~
void set_internal_CP037(int Popt,PUCVEXTCFG Ppcfg);
#endif                                                             //~v660I~
//int ucvext_icuucs2local1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5R~
//#ifdef UTF8UCS4                                                  //~v6x5R~
//int ucvext_iculocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs);//~v6x5R~
//#else                                                            //~v6x5R~
//int ucvext_iculocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs);//~v6x5R~
//#endif                                                           //~v6x5R~
int ucvext_setlocalconverter(int Popt,PUCVEXTCFG Ppcfg);           //~v6c4I~
int chkicuversion(char *Ppdllsuffix,size_t Pdllsuffixsz,char *Ppapisuffix,size_t Papisuffixsz);//~v6M4I~
//****************************************************************
//*cfg data err msg
//****************************************************************
int ucvext_cfglineerr(char *Pfnm,char *Plinebuff)
{
	uerrmsg("%s:syntax err:%s\n",0,                                //~v68cR~//~vbBcR~
    			Pfnm,Plinebuff);
    return 4;
}//ucvext_cfglineerr
//**************************************************************** //~v6x9I~
int ucvext_cfgdupoption(char *Pfnm,char *Poption)                  //~v6x9I~
{                                                                  //~v6x9I~
	uerrmsg("%s:%s option is duplicated",0,                        //~v6x9R~
    			Pfnm,Poption);                                     //~v6x9I~
    return 4;                                                      //~v6x9I~
}//ucvext_cfgdupoption                                             //~v6x9I~
//**************************************************************** //~v5mTI~
//*get mapping data   format=     0xYY: Z  ,   Z: 0xYY             //~v5mTI~
//*opt 0:E2A,1:A2E                                                 //~v5mTI~
//**************************************************************** //~v5mTI~
int ucvext_ux2s(char *Pstr,USHORT *Ppucs)                          //~v5mTI~
{                                                                  //~v5mTI~
	USHORT ucs;                                                    //~v5mTI~
    char *pc;                                                      //~v5mTI~
//********************                                             //~v5mTI~
UTRACEP("%s:str=%s\n",UTT,Pstr);                                     //~v5mTI~//~vbB9R~
	pc=Pstr;                                                       //~v5mTI~
    if (USTRHEADIS_IC(Pstr,"0x"))                                  //~v5mTI~
        pc+=2;                                                     //~v5mTI~
    else                                                           //~v5mTI~
    if (USTRHEADIS_IC(Pstr,"U"))                                   //~v5mTI~
        pc++;                                                      //~v5mTI~
    if (ux2s(pc,&ucs)||!ucs)                                       //~v5mTI~
        return 4;                                                  //~v5mTI~
    *Ppucs=ucs;                                                    //~v5mTI~
UTRACEP("%s:pc=%s->ucs=%x\n",UTT,pc,ucs);                            //~v5mTI~//~vbB9R~
    return 0;                                                      //~v5mTI~
}//ucvext_ux2s                                                     //~v7drR~
//****************************************************************
//*get mapping data   format=     0xYY: Z  ,   Z: 0xYY
//*opt 0:E2A,1:A2E
//****************************************************************
int ucvext_cfgmap(int Popt,UCHAR *Ppmap,char *Pfrom,char *Pto)
{
	UCHAR from,to;
//********************
    UTRACEP("%s:from=%s,to=%s\n",UTT,Pfrom,Pto);                   //~v7dsI~//~v7dvR~
    if (USTRHEADIS_IC(Pfrom,"0x"))
    {
        if (ugethex(Pfrom+2,&from,2)<0)
        	return 4;
    }
    else
    {
//  	if (strlen(Pfrom)!=2||*(Pfrom+1)!=':')                     //~v7dsR~
//          return 4;                                              //~v7dsR~
    	if (strlen(Pfrom)!=1)                                      //~v7dsI~
            return 4;                                              //~v7dsI~
    	from=*Pfrom;
    }
	if (!Pto)
    	return 4;
    if (USTRHEADIS_IC(Pto,"0x"))
    {
        if (ugethex(Pto+2,&to,2)<0)
        	return 4;
    }
    else
    {
    	if (strlen(Pto)!=1)
            return 4;
    	to=*Pto;
    }
#ifdef CCC                                                         //~v7duI~
    if (to>=0x80)                                                  //~v7duI~
    {                                                              //~v7duI~
        uerrmsg("%s is not ascii, use Uxxxx format",0,Pto);        //~v7duR~
        return 4;                                                  //~v7duI~
    }                                                              //~v7duI~
#endif //CCC                                                       //~v7duI~
    Ppmap[from]=to;
    UTRACEP("%s:%s(%02x) -> %s(%02x)\n",UTT,Pfrom,from,Pto,to);    //~vbB9R~
    return 0;
}//ucvext_cfgmap
//**************************************************************** //~v7duI~
//*get mapping data   format=     0xYY: Z  ,   Z: 0xYY             //~v7duI~
//*opt 0:E2A,1:A2E                                                 //~v7duI~
//**************************************************************** //~v7duI~
int ucvext_cfgmapu(int Popt,USHORT *Ppmap,char *Pfrom,char *Pto)   //~v7duI~
{                                                                  //~v7duI~
	UCHAR from;                                                    //~v7duI~
	USHORT to;                                                     //~v7duI~
//********************                                             //~v7duI~
    UTRACEP("%s:fro,=%s,to=%s\n",UTT,Pfrom,Pto);                   //~v7duI~
    if (USTRHEADIS_IC(Pfrom,"0x"))                                 //~v7duI~
    {                                                              //~v7duI~
        if (ugethex(Pfrom+2,&from,2)<0)                            //~v7duI~
        	return 4;                                              //~v7duI~
    }                                                              //~v7duI~
    else                                                           //~v7duI~
    {                                                              //~v7duI~
    	if (strlen(Pfrom)!=1)                                      //~v7duI~
            return 4;                                              //~v7duI~
    	from=*Pfrom;                                               //~v7duI~
    }                                                              //~v7duI~
	if (!Pto)                                                      //~v7duI~
    	return 4;                                                  //~v7duI~
    char *pto=Pto;                                                 //~v7duI~
    if (*pto=='-')                                                 //~v7duR~
        pto++;                                                     //~v7duR~
    if (ux2s(pto,&to))                                             //~v7duI~
        return 4;                                                  //~v7duI~
    Ppmap[from]=to;                                                //~v7duI~
    UTRACEP("%s:%s(%02x) -> %s(%04x)\n",UTT,Pfrom,from,pto,to);    //~v7duR~
    return 0;                                                      //~v7duI~
}//ucvext_cfgmapu                                                  //~v7duI~
//**************************************************************** //~vbB4I~
PUCVEXTCFG ucvext_getpcfg(int Popt)                                //~vbB4I~
{                                                                  //~vbB4I~
	UTRACED("Spcfg",Spcfg,UCVEXTCFGSZ);                            //~vbB4I~
	return Spcfg;                                                  //~vbB4I~
}                                                                  //~vbB4I~
//**************************************************************** //~vbB9I~
void ucvext_notifyTables()                                         //~vbB9I~
{                                                                  //~vbB9I~
	int ii;                                                        //~vbB9I~
    UCHAR *pc,asc;                                                 //~vbB9I~
	UTRACEP("%s\n",UTT);                                             //~vbB9I~//~v7dhR~
    for (ii=0,pc=Sebc2asc037;ii<256;ii++,pc++)                     //~vbB9I~
    {                                                              //~vbB9I~
        asc=*pc;                                                   //~vbB9I~
        if (asc)                                                   //~vbB9I~
            Sasc2ebc037[asc]=(UCHAR)ii;    //reverse map           //~vbB9I~
    }                                                              //~vbB9I~
    ucvebcTables(Sebc2asc037,Sasc2ebc037);                         //~vbB9I~
}                                                                  //~vbB9I~
//****************************************************************
//*get charset cfg parm
//*rc1:1 file not found(Warning)                                   //~v68cR~
//****************************************************************
int ucvext_getcfg(int Popt,char *Pcfgfnm,PUCVEXTCFG Ppcfg)
{
	FILE *fh;
#define CFGLINESZ  512                                             //~v5mTR~
    UCHAR buff[CFGLINESZ],*pc;
    UPODELMTBL buffdelmt[CFGLINESZ];                               //~v5mTR~
    PUPODELMTBL pdelmt=buffdelmt;                                  //~v5mTI~
    UCHAR buffpo[CFGLINESZ];                                       //~v5mTI~
    UCHAR *ppo=buffpo,/**popd,*/*pval,*pval2;                      //~v6b9R~
//  char *pdelmstr=" \t";                                          //~v7dsR~
    char *pdelmstr=" \t:";                                         //~v7dsI~
    int opt=UPARSE2TABISSPACE|UPARSE2USEAREAPARM;
    int opdno,readlen,rc;
//  USHORT ucs;                                                    //~v7dKR~
//*******************************
//*file1
    UTRACEP("%s:popt=0x%08x,Gucvebc_stat=0x%08x,fnm=%s\n",UTT,Popt,Gucvebc_stat,Pcfgfnm);                          //~vbB4I~//~v7d3R~//~vbB8R~//~v7dcR~
    memset(Ppcfg,0,UCVEXTCFGSZ);
  if (!*Pcfgfnm)                                                   //~vbBcI~
  {                                                                //~vbBcI~
    fh=0;                                                          //~vbBcI~
    Popt|=UCEIO_NOERRMSG;                                          //~vbBcI~
  }                                                                //~vbBcI~
  else                                                             //~vbBcI~
  {                                                                //~vbBcI~
	fh=fopen(Pcfgfnm,"r");	//exit when open faile
  }                                                                //~vbBcI~
UTRACEP("%s:OPEN inp=%s,fh=%p,Ppcfg=%p\n",UTT,Pcfgfnm,fh,Ppcfg);                         //~v6baR~//~v77ER~
    if (!fh)
    {
#ifdef UTF8EBCD                                                    //~v660I~
		Ppcfg->UCECflag|=UCECF_OPENERR;                            //~v660I~
#endif                                                             //~v660I~
    	if (Popt & UCEIO_ERREXIT)                                  //~v69vI~
        	uerrexit("open failed for %s",0,                       //~v69vR~
            			Pcfgfnm);                                  //~v69vI~
    	if (Popt & UCEIO_NOERRMSG)
        	return 1;
    	return ufileapierr("fopen",Pcfgfnm,1);
    }
    if (Gucvebc_stat & UCVEBCS_CMDLINEOPTION) // 0x0100 //xe cmdline option cp930/cp939/cp037 specified//~vbB6I~
    {                                                              //~vbB6I~
//        uerrmsg("cmdline option %cc{%s|%s|%s} is ignored if cfg file(%s) was prepared",//~vbB6I~//~vbB8R~
//                "ƒRƒ}ƒ“ƒhƒ‰ƒCƒ“ƒIƒvƒVƒ‡ƒ“ %cc{%s|%s|%s} ‚Í cfg ƒtƒ@ƒCƒ‹(%s) ‚ª‚ ‚é‚Æ‚«‚Í–³Ž‹‚³‚ê‚Ü‚·",//~vbB6I~//~vbB8R~
//                CMDFLAG_PREFIX,EBC_KANA,EBC_ENG,EBC_US,Pcfgfnm);   //~vbB6R~//~vbB8R~
        uerrmsg("cmdline %c%s option except cfg= is ignored if cfg file(%s) was prepared",//~vbB8I~//~vbBcR~
//              "ƒRƒ}ƒ“ƒhƒ‰ƒCƒ“ƒIƒvƒVƒ‡ƒ“ %c%s ‚Í cfg ƒtƒ@ƒCƒ‹(%s) ‚ª‚ ‚é‚Æ‚«‚Í–³Ž‹‚³‚ê‚Ü‚·",//~vbB8I~//~vbBcR~
#ifdef LNX                                                         //~v7deI~
                0,                                                 //~v7deI~
#else                                                              //~v7deI~
                "cfg= ˆÈŠO‚ÌƒRƒ}ƒ“ƒhƒ‰ƒCƒ“ƒIƒvƒVƒ‡ƒ“ %c%s ‚Í cfg ƒtƒ@ƒCƒ‹(%s) ‚ª‚ ‚é‚Æ‚«‚Í–³Ž‹‚³‚ê‚Ü‚·",//~vbBcI~
#endif                                                             //~v7deI~
                CMDFLAG_PREFIX,EBC_STREBC,Pcfgfnm);                //~vbB8R~
        Gucvebc_stat &=~(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_ALL);//~vbB6R~//~vbB9R~
    	UTRACEP("%s:Gucvebc_stat=0x%08x\n",UTT,Gucvebc_stat);      //~vbB6I~
    }                                                              //~vbB6I~
    for (;;)
    {
        if (!fgets(buff,CFGLINESZ,fh))	//eof
        	break;
        USTR_DROPEOL_GETLEN(buff,readlen);
        pc=buff+strspn(buff," \t");
        if (*pc=='#')          //comment line
        	continue;
        uparse2(pc,&pdelmt,&ppo,&opdno,opt,pdelmstr);//no ignore crlf,no delmstr//~v5mTR~
        if (!opdno)    //comment line
        	continue;
        if (opdno<2)        //all var=value  pattern
        	return ucvext_cfglineerr(Pcfgfnm,buff);
//      popd=ppo;                                                  //~v6b9R~
        pval=ppo+strlen(ppo)+1;
        if (opdno>2)        //all var=value  pattern
        {                                                          //~v7dsI~
        	pval2=pval+strlen(pval)+1;
            if (*pval2==':' && *(pval2+1)==0)                      //~v7dsI~
	        	pval2=pval2+strlen(pval2)+1;                       //~v7dsI~
        }                                                          //~v7dsI~
        else
        	pval2=0;
        UTRACEP("%s:%s pval=%s pval2=%s \n",UTT,ppo,pval,pval2);                        //~vbBcI~//~v7dsR~
        if (!stricmp(ppo,UCVEXTCFGPARM_CSDBCS))
            UstrncpyZ(Ppcfg->UCECcsnamedbcs,pval,MAX_CSNAMESZ);
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_CSSBCS))
        {
        	if (!stricmp(pval,UCVEXTCFGPARM_CSSBCSDEF)) //default
            {                                                      //~v6hyI~
                if (*Ppcfg->UCECcsnamesbcs)                         //~v6hyI~//~v6hzR~
                {                                                  //~v6hyI~
					uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~vbBcR~
                    uerrmsg("xeebc.map:%s %s conflict with previous specification(%s)",0,//~v6hyR~//~v6hzR~
							UCVEXTCFGPARM_CSSBCS,UCVEXTCFGPARM_CSSBCSDEF,Ppcfg->UCECcsnamesbcs);//~v6hyR~
					*Ppcfg->UCECcsnamesbcs=0;                      //~v6hyI~
                }                                                  //~v6hyI~
	            Ppcfg->UCECflag|=UCECF_SBCSDEF;
		        Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;              //~v7dPR~
            	if (Ppcfg->UCECflag & UCECF_USE_CONVERTER)         //~v7drI~
                {                                                  //~v7drI~
					uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~v7drI~
                    uerrmsg("xeebc.map:%s available only when not \"%s 0\".",0,//~v7drR~
				        	UCVEXTCFGPARM_CSSBCSDEF,UCVEXTCFGPARM_EXT);//~v7drI~
		            Ppcfg->UCECflag&=~UCECF_SBCSDEF;               //~v7drI~
                }                                                  //~v7drI~
            }                                                      //~v6hyI~
            else
        	if (!stricmp(pval,UCVEXTCFGPARM_CSSBCSDEF_EURO)) //defaultMap_Euro//~v7dPR~
            {                                                      //~v7dPI~
                if (*Ppcfg->UCECcsnamesbcs)                        //~v7dPI~
                {                                                  //~v7dPI~
					uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~v7dPI~
                    uerrmsg("xeebc.map:%s %s conflict with previous specification(%s)",0,//~v7dPI~
							UCVEXTCFGPARM_CSSBCS,UCVEXTCFGPARM_CSSBCSDEF_EURO,Ppcfg->UCECcsnamesbcs);//~v7dPR~
					*Ppcfg->UCECcsnamesbcs=0;                      //~v7dPI~
                }                                                  //~v7dPI~
	            Ppcfg->UCECflag|=UCECF_SBCSDEF;                    //~v7dPI~
	            Ppcfg->UCECflag2|=UCECF2_CP037_EURO;               //~v7dPR~
            	if (Ppcfg->UCECflag & UCECF_USE_CONVERTER)         //~v7dPI~
                {                                                  //~v7dPI~
					uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~v7dPI~
                    uerrmsg("xeebc.map:%s available only when not \"%s 0\".",0,//~v7dPI~
				        	UCVEXTCFGPARM_CSSBCSDEF_EURO,UCVEXTCFGPARM_EXT);//~v7dPR~
		            Ppcfg->UCECflag&=~UCECF_SBCSDEF;               //~v7dPI~
			        Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;          //~v7dPR~
                }                                                  //~v7dPI~
            }                                                      //~v7dPI~
            else                                                   //~v7dPI~
            {                                                      //~v6hyI~
	            if (Ppcfg->UCECflag & UCECF_SBCSDEF)               //~v6hyI~
                {                                                  //~v6hyI~
					uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~vbBcI~
                    uerrmsg("xeebc.map:%s %s conflict with previous specification(%s)",0,//~v6hyR~//~v6hzR~
							UCVEXTCFGPARM_CSSBCS,pval,UCVEXTCFGPARM_CSSBCSDEF);//~v6hyR~
		            Ppcfg->UCECflag&=~UCECF_SBCSDEF;               //~v6hyI~
                }                                                  //~v6hyI~
	            UstrncpyZ(Ppcfg->UCECcsnamesbcs,pval,MAX_CSNAMESZ);
            }                                                      //~v6hyI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_CSLOCAL))
	    	UstrncpyZ(Ppcfg->UCECcsnamelocal,pval,MAX_CSNAMESZ);
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_EXT)) //external converter useage
        {
            if (Ppcfg->UCECflag2 & UCECF2_CONVERTER_PARM)          //~v6x9I~
	        	return ucvext_cfgdupoption(Pcfgfnm,ppo);           //~v6x9R~
            switch (*pval)
            {
            case '0':          //ignore this file
            	Ppcfg->UCECflag2|=UCECF2_CONVERTER_PARM;           //~v6x9I~
                break;
            case '1':
            	Ppcfg->UCECflag2|=UCECF2_CONVERTER_PARM;           //~v6x9I~
            	Ppcfg->UCECflag|=(UCECF_USE_CONVERTER);
            	Ppcfg->UCECflag|=(UCECF_USE_ICU);                  //~v5n2I~
                break;
            case '2':                                              //~v5n2I~
            	Ppcfg->UCECflag2|=UCECF2_CONVERTER_PARM;           //~v6x9I~
            	Ppcfg->UCECflag|=(UCECF_USE_CONVERTER);            //~v5n2I~
				Ppcfg->UCECflag|=UCECF_USE_ICONV;//     0x1000      //CONVERTER is ICONV or MutiByteToWideChar//~v5n2I~
                break;                                             //~v5n2I~
            case 'f':                                              //~v66rR~
            case 'F':                                              //~v66rI~
            	Ppcfg->UCECflag|=(UCECF_USE_CONVERTER);            //~v66rI~
            	Ppcfg->UCECflag|=(UCECF_USE_ICU|UCECF_ICUFALLBACK);//~v66rI~
                break;                                             //~v66rI~
            default:
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            }
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_DLL))
            UstrncpyZ(Ppcfg->UCECdllsuffix,pval,sizeof(Ppcfg->UCECdllsuffix));
        else                                                       //~v6bnI~
        if (!stricmp(ppo,UCVEXTCFGPARM_ICUDATA))                   //~v6bnI~
        {                                                          //~v6bnI~
			udos_setenv(0,ICU_DATAENVNAME,pval);    //putenv should not free source string, setenv(not in Windows) copyed to env//~v6bnI~
	        Ppcfg->UCECflag2|=UCECF2_ICUDATA;                      //~v6bpI~
            Sicudataparm=strdup(pval);                             //~v6M0I~
        }                                                          //~v6bnI~
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_API))
            UstrncpyZ(Ppcfg->UCECapisuffix,pval,sizeof(Ppcfg->UCECapisuffix));
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_MAPE2A))
        {
          if (Ppcfg->UCECflag & (UCECF_USE_CONVERTER))             //~v7dvI~
          {                                                        //~v7dvI~
			uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);               //~v7dvI~
            uerrmsg("%s is for %s is \"1\" or \"2\".\n",0,         //~v7dvI~
			        UCVEXTCFGPARM_MAPE2A,UCVEXTCFGPARM_EXT);       //~v7dvI~
          }                                                        //~v7dvI~
          else                                                     //~v7dvI~
          {                                                        //~v7dvI~
        	if (toupper(*pval2)=='U')                              //~v7duI~
            {                                                      //~v7duI~
	            if (rc=ucvext_cfgmapu(0,Ppcfg->UCECsbcsmape2u,pval,pval2+1),rc)//~v7duI~
	 	       		return ucvext_cfglineerr(Pcfgfnm,buff);        //~v7duI~
            }                                                      //~v7duI~
            else                                                   //~v7duI~
            if (rc=ucvext_cfgmap(0,Ppcfg->UCECsbcsmape2a,pval,pval2),rc)
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            Ppcfg->UCECflag|=UCECF_E2A;
          }                                                        //~v7dvI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_MAPA2E))
        {
          if (Ppcfg->UCECflag & (UCECF_USE_CONVERTER))             //~v7dvI~
          {                                                        //~v7dvI~
			uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);               //~v7dvI~
            uerrmsg("%s is for %s is \"1\" or \"2\".\n",0,         //~v7dvI~
			        UCVEXTCFGPARM_MAPA2E,UCVEXTCFGPARM_EXT);       //~v7dvI~
          }                                                        //~v7dvI~
          else                                                     //~v7dvI~
          {                                                        //~v7dvI~
            if (rc=ucvext_cfgmap(1,Ppcfg->UCECsbcsmapa2e,pval,pval2),rc)
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            Ppcfg->UCECflag|=UCECF_A2E;
          }                                                        //~v7dvI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_MAPF2A))
        {
#ifdef BBB                                                         //~v7dsM~
            if (rc=ucvext_cfgmap(1,Ppcfg->UCECsbcsmapf2a,pval,pval2),rc)
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            Ppcfg->UCECflag|=UCECF_F2A;
#else                                                              //~v7dsI~
				uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);           //~v7dsI~
                uerrmsg("%s was deprecated.\n",0,                  //~v7dsR~
			        UCVEXTCFGPARM_MAPF2A);                         //~v7dsI~
#endif //BBB                                                       //~v7dsI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_MAPA2F))
        {
#ifdef BBB                                                         //~v7dsI~
            if (rc=ucvext_cfgmap(1,Ppcfg->UCECsbcsmapa2f,pval,pval2),rc)
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            Ppcfg->UCECflag|=UCECF_A2F;
#else                                                              //~v7dsI~
				uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);           //~v7dsI~
                uerrmsg("%s was deprecated.\n",0,                  //~v7dsR~
			        UCVEXTCFGPARM_MAPA2F);                         //~v7dsI~
#endif //BBB                                                       //~v7dsM~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_SUBCHARD))
        {
//            if (ucvext_ux2s(pval,&ucs))                            //~v5mTR~//~v7dKR~
//                return ucvext_cfglineerr(Pcfgfnm,buff);          //~v7dKR~
//            Ppcfg->UCECsubchardbcs=ucs;                          //~v7dKR~
            uerrmsg("%s was deprecated.\n",0,                      //~v7dKI~
			        UCVEXTCFGPARM_SUBCHARD);                       //~v7dKI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_SUBCHARS))
        {
//            if (ucvext_ux2s(pval,&ucs))                            //~v5mTI~//~v7dKR~
//                return ucvext_cfglineerr(Pcfgfnm,buff);          //~v7dKR~
//            Ppcfg->UCECsubcharsbcs=ucs;                          //~v7dKR~
            uerrmsg("%s was deprecated.\n",0,                      //~v7dKI~
			        UCVEXTCFGPARM_SUBCHARS);                       //~v7dKI~
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_REPLF))
        {
            switch (*pval)
            {
            case '0':          //ignore this file
                break;
            case '1':
    	        Ppcfg->UCECflag|=UCECF_REPLF;
                break;
            default:
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            }
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_NOS2D))
        {
            switch (*pval)
            {
            case '0':          //ignore this file
                break;
            case '1':
    	        Ppcfg->UCECflag|=UCECF_NOS2D;
                break;
            default:
	        	return ucvext_cfglineerr(Pcfgfnm,buff);
            }
        }
        else
        if (!stricmp(ppo,UCVEXTCFGPARM_SJISOPT))                   //~v5mUI~
        {                                                          //~v5mUI~
            if (!stricmp(pval,"IBM"))                              //~v5mUR~
    	        Ppcfg->UCECflag|=UCECF_IBM;                        //~v5mUI~
            else                                                   //~v5mUI~
            if (!stricmp(pval,"NEC"))                              //~v5mUR~
    	        Ppcfg->UCECflag|=UCECF_NEC;                        //~v5mUI~
            else                                                   //~v5mUI~
            if (!stricmp(pval,"JIS78"))                            //~v5mUR~
    	        Ppcfg->UCECflag|=UCECF_JIS78;                      //~v5mUI~
            else                                                   //~v5mUI~
            if (!stricmp(pval,"JIS83"))                            //~v5mUR~
    	        Ppcfg->UCECflag|=UCECF_JIS83;                      //~v5mUI~
            else                                                   //~v5mUI~
#ifdef UTF8EBCD                                                    //~v660I~
    		if (!stricmp(pval,EBCID_ENGEXT))     //CP939           //~v660R~
            {                                                      //~v7d5I~
            	Ppcfg->UCECflag|=UCECF_CP939;	//use internal map//~v660R~//~v66hR~
            	Ppcfg->UCECflag&=~UCECF_CP930;	//use internal map //~v7d5I~
//          	Ppcfg->UCECflag2&=~(UCECF2_BASE|UCECF2_CP931);	//use internal map //~v7d5R~//~vbB9R~//~v7dmR~
            	Ppcfg->UCECflag2&=~(            UCECF2_CP931);	//use internal map//~v7dmI~
            	Ppcfg->UCECflag2|=UCECF2_SJISOPT_CP;               //~v7dcI~
                UTRACEP("%s:SJISOPT=%s\n",UTT,pval);               //~vbB9I~
            }                                                      //~v7d5I~
        	else                                                   //~v660I~
    		if (!stricmp(pval,EBCID_KANAEXT))      //CP930         //~v660R~
            {                                                      //~v7d5I~
            	Ppcfg->UCECflag|=UCECF_CP930;         //~v660R~    //~v66hR~
            	Ppcfg->UCECflag&=~UCECF_CP939;	//use internal map //~v7d5I~
//          	Ppcfg->UCECflag2&=~(UCECF2_BASE|UCECF2_CP931);	//use internal map //~v7d5R~//~vbB9R~//~v7dmR~
            	Ppcfg->UCECflag2&=~(            UCECF2_CP931);	//use internal map//~v7dmI~
            	Ppcfg->UCECflag2|=UCECF2_SJISOPT_CP;               //~v7dcI~
                UTRACEP("%s:SJISOPT=%s\n",UTT,pval);               //~vbB9I~
            }                                                      //~v7d5I~
//            else                                                   //~v660I~//~v7dmR~
//            if (!stricmp(pval,EBCID_BASE))      //CP037(DP94)+CP300//~v7d5R~//~v7dmR~
//            //*"BASE"                                              //~v7d9I~//~v7dmR~
//            {                                                      //~v7d5I~//~v7dmR~
//                Ppcfg->UCECflag&=~(UCECF_CP930|UCECF_CP939);       //~v7d5R~//~v7dmR~
//                Ppcfg->UCECflag2&=~UCECF2_CP931;                   //~vbB9I~//~v7dmR~
//                Ppcfg->UCECflag2|=UCECF2_BASE;                     //~v7d5R~//~v7dmR~
//            }                                                      //~v7d5I~//~v7dmR~
        	else                                                   //~v7d5I~
//            if (!stricmp(pval,EBCID_LATIN))      //CP037+CP300     //~vbB9I~//~vbBsR~
//            {                                                      //~vbB9I~//~vbBsR~
//                Ppcfg->UCECflag&=~(UCECF_CP930|UCECF_CP939);       //~vbB9I~//~vbBsR~
////              Ppcfg->UCECflag2&=~UCECF2_BASE;                    //~vbB9I~//~v7dmR~//~vbBsR~
//                Ppcfg->UCECflag2|=UCECF2_CP931;                    //~vbB9I~//~vbBsR~
//                Ppcfg->UCECflag2|=UCECF2_SJISOPT_CP;               //~v7dcI~//~vbBsR~
//                UTRACEP("%s:SJISOPT=%s\n",UTT,pval);               //~vbB9I~//~vbBsR~
//            }                                                      //~vbB9I~//~vbBsR~
//            else                                                   //~vbB9I~//~vbBsR~
#endif                                                             //~v660I~
	        	return ucvext_cfglineerr(Pcfgfnm,buff);            //~v5mUI~
        }                                                          //~v5mUI~
        else                                                       //~v5mUI~
        if (!stricmp(ppo,UCVEXTCFGPARM_SOSIA2E))                   //~v5mVI~
        {                                                          //~v5mVI~
            if (!stricmp(pval,"SHIFT"))                            //~v5mVI~
    	        Ppcfg->UCECflag|=UCECF_SOSISHIFT;                  //~v5mVI~
            else                                                   //~v5mVI~
            if (!stricmp(pval,"INS"))                              //~v5mVR~
    	        Ppcfg->UCECflag|=UCECF_SOSIINS;                    //~v5mVI~
            else                                                   //~v5mVI~
            if (!stricmp(pval,"REP"))                              //~v5mVI~
    	        Ppcfg->UCECflag|=UCECF_SOSIREP;                    //~v5mVI~
            else                                                   //~v5mVI~
	        	return ucvext_cfglineerr(Pcfgfnm,buff);            //~v5mVI~
        }                                                          //~v5mVI~
        else                                                       //~v5mVI~
        if (!stricmp(ppo,UCVEXTCFGPARM_SOSIE2A))                   //~v5mVI~
        {                                                          //~v5mVI~
            if (!stricmp(pval,"DEL"))                              //~v5mVI~
    	        Ppcfg->UCECflag|=UCECF_SOSIDEL;                    //~v5mVI~
            else                                                   //~v5mVI~
            if (!stricmp(pval,"REP"))                              //~v5mVI~
    	        Ppcfg->UCECflag|=UCECF_SOSIREPSP;                  //~v5mVI~
            else                                                   //~v5mVI~
	        	return ucvext_cfglineerr(Pcfgfnm,buff);            //~v5mVI~
        }                                                          //~v5mVI~
        else                                                       //~v5mVI~
        	return ucvext_cfglineerr(Pcfgfnm,buff);
    }
    if (!Sicudataparm || !*Sicudataparm)	//missing ICU_DATA parm//~v6M1R~
    {                                                              //~v6M1I~
    	Sicudataparm=getenv(ICU_DATAENVNAME);                      //~v6M1R~
        UTRACEP("%s:ICU_DATA env=%s\n",UTT,Sicudataparm);          //~v6M1I~
        if (Sicudataparm)                                          //~v6M1I~
			Sicudataparm=strdup(Sicudataparm);                     //~v6M1I~
        UTRACEP("%s:ICU_DATA env=%s\n",UTT,Sicudataparm);          //~v6M1I~
	}                                                              //~v6M1I~
    UTRACEP("%s:flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7dcR~
    if ((Ppcfg->UCECflag & UCECF_USE_CONVERTER)==0)                //~vbBcI~
    {                                                              //~vbBcI~
    	char *dbcscv=Ppcfg->UCECcsnamedbcs;                        //~vbBcI~
        if (*dbcscv!=0)                                            //~vbBcI~
        {                                                          //~vbBcI~
            if (!stricmp(dbcscv,EBC_KANA))         //CP930         //~vbBcR~
                Ppcfg->UCECflag|=UCECF_CP930;                      //~vbBcR~
            else                                                   //~vbBcR~
            if (!stricmp(dbcscv,EBC_ENG))          //CP939         //~vbBcR~
                Ppcfg->UCECflag|=UCECF_CP939;                      //~vbBcR~
//            else                                                   //~vbBcR~//~vbBsR~
//            if (!stricmp(dbcscv,EBC_KANJI_LATIN))  //CP939L        //~vbBcR~//~vbBsR~
//                Ppcfg->UCECflag2|=UCECF2_CP931;                    //~vbBcR~//~vbBsR~
            else                                                   //~vbBcR~
            {                                                      //~vbBcR~
				uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);           //~vbBcI~
//              uerrmsg("xeebc.map:if %s=0, %s should be one of %s/%s/%s.\n"//~vbBcR~//~vbBsR~
                uerrmsg("xeebc.map:if %s=0, %s should be one of %s/%s.\n"//~vbBsI~
//  "OR if not use Japanese DBCS, specify %s=%s widthout %s option.",0,//~vbBcR~//~vbBsR~
                            ,0,                                    //~vbBsI~
                            UCVEXTCFGPARM_EXT,        //external converter useage//~vbBcR~
                            UCVEXTCFGPARM_CSDBCS,    //  "SBCS_CHARSET"//~vbBcR~
//                          EBC_KANA,EBC_ENG,EBC_KANJI_LATIN,      //~vbBcR~//~vbBsR~
                            EBC_KANA,EBC_ENG);                     //~vbBsR~
//                          UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~vbBcR~//~vbBsR~
//                          UCVEXTCFGPARM_CSSBCSDEF, //  "DefaultMap"//~vbBcR~//~vbBsR~
//                          UCVEXTCFGPARM_CSDBCS);   //  "SBCS_CHARSET"//~vbBcR~//~vbBsR~
                memset(Ppcfg->UCECcsnamedbcs,0,sizeof(Ppcfg->UCECcsnamedbcs));//~vbBcR~
            }                                                      //~vbBcR~
        }                                                          //~vbBcI~
    	char *sbcscv=Ppcfg->UCECcsnamesbcs;                        //~vbBcI~
        if (*sbcscv!=0)                                            //~vbBcR~
        {                                                          //~vbBcI~
//            if (!stricmp(sbcscv,EBC_US))   //CP037                 //~vbBcI~//~v7dnR~
//            {                                                      //~vbBcR~//~v7dnR~
//                if ((Ppcfg->UCECflag & (UCECF_CP930|UCECF_CP939))  //~vbBcR~//~v7dnR~
//                ||  (Ppcfg->UCECflag2 & (UCECF2_CP931))            //~vbBcR~//~v7dnR~
//                )                                                  //~vbBcR~//~v7dnR~
//                {                                                  //~vbBcR~//~v7dnR~
//                    uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);       //~vbBcI~//~v7dnR~
//                    uerrmsg("xeebc.map:if %s=0, %s can be used without %s or %s=%s/%s/%s.",0,//~vbBcR~//~v7dnR~
//                            UCVEXTCFGPARM_EXT,        //external converter useage//~vbBcR~//~v7dnR~
//                            UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~vbBcR~//~v7dnR~
//                            UCVEXTCFGPARM_CSDBCS,    //  "DBCS_CHARSET"//~vbBcR~//~v7dnR~
//                            UCVEXTCFGPARM_SJISOPT,    //  "SJIS_OPT"//~vbBcR~//~v7dnR~
//                            EBCID_KANAEXT,  //      "KANA_EXT"       //CP930=CP290(katakanaExt)+CP300//~vbBcR~//~v7dnR~
//                            EBCID_ENGEXT,   //      "ENG_EXT"        //CP939=CP1027(EnglishExt)+CP300//~vbBcR~//~v7dnR~
//                            EBCID_LATIN);    //      "LATIN"          //CP300+cp037 = CP931//~vbBcR~//~v7dnR~
//                    memset(Ppcfg->UCECcsnamesbcs,0,sizeof(Ppcfg->UCECcsnamesbcs));//~vbBcR~//~v7dnR~
//                }                                                  //~vbBcR~//~v7dnR~
//                else                                               //~vbBcI~//~v7dnR~
//                {                                                  //~vbBcI~//~v7dnR~
//                    Ppcfg->UCECflag2|=UCECF2_CP037; //widthout SJISOPT//~vbBcR~//~v7dnR~
////                  Gucvebc_stat|=UCVEBCS_SBCSLATIN;               //~v7diI~//~v7dmR~//~v7dnR~
//                    UTRACEP("%s:CONVERTER=0 and SBCSCHARSET=CP037\n",UTT);//~vbBcR~//~v7dnR~
//                    memset(Ppcfg->UCECcsnamesbcs,0,sizeof(Ppcfg->UCECcsnamesbcs));//~vbBcI~//~v7dnR~
//                }                                                  //~vbBcI~//~v7dnR~
//            }                                                      //~vbBcI~//~v7dnR~
//            else                                                   //~vbBcI~//~v7dnR~
            {                                                      //~vbBcI~
				uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);           //~vbBcI~
//              uerrmsg("xeebc.map:if %s=0, specify %s or %s for %s.\n"//~vbBcR~//~v7dnR~
                uerrmsg("xeebc.map:if %s=0, specify %s for %s.\n"  //~v7dnI~
//"OR, if Japanese User, specify DBCS type by %s or %s",0,           //~vbBcR~//~v7dnR~
"OR, if Japanese User, specify DBCS converter by %s",0,            //~v7dnI~
                        UCVEXTCFGPARM_EXT,        //external converter useage//~vbBcI~
						UCVEXTCFGPARM_CSSBCSDEF,  //  "DefaultMap" //~vbBcI~
//			        	EBC_US,                   //CP037          //~vbBcI~//~v7dnR~
                        UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~vbBcR~
//                      UCVEXTCFGPARM_CSDBCS,    //  "DBCS_CHARSET"//~vbBcR~//~v7dnR~
						UCVEXTCFGPARM_SJISOPT);   //     "SJIS_OPT"//~vbBcI~
                memset(Ppcfg->UCECcsnamesbcs,0,sizeof(Ppcfg->UCECcsnamesbcs));//~vbBcI~
            }                                                      //~vbBcI~
        }                                                          //~vbBcI~
    }//converter=0                                                 //~vbBcR~
	if (Ppcfg->UCECflag & UCECF_SBCSDEF)                           //~v7dcI~
    {                                                              //~v7dcM~
    	if (Ppcfg->UCECflag2 & UCECF2_SJISOPT_CP)                  //~v7dcR~
        {                                                          //~v7dcI~
			uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);               //~vbBcI~
//          uerrmsg("xeebc.map:%s=%s conflicts with %s=%s/%s/%s option.\n"//~v7dcR~//~vbBsR~
            uerrmsg("xeebc.map:%s=%s(=CP037) conflicts with %s=%s/%s option.\n"//~vbBsR~
//"To use CP037 mapping as %s width Japanese DBCS, simply specify %s=%s.\n"//~v7dcI~//~vbBsR~
"If no DBCS, specify it widthout %s.",0,                           //~v7dcR~
						UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~v7dcI~
						UCVEXTCFGPARM_CSSBCSDEF, //  "DefaultMap"  //~v7dcI~
						UCVEXTCFGPARM_SJISOPT,    //  "SJIS_OPT"   //~v7dcI~
						EBCID_KANAEXT,	//      "KANA_EXT"       //CP930=CP290(katakanaExt)+CP300//~v7dcI~
						EBCID_ENGEXT,	//      "ENG_EXT"        //CP939=CP1027(EnglishExt)+CP300//~v7dcI~
//  					EBCID_LATIN,    //      "LATIN"          //CP300+cp037 = CP931//~v7dcR~//~vbBsR~
//  					UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~v7dcI~//~vbBsR~
    					UCVEXTCFGPARM_SJISOPT,    //  "SJIS_OPT"   //~v7dcI~
//  					EBCID_LATIN,    //      "LATIN"          //CP300+cp037 = CP931//~v7dcR~//~vbBsR~
						UCVEXTCFGPARM_SJISOPT);    //  "SJIS_OPT"  //~v7dcI~
		    Ppcfg->UCECflag &= ~UCECF_SBCSDEF;                     //~v7dcI~
        }                                                          //~v7dcI~
        if (*Ppcfg->UCECcsnamedbcs)                                //~v7dcI~
        {                                                          //~v7dcI~
			uerrmsg("EBCDIC cfg file=%s",0,Pcfgfnm);               //~vbBcI~
//          uerrmsg("xeebc.map:%s=%s conflicts with %s option.\nTo use CP037 mapping width Japanese DBCS, simply specify %s=%s.",0,//~v7dcI~//~vbBsR~
            uerrmsg("xeebc.map:%s=%s conflicts with %s option.\nCP037 mapping is SBCS only.",0,//~vbBsI~
						UCVEXTCFGPARM_CSSBCS,    //  "SBCS_CHARSET"//~v7dcI~
						UCVEXTCFGPARM_CSSBCSDEF, //  "DefaultMap"  //~v7dcI~
//  					UCVEXTCFGPARM_CSDBCS,     // "DBCS_CHARSET"//~v7dcI~//~vbBsR~
    					UCVEXTCFGPARM_CSDBCS);    // "DBCS_CHARSET"//~vbBsI~
//  					UCVEXTCFGPARM_SJISOPT,    //  "SJIS_OPT"   //~v7dcI~//~vbBsR~
//  					EBCID_LATIN);    //      "LATIN"          //CP300+cp037 = CP931//~v7dcI~//~vbBsR~
		    Ppcfg->UCECflag &= ~UCECF_SBCSDEF;                     //~v7dcI~
        }                                                          //~v7dcI~
    }                                                              //~v7dcI~
//#ifdef LNX                                                       //~v66wR~
//    if (!*Ppcfg->UCECcsnamelocal)   //no local                   //~v66wR~
//    {                                                            //~v66wR~
//        if (UTF8MODEENV())   //env codeset is .UTF-8             //~v66wR~
//        {                                                        //~v66wR~
//            pval=utfcvsetdefaultlocale();                        //~v66wR~
//            if (pval)                                            //~v66wR~
//            {                                                    //~v66wR~
//                UstrncpyZ(Ppcfg->UCECcsnamelocal,pval,MAX_CSNAMESZ);//~v66wR~
//#ifdef AAA   //bothersome                                        //~v66wR~
//                uerrmsg("%s is not specified, %s was set as it",0,//~v66wR~
//                        UCVEXTCFGPARM_CSLOCAL,pval);             //~v66wR~
//#endif                                                           //~v66wR~
//            }                                                    //~v66wR~
//            else                                                 //~v66wR~
//            {                                                    //~v66wR~
//                uerrmsg("specify non-UTF \"%s\" under UTF8 environment",0,//~v66wR~
//                        UCVEXTCFGPARM_CSLOCAL);                  //~v66wR~
//                return 4;                                        //~v66wR~
//            }                                                    //~v66wR~
//        }                                                        //~v66wR~
//    }                                                            //~v66wR~
//#endif                                                           //~v66wR~
	ucvext_setdefaultlocalcv(0,Ppcfg);                             //~v66wI~
	fclose(fh);                                                    //~v5n1I~
    Ppcfg->UCECflag2|=UCECF2_CFGOK;                                //~v68cI~
#ifdef ARM                                                         //~v77EI~
    UTRACEP("%s:UCECapisuffix=%s\n",UTT,Ppcfg->UCECapisuffix);     //~v77EI~
  if (!*Ppcfg->UCECapisuffix)                                      //~v77EI~
#endif                                                             //~v77EI~
	chkicuversion(Ppcfg->UCECdllsuffix,sizeof(Ppcfg->UCECdllsuffix),Ppcfg->UCECapisuffix,sizeof(Ppcfg->UCECapisuffix));//~v6M4I~
	UTRACED("return Ppcfg",Ppcfg,UCVEXTCFGSZ);                     //~vbB6R~
    return 0;
}//ucvext_getcfg
//*************************************************************************//~v66wI~
//*set default local converter for the case utf8 env(wcrtomb is not valid when utf8 env)//~v66wI~//~v66KR~
//from getcfg/xfg mapinit when cfg open err/mapinitsetdefault(xe cfg open err)//~v6f3I~
//*************************************************************************//~v66wI~
int ucvext_setdefaultlocalcv(int Popt,PUCVEXTCFG Ppcfg)            //~v66wR~
{                                                                  //~v66wI~
    UCHAR *pval=0;                                                   //~v66wI~//~v66KR~
//#ifdef LNX                                                         //~v66PI~//~v6f5R~
//#else                                                              //~v66PI~//~v6f5R~
//	ULONG pconverter;                                              //~v66KR~//~v6hhR~
 	ULPTR pconverter;                                              //~v6hhI~
//#endif                                                             //~v66PI~//~v6f5R~
    int rc=0;                                                      //~v66KI~
//***************************                                      //~v66wI~
    UTRACEP("%s:entry name=%s\n",UTT,Ppcfg->UCECcsnamelocal);//~v6c4I~//~vbB9R~
    if (!*Ppcfg->UCECcsnamelocal)   //no local                     //~v66wI~
    {                                                              //~v66wI~
#ifdef LNX                                                         //~v66wI~//~v66KM~
//      if (UTF8MODEENV())   //env codeset is .UTF-8,else use mbrtowc etc//~v66SR~
        if (UDBCSCHK_IS_LOCALICU())                                //~v6f5I~
        {                                                          //~v6f5I~
//  		if (!udbcschk_getbaseconverter(UDCGBC_CHARSET,&pconverter,&pval))//~v6f5I~//~v6fgR~
    		udbcschk_getbaseconverter(UDCGBC_CHARSET,&pconverter,&pval);//~v6fgI~
	    		UstrncpyZ(Ppcfg->UCECcsnamelocal,pval,MAX_CSNAMESZ);//~v6f5I~
//          else                                                   //~v6f5I~//~v6fgR~
//          	rc=4;                                              //~v6f5I~//~v6fgR~
        }                                                          //~v6f5I~
        else                                                       //~v6f5I~
		if (udbcschk_getbaseconverter(UDCGBC_CHARSET,&pconverter,&pval),*pval)	//no -C parameter//~v6fgI~
	    	UstrncpyZ(Ppcfg->UCECcsnamelocal,pval,MAX_CSNAMESZ);   //~v6fgM~
        else                                                       //~v6fgI~
        {                                                          //~v66wI~
			pval=utfcvsetdefaultlocale();                          //~v66wI~
            if (pval)                                              //~v66wI~
            {                                                      //~v66wI~
	    		UstrncpyZ(Ppcfg->UCECcsnamelocal,pval,MAX_CSNAMESZ);//~v66wI~
//#ifdef AAA   //bothersome                                          //~v66wI~//~v6f5R~
//                uerrmsg("%s is not specified, %s was set as it",0, //~v66wI~//~v6f5R~
//                        UCVEXTCFGPARM_CSLOCAL,pval);               //~v66wI~//~v6f5R~
//#endif                                                             //~v66wI~//~v6f5R~
            }                                                      //~v66wI~
            else                                                   //~v66wI~
            {                                                      //~v66wI~
            	uerrmsg("specify non-UTF \"%s\" under UTF8 environment",0,//~v66wI~
        				UCVEXTCFGPARM_CSLOCAL);                    //~v66wI~
            	return 4;                                          //~v66wI~
            }                                                      //~v66wI~
            UTRACEP("%s:name=%s\n",UTT,Ppcfg->UCECcsnamelocal);//~v6c4I~//~vbB9R~
        }                                                          //~v66wI~
#else                                                              //~v66KI~
		udbcschk_getbaseconverter(0,&pconverter,0/*dbcstbl*/);     //~v66KI~
    	pval=Ppcfg->UCECcsnamelocal;                               //~v66KR~
//      sprintf(pval,"%d",pconverter);                             //~v66KI~//~v6L5R~
        sprintf(pval,"%d",(int)pconverter);                        //~v6L5I~
#endif                                                             //~v66wI~//~v66KM~
    }                                                              //~v66wI~
	return rc;                                                      //~v66wI~//~v66KR~
}//ucvext_setdefaultlocalcv                                        //~v66wI~
//#ifdef LNX  //also ARM for win search $PATH                       //~v6baI~//~v6bmR~
//*************************************************************************//~v6baI~
//*get arm so name                                                 //~v6baI~
//*ret version if exist or -1 if so not found                      //~v6baI~
//*************************************************************************//~v6baI~
int ucvext_getarmso1(int Popt,char *Ppath,char *Psoname,char *Psuffix)//~v6baI~
{                                                                  //~v6baI~
	PUDIRLIST pudirlist,pudl0;                                     //~v6baI~
    int ctr,ii,pos,intver=-1;                                      //~v6baI~
    char *pversion;                                                //~v6baI~
    char fpath[_MAX_PATH],*pc;                                         //~v6baI~//~v6bmR~
    int parmsuffix;                                                //~v6baR~
//**********************************                               //~v6baI~
    UTRACEP("%s:path=%s,suffix=%s\n",UTT,Ppath,Psuffix);        //~v6baI~//~vbB9R~
    parmsuffix=Psuffix && *Psuffix;                                //~v6baI~
    if (!parmsuffix)                                               //~v6baI~
#ifdef W32                                                         //~v6bmI~
		sprintf(fpath,"%s\\*%s*.dll",Ppath,ICU_DLLNAME);   //cgicuucxx for cygwin//~v6bmR~
#else                                                              //~v6bmI~
    #ifdef ARM                                                     //~v774I~
	  if (swNewICU4C)                                              //~v774I~
		sprintf(fpath,"%s/lib%s.so*",Ppath,ICU_DLLNAME2);          //~v774I~
      else                                                         //~v774I~
    #endif                                                         //~v774I~
		sprintf(fpath,"%s/lib%s.so*",Ppath,ICU_DLLNAME);          //~v6baR~//~v6bmR~
#endif                                                             //~v6bmI~
    else                                                           //~v6baI~
#ifdef W32                                                         //~v6bmI~
		sprintf(fpath,"%s\\*%s*%s.dll",Ppath,ICU_DLLNAME,Psuffix); //~v6bmR~
#else                                                              //~v6bmI~
    #ifdef ARM                                                     //~v774I~
	  if (swNewICU4C)                                              //~v774I~
		sprintf(fpath,"%s/lib%s.so.%s",Ppath,ICU_DLLNAME2,Psuffix);//~v774I~
      else                                                         //~v774I~
    #endif                                                         //~v774I~
		sprintf(fpath,"%s/lib%s.so.%s",Ppath,ICU_DLLNAME,Psuffix);//~v6baI~//~v6bmR~
#endif                                                             //~v6bmI~
    ctr=udirlistnomsg(fpath,FILE_ALL-FILE_DIRECTORY,&pudl0,'L'/*longname sort*/);//~v6baR~
    UTRACEP("%s:dirlist %s ctr=%d\n",UTT,fpath,ctr);            //~v6baI~//~vbB9R~
    if (ctr<=0) //not found                                        //~v6baI~
        return intver;                                             //~v6baI~
    *Psoname=0;                                                    //~v6M1I~
    for (pudirlist=pudl0,ii=0;ii<ctr;ii++,pudirlist++)             //~v6baI~
    {                                                              //~v6baI~
    	UTRACEP("%s:%s/%s\n",UTT,fpath,pudirlist->name);	       //~v6baI~//~vbB9R~
//      if (!ii)                                                   //~v6baI~//~v6g2R~
//      	strcpy(Psoname,pudirlist->name);                       //~v6baI~//~v6g2R~
        sprintf(Psoname,"%s%c%s",Ppath,DIR_SEPC,pudirlist->name);  //~v6g2R~
        UTRACEP("%s:Psoname=%s\n",UTT,Psoname);                    //~v6M1R~
#ifdef W32                                                         //~v6bmI~
    	pc=strstr(pudirlist->name,ICU_DLLNAME);                    //~v6bmI~
//    	pos=(ULONG)pc-(ULONG)pudirlist->name+sizeof(ICU_DLLNAME)-1;//~v6bmI~//~v6hhR~
//  	pos=(ULPTR)pc-(ULPTR)pudirlist->name+sizeof(ICU_DLLNAME)-1;//~v6hhI~//~v6ByR~
    	pos=(int)((ULPTR)pc-(ULPTR)pudirlist->name+sizeof(ICU_DLLNAME)-1);//~v6ByI~
#else                                                              //~v6bmI~
    	pc=strstr(pudirlist->name,".so");                          //~v6bmR~
//  	pos=(ULONG)pc-(ULONG)pudirlist->name+3;                    //~v6bmR~//~v6BkR~
    	pos=PTRDIFF(pc,pudirlist->name)+3;                         //~v6BkI~
        if (*(pc+3)=='.')                                          //~v6bmI~
            pos++;      //.so.xx                                   //~v6bmI~
#endif                                                             //~v6bmI~
        pversion=pudirlist->name+pos;                              //~v6baI~
        intver=atoi(pversion);                                     //~v6baI~
        if (intver)	//version found                                //~v6baI~
        	break;                                                 //~v6baI~
    }                                                              //~v6baI~
//  ufree(pudl0);                                                  //~v6baI~//~v6qaR~
    UDIRLIST_FREE(pudl0);                                          //~v6qaI~
    UTRACEP("%s:ver=%d,so=%s\n",UTT,intver,Psoname);            //~v6baI~//~vbB9R~
    return intver;                                                 //~v6baI~
}//ucvext_getarmso1                                                //~v6baI~
//#ifdef ARMXXE                                                      //~v77nI~//~v77NR~
#ifdef ARM                                                         //~v77NI~
//*************************************************************************//~v775I~//~v77nM~
int ucvext_chkiculibARM(char *Ppsoname)                            //~v77nI~
{                                                                  //~v775I~//~v77nM~
	int rc=-1;                                                     //~v775I~//~v77nI~
    char *pso;                                                     //~v77nI~
//****************************                                     //~v77nI~
	*Ppsoname=0;                                                   //~v77nI~
	Sicusoname[0]=0;                                               //~v77nI~
//  int opt=RTLD_NOLOAD;                                           //~v77nI~//~v77WR~
    int opt=RTLD_NOW;                                              //~v77WI~
//  opt|=RTLD_GLOBAL;      //try for android9 xcv process TODO TEST//~v77WI~//~v77XR~
    void *handle;                                                  //~v77nI~
    UTRACEP("%s:entry,LD_LIBRARY_PATH=%s\n",UTT,getenv("LD_LIBRARY_PATH"));                                     //~v77nI~//~v77PR~
    for (;;)                                                       //~v77nI~
    {                                                              //~v77nI~
    	pso="libicu.so";                                           //~v77nI~
    	handle=dlopen(pso,opt);                                    //~v77nI~
    	UTRACEP("%s:dlopen opt=0x%x,%s handle=%p,err=%s\n",UTT,opt,pso,handle,dlerror());                //~v775R~//~v77nI~//~v77PR~
    	if (handle)                                                //~v77nI~
        {                                                          //~v77nI~
    		strcpy(Ppsoname,pso);                                  //~v77nI~
            break;                                                 //~v77nI~
        }                                                          //~v77nI~
    	pso="libicuuc.so";                                         //~v77nI~
    	handle=dlopen(pso,opt);                                    //~v77nI~
    	UTRACEP("%s:dlopen opt=0x%x,%s handle=%p,err=%s\n",UTT,opt,pso,handle,dlerror());//~v77PI~
    	if (handle)                                                //~v77nI~
        {                                                          //~v77nI~
    		strcpy(Ppsoname,pso);                                  //~v77nI~
            break;                                                 //~v77nI~
        }                                                          //~v77nI~
    	pso="libi18n.so";                                          //~v77nI~
    	handle=dlopen(pso,opt);                                    //~v77nI~
    	UTRACEP("%s:dlopen opt=0x%x,%s handle=%p,err=%s\n",UTT,opt,pso,handle,dlerror());//~v77PI~
    	if (handle)                                                //~v77nI~
        {                                                          //~v77nI~
    		strcpy(Ppsoname,pso);                                  //~v77nI~
            break;                                                 //~v77nI~
        }                                                          //~v77nI~
        break;                                                     //~v77nI~
    }                                                              //~v77nI~
	if (*Ppsoname)                                                 //~v77nI~
    {                                                              //~v77nI~
    	rc=0;                                                      //~v77nI~
		strcpy(Sicusoname,Ppsoname);                               //~v77nR~
    }                                                              //~v77nI~
    UTRACEP("%s:rc=%d,out soname=%s\n",UTT,rc,Ppsoname);           //~v77nI~
    return rc;                                                     //~v77nI~
}                                                                  //~v775I~//~v77nM~
#endif	//ARM                                                      //~v77NR~
//*************************************************************************//~v6baI~
//*get arm so name                                                 //~v6baI~
//*ret version if exist or -1 if so not found                      //~v6baI~
//*************************************************************************//~v6baI~
int ucvext_getarmso(int Popt,char *Psoname,char *Psuffix)          //~v6baI~
{                                                                  //~v6baI~
	char *plibpath,*pc,*pc2,*pc0;                                  //~v6baR~
    int len,intver=-1;                                             //~v6baR~
    char fpath[_MAX_PATH];                                         //~v6baI~
#ifdef W32                                                         //~v6g3I~
    char fpath2[_MAX_PATH];                                        //~v6g3I~
#endif                                                             //~v6g3I~
//**********************************                               //~v6baI~
	UTRACEP("%s:Psoname=%s\n",UTT,Psoname);                        //~v6M1I~
//#ifdef ARMXXE                                                      //~v77nI~//~v77NR~
#ifdef ARM                                                         //~v77NI~
	intver=ucvext_chkiculibARM(Psoname);	//set SiculibnameARM   //~v77nI~
    if (intver>=0)                                                  //~v77nI~
    	return intver;                                             //~v77nI~
#endif                                                             //~v77nI~
#ifdef W32                                                         //~v6bmI~
	plibpath=getenv("PATH");                                       //~v6bmI~
#else                                                              //~v6bmI~
	plibpath=getenv("LD_LIBRARY_PATH");                            //~v6baI~
#endif                                                             //~v6bmI~
	UTRACEP("%s:env libpath=%s\n",UTT,plibpath);         //~v6baR~ //~vbB9R~
    if (!plibpath)                                                 //~v6baR~
    	plibpath="";                                               //~v6baI~
//  len=strlen(plibpath);                                          //~v6baI~//~v6BkR~
    len=(int)strlen(plibpath);                                     //~v6BkI~
#ifdef W32                                                         //~v6bmI~
    len+=4;                                                        //~v6bmI~
    len+=GetSystemDirectory(fpath,sizeof(fpath));                  //~v6g3I~
    len+=GetWindowsDirectory(fpath2,sizeof(fpath2));               //~v6g3R~
#else                                                              //~v6bmI~
//  len+=strlen(Siculibdir)+4;                                     //~v6baR~//~v6BkR~
    len+=(int)strlen(Siculibdir)+4;                                //~v6BkI~
#endif                                                             //~v6bmI~
//  pc0=pc=umalloc(len);                                           //~v6baI~//~v6BkR~
    pc0=pc=umalloc((size_t)len);                                   //~v6BkI~
#ifdef W32                                                         //~v6bmI~
//    sprintf(pc,"%s",plibpath);                                   //~v6g3R~
    sprintf(pc,"%s;%s;%s",fpath,fpath2,plibpath);                  //~v6g3I~
#else                                                              //~v6bmI~
  if (*plibpath && strcmp(plibpath,Siculibdir))                    //~v6fmR~
    sprintf(pc,"%s:%s",plibpath,Siculibdir);                        //~v6baR~//~v6bnR~
  else                                                             //~v6fmI~
    strcpy(pc,Siculibdir);                                         //~v6fmI~
//    udos_setenv(0,"LD_LIBRARY_PATH",pc);  //ENV is required for dlopen//~v6fmI~//~v6g2R~
//    pc2=getenv("LD_LIBRARY_PATH");                                 //~v6fmI~//~v6g2R~
#endif                                                             //~v6bmI~
//  for (;;pc+=len+1)                                              //~v6baR~//~v6M1R~
    for (;*pc;pc+=len+1)                                           //~v6M1I~
    {                                                              //~v6baI~
    	pc2=strchr(pc,ENV_SEPC);                                   //~v6bmI~//~v6bnR~
        if (pc2)                                                   //~v6baI~
//        	len=(ULONG)pc2-(ULONG)pc;                              //~v6baI~//~v6hhR~
//      	len=(ULPTR)pc2-(ULPTR)pc;                              //~v6hhI~//~v6BkR~
        	len=PTRDIFF(pc2,pc);                                   //~v6BkI~
        else                                                       //~v6baI~
//      	len=strlen(pc);                                        //~v6baI~//~v6BkR~
        	len=(int)strlen(pc);                                   //~v6BkI~
        if (!len)                                                  //~v6baI~
        {                                                          //~v6M1I~
          if (pc2)	//continued seperator	                       //~v6M1I~
        	continue;                                              //~v6baI~
        }                                                          //~v6M1I~
//      UmemcpyZ(fpath,pc,len);                                    //~v6baI~//~v6BkR~
        UmemcpyZ(fpath,pc,(size_t)len);                            //~v6BkI~
    	UTRACEP("%s:libpath=%s\n",UTT,fpath);                    //~v6baI~//~vbB9R~
        intver=ucvext_getarmso1(Popt,fpath,Psoname,Psuffix);       //~v6baI~
        if (intver>=0)                                             //~v6baI~
        	break;                                                 //~v6baI~
#ifdef ARM                                                         //~v774I~
	  	swNewICU4C=1;                                              //~v774I~
        intver=ucvext_getarmso1(Popt,fpath,Psoname,Psuffix);       //~v774I~
	  	swNewICU4C=0;                                              //~v774I~
        if (intver>=0)                                             //~v774I~
        	break;                                                 //~v774I~
#endif                                                             //~v774I~
        if (!pc2) //end of list                                    //~v6baI~
            break;                                                 //~v6baI~
    }                                                              //~v6baI~
    if (intver<0)                                                  //~v6baI~
//	    uerrmsg("ICU library %s(version:%s) not found on %s",0,    //~v6baI~//~v6f3R~
//	    uerrmsg("ICU library %s(version:%s) not found on %s",0,    //~v6f3I~
#ifdef W32                                                         //~v6f3I~
  	    uerrmsg("ICU library %s(version:%s) not found on PATH:%s",0,//~v6f3I~
#else                                                              //~v6f3I~
  	    uerrmsg("ICU library %s(version:%s) not found on LD_LIBRARY_PATH:%s",0,//~v6f3R~
#endif                                                             //~v6f3I~
    	            ICU_DLLNAME,Psuffix,plibpath);                 //~v6baI~
    ufree(pc0);                                                    //~v6baI~
    UTRACEP("%s:ver=%d,so=%s\n",UTT,intver,Psoname);             //~v6baI~//~vbB9R~
    return intver;                                                 //~v6baI~
}//ucvext_getarmso                                                 //~v6baI~
//*************************************************************************//~v6baI~
//*get arm so name                                                 //~v6baI~
//*ret data version if exist or -1 if icudtxxy.dat not found       //~v6baI~
//*************************************************************************//~v6baI~
int ucvext_getarmdata1(int Popt,char *Ppath,int Pversion)          //~v6baI~
{                                                                  //~v6baI~
	PUDIRLIST pudirlist,pudl0;                                     //~v6baI~
    int ctr,ii,pos,intver=-1,rc=-1;                                      //~v6baI~//~v6bmR~
    char *pversion;                                                //~v6baI~
    char fpath[_MAX_PATH];                                         //~v6baI~
//**********************************                               //~v6baI~
    UTRACEP("%s:path=%s,req version=%d\n",UTT,Ppath,Pversion);//~v6baI~//~vbB9R~
#ifdef W32                                                         //~v6bmI~
	sprintf(fpath,"%s\\%s*l.dat",Ppath,ICU_DATANAME);              //~v6bmI~
#else                                                              //~v6bmI~
	sprintf(fpath,"%s/%s*l.dat",Ppath,ICU_DATANAME);               //~v6baI~
#endif                                                             //~v6bmI~
    pos=sizeof(ICU_DATANAME)-1;                                    //~v6baI~
    ctr=udirlistnomsg(fpath,FILE_ALL-FILE_DIRECTORY,&pudl0,'L'/*longname sort*/);//~v6baR~
    if (ctr<=0) //not found                                        //~v6baI~
        return intver;                                             //~v6baI~
    for (pudirlist=pudl0,ii=0;ii<ctr;ii++,pudirlist++)             //~v6baI~
    {                                                              //~v6baI~
    	UTRACEP("%s:%s/%s\n",UTT,fpath,pudirlist->name);      //~v6baI~//~vbB9R~
        pversion=pudirlist->name+pos;                              //~v6baI~
        intver=atoi(pversion);                                     //~v6baI~
        if (intver==Pversion                                       //~v6bmI~
        ||  (intver>0 && !Pversion))	//version found            //~v6bmR~
        {                                                          //~v6bmI~
            rc=intver;                                             //~v6bmI~
            break;                                             //~v6baI~//~v6bmR~
        }                                                          //~v6bmI~
    }                                                              //~v6baI~
//  ufree(pudl0);                                                  //~v6baI~//~v6qaR~
    UDIRLIST_FREE(pudl0);                                          //~v6qaI~
    UTRACEP("%s:ver=%d\n",UTT,rc);                        //~v6baI~//~v6bmR~//~vbB9R~
    return rc;                                                 //~v6baI~//~v6bmR~
}//ucvext_getarmdata1                                                //~v6baI~//~v6bnR~
//*************************************************************************//~v6baI~
//*get arm so name                                                 //~v6baI~
//*ret version if exist or -1 if so not found                      //~v6baI~
//*************************************************************************//~v6baI~
int ucvext_getarmdata(int Popt,int Pversion)                       //~v6baI~
{                                                                  //~v6baI~
	char *pdatapath,*pc,*pc2;                                      //~v6baR~
    int len,intver=-1;                                             //~v6baI~
    char fpath[_MAX_PATH];                                         //~v6baI~
//#ifdef W32                                                         //~v77PI~//~v7dhR~
//#else                                                              //~v77PI~//~v7dhR~
    int swDefault=0;                                               //~v77PI~
//#endif                                                             //~v77PI~//~v7dhR~
	char *penv;                                                    //~v77XI~
//**********************************                               //~v6baI~
	pdatapath=getenv(ICU_DATAENVNAME);                                  //~v6baI~//~v6bnR~
    penv=pdatapath;                                                //~v77XI~
	UTRACEP("%s:env icu_data=%s\n",UTT,pdatapath);      //~v6baR~  //~v6M1R~
    *fpath=0;                                                      //~v6M1I~
    if (!pdatapath)                                                //~v6baI~
    {                                                              //~v77PI~
//#ifdef W32                                                         //~v6bmI~//~v7dhR~
//  	pdatapath="";                                              //~v6bmI~//~v7dhR~
//#else                                                              //~v6bmI~//~v7dhR~
    	pdatapath=Sicudatadir;                                     //~v6baR~
        swDefault=1;                                               //~v77PI~
//#endif                                                             //~v6bmI~//~v7dhR~
	}                                                              //~v77PI~
    for (pc=pdatapath;;pc+=len+1)                                  //~v6baI~
    {                                                              //~v6baI~
    	pc2=strchr(pc,ENV_SEPC);                                   //~v6bmI~//~v6bnR~
        if (pc2)                                                   //~v6baI~
//        	len=(ULONG)pc2-(ULONG)pc;                              //~v6baI~//~v6hhR~
//      	len=(ULPTR)pc2-(ULPTR)pc;                              //~v6hhI~//~v6BkR~
        	len=PTRDIFF(pc2,pc);                                   //~v6BkI~
        else                                                       //~v6baI~
//      	len=strlen(pc);                                        //~v6baI~//~v6BkR~
        	len=(int)strlen(pc);                                   //~v6BkI~
      if (len)                                                  //~v6baI~//~v6bmR~
      {                                                            //~v6bmI~
//      UmemcpyZ(fpath,pc,len);                                    //~v6baI~//~v6BkR~
        UmemcpyZ(fpath,pc,(size_t)len);                            //~v6BkI~
    	UTRACEP("%s:path=%s\n",UTT,fpath);                     //~v6baI~//~vbB9R~
        intver=ucvext_getarmdata1(Popt,fpath,Pversion);            //~v6baR~
        if (intver>=0)                                             //~v6baI~
        {                                                          //~v77WI~
    		UTRACEP("%s setenv ver=%d,fpath=%s,penv=%s\n",UTT,intver,fpath,penv);//~v77WI~//~v77XR~
            if (!penv || !strstr(penv,fpath))                      //~v77XR~
				udos_setenv(0,ICU_DATAENVNAME,fpath);    //for android9//~v77WI~//~v77XR~
        	break;                                                 //~v6baI~
        }                                                          //~v77WI~
      }                                                            //~v6bmI~
        if (!pc2) //end of list                                    //~v6baI~
        {                                                          //~v77PI~
//#ifdef W32                                                         //~v77PI~//~v7dhR~
//#else                                                              //~v77PI~//~v7dhR~
		    if (!swDefault)	//searched env                         //~v77PI~
            {                                                      //~v77PI~
            	pc=Sicudatadir;                                    //~v77PI~
                len=-1;                                            //~v77PI~
                continue;                                          //~v77PI~
            }                                                      //~v77PI~
//#endif                                                             //~v77PI~//~v7dhR~
            break;                                                 //~v6baI~
        }                                                          //~v77PI~
    }                                                              //~v6baI~
    if (intver<0)                                                  //~v6baI~
	    uerrmsg("Warning:ICU Data(icudtXXl.dat version=%d) not found. chk env-var:ICU_DATA(=\"%s\") of cfg file setting.",//~v6M1R~
#ifdef LNX                                                         //~v7deI~
                0,                                                 //~v7deI~
#else                                                              //~v7deI~
	            "Warning:ICU Data(icudtXXl.dat version=%d) ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñBŠÂ‹«•Ï”:ICU_DATA(=\"%s\") ‚ ‚é‚¢‚Í cfg ƒtƒ@ƒCƒ‹‚ðŠm”F",//~v6M1I~
#endif                                                             //~v7deI~
    	            Pversion,pdatapath);                           //~v6baI~
    UTRACEP("%s:swDefault=%d,ver=%d,so=%s\n",UTT,swDefault,intver,fpath);               //~v6baR~//~v6bnR~//~vbB9R~//~v7dhR~
    return intver;                                                 //~v6baI~
}//ucvext_getarmdata                                               //~v6baR~
//*************************************************************************//~v6g4I~
//*chk api suffix %d_%d or _%d                                     //~v6g4I~
//*************************************************************************//~v6g4I~
int chkapiver(int Popt,int Papiver,PUCVEXTCFG Ppcfg)               //~v6g4I~
{                                                                  //~v6g4I~
	char dllname[32];                                              //~v6g4I~
	char apiver[32],*dllver;                                       //~v6g4R~
//  ULONG paddr;                                                   //~v6g4I~//~v6hhR~
    ULPTR paddr;                                                   //~v6hhI~
    DLHANDLE handle;                                               //~v6g4I~
    int rc,opt=0;                                                  //~v6g4R~
//*********************                                            //~v6g4I~
	dllver=Ppcfg->UCECdllsuffix;                                   //~v6g4I~
#ifdef W32                                                         //~v6g4I~
	sprintf(dllname,"%s%s",ICU_DLLNAME,dllver);                    //~v6g4R~
#else                                                              //~v6g4I~
  	if (*dllver)                                                   //~v6g4R~
		sprintf(dllname,"lib%s.so.%s",ICU_DLLNAME,dllver);         //~v6g4R~
  	else                                                           //~v6g4I~
		sprintf(dllname,"lib%s.so",ICU_DLLNAME);                   //~v6g4I~
#endif  //W32                                                      //~v6g4I~
//#ifdef ARMXXE                                                      //~v77nI~//~v77NR~
#ifdef ARM                                                         //~v77NI~
	if (*Sicusoname)  //soname defined without fpath               //~v77nI~
		strcpy(dllname,Sicusoname);                                //~v77nI~
#endif                                                             //~v77nI~
	sprintf(apiver,"_%d",Papiver);                                 //~v6g4I~
	strcpy(Ppcfg->UCECapisuffix,apiver);	//default              //~v6g4I~
	opt|=UPGPAO_NOW|UPGPAO_NOMSG;        //RTLD_NOW                //~v6g4R~
    handle=0;                                                      //~v6g4I~
	rc=uproc_getprocaddr(opt,dllname,0,ICUAPINAME_UERRNAME,apiver,&handle,&paddr);//~v6g4I~
	if (rc)                                                        //~v6g4I~
    {                                                              //~v6g4I~
		sprintf(apiver,"_%d_%d",Papiver/10,Papiver%10);//version from icudtxx//~v6g4R~
		rc=uproc_getprocaddr(opt,dllname,0,ICUAPINAME_UERRNAME,apiver,&handle,&paddr);//~v6g4I~
	    if (!rc)                                                   //~v6g4I~
			strcpy(Ppcfg->UCECapisuffix,apiver);                   //~v6g4I~
    }                                                              //~v6g4I~
    UTRACEP("%s:rc=%d apiver=%d,suffix=%s,dllname=%s\n",UTT,rc,Papiver,Ppcfg->UCECapisuffix,dllname);//~v6g4I~//~v775R~//~vbB9R~
    return rc;                                                     //~v6g4I~
}//chkapiver                                                       //~v6g4I~
//*************************************************************************//~v6baI~
//*for ARM get soname and version                                  //~v6baI~
//*************************************************************************//~v6baI~
int ucvext_icuinit_env(int Popt,PUCVEXTCFG Ppcfg)                  //~v6baR~
{                                                                  //~v6baI~
    char soname[_MAX_PATH];                                        //~v6baR~
    int rc,sover=-1,apiver=-1;                                     //~v6baI~//~v6bmR~
    char *pc;                                                      //~v6g2I~
//**********************************                               //~v6baI~
    UTRACEP("%s:entry dllsuffix=%s,apisuffix=%s\n",UTT,Ppcfg->UCECdllsuffix,Ppcfg->UCECapisuffix);//~v6baR~//~v77ER~
  	if (!(Popt & UCEIO_USEICU))	//explicit request                 //~v6baI~
  		if (!IS_ICUMODE())                                         //~v6baI~
  			return 0;                                              //~v6baI~
    *soname=0;                                                     //~v6g2I~
	for (;;)                                                       //~v6baI~
    {                                                              //~v6baI~
		rc=ucvext_getarmso(Popt,soname,Ppcfg->UCECdllsuffix);      //~v6baI~
        if (rc<0)	//so not found                                 //~v6baI~
        	break;                                                 //~v6baI~
        strcpy(Sdllfpath,soname);	//use when dlopen failed by dllname//~v6g2I~
        sover=rc;                                                  //~v6baI~
        if (rc>0)                                                  //~v6baI~
        {                                                          //~v6baI~
			if (!*Ppcfg->UCECdllsuffix)                            //~v6baI~
            	itoa(sover,Ppcfg->UCECdllsuffix,10);               //~v6baR~
        }                                                          //~v6baI~
        if (*Ppcfg->UCECapisuffix=='_')	//version from icudtxx     //~v6baR~
	        apiver=atoi(Ppcfg->UCECapisuffix+1);	//version from icudtxx//~v6baR~
        else                                                       //~v6baI~
	        apiver=atoi(Ppcfg->UCECapisuffix);	//version from icudtxx//~v6baI~
        if (!apiver)                                               //~v6baI~
        {                                                          //~v6bnI~
        	apiver=sover;                                          //~v6baI~
            if (!apiver)                                           //~v6bnI~
				apiver=ucvext_getarmdata(Popt,apiver);                         //~v6baI~//~v6bmR~//~v6bnI~
        	if (apiver>0)                                              //~v6bmI~//~v6bnR~
	        	if (!*Ppcfg->UCECapisuffix)                            //~v6baI~//~v6bmI~//~v6bnR~
                {                                                  //~v6bqI~
//                  if (apiver==40)                                  //~v6bqR~//~v6g4R~
//                    sprintf(Ppcfg->UCECapisuffix,"_%d_%d",apiver/10,apiver%10);//version from icudtxx//~v6bqI~//~v6g4R~
//                  else                                             //~v6bqI~//~v6g4R~
//                    sprintf(Ppcfg->UCECapisuffix,"_%d",apiver);//version from icudtxx//~v6baR~//~v6bmI~//~v6bnR~//~v6g4R~
                    chkapiver(0,apiver,Ppcfg);                     //~v6g4I~
                }                                                  //~v6bqI~
        }                                                          //~v6bnI~
    	UTRACEP("%s:apiver=%d,sover=%d\n",UTT,apiver,sover);//~v6baI~//~v6bnR~//~vbB9R~
        rc=0;                                                      //~v6bmI~
        break;                                                     //~v6baI~
    }                                                              //~v6baI~
//  if (Gucvebc_stat & UCVEBCS_xcv)                                //~v6bqI~//~v6m3R~
    if (Gucvebc_stat & (UCVEBCS_xcv|UCVEBCS_icutool))	//from xcv and xprint//~v6m3R~
    {                                                              //~v6bqI~
		pc=getenv(ICU_DATAENVNAME);                                //~v6g2I~
        if (!pc)                                                   //~v6g2I~
            pc="";                                                 //~v6g2I~
#ifdef W32                                                         //~v6bqI~
        uerrmsg("ICU .dll-suffix=\"%s\",api-suffix=\"%s\" %s=\"%s\".",0,//~v6bqR~//~v6g2R~
#else                                                              //~v6bqI~
        uerrmsg("ICU .so-suffix=\"%s\",api-suffix=\"%s\" %s=\"%s\".",0,//~v6bqI~//~v6g2R~
#endif                                                             //~v6bqI~
    			Ppcfg->UCECdllsuffix,Ppcfg->UCECapisuffix,         //~v6bqR~
//  			ICU_DATAENVNAME,getenv(ICU_DATAENVNAME));          //~v6bqI~//~v6g2R~
    			ICU_DATAENVNAME,pc);                               //~v6g2I~
    }                                                              //~v6bqI~
    UTRACEP("%s:ret dllsufix=%s,apisuffix=%s,Ppcfg=%p\n",UTT,Ppcfg->UCECdllsuffix,Ppcfg->UCECapisuffix,Ppcfg);//~v6baR~//~v77ER~//~vbB9R~
    return rc;                                                     //~v6baI~
}//ucvext_icuinit_env                                              //~v6baR~
//#endif                                                             //~v6baI~//~v6bmR~
#ifdef ARM                                                         //~v6bqI~
#ifdef XXE                                                         //~v6buR~
//*************************************************************************//~v6bqI~
//*set datadir by icu api                                          //~v6bqI~
//*!!! never called                                                //~v77XI~
//*************************************************************************//~v6bqI~
char *addarmdatadir(PUCVEXTCFG Ppcfg,char *Ppenvicudata)           //~v6bqI~
{                                                                  //~v6bqI~
	int len1=0,len2,len,msgsw,rc,opt;                              //~v6bqR~
    ULONG newattr;                                                 //~v6bqI~
//  char *pswfile,picufolder[_MAX_PATH],pswfilefpath[_MAX_PATH];   //~v6bqI~//~v702R~
    char          picufolder[_MAX_PATH],pswfilefpath[_MAX_PATH];   //~v702I~
    char copytgt[_MAX_PATH],copysrc[_MAX_PATH];                    //~v6bqR~
    char *newenv,*psuffix,*pc;                                     //~v6bqR~
    char buff[_MAX_PATH+128];                                      //~v6bqI~
    FILE *fh;                                                      //~v6bqI~
//******************                                               //~v6bqI~
	rc=jniu_geticudir(0,picufolder,pswfilefpath);                  //~v6bqR~
    UTRACEP("%s:oldenv=%s,icudir=%s,swfile=%s\n",UTT,Ppenvicudata,picufolder,pswfilefpath);//~v6bqR~//~vbB9R~
    if (Ppenvicudata)                                              //~v6bqI~
	    len1=strlen(Ppenvicudata);                                 //~v6bqI~
	len2=strlen(picufolder);                                       //~v6bqI~
    len=len1+len2;                                                 //~v6bqI~
    if (!len)                                                      //~v6bqI~
    	return Ppenvicudata;                                       //~v6bqI~
    pc=umalloc(len+4);                                             //~v6bqI~
    *pc=0;                                                         //~v6bqI~
    if (Ppenvicudata && *Ppenvicudata)                             //~v6bqI~
    	strcpy(pc,Ppenvicudata);                                   //~v6bqI~
    if (*picufolder)                                               //~v6bqI~
    {                                                              //~v6bqI~
    	if (len1 && *(pc+len1-1)!=':')                             //~v6bqR~
    		*(pc+len1++)=':';                                      //~v6bqI~
    	strcpy(pc+len1,picufolder);                                //~v6bqI~
    }                                                              //~v6bqI~
	udos_setenv(0,ICU_DATAENVNAME,pc);    //putenv should not free source string, setenv(not in Windows) copyed to env//~v6bqI~
    ufree(pc);                                                     //~v6bqI~
    newenv=getenv(ICU_DATAENVNAME);    //putenv should not free source string, setenv(not in Windows) copyed to env//~v6bqI~
    psuffix=Ppcfg->UCECapisuffix;                                  //~v6bqI~
    UTRACEP("%s:newenv=%s,apisuffix=%s\n",UTT,newenv,psuffix);//~v6bqR~//~vbB9R~
//  listenv();//TODO test                                          //~v70dR~
    if (*psuffix=='_')                                             //~v6bqI~
    	psuffix++;                                                 //~v6bqI~
    if (!*psuffix)                                                 //~v6bqI~
    	return newenv;                                             //~v6bqI~
    if (!*picufolder)                                              //~v6bqI~
    	return newenv;                                             //~v6bqI~
    fh=fopen(pswfilefpath,"r");                                    //~v6bqI~
    if (fh)        //exist                                         //~v6bqI~
    {                                                              //~v6bqI~
		pc=fgets(buff,sizeof(buff),fh);	//read 1 block             //~v6bqI~
    	fclose(fh);                                                //~v6bqI~
    	UTRACEP("%s:swfile exist fgets=%s\n",UTT,pc);       //~v6bqR~//~vbB9R~
        if (pc)	//not null file                                    //~v6bqR~
	    	return newenv;                                         //~v6bqI~
    }                                                              //~v6bqI~
    sprintf(copytgt,"%s/icudt%sl",picufolder,psuffix);	//icudt44l //~v6bqI~
    sprintf(copysrc,"%s/*.cnv",picufolder);                        //~v6bqI~
    msgsw=Gufile_nomsg;                                            //~v6bqI~
    Gufile_nomsg=1;		//for already exist                        //~v6bqI~
    umkdirmode(copytgt,0777,&newattr);                             //~v6bqR~
    Gufile_nomsg=msgsw;                                            //~v6bqI~
                                                                   //~v6bqI~
    opt=DCPY_REPOLD;                                               //~v6bqI~
	rc=uxmove(copysrc,copytgt,FILE_ALL,opt);                       //~v6bqI~
    if (!rc)                                                       //~v6bqI~
    {                                                              //~v6bqI~
        fh=fopen(pswfilefpath,"w");                                //~v6bqI~
        if (fh)        //opened                                    //~v6bqI~
        {                                                          //~v6bqI~
            fprintf(fh,"Remove this file to update converter in %s\n",picufolder);//~v6bqI~
            fclose(fh);                                            //~v6bqI~
            UTRACEP("%s:swfile created\n",UTT);             //~v6bqR~//~vbB9R~
        }                                                          //~v6bqI~
        else                                                       //~v6bqI~
//      	uerrmsg("%s open failed(ICU data install switch file)",0);//~v6z0R~
        	uerrmsg("%s open failed(ICU data install switch file)",0,//~v6z0I~
                    pswfilefpath);                                 //~v6z0I~
    }                                                              //~v6bqI~
	return newenv;                                                 //~v6bqI~
}//addarmdatadir                                                   //~v6bqI~
#endif //XXE                                                       //~v6buI~
#endif                                                             //~v6bqI~
//*************************************************************************//~v6bpI~
//*set datadir by icu api                                          //~v6bpI~
//*************************************************************************//~v6bpI~
int setdatadir(PUCVEXTCFG Ppcfg)                                   //~v6bpI~
{                                                                  //~v6bpI~
	int rc=0;                                                      //~v6bpI~
    char *dir;                                                     //~v6bpI~
#ifdef TEST_GETDIR                                                 //~v6c3I~
//  char *getdir=0;                                                //~v6c3I~//~v702R~
#ifdef ARM                                                         //~v6c3I~
#ifdef XXE                                                         //~v702I~
    char *getdir;                                                  //~v702M~
#endif                                                             //~v702I~
    UErrorCode uerrc=U_ZERO_ERROR;                                 //~v6c3I~
    UDataFileAccess access=UDATA_FILES_FIRST;	//0:efault,android may changed it to UDATA_ONLY_PACKAGES(1)//~v6c3R~
#endif                                                             //~v6c3I~
#endif                                                             //~v6c3I~
//******************                                               //~v6bpI~
UTRACEP("%s env %s=%s\n",UTT,ICU_DATAENVNAME,getenv(ICU_DATAENVNAME));//~v77WR~
//#ifdef TEST_GETDIR   //TODO test                                   //~v6c3I~//~v77WR~
#ifdef ARM                                                         //~v702I~
#ifdef XXE                                                         //~v702I~
    getdir=0;                                                      //~v702I~
	if (Spfuncgetdatadir)                                          //~v6c3I~
    {                                                              //~v6c3I~
//      getdir=getdir;                                             //~v6n0I~//~v702R~
	    getdir=(*Spfuncgetdatadir)();                              //~v6c3I~
		UTRACEP("%s:getdir=%s\n",UTT,getdir);                      //~v77WI~
    }                                                              //~v6c3I~
#endif                                                             //~v702I~
#endif                                                             //~v702I~
#ifdef ARM                                                         //~v6c3I~
	if (Spfuncfileaccess)                                          //~v6c3I~
    {                                                              //~v6c3I~
	    (*Spfuncfileaccess)(access,&uerrc);                        //~v6c3I~
        if (U_FAILURE(uerrc))                                      //~v6c3I~
        {                                                          //~v6c3I~
            uerrmsg("ICU:udata setFileAccess rc=%d",0,(int)uerrc); //~v6c3I~
		    uerrc=U_ZERO_ERROR;                                    //~v6c3I~
        }                                                          //~v6c3I~
    }                                                              //~v6c3I~
#endif	//ARM                                                      //~v6c3I~
//#endif                                                             //~v6c3I~//~v77WR~
	dir=getenv(ICU_DATAENVNAME);                                   //~v6bpI~
#ifdef ARM                                                         //~v77WI~
	if (1)    //ICU_DATA env is required ? NO-->skip addarmadatadir//~v77XR~
    {                                                              //~v77WI~
		UTRACEP("%s:ARM returns 0 without addarmdatadir\n",UTT);   //~v77WI~
    	return 0;                                                  //~v77WI~
    }                                                              //~v77WI~
#endif                                                             //~v77WI~
#ifdef ARM                                                         //~v6bqI~
#ifdef XXE                                                         //~v6buI~
    if (!dir)                                                      //~v6c0I~
    {                                                              //~v6c3I~
#ifdef TEST_GETDIR                                                 //~v6c3I~
	  if (getdir)                                                  //~v6c3I~
	  	dir=getdir;                                                //~v6c3I~
      else                                                         //~v6c3I~
#endif                                                             //~v6c3I~
    	dir=Sicudatadir;                                           //~v6c0I~
    }                                                              //~v6c3I~
	dir=addarmdatadir(Ppcfg,dir);                                  //~v6bqI~
#endif                                                             //~v6buI~
#endif                                                             //~v6bqI~
	if (Spfuncsetdatadir)                                          //~v6bpI~
    	if (dir && *dir)                                           //~v6bpI~
        {                                                          //~v6bpI~
        	UTRACEP("%s:u_setDataDirectory:%s\n",UTT,dir);     //~v6bpI~//~vbB9R~
	    	(*Spfuncsetdatadir)(dir);                              //~v6bpR~
            rc=1;                                                  //~v6bpI~
#ifdef TEST_GETDIR                                                 //~v6c3I~
			if (Spfuncgetdatadir)                                  //~v6c3I~
    		{                                                      //~v6c3I~
//      		getdir=(*Spfuncgetdatadir)();                      //~v6c3I~//~v702R~
        		UTRACEP("%s:getdir=%p\n",UTT,(*Spfuncgetdatadir)());//~v702I~
    		}                                                      //~v6c3I~
#endif                                                             //~v6c3I~
        }                                                          //~v6bpI~
//  listenv();	//TODO test                                        //~v70dR~
    return rc;                                                     //~v6bpI~
}//setdatadir                                                      //~v6bpI~
//*************************************************************************
//*map init by config file
//*Papis:optional output 3 api addr(open,toucs,fromucs)
//*************************************************************************
int ucvext_mapinit(int Popt,char *Pcfgfnm,PUCVEXTCFG *Ppcfg)
{
	PUCVEXTCFG pcfg;
	static UCVEXTCFG  Scfg;
    char *pdbcscharset,*psbcscharset,*plocalcharset;
//  ULONG addr;                                                    //~v6hhR~
    ULPTR addr;                                                    //~v6hhI~
#ifdef BBB                                                         //~v7dsI~
    UCHAR *pc,*pmap;
#else                                                              //~v7dsI~
    UCHAR *pc;                                                     //~v7dsI~
#endif                                                             //~v7dsI~
#ifdef BBB                                                         //~v7dsI~
    int rc=0,ii,rc2;
#else                                                              //~v7dsI~
    int rc=0,rc2;                                                  //~v7dsI~
#endif                                                             //~v7dsI~
    void *pfuncs[2];                                               //~v69dR~
    int swforcedefault=0;                                          //~v6ffR~
//***********************
    UTRACEP("%s:entry opt=%x\n",UTT,Popt);                       //~v6beI~//~v77ER~
	ucvext_notifyTables();                                         //~vbB9I~
//  Sextflag=0;                                                    //~v5mYI~//~v6f3R~
    Sextflag&=SEXTF_LIBOPENED;	//dont clear for LOCALICU initialized//~v6f3I~
  if (!UDBCSCHK_IS_LOCALICU())		//not local icu option specified(-Yi)//~v6f5I~
	Sextflag|=SEXTF_NOICULOCAL;    //local converter is not ICU    //~v66KI~
    pcfg=&Scfg;
    Spcfg=pcfg;                                                    //~v6bcI~
  	if (Popt & UCEIO_CONVERTERCFG) //parm-cfg is created by getConverterCfg//~v6M5I~
    	memcpy(pcfg,*Ppcfg,UCVEXTCFGSZ);                           //~v6M5R~
    *Ppcfg=pcfg;
    UTRACED("Spcfg",Spcfg,UCVEXTCFGSZ);                            //~v7dcI~
  for (;;)//return at end of func                                  //~v66DI~
  {                                                                //~v66DI~
    if (Popt & UCEIO_CONVERTERCFG) //parm-cfg is created by getConverterCfg//~v6M5I~
    	;                                                          //~v6M5I~
    else                                                           //~v6M5I~
	if (rc=ucvext_getcfg(Popt,Pcfgfnm,pcfg),rc)
    {                                                              //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
//  	if (pcfg->UCECflag & UCECF_OPENERR)                        //~v68cR~
      		if (Popt & UCEIO_LOCALEDIT) //local ebcdic trans support for xe//~v660R~
            {                                                      //~v6bhI~
#ifndef ARM	//LNX have also iconv;request specify iconv or ICU by cfg//~v6bhR~
      		  if (Popt & UCEIO_USEICU)   //get default dl version  //~v6bhI~
#endif                                                             //~v6bhM~
//    			if (Gucvebc_stat & UCVEBCS_xcv    //from xcv       //~v6bhI~//~v6m3R~
      			if ((Gucvebc_stat & (UCVEBCS_xcv|UCVEBCS_icutool))	//from xcv and xprint//~v6m3I~
	  			&&  Pcfgfnm && !*Pcfgfnm       //no mapfile parm but cpeb parm//~v6bhR~
      			&&  ucvext_icuinit_env(Popt|UCEIO_USEICU,pcfg)>=0   //get default dl version//~v6bhR~
	    		&& (rc=ucvext_icuinit(Popt|UCEIO_USEICU,pcfg->UCECdllsuffix,pcfg->UCECapisuffix,0/*apis*/),!rc)//~v6bhR~
      			)                                                  //~v6bhI~
      			{                                                  //~v6bhI~
    				pcfg->UCECflag|=UCECF_USE_CONVERTER|UCECF_USE_ICU;//~v6bhI~
#ifdef ARM                                                         //~v6c4I~
					ucvext_setdefaultlocalcv(0,pcfg); //set localconverter by icu//~v6c4I~
					ucvext_setlocalconverter(0,pcfg); //set icu converter//~v6c4I~
#endif                                                             //~v6c4I~
                    break;                                         //~v6bhI~
                }                                                  //~v6bhI~
        		rc=ucvext_mapinitsetdefault(Popt,pcfg);            //~v660R~
            }                                                      //~v6bhI~
#endif                                                             //~v660I~
//  	return rc;                                                 //~v66DR~
        break;                                                     //~v66DI~
    }                                                              //~v660I~
UTRACED("char cfg",pcfg,UCVEXTCFGSZ);
    if ((pcfg->UCECflag & (UCECF_USE_CONVERTER)) //use converter   //~v5mWR~
    )                                                              //~v5n1I~
    {
        if (pcfg->UCECflag & (UCECF_USE_ICU))                      //~v5n2R~
			Sextflag|=SEXTF_ICU;                                   //~v5n2I~
        if (pcfg->UCECflag & UCECF_ICUFALLBACK)                    //~v66rR~
			Sextflag|=SEXTF_ICUFB;                                 //~v66rI~
    	pdbcscharset=pcfg->UCECcsnamedbcs;
    	psbcscharset=pcfg->UCECcsnamesbcs;
    	plocalcharset=pcfg->UCECcsnamelocal;
      if (pcfg->UCECflag & (UCECF_USE_ICU))                        //~v6fcI~
      {                                                            //~v6fcI~
        if (*pdbcscharset                                          //~v5mTR~
		||	(*psbcscharset && !(pcfg->UCECflag & UCECF_SBCSDEF)) //use sbcs default mapping//~v5mTR~
		||	*plocalcharset)                                        //~v5mTR~
        {                                                          //~v66hI~
//#ifdef ARM  //xeebc.map is setup by converter=icu,sbcs:cp37        //~v6baI~//~v6fcR~
          if (!*pcfg->UCECdllsuffix)    //parameter missing        //~v6fcI~
        	ucvext_icuinit_env(Popt,pcfg);   //get default dll:icuui icudt//~v6baR~
//#endif                                                             //~v6baM~//~v6fcR~
	        if (rc=ucvext_icuinit(Popt,pcfg->UCECdllsuffix,pcfg->UCECapisuffix,0/*apis*/),rc)
            {                                                      //~v6fjI~
//    	    	return rc;                                         //~v6fjR~
				rc=16;                                             //~v6fjI~
                break;                                             //~v6fjI~
			}                                                      //~v6fjI~
#ifndef ARM	//arm uncoditionally add ICU_DATA dir:/data/data/com.xe.Axe/files/icu//~v6bqI~
        	if (pcfg->UCECflag2 & UCECF2_ICUDATA)                  //~v6bpR~
#endif                                                             //~v6bqI~
		        setdatadir(pcfg);                                  //~v6bpI~
        }                                                          //~v66hI~
      }//use icu                                                   //~v6fcI~
        if ( !*pdbcscharset                                        //~v66hI~
		&&   (!*psbcscharset && !(pcfg->UCECflag & UCECF_SBCSDEF)) //use sbcs default mapping//~v66hI~
        )                                                          //~v66hI~
        {                                                          //~v66hI~
			if (Sextflag & SEXTF_ICU)                              //~v66hI~
            {                                                      //~v66hI~
		      if (!(Popt & UCEIO_CONVERTERCFG)) //parm-cfg is created by getConverterCfg//~v6M2I~
              {                                                    //~v6M2I~
				Sextflag&=~SEXTF_ICU;                              //~v66hI~
            	uerrmsg("Specified ICU mode on %s, but missing CHARSET parameter",0,//~v66hR~
							Pcfgfnm);                              //~v66hI~
//            	return 4;                                          //~v66hI~//~v6ffR~
				{                                                  //~v6ffR~
                	swforcedefault=1;                              //~v6ffR~
                	rc=4;                                          //~v6ffR~
              	}                                                  //~v6ffR~
              }                                                    //~v6M2I~
            }                                                      //~v66hI~
			if (pcfg->UCECflag & UCECF_USE_ICONV)                  //~v66hR~
            {                                                      //~v66hI~
            	uerrmsg("Specified External Converter mode on %s, but missing CHARSET parameter",0,//~v66hI~
							Pcfgfnm);                              //~v66hI~
 //         	return 4;                                          //~v66hI~//~v6ffR~
				{                                                  //~v6ffR~
                	swforcedefault=1;                              //~v6ffR~
                	rc=4;                                          //~v6ffR~
              	}                                                  //~v6ffR~
            }                                                      //~v66hI~
        }                                                          //~v66hI~
    	if (*pdbcscharset)
        {
//        	addr=(ULONG)pcfg->UCEChiconvdbcs;	//for linux; parm to ucvext_iconvgetconverter//~v5mTI~//~v6hhR~
        	addr=(ULPTR)pcfg->UCEChiconvdbcs;	//for linux; parm to ucvext_iconvgetconverter//~v6hhI~
		  if (Popt & UCEIO_CONVERTERCFG) //mapinit parm:cfg is created by getConverterCfg//~v6M5I~
			rc2=ucvext_icugetconverter(Popt|UCEIO_DBCSCV|UCEIO_CHKSTATEFULEBC,pdbcscharset,&addr);//~v6M5I~
          else                                                     //~v6M5I~
			rc2=ucvext_icugetconverter(Popt|UCEIO_DBCSCV,pdbcscharset,&addr);
            if (!rc2)
            {
		    	pcfg->UCECconverterdbcs=addr;
		    	pcfg->UCECflag|=UCECF_DBCSCV;
            }
            else
            {                                                      //~v6M5I~
            	rc=4;
            }                                                      //~v6M5I~
        }
    	if (!*psbcscharset)
        	strcpy(psbcscharset,pdbcscharset);
    	if (*psbcscharset)
        {
//        	addr=(ULONG)pcfg->UCEChiconvsbcs;	//for linux; parm to ucvext_iconvgetconverter//~v5mTI~//~v6hhR~
        	addr=(ULPTR)pcfg->UCEChiconvsbcs;	//for linux; parm to ucvext_iconvgetconverter//~v6hhI~
			rc2=ucvext_icugetconverter(Popt|UCEIO_SBCSCV,psbcscharset,&addr);
            if (!rc2)
            {
		    	pcfg->UCECconvertersbcs=addr;
		    	pcfg->UCECflag|=UCECF_SBCSCV;
            }
            else
            {                                                      //~v6c2I~
        		pcfg->UCECflag|=UCECF_SBCSDEF; //use sbcs default mapping//~v6c2I~
    			*psbcscharset=0;		//for title line:Internal map//~v6c2I~
            	rc=4;
            }                                                      //~v6c2I~
        }
    	if (*plocalcharset)
        {
//        	addr=(ULONG)pcfg->UCEChiconvlocal;	//for linux; parm to ucvext_iconvgetconverter//~v5mTI~//~v6hhR~
        	addr=(ULPTR)pcfg->UCEChiconvlocal;	//for linux; parm to ucvext_iconvgetconverter//~v6hhI~
			rc2=ucvext_icugetconverter(Popt|UCEIO_LOCALCV,plocalcharset,&addr);
            if (!rc2)
            {
//#ifdef TEST                                                      //~v7dMR~
		    	pcfg->UCECconverterlocal=addr;
		    	pcfg->UCECflag|=UCECF_LOCALCV;
				if (Sextflag & SEXTF_DBCSSTART)//dbcs start byte saved for the converter//~v66WI~
//  	    		pcfg->UCECflag|=UCECF_DBCSLOCALCV;  //local converter support dbcs//~v66WI~//~v6BkR~
    	    		pcfg->UCECflag|=(int)UCECF_DBCSLOCALCV;  //local converter support dbcs//~v6BkI~
//#endif                                                           //~v7dMR~
            	UTRACEP("%s:localconverter localcharset=%s,UCECconverterlocal=%p\n",UTT,plocalcharset,pcfg->UCECconverterlocal);//~v7d9I~
            }
            else
            	rc=4;
        }
        if (pcfg->UCECflag & UCECF_SBCSDEF) //use sbcs default mapping
        {
    	  if (Gucvebc_stat & UCVEBCS_3270FTP)	        //on xe3270 process//~v6bdI~
          {                                                        //~v6bdI~
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAP,0/*sbcsma*/,&addr);//set Sebc2asc as sbcs mapping
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAP|UCEIO_MAPISA2E,0/*sbcsma*/,&addr);
            pcfg->UCECflag|=UCECF_SBCSMAP;  //sbcs converter=default(not converter but internal mapping)
          }                                                        //~v6bdI~
          else                                                     //~v6bdI~
            set_internal_CP037(0,pcfg);                            //~v6bdI~
        }
        if (pcfg->UCECflag & UCECF_E2A)     //a2a mapping specified
        {
            pc=pcfg->UCECsbcsmape2a;
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAPC,pc,&addr);
            pcfg->UCECflag|=UCECF_SBCSMAPC;
        }
        if (pcfg->UCECflag & UCECF_A2E)     //a2a mapping specified
        {
            pc=pcfg->UCECsbcsmapa2e;
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAPC|UCEIO_MAPISA2E,pc,&addr);
            pcfg->UCECflag|=UCECF_SBCSMAPC;
        }
//      if (pcfg->UCECsubchardbcs)                                 //~v66CR~
//          Ssubchardbcs=pcfg->UCECsubchardbcs;                    //~v66CR~
//      else                                                       //~v5n3I~//~v66DR~
//  		Ssubchardbcs=UDBCSCHK_SUBCHAR_DBCS;                    //~v5n3I~//~v66DR~
//      if (pcfg->UCECsubcharsbcs)                                 //~v66CR~
//          Ssubcharsbcs=pcfg->UCECsubcharsbcs;                    //~v66CR~
//      else                                                       //~v5n3I~//~v66DR~
//  		Ssubcharsbcs=UDBCSCHK_SUBCHAR_SBCS;                    //~v5n3R~//~v66DR~
//      UTRACEP("mapinit subchar dbcs=%x,sbcs=%x\n",Ssubchardbcs,Ssubcharsbcs);//~v5n3I~//~v66DR~//~v66CR~
    }
//  else	//no use converter                                     //~v6ffR~
    if (!(pcfg->UCECflag & (UCECF_USE_CONVERTER)) //use converter  //~v6ffR~
    ||   swforcedefault)                                           //~v6ffR~
    {
#ifdef UTF8EBCD                                                    //~v660I~
      if ((Popt & UCEIO_LOCALEDIT)) //local ebcdic trans support for xe//~v660R~
        ucvext_mapinitsetdefault(Popt,pcfg); //use default mapping//~v660R~//~v66hR~
      else                                                         //~v660I~
#endif                                                             //~v660I~
      {//!LOCALEDIT                                                //~v660I~
#ifdef BBB                                                         //~v7dsI~
        pmap=pcfg->UCECsbcsmapf2a;
        if (pcfg->UCECflag & UCECF_F2A)     //a2a mapping specified
        {
#ifdef AAA
            memcpy(Sebc2asc,Sebc2asc0,256);     //modifiy default e2a mapping
            for (ii=0;ii<256;ii++)  //for CHARSET=DEFAULT+f2e case
            {
                asc=Sebc2asc0[ii];
                if (asc=pmap[asc],asc)   //map to
                    Sebc2asc[ii]=asc;
            }
    UTRACED("f2a     ",pmap     ,256);
    UTRACED("ebc2asc0",Sebc2asc0,256);
    UTRACED("ebc2asc ",Sebc2asc ,256);
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAP,Sebc2asc,&addr);
#endif
        	pcfg->UCECflag|=UCECF_USE_A2A;
        }
        for (ii=0;ii<256;ii++)  //for CHARSET=DEFAULT+f2e case
        {
            if (!pmap[ii])    //not defined
//              pmap[ii]=ii;  //no conversion                      //~v6x8R~
                pmap[ii]=(UCHAR)ii;  //no conversion               //~v6x8I~
        }
    	UTRACED("f2a     ",pmap     ,256);
        ucvext_icugetconverter(Popt|UCEIO_SBCSMAPA2A,pmap,&addr);
        pmap=pcfg->UCECsbcsmapa2f;
        if (pcfg->UCECflag & UCECF_A2F)     //a2a mapping specified
        {
#ifdef AAA
            memcpy(Sasc2ebc,Sasc2ebc0,256);     //modifiy default e2a mapping
            for (ii=0;ii<256;ii++)  //for CHARSET=DEFAULT+f2e case
            {
                asc=pmap[ii];
                if (asc)
                    Sasc2ebc[ii]=Sasc2ebc0[asc]; //to ebc from asc of a2f
            }
    UTRACED("a2f     ",pmap     ,256);
    UTRACED("asc2ebc0",Sasc2ebc0,256);
    UTRACED("asc2ebc ",Sasc2ebc ,256);
            ucvext_icugetconverter(Popt|UCEIO_SBCSMAP|UCEIO_MAPISA2E,Sasc2ebc,&addr);
#endif
        	pcfg->UCECflag|=UCECF_USE_A2A;
        }
        for (ii=0;ii<256;ii++)  //for CHARSET=DEFAULT+f2e case
        {
            if (!pmap[ii])    //not defined
//              pmap[ii]=ii;  //no conversion                      //~v6x8R~
                pmap[ii]=(UCHAR)ii;  //no conversion               //~v6x8I~
        }
    UTRACED("a2f     ",pmap     ,256);                             //~v5n1R~
        ucvext_icugetconverter(Popt|UCEIO_SBCSMAPA2A|UCEIO_MAPISA2E,pmap,&addr);
#else                                                              //~v7dsI~
		UTRACEP("%s:not localedit\n",UTT);                         //~v7dsI~
#endif //BBB                                                       //~v7dsI~
      }//!LOCALEDIT                                                //~v660I~
    }//A2A
    if (pcfg->UCECflag & UCECF_REPLF)
		Sextflag|=SEXTF_REPLF;
    if (pcfg->UCECflag & UCECF_NOS2D)
		Sextflag|=SEXTF_NOS2D;
UTRACED("mapinit exit char cfg",pcfg,UCVEXTCFGSZ);
UTRACEP("%s:extflag=%x\n",UTT,Sextflag);                           //~vbB9R~
//#ifdef LNX                                                       //~v5n2R~
//  ucvext_iconvmapinit(Popt,Sextflag,*Ppcfg); //pass static       //~v5n2R~//~v66NR~
//#endif                                                           //~v5n2R~
#ifdef UTF8EBCD                                                    //~v660I~
	if (Popt & UCEIO_LOCALEDIT)	//from xe                          //~v660R~
		if (UCECF_ISAVAIL_DBCSCV(pcfg))                            //~v660R~
			UDBCSCHK_SETDBCSCV();	//support dbcs                 //~v660I~
#endif                                                             //~v660I~
    break;                                                         //~v66DI~
  }//for                                                           //~v66DI~
  	if (pcfg->UCECsubchardbcs)                                     //~v66CI~
      	Ssubchardbcs=pcfg->UCECsubchardbcs;                        //~v66CI~
  	if (pcfg->UCECsubcharsbcs)                                     //~v66CI~
      	Ssubcharsbcs=pcfg->UCECsubcharsbcs;                        //~v66CI~
    UTRACEP("%s:subchar dbcs=%x,sbcs=%x\n",UTT,Ssubchardbcs,Ssubcharsbcs);//~v66CI~//~vbB9R~
//  ucvext_setupsubch(0,pcfg);                                     //~v66DI~//~v6bcR~
    pfuncs[0]=Spfunctoucs;                                         //~v69dI~
    pfuncs[1]=Spfuncfromucs;                                       //~v69dR~
    ucvext12_init(0,Sextflag,*Ppcfg,pfuncs);                       //~v69dR~
    ucvext_setupsubch(0,pcfg);                                     //~v6bcI~
    ucvext12_init(0,Sextflag,*Ppcfg,pfuncs);	//notify Sextflag at 1st call,notify subchar after setupsubch in this call//~v6bcI~
    ucvext_iconvmapinit(Popt,Sextflag,*Ppcfg); //pass static to ucvext2//~v66NI~
    UTRACED("Ppcfg",*Ppcfg,UCVEXTCFGSZ);                           //~v7dcI~
    ucvebc4_init(0,*Ppcfg);	//handle0 init                         //~v69cR~
    UTRACEP("%s:exit rc=%d\n",UTT,rc);                          //~v6baI~//~vbB4R~//~vbB9R~
    return rc;
}//ucvext_mapinit
#ifdef UTF8EBCD                                                    //~v66DI~
//*************************************************************************//~v66DI~
//*setup ebc/local subch                                           //~v66DI~
//*************************************************************************//~v66DI~
int ucvext_setupsubch(int Popt,PUCVEXTCFG Ppcfg)                   //~v66DI~
{                                                                  //~v66DI~
//  WUCS ucs,ucs2;                                                 //~v66CR~//~v6BjR~
    UWUCS ucs,ucs2;                                                //~v6BjR~
    int opt,mblen,rc2;                                             //~v66DI~
#ifdef W32                                                         //~v66PI~
    int subchmb,subchucs;                                          //~v66NR~
#endif                                                             //~v66PI~
	UCHAR mbstr[MAX_MBCSLEN];                                      //~v66DI~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    WUCS subchdbcscandidate[]={CHAR_UCS_DBCS_ERR/*"?"*/,CHAR_UCS_DBCS_ERR2/*space*/};//~v66VR~
    int ii;                                                        //~v66VI~
//***********************                                          //~v66DI~
    UTRACEP("%s:opt=%08x\n",UTT,Popt);                             //~v7duI~
//*get ICU subchar translated value to chk subchar was set         //~v66DI~
  	if (Ppcfg->UCECflag & UCECF_USE_ICU)                           //~v66DI~
    {                                                              //~v66DI~
//*dbcs                                                            //~v66DI~
		if (UDBCSCHK_ISDBCSCV())                                   //~v66DI~
    	{                                                          //~v66DI~
            opt=0;  //no subchrc(not yet setup chkchar)            //~v66DR~
            ucs=UDBCSCHK_SUBCHAR_DBCS;  //fffd                     //~v66DI~
        	pconverter=Ppcfg->UCECconverterdbcs;                   //~v66DI~
        	if (pconverter)                                        //~v66DI~
        	{                                                      //~v66DI~
        		rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~
        		if (rc2<=1 &&  mblen>1)                            //~v66DI~
                {                                                  //~v66DI~
    				opt=EBC2ASC_STAT_SO;                           //~v66DI~
          			rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,mblen,&ucs2);//~v66DI~
                    if (!rc2 && ucs2==ucs)                         //~v66DI~
                    {                                              //~v66DI~
        				UmemcpyZ(SsubcharICUebcDbcs,mbstr,(UINT)mblen);//~v66DR~
						SsubcharICUebcDbcslen=mblen;               //~v66DR~
                        UTRACEP("%s:ICU ISDBCSCV ucs=%04x,icuucs2ebc1 SsubcharICUebcDbcs=%s\n",UTT,ucs,mbstr);//~v7duI~
                    }                                              //~v66DI~
                }                                                  //~v66DI~
        	}                                                      //~v66DI~
//local converter is not icu                                       //~v66NI~
//            pconverter=Ppcfg->UCECconverterlocal;                  //~v66DI~//~v66NR~
//            if (pconverter)                                        //~v66DI~//~v66NR~
//            {                                                      //~v66DI~//~v66NR~
//                opt=EBC2ASC_LOCALCV;                               //~v66DR~//~v66NR~
//                rc2=ucvext_icuucs2local1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~//~v66NR~
//                if (rc2<=1 &&  mblen>1)                            //~v66DI~//~v66NR~
//                {                                                  //~v66DI~//~v66NR~
//                    rc2=ucvext_iculocal2ucs1(opt,pconverter,mbstr,mblen,0/*chklen*/,&ucs2);//~v66DI~//~v66NR~
//                    if (!rc2 && ucs2==ucs)                         //~v66DR~//~v66NR~
//                    {                                              //~v66DI~//~v66NR~
//                        UmemcpyZ(SsubcharICUlocalDbcs,mbstr,(UINT)mblen);//~v66DR~//~v66NR~
//                        SsubcharICUlocalDbcslen=mblen;             //~v66DR~//~v66NR~
//                    }                                              //~v66DI~//~v66NR~
//                }                                                  //~v66DI~//~v66NR~
//            }                                                      //~v66DI~//~v66NR~
        }                                                          //~v66DI~
//*sbcs                                                            //~v66DI~
        opt=0;                                                     //~v66DR~
        ucs=UDBCSCHK_SUBCHAR_SBCS;  //1a                           //~v66DI~
        pconverter=Ppcfg->UCECconvertersbcs;                       //~v66DI~
        if (!pconverter)                                           //~v66DR~
	        pconverter=Ppcfg->UCECconverterdbcs;                   //~v66DI~
        if (pconverter)                                            //~v66DI~
        {                                                          //~v66DI~
            rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~
            if (rc2<=1 &&  mblen==1)                               //~v66DI~
            {                                                      //~v66DI~
        		rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,mblen,&ucs2);//~v66DI~
//              if (!rc2 && ucs2==ucs)                             //~v66DI~//~v6BtR~
                if (!rc2 && (ucs2==ucs||ucs2==UDBCSCHK_SUBCHAR_DBCS))  //u-1a if subchar1 defined else u-fffd for undefined codepoint//~v6BtR~
	                SsubcharICUebcSbcs=*mbstr;                     //~v66DR~
                UTRACEP("%s:ICU ucs=%04x,icuucs2ebc1 SsubcharICUebcSbcs=%02x\n",UTT,ucs,*mbstr);//~v7duI~
            }                                                      //~v66DI~
        }                                                          //~v66DI~
//local converter is not icu                                       //~v66NI~
//        pconverter=Ppcfg->UCECconverterlocal;                      //~v66DI~//~v66NR~
//        if (pconverter)                                            //~v66DI~//~v66NR~
//        {                                                          //~v66DI~//~v66NR~
//            opt=EBC2ASC_LOCALCV;                                   //~v66DR~//~v66NR~
//            rc2=ucvext_icuucs2local1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~//~v66NR~
//            if (rc2<=1 &&  mblen==1)                               //~v66DI~//~v66NR~
//            {                                                      //~v66DI~//~v66NR~
//                rc2=ucvext_iculocal2ucs1(opt,pconverter,mbstr,mblen,0/*chklen*/,&ucs2);//~v66DI~//~v66NR~
//                if (!rc2 && ucs2==ucs)                             //~v66DR~//~v66NR~
//                    SsubcharICUlocalSbcs=*mbstr;                   //~v66DR~//~v66NR~
//            }                                                      //~v66DI~//~v66NR~
//        }                                                          //~v66DI~//~v66NR~
    	UTRACEP("%s:icu getconvertersubch sbcs=%02x,dbcs=%02x%02x,len=%d,localsbcs=%02x,dbcs==%02x%02x,len=%d\n",//~v66DR~//~vbB9R~
				UTT,SsubcharICUebcSbcs,SsubcharICUebcDbcs[0],SsubcharICUebcDbcs[1],SsubcharICUebcDbcslen,//~v66DI~//~vbB9R~
				SsubcharICUlocalSbcs,SsubcharICUlocalDbcs[0],SsubcharICUlocalDbcs[1],SsubcharICUlocalDbcslen);//~v66DI~
    }//USE_ICU                                                     //~v66DI~
#ifdef W32                                                         //~v66NI~
    else                                                           //~v66NI~
    {                                                              //~v66NI~
        pconverter=Ppcfg->UCECconverterdbcs;                       //~v66NI~
		if (pconverter)                                            //~v66NI~
//  		if (!udbcschk_getsubch(0,pconverter,&subchmb,&subchucs))//~v6x5R~
    		if (!udbcschk_getsubch(0,(ULONG)pconverter/*codepage*/,&subchmb,&subchucs))//~v6x5I~
            {	                                                   //~v66NI~
//          	Ppcfg->UCECsubchardefaultucsdbcs=subchucs;         //~v6x8R~
            	Ppcfg->UCECsubchardefaultucsdbcs=(USHORT)subchucs; //~v6x8I~
//          	Ppcfg->UCECsubchardefaultmbdbcs=subchmb;           //~v66NI~//~v69cR~
                UTRACEP("%s:Not ICU Win udbcschk_getsubch DBCS dcodepage=%ld,efaultucsdbcs=%04x,subchmb=%04x\n",UTT,(ULONG)pconverter,subchucs,subchmb);//~v7duI~
            }                                                      //~v66NI~
        pconverter=Ppcfg->UCECconvertersbcs;                       //~v66NI~
		if (pconverter)                                            //~v66NI~
//  		if (!udbcschk_getsubch(0,pconverter,&subchmb,&subchucs))//~v6x5R~
    		if (!udbcschk_getsubch(0,(ULONG)pconverter/*codepage*/,&subchmb,&subchucs))//~v6x5I~
            {                                                      //~v66NI~
//          	Ppcfg->UCECsubchardefaultucssbcs=subchucs;         //~v6x8R~
            	Ppcfg->UCECsubchardefaultucssbcs=(USHORT)subchucs; //~v6x8I~
//          	Ppcfg->UCECsubchardefaultmbsbcs=subchmb;           //~v66NI~//~v69cR~
                UTRACEP("%s:Not ICU Win udbcschk_getsubch SBCS codepage=%ld,defaultucssbcs=%04x,subchmb=%04x\n",UTT,(ULONG)pconverter,subchucs,subchmb);//~v7duI~
            }                                                      //~v66NI~
    }                                                              //~v66NM~
        pconverter=Ppcfg->UCECconverterlocal;                      //~v66NI~
		if (pconverter)                                            //~v66NI~
//  		if (!udbcschk_getsubch(0,pconverter,&subchmb,&subchucs))//~v6x5R~
    		if (!udbcschk_getsubch(0,(ULONG)pconverter/*codepage*/,&subchmb,&subchucs))//~v6x5I~
            {                                                      //~v66NI~
//          	Ppcfg->UCECsubchardefaultucslocal=subchucs;        //~v6x8R~
            	Ppcfg->UCECsubchardefaultucslocal=(USHORT)subchucs;//~v6x8I~
//          	Ppcfg->UCECsubchardefaultmblocal=subchmb;          //~v6x8R~
            	Ppcfg->UCECsubchardefaultmblocal=(USHORT)subchmb;  //~v6x8I~
                UTRACEP("%s:Win udbcschk_getsubch LOCAL codepage=%ld,defaultucslocal=%04x,subchmb=%04x\n",UTT,(ULONG)pconverter,subchucs,subchmb);//~v7duR~
            }                                                      //~v66NI~
#endif                                                             //~v66NI~
//*prepare locale/ebc code subchar                                 //~v66CI~
//*dbcs                                                            //~v66CI~
    if (UDBCSCHK_ISDBCSCV())                                       //~v66CI~
    {                                                              //~v66CI~
        opt=0;  //no subchrc                                       //~v66CI~
        ucs=Ssubchardbcs;  //default xfffd                         //~v66CI~
        pconverter=Ppcfg->UCECconverterdbcs;                       //~v66CI~
        Ssubcharebcdbcslen=2;                                      //~v66VI~
//      UTF_SETUCSBESTR(CHAR_EBC_DBCS_SPACE,Ssubcharebcdbcs);//set default//~v66VR~//~v7dQR~
        UTF_SETUCSBESTR(CHAR_EBC_DBCS_SUBCHAR,Ssubcharebcdbcs);//set default//~v7dQI~
        if (pconverter)                                            //~v66CI~
        {                                                          //~v66CI~
          for (ii=0;ii<=sizeof(subchdbcscandidate)/sizeof(WUCS);ii++)
          {
            rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66CI~
        UTRACEP("%s:dbcs ebc chk ucs=%04x,rc=%d\n",UTT,(UINT)ucs,rc2);//~v6bnR~//~vbB9R~
        UTRACED("setupsubch dbcs ebc ",mbstr,mblen);
            if (rc2<=1 &&  mblen>1)                                //~v66CI~
            {                                                      //~v66CI~
            	UmemcpyZ(Ssubcharebcdbcs,mbstr,(UINT)mblen);       //~v66CR~
                    Ssubcharebcdbcslen=mblen;                      //~v66CR~
		        UTRACEP("%s:ISDBCSCV icuucs2ebc1 ucs=%04x,Ssubcharebcdbcs=mbstr=%s\n",UTT,(UINT)ucs,mbstr);//~v7duI~
                break;
            }                                                      //~v66CI~
            ucs=subchdbcscandidate[ii];
          }
        }                                                          //~v66CI~
        pconverter=Ppcfg->UCECconverterlocal;                      //~v66CI~
        opt=0;                                                     //~v66CI~
        if (pconverter)                                            //~v66CI~
            opt=EBC2ASC_LOCALCV;                                   //~v66CI~
        UTRACEP("%s:LOCALCV opt=%08x,UCECconverterlocal=%p\n",UTT,opt,pconverter);//~v7dMI~
#ifdef W32                                                         //~v66NI~
  		if (!(Ppcfg->UCECsubchardbcs))	//no user                  //~v66NI~
            ucs=Ppcfg->UCECsubchardefaultucslocal;                 //~v66NR~
#endif                                                             //~v66NI~
      for (ii=0;ii<=sizeof(subchdbcscandidate)/sizeof(WUCS);ii++)  //~v66VR~
      {                                                            //~v66VI~
//      rc2=ucvext_icuucs2local1(opt,pconverter,ucs,mbstr,&mblen); //~v66CR~//~v6BjR~
        rc2=ucvext_icuucs2local1(opt,pconverter,(UWUCS)ucs,mbstr,&mblen);//~v6BjI~
        UTRACEP("%s:dbcs chk ucs=%04x,rc=%d\n",UTT,(UINT)ucs,rc2);//~v66VR~//~v6bnR~//~vbB9R~
//      if (rc2<=1 &&  mblen>1)                                    //~v66WR~
        if (rc2<=1 &&  mblen==2)                                   //~v66WI~
        {                                                          //~v66CR~
            UmemcpyZ(Ssubcharlocaldbcs,mbstr,(UINT)mblen);         //~v66CR~
            Ssubcharlocaldbcslen=mblen;                            //~v66CR~
		    UTRACEP("%s:ISDBCSCV icuucs2local1 ucs=%04x,Ssubcharlocaldbcs=mbstr=%02x%02x\n",UTT,(UINT)ucs,*mbstr,*(mbstr+1));//~v7duR~
            break;                                                 //~v66VI~
        }                                                          //~v66CR~
        ucs=subchdbcscandidate[ii];                                //~v66VI~
      }                                                            //~v66VI~
    }                                                              //~v66CI~
//*sbcs                                                            //~v66CI~
    opt=0;                                                         //~v66CR~
    ucs=Ssubcharsbcs;  //x1a or cfg parm                           //~v66CR~
    pconverter=Ppcfg->UCECconvertersbcs;                           //~v66CR~
    if (!pconverter)                                               //~v66CR~
        pconverter=Ppcfg->UCECconverterdbcs;                       //~v66CR~
    if (pconverter)                                                //~v66CR~
    {                                                              //~v66CR~
        rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);   //~v66CR~
        if (rc2<=1 &&  mblen==1)                                   //~v66CR~
            Ssubcharebcsbcs=*mbstr;                                //~v66CR~
		UTRACEP("%s:icuucs2ebc1 ucs=%04x,Ssubcharebcsbcs=mbstr=%02x\n",UTT,(UINT)ucs,*mbstr);//~v7duI~
    }                                                              //~v66CR~
    if (!UDBCSCHK_ISDBCSCV())                                      //~v68jI~
    {                                                              //~v68jI~
        Ssubcharebcdbcslen=2;                                      //~v68jI~
        memset(Ssubcharebcdbcs,Ssubcharebcsbcs,2);                 //~v68jR~
		UTRACEP("%s:NOT ISDBCSCV Ssubcharebcdbcs=%02x%02x\n",UTT,(UINT)ucs,Ssubcharebcsbcs,Ssubcharebcsbcs);//~v7duI~
    }                                                              //~v68jI~
#ifdef W32                                                         //~v66NM~
  if (!(Ppcfg->UCECsubcharsbcs))	//no user parm                 //~v66NI~
  {                                                                //~v7duI~
    Ssubcharlocalsbcs=(UCHAR)(Ppcfg->UCECsubchardefaultmblocal);   //~v66NR~
	UTRACEP("%s:Win Ssubcharlocalsbcs=%02x\n",UTT,Ssubcharlocalsbcs);//~v7duR~
  }                                                                //~v7duI~
  else                                                             //~v66NI~
#endif                                                             //~v66NM~
  {                                                                //~v66NI~
//  if (Ppcfg->UCECflag & UCECF_USE_CONVERTER) //use "?" if internal map//~v66CR~
//  {                                                              //~v66CR~
    	pconverter=Ppcfg->UCECconverterlocal;                      //~v66CR~
    	opt=0;                                                     //~v66CR~
    	if (pconverter)                                            //~v66CR~
        	opt=EBC2ASC_LOCALCV;                                   //~v66CR~
        UTRACEP("%s:LOCALCV opt=%08x,UCECconverterlocal=%p\n",UTT,opt,pconverter);//~v7dMI~
//  	rc2=ucvext_icuucs2local1(opt,pconverter,ucs,mbstr,&mblen); //~v66CR~//~v6BjR~
    	rc2=ucvext_icuucs2local1(opt,pconverter,(UWUCS)ucs,mbstr,&mblen);//~v6BjI~
    	if (rc2<=1 &&  mblen==1)                                   //~v66CR~
        	Ssubcharlocalsbcs=*mbstr;                              //~v66CR~
		UTRACEP("%s:Ssubcharlocalsbcs=%02x\n",UTT,Ssubcharlocalsbcs);//~v7duR~
//  }                                                              //~v66CR~
  }                                                                //~v66NI~
    UTRACEP("%s:getconvertersubch ebcsbcs=%02x,ebcdbcs=%02x%02x,len=%d,localsbcs=%02x,localdbcs==%02x%02x,len=%d\n",//~v66CR~//~vbB9R~//~v7duR~
            UTT,Ssubcharebcsbcs,Ssubcharebcdbcs[0],Ssubcharebcdbcs[1],Ssubcharebcdbcslen,//~v66CR~//~vbB9R~
            Ssubcharlocalsbcs,Ssubcharlocaldbcs[0],Ssubcharlocaldbcs[1],Ssubcharlocaldbcslen);//~v66CR~
    Ppcfg->UCECsubcharlocalsbcs=Ssubcharlocalsbcs;                 //~v66CR~
    Ppcfg->UCECsubcharebcsbcs=Ssubcharebcsbcs;                     //~v66CR~
    strcpy(Ppcfg->UCECsubcharlocaldbcs,Ssubcharlocaldbcs);         //~v66CR~
    strcpy(Ppcfg->UCECsubcharebcdbcs,Ssubcharebcdbcs);             //~v66CR~
    return 0;                                                      //~v66DI~
}//ucvext_setupsubch                                               //~v66DI~
#endif                                                             //~v66DI~
//*************************************************************************//~v6g2I~
int ucvext_loaddll_icudata(int Popt,char *Pdllname,char *Penvvar,ULPTR *Pphandle)//~v6M2R~
{                                                                  //~v6M2I~
//********************                                             //~v6M2I~
	char *pc,*pc2;                                                 //~v6M2I~
    int len,rc=0;                                                  //~v6M2R~
    char fpath[_MAX_PATH]={0};                                     //~v6M2R~
    int opt=0;                                                     //~v6M2I~
//**********************************                               //~v6M2I~
    UTRACEP("%s:envvar=%s,dllname=%s\n",UTT,Penvvar,Pdllname);         //~v70dI~//~vbB9R~
    pc=Penvvar;                                                    //~v6M2I~
    for (;*pc;pc+=len+1)                                           //~v6M2I~
    {                                                              //~v6M2I~
    	pc2=strchr(pc,ENV_SEPC);                                   //~v6M2I~
        if (pc2)                                                   //~v6M2I~
        	len=PTRDIFF(pc2,pc);                                   //~v6M2I~
        else                                                       //~v6M2I~
        	len=(int)strlen(pc);                                   //~v6M2I~
        if (!len)                                                  //~v6M2I~
        {                                                          //~v6M2I~
          if (pc2)	//continued seperator                          //~v6M2I~
        	continue;                                              //~v6M2I~
          else                                                     //~v6M2I~
          	break;                                                 //~v6M2I~
        }                                                          //~v6M2I~
        if (pc2)                                                   //~v6M2I~
			*pc2=0;                                                //~v6M2R~
        if (*(pc+len-1)==DIR_SEPC)                                 //~v6M2I~
	        sprintf(fpath,"%s%s",pc,Pdllname);                     //~v6M2I~
        else                                                       //~v6M2I~
	        sprintf(fpath,"%s%c%s",pc,DIR_SEPC,Pdllname);          //~v6M2R~
        rc=(int)ufstat(fpath,0);                                   //~v6M2R~
    	UTRACEP("%s:ufstat rc=%d,fpath=%s\n",UTT,rc,fpath);        //~v6M2I~
        if (!rc)                                                   //~v6M2R~
        	break;                                                 //~v6M2I~
        if (pc2)                                                   //~v6M2I~
			*pc2=ENV_SEPC;                                         //~v6M2I~
    }                                                              //~v6M2I~
//  listenv();//TODO test                                          //~v70dR~
    if (rc)                                                        //~v6M2R~
    {                                                              //~v6M2I~
  	    uerrmsg("ICU library %s not found on ICU_DATA path:%s",0,  //~v6M2I~
    	            Pdllname,Penvvar);                             //~v6M2I~
        rc=4;                                                      //~v6M2I~
    }                                                              //~v6M2I~
    else                                                           //~v6M2I~
    {                                                              //~v6M2I~
		if (Popt & UPGPAO_NOW)       //RTLD_NOW                    //~v6M2I~
			opt|=UPLD_NOW;			//         //RTLD_NOW          //~v6M2I~
        opt|=UPLD_DELEMSG|UPLD_SETICUDATAENV;         //ugeterrmsg to delete previous uerrmsg//~v6M2R~
		rc=uproc_loaddllpath(opt,fpath,0,0,Pphandle);              //~v6M2R~
    }                                                              //~v6M2I~
//  listenv();//TODO test                                          //~v70dR~
    UTRACEP("%s:rc=%d,so=%s,paths=%s,fpath=%s\n",UTT,rc,Pdllname,Penvvar,fpath);//~v6M2R~
    return rc;                                                     //~v6M2I~
}//ucvext_loaddll_icudata                                          //~v6M2I~
//*************************************************************************//~v6g2I~
//int ucvext_loaddll(int Popt,char *Pdllname,char *Pdllfpath,ULONG *Pphandle)//~v6g2I~//~v6hhR~
int ucvext_loaddll(int Popt,char *Pdllname,char *Pdllfpath,ULPTR *Pphandle)//~v6hhI~
{                                                                  //~v6g2I~
    int rc=0;                                                      //~v6g2I~
    int opt=0;                                                     //~v6g2I~
//********************                                             //~v6g2I~
    UTRACEP("%s:opt=0x%x,dllname=%s,dllfpath=%s\n",UTT,Popt,Pdllname,Pdllfpath);//~v77PI~
	if (Popt & UPGPAO_NOW)       //RTLD_NOW                        //~v6g2I~
		opt|=UPLD_NOW;			//         //RTLD_NOW              //~v6g2I~
//  rc=uproc_loaddll(opt,Pdllname,0,Pphandle);                     //~v6g2I~//~v6M0R~
//  rc=uproc_loaddllpath(opt,Sicudataparm,Pdllname,0,Pphandle);    //~v6M0R~//~v6M2R~
    rc=uproc_loaddll(opt,Pdllname,0,Pphandle);                     //~v6M2I~
//    if (rc)                                                      //~v6g2R~
//        rc=uproc_loaddll(opt,Pdllfpath,0,Pphandle);              //~v6g2R~
    if (rc)                                                        //~v6M2I~
      if (Pdllfpath && *Pdllfpath)                                 //~v6M2I~
        rc=uproc_loaddll(opt,Pdllfpath,0,Pphandle);                //~v6M2I~
#ifdef W32                                                         //~v6M3I~
    if (rc)                                                        //~v6M2R~
      if (Sicudataparm && *Sicudataparm)                           //~v6M2I~
        rc=ucvext_loaddll_icudata(Popt,Pdllname,Sicudataparm,Pphandle);//~v6M2R~
#endif                                                             //~v6M3I~
    return rc;                                                     //~v6g2I~
}//ucvext_loaddll                                                  //~v6g2I~
//*************************************************************************
//*get icu converter
//*Papis:optional output 3 api addr(open,toucs,fromucs)
//*************************************************************************
//int ucvext_icuinit(int Popt,char *Pdllversion,char *Pprocversion,ULONG *Papis)//~v6x5R~
int ucvext_icuinit(int Popt,char *Pdllversion,char *Pprocversion,ULPTR *Papis)//~v6x5I~
{
//#ifdef W32                                                       //~v5n2R~
	char dllname[32];
//  ULONG paddr;                                                   //~v6hhR~
    ULPTR paddr;                                                   //~v6hhI~
//  ULONG handle;                                                  //~v6baR~
    DLHANDLE handle;                                               //~v6baI~
//#endif  //W32                                                    //~v5n2R~
    int rc=0;
    int opt=0;                                                     //~v6f7I~
//***********************
    UTRACEP("%s:opt=0x%x,dllversion=%s,procversion=%s\n",UTT,Popt,Pdllversion,Pprocversion);//~v77PI~
#ifdef UTF8EBCD                                                    //~v660I~
  if (!(Popt & UCEIO_USEICU))	//explicit request                 //~v660I~
#endif                                                             //~v660I~
  	if (!IS_ICUMODE())                                             //~v5n1R~
  		return 0;                                                  //~v5n1R~
#ifdef W32                                                         //~v5mTI~
//  sprintf(dllname,"%s%s",ICU_DLLNAME,Pdllversion);               //~v6M2R~
	sprintf(dllname,"%s%s.dll",ICU_DLLNAME,Pdllversion);           //~v6M2I~
#else                                                              //~v5n2I~
//  printf("dllversion=%s,apiversion=%s;",Pdllversion,Pprocversio  //~v6baR~
  if (Pdllversion && *Pdllversion)                                 //~v6baR~
	sprintf(dllname,"lib%s.so.%s",ICU_DLLNAME,Pdllversion);        //~v5n2R~
  else                                                             //~v6baI~
	sprintf(dllname,"lib%s.so",ICU_DLLNAME);                       //~v6baI~
#endif  //W32                                                      //~v5n2I~
//#ifdef ARMXXE                                                      //~v77nR~//~v77NR~
#ifdef ARM                                                         //~v77NI~
	if (*Sicusoname)  //soname defined without fpath               //~v77nI~
		strcpy(dllname,Sicusoname);                                 //~v77nI~
#endif                                                             //~v77nI~
    strncpy(Sicuapisuffix,Pprocversion,sizeof(Sicuapisuffix)-1);
    handle=0;
    for (;;)
    {
		opt|=UPGPAO_NOW;        //RTLD_NOW                         //~v6f7I~
	    rc=ucvext_loaddll(opt,dllname,Sdllfpath,&handle);          //~v6g2I~
    	if (rc)                                                    //~v6g2I~
        	break;                                                 //~v6g2I~
		rc=uproc_getprocaddr(opt,dllname,0,ICUAPINAME_UERRNAME,Pprocversion,&handle,&paddr);//~v6f7R~
    	if (rc)
        	break;
        Shiculib=handle;
        if (Shiculib)                                              //~v69dI~
        	Sextflag|=SEXTF_LIBOPENED;                             //~v69dI~
		Spfuncuerrname=(ICUFUNC_UERRNAME)paddr;
        opt=0;                                                     //~v7d2R~
#ifdef W32                                                         //~v7d2I~
		opt|=UPGPAO_NOMSG;                                         //~v7d2I~
#endif                                                             //~v7d2I~
//      rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_SETDATADIR,Pprocversion,&handle,&paddr);//~v6bpI~//~v7d2R~
        rc=uproc_getprocaddr(opt,dllname,0,ICUAPINAME_SETDATADIR,Pprocversion,&handle,&paddr);//~v7d2I~
        opt=0;                                                     //~v7d2I~
        Spfuncsetdatadir=(ICUFUNC_SETDATADIR)paddr;                //~v6bpI~
#ifdef TEST_GETDIR                                                 //~v6c3I~
#ifdef W32                                                         //~v7d2I~
		opt|=UPGPAO_NOMSG;                                         //~v7d2I~
#endif                                                             //~v7d2I~
//      rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_GETDATADIR,Pprocversion,&handle,&paddr);//~v6c3I~//~v7d2R~
        rc=uproc_getprocaddr(opt,dllname,0,ICUAPINAME_GETDATADIR,Pprocversion,&handle,&paddr);//~v7d2I~
        Spfuncgetdatadir=(ICUFUNC_GETDATADIR)paddr;                //~v6c3I~
        opt=0;                                                     //~v7d2I~
#ifdef ARM                                                         //~v6c3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_FILEACCESS,Pprocversion,&handle,&paddr);//~v6c3I~
        Spfuncfileaccess=(ICUFUNC_FILEACCESS)paddr;                //~v6c3I~
#endif                                                             //~v6c3I~
#endif                                                             //~v6c3I~
                                                                   //~v6bpI~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_OPEN,Pprocversion,&handle,&paddr);
        if (rc)
            break;
        Spfuncopen=(ICUFUNC_OPEN)paddr;
        if (Papis)
            Papis[0]=paddr;
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_CLOSE,Pprocversion,&handle,&paddr);//~v6f4I~
        if (rc)                                                    //~v6f4I~
            break;                                                 //~v6f4I~
        Spfuncclose=(ICUFUNC_CLOSE)paddr;                          //~v6f4I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_RESET,Pprocversion,&handle,&paddr);//~v6f3I~
        if (rc)                                                    //~v6f3I~
            break;                                                 //~v6f3I~
        Spfuncreset=(ICUFUNC_RESET)paddr;                          //~v6f3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_TOUCS,Pprocversion,&handle,&paddr);
        if (rc)
            break;
        Spfunctoucs=(ICUFUNC_TOUCS)paddr;
        if (Papis)
            Papis[1]=paddr;
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_FROMUCS,Pprocversion,&handle,&paddr);
        if (rc)
            break;
        Spfuncfromucs=(ICUFUNC_FROMUCS)paddr;
        if (Papis)
            Papis[2]=paddr;
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_SETFALLBACK,Pprocversion,&handle,&paddr);//~v66rI~
        if (rc)                                                    //~v66rI~
            break;                                                 //~v66rI~
        Spfuncsetfallback=(ICUFUNC_SETFALLBACK)paddr;              //~v66rR~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_USESFALLBACK,Pprocversion,&handle,&paddr);//~v66rI~
        if (rc)                                                    //~v66rI~
            break;                                                 //~v66rI~
        Spfuncusesfallback=(ICUFUNC_USESFALLBACK)paddr;            //~v66rI~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_GETSUBCHARS,Pprocversion,&handle,&paddr);//~v6f2R~//~v6f3I~
        if (rc)                                                    //~v6f2I~//~v6f3I~
            break;                                                 //~v6f2I~//~v6f3I~
        Spfuncgetsubchars=(ICUFUNC_GETSUBCHARS)paddr;              //~v6f2I~//~v6f3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_SETSUBCHARS,Pprocversion,&handle,&paddr);//~v6f3I~
        if (rc)                                                    //~v6f3I~
            break;                                                 //~v6f3I~
        Spfuncsetsubchars=(ICUFUNC_SETSUBCHARS)paddr;              //~v6f3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_GETNAME,Pprocversion,&handle,&paddr);//~v6f3I~
        if (rc)                                                    //~v6f3I~
            break;                                                 //~v6f3I~
        Spfuncgetname=(ICUFUNC_GETNAME)paddr;                      //~v6f3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_GETSTARTER,Pprocversion,&handle,&paddr);//~v6f3I~
        if (rc)                                                    //~v6f3I~
            break;                                                 //~v6f3I~
        Spfuncgetstarter=(ICUFUNC_GETSTARTER)paddr;                //~v6f3I~
        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_GETDEFNAME,Pprocversion,&handle,&paddr);//~v6f7I~
        if (rc)                                                    //~v6f7I~
            break;                                                 //~v6f7I~
        Spfuncgetdefname=(ICUFUNC_GETDEFNAME)paddr;                //~v6f7I~
                                                                   //~v77EI~
//!ucnv_versio is not define                                       //~v77EI~
//        rc=uproc_getprocaddr(0,dllname,0,ICUAPINAME_VERSION,Pprocversion,&handle,&paddr);//~v77ER~
//        if (!rc)                                                 //~v77ER~
//        {                                                        //~v77ER~
//            Spfuncversion=(ICUFUNC_VERSION)paddr;                //~v77ER~
//            int version=(*Spfuncversion)();                      //~v77ER~
//            UTRACEP("%s:version=%d\n",version);                  //~v77ER~
//        }                                                        //~v77ER~
        break;
    }
//#endif  //W32                                                    //~v5n2R~
  if (!(Popt & UCEIO_LOCALICU))	//not local is by ICU bit ebcdic local ICU//~v6f3R~
    if (Popt & UCEIO_USEICU)
    {                                                              //~v660I~
        UDBCSCHK_SETUSEICU();
#ifdef UTF8EBCD                                                    //~v660I~
		Sextflag|=SEXTF_ICU;	//for IS_ICUMODE                   //~v660I~
#endif                                                             //~v660I~
    }                                                              //~v660I~
    return rc;
}//ucvext_icuinit
//*************************************************************************//~v7dgI~
//*rc:1:EBCDIC_STATEFUL, -1:err, 0:other                           //~v7dgI~
//*************************************************************************//~v7dgI~
int chkStateful(char *Pcvname)                                     //~v7dgI~
{                                                                  //~v7dgI~
	int rc;                                                        //~v7dgI~
    UConverter *uc;                                                //~v7dgR~
    UTRACEP("%s:cvname=%s\n",UTT,Pcvname);                         //~v7dgI~
    UErrorCode err=U_ZERO_ERROR;                                   //~v7dgI~
	ICUFUNC_OPEN apiopen=Spfuncopen;                               //~v7dgI~
    uc=(*apiopen)(Pcvname,&err);                                   //~v7dgR~
    if (U_FAILURE(err))                                            //~v7dgI~
    {                                                              //~v7dgI~
    	UTRACEP("%s:open null, err=%d,%s\n",UTT,(UINT)err,ucvext_icuuerrname(err));//~v7dgI~
        return -1;                                                 //~v7dgI~
    }                                                              //~v7dgI~
 	int opt=UCVEBC4O_USEICU|UCVEBC4O_NOMSG;                        //~v7dgI~
    rc=ucvebc4_chkdbcsconverter(opt,(ULPTR)uc,Pcvname);            //~v7dgR~
    if (rc>1)                                                      //~v7dgI~
    {                                                              //~v7dgI~
    	UTRACEP("%s:chkdbcs rc=%d\n",UTT,rc);                      //~v7dgI~
    	return -1;                                                 //~v7dgI~
    }                                                              //~v7dgI~
	ICUFUNC_CLOSE apiclose=Spfuncclose;                            //~v7dgR~
    (*apiclose)(uc);                                               //~v7dgI~
    UTRACEP("%s:rc=%d(1:EBCDIC_STATEFUL)\n",UTT,rc);               //~v7dgI~
    return rc;                                                     //~v7dgI~
}                                                                  //~v7dgI~
//#ifdef W32                                                         //~v5mTI~//~v6baR~
//*************************************************************************
//*enum converter
//*************************************************************************
int ucvext_icuenumcvname(int Popt,char *Pdllversion,char* Pprocversion)
{
//    ULONG handle,paddr;                                          //~v6baR~
    DLHANDLE handle=0,paddr;                                       //~v6baR~
    ICUFUNC_ENUMCTR apienumctr;
    ICUFUNC_ENUMNAME apienumname;
    ICUFUNC_ENUMCTRA apienumctralias;
    ICUFUNC_ENUMNAMEA apienumnamealias;
#ifdef AAA                                                         //~v6baI~
    ICUFUNC_OPENALLNAME apiopenall;
    ICUFUNC_ENUMNEXT    apienumnext;
    ICUFUNC_ENUMCLOSE   apienumclose;
#endif                                                             //~v6baI~
    int rc=0,cvctr,ii,aliasctr,jj;
    char *cvname,*aliasname;
    UErrorCode err=U_ZERO_ERROR;
#ifdef AAA                                                         //~v6baI~
    UEnumeration *penum;
    UINT cvnamelen;
#endif                                                             //~v6baI~
	char dllname[32];                                              //~v6baI~
//********************
    UTRACEP("%s:opt=0x%x,dllversion=%s,procversiob=%s,Spcfg=%p\n",UTT,Popt,Pdllversion,Pprocversion,Spcfg);//~v77WI~//~vbB9R~
	if (!Pdllversion)                                              //~v6baI~
    {                                                              //~v6baI~
    	if (!Spcfg)                                                //~v6baI~
        	return 4;                                              //~v6baI~
        Pdllversion=Spcfg->UCECdllsuffix;                          //~v6baR~
        Pprocversion=Spcfg->UCECapisuffix;                         //~v6baI~
    }                                                              //~v6baI~
    for (;;)
    {
#ifdef W32                                                         //~v6baI~
	sprintf(dllname,"%s%s",ICU_DLLNAME,Pdllversion);               //~v6baI~
#else                                                              //~v6baI~
	if (Pdllversion && *Pdllversion)                               //~v6baI~
		sprintf(dllname,"lib%s.so.%s",ICU_DLLNAME,Pdllversion);    //~v6baR~
    else                                                           //~v6baI~
		sprintf(dllname,"lib%s.so",ICU_DLLNAME);                   //~v6baI~
#endif  //W32                                                      //~v6baI~
//		rc=uproc_loaddll(0,ICU_DLLNAME,Pdllversion,&handle);       //~v6baR~
  		rc=uproc_loaddll(0,dllname,0/*suffix*/,&handle);           //~v6baI~
        if (rc)
        	break;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMCTR,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
		apienumctr=(ICUFUNC_ENUMCTR)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMNAME,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
        apienumname=(ICUFUNC_ENUMNAME)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMCTRA,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
		apienumctralias=(ICUFUNC_ENUMCTRA)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMNAMEA,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
        apienumnamealias=(ICUFUNC_ENUMNAMEA)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_OPENALLNAME,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
#ifdef AAA                                                         //~v6baI~
        apiopenall=(ICUFUNC_OPENALLNAME)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMNEXT,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
        apienumnext=(ICUFUNC_ENUMNEXT)paddr;
        rc=uproc_getprocaddr(0,ICU_DLLNAME,0,ICUAPINAME_ENUMCLOSE,Pprocversion,&handle,&paddr);
        if (rc)
        	break;
        apienumclose=(ICUFUNC_ENUMCLOSE)paddr;
#endif                                                             //~v6baI~

//      cvctr=(*apienumctr)();                                     //~v6BkR~
        cvctr=(int)(*apienumctr)();                                //~v6BkI~
        UTRACEP("%s:enumctr=%d\n",UTT,cvctr);                      //~v77WR~
        for (ii=0;ii<cvctr;ii++)
        {
        	cvname=(*apienumname)((UINT)ii);
            int swstateful=chkStateful(cvname);                    //~v7dgI~
//          uerrmsg("Available convertername:%03d:%s",0,           //~v6baR~
          if (swstateful==1)                                       //~v7dgR~
            printf("%03d-Converter:%s (EBCDIC-stateful)\n",        //~v7dgI~
            		ii,cvname);                                    //~v7dgI~
          else                                                     //~v7dgI~
          if (swstateful==0)     //ebcdic(Nod dbcs)                //~v7dgI~
            printf("%03d-Converter:%s (EBCDIC)\n",                 //~v7dgI~
            		ii,cvname);                                    //~v7dgI~
          else                                                     //~v7dgI~
            printf("%03d-Converter:%s\n",                          //~v6baR~
            		ii,cvname);
            UTRACEP("%s:ii=%d,name=%s,stateful=%d\n",UTT,ii,cvname,swstateful);           //~v77WI~//~v7dgR~
	        aliasctr=(*apienumctralias)(cvname,&err);
			if (err!=U_ZERO_ERROR)
            {
		    	ufileapierr(ICUAPINAME_ENUMCTRA,cvname,(int)err);
            }
            else
            {
		        for (jj=0;jj<aliasctr;jj++)
        		{
        			aliasname=(*apienumnamealias)(cvname,(USHORT)jj,&err);
					if (err!=U_ZERO_ERROR)
				    	ufileapierr(ICUAPINAME_ENUMNAMEA,cvname,(int)err);
            		else
                    {                                              //~v6baI~
//          			uerrmsg("  Alias                 % 3d:%s",0,//~v6baR~
//          					jj,aliasname);                     //~v6baI~
                      if (stricmp(aliasname,cvname))               //~v6baI~
            			printf("        Alias:%s\n",               //~v6baR~
            					aliasname);                        //~v6baR~
                    }                                              //~v6baI~
                }
            }
        }
        printf("== %d entry listed\n",cvctr);                      //~v6baI~
#ifdef AAA                                                         //~v6baI~
//*openall
        penum=(*apiopenall)(&err);
		if (err!=U_ZERO_ERROR)
        {
			ufileapierr(ICUAPINAME_OPENALLNAME,"",(int)err);
        	break;
        }
        for (ii=0;;ii++)
        {
	        cvname=(*apienumnext)(penum,&cvnamelen,&err);
			if (err!=U_ZERO_ERROR)
        	{
				ufileapierr(ICUAPINAME_ENUMNEXT,"",(int)err);
        		break;
        	}
            if (!cvname)
                break;
            uerrmsg("Allname :%03d:%s",0,
            		ii,cvname);
    	}
	    (*apienumclose)(penum);
#endif                                                             //~v6baM~
        break;
	}
    return rc;
}//ucvext_icuenumcvname
//#endif  //W32                                                      //~v5mTI~//~v6baR~
//#ifdef W32                                                       //~v5n2R~
//*************************************************************************
//*get icu converter
//*************************************************************************
char *ucvext_icuuerrname(UErrorCode Puerr)
{
	char *perrmsg;
//static char Serrnum[8];                                          //~v6S1R~
static char Serrnum[16];                                           //~v6S1I~
//***********************
	if (Spfuncuerrname)
    	perrmsg=(*Spfuncuerrname)(Puerr);
    else
    {
    	sprintf(Serrnum,"%08x",(UINT)Puerr);
        perrmsg=Serrnum;
    }
    return perrmsg;
}//ucvext_icuuerrname
//#endif  //W32                                                    //~v5n2R~
//#ifdef W32                                                       //~v5n2R~
//*************************************************************************//~v6f3I~
//**getDefaultName returns null                                    //~v6f3I~
//**open(NULL)+getname returns UTF-8 or US-ASCII                   //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icugetdefaultconvertername2(int Popt,char *Pcharset,ULONG *Ppconverter)//~v6f3R~//~v6f7R~//~v6hhR~
int ucvext_icugetdefaultconvertername2(int Popt,char *Pcharset,ULPTR *Ppconverter)//~v6hhI~
{                                                                  //~v6f3I~
    UErrorCode err=U_ZERO_ERROR;                                   //~v6f3I~
	ICUFUNC_OPEN api;                                              //~v6f3I~
	ICUFUNC_GETNAME apign;                                         //~v6f3I~
    char *pname;                                                   //~v6f3R~
    int rc=0;                                                      //~v6f3I~
    UConverter *pconverter;                                        //~v6f3I~
//***********************                                          //~v6f3I~
	UTRACEP("%s:entry charset=%s\n",UTT,Pcharset);                 //~v77ER~
	if (ucvext_icumbinit(UCEIMIO_ENVINIT,0/*Pcharset*/,0/*ppconverter*/))//init dll env//~v6f3R~
    	return 8;                                                  //~v6f3I~
    api=Spfuncopen;                                                //~v6f3I~
    pconverter=(*api)(NULL,&err);                                  //~v6f3I~
	if (U_FAILURE(err))                                            //~v6f3I~
	{                                                              //~v6f3I~
		UTRACEP("%s:open null, err=%d,%s",UTT,(UINT)err,ucvext_icuuerrname(err));//~v6f3I~//~vbB9R~
		rc=4;                                                      //~v6f3I~
	}                                                              //~v6f3I~
    else                                                           //~v6f3I~
    {                                                              //~v6f3I~
        if (Ppconverter)                                           //~v6f3I~
//    	    *Ppconverter=(ULONG)pconverter;                        //~v6f3R~//~v6hhR~
    	    *Ppconverter=(ULPTR)pconverter;                        //~v6hhI~
	    apign=Spfuncgetname;                                       //~v6f3R~
    	pname=(*apign)(pconverter,&err);                           //~v6f3R~
		if (U_FAILURE(err))                                        //~v6f3I~
		{                                                          //~v6f3I~
			UTRACEP("%s:getname ,err=%d,%s",UTT,(UINT)err,ucvext_icuuerrname(err));//~v6f3I~//~vbB9R~
			rc=4;                                                  //~v6f3I~
		}                                                          //~v6f3I~
    	else                                                       //~v6f3I~
		    strcpy(Pcharset,pname);                                //~v6f3R~
        if (!Ppconverter)                                          //~v6f3I~
//        	ucvext_icuclose(0,(ULONG)pconverter);                  //~v6f3R~//~v6hhR~
        	ucvext_icuclose(0,(ULPTR)pconverter);                  //~v6hhI~
    }                                                              //~v6f3I~
    return rc;                                                     //~v6f3I~
}//ucvext_icugetdefaultconvertername2                              //~v6f9R~
//#ifdef ARM                                                         //~v6f9I~//~v6fbR~
//*********************************************************************//~v6f9I~
//* search preferable codeset                                      //~v6f9I~
//ret :rc; 1:not same as nlinfo,-1:env is utf8 no need to setlocale//~v6f9I~
//*********************************************************************//~v6f9I~
int ucvext_getstdcharset(int Popt,char *Pcharset)                  //~v6f9R~
{                                                                  //~v6f9I~
    char *pzhcncs[]={"GB18030","GBK","GB2312",0};                  //~v6f9I~
//  char *pkokrcs[]={"EUC-KR",0};  //unified hangul code           //~v6f9I~//~v6fkR~
    char *pkokrcs[]={"korean","EUC-KR",0};  //icu supports UHC as "korean"//~v6fkR~
//#ifdef ARM                                                         //~v791R~//~v77XR~
//    char *pjajpcs[]={"sjis","EUC-JP",0};  //unified hangul code    //~v791R~//~v77XR~
//#else                                                              //~v791R~//~v77XR~
    char *pjajpcs[]={"EUC-JP",0};  //unified hangul code           //~v6f9I~
//#endif                                                             //~v791R~//~v77XR~
    char *pzhtwcs[]={"Big5-HKSCS","Big5",0};//when on green console//~v6f9R~
    char *pothercs[]={"ISO-8859-1",0};//when on green console      //~v6f9R~
    char **ppc=0;                                                  //~v6f9I~
#ifndef ARM                                                        //~v702I~
    char *pc;                                                      //~v6f9I~//~v6fbR~
#endif                                                             //~v702I~
    int rc;                                                  //~v6f9R~//~v6fbR~
#ifdef ARM                                                         //~v6fbI~
//  char charset[MAXLOCALESZ];                                     //~v6fbR~//~v702R~
#endif                                                             //~v6fbI~
    char locale[MAXLOCALESZ];                                      //~v6fbI~
//************************                                         //~v6f9I~
#ifdef ARM                                                         //~v6fbI~
	rc=ulibarm_getdefaultcharset(0,locale,Pcharset);              //~v6f9I~//~v6fbR~
    if (rc>=2) //lang defined or err                              //~v6f9I~//~v6fbR~
        return rc;                                                //~v6f9I~//~v6fbR~
#else                                                              //~v6f9I~//~v6fbI~
    pc=udbcschk_setlocale(0,LC_CTYPE,"");                          //~v6f9I~//~v6fbI~
    strncpy(locale,pc,sizeof(locale));                             //~v6fbI~
    if (pc=strchr(locale,'.'),pc)   //codeset info                //~v6f9I~//~v6fbR~
    	*pc=0;                                                     //~v6fbR~
#endif                                                             //~v6f9I~//~v6fbI~
    rc=0;                                                          //~v6fbI~
    if (!stricmp(locale,LANG_ZHCN)) //simple chinese               //~v6f9I~
    {                                                              //~v6f9I~
    	for (ppc=pzhcncs;*ppc;ppc++)                               //~v6f9I~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    if (!stricmp(locale,LANG_KOKR)) //korean                       //~v6f9R~
    {                                                              //~v6f9I~
    	for (ppc=pkokrcs;*ppc;ppc++)                               //~v6f9I~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    if (!stricmp(locale,LANG_JAJP)) //japanese                     //~v6f9I~
    {                                                              //~v6f9I~
    	for (ppc=pjajpcs;*ppc;ppc++)                               //~v6f9I~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    if (!stricmp(locale,LANG_JA)) //japanese                       //~v6f9I~
    {                                                              //~v6f9I~
    	for (ppc=pjajpcs;*ppc;ppc++)                               //~v6f9I~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    if (!stricmp(locale,LANG_ZHTW)) //taiwan                       //~v6f9I~
    {                                                              //~v6f9I~
    	for (ppc=pzhtwcs;*ppc;ppc++)                               //~v6f9R~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    {                                                              //~v6f9I~
    	for (ppc=pothercs;*ppc;ppc++)                              //~v6f9I~
			if (!ucvext_icugetmbconverter(0,*ppc,0/*Ppconverter=0:chk only*/))//~v6f9R~
            	break;                                             //~v6f9I~
    }                                                              //~v6f9I~
    if (ppc && *ppc)                                               //~v6f9I~
    {                                                              //~v6f9I~
		strncpy(Pcharset,*ppc,MAXLOCALESZ-1);                      //~v6f9I~
        rc=1;                                                      //~v6f9I~
    }                                                              //~v6f9I~
    UTRACEP("%s:rc=%d,charset=%s\n",UTT,rc,Pcharset);//~v6f9R~     //~vbB9R~
 	return rc;                                                     //~v6f9I~
}//ucvext_getstdcharset                                            //~v6f9I~
//#endif                                                             //~v6f9I~//~v6fbR~
//*************************************************************************//~v6f7M~
//*get icu default converter name                                  //~v6f7M~
//*(converter  will be gotten by getconverter if converter name is NULL)//~v6f7M~
//*************************************************************************//~v6f7M~
//int ucvext_icugetdefaultconvertername(int Popt,char *Pcharset,ULONG *Ppconverter)//~v6f7I~//~v6hhR~
int ucvext_icugetdefaultconvertername(int Popt,char *Pcharset,ULPTR *Ppconverter)//~v6hhI~
{                                                                  //~v6f7M~
    UErrorCode err=U_ZERO_ERROR;                                   //~v6f7I~
//  ULONG handle;                                                  //~v6x5R~
    ULPTR handle;                                                  //~v6x5I~
	ICUFUNC_GETDEFNAME apigetdefname;                              //~v6f7M~
	ICUFUNC_OPEN apiopen;                                          //~v6f7I~
    char *pcharset;                                                //~v6f7M~
    int rc=0;                                                      //~v6f7R~
//#ifdef ARM                                                         //~v6f9I~//~v6fbR~
    char charset[MAXLOCALESZ];                                     //~v6f9I~
    int rc2;                                                       //~v6f9I~
//#endif                                                             //~v6f9I~//~v6fbR~
//***********************                                          //~v6f7M~
	UTRACEP("%s:entry charset=%s\n",UTT,Pcharset);                 //~v77ER~
	if (ucvext_icumbinit(UCEIMIO_ENVINIT,0/*Pcharset*/,0/*ppconverter*/))//init dll env//~v6f7I~
    	return 8;                                                  //~v6f7I~
    apigetdefname=Spfuncgetdefname;                                //~v6f7R~
//#ifdef ARM                                                         //~v6f9I~//~v6fbR~
    rc2=ucvext_getstdcharset(0,charset);                           //~v6f9R~
  if (rc2==1)                                                      //~v6f9R~
  	pcharset=charset;                                              //~v6f9I~
  else                                                             //~v6f9I~
//#endif                                                             //~v6f9I~//~v6fbR~
    pcharset=(*apigetdefname)();                                   //~v6f7M~
    if (!pcharset || !*pcharset)                                                //~v6f3I~//~v6f7I~
    	rc=ucvext_icugetdefaultconvertername2(Popt,Pcharset,Ppconverter);//~v6f7I~//~v6f9R~
    else                                                           //~v6f7I~
    {                                                              //~v6f7I~
	    strcpy(Pcharset,pcharset);                                 //~v6f7I~
        if (Ppconverter)                                           //~v6f7I~
        {                                                          //~v6f7I~
    		apiopen=Spfuncopen;                                    //~v6f7I~
//    		handle=(ULONG)(*apiopen)(pcharset,&err);               //~v6f7R~//~v6hhR~
    		handle=(ULPTR)(*apiopen)(pcharset,&err);               //~v6hhI~
        	if (U_FAILURE(err))                                    //~v6f7I~
        	{                                                      //~v6f7I~
            	UTRACEP("%s:open null, err=%d,%s",UTT,(UINT)err,ucvext_icuuerrname(err));//~v6f7I~//~vbB9R~
            	rc=4;                                              //~v6f7I~
            }                                                      //~v6f7I~
            else                                                   //~v6f7I~
//  	    	*Ppconverter=(ULONG)handle;                        //~v6x5R~
    	    	*Ppconverter=handle;                               //~v6x5I~
        }                                                          //~v6f7I~
    }                                                              //~v6f7I~
    return rc;                                                     //~v6f7I~
}//ucvext_icugetdefaultconvertername                               //~v6f3I~//~v6f7M~
//#endif  //W32                                                    //~v5n2R~
//#ifdef W32                                                       //~v5n2R~
//*************************************************************************
//*get converter type (SBCS,DBCS,MBCS...)
//*rc:-1:unsupported,0:sbcs,1:dbcs,2:MBCS,8:other
//*************************************************************************
//int ucvext_icugetconvertertype(int Popt,ULONG Pconverter,int *Pptype)//~v6hhR~
int ucvext_icugetconvertertype(int Popt,ULPTR Pconverter,int *Pptype)//~v6hhI~
{
	UConverter *pconverter;
    char *pconvertername;
	UConverterType convtype;
//    ULONG handle,paddr;                                          //~v6baR~
    DLHANDLE handle,paddr;                                         //~v6baI~
	ICUFUNC_GETTYPE api;
    int rc=8;
//***********************
//	if (!IS_ICUMODE())                                             //~v5n1I~//~v66KR~
	UTRACEP("%s:opt=0x%04x\n",UTT,Popt);                           //~v7d7I~
  if (!(Popt & UCEIO_OPENICU))	//ICU specific function req        //~v6fdR~
  	if (!IS_ICU_CONVERTER(Popt))                                   //~v66KI~
		return ucvext_iconvgetconvertertype(Popt,Pconverter,Pptype);//~v5n1I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
    handle=Shiculib;
	rc=uproc_getprocaddr(0,0/*dllname*/,0/*dll version*/,ICUAPINAME_GETTYPE,Sicuapisuffix,&handle,&paddr);
    if (rc)
    	return 4;
    api=(ICUFUNC_GETTYPE)paddr;
	if (Popt & UCEIO_OPENED) //UConverter parm is opened ,else parm is convertername
		pconverter=(UConverter*)Pconverter;
    else
    {
		pconvertername=(char*)Pconverter;
UTRACEP("%s:convertername=%s\n",UTT,pconvertername);               //~vbB9R~
		rc=ucvext_icugetconverter(Popt,pconvertername,&paddr);
        if (rc)
        	return 4;
		pconverter=(UConverter*)paddr;
    }
    convtype=(*api)(pconverter);
    if (Pptype)
	    *Pptype=(int)convtype;
    if (convtype==UCNV_SBCS)
    	rc=UCEIRC_SBCS;
    else
    if (convtype==UCNV_DBCS)
    	rc=UCEIRC_DBCS;
    else
    if (convtype==UCNV_MBCS)
    	rc=UCEIRC_MBCS;
    else
    if (convtype==UCNV_EBCDIC_STATEFUL)
		rc=UCEIRC_STATEFULEBC;
    else
    if (convtype==UCNV_UNSUPPORTED_CONVERTER)
    	rc=-1;
	if (!(Popt & UCEIO_OPENED)) //UConverter parm is opened ,else parm is convertername//~v6f3I~
//    	ucvext_icuclose(0,(ULONG)pconverter);                      //~v6f3R~//~v6hhR~
    	ucvext_icuclose(0,(ULPTR)pconverter);                      //~v6hhI~
    UTRACEP("%s:type=%x,rc=%d\n",UTT,convtype,rc);                 //~v7d7R~
    return rc;
}//ucvext_icugetconvertertype
//#endif  //W32                                                    //~v5n2R~
//#ifdef W32                                                       //~v5n2R~
//*************************************************************************
//*get substChars(conv err alternative char)                       //~v6f3R~
//*substitution char is set at ucs-->mb                            //~v6f3I~
//*ex,0x1a for iso8859-1                                           //~v6f3I~
//*if subchar1(1byte) is defined as "|2",set it, else set subchar  //~v6f3I~
//*(mb-->ucs: mblen is 1 and subchar1 is specified 0x1a is set, else 0xfffd is set)//~v6f3I~
//*eucjp:0xf4fe,sjis 0xfcfc                                        //~v6f3R~
//*************************************************************************
//int ucvext_icugetsubchars(int Popt,ULONG Pconverter,char *Psubchars,int *Ppoutlen)//~v6hhR~
int ucvext_icugetsubchars(int Popt,ULPTR Pconverter,char *Psubchars,int *Ppoutlen)//~v6hhI~
{
	UConverter *pconverter;
    char *pconvertername,subcharlen;
//    ULONG handle,paddr;                                          //~v6baR~
//    DLHANDLE handle,paddr;                                         //~v6baI~//~v6f3R~
    DLHANDLE paddr;                                                //~v6f3I~
	ICUFUNC_GETSUBCHARS api;
    UErrorCode err=U_ZERO_ERROR;
    char subchars[8];
    int rc;
//***********************
	ICU_INITCHK(8);    //if icuinit not called ,return 4
//    handle=Shiculib;                                             //~v6f3R~
//    rc=uproc_getprocaddr(0,0/*dllname*/,0/*dll version*/,ICUAPINAME_GETSUBCHARS,Sicuapisuffix,&handle,&paddr);//~v6f3R~
//    if (rc)                                                      //~v6f3R~
//        return 4;                                                //~v6f3R~
//    api=(ICUFUNC_GETSUBCHARS)paddr;                              //~v6f3R~
    api=Spfuncgetsubchars;                                         //~v6f3I~
	if (Popt & UCEIO_OPENED) //UConverter parm is opened ,else parm is convertername
		pconverter=(UConverter*)Pconverter;
    else
    {
		pconvertername=(char*)Pconverter;
		rc=ucvext_icugetconverter(Popt,pconvertername,&paddr);
        if (rc)
        	return 4;
		pconverter=(UConverter*)paddr;
    }
    subcharlen=sizeof(subchars);
    (*api)(pconverter,subchars,&subcharlen,&err);
//  *Ppoutlen=(int)subcharlen;                                     //~v6f3R~
	if (U_FAILURE(err))
	{
		UTRACEP("%s:err=%08x=%s\n",UTT,(UINT)err,ucvext_icuuerrname(err));//~vbB9R~
		rc=4;
	}
    else
	{
    	if (subcharlen>*Ppoutlen)                                  //~v6f3I~
//  		subcharlen=*Ppoutlen;                                  //~v6x8R~
    		subcharlen=(UCHAR)(*Ppoutlen);                         //~v6x8I~
        else                                                       //~v6f3I~
			*Ppoutlen=subcharlen;                                 //~v6f3I~//~v6f7R~
    	UmemcpyZ(Psubchars,subchars,subcharlen);
		rc=0;
	}
	if (!(Popt & UCEIO_OPENED))                                    //~v6f3I~
//    	ucvext_icuclose(0,(ULONG)pconverter);                             //~v6f3I~//~v6f7R~//~v6hhR~
    	ucvext_icuclose(0,(ULPTR)pconverter);                      //~v6hhI~
    UTRACEP("%s:icugetsubchar converter=%lx\n",UTT,Pconverter);           //~v6f3R~//~vbB9R~
    UTRACED("icugetsubchar",subchars,subcharlen);                  //~v6f3I~
    return rc;
}//ucvext_icugetsubchars
//#endif  //W32                                                    //~v5n2R~
//#ifdef W32                                                       //~v5n2R~
//*************************************************************************
//*set stbstChars(conv err alternative char)
//*************************************************************************
//int ucvext_icusetsubchars(int Popt,ULONG Pconverter,char *Psubchars,int Plen)//~v6hhR~
int ucvext_icusetsubchars(int Popt,ULPTR Pconverter,char *Psubchars,int Plen)//~v6hhI~
{
	UConverter *pconverter;
    char *pconvertername;
//    ULONG handle,paddr;                                          //~v6baR~
//    DLHANDLE handle,paddr;                                         //~v6baI~//~v6f3R~
    DLHANDLE paddr;                                                //~v6f3I~
	ICUFUNC_SETSUBCHARS api;
    UErrorCode err=U_ZERO_ERROR;
    int rc;
//***********************
	ICU_INITCHK(8);    //if icuinit not called ,return 4
//    handle=Shiculib;                                             //~v6f3R~
//    rc=uproc_getprocaddr(0,0/*dllname*/,0/*dll version*/,ICUAPINAME_SETSUBCHARS,Sicuapisuffix,&handle,&paddr);//~v6f3R~
//    if (rc)                                                      //~v6f3R~
//        return 4;                                                //~v6f3R~
//    api=(ICUFUNC_SETSUBCHARS)paddr;                              //~v6f3R~
    api=Spfuncsetsubchars;                                         //~v6f2I~//~v6f3R~
	if (Popt & UCEIO_OPENED) //UConverter parm is opened ,else parm is convertername
		pconverter=(UConverter*)Pconverter;
    else
    {
		pconvertername=(char*)Pconverter;
		rc=ucvext_icugetconverter(Popt,pconvertername,&paddr);
        if (rc)
        	return 4;
		pconverter=(UConverter*)paddr;
    }
    (*api)(pconverter,Psubchars,(char)Plen,&err);
	if (U_FAILURE(err))
	{
		UTRACEP("%s:err=%08x=%s\n",UTT,(UINT)err,ucvext_icuuerrname(err));//~vbB9R~
		rc=4;
	}
    else
    	rc=0;
    return rc;
}//ucvext_icusetsubchars
//#endif  //W32                                                    //~v5n2R~
//*************************************************************************
//*get dbcs starter of MBCS
//*************************************************************************
//int ucvext_icugetstarter(int Popt,ULONG Pconverter,UCHAR *Pflags)//~v6hhR~
int ucvext_icugetstarter(int Popt,ULPTR Pconverter,UCHAR *Pflags)  //~v6hhI~
{
//#ifdef W32                                                       //~v5n2R~
	UConverter *pconverter;
//    ULONG handle,paddr;                                          //~v6baR~
//  DLHANDLE handle,paddr;                                         //~v6baI~//~v6f3R~
    DLHANDLE paddr;                                                //~v6f3I~
    UBool *pbool;      //int8
	ICUFUNC_GETSTARTER api;
    UErrorCode err=U_ZERO_ERROR;
    char *pconvertername;
//#endif                                                           //~v5n2R~
    int rc=0;                                                      //~v5mTR~
//***********************
//#ifdef W32                                                       //~v5n2R~
//if (IS_ICUMODE())                                                //~v5n1R~//~v66KR~
//if (IS_ICU_CONVERTER(Popt))                                      //~v66KI~//~v6f3R~
  if (IS_ICU_CONVERTER_OR_MBLOCAL(Popt))                           //~v6f3I~
  {                                                                //~v5n2I~
	ICU_INITCHK(8);    //if icuinit not called ,return 4
//    handle=Shiculib;                                             //~v6f3R~
//    rc=uproc_getprocaddr(0,0/*dllname*/,0/*dll version*/,ICUAPINAME_GETSTARTER,Sicuapisuffix,&handle,&paddr);//~v6f3R~
//    if (rc)                                                      //~v6f3R~
//        return 4;                                                //~v6f3R~
//    api=(ICUFUNC_GETSTARTER)paddr;                               //~v6f3R~
    api=Spfuncgetstarter;                                          //~v6f3I~
	if (Popt & UCEIO_OPENED) //UConverter parm is opened ,else parm is convertername
		pconverter=(UConverter*)Pconverter;
    else
    {
		pconvertername=(char*)Pconverter;
		rc=ucvext_icugetconverter(Popt,pconvertername,&paddr);
        if (rc)
        	return 4;
		pconverter=(UConverter*)paddr;
    }
//  pbool=(UBool*)(ULONG)Pflags;                                   //~v6hhR~
    pbool=(UBool*)(ULPTR)Pflags;                                   //~v6hhI~
    (*api)(pconverter,pbool,&err);
//**if converter is not type of which returns starter, returns err=U_ILLEGAL_ARGUMENT_ERROR//~v6f3I~
	if (U_FAILURE(err))
	{
		UTRACEP("%s:err=%08x=%s\n",UTT,(UINT)err,ucvext_icuuerrname(err));//~vbB9R~
		rc=4;
	}
  }                                                                //~v5n2I~
//#else                                                            //~v5n2R~
  else                                                             //~v5n2I~
  {                                                                //~v5n2I~
//  if (ucvext_iconvgetstarter(Popt,Pconverter,Pflags)>1)          //~v5n8R~
    if (ucvext_iconvgetstarter(Popt,Pconverter,Pflags,0)>1)        //~v5n8I~
    	rc=4;                                                      //~v5mTI~
  }                                                                //~v5n2I~
//#endif                                                           //~v5n2R~
    return rc;
}//ucvext_icugetstarter
//*************************************************************************
//*get icu converter
//*rc 4:err, 1:not stateful ebc
//*************************************************************************
//int ucvext_icugetconverter(int Popt,char *Pcharset,ULONG *Ppconverter)//~v5mTR~//~v6hhR~
int ucvext_icugetconverter(int Popt,char *Pcharset,ULPTR *Ppconverter)//~v6hhI~
{
//#ifdef W32                                                       //~v5n2R~
    UErrorCode uerrc=U_ZERO_ERROR;
	ICUFUNC_OPEN apiopen;
	ICUFUNC_SETFALLBACK apisetfallback;                            //~v66rR~
	ICUFUNC_USESFALLBACK apiusesfallback;                          //~v66rI~
	UConverter *pconverter;
    int type;                                                      //~v5mTI~
//#else                                                            //~v5n2R~
//	ULONG       pconverter;                                        //~v5n2R~
//#endif                                                           //~v5n2R~
    char flags[256];
    int rc=0;                                                      //~v5mTR~
//  ULONG sbcsmap;                                                 //~v6hhR~
    ULPTR sbcsmap;                                                 //~v6hhI~
//  UBool usefb;                                                   //~v66rI~//~v6b9R~
    int cvtype;                                                    //~v5n3I~
    char *papiver,*pdllver;                                        //~v6baR~
//***********************
    UTRACEP("%s:opt=%x,charset=%s\n",UTT,Popt,Pcharset);//~v6beI~  //~vbB9R~
	if (Popt & UCEIO_SBCSMAP)          //get conveter parm is sbcs map
    {
    	if (!Pcharset)                 //map
        {
    		if (Popt & UCEIO_MAPISA2E)//ASCII->EBCDIC conversion
            {                                                      //~v7dQI~
//        		*Ppconverter=sbcsmap=(ULONG)Sasc2ebc0;             //~v6hhR~
        		*Ppconverter=sbcsmap=(ULPTR)Sasc2ebc0;             //~v6hhI~
                UTRACED("Sasc2ebc0",Sasc2ebc0,sizeof(Sasc2ebc0));  //~v7dQI~
            }                                                      //~v7dQI~
        	else
            {                                                      //~v7dQI~
//        		*Ppconverter=sbcsmap=(ULONG)Sebc2asc0;             //~v6hhR~
        		*Ppconverter=sbcsmap=(ULPTR)Sebc2asc0;             //~v6hhI~
                UTRACED("Sebc2asc0",Sebc2asc0,sizeof(Sebc2asc0));  //~v7dQI~
            }                                                      //~v7dQI~
        }
        else
//        	sbcsmap=(ULONG)Pcharset;                               //~v6hhR~
        	sbcsmap=(ULPTR)Pcharset;                               //~v6hhI~
    	if (Popt & UCEIO_SAVEMAP) //save EBC converter DBCS
        {
			Sextflag|=SEXTF_SBCSMAP;   //saved sbcs converter is sbcsmap
    		if (Popt & UCEIO_MAPISA2E)//ASCII->EBCDIC conversion
            {                                                      //~v7d9I~
                UTRACEP("%s:set Ssbcsmap_a2e\n",UTT);              //~v7d9I~//~vbB9M~
                UTRACED("Ssbcsmap_a2e SAVEMAP",Ssbcsmap_a2e,256);//~v7d9R~//~vbB9R~//~v7dQR~
            	Ssbcsmap_a2e=sbcsmap;
            }                                                      //~v7d9I~
            else
            {                                                      //~v7d9I~
                UTRACEP("%s:set Ssbcsmap_e2a\n",UTT);              //~v7d9I~//~vbB9M~
                UTRACED("Ssbcsmap_e2a SAVEMAP",Ssbcsmap_e2a,256);//~v7d9R~//~vbB9R~//~v7dQR~
            	Ssbcsmap_e2a=sbcsmap;
            }                                                      //~v7d9I~
        }
   	 	UTRACED("sbcsmap ",sbcsmap,256);
    }
    else
	if (Popt & UCEIO_SBCSMAPC)          //get conveter parm is sbcs map
    {
//      sbcsmap=(ULONG)Pcharset;                                   //~v6hhR~
        sbcsmap=(ULPTR)Pcharset;                                   //~v6hhI~
    	if (Popt & UCEIO_SAVEMAP) //save EBC converter DBCS
        {
			Sextflag|=SEXTF_SBCSMAPC;   //saved sbcs converter is sbcsmap
    		if (Popt & UCEIO_MAPISA2E)//ASCII->EBCDIC conversion
            	Ssbcsmap_a2eC=sbcsmap;
            else
            	Ssbcsmap_e2aC=sbcsmap;
        }
   	 	UTRACEP("%s:Popt=%x\n",UTT,Popt);                          //~vbB9R~
   	 	UTRACED("sbcsmapC ",sbcsmap,256);
    }
    else
	if (Popt & UCEIO_SBCSMAPA2A)          //get conveter parm is sbcs map
    {
//      sbcsmap=(ULONG)Pcharset;                                   //~v6hhR~
        sbcsmap=(ULPTR)Pcharset;                                   //~v6hhI~
    	if (Popt & UCEIO_SAVEMAP) //save EBC converter DBCS
        {
			Sextflag|=SEXTF_SBCSMAPA2A;   //saved sbcs converter is sbcsmap
    		if (Popt & UCEIO_MAPISA2E)//ASCII->EBCDIC conversion
            	Ssbcsmap_a2f=sbcsmap;
            else
            	Ssbcsmap_f2a=sbcsmap;
        }
   	 	UTRACED("sbcsmap A2A",sbcsmap,256);
    }
    else
    {
//#ifdef W32                                                       //~v5n2R~
//    if (IS_ICUMODE())                                            //~v5n1R~//~v66KR~
//    if (IS_ICU_CONVERTER(Popt))                                  //~v66KI~//~v6f3R~
	  if (IS_ICU_CONVERTER_OR_MBLOCAL(Popt))                       //~v6f3I~
      {                                                            //~v5n2I~
		ICU_INITCHK(8);    //if icuinit not called ,return 4
        apiopen=Spfuncopen;
        pconverter=(*apiopen)(Pcharset,&uerrc);      //ucnv_open
        UTRACEP("%s:IS_ICU_CONVERTER_OR_MBLOCAL;ucnv_open charse=%s,pconverter=%p\n",UTT,Pcharset,pconverter);//~vbB9I~//~v7dnR~
//      *Ppconverter=(ULONG)pconverter;                            //~v6hhR~
        *Ppconverter=(ULPTR)pconverter;                            //~v6hhI~
        if (!pconverter)
        {
            pdllver=Spcfg->UCECdllsuffix;                          //~v6baI~
            papiver=Spcfg->UCECapisuffix;                          //~v6baR~
          if (!strcmp(Pcharset,"?"))                               //~v6baI~
	        ucvext_icuenumcvname(0,pdllver,papiver);               //~v6baI~
          else                                                     //~v6baI~
          {                                                        //~v6baI~
//          uerrmsg("Cannot find ICU converter for %s,errc=%d",0,  //~v6ByR~
//                  Pcharset,(int)uerrc);                          //~v6ByI~
            uerrmsg("ICU converter open failed for \"%s\"(%s),chk %s parameter or environment variable",//~v6ByR~
#ifdef LNX                                                         //~v7deI~
            0,                                                     //~v7deI~
#else                                                              //~v7deI~
                    "ICU ƒRƒ“ƒo[ƒ^ \"%s\" ƒI[ƒvƒ“Ž¸”s(%s),%s ƒpƒ‰ƒ[ƒ^‚È‚¢‚µŠÂ‹«•Ï”‚ðŠm”F",//~v6ByR~
#endif                                                             //~v7deI~
                    Pcharset,ucvext_icuuerrname(uerrc),UCVEXTCFGPARM_ICUDATA);//~v6ByR~
            if (Popt & EBC2ASC_WINCPLIST)	//from xcv             //~v6baI~
                ucvext_icuenumcvname(0,pdllver,papiver);           //~v6baI~
          }                                                        //~v6baI~
            rc=4;
        }
        else                                                       //~v66rI~
        {                                                          //~v66rI~
        apiusesfallback=Spfuncusesfallback;                        //~v66rI~
        /*usefb=*/(*apiusesfallback)(pconverter);      //void:set fallback true//~v66rI~//~v6b9R~
//      UTRACEP("icu fallback mode usage=%d\n",usefb);             //~v66rI~//~v6b9R~
        apisetfallback=Spfuncsetfallback;                          //~v66rI~
		if (Sextflag & SEXTF_ICUFB)                                //~v66rI~
        {                                                          //~v66rI~
        	(*apisetfallback)(pconverter,TRUE);      //void:set fallback true//~v66rR~
            UTRACEP("%s:icu fallback mode TRUE cv=%p\n",UTT,pconverter);  //~v66rR~//~vbB9R~
        }                                                          //~v66rI~
//        else                                                     //~v66rR~
//        {                                                        //~v66rR~
//            (*apisetfallback)(pconverter,FALSE);      //void:set fallback true//~v66rR~
//            UTRACEP("icu fallback mode FALSE cv=%p\n",pconverter);//~v66rR~
//        }                                                        //~v66rR~
        /*usefb=*/(*apiusesfallback)(pconverter);      //void:set fallback true//~v66rI~//~v6b9R~
//      UTRACEP("icu fallback mode after usage=%d\n",usefb);       //~v66rI~//~v6b9R~
        }                                                          //~v66rI~
      }                                                            //~v5n2I~
//#else                                                            //~v5n2R~
      else                                                         //~v5n2I~
      {                                                            //~v5n2I~
//  	rc=ucvext_iconvgetconverter(Popt,Pcharset,Ppconverter);    //~v5n8R~
    	rc=ucvext_iconvgetconverter(0,Pcharset,Ppconverter);       //~v5n8I~
        pconverter=(UConverter*)(*Ppconverter);                    //~v5n2R~
      }                                                            //~v5n2I~
//#endif                                                           //~v5n2R~
    	if (!rc && Popt & UCEIO_SAVECV) //save EBC converter DBCS
        {
    		if (Popt & UCEIO_DBCSCV) //save EBC converter DBCS
            {                                                      //~v66NI~
    			SpebcSBCSconverter=                                //~v66NI~
    			SpebcDBCSconverter=*Ppconverter;
            }                                                      //~v66NI~
            else
    		if (Popt & UCEIO_SBCSCV) //save EBC converter sBCS
    			SpebcSBCSconverter=*Ppconverter;
            else
    		if (Popt & UCEIO_LOCALCV) //save local
            {
    			Splocalconverter=*Ppconverter;
//#ifdef W32                                                       //~v5n2R~
//  			if (ucvext_icugetconvertertype(Popt|UCEIO_OPENED,(ULONG)pconverter,0)==UCEIRC_MBCS)//~v5n3R~//~v66KR~
//  			if (IS_ICUMODE())                                  //~v5n3R~//~v66KR~
// 			  if (IS_ICULOCALMODE())                               //~v66KR~//~v6f3R~
   			  if (IS_ICULOCALMODE_OR_MBLOCAL())                    //~v6f3I~
//  				cvtype=ucvext_icugetconvertertype(Popt|UCEIO_OPENED,(ULONG)pconverter,0);//~v5n3I~//~v66KR~//~v6fdR~
//    				cvtype=ucvext_icugetconvertertype(Popt|UCEIO_OPENED|UCEIO_OPENICU,(ULONG)pconverter,0);//~v6fdI~//~v6hhR~
    				cvtype=ucvext_icugetconvertertype(Popt|UCEIO_OPENED|UCEIO_OPENICU,(ULPTR)pconverter,0);//~v6hhI~
              else                                               //~v5n3I~//~v66KR~
#ifdef W32                                                         //~v66KI~
//                	cvtype=ucvext_icugetconvertertype(Popt,(ULONG)pconverter,0);//~v66KI~//~v6hhR~
                	cvtype=ucvext_icugetconvertertype(Popt,(ULPTR)pconverter,0);//~v6hhI~
#else                                                              //~v66KI~
                	cvtype=ucvext_icugetconvertertype(Popt,(ULONG)Pcharset,0);//~v5n3R~
#endif                                                             //~v66KI~
                if (cvtype==UCEIRC_MBCS)                           //~v5n3R~
                {
//#endif                                                           //~v5n2R~
//					rc=ucvext_icugetstarter(Popt|UCEIO_OPENED,(ULONG)pconverter,flags);//~v6hhR~
					rc=ucvext_icugetstarter(Popt|UCEIO_OPENED,(ULPTR)pconverter,flags);//~v6hhI~
                    if (!rc)
                    {
                    	memcpy(Sstartermap,flags,sizeof(Sstartermap));
						Sextflag|=SEXTF_DBCSSTART;//dbcs start byte saved for the converter
                        UTRACED("mapinit starter",Sstartermap,256);
                    }
//#ifdef W32                                                       //~v5n2R~
                }
//#endif                                                           //~v5n2R~
            }
        }
//#ifdef W32                                                       //~v5n2R~
    	if (!rc && Popt & UCEIO_CHKSTATEFULEBC) //save EBC converter DBCS
        {
//			if (ucvext_icugetconvertertype(Popt|UCEIO_OPENED,(ULONG)pconverter,&type)!=UCEIRC_STATEFULEBC)//~v5n2R~
//			if (IS_ICUMODE()                                       //~v5n1R~//~v66KR~
			if (IS_ICU_CONVERTER(Popt)                             //~v66KR~
// 			&&  (ucvext_icugetconvertertype(Popt|UCEIO_OPENED,(ULONG)pconverter,&type)!=UCEIRC_STATEFULEBC)//~v5n2I~//~v6hhR~
  			&&  (ucvext_icugetconvertertype(Popt|UCEIO_OPENED,(ULPTR)pconverter,&type)!=UCEIRC_STATEFULEBC)//~v6hhI~
            )                                                      //~v5n2I~
            {
			  if (!(Popt & UCEIO_CONVERTERCFG)) //mapinit parm:cfg is created by getConverterCfg//~v6M5I~
	            uerrmsg("Warning:%s is not Stateful EBCDIC",
#ifdef LNX                                                         //~v7deI~
                        0,                                         //~v7deI~
#else                                                              //~v7deI~
                		"Œx:%s ‚Í DBCS‘Î‰ž‚Å‚Í‚ ‚è‚Ü‚¹‚ñ",
#endif                                                             //~v7deI~
                    		Pcharset);
            	rc=1;
            }
        }
//#endif                                                           //~v5n2R~
   	 	UTRACEP("%s:rc=%d, name=%s,converter=%p\n",UTT,rc,Pcharset,*Ppconverter);//~v6baR~//~vbB9R~//~v7dFR~
    }
   	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v7dnI~
    return rc;
}//ucvext_icugetconverter
//*************************************************************************
//*select converter
//* ebc string to mb string
//*************************************************************************
//int ucvext_getparmconverter(int Popt,ULONG *Pconverters,ULONG *Pcvdbcs,ULONG *Pcvsbcs,ULONG *Pmapsbcs,ULONG *Pmapsbcsc,int *Ppopt)//~v6hhR~
int ucvext_getparmconverter(int Popt,ULPTR *Pconverters,ULPTR *Pcvdbcs,ULPTR *Pcvsbcs,ULPTR *Pmapsbcs,ULPTR *Pmapsbcsc,int *Ppopt)//~v6hhI~
{
//	ULONG cvdbcs,cvsbcs,mapsbcs,mapsbcsc;                          //~v6hhR~
	ULPTR cvdbcs,cvsbcs,mapsbcs,mapsbcsc;                          //~v6hhI~
    int opt;
//************************
    UTRACEP("%s:opt=0x%04x,Sextflag=0x%08x\n",UTT,Popt,Sextflag);  //~vbB9I~
    opt=Popt;
    if (Pconverters)
    {
    	cvdbcs=Pconverters[0];
    	cvsbcs=Pconverters[1];
    	mapsbcs=Pconverters[2];
    	mapsbcsc=Pconverters[3];
        UTRACEP("%s:Pconverters!=null mapsbcs=%p\n",UTT,mapsbcs);  //~v7dQI~
    }
    else
    	cvdbcs=cvsbcs=mapsbcs=mapsbcsc=0;
    if (!cvdbcs)
    	cvdbcs=SpebcDBCSconverter;	//previously set by getconverter with save option
    if (!cvsbcs)
	    cvsbcs=SpebcSBCSconverter;
    if (!mapsbcs)                 //full map
    {
        if ((Sextflag & SEXTF_SBCSMAP)||(Popt & EBC2ASC_SBCSMAP) )//use sbcsmap
        {
            if (opt & EBC2ASC_A2E)
            {                                                      //~v7dQI~
                mapsbcs=Ssbcsmap_a2e;
				UTRACED("Ssbcsmap_a2e",Ssbcsmap_a2e,256);              //~vbB9I~//~v7dQI~
            }                                                      //~v7dQI~
            else
            {                                                      //~v7dQI~
                mapsbcs=Ssbcsmap_e2a;
				UTRACED("Ssbcsmap_e2a",Ssbcsmap_e2a,256);              //~vbB9I~//~v7dQI~
            }                                                      //~v7dQI~
            opt|=EBC2ASC_SBCSMAP;
            UTRACEP("%s:Pconverters=null,mapsbcs=%p\n",UTT,mapsbcs);                //~v7d9I~//~v7dQR~
        }
        else
        if ((Sextflag & SEXTF_SBCSMAPA2A)||(Popt & EBC2ASC_SBCSMAPA2A)) //complementary map
        {
            if (opt & EBC2ASC_A2E)
                mapsbcs=Ssbcsmap_a2f;
            else
                mapsbcs=Ssbcsmap_f2a;
			UTRACED("Ssbcsmap_a2f",Ssbcsmap_a2f,256);              //~v7dsI~
			UTRACED("Ssbcsmap_f2a",Ssbcsmap_f2a,256);              //~v7dsI~
            opt|=EBC2ASC_SBCSMAPA2A;
        }
        else
        {
		    mapsbcs=Splocalconverter;
            if (mapsbcs)
	            opt|=EBC2ASC_LOCALCV;	//local converter option
	        UTRACEP("%s:LOCALCV opt=%08x,Splocalconverter=%p\n",UTT,opt,mapsbcs);//~v7dMI~
        }
    }
    if (!mapsbcsc)	//complementary map
    {
        if ((Sextflag & SEXTF_SBCSMAPC)||(Popt & EBC2ASC_SBCSMAPC)) //complementary map
        {
            if (opt & EBC2ASC_A2E)
                mapsbcsc=Ssbcsmap_a2eC;
            else
                mapsbcsc=Ssbcsmap_e2aC;
            opt|=EBC2ASC_SBCSMAPC;
        }
    }
    *Ppopt=opt;
    *Pcvdbcs=cvdbcs;
    *Pcvsbcs=cvsbcs;
    *Pmapsbcs=mapsbcs;
    *Pmapsbcsc=mapsbcsc;
//UTRACEP("getparmconverter opt=%x,cvdbcs=%lx,cvsbcs=%lx,mapsbcs=%lx,mapsbcsc=%lx\n",opt,cvdbcs,cvsbcs,mapsbcs,mapsbcsc);//~v6baR~//~v6hhR~
UTRACEP("%s:opt=%x,cvdbcs=%p,cvsbcs=%p,mapsbcs=%p,mapsbcsc=%p\n",UTT,opt,cvdbcs,cvsbcs,mapsbcs,mapsbcsc);//~v6hhI~//~vbB9R~
    return 0;
}//ucvext_getparmconverter
//*************************************************************************
//*select converter
//* ebc string to mb string
//*************************************************************************
//int ucvext_openparmconverter(int Popt,ULONG *Pconverters,ULONG *Poutconverters,int *Ppopt)//~v6hhR~
int ucvext_openparmconverter(int Popt,ULPTR *Pconverters,ULPTR *Poutconverters,int *Ppopt)//~v6hhI~
{
//	ULONG cvdbcs,cvsbcs,converter,mapsbcs,mapcsbcs;                //~v6hhR~
	ULPTR cvdbcs,cvsbcs,converter,mapsbcs,mapcsbcs;                //~v6hhI~
    int rc=0,opt;
//************************
	UTRACEP("%s:opt=%08x,Pconverters%p\n",UTT,Popt,Pconverters);   //~v7dnI~
	opt=Popt;
    if (Pconverters)
    {
    	cvdbcs=Pconverters[0];
    	cvsbcs=Pconverters[1];
    	mapsbcs=Pconverters[2];
    	mapcsbcs=Pconverters[3];
    }
    else
    	cvdbcs=cvsbcs=mapsbcs=mapcsbcs=0;
//  if (cvdbcs && !(Popt & EBC2ASC_OPENEDCV))                      //~v7dFR~
    if (cvdbcs)                                                    //~v7dFI~
    {
		rc=ucvext_icugetconverter(0,(UCHAR*)cvdbcs,&converter);
        if (!rc)
        	cvdbcs=converter;
    }
//  if (cvsbcs && !(Popt & EBC2ASC_OPENEDCV))                      //~v7dFR~
    if (cvsbcs)                                                    //~v7dFI~
    {
		rc+=ucvext_icugetconverter(0,(UCHAR*)cvsbcs,&converter);
        if (!rc)
        	cvsbcs=converter;
    }
    Poutconverters[0]=cvdbcs;
    Poutconverters[1]=cvsbcs;
    Poutconverters[2]=mapsbcs;
    Poutconverters[3]=mapcsbcs;
    *Ppopt=opt;
    return rc;
}//ucvext_openparmconverter
//*************************************                            //~v5mVI~
//*get ucvebc option from configparm                               //~v5mVI~
//*************************************                            //~v5mVI~
int ucvext_getcvoption(int Popt,PUCVEXTCFG Pcfg,int *Ppopt)        //~v5mVI~
{                                                                  //~v5mVI~
    int flg,opt;                                                   //~v5mVI~
//*******************************                                  //~v5mVI~
	if (!Pcfg)                                                     //~v5mVI~
    	return 0;                                                  //~v5mVI~
    flg=Pcfg->UCECflag;                                            //~v5mVR~
//  int flg2=Pcfg->UCECflag2;                                          //~v7d5I~//~v7d6R~//+v7dSR~
    opt=*Ppopt;                                                    //~v5mVI~
UTRACEP("%s Popt=0x%04x,old *Ppopt=%x,flag=%08x,flag2=0x%04x\n",UTT,Popt,opt,flg,Pcfg->UCECflag2);            //~v5mVI~//~v7d7R~//~vbB9R~//+v7dSR~
	if (!(Popt & UCEGCOO_IGNIBMNEC))    //set EBC2ASC_DBCS etc     //~v5mWI~
    {                                                              //~v5mWI~
        if (flg & UCECF_IBM)                                       //~v5mWR~
        {                                                          //~v5mWR~
            opt|= EBC2ASC_IBM ;             //dbcs map to ibm area //~v5mWR~
            opt&=~EBC2ASC_NEC ;             //dbcs map to ibm area //~v5mWR~
        }                                                          //~v5mWR~
        if (flg & UCECF_NEC)                                       //~v5mWR~
        {                                                          //~v5mWR~
            opt&=~EBC2ASC_IBM ;             //dbcs map to ibm area //~v5mWR~
            opt|= EBC2ASC_NEC ;             //dbcs map to ibm area //~v5mWR~
        }                                                          //~v5mWR~
    }                                                              //~v5mWI~
	if (!(Popt & UCEGCOO_IGNJIS7883))    //set EBC2ASC_DBCS etc    //~v5mWI~
    {                                                              //~v5mWI~
        if (flg & UCECF_JIS78)                                     //~v5mWR~
        {                                                          //~v5mWR~
            opt&=~EBC2ASC_NEW ;             //dbcs map to ibm area //~v5mWR~
            opt|= EBC2ASC_OLD ;             //dbcs map to ibm area //~v5mWR~
        }                                                          //~v5mWR~
        if (flg & UCECF_JIS83)                                     //~v5mWR~
        {                                                          //~v5mWR~
            opt|= EBC2ASC_NEW ;             //dbcs map to ibm area //~v5mWR~
            opt&=~EBC2ASC_OLD ;             //dbcs map to ibm area //~v5mWR~
        }                                                          //~v5mWR~
    }                                                              //~v5mWI~
	if (!(Popt & UCEGCOO_IGNSOSI))    //set EBC2ASC_DBCS etc       //~v5mWI~
    {                                                              //~v5mWI~
        if (opt & EBC2ASC_A2E)          //ascii-->ebc              //~v5mWR~
        {                                                          //~v5mWR~
            if (flg & UCECF_SOSISHIFT)                             //~v5mWR~
            {                                                      //~v5mWR~
                opt|= EBC2ASC_SOSISHIFT;      //override boundary space(a2e), del from follwing if inserted keeping word boundary space//~v5mWR~
                opt&=~(EBC2ASC_SOSI|EBC2ASC_SOSIOS);               //~v5mWR~
            }                                                      //~v5mWR~
            if (flg & UCECF_SOSIREP)                               //~v5mWR~
            {                                                      //~v5mWR~
                opt|= EBC2ASC_SOSIOS;         //override boundary space(a2e), insert sosi if no space//~v5mWR~
                opt&=~(EBC2ASC_SOSI|EBC2ASC_SOSISHIFT);            //~v5mWR~
            }                                                      //~v5mWR~
            if (flg & UCECF_SOSIINS)                               //~v5mWR~
            {                                                      //~v5mWR~
                opt|= EBC2ASC_SOSI;          //default;isrt(a2e),rep by space(e2a)//~v5mWR~
                opt&=~(EBC2ASC_SOSIOS|EBC2ASC_SOSISHIFT);          //~v5mWR~
            }                                                      //~v5mWR~
        }                                                          //~v5mWR~
        else                                                       //~v5mWR~
        {                                                          //~v5mWR~
            if (flg & UCECF_SOSIDEL)                               //~v5mWR~
            {                                                      //~v5mWR~
                opt|= EBC2ASC_SOSID;            //del sosi(e2a/a2e)//~v5mWR~
                opt&=~EBC2ASC_SOSI;                                //~v5mWR~
            }                                                      //~v5mWR~
            if (flg & UCECF_SOSIREPSP)                             //~v5mWR~
            {                                                      //~v5mWR~
                opt|= EBC2ASC_SOSI;             //default;isrt(a2e),rep by space(e2a)//~v5mWR~
                opt&=~EBC2ASC_SOSID;                               //~v5mWR~
            }                                                      //~v5mWR~
        }                                                          //~v5mWR~
    }                                                              //~v5mWI~
	if (Popt & UCEGCOO_CHKDBCS)    //set EBC2ASC_DBCS etc          //~v5mWI~
    {                                                              //~v5mWI~
                                                                   //~v660I~
	    if (UCECF_ISAVAIL_A2A(Pcfg))                               //~v5mWI~
        {                                                          //~v5n1I~
            opt|=EBC2ASC_SBCSMAPA2A;                               //~v5mWI~
            opt&=~EBC2ASC_DBCS;                                    //~v5n1I~
        }                                                          //~v5n1I~
        else                                                       //~v5mWI~
      	if (UCECF_ISAVAIL_DBCSCV(Pcfg))                            //~v5mWI~
        {                                                          //~v66xI~
	      if (!(Popt & UCEGCOO_FORCESBCS))    //set EBC2ASC_DBCS etc//~v66xI~
            opt|=EBC2ASC_DBCS;                                     //~v5mWI~
        }                                                          //~v66xI~
        else                                                       //~v5mYI~
            opt&=~EBC2ASC_DBCS;                                    //~v5mYI~
    }                                                              //~v5mWI~
#ifdef UTF8EBCD                                                    //~v660I~
	if (Popt & UCEGCOO_CTL)    //set EBC2ASC_DBCS etc              //~v660I~
		if (!(flg & UCECF_ANK))   //no ANK option                  //~v660R~
    		opt|=EBC2ASC_CTL;                                      //~v660R~
	if (Popt & UCEGCOO_FORCEANK)    //set EBC2ASC_DBCS etc         //~v66xI~
    	opt&=~EBC2ASC_CTL;                                         //~v66xR~
//    if (!(flg & UCECF_USE_CONVERTER)    //converter=0              //~vbB9I~//~vbBsR~
//    &&   flg2 & UCECF2_CP931)           //SJISOPT:LATIN            //~vbB9I~//~vbBsR~
//    {                                                              //~vbB9I~//~vbBsR~
////      Gucvebc_stat|=UCVEBCS_SJISLATIN;    //     0x2000 //converter=0 and "sjisopt LATIN"//~vbB9I~//~v7dmR~//~vbBsR~
////      opt|=EBC2ASC_SBCSMAP037;                                   //~v7dmI~//~v7duR~//~vbBsR~
//        UIUIBITON(opt,EBC2ASC_SBCSMAP037);                         //~v7duI~//~vbBsR~
//        opt|=EBC2ASC_CP931;                                        //~v7duI~//~vbBsR~
//        UTRACEP("%s:set ebcstat:SJISLatin by converter=0 and flag2 Gucvebc_stat=0x%08x\n",UTT,Gucvebc_stat);//~vbB9R~//~vbBsR~
//    }                                                              //~vbB9I~//~vbBsR~
//    else                                                           //~vbB9I~//~vbBsR~
    if ((flg & UCECF_SBCSDEF) 	//converter=0                      //~v7dmR~
//    ||  (flg2 & UCECF2_CP037)           //SJISOPT:LATIN            //~v7dmI~//~v7dnR~
    )                                                              //~v7dmI~
    {                                                              //~v7dmI~
//	    opt|=EBC2ASC_SBCSMAP037;                                   //~v7dmI~//~v7duR~
  	    UIUIBITON(opt,EBC2ASC_SBCSMAP037);                         //~v7duI~
        UTRACEP("%s:SBCSMAP037 by SBCSDEF or SBCS CP037\n",UTT);   //~v7dmI~
    }                                                              //~v7dmI~
    else                                                           //~v7dmI~
	if (!(Popt & UCEGCOO_IGNCP290))    //set EBC2ASC_DBCS etc            //~v660I~//~v66hR~
    {
//        if (flg2 & UCECF2_BASE)      //use Japanese Katakan Ext    //~v7d5R~//~v7dmR~
////          opt|=EBC2ASC_BASE;                                     //~v7d5R~//~v7dmR~
//            opt=(int)((UINT)opt|EBC2ASC_BASE);                   //~v7dmR~
//        else                                                       //~v7d5I~//~v7dmR~
        if (flg & UCECF_CP930)      //use Japanese Katakan Ext     //~v660I~
        {                                                          //~vbB9I~
    		opt|=EBC2ASC_CP290;                                    //~v660I~
            UTRACEP("%s:set EBC2ASC_CP290 by UCECF_CP930\n",UTT);  //~vbB9I~
        }                                                          //~vbB9I~
    }
#ifdef LNX                                                         //~v66hR~
	if (!(Popt & UCEGCOO_IGNEUC))    //do not set euc,for cvebc3   //~v66hI~
    if (!(flg & UCECF_USE_CONVERTER))                              //~v66hI~
	    if (UDBCSCHK_ISEUCJ())                                     //~v66hR~
	        opt|=EBC2ASC_EUC; //getcvoption is called for B2M/M2B only//~v66hR~
#endif                                                             //~v66hR~
#endif                                                             //~v660I~
	*Ppopt=opt;                                                    //~v5mVI~
UTRACEP("%s:ret opt=%x\n",UTT,opt);                    //~v5mVI~   //~vbB9R~
    return 0;                                                      //~v5mVI~
}//ucvext_getcvoption                                              //~v5mVI~
#ifdef UTF8EBCD                                                    //~v660I~
//***************************************************************  //~v6bdI~
//*default internal map by cp37                                    //~v6bdI~
//***************************************************************  //~v6bdI~
void set_internal_CP037(int Popt,PUCVEXTCFG Ppcfg)                 //~v6b3I~
{                                                                  //~v6b3I~
//  ULONG addr;                                                    //~v6b3I~//~v6hhR~
    ULPTR addr;                                                    //~v6hhI~
//  UCHAR *pc,asc;                                                 //~v6b3I~//~vbB9R~
//  int ii;                                                        //~v6b3I~//~vbB9R~
    int keepflag;                                                  //~v6hzI~
//***********************                                          //~v6b3I~
UTRACEP("%s:entry flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);                                    //~v6bdI~//~v7d8R~
//    for (ii=0,pc=Sebc2asc037;ii<256;ii++,pc++)                     //~v6b3I~//~vbB9R~
//    {                                                              //~v6b3I~//~vbB9R~
//        asc=*pc;                                                   //~v6b3I~//~vbB9R~
//        if (asc)                                                   //~v6b3I~//~vbB9R~
////          Sasc2ebc037[asc]=ii;    //reverse map                  //~v6x8R~//~vbB9R~
//            Sasc2ebc037[asc]=(UCHAR)ii;    //reverse map           //~v6x8I~//~vbB9R~
//    }                                                              //~v6b3I~//~vbB9R~
    Popt|=UCEIO_SAVEMAP; 	//update also Ssbcsmap_a2e,Ssbcsmap_e2a//~v6beI~
    ucvext_icugetconverter(Popt|UCEIO_SBCSMAP,Sebc2asc037,&addr);//set Sebc2asc as sbcs mapping//~v6b3I~
    ucvext_icugetconverter(Popt|UCEIO_SBCSMAP|UCEIO_MAPISA2E,Sasc2ebc037,&addr);//~v6b3I~
//  keepflag=Ppcfg->UCECflag & (UCECF_USE_ICU);//for addtional converter for b2b etc//~v6hzR~//~v7d3R~
//  keepflag=Ppcfg->UCECflag & (UCECF_USE_ICU|UCECF_OPENERR);//for addtional converter for b2b etc//~v7d3I~//~v7dsR~
    int keepf=UCECF_USE_ICU|UCECF_OPENERR	//for addtional converter for b2b etc//~v7dsI~
             |UCECF_E2A|UCECF_A2E;                                 //~v7dsI~
    keepflag=Ppcfg->UCECflag & keepf;                              //~v7dsI~
    if (Ppcfg->UCECflag & UCECF_SBCSDEF)                           //~v7dcI~
    {                                                              //~v7dcI~
    	if (Ppcfg->UCECflag & (UCECF_CP930|UCECF_CP939))	//japanese+SBCSDEF(cp037)//~v7dcI~
			Ppcfg->UCECflag2|=UCECF2_CP931;     //Japanese latin ext//~v7dcI~
    }                                                              //~v7dcI~
#ifdef AAA                                                         //~v7dhI~//~v7diM~
  if (Ppcfg->UCECflag2 & UCECF2_CP931)     //Japanese latin ext    //~vbB9R~
  {                                                                //~vbB9I~
    keepflag=Ppcfg->UCECflag;                                      //~v7dcI~
	Ppcfg->UCECflag|=UCECF_SBCSMAP                                 //~vbB9R~
					|UCECF_SBCSDEF                               //~v7d8R~//~vbB9R~
                   |UCECF_SBCSCV                                   //~v7dcR~
                   |UCECF_USE_CONVERTER //if on set EBC2ASC_EXT on, then refer map tbl at icuebc2mb1/icumb2ebc1//~v7dcR~//~v7dhR~
                    |keepflag;                                     //~vbB9I~
  }                                                                //~vbB9I~
  else                                                             //~vbB9I~
#endif                                                             //~v7dhI~//~v7diM~
  {                                                                //~vbB9I~
    Ppcfg->UCECflag=UCECF_SBCSCV                                   //~v6b3I~
//                 |UCECF_USE_CONVERTER //map converter             //~v6b3I~//~v7diR~
//*                ucvebc2ucs1sbcsJ supports LATIN table           //~v7diI~
                   |UCECF_SBCSMAP                                  //~v6b3I~
                   |UCECF_SBCSDEF                                  //~v6b3I~
                   |keepflag;                                      //~v6hzI~
                    ;                                              //~v6b3I~
  }                                                                //~vbB9I~
	UTRACEP("%s:exit flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7d8I~
	UTRACED("Ppcfg",Ppcfg,UCVEXTCFGSZ);                            //~v7d8I~
}//set_internal_CP037                                              //~v6b3I~
//*************************************************************************//~vbB6I~
void ucvext_cmdlineoption(int Popt,PUCVEXTCFG Ppcfg)               //~vbB6I~
{                                                                  //~vbB6I~
    UTRACEP("%s:opt=0x%04x,UCECflag=0x%08x,Gucvebc_stat=0x%08x\n",UTT,Popt,Ppcfg->UCECflag,Gucvebc_stat);//~vbB6R~
	if (Gucvebc_stat & UCVEBCS_CLO_CP930)                          //~vbB6R~
    {                                                              //~vbB6I~
    	Ppcfg->UCECflag|=UCECF_CP930;     //Japanese katakana ext  //~vbB6I~
    	Ppcfg->UCECflag&=~UCECF_CP939;     //Japanese English ext  //~vbB6I~
    	Ppcfg->UCECflag2&=~UCECF2_CP931;     //Japanese katakana ext//~vbB9R~
//        Ppcfg->UCECflag2&=~UCECF2_CP037;     //Japanese katakana ext//~v7dmI~//~v7dnR~
		Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;                      //~vbBtI~
    }                                                              //~vbB6I~
    else                                                           //~vbB6I~
	if (Gucvebc_stat & UCVEBCS_CLO_CP939)                          //~vbB6R~
    {                                                              //~vbB6I~
    	Ppcfg->UCECflag|=UCECF_CP939;     //Japanese katakana ext  //~vbB6I~
    	Ppcfg->UCECflag&=~UCECF_CP930;     //Japanese English ext  //~vbB6I~
    	Ppcfg->UCECflag2&=~UCECF2_CP931;     //Japanese katakana ext//~vbB9R~
//        Ppcfg->UCECflag2&=~UCECF2_CP037;     //Japanese katakana ext//~v7dmI~//~v7dnR~
		Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;                      //~vbBtI~
    }                                                              //~vbB6I~
    else                                                           //~vbB6I~
	if (Gucvebc_stat & UCVEBCS_CLO_CP931)                          //~vbB9R~
    {                                                              //~vbB9R~
    	Ppcfg->UCECflag2|=UCECF2_CP931;     //Japanese katakana ext//~vbB9R~
    	Ppcfg->UCECflag&=~(UCECF_CP930|UCECF_CP939);     //Japanese English ext//~vbB9R~
//        Ppcfg->UCECflag2|=UCECF2_CP037;     //Japanese katakana ext//~v7dmI~//~v7dnR~
		Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;                      //~vbBtI~
        set_internal_CP037(0,Ppcfg);                               //~vbB9I~
    }                                                              //~vbB9R~
    else                                                           //~vbB9R~
	if (Gucvebc_stat & UCVEBCS_CLO_CP037)                          //~vbB6R~
    {                                                              //~vbB6I~
//		Gucvebc_stat|=UCVEBCS_SBCSLATIN;	//use tbl of cp037     //~v7diI~//~v7dmR~
    	Ppcfg->UCECflag&=~(UCECF_CP930|UCECF_CP939);     //Japanese katakana ext //~vbB6I~//~vbB9R~
    	Ppcfg->UCECflag2&=~UCECF2_CP931;     //Japanese katakana ext//~vbB9R~
//        Ppcfg->UCECflag2|=UCECF2_CP037;     //Japanese katakana ext//~v7dmI~//~v7dnR~
		Ppcfg->UCECflag2&=~UCECF2_CP037_EURO;                      //~vbBtI~
        set_internal_CP037(0,Ppcfg);                               //~vbB6I~
    }                                                              //~vbB6I~
    else                                                           //~vbBtI~
	if (Gucvebc_stat & UCVEBCS_CLO_CP037Euro)                      //~vbBtI~
    {                                                              //~vbBtI~
    	Ppcfg->UCECflag&=~(UCECF_CP930|UCECF_CP939);     //Japanese katakana ext//~vbBtI~
    	Ppcfg->UCECflag2&=~UCECF2_CP931;     //Japanese katakana ext//~vbBtI~
		Ppcfg->UCECflag2|=UCECF2_CP037_EURO;                       //~vbBtI~
        set_internal_CP037(0,Ppcfg);                               //~vbBtI~
    }                                                              //~vbBtI~
    UTRACEP("%s:return UCECflag=0x%08x,Gucvebc_stat=0x%08x\n",UTT,Ppcfg->UCECflag,Gucvebc_stat);//~vbB6R~
}                                                                  //~vbB6I~
//*************************************************************************//~v660I~
//*default map init when map file missing or converter=0            //~v660I~//~v6beR~//~v7d7R~
//*************************************************************************//~v660I~
int ucvext_mapinitsetdefault(int Popt,PUCVEXTCFG Ppcfg)            //~v660R~
{                                                                  //~v660I~
//  ULONG addr;                                                    //~v660I~//~v6hhR~
    ULPTR addr;                                                    //~v6hhI~
//#ifdef BBB                                                         //~v66qM~//~v6b3R~
//    UCHAR *pc,asc;                                                 //~v660I~//~v6b3R~
//    int ii;                                                        //~v660I~//~v6b3R~
//#else                                                              //~v66qI~//~v6b3R~
#ifdef AAA                                                         //~v6fdI~
    UCHAR *psbcscharset;                                           //~v66qR~
#endif                                                             //~v6fdI~
    UCHAR *plocalcharset;                                          //~v66wI~
    int rc2;                                                       //~v66qI~
//#endif                                                             //~v66qI~//~v6b3R~
	int flag;                                                      //~v69hI~
//***********************                                          //~v660I~
    UTRACEP("%s:opt=0x%04x,UCECflag=0x%08x,flag2=0x%04x\n",UTT,Popt,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7d2R~//~vbB9R~
	if (UDBCSCHK_ISDBCSJ()	//japanese                             //~v660R~
//  &&  (Ppcfg->UCECflag & UCECF_OPENERR)	//cfg file not found   //~v68cI~//~v68iR~
    &&  !(Guerropt & GBL_UERR_FORCEENG)	//not test english mode by /N9 ex cmdline parm//~v660I~
    )                                                              //~v660I~
    {                                                              //~v660I~
//    if (Ppcfg->UCECflag & UCECF_OPENERR)	//cfg file not found   //~v68cR~
      if (Ppcfg->UCECflag & UCECF_OPENERR)	//cfg file not found   //~v69hI~
      {                                                            //~vbB6I~
    	Ppcfg->UCECflag=UCECF_DBCSCV                               //~v660R~
                       |UCECF_OPENERR	//cfg file not found       //~v69xI~
        			   |UCECF_JIS83                                //~v660R~
        			   |UCECF_IBM                                  //~v660R~
//      			   |UCECF_SOSISHIFT                            //~v660R~//~v69hR~
        			   |UCECF_SOSIINS|UCECF_SOSIREPSP       //a2e ins,e2a repsp//~v69hR~
    			       |UCECF_CP930     //Japanese katakana ext    //~v660R~
                        ;                                          //~v660I~
        if (Gucvebc_stat & UCVEBCS_CMDLINEOPTION) //0x0100 //xe cmdline option cp930/cp939/cp037 specified//~vbB6R~
        	ucvext_cmdlineoption(0,Ppcfg);                         //~vbB6I~
      }                                                            //~vbB6I~
//    else             //converter=0,accept other option from cfg  //~v68cR~
//  	Ppcfg->UCECflag|=UCECF_DBCSCV                              //~v68cR~
//      else                                                         //~vbBcI~//~v7dnR~
//      if (Ppcfg->UCECflag2 & UCECF2_CP037)                         //~vbBcI~//~v7dnR~
//      {                                                            //~vbBcI~//~v7dnR~
//        UTRACEP("%s:call set_internal_CP037 SBCSCHARSET=CP037 width CONVERTER=0,flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~vbBcI~//~v7dnR~
//        set_internal_CP037(0,Ppcfg);                               //~vbBcI~//~v7dnR~
//      }                                                            //~vbBcI~//~v7dnR~
      else             //converter=0,accept other option from cfg  //~v7dkI~
      if (Ppcfg->UCECflag & UCECF_SBCSDEF)                         //~v7dkR~
      {                                                            //~v7dkI~
        UTRACEP("%s:CP037 by SBCSDEF flag=0x%08x\n",UTT,Ppcfg->UCECflag);//~v7dkR~
        set_internal_CP037(0,Ppcfg);                               //~v7dkR~
      }                                                            //~v7dkI~
      else             //converter=0,accept other option from cfg  //~v69hI~
      {                                                            //~v69hI~
    	flag=Ppcfg->UCECflag|UCECF_DBCSCV;                         //~v69hR~
    	if (!(flag & UCECF_JIS78))                                 //~v69hI~
        	flag|=UCECF_JIS83;                                     //~v69hI~
    	if (!(flag & UCECF_NEC))                                   //~v69hI~
        	flag|=UCECF_IBM;                                       //~v69hI~
    	if (!(flag & UCECF_CP939))                                 //~v69hI~
    	  if (!(Ppcfg->UCECflag2 & UCECF2_CP931))                  //~vbBcR~
        	flag|=UCECF_CP930;                                     //~v69hI~
    	if (!(flag & (UCECF_SOSISHIFT|UCECF_SOSIREP))) //a2e opt   //~v69hR~
        	flag|=UCECF_SOSIINS;                   //inser so/si   //~v69hI~
    	if (!(flag & (UCECF_SOSIDEL))) //e2a opt                   //~v69hR~
        	flag|=UCECF_SOSIREPSP;                 //so/si-->' '   //~v69hI~
    	Ppcfg->UCECflag=flag;                                      //~v69hI~
//      if (flag & UCECF_SBCSDEF)                                  //~v7d8I~//~v7dkR~
//      {                                                          //~v7d8I~//~v7dkR~
//      	UTRACEP("%s:CP037 by SBCSDEF flag=0x%08x\n",UTT,Ppcfg->UCECflag);//~v7d8R~//~v7dkR~
//          set_internal_CP037(0,Ppcfg);                           //~v7d8I~//~v7dkR~
//      }                                                          //~v7d8I~//~v7dkR~
//      else                                                       //~vbB9I~//~v7dkR~
		if (Ppcfg->UCECflag2 & UCECF2_CP931)     //Japanese latin ext//~vbB9I~
        {                                                          //~vbB9I~
        	UTRACEP("%s:CP037 by SJISOPT:LATIN flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~vbB9I~
            set_internal_CP037(0,Ppcfg);                           //~vbB9I~
        }                                                          //~vbB9I~
      }                                                            //~v69hI~
    }                                                              //~v660I~
    else                                                           //~v660I~
    {                                                              //~v660I~
//#ifdef BBB                                                         //~v66qI~//~v6b3R~
//        for (ii=0,pc=Sebc2asc037;ii<256;ii++,pc++)                 //~v660I~//~v6b3R~
//        {                                                          //~v660I~//~v6b3R~
//            asc=*pc;                                               //~v660I~//~v6b3R~
//            if (asc)                                               //~v660R~//~v6b3R~
//                Sasc2ebc037[asc]=ii;    //reverse map              //~v660I~//~v6b3R~
//        }                                                          //~v660I~//~v6b3R~
//        ucvext_icugetconverter(Popt|UCEIO_SBCSMAP,Sebc2asc037,&addr);//set Sebc2asc as sbcs mapping//~v660R~//~v6b3R~
//        ucvext_icugetconverter(Popt|UCEIO_SBCSMAP|UCEIO_MAPISA2E,Sasc2ebc037,&addr);//~v660R~//~v6b3R~
//        Ppcfg->UCECflag=UCECF_SBCSCV                               //~v660R~//~v6b3R~
//                       |UCECF_USE_CONVERTER //map converter        //~v660I~//~v6b3R~
//                       |UCECF_SBCSMAP                              //~v660I~//~v6b3R~
//                       |UCECF_SBCSDEF                              //~v660I~//~v6b3R~
//                       |(Ppcfg->UCECflag & UCECF_OPENERR)   //cfg file not found//~v69xI~//~v6b3R~
//                        ;                                          //~v660I~//~v6b3R~
//#else                                                              //~v66qI~//~v6b3R~
#ifdef AAA                                                         //~v6fdI~
		psbcscharset=Ppcfg->UCECcsnamesbcs;                        //~v66qI~
        strcpy(psbcscharset,EBC_DEFAULT_CP);                       //~v66qI~
        addr=(ULONG)Ppcfg->UCEChiconvsbcs;	//for linux; parm to ucvext_iconvgetconverter//~v66qI~
		rc2=ucvext_icugetconverter(Popt|UCEIO_SBCSCV,psbcscharset,&addr);//~v66qI~
        if (rc2)                                                   //~v66qI~
        {                                                          //~v6b3I~
                                                                   //~v6fdI~
//      	uerrexit("Deafult Codepage %s is not defined on your system,Specify Converter CodePAge on EBCDIC cfg file",0);//~v6b2R~
//        	uerrexit("Deafult Codepage %s is not defined on your system,Specify Converter CodePAge on EBCDIC cfg file",0,//~v6b2I~//~v6b3R~
          	uerrmsg("Deafult Codepage %s is not defined on your system,Specify Converter CodePage on EBCDIC cfg file",0,//~v6b3R~//~v6baR~
            	psbcscharset);                                     //~v6b2I~
            set_internal_CP037(0,Ppcfg);                           //~v6b3I~
        }                                                          //~v6b3I~
        else                                                       //~v6b3I~
        {                                                          //~v6b3I~
        Ppcfg->UCECconvertersbcs=addr;                             //~v66qI~
        Ppcfg->UCECflag|=UCECF_SBCSCV                              //~v66qI~
            	        |UCECF_USE_CONVERTER //map converter       //~v66qI~
                        ;                                          //~v66qI~
        }                                                          //~v6b3I~
#else                                                              //~v6fdI~
        if (Ppcfg->UCECflag & UCECF_OPENERR 	//cfg file not found//~vbB6I~
        && Gucvebc_stat & UCVEBCS_CMDLINEOPTION) //0x0100 //xe cmdline option cp930/cp939/cp037 specified//~vbB6R~
        	ucvext_cmdlineoption(0,Ppcfg);                         //~vbB6I~
        else                                                       //~vbB6I~
        if (Ppcfg->UCECflag & (UCECF_CP930|UCECF_CP939))   //jp option//~vbB9I~
        {                                                          //~vbB9I~
            UTRACEP("%s:NOT ISDBCSJ() and KANA_EXT|ENG_EXT specified,UCECflag=0x%08x\n",UTT,Ppcfg->UCECflag);//~vbB9R~
        }                                                          //~vbB9I~
        else                                                       //~vbB9I~
        {                                                          //~vbB9I~
//        if (Ppcfg->UCECflag & (UCECF_CP930|UCECF_CP939))   //jp option//~vbB9I~//~vbBcR~
            UTRACEP("%s:NOT ISDBCSJ() and NOT(openerr and cmdline option) call set_internap_CP037\n",UTT);//~vbB9I~
        set_internal_CP037(0,Ppcfg);                               //~v6fdI~
        }                                                          //~vbB9I~
#endif                                                             //~v6fdI~
//#endif                                                             //~v66qI~//~v6b3R~
	}                                                              //~v66KI~
    {                                                              //~v66KI~
		ucvext_setdefaultlocalcv(0,Ppcfg);                         //~v66wI~
    	plocalcharset=Ppcfg->UCECcsnamelocal;                      //~v66wI~
    	if (*plocalcharset)                                        //~v66wI~
        {                                                          //~v66wI~
//        	addr=(ULONG)Ppcfg->UCEChiconvlocal;	//for linux; parm to ucvext_iconvgetconverter//~v66wR~//~v6hhR~
        	addr=(ULPTR)Ppcfg->UCEChiconvlocal;	//for linux; parm to ucvext_iconvgetconverter//~v6hhI~
			rc2=ucvext_icugetconverter(Popt|UCEIO_LOCALCV,plocalcharset,&addr);//~v66wI~
            if (!rc2)                                              //~v66wI~
            {                                                      //~v66wI~
		    	Ppcfg->UCECconverterlocal=addr;                    //~v66wR~
		    	Ppcfg->UCECflag|=UCECF_LOCALCV;                    //~v66wR~
				if (Sextflag & SEXTF_DBCSSTART)//dbcs start byte saved for the converter//~v66WI~
//  	    		Ppcfg->UCECflag|=UCECF_DBCSLOCALCV;  //local converter support dbcs//~v66WI~//~v6BkR~
    	    		Ppcfg->UCECflag|=(int)UCECF_DBCSLOCALCV;  //local converter support dbcs//~v6BkI~
            }                                                      //~v66wI~
            else                                                   //~v66wI~
            {                                                      //~v66wI~
//	        	uerrmsg("get converter for Codepage %s failed,errno=%d",0,//~v66wI~//~v66KR~//~v6f3R~
  	        	uerrmsg("get ICU converter for Codepage %s failed,errno=%d",0,//~v6f3I~
                    plocalcharset,errno);                          //~v66wI~
            }                                                      //~v66wI~
            UTRACEP("%s:localconverter localcharset=%s,UCECconverterlocal=%p\n",UTT,plocalcharset,Ppcfg->UCECconverterlocal);//~v7d9R~
        }                                                          //~v66wI~
    }                                                              //~v660I~
	if (UCECF_ISAVAIL_DBCSCV(Ppcfg))                               //~v660R~
		UDBCSCHK_SETDBCSCV();	//support dbcs                     //~v660R~
    ucvebc_adjustB2A(0,Ppcfg);  //adjust b2a tbl by u2m of localconverter//~v7d9R~
    UTRACED("exit Ppcfg",Ppcfg,UCVEXTCFGSZ);                            //~v7d2I~//~vbB9R~
    return 0;                                                      //~v660I~
}//ucvext_mapinitsetdefault                                        //~v660I~
//*************************************************************************//~v6c4I~
int ucvext_setlocalconverter(int Popt,PUCVEXTCFG Ppcfg)            //~v6c4I~
{                                                                  //~v6c4I~
	char *plocalcharset;                                           //~v6c4I~
    int rc=0,rc2;                                                  //~v6c4I~
//  ULONG addr;                                                    //~v6c4I~//~v6hhR~
    ULPTR addr;                                                    //~v6hhI~
//*****************************                                    //~v6c4I~
    plocalcharset=Ppcfg->UCECcsnamelocal;                          //~v6c4I~
    if (*plocalcharset)                                            //~v6c4I~
    {                                                              //~v6c4I~
//      addr=(ULONG)Ppcfg->UCEChiconvlocal; //for linux; parm to ucvext_iconvgetconverter//~v6c4I~//~v6hhR~
        addr=(ULPTR)Ppcfg->UCEChiconvlocal; //for linux; parm to ucvext_iconvgetconverter//~v6hhI~
        rc2=ucvext_icugetconverter(Popt|UCEIO_LOCALCV,plocalcharset,&addr);//~v6c4I~
        if (!rc2)                                                  //~v6c4I~
        {                                                          //~v6c4I~
            Ppcfg->UCECconverterlocal=addr;                        //~v6c4I~
            Ppcfg->UCECflag|=UCECF_LOCALCV;                        //~v6c4I~
            if (Sextflag & SEXTF_DBCSSTART)//dbcs start byte saved for the converter//~v6c4I~
//              Ppcfg->UCECflag|=UCECF_DBCSLOCALCV;  //local converter support dbcs//~v6c4I~//~v6BkR~
                Ppcfg->UCECflag|=(int)UCECF_DBCSLOCALCV;  //local converter support dbcs//~v6BkI~
            rc=1;                                                  //~v6c4I~
        }                                                          //~v6c4I~
        else                                                       //~v6c4I~
        {                                                          //~v6c4I~
//          uerrmsg("get converter for Codepage %s failed,errno=%d",0,//~v6c4I~//~v6f3R~
            uerrmsg("get ICU converter for Codepage %s failed,errno=%d",0,//~v6f3I~
                plocalcharset,errno);                              //~v6c4I~
            rc=4;                                                  //~v6c4I~
        }                                                          //~v6c4I~
    }                                                              //~v6c4I~
    UTRACEP("%s:charset=%s,rc=%d,converter=%x\n",UTT,plocalcharset,rc,Ppcfg->UCECconverterlocal);//~v6c4I~//~vbB9R~
    return rc;                                                     //~v6c4I~
}//ucvext_setlocalconverter                                        //~v6c4I~
//*************************************************************************//~v66DI~
//*chk subchar was set                                             //~v66DI~
//rc:-3:subchar was set,0:not so,4:dbcs was replaced by sbcs                //~v66DI~//~v66NR~
//*************************************************************************//~v66DI~
//int ucvext_icusubcharchk(int Popt,WUCS Pucs,UCHAR *Pstr,int Plen)  //~v66DI~//~v6BjR~
int ucvext_icusubcharchk(int Popt,UWUCS/*ucs4*/ Pucs,UCHAR *Pstr,int Plen)//~v6BjR~
{                                                                  //~v66DI~
    int rc=0,scdbcslen,swcase;                                     //~v66DR~
    UCHAR scsbcs,*pscdbcs;                                         //~v66DR~
    int handle;                                                    //~v6hAI~
//*****************                                                //~v66DI~
    handle=Popt>>UCVEXTISCO_HANDLEMASKSHIFT;                       //~v6hAI~
	swcase=Popt & UCVEXTISCO_MASK;                                 //~v66DR~
	UTRACEP("%s:ucs=%04x,opt=%x,swcase=0x%02x\n",UTT,(UINT)Pucs,Popt,swcase);   //~v681I~//~v6bnR~//~vbB9R~//~v7dFI~
	UTRACED("ucvext_icusubcharchk ebc",Pstr,Plen);                 //~v683I~//~v7dFM~
    if (swcase==UCVEXTISCO_B2U || swcase==UCVEXTISCO_U2B)          //~v66DR~
    {                                                              //~v66DI~
      if (handle) //from ucvext_icusubcharchk_handle               //~v6hAI~
      {                                                            //~v6hAI~
          scsbcs=UCVEBCH_subcharebcsbcs(handle);                    //~v6hhI~//~v6hAR~
          pscdbcs=UCVEBCH_subcharebcdbcs(handle);                   //~v6hhI~//~v6hAR~
          scdbcslen=UCVEBCH_subcharebcdbcslen(handle);              //~v6hhI~//~v6hAR~
      }                                                            //~v6hAI~
      else    //converter from cfg parameter                       //~v6hAI~
      {                                                            //~v6hAI~
        scsbcs=SsubcharICUebcSbcs;                                 //~v66DI~
        pscdbcs=SsubcharICUebcDbcs;                                //~v66DI~
        scdbcslen=SsubcharICUebcDbcslen;                           //~v66DI~
      }                                                            //~v6hAI~
    }                                                              //~v66DI~
    else                                                           //~v66DI~
    {                                                              //~v66DI~
        scsbcs=SsubcharICUlocalSbcs;                               //~v66DI~
        pscdbcs=SsubcharICUlocalDbcs;                              //~v66DI~
        scdbcslen=SsubcharICUlocalDbcslen;                         //~v66DI~
    }                                                              //~v66DI~
    if (swcase==UCVEXTISCO_B2U || swcase==UCVEXTISCO_L2U)          //~v66DI~
    {                                                              //~v66DI~
        if (Pucs==UDBCSCHK_SUBCHAR_SBCS)   //0x1a                  //~v66DR~
        {                                                          //~v66DR~
                                                                   //~v66DR~
            if (Plen!=1)                                           //~v66DR~
//              rc=UCVEXTRC_SUBCH;                                 //~v66DR~//~v66NR~
                rc=4;   //should be replaced by dbcs repch         //~v66NI~
            else                                                   //~v66DR~
                if (*Pstr!=scsbcs)  //reverse chk                  //~v66DR~
                    rc=UCVEXTRC_SUBCH;                             //~v66DR~
        }                                                          //~v66DR~
        else                                                       //~v66DR~
        if (Pucs==UDBCSCHK_SUBCHAR_DBCS)   //0xfffd                //~v683R~
        {                                                          //~v66DR~
          if (Plen==4 && *Pstr==CHAR_SO)                           //~v683I~
          {                                                        //~v683I~
//        	if (memcmp(Pstr+1,pscdbcs,scdbcslen))                  //~v683I~//~v6BkR~
          	if (memcmp(Pstr+1,pscdbcs,(size_t)scdbcslen))          //~v6BkI~
            	rc=UCVEXTRC_SUBCH;                                 //~v683I~
          }                                                        //~v683I~
          else                                                     //~v683I~
          {                                                        //~v683I~
            if (Plen==1)    //chk sbcs                             //~v6BtI~
            {                                                      //~v6BtI~
                if (*Pstr!=scsbcs)                                 //~v6BtI~
                	rc=UCVEXTRC_SUBCH;                             //~v6BtI~
            }                                                      //~v6BtI~
            else                                                   //~v6BtI~
            if (Plen!=scdbcslen)                                   //~v66DR~
//              rc=UCVEXTRC_SUBCH;                                 //~v66DR~//~v66NR~
                rc=4;   //should be replaced by Sbcs repch         //~v66NI~
            else                                                   //~v66DR~
//              if (memcmp(Pstr,pscdbcs,scdbcslen))                //~v66DR~//~v6BkR~
                if (memcmp(Pstr,pscdbcs,(size_t)scdbcslen))        //~v6BkI~
                    rc=UCVEXTRC_SUBCH;                             //~v66DR~
          }                                                        //~v683I~
        }                                                          //~v66DR~
    }                                                              //~v66DI~
    else     //u2b,u2l                                             //~v66DI~
    {                                                              //~v66DI~
        if (Plen==1)                                               //~v66DI~
        {                                                          //~v66DI~
//          if (*Pstr==scsbcs)  //reverse chk                      //~v66DI~//~v6hxR~
            if (scsbcs && *Pstr==scsbcs)  //reverse chk            //~v6hxI~
        		if (Pucs!=UDBCSCHK_SUBCHAR_SBCS)   //0x1a          //~v66DI~
	                rc=UCVEXTRC_SUBCH;                             //~v66DI~
                                                                   //~v66DI~
        }                                                          //~v66DI~
        else                                                       //~v66DI~
        {                                                          //~v66DI~
          if (Plen==4 && *Pstr==CHAR_SO)                           //~v683R~
          {                                                        //~v683I~
//      	if (!memcmp(Pstr+1,pscdbcs,scdbcslen))                 //~v683I~//~v6hxR~
//      	if (scdbcslen && !memcmp(Pstr+1,pscdbcs,scdbcslen))    //~v6hxI~//~v6BkR~
        	if (scdbcslen && !memcmp(Pstr+1,pscdbcs,(size_t)scdbcslen))//~v6BkI~
		        if (Pucs!=UDBCSCHK_SUBCHAR_DBCS)   //0xfffd        //~v683I~
	                rc=UCVEXTRC_SUBCH;                             //~v683I~
          }                                                        //~v683I~
          else                                                     //~v683I~
          {                                                        //~v683I~
//      	if (scdbcslen==Plen && !memcmp(Pstr,pscdbcs,scdbcslen))//~v66DR~//~v6BkR~
        	if (scdbcslen==Plen && !memcmp(Pstr,pscdbcs,(size_t)scdbcslen))//~v6BkI~
		        if (Pucs!=UDBCSCHK_SUBCHAR_DBCS)   //0xfffd        //~v66DI~
	                rc=UCVEXTRC_SUBCH;                             //~v66DI~
          }                                                        //~v683I~
        }                                                          //~v66DI~
    }                                                              //~v66DI~
	UTRACEP("%s:rc=%d,ucs=%04x\n",UTT,rc,Pucs);                    //~v7dFI~
    return rc;                                                     //~v66DI~
}//ucvext_icusubcharchk                                            //~v66DI~
#endif                                                             //~v660I~
//************************************************************************//~v69dI~
//*ucvext_isdbcs1st                                                //~v69dI~
//************************************************************************//~v69dI~
int ucvext_isdbcs1st(int Popt,UCHAR Pch)                           //~v69dR~
{                                                                  //~v69dI~
	return UCVEXT_ISDBCS1ST(Popt,Pch);                             //~v69dI~
}                                                                  //~v69dI~
//*************************************************************************//~v6bhI~
//*chk converter is ebcdic                                         //~v6bhI~
//*************************************************************************//~v6bhI~
int chk_converter_is_ebcdic(int Popt,PUCVEXTCFG Ppcfg)             //~v6bhI~
{                                                                  //~v6bhI~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    char *pcharset;                                                //~v6bhI~
    int opt=0,rc=0;                                                //~v6bhR~
//********************                                             //~v6bhI~
    if (Ppcfg->UCECflag & UCECF_USE_CONVERTER)                     //~v6bhI~
    {                                                              //~v6bhI~
		pconverter=Ppcfg->UCECconverterdbcs;                       //~v6bhI~
		pcharset=Ppcfg->UCECcsnamedbcs;                            //~v6bhI~
        int swdbcs=1;                                              //~v7dSR~
    	if (!pconverter)                                           //~v6bhI~
        {                                                          //~v6bhI~
    	    swdbcs=0;                                              //~v7dSR~
			pconverter=Spcfg->UCECconvertersbcs;                   //~v6bhI~
			pcharset=Ppcfg->UCECcsnamesbcs;                        //~v6bhI~
        }                                                          //~v6bhI~
        if (pconverter)                                            //~v6bhI~
        {                                                          //~v6bhI~
    		if (Ppcfg->UCECflag & UCECF_USE_ICU)                   //~v6bhI~
 		   		opt|=UCVEBC4O_USEICU;                              //~v6bhI~
    		rc=ucvebc4_chkdbcsconverter(opt,pconverter,pcharset);  //~v6bhI~
            UTRACEP("%s:ebcdic is converter rc=%d,converter=%p,charset=%s\n",UTT,rc,pconverter,pcharset);//~v6bhR~//~vbB9R~//~vbBtR~
    		if (rc>1)                                              //~v6bhI~
            {                                                      //~v6bhI~
    			Ppcfg->UCECflag&=~UCECF_USE_CONVERTER;             //~v6bhI~
        		return 4;                                          //~v6bhI~
            }                                                      //~v6bhI~
            if (!rc && swdbcs)  //not dbcs and by csnamedbcs       //~v7dSR~
            {                                                      //~v7dSR~
            	uerrmsg("%s is not DBCS_CHARSET converter, specify as SBCS_CHARSET.",0,pcharset);//~v7dSR~
            }                                                      //~v7dSR~
        }                                                          //~v6bhI~
    }                                                              //~v6bhI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbBtI~
    return rc;                                                     //~v6bhR~
}//chk_converter_is_ebcdic                                         //~v6bhI~
//*************************************************************************//~v69cI~
//*init                                                            //~v69cI~
//*************************************************************************//~v69cI~
int ucvext_handle0init(int Popt,PUCVEXTCFG Ppcfg)                  //~v69cR~
{                                                                  //~v69cI~
    PUCVEBCH pucveh;                                               //~v69cI~
    char *pcvnm,cvname[MAX_CSNAMESZ+32];                  //~v69cR~//~v69vR~
    int cvtype;                                                    //~v69cI~
//  int rc;                                                        //~v6n0R~
    int rc;                                                        //~v7dfI~
//********************                                             //~v69cI~
    UTRACEP("%s:entry opt=0x%04x\n",UTT,Popt);                     //~vbB9I~
    pucveh=UCVEBC_GETPUCVEH(0);     //cfg entry                    //~v69cI~
//  rc=chk_converter_is_ebcdic(0,Ppcfg);                           //~v6n0R~
//     chk_converter_is_ebcdic(0,Ppcfg);                           //~v6n0I~//~v7dfR~
    rc=chk_converter_is_ebcdic(0,Ppcfg);                           //~v7dfI~
// if (rc==1)                                                      //~v6bhI~
//      UDBCSCHK_SETDBCSCV();	//converter supports dbcs          //~v6bhI~
   if (rc==1)                                                      //~v7dfI~
        UDBCSCHK_SETDBCSCV();	//converter supports dbcs          //~v7dfI~
//  if (UDBCSCHK_ISDBCSCV())                                       //~v69cI~//~vbBcR~
    if ((Ppcfg->UCECflag & (UCECF_CP930|UCECF_CP939))              //~vbBcI~
    ||  (Ppcfg->UCECflag2 & (UCECF2_CP931))                        //~vbBcI~
    ||  UDBCSCHK_ISDBCSCV()                                        //~v7dfI~
    )                                                              //~vbBcI~
        pucveh->UCVEHflag|=UCVEHF_DBCSCV;   //dbcs supportlfor UCVEBCH_ISDBCSCV(pucveh)//~v69cI~
    cvtype=ucvebc4_getcvtype(0,0/*handle*/);                       //~v69cI~
    UTRACEP("%s:cvtype=0x%08x\n",UTT,cvtype);                      //~v7dcI~
    if (cvtype & UCVEBC4CVT_EXT)	//external converter           //~v69cR~
    {                                                              //~v69cI~
        pcvnm=Ppcfg->UCECcsnamedbcs;                               //~v69cR~
        if (!*pcvnm)                                               //~v69cR~
            pcvnm=Ppcfg->UCECcsnamesbcs;                           //~v69cR~
        UTRACEP("%s:UCVEBC4CVT_EXT before cvnm=%s\n",UTT,pcvnm);   //~vbBcI~
        if (!*pcvnm)                                               //~v69vI~
        {                                                          //~v6beI~
          if (cvtype & UCVEBC4CVT_MAP)                             //~v6beR~
          {                                                        //~v7dcI~
          	UTRACEP("%s:UCVEBC4CVT_MAP flag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7dcR~
//            if (Ppcfg->UCECflag2 & UCECF2_CP931)                   //~v7dcR~//~vbBsR~
////              pcvnm="CP931-Internal"; //by set_internal_CP037()  //~v7dcI~//~vvBdR~//~vbBsR~
//                pcvnm=EBC_KANJI_LATIN "-Internal"; //by set_internal_CP037()//~vvBdI~//~vbBsR~
//            else                                                   //~v7dcI~//~vbBsR~
        	pcvnm="CP037-Internal"; //by set_internal_CP037()      //~v6beI~
          }                                                        //~v7dcI~
          else                                                     //~v6beI~
    		pcvnm="Unknown";                                       //~v69vI~
        }                                                          //~v6beI~
        UTRACEP("%s:UCVEBC4CVT_EXT after cvnm=%s\n",UTT,pcvnm);    //~vbBcI~
//        if (!(cvtype & UCVEBC4CVT_OPENERR))                        //~v69cR~//~v69vR~
//        {                                                          //~v69cI~//~v69vR~
//            if (cvtype & UCVEBC4CVT_ICU)                           //~v69cR~//~v69vR~
//                pcvtype="ICU";                                     //~v69cR~//~v69vR~
//            else                                                   //~v69cR~//~v69vR~
//                pcvtype="";                                        //~v69cR~//~v69vR~
//        }                                                          //~v69cI~//~v69vR~
//        else                                                       //~v69cI~//~v69vR~
//            if (cvtype & UCVEBC4CVT_ICU)                           //~v69cI~//~v69vR~
//                pcvtype="Not found ICU";                           //~v69cI~//~v69vR~
//            else                                                   //~v69cI~//~v69vR~
//                pcvtype="Not found";                               //~v69cI~//~v69vR~
    }                                                              //~v69cI~
    else                                                           //~v69cI~
    {                                                              //~v69cI~
        UTRACEP("%s:! UCVEBC4CVT_EXT flga=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7dcI~
//  	pcvnm="InternalMap";                                       //~v69cI~//~v69vR~
//        if (Ppcfg->UCECflag2 & UCECF2_CP931)                       //~vbB9I~//~vbBsR~
////          pcvnm="CP931-Internal";    //eng-ext                   //~vbB9I~//~vvBdR~//~vbBsR~
//            pcvnm=EBC_KANJI_LATIN "-Internal"; //by set_internal_CP037()//~vvBdI~//~vbBsR~
//        else                                                       //~vbB9I~//~vbBsR~
        if (Ppcfg->UCECflag & UCECF_CP939)                         //~v69vI~
        	pcvnm="CP939-Internal";    //eng-ext                   //~v69vR~
        else                                                       //~v69vI~
//      if (Ppcfg->UCECflag & UCECF_SBCSDEF)                       //~v7dkI~//~v7dmR~
        if ((Ppcfg->UCECflag & UCECF_SBCSDEF)                      //~v7dmI~
//        ||  (Ppcfg->UCECflag2 & UCECF2_CP037)                      //~v7dmI~//~v7dnR~
        )                                                          //~v7dmI~
        	pcvnm=EBC_US "-Internal";    //-ebcg:Latin, SBCSCHARSET CP037//~v7dkI~
//      else                                                       //~v7dkI~//~v7dmR~
//      if (Gucvebc_stat & UCVEBCS_SBCSLATIN)                      //~vbBgR~//~v7dmR~
//        	pcvnm=EBC_US "-Internal";    //-ebcg:Latin, SBCSCHARSET CP037//~vbBgI~//~v7dmR~
        else                                                       //~vbBgI~
        	pcvnm="CP930-Internal";    //kana-ext                  //~v69vR~
//        pcvtype="";                                                //~v69cI~//~v69vR~
        UTRACEP("%s:!UCVEBC4CVT_EXT cvnm=%s\n",UTT,pcvnm);         //~vbBcI~
    }                                                              //~v69cI~
//  sprintf(cvname,"CFG:%s:%s",pcvtype,pcvnm);                     //~v69cR~//~v69vR~
    sprintf(cvname,"%s",pcvnm);                                    //~v69vI~
    UstrncpyZ(pucveh->UCVEHcvname,cvname,MAX_CSNAMESZ);            //~v69cI~
    if (*(Ppcfg->UCECcsnamesbcs)                                   //~v7dJI~
    &&  strcmp(pcvnm,Ppcfg->UCECcsnamesbcs))                       //~v7dJI~
	    UstrncpyZ(pucveh->UCVEHcvname2,Ppcfg->UCECcsnamesbcs,MAX_CSNAMESZ);//~v7dJI~
    pucveh->UCVEHsubcharebcsbcs=Ssubcharebcsbcs;                   //~v69cI~
    memcpy(pucveh->UCVEHsubcharebcdbcs,Ssubcharebcdbcs,MAX_MBCSLEN);//~v69cI~
//  pucveh->UCVEHsubcharebcdbcslen=strlen(Ssubcharebcdbcs);        //~v69cI~//~v6BkR~
    pucveh->UCVEHsubcharebcdbcslen=(int)strlen(Ssubcharebcdbcs);   //~v6BkI~
    pucveh->UCVEHsubcharICUebcSbcs=SsubcharICUebcSbcs;             //~v69cI~
    memcpy(pucveh->UCVEHsubcharICUebcDbcs,SsubcharICUebcDbcs,MAX_MBCSLEN);//~v69cR~
//  pucveh->UCVEHsubcharICUebcDbcslen=strlen(SsubcharICUebcDbcs);  //~v69cI~//~v6BkR~
    pucveh->UCVEHsubcharICUebcDbcslen=(int)strlen(SsubcharICUebcDbcs);//~v6BkI~
    pucveh->UCVEHsubcharsbcs=Ssubcharsbcs;                         //~v69cI~
    pucveh->UCVEHsubchardbcs=Ssubchardbcs;                         //~v69cI~
    pucveh->UCVEHsubchardefaultucsdbcs=Ppcfg->UCECsubchardefaultucsdbcs;//~v69cR~
    pucveh->UCVEHsubchardefaultucssbcs=Ppcfg->UCECsubchardefaultucssbcs;//~v69cR~
    UTRACED("pucveh",pucveh,UCVEBCHSZ);                 //~vbB4I~  //~v7dnR~
    UTRACEP("%s:exit\n",UTT);                                      //~vbB9I~
    return 0;                                                      //~v69cI~
}//ucvebc4_handle0init                                             //~v69cI~
//*************************************************************************//~v6f4I~
//*get icu converter for mb charset                                //~v6f4I~
//*rc 4:err,1:type=MBCS                                            //~v6f4I~
//*************************************************************************//~v6f4I~
//int ucvext_icuclose(int Popt,ULONG Pconverter)                     //~v6f4I~//~v6hhR~
int ucvext_icuclose(int Popt,ULPTR Pconverter)                     //~v6hhI~
{                                                                  //~v6f4I~
	ICUFUNC_CLOSE api;                                             //~v6f4I~
    int rc=0;                                                      //~v6f4I~
//***********************                                          //~v6f4I~
    ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f4I~
    UTRACEP("%s:converter=%x\n",UTT,Pconverter);          //~v6f4I~//~vbB9R~
    api=Spfuncclose;                                               //~v6f4I~
    (*api)((UConverter *)Pconverter);      //ucnv_close            //~v6f4I~
    return rc;                                                     //~v6f4I~
}//ucvext_icuclose                                                 //~v6f4I~
//*************************************************************************//~v6f3I~
//*get icu converter for mb charset                                //~v6f3I~
//*rc 4:err,1:type=MBCS                                            //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icureset(int Popt,ULONG Pconverter)                     //~v6f3I~//~v6hhR~
int ucvext_icureset(int Popt,ULPTR Pconverter)                     //~v6hhI~
{                                                                  //~v6f3I~
	ICUFUNC_RESET api;                                             //~v6f3I~
    int rc=0;                                                      //~v6f3I~
//***********************                                          //~v6f3I~
    ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3I~
    UTRACEP("%s:converter=%x\n",UTT,Pconverter);          //~v6f3I~//~vbB9R~
    api=Spfuncreset;                                               //~v6f3I~
    (*api)((UConverter *)Pconverter);      //ucnv_open             //~v6f3I~
    return rc;                                                     //~v6f3I~
}//ucvext_icureset                                                //~v6f3I~//~v6f4R~
//*************************************************************************//~v6f3I~
//*get icu converter for mb charset                                //~v6f3I~
//*from mbinit for defaultlocale or -C parm                        //~v6f3I~
//*from getparmconvertermbICU for m2m                              //~v6f3I~
//*rc 4:err,1:type=MBCS                                            //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icugetmbconverter(int Popt,char *Pcharset,ULONG *Ppconverter)//~v6f3I~//~v6hhR~
int ucvext_icugetmbconverter(int Popt,char *Pcharset,ULPTR *Ppconverter)//~v6hhI~
{                                                                  //~v6f3I~
    UErrorCode uerrc=U_ZERO_ERROR;                                 //~v6f3I~
	ICUFUNC_OPEN apiopen;                                          //~v6f3I~
	UConverter *pconverter;                                        //~v6f3I~
    int rc;                                                        //~v6f3I~
//***********************                                          //~v6f3I~
    UTRACEP("%s:opt=%x,charset=%s\n",UTT,Popt,Pcharset);//~v6f3I~  //~vbB9R~
    ICU_INITCHK(8);    //if icuinit not called ,return 4           //~v6f3I~
    apiopen=Spfuncopen;                                            //~v6f3I~
    pconverter=(*apiopen)(Pcharset,&uerrc);      //ucnv_open       //~v6f3I~
  if (Ppconverter)                                                 //~v6f9I~
//  *Ppconverter=(ULONG)pconverter;                                //~v6f3I~//~v6hhR~
    *Ppconverter=(ULPTR)pconverter;                                //~v6hhI~
    if (!pconverter)                                               //~v6f3I~
    {                                                              //~v6f3I~
        uerrmsg("Cannot find ICU converter for %s,errc=%d",0,      //~v6f3R~
                    Pcharset,(int)uerrc);                          //~v6f3I~
        rc=4;                                                      //~v6f3I~
    }                                                              //~v6f3R~
    else                                                           //~v6f3R~
    {                                                              //~v6f3R~
		if (!Ppconverter)                                          //~v6f9I~
//        	ucvext_icuclose(0,(ULONG)pconverter);	//available chk only//~v6f9R~//~v6hhR~
        	ucvext_icuclose(0,(ULPTR)pconverter);	//available chk only//~v6hhI~
        rc=0;                                                      //~v6f3I~
    }                                                              //~v6f3I~
    UTRACEP("%s:rc=%d,charset=%s,converter=%x,Ppconverter=%x\n",UTT,rc,Pcharset,pconverter,Ppconverter);//~v6f9I~//~vbB9R~
    return rc;                                                     //~v6f3I~
}//ucvext_icugetmbconverter                                        //~v6f3I~
//*************************************************************************//~v6f3M~
//*pass pfunc to ucvext12                                          //~v6f3I~
//*************************************************************************//~v6f3I~
int ucvext_icumbinit12(int Popt,PUCVEXTCFG Pcfg)                   //~v6f3M~
{                                                                  //~v6f3M~
    void *pfuncs[2];                                               //~v6f3M~
//******************                                               //~v6f3M~
    pfuncs[0]=Spfunctoucs;                                         //~v6f3M~
    pfuncs[1]=Spfuncfromucs;                                       //~v6f3M~
    ucvext12_init(0,Sextflag,Pcfg,pfuncs);                         //~v6f3M~
    return 0;                                                      //~v6f3I~
}//ucvext_icumbinit12                                              //~v6f3M~
//*************************************************************************//~v6f3I~
//*init icu for local converetr                                    //~v6f3I~
//from udbcschk_icugetlocalconverter                               //~v6f3R~
//from ucvext_icua2ainit for M2M(ENVINIT)                          //~v6f3I~
//from ucvext_getdefaultconvertername(ENVINIT)                     //~v6f3I~
//*************************************************************************//~v6f3I~
//int ucvext_icumbinit(int Popt,char *Pcharset,ULONG *Ppconverter)   //~v6f3R~//~v6hhR~
int ucvext_icumbinit(int Popt,char *Pcharset,ULPTR *Ppconverter)   //~v6hhI~
{                                                                  //~v6f3I~
static	UCVEXTCFG Scfg;                                            //~v6f3R~
	UCVEXTCFG *pcfg;                                               //~v6f3I~
    UCHAR defcharset[256],subchars[MAX_MBCSLEN+1];                 //~v6f3R~
//  ULONG converter=0;                                             //~v6f3I~//~v6h6R~//~v6hhR~
    ULPTR converter=0;                                             //~v6hhI~
    int rc=0,subchlen;                                             //~v6f3R~
//******************                                               //~v6f3I~
    UTRACEP("%s:charset=%s\n",UTT,Pcharset);                       //~v77EI~
	pcfg=&Scfg;                                                    //~v6f3R~
    if (!(pcfg->UCECflag2 & UCECF2_ICUINITEND))	//dup chk          //~v6f3I~
    {                                                              //~v6f3I~
		memset(pcfg,0,sizeof(Scfg));                               //~v6f3R~
		rc=ucvext_icuinit_env(UCEIO_USEICU,pcfg);   //get default dl version//~v6f3R~
		if (!rc)                                                   //~v6f3R~
        {                                                          //~v6f3I~
			rc=ucvext_icuinit(Popt|UCEIO_USEICU,pcfg->UCECdllsuffix,pcfg->UCECapisuffix,0/*apis*/);//~v6f3R~
			if (Popt & UCEIMIO_ENVINIT)                            //~v6f3I~
    	    	ucvext_icumbinit12(0,pcfg);                        //~v6f3I~
          if (!rc)                                                 //~v6fjI~
			pcfg->UCECflag2|=UCECF2_ICUINITEND;                    //~v6f3I~
        }                                                          //~v6f3I~
    }                                                              //~v6f3I~
	if (Popt & UCEIMIO_ENVINIT)                                    //~v6f3I~
    	return rc;                                                 //~v6f3I~
//    if (!rc)                                                     //~v6f3R~
//    {                                                            //~v6f3R~
//        *defcharset=0;                                           //~v6f3R~
//        rc=ucvext_icugetdefaultconvertername(0,defcharset);      //~v6f3R~
//    }                                                            //~v6f3R~
    if (!rc)                                                       //~v6f3R~
    {                                                              //~v6f3I~
    	rc=ucvext_icugetmbconverter(0,Pcharset,&converter);        //~v6f3R~
    	if (rc)                                                    //~v6f3I~
    	{                                                          //~v6f3I~
			rc=ucvext_icugetdefaultconvertername(0,defcharset,&converter);//~v6f3R~
            if (rc || !strcmp(defcharset,LOCALEID_UTF_8))          //~v6f3R~
            {                                                      //~v6f3I~
                strcpy(defcharset,ICU_DEFAULT_CHARSET);            //~v6f3I~
		    	rc=ucvext_icugetmbconverter(0,defcharset,&converter);	//US-ASCII//~v6f3R~
            }                                                      //~v6f3I~
        	uerrmsg("ICU converter open failed for %s",0,          //~v6f3M~
            			Pcharset);                                 //~v6f3M~
            if (!rc)                                               //~v6f3I~
            {                                                      //~v6f3I~
            	strcpy(Pcharset,defcharset);                       //~v6f3I~
        		uerrmsgcat(", %s is used(Specify -C option if required)",0,//~v6f3R~
            				defcharset);                           //~v6f3I~
            }                                                      //~v6f3I~
    	}                                                          //~v6f3I~
    }                                                              //~v6f3I~
    if (!rc)                                                       //~v6f3I~
    {                                                              //~v6f3I~
//  	*Ppconverter=converter;                                    //~v6f7R~
    	Ppconverter[ICULCPL_CONVERTER]=converter;                  //~v6f7R~
        subchlen=sizeof(subchars);	//input                                //~v6f3I~//~v6f7R~
        ucvext_icugetsubchars(UCEIO_OPENED,converter,subchars,&subchlen);//~v6f3R~
        if (subchlen==1)                                           //~v6f3I~
        	pcfg->UCECsubcharlocalsbcs=*subchars;                  //~v6f3R~
        else                                                       //~v6f3I~
        if (subchlen>1)                                            //~v6f3R~
//      	UmemcpyZ(pcfg->UCECsubcharlocaldbcs,subchars,subchlen);//~v6f3R~//~v6BkR~
        	UmemcpyZ(pcfg->UCECsubcharlocaldbcs,subchars,(size_t)subchlen);//~v6BkI~
//  	UmemcpyZ(SsubcharICUmblocal,subchars,subchlen);            //~v6f7R~//~v6BkR~
    	UmemcpyZ(SsubcharICUmblocal,subchars,(size_t)subchlen);    //~v6BkI~
//      Ppconverter[ICULCPL_SUBCH]=(ULONG)SsubcharICUmblocal;      //~v6f7R~//~v6hhR~
        Ppconverter[ICULCPL_SUBCH]=(ULPTR)SsubcharICUmblocal;      //~v6hhI~
//        Ppconverter[ICULCPL_SUBCHLEN]=(ULONG)subchlen;           //~v6fpR~
        ucvext_icumbinit12(0,pcfg);                                //~v6f3R~
    }                                                              //~v6f3I~
	return rc;                                                     //~v6f3I~
}//ucvext_icumbinit                                                //~v6f3I~
//*************************************************************************//~v6f3I~
//*initialy get default charset for ICU                            //~v6f3I~
//*from udbcschk_wcinit                                            //~v6f3I~
//*************************************************************************//~v6f3I~
int ucvext_setdefaultlocale(int Popt,char *Pcharset)               //~v6f3I~
{                                                                  //~v6f3I~
    int ctype,rc=4;                                                //~v6f3I~
    char locale[MAXLOCALESZ];                                      //~v6f3I~
//******************                                               //~v6f3I~
	do                                                             //~v6f3I~
    {                                                              //~v6f3I~
    	*locale=0;                                                 //~v6f3I~
		if (ucvext_icugetdefaultconvertername(0,locale,0/*Ppconverter*/))//~v6f3I~
        	break;                                                 //~v6f3I~
        if (!*locale)                                              //~v6f3I~
        	break;                                                 //~v6f3I~
        ctype=0;                                                   //~v6f3I~
//		ucvext_icugetconvertertype(0,(ULONG)locale,&ctype);        //~v6f3R~//~v6hhR~
		ucvext_icugetconvertertype(0,(ULPTR)locale,&ctype);        //~v6hhI~
  		if (ctype==UCNV_UTF8)                                      //~v6f3I~
    		break;                                                 //~v6f3I~
        strcpy(Pcharset,locale);                                   //~v6f3I~
        rc=0;                                                      //~v6f3I~
    } while(0);                                                    //~v6f3I~
    if (rc) 	//failed to get icu default                        //~v6f3I~
	    UstrncpyZ(Pcharset,utfcvsetdefaultlocaleICU(0),MAXLOCALESZ);  //get from LANG//~v6f3R~
    UTRACEP("%s:out=%s\n",UTT,Pcharset);                           //~v791I~
    return 0;                                                      //~v6f3I~
}//ucvext_setdefaultlocale                                         //~v6f3I~
#endif //WIN/LNX
//************************************************************************//~v6M4I~
//get icu version by uconv cmd                                     //~v6M4I~
//rc:0:suffix specified on cfg parm                                //~v6M4I~
//rc:1:suffix filled                                               //~v6M4I~
//rc:4:err                                                         //~v6M4I~
//************************************************************************//~v6M4I~
int chkicuversion(char *Ppdllsuffix,size_t Pdllsuffixsz,char *Ppapisuffix,size_t Papisuffixsz)//~v6M4I~
{                                                                  //~v6M4I~
    int rc,stdoctr,stdectr,opt,len=0;                              //~v6M4R~
    char **pstde,*pc,*pc2,**pstdo,*pcmd;                                    //~v558R~//~v6M4I~
//********************************                                 //~v6M4I~
    UTRACEP("%s:entry\n",UTT);                                     //~v77EI~
    if (*Ppdllsuffix || *Ppapisuffix)                              //~v6M4I~
    	return 0;                                                  //~v6M4I~
    opt=UPROC_LANGC|UPROC_NOMSG;                                 //~v6M4I~//~v6M5R~
    pcmd="uconv --version";                                        //~v6M4I~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v6M4R~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v6M4R~
 for(;;)                                                           //~v6M4M~
 {                                                                 //~v6M4M~
    rc=4;                                                          //~v6M4M~
    if (!pstdo)                                                    //~v6M4I~
        break;                                                     //~v6M4R~
    pc=*pstdo;                                                     //~v6M4I~
    if (!pc)                                                       //~v6M4I~
        break;                                                     //~v6M4R~
    UTRACEP("%s:stdo=%s\n",UTT,pc);                                //~v6M4I~
    pc=strstr(pc,"ICU");                                           //~v6M4I~
    if (!pc)                                                       //~v6M4I~
        break;                                                     //~v6M4R~
    pc+=3;                                                         //~v6M4I~
    pc+=strspn(pc," \t");                                          //~v6M4R~
    pc2=strpbrk(pc," \t\n");                                       //~v6M4I~
    if (!pc2)                                                      //~v6M4I~
        len=(int)strlen(pc);                                       //~v6M4R~
    else                                                           //~v6M4I~
    	len=PTRDIFF(pc2,pc);                                       //~v6M4R~
    if (len>=(int)Pdllsuffixsz)                                    //~v6M4R~
        break;                                                     //~v6M4R~
    UmemcpyZ(Ppdllsuffix,pc,(size_t)len);                          //~v6M4R~
    pc2=strchr(Ppdllsuffix,'.');                                   //~v6M4R~
    if (pc2)                                                       //~v6M4I~
    {                                                              //~v6M4I~
    	len=PTRDIFF(pc2,Ppdllsuffix);                              //~v6M4R~
        *pc2=0; //Windows dose not slink to 59.1.dll from 59.dll   //~v6M4I~
    }                                                              //~v6M4I~
    if (len+1>=(int)Papisuffixsz)                                  //~v6M4R~
        break;                                                     //~v6M4R~
    rc=0;                                                          //~v6M4I~
    break;                                                         //~v6M4I~
  }                                                                //~v6M4I~
    if (pstdo)                                                     //~v6M4I~
	    ufree(pstdo);                                              //~v6M4R~
    if (pstde)                                                     //~v6M4I~
	    ufree(pstde);                                              //~v6M4R~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v774I~
    if (rc)                                                        //~v6M4I~
    {                                                              //~v7deI~
        Gucvebc_stat|=UCVEBCS_UCONVERR;                            //~v7deI~
        return 4;                                                  //~v6M4I~
    }                                                              //~v7deI~
    *Ppapisuffix='_';                                              //~v6M4I~
    UmemcpyZ(Ppapisuffix+1,Ppdllsuffix,(size_t)len);               //~v6M4R~
    UTRACEP("%s:dllsuffix=%s,apisuffix=%s\n",UTT,Ppdllsuffix,Ppapisuffix);//~v6M4I~
    return 1;                                                      //~v6M4I~//~v6M5R~
}//chkicuversion                                                   //~v6M4I~
//************************************************************************//~v6M5I~
//createcfg by uconv version and convertername                     //~v6M5I~
//rc=4:err                                                         //~v6M5I~
//************************************************************************//~v6M5I~
int ucvext_getConverterCfg(int Popt,PUCVEXTCFG Ppcfg)//~v6M5R~     //~v6M4R~
{                                                                  //~v6M5I~
    int rc;                                                        //~v6M5R~
//********************************                                 //~v6M5I~
    UTRACEP("%s,Pcfg=%p\n",UTT,Ppcfg);                             //~v77EI~
    memset(Ppcfg,0,UCVEXTCFGSZ);                                   //~v6M5I~
	rc=chkicuversion(Ppcfg->UCECdllsuffix,sizeof(Ppcfg->UCECdllsuffix),Ppcfg->UCECapisuffix,sizeof(Ppcfg->UCECapisuffix));//~v6M5R~
    if (rc!=1)                                                     //~v6M5I~
    {                                                              //~v7dgI~
    	UTRACEP("%s:chkicuversion rc=%d,return 4\n",UTT,rc);       //~v7dgI~
    	return 4;                                                  //~v6M5I~
    }                                                              //~v7dgI~
    Ppcfg->UCECflag2|=UCECF2_CFGBYUCONV|UCECF2_CFGOK;              //~v6M2I~
    Ppcfg->UCECflag2|=UCECF2_CONVERTER_PARM;                       //~v6M5I~
    Ppcfg->UCECflag|=UCECF_USE_CONVERTER|UCECF_USE_ICU;            //~v6M5I~
	ucvext_setdefaultlocalcv(0,Ppcfg);                             //~v6M5I~
    UTRACEP("%s:exit rc=0\n",UTT);                                 //~v7dgR~
    return 0;                                                      //~v6M5I~
}//getConverterCfg                                                 //~v6M5I~
