//*CID://+va3gR~:                             update#=   69;
//*************************************************                //~2831I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v78B:080426*(wxe,gxe)vertical ruler draw performance             //~v78bI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v77DI~
//v77D:080129*report by M.J(dup #define warning by vc2005)         //~v77DI~
//v76T:071023 (WXE) sticky crosshair cursor mode                   //~v76TI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//*************************************************                //~v510I~
// wxedef.h                                                        //~2831R~
//*************************************************                //~2831I~
#pragma once                                                       //~va3gI~
                                                                   //~v69fI~
//*** not defined on winuser of vc6                                //~v69fM~
	#ifndef WM_APPCOMMAND                                          //~v77DI~
#define WM_APPCOMMAND                0x0319                        //~v69fM~
	#endif                                                         //~v77DI~
	#ifndef FAPPCOMMAND_MASK                                       //~v77DI~
#define FAPPCOMMAND_MASK             0xf000	//0fff is command of lparam hiword//~v69fM~
	#endif                                                         //~v77DI~
	#ifndef APPCOMMAND_BROWSER_BACKWARD                            //~v77DI~
#define APPCOMMAND_BROWSER_BACKWARD  1                             //~v69fR~
	#endif                                                         //~v77DI~
	#ifndef APPCOMMAND_BROWSER_FORWARD                             //~v77DI~
#define APPCOMMAND_BROWSER_FORWARD   2                             //~v69fM~
	#endif                                                         //~v77DI~
//*** not defined on winuser of vc6                                //~v69fM~
                                                                   //~v69fI~
#define WXE_PGMNAME "wxe"                                          //~2928I~
#define WXE_VER     101                                            //~2A19I~
#define WXE_TITLE "Hybrid Editor:XE"                               //~2922I~
#define WXE_TEMPDIR "NewFiles"                                     //~2923I~
#define BORDERMARGIN    1                                          //~2928M~
#define PRINT_MARGIN_RIGHT_SAFETY  50                              //~2B16R~
#define PRINT_BW_FGCOLOR       RGB(0,0,0)       //black            //~2A27I~
#define PRINT_BW_BGCOLOR       RGB(255,255,255)	//white            //~2A27I~
#define MAXELF 200  	//max save font table                      //~2C03I~
                                                                   //~v77DI~
#define WXEFONTSTYLE_NORMAL       0                                //~v780R~
#define WXEFONTSTYLE_BOLD         1                                //~v780R~
#define WXEFONTSTYLE_UNDERLINE    2                                //~v780R~
#define WXEFONTSTYLE_ITALIC       3                                //~v780R~
#define WXEFONTSTYLE_MAX          4                                //~v780R~
#define WXEFONTSTYLE_NOSYNTAX     WXEFONTSTYLE_MAX	//normal style and no sytax RGB//~v780R~
#define WXE_SYNTAXRGB             0x01000000        //RGBn specified on xesyn.cfg//~v780I~
                                                                   //~va20I~
#define PRINTCOL_MAX         500  //print page column maximum      //~va20I~
                                                                   //~v77DM~
#define RGB_MAKE(r,g,b)  ((((b)<<16) | ((g)<<8) | (r)) & 0xffffff) //~v780I~
//*************************************************                //~2831I~
//*ini file data                                                   //~2A19I~
typedef struct _WXEINIDATA {                                       //~2A19M~
						int   WXEINIver;	//version              //~2A19M~
					    char  WXEINIfontstyle[80]; //font style    //~2A19M~
                        int   WXEINIcmaxrow;//current row count    //~2A19M~
                        int   WXEINIcmaxcol;//current col count    //~2A19M~
						int   WXEINIcellh;	//cell height          //~2A19M~
						int   WXEINIcellw;	//cell width           //~2A19M~
						int   WXEINIcharset;	//cell width       //~2A19M~
						int   WXEINIothercharset;	//cell width   //~3102I~
						int   WXEINIfontheight;	//char height      //~2A19M~
						int   WXEINIfontwidth;	//char width       //~2C14I~
					    int   WXEINIbgcolor;//background clore     //~2A19M~
					    int   WXEINIframewidth;//frame screen width//~2A19M~
					    int   WXEINIframeheight;//frame screen height//~2A19M~
					    int   WXEINIshowmaxsw;//mouse scroll line count//~2A19R~
					    int   WXEINIscrollctr;//mouse scroll line count//~2A19M~
					    int   WXEINIuseact;//use accelerator       //~3103I~
					    int   WXEINIusemk ;//use accelerator       //~3105I~
					    BOOL  WXEINIttfont;//true type font        //~2A19M~
//page setup                                                       //~2B03I~
						char  WXEINIformsize[32];                  //~2B03I~
                        BOOL  WXEINIlandscape;                     //~2B03I~
                        BOOL  WXEINIlinenmber;                     //~2B03I~
                        BOOL  WXEINI2p;                            //~2B03I~
                        BOOL  WXEINIheader;                        //~2B03I~
                        BOOL  WXEINIfooter;                        //~2B03I~
                        BOOL  WXEINIfiletime;                      //~2B03I~
                        BOOL  WXEINIsystime;                       //~2B03R~
                        BOOL  WXEINIwwscrprt;                      //~2B10I~
                        BOOL  WXEINIfullpage;                      //~2B30I~
                        int   WXEINIprtcol;                        //~2B03I~
                        int   WXEINIprtrow;                        //~2B03I~
                        int   WXEINIprt2pcol;                      //~2B04I~
                        int   WXEINIleft;                          //~2B03I~
                        int   WXEINIright;                         //~2B03I~
                        int   WXEINItop;                           //~2B03I~
                        int   WXEINIbottom;                        //~2B03I~
//                      char  WXEINIrsv[256];                      //~v510R~
                        int   WXEINIscrolltimer;                   //~v510I~
//                      int   WXEINIrsv1[31];                      //~v51hR~
                        BOOL  WXEINIchkpfontsz;                    //~v51hI~
                        int   WXEINIpfontszh;                      //~v51hR~
                        int   WXEINIpfontszw;                      //~v51hI~
                        int   WXEINIpcellszh;                      //~v51hI~
                        int   WXEINIpcellszw;                      //~v51hI~
                        int   WXEINIrsv1[26];                      //~v51hR~
						char  WXEINIprtfontstyle[32];              //~v51hI~
//                      char  WXEINIrsv2[96];                      //~v62WR~
                        int   WXEINIpcellszhmax;                   //~v62WR~
//                      char  WXEINIrsv2[92];                      //~v73tR~
                        int   WXEINIrulercolor;                    //~v73tR~
//                      char  WXEINIrsv2[88];                      //~v73yR~
                        int   WXEINIsetflag; //ini data field effectuve flag//~v73yI~
//#define WXEINIF_RULERCOLOR 0x01     XXE only                     //~v73yR~
//#define WXEINIF_BGCOLOR    0x02     XXE only                     //~v73yR~
#define WXEINIF_OPT_QEXIT  0x04                                    //~v73yI~
#define WXEINIF_OPT_LIGATURE   0x08  //ligature option             //~va3gI~
#define WXEINIF_OPT_RULER    0xff00  //ruler mode mask             //~v76TR~
//                      char  WXEINIrsv2[84];                      //~v740R~
                        char  WXEINIrulerkey[4];                   //~v740I~
                        char  WXEINIrsv2[80];                      //~v740I~
                    } WXEINIDATA;                                  //~2A19M~
typedef WXEINIDATA *PWXEINIDATA;                                   //~2A19M~
#define WXEINIDATASZ (sizeof(WXEINTIDATA))                         //~2A19M~
                                                                   //~v78bI~
#include <ulibdefu.h>                                              //~v78bI~
                                                                   //~v78bI~
#ifdef __cplusplus                                                 //~2831M~
extern "C" {                                                       //~2811I~
				int wxecfunc(char *Pparm);                         //~2811I~
           }                                                       //~2811I~
#endif                                                             //~2831I~
