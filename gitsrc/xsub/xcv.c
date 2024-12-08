//*CID://+v7DuR~:                             update#=  975;       //+v7DuR~
//***********************************************************
//* xcv: convert (S)JIS <-->EUC,UCS2,UTF8,EBC                      //~va2oR~
//***********************************************************
//v7dU:241121 (Bug)xcv crash when /mcp037 is specified because Sebc2asc037 is null//~v7DuI~
//vatc:241121 xcv1.24:correct /? msg                               //~vatcI~
//vbBu:241119 Edit/Browse /Mz option for ebc file to accept 0x0d15 as EOL//~vbBuI~
//vbBs:241114 del vbB9(process cp931(cp300+cp037)) because m2b from sjis generates 0e0f dbcs word for byte of sjis 1st byte whichi is byte of iso-8859.//~vbBsI~
//vata:241026 xcv1.24:add option /mcp037                           //~vataI~
//vat3:241009 b2m accept cpxxx of when no cfg file                 //~vat3I~
//vbBh:241009 vbB3 but, revive k2l/l2k even if not round-trip conversion//~vbBhI~
//vat1:240928 xcv:icudata= option as alternative of icu            //~vat1I~
//vat0:240923 xcv:msg for /mf openerr of workdir spec              //~vat0I~
//vbB3:240815 (Bug)l2k/k2l miss to translate. char such as katakana-so(x75 on cp1027, x90 on cp290. but x90 on cp1027 is unprintable, cannot find reverse char)//~vbB3I~
//vasu:240702 xcv:help missing for option i of -Y/N for test       //~vasuI~
//vast:240627 xcv:read by fget for pipe with Yh(hex input)         //~vastI~
//vasn:240627 /yh(hex input) is stdin only                         //~vasnI~
//vasm:240627 xcv;write eol to stdout if input:stdin               //~vasmI~
//vask:240615 xcv;flush required whe -yq(expected close was not effective)//~vaskI~
//vasj:240406 xcv;(BUG)read err by stdinX is effective for other than ucs/utf//~vasjI~
//vasi:240406 xcv;use big-endian output for stdin                  //~vasiI~
//vasg:240312 xcv;warning missing /Y4 for ucs4 v1.23 new           //~vasgI~
//vasb:240123 xcv;input ucs4 by 3 byte ucs(stdin) cause conv err   //~vasbI~
//vasa:240123 xcv;change hex input option when stdin               //~vasaI~
//vas9:240115 xcv;(Bug)dup err of input when xcv - outfile         //~vas9I~
//vas8:240115 xcv;supporthex code input for stdin by /Yx           //~vas8I~
//vas5:230709 do not beep for help                                 //~vas5I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vas2:230630 errmag issued if /ICU is after /[cvType]or /list option//~vas2I~
//vag0:170825 xcv v1.20:create ebc mapfile if dll version was gotten by "uconv --version"//~vag0I~
//vaa2:160424 Lnx64 compiler warning(FDATE/FTIME)                  //~vaa2I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//va9w:160227 LNX compiler warning                                 //~va9wI~
//va97:140908 xcv v1.19 /List option rejected if with /ICU         //~va97R~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va63:120420 xcv:1.18 M2M by ICU, -Yi(default for Axe)to use ICU as local converter for test Axe on Linux//~va63R~
//va61:120121 xcv:1.17 sbcs map overflow;there is no need to create sbscmap for scv(too heavy init process after when added to call wcinit())//~va61I~
//va59:111222 xcv -List option to list icu converter(Linux) or Windows codepage//~va59I~
//va57:111214 xcv:1.16 -ICU option to use icu for B2x/x2B(x:B/M/F) to ommit -mf:mapfile//~va57I~
//va56:111213 xcv:1.16 (BUG)iconv B2B ; no dbcs processing if cfg codepage is dbcs//~va56I~
//va55:111212 xcv:1.16 F2B/B2F support                             //~va59R~
//va54:111210 xcv:1.16 Error msg if mapfile parm missing,b2b may fail because dll sufix,api version is not gotten//~va54I~
//va53:111208 xcv:1.16 ulib support uconv --list when invalid cp   //~va53I~
//va4q:100902 xcv:1.15 add "B2B" option; codepage by -f: and -t:b  //~va4qR~
//va4p:100902 xcv:1.15 add "CPEB:ebc-codepage" option for b2m/m2b  //~va4pI~//~va4qR~
//va4n:100715 xcv:1.14 (BUG)eolid was ignored for F2x(UTF8 file is not binary)//~va4nI~
//va4m:100715 xcv:1.14 allow SOSI option to override cfg option    //~va4mI~
//va4k:100715 xcv:1.14 (BUG)EOL was dropped for not EBC2x trans    //~va4kI~
//va4j:100715 xcv:1.13 specify EBC file EOLID by ASCEOL or EBCEOL for Read(B2x)/Write(x2B), default is EBCEOL.//~va4jI~
//                     SETEOL is used to change input record mode to output line mode.//~va4jI~
//va4i:100527 xcv:1.13 no eol trans ehen seteol option and not recordmode//~va4hI~
//va4h:100527 xcv:1.13 B2E/E2B support(EBCDIC<-->EUC)              //~va4hI~
//va47:080913 xcv.c v1.12:accept "UTF8" for T: F: for windows      //~va47I~
//va46:080826 xcv.c v1.12:accept errch for m2b/b2m                 //~va46I~
//va42:080826 xcv.c v1.12:m2m support                              //~va42I~
//va41:080821 xcv.c v1.12:UTF8SUPP-->WCSUPP                        //~va41I~
//va40:080821 xcv.c v1.12:fix LRECL support for B2x                //~va40I~
//va3z:080821 xcv.c v1.12:SETEOL option to write EOL for x2B       //~va3zR~
//va3y:080819 xcv.c v1.12:b2m/m2b(EBCDIC<->LOCAL) support          //~va3yI~
//va3w:080624 xcv.c v1.11:/Ss option(shift SO/SI for S2E)          //~va3wI~
//va3t:080131 xcv.c v1.10 (W32) compile err                        //~va3tI~
//va3m:080126 xcv v1.10 helpmsg for -l option,rc chk for iconv open//~va3mI~
//va3i:071224 (UTF)xcv: v1.9 mb<->utf conversion support           //~va3iI~
//va3h:071119 xcv: v1.8 euc<->utf conversion support               //~va3hI~
//va2o:061123 xcv:1.7 add B2A/A2B EBC<=>ASCII(NO DBCS)             //~va2oI~
//va2f:060321 xcv:1.6 support \u for s2u(output ucs by \uxxxx fmt) //~va2fI~
//va25:050421 xcv:v1.5:ebcdic<-->sjis:CP290 option                 //~va25I~
//va1x:041030 xcv:v1.5:ebcdic<-->sjis:CP290 option                 //~va1xI~
//va1w:041030 xcv:v1.5:(BUG)ebcdic<-->sjis:err char should be EBC for s2b//~va1wI~
//va1v:041030 xcv:v1.5:ebcdic<-->sjis:accept bot -sbcs and -msbcs  //~va1vI~
//va1u:041026 xcv:v1.5:ebcdic<-->sjis:print also SBCS chklist      //~va1uI~
//va1t:041026 xcv:v1.5:ebcdic<-->sjis(DBCS support);change conv type name a2e-->s2b e2a-->b2s//~va1tI~
//va1s:041026 xcv:v1.5:ebcdic<-->sjis(DBCS support);sbcs option(no dbcs conversion) /Msbcs//~va1sI~
//va1r:041026 xcv:v1.5:ebcdic<-->sjis(DBCS support);option to asume SO at top of line//~va1rI~
//va1q:041023 xcv:v1.5:ebcdic<-->sjis(DBCS support);del SOSI option:rep any//~va1qI~
//va1p:041023 xcv:v1.5:ebcdic<-->sjis(DBCS support);SOSI del/rep/ins option//~va1pI~
//va1n:041023 xcv:v1.5:ebcdic<-->sjis(DBCS support);dbcs repchar option//~va1nI~
//va1m:041022 xcv:v1.5:ebcdic<-->sjis(DBCS support)                //~va1mI~
//*va1c:040122 xcv:v1.4:v141:support ucs code by \uxxxx fmt        //~va1cI~
//030727 xcv v1.3 v134 ebc<-=>ascii conv                           //~v134I~
//030726 xcv v1.3 v133 hankaku katakana<-->lower case conversion support//~v133I~
//030119 xcv v132 err chk,errch is valid with u2s/f2s              //~v132I~
//030111 xcv v131 err data display                                 //~v131I~
//030106 xcv v130 cp943,ms932 option(default is sjis for conv to ucs,all for conv from ucs)//~v130R~
//030102 xcv v129 hex errch notation                               //~v129I~
//021231 xcv v128 err callback func parm                           //~v128I~
//021231 xcv v127 type parm fmt chng /[c]type                      //~v127I~
//021230 xcv v126 euc -->jis conv support                          //~v123I~
//021228 xcv v125 sjis-->jis conv support                          //~v125I~
//021228 xcv v124 contline support for sjjis<-->euc,jis-->sjis     //~v124I~
//021215 xcv v123 redirect pipe input support                      //~v123I~
//021215 xcv v122 mac eol support                                  //~v122I~
//021215 xcv v121 ucs2,utf8 conversion support                     //~v121I~
//020622 xcv v120 jis-->sjis,jis-->euc conv support                //~v120I~
//*020406 xcv v111 support sjis->euc(rename xe2j to xcv)           //~v111I~
//*020406 xe2j v110 v1.1 (BUG)hankaku katakana is not converted.   //~v111R~
//***********************************************************      //~v1.1I~
#define VER "V1.24"   //version                                    //~vasgR~//~vataR~
//***********************************************************
//***********************************************************

#define PGM "xcv"                                                  //~v111R~

//**********************************************/
//*r.c   : none
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX                                                         //~v142I~
    	#include <errno.h>                                         //~v121I~
#else                                                              //~v142I~
    #include <io.h>                                                //~v123I~
    #include <fcntl.h>                                             //~v123I~
#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
#else
    #define INCL_DOSFILEMGR  //DCPY_EXISTING
    #include <os2.h>
#endif
#endif                                                             //~v142I~

//*********************************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>                                                //~v122I~
#include <udbcschk.h>
#include <ufile.h>                                                 //~vaa2I~
#include <ufile5.h>                                                //~v122I~
#include <ufemsg.h>                                                //~v122I~
#include <utrace.h>                                                //~v122I~
#include <ucvucs.h>                                                //~v121I~
#include <ucvebc.h>                                                //~v133I~
#include <ucvebc2.h>                                               //~va1mI~
#include <ucvext.h>                                                //~va3yI~
#include <ucvebc4.h>                                               //~va4pI~
#include <uedit.h>                                                 //~v129I~
#include <uedit2.h>                                                //~v131I~
#include <utf.h>                                                   //~va3iI~
#include <ustring.h>                                               //~va3yI~
#include <ufile4.h>                                                //~vat1I~
#include <udos2.h>                                                 //~vat1I~
//*********************************************************************
//#define UTRACEP printf //@@@@test                                //~va53R~

#define TXTBUFFSZ  	32760                                          //~v121R~
#define EBCPRINTID 	"print"                                        //~va1mI~
#define OPTCPEB    	"CPEB"                                         //~va4pI~
#define OPTLIST    	"List"                                         //~va59I~
#define OPTICU    	"ICU"                                          //~va59I~
#define OPTICU_DATA	    "ICU_DATA"                                 //~vat1R~
//*********************************************************************
static char Spgmver[16];                                           //~v145R~
static char *Sstderrfnm;                                           //~v131I~
static char *Sfnm=0;                                               //~v111R~
static char *Sfnmo=0;                                              //~v122I~
static char *Sconvtype=0;                                          //~v130R~
static FILE *Sfhi=0;                                               //~v121R~
static FILE *Sfho=0;                                               //~v121I~
static int  Simode=0;	//input EOL mode                           //~v122I~
static int  Smiscopt=0;  //other option                            //~v133I~
static int  SswList=0;  //list option                              //~vat1I~
//#define MISC_K2L   0x01   //hankakukatakana-->lowe case            //~v133I~//~va4qR~
//#define MISC_L2K   0x02   //hankakukatakana<--lowe case            //~v133I~//~va4qR~
//#define MISC_M2M   0x04   //hankakukatakana<--lowe case            //~va42I~//~va4qR~
//static int  Sebcopt=EBC2ASC_CTL;  //ebc<-->asc conv opt          //~va1mR~
//static int  Sebcopt=EBC2ASC_CTL|EBC2ASC_DBCS;  //ebc<-->asc conv opt//~va1pR~
static int  Sebcopt=EBC2ASC_CTL|EBC2ASC_DBCS|EBC2ASC_SOSI;  //ebc<-->asc conv opt//~va1pI~
#define OOPT_LOCALICU   0x01    //ICU local converter              //~va64M~
#define OOPT_MBICU      0x02    //ICU converter for M2M            //~va64M~
#ifdef ARM                                                         //~va63I~
	static int  Sotheropt=OOPT_LOCALICU; //other option            //~va63I~
#else                                                              //~va63I~
	static int  Sotheropt=0; //other option                        //~va63R~
#endif                                                             //~va63I~
static int  Sconvopt=0;                                            //~v111I~
#define CONV_E2    0x10                                            //~v111I~
#define CONV_S2    0x20                                            //~v111I~
#define CONV_J2    0x40                                            //~v120I~
#define CONV_EBC2  0x30                                            //~v134I~
#define CONV_2E    0x01                                            //~v111I~
#define CONV_2S    0x02                                            //~v111I~
#define CONV_2J    0x04                                            //~v125I~
#define CONV_A2    0x80                                            //~v133I~
#define CONV_2A    0x08                                            //~v133I~
#define CONV_2EBC  0x03                                            //~v134I~
                                                                   //~v121I~
#define CONV_UCS   0xff00    //UCS mask                            //~v121I~
#define CONV_UCS2  0x0f00    //from UCS mask                       //~v121I~
#define CONV_2UCS  0xf000    //to UCS mask                         //~v121I~
#define CONV_U2    0x0100                                          //~v121I~
#define CONV_F2    0x0200                                          //~v121I~
#define CONV_2U    0x1000                                          //~v121I~
#define CONV_2F    0x2000                                          //~v121I~
                                                                   //~v121I~
#define CONV_E2S   (CONV_E2|CONV_2S)                               //~v111I~
#define CONV_S2E   (CONV_S2|CONV_2E)                               //~v111I~
#define CONV_J2S   (CONV_J2|CONV_2S)                               //~v120I~
#define CONV_J2E   (CONV_J2|CONV_2E)                               //~v120I~
#define CONV_S2J   (CONV_S2|CONV_2J)                               //~v125R~
#define CONV_E2J   (CONV_E2|CONV_2J)                               //~v126R~
#define CONV_A2A   (CONV_A2|CONV_2A)                               //~v133I~
#define CONV_A2E   (CONV_A2|CONV_2EBC)                             //~v134I~
#define CONV_E2A   (CONV_EBC2|CONV_2A)                             //~v134I~
                                                                   //~v121I~
#define CONV_U2S   (CONV_U2|CONV_2S)                               //~v121I~
#define CONV_S2U   (CONV_S2|CONV_2U)                               //~v121I~
#define CONV_S2F   (CONV_S2|CONV_2F)                               //~v121I~
#define CONV_F2S   (CONV_F2|CONV_2S)                               //~v121I~
#define CONV_U2F   (CONV_U2|CONV_2F)                               //~v121I~
#define CONV_F2U   (CONV_F2|CONV_2U)                               //~v121I~
                                                                   //~v121I~
static int  Shanzensw=0;                                           //~v111R~
static int  Shanzenonlysw=0;                                       //~v111I~
static int  Sbuffsz=TXTBUFFSZ;                                     //~v122I~
static int  Sbuff4sz;                                              //~v121I~
static UCHAR Serrch='?';                                           //~v129R~
#ifdef WCSUPP                                                      //~va47I~
static UCHAR Serrchm2m=0;                                          //~va42I~
#endif                                                             //~va47I~
static int  Serrchdbcs=0;                                          //~va1nI~
static int  Srbmode=0;	//read binary mode,0 if text mode          //~v121I~
static int  Sstdinsw=0;                                            //~v123I~
static int  Sstdoutsw=0;                                           //~v123I~
static LONG Sfileoffs=0;                                           //~v128I~
static LONG Soutfileoffs=0;                                        //~v128I~
#define MAXERRPRINT 10                                             //~v128I~
static int  Smaxerrctr=MAXERRPRINT;                                //~v128I~
static int  Serrctr=0;                                             //~v128R~
#ifdef UNX                                                         //~v121I~
	static ULONG Slesw=0;	//endian parm                          //~v130R~
#else                                                              //~v121I~
	static ULONG Slesw=UCVUCS_LE;	//endian parm                  //~v130R~
#endif                                                             //~v121I~
#ifdef WCSUPP                                                      //~va3yI~
	static int Sebcmbsw=0;       //for EBC<->locale conversion,parm to ucvext_getcvopt//~va3yR~
    static PUCVEXTCFG Spcfg=0;                                     //~va3yI~
#endif                                                             //~va3yI~
static int Sebclrecl=0;        //ebcdic file fixed record length   //~va41R~
static char *Sbuff,*Sbuff4;                                        //~v121R~
#ifdef WCSUPP                                                      //~va47I~
static char Scpfrom[64],Scpto[64];                                 //~va42R~
#endif                                                             //~va47I~
static int Sebchandle=-1;                                          //~va4pI~
static int stdinX=0,stdoutX=0;                                     //~vas8R~
static int parmXin=0;	//input hex parm specified                 //~vasaI~
static int swQuit=0;                                               //~vas8I~
static int swBELEparm=0;                                           //~vas8I~
static int stdoutXUpper=0;                                         //~vas8R~
static char Sebccp[MAX_CSNAMESZ];                                  //~va4pI~
static int Smapinitcall;                                           //~vataI~
//*********************************
int mainproc(void);                                                //~v145I~
void parmchk(int parmc,char *parmp[]);                             //~v145I~
void optionerr(char *Ptype,char* Pvalue);                          //~v111I~
void parmconflict(char *Popt);                                     //~v130R~
void help(void);
int xcvucsmain(void);                                              //~v121R~
int xcvtypechk(char *cptr);                                        //~v127I~
UCVUCS_FREAD  xcvfuncread;                                         //~v121I~
UCVUCS_FWRITE xcvfuncwrite;                                        //~v121I~
UCVUCS_FERR   xcvfuncerr;                                          //~v128I~
int xcvfilegetline(int Prbmode,UCHAR *Pfilename,FILE *Phfile,char *Pbuff,//~v121M~
					int Plinewidth,int *Ppoutlen);                 //~v121M~
int xcvfileputline(UCHAR *Pfilename,FILE *Phfile,char *Pbuff,int Plen);//~v121M~
void parmchk0(int parmc,char *parmp[]);                            //~va63I~
void mapinitcallPrint(void);                                       //~vataR~
#ifdef WCSUPP                                                      //~va3yI~
//*********************************************************************//~va3yI~
//*ebcdic trans by external converter                              //~va3yI~
//*********************************************************************//~va3yI~
int extconv(char *Pinpfile,char *Poutfile)                         //~va3yI~
{                                                                  //~va3yI~
    int ebcopt,len,rc,errch;                                       //~va46R~
    char *outfnm;                                                  //~va42I~
    int errmbstrlen;                                               //~va4pI~
    char errmbstr[MAX_MBCSLEN];                                    //~va4pI~
//*****************************                                    //~va3yI~
    if (Sstdoutsw)      //stdout output                            //~va42I~
        outfnm=0;                                                  //~va42I~
    else                                                           //~va42I~
        outfnm=Poutfile;                                           //~va42I~
    UTRACEP("%s:UCECflag=0x%08x\n",UTT,Spcfg->UCECflag);           //~vat3I~
//  if (Spcfg->UCECflag & UCECF_OPENERR)  //cfg file did not defined converter=0 or cfg not found//~vat3R~
//  {                                                              //~vat3R~
//    ebcopt=Sebcopt;                                              //~vat3R~
//    uerrmsg("Warning:Without %cMF option, use converter:%s",0,   //~vat3R~
//            CMDFLAG_PREFIX,ucvebc4_getcvname(0,0/*Phandle*/));   //~vat3R~
//  }                                                              //~vat3R~
//  else                                                           //~vat3R~
//  if (!(Spcfg->UCECflag & UCECF_USE_CONVERTER))     //cfg file did not defined converter=0 or cfg not found//~vat3R~
//  {                                                              //~vat3R~
//    ebcopt=Sebcopt;                                              //~vat3R~
//    uerrmsg("Warning:\"CONVERTER 0\" by cfg file,use converter:%s",0,//~vat3R~
//                ucvebc4_getcvname(0,0/*Phandle*/));              //~vat3R~
//  }                                                              //~vat3R~
//  else                                                           //~vat3R~
    ebcopt=Sebcopt|EBC2ASC_EXT;                                    //~va3yI~
    if (Sconvopt==CONV_A2E)                                        //~va3yR~
    	ebcopt|=EBC2ASC_A2E;                                       //~va3yI~
    UTRACEP("%s:inpfile=%s,outfile=%s,Sebcopt=0x%04x,ebcopt=%04x\n",UTT,Pinpfile,outfnm,Sebcopt,ebcopt);//~vbBhI~
    len=Sebclrecl;                                                 //~va3yM~
    errch=((Serrchdbcs<<8)|Serrchm2m);                             //~va46I~
	ucvext_getcvoption(Sebcmbsw,Spcfg,&ebcopt);                    //~va3yI~
  if (Sebchandle>0)                                                //~va4pR~
  {                                                                //~va4pI~
    Smiscopt|=MISC_HANDLE;                                         //~va4pI~
    if (Sconvopt==CONV_A2E)                                        //~va4pI~
    {                                                              //~va4pI~
    	if (!(errch & 0xff))                                       //~va4pI~
    		errch|=UCVEBCH_subcharebcsbcs(Sebchandle);             //~va4pI~
    	if (!(errch & 0xffff00))                                   //~va4pI~
    		errch|=UBESTR2US(UCVEBCH_subcharebcdbcs(Sebchandle))<<8;//~va4pR~
//    	rc=ucvext_icumb2ebcf(ebcopt,Smiscopt,(ULONG*)(ULONG)Sebchandle,Pinpfile,len,outfnm,errch);//~va4pR~//~va66R~
    	rc=ucvext_icumb2ebcf(ebcopt,Smiscopt,(ULPTR*)(ULPTR)Sebchandle,Pinpfile,len,outfnm,errch);//~va66I~
    }                                                              //~va4pI~
    else                                                           //~va4pI~
    {                                                              //~va4pI~
    	if (!(errch & 0xff))                                       //~va4pI~
    		errch|='?';                                            //~va4pI~
    	if (!(errch & 0xffff00))                                   //~va4pI~
        {                                                          //~va4pI~
        	if (utfcvu2lany1mb(0,UCVEBCH_subchardbcs(Sebchandle),errmbstr,&errmbstrlen))//~va4pR~
    			errch|=(('?'<<8)|'?')<<8;                          //~va4pI~
            else                                                   //~va4pI~
    			errch|=UBESTR2US(errmbstr)<<8;                     //~va4pR~
        }                                                          //~va4pI~
//    	rc=ucvext_icuebc2mbf(ebcopt,Smiscopt,(ULONG*)(ULONG)Sebchandle,Pinpfile,len,outfnm,errch);//~va4pR~//~va66R~
    	rc=ucvext_icuebc2mbf(ebcopt,Smiscopt,(ULPTR*)(ULPTR)Sebchandle,Pinpfile,len,outfnm,errch);//~va66I~
    }                                                              //~va4pI~
  }                                                                //~va4pI~
  else                                                             //~va4pI~
  {                                                                //~va4pI~
    if (Sconvopt==CONV_A2E)                                        //~va3yR~
//  	rc=ucvext_icumb2ebcf(ebcopt,0/*converter*/,Pinpfile,len,outfnm,errch);//~va46R~//~va4jR~
    	rc=ucvext_icumb2ebcf(ebcopt,Smiscopt,0/*converter*/,Pinpfile,len,outfnm,errch);//~va4jI~
    else                                                           //~va3yI~
//  	rc=ucvext_icuebc2mbf(ebcopt,0/*converter*/,Pinpfile,len,outfnm,errch);//~va46R~//~va4jR~
    	rc=ucvext_icuebc2mbf(ebcopt,Smiscopt,0/*converter*/,Pinpfile,len,outfnm,errch);//~va4jI~
  }                                                                //~va4pI~
    return rc;                                                     //~va3yI~
}//extconv                                                         //~va3yI~
//*********************************************************************//~va42I~
//*ebcdic trans by any to any                                      //~va42I~
//*********************************************************************//~va42I~
int extconva2a(char *Pinpfile,char *Poutfile)                      //~va42I~
{                                                                  //~va42I~
    int ebcopt,len,rc,errch;                                       //~va42I~
    char *outfnm;                                                  //~va42I~
//*****************************                                    //~va42I~
    ebcopt=Sebcopt|EBC2ASC_WINCPLIST;	//list installed codepage when codepage err//~va42I~
    len=Sebclrecl;                                                 //~va42I~
    errch=((Serrchdbcs<<8)|Serrchm2m);                             //~va42R~
    if (Sstdoutsw)      //stdout output                            //~va42I~
        outfnm=0;                                                  //~va42I~
    else                                                           //~va42I~
        outfnm=Poutfile;                                           //~va42I~
    if (Smiscopt & MISC_B2B)                                       //~va4qI~
        ebcopt|=UCVEXTO_B2B;                                       //~va4qI~
    if (Sotheropt & OOPT_MBICU)                                    //~va63I~
    	ebcopt|=UCVEXTO_MBICU;	//M2M by ICU                       //~va63I~
	rc=ucvext_iconva2af(ebcopt,Scpfrom,Scpto,Pinpfile,len,outfnm,errch);//~va42R~
	UTRACEP("extconva2a rc=%d\n",rc);                              //~va53I~
    return rc;                                                     //~va42I~
}//extconva2a                                                         //~va42I~//~va4hR~
#endif                                                             //~va3yI~
//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int rc;
    FILE *fhstde;                                                  //~v131I~
    int opt;                                                       //~va61I~
//**********************
    Gucvebc_stat|=UCVEBCS_xcv;          //on xcv    process  to ucvext_mapinit//~va54I~
	sprintf(Spgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);
#ifdef TRACE                                                       //~va59I~
    utrace_init("xcv.trc",1);                                      //~va59M~
#endif                                                             //~va59M~
	parmchk0(parmc,parmp);	//get -Yi option                       //~va63I~
//#ifdef UTF8SUPP                                                  //~va41R~
#ifdef WCSUPP                                                      //~va41I~
//  utf_init(0);  	//set utf8 option by environment               //~va47R~
//  udbcschk_wcinit(0,0);                                          //~va47R~//~va61R~
	opt=UDCWCIO_INTERNAL;	//bypass UDBCSCHK_EXPLICIT and utfucsmapinit(0);//~va61I~
#ifdef LNX                                                         //~va63I~
    if (Sotheropt & OOPT_LOCALICU)                                 //~va63I~
    	opt|=UDCWCIO_LOCALICU;                                     //~va63I~
#endif                                                             //~va63I~
    udbcschk_wcinit(opt,0);                                        //~va6//~va63R~
#endif                                                             //~va3iM~
	uerrmsg_init(Spgmver,stderr,0);//msg to stdout                 //~v111R~
	uerrexit_init(Spgmver,stderr,0,0,0);//stdout only,no pathmsg   //~v111R~
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit
	parmchk(parmc,parmp);
    if (Sstderrfnm)                                                //~v131I~
    {                                                              //~v131I~
    	fhstde=fopen(Sstderrfnm,"w");                              //~v131R~
        if (!fhstde)                                               //~v131I~
        	uerrexit("%s openfailed",0,                            //~v131I~
            			Sstderrfnm);                               //~v131I~
		uerrmsg_init(Spgmver,fhstde,0);//msg to stdout             //~v131R~
    }                                                              //~v131I~
//*****************************
UTRACEP("ebcmbsw=%x,miscopt=%x\n",Sebcmbsw,Smiscopt);              //~va53R~
#ifdef WCSUPP                                                      //~va3yI~
  if (Sebcmbsw & UCEGCOO_CHKDBCS) // B2M/B2F/M2B/F2B translation           //~va3yR~
    rc=extconv(Sfnm,Sfnmo);                                        //~va3yR~
  else                                                             //~va3yI~
  if (Smiscopt & MISC_M2M) // M2M/B2B translation                  //~va42R~
    rc=extconva2a(Sfnm,Sfnmo);                                     //~va42I~
  else                                                             //~va42I~
#endif                                                             //~va3yI~
    rc=mainproc();                                                 //~v145R~
UTRACEP("main rc=%d\n",rc);                                        //~va53R~
//  if (!rc)                                                       //~v122R~
//  	uerrmsg("No Text converted",0);                            //~v122R~
//  else                                                           //~v122R~
		uerrmsg("\n=== %s Process completed===",0,                 //~v125R~
				Sconvtype);                                        //~v125I~
	UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~vas2I~
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
	return rc;
}//main
//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int mainproc(void)                                                 //~v145R~
{
//  FILE *fh;                                                      //~v121R~
    int dbcssw=0,len;                                              //~v145R~
    int opt=0,rc;                                                  //~v121R~
    int klopt;                                                     //~v133I~
//  char buff[TXTBUFFSZ];                                          //~v122R~
//  char buff2[TXTBUFFSZ];                                         //~v122R~
//  char buff3[TXTBUFFSZ];                                         //~v122R~
    char *buff,*buff2,*buff3;                                      //~v122I~
    int contsw,reslen,jismode=0,readlen,eofsplitsw=0;              //~v123R~
    int errch;                                                     //~va1nI~
    int outlen,ebcopt;                                             //~va3yI~
//*****************************
    UTRACEP("%s:Sconvopt=%02x,Sebcopt=%08x\n",UTT,Sconvopt,Sebcopt);//~vatcI~
//*file1
	if (Sstdinsw==1)		//"-" parm                             //~v123R~
    {                                                              //~v122I~
      if (!swQuit)                                                 //~vas8I~
        uerrmsg("input is stdin,exit by quit.",0);                 //~v125R~
      else                                                         //~vas8I~
        uerrmsg("input is stdin.",0);                              //~vas8I~
    	Sfhi=stdin;                                                //~v121R~
        Srbmode=0;       //fgets                                   //~v121R~
    }                                                              //~v122I~
    else                                                           //~v123I~
    if (Sstdinsw==2)	//pipe input                               //~v123I~
    {                                                              //~v123I~
        uerrmsg("input is stdin pipe.",0);                         //~v125R~
#ifdef UNX                                                         //~v123I~
#else                                                              //~v123I~
        rc=setmode(0,O_BINARY);                                    //~v123I~
//UTRACEP("stdin=%d,setmoderc=%x\n",Sstdinsw,rc);                  //~v131R~
#endif                                                             //~v123I~
//      Sfhi=fdopen(0,"rb");	//stdin pipe read by binary mode   //~v123R~
        Sfhi=stdin;         	//stdin pipe read by binary mode   //~v123I~
      if (stdinX)                                                  //~vastR~
        Srbmode=0;       //fgets                                   //~vastI~
      else                                                         //~vastI~
        Srbmode=1;                                                 //~v123M~
    }                                                              //~v123I~
    else                                                           //~v111I~
    {                                                              //~v122I~
#ifndef DOSDOS                                                     //~va1xI~
        UTRACEP("%s:Sfnm=%s,Sconvopt=%04x,Sebcmbsw=%02x\n",UTT,Sfnm,Sconvopt,Sebcmbsw);//~vat3I~
        if (!strcmp(Sfnm,EBCPRINTID))                              //~va1mI~
        {                                                          //~va1mI~
        	if (Sconvopt==CONV_E2A)                                //~va1mI~
            {                                                      //~va1mI~
                mapinitcallPrint();                                //~vataR~
				ucvebc2_chkprintsbcs(Sebcopt,Serrch);              //~va1uR~
              if (Sebcopt & EBC2ASC_DBCS)                          //~va1uI~
              {                                                    //~va1uI~
				ucvebc2_chkprint(Sebcopt);                         //~va1mI~
				ucvebc2_chkprintnewold(Sebcopt);                   //~va1mI~
				ucvebc2_chkprintdup(Sebcopt);                      //~va1mI~
              }                                                    //~va1uI~
            	return 0;                                          //~va1mI~
            }                                                      //~va1mI~
        	if (Sconvopt==CONV_A2E)                                //~va1mI~
            {                                                      //~va1mI~
                mapinitcallPrint();                                //~vataR~
//          	Sebcopt|=EBC2ASC_A2E;                              //~va1mI~//~va4jR~
				ucvebc2_chkprintsbcs(Sebcopt,Serrch);              //~va1uR~
              if (Sebcopt & EBC2ASC_DBCS)                          //~va1uI~
              {                                                    //~va1uI~
				ucvebc2_chkprint(Sebcopt);                         //~va1mI~
				ucvebc2_chkprintnewold(Sebcopt);                   //~va1mI~
              }                                                    //~va1wM~
            	return 0;                                          //~va1mI~
            }                                                      //~va1mI~
        }                                                          //~va1mI~
#endif                                                             //~va1xI~
//      uerrmsg("input is \"%s\".",0,                              //~v125R~//~vas8R~
//  			Sfnm);                                             //~v125I~//~vas8R~
		Sfhi=fopen(Sfnm,"rb");	//exit when open faile             //~v121R~
		UTRACEP("%s:fopen input fnm=%s\n",UTT,Sfnm);               //~vas2I~
        Srbmode=1;		//fread                                    //~v121R~
    }                                                              //~v122I~
    if (!Sfhi)                                                     //~v121R~
        uerrexit("%s open failed",0,                               //~v111R~
           		 Sfnm);                                            //~v145I~
	if (Sstdoutsw)		//stdout output                            //~v123R~
    {                                                              //~v123I~
#ifdef UNX                                                         //~v123I~
#else                                                              //~v123I~
        rc=setmode(1,O_BINARY);                                    //~v123R~
//UTRACEP("stdout=%d,setmoderc=%x\n",Sstdoutsw,rc);                //~v131R~
#endif                                                             //~v123I~
//      Sfho=fdopen(1,"wb");	//write to stdout in binary mode   //~v123R~
        Sfho=stdout;        	//write to stdout in binary mode   //~v123I~
    }                                                              //~v123I~
    else                                                           //~v122I~
    {                                                              //~vas2I~
		Sfho=fopen(Sfnmo,"wb");	//exit when open faile             //~v121R~
		UTRACEP("%s:fopen output fnm=%s\n",UTT,Sfnmo);             //~vas2I~
    }                                                              //~vas2I~
//UTRACEP("stdout=%d\n",Sstdoutsw);                                //~v131R~
    if (!Sfho)                                                     //~v121R~
    {                                                              //~vasnI~
      if (!Sfnmo || !*Sfnmo)                                       //~vasnR~
        uerrexit("output filename is null; (-o option format is -Ofnm)",//~vasnI~
                 "出力ファイルがヌルです。(-o オプションは -ofnm の形式です)");//~vasnI~
      else                                                         //~vasnI~
        uerrexit("open output(\"%s\") failed,errno=%d",0,                               //~v122I~//~vasnR~//~vastR~
           		 Sfnmo,errno);                                           //~v122I~//~vastR~
    }                                                              //~vasnI~
    UTRACEP("%s:call ufgetsinit Simode=x%04x\n",UTT,Simode);       //~vbBuI~
    ufgetsinit(Simode,0,0,0);                                      //~v122R~
    Sbuff=umalloc((UINT)(Sbuffsz+1));                              //~v129R~
    *(Sbuff+Sbuffsz)=0;	//for strlen                               //~v121I~
    Sbuff4sz=Sbuffsz<<2;  //*4 size buff                           //~v121R~
    Sbuff4=umalloc((UINT)Sbuff4sz);  //*4 size buff                //~v129R~
  if (Sconvopt & CONV_UCS)	//ucs or utf process                   //~v121I~
    rc=xcvucsmain();                                               //~v121R~
  else                                                             //~v121I~
  {                                                                //~v121I~
    if (Shanzensw)                                                 //~v111I~
        opt|=UDBCSCHK_EUCHKCONV;                                   //~v111I~
    if (Shanzenonlysw)                                             //~v111I~
        opt|=(UDBCSCHK_EUCHKCONV|UDBCSCHK_KANAONLY);               //~v111I~
    buff=Sbuff;                                                    //~v121I~
    buff2=Sbuff4;                                                  //~v121R~
//  buff3=umalloc(Sbuffsz<<1);                                     //~v125R~
    buff3=umalloc((UINT)Sbuffsz<<2);                               //~v129R~
	reslen=0;                                                      //~v124I~
//  while (fgets(buff,TXTBUFFSZ,fh))                               //~v122R~
    for (;;)                                                       //~v122I~
    {                                                              //~v145I~
//  	rc=xcvfilegetline(Srbmode,Sfnm,Sfhi,buff,Sbuffsz,&len);    //~v124R~
    	rc=xcvfilegetline(Srbmode,Sfnm,Sfhi,buff+reslen,Sbuffsz-reslen,&len);//~v124I~
        len+=reslen;                                               //~v125M~
//UTRACEP("getline jismode=%x,reslen=%d,buffsz=%d,len=%d,rc=%08x\n",jismode,reslen,Sbuffsz,len,rc);//~v131R~
//UTRACED("getline ",buff,len);                                    //~v131R~
      if (rc==UFGETS_MORE)                                         //~v124I~
      	contsw=UDBCSCHK_CONTLINE;                                  //~v124I~
      else                                                         //~v124I~
      {                                                            //~v124I~
      	contsw=0;                                                  //~v124I~
        if (rc)                                                    //~v122I~
        {                                                          //~va1cI~
          if (reslen)                                              //~v124I~
          {                                                        //~v124I~
           eofsplitsw=1;                                           //~v124I~
           len=reslen;                                             //~v124I~
          }                                                        //~v124I~
          else                                                     //~v124I~
        	break;                                                 //~v122I~
        }//rc                                                      //~va1cI~
      }                                                            //~v124I~
        readlen=len;                                               //~v124I~
//  	len=(int)strlen(buff);                                     //~v122R~
//  	len=ushift2euc(buff,len,buff2,dbcs,0);                     //~v145R~
//  	len=ueuc2shift(buff,len,buff2,dbcs,0);                     //~v1.1R~
		rc=0;                                                      //~v111I~
		switch(Sconvopt)                                           //~v111R~
        {                                                          //~v111I~
		case CONV_E2S:                                             //~v111I~
//  		rc=ueuc2shift(buff,0,len,buff2,0,&len,opt);            //~v124R~
    		rc=ueuc2shift(buff,0,len,buff2,0,&len,opt|contsw);     //~v124I~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v124I~
            	reslen=1;                                          //~v124I~
            else                                                   //~v124I~
            	reslen=0;                                          //~v124I~
            break;                                                 //~v111I~
		case CONV_S2E:                                             //~v111R~
//  		rc=ushift2euc(buff,0,len,buff2,0,&len,opt);            //~v124R~
    		rc=ushift2euc(buff,0,len,buff2,0,&len,opt|contsw);     //~v124I~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v124I~
            	reslen=1;                                          //~v124I~
            else                                                   //~v124I~
            	reslen=0;                                          //~v124I~
            break;                                                 //~v111I~
		case CONV_S2J:                                             //~v125I~
    		rc=ustrsjis2jis(opt|jismode|contsw,buff,len,buff2,&len);//~v125R~
            if (contsw)                                            //~v125I~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v125I~
            else                                                   //~v125I~
            	jismode=0;                                         //~v125I~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v125I~
            	reslen=1;                                          //~v125I~
            else                                                   //~v125I~
            	reslen=0;                                          //~v125I~
            break;                                                 //~v125I~
		case CONV_J2S:      //jis-->sjis                           //~v120I~
//  		rc=ustrjis2sjis(0,buff,len,buff2,&len);                //~v124R~
    		rc=ustrjis2sjis(jismode|contsw,buff,len,buff2,&len);   //~v124R~
            if (contsw)                                            //~v124I~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v124I~
            else                                                   //~v124I~
            	jismode=0;                                         //~v124I~
            reslen=(int)((ULONG)(rc & UDBCSCHK_RC_JISSPLIT)>>UDBCSCHK_RC_JISSPLITSHIFT);  //last dbcssplit//~v131R~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v124I~
            	reslen=1;       //jissplit and dbcssplit is excusive//~v124I~
            if ((opt & UDBCSCHK_EUCHKCONV) && (rc & UDBCSCHK_RC_HANKANAFOUND))//~v120I~
            {                                                      //~v120I~
				rc=ushift2euc(buff2,0,len,buff3,0,&len,opt|UDBCSCHK_KANAONLY);//~v120I~
                memcpy(buff2,buff3,(UINT)len);                     //~v120I~
            }                                                      //~v120I~
            break;                                                 //~v120I~
		case CONV_J2E:      //jis-->euc                            //~v120I~
//  		rc=ustrjis2sjis(0,buff,len,buff2,&len);                //~v124R~
    		rc=ustrjis2sjis(jismode|contsw,buff,len,buff2,&len);   //~v124R~
            if (contsw)                                            //~v124I~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v124I~
            else                                                   //~v124I~
            	jismode=0;                                         //~v124I~
            reslen=(int)((ULONG)(rc & UDBCSCHK_RC_JISSPLIT)>>UDBCSCHK_RC_JISSPLITSHIFT);  //last dbcssplit//~v131R~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v124I~
            	reslen=1;                                          //~v124I~
        	if (rc & (UDBCSCHK_RC_DBCSFOUND|UDBCSCHK_RC_HANKANAFOUND))//~v120I~
            {                                                      //~v120I~
				rc=ushift2euc(buff2,0,len,buff3,0,&len,opt);       //~v120I~
                memcpy(buff2,buff3,(UINT)len);                     //~v120I~
            }                                                      //~v120I~
            break;                                                 //~v120I~
		case CONV_E2J:      //jis-->euc                            //~v123I~
    		rc=ueuc2shift(buff,0,len,buff2,0,&len,opt|contsw);     //~v126R~
//UTRACED("e->s",buff2,len);                                       //~v131R~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v126R~
            	reslen=1;                                          //~v126R~
            else                                                   //~v126R~
            	reslen=0;                                          //~v126R~
    		rc=ustrsjis2jis(jismode|contsw,buff2,len,buff3,&len);  //~v126R~
//UTRACED("s->j",buff3,len);                                       //~v131R~
            memcpy(buff2,buff3,(UINT)len);                         //~v126I~
            if (contsw)                                            //~v126R~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v126R~
            else                                                   //~v126R~
            	jismode=0;                                         //~v126R~
            break;                                                 //~v126R~
		case CONV_A2A:      //ascii--ascii                         //~v133I~
#ifdef DOSDOS                                                      //~va25I~
            uerrexit("Not supported conversion type for DOS version",0);//~va25I~
#else                                                              //~va25I~
            if (Smiscopt & MISC_K2L)   //hankakukatakana-->lowe case//~v133R~
                klopt=KANDL_K2L;                                   //~v133I~
            else                                                   //~v133I~
                klopt=0;                                           //~v133I~
    		rc=ucvkandl(klopt,buff,buff2,len);                     //~v133I~
            if (rc==KANDL_RC_DBCSSPLIT)	//last dbcssplit           //~v133I~
            	reslen=1;                                          //~v133I~
            else                                                   //~v133I~
            	reslen=0;                                          //~v133I~
            rc=0;                                                  //~v134I~
#endif                                                             //~va25I~
            break;                                                 //~v133I~
		case CONV_E2A:      //ebcdic->ascii                        //~v134I~
#ifdef DOSDOS                                                      //~va25I~
            uerrexit("Not supported conversion type for DOS version",0);//~va25I~
#else                                                              //~va25I~
            if (Sebcopt & EBC2ASC_SOSIAS)//asume SO at top of line //~va1rI~
            	Sebcopt|=EBC2ASC_SOCONT;                           //~va1rI~
            else                                                   //~va1rI~
            	Sebcopt&=~EBC2ASC_SOCONT;                          //~va1rI~
//  		ucvebc2asc(Sebcopt,buff,0,buff2,len,Serrch); 	//0:dbcs,0:rep char//~va1nR~
            errch=Serrch+(Serrchdbcs<<8);                          //~va1nR~
//          len=        //len may be reduced by SOSI del option    //~va1pR~
//  		ucvebc2asc(Sebcopt,buff,0,buff2,len,errch); 	//0:dbcs,0:rep char//~va1pR~
    		ucvebc2asc(Sebcopt,buff,0,buff2,len,errch,&len); 	//0:dbcs,0:rep char//~va1pI~
            rc=0;                                                  //~v134I~
#endif                                                             //~va25I~
            break;                                                 //~v134I~
		case CONV_A2E:      //ebcdic->ascii                        //~v134I~
#ifdef DOSDOS                                                      //~va25I~
            uerrexit("Not supported conversion type for DOS version",0);//~va25I~
#else                                                              //~va25I~
            errch=Serrch+(Serrchdbcs<<8);                          //~va1nR~
//  		ucvasc2ebc(Sebcopt,buff,0,buff2,len,Serrch); 	//0:dbcs,0:rep char//~va1nR~
//          len=        //len may expanded by SOSI isrt option     //~va1pR~
//  		ucvasc2ebc(Sebcopt,buff,0,buff2,len,errch); 	//0:dbcs,0:rep char//~va1pR~
//  		ucvasc2ebc(Sebcopt,buff,0,buff2,len,errch,&len); 	//0:dbcs,0:rep char//~va3yR~
    		ebcopt=Sebcopt;                                        //~va3yI~
    		outlen=Sebclrecl;                                      //~va40R~
    		ucvasc2ebc(ebcopt,buff,0,buff2,len,errch,&outlen); 	//0:dbcs,0:rep char//~va3yI~
            UTRACED("asc2ebc in",buff,len);                        //~va4jR~
            UTRACED("asc2ebc ot",buff2,outlen);                    //~va4jR~
            len=outlen;                                            //~va3yI~
            rc=0;                                                  //~v134I~
#endif                                                             //~va25I~
            break;                                                 //~v134I~
        }//Sconvopt                                                //~v111I~
        *(buff2+len)=0;                                            //~v111I~
        if (opt & UDBCSCHK_KANAONLY)                               //~v111I~
        	dbcssw=(rc & UDBCSCHK_RC_HANKANAFOUND);                //~v111I~
        else                                                       //~v111I~
        	dbcssw=(rc & UDBCSCHK_RC_DBCSFOUND)                    //~v111I~
            	   ||((opt & UDBCSCHK_EUCHKCONV) && (rc & UDBCSCHK_RC_HANKANAFOUND));//~v111I~
            dbcssw=1;                                              //~v111I~
        xcvfileputline(Sfnmo,Sfho,buff2,len);                      //~v121R~
//UTRACEP("write rc=%08x,contsw=%d,jismode=%x,reslen=%d,eofsplitsw=%d\n",rc,contsw,jismode,reslen,eofsplitsw);//~v131R~
//UTRACED("write   ",buff2,len);                                   //~v131R~
        if (eofsplitsw)                                            //~v124I~
        	break;                                                 //~v124I~
        if (reslen)                                                //~v124I~
        	memcpy(buff,buff+readlen-reslen,(UINT)reslen);         //~v123R~
		if (Sstdinsw==1 && swQuit)		                           //~vas8I~
        	break;                                                 //~vas8I~
//UTRACED("write res",buff,reslen);                                //~v131R~
    }                                                              //~v145I~
    ufree(buff3);                                                  //~v121M~
  }                                                                //~v121I~
    ufree(Sbuff);                                                  //~v121I~
    ufree(Sbuff4);                                                 //~v121R~
    if (Sfhi!=stdin)                                               //~v121R~
	    fclose(Sfhi);                                              //~v121R~
    if (Sfho!=stdout)                                              //~v121R~
	    fclose(Sfho);                                              //~v121R~
    else                                                           //~vaskR~
    	fflush(Sfho);                                              //~vaskR~
    ufgetsinit(UFGETS_TERM,0,0,0);	//free iobuff                  //~v122I~
	UTRACEP("%s:return rc=%d\n",UTT,dbcssw==1);                    //~vas2I~
	return dbcssw==1;                                              //~v145R~
}//mainproc                                                        //~v111R~
//*********************************************************************//~v121I~
//* return 0:fully equall                                          //~v121I~
//*        1:unmatch exist                                         //~v121I~
//*        4:encountered error condition                           //~v121I~
//*********************************************************************//~v121I~
int xcvucsmain(void)                                               //~v121R~
{                                                                  //~v121I~
#ifdef DOSDOS                                                      //~va2oI~
    return uerrnotsupported("UCS conversion","DOS version",4);     //~va2oR~
#else                                                              //~va2oI~
//  int rc;                                                        //~v130R~//~va53R~
    int rc=0;                                                      //~va53I~
    ULONG opt;                                                     //~v130I~
    int SswLEmsg=0;                                                //~vas8I~
//**********************************                               //~v121I~
	if (Sstdinsw==1)		//"-" parm                             //~vasaI~
    	uerrmsg("stdin input by %s",0,(stdinX?"Hex notation code":"Binary code"));//~vasaR~
    opt=Slesw|Serrch|UCVUCS_NOERRMSG;       //own err msg output   //~v128R~
	switch(Sconvopt)                                               //~v121I~
    {                                                              //~v121I~
    case CONV_F2U:                                                 //~v121I~
        if (!SswLEmsg)                                             //~vas8I~
        {                                                          //~vas8I~
        	SswLEmsg=1;                                            //~vas8I~
//          uerrmsg("Output is %s Endian ucs code",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vas8R~//~vasaR~
            uerrmsg("Output option is %s Endian.",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vasaI~
        }                                                          //~vas8I~
        opt|=UCVUCS_LENERRREP;                                     //~va4nI~
		rc=ucvfutf2ucs(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    case CONV_U2F:                                                 //~v121I~
    	if (!swBELEparm && stdinX)	//hexcode input by /Yx         //~vas8I~
//			opt &=~UCVUCS_LE;       //stdin default is BE          //~vas8I~//~vas9R~
  			opt &=(ULONG)(~UCVUCS_LE);       //stdin default is BE //~vas9I~
        if (!SswLEmsg)                                             //~vas8I~
        {                                                          //~vas8I~
        	SswLEmsg=1;                                            //~vas8I~
          if (stdinX)                                              //~vasaI~
//          uerrmsg("Input by %s Endian ucs code",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vas8R~//~vasaR~
            uerrmsg("Input option is %s Endian.",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vasaI~
        }                                                          //~vas8I~
		rc=ucvfucs2utf(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    case CONV_S2U:                                                 //~v121I~
        if (!SswLEmsg)                                             //~vas8I~
        {                                                          //~vas8I~
        	SswLEmsg=1;                                            //~vas8I~
//          uerrmsg("Output is %s Endian ucs code",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vas8R~//~vasaR~
            uerrmsg("Output option is %s Endian.",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vasaI~
        }                                                          //~vas8I~
		rc=ucvfsjis2ucs(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    case CONV_U2S:                                                 //~v121I~
    	if (!swBELEparm && stdinX)	//hexcode input by /Yx         //~vas8I~
//			opt &=~UCVUCS_LE;       //stdin default is BE          //~vas8I~//~vas9R~
  			opt &=(ULONG)(~UCVUCS_LE);       //stdin default is BE //~vas9I~
        if (!SswLEmsg)                                             //~vas8I~
        {                                                          //~vas8I~
        	SswLEmsg=1;                                            //~vas8I~
//          uerrmsg("Input by %s Endian ucs code",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vas8R~//~vasaR~
            uerrmsg("Input option is %s Endian.",0,(opt & UCVUCS_LE) ? "Little" : "Big");//~vasaI~
        }                                                          //~vas8I~
		rc=ucvfucs2sjis(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    case CONV_S2F:                                                 //~v121I~
		rc=ucvfsjis2utf(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    case CONV_F2S:                                                 //~v121I~
        opt|=UCVUCS_LENERRREP;                                     //~va4nI~
		rc=ucvfutf2sjis(xcvfuncread,xcvfuncwrite,xcvfuncerr,opt,Sbuff,Sbuffsz,Sbuff4,Sbuff4sz);//~v128R~
        break;                                                     //~v121I~
    }                                                              //~v121I~
    UTRACED("input",Sbuff,Sbuffsz);                                //~vas8I~
    UTRACED("outpt",Sbuff4,Sbuff4sz);                              //~vas8R~
    if (Serrctr)                                                   //~v128R~
        uerrmsg("\n%d error data detected.",                         //~v128R~//~vasjR~
                "\n%d 個 変換エラー。",                              //~v128R~//~vasjR~
				Serrctr);                                          //~v128I~
    return rc;                                                     //~v121I~
#endif                                                             //~va2oI~
}//xcvucsmain                                                      //~v121I~
//**************************************************************** //~v121I~
// xcvfuncread                                                     //~v121I~
//* input data read interface callback func between ucvfxxxx       //~v121I~
//*parm1:read buff                                                 //~v121I~
//*parm2:read req len                                              //~v121I~
//*parm3:output read len                                           //~v121I~
//*retrn:rc 0:ok ,8:i/o err, -1:eof                                //~v121I~
//**************************************************************** //~v121I~
int xcvfuncread(UCHAR *Pbuff,int Preqlen,int *Preadlen)            //~v121I~
{                                                                  //~v121I~
    int rc;                                                        //~v123R~
    static int readctr=0;                                          //~vas8I~
//**************************                                       //~v121I~
    if (readctr && Sstdinsw==1 && swQuit)                          //~vas8I~
        return -1; //eof                                           //~vas8I~
    readctr++;                                                     //~vas8M~
	rc=xcvfilegetline(Srbmode,Sfnm,Sfhi,Pbuff,Preqlen,Preadlen);   //~v123R~
    return rc;                                                     //~v121I~
}//xcvfuncread                                                     //~v121I~
//**************************************************************** //~vas8I~
// xcvdropLF                                                       //~vasaR~
//**************************************************************** //~vas8I~
int xcvdropLF(UCHAR *Pbuff,int Plen)                               //~vas8I~
{                                                                  //~vas8I~
	int len;                                                       //~vas8R~
    UTRACED("xinput",Pbuff,Plen);                              //~vas8I~//~vasaR~
    len=Plen;                                                      //~vas8I~
	if (Plen)                                                      //~vas8I~
    {                                                              //~vas8I~
        if (*(Pbuff+len-1)=='\n')                                  //~vas8I~
        	len--;                                                 //~vas8I~
    }                                                              //~vas8I~
    else                                                           //~vas8I~
    	uerrmsg("null stdin input",0);                             //~vas8I~
    return len;                                                    //~vas8I~
}//xcvdropLF                                                       //~vas8I~
//**************************************************************** //~vas8M~
// xcvX2S                                                          //~vas8M~
//**************************************************************** //~vas8M~
int xcvX2S(UCHAR *Pbuff,int Plen)                                  //~vas8M~
{                                                                  //~vas8M~
	int len,rc;                                                    //~vas8R~
  UTRACED("xcvX2S input",Pbuff,Plen);                              //~vas8I~
//  memcpy(Sbuff4,Pbuff,Plen);                                     //~vas8I~//~vas9R~
    memcpy(Sbuff4,Pbuff,(size_t)Plen);                             //~vas9I~
    len=Plen;                                                      //~vas8I~
	if (Plen)                                                      //~vas8M~
    {                                                              //~vas8M~
        if (*(Pbuff+len-1)=='\n')                                  //~vas8R~
        	len--;                                                 //~vas8I~
		if (len%2)                                                 //~vas8R~
        {                                                          //~vas8M~
    		len--;                                                 //~vas8R~
    		uerrmsg("odd number of hex code",0);                   //~vas8I~
        }                                                          //~vas8M~
        rc=ugethex(Sbuff4,Pbuff,len);                              //~vas8R~
	  	UTRACEP("xcvX2S rc=%d,len=%d\n",rc,len);                   //~vas8R~
        rc=-rc; //for compiler warning                             //~vasbI~
	  	UTRACED("xcvX2S ugethex",Pbuff,len);                       //~vas8I~
		if (len%2)                                                 //~vas8I~
        {                                                          //~vas8I~
//      	*(Pbuff+len++)=*(Sbuff4+len-1);                        //~vas8R~//~vas9R~
        	*(Pbuff+len)=*(Sbuff4+len-1);                          //~vas9I~
            len++;                                                 //~vas9I~
            len=len/2+1;                                           //~vas8I~
        }                                                          //~vas8I~
        else                                                       //~vas8I~
        	len/=2;                                                //~vas8I~
    }                                                              //~vas8M~
    else                                                           //~vas8M~
    	uerrmsg("null stdin input",0);                             //~vas8I~
    return len;                                                    //~vas8M~
}//xcvX2S                                                          //~vas8M~
//**************************************************************** //~vas8I~
// xcvB2X                                                          //~vas8I~
//**************************************************************** //~vas8I~
int xcvB2X(UCHAR *Pbuff,int Plen,int *Ppoutlen)                    //~vas8I~
{                                                                  //~vas8I~
	int outlen,rc,opt=0;                                           //~vas8R~
    char *buffX;                                                   //~vas8I~
    buffX=Sbuff4+Plen;                                             //~vas8I~
  UTRACED("xcvB2X input",Pbuff,Plen);                              //~vas8I~
    if (!stdoutXUpper)                                             //~vas8R~
        opt=UXDSO_LOWER;                                           //~vas8I~
	rc=uxdumpstr(opt,Pbuff,Plen,buffX,Sbuff4sz-Plen,&outlen);      //~vas8R~
  UTRACED("xcvB2X outpt",buffX,outlen);                            //~vas8R~
    if (rc)                                                        //~vas8R~
    {                                                              //~vas8I~
    	uerrmsg("binary to hex code, buffer overflow buffsz=%d\n",0,Sbuff4sz);//~vas8I~
        outlen=0;                                                  //~vas8I~
    }                                                              //~vas8I~
    else                                                           //~vas8I~
    	memcpy(Pbuff,buffX,(UINT)outlen);                          //~vas8R~
    *Ppoutlen=outlen;                                              //~vas8I~
    return rc;                                                     //~vas8I~
}//xcvB2X                                                          //~vasaR~
//**************************************************************** //~v122I~
// xcvfilegetline                                                  //~v122R~
//* 1 line get                                                     //~v122I~
//*parm1:read binary mode sw                                       //~v122I~
//*parm2:file name for err msg                                     //~v122I~
//*parm3:file handle for i/o                                       //~v122I~
//*parm4:read buff                                                 //~v122I~
//*parm5:max line width                                            //~v122I~
//*parm6:output read len                                           //~v122I~
//*retrn:rc 0:ok ,8:i/o err, -1:eof                                //~v122I~
//**************************************************************** //~v122I~
int xcvfilegetline(int Prbmode,UCHAR *Pfilename,FILE *Phfile,char *Pbuff,//~v122R~
					int Plinewidth,int *Ppoutlen)                  //~v122I~
{                                                                  //~v122I~
    int rc,eolid;                                                  //~v122R~
    UCHAR *pc;                                                     //~v122I~
    UINT len;                                                      //~v121I~
//*******4********************                                     //~v121R~
  	if (Prbmode)                                                   //~v122I~
  	{                                                              //~v122I~
      if (Sconvopt==CONV_E2A && (Sebcopt & EBC2ASC_FIXEDLRECL))         //fixed LRECL input//~va40I~
      {                                                            //~va40I~
//      len=fread(Pbuff,1,(UINT)Sebclrecl,Phfile);                 //~va47R~//~vaa1R~
        len=(UINT)fread(Pbuff,1,(UINT)Sebclrecl,Phfile);           //~vaa1I~
        if (!len)                                                  //~va40I~
        	return -1;    //EOF                                    //~va40I~
        rc=0;                                                      //~va40I~
UTRACED("EBC fixed input",Pbuff,Sebclrecl);                        //~va40I~
      }                                                            //~va40I~
      else                                                         //~va40I~
      {                                                            //~va40I~
        rc=ufgets(Pbuff,(UINT)(Plinewidth-2),Phfile,&len,&eolid);  //~v129R~
        switch (rc)     //0 or 4 is ok                             //~v122I~
        {                                                          //~v122I~
        case UFGETS_ERR:                                           //~v122I~
            ufileapierr("read by fgets",Pfilename,errno);          //~v122I~
            return 8;                                              //~v122I~
        case UFGETS_MORE:                                          //~v122R~
//          if (!(Simode & UFGETS_BIN)) //text read                //~v124R~
//              uerrexit("too long record(>%d) specify buffsize by %cbnn parm",//~v124R~
//                  "入力レコードが長すぎる(>%d)、%cbnn パラメータでバッファ長を指定してください",//~v124R~
//                   Plinewidth,CMDFLAG_PREFIX);                   //~v124R~
            break;                                                 //~v122R~
        case UFGETS_EOF:                                           //~v122I~
            return -1;      //eof                                  //~v122I~
//        default:    //normal                                     //~v122R~
        }//rc                                                      //~v123R~
        pc=Pbuff+len;                                              //~v122I~
UTRACEP("%s:req=%d,eolid=%d,len=%d\n",UTT,Plinewidth-2,eolid,len);//~v131R~//~vasnR~
UTRACED("getline",Pbuff,(int)len);                               //~v131R~//~vasnR~
//     if (Sconvopt==CONV_E2A    //EBC2ASC                           //~va4iI~//~va4jR~
//     &&  !(Sebcopt & EBC2ASC_FIXEDLRECL)    //not fixed LRECL      //~va4iI~//~va4jR~
//     &&  Sebcopt & EBC2ASC_SETEOL           //write eol            //~va4iI~//~va4jR~
//     )                                                             //~va4iI~//~va4jR~
//     if (ucvebc_chkeolopt(UCVEBCCEO_INPUTEOL,&Sebcopt,Smiscopt))	//ignore input eol//~va4jR~//~va4kR~
       if ((UBITCHKALL(Sconvopt,CONV_EBC2)||UBITCHKALL(Sconvopt,CONV_2EBC))//~va4kI~
       && (ucvebc_chkeolopt(UCVEBCCEO_INPUTEOL,&Sebcopt,Smiscopt))	//ignore input eol//~va4kI~
       )                                                           //~va4kI~
          ;                                                          //~va4iI~
       else                                                          //~va4iI~
        switch(eolid)                                              //~v122I~
        {                                                          //~v122I~
        case 1: //0a                                               //~v122I~
            len++;                                                 //~v122I~
            *pc=0x0a;                                              //~v122I~
            break;                                                 //~v122I~
        case 2: //0d0a                                             //~v122I~
            *pc++=0x0d;                                            //~v122I~
            *pc=0x0a;                                              //~v122I~
            len+=2;                                                //~v122I~
            break;                                                 //~v122I~
        case 4: //0d                                               //~v122I~
            *pc=0x0d;                                              //~v122I~
            len++;                                                 //~v122I~
            break;                                                 //~v122I~
        }//eolid                                                   //~v122I~
      }//!(fixed LRECL ebcdic)                                     //~va40I~
    }                                                              //~v122I~
    else  //text mode read                                         //~v122I~
    {                                                              //~v122I~
    	rc=0;                                                      //~v124I~
        *(Pbuff+Plinewidth-1)=0;	//for strlen                   //~v123R~
        if (!fgets(Pbuff,Plinewidth-1,Phfile))//null if error/ eof //~v123I~
        {                                                          //~va1cI~
            if (ferror(Phfile))                                    //~v122I~
            {                                                      //~v122I~
                ufileapierr("read by fgets",Pfilename,errno);      //~v122I~
                return 8;                                          //~v122I~
            }                                                      //~v122I~
            else                                                   //~v122I~
                return -1;      //eof                              //~v122I~
        }//fgets                                                   //~va1cI~
//      if (!stricmp(Pbuff,"quit\n"))                              //~v123R~//~vastR~
//          return -1;                                             //~v123R~//~vastR~
//      len=strlen(Pbuff);         //read len                      //~v129R~//~vaa1R~
        len=(UINT)strlen(Pbuff);         //read len                //~vaa1I~
		UTRACEP("%s:rbmode=0 buff=%s\n",UTT,Pbuff);                //~vastM~
		UTRACED("rbmode=0 buff=",Pbuff,(int)len);                  //~vastI~
        if (len>0 && *(Pbuff+len-1)=='\n')                         //~vastR~
        {                                                          //~vastI~
        	len--;                                                 //~vastI~
	        if (len>0 && *(Pbuff+len-1)=='\r')                     //~vastR~
	        	len--;                                             //~vastI~
            *(Pbuff+len)=0;                                        //~vastI~
        }                                                          //~vastI~
        if (!stricmp(Pbuff,"quit"))                                //~vastI~
            return -1;                                             //~vastI~
		if (stdinX)	//hexcode input by /Yx                         //~vas8R~
//      len=xcvX2S(Pbuff,len);                                     //~vas8I~//~vas9R~
        len=(UINT)xcvX2S(Pbuff,(int)len);                          //~vas9R~
        else                                                       //~vas8I~
		if (Sstdinsw==1 && swQuit)                                 //~vas8I~
//      len=xcvdropLF(Pbuff,len);                                  //~vas8I~//~vas9R~
        len=(UINT)xcvdropLF(Pbuff,(int)len);                       //~vas9R~
		if (Sconvopt==CONV_U2F || Sconvopt==CONV_U2S)              //~vasbI~
        {                                                          //~vasbI~
            if (Slesw & UCVUCS_UCS4)                               //~vasbI~
            {                                                      //~vasbI~
                if (len==1)                                        //~vasbI~
                {                                                  //~vasbI~
                    Pbuff[3]=Pbuff[0];                             //~vasbI~
                    Pbuff[0]=0;                                    //~vasbI~
                    Pbuff[1]=0;                                    //~vasbI~
                    Pbuff[2]=0;                                    //~vasbI~
                    len=4;                                         //~vasbI~
                }                                                  //~vasbI~
                else                                               //~vasbI~
                if (len==2)                                        //~vasbI~
                {                                                  //~vasbI~
                    Pbuff[2]=Pbuff[0];                             //~vasbI~
                    Pbuff[3]=Pbuff[1];                             //~vasbI~
                    Pbuff[0]=0;                                    //~vasbI~
                    Pbuff[1]=0;                                    //~vasbI~
                    len=4;                                         //~vasbI~
                }                                                  //~vasbI~
                else                                               //~vasbI~
                if (len==3)                                        //~vasbI~
                {                                                  //~vasbI~
                    Pbuff[3]=Pbuff[2];                             //~vasbI~
                    Pbuff[2]=Pbuff[1];                             //~vasbI~
                    Pbuff[1]=Pbuff[0];                             //~vasbI~
                    Pbuff[0]=0;                                    //~vasbI~
                    len=4;                                         //~vasbI~
                }                                                  //~vasbI~
            }                                                      //~vasbI~
            else	//ucs2                                         //~vasbI~
            {                                                      //~vasbI~
                if (len==1)                                        //~vasbI~
                {                                                  //~vasbI~
                    Pbuff[1]=Pbuff[0];                             //~vasbI~
                    Pbuff[0]=0;                                    //~vasbI~
                    len=2;                                         //~vasbI~
                }                                                  //~vasbI~
                else                                               //~vasgI~
                if (len>2)                                         //~vasgI~
                {                                                  //~vasgI~
	        		uerrmsg("Requires UCS4 option(%cY4) for over u-ffff",//~vasgI~
    	    			    "u-ffff 以上の場合 UCS4 オプション(%cY4)が必要です",//~vasgI~
							CMDFLAG_PREFIX);                       //~vasgI~
                }                                                  //~vasgI~
            }                                                      //~vasbI~
        }//U2F,U2S                                                 //~vasbI~
    }//rbmode                                                      //~v122I~
	*Ppoutlen=(int)len;                                            //~v129R~
//  return 0;                                                      //~v124R~
    return rc;                                                     //~v124I~
}//xcvfilegetline                                                  //~v122I~
//**************************************************************** //~v121I~
// xcvfuncwrite                                                    //~v121I~
//* output data write interface callback func between ucvfxxxx     //~v121I~
//*parm1:write buff                                                //~v121I~
//*parm2:write req len                                             //~v121I~
//*retrn:rc                                                        //~v121I~
//**************************************************************** //~v121I~
int xcvfuncwrite(UCHAR *Pbuff,int Preqlen)                         //~v121I~
{                                                                  //~v121I~
	Soutfileoffs+=Preqlen;                                         //~v128I~
//UTRACED("xcvfuncwrite",Pbuff,Preqlen);                           //~v131R~
	return xcvfileputline(Sfnmo,Sfho,Pbuff,Preqlen);               //~v121I~
}//xcvfuncwrite                                                    //~v121I~
//**************************************************************** //~v122I~
// xcvfileputline                                                  //~v122I~
//* 1 line get                                                     //~v122I~
//*parm1:eol option                                                //~v122I~
//*parm2:file name for err msg                                     //~v122I~
//*parm3:file handle for i/o                                       //~v122I~
//*parm4:write buff                                                //~v122I~
//*parm5:write len                                                 //~v122I~
//*retrn:rc 0:ok                                                   //~v122I~
//**************************************************************** //~v122I~
int xcvfileputline(UCHAR *Pfilename,FILE *Phfile,char *Pbuff,int Plen)//~v122R~
{                                                                  //~v122I~
    UINT rc;                                                       //~v129R~
    int lrecl,reslen,writelen;                                     //~va3zI~
    char *pc;                                                      //~va3zI~
//****************************                                     //~v122I~
//    if (Phfile==stdout)                                          //~v123R~
//    {                                                            //~v123R~
//UTRACED("stdout",Pbuff,Plen);                                    //~v123R~
//        printf(Pbuff);                                           //~v123R~
////      printf("\n");                                            //~v123R~
//    }//rbmode                                                    //~v123R~
//    else                                                         //~v123R~
//    {                                                            //~v123R~
//#ifndef UNX                                                      //~v129R~
//    if (Sstdoutsw)      //stdout output                          //~v129R~
//    {                                                            //~v129R~
//#ifdef XXX                                                       //~v129R~
//        if (Plen>=2                                              //~v129R~
//        &&  *(Pbuff+Plen-2)==0x0d                                //~v129R~
//        &&  *(Pbuff+Plen-1)==0x0a)                               //~v129R~
//        {                                                        //~v129R~
//            *(Pbuff+Plen-2)=0x0a;                                //~v129R~
//            Plen--;                                              //~v129R~
//        }                                                        //~v129R~
//#endif                                                           //~v129R~
//    }                                                            //~v129R~
//#endif                                                           //~v129R~
      if ((Sconvopt==CONV_A2E)                                     //~va40R~
      &&  (Sebcopt & EBC2ASC_FIXEDLRECL)         //fixed LRECL out //~va40R~
      )                                                            //~va40I~
      {                                                            //~va40R~
        	lrecl=Sebclrecl;                                       //~va40I~
            for (reslen=Plen,pc=Pbuff;reslen>0;reslen-=lrecl,pc+=lrecl)//~va3zR~
            {                                                      //~va3zR~
                    if (reslen<lrecl)                              //~va3zR~
                        memset(pc+reslen,CHAR_EBC_SPACE,(UINT)(lrecl-reslen));//~va3zR~
                    writelen=(int)fwrite(pc,1,(UINT)lrecl,Phfile); //~va3zR~
			        if (writelen<lrecl)                            //~va3zI~
        			{                                              //~va3zI~
            			ufileapierr("fwrite",Pfilename,errno);     //~va3zI~
            			exit(8);                                   //~va3zI~
        			}                                              //~va3zI~
                    if (Sebcopt & EBC2ASC_SETEOL)                  //~va3zR~
                    {                                              //~va4jI~
                      if (Smiscopt & MISC_ASCEOL)                  //~va4iI~
#ifdef UNX                                                         //~va4hI~
                        fwrite("\n",1,1,Phfile);                   //~va3zR~
#else                                                              //~va4hI~
                        fwrite("\r\n",1,2,Phfile);                 //~va4hI~
#endif                                                             //~va4hI~
                      else                                         //~va4iI~
                        fwrite(EBC_NL_STR,1,1,Phfile);             //~va4iI~
                    }                                              //~va4jI~
                    if (writelen<lrecl)                            //~va3zR~
                        break;                                     //~va3zR~
            }                                                      //~va3zR~
      }                                                            //~va3zI~
      else                                                         //~va3zI~
      {                                                            //~va3zI~
//      rc=fwrite(Pbuff,1,(UINT)Plen,Phfile);                      //~v129R~//~vaa1R~
//     if (Sstdinsw && stdoutX)                                    //~vas8R~
       if (stdoutX)                                                //~vas8I~
       {                                                           //~vas8I~
       		int len2;                                              //~vas8I~
//         	rc=xcvB2X(Pbuff,Plen,&len2);                           //~vas8R~//~vas9R~
           	rc=(UINT)xcvB2X(Pbuff,Plen,&len2);                     //~vas9I~
			UTRACED("B2X out",Pbuff,len2);                         //~vas8I~
	        rc=(UINT)fwrite(Pbuff,1,(UINT)len2,Phfile);            //~vas8I~
        if ((int)rc<len2)                                          //~vas8I~
        {                                                          //~vas8I~
            ufileapierr("fwrite",Pfilename,errno);                 //~vas8I~
            exit(8);                                               //~vas8I~
        }                                                          //~vas8I~
#ifdef UNX                                                         //~vasmI~
        fwrite("\n",1,1,Phfile);                                   //~vasmI~
#else                                                              //~vasmI~
        fwrite("\r\n",1,2,Phfile);                                 //~vasmI~
#endif                                                             //~vasmI~
       }                                                           //~vas8I~
       else                                                        //~vas8I~
       {                                                           //~vas8I~
        rc=(UINT)fwrite(Pbuff,1,(UINT)Plen,Phfile);                //~vaa1I~
UTRACED("out",Pbuff,Plen);                                         //~va40R~
        if ((int)rc<Plen)                                          //~v129R~
        {                                                          //~v122I~
            ufileapierr("fwrite",Pfilename,errno);                 //~v123R~
            exit(8);                                               //~v122I~
        }                                                          //~v122I~
       }                                                           //~vas8I~
        if (Sebcopt & EBC2ASC_SETEOL)                              //~va40I~
        	if (Sconvopt==CONV_A2E||Sconvopt==CONV_E2A)            //~va40R~
            {                                                      //~va4jI~
              if (Sconvopt==CONV_A2E && !(Smiscopt & MISC_ASCEOL)) //~va4jI~
                fwrite(EBC_NL_STR,1,1,Phfile);                     //~va4jI~
              else                                                 //~va4jI~
#ifdef UNX                                                         //~va4hI~
            	fwrite("\n",1,1,Phfile);                           //~va40I~
#else                                                              //~va4hI~
            	fwrite("\r\n",1,2,Phfile);                         //~va4hI~
#endif                                                             //~va4hI~
            }                                                      //~va4jI~
      }//                                                          //~va40R~
//    }                                                            //~v123R~
	return 0;                                                      //~v122I~
}//xcvfileputline                                                  //~v122I~
//**************************************************************** //~v128I~
// xcvfuncerr                                                      //~v128I~
//* callback weh err detected                                      //~v128I~
//*parm1:rc                                                        //~v128I~
//*parm2:offset err detected or chked len when normal              //~v128R~
//*retrn:                                                          //~v128I~
//**************************************************************** //~v128I~
int xcvfuncerr(int Prc,int Poffs,int Poutoffs,UCHAR *Pinbuff,int Perrlen)//~v131R~
{                                                                  //~v128I~
    int rc=0;                                                      //~v128R~
    int len;                                                       //~v131I~
    UCHAR errdump[12];                                             //~v131I~
//**************************                                       //~v128I~
//UTRACEP("funcerr rc=%d,in=%08x,out=%08x file=%08x\n",Prc,Poffs,Poutoffs,Sfileoffs);//~v131R~
    switch(Prc)                                                    //~v128I~
    {                                                              //~v128I~
    case 0:            //normal processed                          //~v128I~
    	Sfileoffs+=Poffs;   //add checked len                      //~v128I~
        break;                                                     //~v128I~
    case UCVUCS_LENERR://                                          //~v128M~
        break;                                                     //~v128I~
    case UCVUCS_FMTERR:     //utf,ucs fmt                          //~v128R~
    case UCVUCS_CONVERR:    //sjis->ucs conv err                   //~v128I~
    	len=min(Perrlen,4);                                        //~v131I~
    	len=max(Perrlen,0);                                        //~v131I~
        if (len)                                                   //~v131I~
        {                                                          //~v131I~
            ub2x(UBX_LOWER,errdump,Pinbuff+Poffs,len);             //~v131I~
            *(errdump+len+len)=0;                                  //~v131I~
        }                                                          //~v131I~
        else                                                       //~v131I~
            *errdump=0;                                            //~v131I~
    	if (++Serrctr<=Smaxerrctr)                                 //~v128R~
	        uerrmsg("conversion err at input offset=%08lx(%s),output offset=%08lx",//~v131R~
    	    		"+%08lx(%s) (出力ファイル +%08lx) で変換エラー",//~v131R~
        	        Sfileoffs+Poffs,errdump,Soutfileoffs+Poutoffs);//~v131R~
        break;                                                     //~v128I~
    case UCVUCS_BUFFOVF:                                           //~v128I~
        uerrexit("buffer overflow at input offset %08lx(outlen=%d).",//~v128R~
        		"+%08lx でバッファ溢れ(出力長=%d)",                //~v128R~
                Sfileoffs+Poffs,Poutoffs);                         //~v128R~
        break;                                                     //~v128I~
    }                                                              //~v128I~
//UTRACEP("funcerr ret   in=%08x,out=%08x,file=%08x\n",Poffs,Poutoffs,Sfileoffs);//~v131R~
    return rc;                                                     //~v128I~
}//xcvfuncerr                                                      //~v128I~
//**********************************************************************//~va4pI~
//*get cpeb option                                                 //~va4pI~
//**********************************************************************//~va4pI~
int	getebccodepage(int Popt,char *Pparmstr)                        //~va4pR~
{                                                                  //~va4pI~
	char *pcvname;                                                 //~va4pI~
    int rc,handle;                                                 //~va4pR~
//*************************                                        //~va4pI~
	if (!(Popt & 0x01))                                            //~va4pI~
    {                                                              //~va4pI~
		pcvname=Pparmstr+sizeof(OPTCPEB)-1;                        //~va4pR~
    	if (*pcvname==':'||*pcvname=='='                           //~va4pR~
    	)                                                          //~va4pR~
    		pcvname++;                                             //~va4pR~
        UstrncpyZ(Sebccp,pcvname,sizeof(Sebccp));                  //~va4pI~
    }                                                              //~va4pI~
    else                                                           //~va4pI~
    {                                                              //~va4pI~
    	pcvname=Sebccp;                                            //~va4pR~
    	rc=ucvebc4_createhandle(0,pcvname,&handle);                //~va4pR~
    	if (rc)                                                    //~va4pR~
    		uerrexit("EBCDIC codepage specification err(%s)",0,    //~va4pR~
    				Pparmstr);                                     //~va4pR~
    	Sebchandle=handle;                                         //~va4pR~
    }                                                              //~va4pI~
    return 0;                                                      //~va4pI~
}//getebccodepage                                                  //~va4pI~
//**********************************************************************//~va55I~
void seticudata(int Popt,char *Ppicudata)                          //~vat1M~
{                                                                  //~vat1M~
    char fpath[_MAX_PATH];                                         //~vat1I~
    UTRACEP("%s:icudata=%s\n",UTT,Ppicudata);                      //~vat1M~
    ufullpath(fpath,Ppicudata,sizeof(fpath));                      //~vat1I~
    if (ufstat(fpath,0))                                           //~vat1R~
    {                                                              //~vat1I~
    	uerrexit("%s is not found",0,                              //~vat1I~
        		Ppicudata);                                        //~vat1I~
    }                                                              //~vat1I~
    udos_setenv(0,OPTICU_DATA,Ppicudata);                          //~vat1M~
}                                                                  //~vat1M~
//**********************************************************************//~va55I~
int mapinit(int Popt,char *Pmapfile,PUCVEXTCFG *Ppcfg)             //~va55I~
{                                                                  //~va55I~
//	ULONG pcfg;                                                    //~va55I~//~va66R~
	ULPTR pcfg;                                                    //~va66I~
    int opt;                                                       //~va57R~
	UCVEXTCFG  convertercfg;                                       //~vag0I~
    int rc2=0;                                                     //~vat0I~
//*******************                                              //~va57I~
    UTRACEP("%s:opt=0x%04x,mapfile=%s,Smapinitcall=%d\n",UTT,Popt,Pmapfile,Smapinitcall);       //~vat0I~//~vataR~
	Smapinitcall=1;                                                //~vataI~
    opt=Popt;                                                      //~va57I~
    if (Smiscopt & MISC_ICU)                                       //~va57M~
		opt|=UCEIO_USEICU;         //0x0001 //set use icu flag     //~va57M~
    if (!*Pmapfile	//no /MF: parm                                 //~vag0R~
    &&  Smiscopt & MISC_ICU                                        //~vag0I~
//  &&  !ucvext_getConverterCfg(0,&convertercfg))	//dll found by uconv//~vag0R~//~vat0R~
    &&  !(rc2=ucvext_getConverterCfg(0,&convertercfg),rc2)	//dll found by uconv//~vat0R~
    )                                                              //~vat0I~
    {                                                              //~vag0I~
    	opt|=UCEIO_CONVERTERCFG; //parm-cfg is created by getConverterCfg//~vag0I~
        *Ppcfg=&convertercfg;    //ucvext_mapinit copy convertercfg then uodate it Scfg in ucvext//~vag0I~
		if (ucvext_mapinit(opt,"",Ppcfg))                          //~vag0I~
    		return 4;                                              //~vag0I~
    }                                                              //~vag0I~
    else                                                           //~vag0I~
    {                                                              //~vat0I~
	    char *envicudata=getenv(OPTICU_DATA);// "ICU_DATA"         //~vat1I~
    	UTRACEP("%s:rc2=%d,envicudata=%s,SswList=%d\n",UTT,rc2,envicudata,SswList);                            //~vat0I~//~vat1R~
        if (*Pmapfile)                                             //~vat0I~
	    	opt|=UCEIO_ERREXIT;                                    //~vat0R~
        else                                                       //~vat0I~
    	if (Smiscopt & MISC_ICU)                                   //~vat0I~
        {                                                          //~vat1I~
#ifdef W32                                                         //~vat1I~
        	if (SswList && !envicudata)                            //~vat1I~
				seticudata(0,"c:\\Windows\\Globalization\\ICU");   //~vat1I~
#endif                                                             //~vat1I~
	        envicudata=getenv(OPTICU_DATA);// "ICU_DATA"           //~vat1I~
	    	UTRACEP("%s:envicudata=%s\n",UTT,envicudata);          //~vat1I~
        	if (!(SswList && envicudata))                          //~vat1R~
            {                                                      //~vat1I~
          if (rc2)                                                 //~vat0I~
        	uerrexit("ICU environment check failed, specify it by cfg on %cMF option",0,//~vat0R~
						CMDFLAG_PREFIX);                           //~vat0R~
            }                                                      //~vat1I~
        }                                                          //~vat1I~
      if (Pmapfile)                                                //~vat1I~
    	if (*Pmapfile==':')                                        //~vat0I~
        	uerrmsg("%s is invalid, work dir prefix \"::\" is not available for xcv, specify fullpath name",0,//~vat0I~
            		Pmapfile);                                     //~vat0I~
	if (ucvext_mapinit(opt,Pmapfile,Ppcfg))                       //~va55I~//~va57R~
    	return 4;                                                  //~va55I~
    }                                                              //~vat0I~
//  pcfg=(ULONG)(*Ppcfg);                                          //~va55R~//~va66R~
    pcfg=(ULPTR)(*Ppcfg);                                          //~va66I~
    opt=0;                                                         //~va57I~
	ucvebc3_init(opt,&pcfg);	//set ucvebc3:Sebcopte2a,Sebcopta2e for ucvebc3_f2bcmd//~va55R~//~va57R~
    return 0;                                                      //~va55I~
}//mapinit                                                         //~va55I~
//*********************************************************************//~vataM~
//*setup Sasc2ebc037                                               //~vataM~
//*********************************************************************//~vataM~
void mapinitcallPrint(void)                                        //~vataR~
{                                                                  //~vataM~
	UTRACEP("%s:Smapinitcall=%d,Sebcopt=%08x\n",UTT,Smapinitcall,Sebcopt);//~vataR~
	if (Smapinitcall)                                              //~vataM~
    	return;                                                    //~vataM~
    int optmapi=UCEIO_LOCALEDIT /*do setdefault,set SEXTF_DBCSSTART flag*///~vataM~
					|UCEIO_SAVECV|UCEIO_SAVEMAP|UCEIO_NOERRMSG;    //~vataM~
    if (mapinit(optmapi,""/*mapfile*/,&Spcfg)>1/*file open err*/)  //~vataM~
    	uerrexit("EBCDIC default init failed",0);                  //~vataM~
	ucvebcinita2e(Sebcopt);    //TODO TEST                      //~v7dyI~//~vataI~
	ucvebc_defaultremap(0,Spcfg); //TODO TEST //apply cfg E2A/A2E option for no converter use case//~v7dyI~//~vataI~
}                                                                  //~vataM~
//*********************************************************************//~v7DuI~
//internal table init for B2x or x2B (x=s:sjis,e:euc, a:ascii)     //~v7DuI~
//*********************************************************************//~v7DuI~
void mapinitcallInternalTable(int Popt,char *Pmapfile) 	//internal table init for B2x or x2B (x=s:sjis,e:euc, a:ascii)//~v7DuR~
{                                                                  //~v7DuI~
	UTRACEP("%s:Smapinitcall=%d,Sebcopt=%08x,Pmapfile=%s\n",UTT,Smapinitcall,Sebcopt,Pmapfile);//~v7DuR~
	if (Smapinitcall)                                              //~v7DuI~
    	return;                                                    //~v7DuI~
    int optmapi=UCEIO_LOCALEDIT /*do setdefault,set SEXTF_DBCSSTART flag*///~v7DuI~
					|UCEIO_SAVECV|UCEIO_SAVEMAP|UCEIO_NOERRMSG;    //~v7DuI~
    char *mapf=Pmapfile;                                           //~v7DuI~
    if (!mapf)                                                     //~v7DuI~
    	mapf="";                                                   //~v7DuI~
    if (mapinit(optmapi,mapf,&Spcfg)>1/*file open err*/)           //~v7DuR~
    	uerrexit("%s open error",0,Pmapfile);                      //~v7DuI~
}                                                                  //~v7DuI~
//**********************************************************************//~va59I~
int listconverter(int Popt,char *Pmapfile)                         //~va59I~
{                                                                  //~va59I~
	PUCVEXTCFG pcfg=NULL;                                               //~va59R~//~va64R~
    int opt=-1;                                                    //~va59I~
    int swicu=0;                                                   //~va59I~
    char *pdllver,*papiver,*mapfile;                               //~va59R~
//*******************                                              //~va59I~
    mapfile=Pmapfile;                                              //~va59I~
    if (mapfile)                                                   //~va59R~
        opt=UCEIO_LOCALEDIT|UCEIO_SAVECV|UCEIO_SAVEMAP;            //~va59I~
    else                                                           //~va59I~
    	if (Smiscopt & MISC_ICU)                                   //~va59I~
        {                                                          //~va59I~
            opt=UCEIO_LOCALEDIT|UCEIO_SAVECV|UCEIO_SAVEMAP|UCEIO_NOERRMSG;//~va59I~
            mapfile="";                                            //~va59I~
        }                                                          //~va59I~
    if (opt!=-1)                                                   //~va59I~
    {                                                              //~va59I~
        if (mapinit(opt,mapfile,&pcfg))//set UDBCSCHK_DBCSCV;LOCALEDIT off for xe3270//~va59R~
            uerrexit("mapfile(%s) has error",0,                    //~va59I~
                            mapfile);                              //~va59R~
        swicu=pcfg->UCECflag & UCECF_USE_ICU;                      //~va59I~
    }                                                              //~va59I~
    if (swicu)                                                     //~va59I~
    {                                                              //~va59I~
    	opt=0;                                                     //~va59I~
        pdllver=pcfg->UCECdllsuffix;                               //~va59I~
        papiver=pcfg->UCECapisuffix;                               //~va59I~
		ucvext_icuenumcvname(opt,pdllver,papiver);                 //~va59I~
    }                                                              //~va59I~
    else                                                           //~va59I~
    {                                                              //~va59I~
#ifdef W32                                                         //~va59I~
    	opt=0;                                                     //~va59I~
		ucvext_listwincp(opt);	                                   //~va59I~
#else                                                              //~va59I~
		uerrexit("specify \"%c%s\" option to list ICU converter(Use \"iconv -l\" to list iconv converter)",0,//~va59R~
        			CMDFLAG_PREFIX,OPTICU);                        //~va59I~
#endif                                                             //~va59I~
    }                                                              //~va59I~
    return 0;                                                      //~va59I~
}//listconverter                                                   //~va59I~
//**********************************************************************//~vat1I~
char *createTempMF(int Popt,char *Ppicudata)                       //~vat1R~
{                                                                  //~vat1I~
    char *mf=0;                                                    //~vat1M~
    UTRACEP("%s:icudata=%s\n",UTT,Ppicudata);                      //~vat1I~
#ifdef BBB    	                                                   //~vat1I~
    char fpath[_MAX_PATH];                                         //~vat1M~
    char cfgdata[512];                                             //~vat1M~
  if (Ppicudata)                                                   //~vat1I~
    if (ufstat(Ppicudata,0))                                       //~vat1I~
    {                                                              //~vat1I~
    	uerrexit("%s is not found",0,                              //~vat1I~
        		Ppicudata);                                        //~vat1I~
    }                                                              //~vat1I~
	char *tmpfnm=utempnam(0/*dir*/,"xcvmf",fpath);                 //~vat1I~
    if (tmpfnm)                                                    //~vat1I~
    {                                                              //~vat1I~
        FILE *fh=fopen(fpath,"w");                                 //~vat1I~
      if (Ppicudata)                                               //~vat1I~
        sprintf(cfgdata,"CONVERTER 1  #ICU \n %s  %s\n SBCS_CHARSET %s",//~vat1R~
			OPTICU_DATA,Ppicudata,EBC_US);                         //~vat1R~
      else                                                         //~vat1I~
        sprintf(cfgdata,"CONVERTER 1  #ICU \n #     \n SBCS_CHARSET %s",//~vat1I~
			                      EBC_US);                         //~vat1I~
        UTRACEP("%s:cfgdata=%s\n",UTT,cfgdata);                    //~vat1R~
        fprintf(fh,"%s",cfgdata);                                  //~vat1I~
        fclose(fh);                                                //~vat1I~
        mf=strdup(tmpfnm);                                         //~vat1R~
    }                                                              //~vat1I~
#else                                                              //~vat1I~
#endif                                                             //~vat1I~
    UTRACEP("%s:mf=%s\n",UTT,mf);                                  //~vat1I~
    return mf;                                                     //~vat1I~
}                                                                  //~vat1I~
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
  	int parmno; //parm count work                                  //~v122R~
  	int posparmno=0; //parm count work
    int buffsz,macid=0;                                            //~v122R~
    char *cptr,*pc;                                                //~v145R~
    int mapsw=0,mapsjissw=0,errchsw=0;                             //~v132R~
    int ebcoptsw=0;                                                //~v134I~
    UCHAR errdbcs[4];                                              //~va1nI~
    char *picudata=0;                                              //~vat1I~
#ifdef WCSUPP                                                      //~va3yI~
    char *mapfile=0;                                               //~va3yI~
#endif                                                             //~va3yI~
//#ifdef UTF8SUPP                                                  //~va41R~
#ifdef WCSUPP                                                      //~va41I~
  #ifdef LNX                                                       //~va3iI~
	char *plocale=0;                                               //~va3iI~
//  int rc2;                                                       //~va3tR~
  #endif                                                           //~va3iI~
    int rc2;                                                       //~va3tI~
	char localecode[MAXLOCALESZ];                                  //~va3iR~
#endif                                                             //~va3iI~
	int optmapi;                                                   //~va4pI~
    int swlist=0;                                                  //~va59I~
    int swicu=0;                                                   //~vat1I~
//*************************
  	if (parmc<2 || *parmp[1]=='?')
  	{
    	help();
//  	exit(4);                                                   //~vas5R~
    	exit(0);                                                   //~vas5I~
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
    	int swicudata=0;                                           //~vat1I~
  		cptr=parmp[parmno];
        UTRACEP("%s:cptr=%s\n",UTT,cptr);                          //~vat1I~
#ifdef UNX                                                         //~v143I~
  		if(*cptr=='-')                                             //~v143I~
#else                                                              //~v143I~
  		if(*cptr=='/'||*cptr=='-')
#endif                                                             //~v143I~
  		{//option
        	cptr++;		//dummy for compile warning
            if (!xcvtypechk(cptr))//valid conv type                //~v127I~
            {                                                      //~v127I~
            	Sconvtype=cptr;                                    //~v127I~
                continue;                                          //~v127I~
            }                                                      //~v127I~
//#ifdef W32                                                       //~vat1R~
            if (USTRHEADIS_IC(cptr,OPTICU_DATA) && !isalpha(*(cptr+sizeof(OPTICU_DATA)-1)))//~vat1R~
            {                                                      //~vat1I~
            	picudata=cptr+sizeof(OPTICU_DATA);                 //~vat1R~
                swicudata=1;                                       //~vat1I~
                seticudata(0,picudata);                            //~vat1I~
                UTRACEP("%s:picudata=%s\n",UTT,picudata);          //~vat1R~
            }                                                      //~vat1I~
//#endif                                                           //~vat1R~
//          if (!stricmp(cptr,"ICU"))                              //~va57R~//~va59R~
//          if (!stricmp(cptr,OPTICU))                             //~va59I~//~vat1R~
            if (swicudata || !stricmp(cptr,OPTICU))                //~vat1R~
            {                                                      //~va57I~
                swicu=1;                                           //~vat1I~
			  if (Smiscopt & MISC_M2M && !(Smiscopt & MISC_B2B))	//M2M//~va63I~
                Sotheropt|=OOPT_MBICU;	//M2M by ICU               //~va63I~
              else                                                 //~va63I~
			  if (Smiscopt & MISC_B2B                              //~va63I~
              ||  Sebcmbsw & UCEGCOO_CHKDBCS                       //~va63R~
              )                                                    //~va63I~
                Smiscopt|=MISC_ICU;                                //~va57I~
              else                                                 //~va63I~
              if (swlist)                                          //~va97R~
                Smiscopt|=MISC_ICU;                                //~va97R~
              else                                                 //~va97R~
//        		uerrexit("%c%s option is for M2M,B2x,x2B",0,       //~va63I~//~vas2R~
//      			CMDFLAG_PREFIX,OPTICU);                        //~va63I~//~vas2I~
          		uerrexit("%c%s option is for M2M,B2x,x2B. (%cList or %c[C]type have to be 1st parameter)",//~vas2I~
          		         "%c%s は is M2M,B2x,x2B 用です。（%cList や %c[C]type は最初に指定してください)",//~vas2I~
        			CMDFLAG_PREFIX,OPTICU,CMDFLAG_PREFIX,CMDFLAG_PREFIX,OPTICU);//~vas2I~
                continue;                                          //~va57I~
            }                                                      //~va57I~
            switch(toupper(*cptr))
            {
            case 0  :	// "-" :stdin input                        //~v123R~
                Sstdinsw=1;                                        //~v123I~
                posparmno++;                                       //~vas9I~
    			Sfnm="stdin";                                      //~v123I~
                break;                                             //~v123I~
            case '2'  :	// "-" :stderr file                        //~v131I~
                Sstderrfnm=cptr+1;                                 //~v131I~
                break;                                             //~v131I~
            case '?':
            case 'H':                                              //~vag0I~
                help();
                exit(0);
                break;
            case '\\':                                             //~va1cI~
            	if (!strcmp(cptr,"\\u")||!strcmp(cptr,"\\\\u"))    //~va1cR~
	                Slesw|=UCVUCS_ESCUCS;                          //~va1cI~
                else                                               //~va1cI~
                {                                                  //~va1cI~
                    optionerr("unicode text notation",cptr);       //~va1cR~
                    exit(4);                                       //~v111//~va1cI~
                }                                                  //~va1cI~
                break;                                             //~va1cI~
            case 'B':               //buffz                        //~v122I~
            	buffsz=atoi(cptr+1);                               //~v122I~
                if (buffsz>2)                                      //~v121R~
                	Sbuffsz=buffsz;                                //~v122I~
            	break;                                             //~v122I~
            case 'C':                                              //~v111R~
                if (USTRHEADIS_IC(cptr,OPTCPEB))                   //~va4pR~
                {                                                  //~va4pI~
                	getebccodepage(0,cptr);                        //~va4pR~
                	break;                                         //~va4pI~
                }                                                  //~va4pI~
            	Sconvtype=cptr+1;                                  //~v125I~
                if (xcvtypechk(Sconvtype))                         //~v127R~
                {                                                  //~v127M~
                    optionerr("conv",cptr);                        //~v127M~
                    exit(4);                                       //~v111//~v127M~
                }                                                  //~v127M~
                break;
            case 'E':               //buffz                        //~v128I~
            	Smaxerrctr=atoi(cptr+1);                           //~v128I~
            	break;                                             //~v128I~
#ifdef WCSUPP                                                      //~va3yI~
            case 'F':               //EBC file fixed record length //~va3yI~
              if (*(cptr+1)==':')   // -f:                         //~va42R~
              	UstrncpyZ(Scpfrom,cptr+2,sizeof(Scpfrom));         //~va42I~
              else                                                 //~va42I~
              {                                                    //~va42I~
            	Sebcopt|=EBC2ASC_FIXEDLRECL;                       //~va40I~
            	Sebclrecl=atoi(cptr+1);                            //~va3yR~
                if (Sebclrecl<0)                                   //~va40I~
                    optionerr("FixedLRECL",cptr);                  //~va40I~
                if (!Sebclrecl)                                    //~va40I~
                	Sebclrecl=EBC_DEFAULT_LRECL;                   //~va40I~
            	pc=cptr+1;                                         //~va3yI~
//              pc+=unumlen(pc,0/*digit*/,strlen(pc));             //~va3yI~//~va9wR~
                pc+=unumlen(pc,0/*digit*/,(int)strlen(pc));        //~va9wI~
                if (toupper(*pc)=='N')                             //~va3yR~
					Sebcopt|=EBC2ASC_NUMSTD;//EBC is fixed lrecl and numstd//~va3yI~
                else                                               //~va3zI~
                if (*pc)                                           //~va3zI~
                    optionerr("FixedLRECL",cptr);                  //~va3zI~
              }                                                    //~va42I~
            	break;                                             //~va3yI~
#endif                                                             //~va3yI~
#ifdef LNX                                                         //~va3iI~
            case 'L':               //buffz                        //~va3iI~
            	if (!stricmp(cptr,OPTLIST))                        //~va59R~
                {                                                  //~va59I~
                	swlist=1;                                      //~va59R~
                    break;                                         //~va59I~
                }                                                  //~va59I~
            	plocale=cptr+1;                                    //~va3iI~
            	break;                                             //~va3iI~
#endif                                                             //~va3iI~
#ifdef W32                                                         //~va47I~
            case 'L':               //buffz                        //~va47I~
            	if (!stricmp(cptr,OPTLIST))                        //~va59R~
                {                                                  //~va59I~
                	swlist=1;                                      //~va59R~
                    break;                                         //~va59I~
                }                                                  //~va59I~
              	uerrexit("Use M2M with \"UTF8\" for From/To CodePage.",//~va47I~
                         "\"UTF8\"をFromないしToのコードページに指定した M2Mを使用してください。");//~va47I~
            	break;                                             //~va47I~
#endif                                                             //~va47I~
            case 'R':   //EOL id                                   //~v128R~
                if (strlen(cptr+1)==4)  //dbcs rep char            //~va1nI~
                {                                                  //~va1nI~
                    if (ugethex(cptr+1,errdbcs,4)<=0)              //~va1nR~
                    {                                              //~va1nI~
                    	optionerr("Err-rep-char",cptr);            //~va1nI~
        	            exit(4);                                       //~v111//~va1nI~
                    }                                              //~va1nI~
                    Serrchdbcs=(errdbcs[0]<<8)+errdbcs[1];         //~va1nR~
UTRACEP("errdbcs=%x\n",Serrchdbcs);                                //~va42I~
                }                                                  //~va1nI~
                else                                               //~va1nI~
                if (strlen(cptr+1)==2)                             //~v129I~
                {                                                  //~v134I~
	                if (ugethex(cptr+1,&Serrch,2)<=0)              //~v134R~
                    {                                              //~v134I~
//                  	optionerr("Err-rep-char",cptr);            //~va1nR~
//      	            exit(4);                                       //~v111//~va1nR~
						Serrch=0;                                  //~va1nI~
                        Serrchdbcs=(*(cptr+1)<<8)+*(cptr+2);       //~va1nR~
                    }                                              //~v134I~
                }                                                  //~v134I~
                else                                               //~v129I~
                if (strlen(cptr+1)==1)                             //~v129I~
#ifdef WCSUPP                                                      //~va47I~
                	Serrchm2m=                                     //~va42I~
#endif                                                             //~va47I~
	                Serrch=*(cptr+1);                              //~v129R~
                else                                               //~v129I~
                if (*(cptr+1)=='\'' && *(cptr+3)=='\'')            //~v132R~
#ifdef WCSUPP                                                      //~va47I~
                	Serrchm2m=                                     //~va42I~
#endif                                                             //~va47I~
	                Serrch=*(cptr+2);                              //~v132I~
                else                                               //~v132I~
                if (*(cptr+1)=='\"' && *(cptr+3)=='\"')            //~v132R~
#ifdef WCSUPP                                                      //~va47I~
                	Serrchm2m=                                     //~va42I~
#endif                                                             //~va47I~
	                Serrch=*(cptr+2);                              //~v132I~
                else                                               //~v132I~
                    optionerr("err rep char",cptr);                //~v129I~
                errchsw=1;                                         //~v132I~
                break;                                             //~v121I~
//            case 'M':   //EOL id                                 //~v122R~
//                switch(toupper(*(cptr+1)))                       //~v122R~
//                {                                                //~v122R~
//                case 'P':                                        //~v122R~
//                    Simode=UFGETS_PC;                            //~v122R~
//                    break;                                       //~v122R~
//                case 'U':                                        //~v122R~
//                    Simode=UFGETS_UNIX;                          //~v122R~
//                    break;                                       //~v122R~
//                case 'M':                                        //~v122R~
//                    Simode=UFGETS_MAC;                           //~v122R~
//                    break;                                       //~v122R~
//                case 'T':                                        //~v122R~
//                    Simode=UFGETS_PC|UFGETS_UNIX;   //both accept//~v122R~
//                    break;                                       //~v122R~
//                case 'B':                                        //~v122R~
//                    Simode=UFGETS_BIN;                           //~v122R~
//                    break;                                       //~v122R~
//                default:                                         //~v122R~
//                    optionerr("EOL-id",cptr);                    //~v122R~
//                    exit(4);                                     //~v122R~
//                }                                                //~v122R~
//                switch(toupper(*(cptr+2)))                       //~v122R~
//                {                                                //~v122R~
//                case 'P':                                        //~v122R~
//                    omode=UFGETS_PC;                             //~v122R~
//                    break;                                       //~v122R~
//                case 'U':                                        //~v122R~
//                    omode=UFGETS_UNIX;                           //~v122R~
//                    break;                                       //~v122R~
//                case 'M':                                        //~v122R~
//                    omode=UFGETS_MAC;                            //~v122R~
//                    break;                                       //~v122R~
//                case 'B':                                        //~v122R~
//                    omode=UFGETS_BIN;                            //~v122R~
//                    break;                                       //~v122R~
//                case 'T':                                        //~v122R~
//                case  0 :                                        //~v122R~
//                    break;  //set later default                  //~v122R~
//                default:                                         //~v122R~
//                    optionerr("EOL-id",cptr);                    //~v122R~
//                    exit(4);                                     //~v122R~
//                }                                                //~v122R~
//                break;                                           //~v122R~
            case 'M':   //converter type                           //~v130I~
            	pc=cptr+1;                                         //~v130I~
                if (!stricmp(pc,"CP943C"))                         //~v130I~
                {                                                  //~v130I~
	            	mapsw=1;                                       //~v130I~
                	Slesw|=UCVUCS_CP943C;                          //~v130I~
//              	Slesw&=~UCVUCS_CPMS932;                        //~v130R~//~va9wR~
                	Slesw&=(ULONG)~UCVUCS_CPMS932;                 //~va9wI~
                }                                                  //~v130I~
                else                                               //~v130I~
                if (!stricmp(pc,"MS932"))                          //~v130I~
                {                                                  //~v130I~
	            	mapsw=1;                                       //~v130I~
                	Slesw|=UCVUCS_CPMS932;                         //~v130R~
//                	Slesw&=~UCVUCS_CP943C;                         //~v130I~//~va9wR~
                  	Slesw&=(ULONG)~UCVUCS_CP943C;                  //~va9wI~
                }                                                  //~v130I~
                else                                               //~v130I~
                if (!stricmp(pc,"SJIS"))                           //~v130I~
                {                                                  //~v130I~
	            	mapsw=1;                                       //~v130I~
//              	Slesw&=~(UCVUCS_CPMS932|UCVUCS_CP943C);        //~v130R~//~va9wR~
                	Slesw&=(ULONG)~(UCVUCS_CPMS932|UCVUCS_CP943C); //~va9wI~
                }                                                  //~v130I~
                else                                               //~v130I~
                if (!stricmp(pc,"IBM"))                            //~v130I~
                {                                                  //~v130I~
	            	mapsjissw=1;                                   //~v130I~
//                	Slesw&=~UCVUCS_NEC;                            //~v130I~//~va9wR~
                  	Slesw&=(ULONG)~UCVUCS_NEC;                     //~va9wI~
                	Sebcopt&=~(EBC2ASC_NEC);                       //~va1mI~
                	Sebcopt|=(EBC2ASC_IBM);                        //~va1mI~
                }                                                  //~v130I~
                else                                               //~v130I~
                if (!stricmp(pc,"NEC"))                            //~v130I~
                {                                                  //~v130I~
	            	mapsjissw=1;                                   //~v130I~
                	Slesw|=UCVUCS_NEC;                             //~v130I~
                	Sebcopt&=~(EBC2ASC_IBM);                       //~va1mI~
                	Sebcopt|=(EBC2ASC_NEC);                        //~va1mI~
                }                                                  //~v130I~
                else                                               //~v130I~
                if (!stricmp(pc,"CRLF"))                           //~v134I~
                {                                                  //~v134I~
                	ebcoptsw=1;                                    //~v134I~
                	Sebcopt|=EBC2ASC_CRLF;                         //~v134I~
                	Sebcopt&=~EBC2ASC_CTL;                         //~v134R~
                }                                                  //~v134I~
                else                                               //~v134I~
                if (!stricmp(pc,"CRLFZ"))                          //~vbBuI~
                {                                                  //~vbBuI~
                	ebcoptsw=1;                                    //~vbBuI~
                	Sebcopt|=EBC2ASC_CRLF;                         //~vbBuI~
                	Sebcopt&=~EBC2ASC_CTL;                         //~vbBuI~
                    Smiscopt|=MISC_EBCEOLZ;	//allow 0d15 as eol    //~vbBuI~
                }                                                  //~vbBuI~
                else                                               //~vbBuI~
                if (!stricmp(pc,"ANK"))                            //~v134I~
                {                                                  //~v134I~
                	ebcoptsw=1;                                    //~v134I~
                	Sebcopt&=~(EBC2ASC_CTL|EBC2ASC_CRLF);          //~v134I~
                }                                                  //~v134I~
                else                                               //~va1sI~
                if (!stricmp(pc,"SETEOL"))                         //~va3zI~
                {                                                  //~va3zI~
                	Sebcopt|=EBC2ASC_SETEOL;                       //~va3zR~
                }                                                  //~va3zI~
                else                                               //~va3zI~
                if (!stricmp(pc,"ASCEOL"))                         //~va4jI~
                {                                                  //~va4jI~
                	Smiscopt|=MISC_ASCEOL;                         //~va4jI~
                }                                                  //~va4jI~
                else                                               //~va4jI~
                if (!stricmp(pc,"SBCS"))                           //~va1sI~
                {                                                  //~va1sI~
                	ebcoptsw=1;                                    //~va1sI~
                	Sebcopt&=~EBC2ASC_DBCS;                        //~va1sI~
                }                                                  //~va1sI~
                else                                               //~v134I~
                if (!stricmp(pc,"JIS78"))                          //~va1mI~
                {                                                  //~va1mI~
                	ebcoptsw=1;                                    //~va1mI~
                	Sebcopt&=~(EBC2ASC_NEW);                       //~va1mI~
                	Sebcopt|=(EBC2ASC_OLD);                        //~va1mI~
                }                                                  //~va1mI~
                else                                               //~va1mI~
                if (!stricmp(pc,"JIS83"))                          //~va1mI~
                {                                                  //~va1mI~
                	ebcoptsw=1;                                    //~va1mI~
                	Sebcopt&=~(EBC2ASC_OLD);                       //~va1mI~
                	Sebcopt|=(EBC2ASC_NEW);                        //~va1mI~
                }                                                  //~va1mI~
                else                                               //~va1mI~
//              if (!stricmp(pc,"CP290"))                          //~va1xI~//~va4hR~
                if (!stricmp(pc,"CP290")                           //~va4hI~
                ||  !stricmp(pc,"KANA-EXT")                        //~va4hI~
                ||  !stricmp(pc,EBCID_KANAEXT)                     //~vataI~
                )                                                  //~va4hI~
                {                                                  //~va1xI~
			 		Sebcmbsw|=UCEGCOO_IGNCP290;//ignore this option of map parm file//~va4hI~
                	ebcoptsw=1;                                    //~va1xI~
                	Sebcopt|=EBC2ASC_CP290;                        //~va1xI~
//              	Sebcopt&=~EBC2ASC_SBCSMAP037;                  //~vataR~
                	UIUIBITOFF(Sebcopt,EBC2ASC_SBCSMAP037);        //~vataR~
//              	Sebcopt&=~EBC2ASC_CP931;     //cp300+cp037     //~vataI~//~vbBsR~
                    Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP930); //0x0100+0x0200//~vataI~
                }                                                  //~va1xI~
                else                                               //~va1xI~
                if (!stricmp(pc,"CP1027")                          //~va4hI~
                ||  !stricmp(pc,"ENG-EXT")                         //~va4hI~
                ||  !stricmp(pc,EBCID_ENGEXT)                      //~vataI~
                )                                                  //~va4hI~
                {                                                  //~va4hI~
			 		Sebcmbsw|=UCEGCOO_IGNCP290;//ignore this option of map parm file//~va4hI~
                	ebcoptsw=1;                                    //~va4hI~
                	Sebcopt&=~EBC2ASC_CP290;                       //~va4hI~
//                	Sebcopt&=~EBC2ASC_SBCSMAP037;                  //~vataR~
                	UIUIBITOFF(Sebcopt,EBC2ASC_SBCSMAP037);        //~vataR~
//              	Sebcopt&=~EBC2ASC_CP931;     //cp300+cp037     //~vataI~//~vbBsR~
                    Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP939); //0x0100+0x0400//~vataI~
                }                                                  //~va4hI~
                else                                               //~vataI~
                if (!stricmp(pc,EBC_US)         //cp037            //~vataR~
//              ||  !stricmp(pc,"LATIN-EXT")                       //~vataI~//~vbBsR~
//              ||  !stricmp(pc,EBCID_LATIN)    //LATIN_EXT        //~vataR~//~vbBsR~
                )                                                  //~vataI~
                {                                                  //~vataI~
			 		Sebcmbsw|=UCEGCOO_IGNCP290;//ignore this option of map parm file//~vataI~
                	ebcoptsw=1;                                    //~vataI~
                	Sebcopt&=~EBC2ASC_CP290;                       //~vataI~
//                	Sebcopt|=EBC2ASC_SBCSMAP037;                   //~vataR~
                	UIUIBITON(Sebcopt,EBC2ASC_SBCSMAP037);         //~vataR~
//              	Sebcopt|=EBC2ASC_CP931;                        //~vataI~//~vbBsR~
//                  Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP931); //0x0100+0x1000//~vataI~//~vbBsR~
                    Gucvebc_stat|=(UCVEBCS_CMDLINEOPTION | UCVEBCS_CLO_CP037); //0x0100+0x1000//~vbBsI~
                }                                                  //~vataI~
                else                                               //~va4hI~
#ifdef WCSUPP                                                      //~va3yI~
                if (USTRHEADIS_IC(pc,"F:"))                        //~va3yI~
                	mapfile=pc+2;                                  //~va3yR~
                else                                               //~va3yI~
#endif                                                             //~va3yI~
                    optionerr("Mapping type",cptr);                //~v130I~
                break;                                             //~v130I~
            case 'O':                                              //~v123I~
                Sfnmo=cptr+1;                                      //~v123I~
                break;                                             //~v123I~
            case 'S':       //SO/SI option                         //~va1pI~
              if (!stricmp(cptr,"SBCS"))                           //~va1vI~
              {                                                    //~va1vI~
                	ebcoptsw=1;                                    //~va1vI~
                	Sebcopt&=~EBC2ASC_DBCS;                        //~va1vI~
              }                                                    //~va1vI~
              else                                                 //~va1vI~
              {                                                    //~va1vI~
            	for (pc=cptr+1;*pc;pc++)                           //~va1pI~
                {                                                  //~va1pI~
                	switch(toupper(*pc))                           //~va1pI~
                    {                                              //~va1pI~
                    case 'A':       //asume SO                     //~va1rR~
        				if (Sconvopt!=CONV_E2A)                    //~va1rI~
        					parmconflict("SO/SI option");          //~va1rI~
                        Sebcopt|=EBC2ASC_SOSIAS;//asume SO at top of line//~va1rR~
                        break;                                     //~va1rR~
                    case 'D':       //delete                       //~va1pI~
	                    Sebcopt&=~EBC2ASC_SOSI;//delete SOSI       //~va1pR~
        	            Sebcopt|=EBC2ASC_SOSID;//delete SOSI       //~va1qI~
                        break;                                     //~va1pI~
//                    case 'I':       //isrt                       //~va1qR~
//                        Sebcopt&=~(EBC2ASC_SOSIOA|EBC2ASC_SOSIOS);//~va1qR~
//                        Sebcopt|=EBC2ASC_SOSI;//delete/isrt      //~va1qR~
//                        break;                                   //~va1qR~
                    case 'I':       //isrt                         //~va4mI~
        				if (Sconvopt!=CONV_A2E)                    //~va4mI~
        					parmconflict("SO/SI option");          //~va4mI~
	                    Sebcopt|=EBC2ASC_SOSI;//default (ins sosi) //~va4mI~
        	            Sebcopt&=~(EBC2ASC_SOSIOS|EBC2ASC_SOSID);//reset rep space//~va4mR~
                        break;                                     //~va4mI~
//                    case 'N':       //no process                 //~va1qR~
//                        Sebcopt&=~(EBC2ASC_SOSI|EBC2ASC_SOSIOA|EBC2ASC_SOSIOS);//~va1qR~
//                        break;                                   //~va1qR~
                    case 'R':                                      //~va1qR~
        				if (Sconvopt==CONV_E2A)                    //~va4mI~
                        {                                          //~va4mI~
	                    	Sebcopt|=EBC2ASC_SOSI;//default (rep to space)//~va4mI~
        	            	Sebcopt&=~EBC2ASC_SOSID;//delete SOSI  //~va4mI~
                            break;                                 //~va4mI~
                        }                                          //~va4mI~
        				if (Sconvopt!=CONV_A2E)                    //~va1rR~
        					parmconflict("SO/SI option");          //~va1qR~
	                    Sebcopt&=~EBC2ASC_SOSI;//delete/isrt       //~va1qR~
	                    Sebcopt|=EBC2ASC_SOSIOS;//rep if space     //~va1pI~
                        break;                                     //~va1pI~
                    case 'S':        //shift                       //~va3wI~
        				if (Sconvopt!=CONV_A2E)                    //~va3wI~
        					parmconflict("SO/SI option");          //~va3wI~
	                    Sebcopt&=~EBC2ASC_SOSI;//reset default     //~va3wI~
	                    Sebcopt|=EBC2ASC_SOSISHIFT;//shift         //~va3wI~
                        break;                                     //~va3wI~
                    default:                                       //~va1pI~
                    	optionerr("S",pc);                         //~va1pI~
                    	exit(4);                                   //~va1pI~
                    }                                              //~va1pI~
                }                                                  //~va1pI~
#ifdef WCSUPP                                                      //~va3yI~
			    Sebcmbsw|=UCEGCOO_IGNSOSI; //ignore this option of map parm file//~va3yR~
#endif                                                             //~va3yI~
              }//!sbcs                                             //~va1vI~
                break;                                             //~va1pI~
#ifdef WCSUPP                                                      //~va47I~
            case 'T':                                              //~va42I~
              	if (*(cptr+1)==':')   // -f:                       //~va42R~
              		UstrncpyZ(Scpto,cptr+2,sizeof(Scpto));         //~va42I~
                else                                               //~va42I~
                    optionerr("T:",cptr);                          //~va42R~
                break;                                             //~va42I~
#endif                                                             //~va47I~
            case 'Y':
            	for (pc=cptr+1;*pc;pc++)
                {
                	switch(toupper(*pc))
                    {
                    case 'B':                                      //~v121I~
	                    Slesw|=UCVUCS_BOM;                         //~v121R~
                        break;                                     //~v121I~
//                  case 'D':                                      //~va1sR~
//                      Sebcopt|=EBC2ASC_DBCS;                     //~va1sR~
//                      break;                                     //~va1sR~
                    case 'H':                                      //~vas8I~
	                    stdinX=1;                                  //~vas8M~
                        parmXin=1;                                 //~vasaI~
                        break;                                     //~vas8M~
                    case 'I':     //LOCALEICU                      //~va63I~
                        break;                                     //~va63I~
                    case 'L':                                      //~v121I~
						swBELEparm=1;                              //~vas8I~
	                    Slesw|=UCVUCS_LE;                          //~v121R~
                        break;                                     //~v121I~
                    case 'M':                                      //~v122I~
	                    macid=1;                                   //~v122I~
                        break;                                     //~v122I~
                    case 'Q':                                      //~vas8I~
	                    swQuit=1;                                  //~vas8I~
                        break;                                     //~vas8I~
                    case 'X':                                      //~vas8R~
	                    stdoutX=1;                                 //~vas8I~
                        if (*pc=='X')                              //~vas8R~
                        	stdoutXUpper=1;  //output uppercase    //~vas8I~
                        else                                       //~vas8I~
                        	stdoutXUpper=0;                        //~vas8I~
                        break;                                     //~vas8I~
                    case 'Z':                                      //~v111I~
	                    Shanzensw=1;                               //~v111I~
                        break;                                     //~v111I~
                    case '4':                                      //~v121I~
	                    Slesw|=UCVUCS_UCS4;                        //~v121I~
                        break;                                     //~v121I~
                    case '9':
	                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
    	                UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                        break;                                     //~v111I~
                    default:                                       //~v111I~
                    	optionerr("Y",pc);                         //~v111I~
                    	exit(4);                                   //~v111I~
                    }
                }
            	break;
            case 'N':
            	for (pc=cptr+1;*pc;pc++)
                {
                	switch(toupper(*pc))
                    {
                    case 'B':                                      //~v121I~
//                      Slesw&=~UCVUCS_BOM;                        //~v121R~//~va9wR~
                        Slesw&=(ULONG)~UCVUCS_BOM;                 //~va9wI~
                        break;                                     //~v121I~
//                  case 'D':                                      //~va1sR~
//                      Sebcopt&=~EBC2ASC_DBCS;                    //~va1sR~
//                      break;                                     //~va1sR~
                    case 'H':                                      //~vas8I~
	                    stdinX=0;                                  //~vas8M~
                        parmXin=1;                                 //~vasaI~
                        break;                                     //~vas8M~
                    case 'I':     //LOCALEICU                      //~va63I~
                        break;                                     //~va63I~
                    case 'L':                                      //~v121I~
//                      Slesw&=~UCVUCS_LE;                         //~v121R~//~va9wR~
                        Slesw&=(ULONG)~UCVUCS_LE;                  //~va9wI~
						swBELEparm=1;                              //~vas8I~
                        break;                                     //~v121I~
                    case 'M':                                      //~v122I~
	                    macid=0;                                   //~v122I~
                        break;                                     //~v122I~
                    case 'Q':                                      //~vas8I~
	                    swQuit=0;                                  //~vas8I~
                        break;                                     //~vas8I~
                    case 'X':                                      //~vas8R~
	                    stdoutX=0;                                 //~vas8I~
                        break;                                     //~vas8I~
                    case 'Z':                                      //~v111I~
	                    Shanzensw=0;                               //~v111I~
                        break;                                     //~v111I~
                    case '4':                                      //~v121I~
//                      Slesw&=~UCVUCS_UCS4;                       //~v121I~//~va9wR~
                        Slesw&=(ULONG)~UCVUCS_UCS4;                //~va9wI~
                        break;                                     //~v121I~
                    case '9':
	                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
    	                UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                        break;                                     //~v111I~
                    default:                                       //~v111I~
                    	optionerr("N",cptr);                       //~v111R~
                    	exit(4);                                   //~v111I~
                    }
                }
            	break;
            default:                                               //~v111I~
                optionerr("",cptr);                                //~v111R~
                exit(4);                                           //~v111I~
            }//switch                                              //~v111R~
    	}//flag
      	else
      	{//positional parmno
        	posparmno++;
        	switch (posparmno)
        	{
        	case  1:          //first parm
                if (Sstdinsw)                                      //~v123I~
              		uerrexit("input specification \"-\"(stdin input) and file name(%s) is duplicated.",//~v123I~
                             "\"-\"(標準入力)指定と入力ファイル指定(%s)が重複しています。",//~v123I~
							cptr);                                 //~v123I~
          		Sfnm=cptr;                                         //~v145R~
          		break;
        	case  2:          //2nd parm                           //~v122I~
          		Sfnmo=cptr;                                        //~v122I~
          		break;                                             //~v122I~
            default:
              	uerrexit("too many positional parameter(%s)",0,cptr);
            }//switch by parmno
  		}//option or posparm
	}//for all parm
    UTRACEP("%s:mapfile=%s,picudata=%s\n",UTT,mapfile,picudata);   //~vat1I~
  if (swicu) //-ICU or -ICU_DATA                                   //~vat1I~
  {                                                                //~vat1I~
    if (mapfile)                                                   //~vat1I~
    {                                                              //~vat1I~
    	if (picudata)                                              //~vat1I~
        	uerrexit("%cMF and %c%s is mutually exclusive",0,      //~vat1I~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX,OPTICU_DATA);    //~vat1R~
    }                                                              //~vat1I~
    else                                                           //~vat1I~
    {                                                              //~vat1I~
    	if (picudata)                                              //~vat1I~
        {                                                          //~vat1I~
            if (swlist)                                            //~vat1I~
	        	mapfile=createTempMF(0,picudata);                  //~vat1R~
            else                                                   //~vat1I~
	        	uerrexit("%c%s is for %c%s only",0,                //~vat1I~
						CMDFLAG_PREFIX,OPTICU_DATA,CMDFLAG_PREFIX,OPTLIST);//~vat1R~
        }                                                          //~vat1I~
        else                                                       //~vat1I~
        {                                                          //~vat1I~
            UTRACEP("%s:no MAP,no ICU_DATA,ICU\n",UTT);            //~vat1R~
#ifdef W32                                                         //~vat1I~
            if (swlist)                                            //~vat1R~
	        	mapfile=createTempMF(0,0/*default*/);              //~vat1R~
#endif                                                             //~vat1I~
        }                                                          //~vat1I~
    }                                                              //~vat1I~
  }//swicu                                                         //~vat1I~
    if (swlist)                                                    //~va59I~
    {                                                              //~va59I~
    	SswList=1;                                                 //~vat1I~
    	listconverter(0,mapfile);                                  //~va59I~
        exit(0);                                                   //~va59I~
    }                                                              //~va59I~
    if (posparmno<1 && !Sstdinsw)	//no "-" parm nor infile parm  //~v123R~
    {                                                              //~v123I~
    	Sstdinsw=2;	//pipe input                                   //~v123R~
    	Sfnm="stdin";                                              //~v122R~
    }                                                              //~v123I~
    if (!Sfnmo)		//no -o parm                                   //~v123R~
    {                                                              //~v123I~
    	Sstdoutsw=1;                                               //~v123I~
    	Sfnmo="stdout";                                            //~v122R~
    }                                                              //~v123I~
    if (!Sconvopt)                                                 //~v111I~
    {                                                              //~v111I~
      if (!Shanzensw)                                              //~v111I~
        uerrexit("specify conversion option(%cC)",0,               //~v111R~
				CMDFLAG_PREFIX);                                   //~v111I~
#ifdef LNX                                                         //~v111I~
        Sconvopt=CONV_E2S;                                         //~v111I~
        Shanzenonlysw=1;                                           //~v111I~
#else                                                              //~v111I~
    	Sconvopt=CONV_S2E;                                         //~v111I~
        Shanzenonlysw=1;                                           //~v111I~
#endif                                                             //~v111I~
    }                                                              //~v111I~
    if (Sconvopt==CONV_E2A)		//B2x(B2S,B2E,B2M)                 //~va4jI~//~va4iR~
    {                                                              //~va4jI~
		Simode|=ucvebc_chkeolopt(UCVEBCCEO_FGETSOPT,&Sebcopt,Smiscopt);//~va4jR~
    }                                                              //~va4jI~
    else                                                           //~va4jI~
    if (Sconvopt==CONV_A2E)		//x2B(S2B,E2B,M2B)                 //~va4jR~
    {                                                              //~va4jR~
        Sebcopt|=EBC2ASC_A2E;                                      //~va4jM~
		Simode|=ucvebc_chkeolopt(UCVEBCCEO_FGETSOPT,&Sebcopt,Smiscopt);//~va4jR~
    }                                                              //~va4jR~
    else                                                           //~va4jR~
    if (Sconvopt & CONV_UCS)   //ucs conv                          //~v122I~
    {                                                              //~va4nI~
      if ((Sconvopt & CONV_UCS2)==CONV_F2)                         //~va4nI~
		Simode=UFGETS_PC|UFGETS_UNIX;   //both accept              //~va4nI~
      else                                                         //~va4nI~
		Simode=UFGETS_BIN;                                         //~v122I~
    }                                                              //~va4nI~
    else                                                           //~v122I~
        if (macid)                                                 //~v122I~
			Simode=UFGETS_MAC;   //mac                             //~v122I~
        else                                                       //~v122I~
			Simode=UFGETS_PC|UFGETS_UNIX;   //both accept          //~v122R~
////eol                                                            //~v122R~
//    if (Sconvopt & CONV_UCS2)   //input is ucs                   //~v122R~
//        if (Simode)                                              //~v122R~
//        {                                                        //~v122R~
//            if (Simode!=UFGETS_BIN)                              //~v122R~
//                parmconflict();                                  //~v122R~
//        }                                                        //~v122R~
//        else                                                     //~v122R~
//            Simode=UFGETS_BIN;                                   //~v122R~
//    else                                                         //~v122R~
//        if (Simode & UFGETS_BIN)                                 //~v122R~
//        {                                                        //~v122R~
//            if (!(Sconvopt & CONV_2UCS))    //ucsmain case       //~v122R~
//                parmconflict();                                  //~v122R~
//        }                                                        //~v122R~
//        else                                                     //~v122R~
//            if (!Simode)                                         //~v122R~
//                Simode=UFGETS_PC|UFGETS_UNIX;   //both accept    //~v122R~
////out eol                                                        //~v122R~
//    if (Sconvopt & CONV_UCS)    //input or output is ucs         //~v122R~
//    {                                                            //~v122R~
////        if (!strcmp(Sfnmo,"stdout"))                           //~v122R~
////            uerrexit("specify output filename when unicode conv",//~v122R~
////                    "unicode　変換の時は出力ファイル名を指定してください");//~v122R~
//        if (omode)                                               //~v122R~
//        {                                                        //~v122R~
//            if (omode!=UFGETS_BIN)                               //~v122R~
//                parmconflict();                                  //~v122R~
//        }                                                        //~v122R~
//        else                                                     //~v122R~
//            omode=UFGETS_BIN;                                    //~v122R~
//    }                                                            //~v122R~
//    else                                                         //~v122R~
//        if (!omode) //no outeol parm                             //~v122R~
//            if (Simode==(UFGETS_PC|UFGETS_UNIX))                 //~v122R~
//#ifdef UNX                                                       //~v122R~
//                omode=UFGETS_UNIX;                               //~v122R~
//#else                                                            //~v122R~
//                omode=UFGETS_PC;                                 //~v122R~
//#endif                                                           //~v122R~
//            else                                                 //~v122R~
//                omode=Simode;                                    //~v122R~
    if (mapsw)   //input is ucs                                    //~v130R~
    {                                                              //~v130I~
        if (Sconvopt!=CONV_S2U && Sconvopt!=CONV_S2F)              //~v130R~
        	parmconflict("Mapping type");                          //~v130R~
    }                                                              //~v130I~
    else                                                           //~v130I~
        if ((Sconvopt & CONV_UCS2) && !(Sconvopt & CONV_2UCS))	//ucs2nonucs//~v130I~
	    	Slesw|=UCVUCS_CPMS932|UCVUCS_CP943C;                   //~v130R~
//  if (mapsjissw||errchsw)   //NEC/IBM or errch                   //~v134R~
    if (mapsjissw)            //NEC/IBM or errch                   //~v134I~
    {                                                              //~v130I~
//      if (Sconvopt!=CONV_U2S && Sconvopt!=CONV_F2S)              //~va1mR~
        if (Sconvopt!=CONV_U2S && Sconvopt!=CONV_F2S               //~va1mI~
        &&  Sconvopt!=CONV_E2A && Sconvopt!=CONV_A2E)              //~va1mI~
        	parmconflict("Mapping type");                          //~v130I~
    }                                                              //~v130I~
    if (errchsw)   //err rep char                                  //~v134I~
    {                                                              //~v134I~
        if (Sconvopt!=CONV_U2S && Sconvopt!=CONV_F2S               //~v134I~
        &&  !(Smiscopt & MISC_M2M)                                 //~va42I~
        &&  Sconvopt!=CONV_E2A && Sconvopt!=CONV_A2E)              //~v134I~
        	parmconflict("Err-rep-char");                          //~v134R~
    }                                                              //~v134I~
    if (Sconvopt==CONV_A2E)  //ascii to ebc                        //~va1wI~
        if (Serrch=='?')                                           //~va1wI~
            Serrch=0;   //default EBC "?"                          //~va1wI~
    if (ebcoptsw)                                                  //~v134I~
        if (Sconvopt!=CONV_E2A && Sconvopt!=CONV_A2E)              //~v134I~
        	parmconflict("Mapping type");                          //~v134I~
//#ifdef UTF8SUPP                                                  //~va41R~
#ifdef WCSUPP                                                      //~va41I~
    if (Slesw & UCVUCS_MB)	//M2F/F2M                              //~va3iI~
    {                                                              //~va3iI~
#ifdef LNX                                                         //~va3iI~
    	if (plocale)                                               //~va3iI~
        {                                                          //~va3iI~
            UTF8SETICONV(); //force iconv under env!=utf8          //~va3iI~
        	strncpy(localecode,plocale,sizeof(localecode));        //~va3iR~
            rc2=                                                   //~va3mI~
			utfcvlocaleinit(0,localecode);                         //~va3iR~
      		if (rc2)                                               //~va3mI~
        		uerrexit("iconv open failed for %s",0,             //~va3mI~
							localecode);                           //~va3mI~
        }                                                          //~va3iI~
        else                                                       //~va3iI~
#endif                                                             //~va3iI~
            rc2=                                                   //~va3mI~
			utfcvlocaleinit(UTFCLIO_DEFAULTCHK,localecode);        //~va3iR~
      	if (rc2)                                                   //~va3mI~
        	uerrexit("failed to get default locale",0);            //~va3mI~
        fprintf(stderr,"Using Locale Code: %s\n",localecode);      //~va3iI~
    }                                                              //~va3iI~
#endif                                                             //~va3iI~
#ifdef WCSUPP                                                      //~va3yI~
    if (Sebcmbsw & UCEGCOO_CHKDBCS 	//B2M/M2B                      //~va3yR~//~va4qR~
    ||  Smiscopt & MISC_B2B)                                       //~va4qI~
    {                                                              //~va41I~
        if (mapfile)                                               //~va3yI~
        {                                                          //~va3yI~
//          if (ucvext_mapinit(UCEIO_SAVECV|UCEIO_SAVEMAP,mapfile,&Spcfg))//~va41R~//~va55R~
            if (mapinit(UCEIO_LOCALEDIT|UCEIO_SAVECV|UCEIO_SAVEMAP,mapfile,&Spcfg))//set UDBCSCHK_DBCSCV;LOCALEDIT off for xe3270//~va56R~
                uerrexit("mapfile(%s) has error",0,                //~va3yI~
                                mapfile);                          //~va3yI~
			if (!(Spcfg->UCECflag & UCECF_USE_CONVERTER))	//cfg file did not defined converter=0 or cfg not found//~va4hI~
//              uerrexit("mapfile(%s) missing CONVERTER=1/2",0,    //~va4hI~//~vbBhR~
                uerrexit("mapfile(%s) has to be of CONVERTER=1/2",0,//~vbBhR~
                                mapfile);                          //~va4hI~
        }                                                          //~va3yI~
        else                                                       //~va3yI~
        {                                                          //~va4pI~
    		if (Smiscopt & MISC_B2B)                               //~va56I~
            {                                                      //~va57I~
    		  if (!(Smiscopt & MISC_ICU))                          //~va57I~
                uerrexit("For B2B specify EBCDIC cfg '%cMF:mapfile' option, or specifi %cICU.",0,//~va56I~//~va57R~
                        CMDFLAG_PREFIX,CMDFLAG_PREFIX);            //~va57R~
            }                                                      //~va57I~
		  if (*Sebccp)	//CPEB: option specified                   //~va4pI~
          {                                                        //~va4pI~
    		if (Smiscopt & MISC_B2B)                               //~va54I~
        		uerrexit("%cCPEB option is for M2B/B2M only",0,    //~va54R~
						CMDFLAG_PREFIX);                           //~va54I~
            else                                                   //~vat3I~
        		uerrexit("requires '%cMF:mapfile' of CONVERTER=1/2.",0,//~vat3R~
    					CMDFLAG_PREFIX);                           //~vat3I~
          }                                                        //~va56I~
          else                                                     //~va56I~
          {                                                        //~va56I~
           if (Sebcmbsw & UCEGCOO_CHKDBCS) 	//B2M/M2B              //~va56I~
           {                                                       //~vat3I~
//      	uerrexit("specify EBCDIC codepage by '%cMF:mapfile' or '%cCPEB:cp'.",0,//~va56I~//~vbBhR~
        	uerrexit("specify EBCDIC codepage by '%cMF:mapfile' (and '%cCPEB:cp').",0,//~vbBhI~
    					CMDFLAG_PREFIX,                            //~va56I~
    					CMDFLAG_PREFIX);                           //~va56I~
           }                                                       //~vat3I~
          }                                                        //~va56I~
            optmapi=UCEIO_LOCALEDIT /*do setdefault,set SEXTF_DBCSSTART flag*///~va4pR~
					|UCEIO_SAVECV|UCEIO_SAVEMAP|UCEIO_NOERRMSG;    //~va4pI~
//          if (ucvext_mapinit(optmapi,""/*mapfile*/,&Spcfg)>1/*file open err*/)//~va4pI~//~va55R~
            if (mapinit(optmapi,""/*mapfile*/,&Spcfg)>1/*file open err*/)//~va55I~
                uerrexit("EBCDIC default init failed",0);          //~va4pI~
//		  	if (!(Spcfg->UCECflag & UCECF_USE_ICU))                           //~v66DI~//~va54I~//~va56R~
//        		uerrmsg("ICU library open failed, use %cMF:mapfile option to specify ICU library suffix",0,//~va54R~//~va56R~
//						CMDFLAG_PREFIX);                           //~va54I~//~va56R~
//        }                                                        //~va4pI~//~va56R~
//        else                                                     //~va4pI~//~va56R~
//      	uerrexit("mapfile option '%cMF:mapfile' is required for B2M/M2B translation",0,//~va3yI~//~va53R~
//         if (Sebcmbsw & UCEGCOO_CHKDBCS) 	//B2M/M2B              //~va55I~//~va56R~
//      	uerrexit("specify EBCDIC codepage by '%cMF:mapfile' or '%cCPEB:cp'.",0,//~va53I~//~va56R~
//  					CMDFLAG_PREFIX,                            //~va53I~//~va56R~
//  					CMDFLAG_PREFIX);                           //~va3yI~//~va56R~
        }                                                          //~va4pI~
		if (*Sebccp)	//CPEB: option specified                   //~va4pI~
 			getebccodepage(1/*createhandle*/,Sebccp);              //~va4pI~
    	if (Smiscopt & MISC_B2B)                                   //~va55I~
        {                                                          //~va55I~
//linux can use iconv                                              //~va56I~
//            if (!mapfile && !*Sebccp)                              //~va55R~//~va56R~
//                uerrexit("specify EBCDIC cfg '%cMF:mapfile' option.",0,//~va55I~//~va56R~
//                        CMDFLAG_PREFIX);                           //~va55I~//~va56R~
			if (!*Scpfrom||!*Scpto)                                //~va55I~
	        	uerrexit("specify both codepage of %cf: and %ct: for B2B",0,//~va55I~
						CMDFLAG_PREFIX,                            //~va55I~
						CMDFLAG_PREFIX);                           //~va55I~
        }                                                          //~va55I~
    }                                                              //~va41I~
    else                                                           //~va53I~
    {                                                              //~va53I~
        if (mapfile||*Sebccp)	//CPEB: option specified           //~va53I~
        	uerrexit("'%cMF:mapfile' or '%cCPEB:cp' option is for B2B/M2B/B2M only.",0,//~va53I~
						CMDFLAG_PREFIX,                            //~va53R~
						CMDFLAG_PREFIX);                           //~va53I~
    }                                                              //~va53I~
#endif                                                             //~va3yI~
    if (!Sstdinsw)   // NOT stdin or pipe                          //~vasnI~
    {                                                              //~vasnI~
        if (parmXin)	//(Y/N)h                                   //~vasnI~
        	uerrexit("%c(Y/N)h:Hex input mode is for stdin input only.(input file=\"%s\"",//~vasnR~
        	         "%c(Y/N)h:Hex文字入力オプションはファイル入力(\"%s\")では指定できません",//~vasnR~
						CMDFLAG_PREFIX,Sfnm);                      //~vasnR~
    }                                                              //~vasnI~
	if (!parmXin	//no Y/Nx parm                                 //~vasaM~
    &&   Sstdinsw==1) //not pipe                                   //~vasaI~
    {                                                              //~vasjI~
      if (Sconvopt & CONV_UCS2)  //0100:CONV_U2, 0200:CONV_F2      //~vasjI~
		stdinX=1;                                                  //~vasaM~
      if (Sconvopt & CONV_2UCS)  //1000:CONV_2U, 2000:CONV_2F      //~vasjI~
		stdoutX=1;                                                 //~vasjI~
    }                                                              //~vasjI~
    if (Sstdinsw==1 && !swBELEparm)	//stdin without /Y,/Nl option  //~vasiI~
    	Slesw&=(ULONG)~UCVUCS_LE;                                  //~vasiI~
    if (UBITCHKALL(Sconvopt,CONV_EBC2)||UBITCHKALL(Sconvopt,CONV_2EBC)) //B2x or x2B//~v7DuR~
    	mapinitcallInternalTable(0,mapfile);	//internal table init for B2x or x2B (x=s:sjis,e:euc, a:ascii)//~v7DuI~
    return;                                                        //~v145I~
}//parmchk
//**********************************************************************//~v127I~
//* get conv type                                                  //~v127I~
//**********************************************************************//~v127I~
int xcvtypechk(char *cptr)                                         //~v127R~
{                                                                  //~v127I~
	int rc=0;                                                      //~v127I~
//*******************                                              //~v127I~
                if (!stricmp(cptr,"E2S"))                        //~v111R~
                	Sconvopt=CONV_E2S;                             //~v111I~
                else                                               //~v111I~
                if (!stricmp(cptr,"S2E"))                        //~v111R~
                	Sconvopt=CONV_S2E;                             //~v111I~
                else                                               //~v111I~
                if (!stricmp(cptr,"S2S"))                        //~v111I~
                {                                                  //~v111I~
                	Sconvopt=CONV_S2E;                             //~v111I~
                    Shanzenonlysw=1;                               //~v111I~
                }                                                  //~v111I~
                else                                               //~v111I~
                if (!stricmp(cptr,"E2E"))                        //~v111I~
                {                                                  //~v111I~
                	Sconvopt=CONV_E2S;                             //~v111I~
                    Shanzenonlysw=1;                               //~v111I~
                }                                                  //~v111I~
                else                                               //~v111I~
                if (!stricmp(cptr,"J2S"))                        //~v120I~
                	Sconvopt=CONV_J2S;                             //~v120I~
                else                                               //~v120I~
                if (!stricmp(cptr,"S2J"))                        //~v125I~
                	Sconvopt=CONV_S2J;                             //~v125I~
                else                                               //~v125I~
                if (!stricmp(cptr,"J2E"))                        //~v120I~
                	Sconvopt=CONV_J2E;                             //~v120I~
                else                                               //~v126R~
                if (!stricmp(cptr,"E2J"))                        //~v126R~
                	Sconvopt=CONV_E2J;                             //~v126R~
                else                                               //~v120I~
//                if (!stricmp(cptr,"K2L"))                          //~v133I~//~vbB3R~
//                {                                                  //~v133I~//~vbB3R~
//                    Sconvopt=CONV_A2A;                             //~v133I~//~vbB3R~
//                    Smiscopt|=MISC_K2L;                            //~v133I~//~vbB3R~
//                    Smiscopt&=~MISC_L2K;                           //~v133I~//~vbB3R~
//                }                                                  //~v133I~//~vbB3R~
//                else                                               //~v133I~//~vbB3R~
//                if (!stricmp(cptr,"L2K"))                          //~v133I~//~vbB3R~
//                {                                                  //~v133I~//~vbB3R~
//                    Sconvopt=CONV_A2A;                             //~v133I~//~vbB3R~
//                    Smiscopt|=MISC_L2K;                            //~v133I~//~vbB3R~
//                    Smiscopt&=~MISC_K2L;                           //~v133I~//~vbB3R~
//                }                                                  //~v133I~//~vbB3R~
//                else                                               //~v133I~//~vbB3R~
                if (!stricmp(cptr,"K2L"))                          //~v133I~//~vbB3R~//~vbBhR~
                {                                                  //~v133I~//~vbB3R~//~vbBhR~
                    Sconvopt=CONV_A2A;                             //~v133I~//~vbB3R~//~vbBhR~
                    Smiscopt|=MISC_K2L;                            //~v133I~//~vbB3R~//~vbBhR~
                    Smiscopt&=~MISC_L2K;                           //~v133I~//~vbB3R~//~vbBhR~
                }                                                  //~v133I~//~vbB3R~//~vbBhR~
                else                                               //~v133I~//~vbB3R~//~vbBhR~
                if (!stricmp(cptr,"L2K"))                          //~v133I~//~vbB3R~//~vbBhR~
                {                                                  //~v133I~//~vbB3R~//~vbBhR~
                    Sconvopt=CONV_A2A;                             //~v133I~//~vbB3R~//~vbBhR~
                    Smiscopt|=MISC_L2K;                            //~v133I~//~vbB3R~//~vbBhR~
                    Smiscopt&=~MISC_K2L;                           //~v133I~//~vbB3R~//~vbBhR~
                }                                                  //~v133I~//~vbB3R~//~vbBhR~
                else                                               //~v133I~//~vbB3R~//~vbBhR~
//              if (!stricmp(cptr,"E2A"))                          //~va1tR~
                if (!stricmp(cptr,"B2S"))                          //~va1tI~
                	Sconvopt=CONV_E2A;                             //~v134I~
                else                                               //~v134I~
                if (!stricmp(cptr,"B2E"))                          //~va4hI~
                {                                                  //~va4hI~
                	Sconvopt=CONV_E2A;                             //~va4hI~
                    Sebcopt|=EBC2ASC_EUC;  //to euc                //~va4hI~
                }                                                  //~va4hI~
                else                                               //~va4hI~
                if (!stricmp(cptr,"B2A"))                          //~va2oI~
                {                                                  //~va2oI~
                	Sconvopt=CONV_E2A;                             //~va2oI~
                    Sebcopt&=~EBC2ASC_DBCS;  //no dbcs process     //~va2oR~
                }                                                  //~va2oI~
                else                                               //~va2oI~
//              if (!stricmp(cptr,"A2E"))                          //~va1tR~
                if (!stricmp(cptr,"S2B"))                          //~va1tI~
                	Sconvopt=CONV_A2E;                             //~v134I~
                else                                               //~va2oI~
                if (!stricmp(cptr,"E2B"))                          //~va4hI~
                {                                                  //~va4hI~
                	Sconvopt=CONV_A2E;                             //~va4hI~
                    Sebcopt|=EBC2ASC_EUC;  //to euc                //~va4hI~
                }                                                  //~va4hI~
                else                                               //~va4hI~
                if (!stricmp(cptr,"A2B"))                          //~va2oI~
                {                                                  //~va2oI~
                	Sconvopt=CONV_A2E;                             //~va2oI~
                    Sebcopt&=~EBC2ASC_DBCS;  //no dbcs process     //~va2oR~
                }                                                  //~va2oI~
                else                                               //~v134I~
                if (!stricmp(cptr,"S2U"))                        //~v121I~
                	Sconvopt=CONV_S2U;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"U2S"))                        //~v121I~
                	Sconvopt=CONV_U2S;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"S2F"))                        //~v121I~
                	Sconvopt=CONV_S2F;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"F2S"))                        //~v121I~
                	Sconvopt=CONV_F2S;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"U2F"))                        //~v121I~
                	Sconvopt=CONV_U2F;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"F2U"))                        //~v121I~
                	Sconvopt=CONV_F2U;                             //~v121I~
                else                                               //~v121I~
                if (!stricmp(cptr,"F2E")) //euc<--utf              //~va3hI~
                {                                                  //~va3hI~
                	Sconvopt=CONV_F2S;                             //~va3hI~
                    Slesw|=UCVUCS_EUC;                             //~va3hR~
                }                                                  //~va3hI~
                else                                               //~va3hI~
                if (!stricmp(cptr,"E2F")) //euc-->utf              //~va3hI~
                {                                                  //~va3hI~
                	Sconvopt=CONV_S2F;                             //~va3hI~
                    Slesw|=UCVUCS_EUC;                             //~va3hR~
                }                                                  //~va3hI~
                else                                               //~va3hI~
//#ifdef UTF8SUPP                                                  //~va41R~
#ifdef WCSUPP                                                      //~va41I~
                if (!stricmp(cptr,"F2M")) //euc<--utf              //~va3iI~
                {                                                  //~va3iI~
                	Sconvopt=CONV_F2S;                             //~va3iI~
                    Slesw|=UCVUCS_MB;                              //~va3iI~
                }                                                  //~va3iI~
                else                                               //~va3iI~
                if (!stricmp(cptr,"M2F")) //euc-->utf              //~va3iI~
                {                                                  //~va3iI~
                	Sconvopt=CONV_S2F;                             //~va3iI~
                    Slesw|=UCVUCS_MB;                              //~va3iR~
                }                                                  //~va3iI~
                else                                               //~va3iI~
#endif                                                             //~va3iI~
#ifdef WCSUPP                                                      //~va3yI~
                if (!stricmp(cptr,"B2M")) //ebcdic-->locale        //~va3yI~
                {                                                  //~va3yI~
                	Sconvopt=CONV_E2A;                             //~va3yR~
			    	Sebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B          //~va3yI~
                }                                                  //~va3yI~
                else                                               //~va3yI~
                if (!stricmp(cptr,"B2F")) //ebcdic-->UTF8          //~va55I~
                {                                                  //~va55I~
                	Sconvopt=CONV_E2A;                             //~va55I~
			    	Sebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B          //~va55I~
                    Smiscopt|=MISC_UTF8;        //B2F/F2B          //~va55I~
                }                                                  //~va55I~
                else                                               //~va55I~
                if (!stricmp(cptr,"M2B")) //locale-->ebcdic        //~va3yI~
                {                                                  //~va3yI~
                	Sconvopt=CONV_A2E;                             //~va3yR~
			    	Sebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B          //~va3yI~
                }                                                  //~va3yI~
                else                                               //~va3yI~
                if (!stricmp(cptr,"F2B")) //UTF8  -->ebcdic        //~va55I~
                {                                                  //~va55I~
                	Sconvopt=CONV_A2E;                             //~va55I~
			    	Sebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B          //~va55I~
                    Smiscopt|=MISC_UTF8;        //F2B/B2F          //~va55I~
                }                                                  //~va55I~
                else                                               //~va55I~
                if (!stricmp(cptr,"M2M")) //any to any             //~va42I~
                {                                                  //~va42I~
                	Sconvopt=CONV_A2A;                             //~va42I~
                    Smiscopt|=MISC_M2M;                            //~va42I~
                }                                                  //~va42I~
                else                                               //~va42I~
                if (!stricmp(cptr,"B2B")) //any to any             //~va4qI~
                {                                                  //~va4qI~
                	Sconvopt=CONV_A2A;                             //~va4qI~
                    Smiscopt|=MISC_M2M|MISC_B2B;                   //~va4qI~
                }                                                  //~va4qI~
                else                                               //~va4qI~
#endif                                                             //~va3yI~
                	rc=4;                                          //~v127I~
    return rc;                                                     //~v127R~
}//xcvtypechk                                                      //~v127I~
//**********************************************************************
//* write option err msg
//**********************************************************************
void optionerr(char *Ptype,char* Pvalue)
{
	uerrexit("invalid %s option parm value(%s)\n",0,               //~v111R~
			Ptype,Pvalue);
  	return;
}//optionerr
//**********************************************************************//~v121I~
//* write option err msg                                           //~v121I~
//**********************************************************************//~v121I~
void parmconflict(char *Popt)                                      //~v130R~
{                                                                  //~v121I~
	uerrexit("%cC(Conversion type) and %s parm is conflict",       //~v130R~
	         "%cC(変換タイプ) と %s 指定が矛盾します。",           //~v130R~
			CMDFLAG_PREFIX,Popt);                                  //~v130R~
  	return;                                                        //~v121I~
}//parmconflict                                                    //~va3yR~
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//**********************
#define HELPMSG uerrhelpmsg(stdout,stderr,
//**********************
HELPMSG
//"%s:%s(%c): Code conversion on SJIS,JIS,EUC,UCS2,UTF-8,\n",        //~va47R~//~va57R~
//"%s:%s(%c): SJIS,JIS,EUC,UCS2,UTF-8,\n",                           //~va47R~//~va57R~
"%s:%s(%c): Code conversion on SJIS,JIS,EUC,UCS,UTF-8,EBCDIC,\n",  //~va57I~
"%s:%s(%c): SJIS,JIS,EUC,UCS,UTF-8,EBCDIC\n",                      //~va57I~
				PGM,VER,OSTYPE);                                   //~v111R~
HELPMSG                                                            //~va47I~
//"              Any other iconv/WindowsCP.\n",                      //~va47I~//~va57R~
//"              任意のiconv文字セット/WindowsCP コード変換 PGM。\n",//~va47I~//~va57R~
"              Any other iconv/WindowsCP/ICU.\n",                  //~va57I~
"              任意のiconv/ICU文字セット/WindowsCP コード変換 PGM。\n",//~va57I~
				PGM,VER,OSTYPE);                                   //~va47I~
HELPMSG
"format:\n",0);                                                    //~v111R~
HELPMSG
" %s  [%coptions] [ infile | - ] [outfile]\n",0,                   //~v122R~
			PGM,CMDFLAG_PREFIX);                                   //~v145R~
HELPMSG
"  infile   :Source file name. if missing,assume pipe input. \"-\" is for stdin.\n",//~v131R~
"  infile   :元ファイル名。省略するとパイプ入力。\"-\"は標準入力。\n");//~v131R~
#ifndef DOSDOS                                                     //~va1xI~
HELPMSG                                                            //~va1mI~
"            specify \"%s\" to print dbcs mapping table for b2s/s2b.\n",//~va1tR~
"            b2s/s2b のとき \"%s\"と指定するとDBCS変換テーブルを出力する。\n",//~va1tR~
				EBCPRINTID);                                       //~va1mI~
#endif                                                             //~va1xI~
HELPMSG                                                            //~v122I~
"  outfile  :Output File Name, stdout if missing.\n",              //~v131R~
"  outfile  :出力ファイル名。省略すると標準出力に出力。\n");       //~v131R~
HELPMSG                                                            //~v111I~
"  %coptions :See bellow. CaseInsensitive.\n",                     //~v131R~
"  %coptions :以下、大文字小文字区別なし。\n",                     //~v131R~
			CMDFLAG_PREFIX);                                       //~v121R~
HELPMSG                                                            //~v131I~
"    %c2errf :stderr redirect file forr errmsg.\n",                //~v131R~
"    %c2errf :標準エラー宛先ファイル。\n",                         //~v131R~
			CMDFLAG_PREFIX);                                       //~v131I~
HELPMSG                                                            //~v130R~
"    %c[C]x2y:x2y is following. (Specify as first parameter.)\n",                                //~v130R~//~vag0R~
"    %c[C]x2y:x2y は以下。(オプションパラメータとして最初に指定すること)\n",                                     //~v130R~//~vag0R~
			CMDFLAG_PREFIX);                                       //~v111R~
HELPMSG                                                            //~v121I~
"            e2s/s2e: EUC<-->SJIS.\n",0);                          //~v121I~
HELPMSG                                                            //~v121I~
"            j2s/s2j: JIS<-->SJIS.\n",0);                          //~v125R~
HELPMSG                                                            //~v126R~
"            j2e/e2j: JIS<-->EUC.\n",0);                           //~v126R~
HELPMSG                                                            //~v125M~
"            e2e,s2s: for hankaku-katakana-->zenkaku-katakana conv on EUC,SJIS.\n",//~v125M~
"            e2e,s2s: EUC/SJISの半角カタカナ-->全角カタカナ変換に使用する。\n");//~v125M~
HELPMSG                                                            //~v134I~
//"            e2a/a2e: EBCDIC(SBCS)<-->ASCII.\n",                 //~va1mR~
//"            e2a/a2e: EBCDIC(1バイト文字)<-->ASCII。\n");        //~va1mR~
"            b2s/s2b: EBCDIC<-->SJIS.\n",                          //~va1tR~
"            b2s/s2b: EBCDIC<-->SJIS。\n");                        //~va1tR~
HELPMSG                                                            //~va4hI~
"            b2e/e2b: EBCDIC<-->EUC-Japanese.\n",                  //~va4hI~
"            b2e/e2b: EBCDIC<-->EUC-Japanese。\n");                //~va4hI~
HELPMSG                                                            //~va2oI~
"            b2a/a2b: EBCDIC<-->ASCII.(Ignore SO/SI,No DBCS processing)\n",//~va2oI~
"            b2a/a2b: EBCDIC<-->ASCII。(SO/SIは無視、DBCS処理せず)\n");//~va2oI~
#ifdef WCSUPP                                                      //~va3yI~
HELPMSG                                                            //~va3yI~
"            b2m/m2b: EBCDIC<-->LOCAL CodePage by external converter(ICU/iconv)\n",//~va3yR~
"            b2m/m2b: EBCDIC<-->LOCAL CodePage。外部変換ツール(ICU/iconv)使用\n");//~va3yR~
HELPMSG                                                            //~va55I~
"            b2f/f2b: EBCDIC<-->UTF-8 by external converter(ICU/iconv)\n",//~va55I~
"            b2f/f2b: EBCDIC<-->UTF-8 。外部変換ツール(ICU/iconv)使用\n");//~va55I~
#endif                                                             //~va3yI~
//HELPMSG                                                            //~v133I~//~vbB3R~
////"            k2L/L2k: hankaku-katakana<-->alphabet Lower case.\n",//~va1xR~//~vbB3R~
////"            k2L/L2k: SJISの半角カタカナ<-->英小文字変換。\n");  //~va1xR~//~vbB3R~
//"            k2L/L2k: EBCDIC re-conversion by CP1027(L) and CP290(k) vice versa.\n",//~va1xI~//~vbB3R~
//"            k2L/L2k: CP1027(L)とCP290(k) でのEBCDIC変換のやり直し。\n");//~va1xI~//~vbB3R~
HELPMSG                                                            //~v133I~//~vbB3R~//~vbBhR~
"            k2L/L2k: hankaku-katakana(K)<-->alphabet Lower case(L).\n",//~va1xR~//~vbB3R~//~vbBhR~
"            k2L/L2k: SJISの半角カタカナ(K)<-->英小文字変換(L)。\n");  //~va1xR~//~vbB3R~//~vbBhR~
HELPMSG                                                            //~v133I~
//"                     complemetaly of EBCDIC-->ASCII conversion.\n",//~va1xR~
//"                     EBCDIC->ASCII変換後に使用。\n");           //~va1xR~
//"                     Use for EBCDIC-->ASCII converted file.\n",   //~va1xI~//~vbBhR~
//"                     EBCDIC->ASCII変換されたファイルに適用する。\n");//~va1xI~//~vbBhR~
"                     To converted ASCII file, retranslate by the other.\n",//~vbBhR~
"                     ASCII変換されたファイルを他方で再変換する。\n");//~vbBhR~
HELPMSG                                                            //~v121M~
//"            s2u,u2s: SJIS<-->UCS2 (16bit Unicode).\n",0);         //~v121R~//~va57R~
"            s2u,u2s: SJIS<-->UCS.\n",0);                          //~va57I~
HELPMSG                                                            //~v121I~
"            s2f,f2s: SJIS<-->UTF-8 (8bit Unicode Translation Format).\n",0);//~v121I~
HELPMSG                                                            //~va3hI~
"            e2f,f2e: EUC(Japanese)<-->UTF-8.\n",0);               //~va3hR~
//#ifdef UTF8SUPP                                                  //~va41R~
#ifdef WCSUPP                                                      //~va41I~
HELPMSG                                                            //~va3iI~
"            m2f,f2m: MB(LocaleCode)<-->UTF-8.\n",0);              //~va3iI~
HELPMSG                                                            //~va42I~
//"            m2m    : translation between \"%cF:\" and  \"%cT:\"\n",//~va42I~//~va4qR~
//"            m2m    : \"%cF:\", \"%cT:\" で指定するコード間の変換\n",//~va42I~//~va4qR~
"            m2m/b2b: translation between \"%cF:\" and  \"%cT:\"\n",//~va4qI~
"            m2m/b2b: \"%cF:\", \"%cT:\" で指定するコード間の変換\n",//~va4qI~
			 CMDFLAG_PREFIX,CMDFLAG_PREFIX);                       //~va42I~
HELPMSG                                                            //~va42I~
//"                     select from Windows codepageNo or iconv --list.\n",//~va42I~//~va53R~
//"                     Windowsのコードページ番号,iconv --list 中から選託\n");//~va42I~//~va53R~
"                     select from Windows CP, iconv --list, uconv -l.\n",//~va53I~
"                     Windowsのコードページ番号,iconv --list,uconv -lから選択\n");//~va53R~
HELPMSG                                                            //~va53I~
"                     For Windows Codepage and ICU\n",             //~va53R~
"                     Windows Codepage, ICU では\n");              //~va53R~
HELPMSG                                                            //~va53I~
//"                     Installed Windows codepage will be list if invalid.\n",//~va53I~
//"                     Windowsでは間違えると導入済みのCPがリストされます\n");//~va53R~
//"                     use,for ex,\"F:?\" to list candidate.\n",    //~va53I~//~va59R~
//"                     指定可\x94\\な値は 例えば \"F:?\" でリストされます\n");//~va53R~//~va59R~
"                     use \"%c%s\" to list candidate.\n",          //~va59I~
"                     指定可\x94\\な値は \"%c%s\" でリストされます\n",//~va59I~
						CMDFLAG_PREFIX,OPTLIST);                   //~va59I~
#endif                                                             //~va53I~
HELPMSG                                                            //~v121M~
//"            u2f,f2u: UCS2<-->UTF-8.\n",0);                        //~v121R~//~va57R~
"            u2f,f2u: UCS<-->UTF-8.\n",0);                         //~va57I~
HELPMSG                                                            //~va4pI~
//"    %c%s:cp :EBCDIC codepage for B2M/M2B. Alternative of %cMF:mapfile option.\n",//~va4pR~//~vag0R~
//"    %c%s:cp :EBCDIC コードページ。 B2M/M2B用。%cMF:mapfile の代わり。\n",//~va4pI~//~vag0R~
//			CMDFLAG_PREFIX,OPTCPEB,CMDFLAG_PREFIX);                //~va4pI~//~vag0R~
"    %c%s:cp :EBCDIC codepage for B2M/M2B.\n",                     //~vag0I~
"    %c%s:cp :EBCDIC コードページ。 B2M/M2B用。\n",                //~vag0I~
			CMDFLAG_PREFIX,OPTCPEB);                               //~vag0I~
HELPMSG                                                            //~v128I~
"    %cEnn   :conv err max msg output count. default=%d.\n",       //~v128R~
"    %cEnn   :変換エラーMSG最大出力。省略値=%d。\n",               //~v128R~
			CMDFLAG_PREFIX,MAXERRPRINT);                           //~v128I~
#ifdef WCSUPP                                                      //~va3yI~
HELPMSG                                                            //~va42I~
"    %cF:from:For m2m/b2b, codepage translated from.\n",               //~va42I~//~va54R~
"    %cF:from:変換元コードページ。m2m/b2b で使用\n",                   //~va42R~//~va54R~
			CMDFLAG_PREFIX);                                       //~va42I~
#ifdef W32                                                         //~va42I~
HELPMSG                                                            //~va42I~
"            Default is \"0\"(CP_ACP). \"UTF8\" is alternative of 65001.\n",//~va47R~
"            省略値は \"0\"(CP_ACP). 65001の代わりに\"UTF8\"でも良い。\n");//~va47R~
#else                                                              //~va42I~
HELPMSG                                                            //~va42I~
"             Determined using \"locale -a\" if not specified.\n", //~va46I~
"             指定がないと\"locale -a\"で調べて決める。\n");       //~va46I~
#endif                                                             //~va42I~
HELPMSG                                                            //~va3yI~
"    %cF[nn][N]:EBCDIC file is fixed record length. nn:LRECL(default=%d).\n",//~va3zR~
"    %cF[nn][N]:EBCDIC ファイルが固定長。nn:LRECL(省略値=%d)。\n", //~va3zR~
			CMDFLAG_PREFIX,EBC_DEFAULT_LRECL);                     //~va3yI~
HELPMSG                                                            //~va3yI~
//"              Effective for x2b/b2x(x:a,s,m) only.\n",            //~va40R~//~va4hR~
//"              x2b/b2x(x:a,s,m) でのみ有効。\n");                  //~va40R~//~va4hR~
//"              Effective for x2B/B2x(x:a,s,e,m) only.\n",          //~va4hI~//~va4jR~
//"              x2B/B2x(x:a,s,e,m) でのみ有効。\n");                //~va4hI~//~va4jR~
"              Input(B2x) or Output(x2B) LRECL.\n",                //~va4jI~
"              B2x(入力) 又は x2B(出力) EBCDIC ファイルのLRECL。\n");//~va4jI~
HELPMSG                                                            //~va3yI~
"              N: last 8 byte is line-number-filed. adjust SO/SI insertion.\n",//~va3yR~
"              N: 行末8桁が行番号欄。SO/SI挿入で行長を調整する。\n");//~va3yR~
HELPMSG                                                            //~va3yI~
"                 \"N\" is effective for m2b only.\n",             //~va3yR~
"                 \"N\" は m2b でのみ有効。\n");                   //~va3yR~
#endif                                                             //~va3yI~
HELPMSG                                                            //~va57M~
"    %cICU     :for B2x/x2B(x:B/M/F), specify use ICU when %cMF: is omitted.\n",//~va57R~//~vag0R~
"    %cICU     :B2x/x2B(x:B/M/F)のとき %cmf:の指定無しで ICU 使用の指定。\n",//~va57R~
			CMDFLAG_PREFIX,                                        //~va57I~
			CMDFLAG_PREFIX);                                       //~va57M~
//HELPMSG                                                            //~va63I~//~vag0R~
//"              for M2M, use ICU.\n",                               //~va63R~//~vag0R~
//"              あるいは M2M で ICU 使用の指定。\n",                         //~va63R~//~vag0R~
//            CMDFLAG_PREFIX,                                        //~va63I~//~vag0R~
//            CMDFLAG_PREFIX);                                       //~va63I~//~vag0R~
HELPMSG                                                            //~vag0I~
"              If %cMF:mapfile option is not specified,\n",        //~vag0I~
"              %cMF:mapfile を指定しない場合は\n",                 //~vag0I~
			CMDFLAG_PREFIX);                                       //~vag0I~
HELPMSG                                                            //~vag0I~
#ifdef W32                                                         //~vag0I~
"              set PATH to uconv.exe or ICU library(.dll)\n",      //~vag0I~
"              uconv.exe, ICU library(.dll)にPATH を通すこと\n");  //~vag0I~
#else                                                              //~vag0I~
"              Set PATH to uconv and LD_LIBRARY_PATH to ICU library(.so)\n",//~vag0I~
"              uconv に PATH, ICU library(.so) にLD_LIBRARY_PATH を通すこと\n");//~vag0I~
#endif                                                             //~vag0I~
HELPMSG                                                            //~vat1M~
"    %cICU_DATA:For %cList, directory containing icudt*.dat.\n",   //~vat1R~
"    %cICU_DATA:%cListのとき icudt*.dat を含むディレクトリーの指定。\n",//~vat1R~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~vat1R~
#ifdef W32                                                         //~vat1I~
HELPMSG                                                            //~vat1M~
"              Alternative of %cMF.\n",                            //~vat1R~
"              %cMF の代わりに指定\n",                             //~vat1R~
			CMDFLAG_PREFIX);                                       //~vat1R~
HELPMSG                                                            //~vat1I~
"              Windows default is %s.\n",                          //~vat1I~
"              Winowsの省略値は %s\n",                             //~vat1I~
			ICU_DATADIR_DEFAULT_WINDOWS);                          //~vat1I~
#else                                                              //~vat1I~
HELPMSG                                                            //~vat1I~
"              Alternative of %cMF. No need when PATH is set to uconv.\n",//~vat1R~
"              %cMF の代わり。uconv への PATH があれば不要\n",     //~vat1I~
			CMDFLAG_PREFIX);                                       //~vat1R~
#endif                                                             //~vat1I~
//HELPMSG                                                          //~v122R~
//"    %cMxy   :End-Of-Line-ID specification. x for input, y for output.\n",//~v122R~
//"    %cMxy   :改行文字指定。x は 読みこみ用、y は書き込み用で以下を指定。\n",//~v122R~
//            CMDFLAG_PREFIX);                                     //~v122R~
//HELPMSG                                                          //~v122R~
//"            (for not Unicode conversion)\n",                    //~v122R~
//"            (Unicode変換以外の時有効)\n",                       //~v122R~
//            CMDFLAG_PREFIX);                                     //~v122R~
//HELPMSG                                                          //~v122R~
//"            p:0x0D0A.  u:0x0A.  m:0x0D.  b:ignore EOL(for UCS2,UTF-8)\n",//~v122R~
//"            p:0x0D0A。 u:0x0A。 m:0x0D。 b:EOLを無視(UCS2,UTF-8用)。\n");//~v122R~
//HELPMSG                                                          //~v122R~
//"            t:for input,p or u. for output, p under PC, u under UNIX\n",//~v122R~
//"            t:入力指定の時 p 又は u。出力指定の時 PCでは p,UNIXでは u。\n");//~v122R~
//HELPMSG                                                          //~v122R~
//"            default is /Mtp under PC, -Mtu under UNIX.\n",      //~v122R~
//"            省略値は PC では　/Mtp UNIX では　-Mtu。\n");       //~v122R~
HELPMSG                                                            //~va59I~
"    %cList  :list ICU converter(with %cICU option) or Windows Codepage.\n",//~va59R~
"    %cList  :ICUコンバーター(%cICU指定時)またはWindowsコードページをリスト。\n",//~va59R~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~va59I~
#ifdef LNX                                                         //~va3iR~
HELPMSG                                                            //~va3iI~
"    %cLlocale:LocaleCode for m2f/f2m conversion.\n",              //~va3iI~
"    %cLlocale:m2f/f2mで使用するロケールコード。\n",               //~va3iI~
			CMDFLAG_PREFIX);                                       //~va3iI~
HELPMSG                                                            //~va3iI~
"             Determined using \"locale -a\" if not specified.\n", //~va3iR~
"             指定がないと\"locale -a\"で調べて決める。\n");       //~va3iR~
HELPMSG                                                            //~va3mM~
"             ex) -Leucjp , -Lsjis , -Liso88591\n",                //~va3mR~
"             ex) -Leucjp , -Lsjis , -Liso88591\n");               //~va3mR~
#endif                                                             //~va3iI~
HELPMSG                                                            //~v130I~
"    %cMxxx  :optional mapping type. \n",                          //~v130R~
"    %cMxxx  :マッピングオプション。\n",                           //~v130R~
			CMDFLAG_PREFIX);                                       //~v130I~
HELPMSG                                                            //~va1rM~
"            (specify multiple like as \"%cmJIS78 %cmNEC\" if required.)\n",//~va1rI~
"            (必要なら \"%cmJIS78 %cmNEC\" のように複数指定してください。)\n",//~va1rI~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~va1rM~
HELPMSG                                                            //~v130M~
"            CP943C / MS932 / SJIS(default). use with s2u,stf.\n", //~v130R~
"            CP943C / MS932 / SJIS(省略値)。s2u,s2fで使用。\n");   //~v130R~
HELPMSG                                                            //~v130I~
"              Mapping selection for the code SJIS:Unicode=1:n.\n",//~v130I~
"              SJIS:Unicode=1:n のコードのときどのMappingをとるか選択する。\n");//~v130I~
HELPMSG                                                            //~v130I~
//"            NEC / IBM(default). use with u2s,f2s.\n",           //~va1mR~
//"            NEC / IBM(省略値)。u2s,f2sで使用。\n");             //~va1mR~
"            NEC / IBM(default). use with u2s,f2s,b2s.\n",         //~va1tR~
"            NEC / IBM(省略値)。u2s,f2s,b2sで使用。\n");           //~va1tR~
HELPMSG                                                            //~v130I~
//"              Mapping selection for the code SJIS:Unicode=n:1.\n",//~va1mR~
//"              SJIS:Unicode=n:1 のコードのときどの領域のSJISにMappingするか。\n");//~va1mR~
"              Mapping selection for the code SJIS:Unicode/EBCDIC=n:1.\n",//~va1mI~
"              SJIS:Unicode/EBCDIC=n:1 の時どの領域のSJISにMappingするか。\n");//~va1mR~
HELPMSG                                                            //~v130I~
"              IBM:IBM Selected, NEC:NEC selected or NEC's IBM Selected.\n",//~v130I~
"              IBM:IBM拡張文字、NEC:NEC特殊文字ないしNEC選定IBM拡張文字。\n");//~v130R~
HELPMSG                                                            //~va1sI~
//"            SBCS: use with b2s,s2b,no DBCS consideration.\n",     //~va1tR~//~va4hR~
//"            SBCS: b2s,s2bで使用。すべて一バイト文字として変換\n");//~va1tR~//~va4hR~
"            SBCS: use with B2x,x2B,no DBCS consideration.\n",     //~va4hI~
"            SBCS: B2x,x2Bで使用。すべて一バイト文字として変換\n");//~va4hI~
HELPMSG                                                            //~v134I~
//"            ANK / CRLF. use with b2s,s2b.\n",                     //~va1tR~//~va4hR~
//"            ANK / CRLF。b2s,s2bで使用。\n");                      //~va1tR~//~va4hR~
//"            ANK / CRLF. use with B2x,x2B.\n",                     //~va4hI~//~vbBuR~
//"            ANK / CRLF。B2x,x2Bで使用。\n");                      //~va4hI~//~vbBuR~
"            ANK / CRLF / CRLFZ. use with B2x,x2B.\n",             //~vbBuI~
"            ANK / CRLF / CRLFZ。B2x,x2Bで使用。\n");              //~vbBuI~
HELPMSG                                                            //~v134I~
"              ANK:translate ctl char to '?'. CRLF:translate CR,LF and ANK.\n",//~v134R~
"              ANK:制御文字は'?'に変換。CRLF:制御文字は CR と LF のみ変換。\n");//~v134I~
HELPMSG                                                            //~vbBuI~
"              CRLFZ: Both NL(0x15) and CR+CR(0x0d15) are EndOfLine of EBCDIC.\n",//~vbBuR~
"              CRLFZ: NL(0x15) と CR+NL(0x0d15) 両方で EBC ファイルを行分割\n");//~vbBuR~
HELPMSG                                                            //~va4jI~
#ifdef UNX                                                         //~va4jI~
"            ASCEOL: EBCDIC file EOL-ID is 0x0a. Default:0x%02x.\n",//~va4jR~
"            ASCEOL: EBCDIC ファイルの行末コードが 0x0a。省略値:0x%02x。\n",//~va4jR~
#else                                                              //~va4jI~
"            ASCEOL: EBCDIC file EOL-ID is 0x0d0a. Default:0x%02x.\n",//~va4jI~
"            ASCEOL: EBCDIC ファイルの行末コードが 0x0d0a。省略値:0x%02x。\n",//~va4jI~
#endif                                                             //~va4jI~
					EBC_NL);                                       //~va4jI~
//HELPMSG                                                            //~va3zI~//~va4jR~
//"            SETEOL: append EOL-ID(0x0a) each line, a2b/s2b/m2b/m2m only.\n",//~va47R~//~va4jR~
//"            SETEOL: 出力各行にEOL(0x0a)を追加出力。a2b/s2b/m2b/m2m 用\n");//~va47R~//~va4jR~
//HELPMSG                                                            //~va4hI~//~va4jR~
//"                    For B2x, input EndOfLineID is ignored.\n",    //~va4hI~//~va4jR~
//"                    B2x ではさらに入力の改行コードは変換されない。\n");//~va4hR~//~va4jR~
HELPMSG                                                            //~va4jI~
//"            SETEOL: append EOL-ID to each line. use for x2B and RecordMode B2x.\n",//~va4jR~//~va4iR~//~va4jR~//~va4kR~
//"            SETEOL: 出力各行にEOL-IDを追加出力。x2B と レコードモード B2x用。\n");//~va4jI~//~va4iR~//~va4jR~//~va4kR~
"            SETEOL: append EOL-ID to each line. for m2m, x2B, RecordMode B2x.\n",//~va4kR~
"            SETEOL: 出力各行にEOL-IDを追加出力。m2m, x2B, レコードモード B2x用\n");//~va4kR~
HELPMSG                                                            //~va1mI~
//"            JIS78 / JIS83(default). use with b2s,s2b.\n",         //~va1tR~//~va4hR~
//"            JIS78 / JIS83(省略値)。b2s,s2bで使用。\n");           //~va1tR~//~va4hR~
"            JIS78 / JIS83(default). use with B2x,x2B.\n",         //~va4hI~
"            JIS78 / JIS83(省略値)。B2x,x2Bで使用。\n");           //~va4hI~
HELPMSG                                                            //~va1mI~
"              JIS78(old) or JIS83(new) mapping seq.(28 pair,56 char affected)\n",//~va1mR~
"              新JIS 旧JISを指定。新旧で28対56文字が入れ替わっている。\n");//~va1mR~
HELPMSG                                                            //~va1xI~
//"            CP290:use CP290 for alternative of CP1027 tbl. use with b2s,s2b.\n",//~va1xR~//~va4hR~
//"            CP290:CP1027(省略値)の代わりにCP290変換TBL使用。 b2s,s2b で使用。\n");//~va1xR~//~va4hR~
//"            CP290:use CP290 for alternative of CP1027 tbl. use with B2x,x2B.\n",//~va4hI~//~vataR~
//"            CP290:CP1027(省略値)の代わりにCP290変換TBL使用。 B2x,x2B で使用。\n");//~va4hI~//~vataR~
"            CP290/CP037:use CP290 or CP037 for alt of CP1027 tbl.(B2x,x2B).\n",//~vataI~
"            CP290/CP037:CP1027の代わりにCP290/CP037変換TBL使用。 B2x,x2B で使用\n");//~vataI~
HELPMSG                                                            //~va1xI~
//"              CP290:Japanese Katakana Extension. CP1027:Latin Extension.\n",//~va1xI~//~vataR~
//"              CP290:カタカナ拡張。CP1027:英小文字拡張。\n");      //~va1xI~//~vataR~
"              CP290:Japanese Katakana Extension. CP1027:Japanese English Ext.\n",//~vataI~
"              CP290:カタカナ拡張。CP1027:英小文字拡張。\n");      //~vataI~
HELPMSG                                                            //~vataI~
"              CP037:Latin and ISO8859-1.\n",                      //~vataI~
//"              CP037:ラテン拡張、CP037 と ISO-88591。\n");         //~vataI~//~vbBsR~
"              CP037:ラテン１ と ISO-88591。\n");                  //~vbBsI~
HELPMSG                                                            //~va4hI~
//"              \"KANA-EXT\":CP290, \"ENG-EXT\":CP1027.\n",         //~va4hR~//~vataR~
//"              \"KANA-EXT\":カタカナ拡張。\"ENG-EXT\":英小文字拡張。\n");//~va4hR~//~vataR~
//"              \"KANA-EXT\":CP290, \"ENG-EXT\":CP1027, \"LATIN-EXT\":CP037.\n",//~vataI~//~vbBsR~
//"              \"KANA-EXT\":カタカナ,\"ENG-EXT\":英小文字,\"LATIN-EXT\":ラテン\n");//~vataI~//~vbBsR~
"              \"KANA-EXT\":CP290, \"ENG-EXT\":CP1027.\n",         //~vbBsI~
"              \"KANA-EXT\":カタカナ,\"ENG-EXT\":英小文字\n");     //~vbBsI~
#ifdef WCSUPP                                                      //~va3yI~
HELPMSG                                                            //~va3yI~
//"    %cMF:mapfile :mapping parameter file for B2M/M2B transplation. \n",//~va3yI~//~va4qR~
//"    %cMF:mapfile :B2M/M2B用マッピングパラメータファイル。\n",     //~va3yI~//~va4qR~
"    %cMF:mapfile :mapping parameter file for B2M/M2B/B2B transplation. \n",//~va4qI~
"    %cMF:mapfile :B2M/M2B/B2B 用マッピングパラメータファイル。\n",//~va4qI~
			CMDFLAG_PREFIX);                                       //~va3yI~
HELPMSG                                                            //~va3yI~
"                  (See CV command description in xee.txt)\n",     //~va3yI~
"                  (cv コマンドの説明(xej.txt内)を参照)\n");       //~va3yI~
HELPMSG                                                            //~va4pI~
"                 %c%s:cp is alternative of this option.\n",        //~va4pR~//~va4qR~
"                 %c%s:cp で EBCDIC コードページを指定しても良い\n",//~va4pR~
			CMDFLAG_PREFIX,OPTCPEB);                               //~va4pI~
HELPMSG                                                            //~va4qI~
//"                 But, required to use ICU converter.\n",          //~va4qI~//~va57R~
//"                 但し、ICUのコードページを使用する場合は必要。\n");//~va4qI~//~va57R~
"                 But, To use ICU, specify in this file or use %cICU.\n",//~va57R~
"                 但し、ICUを使用する場合は%cICUかこのファイル内で指定\n",//~va57R~//~vag0R~
			CMDFLAG_PREFIX);                                       //~va57I~
#endif                                                             //~va3yI~
HELPMSG                                                            //~v123I~
"    %cOfnm  :same as outfile parm. e.g) -oOutFile\n",                            //~v122R~//~vastR~
"    %cOfnm  :outfile パラメータに同じ。 e.g) -oOutFile\n",                       //~v122R~//~vastR~
			CMDFLAG_PREFIX);                                       //~v123I~
HELPMSG                                                            //~v134I~
"    %cRx    :1 byte char to replace translation err code. ex, %cr: %cr'^'.\n",//~v134I~
"    %cRx    :無効な変換不\x94\\文字を置きかえる文字。%cr: %cr'^' 等。\n",//~v134R~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~v134I~
HELPMSG                                                            //~v134M~
//"            Default is '?'. Use only with u2s,f2s,b2s and s2b.\n",//~va42R~
//"            省略値は '?'。u2s,f2s,b2s,s2b でのみ使用。\n");     //~va42R~
//"            Default is '?'. Use only with u2s,f2s,b2s,s2b and m2m.\n",//~va42I~//~va4hR~
//"            省略値は '?'。u2s,f2s,b2s,s2b,m2m でのみ使用。\n");   //~va42I~//~va4hR~
"            Default is '?'. Use only with u2s,f2s,B2x,x2B and m2m.\n",//~va4hI~
"            省略値は '?'。u2s,f2s,B2x,x2B,m2m でのみ使用。\n");   //~va4hI~
HELPMSG                                                            //~v129I~
"            2 byte hex digit notation is available. ex, %cr7f.\n",//~v134R~
"            2 バイトヘキサ文字指定も可\x94\\。%cr7f 等｡\n",       //~v134R~
			CMDFLAG_PREFIX);                                       //~v132I~
HELPMSG                                                            //~va1nI~
"            for DBCS,specify 2 byte char or 4 hex digit.default is DBCS \"?\".\n",//~va1nR~
"            DBCS置換文字は 2 桁文字か 4 桁ヘキサ数値で指定。省略値は\"？\"。\n");//~va1nR~
HELPMSG                                                            //~va1nI~
"            specify both if required like as \"%cr. %cr8148\".\n",//~va1nR~
"            両方必要なときは \"%cr. %cr。\" のように指定する。\n",//~va1nR~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~va1nI~
HELPMSG                                                            //~va1pI~
//"    %cSx    :SO(%02x)/SI(%02x) handling option for b2s/s2b.\n",   //~va1tR~//~va4hR~
//"    %cSx    :b2s/s2b で SO(%02x)/SI(%02x)の取り扱いオプション。\n",//~va1tR~//~va4hR~
"    %cSx    :SO(%02x)/SI(%02x) handling option for B2x/x2B.\n",   //~va4hI~
"    %cSx    :B2x/x2B で SO(%02x)/SI(%02x)の取り扱いオプション。\n",//~va4hI~
			CMDFLAG_PREFIX,CHAR_SO,CHAR_SI);                       //~va1pI~
HELPMSG                                                            //~va1pI~
//"            for b2s; x=d:Delete. x=a:Assume SO before the line.\n",//~va1tR~//~va4hR~
//"            b2s の場合; x=d:削除。x=a:SOが行頭にあると想定。\n"); //~va1tR~//~va4hR~
"            for B2x; x=d:Delete. x=a:Assume SO before the line.\n",//~va4hI~
"            B2x の場合; x=d:削除。x=a:SOが行頭にあると想定。\n"); //~va4hI~
HELPMSG                                                            //~va1rI~
//"                     default: Replace SO/SI by space.\n",         //~va1rR~//~va4mR~
//"                        省略値は SO/SI をスペースに置換。\n");    //~va1rR~//~va4mR~
"                        x=r:Replace SO/SI by space.\n",           //~va4mR~
"                        x=r:SO/SI をスペースに置換。\n");         //~va4mR~
HELPMSG                                                            //~va4mI~
"                        This option override option of mapping file for B2m.\n",//~va4mI~
"                        B2mの場合、mappingファイルのオプションを上書きする。\n");//~va4mR~
HELPMSG                                                            //~va1pI~
//"            for s2b; x=r:replace if boundary is space char else insert SO/SI.\n",//~va1tR~//~va4mR~
//"            s2b の場合; x=r:前後がスペースなら置換、そうでないときは挿入。\n");//~va1tR~//~va4mR~
"            for m2B; x=r:replace if boundary is space char else insert SO/SI.\n",//~va4mI~
"            x2B の場合; x=r:前後がスペースなら置換、そうでないときは挿入。\n");//~va4mR~
HELPMSG                                                            //~va3wI~
"                     x=s:replace and shrink following space if inserted.\n",//~va3wR~
"                        x=s:スペース置換だが、挿入分は後続のスペースを縮める。\n");//~va3wI~
HELPMSG                                                            //~va1qI~
//"                     x=d:No SO/SI is set. default:Insert SO/SI.\n",//~va1rR~//~va4mR~
//"                        x=d:SO/SIを設定しない。省略値はSO/SIを挿入。\n");//~va1rR~//~va4mR~
"                     x=d:No SO/SI is set. x=i:Insert SO/SI.\n",   //~va4mR~
"                        x=d:SO/SIを設定しない。x=i:SO/SIを挿入。\n");//~va4mR~
HELPMSG                                                            //~va4mI~
"                        This option override option of mapping file for m2B.\n",//~va4mI~
"                        m2Bの場合、mappingファイルのオプションを上書きする。\n");//~va4mR~
#ifdef WCSUPP                                                      //~va42I~
HELPMSG                                                            //~va42I~
"    %cT:to  :For m2m/b2b, codepage translated to.\n",                 //~va42R~//~va54R~
"    %cT:to  :変換先コードページ。m2m/b2b で使用\n",                   //~va42R~//~va54R~
			CMDFLAG_PREFIX);                                       //~va42I~
#ifdef W32                                                         //~va42I~
HELPMSG                                                            //~va46I~
"            Default is \"0\"(CP_ACP). \"UTF8\" is alternative of 65001.\n",//~va47R~
"            省略値は \"0\"(CP_ACP). 65001の代わりに\"UTF8\"でも良い。\n");//~va47R~
#else                                                              //~va42I~
HELPMSG                                                            //~va42I~
"             Determined using \"locale -a\" if not specified.\n", //~va46I~
"             指定がないと\"locale -a\"で調べて決める。\n");       //~va46I~
#endif                                                             //~va42I~
#endif                                                             //~va42I~
#ifdef UNX                                                         //~va1cI~
HELPMSG                                                            //~va1cI~
//"    %c\\\\u   :input is \\uxxxx format unicode.\n",             //~va2fR~
//"    %c\\\\u   :入力のユニコードが\\uxxxx \x95\\記である。\n",   //~va2fR~
"    %c\\\\u   :DBCS unicode by \\uxxxx format.\n",                //~va2fR~
"    %c\\\\u   :DBCSのユニコードが\\uxxxx \x95\\記。\n",           //~va2fR~
			CMDFLAG_PREFIX);                                       //~va1cI~
#else                                                              //~va1cI~
HELPMSG                                                            //~va1cI~
//"    %c\\u    :input is \\uxxxx format unicode.\n",              //~va2fR~
//"    %c\\u    :入力のユニコードが\\uxxxx \x95\\記である。\n",    //~va2fR~
"    %c\\u    :DBCS unicode by \\uxxxx format.\n",                 //~va2fR~
"    %c\\u    :DBCSのユニコードが\\uxxxx \x95\\記。\n",            //~va2fR~
			CMDFLAG_PREFIX);                                       //~va1cI~
#endif                                                             //~va1cI~
HELPMSG                                                            //~v111I~
"    %cYx,%cNx:toggle type switch; x is as following.default is in ( ).\n",//~v121R~
"    %cYx,%cNx:Yes/No フラグオプション、x は以下。省略値は ( )内。\n",//~v121R~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~v111I~
HELPMSG                                                            //~va57I~
"            4  :4 byte unicode(==>0x10ffff).(%cN4)\n",            //~va57I~
"            4  :4 バイトユニコード(%cN4)\n",                      //~va57I~
			CMDFLAG_PREFIX);                                       //~va57I~
HELPMSG                                                            //~v121I~
"            b  :UTF-8 BOM check(input) or write(output).(%cNb)\n",//~v121I~
"            b  :UTF-8 File読みこみ時先頭 BOM をCHK,書きこみ時BOMを出力。(%cNb)\n",//~v121I~
			CMDFLAG_PREFIX);                                       //~v121I~
//HELPMSG                                                          //~va1sR~
//"            d  :japanese DBCS conversion for b2s/s2b.(%cYd)\n", //~va1sR~
//"            d  :b2s/s2b の時の日本語(DBCS)変換の有無。(%cYd)\n",//~va1sR~
//            CMDFLAG_PREFIX);                                     //~va1sR~
HELPMSG                                                            //~vas8M~
"            h  :input by hex code. (%cYh for stdin else %cNh)\n",//~vas8I~//~vasaR~
"            h  :入力はHexコード。省略値は標準入力は%cYh 以外は%cNh。\n",//~vasaI~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~vasaR~
#ifdef ARM                                                         //~vasuI~
HELPMSG                                                            //~vasuI~
"            i  :Use ICU for M2M(%cYi)\n",                         //~vasuR~
"            i  :M2M で ICU 使用の指定。(%cYi)\n",                 //~vasuI~
			CMDFLAG_PREFIX);                                       //~vasuI~
#else                                                              //~vasuI~
HELPMSG                                                            //~vasuI~
"            i  :Use ICU for M2M(%cNi)\n",                         //~vasuR~
"            i  :M2M で ICU 使用の指定。(%cNi)\n",                 //~vasuI~
			CMDFLAG_PREFIX);                                       //~vasuI~
#endif                                                             //~vasuI~
HELPMSG                                                            //~v121I~
"            L  :Unicode File is Little Endian(%c%cL)\n",          //~va1mR~
"            L  :Unicode File をLittleEndianで読み書きする。(%c%cL)\n",//~va1mR~//~va4jR~
			CMDFLAG_PREFIX,                                        //~v121I~
#ifdef UNX                                                         //~v121I~
				'N');                                              //~v121R~
#else                                                              //~v121I~
				'Y');                                              //~v121R~
#endif                                                             //~v121I~
HELPMSG                                                            //~v122I~
"            m  :Mac file input(EndOfLine ID is 0x0d).(for not UCS conv).(%cNm)\n",//~v122R~
"            m  :入力がMac形式(EndOfLine ID が 0x0d)。(UCS変換以外で使用).(%cNm)\n",//~v122R~
			CMDFLAG_PREFIX);                                       //~v122I~
HELPMSG                                                            //~vas8I~
"            q  :just exit for input from stdin.(%cNq)\n",         //~vas8I~
"            q  :標準入力の時１回の処理で終了する。(%cNq)\n",      //~vas8I~
			CMDFLAG_PREFIX);                                       //~vas8I~
HELPMSG                                                            //~vas8I~
"            x  :output by hex notation. X:uppercase output. (%cNx)\n",//~vas8R~
//"            x  :Hex表示で出力。Xは大文字出力。(%cNx)\n",          //~vas8R~//~vas9R~
"            x  :Hex\x95\\示で出力。Xは大文字出力。(%cNx)\n",      //~vas9I~
			CMDFLAG_PREFIX);                                       //~vas8R~
HELPMSG                                                            //~v111I~
"            z  :conv hankaku-katakana to zenkaku among EUC,JIS and SJIS.(%cNz)\n",//~v125R~
"            z  :SJIS<->EUC<->JIS変換で半角カタカナを全角カタカナにする。(%cNz)\n",//~v125R~
			CMDFLAG_PREFIX);                                       //~v111I~
HELPMSG                                                            //~v122I~
" ex) %s %ccs2u sjis1 | %s %cu2s >sjis2; %s %cj2s -; %s %ccu2f %cYLb ucsbe1 %cof1\n",//~v130R~
" 例) %s %ccs2u sjis1 | %s %cu2s >sjis2; %s %cj2s -; %s %ccu2f %cYLb ucsbe1 %cof1\n",//~v130R~
		PGM,CMDFLAG_PREFIX,PGM,CMDFLAG_PREFIX,PGM,CMDFLAG_PREFIX,PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v122R~
HELPMSG                                                            //~v122I~
"     %s %cce2s %cyz euc1 sjis3; %s %cu2s %cr\"/\" %cmNEC ucsdata sjis1 \n",//~v132R~
"     %s %cce2s %cyz euc1 sjis3; %s %cu2s %cr\"/\" %cmNEC ucsdata sjis1 \n",//~v132R~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,                         //~v132R~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~v132I~
#ifdef WCSUPP                                                      //~va46I~
HELPMSG                                                            //~va46I~
//"     %s %ccm2b ms932 ibm939.txt  %cmf:sjisebc.map %cF80 %cMseteol\n",//~va46R~//~va4jR~
//"     %s %ccm2b ms932 ibm939.txt  %cmf:sjisebc.map %cF80 %cMseteol\n",//~va46R~//~va4jR~
//        PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4jI~
"     %s %ccm2b ms932 ibm939.txt  %cmf:sjisebc.map %cF80 %cMseteol %cMasceol\n",//~va4jR~
"     %s %ccm2b ms932 ibm939.txt  %cmf:sjisebc.map %cF80 %cMseteol %cMasceol\n",//~va4jI~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va46R~//~va4jR~
HELPMSG                                                            //~va4jI~
"         (locale-->ebcdic, output LRECL=80, set ASCII-EOL-ID)\n", //~va4jI~
"         (locale-->ebcdic, output LRECL=80, set ASCII-EOL-ID)\n");//~va4jI~
HELPMSG                                                            //~va4jI~
"     %s %ccm2b ms932 ibm939.txt %cmf:sjisebc.map  %cMasceol %cMseteol\n",//~va4jR~
"     %s %ccm2b ms932 ibm939.txt %cmf:sjisebc.map  %cMasceol %cMseteol\n",//~va4jR~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4jI~
HELPMSG                                                            //~va4jI~
"         (locale-->ebcdic, output line with appened ASCII-EOL)\n",//~va4jI~//~va56R~
"         (locale-->ebcdic, output line with appened ASCII-EOL)\n");//~va4jI~//~va56R~
HELPMSG                                                            //~va4jI~
"     %s %ccb2m ebcf1 ascf2 %cmf:sjisebc.map %cF80 %cMseteol\n",   //~va4jR~
"     %s %ccb2m ebcf1 ascf2 %cmf:sjisebc.map %cF80 %cMseteol\n",   //~va4jR~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4jI~
HELPMSG                                                            //~va4jI~
"         (locale<--ebcdic, input LRECL=80, output line with appened ASCII-EOL)\n",//~va4jI~//~va56R~
"         (locale<--ebcdic, input LRECL=80, output line with appened ASCII-EOL)\n");//~va4jI~//~va56R~
HELPMSG                                                            //~va4jI~
"     %s %ccb2m ebcf1 ascf2 %cmf:sjisebc.map %cMasceol\n",         //~va4jR~
"     %s %ccb2m ebcf1 ascf2 %cmf:sjisebc.map %cMasceol\n",         //~va4jR~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4jI~
HELPMSG                                                            //~va4jI~
"         (locale<--ebcdic, input line with ASCII-EOL-ID\n",       //~va4jI~
"         (locale<--ebcdic, input line with ASCII-EOL-ID\n");      //~va4jI~
HELPMSG                                                            //~va4pI~
//"     %s %ccb2m ebcf1 ascf2 %c%s:%s\n",                            //~va4pI~//~vatcR~
//"     %s %ccb2m ebcf1 ascf2 %c%s:%s\n",                            //~va4pI~//~vatcR~
"     %s %ccb2m ebcf1 ascf2 %cmf:mapcv1 %c%s:%s\n",                //~vatcI~
"     %s %ccb2m ebcf1 ascf2 %cmf:mapcv1 %c%s:%s\n",                //~vatcI~
//		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,OPTCPEB,                 //~vatcI~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,                         //~vatcR~
		CMDFLAG_PREFIX,                                            //~vatcI~
		OPTCPEB,                                                   //~vatcI~
  #ifdef W32                                                       //~va4pI~
  		"37");                                                     //~va4pI~
  #else                                                            //~va4pI~
  		"CP037");                                                  //~va4pI~
  #endif                                                           //~va4pI~
HELPMSG                                                            //~va46I~
  #ifdef W32                                                       //~va46I~
//"     %s %ccm2m latin1 latin15 %cf:28591 %ct:28605\n",             //~va46I~//~va4kR~
//"     %s %ccm2m latin1 latin15 %cf:28591 %ct:28605\n",             //~va46I~//~va4kR~
"     %s %ccm2m latin1 latin15 %cMseteol %cf:28591 %ct:28605\n",   //~va4kI~
"     %s %ccm2m latin1 latin15 %cMseteol %cf:28591 %ct:28605\n",   //~va4kI~
  #else                                                            //~va46I~
//"     %s %ccm2m latin1 latin15 %cf:ISO-8859-1 %ct:ISO-8859-15\n",  //~va46I~//~va4kR~
//"     %s %ccm2m latin1 latin15 %cf:ISO-8859-1 %ct:ISO-8859-15\n",  //~va46I~//~va4kR~
"     %s %ccm2m latin1 latin15 %cMseteol %cf:ISO-8859-1 %ct:ISO-8859-15\n",//~va4kI~
"     %s %ccm2m latin1 latin15 %cMseteol %cf:ISO-8859-1 %ct:ISO-8859-15\n",//~va4kI~
  #endif                                                           //~va46I~
//  	PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);         //~va46I~//~va4kR~
  		PGM,                                                       //~va4kI~
		CMDFLAG_PREFIX,                                            //~va4kI~
		CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);             //~va4kI~
HELPMSG                                                            //~va4qI~
//"     %s %ccb2b ebc1   ebc2    %cMseteol %cf:cp930 %ct:cp939\n",   //~va4qI~//~va56R~
//"     %s %ccb2b ebc1   ebc2    %cMseteol %cf:cp930 %ct:cp939\n",   //~va4qI~//~va56R~
"     %s %ccb2b ebc1   ebc2 %cMf:ebc.map %cMseteol %cf:cp930 %ct:cp939\n",//~va56I~
"     %s %ccb2b ebc1   ebc2 %cMf:ebc.map %cMseteol %cf:cp930 %ct:cp939\n",//~va56I~
  		PGM,                                                       //~va4qI~
		CMDFLAG_PREFIX,                                            //~va56I~
		CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4qI~
HELPMSG                                                            //~va55I~
//"     %s %ccf2b utf1 -oebc1 %cMf:xeebc.map %ccpeb:cp932\n",        //~va55R~//~vatcR~
//"     %s %ccf2b utf1 -oebc1 %cMf:xeebc.map %ccpeb:cp932\n",        //~va55R~//~vatcR~
"     %s %ccf2b utf1 -oebc1 %cMf:xeebc.map %ccpeb:cp939\n",        //~vatcI~
"     %s %ccf2b utf1 -oebc1 %cMf:xeebc.map %ccpeb:cp939\n",        //~vatcI~
  		PGM,                                                       //~va55I~
		CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);             //~va55I~
HELPMSG                                                            //~va59I~
//"     %s %ccf2b utf1 -oebc1 %cICU %ccpeb:ibm-37,swaplfnl\n",       //~va59I~//~vatcR~
//"     %s %ccf2b utf1 -oebc1 %cICU %ccpeb:ibm-37,swaplfnl\n",       //~va59I~//~vatcR~
"     %s %ccf2b utf1 -oebc1 %cICU %ccpeb:ibm-37,swaplfnl %cmf:cfgmap.cv1\n",//~vatcI~
"     %s %ccf2b utf1 -oebc1 %cICU %ccpeb:ibm-37,swaplfnl %cmf:cfgmap.cv1\n",//~vatcI~
  		PGM,                                                       //~va59I~
		CMDFLAG_PREFIX,                                            //~vatcI~
		CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);             //~va59I~
#endif                                                             //~va46I~
}//help
//**********************************************************************//~va63I~
//*parameter chk before wcinit                                     //~va63I~
//**********************************************************************//~va63I~
void parmchk0(int parmc,char *parmp[])                             //~va63I~
{                                                                  //~va63I~
  	int parmno; //parm count work                                  //~va63I~
    char *cptr,*pc;                                                //~va63I~
//*************************                                        //~va63I~
	for (parmno=1;parmno<parmc;parmno++)                           //~va63I~
	{                                                              //~va63I~
  		cptr=parmp[parmno];                                        //~va63I~
#ifdef UNX                                                         //~va63I~
  		if(*cptr=='-')                                             //~va63I~
#else                                                              //~va63I~
  		if(*cptr=='/'||*cptr=='-')                                 //~va63I~
#endif                                                             //~va63I~
  		{//option                                                  //~va63I~
        	cptr++;		//dummy for compile warning                //~va63I~
            switch(toupper(*cptr))                                 //~va63I~
            {                                                      //~va63I~
            case 'Y':                                              //~va63I~
            	for (pc=cptr+1;*pc;pc++)                           //~va63I~
                {                                                  //~va63I~
                	switch(toupper(*pc))                           //~va63I~
                    {                                              //~va63I~
                    case 'I':                                      //~va63I~
						Sotheropt|=OOPT_LOCALICU;                  //~va63I~
                        break;                                     //~va63I~
                    }                                              //~va63I~
                }                                                  //~va63I~
            	break;                                             //~va63I~
            case 'N':                                              //~va63I~
            	for (pc=cptr+1;*pc;pc++)                           //~va63I~
                {                                                  //~va63I~
                	switch(toupper(*pc))                           //~va63I~
                    {                                              //~va63I~
                    case 'I':                                      //~va63I~
						Sotheropt&=~OOPT_LOCALICU;                 //~va63I~
                        break;                                     //~va63I~
                    }                                              //~va63I~
                }                                                  //~va63I~
            	break;                                             //~va63I~
            }//switch                                              //~va63I~
    	}//flag                                                    //~va63I~
	}//for all parm                                                //~va63I~
    return;                                                        //~va63I~
}//parmchk0                                                        //~va63I~
