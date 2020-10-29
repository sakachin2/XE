//*CID://+v710R~:                             update#=  380;       //~v6D0R~//+v710R~
//**************************************************
//*DBCS sjis/euc translation                                       //~v5n8I~
//**************************************************
//v710:201021 (BUG)duplicate declaration Gudbcschk_flag            //+v710I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6C1:160328 (BUG) 8fxxxx(EUC) was not translated to sjis         //~v6C1I~
//v6s1:140212 around v6s0;no need to set TTYCONS for xterm. but on xterm,xterm can not display utf8 japanese//~v6s1I~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h5:120606 (WTL)Bug found by vs2010exp(used uninitialized variable)//~v6h5I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6bt:120102 add "get ucsctr of ddfmt" for cmdline shrink-#2      //~v6btI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62j:090907 UTF8SUPP-->UTF8SUPPH for common to xe and wxe        //~v62jI~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5na:080929 split udbcschk.c to udbcsck2.c                       //~v5n8I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//**************************************************               //~v022I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v39PI~
	#include <unistd.h>                                            //~v39PI~
#else                                                              //~v609I~
//  #ifdef UTF8SUPP                                                //~v5mQR~
    #if defined(W32)||defined(LNX)                                 //~v5mQR~
		#include <locale.h>                                        //~v609I~
	#endif                                                         //~v609I~
#endif                                                             //~v39PI~
//*************************************************************
#ifdef UNX                                                         //~v326R~
	#ifdef LNX                                                     //~v582I~
	  #if !(defined(ARM) && defined(XXE))                          //~v6a0I~
//    #ifndef NOCURSES                                             //~v6hhR~
      #ifndef NOCURSES                                             //~v6k0I~
        #include <term.h>                                          //~v582I~
      #endif //NOCURSES                                            //~v6k0I~
//    #endif //NOCURSES                                            //~v6hhR~
	  #endif //ARMXXE                                              //~v6a0I~
        #include <locale.h>                                        //~v5ifI~
//    #ifdef UTF8SUPP                                              //~v5mQR~
        #include <wchar.h>                                         //~v61bI~
		#include <iconv.h>                                         //~v5n8I~
//    #endif                                                       //~v5mQR~
    #endif                                                         //~v582R~
#else        //!LINUX                                              //~v326I~
#ifdef DOS
	#include <dos.h>
#else
    #ifdef W32                                                     //~v022I~
    	#include <windows.h>                                       //~v022I~
    	#include <wchar.h>                                         //~v5mQI~
      #ifdef WXE                                                   //~v570I~
    	#include <winnls.h>                                        //~v570I~
      #endif                                                       //~v570I~
    #else                                                          //~v022I~
	    #define INCL_BASE                                          //~v022R~
    	#include <os2.h>                                           //~v022R~
	#endif                                                         //~v022I~
#endif
#endif     //!UNX                                                  //~v326I~
//*************************************************************
#include <ulib.h>
#include <uerr.h>
//#define UDBCSCHK_GBLDEF                                            //~v39kI~//+v710R~
#include <udbcschk.h>
#include <ustring.h>
#ifdef DPMI					//DPMI version                         //~v053I~
	#include <udpmisub.h>                                          //~v053I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
#include <utrace.h>                                                //~v57eI~
#ifndef DOSDOS                                                     //~v57pI~
	#include <ucvucs.h>                                            //~v57pI~
#endif                                                             //~v57pI~
#ifdef WCSUPP                                                      //~v5n8I~
	#include <ukbd.h>                                              //~v5n8I~
	#include <uvio.h>                                              //~v5n8I~
	#include <ucvext.h>                                            //~v5n8I~
	#include <ucvext2.h>                                           //~v5n8I~
#endif                                                             //~v5n8I~
#ifdef UNX                                                         //~v582R~
	#include <ukbdl.h>                                             //~v582I~
	#include <uviol.h>                                             //~v6a0I~
	#include <ukbdlnxc.h>                                          //~v6a0I~
#endif                                                             //~v582I~
                                                                   //~v5i9I~
#include <utf.h>                                                   //~v5i9I~
//*******************************************************          //~v024I~
#define PC98        //accept NEC PC98 gaiji                        //~v5mNI~
//#define MAX_JIS   0x7424  //max for SW3.5                        //~v39HR~
#define SJIS        5                                              //~v39xI~
#define EUC         4                                              //~v39xI~
//int uhan2zen(unsigned char Pkatakana,unsigned char **Ppnext,unsigned char *Pend,int Popt);//~v50bR~
int uhan2zen(unsigned int Pkatakana,unsigned char **Ppnext,unsigned char *Pend,int Popt);//~v50bI~
                                                                   //~v39PI~
#ifdef UNX                                                         //~v39HI~
#else                                                              //~v39HI~
static	char   Sjistbl[256]={//04:dbcs 1st ,08:dbcs 2nd            //~v122I~
//       0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f            //~v122I~
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //00    //~v122I~
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //10    //~v122I~
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //20    //~v122I~
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //30    //~v122I~
         8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,   //40    //~v122I~
         8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,   //50    //~v122I~
         8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,   //60    //~v122I~
         8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0,   //70    //~v122I~
         8,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,   //80    //~v122I~
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,   //90    //~v122I~
         8,10,10,10,10,10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,   //a0    //~v122I~
         9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,   //b0    //~v122I~
         9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,   //c0    //~v122I~
         9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,   //d0    //~v122I~
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,   //e0    //~v122I~
        12,12,12,12,12,12,12,12,12,12,12,12,12, 0, 0, 0};  //f0    //~v39xR~
#endif                                                             //~v39HI~
//*******************************************************          //~v39NI~
//*ujischkx208                                                     //~v39NR~
//* jis X 208 tbl chk                                              //~v39NI~
//* parm1 :jis code 1st byte                                       //~v39NI~
//* parm2 :jis code 2nd byte                                       //~v39NI~
//* return:1:jis ok,0:err                                          //~v39NI~
//******************************************************           //~v39NI~
int ujischkx208(int P1,int P2)                                     //~v39NR~
{                                                                  //~v39NI~
#define JIS1_START   0x21                                          //~v39NR~
#define JIS1_END     0x74                                          //~v39NR~
#define JIS2_START   0x21                                          //~v39NR~
#define JIS2_END     0x7e                                          //~v39NR~
#define JIS1_SIZE   (JIS1_END-JIS1_START+1)                        //~v39NR~
#define JIS2_SIZE   (JIS2_END-JIS2_START+1)                        //~v39NR~
static char Sjis_22[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //20       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,         //30       //~v39NI~
               1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,         //40       //~v39NI~
               1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,         //60       //~v39NI~
               0,0,1,1,1,1,1,1,1,1,0,0,0,0,1  };        //70       //~v39NI~
static char Sjis_23[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,         //30       //~v39NI~
               0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NR~
               1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,         //50       //~v39NI~
               0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,0,0,0,0  };        //70       //~v39NI~
static char Sjis_24[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //30       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_25[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //30       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_26[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,         //30       //~v39NI~
               0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NR~
               1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,         //50       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_27[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //30       //~v39NI~
               1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //40       //~v39NI~
               0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,0,0,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_28[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //30       //~v39NI~
               1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //40       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //50       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_4f[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //20       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //30       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,         //50       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
static char Sjis_74[JIS2_SIZE]={                                   //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
                 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,         //20       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //30       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //40       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //50       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  };        //70       //~v39NI~
typedef struct _jistbl {int jis1stsw;char *jis2ndtbl;} jistbl;     //~v39NR~
static jistbl Sjis208tbl[JIS1_SIZE]={                              //~v50bR~
//0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f//~v39NI~
        {1,0},                                                                                    //20//~v39NI~
              {2,Sjis_22},                                         //~v39NI~
                    {2,Sjis_23},                                   //~v39NI~
                          {2,Sjis_24},                             //~v39NI~
                                {2,Sjis_25},                       //~v39NI~
                                      {2,Sjis_26},                 //~v39NI~
                                            {2,Sjis_27},           //~v39NI~
                                                  {2,Sjis_28},     //~v39NI~
                                                        {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//20//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},//30//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},      //40//~v39NI~
                                                                                            {2,Sjis_4f},//40//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},//50//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},//60//~v39NI~
  {1,0},{1,0},{1,0},{1,0},                                                                        //70//~v39NI~
                          {2,Sjis_74}};//70                        //~v39NI~
//*********************************                                //~v39NI~
	P1-=JIS1_START;                                                //~v39NR~
    if (P1<0 || P1>=JIS1_SIZE)                                     //~v39NR~
    	return 0;				//err                              //~v39NI~
	P2-=JIS2_START;                                                //~v39NR~
    if (P2<0 || P2>=JIS2_SIZE)                                     //~v39NR~
    	return 0;				//err                              //~v39NI~
    switch(Sjis208tbl[P1].jis1stsw)                                //~v50bR~
    {                                                              //~v39NI~
    case 1:		//full,0x21-->0x7e                                 //~v39NI~
    	return 1;                                                  //~v39NI~
    case 2:		//partial                                          //~v39NI~
    	return (int)*(Sjis208tbl[P1].jis2ndtbl+P2);                //~v50bR~
    }                                                              //~v39NI~
    return 0;                                                      //~v39NI~
}//ujischkx208                                                     //~v39NR~
//*******************************************************          //~v39NI~
//*usjischkx208                                                    //~v39NR~
//* jis X 208 by sjis tbl chk                                      //~v39NI~
//* parm1 :sjis code 1st byte                                      //~v39NI~
//* parm2 :sjis code 2nd byte                                      //~v39NI~
//* return:1:sjis ok,0:err                                         //~v39NI~
//******************************************************           //~v39NI~
int usjischkx208(int P1,int P2)                                    //~v39NR~
{                                                                  //~v39NI~
#define SJIS1_START   0x81                                         //~v39NR~
#define SJIS1_END     0xea                                         //~v39NR~
#define SJIS2_START   0x40                                         //~v39NR~
#define SJIS2_END     0xfc                                         //~v39NR~
#define SJIS1_SIZE   (SJIS1_END-SJIS1_START+1)                     //~v39NR~
#define SJIS2_SIZE   (SJIS2_END-SJIS2_START+1)                     //~v39NR~
static char Ssjis_81[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //70       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,         //a0       //~v39NI~
               0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,         //b0       //~v39NI~
               0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,         //c0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,         //d0       //~v39NI~
               1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,         //e0       //~v39NI~
               1,1,1,1,1,1,1,1,0,0,0,0,1      };        //f0       //~v39NI~
static char Ssjis_82[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,         //70       //~v39NI~
               0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //a0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //b0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //c0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //d0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //e0       //~v39NI~
               1,1,0,0,0,0,0,0,0,0,0,0,0      };        //f0       //~v39NI~
static char Ssjis_83[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //70       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //a0       //~v39NI~
               1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,         //b0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //c0       //~v39NI~
               1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,         //d0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //e0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0      };        //f0       //~v39NI~
static char Ssjis_84[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //70       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //a0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //b0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //c0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //d0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //e0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0      };        //f0       //~v39NI~
#ifdef PC98                                                        //~v39NI~
static char Ssjis_87[SJIS2_SIZE]={       //pc98 gaiji              //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,         //70       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,         //90       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //a0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //b0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //c0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //d0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //e0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0      };        //f0       //~v39NI~
#endif                                                             //~v39NI~
static char Ssjis_88[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //40       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //50       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //60       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //70       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //80       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //a0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //b0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //c0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //d0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //e0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1      };        //f0       //~v39NI~
static char Ssjis_98[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,         //70       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //80       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,         //90       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //a0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //b0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //c0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //d0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //e0       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1      };        //f0       //~v39NI~
static char Ssjis_ea[SJIS2_SIZE]={                                 //~v39NR~
//             0 1 2 3 4 5 6 7 8 9 a b c d e f                     //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //40       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //50       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //60       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,         //70       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //80       //~v39NI~
               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,         //90       //~v39NI~
               1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,         //a0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //b0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //c0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //d0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,         //e0       //~v39NI~
               0,0,0,0,0,0,0,0,0,0,0,0,0      };        //f0       //~v39NI~
typedef struct _ssjistbl {int sjis1stsw;char *sjis2ndtbl;} sjistbl;//~v39NR~
static sjistbl Ssjistbl[SJIS1_SIZE]={                              //~v39NR~
//0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f//~v39NI~
        {2,Ssjis_81},                                                                              //80//~v39NR~
              {2,Ssjis_82},                                        //~v39NI~
                    {2,Ssjis_83},                                  //~v39NI~
                          {2,Ssjis_84},                            //~v39NI~
                                {0,0},{0,0},                       //~v39NI~
#ifdef PC98                                                        //~v39NI~
                                            {2,Ssjis_87},          //~v39NI~
#else                                                              //~v39NI~
                                            {0,0},                 //~v39NI~
#endif                                                             //~v39NI~
                                                  {2,Ssjis_88},    //~v39NI~
                                                        {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},//80//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},                                                //90//~v39NI~
                                                  {2,Ssjis_98},    //~v39NI~
                                                        {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},//90//~v39NI~
  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//a0//~v39NI~
  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//b0//~v39NI~
  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//c0//~v39NI~
  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//d0//~v39NI~
  {1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},                                    //e0//~v39NI~
                                                              {2,Ssjis_ea}};                      //e0//~v39NI~
//*********************************                                //~v39NI~
#if defined(AIX) || defined(W32)                                   //~v57pI~
    if (Gudbcschk_flag & UDBCSCHK_MS932)	//ms932 chk            //~v57pI~
        return (ucp932sjis2ucs((P1<<8)+P2)!=UCVERRUCS);//chk sjis->ucs copnv tbl//~v57pR~
#endif                                                             //~v57pI~
	P1-=SJIS1_START;                                               //~v39NR~
    if (P1<0 || P1>=SJIS1_SIZE)                                    //~v39NR~
    	return 0;				//err                              //~v39NI~
	P2-=SJIS2_START;                                               //~v39NR~
    if (P2<0 || P2>=SJIS2_SIZE)                                    //~v39NR~
    	return 0;				//err                              //~v39NI~
    switch(Ssjistbl[P1].sjis1stsw)                                 //~v39NR~
    {                                                              //~v39NI~
    case 1:		//full,0x40-->0x7e,0x80-->0xfc                     //~v39NI~
    	return (P2!=(0x7f-SJIS2_START));                           //~v39NR~
    case 2:		//partial                                          //~v39NI~
    	return (int)*(Ssjistbl[P1].sjis2ndtbl+P2);                 //~v39NR~
    }                                                              //~v39NI~
    return 0;                                                      //~v39NI~
}//usjischkx208                                                    //~v39NR~
//*******************************************************          //~v122I~
//*usjis2jis                                                       //~v122I~
//* dbcs code conversion,shift jis to jis;regardless dbcs environment//~v122I~
//* parm1 :shift jis code(dbcs1st+2nd)                             //~v122I~
//* return:jis code;0 if code err                                  //~v122I~
//******************************************************           //~v122I~
unsigned int usjis2jis(unsigned int Psjis)                         //~v198R~
{                                                                  //~v122I~
    unsigned int c1,c2;                                            //~v198R~
//*********************************                                //~v122I~
	c1=((Psjis & 0xff00)>>8);                                      //~v122I~
	c2=(Psjis & 0xff);                                             //~v122I~
#ifdef UNX                                                         //~v39HI~
//	if (!usjischkx208(c1,c2))	//JIS X 208                        //~v39NR~//~v6D0R~
  	if (!usjischkx208((int)c1,(int)c2))	//JIS X 208                //~v6D0I~
    	return 0;                                                  //~v39HI~
#else                                                              //~v39HI~
    if (!(Sjistbl[c1] & 0x04))	//dbcs 1st byte                    //~v122I~
    	return 0;                                                  //~v122I~
    if (!(Sjistbl[c2] & 0x08))  //dbcs 2nd byte                    //~v122I~
    	return 0;                                                  //~v122I~
#endif                                                             //~v39HI~
                                                                   //~v122I~
	if (c1>=0xa0)			//2nd part                             //~v122I~
    	c1-=0xc1;                                                  //~v122I~
	else                    //1st part                             //~v122I~
    	c1-=0x81;                                                  //~v122I~
                                                                   //~v122I~
    if (c2>=0x9f)			                                       //~v122I~
    {                                                              //~v122I~
    	c1+=0x11;                                                  //~v122I~
        c1<<=9;                                                    //~v122I~
        c2-=0x7e;                                                  //~v122I~
    }                                                              //~v122I~
    else                                                           //~v122I~
    {                                                              //~v122I~
        if (c2<=0x7e)                                              //~v122I~
        	c2-=0x1f;                                              //~v122I~
        else                                                       //~v122I~
        	c2-=0x20;                                              //~v122I~
        c1<<=9;                                                    //~v122I~
        c1+=0x2100;                                                //~v122R~
    }                                                              //~v122I~
	return c1+c2;                                                  //~v122I~
}//usjis2jis                                                       //~v122I~
//*******************************************************          //~v39xI~
//*ujis2sjis                                                       //~v39xI~
//* dbcs code conversion,jis to shift jis;regardless dbcs environment//~v39xI~
//* parm1 :jis code(dbcs1st+2nd)                                   //~v39xI~
//* return:shift jis code,0 if err                                 //~v39xI~
//******************************************************           //~v39xI~
unsigned int ujis2sjis(unsigned int Psjis)                         //~v39xR~
{                                                                  //~v39xI~
    unsigned int c1,c2,sjis;                                       //~v39GR~
  	int rowOffset,cellOffset;                                      //~v39xI~
//*********************************                                //~v39xI~
	c1=((Psjis & 0xff00)>>8);                                      //~v39xI~
	c2=(Psjis & 0xff);                                             //~v39xI~
#ifdef UNX                                                         //~v39HI~
//  if (!JIS1(c1) || !JIS2(c2))	//JIS X208 chk                     //~v39NR~
//  if (!ujischkx208(c1,c2))       	//JIS X208 chk                 //~v39NR~//~v6D0R~
    if (!ujischkx208((int)c1,(int)c2))       	//JIS X208 chk     //~v6D0I~
        return 0;                                                  //~v39HI~
#endif                                                             //~v39HI~
  	rowOffset = c1 < 0x5f ? 0x70 : 0xb0;                           //~v39xI~
  	cellOffset = c1 % 2 ? (c2 > 0x5f ? 0x20 : 0x1f) : 0x7e;        //~v39xI~
// 	c1 = ((c1 + 1) >> 1) + rowOffset;                              //~v39xI~//~v6D0R~
   	c1 = ((c1 + 1) >> 1) + (unsigned)rowOffset;                    //~v6D0I~
//	c2 += cellOffset;                                              //~v39xI~//~v6D0R~
  	c2 += (unsigned)cellOffset;                                    //~v6D0I~
                                                                   //~v39xI~
#ifdef UNX                                                         //~v39HI~
#else                                                              //~v39HI~
    if (!(Sjistbl[c1] & 0x04))  //dbcs 1st byte                    //~v39HR~
        return 0;                                                  //~v39HR~
    if (!(Sjistbl[c2] & 0x08))  //dbcs 2nd byte                    //~v39HR~
        return 0;                                                  //~v39HR~
#endif                                                             //~v39HI~
    sjis=(c1<<8)+c2;                                               //~v39GR~
//    if (sjis>MAX_JIS)                                            //~v39HR~
//        return 0;                                                //~v39HR~
    return sjis;                                                   //~v39GI~
}//ujis2sjis                                                       //~v39xI~
//*******************************************************          //~v560M~
//*ustrjis2sjis                                                    //~v560M~
//* convert jis string to sjis string                              //~v560M~
//*parm1:opt:conv to sjis or euc                                   //~v560M~
//*parm2:input jis string                                          //~v560M~
//*parm3:input len,if 0 use strlen and set ouput null term.        //~v560I~
//*parm4:output string                                             //~v560M~
//*parm5:output outarea len                                        //~v560M~
//*rc   :                 02:dbcs err,10:hankaku found,20:dbcs found//~v560I~
//*******************************************************          //~v560M~
int ustrjis2sjis(int Popt,UCHAR *Pjisstr,int Plen,UCHAR *Poutstr,int *Poutlen)//~v560M~
{                                                                  //~v560M~
  	UCHAR *pci,*pco,*pce,hankana;                                  //~v560R~
    UINT  sjis;                                                    //~v560M~
    int   codetype=CT_ASCII,len,rc=0;                              //~v560R~
    int contlinesw,parmcodetype;                                   //~v57dR~
//******************************                                   //~v560M~
    contlinesw=(Popt & UDBCSCHK_CONTLINE);                         //~v57dI~
	parmcodetype=(Popt & UDBCSCHK_JISMODE);	//codetype parm for contined line//~v57dI~
	if (parmcodetype)	//codetype parm for contined line          //~v57dI~
		codetype=(int)((UINT)parmcodetype>>UDBCSCHK_RC_JISMODESHIFT);	//return jismode for cont line//~v5i7R~
	len=Plen;                                                      //~v560M~
    if (!len)                                                      //~v560M~
    	len=(int)strlen(Pjisstr);                                  //~v560M~
	for (pci=Pjisstr,pce=pci+len,pco=Poutstr;pci<pce;pci++)        //~v560M~
    {                                                              //~v560M~
//      len=(int)((ULONG)pci-(ULONG)Pjisstr);                      //~v57dR~
//      len=(int)((ULONG)pce-(ULONG)pci);                          //~v57dR~//~v6hhR~
        len=(int)((ULPTR)pce-(ULPTR)pci);                          //~v6hhI~
UTRACEP("jis2sjis len=%d\n",len);                                  //~v57eI~
//  	if (*pci==0x1b && len>3)                                   //~v57fR~
    	if (*pci==0x1b && len>=3)                                  //~v57fI~
        {                                                          //~v560M~
UTRACEP("jis2sjis 1b len=%d\n",len);                               //~v57eI~
        	switch(*(pci+1))                                       //~v560M~
            {                                                      //~v560M~
            case '$':                                              //~v560M~
	        	switch(*(pci+2))                                   //~v560M~
    	        {                                                  //~v560M~
                case 'B':			//ESC$B   //JISx0208 1983      //~v560M~
                    codetype=CT_JIS83;                             //~v560M~
                    pci+=2;                                        //~v560M~
                	continue;                                      //~v560M~
                case '@':			//ESC$@   //JISx0208 1978      //~v560M~
                    codetype=CT_JIS78;                             //~v560M~
                    pci+=2;                                        //~v560M~
                	continue;                                      //~v560M~
    	        }                                                  //~v560M~
            	break;                                             //~v560M~
            case '(':                                              //~v560M~
	        	switch(*(pci+2))                                   //~v560M~
    	        {                                                  //~v560M~
                case 'B':			//ESC(B   //ASCII              //~v560M~
                    codetype=CT_ASCII;                             //~v560M~
                    pci+=2;                                        //~v560M~
                	continue;                                      //~v560M~
                case 'J':			//ESC(J   //JISx0201 ROMAN     //~v560M~
                    codetype=CT_ROMAN;                             //~v560R~
                    pci+=2;                                        //~v560R~
                	continue;                                      //~v560M~
                case 'I':			//ESC(I   //JISx0201 katakana  //~v560M~
                    codetype=CT_KATAKANA;                          //~v560M~
                    pci+=2;                                        //~v560M~
                	continue;                                      //~v560M~
    	        }                                                  //~v560M~
            	break;                                             //~v560M~
            case '&':                                              //~v560I~
	        	if (*(pci+2)=='@')   //ESC&@   //jis90             //~v560I~
                    continue;                                      //~v560I~
            	break;                                             //~v560I~
            }//ESC$ or ESC(                                        //~v560M~
        }//ESC                                                     //~v560M~
        else                                                       //~v57dI~
//  	if (*pci==0x1b && len<=3 && contlinesw) //spli line        //~v57fR~
    	if (*pci==0x1b && len<3 && contlinesw) //spli line         //~v57fI~
        {                                                          //~v57dI~
        	rc|=(len<<UDBCSCHK_RC_JISSPLITSHIFT);	//UDBCSCHK_RC_JISSPLIT//~v57dR~
UTRACEP("jis2sjis 1b len=%d,rc=5x\n",len,rc);                      //~v57eI~
            break;                                                 //~v57dI~
        }                                                          //~v57dI~
        else	//not ESC                                          //~v560M~
        {                                                          //~v560M~
            switch(codetype)                                       //~v560M~
            {                                                      //~v560M~
            case CT_JIS78:                                         //~v560M~
            case CT_JIS83:                                         //~v560M~
			  if (len<2)	//no dbcs len                          //~v57dI~
              {                                                    //~v57dI~
                	if (contlinesw)                                //~v57dI~
	            		rc|=UDBCSCHK_RC_DBCSSPLIT;                 //~v57dI~
                    else                                           //~v57dI~
		            	rc|=UDBCSCHK_RC_DBCSERR;                   //~v57dI~
			  }                                                    //~v57dI~
              else                                                 //~v57dI~
              {                                                    //~v57dI~
				sjis=ujis2sjis((UINT)((*pci<<8)+*(pci+1)));        //~v57pR~
                if (sjis)	//valid dbcs code                      //~v560M~
                {                                                  //~v560M~
                	*pco++=(UCHAR)(sjis>>8);                       //~v560R~
                	*pco++=(UCHAR)(sjis&255);                      //~v560R~
                    pci++;   		//skip 1st byte                //~v560M~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v560I~
                    continue;                                      //~v560M~
                }                                                  //~v560M~
              }                                                    //~v57dI~
            	rc|=UDBCSCHK_RC_DBCSERR;                           //~v560I~
            	break;                                             //~v560M~
            case CT_KATAKANA:               //ESC(I  7bit code input//~v560M~
            	*pco++=hankana=(UCHAR)(*pci|0x80);                 //~v560R~
        		if (HANKATA(hankana))                              //~v560I~
	                rc|=UDBCSCHK_RC_HANKANAFOUND;                  //~v560I~
                continue;                                          //~v560M~
            case CT_ROMAN:                  //ESC(J  8bit          //~v560M~
                if (*pci==0x0e)       //ESC(J+S/O                  //~v560R~
                {                                                  //~v560I~
                 	codetype=CT_ROMAN7;                            //~v560I~
                   	continue;                                      //~v560I~
                }                                                  //~v560I~
            	*pco++=hankana=*pci;                               //~v560R~
        		if (HANKATA(hankana))                              //~v560I~
	                rc|=UDBCSCHK_RC_HANKANAFOUND;                  //~v560I~
                continue;                                          //~v560M~
            case CT_ROMAN7:                  //ESC(J+S/O  7 bit    //~v560M~
            	if (*pci==0x0f)                                    //~v560M~
                {                                                  //~v560I~
                	codetype=CT_ASCII;                             //~v560M~
                   	continue;                                      //~v560I~
                }                                                  //~v560I~
                *pco++=hankana=(UCHAR)(*pci|0x80);                 //~v560R~
                if (HANKATA(hankana))                              //~v560R~
                    rc|=UDBCSCHK_RC_HANKANAFOUND;                  //~v560R~
                continue;                                          //~v560M~
            }//code type                                           //~v560M~
        }//ESC or else                                             //~v560M~
	    if (rc & UDBCSCHK_RC_DBCSSPLIT)                            //~v57dI~
        	break;	//loop exit                                    //~v57dI~
        *pco++=*pci;		//ASCII or fmt err case                //~v560M~
    }//string loop                                                 //~v560M~
    if (!Plen)              //input is strz                        //~v560M~
        *pco=0;             //null term                            //~v560M~
//  *Poutlen=(int)((ULONG)pco-(ULONG)Poutstr);                     //~v560M~//~v6hhR~
    *Poutlen=(int)((ULPTR)pco-(ULPTR)Poutstr);                     //~v6hhI~
	rc|=(codetype<<UDBCSCHK_RC_JISMODESHIFT);	//return jismode for cont line//~v57dI~
	return rc;                                                     //~v560R~
}//ustrjis2sjis                                                    //~v560M~
//*******************************************************          //~v57eI~
//*ustrsjis2jis                                                    //~v57eI~
//* dbcs code conversion,shift jis to jis                          //~v57eI~
//*parm1:opt:                                                      //~v57eI~
//*parm2:input sjis string                                         //~v57eI~
//*parm3:input len,if 0 use strlen and set ouput null term.        //~v57eI~
//*parm4:output string                                             //~v57eI~
//*parm5:output outarea len                                        //~v57eI~
//* return:output euc string len                                   //~v57eI~
//*rc   :02:dbcs err,10:hankaku found,20:dbcs found                //~v57eI~
//******************************************************           //~v57eI~
int ustrsjis2jis(int Popt,unsigned char *Psjisstr,int Plen,unsigned char *Pjis,int *Poutlen)//~v57eI~
{                                                                  //~v57eI~
  	unsigned int p1,p2,jis,sjis;                                   //~v57eI~
    int codetype=CT_ASCII,len,rc=0,parmcodetype,hkcsw;             //~v57eR~
  	int contlinesw;                                                //~v57eI~
  	unsigned char *pci,*pco,*pce;                                  //~v57eR~
//*********************************                                //~v57eI~
    hkcsw=(Popt & UDBCSCHK_EUCHKCONV);      //hanzen conv          //~v57eI~
    contlinesw=(Popt & UDBCSCHK_CONTLINE);                         //~v57eI~
	parmcodetype=(Popt & UDBCSCHK_JISMODE);	//codetype parm for contined line//~v57eI~
	if (parmcodetype)	//codetype parm for contined line          //~v57eI~
		codetype=(int)((UINT)parmcodetype>>UDBCSCHK_RC_JISMODESHIFT);	//return jismode for cont line//~v5i7R~
	len=Plen;                                                      //~v57eI~
    if (!len)                                                      //~v57eI~
    	len=(int)strlen(Psjisstr);                                 //~v57eI~
  	for (pci=Psjisstr,pco=Pjis,pce=pci+len;pci<pce;)               //~v57eR~
    {                                                              //~v57eI~
    	p1=*pci++;                                                 //~v57eI~
    	if (SJIS1(p1) & (pci<pce))                                 //~v57eI~
		{                                                          //~v57eI~
      		p2=*pci++;                                             //~v57eI~
      		if (SJIS2(p2))                                         //~v57eI~
			{                                                      //~v57eI~
        		jis=usjis2jis((p1<<8)+p2);                         //~v57eI~
                if (jis)//success                                  //~v57eI~
                {                                                  //~v57eI~
                	if (codetype!=CT_JIS83)                        //~v57eI~
                    {                                              //~v57eI~
	            		if (codetype==CT_ROMAN7)                   //~v57eI~
    	            		*pco++=0x0f;	//shift in,close 8bit mode//~v57eI~
		            	codetype=CT_JIS83;                         //~v57eI~
                        *pco++=0x1b;                               //~v57eI~
                        *pco++='$';                                //~v57eI~
                        *pco++='B';	//esc$B jis83                  //~v57eI~
                    }                                              //~v57eI~
                    *pco++=(UCHAR)(jis>>8);                        //~v57eR~
                    *pco++=(UCHAR)(jis&255);                       //~v57eR~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v57eI~
                    continue;                                      //~v57eI~
                }                                                  //~v57eI~
      		}                                                      //~v57eI~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v57eI~
        }                                                          //~v57eI~
    	else                                                       //~v57eI~
        if (HANKATA(p1))                                           //~v57eI~
        {                                                          //~v57eI~
            rc|=UDBCSCHK_RC_HANKANAFOUND;                          //~v57eI~
            if (hkcsw)	//conv to zenkaku                          //~v57eI~
            {                                                      //~v57eI~
                sjis=(unsigned int)uhan2zen(p1,&pci,pce,SJIS);     //~v57eI~
                jis=usjis2jis(sjis);                               //~v57eI~
                if (codetype!=CT_JIS83)                            //~v57eI~
                {                                                  //~v57eI~
	            	if (codetype==CT_ROMAN7)                       //~v57eI~
    	            	*pco++=0x0f;	//shift in,close 8bit mode //~v57eI~
                    codetype=CT_JIS83;                             //~v57eI~
                    *pco++=0x1b;                                   //~v57eI~
                    *pco++='$';                                    //~v57eI~
                    *pco++='B'; //esc$B jis83                      //~v57eI~
                }                                                  //~v57eI~
                *pco++=(UCHAR)(jis>>8);                            //~v57eR~
                *pco++=(UCHAR)(jis&255);                           //~v57eR~
	            continue;                                          //~v57eI~
            }                                                      //~v57eI~
        }//hankaku katakana                                        //~v57eI~
        else                                                       //~v57eI~
    	if (pci==pce)	//last byte                                //~v57eI~
	    	if (SJIS1(p1) && contlinesw)                           //~v57eI~
            {                                                      //~v57eI~
                rc|=UDBCSCHK_RC_DBCSSPLIT;                         //~v57eI~
                break;                                             //~v57eI~
            }                                                      //~v57eI~
        if (p1 & 0x80)                                             //~v57eI~
        {                                                          //~v57eI~
            if (codetype!=CT_ROMAN7)                               //~v57eI~
            {                                                      //~v57eI~
                codetype=CT_ROMAN7;                                //~v57eI~
                *pco++=0x1b;                                       //~v57eI~
                *pco++='(';                                        //~v57eI~
                *pco++='J'; //esc(J 8bit display                   //~v57eI~
                *pco++=0x0e;	//shift out                        //~v57eI~
            }                                                      //~v57eI~
            p1 &=0x7f;      //7bit display                         //~v57eI~
        }                                                          //~v57eI~
        else                                                       //~v57eI~
        {                                                          //~v57eI~
            if (codetype!=CT_ASCII)                                //~v57eI~
            {                                                      //~v57eI~
            	if (codetype==CT_ROMAN7)                           //~v57eI~
                	*pco++=0x0f;	//shift in,close 8bit mode     //~v57eI~
                codetype=CT_ASCII;                                 //~v57eI~
                *pco++=0x1b;                                       //~v57eI~
                *pco++='(';                                        //~v57eI~
                *pco++='B'; //7bit mode                            //~v57eI~
            }                                                      //~v57eI~
        }                                                          //~v57eI~
        *pco++=(unsigned char)p1;                                  //~v57eI~
  	}//loop                                                        //~v57eI~
    if (Poutlen)                                                   //~v57eI~
//		*Poutlen=(int)((ULONG)pco-(ULONG)Pjis);                    //~v57eI~//~v6hhR~
		*Poutlen=(int)((ULPTR)pco-(ULPTR)Pjis);                    //~v6hhI~
	rc|=(codetype<<UDBCSCHK_RC_JISMODESHIFT);	//return jismode for cont line//~v57eI~
    return rc;                                                     //~v57eI~
}//ustrsjis2jis                                                    //~v57eR~
//*******************************************************          //~v39xI~
//*ushift2euc                                                      //~v39xI~
//* dbcs code conversion,shift jis to euc;regardless dbcs environment//~v39xR~
//* parm1 :sjis string                                             //~v39xI~
//* parm2 :optional input dbcstbl                                  //~v550I~
//* parm3 :sjis string len                                         //~v39xI~
//* parm4 :out area addr                                           //~v550I~
//* parm5 :optional dbcs id tbl                                    //~v550R~
//* parm6 :optional out len                                        //~v550I~
//* parm7 :option;conv hankaku katakana,keep tabid                 //~v550R~
//* return:output euc string len                                   //~v39xI~
//******************************************************           //~v39xI~
int ushift2euc(unsigned char *Psjis,unsigned char *Pdbcsi,int Plen,//~v550R~
				unsigned char *Peuc,unsigned char *Pdbcs,int *Poutlen,int Popt)//~v550I~
{                                                                  //~v39xI~
  	unsigned int p1,p2,jis,sjis;                                   //~v39xR~
  	int hkcsw;                                                     //~v39xR~
  	int hkconlysw;                                                 //~v550I~
  	int noclearsw;                                                 //~v549I~
  	int contlinesw;                                                //~v57dI~
  	int rc=0;                                                      //~v550I~
  	unsigned char *pci,*pco,*pcd,*pce;                             //~v39xR~
  	unsigned char *pcdi;                                           //~v550R~
//*********************************                                //~v39xI~
    hkcsw=(Popt & UDBCSCHK_EUCHKCONV);                             //~v39xI~
    hkconlysw=(Popt & UDBCSCHK_KANAONLY);                          //~v550I~
    noclearsw=(Popt & UDBCSCHK_NOCLEAR);                           //~v549I~
    contlinesw=(Popt & UDBCSCHK_CONTLINE);                         //~v57dI~
    pcdi=Pdbcsi;                                                   //~v550I~
  	for (pci=Psjis,pco=Peuc,pcd=Pdbcs,pce=pci+Plen;pci<pce;)       //~v39xR~
    {                                                              //~v39xI~
    	p1=*pci++;                                                 //~v39xI~
        pcdi++;                                                    //~v550R~
    	if (SJIS1(p1) & (pci<pce))                                 //~v39xR~
		{                                                          //~v39xI~
      		p2=*pci++;                                             //~v39xI~
    	    pcdi++;                                                //~v550R~
      		if (SJIS2(p2))                                         //~v39xI~
			{                                                      //~v39xI~
        		jis=usjis2jis((p1<<8)+p2);                         //~v39xR~
                if (jis)//success                                  //~v39xI~
                {                                                  //~v39xI~
                  if (hkconlysw)	                               //~v550I~
                  {                                                //~v550I~
                    *pco++=(UCHAR)p1;                              //~v550R~
                    *pco++=(UCHAR)p2;                              //~v550R~
                  }                                                //~v550I~
                  else                                             //~v550I~
                  {                                                //~v550I~
                    *pco++=(UCHAR)((jis>>8)+0x80);                 //~v39xR~
                    *pco++=(UCHAR)((jis&255)+0x80);                //~v39xR~
                  }                                                //~v550I~
                    if (pcd)                                       //~v39xR~
                    {                                              //~v39xR~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v39xR~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v39xR~
                    }                                              //~v39xR~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v550I~
                    continue;                                      //~v39xI~
                }                                                  //~v39xI~
      		}                                                      //~v39xI~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v550I~
        }                                                          //~v39xI~
    	else                                                       //~v39xI~
        if (HANKATA(p1))                                           //~v39xR~
        {                                                          //~v39xR~
            if (hkcsw)	//conv to zenkaku                          //~v39xR~
            {                                                      //~v39xR~
                sjis=(unsigned int)uhan2zen(p1,&pci,pce,SJIS);     //~v40vR~
              if (hkconlysw)                                       //~v550I~
              {                                                    //~v550I~
                *pco++=(UCHAR)(sjis>>8);                           //~v550I~
                *pco++=(UCHAR)(sjis&255);                          //~v550I~
              }                                                    //~v550I~
              else                                                 //~v550I~
              {                                                    //~v550I~
                jis=usjis2jis(sjis);                               //~v39xR~
                *pco++=(UCHAR)((jis>>8)+0x80);                     //~v39xR~
                *pco++=(UCHAR)((jis&255)+0x80);                    //~v39xR~
              }                                                    //~v550I~
                if (pcd)                                           //~v39xR~
                {                                                  //~v39xR~
                    *pcd++=UDBCSCHK_DBCS1ST;                       //~v39xR~
                    *pcd++=UDBCSCHK_DBCS2ND;                       //~v39xR~
                }                                                  //~v39xR~
            }                                                      //~v39xR~
            else                                                   //~v39xR~
            {                                                      //~v39xR~
        		*pco++=SS2;                                        //~v39xI~
        		*pco++=(UCHAR)p1;                                  //~v39xI~
                if (pcd)                                           //~v39xR~
                {                                                  //~v39xR~
                    *pcd++=UDBCSCHK_HK1;                           //~v39xR~
                    *pcd++=UDBCSCHK_HK2;                           //~v39xR~
                }                                                  //~v39xR~
            }                                                      //~v39xR~
            rc|=UDBCSCHK_RC_HANKANAFOUND;                          //~v550I~
            continue;                                              //~v39xI~
        }//hankaku katakana                                        //~v39xR~
        else                                                       //~v57dI~
    	if (pci==pce)	//last byte                                //~v57dI~
	    	if (SJIS1(p1) && contlinesw)                           //~v57dI~
            {                                                      //~v57dI~
                rc|=UDBCSCHK_RC_DBCSSPLIT;                         //~v57dR~
                break;                                             //~v57dI~
            }                                                      //~v57dI~
        *pco++=(unsigned char)p1;                                  //~v39xI~
        if (pcd)                                                   //~v39xR~
        {                                                          //~v549I~
//          *pcd=UDBCSCHK_SBCS;                                    //~v549I~
//        	if (!noclearsw                                         //~v550R~
//        	||  *pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)    //~v550R~
//      		*pcd=UDBCSCHK_SBCS;                                //~v550R~
            if (noclearsw)                                         //~v550I~
            {                                                      //~v550I~
              if (Pdbcsi)                                          //~v550I~
				if (*(pcdi-1)==UDBCSCHK_DBCS1ST||*(pcdi-1)==UDBCSCHK_DBCS2ND)//~v550R~
		            *pcd=UDBCSCHK_SBCS;                            //~v550I~
                else                                               //~v550I~
		        	*pcd=*(pcdi-1);		//keep tabid               //~v550R~
              else                                                 //~v550I~
              	if (*pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)//~v550I~
		            *pcd=UDBCSCHK_SBCS;                            //~v550I~
            }                                                      //~v550I~
            else                                                   //~v550I~
		        *pcd=UDBCSCHK_SBCS;                                //~v550I~
        	pcd++;                                                 //~v550R~
        }                                                          //~v549I~
  	}//loop                                                        //~v39xI~
//  return (int)((ULONG)pco-(ULONG)Peuc);                          //~v550R~
    if (Poutlen)                                                   //~v550I~
//		*Poutlen=(int)((ULONG)pco-(ULONG)Peuc);                    //~v550I~//~v6hhR~
		*Poutlen=(int)((ULPTR)pco-(ULPTR)Peuc);                    //~v6hhI~
    return rc;                                                     //~v550I~
}//ushift2euc                                                      //~v39xI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//*******************************************************          //~v614I~
//*ushift2euc                                                      //~v614I~
//* 1 sjis char to euc                                             //~v614I~
//* opt:hankana->zenkana conv                                      //~v614I~
//* ret:dbcs,hankana,dbcserr,0(sbcs)                               //~v614I~
//******************************************************           //~v614I~
int ushift2euc1(int Popt,int Psjis,int *Ppeuc)                     //~v614R~
{                                                                  //~v614I~
  	unsigned int p1,p2,jis,sjis,euc=0;                               //~v614I~//~v6h6R~
  	int hkcsw;                                                     //~v614I~
  	int rc=0;                                                      //~v614I~
  	unsigned char wk[2],*pcw;                                      //~v614R~
//*********************************                                //~v614I~
    hkcsw=(Popt & UDBCSCHK_EUCHKCONV);  //han->zen conv            //~v614I~
    p1=((UINT)Psjis>>8);                                           //~v5ntR~
    for (;;)                                                       //~v614I~
    {                                                              //~v614I~
        if (SJIS1(p1))                                             //~v614I~
        {                                                          //~v614I~
            p2=(UINT)(Psjis & 0xff);                               //~v5ntR~
            if (SJIS2(p2))                                         //~v614I~
            {                                                      //~v614I~
                jis=usjis2jis((UINT)Psjis);                        //~v5ntR~
                if (jis)//success                                  //~v614I~
                {                                                  //~v614I~
                    euc=jis+0x8080;                                //~v614I~
                    if (!(Popt & UDBCSCHK_RC0IFNOERR))             //~v614R~
	                    rc=UDBCSCHK_RC_DBCSFOUND;                  //~v614R~
                    break;                                         //~v614I~
                }                                                  //~v614I~
            }                                                      //~v614I~
            rc=UDBCSCHK_RC_DBCSERR;                                //~v614I~
            break;                                                 //~v614I~
        }                                                          //~v614I~
        if (HANKATA(Psjis))                                        //~v614I~
        {                                                          //~v614I~
            if (hkcsw)	//conv to zenkaku                          //~v614I~
            {                                                      //~v614I~
            	wk[0]=(UCHAR)Psjis;                                //~v614I~
                pcw=wk;                                            //~v614R~
                sjis=(unsigned int)uhan2zen(p1,&pcw,pcw+1,SJIS);   //~v614R~
                jis=usjis2jis(sjis);                               //~v614I~
                euc=jis+0x8080;                                    //~v614I~
            }                                                      //~v614I~
            else                                                   //~v614I~
        		euc=(UINT)((SS2<<8)+(UCHAR)Psjis);                 //~v5ntR~
            if (!(Popt & UDBCSCHK_RC0IFNOERR))                     //~v614R~
            	rc=UDBCSCHK_RC_HANKANAFOUND;                       //~v614R~
            break;                                                 //~v614I~
        }//hankaku katakana                                        //~v614I~
        if (p1)	//dbcs                                             //~v614I~
        {                                                          //~v614I~
            rc=UDBCSCHK_RC_DBCSERR;                                //~v614R~
            break;                                                 //~v614R~
        }                                                          //~v614I~
        euc=(unsigned char)Psjis;                                  //~v614I~
        break;                                                     //~v614I~
  	}//loop                                                        //~v614I~
    *Ppeuc=(int)euc;                                               //~v5ntR~
    return rc;                                                     //~v614I~
}//ushift2euc1                                                     //~v614I~
//#endif                                                           //~v5n8R~
//*******************************************************          //~v582I~
//*ushift2euccount                                                 //~v582I~
//* count output(EUC string) length                                //~v582I~
//* parm1 :sjis string                                             //~v582I~
//* parm2 :sjis string len                                         //~v582I~
//* parm3 :opt                                                     //~v582I~
//* return:output euc string len                                   //~v582I~
//******************************************************           //~v582I~
int ushift2euccount(unsigned char *Psjis,int Plen,int *Poutlen,int Popt)//~v582I~
{                                                                  //~v582I~
  	unsigned int p1,p2,jis;                                        //~v582R~
  	int contlinesw,pco;                                            //~v582R~
  	int rc=0;                                                      //~v582I~
  	unsigned char *pci,*pce;                                       //~v582R~
//*********************************                                //~v582I~
    contlinesw=(Popt & UDBCSCHK_CONTLINE);                         //~v582I~
  	for (pci=Psjis,pco=0,pce=pci+Plen;pci<pce;)                    //~v582R~
    {                                                              //~v582I~
    	p1=*pci++;                                                 //~v582I~
    	if (SJIS1(p1) & (pci<pce))                                 //~v582I~
		{                                                          //~v582I~
      		p2=*pci++;                                             //~v582I~
      		if (SJIS2(p2))                                         //~v582I~
			{                                                      //~v582I~
        		jis=usjis2jis((p1<<8)+p2);                         //~v582I~
                if (jis)//success                                  //~v582I~
                {                                                  //~v582I~
                    pco++;                                         //~v582I~
                    pco++;                                         //~v582I~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v582I~
                    continue;                                      //~v582I~
                }                                                  //~v582I~
      		}                                                      //~v582I~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v582I~
        }                                                          //~v582I~
    	else                                                       //~v582I~
        if (HANKATA(p1))                                           //~v582I~
        {                                                          //~v582I~
            pco++;                                                 //~v582I~
            pco++;                                                 //~v582I~
            rc|=UDBCSCHK_RC_HANKANAFOUND;                          //~v582I~
            continue;                                              //~v582I~
        }//hankaku katakana                                        //~v582I~
        else                                                       //~v582I~
    	if (pci==pce)	//last byte                                //~v582I~
	    	if (SJIS1(p1) && contlinesw)                           //~v582I~
            {                                                      //~v582I~
                rc|=UDBCSCHK_RC_DBCSSPLIT;                         //~v582I~
                break;                                             //~v582I~
            }                                                      //~v582I~
        pco++;                                                     //~v582R~
  	}//loop                                                        //~v582I~
    if (Poutlen)                                                   //~v582I~
		*Poutlen=pco;                                              //~v582R~
    return rc;                                                     //~v582I~
}//ushift2euccount                                                 //~v582I~
//*******************************************************          //~v40vI~
//*usjischk                                                        //~v40vI~
//* sjis string dbcs chk by jis X 208                              //~v40vR~
//* parm1 :sjis string                                             //~v40vI~
//* parm2 :sjis string len                                         //~v40vI~
//* parm3 :optional output dbcs id tbl                             //~v550R~
//* parm4 :optional output hankaku-katakana ctr                    //~v550R~
//* parm5 :option;sbcs is >0x80 only,dbcs errchk,keep tabid on dbcstbl//~v550R~
//* return:rc                                                      //~v40vI~
//*        dbcsfound,hankana found,dbcs err,ascii err              //~v550I~
//******************************************************           //~v40vI~
int usjischk(unsigned char *Psjis,int Plen,                        //~v550R~
				unsigned char *Pdbcs,int *Phankanactr,int Popt)    //~v550R~
{                                                                  //~v40vI~
  	unsigned int p1,p2;                                            //~v39NR~
#ifdef UNX                                                         //~v39NI~
#else                                                              //~v39NI~
  	unsigned int sjis;                                             //~v39NI~
#endif                                                             //~v39NI~
  	int sbcsasciisw,errsw=0;                                       //~v40vI~
  	unsigned char *pci,*pcd,*pce;                                  //~v40vI~
  	int noclearsw;                                                 //~v512I~
  	int errdbcschk,dbcserr;                                        //~v513I~
    int hankanactr=0;                                              //~v550I~
//*********************************                                //~v40vI~
    sbcsasciisw=(Popt & UDBCSCHK_ASCIISBCS);//sbcs is valid when <0x80//~v40vI~
    noclearsw=(Popt & UDBCSCHK_NOCLEAR);                           //~v512I~
    errdbcschk=(Popt & UDBCSCHK_ERRDBCSCHK);                       //~v513I~
  	for (pci=Psjis,pcd=Pdbcs,pce=pci+Plen;pci<pce;)                //~v40vI~
    {                                                              //~v40vI~
    	p1=*pci++;                                                 //~v40vI~
        dbcserr=0;                                                 //~v513I~
    	if (SJIS1(p1))                                             //~v40vI~
		{                                                          //~v40vI~
        	dbcserr=1;                                             //~v513I~
			if (pci<pce)                                           //~v40vI~
      			p2=*pci;                                           //~v40vR~
            else                                                   //~v40vI~
            	p2=0;                                              //~v40vI~
      		if (SJIS2(p2))                                         //~v40vI~
			{                                                      //~v40vI~
#ifdef UNX                                                         //~v39NI~
//              if (usjischkx208(p1,p2))//success                  //~v39NR~//~v6D0R~
                if (usjischkx208((int)p1,(int)p2))//success        //~v6D0I~
#else                                                              //~v39NI~
        		sjis=(p1<<8)+p2;                                   //~v40vI~
                if (SJISX208(sjis))//success                       //~v40vR~
#endif                                                             //~v39NI~
                {                                                  //~v40vI~
                  if (pcd)                                         //~v549I~
                  {                                                //~v549I~
                    *pcd++=UDBCSCHK_DBCS1ST;                       //~v40vI~
                    *pcd++=UDBCSCHK_DBCS2ND;                       //~v40vI~
                  }                                                //~v549I~
                    pci++;                                         //~v40vI~
                    errsw|=UDBCSCHK_RC_DBCSFOUND;                  //~v550I~
                    continue;                                      //~v40vI~
                }                                                  //~v40vI~
      		}                                                      //~v40vI~
            errsw|=UDBCSCHK_RC_DBCSERR;                            //~v550I~
        }                                                          //~v40vI~
//      if (HANKATA(p2))                                           //~v550I~//~v6h5R~
        if (HANKATA(p1))                                           //~v6h5I~
        {                                                          //~v550I~
            errsw|=UDBCSCHK_RC_HANKANAFOUND;                       //~v550I~
            hankanactr++;                                          //~v550I~
        }                                                          //~v550I~
        if (sbcsasciisw && p1>=0x80)                               //~v40vI~
        {                                                          //~v40vI~
          if (pcd)                                                 //~v549I~
            *pcd++=UDBCSCHK_HKDBCSERR;                             //~v40vI~
//          errsw=1;                                               //~v550R~
            errsw|=UDBCSCHK_RC_ASCIIERR;                           //~v550I~
        }                                                          //~v40vI~
        else                                                       //~v40vI~
          if (pcd)                                                 //~v549I~
          {                                                        //~v549I~
        if (dbcserr && errdbcschk)                                 //~v513I~
            *pcd++=UDBCSCHK_HKDBCSERR;                             //~v513I~
        else                                                       //~v513I~
        {                                                          //~v549I~
//        if (!(noclearsw && *pcd==UDBCSCHK_TAB))	//keep prev value//~v549R~
          if (!noclearsw                                           //~v549I~
          ||  *pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)      //~v549I~
//          *pcd++=UDBCSCHK_SBCS;                                  //~v549R~
            *pcd=UDBCSCHK_SBCS;                                    //~v549I~
            pcd++;                                                 //~v549I~
        }                                                          //~v549I~
          }                                                        //~v549I~
  	}//loop                                                        //~v40vI~
    if (Phankanactr)                                               //~v550R~
	    *Phankanactr=hankanactr;                                   //~v550R~
	return errsw;                                                  //~v40vR~
}//usjischk                                                        //~v40vI~
//*******************************************************          //~v6C1I~
//* cv euc 8fxxxx (JIS X 0213)                                     //~v6C1I~
//* windows and icu561 dose not support                            //~v6C1I~
//* iconv EUCJP-OPEN(EUCJP-WIN/EUCJP-MS) supports                  //~v6C1I~
//* xe support later                                               //~v6C1I~
//*******************************************************          //~v6C1I~
int ueuc2shift1SS3(int Popt,char *Peuc)                            //~v6C1I~
{                                                                  //~v6C1I~
	int sjis=0;                                                    //~v6C1I~
//*************************                                        //~v6C1I~
//*!! when supported SS3 chk caller may receive output dbcs contains DBCSPAD//~v6C1I~
//*!! for ex,utfcve2f have to chk DBCSPAD                          //~v6C1I~
    UTRACEP("%s:sjis=%04x,euc=%02x-%02x%02x\n",UTT,sjis,Peuc[0],Peuc[1],Peuc[2]);//~v6C1I~
	return sjis;                                                   //~v6C1R~
}                                                                  //~v6C1I~
//*******************************************************          //~v39xI~
//*ueuc2shift                                                      //~v39xI~
//* dbcs code conversion,jis to shift jis;regardless dbcs environment//~v39xI~
//* parm1 :euc string                                              //~v39xI~
//* parm2 :optional input dbcs id tbl                              //~v550I~
//* parm3 :sjis string len                                         //~v550R~
//* parm4 :optional out area addr                                  //~v550R~
//* parm5 :optional output dbcs id tbl                             //~v550R~
//* parm6 :optional output len                                     //~v550I~
//* parm7 :option to converst hankaku katakana to Euc zenkaku katakana//~v550R~
//*        (if 0 hankaku katakana is conversted to 0x8E+xx)        //~v39xI~
//* return:rc                                                      //~v550R~
//*        0x01:hankaku err,02:dbcs err,10:hankaku found,20:dbcs found//~v550R~
//******************************************************           //~v39xI~
int ueuc2shift(unsigned char *Peuc,unsigned char *Pdbcsi,int Plen, //~v550R~
				unsigned char *Psjis,unsigned char *Pdbcs,int *Poutlen,int Popt)//~v550R~
{                                                                  //~v39xI~
  	unsigned int p1,p2,sjis,jis;                                   //~v550R~
  	int hkcsw,errsw,olen=0,sbcsasciisw,hkerr;                      //~v39FR~
  	int noclearsw;                                                 //~v50YI~
  	unsigned char *pci,*pco,*pcd,*pce;                             //~v39xI~
  	unsigned char *pcdi;                                           //~v550R~
    int rc=0;                                                      //~v550I~
    int hkconlysw;  //kana conv only                               //~v550I~
  	int contlinesw;                                                //~v57dI~
//*********************************                                //~v39xI~
    hkcsw=(Popt & UDBCSCHK_EUCHKCONV);                             //~v39xI~
    hkconlysw=(Popt & UDBCSCHK_KANAONLY);                          //~v550I~
    hkerr=(Popt & UDBCSCHK_EUCHKERR);                              //~v39FI~
    sbcsasciisw=(Popt & UDBCSCHK_ASCIISBCS);//sbcs is valid when <0x80//~v39FR~
    noclearsw=(Popt & UDBCSCHK_NOCLEAR);                           //~v50YI~
    contlinesw=(Popt & UDBCSCHK_CONTLINE);                         //~v57dI~
    pcdi=Pdbcsi;                                                   //~v550I~
    UTRACED("euc",Peuc,Plen);                                      //~v6C1I~
    UTRACED("dbcsi",Pdbcsi,Plen);                                  //~v6C1I~
  	for (pci=Peuc,pco=Psjis,pcd=Pdbcs,pce=pci+Plen;pci<pce;)       //~v39xI~
    {                                                              //~v39xI~
	    UTRACEP("%s:euc=%02x,dbcsi=%p=%02x\n",UTT,*pci,pcdi,Pdbcsi?*pcdi:0);//~v6C1R~
    	errsw=1;	//ignore when continued                        //~v39DI~
    	p1=*pci++;                                                 //~v39xI~
        pcdi++;                                                    //~v550R~
    	if (ISEUC(p1) && pci<pce)                                  //~v39xR~
		{                                                          //~v39xI~
      		p2 = *pci++;                                           //~v39xI~
	        pcdi++;                                                //~v550R~
      		if (ISEUC(p2))                                         //~v39xI~
			{                                                      //~v39xI~
//            if (pco)  //conv req                                 //~v550R~
        		sjis=ujis2sjis(((p1-0x80)<<8)+(p2-0x80));          //~v39xR~
//            else      //chk req                                  //~v550R~
//  			sjis=(unsigned int)ujischkx208((int)(p1-0x80),(int)(p2-0x80));       	//JIS X208 chk,0:err//~v550R~
                if (sjis)                                          //~v39xI~
                {                                                  //~v39xI~
                    olen+=2;                                       //~v39DI~
                  if (hkconlysw)                                   //~v550I~
                  {                                                //~v550I~
                    	*pco++=(UCHAR)p1;                          //~v550R~
                    	*pco++=(UCHAR)p2;                          //~v550R~
                  }                                                //~v550I~
                  else                                             //~v550I~
                  {                                                //~v550I~
//              	if (pco)                                       //~v550R~
//                  {                                              //~v550R~
                    	*pco++=(UCHAR)(sjis>>8);                   //~v39DR~
                    	*pco++=(UCHAR)(sjis&255);                  //~v39DR~
//                  }                                              //~v550R~
                  }                                                //~v550I~
                    if (pcd)                                       //~v39xR~
                    {                                              //~v39xR~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v39xR~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v39xR~
                    }                                              //~v39xR~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v550I~
                    continue;                                      //~v39xI~
                }                                                  //~v39xI~
                rc|=UDBCSCHK_RC_DBCSERR;                           //~v550I~
      		}                                                      //~v39xI~
            pci--;  //back to before 2nd byte                      //~v39DI~
            pcdi--;  //back to before 2nd byte                     //~v550R~
    	}                                                          //~v39xI~
    	else                                                       //~v39xI~
        if (p1==SS2 && !hkerr && pci<pce)                          //~v39FR~
        {                                                          //~v39xR~
            p2 = *pci++;                                           //~v39xR~
            pcdi++;                                                //~v550R~
            if (HANKATA(p2))                                       //~v39xR~
            {                                                      //~v39xR~
                if (hkcsw)	//conv to zenkaku                      //~v39xR~
                {                                                  //~v39xR~
                    sjis=(unsigned int)uhan2zen(p2,&pci,pce,EUC);  //~v40vR~
                    olen+=2;                                       //~v39DI~
                  if (hkconlysw)                                   //~v550I~
                  {                                                //~v550I~
                	jis=usjis2jis(sjis);                           //~v550I~
                	*pco++=(UCHAR)((jis>>8)+0x80);                 //~v550I~
                	*pco++=(UCHAR)((jis&255)+0x80);                //~v550I~
                  }                                                //~v550I~
                  else                                             //~v550I~
                  {                                                //~v550I~
//                  if (pco)                                       //~v550R~
//                  {                                              //~v550R~
                    	*pco++=(UCHAR)(sjis>>8);                   //~v39DR~
                    	*pco++=(UCHAR)(sjis & 255);                //~v39DR~
//                  }                                              //~v550R~
                  }                                                //~v550I~
                    if (pcd)                                       //~v39xR~
                    {                                              //~v39xR~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v39xR~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v39xR~
                    }                                              //~v39xR~
                }//conv to xenkaku                                 //~v39xR~
                else                                               //~v39xI~
                {                                                  //~v39DI~
//                    olen+=2;                                     //~v548R~
//                    if (pco)                                     //~v548R~
//                    {                                            //~v548R~
//                        *pco++=(UCHAR)p1;                        //~v548R~
//                        *pco++=(UCHAR)p2;                        //~v548R~
//                    }                                            //~v548R~
//                    if (pcd)                                     //~v548R~
//                    {                                            //~v548R~
//                        *pcd++=UDBCSCHK_HK1;                     //~v548R~
//                        *pcd++=UDBCSCHK_HK2;                     //~v548R~
//                    }                                            //~v548R~
                    olen+=1;                                       //~v548I~
//                  if (pco)                                       //~v550R~
                        *pco++=(UCHAR)p2;                          //~v548I~
                    if (pcd)                                       //~v548I~
                    {                                              //~v549I~
//         			  if (!(noclearsw && *pcd==UDBCSCHK_TAB))	//keep prev value//~v549R~
//                      if (!noclearsw                             //~v550R~
//                      ||  *pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)//~v550R~
                        *pcd++=UDBCSCHK_SBCS;                      //~v550R~
                    }                                              //~v549I~
                }                                                  //~v39DI~
                rc|=UDBCSCHK_RC_HANKANAFOUND;                      //~v550I~
                continue;                                          //~v39DI~
            }//hankaku katakana                                    //~v39xR~
            rc|=UDBCSCHK_RC_HANKANAERR;                            //~v550I~
            pci--;  //back to before 2nd byte                      //~v39DI~
            pcdi--;  //back to before 2nd byte                     //~v550R~
        }                                                          //~v39xR~
    	else                                                       //~v6C1I~
        if (p1==SS3 && !(Popt & UDBCSCHK_SS3ERR) && (pci+1)<pce) //0x8fxxxx//~v6C1I~
        {                                                          //~v6C1I~
//      	sjis=ueuc2shift1SS3(0,pci-1); //8fxxxx                 //~v6C1R~//~v6D0R~
        	sjis=(unsigned)ueuc2shift1SS3(0,pci-1); //8fxxxx       //~v6D0I~
            if (sjis)                                              //~v6C1R~
            {                                                      //~v6C1R~
              	if (hkconlysw)                                     //~v6C1R~
              	{                                                  //~v6C1R~
                    *pco++=(UCHAR)p1;                              //~v6C1R~
                    *pco++=(UCHAR)*(pci+1);                        //~v6C1I~
                    *pco++=(UCHAR)*(pci+2);                        //~v6C1R~
    	            olen+=3;                                       //~v6C1I~
                    if (pcd)                                       //~v6C1I~
                    {                                              //~v6C1I~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v6C1I~
                        *pcd++=UDBCSCHK_DBCSPAD;                   //~v6C1I~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v6C1I~
                    }                                              //~v6C1I~
              	}                                                  //~v6C1R~
              	else                                               //~v6C1R~
              	{                                                  //~v6C1R~
                    *pco++=(UCHAR)(sjis>>8);                       //~v6C1R~
                    *pco++=(UCHAR)(sjis&255);                      //~v6C1R~
    	            olen+=2;                                       //~v6C1I~
                    if (pcd)                                       //~v6C1R~
                    {                                              //~v6C1R~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v6C1R~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v6C1R~
                    }                                              //~v6C1R~
              	}                                                  //~v6C1I~
                pci+=2;                                            //~v6C1I~
                pcdi+=2;                                           //~v6C1I~
                rc|=(UDBCSCHK_RC_DBCSFOUND|UDBCSCHK_RC_SS3);       //~v6C1R~
                continue;                                          //~v6C1R~
            }                                                      //~v6C1R~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v6C1R~
        }                                                          //~v6C1I~
        else                                                       //~v39DI~
        {                                                          //~v57dI~
    		if (pci==pce)	//last byte                            //~v57dI~
	    		if (contlinesw)                                    //~v57dI~
                    if (ISEUC(p1)                                  //~v57dR~
                    || (p1==SS2 && !hkerr))                        //~v57dI~
                    {                                              //~v57dI~
                        rc|=UDBCSCHK_RC_DBCSSPLIT;                 //~v57dR~
                        break;                                     //~v57dI~
                    }                                              //~v57dI~
          if (!sbcsasciisw || (p1<0x80))      //sbcs is valid when <0x80//~v39FR~
        	errsw=0;		//sbcs                                 //~v39DI~
        }                                                          //~v57dI~
        olen++;                                                    //~v39DI~
//      if (pco)                                                   //~v550R~
        	*pco++=(unsigned char)p1;                              //~v39DR~
        if (pcd)                                                   //~v39xR~
        {                                                          //~v582I~
          if (errsw)	                                           //~v39DI~
            *pcd++=UDBCSCHK_HKDBCSERR;                             //~v39DI~
          else                                                     //~v39DI~
          {                                                        //~v549I~
//         if (!noclearsw)	//keep prev value                      //~v511R~
//         if (!(noclearsw && *pcd==UDBCSCHK_TAB))	//keep prev value//~v549R~
//         if (!noclearsw                                          //~v550R~
//         ||  *pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)     //~v550R~
//          *pcd++=UDBCSCHK_SBCS;                                  //~v549R~
            if (noclearsw)                                         //~v550R~
            {                                                      //~v550I~
              if (Pdbcsi)                                          //~v550I~
				if (*(pcdi-1)==UDBCSCHK_DBCS1ST||*(pcdi-1)==UDBCSCHK_DBCS2ND)//~v550R~
		            *pcd=UDBCSCHK_SBCS;                            //~v550I~
                else                                               //~v550I~
		        	*pcd=*(pcdi-1);		//keep tabid               //~v550R~
              else                                                 //~v550I~
              	if (*pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)//~v550I~
		            *pcd=UDBCSCHK_SBCS;                            //~v550I~
            }                                                      //~v550I~
            else                                                   //~v550I~
            *pcd=UDBCSCHK_SBCS;                                    //~v549I~
            pcd++;                                                 //~v550R~
          }                                                        //~v549I~
        }//pcd                                                     //~v582I~
  	}//loop                                                        //~v39xI~
//  return olen;                                                   //~v550R~
	if (Poutlen)                                                   //~v550I~
	    *Poutlen=olen;                                             //~v550R~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6C1I~
    UTRACED("sjis",Psjis,olen);                                    //~v6C1I~
    UTRACED("dbcs",Pdbcs,olen);                                    //~v6C1I~
    return rc;                                                     //~v550I~
}//ueuc2shift                                                      //~v39xI~
//*******************************************************          //~v39DI~
//*ueucchk                                                         //~v39DI~
//* euc code chk                                                   //~v39DI~
//* parm1 :euc string                                              //~v39DI~
//* parm2 :euc string len                                          //~v550R~
//* parm3 :optional output dbcs id tbl                             //~v550R~
//* parm4 :hankaku kana ctr                                        //~v550R~
//* parm5 :option;hankana err,keep tabid,sbcs is valid when <x80 only//~v550R~
//* return:output sjis string len                                  //~v39DI~
//******************************************************           //~v39DI~
int ueucchk(unsigned char *Peuc,int Plen,                          //~v550R~
			unsigned char *Pdbcs,int *Phankanactr,int Popt)        //~v550R~
{                                                                  //~v39DI~
  	unsigned int p1,p2,sjis;                                       //~v550I~
  	int errsw,hankanactr=0,sbcsasciisw,hkerr;                      //~v550R~
  	int noclearsw;                                                 //~v550I~
  	unsigned char *pci,*pcd,*pce;                                  //~v550I~
    int rc=0;                                                      //~v550I~
    int hkdbcs;                                                    //~v5n8I~
//*********************************                                //~v550I~
    hkerr=(Popt & UDBCSCHK_EUCHKERR);  //set err when hankaku katakana//~v550I~
    hkdbcs=(Popt & UDBCSCHK_HKDBCS);   //set dbcs when hankaku katakana//~v5n8I~
    sbcsasciisw=(Popt & UDBCSCHK_ASCIISBCS);//sbcs is valid when <0x80//~v550I~
    noclearsw=(Popt & UDBCSCHK_NOCLEAR);                           //~v550I~
  	for (pci=Peuc,pcd=Pdbcs,pce=pci+Plen;pci<pce;)                 //~v550I~
    {                                                              //~v550I~
    	errsw=1;	//ignore when continued                        //~v550I~
    	p1=*pci++;                                                 //~v550I~
    	if (ISEUC(p1) && pci<pce)                                  //~v550I~
		{                                                          //~v550I~
      		p2 = *pci++;                                           //~v550I~
      		if (ISEUC(p2))                                         //~v550I~
			{                                                      //~v550I~
    			sjis=(unsigned int)ujischkx208((int)(p1-0x80),(int)(p2-0x80));       	//JIS X208 chk,0:err//~v550I~
                if (sjis)                                          //~v550I~
                {                                                  //~v550I~
                    if (pcd)                                       //~v550I~
                    {                                              //~v550I~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v550I~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v550I~
                    }                                              //~v550I~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v550I~
                    continue;                                      //~v550I~
                }                                                  //~v550I~
      		}                                                      //~v550I~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v550I~
            pci--;  //back to before 2nd byte                      //~v550I~
    	}                                                          //~v550I~
    	else                                                       //~v550I~
        if (p1==SS2 && !hkerr && pci<pce)                          //~v550I~
        {                                                          //~v550I~
            p2 = *pci++;                                           //~v550I~
            if (HANKATA(p2))                                       //~v550I~
            {                                                      //~v550I~
                hankanactr++;                                      //~v550I~
                if (pcd)                                           //~v550I~
                {                                                  //~v61fI~
                  if (hkdbcs)                                      //~v5n8I~
                  {                                                //~v5n8I~
                    *pcd++=UDBCSCHK_DBCS1ST;                       //~v5n8I~
                    *pcd++=UDBCSCHK_DBCS2ND;                       //~v5n8I~
                  }                                                //~v5n8I~
                  else                                             //~v5n8I~
                  {                                                //~v5n8I~
//                  *pcd++=UDBCSCHK_SBCS;                          //~v61fI~
                    *pcd++=UDBCSCHK_HK1; 	                       //~v61fI~
                    *pcd++=UDBCSCHK_HK2;                           //~v61fI~
                  }                                                //~v5n8I~
                }                                                  //~v61fI~
                rc|=UDBCSCHK_RC_HANKANAFOUND;                      //~v550I~
                continue;                                          //~v550I~
            }//hankaku katakana                                    //~v550I~
            rc|=UDBCSCHK_RC_HANKANAERR;                            //~v550I~
            pci--;  //back to before 2nd byte                      //~v550I~
        }                                                          //~v550I~
    	else                                                       //~v5ntI~
        if (p1==SS3 && !(Popt & UDBCSCHK_SS3ERR) && (pci+1)<pce) //0x8fxxxx//~v5ntI~
        {                                                          //~v5ntI~
    		if (ISEUC(*pci) && ISEUC(*(pci+1)))                    //~v5ntR~
            {                                                      //~v5ntI~
                if (pcd)                                           //~v5ntI~
                {                                                  //~v5ntI~
#ifdef UTF8SUPPH                                                   //~v62UR~
                    *pcd++=UDBCSCHK_DBCS1ST;                       //~v62UR~
                    *pcd++=UDBCSCHK_DBCSPAD;                       //~v62UR~
                    *pcd++=UDBCSCHK_DBCS2ND;   //SS3:"1d2" pattern //~v62UR~
#else                                                              //~v62UR~
                    *pcd++=UDBCSCHK_SBCS;                          //~v5ntI~
                    *pcd++=UDBCSCHK_DBCS1ST;                       //~v5ntI~
                    *pcd++=UDBCSCHK_DBCS2ND;                       //~v5ntI~
#endif                                                             //~v62UR~
                }                                                  //~v5ntI~
                rc|=(UDBCSCHK_RC_DBCSFOUND|UDBCSCHK_RC_SS3);       //~v5ntI~
                pci+=2;                                            //~v5ntI~
                continue;                                          //~v5ntI~
            }                                                      //~v5ntI~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v5ntI~
        }                                                          //~v5ntI~
        else                                                       //~v550I~
          	if (!sbcsasciisw || (p1<0x80))      //sbcs is valid when <0x80//~v550I~
        		errsw=0;		//sbcs                             //~v550I~
        if (pcd)                                                   //~v550I~
        {                                                          //~v550I~
          	if (errsw)                                             //~v550I~
            	*pcd=UDBCSCHK_HKDBCSERR;                           //~v550I~
          	else                                                   //~v550I~
            	if (noclearsw)                                     //~v550I~
                {                                                  //~v550I~
              		if (*pcd==UDBCSCHK_DBCS1ST||*pcd==UDBCSCHK_DBCS2ND)//~v550I~
		            	*pcd=UDBCSCHK_SBCS;                        //~v550I~
                }                                                  //~v550I~
            	else                                               //~v550I~
            		*pcd=UDBCSCHK_SBCS;                            //~v550I~
            pcd++;                                                 //~v550R~
    	}                                                          //~v550I~
  	}//loop                                                        //~v550I~
	if (Phankanactr)                                               //~v550I~
	    *Phankanactr=hankanactr;                                   //~v550I~
    return rc;                                                     //~v550I~
}//ueucchk                                                         //~v39DI~
//*******************************************************          //~v60eI~
//*ueucchk1 string                                                 //~v614R~
//* 1 euc code chk                                                 //~v60eI~
//* return:rc, dbcserr/hankana/ascii err for err,dbcsfound,hankana found for valid//~v60eI~
//******************************************************           //~v60eI~
int ueuc2shift1(int Popt,unsigned char *Peuc,int Plen,unsigned int *Ppsjis,unsigned char *Pdbcs)//~v614R~
{                                                                  //~v60eI~
  	unsigned int p1,p2,sjis=0;                                     //~v60eI~
  	unsigned char *pci,*pcd;                                       //~v60eR~
    int rc=0;                                                      //~v60eI~
//*********************************                                //~v60eI~
  	pci=Peuc,pcd=Pdbcs;                                            //~v60eI~
    if (pcd)                                                       //~v60eI~
        *pcd=UDBCSCHK_SBCS;                                        //~v60eI~
  	for (;;)                                                       //~v60eI~
    {                                                              //~v60eI~
    	p1=*pci++;                                                 //~v60eI~
    	if (ISEUC(p1) && Plen>=2)                                  //~v60eI~
		{                                                          //~v60eI~
      		p2 = *pci++;                                           //~v60eI~
//#ifdef UTF8SUPP                                                    //~v614I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jR~
            if (!(Popt & UDBCSCHK_ERRDBCSCHK)	//2nd byte validity chk//~v614I~
      		||  ISEUC(p2))                                         //~v614R~
#else                                                              //~v614I~
      		if (ISEUC(p2))                                         //~v614I~
#endif                                                             //~v614I~
			{                                                      //~v60eI~
        		sjis=ujis2sjis(((p1-0x80)<<8)+(p2-0x80));          //~v60eI~
                if (sjis)                                          //~v60eI~
                {                                                  //~v60eI~
                    if (pcd)                                       //~v60eI~
                    {                                              //~v60eI~
                        *pcd++=UDBCSCHK_DBCS1ST;                   //~v60eI~
                        *pcd++=UDBCSCHK_DBCS2ND;                   //~v60eI~
                    }                                              //~v60eI~
                    rc|=UDBCSCHK_RC_DBCSFOUND;                     //~v60eI~
                    break;                                         //~v60eI~
                }                                                  //~v60eI~
      		}                                                      //~v60eI~
            rc|=UDBCSCHK_RC_DBCSERR;                               //~v60eI~
            break;                                                 //~v60eI~
    	}                                                          //~v60eI~
    	else                                                       //~v60eI~
        if (p1==SS2 && Plen>=2)                                    //~v60eI~
        {                                                          //~v60eI~
            p2 = *pci++;                                           //~v60eI~
//#ifdef UTF8SUPP                                                    //~v614I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jR~
            if (!(Popt & UDBCSCHK_ERRDBCSCHK)	//2nd byte validity chk//~v614I~
            ||  HANKATA(p2))                                       //~v614R~
#else                                                              //~v614I~
            if (HANKATA(p2))                                       //~v614I~
#endif                                                             //~v614I~
            {                                                      //~v60eI~
                if (pcd)                                           //~v60eI~
                {                                                  //~v60eI~
                    *pcd++=UDBCSCHK_HK1;                           //~v60eI~
                    *pcd++=UDBCSCHK_HK2;                           //~v60eI~
                }                                                  //~v60eI~
                rc|=UDBCSCHK_RC_HANKANAFOUND;                      //~v60eI~
                sjis=p2;    //hankana                              //~v60eI~
                break;                                             //~v60eI~
            }//hankaku katakana                                    //~v60eI~
            rc|=UDBCSCHK_RC_HANKANAERR;                            //~v60eI~
            break;                                                 //~v60eI~
        }                                                          //~v60eI~
        else                                                       //~v60eI~
        if (p1>=0x80)      //sbcs is valid when <0x80              //~v60eI~
        {                                                          //~v60eI~
	        if (pcd)                                               //~v60eI~
            	*pcd=UDBCSCHK_HKDBCSERR;                           //~v60eI~
            rc|=UDBCSCHK_RC_ASCIIERR;                              //~v60eI~
    	}                                                          //~v60eI~
        break;                                                     //~v60eI~
  	}                                                              //~v60eI~
    if (Ppsjis)                                                    //~v60eI~
    {                                                              //~v60eI~
		if (sjis)                                                  //~v60eI~
		    *Ppsjis=sjis;                                          //~v60eI~
        else                                                       //~v60eI~
		    *Ppsjis=p1;                                            //~v60eI~
    }                                                              //~v60eI~
    return rc;                                                     //~v60eI~
}//ueuc2shift1s                                                    //~v614R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//*******************************************************          //~v614I~
//*ueucchk1 char                                                   //~v614R~
//* 1 euc code chk                                                 //~v614I~
//* return:rc, dbcserr/hankana/ascii err for err,dbcsfound,hankana found for valid//~v614I~
//******************************************************           //~v614I~
int ueuc2shift1c(int Popt,int Peuc,int* Ppsjis)                    //~v614R~
{                                                                  //~v614I~
  	unsigned int p1,p2,sjis;                                       //~v614R~
    int rc=0;                                                      //~v614I~
//*********************************                                //~v614I~
  	for (;;)                                                       //~v614I~
    {                                                              //~v614I~
        sjis=(UINT)Peuc;	//conv err case                        //~v5ntR~
    	p1=(UINT)Peuc>>8;                                          //~v5ntR~
    	if (ISEUC(p1))                                             //~v614R~
		{                                                          //~v614I~
      		p2 =(UINT)(Peuc&255);                                  //~v5ntR~
            if (!(Popt & UDBCSCHK_ERRDBCSCHK)	//2nd byte validity chk//~v614I~
      		||   ISEUC(p2))                                        //~v614I~
            {                                                      //~v614I~
                if (!(Popt & UDBCSCHK_RC0IFNOERR))                 //~v614I~
                	rc=UDBCSCHK_RC_DBCSFOUND;                      //~v614R~
            }                                                      //~v614I~
            else                                                   //~v614I~
	            rc=UDBCSCHK_RC_DBCSERR;                            //~v614I~
        	sjis=ujis2sjis(((p1-0x80)<<8)+(p2-0x80));              //~v614I~
            break;                                                 //~v614I~
    	}                                                          //~v614I~
        if (p1==SS2)                                               //~v614R~
        {                                                          //~v614I~
      		p2 =(UINT)(Peuc&255);                                  //~v5ntR~
            if (!(Popt & UDBCSCHK_ERRDBCSCHK)	//2nd byte validity chk//~v614I~
            ||  HANKATA(p2))                                       //~v614I~
            {                                                      //~v614I~
                if (!(Popt & UDBCSCHK_RC0IFNOERR))                 //~v614I~
	                rc|=UDBCSCHK_RC_HANKANAFOUND;                  //~v614R~
            }                                                      //~v614I~
            else                                                   //~v614I~
	            rc|=UDBCSCHK_RC_HANKANAERR;                        //~v614I~
            sjis=p2;    //hankana                                  //~v614I~
            break;                                                 //~v614I~
        }                                                          //~v614I~
        if (p1) //dbcs                                             //~v614I~
        {                                                          //~v614I~
	        rc|=UDBCSCHK_RC_DBCSERR;                               //~v614I~
            break;                                                 //~v614I~
        }                                                          //~v614I~
        if (!(Popt & UDBCSCHK_ASCIISBCS)	//2nd byte validity chk//~v614I~
        ||    p1<0x80)      //sbcs is valid when <0x80             //~v614I~
            rc=0;		//sbcs                                     //~v614I~
        else                                                       //~v614I~
            rc|=UDBCSCHK_RC_ASCIIERR;                              //~v614I~
        break;                                                     //~v614I~
  	}                                                              //~v614I~
    *Ppsjis=(int)sjis;                                             //~v5ntR~
    return rc;                                                     //~v614I~
}//ueuc2shift1c                                                    //~v614R~
//#endif                                                           //~v5n8R~
//*******************************************************          //~v39xI~
//*uhan2zen                                                        //~v40vR~
//* hankaku to zenkaku                                             //~v39xI~
//* parm1 :katakana code; should be 0xa1--0xdf                     //~v39xR~
//* parm2 :addr of next byte addr                                  //~v39xI~
//* parm3 :end of string addr                                      //~v39xI~
//* parm4 :source code type	 SJIS/EUC                              //~v39xR~
//* return:xenkaku sjis code                                       //~v39xI~
//******************************************************           //~v39xI~
//int uhan2zen(unsigned char Pkatakana,unsigned char **Ppnext,unsigned char *Pend,int Pscode)//~v50bR~
int uhan2zen(unsigned int Pkatakana,unsigned char **Ppnext,unsigned char *Pend,int Pscode)//~v50bI~
{                                                                  //~v39xI~
//ka--to||ha--ho||u                                                //~v39xI~
#define ISNIGORI(A) ((A >= 0xb6 && A <= 0xc4) || (A >= 0xca && A <= 0xce) || (A == 0xb3))//~v39xI~
//ha--ho                                                           //~v39xI~
#define ISMARU(A)   (A >= 0xca && A <= 0xce)                       //~v39xI~
                                                                   //~v39xI~
static int Sdbcskatakanatbl[][2] = {                               //~v39xR~
    {0x81,0x42},{0x81,0x75},{0x81,0x76},{0x81,0x41},{0x81,0x45},{0x83,0x92},//~v39xR~
  // 。maru      「 l-kakko  」r-kakko   、ten       ・chuten   ヲ wo//~v39xI~
    {0x83,0x40},{0x83,0x42},{0x83,0x44},{0x83,0x46},{0x83,0x48},{0x83,0x83},//~v39xI~
  // ァ xa       ィ xi       ゥ xu       ェ xe       ォ xo       ャ xya//~v39xI~
    {0x83,0x85},{0x83,0x87},{0x83,0x62},{0x81,0x5b},{0x83,0x41},{0x83,0x43},//~v39xI~
  // ュ xyu      ョ xyo      ッ xtu      ー bar      ア a        イ i//~v39xI~
    {0x83,0x45},{0x83,0x47},{0x83,0x49},{0x83,0x4a},{0x83,0x4c},{0x83,0x4e},//~v39xI~
  // ウ u        エ e        オ o        カ ka       キ ki       ク ku//~v39xI~
    {0x83,0x50},{0x83,0x52},{0x83,0x54},{0x83,0x56},{0x83,0x58},{0x83,0x5a},//~v39xI~
  // ケ ke       コ lo       サ sa       シ si       ス su       セ se//~v39xI~
    {0x83,0x5c},{0x83,0x5e},{0x83,0x60},{0x83,0x63},{0x83,0x65},{0x83,0x67},//~v39xI~
  // ソ so       タ ta       チ ti       ツ tu       テ te       ト to//~v39xI~
    {0x83,0x69},{0x83,0x6a},{0x83,0x6b},{0x83,0x6c},{0x83,0x6d},{0x83,0x6e},//~v39xI~
  // ナ na       ニ ni       ヌ nu       ネ ne       ノ no       ハ ha//~v39xI~
    {0x83,0x71},{0x83,0x74},{0x83,0x77},{0x83,0x7a},{0x83,0x7d},{0x83,0x7e},//~v39xI~
  // ヒ hi       フ fu       ヘ he       ホ ho       マ ma       ミ mi//~v39xI~
    {0x83,0x80},{0x83,0x81},{0x83,0x82},{0x83,0x84},{0x83,0x86},{0x83,0x88},//~v39xI~
  // ム mu       メ me       モ mo       ヤ ya       ユ yu       ヨ yo//~v39xI~
    {0x83,0x89},{0x83,0x8a},{0x83,0x8b},{0x83,0x8c},{0x83,0x8d},{0x83,0x8f},//~v39xI~
  // ラ ra       リ ri       ル ru       レ re       ロ ro       ワ wa//~v39xI~
    {0x83,0x93},{0x81,0x4a},{0x81,0x4b}                            //~v39xI~
  // ン nn       ゛ dakuten   ゜ handakuten                        //~v39xI~
    };                                                             //~v39xI~
  	int p1,p2,maru = 0,nigori = 0;                                 //~v39xR~
    unsigned char *pnext;                                          //~v39xI~
//*********************************                                //~v39xI~
	pnext=*Ppnext;                                                 //~v39xI~
  	if (Pscode==SJIS)	//source code is sjis                      //~v39xR~
	{                                                              //~v39xI~
    	if (pnext<Pend)                                            //~v39xR~
        {                                                          //~v39xI~
            p2=*pnext;                                             //~v39xR~
            if (p2==0xde && ISNIGORI(Pkatakana))    //allow dakuten//~v39xR~
            {                                                      //~v39xI~
            	nigori=1;                                          //~v39xR~
                pnext++;                                           //~v39xR~
            }                                                      //~v39xR~
            else                                                   //~v39xR~
            if (p2 == 0xdf && ISMARU(Pkatakana))                   //~v39xR~
            {                                                      //~v39xI~
            	maru=1;                                            //~v39xR~
                pnext++;                                           //~v39xR~
            }                                                      //~v39xR~
        }                                                          //~v39xI~
  	}                                                              //~v39xI~
  	else		//euc                                              //~v39xR~
	{                                                              //~v39xI~
    	if (pnext+1<Pend	//next is hankaku katakana             //~v39xR~
        &&  *pnext==SS2)                                           //~v39xI~
        {                                                          //~v39xI~
        	p2=*pnext;                                             //~v39xR~
            if (p2==0xde && ISNIGORI(Pkatakana))                   //~v39xR~
            {                                                      //~v39xI~
                nigori=1;                                          //~v39xR~
                pnext+=2;                                          //~v39xR~
            }                                                      //~v39xR~
            else                                                   //~v39xR~
            if (p2 == 0xdf && ISMARU(Pkatakana))                   //~v39xR~
            {                                                      //~v39xI~
                maru=1;                                            //~v39xR~
                pnext+=2;                                          //~v39xI~
            }                                                      //~v39xR~
        }//next is katakana                                        //~v39xI~
  	}                                                              //~v39xI~
    p1 = Sdbcskatakanatbl[Pkatakana - 0xa1][0];                    //~v39xR~
    p2 = Sdbcskatakanatbl[Pkatakana - 0xa1][1];                    //~v39xR~
	if (nigori)                                                    //~v39xI~
	{                                                              //~v39xI~
    	if ((p2 >= 0x4a && p2 <= 0x67) || (p2 >= 0x6e && p2 <= 0x7a))//ka-to,ha-ho//~v39xR~
      		p2++;                       //ga-do,ba-bo              //~v39xR~
    	else                                                       //~v39xI~
		if (p1 == 0x83 && p2 == 0x45)	//u                        //~v39xR~
      		p2 = 0x94;                  //vu                       //~v39xR~
  	}                                                              //~v39xI~
  	else                                                           //~v39xI~
	if (maru && p2 >= 0x6e && p2 <= 0x7a)//ha-ho                   //~v39xR~
    	p2 += 2;                         //pa-po                   //~v39xR~
    *Ppnext=pnext;                                                 //~v39xI~
    return (p1<<8)+p2;                                             //~v39xI~
}//uhan2zen                                                        //~v39xI~
#ifdef UNX                                                         //~v39PI~
//*****************************************************************//~v39PI~
//*return 1 if tty else 0(/dev/ttyp_)                              //~v39PI~
//*****************************************************************//~v39PI~
#ifndef XXE                                                        //~v6a0I~
int udbcschktty(void)                                              //~v39PI~
{                                                                  //~v39PI~
	char *pc;                                                      //~v39PI~
//  int termid;                                                    //~v582I~//~v6s1R~
//***************************                                      //~v39PI~
//  pc=ttyname(0);                                                 //~v6a0R~
    pc=uttyname(0);                                                //~v6a0I~
    UTRACEP("udbcscktty ttyname=%p\n",pc);                         //~v6a0I~
    if (!pc)                                                       //~v39PI~
    	return 0;                                                  //~v39PI~
    if (strstr(pc,"ttyp"))                                         //~v39PI~
    	return 0;                                                  //~v39PI~
    if (strstr(pc,"pts"))	//under X                              //~v582I~
    {                                                              //~v582I~
//  	termid=ukbdl_gettermid() & TERM_SIMID;                     //~v582I~//~v6s1R~
//      if (termid!=TERM_XTERMSIM)	//kterm or gterm(tl6 gterm dose not support DBCS but)//~v582I~//~v6s1R~
    		return 0;                                              //~v582I~
    }                                                              //~v582I~
    return 1;                                                      //~v39PI~
}//udbcschktty(void)                                               //~v39PI~
#endif  //XXE                                                      //~v6a0I~
//*****************************************                        //~v6btI~
//*searc hankana(8exx)                                             //~v6btI~
//*ret:pos of SS2,-1 if not found                                  //~v6btI~
//*****************************************                        //~v6btI~
int udbcschk_srchSS2(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)  //~v6btI~
{                                                                  //~v6btI~
	UCHAR *pc,*pc2,*pcd;                                           //~v6btI~
    int len,rc=-1,reslen;                                          //~v6btR~
//************************                                         //~v6btI~
	UTRACED("udbcschk_srchSS2 data=",Pdata,Plen);                  //~v6btI~
	UTRACED("udbcschk_srchSS2 dbcs=",Pdbcs,Plen);                  //~v6btI~
	for (pc=Pdata,pcd=Pdbcs,reslen=Plen;reslen>0;pc+=len,pcd+=len,reslen-=len)//~v6btR~
    {                                                              //~v6btI~
//  	pc2=memchr(pc,SS2,reslen);                                 //~v6btI~//~v6D0R~
    	pc2=memchr(pc,SS2,(size_t)reslen);                         //~v6D0I~
        if (!pc2)                                                  //~v6btI~
        	break;                                                 //~v6btI~
//      len=(ULONG)pc2-(ULONG)pc;                                  //~v6btI~//~v6D0R~
        len=(int)((ULONG)pc2-(ULONG)pc);                           //~v6D0I~
        if (*(pcd+len)==UDBCSCHK_DBCS1ST)                          //~v6btI~
        {                                                          //~v6btI~
//      	rc=(ULONG)pc-(ULONG)Pdata;                             //~v6btI~//~v6D0R~
        	rc=(int)((ULONG)pc-(ULONG)Pdata);                      //~v6D0I~
        	break;                                                 //~v6btI~
        }                                                          //~v6btI~
        len++;                                                     //~v6btI~
    }                                                              //~v6btI~
	UTRACEP("udbcschk_srchSS2 rc=%d\n",rc);                        //~v6btI~
    return rc;                                                     //~v6btI~
}//udbcschk_srchSS2                                                //~v6btI~
#endif                                                             //~v39PI~
