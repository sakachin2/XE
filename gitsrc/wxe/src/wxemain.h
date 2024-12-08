//*CID://+vbzMR~:                             update#=  271;       //~vbzMR~
//================================================================================//~v510I~
//vbzM:240408 (WXE) support hardcopy function                      //~vbzMI~
//vbt1:201210 WXE:when kbd changed to 2nd language DBCS chk should be changed//~vbt1I~
//vbj4:180425 click on selected line cmd history list-->"s"(set on under)//~vbj4I~
//vbj3:180425 double click on cmd history list-->"x"(exec on under)//~vbj3I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3k:100210 (BUG:WIN)vsplit line draw err(=1,=2,edit hdr line at right half)//~va3gI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v71B:061031 (WXE:Vista)use not sjis but default_charset for englishmode//~v71BI~
//v69Z:060726 (WXEXXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v69i:060523 (WXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v689:060328 (BUG)on dir list;s+lbdown/c+lbdown is for line selection not paste(ins/rep)//~v689I~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v63hI~
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
//================================================================================
#pragma once                                                       //~@@@@I~
#ifndef HEADER_WXEMAIN                                             //~2827R~
#define HEADER_WXEMAIN                                             //~2827R~
                                                                   //~2816I~
//#ifdef __cplusplus                                               //~@@@@R~
//    #include    <afxwin.h>                                       //~@@@@R~
//#endif                                                           //~@@@@R~
//================================================================================//~2818I~
//================================================================================//~2818I~
#define MAXCOL          240                                        //~2A08R~
#define MAXROW          200                                        //~2901M~
#define MAXCOLOR        16                                         //~2901M~
#define MAXIMECHARCTR   256                                        //~v79zI~
#define MAXIMECHARSZ    4                                          //~v79zI~
#define DEF_BGCOLOR     RGB(0,50,50)                               //~2A05R~
#define DEF_RULERCOLOR     RGB(0,100,100)                          //~v73tI~
#define DEF_RULERKEY    "\x01\x02\x03"  //F1,F2,F3 for ruler key   //~v740I~
#define DEF_DOSFONT     "Terminal"  //dosapp.fon(cp437) or app932.fon//~2A05I~
#define DEF_PRTFONTSTYLE  "Terminal"  //dosapp.fon(cp437) or app932.fon//~v51hI~
#define DEF_FONTSTYLE   DEF_DOSFONT                                //~2928R~
#define DEF_FONTSTYLE2  "System"                                   //~2B30I~
#define DEF_FONTSZH     20                                         //~2915R~
#define DEF_FONTSZW     10                                         //~2818M~
#define DEF_ROWH        20                                         //~2915R~
#define DEF_COLW        10                                         //~2915R~
#define DEF_SCRROW      25                                         //~2915I~
#define DEF_SCRCOL      80                                         //~2915I~
#define DEF_OTHERCHARSET 254                                       //~3102I~
//#define DEF_CHARSET     SHIFTJIS_CHARSET	//for NT               //~v71BR~
//#define DEF_CHARSET     DEF_OTHERCHARSET	//For W95              //~3111R~
#define DEF_CHARSET       DEFAULT_CHARSET	//1 on wingdi.h        //~v71BR~
#define DEF_SCROLLCTR   3                                          //~2A13I~
#define DEF_SCROLLINITWAIT 3                                       //~v51uI~
#define DEF_SCROLLTIMER 200    //ms                                //~v510M~
//*page setup                                                      //~2B03I~
#define DEF_FORMSIZE    "A4"                                       //~2B03I~
#define DEF_A4_COL       0	//0 means by max lrecl                 //~2B09R~
#define DEF_A4_ROW       0  //0 means bu maxcol and cell h/w rate  //~2B09R~
#define DEF_COLFORLRECL0 80 //maxcol for maxlrecl=0                //~2B09I~
#define DEF_CELLSZHMAX   14 //cell height maxlimum                 //~v62WI~
#define DEF_2PCOL        4                                         //~2B04I~
#define PRTSCRID        "PrtScr"                                   //~2B09I~
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
#ifdef __cplusplus                                                 //~2901I~
                                                                   //~2901I~
#define COL(x)      min( MAXCOL-1, ((x-BORDERMARGIN)/Mcellw) )     //~2A07R~
#define ROW(y)      min( MAXROW-1, ((y-BORDERMARGIN)/Mcellh) )     //~2A07R~
#define COLCTR(width)   min( MAXCOL, ((width) -BORDERMARGIN)/Mcellw )//~2A23R~
#define ROWCTR(height)  min( MAXROW, (((height)-BORDERMARGIN-max(Mcellh-Mfontheight,0))/Mcellh) )//~2A23R~
#define CWINWIDTH(col)   ((col)*Mcellw+BORDERMARGIN)               //~2A23R~
#define CWINHEIGHT(row)  ((row)*Mcellh+BORDERMARGIN+max(Mcellh-Mfontheight,0)) //client window height//~2A23R~
#define XX(col)         ((col)*Mcellw+BORDERMARGIN)                //~2901R~
#define YY(row)         ((row)*Mcellh+BORDERMARGIN)                //~2901R~
#define TEXTDATA(row,col)    (Mwxeintf.WXEItext+(row)*MAXCOL+(col))//~2A05R~
#define TEXTDBCS(row,col)    (Mwxeintf.WXEIdbcs+(row)*MAXCOL+(col))//~2A05R~
#define TEXTATTR(row,col)    (Mwxeintf.WXEIattr+(row)*MAXCOL+(col))//~2A05R~
#define TEXTSTYLE(row,col)   (Mwxeintf.WXEIsynstyle+(row)*MAXCOL+(col))//~v780R~
#define TEXTLINEOPT(row,col)   (Mwxeintf.WXEIlineopt+(row)*MAXCOL+(col))//~vb4iI~
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
#endif  //C++                                                      //~2901I~
//================================================================================//~2831I~
typedef struct _WXEINTF {                                          //~2831M~
//*wxe-->xe                                                        //~2831I~
						int   WXEImaxrow;	//screen max row       //~2831I~
						int   WXEImaxcol;	//screen max row       //~2831I~
						USHORT WXEIpallette[MAXCOLOR];	//dos colorno//~2905R~
						UINT   WXEIpalrgb[MAXCOLOR];	//dos colorno//~2905I~
//                      int   WXEIctlkey;   //ctl key down         //~2909R~
//                      int   WXEIshiftkey; //shift key down       //~2909R~
//*xe-->wxe                                                        //~2831I~
						UCHAR  *WXEItext;		//scr text tbl,gotten by xe//~2831R~
						USHORT *WXEIattr;		//scr attr tbl,gotten by xe//~2831R~
						UCHAR  *WXEIlineupdate; //scr line update flag//~2831R~
						UCHAR  *WXEIdbcs;		//scr dbcsid tbl,gotten by xe//~2831R~
						UCHAR  *WXEIsynstyle;  	//scr style tbl for syntax highlight//~v780R~
						int    *WXEIlineopt;  	//ligature/combine option line by line//~vb4iR~
						int    *WXEIsynrgb;     //rgb table for syntax highlight//~v780I~
						int     WXEIcurmovesw;  //cusor moved sw   //~2831I~
						int   WXEIcsrhstart;	//csr height start(0-->7)//~2831I~
						int   WXEIcsrhend;      //csr height end(0-->7)//~2831I~
						int   WXEIcsrvisible;	//csr visible      //~2831I~
						int   WXEIcsrchangesw;	//csr type changed //~2831R~
						int   WXEIcsrvisiblechangesw;	//csr visibility changed//~2914I~
						int   WXEIcsrmovesw;	//csr moved        //~2831I~
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
                        int   WXEIxetermsw;    //xeterm requested  //~v55WI~
                        int   WXEIstatus;   //comm flag with xe    //~v682I~
#define WXEIS_DRAWMENU        0x00000001    //draw menue required by reset func//~v682I~
#ifdef UTF8UCS2                                                    //~va20I~
#define WXEIS_PRTUTF8         0x00000010    //fileprint for UTF8 file//~va20I~
#define WXEPRINT_UTF8MODE()  (Mwxeintf.WXEIstatus & WXEIS_PRTUTF8) //~va20I~
#define WXEIS_PRTVHEX         0x00000020    //fileprint vhex mode  //~va20I~
#define WXEIS_TEMPLIGATURE    0x00000040    //ligature sw by A+";" key//~va3gI~
#define WXEIS_LIGATURE        0x00000080    //ligature sw by disalog chkbox//~va3gI~
#endif                                                             //~va20I~
#define WXEIS_PRTEBC          0x00000100    //fileprint for EBC file//~va80I~
#define WXEPRINT_EBCFILE()   (Mwxeintf.WXEIstatus & WXEIS_PRTEBC)  //~va80I~
#define WXEIS_PRTEBCBYUCS     0x00000200    //fileprint for EBC file//~va80I~
#define WXEPRINT_EBCBYUCS()  (Mwxeintf.WXEIstatus & WXEIS_PRTEBCBYUCS)//~va80I~
                        int   WXEIimestat; //widechar kbd stat     //~v79zR~
#define WXEIIMES_WIDEAPI       0x01         //CJK support          //~v79zR~
#define WXEI_ISWIDEAPI()  (Mwxeintf.WXEIimestat & WXEIIMES_WIDEAPI)//~v79zR~
                        USHORT WXEIimeucs[MAXIMECHARCTR]; //ime unicode char from IME//~v79zR~
                        int    WXEIimeucsctr;   //ime output ucs string char count//~v79zI~
                        int    WXEIimeucsoffs;  //read count from ucs char count//~v79zI~
                        UCHAR  WXEIunpdispchar[4];  //copy of Gunpdispchar[4]//~vb3qR~
                    } WXEINTF;                                     //~2831M~
typedef WXEINTF *PWXEINTF;                                         //~2831M~
#define WXEINTFSZ (sizeof(WXEINTF))                                //~2831M~
                                                                   //~2831I~
#ifdef __cplusplus                                                 //~2831I~
//================================================================================//~2816I~
//                                                                 //~2818R~
//================================================================================//~2816I~
class   CWxemain                                                   //~2827R~
{                                                                  //~2816I~
public :                                                           //~2816I~
    CWxemain();                                                    //~2827R~
    ~CWxemain();                                                   //~2827R~
	int init(CView *Pview);                                        //~2922R~
	int onkeyup  (UINT nChar, UINT nRepCnt, UINT nFlags);          //~2827R~
	int onkeydown(UINT nChar, UINT nRepCnt, UINT nFlags);          //~2827R~
	int onchar   (UINT nChar, UINT nRepCnt, UINT nFlags);          //~2908I~
	int kbdkeyin (int Popt,UINT nChar, UINT nRepCnt, UINT nFlags); //~2908I~
	int syskeyproc(UINT Pmessage,WPARAM wParam,LPARAM lParam);     //~2827R~
	void mouselbdown(UINT nFlags, CPoint point);                   //~2824I~
	void mouserbdown(UINT nFlags, CPoint point);                   //~2825I~
	void mouselbup(UINT nFlags, CPoint point);                     //~2824I~
	void mousemove(UINT nFlags, CPoint point);                     //~2824I~
	int  mouse_csrmovedbykbd(int Popt);                            //~va7DI~
	BOOL mouselbdblclk(UINT nFlags,CPoint pt);                     //~3102I~
	BOOL mouseappcmd(int Pappcmdid);                               //~v69fI~
	int mousescrollbar(int Pmsg,int Pscrollcode);                  //~v69gI~
	void onsetfocus(CWnd* pOldWnd);                                //~2922I~
	void onkillfocus(CWnd* pNewWnd);                               //~2922I~
	int scrcancel(void);                                           //~3102I~
	int scrend(void);                                              //~3102I~
	int scrcmd(int Pfuncid,char *Pparm);                           //~3102I~
	int strcmd(char *Pcmd,char *Pparm);                            //~v51wR~
	int draw(CDC *Pdc,CWxeDoc *Pdoc);                              //~2817R~
	int OnOk(void);                                                //~2817I~
	int OnSize(UINT Ptype,int Px,int Py);                          //~2818I~
	int cpcopy(int Pcutsw);                                        //~2A03R~
	int cpselectall();                                             //~vbd2I~
	int cppaste(int Pinssw);                                       //~2A03R~
#define PASTE_TEXT_ONLY      0x100  //only effective when clipboard is not dropfile but text//~v689I~
#define PASTE_INSMODE        0x001  //only effective when clipboard is not dropfile but text//~v689I~
#define PASTE_PASTEV         0x002  //pastev                       //~v689I~
	int  iniput(WXEINIDATA *pwxei);                                //~2A20R~
	BOOL cpupdateselectall(void);                                  //~vbd2R~
	BOOL onfileCHL(int Pcmd);                                      //~vbj2M~//~vbj3R~
	BOOL onfileCHLdblclick();                                      //~vbj3R~
	BOOL onfileCHLdblclick(int Pcmd);                              //~vbj3I~
	BOOL chkCHLselect(CPoint Ppoint);                              //~vbj4I~
	BOOL selectedCHL(UINT Pflag,CPoint Ppoint);                    //~vbj4I~
	BOOL cpupdatecopy();                                           //~2824R~
	BOOL cpupdatecut();                                            //~2824R~
	BOOL cpupdatepaste();                                          //~2824R~
	BOOL cpupdatepastestd();                                       //~v66hR~
	CFont *createfontsub(int Pcharset,char *Pfontstyle,int Ptruetype,//~2B23R~
						int Pfontheight,int Pfontwidth,int Poutprec);//~2B23I~
	BOOL onmousewheel(UINT nFlags, short zDelta, CPoint pt);       //~2A13I~
	int  printdlg();                                               //~@@@@R~
	void setupprintrange(CDC* Ppdc);                               //~2A27R~
//  int  onprepareprinting(CPrintInfo *pInfo);                     //~@@@@R~
    int  onprepareprinting(int Pprintsw);                          //~@@@@I~
//  void prtpreparedc(CDC *Ppdc,CPrintInfo *pInfo);                //~@@@@R~
    void prtpreparedc(CDC *Ppdc,CPrintInfo *pInfo,int Ppage);      //~@@@@I~
	void onendprinting(CDC* pDC, CPrintInfo* pInfo);               //~2B04I~
//  void afterprint(void);                                         //~v51wI~//~va8aR~
    void afterprint(int Popt);                                     //~va8aI~
	int  prtpreview(CDC *Pdc,RECT *Pdrawrect,int Phcopysw,int Pcurpage);//~2C14R~
//  int  prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppfh,char *Poutfnm,//~v627R~
#ifdef W32UNICODE                                                  //~vavzI~
int CWxemain::prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppcw,void **Pppfh,char *Poutfnm,UWCH *PoytfnmW,int Pbuffsz,//~vavzI~
#else                                                              //~vavzI~
    int  prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Ppcw,void **Pppfh,char *Poutfnm,//~v627R~
#endif                                                             //~vavzI~
					int *Pptotlineno,int *Ppmaxlrecl,int *Pplinenodigit,int *Ppcmaxlrecl,int *Pplnotype);//~2C07R~
	int  prtajustcolrow(int Pscrtype,int Pformw,int Pformh,int Phdrftr,int Pcellw,int Pcellh,//~v51hR~
							  int Pmaxlrecl,int Ptotlineno,int Plinenofw,int Pcol2p,//~v51hI~
							  int *Ppcmaxcol,int *Ppcmaxrow,int Pchkpfontsz,//~v51hR~
                              int Ppcellszhmax,                    //~v62WI~
							  int *Ppdatamaxcol,int *Ppdatamaxrow);//~v51hI~
	int  prtgetformsz(int Plandscape,char *Pform,int *Ppw,int *Pph);//~2B09I~
	int prtgetformtype(char ***Ppformtbl);                         //~2B09I~
//  int kbdimectl(HWND Phwnd,UINT Pmsgid);                         //~v79zR~
	int kbdimectl(HWND Phwnd,UINT Pmsgid,WPARAM wParam,LPARAM lParam);//~v79zR~
//  int kbdime_getchar(int Popt,ULONG Phimc,UINT Pmsgid,WPARAM wParam,LPARAM lParam);//~@@@@R~
    int kbdime_getchar(int Popt,HIMC Phimc,UINT Pmsgid,WPARAM wParam,LPARAM lParam);//~@@@@I~
	int ontimer(UINT Ptimerid);                                    //~3208I~
	void  scrpeninit(int Pinitsw);                                 //~v73tR~
#endif                                                             //~v55WI~
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
                                                                   //~v55WI~
#ifdef __cplusplus                                                 //~v55WI~
	int  ontimeratcmd(UINT Ptimerid);                              //~v55WI~
	int  createfontlist(CComboBox *Ppcombo,char *Pcurfont);        //~v51hR~
	int  onfileopenwith(void);                                     //~v55uM~
//*WTL printing***                                                 //~@@@@I~
	bool printpage(UINT nPage, HDC hDC);   //rc:False=Cancel       //~@@@@I~
	bool isvalidpage(UINT nPage);   //rc:False=Cancel              //~@@@@I~
//********************** public                                    //~2929R~
    COLORREF Mbgcolor;                                             //~2905I~
    COLORREF Mrulercolor;                                          //~v73tI~
    char Mrulerkey[4];                                             //~v740R~
    int  Mscrollctr;                                               //~2A13I~
    int  Mscrolltimereventctr;	//time event counter               //~v51uI~
    int  Mscrolltimer;                                             //~v510I~
    int  Mfontwidth;                                               //~2817I~
    int  Mfontheight;                                              //~2817I~
    int  Mcellh;        //row height                               //~2901R~
    int  Mcellw;         //col width                               //~2901R~
    int  Mcharset;       //charset for createfont                  //~2915I~
    int  Mothercharset;  //other charset editbox value             //~3102I~
    BOOL Mttfont;            //row count of displayed scr          //~2915M~
    BOOL Mligature;            //row count of displayed scr        //~va3gI~
    char Mfontstyle[80];                                           //~2817R~
    int  Museact;   		//use accelerator tbl                  //~3103I~
    int  Musemk ;   		//use menukey                          //~3105I~
    BOOL Mrctl  ;   		//use r-ctrl key                       //~v55cI~
    BOOL Mfreecsr;  		//free cursor mode                     //~v55qI~
    BOOL Mbeep;                                                    //~v55uI~
    CDC *Mpmemdc;			//memory dc                            //~2818I~
    CWnd *Mpmainframe;	//mainframe window for set title           //~2A14R~
    int  Mhcopysw;			//hardcopy or fileprint                //~2B23R~
    int  Mprtcmaxcol;		//current file print max col per line  //~2B02I~
    int  Mprtdatamaxcol;	//actual colomn for small font         //~v51hI~
    int  Mprtmaxlrecl;		//max lrecl to cut line                //~2C01I~
    int  Mprtcmaxlrecl;		//hex display width by pfh             //~2C01I~
    int  Mprtcmaxrow;		//current file print max col per line  //~2B09I~
    int  Mprtdatamaxrow;	//actual data row for small font       //~v51hI~
    int  Mprtcurpage;   	//file print current pageno;start 0    //~2B02I~
    int  Mprtlnotype;   	//hex or decimal                       //~2C07I~
//*pagesetup dialog data                                           //~2B03I~
	char   	Mformtype[32];                                         //~2B09R~
	char   	Mprtfontstyle[32];                                     //~v51hI~
	BOOL	Mportlate;                                             //~2B03M~
	BOOL	M2p;                                                   //~2B03I~
	BOOL	Mheader;                                               //~2B03I~
	BOOL	Mfooter;                                               //~2B03M~
	BOOL	Mlinenumber;                                           //~2B03I~
	BOOL	Mfiletime;                                             //~2B03M~
	BOOL	Msystime;                                              //~2B03I~
	BOOL	Mlandscape;                                            //~2B03I~
	BOOL	Mfullpage ;                                            //~2B30I~
	BOOL	Mwwscrprt;                                             //~2B10I~
	BOOL	Mchkpfontsz;                                           //~v51hI~
	int		Mprtcol;                                               //~2B03R~
	int		Mprtrow;                                               //~2B03I~
	int		Mpfontszh,Mpfontszw;                                   //~v51hR~
	int		Mpcellszh,Mpcellszw;                                   //~v51hI~
	int		Mpcellszhmax;                                          //~v62WI~
	int		Mdrawcellh,Mdrawcellw;                                 //~v51hI~
	int		Mprt2pcol;                                             //~2B04I~
	int		Mmarginl;                                              //~2B03I~
	int		Mmarginr;                                              //~2B03I~
	int		Mmargint;                                              //~2B03I~
	int		Mmarginb;                                              //~2B03M~
    int     Mscrcmaxrow;           //current scr maxrow            //~2B10I~
    int     Mscrcmaxcol;           //current scr maxcol            //~2B10I~
    int  Mswkillfocus;                                             //~v63rM~
    time_t  Msetfocustime;                                         //~v63rR~
    time_t  Msetfocusmsec;                                         //~v63rI~
    time_t  Mscrolllocktime;                                       //~v69bI~
    time_t  Mscrolllockmsec;                                       //~v69bI~
    int  Mcpcopysw;            //cut and paste;copy sw  (public:accsessed by static func)//~v69ZR~
    int  Mcpcopypansw;         //cut on panel(not file data)       //~v69ZI~
//*pagesetup end                                                   //~2B03I~
//***************************************************************  //~2824I~
private :                                                          //~2816I~
	void scrinit();                                                //~2901R~
	void scrupdate(CDC *Ppmemdc,int Pprintsw);                     //~2A20I~
	int  iniget();        //ini file get                           //~2907R~
	void requestRestart();                                         //~vbt1I~
	int  createfont();                                             //~2901R~
	void scronok(int Pcpchngsw);                                   //~2929R~
	int  xeinitcall();                                             //~2831R~
	void optligatureinit(int Popt);                                //~vb4qI~
	int  xeerrchk();                                               //~2901I~
//  int  lineput(CDC *Ppmemdc,int Pprintsw,int Prow);              //~va3gR~
    int  lineput(int Popt,CDC *Ppdc,int Pprintsw,int Prow);        //~va3gI~
	#define LPO_CSRBREAK     0x01	//strput split at csr pos      //~va3gI~
	#define LPO_CPU8         0x02	//csr is on CPU8 text          //~va3gI~
	#define LPO_VHEX         0x04	//data line of vhex line       //~va3tI~
	#define LPO_VHEXMASK   0xff00 	                               //~va3tI~
	#define LPO_VHEXSHIFT       8                                  //~va3tI~
	#define LPO_GETVHEXPOS(opt) (((opt) & LPO_VHEXMASK)>>LPO_VHEXSHIFT)//~va3tI~
//  int  strput(CDC *Ppmemdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw);//~v780R~
	int  strput(CDC *Ppmemdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw);//~v780I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define  SPO_PRINT         0x01       //printsw                //~va20I~
	#define  SPO_DDFMT         0x02       //data/dbcs              //~va20I~
#endif                                                             //~va20I~
	void scrinvalidate();                                          //~2908R~
	void scrbgrect(CDC *Ppmemdc);                                  //~2A20R~
    int  scrsetruler(int Ptype);                                   //~v73tR~
	void scrruler(CDC *Ppmemdc,int Prow,int Pcol);                 //~v73tR~
	void scrrulererase(int Prow,int Pcol);                         //~v73tR~
	void exitmain();                                               //~2908I~
#ifdef UTF8UCS2                                                    //~va20R~
	int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2,int *Pplen);//~va20R~
#else                                                              //~va20R~
	int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2);//~2A05I~
#endif                                                             //~va20R~
	void cpdrawpan(int Prow1,int Prow2,int Prow3);                 //~2A05I~
	int  scrcsr(void);                                             //~2914I~
	int  onprint(CDC *Pdc,CWxeDoc *Pdoc);                          //~2A20I~
	int  prtscr(CDC *Pdc,CFont *Ppfont,                            //~2B24I~
			int Ppreviewwidth,int Ppreviewheight,int Pprevieworgx,int Pprevieworgy);//~2B24I~
	int  prtfile(CDC *Pdc,CFont *Ppfont,int Ppreviewwidth,int Ppreviewheight,int Pmarginx,int Pmarginy);//~2B23R~
	void prtviewporthcopy(CDC* Pdc,                                //~2B24R~
			int Ppreviewwidth,int Ppreviewheight,int Pprevieworgx,int Pprevieworgy);//~2B24I~
	void prtviewportfile(CDC *Pdc,int Pwidth,int Pheight,int Pmarginx,int Pmarginy);//~2B24R~
	void prtmarginrect(CDC *Pdc,RECT *Pprect);                     //~2B23R~
	int  prttextout(int Ppreviewsw,CDC *Pdc,int Pyy,char *Pdata,int Plen);//~2B24I~
#ifdef W32UNICODE                                                  //~vavzI~
int  CWxemain::prttextoutwHeader(CDC *Pdc,int Pyy,char *Pdata,int Plen,int Ppos,int Plclen,UWCH *PfnmW);//~vavzR~
#endif                                                             //~vavzI~
#ifdef UTF8UCS2                                                    //~va20I~
	int  prttextoutw(int Ppreviewsw,CDC *Pdc,int Pyy,int Pcol,char *Pdata,char *Pdbcs,int Plen,int Plinenofldlen);//~va20R~
    #define PRTTOWO_PREVIEW    0x01                                //~va80I~
    #define PRTTOWO_HHEX       0x02                                //~va80I~
    #define PRTTOWO_VHEXLINE   0x04   //when M2P                   //~va80R~
    #define PRTTOWO_LRECLMASK  0xff00                              //~va80I~
    #define PRTTOWO_LRECLMASKSHIFT  8                              //~va80I~
#endif                                                             //~va20I~
//  void prtformsetup(int Pformid,int Plandscape);                 //~@@@@R~
    void prtformsetup(LPDEVMODE Ppdevmode,int Pformid,int Plandscape);//~@@@@I~
	int  mousescrollchk(int Pcol,int Prow);                        //~3208R~
	void mousedragfile(int Pdragopt,void *Ppcw,void* Pplh);        //~v63hR~
	int  mousedodrag(void *Ppcw,int Popt);                         //~v63iR~
	int  mousedragcopy(void * Ppcw,HGLOBAL Phmem);                 //~v63iI~
	int  mousedragcopychk(void);                                   //~v63iI~
	int  chkrulerkey(UINT nChar);                                  //~v740I~
	BOOL cppastedropchk(int Popt);                                 //~v686I~
#define DNDDODRAG_COPY 0x01                                        //~v63iI~
//    scrcombinechk(int Popt,int Pcol,int Plen,int *Ppstarterr,int *Ppendcombine);//not used//~@@@@R~
	int updateFileMenu(int Popt);                                  //~vbdnI~
//********************** private                                   //~2929R~
    CBitmap *Mpbgbitmap;                                           //~2908R~
	WXEINTF Mwxeintf;                                              //~2831I~
    int  Mfulldrawsw;                                              //~2901R~
    int  Mscrmaxrow;            //row count of displayed scr       //~2915I~
    int  Mscrmaxcol;            //col count                        //~2824R~
    int  Mscrheight;            //scr height  Y                    //~2901R~
    int  Mscrwidth;             //scr width   X                    //~2901R~
//  int  Mcpcopysw;            //cut and paste;copy sw             //~v69ZR~
//  int  Mcpcopypansw;         //cut on panel(not file data)       //~v69ZR~
    int  Mcpprevrow;           //cp move prev line                 //~2A01I~
    int  Mcppastesw;          //paste done                         //~2824R~
    int  Mxeinitsw;      	    //xe init called                   //~2914I~
    CPoint Mcellcopy1,Mcellcopy2;   //cut and paste sw             //~2A14I~
    CPoint Mcpoldpos;  		 //cap box draw old pos                //~2A05I~
    CPoint Mcpstart;                //mouse move start point       //~2824R~
    CFont *Mpfont;                                                 //~2817R~
    CFont *Mpfonts[WXEFONTSTYLE_MAX];	//normal,bold,italic,...   //~v780R~
    CBrush *Mphollowbrush;                                         //~2825I~
    CMenu  Mfloatmenu;                                             //~2825I~
    int    Mfloatmenusw;                                           //~2825I~
    CView *Mpview;                                                 //~2817R~
    CDocument *Mpdoc;                                              //~2817I~
    CWxefile *Mpwxefile;                                           //~2817I~
    char Mcharinpup[64];                                           //~2816R~
    char Mcharinpdn[64];                                           //~2816I~
    char Mcharwp[64];                                              //~2816I~
    char *Mptextbuff;                                              //~2824R~
    char *Mpdbcsbuff;                                              //~2824R~
    int  Mwinexth,Mwinextw;		//windows physical box             //~2A27R~
    char Mprtfnm[_MAX_PATH];	//filename to print                //~2B02I~
#ifdef W32UNICODE                                                  //~vavzI~
    UWCH MprtfnmW[_MAX_PATHWC];	//filename to print                //~vavzR~
#endif                                                             //~vavzI~
    char Mprtftime[32];			//filetime to print                //~2B03I~
    char Mprtsystime[32];		//current time to print            //~2B03I~
    int  Mprttype;         	//print screen type 'D'/'F'            //~2B30R~
    int  Mprtmaxpage;         	//print total page                 //~2B02I~
    char *Mprtlinework;       	//print line work to edit lineno   //~2B17R~
    char *Mprtpagework;       	//print page work to edit 2p form  //~2B17I~
    int  Mprtlinenosz;       	//lineno fldsz                     //~2B04I~
    int  Mprtclineno;   	    	//current lineno               //~2B04I~
    char Mprtlinenoedit[8];  	//lineno edit fmt                  //~2B04I~
    int  Mnewimephrase;			//ime position set                 //~3104I~
    int  Mlbdblclicksw;			//dbl click accepted to ignore next lb up//~3202R~
    int  Mlbposid;			    //for auto scroll by edge mouse    //~3208I~
    int  Mimeonsw;			    //for auto scroll by edge mouse    //~3208I~
    CFont *Mpprtfont;                                              //~v51hI~
    void *Mdragpcw;			//to chk drag range by Shift+Lbutton   //~v63pR~
    void *Mdragpfh;			//to chk drag range by Shift+Lbutton   //~v63pI~
    void *Mdragplhs;			//drag drop plh slection range start//~v63pI~
//  void* Mdragpcw;				//drag started pcw                 //~v63kR~
    int  Mcpblockmode;                                             //~v66hR~
    int  Mdragstatus;                                              //~v685I~
    int  Mscrollcode;                                              //~v69gI~
    int  Mscrolllocksw; //on from time of VK_SCROLL keyup to VK_SCROLL keydown//~v69iR~
    int  Mrulermode; //on from time of VK_SCROLL keyup to VK_SCROLL keydown//~v73tR~
#define  WXERULER_NONE  00                                         //~v73tR~
#define  WXERULER_V     01                                         //~v73tR~
#define  WXERULER_H     02                                         //~v73tR~
#define  WXERULER_VH    03                                         //~v73tR~
	int Mrulerrow,Mrulercol,Mrulermodeo;//old pos to erase prev cursor//~v73tI~
    CPen Mrulerpen;                                                //~v73tI~
    int  Maltkeyscancode;                                          //~va3DI~
    CPrinter Mprinter;     //WTL save current printer status       //~@@@@I~
    CDevMode Mdevmode;     //WTL                                   //~@@@@I~
    CPrintJob Mprintjob;   //WTL                                   //~@@@@I~
    int Mprinterinit;                                              //~@@@@R~
    int Mformid;                                                   //~@@@@I~
#define MAX_PAGERANGE  10                                          //~@@@@M~
    PRINTPAGERANGE Mpageranges[MAX_PAGERANGE];                     //~@@@@I~
    int Mpagerangeno;                                              //~@@@@I~
};                                                                 //~2816I~
                                                                   //~2831I~
#endif	//cplus_plus                                               //~2831I~
#ifdef __cplusplus                                                 //~vbzMI~
	#define EXTC extern "C"                                        //~vbzMI~
#else                                                              //~vbzMI~
	#define EXTC                                                   //~vbzMI~
#endif                                                             //~vbzMI~
	EXTC int wxescr_m2u(int Popt,WXEINTF *Pwxei,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr);//~vbzMR~
	EXTC int wxescr_u2altch(int Popt,WXEINTF *Pwxei,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr);//~vbzMR~
                                                                   //~2816I~
#endif	//HEADER_WXEMAIN                                           //~2827R~
