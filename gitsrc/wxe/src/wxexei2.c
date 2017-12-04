//*CID://+vbd2R~:                              update#=  777;      //~vbd2R~
//*********************************************************************//~v440I~
//* wxe interface definition;CAP,PRT                               //~3102R~
//*********************************************************************//~v440I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb2W:160404 W32 64 compiler warning                              //~vb2WI~
//vb2H:160307 (W32)UWCHART cut ucs4                                //~vb2HI~
//vb2B:160221 (Win)UCS4 support                                    //~vb2BI~
//vaz3:150106 (BUG)HANDLE is not ULONG but PVOID(8 byte)           //~vaz3I~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//vamD:131107 (BUG:wxe2010)wxe cmd was ignored.(PostMessage target window is parent)//~vamDI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafa:120607 (WXE2010)C4700 warning(used uninitialized variable)  //~vafaI~
//va8e:101003 (BUG:WXEXXE)bug of va87;no data was printed when pageno specified//~va8eI~
//va8d:101003 (BUG:WXEXXE)bug of va87;vhexmode limit by vhexline char:sbcs may 1 column width but hex 2 column//~va8dI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va89:100926 (WXE)contline dbcs position err for 2p print         //~va89I~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va85:100921 (BUG)wxp cmd;**/*** case,contline dbcstbl postion err(serious for utf8 file)//~va85I~
//va81:100920 (WXEXXE)print ebcfile by ucs for also wxp **/*** option//~va81I~//~va85R~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va7E:100830 (WXE:BUG)copy/cut was enabled status yet after copy done//~va7EI~
//va7A:100829 (WXE:EBC)handle support for mouse cap                //~va7AI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            0x0e,4481,0f,00,0a,00(setclipboatddata)-->0x0e00,4400,fb30,0000,0a00,0000(getclipboarddata)//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err code of utf8 file(u-00a4(Sun)->"?").//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//            CF_OEMTEXT will also translate such as 0x8586->0x8145(=u-30FB)//~va5yI~
//            for over session data identification set prefix at top of ebc data//~va5yI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va3z:100306 (WXEXXE:BUG)dblclick c&p length shortage             //~va3zI~
//va3w:100222 (WXE:BUG)C&P:paste rejected by "region not yet saved"//~va3wI~
//va3v:100222 (WXE:BUG)C&P miss translation clipboard data when dblclick at lineno column//~va3vI~
//va2m:100104 (BUG:WXE)dirlist print by lc name for utf8 filename  //~va2mI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va0u:090909_paste to cmdline wbend if clipboard data start from EOL//~va0uR~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76b:070617 support paste to =2 panel                            //~v731I~
//v731:061226*filesize>4GB support                                 //~v731I~
//v71A:061030 Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v70v:060903 (BUG:WXEXXE)miss paste last line to OS clipboard when copy by PFn//~v70vI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70aI~
//v70a:060730 (WXEXXE:BUG)word copy by mouse dblclick copy word with eolid//~v708R~
//v708:060730 (WXE:XXE)bug by v701;dbl click rejected by csr pos err//~v708I~
//v703:060726 (WXEXXE:BUG)if range is from cmd line to file area,pastev to file area.it should be cmd line//~v703I~
//v701:060726 (WXEXXE:BUGrgn restart msg issued when drrg over beyond screen slit line//~v701I~
//v700:060726 (WXEXXE:BUG)cut/del protection chk err(Point1 is already chked and may be scrolled out now)//~v670I~
//v69Z:060726 (WXEXXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v68b:060329 (BUG:WXE)drag from dirlist remains cp box;func_reset call reset also dnd selection,so simply call capreset//~v68bI~
//v675:051226 (BUG of v66j)abend by dup enq CB pcw when split scr,"e ::cb" at 2nd , paste in 1st,"e ::cb" at 1st;//~v675I~
//v66z:051211 (WXE:BUG)C&P miss last line eol at paste timing      //~v66zI~
//v66x:051211 (WXE:BUG)line dbl click is cursor pos err;support it (stay as block mode)//~v66xI~
//v66i:051023 (WXE)C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66iI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//v65h:050729 (BUG:WXE)hardcopy;fullpage is allways effective      //~v65hI~
//v64k:050623 (WXE:BUG)compiler warning(no initialized variable used);but no actual effect.//~v64kI~
//            because source pfh is clipboard(fhwidth=0)           //~v64kI~
//v627:050309 (WXE)vhex print support                              //~v626I~
//v626:050309 (WXE)for wxp **/***(set space lineno for cont line)  //~v626I~
//v61z:050308 (WXE)shorten DBCS split for vhex print               //~v61zI~
//            (prviously split dbcs data is printed 1 byte overflow width)//~v61zI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v552:040202 identify wxp ** by prefix filename like as xprint    //~v552I~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v53A:031013 (WXE)double click generate push and dblclick;shift+push means paste.//~v53AI~
//            so bell sound when shift+dblclick on filename-list,dir list etc.//~v53AR~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v51f:030525 (WXE:BUG)line counting miss for lrecl=0 line(page count err)//~v51fI~
//v500:021003 (WXE:BUG)initial color is all black.    over update#175//~2A03I~
//v500:020827 wxe support                                          //~v440I~
//*********************************************************************//~v440I~
#include <time.h>                                                  //~v440I~
#include <stdio.h>                                                 //~v440I~
#include <stddef.h>                                                //~2B16I~
#include <stdlib.h>                                                //~v440I~
#include <string.h>                                                //~v440I~
//*************************************************************    //~v440I~
#include <windows.h>                                               //~v440I~
//*************************************************************    //~v440I~
#include <ulib.h>                                                  //~v440I~
#include <uque.h>                                                  //~v440I~
#include <uvio.h>                                                  //~v440I~
#include <ufile.h>                                                 //~v440I~
#include <ufile4.h>                                                //~2B16I~
#include <udbcschk.h>                                              //~2915I~
#include <uerr.h>                                                  //~2928I~
#include <uedit.h>                                                 //~2B03I~
#include <ualloc.h>                                                //~2929I~
#include <utrace.h>                                                //~2929M~
#include <ustring.h>                                               //~2B16I~
#include <uedit2.h>                                                //~2B16I~
#include <ucalc2.h>                                                //~2B16I~
#include <udos.h>                                                  //~2B30I~
#include <ufemsg.h>                                                //~v731I~
#include <utf.h>                                                   //~v7abI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
                                                                   //~v440I~
#include "xe.h"                                                    //~v440R~
#include "xescr.h"                                                 //~v440I~
#include "xekbd.h"                                                 //~vamDM~
#include "xescr2.h"                                                //~2929I~
#include "xecsr.h"                                                 //~2929I~
#include "xefile.h"                                                //~v440I~
#include "xefile22.h"                                              //~v626I~
#include "xefile6.h"                                               //~2B02I~
#include "xedir.h"                                                 //~2B16I~
#include "xedir3.h"                                                //~2B16I~
#include "xepan.h"                                                 //~v440I~
#include "xegbl.h"                                                 //~2929I~
#include "xefunc.h"                                                //~2A03R~
#include "xesub.h"                                                 //~2929I~
#include "xesub2.h"                                                //~va50I~
#include "xecap.h"                                                 //~2A05I~
#include "xeopt.h"                                                 //~2B30I~
#include "xeerr.h"                                                 //~v701I~
#ifdef UTF8UCS2                                                    //~va20R~
#include "xeutf2.h"                                                //~va20R~
#endif                                                             //~va20R~
#include "xeebc.h"                                                 //~va50I~
                                                                   //~v440I~
#define  WXEXEI                                                    //~v440I~
#include "resource.h"                                              //~v54yI~
#include "wxemain.h"                                               //~v440M~
#include "wxexei.h"                                                //~v440I~
#include "wxecsub.h"                                               //~2901I~
//*************************************************************    //~2A05I~
//dir list print fmt                                               //~2B16I~
typedef struct _WDIRLD {                                           //~2B16I~
                        UCHAR  WDDlvl[UDDMAXLEVEL+2];      //10+2dir level//~2B16I~
                        UCHAR  WDDname[35];     //file name        //~2B16I~
						UCHAR  WDDrsv2;                            //~2B16I~
                        UCHAR  WDDattr[UDDATTRSZ];     	//4        //~2B16I~
    					UCHAR  WDDrsv3[1];                         //~2B16I~
                        UCHAR  WDDdate[8];     	//date             //~2B16I~
						UCHAR  WDDrsv4[1];                         //~2B16I~
                        UCHAR  WDDtime[5];     	//time             //~2B16I~
                        UCHAR  WDDsize[13];    	//size             //~2B16I~
					  	} WDIRLD;                                  //~2B16I~
typedef WDIRLD *PWDIRLD;                                           //~2B16I~
#define WDIRLDSZ (sizeof(WDIRLD))                                  //~2B16I~
                                                                   //~2B16I~
#define MASKINTSPACE  4                                            //~2C07I~
#define CONTLINEDELM '|'                                           //~v626I~
//*************************************************************    //~2B16I~
static int Ssplitsw,Slinectr,Seolid,Sdirmaxexplen;                 //~2C07R~
static int Sprtpageno,Sprtreslen/*,Sdbcssplitsw*/;                 //~v61zR~
static PULINEH Sprtplh;                                            //~2B02I~
static int Swkvhexlineid;                                          //~va87I~
static int Swkvhexoffs,Swkvhexoffsnext;                            //~va87R~
static int Swkvhexoffsvhex,Swkvhexoffsnextvhex;                    //~va8dI~
static PUCLIENTWE Sprtpcw;                                         //~v626I~
static char Swxporgfnm[_MAX_PATH+1];                               //~v65hR~
#ifdef W32UNICODE                                                  //~vavzI~
	static UWCH SwxporgfnmW[_MAX_PATHWC];                          //~vavzI~
#endif                                                             //~vavzI~
static int Swxpdatalinenosz;                                       //~v626I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
#define EBC_TEMPEOLID      0x00     //temporaly line delimiter for cap data//~va5yR~//~va50R~//~va5yR~
#define EBC_CBSTRPREFIX    0x00     //clipboard ebcdic string prefix(ucs2)//~va5yR~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
//*************************************************************    //~2B02I~
PULINEH wxe_prtgetnextplh(void);                                   //~2B02I~
int wxe_prtgetdatalen(PUFILEH Ppfh,PULINEH Pplh,int Preslen,int Pmaxcol,int *Pplen,char *Pdbcsdir);//~2C08R~
void wxe_ddsetup(PUFILEH Ppfh,PULINEH Pplh,char *Pdata);           //~2B16I~
int wxe_getddexpand(PULINEH Pplh);                                 //~2B16I~
int wxe_hexdisplay(int Puppersw,char *Pdata,char *Pdbcs,int Plen,char *Phexd,char *Phexw);//~2B30I~
#ifdef UTF8UCS2                                                    //~va20R~
int  wxe_dbcstextcopyu(int Popt,char *Pout,PULINEH Pplh,int Poutbuffsz,int *Ppoutlen);//~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
int  wxe_capb2u(int Popt,char *Pout,PULINEH Pplh,int Poutbuffsz,int *Ppoutlen);//~va5yR~
int  wxe_capu2b(int Popt,UCHAR *Pebcdata,int Plen,int *Ppreadlen,int *Ppoutlen,int *Ppeolid,int *Ppeofsw);//~va5yI~
//int  wxe_capu2ball(int Popt,UCHAR *Pcbdata,int Plen,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int *Ppebclen);//~va5yI~//~va79R~
int  wxe_capu2ball(int Popt,int handle,UCHAR *Pcbdata,int Plen,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int *Ppebclen);//~va79I~
#ifdef AAA                                                         //~va50I~
int wxexei_wxpb2m(int Popt,UCHAR *Poutdata,PULINEH Pplh,int Poffs,int Plen);//~va50R~
#define WXEXEIWXPB2MO_SCRPRT        0x01                           //~va50I~
#endif                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
//PULINEH wxe_prtgetnextplhwkvhex(int Popt,PULINEH *Ppplh,int *Pprc);//~va87R~//~va8eR~
PULINEH wxe_prtgetnextplhwkvhex(int Popt,int *Pprc);               //~va8eI~
int wxe_prtgetdatalenwkvhex(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Pmaxlrecl,int *Pplen);//~va87R~
//*************************************************************    //~2915I~
//*pass key cmd                                                    //~2A03I~
//*************************************************************    //~2A03M~
//int  wxe_strkeyin(int Prow,int Pcol,char *Pdata,int Plen)        //~2A05R~
//{                                                                //~2A05R~
//    int rc,ii,len,pos;                                           //~2A05R~
//    char *pci,*pco,*pc;                                          //~2A05R~
//    PUCLIENTWE pcw;                                              //~2A05R~
////***********************                                        //~2A05R~
//    rc=capchkpastepos(Prow,Pcol,Gcmdbuff,&pcw); //set pos cmd "pos n,m;"//~2A05R~
//    if (rc>0)                                                    //~2A05R~
//        return rc;  //bypass paste                               //~2A05R~
//    if (rc<0)       //cmdline paste                              //~2A05R~
//    {                                                            //~2A05R~
//        pos=-rc;                                                 //~2A05R~
//        len=strlen(Gcmdbuff);                                    //~2A05R~
//        pc=Gcmdbuff+pos;        //minus offset                   //~2A05R~
//        if (UCBITCHK(Gscrstatus,GSCRSINS)      //ins mode        //~2A05R~
//        &&  len>pos)                                             //~2A05R~
//        {                                                        //~2A05R~
//            memmove(pc+Plen,pc,len-pos+1);  //with last null     //~2A05R~
//            memcpy(pc,Pdata,Plen);                               //~2A05R~
//        }                                                        //~2A05R~
//        else                                                     //~2A05R~
//        {                                                        //~2A05R~
//            memcpy(pc,Pdata,Plen);                               //~2A05R~
//            if (len<pos+Plen)                                    //~2A05R~
//                *(pc+Plen)=0;                                    //~2A05R~
//        }                                                        //~2A05R~
//        setflddata(pcw,CMDLINENO,0,Gcmdbuff);//actual set len    //~2A05R~
//        *Gcmdbuff=0;        //avoid process at keyproc           //~2A05R~
//        *(Gcmdbuff+1)=0;    //drop long cmd id                   //~2A05R~
//        UCBITON((pcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);    //~2A05R~
////set csr to next of last char                                   //~2A05R~
//        scrsetcsrpos(Prow,Pcol+Plen);                            //~2A05R~
//        scrdisp();                                               //~2A05R~
//        return rc;                                               //~2A05R~
//    }                                                            //~2A05R~
//    pco=Gcmdbuff+strlen(Gcmdbuff);                               //~2A05R~
//    strcpy(pco,"KEY \"");                                        //~2A05R~
//    pco+=5;                                                      //~2A05R~
//    for (pci=Pdata,ii=0;ii<Plen;ii++)                            //~2A05R~
//    {                                                            //~2A05R~
//        if (*pci=='"')                                           //~2A05R~
//            *pco++='"'; //double quate                           //~2A05R~
//        *pco++=*pci++;                                           //~2A05R~
//    }                                                            //~2A05R~
//    *pco++='"';                                                  //~2A05R~
//    *pco++=0;                                                    //~2A05R~
//    rc=wxe_xecall(WXE_REQ_KEYEVENT,0,0,0);                       //~2A05R~
//    return rc;                                                   //~2A05R~
//}//wxe_strkeyin                                                  //~2A05R~
//*************************************************************    //~2B30I~
//*reset(Esc)                                                      //~2B30I~
//*ret 4:cursor pos err                                            //~2B30I~
//*************************************************************    //~2B30I~
int  wxe_iswinnt(void)                                             //~2B30I~
{                                                                  //~2B30I~
	return udosiswinnt();                                          //~2B30I~
}//wxe_iswinnt                                                     //~2B30I~
//*************************************************************    //~2A05I~
//*reset(Esc)                                                      //~2A05I~
//*ret 4:cursor pos err                                            //~2A05I~
//*************************************************************    //~2A05I~
int  wxe_reset(void)                                               //~2A05I~
{                                                                  //~2A05I~
	return wxe_funccall(FUNCID_RESET,"");                          //~2A20R~
}//wxe_reset                                                       //~2A05I~
//*************************************************************    //~2A06I~
//*reset(Esc)                                                      //~2A06I~
//*ret 4:cursor pos err                                            //~2A06I~
//*************************************************************    //~2A06I~
int  wxe_capreset(void)                                            //~2A06I~
{                                                                  //~2A06I~
	if (Gcappcw||Gcalcpcw)                                         //~2A06I~
    {                                                              //~v68bI~
//		wxe_funccall(FUNCID_RESET,"");                             //~v68bR~
        capreset(1);	//reset cp box                             //~v68bI~
        scrdisp();		//redraw req                               //~v68bI~
    }                                                              //~v68bI~
    return 0;                                                      //~2A06I~
}//wxe_reset                                                       //~2A06I~
//*************************************************************    //~2A03I~
//*cap block                                                       //~2A03I~
//p1:0:block start;1:end                                           //~2A03I~
//p4:in/out copy from panel data(not filedata)                     //~2A05I~
//*ret 4:cursor pos err                                            //~2A05R~
//*************************************************************    //~2A03I~
int  wxe_capblock(int Pstaend,int Prow,int Pcol,int *Ppancopysw)   //~2A05R~
{                                                                  //~2A03I~
    PUCLIENTWE pcw;                                                //~v701I~
	int rc;                                                        //~2A05I~
    int funcid;                                                    //~v66hI~
//************************                                         //~2A05I~
//  if (!Pstaend)	//block start                                  //~v66hR~
    if (Pstaend & CP_DRAGOPEN)	//block start                      //~v66hI~
    {                                                              //~2A05I~
		rc=capchkcsrpos(Prow,Pcol,0);	//rc 1:panel,0:filedata    //~2A05R~
		*Ppancopysw=(rc>1); 	//pan and cmdline                  //~2A12R~
        if (rc)			//panel copy                               //~2A05I~
        	return 0;                                              //~2A05I~
    }                                                              //~2A05I~
    else                                                           //~2A05I~
    {                                                              //~v701I~
    	if (*Ppancopysw)	//panel copy                           //~2A05I~
        	return 0;                                              //~2A05I~
      if (Pstaend & CP_DRAGCLOSE)	//drag close by lbup           //~v708I~
      {                                                            //~v708I~
    	scrcpgetpcw(Prow,Pcol,&pcw);	//get lbup position pcw    //~v701I~
        if (pcw!=Gcappcw)	//not same as start pcw                //~v701I~
        	return errcsrpos();                                    //~v701R~
      }                                                            //~v708I~
    }                                                              //~v701I~
//  rc=wxe_funccall(FUNCID_BLOCK,"");                              //~v66hR~
    if (Pstaend & CP_DRAGBLOCK) //block start                      //~v66hI~
        funcid=FUNCID_BLOCK;                                       //~v66hI~
    else                                                           //~v66hI~
        funcid=FUNCID_STDCPREGION;                                 //~v66hI~
    rc=wxe_funccall(funcid,"");                                    //~v66hI~
	return rc;                                                     //~2A05I~
}//wxe_capblock                                                    //~2A03I~
//*************************************************************    //~vbd2I~
//*cap selectall                                                   //~vbd2I~
//*ret 4:cursor pos err                                            //~vbd2I~
//*************************************************************    //~vbd2I~
int  wxe_capselectall(void)                                        //~vbd2I~
{                                                                  //~vbd2I~
	int rc=0;                                                      //~vbd2I~
    int funcid;                                                    //~vbd2I~
//************************                                         //~vbd2I~
    funcid=FUNCID_LINEMARK;                                        //~vbd2I~
  	Gwxestat|=GWXES_SELECTALL; //    0x1000 //parm to func_lmark_file//~vbd2I~
    rc=wxe_funccall(funcid,"");    //xecap:func_lmark_file         //~vbd2I~
  	Gwxestat&=~GWXES_SELECTALL; //    0x1000 //parm to func_lmark_file//~vbd2I~
	return rc;                                                     //~vbd2I~
}//wxe_capselectall                                                //~vbd2I~
//*************************************************************    //~2A03I~
//*cap copy from plh                                               //~2A03I~
//p1:cutsw 0:copy,1;cut,2:clear                                    //~2A06I~
//*ret 1:active changed                                            //~2A03I~
//*************************************************************    //~2A03I~
int  wxe_capcopy(int Pcutsw,int *Pplen)                            //~2A05R~
{                                                                  //~2A03I~
//    PUCLIENTWE pcw;                                              //~v675R~
    PUFILEH pfh;                                                   //~2A05R~
    PULINEH plh,plh1,plh2;                                         //~2A05I~
	int rc,funcid,totlen,dblclicksw;                               //~3206R~
    int copywordsw;                                                //~v70aR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,ucsctr;                                         //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
    int swebcfile;                                                 //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
//**********************                                           //~2A03I~
	if (Pcutsw & CP_DBLCLICK)                                      //~3202R~
    {                                                              //~3202I~
		Pcutsw &= ~CP_DBLCLICK;                                    //~3202R~
    	dblclicksw=1;                                              //~3202I~
    }                                                              //~3202I~
    else                                                           //~3202I~
    	dblclicksw=0;                                              //~3206R~
	if (Pcutsw & CP_COPYWORD)                                      //~v70aR~
    {                                                              //~v70aR~
		Pcutsw &= ~CP_COPYWORD;                                    //~v70aR~
    	copywordsw=1;                                              //~v70aR~
    }                                                              //~v70aR~
    else                                                           //~v70aR~
    	copywordsw=0;                                              //~v70aR~
	switch(Pcutsw)                                                 //~2A06I~
    {                                                              //~2A06I~
    case 1:		//cut                                              //~2A06I~
    	funcid=FUNCID_BLOCKDEL;	                                   //~2A06M~
        break;                                                     //~2A06I~
    case 2:     //clear                                            //~2A06I~
    	funcid=FUNCID_BLOCKCLEAR;                                  //~2A06I~
        break;                                                     //~2A06I~
    default:                                                       //~2A06I~
    	funcid=FUNCID_COPYTOCB;	                                   //~2A06M~
	}//cutsw                                                       //~2A06I~
	Gwxestat|=GWXES_MOUSECAPCOPY;		//flag for xecap,do not request copytowincb//~v70eI~
	rc=wxe_funccall(funcid,"");	                                   //~2A20R~
	Gwxestat&=~GWXES_MOUSECAPCOPY;		                           //~v70eI~
    if (rc)                                                        //~2A03I~
    	return rc;                                                 //~2A03I~
  if (!dblclicksw)                                                 //~3202I~
  {                                                                //~3202I~
//calc ::cb file data total len                                    //~2A05I~
//    pcw=Gcapcbpcw;                                               //~v675R~
//    if (!pcw)                                                    //~v675R~
//        return 4;                                                //~v675R~
//    pfh=((PUFILEC)pcw->UCWpfc)->UFCpfh;                          //~v675R~
    pfh=Gcapcbpfh;                                                 //~v675I~
    if (!pfh)                                                      //~v675I~
		return 4;                                                  //~v675I~
#ifdef UTF8UCS2                                                    //~va20R~
	swutf8file=FILEUTF8MODE(pfh);	//::cb cpu8 mode               //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
	swebcfile=PFH_ISEBC(pfh);                                      //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
	plh1=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line         //~2A05I~
	plh2=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//end line         //~2A05I~
	for (plh=plh1,totlen=0;plh;plh=UGETQNEXT(plh))                 //~3206R~
    {                                                              //~2A05I~
#ifdef UTF8UCS2                                                    //~va20I~
	  if (swutf8file)                                              //~va20R~
      {                                                            //~va20R~
        utfdd2u(0,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,0/*outucs buff*/,0/*outbuffsz*/,&ucsctr,0/*ucssbcsctr*/,0/*ucsdbcsctr*/);//~va20R~
    	totlen+=(ucsctr+2)*sizeof(WUCS);                           //~va20R~
UTRACEP("wxe_capcopy totlen=%d\n",totlen);                         //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
	  if (swebcfile)                                               //~va5yR~
    	totlen+=(plh->ULHlen+(plh->ULHeolid!=0)*2+1)*WUCSSZ; 	//3: add u-000d,u000a,u0000 for ucs line delimiter//~va5yR~
      else                                                         //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
    	totlen+=plh->ULHlen+2; 	//for 0d0a                         //~3206R~
		if (plh==plh2)                                             //~2A05I~
			break;                                                 //~2A05I~
	}//all plh                                                     //~2A05I~
    if (!totlen)                                                   //~3206M~
    	return 4;                                                  //~3206M~
#ifdef UTF8UCS2                                                    //~va20R~
  if (swutf8file)                                                  //~va20R~
	*Pplen=-totlen;		//notify ucslen                            //~va20R~
  else                                                             //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
  if (swebcfile)                                                   //~va5yR~
	*Pplen=-(totlen+(int)WUCSSZ);		//notify ucslen            //~va5yR~
  else                                                             //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
	*Pplen=totlen;		//last line is padded null only            //~3206R~
  }//not dblclick                                                  //~3202I~
  	if (copywordsw)                                                //~v70aR~
    {                                                              //~v70aR~
	    pfh=Gcapcbpfh;                                             //~v70aR~
    	if (!pfh)                                                  //~v70aR~
			return 4;                                              //~v70aR~
		plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line     //~v70aR~
		plh->ULHeolid=0;                                           //~v70aR~
		plh->ULHeolidid=0;                                         //~v70aR~
		UCBITON(plh->ULHflag4,ULHF4NOEOL);//skip write eol at save //~v70aR~
    }                                                              //~v70aR~
	return 0;                                                      //~2A03I~
}//wxe_capcopy                                                     //~2A03I~
//*************************************************************    //~3202I~
//*cap copy from by dblclick                                       //~3202I~
//p1:cutsw 0:copy,1;cut,2:clear                                    //~3202I~
//p3/p4:grobal csr pos                                             //~3202I~
//*ret 1:active changed                                            //~3202I~
//*************************************************************    //~3202I~
int  wxe_capcopy2(int Pcutsw,int *Pplen,int Prow,int Pcol)         //~3202I~
{                                                                  //~3202I~
    PUCLIENTWE pcw;                                                //~3202I~
	PUSCRD  psd;                                                   //~3202I~
    PULINEH plh;                                                   //~3202I~
    PUFILEC pfc;                                                   //~3202I~
	int ii,rc=0,copypansw=0,pos,cols,cole,totlen,ulhlen,opt;       //~v66xR~
    int copywordsw=0;                                              //~v70aR~
    char *pc;                                                      //~3202R~
#ifdef UTF8UCS2                                                    //~va20I~
    char *pcd,*pcd0,*pc0;                                          //~va20I~
	int swutf8file,ucsctr;                                         //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//******************************                                   //~3202I~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~3202I~
    pfc=pcw->UCWpfc;                                               //~3202R~
    psd=pcw->UCWpsd;                                               //~3202R~
    psd+=Prow-pcw->UCWorgy;                                        //~3202R~
    plh=psd->USDbuffc;                                             //~3202I~
    ulhlen=plh->ULHlen;                                            //~3202I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(plh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Pcol<(int)pcw->UCWlinenosz)	//lineno col;line mode         //~3202R~
    {                                                              //~3202I~
#ifdef UTF8UCS2                                                    //~va3vI~
		swutf8file=PLHUTF8MODE(plh);                               //~va3vI~
#endif                                                             //~va3vI~
    	opt=CP_DRAGBLOCK; //block mode                             //~v66xR~
//      rc=wxe_capblock(0,Prow,Pcol,&copypansw); //start capblock  //~v66xR~
        rc=wxe_capblock(opt,Prow,Pcol,&copypansw); //start capblock//~v66xI~
		opt|=CP_DRAGOPEN;   	//drag end                         //~v66xI~
        if (!rc)                                                   //~3202R~
//      	rc=wxe_capblock(1,Prow,Pcol,&copypansw); //end capblock//~v66xR~
        	rc=wxe_capblock(opt,Prow,Pcol,&copypansw); //end capblock//~v66xI~
#ifdef UTF8UCS2                                                    //~va3zI~
      if (swutf8file)                                              //~va3zI~
      {                                                            //~va3zI~
        utfdd2u(0,plh->ULHdata,plh->ULHdbcs,ulhlen,0/*outucs buff*/,0/*outbuffsz*/,&ucsctr,0/*ucssbcsctr*/,0/*ucsdbcsctr*/);//~va3zI~
    	totlen=(ucsctr+2)*sizeof(WUCS);                            //~va3zI~
      }                                                            //~va3zI~
      else                                                         //~va3zI~
#endif                                                             //~va3zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
    	totlen=(ulhlen+(plh->ULHeolid!=0)*2+1)*sizeof(WUCS);       //~va50R~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        totlen=ulhlen+2;                                           //~3206R~
UTRACEP("wxe_capcopy2 line copy totlen=%d\n",totlen);              //~va3zI~
    }//line cap                                                    //~3202I~
    else 		//cs is on file data                               //~3202I~
    {                                                              //~3202I~
#ifdef UTF8UCS2                                                    //~va20I~
		swutf8file=PLHUTF8MODE(plh);                               //~va20I~
    	pc0=plh->ULHdata;                                          //~va20I~
    	pcd0=plh->ULHdbcs;                                         //~va20I~
#endif                                                             //~va20I~
    	copywordsw=CP_COPYWORD;                                    //~v70aR~
    	pos=pfc->UFCleft+Pcol-pcw->UCWlinenosz-pcw->UCWorgx;       //~3202R~
    	pc=plh->ULHdata+pos;                                       //~3202I~
        if (pos<ulhlen)                                            //~3202R~
        {                                                          //~3202I~
            cols=pos;                                              //~3202I~
#ifdef UTF8UCS2                                                    //~va20I~
			pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                         //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	     	if (UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))  //~va50I~
	#else                                                          //~va50I~
	     	if (UTF_eqspace(swutf8file,*pc,*pcd))                  //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	     	if (*pc==' ')                                          //~3202I~
#endif                                                             //~va20I~
            {                                                      //~3202I~
                pc=plh->ULHdata+pos;                               //~3202I~
                ii=ulhlen-pos;                                     //~3202I~
                for (cole=pos;ii>0;ii--,pc++)                      //~3202I~
                {                                                  //~3202I~
#ifdef UTF8UCS2                                                    //~va20I~
					pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                 //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	     			if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
	#else                                                          //~va50I~
	     			if (UTF_nespace(swutf8file,*pc,*pcd))          //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                    if (*pc!=' ')                                  //~3202I~
#endif                                                             //~va20I~
                        break;                                     //~3202I~
                    cole++;                                        //~3202I~
                }                                                  //~3202I~
            }                                                      //~3202I~
            else                                                   //~3202I~
            {                                                      //~3202I~
                for (ii=pos;ii>=0;ii--,pc--)                       //~3202R~
                {                                                  //~3202R~
#ifdef UTF8UCS2                                                    //~va20I~
					pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                 //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	     			if (UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
	#else                                                          //~va50I~
	     			if (UTF_eqspace(swutf8file,*pc,*pcd))          //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                    if (*pc==' ')                                  //~3202R~
#endif                                                             //~va20I~
                        break;                                     //~3202R~
                    cols--;                                        //~3202R~
                }                                                  //~3202R~
                cols++;                                            //~3202R~
                pc=plh->ULHdata+pos;                               //~3202I~
                cole=pos;                                          //~3202I~
            }                                                      //~3202I~
            ii=ulhlen-pos;                                         //~3202R~
            for (;ii>0;ii--,pc++)                                  //~3202R~
            {                                                      //~3202I~
#ifdef UTF8UCS2                                                    //~va20I~
				pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	     		if (UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
	#else                                                          //~va50I~
	     		if (UTF_eqspace(swutf8file,*pc,*pcd))              //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                if (*pc==' ')                                      //~3202R~
#endif                                                             //~va20I~
                    break;                                         //~3202I~
                cole++;                                            //~3202I~
            }                                                      //~3202I~
            Gwxecpposx=cols+1;	//confirm plus                     //~3202R~
            rc=wxe_capblock(0,Prow,Pcol,&copypansw); //start capblock//~3202R~
            Gwxecpposx=cole+1;                                     //~3202R~
            UCBITON(plh->ULHflag,ULHFDRAW);	//normaly not drawn at close//~3202I~
            if (!rc)                                               //~3202R~
                rc=wxe_capblock(1,Prow,Pcol,&copypansw); //change col to draw line//~v3202~//~3203R~
            Gwxecpposx=0;		//no parm                          //~3202I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (swebcfile)                                           //~va50I~
          {                                                        //~va50I~
 	       	totlen=(1+cole-cols+1)*sizeof(WUCS);	//prefix and last null        //~va50I~//~va5yR~
          }                                                        //~va50I~
          else                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          {                                                        //~va50I~
 	       	totlen=cole-cols+2;	//last null                        //~3206R~
#ifdef UTF8UCS2                                                    //~va20I~
          	if (swutf8file)                                        //~va20I~
            {                                                      //~va20I~
        		utfdd2u(0,pc0+cols,pcd0+cols,cole-cols,0/*outucs buff*/,0/*outbuffsz*/,&ucsctr,0/*ucssbcsctr*/,0/*ucsdbcsctr*/);//~va20R~
    			totlen=(ucsctr+2)*sizeof(WUCS);                    //~va20I~
UTRACEP("wxe_capcopy2 totlen=%d\n",totlen);                        //~va20I~
            }                                                      //~va20I~
#endif                                                             //~va20I~
          }//!ebc                                                  //~va50I~
        }                                                          //~3202I~
        else                                                       //~3206I~
        {                                                          //~3206I~
            totlen=0;   //dummy                                    //~3206I~
            rc=4;                                                  //~3206I~
        }                                                          //~3206I~
    }//word cap                                                    //~3202I~
    if (!rc)                                                       //~3202R~
//    	rc=wxe_capcopy(Pcutsw|CP_DBLCLICK,Pplen);                  //~v70aR~
      	rc=wxe_capcopy(Pcutsw|CP_DBLCLICK|copywordsw,Pplen);       //~v70aR~
#ifdef UTF8UCS2                                                    //~va20I~
    if (swutf8file)                                                //~va20I~
        totlen=-totlen; //notify ucs2 fmt to caller                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    else                                                           //~va50I~
    if (swebcfile)                                                 //~va50I~
        totlen=-totlen; //notify ucs2 fmt to caller                //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    *Pplen=totlen;                                                 //~3206I~
	return rc;                                                     //~3202I~
}//wxe_capcopy2                                                    //~3202I~
//*************************************************************    //~2A03I~
//*cap copy to windows cb from xe ::cb                             //~2A05R~
//called from wxemouse to set data to windows clipboard            //~va5yI~
//p1:0:block start;1:end                                           //~2A03I~
//*ret 4:err,1:data is unicode text                                //~2A05R~//~va20R~
//*************************************************************    //~2A03I~
int  wxe_capcopytowincb(char *Pdata,int Plen)                      //~2A05R~
{                                                                  //~2A03I~
//    PUCLIENTWE pcw;                                              //~v675R~
    PUFILEH pfh;                                                   //~2A05R~
    PULINEH plh,plh1,plh2;                                         //~2A05I~
	char *pc;                                                      //~2A05R~
    int len,totlen,lasteolsw=0;                                    //~3206R~
    int lasteol=0;                                                 //~v66zR~
#ifdef UTF8UCS2                                                    //~va20R~
	int swutf8file,rc2;                                            //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
	int swebcfile,swebc1st=1;                                      //~va5yR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
//**********************                                           //~2A03I~
//    pcw=Gcapcbpcw;                                               //~v675R~
//    if (!pcw)                                                    //~v675R~
//        return 4;                                                //~v675R~
//    pfh=((PUFILEC)pcw->UCWpfc)->UFCpfh;                          //~v675R~
    pfh=Gcapcbpfh;                                                 //~v675I~
    if (!pfh)                                                      //~v675I~
		return 4;                                                  //~v675I~
#ifdef UTF8UCS2                                                    //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
  	Gwxecapebchandle=pfh->UFHhandle;	//::CB handle              //~va7AI~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
	swebcfile=PFH_ISEBC(pfh);                                      //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
	plh1=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line         //~2A05R~
	plh2=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//end line         //~2A05R~
//calc total len                                                   //~2A05I~
	for (plh=plh1,pc=Pdata,totlen=0;plh;plh=UGETQNEXT(plh))        //~v70vR~
    {                                                              //~2A05I~
        lasteolsw=0;                                               //~3206I~
#ifdef UTF8UCS2                                                    //~va20R~
      if (swutf8file)                                              //~va20R~
      {                                                            //~va20R~
		rc2=wxe_dbcstextcopyu(0,pc,plh,Plen-totlen/*for last null*/,&len);	//dd2u and add 0d0a//~va20R~
        totlen+=len;                                               //~va20R~
        pc+=len;                                                   //~va20R~
        if (rc2)                                                   //~va20R~
        	break;                                                 //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
	  if (swebcfile)                                               //~va5yI~
      {                                                            //~va5yI~
		wxe_capb2u(swebc1st,pc,plh,Plen-totlen/*buff reslen*/,&len);//~va5yR~
        swebc1st=0;                                                //~va5yI~
        totlen+=len;                                               //~va5yI~
        pc+=len; 	//output area                                  //~va5yI~
      }                                                            //~va5yI~
      else                                                         //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
      {                                                            //~va20R~
    	len=plh->ULHlen;                                           //~2A05I~
        totlen+=len;                                               //~3206R~
        if (totlen>=Plen)                                          //~3206R~
        	break;                                                 //~2A05I~
		wxe_dbcstextcopy(pc,plh->ULHdata,0,len);                   //~2A05I~
        pc+=len;                                                   //~3206M~
        totlen+=2;                                                 //~3206I~
//      if (totlen>=Plen)                                          //~v66zR~
//      	break;                                                 //~v66zR~
                                                                   //~va50I~
    	*pc++='\r';  				//eol id                       //~2A05R~
    	*pc++='\n';  				//eol id                       //~2A05I~
      }                                                            //~va20R~
        lasteol=plh->ULHeolid;                                     //~v66zI~
        lasteolsw=1;                                               //~3206R~
		if (plh==plh2)                                             //~2A05I~
			break;                                                 //~2A05I~
        if (totlen>=Plen)                                          //~v66zI~
        	break;                                                 //~v66zI~
	}//all plh                                                     //~2A05I~
    if (!totlen)                                                   //~2A05I~
    	return 4;                                                  //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
  if (!swutf8file)                                                 //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
  if (!swebcfile)                                                  //~va5yI~
#endif                                                             //~va5yI~
  {                                                                //~va20R~
    if (lasteolsw)                                                 //~3206R~
      if (!lasteol)                                                //~v66zI~
    	pc-=2;                                                     //~3206I~
    *pc=0;	//end of text for CF_TEXT fmt                          //~3206I~
  }                                                                //~va20R~
  UTRACED("capcopytowincb",Pdata,Plen);                            //~va20R~
	return 0;                                                      //~2A03I~
}//wxe_capcopytowincb                                              //~2A05R~
//*************************************************************    //~v70eI~
//*cap copy to windows cb from xe after save to ::cb by pfkey operation//~v70eI~
//*ret                                                             //~v70eI~
//*************************************************************    //~v70eI~
int  wxe_capcopytowincbfromxe(void)                                //~v70eI~
{                                                                  //~v70eI~
    PUFILEH pfh;                                                   //~v70eI~
    PULINEH plh,plh1,plh2;                                         //~v70eI~
	char *pcg;                                                     //~v70eR~
//  ULONG handle;                                                  //~vaz3R~
    HANDLE handle;                                                 //~vaz3I~
    int totlen;                                                    //~v70eR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,ucsctr;                                         //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**********************                                           //~v70eI~
    pfh=Gcapcbpfh;                                                 //~v70eI~
    if (!pfh)                                                      //~v70eI~
		return 4;                                                  //~v70eI~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(pfh);	//::cb cpu8 mode               //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);	//::cb cpeb                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	plh1=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line         //~v70eI~
	plh2=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//end line         //~v70eI~
//calc total len                                                   //~v70eI~
//	for (plh=plh1,totlen=0;plh && plh!=plh2;plh=UGETQNEXT(plh))    //~v70vR~
    for (plh=plh1,totlen=0;plh;plh=UGETQNEXT(plh))                 //~v70vI~
    {                                                              //~v70vI~
#ifdef UTF8UCS2                                                    //~va20I~
	  if (swutf8file)                                              //~va20I~
      {                                                            //~va20I~
        utfdd2u(0,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,0/*outucs buff*/,0/*outbuffsz*/,&ucsctr,0/*ucssbcsctr*/,0/*ucsdbcsctr*/);//~va20I~
    	totlen+=(ucsctr+2)*sizeof(WUCS);                           //~va20I~
UTRACEP("wxe_capcopy totlen=%d\n",totlen);                         //~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
    	totlen+=(plh->ULHlen+(plh->ULHeolid!=0)*2+1)*sizeof(WUCS); //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	totlen+=plh->ULHlen+2;                                     //~v70eR~
        if (plh==plh2)                                             //~v70vI~
            break;                                                 //~v70vI~
    }                                                              //~v70vI~
    if (!totlen)                                                   //~v70eI~
    	return 4;                                                  //~v70eI~
    if (!uopenclipboard())                                         //~v70eI~
    	return 4;                                                  //~v70eI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
	if (swebcfile)                                                 //~va5yI~
    	totlen+=WUCSSZ;	//prefix                                   //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
    pcg=uglobalalloc(totlen+1,&handle);                            //~v70eI~
    if (!pcg)                                                      //~v70eI~
    	return 4;                                                  //~v70eI~
	wxe_capcopytowincb(pcg,totlen);                                //~v70eI~
UTRACED("Clipboard copytowincbfromxe usetclipboard",pcg,totlen);   //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
  if (swutf8file)                                                  //~va20I~
    usetclipboard(handle,CF_UNICODETEXT);                          //~va20I~
  else                                                             //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (swebcfile)                                                   //~va50I~
    usetclipboard(handle,CF_UNICODETEXT);                          //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    usetclipboard(handle,CF_TEXT);                                 //~v70eI~
    ucloseclipboard();                                             //~v70eI~
	return 0;                                                      //~v70eI~
}//wxe_capcopytowincbfromxe                                        //~v70vR~
//*************************************************************    //~2A03I~
//*cap copy to plh                                                 //~2A03R~
//*called from wxemouse                                            //~va5yI~
//*ret 1:active changed                                            //~2A03I~
//*************************************************************    //~2A03I~
int  wxe_cappaste(int Pinssw,int Prow,int Pcol,char *Pdata,int Plen)//~2A05R~
{                                                                  //~2A03I~
    PUCLIENTWE pcw;                                                //~2A05I~
//  PUFILEH    pfh;                                                //~va79I~//~va7AR~
	int rc,funcid;                                                 //~2A03I~
    int row;                                                       //~v703I~
#ifdef UTF8UCS2                                                    //~va20I~
    char *pc,*pcd;                                                 //~va20I~
    int ddlen;                                                     //~va20I~
    int pinssw;                                                    //~va3wI~
//  int handle=0;                                                  //~va79I~//~va7AR~
    int handle;                                                    //~va7AI~
#endif                                                             //~va20I~
//**********************                                           //~2A03I~
UTRACED("wxe_cappaste data",Pdata,Plen);                           //~va20R~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~va79I~
//  pfh=UGETPFHFROMPCW(pcw);                                       //~va79R~//~va7AR~
//  if (pfh)                                                       //~va79I~//~va7AR~
//      handle=pfh->UFHhandle;                                     //~va79R~//~va7AR~
	Ssplitsw=0;Slinectr=0;Seolid=0;                                //~2A05I~
	Gwxecapdataoffs=0;               //copyed len                  //~2A05R~
	Gwxecapdatalen=Plen;            //total data len               //~2A05R~
	Gwxecapbuff=Pdata;                                             //~2A05I~
#ifdef UTF8UCS2                                                    //~va20M~
    pinssw=Pinssw;                                                 //~va3wI~
    Pinssw&=WXECPO_MASK;//for later mode chk                       //~va3wI~
	Gwxecapdbcs=0;                                                 //~va20I~
    Gwxestat&=~GWXES_CPDATAUCS;         //data is unicodetext      //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
    Gwxestat&=~GWXES_CPDATAEBC;         //data is unicodetext of ebcdic code//~va5yI~
#endif                                                             //~va5yI~
    if (Pdata && Plen)                                             //~va20I~
    {                                                              //~va20I~
//      if (Pinssw & WXECPO_UCS)                                   //~va3wR~
        if (pinssw & WXECPO_UCS)                                   //~va3wI~
        {                                                          //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
//  	  if (*(WUCS*)(ULONG)Pdata==EBC_CBSTRPREFIX)               //~va5yR~//~vafkR~
    	  if (*(WUCS*)(ULPTR)Pdata==EBC_CBSTRPREFIX)               //~vafkI~
          {                                                        //~va5yI~
          	handle=Gwxecapebchandle;	//hadle at ebc ucs2 created(::CB handle)//~va7AI~
            Gwxestat|=GWXES_CPDATAEBC;          //data is unicodetext callback from fcmdgetcopyline//~va5yI~
            Gwxecapdbcs=umalloc(Plen+1);          //ucs2 shrink 1/2,use as data+dbcs//~va5yI~
            UALLOCCHK(Gwxecapdbcs,UALLOC_FAILED);                  //~va5yI~
            Gwxecapbuff=Gwxecapdbcs+Plen/WUCSSZ;//pcg is accessible but dont change,it is used for next paste//~va5yI~
//  		wxe_capu2ball(0,Pdata,Plen,Gwxecapbuff,Gwxecapdbcs,&ddlen);//~va5yI~//~va79R~
    		wxe_capu2ball(0,handle,Pdata,Plen,Gwxecapbuff,Gwxecapdbcs,&ddlen);//~va79I~
            Pdata=Gwxecapbuff;//pcg is accessible but dont change,it is used for next paste//~va5yI~
            Gwxecapdatalen=ddlen;            //total data len      //~va5yI~
UTRACED("cappaste capbuff",Gwxecapbuff,ddlen);                     //~va5yI~
UTRACED("cappaste capdbcs",Gwxecapdbcs,ddlen);                     //~va5yI~
          }                                                        //~va5yI~
          else                                                     //~va5yI~
#endif                                                             //~va5yI~
          {                                                        //~va5yI~
            Gwxestat|=GWXES_CPDATAUCS;          //data is unicodetext callback from fcmdgetcopyline//~va20R~
//          if (xeutfcvu2dd(0,(PWUCS)(ULONG)Pdata,Plen,&pc,&pcd,&ddlen)==UALLOC_FAILED)//~va20R~//~vafkR~
            if (xeutfcvu2dd(0,(PWUCS)(ULPTR)Pdata,Plen,&pc,&pcd,&ddlen)==UALLOC_FAILED)//~vafkI~
                return UALLOC_FAILED;                              //~va20R~
            Gwxecapdbcs=umalloc(ddlen+ddlen+2/*last null*/);       //~va20R~
            UALLOCCHK(Gwxecapdbcs,UALLOC_FAILED);                  //~va20R~
            Pdata=Gwxecapbuff=Gwxecapdbcs+ddlen+1;//pcg is accessible but dont change,it is used for next paste//~va20R~
            UmemcpyZ(Gwxecapbuff,pc,ddlen);                        //~va20R~
            UmemcpyZ(Gwxecapdbcs,pcd,ddlen);                       //~va20R~
            Gwxecapdatalen=ddlen;            //total data len      //~va20R~
UTRACED("cappaste capbuff",Gwxecapbuff,ddlen);                     //~va20R~
UTRACED("cappaste capdbcs",Gwxecapdbcs,ddlen);                     //~va20R~
          }//!ebc                                                  //~va5yI~
        }                                                          //~va20R~
    }                                                              //~va20I~
#endif                                                             //~va20M~
//  scrcpgetpcw(Prow,Pcol,&pcw);                                   //~2A05R~//~va79R~
    row=Prow-pcw->UCWorgy;  //rcsry of Point1                      //~v703R~
//  if (pcw->UCWrcsry!=CMDLINENO)	//paste to file area           //~v703R~
    if (row!=CMDLINENO)	//paste to file area                       //~v703I~
    {                                                              //~v76bR~
	 if (((PUPANELC)pcw->UCWppc)->UPCid==PANFEDIT)                 //~v731I~
     {                                                             //~v731I~
      if (Pdata)    //data exist on windows CB                     //~v66iR~
      {                                                            //~v66iR~
		Gwxestat|=GWXES_MOUSECAPPASTE;		//flag for xecap,req callback//~2A05R~
		rc=capsavedata(pcw);                //once copy clipboard to ::cb//~2A05R~
		Gwxestat&=~GWXES_MOUSECAPPASTE;		//flag for xecap       //~2A05R~
	    if (rc)                                                    //~2A05I~
    		return rc;                                             //~2A05I~
      }                                                            //~v66iR~
     }//editfile scr                                               //~v76bR~
    }                                                              //~2A05I~
    if (Pinssw==2)                                                 //~v66hI~
    	funcid=FUNCID_STDCPPASTE;                                  //~v66hI~
    else                                                           //~v66hI~
	if (Pinssw)                                                    //~2A03I~
    	funcid=FUNCID_BLOCKINS;                                    //~2A03I~
    else                                                           //~2A03I~
    	funcid=FUNCID_BLOCKREP;                                    //~2A03I~
	Gwxecapdataoffs=0;                   //copyed len,cmdline paste//~2A05I~
	Ssplitsw=0;Slinectr=0;Seolid=0;                                //~2A05I~
  if (Pdata)    //windows CB data exist                            //~v66iR~
	Gwxestat|=GWXES_MOUSECAPPASTE;		//flag for xecap,req callback when cmdline paste//~2A05I~
	rc=wxe_funccall(funcid,"");                                    //~2A20R~
	Gwxestat&=~GWXES_MOUSECAPPASTE;		//flag for xecap           //~2A05I~
    if (rc)                                                        //~2A05M~
    	return rc;                                                 //~2A05M~
	return 0;                                                      //~2A03I~
}//wxe_cappaste                                                    //~2A03I~
//*************************************************************    //~v53AI~
//*cap copy to plh                                                 //~v53AI~
//*ret 1:active changed                                            //~v53AI~
//*************************************************************    //~v53AI~
int  wxe_cappasteposchk(int Prow,int Pcol)                         //~v53AR~
{                                                                  //~v53AI~
    PUCLIENTWE pcw;                                                //~v53AI~
	int row,pcid,rc;                                               //~v53AR~
//**********************                                           //~v53AI~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~v53AI~
//  row=pcw->UCWrcsry;                                             //~v703R~
    row=Prow-pcw->UCWorgy;  //rcsry of Point1                      //~v703I~
    if (!row)           //hdr line                                 //~v53AI~
        return 1;		//ignore                                   //~v53AI~
    if (row==CMDLINENO)	//paste to cmd line                        //~v53AI~
        return 0;	//do paste                                     //~v53AI~
                                                                   //~v53AI~
	pcid=((PUPANELC)pcw->UCWppc)->UPCid;                           //~v53AR~
	switch(pcid)                                                   //~v53AI~
    {                                                              //~v53AI~
	case PANTOPMENU:                                               //~v53AI~
		rc=1;	//ignore                                           //~v53AI~
		break;                                                     //~v53AI~
	case PANFNAME  :		//filename                             //~v53AI~
      if (row==PANL300FILENAME	//paste to filename line           //~v76jR~
      ||  row==PANL300DIR)		//paste to dirname line            //~v76bR~
		rc=0;	//ignore                                           //~v76bR~
      else                                                         //~v76bR~
		rc=1;	//ignore                                           //~v53AI~
		break;                                                     //~v53AI~
	case PANDIR   :		//dir list                                 //~v53AI~
		rc=1;	//ignore                                           //~v53AI~
		break;                                                     //~v53AI~
    case PANFBROWSE:                                               //~v53AI~
		rc=1;	//ignore                                           //~v53AI~
		break;                                                     //~v53AI~
    case PANFEDIT:                                                 //~v53AI~
		rc=0;       //do paste                                     //~v53AI~
		break;                                                     //~v53AI~
    case PANUCOMP:                                                 //~v76jI~
    case PANUGREP:                                                 //~v76jI~
		rc=0;       //do paste                                     //~v76jI~
		break;                                                     //~v76jI~
    default:;   //PANOPTCOLOR                                      //~v53AI~
		rc=1;	//ignore                                           //~v53AI~
    }                                                              //~v53AI~
	return rc;                                                     //~v53AI~
}//wxe_cappasteposchk                                              //~v53AI~
//*************************************************************    //~2A03I~
//*cap copy to plh callback from xe to wxe one line data            //~2A03I~//~va20R~
//*p1:max line width, no limit when 0                              //~2A05I~
//*p2:out data addr                                                //~2A05I~
//*p2:optional out dbcs data addr                                  //~2A05I~
//*p3:out data len bt (cr+)lf                                      //~2A05I~
//*p4:optional out line continue id                                //~2A05I~
//*p5:optional out line ctr                                        //~2A05I~
//*p6:optional out eol id len                                      //~2A05I~
//*p7:optional data offset from top                                //~2A05I~
//rc:-1:eof                                                        //~2A05R~
//*************************************************************    //~2A03I~
int  wxe_cappastecallback(void *Ppfh,int Pmaxwidth,char **Ppdata,char **Ppdbcs,int *Pplen,//~3112R~
							int *Psplitsw,int *Plinectr,int *Peolid,int *Plineoffs)//~2A05I~
{                                                                  //~2A03I~
	char *pc,*pc0;                                                 //~2A03I~
	int len,eofsw,eolid,splitsw;                                   //~2A05R~
    PUFILEH pfh;                                                   //~3112I~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8data;                                                //~va20I~
	char *pcd0;                                                    //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
    int swebcdata,readlen=0;                                       //~vafaR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
//**********************                                           //~2A03I~
    pfh=(PUFILEH)Ppfh;                                             //~3112I~
	if (Gwxecapdataoffs>=Gwxecapdatalen)                           //~2A05R~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
		UFREECLEARIFNZ(Gwxecapdbcs);                               //~va20I~
#endif                                                             //~va20I~
    	return -1;  	//eof                                      //~2A05R~
    }                                                              //~va20I~
	pc0=Gwxecapbuff+Gwxecapdataoffs;                               //~2A05R~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8data=(Gwxestat & GWXES_CPDATAUCS);    		//data is unicodetext callback from fcmdgetcopyline//~va20I~
	pcd0=Gwxecapdbcs+Gwxecapdataoffs;                              //~va20I~
//  UTRACED("pastecallback capbuff",pc0,Gwxecapdatalen-Gwxecapdataoffs);//~va20R~//~va5yR~
//  UTRACED("pastecallback capbbcs",pcd0,Gwxecapdatalen-Gwxecapdataoffs);//~va20R~//~va5yR~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
    swebcdata=(Gwxestat & GWXES_CPDATAEBC);    		//data is unicodetext callback from fcmdgetcopyline//~va5yI~
 if (swebcdata)                                                    //~va5yR~
 {                                                                 //~va5yR~
	wxe_capu2b(0,pc0,Gwxecapdatalen-Gwxecapdataoffs,&readlen,&len,&eolid,&eofsw);//~va5yR~
 }                                                                 //~va5yR~
 else                                                              //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
 {//!ebc                                                           //~va5yI~
  if (pfh && UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))                //~3112R~
  {                                                                //~3112I~
#ifdef UTF8UCS2                                                    //~va20I~
    pc=UTF_strchr(swutf8data,pc0,pcd0,'\r');    		//data is unicodetext callback from fcmdgetcopyline//~va20I~
#else                                                              //~va20I~
    pc=strchr(pc0,'\r');                                           //~3112R~
#endif                                                             //~va20I~
    if (pc)                                                        //~3112I~
    {                                                              //~3112I~
    	eolid=4;                                                   //~3112I~
//  	len=(ULONG)pc-(ULONG)pc0;                                  //~3112I~//~vafkR~
//  	len=(ULPTR)pc-(ULPTR)pc0;                                  //~vafkI~//~vb2WR~
    	len=(int)((ULPTR)pc-(ULPTR)pc0);                           //~vb2WI~
        eofsw=0;                                                   //~3112I~
    }                                                              //~3112I~
    else                                                           //~3112I~
    {                                                              //~3112I~
    	eolid=0;                                                   //~3112I~
#ifdef UTF8UCS2                                                    //~va20I~
    	len=UTF_strlen(swutf8data,pc0,pcd0);                       //~va20I~
#else                                                              //~va20I~
    	len=strlen(pc0);                                           //~3112I~
#endif                                                             //~va20I~
        eofsw=1;                                                   //~3112I~
    }                                                              //~3112I~
  }                                                                //~3112I~
  else                                                             //~3112I~
  {                                                                //~3112I~
#ifdef UTF8UCS2                                                    //~va20I~
    pc=UTF_strchr(swutf8data,pc0,pcd0,'\n');    		//data is unicodetext callback from fcmdgetcopyline//~va20I~
#else                                                              //~va20I~
    pc=strchr(pc0,'\n');                                           //~2A05R~
#endif                                                             //~va20I~
    if (pc)                                                        //~2A03I~
    {                                                              //~2A03I~
    	eolid=1;                                                   //~2A05I~
//  	len=(ULONG)pc-(ULONG)pc0;                                  //~2A05R~//~vafkR~
//  	len=(ULPTR)pc-(ULPTR)pc0;                                  //~vafkI~//~vb2WR~
    	len=(int)((ULPTR)pc-(ULPTR)pc0);                           //~vb2WI~
        if (len)                                                   //~2A05I~
#ifdef UTF8UCS2                                                    //~va20I~
        	if (UTF_eq(swutf8data,*(pc-1),*XEUTF_PC2PCD(pcd0,pc-1,pc0),'\r'))//~va20R~
#else                                                              //~va20I~
        	if (*(pc-1)=='\r')	//crlf                             //~2A05I~
#endif                                                             //~va20I~
            {                                                      //~2A05I~
            	eolid=2;                                           //~2A05I~
            	len--;                                             //~2A05I~
            }                                                      //~2A05I~
#ifdef UTF8UCS2                                                    //~va20I~
      if (UTF_nenull(swutf8data,*(pc+1),*XEUTF_PC2PCD(pcd0,pc+1,pc0)))//~va20R~
#else                                                              //~va20I~
      if (*(pc+1))                                                 //~v66zI~
#endif                                                             //~va20I~
        eofsw=0;                                                   //~2A03I~
      else                                                         //~v66zI~
        eofsw=1;                                                   //~v66zI~
    }                                                              //~2A03I~
    else                                                           //~2A03I~
    {                                                              //~2A03I~
    	eolid=0;                                                   //~2A05I~
#ifdef UTF8UCS2                                                    //~va20I~
    	len=UTF_strlen(swutf8data,pc0,pcd0);                       //~va20R~
#else                                                              //~va20I~
    	len=strlen(pc0);                                           //~2A05R~
#endif                                                             //~va20I~
        eofsw=1;                                                   //~2A03I~
    }                                                              //~2A03I~
  }//not mac                                                       //~3112I~
 }//!ebc                                                           //~va5yI~
  UTRACED("wxe_cappastecallback",pc0,len);                         //~va20R~
	*Ppdata=pc0;                                                   //~2A03I~
    if (Pmaxwidth && len>Pmaxwidth)                                //~2A05R~
    {                                                              //~2A05I~
    	len=Pmaxwidth;                                             //~2A05I~
        eolid=0;                                                   //~2A05I~
//      splitsw|=Ssplitsw|ULHF2SPLIT1;                             //~v64kR~
        splitsw=Ssplitsw|ULHF2SPLIT1;                              //~v64kI~
        Ssplitsw|=ULHF2SPLIT2;		//next is follower             //~2A05I~
    }                                                              //~2A05I~
    else                                                           //~2A05I~
    {                                                              //~2A05I~
        splitsw=Ssplitsw;                                          //~2A05I~
        Ssplitsw=0;                                                //~2A05I~
    }                                                              //~2A05I~
    *Pplen=len;                                                    //~2A03I~
    if (Ppdbcs)                                                    //~2A05I~
    {                                                              //~2A05I~
      if (len)                                                     //~va0uR~
      {                                                            //~va0uR~
#ifdef UTF8UCS2                                                    //~va20M~
       if (Ppfh)	//called from fcmdgetwincbdata,read until eof  //~va20I~
       {                                                           //~va20I~
       		if (swutf8data)  //clipboard data is unicodetext       //~va20R~
       			*Ppdbcs=pcd0;                                      //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
			else                                                   //~va5yI~
       		if (swebcdata)                                         //~va5yI~
       			*Ppdbcs=pcd0;                                      //~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yI~
            else                                                   //~va20I~
       			*Ppdbcs=0; //captofld donot ufree by chekking CPDATUCS//~va20I~
       }                                                           //~va20I~
       else	//called from captofld,captofld do ufree               //~va20R~
       if (swutf8data)  //clipboard data is unicodetext            //~va20I~
       {                                                           //~va20I~
       		*Ppdbcs=pcd0;	//captofld,call one and free returned pcd//~va20I~
			Gwxecapdbcs=0;                                         //~va20I~
       }                                                           //~va20I~
       else                                                        //~va20I~
#endif                                                             //~va20M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~//~va5yM~
       if (swebcdata)                                             //~va50I~//~va5yI~
       {                                                           //~va5yI~
       		*Ppdbcs=pcd0;	//captofld,call one and free returned pcd//~va5yI~
			Gwxecapdbcs=0;                                         //~va5yI~
       }                                                           //~va5yI~
       else                                                       //~va50I~//~va5yI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yM~
       {                                                           //~va20R~
    	if (!(*Ppdbcs=umalloc(len)))                               //~2A05I~
        	return UALLOC_FAILED;                                  //~2A05I~
		setdbcstbl(pc0,*Ppdbcs,len);                               //~2A05R~
       }                                                           //~va20I~
      }                                                            //~va0uR~
      else                                                         //~va0uR~
    	*Ppdbcs=0;                                                 //~va0uR~
    }                                                              //~2A05I~
UTRACED("wxe_cappastecallback outdata",*Ppdata,len);               //~va20R~
UTRACEDIFNZ("wxe_cappastecallback outdbcs",*Ppdbcs,len);           //~va20R~
UTRACEP("wxe_cappastecallback return eolid=%d,eofsw=%d,splitsw=%d\n",eolid,eofsw,splitsw);//~va20R~
    Slinectr++;                                                    //~2A05I~
    if (Peolid)                                                    //~2A05I~
	    *Peolid=eolid;                                             //~2A05R~
    if (Plinectr)                                                  //~2A05I~
    	*Plinectr=Slinectr;                                        //~2A05I~
    if (Psplitsw)                                                  //~2A05I~
	    *Psplitsw=splitsw;                                         //~2A05R~
    if (Plineoffs)                                                 //~2A05I~
    	*Plineoffs=Gwxecapdataoffs;		//offset in file           //~2A05I~
    if (eofsw)                                                     //~2A03I~
    	Gwxecapdataoffs=Gwxecapdatalen;	//nex time return eof      //~2A05R~
    else                                                           //~2A03I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yI~
    if (swebcdata)                                                 //~va5yI~
    	Gwxecapdataoffs+=readlen;                                  //~va5yI~
	else                                                           //~va5yR~
#endif                                                             //~va5yI~
    	Gwxecapdataoffs+=len+eolid;                                //~2A05R~
	return 0;                                                      //~2A03I~
}//wxe_cappastecallback                                            //~2A05R~
//*************************************************************    //~2A05M~
//*chk paste available position                                    //~2A05I~
//*ret :0:paste avail pos                                          //~2A05I~
//*************************************************************    //~2A05M~
//int  wxe_capchkprot(int Prow,int Pcol)                           //~v76jR~
int  wxe_capchkprot(int Popt,int Prow,int Pcol)                    //~v76jI~
{                                                                  //~2A05M~
	PUCLIENTWE pcw;                                                //~2A12I~
	PUFILEC    pfc;                                                //~2A12I~
    int rc;                                                        //~2A12R~
    char stat2;                                                    //~v76jR~
//***********************                                          //~2A05M~
    if (Prow<0 && Pcol<0)   //cut chk                              //~v700I~
    {                                                              //~v700I~
        if (!Gcappcw)                                              //~v700I~
            return 1;   //protected err                            //~v700I~
        pcw=Gcappcw;                                               //~v700I~
        if (pcw->UCWtype!=UCWTFILE) //dir list cut is not supported//~v700I~
            return 1;   //err                                      //~v700I~
        pfc=pcw->UCWpfc;                                           //~v700I~
        if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v700I~
            return 1;   //err                                      //~v700I~
		return 0;                                                  //~v700I~
    }                                                              //~v700I~
    rc=capchkcsrpos(Prow,Pcol,&pcw);                             //~2A12R~
	if (Popt & WXECCP_DRAGED)        	//box/rgn;std paste availability chk//~v76jR~
    {                                                              //~v76jI~
UTRACEP("wxe_capchkprot pos rc=%d\n",rc);                          //~v76jI~
    	if (rc)	//not file text area	                           //~v76jI~
        	return 1;	//std paste not avail                      //~v76jR~
        capgetxestat(0,&stat2);                                    //~v76jR~
UTRACEP("wxe_capchkprot stat =%x\n",stat2);                        //~vbd2I~
        if (stat2 & SBLOCK2STDREGION)                              //~v76jI~
        	return 0;      //rgn mode,std paste available          //~v76jR~
        return 1;                                                  //~v76jR~
    }                                                              //~v76jI~
    switch(rc)                                                   //~2A12R~
    {                                                            //~2A12R~
    case 0:     //file data area                                 //~2A12R~
    case 1:     //file lineno fld                                //~2A12R~
        pfc=pcw->UCWpfc;                                         //~2A12R~
        if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                   //~2A12R~
            rc=1;   //protected                                  //~2A12R~
        else                                                     //~2A12R~
            rc=0;   //not protected;                             //~2A12R~
        break;                                                   //~2A12R~
    case 2:     //cmd input line                                 //~2A12R~
    case 3:     //paste available pan fld                          //~v76jI~
	  if (Popt & WXECCP_STDPASTE)        	//box/rgn;std paste availability chk//~v76jI~
      	rc=1;   //ins/rep only for cmdline/utility panel           //~v76jI~
      else                                                         //~v76jI~
        rc=0;   //not protected;                                 //~2A12R~
        break;                                                   //~2A12R~
    default:    //pan scr                                        //~2A12R~
        rc=1;   //protected                                      //~2A12R~
    }                                                            //~2A12R~
    return rc;                                                     //~2A12R~
}//wxe_chkprot                                                     //~2A12R~
//*************************************************************    //~v69ZR~
//*chk cap block is closed on file by key operation                //~v69ZR~
//*ret :1:closed block exist                                       //~v69ZR~
//*************************************************************    //~v69ZR~
int  wxe_capchkxestat(void)                                        //~v69ZR~
{                                                                  //~v69ZR~
    PUCLIENTWE pcw;                                                //~v69ZR~
    char stat1;                                                    //~v69ZR~
//***********************                                          //~v69ZR~
    if (wxe_getpcw(&pcw)!=PRTTYPE_FILE)                            //~v69ZR~
        return 0;                                                  //~v69ZR~
    if (pcw!=Gcappcw)                                              //~v69ZR~
        return 0;                                                  //~v69ZR~
    capgetxestat(&stat1,0);                                        //~v69ZI~
    if (stat1 & SBLOCKCLOSED)                                      //~v69ZR~
      if (!(stat1 & SBLOCKSAVED))                                  //~va7EI~
        return 1;                                                  //~v69ZR~
    return 0;                                                      //~v69ZR~
}//wxe_capchkxestat                                                //~v69ZR~
//*************************************************************    //~vbd2I~
//*chk selectall menu enable                                       //~vbd2I~
//*ret :1:enable                                                   //~vbd2I~
//*************************************************************    //~vbd2I~
int  wxe_capchkselectall(void)                                     //~vbd2I~
{                                                                  //~vbd2I~
    PUCLIENTWE pcw;                                                //~vbd2I~
    int rc=1;                                                      //~vbd2I~
	PUFILEC pfc;                                                   //~vbd2I~
	PUFILEH pfh;                                                   //~vbd2I~
//***********************                                          //~vbd2I~
    rc=(wxe_getpcw(&pcw)==PRTTYPE_FILE);                           //~vbd2R~
UTRACEP("%s:rc=%d\n",UTT,rc);                                      //~vbd2R~
	if (rc)	//file                                                 //~vbd2I~
    {                                                              //~vbd2I~
		pfc=pcw->UCWpfc;                                           //~vbd2R~
		pfh=pfc->UFCpfh;                                           //~vbd2I~
		if (pfh->UFHtype==UFHTCLIPBOARD)                           //~vbd2I~
    		rc=0;	//disable                                      //~vbd2I~
    }                                                              //~vbd2I~
    return rc;                                                     //~vbd2I~
}//wxe_capchkselectall                                             //+vbd2R~
//*************************************************************    //~2A05I~
//*copy dbcs data                                                  //~2A05I~
//*ret :0                                                          //~2A05I~
//*************************************************************    //~2A05I~
int  wxe_dbcstextcopy(char *Pout,char *Pdata,char *Pdbcs,int Plen) //~2A05I~
{                                                                  //~2A05I~
	int ii;                                                        //~2A05I~
    char *pco,*pci;                                                //~2A05I~
//***********************                                          //~2A05I~
    for (ii=0,pco=Pout,pci=Pdata;ii<Plen;ii++)                     //~2A05I~
    {                                                              //~2A05I~
        if (!(*pco++=*pci++))                                      //~2A05I~
        	*(pco-1)=' ';                                          //~2A05I~
    }                                                              //~2A05I~
    if (Pdbcs)	//dbcs prepaired and chk required                  //~2A05I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    xesub_setdbcssplit(0,0/*plh*/,Pout,Pdbcs,Plen,' ');	//clear dbcs id for dbcs chardel at end of fld abend//~va50I~
#else                                                              //~va50I~
	    setdbcssplit(Pout,Pdbcs,Plen,' ');	//clear dbcs id for dbcs chardel at end of fld abend//~2A05I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	return 0;                                                      //~2A05I~
}//wxe_dbcstextcopy                                                //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
//*************************************************************    //~va20R~
//*copy dbcs data                                                  //~va20R~
//*ret :0,MALLOC FAILED                                            //~va20R~
//*************************************************************    //~va20R~
int  wxe_dbcstextcopyu(int Popt,char *Pout,PULINEH Pplh,int Poutbuffsz,int *Ppoutlen)//~va20R~
{                                                                  //~va20R~
	WUCS *pucs;                                                    //~va20R~
    int ucslen,reslen,len,rc;                                      //~va20R~
    int opt;                                                       //~va5yI~
//***********************                                          //~va20R~
	*Ppoutlen=0;                                                   //~va20R~
//  rc=xeutfcvdd2u(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,&pucs,&ucslen);//~va20R~//~va5yR~
	opt=XEUTFDD2UO_NULLREP;         //replace null to errch for utf_strxx//~va5yI~
    rc=xeutfcvdd2u(opt,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,&pucs,&ucslen);//~va5yI~
    if (rc)         //MALLOC FAILED                                //~va20R~
    	return rc;                                                 //~va20R~
    reslen=(Poutbuffsz/WUCSSZ)*WUCSSZ;                             //~va20R~
    if (reslen<=0)                                                 //~va20R~
    	return 1;                                                  //~va20R~
    len=min(reslen,ucslen);                                        //~va20R~
    memcpy(Pout,pucs,(UINT)len);                                   //~va20R~
    if (reslen-len>=4)                                             //~va20I~
    {                                                              //~va20I~
//      pucs=(WUCS*)(ULONG)(Pout+len);                             //~va20I~//~vafkR~
        pucs=(WUCS*)(ULPTR)(Pout+len);                             //~vafkI~
    	if (Pplh->ULHeolid)                                        //~va20R~
	    	*pucs++='\r';  				//eol id                   //~va20R~
    	else                                                       //~va20R~
	    	*pucs++=0;  				//del eol id               //~va20R~
    	*pucs++='\n';  				//like as not utf8 file        //~va20R~
	    len+=2*WUCSSZ;                                             //~va20R~
    }                                                              //~va20I~
    *Ppoutlen=len;                                                 //~va20R~
UTRACEP("wxe_dbcstextcopyu buffsz=%d,reslen=%d,outlen=%d,ucslen=%d\n",Poutbuffsz,reslen,len,ucslen);//~va20R~
UTRACED("wxe_dbcstextcopyu",Pout,len);                             //~va20R~
	return 0;                                                      //~va20R~
}//wxe_dbcstextcopyu                                               //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5yI~
//*************************************************************    //~va5yI~
//*copy ebcdic data byte by bye as ucs2 fmt,no dbcs split consideration//~va5yI~
//*************************************************************    //~va5yI~
int  wxe_capb2u(int Popt,char *Pout,PULINEH Pplh,int Poutbuffsz,int *Ppoutlen)//~va5yR~
{                                                                  //~va5yI~
	WUCS *pucs;                                                    //~va5yI~
    UCHAR *pci;                                                    //~va5yI~
    int ii,outlen,reslen,trailersz;                                //~va5yR~
//***********************                                          //~va5yI~
	*Ppoutlen=0;                                                   //~va5yI~
//  pucs=(WUCS*)(ULONG)Pout;                                       //~va5yI~//~vafkR~
    pucs=(WUCS*)(ULPTR)Pout;                                       //~vafkI~
    if (Popt & 0x01)	//1stsw                                    //~va5yI~
    	*pucs++=EBC_CBSTRPREFIX;                                   //~va5yR~
    for (ii=0,pci=Pplh->ULHdata,ii=Pplh->ULHlen,reslen=Poutbuffsz; //~va5yR~
				ii>0;                                              //~va5yI~
				ii--,reslen-=2)                                    //~va5yI~
    {                                                              //~va5yI~
    	if (reslen<2)                                              //~va5yI~
        	break;                                                 //~va5yI~
        if (!(*pucs++=(WUCS)(*pci++)))                             //~va5yR~
        	*(pucs-1)=' ';         //avoid null is set             //~va5yI~
    }                                                              //~va5yI~
    if (Pplh->ULHeolid)                                            //~va5yI~
    	trailersz=6; //0d,0a,00                                    //~va5yR~
    else                                                           //~va5yI~
    	trailersz=2; //00                                          //~va5yR~
    if (reslen>=trailersz)                                         //~va5yR~
    {                                                              //~va5yI~
    	if (Pplh->ULHeolid)                                        //~va5yI~
    	{                                                          //~va5yI~
			*pucs++='\r';                                          //~va5yI~
			*pucs++='\n';                                          //~va5yI~
    	}                                                          //~va5yR~
		*pucs++=EBC_TEMPEOLID;  				//line delimiter   //~va5yR~
    }                                                              //~va5yI~
//  outlen=(ULONG)pucs-(ULONG)Pout;                                //~va5yI~//~vafkR~
//  outlen=(ULPTR)pucs-(ULPTR)Pout;                                //~vafkI~//~vb2WR~
    outlen=(int)((ULPTR)pucs-(ULPTR)Pout);                         //~vb2WI~
    *Ppoutlen=outlen;                                              //~va5yI~
	return 0;                                                      //~va5yI~
}//wxe_capb2u                                                      //~va5yR~
//*************************************************************    //~va5yI~
//*copy get ebcdic by data from clipboard data(ucs2 fmt)           //~va5yI~
//*************************************************************    //~va5yI~
//int wxe_capu2ball(int Popt,UCHAR *Pcbdata,int Plen,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int *Ppebclen)//~va5yI~//~va79R~
int wxe_capu2ball(int Popt,int Phandle,UCHAR *Pcbdata,int Plen,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int *Ppebclen)//~va79I~
{                                                                  //~va5yI~
	WUCS *pucs,*pucs0,ucs;                                         //~va5yR~
    UCHAR *pco,*pco0,*pcd;                                         //~va5yR~
    int ebclen,reslen;                                             //~va5yR~
//***********************                                          //~va5yI~
//  pucs=(WUCS*)(ULONG)Pcbdata;                                    //~va5yI~//~vafkR~
    pucs=(WUCS*)(ULPTR)Pcbdata;                                    //~vafkI~
    pucs++;		//skip prefix                                      //~va5yI~
    for (pco=Pebcdata,reslen=Plen;reslen>1;)                       //~va5yR~
    {                                                              //~va5yI~
        for (pucs0=pucs,pco0=pco;reslen>1;)                        //~va5yR~
        {                                                          //~va5yI~
            ucs=*pucs++;                                           //~va5yI~
            *pco++=(UCHAR)ucs;                                     //~va5yI~
            reslen-=2;                                             //~va5yI~
            if (ucs==EBC_TEMPEOLID)                                //~va5yI~
                break;                                             //~va5yI~
        }                                                          //~va5yI~
//  	ebclen=(ULONG)pco-(ULONG)pco0;                             //~va5yI~//~vafkR~
//  	ebclen=(ULPTR)pco-(ULPTR)pco0;                             //~vafkI~//~vb2WR~
    	ebclen=(int)((ULPTR)pco-(ULPTR)pco0);                      //~vb2WI~
        pcd=UTF_PC2PCD(Pebcdbcs,pco0,Pebcdata);                    //~va5yR~
//  	xeebc_setdbcstbl(0,pco0,pcd,ebclen);                       //~va5yI~//~va79R~
    	xeebc_setdbcstbl(0,Phandle,pco0,pcd,ebclen);               //~va79I~
    }                                                              //~va5yI~
//  ebclen=(ULONG)pco-(ULONG)Pebcdata;                             //~va5yI~//~vafkR~
//  ebclen=(ULPTR)pco-(ULPTR)Pebcdata;                             //~vafkI~//~vb2WR~
    ebclen=(int)((ULPTR)pco-(ULPTR)Pebcdata);                      //~vb2WI~
    *Ppebclen=ebclen;                                              //~va5yR~
	return 0;                                                      //~va5yI~
}//wxe_capu2ball                                                   //~va5yI~
//*************************************************************    //~va5yI~
//*get ebcdic line                                                 //~va5yR~
//*************************************************************    //~va5yI~
int  wxe_capu2b(int Popt,UCHAR *Pebcdata,int Plen,int *Ppreadlen,int *Ppoutlen,int *Ppeolid,int *Ppeofsw)//~va5yR~
{                                                                  //~va5yI~
    UCHAR *pc;                                                     //~va5yR~
    int readlen,eolid,eofsw,reslen,outlen;                         //~va5yR~
//***********************                                          //~va5yI~
	pc=memchr(Pebcdata,0,Plen);                                    //~va5yI~
    if (!pc)                                                       //~va5yI~
    {                                                              //~va5yI~
    	readlen=Plen;                                              //~va5yI~
        pc=Pebcdata+readlen;                                       //~va5yI~
    }                                                              //~va5yI~
    else                                                           //~va5yI~
//  	readlen=(ULONG)pc-(ULONG)Pebcdata;                         //~va5yR~//~vafkR~
//  	readlen=(ULPTR)pc-(ULPTR)Pebcdata;                         //~vafkI~//~vb2WR~
    	readlen=(int)((ULPTR)pc-(ULPTR)Pebcdata);                  //~vb2WR~
    outlen=readlen;                                                //~va5yI~
    if (readlen>=2                                                 //~va5yR~
    &&  *(pc-2)=='\r' && *(pc-1)=='\n'                             //~va5yR~
    )                                                              //~va5yI~
    {                                                              //~va5yI~
    	eolid=2;                                                   //~va5yI~
        outlen-=2;                                                 //~va5yR~
    }                                                              //~va5yI~
    else                                                           //~va5yI~
    	eolid=0;                                                   //~va5yI~
    readlen++;                                                     //~va5yI~
    reslen=Plen-readlen;                                           //~va5yR~
    if (reslen<2)   //malloc 1 byte over for strz                  //~va5yR~
    	eofsw=1;                                                   //~va5yI~
    else                                                           //~va5yI~
    	eofsw=0;                                                   //~va5yI~
    *Ppreadlen=readlen;                                            //~va5yR~
    *Ppoutlen=outlen;                                              //~va5yI~
    *Ppeolid=eolid;                                                //~va5yI~
    *Ppeofsw=eofsw;                                                //~va5yI~
	return 0;                                                      //~va5yI~
}//wxe_capu2b                                                      //~va5yR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5yI~
//*************************************************************    //~va20R~
//*copypan,create ucs clipboard data from screen data(localeand dd mixed)//~va20R~
//*ret :1 if ucs found,0:all locale                                //~va20R~
//*************************************************************    //~va20R~
int  wxe_dbcstextcopypan(int Popt,char *Pout,char *Pdata,char *Pdbcs,int Plen,int *Pplenucs)//~va20R~
{                                                                  //~va20R~
	int reslen,ucsctr=0,chsz,dbcsid,swgetlen,swucs=0;              //~va20R~
    WUCS *pucs,ucs;                                                //~va20R~
    WUCS  wkwucs[2];                                               //~vb2HI~
    int utf16ctr;                                                  //~vb2HI~
    UWUCS ucs4;                                                    //~vb2HI~
    char *pc,*pcd;                                                 //~va20R~
//***********************                                          //~va20R~
UTRACED("textcopypan in data",Pdata,Plen);                         //~va20R~
UTRACED("textcopypan in dbcs",Pdbcs,Plen);                         //~va20R~
	swgetlen=Popt & WXEDTCPO_GETLENGTH;     //no output area       //~va20R~
//  for (reslen=Plen,pucs=(PWUCS)(ULONG)Pout,pc=Pdata,pcd=Pdbcs;reslen>0;reslen-=chsz,pc+=chsz,pcd+=chsz,ucsctr++)//~va20R~//~vafkR~
    for (reslen=Plen,pucs=(PWUCS)(ULPTR)Pout,pc=Pdata,pcd=Pdbcs;reslen>0;reslen-=chsz,pc+=chsz,pcd+=chsz,ucsctr++)//~vafkI~
    {                                                              //~va20R~
    	dbcsid=*pcd;                                               //~va20R~
        chsz=1;                                                    //~va20R~
        utf16ctr=0;                                                //~vb2HI~
        if (UDBCSCHK_DBCS1STU(dbcsid))                             //~va20R~
        {                                                          //~va20R~
        	swucs=1;                                               //~va20R~
		 	if (reslen>1)	//ucs dcs1st                           //~va20R~
            {                                                      //~va20R~
        	  if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                    //~vb2BI~
              {                                                    //~vb2BI~
        		ucs4=UTF_GETUCSDBCSOVF(pc,pcd);                    //~vb2BR~
                UCS4_TO_UTF16(ucs4,wkwucs,&utf16ctr);              //~vb2BI~
                ucs=wkwucs[0];                                     //~vb2BI~
              }                                                    //~vb2BI~
              else                                                 //~vb2BI~
        		ucs=UTF_GETUCSDBCS(pc);                            //~va20R~
        		chsz=2;                                            //~va20R~
            }                                                      //~va20R~
            else                                                   //~va20R~
            	ucs=' ';                                           //~va20R~
        }                                                          //~va20R~
        else                                                       //~va20R~
        if (UDBCSCHK_ISUCSSBCS(dbcsid))	//ucs dcs1st               //~va20R~
        {                                                          //~va20R~
        	swucs=1;                                               //~va20R~
        	ucs=(WUCS)UTF_GETUCSSBCS(pc,pcd);                      //~va20R~
        }                                                          //~va20R~
        else                                                       //~va20R~
        if (dbcsid==UDBCSCHK_DBCS1ST)                              //~va20R~
        {                                                          //~va20R~
			if (reslen>1)                                          //~va20R~
            {                                                      //~va20R~
//          	utfcvl2uany1mb(0,pc,reslen,&ucs);                  //~va20R~//~v6unR~
//          	utfcvl2uany1mb(0,pc,reslen,&ucs,NULL/*prc*/);      //~v6unI~//~vb2HR~
            	utfcvl2uany1mb(0,pc,reslen,&ucs4,NULL/*prc*/);     //~vb2HI~
                UCS4_TO_UTF16(ucs4,wkwucs,&utf16ctr);              //~vb2HI~
                ucs=wkwucs[0];                                     //~vb2HR~
        		chsz=2;                                            //~va20R~
            }                                                      //~va20R~
            else                                                   //~va20R~
            	ucs=' ';                                           //~va20R~
        }                                                          //~va20R~
        else                                                       //~va20R~
        {                                                          //~va20R~
            ucs=*pc;                                               //~va20R~
        	if (!ucs                                               //~va20R~
            ||  (reslen==Plen && UDBCSCHK_DBCS2NDLU(dbcsid))       //~va20R~
            ||  (reslen==1 && UDBCSCHK_DBCS1STLU(dbcsid))          //~va20R~
            )                                                      //~va20R~
        		ucs=' ';                                           //~va20R~
		}                                                          //~va20R~
        if (!swgetlen)                                             //~va20R~
            *pucs++=ucs;                                           //~va20R~
        if (utf16ctr>1)	//surrogate pair                           //~vb2HI~
        {                                                          //~vb2HI~
        	ucsctr++;                                              //~vb2HI~
	        if (!swgetlen)                                         //~vb2HI~
    	        *pucs++=wkwucs[1];                                 //~vb2HR~
        }                                                          //~vb2HI~
    }                                                              //~va20R~
    if (!swgetlen)                                                 //~va20R~
    {                                                              //~va20R~
    	*pucs++='\r';                                              //~va20R~
    	*pucs++='\n';                                              //~va20R~
    }                                                              //~va20R~
    ucsctr+=2;                                                     //~va20R~
    if (Pplenucs)                                                  //~va20R~
    	*Pplenucs=ucsctr*WUCSSZ;                                   //~va20R~
    if (!swgetlen)                                                 //~va20R~
    {                                                              //~va20R~
UTRACED("textcopypan outucs",Pout,ucsctr*2);;                      //~va20R~
	}                                                              //~va20R~
UTRACEP("return swucs=%d,ucsctr=%d\n",swucs,ucsctr);               //~va20R~
	return swucs;                                                  //~va20R~
}//wxe_dbcstextcopypan                                             //~va20R~
#endif                                                             //~va20R~
//*************************************************************    //~v65hI~
//*return current screen type                                      //~v65hI~
//*************************************************************    //~v65hI~
int  wxe_getpcw(void **Pppcw)                                      //~v65hI~
{                                                                  //~v65hI~
	PUCLIENTWE pcw;                                                //~v65hI~
    int rc;                                                        //~v65hI~
//***********************                                          //~v65hI~
    pcw=scrgetcw(0); 	//get active                               //~v65hI~
    if (Pppcw)	//optional                                         //~v65hI~
    	*Pppcw=pcw;                                                //~v65hI~
    switch(pcw->UCWtype)                                           //~v65hI~
	{                                                              //~v65hI~
	case UCWTDIR:                                                  //~v65hI~
    	rc=PRTTYPE_DIR;                                            //~v65hI~
        break;                                                     //~v65hI~
	case UCWTFILE:                                                 //~v65hI~
    	rc=PRTTYPE_FILE;                                           //~v65hI~
        break;                                                     //~v65hI~
    default:                                                       //~v65hI~
    	rc=PRTTYPE_HCOPY;//-1                                      //~v65hI~
	}                                                              //~v65hI~
	return rc;                                                     //~v65hI~
}//wxe_getpcw                                                      //~v65hI~
//*************************************************************    //~v76jI~
//*return current screen type                                      //~v76jI~
//*************************************************************    //~v76jI~
int  wxe_getpcwsubtype(void* Ppcw)                                 //~v76jR~
{                                                                  //~v76jI~
	PUCLIENTWE pcw;                                                //~v76jI~
	PUPANELC ppc;                                                  //~v76jI~
    int pid,rc;                                                    //~v76jI~
//***********************                                          //~v76jI~
    pcw=(PUCLIENTWE)Ppcw;                                          //~v76jR~
    ppc=(PUPANELC)(pcw->UCWppc);                                   //~v76jI~
	pid=ppc->UPCid;                                                //~v76jI~
	switch(pid)                                                    //~v76jI~
    {                                                              //~v76jI~
	case PANUCOMP  :		//compare                              //~v76jI~
		rc=WXECWST_UCOMP;                                          //~v76jI~
		break;                                                     //~v76jI~
	case PANUGREP  :		//grep                                 //~v76jI~
		rc=WXECWST_UGREP;                                          //~v76jI~
		break;                                                     //~v76jI~
    default:                                                       //~v76jI~
    	rc=0;                                                      //~v76jI~
    }                                                              //~v76jI~
	return rc;                                                     //~v76jI~
}//wxe_getpcwsubtype                                               //~v76jI~
//*************************************************************    //~2B02I~
//*get active screen file name                                     //~2B02I~
//*ret :'F'/'D'/-1/'H'(hex display)/'B'(binary file)               //~2B10R~
//*************************************************************    //~2B02I~
//int  wxe_prtgetfnm(char *Pfnm,void **Pppfh,int *Pplnotype)       //~v626R~
#ifdef W32UNICODE                                                  //~vavzR~
int  wxe_prtgetfnm(char *Pfnm,void **Pppcw,void **Pppfh,int *Pplnotype,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr)//~vavzI~
#else                                                              //~vavzI~
int  wxe_prtgetfnm(char *Pfnm,void **Pppcw,void **Pppfh,int *Pplnotype)//~v626I~
#endif                                                             //~vavzI~
{                                                                  //~2B02I~
	PUCLIENTWE pcw;                                                //~2B02I~
    PUFILEC pfc;                                                   //~2B02I~
    PUFILEH pfh;                                                   //~2B02I~
    int rc,pfhwidth,lnotype=0;                                     //~2C07R~
#ifdef W32UNICODE                                                  //~vavzR~
	int ucsctr,opt;                                                //~vavzR~
#endif                                                             //~vavzI~
//***********************                                          //~2B02I~
#ifdef W32UNICODE                                                  //~vavzR~
	*PfnmW=0;                                                      //~vavzI~
    if (Ppucsctr)                                                  //~vavzI~
    	*Ppucsctr=0;                                               //~vavzI~
#endif                                                             //~vavzI~
    pcw=scrgetcw(0); 	//get active                               //~2B02I~
    if (Pppcw)	//optional                                         //~v626I~
    	*Pppcw=pcw;			                                       //~v626R~
    switch(pcw->UCWtype)                                           //~2B02I~
	{                                                              //~2B02I~
	case UCWTDIR:                                                  //~2B02I~
    	rc=PRTTYPE_DIR;	                                           //~2C07R~
        break;                                                     //~2B02I~
	case UCWTFILE:                                                 //~2B02I~
    	rc=PRTTYPE_FILE;                                           //~2C07R~
        break;                                                     //~2B02I~
    default:                                                       //~2B02I~
    	pfhwidth=0;                                                //~2C01I~
    	rc=-1;                                                     //~2B02I~
	}    	                                                       //~2B02I~
    if (rc!=-1)                                                    //~2B02I~
    {                                                              //~2B02I~
    	pfc=pcw->UCWpfc;                                           //~2B02I~
    	pfh=pfc->UFCpfh;                                           //~2B02I~
#ifdef UTF8UCS2                                                    //~va20I~
    	((PWXEINTF)Gpwxei)->WXEIstatus&=~WXEIS_PRTVHEX;            //~va20I~
#endif                                                             //~va20I~
      if (pfh->UFHtype==UFHTWXPWK)                                 //~v54yI~
      {                                                            //~vavzI~
#ifdef W32UNICODE                                                  //~vavzI~
        wxe_getorgfnm(Pfnm,PfnmW);                                 //~vavzI~
#else                                                              //~vavzI~
        wxe_getorgfnm(Pfnm);                                       //~v54yI~
#endif                                                             //~vavzI~
      }                                                            //~vavzI~
      else                                                         //~v54yI~
      {                                                            //~vavzI~
#ifdef UTF8UCS2                                                    //~va20I~
       if (pfh->UFHfilenamebylc)                                   //~va20I~
        strcpy(Pfnm,pfh->UFHfilenamebylc);                         //~va20R~
       else                                                        //~va20I~
#endif                                                             //~va20I~
        strcpy(Pfnm,pfh->UFHfilename);                             //~2B02I~
#ifdef W32UNICODE                                                  //~vavzR~
         if (pfh->UFHfilenameddlen)                                //~vavzI~
         {                                                         //~vavzI~
			opt=UTFDD2UO_ERRREP;                                   //~vavzI~
       	 	utfdd2u(opt,pfh->UFHfilenamedddata,pfh->UFHfilenamedddbcs,pfh->UFHfilenameddlen,PfnmW,Pbuffsz-UWCHSZ,&ucsctr,NULL/*sbcsctr*/,NULL/*dbcsctr}*/);//~vavzI~
            *(PfnmW+ucsctr)=0;                                     //~vavzR~
            if (Ppucsctr)                                          //~vavzI~
            	*Ppucsctr=ucsctr;                                  //~vavzI~
         }                                                         //~vavzI~
#endif                                                             //~vavzI~
      }//!UFHTWXPWK                                                //~vavzI~
        *Pppfh=pfh;                                                //~2B02I~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~2B10R~
        {                                                          //~va49I~
	      if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))    //VHEX         //~va49I~
        	rc=PRTTYPE_VHEXHHEX;    //vhex and hhex                //~va49I~
          else                                                     //~va49I~
        	rc=PRTTYPE_HEX;    //hex diplay mode                   //~2C07R~
        }                                                          //~va49I~
        else                                                       //~2C01M~
        if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~2C01M~
        {                                                          //~v626I~
	        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                 //~v626I~
    	    	rc=PRTTYPE_VHEXBIN;    //3 line hex diplay mode    //~v626I~
            else                                                   //~v626I~
	            rc=PRTTYPE_BIN;     //bin file                     //~2C07R~
        }                                                          //~v626I~
        else                                                       //~v626I~
        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                     //~v626M~
        {                                                          //~va20I~
        	rc=PRTTYPE_VHEXTEXT;    //3 line hex diplay mode       //~v626I~
#ifdef UTF8UCS2                                                    //~va20I~
    		((PWXEINTF)Gpwxei)->WXEIstatus|=WXEIS_PRTVHEX;	//vhex print//~va20I~
#endif                                                             //~va20I~
        }                                                          //~va20I~
        if (UCBITCHK(pfh->UFHflag4,UFHF4BIN)                       //~2C07I~
		&&  UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                  //~2C07R~
        	if (UCBITCHK(Goptopt,GOPT_HEX_UPPER))                  //~2C07I~
        		lnotype=PRTLNOTYPE_HEX;                            //~2C07I~
        	else                                                   //~2C07I~
        		lnotype=PRTLNOTYPE_hex;                            //~2C07I~
    	else                                                       //~2C07I~
        	lnotype=PRTLNOTYPE_DEC;                                //~2C07I~
    }                                                              //~2B02I~
    *Pplnotype=lnotype;                                            //~2C07I~
	return rc;                                                     //~2B02I~
}//wxe_prtgetfnm                                                   //~2B02I~
//*************************************************************    //~2B02I~
//*init pfh print                                                  //~2B02I~
//*ret :line count                                                 //~2B02I~
//*************************************************************    //~2B02I~
//int wxe_prtinit(void *Ppfh,int *Ppmaxlen,int *Pplinenosz,int *Pppfhwidth)//~v626R~
int wxe_prtinit(void *Ppcw,void *Ppfh,int *Ppmaxlen,int *Pplinenosz,int *Pppfhwidth)//~v626I~
{                                                                  //~2B02I~
    int maxlen=0,len,filesz=0,linenosz,totline;                    //~2C07R~
    PUFILEH pfh;                                                   //~2B02I~
    PULINEH plh;                                                   //~2B02I~
    char linenowk[16];                                             //~2B30M~
//***********************                                          //~2B02I~
	Sprtpcw=Ppcw;                                                  //~v626I~
	pfh=(PUFILEH)Ppfh;                                             //~2B02I~
#ifdef UTF8UCS2                                                    //~va20I~
    if (FILEUTF8MODE(pfh))                                         //~va20R~
    	((PWXEINTF)Gpwxei)->WXEIstatus|=WXEIS_PRTUTF8;	//prt file is utf8 file(dd fmt)//~va20R~
    else                                                           //~va20I~
    	((PWXEINTF)Gpwxei)->WXEIstatus&=~WXEIS_PRTUTF8;            //~va20R~
#endif                                                             //~va20I~
    ((PWXEINTF)Gpwxei)->WXEIstatus&=~(WXEIS_PRTEBC|WXEIS_PRTEBCBYUCS);//~va80I~
    if (PFH_ISEBC(pfh))                                            //~va80I~
    {                                                              //~va80I~
    	((PWXEINTF)Gpwxei)->WXEIstatus|=WXEIS_PRTEBC;	//prt file is utf8 file(dd fmt)//~va80I~
//      if (pfh->UFHtype!=UFHTWXPWK)                               //~va80I~//~va81R~
	    	((PWXEINTF)Gpwxei)->WXEIstatus|=WXEIS_PRTEBCBYUCS;	//prt file is utf8 file(dd fmt)//~va80I~
    }                                                              //~va80I~
	Sprtplh=UGETQTOP(&pfh->UFHlineque);	//top of file hdr line     //~2B02R~
    Sprtpageno=0;                                                  //~2B02I~
    Sprtreslen=0;                                                  //~2B02I~
	Swkvhexlineid=0;        //top data lineid                      //~va87I~
	Swkvhexoffs=0;        //top data lineid                        //~va87I~
	Swkvhexoffsvhex=0;        //top data lineid                    //~va8dI~
//  Sdbcssplitsw=0;                                                //~v61zR~
    for (plh=Sprtplh;plh;plh=UGETQNEXT(plh))                       //~2B16R~
    {                                                              //~2B16R~
        if (plh->ULHtype!=ULHTDATA)                                //~2B16R~
            continue;                                              //~2B16R~
	    if (pfh->UFHtype==UFHTDIR)                                 //~2C07R~
    		len=WDIRLDSZ+wxe_getddexpand(plh);                     //~2B16M~
    	else                                                       //~2B16M~
        {                                                          //~2B16I~
            if (!plh->ULHdbcs)  //not once displayed               //~2B16R~
            {                                                      //~2B16R~
                if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~2B16R~
                    return uerrmsgbox("Storage Shortage",0);       //~2B16R~
            }                                                      //~2B16R~
        	len=plh->ULHlen;                                       //~2B16R~
            filesz+=len;                                           //~2B30I~
        }                                                          //~2B16I~
        if (maxlen<len)                                            //~2B16R~
            maxlen=len;                                            //~2B16R~
    }                                                              //~2B16R~
    Sdirmaxexplen=maxlen-WDIRLDSZ;                                 //~2C07I~
    *Ppmaxlen=maxlen;                                              //~2B02I~
    totline=UGETQCTR(&pfh->UFHlineque)-2;                          //~2B30I~
	if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                      //~2C07I~
    {                                                              //~2C07I~
    	linenosz=sprintf(linenowk,"%x",filesz);	//1 for intermediate space//~2B30I~
        linenosz=(linenosz+1)/2*2;                                 //~2B30I~
    }                                                              //~2C07I~
    else                                                           //~2C07R~
    {                                                              //~2C07I~
    	linenosz=sprintf(linenowk,"%d",totline);	//1 for intermediate space//~2B30M~
    }                                                              //~2C07I~
    *Pplinenosz=linenosz;                                          //~2B30I~
    *Pppfhwidth=pfh->UFHwidth;                                     //~2C01R~
    return totline;                                                //~2B30R~
}//wxe_prtinit                                                     //~2B02I~
//*************************************************************    //~2B02I~
//*count prt page                                                  //~2B02I~
//cmaxcol:1 print line record length ajusted by print line width   //~2C07I~
//*ret :page count                                                 //~2B02I~
//*************************************************************    //~2B02I~
//int wxe_prtgetmaxpage(void *Ppfh,int *Ppcmaxlrecl,int *Ppmaxcol, //~v626R~
int wxe_prtgetmaxpage(void *Ppcw,void *Ppfh,int *Ppcmaxlrecl,int *Ppmaxcol,//~v626I~
						int *Ppdatacol,int Pmaxline,int *Pptotrow) //~v51hI~
{                                                                  //~2B02I~
    PUFILEH pfh;                                                   //~2C01M~
    PUCLIENTWE pcw;                                                //~v626I~
    PUFILEC pfc;                                                   //~v626I~
    PULINEH plh;                                                   //~2C01M~
    int cmaxlrecl,lrecl,lreclo,maxcol,prtreslen;                   //~v76jR~
    int totline,len/*,dbcssplitsw=0*/;                             //~v61zR~
//***********************                                          //~2B02I~
	pcw=(PUCLIENTWE)Ppcw;                                          //~v626I~
	pfc=pcw->UCWpfc;                                               //~v626I~
	pfh=(PUFILEH)Ppfh;                                             //~2C07I~
    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                          //~2C07R~
    {                                                              //~2C01I~
	    cmaxlrecl=*Ppcmaxlrecl;                                    //~2C08I~
//      maxcol=*Ppmaxcol;                                          //~v51hR~
        maxcol=*Ppdatacol;                                         //~v51hI~
        maxcol-=HEXINTERMARGIN;                                    //~2C01R~
        if (maxcol>3)                                              //~2C07I~
        {                                                          //~2C07I~
            for (lreclo=0,lrecl=0,len=0;len<=maxcol;)              //~2C07R~
            {                                                      //~2C07R~
                lreclo=lrecl;                                      //~2C07R~
                if (lrecl && !(lrecl%4))    //boundary             //~2C07R~
                    len++;                                         //~2C07R~
                len+=3;                                            //~2C07R~
                lrecl++;                                           //~2C07R~
            }                                                      //~2C07R~
            cmaxlrecl=lreclo;                                      //~2C07R~
        }                                                          //~2C07I~
	    *Ppcmaxlrecl=cmaxlrecl;                                    //~2C07R~
//      *Ppmaxcol=GET_HEXDISPLAYLINESZ(cmaxlrecl);                 //~v51hR~
        *Ppdatacol=GET_HEXDISPLAYLINESZ(cmaxlrecl);                //~v51hI~
    }                                                              //~2C01I~
    else                                                           //~2C07I~
//      *Ppcmaxlrecl=cmaxlrecl=*Ppmaxcol;                          //~v51hR~
        *Ppcmaxlrecl=cmaxlrecl=*Ppdatacol;                         //~v51hI~
	for (plh=UGETQTOP(&pfh->UFHlineque),totline=0;plh;plh=UGETQNEXT(plh))//~2C08R~
    {                                                              //~2B02I~
    	if (plh->ULHtype!=ULHTDATA)                                //~2B02I~
        	continue;                                              //~2B02I~
	    if (pfh->UFHtype==UFHTDIR)                                 //~2C07I~
        {                                                          //~2C08I~
    		len=WDIRLDSZ+Sdirmaxexplen;                            //~2C07R~
//          dbcssplitsw=(cmaxlrecl<(int)offsetof(WDIRLD,WDDattr[0])+Sdirmaxexplen);//~v61zR~
            totline+=(len+cmaxlrecl-1)/cmaxlrecl;                  //~2C08I~
        }                                                          //~2C08I~
        else                                                       //~2B16I~
        {                                                          //~2C08I~
        	len=plh->ULHlen;                                       //~2B16I~
          if (len)                                                 //~v51fI~
//          for (prtreslen=len;prtreslen;)                         //~v51fR~
            for (prtreslen=len;prtreslen>0;)                       //~v51fI~
            {                                                      //~2C08R~
//              dbcssplitsw+=wxe_prtgetdatalen(pfh,plh,prtreslen,cmaxlrecl,&len,0);//~v61zR~
                wxe_prtgetdatalen(pfh,plh,prtreslen,cmaxlrecl,&len,0);//~v61zI~
                prtreslen-=len;                                    //~2C08R~
                totline++;                                         //~2C08R~
            }                                                      //~2C08R~
          else                                                     //~v51fI~
                totline++;                                         //~v51fI~
        }//not DIR                                                 //~2C08I~
    }                                                              //~2B02I~
    if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))//3 line mode hex print  //~v626I~
    	totline*=3;                                                //~v626I~
    *Pptotrow=totline;                                             //~2B09I~
//    if (dbcssplitsw)                                             //~v61zR~
//    {                                                            //~v61zR~
////      *Ppmaxcol=*Ppmaxcol+1;                                   //~v61zR~
//        *Ppdatacol=*Ppdatacol+1;                                 //~v61zR~
//        if (*Ppmaxcol<*Ppdatacol)   //dbcs overflow line         //~v61zR~
//            *Ppmaxcol=*Ppmaxcol+1;                               //~v61zR~
//                                                                 //~v61zR~
//    }                                                            //~v61zR~
    return (totline+Pmaxline-1)/Pmaxline;                          //~2B02I~
}//wxe_prtgetmaxpage                                               //~2B02I~
#ifdef AAA                                                         //~va50I~
//*************************************************************    //~va50I~
//*b2m for wxp cmd                                                 //~va50I~
//*************************************************************    //~va50I~
int wxexei_wxpb2m(int Popt,UCHAR *Poutdata,PULINEH Pplh,int Poffs,int Plen)//~va50R~
{                                                                  //~va50I~
	int opt=0,rc,outlen,repch='.';                                 //~0428R~//~va50I~
    UCHAR *pdata0,*pdbcs0,*pc,*pcd;                                //~va50I~
//*****************                                                //~0428I~//~va50I~
	pdata0=Pplh->ULHdata;                                          //~va50I~
	pdbcs0=Pplh->ULHdbcs;                                          //~va50I~
    pc=pdata0+Poffs;                                               //~va50I~
    pcd=pdbcs0+Poffs;                                              //~va50I~
	UTRACED("wxpb2m inp",pc,Plen);                              //~0428I~//~va50I~
    if (Popt & WXEXEIWXPB2MO_SCRPRT)                               //~va50R~
    	opt|=UCVEBC3O_SOSIREPQ;                                    //~va50I~
    else                                                           //~va50I~
    	opt|=UCVEBC3O_SOSI2SPACE;                                  //~va50I~
	rc=ucvebc3_b2m(opt,pc,pcd,Plen,Poutdata,Plen,repch,&outlen);//~0428R~//~va50I~
	UTRACED("wxpb2m out",Poutdata,Plen);                              //~0428I~//~va50I~
    return rc;                                                     //~0428I~//~va50I~
}//wxexei_wxpb2m                                                   //~va50I~
#endif                                                             //~va50I~
//*************************************************************    //~2B02I~
//*get  plh data                                                   //~2B02I~
//*parm:pageno; pageno,start from 1.                               //~2B16R~
//*     ppdata; input for dir print,output for file print          //~2B16I~
//*     ppdbcs; for utf8/ebc file only                                 //~va49I~//~va80R~
//*ret :contsw;1:not first line;  -1 for eof                       //~2C08R~
//*************************************************************    //~2B02I~
int wxe_prtgetline(int Ppageno,int Pmaxlrecl,int Pmaxline,char *Ppdata,//~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
					char *Ppdbcs,int *Ppucslen,                    //~va20I~
#endif                                                             //~va20I~
					int *Pplen,int *Ppskiplineno,int *Ppprtlen)    //~2C01R~
{                                                                  //~2B02I~
    PULINEH plh;                                                   //~2B02I~
    PUFILEH pfh;                                                   //~2B16I~
    PUFILEC pfc;                                                   //~v626I~
    int pageno,len,ii,contsw,skiplineno=0,skiplen=0,/*dbcssplitsw,*/dirlrecl;//~v61zR~
    int datalinenoszlen=0;                                         //~v626I~
    int vhexmode;                                                  //~v626I~
    char *pdata,*pdbcs,*phexd,*phexw=0;                            //~v76jR~
    char *plhdata,*plhdbcs;                                        //~v626R~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file,vhlen=0;                                        //~vafaR~
#endif                                                             //~va20I~
    int opttd;                                                     //~va46I~
    int offsvhex;                                                  //~va49I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
	int optwxpb2m=0;                                               //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int handle;                                                    //~va80I~
    int swwkvhex,rc2;                                              //~va87R~
    int wkcontaddlen=0;                                            //~va89I~
//***********************                                          //~2B02I~
    opttd=FILETDO_BINSWMASK|FILETDO_PRINTGUI;                      //~va46R~
	pfc=Sprtpcw->UCWpfc;                                           //~v626I~
    vhexmode=UCBITCHK(pfc->UFCflag2,UFCF2VHEX);//3 line mode hex print//~v626I~
	dirlrecl=WDIRLDSZ+Sdirmaxexplen;                               //~2C08I~
    pdata=Ppdata;                                                  //~2C08M~
    pdbcs=Ppdata+dirlrecl;  //for dir only                         //~2C08I~
	plh=Sprtplh;                                                   //~2B02I~
    pfh=UGETPFH(plh);                                              //~2B16I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
	swwkvhex=UCBITCHK(pfh->UFHflag11,UFHF11WXPPRTSCRVHEX);         //~va87R~
    handle=pfh->UFHhandle;                                         //~va80I~
    if (swebcfile && (((PWXEINTF)Gpwxei)->WXEIstatus & WXEIS_PRTEBCBYUCS))//~va80I~
		optwxpb2m|=TDXPO_EBCBYUCS;                                 //~va80I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	pageno=Ppageno-Sprtpageno-1;                                   //~2B16R~
	for (;pageno>0;pageno--)                                       //~2B04R~
    {                                                              //~2B02I~
    	for (ii=Pmaxline;ii>0;ii--)                                //~2B02R~
        {                                                          //~2B02I~
          if (swwkvhex)                                            //~va87I~
          {                                                        //~va87I~
//      	if ((plh=wxe_prtgetnextplhwkvhex(0,&plh,&rc2)))        //~va87R~//~va8eR~
          	if (!(plh=wxe_prtgetnextplhwkvhex(0,&rc2)))            //~va8eI~
            	return -1;                             //eof       //~va87I~
            if (!rc2)	//top of line(data/vhex)                   //~va87I~
                skiplineno++;                                      //~va87I~
            wxe_prtgetdatalenwkvhex(0,pfh,plh,Pmaxlrecl,&len);     //~va87R~
            skiplen+=len;                                          //~va87I~
          }                                                        //~va87I~
          else                                                     //~va87I~
          {                                                        //~va87I~
//      	if (!Sprtreslen && !Sdbcssplitsw)                      //~v61zR~
        	if (!Sprtreslen)                                       //~v61zI~
            {                                                      //~2B02I~
        		if (!(plh=wxe_prtgetnextplh()))                    //~2B02R~
            		return -1;                                     //~2B02I~
			    if (pfh->UFHtype==UFHTDIR)                         //~2C07I~
    				Sprtreslen=dirlrecl;                           //~2C08R~
        		else                                               //~2B16I~
                	Sprtreslen=plh->ULHlen;                        //~2B16R~
                skiplineno++;                                      //~2B04I~
            }                                                      //~2B02I~
//          Sdbcssplitsw=wxe_prtgetdatalen(pfh,plh,Sprtreslen,Pmaxlrecl,&len,0);//~v61zR~
            wxe_prtgetdatalen(pfh,plh,Sprtreslen,Pmaxlrecl,&len,0);//~v61zI~
            skiplen+=len;                                          //~2B30I~
            Sprtreslen-=len;                                       //~2B02R~
            if (vhexmode)                                          //~v626I~
            	ii-=2;	//3 line mode                              //~v626I~
          }                                                        //~va87I~
        }                                                          //~2B02I~
    }                                                              //~2B02I~
//  if (!Sprtreslen && !Sdbcssplitsw)                              //~v61zR~
  if (swwkvhex)                                                    //~va87I~
  {                                                                //~va87I~
//  if (!(plh=wxe_prtgetnextplhwkvhex(0,&plh,&rc2)))               //~va87I~//~va8eR~
    if (!(plh=wxe_prtgetnextplhwkvhex(0,&rc2)))                    //~va8eI~
    	return -1;                             //eof               //~va87I~
    wxe_prtgetdatalenwkvhex(0,pfh,plh,Pmaxlrecl,&len);             //~va87I~
    contsw=(rc2==1);                                               //~va87R~
	Sprtpageno=Ppageno;                                            //~va87I~
  }                                                                //~va87I~
  else                                                             //~va87I~
  {                                                                //~va87I~
    if (!Sprtreslen)                                               //~v61zI~
    {                                                              //~2B02I~
        if (!(plh=wxe_prtgetnextplh()))                            //~2B02R~
            return -1;                                             //~2B02I~
        if (pfh->UFHtype==UFHTDIR)                                 //~2C07I~
        {                                                          //~2C08I~
    		Sprtreslen=dirlrecl;                                   //~2C08R~
	        wxe_ddsetup(pfh,plh,pdata);                            //~2C08I~
        }                                                          //~2C08I~
        else                                                       //~2B16I~
        	Sprtreslen=plh->ULHlen;                                //~2B16R~
        contsw=0;                                                  //~2B04I~
    }                                                              //~2B02I~
    else	//2nd line                                             //~2C08R~
    	contsw=1;                                                  //~2B04I~
	Sprtpageno=Ppageno;                                            //~2B04I~
//  dbcssplitsw=wxe_prtgetdatalen(pfh,plh,Sprtreslen,Pmaxlrecl-Sdbcssplitsw,&len,pdata+dirlrecl);//~v61zR~
    wxe_prtgetdatalen(pfh,plh,Sprtreslen,Pmaxlrecl,&len,pdata+dirlrecl);//~v61zR~
  }                                                                //~va87I~
    if (pfh->UFHtype==UFHTDIR)                                     //~2C07I~
    {                                                              //~2C07I~
    	if (contsw)                                                //~2C08I~
        {                                                          //~2C08I~
//  		if (Sdbcssplitsw)                                      //~v61zR~
//      		*pdata=' ';                                        //~v61zR~
//      	memcpy(pdata+Sdbcssplitsw,pdata+dirlrecl-Sprtreslen,len);	//shift setup data//~v61zR~
        	memcpy(pdata,pdata+dirlrecl-Sprtreslen,len);	//shift setup data//~v61zI~
        }                                                          //~2C08I~
    }                                                              //~2C07I~
    else                                                           //~v626I~
    if (vhexmode)                                                  //~v626I~
    {                                                              //~v626I~
      if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                        //~va49R~
      {                                                            //~va49R~
        if (len<Pmaxlrecl)                                         //~va49R~
            memset(pdata+len,' ',Pmaxlrecl-len);                   //~va49R~
        phexd=pdata+Pmaxlrecl;                                     //~va49R~
        phexw=phexd+HEXINTERMARGIN+GET_HEXPARTLEN(len);            //~va49R~
        pdbcs=phexw+len+len;                                       //~va49R~
//      offsvhex=(ULONG)pdbcs-(ULONG)pdata+len;                    //~va49I~//~vafkR~
//      offsvhex=(ULPTR)pdbcs-(ULPTR)pdata+len;                    //~vafkI~//~vb2WR~
        offsvhex=(int)((ULPTR)pdbcs-(ULPTR)pdata)+len;             //~vb2WI~
    	plhdata=plh->ULHdata+plh->ULHlen-Sprtreslen;               //~va49I~
    	plhdbcs=plh->ULHdbcs+plh->ULHlen-Sprtreslen;               //~va49I~
        memcpy(pdata,plhdata,len);                                 //~va49R~
        memcpy(pdbcs,plhdbcs,len);                                 //~va49R~
        wxe_hexdisplay(UCBITCHK(Goptopt,GOPT_HEX_UPPER)!=0,        //~va49R~
                        pdata,pdbcs,len,phexd,phexw);   //edit to hexdigit//~va49R~
        vhlen=Pmaxlrecl;    //buffsize for vhex output             //~va49I~
        filevhexdisplay(USDF2VHEXLINE1,plhdata,plhdbcs,phexw,0,len,&vhlen);//~va49R~
        filevhexdisplay(USDF2VHEXLINE2,plhdata,plhdbcs,phexw+vhlen,0,len,&vhlen);//~va49R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (swebcfile && !UCBITCHK(pfh->UFHflag4,UFHF4BIN))        //~va50I~
        {                                                          //~va50I~
        	optwxpb2m|=TDXPO_TEXT;                                 //~va50R~
	    	if (pfh->UFHtype!=UFHTWXPWK)	//wxp **/***           //~va50I~
				optwxpb2m|=TDXPO_TEXTFILE;  //SO/SI to space       //~va50I~
            else                                                   //~va81I~
				optwxpb2m|=TDXPO_WXPWK;                            //~va81I~
        }                                                          //~va50I~
	    if (optwxpb2m & TDXPO_EBCBYUCS)                            //~va80I~
      	{                                                          //~va80I~
        	pdbcs=Ppdbcs;                                          //~va80R~
      		memcpy(pdbcs,plhdbcs,len);                             //~va80I~
      	}                                                          //~va80I~
        tabdisplayforxpr(optwxpb2m,plh,pdata,pdbcs,len);//rep ctl-char to "."//~va50R~
#else                                                              //~va50I~
        tabdisplayforxpr(pdata,pdbcs,len);//rep ctl-char to "."    //~va49I~
#endif                                                             //~va50I~
UTRACED("wxe_prtgetline vhexhhex wk out",pdata,offsvhex+vhlen);    //~va49I~
      }//vhex+hhex                                                 //~va49R~
      else                                                         //~va49I~
      {                                                            //~va49I~
    	plhdata=plh->ULHdata+plh->ULHlen-Sprtreslen;               //~v626R~
    	plhdbcs=plh->ULHdbcs+plh->ULHlen-Sprtreslen;               //~v626R~
        memcpy(pdata,plhdata,len);                                 //~v626I~
UTRACED("wxe_prtgetline tabdisplay inp data",plhdata,len);         //~va20I~
UTRACED("wxe_prtgetline tabdisplay inp dbcs",plhdbcs,len);         //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
      if (swutf8file)                                              //~va20I~
      {                                                            //~va20I~
        memcpy(Ppdbcs,plhdbcs,len);                                //~va20I~
        tabdisplayforxpru8(0,pdata,Ppdbcs,len);//evaluate dd fmt   //~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
      {                                                            //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (swebcfile && !UCBITCHK(pfh->UFHflag4,UFHF4BIN))        //~va50I~
        {                                                          //~va50I~
        	optwxpb2m|=TDXPO_TEXT;                                 //~va50I~
	    	if (pfh->UFHtype!=UFHTWXPWK)	//wxp **/***           //~va50I~
				optwxpb2m|=TDXPO_TEXTFILE;  //SO/SI to space       //~va50I~
            else                                                   //~va81I~
				optwxpb2m|=TDXPO_WXPWK;  //SO/SI to space          //~va81I~
        }                                                          //~va50I~
	  if (optwxpb2m & TDXPO_EBCBYUCS)                              //~va80R~
        tabdisplayforxprebcbyucs(optwxpb2m|TDXPO_EBCSPLITCHK,handle,plh,pdata,Ppdbcs,plh->ULHlen-Sprtreslen/*offs*/,len);//rep ctl-char to "."//~va80R~
      else                                                         //~va80I~
        tabdisplayforxpr(optwxpb2m,plh,pdata,plhdbcs,len);//rep ctl-char to "."//~va50R~
#else                                                              //~va50I~
        tabdisplayforxpr(pdata,plhdbcs,len);//rep ctl-char to "."  //~v626I~
#endif                                                             //~va50I~
      }                                                            //~va50I~
UTRACED("wxe_prtgetline tabdisplay out",pdata,len);                //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
        vhlen=Pmaxlrecl;    //buffsize for vhex output             //~va20I~
        filevhexdisplay(USDF2VHEXLINE1,plhdata,plhdbcs,pdata+len,0,len,&vhlen);//~va20I~
        filevhexdisplay(USDF2VHEXLINE2,plhdata,plhdbcs,pdata+len+vhlen,0,len,&vhlen);//~va20R~
#else                                                              //~va20I~
        filevhexdisplay(USDF2VHEXLINE1,plhdata,plhdbcs,pdata+len,0,len);//~v626I~
        filevhexdisplay(USDF2VHEXLINE2,plhdata,plhdbcs,pdata+len+len,0,len);//~v626I~
#endif                                                             //~va20I~
      }//simple vhex                                               //~va49I~
	    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v626I~
	        skiplineno=skiplen;                                    //~v626I~
    }                                                              //~v626I~
    else                                                           //~2C07I~
    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                          //~2C07I~
    {                                                              //~2C07I~
        if (len<Pmaxlrecl)                                         //~2C07M~
        	memset(pdata+len,' ',Pmaxlrecl-len);                   //~2C07M~
	    phexd=pdata+Pmaxlrecl;                                     //~2C07M~
	    phexw=phexd+HEXINTERMARGIN+GET_HEXPARTLEN(len);            //~2C07M~
	    pdbcs=phexw+len+len;                                       //~2C07M~
	    memcpy(pdata,plh->ULHdata+plh->ULHlen-Sprtreslen,len);     //~2C07M~
	    memcpy(pdbcs,plh->ULHdbcs+plh->ULHlen-Sprtreslen,len);     //~2C07M~
        wxe_hexdisplay(UCBITCHK(Goptopt,GOPT_HEX_UPPER)!=0,        //~2C07R~
						pdata,pdbcs,len,phexd,phexw); 	//edit to hexdigit//~2C07I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    if (optwxpb2m & TDXPO_EBCBYUCS)                            //~va80I~
      	{                                                          //~va80I~
        	pdbcs=Ppdbcs;                                          //~va80R~
      		memcpy(pdbcs,plh->ULHdata+plh->ULHlen-Sprtreslen,len); //~va80I~
      	}                                                          //~va80I~
      if (swebcfile)                                               //~va50I~
        tabdisplayforxpr(optwxpb2m,plh,pdata,pdbcs,len);//cv b2l   //~va50I~
      else                                                         //~va50I~
        tabdisplay(plh,pdata,pdbcs,len,opttd);	//1:binsw          //~va46R~
#else                                                              //~va50I~
        tabdisplay(pdata,pdbcs,len,opttd);	//1:binsw              //~va46R~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
        skiplineno=skiplen;                                        //~2C07M~
        UTRACED("prtgetline HHEX data",pdata,len);                 //~va49I~
        UTRACED("prtgetline HHEX hexdata",phexd,Pmaxlrecl);        //~va49I~
    }                                                              //~2C07I~
    else                                                           //~2C07I~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~2C07I~
    {                                                              //~2C07I~
	    pdbcs=pdata+len;                                           //~2C07M~
	    memcpy(pdata,plh->ULHdata+plh->ULHlen-Sprtreslen,len);     //~2C07M~
	    memcpy(pdbcs,plh->ULHdbcs+plh->ULHlen-Sprtreslen,len);     //~2C07M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (swebcfile)                                               //~va50I~
        tabdisplayforxpr(optwxpb2m,plh,pdata,pdbcs,len);//cv b2l   //~va50I~
      else                                                         //~va50I~
        tabdisplay(plh,pdata,pdbcs,len,opttd);	//1:binsw          //~va46R~
#else                                                              //~va50I~
        tabdisplay(pdata,pdbcs,len,opttd);	//1:binsw              //~va46R~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
        skiplineno=skiplen;                                        //~2C07M~
    }                                                              //~2C07I~
    else    //text file                                            //~2C08R~
    {                                                              //~2C08I~
//  	if (Sdbcssplitsw)                                          //~v61zR~
//      	*pdata++=' ';                                          //~v61zR~
//  	optwxpb2m=TDXPO_TEXT;                                      //~va50R~//~va80R~
    	optwxpb2m|=TDXPO_TEXT;                                     //~va80I~
        pdbcs=Ppdbcs;                                              //~va81I~
	    if (pfh->UFHtype==UFHTWXPWK)	//wxp **/***               //~v626I~
        {                                                          //~v626I~
            if (contsw && Swxpdatalinenosz)   //contline           //~v626R~
            {                                                      //~v626I~
    			wkcontaddlen=Swxpdatalinenosz;	//lrecl(dbcstbsz) was expanded//~va89I~
//* wxp "**"/"***" translate b2m at tabdisplayforxpr               //~va50I~
                memset(pdata,' ',Swxpdatalinenosz-1);              //~v626R~
                *(pdata+Swxpdatalinenosz-1)=CONTLINEDELM;          //~v626R~
                pdata+=Swxpdatalinenosz;                           //~v626I~
                datalinenoszlen=Swxpdatalinenosz;                  //~v626R~
//              if (optwxpb2m & TDXPO_EBCBYUCS)                    //~va81I~//~va85R~
                if (Ppdbcs)                                        //~va87I~
                {                                                  //~va81I~//~va85R~//~va87R~
                	memset(pdbcs,0,Swxpdatalinenosz);              //~va81I~
                	pdbcs+=Swxpdatalinenosz;                       //~va81I~
                }                                                  //~va81I~//~va85R~//~va87R~
            }                                                      //~v626I~
			optwxpb2m|=TDXPO_WXPWK;                                //~va81I~
        }                                                          //~v626I~
        else                                                       //~va50I~
			optwxpb2m|=TDXPO_TEXTFILE;                             //~va50R~
        if (len)                                                   //~2C08I~
        {                                                          //~va20I~
		    memcpy(pdata,plh->ULHdata+plh->ULHlen-Sprtreslen,len); //~2C08R~
          	if (swebcfile                                          //~va50I~
  	      	&&  plh->ULHtype==ULHTDATA	//file data                //~va50I~
          	)                                                      //~va50I~
            {                                                      //~va80I~
#ifdef AAA                                                         //~va50I~
		    	wxexei_wxpb2m(optwxpb2m,pdata,plh,plh->ULHlen-Sprtreslen,len);//~va50I~
#else                                                              //~va50I~
	          if (optwxpb2m & TDXPO_EBCBYUCS)                      //~va80I~
	        	tabdisplayforxprebcbyucs(optwxpb2m|TDXPO_EBCSPLITCHK,handle,plh,pdata,pdbcs,plh->ULHlen-Sprtreslen,len);//~va80R~//~va81R~
              else                                                 //~va80I~
	        	tabdisplayforxpr(optwxpb2m,plh,pdata,plh->ULHdbcs+plh->ULHlen-Sprtreslen,len);//rep ctl-char to "."//~va50R~
#endif                                                             //~va50I~
            }                                                      //~va80I~
#ifdef UTF8UCS2                                                    //~va20I~
      		if (swutf8file)                                        //~va20I~
      		{                                                      //~va20I~
//  		    memcpy(Ppdbcs,plh->ULHdbcs+plh->ULHlen-Sprtreslen,len);//~va20I~//~va85R~
    		    memcpy(pdbcs,plh->ULHdbcs+plh->ULHlen-Sprtreslen,len);//~va85I~
     		}                                                      //~va20I~
#endif                                                             //~va20I~
        }                                                          //~va20I~
    }                                                              //~2C08I~
    Sprtreslen-=len;                                               //~2B02R~
//  *Pplen=len;                                                    //~2C01I~//~va89R~
    *Pplen=len+wkcontaddlen;                                       //~va89I~
    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                          //~2C07I~
//  	*Ppprtlen=(int)((ULONG)phexw-(ULONG)pdata);                //~2C01R~//~vafkR~
    	*Ppprtlen=(int)((ULPTR)phexw-(ULPTR)pdata);                //~vafkI~
    else                                                           //~2C01I~
//      *Ppprtlen=len+Sdbcssplitsw;                                //~v61zR~
//      *Ppprtlen=len;                                             //~v626R~
        *Ppprtlen=len+datalinenoszlen;                             //~v626I~
    *Ppskiplineno=skiplineno;                                      //~2B04I~
#ifdef UTF8UCS2                                                    //~va20I~
	if (Ppucslen)                                                  //~va20I~
    	*Ppucslen=vhlen;                                           //~va20I~
#endif                                                             //~va20I~
//  Sdbcssplitsw=dbcssplitsw;	//for next read                    //~v61zR~
    return contsw;                                                 //~2B04R~
}//wxe_prtgetline                                                  //~2B02I~
//**************************************************************** //~2B30I~
// copyed filehexdisplay                                           //~2B30I~
//**************************************************************** //~2B30I~
int wxe_hexdisplay(int Puppersw,char *Pdata,char *Pdbcs,int Plen,char *Phexd,char *Phexw)//~2B30I~
{                                                                  //~2B30I~
	UCHAR *pdbcs,*phexd,*tabpos,*phexw;                            //~2B30R~
    UINT  ulopt;                                                   //~2B30I~
    int   rlen,len;                                                //~2B30R~
//*****************                                                //~2B30I~
    pdbcs=Pdbcs;                                                   //~2B30I~
	phexd=Phexd;                                                   //~2B30I~
    memset(phexd,' ',HEXINTERMARGIN);                              //~2B30I~
    phexd+=HEXINTERMARGIN;                                         //~2B30I~
//restore tabchar                                                  //~2B30I~
    for (rlen=Plen;rlen;)                                          //~2B30I~
    {                                                              //~2B30I~
//*no TABCHAR on dbcstbl for ebcdic file                           //~va50I~
    	tabpos=memchr(pdbcs,TABCHAR,(UINT)rlen);                   //~2B30I~
        if (!tabpos)                                               //~2B30I~
        	break;                                                 //~2B30I~
//      rlen=(int)((ULONG)tabpos-(ULONG)Pdbcs);                    //~2B30R~//~vafkR~
        rlen=(int)((ULPTR)tabpos-(ULPTR)Pdbcs);                    //~vafkI~
        *(Pdata+rlen)=TABCHAR;                                     //~2B30I~
        rlen=Plen-rlen-1;                                          //~2B30I~
        pdbcs=tabpos+1;                                            //~2B30I~
        if (!rlen)                                                 //~2B30I~
        	break;                                                 //~2B30I~
    }                                                              //~2B30I~
    if (Puppersw)                                                  //~2B30I~
        ulopt=UBX_UPPER;                                           //~2B30I~
    else                                                           //~2B30I~
        ulopt=UBX_LOWER;                                           //~2B30I~
	ub2x(ulopt,Phexw,Pdata,Plen);	//edit to hex without interspace//~2B30I~
    phexw=Phexw;                                                   //~2B30I~
    for (rlen=Plen+Plen;rlen>0;rlen-=8,phexw+=8)                   //~2B30I~
    {                                                              //~2B30I~
    	len=min(rlen,8);                                           //~2B30I~
    	memcpy(phexd,phexw,len);                                   //~2B30I~
        phexd+=len;                                                //~2B30I~
        if (len!=rlen)	//last                                     //~2B30I~
        	*phexd++=' ';                                          //~2B30R~
    }                                                              //~2B30I~
//  return (ULONG)phexd-(ULONG)Phexd;                              //~2B30I~//~vafkR~
//  return (ULPTR)phexd-(ULPTR)Phexd;                              //~vafkI~//~vb2WR~
    return (int)((ULPTR)phexd-(ULPTR)Phexd);                       //~vb2WI~
}//wxe_hexdisplay                                                  //~2B30I~
//*************************************************************    //~2B02I~
//*get  data and len                                               //~2B02I~
//*ret :datalen                                                    //~2B02I~
//*************************************************************    //~2B02I~
int wxe_prtgetdatalen(PUFILEH Ppfh,PULINEH Pplh,int Preslen,int Pmaxlrecl,int *Pplen,char *Pdbcsdir)//~2C08R~
{                                                                  //~2B02I~
    UCHAR *pdbcs;                                                  //~2B02I~
    int len,dbcssplitsw=0;                                         //~2C08R~
#ifdef UTF8UCS2                                                    //~va20I~
    int rc,pos,posi;                                               //~va20R~
#endif                                                             //~va20I~
//***********************                                          //~2B02I~
    dbcssplitsw=0;                                                 //~2C08R~
    if (Ppfh->UFHtype==UFHTWXPWK)	//wxp **/***                   //~v626I~
    {                                                              //~v626I~
    	if (Preslen<Pplh->ULHlen)	//contline                     //~v626I~
        {                                                          //~v626I~
        	if (Pmaxlrecl>Swxpdatalinenosz)                        //~v626R~
	        	Pmaxlrecl-=Swxpdatalinenosz;	//skip linenosz edit by filesave for wxp **/***//~v626R~
        }                                                          //~v626I~
    }                                                              //~v626I~
#ifdef UTF8UCS2                                                    //~va20I~
    if (Ppfh->UFHtype!=UFHTDIR)                                    //~va20R~
    {                                                              //~va20I~
    	if (FILEUTF8MODE(Ppfh) && (((PWXEINTF)Gpwxei)->WXEIstatus & WXEIS_PRTVHEX))//~va20I~
        {                                                          //~va20I~
        	pos=posi=Pplh->ULHlen-Preslen;                         //~va20R~
	        rc=utfddoffs2pos(UTFDDO2PO_INITPOS,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,Pmaxlrecl,&pos);//~va20I~
            if (rc<=1)	//not out of range or dbcssplit            //~va20I~
            	Pmaxlrecl=pos-posi;	//data len ,cut by vhex expansion,split is evaluated later//~va20R~
        }                                                          //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
    if (Preslen<Pmaxlrecl)                                         //~2C01R~
        len=Preslen;                                               //~2C08R~
    else                                                           //~2C08I~
    if (Ppfh->UFHtype==UFHTDIR)                                    //~2C08R~
    {                                                              //~2C08I~
    	if (Pdbcsdir)	//after ddsetup                            //~2C08I~
        {                                                          //~2C08I~
//*dir lsit                                                        //~va20I~
			dbcssplitsw=(*(Pdbcsdir+WDIRLDSZ+Sdirmaxexplen-Sprtreslen+Pmaxlrecl)==DBCS2NDCHAR);//~2C08R~
//      	len=Pmaxlrecl+dbcssplitsw;                             //~v61zR~
        	len=Pmaxlrecl-dbcssplitsw;                             //~v61zI~
        }                                                          //~2C08I~
        else                                                       //~2C08I~
        	len=Pmaxlrecl;	//page skipping case                   //~2C08I~
    }                                                              //~2C08I~
    else                                                           //~2C08I~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~2C08R~
        len=Pmaxlrecl;                                             //~2C08R~
    else	//text file                                            //~2C08I~
    {                                                              //~2C08I~
        pdbcs=Pplh->ULHdbcs+Pplh->ULHlen-Preslen;                  //~2C08R~
#ifdef UTF8UCS2                                                    //~va20I~
        if (UDBCSCHK_DBCSNOTEND(*(pdbcs+Pmaxlrecl-1)))             //~va20I~
#else                                                              //~va20I~
        if (*(pdbcs+Pmaxlrecl)==DBCS2NDCHAR)                       //~2C08R~
#endif                                                             //~va20I~
            dbcssplitsw=1;                                         //~2C08R~
//      len=Pmaxlrecl+dbcssplitsw;                                 //~v61zR~
        len=Pmaxlrecl-dbcssplitsw;                                 //~v61zI~
    }                                                              //~2C08I~
    *Pplen=len;                                                    //~2C08I~
    return dbcssplitsw;                                            //~2C08I~
}//wxe_prtgetdatalen                                               //~2B16R~
//*************************************************************    //~va87I~
//*get  data and len                                               //~va87I~
//*ret :datalen                                                    //~va87I~
//*************************************************************    //~va87I~
int wxe_prtgetdatalenwkvhex(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Pmaxlrecl,int *Pplen)//~va87I~
{                                                                  //~va87I~
static int Swkvhexdbcssplitctr;                                    //~va87I~
    UCHAR *pdbcs;                                                  //~va87R~
    int len,reslen,offs,ulhlen;                                    //~va87R~
    int dbcssplitctr=0;                                            //~va87I~
    int swutf8file,ii,utf8chctr,dbcsid,dbcsidlast,sbcs2ctr=0;      //~va8dR~
    UCHAR *pcd;                                                    //~va8dI~
//***********************                                          //~va87I~
    UTRACEP("wxe_prtgetdatalenwkvhex entry lineno=%d,offs=%d,lineid=%d\n",Pplh->ULHlinenor,Swkvhexoffs,Swkvhexlineid);//~va87I~
	swutf8file=FILEUTF8MODE(Ppfh);	//::cb cpu8 mode               //~va8dI~
  if (Swkvhexlineid>1)	//2,3:vhex line                            //~va8dI~
	offs=Swkvhexoffsvhex;                                          //~va8dI~
  else                                                             //~va8dI~
	offs=Swkvhexoffs;                                              //~va87R~
    if (offs)	//contline                                         //~va87I~
    {                                                              //~va87I~
        if (Pmaxlrecl>Swxpdatalinenosz)                            //~va87I~
	        Pmaxlrecl-=Swxpdatalinenosz;	//skip linenosz edit by filesave for wxp **/***//~va87I~
    }                                                              //~va87I~
    ulhlen=Pplh->ULHlen;                                           //~va87R~
    reslen=max(0,ulhlen-offs);                                     //~va87I~
    Sprtreslen=reslen;                                             //~va87M~
    if (reslen<Pmaxlrecl)                                          //~va87I~
        len=reslen;                                                //~va87I~
    else	//text file                                            //~va87I~
    {                                                              //~va87I~
        len=Pmaxlrecl;                                             //~va87I~
        pdbcs=Pplh->ULHdbcs+ulhlen-reslen;                         //~va87R~
	    if (swutf8file                                             //~va8dI~
        &&  Swkvhexlineid==1	//charline                         //~va8dI~
        )                                                          //~va8dI~
        {                                                          //~va8dI~
            dbcsidlast=0;                                          //~va8dI~
        	for (utf8chctr=0,pcd=pdbcs,ii=Pmaxlrecl;ii>0;ii--,pcd++,utf8chctr++)//~va8dI~
            {                                                      //~va8dI~
            	dbcsid=*pcd;                                       //~va8dI~
            	if (UDBCSCHK_ISUCSSBCS(dbcsid)	//not ovf sbcs     //~va8dI~
            	&&  dbcsid>UDBCSCHK_SBCSUCSID)  //2 byte ucs       //~va8dI~
                {                                                  //~va8dI~
                	ii--;                                          //~va8dI~
                    sbcs2ctr++;	//need for next vhex offs          //~va8dI~
                }                                                  //~va8dI~
            	dbcsidlast=dbcsid;                                 //~va8dI~
            }                                                      //~va8dI~
	        if (utf8chctr && UDBCSCHK_DBCSNOTEND(dbcsidlast))      //~va8dI~
            {                                                      //~va8dI~
            	utf8chctr--;                                       //~va8dI~
            	dbcssplitctr=1;                                    //~va8dI~
            }                                                      //~va8dI~
            len=utf8chctr;                                         //~va8dI~
        }                                                          //~va8dI~
        else                                                       //~va8dI~
        if (UDBCSCHK_DBCSNOTEND(*(pdbcs+Pmaxlrecl-1)))             //~va87R~
        {                                                          //~va87I~
            dbcssplitctr=XESUB_DBCSSPLITCTR_L(pdbcs,Pmaxlrecl);    //~va87R~
            if (len>dbcssplitctr)                                  //~va87I~
            	len-=dbcssplitctr;                                 //~va87I~
            else                                                   //~va87I~
            	dbcssplitctr=0;                                    //~va87I~
        }                                                          //~va87I~
    }                                                              //~va87I~
    switch(Swkvhexlineid)                                          //~va87R~
    {                                                              //~va87I~
    case 0:                    //hdr line                          //~va87I~
    	Swkvhexoffs+=len;                                          //~va87R~
    	break;                                                     //~va87I~
    case 1:                    //dataline                          //~va87I~
    	Swkvhexdbcssplitctr=dbcssplitctr;                          //~va87I~
    	Swkvhexoffsnext=Swkvhexoffs+len;                           //~va87I~//~va8dR~
    	Swkvhexoffsnextvhex=Swkvhexoffsvhex+len+sbcs2ctr;          //~va8dI~
    	break;                                                     //~va87I~
    case 2:                                                        //~va87I~
    	if (len>Swkvhexdbcssplitctr)                               //~va87I~
        	len-=Swkvhexdbcssplitctr;                              //~va87I~
    	break;                                                     //~va87I~
    case 3:                    //vhexline                          //~va87I~
    	if (len>Swkvhexdbcssplitctr)                               //~va87I~
        	len-=Swkvhexdbcssplitctr;                              //~va87I~
    	Swkvhexoffs=Swkvhexoffsnext;                               //~va87I~
    	Swkvhexoffsvhex=Swkvhexoffsnextvhex;                       //~va8dI~
    	break;                                                     //~va87I~
	}                                                              //~va87I~
    UTRACEP("wxe_prtgetdatalenwkvhex next offs=%d,lineid=%d\n",Swkvhexoffs,Swkvhexlineid);//~va87I~
    *Pplen=len;                                                    //~va87I~
    return 0;                                                      //~va87I~
}//wxe_prtgetdatalenwkvhex                                         //~va87I~
//*************************************************************    //~2B02I~
//*get next data plh                                               //~2B02I~
//*ret :plh,0 for eof                                              //~2B02I~
//*************************************************************    //~2B02I~
PULINEH wxe_prtgetnextplh(void)                                    //~2B02I~
{                                                                  //~2B02I~
    PULINEH plh;                                                   //~2B02I~
//***********************	                                       //~2B02I~
    if (!Sprtplh)                                                  //~2B04I~
    	return 0;                                                  //~2B04I~
	for (plh=Sprtplh;plh=UGETQNEXT(plh),plh;)                      //~2B02R~
    	if (plh->ULHtype==ULHTDATA)                                //~2B02R~
        	break;                                                 //~2B02R~
    Sprtplh=plh;                                                   //~2B02I~
	return plh;                                                    //~2B02I~
}//wxe_prtgetnextplh                                               //~2B02I~
//*************************************************************    //~va87I~
//*get next data plh  for wxxp **/*** vhex mode                    //~va87I~
//*ret :plh,0 for eof                                              //~va87I~
//rc2:0:top of line(char/vhex),1:contdata                          //~va87I~
//*************************************************************    //~va87I~
//PULINEH wxe_prtgetnextplhwkvhex(int Popt,PULINEH *Ppplh,int *Pprc) //~va87I~//~va8eR~
PULINEH wxe_prtgetnextplhwkvhex(int Popt,int *Pprc)                //~va8eI~
{                                                                  //~va87I~
    PULINEH plh=NULL;                                              //~vafaR~
    int rc,offs;                                                   //~va87R~
//***********************                                          //~va87I~
    if (!Sprtplh)                                                  //~va87I~
    	return 0;                                                  //~va87R~
  if (Swkvhexlineid==1||Swkvhexlineid==2)                          //~va8dI~
    offs=Swkvhexoffsvhex;                                          //~va8dI~
  else                                                             //~va8dI~
    offs=Swkvhexoffs;                                              //~va87I~
    if (Swkvhexlineid==0        //top data lineid                  //~va87I~
    ||  Swkvhexlineid==3)                                          //~va87I~
    {                                                              //~va87I~
    	if (offs>=Sprtplh->ULHlen)                                 //~va87I~
        {                                                          //~va87I~
    		Swkvhexoffs=0;                                         //~va87I~
    		Swkvhexoffsvhex=0;                                     //~va8dI~
	    	Swkvhexlineid=0;	//new data line                    //~va87I~
        }                                                          //~va87I~
    }                                                              //~va87I~
  if (Swkvhexlineid==1||Swkvhexlineid==2)                          //~va8dI~
    offs=Swkvhexoffsvhex;                                          //~va8dI~
  else                                                             //~va8dI~
    offs=Swkvhexoffs;                                              //~va87R~
    if (offs)                                                      //~va87I~
    	rc=1;                                                      //~va87I~
    else                                                           //~va87R~
    	rc=0;                                                      //~va87I~
    switch(Swkvhexlineid)        //top data lineid                 //~va87R~
    {                                                              //~va87R~
    case 0:                                                        //~va87R~
    case 3:                                                        //~va87R~
    	if (!offs)                                                 //~va87I~
        {                                                          //~va87I~
        	for (plh=Sprtplh;plh=UGETQNEXT(plh),plh;)              //~va87R~
            	if (plh->ULHtype==ULHTDATA                         //~va87R~
            	&&  !UCBITCHK(plh->ULHflag6,ULHF6WXPWKVHEX) //next 2 line is vhex//~va87R~
            	)                                                  //~va87R~
                	break;                                         //~va87R~
        	if (!plh)                                              //~va87R~
            	return 0;                                          //~va87R~
	        Sprtplh=plh;                                           //~va87I~
        }                                                          //~va87I~
        else                                                       //~va87I~
        	plh=Sprtplh;                                           //~va87I~
        if (UCBITCHK(plh->ULHflag6,ULHF6WXPWKDATA)) //next 2 line is vhex//~va87I~
            Swkvhexlineid=1;        //next is vhex 1/2             //~va87I~
        else                                                       //~va87I~
            Swkvhexlineid=0;        //next is vhex 1/2             //~va87I~
        break;                                                     //~va87R~
    case 1:                                                        //~va87R~
        plh=UGETQNEXT(Sprtplh);                                    //~va87I~
        Swkvhexlineid=2;        //next is vhex 1/2                 //~va87R~
        break;                                                     //~va87R~
    case 2:                                                        //~va87R~
        plh=UGETQNEXT(Sprtplh);                                    //~va87R~
        plh=UGETQNEXT(plh);                                        //~va87R~
        Swkvhexlineid=3;        //next is vhex 1/2                 //~va87R~
    }                                                              //~va87R~
//  UTRACEP("wxe_prtgetnext ret topplh=%d,plhlineno=%d,lineid=%d,offs=%d\n",Sprtplh->ULHlinenor,plh->ULHlinenor,Swkvhexlineid,Swkvhexoffs);//~vafaR~
    *Pprc=rc;                                                      //~va87I~
	return plh;                                                    //~va87I~
}//wxe_prtgetnextplhwkvhex                                         //~va87I~
//*************************************************************    //~2B03I~
//*get  file atime and current time                                //~2B03I~
//*ret :none                                                       //~2B03I~
//*************************************************************    //~2B03I~
void wxe_prtgetftime(void *Ppfh,char *Pftime,char *Psystime)       //~2B03R~
{                                                                  //~2B03I~
	PUFILEH pfh;                                                   //~2B03I~
//***********************                                          //~2B03I~
	pfh=(PUFILEH)Ppfh;                                             //~2B03I~
	utimeedit("YY/mm/dd HH:MM:SS",Psystime);                       //~2B03R~
	if (pfh->UFHupctr)	//updating now                             //~2B03R~
    {                                                              //~2B03I~
        strcpy(Pftime,Psystime);                                   //~2B03I~
        strcat(Pftime," *");                                       //~2B03I~
    }                                                              //~2B03I~
    else                                                           //~2B03I~
    {                                                              //~2B03I~
    	ufdateedit(pfh->UFHfiledate,"YY/mm/dd",Pftime); //lower case is 0 suppress//~2B03R~
        *(Pftime+8)=' ';                                           //~2B03I~
    	uftimeedit(pfh->UFHfiletime,"HH:MM:SS",Pftime+9);          //~2B03R~
    }                                                              //~2B03I~
}//wxe_prtgetftime                                                 //~2B03R~
//*************************************************************    //~2B16I~
//*setup dirdata to print work                                     //~2B16I~
//*ret :none                                                       //~2B16I~
//*************************************************************    //~2B16I~
void wxe_ddsetup(PUFILEH Ppfh,PULINEH Pplh,char *Pdata)            //~2B16I~
{                                                                  //~2B16I~
	PUDIRLH pdh;                                                   //~2B16I~
	PWDIRLD pwdd;                                                  //~2B16R~
	UCHAR   *pc,*pc0,*wcmask,*pdbcs;                               //~2C08R~
    int level,len,explen,dirlrecl;                                 //~v76jR~
	UDISKINFO udiskinfo;                                           //~2B16I~
    long clustersz,diskfreesz[3],disktotsz[3];                     //~2B16I~
    UCHAR dweditnumwk[16];                                         //~2B16I~
//******************                                               //~2B16I~
    pdh=UGETPDH(Pplh);                                             //~2B16I~
    explen=Sdirmaxexplen;  //shift by long filename                //~2C07R~
    dirlrecl=WDIRLDSZ+explen;  //line width                        //~2C08R~
    pwdd=(PWDIRLD)(void*)Pdata;			//print work               //~2B16R~
    memset(pwdd,' ',dirlrecl);                                     //~2C08R~
    pdbcs=Pdata+dirlrecl;                                          //~2C08I~
    memset(pdbcs,0,dirlrecl);                                      //~2C08I~
//dir level and type                                               //~2B16I~
    if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max             //~2B16I~
		level=UDDMAXLEVEL;                                         //~2B16I~
	*(pwdd->WDDlvl+level)=pdh->UDHtype;                            //~2B16R~
    if (level)                                                     //~2B16I~
    	memset(pwdd->WDDlvl,'|',(UINT)level);                      //~2B16R~
//file name                                                        //~2B16I~
    pc=pwdd->WDDname;                                              //~2B16R~
    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                        //~2B16R~
        pc-=sizeof(pwdd->WDDlvl)-level-2;                          //~2B16R~
//  pc0=pdh->UDHname;                                              //~2B16M~//~va2mR~
    pc0=PDH_UDHname(pdh);	//lcname if already translated to      //~va2mI~
    len=strlen(pc0);                                               //~2B16I~
    memcpy(pc,pc0,(UINT)len);                                      //~2B16M~
    if (UCBITCHK(pdh->UDHflag2,UDHF2MASKNAME)	//renamesv is dirmask//~2C07I~
    &&  (wcmask=pdh->UDHrenamesv)!=0)                              //~2C07I~
        memcpy(pc+len+MASKINTSPACE,wcmask,strlen(wcmask));         //~2C07R~
    pc=(char*)(void*)pwdd;                                         //~2C07I~
    pc+=explen;                                                    //~2C07I~
    pwdd=(PWDIRLD)(void*)pc;  //shift by long filename             //~2C07R~
//file attr                                                        //~2B16I~
	if (pdh->UDHlevel)                                             //~2B16R~
    	ueditfattr(pdh->UDHattr,pwdd->WDDattr,0);                  //~2B16R~
    if (pdh->UDHlevel)                                             //~2B16R~
    {                                                              //~2B16R~
//size                                                             //~2B16I~
        if (UCBITCHK(pdh->UDHflag2,UDHF2DISPLC))  //display line count//~2B16R~
        {                                                          //~2B16R~
          	unumedit((ULONG)Pplh->ULHlinenow,"z,zzz,zzz,zz9",pwdd->WDDsize);//~2B16R~
          	*(pwdd->WDDsize+1)='#';                                //~2B16R~
        }                                                          //~2B16R~
        else                                                       //~2B16R~
//        	unumedit(pdh->UDHsize,"z,zzz,zzz,zz9",pwdd->WDDsize);  //~v731R~
            ufileeditsz(0,pdh->UDHsize,pwdd->WDDsize);             //~v731R~
        *(pwdd->WDDsize+sizeof(pwdd->WDDsize))=' ';                //~2C07R~
//date/time                                                        //~2B16I~
       	ufdateedit(pdh->UDHdate,"YY-MM-DD",pwdd->WDDdate);         //~2B16R~
        *(pwdd->WDDdate+sizeof(pwdd->WDDdate))=' ';                //~2C07R~
        uftimeedit(pdh->UDHtime,"HH:MM",pwdd->WDDtime);            //~2B16R~
        *(pwdd->WDDtime+sizeof(pwdd->WDDtime))=' ';                //~2C07R~
    }                                                              //~2B16R~
    else                    //root dir                             //~2B16R~
//      if (!ugetdiskfree(*pdh->UDHname,&udiskinfo))               //~v7abR~
        if (!ugetdiskfree(pdh->UDHname,&udiskinfo))                //~v7abI~
        {                                                          //~2B16R~
            clustersz=(long)udiskinfo.bytes_per_sector*(long)udiskinfo.sectors_per_cluster;//~2B16R~
            diskfreesz[0]=0;                                       //~2B16R~
            diskfreesz[1]=(long)udiskinfo.avail_clusters;          //~2B16R~
            ucalc_dwmult(diskfreesz,clustersz);                    //~2B16R~
            disktotsz[0]=0;                                        //~2B16R~
            disktotsz[1]=(long)udiskinfo.total_clusters;           //~2B16R~
            ucalc_dwmult(disktotsz,clustersz);                     //~2B16R~
            sprintf(pwdd->WDDattr,"x%X",(UINT)clustersz);          //~2B16R~
            if (disktotsz[0]) //dword size                         //~2B16R~
            {                                                      //~2B16R~
                ucalc_dwdiv(diskfreesz,1024);                      //~2B16R~
                diskfreesz[2]=diskfreesz[1];                       //~2B16R~
                diskfreesz[1]=0;        //3 word data for bc_dweditnum//~2B16R~
                bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,diskfreesz,dweditnumwk);//~2B16R~
                sprintf(pwdd->WDDdate,"%12sK/",dweditnumwk);       //~2B16R~
                ucalc_dwdiv(disktotsz,1024);                       //~2B16R~
                disktotsz[2]=disktotsz[1];                         //~2B16R~
                disktotsz[1]=0;        //3 word data for bc_dweditnum//~2B16R~
                bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,disktotsz,dweditnumwk);//~2B16R~
                sprintf(pwdd->WDDsize,"%12s",dweditnumwk);         //~2C07R~
                *(pwdd->WDDsize+12)='K';                           //~2C07I~
            }                                                      //~2B16R~
            else                                                   //~2B16R~
            {                                                      //~2B16R~
                unumedit(diskfreesz[1],"z,zzz,zzz,zz9/",pwdd->WDDdate);//~2B16R~
                unumedit(disktotsz[1],"z,zzz,zzz,zz9",pwdd->WDDsize);//~2B16R~
            }                                                      //~2B16R~
        }                                                          //~2B16R~
	setdbcstbl(Pdata,pdbcs,dirlrecl);                              //~2C08I~
    return;                                                        //~2B16I~
}//wxe_ddsetupsub                                                  //~2B16I~
//*************************************************************    //~2B16I~
//*get dirlist expand len by long filename                         //~2B16I~
//*ret :none                                                       //~2B16I~
//*************************************************************    //~2B16I~
int wxe_getddexpand(PULINEH Pplh)                                  //~2B16I~
{                                                                  //~2B16I~
	PUDIRLH pdh;                                                   //~2B16I~
    int len,level;                                                 //~2B16I~
    char *wcmask;                                                  //~2B16I~
//********************************                                 //~2B16I~
    pdh=UGETPDH(Pplh);                                             //~2B16R~
//  len=strlen(pdh->UDHname);                                      //~2B16I~//~va2mR~
    len=strlen(PDH_UDHname(pdh));                                  //~va2mI~
    if (UCBITCHK(pdh->UDHflag2,UDHF2MASKNAME)	//renamesv is dirmask//~2C07I~
    &&  (wcmask=pdh->UDHrenamesv)!=0)                              //~2C07I~
        len+=strlen(wcmask)+MASKINTSPACE;                          //~2C07R~
    if ((level=pdh->UDHlevel)>UDDMAXLEVEL)  //over max             //~2B16I~
        level=UDDMAXLEVEL;                                         //~2B16I~
    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                        //~2B16I~
        len-=sizeof(((PWDIRLD)0)->WDDlvl)-level-2;                 //~2B16I~
    if ((len-=sizeof(((PWDIRLD)0)->WDDname))<0) //if >0;name overflow//~2B16I~
        len=0;                                                     //~2B16I~
    return len;                                                    //~2B16I~
}//wxe_getddexpand                                                 //~2B16I~
//*************************************************************    //~va87I~
//*setup print scr work                                            //~va87I~
//*************************************************************    //~va87I~
int wxe_wxpsetupprtscr(int Popt,PUFILEH Ppfh)                      //~va87I~
{                                                                  //~va87I~
    int swebcfile,datalineid,vhexlineid,len;                       //~va87R~
    PULINEH plh;                                                   //~va87I~
    UCHAR *pc,*pcd;                                                //~va87I~
//********************************                                 //~va87I~
	UCBITON(Ppfh->UFHflag11,UFHF11WXPPRTSCRVHEX);    // wxp work file for wxp **/*** cmd//~va87R~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va87I~
    datalineid=UWHICH(swebcfile,CHAR_EBC_0,'0');                   //~va87I~
    vhexlineid=UWHICH(swebcfile,CHAR_EBC_SPACE,' ');               //~va87I~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~va87I~
    {                                                              //~va87I~
    	if (plh->ULHtype!=ULHTDATA)                                //~va87I~
        	continue;                                              //~va87I~
        len=plh->ULHlen;                                           //~va87I~
        pc=plh->ULHdata;                                           //~va87I~
        pcd=plh->ULHdbcs;                                          //~va87I~
      	if (len)                                                   //~va87I~
        {                                                          //~va87I~
        	len--;                                                 //~va87I~
        	if (*pc==datalineid)                                   //~va87R~
            	UCBITON(plh->ULHflag6,ULHF6WXPWKDATA);             //~va87I~
            else                                                   //~va87I~
        	if (*pc==vhexlineid)                                   //~va87R~
            	UCBITON(plh->ULHflag6,ULHF6WXPWKVHEX);             //~va87I~
            memcpy(pc,pc+1,(UINT)len);                             //~va87I~
            if (pcd)                                               //~va87I~
            	memcpy(pcd,pcd+1,(UINT)len);                       //~va87I~
        	plh->ULHlen=len;                                       //~va87I~
        }                                                          //~va87I~
    }                                                              //~va87I~
    return 0;                                                      //~va87I~
}//wxe_wxpsetupprtscr                                              //~va87I~
//*************************************************************    //~v54yI~
//*save wxp parm and kick page setup                               //~v54yI~
//*ret :rc                                                         //~v54yI~
//*************************************************************    //~v54yI~
//int wxe_wxpreq(char *Porgfnm)                                    //~v552R~
//int wxe_wxpreq(int Popt,char *Porgfnm)                             //~v552I~//~va87R~
#ifdef W32UNICODE                                                  //~vavzI~
int wxe_wxpreq(int Popt,char *Porgfnm,void *Ppfh,void *Ppfhorg)    //~vavzI~
#else                                                              //~vavzI~
int wxe_wxpreq(int Popt,char *Porgfnm,void *Ppfh)                  //~va87I~
#endif                                                             //~vavzI~
{                                                                  //~v54yI~
    int rc;                                                        //~v54yI~
    PUFILEH pfh;                                                   //~va87I~
#ifdef W32UNICODE                                                  //~vavzI~
    PUFILEH pfhorg;                                                //~vavzI~
#endif                                                             //~vavzI~
//********************************                                 //~v54yI~
#ifdef W32UNICODE                                                  //~vavzI~
	*SwxporgfnmW=0;                                                //~vavzI~
    pfhorg=(PUFILEH)Ppfhorg;                                       //~vavzR~
#endif                                                             //~vavzI~
	if (Porgfnm)                                                   //~v54yI~
    {                                                              //~v54yI~
    	*Swxporgfnm='*';	//work id                              //~v54yR~
      if (Popt & WXP_PRTSCR)                                       //~v552I~
      {                                                            //~v552I~
    	*(Swxporgfnm+1)='*';	//work id                          //~v552I~
		strcpy(Swxporgfnm+2,Porgfnm);                              //~v552I~
      }                                                            //~v552I~
      else                                                         //~v552I~
		strcpy(Swxporgfnm+1,Porgfnm);                              //~v54yI~
        Swxpdatalinenosz=((UINT)Popt>>8);                          //~v626I~
#ifdef W32UNICODE                                                  //~vavzM~
        if (pfhorg && pfhorg->UFHfilenamedddata)                   //~vavzR~
        {                                                          //~vavzI~
            int ucsctr,opt;                                        //~vavzI~
        //****************                                         //~vavzI~
            opt=UTFDD2UO_ERRREP;                                   //~vavzI~
            *SwxporgfnmW='*';   //work id                          //~vavzI~
            if (Popt & WXP_PRTSCR)                                 //~vavzI~
            {                                                      //~vavzI~
                *(SwxporgfnmW+1)='*';   //work id                  //~vavzI~
                utfdd2u(opt,pfhorg->UFHfilenamedddata,pfhorg->UFHfilenamedddbcs,pfhorg->UFHfilenameddlen,SwxporgfnmW+2,sizeof(SwxporgfnmW)-UWCHSZ*3,&ucsctr,NULL/*sbcsctr*/,NULL/*dbcsctr}*/);//~vavzR~
                *(SwxporgfnmW+2+ucsctr)=0;                         //~vavzI~
            }                                                      //~vavzI~
            else                                                   //~vavzI~
            {                                                      //~vavzI~
                utfdd2u(opt,pfhorg->UFHfilenamedddata,pfhorg->UFHfilenamedddbcs,pfhorg->UFHfilenameddlen,SwxporgfnmW+1,sizeof(SwxporgfnmW)-UWCHSZ*2,&ucsctr,NULL/*sbcsctr*/,NULL/*dbcsctr}*/);//~vavzR~
                *(SwxporgfnmW+1+ucsctr)=0;                         //~vavzI~
            }                                                      //~vavzI~
        }                                                          //~vavzI~
#endif                                                             //~vavzM~
    }                                                              //~v54yI~
    else                                                           //~v54yI~
    {                                                              //~v626I~
    	Swxpdatalinenosz=0;                                        //~v626I~
    	*Swxporgfnm=0;                                             //~v54yI~
    }                                                              //~v626I~
    if (Ppfh)                                                      //~va87I~
    {                                                              //~va87I~
    	pfh=(PUFILEH)Ppfh;                                         //~va87I~
	    if (pfh->UFHtype==UFHTWXPWK	//wxp **/***                   //~va87R~
		&&  UBITCHKALL(Popt,WXP_PRTSCR|WXP_VHEX)                   //~va87R~
        )                                                          //~va87I~
    		wxe_wxpsetupprtscr(0,pfh);                             //~va87R~
    }                                                              //~va87I~
//  rc=upostmsg(WM_COMMAND,ID_PAGE_SETUP,0);                       //~v54yI~//~vamDR~
    rc=upostmsgp(WM_COMMAND,ID_PAGE_SETUP,0);                      //~vafkI~
    return rc;                                                     //~v54yI~
}//wxe_wxpreq                                                      //~v54yI~
//*************************************************************    //~v54yI~
//*save wxp parm and kick page setup                               //~v54yI~
//*ret :rc:1:original filename is not same as UFHfilename          //~v54yI~
//*************************************************************    //~v54yI~
#ifdef W32UNICODE                                                  //~vavzI~
int wxe_getorgfnm(char *Porgfnm,UWCH *PorgfnmW)                    //~vavzI~
#else                                                              //~vavzI~
int wxe_getorgfnm(char *Porgfnm)                                   //~v54yI~
#endif                                                             //~vavzI~
{                                                                  //~v54yI~
//********************************                                 //~v54yI~
	if (!*Swxporgfnm)                                              //~v54yI~
    {                                                              //~v54yI~
        *Porgfnm=0;                                                //~v54yI~
    	return 0;                                                  //~v54yI~
    }                                                              //~v54yI~
	strcpy(Porgfnm,Swxporgfnm);                                    //~v54yI~
#ifdef W32UNICODE                                                  //~vavzI~
	strcpyW(PorgfnmW,SwxporgfnmW);                                 //~vavzI~
#endif                                                             //~vavzI~
    return 1;                                                      //~v54yI~
}//wxe_getorgfnm                                                   //~v54yI~
////*************************************************************  //~v71AR~
////*kick winhelp                                                  //~v71AR~
////*ret :rc                                                       //~v71AR~
////*************************************************************  //~v71AR~
//int wxe_helpreq(void)                                            //~v71AR~
//{                                                                //~v71AR~
//    int rc;                                                      //~v71AR~
////********************************                               //~v71AR~
//    rc=upostmsgp(WM_COMMAND,ID_HELPXE,0); //msg to parent window //~v71AR~
//    return rc;                                                   //~v71AR~
//}//wxe_helpreq                                                   //~v71AR~
//*************************************************************    //~v71AI~
//*copy file into dir by dnd                                       //~v71AI~
//*************************************************************    //~v71AI~
int wxe_helpcall(void)                                             //~v71AI~
{                                                                  //~v71AI~
    int rc;                                                        //~v71AI~
//***********************                                          //~v71AI~
	rc=wxe_funccall(FUNCID_HELP,"");                               //~v71AI~
    return rc;                                                     //~v71AI~
}//wxe_helpcall                                                    //~v71AI~
//*************************************************************    //~va8aI~
//*end wxp edit panel                                              //~va8aI~
//*************************************************************    //~va8aI~
int wxe_endprint(int Popt)                                         //~va8aI~
{                                                                  //~va8aI~
    int rc=0;                                                      //~va8aI~
    PUCLIENTWE pcw;                                                //~va8aI~
    PUFILEH pfh;                                                   //~va8aI~
//***********************                                          //~va8aI~
	if (wxe_getpcw(&pcw)==PRTTYPE_FILE)                            //~va8aI~
    {                                                              //~va8aI~
    	pfh=UGETPFHFROMPCW(pcw);                                   //~va8aI~
      	if (pfh->UFHtype==UFHTWXPWK)                               //~va8aI~
        {                                                          //~va8aI~
			rc=wxe_funccall(FUNCID_CANCEL,"");                     //~va8aI~
        }                                                          //~va8aI~
    }                                                              //~va8aI~
    return rc;                                                     //~va8aI~
}//wxe_endprint                                                    //~va8aI~
