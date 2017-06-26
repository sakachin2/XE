//*CID://+v6BuR~:                             update#=  273;       //+v6BuR~
//******************************************************           //~v5n3R~//~v69cI~
//v6Bu:160226 support ebc(0x00->oxff)->ucs4  mapping               //+v6BuI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6hhI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6bd:111209 change default map to cp37(contains ctl char) from c3270ftp when not xe3270//~v6bdI~
//v69u:100903 b2b support for xcv(a2a is not proper for dbcs converter because dbcsstarter is null for ebc)//~v69uI~
//v69t:100903 add isebccodepage                                    //~v69tI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//******************************************************           //~v69cI~
//*ucvext3.h                                                       //~v69cI~
//******************************************************           //~v69cI~
#ifdef WCSUPP                                                      //~v69cI~
//******************************************************           //~v5n8I~//~v69cI~
//******************************************************           //~v69cI~
typedef struct _UCVEBCH {  //converter handle                      //~v69cR~
#define  UCVEBCH_GETCFG(pucveh)   \
    ((PUCVEXTCFG)((ULONG)(((UCVEBCH*)(pucveh))->UCVEHqelem.UQqhdr)-offsetof(UCVEXTCFG,UCECFhque)))//~v69cR~
					int    UCVEHhandle;                            //~v69cI~
#define UCVEBCH_MAXHANDLE        8        //0:from config,1-7 parm converter//~v69cR~
					char   UCVEHcvname[MAX_CSNAMESZ];              //~v69cR~
                    int    UCVEHflag;                              //~v69cI~
#define UCVEHF_DBCSCV            0x01   //dbcs support             //~v69cR~
	#define UCVEBCH_ISDBCSCV(pcveh)  ((pcveh)->UCVEHflag & UCVEHF_DBCSCV)//~v69cR~
#define UCVEHF_SBCSMAPINIT       0x02   //sbcs map init end        //~v69cR~
	#define UCVEBCH_ISSBCSMAPINIT(pcveh)  ((pcveh)->UCVEHflag & UCVEHF_SBCSMAPINIT)//~v69cR~
					UCHAR  UCVEHsubcharebcsbcs;                    //~v69cR~
					UCHAR  UCVEHsubcharebcdbcs[MAX_MBCSLEN];       //~v69cR~
					UCHAR  UCVEHsubcharICUebcSbcs;                 //~v69cR~
					UCHAR  UCVEHsubcharICUebcDbcs[MAX_MBCSLEN];    //~v69cR~
                    int    UCVEHsubcharebcdbcslen;                 //~v69cR~
                    int    UCVEHsubcharICUebcDbcslen;              //~v69cR~
					WUCS   UCVEHsubcharsbcs;                       //~v69cR~
					WUCS   UCVEHsubchardbcs;                       //~v69cR~
					WUCS   UCVEHsubchardefaultucsdbcs;	//win cpinfo//~v69cI~
					WUCS   UCVEHsubchardefaultucssbcs;	//win cpinfo//~v69cI~
//                  ULONG *UCVEHpconverters;                       //~v69cR~//~v6hhR~
                    ULPTR *UCVEHpconverters;                       //~v6hhI~
//                  ULONG  UCVEHpconverter[4]; //0:dbcs,1:sbcs,3,4:map//~v69cI~//~v6hhR~
                    ULPTR  UCVEHpconverter[4]; //0:dbcs,1:sbcs,3,4:map//~v6hhI~
//                  ULONG  UCVEHhiconv[2];     //common to sbcs and dbcs//~v69cR~//~v6hhR~
                    ULPTR  UCVEHhiconv[2];     //common to sbcs and dbcs//~v6hhI~
					UCHAR  UCVEHu2bmap[256];                       //~v69cI~
//  				WUCS   UCVEHb2umap[256];   //ucs2              //~v69cI~//+v6BuR~
    				UWUCS  UCVEHb2umap[256];   //ucs4 for ebc(<0x100)->ucs mapping//+v6BuI~
					UCHAR  UCVEHu2bffmap[256];                     //~v69cI~
//  				WUCS   UCVEHu2bnonasciimapucs[256];            //~v69cI~//+v6BuR~
    				UWUCS  UCVEHu2bnonasciimapucs[256];            //+v6BuI~
					UCHAR  UCVEHu2bnonasciimapebc[256];            //~v69cI~
					int    UCVEHu2bnonasciictr;                    //~v69cI~
					UCHAR  UCVEHctype[256];                        //~v69cI~
#define EBCTYPE_LOWER       0x01                                   //~v69cI~
#define EBCTYPE_UPPER       0x02                                   //~v69cI~
#define EBCTYPE_ALPHA       0x03                                   //~v69cI~
#define EBCTYPE_NUM         0x04                                   //~v69cI~
#define EBCTYPE_DBCS        0x08                                   //~v69cI~
#define EBCTYPE_SS3         0x10                                   //~v69cI~
#define EBCTYPE_GB4         0x20                                   //~v69cI~
					UCHAR  UCVEHtoupper[256];                      //~v69cI~
	                UCHAR  UCVEHtolower[256];                      //~v69cI~
	                UCHAR  UCVEHa2bmap[256];    //ascii->ebc map for sbcs//~v69cI~
   	                ULONG  UCVEHb2amap[256];   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
                   } UCVEBCH,*PUCVEBCH;                            //~v69cR~
#define UCVEBCHSZ sizeof(UCVEBCH)                                  //~v69cR~
//*********************************************                    //~v69cI~
    EXT_EBC UCVEBCH Gucvebch[UCVEBCH_MAXHANDLE];                   //~v69cI~
    EXT_EBC int     Gucvebchctr;                                   //~v69cI~
    #define UCVEBCH_toupper(h,ch)    ((int)(Gucvebch[h].UCVEHtoupper[(int)(ch)]))//~v69cR~
    #define UCVEBCH_tolower(h,ch)    ((int)(Gucvebch[h].UCVEHtolower[(int)(ch)]))//~v69cR~
    #define UCVEBCH_A2B(h,ch)        (Gucvebch[h].UCVEHa2bmap[(int)(ch)])//~v69cR~
    #define UCVEBCH_B2A(h,ch)        (Gucvebch[h].UCVEHb2amap[(int)(ch)])//~v69cR~
    #define UCVEBCH_B2A_ISDBCS(h,ch) (UCVEBCH_B2A(ch) & 0xff00)    //~v69cI~
                                                                   //~v69cI~
    #define UCVEBCH_B2A_TYPEISDBCS(h,ch) (Gucvebch[h].UCVEHctype[(int)(ch)] & EBCTYPE_DBCS)//~v69cR~
    #define UCVEBCH_B2A_TYPEISSS3(h,ch)  (Gucvebch[h].UCVEHctype[(int)(ch)] & EBCTYPE_SS3)//~v69cR~
    #define UCVEBCH_B2A_TYPEISGB4(h,ch)  (Gucvebch[h].UCVEHctype[(int)(ch)] & EBCTYPE_GB4)//~v69cR~
    #define UCVEBCH_subcharsbcs(h)       (Gucvebch[h].UCVEHsubcharsbcs)//~v69cR~
    #define UCVEBCH_subchardbcs(h)       (Gucvebch[h].UCVEHsubchardbcs)//~v69cR~
    #define UCVEBCH_subcharebcsbcs(h)    (Gucvebch[h].UCVEHsubcharebcsbcs)//~v69cR~
    #define UCVEBCH_subcharebcdbcs(h)    (Gucvebch[h].UCVEHsubcharebcdbcs)//~v69cR~
    #define UCVEBCH_subcharebcdbcslen(h) (Gucvebch[h].UCVEHsubcharebcdbcslen)//~v69cR~
                                                                   //~v69cI~
#define UCVEBC_GETPUCVEH(handle) (Gucvebch+(handle))               //~v69cR~
#define UCVEBCH_HANDLE_ISDBCSCV(handle)  ((UCVEBC_GETPUCVEH(handle))->UCVEHflag & UCVEHF_DBCSCV)//~v69cR~
//*                                                                //~v69cI~
#define  UCVEBC4O_CFG                 0x01	//entry for cfg converetr//~v69cI~
#define  UCVEBC4O_EXCEPTCFG           0x02       //return null if cfg defined converter//~v69cI~
#define  UCVEBC4O_DBCSCV              0x04       //dbcs converter  //~v69cI~
#define  UCVEBC4O_USEICU              0x08       //use icu         //~v69cR~
                                                                   //~v69cI~
//******************************************************           //~v69cI~
int ucvebc4_init(int Popt,PUCVEXTCFG Ppcfg);                       //~v69cR~
//******************************************************           //~v69cI~
int ucvebc4_createhandle(int Popt,char *Pcvname,int *Pphandle);    //~v69cI~
#define UCVEBCCHO_CFG    0x01	//entry for cfg converetr          //~v69cI~
#define UCVEBCCHO_CHKEBCCP    0x02 //confirm ebc codepage          //~v69uI~
//******************************************************           //~v69cI~
PUCVEBCH ucvebc4_getpcveh(int Popt,int Phandle);                   //~v69cI~
//******************************************************           //~v69cI~
char *ucvebc4_getcvname(int Popt,int Phandle);                     //~v69cI~
#define UCVEBC_GETCVNAME(handle) ucvebc4_getcvname(0/*opt*/,handle)//~v69cR~
//******************************************************           //~v69cI~
//int ucvebc4_getparmconverter(int Popt,int Phandle,ULONG *Pcvdbcs,ULONG *Pcvsbcs,ULONG *Pmapsbcs,ULONG *Pmapsbcsc,int *Ppopt);//~v69cI~//~v6hhR~
int ucvebc4_getparmconverter(int Popt,int Phandle,ULPTR *Pcvdbcs,ULPTR *Pcvsbcs,ULPTR *Pmapsbcs,ULPTR *Pmapsbcsc,int *Ppopt);//~v6hhI~
//******************************************************           //~v69cR~
int ucvebc4_getcvtype(int Popt,int Phandle);                       //~v69cI~
#define  UCVEBC4CVT_DBCSCV           0x01                          //~v69cI~
#define  UCVEBC4CVT_EXT              0x02                          //~v69cI~
#define  UCVEBC4CVT_ICU              0x04                          //~v69cI~
#define  UCVEBC4CVT_OPENERR          0x08                          //~v69cI~
#define  UCVEBC4CVT_MAP              0x10                          //~v6bdI~
//******************************************************           //~v69cI~
#ifdef AAA	//no caller                                            //~v6hhI~
//int ucvebc4_isebccodepage(int Popt,ULONG Pconverter);            //~v6hhR~
int ucvebc4_isebccodepage(int Popt,ULPTR Pconverter);              //~v6hhI~
#endif                                                             //~v6hhI~
//******************************************************           //~v69tR~
//int ucvebc4_chkdbcsconverter(int Popt,ULONG Pconveretr,char *Pcvname);//~v6bkI~//~v6hhR~
int ucvebc4_chkdbcsconverter(int Popt,ULPTR Pconveretr,char *Pcvname);//~v6hhI~
//******************************************************           //~v6bdI~
                                                                   //~v69cR~
#endif	//WCSUPP                                                   //~v69cR~
