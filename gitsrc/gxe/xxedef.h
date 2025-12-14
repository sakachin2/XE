//*CID://+vbC3R~:                             update#=  111;       //+vbC3R~
//*************************************************                //~2831I~
//vbC3:250108 (gxe)crash at xxemain_setfont(Pstle=8). 8 is maxstyle at xesyn but 4 in gxe(Gsynfontdesc init 4 entry)//+vbC3I~
//vbi9:180221 (GTK3:bug)window size recovery err                   //~vbi9I~
//vbd1:171114 (Wxe:BUG)Help About:version 1.28-->1.29              //~vbd1I~
//vb00:150309 v1.28                                                //~vb00I~
//vam7:130929 add print with ligature(also for gnomeprint)         //~vam7I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaiD:130703 xe version  1.27                                     //~vaiDI~
//va8x:110520 version:v1.26                                        //~va8xI~
//va26:091210 (BUG)Info from Dirk                                  //~va26I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76T:071023 (WXE) sticky crosshair cursor mode                   //~v76TI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v69U:060718 (XXE:BUG)errmsg "Cut/Pastet source data contains invalid data"//~v69UI~
//            because scr width is not multiple of cellw,copy data contains 1 column over//~v69UI~
//v695:060427 (XXE) help version correct                           //~v695I~
//v67L:060205 v121                                                 //~v67LI~
//v667:050823 (XXE)add printer selection dropdown list(effective only for CUPS)//~vXXEI~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//*************************************************                //~v510I~
// wxedef.h                                                        //~2831R~
//*************************************************                //~2831I~
#define WXE_PGMNAME "xxe"                                          //~vXXER~
//#define WXE_VER     124                                            //~v76TR~//~va26R~
//#define WXE_VER     126                                            //~va26I~//~vaiDR~
//#define WXE_VER     127                                          //~vb00R~
//#define WXE_VER     128                                            //~vb00I~//~vbd1R~
#define WXE_VER     129                                            //~vbd1I~
#define WXE_TITLE "Hybrid Editor:XE"                               //~2922I~
#define WXE_TEMPDIR "NewFiles"                                     //~2923I~
//#define BORDERMARGIN    1                                        //~v69UR~
#define BORDERMARGIN    0                                          //~v69UI~
#define RESIZE_HINT_BASE_COLUMN 74	//minimum column for ICON by icon menu item//~v69UI~
#define RESIZE_HINT_BASE_ADJUST -7	//ajust for boundary           //~v69UR~
#define PRINT_MARGIN_RIGHT_SAFETY  50                              //~2B16R~
#define PRINT_BW_FGCOLOR       RGB(0,0,0)       //black            //~2A27I~
#define PRINT_BW_BGCOLOR       RGB(255,255,255)	//white            //~2A27I~
#define MAXELF 200  	//max save font table                      //~2C03I~
#define DEF_FRAMEWIDTH   600                                       //~vXXER~
#define DEF_FRAMEHEIGHT  400                                       //~vXXER~
#define DEF_DRAGTIMEOUT   60                                       //~vXXEI~
                                                                   //~v780I~
#define WXEFONTSTYLE_NORMAL       0                                //~v780I~
#define WXEFONTSTYLE_BOLD         1                                //~v780I~
#define WXEFONTSTYLE_UNDERLINE    2                                //~v780I~
#define WXEFONTSTYLE_ITALIC       3                                //~v780I~
//#define WXEFONTSTYLE_MAX          4                                //~v780I~//+vbC3R~
#define WXEFONTSTYLE_MAX          8                                //+vbC3I~
#define WXEFONTSTYLE_NOSYNTAX     WXEFONTSTYLE_MAX	//normal style and no sytax RGB//~v780I~
#define WXE_SYNTAXRGB             0x01000000        //RGBn specified on xesyn.cfg//~v780I~
                                                                   //~vXXEI~
#define PRINTCOL_MAX         500  //print page column maximum      //~va20I~
#define PPDMAXNAME    44 // from cups/ppd.h:PPD_MAX_NAME=41        //~vam0I~
                                                                   //~va20I~
//*************************************************                //~2831I~
#define MK_SHIFT   (GDK_SHIFT_MASK)                                //~vXXER~
#define MK_CONTROL (GDK_CONTROL_MASK)                              //~vXXER~
#define MK_ALT     (GDK_MOD1_MASK)                                 //~vXXEI~
#define MK_LBUTTON (GDK_BUTTON1_MASK)                              //~vXXEI~
#define MK_MBUTTON (GDK_BUTTON2_MASK)                              //~vXXEI~
#define MK_RBUTTON (GDK_BUTTON3_MASK)                              //~vXXEI~
#define RGB_MAKE(r,g,b)  ((((b)<<16) | ((g)<<8) | (r)) & 0xffffff) //~v780I~
//*************************************************                //~vXXEI~
#define HWND    void*                                              //~vXXEI~
#define CDC     GdkPixmap                                          //~vXXEI~
typedef struct _GdkPoint CPoint;                                   //~vXXER~
                                                                   //~vXXEM~
typedef struct _XXECOLOR { USHORT red; USHORT green; USHORT blue;} XXECOLOR,*PXXECOLOR;//~vXXEM~
#define XXECOLORSZ sizeof(XXECOLOR)                                //~vXXEM~
#define RGB(r,g,b)      {r,g,b}                                    //~vXXEM~
#define COLORCOPY(t,s)  memcpy(&(t),&(s),XXECOLORSZ)               //~vXXEM~
                                                                   //~vXXEI~
typedef struct _RECT { int left ;int top; int right; int bottom;} RECT,*PRECT;//~vXXER~
//*ini file data                                                   //~2A19I~
typedef struct _WXEINIDATA {                                       //~2A19M~
						int   WXEINIver;	//version              //~2A19M~
					    char  WXEINIfontstyle[256]; //font style   //~vXXER~
                        int   WXEINIcmaxrow;//current row count    //~2A19M~
                        int   WXEINIcmaxcol;//current col count    //~2A19M~
						int   WXEINIcellh;	//cell height          //~2A19M~
						int   WXEINIcellw;	//cell width           //~2A19M~
//  					int   WXEINIcharset;	//cell width       //~vXXER~
//  					int   WXEINIothercharset;	//cell width   //~vXXER~
//						int   WXEINIfontheight;	//char height      //~vXXER~
//						int   WXEINIfontwidth;	//char width       //~vXXER~
					    XXECOLOR  WXEINIbgcolor;//background clore //~vXXER~
					    int   WXEINIframewidth;//frame screen width//~2A19M~
					    int   WXEINIframeheight;//frame screen height//~2A19M~
					    int   WXEINIshowmaxsw;//mouse scroll line count//~2A19R~
					    int   WXEINIscrollctr;//mouse scroll line count//~2A19M~
					    int   WXEINIuseact;//use accelerator       //~3103I~
					    int   WXEINIusemk ;//use accelerator       //~3105I~
					    BOOL  WXEINIttfont;//true type font        //~2A19M~
//page setup                                                       //~2B03I~
//  					char  WXEINIformsize[32];                  //~vam0R~
    					char  WXEINIrsv4[32];                      //~vam0R~
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
//                      int   WXEINIpfontszh;                      //~vXXER~
//                      int   WXEINIpfontszw;                      //~vXXER~
                        int   WXEINIpcellszh;                      //~v51hI~
                        int   WXEINIpcellszw;                      //~v51hI~
//                      int   WXEINIrsv1[26];                      //~vam7R~
                        BOOL  WXEINIprintLigature;                 //~vam7R~
                        int   WXEINIrsv1[25];                      //~vam7I~
//  					char  WXEINIprtfontstyle[256];             //~vam0R~
    					char  WXEINIprtfontstyle[128];             //~vam0I~
						char  WXEINIformsize[PPDMAXNAME]; //44     //~vam0I~
						char  WXEINIprinter[PPDMAXNAME]; //44      //~vam0I~
  						char  WXEINIrsv6[40];                      //~vam0R~
//                      char  WXEINIrsv2[96];                      //~v62WR~
                        int   WXEINIpcellszhmax;                   //~v62WR~
//                      char  WXEINIrsv2[92];                      //~vXXER~
                        int   WXEINIdblclicktimer;                 //~vXXER~
//                      char  WXEINIrsv2[88];                      //~vXXER~
//						char  WXEINIprinter[32];                   //~vam0R~
  						char  WXEINIrsv5[32];                      //~vam0I~
//                      char  WXEINIrsv2[56];                      //~v73tR~
                        int   WXEINIsetflag; //ini data field effectuve flag//~v73tI~
#define WXEINIF_RULERCOLOR 0x01                                    //~v73tR~
//#define WXEINIF_BGCOLOR    0x02                                  //~v73yR~
#define WXEINIF_OPT_QEXIT  0x04                                    //~v73yI~
#define WXEINIF_RULERKEY   0x08                                    //~v740I~
#define WXEINIF_OPT_LIGATURE   0x10                                //~va1MR~
#define WXEINIF_OPT_RULER    0xff00  //ruler mode mask             //~v76TI~
                        XXECOLOR  WXEINIrulercolor;                //~v73tR~
                        char  WXEINIrsv2[2];                       //~v73tR~
//                      char  WXEINIrsv3[44];                      //~v740R~
                        char  WXEINIrulerkey[4];                   //~v740I~
                        char  WXEINIrsv3[40];                      //~v740I~
                    } WXEINIDATA;                                  //~2A19M~
typedef WXEINIDATA *PWXEINIDATA;                                   //~2A19M~
//#define WXEINIDATASZ (sizeof(WXEINTIDATA))                         //~2A19M~//~vbi9R~
#define WXEINIDATASZ (sizeof(WXEINIDATA))                          //~vbi9I~
#ifdef __cplusplus                                                 //~2831M~
extern "C" {                                                       //~2811I~
				int wxecfunc(char *Pparm);                         //~2811I~
           }                                                       //~2811I~
#endif                                                             //~2831I~
