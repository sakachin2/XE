//*CID://+v6BjR~: update#=   66;                                   //+v6BjR~
//******************************************************           //~v600I~
//*utf2.h                                                          //~v600I~
//******************************************************           //~v600I~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //+v6BjI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f9:120423 (Axe)default locale by locale.getDefault().toString()+"."+Charset.defaultCharset(="UTF-8")//~v6f9I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6df:120218 add validateutf8str for Axe(NewStringUTF function cause SIGSEGV when invalid utf8 char contained)//~v6dfI~
//v6c5:120121 (Axe)no mk_wcwidth,completeley depends to wcwwidth(Java getTextWidths)(but allow adjust by parameter file)//~v6c5I~
//v6a0:110520 Android porting(-DARM)                               //~v650I~
//v650:100121 print width=0(combine mdeo)                          //~v650I~
//v647:100115 (WIN)wchar_t is ushort on Windows,consideration for UCS4//~v647I~
//v634:091115 (UTF8:BUG) selevt "UHC"/"GB18030" as default if env is UTF8//~v634I~
//v626:090718 use GB18030>GBK>GB2312 fo zh_CN                      //~v626I~
//v61b:071205 (UTF:LNX)support locale other than EUC               //~v61bI~
//v600:070710 (UTF8)new typdef                                     //~v600I~
//******************************************************           //~v600I~
#define LANG_ZHCN       "zh_CN"		//simplified chines            //~v626I~
#define LANG_KOKR       "ko_KR"		//korean                       //~v634I~
#define LANG_JAJP       "ja_JP"		//japanese                     //~v634I~
#define LANG_JA         "ja"		//japanese                     //~v6f9I~
#define LANG_ZHTW       "zh_TW"		//taiwan                       //~v6f9I~
#define UTC_OPTCOL2POS(opt) \
    		((opt & ~(UTCO_BYOFF))| ((opt & UTCO_BYLEN)?UTCO_BYOFF:0)) //pos option by len parm option//~v600R~
//******************************************************           //~v600I~
int utfbackoffset(int Popt,PUTCHARS Pputc,int Plen);               //~v600I~
//******************************************************           //~v600I~
int utfgetposoffs(int Popt,PUTCHARS Pputchs,int Pposoff,int *Pppos,int *Ppoffs);//~v600R~
//******************************************************           //~v600I~
int utfgetposoffscntlen(int Popt,PUTCHARS Pputchs,int Pposoffs,int Pcntlen,int *Pppos,int *Ppoffs,int *Ppcnt,int *Pplen);//~v600R~
//*******************************************************          //~v600I~
int utfsetchofD(int Popt,                                          //~v600I~
				PUTCHARS Pputc,		//data and chof and lenc       //~v600I~
				int Ppost,           //start column                //~v600I~
				UCHAR *Psrc,            //data source              //~v600R~
				int Pposs,           //skip column                 //~v600R~
				int Plen,            //lenutf or lenc              //~v600I~
				int *Pplenc,         //setup column                //~v600I~
				int *Ppskiplen,      //utflen correspond to Pposs  //~v600I~
				int *Pplenutf);      //chked data lenutf           //~v600R~
//******************************************************           //~v600I~
int utfsetchofmbr2wc(int Popt,                                     //~v600I~
                    UCHAR *Pdata,          //data addr             //~v600I~
                    int Plenutf,           //data length           //~v600I~
                    int Pstartpos,         //skip column           //~v600I~
                    int Pmaxcol,           //right boundary column from Pstartpos(-1:no limit)//~v600I~
                    int Pmaxlenutf,        //right boundary by length from Pstartpos(-1:no limit)//~v600I~
                    PCHOFTYPE Ppchof,      //output:chof top(0 if no chof set)//~v600I~
                    int Pinitoffs,         //offsetvalue for top of Pchof//~v600I~
                    int *Ppcharcnt,        //output:charcnt        //~v600I~
                    int *Ppstartoffs,      //output:offset corresponding to Pstartpos//~v600I~
                    int *Pplenutf);        //output:chked data length after Pstartoffs//~v600R~
//*******************************************************          //~v600I~
//*utf strchk by mbrtowc                                           //~v600I~
//* assign 1 column for each for invalid/inmatured utf char        //~v600I~
//* rc:errutf/dbcssplit                                            //~v600I~
//*******************************************************          //~v600I~
int utfstrchkmbr2wc(int Popt,                                      //~v600I~
                    UCHAR *Pdata,          //data addr             //~v600I~
                    int Plenutf,           //data length           //~v600I~
                    int Pstartpos,         //skip column           //~v600I~
                    int Pmaxcol,           //right boundary column from Pstartpos(-1:no limit)//~v600I~
                    int Pmaxlenutf,        //right boundary by length from Pstartpos(-1:no limit)//~v600I~
                    PCHOFTYPE Ppchof,      //output:chof top(0 if no chof set)//~v600I~
                    int Pinitoffs,         //offsetvalue for top of Pchof//~v600I~
                    int *Ppcharcnt,        //output:charcnt        //~v600I~
                    int *Ppstartoffs,      //output:offset corresponding to Pstartpos//~v600I~
                    int *Pplenutf);        //output:chked data length after Pstartoffs//~v600R~
//******************************************************           //~v600I~
int utfgetposoffsmbr2wc(int Popt,PUTCHARS Pputcs,int Pposoff,int *Pppos,int *Ppoffs);//~v600R~
//******************************************************           //~v600I~
int utfeqchof(int Popt,PUTCHARS Pputc,int Ppos,int Pch);           //~v600R~
//******************************************************           //~v600I~
int utfmemsetchof(int Popt,PUTCHARS Pputc,int Ppos,int Pch,UINT Plen);//~v600R~
//******************************************************           //~v600I~
int utfmemcpychof(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,UINT Plen);//~v600I~
//******************************************************           //~v600I~
int utfmemcmpchof(int Popt,PUTCHARS Pputct,int Ppost,PUTCHARS Pputcs,int Pposs,UINT Plen);//~v600I~
//******************************************************           //~v61bI~
int utfgetwc(UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Pchklen);     //~v61bM~
//******************************************************           //~v600I~
int utfctr2offs(int Popt,char *Putf8,char *Pdbcs,char *Pcodetype,int Ppos,int Putf8len,int *Ppoffs,int *Ppwidth);//~v650R~
//******************************************************           //~v600I~
//******************************************************           //~v600I~
//******************************************************           //~v600I~
#ifdef UTF8UCS2                                                    //~v647I~
//int mk_wcwidth_cjk(UWCHART ucs);                                   //~v647R~//+v6BjR~
int mk_wcwidth_cjk(UWUCS ucs);                                     //+v6BjI~
//int mk_wcwidth_j(UWCHART ucs);                                     //~v647R~//+v6BjR~
int mk_wcwidth_j(UWUCS ucs);                                       //+v6BjI~
//int mk_wcwidth(UWCHART ucs);                                       //~v647R~//+v6BjR~
int mk_wcwidth(UWUCS ucs);                                         //+v6BjI~
//int mk_wcwidth_combining(wchar_t ucs);                           //~v650R~
//int mk_wcwidth_combining(UWCHART ucs);                             //~v650I~//+v6BjR~
int mk_wcwidth_combining(UWUCS ucs);                               //+v6BjI~
//int mk_wcwidth_adjsbcs(UWCHART ucs);                               //~v6c5R~//+v6BjR~
int mk_wcwidth_adjsbcs(UWUCS ucs);                                 //+v6BjI~
#else                                                              //~v647I~
int mk_wcwidth_cjk(wchar_t ucs);                                   //~v600I~
int mk_wcwidth_j(wchar_t ucs);                                     //~v600I~
int mk_wcwidth(wchar_t ucs);                                       //~v600I~
#endif                                                             //~v647I~
//******************************************************           //~v6dfI~
int utfstrvalidate(int Popt,char *Pstr,int Plen,int Perrch,int *Ppokctr,int *Pprepctr);//~v6dfI~
//******************************************************           //~v6dfI~
#ifdef ARM                            //wchar_t:char if APIlevel<9 //~v650I~
   	#ifndef ARMAPI9                                                //~v650I~
		#define mbtowc  mbtowc_api4                                //~v650I~
		#define wctomb  wctomb_api4                                //~v650I~
		#define mbrtowc mbrtowc_api4                               //~v650I~
		#define wctomb  wctomb_api4                                //~v650I~
    #endif                                                         //~v650I~
#endif                                                             //~v650I~
//int utfcvf2lany1ICU(int Popt,char *Pplocale,ULONG *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5R~
int utfcvf2lany1ICU(int Popt,char *Pplocale,ULPTR *Pphandle,char *Pout,int Poutbufflen,char *Pinp,int Pinplen,//~v6x5I~
			int *Ppchklen,int *Ppoutlen);                          //~v6f3M~
//int utfcvl2fany1ICU(int Popt,char *Pplocale,ULONG *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6f3I~//~v6hhR~
int utfcvl2fany1ICU(int Popt,char *Pplocale,ULPTR *Pphandle,char *Poututf8,int Poutbufflen,char *Pinp,int Pinplen,//~v6hhI~
			int *Ppchklen,int *Ppoutlen);                          //~v6f3I~
char *utfcvsetdefaultlocaleICU(int Popt);                          //~v6f3I~
