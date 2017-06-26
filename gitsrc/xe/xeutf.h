//*CID://+vb3kR~:                             update#=  605;       //+vb3kR~
//*********************************************************************
//* xeutf.h
//*********************************************************************
//vb3k:160608 (LNX:BUG)dir list display 2 sbcs for unprintable ucs //+vb3kI~
//vb2k:160130 membername on dirlist is FNLC but edit panelfile name is FNU8.//~vb2kI~
//            dirsetlocalename call dirsetddfmtname(DSDFO_L2DD) if not all utf8,//~vb2kI~
//            fileutf8setfilenamecodetype call xeutf_getlocalepathname and GUM_MIXWORDMODE allow UTF8/LC mixed in a pathname.//~vb2kI~
//            Now xeutf_getlocalepathname pre-chk all utf8 and accept the path is utf8.//~vb2kI~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4)              //~vax1I~
//vawB:140612 (BUG)too long renamesv was displayed by LC because getmixedstr returns LC when output area ovf.//~vawBI~
//vawp:140607 (BUG)ddfmt display err for expand1 wildcard          //~vawpI~
//vawj:140605 (BUG:LNX)paste to rename fld;when l2f to katakana ct is 3 byte CTUTF8,it should be chked at l2fbyct//~vawjI~
//            no problem when ct is from cmd buff(fcmdcvl2fsrchstr,utfgetddstr)//~vawjI~
//vavG:140401 (W32UNICODE) MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;hdrname truncated by l2u err//~vavGI~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vauJ:140317 (BUG)UFHfilename:membername ct of fpath should not apply to pathname//~vauJI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vaum:140313 (BUG)same as vau2,occurs on retrieve cmd over session//~vaumI~
//vaud:140310 Alt+W(Copy to cb)select utf8 code if dirlist member codetype:utf8 none the less kbd mode//~vaudI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vau5:140228 (BUG)like as vau0,C+w/A+w and A+Ins(paste to cmdline) colomn err for germany//~vau5I~
//vau2:140227 (BUG)u8 string on cmdline;corrupted display          //~vau8I~
//vak5:130816 compiler warning;set but not used                    //~vak5I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vagv:120915 delete unused function; filesetdbcstblu,xeutfcvl2f   //~vagvI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaaq:111231 (BUG)errmsg attr:green(utf8) position shifted by l2f //~vaaqI~
//vaak:111229 (Bug)va5j: if traslated l2u for cmdline,coloumn pos changes. csrright will split local dbcs and rep to space.//~vaakI~
//va8f:101003 (BUG)lcmd "=" fail by tab compare(l2dd drop tab attr)//~va8fI~
//va8b:101001 dbcs consideration for C&P                           //~va8bI~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va6w:000627 lcmd comp("=") support among locale,utf8 and ebc file//~va5wI~
//va5r:100512 (BUG)cmd stack u8 codetype will be lost              //~va5rI~
//va50 100329 raw ebcdic file support                              //~va50I~
//va3j:100208 (LNX)try ligature for console version                //~va3jI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1N:091122 (UTF8)CPU8 trans err reloading is option by UTF8 cmd //~va1NI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1CI~
//va1y:091108_(UTF8)like as cmd string,stack filename list with lc //~va1yI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1n:091103_(UTF8)cmdline parm for filename encoding             //~va1nI~
//va1m:091102_(UTF8)cmdline parm to force "file encoding is locale code"//~va1mI~
//va1g:091102_Find cmd;search word code is depend not on env(LANG) but kbd mode(A+u)//~va1gI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//                      GUM2_KBDU2L,GUM2_KBDL2U-->GUM2_KBDUTF8 on/off//~va10I~
//                      Mixed string word by word                  //~va10I~
//va0N:091002!(WIN:BUG) C(J)K console kbd input is utf8,treate as locale code//~va0NI~
//va0w:090919!assume locale if lognger than utf8 translation       //~va0wI~
//va00:090510 merge utf8 version                                   //~va00I~
//          del not used xeutf_lcudl/xeutf_setdbcstblmix(call xeutf_getutf8str)//~va00I~
//          conv utf8 to locale                                    //~va00I~
//          always XEUTF8MODE if LNX                               //~va00I~
//          locale/utf8 mixed errmsg                               //~va00I~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~
//v77g:071227 (UTF)re-evaluate utf8 char after join-line           //~v77gI~
//v91M:071224 (UTF:BUG)chng cmd on bin file(spanned case)          //~v91MI~
//v91s:071214 (UTF8)integrate opt mode kbd to mode swkbd           //~v91sI~
//v91r:071214 (UTF8)change cmd for both utf8 and locale file       //~v91gI~
//v91g:071211 (UTF8)dir desc fld attr for utf8/locale              //~v91gI~
//v91c:071205 (UTF8)display mixed code on cmdline                  //~v91cI~
//v918:071130 (UTF8:BUG)dirlist rename fld by utf8                 //~v918I~
//v917:071130 (UTF8)assign A+u to switch kbd conversion mode between asis and conv mode//~v917I~
//v915:071128 (UTF8)distinguish LOCALE file and asis file          //~v915I~
//v913:071128 (UTF8)display sign of utf8 inputmode on cmdline      //~v913I~
//v912:071128 (UTF8)display sign of utf8 encoded on header line    //~v912I~
//v90x:071126 (UTF8) U8/LC cmd(convert cmd string to UTF8/LOCALE)  //~v90xI~
//v90w:071124 (UTF8) MODE command                                  //~v90wI~
//v90r:071113 (UTF8) display filename by utf8                      //~v90rI~
//v90p:071106 (UTF8) apply modification                            //~v90pI~
//v90n:071026 (UTF8) utf is option for each file                   //~v90nI~
//v90d:071016 (UTF8)display dirlist by utf8 if valid locale encoded filename//~v90dI~
//v904:070804 (UTF8)define as not PUTCHARS but UTCHARS             //~v904I~
//v901:070710 (UTF8)setdbcstbl                                     //~v901R~
//v901:070710 (UTF8)utf8 support                                   //~v901I~
//*********************************************************************
//*********************************************************************            ]//~v901R~
//*********************************************************************            ]//~v901R~
#ifdef UTF8SUPP                                                    //~v901R~
//*********************************************************************            ]//~v901R~
#ifdef  GLOBAL_XEUTF                                               //~v90rR~
  #define XEUTFGBL_EXT                                             //~v90rI~
#else                                                              //~v90rI~
  #define XEUTFGBL_EXT extern                                      //~v90rI~
#endif                                                             //~v90rI~
    XEUTFGBL_EXT  CHOFTYPE Gwkchoftype[_MAX_PATH*2+1];             //~v90rR~
	XEUTFGBL_EXT  int     Gutfmode;			//utf flag from Gdbcschk_flag//~v917I~
    #define XEUTF8MODE() (Gutfmode)                                //~v917M~
                                                                   //~v917I~
	XEUTFGBL_EXT  int     Gutfmode2;	//utf flag from Gdbcschk_flag//~v917I~
    #define  GUM2_KBDU2L			0x0001      //kbd input convert utf8 to locale//~v91sR~
    #define  GUM2_KBDL2U			0x0002      //kbd input convert locale to utf8//~v91sR~
	#define  GUM2_ALLFILEUTF8CLP  	0x0004   //all file by cmdline parm//~v917I~
	#define  GUM2_MODEINPUTL2UCLP   0x0008   //convert input locale to utf by cmdline option//~v917I~
//**                                                               //~v90rI~
                                                                   //~v90nI~
    #define XEUTF_VARNAME(notutf8name,utf8name)  utf8name          //~v904R~
    #define XEUTF_DDCWORKSZ(sz)   ((sz)*UTF8_MAXCHARSZ*(1+1+CHOFSZ)+CHOFSZ) //data+dbcs+chof area size//~v904R~
    #define XEUTF_DDCWORKDBCS(pwork,sz)   (pwork+(sz)*UTF8_MAXCHARSZ)//~v904I~
    #define XEUTF_DDCWORKCHOF(pwork,sz)   (PCHOFTYPE)(ULONG)(pwork+(sz)*UTF8_MAXCHARSZ*2)//~v904I~
    #define XEUTF_UTCCAST(name)    (PUTCHARS)(ULONG)name           //~v901R~
                                                                   //~v901I~
    #define XEUTF_DEFPARMNAME       parm_temp                      //~v901R~
    #define XEUTF_PARMDEF           UTC_SPDEFI(XEUTF_DEFPARMNAME)  //~v901R~
    #define XEUTF_PARMDEF_          XEUTF_PARMDEF;                 //~v901R~
    #define XEUTF_PARMRD_(type_name)  type_name;	   //redefine for UTCPARMD2//~v901R~
    #define XEUTF_PARMRDSET_(setstmt) setstmt;                     //~v901R~
    #define XEUTF_PARMRDSETD_(pc,putch) pc=putch->data;            //~v901R~
                                                                   //~v901I~
    #define XEUTF_UTCD(type,name)        UTC_SDEF(name)            //~v901I~
                                                                   //~v901I~
    #define XEUTF_PUTCD(type,name)       UTC_SPDEFI(name)          //~v901R~
    #define XEUTF_PUTCDTL(name)          UTC_SPDEFI(name)          //~v90nI~
    #define XEUTF_PUTCDT(type,name)      UTC_SPDEFI(name);type     //~v901R~
    #define XEUTF_PUTCDTC(type,name)     UTC_SPDEFI(name)          //~v901I~
    #define XEUTF_PUTCDM(type,name)     ;UTC_SPDEFI(name);type     //~v901I~
    #define XEUTF_PUTCDMC(type,name)    ;UTC_SPDEFI(name)          //~v901I~
    #define XEUTF_PUTCDL(name)          ;UTC_SPDEFI(name)          //~v901R~
    #define XEUTF_PUTCDLIV(name,iv)     ;UTC_SPDEFI(name)       //,*pc=iv//~v901R~
                                                                   //~v901I~
    #define XEUTF_UTCDEF(type,name,sz) UCHAR name##_data[(sz)*UTF8_MAXCHARSZ];\
                            USHORT name##_chof[((sz)+1)*CHOFSZ];\
                            UTCHARS name##_utch=UTCVAL(name##_data,name##_chof,0);\
                            PUTCHARS name=&name##_utch             //~v901R~
    #define XEUTF_UTCDEFL(name,sz)  ;UCHAR name##_data[(sz)*UTF8_MAXCHARSZ];\
                            USHORT name##_chof[((sz)+1)*CHOFSZ];\
                            UTCHARS name##_utch=UTCVAL(name##_data,name##_chof,0);\
                            PUTCHARS name=&name##_utch             //~v904I~
    #define XEUTF_UTCDEF_UTCDATA(name) name##_data                 //~v901R~
                                                                   //~v901I~
//param setting                                                    //~v901I~
    #define XEUTF_UTCparmP(Psrc,Ppos)  \
			(UTCsetP(XEUTF_DEFPARMNAME,Psrc,Ppos)) //set cpos temporary//~v901I~
    #define XEUTF_UTCparmPL(Psrc,Ppos,Plenc)  \
			(UTCsetPL(XEUTF_DEFPARMNAME,Psrc,Ppos,Plenc)) //set cpos temporary//~v904I~
    #define XEUTF_UTCparmMP(Psrc,Ppos)  \
			(UTCsetMP(XEUTF_DEFPARMNAME,Psrc,Ppos)) //set cpos temporary//~v904I~
    #define XEUTF_UTCparmD(Psrc)  /*define default parm by XEUTF_PUCTDI_DEFPARM0 */\
			(UTCsetD(XEUTF_DEFPARMNAME,Psrc)) //set cpos temporary //~v901R~
    #define XEUTF_UTCparmAD(Psrc)  /*define default parm by XEUTF_PUCTDI_DEFPARM0 */\
			(UTCsetDCL(XEUTF_DEFPARMNAME,Psrc,UTCCHOFASCII,0)) //set cpos temporary//~v904R~
    #define XEUTF_UTCparmADL(Psrc,len)  /*define default parm by XEUTF_PUCTDI_DEFPARM0 */\
			(UTCsetDCL(XEUTF_DEFPARMNAME,Psrc,UTCCHOFASCII,len))   //~v904R~
    #define XEUTF_UTCparmUDL(Psrc,lenutf) \
			(UTCsetUDCL(XEUTF_DEFPARMNAME,Psrc,Gwkchoftype,lenutf))//~v90rR~
                                                                   //~v90rI~
    #define XEUTF_UTCparmLCUDL(Psrc,lenutf) \
			xeutf_lcudl(0,XEUTF_DEFPARMNAME,Psrc,Gwkchoftype,lenutf)//~v90rR~
	PUTCHARS xeutf_lcudl(int Popt,PUTCHARS Pputc,char *Pdata,PCHOFTYPE Ppchof,int Plenutf);//~v90rR~
                                                                   //~v90rI~
    #define XEUTF_UTCparmDC(Pdata,Pchof)  /*set data/chof/utflen*/\
			(UTCsetDC(XEUTF_DEFPARMNAME,Pdata,Pchof)) //set cpos temporary//~v901R~
    #define XEUTF_UTCparmDCL(Pdata,Pchof,Pwidth)  /*set data/chof/utflen*/\
			(UTCsetDCL(XEUTF_DEFPARMNAME,Pdata,Pchof,Pwidth)) //set cpos temporary//~v901I~
    #define XEUTF_UTCparmULHdataP(Pplh,pos)\
			(UTCsetP(XEUTF_DEFPARMNAME,PLHDATAP(Pplh),pos)) //set cpos temporary//~v901I~
//init                                                             //~v901I~
    #define XEUTF_UTCINIT_(Pputc,Pdata,Pchof,Pwidth) \
			UTCsetDCL(Pputc,Pdata,Pchof,Pwidth);                   //~v901R~
    #define XEUTF_UTCINIT0(putc)              putc->lenc=putc->cpos=0 /*reset before 1st UTCmemcpy*///~v904R~
    #define XEUTF_UTCINIT0C(putc)             XEUTF_UTCINIT0(putc) //~v904I~
    #define XEUTF_UTCINIT0_(putc)             XEUTF_UTCINIT0(putc);//~v904I~
    #define XEUTF_UTCSETP(pc,putc,src,pos)    UTCsetP(putc,src,pos)//~v904I~
    #define XEUTF_SET_USDDATA_LENC_(psd,len)   PSDDATAP(psd)->lenc=len;//~v901R~
	#define XEUTF_REPEXPAND_(Pplh,Plenc)   xeutf_repexpand(Pplh,Plenc);//~v904I~
	#define XEUTF_PARMU2L_(Pplh,Pputc,Pplenutf) \
         if (!PLHUTF8MODE(Pplh) && UTCUTF8MODE(Pputc)) /*set utf8 data to locale plh*/\
         	*(Pplenutf)=UTCLENUTFCHOFFROMCPOS(Pputc),UTCCHOF(Pputc)=0//~v91gR~
	#define XEUTF_KBDISL2U() \
					(   (!UTF8MODEENV()) \
					 && (   (Gutfmode2 & GUM2_KBDL2U) \
                        ) \
                    )                                              //~v91sI~
	#define XEUTF_KBDISU2L() \
					(   ( UTF8MODEENV())  \
					 && (   (Gutfmode2 & GUM2_KBDU2L)  \
                        ) \
                    )                                              //~v91sI~
	#define XEUTF_KBDISUTF8() \
					(    UTF8MODEENV() \
					 && !XEUTF_KBDISU2L() \
                    )                                              //~v91sI~
	#define XEUTF_KBDISLOCALE() \
					(   !UTF8MODEENV() \
					 && !XEUTF_KBDISL2U() \
                    )                                              //~v91sI~
//*********************************************************************//~v901R~
#else //!UTF8                                                      //~v901R~
//*********************************************************************//~v901R~
  #ifdef UTF8SUPPH                                                 //~va00I~
	#ifdef  GLOBAL_XEUTF                                           //~va00I~
  		#define XEUTFGBL_EXT                                       //~va00I~
	#else                                                          //~va00I~
  		#define XEUTFGBL_EXT extern                                //~va00I~
	#endif                                                         //~va00I~
	XEUTFGBL_EXT  int     Gutfmode;			//utf flag from Gdbcschk_flag//~va00I~
	XEUTFGBL_EXT  int     Gutfmode2;	//utf flag from Gdbcschk_flag//~va00I~
#ifdef OLDA10                                                      //~va10I~
    #define  GUM2_KBDU2L			0x0001      //kbd input convert utf8 to locale//~va00I~
    #define  GUM2_KBDL2U			0x0002      //kbd input convert locale to utf8//~va00I~
#endif                                                             //~va10I~
	#define  GUM2_ALLFILEUTF8CLP  	0x0004   //all file by cmdline parm//~va00I~
	#define  GUM2_MODEINPUTL2UCLP   0x0008   //convert input locale to utf by cmdline option//~va00I~
    #define  GUM2_UTF8VERSIONMODE   0x0010   //filename/file contents may be utf8 encoded//~va00I~
	#define  GUM2_WINKBDUTF8        0x0020   //windows kbd input is utf8//~va0NI~
    #define  GUM2_KBDUTF8           0x0040   //kbd input is assumed as UTF8//~va10I~
    #define  GUM2_MIXEDWORDMODE     0x0080   //mixed string is allowed word by word//~va10I~
    #define XEUTF8MODE() (Gutfmode2 & GUM2_UTF8VERSIONMODE)        //~va00I~
    #define XEUTF8MODE_ENV_FORCE() (Gutfmode)	//env is utf8 or force utf8//~va00I~
    #define XEUTF8MODE_ENV()       (Gutfmode & GULIBUTFENV)	//env is utf8//~va00I~
	#define  GUM2_ALLFILELCCLP  	0x0100   //all file is locale by cmdline parm//~va1mI~
	#define  GUM2_DIRU8CLP      	0x0200   //dirlist filename encoding primarily translate as UTF8//~va1nI~
	#define  GUM2_DIRLCCLP      	0x0400   //dirlist filename encoding primarily translate as locale code//~va1nI~
	#define  GUM2_KEEPIFCVERR   	0x0800   //keep original value even when f2l cv err at load//~va1EI~
//  #define  GUM2_NORETRYCPU8ERR    0x1000    //no retry when cpu8 err at fileload//~va1ER~//~va1NR~
//  #define  GUM2_CONSLIGATURE      0x2000    //ligature ON for console mode//~va3jR~
                                                                   //~va00I~
  #else                                                            //~va00I~
    #define XEUTF8MODE() 0                                         //~v90nI~
    #define XEINPUTUTF8MODE() 0                                    //~v90nI~
    #define XEUTF8MODE_ENV()  0                                    //~va00I~
  #endif // UTF8SUPPH                                              //~va00M~
                                                                   //~v90nI~
    #define XEUTF_VARNAME(notutf8name,utf8name)  notutf8name       //~v904R~
    #define XEUTF_DDCWORKSZ(sz)   ((sz)*2) //data+dbcs      area size//~v901I~
    #define XEUTF_UTCCAST(name)          name                      //~v901I~
                                                                   //~v901I~
//  #define XEUTF_DEFPARMNAME                                      //~v901I~
//  #define XEUTF_PARMDEF                                          //~v901I~
    #define XEUTF_PARMDEF_                                         //~v901R~
    #define XEUTF_PARMRD_(type_name)                               //~v901R~
    #define XEUTF_PARMRDSET_(setstmt)                              //~v901R~
    #define XEUTF_PARMRDSETD_(pc,putch)                            //~v901R~
                                                                   //~v901I~
    #define XEUTF_UTCD(type,name)        type *name                //~v901I~
                                                                   //~v901I~
    #define XEUTF_PUTCD(type,name)       type *name                //~v901R~
    #define XEUTF_PUTCDT(type,name)      type *name,               //~v901I~
    #define XEUTF_PUTCDTC(type,name)     type *name                //~v901R~
    #define XEUTF_PUTCDM(type,name)      ,*name,                   //~v901I~
    #define XEUTF_PUTCDMC(type,name)     ,*name                    //~v901R~
    #define XEUTF_PUTCDL(name)           ,*name                    //~v901I~
    #define XEUTF_PUTCDLIV(name,iv)      ,*name=iv                 //~v901R~
                                                                   //~v901I~
    #define XEUTF_UTCDEF(type,name,sz)   type name[sz]             //~v901I~
    #define XEUTF_UTCDEFL(name,sz)       ,name[sz]                 //~v904R~
    #define XEUTF_UTCDEF_UTCDATA(name)   name                      //~v901I~
                                                                   //~v901I~
//param setting                                                    //~v901I~
    #define XEUTF_UTCparmP(Psrc,Ppos)             Psrc+Ppos        //~v901I~
    #define XEUTF_UTCparmPL(Psrc,Ppos,Plenc)      Psrc+Ppos        //~v904I~
    #define XEUTF_UTCparmMP(Psrc,Ppos)            Psrc-Ppos        //~v904I~
    #define XEUTF_UTCparmD(Psrc)                  Psrc             //~v901I~
    #define XEUTF_UTCparmAD(Psrc)                 Psrc             //~v901I~
    #define XEUTF_UTCparmADL(Psrc,len)            Psrc             //~v904I~
    #define XEUTF_UTCparmUDL(Psrc,len)            Psrc             //~v90rI~
    #define XEUTF_UTCparmLCUDL(Psrc,len)          Psrc             //~v90rI~
    #define XEUTF_UTCparmDC(Pdata,Pchof)          Pdata            //~v901I~
    #define XEUTF_UTCparmDCL(Pdata,Pchof,Pwidth)  Pdata            //~v901I~
    #define XEUTF_UTCparmULHdata(Pplh)            Pplh->ULHdata    //~v901I~
    #define XEUTF_UTCparmULHdataP(Pplh,Ppos)      Pplh->ULHdata+Ppos//~v901I~
//init                                                             //~v901I~
    #define XEUTF_UTCINIT_(Pputc,Pdata,Pchof,Pwidth)               //~v901I~
    #define XEUTF_UTCINIT0C(putc)                 *putc=0          //~v904R~
    #define XEUTF_UTCINIT0(putc)                                   //~v904I~
    #define XEUTF_UTCINIT0_(putc)                                  //~v904I~
    #define XEUTF_UTCSETP(pc,putc,src,pos)        pc=src+pos       //~v904I~
    #define XEUTF_SET_USDDATA_LENC_(psd,len)                       //~v901I~
                                                                   //~v904I~
	#define XEUTF_REPEXPAND_(Pplh,Plenc)                           //~v904I~
	#define XEUTF_PARMU2L_(Pplh,Pputc,Pplenutf)                    //~v91gI~
//*********************************************************************//~v904I~
#endif //!UTF8                                                     //~v901R~
//*********************************************************************//~v901R~
//*********************************************************************//~v901R~
//*********************************************************************//~v901R~
//#ifdef UTF8SUPP                                                  //~va00R~
#ifdef UTF8SUPPH                                                   //~va00I~
//*********************************************************************//~v901R~
#define XEUTF_MIXEDFLDCOLOR    (Gattrtbl[COLOR_DLINENO])           //~v91sR~
#define XEUTF_MIXEDFLDFGCOLOR  (XEUTF_MIXEDFLDCOLOR & 0x0f)        //~v91sR~
//*********************************************************************//~v90rI~
void xeutf_init(int Popt);                                         //~v901R~
#define XEUTFIO_INIT      0x01000000                               //~v90nR~
#define XEUTFIO_RESET     0x02000000                               //~v90nR~
#define XEUTFIO_FILE      0x04000000                               //~v90nR~
#define XEUTFIO_KBD       0x08000000                               //~v90nR~
#define XEUTFIO_FORCE_ENG 0x10000000                               //~v90nR~
#define XEUTFIO_PARMCP    0x20000000 //locale parm specified       //~va00I~
#define XEUTFIO_FILELC    0x40000000 //file is locale code as default//~va1mI~
#define XEUTFIO_DIRU8     0x00010000 //dirname is utf8 code as default//~va1nI~
#define XEUTFIO_DIRLC     0x00020000 //dirname is utf8 code as default//~va1nI~
//*********************************************************************//~v904I~
int xeutf_repexpand(PULINEH Pplh,int Plenc);                       //~v904I~
//*********************************************************************//~v904I~
int xeutf_presetlens(PULINEH Pplh,int Plenc);                      //~v904R~
//*********************************************************************//~v901R~
int xeutf_setdbcstbl(PUTCHARS Pputch,UCHAR *Ppdbcs,int Plen,int Popt);//~v901R~
//*********************************************************************//~v77gI~
int xeutf_setdbcstbltabkeep(int Popt,PUTCHARS Pputch,UCHAR *Pdbcs,int Ppos);//~v77gI~
//*********************************************************************//~v918I~
int xeutf_setdbcstblmix(PUTCHARS Pputch,UCHAR *Ppdbcs,int Plen,int Popt);//~v918I~
//*********************************************************************//~v901R~
int xeutf_plhoffs2pos(int Popt,       //search spacing char        //~v904R~
                    PULINEH Pplh,                                  //~v904I~
				    int Poffs,			//offset in data to calc corresponding column//~v904I~
                    int *Poffsinchar);   //offset in char          //~v904I~
//*********************************************************************//~v904I~
int xeutf_plhrep(int Popt,PULINEH Pplh,int Pposoffs,int Plencol,   //~v904I~
					PUTCHARS Prepdataputc,UCHAR *Prepdatapdbcs);   //~v904R~
#define XEUTFREPO_BYOFFS     0x01	//parm is offset/utflen        //~v904R~
#define XEUTFREPO_UPDATELENS 0x02	//parm is offset/utflen        //~v904R~
#define XEUTFREPO_CHARBNDS   0x04	//target and source are cpomplete character boundary//~v904I~
#define XEUTFREPO_DELRBTAB   0x08	//drop tab padding on right boundary//~v904I~
#define XEUTFREPO_MEMSET     0x10	//repdata is clear char        //~v904R~
#define XEUTFREPO_NOCHARBNDS 0x20	//force no charcter boundary operation//~v904I~
#define XEUTFREPO_CMARGINCUT 0x40	//cut by margin for rep        //~v904I~
#define XEUTFREPO_CUNDO      0x80	//undo prepare before update   //~v904I~
#define XEUTFREPO_CUTRESTORETAB   0x0100 //cut by offs but restore tab for cut data//~v904I~
                                                                   //~v904I~
#define XEUTFREPRC_SETDBCS    0x01	//setdbcstbl done              //~v904I~
#define XEUTFREPRC_TABRESTORE 0x02  //tabrestore done              //~v904R~
#define XEUTFREPRC_DROPTABPAD 0x04  //tabpadding dropped           //~v904I~
#define XEUTFREPRC_ERR        0x10  //update rejected              //~v91MI~
//*********************************************************************//~v904I~
int xeutf_plhcut(int Popt,PULINEH Pplh,                            //~v904I~
                    int Poffs,		//cut offset                   //~v904I~
                    int *Ppnewlenc);                               //~v904R~
//*********************************************************************//~v904I~
int xeutf_plhexprep(int Popt,PULINEH Pplh,                         //~v904I~
                    int Ppos,		//target column                //~v904I~
					PUTCHARS Pdata, //repdata,set utflen when no chof//~v904I~
					int Pposs, //data pos(col)                     //~v904I~
                    int Plen,  //data lenc                         //~v904I~
                    PUTCHARS Ppoutplhdata,   //optional putchars to be updated//~v904I~
                    UCHAR ** Ppoutdbcs);    //optional dbcst to be updated//~v904I~
//*********************************************************************//~v904I~
int xeutf_getutf8pathname(int Popt,char *Pfilename,char Pdirsepc,char *Poutbuff,int *Pplenc,int *Pplenutf,char *Pnametype);//~v90rI~
#define XEUTFGUPO_FILEHDR   0x01     //file header line display    //~v90rI~
#define XEUTFGUPO_2LC       0x02     //conv to locale              //~v90xI~
                                                                   //~v90rI~
//#define XEUTFGUPRC_UTF8     0x01    //contains utf8 code           //~v918R~//~vavaR~
//#define XEUTFGUPRC_LC       0x02    //locale code converted to utf8//~v918R~//~vavaR~
//#define XEUTFGUPRC_CVDISP   0x04    //display by color green       //~v918R~//~vavaR~
//*********************************************************************//~v90rI~
#ifdef AAA                                                         //~vagvI~
char *xeutf_getutf8str(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,PCHOFTYPE Ppchof,char *Ppdbcs,int Pbufflen,int *Ppreadlen,int *Pputflen,int *Ppcharcnt);//~v91cR~
#endif                                                             //~vagvI~
#define XEUTFGUO_ASCIIDELM       0x01 //exclude ascii as utf8 code //~v91cR~
#define XEUTFGUO_NOLOCALEDBCSTB  0x02 //not request setdbcs for locale str//~v91cI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define XEUTFGU_RCREVCHK(pc) /*chk to draw string by green*/\
            (pc==0 || pc==(char*)-2 )    /*all utf8 or utf8 follows ascii*///~va00I~
#else                                                              //~va00I~
#define XEUTFGU_RCREVCHK(pc) /*chk to draw string by green*/\
        (UTF8MODEENV()  \
        	? (pc!=0 && pc!=(char*)-1 && pc!=(char *)-2)    /*not all utf and ascii*/\
            : (pc==0 || pc==(char*)-2 )    /*all utf8 or utf8 follows ascii*/\
        )                                                          //~v91gI~
#endif                                                             //~va00I~
#define XEUTF_ERRREPCH   '.'      //should be <0x30 to avoid matching with GB18030 DBCS byte//~va1ER~
#define XEUTF_ERRREPCH_F2LFILE    '?'      //f2l err replace on plh//~va00I~
//#define XEUTF_ERRREPCH_NPUCS      ':'      //f2l err replace on plh//~va20I~//+vb3kR~
//#define XEUTF_ERRREPCH_NPUCSW     ';'      //width is not of wcwidth(for test)//~va20I~//+vb3kR~
#define XEUTF_ERRREPCH_NPUCS     UDBCSCHK_ERRREPCH_NPUCS   //   ':'      //f2l err replace on plh//+vb3kI~
#define XEUTF_ERRREPCH_NPUCSW    UDBCSCHK_ERRREPCH_NPUCSW  //   ';'      //width is not of wcwidth(for test)//+vb3kI~
#define XEUTF_DBCSCHSZ   2                 //dbcs size             //~va0wI~
//*********************************************************************//~va00I~
//int xeutf_getlocalepathname(int Popt,char *Pfpath,int Ppathlen,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen);//~vauaR~
int xeutf_getlocalepathname(int Popt,char *Pfpath,int Ppathlen,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,//~vauaI~
				char *Pdddata,char *Pdddbcs,char* Pddcode,int Pddbuffsz,int *Ppddlen);//~vauaI~
#define XEUTFGLPNO_TAIL              0x01	//trailing ascii data length is on parm//~va00R~
#define XEUTFGLPNO_STRZ              0x02	//strz                 //~va00I~
#define XEUTFGLPNO_MEMBNAME          0x04	//no dirsepc chk       //~va10I~
#define XEUTFGLPNO_FNU8              0x08	//select utf8 for filename encoding if both utf8 and locale is valid//~vagEI~
#define XEUTFGLPNO_FNLC              0x10	//select locale code for filename encoding if both utf8 and locale is valid//~vagEI~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
#define XEUTFGLPNO_LCWIDTHBYDDWIDTH  0x20	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vaubR~
#endif                                                             //~vaubI~
#define XEUTFGLPNO_FNU8MEMB          0x40	//membername is UTF8   //~vauJI~
#define XEUTFGLPNO_FNLCMEMB          0x80	//membername is LC     //~vauJI~
#define XEUTFGLPNO_TAILLENMASK     0xff00	//trailing ascii data length//~va00I~
#ifdef W32UNICODE                                                  //~vavcI~
#define XEUTFGLPNO_REMOTE        0x010000	//remote file          //~vavcI~
#define XEUTFGLPNO_ALLOWSUBCH    0x020000	//ignore rep to subchjar at l2u//~vavGI~
#endif                                                             //~vavcI~
#ifdef LNX                                                         //~vb2kI~
#define XEUTFGLPNO_ERRREPLC      0x040000	//rep by '.' when l2f cverr//~vb2kR~
#endif                                                             //~vb2kI~
//*********************************************************************//~v90xI~
#ifdef AAA                                                         //~vagvI~
int xeutf_getutf8strm(int Popt,char *Pstr,int Pdatalen,char *Pdelmstr,char *Poutbuff,char *Pcodetype,int Pmaxoutlen,int *Pputflen,int *Pplenc);//~v918R~
#endif                                                             //~vagvI~
                                                                   //~va00R~
#define XEUTFGU8MRC_UTF8     0x01                                  //~v918I~
#define XEUTFGU8MRC_LC       0x02                                  //~v918I~
#ifdef W32UNICODE                                                  //~vavaI~
#define XEUTFGU8MRC_UTF8SUBC 0x04 //with _UTF8                     //~vavaR~
#endif                                                             //~vavaI~
                                                                   //~v918I~
#define XEUTFCT_ASCII        0x00   //codetype table value,ascii   //~v918I~
#define XEUTFCT_UTF8   UTFCT_UTF8   //   0x01   //originaly utf8 code//~va00R~
#define XEUTFCT_LC           0x02   //locale converted to utf8     //~v918I~
#ifdef W32                                                         //~vavaI~
#define XEUTFCT_UTF8SUBC  UTFCT_UTF8SUBC  //utf8 containing f2l err code//~vavaR~
#endif                                                             //~vavaI~
                                                                   //~vaaqI~
#ifdef AAA                                                         //~vaaqI~
#define XEUTFCT_L2F          0x80   //temporary value for l2f;     //~vaaqR~
#define XEUTFCT_L2F_LEN2     0x40   //L2F length by 2 byte   ;     //~vaaqR~
#define XEUTFCT_L2F_LENMASK  0x3f   //utf string length generated by l2f//~vaaqR~
#define XEUTFCT_SETL2FCT(pct,len) /*len:max 3fff:16K*/\
                if ((len)>=XEUTFCT_L2F_LENMASK)     \
                {                                    \
                    *(pct)=(UCHAR)((len)/256+XEUTFCT_L2F+XEUTFCT_L2F_LEN2);\
                    *(pct+1)=(UCHAR)((len)%256); \
                }                                \
                else                             \
                {                                \
                    *(pct)=(UCHAR)((len)+XEUTFCT_L2F);\
                }                                                  //~vaaqR~
#define XEUTFCT_GETL2FU8LEN(pct) /*len:max 3fff:16K*/\
                (*(pct) & XEUTFCT_L2F_LEN2)) \
                ? (*(pct) & XEUTFCT_L2F_LENMASK)*256+*((UCHAR*)((pct)+1))\
                : (*(pct) & XEUTFCT_L2F_LENMASK)                   //~vaaqR~
#endif                                                             //~vaaqI~
                                                                   //~vaaqR~
#define XEUTF_FG_UTF8	(Gattrtbl[COLOR_DLINENO]&0x0f)             //~va00R~
//*********************************************************************//~v918I~
char *xeutf_getlocalestr(char *Pstr,int Pdatalen,char *Poutbuff,int Pbufflen,int *Pputflen,int *Ppcharcnt);//~v90xI~
//#define XEUTFGLRC_ISF2L(pc) /*utf8->locale conversion done*/     //~vafkR~
//            (!(pc==0 || pc==(char*)-1 ))    /*NOT all locale or ascll*///~va00I~//~vafkR~
#define XEUTFGLRC_ISF2L(pc) /*utf8->locale conversion done*/\
            (!(pc==0 || pc==(char*)(ULPTR)-1 ))    /*NOT all locale or ascll*///~vafkI~
#define XEUTFGLRC_ISALLASCII(pc)  (pc==(char*)-1 )                 //~va1gR~
int xeutf_getmixedstr(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Pdbcs,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,//~va00R~
                        char *Poututf8,int Poututf8sz,int *Ppoututf8len);//~va00I~
#define XEUTFGLSMO_STRZ        0x01 //set output STRZ              //~va00I~
#define XEUTFGLSMO_KEEPLC      0x02 //output source locale code to Poututf8//~va00I~
#define XEUTFGLSMO_ERRMSG      0x04 //source is for errmsg display //~va10I~
#define XEUTFGLSMO_FILEPATH    0x08 //for filename path(same encoding in the level)//~va10I~
//#define XEUTFGLSMO_DDFMT       0x10 //get output by ddfmt not by lc//~vau7R~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
#define XEUTFGLSMO_LCWIDTHBYDDWIDTH  0x10	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vaubI~
#endif                                                             //~vaubI~
#define XEUTFGLSMO_UTF8        0x20	//apply utf8 if both u8/lc ok  //~vauDI~
#define XEUTFGLSMO_LC          0x40	//apply utf8 if both u8/lc ok  //~vauDI~
#ifdef W32UNICODE                                                  //~vavcI~
#define XEUTFGLSMO_LCPRIMARY   0x80	//apply LC for W32 local       //~vavcI~
#define XEUTFGLSMO_SETINPATHALL   0x0100	//set XEUTFCT_UTF8 all char in the path//~vavpI~
#endif                                                             //~vavcI~
#ifdef W32UNICODE                                                  //~vavpI~
	#define XEUTFGLSMO_MIXEDUDSTR 0x0200	//from getmisexstring to getmixedword,regardless seperator of dirsepc//~vavpI~
	#define XEUTFGLSMO_ALLOWSUBCH 0x0400	//ignore rep to subchjar at l2u//~vavGR~
#endif                                                             //~vavpI~
#define XEUTFGLSMO_ALLOWF2LOUTOVF 0x0800	//not f2lerr when output overflow//~vawBI~
#ifdef LNX                                                         //~vb2kI~
#define XEUTFGLSMO_NOTUTF8PATH    0x1000	//the path name is not valid utf8 string//~vb2kI~
#endif                                                             //~vb2kI~
#ifdef LNX                                                         //~vb2kI~
#define XEUTFGLSMO_ERRREPLC       0x2000	//rep by '.' for l2f cv err//~vb2kI~
#endif                                                             //~vb2kI~
#define XEUTFGLSMO_SEPCMASK    0xff0000 //from getlocalepath dirsepc value mask//~va10I~
//*********************************************************************//~v90nI~
int xeutf_plhl2f(int Popt,PUTCHARS Ptgt,char *Pdbcs,PULINEH Pplh,int Poffs,int Plenc,int *Ppoutlen);//~v90nI~
//*********************************************************************//~v90nI~
#ifdef UTF8SUPP //utf version                                      //~va20R~
int xeutf_modechng(int Popt,PUFILEH Ppfh,PULINEH Pplh,PUTCHARS Psrcputc,int Pcol,//~v90nI~
					PUTCHARS Poutputc,char **Ppdbcs,int *Pplenc,int *Pplenutf);//~v90nR~
#define XEUTFMCO_TABKEEP    0x01                                   //~v90nI~
#else                                                              //~va20I~
	#ifdef UTF8UCS2                                                //~va20I~
		int xeutf_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20I~
					UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen);//~va20M~
        #define XEUTFMCO_SRCU8       0x01                          //~va20I~
        #define XEUTFMCO_SRCLC       0x02                          //~va20I~
	  #ifdef UTF8EBCD	  //raw ebcdic file support                //~va50I~
        #define XEUTFMCO_SRCEB       0x04                          //~va50I~
	  #endif //UTF8EBCD raw ebcdic file support                    //~va50I~
        #define XEUTFMCO_EBCHANDLEP  0x08                          //~va7yI~
		#define XEUTFMCO_HANDLEMASK  0x00000070   //ebc converter handle(00->07)//~va7yI~
		#define XEUTFMCO_HANDLEMASK_SHIFT  4       //handle shift count//~va7yI~
		#define XEUTFMCO_GETHANDLE(opt)  ((((opt) & XEUTFMCO_HANDLEMASK))>>XEUTFMCO_HANDLEMASK_SHIFT)//~va7yI~
		#define XEUTFMCO_SETHANDLE(handle)  (((handle)<<XEUTFMCO_HANDLEMASK_SHIFT) & XEUTFMCO_HANDLEMASK)//~va7yI~
	#endif                                                         //~va20I~
#endif                                                             //~va20I~
//*********************************************************************//~va20M~
//*********************************************************************//~v90nI~
char *xeutf_buffget(int Pbuffid,int Plen);                         //~v90nM~
#define XEUTF_BUFFFREE    -1                                       //~v90nM~
#define XEUTF_BUFFDATA     0                                       //~v90nR~
#define XEUTF_BUFFCHOF     1                                       //~v90nM~
#define XEUTF_BUFFTABEXP   2                                       //~v90nI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#define XEUTF_BUFFMULC     3                                   //~va00I~
	#define XEUTF_BUFFMIXWORD  4                                   //~va10I~
	#define XEUTF_BUFF2        5  //for setdbcs 2nd buff           //~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define XEUTF_BUFEBC       6                                   //~va50I~
	#define XEUTF_BUFEBC2      7    //for b2b                      //~va7tI~
	#define XEUTF_BUFEBCCAP    8    //for C&P                      //~va8bI~
//#ifdef LNX                                                         //~vaumI~//~vauER~
	#define XEUTF_BUFF3        9                                   //~vau7I~
//#endif                                                             //~vaumI~//~vauER~
	#define XEUTF_MAXBUFFID   10                                   //~va50I~
#else                                                              //~va50I~
	#define XEUTF_MAXBUFFID    6                                   //~va00R~//~va1cR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#else                                                              //~va00I~
#define XEUTF_MAXBUFFID    3                                       //~v90nI~
#endif                                                             //~va00I~
//*********************************************************************//~v90nI~
int xeutf_tabexp(int Popt,PUFILEH Ppfh,PUTCHARS Psrc,char *Pdbcs,int Pcol,//~v90nI~
			int Pbuffsz,int *Pplenc,int *Pplenutf,PUTCHARS Poutputc,char **Ppoutdbcs);//~v90nI~
//*******************************************************************//~va1EI~
int xeutf_cvdatawb(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen);//~va1EI~//~va5wR~
//*******************************************************************//~v92nI~
int xeutf_cvdata(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen);//~v92nR~//~va5wR~
#define  XEUTFCVO_CPLC  0x01                                       //~v92nI~
#define  XEUTFCVO_CPU8  0x02                                       //~v92nI~
#define  XEUTFCVO_RETALLASCII  0x04   //set rc if all ascii        //~va00R~
#define  XEUTFCVO_ENVCHK       0x08   //for islocalestr;return UTF8 if env is utf8(kbd input is converted from utf8 to locale)//~va00R~
#define  XEUTFCVO_OUTPARM      0x10   //Ppout is input(output area addr)//~va00I~
#define  XEUTFCVO_STRZ         0x20   //append 0 at end            //~va00I~
#define  XEUTFCVO_UCSLE        0x40   //ucs2 is little endian      //~va00I~
#define  XEUTFCVO_SETCT        0x80  //setup utf8/codetype even when no utf8 contains//~va00I~
#define  XEUTFCVO_NOERRREP   0x0100  //no error data replace       //~va00I~
#define  XEUTFCVO_ERRREPQM   0x0200  //errrep char is "?"          //~va00I~
#define  XEUTFCVO_CPU8UCS2   0x0400  //trans from ddfmt to utf8    //~va20I~
#define  XEUTFCVO_CPLCUCS2   0x0800  //trans from ddfmt to locale  //~va20I~
#define  XEUTFCVO_SETTABCHAR 0x1000  //for l2dd                    //~va8fI~
#define  XEUTFCVO_OUTWIDTH   0x2000  //for f2dd output width limit //~vaaqI~
#define  XEUTFCVO_UCS4       0x4000  //for xeutf_getucsstr,output is not ucs2 but ucs4//~vax1I~
                                                                   //~va00I~
#define  XEUTFCVRC_ALLASCII  0x01   //data is all ascii            //~va00I~
#define  XEUTFCVRC_ERR       0x04   //conv err                     //~va00I~
//*********************************************************************//~v90nI~
int xeutf_islocalestr(int Popt,char *Pinp,int Pinplen,UCHAR **Pputf8,int *Pputflen);//~va00R~//~va5wR~
#define  XEUTFILRC_ALLASCII  0x00   //data is all ascii            //~va00I~
#define  XEUTFILRC_LOCALE    0x01   //data contains locale code under no utf8 env//~va00I~
#define  XEUTFILRC_UTF8      0x02   //data contains locale code under utf8 env//~va00I~
//*********************************************************************//~va00I~
int xeutf_getucsstr(int Popt,char *Pinp,int Pinplen,char *Pout,int Poutbufflen,int *Ppoutlen);//~va00I~
//*********************************************************************//~va20I~
#ifdef UTF8UCS2 //for compchk                                      //~va20I~
int xeutf_cvl2fbyct(int Popt,char *Pinp,int Pinplen,char *Pdbcs,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen);//~va20R~
#define XEUTFL2FBCO_CHKLCLENBYF2L 0x01   //advance ct by the length of F2L outlen//~vawjI~
#endif                                                             //~va20I~
//*********************************************************************//~va00I~
int xeutf_fldl2f(int Popt,char *Pdata,char *Pdbcs,char *Pwk,int Plen,char *Pcodetype,char *Putf8,int *Pputf8len);//~va00R~
//*********************************************************************//~va00I~
int xeutf_mixedstrupdate(int Popt,char *Ptgtlc,char *Ptgtutf8,char *Ptgtcodetype,char *Ptgtdbcs,int Ptgtlclen,int *Pptgtlclen,int *Pptgtutf8len,//~va00R~
							int Ptgtpos,int Ptgtwidth,             //~va00I~
							char *Psrclc,char *Psrcutf8,char *Psrccodetype,char *Psrcdbcs,int Psrclclen,int Psrcutf8len,int Psrcutf8buffsz);//~va00R~
#define  XEUTFMSUO_STRZ       0x01                                 //~va00I~
#define  XEUTFMSUO_INS        0x02                                 //~va00I~
#define  XEUTFMSUO_SETUTF8RC  0x04  	//return rc=1 if utf8 code contained//~va00I~
#define  XEUTFMSUO_UTF8       0x08  	//parm to get mixed string //~vauDI~
#define  XEUTFMSUO_LC         0x10  	//parm to get mixed string //~vauDI~
                                                                   //~va00I~
#define  XEUTFMSURC_UTF8      1		//target contains utf8 coed    //~va00I~
                                                                   //~va00I~
//*********************************************************************//~va00I~
int xeutf_dbcssplit(int Popt,char *Plc,char *Putf8,char *Pcodetype,char *Pdbcs,int Ppos,int *Pputf8len,int *Pputf8offs);//~va00I~
#define XEUTFDSO_STRZ        0x01                                  //~va00I~
                                                                   //~va00I~
//*********************************************************************//~va00I~
//int xeutf_cvf2lsetdbcs(int Popt,char *Pinp,int Pinplen,UCHAR **Pout,UCHAR *Pdbcs,int *Ppoutlen);//~va1cR~//~va5wR~
int xeutf_cvf2lsetdbcs(int Popt,char *Pinp,int Pinplen,UCHAR **Pout,UCHAR **Ppdbcs,int *Ppoutlen);//~va1cR~//~va5wR~
#define  XEUTFF2LO_KEEPIFCVERR 0x01  //setdbcs by org line if cverr//~va1ER~
#define  XEUTFF2LO_SAVECVERRCH 0x02  //setdbcs by org char if cverr//~va1EI~
#define  XEUTFF2LO_DDFMT       0x04  //utf8 file by ucs code       //~va20R~
                                                                   //~va00I~
#define  XEUTFF2LRC_UTF8        0x01  //utf8 code detected         //~va00R~
#define  XEUTFF2LRC_DBCS        0x02  //DBCS detected              //~va00R~
#define  XEUTFF2LRC_SAVEERRCH   0x04  //left org byte code by trans err//~va1EI~
//#define  XEUTFF2LRC_ERR         0x04  //invalid utf8 detected    //~va1ER~
//#define  XEUTFF2LRC_ERRKEPTORG  0x08  //invalid utf8 line was not converted by option//~va1ER~
#define  XEUTFF2LRC_L2FPADDING  0x08  //inserted padding for l2f shrinked local>ucs//~vaakR~
#define  XEUTFF2LRC_WIDTHOVF    0x10  //inserted padding for l2f shrinked local>ucs//~vaaqI~
#define  XEUTFF2LRC_ERR         0x40  //invalid utf8 detected      //~va1EI~
#define  XEUTFF2LRC_ERRKEPTORG  0x80  //invalid utf8 line was not converted by option//~va1EI~
                                                                   //~va00I~
//*********************************************************************//~va1rI~
int xeutf_setctbyu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc,char *Ppct,int Pctbuffsz);//~va1rI~
#define  XEUTFSCBULO_ALLOWREPCH  0x01 //accept repch "?" as valid for cmd retrieve chk//~va5rI~
//*********************************************************************//~va1rI~
//int xeutf_memcmpu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc);//~va1rI~//~va1yR~
int xeutf_memcmpu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc,int *Pplenlc);//~va1yI~
#define XEUTFMC8LO_CHKLCLEN    0x01   //utf8 string is part of locale str to be chked,return lclen if matched//~va1yI~
#define XEUTFMC8LO_ALLOWREPCH  0x02   //accept repch "?" as valid for cmd retrieve chk//~va5rI~
#ifdef LNX                                                         //~vaumI~
#define XEUTFMC8LO_DDWREPCH    0x04   //accept repch "?" as valid for cmd retrieve chk by DDW chking(1 byte ? for u-umrout)//~vaumI~
#endif                                                             //~vaumR~
//*********************************************************************//~va5wI~
int xeutf_memcmpddlc(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,UCHAR *Plcdata,UCHAR *Plcdbcs,int Plclen,int *Pppos1,int *Ppos2);//~va5wR~
//*********************************************************************//~va1CI~
int xeutf_savefnmforerrmsg(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh); //~va1CI~
#ifdef BBB                                                         //~va50I~
int xeutf_seterrmsgct(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Ppct,int Pbuffsz,int *Pplenlc);//~va1CI~
#else                                                              //~va50I~
int xeutf_seterrmsgct(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdbcs,char *Ppct,int Pbuffsz,int *Pplenlc);//~va50R~
#endif                                                             //~va50I~
//int xeutf_savelcctforerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pct,int Plenlc);//~vau7R~
int xeutf_savelcctforerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdddbcs,char *Pct,int Plenlc);//~vau7I~
#define  XEUTFSLCFEO_SPLITIDMASK          0x01                     //~va1CI~
#define  XEUTFSLCFEO_FILENAME             0x02   //filename entry  //~va1CI~
#ifdef UTF8UCS2                                                    //~va20I~
	#define  XEUTFSLCFEO_WORD2            0x04                     //~va20I~
	#define  XEUTFSLCFEO_INDEXMASK        0x07  //2 word support for find AND search//~va20I~
#else                                                              //~va20I~
#define  XEUTFSLCFEO_INDEXMASK            0x03   //[0,1] for operand,[2,3] for filename//~va1CI~
#endif                                                             //~va20I~
//#ifdef LNX                                                         //~vaumR~//~vauER~
	#define  XEUTFSLCFEO_DDFMT            0x10   //parameter is ddfmt//~vau7I~
//#endif                                                             //~vaumR~//~vauER~
//*********************************************************************//~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
int xeutfcvf2lc(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,int *Ppchklen);//~va20R~
#define XEUTFF2LCO_ERRREP      0x01                                //~va20R~
                                                                   //~va20I~
#define XEUTFF2LCRC_UTF8       0x01                                //~va20I~
#define XEUTFF2LCRC_UTF8ERR    0x02                                //~va20I~
#define XEUTFF2LCRC_ERR        0x10                                //~va20I~
#define XEUTFF2LCRC_OVF        0x10                                //~va20I~
                                                                   //~va20I~
//*********************************************************************//~va5wI~
int xeutf_cvlf2lbyct(int Popt,char *Pinp,int Pinplen,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen);//~va5wR~
//*********************************************************************//~va20I~
#ifdef AAA                                                         //~vagvI~
int xeutfcvl2f(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen);//~va20R~//~va5wR~
#endif                                                             //~vagvI~
//*********************************************************************//~vaaqI~
//#ifdef AAA                                                         //~vak5I~//~vau5R~
int xeutf_strlenu8byct(int Popt,char *Pinp,int Pinplen,char *Pdbcs,char *Pcodetype,int Plclen,int *Ppu8len,int *Pplclen);//~vaaqI~
//#endif                                                             //~vak5I~//~vau5R~
//*********************************************************************//~vaaqI~
int xeutf_strwidthu8byct(int Popt,char *Pcodetb,int Plclen);       //~vaaqI~
//*********************************************************************//~vaaqI~
int xeutf_strwidthlcbyct(int Popt,char *Pcodetb,int Pctlen);       //~vaaqI~
//*********************************************************************//~va20I~
#endif //UTF8UCS2                                                  //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int xeutf_setdbcstblbyct(int Popt,UCHAR *Psrch,int Psrchlen,UCHAR *Pct,UCHAR *Pdbcs,int Pbuffsz,int *Ppctlen);//~va50I~//~va5wR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
int xeutfcvdd2lc(int Popt,char *Pdata,int Pdatalen,char *Pdbcs,char *Poutbuff,char *Pcodetypetbl,int Poutbuffsz,int *Ppoutlen);//~vau5M~
#define XEUTFDD2LCRC_ERR       4                                   //~vau5I~
#define XEUTFDD2LCRC_UTF8ERR   1                                   //~vau5I~
#define XEUTFDD2LC_REPERR      '?'      //f2l err replace on plh   //~vaubR~
//#ifdef LNX                                                         //~vau7I~//~vauER~
//int xeutfcvlf2ddAdjust(int Popt,char *Ppu8,int Pu8len,char *Pct,int Plclen,//~vaumR~
int xeutfcvlf2ddAdjust(int Popt,char *Ppu8,int Pu8len,char *Plc,char *Pct,int Plclen,//~vaumI~
					char *Pdddata,char *Pdddbcs,char *Pddct,int Pbuffsz,int *Ppddlen);//~vau7R~
#define XEUTFCVLF2DAO_CHKERRREP  0x01   //chk already adjusted sign and set rc=2//~vaumI~
//#endif                                                             //~vau7I~//~vauER~
#endif //UTF8SUPPH                                                 //~va00R~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	int xeutf_cvlf2lbyctDDW(int Popt,char *Pinp,int Pinplen,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen);//~vaubI~
#endif                                                             //~vaubI~
int xeutfgetmixstrctopt(int Popt,PUFILEH Ppfh);                    //~vawpI~
