//*CID://+v6E1R~:                             update#=  318;       //~v6E1R~
//******************************************************           //~v5n3R~
//v6E1:160718 (W32)WideCharToMultiByte dose not set err            //~v6E1I~
//            cv F8F0->a0,F8F1->fd,F8F2->fe,F8F3->ff and it is reversible//~v6E1I~
//            not by v6E0 but chk reversible by MB_ERR_INVALID_CHARS//~v6E1I~
//v6BA:160303 W32:wcstombs and mbrtowc dose not support surrogate pair,use WIdeChar<-->Multibute api//~v6BAI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6x9:150111 xeebc.map duplicate parameter chk for CONVERTER      //~v6x5I~
//v6x5:150108 ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6m2:130725 (BUG)EBC2ASC_IBM(x20) and UCVEXTO_TOUTF8 conflict occured//~v6m2I~
//            xprint ucvebc3_b2m translate to utf8 when no cfg found(default IBM option)//~v6m2I~
//            IBM/NEC is for the case of using internal mapp       //~v6m2I~
//v6hA:120822 (BUG)EBC handle subchar was not used for subcharchk  //~v6hAI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6fp:120506 (BUG)ICU subchar len for pconverters                 //~v6fpI~
//v6fe:120427 (BUG)"open err" when -Yi and default is set to ISO-8859-1(go to iconvgetconvertertype)//~v6feI~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6bo:111214 putenv/setenv is not effective for ICU dll;use u_setDataDirectory()//~v6boI~
//v6bm:111214 for xcv;-ICU option alternative for -mf:mapfile      //~v6bmI~
//v6bj:111212 for XCV;F2B/B2F support                              //~v6bjI~
//v6ba:111208 (ARM)icu support                                     //~v6baI~
//v69w:100908 for xprint,cfg err exit                              //~v69wI~
//v69s:100903 (BUG)xcv m2m trans to utf8(v66k but a2a calls not icuucs2local1 but iconvucvs2local1)//~v69sI~
//v69p:100902 (EBC)for xcv:handle support                          //~v69pI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v69d:100815 split ucvext                                         //~v69dI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v68c:100623 set default when cfg parm err                        //~v68cI~
//v66Y:100614 (LNX)dbcsenv for local converter to allow b2m output is dbcs//~v66YI~
//v66C:100604 use converters native subchar if no subchar was specified on cfg//~v66CI~
//v66D:100604 indicate SUBCHAR was set by rc                       //~v66DI~
//v66A:100602 hankana is 2byte ebc sbcs                            //~v66AI~
//v66z:100602 U-FFFd is standard replacement char of ICU           //~v66xI~
//v66x:100602 for cv cmd:apply -SBCS,ANK option from cmd option    //~v66xI~
//v66r:100530 add fallback option for icu.  2 ucs<-->1 mb case, mb->normal and fallback pattern//~v660I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v62V:091102_a2a GB180 & EUC consideration                        //~v62VI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62E:091003_(WIN)f2l support errret for WideToMultiByte          //~v62EI~
//v621:090511 add ucvext_a2ainit                                   //~v621I~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n7:080913*(Lnx)support UTF8 /f: of m2m                         //~v5n7I~
//v5n3:080904 cv cmd m2m support                                   //~v5n3I~
//v5n2:080824 Linux ICU spoort                                     //~v5n2I~
//v5n1:080822 (EBC)offer translation by Windows API MultiByteToWideChar//~v5n1I~
//v5mV:080819 DBCS uplaod SOSI option                              //~v5mVI~
//v5mU:080818 CP930/CP939 EBCS translation option support(IBM/NEC/NEW/OLD)//~v5mUI~
//v5mT:080817 EBCS translation for linux using iconv               //~v5mTI~
//v5mP:080805 EBC translation by ICU for 3270
//******************************************************
//*ucvext.h
//******************************************************
//#define DLHANDLE ULONG //void*                                     //~v6baR~//~v6hhR~
#define DLHANDLE ULPTR //void*                                     //~v6hhI~
#define ICU_DEFAULT_CHARSET "US-ASCII"                             //~v6f3I~
#ifdef WCSUPP
//******************************************************           //~v5n8I~
#define  HICONV_CPTO        0     //index for cpto   of m2m        //~v5n8M~
#define  HICONV_CPFROM      1     //index for cpfrom of m2m        //~v5n8M~
#define  HICONV_DBCSSTARTER 2     //index for dbcstbl of cpfrom of m2m//~v5n8M~
#define  HICONV_SUBCHTO     3     //subchar of cpto                //~v6f2R~//~v6f4I~
#define  HICONV_SUBCHFROM   4     //subchar of cpfrom              //~v6f2R~//~v6f4I~
#define  HICONV_CLOSETO     5     //should close at end            //~v6f4I~
#define  HICONV_CLOSEFROM   6     //should close at end            //~v6f4I~
//#define  ICU_STD_SUBCHAR_UCS 0xfffd //icu standard subchar for 2U trans err//~v66xI~//~v66DR~
//******************************************************           //~v6f7I~
#define  ICULCPL_CONVERTER  0    //ICU converters parameter index:Uconverter*//~v6f7R~
#define  ICULCPL_SUBCH      1    //pointer to Subchar string       //~v6f7R~
//#define  ICULCPL_SUBCHLEN   2    //pointer to Subchar string     //~v6fpR~
//******************************************************
//for Sextflag                                                     //~v5mTI~
#define SEXTF_SBCSMAP    0x01   //saved sbcsmap                    //~v5mTM~
#define SEXTF_SBCSMAPC   0x02   //saved comprementary map          //~v5mTM~
#define SEXTF_SBCSMAPA2A 0x04   //ascii-ascii mapping              //~v5mTM~
#define SEXTF_DBCSSTART  0x08   //dbcs start byte saved for the converter//~v5mTM~
#define SEXTF_REPLF      0x10   //replace 0x0a by subchar when e2a //~v5mTM~
#define SEXTF_NOS2D      0x20   //replace by subchar when SBCS output is dbcs when E2A//~v5mTM~
#define SEXTF_ICU        0x40   //converter is ICU                 //~v5n2I~
#define SEXTF_ICUFB      0x80   //fallback icu                     //~v660I~
#define SEXTF_NOICULOCAL 0x0100 //local converter is not icu       //~v66CI~
#define SEXTF_LIBOPENED  0x0200 //iculib opened                    //~v69dI~
#define IS_ICULIBOPENED()      (Sextflag & SEXTF_LIBOPENED)   //iculib opened//~v69dR~
#define IS_ICUMODE()  (Sextflag & SEXTF_ICU)                       //~v5n1R~
#define IS_NATIVELOCALMODE()   (Sextflag & SEXTF_NOICULOCAL)       //~v66CR~
#define IS_ICULOCALMODE()      (IS_ICUMODE() && !IS_NATIVELOCALMODE())//~v66CR~
#define IS_NATIVE_LOCALCV(opt) (IS_NATIVELOCALMODE() && (opt & UCEIO_LOCALCV))//~v66CR~
#define IS_ICU_CONVERTER(opt)  (IS_ICUMODE() && !IS_NATIVE_LOCALCV(opt))//~v66CR~
//#define IS_ICU_CONVERTER_OR_MBLOCAL(opt)  (IS_ICU_CONVERTER(opt)||(opt & (UCEIO_MBICU|UCEIO_LOCALICU)))//~v6f3R~//~v6f4R~//~v6f3R~
#define IS_ICU_CONVERTER_OR_MBLOCAL(opt)  \
		(	IS_ICU_CONVERTER(opt)                      /*ICU mode by xeebc.map*/\
		||	(opt & (UCEIO_MBICU|UCEIO_LOCALICU))       /*explicit ICU request to icugetstarter from udbcschk*/\
		||	((opt & UCEIO_LOCALCV) && UDBCSCHK_IS_LOCALICU())  /*emcmap is iconv mode but LOCAL ICU mode was setup by -Yi*/\
        )                                                          //~v6f3I~
#define IS_ICULOCALMODE_OR_MBLOCAL() /*for icugetconverter*/ \
		(	IS_ICULOCALMODE()      	/*for EBCDIC conversion*/ \
		||	UDBCSCHK_IS_LOCALICU()  /*emcmap is iconv mode but LOCAL ICU mode was setup by -Yi*/ \
        )                                                          //~v6f3I~
#define IS_MBICU(opt) (opt & UCVEXTO_MBICU)                        //~v6f4I~

#define UCEIO_USEICU         0x0001 //set use icu flag
#define UCEIO_GETCONVERTER   0x0002 //initialize onverter handle
#define UCEIO_NOERRMSG       0x0004 //skip errmsg issue
#define UCEIO_OPENED         0x0008 //UConverter parm is opened ,else parm is convertername
#define UCEIO_DBCSCV         0x0010 //save EBC converter SBCS
#define UCEIO_SBCSCV         0x0020 //save EBC converter SBCS
#define UCEIO_LOCALCV        0x0040 //save EBC converter SBCS
#define UCEIO_SBCSMAP        0x0080 //get conveter parm is sbcs map
#define UCEIO_SBCSMAPC       0x0100 //map is comlementary map
#define UCEIO_SBCSMAPA2A     0x0200 //A2F/F2A map
#define UCEIO_MAPISA2E       0x0400 //a2e map
#define UCEIO_SAVECV         0x0800 //save EBC converter DBCS
#define UCEIO_SAVEMAP        0x1000 //save map addr
#define UCEIO_CHKSTATEFULEBC 0x2000 //warning ebcdic is not statefull
//#define UCEIO_DEFLOCALCV     0x4000 //default windows cp for localcv//~v66CI~//~v6baR~
#define UCEIO_ERREXIT        0x8000 //uerrexit by cfg err          //~v69wI~
                                                                   //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
#define UCEIO_LOCALEDIT      0x4000 //local ebcdic trans support for xe//~v660I~
#endif                                                             //~v660I~
#define UCEIO_LOCALICU     0x010000 //local icu init               //~v6f3I~//~v6f4R~
#define UCEIO_MBICU        0x020000 //m2m icu                      //~v6f4I~
#define UCEIO_OPENICU      0x040000 //ICU specific function        //~v6feI~
                                                                   //~v5mVI~
#define UCEIRC_SBCS         0
#define UCEIRC_DBCS         1
#define UCEIRC_MBCS         2
#define UCEIRC_STATEFULEBC  3
#define UCEIRC_UTF8         4                                      //~v5n7I~

//* map definition file
//#define MAX_CSNAMESZ  60                                         //~v69cR~
//#define MAX_MBCSLEN    5  //from windows cplist ;moved to ulibdefu.h//~v62UR~
typedef struct _UCVEXTCFG {
                    int  UCECflag;
#define  UCECF_E2A             0x01        //MAP_E2A specified
#define  UCECF_A2E             0x02
#define  UCECF_F2A             0x04
#define  UCECF_A2F             0x08
#define  UCECF_SBCSDEF         0x10        //SBCS is by default(ISO-8859-1)
#define  UCECF_USE_ICU         0x20        //converter is ICU      //~v5n2I~
#define  UCECF_USE_CONVERTER   0x40        //use charset converter(no A2A)
#define  UCECF_USE_A2A         0x80        //use a2a mapping
#define  UCECF_DBCSCV        0x0100        //dbcs converter avail
#define  UCECF_SBCSCV        0x0200        //sbcs converter avail
#define  UCECF_LOCALCV       0x0400        //sbcs converter avail
#define  UCECF_SBCSMAP       0x0800      //sbcs is not by converter but internaly full mapping avail
#define  UCECF_USE_ICONV     0x1000      //CONVERTER is ICONV or MutiByteToWideChar//~v5n2I~
#define  UCECF_SBCSMAPC      0x2000      //sbcs adjust by A2E and E2A mapping
#define  UCECF_REPLF         0x4000      //replace 0x0a by subchar
#define  UCECF_NOS2D         0x8000      //replace 0x0a when SBCS output is DBCS
#define  UCECF_IBM         0x010000      //sjis option             //~v5mUI~
#define  UCECF_NEC         0x020000      //sjis option             //~v5mUI~
#define  UCECF_JIS78       0x040000      //sjis option             //~v5mUI~
#define  UCECF_JIS83       0x080000      //sjis option             //~v5mUI~
#define  UCECF_SOSISHIFT   0x100000      //a2e SOSI option shift   //~v5mVI~
#define  UCECF_SOSIREP     0x200000      //a2e SOSI option replace boundary space//~v5mVI~
#define  UCECF_SOSIINS     0x400000      //a2e SOSI option always insert//~v5mVI~
#define  UCECF_SOSIDEL     0x800000      //e2a SOSI option del     //~v5mVI~
#define  UCECF_SOSIREPSP 0x01000000      //e2a SOSI option rep by space//~v5mVI~
                                                                   //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
#define  UCECF_CP939     0x02000000      //use Japanese Eng ext    //~v660R~
#define  UCECF_CP930     0x04000000      //use Japanese Katakan Ext//~v660R~
#define  UCECF_OPENERR   0x08000000      //cfg open err            //~v660I~
#define  UCECF_ANK       0x10000000      //no CTL and no CRLF      //~v660I~
#define  UCECF_ICUFALLBACK  0x20000000   //use icu fallback mapping option//~v660I~
#define  UCECF_DEFLOCALCV   0x40000000   //use no icu default icu local converter//~v66CI~
#define  UCECF_DBCSLOCALCV  0x80000000   //local converter support dbcs//~v66YI~
#endif                                                             //~v660I~

#define UCECF_ISAVAIL_DBCSCV(pcfg) (pcfg!=0 && ((pcfg)->UCECflag & UCECF_DBCSCV)!=0)   //dbcs converter avail
#define UCECF_ISAVAIL_SBCSCV(pcfg) (pcfg!=0 && ((pcfg)->UCECflag & UCECF_SBCSCV)!=0)   //dbcs converter avail
#define UCECF_ISAVAIL_SBCSMAP(pcfg) (pcfg!=0 && ((pcfg)->UCECflag & UCECF_SBCSMAP)!=0)   //dbcs converter avail
#define UCECF_ISAVAIL_SBCSMAPC(pcfg) (pcfg!=0 && ((pcfg)->UCECflag & UCECF_SBCSMAPC)!=0)   //dbcs converter avail
#define UCECF_ISAVAIL_A2A(pcfg) (pcfg!=0 && ((pcfg)->UCECflag & UCECF_USE_A2A)!=0)   //dbcs converter avail
                    int  UCECflag2;                                //~v68cI~
#define  UCECF2_CFGOK          0x00000001      //cf has no err     //~v68cI~
#define  UCECF2_ICUDATA        0x00000002      //setenv was done for ICU_DATA//~v6boI~
#define  UCECF2_ICUINITEND     0x00000004      //icuinitend        //~v6f3I~
#define  UCECF2_CONVERTER_PARM 0x00000008      //for dup chk       //~v6x5R~
					USHORT UCECsubchardbcs;
					USHORT UCECsubcharsbcs;
					USHORT UCECsubchardefaultucsdbcs;   //windows cp info//~v66CI~
					USHORT UCECsubchardefaultucssbcs;   //windows cp info//~v66CI~
					USHORT UCECsubchardefaultucslocal;   //windows cp info//~v66CI~
//  				USHORT UCECsubchardefaultmbdbcs;   //windows cp info//~v66CI~//~v69cR~
//  				USHORT UCECsubchardefaultmbsbcs;   //windows cp info//~v66CI~//~v69cR~
					USHORT UCECsubchardefaultmblocal;   //windows cp info//~v66CI~
					char  UCECdllsuffix[8];
					char  UCECapisuffix[8];
					char  UCECcsnamedbcs[MAX_CSNAMESZ];
					char  UCECcsnamesbcs[MAX_CSNAMESZ];
					char  UCECcsnamelocal[MAX_CSNAMESZ];
//                  ULONG UCECconverterdbcs;                       //~v6x5R~
                    ULPTR UCECconverterdbcs;   //icu converter addr//~v6x5I~
//                  ULONG UCECconvertersbcs;                       //~v6x5R~
                    ULPTR UCECconvertersbcs;                       //~v6x5I~
//                  ULONG UCECconverterlocal;                      //~v6x5R~
                    ULPTR UCECconverterlocal;  //4 byte cp for win,but for unity with sbcs/dbcs//~v6x5I~
                    ULONG UCEChiconvdbcs[2];    //for linux,iconv_t To and From//~v5mTI~
                    ULONG UCEChiconvsbcs[2];    //for linux,iconv_t To and From//~v5mTI~
                    ULONG UCEChiconvlocal[2];   //for linux,iconv_t To and From//~v5mTI~
					char  UCECsbcsmape2a[256];
					char  UCECsbcsmapa2e[256];
					char  UCECsbcsmapf2a[256];
					char  UCECsbcsmapa2f[256];
					UCHAR UCECsubcharlocalsbcs;                    //~v66CI~
					UCHAR UCECsubcharebcsbcs;                      //~v66CI~
					UCHAR UCECsubcharlocaldbcs[MAX_MBCSLEN];       //~v66CI~
					UCHAR UCECsubcharebcdbcs[MAX_MBCSLEN];       //ebc dbcs space//~v66CI~
                   } UCVEXTCFG,*PUCVEXTCFG;
#define UCVEXTCFGSZ sizeof(UCVEXTCFG)

#define MB_MAXLINELEN 32760                                        //~v5n1M~
//for xcv                                                          //~v68hI~
#define MISC_K2L   0x01   //hankakukatakana-->lowe case            //~v68hI~
#define MISC_L2K   0x02   //hankakukatakana<--lowe case            //~v68hI~
#define MISC_M2M   0x04   //hankakukatakana<--lowe case            //~v68hI~
#define MISC_ASCEOL  0x08   //ascii eol option for ebc file        //~v68hI~
#define MISC_HANDLE  0x10   //converter parm is handle             //~v69pI~
#define MISC_B2B     0x20   //b2b of xcv                           //~v69sI~
#define MISC_UTF8    0x40   //F2B/B2F                              //~v6bjI~
#define MISC_ICU     0x80   //use icu for the case missing -mf:mapfile//~v6bmI~
//******************************************************
int ucvext_mapinit(int Popt,char *Pcfgfnm,PUCVEXTCFG *Ppcfg);
//******************************************************
int ucvext_getcfg(int Popt,char *Pcfgfnm,PUCVEXTCFG Ppcvextcfg);
//******************************************************
//int ucvext_icuinit(int Popt,char *Pdllversion,char *Pprocversion,ULONG *Papis);//~v6x5R~
int ucvext_icuinit(int Popt,char *Pdllversion,char *Pprocversion,ULPTR *Papis);//~v6x5I~
//******************************************************
//int ucvext_icuebc2mbs(int Popt,ULONG *Pconverter,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v6hhR~
int ucvext_icuebc2mbs(int Popt,ULPTR *Pconverter,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v6hhI~
					UCHAR *Pout,int *Ppoutlen,int Perrrep);
//******************************************************
//int ucvext_icumb2ebcs(int Popt,ULONG *Pconverter,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v6hhR~
int ucvext_icumb2ebcs(int Popt,ULPTR *Pconverter,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v6hhI~
					UCHAR *Pout,int *Poutlen,int Prepchar);
//******************************************************           //~v69cI~
int ucvext_icuebc2mbs_handle(int Popt,int Phandle,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v69cI~
					UCHAR *Pout,int *Ppoutlen,int Perrrep);        //~v69cI~
//******************************************************           //~v69cI~
int ucvext_icumb2ebcs_handle(int Popt,int Phandle,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,//~v69cI~
					UCHAR *Pout,int *Poutlen,int Prepchar);        //~v69cI~
//******************************************************
//int ucvext_icumb2ebcf(int Popt,ULONG *Pconverters,char *Pinpfilename,int Pmaxlinelen,char *Poutfilename,int Perrrep);//~v5mVR~//~v68hR~
//int ucvext_icumb2ebcf(int Popt,int Pmiscopt,ULONG *Pconverters,char *Pinpfilename,int Pmaxlinelen,char *Poutfilename,int Perrrep);//~v68hI~//~v6hhR~
int ucvext_icumb2ebcf(int Popt,int Pmiscopt,ULPTR *Pconverters,char *Pinpfilename,int Pmaxlinelen,char *Poutfilename,int Perrrep);//~v6hhI~
//******************************************************
//int ucvext_icugetconverter(int Popt,char *Pcharset,ULONG *Ppconverter);//~v6hhR~
int ucvext_icugetconverter(int Popt,char *Pcharset,ULPTR *Ppconverter);//~v6hhI~
//******************************************************
//int ucvext_icuebc2mbf(int Popt,ULONG *Pconverters,char *Pinpfilename,int Plrecl,char *Poutfilename,int Perrrep);//~v5mVR~//~v68hR~
//int ucvext_icuebc2mbf(int Popt,int Pmiscopt,ULONG *Pconverters,char *Pinpfilename,int Plrecl,char *Poutfilename,int Perrrep);//~v68hI~//~v6hhR~
int ucvext_icuebc2mbf(int Popt,int Pmiscopt,ULPTR *Pconverters,char *Pinpfilename,int Plrecl,char *Poutfilename,int Perrrep);//~v6hhI~
//******************************************************
//int ucvext_icugetstarter(int Popt,ULONG Pconverter,UCHAR *Pflags); //~v5n8R~//~v6hhR~
int ucvext_icugetstarter(int Popt,ULPTR Pconverter,UCHAR *Pflags); //~v6hhI~
//#ifdef W32                                                         //~v5mTI~//~v660R~
//******************************************************           //~v5mTI~
//	int ucvext_icugetconvertertype(int Popt,ULONG Pconverter,int *Pptype);//~v5mTI~//~v6hhR~
	int ucvext_icugetconvertertype(int Popt,ULPTR Pconverter,int *Pptype);//~v6hhI~
//******************************************************
//	int ucvext_icugetsubchars(int Popt,ULONG Pconverter,char *Psubchars,int *Ppoutlen);//~v5mTI~//~v6hhR~
	int ucvext_icugetsubchars(int Popt,ULPTR Pconverter,char *Psubchars,int *Ppoutlen);//~v6hhI~
//******************************************************
//	int ucvext_icusetsubchars(int Popt,ULONG Pconverter,char *Psubchars,int Plen);//~v5mTI~//~v6hhR~
	int ucvext_icusetsubchars(int Popt,ULPTR Pconverter,char *Psubchars,int Plen);//~v6hhI~
//******************************************************
//	int ucvext_icugetdefaultconvertername(int Popt,char *Pcharset,ULONG *Phiconv);//~v5mTI~//~v6f3R~//~v6hhR~
	int ucvext_icugetdefaultconvertername(int Popt,char *Pcharset,ULPTR *Phiconv);//~v6hhI~
//******************************************************
	int ucvext_icuenumcvname(int Popt,char *Pdllversion,char* Pprocversion);//~v5mTI~
//#endif                                                             //~v5mTI~//~v660R~
int ucvext_getcvoption(int Popt,PUCVEXTCFG Pcfg,int *Ppopt);       //~v5mVI~
#define UCEGCOO_CHKDBCS     0x01    //set EBC2ASC_DBCS etc         //~v5mVI~
#define UCEGCOO_IGNIBMNEC   0x02    //ignore IBM/NEC option of cfg file//~v5mVI~
#define UCEGCOO_IGNSOSI     0x04    //ignore SOSI    option of cfg file//~v5mVI~
#define UCEGCOO_IGNJIS7883  0x08    //ignore JIS78/JIS83 option of cfg file//~v5mVI~
#ifdef UTF8EBCD                                                    //~v660I~
#define UCEGCOO_IGNCP290    0x10    //set CP290(KANA-EXT) by CP930 //~v660R~
#define UCEGCOO_CTL         0x20    //set CTL by ANK               //~v660R~
#define UCEGCOO_IGNEUC      0x40    //ucvebc3 do not euc for b2dd  //~v660I~
#define UCEGCOO_FORCESBCS   0x80    //force SBCS by cv cmd option  //~v66xI~
#define UCEGCOO_FORCEANK    0x0100  //force ANK(no CTL) by cv cmd option//~v66xI~
#endif                                                             //~v660I~
//******************************************************           //~v5n1I~
//int ucvext_iconva2as(int Popt,ULONG *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,int Perrrep,int *Pprepctr);//~v5n3I~//~v6hhR~
int ucvext_iconva2as(int Popt,ULPTR *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,int Perrrep,int *Pprepctr);//~v6hhI~
//define UCVEXTO_TOUTF8          0x0100 //m2m to   UTF8            //~v5n8I~//~v69sR~
#define UCVEXTO_SETSUBCHRC       0x0010 //=EBC2ASC_NEC             //~v6f3I~
//#define UCVEXTO_TOUTF8           0x0020 //=EBC2ASC_IBM(not used when external conv case)//~v69sR~//~v6m2R~
#define UCVEXTO_B2B              0x0040 //=EBC2ASC_OLD(not used when external conv case)//~v69sI~
#define UCVEXTO_MBICU            0x0080 //=EBC2ASC_NEW(not used when external conv case)//~v6f4R~
#define UCVEXTO_ERRRET           0x0200 //return if err detected for ucvext_iconvucs2local1 =EBC2ASC_SOSI//~v62EI~
#define UCVEXTO_LNCONT           0x4000  //line continued to next=EBC2ASC_LNCONT//~v5n8I~
#define UCVEXTO_CHARLEN          0x8000  //for ucvext_local2ucs1;len parm is charlen(for EUC 3 byte DBCS)//~v5ntI~
#ifdef AAA                                                         //~v62VI~
#define UCVEXTO_FROMGB4        0x010000  //a2a from GB18030(=EBC2ASC_SOSISHIFT)//~v62VI~
#define UCVEXTO_FROMEUC        0x020000  //a2a from EUC(=EBC2ASC_EUC)//~v62VI~
#endif                                                             //~v62VI~
#define UCVEXTO_STAT_SO        0x200000 //DBCS                   =EBC2ASC_STAT_SO//~v5n8I~
#define UCVEXTO_FIXEDLRECL   0x02000000 //fixed lrecl            =EBC2ASC_FIXEDLRECL//~v5n8I~
#define UCVEXTO_SETEOL       0x08000000 //write EOL for x2B      =EBC2ASC_SETEOL//~v5n8I~
#define UCVEXTO_WINCPLIST    0x10000000 //list windows codepage if codepage parameter err =EBC2ASC_WINCPLIST//~v5n8I~
#define UCVEXTO_FROMUTF8     0x20000000 //m2m from UTF8            //~v5n8I~
#define UCVEXTO_PARMUCVEXT   0x40000000 //Popt bit is by UCVEXTOxxx not by EBC2ASC_xxx//~v5ntI~
                                                                   //~v66DI~
#define UCVEXTRC_SUBCH       -3        //rc of subchar was set     //~v66DI~
#define UCVEXTRC_HANKANA     -2        //hankana                   //~v66AI~
#define UCVEXTRC_ERRMSGISSUED  31                                  //~v69cI~
#define UCVEXTRC_BUFFOVF     -4                                    //~v6f3I~
#define UCVEXTRC_ERR         4                                     //~v6f3I~
                                                                   //~v6m2I~
#define UCVEXT_TOUTF8_ON()      Gucvebc_stat|=UCVEBCS_TOUTF8       //~v6m2I~
#define UCVEXT_TOUTF8_OFF()     Gucvebc_stat&=~UCVEBCS_TOUTF8      //~v6m2I~
#define UCVEXT_TOUTF8_CHKON()   (Gucvebc_stat & UCVEBCS_TOUTF8)!=0 //~v6m2I~
//******************************************************           //~v5n1I~
#ifdef UTF8SUPPH                                                   //~v621I~
//int ucvext_iconva2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULONG *Pconverters);//~v621I~//~v6hhR~
int ucvext_iconva2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULPTR *Pconverters);//~v6hhI~
#endif                                                             //~v621I~
int ucvext_iconva2af(int Popt,char *Pcpfrom,char *Pcpto,char *Pinpfilename,int Plen,char *Poutfilename,int Perrrep);//~v5n1I~
//******************************************************           //~v5n3I~
#ifdef W32                                                         //~v5n1I~
	int ucvext_listwincp(int Popt);                                //~v5n1I~
//	int ucvext_winucs2cp1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v5n8I~//~v6BjR~
  	int ucvext_winucs2cp1(int Popt,ULONG Pconverter,UWUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6BjI~
//  int ucvext_wincp2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs,int *Ppchklen);//~v5n8I~//~v6BjR~
    int ucvext_wincp2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs,int *Ppchklen);//~v6BjI~
	int ucvext_wincp2ucss(int Popt,ULONG Pconverter,UCHAR *Ppmbs,UCHAR *Ppdbcs,int Pinplen,WUCS *Ppucs,int Poutbufflen,int *Ppoutctr);//~v5n8I~
	int ucvext_getwincodepage(int Popt,char *Pcharset,ULONG *Pcp); //~v5n8I~
	int ucvext_MB2WC(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs,int *Ppmblen,int *Pplasterr);//~v6BAI~
#endif                                                             //~v5n1I~
//******************************************************           //~v5n8M~
#ifdef UTF8UCS4                                                    //~v65cI~
//	int ucvext_iconvucs2local1(int Popt,ULONG Pconverter,WUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5R~
	int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,WUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5I~
#else                                                              //~v65cI~
//int ucvext_iconvucs2local1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5R~
//int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6x5I~//~v6BjR~
int ucvext_iconvucs2local1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6BjI~
#endif                                                             //~v65cI~
//******************************************************           //~v5n8M~
#ifdef UTF8UCS4                                                    //~v65cI~
//  int ucvext_iconvlocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs);//~v6x5R~
    int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,WUCS *Ppucs);//~v6x5I~
#else                                                              //~v65cI~
//int ucvext_iconvlocal2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs);//~v6x5R~
//int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,USHORT *Ppucs);//~v6x5I~//~v6BjR~
int ucvext_iconvlocal2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS/*int4*/*Ppucs);//~v6BjI~
#endif                                                             //~v65cI~
#define UCEICL2U1ORC_DBCSSPLIT           -11                       //~v62VI~
                                                                   //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
//******************************************************           //~v660I~
//int ucvext_icuebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,USHORT *Ppucs);//~v66CR~
//int ucvext_icuebc2ucs1(int Popt,ULONG Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs);//~v66CI~//~v6hhR~
//int ucvext_icuebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,WUCS *Ppucs);//~v6hhI~//~v6BjR~
int ucvext_icuebc2ucs1(int Popt,ULPTR Pconverter,char *Ppebc,int Pinplen,UWUCS/*ucs4*/ *Ppucs);//~v6BjI~
//******************************************************           //~v660I~
//int ucvext_icuucs2ebc1(int Popt,ULONG Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v660I~//~v6hhR~
//int ucvext_icuucs2ebc1(int Popt,ULPTR Pconverter,USHORT Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v6hhI~//~v6BjR~
int ucvext_icuucs2ebc1(int Popt,ULPTR Pconverter,UWUCS Pucs,UCHAR *Ppebc,int *Ppoutlen);//~v6BjI~
//******************************************************           //~v660I~
//int ucvext_getparmconverter(int Popt,ULONG *Pconverters,ULONG *Pcvdbcs,ULONG *Pcvsbcs,ULONG *Pmapsbcs,ULONG *Pmapsbcsc,int *Ppopt);//~v660I~//~v6hhR~
int ucvext_getparmconverter(int Popt,ULPTR *Pconverters,ULPTR *Pcvdbcs,ULPTR *Pcvsbcs,ULPTR *Pmapsbcs,ULPTR *Pmapsbcsc,int *Ppopt);//~v6hhI~
//******************************************************           //~v660I~
//int ucvext_icumb2ebc1(int Popt,ULONG Pconverter,ULONG Psbcsmap,ULONG Psbcsmapc,UCHAR *Ppmbs,int Pinplen,UCHAR *Ppebc,int *Ppchklen,int *Ppoutlen,int Perrrep);//~v660I~//~v6hhR~
int ucvext_icumb2ebc1(int Popt,ULPTR Pconverter,ULPTR Psbcsmap,ULPTR Psbcsmapc,UCHAR *Ppmbs,int Pinplen,UCHAR *Ppebc,int *Ppchklen,int *Ppoutlen,int Perrrep);//~v6hhI~
//******************************************************           //~v660I~
//int ucvext_icuucs2local1wocv(int Popt,WUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v660I~//~v6BjR~
#ifdef AAA                                                         //~v6BjI~
int ucvext_icuucs2local1wocv(int Popt,UWUCS Pucs,UCHAR *Ppmbs,int *Ppoutlen);//~v6BjI~
#endif                                                             //~v6BjI~
//******************************************************           //~v69dI~
//int ucvext_icusubcharchk(int Popt,WUCS Pucs,UCHAR *Pstr,int Plen); //~v66DI~//~v69dI~//~v6BjR~
int ucvext_icusubcharchk(int Popt,UWUCS/*ucs4*/ Pucs,UCHAR *Pstr,int Plen);//~v6BjI~
#define UCVEXTISCO_MASK         0x0f                               //~v66DR~//~v69dI~
#define UCVEXTISCO_U2B         0x01                                //~v66DR~//~v69dI~
#define UCVEXTISCO_U2L         0x02                                //~v66DR~//~v69dI~
#define UCVEXTISCO_B2U         0x03                                //~v66DR~//~v69dI~
#define UCVEXTISCO_L2U         0x04                                //~v66DR~//~v69dI~
#define UCVEXTISCO_HANDLEMASK  0xff000000                          //~v6hAR~
#define UCVEXTISCO_HANDLEMASKSHIFT 24                              //~v6hAR~
//******************************************************           //~v69dI~
//int ucvext_openparmconverter(int Popt,ULONG *Pconverters,ULONG *Poutconverters,int *Ppopt);//~v69dI~//~v6hhR~
int ucvext_openparmconverter(int Popt,ULPTR *Pconverters,ULPTR *Poutconverters,int *Ppopt);//~v6hhI~
//******************************************************           //~v69dI~
int ucvext_isdbcs1st(int Popt,UCHAR Pch);                          //~v69dR~
//******************************************************           //~v69cI~
int ucvext_handle0init(int Popt,PUCVEXTCFG Ppcfg);                 //~v69cR~
#endif                                                             //~v660I~
                                                                   //~v660I~
//int ucvext_icuclose(int Popt,ULONG Pconverter);                    //~v6f4I~//~v6hhR~
int ucvext_icuclose(int Popt,ULPTR Pconverter);                    //~v6hhI~
//int ucvext_icureset(int Popt,ULONG Pconverter);                    //~v6f3I~//~v6hhR~
int ucvext_icureset(int Popt,ULPTR Pconverter);                    //~v6hhI~
//int ucvext_icugetmbconverter(int Popt,char *Pcharset,ULONG *Ppconverter);//~v6f3I~//~v6hhR~
int ucvext_icugetmbconverter(int Popt,char *Pcharset,ULPTR *Ppconverter);//~v6hhI~
//int ucvext_icumb2ucs1(int Popt,ULONG Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS *Ppucs);//~v6f3I~//~v6f7R~//~v6hhR~
int ucvext_icumb2ucs1(int Popt,ULPTR Pconverter,char *Ppmbs,int Pinplen,int *Ppchklen,UWUCS *Ppucs);//~v6hhI~
//int ucvext_icumb2utf1(int Popt,ULONG *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int *Ppreadlen,int *Ppoutlen);//~v6f3I~//~v6hhR~
int ucvext_icumb2utf1(int Popt,ULPTR *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int *Ppreadlen,int *Ppoutlen);//~v6hhI~
//int ucvext_icumb2utf(int Popt,ULONG *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int Prepch,//~v6f3I~//~v6hhR~
int ucvext_icumb2utf(int Popt,ULPTR *Pconverters,char *Ppmbs,int Pinplen,char *Pputf8,int Pbuffsz,int Prepch,//~v6hhI~
	int *Ppreadlen,int *Ppoutlen,int *Prepctr);                    //~v6f3I~
//int ucvext_icuucs2mb1(int Popt,ULONG *Pconverters,UWUCS Pucs,char *Ppmbs,int *Ppoutlen);//~v6f3R~//~v6f7R~//~v6hhR~
int ucvext_icuucs2mb1(int Popt,ULPTR *Pconverters,UWUCS Pucs,char *Ppmbs,int *Ppoutlen);//~v6hhI~
//int ucvext_icuutf2mb1(int Popt,ULONG Pconverter,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen);//~v6f3R~//~v6f7R~
//int ucvext_icuutf2mb1(int Popt,ULONG *Pconverters,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen);//~v6f7I~//~v6hhR~
int ucvext_icuutf2mb1(int Popt,ULPTR *Pconverters,char *Pputf8,int Pinplen,char *Ppmbs,int Pbuffsz,int *Ppreadlen,int *Ppoutlen);//~v6hhI~
//int ucvext_icuisprint(int Popt,ULONG Pconverter,int Pucs);         //~v6f3I~//~v6f7R~
//int ucvext_icuisprint(int Popt,ULONG *Pconverters,int Pucs);       //~v6f7I~//~v6hhR~
int ucvext_icuisprint(int Popt,ULPTR *Pconverters,int Pucs);       //~v6hhI~
//int ucvext_icumbinit(int Popt,char *Pcharset,ULONG *Phiconv);      //~v6f3I~//~v6hhR~
int ucvext_icumbinit(int Popt,char *Pcharset,ULPTR *Phiconv);      //~v6hhI~
#define UCEIMIO_ENVINIT     0x01  //init dll env                   //~v6f3I~
int ucvext_setdefaultlocale(int Popt,char *Pcharset);              //~v6f3I~
//int ucvext_locale1ICU(int Popt,ULONG Pconverter,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs);//~v6f3I~//~v6hhR~
int ucvext_locale1ICU(int Popt,ULPTR Pconverter,UCHAR *Pstr,int Plen,int *Ppreadlen,UWUCS *Ppucs);//~v6hhI~
//int ucvext_icua2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULONG *Pconverters);//~v6f4I~//~v6hhR~
int ucvext_icua2ainit(int Popt,char *Pcpfrom,char *Pcpto,UCHAR *Pdbcsflag,int *Ppopt,ULPTR *Pconverters);//~v6hhI~
//int ucvext_icua2as(int Popt,ULONG *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,ULONG Pferr,int Perrrep,int *Pprepctr);//~v6f4R~//~v6hhR~
int ucvext_icua2as(int Popt,ULPTR *Pconverters,UCHAR *Pinp,UCHAR *Ppdbcs,int Pinplen,UCHAR *Pout,int Poutbuffsz,int *Ppreadlen,int *Ppoutlen,ULPTR Pferr,int Perrrep,int *Pprepctr);//~v6hhR~
//int ucvext_icua2aterm(int Popt,ULONG *Pconverters);                //~v6f4R~//~v6hhR~
int ucvext_icua2aterm(int Popt,ULPTR *Pconverters);                //~v6hhI~
#endif	//WCSUPP                                                   //~v5n1R~
#ifdef W32                                                         //~v6BII~//~v6BHM~
int uMultiByteToWideChar(int Popt,ULONG Pconverter,int Papiopt,char *Ppebc,int Pinplen,WUCS/*ucs2*/ *Ppucs,size_t Pbuffsz,int *Pplasterr);//~v6BHM~
int uWideCharToMultiByte(int Popt,ULONG Pconverter,int Papiopt,WUCS/*int2*/*Ppucs,int Pucsctr,UCHAR *Ppmbs,size_t Pbuffsz,char *Pdefaultchars,int *Ppdefaultused,int *Pplasterr);//~v6BIR~//~v6BHR~
//#define UWCTMBO_SETSUBCHRC      0x01  //reverse chk              //+v6E1R~
#define UWCTMBO_REVERSECHK      0x02  //from reverse chk protect recursive//~v6E1I~
#endif                                                             //~v6BII~//~v6BHM~
