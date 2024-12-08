//*CID://+vbAnR~:                             update#=   44;       //+vbAnR~
//******************************************************
//vbAn:240627 for performance bypass glyphchk when help            //+vbAnI~
//v7c7:240624 (W32) treate glyph width=0 for category Cf(Format, 200d:ZWJ etc)//~v7c7I~
//vbzZ:240503 LNX:del vbzY because wcwidth()=1 is same as -G1      //~vbzZI~
//vbzY:240503 LNX:use wcwidth() for ambiguous when -gN and allow specification to ambig lang//~vbzYI~
//v7be:240327 optionally chk glyph width by also TextDraw          //~v7beI~
//v7bd:240327 test function to chk char both extent and textDraw   //~v7bdI~
//v7b8:240324 try to chk glyph width by extent for not ambiguous   //~v7b8I~
//v7b5:240322 (Win)Sconouttemp to gbl for uvtest6 etc              //~v7b5I~
//v7b1:240320 for ucs4(>=ENTNO) HDC should not be closed           //~v7b0R~
//v7b0:240320 (W32) test function for uvtest6 output charwidth and is wide//~vbzzI~
//vbzz:240311 arrange vbz3,vbzp:/Yv and vbzy:YL to /Gv[L]          //~v7aqI~
//v7ag:240301 (LNXCON)like as v7ad(WINCON),chk glyph width for F2C1//~v7aqI~
//vbzq:240228 (W32:Console) /Ffontname[:charset] for WindowsTerminal//~vbzqI~
//v7a7:240226 (W32 console)for /Yv,evaluate griph width for ambiguous using DrawTextW(not GetTextExtentPointW,GetCharWidth32,GetABCWidthsW)//~v7a7I~
//v796:240118 W32:try to chk cursor step for cpu8 file.            //~v796I~
//            Adjust culumn width by uftwcwidth for cursor width is single column to avoid column string move by cursor position//~v796I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//v156:980126 ugetconhwnd:get console appl HWND                    //~v156I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v044I~
//            but video mode.video buff chk by int 10 ah=FE        //~v044I~
//            (none is displayed under os2 dos session when changed chev us)//~v044I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
#ifdef UVIO2_GBLDEF                                                //~v7a7I~
    int Guvio2Stat;                                                //~v7a7I~
    int Guvio2Info;                                                //~vbzzI~
	HANDLE GhconoutTemp;                                           //~v7b5I~
#else                                                              //~v7a7I~
    extern int Guvio2Stat;                                         //~v7a7I~
    extern int Guvio2Info;                                         //~v7b0R~
	extern HANDLE GhconoutTemp;                                    //~v7b5I~
#endif                                                             //~v7a7I~
//#ifdef W32                                                         //~v7a7I~//~v7aqR~
#if defined(W32) || defined(LNXCON)                                //~v7aqR~
	#define UVIO2S_CONSOLE_MONOFONT          0x0001                //~v7a7I~
#endif                                                             //~v7a7I~
	#define UVIO2S_AMBIG_SBCS                0x0002  //default off:WIDE//~vbzzR~
	#define UVIO2S_AMBIG_UNP                 0x0004  //unprintable all unbiguous//~vbzzR~
	#define UVIO2S_NO_FONTCLOSE              0x0100  //test skip close, to getglyph width after mapinit//~vbzzR~
	#define UVIO2S_TESTWCW                   0x0200  //for test    //~v7bdI~
	#define UVIO2S_DRAWTEXTALL               0x0400  //chk glyph width by TextDraw for not ambiguous//~v7beI~
//    #define UVIO2S_USEAPI                    0x0800  //chk glyph width by TextDraw for not ambiguous//~vbzYR~//~vbzZR~
//    #define UVIO2S_USEAPI_AMBIGLANG          0x1000                //~vbzYR~//~vbzZR~
	#define UVIO2S_NOGLYPHCHK                0x0800  //no glyph chk for /help option//+vbAnI~
#ifdef LNXCON                                                      //~v7aqI~
    #define LF_FACESIZE 128                                        //~v7aqI~
#endif                                                             //~v7aqI~
    #define UVIO2SI_MASK_WWGLYPH         0xff   //outout char width//~v7b0R~
    #define UVIO2SI_MASK_HHFONT        0xff00 //outout char width  //~v7b0R~
    #define UVIO2SI_MASK_ISWIDE      0x010000 //outout char width  //~v7b0R~
#ifdef W32                                                         //~v044I~
//*******************************************************          //~v044M~
//void uvio2_init(HANDLE Phconout);                                //~v5fhR~
void uvio2_init(HANDLE Phconout,int Stoplineoffs);                 //~v5fhI~
                                                                   //~v044I~
//*******************************************************          //~v022I~
HANDLE ugetstdhandle(int Pid);                                     //~v022R~
                                                                   //~v044I~
//*******************************************************          //~v252I~
HANDLE uviowincreatecsb(int Popt);                                 //~v252I~
                                                                   //~v252I~
#endif                                                             //~v022I~
                                                                   //~v044I~
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol);
                                                                   //~v044I~
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol);
                                                                   //~v044I~
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo);
                                                                   //~v044I~
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo);
                                                                   //~v044I~
//*******************************************************
UINT uviowrttty(PCH pch,int Plen);
                                                                   //~v044I~
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk);
                                                                   //~v044I~
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk);
                                                                //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrolldn(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell);//~5222I~
                                                                //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrollup(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell);//~5222R~
                                                                   //~v044I~
//*******************************************************          //~v044I~
int uvio_dosgetvbuff(UCHAR **Ppvbuff);                             //~v044I~
                                                                   //~v156I~
//#ifdef W32                                                         //~v156I~//~v7aqR~
#if defined(W32) || defined(LNXCON)                                //~v7aqR~
//********************************************************************///~v156I~
#ifdef W32                                                         //~v7aqI~
//ULONG ugetconhwnd(void);                                           //~v156R~//~v6hhR~
ULPTR ugetconhwnd(void);                                           //~v6hhI~
#endif                                                             //~v7aqI~
int uvioGetCursorWidth(int Popt,ULONG Pucs);                       //~v796R~
#define UVGCWO_OPEN     0x01        //open  consolebuffer handle   //~v796R~
#define UVGCWO_CLOSE    0x02        //close consolebuffer handle   //~v796I~
#define UVGCWO_FORCE    0x04        //force close                  //~v7b1R~
#define UVGCWO_NOAMB    0x10        //chk fo non ambiguous char    //~v7b8I~
#define UVGCWO_RETW0    0x20        //return width=0               //~v7c7I~
//*******************************                                  //~v7a7I~
//void setConsoleFont(char *Pfontface);                              //~v7a7I~//~vbzqR~
void setConsoleFont(char *Pfontface);                              //~vbzqR~
#endif                                                             //~v156I~
