//*CID://+v6M5R~:                             update#=  323;       //+v6M5R~
//******************************************************           //~v57GI~
//v6M5:170825 for xcv,xprint;create EBC cfg by uconv output        //+v6M5I~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6m3:130726 for xprint, support -ICU without CFG parm file       //~v6m3I~
//v6m2:130725 (BUG)EBC2ASC_IBM(x20) and UCVEXTO_TOUTF8 conflict occured//~v6m2I~
//            xprint ucvebc3_b2m translate to utf8 when no cfg found(default IBM option)//~v6m2I~
//            IBM/NEC is for the case of using internal mapp       //~v6m2I~
//v6hw:120821 option to b2f/b2m to leave err rep by subchar        //~v6hwI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f4:120419 option to use ICU as M2M converter                   //~v6f4I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6bj:111212 for XCV;F2B/B2F support                              //~v6bjI~
//v6bh:111210 for XCV;serach ICU lib when no -mf: parm             //~v6bhI~
//v6bd:111209 change default map to cp37(contains ctl char) from c3270ftp when not xe3270//~v6bdI~
//v69y:100909 errrep option for xprint                             //~v69yI~
//v69w:100908 for xprint,cfg err exit                              //~v69wI~
//v69u:100903 b2b support for xcv(a2a is not proper for dbcs converter because dbcsstarter is null for ebc)//~v69uI~
//v69s:100903 (BUG)xcv m2m trans to utf8(v66k but a2a calls not icuucs2local1 but iconvucvs2local1)//~v69sI~
//v69k:100823 (EBC)aallow b2dd to output dbcs ucs for b2b cv       //~v69kI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v68b:100622 (BUG)v66U missing set dbcstbl for hankana expansion  //~v68bI~
//v68a:100622 SOSI option for gxe C&P,chk cfg                      //~v68aI~
//v689:100620 accept SOSI cmd option                               //~v687I~
//v687:100619 f2b support(utf8 to ebc)                             //~v687I~
//v686:100619 REPNUL option to b2dd                                //~v686I~
//v66X:100614 (LNX)CN-EBCDIC(CP935) si 2 byte dbcs only but local may be 4 byte dbcs for under GB18030(ex.u-81-x81308131)//~v66XI~
//v66U:100613 (LNX)allow b2a expand sbcs->dbcs for EUC hankana(katakana -->8exx under EUC-J)//~v66UI~
//v66N:100611 ebc-b9->u178 is err if reverse chk,allow not reversible for b2u//~v66LI~
//v66L:100610 update ctl char trans table(and EBC_LF is 0x25<-->u-000a)//~v66LI~
//v66D:100604 indicate SUBCHAR was set by rc                       //~v66DI~
//v66g:100523 rep SO/SI to "?" as printable for xpr                //~v66gI~
//v66f:100522 add ebcdic cv dbcs err ch function                   //~v66fI~
//v66a:100519 drop SO/SI option for B2M(and B2DD)                  //~v66aI~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5n7:080913*(Lnx)support UTF8 /f: of m2m                         //~v5n7I~
//v5mY:080821 SETEOL option to write EOL for m2b s2b a2b           //~v5mYI~
//v5mW:080819 xcv cmd support                                      //~v5mWI~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5mE:080625 EBC<->EUC conversion support                         //~v5mEI~
//v5mC:080624 sjis->ebc conversion;SO/SO shift option(drop following space if SO/SI inserted)//~v5mCI~
//v5eq:041030 ebc<-->sjis:CP290 option(katakana extended)          //~v5eqI~
//v5ep:041030 (BUG)ebc<-->sjis:ebc "?" should be 0x6f (not 3f)     //~v5epI~
//v5em:041026 ebc<-->sjis chkprint also sbcs tbl                   //~v5emI~
//v5ek:041026 ebc<-->sjis dbcs support;option of asume SO top of line//~v5ekI~
//v5ej:041023 ebc<-->sjis dbcs support;delete rep any char by so/si//~v5eiI~
//v5ei:041023 ebc<-->sjis dbcs support;xe cont line support        //~v5eiI~
//v5eh:041023 ebc<-->sjis dbcs support;length chk option(before set conversion out)//~v5ehI~
//v5eg:041023 ebc<-->sjis dbcs support;sosi isrt/del/rep option support//~v5egI~
//v5ef:041023 ebc<-->sjis dbcs support,dbcs errrep char support    //~v5efI~
//v5ed:041020 ebc<-->sjis dbcs support                             //~v5edI~
//v57V:030727 conv ascii<->ebc ctl char option                     //~v57SI~
//v57U:030726 conv ascii-->ebc(CP1027âpè¨ï∂éöägí£)                 //~v57SI~
//v57S:030726 hankaku katakana<-->alphabet small letter conversion //~v57SI~
//v57G:030607 for EBCDIC-->ASCII conversion                        //~v57GI~
//******************************************************           //~v57GI~
#ifdef UTF8EBCD                                                    //~v660I~
	#ifdef  GLOBAL_EBC                                             //~v660I~
  		#define EXT_EBC                                            //~v660I~
  		#define INIT_EBC(value) =value                             //~v660I~
	#else                                                          //~v660I~
  		#define EXT_EBC extern                                     //~v660I~
  		#define INIT_EBC(value)                                    //~v660I~
	#endif                                                         //~v660I~
                                                                   //~v69cR~
//  EXT_EBC int   Gucvebc_stat;                                    //~v660I~//~v69cR~
//  #define UCVEBCS_SBCSMAPINIT   0x01 //sbcsmap was initialized   //~v660I~//~v69cR~
    EXT_EBC int   Gucvebc_stat;                                    //~v6bdI~
    #define UCVEBCS_3270FTP       0x01 //on xe3270 process         //~v6bdI~
    #define UCVEBCS_xcv           0x02 //on xcv    process         //~v6bhI~
    #define UCVEBCS_TOUTF8        0x04 //parm to ucvext_iconvucs2local1//~v6m2I~
    #define UCVEBCS_icutool       0x08 //tool to use ICU           //~v6m3I~
    #define UCVEBCS_CONVERTERCFG  0x10 //create cfg by uconv --version//+v6M5I~
                                                                   //~v660I~
//  EXT_EBC UCHAR Gucvebc_toupper[256];                            //~v660R~//~v69cR~
//  #define EBC_toupper(ch) ((int)Gucvebc_toupper[(int)(ch)])      //~v660R~//~v69cR~
//  EXT_EBC UCHAR Gucvebc_tolower[256];                            //~v660I~//~v69cR~
//  #define EBC_tolower(ch) ((int)Gucvebc_tolower[(int)(ch)])      //~v660R~//~v69cR~
//  EXT_EBC UCHAR Gucvebc_a2bmap[256];    //ascii->ebc map for sbcs//~v660I~//~v69cR~
//  #define EBC_A2B(ch) (Gucvebc_a2bmap[(int)(ch)])                //~v660R~//~v69cR~
//	EXT_EBC UCHAR Gucvebc_b2amap[256];    //ascii->ebc map for sbcs//~v66UR~
// 	EXT_EBC USHORT Gucvebc_b2amap[256];   //ascii->ebc map for sbcs,2 byte for euchankana//~v66XR~
// 	EXT_EBC ULONG  Gucvebc_b2amap[256];   //ascii->ebc map for sbcs,2 byte for euchankana//~v66XI~//~v69cR~
//  #define EBC_B2A(ch) (Gucvebc_b2amap[(int)(ch)])                //~v660R~//~v69cR~
//  #define EBC_B2A_ISDBCS(ch) (EBC_B2A(ch) & 0xff00)              //~v66UI~//~v69cR~
                                                                   //~v66UI~
//  EXT_EBC UCHAR Gucvebc_ctype[256];                              //~v660I~//~v69cR~
//  #define EBCTYPE_LOWER       0x01                               //~v660I~//~v69cR~
//  #define EBCTYPE_UPPER       0x02                               //~v660I~//~v69cR~
//  #define EBCTYPE_ALPHA       0x03                               //~v660I~//~v69cR~
//  #define EBCTYPE_NUM         0x04                               //~v660I~//~v69cR~
//  #define EBCTYPE_DBCS        0x08                               //~v66UR~//~v69cR~
//  #define EBCTYPE_SS3         0x10                               //~v66XI~//~v69cR~
//  #define EBCTYPE_GB4         0x20                               //~v66XI~//~v69cR~
                                                                   //~v66UI~
//  #define EBC_B2A_TYPEISDBCS(ch) (Gucvebc_ctype[(int)(ch)] & EBCTYPE_DBCS)//~v66XR~//~v69cR~
//  #define EBC_B2A_TYPEISSS3(ch)  (Gucvebc_ctype[(int)(ch)] & EBCTYPE_SS3)//~v66XR~//~v69cR~
//  #define EBC_B2A_TYPEISGB4(ch)  (Gucvebc_ctype[(int)(ch)] & EBCTYPE_GB4)//~v66XR~//~v69cR~
                                                                   //~v660I~
#endif                                                             //~v660I~
#define CHAR_SO    0x0e    //shift out                             //~v5edI~
#define CHAR_SI    0x0f    //shift in                              //~v5edI~
#define CHAR_EBC_SPACE   0x40    //ebcdic space                    //~v5eiI~
#define CHAR_EBC_ERR     0x6f    //ebcdic "?"                      //~v5epI~
#ifdef UTF8EBCD                                                    //~v660I~
	#define CHAR_DBCS_ERR  		0x8148   //DBCS "?"                //~v660I~
	#define CHAR_UCS_DBCS_ERR  	0xFF1F   //UCS zenkaku "?"         //~v660I~
	#define CHAR_UCS_DBCS_ERR2 	0x3000   //UCS zenkaku " "         //~v660I~
	#define CHAR_EBC_ERR_DBCS   0x426f   //ebcdic DBCS "?"         //~v660I~
	#define CHAR_UCS_SUB        0x1a    //SUB(substitution char)   //~v660R~
	#define CHAR_EBC_SUB        0x3f    //SUB(substitution char)   //~v660I~
	#define CHAR_EBC_DBCS_SPACE  0x4040    //ebcdic DBCS space     //~v660I~
	#define CHAR_EBC_ACK        0x2e       //ebcdic ACK            //~v66gI~
	#define CHAR_UCS_ACK        0x06       //ucs  ACK              //~v66gR~
                                                                   //~v660I~
    #define CHAR_EBC_0         0xf0                                //~v660I~
    #define CHAR_EBC_1         0xf1                                //~v660I~
    #define CHAR_EBC_2         0xf2                                //~v660I~
    #define CHAR_EBC_3         0xf3                                //~v660I~
    #define CHAR_EBC_4         0xf4                                //~v660I~
    #define CHAR_EBC_5         0xf5                                //~v660I~
    #define CHAR_EBC_6         0xf6                                //~v660I~
    #define CHAR_EBC_7         0xf7                                //~v660I~
    #define CHAR_EBC_8         0xf8                                //~v660I~
    #define CHAR_EBC_9         0xf9                                //~v660I~
    #define CHAR_EBC_PLUS      0x4e    //"+"                       //~v660I~
    #define CHAR_EBC_MINUS     0x60    //"-"                       //~v660I~
    #define CHAR_EBC_A         0xc1    //"-"                       //~v660I~
    #define CHAR_EBC_F         0xc6    //"-"                       //~v660I~
//  #define CHAR_EBC_a         Gucvebc_tolower[CHAR_EBC_A]         //~v660R~//~v69cR~
    #define CHAR_EBC_a         Gucvebch[0].UCVEHtolower[CHAR_EBC_A]//~v69cI~
//  #define CHAR_EBC_f         Gucvebc_tolower[CHAR_EBC_F]         //~v660R~//~v69cR~
    #define CHAR_EBC_f         Gucvebch[0].UCVEHtolower[CHAR_EBC_F]//~v69cI~
                                                                   //~v660I~
    #define EBC_ISNUMERIC(ch)  ((ch)>=CHAR_EBC_0 && (ch)<=CHAR_EBC_9)//~v660I~
#else                                                              //~v660I~
#define CHAR_EBC_ERR_DBCS  0x4040    //ebcdic DBCS space           //~v660I~
#endif                                                             //~v660I~
#define CHAR_ASCII_ERR   '?'     //ebcdic "?"                      //~v5mPI~
#define EBC_CR   0x0d                                              //~v5mPI~
#define EBC_NL   0x15         //for ufile5                         //~v5mPI~//~v66LR~
#define EBC_NL_STR "\x15"                                          //~v68hI~
#define EBC_LF   0x25                                              //~v66LI~
#define EBC_TAB  0x05         //HT                                 //~v660I~
#define EBC_PERIOD 0x4b                                            //~v5mPI~
#define EBC_DEFAULT_LRECL 80                                       //~v5mWI~
                                                                   //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
#define EBCID_ENGEXT      "ENG_EXT"        //CP939=CP1027(EnglishExt)+CP300//~v660R~
#define EBCID_KANAEXT     "KANA_EXT"       //CP930=CP290(katakanaExt)+CP300//~v660R~
#endif                                                             //~v660I~
//******************************************************           //~v5edI~
unsigned char *ucvebc_gettrte2a(void);                             //~v57GI~
void ucvebcinita2e(int Popt);                                      //~v660I~
//*******************************************************          //~v57GI~
int ucvebc2asc_handle(int Popt,int Phandle,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v69cI~
               unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v69cI~
int ucvasc2ebc_handle(int Popt,int Phandle,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v69cI~
				unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v69cI~
//int ucvebc_2asc(int Popt,unsigned char *Pibuff,unsigned char *Pobuff,int Plen);//~v57SR~
//int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,UCHAR Prepchar);//~v5efR~
//int ucvasc2ebc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,UCHAR Prepchar);//~v5efR~
//int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,int Prepchar);//~v5eiR~
//int ucvasc2ebc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,int Prepchar);//~v5eiR~
int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v5eiI~
               unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen);//~v5eiI~
int ucvasc2ebc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v5eiI~
				unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen);//~v5eiR~
#define EBC2ASC_CRLF   0x01                                        //~v57GI~
#define EBC2ASC_A2E    0x02    	//ascii-->ebc                      //~v57SI~
#define EBC2ASC_CTL    0x04    	//ctl char conv                    //~v57SI~
#define EBC2ASC_CP290  0x08    	//ebc2asc use cp290(not cp1027)    //~v5eqI~
                                 //290 katakana ext                //~v660I~
#define EBC2ASC_NEC      0x10    //dbcs map to nec area            //~v5edR~
#define EBC2ASC_EXT_SETSUBCHRC    0x10    //set return code "subchar was set"//~v66DI~
#define EBC2ASC_IBM      0x20    //dbcs map to ibm area            //~v5edR~
//#define EBC2ASC_EXT_TOUTF8        0x20    //reserved for UCVEXTO_TOUTF8//~v69sI~//~v6m2R~
#define EBC2ASC_OLD      0x40    //oldjis(78) seq                  //~v5edR~
#define EBC2ASC_EXT_B2B           0x40    //reserved for UCVEXTO_B2B//~v69uI~
#define EBC2ASC_NEW      0x80    //newjis(83) seq                  //~v5edR~
#define EBC2ASC_EXT_MBICU 0x80    //reserved for UCVEXTO_MBICU     //~v6f4R~
#define EBC2ASC_DBCS   0x0100     //newjis(83) seq                 //~v5edI~
#define EBC2ASC_SOSI   0x0200     //default;isrt(a2e),rep by space(e2a)//~v5eiR~
#define EBC2ASC_SOSIAS 0x0400     //asume so before the line top(e2a)//~v5ekR~
#define EBC2ASC_SOSID  0x0800     //del sosi(e2a/a2e)              //~v5eiI~
#define EBC2ASC_SOSIOS 0x1000     //override boundary space(a2e)   //~v5ekR~
#define EBC2ASC_BUFTOP 0x2000     //previous byte can not be rep by SO for a2e//~v5egR~
#define EBC2ASC_LNCONT 0x4000     //line continued to next         //~v5eiR~
#define EBC2ASC_SOCONT 0x8000     //SO status continuing           //~v5eiR~
#define EBC2ASC_SOSISHIFT  0x010000  //(a2e)override boundary space,insert if no space,borrow from following string//~v5mCI~
#define EBC2ASC_EUC        0x020000  //EUC conversion              //~v5mEI~
#ifdef WCSUPP                                                      //~v5mPR~
	#define EBC2ASC_EXT        0x040000 //translate using ICU/iconv//~v5mPI~
	#define EBC2ASC_SBCSMAP    0x080000 //convert sbcs not by icu but mapping tbl//~v5mPI~
	#define EBC2ASC_OPENEDCV   0x100000 //converter is opened already//~v5mPI~
	#define EBC2ASC_STAT_SO    0x200000 //SO effective             //~v5mPI~
	#define EBC2ASC_SBCSMAPC   0x400000 //complementary map(apply map to only specified codepoint)//~v5mPR~
	#define EBC2ASC_LOCALCV    0x800000 //use local converter      //~v5mPR~
#endif                                                             //~v5mPM~
#define EBC2ASC_SBCSMAPA2A   0x01000000 //A2F and F2A              //~v5mPR~
#define EBC2ASC_FIXEDLRECL   0x02000000 //EBC is fixed lrecl       //~v5mWI~
#define EBC2ASC_NUMSTD       0x04000000 //EBC is fixed lrecl and numstd//~v5mWI~
#define EBC2ASC_SETEOL       0x08000000 //write EOL for x2B        //~v5mYI~
#define EBC2ASC_WINCPLIST    0x10000000 //list windows codepage if codepage parameter err//~v5mYI~
//#define EBC2ASC_FROMUTF8     0x20000000 //m2m from UTF8          //~v5n7R~
#define EBC2ASC_FROMUTF8     0x20000000 //=UCVEXTO_FROMUTF8(m2m from UTF8)//~v69kI~
#ifdef UTF8EBCD                                                    //~v660I~
//#define EBC2ASC_LOCALEDIT    0x20000000 //locale ebc file edit     //~v660I~//~v69kR~
#endif                                                             //~v660I~
#define EBC2ASC_PARMUCVEXT   0x40000000 //opt parm bit have to be evaluated by UCVEXTO_xxx//~v5ntR~
                                                                   //~v5eiI~
#define EBC2ASC_RC_ERRREP    0x01                                  //~v5eiM~
#define EBC2ASC_RC_HANKANA   0x02                                  //~v66gI~
#define EBC2ASC_RC_HALFBYTE  0x04                                  //~v5eiM~
#define EBC2ASC_RC_ISRTSO    0x08   //SO inserted because rep not avail//~v5eiM~
#define EBC2ASC_RC_ISRTSI    0x10   //SI inserted because rep not avail//~v5eiM~
#define EBC2ASC_RC_SIPEND    0x20   //SI set pending by end of line of continuening line//~v5eiR~
#define EBC2ASC_RC_DBCSFOUND 0x40   //line has dbcs                //~v5eiI~
#define EBC2ASC_RC_ISRTTOPSO 0x80   //SO is inserted to top of line//~v5eiR~
//*******************************************************          //~v57SI~
int ucvkandl(int Popt,unsigned char *Pibuff,unsigned char *Pobuff,int Plen);//~v57SR~
#define KANDL_K2L      0x01                                        //~v57SI~
#define KANDL_RC_DBCSSPLIT   -1    //for conv;last is dbcs 1st byte only//~v57SI~
#define KANDL_RC_WILLCONV    -2    //for chk only;exist char to be converted//~v57SI~
//*******************************************************          //~v5emI~
int ucvebc2_chkprintsbcs(int Popt,int Prepchar);                   //~v5emR~
                                                                   //~v660I~
//*******************                                              //~v660I~
#ifdef UTF8EBCD  //**                                              //~v660I~
//*******************                                              //~v660I~
	#define UCVEBC_ISDBCS(dbcsid)   \
			( UDBCSCHK_DBCS1STL(dbcsid)||UDBCSCHK_DBCS2NDL(dbcsid) )//~v660I~
	#define UCVEBC_ISSPACE(datach,dbcsid) \
                ( (datach)==CHAR_EBC_SPACE && (dbcsid)==0 )        //~v660R~
	#define UCVEBC_eqspace(swebc,datach,dbcsid) /*use for not utf8 file*/\
		(   (swebc) ? UCVEBC_ISSPACE(datach,dbcsid) \
                 :  ((detach)==' ') \
        )                                                          //~v660I~
	#define UCVEBC_eqtab(swebc,dbcsid) /*use for not utf8 file*/\
		(   (swebc) ? 0 \
                 :  ((dbcsid)==UDBCSCHK_TABCHAR) \
        )                                                          //~v660I~
	#define UCVEBCUTF_eqspace(swebc,swutf,datach,dbcsid) \
		(   (swebc) ? UCVEBC_ISSPACE(datach,dbcsid) \
                 : ( UTF_eqspace(swutf,datach,dbcsid) ) \
        )                                                          //~v660I~
	#define UCVEBCUTF_eqspacetab(swebc,swutf,datach,dbcsid) \
		(   (swebc) ? UCVEBC_ISSPACE(datach,dbcsid) \
                 : ( UTF_eqspacetab(swutf,datach,dbcsid) ) \
        )                                                          //~v660I~
	#define UCVEBC_ISNOTSPACE(datach,dbcsid) \
				(!UCVEBC_ISSPACE(datach,dbcsid))                   //~v660R~
	#define UCVEBC_nespace(swebc,datach,dbcsid) \
				(!UCVEBC_eqspace(swebc,datach,dbcsid))             //~v660I~
	#define UCVEBCUTF_nespace(swebc,swutf,datach,dbcsid) \
				(!UCVEBCUTF_eqspace(swebc,swutf,datach,dbcsid))    //~v660R~
	#define UCVEBCUTF_nespacetab(swebc,swutf,datach,dbcsid) \
				(!UCVEBCUTF_eqspacetab(swebc,swutf,datach,dbcsid)) //~v660I~
	#define UCVEBC_ISNULL(datach) \
                ( (datach)==0 )                                    //~v660I~
	#define UCVEBCUTF_eqnull(swebc,swutf,datach,dbcsid) \
		(   (sw) ? UCVEBC_ISNULL(datach) \
                 : (UTF_eqnull(swutf,datach,datadbcs)) \
        )                                                          //~v660I~
	#define UCVEBCUTF_nenull(swebc,swutf,datach,dbcsid) \
			(!(UCVEBC_eqnull(swebc,swutf,datach,dbcsid)))          //~v660I~
	#define UCVEBC_ASCIIEQ(ch1,dbcsid,ch2) \
				( ((ch1)==(ch2)) && !(dbcsid) )                    //~v660R~
	#define UCVEBCUTF_eqascii(swebc,swutf,ch1,dbcsid,ch2) \
		(   (swebc) ? UCVEBC_ASCIIEQ(ch1,dbcsid,ch2) \
                 : (UTF_eq(swutf,ch1,dbcsid,ch2)) \
        )                                                          //~v660I~
	#define UCVEBC_ASCIINOTEQ(ch1,dbcsid,ch2)   \
				(!UCVEBCDD_ASCIIEQ(ch1,dbcsid,ch2)                 //~v660R~
//  #define UCVEBCUTF_eqascii_b2a(swebc,swutf,ch1,dbcsid,ch2)      //~v69cR~
//  	(   (swebc) ? UCVEBC_ASCIIEQ(EBC_B2A(ch1),dbcsid,ch2)      //~v69cR~
//               : (UTF_eq(swutf,ch1,dbcsid,ch2))                  //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_eqascii_b2a(swebc,swutf,handle,ch1,dbcsid,ch2) \
    	(   (swebc) ? UCVEBC_ASCIIEQ(UCVEBCH_B2A(handle,ch1),dbcsid,ch2) \
                 : (UTF_eq(swutf,ch1,dbcsid,ch2)) \
        )                                                          //~v69cI~
//  #define UCVEBCUTF_neascii_b2a(swebc,swutf,ch1,dbcsid,ch2)      //~v69cR~
//  		(!UCVEBCUTF_eqascii_b2a(swebc,swutf,ch1,dbcsid,ch2))   //~v660R~//~v69cR~
    #define UCVEBCUTF_neascii_b2a(swebc,swutf,handle,ch1,dbcsid,ch2) \
    		(!UCVEBCUTF_eqascii_b2a(swebc,swutf,handle,ch1,dbcsid,ch2))//~v69cI~
                                                                   //~v660I~
	#define UCVEBCUTF_neascii(swebc,swutf,ch1,dbcsid,ch2) \
				(!UCVEBCUTF_eqascii(swebc,swutf,ch1,dbcsid,ch2))   //~v660R~
	#define UCVEBCUTF_umemspnc_space(swebc,swutf,pc,pcd,len) \
		(   (swebc) ? ucvebc_umemspnc(0,pc,pcd,CHAR_EBC_SPACE,len) \
                 : (UTF_umemspnc(swutf,pc,pcd,' ',len)) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_isalnum_b2a(swebc,swutf,ch,dbcsid)           //~v69cR~
//  	(  (swebc) ? (dbcsid)==0 && isalnum(EBC_B2A(ch))           //~v69cR~
//               : (UTF_isalnum(swutf,ch,dbcsid))                  //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_isalnum_b2a(swebc,swutf,handle,ch,dbcsid) \
    	(  (swebc) ? (dbcsid)==0 && isalnum(UCVEBCH_B2A(handle,ch)) \
                 : (UTF_isalnum(swutf,ch,dbcsid)) \
        )                                                          //~v69cI~
//  #define UCVEBC_uispunct(pc,pcd,reslen)                         //~v69cR~
//  	  ucvebc_uispunct(0,pc,pcd,reslen)                         //~v660R~//~v69cR~
    #define UCVEBC_uispunct(handle,pc,pcd,reslen) \
    	  ucvebc_uispunct(0,handle,pc,pcd,reslen)                  //~v69cI~
                                                                   //~v660I~
//  #define UCVEBC_asciilen(pc,pcd,len)                            //~v69cR~
//  	  ucvebc_asciilen(0,pc,pcd,len)                            //~v660I~//~v69cR~
    #define UCVEBC_asciilen(handle,pc,pcd,len) \
    	  ucvebc_asciilen(0,handle,pc,pcd,len)                     //~v69cI~
                                                                   //~v660I~
	#define UCVEBCUTF_umemspnc_spacetab(swebc,swutf,pc,pcd,len) \
		(   (swebc) ? ucvebc_umemspnc(0,pc,pcd,CHAR_EBC_SPACE,len) \
                 : (UTF_ustrnspn(swutf,pc,pcd," \t",len)) \
        )                                                          //~v660I~
	#define UCVEBC_ustrnspnc_space(pc,pcd,len) \
		(   ucvebc_umemspnc(UCVEBCO_STRN,pc,pcd,CHAR_EBC_SPACE,len) )//~v660I~
	#define UCVEBCUTF_ustrnspnc_space(swebc,swutf,pc,pcd,len) \
		(   (swebc) ? UCVEBC_ustrnspnc_space(pc,pcd,len) \
                 : (UTF_ustrnspn(swutf,pc,pcd," ",len)) \
        )                                                          //~v660I~
	#define UCVEBCUTF_unumlen(swebc,swutf,pc,pcd,opt,len) \
		(   (swebc) ? ucvebc_unumlen((opt),(pc),(pcd),(len)) \
                 : UTF_unumlen(swutf,pc,pcd,opt,len) \
        )                                                          //~v660I~
	#define UCVEBC_uatoin(swebc,pc,pcd,len) \
		(   (swebc) ? ucvebc_uatoin(0,pc,pcd,len) \
                 : uatoin(pc,len) \
        )                                                          //~v660I~
	#define UCVEBCUTF_uatoin(swebc,swutf,pc,pcd,len) \
		(   (swebc) ? ucvebc_uatoin(0,pc,pcd,len) \
                 : UTF_uatoin(swutf,pc,pcd,len) \
        )                                                          //~v660I~
                                                                   //~v660I~
	#define UCVEBC_umemrspnc(swebc,pc,pcd,ch,len) \
		(   (swebc) ? ucvebc_umemrspnc(0,pc,pcd,ch,len) \
                 : umemrspnc((pc),(ch),(len)) \
        )                                                          //~v660I~
	#define UCVEBC_umemrspnc_space(swebc,pc,pcd,len) \
		(   (swebc) ? ucvebc_umemrspnc(0,pc,pcd,CHAR_EBC_SPACE,len) \
                 : umemrspnc((pc),' ',(len))                        \
        )                                                          //~v660I~
	#define UCVEBCUTF_umemrspnc(swebc,swutf,pc,pcd,ch1,ch2,len) \
		(   (swebc) ? ucvebc_umemrspnc(0,pc,pcd,ch1,len) \
                 : UTF_umemrspnc(swutf,pc,pcd,ch2,len) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umemchr2_a2b(swebc,swutf,pc,pcd,ch,len)      //~v69cR~
//  	(   (swebc) ? ucvebc_umemchr(UCVEBCO_A2B,pc,pcd,ch,len)    //~v69cR~
//               : UTF_umemchr2(swutf,pc,pcd,ch,len)               //~v69cR~
//      )                                                          //~v660M~//~v69cR~
    #define UCVEBCUTF_umemchr2_a2b(swebc,swutf,handle,pc,pcd,ch,len) \
    	(   (swebc) ? ucvebc_umemchr(UCVEBCO_A2B,handle,pc,pcd,ch,len) \
                 : UTF_umemchr2(swutf,pc,pcd,ch,len) \
        )                                                          //~v69cI~
	#define UCVEBCUTF_umemchr_a2b(swebc,swutf,pc,pcd,ch,len) \
		(   (swebc) ? ucvebc_umemchr(UCVEBCO_A2B,pc,pcd,ch,len) \
                 : UTF_memchr(swutf,pc,pcd,ch,len) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umemchr(swebc,swutf,pc,pcd,ch,len)           //~v69cR~
//  	(   (swebc) ? ucvebc_umemchr(0,pc,pcd,ch,len)              //~v69cR~
//               : UTF_memchr(swutf,pc,pcd,ch,len)                 //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemchr(swebc,swutf,handle,pc,pcd,ch,len) \
    	(   (swebc) ? ucvebc_umemchr(0,handle,pc,pcd,ch,len) \
                 : UTF_memchr(swutf,pc,pcd,ch,len) \
        )                                                          //~v69cI~
//  #define UCVEBCUTF_umemchr_space(swebc,swutf,pc,pcd,len)        //~v69cR~
//  	(   (swebc) ? ucvebc_umemchr(0,pc,pcd,CHAR_EBC_SPACE,len)  //~v69cR~
//               : UTF_memchr(swutf,pc,pcd,' ',len)                //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemchr_space(swebc,swutf,pc,pcd,len) \
    	(   (swebc) ? ucvebc_umemchr(0,0/*handle*/,pc,pcd,CHAR_EBC_SPACE,len) \
                 : UTF_memchr(swutf,pc,pcd,' ',len) \
        )                                                          //~v69cI~
//  #define UCVEBCUTF_umemrchr2_a2b(swebc,swutf,pc,pcd,ch,len)     //~v69cR~
//  	(   (swebc) ? ucvebc_umemrchr(UCVEBCO_A2B,pc,pcd,ch,len)   //~v69cR~
//               : UTF_umemrchr2(swutf,pc,pcd,ch,len)              //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemrchr2_a2b(swebc,swutf,handle,pc,pcd,ch,len) \
    	(   (swebc) ? ucvebc_umemrchr(UCVEBCO_A2B,handle,pc,pcd,ch,len) \
                 : UTF_umemrchr2(swutf,pc,pcd,ch,len) \
        )                                                          //~v69cI~
//  #define UCVEBCUTF_umemrchr_space(swebc,swutf,pc,pcd,len)       //~v69cR~
//  	(   (swebc) ? ucvebc_umemrchr(0,pc,pcd,CHAR_EBC_SPACE,len) //~v69cR~
//               : UTF_umemrchr(swutf,pc,pcd,' ',len)              //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemrchr_space(swebc,swutf,pc,pcd,len) \
    	(   (swebc) ? ucvebc_umemrchr(0,0/*handle*/,pc,pcd,CHAR_EBC_SPACE,len) \
                 : UTF_umemrchr(swutf,pc,pcd,' ',len) \
        )                                                          //~v69cI~
	#define UCVEBCUTF_umemrspnc_space(swebc,swutf,pc,pcd,len) \
		UCVEBCUTF_umemrspnc(swebc,swutf,pc,pcd,CHAR_EBC_SPACE,' ',len) \
                                                                   //~v660I~
	#define UCVEBC_CHAR_SPACE(swebc) ((swebc) ? CHAR_EBC_SPACE : ' ')//~v660I~
	#define UCVEBC_memset_space(swebc,pc,len) \
		(   memset((pc),UCVEBC_CHAR_SPACE(swebc),(UINT)(len)) \
        )                                                          //~v660I~
                                                                   //~v660I~
	#define UCVEBC_umemspn(pc,pcd,pdelm,len) \
		(   ucvebc_umemspn(0,pc,pcd,pdelm,len) )                   //~v660R~
	#define UCVEBCUTF_umemspn(swebc,swutf,pc,pcd,pdelm,len) \
		(   (swebc) ? UCVEBC_umemspn(pc,pcd,pdelm,len) \
                 : UTF_umemspn(swutf,pc,pcd,pdelm,len) \
        )                                                          //~v660I~
                                                                   //~v660I~
	#define UCVEBC_umemrspn(pc,pcd,pdelm,len) \
		(   ucvebc_umemrspn(0,pc,pcd,pdelm,len) )                  //~v660R~
	#define UCVEBCUTF_umemrspn(swebc,swutf,pc,pcd,pdelm,len) \
		(   (swebc) ? UCVEBC_umemrspn(pc,pcd,pdelm,len) \
                 : UTF_umemrspn(swutf,pc,pcd,pdelm,len) \
        )                                                          //~v660I~
                                                                   //~v660I~
//  #define UCVEBC_a2bfld(swebc,pc,len)                            //~v69cR~
//  	   if (swebc) ucvebc_a2bfld(0,pc,pc,len)                   //~v660R~//~v69cR~
    #define UCVEBC_a2bfld(swebc,handle,pc,len) \
    	   if (swebc) ucvebc_a2bfld(0,handle,pc,pc,len)            //~v69cI~
//  #define UCVEBC_a2bcopy(swebc,pc,pco,len)                       //~v69cR~
//  	   if (swebc) ucvebc_a2bfld(0,pc,pco,len)                  //~v660I~//~v69cR~
    #define UCVEBC_a2bcopy(swebc,handle,pc,pco,len) \
    	   if (swebc) ucvebc_a2bfld(0,handle,pc,pco,len)           //~v69cI~
//  #define UCVEBC_b2afld(swebc,pc,len)                            //~v69cR~
//  	   if (swebc) ucvebc_b2afld(0,pc,pc,len)                   //~v660I~//~v69cR~
    #define UCVEBC_b2afld(swebc,handle,pc,len) \
    	   if (swebc) ucvebc_b2afld(0,handle,pc,pc,len)            //~v69cI~
	#define UCVEBC_b2acopy(swebc,pc,pco,len) \
		   if (swebc) ucvebc_b2afld(0,pc,pco,len)                  //~v660I~
                                                                   //~v660I~
	#define UCVEBC_CONST(swebc,const) \
		   UWHICH(swebc,const##_EBC,const)                         //~v660I~
//  #define UCVEBC_CONSTC(swebc,const)                             //~v69cR~
//  	   UWHICH(swebc,EBC_A2B(const),const)                      //~v660I~//~v69cR~
    #define UCVEBC_CONSTC(swebc,handle,const) \
    	   UWHICH(swebc,UCVEBCH_A2B(handle,const),const)           //~v69cI~
	#define UCVEBCUTF_umemrmem(swebc,swutf,pc,pcd,key,keydbcs,len,lenk) \
		(   (swebc) ? ucvebc_umemrmem(0,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemrmem(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v660I~
	#define UCVEBCUTF_umemrmem_opt(swebc,swutf,opt,pc,pcd,key,keydbcs,len,lenk) \
		(   (swebc) ? ucvebc_umemrmem(opt,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemrmem(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umemrmemi(swebc,swutf,pc,pcd,key,keydbcs,len,lenk)//~v69cR~
//  	(   (swebc) ? ucvebc_umemrmemi(0,pc,pcd,len,key,keydbcs,lenk)//~v69cR~
//               : UTF_umemrmemi(swutf,pc,pcd,key,keydbcs,len,lenk)//~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemrmemi(swebc,swutf,handle,pc,pcd,key,keydbcs,len,lenk) \
		(   (swebc) ? ucvebc_umemrmemi(0,handle,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemrmemi(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v69cI~
	#define UCVEBCUTF_umemmem(swebc,swutf,pc,pcd,key,keydbcs,len,lenk) \
		(   (swebc) ? ucvebc_umemmem(0,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemmem(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v660I~
	#define UCVEBCUTF_umemmem_opt(swebc,swutf,opt,pc,pcd,key,keydbcs,len,lenk) \
		(   (swebc) ? ucvebc_umemmem(opt,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemmem(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v660I~
	#define UCVEBCUTF_umemmem_a2b(swebc,swutf,pc,pcd,key,len,lenk) \
		(   (swebc) ? ucvebc_umemmem(UCVEBCO_A2B,pc,pcd,len,key,lenk) \
                 : UTF_umemmem(swutf,pc,pcd,key,len,lenk) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umemmemi(swebc,swutf,pc,pcd,key,keydbcs,len,lenk)//~v69cR~
//  	(   (swebc) ? ucvebc_umemmemi(0,pc,pcd,len,key,keydbcs,lenk)//~v69cR~
//               : UTF_umemmemi(swutf,pc,pcd,key,keydbcs,len,lenk) //~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemmemi(swebc,swutf,handle,pc,pcd,key,keydbcs,len,lenk) \
    	(   (swebc) ? ucvebc_umemmemi(0,handle,pc,pcd,len,key,keydbcs,lenk) \
                 : UTF_umemmemi(swutf,pc,pcd,key,keydbcs,len,lenk) \
        )                                                          //~v69cI~
	#define UCVEBCUTF_umempbrk_a2b(swebc,swutf,pc,pcd,delm,len) \
		(   (swebc) ? ucvebc_umempbrk(UCVEBCO_A2B,pc,pcd,delm,len) \
                 : UTF_UMEMPBRK(swutf,pc,pcd,delm,len) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umempbrk_nonascii(swebc,swutf,pc,pcd,delm,delmdbcs,len)//~v69cR~
//  	(   (swebc) ? ucvebc_umempbrk(0,pc,pcd,delm,len)           //~v69cR~
//               : UTF_umempbrk_nonascii(swutf,pc,pcd,delm,delmdbcs,len)//~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umempbrk_nonascii(swebc,swutf,handle,pc,pcd,delm,delmdbcs,len) \
    	(   (swebc) ? ucvebc_umempbrk(0,handle,pc,pcd,delm,len) \
                 : UTF_umempbrk_nonascii(swutf,pc,pcd,delm,delmdbcs,len) \
        )                                                          //~v69cI~
	#define UCVEBCUTF_umempbrk(swebc,swutf,pc,pcd,delm,len) \
		(   (swebc) ? ucvebc_umempbrk(0,pc,pcd,delm,len) \
                 : UTF_UMEMPBRK(swutf,pc,pcd,delm,len) \
        )                                                          //~v660I~
	#define UCVEBCUTF_umemrpbrk(swebc,swutf,pc,pcd,delm,len) \
		(   (swebc) ? ucvebc_umemrpbrk(0,pc,pcd,delm,len) \
                 : UTF_umemrpbrk(swutf,pc,pcd,delm,len) \
        )                                                          //~v660I~
//  #define UCVEBCUTF_umemrpbrk_nonascii(swebc,swutf,pc,pcd,delm,delmdbcs,len)//~v69cR~
//  	(   (swebc) ? ucvebc_umemrpbrk(0,pc,pcd,delm,len)          //~v69cR~
//               : UTF_umemrpbrk_nonascii(swutf,pc,pcd,delm,delmdbcs,len)//~v69cR~
//      )                                                          //~v660I~//~v69cR~
    #define UCVEBCUTF_umemrpbrk_nonascii(swebc,swutf,handle,pc,pcd,delm,delmdbcs,len) \
		(   (swebc) ? ucvebc_umemrpbrk(0,handle,pc,pcd,delm,len) \
                 : UTF_umemrpbrk_nonascii(swutf,pc,pcd,delm,delmdbcs,len) \
        )                                                          //~v69cI~
//  #define UCVEBC_isasciistr(pc,pcd,len)                          //~v69cR~
//  	( ucvebc_asciilen(0,pc,pcd,len)==(len))                    //~v660I~//~v69cR~
    #define UCVEBC_isasciistr(hanle,pc,pcd,len) \
    	( ucvebc_asciilen(0,handle,pc,pcd,len)==(len))             //~v69cI~
    #define UCVEBC_CUTSIDESOSI(pebc,pdbcs,ebclen) \
    (	( ((ebclen)>2 && *(pebc)==CHAR_SO && *((pebc)+(ebclen)-1)==CHAR_SI) ) \
    	? (                                                    \
        	memcpy((pebc),((pebc)+1),(UINT)((ebclen)-2)),       \
        	memcpy((pdbcs),((pdbcs)+1),(UINT)((ebclen)-2)),       \
            *((pebc)+(ebclen)-2)=0,                             \
            *((pebc)+(ebclen)-1)=0,                             \
            (ebclen)-2                                          \
          )                                                     \
        :   (ebclen)                                            \
    )	                                                           //~v69cR~
                                                                   //~v660I~
//**********                                                       //~v660I~
	int ucvebc_umemspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v660M~
	int ucvebc_umemrspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v660I~
//  char *ucvebc_umemrchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v660R~//~v69cR~
    char *ucvebc_umemrchr(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v69cI~
	int ucvebc_unumlen(int Popt,char *Pstr,char *Pdbcs,int Plen);  //~v660I~
//	int ucvebc_memcmp(int Popt,char *Pstr1,char *Pdbcs1,char *Pstr2,char *Pdbcs2,int Plen);//~v660I~//~v69cR~
  	int ucvebc_memcmp(int Popt,int Phandle,char *Pstr1,char *Pdbcs1,char *Pstr2,char *Pdbcs2,int Plen);//~v69cI~
	int ucvebc_issbcsstr(int Popt,char *Pdbcs,int Plen);           //~v660I~
	int ucvebc_uatoin(int Popt,char *Pstr,char *Pdbcs,int Plen);   //~v660R~
//  int ucvebc_a2bfld(int Popt,char *Pstr,char *Poutstr,int Plen); //~v660R~//~v69cR~
    int ucvebc_a2bfld(int Popt,int Phandle,char *Pstr,char *Poutstr,int Plen);//~v69cI~
//  int ucvebc_b2afld(int Popt,char *Pstr,char *Poutstr,int Plen); //~v660I~//~v69cR~
    int ucvebc_b2afld(int Popt,int Phandle,char *Pstr,char *Poutstr,int Plen);//~v69cI~
//  char *ucvebc_umemchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v660I~//~v69cR~
    char *ucvebc_umemchr(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v69cI~
//  char *ucvebc_umempbrk(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v660I~//~v69cR~
    char *ucvebc_umempbrk(int Popt,int Phandle,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v69cI~
//  char *ucvebc_umemrpbrk(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v660I~//~v69cR~
    char *ucvebc_umemrpbrk(int Popt,int Phandle,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v69cI~
	int ucvebc_umemspn(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v660R~
	int ucvebc_umemrspn(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v660R~
//*******************                                              //~v660I~
#define UCVEBC3O_CFGFILE            0x00000001                     //~v660R~
#ifdef AAA                                                         //~v660I~
#define UCVEBC3O_TABKEEP            0x00000002                     //~v660R~
#endif                                                             //~v660I~
#define UCVEBC3O_SBCS               0x00000004                     //~v660R~
#define UCVEBC3O_CVCTL              0x00000008    //translate ctl char//~v660R~
#define UCVEBC3O_BIN                0x00000010    //bin file(no SO/SI ctl)//~v660I~
//#define UCVEBC3O_DBCS  not used   0x00000020    //force dbcs mode//~v660I~//~v6bhR~
#define UCVEBC3O_SOSISHIFT          0x00000020    //x2B shrink space(after SI or continued space) by SO/SI increased count//~v6bhI~
#define UCVEBC3O_SOSI2SPACE         0x00000040    //replace so/si to space//~v660I~
#define UCVEBC3O_ERRREP             0x00000080    //replace dbcs cv err//~v660R~
#define UCVEBC3O_B2F                0x00000100    //b2f for b2dd rtn//~v660I~
#define UCVEBC3O_SOSIREP            0x00000200    //replace so/si to "."//~v660I~
#define UCVEBC3O_SOSIREPQ           0x00000400    //replace so/si to "?"//~v660I~
#define UCVEBC3O_CHKDBCSTB          0x00000800    //for b2dd,dbcstb is input(chk DBCS1ST/DBCS2ND for dbcs trans)//~v660R~
#define UCVEBC3O_SETF2LERR          0x00001000    //for b2m, set F2LERR on dbcstb except SO/SI//~v660I~
#define UCVEBC3O_CMPSO              0x00002000    //for memmem include starting SO//~v660R~
#define UCVEBC3O_DROPSOSI           0x00004000    //drop so/si at B2DD(B2F)//~v66aR~
#define UCVEBC3O_SOSIREPQP          0x00008000    //replace so/si to "?" as printable//~v66gI~
#define UCVEBC3O_GETCFG             0x00010000    //get cfg structutre addr//~v66gI~
#define UCVEBC3O_UCSNP              0x00020000    //non printable ucs//~v66gI~
#define UCVEBC3O_SETSUBCHRC         0x00040000    //return subchar was set//~v66LI~
#define UCVEBC3O_MBCHSZ             0x00080000    //m2b parm length is mbchsz//~v66XI~
#define UCVEBC3O_REPNULL            0x00100000    //replace null to space//~v686I~
#define UCVEBC3O_SOSIINS            0x00200000    //A2B insert SOSI//~v687I~
#define UCVEBC3O_SOSICMDO           0x00400000    //sosi cmd option parm//~v687I~
#define UCVEBC3O_CFGSOSI            0x00800000    //for c&p sosi option by cfg//~v68aI~
#define UCVEBC3O_DBCSUCSOK          0x01000000    //accept dbcs ucs for b2dd//~v69kI~
#define UCVEBC3O_ERREXIT            0x02000000    //errexit at cfg err//~v69wR~
#define UCVEBC3O_ERRMSG             0x04000000    //erremsg at cfg err//~v69wI~
#define UCVEBC3O_ERRREP2            0x08000000    //errrep to "." for xprint//~v69yI~
#define UCVEBC3O_ERRREP3            0x10000000    //leave to rep err by subchar//~v6hwI~
#define UCVEBC3O_USEICU             0x20000000    //use icu when cfg err//~v6m3I~
                                                                   //~v660I~
#define UCVEBCO_STRN                0x00000001    //chk strz       //~v660R~
#define UCVEBCO_A2B                 0x00000002    //search char after A2B//~v660I~
#define UCVEBCO_NOCASE              0x00000004    //compare case insensitive//~v660I~
#define UCVEBCO_NODBCS              0x00000008    //no dbcstbl for compare//~v66gI~
//*******************************************************          //~v660I~
//int ucvebc3_b2dd(int Popt,UCHAR *Pebc,int Plen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen);//~v660I~//~v69cR~
int ucvebc3_b2dd(int Popt,int Phandle,UCHAR *Pebc,int Plen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc3_dd2b(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Plen,UCHAR *Pebc,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppebclen);//~v660R~//~v69cR~
int ucvebc3_dd2b(int Popt,int Phandle,UCHAR *Pdddata,UCHAR *Pdddbcs,int Plen,UCHAR *Pebc,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppebclen);//~v69cI~
//*******************************************************          //~v687I~
//int ucvebc3_f2b(int Popt,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~v687I~//~v69cR~
int ucvebc3_f2b(int Popt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v660I~
int ucvebc2asc1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,int *Ppsjis);//~v660I~
//*******************************************************          //~v660I~
//int ucvebc2ucs1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,WUCS *Ppucs);//~v660I~//~v6BjR~
int ucvebc2ucs1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,UWUCS *Ppucs);//~v6BjI~
//*******************************************************          //~v660I~
//int ucvebc3_init(int Popt,ULONG *Pcfg);                             //~v660I~//~v66gR~//~v6hhR~
int ucvebc3_init(int Popt,ULPTR *Pcfg);                            //~v6hhI~
//*******************************************************          //~v660I~
//int ucvebc3_b2m(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,int Poutbuffsz,int Prepch,int *Ppoutlen);//~v68bR~
//int ucvebc3_b2m(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int Prepch,int *Ppoutlen);//~v68bI~//~v69cR~
int ucvebc3_b2m(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int Prepch,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc3_setdbcstbl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~v660I~//~v69cR~
int ucvebc3_setdbcstbl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc3_m2b1(int Popt,UCHAR *Pdata,int Pinplen,UCHAR *Poutbuff,int *Ppoutlen);//~v660I~//~v69cR~
int ucvebc3_m2b1(int Popt,int Phandle,UCHAR *Pdata,int Pinplen,UCHAR *Poutbuff,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc3_u2b1(int Popt,WUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen);//~v660I~//~v69cR~
//int ucvebc3_u2b1(int Popt,int Phandle,WUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen);//~v69cI~//~v6m3R~
int ucvebc3_u2b1(int Popt,int Phandle,UWUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen);//~v6m3I~
//*******************************************************          //~v660I~
//int ucvebc3_b2ddSbcs1(int Popt,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen);//~v660R~//~v69cR~
//int ucvebc3_b2ddSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen);//~v69cI~//~v6m3R~
int ucvebc3_b2ddSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,UWUCS *Ppwucs,int *Ppoutlen);//~v6m3I~
//*******************************************************          //~v660I~
//int ucvebc3_b2ddDbcs1(int Popt,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen);//~v660R~//~v69cR~
//int ucvebc3_b2ddDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen);//~v69cI~//~v6m3R~
int ucvebc3_b2ddDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,int *Ppoutlen);//~v6m3I~
//*******************************************************          //~v660I~
//int ucvebc3_m2b1Sbcs1(int Popt,int Pmbch);                          //~v660I~//~v66gR~//~v69cR~
int ucvebc3_m2b1Sbcs1(int Popt,int Phandle,int Pmbch);             //~v69cI~
//*******************************************************          //~v660I~
//int ucvebc3_m2b(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~v660I~//~v69cR~
int ucvebc3_m2b(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~v69cI~
//*******************************************************          //~v6bjI~
int ucvebc3_b2f(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Ppoutdata,UCHAR *Poutdbcs,int Pbuffsz,int *Ppoutlen);//~v6bjI~
//*******************************************************          //~v6bjI~
int ucvebc3_f2bcmd(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutdata,UCHAR *Poutdbcs,int Pbuffsz,int *Ppoutlen);//~v6bjI~
//*******************************************************          //~v6bjI~
int ucvebc3_getebc3opt(int Pebcopt);                               //~v6bjI~
//*******************************************************          //~v660I~
//int ucvebc_memicmp(char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen);//~v660I~//~v69cR~
int ucvebc_memicmp(int Phandle,char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen);//~v69cI~
//*******************************************************          //~v660I~
//char *ucvebc_umemmemi(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v660I~//~v69cR~
char *ucvebc_umemmemi(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v69cI~
//*******************************************************          //~v660I~
//char *ucvebc_umemrmemi(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v660R~//~v69cR~
char *ucvebc_umemrmemi(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v69cI~
//*******************************************************          //~v660R~
char *ucvebc_umemmem(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v660I~
//*******************************************************          //~v660I~
char *ucvebc_umemrmem(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk);//~v660I~
//*******************************************************          //~v660I~
//int ucvebc_memcmp_banda(int Popt,char *Pdata1,char *Pdbcs1,char *Pdata2,int Plen);//~v660R~//~v69cR~
int ucvebc_memcmp_banda(int Popt,int Phandle,char *Pdata1,char *Pdbcs1,char *Pdata2,int Plen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc_uispunct(int Popt,char *Pdata,char *Pdbcs,int Preslen); //~v660R~//~v69cR~
int ucvebc_uispunct(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Preslen);//~v69cI~
//*******************************************************          //~v660I~
//int ucvebc_asciilen(int Popt,char *Pdata,char *Pdbcs,int Plen);    //~v660I~//~v69cR~
int ucvebc_asciilen(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Plen);//~v69cI~
//*******************************************************          //~v66fI~
int ucvebc_getsubchar_dbcs(int Popt);                              //~v66fI~
#define UCVEBCGSCDO_LC       0x00        //get locale code         //~v66fI~
#define UCVEBCGSCDO_UCS      0x01        //get ucs code            //~v66fI~
#define UCVEBCGSCDO_EBC      0x02        //get ebc code            //~v66fI~
//*******************************************************          //~v66LI~
int ucvebc_defaultremap(int Popt,void *Ppcfg);                     //~v66LI~
#endif //UTF8EBCD                                                  //~v660R~
//*******************************************************          //~v68hI~
int ucvebc_chkeolopt(int Popt,int *Ppebcopt,int Smiscopt);         //~v68hR~
#define UCVEBCCEO_INPUTEOL     0x01  //chk input eol have to be ignore//~v68hI~
#define UCVEBCCEO_FGETSOPT     0x02  //return fgets option for EBC file of B2x//~v68hI~
