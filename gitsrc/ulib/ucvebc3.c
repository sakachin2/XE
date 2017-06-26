//*CID://+v6BuR~:                                   update#=  359; //~v6BuR~
//***********************************************************************
//v6Bu:160226 support ebc(0x00->oxff)->ucs4  mapping               //~v6BuI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6x4:150107 gcc warning: array subscript is above array bounds [-Warray-bounds]//~v6x4I~
//v6m3:130726 for xprint, support -ICU without CFG parm file       //~v6m3I~
//v6m1:130722 (BUG)field overflow(debugger check)                  //~v6m1I~
//            ucvebc3_m2b1Sbcs1 call ucvasc2ebc_handle with outbuffsz=1//~v6m1I~
//            ucvext_icsuucs2ebc1 set 2 byte fefe for 0xa1 when cpeb:cp935//~v6m1I~
//v6hw:120821 option to b2f/b2m to leave err rep by subchar        //~v6hwI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hf:120616 (BUG)found by VC10:/W4 warning except                //~v6hfI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6g1:120509 (BUG)ucvebc3_b2uSbcs1 return ebc(=ucs) if map is not defined on not japanese env//~v6g1I~
//            so ucvebc3_setletter set ebc=20 for ucs=20(could not override)//~v6g1I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6bj:111212 for XCV;F2B/B2F support                              //~v6bjI~
//v6bi:111212 f2b sosi:shift support                               //~v6biI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v69y:100909 errrep option for xprint                             //~v69yI~
//v69w:100908 for xprint,cfg err exit                              //~v69wI~
//v69n:100825 (EBC)option to set F2LERR to dd2b                    //~v69nI~
//v69m:100825 (EBC*BUG)F2LERR should not set for DD fmt(b2ddsbcs)  //~v69mI~
//v69k:100823 (EBC)allow b2dd to output dbcs ucs for b2b cv       //~v69kI~//~v69nR~
//v69i:100820 (BUG)dbcstbl is not set to copy line u8 to ebc (sbcs env)//~v69iI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v692:100730 (BUG of ucs4 support) USHORT remaining for ucs       //~v692I~
//v68m:100721 (BUG)dbcstbl maintaenance required when copy cpeb to cpu8 with drop sosi option//~v68mI~
//v68b:100622 (BUG)v66U missing set dbcstbl for hankana expansion  //~v68bI~
//v68a:100622 SOSI option for gxe C&P,chk cfg                      //~v68aI~
//v689:100620 accept SOSI cmd option                               //~v689I~
//v688:100620 apply cfg SOSI option also to ebc3                   //~v688I~
//v687:100619 f2b support(utf8 to ebc)                             //~v687I~
//v686:100619 REPNUL option to b2dd                                //~v686I~
//v66X:100614 (LNX)CN-EBCDIC(CP935) is 2 byte dbcs only but local may be 4 byte dbcs for under GB18030(ex.u-81-x81308131)//~v66XR~
//v66V:100613 (LNX:BUG)iconv returm rc=0 with outlen=0 for 0x0e(b2u)//~v66VI~
//                     iconv set "?" without rc indicating subchar count//~v66VI~
//v66U:100613 (LNX)allow b2a expand sbcs->dbcs for EUC hankana(katakana -->8exx under EUC-J)//~v66UI~
//v66R:100612 apply cfg option E2A/A2E to also internal mapping(ctl char only)//~v66RI~
//v66N:100611 ebc-b9->u178 is err if reverse chk,allow not reversible for b2u//~v66NI~
//            this is 1:n but not the case of subchar.             //~v66NI~
//v66M:100611 avoid crash even when cfg err                        //~v66MI~
//v66H:100610 (BUG)u2b is not reverse of b2u(b2u use new cp290/cp1027 sbcs mapping but u2b use old ucstbl)//~v66HI~
//v66D:100604 indicate SUBCHAR was set by rc                       //~v66DI~
//v66C:100604 use converters native subchar if no subchar was specified on cfg//~v66CI~
//v66z:100602 U-FFFd is standard replacement char of ICU           //~v66zI~
//v66y:100602 support binaly file M2B(SBCS translation)            //~v66yI~
//v66v:100601 consider cfg option SUBCHAR_0a                       //~v66vI~
//v66s:100531 (BUG)ebc chsz is of itself depending not on locale dbcs/sbcs//~v66sI~
//v66q:100530 set default cp037 mapping but real default converter(256 mapping tbl will be initialized at init)//~v66qI~
//v66p:100529 (LNX:BUG)dd2b abend when no converter defined(map defines only b2a/a2b)//~v66pI~
//v66m:100529 (LNX:BUG)SO/SI chk only for dbcs converter           //~v66mI~
//v66g:100523 rep SO/SI to "?" as printable for xpr                //~v66gI~
//v66f:100522 add ebcdic cv dbcs err ch function                   //~v66cI~
//v66c:100521 (BUG)SO..SO..SI case, setdbcstbl treate as DBCS from 2nd SO,but b2ddDbcs dose not//~v66cI~
//v66b:100519 (BUG)by option chkdbcstb swdbcs was reset(b2f change to sbcs tarnslation)//~v66bI~
//v66a:100519 drop SO/SI option for B2M(and B2DD)                  //~0519I~
//v660:100325 local EBCDIC translation support
//***********************************************************************
//* ucvebc3c
//* ebc<-->ucs translation(dd fmt)
//***********************************************************************
//***********************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>                                                 //~0518I~

#include <ulib.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uedit.h>
#include <ucvucs.h>
#include <ucvebc.h>
#include <ucvebc2.h>
#include <ucvext.h>
#include <ucvebc4.h>                                               //~v69cM~
#include <utf.h>
#include <utf2.h>                                                  //~v687I~
#include <utf22.h>
#include <utrace.h>
#include <ustring.h>
//*******************************************************
static UCVEXTCFG *Spcfg;
//static ULONG Spcva2e[4],Spcve2a[4];//cvdbcs,cvsbcs,mapsbcs,mapsbcscomp//~v6hhR~
static ULPTR Spcva2e[4],Spcve2a[4];//cvdbcs,cvsbcs,mapsbcs,mapsbcscomp//~v6hhI~
#define CONVERTER_DBCS     0
#define CONVERTER_SBCS     1
#define CONVERTER_SBCSMAP  2
#define CONVERTER_SBCSMAPC 3
//atic int Sebcopta2e,Sebcopte2a;                                  //~v688R~
static int Sebcopta2e=EBC2ASC_A2E|EBC2ASC_SOSI,Sebcopte2a=EBC2ASC_SOSI;  //default SOSI option//~v688I~
static int Sucsopt;
//static int SsubcharucsSbcs,SsubcharebcSbcs,SsubcharucsDbcs;      //~v66CR~
//static UCHAR SsubcharebcDbcs[2];                                 //~v66CR~
static UCHAR  Ssubcharlocalsbcs;                                   //~v66CI~
static UCHAR  *Spsubcharlocaldbcs;                                 //~v66MR~
static int    Ssubcharlocaldbcslen;                                //~v66CI~
//static UCHAR  Ssubcharebcsbcs;                                     //~v66CI~//~v69cR~
//static UCHAR  *Spsubcharebcdbcs;                                   //~v66CI~//~v69cR~
//static int    Ssubcharebcdbcslen;                                  //~v66CI~//~v69cR~
//static WUCS   Ssubchardbcs=UDBCSCHK_SUBCHAR_DBCS,Ssubcharsbcs=UDBCSCHK_SUBCHAR_SBCS;//~v66CI~//~v69cR~
//static UCHAR Su2bmap[256];                                         //~v66pR~//~v69cR~
//static WUCS  Sb2umap[256];                                         //~v66qR~//~v69cR~
//static UCHAR Su2bffmap[256];                                       //~v66HI~//~v69cR~
//static WUCS  Su2bnonasciimapucs[256];                              //~v66HR~//~v69cR~
//static UCHAR Su2bnonasciimapebc[256];                              //~v66HI~//~v69cR~
//static int   Su2bnonasciictr;                                      //~v66HR~//~v69cR~

//*************************************************************************//~v66qI~
//int ucvebc3_b2uSbcs1(int Popt,UCHAR *Ppebc,int Prepch,WUCS *Ppucs);//~v66qI~//~v69cR~
//int ucvebc3_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,WUCS *Ppucs);//~v69cI~//~v6BjR~
int ucvebc3_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UWUCS *Ppucs);//~v6BjI~
//int ucvebc3_b2mSbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,int Pbuffsz,int *Ppmblen);//~v68bR~
//int ucvebc3_b2mSbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen);//~v68bI~//~v69cR~
int ucvebc3_b2mSbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen);//~v69cI~
//*************************************************************************
//*select converter
//* ret:opt map/local/mapc
//*************************************************************************
//int ucvebc3_getcfgparmconverter(int Popt,PUCVEXTCFG Ppcfg,ULONG *Pcve2a,ULONG *Pcva2e)//~v6hhR~
int ucvebc3_getcfgparmconverter(int Popt,PUCVEXTCFG Ppcfg,ULPTR *Pcve2a,ULPTR *Pcva2e)//~v6hhR~
{
    int opt,mapopt;
//  ULONG cvdbcs,cvsbcs,pmap,pmapc;                                //~v6hhR~
    ULPTR cvdbcs,cvsbcs,pmap,pmapc;                                //~v6hhI~
//************************
	opt=0;
	ucvext_getparmconverter(opt,0,&cvdbcs,&cvsbcs,&pmap,&pmapc,&mapopt);
    Sebcopte2a|=mapopt;
    Pcve2a[CONVERTER_DBCS]=Pcva2e[CONVERTER_DBCS]=cvdbcs;
    Pcve2a[CONVERTER_SBCS]=Pcva2e[CONVERTER_SBCS]=cvsbcs;
	Pcve2a[CONVERTER_SBCSMAP]=pmap;
	Pcve2a[CONVERTER_SBCSMAPC]=pmapc;
	opt=EBC2ASC_A2E;
	ucvext_getparmconverter(opt,0,&cvdbcs,&cvsbcs,&pmap,&pmapc,&mapopt);
    Sebcopta2e|=mapopt;
	Pcva2e[CONVERTER_SBCSMAP]=pmap;
	Pcva2e[CONVERTER_SBCSMAPC]=pmapc;
    mapopt=0;
    if ((Ppcfg->UCECflag & UCECF_USE_CONVERTER)) //use converter
    	mapopt|=EBC2ASC_EXT;  //external converter
    else
    {
    	if (Ppcfg->UCECflag & UCECF_CP930) //use converter
    		mapopt|=EBC2ASC_CP290;  //Japanese katakana ext
    	else
    	if (!(Ppcfg->UCECflag & UCECF_CP939)) //use internal map
        {
        	if (Ppcfg->UCECflag & (UCECF_SBCSMAP)) //use internal map
    			mapopt|=EBC2ASC_EXT;  //external converter
        }
    }
    Sebcopta2e|=mapopt;
    Sebcopte2a|=mapopt;
//  Sebcopte2a|=EBC2ASC_CTL;	//additional parm                  //~0426I~//~0428R~
//  Sebcopta2e|=EBC2ASC_CTL;	//additional parm                  //~0426I~//~0428R~
UTRACEP("getcfgparmconverter Sebcopte2a=%x,a2e=%x\n",Sebcopte2a,Sebcopta2e);
UTRACED("getcfgparmconverter out e2a",Pcve2a,sizeof(ULPTR)*4);     //~v6hhR~
UTRACED("getcfgparmconverter out a2e",Pcva2e,sizeof(ULPTR)*4);     //~v6hhR~
    return 0;
}//ucvebc3_getcfgparmconverter
//*************************************************************************//~v6bjI~
//*select converter                                                //~v6bjI~
//* ret:opt map/local/mapc                                         //~v6bjI~
//*************************************************************************//~v6bjI~
int ucvebc3_init_xcv(int Popt,PUCVEXTCFG Ppcfg)                    //~v6bjI~
{                                                                  //~v6bjI~
//************************                                         //~v6bjI~
    ucvebc3_getcfgparmconverter(0,Ppcfg,Spcve2a,Spcva2e);//opt:map/local/mapc//~v6bjI~
UTRACEP("ucvebc3_init_xcv Sebcopte2a=%x,a2e=%x\n",Sebcopte2a,Sebcopta2e);//~v6bjI~
    return 0;                                                      //~v6bjI~
}//ucvebc3_init_xcv                                                //~v6hhR~
//*************************************************************************
//*get converter subchar
//*************************************************************************
int ucvebc3_getconvertersubchar(int Popt,PUCVEXTCFG Ppcfg)
{
//    if (Ppcfg->UCECsubcharsbcs)                                    //~v66CI~//~v69cR~
//        Ssubcharsbcs=Ppcfg->UCECsubcharsbcs;                       //~v66CI~//~v69cR~
//    if (Ppcfg->UCECsubchardbcs)                                    //~v66CI~//~v69cR~
//        Ssubcharsbcs=Ppcfg->UCECsubchardbcs;                       //~v66CI~//~v69cR~
    Ssubcharlocalsbcs=Ppcfg->UCECsubcharlocalsbcs;                 //~v66CR~
//    Ssubcharebcsbcs=Ppcfg->UCECsubcharebcsbcs;                     //~v66CR~//~v69cR~
	Spsubcharlocaldbcs=Ppcfg->UCECsubcharlocaldbcs;                //~v66CI~
//    Spsubcharebcdbcs=Ppcfg->UCECsubcharebcdbcs;                    //~v66CI~//~v69cR~
//  Ssubcharlocaldbcslen=strlen(Spsubcharlocaldbcs);               //~v66CI~//~v6BkR~
    Ssubcharlocaldbcslen=(int)strlen(Spsubcharlocaldbcs);          //~v6BkI~
//    Ssubcharebcdbcslen=strlen(Spsubcharebcdbcs);                   //~v66CI~//~v69cR~
    UTRACEP("getconverter subcharlocal dbcs=%02x%02x,sbcs=%02x\n",*Spsubcharlocaldbcs,*(Spsubcharlocaldbcs+1),Ssubcharlocalsbcs);//~v66CI~
    return 0;
}//ucvebc3_getconvertersubchar
//*************************************************************************
//*get ebc letter for lowercase letter which varies according to codepage
//*************************************************************************
int ucvebc3_setletter(int Popt)
{
    int ii,opt,ebc;
    int len,optb2m;                                                       //~v66sI~//~v66vR~
    int opt3;                                                      //~v66qI~
    UCHAR ebclower[26],ebcl;
    UCHAR ebcupper[26],ebcu;
//  UCHAR wkch[4];                                                    //~v66pR~//~v6x4R~
//  UCHAR wkdbcs[4];                                               //~v6x4R~
    UCHAR wkch[8];   //1byte src and max 4 byte b2m out            //~v6x4I~
    UCHAR wkdbcs[8];                                               //~v6x4I~
//  WUCS ucs=0;                                                      //~v66qI~//~v6h7R~//~v6BuR~
    UWUCS ucs=0;                                                   //~v6BuI~
    UWUCS ucs4;                                                    //~v6f3I~
    UCHAR *pce2a,*pca2e,mb;                                        //~v66RR~
//  ULONG plocalconverter;                                         //~v6x5R~
    ULPTR plocalconverter;                                         //~v6x5I~
    int rc2,swoverride,swdup,jj;                                   //~v66RR~
    int mb2;                                                       //~v66UI~
                                                                   //~v69cI~
    PUCVEBCH pucveh;                                               //~v69cI~
	UCHAR *pu2bmap;                                                //~v69cI~
//  WUCS  *pb2umap;                                                //~v69cI~//~v6BuR~
    UWUCS  *pb2umap;   //ucs4                                      //~v6BuI~
	UCHAR *pu2bffmap;                                              //~v69cI~
//	WUCS  *pu2bnonasciimapucs;                                     //~v69cI~//~v6BuR~
  	UWUCS  *pu2bnonasciimapucs;                                    //~v6BuI~
	UCHAR *pu2bnonasciimapebc;                                     //~v69cI~
	int   u2bnonasciictr=0;                                        //~v69cI~
	UCHAR *ptoupper;                                               //~v69cI~
	UCHAR *ptolower;                                               //~v69cI~
	UCHAR *pa2bmap;    //ascii->ebc map for sbcs                   //~v69cI~
   	ULONG *pb2amap;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
   	UCHAR *pctype;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
    int handle;                                                    //~v69cI~
//***************************
    handle=0;                                                      //~v69cR~
	pucveh=UCVEBC_GETPUCVEH(handle);                               //~v69cR~
	pu2bmap=pucveh->UCVEHu2bmap;                                   //~v69cI~
	pb2umap=pucveh->UCVEHb2umap;                                   //~v69cI~
	pu2bffmap=pucveh->UCVEHu2bffmap;                               //~v69cI~
	pu2bnonasciimapucs=pucveh->UCVEHu2bnonasciimapucs;             //~v69cI~
	pu2bnonasciimapebc=pucveh->UCVEHu2bnonasciimapebc;             //~v69cI~
	ptoupper=pucveh->UCVEHtoupper;                                 //~v69cI~
	ptolower=pucveh->UCVEHtolower;                                 //~v69cI~
	pa2bmap=pucveh->UCVEHa2bmap;    //ascii->ebc map for sbcs      //~v69cI~
   	pb2amap=pucveh->UCVEHb2amap;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
    pctype=pucveh->UCVEHctype;                                     //~v69cI~
                                                                   //~v69cI~
    plocalconverter=Spcfg->UCECconverterlocal;                     //~v66RI~
	for (ii=0;ii<26;ii++)
    {
//  	ebcl=ucvebc3_m2b1Sbcs1(0,ii+'a');                          //~v66qR~//~v69cR~
//  	ebcl=ucvebc3_m2b1Sbcs1(0,handle,ii+'a');                   //~v69cI~//~v6BiR~
    	ebcl=(UCHAR)ucvebc3_m2b1Sbcs1(0,handle,ii+'a');            //~v6BiI~
        ebclower[ii]=ebcl;
//      Gucvebc_ctype[ebcl]|=EBCTYPE_LOWER;                        //~v69cR~
        pctype[ebcl]|=EBCTYPE_LOWER;                               //~v69cI~
//  	ebcu=ucvebc3_m2b1Sbcs1(0,ii+'A');                          //~v66qR~//~v69cR~
//  	ebcu=ucvebc3_m2b1Sbcs1(0,handle,ii+'A');                   //~v69cI~//~v6BiR~
    	ebcu=(UCHAR)ucvebc3_m2b1Sbcs1(0,handle,ii+'A');            //~v6BiI~
        ebcupper[ii]=ebcu;
//      Gucvebc_ctype[ebcu]|=EBCTYPE_UPPER;                        //~v69cR~
        pctype[ebcu]|=EBCTYPE_UPPER;                               //~v69cI~
    }
    opt=EBC2ASC_CTL|Sebcopta2e;	//additional parm                  //~v66sR~//~v66vR~
    optb2m=UCVEBC3O_CVCTL;                                         //~v66vI~
    opt3=UCVEBC3O_CVCTL|UCVEBC3O_SBCS;	//additional parm          //~v66qR~
    if (Spcfg->UCECflag & UCECF_E2A)     //a2a mapping specified   //~v66RI~
        pce2a=Spcfg->UCECsbcsmape2a;                               //~v66RR~
    else                                                           //~v66RI~
    	pce2a=0;                                                   //~v66RI~
    if (Spcfg->UCECflag & UCECF_A2E)     //a2a mapping specified   //~v66RI~
        pca2e=Spcfg->UCECsbcsmapa2e;                               //~v66RR~
    else                                                           //~v66RI~
    	pca2e=0;                                                   //~v66RR~
    plocalconverter=Spcfg->UCECconverterlocal;                     //~v66RI~
	for (ii=0;ii<256;ii++) //all ascii
    {
//		if ((ebc=ucvebc3_m2b1Sbcs1(opt,ii))>=0)                    //~v66qR~//~v66RR~
		if (pca2e && (ebc=pca2e[ii],ebc))                          //~v66VR~
//      	Gucvebc_a2bmap[ii]=ebc;                                //~v66VI~//~v69cR~
//      	pa2bmap[ii]=ebc;                                       //~v69cI~//~v6BiR~
        	pa2bmap[ii]=(UCHAR)ebc;                                //~v6BiI~
        else                                                       //~v66VI~
        {                                                          //~v66VI~
          if (ii==CHAR_SO||ii==CHAR_SI)                            //~v66VI~
//      	Gucvebc_a2bmap[ii]=ii;                                 //~v66VI~//~v69cR~
//      	pa2bmap[ii]=ii;                                        //~v69cI~//~v6BiR~
        	pa2bmap[ii]=(UCHAR)ii;                                 //~v6BiI~
          else                                                     //~v66VI~
          {                                                        //~v66VI~
//			ebc=ucvebc3_m2b1Sbcs1(opt,ii);                         //~v66RI~//~v69cR~
  			ebc=ucvebc3_m2b1Sbcs1(opt,handle,ii);                  //~v69cI~
   		if (ebc>=0)                                                //~v66RI~
//      	Gucvebc_a2bmap[ii]=ebc;                                //~v69cR~
//      	pa2bmap[ii]=ebc;                                       //~v69cI~//~v6BiR~
        	pa2bmap[ii]=(UCHAR)ebc;                                //~v6BiI~
          }                                                        //~v66VI~
//        else                                                     //~v66VR~
//        {                                                        //~v66VR~
//            if (ii==CHAR_SO||ii==CHAR_SI)                        //~v66VR~
//                Gucvebc_a2bmap[ii]=ii;                           //~v66VR~
//                                                                 //~v66VR~
//        }                                                        //~v66VR~
        }                                                          //~v66VI~
//      UTRACEP("setletter a2b mb=%x--->ebc=%x\n",ii,pa2bmap[ii]);      //~v66qI~//~v66vR~//~v66HR~//~v69cR~//~v6m3R~
        wkch[0]=(UCHAR)ii;                                         //~v66vR~
//		if (!ucvebc3_b2mSbcs(optb2m,wkch,wkdbcs,1,wkch+1,sizeof(wkch)-1,&len))//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v66vR~//~v66RR~
		if (pce2a && (wkch[1]=pce2a[ii],wkch[1]))                  //~v66RI~
        {                                                          //~v66RI~
        	rc2=0;                                                 //~v66RI~
            len=1;                                                 //~v66RI~
        }                                                          //~v66RI~
        else                                                       //~v66RI~
//  		rc2=ucvebc3_b2mSbcs(optb2m,wkch,wkdbcs,1,wkch+1,sizeof(wkch)-1,&len);//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v68bR~
//			rc2=ucvebc3_b2mSbcs(optb2m,wkch,wkdbcs,1,wkch+1,wkdbcs,sizeof(wkch)-1,&len);//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v68bI~//~v69cR~
  			rc2=ucvebc3_b2mSbcs(optb2m,handle,wkch,wkdbcs,1,wkch+1,wkdbcs,sizeof(wkch)-1,&len);//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v69cI~
        if (!rc2)                                                  //~v66RI~
        {                                                          //~v66UI~
          if (len>1)    //sbcs->dbcs by EUC hankana                //~v66UI~
          {                                                        //~v66UI~
           if (len==4)                                             //~v66XI~
           {                                                       //~v66XI~
//          Gucvebc_ctype[ii]|=EBCTYPE_GB4|EBCTYPE_DBCS;           //~v66XI~//~v69cR~
            pctype[ii]|=EBCTYPE_GB4|EBCTYPE_DBCS;                  //~v69cI~
            mb2=UBESTR2UL(wkch+1);                                 //~v66XR~
           }                                                       //~v66XI~
           else                                                    //~v66XI~
           if (len==3)                                             //~v66XI~
           {                                                       //~v66XI~
//          Gucvebc_ctype[ii]|=EBCTYPE_SS3|EBCTYPE_DBCS;           //~v66XR~//~v69cR~
            pctype[ii]|=EBCTYPE_SS3|EBCTYPE_DBCS;                  //~v69cI~
            mb2=UBESTR2UL3(wkch+1);                                //~v66XR~
           }                                                       //~v66XI~
           else                                                    //~v66XI~
           {                                                       //~v66XI~
            mb2=UBESTR2US(wkch+1);                                 //~v66XR~
//          Gucvebc_ctype[ii]|=EBCTYPE_DBCS;                       //~v66XM~//~v69cR~
            pctype[ii]|=EBCTYPE_DBCS;                              //~v69cI~
           }                                                       //~v66XI~
//      	Gucvebc_b2amap[ii]=mb2;                                //~v66UI~//~v69cR~
//      	pb2amap[ii]=mb2;                                       //~v69cI~//~v6BkR~
        	pb2amap[ii]=(ULONG)mb2;                                //~v6BkI~
          }                                                        //~v66UI~
          else                                                     //~v66UI~
//      	Gucvebc_b2amap[ii]=wkch[1];                            //~v66vR~//~v69cR~
        	pb2amap[ii]=wkch[1];                                   //~v69cI~
        }                                                          //~v66UI~
        else                                                       //~v66vR~
        {                                                          //~v66vR~
            if (ii==CHAR_SO||ii==CHAR_SI)                          //~v66vR~
//      		Gucvebc_b2amap[ii]=ii;                             //~v66vR~//~v69cR~
//      		pb2amap[ii]=ii;                                    //~v69cI~//~v6BkR~
        		pb2amap[ii]=(ULONG)ii;                             //~v6BkI~
        }                                                          //~v66vR~
//      UTRACEP("setletter b2a mb=%08x<--ebc=%02x\n",pb2amap[ii],ii);      //~v66vR~//~v66XR~//~v69cR~//~v6m3R~
//        if (!ucvebc3_u2b1(opt3,(WUCS)ii,wkch,0/*outlen*/))          //~v66pI~//~v66qR~//~v66sR~//~v66HR~
//            Su2bmap[ii]=wkch[0];    //u2b mapping          //~v66pR~//~v66qI~//~v66sR~//~v66HR~
//        else                                                       //~v66sI~//~v66HR~
//        {                                                          //~v66sI~//~v66HR~
//            if (ii==CHAR_SO||ii==CHAR_SI)                          //~v66sI~//~v66HR~
//                Su2bmap[ii]=ii; //set so/si mapping                //~v66sI~//~v66HR~
//        }                                                          //~v66sI~//~v66HR~
//        UTRACEP("setletter u2b ucs=%x,ebc=%x\n",ii,(int)wkch[0]);     //~v66qI~//~v66sR~//~v66HR~
        wkch[0]=(UCHAR)ii;                                            //~v66qI~//~v66sR~
//  	if (!ucvebc3_b2uSbcs1(opt3,wkch,0/*repch*/,&ucs))         //~v66qR~//~v66sR~//~v66RR~
		rc2=1;                                                     //~v66RI~
        swoverride=0;                                              //~v66RI~
		if (plocalconverter && pce2a && (mb=pce2a[ii],mb))   //accept ascii(ucs==ascii) only//~v66RR~
        {                                                          //~v6f3I~
          if (UDBCSCHK_IS_LOCALICU())                              //~v6f3I~
          {                                                        //~v6f3I~
            rc2=ucvext_icumb2ucs1(UCVEXTO_SETSUBCHRC,plocalconverter,&mb,1,0/*chklen*/,&ucs4);//~v6f3R~
//          ucs=ucs4;                                              //~v6f3I~//~v6BiR~
//          ucs=(WUCS)ucs4;                                        //~v6BiI~//~v6BuR~
            ucs=ucs4;                                              //~v6BuI~
          }                                                        //~v6f3I~
          else                                                     //~v6f3I~
          {                                                        //~v6BjI~
//          rc2=ucvext_iconvlocal2ucs1(opt,plocalconverter,&mb,1,0/*chklen*/,&ucs);//~v66RI~//~v6BjR~
            rc2=ucvext_iconvlocal2ucs1(opt,plocalconverter,&mb,1,0/*chklen*/,&ucs4);//~v6BjI~
//          ucs=ucs4;                                              //~v6BjI~//~v6BiR~
//          ucs=(WUCS)ucs4;                                        //~v6BiI~//~v6BuR~
            ucs=ucs4;                                              //~v6BuI~
          }                                                        //~v6BjI~
        }                                                          //~v6f3I~
        if (rc2)                                                   //~v66RI~
        {                                                          //~v6BjI~
//  		rc2=ucvebc3_b2uSbcs1(opt3,wkch,0/*repch*/,&ucs);       //~v66RI~//~v69cR~
//  		rc2=ucvebc3_b2uSbcs1(opt3,handle,wkch,0/*repch*/,&ucs);//~v69cI~//~v6BjR~
    		rc2=ucvebc3_b2uSbcs1(opt3,handle,wkch,0/*repch*/,&ucs4);//~v6BjR~
//          ucs=(WUCS)ucs4;                                        //~v6BjI~//~v6BuR~
            ucs=ucs4;                                              //~v6BuI~
        }                                                          //~v6BjI~
        else                                                       //~v66RI~
        	swoverride=1;	//ucs by local2ucs                     //~v66RR~
    	if (!rc2)                                                  //~v66RI~
        {                                                          //~v66HI~
//          Sb2umap[ii]=ucs;				//b2u mapping          //~v66qI~//~v69cR~
            pb2umap[ii]=ucs;				//b2u mapping          //~v69cI~
            if (ucs<0x100)                                         //~v66HI~
            {                                                      //~v66RI~
//            if (swoverride||!Su2bmap[ucs])	//dup is err if not by cfg parm//~v66RI~//~v69cR~
              if (swoverride||!pu2bmap[ucs])	//dup is err if not by cfg parm//~v69cI~
//              Su2bmap[ucs]=ii;				//reverse          //~v66HI~//~v69cR~
//              pu2bmap[ucs]=ii;				//reverse          //~v69cI~//~v6BiR~
                pu2bmap[ucs]=(UCHAR)ii;				//reverse      //~v6BiI~
//              else                                               //~v6g1R~
//              if (pu2bmap[ucs]==ucs)    //set ucs=ebc if ucs=0 at b2usbcs//~v6g1R~
//                pu2bmap[ucs]=ii;                //override       //~v6g1R~
            }                                                      //~v66RI~
            else                                                   //~v66HI~
            if ((ucs>>8)==0xff)     //0xffxx	//japanese hankaku katakana//~v66HI~
            {                                                      //~v66RI~
//            if (swoverride||!Su2bffmap[ucs & 0xff])	//dup is err if not by cfg parm//~v66RI~//~v69cR~
              if (swoverride||!pu2bffmap[ucs & 0xff])	//dup is err if not by cfg parm//~v69cI~
//              Su2bffmap[ucs & 0xff]=ii;		//reverse          //~v66HI~//~v69cR~
//              pu2bffmap[ucs & 0xff]=ii;		//reverse          //~v69cI~//~v6BiR~
                pu2bffmap[ucs & 0xff]=(UCHAR)ii;		//reverse  //~v6BiI~
            }                                                      //~v66RI~
            else                                                   //~v66HI~
            {                                                      //~v66HI~
            	swdup=0;                                           //~v66RI~
//            	for (jj=0;jj<Su2bnonasciictr;jj++)                 //~v66RR~//~v69cR~
              	for (jj=0;jj<u2bnonasciictr;jj++)                  //~v69cI~
                {                                                  //~v66RI~
//              	if (ucs==Su2bnonasciimapucs[jj])	//duplicated ebc to ucs//~v66RI~//~v69cR~
                	if (ucs==pu2bnonasciimapucs[jj])	//duplicated ebc to ucs//~v69cI~
                    {                                              //~v66RI~
                    	swdup=1;                                   //~v66RI~
                    	if (swoverride)                            //~v66RI~
//  			            Su2bnonasciimapebc[jj]=ii;		//ebc  //~v66RI~//~v69cR~
//  			            pu2bnonasciimapebc[jj]=ii;		//ebc  //~v69cI~//~v6BiR~
    			            pu2bnonasciimapebc[jj]=(UCHAR)ii;		//ebc//~v6BiI~
                    	break;                                     //~v66RI~
                    }                                              //~v66RI~
                }                                                  //~v66RI~
              if (!swdup)                                          //~v66RI~
              {                                                    //~v66RI~
//              Su2bnonasciimapebc[Su2bnonasciictr]=ii;		//ebc  //~v66HI~//~v69cR~
//              pu2bnonasciimapebc[u2bnonasciictr]=ii;		//ebc  //~v69cI~//~v6BiR~
                pu2bnonasciimapebc[u2bnonasciictr]=(UCHAR)ii;		//ebc//~v6BiI~
//              Su2bnonasciimapucs[Su2bnonasciictr++]=ucs;		//reverse//~v66HR~//~v69cR~
                pu2bnonasciimapucs[u2bnonasciictr++]=ucs;		//reverse//~v69cI~
              }                                                    //~v66RI~
            }                                                      //~v66HI~
        }                                                          //~v66HI~
        else                                                       //~v66sI~
        {                                                          //~v66sI~
            if (ii==CHAR_SO||ii==CHAR_SI)                          //~v66sI~
            {                                                      //~v66HI~
//              Sb2umap[ii]=ii;				//b2u mapping          //~v66sI~//~v69cR~
//              pb2umap[ii]=ii;				//b2u mapping          //~v69cI~//~v6BiR~
//              pb2umap[ii]=(WUCS)ii;				//b2u mapping  //~v6BiI~//~v6BuR~
                pb2umap[ii]=(UWUCS)ii;				//b2u mapping  //~v6BuI~
//              Su2bmap[ii]=ii;				//u2b mapping          //~v66HI~//~v69cR~
//              pu2bmap[ii]=ii;				//u2b mapping          //~v69cI~//~v6BiR~
                pu2bmap[ii]=(UCHAR)ii;				//u2b mapping  //~v6BiI~
            }                                                      //~v66HI~
        }                                                          //~v66sI~
//      UTRACEP("setletter b2u ucs=%x,ebc=%x\n",pb2umap[ii],ii);           //~v66qI~//~v66HR~//~v69cR~//~v6m3R~
//#ifndef AAA                                                        //~v66sI~//~v66HR~
//        ucvext_icuucs2local1wocv(0,ucs,wkch,&len);                 //~v66sI~//~v66HR~
//        UTRACEP("setletter U2L ucs=%x,len=%d,mb=%x\n",ucs,len,wkch[0]);//~v66sR~//~v66HR~
//#endif                                                             //~v66sI~//~v66HR~
//  	Gucvebc_toupper[ii]=ii;                                    //~v69cR~
//  	ptoupper[ii]=ii;                                           //~v69cI~//~v6BiR~
    	ptoupper[ii]=(UCHAR)ii;                                    //~v6BiI~
//  	Gucvebc_tolower[ii]=ii;                                    //~v69cR~
//  	ptolower[ii]=ii;                                           //~v69cI~//~v6BiR~
    	ptolower[ii]=(UCHAR)ii;                                    //~v6BiI~
    }
#ifdef AAA  //internal map has no u2b map                          //~v66RI~
    if (pca2e)                                                     //~v66RI~
        for (ii=0;ii<128;ii++) //asccept ascii(ucs==ascii) only    //~v66RI~
        {                                                          //~v66RI~
            if (ebc=pca2e[ii],ebc)                                 //~v66RI~
	            Su2bmap[ii]=ebc;                                   //~v66RI~
            UTRACEP("setletter u2b by cfg a2e ucs=%02x--->ebc=%x\n",ii,Su2bmap[ii]);//~v66RI~
        }                                                          //~v66RI~
#endif                                                             //~v66RI~
	for (ii=0;ii<26;ii++)
    {
		ebcl=ebclower[ii];
		ebcu=ebcupper[ii];
//      Gucvebc_toupper[ebcl]=ebcu;                                //~v69cR~
        ptoupper[ebcl]=ebcu;                                       //~v69cI~
//      Gucvebc_tolower[ebcu]=ebcl;                                //~v69cR~
        ptolower[ebcu]=ebcl;                                       //~v69cI~
    }
#ifdef AAA //fallback test                                         //~v66qR~
	for (ii=0xff01;ii<0xff10;ii++) //all ascii                     //~v66qI~
    {                                                              //~v66qI~
//		ucvebc3_u2b1(opt3,(WUCS)ii,&wkch,0/*outlen*/);             //~v66qR~//~v6BjR~
  		ucvebc3_u2b1(opt3,(UWUCS)ii,&wkch,0/*outlen*/);            //~v6BjI~
        UTRACEP("setletter fbtest u2b ucs=%x,ebc=%x\n",ii,(int)wkch);//~v66qI~
    }                                                              //~v66qI~
#endif                                                             //~v66qI~
    UTRACED("toupper",ptoupper,256);                               //~v69cR~
    UTRACED("tolower",ptolower,256);                               //~v69cR~
    UTRACED("ctype",pctype,256);                                   //~v69cR~
    UTRACED("a2b  ",pa2bmap,256);                                  //~v69cR~
    UTRACED("b2a  ",pb2amap,sizeof(pucveh->UCVEHb2amap));        //~v66UR~//~v69cR~
	UTRACED("u2b",pu2bmap,sizeof(pucveh->UCVEHu2bmap));                        //~v66pI~//~v69cR~
	UTRACED("b2u",pb2umap,sizeof(pucveh->UCVEHb2umap));                        //~v66qI~//~v69cR~
	UTRACED("u2bff",pu2bffmap,sizeof(pucveh->UCVEHu2bffmap));                  //~v66HI~//~v69cR~
	UTRACED("u2bnonasciiucs",pu2bnonasciimapucs,u2bnonasciictr*(int)UWUCSSZ);//~v66HR~//~v66NR~//~v69cR~//~v6BkR~//~v6BuR~
	UTRACED("u2bnonasciiebc",pu2bnonasciimapebc,u2bnonasciictr);     //~v66HI~//~v66NR~//~v69cR~
//  Gucvebc_stat|=UCVEBCS_SBCSMAPINIT;//sbcsmap was initialized    //~v69cR~
    pucveh->UCVEHflag|=UCVEHF_SBCSMAPINIT;//sbcsmap was initialized//~v69cI~
    pucveh->UCVEHu2bnonasciictr=u2bnonasciictr;                    //~v69cI~
//  ucvebc_getsubchar_dbcs(0);		//init dbcs repch              //~v66cI~//~v66CR~
    return 0;
}//ucvebc3_setletter
//****************************************************************
//read cfg parm
//****************************************************************
//int ucvebc3_init(int Popt,ULONG *Pcfg)                             //~v660R~//~v6hhR~
int ucvebc3_init(int Popt,ULPTR *Pcfg)                             //~v6hhI~
{
	UCVEXTCFG *pcfg;
//  UCVEBCH   *pucveh;                                             //~v6b9R~
    char *pfnm;
    int rc=0,opt;
//*****************
    if (Gucvebc_stat & UCVEBCS_xcv)          //on xcv    process  to ucvext_mapinit//~va54I~//~v6bjI~
    {                                                              //~v6bjI~
        Spcfg=(PUCVEXTCFG)(*Pcfg);                                 //~v6bjR~
        UTRACEP("ucvebc3_init for xcv cfg=%p\n",Spcfg);            //~v6bjI~
    	return ucvebc3_init_xcv(Popt,(PUCVEXTCFG)(*Pcfg));         //~v6bjR~
    }                                                              //~v6bjI~
//  pucveh=UCVEBC_GETPUCVEH(0);                                    //~v69cI~//~v6b9R~
	if (Popt & UCVEBC3O_CFGFILE)
    {
//      pfnm=(char*)(ULONG)Pcfg;                                   //~v660R~//~v6hhR~
        pfnm=(char*)(ULPTR)Pcfg;                                   //~v6hhI~
        opt=UCEIO_LOCALEDIT|UCEIO_SAVECV|UCEIO_SAVEMAP|UCEIO_NOERRMSG;
        if (Popt & UCVEBC3O_ERREXIT)                               //~v69wR~
        	opt|=UCEIO_ERREXIT;                                    //~v69wR~
        if (Popt & UCVEBC3O_ERRMSG)                                //~v69wI~
        	opt&=~UCEIO_NOERRMSG;                                  //~v69wI~
        if (Popt & UCVEBC3O_USEICU)                                //~v6m3I~
        	opt|=UCEIO_USEICU;  //use icu if cfg err               //~v6m3I~
                                                                   //~v69wI~
        if (ucvext_mapinit(opt,pfnm,&pcfg))
			rc=4;
//      else                                                       //~v66MR~
        {
        	Spcfg=pcfg;
        	opt=UCEGCOO_CHKDBCS;    //set EBC2ASC_DBCS etc//~0501R~//~v660R~
//        	opt|=UCEGCOO_IGNEUC;    //not use EUC for B2DD,but sue for b2l//~v660R~
			ucvext_getcvoption(opt,Spcfg,&Sebcopte2a);
//            Sebcopta2e=Sebcopte2a;                               //~v688R~
			ucvext_getcvoption(opt,Spcfg,&Sebcopta2e);             //~v688R~
			ucvebcinita2e(Sebcopta2e);	//init CP290(kana)/CP1027(Eng)//~0501I~
			ucvebc_defaultremap(0,pcfg);	//apply cfg E2A/A2E option for no converter use case//~v66RR~
        	ucvebc3_getcfgparmconverter(0,Spcfg,Spcve2a,Spcva2e);//opt:map/local/mapc
      		ucvebc3_getconvertersubchar(0,Spcfg);
      		ucvebc3_setletter(0);
        }
        return rc;
    }
	if (Popt & UCVEBC3O_GETCFG)                                    //~v660I~
    {                                                              //~v660I~
//      *Pcfg=(ULONG)Spcfg;                                        //~v660R~//~v6hhR~
        *Pcfg=(ULPTR)Spcfg;                                        //~v6hhI~
        return 0;                                                  //~v660I~
    }                                                              //~v660I~
    return 0;
}//ucvebc3_init
//****************************************************************
//*ebc->dd fmt
//****************************************************************
int ucvebc3_cfgerr(void)
{
//********************
    uerrmsg("EBCDIC traslation will not be done by EBCDIC map config file err",
    		"EBCDIC map config ファイルにエラーがあります。EBCDIC変換できません");
    return 8;
}//ucvebc3_cfgerr
//*************************************************************************
//*ebc->ucs1(SBCS) int/ext
//* 1 ebc to ucs
//*rc:1:errrep
//*************************************************************************
//int ucvebc3_b2uSbcs1(int Popt,UCHAR *Ppebc,int Prepch,WUCS *Ppucs)//~v69cR~
//int ucvebc3_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,WUCS *Ppucs)//~v69cI~//~v6BjR~
int ucvebc3_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UWUCS *Ppucs)//~v6BjI~
{
    int rc=0,rc2,opt;                                              //~0428R~
//  USHORT usucs;                                                  //~v66CR~
    UWUCS  usucs;                                                  //~v66CI~
//  WUCS wucs;                                                     //~v6BjR~
    UWUCS wucs;                                                    //~v6BjI~
    UCHAR ch,*pmap,*pmapc,chebc;
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    PUCVEBCH pucveh;                                               //~v69cR~
//***************************
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
    chebc=*Ppebc;
    opt=Sebcopte2a;                                                //~0428I~
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66NR~
    if (Popt & UCVEBC3O_CVCTL)                                     //~0428I~
        opt|=EBC2ASC_CTL;	                                       //~0428I~
//  if (!(Sebcopte2a & EBC2ASC_EXT))//if not Japanese,EXT on and use cp037 map//~v69cR~
    if (!Phandle                                                   //~v69cI~
    &&  !(Sebcopte2a & EBC2ASC_EXT)//if not Japanese,EXT on and use cp037 map//~v69cI~
       )                                                           //~v69cI~
    {
#ifdef AAA
    	optucs=Sucsopt;
        rc=ucvebc2asc1sbcsJ(opt,Ppebc,Prepch,&sjis);//rc=1 when errrep//~0428R~
//      wucs=(WUCS)uccvsjis2ucs(optucs,sjis);                      //~v6BjR~
        wucs=(UWUCS)uccvsjis2ucs(optucs,sjis);                     //~v6BjI~
        if (wucs==UCVERRUCS)
        {
            wucs=Prepch;
            rc|=1;
        }
#else
    	rc=ucvebc2ucs1sbcsJ(opt,Ppebc,Prepch,&wucs);               //~0428R~
#endif
    }
    else
    {
//    if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v66qI~//~v69cR~
      if (UCVEBCH_ISSBCSMAPINIT(pucveh))//sbcsmap was initialized  //~v69cI~
      {                                                            //~v66qI~
    	if (chebc<CHAR_EBC_SPACE     //ctl char                    //~v66qI~
		&&  !(opt & EBC2ASC_CTL)                                   //~v66qI~
        )                                                          //~v66qI~
            wucs=0;	//errrep later                                 //~v66qI~
        else                                                       //~v66qI~
//    		wucs=Sb2umap[(int)chebc];                              //~v66qR~//~v69cR~
//    		wucs=pucveh->UCVEHb2umap[(int)chebc];                  //~v69cI~//~v6BjR~
      		wucs=(UWUCS)pucveh->UCVEHb2umap[(int)chebc];           //~v6BjI~
        if (!wucs && chebc)                                        //~v66qR~
        {	                                                       //~v66qI~
//      	wucs=Prepch;                                           //~v66qI~//~v6BjR~
//      	wucs=(WUCS)Prepch;                                     //~v6BiI~//~v6BjR~
        	wucs=(UWUCS)Prepch;                                    //~v6BjI~
            rc|=1;                                                 //~v66qI~
        }                                                          //~v66qI~
		UTRACEP("b2uSbcs aftermapinit opt=%x,ebc=%x,ucs=%x,rc=%d\n",Popt,chebc,wucs,rc);//~v66qR~
      }                                                            //~v66qI~
      else                                                         //~v66qI~
      {                                                            //~v66qI~
       if (Phandle)                                                //~v69cI~
        pconverter=pucveh->UCVEHpconverter[CONVERTER_SBCS];        //~v69cR~
       else                                                        //~v69cI~
        pconverter=Spcve2a[CONVERTER_SBCS];
        pmap=(UCHAR*)Spcve2a[CONVERTER_SBCSMAP];
        pmapc=(UCHAR*)Spcve2a[CONVERTER_SBCSMAPC];
//      UTRACEP("ebc3b2uSbcs1 opt=%x ebc1=%02x\n",Popt,*Ppebc);    //~v6m3R~
        if ( (Sebcopte2a & EBC2ASC_SBCSMAPC)    //special code point
        &&   !Phandle            //cfg converter                   //~v69cI~
        &&   (ch=pmapc[chebc]))  //source is sbcs
        {
            wucs=ch;
//  UTRACEP("b2usbcs SBCSMAPC %02x->%02x\n",chebc,wucs);           //~v6m3R~
        }
        else
        if ( (Sebcopte2a & EBC2ASC_SBCSMAP) //special code point
        &&   !Phandle            //cfg converter                   //~v69cI~
        )
        {
    		if (chebc<CHAR_EBC_SPACE     //ctl char
			&&  !(opt & EBC2ASC_CTL)                               //~0428R~
            )
            	wucs=0;	//errrep later
            else
//          	wucs=pmap[chebc];                                  //~v6BjR~
            	wucs=(UWUCS)pmap[chebc];                           //~v6BjI~
//  UTRACEP("b2usbcs by SBCSMAP %02x->%02x\n",chebc,wucs);         //~v6m3R~
//#ifdef BBB                                                       //~v6g1R~
            if (!wucs && chebc)                                    //~v66mI~
//                wucs=chebc; //keep org value                       //~v66mI~//~v6g1R~
                rc|=1;                                             //~v6g1I~
//#endif                                                           //~v6g1R~
        }
        else
        {
            rc2=ucvext_icuebc2ucs1(opt,pconverter,Ppebc,1,&usucs); //~0428R~
//setsubch is replaced by parameter repch                          //~v66DI~
            if (rc2)
            {
//              wucs=Prepch;                                       //~v6BiR~
//              wucs=(WUCS)Prepch;                                 //~v6BiI~//~v6BjR~
                wucs=(UWUCS)Prepch;                                //~v6BjI~
                rc|=1;
            }
            else
            {                                                      //~v66sI~
//              if (usucs>=0x100  // chk dbcs subchar was set      //~v66sR~
//              &&  utfwcwidth(0,usucs,0)==2) //dbcs subchar was set//~v66sR~
//              {                                                  //~v66sR~
//                rc|=1;                                           //~v66sR~
//                wucs=Prepch;                                     //~v66sR~
//              }                                                  //~v66sR~
//              else                                               //~v66sR~
//              wcwidth of output ucs may be any for b2U           //~v66sI~
//              if (usucs==ICU_STD_SUBCHAR_UCS)  // icu subchar fffd //~v66zI~//~v66DR~
//              {                                                    //~v66zI~//~v66DR~
//                rc|=1;                                             //~v66zI~//~v66DR~
//                wucs=Prepch;                                       //~v66zI~//~v66DR~
//              }                                                    //~v66zI~//~v66DR~
//              else                                                 //~v66zI~//~v66DR~
//              wucs=usucs;                                        //~v6BjR~
//              wucs=(WUCS)usucs;                                  //~v6BjR~
                wucs=usucs;                                        //~v6BjI~
            }                                                      //~v66sI~
        }
//        if (!rc)                                                 //~v66DR~
//            if ((!wucs && chebc)                                 //~v66DR~
//            ||  (wucs==CHAR_ASCII_ERR && chebc!=CHAR_EBC_ERR) //"?"//~v66DR~
////            ||  (wucs==CHAR_UCS_SUB   && chebc!=CHAR_EBC_SUB) //0x1a and 0x3f//~v66mR~//~v66DR~
//            ||  (wucs==CHAR_UCS_SUB/*0x1a*/ && chebc!=CHAR_EBC_SUB/*0x3f*/) //0x1a and 0x3f,not kept org value by map//~v66mI~//~v66sR~//~v66DR~
//            ||  (wucs=='.' && chebc!=EBC_PERIOD)    //err rep occured//~v66DR~
//            )                                                    //~v66DR~
//            {                                                    //~v66DR~
//                wucs=Prepch;                                     //~v66DR~
//                rc|=1;                                           //~v66DR~
//            }                                                    //~v66DR~
      }//!not yet mapinit                                          //~v66qI~
    }
    *Ppucs=wucs;
//  UTRACEP("ucvebc3_b2uSbcs1 rc=%x,in=%02x,outucs=%x\n",rc,*Ppebc,wucs);//~v6m3R~
    return rc;
}//ucvebc3_b2uSbcs1
//*************************************************************************
//*ebc->dd1(SBCS) int/ext
//* 1 ebc to dd/utf8                                               //~0425R~
//* dbcs is optional for b2dd                                      //~0425I~
//*rc:1:errrep
//*************************************************************************
//int ucvebc3_b2ddSbcs1(int Popt,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen)//~0425R~//~v69cR~
//int ucvebc3_b2ddSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen)//~v69cI~//~v6BjR~
int ucvebc3_b2ddSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,UWUCS *Ppwucs,int *Ppoutlen)//~v6BjI~
{
//  int rc=0,rc2,len,swb2f;                                        //~0425R~//~v6h6R~
    int rc=0,rc2,len=0,swb2f;                                      //~v6h6I~
//  WUCS wucs,repch;                                               //~v6BjR~
    UWUCS wucs,repch;                                              //~v6BjR~
//***************************
//  repch=(WUCS)(Prepch&0xff);                                     //~v6BjR~
    repch=(UWUCS)(Prepch&0xff);                                    //~v6BjI~
    swb2f=(Popt & UCVEBC3O_B2F);	//ebc->utf8                    //~0425R~
//repch=0 when from xeebc:b2ddtab                                  //~v66CM~
    if (!repch)
//  	repch=CHAR_ASCII_ERR;                                      //~v66CR~
//  	repch=Ssubcharsbcs;	//by ucs,may be changed by cfg parm    //~v66CR~//~v69cR~
    	repch=UCVEBCH_subcharsbcs(Phandle);	//by ucs,may be changed by cfg parm//~v69cI~
//  rc2=ucvebc3_b2uSbcs1(Popt,Ppebc,repch,&wucs);                  //~v69cR~
    rc2=ucvebc3_b2uSbcs1(Popt,Phandle,Ppebc,repch,&wucs);          //~v69cI~
    if (!wucs)                                                     //~v686I~
    	if (Popt & UCVEBC3O_REPNULL)                               //~v686I~
        	wucs=' ';                                              //~v686I~
    if (!rc2)                                                      //~0425R~
    {                                                              //~0425R~
    	if (swb2f)	//ebc->utf8                                    //~0425I~
    	{                                                          //~0425I~
//    		len=uccvucs2utf((ULONG)wucs,Pdddata);                  //~0425I~//~v6BkR~
      		len=uccvucs2utf(wucs,Pdddata);                         //~v6BkI~
        	if (!len)                                              //~0425I~
        		rc2=4;                                             //~0425I~
    	}                                                          //~0425I~
    	else                                                       //~0425I~
    	{                                                          //~0425I~
            UTF_U2DD1(wucs,Pdddata,Pdddbcs,&len);                  //~0425R~
            if (len!=1)                                            //~0425R~
              if (!(Popt & UCVEBC3O_DBCSUCSOK))                    //~v69kI~
                rc2=4;                                             //~0425R~
        }                                                          //~0425R~
    }                                                              //~0425I~
    if (rc2)                                                       //~0425R~
    {                                                              //~0425R~
    	if (swb2f)	//ebc->utf8                                    //~0425I~
//    		len=uccvucs2utf((ULONG)repch,Pdddata);                 //~0425I~//~v6BkR~
      		len=uccvucs2utf(repch,Pdddata);                        //~v6BkI~
    	else                                                       //~0425I~
        	UTF_U2DD1(repch,Pdddata,Pdddbcs,&len);                 //~0425R~
        rc=1;                                                      //~0425R~
    }                                                              //~0425R~
    if (Ppwucs)
    	*Ppwucs=wucs;
    if (Ppoutlen)                                                  //~0425I~
    	*Ppoutlen=len;                                             //~0425I~
    UTRACEP("ucvebc3_b2ddSbcs1 rc=%x,opt=%x,in=%02x,outdd=%x,outdbcs=%x,len=%d,\n",rc,Popt,*Ppebc,*Pdddata,UWHICH(swb2f,0,*Pdddbcs),len);//~0425R~//~v660R~//~v69yR~
    UTRACED("ucvebc3_b2ddSbcs1 outdata",Pdddata,len);              //~v660I~
    return rc;
}//ucvebc3_b2ddSbcs1                                               //~0425R~
//*************************************************************************
//*ebc-->dd/utf8 (SBCS)                                            //~0425R~
//* ebc string to dd str(DBCS)
//  pdbcs optional for b2dd                                        //~0425I~
//* rc:1:F2LERR,8:buff ovf
//*************************************************************************
//int ucvebc3_b2ddSbcs(int Popt,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pbuffsz,int *Ppddlen)//~v69cR~
int ucvebc3_b2ddSbcs(int Popt,int Phandle,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pbuffsz,int *Ppddlen)//~v69cI~
{
    int rc=0,rc2,resleno,ddlen,/*optint,opts2u,*/repch,outlen,swb2f;//~0425R~//~0505R~//~v6b9R~
    UCHAR *pci,*pce,*pdd,*pcd;
//  ULONG pconverter;                                              //~v6b9R~
    UCHAR wkutf[MAX_MBCSLEN];                                      //~0505I~
    int swdbcsenv;                                                 //~v66mI~
//***************************
  if (Popt & UCVEBC3O_BIN)                                         //~v66yI~
    swdbcsenv=0;                                                   //~v66yI~
  else                                                             //~v66yI~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v66mI~//~v69cR~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~v69cI~
//  pconverter=Spcve2a[CONVERTER_DBCS];                            //~v6b9R~
//  optint=Sebcopte2a;                                             //~v6b9R~
//  opts2u=Sucsopt;                                                //~v6b9R~
//  repch=CHAR_ASCII_ERR;                                          //~v66CR~
//  repch=Ssubcharsbcs;   //by ucs                                 //~v66CR~//~v69cR~
    repch=UCVEBCH_subcharsbcs(Phandle);   //by ucs                 //~v69cI~
	swb2f=Popt & UCVEBC3O_B2F;                                     //~0505I~
	for (pci=Ppebc,pce=pci+Pinplen,pcd=Pdddbcs,pdd=Pdddata,resleno=Pbuffsz;pci<pce;pci++,pdd+=outlen,pcd+=outlen,resleno-=outlen)//~0425R~
    {
        if (resleno<1)                                  //~0425R~  //~0505R~
        {                                                          //~0505I~
        	rc=8;                                                  //~0505I~
        	break;                                                 //~0505R~
        }                                                          //~0505I~
      if (swdbcsenv)                                               //~v66mI~
        if (*pci==CHAR_SO||*pci==CHAR_SI)
        {
	        outlen=1;                                              //~0425I~
			if (Popt & UCVEBC3O_SOSI2SPACE)    //replace so/si to space//~0423I~
            {                                                      //~0423I~
        		*pdd=' ';                                          //~0423R~
                if (Pdddbcs)	//b2dd                             //~0425I~
	        		*pcd=0;       //keep original value and siplay by green//~0425R~
            }                                                      //~0423I~
            else                                                   //~0423I~
			if (Popt & UCVEBC3O_SOSIREP)    //replace so/si to space//~0429I~
            {                                                      //~0429I~
        		*pdd='.';                                          //~0429I~
                if (Pdddbcs)	//b2dd                             //~0429I~
                {                                                  //~v69mI~
                  if (Popt & UCVEBC3O_SETF2LERR)                   //~v69mI~
        			*pcd=UDBCSCHK_F2LERR;                          //~0429I~
                  else                                             //~v69mI~
        			*pcd=0;                                        //~v69mI~
                }                                                  //~v69mI~
            }                                                      //~0429I~
            else                                                   //~0429I~
			if (Popt & UCVEBC3O_SOSIREPQ)    //replace so/si to space//~0501I~
            {                                                      //~0501I~
        		*pdd='?';                                          //~0501I~
                if (Pdddbcs)	//b2dd                             //~0501I~
                {                                                  //~v69mI~
                  if (Popt & UCVEBC3O_SETF2LERR)                   //~v69mI~
        			*pcd=UDBCSCHK_F2LERR;                          //~0501I~
                  else                                             //~v69mI~
        			*pcd=0;                                        //~v69mI~
                }                                                  //~v69mI~
            }                                                      //~0501I~
            else                                                   //~0501I~
			if (Popt & UCVEBC3O_SOSIREPQP)   //replace so/si to space as printable//~v66gI~
            {                                                      //~v66gI~
        		*pdd='?';                                          //~v66gI~
                if (Pdddbcs)	//b2dd                             //~v66gI~
        			*pcd=0;                                        //~v66gI~
            }                                                      //~v66gI~
            else                                                   //~v66gI~
            {                                                      //~0423I~
        		*pdd=*pci;                                         //~0423R~
                if (Pdddbcs)	//b2dd                             //~0425I~
            	{                                                  //~v69mI~
                  if (Popt & UCVEBC3O_SETF2LERR)                   //~v69mI~
        			*pcd=UDBCSCHK_F2LERR;                          //~0425R~
                  else                                             //~v69mI~
        			*pcd=0;                                        //~v69mI~
                }                                                  //~v69mI~
            }                                                      //~0423I~
            continue;
        }
        if (swb2f)                                                 //~0505I~
        {                                                          //~0505I~
//  		rc2=ucvebc3_b2ddSbcs1(Popt,pci,repch,wkutf,0/*pcd*/,0/*out ucs*/,&outlen);//~0505I~//~v69cR~
    		rc2=ucvebc3_b2ddSbcs1(Popt,Phandle,pci,repch,wkutf,0/*pcd*/,0/*out ucs*/,&outlen);//~v69cI~
            if (outlen>resleno)                                    //~0505I~
            {                                                      //~0505I~
            	rc=8;                                              //~0505M~
            	break;                                             //~0505I~
            }                                                      //~0505I~
            memcpy(pdd,wkutf,(UINT)outlen);                        //~0505R~
        }                                                          //~0505I~
        else                                                       //~0505I~
//  		rc2=ucvebc3_b2ddSbcs1(Popt,pci,repch,pdd,pcd,0/*out ucs*/,&outlen);//~0425R~//~0505R~//~v69cR~
    		rc2=ucvebc3_b2ddSbcs1(Popt,Phandle,pci,repch,pdd,pcd,0/*out ucs*/,&outlen);//~v69cI~
    	if (rc2)
    	{
			if (!(Popt & UCVEBC3O_B2F))                            //~0425R~
            {                                                      //~v69yI~
              if (repch && *pdd==repch && *pcd==0                  //~v6hwI~
              &&  Popt & UCVEBC3O_ERRREP3)                         //~v6hwI~
              	;                                                  //~v6hwI~
              else                                                 //~v6hwI~
			  if ((Popt & UCVEBC3O_ERRREP2))                       //~v69yR~
        		*pdd='.';                                          //~v69yI~
              else                                                 //~v69yI~
        		*pdd=*pci;                                         //~0425R~
            }                                                      //~v69yI~
            if (Pdddbcs)	//b2dd                                 //~0425I~
            {                                                      //~v69mI~
              if (Popt & UCVEBC3O_SETF2LERR)//xeebc_cvmemcmp use this option//~v69mI~
        		*pcd=UDBCSCHK_F2LERR;                              //~0425R~
              else                                                 //~v69mI~
        		*pcd=0;                                            //~v69mI~
            }                                                      //~v69mI~
        	rc|=1;
    	}
    }
//  ddlen=(ULONG)pdd-(ULONG)Pdddata;                               //~v6hhR~
//  ddlen=(ULPTR)pdd-(ULPTR)Pdddata;                               //~v6hhI~//~v6BkR~
    ddlen=PTRDIFF(pdd,Pdddata);                                    //~v6BkI~
UTRACED("ucvebc3 b2dd sbcs output",Pdddata,ddlen);
UTRACED("ucvebc3 b2dd sbcs dbcd",Pdddbcs,ddlen);
	*Ppddlen=ddlen;
    return rc;
}//ucvebc3_b2ddSbcs
//*************************************************************************
//*ebc->ucs1(DBCS) int/ext
//* ebc string to ucs(DBCS)
//* rc:1 errrep
//*************************************************************************
//int ucvebc3_b2uDbcs1(int Popt,UCHAR *Ppebc,int Prepch,WUCS *Ppwucs)//~v69cR~
//int ucvebc3_b2uDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,WUCS *Ppwucs)//~v69cI~//~v6BjR~
int ucvebc3_b2uDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UWUCS *Ppwucs)//~v6BjI~
{
//  ULONG pconverter,ulucs;                                        //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    ULONG ulucs;                                                   //~v6x5I~
    int rc=0,optint,optext,opts2u,rc2;
//  WUCS wucs;                                                     //~v6BjR~
    UWUCS wucs;                                                    //~v6BjI~
//  USHORT usucs,ussjis;                                           //~v66CR~
    UWUCS usucs=0;                                                    //~v66CR~//~v6h6R~//~v6BjR~
    USHORT ussjis;                                                 //~v66CI~
    int repchdbcs;                                                 //~v66CI~
    PUCVEBCH pucveh;                                               //~v69cI~
//*********************
UTRACEP("ucvebc3 b2u DBCS dbcsbyte=%02x%02x\n",*Ppebc,*(Ppebc+1));
    if (Phandle)                                                   //~v69cI~
    {                                                              //~v69cI~
    	pucveh=UCVEBC_GETPUCVEH(Phandle);                          //~v69cI~
	    optext=EBC2ASC_STAT_SO;                                    //~v69cI~
	    optext|=EBC2ASC_EXT_SETSUBCHRC;                            //~v69cI~
		pconverter=pucveh->UCVEHpconverter[CONVERTER_SBCS];        //~v69cR~
        rc2=ucvext_icuebc2ucs1(optext,pconverter,Ppebc,2,&usucs);  //~v69cI~
    }                                                              //~v69cI~
    else                                                           //~v69cI~
    if (Sebcopte2a & EBC2ASC_EXT)
    {
	    optext=Sebcopte2a|EBC2ASC_STAT_SO;
	    optext|=EBC2ASC_EXT_SETSUBCHRC;                            //~v66DI~
		pconverter=Spcve2a[CONVERTER_DBCS];
        rc2=ucvext_icuebc2ucs1(optext,pconverter,Ppebc,2,&usucs);
    }
    else    //internal dbcsmap                                     //~v66DR~
    {
	    optint=Sebcopte2a|EBC2ASC_SOCONT;
#ifdef LNX                                                         //~v660I~
		optint&=~EBC2ASC_EUC;	//intermediate code is sjis        //~v660I~
#endif                                                             //~v660I~
	    opts2u=Sucsopt;
//      rc2=ucvebc2_ebc2asc1dbcsJ(optint,Ppebc,0/*repch*/,&ussjis);//~v66CR~
		repchdbcs=UTF_GETUCSBESTR(Spsubcharlocaldbcs);             //~v66CR~
        rc2=ucvebc2_ebc2asc1dbcsJ(optint,Ppebc,repchdbcs,&ussjis); //~v66CI~
        if (!rc2)   //valid ebc
        {
//          ulucs=uccvsjis2ucs(opts2u,(int)ussjis);                //~v6BkR~
            ulucs=(ULONG)uccvsjis2ucs((ULONG)opts2u,(int)ussjis);  //~v6BkI~
            if (ulucs==UCVERRUCS)
                rc2=4;
            else
//              usucs=(USHORT)ulucs;                               //~v692R~
                usucs=(UWUCS)ulucs;                                 //~v692R~//~v6BjR~
        }
    }
    if (rc2)
    {
    	rc=1;
        wucs=Prepch; 
    }
    else
//  	wucs=(WUCS)usucs;
    	wucs=usucs;
    *Ppwucs=wucs;
    return rc;
}//ucvebc3_b2uDbcs1
//*************************************************************************
//*ebc->dd1(DBCS)
//* ebc string to dd str(DBCS)
//* rc:1 errrep
//*************************************************************************
//int ucvebc3_b2ddDbcs1(int Popt,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen)//~0425R~//~v69cR~
//int ucvebc3_b2ddDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,WUCS *Ppwucs,int *Ppoutlen)//~v69cI~//~v6BjR~
int ucvebc3_b2ddDbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UCHAR *Pdddata,UCHAR *Pdddbcs,int *Ppoutlen)//~v6BjI~
{
    int rc=0,rc2,len=0,swb2f;                                        //~0425R~//~v6h6R~
//  WUCS wucs,repch;                                               //~v6BjR~
    UWUCS wucs,repch;                                              //~v6BjI~
//*********************
	swb2f=(Popt & UCVEBC3O_B2F);                                   //~0425R~
//  rc2=ucvebc3_b2uDbcs1(Popt,Ppebc,0/*repch*/,&wucs);             //~v69cR~
    rc2=ucvebc3_b2uDbcs1(Popt,Phandle,Ppebc,0/*repch*/,&wucs);     //~v69cI~
    if (!rc2)
    {
		if (swb2f)                                                 //~0425I~
        {                                                          //~0425I~
//  		len=uccvucs2utf((ULONG)wucs,Pdddata);                  //~0425I~//~v6BkR~
    		len=uccvucs2utf(wucs,Pdddata);                         //~v6BkI~
            if (!len)                                              //~0425I~
            	rc2=2;                                             //~0425I~
        }                                                          //~0425I~
        else                                                       //~0425I~
        {                                                          //~0426I~
        	UTF_U2DD1(wucs,Pdddata,Pdddbcs,&len);                  //~0425R~
        	if (len!=2)                                            //~0426R~
            	rc2=2; //width!=2                                  //~0426R~
        }                                                          //~0426I~
    }
    if (rc2)
    {
    	rc=1;
//  	repch=(WUCS)Prepch;                                        //~v6BjR~
    	repch=(UWUCS)Prepch;                                       //~v6BjI~
        if (!repch)
//      	repch=CHAR_UCS_DBCS_ERR;      //  "?"  zenkaku         //~0424R~//~v66CR~
//      	repch=Ssubchardbcs;	//ucs                              //~v66CI~//~v69cR~
        	repch=UCVEBCH_subchardbcs(Phandle);	//ucs              //~v69cI~
		if (swb2f)                                                 //~0425I~
        {                                                          //~0425I~
//    		len=uccvucs2utf((ULONG)repch,Pdddata);                 //~0425I~//~v6BkR~
      		len=uccvucs2utf(repch,Pdddata);                        //~v6BkI~
//            if (!len)                                              //~0425I~//~v66DR~
//            {                                                      //~0425I~//~v66DR~
//                repch=CHAR_UCS_DBCS_ERR2;     //space              //~0425I~//~v66DR~
//                len=uccvucs2utf((ULONG)repch,Pdddata);             //~0425I~//~v66DR~
//            }                                                      //~0425I~//~v66DR~
        }                                                          //~0425I~
        else                                                       //~0425I~
        {                                                          //~0425I~
		  if ((Popt & UCVEBC3O_ERRREP2))                           //~v69yI~
          {                                                        //~v69yI~
        	*Pdddata='.';                                          //~v69yI~
        	*(Pdddata+1)='.';                                      //~v69yI~
            if (Popt & UCVEBC3O_SETF2LERR)                         //~v69yI~
        		*Pdddbcs=UDBCSCHK_F2LERR;    //set outlen=1 later  //~v69yI~
            else                                                   //~v69yI~
        		*Pdddbcs=0;                                        //~v69yI~
        	*(Pdddbcs+1)=*Pdddbcs=0;                               //~v69yR~
            len=2;                                                 //~v69yI~
          }                                                        //~v69yI~
          else                                                     //~v69yI~
        	UTF_U2DD1(repch,Pdddata,Pdddbcs,&len);                 //~0425R~
//            if (len!=2)                                            //~0425R~//~v66DR~
//            {                                                      //~0425R~//~v66DR~
//                repch=CHAR_UCS_DBCS_ERR2;     //space              //~0425R~//~v66DR~
//                UTF_U2DD1(repch,Pdddata,Pdddbcs,&len);             //~0425R~//~v66DR~
//            }                                                      //~0425R~//~v66DR~
        }                                                          //~0425I~
    }
    if (Ppoutlen)                                                  //~0425I~
    	*Ppoutlen=len;                                             //~0425R~
UTRACEP("ucvebc3 b2dd DBCS dbcsbyte=%02x%02x,ucs=%x,outdd=%x-%x,outlen=%d\n",*Ppebc,*(Ppebc+1),wucs,//~0425R~
			*Pdddata,UWHICH(swb2f,*(Pdddata+1),*Pdddbcs),len);     //~0425R~
    return rc;
}//ucvebc3_b2ddDbcs1
//*************************************************************************
//*translate by icu converter
//* ebc string to dd/utf8 str(DBCS)                                //~0425R~
//* pdbcs is optional for b2dd                                     //~0425I~
//* rc:8 buff ovf,1:errrep
//*************************************************************************
//int ucvebc3_b2ddDbcsstr(int Popt,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen)//~v69cR~
int ucvebc3_b2ddDbcsstr(int Popt,int Phandle,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen)//~v69cI~
{
//  int rc=0,optint,optext,rc2,resleno,opts2u,ddlen,repch,outlen,swb2f;//~0505R~//~v69cR~
    int rc=0,/*optint,optext,*/rc2,resleno,/*opts2u,*/ddlen,repch,outlen,swb2f;//~v69cI~
    UCHAR *pci,*pce,*pcd,*pdd;
//  ULONG pconverter;                                              //~v69cR~
    UCHAR wkutf[MAX_MBCSLEN];                                      //~0505I~
//***************************
//  pconverter=Spcve2a[CONVERTER_DBCS];                            //~v69cR~
//  optext=Sebcopte2a|EBC2ASC_STAT_SO;                             //~v69cR~
//  optint=Sebcopte2a|EBC2ASC_SOCONT;                              //~v69cR~
//  opts2u=Sucsopt;                                                //~v69cR~
	swb2f=(Popt & UCVEBC3O_B2F);                                   //~0505I~
//  repch=0;	//default zenkaku "?"                              //~0424R~//~v66CR~
//  repch=Ssubchardbcs;	//by ucs                                   //~v66CI~//~v69cR~
    repch=UCVEBCH_subchardbcs(Phandle);	//by ucs                   //~v69cI~
	for (pci=Ppebc,pce=pci+Pinplen,pcd=Pdddbcs,pdd=Pdddata,resleno=Poutbuffsz;pci<pce;pci+=2,pdd+=outlen,resleno-=outlen)//~0425R~
    {
        if (resleno<2)                                  //~0425R~  //~0505R~
        {                                                          //~0505I~
        	rc=8;                                                  //~0505I~
        	break;                                                 //~0505R~
        }                                                          //~0505I~
UTRACEP("ucvebc3 b2dd DBCSstr dbcsbyte=%02x%02x\n",*pci,*(pci+1));
        if (swb2f)                                                 //~0505I~
        {                                                          //~0505I~
//  		rc2=ucvebc3_b2ddDbcs1(Popt,pci,repch,wkutf,0/*pcd*/,0/*ucs*/,&outlen);//~0505R~//~v69cR~
//  		rc2=ucvebc3_b2ddDbcs1(Popt,Phandle,pci,repch,wkutf,0/*pcd*/,0/*ucs*/,&outlen);//~v69cI~//~v6BjR~
    		rc2=ucvebc3_b2ddDbcs1(Popt,Phandle,pci,repch,wkutf,0/*pcd*/,&outlen);//~v6BjI~
            if (outlen>resleno)                                    //~0505I~
            {                                                      //~0505I~
            	rc=8;                                              //~0505I~
                break;                                             //~0505I~
            }                                                      //~0505I~
            memcpy(pdd,wkutf,(UINT)outlen);                        //~0505I~
        }                                                          //~0505I~
        else                                                       //~0505I~
//  		rc2=ucvebc3_b2ddDbcs1(Popt,pci,repch,pdd,pcd,0/*ucs*/,&outlen);//~0425R~//~0505R~//~v69cR~
//  		rc2=ucvebc3_b2ddDbcs1(Popt,Phandle,pci,repch,pdd,pcd,0/*ucs*/,&outlen);//~v69cI~//~v6BjR~
    		rc2=ucvebc3_b2ddDbcs1(Popt,Phandle,pci,repch,pdd,pcd,&outlen);//~v6BjI~
        if (rc2)
        	rc|=1;
        if (Pdddbcs)                                               //~0425I~
        	pcd+=outlen;                                           //~0425I~
    }
//  ddlen=(ULONG)pdd-(ULONG)Pdddata;                               //~v6hhR~
//  ddlen=(ULPTR)pdd-(ULPTR)Pdddata;                               //~v6hhI~//~v6BkR~
    ddlen=PTRDIFF(pdd,Pdddata);                                    //~v6BkI~
    *Ppddlen=ddlen;
UTRACEP("ebc2ucsdbcs rc=%d\n",rc);
UTRACED("output dd",Pdddata,ddlen);
UTRACED("output dbcs",Pdddbcs,ddlen);
    return rc;
}//ucvebc3_b2ddDbcsstr
//*************************************************************************
//* ebc string to dd/utf8 string(DBCS lang)                        //~0425R~
//*  DBCS by chekking SO/SI                                        //~0423I~
//* pdbcs is optional for b2dd                                     //~0425I~
//* rc:1:F2LERR,8:buff overflow
//*************************************************************************
//int ucvebc3_b2ddDbcs(int Popt,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pbuffsz,int *Ppoutlen)//~v69cR~
int ucvebc3_b2ddDbcs(int Popt,int Phandle,UCHAR *Ppebc,int Pinplen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pbuffsz,int *Ppoutlen)//~v69cI~
{
    int rc=0,len,resleno,ddlen,swso=0,rc2;
//  UCHAR *pci,*pce,*pcd,*pcisbcs,*pcidbcs,*pdd,*pcdi=NULL;             //~0505R~//~v6h6R~
    UCHAR *pci,*pce,*pcd,*pcisbcs,*pcidbcs=NULL,*pdd,*pcdi=NULL;   //~v6h6I~
    int swcase,swchkdbcstb,swdbcs=0;                               //~0505R~
    int swdropsosi=0;                                              //~v688R~
//***************************
UTRACED("ucvebc3_b2ddDbcs input ebc",Ppebc,Pinplen);
    pcisbcs=Ppebc;
    swchkdbcstb=Popt & UCVEBC3O_CHKDBCSTB; //option for B2F        //~0505R~
    if (swchkdbcstb)                                               //~0505I~
    	pcdi=Pdddbcs;                                              //~0505R~
	if (Popt & UCVEBC3O_SOSICMDO)                                  //~v688I~
    {                                                              //~v688I~
		if (Popt & UCVEBC3O_DROPSOSI)                              //~v688R~
    		swdropsosi=1;                                          //~v688R~
    }                                                              //~v688I~
    else                                                           //~v688I~
    {                                                              //~v688I~
    	if (Sebcopte2a & EBC2ASC_SOSID)                            //~v688R~
	    	swdropsosi=1;                                          //~v688R~
        else                                                       //~v68aI~
        if (Popt & UCVEBC3O_CFGSOSI)	//from gxe CAP             //~v68aI~
	    	Popt|=UCVEBC3O_SOSI2SPACE;                             //~v68aI~
    }                                                              //~v688I~
	for (pci=Ppebc,pce=pci+Pinplen,pdd=Pdddata,pcd=Pdddbcs,resleno=Pbuffsz;
			pci<pce;pci++)                                         //~0503R~
    {
UTRACEP("ebc2ucs2dbcs byte=%02x\n",*pci);
        if (*pci==CHAR_SO)                                         //~0503R~
            swcase=CHAR_SO;                                        //~0503R~
        else                                                       //~0503R~
        if (*pci==CHAR_SI)                                         //~0503R~
            swcase=CHAR_SI;                                        //~0503R~
        else                                                       //~0503R~
        {                                                          //~0505I~
        	if (swchkdbcstb)                                       //~0505I~
            	swcase=*pcdi;                                      //~0505R~
            else                                                   //~0505I~
	        	swcase=0;                                                  //~0503R~//~0505R~
        }                                                          //~0505I~
        rc2=0;
        switch(swcase)
        {
        case CHAR_SO:
        	if (swso && swcase==CHAR_SO)
//          	swso=0;                                            //~v66cR~
//          else	//valid SO/SI combination or EOL reached       //~v66cR~
                pcisbcs=pcidbcs;    //dup SO,treate as sbc from the next of previous SO//~v66cI~
//          {                                                      //~v66cR~
                pcidbcs=pci+1;
//              len=(ULONG)pcidbcs-(ULONG)pcisbcs;  //include SO   //~v6hhR~
//              len=(ULPTR)pcidbcs-(ULPTR)pcisbcs;  //include SO   //~v6hhI~//~v6BkR~
                len=PTRDIFF(pcidbcs,pcisbcs);  //include SO        //~v6BkI~
                if (Pdddbcs)                                       //~0425I~
	                pcd=UTF_PC2PCD(Pdddbcs,pdd,Pdddata);           //~0425R~
        		else                                               //~0505I~
            		pcd=0;                                         //~0505I~
//  			rc2=ucvebc3_b2ddSbcs(Popt,pcisbcs,len,pdd,pcd,resleno,&ddlen);//~v69cR~
    			rc2=ucvebc3_b2ddSbcs(Popt,Phandle,pcisbcs,len,pdd,pcd,resleno,&ddlen);//~v69cI~
        		swso=1;
        		if (rc2==1)
            		rc|=1; //errrep
                pdd+=ddlen;
                resleno-=ddlen;
                pcisbcs=pcidbcs; //for the case dbcs err           //~0503R~
//          }                                                      //~v66cR~
            break;
        case CHAR_SI:
        	if (swso)
            {
//              len=(ULONG)pci-(ULONG)pcidbcs;                     //~v6hhR~
//              len=(ULPTR)pci-(ULPTR)pcidbcs;                     //~v6hhI~//~v6BkR~
                len=PTRDIFF(pci,pcidbcs);                          //~v6BkI~
                if (len && !(len & 1))	//odd number
                {
	                if (Pdddbcs)                                   //~0425I~
	                    pcd=UTF_PC2PCD(Pdddbcs,pdd,Pdddata);       //~0425R~
	        		else                                           //~0505I~
    	        		pcd=0;                                     //~0505I~
//  				rc2=ucvebc3_b2ddDbcsstr(Popt,pcidbcs,len,pdd,pcd,resleno,&ddlen);//~v69cR~
    				rc2=ucvebc3_b2ddDbcsstr(Popt,Phandle,pcidbcs,len,pdd,pcd,resleno,&ddlen);//~v69cI~
                    if (rc2==1)                                    //~0424R~
                    {                                              //~0424I~
    	        		rc|=1; //errrep                            //~0424I~
	                    if (Popt & UCVEBC3O_ERRREP)                //~0426R~
                    		rc2=0;	//not sbcs mode                //~0424I~
                    }                                              //~0424I~
                    if (!rc2)                                      //~0424R~
                    {
//                    if (Popt & UCVEBC3O_DROPSOSI)                //~v66aI~//~v688R~
                      if (swdropsosi)                              //~v688I~
                      {                                            //~v66aI~
                        memcpy(pdd-1,pdd,(UINT)ddlen);             //~v66aR~
                        if (Pdddbcs) //0 if B2F                    //~v66aR~
	                        memcpy(pcd-1,pcd,(UINT)ddlen);         //~v66aR~
                        pcisbcs=pci+1;                             //~v66aI~
                        pdd+=ddlen-1;                              //~v66aI~
                        resleno-=(ddlen-1);                        //~v66aI~
                      }                                            //~v66aI~
                      else                                         //~v66aI~
                      {                                            //~v66aI~
                        pcisbcs=pci;                               //~0424R~
                        pdd+=ddlen;                                //~0424R~
                        resleno-=ddlen;                            //~0424R~
                      }                                            //~v66aI~
                    }
//***               else re-evaluate as SBCS (using pcisbcs previously set)//~v69yI~
                }
            	swso=0;
            }
            break;
        case UDBCSCHK_DBCS1ST:                                     //~0505M~
        	swdbcs=1;                                              //~0505I~
        	if (!swso)	//not start by SO                          //~0505M~
            {                                                      //~0505M~
    	        pcidbcs=pci;                                       //~0505M~
        		swso=2;     //start not by so but by dbcstbl       //~0505M~
                pcisbcs=pcidbcs; //for the case dbcs err           //~0505M~
//              len=(ULONG)pcidbcs-(ULONG)pcisbcs;  //include SO   //~0505M~//~v6hhR~
//              len=(ULPTR)pcidbcs-(ULPTR)pcisbcs;  //include SO   //~v6hhI~//~v6BkR~
                len=PTRDIFF(pcidbcs,pcisbcs);  //include SO        //~v6BkI~
                if (len)                                           //~0505M~
                {                                                  //~0505M~
//  				rc2=ucvebc3_b2ddSbcs(Popt,pcisbcs,len,pdd,0/*pcd,0 for B2F*/,resleno,&ddlen);//~0505M~//~v69cR~
    				rc2=ucvebc3_b2ddSbcs(Popt,Phandle,pcisbcs,len,pdd,0/*pcd,0 for B2F*/,resleno,&ddlen);//~v69cI~
        			if (rc2==1)                                    //~0505M~
            			rc|=1; //errrep                            //~0505M~
                	pdd+=ddlen;                                    //~0505M~
                	resleno-=ddlen;                                //~0505M~
                }                                                  //~0505M~
            }                                                      //~0505M~
            break;                                                 //~0505M~
        case UDBCSCHK_DBCS2ND:                                     //~0505I~
            break;                                                 //~0505I~
        default:                                                   //~0505I~
    	  if (swchkdbcstb)                                         //~v66bI~
          {                                                        //~v69iI~
//** should call translation if swdbcs=1; but currentry inpu string is end before SI//~v69iI~
        	swdbcs=0;                                              //~0505I~
          }                                                        //~v69iI~
        }//sw
        if (rc2>=8)	//buff ovf
        {
        	rc=8;
        	break;
        }
      if (swchkdbcstb)                                             //~v6h6I~
        pcdi++;                                                    //~0505I~
    }
    if (swso==2	//EOL by dbcstb                                    //~0505R~
    ||  (swso && swdbcs))                                            //~0505I~//~0518R~
    {                                                              //~0505I~
//    	len=(ULONG)pce-(ULONG)pcidbcs;  //include SO               //~0505I~//~v6hhR~
//  	len=(ULPTR)pce-(ULPTR)pcidbcs;  //include SO               //~v6hhI~//~v6BkR~
    	len=PTRDIFF(pce,pcidbcs);  //include SO                    //~v6BkI~
//  	rc2=ucvebc3_b2ddDbcsstr(Popt,pcidbcs,len,pdd,0/*pcd*/,resleno,&ddlen);//~0505I~//~v69cR~
    	rc2=ucvebc3_b2ddDbcsstr(Popt,Phandle,pcidbcs,len,pdd,0/*pcd*/,resleno,&ddlen);//~v69cI~
    }                                                              //~0505I~
    else                                                           //~0505I~
    {                                                              //~0505I~
//    	len=(ULONG)pce-(ULONG)pcisbcs;  //include SO                   //~0503I~//~0505R~//~v6hhR~
//  	len=(ULPTR)pce-(ULPTR)pcisbcs;  //include SO               //~v6hhI~//~v6BkR~
    	len=PTRDIFF(pce,pcisbcs);  //include SO                    //~v6BkI~
    	if (Pdddbcs)                                                   //~0503I~//~0505R~
			pcd=UTF_PC2PCD(Pdddbcs,pdd,Pdddata);                       //~0503I~//~0505R~
        else                                                       //~0505I~
            pcd=0;                                                 //~0505I~
//  	rc2=ucvebc3_b2ddSbcs(Popt,pcisbcs,len,pdd,pcd,resleno,&ddlen); //~0503I~//~0505R~//~v69cR~
    	rc2=ucvebc3_b2ddSbcs(Popt,Phandle,pcisbcs,len,pdd,pcd,resleno,&ddlen);//~v69cI~
    }                                                              //~0505I~
    if (rc2==1)                                                    //~0503I~//~0505R~
    	rc|=1; //errrep                                            //~0503I~//~0505R~
    pdd+=ddlen;                                                    //~0503I~
//  ddlen=(int)((ULONG)pdd-(ULONG)Pdddata);                        //~v6hhR~
    ddlen=(int)((ULPTR)pdd-(ULPTR)Pdddata);                        //~v6hhI~
    if (Ppoutlen)
        *Ppoutlen=ddlen;
UTRACEP("ucvebc3 b2ddDbcs rc=%d\n",rc);
UTRACED("output data",Pdddata,ddlen);
UTRACED("output dbcs",Pdddbcs,ddlen);
    return rc;
}//ucvebc3_b2ddDbcs
//****************************************************************
//*ebc->dd fmt(data contains no TAB/TABPAD) chekking SO/SI         //~0423R~
//* rc:1:F2LERR,8:buff overflow
//****************************************************************
//int ucvebc3_b2dd(int Popt,UCHAR *Pebc,int Plen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen)//~v69cR~
int ucvebc3_b2dd(int Popt,int Phandle,UCHAR *Pebc,int Plen,UCHAR *Pdddata,UCHAR *Pdddbcs,int Poutbuffsz,int *Ppddlen)//~v69cI~
{
	int rc;
//********************
    UTRACEP("ebc3_b2dd opt=%x,handle=%d\n",Popt,Phandle);                      //~v69cI~//~v69mR~
    if (!(Popt & UCVEBC3O_BIN)
//  &&  UDBCSCHK_ISDBCSCV()                                        //~v69cR~
    &&  UCVEBCH_HANDLE_ISDBCSCV(Phandle)                           //~v69cI~
    )
//  	rc=ucvebc3_b2ddDbcs(Popt,Pebc,Plen,Pdddata,Pdddbcs,Poutbuffsz,Ppddlen);//~v69cR~
    	rc=ucvebc3_b2ddDbcs(Popt,Phandle,Pebc,Plen,Pdddata,Pdddbcs,Poutbuffsz,Ppddlen);//~v69cI~
    else
//  	rc=ucvebc3_b2ddSbcs(Popt,Pebc,Plen,Pdddata,Pdddbcs,Poutbuffsz,Ppddlen);//~v69cR~
    	rc=ucvebc3_b2ddSbcs(Popt,Phandle,Pebc,Plen,Pdddata,Pdddbcs,Poutbuffsz,Ppddlen);//~v69cI~
    UTRACED("ebc3_b2dd inp",Pebc,Plen);
    UTRACED("ebc3_b2dd pdd",Pdddata,*Ppddlen);
    UTRACED("ebc3_b2dd pcd",Pdddbcs,*Ppddlen);
    return rc;
}//ucvebc3_b2dd
//*************************************************************************//~v66HI~
//* ucs->ebc 1 char using map                                      //~v66HI~
//* ret :ebc, 0: err for <0x100, -1:more search requred            //~v66HI~
//*************************************************************************//~v66HI~
//int ucvebc3_u2b1map(int Popt,WUCS Pucs)                            //~v66HI~//~v69cR~
//int ucvebc3_u2b1map(int Popt,int Phandle,WUCS Pucs)                //~v69cI~//~v6BjR~
int ucvebc3_u2b1map(int Popt,int Phandle,UWUCS Pucs)               //~v6BjI~
{                                                                  //~v66HI~
	int ebc=-1,ii;                                                 //~v66HR~
    PUCVEBCH pucveh;                                               //~v69cI~
//*************                                                    //~v66HI~
//  if (UTF_ISUCS4(Pucs))                                          //~v6BjI~//+v6BuR~
//  	return -1;	//no map for ucs4                              //~v6BjI~//+v6BuR~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
    if (Pucs<0x100)                                                //~v66HI~
//    	ebc=Su2bmap[(int)Pucs];                                    //~v66HI~//~v69cR~
      	ebc=pucveh->UCVEHu2bmap[(int)Pucs];                        //~v69cI~
    else                                                           //~v66HI~
    if ((Pucs>>8)==0xff)	//FFxx                                 //~v66HI~
    {                                                              //~v66HI~
//    	ebc=Su2bffmap[(int)(Pucs&0xff)];                           //~v66HI~//~v69cR~
      	ebc=pucveh->UCVEHu2bffmap[(int)(Pucs&0xff)];               //~v69cI~
        if (!ebc)                                                  //~v66HI~
        	ebc=-1;	//retry search                                 //~v66HI~
    }                                                              //~v66HI~
    else                                                           //~v66HI~
    {                                                              //~v66HI~
//  	for (ii=0;ii<Su2bnonasciictr;ii++)	//euro sign etc        //~v66HI~//~v69cR~
    	for (ii=0;ii<pucveh->UCVEHu2bnonasciictr;ii++)	//euro sign etc//~v69cI~
        {                                                          //~v66HI~
//      	if (Su2bnonasciimapucs[ii]==Pucs)                      //~v66HR~//~v69cR~
        	if (pucveh->UCVEHu2bnonasciimapucs[ii]==Pucs)          //~v69cI~
            {                                                      //~v66HI~
//          	ebc=Su2bnonasciimapebc[ii];                        //~v66HR~//~v69cR~
            	ebc=pucveh->UCVEHu2bnonasciimapebc[ii];            //~v69cI~
            	break;                                             //~v66HI~
            }                                                      //~v66HI~
        }                                                          //~v66HI~
    }                                                              //~v66HI~
    UTRACEP("ucvebc3_u2b1bymap ucs=%04x,ebc=%02x\n",Pucs,ebc);       //~v66HI~//~v6biR~
    return ebc;                                                    //~v66HI~
}//ucvebc3_u2b1map                                                 //~v66HI~
//*************************************************************************
//* ucs->ebc 1 char
//* rc:4:F2LERR                                                    //~0423R~
//*************************************************************************
//int ucvebc3_u2b1(int Popt,WUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen)//~v69cR~
//int ucvebc3_u2b1(int Popt,int Phandle,WUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen)//~v69cI~//~v6BjR~
int ucvebc3_u2b1(int Popt,int Phandle,UWUCS Pucs,UCHAR *Poutbuff,int *Ppoutlen)//~v6BjI~
{
    int rc=0,rc2,optint,optext,optu2s,/*swdbcsu,swdbcse,*/ebclen=0,sjis,ebc;//~0430R~
//  USHORT usucs;                                                  //~v692R~
    UWUCS  usucs;                                                  //~v692R~//~v6BiR~
//  ULONG ulucs,pconverter;                                        //~v6x5R~
    ULONG ulucs;                                                   //~v6x5I~
    ULPTR pconverter;                                              //~v6x5I~
    UCHAR chsjis;
//  int wcwidth;                                                   //~v66mI~//~v66qR~
	PUCVEBCH pucveh;                                               //~v69cI~
//***************************
UTRACEP("ucvebc3 u2b1 opt=%x,handle=%d,inp ucs=%x\n",Popt,Phandle,Pucs);//~v69cR~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
    if ( Pucs<' '
    &&  !(Popt & UCVEBC3O_CVCTL)
    )
    {
        rc2=4;
    }
    else	//not ctl char
    {
//      swdbcsu=(Popt & UCVEBC3O_DBCS)!=0;                         //~0423R~//~0430R~
//    if (UTF8ISASCII(Pucs) //for performance                      //~v66qR~
//    if (UTF8ISASCII(Pucs) //for performance                      //~v66qI~
//    if (Pucs<0x100 //for performance                             //~v66qI~//~v66HR~
//    if (Pucs<0x100 //for performance                             //~v66HI~
//    &&  Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v66HR~
//    if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)                      //~v66HI~//~v69cR~
      if (UCVEBCH_ISSBCSMAPINIT(pucveh))                           //~v69cI~
//  	ebc=ucvebc3_u2b1map(0,Pucs);    //0 or ebc                 //~v66HI~//~v69cR~
    	ebc=ucvebc3_u2b1map(0,Phandle,Pucs);    //0 or ebc         //~v69cI~
      else                                                         //~v66HI~
      	ebc=-1;                                                    //~v66HI~
      if (ebc>=0)   //value of <0x100 or ffxx or euro sign etc     //~v66HI~
      {
//    	*Poutbuff=ebc=EBC_A2B(Pucs);                               //~0423R~//~v66qR~
//    	*Poutbuff=ebc=Su2bmap[(int)Pucs];                          //~v66qI~//~v66HR~
//    	*Poutbuff=ebc;                                             //~v66HI~//~v6BiR~
      	*Poutbuff=(UCHAR)ebc;                                      //~v6BiI~
        ebclen=1;
        rc2=0;
//      if (!ebc && Pucs)                                          //+v6BuR~
        if (!ebc && Pucs<0x100) //if >=0x100,explicitly map to 0x00 by UCVEHu2bffmap or UCVEHu2bnonasciimapucs//+v6BuI~
            rc2=4;
      }
      else
      {
       if (Phandle>0)                                              //~v69cI~
        pconverter=pucveh->UCVEHpconverter[CONVERTER_SBCS];        //~v69cR~
       else                                                        //~v69cI~
       if (Popt & UCVEBC3O_SBCS)                                   //~v66qI~
       {                                                           //~v66qI~
        pconverter=Spcva2e[CONVERTER_SBCS];                        //~v66qI~
        if (!pconverter)                                           //~v66qI~
            pconverter=Spcva2e[CONVERTER_DBCS];                    //~v66qI~
       }                                                           //~v66qI~
       else                                                        //~v66qI~
       {                                                           //~v66qI~
        pconverter=Spcva2e[CONVERTER_DBCS];
        if (!pconverter)
            pconverter=Spcva2e[CONVERTER_SBCS];
       }                                                           //~v66qI~
        optext=Sebcopta2e;
        optint=Sebcopta2e;
#ifdef LNX                                                         //~v660I~
		optint&=~EBC2ASC_EUC;	//intermediate code is sjis        //~v660I~
#endif                                                             //~v660I~
        optu2s=0;   //MS932,CP943C is jis->utf8 parameter
//      if (Sebcopta2e & EBC2ASC_EXT)                              //~v69cR~
        if (Phandle                                                //~v69cI~
        ||  (Sebcopta2e & EBC2ASC_EXT)                             //~v69cI~
        )                                                          //~v69cI~
        {
//      	if (swdbcsu)                                           //~0430I~
//         	optext|=EBC2ASC_STAT_SO;                               //~0430I~
           	optext=0;                                              //~0430I~
		    optext|=EBC2ASC_EXT_SETSUBCHRC;                        //~v66DI~
//          usucs=(USHORT)Pucs;                                    //~v692R~
            usucs=Pucs;                                            //~v692R~//~v6BiR~
            rc2=ucvext_icuucs2ebc1(optext,pconverter,usucs,Poutbuff,&ebclen);
            if (rc2==UCVEXTRC_SUBCH)                               //~v66DI~
            {                                                      //~v66CI~
                rc=rc2; //return -3                                //~v66DI~//~v66CR~
                rc2=0;                                             //~v66CI~
            }                                                      //~v66CI~
            else                                                   //~v66DI~
            if (rc2<=1)      //1:dbcs                              //~v66qR~
            {
                rc2=0;                                             //~v66mI~
#ifdef AAA                                                         //~v66qI~
//              if (utfwcwidth(0,Pucs,0)!=ebclen)                  //~v66mI~
//                  rc2=4;                                         //~v66mI~
                if (Popt & UCVEBC3O_UCSNP)   //konow as unprintable sbvcs//~v66mI~
                {                                                  //~v66mI~
                	if (ebclen!=1)                                 //~v66mI~
	                    rc2=4;                                     //~v66mI~
                }                                                  //~v66mI~
                else                                               //~v66mI~
                {                                                  //~v66mI~
                  	wcwidth=utfwcwidth(0,Pucs,0);                  //~v66mI~
                    if (wcwidth>=0 && wcwidth!=ebclen)	//dbcs err //~v66mI~
                    	rc2=4;                                     //~v66mR~
                }                                                  //~v66mI~
#endif                                                             //~v66qI~
            }
        }
        else    //interbnal dbcsmap
        {
            rc2=4;
            ulucs=(ULONG)Pucs;
//          sjis=uccvucs2sjis(optu2s,ulucs);                       //~v6BkR~
            sjis=uccvucs2sjis((ULONG)optu2s,(UWUCS)ulucs);         //~v6BkI~
            if (sjis>0 && sjis!=UCVERRUCS)
            {
              if (sjis>0xff)    //dbcs                             //~0430R~
              {
                ebc=ucvebc2_s2e(optint,(USHORT)sjis);
//              swdbcse=(ebc>=0x100);                              //~0430R~
//              if (swdbcsu==swdbcse)                              //~0430R~
                if (ebc>0xff)                                      //~0430I~
                {
                    rc2=0;
                    ebclen=2;
                    UTF_SETUCSBESTR(ebc,Poutbuff);
                }
              }
              else
              {
//          	chsjis=sjis;                                       //~v6BiR~
            	chsjis=(UCHAR)sjis;                                //~v6BiI~
                optint=EBC2ASC_CTL; //for mapinit                  //~0430I~//~v66qR~
//  			ucvasc2ebc(optint,&chsjis,0/*dbcs*/,Poutbuff,1,0/*repch*/,&ebclen);//~v69cR~
    			ucvasc2ebc_handle(optint,Phandle,&chsjis,0/*dbcs*/,Poutbuff,1,0/*repch*/,&ebclen);//~v69cI~
                rc2=ebclen!=1;
              }
            }
        }
//        if (ebclen==1)  //sbcs                                     //~v66qI~//~v66DR~
//        {                                                          //~v66qI~//~v66DR~
//            ebc=*Poutbuff;                                         //~v66qI~//~v66DR~
//            if ((ebc==CHAR_EBC_ERR && Pucs!=CHAR_ASCII_ERR)        //~v66qR~//~v66DR~
//            )                                                      //~v66qI~//~v66DR~
//                rc2=1;                                             //~v66qI~//~v66DR~
//            else                                                   //~v66qI~//~v66DR~
////          if (ebc=='.' && Pucs!='.')    //windows cp return "."  //~v66qI~//~v66sR~//~v66DR~
//            if (ebc==CHAR_EBC_ACK /*0x2e=*/ && Pucs!=CHAR_UCS_ACK)    //windows cp return "."//~v66sR~//~v66DR~
//                rc2=1;                                             //~v66qI~//~v66DR~
//            else                                                   //~v66qI~//~v66DR~
////          if (ebc==CHAR_ASCII_ERR && Pucs!=CHAR_ASCII_ERR)    //windows cp return "?"//~v66qI~//~v66sR~//~v66DR~
//            if (ebc==CHAR_EBC_SUB /*0x3f*/ && Pucs!=CHAR_UCS_SUB /*0x1a*/)    //windows cp return "?"//~v66sR~//~v66DR~
//                rc2=1;                                             //~v66qI~//~v66DR~
//        }                                                          //~v66qI~//~v66DR~
      }//by initializec sbcs map
    }
    if (rc2)
    	rc=4;
    if (Ppoutlen)
    	*Ppoutlen=ebclen;
UTRACED("ucvebc3 u2b1 output data",Poutbuff,ebclen);
UTRACEP("ucvebc3 u2b1 rc=%d\n",rc);
    return rc;
}//ucvebc3_u2b1
//*************************************************************************
//* ucs->ebc 1 char
//* rc:ebc or -1
//*************************************************************************
//int ucvebc3_m2b1Sbcs1(int Popt,int Pmbch)                          //~v66qR~//~v69cR~
int ucvebc3_m2b1Sbcs1(int Popt,int Phandle,int Pmbch)              //~v69cI~
{
    int rc2,ebc,repch,ebclen,opt;
//  UCHAR chmb,chebc;                                              //~v6m1R~
    UCHAR chmb,wkebc[8];                                           //~v6m1I~
    PUCVEBCH pucveh;                                               //~v69cI~
//***************************
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
//  chmb=Pmbch&0xff;                                               //~v6BkR~
    chmb=(UCHAR)(Pmbch&0xff);                                      //~v6BkI~
//  if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v69cR~
    if (UCVEBCH_ISSBCSMAPINIT(pucveh))//sbcsmap was initialized    //~v69cI~
    {
//    	ebc=EBC_A2B(chmb);                                         //~v69cR~
      	ebc=UCVEBCH_A2B(Phandle,chmb);                             //~v69cR~
        rc2=0;
    }
    else
    {
    	opt=Sebcopta2e|Popt;
    	opt|=EBC2ASC_EXT_SETSUBCHRC;                               //~v66DI~
    	opt&=~EBC2ASC_DBCS;	//dbcsenv
//      repch=CHAR_EBC_ERR;                                        //~v66CR~
//      repch=Ssubcharebcsbcs;                                     //~v66CR~//~v69cR~
        repch=UCVEBCH_subcharebcsbcs(Phandle);                     //~v69cI~
//  	rc2=ucvasc2ebc(opt,&chmb,0/*pdbcs*/,&chebc,1/*ren*/,repch,&ebclen);//~v69cR~
//  	rc2=ucvasc2ebc_handle(opt,Phandle,&chmb,0/*pdbcs*/,&chebc,1/*ren*/,repch,&ebclen);//~v69cI~//~v6m1R~
//      ebc=chebc;                                                 //~v6m1R~
    	rc2=ucvasc2ebc_handle(opt,Phandle,&chmb,0/*pdbcs*/,wkebc,1/*ren*/,repch,&ebclen);//~v6m1I~
        ebc=wkebc[0];                                              //~v6m1I~
//        if (!rc2)                                                //~v66DR~
//        {                                                          //~v66qI~//~v66DR~
//            if (ebc==CHAR_EBC_ERR && chmb!=CHAR_ASCII_ERR)         //~v66sR~//~v66DR~
//                rc2=4;                                           //~v66DR~
//            else                                                   //~v66qI~//~v66DR~
////          if (ebc=='.'   && chmb!='.')    //windows cp return "."//~v66qI~//~v66sR~//~v66DR~
//            if (ebc==CHAR_EBC_ACK /*0x2e=*/ && chmb!=CHAR_UCS_ACK)    //windows cp return "."//~v66sI~//~v66DR~
//                rc2=4;                                             //~v66qI~//~v66DR~
//            else                                                   //~v66qI~//~v66DR~
////          if (ebc==CHAR_ASCII_ERR && chmb!=CHAR_ASCII_ERR)    //windows cp return "?"//~v66qI~//~v66sR~//~v66DR~
//            if (ebc==CHAR_EBC_SUB /*0x3f*/ && chmb!=CHAR_UCS_SUB /*0x1a*/)    //windows cp return "?"//~v66sI~//~v66DR~
//                rc2=4;                                             //~v66qI~//~v66DR~
//        }                                                          //~v66qI~//~v66DR~
    }
    if (!rc2)
    	if (!ebc && chmb)    //not null-->null by sbcs map
        	rc2=4;
    if (rc2)
        ebc=-1;
UTRACEP("ucvebc3 m2b1SBCS1 opt=%x,mb=%x,ebc=%x\n",Popt,chmb,ebc);  //~v66qR~
    return ebc;
}//ucvebc3_m2b1Sbcs1                                               //~v66qR~
//*************************************************************************
//* mb->ebc 1 char
//* rc:1:DBCS,4:F2LERR
//*************************************************************************
//int ucvebc3_m2b1(int Popt,UCHAR *Pdata,int Pinplen,UCHAR *Poutbuff,int *Ppoutlen)//~v69cR~
int ucvebc3_m2b1(int Popt,int Phandle,UCHAR *Pdata,int Pinplen,UCHAR *Poutbuff,int *Ppoutlen)//~v69cI~
{
    int rc=0,rc2,repch,repchdbcs,mblen=0,opt,len,ebc,outlen,repchparm;//~0423R~
//***************************
UTRACED("ucvebc3 m2b1 inp data",Pdata,Pinplen);
    opt=Sebcopta2e;
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66DI~
  if (Popt & UCVEBC3O_MBCHSZ)    //m2b parm length is mbchsz       //~v66XR~
    len=Pinplen;                                                   //~v66XI~
  else                                                             //~v66XI~
  {                                                                //~v66XI~
		len=min(2,Pinplen);                                        //~v66XI~
    if (Popt & UCVEBC3O_SBCS)
        len=min(1,len);
  }                                                                //~v66XI~
    if (len>1)
//  	opt|=EBC2ASC_SOCONT;                                       //~v688R~
    	opt|=EBC2ASC_SOCONT|EBC2ASC_LNCONT; //LNCONT:skip set last SI//~v688I~
//  repch=CHAR_EBC_ERR;                                            //~v66CR~
//  repch=Ssubcharebcsbcs;                                         //~v66CI~//~v69cR~
    repch=UCVEBCH_subcharebcsbcs(Phandle);                         //~v69cR~
//  repchdbcs=CHAR_EBC_ERR_DBCS;                                   //~v66cR~
//  repchdbcs=ucvebc_getsubchar_dbcs(UCVEBCGSCDO_EBC);             //~v66cI~//~v66CR~
//  repchdbcs=UTF_GETUCSBESTR(Spsubcharebcdbcs);                   //~v66CR~//~v69cR~
    repchdbcs=UTF_GETUCSBESTR(UCVEBCH_subcharebcdbcs(Phandle));    //~v69cI~
    repchparm=repch|(repchdbcs<<8);                                //~0423I~
    mblen=len;
    if (len==1
    &&  *Pdata<' '
    &&  !(Popt & UCVEBC3O_CVCTL)
    )
    {                                                              //~v660I~
        rc|=EBC2ASC_RC_ERRREP;                                     //~v66mR~
//      *Poutbuff=repch;    //SBCS repch                           //~v660I~//~v6BiR~
        *Poutbuff=(UCHAR)repch;    //SBCS repch                    //~v6BiI~
    }                                                              //~v660I~
    else
    {
    	if (len==1)
        {
//  		ebc=ucvebc3_m2b1Sbcs1(opt,*Pdata);                     //~v66qR~//~v69cR~
    		ebc=ucvebc3_m2b1Sbcs1(opt,Phandle,*Pdata);             //~v69cI~
//            if (!ebc && *Pdata) //no mapping tbl defined           //~v66mI~//~v66qR~
//            {                                                      //~v66mI~//~v66qR~
//                *Poutbuff=*Pdata;   //keep org value               //~v66mR~//~v66qR~
//            }                                                      //~v66mI~//~v66qR~
//            else                                                   //~v66mI~//~v66qR~
            if (ebc==-1)
            {                                                      //~0423I~
                rc|=EBC2ASC_RC_ERRREP;                             //~0426R~
//              *Poutbuff=repch;	//SBCS repch                   //~0423R~//~v6BiR~
                *Poutbuff=(UCHAR)repch;	//SBCS repch               //~v6BiI~
            }                                                      //~0423I~
            else
//              *Poutbuff=ebc;                                     //~v6BiR~
                *Poutbuff=(UCHAR)ebc;                              //~v6BiI~
        }
        else
        {
//  		rc2=ucvasc2ebc(opt,Pdata,0/*pdbcs*/,Poutbuff,len,repchparm,&outlen);//~0423R~//~v69cR~
    		rc2=ucvasc2ebc_handle(opt,Phandle,Pdata,0/*pdbcs*/,Poutbuff,len,repchparm,&outlen);//~v69cR~
//          rc2&=~EBC2ASC_RC_DBCSFOUND;                            //~0423I~//~v688R~
            rc2&=~(EBC2ASC_RC_DBCSFOUND|EBC2ASC_RC_SIPEND);        //~v688R~
            if (rc2& EBC2ASC_RC_HANKANA && outlen==1)              //~v66UI~
            {                                                      //~v66UI~
	            rc2&=~EBC2ASC_RC_HANKANA;                          //~v66UI~
                mblen=1;                                           //~v66UI~
            }                                                      //~v66UI~
//          if (rc2||outlen!=2)                                    //~v66UR~
            if (rc2||!outlen)                                      //~v66UI~
            {                                                      //~v66XI~
                if (outlen)                                        //~v66XI~
                    mblen=outlen;                                  //~v66XI~
                rc|=EBC2ASC_RC_ERRREP;                             //~0426R~
            }                                                      //~v66XI~
        	else
            	if (!*Poutbuff && *Pdata)    //not null-->null by sbcs map
                	rc|=EBC2ASC_RC_ERRREP;                         //~0426R~
        }
    }
    if (Ppoutlen)
    	*Ppoutlen=mblen;
UTRACED("ucvebc3 m2b1 output data",Poutbuff,mblen);
UTRACEP("ucvebc3 m2b1 opt=%x,rc=%d,errrep=%x\n",Popt,rc,repch);    //~v660R~
    return rc;
}//ucvebc3_m2b1
//****************************************************************
//*ebc<--mb translation using dbcstbl                              //~0424R~
//*errdbcs is repelace
//*rc:1 errrep,8:buff ovf
//****************************************************************
//int ucvebc3_m2b(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~v69cR~
int ucvebc3_m2b(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~v69cI~
{
    int rc=0,resleno,reslen,mblen,swdbcs,len,outlen;
    int swbin;                                                     //~v66yR~
    int rc2;                                                       //~v66UI~
    int opt;                                                       //~v66XI~
    int setsoopt,sosilen,replen,setsoopt0;                                   //~v688I~//~v689R~
    UCHAR *pcd,*pci,*pco,*pcdo;
    UCHAR wkebc[MAX_MBCSLEN];                                      //~v66UI~
//***************************
UTRACED("ucvebc3 m2b inp data",Pdata,Plen);
UTRACED("ucvebc3 m2b inp dbcd",Pdbcs,Plen);
    swdbcs=0;
    swbin=(Popt & UCVEBC3O_BIN);                                   //~v66yR~
    opt=Popt;                                                      //~v66XI~
    opt|=UCVEBC3O_MBCHSZ;    //m2b parm length is mbchsz           //~v66XI~
    setsoopt0=Sebcopta2e;                                          //~v689I~
    if (Popt & (UCVEBC3O_SOSIINS|UCVEBC3O_SOSIREP))	//cmd option specified//~v689I~
    {                                                              //~v689I~
    	setsoopt0 &= ~(EBC2ASC_SOSI|EBC2ASC_SOSIOS);	//delete cfg parameter effect//~v689I~
    	if (Popt & UCVEBC3O_SOSIINS)	//cmd option specified     //~v689I~
    		setsoopt0 |= EBC2ASC_SOSI;		//insert option        //~v689I~
        else                                                       //~v689I~
	    	setsoopt0 |= EBC2ASC_SOSIOS;	//rep boundary space   //~v689I~
    }                                                              //~v689I~
	for (pci=Pdata,reslen=Plen,pcd=Pdbcs,pco=Poutbuff,pcdo=Poutdbcs,resleno=Poutbuffsz;
//			reslen>0;pci+=len,pcd+=len,reslen-=len,resleno-=len)   //~v66UR~
 			reslen>0;pci+=len,pcd+=len,reslen-=len)                //~v66UR~
    {
      if (swbin)	//no chk dbcstbl                               //~v66yR~
      {                                                            //~v66yI~
        len=1;                                                     //~v66yI~
        if (resleno<len)                                           //~v66yI~
        {                                                          //~v66yI~
        	rc=8;                                                  //~v66yI~
        	break;                                                 //~v66yI~
        }                                                          //~v66yI~
        *pcdo++=0;                                                 //~v66yI~
//   	rc|=ucvebc3_m2b1(Popt,pci,len,pco,&outlen);                //~v66XR~
// 		rc|=ucvebc3_m2b1(opt,pci,len,pco,&outlen);                 //~v66XI~//~v69cR~
   		rc|=ucvebc3_m2b1(opt,Phandle,pci,len,pco,&outlen);         //~v69cI~
        pco++;                                                     //~v66UR~
        outlen=len;                                                //~v66UI~
        resleno--;                                                 //~v66UI~
      }                                                            //~v66yI~
      else                                                         //~v66yI~
      {                                                            //~v66yI~
        UTRACED("b2m dbcs",pcd,1);                                 //~v66XI~
    	if (*pcd==UDBCSCHK_DBCS1ST)
        {
//      	if (reslen==1)                                         //~v66XR~
//      		len=1;                                             //~v66XR~
//          else                                                   //~v66XR~
//      		len=2;                                             //~v66XR~
            len=UDBCSCHK_PCD_MBCHSZ(pcd,reslen);    //1 if err     //~v66XI~
        }
        else
        	len=1;
        if (resleno<len+1)                                         //~0423R~
        {
        	rc=8;
        	break;
        }
//		rc2=ucvebc3_m2b1(Popt,pci,len,wkebc,&outlen);              //~v66XR~
//		rc2=ucvebc3_m2b1(opt,pci,len,wkebc,&outlen);               //~v66XI~//~v69cR~
  		rc2=ucvebc3_m2b1(opt,Phandle,pci,len,wkebc,&outlen);       //~v69cI~
        rc|=rc2;                                                   //~v66UI~
//      if (len==2)                                                //~v66UR~
        if (outlen==2)                                             //~v66UI~
        {
        	if (!swdbcs)
            {
            	swdbcs=1;
//      		*pco++=CHAR_SO;                                    //~v688R~
//  			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
    			setsoopt=setsoopt0;                                //~v689I~
            	if (pci==Pdata)                                    //~v688I~
	            	setsoopt|=EBC2ASC_BUFTOP;	//insert SO        //~v688I~
              	ucvebc2_setso(setsoopt,pci,pco,reslen,&sosilen);	//SO inserted//~v688R~
              if (sosilen)	//SO inserted                          //~v688I~
              {                                                    //~v688I~
              	pco++;                                             //~v688I~
        		*pcdo++=0;
                resleno--;
              }                                                    //~v688I~
            }
            *pco++=wkebc[0];                                       //~v66UI~
            *pco++=wkebc[1];                                       //~v66UI~
            *pcdo++=UDBCSCHK_DBCS1ST;
            *pcdo++=UDBCSCHK_DBCS2ND;
//	        resleno--;                                             //~v66UI~//~v688R~
  	        resleno-=2;                                            //~v688I~
        }
        else
        {
        	replen=0;                                              //~v688I~
        	if (swdbcs)
            {
            	swdbcs=0;
//      		*pco++=CHAR_SI;                                    //~v688R~
//  			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
    			setsoopt=setsoopt0;                                //~v689I~
				ucvebc2_setsi(setsoopt,pci,pco,reslen,&replen,&sosilen);//~v688I~
              if (sosilen)                                         //~v69cI~
              {                                                    //~v69cI~
              	pco++;                                             //~v688R~
        		*pcdo++=0;
                resleno--;
              }                                                    //~v69cI~
            }
          if (!replen)                                             //~v688I~
          {                                                        //~v688I~
            *pco++=wkebc[0];                                       //~v66UI~
        	*pcdo++=0;
//           resleno-=2;                                           //~v66UI~//~v688R~
             resleno--;                                            //~v688I~
          }                                                        //~v688I~
        }
      }                                                            //~v66yI~
//  	rc|=ucvebc3_m2b1(Popt,pci,len,pco,&outlen);                //~v66UR~
//      pco+=len;                                                  //~v66UR~
    }
    if (swdbcs) //last end by dbcs                                 //~0423I~
    {                                                              //~0423I~
//        *pco++=CHAR_SI;                                            //~0423I~//~v69cR~
//        *pcdo++=0;                                                 //~0423I~//~v69cR~
    	setsoopt=setsoopt0;                                        //~v69cI~
		ucvebc2_setsi(setsoopt,"xx"/*nonspace*/,pco,reslen,&replen,&sosilen);//~v69cI~
        if (sosilen)                                               //~v69cI~
        {                                                          //~v69cI~
        	pco++;                                                 //~v69cI~
        	*pcdo++=0;                                             //~v69cI~
            resleno--;                                             //~v69cI~
        }                                                          //~v69cI~
    }                                                              //~0423I~
//  mblen=(int)((ULONG)pco-(ULONG)Poutbuff);                       //~v6hhR~
    mblen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                       //~v6hhI~
    if (Ppoutlen)
        *Ppoutlen=mblen;
UTRACED("ucvebc3 m2m  output data",Poutbuff,mblen);
UTRACED("ucvebc3 m2b  output dbcs",Poutdbcs,mblen);                //~0423R~
UTRACEP("ucvebc3 rc=%d\n",rc);
    return rc;
}//ucvebc3_m2b                                                     //~0426R~
//**************************************************************** //~v687I~
//*utf8->ebc translation (XXE use)                                 //~v69mR~
//*fcmd f2b after restoretab                                       //~v6biI~
//*errdbcs is repelace                                             //~v687I~
//*rc:1 errrep,8:buff ovf                                          //~v687I~
//**************************************************************** //~v687I~
//int ucvebc3_f2b(int Popt,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~v687I~//~v69cR~
int ucvebc3_f2b(int Popt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~v69cI~
{                                                                  //~v687I~
    int rc=0,resleno,reslen,mblen,swdbcs,outlen=0,repch,repchdbcs,/*opt,*/rc2,opt2;//~v687R~//~v6b9R~//~v6h6R~
    int swdbcsenv,chklen;                                          //~v687R~
    int setsoopt,sosilen,replen,setsoopt0;                                   //~v688R~//~v689R~
    int explen=0,rcsosi;                                           //~v6biR~
    UCHAR *pci,*pco,*pcdo;                                         //~v687R~
    ULONG wucs;                                                    //~v687I~
    UCHAR wkebc[4];                                                //~v687I~
//***************************                                      //~v687I~
UTRACED("ucvebc3 f2b inp data",Pdata,Plen);                        //~v687I~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v687I~//~v69cR~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~v69cI~
    swdbcs=0;                                                      //~v687I~
//  repch=Ssubcharebcsbcs;	//repch                                //~v687I~//~v69cR~
    repch=UCVEBCH_subcharebcsbcs(Phandle);	//repch                //~v69cI~
//  repchdbcs=UTF_GETUCSBESTR(Spsubcharebcdbcs);                   //~v687I~//~v69cR~
    repchdbcs=UTF_GETUCSBESTR(UCVEBCH_subcharebcdbcs(Phandle));    //~v69cI~
//  opt=0;	//repch                                                //~v687I~//~v6b9R~
    setsoopt0=Sebcopta2e;                                          //~v689I~
    if (Popt & UCVEBC3O_SOSISHIFT)                                 //~v6biI~
    {                                                              //~v6biI~
    	setsoopt0 &= ~EBC2ASC_SOSI;                                //~v6biI~
    	setsoopt0|=EBC2ASC_SOSIOS|EBC2ASC_SOSISHIFT;               //~v6biI~
    }                                                              //~v6biI~
    else                                                           //~v6biI~
    if (Popt & (UCVEBC3O_SOSIINS|UCVEBC3O_SOSIREP))	//cmd option specified//~v689I~
    {                                                              //~v689I~
    	setsoopt0 &= ~(EBC2ASC_SOSI|EBC2ASC_SOSIOS);	//delete cfg parameter effect//~v689I~
    	if (Popt & UCVEBC3O_SOSIINS)	//cmd option specified     //~v689I~
    		setsoopt0 |= EBC2ASC_SOSI;		//insert option        //~v689I~
        else                                                       //~v689I~
	    	setsoopt0 |= EBC2ASC_SOSIOS;	//rep boundary space   //~v689I~
    }                                                              //~v689I~
	for (pci=Pdata,reslen=Plen,pco=Poutbuff,pcdo=Poutdbcs,resleno=Poutbuffsz;//~v687I~
    		reslen>0;pci+=chklen,reslen-=chklen)                   //~v687I~
    {                                                              //~v687I~
		rc2=utfgetwc(pci,reslen,&wucs,&chklen);                    //~v687R~
        if (!rc2)                                                  //~v687I~
        {                                                          //~v687I~
            opt2=Popt;                                             //~v687I~
//  		rc2=ucvebc3_u2b1(opt2,(WUCS)wucs,wkebc,&outlen);             //~v687I~//~v688R~//~v69cR~
//  		rc2=ucvebc3_u2b1(opt2,Phandle,(WUCS)wucs,wkebc,&outlen);//~v69cI~//~v6BjR~
    		rc2=ucvebc3_u2b1(opt2,Phandle,(UWUCS)wucs,wkebc,&outlen);//~v6BjI~
            if (rc2==UCVEXTRC_SUBCH)                               //~v687I~
            {                                                      //~v687I~
                rc2=0;                                             //~v687I~
            	rc|=EBC2ASC_RC_ERRREP;                             //~v687I~
            }                                                      //~v687I~
        }                                                          //~v687I~
        if (rc2)                                                   //~v687I~
			outlen=1;                                              //~v687I~
	  if (swdbcsenv)                                               //~v687I~
      {                                                            //~v687I~
        if (outlen==2)                                             //~v687I~
        {                                                          //~v687I~
        	if (!swdbcs)                                           //~v687I~
            {                                                      //~v687I~
            	swdbcs=1;                                          //~v687I~
//      		*pco++=CHAR_SO;                                    //~v687I~//~v688R~
//    			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
     			setsoopt=setsoopt0;                                //~v689I~
            	if (pci==Pdata)                                    //~v688I~
	            	setsoopt|=EBC2ASC_BUFTOP;	//insert SO        //~v688I~
              rcsosi=                                              //~v6biI~
              	ucvebc2_setso(setsoopt,pci,pco,reslen,&sosilen);	//SO inserted//~v688R~
              if (sosilen)	//SO inserted                          //~v688I~
              {                                                    //~v688I~
              	pco++;                                             //~v688I~
        		*pcdo++=0;                                         //~v687I~
                resleno--;                                         //~v687I~
                if (rcsosi)	//not replaced neighbor                //~v6biI~
	                explen++;	//to be shrink                     //~v6biR~
              }                                                    //~v688I~
            }                                                      //~v687I~
            *pcdo++=UDBCSCHK_DBCS1ST;                              //~v687I~
            *pcdo++=UDBCSCHK_DBCS2ND;                              //~v687I~
        }                                                          //~v687I~
        else                                                       //~v687I~
        {                                                          //~v687I~
        	if (swdbcs)                                            //~v687I~
            {                                                      //~v687I~
            	swdbcs=0;                                          //~v687I~
//      		*pco++=CHAR_SI;                                    //~v687I~//~v688R~
//  			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
    			setsoopt=setsoopt0;                                //~v689I~
              rcsosi=                                              //~v6biI~
				ucvebc2_setsi(setsoopt,pci,pco,reslen,&replen,&sosilen);//~v688I~
                if (replen)                                        //~v688I~
                    outlen=0;   //next space is replaced by SI     //~v688R~
              if (sosilen)                                         //~v69cI~
              {                                                    //~v69cI~
              	pco++;                                             //~v688R~
        		*pcdo++=0;                                         //~v687I~
                resleno--;                                         //~v687I~
                if (rcsosi)	//not replaced neighbor                //~v6biI~
	                explen++;	//to be shrink                     //~v6biR~
              }                                                    //~v69cI~
            }                                                      //~v687I~
          if (outlen)                                              //~v688I~
        	*pcdo++=0;                                             //~v687I~
        }                                                          //~v687I~
        if (!rc2)                                                  //~v687I~
        {                                                          //~v687I~
          if (explen                                               //~v6biI~
          &&  (setsoopt0 & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert//~v6biR~
          &&  outlen==1                                            //~v6biI~
          &&  wkebc[0]==CHAR_EBC_SPACE                             //~v6biR~
          &&  pco>Poutbuff                                         //~v6biI~
          &&  (*(pco-1)==CHAR_SI||*(pco-1)==CHAR_EBC_SPACE) //keep word delm//~v6biI~
          )                                                        //~v6biI~
          {                                                        //~v6biI~
            outlen=0;                                              //~v6biI~
            explen--;                                              //~v6biI~
          }                                                        //~v6biI~
          else                                                     //~v6biI~
          if (outlen)                                              //~v688I~
//          memcpy(pco,wkebc,outlen);                              //~v687I~//~v6BkR~
            memcpy(pco,wkebc,(size_t)outlen);                      //~v6BkI~
        }                                                          //~v687I~
        else                                                       //~v687I~
        {                                                          //~v687I~
        	if (outlen>1)                                          //~v687I~
            	UTF_SETUCSBESTR(repchdbcs,pco);                    //~v687I~
            else                                                   //~v687I~
//      		*pco=repch;                                        //~v687I~//~v6BiR~
        		*pco=(UCHAR)repch;                                 //~v6BiI~
            rc|=EBC2ASC_RC_ERRREP;                                 //~v687I~
        }                                                          //~v687I~
        pco+=outlen;                                               //~v687I~
        resleno-=outlen;                                           //~v687I~
      }                                                            //~v687I~
      else	//!dbcsenv                                             //~v687I~
      {                                                            //~v687I~
        *pcdo++=0;                                                 //~v69nI~
        if (!rc2)                                                  //~v687I~
        {                                                          //~v687I~
        	*pco=*wkebc;                                           //~v687I~
        }                                                          //~v687I~
        else                                                       //~v687I~
        {                                                          //~v687I~
//      	*pco=repch;                                            //~v687I~//~v6BiR~
        	*pco=(UCHAR)repch;                                     //~v6BiI~
            rc|=EBC2ASC_RC_ERRREP;                                 //~v687I~
        }                                                          //~v687I~
        pco+=outlen;                                               //~v687I~
        resleno-=outlen;                                           //~v687I~
      }                                                            //~v687I~
    }                                                              //~v687I~
    if (swdbcs) //last end by dbcs                                 //~v687I~
    {                                                              //~v687I~
//        *pco++=CHAR_SI;                                            //~v687I~//~v69cR~
//        *pcdo++=0;                                                 //~v687I~//~v69cR~
    	setsoopt=setsoopt0;                                        //~v69cI~
		ucvebc2_setsi(setsoopt,"xx"/*nonspace*/,pco,reslen,&replen,&sosilen);//~v69cI~
        if (sosilen)                                               //~v69cI~
        {                                                          //~v69cI~
        	pco++;                                                 //~v69cI~
        	*pcdo++=0;                                             //~v69cI~
            resleno--;                                             //~v69cI~
        }                                                          //~v69cI~
    }                                                              //~v687I~
//  mblen=(int)((ULONG)pco-(ULONG)Poutbuff);                       //~v687I~//~v6hhR~
    mblen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                       //~v6hhI~
    if (Ppoutlen)                                                  //~v687I~
        *Ppoutlen=mblen;                                           //~v687I~
//  if (!swdbcsenv)                                                //~v69iI~//~v69nR~
//  	memset(Poutdbcs,0,mblen);                                  //~v69iI~//~v69nR~
UTRACED("ucvebc3 f2b  output data",Poutbuff,mblen);                //~v687I~
UTRACED("ucvebc3 f2b  output dbcs",Poutdbcs,mblen);                //~v687I~
UTRACEP("ucvebc3 f2b rc=%d,opt=%x\n",rc,Popt);                     //~v687I~
    return rc;                                                     //~v687I~
}//ucvebc3_f2b                                                     //~v687I~
//**************************************************************** //~0423I~
//*dd fmt->ebc translation                                         //~0423I~
//*errdbcs is repelace                                             //~0423I~
//*rc:1 errrep,8:buff ovf                                          //~0423I~
//**************************************************************** //~0423I~
//int ucvebc3_dd2b(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~0423R~//~v69cR~
int ucvebc3_dd2b(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~v69cI~
{                                                                  //~0423I~
    int rc=0,resleno,reslen,mblen,swdbcs,outlen=0,repch,repchdbcs,opt,/*dcsid,*/rc2,chsz,opt2;//~0423R~//~v6b9R~//~v6h6R~
    int swdbcsenv,swunp;                                           //~v66mR~
    int setsoopt,sosilen,replen,setsoopt0;                                   //~v688R~//~v689R~
    int swsetf2lerr;                                               //~v69nI~
    UCHAR *pcd,*pci,*pco,*pcdo;                                    //~0423I~
//  WUCS wucs;                                                     //~0423I~//~v6BjR~
    UWUCS wucs;                                                    //~v6BjI~
    UCHAR wkebc[4];                                                //~v66sI~
//***************************                                      //~0423I~
UTRACED("ucvebc3 dd2b inp data",Pdata,Plen);                       //~0423I~
UTRACED("ucvebc3 dd2b inp dbcd",Pdbcs,Plen);                       //~0423I~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v66mI~//~v69cR~
    swsetf2lerr=Popt & UCVEBC3O_SETF2LERR;                         //~v69nI~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~v69cI~
    swdbcs=0;                                                      //~0423I~
//  repch=CHAR_EBC_ERR;	//repch                                    //~0423R~//~v66CR~
//  repch=Ssubcharebcsbcs;	//repch                                //~v66CI~//~v69cR~
    repch=UCVEBCH_subcharebcsbcs(Phandle);	//repch                //~v69cI~
//  repchdbcs=CHAR_EBC_ERR_DBCS;	//repch                        //~0423I~//~v66cR~
//  repchdbcs=ucvebc_getsubchar_dbcs(UCVEBCGSCDO_EBC);             //~v66cI~//~v66CR~
//  repchdbcs=UTF_GETUCSBESTR(Spsubcharebcdbcs);                   //~v66CI~//~v69cR~
    repchdbcs=UTF_GETUCSBESTR(UCVEBCH_subcharebcdbcs(Phandle));    //~v69cI~
    opt=0;	//repch                                                //~0423R~
    setsoopt0=Sebcopta2e;                                          //~v689I~
    if (Popt & (UCVEBC3O_SOSIINS|UCVEBC3O_SOSIREP))	//cmd option specified//~v689I~
    {                                                              //~v689I~
    	setsoopt0 &= ~(EBC2ASC_SOSI|EBC2ASC_SOSIOS);	//delete cfg parameter effect//~v689I~
    	if (Popt & UCVEBC3O_SOSIINS)	//cmd option specified     //~v689I~
    		setsoopt0 |= EBC2ASC_SOSI;		//insert option        //~v689I~
        else                                                       //~v689I~
	    	setsoopt0 |= EBC2ASC_SOSIOS;	//rep boundary space   //~v689I~
    }                                                              //~v689I~
	for (pci=Pdata,reslen=Plen,pcd=Pdbcs,pco=Poutbuff,pcdo=Poutdbcs,resleno=Poutbuffsz;//~0423I~
//  		reslen>0;pci+=chsz,pcd+=chsz,reslen-=chsz,resleno-=chsz)//~0423R~//~v66mR~
    		reslen>0;pci+=chsz,pcd+=chsz,reslen-=chsz)             //~v66mI~
    {                                                              //~0423I~
//    	dbcsid=*pcd;                                               //~0423I~//~v6b9R~
    	wucs=utfdd2u1chsz(opt,pci,pcd,reslen,&chsz);               //~0423R~
        swunp=0;	//unprintable ucs                              //~v66mI~
        rc2=0;                                                 //~v66mI~//~v66sI~
        if (chsz==-2) //unprintable ucs                            //~v66mR~
        {                                                          //~v66mI~
            chsz=2;	//input area step                              //~v66mI~
            swunp=1;                                               //~v66mI~
        }                                                          //~v66mI~
        else                                                       //~v66mI~
        if (chsz<0)	//dbcs split data,unprintabe ucs               //~0423R~//~v66mR~
        {                                                          //~0423I~
        	rc2=4;                                                 //~0423I~
            chsz=1;                                                //~0423I~
        }                                                          //~0423I~
//        else                                                       //~0423I~//~v66HR~
//        {                                                          //~0423I~//~v66HR~
//          if (swdbcsenv)                                           //~v66mI~//~v66HR~
//            if (wucs==CHAR_SO||wucs==CHAR_SI)                      //~0423R~//~v66HR~
//                rc2=4;                                             //~0423I~//~v66HR~
//        }                                                          //~0423I~//~v66HR~
        if (resleno<chsz+1)                                        //~0423I~
        {                                                          //~0423I~
        	rc=8;                                                  //~0423I~
        	break;                                                 //~0423I~
        }                                                          //~0423I~
        if (!rc2)                                                  //~v66sI~
        {                                                          //~v66sI~
            opt2=Popt;                                             //~v66sI~
            if (swunp)                                             //~v66sI~
                opt2|=UCVEBC3O_UCSNP;   //no errrep sbcs           //~v66sI~
//  		rc2=ucvebc3_u2b1(opt2,wucs,wkebc,&outlen);             //~v66sI~//~v69cR~
    		rc2=ucvebc3_u2b1(opt2,Phandle,wucs,wkebc,&outlen);     //~v69cI~
            if (rc2==UCVEXTRC_SUBCH)                               //~v66CI~
            if (!swsetf2lerr)                                      //~v69nI~
            {                                                      //~v66CI~
                rc2=0;                                             //~v66CI~
            	rc|=EBC2ASC_RC_ERRREP;                             //~v66CI~
            }                                                      //~v66CI~
        }                                                          //~v66sI~
        if (rc2)                                                   //~v66sI~
			outlen=1;                                              //~v66sI~
	  if (swdbcsenv)                                               //~v66mI~
      {                                                            //~v66mI~
//      if (chsz==2)                                               //~0423I~//~v66sR~
        if (outlen==2)                                             //~v66sI~
        {                                                          //~0423I~
        	if (!swdbcs)                                           //~0423I~
            {                                                      //~0423I~
            	swdbcs=1;                                          //~0423I~
//      		*pco++=CHAR_SO;                                    //~0423I~//~v688R~
//  			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
    			setsoopt=setsoopt0;                                //~v689I~
            	if (pci==Pdata)                                    //~v688I~
	            	setsoopt|=EBC2ASC_BUFTOP;	//insert SO        //~v688I~
              	ucvebc2_setso(setsoopt,pci,pco,reslen,&sosilen);	//SO inserted//~v688R~
              if (sosilen)	//SO inserted                          //~v688I~
              {                                                    //~v688I~
              	pco++;                                             //~v688I~
        		*pcdo++=0;                                         //~0423I~
                resleno--;                                         //~0423I~
              }                                                    //~v688I~
            }                                                      //~0423I~
            *pcdo++=UDBCSCHK_DBCS1ST;                              //~0423I~
            *pcdo++=UDBCSCHK_DBCS2ND;                              //~0423I~
//          opt2=Popt|UCVEBC3O_DBCS;                                //~0423I~//~v660R~//~v66sR~
        }                                                          //~0423I~
        else                                                       //~0423I~
        {                                                          //~0423I~
        	if (swdbcs)                                            //~0423I~
            {                                                      //~0423I~
            	swdbcs=0;                                          //~0423I~
//      		*pco++=CHAR_SI;                                    //~0423I~//~v688R~
//  			setsoopt=Sebcopta2e;                               //~v688I~//~v689R~
    			setsoopt=setsoopt0;                                //~v689I~
				ucvebc2_setsi(setsoopt,pci,pco,reslen,&replen,&sosilen);//~v688I~
                if (replen)                                        //~v688I~
                    outlen=0;   //next space is replaced by SI     //~v688R~
              if (sosilen)                                         //~v69cI~
              {                                                    //~v69cI~
              	pco++;                                             //~v688R~
        		*pcdo++=0;                                         //~0423I~
                resleno--;                                         //~0423I~
              }                                                    //~v69cI~
            }                                                      //~0423I~
          if (outlen)                                              //~v688I~
        	*pcdo++=0;                                             //~0423I~
//          opt2=Popt&~UCVEBC3O_DBCS;     //CVCTL etc                                         //~0423I~//~v660R~//~v66sR~
        }                                                          //~0423I~
        if (!rc2)                                                  //~0423R~
        {                                                          //~0423I~
//  		rc2=ucvebc3_u2b1(opt2,wucs,pco,&outlen);               //~0423R~//~v66sR~
//          if (rc2||outlen!=chsz)                                 //~0423R~//~v66sR~
//          	rc2=4;                                             //~0423I~//~v66sR~
          if (outlen)                                              //~v688I~
//          memcpy(pco,wkebc,outlen);                              //~v66sI~//~v6BkR~
            memcpy(pco,wkebc,(size_t)outlen);                      //~v6BkI~
        }                                                          //~0423I~
//      if (rc2)                                                   //~0423I~//~v66sR~
        else                                                       //~v66sI~
        {                                                          //~0423I~
//      	if (chsz>1)                                            //~0423I~//~v66sR~
        	if (outlen>1)                                          //~v66sI~
            {                                                      //~v69nI~
            	UTF_SETUCSBESTR(repchdbcs,pco);                    //~0423I~
            	if (swsetf2lerr)                                   //~v69nI~
        			memset(pcdo,UDBCSCHK_F2LERR,(UINT)outlen);     //~v69nR~
            }                                                      //~v69nI~
            else                                                   //~0423I~
            {                                                      //~v69nI~
//      		*pco=repch;                                        //~0423I~//~v6BiR~
        		*pco=(UCHAR)repch;                                 //~v6BiI~
        		*pcdo=UDBCSCHK_F2LERR;    //set outlen=1 later     //~v69nI~
            }                                                      //~v69nI~
            rc|=EBC2ASC_RC_ERRREP;                                 //~0423I~
        }                                                          //~0423I~
//      pco+=chsz;                                                 //~0423I~//~v66sR~
//      resleno-=chsz;                                             //~v66mI~//~v66sR~
        pco+=outlen;                                               //~v66sI~
        resleno-=outlen;                                           //~v66sI~
      }                                                            //~v66mI~
      else	//!dbcsenv                                             //~v66mI~
      {                                                            //~v66mI~
        if (!rc2)                                                  //~v66mI~
        {                                                          //~v66mI~
//          opt2=Popt&~UCVEBC3O_DBCS;     //CVCTL etc              //~v66mI~//~v66sR~
//          if (swunp)                                             //~v66mI~//~v66sR~
//              opt2|=UCVEBC3O_UCSNP;   //no errrep sbcs           //~v66mI~//~v66sR~
//  		rc2=ucvebc3_u2b1(opt2,wucs,pco,&outlen);               //~v66mI~//~v66sR~
//          if (rc2)                                               //~v66mI~//~v66sR~
//          	rc2=4;                                             //~v66mI~//~v66sR~
        	*pco=*wkebc;                                           //~v66sI~
        	*pcdo++=0;                                             //~v69nI~
        }                                                          //~v66mI~
//      if (rc2)                                                   //~v66mI~//~v66sR~
        else                                                       //~v66sI~
        {                                                          //~v66mI~
//      	*pco=repch;                                            //~v66mI~//~v6BiR~
        	*pco=(UCHAR)repch;                                     //~v6BiI~
            rc|=EBC2ASC_RC_ERRREP;                                 //~v66mI~
            if (swsetf2lerr)                                       //~v69nI~
        		*pcdo++=UDBCSCHK_F2LERR;                           //~v69nR~
            else                                                   //~v69nI~
	        	*pcdo++=0;                                         //~v69nI~
//          outlen=1;                                              //~v66mI~//~v66sR~
        }                                                          //~v66mI~
        pco+=outlen;                                               //~v66mI~
        resleno-=outlen;                                           //~v66mI~
      }                                                            //~v66mI~
    }                                                              //~0423I~
    if (swdbcs) //last end by dbcs                                 //~0423I~
    {                                                              //~0423I~
//        *pco++=CHAR_SI;                                            //~0423I~//~v69cR~
//        *pcdo++=0;                                                 //~0423I~//~v69cR~
    	setsoopt=setsoopt0;                                        //~v69cI~
		ucvebc2_setsi(setsoopt,"xx"/*nonspace*/,pco,reslen,&replen,&sosilen);//~v69cI~
        if (sosilen)                                               //~v69cI~
        {                                                          //~v69cI~
        	pco++;                                                 //~v69cI~
        	*pcdo++=0;                                             //~v69cI~
            resleno--;                                             //~v69cI~
        }                                                          //~v69cI~
    }                                                              //~0423I~
//  mblen=(int)((ULONG)pco-(ULONG)Poutbuff);                       //~0423I~//~v6hhR~
    mblen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                       //~v6hhI~
    if (Ppoutlen)                                                  //~0423I~
        *Ppoutlen=mblen;                                           //~0423I~
//  if (!swdbcsenv)                                                //~v69iI~//~v69nR~
//  	memset(Poutdbcs,0,mblen);                                  //~v69iI~//~v69nR~
UTRACED("ucvebc3 dd2b  output data",Poutbuff,mblen);               //~0423I~
UTRACED("ucvebc3 dd2b  output dbcs",Poutdbcs,mblen);               //~0423I~
UTRACEP("ucvebc3 rc=%d,opt=%x\n",rc,Popt);                                     //~0423I~//~v66mR~
    return rc;                                                     //~0423I~
}//ucvebc3_dd2b                                                    //~0423R~
//*************************************************************************
//* ebc string to mbstr(SBCS)
//* rc:1:F2LERR,8:buff ovf
//*************************************************************************
//int ucvebc3_b2mSbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen)//~v68bR~//~v69cR~
int ucvebc3_b2mSbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen)//~v69cR~
{
    int rc=0,rc2,resleno,opt,repch,mblen,ch;
    int mb2;                                                       //~v66UI~
    int swsetf2lerr;                                               //~0508I~
    int swdbcsenv;                                                 //~v66mI~
    UCHAR *pci,*pce,*pcd,*pco;
    int dbcsskip;                                                  //~v66XI~
    PUCVEBCH pucveh;                                               //~v69cI~
//***************************
    UTRACEP("b2msbcs opt=%x,handle=%d\n",Popt,Phandle);                              //~0423I~//~v69cR~
//  UTRACED("b2msbcs input data",Pdata,Pinplen);                   //~0423I~//~v6m3R~
//  UTRACED("b2msbcs input dbcs",Pdbcs,Pinplen);                   //~0423I~//~v6m3R~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
  if (Popt & UCVEBC3O_BIN)                                         //~v66yI~
   	swdbcsenv=0;                                                   //~v66yI~
  else                                                             //~v66yI~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v66mI~//~v69cR~
    swdbcsenv=UCVEBCH_ISDBCSCV(pucveh);   //@@@@                   //~v69cI~
    swsetf2lerr=Popt & UCVEBC3O_SETF2LERR;                         //~0508I~
    opt=Sebcopte2a;
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66DI~
    if(Popt & UCVEBC3O_CVCTL)                                      //~0428I~
    	opt|=EBC2ASC_CTL;                                          //~0428I~
//  repch='.';                                                     //~v66qR~
//  repch=CHAR_ASCII_ERR;                                          //~v66qI~//~v66CR~
    repch=Ssubcharlocalsbcs;                                       //~v66CI~
//  for (pci=Pdata,pce=pci+Pinplen,pcd=Pdbcs,pco=Poutbuff,resleno=Pbuffsz;pci<pce;pci++,pcd++,pco++,resleno--)//~v68bR~
    for (pci=Pdata,pce=pci+Pinplen,pco=Poutbuff,resleno=Pbuffsz;pci<pce;pci++,pco++,resleno--)//~v68bI~
    {
        ch=*pci;
        pcd=UTF_PC2PCD(Poutdbcs,pco,Poutbuff);                     //~v68bI~
        *pcd=0;                                                    //~v68bI~
      if (swdbcsenv)                                               //~v66mI~
      {                                                            //~v66mI~
        if (ch==CHAR_SO||ch==CHAR_SI)
        {
			if (Popt & UCVEBC3O_SOSI2SPACE)    //replace so/si to space//~0423I~
            {                                                      //~0423I~
        		*pco=' ';                                          //~0423I~
//      		*pcd=0;       //keep original value and siplay by green//~v68bR~
            }                                                      //~0423I~
            else                                                   //~0423I~
			if (Popt & UCVEBC3O_SOSIREP)    //replace so/si to space//~0429I~
            {                                                      //~0429I~
        		*pco='.';                                          //~0429I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0429I~
            }                                                      //~0429I~
            else                                                   //~0429I~
			if (Popt & UCVEBC3O_SOSIREPQ)    //replace so/si to space//~0501I~
            {                                                      //~0501I~
        		*pco='?';                                          //~0501I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0501I~
            }                                                      //~0501I~
            else                                                   //~0501I~
			if (Popt & UCVEBC3O_SOSIREPQP)   //replace so/si to space as printable//~v66gI~
            {                                                      //~v66gI~
        		*pco='?';                                          //~v66gR~
//      		*pcd=0;       //keep original value and siplay by green//~v68bR~
            }                                                      //~v66gI~
            else                                                   //~v66gI~
            {                                                      //~0423I~
//      		*pco=ch;                                           //~0423R~//~v6BiR~
        		*pco=(UCHAR)ch;                                    //~v6BiI~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0423R~//~0428R~
            }                                                      //~0423I~
            continue;
        }
      }//swdbcsenv                                                 //~v66mI~
        if (ch<CHAR_EBC_SPACE)
        {
            if (!(Popt & UCVEBC3O_CVCTL))
            {
//      		*pco=ch;                                           //~v6BiR~
        		*pco=(UCHAR)ch;                                    //~v6BiI~
              if (swsetf2lerr)                                     //~0508I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0426R~
          	  else                                                 //~v66qI~
//      		*pco=repch;                                        //~v66qI~//~v6BiR~
        		*pco=(UCHAR)repch;                                 //~v6BiI~
//	            continue;                                          //~v6hfR~
	            rc|=1;                                             //~v66qI~
	            continue;                                          //~v6hfI~
            }
		}
//    if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v66qI~//~v69cR~
      if (UCVEBCH_ISSBCSMAPINIT(pucveh))//sbcsmap was initialized  //~v69cI~
      {                                                            //~v66qI~
//    	*pco=EBC_B2A(ch);                                          //~v66UR~
//  	mb2=EBC_B2A(ch);                                           //~v66UI~//~v69cR~
//  	mb2=UCVEBCH_B2A(Phandle,ch);                               //~v69cR~//~v6BkR~
    	mb2=(int)UCVEBCH_B2A(Phandle,ch);                          //~v6BkI~
        UTRACEP("b2msbcs from B2AMAP ebc=%x,mb=%x\n",ch,mb2);      //~v6hwI~
       if (mb2>>8)                                                 //~v66UI~
       {                                                           //~v66UI~
//      if (EBC_B2A_TYPEISGB4(ch))                                 //~v66XR~//~v69cR~
        if (UCVEBCH_B2A_TYPEISGB4(Phandle,ch))                     //~v69cR~
        {                                                          //~v66XI~
        	mblen=4;                                               //~v66XI~
            UUL2BESTR(mb2,pco);                                    //~v66XI~
            *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCS2ND;//~v68bR~
        }                                                          //~v66XI~
        else                                                       //~v66XR~
//      if (EBC_B2A_TYPEISSS3(ch))                                 //~v66XR~//~v69cR~
        if (UCVEBCH_B2A_TYPEISSS3(Phandle,ch))                     //~v69cR~
        {                                                          //~v66XI~
        	mblen=3;                                               //~v66XR~
            UUL32BESTR(mb2,pco);                                   //~v66XI~
            *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCS2ND;//~v68bR~
        }                                                          //~v66XI~
        else                                                       //~v66XR~
        {                                                          //~v66XI~
        mblen=2;                                                   //~v66UI~
            UUS2BESTR(mb2,pco);                                    //~v66XI~
            *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCS2ND;       //~v68bR~
        }                                                          //~v66XI~
        UTRACED("b2msbcs DBCS from map",pco,mblen);                //~v66XR~
       }                                                           //~v66UI~
       else                                                        //~v66UI~
       {                                                           //~v66UI~
//   	*pco=mb2;                                                  //~v66UI~//~v6BiR~
     	*pco=(UCHAR)mb2;                                           //~v6BiI~
        mblen=1;                                                   //~v66qI~
       }                                                           //~v66UI~
        rc2=0;                                                     //~v66qI~
      }                                                            //~v66qI~
      else                                                         //~v66qI~
      {                                                            //~v66DI~
//      rc2=ucvebc2asc(opt,pci,0/*pdbcs*/,pco,1,repch,&mblen);     //~v69cR~
        rc2=ucvebc2asc_handle(opt,Phandle,pci,0/*pdbcs*/,pco,1,repch,&mblen);//~v69cI~
      }                                                            //~v66DI~
//      UTRACEP("b2msbcs ebc=%x,mb=%02x%02x,rc=%d,mblen=%d\n",ch,*pco,*(pco+1),rc2,mblen);//~v66XR~//~v6m3R~
        if (!rc2)
        {
////cv cmd allow Sbcs->DBCS if no NOS2D cfg option nor -SBCS cmd option//~v66UR~
////but force err for REP cmd etc                                  //~v66UR~
//EUC hankana ex) CP930 ebc-81->eucJ-8eb1                          //~v66UI~
      		if (mblen!=1)                                          //~v66UR~
            {                                                      //~v66UI~
                dbcsskip=mblen-1;                                  //~v66XR~
//            	pco++;                                             //~v66XR~
//            	pcd++;                                             //~v66XR~
//              resleno--;                                         //~v66XR~
              	pco+=dbcsskip;                                     //~v66XI~
//          	pcd+=dbcsskip;                                     //~v68bR~
                resleno-=dbcsskip;                                 //~v66XI~
            }                                                      //~v66UI~
          	else                                                   //~v66UR~
            if (*pco=='.' && *pci!=EBC_PERIOD)    //err rep occured//~v66qR~
                rc2=4;
            else
            if (!*pco && ch)    //not null-->null by sbcs map      //~v66qR~
                rc2=4;
        }
    	if (rc2)
    	{
//      	*pco=ch;                                               //~v6BiR~
        	*pco=(UCHAR)ch;                                        //~v6BiI~
          if (swsetf2lerr)                                         //~0508I~
        	*pcd=UDBCSCHK_F2LERR;       //keep original value and siplay by green
          else                                                     //~v66qI~
//      	*pco=repch;                                            //~v66qI~//~v6BiR~
        	*pco=(UCHAR)repch;                                     //~v6BiI~
            rc|=1;
    	}
    }
//  mblen=(ULONG)pco-(ULONG)Poutbuff;                              //~v6hhR~
//  mblen=(ULPTR)pco-(ULPTR)Poutbuff;                              //~v6hhI~//~v6BkR~
    mblen=PTRDIFF(pco,Poutbuff);                                   //~v6BkI~
    if (Ppmblen)
    	*Ppmblen=mblen;
//UTRACED("ucvebc3 b2m sbcs output data",Poutbuff,mblen);          //~v6m3R~
//UTRACED("ucvebc3 b2m sbcs output dbcs",Poutdbcs,mblen);            //~v68bR~//~v6m3R~
    return rc;
}//ucvebc3_b2mSbcs
//*************************************************************************
//*translate by icu converter
//* ebc string to dd str(DBCS)
//* rc:8 buff ovf,1:F2LERR
//*************************************************************************
//int ucvebc3_b2mDbcsstr(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,int Poutbuffsz,int *Ppmblen)//~v68bR~
//int ucvebc3_b2mDbcsstr(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppmblen)//~v68bI~//~v69cR~
int ucvebc3_b2mDbcsstr(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppmblen)//~v69cI~
{
    int rc=0,mblen,opt,rc2,resleno,repch,repchdbcs,repchparm;      //~v66NR~
    int swsetf2lerr;                                               //~0508I~
    UCHAR *pci,*pce,*pcd,*pco;
//***************************
UTRACED("ucvebc3 b2m data inp data",Pdata,Pinplen);                //~v660R~
UTRACED("ucvebc3 b2m dbcs inp dbcs",Pdbcs,Pinplen);
    swsetf2lerr=Popt & UCVEBC3O_SETF2LERR;                         //~0508I~
    opt=Sebcopte2a|EBC2ASC_STAT_SO|EBC2ASC_SOCONT;
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66DI~
//  repch='.';  //temporary to chk cv err                          //~v66CR~
    repch=Ssubcharlocalsbcs;                                       //~v66CI~
//  repchdbcs=(repch<<8)|repch;                                    //~v66CR~
    repchdbcs=UTF_GETUCSBESTR(Spsubcharlocaldbcs);                 //~v66CI~
    repchparm=repch|(repchdbcs<<8);                                //~v66NI~
//	for (pci=Pdata,pce=pci+Pinplen,pcd=Pdbcs,pco=Poutbuff,resleno=Poutbuffsz;pci<pce;pci+=2,pcd+=2,pco+=2,resleno-=2)//~v68bR~
	for (pci=Pdata,pce=pci+Pinplen,pco=Poutbuff,resleno=Poutbuffsz;pci<pce;pci+=2,pco+=2,resleno-=2)//~v68bI~
    {
    	if (resleno<2)
        {
        	rc=8;
            break;
        }
        pcd=UTF_PC2PCD(Poutdbcs,pco,Poutbuff);                     //~v68bI~
        *pcd=UDBCSCHK_DBCS1ST;                                     //~v68bI~
        *(pcd+1)=UDBCSCHK_DBCS2ND;                                 //~v68bI~
//  	rc2=ucvebc2asc(opt,pci,pcd,pco,2,repchparm,&mblen);        //~v66NR~//~v69cR~
    	rc2=ucvebc2asc_handle(opt,Phandle,pci,pcd,pco,2,repchparm,&mblen);//~v69cR~
        if (!rc2)
        {
  	     	if (mblen!=2)
            	rc2=4;
            else
            if (*pco!=repch && *(pco+1)==repch)    //err rep occured
                rc2=4;
        }
    	if (rc2)
    	{

          if (swsetf2lerr)                                         //~0508I~//~v66NM~
          {                                                        //~v66NI~
        	*pco=*pci;
        	*pcd=UDBCSCHK_F2LERR;       //keep original value and siplay by green
          }                                                        //~v66NI~
            if (pci+1<pce)
            {
              if (swsetf2lerr)                                     //~0508I~//~v66NM~
              {                                                    //~v66NI~
        		*(pco+1)=*(pci+1);
        		*(pcd+1)=UDBCSCHK_F2LERR;
              }                                                    //~v66NI~
            }
            rc|=1;
    	}
    }
//  mblen=(ULONG)pco-(ULONG)Poutbuff;                              //~v6hhR~
//  mblen=(ULPTR)pco-(ULPTR)Poutbuff;                              //~v6hhI~//~v6BkR~
    mblen=PTRDIFF(pco,Poutbuff);                                   //~v6BkI~
    if (Ppmblen)
    	*Ppmblen=mblen;
UTRACED("ucvebc3 b2m data output data",Poutbuff,mblen);            //~v660R~
UTRACED("ucvebc3 b2m dbcs output dbcs",Pdbcs,mblen);
    return rc;
}//ucvebc3_b2mDbcsstr
//****************************************************************
//*ebc-->mb translation
//*update dbcstbl for err
//*data contains no tab/tabpad/so/si
//****************************************************************
//int ucvebc3_b2m(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,int Poutbuffsz,int Prepch,int *Ppoutlen)//~v68bR~
//int ucvebc3_b2m(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int Prepch,int *Ppoutlen)//~v68bR~//~v69cR~
int ucvebc3_b2m(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Poutbuffsz,int Prepch,int *Ppoutlen)//~v69cI~
{
    int rc=0,resleno,mblen,rc2,swdbcs,dbcsid,cvlen;
    int swsetf2lerr;                                               //~0508I~
    int swdropsosi=0;                                              //~v688I~
    UCHAR *pcd,*pci,*pcidbcs=NULL,*pcdsbcs,*pcisbcs,*pcddbcs,*pco,*pce;//~v6h6R~
    UCHAR *pcdo/*,*pcdos*/;	                                       //~v68bR~
//***************************
UTRACED("ucvebc3 inp b2m data",Pdata,Plen);
UTRACED("ucvebc3 inp b2m dbcd",Pdbcs,Plen);
    swsetf2lerr=Popt & UCVEBC3O_SETF2LERR;                         //~0508I~
//if (Popt & UCVEBC3O_BIN)                                         //~0428I~//~v66qR~
  if ((Popt & UCVEBC3O_BIN)                                        //~v66qI~
//||  !UDBCSCHK_ISDBCSCV()                                         //~v66qI~//~v69cR~
  ||  !UCVEBCH_HANDLE_ISDBCSCV(Phandle)                            //~v69cI~
  )                                                                //~v66qI~
// 	rc=ucvebc3_b2mSbcs(Popt,Pdata,Pdbcs,Plen,Poutbuff,Poutbuffsz,&mblen);//~v68bR~
// 	rc=ucvebc3_b2mSbcs(Popt,Pdata,Pdbcs,Plen,Poutbuff,Poutdbcs,Poutbuffsz,&mblen);//~v68bI~//~v69cR~
   	rc=ucvebc3_b2mSbcs(Popt,Phandle,Pdata,Pdbcs,Plen,Poutbuff,Poutdbcs,Poutbuffsz,&mblen);//~v69cI~
  else                                                             //~0428I~
  {                                                                //~0428I~
	if (Popt & UCVEBC3O_SOSICMDO)                                  //~v688I~
    {                                                              //~v688I~
		if (Popt & UCVEBC3O_DROPSOSI)                              //~v688I~
    		swdropsosi=1;                                          //~v688I~
    }                                                              //~v688I~
    else                                                           //~v688I~
    {                                                              //~v688I~
    	if (Sebcopte2a & EBC2ASC_SOSID)                            //~v688I~
	    	swdropsosi=1;                                          //~v688I~
    }                                                              //~v688I~
    pcisbcs=Pdata;
    swdbcs=0;
//    pcdo=Pdbcs;                                                  //~v68bR~
	for (pci=Pdata,pce=pci+Plen,pcd=Pdbcs,pco=Poutbuff,resleno=Poutbuffsz;
//  		pci<=pce;pci++,pcd++)                                  //~v688R~
//  		pci<=pce;pci++,pcd++,pcdo++)                           //~v68bR~
    		pci<=pce;pci++,pcd++)                                  //~v68bI~
    {
        pcdo=UTF_PC2PCD(Poutdbcs,pco,Poutbuff);                    //~v68bI~
        if (pci==pce)
        {
        	if (swdbcs)
            	dbcsid=0;					//write dbcs;
            else
            	dbcsid=UDBCSCHK_DBCS1ST;	//write sbcs

        }
        else
        	dbcsid=*pcd;
    	if (dbcsid==UDBCSCHK_DBCS1ST)
        {
        	if (swdbcs)
            	continue;
            swdbcs=1;
//          cvlen=(ULONG)pci-(ULONG)pcisbcs;                       //~v6hhR~
//          cvlen=(ULPTR)pci-(ULPTR)pcisbcs;                       //~v6hhI~//~v6BkR~
            cvlen=PTRDIFF(pci,pcisbcs);                            //~v6BkI~
            if (cvlen)	//sbcs before DBCS
            {
                pcdsbcs=UTF_PC2PCD(Pdbcs,pcisbcs,Pdata);
//              rc2=ucvebc3_b2mSbcs(Popt,pcisbcs,pcdsbcs,cvlen,pco,resleno,&mblen);//~v68bR~
//              rc2=ucvebc3_b2mSbcs(Popt,pcisbcs,pcdsbcs,cvlen,pco,pcdo,resleno,&mblen);//~v68bI~//~v69cR~
                rc2=ucvebc3_b2mSbcs(Popt,Phandle,pcisbcs,pcdsbcs,cvlen,pco,pcdo,resleno,&mblen);//~v69cI~
                if (rc2>4) //buff ovf
                {
                    rc=rc2;
                    break;
                }
            	rc|=rc2;    //cverr                                //~v66qI~
//              pcdos=UTF_PC2PCD(Pdbcs,pco,Poutbuff);              //~v68bR~
//              if (pcdos!=pcdsbcs)                                //~v68bR~
//              	memcpy(pcdos,pcdsbcs,(UINT)mblen);             //~v68bR~
                pco+=mblen;
                resleno-=mblen;
//              pcdo+=mblen;                                       //~v68bI~
            }
            pcidbcs=pci;
        }
        else
    	if (dbcsid==UDBCSCHK_DBCS2ND)
        {
        	if (swdbcs)
	            continue;
          if (swsetf2lerr)                                         //~0508I~
          {                                                        //~v688I~
//          *pcd=UDBCSCHK_F2LERR;                                  //~v688R~
            *pcdo=UDBCSCHK_F2LERR;                                 //~v688I~
          }                                                        //~v688I~
        }
        else	//SBCS or ASCII
        {
        	if (!swdbcs)
            	continue;
//end of dbcs str
            swdbcs=0;
//          cvlen=(ULONG)pci-(ULONG)pcidbcs;                       //~v6hhR~
//          cvlen=(ULPTR)pci-(ULPTR)pcidbcs;                       //~v6hhI~//~v6BkR~
            cvlen=PTRDIFF(pci,pcidbcs);                            //~v6BkI~
            pcddbcs=UTF_PC2PCD(Pdbcs,pcidbcs,Pdata);
//			rc2=ucvebc3_b2mDbcsstr(Popt,pcidbcs,pcddbcs,cvlen,pco,resleno,&mblen);//~v68bR~
//			rc2=ucvebc3_b2mDbcsstr(Popt,pcidbcs,pcddbcs,cvlen,pco,pcdo,resleno,&mblen);//~v68bI~//~v69cR~
  			rc2=ucvebc3_b2mDbcsstr(Popt,Phandle,pcidbcs,pcddbcs,cvlen,pco,pcdo,resleno,&mblen);//~v69cI~
	        if (rc2>4)	//buff ovf
    	    {
        		rc=rc2;
        		break;
        	}
            rc|=rc2;    //cverr                                    //~v66qI~
//          pcdos=UTF_PC2PCD(Pdbcs,pco,Poutbuff);                  //~v68bR~
//        if (Popt & UCVEBC3O_DROPSOSI                             //~v689I~//~v688R~
          if (swdropsosi                                           //~v688I~
          &&  pcidbcs>Pdata && *(pcidbcs-1)==CHAR_SO               //~v689I~
          )                                                        //~v689I~
          {                                                        //~v689I~
//        	pcdos--;                                               //~v68bR~
            memcpy(pco-1,pco,(UINT)mblen);                         //~v689I~
            pco+=mblen-1;                                          //~v689I~
            memcpy(pcdo-1,pcdo,(UINT)mblen);	//shift also dbcstbl//~v68mI~
            resleno-=(mblen-1);                                    //~v689I~
            pcisbcs=pci;                                           //~v689I~
            if (*pci==CHAR_SI)                                     //~v689I~
	            pcisbcs++;                                         //~v689I~
          }                                                        //~v689I~
          else                                                     //~v689I~
          {                                                        //~v689I~
            pco+=mblen;
            resleno-=mblen;
            pcisbcs=pci;
          }                                                        //~v689I~
//          if (pcdos!=pcddbcs)                                    //~v68bR~
//              memcpy(pcdos,pcddbcs,(UINT)mblen);                 //~v68bR~
        }
    }
//  mblen=(int)((ULONG)pco-(ULONG)Poutbuff);                       //~v6hhR~
    mblen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                       //~v6hhI~
  }                                                                //~0428I~
    if (Ppoutlen)
        *Ppoutlen=mblen;
UTRACED("ucvebc3 b2m  output data",Poutbuff,mblen);
UTRACED("ucvebc3 b2m  output dbcs",Poutdbcs,mblen);                //~v68bR~
UTRACEP("ucvebc3 rc=%d\n",rc);
    return rc;
}//ucvebc3_b2m
//****************************************************************
//*setdbcstbl by SO/SI at init
//TAB 0x09 data is not tab, fldedit tab insert set spacr and dbcstbl as usual
//rc:1:dbcs detected
//****************************************************************
//int ucvebc3_setdbcstbl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~v69cR~
int ucvebc3_setdbcstbl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~v69cI~
{
	int lend,swdbcsenv,ch,rc=0;
	UCHAR *pc,*pcd,*pcdso,/**pcdo,*/*pcdw,*pce;                    //~v6b9R~
#ifdef AAA
	int swtabkeep;
#endif
//*****************
UTRACEP("ucvebc3_setdbcstbl opt=%x,handle=%d\n",Popt,Phandle);     //~v69cR~
UTRACED("ucvebc3_setdbcstbl inp data",Pdata,Plen);                 //~v69cI~
#ifdef AAA
	swtabkeep=Popt & UCVEBC3O_TABKEEP;
#endif
//  memset(Pdbcs,0,Plen);                                          //~0423I~//~v6BkR~
    memset(Pdbcs,0,(size_t)Plen);                                  //~v6BkI~
	pc=Pdata;
	pcd=Pdbcs;
    pce=pc+Plen;
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v69cR~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~v69cI~
	for(/*pcdo=pcd,*/pcdso=0;pc<pce;pc++,pcd++)                    //~v6b9R~
    {
    	ch=*pc;
		if (ch==CHAR_SO && swdbcsenv)
        	pcdso=pcd+1;	//last SO
        else
		if (ch==CHAR_SI)
        {
			if (pcdso)
            {
//              lend=(ULONG)pcd-(ULONG)pcdso;     //DBCSlen        //~v6hhR~
//              lend=(ULPTR)pcd-(ULPTR)pcdso;     //DBCSlen        //~v6hhI~//~v6BkR~
                lend=PTRDIFF(pcd,pcdso);     //DBCSlen             //~v6BkI~
                if (!(lend & 1))    //odd number is invalid
                {
                    for (pcdw=pcdso;pcdw<pcd;)
                        *pcdw++=UDBCSCHK_DBCS1ST,*pcdw++=UDBCSCHK_DBCS2ND;
                    rc|=1;
                }
	            pcdso=0;    //start of sbcs
            }
        }
#ifdef AAA
        if (!swtabkeep||(*pcd!=UDBCSCHK_TABCHAR && *pcd!=UDBCSCHK_TABPADCHAR))
        	*pcd=0;
#endif
    }
UTRACED("ucvebc3_setdbcstbl out dbcs",Pdbcs,Plen);
	return 1;
}//ucvebc3_setdbcstbl
#ifdef AAA                                                         //~v66CI~
//**************************************************************** //~v66cI~
//*set dbcs errrep for b2l/l2b  trans err if dbcs available        //~v66cI~
//*ret ebc/locale/ucs                                              //~v66cI~
//**************************************************************** //~v66cI~
int ucvebc_getsubchar_dbcs(int Popt)                               //~v66cI~
{                                                                  //~v66cI~
	static int Sinitsw=0;                                          //~v66cI~
	static int Srepchdbcs[3];     //locale,ucs,ebc                 //~v66cI~
    UCHAR wklc[MAX_MBCSLEN];                                       //~v66cI~
    UCHAR wkebc[MAX_MBCSLEN];                                      //~v66cI~
    int opt,outlen;                                                //~v66cR~
//*************                                                    //~v66cI~
	if (!Sinitsw)                                                  //~v66cI~
    {                                                              //~v66cI~
    	Sinitsw=1;                                                 //~v66cI~
		Srepchdbcs[UCVEBCGSCDO_UCS]=utf_setsubchar_dbcs(0,wklc);   //~v66cR~
        Srepchdbcs[UCVEBCGSCDO_LC]=UTF_GETUCSBESTR(wklc);          //~v66cR~
        opt=0;                                                     //~v66cI~
		if (ucvebc3_u2b1(opt,(WUCS)Srepchdbcs[UCVEBCGSCDO_UCS],wkebc,&outlen))//~v66cR~
        	Srepchdbcs[UCVEBCGSCDO_EBC]=CHAR_EBC_ERR_DBCS;     //0x4040//~v66cR~
        else                                                       //~v66cI~
        	Srepchdbcs[UCVEBCGSCDO_EBC]=UTF_GETUCSBESTR(wkebc);    //~v66cR~
        UTRACEP("ebcsubchardbcs=%x,ucs=%x,ebc=%x\n",Srepchdbcs[0],Srepchdbcs[1],Srepchdbcs[2]);//~v66cI~
    }                                                              //~v66cI~
	return Srepchdbcs[Popt&0x03];                                  //~v66cI~
}//ucvebc_getsubchar_dbcs                                          //~v66cI~
#endif                                                             //~v66CI~
//************************************                             //~v6bjR~
//*flag trans EBC2ASC_xx to UCVEBC3O_xx                            //~v6bjR~
//************************************                             //~v6bjR~
int ucvebc3_getebc3opt(int Pebcopt)                                //~v6bjR~
{                                                                  //~v6bjR~
	int opt=0;                                                     //~v6bjR~
//*****************                                                //~v6bjR~
    if (Pebcopt & EBC2ASC_CTL)  //default ctl char conv         //~v51MI~//~v6bjR~
        opt|=UCVEBC3O_CVCTL;                                       //~v6bjR~
    if (!(Pebcopt & EBC2ASC_DBCS))	//UCEGCOO_FORCESBCS by "SBCS" option//~v6bjR~
        opt|=UCVEBC3O_SBCS;                                        //~v6bjR~
    if (Pebcopt & EBC2ASC_A2E)	//M2B                              //~v6bjR~
    {                                                              //~v6bjR~
    	if (Pebcopt & EBC2ASC_SOSIOS) //M2B;rep if space(a2e)      //~v6bjR~
        	opt|=UCVEBC3O_SOSIREP;    //rep boundary space         //~v6bjR~
        else                                                       //~v6bjR~
	    if (Pebcopt & EBC2ASC_SOSISHIFT)//SOSIOS and del followed space rep//~v6bjR~
    	    opt|=UCVEBC3O_SOSISHIFT;    //rep boundary space and shrink space by incresed length//~v6bjR~
        else                                                       //~v6bjR~
        	opt|=UCVEBC3O_SOSIINS;                                 //~v6bjR~
    }                                                              //~v6bjR~
    else						//B2M                              //~v6bjR~
    {                                                              //~v6bjR~
	    if (Pebcopt & EBC2ASC_SOSID)  //B2Mdelete SOSI            //~v58UI~//~v6bjR~
    	    opt|=UCVEBC3O_DROPSOSI;                                //~v6bjR~
        else                                                       //~v6bjR~
	        opt|=UCVEBC3O_SOSI2SPACE;                              //~v6bjR~
    }                                                              //~v6bjR~
    return opt;                                                    //~v6bjR~
}//getebc3opt                                                      //~v6bjR~
//**************************************************************** //~v6bjR~
//ucvebc3_b2f                                                      //~v6bjR~
//*translate ebc->utf8                                             //~v6bjR~
//rc:UALLOC_FAILED,4:other err                                     //~v6bjR~
//**************************************************************** //~v6bjR~
int ucvebc3_b2f(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutdata,UCHAR *Poutdbcs,int Pbuffsz,int *Ppoutlen)//~v6bjR~
{                                                                  //~v6bjR~
	int rc,opt,outlen;                                             //~v6bjR~
//*****************                                                //~v6bjR~
    opt=ucvebc3_getebc3opt(Pebcopt);                               //~v6bjR~
    opt|=UCVEBC3O_ERRREP|UCVEBC3O_B2F|UCVEBC3O_SOSICMDO/*override cfg*/;//~v6bjR~
    opt|=Popt;                                                     //~v6bjI~
    rc=ucvebc3_b2dd(opt,Phandle,Pdata,Plen,Poutdata,Poutdbcs/*maybe null*/,Pbuffsz,&outlen);//~v6bjR~
    *Ppoutlen=outlen;                                              //~v6bjR~
UTRACED("xeebc_b2f inp data",Pdata,Plen);                          //~v6bjR~
UTRACED("xeebc_b2f out u8",Poutdata,outlen);                       //~v6bjR~
	return rc;                                                     //~v6bjR~
}//ucvebc3_b2f                                                     //~v6bjR~
//**************************************************************** //~v6bjI~
//ucvebc3_f2b                                                      //~v6bjI~
//*translate ebc<-utf8                                             //~v6bjI~
//rc:UALLOC_FAILED,4:other err                                     //~v6bjI~
//**************************************************************** //~v6bjI~
int ucvebc3_f2bcmd(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutdata,UCHAR *Poutdbcs,int Pbuffsz,int *Ppoutlen)//~v6bjI~
{                                                                  //~v6bjI~
	int rc,ebc3opt,outlen;                                         //~v6bjR~
//*****************                                                //~v6bjI~
	ebc3opt=ucvebc3_getebc3opt(Pebcopt);                           //~vaacR~//~v6bjI~
    ebc3opt|=UCVEBC3O_ERRREP|UCVEBC3O_SOSICMDO/*override cfg*/;    //~vaacR~//~v6bjI~
    rc=ucvebc3_f2b(ebc3opt,Phandle,Pdata,Plen,Poutdata,Poutdbcs,Pbuffsz,&outlen);//~vaacR~//~v6bjI~
    *Ppoutlen=outlen;                                              //~v6bjI~
UTRACED("xeebc_f2bcmd inp data",Pdata,Plen);                       //~v6bjI~
UTRACED("xeebc_f2bcmd out ebbc",Poutdata,outlen);                  //~v6bjI~
	return rc;                                                     //~v6bjI~
}//ucvebc3_b2fcmd                                                  //~v6bjI~
