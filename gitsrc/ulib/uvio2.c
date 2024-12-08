//CID://+v7d0R~:       update#= 461                                //+v7d0R~
//*************************************************************
//v7d0:240801 errmsg by printf missing EOL                         //+v7d0I~
//v7ca:240628 (gxe) hardcopy support                               //~v7caI~
//v7c9:240628 (W32) print fontname selected at termination         //~v7c9I~
//vbAn:240627 for performance bypass glyphchk when help            //~vbAnI~
//v7c7:240624 (W32) treate glyph width=0 for category Cf(Format, 200d:ZWJ etc)//~v7c7I~
//v7c1:240605 (LNX)additional to v7c0, outsource to external shell for later linux update//~v7c1I~
//v7c0:240603 (LNX)font by dconf cmd,consider multiple profile(use not "dconf dump" but "dconf read")//~v7c0I~
//v7bh:240402 update errmsg for dconf failed                       //~v7bhI~
//v7bg:240401 (LNX)dconf failed if sudo xe.                        //~v7bgI~
//v7be:240327 optionally chk glyph width by also TextDraw          //~v7beI~
//v7bd:240327 test function to chk char both extent and textDraw   //~v7bdI~
//v7bc:240326 Win: use utf16 for windows api for ucs4              //~v7bcI~
//v7bb:240326 It should not use mblen it depends locale, for unicode file it have to depend font.//~v7bbI~
//v7b8:240324 try to chk glyph width by extent for not ambiguous   //~v7b8I~
//v7b7:240324 change wide glyph determination from TextDraw-->Extent.//~v7b7I~
//            About all of wide by extent is wide by draw and ExtentPoint api performance is rather good over TextDraw.//~v7b7I~
//vbzC:240323 /Ffontname parm; suuport \uxxxx specification        //~vbzCI~
//v7b5:240322 (Win)Sconouttemp to gbl for uvtest6 etc              //~v7b5I~
//v7b4:240321 (Win)if non monofont was set,cretae font failed by Arial was set after cretaefont//~v7b4I~
//v7b1:240320 for ucs4(>=ENTNO) HDC should not be closed           //~v7b1I~
//v7ax:240318 (LNX)0c4 by pango_font_description_get_family return s null//~v7awI~
//v7aw:240318 (LNX)chk glyph width for #Lo(Other Letter):wcwidth=0 //~v7awI~
//v7ar:240315 (BUG)v7a8 should not to use UTF option               //~v7arI~
//v7aq:240315 WINCON;try to get console font by reading settings.json//~v7aqI~
//v7an:240314 try to get console font by dconf cmd                 //~v7anI~
//v7aj:240309 utfcvl2u, apply STRZ option                          //~v7ajI~
//v7ai:240308 (WINCON)glyph width by DrawText(GetCharWidth is always half of height)//~v7aiI~
//v7ag:240301 (LNXCON)like as v7ad(WINCON),chk glyph width for F2C1//~v7agI~
//v7ad:240301 (WINCON)fontparm(/F) accept utf8 encoding by /F8fontname[:charset]//~v7adI~
//vbzq:240228 (W32:Console) /Ffontname[:charset] for WindowsTerminal//~vbzqI~
//v7a7:240226 (W32 console)for /Yv,evaluate griph width for ambiguous using DrawTextW(not GetTextExtentPointW,GetCharWidth32,GetABCWidthsW)//~v7a7I~
//v79Q:240215 W32:drop v79N; errournous cursor movement. and not effective on file contents.//~v79QI~
//v79P:240213 W32:chk unprintable by GetFontUnicodeRanges; but ineffective for Console.//~v79PI~
//v79N:240213 (WindowsTerminal)Consoel API:SetConsoleCursorInfo) is not effective. usr VT cmd.//~v79NI~
//v796:240118 W32:try to chk cursor step for cpu8 file.            //~v796I~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v570:020824 wxe support                                          //~v570I~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//v156:980126 ugetconhwnd:get console appl HWND                    //~v156I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v151M~
//            but video mode.video buff chk by int 10 ah=FE        //~v151M~
//            (none is displayed under os2 dos session when changed chev us)//~v151M~
//v056:970119:for int10 ah=0e(tty write),not needed INT10X,INT10 is sufficiant.//~v056I~
//v053:970406:gcc version(control by DPMI)                         //~v053I~
//            -short size ont equal int size                       //~v053I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//           .scroll function not usefull for clear screen         //~v034R~
//            (dest position must not negative,so need twice half scroll)//~v034I~
//           .WriteConsoleOutput is not effective when full-screen mode//~v034I~
//            Output can be seen after when change active screen buffer//~v034I~
//            to another and returned.                             //~v034I~
//            (so use WriteConsoleOutputCharacter and WriteConsoleOutputAttribute)//~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*ugetstdhandle                                                   //~v044I~
//*uviogetcurtype/uviogetcurpos                                    //~v044R~
//*uviosetcurtype/uviosetcurpos                                    //~v044R~
//*uviowrttty                                                      //~v043I~
//*uviogetstate/uviosetsate
//*uvioscrolldn(back)/uvioscrollup(forward)                     //~5222I~
//*************************************************************
//v015:960211:(BUG)uviowrttty advance char ptr for DOS          //~6212I~
//951001:malloc uvio work at init(uvio_init,uvio_term)          //~5A01I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950513 write direct to b800 when english display mode 3      //~5513I~
//*       (int10 ax=1302 cause scroll up when write to row 25 col 80)//~5513I~
//*950222 scroll down/up                                        //~5222R~
//*941221 int 10 ax=1302 for english mode not but 1320          //~5222I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#ifndef LNX                                                        //~v7agI~
#ifdef DOS
	#include <dos.h>                                               //~v022R~
    #ifdef DPMI                                                    //~v151I~
    	#include <dpmi.h>                                          //~v151I~
    	#include <go32.h>                                          //~v151I~
    #endif                                                         //~v151I~
#else
	#ifdef W32                           //v3.6a                   //~v022M~
		#include <windows.h>	         //v1.3 add                //~v022M~
	#else                                //v3.6a                   //~v022M~
		#define INCL_BASE                                          //~v022R~
		#include <os2.h>                                           //~v022R~
    	#pragma stack16(8192)                                      //~v034I~
	#endif                                                         //~v022M~
#endif
#endif //!LNX                                                      //~v7agI~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <uvio.h>
#define UVIO2_GBLDEF                                               //~v7a7I~
#include <uvio2.h>                                                 //~v044I~
#ifndef LNX                                                        //~v7agI~
#include <uviom.h>                                                 //~v79NI~
#endif                                                             //~v7agI~
#include <ustring.h>                                               //~v044I~
#include <uedit.h>                                                 //~v044I~
#include <uedit2.h>                                                //~v7adI~
#include <uerr.h>                                                  //~v022I~
#include <utf.h>                                                   //~v792I~
#include <utf22.h>                                                 //~v7beI~
#include <utrace.h>                                                //~v151I~
#include <ualloc.h>                                                //~v79PI~
#include <uproc2.h>                                                //~v7a7I~
#include <ucvucs.h>                                                //~v7a7I~
#include <uproc.h>                                                 //~v7anI~
#include <ufile.h>                                                 //~v7aqI~
#ifdef DPMI                                                        //~v151I~
	#include <udpmisub.h>	//udpmiint86x                          //~v151I~
#endif                                                             //~v151I~
#ifdef WXE                                                         //~v570I~
	#include <wxexei.h>     //ukbd_w95init                         //~v570I~
#endif                                                             //~v570I~
#ifdef XXE                                                         //~v7caI~
	#include <xxexei.h>     //ukbd_w95init                         //~v7caI~
#endif                                                             //~v7caI~
//*******************************************************
int showFontWarning(int Popt/*1:fprintf,0:uerrmsg*/,char *Pmsg,int Pparm);//~v7bhM~
#ifdef LNX                                                         //~v7agR~
#ifdef LNXCON                                                      //~v7agI~
	#include <gtk/gtk.h>                                           //~v7agI~
	static char SconsoleFont[LF_FACESIZE]; //                      //~v7agI~
int getLinuxConsoleFont(int Popt,char *Ppfontface,int Pbuffsz);    //~v7anM~
#define GLCFO_MSG 0x01                                             //~v7anM~
                                                                   //~v7bhI~
#define DCONF_DUMP  "dconf dump /org/gnome/terminal/"              //~v7bhI~
#define DCONF_CMD  "dconf"                                         //~v7c0R~
#define DCONF_CMDHELP  DCONF_CMD " help"                           //~v7c0R~
#define DCONF_READ  DCONF_CMD " read /org/gnome/terminal/"         //~v7c0R~
#define DCONF_READ_DEFAULT_PROFILE "legacy/profiles:/default"      //~v7c0I~
#define DCONF_READ_DEFAULT_FONT    "legacy/profiles:/:%s/font"     //~v7c0R~
#define XEGETFONT_SH   "xeGetFont.sh"                              //~v7c1I~
#endif                                                             //~v7agI~
	int Sfonterr;                                                  //~v7c0I~
#else                                                              //~v7agI~
#ifdef WINCON                                                      //~v7aqI~
	int getW32ConsoleFont(int Popt,char *Ppfontface,int Pbuffsz,int *Ppsz,wchar_t *PpfaceW,int PbuffszW);//~v7aqR~
	#define GWCFO_MSG 0x01                                         //~v7aqI~
#endif                                                             //~v7aqI~
//*******************************************************
#ifdef DOS
	static	union 	REGS	Sreg;
    static	struct 	SREGS 	Ssegreg;                               //~v151R~
#else                                                              //~v022I~
	#ifdef W32                           //v3.6a                   //~v022I~
		static 	HANDLE  Shconout;		 //std  output console handle//~v022I~
		static 	int     Stoplineoffs;    //window top line in consolebuff//~v5fhI~
		static  HANDLE ShconoutTemp;                               //~v796R~
		static  int    ShconoutTempErr;                            //~v796R~
		static  CONSOLE_SCREEN_BUFFER_INFOEX Scsbi;                //~v796R~
        static int Scposx,Scposy;                                  //~v79NI~
		int  chkGlyph();                                           //~v79PI~
	#else                                //v3.6a                   //~v022I~
	#endif                                                         //~v022I~
#endif
static char SconsoleFont[LF_FACESIZE*2+2];                         //~v7a7I~
static HFONT SglyphFont;                                           //~v7a7I~
static int SfontH,SfontW;                                          //~v7a7R~
static int ScharsetParm=-1;                                        //~vbzqR~
static int ScharsetSelected;                                       //~v7c9R~
int uvioGetGlyphWidth(int Popt,ULONG Pucs);                        //~v7a7I~
#define TOPDIR "LOCALAPPDATA"                                  //~v7aqI~//~v7bhI~
#define SETTINGFILE "Packages\\*WindowsTerminal*\\LocalState\\settings.json"//~v7aqI~//~v7bhI~
#ifdef WINCON                                                      //~vbzCI~
int getfaceW(char *Pface,wchar_t *PpfaceW,int PbuffszW,char *PpfaceMB,int PbuffszMB);//~vbzCI~
#endif                                                             //~vbzCI~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void uvio2(void)                                                   //~v044R~
{
	return;
}

#ifdef W32                                                         //~v044M~
                                                                   //~v044I~
//*******************************************************          //~v044I~
//*init,receive handle from uvio                                   //~v044I~
//*parm1:stdout handle                                             //~v044I~
//*ret  :none                                                      //~v044I~
//*******************************************************          //~v044I~
//void uvio2_init(HANDLE Phconout)                                 //~v5fhR~
void uvio2_init(HANDLE Phconout,int Ptoplineoffs)                  //~v5fhI~
{                                                                  //~v044I~
	Shconout=Phconout;                                             //~v044I~
	Stoplineoffs=Ptoplineoffs;                                     //~v5fhI~
    UTRACEP("%s:Shconout=%p,toplineoffs=%d\n",UTT,Shconout,Ptoplineoffs);//~v7a7I~
//	chkGlyph();	//TODO test                                        //~v79PI~//~v7a7R~
	return;                                                        //~v044I~
}//uvio2_init                                                      //~v044R~
//*******************************************************          //~v022M~
//*get win95 console handle                                        //~v022M~
//*parm  :id(STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STR_ERROR_HANDLE)  //~v022M~
//*return:handle                                                   //~v022M~
//*******************************************************          //~v022M~
HANDLE ugetstdhandle(int Pid)                                      //~v022R~
{                                                                  //~v022M~
    HANDLE h;                                                      //~v022I~
//**********************                                           //~v022M~
    h=GetStdHandle(Pid);                                           //~v022R~
    if (h==INVALID_HANDLE_VALUE)                                   //~v022I~
		uerrapi1x("GetStdHandle",uitoa10(Pid),GetLastError());     //~v022R~
    return h;                                                      //~v022I~
}//ugetstdhandle                                                   //~v022I~
                                                                   //~v252I~
//*******************************************************          //~v252I~
//*get CreateConsoleScreenBuffer                                   //~v252I~
//*parm  :opt	1:issue errmsg                                     //~v252I~
//*return:handle                                                   //~v252I~
//*******************************************************          //~v252I~
HANDLE uviowincreatecsb(int Popt)                                  //~v252I~
{                                                                  //~v252I~
	HANDLE csbh;                                                   //~v252I~
//********                                                         //~v252I~
    csbh=CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,   //~v252I~
                 FILE_SHARE_READ | FILE_SHARE_WRITE,               //~v252I~
                 NULL,                                             //~v252I~
                 CONSOLE_TEXTMODE_BUFFER,                          //~v252I~
                 NULL);                                            //~v252I~
    if (csbh==INVALID_HANDLE_VALUE)                                //~v252I~
    	if (Popt)                                                  //~v252I~
        	printf("CreateConsoleScreenBuffer failed,LastError=%d",GetLastError());//~v252I~
    UTRACEP("%s:csbh=%p\n",UTT,csbh);                              //~v792I~
	return csbh;                                                   //~v252I~
}//uviowincreatecsb                                                //~v252I~
#ifndef WXE                                                        //~v792I~
//*******************************************************          //~v792I~
int copyFontInfo(HANDLE Pto)                                       //~v796R~
{                                                                  //~v796R~
	int rc;                                                        //~v796R~
    CONSOLE_FONT_INFOEX inf;                                       //~v796R~
	HANDLE hstdo=ugetstdhandle(STD_OUTPUT_HANDLE);                 //~v796R~
    if (hstdo==INVALID_HANDLE_VALUE)                               //~v796R~
    	return -1;                                                 //~v796R~
    inf.cbSize=sizeof(inf);                                        //~v796R~
    rc=GetCurrentConsoleFontEx(hstdo,FALSE/*maxsize*/,&inf);       //~v796R~
    if (!rc)                                                       //~v796R~
    	return -1;                                                 //~v796R~
    UTRACED("infoex stdout",&inf,sizeof(inf));                     //~v796R~
    rc=GetCurrentConsoleFontEx(Pto,FALSE/*maxsize*/,&inf);         //~v796R~
    if (!rc)                                                       //~v796R~
    	return -1;                                                 //~v796R~
    UTRACED("infoex Pto",&inf,sizeof(inf));                        //~v796R~
    rc=SetCurrentConsoleFontEx(Pto,FALSE/*maxsize*/,&inf);         //~v796R~
    if (!rc)                                                       //~v796R~
    	return -1;                                                 //~v796R~
    rc=GetCurrentConsoleFontEx(Pto,FALSE/*maxsize*/,&inf);         //~v796R~
    if (!rc)                                                       //~v796R~
    	return -1;                                                 //~v796R~
    UTRACED("infoex Pto aftercopy",&inf,sizeof(inf));              //~v796R~
    UTRACEP("%s:return",UTT);                                      //~v796R~
    return 0;                                                      //~v796R~
}                                                                  //~v796R~
#endif                                                             //~v796R~
#endif                                                             //~v022M~
                                                                   //~v022I~
//*******************************************************
//*VioGetCurPos
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_SCREEN_BUFFER_INFO csbi;                           //~v022I~
		APIRET16 apiret16;                                         //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	USHORT seg16usrow,seg16uscol;
	#pragma seg16(seg16usrow)
	#pragma seg16(seg16uscol)
	APIRET16 apiret16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;		//page no
	INT10(0x03);		//read cursor position
	*Pprow=Sreg.h.dh;
	*Ppcol=Sreg.h.dl;
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_getcurpos(Pprow,Ppcol);                   //~v570I~
      #else  //!WXE                                                //~v570I~
    	apiret16=(APIRET16)!GetConsoleScreenBufferInfo(Shconout,&csbi);//true/false//~v022R~
		*Ppcol=(int)csbi.dwCursorPosition.X;                       //~v022I~
//  	*Pprow=(int)csbi.dwCursorPosition.Y;                       //~v5fhR~
    	*Pprow=(int)(csbi.dwCursorPosition.Y-Stoplineoffs);        //~v5fhI~
        UTRACEP("%s:row=%d,col=%d\n",UTT,*Pprow,*Ppcol);           //~v79PR~
		return (UINT)apiret16;                                     //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	apiret16=VioGetCurPos(&seg16usrow,&seg16uscol,0);
	*Pprow=(int)seg16usrow;
	*Ppcol=(int)seg16uscol;
	return (UINT)apiret16;
	#endif                                                         //~v022I~
#endif
}//uviogetcurpos

//*******************************************************
//*VioSetCurPos
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol)
{
#ifdef DOS
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	COORD coord;                                               //~v022R~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;					//page no
	Sreg.h.dh=(UCHAR)Prow;
	Sreg.h.dl=(UCHAR)Pcol;
	INT10(0x02);					//set cursor pos
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_setcurpos(Prow,Pcol);                     //~v570I~
      #else  //!WXE                                                //~v570I~
    	coord.X=(SHORT)Pcol;                                       //~v022R~
//  	coord.Y=(SHORT)Prow;                                       //~v5fhR~
    	coord.Y=(SHORT)(Prow+Stoplineoffs);                        //~v5fhI~
        Scposx=Pcol; Scposy=Prow;                                  //~v79NI~
        UTRACEP("%s:row=%d,col=%d\n",UTT,Prow,Pcol);               //~v79PR~
        return !SetConsoleCursorPosition(Shconout,coord);          //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   return (UINT)VioSetCurPos((USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022I~
#endif
}//uviosetcurpos                                                   //~v022R~

//*******************************************************
//*VioGetCurType
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_CURSOR_INFO cci;                                   //~v022I~
		APIRET16 rc16;                                             //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	VIOCURSORINFO 	seg16cursorinfo1;
	#pragma seg16(seg16cursorinfo1)
	APIRET16 rc16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;		//page no
	INT10(0x03);		//read cursor position
	pvioCursorInfo->yStart	=(USHORT)Sreg.h.ch;
    pvioCursorInfo->cEnd	=(USHORT)Sreg.h.cl;
    pvioCursorInfo->cx		=0;
    pvioCursorInfo->attr	=0;
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_getcurtype(pvioCursorInfo);               //~v570R~
      #else  //!WXE                                                //~v570I~
    	rc16=(APIRET16)!GetConsoleCursorInfo(Shconout,&cci);       //~v022R~
        if (rc16)                                                  //~v034I~
//          rc16=uerrapi0("GetConsoleCursorInfo",GetLastError());  //~v034I~//~v6BiR~
            rc16=(USHORT)uerrapi0("GetConsoleCursorInfo",GetLastError());//~v6BiI~
		pvioCursorInfo->yStart	=(USHORT)cci.dwSize;//percentage(0-100)//~v022R~
	    pvioCursorInfo->cEnd	=0;                                //~v022I~
	    pvioCursorInfo->cx		=0;                                //~v022I~
	    if (cci.bVisible)                                          //~v022R~
		    pvioCursorInfo->attr=0;                                //~v022I~
		else                                                       //~v022I~
		    pvioCursorInfo->attr=(USHORT)-1;                       //~v034R~
		return (UINT)rc16;                                         //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   rc16=VioGetCurType (&seg16cursorinfo1,0);
   *pvioCursorInfo=seg16cursorinfo1;
   return (UINT)rc16;
	#endif                                                         //~v022I~
#endif
}//uviogetcurtype

#ifndef WXE                                                        //~v79NI~
//*******************************************************          //~v79NI~
//*for WindowsTerminal set cursor shape                            //~v79NI~
//*rc=0:done                                                       //~v79NI~
//*******************************************************          //~v79NI~
int VTsetCursorShape(CONSOLE_CURSOR_INFO *Ppcci)                   //~v79NI~
{                                                                  //~v79NI~
	int rc=0,sz;                                                   //~v79NI~
    char *escstr;                                                  //~v79NI~
//    char vintage[16];                                            //~v79NR~
//    COORD pos;                                                   //~v79NR~
//    CONSOLE_SCREEN_BUFFER_INFOEX csbi;                           //~v79NR~
static char *CSR_DEFAULT="\x1B[0 q";                               //~v79NR~
static char *CSR_BLOCK="\x1B[1 q";          //1:blink,2:stedy      //~v79NI~
static char *CSR_UNDERSCORE="\x1B[4 q";     //3:blink,4:stedy      //~v79NM~
//static char *CSR_VINTAGE="\x1B[7:%d q";     //vintage with bpercentage//~v79NR~
static char *CSR_VINTAGE="\x1B[7 q";     //vintage with bpercentage//~v79NI~
static char *CSR_SHOW="\x1B[?25h";                                 //~v79NM~
static char *CSR_HIDE="\x1B[?25l";                                 //~v79NM~
//static char *CSR_SAVE_POS="\x1B" "7";                            //~v79NR~
//static char *CSR_REST_POS="\x1B" "8";                            //~v79NR~
//*************************************                            //~v79NI~
    UTRACEP("%s:GoptWindowsTerminal=0x%x,IS_ON_TERMINAL=%d,csrSz=%d,csrPosY=%d,csrPosx=%d\n",UTT,GoptWindowsTerminal,IS_ON_TERMINAL(),Ppcci->dwSize,Scposy,Scposx);//~v79NR~
	if (IS_ON_TERMINAL())                                          //~v79NI~
    {                                                              //~v79NI~
//        csbi.cbSize=sizeof(csbi);                                //~v79NR~
//        if (GetConsoleScreenBufferInfoEx(Shconout,&csbi))        //~v79NR~
//        {                                                        //~v79NR~
//            UTRACEP("%s:csrpos before %d,%d\n",UTT,csbi.dwCursorPosition.X,csbi.dwCursorPosition.Y);//~v79NR~
//      	puts(CSR_SAVE_POS);                                    //~v79NR~
        	puts("\x1b[s");                                        //~v79NI~
			sz=Ppcci->dwSize;                                      //~v79NR~
//	    	escstr=sz>=50 ? CSR_BLOCK : CSR_UNDERSCORE;            //~v79NR~
  	    	escstr=sz>=50 ? CSR_BLOCK : CSR_DEFAULT;               //~v79NI~
//    	    sprintf(vintage,CSR_VINTAGE,sz);                       //~v79NR~
//      	puts(vintage);                                         //~v79NR~
        	puts(escstr);                                          //~v79NI~
            UTRACEP("%s:puts shape esc=%s\n",UTT,escstr);          //~v79PI~
//            UTRACED("vintage",vintage,sizeof(vintage));          //~v79NR~
        	escstr=Ppcci->bVisible ? CSR_SHOW : CSR_HIDE;          //~v79NR~
        	puts(escstr);                                          //~v79NR~
            UTRACEP("%s:puts visible esc=%s\n",UTT,escstr);        //~v79PR~
//      	puts(CSR_REST_POS);                                    //~v79NR~
//            GetConsoleScreenBufferInfoEx(Shconout,&csbi);        //~v79NR~
//            UTRACEP("%s:csrpos after %d,%d\n",UTT,csbi.dwCursorPosition.X,csbi.dwCursorPosition.Y);//~v79NR~
//            pos=csbi.dwCursorPosition;                           //~v79NR~
//            SetConsoleCursorPosition(Shconout,pos);              //~v79NR~
//            puts("\x1b[u");                                      //~v79NR~
//  		uviosetcurpos(Scposy,Scposx);                          //~v79NI~//~v79PR~
//        }                                                        //~v79NR~
    	rc=1;                                                      //~v79NI~
    }                                                              //~v79NI~
    return rc;                                                     //~v79NI~
}                                                                  //~v79NI~
#endif                                                             //~v79NI~
//*******************************************************
//*VioSetCurType
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_CURSOR_INFO cci;                                   //~v022I~
        UINT rc;                                                   //~v034I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	VIOCURSORINFO 	seg16cursorinfo2;
	#pragma seg16(seg16cursorinfo2)
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.ch			=(UCHAR)pvioCursorInfo->yStart;
    Sreg.h.cl			=(UCHAR)pvioCursorInfo->cEnd;
	INT10(0x01);						//set cursor type
	return 0;                                                   //~v013R~
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_setcurtype(pvioCursorInfo);               //~v570R~
      #else  //!WXE                                                //~v570I~
		cci.dwSize=pvioCursorInfo->yStart; //height percent        //~v034R~
		if (!pvioCursorInfo->attr)		//normal(visible)          //~v022R~
			cci.bVisible=1;                                        //~v022I~
		else                                                       //~v022I~
			cci.bVisible=0;   			//hidden                   //~v022I~
//      if (VTsetCursorShape(&cci))   //not Windows Terminal         //~v79NI~//~v79QR~
//        rc=0;                                                      //~v79NI~//~v79QR~
//      else                                                         //~v79NI~//~v79QR~
//      {                                                            //~v79NI~//~v79QR~
    	rc=!SetConsoleCursorInfo(Shconout,&cci);                   //~v034R~
        UTRACEP("%s:SetConsoleCursorInfo rc=%d(0:OK)\n",UTT,rc);   //~v79PI~
        if (rc)                                                    //~v034I~
            rc=uerrapi0("SetConsoleCursorInfo",GetLastError());    //~v034I~
//      }                                                            //~v79NI~//~v79QR~
		return rc;                                                 //~v034I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   seg16cursorinfo2=*pvioCursorInfo;
   return (UINT)VioSetCurType(&seg16cursorinfo2,0);
	#endif                                                         //~v022I~
#endif
}//uviosetcurtype

//*******************************************************
//*VioWrtTTY
//*******************************************************
UINT uviowrttty(PCH pch,int Plen)
{
#ifdef DOS
	int i;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		DWORD         len;                                         //~v022R~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	for (i=0;i<Plen;i++)
	{
		Sreg.h.al	=*pch++;                                    //~6212R~
		Sreg.h.bl	=0;						//parm for graphic		
//  	INT10X(0x0e);						//teletype write       //~v056R~
    	INT10(0x0e);						//teletype write       //~v056I~
	}
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
		return !WriteConsole(Shconout,pch,Plen,&len,NULL);         //~v022I~
    #else                                                          //~v022I~
   return (UINT)VioWrtTTY(pch,(USHORT)Plen,0);
	#endif                                                         //~v022I~
#endif
}//uviowrttty
//*******************************************************
//*uviogetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk)
{
#ifdef DOS
	int reqtype,i,max;
	PVIOPALSTATE ppal;
	PVIOOVERSCAN povs;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
//	reqtype=*((int*)Ppreqblk+1);                                   //~v053R~
  	reqtype=(int)(*((short*)Ppreqblk+1));                          //~v053I~
	switch(reqtype)
	{
	case 0:		//pallette reg get req
		ppal=Ppreqblk;
		if (ppal->cb < sizeof(VIOPALSTATE)
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)
			return ERROR_VIO_INVALID_LENGTH;
		if (ppal->iFirst > 15)
			return ERROR_VIO_INVALID_PARMS;
		max=(ppal->cb-sizeof(VIOPALSTATE))/2+1;
		for (i=0;i<max;i++)
		{
			Sreg.h.al=0x07;				//read each pallet reg
			Sreg.h.bl=(UCHAR)(ppal->iFirst+i);	//pallette reg number
			INT10(0x10);				//pallette reg
			ppal->acolor[i]=Sreg.h.bh;	//color reg of the pallette
		}//reg count
		break;
	case 1:		//overscan reg get req
		povs=Ppreqblk;
		Sreg.h.al=0x08;				//read overscan reg
		INT10(0x10);				//pallette reg
		povs->color=Sreg.h.bh;		//overscan reg value
		break;
	default:
		return ERROR_VIO_INVALID_PARMS;
	}//switch by reqtype
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
    	return (UINT)wxe_uviogetstate(Ppreqblk);                   //~v570I~
      #else  //!WXE                                                //~v570I~
		*(int*)Ppreqblk=0;                                         //~v022I~
    	return ERROR_VIO_EXTENDED_SG;   //not supported            //~v034R~
      #endif //!WXE                                                //~v570I~
	#else                                                          //~v022I~
   return (UINT)VioGetState(Ppreqblk,0);
	#endif                                                         //~v022I~
#endif
}//uvigetstate
                                                                //~5222I~
//*******************************************************
//*uviosetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk)
{
#ifdef DOS
	int reqtype,i,max;
	PVIOPALSTATE  ppal;
	PVIOOVERSCAN  povs;
	PVIOINTENSITY pint;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
//  reqtype=*((int*)Ppreqblk+1);                                   //~v053R~
    reqtype=(int)(*((short*)Ppreqblk+1));                          //~v053I~
	switch(reqtype)
	{
	case 0:		//pallette reg set req
		ppal=Ppreqblk;
		if (ppal->cb < sizeof(VIOPALSTATE)
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)
			return ERROR_VIO_INVALID_LENGTH;
		if (ppal->iFirst > 15)
			return ERROR_VIO_INVALID_PARMS;
		max=(ppal->cb-sizeof(VIOPALSTATE))/2+1;
		for (i=0;i<max;i++)
		{
			Sreg.h.al=0x00;				//set  each pallet reg
			Sreg.h.bl=(UCHAR)(ppal->iFirst+i);	//pallette reg number
			Sreg.h.bh=(UCHAR)ppal->acolor[i];	//color reg of the pallette
			INT10(0x10);				//pallette reg
		}//reg count
		break;
	case 1:		//overscan reg set req
		povs=Ppreqblk;
		Sreg.h.al=0x01;				//set  overscan reg
		Sreg.h.bh=(UCHAR)povs->color;		//overscan reg value
		INT10(0x10);				//pallette reg
		break;
	case 2:		//brink or highlight background
		pint=Ppreqblk;
		Sreg.h.al=0x03;				//set change brink/bg hilight
		Sreg.h.bl=(UCHAR)(!pint->fs);//overscan reg value 01:brink
		INT10(0x10);				//pallette reg
		break;
	default:
		return ERROR_VIO_INVALID_PARMS;
	}//switch by reqtype
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
    	return (UINT)wxe_uviosetstate(Ppreqblk);                   //~v570I~
      #else  //!WXE                                                //~v570I~
		*(int*)Ppreqblk=0;                                         //~v022I~
    	return 16;						//not supported            //~v022I~
      #endif //!WXE                                                //~v570I~
	#else                                                          //~v022I~
   return (UINT)VioSetState(Ppreqblk,0);
	#endif                                                         //~v022I~
#endif
}//uviosetstate                                                 //~5222R~
                                                                //~5222I~
//*******************************************************       //~5222I~
//*uvioscrolldn                                                 //~5222I~
//* scrool down(backward)                                       //~5222I~
//*parm:range (top left and bottom right)                       //~5222I~
//*    :scroll count(line count inserted to top)                //~5222I~
//*    :  if 0,full scroll                                      //~5222I~
//*    :insert line padding char and attr                       //~5222I~
//*    :   for dos char ignored and always space is written     //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrolldn(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)//~5222I~
{                                                               //~5222I~
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
    	SMALL_RECT srcrect;				//rectangular              //~v022I~
    	COORD      coorddest;				//x,y                  //~v022R~
    	CHAR_INFO  chi;                                            //~v022I~
	#endif                                                         //~v022I~
#endif                                                             //~v022I~
//*********************************                             //~5222I~
#ifdef DOS                                                      //~5222I~
	Sreg.h.al=(UCHAR)Pline;			//scroll count              //~5222I~
	Sreg.h.ch=(UCHAR)Ptoprow;		                            //~5222I~
	Sreg.h.cl=(UCHAR)Pleftcol;                                  //~5222I~
	Sreg.h.dh=(UCHAR)Pbottomrow;		                        //~5222I~
	Sreg.h.dl=(UCHAR)Prightcol;                                 //~5222I~
	Sreg.h.bh=*(Pcell+1);			//attr                      //~5222I~
	INT10(0x07);				//scroll down                   //~5222I~
	return Sreg.x.cflag;                                        //~5222I~
#else                                                           //~5222I~
	#ifdef W32                           //win95                   //~v022I~
    	srcrect.Right	=(SHORT)Prightcol;                         //~v022R~
//  	srcrect.Bottom	=(SHORT)Pbottomrow;                        //~v5fhR~
    	srcrect.Bottom	=(SHORT)(Pbottomrow+Stoplineoffs);         //~v5fhI~
    	srcrect.Left	=(SHORT)Pleftcol;                          //~v022R~
//    	srcrect.Top		=(SHORT)Ptoprow;                           //~v5fhR~
      	srcrect.Top		=(SHORT)(Ptoprow+Stoplineoffs);            //~v5fhI~
        coorddest.X     =(SHORT)Pleftcol;                          //~v022R~
//      coorddest.Y     =(SHORT)(Ptoprow+Pline);	//Pline down   //~v5fhR~
        coorddest.Y     =(SHORT)(Ptoprow+Pline+Stoplineoffs);	//Pline down//~v5fhI~
        chi.Char.UnicodeChar=0;                                    //~v022I~
        chi.Char.AsciiChar=*Pcell;			//insert space line    //~v022R~
        chi.Attributes    =(WORD)*(Pcell+1);                       //~v022R~
    	return !ScrollConsoleScreenBuffer(Shconout,                //~v022I~
        									&srcrect,	//move box //~v022R~
        									NULL,		//no clip  //~v022I~
        									coorddest,	//destination//~v022R~
                                            &chi);//fill cell      //~v022I~
    #else                                                          //~v022I~
    if (!Pline)             //0 line scroll                     //~5222I~
        Pline=-1;           //execute full line scroll          //~5222I~
  	return (UINT)VioScrollDn((USHORT)Ptoprow,(USHORT)Pleftcol,(USHORT)Pbottomrow,(USHORT)Prightcol,//~5222R~
								(USHORT)Pline,Pcell,0);         //~5222R~
	#endif                                                         //~v022I~
#endif                                                          //~5222I~
}//uvioscrolldn                                                 //~5222I~
                                                                //~5222I~
//*******************************************************       //~5222I~
//*uvioscrollup                                                 //~5222I~
//* scrool down(forward)                                        //~5222I~
//*parm:range (top left and bottom right)                       //~5222I~
//*    :scroll count(line count inserted to bottom)             //~5222I~
//*    :  if 0,full scroll                                      //~5222I~
//*    :insert line padding char and attr                       //~5222I~
//*    :   for dos char ignored and always space is written     //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrollup(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)//~5222R~
{                                                               //~5222I~
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
    	SMALL_RECT srcrect;				//rectangular              //~v022I~
    	COORD      coorddest;				//x,y                  //~v022R~
    	CHAR_INFO  chi;                                            //~v022I~
	#endif                                                         //~v022I~
#endif                                                             //~v022I~
//*********************************                             //~5222I~
#ifdef DOS                                                      //~5222I~
	Sreg.h.al=(UCHAR)Pline;			//scroll count              //~5222I~
	Sreg.h.ch=(UCHAR)Ptoprow;		                            //~5222I~
	Sreg.h.cl=(UCHAR)Pleftcol;                                  //~5222I~
	Sreg.h.dh=(UCHAR)Pbottomrow;		                        //~5222I~
	Sreg.h.dl=(UCHAR)Prightcol;                                 //~5222I~
	Sreg.h.bh=*(Pcell+1);			//attr                      //~5222I~
	INT10(0x06);				//scroll up                     //~5222I~
	return Sreg.x.cflag;                                        //~5222I~
#else                                                           //~5222I~
	#ifdef W32                           //win95                   //~v022I~
    	srcrect.Right	=(SHORT)Prightcol;                         //~v022R~
//  	srcrect.Bottom	=(SHORT)Pbottomrow;                        //~v5fhR~
    	srcrect.Bottom	=(SHORT)(Pbottomrow+Stoplineoffs);         //~v5fhI~
    	srcrect.Left	=(SHORT)Pleftcol;                          //~v022R~
//  	srcrect.Top		=(SHORT)Ptoprow;                           //~v5fhR~
    	srcrect.Top		=(SHORT)(Ptoprow+Stoplineoffs);            //~v5fhI~
        coorddest.X     =(SHORT)Pleftcol;                          //~v022R~
//      coorddest.Y     =(SHORT)(Ptoprow-Pline);	//Pline up     //~v5fhR~
        coorddest.Y     =(SHORT)(Ptoprow-Pline+Stoplineoffs);	//Pline up//~v5fhI~
        chi.Char.UnicodeChar=0;                                    //~v022I~
        chi.Char.AsciiChar=*Pcell;                                 //~v022R~
        chi.Attributes=(WORD)*(Pcell+1);                           //~v022R~
    	return !ScrollConsoleScreenBuffer(Shconout,                //~v022I~
        									&srcrect,	//move box //~v022R~
        									NULL,		//no clip  //~v022I~
        									coorddest,	//destination//~v022R~
                                            &chi);//fill cell      //~v022I~
    #else                                                          //~v022I~
    if (!Pline)             //0 line scroll                     //~5222I~
        Pline=-1;           //execute full line scroll          //~5222I~
  	return (UINT)VioScrollUp((USHORT)Ptoprow,(USHORT)Pleftcol,(USHORT)Pbottomrow,(USHORT)Prightcol,//~5222I~
								(USHORT)Pline,Pcell,0);         //~5222R~
	#endif                                                         //~v022I~
#endif                                                          //~5222I~
}//uvioscrollup                                                 //~5222I~
                                                                   //~v151I~
#ifdef DOS                                                         //~v151M~
//*******************************************************          //~v151M~
//*uvio_dosgetvbuff                                                //~v151M~
//*  get dos video buff                                            //~v151M~
//*parm1:optional output dos video buff ptr                        //~v151M~
//*return:rc  0:not real,1:real buff(b800:0)                       //~v151M~
//*******************************************************          //~v151M~
int uvio_dosgetvbuff(UCHAR **Ppvbuff)                              //~v151M~
{                                                                  //~v151M~
	int rc;                                                        //~v151M~
//*********************************                                //~v151M~
    Ssegreg.es=0xb800;                                             //~v151M~
    Sreg.x.di=0;                                                   //~v151M~
#ifdef DPMI                                                        //~v151M~
    Ssegreg.ds=0;                                                  //~v151I~
    Sreg.x.ax=0xfe00;                                              //~v151I~
    udpmiint86x(0x10,&Sreg,&Sreg,&Ssegreg);                        //~v151R~
    if (Ppvbuff)	//optional                                     //~v151I~
	    *Ppvbuff=(UCHAR*)((((ULONG)Ssegreg.es)<<16)+Sreg.x.di);   //video mode//~v151I~
#else                                                              //~v151M~
    INT10X(0xfe);                                                  //~v151M~
    if (Ppvbuff)	//optional                                     //~v151M~
	    *Ppvbuff=FP_SEGOFF(Ssegreg.es,Sreg.x.di);   //video mode   //~v151M~
#endif                                                             //~v151M~
    rc=(Ssegreg.es==0xb800 && Sreg.x.di==0);    //same as real     //~v151M~
	return rc;                                                     //~v151M~
}//uvio_dosgetvbuff                                                //~v151M~
#endif                                                             //~v151M~
                                                                   //~v156I~
#ifdef W32                                                         //~v156I~
//*******************************************************************//~v156M~
//* FUNCTION: ugetconhwnd                                          //~v156M~
//* PURPOSE: get console appl hwnd                                 //~v156M~
//* parm :node                                                     //~v156M~
//* ret  :hwnd or 0                                                //~v156M~
//********************************************************************///~v156M~
//ULONG ugetconhwnd(void)                                            //~v156R~//~v6hhR~
ULPTR ugetconhwnd(void)                                            //~v6hhI~
{                                                                  //~v156M~
	BOOL ok;                                                       //~v156M~
  	HWND hwnd;                                                     //~v156M~
  	char otitle[1024],ntitle[32];                                  //~v156M~
//**********                                                       //~v156M~
  	ok=GetConsoleTitle(otitle,sizeof(otitle));                     //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi0x("GetConsoleTitle",GetLastError());               //~v156M~
	sprintf(ntitle,"XE:%d/%d",GetTickCount(),GetCurrentProcessId());//~v156M~
//  printf("new title=%s\n",ntitle);	//@@@@                     //~v156M~
  	ok=SetConsoleTitle(ntitle);                                    //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi1x("SetConsoleTitle",ntitle,GetLastError());        //~v156M~
	Sleep(50);	//wait sometime like as cd manual                  //~v156M~
  	hwnd=FindWindow(NULL,ntitle);                                  //~v156M~
    if (!hwnd)                                                     //~v156M~
		uerrapi1x("FindWindow",ntitle,GetLastError());             //~v156M~
  	ok=SetConsoleTitle(otitle);	//restore                          //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi1x("SetConsoleTitle",otitle,GetLastError());        //~v156M~
//  return (ULONG)hwnd;                                            //~v156R~//~v6hhR~
    return (ULPTR)hwnd;                                            //~v6hhI~
}//ugetconhwnd                                                     //~v156M~
#ifndef WXE                                                        //~v796R~
//********************************************************************///~v792I~
int uvioGetCursorWidth(int Popt,ULONG Pucs)                        //~v796R~
{                                                                  //~v796R~
	int step=0,rc,writelen;                                        //~v796R~
    CONSOLE_SCREEN_BUFFER_INFOEX csbi;                             //~v796R~
    COORD cursorpos={0,0};                                         //~v796R~
//************************                                         //~v796R~
//*for not ambigous     if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)) //0x08000000  //utfwcwidth chr cursor step//~v796R~//~v7bbR~
//    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)) //0x08000000  //utfwcwidth chr cursor step//~v7bbI~
//    {                                                              //~v7b1I~//~v7bbR~
//        UTRACEP("%s:opt=%x,ucs=u-%04x,return -1 by APICHK_CSR off Gulibutfmode=0x%08x\n",UTT,Popt,Pucs,Gulibutfmode);//~v7b1I~//~v7bbR~
//        return -1;                                                  //~v796R~//~v7agR~//~v7bbR~
//    }                                                              //~v7b1I~//~v7bbR~
    if (Guvio2Stat & UVIO2S_NOGLYPHCHK)//     //test skip close, to getglyph width after mapinit//~vbAnI~
    {                                                              //~vbAnI~
		UTRACEP("%s:return -1 NOGLYPHCHK option\n",UTT);           //~vbAnI~
    	return -1;                                                 //~vbAnI~
    }                                                              //~vbAnI~
    if (!(Gulibutfmode & GULIBUTF_CSRSTEP)) //0x40000000  //utfwcwidth chr cursor step//~v7a7I~
    	return uvioGetGlyphWidth(Popt,Pucs);                       //~v7a7I~
//  UTRACEP("%s:opt=%x,ucs=u-%04x,ShconoutTempErr=%d\n",UTT,Popt,Pucs,ShconoutTempErr);//~v796R~
	if (Popt & UVGCWO_CLOSE) //    0x01        //close consolebuffer handle//~v796R~
    {                                                              //~v796R~
    	if (Guvio2Stat & UVIO2S_NO_FONTCLOSE)//    0x0100  //test skip close, to getglyph width after mapinit//~v7awI~
        {                                                          //~v7awI~
			UTRACEP("%s:CLOSE skip by UVIO2S_NO_FONTCLOSE\n",UTT); //~v7awI~
	        return 0;                                              //~v7awI~
        }                                                          //~v7awI~
    	if (!(Popt & UVGCWO_FORCE))                                //~v7b1R~
        {                                                          //~v7b1I~
			UTRACEP("%s:CLOSE skip by no FORCE option\n",UTT);     //~v7b1I~
	        return 0;                                              //~v7b1I~
        }                                                          //~v7b1I~
		if (ShconoutTemp)                                          //~v796R~
		    CloseHandle(ShconoutTemp);                             //~v796R~
        ShconoutTemp=0;                                            //~v796R~
		UTRACEP("%s:CLOSE\n",UTT);                                 //~v796R~
        return 0;                                                  //~v796R~
    }                                                              //~v796R~
    else                                                           //~v796R~
	if (Popt & UVGCWO_OPEN) //    0x01        //close consolebuffer handle//~v796R~
    {                                                              //~v796R~
		if (ShconoutTemp)                                          //~v796R~
        {                                                          //~v7b1I~
//  		uvioGetCursorWidth(UVGCWO_CLOSE,0);	//free old if gotten//~v796R~//~v7b1R~
			UTRACEP("%s:OPEN dupopen\n",UTT);                      //~v7b1I~
    		return -1;                                             //~v7b1I~
        }                                                          //~v7b1I~
	    ShconoutTemp=uviowincreatecsb(1/*errmsg*/);                //~v796R~
        if (ShconoutTemp==INVALID_HANDLE_VALUE)                    //~v796R~
        {                                                          //~v796R~
		    ShconoutTemp=0;                                        //~v796R~
        	ShconoutTempErr=1;                                     //~v796R~
            return -1;                                             //~v796R~
        }                                                          //~v796R~
		if (copyFontInfo(ShconoutTemp))                            //~v796R~
            return -1;                                             //~v796R~
	    csbi.cbSize=sizeof(csbi);                                  //~v796R~
    	if (!GetConsoleScreenBufferInfoEx(ShconoutTemp,&csbi))     //~v796R~
    	{                                                          //~v796R~
        	UTRACEP("%s:GetConsoleScreenBufferInfo failed LastError=%d\n",UTT,GetLastError());//~v796R~
		    ShconoutTemp=0;                                        //~v796R~
        	ShconoutTempErr=1;                                     //~v796R~
        	return -1;                                             //~v796R~
    	}                                                          //~v796R~
        Scsbi=csbi;                                                //~v796R~
    	ShconoutTempErr=0;                                         //~v796R~
		UTRACEP("%s:OPEN\n",UTT);                                  //~v796R~
    }                                                              //~v796R~
    else                                                           //~v796R~
    if (ShconoutTempErr)                                           //~v796R~
    	return -1;                                                 //~v796R~
    else                                                           //~v796R~
    {                                                              //~v796R~
	    if (!ShconoutTemp)                                         //~v796R~
        	return -1;                                             //~v796R~
        rc=SetConsoleCursorPosition(ShconoutTemp,cursorpos);       //~v796R~
        if (!rc)                                                   //~v796R~
        {                                                          //~v796R~
			UTRACEP("%s:SetConsoleCursorPos ERRrc=%d\n",UTT,rc);   //~v796R~
        	return -1;                                             //~v796R~
        }                                                          //~v796R~
		rc=WriteConsoleW(ShconoutTemp,&Pucs,1,&writelen,NULL);     //~v796R~
        if (!rc)                                                   //~v796R~
        {                                                          //~v796R~
	    	UTRACEP("%s:writeconsoleW ERR rc=%d,writelen=%d\n",UTT,rc,writelen);//~v796R~
        	return -1;                                             //~v796R~
        }                                                          //~v796R~
	    rc=GetConsoleScreenBufferInfoEx(ShconoutTemp,&Scsbi);      //~v796R~
        if (!rc)                                                   //~v796R~
        {                                                          //~v796R~
    		UTRACEP("%s:GetConsoleScreenBufferInfoEx ERR rc=%d,pos=%d\n",UTT,rc,Scsbi.dwCursorPosition.X);//~v796R~
        	return -1;                                             //~v796R~
        }                                                          //~v796R~
	    step=Scsbi.dwCursorPosition.X;                             //~v796R~
    }                                                              //~v796R~
    UTRACEP("%s:step=rc=%d,ucs=0x%04x\n",UTT,step,Pucs);           //~v796R~
    return step;                                                   //~v796R~
}//uvioGetCursorWidth                                              //~v796R~
#endif  //!WXE                                                     //~v796R~
//******************************************************           //~v79PI~
int  chkGlyphRange(HDC Phdc)                                       //~v79PI~
{                                                                  //~v79PI~
    GLYPHSET *pgs;                                                 //~v79PI~
    int sz,ii,rc;                                                  //~v79PI~
    sz=GetFontUnicodeRanges(Phdc,NULL);                            //~v79PI~
    UTRACEP("%s:sz=%d,Phdc=%p\n",UTT,sz,Phdc);                     //~v79PI~
    pgs=umalloc(sz);                                               //~v79PI~
    memset(pgs,0,sz);                                              //~v79PI~
    pgs->cbThis=sz;                                                //~v79PI~
    rc=GetFontUnicodeRanges(Phdc,pgs);                             //~v79PR~
    UTRACEP("%s:glyphset ctr=%d,rc=%d,err=%d\n",UTT,pgs->cRanges,rc,GetLastError());//~v79PI~
    UTRACED("Glyph",pgs,sz);                                       //~v79PI~
    for (ii=0;ii<(int)pgs->cRanges;ii++)                           //~v79PR~
    {                                                              //~v79PI~
    	WCRANGE *pr=pgs->ranges+ii;                                //~v79PI~
        UTRACEP("%s:range ii=%04d low=0x%04x,ctr=0x%04x\n",UTT,ii,pr->wcLow,pr->cGlyphs);//~v79PI~
    }                                                              //~v79PI~
    ufree(pgs);                                                    //~v79PI~
    return 0;                                                      //~v79PI~
}                                                                  //~v79PI~
//******************************************************           //~v79PI~
HDC  getDC()                                                       //~v79PI~
{                                                                  //~v79PI~
    HWND wnd;                                                      //~v79PI~
    HDC  hdc;                                                      //~v79PI~
    wnd=GetConsoleWindow();                                        //~v79PI~
    hdc=GetDC(wnd);                                                //~v79PI~
    return hdc;                                                    //~v79PI~
}                                                                  //~v79PI~
//******************************************************           //~v79PI~
int  chkGlyph()                                                    //~v79PI~
{                                                                  //~v79PI~
    HDC  hdc;                                                      //~v79PI~
    hdc=getDC();                                                   //~v79PI~
	chkGlyphRange(hdc);                                            //~v79PI~
    return 0;                                                      //~v79PI~
}                                                                  //~v79PI~
#ifndef WXE                                                        //~v7a7I~
//*****************************************************************//~v7a7I~
char *uviocvU2L(int Popt,UWCHART *PstrUcs,char *PstrLocal,int Pbuffsz)//~v7a7R~
{                                                                  //~v7a7I~
	int opt=UTFCVO_STRZ,chklen,outlen,repctr;                      //~v7a7R~
	utfcvu2lmb(opt,PstrUcs,wcslen(PstrUcs),PstrLocal,Pbuffsz,&chklen,&outlen,&repctr);//~v7a7R~
    UTRACEP("%s:out=%s\n",UTT,PstrLocal);                          //~v7a7I~
	return PstrLocal;                                              //~v7a7I~
}                                                                  //~v7a7I~
//*****************************************************************//~v7a7I~
char *uviocvU2F(int Popt,UWCHART *PstrUcs,char *PstrU8,int Pbuffsz)//~v7a7I~
{                                                                  //~v7a7I~
//	int opt=UTFCVO_STRZ|UCVUCS_LE;                                 //~v7a7R~//~v7arR~
  	int opt=UCVUCS_STRZU8|UCVUCS_LE;                               //~v7arI~
    ucvsucs2utf(0,opt,(char*)PstrUcs,wcslen(PstrUcs)*2,PstrU8,Pbuffsz,0/*chklen*/,0/*outlen*/,0/*repctr*/);//~8807I~//~v7a7R~
    UTRACEP("%s:out=%s\n",UTT,PstrU8);                             //~v7a7I~
	return PstrU8;                                                 //~v7a7I~
}                                                                  //~v7a7I~
//*****************************************************************//~v7a7I~
UWCHART *uviocvL2U(int Popt,char *PstrLocal,UWCHART *PstrUcs,int Pbuffsz,int *Ppoutlen)//~v7a7R~
{                                                                  //~v7a7I~
	UWCHART *pwc;                                                  //~v7a7R~
    int opt=UTFCVO_ERRRET|UTFCVO_STRZ;  //return if err                        //~v7a7R~//~v7ajR~
	int rc2=utfcvl2u(opt,SconsoleFont,(int)strlen(PstrLocal),(char*)PstrUcs,0/*Pdbcs*/,Pbuffsz,Ppoutlen);//~v7a7R~
    if (rc2)                                                       //~v7a7I~
    	pwc=0;                                                     //~v7a7M~
    else                                                           //~v7a7I~
    	pwc=PstrUcs;                                               //~v7a7M~
	return pwc;                                                    //~v7a7I~
}                                                                  //~v7a7I~
//*************************************************************************//~v7a7I~
//HFONT uvioCreateFont(UWCHART *Pface,int PfontW,int PfontH)             //~4225I~//~v7a7R~//~vbzqR~
HFONT uvioCreateFont(UWCHART *Pface,int PfontW,int PfontH,int Pcharset)//~vbzqI~
{                                                                  //~4225I~//~v7a7I~
    int outprec=OUT_DEFAULT_PRECIS;                                //~4225I~//~v7a7I~
    UTRACEP("%s:before uvioCreateFont charset=%d,size=w=%d,h=%d,err=%d\n",UTT,Pcharset,PfontW,PfontH,GetLastError());//~4225R~//~v7a7R~//~vbzqR~
    UTRACED("Pface",Pface,wcslen(Pface)*2);                        //~4225I~//~v7a7I~
//  int charset=0;//CHARSET_DEFAULT;                               //~4225R~//~v7a7I~//~vbzqR~
    int charset=Pcharset;//CHARSET_DEFAULT;                        //~vbzqI~
    int pitchAndFamily=0;                                          //~4225R~//~v7a7I~
    HFONT fnt=CreateFontW(PfontH,	//font height                  //~4225R~//~v7a7I~
					 PfontW,   //font width                        //~4225R~//~v7a7I~
                     0,0,FW_REGULAR,              //escapement,orientation,weight//~4225I~//~v7a7I~
                     FALSE,FALSE,FALSE,                   //italic,underline,strikeout//~4225I~//~v7a7I~
                     charset,              //from dialog           //~4225I~//~v7a7I~
                     (BYTE)outprec,                //output precision//~4225I~//~v7a7I~
                     CLIP_DEFAULT_PRECIS,     //clip precision     //~4225I~//~v7a7I~
                     DRAFT_QUALITY,         //quality,scaling avail for raster font//~4225I~//~v7a7I~
                     pitchAndFamily, //pitch and family            //~4225R~//~v7a7I~
                     Pface);      //face                           //~4225I~//~v7a7I~
    UTRACEP("%s:fnt=%p,err=%d\n",UTT,fnt,GetLastError());          //~4225I~//~v7a7I~
    return fnt;                                                    //~4225I~//~v7a7I~
}                                                                  //~4225I~//~v7a7I~
//*************************************************************************//~v7a7I~
//int uvioGetFontInfo(HDC Phdc,wchar_t *Pfacename,int *Ppww,int *Pphh)//~v7a7R~//~vbzqR~
int uvioGetFontInfo(HDC Phdc,wchar_t *Pfacename,int *Ppww,int *Pphh,int *Ppcharset,char *Pmbface,char *Pu8face)//~vbzqI~//~v7b4R~
{                                                                  //~v7a7I~
    wchar_t facenameW[LF_FACESIZE];                                //~v7a7I~
    TEXTMETRIC tm;                                                 //~v7a7I~
//#ifndef NOTRACE                                                    //~v7a7I~//~v7b4R~
    char mbFacename[LF_FACESIZE*2+2];                              //~v7a7I~
    char wkutf8[LF_FACESIZE*UTF8_MAXCHARSZMAX/*6*/];               //~v7a7I~
//#endif                                                             //~v7a7I~//~v7b4R~
//*****************                                                //~v7a7I~
    UTRACEP("%s:hdc=%p\n",UTT,Phdc);                               //~v7a7I~
    *Ppww=0; *Pphh=0;                                              //~v7a7I~
	                                                               //~v7adI~
//    char facenameA[LF_FACESIZE];    //TODO test  Returns Locale name it is not english name//~v7adR~
//    int rc2=GetTextFaceA(Phdc,sizeof(facenameA),facenameA);      //~v7adR~
//    UTRACED("facenameA",facenameA,sizeof(facenameA));            //~v7adR~
                                                                   //~v7adI~
    int rc=GetTextFaceW(Phdc,sizeof(facenameW),facenameW);         //~v7a7I~
    UTRACED("facename",facenameW,sizeof(facenameW));               //~v7a7I~
//#ifndef NOTRACE                                                    //~v7ajI~//~v7b4R~
	*mbFacename=0;                                                 //~v7b4I~
	if (Pmbface)                                                   //~v7b4I~
    {                                                              //~v7b4I~
		uviocvU2L(0,facenameW,mbFacename,(int)sizeof(mbFacename)); //~v7b4R~
        strcpy(Pmbface,mbFacename);                                //~v7b4I~
    }                                                              //~v7b4I~
	*wkutf8=0;                                                     //~v7b4I~
	if (Pu8face)                                                   //~v7b4I~
    {                                                              //~v7b4I~
		uviocvU2F(0,facenameW,wkutf8,sizeof(wkutf8));              //~v7b4R~
        strcpy(Pu8face,wkutf8);                                    //~v7b4I~
    }                                                              //~v7b4I~
    UTRACEP("%s:facenameMB=%s,facenameU8=%s\n",UTT,mbFacename,wkutf8);//~v7b4R~
//#endif                                                             //~v7ajI~//~v7b4R~
    if (!rc)                                                       //~v7a7I~
    	return 4;                                                  //~v7a7I~
    wcscpy(Pfacename,facenameW);                                   //~v7a7I~
    rc=GetTextMetrics(Phdc,&tm);                                   //~v7a7I~
    UTRACEP("%s:GetTextMetrics rc=%d,err=%d\n",UTT,rc,GetLastError());//~v7a7I~
    if (!rc)                                                       //~v7a7I~
    	return 4;                                                  //~v7a7I~
    UTRACED("TEXTMETRIC",&tm,sizeof(tm));                          //~v7a7I~
    int ww=tm.tmAveCharWidth;                                      //~v7a7I~
    int hh=tm.tmHeight;                                            //~v7a7I~
    UTRACEP("%s:GetTextMetrics ww=%d,hh=%d,charset=0x%02x,pictchAndFamily=0x%02x\n",UTT,ww,hh,tm.tmCharSet,tm.tmPitchAndFamily);//~v7a7I~
    *Ppww=ww; *Pphh=hh;                                            //~v7a7I~
    *Ppcharset=tm.tmCharSet;                                       //~vbzqI~
    return 0;                                                      //~v7a7I~
}                                                                  //~v7a7I~
//*************************************************************************//~v7a7I~
//wchar_t *uvioGetCurrentFont(HDC Phdc,int *PpfontW,int *PpfontH)    //~v7a7R~//~vbzqR~
wchar_t *uvioGetCurrentFont(HDC Phdc,int *PpfontW,int *PpfontH,int *Ppcharset)//~vbzqI~
{                                                                  //~v7a7I~
	static wchar_t *pwc;                                           //~v7a7I~
    char mbFacename[LF_FACESIZE*2+2];                              //~v7a7I~
    CONSOLE_FONT_INFOEX fi;                                        //~v7a7I~
    TEXTMETRIC tm;                                                 //~vbzqI~
    int charset=0;                                                 //~vbzqI~
//*************************                                        //~v7a7I~
    memset(&fi,0,sizeof(fi));                                      //~v7a7I~
    fi.cbSize=sizeof(fi);                                          //~v7a7I~
    int rc16=GetCurrentConsoleFontEx(Phdc,FALSE/*not fullscreen size*/,&fi);//~v7a7I~
    UTRACEP("%s:getCurrentConsoleFontEx rc=%d,errno=%d,hdc=%p\n",UTT,rc16,GetLastError(),Phdc);//~v7a7I~
    UTRACEP("%s:size=W=%d-H=%d\n",UTT,fi.dwFontSize.X,fi.dwFontSize.Y);//~v7a7I~
    *PpfontW=fi.dwFontSize.X;                                      //~v7a7I~
    *PpfontH=fi.dwFontSize.Y;                                      //~v7a7I~
    UTRACED("showfont fi",&fi,sizeof(fi));                         //~v7a7I~
  if (rc16)                                                        //~v7a7I~
  {                                                                //~v7a7I~
    UTRACEP("%s:mbfacename=%s\n",UTT,uviocvU2L(0,fi.FaceName,mbFacename,(int)sizeof(mbFacename)));//~v7a7R~
    int len=wcslen(fi.FaceName);                                   //~v7a7I~
    pwc=malloc(len+len+2);                                         //~v7a7I~
    wcscpy(pwc,fi.FaceName);                                       //~v7a7I~
                                                                   //~vbzqI~
    rc16=GetTextMetrics(Phdc,&tm);                                 //~vbzqI~
    UTRACEP("%s:GetTextMetrics rc=%d,err=%d\n",UTT,rc16,GetLastError());//~vbzqR~
    if (rc16)                                                      //~vbzqI~
    	charset=tm.tmCharSet;                                      //~vbzqI~
    UTRACED("TEXTMETRIC",&tm,sizeof(tm));                          //~vbzqI~
    int ww=tm.tmAveCharWidth;                                      //~vbzqI~
    int hh=tm.tmHeight;                                            //~vbzqI~
    UTRACEP("%s:GetTextMetrics ww=%d,hh=%d,charset=0x%02x,pictchAndFamily=0x%02x\n",UTT,ww,hh,tm.tmCharSet,tm.tmPitchAndFamily);//~vbzqI~
  }                                                                //~v7a7I~
  else                                                             //~v7a7I~
    pwc=0;                                                         //~v7a7I~
    *Ppcharset=charset;                                            //~vbzqI~
    return pwc;                                                    //~v7a7I~
}                                                                  //~v7a7I~
//*****************************************************************//~v7a7M~
//*WINCON                                                          //~vbzCI~
//*****************************************************************//~vbzCI~
int uvioGetDrawWidth(int Pucs,HDC Phdc)                            //~v7a7M~
{                                                                  //~v7a7M~
	RECT rect={0,0,0,0};                                           //~v7a7M~
    UWCHART wch[2];                                                //~v7a7M~
    int ww=0,ucs2len,*plen;                                        //~v7a7M~
//****************                                                 //~v7a7M~
	plen=&ucs2len;                                                 //~v7a7M~
	UCS4_TO_UTF16(Pucs,wch,plen);                                  //~v7a7M~
    int rc2=DrawTextW(Phdc,wch,ucs2len,&rect,DT_CALCRECT|DT_NOPREFIX);//~v7a7M~
    if (rc2)                                                       //~v7a7M~
    	ww=rect.right-rect.left;                                   //~v7a7M~
    UTRACEP("%s:rc=ww=%d,rc2=%d,ucs2len=%d:%04x-%04x,err=%d,ucs=0x%04x,ww=%d,hh=%d,rect=l=%d,t=%d-r=%d,b=%d,hdc=%p\n",//~v7bcR~
			UTT,ww,rc2,ucs2len,wch[0],wch[1],GetLastError(),Pucs,  //~v7bcR~
			rect.right-rect.left,rect.bottom-rect.top,             //~v7a7M~
			rect.left,rect.top,rect.right,rect.bottom,Phdc);            //~v7a7M~//~v7awR~
    return ww;                                                     //~v7a7M~
}                                                                  //~v7a7M~
//*****************************************************************//~v7a7M~
int uvioGetCharWidth(HDC Phdc,int Pucs)                            //~v7a7M~
{                                                                  //~v7a7M~
    UWCHART wch;                                                   //~v7a7R~
    SIZE sza;                                                      //~v7a7R~
    int rc=0,rc2;                                                  //~v7a7R~
    ABC abcs[2];                                                   //~v7a7R~
//************************                                         //~v7a7M~
    if (!rc)                                                       //~v7a7I~
    {                                                              //~v7a7I~
        rc2=GetCharABCWidthsW(Phdc,Pucs,Pucs,abcs);   //for TT font//~v7a7I~
        UTRACEP("%s:GetCharABCWidthsW rc2=%d,err=%d,ucs=0x%04x A=%d,B=%d,C=%d\n",UTT,rc2,GetLastError(),Pucs,abcs[0].abcA,abcs[0].abcB,abcs[0].abcC);//~v7a7I~
        if (rc2)                                                   //~v7a7I~
            rc=abcs[0].abcA+abcs[0].abcB+abcs[0].abcC;             //~v7a7I~
    }                                                              //~v7a7I~
    if (!rc)                                                       //~v7a7I~
    {                                                              //~v7a7I~
        wch=(UWCHART)Pucs;                                         //~v7a7R~
        rc2=GetTextExtentPoint32W(Phdc,&wch,1,&sza);               //~v7a7R~
        if (rc2)                                                   //~v7a7I~
        {                                                          //~v7a7I~
        	UTRACEP("%s:rc=%d,err=%d,ucs=0x%04x GetTextExtentPoint32W cx=%d,cy=%d\n",UTT,rc,GetLastError(),Pucs,sza.cx,sza.cy);//~v7a7R~
        	rc=sza.cx;                                             //~v7a7R~
        }                                                          //~v7a7I~
	}                                                              //~v7a7I~
    UTRACEP("%s:rc=%d,ucs=0x%04x\n",UTT,rc,Pucs);                  //~v7a7R~
    return rc;                                                     //~v7a7M~
}                                                                  //~v7a7M~
//*****************************************************************//~vbzCI~
int uvioGetCharExtent(HDC Phdc,int Pucs)                           //~vbzCI~
{                                                                  //~vbzCI~
//  UWCHART wch;                                                   //~vbzCI~//~v7bcR~
    SIZE sza;                                                      //~vbzCI~
    int rc=-1,rc2;                                                 //~vbzCI~
	wchar_t wkucs16[4];                                            //~v7bcI~
    int ucs16ctr=1;                                                //~v7bcI~
//************************                                         //~vbzCI~
//  wch=(UWCHART)Pucs;                                             //~vbzCI~//~v7bcR~
//  rc2=GetTextExtentPoint32W(Phdc,&wch,1,&sza);                   //~vbzCI~//~v7bcI~
    if (Pucs>0xffff)                                               //~v7bcI~
		UCS4_TO_UTF16(Pucs,wkucs16,&ucs16ctr);                     //~v7bcI~
    else                                                           //~v7bcI~
		wkucs16[0]=(wchar_t)Pucs;                                  //~v7bcI~
    rc2=GetTextExtentPoint32W(Phdc,wkucs16,ucs16ctr,&sza);         //~v7bcI~
    if (rc2)                                                       //~vbzCI~
    {                                                              //~vbzCI~
    	UTRACEP("%s:rc2=%d,err=%d,ucs=0x%04x ucs16ctr=%d:%04x-%04x GetTextExtentPoint32W cx=%d,cy=%d\n",//~v7bcR~
			UTT,rc2,GetLastError(),Pucs,ucs16ctr,wkucs16[0],wkucs16[1],sza.cx,sza.cy);//~v7bcR~
        rc=sza.cx;                                                 //~vbzCI~
	}                                                              //~vbzCI~
    UTRACEP("%s:rc=%d,ucs=0x%04x\n",UTT,rc,Pucs);                  //~vbzCI~
    return rc;                                                     //~vbzCI~
}                                                                  //~vbzCI~
//*****************************************************************//~v7adI~
int uvioGetFacenameW(int Popt,char *Pfacename,wchar_t *Poutwcs,int Pbuffsz)//~v7adR~
{                                                                  //~v7adI~
	char *pnameA;                                                  //~v7adR~
    char  nameA[LF_FACESIZE*2+2];                                  //~v7adI~
    char  nameMB[LF_FACESIZE*2+2];                                 //~vbzCI~
    int len,rc=0;                                                  //~v7adR~
//***********************************                              //~v7adI~
    UstrncpyZ(nameA,Pfacename,sizeof(nameA));                      //~v7adR~
    pnameA=nameA;                                                  //~v7adI~
    len=(int)strlen(nameA);                                        //~v7adI~
	if (*pnameA=='8' && *(pnameA+1)=='-')  //parm is utf8 code     //~v7adR~
    {                                                              //~v7adI~
    	len-=2;                                                    //~v7adI~
        pnameA+=2;                                                 //~vbzCI~
        if (*pnameA=='\"')                                         //~vbzCI~
        {                                                          //~vbzCI~
            pnameA++;                                              //~vbzCI~
            len--;                                                 //~vbzCI~
            char *pc=strchr(pnameA,'\"');                          //~vbzCI~
            if (pc)                                                //~vbzCI~
            {                                                      //~vbzCI~
                *pc=0;                                             //~vbzCI~
                len--;                                             //~vbzCI~
            }                                                      //~vbzCI~
        }                                                          //~vbzCI~
    	ULONG opt;                                                 //~v7adI~
        int chklen,outlen,errctr;                                  //~v7adR~
        opt=UCVUCS_LE;                                             //~v7adR~
//  	int rc2=ucvsutf2ucs(0/*Pferr*/,opt,pnameA+2,len,(UCHAR *)Poutwcs,Pbuffsz,&chklen,&outlen,&errctr);//~v7adR~//~vbzCR~
    	int rc2=ucvsutf2ucs(0/*Pferr*/,opt,pnameA,len,(UCHAR *)Poutwcs,Pbuffsz,&chklen,&outlen,&errctr);//~vbzCI~
	    UTRACEP("%s:ucscvuutf2ucs rc=%d,pnameA=%s\n",UTT,rc2,pnameA);                //~v7adR~//~vbzCR~
        if (rc2)                                                   //~v7adR~
        	rc=4;                                                  //~v7adR~
    }                                                              //~v7adI~
    else                                                           //~v7adI~
    {                                                              //~v7adI~
		UTRACEP("%s:pnameA=%s\n",UTT,pnameA);                      //~v7adI~
        if (strstr(pnameA,"\\u")||strstr(pnameA,"\\U"))            //~vbzCI~
        {                                                          //~vbzCI~
			if (getfaceW(pnameA,Poutwcs,Pbuffsz,nameMB,(int)sizeof(nameMB)))//~vbzCI~
            	rc=4;                                              //~vbzCI~
        }                                                          //~vbzCI~
        else                                                       //~vbzCI~
    	if (!uviocvL2U(0,pnameA,Poutwcs,Pbuffsz,0/*outlen*/))      //~v7adR~
        	rc=4;                                                  //~v7adI~
    }                                                              //~v7adI~
    UTRACED("input facename",Pfacename,strlen(Pfacename));         //~v7adR~
    UTRACED("facenameW",Poutwcs,Pbuffsz);                          //~v7adI~
    return rc;                                                     //~v7adR~
}                                                                  //~v7adI~
//*****************************************************************//~v7a7I~
//*Win                                                             //~v7arI~
//*****************************************************************//~v7arI~
int uvioChkGlyphInit(int *Ppww,int *Pphh)                          //~v7a7R~
{                                                                  //~v7a7I~
	HFONT fnt,fntold;                                              //~v7a7I~
    char mbFacename[LF_FACESIZE*2+2];                              //~v7a7I~//~v7adR~
    char wkutf8[LF_FACESIZE*UTF8_MAXCHARSZMAX/*6*/];               //~v7b4I~
    wchar_t consoleFontW[LF_FACESIZE]={0};                 //~v7a7I~//~v7adR~
    char wkhex[LF_FACESIZE*MAX_MBCSLEN];                           //~v7adI~
    wchar_t selectedFacenameW[LF_FACESIZE]={0};                    //~v7a7I~
    wchar_t defaultFacenameW[LF_FACESIZE];                         //~v7a7I~
    wchar_t *pnameW;                                               //~v7adI~
    int swTerminal;                                                //~v7a7R~
    int fontH=0,fontW=0;                                           //~v7a7R~
    int charset=0;                                                 //~vbzqI~
    int sz;                                                        //~v7aqI~
//*********************************************                    //~v7a7I~
    UTRACEP("%s:entry\n",UTT);                                     //~v7a7I~
    if (!Shconout)	//mapinit is before uvio2_init                 //~v7a7I~
    	Shconout=ugetstdhandle(STD_OUTPUT_HANDLE);                 //~v7a7I~
    ShconoutTemp=GetDC(NULL);                                      //~v7a7I~
    if (ShconoutTemp==INVALID_HANDLE_VALUE)                        //~v7a7I~
    {                                                              //~v7a7I~
        ShconoutTemp=0;                                            //~v7a7I~
	    UTRACEP("%s;GetDC(NULL) failed\n",UTT);                    //~v7a7I~
        return 4;                                                  //~v7a7I~
    }                                                              //~v7a7I~
    UTRACEP("%s:ShconoutTemp=%p,Shconout=%p,facename=%s\n",UTT,ShconoutTemp,Shconout,(GetTextFaceA(ShconoutTemp,(int)sizeof(mbFacename),mbFacename),mbFacename));//~v7a7R~
    swTerminal=chkTerminal();	//1:conhost,0:unknown,2:terminal   //~v7a7I~
    if (swTerminal==1)  //conhost                                  //~v7a7I~
    {                                                              //~v7a7I~
//  	pnameW=uvioGetCurrentFont(Shconout,&fontW,&fontH);         //~v7a7R~//~vbzqR~
    	pnameW=uvioGetCurrentFont(Shconout,&fontW,&fontH,&charset);//~vbzqR~
        UTRACEP("%s:conhost fontW=%d,fontH=%d,charset=%d\n",UTT,fontW,fontH,charset);//~v7arR~
        if (!pnameW)                                               //~v7a7I~
        	UTRACEP("%s:get default font from stdout for conhost failed Shconout=%p\n",UTT,Shconout);//~v7a7I~
        else                                                       //~v7a7I~
        {                                                          //~v7c9I~
        	wcscpy(consoleFontW,pnameW);                           //~v7a7I~
			uviocvU2L(0,consoleFontW,SconsoleFont,(int)sizeof(SconsoleFont));//~v7c9I~
        }                                                          //~v7c9I~
    }                                                              //~v7a7I~
    else                                                           //~v7arI~
    {                                                              //~v7arI~
	    if (!SconsoleFont[0])                                      //~v7arI~
        {                                                          //~v7arI~
        	UTRACEP("%s:no font parm on WindowsTerminal, swTerminal=%d\n",UTT,swTerminal);//~v7arI~//~v7c9R~
//			if (!UTF_AMBIG2CELLMODE())                             //~v7arI~//~v7bhR~
//          {                                                      //~v7arI~//~v7bhR~
        		UTRACEP("%s:try to find settings.json\n",UTT);     //~v7arI~
              	getW32ConsoleFont(GWCFO_MSG,SconsoleFont,(int)sizeof(SconsoleFont),&sz,consoleFontW,sizeof(consoleFontW));//~v7arI~
//          }                                                      //~v7arI~//~v7bhR~
     	}                                                          //~v7arI~
    }                                                              //~v7arI~
    if (!*consoleFontW)	//for also windows terminal                //~v7a7I~
    {                                                              //~v7a7I~
	    if (!SconsoleFont[0])                                      //~v7a7I~
        {                                                          //~v7a7I~
//  		if (!UTF_AMBIG2CELLMODE())                             //~v7a7I~//~v7bhR~
//              uerrmsg("Warning:Font name cmdline parameter(/Ffacename[:charset]) is recommended on WindowsTerminal(Not on Conhost). \n"//~vbzqR~//~v7bhR~
//                      "About charset(0-255), see Microsoft Document about Charset.\n",0);//~vbzqR~//~v7bhR~
	    		showFontWarning(0,0/*Win*/,0/*parm*/);             //~v7bhR~
            return 4;                                              //~v7a7I~
        }                                                          //~v7a7I~
//  	pnameW=uviocvL2U(0,SconsoleFont,consoleFontW,sizeof(consoleFontW),0/*outlen*/);//~v7a7R~//~v7adR~
    	int rc2=uvioGetFacenameW(0,SconsoleFont,consoleFontW,sizeof(consoleFontW));//~v7adR~
        if (rc2)                                                   //~v7adR~
        {                                                          //~v7a7I~
        	UTRACEP("%s:fontname(%s) l2u err\n",UTT,SconsoleFont); //~v7a7I~
			ub2x(0,wkhex,SconsoleFont,strlen(SconsoleFont));       //~v7adI~
            wkhex[strlen(SconsoleFont)*2]=0;                       //~v7adI~
        	uerrmsg("Translation Locale or UTF-8 code to Unicode translation failed for fontname(%s, 0x%s)\n",0,                    //~v7a7I~//~v7adR~
						SconsoleFont,wkhex);                             //~v7a7I~//~v7adR~
            return 4;                                              //~v7a7I~
        }                                                          //~v7a7I~
//  	uvioGetFontInfo(ShconoutTemp,defaultFacenameW,&fontW,&fontH);//it may be "System", but call to get width and height//~v7a7R~//~vbzqR~
//  	uvioGetFontInfo(ShconoutTemp,defaultFacenameW,&fontW,&fontH,&charset);//it may be "System", but call to get width and height//~vbzqI~//~v7b4R~
    	uvioGetFontInfo(ShconoutTemp,defaultFacenameW,&fontW,&fontH,&charset,mbFacename,wkutf8);//it may be "System", but call to get width and height//~v7b4I~
    }                                                              //~v7a7I~
    UTRACED("consoleFontW",consoleFontW,sizeof(consoleFontW));     //~v7a7I~
    UTRACEP("%s:before createFont charset=%d,ScharsetParm=%d\n",UTT,charset,ScharsetParm);//~vbzqI~
	if (ScharsetParm>=0)                                           //~vbzqI~
    	charset=ScharsetParm;                                      //~vbzqI~
//  fnt=uvioCreateFont(consoleFontW,fontW,fontH);                  //~v7a7R~//~vbzqR~
    fontH=((fontH+1))/2*2;                                         //~v7agI~
    fontW=0;                                                       //~v7agI~
    fnt=uvioCreateFont(consoleFontW,fontW,fontH,charset);          //~vbzqI~
	fntold=SelectObject(ShconoutTemp,fnt);                         //~v7a7I~
    if (!fntold)                                                   //~v7a7I~
    {                                                              //~v7a7I~
        UTRACEP("%s:selectObject for font(%p) failed err=%d HDC=%p\n",UTT,fnt,GetLastError(),ShconoutTemp);//~v7a7I~
		uviocvU2L(0,consoleFontW,mbFacename,(int)sizeof(mbFacename));//~v7a7R~
        uerrmsg("selectObject for font(%s) failed err=%d\n",0,     //~v7a7I~
					mbFacename,GetLastError());                    //~v7a7I~
        return 4;                                                  //~v7a7I~
    }                                                              //~v7a7I~
    SglyphFont=fnt;	//later DeleteObject                           //~v7a7I~
    int charsetNew;                                                //~vbzqI~
//	uvioGetFontInfo(ShconoutTemp,selectedFacenameW,&fontW,&fontH,&charsetNew); //~v7a7R~//~vbzqR~//~v7b4R~
  	uvioGetFontInfo(ShconoutTemp,selectedFacenameW,&fontW,&fontH,&charsetNew,mbFacename,wkutf8);//~v7b4I~
    ScharsetSelected=charsetNew;                                   //~v7c9I~
    UTRACED("selectedFacenameW",selectedFacenameW,sizeof(selectedFacenameW));//~v7a7I~
    UTRACED("consoleFontW",consoleFontW,sizeof(consoleFontW));     //~v7a7I~
    if (wcscmp(selectedFacenameW,consoleFontW))                    //~v7a7I~
    {                                                              //~v7a7I~
        UTRACEP("%s:uvioCreateFont failed by invalid facename(%s),charset=%d,charsetNew=%d\n",UTT,SconsoleFont,charset,charsetNew);//~v7a7R~//~v7c9R~
        if (swTerminal==2)                                         //~v7c9R~
	    	showFontWarning(3,0,0); //Win, searching json          //~v7c9R~
        uerrmsg("CreateFont failed for Font Facename(%s) and Charset(%d).\n",0,//~v7a7R~//~vbzqR~
					SconsoleFont,charset);                                 //~v7a7I~//~vbzqR~
        uerrmsg("System selected %s, charset=%d.\n",0,                         //~v7b4I~//~v7c9R~
					mbFacename,charset);                                   //~v7b4I~//~v7c9R~
        if (ScharsetParm==-1)                                      //~vbzqR~
        {                                                          //~vbzqI~
//            uerrmsg("Font Facename and Charset are required if on WindowsTerminal(not Conhost) console.\n"//~vbzqR~//~v7arR~
//                    "Currently, Facename can not be get, you can specify it with proper Charset by cmdline option of /F[8-]facename[:charset].\n"//~vbzqR~//~v7adR~//~v7arR~
//                    "About charset(0-255,current is %d), see Microsoft Document about Charset.\n",//~vbzqR~//~v7arR~
//                    "(Conhostではない) WindowsTerminal コンソール上ではフォント名と文字セット(Charset)が必要です。\n"//~vbzqI~//~v7arR~
//                    "現在のところフォント名の設定を知ることができないので、\n"//~vbzqI~//~v7arR~
//                    "適合する Charsetと共にコマンドラインパラメータ /F[8-]facename[:charset] を指定してください。\n"//~vbzqI~//~v7adR~//~v7arR~
//                    "文字セットの値(0-255)は現在は %d ですがについては Microsoft のドキュメントを参照してください。\n",//~vbzqI~//~v7arR~
//                    charset);                                      //~vbzqI~//~v7arR~
//            uerrmsg("When /GY (Adjust display width f Ambiguous chars) is specified,\n"//~v7bhR~
//                    "font Facename and Charset are required on WindowsTerminal(not Conhost) console.\n"//~v7bhR~
//                    "xe tries to get it from setting.json file. If failed, you have to specify it\n"//~v7bhR~
//                    "with proper Charset by cmdline option of /F.\n"//~v7bhR~
//                    "About charset(0-255,current is %d), see Microsoft Document about Charset.\n",//~v7bhR~
//                    "/GY (表示幅が曖昧とされるユニコード文字をフォントに従い調整する)オプションのとき\n"//~v7bhR~
//                    "(Conhostではない) WindowsTerminal コンソール上ではフォント名と文字セット(Charset)が必要です。\n"//~v7bhR~
//                    "setting.json からフォント名を得ようとしますが、失敗した場合は\n"//~v7bhR~
//                    "適合する Charsetと共にコマンドラインパラメータ /F を指定してください。\n"//~v7bhR~
//                    "文字セットの値(0-255)は現在は %d ですがについては Microsoft のドキュメントを参照してください。\n",//~v7bhR~
//                    charset);                                    //~v7bhR~
	    	showFontWarning(2,mbFacename,charset); //Win           //~v7bhR~
        }                                                          //~vbzqI~
        return 4;                                                  //~v7a7I~
    }                                                              //~v7a7I~
    *Ppww=fontW;                                                   //~v7a7I~
    *Pphh=fontH;                                                   //~v7a7I~
	int wwA=uvioGetCharWidth(ShconoutTemp,'A');                    //~v7a7I~
	int wwW=uvioGetCharWidth(ShconoutTemp,'W');                    //~v7a7I~
    if (wwA==wwW)                                                  //~v7a7I~
    	Guvio2Stat|=UVIO2S_CONSOLE_MONOFONT;                       //~v7a7R~
    else                                                           //~v7a7I~
    	Guvio2Stat&=~UVIO2S_CONSOLE_MONOFONT;                      //~v7a7R~
    UTRACEP("%s:return 0 monofont ? Guvio2Stat=0x%04x,Gulibutfmode=0x%08x\n",UTT,Guvio2Stat,Gulibutfmode);   //~v7a7I~//~v7arR~
    UTRACED("selectedFacenameW",selectedFacenameW,sizeof(selectedFacenameW));//~v7arI~
    return 0;                                                      //~v7a7I~
}                                                                  //~v7a7I~
//*****************************************************************//~v7a7I~
//*WINCON                                                          //~vbzCI~
//*rc=1:wide, -1:width=0                                           //~v7c7I~
//*****************************************************************//~vbzCI~
//int uvioIsWideGlyph(HDC Phdc,int PfontW,int PfontH,int Pucs)       //~v7a7R~//~v7b8R~
int uvioIsWideGlyph(int Popt,HDC Phdc,int PfontW,int PfontH,int Pucs)//~v7b8I~
{                                                                  //~v7a7I~
	int wwDraw=-2;                                                  //~v7a7I~//~v7bdR~
    int wwExt;                                                     //~v7b7I~
    int rc;                                                        //~v7aiI~
//************************                                         //~v7a7I~
	wwExt=uvioGetCharExtent(Phdc,Pucs);                            //~v7b7R~
	rc=wwExt>(PfontH+1)/2;                                         //~v7b7I~
//    int ww=uvioGetCharWidth(Phdc,Pucs);                            //~v7a7R~//~v7aiR~
//    int rc=ww>(PfontH+1)/2;                                        //~v7a7R~//~v7aiR~
//    if (!rc)    //1cell,confirm by draw width                      //~v7a7I~//~v7aiR~
//    {                                                              //~v7a7M~//~v7aiR~
    Guvio2Info|=(wwExt & UVIO2SI_MASK_WWGLYPH);                    //~v7bdI~
//if (!(Popt & UVGCWO_NOAMB))	//ext only for non ambiguous       //~v7b8R~//~v7beR~
//  if (!rc)  //not wide                                           //~v7b7I~//~v7beR~
  	int swTextDraw=0;                                              //~v7beI~
    if (!rc) //sbcs width                                          //~v7beI~
  		if (!(Popt & UVGCWO_NOAMB)	//ucs is ambiguous(not non-ambiguous)//~v7beI~
        ||  Pucs>=UCS2DDMAP_ENTNO   //not mapinit,volume is not so large//~v7beI~
        ||  Guvio2Stat & UVIO2S_DRAWTEXTALL) //option to chk also non-ambiguous//~v7beI~
        	swTextDraw=1;                                          //~v7beI~
  	if (swTextDraw)                                                //~v7beI~
    {                                                              //~v7b7I~
        wwDraw=uvioGetDrawWidth(Pucs,Phdc);                        //~v7a7I~
    	Guvio2Info|=(wwDraw & UVIO2SI_MASK_WWGLYPH);               //~v7bdI~
//        if (wwDraw>ww)                                             //~v7a7I~//~v7aiR~
		    rc=wwDraw>(PfontH+1)/2;                                //~v7a7I~
//    }                                                              //~v7a7M~//~v7aiR~
    }                                                              //~v7b7I~
    Guvio2Info|=((PfontH<<8) & UVIO2SI_MASK_HHFONT);               //~v7awR~
    if (rc)                                                        //~v7awI~
	    Guvio2Info|=UVIO2SI_MASK_ISWIDE;                           //~v7awI~
    else                                                           //~v7awI~
	    Guvio2Info&=~UVIO2SI_MASK_ISWIDE;                          //~v7awI~
    if (Guvio2Stat & UVIO2S_TESTWCW) // 0x0200  //for test         //~v7bdI~
    {                                                              //~vbzCI~
        int wwDraw2=uvioGetDrawWidth(Pucs,Phdc);                   //~v7bdR~
		int wwChr=uvioGetCharWidth(Phdc,Pucs);                     //~vbzCI~
	    UTRACEP("%s:Compare fontH=%02d,ucs=0x%04x(%s),"            //~vbzCR~
				"Draw=%d,Ext=%d,Chr=%d,Draw_Ext_Same=%d,Draw_Chr_Same=%d,"//~vbzCI~
				"Ext_Chr_same=%d,wideDraw=%d,wideExt=%d,wideChr=%d,wideDraw=%d\n",//~vbzCI~//~v7bdR~
				UTT,PfontH,Pucs,UCV_U2F1(Pucs),                    //~vbzCR~
				wwDraw2,wwExt,wwChr,wwDraw2==wwExt,wwDraw2==wwChr,    //~vbzCI~//~v7bdR~
				wwExt==wwChr,rc,wwExt>(PfontH+1)/2,wwChr>(PfontH+1)/2,wwDraw2>(PfontH+1)/2);//~vbzCI~//~v7bdR~
    }                                                              //~vbzCI~
//  UTRACEP("%s:Guvio2Info=0x%04x\n",UTT,Guvio2Info);              //~v7awR~
	if (!wwExt && (wwDraw==-2 || wwDraw==0))                       //~v7c7I~
    {                                                              //~v7c7I~
	    UTRACEP("%s:return 0 by glyph width=0\n",UTT);             //~v7c7I~
    	rc=-1;	//width=0                                          //~v7c7I~
    }                                                              //~v7c7I~
    UTRACEP("%s:opt=0x%04X,rc=%d,wwDraw=%0d,wwExt=%d,fontH=%02d,ucs=0x%04x(%s)\n",UTT,Popt,rc,wwDraw,wwExt,PfontH,Pucs,UCV_U2F1(Pucs));//~v7a7R~//~v7aiR~//~v7b7R~//~v7b8R~//~v7c7R~
    return rc;                                                     //~v7a7I~
}                                                                  //~v7a7I~
//********************************************************************///~v7a7I~
//*WINCON                                                          //~vbzCR~
//********************************************************************///~v7awI~
int uvioGetGlyphWidth(int Popt,ULONG Pucs)                         //~v7a7I~
{                                                                  //~v7a7I~
	int rc=0,fontW,fontH;                                          //~v7a7R~
//************************                                         //~v7a7I~
    UTRACEP("%s:opt=%x,ucs=u-%04x\n",UTT,Popt,Pucs);               //~v7a7I~
    if (Guvio2Stat & UVIO2S_NOGLYPHCHK)//     //test skip close, to getglyph width after mapinit//~vbAnI~
    {                                                              //~vbAnI~
		UTRACEP("%s:return -1 NOGLYPHCHK option\n",UTT);           //~vbAnI~
    	return -1;                                                 //~vbAnI~
    }                                                              //~vbAnI~
	if (Popt & UVGCWO_CLOSE) //    0x01        //close consolebuffer handle//~v7a7I~
    {                                                              //~v7a7I~
    	if (Guvio2Stat & UVIO2S_NO_FONTCLOSE)//    0x0100  //test skip close, to getglyph width after mapinit//~v7awI~
        {                                                          //~v7awI~
			UTRACEP("%s:CLOSE skip by UVIO2S_NO_FONTCLOSE\n",UTT); //~v7awI~
	        return 0;                                              //~v7awI~
        }                                                          //~v7awI~
    	if (!(Popt & UVGCWO_FORCE))                                //~v7b1R~
        {                                                          //~v7b1I~
			UTRACEP("%s:CLOSE skip by no FORCE option\n",UTT);     //~v7b1I~
	        return 0;                                              //~v7b1I~
        }                                                          //~v7b1I~
        if (SglyphFont)                                            //~v7a7I~
        {                                                          //~v7a7I~
        	rc=DeleteObject(SglyphFont);                           //~v7a7I~
            UTRACEP("%s:DeleteObject rc=%d,err=%d object=%p\n",UTT,rc,GetLastError(),SglyphFont);//~v7a7R~
        }                                                          //~v7a7I~
//  	if (ShconoutTemp)                                          //~v7a7R~
//      {                                                          //~v7a7R~
//      	UTRACEP_FLUSH("%s:CloseHandle ShcompTemp=%p\n",UTT,ShconoutTemp);//~v7a7R~
//  	    rc=CloseHandle(ShconoutTemp);                          //~v7a7R~
//          UTRACEP("%s:CloseHandle rc=%d,err=%d ShconoutTemp=%p\n",UTT,rc,GetLastError(),ShconoutTemp);//~v7a7R~
//          rc=ReleaseDC(NULL,ShconoutTemp);                       //~v7a7R~
//          UTRACEP_FLUSH("%s:DeleteDC rc=%d,err=%d ShconoutTemp=%p\n",UTT,rc,GetLastError(),ShconoutTemp);//~v7a7R~
//      }                                                          //~v7a7R~
        ShconoutTemp=0;                                            //~v7a7I~
        SglyphFont=0;                                              //~v7a7I~
		printf("Font selected is \"%s\", charset=%d.\n",SconsoleFont,ScharsetSelected);//~v7c9R~
		UTRACEP("%s:CLOSE return\n",UTT);                          //~v7a7I~
        return 0;                                                  //~v7a7I~
    }                                                              //~v7a7I~
    else                                                           //~v7a7I~
	if (Popt & UVGCWO_OPEN) //    0x01        //close consolebuffer handle//~v7a7I~
    {                                                              //~v7a7I~
		UTRACEP("%s:OPEN ShconoutTemp=%p\n",UTT,ShconoutTemp);     //~v7awI~
		if (ShconoutTemp)                                          //~v7a7I~
        {                                                          //~v7b1I~
//  		uvioGetGlyphWidth(UVGCWO_CLOSE,0);	//free old if gotten//~v7a7I~//~v7b1R~
			UTRACEP("%s:OPEN dupopen\n",UTT);                      //~v7b1I~
    		return -1;                                             //~v7b1I~
        }                                                          //~v7b1I~
		if (uvioChkGlyphInit(&fontW,&fontH))                       //~v7a7R~
        {                                                          //~v7a7I~
        	ShconoutTempErr=1;                                     //~v7a7I~
        	return -1;                                             //~v7a7R~
        }                                                          //~v7a7I~
        SfontW=fontW; SfontH=fontH;                                //~v7a7I~
    	GhconoutTemp=ShconoutTemp;                                 //~v7b5I~
    }                                                              //~v7a7I~
    else                                                           //~v7a7I~
    if (ShconoutTempErr)                                           //~v7a7I~
    	return -1;                                                 //~v7a7R~
    else                                                           //~v7a7I~
    {                                                              //~v7a7I~
//  	rc=uvioIsWideGlyph(ShconoutTemp,SfontW,SfontH,Pucs);       //~v7a7R~//~v7b8R~
    	rc=uvioIsWideGlyph(Popt,ShconoutTemp,SfontW,SfontH,Pucs);  //~v7b8I~
        if (rc==1)                                                 //~v7a7I~
        	rc=2;                                                  //~v7a7I~
        else                                                       //~v7a7I~
        if (rc==-1 && (Popt & UVGCWO_RETW0)) //    0x20        //return width=0//~v7c7I~
        {                                                          //~v7c7I~
	    	UTRACEP("%s:return width0 by option,ucs=0x%04x\n",UTT,Pucs);//~v7c7I~
        	rc=0;                                                  //~v7c7I~
        }                                                          //~v7c7I~
        else                                                       //~v7c7I~
        	rc=1;                                                  //~v7a7I~
    	UTRACEP("%s:rc=%d,ucs=0x%04x\n",UTT,rc,Pucs);              //~v7a7R~
    }                                                              //~v7a7I~
    return rc;                                                     //~v7a7R~
}//uvioGetCursorWidth                                              //~v7a7I~
#endif   //ndef WXE                                                //~v7agI~
#endif   //W32                                                     //~v7agI~
#endif   //!LNX                                                    //~v7agM~
#ifndef WXEXXE                                                     //~v7agI~
#ifdef LNXCON                                                      //~v7agI~
//*****************************************************************//~vbzCI~
int uvioGetFacenameW(int Popt,char *Pfacename,char *Poutu8,int Pbuffsz)//~vbzCI~
{                                                                  //~vbzCI~
	char *pnameA;                                                  //~vbzCI~
    int rc=0;                                                      //~vbzCR~
//***********************************                              //~vbzCI~
	UTRACEP("%s:Pfacename=%s\n",UTT,Pfacename);                    //~vbzCI~
    pnameA=Pfacename;                                              //~vbzCR~
	if (*pnameA=='8' && *(pnameA+1)=='-')  //parm is utf8 code     //~vbzCI~
    {                                                              //~vbzCI~
        pnameA+=2;                                                 //~vbzCI~
        if (*pnameA=='\"')                                         //~vbzCI~
        {                                                          //~vbzCI~
            pnameA++;                                              //~vbzCI~
            char *pc=strchr(pnameA,'\"');                          //~vbzCI~
            if (pc)                                                //~vbzCI~
            {                                                      //~vbzCI~
                *pc=0;                                             //~vbzCI~
            }                                                      //~vbzCI~
        }                                                          //~vbzCI~
        UstrncpyZ(Poutu8,pnameA,(UINT)Pbuffsz);                    //~vbzCR~
    }                                                              //~vbzCI~
    else                                                           //~vbzCI~
    {                                                              //~vbzCI~
        if (*pnameA=='\"')                                         //~vbzCI~
        {                                                          //~vbzCI~
            pnameA++;                                              //~vbzCI~
            char *pc=strchr(pnameA,'\"');                          //~vbzCI~
            if (pc)                                                //~vbzCI~
            {                                                      //~vbzCI~
                *pc=0;                                             //~vbzCI~
            }                                                      //~vbzCI~
        }                                                          //~vbzCI~
        if (strstr(pnameA,"\\u")||strstr(pnameA,"\\U"))            //~vbzCI~
        {                                                          //~vbzCI~
            int chklen,outlen,errctr;                              //~vbzCR~
            ULONG opt=UCVUCS_ESCUCS|UCVUCS_STRZU8;                 //~vbzCR~
            int rc2=ucvsucs2utf(0/*Perr*/,opt,pnameA,(int)strlen(pnameA),Poutu8,Pbuffsz,&chklen,&outlen,&errctr);//~vbzCR~
            if (rc2)                                               //~vbzCI~
                rc=4;                                              //~vbzCI~
        }                                                          //~vbzCI~
        else                                                       //~vbzCI~
	        UstrncpyZ(Poutu8,pnameA,(UINT)Pbuffsz);                //~vbzCR~
    }                                                              //~vbzCI~
    UTRACED("input facename",Pfacename,(int)strlen(Pfacename));    //~vbzCR~
    UTRACED("PoutU8",Poutu8,Pbuffsz);                              //~vbzCR~
    return rc;                                                     //~vbzCI~
}                                                                  //~vbzCI~
//*****************************************************************//~vbzCI~
//LNX                                                              //~vbzCI~
//*****************************************************************//~vbzCI~
void setConsoleFont(char *Pfontface)                               //~v7agI~
{                                                                  //~v7agI~
    char buff[LF_FACESIZE];                                        //~v7agI~
    char trim[LF_FACESIZE];                                        //~v7agI~
    char *pc;                                                      //~v7agI~
    int  trimlen;                                                //~v7agR~//~v7anR~
//    int charset=-1;                                              //~v7agI~
//    fprintf(stderr,"fnm=%s  ***************\n",Pfontface);       //~v7agR~
    if (*Pfontface=='@')    //filename                             //~v7agI~
    {                                                              //~v7agI~
        FILE *fh=fopen(Pfontface+1,"r");                           //~v7agI~
        if (!fh)                                                   //~v7agI~
            uerrexit("Open failed Font param file(%s).",           //~v7agI~
                    "フォント パラメータファイル オープンエラー(%s).",//~v7agI~
					Pfontface+1);                                  //~v7agI~
        if (!fgets(buff,sizeof(buff),fh))                          //~v7agI~
            uerrexit("Read failed Font param file(%s).",0,Pfontface+1);//~v7agI~
        pc=strchr(buff,'\n');                                      //~v7agI~
        if (pc)                                                    //~v7agI~
        	*pc=0;                                                 //~v7agI~
        pc=strchr(buff,'\r'); //for pc eol \r\n                    //~vbzCM~
        if (pc)                                                    //~vbzCM~
        	*pc=0;                                                 //~vbzCM~
//      printf("fnm=%s  ***************\n",Pfontface);             //~v7agR~
    }                                                              //~v7agI~
    else                                                           //~v7agI~
    if (*Pfontface=='%')                                           //~v7agI~
    {                                                              //~v7agI~
        char *penv=getenv(Pfontface+1);                            //~v7agI~
        if (penv && *penv)                                         //~v7agI~
        	UstrncpyZ(buff,penv,sizeof(buff));                     //~v7agI~
        else                                                       //~v7agI~
	    	uerrexit("Font parm(%s) err No environment variable is set(%s)\n",0,Pfontface,penv);//~v7agI~
    }                                                              //~v7agI~
    else                                                           //~v7agI~
    	UstrncpyZ(buff,Pfontface,sizeof(buff));                    //~v7agI~
//    pc=strchr(buff,':');                                         //~v7agI~
//    if (pc)                                                      //~v7agI~
//    {                                                            //~v7agI~
//        *pc=0;  //sep of charset                                 //~v7agI~
//        charset=atoi(pc+1);                                      //~v7agI~
//    }                                                            //~v7agI~
    if (*buff=='\"')                                               //~v7agI~
    {                                                              //~v7agI~
    	*buff=0;                                                   //~v7agI~
	    pc=strchr(buff+1,'\"');                                    //~v7agI~
    	if (pc)                                                    //~v7agI~
        	*pc=0;                                                 //~v7agI~
        pc=buff+1;                                                 //~v7agI~
    }                                                              //~v7agI~
    else                                                           //~v7agI~
    	pc=buff;                                                   //~v7agI~
    if (!*pc)                                                      //~v7agI~
	    uerrexit("Font parm(%s) format err\n",0,Pfontface);        //~v7agI~
	UstrncpyZ(SconsoleFont,pc,sizeof(SconsoleFont));               //~v7agI~
	umemtrim(0,SconsoleFont,(int)strlen(SconsoleFont),' ',trim,&trimlen);//~v7agI~
//    pc=strrchr(trim,' ');                                          //~v7agR~//~v7anR~
//    printf("trim=%s,pc=%s\n",trim,pc);                           //~v7agR~
//    if (pc)                                                        //~v7agI~//~v7anR~
//        sz=atoi(pc);                                               //~v7agR~//~v7anR~
	strcpy(SconsoleFont,trim);                                     //~v7agI~
//    ScharsetParm=charset;                                        //~v7agI~
    UTRACEP("%s:parm=%s,fontface=%s,size=%d\n",UTT,Pfontface,SconsoleFont);//~v7agI~//~v7anR~
//    printf("exit fnm=%s  ***************,sz=%d\n",SconsoleFont,sz);//~v7agR~
}                                                                  //~v7agI~
#else                                                              //~v7agI~
//*****************************************************************//~v7a7I~
//Win                                                              //~vbzCI~
//*****************************************************************//~vbzCI~
void setConsoleFont(char *Pfontface)                               //~v7a7I~//~vbzqR~//~v7adR~
{                                                                  //~v7a7I~
//  char buff[LF_FACESIZE*2+2];                                    //~v7adI~//~vbzCR~
    char buff[256];                                                //~vbzCI~
    char *pc;                                                      //~v7adI~
    int charset=-1;                                                //~v7adR~
//    fprintf(stderr,"fnm=%s  ***************\n",Pfontface);       //~v7adR~
    if (*Pfontface=='@')    //filename                             //~v7adI~
    {                                                              //~v7adI~
        FILE *fh=fopen(Pfontface+1,"r");                           //~v7adR~
        if (!fh)                                                   //~v7adI~
            uerrexit("Open failed Font param file(%s).",           //~v7adR~
                    "フォント パラメータファイル オープンエラー(%s).",//~v7adI~
					Pfontface+1);                                  //~v7adI~
        if (!fgets(buff,sizeof(buff),fh))                          //~v7adR~
            uerrexit("Read failed Font param file(%s).",0,Pfontface+1);//~v7adR~
        pc=strchr(buff,'\n');                                      //~v7adR~
        if (pc)                                                    //~v7adI~
        	*pc=0;                                                 //~v7adI~
//      printf("fnm=%s  ***************\n",Pfontface);             //~v7adR~
    }                                                              //~v7adI~
    else                                                           //~v7adI~
    if (*Pfontface=='%')                                           //~v7adR~
    {                                                              //~v7adI~
        char *penv=getenv(Pfontface+1);                            //~v7adI~
        if (penv && *penv)                                         //~v7adR~
        	UstrncpyZ(buff,penv,sizeof(buff));                     //~v7adI~
        else                                                       //~v7adI~
	    	uerrexit("Font parm(%s) err No environment variable is set(%s)\n",0,Pfontface,penv);//~v7adR~
    }                                                              //~v7adI~
    else                                                           //~v7adI~
    	UstrncpyZ(buff,Pfontface,sizeof(buff));                    //~v7adR~
    pc=strchr(buff,':');                                           //~v7adI~
    if (pc)                                                        //~v7adI~
    {                                                              //~v7adI~
    	*pc=0;	//sep of charset                                   //~v7adI~
    	charset=atoi(pc+1);                                        //~v7adI~
    }                                                              //~v7adI~
    if (*buff=='\"')                                               //~v7adI~
    {                                                              //~v7adI~
    	*buff=0;                                                   //~v7adI~
	    pc=strchr(buff+1,'\"');                                    //~v7adI~
    	if (pc)                                                    //~v7adI~
        	*pc=0;                                                 //~v7adR~
        pc=buff+1;                                                 //~v7adI~
    }                                                              //~v7adI~
    else                                                           //~v7adI~
    	pc=buff;                                                   //~v7adI~
    if (!*pc)                                                      //~v7adI~
	    uerrexit("Font parm(%s) format err\n",0,Pfontface);        //~v7adI~
	UstrncpyZ(SconsoleFont,pc,sizeof(SconsoleFont));        //~v7a7R~//~v7adR~
	ScharsetParm=charset;                                         //~vbzqM~//~v7adR~
    UTRACEP("%s:parm=%s,fontface=%s,charset=%d\n",UTT,Pfontface,SconsoleFont,ScharsetParm);//~v7adR~
//  printf("exit fnm=%s  ***************\n",SconsoleFont);         //~v7adR~
}                                                                  //~v7a7I~
#endif  //!LNXCON                                                  //~v7agI~
#endif //ndef WXEXXE                                               //~v7agI~
//#endif   //ndef WXE                                                //~v7a7I~//~v7agR~
//#endif   //W32                                                          //~v156I~//~v7a7R~//~v7agR~
#ifdef LNXCON                                                      //~v7agI~
//********************************************************************///~v7agI~
int getPangoSize(PangoLayout *Pplayout,int Pucs,int *Pww,int *Phh)                     //~4305I~//~v7agR~
{                                                                  //~4305I~//~v7agI~
	PangoRectangle recti,rectl;                          //~vbz5I~ //~4305I~//~v7agI~
	int ww,u8len,hh;                                               //~4305I~//~v7agR~
    char utf8[32];                                                 //~4305I~//~v7agI~
    u8len=uccvucs2utf(Pucs,utf8);                                  //~4305I~//~v7agI~
    utf8[u8len]=0;                                                 //~4305I~//~v7agI~
    pango_layout_set_text(Pplayout,utf8,u8len);                     //~4305R~//~v7agI~
    pango_layout_get_pixel_extents(Pplayout,&recti,&rectl);//get logical extent//~4305R~//~v7agI~
    ww=rectl.width;                                                //~4305R~//~v7agI~
    hh=rectl.height;                                               //~v7agI~
    UTRACEP("%s:pango layout pixcel ucs=0x%04x(%s),rc=%d,rect=(x=%d,y=%d-w=%d,h=%d),logical=(x=%d,y=%d-w=%d,h=%d)\n",//~4305R~//~v7agI~
            UTT,Pucs,utf8,ww,recti.x,recti.y,recti.width,recti.height, //~4305R~//~v7agI~
            rectl.x,rectl.y,rectl.width,rectl.height);             //~4305R~//~v7agI~
//    chklayout(Pplayout);                                           //~4306I~//~v7agI~
	*Pww=ww;                                                       //~v7agI~
	*Phh=hh;                                                       //~v7agI~
    return ww;                                                     //~4305R~//~v7agI~
}                                                                  //~4305I~//~v7agI~
//*****************************************************************//~v7agI~
//*LNX                                                             //~vbzCR~
//*return 1:wide,0:sbcs,-1:width=0                                 //~vbzCI~
//*****************************************************************//~v7awI~
int uvioIsWideGlyph(PangoLayout *Pplayout,int PfontH,int Pucs)     //~v7agI~
{                                                                  //~v7agI~
	int ww,hh;                                                     //~v7agI~
//************************                                         //~v7agI~
	getPangoSize(Pplayout,Pucs,&ww,&hh);                           //~v7agR~
    int rc=ww>(PfontH+1)/2;                                        //~v7agI~
    if (!ww)                                                       //~v7awR~
        rc=-1;                                                     //~v7awI~
    UTRACEP("%s:rc=%d,ww=%02d,fontH=%02d,ucs=0x%04x(%s)\n",UTT,rc,ww,PfontH,Pucs,UCV_U2F1(Pucs));//~v7agI~
    return rc;                                                     //~v7agI~
}                                                                  //~v7agI~
//********************************************************************///~v7agI~
int getFontSize(PangoLayout *Pplayout,int *PpMonospace)            //~v7agR~
{                                                                  //~v7agI~
    int wwA,hhA,wwW,hhW;                                           //~v7agI~
	getPangoSize(Pplayout,'A',&wwA,&hhA);                          //~v7agI~
	getPangoSize(Pplayout,'W',&wwW,&hhW);                          //~v7agI~
    int swMonospace=wwA==wwW;                                      //~v7agR~
    int fontH=hhA;                                                 //~v7agI~
    if (PpMonospace)                                               //~v7agI~
    	*PpMonospace=swMonospace;                                  //~v7agI~
    UTRACEP("%s:monospace=%d,fontH=%d\n",UTT,swMonospace,fontH);   //~v7agR~
    return fontH;                                                  //~v7agI~
}                                                                  //~v7agI~
//********************************************************************///~v7agI~
int searchFontList(PangoFontMap *pfm,char *Ppfamily)               //~v7agI~
{                                                                  //~v7agI~
  int nfam,rc=0,ii;                                                //~v7agI~
  PangoFontFamily **famlist,*fam;                                  //~v7agI~
//**********************                                           //~v7agI~
	UTRACEP("%s:face=%s\n",UTT,Ppfamily);                          //~v7agI~
    pango_font_map_list_families(pfm,&famlist,&nfam);              //~v7agI~
    for (ii=0;ii<nfam;ii++)                                        //~v7agI~
    {                                                              //~v7agI~
    	fam=famlist[ii];                                           //~v7agR~
	    const char* pfamilyName=pango_font_family_get_name(fam);//UTF8 string//~v7agI~
	    UTRACEP("%s:facename=%s\n",UTT,pfamilyName);               //~v7agR~
        if (!strcmp(pfamilyName,Ppfamily))                         //~v7agI~
        {                                                          //~v7agI~
            rc=1;                                                  //~v7agI~
        	break;                                                 //~v7agI~
        }                                                          //~v7agI~
    }                                                              //~v7agI~
  	UTRACEP("%s:rc=%d,parm=%s\n",UTT,rc,Ppfamily);                 //~v7agI~
    return rc;                                                     //~v7agI~
}                                                                  //~v7agI~
//********************************************************************///~v7agI~
int isValidFont(PangoFontDescription *Ppfontdesc)                  //~v7agR~
{                                                                  //~v7agI~
    char *pfamily=(char*)pango_font_description_get_family(Ppfontdesc);//~v7agR~
    if (!pfamily)                                                  //~v7axR~
    {                                                              //~v7axR~
    	return 0;                                                  //~v7axR~
    }                                                              //~v7axR~
    UTRACEP("%s:family=%s\n",UTT,pfamily);	//utf8 str             //~v7agI~
  	PangoFontMap *pfm;                                             //~v7agI~
    pfm=pango_cairo_font_map_get_default();                        //~v7agI~
	int rc=searchFontList(pfm,pfamily);                            //~v7agR~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v7agI~
    return rc;                                                     //~v7agI~
}                                                                  //~v7agI~
//********************************************************************///~v7agI~
//LNXCON                                                           //~v7ajI~
//********************************************************************///~v7ajI~
int uvioGetCursorWidth(int Popt,ULONG Pucs)                        //~v7agI~
{                                                                  //~v7agI~
static int SswDupCall=0;                                           //~v7agI~
static int SswErr=1;                                               //~v7agI~
static int SfontH;                                                 //~v7agI~
static	PangoLayout *Splayout;                                          //~4305R~//~v7agI~
	GtkWidget *pview=NULL;                                         //~4305R~//~v7agI~
	PangoFontDescription *pfontdesc;                               //~v7agI~
	int swMonospace;                                               //~v7agR~
	int rc=0;                                                      //~v7agR~
    int argc=0;                                                    //~v7agI~
    char **argv=NULL;                                              //~v7agI~
    char  faceU8[LF_FACESIZE];	//128                              //~vbzCI~
//************************                                         //~v7agI~
    UTRACEP("%s:opt=%x,ucs=u-%04x,Gulibutfmode=0x%08x\n",UTT,Popt,Pucs,Gulibutfmode);               //~v7agI~//~v7arI~
//#ifndef TEST                                                     //~v7c1R~
//        gtk_init(&argc,&argv);                                   //~v7c1R~
//        pview=gtk_window_new(GTK_WINDOW_TOPLEVEL);               //~v7c1R~
//        PangoContext *ppangocontext=gtk_widget_get_pango_context(pview);//~v7c1R~
//        UTRACEP("%s:PangoContext=%p\n",UTT,ppangocontext);       //~v7c1R~
//        pfontdesc=pango_context_get_font_description(ppangocontext);//~v7c1R~
//        UTRACEP("%s:fontdesc=%p,str=%s\n",UTT,pfontdesc,pango_font_description_to_string(pfontdesc));//~v7c1R~
//        //==>"Cantare11 11" returned                             //~v7c1I~
//#endif                                                           //~v7c1R~
    if (Guvio2Stat & UVIO2S_NOGLYPHCHK)//     //test skip close, to getglyph width after mapinit//~vbAnI~
    {                                                              //~vbAnI~
		UTRACEP("%s:return -1 NOGLYPHCHK option\n",UTT);           //~vbAnI~
    	return -1;                                                 //~vbAnI~
    }                                                              //~vbAnI~
    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)) //0x08000000  //utfwcwidth chr cursor step//~v7agI~//~v7awR~//~v7axR~//~v7awR~
    {                                                              //~v7b1I~
		UTRACEP("%s:opt=%x,ucs=u-%04x,return -1 by APICHK_CSR off Gulibutfmode=0x%08x\n",UTT,Popt,Pucs,Gulibutfmode);//~v7b1I~//~v7bhR~
        return -1;     //called for not only ambiguous but for category Cf(Format)//~v7awR~//~v7axR~//~v7awR~
    }                                                              //~v7b1I~
	if (Popt & UVGCWO_CLOSE) //    0x01        //close consolebuffer handle//~v7agI~
    {                                                              //~v7agI~
    	if (!(Popt & UVGCWO_FORCE))                                //~v7b1I~
        {                                                          //~v7b1I~
			UTRACEP("%s:CLOSE skip by no FORCE option\n",UTT);     //~v7b1I~
	        return 0;                                              //~v7b1I~
        }                                                          //~v7b1I~
        SswErr=1;                                                  //~v7agR~
        SswDupCall=0;                                              //~v7agR~
		UTRACEP("%s:CLOSE return\n",UTT);                          //~v7agI~
        return 0;                                                  //~v7agI~
    }                                                              //~v7agI~
    else                                                           //~v7agI~
	if (Popt & UVGCWO_OPEN) //    0x01        //close consolebuffer handle//~v7agI~
    {                                                              //~v7agI~
		if (SswDupCall)                                            //~v7agR~
        	return -1;                                             //~v7agI~
        if (!*SconsoleFont)                                        //~v7agI~
        {                                                          //~v7ajI~
//		  if (!UTF_AMBIG2CELLMODE())  //Not mode of no adjust all  //~v7aqI~//~v7awR~
            if (getLinuxConsoleFont(GLCFO_MSG,SconsoleFont,(int)sizeof(SconsoleFont)))//~v7anR~
            {                                                      //~v7anI~
//                uerrmsg("-Ffontname cmdline parameter is required to adjust cell width of unicode of ambiguous width by -GY. \n",//~v7ajI~//~v7bhR~
//                        "-GY オプションでユニコードの\x95\\示幅を調整するには -F でフォント名を指定する必要があります");//~v7bhR~
//                uerrmsg("If you are root user by \"sudo xe\", and  /root/.config/dconf/user\" is missing,\n"//~v7bhR~
//                        "alternatively try \"cp /home/USER/.config/dconf/user /root/.config/dconf/user\".\n",0);//~v7bhR~
                showFontWarning(0,0,0/*parm*/); //LNX              //~v7bhR~
        		return -1;                                             //~v7agI~//~v7anR~
            }                                                      //~v7anI~
        }                                                          //~v7ajI~
        else                                                       //~vbzCI~
        {                                                          //~vbzCI~
    		int rc2=uvioGetFacenameW(0,SconsoleFont,faceU8,sizeof(faceU8));//~vbzCI~
            if (!rc2)                                              //~vbzCI~
            	strcpy(SconsoleFont,faceU8);                       //~vbzCI~
        }                                                          //~vbzCI~
//      printf("Create Font:%s\n",SconsoleFont);                   //~vbzCR~//~v7c1R~
        gtk_init(&argc,&argv);                                         //~4305R~//~4306R~//~v7agI~
        pview=gtk_window_new(GTK_WINDOW_TOPLEVEL);                     //~4305I~//~v7agI~
        UTRACEP("%s:pview=%p\n",UTT,pview);                                    //~4305I~//~v7agI~
        if (!pview)                                                //~v7agI~
        	return -1;                                             //~v7agI~
//        PangoContext *ppangocontext=gtk_widget_get_pango_context(pview);           //~vXXEM~//~4305R~//~v7agI~
//        printf("PangoContext=%p\n",ppangocontext);                     //~4305R~//~v7agI~
//        pfontdesc=pango_context_get_font_description(ppangocontext);//~vXXEI~//~4305R~//~v7agI~
//        pfontdescContext=pfontdesc;                                    //~4305I~//~v7agI~
//        printf("fontdesc=%p,str=%s\n",pfontdesc,pango_font_description_to_string(pfontdesc));//~4305R~//~v7agI~
        pfontdesc=pango_font_description_from_string(SconsoleFont);    //~4305R~//~v7agR~
        UTRACEP("%s:fontdesc=%p,parm=%s,str=%s\n",UTT,pfontdesc,SconsoleFont,pango_font_description_to_string(pfontdesc));//~4305I~//~v7agR~
        if (!pfontdesc)                                            //~v7agI~
        	return -1;                                             //~v7agI~
        UTRACEP("%s:size=%d,fontdesc=%p,parm=%s,str=%s\n",UTT,pango_font_description_get_size(pfontdesc),pfontdesc,SconsoleFont,pango_font_description_to_string(pfontdesc));//~v7agR~
        if (!isValidFont(pfontdesc))                               //~v7agI~
        {                                                          //~v7agI~
//	    	uerrexit("Font parm(%s) is unknown font name.\n",0,SconsoleFont);//~v7agR~//~v7c1R~
  	    	uerrmsg("Font parm(\"%s\") is unknown font name.\n",0,SconsoleFont);//~v7c1R~
        	return -1;                                             //~v7c1I~
        }                                                          //~v7agI~
        Splayout=gtk_widget_create_pango_layout(pview,NULL);           //~vamgI~//~4305R~//~v7agI~
        UTRACEP("%s:layout=%p\n",UTT,Splayout);                                 //~4305I~//~v7agI~
        if (!Splayout)                                             //~v7agI~
        	return -1;                                             //~v7agI~
        pango_layout_set_font_description(Splayout,pfontdesc);          //~vamgI~//~4305I~//~v7agI~
//        const PangoFontDescription *pfontd=pango_layout_get_font_description(Splayout);//TODO test//~v7agR~
//        UTRACEP("%s:confirm fontdesc=%p,str=%s\n",UTT,pfontd,pango_font_description_to_string(pfontd));//~v7agR~
                                                                   //~v7agI~
        SfontH=getFontSize(Splayout,&swMonospace);                 //~v7agI~
        if (SfontH<=0)                                             //~v7agI~
        {                                                          //~v7agI~
	    	uerrexit("Font parm(%s) err missing size\n",0,SconsoleFont);//~v7agI~
        }                                                          //~v7agI~
    	if (swMonospace)                                           //~v7agI~
	    	Guvio2Stat|=UVIO2S_CONSOLE_MONOFONT;                   //~v7agI~
    	else                                                       //~v7agI~
    		Guvio2Stat&=~UVIO2S_CONSOLE_MONOFONT;                  //~v7agI~
        SswErr=0;                                                  //~v7agI~
    }                                                              //~v7agI~
    else                                                           //~v7agI~
    if (SswErr)                                                    //~v7agR~
    {                                                              //~v7awI~
    	UTRACEP("%s:rc=-1 by SswErr ucs=0x%04x\n",UTT,rc,Pucs);    //~v7awI~
    	return -1;                                                 //~v7agI~
    }                                                              //~v7awI~
    else                                                           //~v7agI~
    if (!*SconsoleFont)                                            //~v7axI~
    {                                                              //~v7awI~
    	UTRACEP("%s:rc=-1 by !*SconsoleFont ucs=0x%04x\n",UTT,rc,Pucs);//~v7awI~
    	return -1;                                                 //~v7axI~
    }                                                              //~v7awI~
    else                                                           //~v7axI~
    {                                                              //~v7agI~
		rc=uvioIsWideGlyph(Splayout,SfontH,(int)Pucs);             //~v7agR~
//        if (rc==1)                                                 //~v7agI~//~v7awR~
//            rc=2;                                                  //~v7agI~//~v7awR~
//        else                                                       //~v7agI~//~v7awR~
//            rc=1;                                                  //~v7agI~//~v7awR~
		rc++;		//-1->0,1(dbcs)-->2                            //~v7awI~
    	UTRACEP("%s:rc=%d,ucs=0x%04x\n",UTT,rc,Pucs);              //~v7agI~
    }                                                              //~v7agI~
    return rc;                                                     //~v7agI~
}//uvioGetCursorWidth                                              //~v7agI~
#ifdef AAA                                                         //~v7c0I~
//********************************************************         //~v7anI~
int getLinuxConsoleFont(int Popt,char *Ppfontface,int Pbuffsz)     //~v7anI~
{                                                                  //~v7anI~
    int rc,stdoctr,stdectr,opt;                                    //~v7anI~
    char **pstde,*pc,*pc2,**pstdo,*pcmd,*pface=0,**ppc;            //~v7anI~
//********************************                                 //~v7anI~
    UTRACEP("%s:entry\n",UTT);                                     //~v7anI~
    if (Popt & GLCFO_MSG)                                          //~v7anI~
    {                                                              //~v7beI~
//        fprintf(stderr,"Trying to get Terminal font by dconf command. If failed, specify fontname by /F cmdline option!!\n");//~v7bhR~
//        fprintf(stderr,"If it failes when root user by \"sudo xe\", and /root/.config/dconf/user\" is missing,\n"//~v7bhR~
//                        "try after \"cp /home/USER/.config/dconf/user /root/.config/dconf/user\".\n");//~v7bhR~
        showFontWarning(1,0,0);  //LNX                             //~v7bhR~
    }                                                              //~v7beI~
    opt=UPROC_LANGC|UPROC_NOMSG;                                   //~v7anI~
//  pcmd="dconf dump /org/gnome/terminal/";                        //~v7anI~//~v7bhR~
    pcmd=DCONF_DUMP;                                               //~v7bhI~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v7anI~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v7anI~
	for (ppc=pstdo;*ppc;ppc++)                                     //~v7anI~
    {                                                              //~v7anI~
        rc=4;                                                      //~v7anI~
        if (!ppc)                                                  //~v7anI~
            break;                                                 //~v7anI~
        pc=*ppc;                                                   //~v7anI~
        if (!pc)                                                   //~v7anI~
            break;                                                 //~v7anI~
        UTRACEP("%s:stdo=%s\n",UTT,pc);                            //~v7anI~
        pc2=strstr(pc,"font=");                                    //~v7anI~
        if (!pc2)                                                  //~v7anI~
           continue;                                               //~v7anI~
        pc=pc2+5;                                                  //~v7anI~
        pc2=strchr(pc,'\n');                                       //~v7anI~
        if (pc2)                                                   //~v7anI~
        	*pc2=0;                                                //~v7anI~
        pface=pc;                                                  //~v7anI~
        if (*pc=='\'')                                             //~v7anI~
        {                                                          //~v7anI~
        	pc2=strchr(pc+1,'\'');                                 //~v7anI~
            if (pc2)                                               //~v7anI~
            {                                                      //~v7anI~
            	*pc2=0;                                            //~v7anI~
                pface++;                                           //~v7anI~
            }                                                      //~v7anI~
        }                                                          //~v7anI~
        break;                                                     //~v7anI~
    }                                                              //~v7anI~
    if (pstdo)                                                     //~v7anI~
	    ufree(pstdo);                                              //~v7anI~
    if (pstde)                                                     //~v7anI~
	    ufree(pstde);                                              //~v7anI~
    if (pface)                                                     //~v7anI~
    {                                                              //~v7anI~
	    UstrncpyZ(Ppfontface,pface,(UINT)Pbuffsz);                 //~v7anI~
    	if (Popt & GLCFO_MSG)                                      //~v7anI~
    		printf("Terminal font \"%s\" was detected\n",pface);   //~v7anR~
        rc=0;                                                      //~v7anI~
    }                                                              //~v7anI~
    else                                                           //~v7anI~
    {                                                              //~v7anI~
    	if (Popt & GLCFO_MSG)                                      //~v7anI~
    		printf("Failed to get Terminal font!!\n");             //~v7anI~
    	rc=4;                                                      //~v7anI~
    }                                                              //~v7anI~
    UTRACEP("%s:rc=%d,face=%s\n",UTT,rc,pface);                    //~v7anI~
    return rc;                                                     //~v7anI~
}//getLinuxConsoleFont                                             //~v7anI~
#else                                                              //~v7c0I~
//********************************************************         //~v7c1I~
//*LNX                                                             //~v7c1I~
//*get font from default profile; out source the logic to xeGetFont.sh//~v7c1I~
//********************************************************         //~v7c1I~
int getLinuxConsoleFontSH(int Popt,char *Ppfontface,int Pbuffsz)   //~v7c1I~
{                                                                  //~v7c1I~
    int rc,stdoctr,stdectr,opt;                                    //~v7c1I~
    char **pstde,*pc,**pstdo,*pcmd,*pface=0,**ppc;                 //~v7c1R~
//********************************                                 //~v7c1I~
    UTRACEP("%s:entry\n",UTT);                                     //~v7c1I~
    if (Popt & GLCFO_MSG)                                          //~v7c1I~
    {                                                              //~v7c1I~
        showFontWarning(3,0,0);  //LNX                             //~v7c1I~
    }                                                              //~v7c1I~
    opt=UPROC_LANGC|UPROC_NOMSG;                                   //~v7c1I~
    pcmd=XEGETFONT_SH; //"xeGetFont.sh"                            //~v7c1I~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v7c1I~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s,stdoctr=%d,stdectr=%d\n",UTT,rc,pcmd,stdoctr,stdectr);//~v7c1I~
    if (Popt & GLCFO_MSG)                                          //~v7c1I~
    {                                                              //~v7c1I~
        for (ppc=pstde;*ppc;ppc++)                                 //~v7c1I~
        {                                                          //~v7c1I~
            if (!ppc)                                              //~v7c1I~
                break;                                             //~v7c1I~
            pc=*ppc;                                               //~v7c1I~
            if (!pc)                                               //~v7c1I~
                break;                                             //~v7c1I~
            UTRACEP("%s:stde=%s\n",UTT,pc);                        //~v7c1I~
            printf("%s\n",pc);                                     //~v7c1I~
        }                                                          //~v7c1I~
    }                                                              //~v7c1I~
    if (stdoctr==1)                                                //~v7c1I~
    {                                                              //~v7c1I~
		pface=*pstdo;                                              //~v7c1I~
    	UTRACEP("%s:%s succeeded font=%s\n",UTT,pcmd,pface);       //~v7c1I~
	    UstrncpyZ(Ppfontface,pface,(UINT)Pbuffsz);                 //~v7c1I~
    	if (Popt & GLCFO_MSG)                                      //~v7c1I~
    		printf("Terminal font \"%s\" was detected\n",pface);   //~v7c1I~
        rc=0;                                                      //~v7c1I~
    }                                                              //~v7c1I~
    else                                                           //~v7c1I~
    {                                                              //~v7c1I~
    	if (Popt & GLCFO_MSG)                                      //~v7c1I~
    	    printf("%s Failed to get Terminal font!!\n",pcmd);     //~v7c1I~
    	rc=4;                                                      //~v7c1I~
    }                                                              //~v7c1I~
    if (pstdo)                                                     //~v7c1I~
	    ufree(pstdo);                                              //~v7c1I~
    if (pstde)                                                     //~v7c1I~
	    ufree(pstde);                                              //~v7c1I~
    UTRACEP("%s:rc=%d,face=%s\n",UTT,rc,pface);                    //~v7c1I~
    return rc;                                                     //~v7c1I~
}//getLinuxConsoleFontSH                                           //~v7c1I~
#ifdef BBB                                                         //~v7c1R~
//********************************************************         //~v7c0I~
//*LNX                                                             //~v7c1I~
//*get font from default profile                                   //~v7c0I~
//********************************************************         //~v7c0I~
int getLinuxConsoleFont(int Popt,char *Ppfontface,int Pbuffsz)     //~v7c0I~
{                                                                  //~v7c0I~
    int rc,stdoctr,stdectr,opt;                                    //~v7c0I~
    char **pstde,*pc,*pc2,**pstdo,*pcmd,*pface=0,**ppc;            //~v7c0I~
    char cmdreadfont[512];                                         //~v7c0I~
//********************************                                 //~v7c0I~
    UTRACEP("%s:entry\n",UTT);                                     //~v7c0I~
    if (Popt & GLCFO_MSG)                                          //~v7c0I~
    {                                                              //~v7c0I~
        showFontWarning(1,0,0);  //LNX                             //~v7c0I~
    }                                                              //~v7c0I~
    opt=UPROC_LANGC|UPROC_NOMSG;                                   //~v7c0I~
    pcmd=DCONF_CMDHELP; //"dconf -h"    chk existing               //~v7c0R~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v7c0I~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v7c0I~
    if (pstdo)                                                     //~v7c0I~
	    ufree(pstdo);                                              //~v7c0I~
    if (pstde)                                                     //~v7c0I~
	    ufree(pstde);                                              //~v7c0I~
    if (rc)                                                        //~v7c0M~
    {                                                              //~v7c0M~
        Sfonterr=1;                                                //~v7c0I~
    	UTRACEP("%s: %s cmd not found rc=%d\n",UTT,pcmd,rc);       //~v7c0R~
    	if (Popt & GLCFO_MSG)                                      //~v7c0I~
	    	printf("%s cmd failed rc=0x%04x\n",pcmd,rc);           //~v7c0R~
        return rc;                                                 //~v7c0M~
    }                                                              //~v7c0M~
    pcmd=DCONF_READ DCONF_READ_DEFAULT_PROFILE; //"dconf read /org/gnome/terminal/legacy/profiles:/default"//~v7c0I~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v7c0I~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v7c0I~
    rc=4;                                                          //~v7c0I~
	for (ppc=pstdo;*ppc;ppc++)                                     //~v7c0I~
    {                                                              //~v7c0I~
        if (!ppc)                                                  //~v7c0I~
            break;                                                 //~v7c0I~
        pc=*ppc;                                                   //~v7c0I~
        if (!pc)                                                   //~v7c0I~
            break;                                                 //~v7c0I~
        UTRACEP("%s:stdo=%s\n",UTT,pc);                            //~v7c0I~
        if (*pc=='\'')                                             //~v7c0R~
        {                                                          //~v7c0I~
        	pc++;                                                  //~v7c0I~
	        pc2=strchr(pc,'\'');                                   //~v7c0I~
            if (pc2)                                               //~v7c0I~
            	*pc2=0;                                            //~v7c0I~
        }                                                          //~v7c0I~
        pc2=strchr(pc,'\n');                                       //~v7c0I~
        if (pc2)                                                   //~v7c0I~
        	*pc2=0;                                                //~v7c0I~
        rc=0;                                                      //~v7c0I~
        break;                                                     //~v7c0I~
    }                                                              //~v7c0I~
    if (pstdo)                                                     //~v7c0I~
	    ufree(pstdo);                                              //~v7c0I~
    if (pstde)                                                     //~v7c0I~
	    ufree(pstde);                                              //~v7c0I~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v7c0I~
    if (rc)                                                        //~v7c0I~
    {                                                              //~v7c0I~
    	UTRACEP("%s:get defaultprofile failed\n",UTT,rc,pcmd);     //~v7c0I~
    	return rc;                                                 //~v7c0I~
    }                                                              //~v7c0I~
    sprintf(cmdreadfont,DCONF_READ DCONF_READ_DEFAULT_FONT,pc);//    "legacy/profiles:/:%s/ font"//~v7c0I~
    pcmd=cmdreadfont;                                              //~v7c0I~
	rc=usystem_redirect(opt,pcmd,&pstdo,&pstde,&stdoctr,&stdectr); //~v7c0I~
    UTRACEP("%s:usystem_redirect rc=%d,cmd=%s\n",UTT,rc,pcmd);     //~v7c0I~
    rc=4;                                                          //~v7c0I~
	for (ppc=pstdo;*ppc;ppc++)                                     //~v7c0I~
    {                                                              //~v7c0I~
        if (!ppc)                                                  //~v7c0I~
            break;                                                 //~v7c0I~
        pc=*ppc;                                                   //~v7c0I~
        if (!pc)                                                   //~v7c0I~
            break;                                                 //~v7c0I~
        UTRACEP("%s:stdo=%s\n",UTT,pc);                            //~v7c0I~
        if (*pc=='\'')                                             //~v7c0R~
        {                                                          //~v7c0I~
        	pc++;                                                  //~v7c0I~
	        pc2=strchr(pc,'\'');                                   //~v7c0I~
            if (pc2)                                               //~v7c0I~
            	*pc2=0;                                            //~v7c0I~
        }                                                          //~v7c0I~
        pc2=strchr(pc,'\n');                                       //~v7c0I~
        if (pc2)                                                   //~v7c0I~
        	*pc2=0;                                                //~v7c0I~
        rc=0;                                                      //~v7c0I~
        break;                                                     //~v7c0I~
    }                                                              //~v7c0I~
    if (pstdo)                                                     //~v7c0I~
	    ufree(pstdo);                                              //~v7c0I~
    if (pstde)                                                     //~v7c0I~
	    ufree(pstde);                                              //~v7c0I~
    pface=pc;                                                      //~v7c0R~
    if (pface)                                                     //~v7c0I~
    {                                                              //~v7c0I~
	    UstrncpyZ(Ppfontface,pface,(UINT)Pbuffsz);                 //~v7c0I~
    	if (Popt & GLCFO_MSG)                                      //~v7c0I~
    		printf("Terminal font \"%s\" was detected\n",pface);   //~v7c0I~
        rc=0;                                                      //~v7c0I~
    }                                                              //~v7c0I~
    else                                                           //~v7c0I~
    {                                                              //~v7c0I~
    	if (Popt & GLCFO_MSG)                                      //~v7c0I~
    		printf("Failed to get Terminal font!!\n");             //~v7c0I~
    	rc=4;                                                      //~v7c0I~
    }                                                              //~v7c0I~
    UTRACEP("%s:rc=%d,face=%s\n",UTT,rc,pface);                    //~v7c0I~
    return rc;                                                     //~v7c0I~
}//getLinuxConsoleFont                                             //~v7c0I~
#else  //else BBB                                                  //~v7c1R~
//********************************************************         //~v7c1I~
int getLinuxConsoleFont(int Popt,char *Ppfontface,int Pbuffsz)     //~v7c1I~
{                                                                  //~v7c1I~
    int rc=getLinuxConsoleFontSH(Popt,Ppfontface,Pbuffsz);         //~v7c1I~
    return rc;                                                     //~v7c1I~
}//getLinuxConsoleFont                                             //~v7c1I~
#endif                                                             //~v7c0I~
#endif  //AAA                                                      //~v7c1I~
#endif  //LNXCON                                                   //~v7agI~
#ifdef WINCON                                                      //~v7aqI~
//********************************************************         //~v7aqI~
int getfaceW(char *Pface,wchar_t *PpfaceW,int PbuffszW,char *PpfaceMB,int PbuffszMB)//~v7aqR~
{                                                                  //~v7aqI~
    char wkutf8[LF_FACESIZE*UTF8_MAXCHARSZMAX/*6*/];               //~v7aqI~
    int chklen,outlen,errctr,rc;                                   //~v7aqI~
//**********************                                           //~v7aqI~
	int opt=UCVUCS_ESCUCS|UCVUCS_STRZU8;                          //~v7aqI~//~v7arR~
	rc=ucvsucs2utf(0,opt,Pface,(int)strlen(Pface),wkutf8,(int)sizeof(wkutf8),&chklen,&outlen,&errctr);//~v7aqI~
    if (!rc)                                                       //~v7aqI~
    {                                                              //~v7aqI~
        opt=UCVUCS_LE;                                             //~v7aqI~
		rc=ucvsutf2ucs(0/*Pferr*/,opt,wkutf8,(int)strlen(wkutf8),(UCHAR *)PpfaceW,PbuffszW,&chklen,&outlen,&errctr);//~v7aqI~
		opt=UTFCVO_STRZ;                                           //~v7aqI~
		uviocvU2L(opt,PpfaceW,PpfaceMB,PbuffszMB);           //~v7aqI~//~v7arR~
    }                                                              //~v7aqI~
    return rc;                                                     //~v7aqI~
}                                                                  //~v7aqI~
//********************************************************         //~v7aqI~
int getW32ConsoleFont(int Popt,char *Ppface,int Pbuffsz,int *Ppsz,wchar_t *PpfaceW,int PbuffszW)//~v7aqR~
{                                                                  //~v7aqI~
    #define BLOCK1 "\"profiles\""                                  //~v7aqI~
    #define BLOCK2 "\"list\""                                      //~v7aqI~
    #define BLOCK3 "\"font\""                                      //~v7aqI~
    #define BLOCKEND '}'                                           //~v7aqI~
    #define ITEM1  "\"face\":"                                     //~v7aqI~
    #define ITEM2  "\"size\":"                                     //~v7aqI~
    #define MSGSZ   4096                                           //~v7aqI~
                                                                   //~v7aqI~
    int rc,len,sz=0;                                               //~v7aqR~
    char *pc,*pc2,*pc3;                                            //~v7aqI~
    char fnm[_MAX_PATH],fpath[_MAX_PATH];                          //~v7aqR~
    char buff[1024];                                               //~v7aqI~
    char face[(LF_FACESIZE+1)*6]={0};   //5 for \uxxxx                               //~v7aqR~//~v7arR~
    char faceMB[LF_FACESIZE*UTF8_MAXCHARSZMAX/*6*/]={0};           //~v7aqI~
    FILE *fh;                                                      //~v7aqI~
    char *errmsg,*pce;                                             //~v7aqI~
//********************************                                 //~v7aqI~
    UTRACEP("%s:entry\n",UTT);                                     //~v7aqI~
    errmsg=umalloc(MSGSZ);                                         //~v7aqI~
    pce=errmsg;                                                    //~v7aqI~
    if (Popt & GWCFO_MSG)                                          //~v7aqR~
    {                                                              //~v7arI~
//      printf("Trying to get Windows Terminal font from settings.json file. If failed, specify fontname by /F cmdline option!!\n");//~v7aqR~//~v7bhR~
//      pce+=sprintf(pce,"Trying to get Windows Terminal font from settings.json file. If failed, specify fontname by /F cmdline option!!\n");//~v7bhR~
    	pce+=showFontWarning(1,pce,0); //WIN                       //~v7bhR~
    }                                                              //~v7arI~
    for (rc=4;;)                                                   //~v7aqI~
    {                                                              //~v7aqI~
	    pc=getenv(TOPDIR);                                         //~v7aqI~
        if (!pc || !*pc)                                           //~v7aqI~
        {                                                          //~v7aqI~
		 	if (Popt & GWCFO_MSG)                                  //~v7aqR~
    			pce+=sprintf(pce,"No environt variable(%s) is not set.\n",TOPDIR);//~v7aqR~
            break;                                                 //~v7aqI~
        }                                                          //~v7aqI~
        len=(int)strlen(pc);                                       //~v7aqI~
        memcpy(fnm,pc,(UINT)len);                                  //~v7aqI~
        if (fnm[len-1]!='\\')                                      //~v7aqI~
        	fnm[len++]='\\';                                       //~v7aqI~
        strcpy(fnm+len,SETTINGFILE);                               //~v7aqI~
        ufullpathwildexp(0,fpath,fnm,sizeof(fpath));               //~v7aqI~
        fh=fopen(fpath,"r");                                       //~v7aqR~
        if (!fh)                                                   //~v7aqI~
        {                                                          //~v7aqI~
		 	if (Popt & GWCFO_MSG)                                  //~v7aqR~
    			pce+=sprintf(pce,"Setting file(%s) open failed.\n",fnm);//~v7aqR~
            break;                                                 //~v7aqI~
        }                                                          //~v7aqI~
        int swFound=0;                                             //~v7aqI~
        face[0]=0;                                                 //~v7aqI~
        for (;;)                                                   //~v7aqI~
        {                                                          //~v7aqI~
        	if (!fgets(buff,sizeof(buff),fh))                      //~v7aqI~
            	break;                                             //~v7aqI~
            pc=buff+strspn(buff," ");                              //~v7aqR~
            if (strstr(pc,BLOCK1)==pc) //profile                   //~v7aqI~
            {                                                      //~v7aqI~
                swFound=1;                                         //~v7aqI~
                continue;                                          //~v7aqI~
            }                                                      //~v7aqI~
            if (strstr(pc,BLOCK2)==pc) //list                      //~v7aqI~
            {                                                      //~v7aqI~
                if (swFound==1)                                    //~v7aqI~
                	swFound=2;                                     //~v7aqI~
                continue;                                          //~v7aqI~
            }                                                      //~v7aqI~
            if (strstr(pc,BLOCK3)==pc) //font                      //~v7aqI~
            {                                                      //~v7aqI~
                if (swFound==2)                                    //~v7aqI~
                	swFound=3;                                     //~v7aqI~
                continue;                                          //~v7aqI~
            }                                                      //~v7aqI~
            if (strstr(pc,ITEM1)==pc) //font                       //~v7aqI~
            {                                                      //~v7aqI~
                if (swFound==3)                                    //~v7aqI~
                {                                                  //~v7aqI~
                	pc2=pc+sizeof(ITEM1);                          //~v7aqI~
                	pc2+=strspn(pc2," ");                          //~v7aqR~
                    UstrncpyZ(face,pc2,sizeof(face));              //~v7aqR~
                    pc2=face;                                      //~v7aqI~
                    if (*pc2=='\"')                                //~v7aqR~
                    {	                                           //~v7aqI~
                    	pc3=strchr(pc2+1,'\"');                    //~v7aqR~
                        if (pc3)                                   //~v7aqI~
                        	*pc3=0;                                //~v7aqI~
                        strcpy(pc2,pc2+1);                         //~v7aqI~
                    }                                              //~v7aqI~
                	swFound=4;                                     //~v7aqI~
                }                                                  //~v7aqI~
                continue;                                          //~v7aqI~
            }                                                      //~v7aqI~
            if (strstr(pc,ITEM2)==pc) //size                       //~v7aqI~
            {                                                      //~v7aqI~
                if (swFound==4)                                    //~v7aqI~
                {                                                  //~v7aqI~
                	pc2=pc+sizeof(ITEM2);                          //~v7aqI~
                	pc2+=strspn(pc2," ");                          //~v7aqR~
                    sz=atoi(pc2);                                  //~v7aqI~
                	swFound=5;                                     //~v7aqI~
                }                                                  //~v7aqI~
                continue;                                          //~v7aqI~
            }                                                      //~v7aqI~
            if (*pc==BLOCKEND) //font                              //~v7aqI~
            {                                                      //~v7aqI~
            	if(swFound==4)                                     //~v7aqI~
                	break;                                         //~v7aqI~
            }                                                      //~v7aqI~
        }//fgets                                                   //~v7aqI~
        fclose(fh);                                                //~v7bhR~
        if (!face[0])                                              //~v7aqI~
        {                                                          //~v7aqI~
		 	if (Popt & GWCFO_MSG)                                  //~v7aqR~
    			pce+=sprintf(pce,"Could not find font face from %s.\n",fnm);//~v7aqR~
            break;                                                 //~v7aqI~
        }                                                          //~v7aqI~
        rc=0;                                                      //~v7aqI~
        break;                                                     //~v7aqI~
    }//for                                                         //~v7aqI~
    if (!rc)                                                       //~v7aqI~
    {                                                              //~v7aqI~
    	rc=getfaceW(face,PpfaceW,PbuffszW,faceMB,sizeof(faceMB));  //~v7aqR~
        if (rc)                                                    //~v7aqI~
        {                                                          //~v7aqI~
		 	if (Popt & GWCFO_MSG)                                  //~v7aqI~
    			pce+=sprintf(pce,"Unicode translation error for font face name(%s).\n",face);//~v7aqI~
        }                                                          //~v7aqI~
    }                                                              //~v7aqI~
    if (rc)	                                                       //~v7aqM~
    {                                                              //~v7aqI~
		if (Popt & GWCFO_MSG)                                      //~v7aqM~
	    	uerrmsg(errmsg,0);                                     //~v7aqM~
    }                                                              //~v7aqI~
    else                                                           //~v7aqI~
    {                                                              //~v7aqI~
		if (Popt & GWCFO_MSG)                                      //~v7aqM~
        {                                                          //~v7aqI~
    		pce+=sprintf(pce,"Found font face:%s, size:%d file:%s\n",faceMB,sz,fnm);//~v7aqI~//~v7arR~
//  		uerrmsg("Found font face:%s,size:%d from %s\n",0,faceMB,sz,fnm);//TODO test //~v7aqI~//~v7arR~
        }                                                          //~v7aqI~
    	strcpy(Ppface,faceMB);                                     //~v7aqI~
    	if (Ppsz)                                                  //~v7aqM~
    		*Ppsz=sz;                                              //~v7aqM~
    }                                                              //~v7aqI~
	ufree(errmsg);                                                 //~v7aqI~
    return rc;                                                     //~v7aqI~
}//getLinuxConsoleFont                                             //~v7aqI~
#endif //WINCON                                                    //~v7aqI~
//**********************************************                   //~v7bhI~
//*issue err msg when get fontname failed                          //~v7bhI~
//**********************************************                   //~v7bhI~
int showFontWarning(int Popt/*1:fprintf,0:uerrmsg*/,char *Pmsg,int Pparm)//~v7bhR~
{                                                                  //~v7bhI~
	int rc=0;                                                      //~v7bhI~
#ifdef LNX                                                         //~v7bhR~
#ifdef LNXCON                                                      //~v7bhI~
	if (Popt==0)                                                   //~v7bhR~
    {                                                              //~v7bhI~
//      uerrmsg("-Ffontname cmdline parameter is required to adjust cell width of unicode of ambiguous width by -GY. \n",//~v7bhR~
//              "-GY オプションでユニコードの\x95\\示幅を調整するには -F でフォント名を指定する必要があります");//~v7bhR~
//      uerrmsg("If you are root user by \"sudo xe\", and  /root/.config/dconf/user\" is missing,\n"//~v7bhR~
//              "alternatively try \"cp /home/USER/.config/dconf/user /root/.config/dconf/user\".\n",0);//~v7bhR~
//      if (Sfonterr==1)                                           //~v7c0I~//~v7c9R~
//     		uerrmsg("dconf cmd failed. It may not be installed.\n",0);//~v7c0I~//~v7c9R~
//      uerrmsg("Failed to get font name.\n"                       //~v7bhI~//~v7c9R~
        uerrmsg("Failed to get font name by \"%s\".\n"             //~v7c9R~
				"If you fails when sudo-ing, try \"sudo -E xe\".\n",//~v7bhI~
				"フォント名の取得に失敗しました。(\"%s\")\n"       //~v7c9I~
				"sudo すると失敗する場合は \"sudo -E xe\" を試してください。\n"//~v7bhI~
				,XEGETFONT_SH                                      //~v7c9I~
                );                                                 //~v7bhI~
        uerrmsg("Font are used to adjust the display width of characters depending -G cmdline option.\n"//~v7bhI~//~v7c1R~
				"If obtaining the font name fails, specify a font name by the -F cmdline option.\n\n"//~v7bhI~//~v7c1R~
				"Ignore this warning if you are using limited range of unicode.\n",//~v7bhI~//~v7c1R~
				"フォントは -G コマンドラインオプションに従って文字の\x95\\示幅を調整するために使用されます。\n"//~v7c1I~
				"フォント名の取得に失敗する場合は -F コマンドラインパラメータでフォント名を指定してください。\n\n"//~v7c1I~
				"使用するユニコードの範囲が限定的な場合はこの警告は無視してください。\n");//~v7c1I~
    }                                                              //~v7bhI~
    else                                                           //~v7bhI~
	if (Popt==1)                                                   //~v7bhR~
    {                                                              //~v7bhI~
//        fprintf(stderr,"Trying to get Terminal font by dconf command. If failed, specify fontname by /F cmdline option!!\n");//~v7bhR~
//        fprintf(stderr,"If it failes when root user by \"sudo xe\", and /root/.config/dconf/user\" is missing,\n"//~v7bhR~
//                        "try after \"cp /home/USER/.config/dconf/user /root/.config/dconf/user\".\n");//~v7bhR~
//      fprintf(stderr,"Checking the font name for gnome-terminal by dconf cmd(%s).\n",DCONF_DUMP);//~v7bhI~//~v7c0R~
        fprintf(stderr,"Checking the font name for gnome-terminal by \"dconf\" cmd.\n");//~v7c0I~
	}                                                              //~v7bhI~
    else                                                           //~v7c1I~
	if (Popt==3)    //by xeGetFontSH                               //~v7c1I~
    {                                                              //~v7c1I~
        fprintf(stderr,"Checking the font name by \"xeGetFont.sh\".\n");//~v7c1I~
	}                                                              //~v7c1I~
#endif//LNXCON                                                     //~v7bhI~
#else //!LNX                                                       //~v7bhR~
	if (Popt==0)                                                   //~v7bhI~
    {                                                              //~v7bhI~
//            uerrmsg("Font Facename and Charset are required if on WindowsTerminal(not Conhost) console.\n"//~v7bhI~
//                    "Currently, Facename can not be get, you can specify it with proper Charset by cmdline option of /F[8-]facename[:charset].\n"//~v7bhI~
//                    "About charset(0-255,current is %d), see Microsoft Document about Charset.\n",//~v7bhI~
//                    "(Conhostではない) WindowsTerminal コン\x83\\ール上ではフォント名と文字セット(Charset)が必要です。\n"//~v7bhR~
//                    "現在のところフォント名の設定を知ることができないので、\n"//~v7bhI~
//                    "適合する Charsetと共にコマンドラインパラメータ /F[8-]facename[:charset] を指定してください。\n"//~v7bhI~
//                    "文字セットの値(0-255)は現在は %d ですがについては Microsoft のドキュメントを参照してください。\n",//~v7bhI~
//                    charset);                                    //~v7bhI~
//            uerrmsg("When /GY (Adjust display width f Ambiguous chars) is specified,\n"//~v7bhI~
//                    "font Facename and Charset are required on WindowsTerminal(not Conhost) console.\n"//~v7bhI~
//                    "xe tries to get it from setting.json file. If failed, you have to specify it\n"//~v7bhI~
//                    "with proper Charset by cmdline option of /F.\n"//~v7bhI~
//                    "About charset(0-255,current is %d), see Microsoft Document about Charset.\n",//~v7bhI~
//                    "/GY (\x95\\示幅が曖昧とされるユニコード文字をフォントに従い調整する)オプションのとき\n"//~v7bhR~
//                    "(Conhostではない) WindowsTerminal コン\x83\\ール上ではフォント名と文字セット(Charset)が必要です。\n"//~v7bhR~
//                    "setting.json からフォント名を得ようとしますが、失敗した場合は\n"//~v7bhI~
//                    "適合する Charsetと共にコマンドラインパラメータ /F を指定してください。\n"//~v7bhI~
//                    "文字セットの値(0-255)は現在は %d ですがについては Microsoft のドキュメントを参照してください。\n",//~v7bhI~
//                    charset);                                    //~v7bhI~
              uerrmsg("Font are used to adjust the display width of characters.\n"//~v7bhI~
						"If obtaining the font name fails, specify the font name with the /F command line parameter.\n\n"//~v7bhI~
						"Ignore this warning if you are using a limited number of character types\n"//~v7bhI~
						" and are not concerned about the display width of the characters.\n",//~v7bhI~
					  "フォントは文字の\x95\\示幅を調整するために使用されます。\n"//~v7bhR~
					 	"フォント名の取得に失敗する場合は /F コマンドラインパラメータでフォント名を指定してください。\n\n"//~v7bhI~
						"使用する文字種が限定的な場合で文字の \x95\\幅が気にならない場合はこの警告は無視してください。\n");//~v7bhR~
	}                                                              //~v7bhI~
    else                                                           //~v7bhI~
	if (Popt==1)                                                   //~v7bhI~
    {                                                              //~v7bhI~
//      printf("Trying to get Windows Terminal font from settings.json file. If failed, specify fontname by /F cmdline option!!\n");//~v7bhR~
//      rc=sprintf(Pmsg,"Trying to get Windows Terminal font from settings.json file. If failed, specify fontname by /F cmdline option!!\n");//~v7bhR~
//		rc=sprintf(Pmsg,"Checking the font name for Windows Terminal in the settings.json file(%s\\%s).",//~v7bhR~//~v7c9R~//+v7d0R~
  		rc=sprintf(Pmsg,"Checking the font name for Windows Terminal in the settings.json file(%s\\%s).\n",//+v7d0I~
			    getenv(TOPDIR),SETTINGFILE);                       //~v7c9I~
    	printf("%s",Pmsg);                                         //~v7bhI~//~v7c9R~
//settings.jsonファイルの中のWindows Terminal 用のフォント名を調べています//~v7bhI~
	}                                                              //~v7bhI~
    else                                                           //~v7bhI~
	if (Popt==3)                                                   //~v7c9I~
    {                                                              //~v7c9I~
  		uerrmsg("Checking the font name for Windows Terminal in the settings.json file(%s\\%s).",0,//~v7c9I~
			    getenv(TOPDIR),SETTINGFILE);                       //~v7c9I~
	}                                                              //~v7c9I~
    else                                                           //~v7c9I~
	if (Popt==2)                                                   //~v7bhI~
    {                                                              //~v7bhI~
//      uerrmsg("Warning:Font name cmdline parameter(/Ffacename[:charset]) is recommended on WindowsTerminal(Not on Conhost). \n"//~v7bhI~
//              "About charset(0-255), see Microsoft Document about Charset.\n",0);//~v7bhI~
        uerrmsg("Font (%s) settings failed.\n"                     //~v7bhI~
				"It may not be consistent with chrset (%d). Check the /F parameter (/Ffacename[:charset]).\n",//~v7bhR~
				"フォント(%s)の設定に取得に失敗しました。\n"       //~v7bhI~
				"chrset(%d) と整合しない可\x94\\性があります。/F パラメータ (/Ffacename[:charset]) を確認してください。\n",//~v7bhR~
                Pmsg/*mbFacename*/,Pparm/*charset*/);              //~v7bhI~
	}                                                              //~v7bhI~
#endif                                                             //~v7bhI~
	return rc;                                                     //~v7bhI~
}                                                                  //~v7bhI~
#ifdef XXE                                                         //~v7caI~
//*************************************************************************//~v7caM~
int uvioGetCellDataXXE(int Popt,int Prow,int PcmaxCol,int PsplitHpos,int PsplitVpos,UCHAR *Ppdddata,UCHAR *Ppdddbcs)//~v7caR~
{                                                                  //~v7caM~
    int lenL,lenR,rc2;                                             //~v7caR~
//************************                                         //~v7caM~
	UTRACEP("%s:opt=%04x,row=%d,PcmaxCol=%d,splitVpos=%d,splitHpos=%d\n",UTT,Popt,Prow,PcmaxCol,PsplitVpos,PsplitHpos);//~v7caR~
    if (PsplitVpos)                                                //~v7caR~
    {                                                              //~v7caR~
        lenL=PsplitVpos; lenR=PcmaxCol-PsplitVpos;                 //~v7caR~
    }                                                              //~v7caR~
    else                                                           //~v7caR~
    {                                                              //~v7caR~
        lenL=PcmaxCol; lenR=0;                                     //~v7caR~
    }                                                              //~v7caR~
	rc2=xxe_getCellData(Prow,0,lenL,Ppdddata,Ppdddbcs);            //~v7caI~
    if (rc2>=0)                                                    //~v7caI~
        if (lenR)                                                  //~v7caR~
        {                                                          //~v7caR~
            rc2=xxe_getCellData(Prow,PsplitVpos,lenR,Ppdddata+lenL,Ppdddbcs+lenL);//~v7caR~
        }                                                          //~v7caR~
    if (rc2<0)  //over maxrow                                      //~v7caI~
    {                                                              //~v7caI~
        UTRACEP("%s:end of row\n",UTT);                            //~v7caI~
        return -1;                                                 //~v7caI~
    }                                                              //~v7caI~
    return 0;                                                      //~v7caM~
}//uvioGetCellDataXXE                                              //~v7caM~
#endif //XXE                                                       //~v7caR~
