//*CID://+vb4AR~:                             update#=  454;       //~vb4AR~
//***************************************************************************//~2818I~
//* c subrtn for wxe                                               //~2818I~
//***************************************************************************//~2818I~
//vb4A:160815 if UNICOMB UNPR mode and LIGATURE ON, write altch just after base char using GetTextExtentPoint32W//~vb4zI~
//vb4z:160815 if UNICOMB SPLIT mode and LIGATURE ON, write combining char just after base char using GetTextExtentPoint32W//~vb4zR~
//vb4j:160806 (W32)OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay)//~vb4jI~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb3x:160621 ffff is treated as dbcsspace on dirlist. tabdisplay set dbcs space to ffff/()//~vb3xI~
//vb3s:160618 del vb3r because it effect also edit panel           //~vb3sI~
//vb3r:160618 print dbcsspace by altch for dirlist                 //~vb3rI~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vb3m:160613 (WXE:BUG)utfdd2u set unprintable to sbcs-altch,but wxe use chsz=2//~vb3mI~
//vb2W:160404 W32 64 compiler warning                              //~vb2WI~
//vb2T:160403 (Win)wxe:not valid dbcs siaply when non-ligature mode  with parameter /Czh_CN.54936//~vb2TI~
//            (Setlocale fail if MB_CHAR_MAX>2, Microsoft says to use not MBCS but UNICODE version.)//~vb2TI~
//vb2Q:160320 apply ulib:v6BW to wxe; write ucs4 at once when ligature on//~vb2QI~
//vb2P:160320 apply ulib:v6uB to wxe; set ucs4 is not combinable   //~vb2PI~
//vb2K:160314 (W32:BUG) need to consider 3/4 byte DBCS             //~vb2KI~
//vb2H:160307 (W32)UWCHART cut ucs4                                //~vb2HI~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\
//vaz7:150109 ULPTR and ULONG (by C4244)                           //~vaz7I~
//vaz3:150106 (BUG)HANDLE is not ULONG but PVOID(8 byte)           //~vaz3I~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//va7Q:100907 (WXE:BUG)csr width did'nt change fo del-key dbcs<-->may be changed by shift//~va7QI~
//va74:100806 (BUG:WXE)reset va6v; write by locale code to use font codepage on setupdialog//~va74I~
//                     currentrly l2uany use base locale           //~va74I~
//va6v:000626 (WXE)use textoutW for locale code (more printable for any font slected)//~va6vI~
//va6u:000626 (WXE)ligature support for also locale code file      //~va6uI~
//va5G:100521 (WXE:BUG)for dd fmt display for U8/lc mixed string on pan//~va5GI~
//            nul was printed by no printable altchar              //~va5GI~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va44:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~va44I~
//va42:100328 (WXE:BUG)tab,tab padding char is not visual,print alt char//~va42I~
//va3u:100221 (BUG)not unconditionaly set green for combining char when ligature+split mode//~va3uI~
//            If so so,sub string split at it,then ligature in effective.//~va3uI~
//            (Split altchar is Linux console only)                //~va3uI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va3a:100205 (WXE)dbcs caret support                              //~va36I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va20I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v77x:080117 Bug report by M.J                                    //~v77xI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70eI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68iI~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//v65e:050728 (WXE)version chki bypass(format chk only)(XXE use version on About dlg)//~v65eI~
//v63m:050510 (WXE)draw screen between exe cmd file                //~v63mI~
//v56h:040404 (WXE)ignore setcaretpos r.c because it may occur when windows z-order is changed//~v56hI~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL                          //~v55cI~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v53yI~
//v53t:031004 (WXE:BUG)not freed area exist                        //~v53tI~
//***************************************************************************//~v53tI~
#include <time.h>                                                  //~2907I~
#include <stdio.h>                                                 //~2907I~
#include <stdlib.h>                                                //~2907I~
#include <string.h>                                                //~2907I~
//*************************************************************    //~2907I~
#include <windows.h>                                               //~2818R~
                                                                   //~2907I~
#include "ulib.h"                                                  //~2907I~
#include "ualloc.h"                                                //~2907R~
#include "uque.h"                                                  //~2929I~
#include "uerr.h"                                                  //~2907I~
#include "utrace.h"                                                //~2914I~
#include "ufile.h"                                                 //~2922I~
#include "ufile2.h"                                                //~2923I~
#include "ufile4.h"                                                //~2923I~
#ifdef UTF8UCS2                                                    //~va20I~
#include "udbcschk.h"                                              //~va20R~
#include "uvio.h"                                                  //~va20I~
#include "uviom.h"                                                 //~va20I~
#include "utf.h"                                                   //~va36I~
#include "utf22.h"                                                 //~va20I~
#endif                                                             //~va20I~
                                                                   //~2818I~
#include "xe.h"                                                    //~2929I~
                                                                   //~2929I~
#include "wxedef.h"                                                //~2923I~
#include "wxemain.h"                                               //~2901I~
#include "wxecsub.h"                                               //~2831I~
#include "wxexei.h"                                                //~2907I~
//***************************************************************************//~2818I~
#define COL(x)          ((x-BORDERMARGIN)/Scellw)                  //~2831I~
#define ROW(y)          ((y-BORDERMARGIN)/Scellh)                  //~2831I~
#define XX(col)         ((col)*Scellw+BORDERMARGIN)                //~2831I~
#define YY(row)         ((row)*Scellh+BORDERMARGIN)                //~2831I~
    //***************************************************************************//~vb4iR~
static int Sstylectr=0;                                            //~2818I~
//static Selfmaxctr=0;                                               //~2818I~//~vafhR~
static int Selfmaxctr=0;                                           //~vafhI~
static HWND  Shwnd;                                                //~2831I~
//static HBITMAP Shbm_caret[4];                                    //~2914R~
static int   Scellh,Scellw;                                        //~2831I~
static int   Scdbcssw,Scheightrate,Scfonth,Scrow,Sccol;            //~2922R~
static char  Swdtemp[_MAX_PATH];                                   //~2B30R~
//***************************************************************************//~2907I~
int  iniacrnmchk(FILE *Pfh);                                       //~2907I~
int  iniacrnmput(FILE *Pfh);                                       //~2907I~
int  usetupwd(void);                                               //~2A12I~
int  usetupwdtemp(void);                                           //~2A12I~
int csubtextoutWcombining_notcombinemode(int Popt,HDC Phdc,int Pxx,int Pyy,WUCS *Pucs,int Pucsctr);//~vb4AI~
//***************************************************************************//~2831I~
//init static                                                      //~2831I~
//***************************************************************************//~2831I~
int csubinit1(HWND Phwnd)                                          //~2914R~
{                                                                  //~2831I~
	Shwnd=Phwnd;                                                   //~2831I~
//    memcpy(Shbm_caret,Phbmtbl,sizeof(Shbm_caret));               //~2914R~
    return 0;                                                      //~2831I~
}                                                                  //~2831I~
//***************************************************************************//~2901I~
//init static                                                      //~2901I~
//***************************************************************************//~2901I~
int csubinit2(int Pcellh,int Pcellw)                               //~2901I~
{                                                                  //~2901I~
    Scellh=Pcellh;                                                 //~2901I~
    Scellw=Pcellw;                                                 //~2901I~
    return 0;                                                      //~2901I~
}                                                                  //~2901I~
//***************************************************************************//~2818I~
//int CALLBACK effp(LOGFONT *Pelf,TEXTMETRIC *Pntm,DWORD Pft,LPARAM Plp);//~2817R~
//int (CALLBACK *effp)(const LOGFONT *Pelf,const TEXTMETRIC *Pntm,DWORD Pft,LPARAM Plp);//~2817R~
//	FONTENUMPROC effp;                                             //~2817R~
//***************************************************************************//~2817M~
//*callback function from EnumFontFamilies to chk font name with /F parm//~2817M~
//parm1:ENUMLOGFONT ptr                                            //~2817M~
//parm2:NEWTEXTMETRICS ptr                                         //~2817M~
//parm3:font type: x01:RASTER_FONTTYPE                             //~2817M~
//                 x02:DEVICE_FONTTYPE                             //~2817M~
//                 x04:TRUETYPE_FONTTYPE                           //~2817M~
//parm4:user data ptr                                              //~2817M~
//ret  :rc    4:not found                                          //~2817M~
//**************************************************************************//~2817M~
int CALLBACK effp(const LOGFONT *Pelf,const TEXTMETRIC *Pntm,DWORD Pft,LPARAM Plp)//~2817I~
{                                                                  //~2817M~
	LOGFONT *pelftbl;	//4 candidit parm to callback func         //~2817I~
//*****************************                                    //~2817M~
	pelftbl=(LOGFONT*)Plp;                                         //~2817I~
//  if (!(Pntm->tmPitchAndFamily & TMPF_FIXED_PITCH))  //1:var,0:fixed//~2824R~
//  	if (*Pelf->lfFaceName!='@')                                //~2915R~
    		if (Sstylectr<Selfmaxctr)                              //~2818R~
            {                                                      //~2C03I~
//UTRACEP("%-32s;height=%2d,width=%2d,ori=%d,charset=%3d,outprec=%d,quarilt=%2d,pitch=%2x\n",//~v56hR~
//            Pelf->lfFaceName,                                    //~v56hR~
//            Pelf->lfHeight,                                      //~v56hR~
//            Pelf->lfWidth,                                       //~v56hR~
//            Pelf->lfOrientation,                                 //~v56hR~
//            Pelf->lfCharSet,                                     //~v56hR~
//            Pelf->lfOutPrecision,                                //~v56hR~
//            Pelf->lfQuality,                                     //~v56hR~
//            Pelf->lfPitchAndFamily);                             //~v56hR~
        		pelftbl[Sstylectr++]=*Pelf;	                       //~2817R~
            }                                                      //~2C03I~
	return 1;                                                      //~2817M~
}//effp                                                            //~2817M~
//**************************************************************** //~2817I~
//*                                                                //~2817I~
//**************************************************************** //~2817I~
int enumfont(HDC Phdc,LOGFONT *Pelftbl,int Pmaxctr)                //~2818R~
{                                                                  //~2817I~
//********************************                                 //~2817I~
	Selfmaxctr=Pmaxctr;                                            //~2818I~
    Sstylectr=0;                                                   //~2818I~
//  EnumFontFamilies(Phdc,NULL,&effp,(long)Pelftbl);//NULL:no specific family name//~2818R~//~vafkR~
    EnumFontFamilies(Phdc,NULL,&effp,(ULPTR)Pelftbl);//NULL:no specific family name//~vafkR~
    return Sstylectr;                                              //~2818R~
}                                                                  //~2817I~
////****************************************************************//~2A14R~
////*rc:ret code                                                   //~2A14R~
////****************************************************************//~2A14R~
//int uscrresize(int Pwidth,int Pheight)                           //~2A14R~
//{                                                                //~2A14R~
//    int xx,yy,cx,cy;                                             //~2A14R~
//    WINDOWPLACEMENT pwp;                                         //~2A14R~
//    WINDOWPLACEMENT wp;                                          //~2A14R~
//    HWND  hwnd;                                                  //~2A14R~
//    RECT rect;                                                   //~2A14R~
////********************************                               //~2A14R~
//    memset(&wp,0,sizeof(wp));                                    //~2A14R~
//    wp.length=sizeof(wp);                                        //~2A14R~
//    memcpy(&pwp,&wp,sizeof(wp));                                 //~2A14R~
//    if (!(hwnd=GetParent(Shwnd)))                                //~2A14R~
//        return uerrlast("GetParent");                            //~2A14R~
//    if (!GetWindowPlacement(hwnd,&pwp))                          //~2A14R~
//        return uerrlast("GetWindowPlacement");                   //~2A14R~
//    if (!GetWindowPlacement(Shwnd,&wp))                          //~2A14R~
//        return uerrlast("GetWindowPlacement");                   //~2A14R~
//    GetClientRect(Shwnd,&rect);                                  //~2A14R~
//    GetClientRect(hwnd,&rect);                                   //~2A14R~
//    cx=wp.rcNormalPosition.left+Pwidth;                          //~2A14R~
//    cy=wp.rcNormalPosition.top+Pheight;                          //~2A14R~
//    xx=pwp.rcNormalPosition.left;                                //~2A14R~
//    yy=pwp.rcNormalPosition.top;                                 //~2A14R~
//    if (!MoveWindow(hwnd,xx,yy,cx,cy,TRUE))//TRUE:re-ddraw       //~2A14R~
//        return uerrlast("MoveWindow");                           //~2A14R~
//    return 0;                                                    //~2A14R~
//}//uscrresize                                                    //~2A14R~
//**************************************************************** //~2907I~
//*rc:ret code                                                     //~2907I~
//**************************************************************** //~2907I~
//int ugetframesize(int *Pwidth,int *Pheight)                      //~2A19R~
//{                                                                //~2A19R~
////    HWND  hwnd;                                                //~2A19R~
////    RECT rect;                                                 //~2A19R~
////********************************                               //~2A19R~
////    if (!(hwnd=GetParent(Shwnd)))                              //~2A19R~
////        return uerrlast("GetParent");                          //~2A19R~
////    if (!GetClientRect(hwnd,&rect))                            //~2A19R~
////        return uerrlast("GetClientRect of parent hwnd");       //~2A19R~
////    *Pwidth=rect.right+WINDOW_FRAME_OVERHEAD_WIDTH;            //~2A19R~
////    *Pheight=rect.bottom+WINDOW_FRAME_OVERHEAD_HEIGHT;         //~2A19R~
////UTRACEP("frame size bef:right=%d,bottom=%d\n",rect.right,rect.bottom);//~2A19R~
//UTRACEP("frame size bef:right=%d,bottom=%d\n",*Pwidth,*Pheight); //~2A19R~
//    *Pwidth+=WINDOW_FRAME_OVERHEAD_WIDTH;                        //~2A19R~
//    *Pheight+=WINDOW_FRAME_OVERHEAD_HEIGHT;                      //~2A19R~
//UTRACEP("frame size aft:right=%d,bottom=%d\n",*Pwidth,*Pheight); //~2A19R~
//    return 0;                                                    //~2A19R~
//}//ugetframesize                                                 //~2A19R~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int usetcaret(int Pdbcssw,int Pheightrate,int Pcellw,int Pcellh,int Pfonth)//~2914R~
{                                                                  //~2831I~
	int rc,ww,hh;                                                  //~2831I~
//********************************                                 //~2831I~
	Scdbcssw=Pdbcssw;	//save for setcaretpos failed              //~2922I~
	Scheightrate=Pheightrate;                                      //~2922I~
	Scfonth=Pfonth;                                                //~2922I~
	ww=(Pdbcssw+1)*Pcellw;                                         //~2914R~
//  hh=Pcellh*Pheightrate/100+max(0,Pcellh-Pfonth);    //% of heifht for windows//~v53yR~
    hh=Pcellh*Pheightrate/100+min(max(0,Pcellh-Pfonth),1);    //% of heifht for windows//~v53yI~
    if (hh<2 && Pcellh>4)                                          //~v53yI~
        hh=2;       //minimum 2 pixel                              //~v53yI~
//  rc=CreateCaret(Shwnd,(HBITMAP)1,ww,hh);		//0:black,1:gray   //~2914R~
    rc=CreateCaret(Shwnd,(HBITMAP)NULL,ww,-hh);		//0:black,1:gray//~2914R~
//  rc=CreateCaret(Shwnd,Shbm_caret[0],0,0);		//0:black,1:gray//~2914R~
	if (!rc)                                                       //~2831I~
		rc=uerrlast("CreateCaret");                                //~2914I~
    else                                                           //~2831I~
        rc=0;                                                      //~2831I~
UTRACEP("usetcaret dbcssw=%d,new ww=%d,hh=%d\n",Pdbcssw,ww,hh); //~va36I~//~va74R~
                                                                   //~va36I~
    return rc;                                                     //~2831I~
}                                                                  //~2831I~
//**************************************************************** //~2922I~
//*rc:ret code                                                     //~2922I~
//**************************************************************** //~2922I~
void uredrawcaret(void)                                            //~2922I~
{                                                                  //~2922I~
//********************************                                 //~2922I~
	usetcaret(Scdbcssw,Scheightrate,Scellw,Scellh,Scfonth);	//recreate//~2922I~
//  usetcaretpos(Scrow,Sccol);                                     //~2922I~//~va36R~
	usetcaretpos(Scdbcssw,Scrow,Sccol);                            //~va36R~
	ushowcaret();                                                  //~2922I~
    return;                                                        //~2922I~
}                                                                  //~2922I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int ushowcaret(void)                                               //~2831I~
{                                                                  //~2831I~
	int rc;                                                        //~2831I~
//********************************                                 //~2831I~
	rc=ShowCaret(Shwnd);                                           //~2831I~
	if (!rc)                                                       //~2831I~
		rc=uerrlast("ShowCaret");                                  //~2914I~
    else                                                           //~2831I~
        rc=0;                                                      //~2831I~
    UTRACEP("ushow caret rc=%d\n",rc);                             //~va74I~
    return rc;                                                     //~2831I~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int uhidecaret(void)                                               //~2831I~
{                                                                  //~2831I~
	int rc;                                                        //~2831I~
//********************************                                 //~2831I~
	rc=HideCaret(Shwnd);                                           //~2831I~
	if (!rc)                                                       //~2831I~
		rc=uerrlast("HideCaret");                                  //~2914I~
    else                                                           //~2831I~
        rc=0;                                                      //~2831I~
    return rc;                                                     //~2831I~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int ugetcaretpos(int *Pprow,int *Ppcol)	//client axis              //~2831I~
{                                                                  //~2831I~
	POINT pt;                                                      //~2831I~
    int rc;                                                        //~2831I~
//********************************                                 //~2831I~
	rc=GetCaretPos(&pt);                                           //~2831I~
	if (!rc)                                                       //~2831I~
		rc=uerrlast("GetCaretPos");                                //~2914I~
    else                                                           //~2831I~
    {                                                              //~2831I~
    	*Pprow=ROW(pt.y);                                          //~2831R~
    	*Ppcol=COL(pt.x);                                          //~2831R~
        rc=0;                                                      //~2831I~
    }                                                              //~2831I~
    return rc;                                                     //~2831I~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
//int usetcaretpos(int Prow,int Pcol)                                //~2831I~//~va36R~
int usetcaretpos(int Popt,int Prow,int Pcol)                       //~va36R~
{                                                                  //~2831I~
    int rc,x,y,rcl;                                                //~2922R~
    int swdbcs;                                                    //~va36I~
//********************************                                 //~2831I~
	Scrow=Prow;     //for the case redraw by getforcus             //~2922I~
	Sccol=Pcol;                                                    //~2922I~
	swdbcs=(Popt & USCPO_DBCS1ST)!=0;                              //~va36I~
	if (swdbcs!=Scdbcssw)                                          //~va36R~
		usetcaret(swdbcs,Scheightrate,Scellw,Scellh,Scfonth);	//recreate//~va36I~
	y=YY(Prow+1);                                                  //~2914R~
	x=XX(Pcol);                                                    //~2914R~
//UTRACEP("setcaretpos:(%d,%d)=(%d,%d)\n",Prow,Pcol,y,x);          //~v56hR~
	rc=SetCaretPos(x,y);                                           //~2831I~
	if (!rc)                                                       //~2831I~
    {                                                              //~2922I~
//  	rcl=GetLastError();                                        //~v560R~
//        if (!rcl)       //after ctl+O popup msg,setcaretpos fail //~2922R~
//        {                                                        //~2922R~
//            usetcaret(Scdbcssw,Scheightrate,Scellw,Scellh,Scfonth); //recreate//~2922R~
//            rc=SetCaretPos(x,y);                                 //~2922R~
//        }                                                        //~2922R~
//        if (!rc)                                                 //~2922R~
//        {                                                        //~2922R~
			rcl=GetLastError();                                    //~2922I~
//UTRACEP("setcaretpos:rc=%d-%d\n",rc,rcl);                        //~v56hR~
//			uerrmsgbox("SetCaretPos (%d,%d)=(%d,%d) failed rc=%d,",0,//~v56hR~
//						Prow,Pcol,y,x,rcl);                        //~v56hR~
//        }                                                        //~2922R~
    }                                                              //~2922I~
    else                                                           //~2831I~
    {                                                              //~2831I~
        rc=0;                                                      //~2831I~
    }                                                              //~2831I~
    UTRACEP("usetcaretpos rc=%d,row=%d,col=%d\n",rc,Prow,Pcol);    //~va74I~
    return rc;                                                     //~2831I~
}                                                                  //~2831I~
//**************************************************************** //~va7QI~
//chak dbcs status changed under caretpos not changed condition    //~va7QI~
//*rc:ret code                                                     //~va7QI~
//**************************************************************** //~va7QI~
int usetcaretwidthchngchk(int Popt)                                //~va7QI~
{                                                                  //~va7QI~
    int swdbcs,rc;                                                 //~va7QR~
//********************************                                 //~va7QI~
    UTRACEP("usetcaretwidthchngchk row=%d,col=%d\n",Scrow,Sccol);  //~va7QR~
	swdbcs=(Popt & USCPO_DBCS1ST)!=0;                              //~va7QI~
	if (swdbcs==Scdbcssw)                                          //~va7QI~
    	return 0;                                                  //~va7QI~
	rc=usetcaret(swdbcs,Scheightrate,Scellw,Scellh,Scfonth);	//recreate//~va7QR~
    UTRACEP("usetcaretwidthchngchk rc=%d,dbcs=%d\n",rc,swdbcs);    //~va7QI~
    return rc;                                                     //~va7QI~
}                                                                  //~va7QI~
//**************************************************************** //~2901I~
//*rc:ret code                                                     //~2901I~
//**************************************************************** //~2901I~
//int umsgbox(char *Ppmsg)                                         //~v66AR~
int umsgbox(char *Ppmsg,int Pflag)                                 //~v66AI~
{                                                                  //~2901I~
	int rc;                                                        //~v66AI~
//********************************                                 //~2901I~
//  MessageBox(Shwnd,Ppmsg,NULL,MB_OK);                            //~v66AR~
//  return 0;                                                      //~v66AR~
    rc=MessageBox(Shwnd,Ppmsg,NULL,Pflag);                         //~v66AI~
    if (rc==IDOK||rc==IDYES)                                       //~v66AI~
    	return 0;                                                  //~v66AI~
    return rc;                                                     //~v66AI~
}                                                                  //~2901I~
//**************************************************************** //~v66AI~
//*rc:ret code                                                     //~v66AI~
//**************************************************************** //~v66AI~
int umsgbox2(char *Ppmsg,char *Ptitle,int Pflag)                   //~v66AI~
{                                                                  //~v66AI~
	int rc;                                                        //~v66AI~
//********************************                                 //~v66AI~
    rc=MessageBox(Shwnd,Ppmsg,Ptitle,Pflag);                       //~v66AI~
    if (rc==IDOK||rc==IDYES)                                       //~v66AI~
    	return 0;                                                  //~v66AI~
    return rc;                                                     //~v66AI~
}                                                                  //~v66AI~
//**************************************************************** //~2907I~
//*rc:ret code                                                     //~2907I~
//**************************************************************** //~2907I~
int uerrmsgbox(char * Pemsg,char * Pjmsg,... )                     //~2907R~
{                                                                  //~2907I~
//  ULONG *parm;                                                   //~2907R~//~vafkR~
    ULPTR         parm[UERRMSG_MAXPARM];                           //~vafkI~
	char *pmsg;                                                    //~2907I~
//********************************                                 //~2907I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~2907I~//~vafkR~
    UGETSTDARG(ULPTR,parm,Pjmsg,UERRMSG_MAXPARM);                  //~vafkI~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                         //~2907R~
//	umsgbox(pmsg);                                                 //~v66AR~
	umsgbox(pmsg,MB_OK);                                           //~v66AI~
    ugeterrmsg();		//clear msg saved                          //~2928I~
    return 4;                                                      //~2B02R~
}//uerrmsgbox                                                      //~2907R~
//**************************************************************** //~v66AI~
//*rc:ret code                                                     //~v66AI~
//**************************************************************** //~v66AI~
int uerrmsgboxokcan(char * Pemsg,char * Pjmsg,... )                //~v66AI~
{                                                                  //~v66AI~
//  ULONG *parm;                                                   //~v66AI~//~vafkR~
    ULPTR         parm[UERRMSG_MAXPARM];                           //~vafkI~
	char *pmsg;                                                    //~v66AI~
    int rc;                                                        //~v66AI~
//********************************                                 //~v66AI~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v66AI~//~vafkR~
    UGETSTDARG(ULPTR,parm,Pjmsg,UERRMSG_MAXPARM);                  //~vafkI~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                         //~v66AI~
	rc=umsgbox2(pmsg,"wxe",MB_OKCANCEL);                           //~v66AR~
    ugeterrmsg();		//clear msg saved                          //~v66AI~
    return rc;                                                     //~v66AI~
}//uerrmsgboxokcan                                                 //~v66AR~
//**************************************************************** //~v68iI~
//*rc:ret code                                                     //~v68iI~
//**************************************************************** //~v68iI~
//ULONG usetfocus(void)                                            //~vaz7R~
ULPTR usetfocus(void)                                              //~vaz7I~
{                                                                  //~v68iI~
//  ULONG hwnd;	                                                   //~v68iR~//~vafkR~
    ULPTR hwnd;                                                    //~vafkI~
//********************************                                 //~v68iI~
//  hwnd=(ULONG)SetFocus(Shwnd);	//set focus to wxeview         //~v68iR~//~vafkR~
    hwnd=(ULPTR)SetFocus(Shwnd);	//set focus to wxeview         //~vafkI~
    return hwnd;	//previous focus window or null if err         //~v68iI~
}//usetfocus                                                       //~v68iR~
//**************************************************************** //~v53yI~
//*rc:ret code                                                     //~v53yI~
//**************************************************************** //~v53yI~
int upostmsg(UINT Pmsg,ULONG Pwparm,ULONG Plparm)                  //~v53yR~
{                                                                  //~v53yI~
//********************************                                 //~v53yI~
	if (PostMessage(Shwnd,Pmsg,(WPARAM)Pwparm,(LPARAM)Plparm))     //~v53yI~
    	return 0;                                                  //~v53yI~
    return GetLastError();                                         //~v53yI~
}//upostmsg                                                        //~v53yI~
//**************************************************************** //~v55DI~
//*rc:ret code                                                     //~v55DI~
//**************************************************************** //~v55DI~
int upostmsgp(UINT Pmsg,ULONG Pwparm,ULONG Plparm)                 //~v55DI~
{                                                                  //~v55DI~
	HWND hwnd;                                                     //~v55DI~
//********************************                                 //~v55DI~
	hwnd=GetParent(Shwnd);                                         //~v55DR~
	if (PostMessage(hwnd,Pmsg,(WPARAM)Pwparm,(LPARAM)Plparm))      //~v55DI~
    	return 0;                                                  //~v55DI~
    return GetLastError();                                         //~v55DI~
}//upostmsgp                                                       //~v55DI~
//**************************************************************** //~v55ZI~
//*rc:ret code                                                     //~v55ZI~
//**************************************************************** //~v55ZI~
int usettimer(UINT Ptimerid,int Pintvlms,void *Pcallback)          //~v55ZI~
{                                                                  //~v55ZI~
//********************************                                 //~v55ZI~
    SetTimer(Shwnd,Ptimerid,Pintvlms,Pcallback);//schedule timer   //~v55ZI~
    return GetLastError();                                         //~v55ZI~
}//usettimer                                                       //~v55ZI~
//**************************************************************** //~v560I~
//*rc:ret code                                                     //~v560I~
//**************************************************************** //~v560I~
int ukilltimer(UINT Ptimerid)                                      //~v560I~
{                                                                  //~v560I~
//********************************                                 //~v560I~
    KillTimer(Shwnd,Ptimerid);                                     //~v560I~
    return GetLastError();                                         //~v560I~
}//ukilltimer                                                      //~v560I~
//**************************************************************** //~v55WI~
//*invalidate rect                                                 //~v55WI~
//*rc:ret code                                                     //~v55WI~
//**************************************************************** //~v55WI~
int uinvalidate(int Pbgdraw)                                       //~v55WR~
{                                                                  //~v55WI~
    int rc;                                                        //~v63mI~
//********************************                                 //~v55WI~
//  return InvalidateRect(Shwnd,NULL,Pbgdraw);                     //~v63mR~
    rc=InvalidateRect(Shwnd,NULL,Pbgdraw);                         //~v63mR~
    rc+=UpdateWindow(Shwnd);                                       //~v63mI~
    return rc;                                                     //~v63mI~
}//ureqredraw                                                      //~v55WI~
//**************************************************************** //~2907I~
//*rc:ret code                                                     //~2907I~
//**************************************************************** //~2907I~
int uerrlast(char *Papi)                                           //~2907I~
{                                                                  //~2907I~
    int rc;                                                        //~2907I~
    char *pmsg;                                                    //~2907I~
//********************************                                 //~2907I~
	rc=GetLastError();                                             //~2907I~
	pmsg=uerrsprintf("%s failed by rc=%d (%08x)",0,                //~2907R~
					Papi,rc,rc);                                   //~2907I~
//  umsgbox(pmsg);                                                 //~v66AR~
    umsgbox(pmsg,MB_OK);                                           //~v66AI~
    if (!rc)                                                       //~2A05I~
    	rc=-1;                                                     //~2A05I~
    return rc;                                                     //~2907I~
}//uerrmsgbox                                                      //~2907I~
////===============================================================================//~2A19R~
////get initial scr size                                           //~2A19R~
////===============================================================================//~2A19R~
//int ugetinitsize(int *Pptype,int *Px,int *Py)                    //~2A19R~
//{                                                                //~2A19R~
//    WXEINIDATA wxei;                                             //~2A19R~
////************************************                           //~2A19R~
//    usetupwd();                                                  //~2A19R~
//    if (ugetinidata(&wxei))                                      //~2A19R~
//    {                                                            //~2A19R~
//        *Px=DEF_FRAMEWIDTH;                                      //~2A19R~
//        *Py=DEF_FRAMEHEIGHT;                                     //~2A19R~
//        *Pptype=0;                                               //~2A19R~
//        UTRACEP("getini failed");                                //~2A19R~
//        return 1;                                                //~2A19R~
//    }                                                            //~2A19R~
//    *Pptype=wxei.WXEINIonsizetype;                               //~2A19R~
//    if (wxei.WXEINIframewidth)                                   //~2A19R~
//        *Px=wxei.WXEINIframewidth;                               //~2A19R~
//    if (wxei.WXEINIframeheight)                                  //~2A19R~
//        *Py=wxei.WXEINIframeheight;                              //~2A19R~
//    UTRACEP("getini type=%d,x=%d,y=%d\n",                        //~2A19R~
//            wxei.WXEINIonsizetype,                               //~2A19R~
//            wxei.WXEINIframewidth,                               //~2A19R~
//            wxei.WXEINIframeheight);                             //~2A19R~
//    return 0;                                                    //~2A19R~
//}//ugetinitsize                                                  //~2A19R~
////===============================================================================//~2A19R~
////get initial scr size                                           //~2A19R~
////===============================================================================//~2A19R~
//int ugetinitsize2(WINDOWPLACEMENT *Ppwp)                         //~2A19R~
//{                                                                //~2A19R~
//    WXEINIDATA wxei;                                             //~2A19R~
////************************************                           //~2A19R~
//    usetupwd();                                                  //~2A19R~
//    ugetinidata(&wxei);                                          //~2A19R~
//    *Ppwp=wxei.WXEINIwp;                                         //~2A19R~
//    UTRACED("initsize2",&wxei.WXEINIwp,44);                      //~2A19R~
//    return 0;                                                    //~2A19R~
//}//ugetinitsize2                                                 //~2A19R~
//===============================================================================//~2907I~
//get ini file on work dir                                         //~2907I~
//===============================================================================//~2907I~
int ugetinidata(PWXEINIDATA Ppwxeini)                              //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907R~
	char fnm[_MAX_PATH];                                           //~2928I~
    WXEINIDATA wei;                                                //~2907I~
    FILE *fh;                                                      //~2907I~
//************************************                             //~2907I~
    sprintf(fnm,"%s\\%s",Gworkdir,INI_FILENAME);                   //~2B30R~
    memset(Ppwxeini,0,sizeof(WXEINIDATA));                         //~2907I~
	fh=fopen(fnm,"rb");                                            //~2907I~
    if (!fh)                                                       //~2907I~
		return 1;                                                  //~2907I~
    rc=iniacrnmchk(fh);                                            //~2907I~
    if (!rc)                                                       //~2907I~
    {                                                              //~2907I~
		len=fread(&wei,1,sizeof(wei),fh);                          //~2907R~
    	if (len!=sizeof(wei))                                      //~2907I~
        	rc=4;                                                  //~2907I~
//        if (wei.WXEINIver!=WXE_VER)                              //~v65eR~
//        {                                                        //~v65eR~
//            uerrmsgbox("Old Version ini file(%s);Delete then restart.",0,//~v65eR~
//                        fnm);                                    //~v65eR~
//            rc=2;                                                //~v65eR~
//        }                                                        //~v65eR~
    }                                                              //~2907I~
    if (!rc)                                                       //~2907I~
    	rc=iniacrnmchk(fh);                                        //~2907I~
    if (rc)                                                        //~v65eR~
    	uerrmsgbox("Invalid format ini file(%s), It may be of old version.",0,//~v65eR~
					fnm);                                          //~2907R~
    if (!rc)                                                       //~2907I~
    	memcpy(Ppwxeini,&wei,sizeof(WXEINIDATA));                  //~2907R~
    fclose(fh);                                                    //~2907I~
    return rc;                                                     //~2907I~
}//ugetinidata                                                     //~2907I~
//===============================================================================//~2907I~
//put ini file to work dir                                         //~2907I~
//===============================================================================//~2907I~
int uputinidata(PWXEINIDATA Ppwxeini)                              //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907R~
	char fnm[_MAX_PATH];                                           //~2907R~
    FILE *fh;                                                      //~2907I~
//************************************                             //~2907I~
    sprintf(fnm,"%s\\%s",Gworkdir,INI_FILENAME);                   //~2B30R~
	fh=fopen(fnm,"wb");                                            //~2907I~
    if (!fh)                                                       //~2907I~
    {                                                              //~2907I~
    	uerrmsgbox("ini file \"wb\" open failed(%s)",0,            //~2928R~
					fnm);                                          //~2928R~
		return 1;                                                  //~2907I~
    }                                                              //~2907I~
    rc=iniacrnmput(fh);                                            //~2907I~
    if (!rc)                                                       //~2907I~
    {                                                              //~2907I~
		len=fwrite(Ppwxeini,1,sizeof(WXEINIDATA),fh);              //~2907R~
    	if (len!=sizeof(WXEINIDATA))                               //~2907I~
        	rc=4;                                                  //~2907I~
    }                                                              //~2907I~
    if (!rc)                                                       //~2907I~
    	rc=iniacrnmput(fh);                                        //~2907I~
    if (rc)                                                        //~2907I~
    	uerrmsgbox("ini file write failed(%s)",0,                  //~2907I~
					fnm);                                          //~2907R~
    fclose(fh);                                                    //~2907I~
    return rc;                                                     //~2907I~
}//uputinidata                                                     //~2907I~
//===============================================================================//~2907I~
//ini file acronym chk                                             //~2907I~
//===============================================================================//~2907I~
int  iniacrnmchk(FILE *Pfh)                                        //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907I~
	char *inidata[256];                                            //~2907I~
//************************************                             //~2907I~
	len=fread(inidata,1,sizeof(INI_ACRNM),Pfh);                    //~2907I~
    if (len!=sizeof(INI_ACRNM))                                    //~2907I~
    	rc=4;                                                      //~2907I~
    if (!rc)                                                       //~2907I~
    	if (memcmp(inidata,INI_ACRNM,sizeof(INI_ACRNM)))           //~2907R~
        	rc=4;                                                  //~2907I~
    return rc;                                                     //~2907I~
}//iniacrnmchk                                                     //~2907I~
//===============================================================================//~2907I~
//ini file acronym put                                             //~2907I~
//===============================================================================//~2907I~
int  iniacrnmput(FILE *Pfh)                                        //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907I~
//************************************                             //~2907I~
	len=fwrite(INI_ACRNM,1,sizeof(INI_ACRNM),Pfh);                 //~2907R~
    if (len!=sizeof(INI_ACRNM))                                    //~2907I~
    	rc=4;                                                      //~2907I~
    return rc;                                                     //~2907I~
}//iniacrnmput                                                     //~2907I~
//===============================================================================//~2921I~
//ugetkbdshiftstatus                                               //~v55cR~
//===============================================================================//~2921I~
//int  ugetkbdshiftstatus(void)                                    //~v55cR~
int  ugetkbdshiftstatus(UINT nChar)                                //~v55cR~
{                                                                  //~2921I~
    int kstat=0;                                                   //~2921I~
    USHORT us1,us2;                                                //~2921R~
//  USHORT us3;                                                    //~v77xR~
    USHORT us3=0;                                                  //~v77xI~
    USHORT us4;                                                    //~v69bI~
    USHORT us5;                                                    //~v70eI~
//******************************                                   //~2921I~
    us1=GetKeyState(VK_SHIFT);                                     //~2921R~
    if (us1 & 0x8000)	//key down                                 //~2921R~
        kstat|=WXEKBDMSG_SHIFTKEY;	//      0x10                   //~2921R~
    us4=GetKeyState(VK_SCROLL);                                    //~v69bI~
    if (us4 & 0x8000)	//key down                                 //~v69bI~
        kstat|=WXEKBDMSG_SCROLLLOCKKEY;                            //~v69bR~
    if (us4 & 0x0001)	//key down                                 //~v69bI~
        kstat|=WXEKBDMSG_SCROLLLOCKON;                             //~v69bI~
    us2=GetKeyState(VK_CONTROL);                                   //~2921R~
    if (us2 & 0x8000)	//key down                                 //~2921R~
    {                                                              //~v55cI~
        kstat|=WXEKBDMSG_CTLKEY;	//      0x10                   //~2921R~
        if (nChar==VK_CONTROL)                                     //~v55cI~
        {                                                          //~v55cI~
    		if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter//~v55cR~
            {                                                      //~v55cR~
	    		us3=GetKeyState(VK_RCONTROL);                      //~v55cR~
    			if (us3 & 0x8000)	//key down                     //~v55cR~
	        		kstat|=WXEKBDMSG_RCTLKEY;                      //~v55cR~
            }                                                      //~v55cR~
        }                                                          //~v55cI~
    }                                                              //~v55cI~
    us5=GetKeyState(VK_MENU);                                      //~v70eR~
    if (us5 & 0x8000)	//key down                                 //~v70eR~
        kstat|=WXEKBDMSG_ALTKEY;	//                             //~v66hI~
UTRACEP("shift status ret=%x shift=%04x,ctl=%04x,rctl=%04x,scroll=%04x,alt=%04x\n",kstat,us1,us2,us3,us4,us5);//~v70eR~
    return kstat;                                                  //~2921I~
}//ugetkbdshiftstatus                                              //~2921I~
//*************************************************************    //~2922I~
//*get current path                                                //~2922I~
//*rc:1:path changed after prev                                    //~2922I~
//*************************************************************    //~2922I~
int  ugetcpath(char *Ppath)                                        //~2922I~
{                                                                  //~2922I~
	int rc;                                                        //~2922I~
static 	char Scpath[_MAX_PATH];                                    //~2922I~
//***********************                                          //~2922I~
//  ugetcwd(Ppath);                                                //~2922I~//~vb06R~
    ugetcwdW(UGCWDWO_DROPPREFIX,Ppath);                            //~vb06I~
    if (strcmp(Ppath,Scpath))                                      //~2922I~
    {                                                              //~2922I~
    	strcpy(Scpath,Ppath);                                      //~2922I~
    	rc=1;                                                      //~2922I~
    }                                                              //~2922I~
    else                                                           //~2922I~
    	rc=0;                                                      //~2922I~
    return rc;                                                     //~2922I~
}//ugetcpath                                                       //~2922I~
//*************************************************************    //~2923I~
//*get tempfilename on workdir                                     //~2923I~
//*option:1 use Gworkdir if avail                                  //~2A12I~
//*************************************************************    //~2923I~
int ugettempfname(int Popt,char *Ptempnam)                         //~2A12R~
{                                                                  //~2923I~
	int rc;                                                        //~2929R~
    static int Stmpdirsw=0;                                        //~2A12I~
//***********************                                          //~2923I~
    if (Popt==1 && *Gworkdir)  //xe called once                    //~2A12R~
    	strcpy(Ptempnam,Gworkdir);                                 //~2A12R~
    else                                                           //~2A12I~
    {                                                              //~2A12I~
		usetupwdtemp();                                            //~2A12I~
    	strcpy(Ptempnam,Swdtemp);                                  //~2A12I~
    }                                                              //~2A12I~
    rc=utempnam(Ptempnam,"nf_",Ptempnam)!=0;     //dir,prefix,outarea//~2929R~
    return rc;                                                     //~2923I~
}//ugettempfname                                                   //~2923I~
//*************************************************************    //~2A12M~
//*allocate dummy file for the case no filename parm in cmdline    //~2A12M~
//*  to avoid filename prompt at "save file"                       //~2A12M~
//*************************************************************    //~2A12M~
void uallocdummynewfile(char *Pfnm)                                //~2A12M~
{                                                                  //~2A12M~
	FILE *fh;                                                      //~2A12M~
//****************************                                     //~2A12M~
	ugettempfname(0,Pfnm); 		//temp on wxe work                 //~2A12M~
    strcpy(Pfnm+PATHLEN(Pfnm),"tmpfile");                          //~2A12M~
	if (ufstat(Pfnm,0))	//not found                                //~2A12M~
    {                                                              //~2A12M~
		fh=fopen(Pfnm,"w");                                        //~2A12M~
		fclose(fh);                                                //~2A12M~
    }                                                              //~2A12M~
    return;                                                        //~2A12M~
}//uallocdummynewfile                                              //~2A12M~
////===============================================================================//~2B30R~
////get ini file on work dir                                       //~2B30R~
////===============================================================================//~2B30R~
//int usetupwd(void)                                               //~2B30R~
//{                                                                //~2B30R~
//    char *fnm;                                                   //~2B30R~
//static int Ssetupwd=0;                                           //~2B30R~
////************************************                           //~2B30R~
//    if (!Ssetupwd)                                               //~2B30R~
//    {                                                            //~2B30R~
//        Ssetupwd=1;                                              //~2B30R~
//        fnm=WXE_WKDIR;                                           //~2B30R~
//        if (ufstat(fnm,0))  //not found                          //~2B30R~
//        {                                                        //~2B30R~
//            if (!umkdir(fnm))                                    //~2B30R~
//                uerrmsgbox("WorkDir %s is for %s now created",0, //~2B30R~
//                        fnm,WXE_PGMNAME);                        //~2B30R~
//            else                                                 //~2B30R~
//                uerrmsgbox("WorkDir %s for %s created",0,        //~2B30R~
//                        fnm,WXE_PGMNAME);                        //~2B30R~
//        }                                                        //~2B30R~
//    }                                                            //~2B30R~
//    return 0;                                                    //~2B30R~
//}//usetupwd                                                      //~2B30R~
//*************************************************************    //~2A12I~
//*get tempfilename on workdir                                     //~2A12I~
//*option:1 use Gworkdir if avail                                  //~2A12I~
//*************************************************************    //~2A12I~
int usetupwdtemp(void)                                             //~2A12I~
{                                                                  //~2A12I~
static int Ssetupwdtemp=0;                                         //~2A12I~
	int rc=0;                                                      //~2B30I~
//***********************                                          //~2A12I~
	if (!Ssetupwdtemp)                                             //~2A12I~
    {                                                              //~2A12I~
		Ssetupwdtemp=1;                                            //~2A12I~
		strcpy(Swdtemp,Gworkdir);                                  //~2B30I~
		strcat(Swdtemp,WXE_TEMPDIR);                               //~2B30I~
        if (ufstat(Swdtemp,0)) //not found                         //~2A12I~
        	rc=umkdir(Swdtemp);                                    //~2B30R~
    }                                                              //~2A12I~
    return rc;                                                     //~2B30R~
}//usetupwdtemp                                                    //~2A12I~
//*************************************************************    //~2929I~
//*intf to umalloc                                                 //~2929I~
//*************************************************************    //~2929I~
void *umemalloc(int Plen)                                          //~2929I~
{                                                                  //~2929I~
	return umalloc(Plen);	                                       //~2929I~
}//umemalloc                                                       //~2929I~
//*************************************************************    //~2929I~
//*intf to ufree                                                   //~2929I~
//*************************************************************    //~2929I~
void umemfree(void *Paddr)                                         //~2929I~
{                                                                  //~2929I~
	ufree(Paddr);                                                  //~2929I~
    return;                                                        //~2929I~
}//umemfree                                                        //~2929I~
//*************************************************************    //~v53tI~
//*intf to malloc                                                  //~v53tI~
//*************************************************************    //~v53tI~
void *wxemalloc(int Plen)                                          //~v53tI~
{                                                                  //~v53tI~
	return malloc(Plen);                                           //~v53tI~
}//wxemalloc                                                       //~v53tI~
//*************************************************************    //~v53tI~
//*intf to free                                                    //~v53tI~
//*************************************************************    //~v53tI~
void wxefree(void *Paddr)                                          //~v53tI~
{                                                                  //~v53tI~
	free(Paddr);                                                   //~v53tI~
    return;                                                        //~v53tI~
}//wxefree                                                         //~v53tI~
//*************************************************************    //~v70eI~
//ret 0:fail                                                       //~v70eI~
//*************************************************************    //~v70eI~
int  uopenclipboard(void)                                          //~v70eI~
{                                                                  //~v70eI~
	return OpenClipboard(Shwnd);                                   //~v70eI~
}//uopenclipboard                                                  //~v70eI~
//*************************************************************    //~v70eI~
//*************************************************************    //~v70eI~
char *uglobalalloc(int Plen,void *Pphandle)                        //~v70eI~
{                                                                  //~v70eI~
	HGLOBAL hGlobal,*ph;                                           //~v70eR~
//***********************                                          //~v70eI~
    hGlobal=GlobalAlloc(GMEM_MOVEABLE,Plen);                       //~v70eI~
	if (hGlobal==NULL)                                             //~v70eI~
    {                                                              //~v70eI~
        uerrmsgbox("GlobalAlloc failed, len=%d,rc=%d",0,           //~v70eI~
							Plen,GetLastError());                  //~v70eI~
		CloseClipboard();                                          //~v70eI~
        return 0;                                                  //~v70eI~
    }                                                              //~v70eI~
//  ph=(HGLOBAL*)(ULONG)Pphandle;                                  //~v70eI~//~vafkR~
    ph=(HGLOBAL*)(ULPTR)Pphandle;                                  //~vafkI~
    *ph=hGlobal;                                                   //~v70eR~
	return (char *)GlobalLock(hGlobal);                            //~v70eI~
}//uglobalalloc                                                    //~v70eI~
//*************************************************************    //~v70eI~
//*************************************************************    //~v70eI~
//int usetclipboard(ULONG Phandle,ULONG Ptype)                       //~v70eR~//~vafkR~
//int usetclipboard(ULPTR Phandle,ULONG Ptype)                     //~vaz3R~
int usetclipboard(HANDLE Phandle,ULONG Ptype)                      //~vaz3I~
{                                                                  //~v70eI~
	HGLOBAL hGlobal;                                               //~v70eI~
//*********************************                                //~v70eI~
    hGlobal=(HGLOBAL)Phandle;                                      //~v70eI~
    EmptyClipboard();                                              //~v70eI~
	GlobalUnlock(hGlobal);                                         //~v70eI~
	SetClipboardData(Ptype,hGlobal);                               //~v70eI~
UTRACEP("Clipboard usetclipboard type=%d\n",Ptype);                //~va20I~
    return 0;                                                      //~v70eI~
}//usetclipboard                                                   //~v70eI~
//*************************************************************    //~v70eI~
//*************************************************************    //~v70eI~
int ucloseclipboard(void)                                          //~v70eI~
{                                                                  //~v70eI~
	CloseClipboard();                                              //~v70eI~
    return 0;                                                      //~v70eI~
}//ucloseclipboard                                                 //~v70eI~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//*                                                                //~va20I~
//**************************************************************** //~va20I~
int csubchkdd(int Popt,char *Pdbcs,int Plen)                       //~va20I~
{                                                                  //~va20I~
    return utfchkdd(0,(UCHAR*)Pdbcs,Plen);                         //~va20R~
}//csubchkdd                                                       //~va20I~
//**************************************************************** //~va20I~
#ifdef AAA //no caller                                             //~vaw1I~
int csubddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr)//~va30R~
{                                                                  //~va30R~
	return utfddcombine(Popt,Pdata,Pdbcs,Pcombineid,Plen,Ppstarterrctr,Ppendcombinectr);//~va30R~
}//csubddcombine                                                   //~va30R~
#endif //AAA                                                       //~vaw1I~
//**************************************************************** //~va3gI~
//*same as uviom logic                                             //~va3uR~
//**************************************************************** //~va3gI~
//int csubtextoutw_ligature(int Popt,HDC Phdc,int Px,int Py,WUCS *Pdata,int Pucsctr,char *Pdbcs,int Plen,int Pcellw)//~vb4iR~
int csubtextoutw_ligature(int Popt,int Plineopt,HDC Phdc,int Px,int Py,WUCS *Pdata,int Pucsctr,char *Pdbcs,int Plen,int Pcellw)//~vb4iR~
{                                                                  //~va3gI~
    char *pdbcs;                                                   //~va3gI~
	int ii,dbcsid,ligucsctr=0,xx,dbcssw,dbcssz,chtype,chtypeo,ligchsz=0,swcombinable=0;//~va3gR~
//  WUCS wkligature[2][MAXCOL],*pwkucs,*pucs,ucs;                  //~va3gR~//~vb2HR~
    WUCS wkligature[2][MAXCOL*2],*pwkucs,*pucs,ucs;                //~vb2HI~
    WUCS utf16low;                                                 //~vb2HI~
    int utf16ctr;                                                  //~vb2HI~
    int swovf;                                                     //~vb2PI~
#ifndef SSS                                                        //~vb3xI~
    WUCS wkucsdbcsspace[2];                                        //~vb3xI~
    int swdbcsspaceutf8;                                           //~vb3xI~
#endif                                                             //~vb3xI~
//**********************                                           //~va3gI~
    UTRACEP("%s:opt=%x,lineopt=%x,len=%d,xx=%d,yy=%d,ucsctr=%d,dbcslen=%d,cwllw=%d\n",UTT,Popt,Plineopt,Plen,Px,Py,Pucsctr,Plen,Pcellw);//~vb4iR~
    chtypeo=-2;                                                    //~va3gI~
    for (ii=0,pucs=Pdata,xx=Px,pdbcs=Pdbcs;ii<Pucsctr;ii++,pucs++,pdbcs+=dbcssz)//~va3gR~
    {                                                              //~va3gI~
        ucs=*pucs;                                                 //~va3gI~
        utf16low=0;                                                //~vb2HI~
        utf16ctr=1;                                                //~vb2HI~
        if (ii+1<Pucsctr && IS_UTF16_PAIR(ucs,*(pucs+1)))          //~vb2HI~
        {                                                          //~vb2HI~
        	utf16ctr=2;                                            //~vb2HI~
            utf16low=*(pucs+1);                                    //~vb2HI~
        }                                                          //~vb2HI~
        dbcsid=*pdbcs;                                             //~va3gI~
//      dbcssw=UDBCSCHK_DBCS1STUCS2NW(dbcsid);                     //~va3gR~//~vb2HR~
//      dbcssw=UDBCSCHK_DBCS1STUCS2NWPO(dbcsid);                   //~vb2HI~//~vb3mR~
        dbcssw=UDBCSCHK_DBCS1STUCS2NWO(dbcsid);   //for unprintable,utfdd2u set 2 altch(sbcs)//~vb3mI~
		swovf=0;                                                   //~v6uBI~//~vb2PI~
		if (UDBCSCHK_ISUCSOVF1ST(dbcsid)) //ucs4                   //~v6uBI~//~vb2PI~
        {                                                          //~v6uBI~//~vb2PI~
        	swovf=1;                                               //~v6uBI~//~vb2PI~
          	dbcssw=1;                                              //~v6uBI~//~vb2PI~
        }                                                          //~v6uBI~//~vb2PI~
        UTRACEP("csubtextoutw_ligature combined swovf=%d,utf16ctr=%d,ucs ii=%d,dbcsid=%02x,dbcssw=%d,xx=%d,yy=%d,ucs=%04x-%04x,ligucsctr=%d\n",swovf,utf16ctr,ii,dbcsid,dbcssw,xx,Py,ucs,utf16low,ligucsctr);//~va3gR~//~vb2HR~//~vb2PR~
        dbcssz=1+dbcssw;                                           //~va3gI~
//        if (UTF_COMBINABLE(ucs))                                 //~va3uR~
//        {                                                        //~va3uR~
//            chtype=1;       //LTR or RTL                         //~va3uR~
//            swcombinable=1;                                      //~va3uR~
//        }                                                        //~va3uR~
//        else                                                     //~va3uR~
//        {                                                        //~va3uR~
#ifdef AAA                                                         //~vb2QI~
		  if (swovf)                                               //~v6uBI~//~vb2PI~
          	chtype=-1;					//single write             //~v6uBI~//~vb2PI~
          else                                                     //~v6uBI~//~vb2PI~
#endif                                                             //~vb2QI~
#ifndef SSS                                                        //~vb3xI~
    	  swdbcsspaceutf8=0;                                       //~vb3xI~
      	  if (ucs==DBCSSPACE_ALT2   //ffff                         //~vb3xI~
	  	  &&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~vb3xI~
      	  {                                                        //~vb3xI~
	    		swdbcsspaceutf8=1;                                 //~vb3xI~
            	chtype=-1;					//single write         //~vb3xI~
	  	  }                                                        //~vb3xI~
          else                                                     //~vb3xI~
#endif                                                             //~vb3xI~
          {                                                        //~v6uBI~//~vb2PI~
        	if (UDBCSCHK_ISUCSWIDTH0(dbcsid))	//combine char     //~va3gI~
            {                                                      //~va3gI~
//      		if (swcombinable && UTF_COMBINEMODE())	           //~vb4iR~
        		if (swcombinable && WXE_COMBINEMODE(Plineopt))   //for also UVIOO_FORCECOMBINE//~vb4iI~
                {                                                  //~va3gI~
            		chtype=1;					//add to LTR/RTL group//~va3gI~
                }                                                  //~va3gI~
            	else                                               //~va3gI~
//          		chtype=-1;					//single write     //~vb4zR~
            		chtype=-2;					//combining char itself,single write//~vb4zR~
            }                                                      //~va3gI~
        	else                                                   //~va3gI~
            {                                                      //~va3gI~
#ifdef AAA                                                         //~va3gI~
        		chtype=0;						//space,digit etc LTR only//~va3gI~
#else                                                              //~va3gI~
        		chtype=1;						//mix all          //~va3gR~
#endif                                                             //~va3gI~
              if (UTF_COMBINABLE(ucs))                             //~va3uI~
	            swcombinable=1;                                    //~va3uI~
	          else                                                 //~va3uI~
				swcombinable=0;                                    //~va3gI~
            }                                                      //~va3gI~
          }                                                        //~v6uBI~//~vb2PI~
//        }                                                        //~va3uR~
UTRACEP("ligature chtype=%d,old=%d,ucs=%04x,dbcssw=%d,swcombinable=%d\n",chtype,chtypeo,ucs,dbcssw,swcombinable);//~va3uR~
        if (chtype<0||(ligucsctr && chtype!=chtypeo))	//breaker  //~va3gR~
        {                                                          //~va3gI~
            if (ligucsctr)                                         //~va3gI~
            {                                                      //~va3gI~
            	pwkucs=wkligature[chtypeo];                        //~va3gR~
            	TextOutW(Phdc,xx,Py,pwkucs,ligucsctr);             //~va3gI~
            	UTRACEP("%s:ligature group chtype=%d,ucsctr=%d,chsz=%d,xx=%d\n",UTT,chtypeo,ligucsctr,ligchsz,xx);//~va3gI~//~vb4jR~
            	UTRACED("csubtextoutw ligature group pos",pwkucs,ligucsctr*WUCSSZ);//~va3gI~//~vb2PR~
                {                                                  //~vb4jI~
                	SIZE sz;                                       //~vb4jI~
            		UTRACEP("%s:at breake;GetTextExtentPoint32W cellsz=%d,drawsz=%d\n",UTT,Pcellw*ligchsz,(GetTextExtentPoint32W(Phdc,pwkucs,ligucsctr,&sz)?sz.cy*1000+sz.cx:0));//~vb4jR~
                }                                                  //~vb4jI~
			  if (chtype==-2)	//combining char not combine mode  //~vb4zR~
              {                                                    //~vb4zR~
              	SIZE sz;                                           //~vb4zR~
            	if (GetTextExtentPoint32W(Phdc,pwkucs,ligucsctr,&sz))//~vb4zR~
                {                                                  //~vb4zR~
	            	xx+=sz.cx;                                     //~vb4zR~
            		UTRACEP("%s:before combining char under not combinemode cellsz=%d,drawsz=%d,new xx=%d\n",UTT,Pcellw*ligchsz,sz.cx,xx);//~vb4zR~
                }                                                  //~vb4zR~
                else                                               //~vb4zR~
	            	xx+=Pcellw*ligchsz;                            //~vb4zR~
              }                                                    //~vb4zR~
              else                                                 //~vb4zR~
	            xx+=Pcellw*ligchsz;                                //~va3gI~
            }                                                      //~va3gI~
            if (chtype<0)                                          //~va3gI~
            {                                                      //~va3gI~
#ifndef SSS                                                        //~vb3xI~
	    	  if (swdbcsspaceutf8)                                 //~vb3xI~
              {                                                    //~vb3xI~
		        wkucsdbcsspace[0]=(WUCS)UTF_GETALTCH_DBCS();       //~vb3xI~
          	    wkucsdbcsspace[1]=wkucsdbcsspace[0];               //~vb3xI~
                TextOutW(Phdc,xx,Py,wkucsdbcsspace,2);             //~vb3xI~
            	UTRACEP("%s:dbcsspaceutf8 xx=%d,yy=%d,altch=%02x\n",UTT,xx,Py,wkucsdbcsspace[0]);//~vb3xI~
                {                                                  //~vb4jI~
                	SIZE sz;                                       //~vb4jI~
            		UTRACEP("%s:after break dbcs space GetTextExtentPoint32W cellsz=%d,drawsz=%d\n",UTT,Pcellw*dbcssz,(GetTextExtentPoint32W(Phdc,wkucsdbcsspace,2,&sz)?sz.cy*1000+sz.cx:0));//~vb4jR~
                }                                                  //~vb4jI~
              }                                                    //~vb3xI~
              else                                                 //~vb3xI~
#endif                                                             //~vb3xI~
              {                                                    //~vb3xI~
               if (chtype==-2) //combining char under not combinemode//~vb4AI~
				csubtextoutWcombining_notcombinemode(0,Phdc,xx,Py,pucs,utf16ctr);//~vb4AI~
               else                                                //~vb4AI~
               {                                                   //~vb4AI~
//          	TextOutW(Phdc,xx,Py,pucs,1);                       //~va3gR~//~vb2HR~
            	TextOutW(Phdc,xx,Py,pucs,utf16ctr);                //~vb2HI~
            	UTRACEP("%s: chtype<0 utf16ctr=%d,xx=%d,ucs=%04x,dbcssz=%d,utf16ctr=%d\n",UTT,utf16ctr,xx,*pucs,dbcssz,utf16ctr);//~vb4jR~
            	UTRACED("chtype<0 pucs",pucs,utf16ctr*WUCSSZ);     //~vb4jR~
                {                                                  //~vb4jI~
                	SIZE sz;                                       //~vb4jI~
            		UTRACEP("%s:after break not dbcs space GetTextExtentPoint32W cellsz=%d,drawsz=%d\n",UTT,Pcellw*utf16ctr,(GetTextExtentPoint32W(Phdc,pucs,utf16ctr,&sz)?sz.cy*1000+sz.cx:0));//~vb4jR~
                }                                                  //~vb4jI~
               }                                                   //~vb4AI~
              }                                                    //~vb3xI~
            	xx+=Pcellw*dbcssz;                                 //~va3gR~
            }                                                      //~va3gI~
            ligucsctr=0;                                           //~va3gR~
            ligchsz=0;                                             //~va3gI~
#ifdef AAA                                                         //~vb2QI~
            if (chtype<0)                                          //~va3gI~
#endif                                                             //~vb2QI~
            {                                                      //~vb2HI~
    		    if (utf16ctr>1)                                    //~vb2HR~
                {                                                  //~vb2HI~
	        	    pucs++;                                        //~vb2HI~
                    ii++;                                          //~vb2HI~
                }                                                  //~vb2HI~
            	continue;                                          //~va3gI~
            }                                                      //~vb2HI~
        }                                                          //~va3gI~
        chtypeo=chtype;                                            //~va3gI~
        wkligature[chtype][ligucsctr++]=ucs;                       //~va3gR~
        if (utf16ctr>1)                                            //~vb2HR~
        {                                                          //~vb2HI~
	        wkligature[chtype][ligucsctr++]=utf16low;              //~vb2HI~
            pucs++;                                                //~vb2HI~
            ii++;                                                  //~vb2HI~
        }                                                          //~vb2HI~
        ligchsz+=dbcssz;                                           //~va3gR~
    }                                                              //~va3gI~
    if (ligucsctr)                                                 //~va3gI~
    {                                                              //~va3gI~
        pwkucs=wkligature[chtypeo];                                //~va3gR~
        TextOutW(Phdc,xx,Py,pwkucs,ligucsctr);                     //~va3gI~
        UTRACEP("csubtextoutw ligature group last chtype=%d,ucsctr=%d,chsz=%d,posx=%d\n",chtypeo,ligucsctr,ligchsz,xx);//~va3gI~//~vb2QR~
        UTRACED("csubtextoutw ligature last group",pwkucs,ligucsctr*WUCSSZ);//~va3gI~
        {                                                          //~vb4jI~
            SIZE sz;                                               //~vb4jI~
            UTRACEP("%s:last, GetTextExtentPoint32W cellsz=%d,drawsz=%d\n",UTT,Pcellw*ligucsctr,(GetTextExtentPoint32W(Phdc,pwkucs,ligucsctr,&sz)?sz.cy*1000+sz.cx:0));//~vb4jR~
        }                                                          //~vb4jI~
    }                                                              //~va3gI~
    return 0;                                                      //~va3gI~
}//csubtextoutw_ligature                                           //~va3gI~
//**************************************************************** //~v907I~//~va20I~
//*                                                                //~v907I~//~va20I~
//**************************************************************** //~v907I~//~va20I~
//int csubtextoutw(int Popt,HDC Phdc,int Px,int Py,char *Pdata,char *Pdbcs,int Plen,int Pcellw)//~va20R~//~vb4iR~
//int csubtextoutw(int Popt,int Plineopt,HDC Phdc,int Px,int Py,char *Pdata,char *Pdbcs,int Plen,int Pcellw,int Pfgcolor,int Pbgcolor)//~vb4jR~
int csubtextoutw(int Popt,int Plineopt,HDC Phdc,int Px,int Py,char *Pdata,char *Pdbcs,int Plen,int Pcellw)//~vb4jI~
{                                                                  //~v907I~//~va20I~
    WUCS wkucs[PRINTCOL_MAX*2],*pucs;                              //~va20R~
    char *pdbcs;                                                   //~va20I~
	int ii,dbcsid,ucsctr,xx,opt,swscr;                             //~va20R~
    int jj,kk,wrtctr,dbcssw,dbcssz;                                //~va30R~
    WUCS wkcombine[UVIOM_MAXCOMBINE+1],*pwkcomb,*pucsw;            //~va30R~
    int utf16ctr;                                                  //~vb2HR~
    UWUCS ucs4;                                                    //~vb2HR~
#ifndef SSS                                                        //~vb3xI~
    WUCS wkucsdbcsspace[2];                                        //~vb3xR~
#endif                                                             //~vb3xI~
//    COLORREF altchcolor=RGB(255,255,0);                          //~vb4jR~
//    COLORREF bkhiwhite=RGB(255,255,255);                         //~vb4jR~
//**********************                                           //~va20I~
  	opt=UVIO_ERRREP;                                               //~va20I~
	swscr=!(Popt & CSTOWO_PRINT);//   scr output                   //~va20I~
	if (swscr)//   scr output                                      //~va20I~
//		opt|=UTFDD2UO_VIO;		//output unprintable alternative char//~va20I~//~va5GR~
  		opt|=UTFDD2UO_VIO|UTFDD2UO_NULLREP;		//output unprintable alternative char,null is to space//~va5GI~
  	utfdd2u(opt,Pdata,Pdbcs,Plen,wkucs,sizeof(wkucs),&ucsctr,0/*dbcsctr*/,0/*sbcsctr*/);//~va20R~
	if (!swscr)//                                                  //~va20R~
    {                                                              //~va20I~
        TextOutW(Phdc,Px,Py,wkucs,ucsctr);                         //~va20R~
        UTRACED("textoutw",wkucs,ucsctr*2);                        //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    if (Popt & CSTOWO_COMBINECHK         //UTF8 file               //~va3gR~
//  &&  (((GPWXEI()->WXEIstatus & WXEIS_LIGATURE)!=0) ^ ((GPWXEI()->WXEIstatus & WXEIS_TEMPLIGATURE)!=0))//~vb4iR~
    &&  WXE_LIGATUREMODE(Plineopt)                                 //~vb4iR~
    )                                                              //~va3gI~
    {                                                              //~va3gI~
//  	csubtextoutw_ligature(Popt,Phdc,Px,Py,wkucs,ucsctr,Pdbcs,Plen,Pcellw);//~vb4iR~
    	csubtextoutw_ligature(Popt,Plineopt,Phdc,Px,Py,wkucs,ucsctr,Pdbcs,Plen,Pcellw);//~vb4iI~
    }                                                              //~va3gI~
    else                                                           //~va3gI~
//  if (Popt & CSTOWO_COMBINECHK)                                  //~va36R~
    if (Popt & CSTOWO_COMBINECHK                                   //~va36I~
//  &&  UTF_COMBINEMODE()                                          //~vb4iR~
    &&  WXE_COMBINEMODE(Plineopt)                                  //~vb4iI~
    )                                                              //~va36I~
    {                                                              //~va30R~
      	UTRACEP("csubtextoutw len=%d,xx=%d,yy=%d,cwllw=%d\n",Plen,Px,Py,Pcellw);//~va30I~
        wrtctr=0;                                                  //~@@@@I~
        for (ii=0,pucs=wkucs,xx=Px,pdbcs=Pdbcs;ii<ucsctr;ii+=wrtctr)//~va30R~
        {                                                          //~va30R~
            dbcsid=*pdbcs;                                         //~va30R~
//          dbcssw=UDBCSCHK_DBCS1STUCS2NW(dbcsid);                 //~va3gR~//~vb2HR~
//          dbcssw=UDBCSCHK_DBCS1STUCS2NWPO(dbcsid);//+unprintable and overflow(ucs4)//~vb2HI~//~vb3mR~
            dbcssw=UDBCSCHK_DBCS1STUCS2NWO(dbcsid);   //for unprintable,utfdd2u set 2 altch(sbcs)//~vb3mI~
            utf162ucs4(U162U4O_UCS1,pucs,ucsctr-ii,&ucs4,(int)sizeof(ucs4),&utf16ctr,0/*outucsctr*/);//~vb2HM~
      		UTRACEP("csubtextoutw combined ucs ii=%d,dbcsid=%02x,dbcssw=%d,xx=%d,yy=%d,ucs4=%04x,utf16ctr=%d\n",ii,dbcsid,dbcssw,xx,Py,ucs4,utf16ctr);//~va30I~//~vb2HR~//~vb2WR~
            dbcssz=1+dbcssw;                                       //~va30I~
#ifndef SSS                                                        //~vb3xI~
      		if (*pucs==DBCSSPACE_ALT2   //ffff                     //~vb3xI~
	  		&&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~vb3xI~
      		{                                                      //~vb3xI~
          		wkucsdbcsspace[0]=(WUCS)UTF_GETALTCH_DBCS();       //~vb3xI~
          		wkucsdbcsspace[1]=wkucsdbcsspace[0];               //~vb3xI~
          		TextOutW(Phdc,xx,Py,wkucsdbcsspace,2);             //~vb3xI~
		  		UTRACEP("%s:dbcsspaceutf8 ucs=%04x-->%04x,dbcsid=%02x\n",UTT,*pucs,wkucsdbcsspace[0],*pdbcs);//~vb3xI~
		        wrtctr=1;                                          //~vb3xI~
                pdbcs+=dbcssz;                                     //~vb3xI~
            	pucs++;                                            //~vb3xI~
          		xx+=Pcellw*2;                                      //~vb3xI~
	  		}                                                      //~vb3xI~
      		else                                                   //~vb3xI~
#endif                                                             //~vb3xI~
            if (!UDBCSCHK_ISUCSWIDTH0(dbcsid)                      //~va30R~
            &&   ii+1<ucsctr                                       //~va30I~
            &&   (dbcsid=*(pdbcs+dbcssz),UDBCSCHK_ISUCSWIDTH0(dbcsid))//next is combining char//~va30R~
            )                                                      //~va30I~
            {                                                      //~va30R~
            	pwkcomb=wkcombine;                                 //~va30I~
                *pwkcomb++=*pucs++;                                //~va30R~
                if (utf16ctr>1)                                    //~vb2HI~
	                *pwkcomb++=*pucs++;                            //~vb2HI~
                *pwkcomb++=*pucs++;    //1st combine               //~va30I~
                pdbcs+=dbcssz+1;                                   //~va30I~
//              wrtctr=2;                                          //~va30I~//~vb2HR~
                wrtctr=1+utf16ctr;                                 //~vb2HI~
//*assum combine char is ucs2***                                   //~vb2HI~
        		for (jj=1,kk=ii+2;jj<UVIOM_MAXCOMBINE && kk<ucsctr;kk++,jj++,pdbcs++)//~va30I~
                {                                                  //~va30R~
		            dbcsid=*pdbcs;                                 //~va30R~
					if (!UDBCSCHK_ISUCSWIDTH0(dbcsid))             //~va30R~
                    	break;                                     //~va30R~
                    *pwkcomb++=*pucs++;                            //~va30R~
                    wrtctr++;                                      //~va30I~
                }                                                  //~va30R~
                pucsw=wkcombine;	                               //~va30M~
                TextOutW(Phdc,xx,Py,pucsw,wrtctr);                 //~va30I~
            	UTRACED("csubtextoutw combined ucs2",pucsw,wrtctr*WUCSSZ);//~va30I~//~vb2HR~
            	xx+=Pcellw*(dbcssw+wrtctr);                        //~va30R~
            }                                                      //~va30R~
            else                                                   //~va30I~
            {                                                      //~va30I~
		        wrtctr=1;                                          //~va30R~
                pdbcs+=dbcssz;                                     //~va30R~
            	pucsw=pucs++;                                      //~va30I~
//                if (UDBCSCHK_DBCS1STUCS2(dbcsid)                 //~vb3rR~//~vb3sR~
//                &&  *pucsw==((PWXEINTF)Gpwxei)->WXEIunpdispchar[3] && *(pucsw+1)==*pucsw)    //dbcsspace altch,may changed by ini file//~vb3rR~//~vb3sR~
//                {                                                //~vb3rR~//~vb3sR~
//                    wrtctr=2;                                    //~vb3rR~//~vb3sR~
//                    pucs++;                                      //~vb3rR~//~vb3sR~
//                }                                                //~vb3rR~//~vb3sR~
                if (utf16ctr>1)                                    //~vb2HI~
                {                                                  //~vb2HI~
                    wrtctr++;                                      //~vb2HI~
                    pucs++;                                        //~vb2HI~
                }                                                  //~vb2HI~
                TextOutW(Phdc,xx,Py,pucsw,wrtctr);                 //~va30I~
            	UTRACED("csubtextoutw not combined ucs",pucsw,wrtctr*WUCSSZ);//~va30I~//~vb2WR~
            	xx+=Pcellw*dbcssz;                                 //~va30I~
            }                                                      //~va30I~
        }                                                          //~va30R~
    }                                                              //~va30R~
    else                                                           //~va30R~
//*not combinemode                                                 //~vb4iI~
    for (ii=0,pucs=wkucs,xx=Px,pdbcs=Pdbcs;ii<ucsctr;ii++,pucs++,pdbcs++,xx+=Pcellw)//~va20I~
    {                                                              //~va20I~
    	dbcsid=*pdbcs;                                             //~va20I~
#ifndef SSS                                                        //~vb3xI~
      if (*pucs==DBCSSPACE_ALT2   //ffff                           //~vb3xI~
	  &&  *pdbcs==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~vb3xI~
      {                                                            //~vb3xI~
          wkucsdbcsspace[0]=(WUCS)UTF_GETALTCH_DBCS();             //~vb3xR~
          wkucsdbcsspace[1]=wkucsdbcsspace[0];                     //~vb3xR~
          TextOutW(Phdc,xx,Py,wkucsdbcsspace,2);                   //~vb3xR~
		  UTRACEP("%s:dbcsspaceutf8 ucs=%04x-->%04x,dbcsid=%02x\n",UTT,*pucs,wkucsdbcsspace[0],*pdbcs);//~vb3xR~
          pdbcs++;                                                 //~vb3xR~
          xx+=Pcellw;                                              //~vb3xI~
	  }                                                            //~vb3xI~
      else                                                         //~vb3xI~
#endif                                                             //~vb3xI~
      if (ii+1<ucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))           //~vb2HR~
      {                                                            //~vb2HI~
        TextOutW(Phdc,xx,Py,pucs,2);                               //~vb2HI~
  		UTRACEP("csubtextoutw ucs ii=%d,dbcsid=%02x,xx=%d,yy=%d,ucs=%04x-%04x\n",ii,dbcsid,xx,Py,*pucs,*(pucs+1));//~vb2HI~
        pucs++;                                                    //~vb2HI~
        ii++;                                                      //~vb2HI~
      }                                                            //~vb2HI~
      else                                                         //~vb2HI~
//      if (Popt & CSTOWO_COMBINECHK                               //~vb4jR~
//      &&  UDBCSCHK_ISUCSWIDTH0(dbcsid)                           //~vb4jR~
//      &&  UTF_COMBINEMODE_NP()                                   //~vb4jR~
//      &&  Gutfcombaltch                                          //~vb4jR~
//      )                                                          //~vb4jR~
//      {                                                          //~vb4jR~
//        SetTextColor(Phdc,altchcolor);                           //~vb4jR~
//        if ((unsigned)Pbgcolor==bkhiwhite)                       //~vb4jR~
//            SetBkColor(Phdc,RGB(192,192,192));                   //~vb4jR~
//        SetTextColor(Phdc,altchcolor);                           //~vb4jR~
//        TextOutW(Phdc,xx,Py,&Gutfcombaltch,1);                   //~vb4jR~
//        SetTextColor(Phdc,Pfgcolor);                             //~vb4jR~
//        if ((unsigned)Pbgcolor==bkhiwhite)                       //~vb4jR~
//            SetBkColor(Phdc,bkhiwhite);                          //~vb4jR~
//        UTRACEP("%s:write combaltch  ii=%d,dbcsid=%02x,xx=%d,yy=%d,ucs=%04x,altchcolor=%x,restorecolor=%x\n",UTT,ii,dbcsid,xx,Py,Gutfcombaltch,altchcolor,Pfgcolor);//~vb4jR~
//      }                                                          //~vb4jR~
//      else                                                       //~vb4jR~
      {                                                            //~vb2HI~
        TextOutW(Phdc,xx,Py,pucs,1);                               //~va20I~
  		UTRACEP("csubtextoutw ucs ii=%d,dbcsid=%02x,xx=%d,yy=%d,ucs=%04x\n",ii,dbcsid,xx,Py,*pucs);//~va20R~
      }                                                            //~vb2HI~
//  	if (UDBCSCHK_DBCS1STUCS2NW(dbcsid)                       //~v640R~//~va20R~//~vb2HR~
    	if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid)	//+Overflow(UCS4)      //~vb2HI~
        ||	(!swscr && UDBCSCHK_ISUCSNP(dbcsid))  //print unprintable as is base//~va20I~
        )                                                          //~va20I~
        {                                                          //~va20I~
        	pdbcs++;                                               //~va20I~
            xx+=Pcellw;                                            //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    return ucsctr;                                                 //~va20R~
}//csubtextoutw                                                    //~va3gR~
//**************************************************************** //~va20I~
//*                                                                //~va20I~
//**************************************************************** //~va20I~
int csubtextoutw1(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen)//~va20R~
{                                                                  //~va20I~
#ifdef UTF8UTF16                                                   //~vaw0R~
	UWUCS ucs;                                                     //~vaw0R~
    WUCS  wucs[2];                                                 //~vaw0R~
    int ucsctr;                                                    //~vaw0R~
#else                                                              //~vaw0R~
	WUCS ucs;                                                      //~va20R~
#endif                                                             //~vaw0R~
//**********************                                           //~va20I~
#ifdef UTF8UTF16                                                   //~vaw1I~
	ucs=(UWUCS)UTF_GETDDUCS1(Pdata,Pdbcs,Plen);                    //~vaw1I~
#else                                                              //~vaw1I~
	ucs=(WUCS)UTF_GETDDUCS1(Pdata,Pdbcs,Plen);                     //~va20R~
#endif                                                             //~vaw1I~
#ifdef UTF8UTF16                                                   //~vaw1R~
  	UCS4_TO_UTF16(ucs,wucs,&ucsctr);                               //~vaw1R~//~v6unR~
	TextOutW(Phdc,Pxx,Pyy,wucs,ucsctr);                            //~vaw1R~//~v6unR~
#else                                                              //~v6unI~
	TextOutW(Phdc,Pxx,Pyy,&ucs,1);                                 //~va20R~
#endif                                                             //~vaw1R~//~v6unM~
    return 0;                                                      //~va20I~
}                                                                  //~va20I~
//**************************************************************** //~va42I~
//*write special char invisible                                    //~va42I~
//**************************************************************** //~va42I~
int csubtextoutw1alt(int Popt,HDC Phdc,int Pxx,int Pyy,WUCS Pucs)  //~va42I~
{                                                                  //~va42I~
	WUCS ucs;                                                      //~va42I~
    int altch;                                                     //~va42I~
//**********************                                           //~va42I~
  if (Popt & CSUBTOWAO_FORCE)                                      //~va44R~
  	ucs=Pucs;                                                      //~va44I~
  else                                                             //~va44I~
  {                                                                //~va44I~
   if (Pucs==DEFAULT_ALTCH)                                        //~va46I~
    altch=utfgetvisiblealtch(Popt & CSUBTOWAO_MASK,Pucs);          //~va46I~
   else                                                            //~va46I~
    altch=utfgetvisiblealtch(0,Pucs);                              //~va42R~
    if (altch<=0)                                                  //~va42R~
    	return 0;                                                  //~va42I~
    ucs=(WUCS)altch;                                               //~va42I~
  }                                                                //~va44I~
  if (Phdc) //write to screen                                      //~va6uI~
	TextOutW(Phdc,Pxx,Pyy,&ucs,1);                                 //~va42I~
    UTRACEP("csubtextoutw1alt inp opt=%x,ucs=%x,out ucs=%x\n",Popt,Pucs,ucs);//~va46I~
    return ucs;         //written                                  //~va42R~
}                                                                  //~va42I~
//**************************************************************** //~va30I~
//*get column of csr position-1 and +1 and +0                      //~va30I~
//**************************************************************** //~va30I~
int csubgetcsrposbf(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Ppposc,int *Ppposa)//~va30R~
{                                                                  //~va30I~
    return utfddgetcsrposbca(Popt,Pdbcs,Plen,Ppos,Ppposb,Ppposc,Ppposa);//~va30R~
}//csubgetcsrposbf                                                 //~va30I~
//===============================================================================//~va6uM~
//locale code write string when ligature mode                      //~va6uM~
//===============================================================================//~va6uM~
int  csubtextoutw_locale_ligature(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen)//~va6uI~
{                                                                  //~va6uM~
    char   *pdata,*pdbcs;                                          //~va6uM~
    int dbcssw,ii,ucsctr,ucsalt;                                   //~va6uR~
    WUCS ucs;                                                      //~va6uR~
    WUCS wkucs[MAXCOL],*pwkucs;                                    //~va6uR~
    UWUCS ucs4;                                                    //~vb2HI~
    int utf16ctr;                                                  //~vb2HI~
    int mblen;                                                     //~vb2KI~
//************************************                             //~va6uM~
    pdata=Pdata;                                                   //~va6uM~
    pdbcs=Pdbcs;                                                   //~va6uM~
    UTRACED("strput_locale_ligature data",pdata,Plen);             //~va6uM~
    UTRACED("strput_locale_ligature dbcs",pdbcs,Plen);             //~va6uM~
    dbcssw=0;                                                      //~va6uM~
    ucsalt=0;                                                      //~va6uM~
    pwkucs=wkucs;                                                  //~va6uR~
    for (ii=0;ii<Plen;ii++,pdata++,pdbcs++)                        //~va6uM~
    {                                                              //~va6uM~
        if (!*pdata)                                               //~va6uM~
            *pdata=' ';                                            //~va6uM~
        ucs=(WUCS)*pdata;                                          //~va6uM~
        utf16ctr=0;                                                //~vb2HI~
        if (*pdbcs==UDBCSCHK_DBCS1ST && (ii+1)<Plen)               //~va6uM~
        {                                                          //~va6uM~
             mblen=UDBCSCHK_PCD_MBCHSZ(pdbcs,Plen-ii);             //~vb2KI~
  UTRACEP("dbcs ii=%d,%02x,%02x,mblen=%d\n",ii,*pdata,*(pdata+1),mblen);          //~va6uM~//~vb2KR~
            ucsalt=-1;                                             //~va6uM~
	        if (ucs==((PWXEINTF)Gpwxei)->WXEIunpdispchar[3] && *(pdata+1)==ucs)    //dbcsspace altch,may changed by ini file//~vb3qR~
            {                                                      //~vb3qI~
                ucsalt=csubtextoutw1alt(UTFGVACO_DBCSSPACE,0/*hdc*/,0/*x*/,0/*y*/,ucs);//~vb3qI~
                if (!ucsalt)                                         //no altch defined//~vb3qI~
	                ucsalt=csubtextoutw1alt(CSUBTOWAO_FORCE,0/*hdc*/,0/*x*/,0/*y*/,ucs);//~vb3qI~
            }                                                      //~vb3qI~
            else                                                   //~vb3qI~
          	if (ucs<0x20)                                          //~va6uM~
              	ucsalt=csubtextoutw1alt(0,0/*hdc*/,0/*x*/,0/*y*/,ucs);//~va6uR~
          	else                                                   //~va6uM~
//            if (ucs==DEFAULT_ALTCH && *(pdata+1)==DEFAULT_ALTCH)    //default DBCSSPACE altch//~va6uM~//~vb3qR~
//                ucsalt=csubtextoutw1alt(UTFGVACO_DBCSSPACE,0/*hdc*/,0/*x*/,0/*y*/,ucs);//~va6uR~//~vb3qR~
//            else                                                   //~va6uM~//~vb3qR~
          	if (ucs<0x80)                                          //~va6uM~
              	ucsalt='.';                                        //~va6uM~
            if (ucsalt<0)                                          //~va6uR~
            {                                                      //~vb2HI~
//        		if (utfcvl2uany1mb(0,pdata,2,pwkucs)<=0)           //~va6uR~//~v6unR~
//        		if (utfcvl2uany1mb(0,pdata,2,pwkucs,NULL/*prc*/)<=0)//~v6unI~//~vb2HR~
//        		if (utfcvl2uany1mb(0,pdata,2,&ucs4,NULL/*prc*/)<=0)//~vb2HI~//~vb2KR~
          		if (utfcvl2uany1mb(0,pdata,mblen,&ucs4,NULL/*prc*/)<=0)//~vb2KI~
                	ucsalt='.';                                    //~va6uR~
                else                                               //~vb2HI~
                {                                                  //~vb2HI~
                	UCS4_TO_UTF16(ucs4,pwkucs,&utf16ctr);          //~vb2HI~
                }                                                  //~vb2HI~
            }                                                      //~vb2HI~
            if (!ucsalt)	//no altch by cubtextoutw1alt          //~va6uR~
            	ucsalt=ucs;	//write org code                       //~va6uR~
            if (ucsalt>0)                                          //~va6uR~
//        		*pwkucs=ucsalt;                                    //~va6uM~//~vb06R~
          		*pwkucs=(WUCS)ucsalt;                              //~vb06I~
            pwkucs++;                                              //~va6uM~
          if (mblen>1)                                             //~vb2KI~
          	dbcssw=1;                                              //~va6uM~
            if (utf16ctr>1)                                        //~vb2HR~
            	pwkucs++;                                          //~vb2HI~
        }                                                          //~va6uM~
        else                                                       //~va6uM~
//      if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~va6uM~//~vb2KR~
        if (*pdbcs==UDBCSCHK_DBCS2ND||*pdbcs==UDBCSCHK_DBCSPAD)    //~vb2KI~
        {                                                          //~va6uM~
          	if (dbcssw)                                            //~va6uM~
          	{                                                      //~va6uM~
          		if (ucsalt>0)                                      //~va6uR~
//  				*pwkucs++=ucsalt;	//alt ch not written       //~va6uM~//~vb06R~
    				*pwkucs++=(WUCS)ucsalt;	//alt ch not written   //~vb06I~
            	continue;                                          //~va6uM~
          	}                                                      //~va6uM~
			*pwkucs++=*pdata;	//alt ch not written               //~va6uR~
        }                                                          //~va6uM~
        else                                                       //~va6uM~
        {                                                          //~va6uM~
            dbcssw=0;                                              //~va6uM~
          	ucsalt=UTF_GETALTCH_SBCSID(*pdbcs);                    //~va6uR~
          	if (ucsalt>=0)	//not tab/unp                          //~va6uR~
          		ucsalt=csubtextoutw1alt(ucsalt,0/*hdc*/,0/*x*/,0/*y*/,ucs);	//alt ch not written//~va6uR~
          	else                                                   //~va6uM~
          	if (ucs<0x20)                                          //~va6uM~
				ucsalt=csubtextoutw1alt(0,0/*hdc*/,0/*x*/,0/*y*/,ucs);//~va6uR~
          	else                                                   //~va6uM~
            {                                                      //~va6uI~
                ucs=*pdata;                                        //~va6uI~
                if (UTF8ISASCII(ucs))                              //~va6uR~
                    ucsalt=ucs;                                    //~va6uI~
                else                                               //~va6uI~
                {                                                  //~va6uI~
//         			if (utfcvl2uany1mb(0,pdata,1,pwkucs)<=0)       //~va6uR~//~v6unR~
//         			if (utfcvl2uany1mb(0,pdata,1,pwkucs,NULL/*prc*/)<=0)//~v6unI~//~vb2HR~
           			if (utfcvl2uany1mb(0,pdata,1,&ucs4,NULL/*prc*/)<=0)//~vb2HI~
                		ucsalt='.';                                //~va6uI~
                    else                                           //~va6uI~
                    {                                              //~vb2HI~
                		UCS4_TO_UTF16(ucs4,pwkucs,&utf16ctr);      //~vb2HI~
                    	ucsalt=*pwkucs;	                           //~va6uI~
                    }                                              //~vb2HI~
                }                                                  //~va6uI~
            }                                                      //~va6uI~
          	if (ucsalt)                                            //~va6uR~
            {                                                      //~vb2HI~
//  			*pwkucs++=ucsalt;                                  //~va6uI~//~vb06R~
    			*pwkucs++=(WUCS)ucsalt;                            //~vb06I~
                if (utf16ctr>1)                                    //~vb2HI~
                	pwkucs++;                                      //~vb2HI~
            }                                                      //~vb2HI~
            else                                                   //~va6uI~
				*pwkucs++=*pdata;                                  //~va6uM~
  UTRACEP("sbcs ii=%d,%02x\n",ii,*pdata);                          //~va6uM~
        }                                                          //~va6uM~
    }//for                                                         //~va6uM~
//  ucsctr=((ULONG)pwkucs-(ULONG)wkucs)/WUCSSZ;                    //~va6uR~//~vafkR~
//  ucsctr=((ULPTR)pwkucs-(ULPTR)wkucs)/WUCSSZ;                    //~vafkI~//~vb2WR~
    ucsctr=(int)((ULPTR)pwkucs-(ULPTR)wkucs)/WUCSSZ;               //~vb2WI~
    TextOutW(Phdc,Pxx,Pyy,wkucs,ucsctr);                           //~va6uR~
    UTRACED("csubtextoutw_locale_ligature ucs",wkucs,ucsctr*WUCSSZ);//~va6uR~
    return 0;                                                      //~va6uM~
}//csubtextoutw_locale_ligature                                    //~vb2HR~
//**************************************************************** //~va6vI~
//*                                                                //~va6vI~
//**************************************************************** //~va6vI~
int csubtextoutw1_locale(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,int Plen)//~va6vI~
{                                                                  //~va6vI~
	int ctr=1,swcverr=0;                                           //~va6vR~
	WUCS ucs,wkucs[2];                                             //~va6vI~
	UWUCS ucs4;                                                    //~vb2HI~
//**********************                                           //~va6vI~
//if (Popt & CSTOW1LO_NOTRANS)                                     //~va74R~//~vb2TR~
  if (Popt & CSTOW1LO_NOTRANS                                      //~vb2TI~
  &&  !(Gulibutfmode & GULIBSETLOCALERR)                           //~vb2TI~
  )                                                                //~vb2TI~
  {                                                                //~vb2QI~
	TextOut(Phdc,Pxx,Pyy,Pdata,Plen);                              //~va74I~
    UTRACED("NOTRANS TextOut",Pdata,Plen);                         //~vb2QI~
  }                                                                //~vb2QI~
  else                                                             //~va74I~
  {                                                                //~va74I~
//*!!! currently no caller !!!                                     //~vb2KI~
	if (Plen==1)                                                   //~va6vI~
    {                                                              //~va6vI~
		ucs=*Pdata;                                                //~va6vR~
        if (UTF8ISASCII(ucs))                                      //~va6vI~
        	wkucs[0]=ucs;                                          //~va6vI~
        else                                                       //~va6vI~
        {                                                          //~va6vI~
//      	if (utfcvl2uany1mb(0,Pdata,1,wkucs)<=0)                //~va6vR~//~v6unR~
//      	if (utfcvl2uany1mb(0,Pdata,1,wkucs,NULL/*prc*/)<=0)    //~v6unI~//~vb2HR~
        	if (utfcvl2uany1mb(0,Pdata,1,&ucs4,NULL/*prc*/)<=0)    //~vb2HI~
            {                                                      //~va6vI~
		        wkucs[0]='.';                                      //~va6vI~
                swcverr=1;                                         //~va6vI~
            }                                                      //~va6vI~
            else                                                   //~vb2HI~
            {                                                      //~vb2HI~
                UCS4_TO_UTF16(ucs4,wkucs,&ctr);                    //~vb2HI~
            }                                                      //~vb2HI~
                                                                   //~va6vI~
        }                                                          //~va6vI~
    }                                                              //~va6vI~
    else                                                           //~va6vI~
    {                                                              //~va6vI~
//      if (utfcvl2uany1mb(0,Pdata,Plen,wkucs)<=0)                 //~va6vR~//~v6unR~
//      if (utfcvl2uany1mb(0,Pdata,Plen,wkucs,NULL/*prc*/)<=0)     //~v6unI~//~vb2HR~
        if (utfcvl2uany1mb(0,Pdata,Plen,&ucs4,NULL/*prc*/)<=0)     //~vb2HI~
        {                                                          //~va6vI~
            wkucs[0]=wkucs[1]='.';                                 //~va6vI~
            ctr=2;                                                 //~va6vI~
            swcverr=1;                                             //~va6vI~
        }                                                          //~va6vI~
        else                                                       //~vb2HI~
        {                                                          //~vb2HI~
            UCS4_TO_UTF16(ucs4,wkucs,&ctr);                        //~vb2HI~
        }                                                          //~vb2HI~
    }                                                              //~va6vI~
    if (swcverr && (Popt & CSTOW1LO_LOCALEIFCVERR))                //~va6vI~
    {                                                              //~vb2QI~
		TextOut(Phdc,Pxx,Pyy,Pdata,Plen);                          //~va6vI~
    	UTRACED("cverr TextOut",Pdata,Plen);                       //~vb2QI~
    }                                                              //~vb2QI~
    else                                                           //~va6vI~
    {                                                              //~vb2QI~
		TextOutW(Phdc,Pxx,Pyy,wkucs,ctr);                          //~va6vR~
    	UTRACED("!NOTRANS TextOutW",wkucs,ctr*(int)sizeof(WUCS));                   //~vb2QI~//~vb2TR~
    }                                                              //~vb2QI~
  }                                                                //~va74I~
    return 0;                                                      //~va6vI~
}                                                                  //~va6vI~
#ifdef W32UNICODE                                                  //~vavzI~
//**************************************************************** //~vavzI~
//*WTL::CDCT have not TextOutW as member                           //~vavzI~
//**************************************************************** //~vavzI~
int csubtextoutWW(int Popt,HDC Phdc,int Pxx,int Pyy,UWCH *Pucs,int Pucsctr)//~vavzI~
{                                                                  //~vavzI~
	TextOutW(Phdc,Pxx,Pyy,Pucs,Pucsctr);                           //~vavzR~
    return 0;                                                      //~vavzI~
}                                                                  //~vavzI~
#endif                                                             //~vavzI~
#endif                                                             //~v907I~//~va20I~
//**************************************************************** //~vb4AI~
//*write altch                                                     //~vb4AI~
//**************************************************************** //~vb4AI~
int csubtextoutWcombining_notcombinemode(int Popt,HDC Phdc,int Pxx,int Pyy,WUCS *Pucs,int Pucsctr)//~vb4AI~
{                                                                  //~vb4AI~
    COLORREF currentcolor,altchcolor=RGB(0,255,0);   //high green  //~vb4AI~
//**********************                                           //~vb4AI~
    currentcolor=GetTextColor(Phdc);                               //~vb4AI~
    SetTextColor(Phdc,altchcolor);                                 //~vb4AI~
	if (UTF_COMBINEMODE_NP() && Gutfcombaltch)                     //~vb4AI~
    {                                                              //~vb4AI~
    	TextOutW(Phdc,Pxx,Pyy,&Gutfcombaltch,1);                   //+vb4AR~
	    UTRACEP("%s: UNICOMB UNPR Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~vb4AI~
    }                                                              //~vb4AI~
    else                                                           //~vb4AI~
    {                                                              //~vb4AI~
    	TextOutW(Phdc,Pxx,Pyy,Pucs,Pucsctr);                       //+vb4AR~
	    UTRACEP("%s: UNICOMB SPLIT ucs=%04x,ucsctr=%d\n",UTT,*Pucs,Pucsctr);//+vb4AR~
    }                                                              //~vb4AI~
    SetTextColor(Phdc,currentcolor);                               //~vb4AI~
    return 0;                                                      //~vb4AI~
}//csubtextoutWcombining_notcombinemode                            //~vb4AI~
