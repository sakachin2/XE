//*CID://+v7fzR~:                             update#=  376;       //~v7fzR~
//================================================================================//~v510I~
//v7fz:251205 (gxe) hcopy eol option for also gxe                  //~v7fzI~
//vbAp:240701 (gxe)  hardcopy support                              //~vbApI~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~vb4rI~
//var8:140127 gtk3 suppott                                         //~var8I~
//vamt:131015 (GtkPrint)accept minus value of margin to adjust origin for each printer's paper folder shift attachment.(case of that b5 origin is relativ to a4 origin)//~vamtI~
//vamk:131006 margin not by int but by gdouble for acuracy         //~vamkI~
//vam7:130929 add print with ligature                              //~vam7I~
//vam3:130927 point<-->mm acurate value 1 mm = 360.0/127 point     //~vam3I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va6y:000706 CUPs default printer is not same as gnome default    //~va6yI~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//va0T:091003!(BUG:XXE)miss utf8 string when ime returns mutiple utf8 char//~va0TI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78B:080426*(wxe,gxe)vertical ruler draw performance             //~v78BI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76e:070618 (XXE)typematic support for R-Ctrl                    //~v76eI~
//v76c:070617 (XXE)paste from PRIMARY clipboard by middle button down//~v76cI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v71x:061023 (XXE)it take time to download for DND and Application HUNG occurs//~v71xI~
//            aftwer completed using user msg to download,issue begindrag//~v71xI~
//v71s:061022 (WXE/XXE)err msg when drag canceled by mouse lb release//~v71sI~
//v69U:060718 (XXE:BUG)errmsg "Cut/Pastet source data contains invalid data"//~v69UI~
//            because scr width is not multiple of cellw,copy data contains 1 column over//~v69UI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69d:060518 (GXE:BUG)killfocus chk logic missing                 //~v69bI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v689:060328 (BUG)on dir list;s+lbdown/c+lbdown is for line selection not paste(ins/rep)//~v689I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v66p:051026 (XXE)std paste support                               //~v66pI~
//v667:050823 (XXE)add printer selection dropdown list(effective only for CUPS)//~v667I~
//vX02:050729 set defaut printer font same as screen               //~vX01I~
//vX01:050729 cellh/cellw=0 mean same as fonth/fontw               //~vX01I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v63r:050525 ignore(no cursor move) 1st mouse click after killfocus//~v63rI~
//v63p:050510 (WXE:BUG)range spcification should be for each pcw   //~v63pI~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~v63kI~
//v63i:050507 (WXE)dragdrop by copy/paste                          //~v63iI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v627:050309 (WXE)vhex print support                              //~v627I~
//v564:040326 (WIN)at cmd ignore err option "-i"                   //~v564I~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55G:040315 (WXE)Beep option on setup dialog                     //~v55uI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v53q:030930 (WXE:BUG) area not freed when print canceled because endprinting is not called//~v51wI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//v51u:030615 (WXE)wait scroll kick at first 3 time interval       //~v51uI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//================================================================================//~v510I~
#ifndef HEADER_WXEMAIN                                             //~2827R~
#define HEADER_WXEMAIN                                             //~2827R~
                                                                   //~2816I~
#ifdef __cplusplus                                                 //~2831I~
	#include    <afxwin.h>                                         //~2831R~
#endif                                                             //~2831I~
//================================================================================//~2818I~
#ifdef GBL_XXEMAIN                                                 //~vXXEI~
	#define EXT                                                    //~vXXEI~
	#define INIT(value)  =value                                    //~vXXEI~
#else                                                              //~vXXEI~
	#define EXT extern                                             //~vXXEI~
	#define INIT(value)                                            //~vXXEI~
#endif                                                             //~vXXEI~
//================================================================================//~vXXEI~
//================================================================================//~2818I~
EXT    XXECOLOR DEF_BGCOLOR INIT(RGB(0x1000,0x2000,0x1000));       //~vX01R~
EXT    XXECOLOR DEF_RULERCOLOR INIT(RGB(0x2000,0x6000,0x2000));    //~v73tR~
#define DEF_RULERKEY  "\x01\x02\x03"  //S+C+F1,F2,F3               //~v740R~
//================================================================================//~vXXEI~
#define MAXIMECHARCTR   256                                        //~v79zI~
//#define MAXIMECHARSZ    4                                          //~v79zI~//~va0TR~
#define MAXCOL          240                                        //~2A08R~
#define MAXROW          200                                        //~2901M~
#define MAXCOLOR        16                                         //~vXXER~
#define DEF_DOSFONT     "Terminal"  //dosapp.fon(cp437) or app932.fon//~2A05I~
#define DEF_PRTFONTSTYLE  ""                                       //~vX01R~
//#define DEF_FONTSTYLE   DEF_DOSFONT                              //~vX01R~
#define DEF_FONTSTYLE   "" //get default at gxedlg_init from pango context//~vX01I~
#define DEF_FONTSTYLE2  "System"                                   //~2B30I~
#define DEF_FONTSZH     0 //by fontdescription                     //~vX01R~
#define DEF_FONTSZW     0 //set at createfont                      //~vX01R~
#define DEF_ROWH        0 //from font height                       //~vX01R~
#define DEF_COLW        0 //from font width                        //~vX01R~
#define DEF_SCRROW      25                                         //~2915I~
#define DEF_SCRCOL      80                                         //~2915I~
#define DEF_TEXTCSR_HEIGHT  2  //rep mode text cursor height pixel //~vXXEI~
//#define DEF_OTHERCHARSET 254                                     //~vXXER~
//#define DEF_CHARSET     SHIFTJIS_CHARSET	//for NT               //~vXXER~
//#define DEF_CHARSET     DEF_OTHERCHARSET	//For W95              //~3111R~
#define DEF_SCROLLCTR   3                                          //~2A13I~
#define DEF_SCROLLINITWAIT 3                                       //~v51uI~
#define DEF_SCROLLTIMER 200    //ms                                //~v510M~
#define DEF_DBLCLICKTIMER  500    //ms time from push to 2nd button up//~vXXEI~
#define DEF_TYPEMATICDELAY    250    //typematic start after 250ms wait//~v76eI~
#define DEF_TYPEMATICINTERVAL    30    //repeat typematic each 30 ms=33char/sec//~v76eR~
#define DEF_TYPEMATICCHKINTERVAL 30    //timer interval            //~v76eI~
//*page setup                                                      //~2B03I~
#define DEF_FORMSIZE    "A4"                                       //~2B03I~
#define DEF_PRINTER     "Default"                                  //~v667I~
#ifndef OPTGTK3                                                    //~var8R~
#define NO_CUPS_PRINTER "No-CUPS"                                  //~vam0I~
#else   //OPTGTK3                                                  //~var8R~
#define NO_CUPS_PRINTER "No-CUPS-Printer"                          //~var8R~
#endif                                                             //~var8R~
#define DEF_A4_COL       0	//0 means by max lrecl                 //~2B09R~
#define DEF_A4_ROW       0  //0 means bu maxcol and cell h/w rate  //~2B09R~
#define DEF_COLFORLRECL0 80 //maxcol for maxlrecl=0                //~2B09I~
#define DEF_CELLSZHMAX   14 //cell height maxlimum                 //~v62WI~
#define DEF_2PCOL        4                                         //~2B04I~
#define PRTSCRID        "PrtScr"                                   //~2B09I~
                                                                   //~va6yI~
//#define POINT2MM(pt)    ((float)(pt)*0.353)                        //~va6yR~//~vam3R~
#define POINT2MM(pt)    ((float)(pt)*127.0f/360.0f)                //~vam3I~
//#define MM2POINT(mm)    ((float)(mm)*2.835)      // 72/25.4 //1inch=72point=25.4mm//~va6yR~//~vam3R~
#define MM2POINT(mm)    ((float)(mm)*360.0f/127.0f)      // 72/25.4 //1inch=72point=25.4mm//~vam3I~
#define INCH2MM(inch)    ((float)(inch)*25.4)                      //~va6yR~
#define INCH2POINT(inch)    ((float)(inch)*72)                     //~va6yR~
                                                                   //~2B30I~
#define PRTTYPE_HCOPY         -1                                   //~2B30M~
#define PRTTYPE_FILE          'F'                                  //~2B30M~
#define PRTTYPE_DIR           'D'                                  //~2B30M~
#define PRTTYPE_BIN           'B'                                  //~2B30M~
#define PRTTYPE_HEX           'H'                                  //~2C07R~
#define PRTTYPE_VHEXBIN       'b'                                  //~v627R~
#define PRTTYPE_VHEXTEXT      't'                                  //~v627I~
#define PRTTYPE_VHEXHHEX      'V'      //vhex and hex              //~va49I~
                                                                   //~2C07I~
#define PRTLNOTYPE_DEC        'D'                                  //~2C07R~
#define PRTLNOTYPE_HEX        'X'                                  //~2C07R~
#define PRTLNOTYPE_hex        'x'                                  //~2C07R~
                                                                   //~2905I~
#define RGB_GETBLUE(rgb)   (((rgb)>>16) & 0xff)                    //~2905M~
#define RGB_GETGREEN(rgb) (((rgb)>>8) & 0xff)                      //~2905M~
#define RGB_GETRED(rgb)  ((rgb) & 0xff)                            //~2905M~
//#define RGB_MAKE(r,g,b)  ((((b)<<16) | ((g)<<8) | (r)) & 0xffffff)//~v780R~
                                                                   //~2818I~
//#ifdef __cplusplus                                               //~vXXER~
                                                                   //~2901I~
//#define COL(x)      min( MAXCOL-1, ((x-BORDERMARGIN)/Mcellw) )   //~v69UR~
#define COL(x)     max(0, min( Mscrcmaxcol-1, ((x-BORDERMARGIN)/Mcellw) ) )//~v69UR~
//#define ROW(y)      min( MAXROW-1, ((y-BORDERMARGIN)/Mcellh) )   //~v69UR~
#define ROW(y)     max(0,  min( Mscrcmaxrow-1, ((y-BORDERMARGIN)/Mcellh) ) )//~v69UR~
#define COLCTR(width)   min( MAXCOL, ((width) -BORDERMARGIN)/Mcellw )//~2A23R~
//#define ROWCTR(height)  min( MAXROW, (((height)-BORDERMARGIN-max(Mcellh-Mfontheight,0))/Mcellh) )//~vXXER~
#define ROWCTR(height)  min( MAXROW, (((height)-BORDERMARGIN)/Mcellh) )//~vXXEI~
#define CWINWIDTH(col)   ((col)*Mcellw+BORDERMARGIN)               //~2A23R~
#define CWINHEIGHT(row)  ((row)*Mcellh+BORDERMARGIN+max(Mcellh-Mfontheight,0)) //client window height//~2A23R~
#define XX(col)         ((col)*Mcellw+BORDERMARGIN)                //~2901R~
#define YY(row)         ((row)*Mcellh+BORDERMARGIN)                //~2901R~
#define INVALIDATE_LINE(row) *(Mwxeintf.WXEIlineupdate+(row))=1    //~vXXEI~
                                                                   //~vXXEI~
#define MAKE_TEXT_RECT(rect,row,col,chars) \
			(rect)->top=YY(row);     \
			(rect)->left=XX(col);    \
			(rect)->bottom=YY((row)+1);    \
			(rect)->right=XX((col)+(chars))                        //~vXXER~
#define TEXTDATA(row,col)    (Mwxeintf.WXEItext+(row)*MAXCOL+(col))//~2A05R~
#define TEXTDBCS(row,col)    (Mwxeintf.WXEIdbcs+(row)*MAXCOL+(col))//~2A05R~
#define TEXTATTR(row,col)    (Mwxeintf.WXEIattr+(row)*MAXCOL+(col))//~2A05R~
#define TEXTSTYLE(row,col)   (Mwxeintf.WXEIsynstyle+(row)*MAXCOL+(col))//~v780I~
#define TEXTLINEOPT(row,col)   (Mwxeintf.WXEIlineopt+(row)*MAXCOL+(col))//~vb4rI~
// swap pt1 and pt2 if pt2 is top left corner                      //~2A01I~
#define CAPGETBOX(pt1,pt2)                          \
       {                                            \
            CPoint ptw1,ptw2;                       \
            ptw1.x=min(pt1.x,pt2.x);                \
            ptw1.y=min(pt1.y,pt2.y);                \
            ptw2.x=max(pt1.x,pt2.x);                \
            ptw2.y=max(pt1.y,pt2.y);                \
    		pt1=ptw1;                               \
    		pt2=ptw2;                               \
        }                                               //         //~2A01I~
// chk the point is in cap box                                     //~2A01I~
// ret 1:in the range, 0:row is inthe range but col is out of range, -1:row is out of range//~2A01I~
#define CAPCHKINBOX(pt1,pt2,row,col)                    \
       (                                                \
    	  (row>=pt1.y && row<=pt2.y) ?                  \
            ( (col>=pt1.x && col<=pt2.x) ? 1:0)         \
            :-1                                         \
       )                                                           //~2A01I~
#define SAMEPOS(pt1,pt2)                    \
       (  (pt1.y == pt2.y) && (pt1.x == pt2.x) )                   //~2A05I~
//set line draw flag                                               //~2A01R~
#define   SETDRAWLINE(row) (*(Mwxeintf.WXEIlineupdate+(row))=1)    //~2A01I~
//#endif  //C++                                                    //~vXXER~
//================================================================================//~2831I~
typedef struct _WXEINTF {                                          //~2831M~
//*wxe-->xe                                                        //~2831I~
						int   WXEImaxrow;	//screen max row       //~2831I~
						int   WXEImaxcol;	//screen max row       //~2831I~
						USHORT WXEIpallette[MAXCOLOR];	//dos colorno//~2905R~
						UINT   WXEIpalrgb[MAXCOLOR];	//rgb value(24bit color)//~vXXER~
//                      int   WXEIctlkey;   //ctl key down         //~2909R~
//                      int   WXEIshiftkey; //shift key down       //~2909R~
//*xe-->wxe                                                        //~2831I~
						UCHAR  *WXEItext;		//scr text tbl,gotten by xe//~2831R~
						USHORT *WXEIattr;		//scr attr tbl,gotten by xe//~2831R~
						UCHAR  *WXEIlineupdate; //scr line update flag//~2831R~
						UCHAR  *WXEIdbcs;		//scr dbcsid tbl,gotten by xe//~2831R~
						UCHAR  *WXEIsynstyle;  	//scr style tbl for syntax highlight//~v780I~
						int    *WXEIlineopt;  	//ligature/combine option line by line//~vb4rI~
						int    *WXEIsynrgb;     //rgb table for syntax highlight//~v780I~
						int     WXEIcurmovesw;  //cusor moved sw   //~2831I~
						int   WXEIcsrhstart;	//csr height start(0-->7)//~2831I~
						int   WXEIcsrhend;      //csr height end(0-->7)//~2831I~
						int   WXEIcsrvisible;	//csr visible      //~2831I~
						int   WXEIcsrchangesw;	//csr type changed //~2831R~
						int   WXEIcsrvisiblechangesw;	//csr visibility changed//~2914I~
						int   WXEIcsrmovesw;	//csr moved        //~2831I~
#define WXEICSR_CHANGEBYKBD 0x04                                   //~va7DI~
#define WXEICSR_CHANGEROW   0x02                                   //~vXXEI~
#define WXEICSR_CHANGECOL   0x01                                   //~vXXEI~
//  					int   WXEIcsrdbcssw;	//csr on dbcs      //~2915R~
                        int   WXEIvsplitsw;                        //~2901I~
                        int   WXEIsplitpos;                        //~2901I~
                        int   WXEIscrbg[2];	//split screen bg pallet no//~2901I~
                        char *WXEIerrmsg;		//multi line uerrmsg//~2901I~
                        int   WXEIatcmdopt;                        //~v564I~
                        int   WXEIatcmdintvl;                      //~v55WI~
                        int   WXEIatcmdrepeat;                     //~v55WI~
                        int   WXEIatcmdcurrctr;                    //~v55WM~
                        char *WXEIatcmdstring;                     //~v55WI~
                        char *WXEIatcmdnext;                       //~v55WI~
                        int   WXEIsleepinmult;//sleep in mult cmd  //~v560I~
                        int   WXEIsleeptime;                       //~v560I~
                        int   WXEIsleepmaxtime;                    //~v564R~
//*xe<-->wxe                                                       //~2831I~
						int   WXEIcsrposx;	//curr cursor pos col  //~2831R~
						int   WXEIcsrposy;	//curr cursor pos row  //~2831R~
						int   WXEIoldcsrposy;	//prev cursor pos row//~vXXEI~
                        int   WXEIxetermsw;    //xeterm requested  //~v55WI~
                        int   WXEIstatus;   //comm flag with xe    //~v682I~
#define WXEIS_DRAWMENU        0x00000001    //draw menue required by reset func//~v682I~
#ifdef UTF8UCS2                                                    //~va20I~
#define WXEIS_PRTUTF8         0x00000010    //fileprint for UTF8 file//~va20I~
#define WXEPRINT_UTF8MODE()  (Mwxeintf.WXEIstatus & WXEIS_PRTUTF8) //~va20I~
#define WXEIS_PRTVHEX         0x00000020    //fileprint vhex mode  //~va20I~
#endif                                                             //~va20I~
#define WXEIS_PRTEBC          0x00000100    //fileprint for EBC file//~va80I~
#define WXEPRINT_EBCFILE()   (Mwxeintf.WXEIstatus & WXEIS_PRTEBC)  //~va80I~
#define WXEIS_PRTEBCBYUCS     0x00000200    //fileprint for EBC file//~va80I~
#define WXEPRINT_EBCBYUCS()  (Mwxeintf.WXEIstatus & WXEIS_PRTEBCBYUCS)//~va80I~
                        int   WXEIkbddelay; //ms   initial wait to start typematic//~v76eI~
                        int   WXEIkbdspeed; //ms                   //~v76eI~
                        UCHAR WXEIimembs[MAXIMECHARCTR]; //ime translated MBstring//~v79zR~
                    } WXEINTF;                                     //~2831M~
typedef WXEINTF *PWXEINTF;                                         //~2831M~
#define WXEINTFSZ (sizeof(WXEINTF))                                //~2831M~
                                                                   //~vXXEI~
#ifdef __cplusplus                                                 //~2831I~
//================================================================================//~2816I~
//                                                                 //~2818R~
//================================================================================//~2816I~
class   CWxemain                                                   //~2827R~
{                                                                  //~2816I~
public :                                                           //~2816I~
#endif                                                             //~vXXEI~
//* public func *******************                                //~vXXEI~
	void scrruler(int Prow,int Pcol);                              //~v78BI~
    int  scrcsr(void);                                             //~v78BI~
	int  xxemain_iniput(WXEINIDATA *pwxei);                        //~vXXER~
	void xxemain_construct(void);                                  //~vXXEM~
	int  xxemain_init(int Pswinigetfail);                          //~vXXER~
	int  xxemain_onkeydown(UINT nChar, UINT nScan, UINT nFlags,char *Pstr,int Pstrlen);//~vXXER~
	int  xxemain_onchar(UINT nChar, UINT nScan, UINT nFlags,char *Pstr,int Plen);//~vXXER~
	int  xxemain_onkeyup(UINT nChar, UINT nsCAN, UINT nFlags,char *Pstr);//~vXXER~
	void xxemain_scrinvalidate(int Popt);                          //~vXXER~
#define SCRINVO_FULLDRAW       0x01       //fullscreen update      //~vXXEI~
#define SCRINVO_SYNCEXPOSE     0x02       //syncronously expose    //~vXXEI~
    int  xxemain_scrsetruler(int Ptype);                           //~v73tR~
	void exitmain();                                               //~vXXEM~
	void xxemain_kbdinit(void);                                    //~vXXEI~
	void xxemain_scrinit(void);                                    //~vXXEI~
	void xxemain_prtinit(void);                                    //~vXXEI~
	int  xxemain_createfont(void);                                 //~vXXEI~
	void xxemain_scrbgrect(void);                                  //~vXXER~
	int  xxemain_OnSize(int Pwidth,int Pheight);                   //~vXXER~
	int  xxemain_scrcancel(void);                                  //~vXXEI~
	int  xxemain_scrend(void);                                     //~vXXEI~
	int  xxemain_scrcmd(int Pfuncid,char *Pparm);                  //~vXXEI~
	int  xxemain_strcmd(char *Pcmd,char *Pparm);                   //~vXXEI~
	int  xxemain_scrpreedit(char *Pstr,int Plen,int Pcsrpos);      //~vXXER~
	int  xxemain_onfileopenwith(void);                             //~vXXEI~
	void xxemain_mouselbdown(UINT nFlags, CPoint point);           //~vXXER~
	int  xxemain_mouserbdown(UINT nFlags, CPoint point);           //~vXXER~
	int  xxemain_mousembdown(UINT nFlags, CPoint point);           //~v76cI~
	void xxemain_mouselbup(UINT nFlags, CPoint point);             //~vXXER~
	BOOL xxemain_onmousewheel(UINT nFlags, int Pdirection, CPoint pt);//~vXXER~
	BOOL xxemain_mouselbdblclk(UINT nFlags,CPoint pt);             //~vXXEI~
	int xxemain_setupdragfile(ULONG Pcmdparm1,ULONG Pcmdparm2);    //~v71xI~
#define SDFP2_SETUPREQ    0x01	//etupreq                          //~v71xR~
#define SDFP2_SETUPMSG    0x02  //msg to display uerrmsg           //~v71xI~
#define SDFP2_SETUPEND    0x04  //setup end                        //~v71xR~
	BOOL xxemain_ontimer(void *Ptimerid);                          //~vXXEI~
	BOOL xxemain_ontimeratcmd(UINT Ptimerid);                      //~vXXEI~
	void xxemain_mousemove(UINT nFlags, CPoint point);             //~vXXEI~
	int  xxemain_cpcopy(int Pcutsw);                               //~vXXEI~
	int  xxemain_cpselectall();                                    //~vbd2I~
	int  xxemain_cppaste(int Pinssw);                              //~vXXEI~
#define PASTE_TEXT_ONLY      0x100  //only effective when clipboard is not dropfile but text//~v689I~
#define PASTE_INSMODE        0x001  //paste-ins                    //~v689R~
#define PASTE_PASTEV         0x002  //pastev                       //~v689I~
	int  xxemain_mousedragbegin(void);                             //~v71sI~
	int  xxemain_mousedraggetdata(char **Plist);                   //~vXXER~
	int  xxemain_mousedragend(void);                               //~vXXER~
	BOOL xxemain_cpupdateselectall(void);                          //~vbd2R~
	BOOL xxemain_cpupdatecopy();                                   //~vXXEI~
	BOOL xxemain_cpupdatecut();                                    //~vXXEI~
	BOOL xxemain_cpupdatepaste();                                  //~vXXEI~
	BOOL xxemain_cpupdatepastev();                                 //~v66pI~
	int mouse_csrmovedbykbd(int Popt);                             //~va7DI~
	void xxemain_scrupdate(CDC *Ppdc,int Pprintsw);                //~vXXER~
	int  xxemain_OnOk(void);                                       //~vXXEI~
	void xxemain_scronok(int Pcpchngsw);                           //~vXXEI~
	int  xxemain_scrstrcmd(char *Pcmd,char *Pparm);                //~vXXER~
	int  xxemain_scrcmd(int Pfuncid,char *Pparm);                  //~vXXER~
	int  xxemain_prtajustcolrow(int Pscrtype,int Pformw,int Pformh,int Phdrftr,int Pcellw,int Pcellh,//~vXXEI~
							  int Pmaxlrecl,int Ptotlineno,int Plinenofw,int Pcol2p,//~vXXEM~
							  int *Ppcmaxcol,int *Ppcmaxrow,int Pchkpfontsz,//~vXXEM~
                              int Ppcellszhmax,                    //~vXXEM~
							  int *Ppdatamaxcol,int *Ppdatamaxrow);//~vXXEM~
	int  xxemain_onprepareprinting(int Pnotpreviewsw);             //~vXXEI~
	int  xxemain_onprint(void);                                    //~vXXEI~
	void xxemain_prtpreparedc(int Pcurpageno);                     //~vXXEI~
	void xxemain_onendprinting(void);                              //~vXXER~
//	void xxemain_prtdefaultmarginrect(RECT *Pprect);               //~vamkR~
// 	void xxemain_prtdefaultmarginrect(RECT *Pprect,gdouble *Pptblr);//~vamkR~
  	void xxemain_prtdefaultmarginrect(RECT *Pprect);               //~vamkI~
	int  xxemain_prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppcw,void **Pppfh,char *Poutfnm,//~vXXER~
					int *Pptotlineno,int *Ppmaxlrecl,int *Pplinenodigit,int *Ppcmaxlrecl,int *Pplnotype);//~vXXEM~
	int  xxemain_prtpreview(int Phcopysw,int Pcurpage);            //~vXXER~
	void xxemain_mousecpdrawpan(int Prow1,int Prow2,int Prow3);    //~vXXEI~
	void xxemain_onsetfocus(void);                                 //~v69bI~
	void xxemain_onkillfocus(void);                                //~v69bI~
	int xxemain_csrposchng(int Popt);                              //~va6yR~
	void afterprint(int Popt);                                     //~va8aR~
	BOOL onfileCHL(int Pcmd);                                      //~vbj2I~
//  int  drawtextstrHC(int Popt,char *Ppdata,char *Ppdbcs,int Plen,int Prow,int Pcol,char *Ppdddata,char *Ppdddbcs);//~vbApI~//~v7fzR~//~vbApR~//+v7fzR~
    int  drawtextstrHC(int Popt,char *Ppdata,char *Ppdbcs,int Plen,int Prow,int Pcol,char *Ppdddata,char *Ppdddbcs,int *Ppddlen);//+v7fzR~
//* public data *******************                                //~vXXEI~
EXT  int  Mxeinitsw;      	    //xe init called                   //~vXXER~
EXT  int  Mxxemaininitsw;      	//xxemain init end                 //~vX01R~
EXT  XXECOLOR Mbgcolor;                                            //~vXXER~
EXT  XXECOLOR Mrulercolor;                                         //~v73tI~
EXT  char Mrulerkey[4];        //3 letter                          //~v740I~
EXT  char Mcharinpup[64];                                          //~vXXER~
EXT  char Mcharinpdn[64];                                          //~vXXER~
EXT  char Mcharwp[64];                                             //~vXXER~
EXT  int  Mscrollctr;                                              //~vXXER~
EXT  int  Mscrolltimereventctr;	//time event counter               //~vXXER~
EXT  int  Mscrolltimer;                                            //~vXXER~
EXT  int  Mdblclicktimer;                                          //~vXXEI~
EXT  int  Mtypematicdelay;                                         //~v76eI~
EXT  int  Mtypematicinterval;                                      //~v76eI~
EXT  int  Mtypematicchkinterval;                                   //~v76eI~
EXT  int  Mtypematicintervalwait;                                  //~v76eR~
EXT  int  Mfontwidth;                                              //~vXXER~
EXT  int  Mfontheight;                                             //~vXXER~
EXT  int  Mmonospace;		//screen font is monospace             //~vXXEI~
EXT  int  Mmonospacepreviewfile; //file preview font is monospace  //~vXXEI~
EXT  int  Mfontoffsx,Mfontoffsy;	//offset in cell               //~vXXEI~
EXT  int  Mcellh;        //row height ,=fontheight if Mcellh0=0    //~vXXER~
EXT  int  Mcellw;         //col width                              //~vXXER~
EXT  int  Mcellh0;       //row height by option dlg                //~vXXEI~
EXT  int  Mcellw0;        //col width                              //~vXXEI~
EXT  BOOL Mttfont;            //row count of displayed scr         //~vXXER~
EXT  char Mfontstyle[80];                                          //~vXXER~
EXT  int  Museact;   		//use accelerator tbl                  //~vXXER~
EXT  int  Musemk ;   		//use menukey                          //~vXXER~
EXT  BOOL Mligature; 		//use ligature                         //~va1MR~
EXT  BOOL Mligaturereverse;  //temp toggle ligature                //~va3dR~
EXT  BOOL Mrctl  ;   		//use r-ctrl key                       //~vXXER~
EXT  BOOL Mfreecsr;  		//free cursor mode                     //~vXXER~
EXT  BOOL Mbeep;                                                   //~vXXER~
EXT  int  Mfulldrawsw;                                             //~vXXEI~
//  CWnd *Mpmainframe;	//mainframe window for set title           //~vXXER~
EXT  int  Mhcopysw;			//hardcopy or fileprint                //~vXXER~
EXT  int  Mprtcmaxcol;		//current file print max col per line  //~vXXER~
EXT  int  Mprtdatamaxcol;	//actual colomn for small font         //~vXXER~
EXT  int  Mprtmaxlrecl;		//max lrecl to cut line                //~vXXER~
EXT  int  Mprtcmaxlrecl;		//hex display width by pfh         //~vXXER~
EXT  int  Mprtcmaxrow;		//current file print max col per line  //~vXXER~
EXT  int  Mprtdatamaxrow;	//actual data row for small font       //~vXXER~
EXT  int  Mprtcurpage;   	//file print current pageno;start 0    //~vXXER~
EXT  int  Mprtlnotype;   	//hex or decimal                       //~vXXER~
//*pagesetup dialog data                                           //~vXXEM~
//EXT  char   	Mformtype[32];                                     //~vam0R~
//EXT  char   	Mprinter[32];                                      //~vam0R~
//EXT  char   	Mprinter_cupsdefault[32];                          //~vam0R~
EXT  char   	Mformtype[PPDMAXNAME];                             //~vam0I~
EXT  char   	Mprinter[PPDMAXNAME];                              //~vam0I~
EXT  char   	Mprinter_cupsdefault[PPDMAXNAME];                  //~vam0I~
EXT  char   	Mprtfontstyle[128];                                //~vXXER~
EXT  BOOL	MprintLigature;                                        //~vam7I~
EXT  BOOL	Mportlate;                                             //~vXXER~
EXT  BOOL	M2p;                                                   //~vXXER~
EXT  BOOL	Mheader;                                               //~vXXER~
EXT  BOOL	Mfooter;                                               //~vXXER~
EXT  BOOL	Mlinenumber;                                           //~vXXER~
EXT  BOOL	Mfiletime;                                             //~vXXER~
EXT  BOOL	Msystime;                                              //~vXXER~
EXT  BOOL	Mlandscape;                                            //~vXXER~
EXT  BOOL	MlandscapeR;  //rotation -1(-R90) or 1(R90)            //~vamkI~
EXT  BOOL	Mfullpage ;                                            //~vXXER~
EXT  BOOL	Mwwscrprt;                                             //~vXXER~
EXT  BOOL	Mchkpfontsz;                                           //~vXXER~
EXT  int		Mprtcol;                                           //~vXXER~
EXT  int		Mprtrow;                                           //~vXXER~
EXT  int		Mpfontszh,Mpfontszw;                               //~vXXER~
EXT  int		Mpcellszh,Mpcellszw;                               //~vXXER~
EXT  int		Mpcellszhmax;                                      //~vXXER~
EXT  int		Mdrawcellh,Mdrawcellw;                             //~vXXER~
EXT  int		Mprt2pcol;                                         //~vXXER~
EXT  int		Mmarginl;                                          //~vXXER~
EXT  int		Mmarginr;                                          //~vXXER~
EXT  int		Mmargint;                                          //~vXXER~
EXT  int		Mmarginb;                                          //~vXXER~
#ifdef GTKPRINT                                                    //~vamtI~
	EXT  int	MmarginshiftT;	//for paper position on printer folder;shift to top:top margin<0//~vamtR~
	EXT  int	MmarginshiftB;	//for paper position on printer folder;shift to bottom:bottom margin<0//~vamtI~
	EXT  int	MmarginshiftL;	//for paper position on printer folder;shift to left:left margin<0//~vamtR~
	EXT  int	MmarginshiftR;	//for paper position on printer folder;shift to right:right margin<0//~vamtI~
	EXT  int	Mmarginshift;	//shift requested                  //~vamtI~
#endif                                                             //~vamtI~
EXT  int     Mscrcmaxrow;           //current scr maxrow           //~vXXER~
EXT  int     Mscrcmaxcol;           //current scr maxcol           //~vXXER~
EXT  int  Mswkillfocus;                                            //~vXXER~
EXT  time_t  Msetfocustime;                                        //~vXXER~
EXT  int     Msetfocusmsec;                                        //~v69iR~
EXT  time_t  Mscrolllocktime;                                      //~v69bI~
EXT  int     Mscrolllockmsec;                                      //~v69iR~
EXT  int     Mscrolllocksw; //on from time of VK_SCROLL keyup to VK_SCROLL keydown//~v69iI~
EXT  int  	 Mscrheight;            //scr height  Y                //~vXXER~
EXT  int  	 Mscrwidth;             //scr width   X                //~vXXER~
EXT  WXEINTF Mwxeintf;                                             //~vXXEI~
EXT  CPoint  Mcellcopy1,Mcellcopy2;   //cut and paste sw           //~vXXEI~
EXT  int     Mcpcopypansw;         //cut on panel(not file data)   //~vXXEI~
EXT  int     Mlbdblclicksw;			//dbl click accepted to ignore next lb up//~vXXEI~
EXT  int     Mcpcopysw;            //cut and paste;copy sw         //~vXXEI~
EXT  int     Mcppastesw;          //paste done                     //~vXXEI~
EXT  int     Mcpblockmode;			                               //~v66pI~
EXT  CPoint  Mcpstart;                //mouse move start point     //~vXXEI~
EXT  CPoint  Mcpoldpos;  		 //cap box draw old pos            //~vXXEI~
EXT  int     Mlbposid;			    //for auto scroll by edge mouse//~vXXEI~
EXT  void   *Mdragplhs;			//drag drop plh slection range start//~vXXEI~
EXT  void   *Mdragpcw;			//to chk drag range by Shift+Lbutton//~vXXEI~
EXT  void   *Mdragedpcw;		//darg begin issued pcw            //~vXXEI~
EXT  char   *Mdraglist;			//dragged filename list            //~vXXEI~
EXT  int     Mdragacceptsw; 	//get data event occued            //~vXXER~
EXT  int     Mdroprc;       	//internal drag/drop drop rc       //~v685I~
EXT  int     Mdragtimeout;  	//from dragstart to dragend        //~vXXEI~
EXT  int     Mfloatmenusw;                                         //~vXXEI~
EXT  int     Mwinexth,Mwinextw;	//windows physical screen size     //~vXXEI~
EXT  int     Mprtmaxpage;         	//print total page             //~vXXER~
#define      MAXPAGERANGE   20                                     //~vXXEI~
EXT  int     Mpagerange[MAXPAGERANGE];  //print page range parm    //~vXXEI~
EXT  int     Mpagerangeno;	//print page range entry count         //~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
EXT  GnomeFont *Mpprtfont;                                         //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
EXT  int     Mprtfontascendant; //font baseline pos                //~vXXER~
EXT  BOOL    Mimageprtscr;  //print screen by image print          //~vXXEI~
EXT  int     Mpreviewmode;                                         //~vXXEI~
EXT  gdouble Mprevieworgx,Mprevieworgy,Mpreviewscalex,Mpreviewscaley;	//for preview//~vXXEI~
EXT  int  Mrulermode; //on from time of VK_SCROLL keyup to VK_SCROLL keydown//~v73tI~
#define  WXERULER_NONE  00                                         //~v73tM~
#define  WXERULER_V     01                                         //~v73tM~
#define  WXERULER_H     02                                         //~v73tM~
#define  WXERULER_VH    03                                         //~v73tM~
EXT 	int Mrulerrow,Mrulercol,Mrulermodeo;//old pos to erase prev cursor//~v73tI~
//EXT 	char Mlinedrawstat[MAXROW];//line draw status              //~va30R~
#define LDS_DRAWN       0x01   //drawn by update,full draw,combine/ligature//~va30R~
#define LDS_DRAWSKIP    0x02   //drawn skipped                     //~va30I~
#define LDS_COMBINE     0x10   //drawn line contains combining     //~va30I~
#define LDS_LIGATURE    0x20   //drawn line contains ligature      //~va30R~
#define LDS_DDFMT       0x40   //contains                          //~va30I~
                                                                   //~vXXEI~
//* priveate func ************************************             //~vXXER~
#ifdef GBL_XXEMAIN                                                 //~vXXEI~
//* private data ********************************                  //~vXXEI~
static  int  Mscrmaxrow;            //row count of displayed scr   //~vXXER~
static  int  Mscrmaxcol;            //col count                    //~vXXER~
//static  int  Mcpprevrow;           //cp move prev line           //~vXXER~
//static  CBrush *Mphollowbrush;                                   //~vXXER~
//static  CMenu  Mfloatmenu;                                       //~vXXER~
//static  CWxefile *Mpwxefile;                                     //~vXXER~
//static  char *Mptextbuff;                                        //~vXXER~
//static  char *Mpdbcsbuff;                                        //~vXXER~
static  int  Mnewimephrase;			//ime position set             //~vXXER~
static  int  Mimeonsw;			    //for auto scroll by edge mouse//~vXXER~
//static  void *Mdragpfh;			//to chk drag range by Shift+Lbutton//~vXXER~
#endif //GBL_XXEMAIN (private)                                     //~vXXEI~
//***************************************************              //~vXXEI~
                                                                   //~v55WI~
#define TID_SCROLLCHK     0x80     //csr pos is left edge when lbtn down//~3208I~
#define TID_SCLEFT        0x01     //csr pos is left edge when lbtn down//~3208R~
#define TID_SCRIGHT       0x02                                     //~3208R~
#define TID_SCTOP         0x04                                     //~3208R~
#define TID_SCBOTTOM      0x08                                     //~3208R~
#define TID_ATCMD       0x0100     //msg for AT cmd                //~v55WR~
#define TID_ATCMDTIMER  0x0200     //AT cmd timer interval msg     //~v55WR~
#define TID_ATCMDDRAW   0x0400     //to draw err msg               //~v55WR~
#define TID_ATCMDSLEEP  0x0800     //sleep timer                   //~v560I~
#define TID_SLEEPSUBCMP 0x1000     //sleep cmd in multi-cmd comp   //~v560I~
//#define TID_DRAGDROP    0x100000   //dragdrop interval to avoid drop on myself//~v63kR~
#define TID_RCTLKEY     0x010000     //rctl typematic support      //~v76eR~
                                                                   //~v55WI~
#ifdef __cplusplus                                                 //~v55WI~
	int  createfontlist(CComboBox *Ppcombo,char *Pcurfont);        //~v51hR~
//********************** public                                    //~2929R~
//*pagesetup end                                                   //~2B03I~
//***************************************************************  //~2824I~
private :                                                          //~2816I~
	void prtformsetup(int Pformid,int Plandscape);                 //~2B24I~
//********************** private                                   //~2929R~
    CFont *Mpfont;                                                 //~vXXEI~
    CFont *Mpfonts[WXEFONTSTYLE_MAX];	//normal,bold,italic,...   //~v780I~
    CView *Mpview;                                                 //~vXXEI~
    CBitmap *Mpbgbitmap;                                           //~2908R~
#endif //XXE                                                       //~vXXEI~
#ifdef __cplusplus                                                 //~vXXEI~
};                                                                 //~2816I~
                                                                   //~2831I~
#endif	//cplus_plus                                               //~2831I~
                                                                   //~2816I~
#endif	//HEADER_WXEMAIN                                           //~2827R~
