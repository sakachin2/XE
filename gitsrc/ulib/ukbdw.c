//CID://+v6VuR~:             update#=  167                         //~v6VuR~
//*************************************************************
//*ukbdpeek/ukbdcharin/ukbdsetrate/ukbdsetstate                 //~5104R~
//*************************************************************
//v6Vu:180622 UTRACE;support force option off                      //~v6VuI~
//v6U1:180317 ReadConsoleInputW loop by continued eventrecord eventType=x10(FOCUS_EVENT),try flush//~v6U1I~
//v6L5:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//~v6L5I~
//v6Ez:160826 S+C+F5 shows S+F5, it will be better to be C+F5 with shift modifyer//~v6EzI~
//v6By:160212 (W32)compiler warning at w7                          //~v6ByI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Be:160207 utf8 char input emulation                            //~v6BeI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning(C4057)                           //~v6hdI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v65d:100311 RAW unicode input(ucs2local fail but accept it when env is utf8)//~v65dI~
//v62C:091003_(WIN:BUG) wide API but not through IME case(ISO8859 etc);generate utf8 string//~v62CI~
//v62r:090922!(WIN)NOUTF8 support for WIDEAPI test (/Yw /Nm)       //~v62rI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5n8R~//~v5ncR~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v5kp:070613 (BUG)repeated rctl is effective only once(need keyup)//~v5kpI~
//v5ir:060811*(WIN)Alt+Shift+n for graph key(use shift to 2nd linech string)//~v5irI~
//v5ip:060801 (BUG)C+10key,C+"-",c+"+" is ignored                  //~v5ipI~
//v5im:060722*101 kbd support(for line drawing char '^' is '=' on 101 kbd)//~v5imI~
//v5bi:040208 (WXE)distinguish R-CONTROL for WXE                   //~v5biI~
//v570:020824 wxe support                                          //~v570I~
//v299:000220 (Win:BUG)Enter cause invalid scancode:               //~v299I~
//            char:scan is gotten by 8000 reord and 8000 record is missing//~v299I~
//            scan code.So scan code is gotten by prev entry.      //~v299I~
//            But prev record is sometime keyup of other key.      //~v299I~
//            It cause 0d/xx for Enter key and beep.               //~v299I~
//v298:000205 add option of w95 kbd trace by UTRACE                //~v298R~
//v253:990626 (Win):same as V253 for getconsolemode(return rc=-1 when redirected.)//~v253I~
//v241:990510 no err msg fo win stdout redirect err                //~v241I~
//v204:981201 getconsolemode faile when stdout redirected(lasterr=6)//~v204I~
//            uerrexit cause loop,so msg by printf                 //~v204I~
//v187:980802 Windows98 abend for kbdinit                          //~v187I~
//            logic from Getconsolemode is no more valid           //~v187I~
//            search vxd service rtn                               //~v187I~
//v186:980724 accept force NT mode req                             //~v186I~
//v185:980724 try NT mode when english mode for kbd input          //~v185I~
//v184:980711 (BUG) abend repoted;4.00.950b kbdwinit               //~v184I~
//            try GetNumberOfConsoleInputEvent to get index value  //~v184I~
//            (alternative of ecx+158)                             //~v184I~
//v164:980410 (BUG)NT return 0f09 for shift+tab(it is same as tab) //~v164I~
//v146:980116 (W32:BUG)under Win95 ctl+C=x03 cannot be input       //~v146I~
//v141:980115 (W32)uget/usetconsolemode for input/output each      //~v141I~
//v139:980110 (W32)WINNT support                                   //~v139I~
//                 key conv tbl change from getch to DOS manual    //~v139I~
//                 alt+tab(scan=0f):0f00-->a500                    //~v139R~
//                 alt+](scan=2b):0000-->2b00                      //~v139R~
//                 shift+0=0x0b29')'-->0x0b00                      //~v139I~
//                 ctrl+@=-0x1a1b(esc)-->0x0000                    //~v139I~
//                 use scan=29 for hankaku                         //~v139I~
//                 add hiragana/henkan/muhenkan                    //~v139I~
//                 add scan=7d(\)                                  //~v139I~
//                 add scan=73(back slash)                         //~v139I~
//v137:980110 (W32)split ukbdw.c from ubd ukbd.c                   //~v137I~
//v055:970118:when int 16 ah=13,al=00 or 01 is valid               //~v055I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -REGS contain flags,so no need of ukintf(asm) routine//~v053I~
//v044:961106:split uvio.c to uvio2.c(screen i/o)                  //~v044I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//* 950110 shift report(RCTL key support)                       //~5110R~
//* 950104 ukbdsetstate                                         //~5110I~
//************************************************************* //~5104I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
//*******************************************************
		#include <windows.h>                                       //~v022I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <udos.h>                                                  //~v139I~
#include <ukbd.h>                                                  //~v137R~
#include <ukbdw.h>                                                 //~v137I~
#include <uvio.h>                                                  //~v022I~
#include <uvio2.h>                                                 //~v044I~
#include <udbcschk.h>                                              //~v034I~
#include <uwinsp.h>                                                //~v187R~
#include <utrace.h>                                                //~v139I~
#include <ucvebc.h>                                                //~v5n8I~
#include <ucvext.h>                                                //~v5n8I~
#include <utf.h>                                                   //~v6BeI~
#ifdef UTF8SUPPH                                                   //~v5n8I~
	#include <ucvucs.h>                                            //~v5n8I~
#endif                                                             //~v5n8I~
                                                                   //~v570I~
#ifdef WXE                                                         //~v570I~
	#include "wxexei.h"                                            //~v570I~
#endif                                                             //~v570I~
//*******************************************************
        #define READCTR         2                                  //~v034R~
        #define VRECID          0x8000                             //~v034R~
        #define SCAN_LSHIFT     0x2a                               //~v034I~
        #define SCAN_RSHIFT     0x36                               //~v034I~
#define SCAN_CTL_C      0x2e                                       //~v146I~
#define CHAR_CTL_C      0x03                                       //~v146I~
#ifdef WXE                                                         //~v570I~
    	static int    Sinitsw=0;                                   //~v570I~
#else                                                              //~v570I~
    	static HANDLE Shstdin;                                     //~v034R~
#endif                                                             //~v570I~
    	static INPUT_RECORD **Sirtop,**Sirread,**Sirwrite,**Sirlast;//~v034R~
                                                                   //~v034R~
    	static UCHAR Svkeytbl[256];                                //~v034R~
            #define	VKID_EXTSHIFT   1                              //~v034R~
            #define VKID_SHIFT		2                              //~v034R~
            #define VKID_IGNORE     3                              //~v034R~
    	static int Stracesw;                                       //~v034R~
    	static int Stracesw2;                                      //~v298I~
                                                                   //~v034R~
static KBDINFO Skbdinfo;	//save for ukbdcharin                  //~v139M~
static int Sntsw;               //windows NT                       //~v146R~
static int Sshiftreprtsw;               //windows NT               //~v146I~
static int Sforcentsw;                                             //~v186I~
//***** extended key conversion tbl  ********************          //~v139I~
static UCHAR Sextkeytbl1[]={0x1c,       //enter                    //~v139M~
                            0x35,                                  //~v139M~
                            0x47,       //home                     //~v139M~
                            0x48,       //up                       //~v139M~
                            0x49,       //pgup                     //~v139M~
                            0x4b,       //left                     //~v139M~
                            0x4d,       //right                    //~v139M~
                            0x4f,       //end                      //~v139M~
                            0x50,       //down                     //~v139M~
                            0x51,       //pgdn                     //~v139M~
                            0x52,       //ins                      //~v139M~
                            0x53};      //del                      //~v139M~
//***** conversion tbl used when ReadConsole returned char==0 ***  //~v139I~
//*****                     or alt key used                   ***  //~v139I~
static USHORT Sextkeytbl2[][4]=                                    //~v139M~
	{//  normal,shift ,ctl   ,alt                                  //~v139M~
        {0x000d,0x000d,0x000a,0xa600},  //0x1c,       //enter      //~v139M~
        {0x002f,0x003f,0x9500,0xa400},  //0x35,                    //~v139M~
        {0x47e0,0x47e0,0x77e0,0x9700},  //0x47,       //home       //~v139M~
        {0x48e0,0x48e0,0x8de0,0x9800},  //0x48,       //up         //~v139M~
        {0x49e0,0x49e0,0x84e0,0x9900},  //0x49,       //pgup       //~v139M~
        {0x4be0,0x4be0,0x73e0,0x9b00},  //0x4b,       //left       //~v139M~
        {0x4de0,0x4de0,0x74e0,0x9d00},  //0x4d,       //right      //~v139M~
        {0x4fe0,0x4fe0,0x75e0,0x9f00},  //0x4f,       //end        //~v139M~
        {0x50e0,0x50e0,0x91e0,0xa000},  //0x50,       //down       //~v139M~
        {0x51e0,0x51e0,0x76e0,0xa100},  //0x51,       //pgdn       //~v139M~
        {0x52e0,0x52e0,0x92e0,0xa200},  //0x52,       //ins        //~v139M~
        {0x53e0,0x53e0,0x93e0,0xa300}   //0x53}       //del        //~v139M~
    };                                                             //~v139M~
static USHORT Sscanconvtbl[][4]=                                   //~v139M~
	{//  normal,shift ,ctl   ,alt       scan code                  //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x00,  dummy 106 kbd     //~v139M~
                                                                   //~v139M~
        {0x001b,0x001b,0x001b,0x0100},  //0x01,  esc   norml,shift,ctl  ,alt//~v139M~
//1st line                                                         //~v139M~
        {0x0031,0x0021,0x0000,0x7800},  //0x02,  1,!               //~v139M~
        {0x0032,0x0040,0x0300,0x7900},  //0x03,  2,@         22(") //~v139M~
        {0x0033,0x0023,0x0000,0x7a00},  //0x04,  3,#               //~v139M~
        {0x0034,0x0024,0x0000,0x7b00},  //0x05,  4,$               //~v139M~
        {0x0035,0x0025,0x0000,0x7c00},  //0x06,  5,%               //~v139M~
        {0x0036,0x005e,0x001e,0x7d00},  //0x07,  6,^         26(&) //~v139M~
        {0x0037,0x0026,0x0000,0x7e00},  //0x08,  7,&         27(') //~v139M~
        {0x0038,0x002a,0x0000,0x7f00},  //0x09,  8,*         28(() //~v139M~
        {0x0039,0x0028,0x0000,0x8000},  //0x0a,  9,(         29()) //~v139M~
//      {0x0030,0x0029,0x0000,0x8100},  //0x0b,  0,)         0b00  //~v139R~
        {0x0030,0x0b00,0x0000,0x8100},  //0x0b,  0,0x0b00    0b00  //~v139I~
        {0x002d,0x005f,0x001f,0x8200},  //0x0c,  -,_         3d(=) //~v139M~
        {0x003d,0x002b,0x0000,0x8300},  //0x0d,  =,_   5e(^),7e(=) //~v139M~
        {0x0008,0x0008,0x007f,0x0e00},  //0x0e,  bs                //~v139M~
//2nd line                                                         //~v139M~
        {0x0009,0x0f00,0x9400,0x0f00},  //0x0f,  tab        ,     ,     ,0xa500//~v139M~
        {0x0071,0x0051,0x0011,0x1000},  //0x10,  q,Q               //~v139M~
        {0x0077,0x0057,0x0017,0x1100},  //0x11,  w,W               //~v139M~
        {0x0065,0x0045,0x0005,0x1200},  //0x12,  e,E               //~v139M~
        {0x0072,0x0052,0x0012,0x1300},  //0x13,  r,R               //~v139M~
        {0x0074,0x0054,0x0014,0x1400},  //0x14,  t,T               //~v139M~
        {0x0079,0x0059,0x0019,0x1500},  //0x15,  y,Y               //~v139M~
        {0x0075,0x0055,0x0015,0x1600},  //0x16,  u,U               //~v139M~
        {0x0069,0x0049,0x0009,0x1700},  //0x17,  i,I               //~v139M~
        {0x006f,0x004f,0x000f,0x1800},  //0x18,  o,O               //~v139M~
        {0x0070,0x0050,0x0010,0x1900},  //0x19,  p,P               //~v139M~
//      {0x005b,0x007b,0x001b,0x1a00},  //0x1a,  [,{   40(@),60(`),0x0000//~v139R~
        {0x005b,0x007b,0x0000,0x1a00},  //0x1a,  [,0x00 40(@),60(`),0x0000//~v139I~
        {0x005d,0x007d,0x001d,0x1b00},  //0x1b,  ],}   5b([),7b({),0x001b//~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x000a,0x1c00},  //0x1c,                    //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x1d,                    //~v139M~
//3rd line                                                         //~v139M~
        {0x0061,0x0041,0x0001,0x1e00},  //0x1e,  a,A               //~v139M~
        {0x0073,0x0053,0x0013,0x1f00},  //0x1f,  s,S               //~v139M~
        {0x0064,0x0044,0x0004,0x2000},  //0x20,  d,D               //~v139M~
        {0x0066,0x0046,0x0006,0x2100},  //0x21,  f,F               //~v139M~
        {0x0067,0x0047,0x0007,0x2200},  //0x22,  g,G               //~v139M~
        {0x0068,0x0048,0x0008,0x2300},  //0x23,  h,H               //~v139M~
        {0x006a,0x004a,0x000a,0x2400},  //0x24,  j,J               //~v139M~
        {0x006b,0x004b,0x000b,0x2500},  //0x25,  k,K               //~v139M~
        {0x006c,0x004c,0x000c,0x2600},  //0x26,  l,L               //~v139M~
        {0x003b,0x003a,0x0000,0x2700},  //0x27,  ;,:        ,2b(+) //~v139M~
        {0x0027,0x0022,0x0000,0x2800},  //0x28,  ',"   3a(:),2a(*) //~v139M~
//      {0x0060,0x007e,0x0000,0x2900},  //0x29,  `,~               //~v139R~
        {0xaf00,0xb000,0xb100,0xb200},  //0x29,  hankaku           //~v139I~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x2a,                    //~v139M~
                                                                   //~v139M~
//      {0x005c,0x007c,0x001c,0x0000},  //0x2b,  \,|   5d(]),7d(}),0x001d//~v139R~
        {0x005c,0x007c,0x001c,0x2b00},  //0x2b,  \,|   5d(]),7d(}),0x001d//~v139I~
//4th line                                                         //~v139M~
        {0x007a,0x005a,0x001a,0x2c00},  //0x2c,  z,Z               //~v139M~
        {0x0078,0x0058,0x0018,0x2d00},  //0x2d,  x,X               //~v139M~
        {0x0063,0x0043,0x0003,0x2e00},  //0x2e,  c,C               //~v139M~
        {0x0076,0x0056,0x0016,0x2f00},  //0x2f,  v,V               //~v139M~
        {0x0062,0x0042,0x0002,0x3000},  //0x30,  b,B               //~v139M~
        {0x006e,0x004e,0x000e,0x3100},  //0x31,  n,N               //~v139M~
        {0x006d,0x004d,0x000d,0x3200},  //0x32,  m,M               //~v139M~
        {0x002c,0x003c,0x0000,0x3300},  //0x33,  ,,<               //~v139M~
        {0x002e,0x003e,0x0000,0x3400},  //0x34,  .,>               //~v139M~
        {0x002f,0x003f,0x0000,0x3500},  //0x35,  /,?               //~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x36,                    //~v139M~
                                                                   //~v139M~
        {0x002a,0x0000,0x0072,0x0000},  //0x37,  *                 //~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x38,                    //~v139M~
//5th line                                                         //~v139M~
        {0x0020,0x0020,0x0020,0x0020},  //0x39,  space             //~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x3a,                    //~v139M~
//pfkey                                                            //~v139M~
        {0x3b00,0x5400,0x5e00,0x6800},  //0x3b,  f1                //~v139M~
        {0x3c00,0x5500,0x5f00,0x6900},  //0x3c,  f2                //~v139M~
        {0x3d00,0x5600,0x6000,0x6a00},  //0x3d,  f3                //~v139M~
        {0x3e00,0x5700,0x6100,0x6b00},  //0x3e,  f4                //~v139M~
        {0x3f00,0x5800,0x6200,0x6c00},  //0x3f,  f5                //~v139M~
        {0x4000,0x5900,0x6300,0x6d00},  //0x40,  f6                //~v139M~
        {0x4100,0x5a00,0x6400,0x6e00},  //0x41,  f7                //~v139M~
        {0x4200,0x5b00,0x6500,0x6f00},  //0x42,  f8                //~v139M~
        {0x4300,0x5c00,0x6600,0x7000},  //0x43,  f9                //~v139M~
        {0x4400,0x5d00,0x6700,0x7100},  //0x44,  f10               //~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x45,                    //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x46,                    //~v139M~
//ext key                                                          //~v139M~
        {0x4700,0x0037,0x7700,0x0000},  //0x47,  home              //~v139M~
        {0x4800,0x0038,0x8d00,0x0000},  //0x48,  up                //~v139M~
        {0x4900,0x0039,0x8400,0x0000},  //0x49,  pgup              //~v139M~
//      {0x0000,0x002d,0x0000,0x0000},  //0x4a,                    //~v5ipR~
        {0x4a00,0x002d,0x8e00,0x4a00},  //0x4a,  10key"-"          //~v5ipI~
        {0x4b00,0x0034,0x7300,0x0000},  //0x4b,  left              //~v139M~
//      {0x0000,0x0035,0x0000,0x0000},  //0x4c,                    //~v5ipR~
        {0x4c00,0x0035,0x8f00,0x0000},  //0x4c,  Center(10key-5)   //~v5ipR~
        {0x4d00,0x0036,0x7400,0x0000},  //0x4d,  right             //~v139M~
//      {0x0000,0x002b,0x0000,0x0000},  //0x4e,                    //~v5ipR~
        {0x4e00,0x002b,0x9000,0x4e00},  //0x4e,                    //~v5ipI~
        {0x4f00,0x0031,0x7500,0x0000},  //0x4f,  end               //~v139M~
        {0x5000,0x0032,0x9100,0x0000},  //0x50,  down              //~v139M~
        {0x5100,0x0033,0x7600,0x0000},  //0x51,  pgdn              //~v139M~
        {0x5200,0x0030,0x9200,0x0000},  //0x52,  ins               //~v139M~
        {0x5300,0x002e,0x9300,0x0000},  //0x53,  del               //~v139M~
                                                                   //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x54,                    //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x55,                    //~v139M~
        {0x0000,0x0000,0x0000,0x0000},  //0x56,                    //~v139M~
//pfkey                                                            //~v139M~
        {0x85e0,0x87e0,0x89e0,0x8be0},  //0x57,  f11               //~v139M~
        {0x86e0,0x88e0,0x8ae0,0x8ce0},  //0x58,  f12               //~v139R~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x59,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5a,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5b,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5c,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5d,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5e,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x5f,                    //~v139I~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x60,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x61,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x62,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x63,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x64,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x65,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x66,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x67,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x68,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x69,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6a,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6b,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6c,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6d,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6e,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x6f,                    //~v139I~
                                                                   //~v139I~
        {0xb600,0xb700,0xb800,0xb900},  //0x70, hiragana           //~v139I~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x71,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x72,                    //~v139I~
                                                                   //~v139I~
        {0x005c,0x005f,0x001c,0x0000},  //0x73, back slash         //~v139R~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x74,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x75,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x76,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x77,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x78,                    //~v139I~
                                                                   //~v139I~
        {0xa700,0xa800,0xa900,0xaa00},  //0x79,  henkan            //~v139I~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x7a,                    //~v139I~
                                                                   //~v139I~
        {0xab00,0xac00,0xad00,0xae00},  //0x7b,  muhenkan          //~v139I~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x7c,                    //~v139I~
                                                                   //~v139I~
        {0x005c,0x007c,0x001c,0x0000},  //0x7d,  \                 //~v139R~
                                                                   //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x7e,                    //~v139I~
        {0x0000,0x0000,0x0000,0x0000},  //0x7f,                    //~v139I~
    };                                                             //~v139M~
#define VKALTTBSZ 1                                                //~v5imI~
static UCHAR Svkeyalttbl[VKALTTBSZ*3]={	//Alt[+Shift][+Ctl]        //~v5imI~
				 '=',0x83,0x00          //on 106kbd S+A+'-'(106kbd) is A+'='//~v5imI~
				};                                                 //~v5imR~
	ULONG Scodepage=0;                                             //~v5n8R~
	int   Swcstat=0;                                               //~v5n8R~
//**************************************************               //~v139I~
        int ukbd_w95keyinfo(PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo,//~v034R~
        			PINPUT_RECORD Pp8000rec,int Pshift);           //~v034R~
		USHORT ukbd_w95shiftconv(PINPUT_RECORD Ppinprec);          //~v034I~
		PINPUT_RECORD ukbd_w95getnext(PINPUT_RECORD Ppinprec);     //~v034I~
//      void ureadconsole(char *Parea,int Pilen,int *Polen);       //~v65dR~
        void ureadconsoleinput(PINPUT_RECORD Pinprec,int Pilen,int *Polen);//~v034R~
        void ukbd_w95trace(char *comm,void *Ppinprec);             //~v139R~
int ukbd_wntread(PKBDKEYINFO Ppkinf,int Pwait);                    //~v139I~
int ugetinputeventno(void);                                        //~v139I~
void upeekconsoleinput(PINPUT_RECORD Pinprec,int Preqctr,int *Poutctr);//~v139I~
int ukbd_wntkeyinfo(PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo,int Pshift);//~v139I~
int ukbd_wntkeyinfo_u2m(int Popt,PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo);//~v5n8R~
#define UKBD_MBSCHK        0x01       //read pending mb string     //~v5n8I~
//**************************************************               //~v034M~
//*ukbd_w95init                                                    //~v034R~
//*init for win console appl                                       //~v034M~
//*parm1:none                                                      //~v034M~
//*rc   :none                                                      //~v034M~
//**************************************************               //~v034M~
void ukbd_w95init(void)                                            //~v034R~
{                                                                  //~v034M~
#ifndef WXE                                                        //~v570I~
#ifndef MGW32                                                      //~v5ncI~
#ifndef ULIB64X                                                    //~v6hhI~
//  UINT inputmode;                                                //~v034M~//~v6hdR~
    DWORD inputmode;                                               //~v6hdI~
    char *pc;                                                      //~v034M~
    char *peventh=NULL;		//event hdr ptr                            //~v187I~//~v6h7R~
	int 	bool;                                                  //~v034M~
	UINT 	offs,index;                                            //~v034M~
	int 	oecx,oedx;                                             //~v034M~
#endif //!ULIB64X                                                  //~v6hhI~
#endif //!MINGW                                                    //~v5ncI~
#endif //!WXE                                                      //~v570I~
//***************************************                          //~v034M~
#ifdef WXE                                                         //~v570I~
	Sinitsw=1;                                                     //~v570I~
    Sntsw=1;         //always use ntread rtn                       //~v570I~
#else                                                              //~v570I~
                                                                   //~v570I~
  if (Sforcentsw)	                                               //~v186I~
    Sntsw=1;                                                       //~v186I~
  else                                                             //~v186I~
  {                                                                //~v186I~
    Sntsw=udosiswinnt();            //Windows NT?                  //~v139I~
    if (!Sntsw)                                                    //~v185I~
        if (!udbcschkcp())                                         //~v185I~
        	Sntsw=1;                                               //~v185I~
  }	                                                               //~v186I~
#endif  //!WXE                                                     //~v570I~
//*shift report key                                                //~v034M~
	Svkeytbl[VK_SHIFT]  =					//0x10                 //~v034R~
							VKID_EXTSHIFT;                         //~v034M~
	Svkeytbl[VK_CONTROL]=                   //0x11                 //~v034R~
	Svkeytbl[VK_MENU   ]=			//alt   //0x12                 //~v034R~
	Svkeytbl[VK_CAPITAL]=                   //0x14                 //~v034I~
	Svkeytbl[VK_NUMLOCK]=                   //0x90                 //~v034R~
	Svkeytbl[VK_SCROLL ]=                   //0x91                 //~v034R~
							VKID_SHIFT;                            //~v034M~
//*ignore virtual key                                              //~v034M~
	Svkeytbl[0xAF]      =			//hankaku/zenkaku              //~v034M~
	Svkeytbl[0xB0]      =			//S+hankaku/zenkaku            //~v034M~
	Svkeytbl[0xB2]      =			//A+hankaku/zenkaku            //~v034M~
	Svkeytbl[0xB1]      =			//C+hankaku/zenkaku            //~v034M~
	Svkeytbl[0xB3]      =			//eisu                         //~v034M~
	Svkeytbl[0xB5]      =			//A+eisu                       //~v034M~
	Svkeytbl[0xB4]      =			//C+eisu                       //~v034M~
	Svkeytbl[0xAB]      =			//muhenkan                     //~v034M~
	Svkeytbl[0xAC]      =			//S+muhenkan                   //~v034M~
	Svkeytbl[0xAE]      =			//A+muhenkan                   //~v034M~
	Svkeytbl[0xAD]      =			//C+muhenkan                   //~v034M~
	Svkeytbl[0xA7]      =			//henkan                       //~v034M~
	Svkeytbl[0xA8]      =			//S+henkan                     //~v034M~
	Svkeytbl[0xAA]      =			//A+henkan                     //~v034M~
	Svkeytbl[0xA9]      =			//C+henkan                     //~v034M~
	Svkeytbl[0xB6]      =			//hiragana                     //~v034M~
	Svkeytbl[0xB7]      =			//S+hiragana                   //~v034M~
	Svkeytbl[0xB9]      =			//A+hiragana                   //~v034M~
	Svkeytbl[0xB8]      =			//C+hiragana                   //~v034M~
							VKID_IGNORE;                           //~v034M~
#ifdef WXE                                                         //~v570I~
#else                                                              //~v570I~
#ifndef MGW32                                                      //~v5ncI~
//get handle                                                       //~v034M~
	Shstdin=ugetstdhandle(STD_INPUT_HANDLE);                       //~v034M~
#ifndef ULIB64X                                                    //~v6hhM~
  	if (!Sntsw)                                                    //~v187I~
    	if (udosiswin98())      //win98                            //~v187R~
			if (uwinsp_getcurrenteventhdr(Shstdin,&peventh))//err  //~v187I~
        		Sntsw=1;			//force nt mode                //~v187I~
  if (!Sntsw)                                                      //~v139I~
  {                                                                //~v139I~
   if (!udosiswin98())      //win95                                //~v187R~
   {                                                               //~v187I~
//********windows 95 init ****                                     //~v139I~
//search key event table                                           //~v034M~
//(1)file handle is key of file table                              //~v034M~
//   ReadConsoleInput has logic to get file table addr             //~v034M~
//   But SetConsoleModde return file table addr in ECX,use it.     //~v034M~
//(2)file table has index to console context table                 //~v034M~
//   file table +0x158 is the index.                               //~v034M~
//(3)console context table point event table header                //~v034M~
//   context table+8 point event table header.                     //~v034M~
//   VxD 0038xxxx has logic to get context table,it refer top addr.//~v034M~
//   The relocatable data is get from code segment.                //~v034M~
//   The logic to get VxD routine addr is on IDT(interruption descriptor//~v034M~
//   table) for int 0x30.                                          //~v034M~
//   But GetConsoleMode return routine addr of VxD for 0038000f.   //~v034M~
//     That routin call subroutin at entry+3(call near +56D:E86D050000)//~v034M~
//     The subroutin use context table pointer at entry+9          //~v034M~
//	   (mov eax,[c032444c+eax*4]:8B04854C4432C0)                   //~v034M~
//(4)event table header maintain event entry top/last/read/write ptr//~v034M~
//   event table header +04:entry size                             //~v034M~
//                      +08:top entry                              //~v034M~
//                      +0c:next read entry                        //~v034M~
//                      +10:next write entry                       //~v034M~
//                      +14:end addr                               //~v034M~
//                      +1C:console mode                           //~v034M~
	bool=GetConsoleMode(Shstdin,&inputmode);                       //~v034M~
    __asm {                                                        //~v034M~
            mov   oedx,edx          //0038000f addr                //~v034M~
    }                                                              //~v034M~
	if (bool==FALSE)                                               //~v034M~
		uerrapi1x("GetConsoleMode","STD_INPUT",GetLastError());    //~v034M~
    pc=(char*)oedx;                 //0038000f entry(reg on tbl)   //~v034M~
//  printf("0038000f entry 1=%08x\n",pc);                          //~v034M~
    offs=*(ULONG*)(void*)(pc+4);	//c0293d95(e86d050000)         //~v034M~
    pc+=offs+4+4;				    //called                       //~v034M~
//  printf("0038000f entry 2=%08x\n",pc);                          //~v034M~
    offs=*(ULONG*)(void*)(pc+12);	//mov eax,[c032444c+eax*4]     //~v034M~
//  printf("index table=%08x\n",offs);                             //~v034M~
//*                                                                //~v034M~
#define W32B                                                       //~v184I~
#ifdef W32B                                                        //~v184I~
	bool=GetNumberOfConsoleInputEvents(Shstdin,&inputmode);        //~v184I~
    __asm {                                                        //~v184I~
            mov   oecx,esp          //stack                        //~v184I~
    }                                                              //~v184I~
    pc=(char*)oecx;                                                //~v184I~
    index=*((ULONG*)(void*)(pc-0x10));                             //~v184I~
	if (bool==FALSE)                                               //~v184I~
		uerrapi1x("GetNumberOfConsoleInputEvents","STD_INPUT",GetLastError());//~v184I~
//  printf("index=%08x\n",index);                                  //~v184R~
#else                                                              //~v184I~
	bool=SetConsoleMode(Shstdin,inputmode);                        //~v034M~
    __asm {                                                        //~v034M~
            mov   oecx,ecx          //xfcb ptr                     //~v034M~
    }                                                              //~v034M~
	if (bool==FALSE)                                               //~v034M~
		uerrapi1x("SetConsoleMode","STD_INPUT",GetLastError());    //~v034M~
    pc=(char*)oecx;                                                //~v034M~
//  printf("xfcb=%08x\n",pc);                                      //~v034M~
    index=*((ULONG*)(void*)(pc+0x158));                            //~v034M~
#endif                                                             //~v184I~
    pc=*(char**)(offs+index*4);                                    //~v034M~
//  printf("index=%d,xdcb=%08x\n",index,pc);                       //~v034M~
    pc=*((char**)(pc+8));                                          //~v034M~
//  printf("buffc=%08x\n",pc);                                     //~v034M~
   }//win95                                                        //~v187I~
   else     //win98                                                //~v187I~
    pc=peventh;                                                    //~v187I~
                                                                   //~v187I~
    Sirtop  =(PINPUT_RECORD*)(void*)(pc+0x08);  //top entry        //~v034M~
    Sirread =(PINPUT_RECORD*)(void*)(pc+0x0c);  //next read        //~v034M~
    Sirwrite=(PINPUT_RECORD*)(void*)(pc+0x10);  //next write       //~v034M~
    Sirlast =(PINPUT_RECORD*)(void*)(pc+0x14);  //last entry       //~v034M~
//  printf("top=%08x,read=%08x,write=%08x,last=%08x\n",            //~v034M~
//  		*Sirtop,*Sirread,*Sirwrite,*Sirlast);                  //~v034M~
  }//windows95 init                                                //~v139I~
#endif  //!ULIB64X                                                 //~v6hhI~
#endif  //!MINGW                                                   //~v5ncI~
#endif  //!WXE                                                     //~v570I~
	return;                                                        //~v034M~
}//ukbd_w95init                                                    //~v034R~
                                                                   //~v034I~
//*******************************************************          //~v034I~
//*win95 read kbd event                                            //~v034I~
//p1 :output KBDKEYINFO addr                                       //~v034I~
//p2 :wait option                                                  //~v034I~
//ret:read ctr,always 1                                            //~v034I~
//*******************************************************          //~v034I~
int ukbd_w95read(PKBDKEYINFO Ppkinf,int Pwait)                     //~v034R~
{                                                                  //~v034I~
static	INPUT_RECORD Sinprecsv,*Sirpassed,*Sirmore;                //~v034R~
static  USHORT      Sshiftsv;                                      //~v034I~
//static  UCHAR       Sbuff[2];                                    //~v5ncR~
static	UCHAR 		Ssavesw;                                       //~v034M~
	INPUT_RECORD *beforeread,*afterread;                           //~v034R~
	INPUT_RECORD inprec;                                           //~v034I~
    int         readctr,reportsw,skipreadsw,rc;                    //~v034R~
    USHORT      vkey,newshift;                                     //~v034R~
//****************************                                     //~v034I~
#ifdef WXE                                                         //~v570I~
	if (!Sinitsw)                                                  //~v570I~
#else                                                              //~v570I~
	if (!Shstdin)                                              //~v022M~//~v034I~
#endif                                                             //~v570I~
    	ukbd_w95init();                                        //~v034R~//~v034I~
    if (Sntsw)                                                     //~v139I~
        return ukbd_wntread(Ppkinf,Pwait);                         //~v139R~
    for (;;)                                                       //~v034I~
    {                                                              //~v034I~
	    beforeread=*Sirread;			//entry ptr before read//~v034R~//~v034I~
//created entry at readconsoleinput process                        //~v034I~
        skipreadsw=0;                                              //~v034I~
        if (Sirpassed)		//8000 entry passed                    //~v034R~
        {                                                          //~v034I~
			if (Sirpassed->EventType==VRECID)	//reached to prev read 0001 entry//~v034R~
            {                                                      //~v034I~
	  		    if (Stracesw)                                          //~v034R~//~v034I~
//  	    	    printf("set by passed data %08x\n",Sirpassed);        //~6A23I~//~v034I~//~v139R~//~v6L5R~
    	    	    printf("set by passed data %p\n",Sirpassed);   //~v6L5I~
	    	    rc=ukbd_w95keyinfo(&Sinprecsv,Ppkinf,Sirpassed,(int)Sshiftsv);//~v034R~
                Sirpassed=ukbd_w95getnext(Sirpassed);	//next entry//+v034R~//~v034I~
                if (rc)	//not ignored                              //~v034I~
		            return 1;		//set by skipped entry         //~v034R~
			}                                                      //~v034I~
  		    if (Stracesw)                                          //~v034R~//~v034I~//~v034R~
//      	    printf("end of passed data %08x\n",Sirpassed);        //~6A23I~//~v034I~//+v034R~//~v034R~//~v6L5R~
        	    printf("end of passed data %p\n",Sirpassed);       //~v6L5I~
            beforeread=Sirpassed;	//to bypass no wait chk        //~v034R~
            Sirpassed=0;                                           //~v034I~
            skipreadsw=1;                                          //~v034I~
        }                                                          //~v034R~
        if (Sirmore)                                               //~v034I~
        {                                                          //~v034I~
			if (Sirmore!=*Sirwrite                                 //~v034R~
			&&  Sirmore->EventType==VRECID)	//reached to prev read 0001 entry//~v034I~
            {                                                      //~v034I~
	  		    if (Stracesw)                                      //~v034I~
//  	    	    printf("set by more data %08x,write=%08x\n",Sirmore,*Sirwrite);//~v034R~//~v6L5R~
    	    	    UTRACEPF("%s:set by more data %p,write=%p\n",UTT,Sirmore,*Sirwrite);//~v6L5I~//~v6VuR~
//must char!=0  ureadconsole(Sbuff,1,&readctr);//kick more write   //~v034R~
        	    rc=ukbd_w95keyinfo(&Sinprecsv,Ppkinf,Sirmore,(int)Sshiftsv);//~v034R~
                Sirmore=ukbd_w95getnext(Sirmore);	//next entry   //~v034I~
                if (rc)	//not ignored                              //~v034I~
    	            return 1;		//set by skipped entry         //~v034R~
			}                                                      //~v034I~
  		    if (Stracesw)                                          //~v034I~
//      	    printf("end of more data %08x\n",Sirmore);         //~v034R~//~v6L5R~
        	    UTRACEPF("%s:end of more data %p\n",UTT,Sirmore);           //~v6L5I~//~v6VuR~
            beforeread=Sirmore;	//latest afterread                 //~v034I~
            Sirmore=0;                                             //~v034I~
        }                                                          //~v034I~
//NO_WAIT option                                                   //~v034R~
        if (Pwait==IO_NOWAIT)                                      //~v034I~
        	if (beforeread==*Sirwrite)	//no more data             //~v034R~
            	return 0;                                          //~v034I~
//0001 entry read req                                              //~v034I~
	    if (Stracesw)                                              //~v034I~
//  		printf ("beforeread=%08x\n",beforeread);               //~v034I~//~v6L5R~
    		UTRACEPF("%s:beforeread=%p\n",UTT,beforeread);                 //~v6L5I~//~v6VuR~
        if (skipreadsw)	//already read                             //~v034R~
        {                                                          //~v034I~
        	inprec=*beforeread;                                    //~v034R~
        	Sshiftsv=ukbd_w95shiftconv(&inprec);                   //~v034R~
            afterread=ukbd_w95getnext(beforeread);	//next entry   //~v034R~
		}                                                          //~v034I~
        else                                                       //~v034I~
        {                                                          //~v034I~
	    	ureadconsoleinput(&inprec,1,&readctr);                 //~v034R~
	        afterread=*Sirread;			//entry ptr after read     //~v034R~
//chek entry created at readconsoleinput process(dbcs translation entry)//~v034I~
            if (afterread!=ukbd_w95getnext(beforeread))            //~v034R~
            {                                                      //~v034R~
    	    	Sirpassed=beforeread;		//prev of crated entry //~v034R~
      		    if (Stracesw)                                      //~v034R~
//  				printf ("detected skipped rec %08x->%08x\n",Sirpassed,afterread);//~v034R~//~v6L5R~
    				UTRACEPF("%s:detected skipped rec %p->%p\n",UTT,Sirpassed,afterread);//~v6L5I~//~v6VuR~
                continue;					//process following    //~v034R~
            }                                                      //~v034R~
        }                                                          //~v034I~
//shift report                                                     //~v034I~
        reportsw=0;                                                //~v034M~
    	newshift=ukbd_w95shiftconv(&inprec);                       //~v034R~
//      if (Skbdinfo.fsMask & KEYBOARD_SHIFT_REPORT)       //~v034R~//~v146R~
		if (Sshiftreprtsw)                                         //~v146I~
        {                                                          //~v034I~
    		if (Ssavesw) 	//not first time                       //~v034R~
            {                                                      //~v034R~
    			if (Sshiftsv!=newshift)                            //~v034R~
                {                                                  //~v034I~
                    reportsw=1;                                    //~v034I~
		   		    if (Stracesw)                                  //~v034R~
						UTRACEPF("%s:not same sv=%04x and rd=%04x\n",UTT,  //~v034R~//~v6VuR~
								Sinprecsv.Event.KeyEvent.dwControlKeyState,//~v034R~
    			            	inprec.Event.KeyEvent.dwControlKeyState);   //status changed//~v034R~
                }                                                  //~v034I~
    		}                                                      //~v034R~
	   		else			//first time                           //~v034R~
            {                                                      //~v034R~
        	    vkey=inprec.Event.KeyEvent.wVirtualKeyCode;        //~v034R~
        	    switch(Svkeytbl[vkey])                             //~v034R~
                {                                                  //~v034R~
                case VKID_EXTSHIFT:                                //~v034R~
        		case VKID_SHIFT:                                   //~v034M~
                    reportsw=1;                                //~v034R~//~v034R~//~v034R~
                }//sw                                              //~v034R~
            }//first time                                          //~v034R~
		}//report flag                                             //~v034I~
      if (inprec.Event.KeyEvent.bKeyDown)	//use only key down record for 8000 record scancode//~v299I~
        Sinprecsv=inprec;//latest read entry                       //~v034I~
        Sshiftsv=newshift;                                         //~v034I~
    	Ssavesw=1;                                                 //~v034I~
//chek entry created at key down                                   //~v034M~
		if (*Sirwrite!=afterread				//more to be read  //~v034R~
		&&  afterread->EventType==VRECID)	//reached to prev read 0001 entry//~v034I~
        {                                                          //~v034I~
	    	Sirmore=afterread;			//all 8000 entry           //~v034R~
   		    if (Stracesw)                                          //~v034R~
//  			printf ("detected more rec %08x->%08x\n",afterread,*Sirwrite);//~v034I~//~v6L5R~
				UTRACEPF("%s:detected more rec %p->%p\n",UTT,afterread,*Sirwrite);//~v6L5I~//~v6VuR~
        }                                                          //~v034I~
        else    //nor next data or next is not VREC(8000)          //~v146I~
//      	if (Sinprecsv.Event.KeyEvent.bKeyDown)	//key down record//~v299R~
        	if (inprec.Event.KeyEvent.bKeyDown)	//key down record  //~v299I~
            {                                                      //~v146I~
//          	if (Sinprecsv.Event.KeyEvent.wVirtualScanCode==SCAN_CTL_C	//2e//~v299R~
//          	&&  Sinprecsv.Event.KeyEvent.uChar.AsciiChar==CHAR_CTL_C) //03//~v299R~
            	if (inprec.Event.KeyEvent.wVirtualScanCode==SCAN_CTL_C	//2e//~v299I~
            	&&  inprec.Event.KeyEvent.uChar.AsciiChar==CHAR_CTL_C) //03//~v299I~
                {                                                  //~v146I~
//  				ukbd_w95keyinfo(&Sinprecsv,Ppkinf,0,Sshiftsv);//shift record//~v299R~
					ukbd_w95keyinfo(&inprec,Ppkinf,0,Sshiftsv);//shift record//~v299I~
                    break;                                         //~v146I~
                }//CTRL+C	                                       //~v146I~
			}                                                      //~v146I~
        if (reportsw)                                              //~v034I~//~v034R~
        {                                                          //~v034I~
			ukbd_w95keyinfo(&inprec,Ppkinf,0,Sshiftsv);//shift record     //~v034R~//~v034R~
    	    Ppkinf->fbStatus|=KBDTRF_SHIFT_KEY_IN;	//       0x01  //~v146R~
            break;                                                 //~v034I~
		}                                                          //~v034I~
    }//loop                                                        //~v034I~
    return 1;                                                      //~v034I~
}//ukbd_w95read                                                    //~v034I~
                                                                   //~v034I~
//**************************************************               //~v034I~
//*ukbd_w95getnext                                                 //~v034I~
//*get next entry addr                                             //~v034I~
//*parm1:PINPUT_RECORD                                             //~v034I~
//*ret  :PINPUT_RECORD                                             //~v034I~
//**************************************************               //~v034I~
PINPUT_RECORD ukbd_w95getnext(PINPUT_RECORD Ppinprec)              //~v034I~
{                                                                  //~v034I~
//***************************                                      //~v034I~
	if (++Ppinprec==*Sirlast)                            //~6A23I~ //~v034I~
		Ppinprec=*Sirtop;                              //~6A23I~   //~v034I~
	return 	Ppinprec;                                              //~v034I~
}//ukbd_w95getnext                                                 //~v034R~
                                                                   //~v034I~
//*******************************************************          //~v139M~
//*win/NT read kbd event                                           //~v139M~
//p1 :output KBDKEYINFO addr                                       //~v139M~
//p2 :wait option                                                  //~v139M~
//ret:read ctr,always 1                                            //~v139M~
//*******************************************************          //~v139M~
int ukbd_wntread(PKBDKEYINFO Ppkinf,int Pwait)                     //~v139M~
{                                                                  //~v139M~
static  USHORT      Sshiftsv;                                      //~v139I~
	INPUT_RECORD inprec;                                           //~v139M~
    int         readctr,rc;                                        //~v139R~
    USHORT      newshift;                                          //~v139M~
#define MAXPEEK 100                                                //~v139M~
	INPUT_RECORD  peekrec[MAXPEEK];                                //~v139M~
    int eventno=0,peekctr=0;                                           //~v139M~//~v6h6R~
#ifdef WXE                                                         //~v6U1I~
#else                                                              //~v6U1I~
	int focuseventctr=0;                                           //~v6U1I~
	DWORD eventctr;                                                //~v6U1I~
	#define LOOP_BREAK 20                                          //~v6U1R~
#endif                                                             //~v6U1I~
//****************************                                     //~v139M~
//  UTRACEP("%s:entry        focuseventctr=%d\n",UTT,focuseventctr);//~v6U1R~
    if (Pwait==IO_NOWAIT)   //peek                                 //~v139M~
    {                                                              //~v139M~
		eventno=ugetinputeventno();                                //~v139M~
        if (!eventno)                                              //~v139M~
        	return 0;                                              //~v139M~
		if (eventno>MAXPEEK)                                       //~v139M~
        	eventno=MAXPEEK;                                       //~v139M~
        peekctr=eventno;                                           //~v139M~
		upeekconsoleinput(peekrec,peekctr,&eventno);               //~v139M~
        peekctr=0;                                                 //~v139M~
    }                                                              //~v139M~
    for (;;)                                                       //~v139M~
    {                                                              //~v139M~
	    if (Pwait==IO_NOWAIT)   //peek                             //~v139M~
        {                                                          //~v139M~
        	if (peekctr>=eventno)                                  //~v139M~
            	return 0;                                          //~v139M~
        	inprec=peekrec[peekctr];                               //~v139M~
            peekctr++;                                             //~v139M~
		}                                                          //~v139M~
        else                                                       //~v139M~
        {                                                          //~v139I~
  		  	if (Swcstat & UDCWCIO_KBDMBS)                          //~v5n8R~
				if (ukbd_wntkeyinfo_u2m(UKBD_MBSCHK,&inprec/*not used*/,Ppkinf))//~v5n8R~
                	return 1;                                      //~v5n8I~
	    	ureadconsoleinput(&inprec,1,&readctr);	//get event record//~v139R~
        	if (!readctr)                                          //~v139I~
#ifdef WXE                                                         //~v570I~
            	return 0;   //retur 0;xekbd return with nop        //~v570I~
#else                                                              //~v570I~
            	continue;                                          //~v139R~
#endif                                                             //~v570I~
		}                                                          //~v139I~
        		                                                   //~v139I~
//      UTRACEP("%s:eventtype=%x focuseventctr=%d\n",UTT,inprec.EventType,focuseventctr);//~v6U1R~
        if (inprec.EventType!=KEY_EVENT)                           //~v139M~
#ifdef WXE                                                         //~v570I~
            return 0;   //retur 0;xekbd return with nop            //~v570I~
#else                                                              //~v570I~
		{                                                          //~v6U1I~
        	if (inprec.EventType==FOCUS_EVENT)                     //~v6U1I~
        	{		                                               //~v6U1I~
        		focuseventctr++;                                   //~v6U1I~
//          	GetNumberOfConsoleInputEvents(Shstdin,&eventctr);  //~v6U1R~
//          	UTRACEP("%s:focusevent ctr=%d,bSetFocus=%d,numberofevent=%d\n",UTT,focuseventctr,inprec.Event.FocusEvent.bSetFocus,eventctr);//~v6U1R~
                if (focuseventctr%LOOP_BREAK==0)                   //~v6U1R~
                {                                                  //~v6U1I~
	            	GetNumberOfConsoleInputEvents(Shstdin,&eventctr);//~v6U1I~
	            	UTRACEP("%s:flush by focusevent ctr=%d,bSetFocus=%d,numberofevent=%d\n",UTT,focuseventctr,inprec.Event.FocusEvent.bSetFocus,eventctr);//~v6U1R~
                	FlushConsoleInputBuffer(Shstdin);              //~v6U1I~
                }                                                  //~v6U1I~
        	}                                                      //~v6U1I~
        	continue;	//other event                              //~v139M~
        }                                                          //~v6U1I~
#endif                                                             //~v570I~
        if (!inprec.Event.KeyEvent.bKeyDown)                       //~v139R~
        {                                                          //~v146I~
	   	  	if (!Sshiftreprtsw)	//no shift reprt                   //~v146I~
#ifdef WXE                                                         //~v570I~
      		    return 0;   //retur 0;xekbd return with nop        //~v570I~
#else                                                              //~v570I~
        		continue;			//wait keydown event               //~v146R~
#endif                                                             //~v570I~
		  	newshift=ukbd_w95shiftconv(&inprec);                     //~v146I~
		}                                                          //~v146I~
        else	//key down                                                       //~v146I~
        {                                                          //~v146I~
	    	newshift=ukbd_w95shiftconv(&inprec);                       //~v139R~
            rc=ukbd_wntkeyinfo(&inprec,Ppkinf,newshift);               //~v139R~
            if (rc)         //not ignore                               //~v139R~
            {                                                          //~v139I~
                Sshiftsv=newshift;                                     //~v139I~
                break;                                                 //~v139R~
            }                                                          //~v139I~
        }                                                          //~v146I~
//shift report                                                     //~v139M~
//      if (Skbdinfo.fsMask & KEYBOARD_SHIFT_REPORT)               //~v146R~
		if (Sshiftreprtsw)                                         //~v146I~
#ifdef WXE                                                         //~v5biM~
			if (newshift & KBDSTF_RIGHTCONTROL)                    //~v5biI~
#else                                                              //~v5biM~
//          if (Sshiftsv!=newshift)                                //~v5kpR~
			if (newshift & KBDSTF_RIGHTCONTROL)                    //~v5kpI~
#endif                                                             //~v5biM~
            {                                                      //~v139I~
                Ppkinf->fbStatus|=KBDTRF_SHIFT_KEY_IN;  //       0x01//~v139R~
    	        Sshiftsv=newshift;                                 //~v139I~
                break;                                             //~v139R~
            }                                                      //~v139I~
    }//loop                                                        //~v139M~
    return 1;                                                      //~v139M~
}//ukbd_wntread                                                    //~v139M~
                                                                   //~v139M~
//**************************************************               //~v034I~
//*ukbd_w95keyinfo                                                 //~v034R~
//*setup keyinfo record from win95 event record                    //~v034R~
//*parm1:INPUT_RECORD                                              //~v034I~
//*parm2:KBDKEYINFO                                                //~v034I~
//*parm3:INPUT_RECORD of type 0x8000 or 0 for shift report or peek req//~v034R~
//*parm4:meaningfull when parm3==0                                 //~v034I~
//       shift status for shift report                             //~v139R~
//*rc   :1:ok,0:ignored                                            //~v034R~
//**************************************************               //~v034I~
int ukbd_w95keyinfo(PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo,    //~v034R~
			PINPUT_RECORD Pp8000rec,int Pshift)                    //~v034R~
{                                                                  //~v034I~
static UCHAR Sdbcssw;                                              //~v034R~
    USHORT vkey;                                                   //~v034I~
    UCHAR  ch,scan;                                                //~v034R~
//**********************                                           //~v034I~
    if (Stracesw & 0x01)                                           //~v034R~
		UTRACEPF("%s:ukbd_w95keyinfo-1:%04x,%08x,%04x-%04x,%04x-%04x,%08x\n",UTT,//~v034I~//~v6VuR~
            	(UINT)Ppinprec->EventType,                         //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.bKeyDown,           //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.wRepeatCount,       //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.wVirtualKeyCode,    //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.wVirtualScanCode,   //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.uChar.AsciiChar,    //~v034I~
            	(UINT)Ppinprec->Event.KeyEvent.dwControlKeyState); //~v034I~
	memset(Ppkinfo,0,sizeof(KBDKEYINFO));                          //~v034I~
//  if (Pshift==-1)    //peek                                      //~v139R~
//  	Ppkinfo->fsState=ukbd_w95shiftconv(Ppinprec);              //~v139R~
//  else                                                           //~v139R~
		Ppkinfo->fsState=(USHORT)Pshift;                           //~v034I~
    if (Pp8000rec)	//8000 process                                 //~v034R~
    {                                                              //~v034I~
//dos accept henkann etc as ext key,os2 accept as space            //~v034I~
//we set win95 like dos                                            //~v034I~
        vkey=Pp8000rec->Event.KeyEvent.wVirtualKeyCode;            //~v034I~
//@@@@  if (Svkeytbl[vkey]==VKID_IGNORE)                           //~v034R~
//@@@@  	return 0;                                              //~v034R~
	    if (Stracesw & 0x01)                                       //~v034I~
    		UTRACEPF("%s:ukbd_w95keyinfo-2:%04x,%08x,%04x-%04x,%04x-%04x,%08x\n",UTT,//~v034I~//~v6VuR~
                	(UINT)Pp8000rec->EventType,                    //~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.bKeyDown,      //~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.wRepeatCount,  //~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.wVirtualKeyCode,//~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.wVirtualScanCode,//~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.uChar.AsciiChar,//~v034R~
                	(UINT)Pp8000rec->Event.KeyEvent.dwControlKeyState);//~v034R~
    	ch  =(UCHAR)Pp8000rec->Event.KeyEvent.uChar.AsciiChar;     //~v034I~
     	if (!(scan=(UCHAR)Pp8000rec->Event.KeyEvent.wVirtualKeyCode))//no vkey//~v034R~//~v034R~
		{   	//no virtual key                                   //~v034I~
            if (Sdbcssw)                                           //~v034I~
            {                                                      //~v034I~
            	Sdbcssw=0;                                         //~v034I~
                scan=0;         //dbcs second byte                 //~v034I~
            }                                                      //~v034I~
            else                                                   //~v034I~
	            if (udbcschk(ch))   //dbcs first byte              //~v034R~
    	        {                                                  //~v034R~
                	Sdbcssw=1;                                     //~v034I~
                    scan=0;         //dbcs second byte             //~v034I~
				}                                                  //~v034I~
                else                                               //~v034I~
                    if (ch>=0x80)   //katakana                     //~v034I~
                        scan=0;         //dbcs second byte         //~v034I~
                    else                                           //~v034I~
                    	scan=(UCHAR)Ppinprec->Event.KeyEvent.wVirtualScanCode;//~v034I~//~v034I~
        }//no virtual key                                          //~v034I~
    }//8000 record exist                                           //~v034I~
    else	//peek/shift report                                    //~v034R~
    {                                                              //~v034I~
    	scan=(UCHAR)Ppinprec->Event.KeyEvent.wVirtualScanCode,     //~v034I~
    	ch  =(UCHAR)Ppinprec->Event.KeyEvent.uChar.AsciiChar;  //~v034I~//~v034I~
//  	if (Pshift!=-1)    //peek                                  //~v146R~
//  	    Ppkinfo->fbStatus|=KBDTRF_SHIFT_KEY_IN;	//       0x01//~v034R~//~v146R~
    }                                                              //~v034I~
    Ppkinfo->chScan=scan;                                          //~v034I~
    Ppkinfo->chChar=ch;                                            //~v034I~
//  if (Stracesw)                                          //~v034I~//~v034R~
//  	printf("++keyinfo:next=%08x:scan=%02x,char=%02x,status=%04x\n",//~v034R~
//  			Pp8000rec,(int)scan,(int)ch,(int)ostate);          //~v034R~
	return 1;	//processed                                        //~v034I~
}//ukbd_w95keyinfo                                                 //~v034R~
                                                                   //~v034I~
//**************************************************               //~v139M~
//*ukbd_wntkeyinfo                                                 //~v139M~
//*setup keyinfo record from win95 event record                    //~v139M~
//*parm1:INPUT_RECORD                                              //~v139M~
//*parm2:KBDKEYINFO                                                //~v139M~
//*parm3:shft report                                               //~v139M~
//       shift status for shift report,-1 for peek record          //~v139M~
//*rc   :1:ok,0:ignored                                            //~v139M~
//**************************************************               //~v139M~
int ukbd_wntkeyinfo(PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo,int Pshift)//~v139M~
{                                                                  //~v139M~
	USHORT shift;                                                  //~v139M~
	USHORT scanchar;                                               //~v139M~
	UCHAR  scan,sc=0,ch;                                             //~v139R~//~v6h6R~
    int ii,jj;                                                     //~v139M~
    int rc;                                                        //~v5n8I~
//**********************                                           //~v139M~
    if (Stracesw & 0x01)                                           //~v139M~
    {                                                              //~v139M~
		UTRACEPF("%s:ukbd_w95keyinfo-1:shift=%08x\n",UTT,Pshift);           //~v139M~//~v6VuR~
		UTRACEPF("%s:ukbd_w95keyinfo-1:%04x,%08x,%04x-%04x,%04x-%04x,ucs=%04x,%08x\n",UTT,//~v5n8R~//~v6VuR~
            	(UINT)Ppinprec->EventType,                         //~v139M~
            	(UINT)Ppinprec->Event.KeyEvent.bKeyDown,           //~v139M~
            	(UINT)Ppinprec->Event.KeyEvent.wRepeatCount,       //~v139M~
            	(UINT)Ppinprec->Event.KeyEvent.wVirtualKeyCode,    //~v139M~
            	(UINT)Ppinprec->Event.KeyEvent.wVirtualScanCode,   //~v139M~
            	(UINT)Ppinprec->Event.KeyEvent.uChar.AsciiChar,    //~v139M~
	            (UINT)Ppinprec->Event.KeyEvent.uChar.UnicodeChar,  //~v5n8I~
            	(UINT)Ppinprec->Event.KeyEvent.dwControlKeyState); //~v139M~
    }                                                              //~v139M~
	memset(Ppkinfo,0,sizeof(KBDKEYINFO));                          //~v139M~
    Ppkinfo->fsState=(USHORT)Pshift;                               //~v139R~
    if (Swcstat & UDCWCIO_KBDUNICODE) //return unicode             //~v5n8R~
    {                                                              //~v5n8I~
    	if (!Ppinprec->Event.KeyEvent.wVirtualKeyCode && !Ppinprec->Event.KeyEvent.wVirtualScanCode) //IME output//~v5n8I~
        {                                                          //~v5n8I~
		    Ppkinfo->bNlsShift=KBDNLS_UNICODE;                     //~v5n8I~
			Ppkinfo->chScan=(UCHAR)((UINT)(Ppinprec->Event.KeyEvent.uChar.UnicodeChar) & 0xff);//~v5n8I~
			Ppkinfo->chChar=(UCHAR)((UINT)(Ppinprec->Event.KeyEvent.uChar.UnicodeChar) >>8);//~v5n8I~
            return 1;                                              //~v5n8I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    else                                                           //~v5n8I~
    if (Swcstat & UDCWCIO_WIDEAPI)    //by Widechar API            //~v5n8R~
    {                                                              //~v5n8I~
		if ((rc=ukbd_wntkeyinfo_u2m(0,Ppinprec,Ppkinfo))>=0)  //Wide->MB conversion//~v5n8R~
        	return rc;                                             //~v5n8I~
    }                                                              //~v5n8I~
	shift=Ppkinfo->fsState;                                        //~v139M~
	scan=                                                          //~v139M~
    Ppkinfo->chScan=(UCHAR)Ppinprec->Event.KeyEvent.wVirtualScanCode,//~v139M~
    Ppkinfo->chChar=(UCHAR)Ppinprec->Event.KeyEvent.uChar.AsciiChar;//~v139M~
                                                                   //~v139R~
    if (shift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))              //~v139I~
    {                                                              //~v6EzI~
	  if (shift & (KBDSTF_RIGHTALT|KBDSTF_LEFTALT))                //~v5irI~
        jj=3;       //alt                                          //~v5irI~
      else                                                         //~v5irI~
      if (shift & (KBDSTF_RIGHTCONTROL|KBDSTF_LEFTCONTROL))        //~v6EzI~
        jj=2;       //control                                      //~v6EzI~
      else                                                         //~v6EzI~
        jj=1;       //shift                                        //~v139I~
    }                                                              //~v6EzI~
    else                                                           //~v139I~
    if (shift & (KBDSTF_RIGHTCONTROL|KBDSTF_LEFTCONTROL))          //~v139I~
        jj=2;       //control                                      //~v139I~
    else                                                           //~v139I~
    if (shift & (KBDSTF_RIGHTALT|KBDSTF_LEFTALT))                  //~v139I~
        jj=3;       //alt                                          //~v139I~
    else                                                           //~v139I~
        jj=0;       //normal                                       //~v139I~
//ext  key conversion                                              //~v139I~
    if (!Ppkinfo->chChar                                           //~v139R~
	&&   (Ppinprec->Event.KeyEvent.dwControlKeyState & ENHANCED_KEY))//~v139R~
    {                                                              //~v139R~
        for (ii=0;ii<sizeof(Sextkeytbl1);ii++)                     //~v139R~
            if( scan==Sextkeytbl1[ii])                             //~v139R~
                break;                                             //~v139R~
        if (ii>=sizeof(Sextkeytbl1))                               //~v139R~
            return 0;                                              //~v139R~
        scanchar=Sextkeytbl2[ii][jj];                              //~v139R~
        sc=(scanchar>>8);                                          //~v139R~
        ch=(scanchar & 255);                                       //~v139R~
    }   //enhanced key                                             //~v139R~
    else                                                           //~v139R~
    {                                                              //~v5imI~
        scanchar=0;                                                //~v5imI~
        ch=(UCHAR)Ppinprec->Event.KeyEvent.wVirtualKeyCode; //on wxe ascii=0;on xe ascii!=0 when A+//~v5imI~
        if (jj!=3 && shift & (KBDSTF_RIGHTALT|KBDSTF_LEFTALT))   //alt is combined with other shift key//~v5imI~
        {                                                          //~v5imI~
            ch&=0x7f;   //0x80 on in some key                      //~v5imI~
            for (ii=0;ii<VKALTTBSZ;ii+=3)                          //~v5imI~
                if(ch==Svkeyalttbl[ii])                            //~v5imI~
                {                                                  //~v5imI~
                    sc=Svkeyalttbl[ii+1];                          //~v5imI~
                    ch=Svkeyalttbl[ii+2];                          //~v5imI~
                    scanchar=(sc<<8)+ch;                           //~v5imI~
                    break;                                         //~v5imI~
                }                                                  //~v5imI~
        }                                                          //~v5imI~
      if (!scanchar)                                               //~v5imI~
      {                                                            //~v5ncI~
	    if (!Ppkinfo->chChar                                       //~v139I~
        ||  scan==0x0f            //TABCHAR                        //~v164R~
        ||  jj==3)	//alt                                          //~v139R~
        {                                                          //~v139I~
            scanchar=Sscanconvtbl[scan][jj];                       //~v139R~
            sc=(scanchar>>8);                                      //~v139R~
            ch=(scanchar & 255);                                   //~v139R~
            if (!ch || ch==0xe0)                                   //~v139R~
            {                                                      //~v139R~
                if (!sc)        //both ==0                         //~v139R~
                    return 0;                                      //~v139R~
            }                                                      //~v139R~
            else        //ch!=0                                    //~v139R~
            {                                                      //~v139R~
                if (sc)     //both !=0                             //~v139R~
                    return 0;                                      //~v139R~
                sc=scan;    //keep  original scan code             //~v139R~
            }                                                      //~v139R~
        }//char==0 or alt                                          //~v139I~
        else                                                       //~v139I~
            return 1;                                              //~v139I~
      }                                                            //~v5ncI~
    }                                                              //~v5imI~
    if (Stracesw)                                                  //~v139R~
    {                                                              //~v6VuI~
//      printf("code conv %02x,%02x-->%02x,%02x\n",                //~v139R~//~v6VuR~
//                  Ppkinfo->chScan,Ppkinfo->chChar,sc,ch);        //~v139R~//~v6VuR~
UTRACEPF("%s:code conv %02x,%02x-->%02x,%02x SHIFT=%x\n",UTT,              //~v5maI~//~v6VuR~
                   Ppkinfo->chScan,Ppkinfo->chChar,sc,ch,Pshift);  //~v5maI~
    }                                                              //~v6VuI~
    Ppkinfo->chScan=sc;                                            //~v139R~
    Ppkinfo->chChar=ch;                                            //~v139R~
	return 1;	//processed                                        //~v139M~
}//ukbd_wntkeyinfo                                                 //~v139M~
//**************************************************               //~v5n8I~
//*ukbd_wntkeyinfo                                                 //~v5n8I~
//*convert widechar to multibyte                                   //~v5n8I~
//*rc   :1:ok,0:ignored,-1:not ime char                            //~v5n8I~
//**************************************************               //~v5n8I~
int ukbd_wntkeyinfo_u2m(int Popt,PINPUT_RECORD Ppinprec,PKBDKEYINFO Ppkinfo)//~v5n8R~
{                                                                  //~v5n8I~
static int Smbslen=0,Smbsoffs=0;	                               //~v5n8I~
static UCHAR Smbs[MAX_MBCSLEN];                                    //~v5n8I~
static KBDKEYINFO Simekeyinfo;                                     //~v5n8I~
	USHORT ucs;                                                    //~v5n8I~
    UCHAR ch;                                                      //~v5n8R~
    int mbslen;                                                    //~v5n8R~
#ifdef UTF8SUPPH                                                   //~v5n8I~
	int utf8len;                                                   //~v5n8I~
#endif                                                             //~v5n8I~
//**********************                                           //~v5n8I~
	if (Smbsoffs<Smbslen)	//remaining previous mbs input         //~v5n8I~
    {                                                              //~v5n8I~
    	memcpy(Ppkinfo,&Simekeyinfo,sizeof(KBDKEYINFO));           //~v5n8R~
		Ppkinfo->bNlsShift=KBDNLS_F2L_DBCS2ND;                     //~v5n8R~
		Ppkinfo->chChar=Smbs[Smbsoffs++];                          //~v5n8I~
UTRACED("keyinfo",Ppkinfo,sizeof(KBDKEYINFO));                     //~v5n8R~
UTRACEP("ret cont len=%d,offs=%d\n",Smbslen,Smbsoffs);             //~v5n8I~
        return 1;                                                  //~v5n8I~
    }                                                              //~v5n8I~
    else                                                           //~v5n8I~
    	if (Popt & UKBD_MBSCHK)	//chk pending before issue API     //~v5n8I~
        {                                                          //~v5n8I~
			UTRACEP("ukbdw rchk pending,rec=0\n");                 //~v5n8R~
        	return 0;                                              //~v5n8I~
        }                                                          //~v5n8I~
UTRACED("inprec",Ppinprec,sizeof(INPUT_RECORD));                   //~v5n8M~
    Smbslen=0;                                                     //~v5n8I~
#ifdef UTF8UCS2                                                    //~v62CI~
	#ifdef WXE                                                     //~v62CI~
	if (Ppinprec->Event.KeyEvent.uChar.UnicodeChar==0xe0           //~v62CI~
    &&  !(Ppinprec->Event.KeyEvent.wVirtualKeyCode))       //from wxe_funccall//~v62CR~
    	return -1;                                                 //~v62CI~
    if (Ppinprec->Event.KeyEvent.wVirtualKeyCode)       //not WXEKBDMSG_ONCHARUCS case//~v65dR~
    	return -1;                                                 //~v65dR~
	#endif                                                         //~v62CI~
#endif                                                             //~v62CI~
    if (Ppinprec->Event.KeyEvent.wVirtualKeyCode || Ppinprec->Event.KeyEvent.wVirtualScanCode) //not IME output//~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62CR~
    {                                                              //~v62CI~
	  if (Ppinprec->Event.KeyEvent.uChar.UnicodeChar<0x80)	//0:ext key,ascii noreed to translate//~v62CR~
    	return -1;                                                 //~v5n8I~
	  Ppkinfo->chScan=(UCHAR)(Ppinprec->Event.KeyEvent.wVirtualScanCode); //not IME output//~v62CR~
    }                                                              //~v62CI~
  else                                                             //~v62CI~
#endif                                                             //~v62CI~
	Ppkinfo->chScan=KBDSCAN_IMECHAR;	//=0                       //~v5n8I~
	ucs=Ppinprec->Event.KeyEvent.uChar.UnicodeChar;                //~v5n8I~
    if (!(ucs & 0xff80))	//ascii	                               //~v5n8I~
    {                                                              //~v5n8I~
    	ch=(UCHAR)ucs;                                             //~v5n8I~
    }                                                              //~v5n8I~
    else                                                           //~v5n8I~
    {                                                              //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62rI~
      if (Swcstat & UDCWCIO_KBDNOUTF8)    // -Nm option            //~v62rR~
      {                                                            //~v62rI~
		Smbslen=uccvucs2utf((ULONG)ucs,Smbs);                      //~v62rI~
        ch=Smbs[0];                                                //~v62rI~
        Smbsoffs=1;                                                //~v62rI~
      }                                                            //~v62rI~
      else                                                         //~v62rI~
#endif                                                             //~v62rI~
      {                                                            //~v62rI~
		ukbd_u2m(0,ucs,Smbs,&mbslen);                              //~v5n8I~
        ch=Smbs[0];                                                //~v5n8I~
        if (mbslen>1)                                              //~v5n8I~
        {                                                          //~v5n8I~
        	Smbslen=mbslen;                                        //~v5n8I~
            Smbsoffs=1;                                            //~v5n8I~
	    	memcpy(&Simekeyinfo,Ppkinfo,sizeof(KBDKEYINFO));       //~v5n8R~
		    Ppkinfo->bNlsShift=KBDNLS_F2L_DBCS1ST;                 //~v5n8R~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
		    Ppkinfo->bNlsShift=KBDNLS_F2L_SBCS;                    //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v5n8I~
		utf8len=uccvucs2utf((ULONG)ucs,Ppkinfo->u8str);            //~v5n8R~
		*(Ppkinfo->u8str+utf8len)=0;                               //~v5n8R~
#endif                                                             //~v5n8I~
      }                                                            //~v62rI~
    }                                                              //~v5n8I~
    Ppkinfo->chChar=ch;                                            //~v5n8I~
UTRACED("keyinfo",Ppkinfo,sizeof(KBDKEYINFO));                     //~v5n8R~
UTRACEP("ret len=%d,offs=%d\n",Smbslen,Smbsoffs);                  //~v5n8I~
	return 1;	//processed                                        //~v5n8I~
}//ukbd_wntkeyinfo_u2m                                             //~v5n8R~
                                                                   //~v5n8I~
//**************************************************               //~v034I~
//*ukbd_w95shiftconv                                               //~v034I~
//*convert w95 shift status flag to os2                            //~v034R~
//*parm1:INPUT_RECORD                                              //~v034I~
//*rc   :shift status                                              //~v034R~
//**************************************************               //~v034I~
USHORT ukbd_w95shiftconv(PINPUT_RECORD Ppinprec)                   //~v034R~
{                                                                  //~v034I~
    int    istate;                                                 //~v034R~
    USHORT ostate=0,scan;                                          //~v034I~
//**********************                                           //~v034I~
	istate=Ppinprec->Event.KeyEvent.dwControlKeyState;             //~v034I~
//win95 has no difference in shift status by right/left shift key  //~v034I~
	if (istate & SHIFT_PRESSED)                                    //~v034I~
    {                                                              //~v5ncI~
        if ((scan=Ppinprec->Event.KeyEvent.wVirtualScanCode)==SCAN_LSHIFT)//~v034I~
	    	ostate|=KBDSTF_LEFTSHIFT;                              //~v034I~
		else                                                       //~v034I~
	        if (scan==SCAN_RSHIFT)                                 //~v034I~
	    		ostate|=KBDSTF_RIGHTSHIFT;                         //~v034I~
			else                                                   //~v034I~
	    		ostate|=KBDSTF_RIGHTSHIFT+KBDSTF_LEFTSHIFT;        //~v034I~
    }                                                              //~v5ncI~
	if (istate & RIGHT_ALT_PRESSED)                                //~v034I~
    	ostate|=KBDSTF_ALT+KBDSTF_RIGHTALT;                        //~v034I~
	if (istate & LEFT_ALT_PRESSED)                                 //~v034I~
    	ostate|=KBDSTF_ALT+KBDSTF_LEFTALT;                         //~v034I~
	if (istate & RIGHT_CTRL_PRESSED)                               //~v034I~
    	ostate|=KBDSTF_CONTROL+KBDSTF_RIGHTCONTROL;                //~v034I~
	if (istate & LEFT_CTRL_PRESSED)                                //~v034I~
    	ostate|=KBDSTF_CONTROL+KBDSTF_LEFTCONTROL;                 //~v034I~
	if (istate & NUMLOCK_ON)                                       //~v034I~
    	ostate|=KBDSTF_NUMLOCK_ON;                                 //~v034I~
	if (istate & SCROLLLOCK_ON)                                    //~v034I~
    	ostate|=KBDSTF_SCROLLLOCK_ON;                              //~v034I~
	if (istate & CAPSLOCK_ON)                                      //~v034I~
    	ostate|=KBDSTF_CAPSLOCK_ON;                                //~v034I~
    if (Stracesw)                                                  //~v034I~
		UTRACEPF("%s:shift conv in=%04x,out=%04x\n",UTT,istate,ostate);     //~v034I~//~v6VuR~
	return ostate;                                                 //~v034I~
}//ukbd_w95shiftconv                                               //~v034R~
                                                                   //~v034I~
//**************************************************               //~v034I~
//*ukbd_w95trace                                                   //~v034I~
//*trace event record                                              //~v034I~
//*parm1:comment                                                   //~v139R~
//*parm2:INPUT_RECORD or 0                                         //~v139R~
//*rc   :none                                                      //~v034I~
//**************************************************               //~v034I~
void ukbd_w95trace(char *comm,void *Ppinprec)                      //~v139R~
{                                                                  //~v034I~
//static pno;                                                      //~v5ncR~
static int pno;                                                    //~v5ncI~
    UINT typ,hh,down,rep,vkey,scan,ch,state;                       //~v034I~
    INPUT_RECORD *inprec;                                          //~v034I~
	char *pc1=NULL,*pc2,*pc0;                                           //~v034I~//~v6h6R~
    int len,loop,ii;                                               //~v034R~
//**********************                                           //~v034I~
  if (Sntsw)	                                                   //~v139I~
  {                                                                //~v139I~
  	if (Ppinprec)                                                  //~v139I~
    {                                                              //~v139I~
    	loop=1;                                                    //~v139I~
        pc1=Ppinprec;                                              //~v139R~
    }                                                              //~v139I~
    else                                                           //~v139I~
        loop=0;                                                    //~v139I~
    pno=0;  //from first                                           //~v139I~
  }                                                                //~v139I~
  else                                                             //~v139I~
  {                                                                //~v139I~
    if (!*comm)                                                    //~v034I~
    	pno=0; 	//from first                                       //~v034I~
    pc0=(char*)(void*)*Sirtop;                                     //~v034I~
    pc1=pc0+pno*0x14;                                              //~v034I~
    pc2=(char*)(void*)*Sirwrite;                                   //~v034I~
//  len=(ULONG)pc2-(ULONG)pc1;                                     //~v034I~//~v6hhR~
//  len=(ULPTR)pc2-(ULPTR)pc1;                                     //~v6hhI~//~v6ByR~
    len=PTRDIFF(pc2,pc1);                                          //~v6ByI~
    len/=0x14;                                                     //~v034I~
    loop=len;                                                      //~v034I~
//  if (pno)                                                       //~v034I~
//  {                                                              //~v034I~
//      pc1-=0x14;                                                 //~v034I~
//      loop++;                                                    //~v034I~
//      pno--;                                                     //~v034I~
//  }                                                              //~v034I~
  if (Stracesw2 & KBD_PTRACE)                                      //~v298R~
//  printf("=%s===readptr=%08x,writeptr=%08x\n",comm,*Sirread,*Sirwrite);//~v034I~//~v6L5R~
//  printf("=%s===readptr=%p,writeptr=%p\n",comm,*Sirread,*Sirwrite);//~v6L5I~//~v6VuR~
    UTRACEPF("%s:=%s===readptr=%p,writeptr=%p\n",UTT,comm,*Sirread,*Sirwrite);//~v6VuI~
  }                                                                //~v139I~
  if (Stracesw2 & KBD_PTRACE)                                      //~v298R~
    for (ii=0;ii<loop;ii++,pc1+=0x14)                              //~v034I~
    {                                                              //~v034I~
    	if (!pc1)                                                  //~v6h6I~
        	break;                                                 //~v6h6I~
		hh=(UINT)(*(USHORT*)(void*)(pc1+2));                       //~v034I~
    	inprec=(INPUT_RECORD *)(void*)pc1;                         //~v034I~
		typ=(UINT)inprec->EventType;                               //~v034I~
		ch=(UINT)inprec->Event.KeyEvent.uChar.AsciiChar;           //~v034I~
		down=(UINT)inprec->Event.KeyEvent.bKeyDown;                //~v034I~
		rep=(UINT)inprec->Event.KeyEvent.wRepeatCount;             //~v034I~
	    vkey=(UINT)inprec->Event.KeyEvent.wVirtualKeyCode;         //~v034I~
	    scan=(UINT)inprec->Event.KeyEvent.wVirtualScanCode;        //~v034I~
	    state=(UINT)inprec->Event.KeyEvent.dwControlKeyState;      //~v034I~
//      printf("%08x=#%02d: %04x-%04x,%08x,%04x-%04x,%04x-%04x,%08x\n",//~v034I~//~v6L5R~
//      printf("%p=#%02d: %04x-%04x,%08x,%04x-%04x,%04x-%04x,%08x\n",//~v6L5I~//~v6VuR~
        UTRACEPF("%s:%p=#%02d: %04x-%04x,%08x,%04x-%04x,%04x-%04x,%08x\n",UTT,//~v6VuI~
        pc1,pno+ii,(UINT)typ,(UINT)hh,down,(UINT)rep,(UINT)vkey,(UINT)scan,(UINT)ch,state);//~v034I~
    }                                                              //~v034I~
    else                                                           //~v298I~
        UTRACED(comm,pc1,loop*0x14);                               //~v298R~
//  pno+=loop;                                                     //~v298R~
}//ukbd_w95trace                                                   //~v034R~
                                                                   //~v034I~
//*******************************************************          //~v034M~
//*win get console mode                                            //~v034M~
//*may called before w95init                                       //~v034M~
//*parm1:id of in/out  0:input,1:output                            //~v141I~
//ret:current mode                                                 //~v034M~
//*******************************************************          //~v034M~
//UINT ugetconsolemode(int Pid)                                      //~v141R~//~v6hdR~
DWORD ugetconsolemode(int Pid)                                     //~v6hdI~
{                                                                  //~v034M~
//	UINT oldmode;                                                  //~v034M~//~v6hdR~
  	DWORD oldmode;                                                 //~v6hdI~
	HANDLE hstdin;                                                 //~v034M~
    UINT lasterr;                                                  //~v204I~
//******************                                               //~v034M~
  if (Pid)                                                         //~v141I~
	hstdin=ugetstdhandle(STD_OUTPUT_HANDLE);                       //~v141I~
  else                                                             //~v141I~
	hstdin=ugetstdhandle(STD_INPUT_HANDLE);                        //~v034M~
	if (!GetConsoleMode(hstdin,&oldmode))                          //~v034M~
    {                                                              //~v204I~
        lasterr=GetLastError();                                    //~v204R~
        if (lasterr==6)                                            //~v204I~
        {                                                          //~v204I~
//          if (Pid)                                               //~v241R~
//            printf("\nGetConsoleMode(STD_OUTPUT) failed(redirect)\n");//~v241R~
//          else                                                   //~v241R~
//            printf("\nGetConsoleMode(STD_INPUT) failed(redirect)\n");//~v241R~
            if (!Pid)	//stdin                                    //~v253I~
            	UTRACEP("\n%s:GetConsoleMode(STD_INPUT) failed(redirect)\n",UTT);//~v253I~//+v6VuR~
            oldmode=0xffffffff;                                    //~v204I~
        }                                                          //~v204I~
        else                                                       //~v204I~
	  if (Pid)                                                     //~v141I~
		uerrapi1x("GetConsoleMode","STD_OUTPUT",GetLastError());   //~v141I~
	  else                                                         //~v141I~
		uerrapi1x("GetConsoleMode","STD_INPUT",GetLastError());    //~v034M~
    }                                                              //~v204I~
	return oldmode;                                                //~v034M~
}//ugetconsolemode                                                 //~v034M~
//*******************************************************          //~v034M~
//*win set console mode                                            //~v034M~
//*may called before w95init                                       //~v034M~
//*parm1:id of in/out  0:input,1:output                            //~v141I~
//*parm2 :set mode                                                 //~v141I~
//ret:previous mode                                                //~v034M~
//*******************************************************          //~v034M~
//UINT usetconsolemode(int Pid,UINT Pmode)                           //~v141R~//~v6hdR~
DWORD usetconsolemode(int Pid,UINT Pmode)                          //~v6hdI~
{                                                                  //~v034M~
//  UINT oldmode;                                                  //~v034M~//~v6hdR~
    DWORD oldmode;                                                 //~v6hdI~
	HANDLE hstdin;                                                 //~v034M~
//******************                                               //~v034M~
  if (Pid)                                                         //~v141I~
	hstdin=ugetstdhandle(STD_OUTPUT_HANDLE);                       //~v141I~
  else                                                             //~v141I~
	hstdin=ugetstdhandle(STD_INPUT_HANDLE);                        //~v034M~
//  if (!GetConsoleMode(hstdin,&oldmode))                          //~v141R~
//  	uerrapi1x("GetConsoleMode","STD_INPUT",GetLastError());    //~v141R~
    oldmode=ugetconsolemode(Pid);                                  //~v141I~
//UTRACEP("GetConsoleMode %08x\n",oldmode);                        //~v139R~
	if (!SetConsoleMode(hstdin,Pmode))                             //~v034M~
    {                                                              //~v5ncI~
	  if (Pid)                                                     //~v141I~
		uerrapi1x("SetConsoleMode","STD_OUTPUT",GetLastError());   //~v141I~
	  else                                                         //~v141I~
		uerrapi1x("SetConsoleMode","STD_INPUT",GetLastError());    //~v034M~
    }                                                              //~v5ncI~
//UTRACEP("SetConsoleMode %08x\n",Pmode);                          //~v139R~
	return oldmode;                                                //~v034M~
}//usetconsolemode                                                 //~v034M~
//*******************************************************          //~v5maI~
//*win set console mode                                            //~v5maI~
//*ret rc;                                                         //~v5maI~
//*******************************************************          //~v5maI~
int usetconsolemode2(int Popt,int Pid,UINT Pmode,UINT *Ppoldmode)  //~v5maI~
{                                                                  //~v5maI~
	HANDLE hstdin;                                                 //~v5maI~
    int rc=0;                                                      //~v5maI~
//******************                                               //~v5maI~
  	if (Pid)                                                       //~v5maI~
		hstdin=ugetstdhandle(STD_OUTPUT_HANDLE);                   //~v5maI~
  	else                                                           //~v5maI~
		hstdin=ugetstdhandle(STD_INPUT_HANDLE);                    //~v5maI~
    if (Ppoldmode)                                                 //~v5maI~
    	*Ppoldmode=ugetconsolemode(Pid);                           //~v5maI~
UTRACEP("usetconsoldemode2 oldmode=%08x\n",ugetconsolemode(Pid));  //~v5maR~
	if (!SetConsoleMode(hstdin,Pmode))                             //~v5maI~
    {                                                              //~v5maI~
		rc=GetLastError();                                         //~v5maI~
    	if (Popt & USCM_ERREXIT) //errexit if err                  //~v5maR~
		  	if (Pid)                                               //~v5maI~
				uerrapi1x("SetConsoleMode","STD_OUTPUT",rc);       //~v5maI~
	  		else                                                   //~v5maI~
				uerrapi1x("SetConsoleMode","STD_INPUT",rc);        //~v5maI~
        else                                                       //~v5maM~
		  	if (Pid)                                               //~v5maM~
				uerrapi1("SetConsoleMode","STD_OUTPUT",rc);        //~v5maM~
	  		else                                                   //~v5maM~
				uerrapi1("SetConsoleMode","STD_INPUT",rc);         //~v5maM~
    }                                                              //~v5maI~
UTRACEP("SetConsoleMode %08x,rc=%d\n",Pmode,rc);                   //~v5maI~
	return rc;                                                     //~v5maR~
}//usetconsolemode2                                                //~v5maI~
#ifndef WXE                                                        //~v570I~
//**************************************************               //~v034M~
//*ureadconsole                                                    //~v034M~
//*read console api                                                //~v034M~
//*parm1:receive area                                              //~v034M~
//*parm2:receive len                                               //~v034M~
//*parm3:output read counter area                                  //~v034M~
//*rc   :none                                                      //~v034M~
//**************************************************               //~v034M~
void ureadconsole(char *Parea,int Pilen,int *Polen)                //~v034M~
{                                                                  //~v034M~
	DWORD readlen;                                                 //~v6hdI~
//*******************                                              //~v034M~
//  printf("readconsole req\n");                                 //+6A22M~//~v034M~
//  if (Stracesw & 0x01)                                           //~v298R~
    if (Stracesw2)                                                 //~v298I~
  		ukbd_w95trace("ReadCosole:before",0);                                   //~6A22R~//~v139R~
	if (ReadConsole(Shstdin,		//advance read ptr             //~v034M~
    				Parea,          //receive area                 //~v034M~
//  				Pilen,			//request count                //~v034M~//~v6hdR~
    				(DWORD)Pilen,			//request count        //~v6hdI~
//                  Polen,    		//out ctr                      //~v034M~//~v6hdR~
                    &readlen, 		//out ctr                      //~v6hdI~
					0)				//reserved                     //~v034M~
		==FALSE)                                                   //~v034M~
		uerrapi1x("ReadConsole","STD_INPUT",GetLastError());       //~v034M~
//  printf("ReadConsole: %02x,ilen=%d,olen=%d\n",*Parea,Pilen,*Polen);//~6A22I~//~v034M~
//  if (Stracesw & 0x01)                                           //~v298R~
    if (Stracesw2)                                                 //~v298I~
		ukbd_w95trace("ReadConsole:after",Parea);                                   //~6A22R~//~v139R~
    *Polen=(int)readlen;                                           //~v6hdI~
	return;                                                        //~v034M~
}//ureadconsole                                                    //~v034M~
//**************************************************               //~v65dI~
//*uwriteconsoleinput                                              //~v65dI~
//*insert record to last not yet processed                         //~v65dI~
//*rc   :bool                                                      //~v65dI~
//**************************************************               //~v65dI~
int uwriteconsoleinput(int Popt,PINPUT_RECORD Pinprec,int Pilen,int *Polen)//~v65dI~
{                                                                  //~v65dI~
	int rc;                                                        //~v65dI~
    DWORD writelen;                                                //~v6hdI~
//*******************                                              //~v65dI~
	rc=WriteConsoleInput(Shstdin,		//advance read ptr         //~v65dI~
    				Pinprec,        //write   area                 //~v65dR~
//  				Pilen,			//request count                //~v65dI~//~v6hdR~
    				(DWORD)Pilen,			//request count        //~v6hdI~
//                  Polen);    		//out ctr                      //~v65dI~//~v6hdR~
                    &writelen);    		//out ctr                  //~v6hdI~
	if (rc==FALSE)                                                 //~v65dI~
		uerrapi1("WriteConsoleInput","STD_INPUT",GetLastError());  //~v65dI~
    *Polen=(int)writelen;                                          //~v6hdI~
	return rc;                                                     //~v65dI~
}//uwriteconsoleinput                                              //~v65dI~
#endif 	//!WXE                                                     //~v570I~
//**************************************************               //~v034M~
//*ureadconsoleinput                                               //~v034M~
//*read console input api                                          //~v034M~
//*parm1:receive area                                              //~v034M~
//*parm2:receive len                                               //~v034M~
//*parm3:output read counter area                                  //~v034M~
//*rc   :none                                                      //~v034M~
//**************************************************               //~v034M~
void ureadconsoleinput(PINPUT_RECORD Pinprec,int Pilen,int *Polen) //~v034M~
{                                                                  //~v034M~
#ifndef WXE                                                        //~v6hdI~
	DWORD readlen;                                                 //~v6hdI~
#endif 	//!WXE                                                     //~v6hdI~
//*******************                                              //~v034M~
//  printf("readconsoleinput req\n");                                 //+6A22M~//~v034M~
//  if (Stracesw & 0x01)                                           //~v298R~
    if (Stracesw2)                                                 //~v298I~
		ukbd_w95trace("before",0);                                   //~6A22R~//~v139R~
#ifdef WXE                                                         //~v570I~
	wxe_readkbd(Pinprec,Polen);		//set from keyup/down WMmsg    //~v570I~
#else                                                              //~v570I~
  if (Swcstat & UDCWCIO_WIDEAPI)                                   //~v5n8R~
  {                                                                //~v5n8I~
	if (ReadConsoleInputW(Shstdin,                                 //~v5n8I~
        					Pinprec,                               //~v5n8I~
//        					Pilen,			//request count        //~v5n8I~//~v6hdR~
          					(DWORD)Pilen,			//request count//~v6hdI~
//                          Polen)                                 //~v5n8I~//~v6hdR~
                            &readlen)                              //~v6hdI~
		==FALSE)                                                   //~v5n8I~
		uerrapi1x("ReadConsoleInputW","STD_INPUT",GetLastError()); //~v5n8I~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
	if (ReadConsoleInput(Shstdin,                                  //~v034M~
        					Pinprec,                               //~v034M~
//      					Pilen,			//request count        //~v034M~//~v6hdR~
        					(DWORD)Pilen,			//request count//~v6hdI~
//                          Polen)                                 //~v034M~//~v6hdR~
                            &readlen)                              //~v6hdI~
		==FALSE)                                                   //~v034M~
		uerrapi1x("ReadConsoleInput","STD_INPUT",GetLastError());  //~v034M~
	*Polen=(int)readlen;                                           //~v6hdM~
#endif 	//!WXE                                                     //~v570I~
    if (Stracesw)                                                  //~v034M~
		UTRACEPF("%s:ReadConsoleInput: %04x,%08x,%04x-%04x,%04x-%04x,ucs=%04x,%08x(ilen=%d,olen=%d)\n",UTT,//~6A22I~//~v5n8R~//~v6VuR~
            	(UINT)Pinprec->EventType,                                //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.bKeyDown,                  //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.wRepeatCount,              //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.wVirtualKeyCode,           //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.wVirtualScanCode,          //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.uChar.AsciiChar,           //~6A22R~//~v034M~
            	(UINT)Pinprec->Event.KeyEvent.uChar.UnicodeChar,   //~v5n8I~
            	(UINT)Pinprec->Event.KeyEvent.dwControlKeyState,   //~v034M~
            	Pilen,*Polen);                                     //~v034M~
//  if (Stracesw & 0x01)                                           //~v298R~
    if (Stracesw2)                                                 //~v298I~
		ukbd_w95trace("after",Pinprec);                                   //~6A22R~//~v139R~
	return;                                                        //~v034M~
}//ureadconsole                                                    //~v034M~
                                                                   //~v022I~
//**************************************************               //~v139M~
//*upeekconsoleinput                                               //~v139M~
//*peek console input api                                          //~v139M~
//*parm1:receive area                                              //~v139M~
//*parm2:req cntr                                                  //~v139M~
//*parm3:output peek result area                                   //~v139M~
//*rc   :none                                                      //~v139M~
//**************************************************               //~v139M~
void upeekconsoleinput(PINPUT_RECORD Pinprec,int Preqctr,int *Poutctr)//~v139M~
{                                                                  //~v139M~
#ifndef WXE                                                        //~v6hdI~
	DWORD readlen;                                                 //~v6hdI~
#endif                                                             //~v6hdI~
//*******************                                              //~v139M~
#ifdef WXE                                                         //~v570I~
	wxe_peekkbd(Pinprec,Poutctr);		//set from keyup/down WMmsg//~v570R~
#else                                                              //~v570I~
  if (Swcstat & UDCWCIO_WIDEAPI)                                   //~v5n8R~
  {                                                                //~v5n8I~
	if (!PeekConsoleInputW(Shstdin,                                //~v5n8I~
        					Pinprec,                               //~v5n8I~
//      					Preqctr,		//request count        //~v5n8I~//~v6hdR~
        					(DWORD)Preqctr,		//request count    //~v6hdI~
//                          Poutctr))                              //~v5n8I~//~v6hdR~
                            &readlen))                             //~v6hdI~
		uerrapi1x("PeekConsoleInputW","STD_INPUT",GetLastError()); //~v5n8I~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
	if (!PeekConsoleInput(Shstdin,                                 //~v139M~
        					Pinprec,                               //~v139M~
//      					Preqctr,		//request count        //~v139M~//~v6hdR~
        					(DWORD)Preqctr,		//request count    //~v6hdI~
//                          Poutctr))                              //~v139M~//~v6hdR~
                            &readlen))                             //~v6hdI~
		uerrapi1x("PeekConsoleInput","STD_INPUT",GetLastError());  //~v139M~
	*Poutctr=(int)readlen;                                         //~v6hdM~
#endif 	//!WXE                                                     //~v570I~
    if (Stracesw)                                                  //~v139M~
		UTRACEPF("%s:ReadConsoleInput: %04x,%08x,%04x-%04x,%04x-%04x,ucs=%04x,%08x(ilen=%d,olen=%d)\n",UTT,//~v5n8R~//~v6VuR~
            	(UINT)Pinprec->EventType,                          //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.bKeyDown,            //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.wRepeatCount,        //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.wVirtualKeyCode,     //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.wVirtualScanCode,    //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.uChar.AsciiChar,     //~v139M~
            	(UINT)Pinprec->Event.KeyEvent.uChar.UnicodeChar,   //~v5n8I~
            	(UINT)Pinprec->Event.KeyEvent.dwControlKeyState,   //~v139M~
            	Preqctr,*Poutctr);                                 //~v139M~
	return;                                                        //~v139M~
}//upeekconsoleinput                                               //~v139M~
                                                                   //~v139I~
//**************************************************               //~v139M~
//*ugetinputeventno                                                //~v139M~
//*get console event number not yet read                           //~v139M~
//*parm :none                                                      //~v139M~
//*rc   :eventno                                                   //~v139M~
//**************************************************               //~v139M~
int ugetinputeventno(void)                                         //~v139M~
{                                                                  //~v139M~
//  int eventno;                                                   //~v139M~//~v6hdR~
    DWORD eventno;                                                 //~v6hdI~
//*******************                                              //~v139M~
  #ifdef WXE                                                       //~v570R~
    wxe_geteventno(&eventno);                                      //~v570I~
  #else                                                            //~v570I~
    if (!GetNumberOfConsoleInputEvents(Shstdin,&eventno))          //~v139M~
		uerrapi1x("GetNumberOfConsoleInputEvents","STD_INPUT",GetLastError());//~v139M~
  #endif                                                           //~v570I~
    if (Stracesw)                                                  //~v139M~
		UTRACEPF("%s:GetNumberOfConsoleInputEvents: %d\n",UTT,eventno);     //~v139M~//~v6VuR~
	return eventno;                                                //~v139M~
}//ugetinputeventno                                                //~v139R~
                                                                   //~v139I~
//**************************************************               //~v034M~
//*ukbd_w95traceinit                                               //~v034M~
//*trace option set                                                //~v034M~
//*parm1:option(1:w95trace on,2:w95trace by UTRACE only(no printf))//~v298R~
//*             other nonzero:printf)                              //~v298I~
//*rc   :none                                                      //~v034M~
//**************************************************               //~v034M~
void ukbd_w95traceinit(int Popt)                                   //~v034M~
{                                                                  //~v034M~
//**************                                                   //~v034M~
        if (Stracesw && !Popt)                                     //~v034I~
    		ukbd_w95trace("",0);                                   //~v139R~
    Stracesw=Popt & ~KBD_UTRACE;                                   //~v298R~
    Stracesw2=Popt & (KBD_PTRACE|KBD_UTRACE);                      //~v298I~
}//ukbd_w95traceinit                                               //~v034M~
                                                                   //~v034M~
//**************************************************            //~5104I~
//*ukbd_w95setstatus                                               //~v137R~
//*set kbd status(binary mode,shift report etc)                 //~5104I~
//*parm1:KBDINFO addr                                           //~5104I~
//*rc   :0 or 504(ERROR_KBD_EXTENDED_SG)                        //~5104I~
//**************************************************            //~5104I~
int ukbd_w95setstatus(PKBDINFO Ppkbdinfo)                          //~v137R~
{                                                               //~5104I~
#ifndef WXE                                                        //~v570I~
    	UINT	mode;                                              //~v137R~
    	USHORT	mask;                                              //~v034I~
#endif //!WXE                                                      //~v570I~
//***************************************                       //~5104I~
#ifndef WXE                                                        //~v570I~
  		mask=Ppkbdinfo->fsMask;                                    //~v034I~
        mode=0;                                                    //~v034I~
        if (mask & KEYBOARD_ECHO_ON)                               //~v034I~
        	mode|= ENABLE_ECHO_INPUT;                              //~v034I~
        if (mask & KEYBOARD_ECHO_OFF)                              //~v034I~
        	mode&=~ENABLE_ECHO_INPUT;                              //~v034I~
        if (mask & KEYBOARD_BINARY_MODE)                           //~v034I~
        	mode&=~ENABLE_PROCESSED_INPUT;                         //~v034I~
        if (mask & KEYBOARD_ASCII_MODE)                            //~v034I~
        	mode|= ENABLE_PROCESSED_INPUT;                         //~v034I~
		usetconsolemode(0,mode);	//std input                    //~v141R~
#endif //!WXE                                                      //~v5biI~
		Skbdinfo=*Ppkbdinfo;                                    //~5104I~
//#endif //!WXE                                                    //~v5biR~
		Sshiftreprtsw=(Skbdinfo.fsMask & KEYBOARD_SHIFT_REPORT);   //~v146I~
	return 0;                                                      //~v137R~
}//ukbd_w95setstatus                                               //~v137R~
//**************************************************               //~v186I~
//*ukbd_w95forcent                                                 //~v186I~
//*force NT mode kbd input process(no DBCS accept)                 //~v186I~
//*parm :none                                                      //~v186I~
//*rc   :none                                                      //~v186I~
//**************************************************               //~v186I~
void ukbd_w95forcent(void)                                         //~v186I~
{                                                                  //~v186I~
//***************************************                          //~v186I~
	Sforcentsw=1;                                                  //~v186I~
	return;                                                        //~v186I~
}//ukbd_w95forcent                                                 //~v186I~
//**************************************************               //~v5n8I~
//*ukbd_localeinit                                                 //~v5n8I~
//*parm :none                                                      //~v5n8I~
//*rc   :none                                                      //~v5n8I~
//**************************************************               //~v5n8I~
int ukbd_wcinit(int Popt,ULONG Pcodepage)                          //~v5n8I~
{                                                                  //~v5n8I~
//***************************************                          //~v5n8I~
	Scodepage=Pcodepage;                                           //~v5n8I~
    Swcstat|=Popt;                                                 //~v5n8R~
    if (Swcstat & UDCWCIO_WIDEAPI)                                 //~v5n8R~
	    if (!(Swcstat & UDCWCIO_KBDUNICODE))                       //~v5n8R~
	    	Swcstat|=UDCWCIO_KBDMBS;   //return mbstring           //~v5n8R~
    UTRACEP("kbd wcinit stat=%x\n",Swcstat);                       //~v5n8I~
#ifdef WXE                                                         //~v5n8I~
	wxe_kbdwcinit(0,Swcstat,Scodepage);		//notify to wxe        //~v5n8R~
#endif                                                             //~v5n8I~
    return 0;                                                      //~v5n8I~
}//ukbd_wcinit                                                     //~v5n8I~
//**************************************************               //~v5n8I~
//*ukbd unicode to multibyte                                       //~v5n8R~
//**************************************************               //~v5n8I~
int ukbd_u2m(int Popt,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)      //~v5n8R~
{                                                                  //~v5n8I~
	int mbslen,rc;                                                 //~v5n8R~
//***************************************                          //~v5n8I~
//  rc=ucvext_winucs2cp1(0,Scodepage,Pucs,Ppmbs,&mbslen);          //~v5n8I~//~v6BjR~
    rc=ucvext_winucs2cp1(0,Scodepage,(UWUCS)Pucs,Ppmbs,&mbslen);   //~v6BjR~
	if (rc>1)                                                      //~v5n8I~
    {                                                              //~v5n8I~
    	mbslen=1;                                                  //~v5n8I~
        *Ppmbs=CHAR_ASCII_ERR;                                     //~v5n8I~
    }                                                              //~v5n8I~
    *Ppoutlen=mbslen;                                              //~v5n8I~
UTRACEP("ukbd_u2m ucs=%x,mblen=%d,mb=%s\n",Pucs,mbslen,Ppmbs);     //~v62rI~
    return rc;                                                     //~v5n8I~
}//ukbd_u2m                                                        //~v5n8I~
//**************************************************               //~v6BeI~
//*ukbd unicode to multibyte                                       //~v6BeI~
//**************************************************               //~v6BeI~
int ukbd_simutf8_f2l(int Popt,char *Putf8,int Plen,char *Ppout,int Pbuffsz,int *Ppoutlen)//~v6BeR~
{                                                                  //~v6BeI~
	int opt2,repctr,rc,chklen,mbslen,ddlen;                        //~v6BeI~
	UCHAR wkdddata[4],wkdddbcs[4];                                 //~v6BeI~
    ULONG opt;                                                     //~v6BeI~
    char errrep;                                                   //~v6BeI~
//****************                                                 //~v6BeI~
    errrep=(char)Popt & UKSF2LO_ERRREPCH;                          //~v6BeR~
	opt=UCVUCS_ERRSTOP;                                            //~v6BeI~
    rc=ucvsutf2mb(NULL/*Perr*/,opt,Putf8,Plen,Ppout,Pbuffsz,&chklen,&mbslen,&repctr);//~v6BeI~
    if (rc)                                                        //~v6BeI~
    {                                                              //~v6BeI~
        opt2=0;                                                    //~v6BeI~
        utfcvf2dd(opt2,Putf8,Plen,wkdddata,wkdddbcs,(int)sizeof(wkdddata),&ddlen);//~v6BeI~
        *Ppout=errrep;   //?                                       //~v6BeR~
        *(Ppout+1)=errrep;   //?                                   //~v6BeR~
        mbslen=ddlen;                                              //~v6BeI~
    }                                                              //~v6BeI~
    *Ppoutlen=mbslen;                                              //~v6BeI~
    UTRACED("out mbs",Ppout,mbslen);                               //~v6BeI~
    return rc;                                                     //~v6BeI~
}//ukbdw_simutf8_f2l                                               //~v6BeR~
