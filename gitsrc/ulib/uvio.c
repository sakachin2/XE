//*CID://+v7eeR~:                             update#=  422;       //~v7eeR~
//*************************************************************
//v7ee:250716 (WINCON:Bug) Consider Stoplineoffs if on conhost to read screen for HCopy.//~v7eeI~
//v7d1:240806 (Bug)hardcopy;corrupted char for ucs=FFxx            //~v7d1I~
//v7c9:240628 (W32) print fontname selected at termination         //~v7c9I~
//vbzM:240408 (WXE) support hardcopy function                      //~vbzMI~
//v7bn:240406 (WINCON)hardcopy;errmsg is not write to buffer,use only readconsole except fffd is detected//~v7bnI~
//v7bm:240406 (WINCON)hardcopy function for vsplit(write from readConsole result+data/dbcs)//~v7bmI~
//vbzJ:240403 appendmode screen print to ::hp by Ctrl+h (hardcopy) //~vbzHI~
//vbzH:240403 (Bug of vbx4)WINCON:0x01-0x06 cause column shift on windows terminal//~vbzHR~
//v7a6:240226 chktermnal by GetConsoleMode                         //~v7a6I~
//v761:221214 for v760,chk parent to find WindowTerminal           //~v761I~
//v760:221213 On Windows Terminal; qurious action; try panel width decrease one without checking parent process is Terminal(old conhost is no problem)//~v760I~
//v6L5:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//~v6L5I~
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //~v6EqI~
//v6Ep:160812 (WXE)errmsg lineopt;strput called intermediate of errmsg string by attr change,it should not Col but msg len//~v6EpI~
//v6Eo:160811 (XXE)v6ei for XXE(specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EoI~
//v6Ek:160806 (W32)for xe:b4j(OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay))//~v6EkI~
//v6Ej:160805 v6Ei for wxe(XE:vb4i)specify ligature on/off,combine on/of line by line//~v6EjI~
//v6Ei:160802 (XE:vb4f)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EiR~
//v6BL:160308 (W32)enough Guviombuffu allocation for surrogate  pair//~v6BLI~
//v6Bc:160207 (BUG:W32)screen corrupted when screen buffer width is odd number//~v6BcI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning                                  //~v6hdI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v5nm:081102 (Win:BUG)null should be replaced to space when WideAPI(when /Yw specified)//~v5nmI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5m7:080204 move internal function to header                     //~v5m7I~
//v5ky:071006*(WXE:BUG)scrcls parme len is multiline(LINEUPDATE flag set on multiple line)//~v5kyI~
//v5fy:050419 del UTRACE(helpmsg call uviogetmode)                 //~v5fyI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v5e0:040828 drop dangerouse coding(using __asm)                  //~v5e0I~
//v5bj:040209 (WIN)set scree size from window size not by buff size//~v5bjI~
//v570:020824 wxe support                                          //~v570I~
//v534:020315 (WIN/AIX)screen width parameter support              //~v534I~
//v531:020309 (WIN)screen height parameter support                 //~v531I~
//v50X:011202 force nt option for vio                              //~v50XI~
//v307 000422:try test for scr unable to redraw.                   //~v307I~
//v305 000409:(Win:BUG)cause of eh fail.uehexit-->scrcls-->uviowrtncell-->memcpy//~v252I~
//            memcpy source Sw95buffa malloc size is screen width  //~v252I~
//            but scrcl request scrieen size write by space.       //~v252I~
//            loop required bu screen width.                       //~v252I~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//                  return rc=1 when redirected.                   //~v252I~
//v@@@ test trace on 98/01/31 18:52 version                        //~v@@@R~
//v157:980131 scr height for W95 english mode(set value included IME line,//~v157I~
//            caller chk english mode and count down.it is same as DOS)//~v157I~
//            Only OS/2 dos session return 23(lineno except IME line.//~v157I~
//            leave it until OS/2 can be determinable.             //~v157I~
//v155:980123 (BUG:NT)under NT english mode fullscreen x'00' by cell write//~v153I~
//            display invalid char.                                //~v153I~
//            English mode chk by udbcschk(chk dbcs env tbl) in not valid//~v153I~
//            because NT english mode has dbcs tbl.So use udbcschkcp.//~v153I~
//v153:980123 (BUG:DOS/GCC)DOS english mode under OS/2 video buff is virtul//~v153I~
//            but dbcs tble is null.And os/2 hang soon if dbcs is written.//~v153I~
//            So vbuff is virtual and english mode,change dbcs first byte to//~v153I~
//            special char.                                        //~v153I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v151I~
//            but video mode.video buff chk by int 10 ah=FE        //~v151I~
//            (none is displayed under os2 dos session when changed chev us)//~v151I~
//            add udpmiint86x(pass through es/dsetc )              //~v151I~
//v149:980118 (GCC:BUG)w96buffwrite support rec(height,width) specification//~v149I~
//v145:980116 (W32)performance reason                              //~v145I~
//            -uvio_w95wrtcharstratt3 (2 part attr at once)        //~v145I~
//v144:980116 (W32)WINNT support                                   //~v144I~
//            -USDCELLSTR2 type support for cell write required case//~v144I~
//				uvio_w95wrtcharstratt2                             //~v144I~
//v143:980115 (BUG:W32)uvio_w95buffwrite--uviowrtcellstr interface //~v143I~
//             height for cell ctr specified case                  //~v143I~
//v142:980115 (W32)WINNT support                                   //~v142I~
//            -Nt english mode cannot display ctl char normaly when fullscreen//~v142R~
//             WriteConsoleOutputCharacter+WriteConsoleOutputAttribute//~v142R~
//             cdisplay ? for some ctl char,buff image for x'00'   //~v142I~
//             WriteConsoleOutput is errornous for x'00' only.     //~v142I~
//            -same matter for WriteConsolCharacter+FillConsoleOutputAttribute//~v142I~
//v054:970111:for also DOS,getwork by full screen size at init to avoid//~v053R~
//            frequent get/free.                                   //~v053I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//     970406 -short size ont equal int size                       //~v053I~
//v046:961112:screen row is already -1 if IME is on at start.      //~v046I~
//v045:961109:(BUG)buffwrite ctr                                   //~v045I~
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
//*uvio_init/uvio_term                                             //~v022R~
//*uviogetmode                                                     //~v044R~
//*uviosetmode                                                     //~v044R~
//*uvioreadcellstr/uvioreadcharstr
//*uviowrtcellstr/uviowrtcharstr/uviowrtcharstratt/uviowrtattrstr  //~v043R~
//*uviowrtnattr/uviowrtncell/uviowrtnchar
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
#ifdef DOS
	#include <dos.h>                                               //~v022R~
#else
	#ifdef W32                           //v3.6a                   //~v022M~
		#include <windows.h>	         //v1.3 add                //~v022M~
	#else                                //v3.6a                   //~v022M~
		#define INCL_BASE                                          //~v022R~
		#include <os2.h>                                           //~v022R~
    	#pragma stack16(8192)                                      //~v034I~
	#endif                                                         //~v022M~
#endif
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <ualloc.h>
#include <udbcschk.h>
#include <uvio.h>
#include <uviow.h>                                                 //~v5m7I~
#include <uvio2.h>                                                 //~v044I~
#include <uerr.h>                                                  //~v022I~
#include <uedit.h>                                                 //~v022I~
#include <utrace.h>                                                //~v034I~
#include <udos.h>                                                  //~v159I~
#include <ustring.h>                                               //~v6EkI~
#include <uproc2.h>                                                //~v761I~
#ifdef DPMI                 //gcc                                  //~v053R~
	#include <udpmivio.h>                                          //~v053I~
	#include <udpmisub.h>                                          //~v053I~
#endif                                                             //~v053I~
#ifdef W32                  //win                                  //~v142I~
	#include <udos.h>       //udosiswinnt                          //~v142I~
	#include <ukbd.h>       //for ukbdw                            //~v307I~
	#include <ukbdw.h>      //ukbd_w95init                         //~v307I~
	#include <uviom.h>     //CJK support                           //~v5n8R~
  #ifdef WXE                                                       //~v570I~
	#include <wxexei.h>     //ukbd_w95init                         //~v570R~
  #endif                                                           //~v570I~
#endif                                                             //~v142I~
#include <utf.h>     //CJK support                                 //~v6EkI~
#include <utf22.h>     //CJK support                               //~v6EkI~
//*******************************************************
#if defined(DOS) || defined(W32)                                   //~v022I~
//	#define	ATTRCOUNT()										\
//	((*(UCHAR*)FP_SEGOFF(0x40,0x49)==0x73					\
//	||  *(UCHAR*)FP_SEGOFF(0x40,0x49)==0x71)?3:1)
  	#define	ATTRCOUNT() Sattrcount
                                                                //~5A01I~
    #define UALLOCM16WORK(len)                       \
        ( ((len) <= Svioworklen) ? Sviowork :        \
							(		UTRACEP("uallocm16work len=%d\n",len),\
		 							((PCH)UALLOCM16(len)) )  )     //~v142R~
    #define UFREE16WORK(addr)                       \
        if ((char*)(addr)!= Sviowork)                      \
        	UTRACEP("ufree16work addr=%08x\n",addr), \
			ufree16(addr)                                          //~v142R~
#endif
                                                                   //~vbzJI~
#ifdef WINCON                                                      //~vbzJM~
    typedef struct _LOCALE_LINE_INFO                               //~vbzJM~
    {                                                              //~vbzJM~
    	int LLIstartL;  //col  for localefile                      //~vbzJI~
    	int LLIucsctrL;  //ucsctr for localefile                   //~vbzJR~
    	int LLIstartW;  //ddfmt start cols                         //~vbzJI~
    	int LLIddctrW;  //ddfmt len;                               //~vbzJI~
    } LOCALE_LINE_INFO,*PLOCALE_LINE_INFO;                         //~vbzJM~
	void uvioSetBufferWrite(int Popt,int Prow,int Pcol,int Plen);  //~vbzJI~
#endif                                                             //~vbzJM~

//*******************************************************
#define UVIOMATTR_DBCS1        0x01         //1:dbcs1st,2:DBCS2ND same as uviom.c//~vbzJI~
#define UVIOMATTR_DBCS2        0x02         //1:dbcs1st,2:DBCS2ND same as uviom.c//~vbzJI~
#define OS2DOSENGDISP    0xb2                                      //~v153R~
#define WINNTNULLDISP    ' '  //if >=x'80',disply ? actualy under nt eng fullscreen//~v153R~
                              //disply it if windows mode          //~v153I~
#ifdef DOS
	static	union 	REGS	Sreg;
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
	static	struct 	SREGS 	Ssegreg;
    #endif                      //DPMI or not                      //~v053I~
	static  int         Sattrcount=1;	//attribute byte counte
//	static  int         Senglishsw; 	//english mode sw          //~v151R~
  	static  int         Senglishsw; 	//english mode sw          //~v153I~
  	static  int         Srvbuffsw;  	//b800 is video buff(under english mode)//~v151I~
	static 	int  		Sdosintcallsw;  //internal call to uviowrtcellstr//~v153I~
	static  int         Svioworklen; 	//vioworklen            //~5A01I~
	static 	char 		*Sviowork;		//to avoid malloc at emergency msg//~5A01I~
	void uviogetwork(int Pscrwidth);                               //~v042I~
#else                                                              //~v022I~
	#ifdef W32                           //v3.6a                   //~v022I~
		static 	HANDLE  Shconout;		 //std  output console handle//~v022I~
		static  int     Sattrcount=1;	//attribute byte counte    //~v022I~
      #ifndef WXE                                                  //~v570I~
		static  USHORT  Sbuffattr;   	//attribute for scroll     //~v022I~
      #endif //!WXE                                                //~v570I~
		static  USHORT  Stoplineoffs=0;//xe window top line offset //~v5fhM~
    	static  int     Svioworklen; 	//vioworklen               //~v022I~
    	static 	char 	*Sviowork;		//to avoid malloc at emergency msg//~v022I~
//      static  char    Sfullscreensw=1;//cell write or char and attr write//~v142R~
        static  char    Scellnasw;//cell write or char and attr write//~v142I~
        static  char    Sforcentsw=0;//cell write or char and attr write//~v50XI~
    #ifndef WXE                                                    //~v570I~
        static  char    Snullnasw;//null write should be change to space write//~v142I~
		static  char    Senglishsw; 	//english mode sw          //~v142I~
		static  char    Sntsw; 	//windowsNT                        //~v@@@I~
    #endif                                                         //~v570I~
                                                                   //~v042I~
		static  UCHAR   Sw95buffmode;	//buffer mode(set char/attr to buffer)//~v042R~
    	#define WRITETOBUFF    1		//buff mode on             //~v042I~
    	#define WRITEFROMBUFF 0xff  	//caller id to uviowrtcellstr//~v042R~
                                                                   //~v042I~
		static  UCHAR   *Sw95buffc;		//screen char buffer       //~v042I~
#ifdef WXE                                                         //~v570I~
		static  UCHAR   *Swxelineupdate;	//line update flag tbl //~v570R~
        static  int     Sscrheight;  	//scr line count           //~v570I~
#endif                                                             //~v570I~
		static  WORD    *Sw95buffa;		//screen attribute buffer  //~v042R~
		static  WORD    *Sw95buffa0;	//screen attribute buffer foe save const//~v043I~
//		static  int     *Sw95buffopt;	//ligature option for line by line//~v6EoR~
		static  int     Sw95buffoptsz;	//ligature option for line by line//~v6EiI~
        static  int     Sscrsize;   	//screen size(row*col)     //+v042I~//~v042I~
        static  int     Sscrwidth;   	//scr line size            //+v042I~//~v042I~
		static  UCHAR   *Sdbcstbl;		//xe's scr dbcstbl         //~v5n8I~
#ifdef CCC                                                         //~v7bmI~
		static  WUCS    *SucsLocalefile;//ucs written for localefile//~vbzJI~
	    static  PLOCALE_LINE_INFO SucsLocaleLineInfo;              //~vbzJR~
#endif                                                             //~v7bmI~
                                                                   //~v5n8I~
    	void uviogetwork(int Pscrwidth);                           //~v042I~
		WORD *uvio_w95getattrtbl(USHORT Pattr);                    //~v043R~
		void  uvio_w95setscrattr(void *Pout,USHORT Pattr,int Plen);//~v252I~
//		int uvio_w95writecell(int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2);//~v6EiR~
  		int uvio_w95writecell(int Popt,int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2);//~v6EiR~
//    #ifndef WXE                                                  //~v5m7R~
//  	int uvio_setinitwindowpos(CONSOLE_SCREEN_BUFFER_INFO *Ppcsbi,int Pwinh);//~v5m7R~
//    #endif                                                       //~v5m7R~
	#else                                //v3.6a                   //~v022I~
	#endif                                                         //~v022I~
#endif
#ifdef WXE                                                         //~v6EkI~
int uvio_setcombinealtch(int Plineopt,int Ppos,int Plen);          //~v6EkI~
#endif                                                             //~v6EkI~
                                                                   //~v531I~
#ifndef OS2                                                        //~v5e0I~
static int Sheightparm=0,Swidthparm=0;	//user specification       //~v531I~
#endif                                                             //~v5e0I~

static VIOMODEINFO SvioModeInfo;	//save current mode
                                                                //~5A01I~
#ifdef W32                           //v3.6a                       //~v760I~
#ifndef WXE                                                        //~v760I~
UINT uviowrtncellRightEdge(int Popt,PBYTE pCell,int Pcol,int Prow);//~v760R~
#endif                                                             //~v760I~
#endif                                                             //~v760I~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void uvio(void)
{
	return;
}

#if defined(DOS) || defined(W32)                                   //~v022I~
//*******************************************************       //~5A01I~
//*free vio work                                                //~5A01I~
//*******************************************************       //~5A01I~
void uviofreework(void)                                         //~5A01I~
{                                                               //~5A01I~
//**********************                                        //~5A01I~
//UTRACEP("uviofreework\n");                                       //~v5fyR~
	if (Sviowork)                                               //~5A01I~
    {                                                           //~5A01I~
	    ufree16(Sviowork);		//cell size                     //~5A01I~
    	Sviowork=0;                                             //~5A01I~
	    Svioworklen=0;                                          //~5A01I~
	}                                                           //~5A01I~
#ifdef W32                                                         //~v042I~
	if (Sw95buffc)                                                 //~v042I~
	    ufree16(Sw95buffc);                                        //~v042I~
	if (Sw95buffa0)                                                //~v043I~
	    ufree16(Sw95buffa0);                                       //~v043I~
#ifdef CCC                                                         //~v7bmI~
	if (SucsLocalefile)                                            //~vbzJI~
    {                                                              //~vbzJI~
	    ufree(SucsLocalefile);                                     //~vbzJI~
	    SucsLocalefile=0;                                          //~vbzJI~
    }                                                              //~vbzJI~
	if (SucsLocaleLineInfo)                                        //~vbzJI~
    {                                                              //~vbzJI~
	    ufree(SucsLocaleLineInfo);                                 //~vbzJI~
	    SucsLocaleLineInfo=0;                                      //~vbzJI~
    }                                                              //~vbzJI~
#endif                                                             //~v7bmI~
#ifdef WXE                                                         //~v570I~
	if (Swxelineupdate)                                            //~v570I~
	    ufree(Swxelineupdate);                                     //~v570I~
    Swxelineupdate=0;                                              //~v570I~
#else                                                              //~v5n8I~
	UFREECLEARIFNZ(Guviombuffu);                                   //~v5n8R~
#endif                                                             //~v570I~
//  if (Sw95buffopt)                                               //~v6EoR~
    if (Gw95buffopt)                                               //~v6EoI~
//      ufree(Sw95buffopt);                                        //~v6EoR~
        ufree(Gw95buffopt);                                        //~v6EoI~
	Sw95buffc=0;                                                   //~v043R~
	Sw95buffa0=0;                                                  //~v043I~
//  Sw95buffopt=0;                                                 //~v6EoR~
    Gw95buffopt=0;                                                 //~v6EoI~
	Sw95buffmode=0;                                            //+v042M~//~v042I~
#endif                                                             //~v042I~
	return;                                                     //~5A01I~
}//uviofreework                                                 //~5A01I~
                                                                //~5A01I~
//*******************************************************       //~5A01I~
//*get vio work                                                 //~5A01I~
//*parm:screen width                                            //~5A01I~
//*******************************************************       //~5A01I~
void uviogetwork(int Pscrwidth)                                 //~5A01I~
{                                                               //~5A01I~
    int len;                                                    //~5A01I~
#ifdef W32                                                         //~v5nmI~
#ifndef WXE                                                        //~v5n8I~
    int buffusz;                                                   //~v5n8R~
#endif                                                             //~v5n8I~
#endif                                                             //~v5nmI~
//**********************                                        //~5A01I~
#ifdef W32                                                         //~v034I~
    len=Pscrwidth*sizeof(CHAR_INFO);	//cell size                //~v042R~
#else                                                              //~v034I~
    len=Pscrwidth*(ATTRCOUNT()+1);		//cell size             //~5A01I~
#endif                                                             //~v034I~
    if (len==Svioworklen)                                          //~v042R~
        return;                                                 //~5A01I~
	uviofreework();		//cell size                             //~5A01I~
    Svioworklen=len;		//cell size                         //~5A01R~
//  if (Svioworklen)                                               //~v042R~
	Sviowork=UALLOCM16(Svioworklen);                        //~5A01I~//~v042R~
    if (!Sviowork)                                                 //~v042R~
    	uerrexit("uviogetwork malloc failed(len=%d)",0,len);       //~v042I~
//  Sw95buffoptsz=(Pscrwidth/Sscrwidth)*(int)sizeof(int)*2;	//opt for pcw1 and pcw2//~v6EpR~
    Sw95buffoptsz=(Pscrwidth/Sscrwidth+2)*(int)sizeof(int)*2;	//opt for pcw1 and pcw2,+2:errmsg1/2//~v6EpI~
//	Sw95buffopt=UALLOCC(1,(size_t)Sw95buffoptsz);	//opt for pcw1 and pcw2//~v6EoR~
  	Gw95buffopt=UALLOCC(1,(size_t)Sw95buffoptsz);	//opt for pcw1 and pcw2//~v6EoI~
#ifdef W32                                                         //~v042I~
	Sw95buffc=UALLOCM16(Pscrwidth*3);	//char+WORD+WORD tbl       //~v043R~
	if (!Sw95buffc)                                                //~v042R~
		uerrexit("Win95 scrren buff malloc failed(len=%d)",0,Pscrwidth*3);//~v042R~
    Sw95buffa=(USHORT*)(void*)(Sw95buffc+Pscrwidth);	//attr table//~v042R~
//  Sw95buffa0=UALLOCC(1,Sscrwidth*sizeof(USHORT));			//attr table for save value//~v570R~
    Sw95buffa0=UALLOCC(1,Pscrwidth*sizeof(USHORT));			//attr table for save value//~v570I~
  	#ifdef WXE                                                     //~v570I~
    	Swxelineupdate=UALLOCC(1,Sscrheight);			//attr table for save value//~v570R~
//      wxe_uviogetwork(Sw95buffc,Sw95buffa,Swxelineupdate);       //~v6EjR~
//      wxe_uviogetwork(Sw95buffc,Sw95buffa,Swxelineupdate,Sw95buffopt);//~v6EoR~
        wxe_uviogetwork(Sw95buffc,Sw95buffa,Swxelineupdate,Gw95buffopt);//~v6EoI~
    #else                                                          //~v5n8I~
    	buffusz=Pscrwidth*WUCSSZ;			//attr table for save value//~v5n8R~
    	buffusz+=buffusz;                                          //~v6BLR~
    	Guviombuffu=UALLOCC(1,buffusz);			//attr table for save value//~v5n8R~
      #ifdef CCC                                                   //~v7bmI~
    	SucsLocalefile=UALLOCC(1,buffusz);		//ucs written for localefile//~vbzJI~
	    SucsLocaleLineInfo=(PLOCALE_LINE_INFO)UALLOCC(1,sizeof(LOCALE_LINE_INFO)*(Pscrwidth/Sscrwidth));//~vbzJR~
      #endif                                                       //~v7bmI~
  	#endif                                                         //~v570I~
#endif                                                             //~v042I~
	return;                                                     //~5A01I~
}//uviogetwork                                                  //~5A01I~
                                                                //~5A01I~
#endif                                                          //~5A01I~
                                                                //~5A01I~
#ifdef W32                           //v3.6a                       //~v022M~
//*********************************************************************//~v5n8M~
//* uvio_init2                                                     //~v5n8M~
//*   get dbcstbl addr from xe                                     //~v5n8M~
//*   opt is same as Gudbcschk_flagget dbcstbl addr from xe        //~v5n8M~
//*********************************************************************//~v5n8M~
void uvio_init2(int Popt,UCHAR *Pdbcstbl)                          //~v5n8M~
{                                                                  //~v5n8M~
//*************************                                        //~v5n8M~
	Sdbcstbl=Pdbcstbl;                                             //~v5n8M~
    return;                                                        //~v5n8M~
}//uvio_init2                                                      //~v5n8M~
//*******************************************************          //~v50XI~
//uvio_winopt                                                      //~v50XI~
//*set option for win                                              //~v50XI~
//*parm1:option                                                    //~v50XI~
//*******************************************************          //~v50XI~
void uvio_winopt(int Popt)                                         //~v50XI~
{                                                                  //~v50XI~
	Sforcentsw=(Popt & UVIOWINFORCENT);                            //~v50XI~
    return;                                                        //~v50XI~
}//uvio_winopt                                                     //~v50XI~
//*******************************************************          //~v042I~
//uvio_w95buffmode                                                 //~v042I~
//*(W95)set buufer mode                                            //~v042I~
//*parm1:mode switch,1:buffer mode on,0:buffer mode off            //~v042R~
//*******************************************************          //~v042I~
void uvio_w95buffmode(int Pbuffmode)                               //~v042R~
{                                                                  //~v042I~
//**********************                                           //~v042I~
	Sw95buffmode=(Pbuffmode!=0);	//change to 0 or 1 only        //~v042R~
    UTRACEP("%s:buffmode=%d\n",UTT,Sw95buffmode);                  //~v6BLI~
	return;                                                        //~v042R~
}//uvio_w95buffmode                                                //~v042I~
                                                                   //~v043I~
//*******************************************************          //~v043I~
//uvio_w95getattrtbl                                               //~v043I~
//*(W95)get attr table constatnt value                             //~v043I~
//*parm1 :attr to set                                              //~v043I~
//*return:attr table                                               //~v043I~
//*******************************************************          //~v043I~
WORD *uvio_w95getattrtbl(USHORT Pattr)                             //~v043R~
{                                                                  //~v043I~
    int ii;                                                        //~v043I~
//*********************************                                //~v043I~
	if (*Sw95buffa0!=Pattr)                                        //~v043I~
    	for (ii=0;ii<Sscrwidth;ii++)                               //~v043I~
        	Sw95buffa0[ii]=Pattr;                                  //~v043I~
	return Sw95buffa0;                                             //~v043I~
}//uvio_w95getattrtbl                                              //~v043I~
//*******************************************************          //~v252I~
//uvio_w95setscrattr                                               //~v252I~
//*(W95)get screen attribute line by line                          //~v252I~
//*parm1 :out area                                                 //~v252I~
//*parm2 :attr to set(WORD)                                        //~v252I~
//*parm3 :out area len(not ctr but len of ushort buff       //~v252I~//~v6BcR~
//*return:none                                                     //~v252I~
//*******************************************************          //~v252I~
void uvio_w95setscrattr(void *Pout,USHORT Pattr,int Plen)          //~v252I~
{                                                                  //~v252I~
    int len,width,linewidth;                                       //~v252R~
    char *pattrtb,*pout;                                           //~v252I~
//*********************************                                //~v252I~
	pattrtb=(char*)(void*)uvio_w95getattrtbl(Pattr);//len=scrwidth //~v252I~
    linewidth=(Sscrwidth<<1);                                      //~v252I~
    for (pout=Pout,len=Plen;len>0;len-=width,pout+=width)          //~v252I~
    {                                                              //~v252I~
//  	width=min(len,Sscrwidth);                                  //~v252I~//~v6BcR~
    	width=min(len,linewidth);                                  //~v6BcI~
		memcpy(pout,pattrtb,width);                                //~v252R~
	}                                                              //~v252I~
	return;                                                        //~v252I~
}//uvio_w95setscrattr                                              //~v252I~
//*******************************************************          //~v042I~
//uvio_w95buffwrite                                                //~v042I~
//*(W95)write from buffer                                          //~v042I~
//*parm1:row                                                       //~v042I~
//*parm2:col                                                       //~v042I~
//*parm3:height+width or ctr(0 for full screen write)              //~v045R~
//*ret  :rc                                                        //~v042I~
//*******************************************************          //~v042I~
//int  uvio_w95buffwrite(int Prow,int Pcol,int Pctr)               //~v6EiR~
int  uvio_w95buffwrite(int Popt,int Prow,int Pcol,int Pctr)        //~v6EiR~
{                                                                  //~v042I~
	int rc,pos;                                                    //~v042R~
	UCHAR mode;                                                    //~v042I~
    int opt;                                                       //~v6EiR~
//**********************                                           //~v042I~
	UTRACEP("%s:opt=%02x,row=%d,col=%d,ctr=%08x\n",UTT,Popt,Prow,Pcol,Pctr);//~v6EiR~
	if (!Sw95buffmode)                                             //~v042I~
    	return -2;		//not buffer mode                          //~v042I~
	mode=Sw95buffmode;	//save current                             //~v042I~
	Sw95buffmode=WRITEFROMBUFF;	//caller id = buffer write         //~v042I~
    if (!Pctr)                                                     //~v042I~
    	Pctr=Sscrsize;                                             //~v042I~
    if (!(Pctr>>16))	//no height,cell ctr	                   //~v042R~
    {                                                              //~v042I~
       pos=Pcol+Prow*Sscrwidth;                                    //~v042I~
       if (pos<0 || (pos+Pctr)>Sscrsize)                           //~v042R~
           	return -3;                                             //~v042I~
#ifdef CCC                                                         //~v7bmI~
	   uvioSetBufferWrite(0,Prow,Pcol,Pctr);                       //~vbzJR~
#endif                                                             //~v7bmI~
       Pctr*=2;	//by cell length                                   //~v045R~
    }                                                              //~v042I~
UTRACEP("Buffwrite row=%d,col=%d,ctr=%d\n",Prow,Pcol,Pctr);        //~v142R~
//  rc=uviowrtcellstr(0,Pctr,Prow,Pcol);	//by celllen           //~v6EiR~
    opt=Popt|UVIOO_BUFFWRITE;                                      //~v6EiR~
    rc=uviowrtcellstr(opt,0,Pctr,Prow,Pcol);	//by celllen       //~v6EiR~
	Sw95buffmode=mode;	//restore current                          //~v042I~
	return rc;                                                     //~v042R~
}//uvio_w95buffwrite                                               //~v042I~
                                                                   //~v042I~
#endif                                                             //~v022M~
                                                                   //~v022I~
//*******************************************************
//*uvio_initparm                                                   //~v531R~
//*******************************************************
//void uvio_initparm(int Pheight,int Pwidth)                       //~v534R~
void uvio_initparm(int *Pscrparm)                                  //~v534I~
{                                                                  //~v531I~
//  Sheightparm=Pheight;                                           //~v534R~
//  Swidthparm=Pwidth;                                             //~v534R~
#ifndef OS2
    if (Pscrparm)                                                  //~v534I~
    {                                                              //~v534I~
    	Sheightparm=Pscrparm[0];                                   //~v534R~
    	Swidthparm=Pscrparm[1];                                    //~v534R~
    }                                                              //~v534I~
#endif
    return;                                                        //~v531I~
}//uvio_initparm                                                   //~v534R~
//*******************************************************          //~v760I~
#ifdef WINCON                                                      //~v760R~
//*******************************************************          //~v760I~
int chkWindowsTerminal()                                           //~v760I~
{                                                                  //~v760I~
	int cpcon=0;                                                   //~v760R~
//                                00000000000000001111111111111111    //~vbx4I~//~v760R~
//                                0123456789abcdef0123456789abcdef    //~vbx4I~//~v760R~
//	static char* SunpTerminal932="10000001101111110000000000000000";  //~vbx4R~//~v760R~//~vbzHR~
  	static char* SunpTerminal932="01111111000100111010111101001111";//only 01-06 for windows terminal,tbl on xegbl is yet effective.//~vbzHR~
	static char* SunpTerminal437="10000000000000000000000000000000";//~v760I~
//***************                                                  //~v760I~
    if (chkTerminal()==1)   //conhost                              //~v761I~
		GoptWindowsTerminal|=GOPT_WT_CONHOST;                      //~v761I~
	if (IS_ON_TERMINAL())                                          //~v760I~
    {                                                              //~v760I~
		GoptWindowsTerminal|=GOPT_WT_RCOLS; //free right edge 1 column//~v760R~
		cpcon=(int)GetConsoleCP();                                 //~v5n8I~//~v760I~
        if (cpcon==437)                                            //~v760I~
        {                                                          //~v760I~
			GoptWindowsTerminal|=GOPT_WT_CP437;                    //~v760I~
			GunprintableOnTerminal=SunpTerminal437;                //~v760I~
			UTRACED("unpTable 437",GunprintableOnTerminal,32);     //~v760I~
        }                                                          //~v760I~
        else                                                       //~v760I~
        if (cpcon==932)                                            //~v760I~
        {                                                          //~v760I~
			GoptWindowsTerminal|=GOPT_WT_CP932;                    //~v760I~
			GunprintableOnTerminal=SunpTerminal932;                //~v760R~
			UTRACED("unpTable 932",GunprintableOnTerminal,32);     //~v760I~
        }                                                          //~v760I~
    }                                                              //~v760I~
	UTRACEP("%s:cpcon=%d,GoptWindowsTerminal=0x%x\n",UTT,cpcon,GoptWindowsTerminal);//~v760I~
    return 0;                                                      //~v760I~
}                                                                  //~v760I~
//*******************************************************          //~v760I~
int clearRightEdge(int Pcol,int Prow)                              //~v760I~
{                                                                  //~v760I~
	UTRACEP("%s:col=%d,row=%d\n",UTT,Pcol,Prow);                   //~v760I~
    char *cellSpace=" \x07";    //space white on black             //~v760I~
    uviowrtncellRightEdge(0,cellSpace,Pcol-1,Prow);                //~v760I~
    return 0;                                                      //~v760I~
}                                                                  //~v760I~
#endif  //WINCON                                                   //~v760R~
//*******************************************************          //~v531I~
//*VioGetMode                                                      //~v531I~
//*rc=1:mean redirected(Win)                                       //~v531I~
//*******************************************************          //~v531I~
UINT uviogetmode(PVIOMODEINFO PvioModeInfo)                        //~v531I~
{
#ifdef DOS
static struct {int mode;int color;int textmode;}	Smodetbl[]
			={{0x00, 16,1},
			  {0x01, 16,1},
			  {0x02, 16,1},
			  {0x03, 16,1},
			  {0x04,  4,0},
			  {0x05,  4,0},
			  {0x06,  2,0},
			  {0x07,  0,1},
			  {0x08, 16,0},		//by PC source book
			  {0x09, 16,0},		//by PC source book
			  {0x0a,  4,0},		//by PC source book
			  {0x0d, 16,0},
			  {0x0e, 16,0},
			  {0x0f,  0,0},
			  {0x10, 16,0},
			  {0x11,  2,0},
			  {0x12, 16,0},
			  {0x13,256,0},
			  {0x70, 16,1},		//dos/v extension(.=.0x03)
			  {0x71,  2,1},		//dos/v extension(.=.0x73)
			  {0x72, 16,0},
			  {0x73, 16,1},		//.=.0x03(ext CGA)	
			  {-1}          	//terminator
			};
	int i;
	int color;
	int vmode,mi;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_SCREEN_BUFFER_INFO csbi;                           //~v022I~
        DWORD laster;                                              //~v252I~
      #endif //!WXE                                                //~v570M~
        HANDLE temph;                                              //~v252I~
        int buffh;                                                 //~v5fhI~
    #else                                                          //~v022I~
	VIOMODEINFO 	seg16viomodeinfo1;	
	#pragma seg16(seg16viomodeinfo1)
    #endif                                                         //~v022I~
#endif
	APIRET16 rc16;
//*********************************
#ifdef DOS
//  Senglishsw=!udbcschk(0x81);                                    //~v151R~
    Senglishsw=!udbcschkcp();   //englsh mode                      //~v153I~
    Srvbuffsw=uvio_dosgetvbuff(0);//no output buff addr required   //~v151I~
	memset(PvioModeInfo,0,sizeof(VIOMODEINFO));
	PvioModeInfo->cb=sizeof(VIOMODEINFO);
#ifdef DPMI                 //dpim                                 //~v053R~
    vmode=0;                //int size                             //~v053I~
	udpmidosmemget(&vmode,0x40,0x49,1);	//get video mode           //~v053R~
#else                       //not gcc                              //~v053I~
	vmode=*(UCHAR*)FP_SEGOFF(0x40,0x49);	//video mode
#endif                                                             //~v053I~
	for (i=0;;i++)
	{
		if (vmode==Smodetbl[i].mode)
			break;
		if (Smodetbl[i].mode==-1)
			return 1;
	}
	mi=i;
//text mode
	PvioModeInfo->fbType=(UCHAR)((!(Smodetbl[mi].textmode))*VGMT_GRAPHICS);
//  color;
	color=Smodetbl[mi].color;
	for (i=0;i<8;i++)
		if (!(color=(color>>1)))
			break;
	PvioModeInfo->color=(UCHAR)i;
//colomn
    #ifdef DPMI					//DPMI version                     //~v053I~
    	udpmidosmemget(&PvioModeInfo->col,0x40,0x4a,2);	//width by word//~v053R~
    #else                       //not DPMI                         //~v053I~
    PvioModeInfo->col=*(int*)FP_SEGOFF(0x40,0x4a);		//
    #endif                      //DPMI or not                      //~v053I~
//row
    #ifdef DPMI					//DPMI version                     //~v053I~
    	udpmidosmemget(&PvioModeInfo->row,0x40,0x84,1);	//row-1 by byte//~v053R~
    	PvioModeInfo->row++;	//+1 by int                        //~v053I~
    #else                       //not DPMI                         //~v053I~
	PvioModeInfo->row=(int)(*(UCHAR*)FP_SEGOFF(0x40,0x84)+1);//Shift line excluded
    #endif                      //DPMI or not                      //~v053I~
        	                                                       //~v159I~
//hres;
//vres;
    #ifdef DPMI					//DPMI version                     //~v053I~
    	udpmidosmemget(&PvioModeInfo->vres,0x40,0x85,2);//char height  by byte//~v053R~
    	PvioModeInfo->vres*=PvioModeInfo->row;                     //~v053I~
    #else                       //not DPMI                         //~v053I~
	PvioModeInfo->vres=*(int*)FP_SEGOFF(0x40,0x85) * PvioModeInfo->row;
    #endif                      //DPMI or not                      //~v053I~
//fmt_ID				//temp use
	PvioModeInfo->fmt_ID=(UCHAR)vmode;
//atrribute byte count
    PvioModeInfo->attrib=(UCHAR)Sattrcount;
//buf_addr;
//buf_length;
//full_length;
//partial_length;
//ext_data_addr;
//	uviogetwork(PvioModeInfo->col);	//malloc work                  //~v054R~
  	uviogetwork(PvioModeInfo->col*PvioModeInfo->row);	//malloc work//~v054I~
    #ifdef DPMI					//DPMI version                     //~v053M~
		udpmivio_init(PvioModeInfo->col,PvioModeInfo->row); //get dos memory for vio//~v053R~
    #else                       //not DPMI                         //~v053M~
    #endif                      //DPMI or not                      //~v053M~
	rc16=0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        Scellnasw=1;	//wxe use 2 api TextOut and TextColor      //~v570I~
      #else   //!WXE                                               //~v570I~
//		Senglishsw=!udbcschk(0x81);                                //~v153R~
  		Senglishsw=!udbcschkcp();	//chk also code page           //~v153I~
    	Shconout=ugetstdhandle(STD_OUTPUT_HANDLE);                 //~v022I~
//      uvio2_init(Shconout);	//pass to uvio2                    //~v5fhR~
        if (udosiswinnt())		//winnt                            //~v142I~
        {                                                          //~v142I~
        	Sntsw=1;                                               //~v@@@I~
        	if (Senglishsw)		//japanes                          //~v142I~
        		Snullnasw=1;	//null char is errornous display when fullscreen mode//~v142I~
//printf("nullnasw=%d\n",Snullnasw);//@@@@                         //~v153R~
		}                                                          //~v142I~
        else                       //win95                         //~v142I~
        	if (!Senglishsw)		//japanese                     //~v142I~
              if (!Sforcentsw)		//for force cell specified as parm//~v50XI~
        		Scellnasw=1;		//cell write is not functional when fullscreen mode//~v145R~
       if (Guviomopt & UDCWCIO_WIDEAPI)                            //~v5nmI~
#ifdef UTF8UCS2                                                    //~v640I~
        	Snullnasw=0;	//rep null by space as default action when ucs write//~v640I~
#else                                                              //~v640I~
        	Snullnasw=1;	//null char is errornous display when fullscreen mode//~v5nmI~
#endif                                                             //~v640I~
UTRACEP("Guviomopt=%x,Snullnasw=%d,Scellnasw=%d,Senglishsw=%d,Sforcentsw=%d,Sntsw=%d\n",Guviomopt,Snullnasw,Scellnasw,Senglishsw,Sforcentsw,Sntsw);//~v5fyR~//~v5n8R~//~v5nmR~
      #endif //!WXE                                                //~v570I~
                                                                   //~v570I~
//#define TEST2                                                    //~v307R~
#ifdef TEST2                                                       //~v307I~
        Shconout=CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,//~v307R~
//   				 FILE_SHARE_READ | FILE_SHARE_WRITE,           //~v307R~
     				 0,                                            //~v307I~
    				 NULL,                                         //~v307R~
    				 CONSOLE_TEXTMODE_BUFFER,                      //~v307R~
    			     NULL);                                        //~v307R~
  		if (Shconout==INVALID_HANDLE_VALUE)                        //~v307R~
        	uerrapi0x("CreateConsoleScreenBuffer",GetLastError()); //~v307R~
        if (SetConsoleActiveScreenBuffer(Shconout)==FALSE)         //~v307R~
        	uerrapi0x("SetActiveScreenBuffer",GetLastError());     //~v307R~
        uvio2_init(Shconout);	//pass to uvio2                    //~v307I~
#endif                                                             //~v307I~
        temph=0;                                                   //~v252I~
    #ifdef WXE                                                     //~v570I~
    #else //!WXE                                                   //~v570I~
        chkWindowsTerminal();                                      //~v760I~
    	if (!GetConsoleScreenBufferInfo(Shconout,&csbi))	//fail //~v022I~
        {                                                          //~v252I~
        	laster=GetLastError();                                 //~v252R~
          if (laster!=6)                     //redirec             //~v252R~
        	return rc16=4;                                         //~v022I~
            temph=uviowincreatecsb(1);	//createconsolescreenbuff,issue errmsg//~v252R~
			if (temph==INVALID_HANDLE_VALUE)                       //~v252I~
	        	return rc16=4;                                     //~v252I~
    		if (!GetConsoleScreenBufferInfo(temph,&csbi))	//retry//~v252I~
            {                                                      //~v252I~
            	CloseHandle(temph);                                //~v252I~
                printf("uviogetmode:GetConsoleScreenBufferInfo retry failed LastError=%d\n",//~v252I~
						GetLastError());                           //~v252R~
	        	return rc16=4;                                     //~v252I~
            }                                                      //~v252I~
            UTRACED("vsbi",&csbi,sizeof(csbi));                    //~v7d1I~
            if (!CloseHandle(temph))                               //~v252I~
//              printf("uviogetmode:CloseHandle(%08x) failed LastError=%d\n",//~v252I~//~v6L5R~
                printf("uviogetmode:CloseHandle(%p) failed LastError=%d\n",//~v6L5I~
						temph,GetLastError());                     //~v252R~
        }                                                          //~v252I~
//      else                                                       //~v252R~
//      {                                                          //~v252R~
    #endif //!WXE                                                  //~v570I~
        	memset(PvioModeInfo,0,sizeof(VIOMODEINFO));            //~v022I~
        	PvioModeInfo->cb=sizeof(VIOMODEINFO);                  //~v022I~
//text mode                                                        //~v022I~
        	PvioModeInfo->fbType=(UCHAR)(0*VGMT_GRAPHICS);         //~v022I~
//  color;                                                         //~v022I~
        	PvioModeInfo->color=(UCHAR)4;  //2**4                  //~v022R~
//colomn                                                           //~v022I~
    	#ifdef WXE                                                 //~v570I~
            wxe_getmaxscrsize(&PvioModeInfo->col,&PvioModeInfo->row);//~v570R~
            buffh=PvioModeInfo->row;                               //~v5fhI~
        #else                                                      //~v570I~
            UTRACEP("%s:ConsoleScreenBufferInfo size=(%d,%d),csrPos=(%d,%d),attr=%08x,srWindow=(%d,%d-%d,%d),maxsize=(%d,%d)\n",//~v7d1I~
                UTT,csbi.dwSize.X,csbi.dwSize.Y,csbi.dwCursorPosition.X,csbi.dwCursorPosition.Y,csbi.wAttributes,csbi.srWindow.Left,csbi.srWindow.Top,csbi.srWindow.Right,csbi.srWindow.Bottom,csbi.dwMaximumWindowSize.X,csbi.dwMaximumWindowSize.Y);//~v7d1R~
//          PvioModeInfo->col=csbi.dwSize.X;                       //~v5bjR~
//          PvioModeInfo->col=csbi.srWindow.Right-csbi.srWindow.Left+1;//~v5bjR~
            PvioModeInfo->col=csbi.dwSize.X;//should be =buffsz    //~v5bjI~
//row                                                              //~v022I~
//printf("dwSize=%d\n",csbi.dwSize.Y);                             //~v157R~
//            if (csbi.dwSize.Y==24)  //IME line exist             //~v157R~
//                csbi.dwSize.Y=25;                                //~v157R~
//          PvioModeInfo->row=csbi.dwSize.Y;                       //~v5bjR~
            PvioModeInfo->row=csbi.srWindow.Bottom-csbi.srWindow.Top+1;//~v5bjR~
		  if (GoptWindowsTerminal & GOPT_WT_RCOLS)                 //~v760M~
          {                                                        //~v760I~
            clearRightEdge(PvioModeInfo->col,PvioModeInfo->row);   //~v760I~
            PvioModeInfo->col--;                                   //~v760M~
          }                                                        //~v760I~
    		buffh=csbi.dwSize.Y;	//buffer height                //~v5fhR~
//UTRACED("csbi",&csbi,sizeof(csbi));                              //~v5fyR~
        #endif                                                     //~v570M~
			if (Sheightparm)                                       //~v531I~
            {                                                      //~v531I~
//  			if (Sheightparm>PvioModeInfo->row)                 //~v5fhR~
    			if (Sheightparm>buffh)                             //~v5fhI~
                {                                                  //~v531I~
                	printf("Screen height parm(%d)>screen buff size(%d)",//~v531R~
//  						Sheightparm,PvioModeInfo->row);        //~v5fhR~
    						Sheightparm,buffh);                    //~v5fhI~
		        	return rc16=2;                                 //~v531R~
                }                                                  //~v531I~
//  			PvioModeInfo->row=Sheightparm;                     //~v531I~//~v6BcR~
    			PvioModeInfo->row=(USHORT)Sheightparm;             //~v6BcI~
			}                                                      //~v531I~
			if (Swidthparm)                                        //~v531I~
            {                                                      //~v531I~
				if (Swidthparm>PvioModeInfo->col)                  //~v531I~
                {                                                  //~v531I~
                	printf("Screen width parm(%d)>screen buff size(%d)",//~v531R~
							Swidthparm,PvioModeInfo->col);         //~v531I~
		        	return rc16=2;                                 //~v531R~
                }                                                  //~v531I~
//  			PvioModeInfo->col=Swidthparm;                      //~v531I~//~v6BcR~
    			PvioModeInfo->col=(USHORT)Swidthparm;              //~v6BcI~
			}                                                      //~v531I~
                                                                   //~v531I~
//hres;                                                            //~v022I~
//vres;                                                            //~v022I~
//fmt_ID				//temp use                                 //~v022I~
			PvioModeInfo->fmt_ID=(UCHAR)3;                         //~v022I~
//atrribute byte count                                             //~v022I~
    		PvioModeInfo->attrib=(UCHAR)Sattrcount;                //~v022I~
//buf_addr;                                                        //~v022I~
//buf_length;                                                      //~v022I~
//full_length;                                                     //~v022I~
//partial_length;                                                  //~v022I~
//ext_data_addr;                                                   //~v022I~
                                                                   //~v022I~
      	#ifdef WXE                                                 //~v570R~
        	Sscrheight=PvioModeInfo->row;                          //~v570I~
        #else   //!WXE                                             //~v570I~
            Sbuffattr=csbi.wAttributes;                            //~v022I~
        #endif //!WXE                                              //~v570I~
        	Sscrwidth=PvioModeInfo->col;          //+v042R~         //~v042I~//~v043I~
        	Sscrsize =PvioModeInfo->col*PvioModeInfo->row;          //+v042R~//~v042I~//~v043I~
        	uviogetwork(Sscrsize);	//malloc work                  //~v043R~
          if (temph)                                               //~v252I~
            rc16=1;     //notify redirected                        //~v252I~
          else                                                     //~v252I~
        	rc16=0;                                                //~v022I~
//      }                                                          //~v252R~
    	#ifndef WXE                                                //~v5fhI~
//  		Stoplineoffs=uvio_setinitwindowpos(&csbi,(int)(PvioModeInfo->row));//~v5fhI~//~v6BcR~
    		Stoplineoffs=(USHORT)uvio_setinitwindowpos(&csbi,(int)(PvioModeInfo->row));//~v6BcI~
   		    uvio2_init(Shconout,Stoplineoffs);	//pass to uvio2    //~v5fhM~
// 		    uviom_init(0/*opt*/,(ULONG)Shconout,Sscrwidth,Sscrsize,Stoplineoffs);	//pass to uvio2//~v5n8R~//~v6hhR~
   		    uviom_init(0/*opt*/,(ULPTR)Shconout,Sscrwidth,Sscrsize,Stoplineoffs);	//pass to uvio2//~v6hhI~
	    #endif                                                     //~v5fhI~
    #else                                                          //~v022I~
	seg16viomodeinfo1.cb=sizeof(VIOMODEINFO);
   	rc16=VioGetMode (&seg16viomodeinfo1,0);
   	*PvioModeInfo=seg16viomodeinfo1;
    #endif                                                         //~v022I~
#endif
	SvioModeInfo=*PvioModeInfo;	//save current
//  UTRACEP("cellnasw=%d\n",Scellnasw);                            //~v5n8R~
   	return (UINT)rc16;
}//uviogetmode                                                     //~v252R~

#ifdef W32                                                         //~v5fhI~
#ifndef WXE                                                        //~v5fhI~
//*******************************************************          //~v5fhI~
//*determin window position in console buff                        //~v5fhI~
// and scroll if reached to end of buff                            //~v5fhI~
//*******************************************************          //~v5fhI~
int uvio_setinitwindowpos(CONSOLE_SCREEN_BUFFER_INFO *Ppcsbi,int Pwinh)//~v5fhR~
{                                                                  //~v5fhI~
	int winbot,wintop,winh,topoffs,scrollctr,buffh;                 //~v5fhR~
    SMALL_RECT winrect;             //rectangular                  //~v5fhR~
    COORD      coorddest;               //x,y                      //~v5fhI~
    CHAR_INFO  chi;                                                //~v5fhI~
//**********************                                           //~v5fhI~
    wintop=Ppcsbi->srWindow.Top;       	//window Top    line offset in console buff//~v5fhI~
    winbot=Ppcsbi->srWindow.Bottom+1;   //window Bottom line offset in console buff//~v5fhI~
    winh=winbot-wintop; 	//windows height                       //~v5fhR~
    buffh=Ppcsbi->dwSize.Y;	//buffer height                        //~v5fhI~
    UTRACEP("%s:wintop=%d,winbot=%d,winh=%d,buffh=%d\n",UTT,wintop,winbot,winh,buffh);//~v7d1I~
    if (winh>=buffh)	//windows heigh=buffer height              //~v5fhR~
    	return 0;                                                  //~v5fhI~
    topoffs=Ppcsbi->dwCursorPosition.Y;    //cursor position is window top position//~v5fhI~
    scrollctr=(topoffs+Pwinh)-buffh;                               //~v5fhR~
    UTRACEP("%s:topoffs=%d,scrollctr=%d\n",UTT,topoffs,scrollctr); //~v7d1I~
//*                                                                //~v5fhI~
    winrect.Left    =(SHORT)0;                                     //~v5fhR~
    winrect.Right   =(SHORT)Ppcsbi->dwSize.X-1;   //buffer width;  //~v5fhR~
    winrect.Top     =(SHORT)topoffs;                               //~v5fhR~
    winrect.Bottom  =(SHORT)(topoffs+winh-1);                      //~v5fhR~
    UTRACEP("%s:winrect Top=%d,Bottom=%d,left=%d,right=%d\n",UTT,(int)winrect.Top,(int)winrect.Bottom,(int)winrect.Left,(int)winrect.Right);//~v7d1I~
    if (scrollctr>0)                                               //~v5fhI~
    {                                                              //~v5fhI~
//scrollup                                                         //~v5fhI~
    	winrect.Bottom	=(SHORT)(buffh-1);//scroll box bottom      //~v5fhR~
    	winrect.Top		=(SHORT)scrollctr;//scroll box top         //~v5fhR~
	    UTRACEP("%s:scrollctr>0 winrect Top=%d,Bottom=%d\n",UTT,(int)winrect.Top,(int)winrect.Bottom);//~v7d1I~
        coorddest.X     =(SHORT)0;                                 //~v5fhI~
        coorddest.Y     =(SHORT)0;                                 //~v5fhI~
        chi.Char.UnicodeChar=0;                                    //~v5fhI~
        chi.Char.AsciiChar=' ';                                    //~v5fhI~
        chi.Attributes=0;                                          //~v5fhI~
UTRACED("scroll rect",&winrect,8);                                 //~v5fhI~
    	ScrollConsoleScreenBuffer(Shconout,                        //~v5fhI~
        									&winrect,	//move box //~v5fhR~
        									NULL,		//no clip  //~v5fhI~
        									coorddest,	//destination//~v5fhI~
                                            &chi);//fill cell      //~v5fhI~
        topoffs-=scrollctr;                                        //~v5fhI~
    	winrect.Top		=(SHORT)topoffs;//window rect              //~v5fhR~
    	winrect.Bottom	=(SHORT)(topoffs+winh-1);//window rect     //~v5fhR~
	    UTRACEP("%s:scrollctr>0 adjusted winrect Top=%d,Bottom=%d\n",UTT,(int)winrect.Top,(int)winrect.Bottom);//~v7d1I~
    }                                                              //~v5fhI~
  int rc2=                                                         //~v7d1I~
    SetConsoleWindowInfo(Shconout,TRUE,&winrect);                  //~v5fhR~
UTRACEP("%s:scrollctr=%d,topoffs=%d,rc2=%d,lastError=%d\n",UTT,scrollctr,topoffs,rc2,GetLastError());//~v7d1R~
UTRACEP("%s:winrect return topoffs=%d,Top=%d,Bottom=%d,left=%d,right=%d\n",UTT,topoffs,(int)winrect.Top,(int)winrect.Bottom,(int)winrect.Left,(int)winrect.Right);//~v7d1I~
    return topoffs;                                                //~v5fhI~
}//uvio_setinitwindowpos                                           //~v5fhR~
#endif                                                             //~v5fhI~
#endif //W32                                                       //~v5fhI~
//*******************************************************
//*VioSetMode(for Win95 resize by new (col,row))                   //~v022R~
//*parm:pviomodeinfo,if 0 free work and return                  //~5A01I~
//*******************************************************
UINT uviosetmode (PVIOMODEINFO pvioModeInfo)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	SMALL_RECT wrect;				//rectangular              //~v022I~
    	COORD      coord;				//x,y                      //~v022I~
        int        sizedown;                                       //~v022R~
        SHORT       x,y;                                           //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	VIOMODEINFO 	seg16viomodeinfo2;	
	#pragma seg16(seg16viomodeinfo2)
	#endif                                                         //~v022I~
#endif
	APIRET16 rc16;
//*********************************
#ifdef DOS
	if (!pvioModeInfo)                                          //~5A01I~
    {                                                           //~5A01I~
    	uviofreework();                                         //~5A01I~
        return 0;                                               //~5A01I~
    }                                                           //~5A01I~
//  Senglishsw=!udbcschk(0x81);                                    //~v151R~
    Senglishsw=!udbcschkcp(); 	//english mode                     //~v153I~
    Srvbuffsw=uvio_dosgetvbuff(0);//no output buff addr required   //~v151I~
	Sreg.h.al=pvioModeInfo->fmt_ID;	//mode
	INT10(0x00);						//set video mode
    Sattrcount=pvioModeInfo->attrib;
	rc16=0;
#else
	if (!pvioModeInfo)                                          //~5A01I~
    {                                                              //~v034I~
#ifdef W32                           //win95                       //~v034I~
    #ifdef WINCON                                                  //~v7c9I~
		uvioGetCursorWidth(UVGCWO_CLOSE|UVGCWO_FORCE,0/*Pucs*/);   //~v7c9I~
    #endif                                                         //~v7c9I~
    	uviofreework();                                            //~v034I~
#endif                                                             //~v034I~
        return 0;                                               //~5A01I~
    }                                                              //~v034I~
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
    	rc16=0;                                                    //~v570I~
      #else  //!WXE                                                //~v570I~
    	coord=GetLargestConsoleWindowSize(Shconout);               //~v022I~
UTRACEP("GetLargestConsoleWindowsSize x=%d,y=%d\n",coord.X,coord.Y);//~v@@@R~
    	x=min(pvioModeInfo->col,coord.X);                          //~v022R~
    	y=min(pvioModeInfo->row,coord.Y);                          //~v022R~
    	wrect.Right=(SHORT)(x-1);                                  //~v022R~
    	wrect.Bottom=(SHORT)(y-1);                                 //~v022R~
    	wrect.Left=                                                //~v022I~
    	wrect.Top=0;                                               //~v022I~
       	coord.X=x;                                                 //~v022I~
       	coord.Y=y;                                                 //~v022I~
    	sizedown=SvioModeInfo.col*SvioModeInfo.row-x*y;	//plus if size down//~v022I~
    	rc16=0;	                                                   //~v022I~
		if (sizedown>0)                                            //~v022I~
        {                                                          //~v022I~
        	if (!SetConsoleWindowInfo(Shconout,TRUE,&wrect))       //~v022R~
    	    	rc16=16;				//setconwinf err           //~v022I~
    		else                                                   //~v022I~
    	    	if (!SetConsoleScreenBufferSize(Shconout,coord))   //~v022I~
    		    	rc16=8;				//setconbuffi err          //~v022I~
		}                                                          //~v022I~
        else                                                       //~v022I~
			if (sizedown<0)                                        //~v022I~
	        {                                                      //~v022I~
	    		if (!SetConsoleScreenBufferSize(Shconout,coord))   //~v022R~
    			    rc16=8;				//setconbuffi err          //~v022R~
    			else                                               //~v022R~
	    	    	if (!SetConsoleWindowInfo(Shconout,TRUE,&wrect))//~v022R~
	    		    	rc16=16;				//setconwinf err   //~v022R~
	        }                                                      //~v022I~
UTRACEP("uviosetmode sizedown=%d,rc=%d,windowsinfo=(%d,%d),coord=(%d,%d)\n",//~v@@@I~
		sizedown,rc16,                                             //~v@@@R~
    	wrect.Right,wrect.Bottom,coord.X,coord.Y);                 //~v@@@I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   	seg16viomodeinfo2=*pvioModeInfo;
    rc16=VioSetMode(&seg16viomodeinfo2,0);
	#endif                                                         //~v022I~
#endif
  #ifndef WXE                                                      //~v570I~
	if (!rc16)
		uviogetmode(&SvioModeInfo);		//save current status
  #endif //!WXE                                                    //~v570I~
    return (UINT)rc16;
}//uviosetmode

//*******************************************************
//*VioReadCellStr
//*******************************************************
UINT uvioreadcellstr(PCH pchCellStr,int *Pplen,int Prow,int Pcol)
{
#ifdef DOS
	int attr;                                                      //~v053R~
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
	int offs;                                                      //~v053I~
	char *videobuff;                                            //~4C21I~
    #endif                      //DPMI or not                      //~v053I~
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
		UCHAR  *pcd;                                               //~v570R~
		USHORT *pca;                                               //~v570I~
		int len,reqctr;                                            //~v570I~
      #else //!WXE                                                 //~v570I~
		SMALL_RECT	srcrect;                                       //~v022I~
		COORD 		coordbufsz,coordpos={0,0};                     //~v022I~
		APIRET16 rc16;                                             //~v022I~
		int len,reqctr;                                            //~v034R~
		PCHAR_INFO wk,wko;                                         //~v034R~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	USHORT seg16cb1;
	#pragma seg16(seg16cb1)
	APIRET16 rc16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
   	attr=ATTRCOUNT();				//attribute byte count      //~4C21I~
//  if (Senglishsw)                 //int 10 ah=1310/1311 not avail//~v151R~
    if (Srvbuffsw)                  //video buff is real           //~v151I~
    {                                                           //~4C21I~
    #ifdef DPMI                 //dos extender                     //~v053R~
		udpmiviogettext(pchCellStr,*Pplen,Prow,Pcol);              //~v053R~
    #else                       //not gcc                          //~v053I~
		offs=(Prow*SvioModeInfo.col+Pcol)<<1;                    //~4C21I~
		videobuff=FP_SEGOFF(0xb800,offs);                       //~4C21I~
		memcpy(pchCellStr,videobuff,*Pplen);                    //~4C21I~
    #endif                                                         //~v053I~
    }                                                           //~4C21I~
    else                                                        //~4C21I~
    {                                                           //~4C21I~
//  	Ssegreg.es	=FP_SEG(pchCellStr);                           //~v053R~
		Sreg.x.cx	=*Pplen/(attr+1);	//char count(w/o attr byte)//~4C21R~
		Sreg.h.dh	=(UCHAR)Prow;                               //~4C21R~
		Sreg.h.dl	=(UCHAR)Pcol;                               //~4C21R~
	    Sreg.h.bh	=0;						//page no           //~4C21R~
		if (attr==1)                                            //~4C21R~
	    	Sreg.h.al=0x10;						//char block read//~4C21R~
		else                                                    //~4C21R~
	    	Sreg.h.al=0x11;						//char block read (ext CGA)//~4C21R~
		Sreg.h.ah	=0x13;                   	//char read/write//~4C21R~
    #ifdef DPMI                 //gcc                              //~v053R~
	  	Sreg.d.ebp=(int)pchCellStr;                                //~v053R~
		udpmiint86(0x10,&Sreg,&Sreg);                              //~v053R~
    #else                       //not gcc                          //~v053I~
    	Ssegreg.es	=FP_SEG(pchCellStr);                           //~v053I~
		uvintbp(FP_OFF(pchCellStr),&Sreg,&Sreg,&Ssegreg);       //~4C21R~
    #endif                                                         //~v053I~
	}                                                           //~4C21I~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        pcd=UVIO_TEXTDATA(Prow,Pcol);                              //~v570I~
        pca=UVIO_ATTRDATA(Prow,Pcol);                              //~v570I~
    	reqctr=*Pplen/2;				//cell count               //~v570I~
        for (len=0;len<reqctr;len++)  //char(BYTE)+attr(BYTE) fmt  //~v570I~
        {                                                          //~v570I~
            *pchCellStr++=*pcd++;                                  //~v570I~
            *pchCellStr++=(UCHAR)(*pca++);                         //~v570R~
        }                                                          //~v570I~
        return 0;                                                  //~v570R~
      #else		//!WXE                                             //~v570I~
    	reqctr=*Pplen/2;				//cell count               //~v034I~
    	srcrect.Top   =                                            //~v022I~
//  	srcrect.Bottom=(SHORT)Prow;                                //~v5fhR~
    	srcrect.Bottom=(SHORT)(Prow+Stoplineoffs);                 //~v5fhI~
    	srcrect.Left  =(SHORT)Pcol;                                //~v022R~
    	srcrect.Right =(SHORT)(reqctr+Pcol-1);					//read width//~v034R~
        coordbufsz.X  =(SHORT)reqctr;					//read width//~v034R~
        coordbufsz.Y  =1;						//read line numbers//~v022I~
        coordpos.X  =                                              //~v022I~
        coordpos.Y  =0;						//pos in source buff   //~v022I~
                                                                   //~v022I~
		len=reqctr*sizeof(CHAR_INFO);		//cell read work       //~v034R~
		wko=wk=(PCHAR_INFO)(PVOID)UALLOCM16WORK(len);		//cell read work//~v034R~
	    UALLOCCHK(wk,UALLOC_FAILED);                               //~v022I~
                                                                   //~v022I~
		rc16=(APIRET16)!ReadConsoleOutput(Shconout,		//read buffer//~v022R~
								wk,		//CHAR_INFO(WORD+WORD)     //~v022R~
                                coordbufsz,		//rectangle of dest buff//~v022I~
                                coordpos,		//upper left pos in dest buff//~v022I~
                                &srcrect);		//source rectangle //~v022I~
UTRACEP("uvioreadcellstr rect=(%d,%d)-(%d,%d) ctr=%d\n",           //~v@@@I~
    	srcrect.Top,                                               //~v@@@I~
    	srcrect.Left,                                              //~v@@@I~
    	srcrect.Bottom,                                            //~v@@@I~
    	srcrect.Right,reqctr);                                     //~v@@@R~
//UTRACED("uvioreadcellstr",wk,len);                               //~v531R~
		if (!rc16)                                                 //~v022I~
        	for (len=0;len<reqctr;len++,wk++)  //char(BYTE)+attr(BYTE) fmt//~v034R~
            {                                                      //~v022I~
            	*pchCellStr++=wk->Char.AsciiChar;                  //~v022R~
            	*pchCellStr++=(UCHAR)wk->Attributes;               //~v022R~
            }                                                      //~v022I~
        else                                                       //~v034I~
//          rc16=uerrapi0("ReadConsoleOutput",GetLastError());     //~v034R~//~v6BcR~
            rc16=(USHORT)uerrapi0("ReadConsoleOutput",GetLastError());//~v6BcI~
    	UFREE16WORK((char*)(void*)wko);                            //~v054R~
		return (UINT)rc16;                                         //~v022I~
      #endif		//!WXE                                         //~v570M~
    #else                                                          //~v022I~
   seg16cb1=(USHORT)(*Pplen);
   rc16=VioReadCellStr (pchCellStr,&seg16cb1,(USHORT)Prow,(USHORT)Pcol,0);
	*Pplen=seg16cb1;
   return (UINT)rc16;
	#endif                                                         //~v022I~
#endif
}//uvioreadcellstr

//*******************************************************
//*VioWrtCellStr
//*parm1:cell(char+attr) addr                                      //~v042I~
//*parm2:cell string len                                           //~v042I~
//       or height+width(W95 only,avail when write from buff and box mode)//~v042I~
//*parm3:target row                                                //~v042I~
//*parm4:target column                                             //~v042I~
//*ret  :rc                                                        //~v042R~
//*******************************************************          //~v042I~
//UINT uviowrtcellstr (PCH pchCellStr,int Plen,int Prow,int Pcol)  //~v6EiR~
UINT uviowrtcellstr (int Popt,PCH pchCellStr,int Plen,int Prow,int Pcol)//~v6EiR~
{
#ifdef DOS
	int attr;                                                      //~v053I~
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
	int offs;                                                      //~v053R~
	char *videobuff;                                            //~5513I~
    #endif                      //DPMI or not                      //~v053I~
	UCHAR *wk,*wko,*wke,ch;                                        //~v153R~
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		COORD 		coordpos={0,0};                                //~v142R~
		int len,reqctr;                                            //~v034R~
        DWORD dwlen;                                               //~v6hdI~
        int pos,height;                                            //~v143R~
        UINT rc;                                                   //~v034I~
		PCHAR_INFO wk,wko;                                         //~v034R~
		char      *wpch;                                           //~v034I~
		WORD      *wpat;                                           //~v034I~
    #else                                                          //~v022I~
	#endif                                                         //~v022R~
#endif                                                             //~v022I~
//*********************************
#ifdef DOS
//  attr=ATTRCOUNT();				//attribute byte count         //~v053R~
//  Ssegreg.es	=FP_SEG(pchCellStr);                               //~v053R~
//  Sreg.x.cx	=Plen/(attr+1);			//char count(w/o attr byte)//~v053R~
//  Sreg.h.dh	=(UCHAR)Prow;                                      //~v053R~
//  Sreg.h.dl	=(UCHAR)Pcol;                                      //~v053R~
//  Sreg.h.bh	=0;						//page no                  //~v053R~
//  if (Senglishsw)                                                //~v151R~
    if (Srvbuffsw)                  //video buff is real           //~v151I~
    {                                                           //~5513I~
//    	Sreg.h.al=0x02;						//english mode      //~5513R~
    #ifdef DPMI                 //dos extender                     //~v053I~
		udpmivioputtext(pchCellStr,Plen,Prow,Pcol);                //~v053I~
    #else                       //not gcc                          //~v053I~
		offs=(Prow*SvioModeInfo.col+Pcol)<<1;                   //~5513I~
		videobuff=FP_SEGOFF(0xb800,offs);                       //~5513I~
		memcpy(videobuff,pchCellStr,Plen);                      //~5513I~
    #endif                      //not gcc                          //~v053I~
	}                                                           //~5513I~
	else
    {                                                           //~5513I~
		attr=ATTRCOUNT();				//attribute byte count     //~v053I~
        Sreg.x.cx	=Plen/(attr+1);			//char count(w/o attr byte)//~v053I~
        Sreg.h.dh	=(UCHAR)Prow;                                  //~v053I~
        Sreg.h.dl	=(UCHAR)Pcol;                                  //~v053I~
        Sreg.h.bh	=0;						//page no              //~v053I~
		if (attr==1)
    		Sreg.h.al=0x20;		//char block write,avail japanese mode only
		else
    		Sreg.h.al=0x21;		//char block write(ext CGA),japanese only
		Sreg.h.ah	=0x13;                   	//char read/write//~5513R~
//repl dbcs for os2 dos session english mode                       //~v153I~
        wko=pchCellStr;                                            //~v153R~
    	if (Senglishsw)			//OS2 dos english mode             //~v153I~
        {                                                          //~v153I~
			if (!Sdosintcallsw)   //not internal call to uviowrtcellstr//~v153R~
            {                                                      //~v153I~
				wko=UALLOCM16WORK(Plen);                           //~v153R~
    			UALLOCCHK(wko,UALLOC_FAILED);                      //~v153R~
                memcpy(wko,pchCellStr,Plen);                       //~v153R~
            }                                                      //~v153I~
            wk=wko;                                                //~v153I~
			wke=wk+Plen;                                           //~v153I~
            while (wk<wke)                                         //~v153I~
            {                                                      //~v153I~
            	ch=*wk;                                            //~v153I~
            	if ((ch>=0x81 && ch<=0x9f)                         //~v153R~
            	||  (ch>=0xe0 && ch<=0xfc))                        //~v153R~
                    *wk=OS2DOSENGDISP;                             //~v153I~
                wk+=(attr+1);                                      //~v153I~
            }                                                      //~v153I~
    	}//repl dbcs 1st byte by special char                      //~v153I~
    #ifdef DPMI                 //gcc                              //~v053I~
//    	Sreg.d.ebp=(int)pchCellStr;                                //~v153R~
      	Sreg.d.ebp=(int)wko;                                       //~v153R~
		udpmiint86(0x10,&Sreg,&Sreg);                              //~v053R~
    #else                       //not gcc                          //~v053I~
//      Ssegreg.es	=FP_SEG(pchCellStr);                           //~v153R~
        Ssegreg.es	=FP_SEG(wko);                                  //~v153R~
//  	uvintbp(FP_OFF(pchCellStr),&Sreg,&Sreg,&Ssegreg);          //~v153R~
    	uvintbp(FP_OFF(wko),&Sreg,&Sreg,&Ssegreg);                 //~v153R~
    #endif                      //not gcc                          //~v053I~
    	if (Senglishsw)			//OS2 dos english mode             //~v153I~
			if (!Sdosintcallsw)   //not internal call to uviowrtcellstr//~v153R~
	    		UFREE16WORK(wko);                                  //~v153I~
    }                                                           //~5513I~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
	UTRACEP("%s:W32 opt=x%02x,row=%d,col=%d,len=%d,buffmode=x%02x,cellnasw=%d\n",UTT,Popt,Prow,Pcol,Plen,Sw95buffmode,Scellnasw);//~v6EiR~
        height=(Plen>>16);                                         //~v042I~
        if (height)                                                //~v042I~
//  		reqctr=(Plen&0xffff);                                  //~v149R~
    		reqctr=height*Sscrwidth;    //called from writebuff,needed cell buff ctr;//~v149I~
        else                                                       //~v042I~
    	reqctr=Plen/2;                                             //~v034I~
		UTRACED("pchCellStr",pchCellStr,reqctr*2);                 //~v6EiI~
                                                                   //~v022I~
      if (Sw95buffmode==WRITETOBUFF)                               //~v042R~
      {                                                            //~v042I~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+reqctr)>Sscrsize)                    //~v042R~
            	rc=8;                                              //~v042I~
            else                                                   //~v042I~
            {                                                      //~v042I~
#ifdef WXE                                                         //~v570I~
            	UVIO_LINEUPDATE(Prow);                             //~v570I~
#endif                                                             //~v570I~
//          	uvio_setbufflineopt(0,Prow,Popt);                  //~v6EpR~
            	uvio_setbufflineopt(0,Prow,Popt,Pcol,reqctr);      //~v6EpR~
                UTRACEP("%s:save lineopt row=%d,opt=%04x\n",UTT,Prow,Popt);//~v6EiI~
                                                                   //~v6EiR~
                wpch=&Sw95buffc[pos];                              //~v042I~
                wpat=&Sw95buffa[pos];                              //~v042I~
            	for (len=0;len<reqctr;len++)  //charstring+attrtbl //~v042I~
                {                                                  //~v042I~
                	*wpch++=*pchCellStr++;                         //~v042I~
                	*wpat++=(WORD)*pchCellStr++;                   //~v042I~
                }                                                  //~v042I~
                UTRACED("buffmode Sw95buffc",Sw95buffc+pos,reqctr);//~v6EjR~
                UTRACED("buffmode Sw95buffa",Sw95buffa+pos,reqctr*(int)sizeof(Sw95buffa[0]));//~v6EjR~
                UTRACED("buffmode Sdbcstbl",Sdbcstbl+pos,reqctr);  //~v6EjI~
#ifdef WXE                                                         //~v6EkI~
            	uvio_setcombinealtch(Popt,pos,reqctr);             //~v6EkR~
#endif                                                             //~v6EkI~
                rc=0;                                              //~v042I~
            }                                                      //~v042I~
      }                                                            //~v042I~
      else  //not write to buff                                    //~v042R~
      {                                                            //~v042I~
		len=reqctr*sizeof(CHAR_INFO);		//cell read work       //~v034R~
//  	wko=wk=(PCHAR_INFO)(PVOID)UALLOCM16WORK(len);		//cell read work//~v142R~
//      UALLOCCHK(wk,UALLOC_FAILED);                               //~v142R~
//      if (Sfullscreensw)                                         //~v142R~
        if (Scellnasw)      //cell write not avail                 //~v142I~
        {                                                          //~v034I~
    		wko=wk=(PCHAR_INFO)(PVOID)UALLOCM16WORK(len);		//cell read work//~v142I~
        	UALLOCCHK(wk,UALLOC_FAILED);                           //~v142I~
            coordpos.X  =(SHORT)Pcol;                              //~v034I~
//          coordpos.Y  =(SHORT)Prow;                              //~v5fhR~
            coordpos.Y  =(SHORT)(Prow+Stoplineoffs);               //~v5fhI~
                                                                   //~v034I~
	      if (Sw95buffmode==WRITEFROMBUFF)                         //~v042R~
          {                                                        //~v042I~
            coordpos.X  =0;                                        //~v149I~
//          pos=Pcol+Prow*Sscrwidth;                               //~v149R~
            pos=Prow*Sscrwidth;                                    //~v149I~
            wpch=&Sw95buffc[pos];                                  //~v042I~
            wpat=&Sw95buffa[pos];                                  //~v042I~
          }                                                        //~v042I~
          else                                                     //~v042I~
          {				//write from parm                          //~v042I~
            wpch=(void*)wko;                                       //~v034I~
            wpat=(void*)(wpch+reqctr);                             //~v034I~
        	for (len=0;len<reqctr;len++)  //charstring+attrtbl     //~v034I~
            {                                                      //~v034I~
            	*wpch++=*pchCellStr++;                             //~v034R~
            	*wpat++=(WORD)*pchCellStr++;                       //~v034R~
            }                                                      //~v034I~
            wpch=(void*)wko;                                       //~v034I~
            wpat=(void*)(wpch+reqctr);                             //~v034I~
          }//write from buff or else                               //~v042I~
    		rc=!WriteConsoleOutputCharacter(Shconout,		//write to buffer//~v034I~
    										wpch,			//char //~v034I~
//                                  		reqctr,                //~v034I~//~v6hdR~
                                    		(DWORD)reqctr,         //~v6hdI~
                                    		coordpos,		//upper left pos in source buff//~v034I~
//                              			&len);			//writelen//~v034I~//~v6hdR~
                                			&dwlen);			//writelen//~v6hdI~
            if (rc)                                                //~v034I~
                rc=uerrapi0("WriteConsoleOutputCharacter",GetLastError());//~v034I~
UTRACED("uviowrtcellstr cordpos",&coordpos,sizeof(coordpos));      //~v@@@R~
UTRACED("uviowrtcellstr WriteConsoleOutputCharacter",wpch,reqctr); //~v@@@I~
    		rc=!WriteConsoleOutputAttribute(Shconout,		//write to buffer//~v034I~
    										wpat,			//attribute//~v034I~
//                                  		reqctr,                //~v034I~//~v6hdR~
                                    		(DWORD)reqctr,         //~v6hdI~
                                    		coordpos,		//upper left pos in source buff//~v034I~
//                              			&len);			//writelen//~v034I~//~v6hdR~
                                			&dwlen);			//writelen//~v6hdI~
            if (rc)                                                //~v034I~
                rc=uerrapi0("WriteConsoleOutputAttribute",GetLastError());//~v034I~
UTRACED("uviowrtcellstr WriteConsoleOutputAttribute",wpat,reqctr*2);//~v@@@R~
  		  	UFREE16WORK((char*)(void*)wko);                        //~v142I~
        }                                                          //~v034I~
        else    //fullscreensw off(box write)                      //~v042R~
        {                                                          //~v034I~
//****use writeconsoleoutput                                       //~v142I~
	      if (Sw95buffmode==WRITEFROMBUFF)                         //~v042I~
           if (height)                                             //~v149I~
//          rc=uvio_w95writecell(6,Prow,Pcol,Plen,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v6EiR~
            rc=uvio_w95writecell(Popt,6,Prow,Pcol,Plen,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v6EiR~
           else                                                    //~v149I~
//          rc=uvio_w95writecell(1,Prow,Pcol,reqctr,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v6EiR~
            rc=uvio_w95writecell(Popt,1,Prow,Pcol,reqctr,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v6EiR~
          else                                                     //~v042I~
//          rc=uvio_w95writecell(2,Prow,Pcol,reqctr,pchCellStr,0);//parm is cell//~v6EiR~
            rc=uvio_w95writecell(Popt,2,Prow,Pcol,reqctr,pchCellStr,0);//parm is cell//~v6EiR~
		}                                                          //~v034I~
//  	UFREE16WORK((char*)(void*)wko);                            //~v142R~
      }//buff mode or else                                         //~v042I~
        return rc;                                                 //~v034I~
    #else                                                          //~v022I~
   return (UINT)VioWrtCellStr(pchCellStr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022R~
#endif                                                             //~v022I~
}//uviowrtcellstr

//*******************************************************
//*VioReadCharStr(read char+attr then pick up char)
//*******************************************************
UINT uvioreadcharstr(PCH pchStr,int *Pplen,int Prow,int Pcol)
{
#ifdef DOS
	int i;
	int width;
	int len;
	PCH wk,wko;
#else
	#ifdef W32                           //win95                   //~v022I~
		COORD 		coord;				//read pos                 //~v022I~
        DWORD       len;                                           //~v022R~
		APIRET16 rc16;                                             //~v022I~
    #else                                                          //~v022I~
	USHORT seg16cb2;
	#pragma seg16(seg16cb2)
	APIRET16 rc16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=ATTRCOUNT()+1;		//cell size
	len=*Pplen*width;		//cell read work                    //~5A01R~
	wko=wk=UALLOCM16WORK(len);		//cell read work            //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930R~
	uvioreadcellstr(wk,&len,Prow,Pcol);
	for (i=0;i<*Pplen;i++)	//drop attr
	{
		*pchStr++=*wk;
		wk+=width;
	}
    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef	W32                                                    //~v022I~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
    	rc16=(APIRET16)!ReadConsoleOutputCharacter(Shconout,       //~v022R~
        								pchStr,	//buff read into   //~v022R~
        								*Pplen,	//read len         //~v022I~
        								coord,	//pos read from    //~v022I~
                                        &len);	//output read      //~v022I~
		*Pplen=len;                                                //~v022I~
		return (UINT)rc16;                                         //~v022I~
    #else                                                          //~v022I~
   seg16cb2=(USHORT)*Pplen;
   rc16=VioReadCharStr(pchStr,&seg16cb2,(USHORT)Prow,(USHORT)Pcol,0);
	*Pplen=seg16cb2;
   return (UINT)rc16;
	#endif                                                         //~v022I~
#endif
}//uvioreadcharstr

//*******************************************************
//*VioWrtCharStr(read char+attr and merge char then write)
//*******************************************************
//UINT uviowrtcharstr(PCH pchStr,int Plen,int Prow,int Pcol)       //~v6EiR~
UINT uviowrtcharstr(int Popt,PCH pchStr,int Plen,int Prow,int Pcol)//~v6EiI~
{
#ifdef DOS
	int i;
	int width;
	int len;
	PCH wk,wko;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		COORD 		coord;				//read pos                 //~v022I~
        DWORD       len;                                           //~v022R~
        int pos;                                                   //~v042I~
      #ifndef WXE                                                  //~v5n8I~
        UCHAR *pdbcs;                                              //~v5n8I~
      #endif                                                       //~v5n8I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=ATTRCOUNT()+1;		//cell size
	len=Plen*width;                                             //~5A01R~
	wko=wk=UALLOCM16WORK(len);                                  //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930R~
	uvioreadcellstr(wk,&len,Prow,Pcol);
	for (i=0;i<Plen;i++)	//drop attr
	{
		*wk=*pchStr++;
		wk+=width;
	}
	wk=wko;
	Sdosintcallsw=1;  //internal call to uviowrtcellstr            //~v153I~
	uviowrtcellstr(wk,len,Prow,Pcol);
	Sdosintcallsw=0;  //internal call to uviowrtcellstr            //~v153I~

    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef	W32                                                    //~v022I~
      if (Sw95buffmode)                                            //~v042R~
      {                                                            //~v042I~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
#ifdef WXE                                                         //~v570I~
            UVIO_LINEUPDATE(Prow);                                 //~v570I~
#endif                                                             //~v570I~
//          uvio_setbufflineopt(0,Prow,Popt);                      //~v6EpR~
            uvio_setbufflineopt(0,Prow,Popt,Pcol,Plen);            //~v6EpR~
            UTRACEP("%s:save lineopt row=%d,opt=%04x\n",UTT,Prow,Popt);//~v6EiI~
            memcpy(&Sw95buffc[pos],pchStr,Plen);                   //~v042I~
            UTRACED("buffmode Sw95buffc",Sw95buffc,Plen);          //~v6EjI~
            return 0;                                              //~v042I~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
UTRACEP("uviowrtchrstr pos x=%d,y=%d\n",coord.X,coord.Y);          //~v@@@I~
UTRACED("uviowrtcharstr WriteConsoleOutputCharacter",pchStr,Plen); //~v@@@I~
  #ifndef WXE                                                      //~v5n8I~
       if (Guviomopt & UDCWCIO_WIDEAPI)                            //~v5n8R~
       {                                                           //~v5n8I~
	  	pdbcs=Sdbcstbl+Sscrwidth*Prow+Pcol;                        //~v5n8I~
    	return uviowrtcharstrW(0,                                  //~v5n8R~
        					pchStr,	//buff write from              //~v5n8I~
        					Plen,	//write len                    //~v5n8I~
                            pdbcs,                                 //~v5n8R~
        					coord); //pos write into               //~v5n8R~
       }                                                           //~v5n8I~
       else                                                        //~v5n8I~
  #endif  //!WXE                                                   //~v5n8I~
    	return !WriteConsoleOutputCharacter(Shconout,              //~v022R~
        								pchStr,	//buff write from  //~v022I~
        								Plen,	//write len        //~v022I~
        								coord,	//pos write into   //~v022I~
                                        &len);	//len written      //~v022I~
      }                                                            //~v042I~
    #else                                                          //~v022I~
   return (UINT)VioWrtCharStr(pchStr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022I~
#endif
}//uviowrtcharstr
                                                                   //~v5n8I~
#ifdef	W32                                                        //~v043I~
//*******************************************************          //~v043I~
//*uviowrtattrstr(attr string write)                               //~v043I~
//*parm1 :attr WORD table                                          //~v043I~
//*parm2 :word count                                               //~v043I~
//*parm3 :pos row                                                  //~v043I~
//*parm4 :pos col                                                  //~v043I~
//*******************************************************          //~v043I~
UINT uviowrtattrstr(USHORT *Pattr,int Plen,int Prow,int Pcol)      //~v043R~
{                                                                  //~v043I~
	COORD 		coordpos;				//read pos                 //~v043R~
    DWORD       len;                                               //~v043I~
    int pos;                                                       //~v043I~
    UINT rc;                                                       //~v043I~
//*********************************                                //~v043I~
    if (Sw95buffmode)                                              //~v043I~
    {                                                              //~v043I~
 		pos=Pcol+Prow*Sscrwidth;                                   //~v043I~
        if (pos<0 || (pos+Plen)>Sscrsize)                          //~v043I~
         	return 8;                                              //~v043I~
#ifdef WXE                                                         //~v570I~
         UVIO_LINEUPDATE(Prow);                                    //~v570I~
#endif                                                             //~v570I~
         memcpy(&Sw95buffa[pos],Pattr,Plen*2);                     //~v043R~
         rc=0;                                                     //~v043I~
    }                                                              //~v043I~
    else  //not buff mode                                          //~v043I~
    {                                                              //~v043I~
		coordpos.X  =(SHORT)Pcol;					//pos x        //~v043R~
//    	coordpos.Y  =(SHORT)Prow;					//pos y        //~v5fhR~
      	coordpos.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
		rc=!WriteConsoleOutputAttribute(Shconout,		//write to buffer//~v043I~
										Pattr,			//attribute//~v043I~
                                		Plen,                      //~v043I~
                                		coordpos,		//upper left pos in source buff//~v043I~
                            			&len);			//writelen //~v043I~
        if (rc)                                                    //~v043I~
            rc=uerrapi0("WriteConsoleOutputAttribute",GetLastError());//~v043I~
UTRACEP("uviowrtattrstrr pos x=%d,y=%d\n",coordpos.X,coordpos.Y);  //~v@@@I~
UTRACED("uviowrtatrrstr WriteConsoleOutputAttribute",Pattr,Plen*2);//~v@@@R~
    }                                                              //~v043I~
    return rc;                                                     //~v043I~
}//uviowrtattrstr                                                  //~v043I~
#endif                                                             //~v043I~
                                                                   //~v043I~
//*******************************************************
//*VioWrtCharStrAtt(support 3 byte attr)
//*******************************************************
//UINT uviowrtcharstratt(PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EiR~
UINT uviowrtcharstratt(int Popt,PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EiR~
{
#ifdef DOS
	int i;
	int attr;
	int width;
	int len;
	PCH wk,wko;
	UCHAR cell[4];
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		COORD 		coord;				//read pos                 //~v022I~
        DWORD       len;                                           //~v022R~
        UINT        rc;                                            //~v022I~
        int			pos;                                           //~v042I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=(attr=ATTRCOUNT())+1;		//cell size
	for (i=0;i<attr;i++)	//drop attr
		cell[i+1]=*(pAttr+i);
	
	len=Plen*width;	//char+attr                                 //~5A01R~
	wko=wk=UALLOCM16WORK(len);	//char+attr                     //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930I~
	for (i=0;i<Plen;i++)	//drop attr
	{
		*cell=*pch++;
		if (attr==1)
//  		*(int*)(PVOID)wk=*(int*)(PVOID)cell;                   //~v053R~
    		*(USHORT*)(PVOID)wk=*(USHORT*)(PVOID)cell;             //~v053I~
		else
			*(ULONG*)(PVOID)wk=*(ULONG*)(PVOID)cell;
		wk+=width;
	}
	wk=wko;

	Sdosintcallsw=1;  //internal call to uviowrtcellstr            //~v153I~
	uviowrtcellstr(wk,len,Prow,Pcol);
	Sdosintcallsw=0;  //internal call to uviowrtcellstr            //~v153I~

    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
	  UTRACEP("%s:opt=%02x,row=%d,col=%d,len=%d,buffmode=%x\n",UTT,Popt,Prow,Pcol,Plen,Sw95buffmode);//~v6EiI~
	  UTRACED("pch",pch,Plen);                                     //~v6EiI~
      if (Sw95buffmode)                                            //~v042R~
      {             //wrtcharstratt                                //~v042R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	rc=8;                                              //~v042I~
            else                                                   //~v042I~
            {                                                      //~v042I~
#ifdef WXE                                                         //~v570I~
	 	        UVIO_LINEUPDATE(Prow);                             //~v570I~
#endif                                                             //~v570I~
//          	uvio_setbufflineopt(0,Prow,Popt);                  //~v6EpR~
            	uvio_setbufflineopt(0,Prow,Popt,Pcol,Plen);        //~v6EpR~
            	UTRACEP("%s:save lineopt row=%d,opt=%04x\n",UTT,Prow,Popt);//~v6EiI~
                memcpy(&Sw95buffc[pos],pch,Plen);                  //~v042R~
//              memcpy(&Sw95buffa[pos],uvio_w95getattrtbl((WORD)*pAttr),Plen*2);//~v252R~
                uvio_w95setscrattr(&Sw95buffa[pos],(WORD)*pAttr,Plen*2);//~v252I~
                UTRACED("buffmode Sw95buffc",Sw95buffc+pos,Plen);  //~v6EjI~
                UTRACED("buffmode Sw95buffa",Sw95buffa+pos,Plen*(int)sizeof(Sw95buffa[0]));//~v6EjI~
                UTRACED("buffmode Sdbcstbl",Sdbcstbl+pos,Plen);    //~v6EjR~
#ifdef WXE                                                         //~v6EkI~
	            uvio_setcombinealtch(Popt,pos,Plen);               //~v6EkR~
#endif                                                             //~v6EkI~
                rc=0;                                              //~v042I~
            }                                                      //~v042I~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
      if (!Scellnasw)		//except cell na,cell is recommendable for avoid rewrite flush//~v144R~
//      rc=uvio_w95writecell(4,Prow,Pcol,Plen,pch,pAttr);//parm is char and a attr byte//~v6EiR~
        rc=uvio_w95writecell(Popt,4,Prow,Pcol,Plen,pch,pAttr);//parm is char and a attr byte//~v6EiR~
      else                                                         //~v142M~
      {                                                            //~v142M~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
    	rc=!WriteConsoleOutputCharacter(Shconout,                  //~v022I~
        								pch,	//buff write from  //~v022I~
        								Plen,	//write len        //~v022I~
        								coord,	//pos write into   //~v022I~
                                        &len);	//len written      //~v022I~
UTRACEP("uviowrtcharstratt pos x=%d,y=%d\n",coord.X,coord.Y);      //~v@@@I~
UTRACED("uviowrtcharstratt WriteConsoleOutputCharacter",pch,Plen); //~v@@@I~
    	if (!rc)                                                   //~v022I~
			rc=!FillConsoleOutputAttribute(Shconout,	//fill by one attrib//~v022I~
            								(WORD)*pAttr,          //~v022R~
		       								Plen,	//write len    //~v022I~
                                            coord,                 //~v022I~
                                            &len);                 //~v022I~
UTRACED("uviowrtcharstratt FillConsoleOutputAttribute",pAttr,2);   //~v@@@I~
	  }//char+fillattr avail	                                   //~v142I~
      }//buff mode or else                                         //~v042I~
		return rc;                                                 //~v022I~
    #else                                                          //~v022I~
   return (UINT)VioWrtCharStrAtt(pch,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,pAttr,0);
	#endif                                                         //~v022I~
#endif
}//uviowrtcharstratt

//*******************************************************
//*VioWrtNAtrr(read char+attr and merge attr then write)
//*******************************************************
UINT uviowrtnattr (PBYTE pAttr,int Plen,int Prow,int Pcol)
{
#ifdef DOS
	int i;
	int attr;
	int width;
	int len;
	PCH wk,wko;
	UCHAR cell[4];
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		COORD 		coord;				//read pos                 //~v022I~
        DWORD       len;                                           //~v022R~
        int         pos;                                           //~v042I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=(attr=ATTRCOUNT())+1;		//cell size
	for (i=0;i<attr;i++)	//drop attr
		cell[i+1]=*(pAttr+i);
	len=Plen*width;                                             //~5A01R~
	wko=wk=UALLOCM16WORK(len);                                  //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930I~
	uvioreadcellstr(wk,&len,Prow,Pcol);
	for (i=0;i<Plen;i++)	//drop attr
	{
		*cell=*wk;
		if (attr==1)
//			*(int*)(PVOID)wk=*(int*)(PVOID)cell;                   //~v053R~
  			*(USHORT*)(PVOID)wk=*(USHORT*)(PVOID)cell;             //~v053I~
		else
			*(ULONG*)(PVOID)wk=*(ULONG*)(PVOID)cell;
		wk+=width;
	}
	wk=wko;

	Sdosintcallsw=1;  //internal call to uviowrtcellstr            //~v153I~
	uviowrtcellstr(wk,len,Prow,Pcol);
	Sdosintcallsw=0;  //internal call to uviowrtcellstr            //~v153I~
	
    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      if (Sw95buffmode)                                            //~v042R~
      {						//wrtnattr                             //~v042R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
#ifdef WXE                                                         //~v570I~
	 	    UVIO_LINEUPDATE(Prow);                                 //~v570I~
#endif                                                             //~v570I~
//          memcpy(&Sw95buffa[pos],uvio_w95getattrtbl((WORD)*pAttr),Plen*2);//~v252R~
            uvio_w95setscrattr(&Sw95buffa[pos],(WORD)*pAttr,Plen*2);//~v252I~
            return 0;                                              //~v042I~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
UTRACEP("uviowrtnattr pos x=%d,y=%d\n",coord.X,coord.Y);           //~v@@@I~
UTRACED("uviowrtnattr FillConsoleOutputAttribute",pAttr,2);        //~v@@@I~
		return !FillConsoleOutputAttribute(Shconout,	//fill by one attrib//~v022I~
            								(WORD)*pAttr,          //~v022R~
		       								Plen,	//write len    //~v022I~
                                            coord,                 //~v022I~
                                            &len);                 //~v022I~
      }//buff mode or else                                         //~v042I~
    #else                                                          //~v022I~
   return (UINT)VioWrtNAttr(pAttr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022I~
#endif
}//uviowrtnattr

//*******************************************************
//*VioWrtNCell(setup buff and write cell(char+attr))
//*******************************************************
//UINT uviowrtncell(PBYTE pCell,int Plen,int Prow,int Pcol)        //~v6EqR~
UINT uviowrtncell(int Popt,PBYTE pCell,int Plen,int Prow,int Pcol) //~v6EqI~
{
#ifdef DOS
	int i;
	int width,width1;
	int len;
	PCH wk,wko;
	ULONG cell,cell2;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		DWORD         len;                                         //~v022R~
		COORD 		coordpos;                                      //~v022R~
        UINT        rc;                                            //~v022I~
        int         pos;                                           //~v042I~
        int         col,lineoptlen;                                //~v6EqI~
//    #ifdef WXE                                                   //~v6EqR~
        int row,reslen;                                            //~v5kyI~
//    #endif                                                       //~v6EqR~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=(width1=(ATTRCOUNT()+1))*(1+udbcschk(*pCell));	//double if dbcs
	if (width1==2)			//attr=1
		if (width==2)		//sbcs
//			cell=*(int*)(PVOID)pCell;                              //~v053R~
  			cell=*(USHORT*)(PVOID)pCell;                           //~v053I~
		else				//dbcs
			cell=*(ULONG*)(PVOID)pCell;
	else					//attr=3
	{	
		cell=*(ULONG*)(PVOID)pCell;
		if (width==8)		//dbcs
			cell2=*(ULONG*)(PVOID)(pCell+4);
	}
	len=Plen*width;                                             //~5A01R~
	wko=wk=UALLOCM16WORK(len);                                  //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930I~
	for (i=0;i<Plen;i++)				//set NAttr
	{
//  	if (width1=2)				//sbcs attr 1                  //~v053R~
    	if (width1==2)				//sbcs attr 1                  //~v053I~
//  		*(int*)(PVOID)wk=(int)cell;                            //~v053R~
    		*(USHORT*)(PVOID)wk=(USHORT)cell;                      //~v053I~
		else
		{
			*(ULONG*)(PVOID)wk=cell;
			if (width==8)			//dbcs attr 3
				*(ULONG*)(PVOID)(wk+4)=cell2;
		}
		wk+=width;
	}
	wk=wko;
	Sdosintcallsw=1;  //internal call to uviowrtcellstr            //~v153I~
	uviowrtcellstr(wk,len,Prow,Pcol);
	Sdosintcallsw=0;  //internal call to uviowrtcellstr            //~v153I~

    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      if (Sw95buffmode)                                            //~v042R~
      {				//wrtncell                                     //~v042R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	rc=8;                                              //~v042I~
			else                                                   //~v042I~
            {                                                      //~v042I~
//#ifdef WXE                                                       //~v6EqR~
//   	    	UVIO_LINEUPDATE(Prow);                             //~v5kyR~
			  col=Pcol;                                            //~v6EqI~
              lineoptlen=min(Plen,Sscrwidth-col);                  //~v6EqR~
              for (row=Prow,reslen=Plen;reslen>0;row++,reslen-=Sscrwidth)//~v5kyR~
              {                                                    //~v6EqI~
#ifdef WXE                                                         //~v6EqI~
     	    	UVIO_LINEUPDATE(row);                              //~v5kyI~
#endif                                                             //~v6EqI~
	            uvio_setbufflineopt(Popt,row,Popt,col,lineoptlen); //~v6EqR~
                col=0;                                             //~v6EqI~
                lineoptlen=min(reslen,Sscrwidth);                  //~v6EqI~
              }                                                    //~v6EqI~
//#endif                                                           //~v6EqR~
            	memset(&Sw95buffc[pos],*pCell,Plen);               //~v042I~
//          	memcpy(&Sw95buffa[pos],                            //~v252R~
//  					uvio_w95getattrtbl((WORD)*(pCell+1)),      //~v252R~
//  					Plen*sizeof(USHORT));                      //~v252R~
                uvio_w95setscrattr(&Sw95buffa[pos],                //~v252I~
    					           (WORD)*(pCell+1),               //~v252I~
                                    Plen*sizeof(USHORT));          //~v252I~
            	rc=0;                                              //~v042I~
            }                                                      //~v042I~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
        coordpos.X  =(SHORT)Pcol;					//write width  //~v022R~
//      coordpos.Y  =(SHORT)Prow;						//box height//~v5fhR~
        coordpos.Y  =(SHORT)(Prow+Stoplineoffs);						//box height//~v5fhI~
		rc=!FillConsoleOutputCharacter(Shconout,//fill by char     //~v022I~
								*pCell,    	//output character     //~v022I~
                                Plen,			//output len       //~v022I~
                                coordpos,		//upper left pos in source buff//~v022I~
                                &len);		//source rectangle     //~v022I~
UTRACEP("uviowrtncell pos x=%d,y=%d\n",coordpos.X,coordpos.Y);     //~v@@@I~
UTRACED("uviowrtncell FillConsoleOutputCharacter",pCell,2);        //~v@@@I~
		if (!rc)                                                   //~v022I~
			rc=!FillConsoleOutputAttribute(Shconout,//fill by attr //~v022I~
								(WORD)*(pCell+1),    	//output character//~v022R~
                                Plen,			//output len       //~v022I~
                                coordpos,		//upper left pos in source buff//~v022I~
                                &len);		//source rectangle     //~v022I~
UTRACED("uviowrtncell FillConsoleOutputAttribute",pCell,2);        //~v@@@I~
      }//buff mode or else                                         //~v042I~
		return rc;                                                 //~v022I~
    #else                                                          //~v022I~
   return (UINT)VioWrtNCell(pCell,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022R~
#endif                                                             //~v022I~
}//uviowrtncell

//*******************************************************          //~v760I~
//*write spec on the right edge                                    //~v760I~
//*******************************************************          //~v760I~
UINT uviowrtncellRightEdge(int Popt,PBYTE pCell,int Pcol,int Prow) //~v760I~
{                                                                  //~v760I~
    DWORD         len;                                             //~v760I~
    COORD       coordpos;                                          //~v760I~
    int ii;                                                        //~v760R~
    UINT rc=0;                                                     //~v760I~
//*********************************                                //~v760I~
UTRACEP("%s:col=%d,row=%d\n",UTT,Pcol,Prow);                       //~v760I~
    coordpos.X  =(SHORT)Pcol;					//write width      //~v760I~
    coordpos.Y  =(SHORT)Stoplineoffs;						//box height//~v760I~
    for (ii=0;ii<Prow;ii++)                                        //~v760R~
    {                                                              //~v760I~
UTRACEP("%s:ii=%d,row=%d\n",UTT,ii,coordpos.Y);                    //~v760I~
		rc=!FillConsoleOutputCharacter(Shconout,//fill by char     //~v760I~
								*pCell,    	//output character     //~v760I~
                                1,			//output len           //~v760I~
                                coordpos,		//upper left pos in source buff//~v760I~
                                &len);		//source rectangle     //~v760I~
		if (rc)                                                    //~v760I~
        	break;                                                 //~v760I~
        rc=!FillConsoleOutputAttribute(Shconout,//fill by attr     //~v760I~
                            (WORD)*(pCell+1),       //output character//~v760I~
                            1,          //output len               //~v760I~
                            coordpos,       //upper left pos in source buff//~v760I~
                            &len);      //source rectangle         //~v760I~
                                                                   //~v760I~
		if (rc)                                                    //~v760I~
        	break;                                                 //~v760I~
    	coordpos.Y++;                                              //~v760I~
    }                                                              //~v760I~
UTRACEP("%s:exit\n",UTT);                                          //~v760R~
	return rc;                                                     //~v760I~
}//uviowrtncell                                                    //~v760I~
                                                                   //~v760I~
//*******************************************************
//*VioWrtNChar(read char+attr and merge same char then write)
//*******************************************************
UINT uviowrtnchar(PCH pchChar,int Plen,int Prow,int Pcol)
{
#ifdef DOS
	int i;
	int width,width1;
	int len;
	PCH wk,wko;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		DWORD        len;                                          //~v022R~
		COORD 		coordpos;                                      //~v022R~
        int         pos;                                           //~v042I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	width=(width1=(ATTRCOUNT()+1))*(1+udbcschk(*pchChar));	//double if dbcs
	len=Plen*width;                                             //~5A01R~
	wko=wk=UALLOCM16WORK(len);                                  //~5A01I~
    UALLOCCHK(wk,UALLOC_FAILED);                                //~5930I~
	uvioreadcellstr(wk,&len,Prow,Pcol);
	for (i=0;i<Plen;i++)	//drop attr
	{
		*wk=*pchChar;
		if (width!=width1)				//dbcs
			*(wk+=width1)=*(pchChar+1);	//dbcs second byte
		wk+=width1;
	}
	wk=wko;
	
	Sdosintcallsw=1;  //internal call to uviowrtcellstr            //~v153I~
	uviowrtcellstr(wk,len,Prow,Pcol);
	Sdosintcallsw=0;  //internal call to uviowrtcellstr            //~v153I~

    UFREE16WORK(wko);                                              //~v054R~
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      if (Sw95buffmode)                                            //~v042R~
      {                 //wrtcharstr                               //~v042R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
#ifdef WXE                                                         //~v570I~
 	    	UVIO_LINEUPDATE(Prow);                                 //~v570I~
#endif                                                             //~v570I~
        	memset(&Sw95buffc[pos],*pchChar,Plen);                 //~v042I~
	       	return 0;                                              //~v042R~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
        coordpos.X  =(SHORT)Pcol;					//write width  //~v022R~
//      coordpos.Y  =(SHORT)Prow;						//box height//~v5fhR~
        coordpos.Y  =(SHORT)(Prow+Stoplineoffs);						//box height//~v5fhI~
UTRACEP("uviowrtnchar pos x=%d,y=%d\n",coordpos.X,coordpos.Y);     //~v@@@I~
UTRACED("uviowrtnchar FillConsoleOutputCharacter",pchChar,1);      //~v@@@I~
		return !FillConsoleOutputCharacter(Shconout,//fill by char //~v022I~
								*pchChar,    	//output character //~v022I~
                                Plen,			//output len       //~v022I~
                                coordpos,		//upper left pos in source buff//~v022I~
                                &len);		//source rectangle     //~v022I~
      }                                                            //~v042I~
    #else                                                          //~v022I~
   return (UINT)VioWrtCharStr(pchChar,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022R~
#endif                                                             //~v022I~
}//uviowrtnchar                                                 //~5A01R~
#ifdef W32                                                         //~v142I~
//*******************************************************          //~v142I~
//*uvio_w95writecell                                               //~v142I~
//*		write by window cell(CHAR_INFO)                            //~v142I~
//*parm1:parm type                                                 //~v142I~
//*				1:buff(str1=char,str2=USHORT attr str)             //~v144R~
//*				2:cell(str1=char+attr byte)                        //~v142I~
//*				3:char and USHORT attr(str1=cha,str2=USHORT attr str)//~v144R~
//*				4:char and a attr byte(str1=cha,str2=attr byte)    //~v142I~
//*				5:char and 2 USHORT attr string(str1=cha,str2=USHORT attr str)//~v144I~
//*				6:same as 1 except parm4 is height+width(box write)//~v149I~
//*parm2:output row                                                //~v142I~
//*parm3:output column                                             //~v142I~
//*parm4:char/cell len                                             //~v144R~
//*         for type=5,len=1st halflen+total len                   //~v145R~
//*         for type=6,len=box height+box width                    //~v149I~
//*parm5:str1                                                      //~v142I~
//*parm6:str2                                                      //~v142I~
//*ret  :rc                                                        //~v142I~
//*******************************************************          //~v142I~
//int uvio_w95writecell(int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2)//~v6EiR~
int uvio_w95writecell(int Popt,int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2)//~v6EiR~
{                                                                  //~v142I~
#ifdef WXE                                                         //~v570I~
	return 0;   //never called                                     //~v570I~
#else                                                              //~v570I~
		SMALL_RECT	targetrect;                                    //~v142R~
		COORD 		srcbufsz,posinsrcbuff;                         //~v142R~
        int pos,height;                                            //~v142I~
        int rc;                                                    //~v142I~
		PCHAR_INFO wk,wko;                                         //~v142I~
		char      *wpch,*wpat,*wpchend;                            //~v142R~
		WORD      *wpusat,usat;                                    //~v144R~
        int len1=0,ii;                                               //~v144I~//~v6h7R~
        int width;                                                 //~v149I~
        UCHAR *pdbcs;                                              //~v5n8R~
//************************                                         //~v142I~
	UTRACEP("%s:opt=%02x,type=%d,row=%d,col=%d,len=%d\n",UTT,Popt,Ptype,Prow,Pcol,Plen);//~v6EiI~
  if (Ptype==6)                                                    //~v149I~
  {                                                                //~v149I~
    height=Plen>>16;                                               //~v149I~
    width=min(Plen&0xffff,Sscrwidth);		//2nd half len for type 5//~v149R~
    Plen=height*Sscrwidth;                                         //~v149I~
//  posinsrcbuff.X  =Pcol;  		//pos in parm buff(wko)        //~v149R~//~v6BcR~
    posinsrcbuff.X  =(SHORT)Pcol;  		//pos in parm buff(wko)    //~v6BcI~
    posinsrcbuff.Y  =0;             //pos in parm buff             //~v149R~
    srcbufsz.X  =(SHORT)Sscrwidth;    //rect of parm buff,width    //~v149I~
    srcbufsz.Y  =(SHORT)height;       //rect of parm buff,height   //~v149R~
//  targetrect.Top   =(SHORT)Prow;                                 //~v5fhR~
//  targetrect.Bottom=(SHORT)(Prow+height-1);                      //~v5fhR~
    targetrect.Top   =(SHORT)(Prow+Stoplineoffs);                  //~v5fhI~
    targetrect.Bottom=(SHORT)(Prow+height-1+Stoplineoffs);         //~v5fhI~
    targetrect.Left  =(SHORT)Pcol;                                 //~v149I~
    targetrect.Right =(SHORT)(min(Pcol+width,Sscrwidth)-1);  //rect of buff,width//~v149I~
  }                                                                //~v149I~
  else                                                             //~v149I~
  {                                                                //~v149I~
	len1=Plen>>16;      //1st half len for type 5                  //~v144I~
    Plen&=0xffff;		//2nd half len for type 5                  //~v144I~
    height=Plen/Sscrwidth;                                         //~v142I~
    if (Plen%Sscrwidth)                                            //~v142I~
       	height++;                                                  //~v142I~
    posinsrcbuff.X  =0;     				//pos in parm buff     //~v142R~
    posinsrcbuff.Y  =0;                     //pos in parm buff     //~v142R~
    srcbufsz.X  =(SHORT)min(Plen,Sscrwidth);    //rect of parm buff,width//~v142R~
    srcbufsz.Y  =(SHORT)height;       //rect of parm buff,height   //~v142R~
//  targetrect.Top   =(SHORT)Prow;                                 //~v5fhR~
//  targetrect.Bottom=(SHORT)(Prow+height-1);                      //~v5fhR~
    targetrect.Top   =(SHORT)(Prow+Stoplineoffs);                  //~v5fhI~
    targetrect.Bottom=(SHORT)(Prow+height-1+Stoplineoffs);         //~v5fhI~
    targetrect.Left  =(SHORT)Pcol;                                 //~v142R~
    targetrect.Right =(SHORT)(min(Pcol+Plen,Sscrwidth)-1);  //rect of buff,width//~v142R~
  }                                                                //~v149I~
//************************                                         //~v142I~
    wko=wk=(void*)UALLOCM16WORK((int)(Plen*sizeof(CHAR_INFO)));    //~v142I~
    UALLOCCHK(wk,UALLOC_FAILED);                                   //~v142I~
//*                                                                //~v142I~
	switch(Ptype)                                                  //~v142I~
    {                                                              //~v142I~
    case 1:			//write from buff char an ushort attr          //~v142I~
    case 6:			//write box from buff                          //~v149I~
      if (Ptype==6)				//box write                        //~v149I~
        pos=Prow*Sscrwidth;		//containing out of box            //~v149I~
      else                                                         //~v149I~
        pos=Pcol+Prow*Sscrwidth;                                   //~v142I~
        wpch=Pstr1;                                                //~v142I~
        wpch+=pos;                                                 //~v142I~
        wpusat=Pstr2;                                              //~v142I~
        wpusat+=pos;                                               //~v142I~
        for (wpchend=wpch+Plen;wpch<wpchend;wk++,wpch++)  //char(BYTE) and attr(USHORT) fmt//~v142I~
        {                                                          //~v142I~
            wk->Char.UnicodeChar=0;                                //~v142I~
          	if (Snullnasw && !*wpch)                               //~v142I~
            	wk->Char.AsciiChar=WINNTNULLDISP;                  //~v153R~
          	else                                                   //~v142I~
            	wk->Char.AsciiChar=*wpch;                          //~v142I~
            wk->Attributes=*wpusat++;                              //~v142I~
        }                                                          //~v142I~
        break;                                                     //~v142I~
    case 2:			//write from cell parm                         //~v142R~
        wpch=Pstr1;                                                //~v142I~
        for (wpchend=wpch+Plen*2;wpch<wpchend;wk++,wpch++)  //char(BYTE)+attr(BYTE) fmt//~v142I~
        {                                                          //~v142I~
            wk->Char.UnicodeChar=0;                                //~v142I~
          	if (Snullnasw && !*wpch)                               //~v142R~
            	wk->Char.AsciiChar=WINNTNULLDISP;                  //~v153I~
          	else                                                   //~v142I~
            	wk->Char.AsciiChar=*wpch;                          //~v142I~
            wk->Attributes=(WORD)*(++wpch);                        //~v142I~
        }                                                          //~v142I~
        break;                                                     //~v142I~
    case 3:			//write from parm char and USHORT attr         //~v145R~
        wpch=Pstr1;                                                //~v142I~
        wpusat=Pstr2;                                              //~v144R~
        for (wpchend=wpch+Plen;wpch<wpchend;wk++,wpch++)  //char(BYTE)+attr(BYTE) fmt//~v142I~
        {                                                          //~v142I~
            wk->Char.UnicodeChar=0;                                //~v142I~
          	if (Snullnasw && !*wpch)                               //~v142R~
            	wk->Char.AsciiChar=WINNTNULLDISP;                  //~v153I~
          	else                                                   //~v142I~
            	wk->Char.AsciiChar=*wpch;                          //~v142I~
            wk->Attributes=*wpusat++;                              //~v144R~
        }                                                          //~v142I~
        break;                                                     //~v142I~
    case 4:			//write from parm char and same attr byte      //~v142I~
        wpch=Pstr1;                                                //~v142I~
        wpat=Pstr2;                                                //~v142I~
        usat=*wpat;                                                //~v144I~
        for (wpchend=wpch+Plen;wpch<wpchend;wk++,wpch++)  //char(BYTE)+attr(BYTE) fmt//~v142I~
        {                                                          //~v142I~
            wk->Char.UnicodeChar=0;                                //~v142I~
          	if (Snullnasw && !*wpch)                               //~v142R~
            	wk->Char.AsciiChar=WINNTNULLDISP;                  //~v153I~
          	else                                                   //~v142I~
            	wk->Char.AsciiChar=*wpch;                          //~v142I~
            wk->Attributes=usat;                                   //~v144R~
        }                                                          //~v142I~
        break;                                                     //~v142I~
    case 5:			//write from parm char and 2 part attr         //~v145R~
        wpch=Pstr1;                                                //~v145R~
        wpusat=Pstr2;                                              //~v145R~
        wpchend=wpch+len1;                                         //~v145R~
//UTRACED("wpch",wpch,80);                                         //~v145R~
//UTRACEP("len1=%d,total=%d\n",len1,Plen);                         //~v145R~
        for (ii=0;ii<2;ii++)                                       //~v145R~
        {                                                          //~v145R~
            usat=wpusat[ii];                                       //~v145R~
//UTRACEP("wpchend=%08x,ii=%d\n",wpchend,ii);                      //~v145R~
            for (;wpch<wpchend;wk++,wpch++)  //char(BYTE)+attr(BYTE) fmt//~v145R~
            {                                                      //~v145R~
//UTRACED("wpch",wpch,6);                                          //~v145R~
                wk->Char.UnicodeChar=0;                            //~v145R~
                if (Snullnasw && !*wpch)                           //~v145R~
	            	wk->Char.AsciiChar=WINNTNULLDISP;              //~v153I~
                else                                               //~v145R~
                    wk->Char.AsciiChar=*wpch;                      //~v145R~
                wk->Attributes=usat;                               //~v145R~
            }                                                      //~v145R~
	        wpchend=wpch+Plen-len1;	//2nd half                     //~v145R~
//UTRACEP("wpchend=%08x,ii=%d\n",wpchend,ii);                      //~v145R~
        }//ii                                                      //~v145R~
        break;                                                     //~v145R~
	}//sw type                                                     //~v142I~
UTRACEP("writecell type=%d,opt=%x\n",Ptype,Guviomopt);             //~v5n8I~
  if (Guviomopt & UDCWCIO_WIDEAPI)                                 //~v5n8R~
  {                                                                //~v5n8I~
  	pdbcs=Sdbcstbl+Sscrwidth*Prow+Pcol;                            //~v5n8I~
//	rc=uviowrtcellW(0,                                             //~v6EiR~
  	rc=uviowrtcellW(Popt,       //line opt                         //~v6EiI~
				wko,				//CHAR_INFO                    //~v5n8I~
                Plen,                                              //~v5n8I~
                pdbcs,                                             //~v5n8R~
                srcbufsz,     //rectangle in source buff           //~v5n8I~
                posinsrcbuff,       //upper left pos in source buff//~v5n8I~
                &targetrect);      //source rectangle              //~v5n8I~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
  {                                                                //~v5n8I~
	rc=!WriteConsoleOutput(Shconout,		//write to buffer      //~v142I~
							wko,				//CHAR_INFO        //~v142I~
                            srcbufsz,     //rectangle in source buff//~v142R~
                            posinsrcbuff,       //upper left pos in source buff//~v142R~
                            &targetrect);      //source rectangle  //~v142R~
//#ifdef DDDDD                                                     //~v5n8R~
//#ifdef NOTRACE                                                   //~v5n8R~
//#else                                                            //~v5n8R~
//    {                                                            //~v5n8R~
//        int edxsv;                                               //~v5n8R~
//        __asm {                                                  //~v5n8R~
//                mov   edxsv,edx          //0038000f addr         //~v5n8R~
//        }                                                        //~v5n8R~
//                                                                 //~v5n8R~
//        if (Sntsw)                                               //~v5n8R~
//            UTRACED("uvio_w95wrtncell EDX",edxsv&0xfffff000,8192);//~v5n8R~
//    }                                                            //~v5n8R~
//#endif                                                           //~v5n8R~
//#endif          //DDDDD                                          //~v5n8R~
UTRACEP("uvio_w95wrtncell rc=%d,Type=%d,Top=%d,Bot=%d,Left=%d,Right=%d,bufx=%d,bufy=%d,srcx=%d,srcy=%d\n",//~v@@@R~
    		rc,                                                    //~v142I~
    		Ptype,                                                 //~v142M~
        	targetrect.Top,                                        //~v142M~
        	targetrect.Bottom,                                     //~v142M~
        	targetrect.Left,                                       //~v142M~
        	targetrect.Right,                                      //~v142M~
            srcbufsz.X,                                            //~v142M~
            srcbufsz.Y,                                            //~v142M~
            posinsrcbuff.X,                                        //~v142M~
            posinsrcbuff.Y);                                       //~v142M~
UTRACED("uvio_w95wrtncell WriteConsoleOutput",wko,Plen*sizeof(CHAR_INFO));//~v@@@I~
    if (rc)                                                        //~v142I~
        rc=uerrapi0("WriteConsoleOutput",GetLastError());          //~v142I~
  }                                                                //~v5n8I~
	UFREE16WORK((char*)(void*)wko);                                //~v142I~
    return rc;                                                     //~v142I~
#endif //!WXE                                                      //~v570I~
}//uvio_w95writecell                                               //~v142I~
//*******************************************************          //~v144I~
//*uvio_w95wrtcharstratt2                                          //~v144I~
//*  write from char and attr string parm                          //~v144I~
//*    do cell write when required for nt english mode             //~v144I~
//*parm1:row                                                       //~v144I~
//*parm2:column                                                    //~v144I~
//*parm3:len                                                       //~v144I~
//*parm4:char string                                               //~v144I~
//*parm5:attr string                                               //~v144I~
//*return:rc                                                       //~v144I~
//*******************************************************          //~v144I~
//UINT uvio_w95wrtcharstratt2(int Prow,int Pcol,int Plen,PCH Pchstr,USHORT *Pattstr)//~v6EiR~
UINT uvio_w95wrtcharstratt2(int Popt,int Prow,int Pcol,int Plen,PCH Pchstr,USHORT *Pattstr)//~v6EiR~
{                                                                  //~v144I~
    UINT        rc;                                                //~v144I~
//*********************************                                //~v144I~
	UTRACEP("%s:opt=%02x,row=%d,col=%d,len=%d,buffmode=%x,cellnase=%d\n",UTT,Popt,Prow,Pcol,Plen,Sw95buffmode,Scellnasw);//~v6EiI~
	if (Sw95buffmode || Scellnasw)//cell not avail                 //~v144I~
    {                                                              //~v144I~
//		rc=uviowrtcharstr(Pchstr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol);//~v6EiR~
  		rc=uviowrtcharstr(Popt,Pchstr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol);//~v6EiI~
		rc+=uviowrtattrstr(Pattstr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol);//~v144R~
	}                                                              //~v144I~
    else	//cell is recommendable or required                    //~v144I~
//      rc=uvio_w95writecell(3,Prow,Pcol,Plen,Pchstr,Pattstr);//parm is char and attr str//~v6EiR~
        rc=uvio_w95writecell(Popt,3,Prow,Pcol,Plen,Pchstr,Pattstr);//parm is char and attr str//~v6EiR~
	return rc;                                                     //~v144I~
}//uvio_w95wrtcharstratt2                                          //~v144I~
                                                                   //~v144I~
//*******************************************************          //~v145R~
//*uvio_w95wrtcharstratt3                                          //~v145R~
//*  write from char and 2 attr byte                               //~v145R~
//*    do cell write at once(2 differrent attr line)               //~v145R~
//*parm1:row                                                       //~v145R~
//*parm2:column                                                    //~v145R~
//*parm3:char str                                                  //~v145R~
//*parm4:1st half len                                              //~v145R~
//*parm5:1st half attr                                             //~v145R~
//*parm6:2nd half len                                              //~v145R~
//*parm7:2nd half attr                                             //~v145R~
//*return:rc                                                       //~v145R~
//*******************************************************          //~v145R~
//UINT uvio_w95wrtcharstratt3(int Prow,int Pcol,PCH Pchstr,        //~v6EiR~
UINT uvio_w95wrtcharstratt3(int Popt,int Prow,int Pcol,PCH Pchstr, //~v6EiR~
                    int Plen1,UCHAR Pattr1,int Plen2,UCHAR Pattr2) //~v145R~
{                                                                  //~v145R~
    UINT        rc,ulen;                                           //~v145R~
    USHORT    attr[2];                                             //~v145R~
//*********************************                                //~v145R~
	UTRACEP("%s:opt=%02x,row=%d,col=%d,len=%d,buffmode=%x,cellnase=%d\n",UTT,Popt,Prow,Pcol,Plen1,Sw95buffmode,Scellnasw);//~v6EiR~
    if (Sw95buffmode || Scellnasw)//cell not avail                 //~v145R~
    {                                                              //~v145R~
//      rc=uviowrtcharstratt(Pchstr,(USHORT)Plen1,(USHORT)Prow,(USHORT)Pcol,&Pattr1);//~v6EiR~
        rc=uviowrtcharstratt(Popt,Pchstr,(USHORT)Plen1,(USHORT)Prow,(USHORT)Pcol,&Pattr1);//~v6EiR~
//      rc+=uviowrtcharstratt(Pchstr+Plen1,(USHORT)Plen2,(USHORT)Prow,(USHORT)Pcol+Plen1,&Pattr2);//~v6EiR~
        rc+=uviowrtcharstratt(Popt,Pchstr+Plen1,(USHORT)Plen2,(USHORT)Prow,(USHORT)Pcol+Plen1,&Pattr2);//~v6EiR~
    }                                                              //~v145R~
    else    //cell is recommendable or required                    //~v145R~
    {                                                              //~v145R~
        attr[0]=(USHORT)Pattr1;                                    //~v145R~
        attr[1]=(USHORT)Pattr2;                                    //~v145R~
        ulen=((Plen1<<16)|(Plen1+Plen2));                          //~v145R~
//UTRACED("wrtcharstratt3",Pchstr,80);                             //~v145R~
//      rc=uvio_w95writecell(5,Prow,Pcol,ulen,Pchstr,attr);//parm is char and attr str//~v6EiR~
        rc=uvio_w95writecell(Popt,5,Prow,Pcol,ulen,Pchstr,attr);//parm is char and attr str//~v6EiR~
    }                                                              //~v145R~
    return rc;                                                     //~v145R~
}//uvio_w95wrtcharstratt3                                          //~v145R~
                                                                   //~v145R~
//*******************************************************          //~v307I~
//*uvio_w95resetconsole                                            //~v307I~
//*  for test redrau unavaile bug;reset console                    //~v307I~
//*return:rc                                                       //~v307I~
//*******************************************************          //~v307I~
void uvio_w95resetconsole(void)                                    //~v307I~
{                                                                  //~v307I~
//*********************************                                //~v307I~
//*reset console-->created another dosprompt frame!!               //~v307I~
//    if (!FreeConsole())                                          //~v307R~
//        uerrapi0("FreeConsole",GetLastError());                  //~v307R~
//    if (!AllocConsole())                                         //~v307R~
//        uerrapi0("AllocConsole",GetLastError());                 //~v307R~
//    Shconout=ugetstdhandle(STD_OUTPUT_HANDLE);                   //~v307R~
//    uvio2_init(Shconout);   //pass to uvio2                      //~v307R~
//    ukbd_w95init();                                              //~v307R~
//*pritf(x07);  caused redraw                                      //~v307I~
//    if (!SetConsoleActiveScreenBuffer(Shconout))                 //~v307R~
//        uerrapi0x("SetConsoleActiveScreenBuffer",GetLastError());//~v307R~
//    usetconsolemode(1,ENABLE_PROCESSED_OUTPUT);   //stdout console mode//~v307R~
//try another buffer                                               //~v307I~
//    CloseHandle(Shconout);                                       //~v307R~
//    Shconout=CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,//~v307R~
//                 FILE_SHARE_READ | FILE_SHARE_WRITE,             //~v307R~
//                 NULL,                                           //~v307R~
//                 CONSOLE_TEXTMODE_BUFFER,                        //~v307R~
//                 NULL);                                          //~v307R~
//    if (Shconout==INVALID_HANDLE_VALUE)                          //~v307R~
//        uerrapi0x("CreateConsoleScreenBuffer",GetLastError());   //~v307R~
//    if (!SetStdHandle(STD_OUTPUT_HANDLE,Shconout))               //~v307R~
//        uerrapi0x("SetStdHandle",GetLastError());                //~v307R~
//    if (SetConsoleActiveScreenBuffer(Shconout)==FALSE)           //~v307R~
//        uerrapi0x("SetActiveScreenBuffer",GetLastError());       //~v307R~
//    usetconsolemode(1,0);   //stdout console mode                //~v307R~
//    uvio2_init(Shconout);   //pass to uvio2                      //~v307R~
//try re-set buff inf                                              //~v307I~
//    int    ii;                                                   //~v307R~
//    int      rc16;                                               //~v307R~
//    CONSOLE_SCREEN_BUFFER_INFO csbi;                             //~v307R~
////*********************************                              //~v307R~
//    rc16=0;                                                      //~v307R~
//    GetConsoleScreenBufferInfo(Shconout,&csbi);                  //~v307R~
//    if (!SetConsoleScreenBufferSize(Shconout,csbi.dwSize))       //~v307R~
//        rc16=2;             //setconbuffi err                    //~v307R~
//    for (ii=0;ii<rc16;ii++)                                      //~v307R~
//        ubell();                                                 //~v307R~
//no buffering stdout                                              //~v307I~
//  setvbuf(stdout,NULL,_IONBF,0);                                 //~v307R~
//close and create new buff                                        //~v307I~
    return;                                                        //~v307I~
}//uvio_w95resetconsole                                            //~v307I~
#endif                                                             //~v142I~
#ifdef WXE                                                         //~v6EoR~
//************************************************************************//~v6EkI~
//*rc:0:no rep,1:rep done by altch                                 //~v6EkI~
//************************************************************************//~v6EkI~
int uvio_setcombinealtch(int Plineopt,int Ppos,int Plen)           //~v6EkI~
{                                                                  //~v6EkI~
	UCHAR *pc0,*pc,*pcd0,*pcd,wkdbcs[4],wkdata[4];                 //~v6EkR~
	WORD *pca0,*pca,attr,repattr;                                  //~v6EkR~
    int len,reslen,combinectr=0;                                   //~v6EkR~
//*********************************                                //~v6EkI~
	UTRACEP("%s:Plineopt=%04x,pos=%d\n",UTT,Plineopt,Ppos);        //~v6EkI~
    if (LIGATUREMODE(Plineopt))	//ligature line                    //~v6EkR~
    	return 0;                                                  //~v6EkI~
    if (COMBINEMODE(Plineopt))	//force or optional                //~v6EkI~
    	return 0;                                                  //~v6EkI~
	if (!Gutfcombaltch)                                            //~v6EkI~
    	return 0;                                                  //~v6EkI~
	if (UTF_UCS2DDSBCS((ULONG)Gutfcombaltch,wkdata,wkdbcs)>1)      //~v6EkR~
    	return 0;                                                  //~v6EkI~
    pc0=Sw95buffc+Ppos;                                            //~v6EkI~
    pca0=Sw95buffa+Ppos;                                           //~v6EkI~
    pcd0=Sdbcstbl+Ppos;                                            //~v6EkI~
    for (pc=pc0,pcd=pcd0,pca=pca0,reslen=Plen;reslen>0;pc++,pcd++,pca++,reslen--)//~v6EkI~
    {                                                              //~v6EkI~
    	len=umemspnc(pcd,0x00,reslen);                             //~v6EkI~
        pc+=len;                                                   //~v6EkI~
        pcd+=len;                                                  //~v6EkI~
        pca+=len;                                                  //~v6EkI~
        reslen-=len;                                               //~v6EkI~
        if (!UDBCSCHK_ISUCSWIDTH0(*pcd))	//combine char         //~v6EkI~
        {                                                          //~v6EkI~
        	combinectr=0;                                          //~v6EkI~
        	continue;                                              //~v6EkI~
        }                                                          //~v6EkI~
        attr=*pca;                                                 //~v6EkI~
	   	if (UTF_COMBINEMODE_NP())  //altch mode                    //~v6EkR~
        {                                                          //~v6EkI~
        	repattr=ATTR_COMBINENP_FG;                             //~v6EkI~
    	    *pc=wkdata[0];                                         //~v6EkI~
        	*pcd=wkdbcs[0];                                        //~v6EkI~
        }                                                          //~v6EkI~
        else	//split mode                                       //~v6EkR~
        {                                                          //~v6EkI~
        	if (combinectr++%2) //2nd                              //~v6EkI~
    	    	repattr=ATTR_COMBINE_FG2;                          //~v6EkI~
            else                //1st                              //~v6EkI~
    	    	repattr=ATTR_COMBINE_FG;                           //~v6EkI~
        }                                                          //~v6EkI~
        if (attr & 0xf0)    //bg specified                         //~v6EkR~
            *pca=(attr & 0xf0)|repattr;                            //~v6EkR~
        else                                                       //~v6EkR~
            *pca=repattr;                                          //~v6EkR~
    }                                                              //~v6EkI~
	UTRACED("buffmode Sw95buffc",pc0,Plen);                        //~v6EkI~
    UTRACED("buffmode Sw95buffa",pca0,Plen*(int)sizeof(Sw95buffa[0]));//~v6EkI~
    UTRACED("buffmode Sdbcstbl",pcd0,Plen);                        //~v6EkI~
    return 1;                                                      //~v6EkI~
}//uvio_setcombinealtch                                            //~v6EkI~
#endif	//WXE                                                      //~v6EoR~
#ifdef W32                                                         //~v7a6I~
//*****************************************************************//~v7a6I~
//*rc=1:VT mode,0 not VTmode, -1 err                               //~v7a6I~
//*****************************************************************//~v7a6I~
int isVTmode()                                                     //~v7a6I~
{                                                                  //~v7a6I~
	int rc=-1;                                                     //~v7a6R~
	DWORD mode=ugetconsolemode(1/*stdout*/);	                   //~v7a6I~
    if (mode!=0xffffffff)                                          //~v7a6I~
    {                                                              //~v7a6I~
    	rc=(mode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)!=0 ? 1 : 0; //~v7a6R~
    }                                                              //~v7a6I~
    UTRACEP("%s:rc=%d,mode=0x%04x\n",UTT,rc,mode);                 //~v7a6I~
    return rc;                                                     //~v7a6I~
}                                                                  //~v7a6I~
#endif //W32                                                       //~v7a6I~
#ifdef W32                                                         //~vbzMR~
#ifdef WINCON                                                      //~v7bmI~//~vbzMI~
//*************************************************************************//~vbzJI~
int uvioReadConsoleOutput(int Popt,int Prow,int Plen,PCHAR_INFO Ppchi,int *Ppreadctr)//~vbzJR~
{                                                                  //~vbzJI~
	COORD sz,pos;                                                  //~vbzJI~
    SMALL_RECT rect;                                               //~vbzJI~
	sz.X/*col*/=(SHORT)Plen; sz.Y/*row*/=1;	//read buffsz          //~vbzJR~
	pos.X/*col*/=0; pos.Y/*row*/=0;      //pos in read buff        //~vbzJR~
	rect.Left=0; rect.Top=(SHORT)Prow; rect.Right=(SHORT)Plen-1; rect.Bottom=(SHORT)Prow;   //rect in screen buffer//~vbzJR~
    int rc=ReadConsoleOutputW(Shconout,Ppchi,sz,pos,&rect);        //~vbzJR~
    *Ppreadctr=rect.Right+1;                                       //~vbzJI~
    rc=(rc!=0 ? 0 : 4);                                            //~vbzJI~
    UTRACEP("%s:rc=%d(0:OK),readctr=%d,rect l=%d,t=%d,r=%d,b=%d,lasterr=%d\n",UTT,rc,*Ppreadctr,rect.Left,rect.Top,rect.Right,rect.Bottom,GetLastError());//~vbzJR~
    UTRACED("read chi",Ppchi,Plen*sizeof(CHAR_INFO));              //~vbzJR~
    return rc;                                                     //~vbzJI~
}                                                                  //~vbzJI~
#endif //WINCON                                                    //~vbzMI~
#ifdef CCC                                                         //~v7bmI~
//*************************************************************************//~vbzJI~
//*rc=0:OK ;4:readconsole err, -1 :end of line                     //~vbzJR~
//*************************************************************************//~vbzJI~
int uvioGetCellData(int Popt,int Prow,UWCHART *Ppucs,int *Ppucsctr)//~vbzJR~
{                                                                  //~vbzJI~
	int rc,maxrow,ii,ucsctr=0,maskdbcs1;                           //~vbzJR~
    int pos;                                                       //~vbzJI~
	CHAR_INFO *pchi,wkchi[UVIOM_MAXCOL];                           //~vbzJR~
    UWCHART *pucs,ucs;                                             //~vbzJR~
    UWCHART *pucsL;                                                //~vbzJR~
    WORD attr;                                                     //~vbzJI~
    UCHAR *pdata,*pdbcs;                                           //~vbzJI~
    UWUCS ucs4;                                                    //~vbzJI~
    int utf16ctr,chsz,swddfmt,readucsctr;                          //~vbzJR~
    UWCHART wkutf16[2];                                            //~vbzJI~
//************************                                         //~vbzJI~
    maxrow=Sscrsize/Sscrwidth;                                     //~vbzJI~
	UTRACEP("%s:opt=%02x,row=%d,maxrow=%d,scrWidth=%d\n",UTT,Popt,Prow,maxrow,Sscrwidth);//~vbzJR~
    if (Prow>=maxrow)                                              //~vbzJR~
    {                                                              //~vbzJI~
		UTRACEP("%s:end of row maxrow=%d\n",UTT,maxrow);           //~vbzJR~
    	return -1;                                                 //~vbzJI~
    }                                                              //~vbzJI~
    pos=Prow*Sscrwidth;                                            //~vbzJI~
    pdata=Sw95buffc+pos;		//screen char buffer               //~vbzJI~
    pdbcs=Sdbcstbl+pos;		//screen char buffer                   //~vbzJI~
    UTRACED("data",pdata,Sscrwidth);                               //~vbzJI~
    UTRACED("dbcs",pdbcs,Sscrwidth);                               //~vbzJI~
    maskdbcs1=UVIOMATTR_DBCS1<<8;                                  //~vbzJR~
	swddfmt=utfchkdd(0,pdbcs,Sscrwidth);                           //~vbzJI~
  if (swddfmt)                                                     //~vbzJI~
    rc=uvioReadConsoleOutput(Popt,Prow,Sscrwidth,wkchi,&readucsctr);//~vbzJM~
  else                                                             //~vbzJI~
  	rc=0;                                                          //~vbzJI~
    if (rc==0)	//read ok                                          //~vbzJR~
    {                                                              //~vbzJI~
        if (swddfmt)                                               //~vbzJI~
        {                                                          //~vbzJI~
            for (ii=0,pchi=wkchi,pucs=Ppucs;ii<Sscrwidth;ii++,pchi++,pdata++,pdbcs++)//~vbzJR~
            {                                                      //~vbzJR~
                ucs=pchi->Char.UnicodeChar;                        //~vbzJR~
                attr=pchi->Attributes;                             //~vbzJR~
                UTRACEP("%s:ii=%d,ucs2=%04x,attr=0x%04x,dbcsid=%c,pucs=0x%04x\n",UTT,ii,ucs,attr,*pdbcs,*pucs);//~vbzJR~
                if (!*pdbcs || ucs<0x80)     //ascii or errrep     //~vbzJR~
                {                                                  //~vbzJR~
                    *pucs++=ucs;                                   //~vbzJR~
                }                                                  //~vbzJR~
                else                                               //~vbzJR~
                {                                                  //~vbzJR~
                    int sw2cell=0;                                 //~vbzJR~
                    int reslen=Sscrwidth-ii;                       //~vbzJR~
                    ucs4=utfdd2u1chsz(0,pdata,pdbcs,reslen,&chsz); //~vbzJR~
		        	if (ucs4==DBCSSPACE_ALT2   //ffff                         //~v6G0R~//~vbzJI~
        			&&  *pdbcs==UDBCSCHK_DBCS1STUCS)    //tabdisplay set ffff/() for dbcsspace//~v6G0R~//~vbzJI~
                	{                                              //~vbzJI~
                    	*pucs++=ucs;                               //~vbzJI~
                    	*pucs++=ucs;                               //~vbzJI~
                        sw2cell=1;                                 //~vbzJI~
                        UTRACEP("%s:ucs=0x%04x,ucs4=%04x dbcs space altch\n",UTT,ucs,ucs4);//~vbzJR~
                	}                                              //~vbzJI~
                    else                                           //~vbzJI~
                    if (UTF_ISUCS4(ucs4) && chsz>0)                //~vbzJR~
                    {                                              //~vbzJR~
                        UCS4_TO_UTF16(ucs4,wkutf16,&utf16ctr);     //~vbzJR~
                        *pucs++=wkutf16[0];                        //~vbzJR~
                        *pucs++=wkutf16[1];                        //~vbzJR~
                        UTRACEP("%s:ucs=%04x,ucs4=0x%06x(0x%04x:%04x),attr=0x%04x,chsz=%d\n",UTT,ucs,ucs4,wkutf16[0],wkutf16[1],attr,chsz);//~vbzJR~
                        if (chsz==2)                               //~vbzJR~
                        {                                          //~vbzJR~
                            sw2cell=1;                             //~vbzJR~
                            UTRACEP("%s:ucs=%04x skip next by ucs4 chsz=2,ucs4=0x%06x\n",UTT,ucs,ucs4);//~vbzJR~
                        }                                          //~vbzJR~
                    }                                              //~vbzJR~
                    else //ucs2                                    //~vbzJR~
                    {                                              //~vbzJR~
                        *pucs++=ucs;                               //~vbzJR~
                        if (chsz==2)                               //~vbzJR~
                        {                                          //~vbzJR~
                            sw2cell=1;                             //~vbzJR~
                            UTRACEP("%s:ucs=%04x skip next by ucs2 chsz=2\n",UTT,ucs);//~vbzJR~
                        }                                          //~vbzJR~
                        else                                       //~vbzJR~
                        if (attr & maskdbcs1)   //dbcs2nd          //~vbzJR~
                        {                                          //~vbzJR~
                            sw2cell=1;                             //~vbzJR~
                            UTRACEP("%s:ucs=%04x skip next by ucs2 dbcs\n",UTT,ucs);//~vbzJR~
                        }                                          //~vbzJR~
                    }//ucs2                                        //~vbzJR~
                    if (sw2cell)                                   //~vbzJR~
                    {                                              //~vbzJR~
                        pdata++; pdbcs++;                          //~vbzJR~
                        ii++;                                      //~vbzJR~
                        pchi++;                                    //~vbzJR~
                    }                                              //~vbzJR~
                }                                                  //~vbzJR~
            }//for                                                 //~vbzJR~
        }                                                          //~vbzJI~
        else	//locale file                                      //~vbzJI~
        {                                                          //~vbzJI~
        	pucsL=SucsLocalefile+Prow*Sscrwidth;	//save ucs for localefile//~vbzJR~
    		UTRACED("ucsLocal",pucsL,Sscrwidth*sizeof(UWCHART));   //~vbzJI~
#ifdef AAA                                                         //~vbzJI~
            int dbcssz;                                            //~vbzJI~
            for (ii=0,pchi=wkchi,pucs=Ppucs;ii<readucsctr;ii++,pchi++,pucs++,pucsL++,pdbcs++)//~vbzJR~
            {                                                      //~vbzJI~
                ucs=pchi->Char.UnicodeChar;                        //~vbzJI~
                attr=pchi->Attributes;                             //~vbzJI~
                ucsL=*pucsL;                                       //~vbzJI~
                int reslen=Sscrwidth-ii;                           //~vbzJI~
          		if (*pdbcs==UDBCSCHK_DBCS1ST)                          //~v6DdI~//~vbzJI~
					dbcssz=UDBCSCHK_PCD_MBCHSZ(pdbcs,reslen);//~v6DdI~//~vbzJI~
                else                                               //~vbzJI~
                	dbcssz=1;                                      //~vbzJI~
                UTRACEP("%s:ii=%d,ucs2=%04x,ucsL=0x%04x,attr=0x%04x,dbcs=0x%02x,dbcssz=%d\n",UTT,ii,ucs,ucsL,attr,*pdbcs,dbcssz);//~vbzJR~
                if (ucsL)                                          //~vbzJI~
                	*pucs=ucsL;                                    //~vbzJR~
                else                                               //~vbzJI~
                	*pucs=ucs;                                     //~vbzJR~
                if (attr & maskdbcs1)   //dbcs2nd                  //~vbzJI~
                {	                                               //~vbzJI~
                	ii++;                                          //~vbzJI~
                    pchi++;                                        //~vbzJI~
                    pdbcs++;                                       //~vbzJI~
                	UTRACEP("%s:mask dbcs1st skip ii=%d,dbcsid=0x%02x\n",UTT,ii,*pdbcs);//~vbzJI~
                }                                                  //~vbzJI~
                else                                               //~vbzJI~
                if (dbcssz>1)  //                                  //~vbzJI~
                {                                                  //~vbzJI~
                    int skip=dbcssz-1;                             //~vbzJI~
                    ii+=skip;                                      //~vbzJI~
                	pchi+=skip;                                    //~vbzJI~
                    pdbcs+=skip;                                   //~vbzJR~
                    pucsL+=skip;                                   //~vbzJI~
                	UTRACEP("%s:dbcsid dbcs1st skip ii=%d,skip=%d,dbcsid=0x%02x,*pucsL=0x%04x\n",UTT,ii,skip,*pdbcs,*pucsL);//~vbzJR~
                }                                                  //~vbzJI~
            }//for                                                 //~vbzJI~
#else //!AAA                                                       //~vbzJI~
			PLOCALE_LINE_INFO pli=SucsLocaleLineInfo+Prow;         //~vbzJR~
    		ucsctr=pli->LLIucsctrL;                                //~vbzJR~
            UTRACEP("%s:locale file line ucsctr=%d,row=%d\n",UTT,ucsctr,Prow);//~vbzJI~
            memcpy(Ppucs,pucsL,ucsctr*sizeof(UWCHART));            //~vbzJR~
            pucs=Ppucs+ucsctr;                                     //~vbzJI~
#endif                                                             //~vbzJI~
        }                                                          //~vbzJI~
        ucsctr=PTRDIFF(pucs,Ppucs)/sizeof(ucs);                    //~vbzJR~
    }                                                              //~vbzJI~
    else                                                           //~vbzJI~
    {                                                              //~vbzJI~
    	memset(Ppucs,0,Sscrwidth*sizeof(UWCHART));                 //~vbzJI~
        rc=4;                                                      //~vbzJI~
    }                                                              //~vbzJI~
    *Ppucsctr=ucsctr;                                              //~vbzJI~
	UTRACEP("%s:rc=%d,ucsctr=%d,swddfmt=%d\n",UTT,rc,ucsctr,swddfmt);//~vbzJR~
	UTRACED("out ucs",Ppucs,Sscrwidth*sizeof(UWCHART));            //~vbzJR~
    return rc;                                                     //~vbzJI~
}//uvioGetCellData                                                 //~vbzJI~
#endif                                                             //~v7bmI~
#ifdef CCC                                                         //~v7bmI~
//*******************************************************          //~vbzJI~
void uvioSetBufferWrite(int Popt,int Prow,int Pcol,int Plen)       //~vbzJR~
{                                                                  //~vbzJI~
	PLOCALE_LINE_INFO pli=SucsLocaleLineInfo+Prow;                 //~vbzJI~
	UTRACEP("%s:opt=%d,row=%d,col=%d,Plen=%d\n",UTT,Popt,Prow,Pcol,Plen);//~vbzJI~
    pli->LLIstartW=Pcol;                                           //~vbzJR~
    pli->LLIddctrW=Plen;                                           //~vbzJI~
	UTRACEP("%s:startW=%d,lenW=%d,startL=%d,ucsctrL=%d\n",UTT,pli->LLIstartW,pli->LLIddctrW,pli->LLIstartL,pli->LLIucsctrL);//~vbzJI~
}                                                                  //~vbzJI~
//*******************************************************          //~vbzJI~
//*from uviom                                                      //~vbzJI~
//*******************************************************          //~vbzJI~
int uvioSaveCellDataLocalefileW(int Popt,WUCS *Ppucs,int Pucsctr,int Prow,int Pcol)//~vbzJR~
{                                                                  //~vbzJI~
	PLOCALE_LINE_INFO pli=SucsLocaleLineInfo+Prow;                 //~vbzJR~
    int pos=pli->LLIucsctrL;                                       //~vbzJR~
	UTRACEP("%s:opt=%d,row=%d,col=%d,Pucsctr=%d,pos=%d\n",UTT,Popt,Prow,Pcol,Pucsctr,pos);//~vbzJR~
	UTRACED("input pucs",Ppucs,Pucsctr*sizeof(WUCS));              //~vbzJI~
    WUCS *pucs=SucsLocalefile+Prow*Sscrwidth+pos;                  //~vbzJR~
	if (Popt & UVIOSCDLO_CLEAR)                                    //~vbzJI~
    {                                                              //~vbzJI~
	    pli->LLIstartL=Pcol;                                       //~vbzJR~
	    pli->LLIucsctrL=0;                                         //~vbzJI~
    }                                                              //~vbzJI~
    else                                                           //~vbzJI~
    {                                                              //~vbzJI~
#ifdef BBB   //adjusted padding ctr at uviom for width=0           //~vbzJI~
        if (Pcol<pos)   //padding the ucs for combining(width=0)   //~vbzJI~
        {                                                          //~vbzJI~
        	UINT ulen=pos-Pcol;                                    //~vbzJR~
            UTRACED("insert old",SucsLocalefile+Prow*Sscrwidth,pos*sizeof(WUCS));//~vbzJI~
            memmove(pucs-ulen+Pucsctr,pucs-ulen,ulen*sizeof(WUCS));//~vbzJR~
	    	memcpy(pucs-ulen,Ppucs,Pucsctr*sizeof(WUCS));          //~vbzJI~
	    	pli->LLIucsctrL+=Pucsctr;                              //~vbzJR~
            UTRACED("insert new",SucsLocalefile+Prow*Sscrwidth,pli->LLIucsctrL*sizeof(WUCS));//~vbzJR~
        }                                                          //~vbzJI~
        else                                                       //~vbzJI~
#endif                                                             //~vbzJI~
        {                                                          //~vbzJI~
	    	memcpy(pucs,Ppucs,Pucsctr*sizeof(WUCS));               //~vbzJR~
	    	pli->LLIucsctrL+=Pucsctr;                              //~vbzJR~
        }                                                          //~vbzJI~
    }                                                              //~vbzJI~
	UTRACEP("%s:new row=%d,startL=%d,ucsctrL=%d,startW=%d,ddctrW=%d\n",UTT,Prow,pli->LLIstartL,pli->LLIucsctrL,pli->LLIstartW,pli->LLIddctrW);//~vbzJR~
    return 0;                                                      //~vbzJI~
}                                                                  //~vbzJI~
#endif                                                             //~v7bmI~
#ifdef AAA                                                         //~vbzJI~
//*******************************************************          //~vbzJI~
int uvioSaveCellDataLocalefile(int Popt,UCHAR *Ppdata,int Plen,int Prow,int Pcol)//~vbzJI~
{                                                                  //~vbzJI~
	UCHAR *pc=Ppdata;                                              //~vbzJI~
	UTRACEP("%s:opt=%d,row=%d,col=%d,Plen=%d\n",UTT,Popt,Prow,Pcol,Plen);//~vbzJI~
	UTRACED("input pdata",Ppdata,Plen);                            //~vbzJR~
    WUCS *pucs=SucsLocalefile+Prow*Sscrwidth+Pcol;                 //~vbzJI~
    for (int ii=0;ii<Plen;ii++)                                    //~vbzJI~
	    *pucs++=(WUCS)(*pc++);                                     //~vbzJI~
    return 0;                                                      //~vbzJI~
}                                                                  //~vbzJI~
#endif                                                             //~vbzJI~
//#ifdef DDD                                                       //~v7bnR~
#ifdef WINCON   //wxe save to buffer for errmsg                    //~vbzMR~
//*************************************************************************//~v7bnI~
//*for utf8 uerrmsg                                                //~v7bnI~
//*************************************************************************//~v7bnI~
int uvioSaveCellDataDD(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pucsctr,int Prow,int Pcol)//~v7bnR~
{                                                                  //~v7bnI~
	UTRACEP("%s:opt=%02x,row=%d,col=%d,len=%d,ucsctr=%d\n",UTT,Popt,Prow,Pcol,Plen,Pucsctr);//~v7bnI~
	UTRACED("data",Ppdata,Plen);                                   //~v7bnR~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~v7bnR~
	UTRACED("ucs",Ppucs,Pucsctr*sizeof(WUCS));                     //~v7bnR~
    int pos=Prow*Sscrwidth+Pcol;                                   //~v7bnR~
    UCHAR *pdata=Sw95buffc+pos;		//screen char buffer           //~v7bnI~
    UCHAR *pdbcs=Sdbcstbl+pos;		//screen char buffer           //~v7bnI~
	UTRACED("data old",pdata,Plen);                                //~v7bnI~
	UTRACED("dbcs old",pdbcs,Plen);                                //~v7bnI~
    memcpy(pdata,Ppdata,(UINT)Plen);                               //~v7bnR~
    memcpy(pdbcs,Ppdbcs,(UINT)Plen);                               //~v7bnR~
    return 0;                                                      //~v7bnI~
}                                                                  //~v7bnI~
#endif //WINCON                                                    //~vbzMR~
#ifdef WINCON   //wxe save to buffer for errmsg                    //~vbzMI~
//*************************************************************************//~v7bmI~
//*rc=0:OK ;4:readconsole err, -1 :end of line                     //~v7bmI~
//*************************************************************************//~v7bmI~
int uvioGetCellData(int Popt,int Prow,UWCHART *Ppucs,int *Ppucsctr)//~v7bmI~
{                                                                  //~v7bmI~
	int rc,maxrow,ii,jj,ucsctr=0,maskdbcs1,pos;                    //~v7bmR~
	CHAR_INFO *pchi,*pchi2,wkchi[UVIOM_MAXCOL];                    //~v7bmR~
    UWCHART *pucs,ucs;                                             //~v7bmI~
    WORD attr;                                                     //~v7bmI~
    UCHAR *pdata,*pdbcs;                                           //~v7bmI~
    UWUCS ucs4;                                                    //~v7bmI~
    int utf16ctr,chsz,readucsctr,wwGlyph,ctrskip,swMbUnp;          //~v7bmR~
    UCHAR dbcsid,altchid;                                          //~v7bmR~
    UWCHART wkutf16[2];                                            //~v7bmI~
//************************                                         //~v7bmI~
    maxrow=Sscrsize/Sscrwidth;                                     //~v7bmI~
    altchid=DEFAULT_ALTCH;                                         //~v7bmI~
	UTRACEP("%s:opt=%02x,Stoplineoffs=%d,row=%d,maxrow=%d,scrWidth=%d,dbcsspacealt=%02x\n",UTT,Popt,Stoplineoffs,Prow,maxrow,Sscrwidth);//~v7eeR~
    if (Prow>=maxrow)                                              //~v7bmI~
    {                                                              //~v7bmI~
		UTRACEP("%s:end of row maxrow=%d\n",UTT,maxrow);           //~v7bmI~
    	return -1;                                                 //~v7bmI~
    }                                                              //~v7bmI~
    pos=Prow*Sscrwidth;                                            //~v7bmI~
    pdata=Sw95buffc+pos;		//screen char buffer               //~v7bmI~
    pdbcs=Sdbcstbl+pos;		//screen char buffer                   //~v7bmI~
    UTRACED("data",pdata,Sscrwidth);                               //~v7bmI~
    UTRACED("dbcs",pdbcs,Sscrwidth);                               //~v7bmI~
    maskdbcs1=UVIOMATTR_DBCS1<<8;                                  //~v7bmI~
//  rc=uvioReadConsoleOutput(Popt,Prow,Sscrwidth,wkchi,&readucsctr);//~v7eeR~
    int tgtline=Prow+Stoplineoffs;                                 //~v7eeI~
    rc=uvioReadConsoleOutput(Popt,tgtline,Sscrwidth,wkchi,&readucsctr);//~v7eeI~
    if (rc!=0)	//read faled                                       //~v7bmR~
    {                                                              //~v7bmM~
    	memset(Ppucs,0,Sscrwidth*sizeof(UWCHART));                 //~v7bmM~
		UTRACEP("%s:return 4 by readconsole err\n");               //~v7bmI~
        return 4;                                                  //~v7bmI~
    }                                                              //~v7bmM~
    for (ii=0,pchi=wkchi,pucs=Ppucs;ii<Sscrwidth;ii++,pchi++,pdata++,pdbcs++)//~v7bmR~
    {                                                              //~v7bmR~
        ucs=pchi->Char.UnicodeChar;                                //~v7bmR~
        attr=pchi->Attributes;                                     //~v7bmR~
        dbcsid=*pdbcs;                                             //~v7bmI~
        UTRACEP("%s:ii=%d,ucs2=%04x,attr=0x%04x,data=0x%02x,dbcsid=%02x\n",UTT,ii,ucs,attr,*pdata,dbcsid);//~v7bmR~
        if (ucs<0x80 || !dbcsid || dbcsid==DEFAULT_UNPATTR) //'l' for x1b etc//~v7bmR~
        {                                                          //~v7bmI~
            *pucs++=ucs;                                           //~v7bmI~
            continue;                                              //~v7bmI~
        }                                                          //~v7bmI~
        if (*pdata==DEFAULT_ALTCH)     //altch 0xff                //~v7bmR~
        {                                                          //~v7bmI~
			if (dbcsid==UDBCSCHK_TABCHAR || dbcsid==UDBCSCHK_TABPADCHAR//~v7bmR~
			||  dbcsid==UDBCSCHK_DBCS1ST || dbcsid==UDBCSCHK_DBCS2ND//~v7bmI~
//  		||  dbcsid==UDBCSCHK_DBCS1STUCS || dbcsid==UDBCSCHK_DBCS2NDUCS //FF12 is DBCS "2"//~v7d1R~
        	)                                                      //~v7bmR~
            {                                                      //~v7bmR~
                *pucs++=ucs;                                       //~v7bmR~
                continue;                                          //~v7bmR~
            }                                                      //~v7bmR~
        }                                                          //~v7bmI~
        int reslen=Sscrwidth-ii;                                   //~v7bmI~
        chsz=1;                                                    //~v7bmI~
        swMbUnp=0;	//ucs was changed to unprintable               //~v7bmI~
        if (dbcsid==UDBCSCHK_DBCS1ST)  //locale data               //~v7bmI~
        {                                                          //~v7bmI~
            for (jj=1;jj<reslen;jj++)                              //~v7bmI~
            {                                                      //~v7bmI~
                chsz++;                                            //~v7bmI~
                if (*(pdbcs+jj)==UDBCSCHK_DBCS2ND)                 //~v7bmI~
                    break;                                         //~v7bmI~
            }                                                      //~v7bmI~
    	    UTRACEP("%s:locale chsz ucs=%04x,chsz=%d,dbcsid=0x%02x\n",UTT,ucs,chsz,dbcsid);//~v7bmI~
            int readlen;                                           //~v7bmI~
            int rc2=udbcschk_mb2ucs1(0,pdata,chsz,&readlen,&ucs4); //~v7bmI~
            if (rc2>1)  //1:dbcs 0:sbcs or non-spacing             //~v7bmI~
                ucs4=ucs;                                          //~v7bmI~
            else                                                   //~v7bmI~
            	swMbUnp=(UWUCS)ucs!=ucs4;                          //~v7bmI~
	        UTRACEP("%s:mb2ucs swMbUnp=%d ucs=%04x,ucs4=0x%06x,chsz=%d,dbcsid=0x%02x\n",UTT,swMbUnp,ucs,ucs4,chsz,dbcsid);//~v7bmI~
        }                                                          //~v7bmI~
        else                                                       //~v7bmI~
        {                                                          //~v7bmI~
            ucs4=utfdd2u1chsz(0,pdata,pdbcs,reslen,&chsz);         //~v7bmI~
            swMbUnp=(UWUCS)ucs!=ucs4;                              //~v7bmI~
	        UTRACEP("%s:ddfmt chsz ucs=%04x,ucs4=0x%06x,chsz=%d,swMbUnp=%d,dbcsid=0x%02x\n",UTT,ucs,ucs4,chsz,swMbUnp,dbcsid);//~v7bmR~
        }                                                          //~v7bmI~
        if (attr & maskdbcs1 && !swMbUnp)   //dbcs2nd              //~v7bmR~
        {                                                          //~v7bmI~
        	*pucs++=ucs;                                           //~v7bmI~
        	int padctr=chsz-2;                                     //~v7bmI~
            UTRACEP("%s:attr dbcs1 ucs=%04x,chsz=%d,padctr=%d\n",UTT,ucs,chsz,padctr);//~v7bmI~
            pchi2=pchi+2;                                          //~v7bmI~
            for (jj=0;jj<padctr;jj++)                              //~v7bmI~
            {                                                      //~v7bmI~
                UTRACEP("%s:attr:dbcs1 copy padding jj=%d ucs=%04x\n",UTT,jj,pchi2->Char.UnicodeChar);//~v7bmR~
                *pucs++=(pchi2++)->Char.UnicodeChar;               //~v7bmI~
            }                                                      //~v7bmI~
            ctrskip=chsz-1;                                        //~v7bmI~
            ii+=ctrskip;                                           //~v7bmI~
            pdata+=ctrskip;                                        //~v7bmI~
            pdbcs+=ctrskip;                                        //~v7bmI~
            pchi+=ctrskip;                                         //~v7bmI~
            continue;                                              //~v7bmI~
        }                                                          //~v7bmI~
        int sw2cell=0;                                             //~v7bmM~
        if (dbcsid==UDBCSCHK_DBCS1ST)  //locale data               //~v7bmR~
        {                                                          //~v7bmR~
            if (UTF_ISUCS4(ucs4))                                  //~v7bmR~
            {                                                      //~v7bmR~
                UCS4_TO_UTF16(ucs4,wkutf16,&utf16ctr);             //~v7bmR~
                UTRACEP("%s:DBCS1ST ucs4(0x%06x)->utf16 %04x:%04x\n",UTT,ucs4,wkutf16[0],wkutf16[1]);//~v7bmR~
                *pucs++=wkutf16[0];                                //~v7bmR~
                *pucs++=wkutf16[1];                                //~v7bmR~
            }                                                      //~v7bmR~
            else                                                   //~v7bmR~
                *pucs++=(WUCS)ucs4;                                //~v7bmR~
            wwGlyph=uvioGetCursorWidth(0,ucs4);                    //~v7bmR~
            int padctr=chsz-wwGlyph;                               //~v7bmR~
            UTRACEP("%s:DBCS1ST ucs=%04x,chsz=%d,wwGlyph=%d,padctr=%d,swMbUnp=%d\n",UTT,ucs,chsz,wwGlyph,padctr,swMbUnp);//~v7bmR~
            pchi2=pchi+1+swMbUnp;                                  //~v7bmI~
            for (jj=0;jj<padctr;jj++)                              //~v7bmR~
            {                                                      //~v7bmR~
                UTRACEP("%s:copy padding jj=%d ucs=%04x\n",UTT,jj,(pchi+1)->Char.UnicodeChar);//~v7bmR~
                *pucs++=(pchi2++)->Char.UnicodeChar;               //~v7bmR~
            }                                                      //~v7bmR~
            ii+=padctr;                                            //~v7bmI~
            pdata+=padctr;                                         //~v7bmR~
            pdbcs+=padctr;                                         //~v7bmR~
            pchi+=padctr;                                          //~v7bmI~
            sw2cell=swMbUnp;    //add 1 more if ucs is dbcs1st and dbcs2nd//~v7bmR~
        }                                                          //~v7bmR~
        else    //ddfmt                                            //~v7bmR~
        {                                                          //~v7bmR~
            if (UTF_ISUCS4(ucs4) && chsz>0)                        //~v7bmR~
            {                                                      //~v7bmR~
                UCS4_TO_UTF16(ucs4,wkutf16,&utf16ctr);             //~v7bmR~
                *pucs++=wkutf16[0];                                //~v7bmR~
                *pucs++=wkutf16[1];                                //~v7bmR~
                UTRACEP("%s:ucs=%04x,ucs4=0x%06x(0x%04x:%04x),attr=0x%04x,chsz=%d\n",UTT,ucs,ucs4,wkutf16[0],wkutf16[1],attr,chsz);//~v7bmR~
                if (chsz==2)                                       //~v7bmR~
                {                                                  //~v7bmR~
                    sw2cell=1;                                     //~v7bmR~
                    UTRACEP("%s:ucs=%04x skip next by ucs4 chsz=2,ucs4=0x%06x\n",UTT,ucs,ucs4);//~v7bmR~
                }                                                  //~v7bmR~
            }                                                      //~v7bmR~
            else //ucs2                                            //~v7bmR~
            {                                                      //~v7bmR~
                *pucs++=(UWCHART)ucs4;                             //~v7bmR~
                if (chsz==2)                                       //~v7bmR~
                {                                                  //~v7bmR~
                    sw2cell=1;                                     //~v7bmR~
                    UTRACEP("%s:ucs=%04x skip next by ucs2 chsz=2\n",UTT,ucs);//~v7bmR~
                }                                                  //~v7bmR~
            }//ucs2                                                //~v7bmR~
        }//ddfmt                                                   //~v7bmR~
        if (sw2cell)                                               //~v7bmI~
        {                                                          //~v7bmI~
            pdata++; pdbcs++;                                      //~v7bmI~
            ii++;                                                  //~v7bmI~
            pchi++;                                                //~v7bmI~
        }                                                          //~v7bmI~
    }//for                                                         //~v7bmR~
    ucsctr=PTRDIFF(pucs,Ppucs)/sizeof(ucs);                        //~v7bmR~
    *Ppucsctr=ucsctr;                                              //~v7bmI~
	UTRACEP("%s:return 0,usctr=%d\n",UTT,ucsctr);                  //~v7bmR~
	UTRACED("out ucs",Ppucs,Sscrwidth*sizeof(UWCHART));            //~v7bmI~
    return 0;                                                      //~v7bmR~
}//uvioGetCellData                                                 //~v7bmI~
#endif      //WINCON                                             //~v7bnR~//~vbzMR~
#ifdef DDD                                                         //~v7bnI~
//*************************************************************************//~v7bnI~
//*rc=0:OK ;4:readconsole err, -1 :end of line                     //~v7bnI~
//*************************************************************************//~v7bnI~
int uvioGetCellData(int Popt,int Prow,UWCHART *Ppucs,int *Ppucsctr)//~v7bnI~
{                                                                  //~v7bnI~
#define UNPUCS 0xfffd                                              //~v7bnI~
	int rc,maxrow,ii,jj,maskdbcs1,pos;                             //~v7bnR~
	CHAR_INFO *pchi,*pchi2,wkchi[UVIOM_MAXCOL];                    //~v7bnI~
    UWCHART *pucs,ucs;                                             //~v7bnI~
    WORD attr;                                                     //~v7bnI~
    UCHAR *pdata,*pdbcs,*pdtata,*pdbcs0;                           //~v7bnR~
    UWUCS ucs4;                                                    //~v7bnI~
    int utf16ctr,chsz,readucsctr,ucsctrOut=0;                      //~v7bnR~
    UCHAR dbcsid,altchid;                                          //~v7bnI~
    UWCHART wkutf16[2];                                            //~v7bnI~
//************************                                         //~v7bnI~
    maxrow=Sscrsize/Sscrwidth;                                     //~v7bnI~
    altchid=DEFAULT_ALTCH;                                         //~v7bnI~
	UTRACEP("%s:opt=%02x,row=%d,maxrow=%d,scrWidth=%d\n",UTT,Popt,Prow,maxrow,Sscrwidth);//~v7bnI~//~vbzMR~
    if (Prow>=maxrow)                                              //~v7bnI~
    {                                                              //~v7bnI~
		UTRACEP("%s:end of row maxrow=%d\n",UTT,maxrow);           //~v7bnI~
    	return -1;                                                 //~v7bnI~
    }                                                              //~v7bnI~
    pos=Prow*Sscrwidth;                                            //~v7bnI~
    pdata0=Sw95buffc+pos;		//screen char buffer               //~v7bnR~
    pdbcs0=Sdbcstbl+pos;		//screen char buffer               //~v7bnR~
    UTRACED("data",pdata,Sscrwidth);                               //~v7bnI~
    UTRACED("dbcs",pdbcs,Sscrwidth);                               //~v7bnI~
    maskdbcs1=UVIOMATTR_DBCS1<<8;                                  //~v7bnI~
    rc=uvioReadConsoleOutput(Popt,Prow,Sscrwidth,wkchi,&readucsctr);//~v7bnI~
    if (rc!=0)	//read faled                                       //~v7bnI~
    {                                                              //~v7bnI~
    	memset(Ppucs,0,Sscrwidth*sizeof(UWCHART));                 //~v7bnI~
		UTRACEP("%s:return 4 by readconsole err\n");               //~v7bnI~
        return 4;                                                  //~v7bnI~
    }                                                              //~v7bnI~
    for (ii=0,pchi=wkchi,pucs=Ppucs;ii<Sscrwidth;ii++,pchi++)      //~v7bnI~
    {                                                              //~v7bnI~
        *pucs++=pchi->Char.UnicodeChar;                            //~v7bnI~
    }                                                              //~v7bnI~
    for (ii=0,pchi=wkchi,pucs=Ppucs;ii<readucsctr;ii++,pchi++)     //~v7bnI~
    {                                                              //~v7bnI~
        ucs=pchi->Char.UnicodeChar;                                //~v7bnI~
        attr=pchi->Attributes;                                     //~v7bnI~
        UTRACEP("%s:ii=%d,ucs2=%04x,attr=0x%04x\n",UTT,ii,ucs,attr);//~v7bnI~
        if (ucs!=UNPUCS)                                           //~v7bnI~
            continue;                                              //~v7bnI~
        pdata=pdata0+ii;                                           //~v7bnI~
        pdbcs=pdbcs0+ii;                                           //~v7bnI~
        int reslen=Sscrwidth-ii;                                   //~v7bnI~
        if (dbcsid==UDBCSCHK_DBCS1ST)  //locale data               //~v7bnI~
        {                                                          //~v7bnI~
            for (jj=1;jj<reslen;jj++)                              //~v7bnI~
            {                                                      //~v7bnI~
                chsz++;                                            //~v7bnI~
                if (*(pdbcs+jj)==UDBCSCHK_DBCS2ND)                 //~v7bnI~
                    break;                                         //~v7bnI~
            }                                                      //~v7bnI~
    	    UTRACEP("%s:locale chsz ucs=%04x,chsz=%d,data=0x%02x,dbcs=0x%02x\n",UTT,ucs,chsz,*pdata,*pdbcs);//~v7bnI~
            int rc2=udbcschk_mb2ucs1(0,pdata,chsz,&readlen,&ucs4); //~v7bnI~
            if (rc2>1)  //1:dbcs 0:sbcs or non-spacing             //~v7bnI~
                ucs4=ucs;                                          //~v7bnI~
    	    UTRACEP("%s:locale ucs2=%04x,ucs4=0x%06x,chsz=%d\n",UTT,ucs,ucs4,chsz);//~v7bnI~
            if (UTF_ISUCS4(ucs4))                                  //~v7bnI~
            {                                                      //~v7bnI~
                UCS4_TO_UTF16(ucs4,wkutf16,&utf16ctr);             //~v7bnI~
                UTRACEP("%s:DBCS1ST ucs4(0x%06x)->utf16 %04x:%04x\n",UTT,ucs4,wkutf16[0],wkutf16[1]);//~v7bnI~
                *pucs++=wkutf16[0];                                //~v7bnI~
                *pucs++=wkutf16[1];                                //~v7bnI~
            }                                                      //~v7bnI~
        }                                                          //~v7bnI~
        else                                                       //~v7bnI~
        {                                                          //~v7bnI~
            ucs4=utfdd2u1chsz(0,pdata,pdbcs,reslen,&chsz);         //~v7bnI~
    	    UTRACEP("%s:ddfmt ucs2=%04x,ucs4=0x%06x,chsz=%d,data=0x%02x,dbcs=0x%02x\n",UTT,ucs,ucs4,chsz,*pdata,*pdbcs);//~v7bnI~
        }                                                          //~v7bnI~
    }                                                              //~v7bnI~
    ucsctr=PTRDIFF(pucs,Ppucs)/sizeof(ucs);                        //~v7bnI~
    *Ppucsctr=ucsctr;                                              //~v7bnI~
	UTRACEP("%s:return 0,usctr=%d\n",UTT,ucsctr);                  //~v7bnI~
	UTRACED("out ucs",Ppucs,Sscrwidth*sizeof(UWCHART));            //~v7bnI~
    return 0;                                                      //~v7bnI~
}//uvioGetCellData                                                 //~v7bnI~
#endif DDD                                                         //~v7bnI~
#ifdef WXE      //wxe save to buffer for errmsg                    //~vbzMI~
//*************************************************************************//~vbzMI~
int uvio_m2dd(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int *Ppddctr)//~vbzMR~
{                                                                  //~vbzMI~
    WUCS wkucs[UVIOM_MAXCOL];                                      //~vbzMR~
    int ucsctr;                                                    //~vbzMI~
    //*******************************                              //~vbzMI~
	UTRACEP("%s:opt=0x%02x,row=%d,col=%d\n",UTT,Popt,Prow,Pcol);   //~vbzMI~
	UTRACED("data",Ppdata,Plen);                                   //~vbzMI~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~vbzMI~
    wxe_m2u(Popt,Prow,Pcol,Ppdata,Ppdbcs,Plen,wkucs,(int)sizeof(wkucs),&ucsctr);//~vbzMR~
    int opt=U162DO_REPUCS;                                         //~vbzMI~
	int rc=utf162dd(opt,wkucs,ucsctr,Ppdddata,Ppdddbcs,Plen,Ppddctr);//~vbzMR~
	UTRACEP("%s:rc=%d,len=%d,ddctr=%d\n",UTT,rc,Plen,*Ppddctr);    //~vbzMI~
	UTRACED("out dddata",Ppdddata,Plen);                           //~vbzMI~
	UTRACED("out dddbcs",Ppdddbcs,Plen);                           //~vbzMI~
    return rc;                                                     //~vbzMI~
}                                                                  //~vbzMI~
//*************************************************************************//~vbzMI~
//*adjust by altch                                                 //~vbzMI~
//*************************************************************************//~vbzMI~
int uvio_u2dd(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int *Ppddctr)//~vbzMR~
{                                                                  //~vbzMI~
    WUCS wkucs[UVIOM_MAXCOL];                                      //~vbzMI~
    int ucsctr;                                                    //~vbzMI~
    //*******************************                              //~vbzMI~
	UTRACEP("%s:opt=0x%02x,row=%d,col=%d\n",UTT,Popt,Prow,Pcol);   //~vbzMI~
	UTRACED("data",Ppdata,Plen);                                   //~vbzMI~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~vbzMI~
    wxe_u2altch(Popt,Prow,Pcol,Ppdata,Ppdbcs,Plen,wkucs,(int)sizeof(wkucs),&ucsctr);//~vbzMR~
    int opt=U162DO_REPUCS;                                         //~vbzMI~
	int rc=utf162dd(opt,wkucs,ucsctr,Ppdddata,Ppdddbcs,Plen,Ppddctr);//~vbzMI~
	UTRACEP("%s:rc=%d,len=%d,ddctr=%d\n",UTT,rc,Plen,*Ppddctr);    //~vbzMI~
	UTRACED("out dddata",Ppdddata,Plen);                           //~vbzMI~
	UTRACED("out dddbcs",Ppdddbcs,Plen);                           //~vbzMI~
    return rc;                                                     //~vbzMI~
}                                                                  //~vbzMI~
//*************************************************************************//~vbzMI~
//*rc=0:OK ;4:readconsole err, -1 :end of line                     //~vbzMI~
//*************************************************************************//~vbzMI~
int uvioGetCellDataWXE(int Popt,int Prow,int PcmaxCol,int PsplitHpos,int PsplitVpos,UCHAR *Ppdddata,UCHAR *Ppdddbcs)//~vbzMR~
{                                                                  //~vbzMI~
	int maxrow,pos;                                                //~vbzMR~
    UCHAR *pdata,*pdbcs;                                           //~vbzMI~
    int utf8lenL,utf8lenR=0,lenL,lenR,ddctr;                       //~vbzMR~
    int opt;                                                       //~vbzMR~
//************************                                         //~vbzMI~
    maxrow=Sscrsize/Sscrwidth;                                     //~vbzMI~
	UTRACEP("%s:opt=%04x,row=%d,maxrow=%d,scrWidth=%d,cmaxCol=%d,splitVpos=%d\n",UTT,Popt,Prow,maxrow,Sscrwidth,PcmaxCol,PsplitVpos);//~vbzMR~
	opt =Popt;                                                     //~vbzMI~
    if (Prow>=maxrow)                                              //~vbzMI~
    {                                                              //~vbzMI~
		UTRACEP("%s:end of row maxrow=%d\n",UTT,maxrow);           //~vbzMI~
    	return -1;                                                 //~vbzMI~
    }                                                              //~vbzMI~
    pos=Prow*Sscrwidth;                                            //~vbzMI~
    pdata=Sw95buffc+pos;		//screen char buffer               //~vbzMI~
    pdbcs=Sdbcstbl+pos;		//screen char buffer                   //~vbzMI~
    UTRACED("data",pdata,PcmaxCol);                                //~vbzMR~
    UTRACED("dbcs",pdbcs,PcmaxCol);                                //~vbzMR~
//    if (PsplitHpos)                                              //~vbzMR~
//    {                                                            //~vbzMR~
//        if (Prow<PsplitHpos)                                     //~vbzMR~
//        {                                                        //~vbzMR~
//            opt|=WXEHCO_HSPLIT_UPPER;                            //~vbzMR~
//            if (Popt & WXEHCO_PCW1_FILE)                         //~vbzMI~
//            {                                                    //~vbzMI~
//                if (Prow>=2)                                     //~vbzMI~
//                    opt|=WXEHCO_DATAINE;                         //~vbzMI~
//            }                                                    //~vbzMI~
//        }                                                        //~vbzMR~
//        else                                                     //~vbzMR~
//        {                                                        //~vbzMR~
//            opt|=WXEHCO_HSPLIT_LOWER;                            //~vbzMR~
//            if (Popt & WXEHCO_PCW2_FILE)                         //~vbzMI~
//            {                                                    //~vbzMI~
//                if (Prow-PsplitHpos>=2)                          //~vbzMI~
//                    opt|=WXEHCO_DATAINE;                         //~vbzMI~
//            }                                                    //~vbzMI~
//        }                                                        //~vbzMR~
//    }                                                            //~vbzMR~
    if (PsplitVpos)                                                //~vbzMI~
    {                                                              //~vbzMI~
    	lenL=PsplitVpos; lenR=PcmaxCol-PsplitVpos;                 //~vbzMI~
    }                                                              //~vbzMI~
    else                                                           //~vbzMI~
    {                                                              //~vbzMI~
    	lenL=PcmaxCol; lenR=0;                                     //~vbzMI~
    }                                                              //~vbzMI~
    utf8lenL=0;                                                    //~vbzMI~
    if (lenL)                                                      //~vbzMI~
    {                                                              //~vbzMI~
		if (utfchkdd(0,pdbcs,lenL))                                //~vbzMR~
        	utf8lenL=lenL;                                         //~vbzMR~
    }                                                              //~vbzMI~
    utf8lenR=0;                                                    //~vbzMI~
    if (lenR)                                                      //~vbzMI~
    {                                                              //~vbzMI~
	    if (utfchkdd(0,pdbcs+lenL,lenR))                           //~vbzMI~
        	utf8lenR=lenR;                                         //~vbzMI~
    }                                                              //~vbzMI~
    opt|=WXEHCO_VSPLIT_LEFT;                                       //~vbzMI~
    if (utf8lenL)                                                  //~vbzMI~
    {                                                              //~vbzMI~
		uvio_u2dd(opt,Prow,0,pdata,pdbcs,lenL,Ppdddata,Ppdddbcs,&ddctr);//~vbzMR~
    }                                                              //~vbzMI~
    else	//left is locale data                                  //~vbzMR~
    {                                                              //~vbzMI~
		uvio_m2dd(opt,Prow,0,pdata,pdbcs,lenL,Ppdddata,Ppdddbcs,&ddctr);//~vbzMR~
    }                                                              //~vbzMI~
    if (lenR)                                                      //~vbzMI~
    {                                                              //~vbzMI~
        opt|=WXEHCO_VSPLIT_RIGHT;                                  //~vbzMI~
        if (utf8lenR)                                              //~vbzMI~
        {                                                          //~vbzMI~
			uvio_u2dd(opt,Prow,lenL,pdata+lenL,pdbcs+lenL,lenR,Ppdddata+lenL,Ppdddbcs+lenL,&ddctr);//~vbzMR~
        }                                                          //~vbzMI~
        else                                                       //~vbzMI~
        {                                                          //~vbzMI~
			uvio_m2dd(opt,Prow,lenL,pdata+lenL,pdbcs+lenL,lenR,Ppdddata+lenL,Ppdddbcs+lenL,&ddctr);//~vbzMR~
        }                                                          //~vbzMI~
    }                                                              //~vbzMI~
	UTRACED("out dddata",Ppdddata,(UINT)PcmaxCol);                 //~vbzMR~
	UTRACED("out dddbcs",Ppdddbcs,(UINT)PcmaxCol);                 //~vbzMR~
    return 0;                                                      //~vbzMI~
}//uvioGetCellDataWXE                                              //~vbzMI~
#endif  //WXE                                                      //~vbzMR~
#endif  //W32                                                     
