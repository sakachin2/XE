//*CID://+vby3R~:                             update#=  676;       //~vby3R~
//*************************************************************
//*xefcmd5.c*                                                      //~v47AR~
//**file cmd CV                                                    //~v47AR~
//*************************************************************
//vby3:230331 (Bug)ARM UTF8 localeid for iconv is UTF-8            //~vby3I~
//vbkz:180714 (Bug)CV cmd;LNX should treate M(of such as F2M) as default locale such as eucjp,GB18030//~vbkzI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaz9:150111 msg change for more easy to understand of "Use EBC command" after cv b2b//~vaz9I~
//vaz6:150108 CPEB option ignored(invalid use of USTRHEADIS_IC; parm was not literal but char *)//~vaz6I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vag8:120821 (BUG)cv b2b cmd did not set errline flag             //~vag8I~
//vag6:120821 rep by subchar for b2b(now keep original value)      //~vag6I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vad1:120419 (Lnx)option to use ICU for M2M                       //~vad1I~
//vaae:111212 Add -Si/-Sr to deny cfg default                      //~vaaeI~
//vaad:111212 (BUG)CV cmd;flag convopt and ebcopt is misxed;       //~vaadI~
//vaac:111211 CV cmd;add F2B/B2F because cpu8 file could not be conv at place by DBCS tbl fmt difference//~vaacI~
//            and M of M2B/B2M is current locale only              //~vaacI~
//vaab:111210 CV cmd;chk -t:/-f: for except M2M                    //~vaabI~
//vaaa:111210 CV cmd;warning:not required -mf: or cpeb: parm       //~vaaaI~
//va8m:101018 info msg for reject CV cmd for utf8 file             //~va8mI~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7K:100904 add SETCP option to cv cmd B2B(change UFHhandle) and SETCP option to EBC cmd.//~va7KI~
//va7H:100903 cv cmd:add b2b                                       //~va7HI~
//va7F:100902 (EBC)handle support for cv cmd                       //~va7FI~
//va6b:100619 CV cmd ucs4 option for UCS4(4 byte ucs)              //~va6bI~
//va5Z:100602 cv cmd;apply cmd opytion also to M2B/B2M, -SBCS ANK etc(currentry all is from cfg file)//~va5ZI~
//va5Y:100601 tab translation rule of EBC file                     //~va5YI~
//            save: NOTC/TC option is Invalid for ebc file(keep tab 0x05 and 0x09)//~va5YI~
//            rep:  nonEBC->EBC ignore source NOTC/TC option,always translate tab//~va5YI~
//            load:NOTC option is valid for fixLrecl for excep EBC file;tabctr=1,TC as default for RECORD mode//~va5YI~
//            CV cmd:restoretab for M2B (as usual for A2E)         //~va5YI~
//va5W:100527 CV cmd;B2E/E2B support                               //~va5WI~
//va5V:100527 add ENG-EXT/KANA-EXT is alternative of CP290         //~va5VI~
//va5T:100526 reject cv cmd on ebcfile because pfhflag10EBC remains//~va5TI~
//va50 100329 raw ebcdic file support                              //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd5.c :reject cv cmd                               //~va20I~
//va1k:091102_(UTF8)for cv cmd,4byte(GB18030),3byte(SS3) is not env but parm. It should to apply to a2a//~va1kI~
//va1j:091102_(BUG)cv cmd;errch parm "?" is trated as help req     //~va1jI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va05:090616 apply (UTF8)v90v:cv f2e(UTF<->EUC); v91N(m2f)        //~va05I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v79w:080913 cv m2m supports utf8                                 //~v79wI~
//v79t:080905 accept errrep for m2b/b2m                            //~v79tI~
//v79s:080904 CV cmd:m2m support                                   //~v79sI~
//v79j:080821 CV cmd:m2b/b2m support by -mf:mapfile                //~v79jI~
//v798:080803*(BUG)ucs conv miss strat plh to be converted when label specified//~v78UI~
//v78U:080624 xcv s2e new sosi option -Ss(del space by expand count by SO/SI insert)//~v78UI~
//v78R:080604 cv cmd:x2c ebc multiline by default(check SO/SI) if not inplace option//~v78RI~
//v78Q:080604 cv cmd:ebc multiline option                          //~v78QI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v77N:080209*(BUG) cv cmd access beyond ULHlen when ULHlen=0      //~v77NI~
//v77e:071226*err msg for duplicated x2c input range specification(currentry later is accepted)//~v77eI~
//v76J:070907*(BUG)lineend-file abend by access EOL position       //~v76JI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v72e:061123 add B2A/A2B option for EBC conv(without DBCS option) //~v72eI~
//v683:060321 ucs conv:support \u option for s2u,f2u(\uxxxx format output),u2f(\uxxxx input)//~v683I~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v61s:050306 for multiple found reverse support;change structure of mfwtbl(offs,len,next entry offset ushort count)//~v61sI~
//v60a:050109 (BUG)cv cmd;x2c with multi;output duplicated if not hex data is followed after hexdata//~v60aI~
//v59B:041118 (BUG)missing -Sa option on help msg                  //~v59BI~
//v59s:041114 cv x2c cmd;ebc support for mult,-H option            //~v59sR~
//v59r:041114 (BUG)ucvebc2asc interface changed (return is rc not len)//~v59sR~
//v59q:041114 (BUG)cv x2c cmd;line is cut when rep option used with conv range//~v59sR~
//v591:041030 cv cmd:CP290 option support                          //~v591I~
//v58Y:041026 cv cmd:MULT is optional(not required) for repinplace of x2c.//~v58YR~
//            but issue warning if 0 lines are translated.         //~v58YI~
//v58X:041026 cv cmd:ebc<-->sjis dbcs support;chng conv type a2e-->b2s,e2a-->s2b//~v58XI~
//v58W:041026 cv cmd:ebc<-->sjis dbcs support;-Sbcs option to ignore DBCS//~v58WI~
//v58V:041026 cv cmd:ebc<-->sjis dbcs support;-Sa option:to asume SO before line//~v58UI~
//v58U:041023 cv cmd:ebc<-->sjis dbcs support;drop -sa(replace any) option//~v58UI~
//v58T:041023 cv cmd:ebc<-->sjis dbcs support;cont line support    //~v58TR~
//v58S:041023 cv cmd:ebc<-->sjis dbcs support                      //~v58SI~
//v55K:040316 cv cmd;hexchar prefix parm -h,ex -h0x'xx' -h\'xx     //~v55KI~
//v54Q:040124 cv cmd:x2c:support outpos n-m:REP(repl in place)     //~v54QR~
//v54P:040124 cv cmd:x2c:support outpos m-n:max (max record len pos)//~v54PR~
//v54N:040124 cv cmd:x2c:allow any delm other than space/tab and conv all word even id err found//~v54NI~
//v54M:040122 cv cmd:\uxxx notation conversion support             //~v54MI~
//v530:030912 (BUG)malloc err not chked(DRO,X etc cmd abended)     //~v530I~
//vxxx:030831 DOS  compile err                                     //~vxxxI~
//v51Q:030802 cv cmd:NX(not excluded line) option support          //~v51QI~
//v51N:030727 hex dump<-->bin/ebc translation                      //~v51NI~
//v51M:030727 ascii<->ebc ctl char conv option                     //~v51MI~
//v51L:030726 ascii->ebc conv by cp1027(日本語英小文字拡張)        //~v51LI~
//v51K:030726 ebc conv by cp1027(日本語英小文字拡張)               //~v51KI~
//v51J:030726 CV cmd;support L2k/k2L conv(small letter<-->hankaku katakana)//~v51JI~
//v51H:030726 CV cmd;change et2a and eb2a to e2a [crlf]            //~v51HI~
//v51G:030726 CV cmd;add support label operand                     //~v51GI~
//v51q:030607 cov ebcdic to ascii                                  //~v51qI~
//v50x:030119 ucsconv:accept errch only when f2s/u2s               //~v50vI~
//v50v:030111 (BUG)find word tbl is not fully used                 //~v50vR~
//v50p:030111 add ucs-->sji conv option IBM/NEC                    //~v50pI~
//v50i:021230 cv cmd:ucs conv support                              //~v50iI~
//v50h:021230 cv cmd:cont line support                             //~v50hI~
//v50g:021230 cv cmd:sjis-->jis ,euc-->jis conv support            //~v50gI~
//v50f:021229 (BUG)tab disappear by cv cmd                         //~v50fI~
//v50e:021229 dbcs conv cont line chk(err if cont)                 //~v50eI~
//v49a:020622 new conv option jis-->sjis                           //~v49aI~
//v47U:020407 cv cmd(euc<-->sjis)                                  //~v47UI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <udbcschk.h>                                              //~v47UR~
#include <ufile.h>                                              //~5318I~
#include <ualloc.h>                                             //~v04dI~
#include <utrace.h>                                                //~v50eI~
#include <uparse.h>                                                //~v50iI~
#include <uedit.h>                                                 //~v50iI~
#include <ustring.h>                                               //~v55KI~
#include <utf.h>                                                   //~vbkzI~
                                                                   //~v50iI~
#ifndef DOSDOS                                                     //~v50iI~
	#include <ucvucs.h>                                            //~v50iI~
	#include <ucvebc.h>                                            //~v51qI~
	#include <ucvext.h>                                            //~v79jI~
	#include <ucvext2.h>                                           //~v79sI~
	#include <ucvebc4.h>                                           //~va7FI~
#endif                                                             //~v50iI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v50iI~
#include "xefile2.h"                                               //~v50iR~
#include "xefile5.h"                                               //~va7KI~
#include "xefile6.h"                                               //~v47UI~
#include "xefcmd2.h"                                               //~v50iI~
#include "xefcmd22.h"                                              //~v50iI~
#include "xefcmd5.h"                                               //~v47UR~
#include "xefcmd6.h"                                               //~v51GI~
#include "xelcmd.h"                                                //~v51GI~
#include "xeerr.h"                                              //~v033I~
#include "xechar2.h"                                               //~v51NI~
#include "xesub.h"                                                 //~v47UI~
#include "xesub2.h"                                                //~va1cR~
#include "xefsub.h"                                                //~v50eI~
#include "xeundo.h"                                                //~v47UI~
#include "xeebc.h"                                                 //~va50I~
#include "xeopt.h"                                                 //~va7FI~
//*******************************************************
//#define DBCSCONV_S2E   'E'                                       //~v50gR~
//#define DBCSCONV_E2S   'S'                                       //~v50gR~
//#define DBCSCONV_J2S   'J'  //jis to sjis                        //~v50gR~
//#define DBCSCONV_J2E   'j'  //jis to sjis                        //~v50gR~
#define DBCSCONV_S2E  0x12                                         //~v50iR~
#define DBCSCONV_E2S  0x21                                         //~v50iR~
#define DBCSCONV_J2S  0x31   //jis to sjis                         //~v50iR~
#define DBCSCONV_S2J  0x13   //sjis to jis                         //~v50iI~
#define DBCSCONV_J2E  0x32   //jis to euc                          //~v50iR~
#define DBCSCONV_E2J  0x23   //sjis to jis                         //~v50iR~
                                                                   //~v51qI~
#define DBCSCONV_E2A   0x67   //EBCDIC to ASCII                    //~v51qR~
#define DBCSCONV_A2E   0x76   //EBCDIC<---ASCII                    //~v51LI~
#define DBCSCONV_K2L   0x89   //hankaku katakana-->alphabet small letter//~v51JI~
#define DBCSCONV_L2K   0x98   //hankaku katakana<--alphabet small letter//~v51JI~
                                                                   //~v51NI~
#define DBCSCONV_X2A   0xa7   //hex dump-->binary                  //~v51NI~
#define DBCSCONV_A2X   0x7a   //hex dump<--binary                  //~v51NI~
#define DBCSCONV_X2E   0xa6   //hex dump-->ebcdic                  //~v51NI~
                                                                   //~v50iI~
#define UCSCONV_S2U   0x14   //sjis to UCS2                        //~v50iR~
#define UCSCONV_U2S   0x41   //UCS2 to sjis                        //~v50iR~
#define UCSCONV_S2F   0x15   //sjis to UTF8                        //~v50iR~
#define UCSCONV_F2S   0x51   //UTF8 to sjis                        //~v50iR~
#define UCSCONV_U2F   0x45   //UCS2 to UTF8                        //~v50iR~
#define UCSCONV_F2U   0x54   //UTF8 to UCS2                        //~v50iR~
#define UCSCONV_A2A   0xbb   //any to any                          //~v79sI~
                                                                   //~v51qI~
#define MAXLABEL      2                                            //~v51GI~
#define X2C_OUTMAX    -2    //id of x2c outpos is max record len pos//~v54PR~
#define X2C_OUTINPLACE -3   //repl in place                        //~v54QI~
//*******************************************************          //~v42jI~
    static PULINEH Splhs,Splhe;		//by label,start and next of end//~v51GI~
#ifndef DOSDOS                                                     //~v50iI~
    static PULINEH Splh;                                           //~v50iR~
    static PULINEH Splhcsr;                                        //~v50iR~
    static PUFILEH Spfh;                                           //~v50iI~
    static PUCLIENTWE Spcw;                                        //~v50iI~
	static int Serrctr;                                            //~v50iR~
	static int Serroffs=0;                                         //~v54QR~
	static int Serrstopsw;                                         //~v50iI~
//  static int Smfwtindex=0;	//Gfilemfwtbl index                //~v62bR~
//  static int Smfwtovf=0;		//found count at Gfilemfwtbl overflow//~v50vR~
    static PULINEH Smfwtovf=0;		//found plh at Gfilemfwtbl overflow//~v50vR~
//  static int Sfoundctr=0;		//found count                      //~v50vR~
    static int Sconvtype;                                          //~v50iI~
    static int Sucsopt=0;      //parm to callback                  //~v54MI~
    static int Shexlen=0,Shexinoffs=0,Shexoutoffs=0;	//for hex conv data//~v51NI~
    static int Sidatalen;                                          //~v50iI~
    static UCHAR *Sibuff;                                          //~v50iR~
#define MAX_HEXNOTATION  16                                        //~v55KI~
    static char Shexnotationpre[MAX_HEXNOTATION];                  //~v55KR~
    static char Shexnotationpost[MAX_HEXNOTATION];                 //~v55KR~
#endif                                                             //~v50iI~
    static long Sotheropt=0;                                       //~v51QI~
#define  OOPT_NX        0x01                                       //~v51QI~
#define  OOPT_MULT      0x02    //x2c multi-word conv              //~v54NI~
#define  OOPT_OUTINPLACE 0x04    //x2c multi-word conv replace in th place//~v54QR~
#define  OOPT_XNOTEPARM 0x08    //x2c hex notation parm specified  //~v55KI~
#define  OOPT_MULTLINE  0x10    //e2s multi-line                   //~v78QI~
#define  OOPT_B2B       0x20    //B2B option                       //~va7HI~
#define  OOPT_RESET     0x40    //B2B RESET option                 //~va7KI~
#define  OOPT_UTF8      0x80    //B2F/F2B                          //~vaacI~
#define  OOPT_MBICU   0x0100    //local by ICU                     //~vad1I~
    static long Sebcopt=0;  //parm to x2c with ebc option          //~v59sI~
#ifdef WCSUPP                                                      //~v79jI~
    static PUCVEXTCFG Spcfg=0;                                     //~v79jI~
    static char Scpfrom[64],Scpto[64]; //charset for m2m           //~v79sI~
#endif                                                             //~v79jI~
    static int  Sebchandle;  //parm to x2c with ebc option         //~va7FI~
    static int  Sb2bopt;  	//for setdbcstbl                       //~va7LI~
//****************************************************************
//long fcmddbcsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,int Pconvopt);//~v50eR~
int fcmddbcsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,int Pconvopt,LONG *Pplineno,int Perrch);//~v51MR~
#ifndef DOSDOS                                                     //~v50iI~
	int fcmducsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,ULONG Pucsopt);//~v50pR~
	UCVUCS_FREAD  fcmdcvgetdata;                                   //~v50iR~
	UCVUCS_FWRITE fcmdcvsavedata;                                  //~v50iR~
	UCVUCS_FERR   fcmdcvfuncerr;                                   //~v50iI~
	int fcmdcvconflict(void);                                      //~v50iI~
	int fcmdcvundo(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh);     //~v50iI~
	int fcmdcvajusttabsub(PUFILEH Ppfh,PULINEH Pplh,USHORT *Pmfwtbl);//~v50iR~
	int fcmdcvajusttabsub2(PUFILEH Ppfh,PULINEH Pplh,USHORT *Pmfwtbl);//~v50iI~
	int fcmdcvajusttab(void);                                      //~v50iI~
//  int fcmdebc2ascii(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno,int Perrch);//~v58TR~
	int fcmdkandl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno);//~v51JI~
	int fcmdgethexparm(UCHAR *Popd,int *Ppinoffs,int *Pplen,int *Ppoutoffs);//~v51NI~
	int fcmdhex2ascii(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno,int Perrch);//~v51NI~
//  int fcmdhexconv(UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen);//~v54QR~
//  int fcmdhexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen);//~v59sR~
    int fcmdhexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen,int Perrch);//~v59sI~
//  int fcmdmulthexconv(UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen);//~v54QR~
//  int fcmdmulthexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen);//~v59sR~
    int fcmdmulthexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen,int Perrch);//~v59sI~
//  int fcmdxnotehexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen);//~v59sR~
    int fcmdxnotehexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen,int Perrch);//~v59sI~
	int fcmdxnotepchk(UCHAR *Pxnoteparm);                          //~v55KI~
	int fcmdgetopt(int Popt,UCHAR *Popd,UCHAR *Poptid,UCHAR **Popdvalue);//~va7FI~
#endif                                                             //~v50iI~
//****************************************************************
// func_cid
//*rc   :0
//****************************************************************
int func_dbcsconv(PUCLIENTWE Ppcw)                                 //~v47UR~
{
//static UCHAR *Swordtbl="E2S\0S2E\0Z\0E2E\0S2S\0";                //~v49aR~
//static UCHAR *Swordtbl="E2S\0S2E\0Z\0E2E\0S2S\0J2S\0J2E";        //~v50gR~
//static UCHAR *Swordtbl="E2S\0S2E\0Z\0E2E\0S2S\0J2S\0J2E\0S2J\0E2J";//~v50iR~
static UCHAR *Swordtbl="E2S\0S2E\0Z\0E2E\0S2S\0J2S\0J2E\0S2J\0E2J\0" \
						"BOM\0BE\0LE\0IBM\0NEC\0"       \
//                      "EB2A\0ET2A\0"               /*15,16*/     //~v51HR~
//                      "E2A\0CRLF\0"               /*15,16*/      //~v58XR~
                        "B2S\0CRLF\0"               /*15,16*/    \
//  					"S2U\0U2S\0S2F\0F2S\0U2F\0F2U"; //15->     //~v51qR~
//  					"S2U\0U2S\0S2F\0F2S\0U2F\0F2U"; //17->     //~v51JR~
    					"S2U\0U2S\0S2F\0F2S\0U2F\0F2U\0"  //17->22 //~v51JR~
                        "K2L\0L2K\0"               /*23,24*/    \
//                      "A2E\0"               /*25*/               //~v58XR~
                        "S2B\0"               /*25*/    \
                        "ANK\0"               /*26*/    \
                        "X2C\0EBC\0"            /*27,28*/    \
                        "NX\0"               /*29*/    \
                        "\\u\0"              /*30*/    \
                        "MULT\0"             /*31*/	/*for x2c conv all word  */\
                        "JIS78\0"            /*32*/	/*for e2a/a2e */\
                        "JIS83\0"            /*33*/	/*for e2a/a2e */\
                        "CP290\0"            /*34*/	/*for e2a/a2e */\
                        "B2A\0A2B\0"         /*35,36*/	/*for b2a/a2b*///~v77NR~
//#ifdef UTF8SUPP                                                    //~v79tI~//~va05R~
#ifdef UTF8SUPPH                                                    //~v79tI~//~va05I~
                        "E2F\0F2E\0"         /*37,38*/	/*for EUC<-->UTF*///~v79tI~
                        "M2F\0F2M\0"         /*39,40*/	/*for LOCALE<-->UTF*///~v79tI~
#else                                                              //~v79tI~
                        "\x01\0\x01\0" //"E2F\0F2E\0"         /*37,38*/	/*for EUC<-->UTF*///~v79tI~
                        "\x01\0\x01\0" //"M2F\0F2M\0"         /*39,40*/	/*for LOCALE<-->UTF*///~v79tI~
#endif                                                             //~v79tI~
                        "B2M\0M2B\0"         /*41,42*/	/*for b2m/m2b*///~v79tR~
                        "M2M\0"              /*43*/	    /*for m2m*///~v79tR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5VI~
                        "CP1027\0KANA-EXT\0ENG-EXT\0"   /*44-46*/	//~va5VI~
#endif                                                             //~va5VI~
                        "B2E\0E2B\0"         /*47,48*/	/*EBC<-->EUC*///~va5WI~
                        "UCS4\0"         /*49*/	/*U2F,F2U*/        //~va6bI~
                        "B2B\0"           /*50*/	    /*for b2b*///~va7HR~
                        EBCCMD_OPT_SETCP "\0"           /*51*/	    /*for b2b reset UFHhandle*///~va7KR~
                        "F2B\0"             /*52*/                 //~vaacI~
                        "B2F\0"             /*53*/                 //~vaacI~
                        "ICU\0"             /*54*/                 //~vad1I~
                        ;                                          //~v51JI~
//#define UCSCONVTYPEPARMNO 15                                     //~v51qR~
#define UCSCONVTYPEPARMNO 17                                       //~v51qR~
    PUFILEC pfc;                                                   //~v47UM~
    PUFILEH pfh;                                                   //~v47UM~
    int ii,opdno,opid,convopt=0,convtype=0;                        //~v47UR~
    int rc;                                                        //~v50eI~
    long lineno;
    UCHAR *pc;                                                     //~v47UI~
    UPODELMTBL *podt;                                              //~v50iI~
    int labctr=0;                                                  //~v51GI~
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1];//label opd from/to        //~v51GI~
//  UCHAR errch='?';                                               //~v58SR~
    int errch='?';                                                 //~v58SI~
    UCHAR hexwk[4];                                                //~v58SI~
#ifndef DOSDOS                                                     //~v50iI~
	int xrangeparmsw=0;                                            //~v77eI~
    UCHAR *pc2;                                                    //~v58SI~
    int errchdbcs=0;                                               //~v58SI~
    int errchm2m=0;                                                //~v79sI~
//  UCHAR errch='?';                                               //~vxxxR~
	int ucsconvsw=0;                                               //~v50iI~
    int ucsparmsw=0;                                               //~v50iI~
    int noucsparmsw=0;                                             //~v50iR~
    int bomparmsw=0;                                               //~v50iI~
    int endianparmsw=0;                                            //~v50iI~
    int ibmnecparmsw=0;                                            //~v50pI~
    int errchsw=0;                                                 //~v50vI~
    int ebcopt=EBC2ASC_DBCS|EBC2ASC_SOSI;	//default dbcs conv    //~v58SR~
    int len;                                                       //~v55KI~
    int icuok=0;                                                   //~vad1I~
#ifdef WCSUPP                                                      //~v79wI~
    char *mapfile=0;                                               //~v79jI~
#endif                                                             //~v79wI~
//  #ifdef UNX                                                     //~va1cR~
    #ifdef BIGENDIAN                                               //~va1cR~
		ULONG  ucsopt=0;			//default big endian           //~v50pR~
	#else                                                          //~v50iI~
		ULONG  ucsopt=UCVUCS_LE;	//default little endian        //~v50pR~
	#endif                                                         //~v50iI~
	static int Sucsconvtype[]=                                     //~v50iI~
		{UCSCONV_S2U,UCSCONV_U2S,UCSCONV_S2F,UCSCONV_F2S,UCSCONV_U2F,UCSCONV_F2U};//~v50iR~
#ifdef WCSUPP                                                      //~v79wI~
	int ebcmbsw=0;       //for EBC<->locale conversion,parm to ucvext_getcvopt//~v79jI~
#endif                                                             //~v79wI~
#endif                                                             //~v50iI~
	UCHAR *pebccvname=0;                                           //~va7FI~
    int handle;                                                    //~va7FI~
    int swb2b=0;                                                   //~va7HR~
    int oldhandle;                                                 //~va7LI~
//*********************************
#ifndef DOSDOS                                                     //~v55KI~
    Sebchandle=0;                                                  //~va7FI~
    Sb2bopt=0;                                                     //~va7LI~
    Shexinoffs=0;                                                  //~v54NI~
	Shexlen=0;                                                     //~v54NI~
	Shexoutoffs=-1;                                                //~v54NR~
#ifdef WCSUPP                                                      //~v79wI~
    *Scpfrom=0;                                                    //~v79sI~
    *Scpto  =0;                                                    //~v79sI~
#endif                                                             //~v79wI~
#endif                                                             //~v55KI~
    Sotheropt=0;                                                   //~v51QI~
#ifndef DOSDOS                                                     //~v55KI~
    *Shexnotationpre=0;                                            //~v55KR~
    *Shexnotationpost=0;                                           //~v55KR~
#endif                                                             //~v55KI~
    opdno=Ppcw->UCWopdno;                                          //~v47UI~
	if (!opdno)		//operand                                      //~v47UR~
    {                                                              //~v0eAI~
//      uerrmsg("CV {e2s | s2e | e2e | s2s} [z]",0);               //~v49aR~
//      uerrmsg("CV {e2s | s2e | e2e | s2s | j2s | j2e} [z]",0);   //~v50gR~
#ifdef DOSDOS                                                      //~v50iI~
//      uerrmsg("CV {e2s | s2e | e2e | s2s | j2s | s2j | j2e | e2j} [z]",0);//~v51QR~
        uerrmsg("CV {E2S | S2E | E2E | S2S | J2S | S2J | J2E | E2J} [Z] [NX]",0);//~v51QI~
#else                                                              //~v50iI~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u} [z] [bom] [be|le] [ibm|nec] ['err-rep-char']",0);//~v51qR~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u|eb2a|et2a} [z] [bom] [be|le] [ibm|nec] ['err-rep-char']",0);//~v51HR~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u|e2a} [z] [bom] [be|le] [ibm|nec] [crlf] ['err-rep-char']",0);//~v51JR~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u|e2a|k2L|L2k} [z] [bom] [be|le] [ibm|nec] [crlf] ['err-rep-char']",0);//~v51LR~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u|e2a|a2e|k2L|L2k} [z] [bom] [be|le] [ibm|nec] [crlf] ['err-rep-char']",0);//~v51MR~
//      uerrmsg("CV {e2s|s2e|e2e|s2s|j2s|s2j|j2e|e2j|s2u|u2s|s2f|f2s|u2f|f2u|e2a|a2e|k2L|L2k} [z] [bom] [be|le] [ibm|nec] [crlf|ank] ['err-rep-char']",0);//~v51NR~
//      uerrmsg("CV {E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|E2A|A2E|K2L|L2K|X2C} [Z] [BOM] [BE|LE] [IBM|NEC] [CRLF|ANK] [EBC] [l[-m][:n]] ['err-rep-char']",0);//~v51QR~
//      uerrmsg("CV {E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|E2A|A2E|K2L|L2K|X2C} [Z] [BOM] [BE|LE] [IBM|NEC] [CRLF|ANK] [EBC] [l[-m][:n]] [NX] ['err-rep-char']",0);//~v54MR~
//      uerrmsg("CV {E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|E2A|A2E|K2L|L2K|X2C} [Z] [BOM] [BE|LE] [IBM|NEC] [CRLF|ANK] [EBC] [\\u] [l[-m][:n]] [NX] ['err-char']",0);//~v54NR~
//      uerrmsg("CV conv-type(chk it by \"CV ?\") [Z] [BOM] [BE|LE] [IBM|NEC] [CRLF|ANK] [EBC] [\\u] [l[-m]][:{n|MAX|REP}] [MULT] [NX] ['err-char']",0);//~v55KR~
//      uerrmsg("CV conv-type(chk it by \"CV ?\") [Z] [BOM] [BE|LE] [IBM|NEC] [CRLF|ANK] [EBC] [\\u] [l[-m]][:{n|MAX|REP}] [MULT | -Hpre[XXpost]] [NX] ['err-char']",0);//~v58SR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][\\u] [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[d|r|bcs]] [NX] [\"err\"]",0);//~v59BR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|r|bcs]] [NX] [\"err\"]",0);//~v72eR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|r]|-SBCS] [NX] [\"err\"]",0);//~v78QR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|r|m]|-SBCS] [NX] [\"err\"]",0);//~v78UR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"]",0);//~v79jR~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] ... Hit Esc Key\n [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-MF:mapfile]",0);//~v79sR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5VI~
//      uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290|CP1027|KANA-EXT|ENG-EXT][\\u] ... Hit Esc Key\n"//~va6bR~
        uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][UCS4][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290|CP1027|KANA-EXT|ENG-EXT][\\u] ... Hit Esc Key\n" \
//                 " [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-F:CPfrom -T:CPto]",0);//~va5VI~//~va7FR~
//                 " [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-F:CPfrom -T:CPto] [%s:cp]",0,//~va7FR~//~va7KR~
//                 " [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-F:CPfrom -T:CPto] [%s:cp] [%s]",0,//~va7KR~//~vad1R~
                   " [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-F:CPfrom -T:CPto] [%s:cp] [%s] [%s]",0,//~vad1I~
//                  MODE_EBC);                                	   //~va7FI~//~va7KR~
//                  MODE_EBC,EBCCMD_OPT_SETCP);                    //~va7KI~//~vad1R~
                      MODE_EBC,EBCCMD_OPT_SETCP,"ICU");            //~vad1I~
#else                                                              //~va5VI~
        uerrmsg("CV type(chk it by \"CV ?\")[Z][BOM][BE|LE][IBM|NEC][JIS78][CRLF|ANK][EBC][CP290][\\u] ... Hit Esc Key\n" \
                   " [l[-m]][:{n|MAX|REP}] [MULT|-Hpre[XXpost]] [-S[a|d|m|r|s]|-SBCS] [NX] [\"err\"] [-MF:mapfile] [-F:CPfrom -T:CPto]",0);//~v79sI~
#endif                                                             //~va5VI~
#endif                                                             //~v50iI~
        return 0;                                                  //~v20wI~
    }                                                              //~v0eAI~
	pfc=Ppcw->UCWpfc;                                              //~v47UM~
	pfh=pfc->UFCpfh;                                               //~v47UM~
    pc=Ppcw->UCWopdpot;                                            //~v47UI~
#ifdef UTF8UCS2                                                    //~va20I~
    if (FILEUTF8MODE(pfh))                                         //~va20I~
    {                                                              //~va20I~
//      return errnotsupported("CV cmd","UTF8 file");              //~va20I~//~va8mR~
//      uerrmsg("Apply CV cmd for UTF8 file with opend by CPLC mode.",//~va8mI~//~vaadR~
//              "UTF8ファイルの変換は CPLC で開いてから実行してください");//~va8mI~//~vaadR~
        uerrmsg("Apply CV cmd for UTF8 file with opend by CPLC mode and use 'F2x' option.",//~vaadI~
                "UTF8ファイルの変換は CPLC で開いてから'F2x'を実行してください");//~vaadI~
        return 4;                                                  //~va8mI~
    }                                                              //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5TI~
#ifdef UTF8UCS2                                                    //~va5TI~
//  if (PFH_ISEBC(pfh))                                            //~va5TI~//~va7FR~
//  {                                                              //~va5TI~//~va7FR~
//      return errnotsupported("CV cmd","EBCDIC file");            //~va5TI~//~va7FR~
//  }                                                              //~va5TI~//~va7FR~
#endif                                                             //~va5TI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5TI~
    podt=Ppcw->UCWopddelmt;                                        //~v50iI~
//  for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)                      //~v50iR~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)               //~v50iI~
    {                                                              //~v47UI~
      if (!podt->upoquate)	//delm strin should be enclosed by quate//~v51MI~
        if (*pc==ULCCMDLABEL)  //lebel specified                   //~v51GI~
        {                                                          //~v51GI~
            if (labctr==MAXLABEL)                                  //~v51GI~
                return fcmdlabelerr("Too many");                   //~v51GI~
            strncpy(labt[labctr],pc,ULHLINENOSZ);                  //~v51GI~
            labctr++;                                              //~v51GI~
            continue;                                              //~v51GI~
		}                                                          //~v51GI~
#ifndef DOSDOS                                                     //~v54NI~
     	if (*pc=='?')	//help                                     //~v54NI~
        if (!podt->upoquate)	//delm strin should be enclosed by quate//~va1jI~
        {                                                          //~v54NI~
//			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|E2A|A2E|K2L|L2K|X2C}",0);//~v58XR~
//			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|B2S|S2B|K2L|L2K|X2C}",0);//~v72eR~
//			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|B2S|S2B|B2A|A2B|K2L|L2K|X2C}",0);//~v79jR~
//			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|B2S|S2B|B2A|A2B|B2M|M2B|K2L|L2K|X2C}",0);//~v79sR~
//#ifdef UTF8SUPP                                                    //~v90vI~//~va05I~//~va7HR~
#ifdef UTF8SUPPH                                                   //~va7HI~
// 			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|E2F|F2E|M2F|F2M|U2F|F2U|B2S|S2B|B2A|A2B|B2M|M2B|M2M|K2L|L2K|X2C}",0);//~v79sI~//~va05I~//~va5WR~//~va7HR~
// 			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|E2F|F2E|M2F|F2M|U2F|F2U|B2S|S2B|B2E|E2B|B2A|A2B|B2M|M2B|B2B|M2M|K2L|L2K|X2C}",0);//~va7HI~//~vaacR~
   			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|E2F|F2E|M2F|F2M|U2F|F2U|B2S|S2B|B2E|E2B|B2A|A2B|B2M|B2F|M2B|F2B|B2B|M2M|K2L|L2K|X2C}",0);//~vaacI~
#else                                                              //~v90vM~//~va05I~
//			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|B2S|S2B|B2A|A2B|B2M|M2B|M2M|K2L|L2K|X2C}",0);//~v79sI~//~va5WR~
  			uerrmsg("conv-type:{E2S|S2E|E2E|S2S|J2S|S2J|J2E|E2J|S2U|U2S|S2F|F2S|U2F|F2U|B2S|S2B|B2E|E2B|B2A|A2B|B2M|M2B|M2M|K2L|L2K|X2C}",0);//~va5WI~
#endif                                                             //~v90vI~//~va05I~
            return 0;                                              //~v54NR~
        }                                                          //~v54NI~
        len=(int)strlen(pc);                                       //~v55KI~
//      if (len>2 && !memicmp(pc,"-H",2))                          //~v58UR~
        if (len>2 && (!memicmp(pc,"-H",2)||!memicmp(pc,"/H",2)))   //~v58UI~
        {                                                          //~v55KI~
        	if (fcmdxnotepchk(pc+2))                               //~v55KR~
	        	return errinvalid(pc);                             //~v55KI~
            Sotheropt|=OOPT_XNOTEPARM|OOPT_MULT;                   //~v55KI~
            continue;                                              //~v55KI~
        }//hex nptation parm                                       //~v55KI~
#ifdef WCSUPP                                                      //~v79sI~
        if (USTRHEADIS_IC(pc,"-MF:")||USTRHEADIS_IC(pc,"/MF:"))    //~v79jI~
        {                                                          //~v79jI~
        	mapfile=pc+4;                                          //~v79jI~
            continue;                                              //~v79jI~
        }                                                          //~v79jI~
        if (!fcmdgetopt(0,pc,MODE_EBC,&pebccvname))                //~va7FR~
            continue;	//get CPEB option                          //~va7FR~
        if (USTRHEADIS_IC(pc,"-F:")||USTRHEADIS_IC(pc,"/F:"))      //~v79sI~
        {                                                          //~v79sI~
            UstrncpyZ(Scpfrom,pc+3,sizeof(Scpfrom));               //~v79sI~
            continue;                                              //~v79sI~
        }                                                          //~v79sI~
        if (USTRHEADIS_IC(pc,"-T:")||USTRHEADIS_IC(pc,"/T:"))      //~v79sI~
        {                                                          //~v79sI~
            UstrncpyZ(Scpto,pc+3,sizeof(Scpto));                   //~v79sI~
            continue;                                              //~v79sI~
        }                                                          //~v79sI~
#endif                                                             //~v79sI~
        if (len>2 && (!memicmp(pc,"-S",2)||!memicmp(pc,"/S",2)))   //~v58UR~
        {                                                          //~v58SI~
      		if (convtype!=DBCSCONV_E2A                             //~v58SI~
      		&&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v58SI~
    	    	return fcmdcvconflict();                           //~v58SI~
          if (!stricmp(pc+1,"SBCS"))                               //~v58WI~
          {                                                        //~va5ZI~
    		ebcopt&=~EBC2ASC_DBCS;	//no dbcs conversion           //~v58WI~
			ebcmbsw|=UCEGCOO_FORCESBCS;//for B2M/M2B               //~va5ZR~
          }                                                        //~va5ZI~
          else                                                     //~v58WI~
          {                                                        //~v58WI~
            for (pc2=pc+2;*pc2;pc2++)                              //~v58SI~
            {                                                      //~v58SI~
#ifdef WCSUPP                                                      //~v79jI~
			    ebcmbsw|=UCEGCOO_IGNSOSI; //ignore this option of map parm file//~v79jI~
#endif                                                             //~v79jI~
                switch(toupper(*pc2))                              //~v58SI~
                {                                                  //~v58SI~
                case 'A':       //any                              //~v58VR~
      				if (convtype!=DBCSCONV_E2A)                    //~v58VR~
		    	    	return fcmdcvconflict();                   //~v58VR~
                    ebcopt|=EBC2ASC_SOSIAS;//delete/isrt           //~v58VR~
                    break;                                         //~v58VR~
                case 'D':       //delete                           //~v58SI~
                    ebcopt&=~EBC2ASC_SOSI;//drop ins(a2e)/rep to spce(e2a)//~v58UR~
                    ebcopt|=EBC2ASC_SOSID;//delete SOSI            //~v58UI~
                    break;                                         //~v58SI~
//              case 'I':       //isrt                             //~v58UR~
//                  ebcopt&=~EBC2ASC_SOSIR;                        //~v58UR~
//                  ebcopt|=EBC2ASC_SOSI;//delete/isrt             //~v58UR~
//                  break;                                         //~v58UR~
                case 'I':       //isrt for M2B                     //~vaaeI~
      				if (convtype==DBCSCONV_A2E)     //B2x          //~vaaeI~
                    {                                              //~vaaeI~
                    	ebcopt&=~EBC2ASC_SOSIOS;	//rep neighbour space//~vaaeI~
                    	ebcopt|=EBC2ASC_SOSI;//default repspace(B2x)/insert(x2B)//~vaaeI~
                    }                                              //~vaaeI~
                    break;                                         //~vaaeI~
                case 'M':       //multiline                        //~v78QI~
      				if (convtype!=DBCSCONV_E2A)                    //~v78QI~
		    	    	return fcmdcvconflict();                   //~v78QI~
                    Sotheropt|=OOPT_MULTLINE;//so status continue to next line//~v78QI~
                    break;                                         //~v78QI~
//              case 'N':       //no process                       //~v58UR~
//                  ebcopt&=~(EBC2ASC_SOSI|EBC2ASC_SOSIR);         //~v58UR~
//                  break;                                         //~v58UR~
                case 'R':                                          //~v58UR~
      				if (convtype==DBCSCONV_E2A)     //B2x          //~vaaeI~
                    {                                              //~vaaeI~
                    	ebcopt&=~EBC2ASC_SOSID;//repspace(E2A)/isrt(A2E)//~vaaeI~
                    	ebcopt|=EBC2ASC_SOSI;//default repspace(B2x)/insert(x2B)//~vaaeI~
	                    break;                                     //~vaaeI~
                    }                                              //~vaaeI~
      				if (convtype!=DBCSCONV_A2E)                    //~v58UR~
      				  if (convtype!=DBCSCONV_X2E)                  //~v59sI~
		    	    	return fcmdcvconflict();                   //~v58UI~
                    ebcopt&=~EBC2ASC_SOSI;//delete/isrt            //~v58UR~
                    ebcopt|=EBC2ASC_SOSIOS;//rep if space(a2e)     //~v58UR~
                    break;                                         //~v58SI~
                case 'S':                                          //~v78UI~
      				if (convtype!=DBCSCONV_A2E)                    //~v78UI~
      				  if (convtype!=DBCSCONV_X2E)                  //~v78UI~
		    	    	return fcmdcvconflict();                   //~v78UI~
                    ebcopt&=~EBC2ASC_SOSI;//delete/isrt            //~v78UI~
                    ebcopt|=EBC2ASC_SOSISHIFT;//rep if space(a2e),shrink following space//~v78UI~
                    break;                                         //~v78UI~
                default:                                           //~v58SI~
                    return errinvalid(pc);                         //~v58SI~
                }                                                  //~v58SI~
            }//for                                                 //~v58SI~
          }//not sbcs                                              //~v58WI~
            continue;                                              //~v58SI~
        }//hex nptation parm                                       //~v58SI~
#endif                                                             //~v54NI~
 		switch(opid=wordtblisrch(pc,Swordtbl),opid)                //~v47UI~
        {                                                          //~v47UI~
        case 0:	//err                                              //~v47UI~
#ifndef DOSDOS                                                     //~v50iI~
      		if (podt->upoquate)	//delm strin should be enclosed by quate//~v50iI~
            {                                                      //~v50iI~
//      		ucsparmsw=1;	//for ucs cmd only                 //~v51MR~
        		errchsw=1;      //u2s/f2s only                     //~v50vI~
                len=(int)strlen(pc);                               //~v59BR~
                if (len==4)  //dbcs rep char                       //~v58SR~
                {                                                  //~v58SI~
                    if (ugethex(pc,hexwk,4)<=0)                    //~v58SI~
                    	return errinvalid(pc);                     //~v58SI~
                    errchdbcs=(hexwk[0]<<8)+hexwk[1];              //~v58SI~
                }                                                  //~v58SI~
                else                                               //~v58SI~
//              if (strlen(pc)>=2)                                 //~v58SR~
                if (len==2)                                        //~v58SR~
                {                                                  //~v58SI~
//                  ugethex(pc,&errch,2);                          //~v58SR~
                    if (ugethex(pc,hexwk,2)<=0)                    //~v58SR~
                    {                                              //~v58SI~
                    	errch=0;                                   //~v58SI~
                        errchdbcs=(*pc<<8)+*(pc+1);	//2byte dbcs err rep//~v58SR~
                    }                                              //~v58SI~
                    else                                           //~v79sI~
                    errch=(int)hexwk[0];                           //~v58SI~
                }                                                  //~v58SI~
                else                                               //~v50iI~
                if (len==1)                                        //~v58SI~
	            	errch=*pc;                                     //~v50iR~
                else                                               //~v58SI~
                    return errinvalid(pc);                         //~v58SI~
                errchm2m=(errch & 0xff)|(errchdbcs<<8);            //~v79sI~
                break;                                             //~v50iI~
            }                                                      //~v50iI~
            if (!fcmdgethexparm(pc,&Shexinoffs,&Shexlen,&Shexoutoffs))//~v51NI~
            {                                                      //~v51NI~
      			if (convtype!=DBCSCONV_X2A                         //~v51NI~
      			&&  convtype!=DBCSCONV_X2E)                        //~v51NI~
                {                                                  //~v54QI~
                    uerrmsg("column is for X2C only",0);           //~v54QI~
    	    		return 4;                                      //~v54QR~
                }                                                  //~v54QI~
				if (xrangeparmsw)                                  //~v77eI~
                {                                                  //~v77eI~
                    uerrmsg("duplicated input column range specificationis",//~v77eI~
                            "桁範囲指定の重複");                   //~v77eI~
    	    		return 4;                                      //~v77eI~
                }                                                  //~v77eI~
				xrangeparmsw=1;                                    //~v77eI~
          		if (Shexoutoffs==X2C_OUTINPLACE)                   //~v54QI~
            		Sotheropt|=OOPT_OUTINPLACE;                    //~v54QR~
                break;                                             //~v51NI~
            }                                                      //~v51NI~
#endif                                                             //~v50iI~
        	return errinvalid(pc);                                 //~v47UI~
        case 1: //e2s                                              //~v47UI~
            convtype=DBCSCONV_E2S;                                 //~v47UR~
            break;                                                 //~v47UI~
        case 2: //s2e                                              //~v47UI~
            convtype=DBCSCONV_S2E;                                 //~v47UR~
            break;                                                 //~v47UI~
        case 3: //z                                                //~v47UI~
#ifndef DOSDOS                                                     //~v50iI~
        	noucsparmsw=1;                                         //~v50iI~
#endif                                                             //~v50iI~
//*UDBCSCHK_EUCHKONV:0x01==EBC2ASC_CRLF; reject by crlf is E2A/A2E/X2E only//~vaadI~
            convopt|=UDBCSCHK_EUCHKCONV;                           //~v47UI~
            break;                                                 //~v47UI~
        case 4: //e2e                                              //~v47UI~
            convtype=DBCSCONV_E2S;                                 //~v47UI~
//*UDBCSCHK_KANAONLY:0x20==EBC2ASC_IBM; reject by ibm(ucsparmsw=1) E2A/A2E/X2E only//~vaadI~
            convopt|=(UDBCSCHK_KANAONLY|UDBCSCHK_EUCHKCONV); //euc hankaku katakana-->zenkaku//~v47UI~
            break;                                                 //~v47UI~
        case 5: //s2s                                              //~v47UI~
            convtype=DBCSCONV_S2E;                                 //~v47UI~
            convopt|=(UDBCSCHK_KANAONLY|UDBCSCHK_EUCHKCONV); //euc hankaku katakana-->zenkaku//~v47UI~
            break;                                                 //~v47UI~
        case 6: //j2s                                              //~v49aI~
            convtype=DBCSCONV_J2S;  //jis-->sjis                   //~v49aI~
            break;                                                 //~v49aI~
        case 7: //j2e                                              //~v49aI~
            convtype=DBCSCONV_J2E;  //jis-->euc                    //~v49aI~
            break;                                                 //~v49aI~
        case 8: //s2j                                              //~v50gI~
            convtype=DBCSCONV_S2J;  //sjis-->jis                   //~v50gI~
            break;                                                 //~v50gI~
        case 9: //e2j                                              //~v50gI~
            convtype=DBCSCONV_E2J;  //euc -->jis                   //~v50gI~
            break;                                                 //~v50gI~
#ifndef DOSDOS                                                     //~v50iR~
        case 10: //bom                                             //~v50iI~
        	ucsparmsw=1;                                           //~v50iI~
            bomparmsw=1;                                           //~v50iI~
            ucsopt|=UCVUCS_BOM;  //euc -->jis                      //~v50iI~
            break;                                                 //~v50iI~
        case 11: //be                                              //~v50iI~
        	ucsparmsw=1;                                           //~v50iI~
            endianparmsw=1;                                        //~v50iI~
//          ucsopt&=~UCVUCS_LE;  //big endian                      //~v50iI~//~vb2DR~
            ucsopt&=(ULONG)(~UCVUCS_LE);  //big endian             //~vb2DI~
            break;                                                 //~v50iI~
        case 12: //le                                              //~v50iI~
        	ucsparmsw=1;                                           //~v50iI~
            endianparmsw=1;                                        //~v50iI~
            ucsopt|=UCVUCS_LE;  //little endian                    //~v50iI~
            break;                                                 //~v50iI~
        case 13: //IBM                                             //~v50pI~
      	  if (convtype!=DBCSCONV_E2A                               //~v58SI~
      	  &&  convtype!=DBCSCONV_X2E                               //~v59sI~
      	  &&  convtype!=DBCSCONV_A2E)//IBM parm is common to ucs conv & ebc conv//~v58SI~
        	ucsparmsw=1;                                           //~v50pI~
            ibmnecparmsw=1;                                        //~v50pI~
//          ucsopt&=~UCVUCS_NEC;  //UCS conv to IBM rgn on MS kanji//~v50pI~//~vb2DR~
            ucsopt&=(ULONG)(~UCVUCS_NEC);  //UCS conv to IBM rgn on MS kanji//~vb2DI~
            ebcopt&=~EBC2ASC_NEC;  //NEC rgn on MS kanji           //~v58SI~
            ebcopt|=EBC2ASC_IBM;  //NEC rgn on MS kanji            //~v58SI~
            break;                                                 //~v50pI~
        case 14: //NEC                                             //~v50pR~
      	  if (convtype!=DBCSCONV_E2A                               //~v58SI~
      	  &&  convtype!=DBCSCONV_X2E                               //~v59sI~
      	  &&  convtype!=DBCSCONV_A2E)//NEC parm is common to ucs conv & ebc conv//~v58SI~
        	ucsparmsw=1;                                           //~v50pI~
            ibmnecparmsw=1;                                        //~v50pI~
            ucsopt|=UCVUCS_NEC;  //NEC rgn on MS kanji             //~v50pI~
            ebcopt|=EBC2ASC_NEC;  //NEC rgn on MS kanji            //~v58SI~
            ebcopt&=~EBC2ASC_IBM;  //NEC rgn on MS kanji           //~v58SI~
            break;                                                 //~v50pI~
#ifndef DOSDOS                                                     //~v59BI~
        case 15: //E2A     //ebcdic to ascii                       //~v51HR~
        case 35: //B2A     //ebcdic to ascii(SBCS)                 //~v72eI~
        case 47: //B2E     //Ebcdic to EUC-J                       //~va5WI~
 		    if (opid==35)   //b2a                                  //~v72eI~
    			ebcopt&=~EBC2ASC_DBCS;	//reset default dbcs conv  //~v72eR~
 		    if (opid==47)   //b2a                                  //~va5WI~
    			ebcopt|=EBC2ASC_EUC;	//reset default dbcs conv  //~va5WI~
            convtype=DBCSCONV_E2A;  //euc -->jis                   //~v51qI~
//          convopt&=~EBC2ASC_CRLF;                                //~v51LR~
//          convopt|=EBC2ASC_CTL;  //default ctl char conv         //~v51MI~//~vaadR~
            ebcopt|=EBC2ASC_CTL;  //default ctl char conv          //~vaadI~
            ebcopt&=~EBC2ASC_A2E;                                  //~v58SR~
            break;                                                 //~v51qI~
#endif                                                             //~v59BI~
        case 16: //CRLF     //ebcdic to ascii,text(crlf chk)       //~v51HR~
//          convtype=DBCSCONV_E2A;  //euc -->jis                   //~v51HR~
//          convopt|=EBC2ASC_CRLF;                                 //~v51qI~//~vaadR~
            ebcopt|=EBC2ASC_CRLF;                                  //~vaadI~
//          convopt&=~EBC2ASC_CTL;                                 //~v51MI~//~vaadR~
            ebcopt&=~EBC2ASC_CTL;                                  //~vaadI~
//    		if (convtype!=DBCSCONV_E2A)                            //~v51LR~
      		if (convtype!=DBCSCONV_E2A                             //~v51LI~
      		&&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v51LI~
    	    	return fcmdcvconflict();                           //~v51HM~
            break;                                                 //~v51qI~
        case 23: //K2L      //katakana->ascii lower case letter    //~v51JR~
            convtype=DBCSCONV_K2L;  //euc -->jis                   //~v51JR~
            convopt|=KANDL_K2L;                                    //~v51JI~
            break;                                                 //~v51JI~
        case 24: //L2K      //katakana<-ascii lower case letter    //~v51JI~
            convtype=DBCSCONV_K2L;  //euc -->jis                   //~v51JR~
            convopt&=~KANDL_K2L;                                   //~v51JI~
            break;                                                 //~v51JI~
#ifndef DOSDOS                                                     //~v59BI~
        case 25: //A2E      //ascii-->ebc                          //~v51LI~
        case 36: //A2B     //ebcdic from ascii(SBCS)               //~v72eI~
        case 48: //E2B     //ebcdic from EUC-J                     //~va5WI~
 		    if (opid==36)   //b2a                                  //~v72eI~
    			ebcopt&=~EBC2ASC_DBCS;	//reset default dbcs conv  //~v72eR~
 		    if (opid==48)   //b2a                                  //~va5WI~
    			ebcopt|=EBC2ASC_EUC;	//reset default dbcs conv  //~va5WI~
            convtype=DBCSCONV_A2E;  //ascii-->ebc                  //~v51LI~
//          convopt|=EBC2ASC_CTL;  //default ctl char conv         //~v51MI~//~vaadR~
            ebcopt|=EBC2ASC_CTL;  //default ctl char conv          //~vaadI~
            ebcopt|=EBC2ASC_A2E;                                   //~v58SR~
            break;                                                 //~v51LI~
#endif                                                             //~v59BI~
        case 26: //ANK      //no ctl char conv                     //~v51MR~
      		if (convtype!=DBCSCONV_E2A                             //~v51MI~
      	    &&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v51MI~
    	    	return fcmdcvconflict();                           //~v51MI~
//          convopt&=~EBC2ASC_CTL;                                 //~v51MI~//~vaadR~
            ebcopt&=~EBC2ASC_CTL;                                  //~vaadI~
//          convopt&=~EBC2ASC_CRLF;                                //~v51MI~//~vaadR~
            ebcopt&=~EBC2ASC_CRLF;                                 //~vaadI~
			ebcmbsw|=UCEGCOO_FORCEANK;//for B2M/M2B                //~va5ZR~
            break;                                                 //~v51MI~
        case 27: //X2C      //hex dump-->ascii                     //~v51NR~
            convtype=DBCSCONV_X2A;                                 //~v51NI~
            break;                                                 //~v51NI~
        case 28: //X2E      //hex dump-->ebcdic                    //~v51NI~
        	if (convtype!=DBCSCONV_X2A)                            //~v51NI~
            {                                                      //~v54QI~
                uerrmsg("EBC is for X2C only",0);                  //~v54QI~
    	    	return 4;                                          //~v54QR~
            }                                                      //~v54QI~
            convtype=DBCSCONV_X2E;                                 //~v51NI~
            break;                                                 //~v51NI~
#endif                                                             //~v50iI~
        case 29: //NX       //not excluded option                  //~v51QI~
#ifndef DOSDOS                                                     //~vxxxI~
    		if (ucsconvsw)                                         //~v51QI~
	        	return fcmdcvconflict();                           //~v51QI~
#endif                                                             //~vxxxI~
            Sotheropt|=OOPT_NX;                                    //~v51QI~
            break;                                                 //~v51QI~
#ifndef DOSDOS                                                     //~v54MI~
        case 30: //\uxxxx fmt                                      //~v54MI~
//      	if (convtype!=UCSCONV_U2S)      //unicode to sjis only //~v683R~
        	if (convtype!=UCSCONV_U2S       //unicode to sjis only //~v683I~
        	&&  convtype!=UCSCONV_U2F       //unicode to sjis only //~v683I~
        	&&  convtype!=UCSCONV_F2U       //unicode to sjis only //~v683I~
        	&&  convtype!=UCSCONV_S2U)      //unicode to sjis only //~v683I~
            {                                                      //~v54QI~
//              uerrmsg("\\u is for U2S only",0);                  //~v683R~
                uerrmsg("\\u is for U2S/U2F/S2U/F2U only",0);      //~v683I~
    	    	return 4;                                          //~v54QR~
            }                                                      //~v54QI~
            ucsopt|=UCVUCS_ESCUCS;                                 //~v54MR~
            break;                                                 //~v54MI~
        case 31: //\uxxxx fmt                                      //~v54NI~
            Sotheropt|=OOPT_MULT;                                  //~v54NI~
            break;                                                 //~v54NI~
        case 32: //JIS78                                           //~v58SI~
      		if (convtype!=DBCSCONV_E2A                             //~v58SI~
      	    &&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v58SI~
    	    	return fcmdcvconflict();                           //~v58SI~
            ebcopt|=EBC2ASC_OLD;                                   //~v58SI~
            ebcopt&=~EBC2ASC_NEW;                                  //~v58SI~
            break;                                                 //~v58SI~
        case 33: //JIS78                                           //~v58SI~
      		if (convtype!=DBCSCONV_E2A                             //~v58SI~
      	    &&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v58SI~
    	    	return fcmdcvconflict();                           //~v58SI~
            ebcopt&=~EBC2ASC_OLD;                                  //~v58SI~
            ebcopt|=EBC2ASC_NEW;                                   //~v58SI~
            break;                                                 //~v58SI~
        case 34: //CP290                                           //~v591I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5VI~
        case 44: //CP1027                                          //~va5VI~
        case 45: //KANA-EXT                                        //~va5VI~
        case 46: //ENG-EXT                                         //~va5VI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5VI~
      		if (convtype!=DBCSCONV_E2A                             //~v591I~
      	    &&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v591I~
    	    	return fcmdcvconflict();                           //~v591I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5VI~
			 ebcmbsw|=UCEGCOO_IGNCP290;//ignore this option of map parm file//~va5TI~//~va5VM~
          if (opid==44||opid==46)                                  //~va5VI~
            ebcopt|=~EBC2ASC_CP290;                                //~va5VI~
          else                                                     //~va5VI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5VI~
            ebcopt|=EBC2ASC_CP290;                                 //~v591I~
            break;                                                 //~v591I~
#ifdef UTF8SUPPH                                                    //~v90vI~//~va05I~
        case 37: //E2F                                             //~v90vI~//~va05I~
			ucsconvsw=1;                                           //~v90vI~//~va05I~
#ifdef LNX                                                         //~vbkzI~
            convtype=UCSCONV_A2A;  //any to any                    //~vbkzI~
            icuok=1;                                               //~vbkzI~
        #ifdef ARM                                                 //~vby3I~
            strcpy(Scpto,LOCALEID_UTF_8);                          //~vby3I~
        #else                                                      //~vby3I~
            strcpy(Scpto,LOCALEID_UTF8);                           //~vbkzI~
        #endif                                                     //+vby3R~
            strcpy(Scpfrom,"eucjp");  //dropped .utf8 from setlocale()//~vbkzR~
#else                                                              //~vbkzI~
            ucsopt|=UCVUCS_EUC;                                    //~v90vI~//~va05I~
            convtype=UCSCONV_S2F;                                  //~v90vI~//~va05I~
#endif                                                             //~vbkzI~
            break;                                                 //~v90vI~//~va05I~
        case 38: //F2E                                             //~v90vI~//~va05I~
			ucsconvsw=1;                                           //~v90vI~//~va05I~
#ifdef LNX                                                         //~vbkzI~
            convtype=UCSCONV_A2A;  //any to any                    //~vbkzI~
			icuok=1;                                               //~vbkzI~
        #ifdef ARM                                                 //~vby3I~
            strcpy(Scpfrom,LOCALEID_UTF_8);                        //~vby3I~
        #else                                                      //~vby3I~
            strcpy(Scpfrom,LOCALEID_UTF8);                         //~vbkzI~
        #endif                                                     //~vby3I~
            strcpy(Scpto,"eucjp");  //dropped .utf8 from setlocale()//~vbkzI~
#else                                                              //~vbkzI~
            ucsopt|=UCVUCS_EUC;                                    //~v90vI~//~va05I~
            convtype=UCSCONV_F2S;                                  //~v90vI~//~va05I~
#endif                                                             //~vbkzI~
            break;                                                 //~v90vI~//~va05I~
        case 39: //M2F                                             //~v91NI~//~va05I~
			ucsconvsw=1;                                           //~v91NI~//~va05I~
            ucsopt|=UCVUCS_MB;                                     //~v91NI~//~va05I~
#ifdef LNX                                                         //~vbkzR~
            convtype=UCSCONV_A2A;  //any to any                    //~vbkzR~
            icuok=1;                                               //~vbkzR~
        #ifdef ARM                                                 //~vby3I~
            strcpy(Scpto,LOCALEID_UTF_8);                          //~vby3I~
        #else                                                      //~vby3I~
            strcpy(Scpto,LOCALEID_UTF8);                           //~vbkzR~
        #endif                                                     //~vby3I~
            strcpy(Scpfrom,Gdefaultlocalecode);  //dropped .utf8 from setlocale()//~vbkzR~
#else                                                              //~vbkzR~
            convtype=UCSCONV_S2F;                                  //~v91NI~//~va05I~
#endif                                                             //~vbkzR~
            break;                                                 //~v91NI~//~va05I~
        case 40: //F2M                                             //~v91NI~//~va05I~
			ucsconvsw=1;                                           //~v91NI~//~va05I~
            ucsopt|=UCVUCS_MB;                                     //~v91NI~//~va05I~
#ifdef LNX                                                         //~vbkzI~
            convtype=UCSCONV_A2A;  //any to any                    //~vbkzI~
			icuok=1;                                               //~vbkzI~
        #ifdef ARM                                                 //~vby3I~
            strcpy(Scpfrom,LOCALEID_UTF_8);                        //~vby3I~
        #else                                                      //~vby3I~
            strcpy(Scpfrom,LOCALEID_UTF8);                         //~vbkzR~
        #endif                                                     //~vby3I~
            strcpy(Scpto,Gdefaultlocalecode);  //dropped .utf8 from setlocale()//~vbkzR~
#else                                                              //~vbkzI~
            convtype=UCSCONV_F2S;                                  //~v91NI~//~va05I~
#endif                                                             //~vbkzI~
            break;                                                 //~v91NI~//~va05I~
#endif                                                             //~v90vI~//~va05I~
        case 41: //B2M                                             //~v79tR~
        case 53: //B2F                                             //~vaacI~
#ifdef WCSUPP                                                      //~v79jI~
        	if (opid==53)                                          //~vaacI~
            	Sotheropt|=OOPT_UTF8;                              //~vaacR~
            convtype=DBCSCONV_E2A;  //euc -->jis                   //~v79jI~
			ebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B                  //~v79jI~
            ebcopt|=EBC2ASC_EXT;                                   //~v79jR~
            ebcopt&=~EBC2ASC_A2E;                                  //~v79jI~
//          ebcopt|=EBC2ASC_CTL;	//reset by ANK option;CTL is not for external converter(cv=0 and windowsJ)//~va5WR~
			ebcmbsw|=UCEGCOO_CTL;	//B2M/M2B ,ctl by cfg          //~va5ZI~
            break;                                                 //~v79jI~
#else                                                              //~v79jI~
			return errnotsupported("B2M(from EBCDIC by mappfile)","except Win/Linux");//~v79wR~
#endif                                                             //~v79jI~
        case 50: //B2B                                             //~va7HR~
        case 42: //M2B                                             //~v79tR~
        case 52: //F2B                                             //~vaacI~
        	if (opid==50)                                          //~va7HR~
            	swb2b=1;                                           //~va7HR~
        	if (opid==52)                                          //~vaacI~
            	Sotheropt|=OOPT_UTF8;                              //~vaacI~
#ifdef WCSUPP                                                      //~v79jI~
            convtype=DBCSCONV_A2E;  //euc -->jis                   //~v79jI~
			ebcmbsw|=UCEGCOO_CHKDBCS;	//B2M/M2B                  //~v79jI~
            ebcopt|=EBC2ASC_EXT;                                   //~v79jI~
            ebcopt|=EBC2ASC_A2E;                                   //~v79jI~
//          ebcopt|=EBC2ASC_CTL;	//reset by ANK option;CTL is not for external converter(cv=0 and windowsJ)//~va5WI~
			ebcmbsw|=UCEGCOO_CTL;	//B2M/M2B ,ctl by cfg          //~va5ZI~
            break;                                                 //~v79jI~
#else                                                              //~v79jI~
			return errnotsupported("M2B(to EBCDIC by mappfile)","except Win/Linux");//~v79wR~
#endif                                                             //~v79jI~
        case 43: //M2M                                             //~v79tR~
#ifdef WCSUPP                                                      //~v79sI~
            convtype=UCSCONV_A2A;  //any to any                    //~v79sR~
			ucsconvsw=1;            //through fcmducsconv          //~v79sI~
			icuok=1;                                               //~vad1I~
            break;                                                 //~v79sI~
#else                                                              //~v79sI~
			return errnotsupported("M2M(any to any)","except Win/Linux");//~v79wR~
#endif                                                             //~v79sI~
#endif                                                             //~v54MI~
        case 49: //UCS4                                            //~va6bI~
            ucsopt|=UCVUCS_UCS4;  //euc -->jis                     //~va6bI~
            break;                                                 //~va6bI~
        case 51: //RESET                                           //~va7KI~
			Sotheropt|=OOPT_RESET;                                 //~va7KI~
            break;                                                 //~va7KI~
        case 54: //ICU                                             //~vad1I~
			Sotheropt|=OOPT_MBICU;                                 //~vad1I~
            break;                                                 //~vad1I~
        default:                                                   //~v50iI~
#ifdef DOSDOS                                                      //~v50iI~
        	uerrmsg("%s is not supported by DOS version",          //~v50iI~
				"DOS版では %s はサポートして言いません",           //~v50iR~
				pc);                                               //~v50iI~
        	return 4;                                              //~v50iI~
#else                                                              //~v50iI~
			ucsconvsw=1;                                           //~v50iI~
            convtype=Sucsconvtype[opid-UCSCONVTYPEPARMNO];         //~v50pR~
#endif                                                             //~v50iI~
        }//sw                                                      //~v47UI~
    }//opd loop                                                    //~v47UI~
    if (labctr && (labctr!=MAXLABEL))                              //~v51GI~
        return fcmdlabelerr("label count=0 or 2");                 //~v51GI~
	if (rc=fcmdgetabrange(Ppcw,pfh,labt,labctr,&Splhs,&Splhe,1),rc) //1:plh2 is next plh//~v51GI~
    	return rc;	//may 1:no bell                                //~v51GI~
    	                                                           //~va7KI~
    if (!convtype)                                                 //~v47UI~
    {                                                              //~v47UI~
      if (!(convopt & UDBCSCHK_EUCHKCONV))                         //~v47UI~
      {                                                            //~v47UI~
        uerrmsg("Missing conversion option",                       //~v47UR~
				"変換オプションを指定して下さい");                 //~v47UR~
        return 4;                                                  //~v47UI~
      }                                                            //~v47UI~
#ifdef LNX                                                         //~v47UI~
      convtype=DBCSCONV_E2S;	//default with Z                   //~v47UR~
#else                                                              //~v47UI~
      convtype=DBCSCONV_S2E;                                       //~v47UR~
#endif                                                             //~v79sR~
      convopt|=(UDBCSCHK_KANAONLY|UDBCSCHK_EUCHKCONV); //euc hankaku katakana-->zenkaku//~v47UI~
    }                                                              //~v47UI~
	if (Sotheropt & OOPT_RESET)                                    //~va7KI~
    {                                                              //~va7KI~
		if (!swb2b)                                                //~va7KR~
        {                                                          //~va7KI~
        	uerrmsg("%s option is for B2B",                     //~va7KI~//~va7LR~
					"%s オプションは B2B 用です。",                //~va7LR~
                    EBCCMD_OPT_SETCP);                             //~va7LR~
        	return 4;                                              //~va7KI~
        }                                                          //~va7KI~
    }                                                              //~va7KI~
#ifndef DOSDOS                                                     //~v50iI~
    if (convtype!=UCSCONV_A2A)  //not M2M                          //~vaabI~
        if (*Scpfrom||*Scpto)                                      //~vaabM~
        {                                                          //~vaabM~
        	uerrmsg("'F:' or 'T:' option is for M2M only",         //~vaabM~
        			"'F:' と 'T:' オプションは M2M 用");           //~vaabM~
        	return 4;                                              //~vaabI~
        }                                                          //~vaabM~
	if (Sotheropt & OOPT_MBICU)                                    //~vad1I~
    {                                                              //~vad1I~
        if (!icuok)                                                //~vad1I~
        {                                                          //~vad1I~
            uerrmsg("ICU option is for M2M only",0);               //~vad1R~
        	return 4;                                              //~vad1I~
        }                                                          //~vad1I~
    }                                                              //~vad1I~
    if (ucsconvsw)                                                 //~v50iI~
    {                                                              //~v50iI~
    	if (noucsparmsw)                                           //~v50iI~
        	return fcmdcvconflict();                               //~v50iI~
        if (endianparmsw)                                          //~v50iI~
      		if (convtype==UCSCONV_F2S || convtype==UCSCONV_S2F)   //no ucs//~v50iR~
    	    	return fcmdcvconflict();                           //~v50iI~
        if (ibmnecparmsw||errchsw)                                 //~v50vR~
      		if (convtype!=UCSCONV_F2S && convtype!=UCSCONV_U2S)   //no ucs//~v50pI~
      		  if (convtype!=DBCSCONV_E2A && convtype!=DBCSCONV_A2E)   //no ucs//~v58SR~
      	       if (convtype!=DBCSCONV_X2E)                         //~v59sI~
      	       if (convtype!=UCSCONV_A2A)                          //~v79sR~
    	    	return fcmdcvconflict();                           //~v50pI~
        if (bomparmsw)                                             //~v50iI~
      		if (convtype==UCSCONV_U2S || convtype==UCSCONV_S2U)   //no ucs//~v50iR~
    	    	return fcmdcvconflict();                           //~v50iI~
      	if (convtype==UCSCONV_A2A)                                 //~v79sI~
        {                                                          //~v79sI~
	    	return fcmducsconv(Ppcw,pfh,convtype,(ULONG)errchm2m); //~v79wR~
        }                                                          //~v79sI~
        ucsopt|=(errch & UCVUCS_ERRCH);                            //~v50iI~
		ucsopt|=UCVUCS_NOERRMSG;	//no fmt err msg               //~v50iI~
    	return fcmducsconv(Ppcw,pfh,convtype,ucsopt);              //~v50iR~
    }                                                              //~v50iI~
    else 	//not ucs conv                                         //~v50iI~
    {                                                              //~v50iI~
    	if (ucsparmsw)                                             //~v50iI~
        	return fcmdcvconflict();                               //~v50iI~
        if (errchsw)                                               //~v51MI~
      		if (convtype!=DBCSCONV_E2A                             //~v51MI~
      	    &&  convtype!=DBCSCONV_X2E                             //~v59sI~
      		&&  convtype!=DBCSCONV_A2E)                            //~v51MI~
    	    	return fcmdcvconflict();                           //~v51MI~
    }                                                              //~v50iI~
//    if (convtype!=DBCSCONV_X2A  //ebc not supported              //~v59sR~
//    &&  Sotheropt & OOPT_MULT)                                   //~v59sR~
//    {                                                            //~v59sR~
////      uerrmsg("MULT is for X2C Without EBC only",0);           //~v59sR~
//        uerrmsg("MULT or -H is for X2C Without EBC only",0);     //~v59sR~
//        return 4;                                                //~v59sR~
//    }                                                            //~v59sR~
	if (Sotheropt & OOPT_OUTINPLACE)                               //~v54QR~
//  	if (!(Sotheropt & OOPT_MULT && convtype==DBCSCONV_X2A))	 //ebc not supported//~v58YR~
//  	if (!(convtype==DBCSCONV_X2A))	 //ebc not supported       //~v59sR~
		if (!(convtype==DBCSCONV_X2A||convtype==DBCSCONV_X2E))	 //x2c wit or w/o EBC option//~v59sI~
        {                                                          //~v54QI~
//          uerrmsg(":r is for X2C with MULT only",0);             //~v55KR~
            uerrmsg(":REP is for X2C with MULT or -H only",0);     //~v55KI~
			return 4;                                              //~v54QR~
        }                                                          //~v54QI~
#endif                                                             //~v50iI~
//  lineno=fcmddbcsconv(Ppcw,pfh,convtype,convopt);                //~v50eR~
#ifndef DOSDOS                                                     //~v59BI~
#ifdef WCSUPP                                                      //~v79jI~
    if (ebcopt & EBC2ASC_EXT)                                      //~v79jI~
    {                                                              //~v79jI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	if (!mapfile || !*mapfile)                                 //~va50I~
        {                                                          //~va50I~
          	if (!Spcfg)                                            //~va50I~
          	{                                                      //~va50I~
        		if (xeebc_init(XEEBCIO_GETDEFAULT,&Spcfg)||!Spcfg)         //~va50R~//~va5TR~
                {                                                  //~va50I~
		            Spcfg=0;                                       //~va50I~
		            uerrmsg("EBCDIC cfg file contains error,chk %s parm of INI file",//~va5TI~
        	    		"EBCDIC 変換 cfg ファイルにエラーがあります、INI ファイルの %s を調べる",//~va5TI~
 						XEEBC_INIFILEPARM);                        //~va5TI~
					return 4;                                      //~va50I~//~va5TR~
                }                                                  //~va50I~
          	}                                                      //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
            uerrmsg("map file option discarded,use %s parm of INI file",//~va50I~
            		"mapfile オプションは廃止、INI ファイルの %s で指定してください",//~va50I~
 					XEEBC_INIFILEPARM);                            //~va50R~
            uerrmsgcat("You can use \"-%s:cp\" option as alternative",//~va7FI~
            			"\"-%s:cp\" でもコードページ指定できます", //~va7FI~
                        	MODE_EBC);                             //~va7FI~
			return 4;                                              //~va50I~
        }                                                          //~va50I~
#else                                                              //~va50I~
    	if (!mapfile || !*mapfile)                                 //~v79jI~
        {                                                          //~v79jI~
          if (!Spcfg)                                              //~v79jI~
          {                                                        //~v79jI~
            uerrmsg("This is 1st time of M2B/B2M, requires -MF:mapfile parameter",0);//~v79jR~
			return 4;                                              //~v79jI~
          }                                                        //~v79jI~
        }                                                          //~v79jI~
        else                                                       //~v79jI~
        if (ucvext_mapinit(UCEIO_SAVECV|UCEIO_SAVEMAP,mapfile,&Spcfg))//~v79jR~
        {                                                          //~v79jI~
            Spcfg=0;                                               //~v79jI~
			return 4;                                              //~v79jI~
        }                                                          //~v79jI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		ucvext_getcvoption(ebcmbsw,Spcfg,&ebcopt);                 //~v79jR~
        if (pebccvname)	//CPEB parameter                           //~va7FI~
        {                                                          //~va7FI~
//  		rc=ucvebc4_createhandle(0,pebccvname,&handle);         //~va7FI~//~va7KR~
			rc=fileoptionchkebcconverter(0,pebccvname,0,&handle);  //~va7KI~
    		if (rc)                                                //~va7FI~
            {                                                      //~va7FI~
            	uerrmsgcat(";codepage err(%s)",0,                  //~vaz6R~
                        pebccvname);                               //~va7FI~
            	return 4;                                          //~va7FR~
            }                                                      //~va7FI~
    		Sebchandle=handle;                                     //~va7FI~
        }                                                          //~va7FI~
		if (PFH_ISEBC(pfh))                                    //~va7FI~
        {
          	if (convtype==DBCSCONV_E2A)  //b2m                       //~va7FI~
            {
        		if (!Sebchandle)                                           //~va7FI~
            		Sebchandle=pfh->UFHhandle;                         //~va7FI~
            }
            else	//m2b including b2b                            //~va7HI~
            {                                                      //~va7HI~
            	if (swb2b)	//B2B                                  //~va7HI~
                {                                                  //~va7HI~
                	if (Sebchandle==pfh->UFHhandle)                //~va7HI~
                    {                                              //~va7HI~
//                    	uerrmsg("No EBCDIC codepage change request",//~va7HR~//~vad1R~
                    	uerrmsg("No change in codepage",           //~vad1I~
                                "EBCDIC コードページの変更がありません");//~va7HI~
                        return 4;                                  //~va7HI~
                    }                                              //~va7HI~
                    Sotheropt|=OOPT_B2B;                           //~va7HI~
                    if (Sotheropt & OOPT_RESET)	//SETCP request    //~va7LI~
                    {                                              //~va7LI~
                    	Sb2bopt|=FSDT_B2B;    //for filesetdbcstblplh_handle//~va7LI~
						if (UCVEBCH_HANDLE_ISDBCSCV(Sebchandle))   //~va7LI~
                    		Sb2bopt|=FSDT_TGTDBCS;    //for filesetdbcstblplh_handle//~va7LI~
						if (UCVEBCH_HANDLE_ISDBCSCV(pfh->UFHhandle))//~va7LI~
                    		Sb2bopt|=FSDT_SRCDBCS;    //for filesetdbcstblplh_handle//~va7LI~
                    }                                              //~va7LI~
                }                                                  //~va7HI~
            }                                                      //~va7HI~
        }
        else                                                       //~va7HI~
        {                                                          //~va7HI~
            if (swb2b)	//B2B                                      //~va7HI~
            {                                                      //~va7HI~
                uerrmsg("B2B option is for EBCDIC file",           //~va7HI~
                        "B2B オプションは EBCDIC ファイル用です"); //~va7HI~
                return 4;                                          //~va7HI~
            }                                                      //~va7HI~
        }                                                          //~va7HI~
    }                                                              //~v79jI~
    else                                                           //~vaaaI~
    {                                                              //~vaaaI~
        if (pebccvname)	//CPEB parameter                           //~vaaaI~
        {                                                          //~vaaaI~
            uerrmsg("CPEB option is for B2B/M2B/B2M only",         //~vaaaI~
            		"CPEB オプションは B2B/M2B/B2M用です");        //~vaaaI~
            return 4;                                              //~vaaaI~
        }                                                          //~vaaaI~
    }                                                              //~vaaaI~
#endif                                                             //~v79jI~
//b2dd support internal DBCS mapping ebc to ucs ***                //~vaaeI~
//    if (convtype==DBCSCONV_E2A                                   //~vaaeR~
//    &&  Sotheropt & OOPT_UTF8)  //B2F                            //~vaaeR~
//    {                                                            //~vaaeR~
//        if (!Sebchandle                                          //~vaaeR~
//        &&  !(Spcfg && (Spcfg->UCECflag & UCECF_USE_CONVERTER))     //cfg file did not defined converter=0 or cfg not found//~vaaeR~
//        )                                                        //~vaaeR~
//        {                                                        //~vaaeR~
//            uerrmsg("CPEB option is required for B2F because EBCDIC cfg is not defined converter",//~vaaeR~
//                    "EBCDIC cfg ファイルが外部コンバーターを定義していない場合 M2F には CPEB オプションが必要です");//~vaaeR~
//            return 4;                                            //~vaaeR~
//        }                                                        //~vaaeR~
//        ebcopt|=EBC2ASC_EXT_TOUTF8;                              //~vaaeR~
//    }                                                            //~vaaeR~
    if (convtype==DBCSCONV_E2A                                     //~v58SR~
    ||  convtype==DBCSCONV_X2E                                     //~v59sI~
    ||  convtype==DBCSCONV_A2E)                                    //~v58SR~
    {                                                              //~v58SI~
		errch+=(errchdbcs<<8);                                     //~v58SR~
        convopt|=ebcopt;                                           //~v58SI~
    }                                                              //~v58SI~
#ifdef WCSUPP                                                      //~v79wI~
    if (ebcopt & EBC2ASC_EXT)                                      //~v79tI~
        errch=errchm2m;                                            //~v79tM~
#endif                                                             //~v79wI~
    Sebcopt=ebcopt; //parm to x2c with ebc option                  //~v59sI~
    oldhandle=pfh->UFHhandle;                                      //~va7LI~
#endif                                                             //~v59BI~
    rc=fcmddbcsconv(Ppcw,pfh,convtype,convopt,&lineno,errch);      //~v51MR~
  if (!rc)                                                         //~v50eR~
  {                                                                //~va7HI~
    uerrmsg("%ld line converted",                                  //~v47UI~
    		"%ld 行変換",                                          //~v47UI~
            lineno);                                               //~v47UR~
    if (swb2b)	//B2B                                              //~va7HI~
    {                                                              //~va7KI~
        uerrmsgcat(" (%s-->%s)",0,                                 //~va7HR~
                    ucvebc4_getcvname(0,oldhandle),ucvebc4_getcvname(0,Sebchandle));//~va7HI~//~va7LR~
		if (Sotheropt & OOPT_RESET)                                //~va7KI~
        	uerrmsgcat(" with %s",0,                               //~va7LR~
                    EBCCMD_OPT_SETCP);                             //~va7LI~
        else                                                       //~va7KI~
//      	uerrmsgcat(" ,Use \"EBC\" cmd to change current codepage",      //~va7KI~//~va7LR~//~vaz9R~
//          			",現在のコードページは \"EBC\" コマンドで変更できます");//~va7KR~//~vaz9R~
        	uerrmsgcat(" ,Use \"SETCP\" option or Use \"EBC SETCP=xxx\" cmd to change current codepage(disply by it)",//~vaz9R~
            			",現在のコードページは \"SETCP\" オプションを追加するか \"EBC SETCP=xxx\" コマンドで変更できます(其のコードページで\x95\\示)");//~vaz0R~
    }                                                              //~va7KI~
                                                                   //~va7HI~
  }                                                                //~va7HI~
//  return 0;                                                      //~v50eR~
    return rc;                                                     //~v50eI~
}//func_dbcsconv                                                   //~v47UR~
#ifndef DOSDOS                                                     //~v51NI~
//************************************************************     //~va7FI~
// fcmdgetopt                                                      //~va7FI~
//************************************************************     //~va7FI~
int fcmdgetopt(int Popt,UCHAR *Popd,UCHAR *Poptid,UCHAR **Popdvalue)//~va7FI~
{                                                                  //~va7FI~
	UCHAR *pc;                                                     //~va7FI~
    int len;                                                       //~va7FI~
//****************	                                               //~va7FI~
	pc=Popd;                                                       //~va7FI~
    if (*pc=='-'||*pc=='/')                                        //~va7FI~
    	pc++;                                                      //~va7FI~
//  if (!USTRHEADIS_IC(pc,Poptid))                                 //~vaz6R~
    if (!USTRHEADIS_IC_STR(pc,Poptid))                             //~vaz6I~
    	return 1;                                                  //~va7FI~
//  len=strlen(Poptid);                                            //~va7FI~//~vb2DR~
    len=(int)strlen(Poptid);                                       //~vb2DI~
    pc+=len;                                                       //~va7FI~
    if (*pc==':'||*pc=='=')                                        //~va7FI~
    	pc++;                                                      //~va7FI~
    *Popdvalue=pc;                                                 //~va7FI~
    return 0;                                                      //~va7FI~
}//fcmdgetopt                                                      //~va7FI~
//************************************************************     //~v51NI~
// fcmdgethexparm    lll-mmm:nnn fmt                               //~v51NI~
//*parm1:operand value                                             //~v51NI~
//*parm2:out:input offs                                            //~v51NI~
//*parm3:out:input len:0 for up to eol                             //~v51NR~
//*parm4:out:output offs:0 for at eol                              //~v51NR~
//*return:rc                                                       //~v51NI~
//************************************************************     //~v51NI~
int fcmdgethexparm(UCHAR *Popd,int *Ppinoffs,int *Pplen,int *Ppoutoffs)//~v51NI~
{                                                                  //~v51NI~
	int rc,pos1,pos2,pos3;                                         //~v51NI~
    UCHAR *posout;                                                 //~v54QR~
    long  pos1l,pos2l;                                             //~v51NI~
//*****************************                                    //~v51NI~
	posout=strchr(Popd,':');                                       //~v51NR~
    if (posout)                                                    //~v51NR~
    	*posout=0;	//for ugetnumrange;                            //~v51NR~
  if (posout==Popd) //no m-n parm                                  //~v54PI~
  {                                                                //~v54PI~
    rc=0;                                                          //~v54PI~
    pos1=1;                                                        //~v54PI~
    pos2=0;                                                        //~v54PI~
  }                                                                //~v54PI~
  else                                                             //~v54PI~
  {                                                                //~v54PI~
    rc=ugetnumrange(Popd,&pos1l,&pos2l);                           //~v51NR~
    pos1=(int)pos1l;                                               //~v51NI~
    pos2=(int)pos2l;                                               //~v51NI~
  }                                                                //~v54PI~
    if (posout)                                                    //~v51NI~
    	*posout=':';		//restore                              //~v51NR~
    if (rc>1)                                                      //~v51NI~
        return 4;                                                  //~v51NI~
    if (posout)                                                    //~v51NI~
    {                                                              //~v51NI~
      if (!stricmp(posout+1,"MAX"))                                //~v54PR~
      	pos3=X2C_OUTMAX;                                           //~v54PR~
      else                                                         //~v54QI~
      if (!stricmp(posout+1,"REP"))                                //~v54QR~
      	pos3=X2C_OUTINPLACE;                                       //~v54QI~
      else                                                         //~v54PI~
      {                                                            //~v54PI~
    	pos3=atoi(posout+1);                                       //~v51NR~
        if (!pos3)                                                 //~v51NI~
        	return 4;                                              //~v51NI~
    	pos3--;                                                    //~v51NM~
      }                                                            //~v54PI~
    }                                                              //~v51NI~
    else                                                           //~v51NI~
    	pos3=-1;                                                   //~v51NR~
    if (!pos1)                                                     //~v51NR~
    	return 4;                                                  //~v51NI~
    pos1--;                                                        //~v51NI~
    if (pos2)                                                      //~v51NI~
    {                                                              //~v51NI~
        if (pos2-pos1<2)                                           //~v51NR~
            return 4;                                              //~v51NR~
        if (posout)                                                //~v51NI~
        	if (pos3>pos1 && pos3<pos2)                            //~v51NR~
            	return 4;                                          //~v51NR~
    	pos2-=pos1;                                                //~v51NM~
    }                                                              //~v51NI~
    *Ppinoffs=pos1;                                                //~v51NR~
    *Pplen=pos2;                                                   //~v51NI~
    *Ppoutoffs=pos3;                                               //~v51NR~
    return 0;                                                      //~v51NI~
}//fcmdgethexparm                                                  //~v51NI~
//************************************************************     //~v55KI~
// fcmdxnotepchk:hex notation parameter chk                        //~v55KI~
// if last is quate(' or ") that is postfix if same quote is exist //~v55KI~
// if no postfix all is prefix                                     //~v55KI~
//*return:rc                                                       //~v55KI~
//************************************************************     //~v55KI~
int fcmdxnotepchk(UCHAR *Pxnoteparm)                               //~v55KI~
{                                                                  //~v55KI~
    char *pc;                                                      //~v55KR~
    int len;                                                       //~v55KI~
//*****************************                                    //~v55KI~
	pc=ustrstri(Pxnoteparm,"XX");                                  //~v55KR~
    if (pc && *(pc+2))                                             //~v55KR~
    {	                                                           //~v55KI~
//      len=(int)((ULONG)pc-(ULONG)Pxnoteparm);                    //~v55KI~//~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)Pxnoteparm);                    //~vafkI~
    	pc+=2;                                                     //~v55KI~
        if (strlen(pc)>=MAX_HEXNOTATION)                           //~v55KI~
        	return 4;                                              //~v55KI~
        strcpy(Shexnotationpost,pc);                               //~v55KI~
    }                                                              //~v55KI~
    else                                                           //~v55KI~
        len=(int)strlen(Pxnoteparm);                               //~v55KR~
    if (len>=MAX_HEXNOTATION)                                      //~v55KI~
        return 4;                                                  //~v55KI~
    memcpy(Shexnotationpre,Pxnoteparm,(UINT)len);                  //~v55KI~
    *(Shexnotationpre+len)=0;                                      //~v55KI~
    return 0;                                                      //~v55KI~
}//fcmdxnotepchk                                                   //~v55KI~
#endif                                                             //~v51NI~
//************************************************************     //~v47UI~
// fcmddbcsconv                                                    //~v47UI~
//*dbcs conversion                                                 //~v47UI~
//*parm1:pcw                                                       //~v47UI~
//*parm2:pfh                                                       //~v47UI~
//*parm3:conv type                                                 //~v47UI~
//*parm4:option han-kana zenkaku conv                              //~v47UI~
//*return:rc                                                       //~v47UI~
//************************************************************     //~v47UI~
//long fcmddbcsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,int Pconvopt)//~v50eR~
int fcmddbcsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,int Pconvopt,LONG *Pplineno,int Perrch)//~v51MR~
{                                                                  //~v47UI~
	PULINEH plh,plh1st=0;                                          //~v47UI~
	PULINEH plhx;                                                  //~v51QI~
	PULINEH plhsoprev=0;                                           //~v58TR~
    long convlineno=0;                                             //~v47UR~
	int len,len2=0,opt,dbcssw,rc;                                    //~v47UR~//~vafcR~
//  int buffsz=GFILEBUFFSZ,convlen;                                //~v50fI~//~vafcR~
    int buffsz=GFILEBUFFSZ,convlen=0;                              //~vafcI~
    int maxlen,maxcontlen;                                         //~v50eI~
    int contsw,contlen=0,jismode=0;                                //~v50hI~
    int contxsw=0;  //to chk all excluded split line               //~v51QI~
    char *pdata,*pdbcs,*pdataw;                                    //~v50fR~
    UCHAR *pbuff,*pbuff2;                                          //~v50fR~
    UCHAR contdata[4];                                             //~v50hI~
    int fgmopt,ebcopt,sipendsw=0,rc2,binfsw;                       //~v58TR~
    UCHAR *pdbcsw=NULL,*pebcdata;                                       //~va7HR~//~vafcR~
    int ebclen,optb2b;                                             //~va7HI~
    UCHAR *putf8data;                                              //~vaacI~
    int swsetlineerr;                                              //~vag8I~
//*****************************                                    //~v47UI~
#ifndef DOSDOS                                                     //~v51qI~
    if (Pconvtype==DBCSCONV_X2A)    //hexdump-->ascii              //~v51NI~
		return fcmdhex2ascii(Pconvopt,Ppcw,Ppfh,Pplineno,Perrch);  //~v51NI~
    if (Pconvtype==DBCSCONV_X2E)    //hexdump-->ascii              //~v51NI~
		return fcmdhex2ascii(Pconvopt|EBC2ASC_A2E,Ppcw,Ppfh,Pplineno,Perrch);//~v51NI~
//  if (Pconvtype==DBCSCONV_E2A)    //ebcdic->ascii                //~v58TR~
//  	return fcmdebc2ascii(Pconvopt,Ppcw,Ppfh,Pplineno,Perrch);  //~v58TR~
//  if (Pconvtype==DBCSCONV_A2E)    //ebcdic<-ascii                //~v58TR~
//  	return fcmdebc2ascii(Pconvopt|EBC2ASC_A2E,Ppcw,Ppfh,Pplineno,Perrch);//~v58TR~
    if (Pconvtype==DBCSCONV_K2L)    //ebcdic->ascii                //~v51JI~
		return fcmdkandl(Pconvopt,Ppcw,Ppfh,Pplineno);             //~v51JI~
#endif                                                             //~v51qI~
	binfsw=UCBITCHK(Ppfh->UFHflag4,UFHF4BIN);                      //~v58TI~
//  if (rc=fsubgetmaxlen(0,Ppfh,&maxlen,&maxcontlen),rc)           //~v58TR~
    if (Pconvtype==DBCSCONV_A2E     //ebcdic<-ascii                //~v58TR~
    ||  Pconvtype==DBCSCONV_E2A)    //ebcdic<-ascii                //~v58TI~
		fgmopt=FSGML_TABEXP;       //expand tab                    //~v58TI~
    else                                                           //~v58TI~
		fgmopt=0;                                                  //~v58TI~
    if (rc=fsubgetmaxlen(fgmopt,Ppfh,&maxlen,&maxcontlen),rc)      //~v58TI~
    	return rc;                                                 //~v50eI~
    if (maxlen>buffsz)                                             //~v50fI~
    {                                                              //~v50fI~
    	uerrmsg("Too long record,reload and retry",                //~v50fI~
				"行が長すぎる、再ロードして再試行してください。"); //~v50fI~
        return 4;                                                  //~v50fI~
    }                                                              //~v50fI~
UTRACEP("maxlen=%d,maxcont=%d\n",maxlen,maxcontlen);               //~v50eI~
//  if (maxlen!=maxcontlen)                                        //~v50hR~
//  {                                                              //~v50hR~
//      uerrmsg("split line exist,use xcv utility",                //~v50hR~
//              "分割行があります。変換ツール xcv を使用してください。");//~v50hR~
//      return 4;                                                  //~v50hR~
//  }                                                              //~v50hR~
    pbuff=umalloc((UINT)buffsz<<1);                                //~v50iR~
    UALLOCCHK(pbuff,UALLOC_FAILED);                                //~v50iI~
    pbuff2=pbuff+buffsz;                                           //~v50fI~
    opt=Pconvopt;                                                  //~v47UR~
//  opt|=UDBCSCHK_NOCLEAR;  //keep tab id on dbcstbl               //~v50fR~
    UPCTRREQ(Ppfh);         //write at save                        //~v47UI~
//  pdataw=Gfilebuff;                                              //~v49aR~
//  pdbcsw=Gfilebuff2;                                             //~v49aR~
//  for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v51GR~
    for (plh=Splhs                      ;plh;plh=UGETQNEXT(plh))   //~v51GI~
	{                                                              //~v47UI~
        if (plh==Splhe)     //reached to label range               //~v51GI~
            break;                                                 //~v51GI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v47UI~
        	continue;                                              //~v47UI~
        if (Sotheropt & OOPT_NX)	//skip excluded line           //~v51QI~
        {                                                          //~v54QI~
        	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //excluded  //~v51QI~
            {                                                      //~v51QI~
                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2)) //follower//~v51QI~
                {                                                  //~v51QI~
                    if (contxsw)                                   //~v51QI~
	                    continue;   //fully excluded               //~v51QI~
                }                                                  //~v51QI~
                else                                               //~v51QI~
                {                                                  //~v51QI~
                	contxsw=0;                                     //~v51QR~
        			if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//has follower//~v51QR~
                    {                                              //~v51QI~
						for (plhx=UGETQNEXT(plh);plhx;plhx=UGETQNEXT(plhx))//~v51QI~
                        {                                          //~v51QI~
				        	if (!UCBITCHK(plhx->ULHflag2,ULHF2EXCLUDED)) //not excluded//~v51QI~
                            	break;                             //~v51QI~
	        				if (!UCBITCHK(plhx->ULHflag2,ULHF2SPLIT1)) //end(has no follower)//~v51QI~
                            {                                      //~v51QI~
                            	contxsw=1;	//fully excluded       //~v51QI~
                                break;                             //~v51QR~
                            }                                      //~v51QI~
                        }                                          //~v51QI~
                        if (contxsw)                               //~v51QI~
                            continue;                              //~v51QI~
                    }//top line of split                           //~v51QI~
                }                                                  //~v51QI~
            }//excluded                                            //~v51QI~
            else	//not excluded                                 //~v51QI~
            	contxsw=0;                                         //~v51QI~
        }//opt_nx                                                  //~v54QI~
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1)) //splitted        //~v50hR~
	      	contsw=UDBCSCHK_CONTLINE;                              //~v50hI~
        else                                                       //~v50hI~
	      	contsw=0;                                              //~v50hI~
//      pdataw=Gfilebuff;                                          //~v50fR~
//      pdbcsw=Gfilebuff2;                                         //~v50fR~
        len=plh->ULHlen;                                           //~v47UI~
        pdata=plh->ULHdata;                                        //~v47UI~
//      pdbcs=plh->ULHdbcs;                                        //~v50fR~
		if (contlen)                                               //~v50hI~
        	memcpy(pbuff,contdata,(UINT)contlen);                  //~v50hI~
//      rc=filetabrestore(Ppfh,plh,pbuff,buffsz,&convlen);//tab reduce//~v50hR~
    if (Sotheropt & OOPT_B2B)                                      //~va7HI~
    {                                                              //~va7HI~
        pdataw=plh->ULHdata;                                       //~va7HI~
        pdbcsw=plh->ULHdbcs;                                       //~va7HI~
        convlen=len;                                               //~va7HI~
    }                                                              //~va7HI~
    else                                                           //~va7HI~
    {                                                              //~va7HI~
      if (Pconvtype==DBCSCONV_A2E)    //ebcdic<-ascii              //~v58TI~
      {                                                            //~va5YI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5YI~
        if (Sebcopt & EBC2ASC_EXT)	//M2B/B2M, so M2B              //~va5YI~
          rc=filetabrestore(Ppfh,plh,pbuff+contlen,buffsz-contlen,&convlen);//tab reduce//~va5YI~
        else                                                       //~va5YI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5YI~
      	rc=0;						//conv tab as space(no tab reduce)//~v58TI~
      }                                                            //~va5YI~
      else                                                         //~v58TI~
        rc=filetabrestore(Ppfh,plh,pbuff+contlen,buffsz-contlen,&convlen);//tab reduce//~v50hI~
        if (rc==FTRRC_TABDETECTED)	//tab restored to convwk       //~v50fI~
        {                                                          //~v50hI~
        	pdataw=pbuff;                                          //~v50fR~
            convlen+=contlen;                                      //~v50hI~
        }                                                          //~v50hI~
        else                                                       //~v50fI~
        {                                                          //~v50fI~
          if (contlen)                                             //~v50hI~
          {                                                        //~v50hI~
            	memcpy(pbuff+contlen,pdata,(UINT)len);//concatinate to cont data//~v50hI~
                convlen=len+contlen;                               //~v50hI~
        		pdataw=pbuff;		//not copyed                   //~v50hI~
          }                                                        //~v50hI~
          else//cont data exist                                    //~v50hI~
          {                                                        //~v50hI~
        	pdataw=pdata;		//not copyed                       //~v50fR~
            convlen=len;                                           //~v50fI~
          }                                                        //~v50hI~
        }                                                          //~v50fI~
    }//!B2B                                                        //~va7HI~
        dbcssw=0;                                                  //~v47UI~
        contlen=0;	//init                                         //~v50hI~
    	swsetlineerr=0;                                            //~vag8I~
      if (convlen>0)                                               //~v77NI~
        *contdata=*(pdataw+convlen-1);	//save last byte           //~v50hI~
		switch(Pconvtype)                                          //~v47UR~
        {                                                          //~v47UI~
		case DBCSCONV_E2S:                                         //~v47UI~
//  		rc=ueuc2shift(pdata,pdbcs,len,pdataw,pdbcsw,&len2,opt);//~v50fR~
//  		rc=ueuc2shift(pdataw,0,convlen,pbuff2,0,&len2,opt);    //~v50hR~
    		rc=ueuc2shift(pdataw,0,convlen,pbuff2,0,&len2,opt|contsw);//~v50hI~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;                                         //~v50hI~
            pdataw=pbuff2;                                         //~v50fI~
            break;                                                 //~v47UI~
		case DBCSCONV_S2E:                                         //~v47UR~
//  		rc=ushift2euc(pdata,pdbcs,len,pdataw,pdbcsw,&len2,opt);//~v50fR~
//  		rc=ushift2euc(pdataw,0,convlen,pbuff2,0,&len2,opt);    //~v50hR~
    		rc=ushift2euc(pdataw,0,convlen,pbuff2,0,&len2,opt|contsw);//~v50hI~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;                                         //~v50hI~
            pdataw=pbuff2;                                         //~v50fI~
            break;                                                 //~v49aI~
		case DBCSCONV_J2S:  //jis-->sjis                           //~v49aI~
//  		rc=ustrjis2sjis(0,pdata,len,pdataw,&len2);             //~v50fR~
//  		rc=ustrjis2sjis(0,pdataw,convlen,pbuff2,&len2);        //~v50hR~
          if (convlen)                                             //~v77NI~
    		rc=ustrjis2sjis(jismode|contsw,pdataw,convlen,pbuff2,&len2);//~v50hI~
          else                                                     //~v77NI~
            rc=len2=0;                                             //~v77NI~
            if (contsw)                                            //~v50hI~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v50hI~
            else                                                   //~v50hI~
            	jismode=0;                                         //~v50hI~
            contlen=(int)(((UINT)(rc & UDBCSCHK_RC_JISSPLIT)>>UDBCSCHK_RC_JISSPLITSHIFT));  //last dbcssplit//~v55KR~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;       //jissplit and dbcssplit is excusive//~v50hI~
            if (contlen)                                           //~v50hR~
            	memcpy(contdata,pdataw+convlen-contlen,(UINT)contlen);	//save alst byte//~v50iR~
            if ((opt & UDBCSCHK_EUCHKCONV) && (rc & UDBCSCHK_RC_HANKANAFOUND))//~v49aI~
            {                                                      //~v49aI~
//  			rc=ushift2euc(pdataw,0,len2,pdbcsw,0,&len2,opt|UDBCSCHK_KANAONLY);//~v50fR~
    			rc=ushift2euc(pbuff2,0,len2,pbuff,0,&len2,opt|UDBCSCHK_KANAONLY);//~v50fI~
//              memcpy(pdataw,pdbcsw,(UINT)len2);                  //~v50fR~
                pdataw=pbuff;                                      //~v50fR~
            }                                                      //~v49aI~
            else                                                   //~v50fI~
                pdataw=pbuff2;                                     //~v50fR~
//          pdbcsw=0;   //set dbcs tbl later                       //~v50fR~
            break;                                                 //~v47UI~
		case DBCSCONV_S2J:  //sjis-->jis                           //~v50gI~
//  		rc=ustrsjis2jis(0,pdataw,convlen,pbuff2,&len2);        //~v50hR~
          if (convlen)                                             //~v77NI~
    		rc=ustrsjis2jis(opt|jismode|contsw,pdataw,convlen,pbuff2,&len2);//~v50hR~
          else                                                     //~v77NI~
            rc=len2=0;                                             //~v77NI~
            if (contsw)                                            //~v50hI~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v50hI~
            else                                                   //~v50hI~
            	jismode=0;                                         //~v50hI~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;                                         //~v50hI~
            pdataw=pbuff2;                                         //~v50gI~
            break;                                                 //~v50gI~
		case DBCSCONV_J2E:  //jis-->euc                            //~v49aI~
//  		rc=ustrjis2sjis(0,pdata,len,pdbcsw,&len2);//dbcsw temp use//~v50fR~
//  		rc=ustrjis2sjis(0,pdataw,convlen,pbuff2,&len2);//dbcsw temp use//~v50hR~
          if (convlen)                                             //~v77NI~
    		rc=ustrjis2sjis(jismode|contsw,pdataw,convlen,pbuff2,&len2);//dbcsw temp use//~v50hI~
          else                                                     //~v77NI~
            rc=len2=0;                                             //~v77NI~
            if (contsw)                                            //~v50hI~
            	jismode=rc & UDBCSCHK_RC_JISMODE;	//pass to next cond line//~v50hI~
            else                                                   //~v50hI~
            	jismode=0;                                         //~v50hI~
            contlen=(int)(((UINT)(rc & UDBCSCHK_RC_JISSPLIT)>>UDBCSCHK_RC_JISSPLITSHIFT));  //last dbcssplit//~v55KR~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;                                         //~v50hI~
            if (contlen)                                           //~v50hR~
            	memcpy(contdata,pdataw+convlen-contlen,(UINT)contlen);	//save alst byte//~v50iR~
        	if (rc & (UDBCSCHK_RC_DBCSFOUND|UDBCSCHK_RC_HANKANAFOUND))//~v49aR~
            {                                                      //~v50fI~
//  			rc=ushift2euc(pdbcsw,0,len2,pdataw,0,&len2,opt);   //~v50fR~
    			rc|=ushift2euc(pbuff2,0,len2,pbuff,0,&len2,opt);   //~v50gR~
                pdataw=pbuff;                                      //~v50fR~
            }                                                      //~v50fI~
            else                                                   //~v50fI~
                pdataw=pbuff2;                                     //~v50fR~
//          pdbcsw=0;   //set dbcs tbl later                       //~v50fR~
            break;                                                 //~v49aI~
		case DBCSCONV_E2J:  //jis-->euc                            //~v50gI~
//  		rc=ueuc2shift(pdataw,0,convlen,pbuff2,0,&len2,opt);    //~v50hR~
    		rc=ueuc2shift(pdataw,0,convlen,pbuff2,0,&len2,opt|contsw);//~v50hI~
            if (rc & UDBCSCHK_RC_DBCSSPLIT)	//last dbcssplit       //~v50hI~
            	contlen=1;                                         //~v50hI~
          if (len2)                                                //~v77NI~
    		rc|=ustrsjis2jis(0,pbuff2,len2,pbuff,&len2);           //~v50gR~
            pdataw=pbuff;                                          //~v50gI~
            break;                                                 //~v50gI~
#ifndef DOSDOS                                                     //~v59BI~
		case DBCSCONV_A2E:  //sjis-->ebc                           //~v58TI~
            if (Sotheropt & OOPT_B2B)                              //~va7HM~
            {                                                      //~va7HM~
//          	optb2b=XEEBCO_CVCTL|XEEBCO_ERRREP;//~va7HR~        //~va7LR~//~vag6R~
            	optb2b=XEEBCO_CVCTL|XEEBCO_ERRREP|XEEBCO_ERRREP3; //set subchar//~vag6I~
              rc=                                                  //~vag8I~
				xeebc_b2b(optb2b,Ppfh->UFHhandle,Sebchandle,pdataw,pdbcsw,convlen,&pebcdata,0/*dbcs:setdbcstbl by src handle*/,&ebclen);//~va7HM~
//              rc=0;                                              //~va7HM~//~vag8R~
				if (rc)                                            //~vag8I~
                	swsetlineerr=1;	                               //~vag8R~
                len2=ebclen;                                       //~va7HM~
                pdataw=pebcdata;                                   //~va7HM~
                break;                                             //~va7HM~
            }                                                      //~va7HM~
            if (Sotheropt & OOPT_UTF8)	//F2B                      //~vaacI~
            {                                                      //~vaacI~
            	optb2b=XEEBCO_ERRREP;                              //~vaacI~
//				rc=xeebc_f2b(optb2b,Sebcopt,Sebchandle,pdataw,convlen,&pebcdata,&len2);//~vaacR~//~vaadR~//~vb2ER~
  				rc=xeebc_f2b(optb2b,(int)Sebcopt,Sebchandle,pdataw,convlen,&pebcdata,&len2);//~vb2EI~
                UTRACEP("fcmd5 F2B rc=%d\n",rc);                   //~vaacI~
                pdataw=pebcdata;                                   //~vaacI~
                break;                                             //~vaacI~
            }                                                      //~vaacI~
        	ebcopt=Pconvopt|sipendsw;                              //~v58TM~
            if (contsw||binfsw)                                    //~v58TR~
            	ebcopt|=EBC2ASC_LNCONT;                            //~v58TR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5VI~
		  	if (!(Spcfg && (Spcfg->UCECflag & UCECF_USE_CONVERTER)))	//cfg file did not defined converter=0 or cfg not found//~va5VR~
          		ebcopt&=~EBC2ASC_EXT;	//user internal sjis map   //~va5VI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5VI~
//  		rc2=ucvasc2ebc(ebcopt,pdataw,0,pbuff2,convlen,Perrch,&len2);//~v58TR~//~va7FR~
    		rc2=ucvasc2ebc_handle(ebcopt,Sebchandle,pdataw,0,pbuff2,convlen,Perrch,&len2);//~va7FI~
            if (rc2 & EBC2ASC_RC_HALFBYTE)	//last dbcssplit       //~v58TI~
            	contlen=1;                                         //~v58TI~
            if (rc2 & EBC2ASC_RC_SIPEND)	//last dbcssplit       //~v58TI~
            	sipendsw=EBC2ASC_SOCONT;                           //~v58TI~
            else                                                   //~v58TI~
            	sipendsw=0;                                        //~v58TI~
			if (rc2 & EBC2ASC_RC_DBCSFOUND)                        //~v58TI~
            	rc|=UDBCSCHK_RC_DBCSFOUND;                         //~v58TI~
			if (rc2 & EBC2ASC_RC_ISRTTOPSO)	//SO inserted to top of line//~v58TR~
            {                                                      //~v58TI~
	            if (binfsw			//contline                     //~v58TI~
	            ||  UCBITCHK(plh->ULHflag2,ULHF2SPLIT2)) //follower//~v58TI~
	            	if (plhsoprev && plhsoprev==UGETQPREV(plh))    //~v58TR~
	                	plhsoprev->ULHlen--;	//drop last space  //~v58TR~
            }                                                      //~v58TI~
            plhsoprev=0;  //for space rep by so/si option,if line is splited by space//~v58TI~
            if (contsw) //has follower                             //~v58TR~
            {                                                      //~v58TI~
            	if (len2 && *(pbuff2+len2-1)==CHAR_EBC_SPACE)//left eol space//~v58TR~
                	plhsoprev=plh;	//last is space,may next line replace(drop) it.//~v58TR~
            }                                                      //~v58TI~
            pdataw=pbuff2;                                         //~v58TR~
            break;                                                 //~v58TI~
		case DBCSCONV_E2A:  //sjis-->ebc                           //~v58TI~
            if (Sotheropt & OOPT_UTF8)  //B2F                      //~vaacR~
            {                                                      //~vaacR~
                optb2b=XEEBCO_ERRREP;                              //~vaacR~
                if (binfsw)                                        //~vaacR~
                    optb2b|=XEEBCO_BIN; //no DBCS                  //~vaacR~
//              rc=xeebc_b2f(optb2b,Sebcopt,Sebchandle,pdataw,convlen,&putf8data,&len2);//~vaacR~//~vb2ER~
                rc=xeebc_b2f(optb2b,(int)Sebcopt,Sebchandle,pdataw,convlen,&putf8data,&len2);//~vb2EI~
                UTRACEP("fcmd5 B2F rc=%d\n",rc);                   //~vaacR~
                pdataw=putf8data;                                  //~vaacR~
                break;                                             //~vaacR~
            }                                                      //~vaacR~
        	ebcopt=Pconvopt|sipendsw;                              //~v58TI~
//          if (contsw||binfsw)                                    //~v78QR~
            if (contsw||binfsw||(Sotheropt & OOPT_MULTLINE))       //~v78QI~
            	ebcopt|=EBC2ASC_LNCONT;                            //~v58TR~
            if (!contsw && (Pconvopt & EBC2ASC_SOSIAS))	//optio to asume SO at top of line//~v58VR~
            	ebcopt|=EBC2ASC_SOCONT;                            //~v58VI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5TI~
		  	if (!(Spcfg && (Spcfg->UCECflag & UCECF_USE_CONVERTER)))	//cfg file did not defined converter=0 or cfg not found//~va5TI~//~va5VR~
          		ebcopt&=~EBC2ASC_EXT;	//user internal sjis map   //~va5TI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5TI~
//			rc2=ucvebc2asc(ebcopt,pdataw,0,pbuff2,convlen,Perrch,&len2);//~v58TR~//~va7FR~
  			rc2=ucvebc2asc_handle(ebcopt,Sebchandle,pdataw,0,pbuff2,convlen,Perrch,&len2);//~va7FI~
            if (rc2 & EBC2ASC_RC_HALFBYTE)	//last dbcssplit       //~v58TR~
            	contlen=1;                                         //~v58TI~
            if (rc2 & EBC2ASC_RC_SIPEND)	//last dbcssplit       //~v58TI~
            	sipendsw=EBC2ASC_SOCONT;                           //~v58TI~
            else                                                   //~v58TI~
            	sipendsw=0;                                        //~v58TI~
			if (rc2 & EBC2ASC_RC_DBCSFOUND)                        //~v58TI~
            	rc|=UDBCSCHK_RC_DBCSFOUND;                         //~v58TI~
            pdataw=pbuff2;                                         //~v58TI~
            break;                                                 //~v58TI~
#endif //DOSDOS                                                    //~v59BI~
        }//Sconvopt                                                //~v47UI~
        if (opt & UDBCSCHK_KANAONLY)                               //~v47UI~
        	dbcssw=(rc & UDBCSCHK_RC_HANKANAFOUND);                //~v47UI~
        else                                                       //~v47UI~
        	dbcssw=(rc & UDBCSCHK_RC_DBCSFOUND)                    //~v47UR~
            	   ||((opt & UDBCSCHK_EUCHKCONV) && (rc & UDBCSCHK_RC_HANKANAFOUND));//~v47UR~
//  	if (dbcssw)         //contain dbcs                         //~v50fR~
//  	if (dbcssw || len2!=len)	//dbcs detected or len changed //~v51GR~
//  	if (dbcssw || len2!=convlen)	//dbcs detected or len changed//~v58TR~
    	if (dbcssw || len2!=convlen 	//dbcs detected or len changed//~v58TI~
        ||  Pconvtype==DBCSCONV_A2E     //ebcdic<-ascii            //~v58TR~
        ||  Pconvtype==DBCSCONV_E2A)    //ebcdic->ascii            //~v58TI~
        {                                                          //~v47UI~
        	convlineno++;                                          //~v47UI~
	    	if (!plh1st)                                           //~v47UI~
            	plh1st=plh;                                        //~v47UI~
			if (len2>plh->ULHbufflen)                              //~v47UM~
				if (fileexpandbuff(plh,len2)==UALLOC_FAILED)		//expand buff//~v47UM~
                {                                                  //~v50fI~
                	ufree(pbuff);                                  //~v50fI~
               		return 4;                                      //~v47UM~
                }                                                  //~v50fI~
//			if (rc=undoupdate(Ppcw,plh,UUHTCIDCLEAR),rc)	//prepare undo and update process//~v50iR~
  			if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v50iI~
            {                                                      //~v50fI~
                ufree(pbuff);                                      //~v50fI~
                return rc;                                         //~v47UI~
            }                                                      //~v50fI~
            if (swsetlineerr)                                      //~vag8I~
				filesetlineerr(plh);                               //~vag8I~
            pdata=plh->ULHdata; //addr change if expanded          //~v47UI~
            pdbcs=plh->ULHdbcs;                                    //~v47UI~
            memcpy(pdata,pdataw,(UINT)len2);                       //~v50fR~
            if (pdbcs)                                             //~v50fR~
            {                                                      //~v50fR~
//            if (pdbcsw)                                          //~v50fR~
//  	        memcpy(pdbcs,pdbcsw,(UINT)len2);                   //~v50fR~
//          	filesetdbcstbl(pdata,pdbcs,len2,FSDT_TABSAVE);     //~v50fR~
    		  if (PFH_ISEBC(Ppfh))                                 //~va7FI~
//  			filesetdbcstblplh(FSDT_EBC,Ppfh,plh,0/*pos*/,len2);//~va7FR~//~va7LR~
    			filesetdbcstblplh_handle(FSDT_EBC|FSDT_CVCMD|Sb2bopt,Sebchandle,Ppfh,plh,0/*pos*/,len2);//~va7LR~
              else                                                 //~va7FI~
            	filesetdbcstbl(pdata,pdbcs,len2,0);                //~v50fI~
//                if (len2!=len)  //len changed                    //~v50fR~
//                {                                                //~v50fR~
                plh->ULHlen=len2;   //len update undo not avail    //~v50fR~
//              if (filetabexp(1,plh,0,&len2)==UALLOC_FAILED)   //tab re-expand(len update)//~v50fR~
                if (filetabexp(0,plh,0,&len2)==UALLOC_FAILED)   //initial expand,Gfilebuff used//~v50fI~
                {                                                  //~v50fR~
                    ufree(pbuff);                                  //~v50fR~
                    return UALLOC_FAILED;                          //~v50fR~
                }                                                  //~v50fR~
//                }                                                //~v50fR~
            }                                                      //~v50fR~
            else    //not yet expanded                             //~v50fR~
                plh->ULHlen=len2;   //len update undo not avail    //~v50fR~
		}                                                          //~v47UI~
	}//all line                                                    //~v47UI~
    ufree(pbuff);                                                  //~v50fI~
	if (UBITCHKALL(Sotheropt,OOPT_B2B|OOPT_RESET))                                //~va7KI~//~va7LI~
        opt2resethandle(0,Ppcw,Ppfh,Sebchandle);                //~va7KR~//~va7LR~
    UPCTRREQ(Ppfh);         //write at save                        //~v47UI~
    if (plh1st)                                                    //~v47UI~
    	undocsrmove(Ppcw,plh1st);                                  //~v47UI~
//  return convlineno;                                             //~v50eR~
    *Pplineno=convlineno;                                          //~v50eI~
    return 0;                                                      //~v50eI~
}//fcmddbcsconv                                                    //~v47UI~
#ifndef DOSDOS                                                     //~v50iI~
////************************************************************   //~v58TR~
//// fcmdebc2ascii                                                 //~v58TR~
////*ebcdic-->ascii                                                //~v58TR~
////*parm1:pcw                                                     //~v58TR~
////*parm2:pfh                                                     //~v58TR~
////*return:rc                                                     //~v58TR~
////************************************************************   //~v58TR~
//int fcmdebc2ascii(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno,int Perrch)//~v58TR~
//{                                                                //~v58TR~
//    PULINEH plh;                                                 //~v58TR~
//    long convlineno=0;                                           //~v58TR~
//    int rc,len,opt;                                              //~v58TR~
////  int a2esw;                                                   //~v58TR~
//    UCHAR *pdata,*pdbcs;                                         //~v58TR~
////*****************************                                  //~v58TR~
//    if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                      //~v58TR~
//    {                                                            //~v58TR~
//        uerrmsg("Open file by binary for EBCDIC conversion",     //~v58TR~
//                "EBCDIC 変換する時はバイナリーモードで開いてください。");//~v58TR~
//        return 4;                                                //~v58TR~
//    }                                                            //~v58TR~
//    opt=Popt;                                                    //~v58TR~
////  a2esw=Popt&EBC2ASC_A2E;                                      //~v58TR~
//    UPCTRREQ(Ppfh);         //write at save                      //~v58TR~
////  for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh)) //~v58TR~
//    for (plh=Splhs                      ;plh;plh=UGETQNEXT(plh)) //~v58TR~
//    {                                                            //~v58TR~
//        if (plh==Splhe)     //reached to label range             //~v58TR~
//            break;                                               //~v58TR~
//        if (plh->ULHtype!=ULHTDATA) //file data                  //~v58TR~
//            continue;                                            //~v58TR~
//        if (Sotheropt & OOPT_NX)    //skip excluded line         //~v58TR~
//            if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //excluded//~v58TR~
//                continue;                                        //~v58TR~
//        if (rc=undoupdate(Ppcw,plh,UUHTREP),rc) //prepare undo and update process//~v58TR~
//            return rc;                                           //~v58TR~
//        pdata=plh->ULHdata;                                      //~v58TR~
//        pdbcs=plh->ULHdbcs;                                      //~v58TR~
//        len=  plh->ULHlen;                                       //~v58TR~
////      ucvebc_2asc(opt,pdata,pdata,len);                        //~v58TR~
////    if (a2esw)                                                 //~v58TR~
////      len=          //may reduced by tab expand                //~v58TR~
////      ucvasc2ebc(opt,pdata,pdbcs,pdata,len,(UCHAR)Perrch);    //0:repchar-->'?'//~v58TR~
////      ucvasc2ebc(opt,pdata,pdbcs,pdata,len,Perrch);   //0:repchar-->'?'//~v58TR~
////    else                                                       //~v58TR~
////      len=                                                     //~v58TR~
////      ucvebc2asc(opt,pdata,pdbcs,pdata,len,(UCHAR)Perrch);    //0:repchar-->'?'//~v58TR~
////      ucvebc2asc(opt,pdata,pdbcs,pdata,len,Perrch);   //0:repchar-->'?'//~v58TR~
//        ucvebc2asc(opt,pdata,pdbcs,pdata,len,Perrch,&len);  //0:repchar-->'?'//~v58TR~
//        plh->ULHlen=len;                                         //~v58TR~
//        if (pdbcs)                                               //~v58TR~
//        {                                                        //~v58TR~
////          memset(pdbcs,0,(UINT)len);                           //~v58TR~
//            filesetdbcstbl(pdata,pdbcs,len,0);                   //~v58TR~
//            if (filetabexp(0,plh,0,&len)==UALLOC_FAILED)   //initial expand,Gfilebuff used//~v58TR~
//                return UALLOC_FAILED;                            //~v58TR~
//        }                                                        //~v58TR~
//        convlineno++;                                            //~v58TR~
//    }//all line                                                  //~v58TR~
//    UPCTRREQ(Ppfh);         //write at save                      //~v58TR~
//    *Pplineno=convlineno;                                        //~v58TR~
//    return 0;                                                    //~v58TR~
//}//fcmdebc2ascii                                                 //~v58TR~
//************************************************************     //~v51NI~
// fcmdhex2ascii                                                   //~v51NI~
//*ebcdic-->ascii                                                  //~v51NI~
//*parm1:pcw                                                       //~v51NI~
//*parm2:pfh                                                       //~v51NI~
//*return:rc                                                       //~v51NI~
//************************************************************     //~v51NI~
int fcmdhex2ascii(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno,int Perrch)//~v51NI~
{                                                                  //~v51NI~
	PULINEH plh;                                                   //~v51NI~
    long convlineno=0;                                             //~v51NI~
    int rc,len,cvlen,maxlen,maxcontlen,outoffs;                    //~v51NR~
    int maxright;                                                  //~v54PI~
    int hexlen;                                                    //~v59sR~
    int errctr=0;                                                  //~v58YI~
    UCHAR *pdata,*pbuff;                                           //~v51NR~
    int socontsw=0,rc2,splitch=-1;                                 //~v78RR~
//*****************************                                    //~v51NI~
    if (Sebcopt & EBC2ASC_DBCS) //DBCS chk                         //~v78RI~
        Sebcopt|=EBC2ASC_LNCONT;   //ucvebc2asc returns rc SIPEND/HALFBYTE//~v78RI~
    if (rc=fsubgetmaxlen(FSGML_TABEXP,Ppfh,&maxlen,&maxcontlen),rc)//expand tab//~v51NI~
    	return rc;                                                 //~v51NI~
    maxlen++;		//for dbcs split                               //~v78RM~
    maxright=maxlen;                                               //~v54PI~
  if (Sotheropt & OOPT_MULT)                                       //~v54NI~
    maxlen=maxlen*2;                                               //~v54NI~
  else                                                             //~v54NI~
    maxlen=(maxlen+1)/2;                                           //~v51NI~
    if (!maxlen)                                                   //~v51NI~
        maxlen=8;       //avoid umalloc err                        //~v51NI~
    pbuff=umalloc((UINT)(maxlen<<1));                              //~v51NI~
    UALLOCCHK(pbuff,UALLOC_FAILED);                                //~v51NI~
//  a2esw=Popt&EBC2ASC_A2E;                                        //~v59sR~
    UPCTRREQ(Ppfh);         //write at save                        //~v51NI~
    for (plh=Splhs;plh;plh=UGETQNEXT(plh))                         //~v51NI~
	{                                                              //~v51NI~
        if (plh==Splhe)     //reached to label range               //~v51NI~
            break;                                                 //~v51NI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v51NI~
        	continue;                                              //~v51NI~
        if (Sotheropt & OOPT_NX)	//skip excluded line           //~v51QI~
        	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //excluded  //~v51QI~
		        continue;                                          //~v51QI~
        pdata=plh->ULHdata;                                        //~v51NI~
        len=  plh->ULHlen;                                         //~v51NI~
        if (!(hexlen=Shexlen))                                     //~v51NI~
        	hexlen=len;                                            //~v51NI~
//      if (fcmdhexconv(pdata,len,Shexinoffs,hexlen,pbuff,&cvlen))	//not valid line//~v54QR~
//      if (fcmdhexconv(plh,pdata,len,Shexinoffs,hexlen,pbuff,&cvlen))	//not valid line//~v59sR~
        if (fcmdhexconv(Popt,plh,pdata,len,Shexinoffs,hexlen,pbuff,&cvlen,Perrch))	//not valid line//~v59sI~
        {                                                          //~v58YI~
        	socontsw=0;                                            //~v78RI~
            splitch=-1;                                            //~v78RI~
        	errctr++;                                              //~v58YI~
        	continue;                                              //~v51NI~
        }                                                          //~v58YI~
        if ((Popt & EBC2ASC_A2E)                                   //~v78RI~
        &&  (Sebcopt & EBC2ASC_DBCS)) //SO/SI consideration        //~v78RR~
        {                                                          //~v78RI~
        	if (splitch>=0)                                        //~v78RI~
            {                                                      //~v78RI~
            	memmove(pbuff+1,pbuff,(UINT)cvlen);                //~v78RI~
                *pbuff=(UCHAR)splitch;                             //~v79wR~
                cvlen++;                                           //~v78RI~
            }                                                      //~v78RI~
            splitch=-1;                                            //~v78RI~
//  	  	rc2=ucvebc2asc(Sebcopt|socontsw,pbuff,0,pbuff,cvlen,Perrch,&cvlen);	//evc->asc conv//~v78RI~//~va7FR~
//  	  	rc2=ucvebc2asc_handle(Sebcopt|socontsw,Sebchandle,pbuff,0,pbuff,cvlen,Perrch,&cvlen);	//evc->asc conv//~va7FR~//~vb2ER~
    	  	rc2=ucvebc2asc_handle((int)Sebcopt|socontsw,Sebchandle,pbuff,0,pbuff,cvlen,Perrch,&cvlen);	//evc->asc conv//~vb2EI~
            if (rc2 & EBC2ASC_RC_SIPEND)                           //~v78RI~
            {	                                                   //~v78RI~
            	if (rc2 & EBC2ASC_RC_HALFBYTE)	//last split dbcs  //~v78RI~
                	splitch=*(pbuff+cvlen);  //ucvebc2asc returns convlen//~v78RR~
            	socontsw=EBC2ASC_SOCONT; //nextline assume so      //~v78RI~
            }                                                      //~v78RI~
            else                                                   //~v78RI~
            	socontsw=0;                                        //~v78RI~
        }                                                          //~v78RI~
  		if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v51NI~
//      	break;                                                 //~v530R~
  			return rc;		//UALLOC_FAILED                        //~v530I~
//    	if (a2esw)                                                 //~v59sR~
//      	cvlen=ucvebc2asc(Popt,pbuff,0,pbuff,cvlen,(UCHAR)Perrch);	//evc->asc conv//~v58TR~
//      	cvlen=ucvebc2asc(Popt,pbuff,0,pbuff,cvlen,Perrch,&cvlen);	//evc->asc conv//~v59rR~
//      	ucvebc2asc(Popt,pbuff,0,pbuff,cvlen,Perrch,&cvlen);	//evc->asc conv//~v59sR~
        setdbcstbl(pbuff,pbuff+maxlen,cvlen);                      //~v51NR~
        setdbcstbltabid(SDTTI_SETTABFOUND,plh,pbuff,pbuff+maxlen,cvlen);	//conv tab to tabid on dbcstbl//~v74xR~
      if (Sotheropt & OOPT_OUTINPLACE)                             //~v54QR~
      {                                                            //~v54QI~
        outoffs=Shexinoffs;                                        //~v54QI~
        if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_NOREV,pbuff,pbuff+maxlen,cvlen,plh,outoffs))>1) //block insert//~v54QI~
        	break;                                                 //~v54QI~
        plh->ULHlen=outoffs+cvlen;                                 //~v54QI~
      }                                                            //~v54QI~
      else                                                         //~v54QI~
      {                                                            //~v54QI~
        if ((outoffs=Shexoutoffs)<0)	//outoffs parm missing     //~v51NR~
        {                                                          //~v54PI~
          if (outoffs==X2C_OUTMAX)                                 //~v54PR~
            outoffs=maxright;                                      //~v54PI~
          else                                                     //~v54PI~
        	outoffs=len;                                           //~v51NI~
        }                                                          //~v54PI~
        if ((rc=charcap2(Ppcw,CHAROPBINS|CHARCAP2_NOREV,pbuff,pbuff+maxlen,cvlen,plh,outoffs))>1) //block insert//~v51NR~
        	break;                                                 //~v51NI~
      }                                                            //~v54QI~
        convlineno++;                                              //~v51NI~
	}//all line                                                    //~v51NI~
    UPCTRREQ(Ppfh);         //write at save                        //~v51NI~
    *Pplineno=convlineno;                                          //~v51NI~
    ufree(pbuff);                                                  //~v51NI~
    if (!convlineno && errctr)	//all line err                     //~v58YI~
    {                                                              //~v58YI~
  		if (Sotheropt & OOPT_MULT)	//no MULT parm                 //~v58YR~
        	uerrmsg("No line has valid hex digit string only,try -H option or insert delimiter.",//~v58YI~
            		"HEX数字のみを含む行がありません。\"-H\"を試すか分離文字を入れてください。");//~v58YI~
  		else                                                       //~v58YR~
        	uerrmsg("No line has valid hex digit string only,try MULT or -H option.",//~v58YI~
            		"HEX数字のみを含む行がありません。\"MULT\"や\"-H\"オプションを試してみてください。");//~v58YR~
        return 4;                                                  //~v58YI~
    }                                                              //~v58YI~
    return 0;                                                      //~v51NI~
}//fcmdhex2ascii                                                   //~v51NI~
//************************************************************     //~v51NI~
// fcmdhexconv                                                     //~v51NI~
//*hex dump data conv to binary                                    //~v51NI~
//*parm1:data                                                      //~v51NI~
//*parm2:data len                                                  //~v51NI~
//*parm3:conv start offs                                           //~v51NI~
//*parm4:conv len                                                  //~v51NI~
//*parm5:out area                                                  //~v51NI~
//*return:rc                                                       //~v51NI~
//************************************************************     //~v51NI~
//int fcmdhexconv(UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen)//~v54QR~
//int fcmdhexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen)//~v59sR~
int fcmdhexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,int Poffs,int Pcvlen,UCHAR *Ppout,int *Poutlen,int Perrch)//~v59sI~
{                                                                  //~v51NI~
    int cvlen,binlen,chklen;                                       //~v51NR~
    int reslen,rc;                                                 //~v59qI~
//*****************************                                    //~v51NI~
	if ((cvlen=Plen-Poffs)<=0)                                     //~v51NI~
    	return 4;                                                  //~v51NI~
    if (Pcvlen<cvlen)                                              //~v51NI~
    {                                                              //~v59qI~
        reslen=cvlen-Pcvlen;                                       //~v59qI~
    	cvlen=Pcvlen;                                              //~v51NI~
    }                                                              //~v59qI~
    else                                                           //~v59qI~
        reslen=0;                                                  //~v59qI~
    if (Sotheropt & OOPT_XNOTEPARM)                                //~v55KI~
//      return (fcmdxnotehexconv(Pplh,Pdata+Poffs,cvlen,Ppout,Poutlen)==0);//rc word count conved//~v59sR~
        return (fcmdxnotehexconv(Popt,Pplh,Pdata+Poffs,cvlen,Ppout,Poutlen,Perrch)==0);//rc word count conved//~v59sI~
    else                                                           //~v55KI~
    if (Sotheropt & OOPT_MULT)                                     //~v54NI~
    {                                                              //~v59qI~
//      return (fcmdmulthexconv(Pdata+Poffs,cvlen,Ppout,Poutlen)==0);//rc word count conved//~v54QR~
//      return (fcmdmulthexconv(Pplh,Pdata+Poffs,cvlen,Ppout,Poutlen)==0);//rc word count conved//~v59qR~
//      rc=(fcmdmulthexconv(Pplh,Pdata+Poffs,cvlen,Ppout,Poutlen)==0);//rc word count conved//~v59sR~
        rc=(fcmdmulthexconv(Popt,Pplh,Pdata+Poffs,cvlen,Ppout,Poutlen,Perrch)==0);//rc word count conved//~v59sI~
        if (!rc)	                                               //~v59qI~
          if (Shexoutoffs==X2C_OUTINPLACE)     //repl in place     //~v60aR~
          {                                                        //~v60aI~
        	if (reslen)                                            //~v59qI~
            {                                                      //~v59qI~
            	memcpy(Ppout+*Poutlen,Pdata+Poffs+cvlen,(UINT)reslen);//~v59qI~
                *Poutlen=*Poutlen+reslen;                          //~v59qR~
            }                                                      //~v59qI~
          }//not outpos:max                                        //~v60aI~
        return rc;                                                 //~v59qI~
    }                                                              //~v59qI~
    binlen=ugethexdump(UGHD_SPACESKIP,Pdata+Poffs,Ppout,cvlen,&chklen);//~v51NI~
    if (binlen<=0)                                                 //~v51NR~
    	return 4;		//odd number hex digit                     //~v51NI~
    if (chklen!=cvlen)                                             //~v51NI~
    	return 4;		//non hex digit exist                      //~v51NI~
    if (Popt&EBC2ASC_A2E)                                          //~v59sI~
      if (!(Sebcopt & EBC2ASC_DBCS)) //no DBCS consideration       //~v78RI~
//  	ucvebc2asc(Sebcopt,Ppout,0,Ppout,binlen,Perrch,&binlen);	//evc->asc conv//~v59sR~//~va7FR~
//  	ucvebc2asc_handle(Sebcopt,Sebchandle,Ppout,0,Ppout,binlen,Perrch,&binlen);	//evc->asc conv//~va7FI~//~vb2ER~
    	ucvebc2asc_handle((int)Sebcopt,Sebchandle,Ppout,0,Ppout,binlen,Perrch,&binlen);	//evc->asc conv//~vb2EI~
    *Poutlen=binlen;                                               //~v51NI~
    return 0;                                                      //~v51NI~
}//fcmdhexconv                                                     //~v51NI~
//************************************************************     //~v54NI~
// fcmdmulthexconv                                                 //~v54NI~
//*hex dump data conv to binary with any delm and multiple word    //~v54NI~
//*parm1:data                                                      //~v54NI~
//*parm2:data len                                                  //~v54NI~
//*parm4:conv len                                                  //~v54NI~
//*parm5:out area                                                  //~v54NI~
//*return:conved word count                                        //~v54NI~
//************************************************************     //~v54NI~
//int fcmdmulthexconv(UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen)//~v54QR~
//int fcmdmulthexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen)//~v59sR~
int fcmdmulthexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen,int Perrch)//~v59sI~
{                                                                  //~v54NI~
	char *pc,*pce,*pco;                                            //~v54QR~
    int binlen,reslen,chklen,wordno=0,ch,delmsw=1,prevdelmsw;      //~v54QR~
    int inplacesw;                                                 //~v54QR~
//*****************************                                    //~v54NI~
    inplacesw=Sotheropt&OOPT_OUTINPLACE;                           //~v54QR~
	for (pc=Pdata,pce=Pdata+Plen,pco=Ppout;pc<pce;)                //~v54NI~
    {                                                              //~v54NI~
    	prevdelmsw=delmsw;                                         //~v54QI~
        ch=*pc;                                                    //~v54QI~
        if (!isxdigit(ch))                                         //~v54QR~
        {	                                                       //~v54NI~
            if (inplacesw)                                         //~v54QI~
                *pco++=(char)ch;                                   //~v54QR~
        	pc++;    	//skip input                               //~v54NI~
     		delmsw=(ch<'0'||(ch>'9'&&ch<'@')||(ch>'Z'&&ch<'a')||(ch>'z'&&ch<0x80));//delm//~v54QI~
            continue;                                              //~v54NI~
        }                                                          //~v54NI~
//    	reslen=(int)((ULONG)pce-(ULONG)pc);                        //~v55KR~//~vafkR~
    	reslen=(int)((ULPTR)pce-(ULPTR)pc);                        //~vafkI~
    	binlen=ugethexdump(0,pc,pco,reslen,&chklen);//-binlen:odd numer hex digit//~v54NI~
	    if (Popt&EBC2ASC_A2E)                                      //~v59sI~
          if (!(Sebcopt & EBC2ASC_DBCS)) //no DBCS consideration   //~v78RI~
//  		ucvebc2asc(Sebcopt,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~v59sR~//~va7FR~
//  		ucvebc2asc_handle(Sebcopt,Sebchandle,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~va7FI~//~vb2ER~
    		ucvebc2asc_handle((int)Sebcopt,Sebchandle,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~vb2EI~
        if (reslen==chklen)	//reached to eol                       //~v54QI~
        	delmsw=2;                                              //~v54QI~
        else                                                       //~v54QI~
        {                                                          //~v54QI~
	        ch=*(pc+chklen);                                       //~v54QI~
     		delmsw=(ch<'0'||(ch>'9'&&ch<'@')||(ch>'Z'&&ch<'a')||(ch>'z'&&ch<0x80));//delm//~v54QI~
        }                                                          //~v54QI~
        if (binlen>0 && delmsw && prevdelmsw)	//hex string word  //~v54QI~
        {                                                          //~v54QI~
            pco+=binlen;                                           //~v54QI~
            wordno++;                                              //~v54QI~
        }                                                          //~v54QI~
        else                                                       //~v54QI~
        {                                                          //~v54QI~
            if (inplacesw)                                         //~v54QI~
            {                                                      //~v54QI~
            	memcpy(pco,pc,(UINT)chklen);                       //~v54QI~
                pco+=chklen;                                       //~v54QI~
            }                                                      //~v54QI~
            else                                                   //~v54QI~
	            *pco++=' '; //seperator                            //~v54QI~
        }                                                          //~v54QI~
	    reslen-=chklen;                                            //~v54QI~
    	pc+=chklen;                                                //~v54QI~
    }//loop                                                        //~v54NI~
//  *Poutlen=(int)((ULONG)pco-(ULONG)Ppout);                       //~v55KR~//~vafkR~
    *Poutlen=(int)((ULPTR)pco-(ULPTR)Ppout);                       //~vafkI~
    return wordno;                                                 //~v54NI~
}//fcmdmulthexconv                                                 //~v54NI~
//************************************************************     //~v55KI~
// fcmdxnotehexconv                                                //~v55KI~
//*hex dump data conv to binary with hex notation parm             //~v55KI~
//*parm1:data                                                      //~v55KI~
//*parm2:data len                                                  //~v55KI~
//*parm4:conv len                                                  //~v55KI~
//*parm5:out area                                                  //~v55KI~
//*return:conved word count                                        //~v55KI~
//************************************************************     //~v55KI~
//int fcmdxnotehexconv(PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen)//~v59sR~
int fcmdxnotehexconv(int Popt,PULINEH Pplh,UCHAR *Pdata,int Plen,UCHAR *Ppout,int *Poutlen,int Perrch)//~v59sI~
{                                                                  //~v55KI~
	char *pc,*pc2,*pc3,*pce,*pco;                                  //~v55KR~
    int binlen,reslen,chklen,wordno=0,inplacesw,prelen,postlen,hexlen,len;//~v55KR~
//*****************************                                    //~v55KI~
    inplacesw=Sotheropt&OOPT_OUTINPLACE;                           //~v55KI~
    prelen=(int)strlen(Shexnotationpre);                           //~v55KI~
    if (*Shexnotationpost)                                         //~v55KR~
	    postlen=(int)strlen(Shexnotationpost);                     //~v55KI~
    else                                                           //~v55KI~
	    postlen=0;                                                 //~v55KI~
	for (pc=Pdata,pce=Pdata+Plen,pco=Ppout;pc<pce;)                //~v55KI~
    {                                                              //~v55KI~
//    	reslen=(int)((ULONG)pce-(ULONG)pc);                        //~v55KR~//~vafkR~
    	reslen=(int)((ULPTR)pce-(ULPTR)pc);                        //~vafkI~
    	pc2=umemmem(pc,Shexnotationpre,(UINT)reslen,(UINT)prelen); //~v55KR~
        if (pc2)                                                   //~v55KI~
//        	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v55KI~//~vafkR~
        	len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~vafkI~
        else                                                       //~v55KI~
        	len=reslen;                                            //~v55KI~
        if (len)                                                   //~v55KI~
        {                                                          //~v55KI~
            if (inplacesw)                                         //~v55KI~
            {                                                      //~v55KI~
            	memcpy(pco,pc,(UINT)len);                          //~v55KI~
                pco+=len;                                          //~v55KR~
            }                                                      //~v55KI~
        }                                                          //~v55KI~
        reslen-=len;                                               //~v55KI~
        if (!pc2)	//prefix not found                             //~v55KI~
        	break;                                                 //~v55KI~
        pc2+=prelen;                                               //~v55KI~
        reslen-=prelen;                                            //~v55KI~
        if (*Shexnotationpost)	//postfix specified                //~v55KR~
        {                                                          //~v55KI~
        	pc3=umemmem(pc2,Shexnotationpost,(UINT)reslen,(UINT)postlen);//~v55KR~
            if (!pc3)	//postfix not found                        //~v55KI~
            {                                                      //~v55KI~
                if (inplacesw)                                     //~v55KI~
                {                                                  //~v55KI~
                    memcpy(pco,pc2,(UINT)reslen);                  //~v55KI~
                    pco+=reslen;                                   //~v55KI~
                }                                                  //~v55KI~
                break;                                             //~v55KI~
            }                                                      //~v55KI~
//          hexlen=(int)((ULONG)pc3-(ULONG)pc2);                   //~v55KI~//~vafkR~
            hexlen=(int)((ULPTR)pc3-(ULPTR)pc2);                   //~vafkI~
        }                                                          //~v55KI~
        else                                                       //~v55KI~
        	hexlen=reslen;                                         //~v55KI~
    	binlen=ugethexdump(0,pc2,pco,hexlen,&chklen);//-binlen:odd numer hex digit//~v55KI~
	    if (Popt&EBC2ASC_A2E)                                      //~v59sI~
          if (!(Sebcopt & EBC2ASC_DBCS)) //no DBCS consideration   //~v78RI~
//  		ucvebc2asc(Sebcopt,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~v59sR~//~va7FR~
//  		ucvebc2asc_handle(Sebcopt,Sebchandle,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~va7FI~//~vb2ER~
    		ucvebc2asc_handle((int)Sebcopt,Sebchandle,pco,0,pco,binlen,Perrch,&binlen);	//evc->asc conv//~vb2EI~
        pco+=binlen;                                               //~v55KI~
        pc2+=chklen;	//input pos                                //~v55KI~
        if (*Shexnotationpost)	//postfix specified                //~v55KR~
        	if (chklen==hexlen)                                    //~v55KI~
            	pc2+=postlen;	                                   //~v55KR~
        if (chklen)                                                //~v55KI~
	        wordno++;                                              //~v55KI~
    	pc=pc2;                                                    //~v55KR~
    }//loop                                                        //~v55KI~
//  *Poutlen=(int)((ULONG)pco-(ULONG)Ppout);                       //~v55KR~//~vafkR~
    *Poutlen=(int)((ULPTR)pco-(ULPTR)Ppout);                       //~vafkI~
    return wordno;                                                 //~v55KI~
}//fcmdxnotehexconv                                                //~v55KI~
//************************************************************     //~v51JI~
// fcmdkandl                                                       //~v51JI~
//*hankaku katakana<-->lower case letter                           //~v51JI~
//*parm1:pcw                                                       //~v51JI~
//*parm2:pfh                                                       //~v51JI~
//*return:rc                                                       //~v51JI~
//************************************************************     //~v51JI~
int fcmdkandl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,LONG *Pplineno)//~v51JI~
{                                                                  //~v51JI~
	PULINEH plh;                                                   //~v51JI~
    long convlineno=0;                                             //~v51JI~
    int rc,len,opt;                                                //~v51JI~
    UCHAR *pdata;                                                  //~v51JR~
//*****************************                                    //~v51JI~
//  opt=Popt&EBC2ASC_CRLF;                                         //~v51JI~//~vaadR~
    opt=Popt&KANDL_K2L; //=EBC2ASC_CRLF=0x01                       //~vaadI~
    UPCTRREQ(Ppfh);         //write at save                        //~v51JI~
    for (plh=Splhs                      ;plh;plh=UGETQNEXT(plh))   //~v51JI~
	{                                                              //~v51JI~
        if (plh==Splhe)     //reached to label range               //~v51JI~
            break;                                                 //~v51JI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v51JI~
        	continue;                                              //~v51JI~
        if (Sotheropt & OOPT_NX)	//skip excluded line           //~v51QI~
        	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //excluded  //~v51QI~
		        continue;                                          //~v51QI~
        pdata=plh->ULHdata;                                        //~v51JI~
        len=  plh->ULHlen;                                         //~v51JI~
    	if (ucvkandl(opt,pdata,0,len)!=KANDL_RC_WILLCONV)	//no conversion may occur//~v51JR~
        	continue;                                              //~v51JI~
  		if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v51JI~
        	return rc;                                             //~v51JI~
    	ucvkandl(opt,pdata,pdata,len);                             //~v51JI~
        convlineno++;                                              //~v51JI~
	}//all line                                                    //~v51JI~
    UPCTRREQ(Ppfh);         //write at save                        //~v51JI~
    *Pplineno=convlineno;                                          //~v51JI~
    return 0;                                                      //~v51JI~
}//fcmdkandl                                                       //~v51JI~
//************************************************************     //~v50iI~
// fcmducsconv                                                     //~v50iI~
//*ucs conversion                                                  //~v50iR~
//*parm1:pcw                                                       //~v50iI~
//*parm2:pfh                                                       //~v50iI~
//*parm3:conv type                                                 //~v50iI~
//*parm4:little endian,err rep char                                //~v50iR~
//*return:rc                                                       //~v50iI~
//************************************************************     //~v50iI~
int fcmducsconv(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pconvtype,ULONG Pucsopt)//~v50pR~
{                                                                  //~v50iI~
    static int Sinitsw=0;                                          //~v50iI~
	PUFILEC pfc;                                                   //~v50iR~
    int buffsz=GFILEBUFFSZ,buff2sz;                                //~v50iR~
    UCHAR *pbuff,*pbuff2;                                          //~v50iI~
    int maxlen,maxcontlen,rc,rct=0;                                //~v50iR~
    int rc2;                                                       //~vad1I~
    PULINEH plhs;                                                  //~v78UI~
#ifdef WCSUPP                                                      //~v79wI~
    int errch;                                                     //~v79wM~
#ifdef UTF8SUPPH                                                   //~va1kI~
//  ULONG pconverters[7];                                          //~va1kI~//~vafkR~
    ULPTR pconverters[7];                                          //~vafkI~
#else                                                              //~va1kI~
    ULONG pconverters[3];                                          //~v79sI~
#endif                                                             //~va1kI~
    UCHAR dbcsflag[256];                                           //~v79sI~
    int opt=0;                                                     //~v79wI~
#endif                                                             //~v79wI~
#ifdef LNX                                                         //~v79sI~
  #ifdef UTF8SUPPH                                                 //~va1kI~
  #else                                                            //~va1kI~
	ULONG pconvcpto[2],pconvcpfrom[2];	//0:TOUCS,1:FROMUCS        //~v79sI~
  #endif                                                           //~va1kI~
#endif                                                             //~v79sI~
//****************************                                     //~v50iI~
    if (!Sinitsw)                                                  //~v50iI~
    {                                                              //~v50iI~
    	Sinitsw=1;                                                 //~v50iI~
		if (ucp932init(0,0))	//alloc cp932tbl                   //~v50iI~
        	return 8;                                              //~v50iI~
    }                                                              //~v50iI~
	pfc=Ppcw->UCWpfc;                                              //~v50iI~
    Sconvtype=Pconvtype;                                           //~v50iI~
    Sucsopt=(int)Pucsopt;                                          //~v55KR~
	Serrctr=0;                                                     //~v50iI~
	Serrstopsw=0;                                                  //~v50iI~
	Splhcsr=0;                                                     //~v50iR~
    if (rc=fsubgetmaxlen(0,Ppfh,&maxlen,&maxcontlen),rc)           //~v50iI~
    	return rc;                                                 //~v50iI~
    if (maxlen>buffsz)                                             //~v50iI~
    {                                                              //~v50iI~
    	uerrmsg("Too long record,reload and retry",                //~v50iI~
				"行が長すぎる、再ロードして再試行してください。"); //~v50iI~
        return 4;                                                  //~v50iI~
    }                                                              //~v50iI~
  if (Pconvtype!=UCSCONV_A2A)                                      //~v79sI~
  	if (!(Pconvtype==UCSCONV_F2S||Pconvtype==UCSCONV_S2F))	//between UCS2//~v50iI~
  	  if (!(Pucsopt & UCVUCS_ESCUCS))	//not \ucxxxx text input   //~v54MR~
        if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                    //~v50iR~
    	{                                                          //~v50iI~
//      	uerrmsg("Open file by binary mode for conv between UCS",//~v683R~
//          	    "UCSと変換する時はバイナリーモードで開いてください。");//~v683R~
        	uerrmsg("Use \"\\u\" option or open file by binary mode for conv between UCS",//~v683I~
            	    "UCSと変換する時は\"\\u\"オプションを指定するかバイナリーモードで開いてください。");//~v683I~
        	return 4;                                              //~v50iI~
    	}                                                          //~v50iI~
//  buff2sz=buffsz*4;                                              //~va1cR~
    buff2sz=buffsz*MAX_MBCSLEN;                                    //~va1cR~
    Sibuff=pbuff=umalloc((UINT)(buffsz+buff2sz));                  //~v50iR~
    UALLOCCHK(pbuff,UALLOC_FAILED);                                //~v50iI~
    pbuff2=pbuff+buffsz;                                           //~v50iR~
//  Splh=UGETQTOP(&Ppfh->UFHlineque);  //start plh                 //~v51GR~
    plhs=UGETQPREV(Splhs);                                         //~v78UI~
  if (plhs)                                                        //~v78UI~
    Splh=plhs;                                                     //~v78UI~
  else                                                             //~v78UI~
    Splh=Splhs;                        //start plh                 //~v51GI~
    Spfh=Ppfh;                                                     //~v50iI~
    Spcw=Ppcw;                                                     //~v50iI~
    UPCTRREQ(Ppfh);         //write at save                        //~v50iI~
	switch(Pconvtype)                                              //~v50iI~
    {                                                              //~v50iI~
    case UCSCONV_F2U:                                              //~v50iI~
		rc=ucvfutf2ucs(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_U2F:                                              //~v50iI~
		rc=ucvfucs2utf(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_S2U:                                              //~v50iI~
		rc=ucvfsjis2ucs(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_U2S:                                              //~v50iI~
		rc=ucvfucs2sjis(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_S2F:                                              //~v50iI~
		rc=ucvfsjis2utf(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_F2S:                                              //~v50iI~
		rc=ucvfutf2sjis(fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,Pucsopt,pbuff,buffsz,pbuff2,buff2sz);//~v50iR~
        break;                                                     //~v50iI~
    case UCSCONV_A2A:                                              //~v79sI~
#ifdef WCSUPP                                                      //~v79wI~
#ifdef UTF8SUPPH                                                   //~va1kR~
//      if (ucvext_iconva2ainit(0,Scpfrom,Scpto,dbcsflag,&opt,pconverters))//~va1kI~//~vad1R~
		if (Sotheropt & OOPT_MBICU)                                //~vad1I~
        	rc2=ucvext_iconva2ainit(UCVEXTO_MBICU,Scpfrom,Scpto,dbcsflag,&opt,pconverters);//~vad1R~
        else                                                       //~vad1I~
        	rc2=ucvext_iconva2ainit(0,Scpfrom,Scpto,dbcsflag,&opt,pconverters);//~vad1R~
        if (rc2)                                                   //~vad1I~
#else                                                              //~va1kI~
#ifdef LNX                                                         //~v79sI~
		pconverters[HICONV_CPTO]=(ULONG)pconvcpto;	//parm to iconv getconverter//~v79sI~
		pconverters[HICONV_CPFROM]=(ULONG)pconvcpfrom;	//parm to iconv getconverter//~v79sI~
  		if (ucvext_iconvgetconvertertype(0,(ULONG)Scpfrom,0)==UCEIRC_UTF8)//~v79wR~
//      	opt|=EBC2ASC_FROMUTF8;                                 //~v79zR~
        	opt|=UCVEXTO_FROMUTF8;                                 //~v79zI~
#endif                                                             //~v79sI~
		pconverters[HICONV_DBCSSTARTER]=(ULONG)dbcsflag;	//parm to iconv getconverter//~v79sI~
		if (ucvext_iconvgetparmconverter(0,Scpfrom,Scpto,pconverters)>1)//~v79sI~
#endif                                                             //~va1kM~
        {                                                          //~v79sI~
    		ufree(pbuff);                                          //~v79sI~
    		return 8;                                              //~v79sI~
        }                                                          //~v79sI~
//  	errch=Pucsopt; //dbcs+sbcs err                             //~v79sR~//~vb2DR~
    	errch=(int)Pucsopt; //dbcs+sbcs err                        //~vb2DI~
		rc=ucvext_iconva2acont(pconverters,fcmdcvgetdata,fcmdcvsavedata,fcmdcvfuncerr,//~v79sI~
//  		 0/*opt*/,pbuff,buffsz,pbuff2,buff2sz,errch);          //~v79wR~
//  		 opt,pbuff,buffsz,pbuff2,buff2sz,errch);               //~v79wI~//~vb2DR~
    		 (ULONG)opt,pbuff,buffsz,pbuff2,buff2sz,errch);        //~vb2DI~
#endif	//WCSUPP                                                   //~v79wI~
        break;                                                     //~v79sI~
    default:                                                       //~v79sI~
        return 8;//internal logic err                              //~v79sI~
    }                                                              //~v50iI~
//  rct=fcmdcpymfwt2(Ppfh,Smfwtindex);                             //~v62bR~
    UPCTRREQ(Ppfh);         //write at save                        //~v50iI~
    ufree(pbuff);                                                  //~v50iI~
  	if (Splhcsr)                                                   //~v50iR~
    {                                                              //~v50iI~
        if (Serrctr)                                               //~v50iI~
        {                                                          //~v50iI~
			fcmdscrollpagemid(Ppcw,Splhcsr);                       //~v50iR~
	    	filesetcsr(Ppcw,Splhcsr,1,Serroffs-pfc->UFCleft);	//on cmd line//~v50iI~
        	rct=4;                                                 //~v50iM~
        }                                                          //~v50iI~
        else                                                       //~v50iI~
    		filesetcsr(Ppcw,Splhcsr,0,0);	//on cmd line          //~v50iR~
    }                                                              //~v50iI~
//  if (Splh)	//not reached to eof                               //~v51GR~
    if (Splh && Splh!=Splhe)	//not reached to eof               //~v51GI~
    	rct=4;                                                     //~v50iI~
    else 	//reached to eof                                       //~v50iI~
//      if (Smfwtovf)                                              //~v50vR~
// //   	uerrmsg("%d err detected,from %d'th diplayed 1 word per line",//~v50vR~
// //   			"%d 個のエラー検知,但し %d 以降の反転は一行一個のみ。",//~v50vR~
// //   	    		Serrctr,Smfwtovf);                         //~v50vR~
        if (Serrctr && Smfwtovf)                                   //~v50vI~
//      	uerrmsg("%d err detected; from line %ld-%d (offs=x%lX), diplayed 1 word per line",//~vaz0R~
//  				"%d 個のエラー検知,但し %ld-%d 行(offs=x%lX) 以降の反転は一行一個のみ。",//~vaz0R~
//      	    		Serrctr,Smfwtovf->ULHlinenor,Smfwtovf->ULHsuffix,Smfwtovf->ULHoffs);//~vaz0R~
        	uerrmsg("%d err detected; from line %ld-%d (offs=%s), diplayed 1 word per line",//~vaz0I~
    				"%d 個のエラー検知,但し %ld-%d 行(offs=%s) 以降の反転は一行一個のみ。",//~vaz0I~
        	    		Serrctr,Smfwtovf->ULHlinenor,Smfwtovf->ULHsuffix,ueditFILESZ(0/*opt*/,0/*outbuff*/,0/*buffsz*/,"x%$X",Smfwtovf->ULHoffs));//~vaz0R~
        else                                                       //~v50iI~
	    	uerrmsg("%d err detected",                             //~v50iR~
    				"%d 個のエラー検知",                           //~v50iR~
        	    		Serrctr);                                  //~v50iR~
    if (rct)                                                       //~v50iI~
    	ubell();                                                   //~v50iI~
    return 0;                                                      //~v50iR~
}//fcmducsconv                                                     //~v50iR~
//**************************************************************** //~v50iI~
// fcmdcvgetdata                                                   //~v50iI~
//* input data read interface callback func between ucvfxxxx       //~v50iI~
//*parm1:read buff                                                 //~v50iI~
//*parm2:read buff sz                                              //~v50iR~
//*parm3:output read len                                           //~v50iI~
//*retrn:rc 0:ok(line split), 1(line end), -1:eof                  //~v50iR~
//**************************************************************** //~v50iI~
int fcmdcvgetdata(UCHAR *Pbuff,int Preqlen,int *Ppreadlen)         //~v50iR~
{                                                                  //~v50iI~
    int rc=0,len,convlen;                                          //~v50iR~
//**************************                                       //~v50iI~
	if (Serrstopsw)                                                //~v50iI~
    	return 16;	//stop conv                                    //~v50iI~
    for (;;)                                                       //~v50iI~
    {                                                              //~v50iI~
    	Splh=UGETQNEXT(Splh);                                      //~v50iI~
		if (!Splh)                                                 //~v50iR~
        	return -1;                                             //~v50iI~
		if (Splh==Splhe)	//next of labae range                  //~v51GI~
        	return -1;                                             //~v51GI~
		if (Splh->ULHtype==ULHTDATA)	//file data                //~v50iR~
        	break;                                                 //~v50iI~
    }                                                              //~v50iI~
    len=Splh->ULHlen;                                              //~v50iI~
    rc=filetabrestore(Spfh,Splh,Pbuff,Preqlen,&convlen);//tab reduce//~v50iR~
    if (rc==FTRRC_BUFFOVERFLOW)                                    //~v50iR~
    {                                                              //~v50iI~
        uerrmsg("Buffer overflow to tabrestore",0);                //~v50iI~
        return rc;                                                 //~v50iI~
    }                                                              //~v50iI~
    if (rc!=FTRRC_TABDETECTED)	//tab not restored to convwk       //~v50iI~
    {                                                              //~v50iI~
    	memcpy(Pbuff,Splh->ULHdata,(UINT)len);//concatinate to cont data//~v50iR~
        convlen=len;                                               //~v50iI~
    }                                                              //~v50iI~
    *Ppreadlen=convlen;                                            //~v50iI~
//  Sidatalen=(int)((ULONG)Pbuff-(ULONG)Sibuff)+convlen;           //~v50iR~//~vafkR~
    Sidatalen=(int)((ULPTR)Pbuff-(ULPTR)Sibuff)+convlen;           //~vafkI~
//  if (UGETQNEXT(Splh)==UGETQEND(&Spfh->UFHlineque))    //last line//~v51GR~
    if (UGETQNEXT(Splh)==Splhe)    //last line                     //~v51GI~
        rc=1;         //line end                                   //~v50iI~
    else                                                           //~v50iI~
        if (UCBITCHK(Spfh->UFHflag4,UFHF4BIN))  //bin file         //~v50iR~
            rc=0;       //always cont'ed to next lien              //~v50iR~
        else                                                       //~v50iR~
            if (!UCBITCHK(Splh->ULHflag2,ULHF2SPLIT1))             //~v50iR~
                rc=1;    //line end                                //~v50iR~
            else                                                   //~v50iR~
                rc=0;    //line cont                               //~v50iR~
    return rc;                                                     //~v50iR~
}//fcmdcvgetdata                                                   //~v50iR~
//**************************************************************** //~v50iI~
// xcvfuncwrite                                                    //~v50iI~
//* output data write interface callback func between ucvfxxxx     //~v50iI~
//*parm1:write buff                                                //~v50iI~
//*parm2:write req len                                             //~v50iI~
//*retrn:rc                                                        //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvsavedata(UCHAR *Pbuff,int Preqlen)                       //~v50iR~
{                                                                  //~v50iI~
    int len,undosw=0,errlinesw;                                    //~v50iR~
	UCHAR *pdata,*pdbcs;                                           //~v50iR~
    int rc;                                                        //~v62bI~
    PUFILEH pfh;                                                   //~v8@2R~
    int tabskip;                                                   //~v8@2R~
//********************                                             //~v50iI~
	pfh=UGETPFH(Splh);                                             //~v8@2R~
    tabskip=pfh->UFHtabskip;                                       //~v8@2R~
	if (Preqlen>Splh->ULHbufflen)                                  //~v50iR~
        if (fileexpandbuff(Splh,Preqlen)==UALLOC_FAILED)        //expand buff//~v50iR~
            return 4;                                              //~v50iI~
//  if (Sconvtype==UCSCONV_S2F||Sconvtype==UCSCONV_F2S)            //~v54MR~
    if (Sconvtype==UCSCONV_S2F||Sconvtype==UCSCONV_F2S             //~v54MI~
//  || (Sconvtype==UCSCONV_U2S && (Sucsopt & UCVUCS_ESCUCS)))      //~v683R~
    || (Sucsopt & UCVUCS_ESCUCS))                                  //~v683I~
    {                                                              //~v50iI~
    	if (Sidatalen!=Preqlen      //len chnged                   //~v50iR~
        ||  memcmp(Sibuff,Pbuff,(UINT)Preqlen)) //data(tab compressed fmt) not same//~v50iR~
        	undosw=1;                                              //~v50iI~
    }                                                              //~v50iI~
    else                                                           //~v50iI~
        undosw=1;   //always undo                                  //~v50iI~
    if (undosw)                                                    //~v50iI~
        if (fcmdcvundo(Spcw,Spfh,Splh)) //to protect clear lineerr & curfound by undo call//~v50iI~
        {                                                          //~v50iI~
            Serrstopsw=1;                                          //~v50iI~
            return 16;                                             //~v50iI~
        }                                                          //~v50iI~
    pdata=Splh->ULHdata; //addr change if expanded                 //~v50iR~
    pdbcs=Splh->ULHdbcs;                                           //~v50iR~
    memcpy(pdata,Pbuff,(UINT)Preqlen);                             //~v50iI~
    Splh->ULHlen=Preqlen;   //len update undo not avail            //~v50iR~
	errlinesw=(UCBITCHK(Splh->ULHflag,ULHFCURFOUND)	//conv err line//~v50iI~
			   &&  Splh->ULHrevctr==Spfh->UFHfindctr);             //~v50iI~
	if (!Spfh->UFHmfwtbl)                                          //~v62bR~
		if (rc=fcmdallocmfwt(Spfh),rc)                             //~v62bR~
        	return rc;                                             //~v62bI~
    if (errlinesw)                                                 //~v50iI~
	    fcmdcvajusttab();                                          //~v50iR~
    if (Splh==Splhcsr)                                             //~v50iI~
        if (Serroffs)                                              //~v50iI~
//          Serroffs=filetgettabexplensub(0,pdata,Serroffs);       //~v8@2R~
            Serroffs=filetgettabexplensub(0,pdata,Serroffs,tabskip);//~v8@2R~
    len=Preqlen;                                                   //~v50iI~
    if (pdbcs)                                                     //~v50iR~
    {                                                              //~v50iI~
        filesetdbcstbl(pdata,pdbcs,Preqlen,0);                     //~v50iI~
        if (filetabexp(0,Splh,0,&len)==UALLOC_FAILED)   //initial expand,Gfilebuff used//~v50iR~
        {                                                          //~v50iI~
            Serrstopsw=1;                                          //~v50iI~
            return UALLOC_FAILED;                                  //~v50iI~
        }                                                          //~v50iI~
    }                                                              //~v50iI~
    else	//not yet expanded                                     //~v50iI~
        if (errlinesw)                                             //~v50iI~
			if (filechktabdbcs(Splh)==UALLOC_FAILED)//expand to chk find pos is dbcs//~v50iR~
	        {                                                      //~v50iI~
    	        Serrstopsw=1;                                      //~v50iI~
        	    return UALLOC_FAILED;                              //~v50iI~
	        }                                                      //~v50iI~
    if (errlinesw)                                                 //~v50iI~
//  	fcmdcvajusttabsub2(Spfh,Splh,Gfilemfwtbl);                 //~v62bR~
    	fcmdcvajusttabsub2(Spfh,Splh,Spfh->UFHmfwtbl);             //~v62bR~
	return 0;                                                      //~v50iR~
}//fcmdcvsavedata                                                  //~v50iR~
//**************************************************************** //~v50iI~
// fcmdcvfuncerr                                                   //~v50iI~
//* callback weh err detected                                      //~v50iI~
//*parm1:rc                                                        //~v50iI~
//*parm2:offset err detected or chked len when normal              //~v50iI~
//*retrn:                                                          //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvfuncerr(int Prc,int Poffs,int Poutoffs,UCHAR *Pbuff,int Perrlen)//~v50pR~
{                                                                  //~v50iI~
    int rc=0,olderrctr;                                            //~v50iR~
//**************************                                       //~v50iI~
	olderrctr=Serrctr;                                             //~v50iI~
    switch(Prc)                                                    //~v50iI~
    {                                                              //~v50iI~
    case 0:            //normal processed                          //~v50iI~
        break;                                                     //~v50iI~
    case UCVUCS_LENERR://                                          //~v50iI~
        break;                                                     //~v50iI~
    case UCVUCS_FMTERR:     //utf,ucs fmt                          //~v50iI~
    case UCVUCS_CONVERR:    //sjis->ucs conv err                   //~v50iI~
		if (fcmdcvundo(Spcw,Spfh,Splh))	//to protect clear lineerr & curfound by undo call//~v50iI~
        {                                                          //~v50iI~
            Serrstopsw=1;                                          //~v50iI~
            return 16;                                             //~v50iI~
        }                                                          //~v50iI~
		filesetlineerr(Splh);                                      //~v50iM~
        rc=                                                        //~v62bI~
		fcmdsetfound(Spfh,Splh,Serrctr==0,Poutoffs,1);             //~v50pR~
        if (rc)                                                    //~v62bI~
        	return rc;                                             //~v62bI~
    	Serrctr++;                                                 //~v50iI~
        break;                                                     //~v50iI~
    case UCVUCS_BUFFOVF:                                           //~v50iI~
        uerrmsg("buffer overflow at line %ld-%d",                  //~v50iR~
        		"行 %ld-%d でバッファ溢れ",                        //~v50iR~
                Splh->ULHlinenor,Splh->ULHsuffix);                 //~v50iR~
        break;                                                     //~v50iI~
    }                                                              //~v50iI~
    if (!Splhcsr||(Serrctr==1 && !olderrctr))	//1st update if no err//~v50iR~
    {                                                              //~v50iI~
    	Serroffs=Poutoffs;                                         //~v50iR~
    	Splhcsr=Splh;                                              //~v50iR~
    }                                                              //~v50iI~
    return rc;                                                     //~v50iI~
}//fcmdcvfuncerr                                                   //~v50iI~
//**************************************************************** //~v50iI~
//!fcmdsetfindhighlight                                            //~v50iI~
//! set highlight on found word                                    //~v50iI~
//* parm1 :pfh                                                     //~v50iI~
//* parm2 :plh                                                     //~v50iI~
//* parm3 :1st call sw                                             //~v50iI~
//* parm4 :word offset                                             //~v50iI~
//* parm5 :word len                                                //~v50iI~
//* rc    :0,UALLOC_FAILED                                         //~v62bR~
//**************************************************************** //~v50iI~
int fcmdsetfound(PUFILEH Ppfh,PULINEH Pplh,int Plocatesw,int Poffset,int Pwordlen)//~v50iI~
{                                                                  //~v50iI~
	int idx1st;                                                    //~v50vR~
    int ii;                                                        //~v61sI~
	USHORT *pusoffs;                                               //~v61sI~
	USHORT *filemfwtbl;                                            //~v62bI~
    int rc,mfwtindex;                                              //~v62bR~
//*****************                                                //~v50iI~
	if (!Ppfh->UFHmfwtbl)                                          //~v62bR~
		if (rc=fcmdallocmfwt(Ppfh),rc)                             //~v62bI~
        	return rc;                                             //~v62bI~
	filemfwtbl=Ppfh->UFHmfwtbl;                                    //~v62bI~
    mfwtindex=Ppfh->UFHmfwtindex;	//mfwt current USHORT position //~v62bR~
	if (Plocatesw)                                                 //~v50iI~
    {                                                              //~v50iI~
    	++Ppfh->UFHfindctr;				//new level                //~v50iI~
		Smfwtovf=0;						//overflow point           //~v50iI~
//  	Smfwtindex=0;					//clear used entry         //~v62bR~
    	mfwtindex=0;					//clear used entry         //~v62bI~
//  	Sfoundctr=0;					//count up at return       //~v50vR~
	}                                                              //~v50iI~
//  Sfoundctr++;                                                   //~v50vR~
    if (Plocatesw || Pplh->ULHrevctr!=Ppfh->UFHfindctr)    //new find//~v50iI~
    {                                                              //~v50iI~
		Pplh->ULHrevoffs=(USHORT)Poffset;                          //~v50iI~
		Pplh->ULHrevlen=(USHORT)Pwordlen;//reverse len,next rfind step//~v50iI~
		UCBITOFF(Pplh->ULHflag2,ULHF2MFOUND);//reset multiple      //~v50iI~
                                                                   //~v50vR~
        Pplh->ULHrevctr=Ppfh->UFHfindctr;//find cmd ctr for disply current;//~v50vR~
        UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v50vR~
        UCBITOFF(Pplh->ULHflag,ULHFCURCAP);//reset hilight reason cap//~v50vR~
	}                                                              //~v50iI~
    else        //second call for "all"                            //~v50iI~
    {                                                              //~v50iI~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))//already multiple//~v50iI~
        {                                                          //~v50iI~
//          if (Smfwtindex<=MAXMFWTENTRY)                          //~v50vR~
//          if (Smfwtindex<=(MAXMFWTENTRY+MAXMFWTENTRY))           //~v61sR~
//          if (Smfwtindex<=MFWTBLSZ)                              //~v62bR~
            if (mfwtindex<MFWTBLSZ)                                //~v62bR~
            {                                                      //~v50iI~
//              for (ii=Pplh->ULHrevlen-1,pusoffs=Gfilemfwtbl+Pplh->ULHrevoffs;//~v62bR~
                for (ii=Pplh->ULHrevlen-1,pusoffs=filemfwtbl+Pplh->ULHrevoffs;//~v62bI~
					ii>0;ii--)  //search last entry addr           //~v61sI~
                    pusoffs+=*(pusoffs+2);	//3rd entry is ushort count to next 3 ushort entry//~v61sI~
//              *(pusoffs+2)=(USHORT)(Smfwtindex-((ULONG)pusoffs-(ULONG)Gfilemfwtbl)/sizeof(USHORT));//~v62bR~
//              *(pusoffs+2)=(USHORT)(mfwtindex-((ULONG)pusoffs-(ULONG)filemfwtbl)/sizeof(USHORT));//~v62bI~//~vafkR~
//              *(pusoffs+2)=(USHORT)(mfwtindex-((ULPTR)pusoffs-(ULPTR)filemfwtbl)/sizeof(USHORT));//~vafkI~//~vb2DR~
                *(pusoffs+2)=(USHORT)(mfwtindex-(PTRDIFF(pusoffs,filemfwtbl))/(int)sizeof(USHORT));//~vb2DI~
                Pplh->ULHrevlen++;   //wordcount                   //~v50iI~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Pwordlen;      //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=0;	//offset to next entry//~v62bR~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
                *(filemfwtbl+mfwtindex++)=(USHORT)Pwordlen;        //~v62bI~
                *(filemfwtbl+mfwtindex++)=0;	//offset to next entry//~v62bI~
            }                                                      //~v50iI~
            else                                                   //~v50iI~
                if (!Smfwtovf)			//first overflow           //~v50iI~
                {                                                  //~v50vR~
//                  Smfwtovf=Sfoundctr;                            //~v50vR~
                    Smfwtovf=Pplh;                                 //~v50vR~
                    idx1st=(int)Pplh->ULHrevoffs;	 //1st word index on tbl//~v50vR~
//  				Pplh->ULHrevoffs=*(Gfilemfwtbl+idx1st++);  //1st word offset restore//~v62bR~
//  				Pplh->ULHrevlen=*(Gfilemfwtbl+idx1st);     //len//~v62bR~
    				Pplh->ULHrevoffs=*(filemfwtbl+idx1st++);  //1st word offset restore//~v62bI~
    				Pplh->ULHrevlen=*(filemfwtbl+idx1st);     //len//~v62bI~
	                UCBITOFF(Pplh->ULHflag2,ULHF2MFOUND); //reset multiple//~v50vR~
				}                                                  //~v50vR~
        }                                                          //~v50iI~
        else    //first multiple                                   //~v50iI~
        {                                                          //~v50iI~
//          if (Smfwtindex<MAXMFWTENTRY)                           //~v50vR~
//          if (Smfwtindex<(MAXMFWTENTRY+MAXMFWTENTRY))            //~v61sR~
//          if (Smfwtindex<MFWTBLSZ)                               //~v62bR~
            if (mfwtindex<MFWTBLSZ)                                //~v62bI~
            {                                                      //~v50iI~
                UCBITON(Pplh->ULHflag2,ULHF2MFOUND);//multiple     //~v50iI~
//              *(Gfilemfwtbl+Smfwtindex)=Pplh->ULHrevoffs;        //~v62bR~
//              Pplh->ULHrevoffs=(USHORT)Smfwtindex++;//strat pos  //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=Pplh->ULHrevlen;//1st word length//~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=MFWTENTSZ;	//next entry is after 3 ushort//~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Pwordlen;      //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=0;	//offset to enxt entry//~v62bR~
                *(filemfwtbl+mfwtindex)=Pplh->ULHrevoffs;          //~v62bI~
                Pplh->ULHrevoffs=(USHORT)mfwtindex++;//strat pos   //~v62bI~
                *(filemfwtbl+mfwtindex++)=Pplh->ULHrevlen;//1st word length//~v62bI~
                *(filemfwtbl+mfwtindex++)=MFWTENTSZ;	//next entry is after 3 ushort//~v62bI~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
                *(filemfwtbl+mfwtindex++)=(USHORT)Pwordlen;        //~v62bI~
                *(filemfwtbl+mfwtindex++)=0;	//offset to enxt entry//~v62bI~
                Pplh->ULHrevlen=2;           //wordcount           //~v50iR~
            }                                                      //~v50iI~
            else                                                   //~v50iI~
                if (!Smfwtovf)			//first overflow           //~v50iI~
//                  Smfwtovf=Sfoundctr;                            //~v50vR~
                    Smfwtovf=Pplh;                                 //~v50vR~
        }                                                          //~v50iI~
    }                                                              //~v50iI~
//    if (!Smfwtovf)  //before overflow                            //~v50vR~
//    {                                                            //~v50vR~
//        Pplh->ULHrevctr=Ppfh->UFHfindctr;// find cmd ctr for disply current;//~v50vR~
//        UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFCURFOUND);// draw word after wordrep//~v50vR~
//        UCBITOFF(Pplh->ULHflag,ULHFCURCAP);// reset hilight reason cap//~v50vR~
//    }                                                            //~v50vR~
    Ppfh->UFHmfwtindex=mfwtindex;	//mfwt current USHORT position //~v62bR~
    return 0;                                                      //~v50iI~
}//fcmdsetfound                                                    //~v50iI~
//**************************************************************** //~v50iI~
// undo prepare                                                    //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvundo(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh)          //~v50iI~
{                                                                  //~v50iI~
	int rc=0;                                                      //~v50iR~
//****************************                                     //~v50iI~
	if (UCBITCHK(Ppfh->UFHflag,UFHFUPCTRREQ)//first time after UPCTRREQ//~v50iI~
	||  Pplh->ULHupctr!=Ppfh->UFHupctr)                            //~v50iR~
    	rc=undoupdate(Ppcw,Pplh,UUHTREP);    //prepare undo and update process//~v50iM~
    return rc;                                                     //~v50iI~
}//fcmdcvundo                                                      //~v50iI~
//**************************************************************** //~v50iI~
// ajust find offset by tab expand                                 //~v50iI~
// return found pos changed count                                  //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvajusttab(void)                                           //~v50iI~
{                                                                  //~v50iI~
//****************************                                     //~v50iI~
	if (UCBITCHK(Spfh->UFHflag4,UFHF4BIN))  //bin file             //~v50iI~
    	return 0;                                                  //~v50iI~
	if (Splh->ULHdbcs && !UCBITCHK(Splh->ULHflag2,ULHF2TABFOUND))	//no tab detected//~v50iR~
    	return 0;                                                  //~v50iI~
//  return fcmdcvajusttabsub(Spfh,Splh,Gfilemfwtbl);               //~v62bR~
    return fcmdcvajusttabsub(Spfh,Splh,Spfh->UFHmfwtbl);           //~v62bI~
}//fcmdcvajusttab                                                  //~v50iI~
//**************************************************************** //~v50iI~
// ajust find offset by tab expand                                 //~v50iI~
// return found pos changed count                                  //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvajusttabsub(PUFILEH Ppfh,PULINEH Pplh,USHORT *Pmfwtbl)   //~v50iR~
{                                                                  //~v50iI~
	int multifindsw,jj,offs,newoffs,upctr=0;                       //~v50iR~
    int tabskip;                                                   //~v8@2R~
	USHORT *pusoffs=NULL;                                               //~v50iI~//~vaf9R~
//****************************                                     //~v50iI~
	tabskip=Ppfh->UFHtabskip;                                      //~v8@2R~
    multifindsw=0;                                                 //~v50iI~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))   //multiple found word//~v50iI~
    {                                                              //~v50iI~
        if (Pmfwtbl)         //find all tbl,umalloc success        //~v50iR~
        {                                                          //~v50iI~
            jj=(int)Pplh->ULHrevlen;        //word count           //~v50iI~
            multifindsw=1;                                         //~v50iI~
            pusoffs=Pmfwtbl+Pplh->ULHrevoffs; //offset tbl start   //~v50iR~
        }                                                          //~v50iI~
        else                                                       //~v50iI~
            jj=0;       //bypass reverse                           //~v50iI~
    }                                                              //~v50iI~
    else                                                           //~v50iI~
    {                                                              //~v50iI~
        jj=1;                           //word count               //~v50iI~
        pusoffs=&Pplh->ULHrevoffs;      //offset tbl start         //~v50iI~
    }                                                              //~v50iI~
//  for (;jj;jj--,pusoffs++)                                       //~v61sR~
    for (;jj;jj--,pusoffs+=*(pusoffs+1)-1)                         //~v61sR~
    {                                                              //~v50iI~
        offs=(int)*pusoffs;                                        //~v50iI~
//  	newoffs=filetgettabexplensub(0,Pplh->ULHdata,offs);        //~v8@2R~
    	newoffs=filetgettabexplensub(0,Pplh->ULHdata,offs,tabskip);//~v8@2R~
        if (newoffs!=offs)                                         //~v50iI~
        {                                                          //~v50iI~
        	upctr++;                                               //~v50iI~
        	*pusoffs=(USHORT)newoffs;                              //~v50iR~
        }                                                          //~v50iI~
        if (multifindsw)                                           //~v50iI~
            pusoffs++;  //skip len;pair of offset,len              //~v50iI~
    }//multiple word                                               //~v50iI~
    return upctr;                                                  //~v50iI~
}//fcmdcvajusttabsub                                               //~v50iI~
//**************************************************************** //~v50iI~
// ajust find word len for the pos is dbcs after tab expand        //~v50iI~
// return found pos changed count                                  //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvajusttabsub2(PUFILEH Ppfh,PULINEH Pplh,USHORT *Pmfwtbl)  //~v50iI~
{                                                                  //~v50iI~
	int multifindsw,jj,offs,upctr=0;                               //~v50iR~
	USHORT *pusoffs=NULL,*puslen=NULL;                                       //~v50iI~//~vaf9R~
    UCHAR  *pdbcs;                                                 //~v50iI~
//****************************                                     //~v50iI~
	pdbcs=Pplh->ULHdbcs;                                           //~v50iI~
    multifindsw=0;                                                 //~v50iI~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))   //multiple found word//~v50iI~
    {                                                              //~v50iI~
        if (Pmfwtbl)         //find all tbl,umalloc success        //~v50iI~
        {                                                          //~v50iI~
            jj=(int)Pplh->ULHrevlen;        //word count           //~v50iI~
            multifindsw=1;                                         //~v50iI~
            pusoffs=Pmfwtbl+Pplh->ULHrevoffs; //offset tbl start   //~v50iI~
        }                                                          //~v50iI~
        else                                                       //~v50iI~
            jj=0;       //bypass reverse                           //~v50iI~
    }                                                              //~v50iI~
    else                                                           //~v50iI~
    {                                                              //~v50iI~
        jj=1;                           //word count               //~v50iI~
        pusoffs=&Pplh->ULHrevoffs;      //offset tbl start         //~v50iI~
        puslen =&Pplh->ULHrevlen;                                  //~v50iR~
    }                                                              //~v50iI~
//  for (;jj;jj--,pusoffs++)                                       //~v61sR~
    for (;jj;jj--,pusoffs+=*(pusoffs+1)-1)                         //~v61sR~
    {                                                              //~v50iI~
		if (multifindsw)                                           //~v50iI~
  			puslen=pusoffs+1;	//pair of offset,len               //~v50iI~
        offs=(int)*pusoffs;                                        //~v50iI~
//  	if (*(pdbcs+offs)==DBCS1STCHAR)                            //~v76JR~
    	if (offs<Pplh->ULHlen && *(pdbcs+offs)==DBCS1STCHAR)       //~v76JI~
        {                                                          //~v50iI~
#ifdef UTF8SUPPH                                                   //~va1cR~
//      	*puslen=XESUB_DBCSSPLITCTR(pdbcs,Pplh->ULHlen,offs);   //~va1cR~//~vag8R~
        	*puslen=(USHORT)XESUB_DBCSSPLITCTR(pdbcs,Pplh->ULHlen,offs);//~vag8I~
#else                                                              //~va1cR~
        	*puslen=2;		//1-->                                 //~v50iI~
#endif                                                             //~va1cR~
        	upctr++;                                               //~v50iI~
        }                                                          //~v50iI~
        if (multifindsw)                                           //~v50iI~
            pusoffs++;  //skip len;pair of offset,len              //~v50iI~
    }//multiple word                                               //~v50iI~
    return upctr;                                                  //~v50iI~
}//fcmdcvajusttabsub                                               //~v50iI~
//**************************************************************** //~v50iI~
// fcmdcvconflict                                                  //~v50iI~
//**************************************************************** //~v50iI~
int fcmdcvconflict(void)                                           //~v50iI~
{                                                                  //~v50iI~
//****************************                                     //~v50iI~
	uerrmsg("Convtyep and other option parm is conflict",          //~v50iI~
    		"変換タイプと他のオプションが矛盾する。");             //~v50iI~
    return 4;                                                      //~v50iI~
}//fcmdcvconflict                                                  //~v50iI~
#endif //not DOSDOS                                                //~v50iI~
////****************************************************************//~v62bR~
////!fcmdcpymfwt2                                                  //~v62bR~
////  copy multiword find tbl to pfh                               //~v62bR~
////* parm1 :pfh                                                   //~v62bR~
////* parm2 :used entry count                                      //~v62bR~
////*rc   :0                                                       //~v62bR~
////****************************************************************//~v62bR~
//int fcmdcpymfwt2(PUFILEH Ppfh,int Pindex)                        //~v62bR~
//{                                                                //~v62bR~
//    if (!Pindex)    //multiple found                             //~v62bR~
//        return 0;                                                //~v62bR~
//    if (Ppfh->UFHmfwtbl)                                         //~v62bR~
//        ufree(Ppfh->UFHmfwtbl);  //free old                      //~v62bR~
//    Ppfh->UFHmfwtbl=UALLOCM((UINT)(Pindex*sizeof(USHORT)));      //~v62bR~
//    UALLOCCHK(Ppfh->UFHmfwtbl,UALLOC_FAILED);                    //~v62bR~
//    memcpy(Ppfh->UFHmfwtbl,Gfilemfwtbl,(UINT)(Pindex*sizeof(USHORT)));//~v62bR~
//    Ppfh->UFHmfwtblentno=Pindex;//USHORT count in UFHmfwtbl for copy back at multi rev req//~v62bR~
//    return 0;                                                    //~v62bR~
//}//fcmdcpymfwt2                                                  //~v62bR~
////****************************************************************//~v62bR~
////!fcmdcpymfwtback                                               //~v62bR~
////  copy back found tbl for multiple reverse                     //~v62bR~
////*ret :entryno                                                  //~v62bR~
////****************************************************************//~v62bR~
//int fcmdcpymfwtback(PUFILEH Ppfh,char *Ptbladdr)                 //~v62bR~
//{                                                                //~v62bR~
//    int entno;                                                   //~v62bR~
//    char *pmfwt;                                                 //~v62bR~
////*********************                                          //~v62bR~
//    pmfwt=(char*)(ULONG)Ppfh->UFHmfwtbl;                         //~v62bR~
//    entno=Ppfh->UFHmfwtblentno;//USHORT count in UFHmfwtbl for copy back at multi rev req//~v62bR~
//    if (!pmfwt||!entno)                                          //~v62bR~
//        return 0;                                                //~v62bR~
//    memcpy(Ptbladdr,pmfwt,(UINT)(entno*sizeof(USHORT)));         //~v62bR~
//    return entno;                                                //~v62bR~
//}//fcmdcpymfwtback                                               //~v62bR~
//**************************************************************** //~v62bI~
//  allocate multiple find word position tbl                       //~v62bI~
//*ret :entryno                                                    //~v62bI~
//**************************************************************** //~v62bI~
int fcmdallocmfwt(PUFILEH Ppfh)                                    //~v62bI~
{                                                                  //~v62bI~
	if (Ppfh->UFHmfwtbl)                                           //~v62bI~
    	return 0;                                                  //~v62bI~
    Ppfh->UFHmfwtbl=(USHORT*)UALLOCM((MFWTBLSZ+MFWTENTSZ+MFWTENTSZ)*sizeof(USHORT)); //3 ushort and +1 allowance//~v62bR~
    UALLOCCHK(Ppfh->UFHmfwtbl,UALLOC_FAILED);                      //~v62bI~
    return 0;                                                      //~v62bI~
}//fcmdallocmfwt                                                   //~v62bI~
