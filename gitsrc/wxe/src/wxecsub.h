//*CID://+vbziR~:                             update#=  122;       //~vbzhR~//+vbziR~
//*********************************************************************//~2818I~
//* wxecsub.h                                                      //~2818I~
//*********************************************************************//~2818I~
//vbzi:240201 (WXE)vbz4 had no effect. Reason is font=System. SelectFont was not done at scrinit.//+vbziI~
//vbzh:240201 (WXE)try GetCharWidth/GetABCCharWidths(for TrueTypeFont)//~vbzhI~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb4g:160801 (WXE)dirlist ligature on always like as vb37         //~vb4gI~
//vaz7:150109 ULPTR and ULONG (by C4244)                           //~vaz7I~
//vaz3:150106 (BUG)HANDLE is not ULONG but PVOID(8 byte)           //~vaz3I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va7Q:100907 (WXE:BUG)csr width did'nt change fo del-key dbcs<-->may be changed by shift//~va7QI~
//va74:100806 (BUG:WXE)reset va6v; write by locale code to use font codepage on setupdialog//~va74I~
//                     currentrly l2uany use base locale           //~va74I~
//va6v:000626 (WXE)use textoutW for locale code (more printable for any font slected)//~va6vI~
//va6u:000626 (WXE)ligature support for also locale code file      //~va6uI~
//va44:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~va44I~
//va42:100328 (WXE:BUG)tab,tab padding char is not visual,print alt char//~va42I~
//va3a:100205 (WXE)dbcs caret support                              //~va36I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70eI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68aI~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55DI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL                          //~v55cI~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v53t:031004 (WXE:BUG)not freed area exist                        //~v53tI~
//*********************************************************************//~v53tI~
#define INI_FILENAME   "wxew.ini"                                  //~2907R~
#define INI_ACRNM   INI_FILENAME "----!!\n"                        //~2907R~
                                                                   //~2907I~
#ifdef __cplusplus                                                 //~2818I~
extern  "C"                                                        //~2818I~
{                                                                  //~2818I~
#endif                                                             //~2818I~
                                                                   //~2818I~
	int enumfont(HDC Phdc,LOGFONT *Pelftbl,int Pmaxctr);           //~2818R~
//  int csubinit1(HWND Phwnd,HBITMAP *Phbmtbl);                    //~2914R~
	int csubinit1(HWND Phwnd);                                     //~2914I~
	int csubinit2(int Pcellh,int Pcellw);                          //~2901I~
	void csubinit3(HDC Phdc);                                      //~vbz4I~
	void csubinit4(HFONT Pfh);                                     //+vbziR~
//  int uscrresize(int Pwidth,int Pheight);                        //~2A14R~
	int usetcaret(int Pdbcssw,int Pheightrate,int Pcellw,int Pcellh,int Pfonth);//~2914I~
	int ushowcaret(void);                                          //~2831I~
	int uhidecaret(void);                                          //~2831I~
	int ugetcaretpos(int *Pprow,int *Ppcol);	//client axis      //~2831I~
//  int usetcaretpos(int Prow,int Pcol);                           //~2831I~//~va36R~
	int usetcaretpos(int Popt,int Prow,int Pcol);                  //~va36I~
    #define USCPO_DBCS1ST      0x01       //pos is dbcs1st         //~va36I~
	int usetcaretwidthchngchk(int Popt);                           //~va7QI~
	int uerrlast(char *Papi);                                      //~2907I~
//  int umsgbox(char *Ppmsg);                                      //~v66AR~
	int umsgbox(char *Ppmsg,int Pflag);                            //~v66AI~
	int umsgbox2(char *Ppmsg,char *Ptitle,int Pflag);              //~v66AI~
	int uerrmsgbox(char *,char *,... );                            //~2907I~
	int uerrmsgboxokcan(char * Pemsg,char * Pjmsg,... );           //~v66AI~
	int ugetinidata(void * /*PWXEINIDATA*/ Ppwxeini);              //~2907R~
	int uputinidata(void * /*PWXEINIDATA*/ Ppwxeini);              //~2907R~
//    int ugetinitsize(int *Pptype,int *Px,int *Py);               //~2A19R~
//    int ugetinitsize2(WINDOWPLACEMENT *Ppwp);                    //~2A19R~
	int ugetframesize(int *Pwidth,int *Pheight);                   //~2907I~
//  int ugetkbdshiftstatus(void);                                  //~v55cR~
    int ugetkbdshiftstatus(UINT nChar);                            //~v55cI~
	void uredrawcaret(void);                                       //~2922I~
	int  ugetcpath(char *Ppath);                                   //~2922I~
	int ugettempfname(int Popt,char *Ptempnam);                    //~2A12R~
	int usetupwd(void);                                            //~2928I~
	void *umemalloc(int Plen);                                     //~2929I~
	void umemfree(void *Paddr);                                    //~2929I~
	void uallocdummynewfile(char *Pfnm);                           //~2A12I~
	void ualloctrcfile(char *Pfnm);                                //~2A12I~
	DEVMODE *usetupprinter(int Pformid,int Plandscape);            //~2B24I~
	void *wxemalloc(int Plen);                                     //~v53tI~
	void wxefree(void *Paddr);                                     //~v53tI~
//  ULONG usetfocus(void);                                         //~vaz7R~
    ULPTR usetfocus(void);                                         //~vaz7I~
//	int upostmsg(UINT Pmsg,ULONG Pwparm, ULONG Plparm);            //~v54yI~//~vb4iR~
  	int upostmsg(UINT Pmsg,ULPTR Pwparm, ULPTR Plparm);            //~vb4iI~
//  int upostmsgp(UINT Pmsg,ULONG Pwparm, ULONG Plparm);           //~v55DI~//~vb4iR~
    int upostmsgp(UINT Pmsg,ULPTR Pwparm, ULPTR Plparm);           //~vb4iI~
	int usettimer(UINT Ptimerid,int Pintvlms,void *Pcallback);     //~v55ZI~
	int ukilltimer(UINT Ptimerid);                                 //~v560I~
	int uopenwith(char *Pfname,HINSTANCE *Phi);                    //~v55uI~
	int uinvalidate(int Pbgdraw);                                  //~v55DR~
	int  uopenclipboard(void);                                     //~v70eI~
	char *uglobalalloc(int Plen,void *Pphandle);                   //~v70eI~
//	int usetclipboard(ULONG Phandle,ULONG Ptype);                  //~v70eR~//~vafkR~
// 	int usetclipboard(ULPTR Phandle,ULONG Ptype);                  //~vaz3R~
  	int usetclipboard(HANDLE Phandle,ULONG Ptype);                 //~vaz3I~
	int ucloseclipboard(void);                                     //~v70eI~
	int uhtmlhelp(int Popt,HWND Pwnd,char *Ppopuptext,POINT Ppoint);//~v71AR~
#ifdef UTF8UCS2                                                    //~va20I~
int csubgetcsrposbf(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Pposc,int *Ppposa);//~va30R~
//int csubtextoutw(int Popt,HDC Phdc,int Px,int Py,char *Pddata,char *Pdbcs,int Plen,int Pcellw);//~va20R~//~vb4iR~
//int csubtextoutw(int Popt,int Plineopt,HDC Phdc,int Px,int Py,char *Pddata,char *Pdbcs,int Plen,int Pcellw,int Pfgcolor,int Pbgcolor);//~vb4iR~
int csubtextoutw(int Popt,int Plineopt,HDC Phdc,int Px,int Py,char *Pddata,char *Pdbcs,int Plen,int Pcellw);//~vb4iI~
#define CSTOWO_PRINT        0x01 //write a line at once            //~va20I~
#define CSTOWO_COMBINECHK   0x02 //chk combine                     //~va30I~
int csubtextoutw1(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen);//~va20I~
int csubchkdd(int Popt,char *Pdbcs,int Plen);                      //~va20I~
#ifdef AAA                                                         //~vaw1I~
int csubddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr);//~va30R~
#endif                                                             //~vaw1I~
#endif                                                             //~va20I~
int csubtextoutw1alt(int Popt,HDC Phdc,int Pxx,int Pyy,unsigned short Pucs);//~va42R~
//#define CSUBTOWAO_FORCE    0x01                                  //~va44R~
#define CSUBTOWAO_MASK       0xff	//opt for utfgetvisiblealt     //~va44I~
#define CSUBTOWAO_FORCE    0x0100                                  //~va44I~
//*******                                                          //~va6uI~
int  csubtextoutw_locale_ligature(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen);//~va6uI~
int csubtextoutw1_locale(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,int Plen);//~va6vI~
#define CSTOW1LO_LOCALEIFCVERR   0x01     //TextOut if translation err//~va6vI~
#define CSTOW1LO_NOTRANS         0x02     //TextOut without translation//~va74R~
#ifdef W32UNICODE                                                  //~vavzI~
//**************************************************************** //~vavzI~
	int csubtextoutWW(int Popt,HDC Phdc,int Pxx,int Pyy,UWCH *Pucs,int Pucsctr);//~vavzI~
#endif                                                             //~vavzI~
int csubGetCursorPos(int Popt,ULONG Pucs);                         //~vbz4I~
#ifdef __cplusplus                                                 //~2818I~
}                                                                  //~2818I~
#endif                                                             //~2818I~
