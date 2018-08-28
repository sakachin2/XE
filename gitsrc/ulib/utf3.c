//*CID://+v6X3R~:                             update#=  679;       //~v6X3R~
//*********************************************************************//~7712I~
//utf3.c                                                           //~7817R~
//* utf8 data manipulation:os library                              //~7712R~
//*********************************************************************//~7712I~
//v6X3:180816 Hangul 1160-11ff is not combining(Category:Lo:Letter,Other) but combined actualy(u1109+u1161), On W32 Suctbj adjust as DBCS if ISDBCS_J()//~v6X3I~
//vbmk:180813 (XE)for test,try mk_wcwidth_cjk(ambiguous:Wide DBCS) for visibility chk. use /YJ option//~vbmkI~
//v6Wq:180803 Format is not always width=1(u+06dd:End of Ayah is dbcs size)//~v6WqI~
//v6Wp:180802 adjust wcwidth on Win10                              //~v6WpI~
//v6Wn:180724 (v6W9 for gxe) combining char such as u309a(u306f+u309a) exists.//~v6WnI~
//v6Wm:180724 utfwcwidth return len=1 for Category "Cf"(wcwidth=0)  if ucs<ENTNO(2 if ucs>=ENTNO).//~v6WmI~
//            determin combining for ucs>=ENTNOv should not use wcwidth==0 but combining definition//~v6WmI~
//v6Wk:180723 (gxe)ambiguous(width=2) for gxe                      //~v6WkI~
//v6Wi:180722 u+ad(Soft Hyphen) is wcwidth=0,bu combineprocess A0+ad show on 2 col. trate it as utfwcwidth=1 (unicode category Cf:Format)//~v6WiI~
//v6Wh:180722 modify utfwcwidth 2-->1 for ambiguous for wcwidth=1  //~v6WhI~
//v6W9:180708 dbcs combining char such as u309a(u306f+u309a) exists.//~v6W9I~
//v6Vt:180622 (BUG)checking Pucs==Solducs bypass UCODETB_UNP chking//~v6VtI~
//v6Vr:180622 move v6Vn to common to xe and wxe(Suctbj), visible for xe if defined as WIDE//~v6VrI~
//v6Vo:180621 (W32:BUG)Suctbj UCODEID_UNPF should return -1 like as Suctbj_cjk//~v6VoI~
//v6Vn:180620 (WXE)define ambiguous for wxe                        //~v6VnI~
//v6Vb:180612 add isSpacingCombiningmark                           //~v6VbI~
//v6V9:180608 (LNX)unicode tbl,move Suctb_euc(_console) to Suctbl_utf8(_XXE)//~v6V9I~
//            uviom use move+add_wchnstr for utf8 file             //~v6V9I~
//            uviom use mvaddchnstr for localefile(euc) width UDBCSCHK_DBCS1/2//~v6V9I~
//v6V7:180606 do not modify by wcwidth api,acept it only for return by mk_wcwidth//~v6V7I~
//v6V4:180531 apply mk_wcwidth also for ucs4(>=map entry)          //~v6V4I~
//v6V2:180522 unicode display test on ub17.10                      //~v6V2I~
//v6V1:180518 char width adjust to ubuntu 17.10(kernel 4.13.0)     //~v6V1I~
//v6S1:180129 (Ubuntu 17.10:gcc7.2)Lnx warning iswprint is not defined(wctype.h required)//~v6S1I~
//v6C3:160331 (BUG) missing to free modify map work tbl            //~v6C3I~
//v6BC:160306 W32:iswprint support BMP(ucs2) only                  //~v6BCI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6hH:120915 (BUG) dbcstbl is all sbcs(utfcvl2f)                  //~v6hHI~
//v6fs:120507 (Sabayon) #error glib.h can be included directly     //~v6fsI~
//v6c5:120121 (Axe)no mk_wcwidth,completeley depends to wcwwidth(Java getTextWidths)(but allow adjust by parameter file)//~v6c5I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6b5:110829 utfcvf2u:no need to chk printable as locale code     //~v6b5I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v697:100807 (W32)sbcs map tbl overflow for non CJK; chk printable because win has no wcwidth which linux has.//~v697I~
//v696:100807 (WXE:BUG)reports from dsk1;mkwcwidth_cjk was applied for not DBCS env//~v696I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v67Z:100615 (LNX)sbcsid overflowed at ub9(ue000-u8ff private area is assigbed as sbcs)//~v67ZI~
//            remap should reassign for overflowed ucs             //~v67ZI~
//v65p:100401 v65n for LNX                                         //~v65pI~
//v65e:100313 (LNX:BUG)when CJK is not UTF8,width tbl search return unpredictable value(invalid wcwidth)//~v65eI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v655:100211 XXE:adust font width for CJK by test as not CONSOLE so far//~v651I~
//v651:100207 (WIN)support ligature(by A+";") for RTL lang(no need DBCS for arabic)//~v651I~
//v650:100121 print width=0(combine mdeo)                          //~v650I~
//v647:100115 (WIN)wchar_t is ushort on Windows,consideration for UCS4//~v647I~
//v643:091204 (Win:UTF8)base on v614;define wide                   //~v643I~
//v642:091126 (UTF8:BUG)devide is wide but value is f7 not f6      //~v642I~
//v641:091126 (UTF8:BUG)wcwidth_cjk was for LNX only on xeu        //~v641I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62X:091107_compchkm                                             //~v62XI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62G:091005_(BUG)for isprint func;utfcvu2lany1mb is always success. isprint should be used//~v62GI~
//                 but for isprint setlocale should be issued for -Cparameter. v62F is now meaningless.//~v62GI~
//v620:090506 merge UTF8 version                                   //~v620I~
//            utfwcwidth-->mbcslen after ucs->locale               //~v620I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5m0:080125 warning when install to debian4                      //~v5m0R~
//v60q:071021 (UTF:LNX)cursesw write to screen only when wcrtomb>0 (use as isprintable)//~v60mI~
//v60m:071019 (UTF:LNX)default width table for ja_JP.eucJP         //~v60mI~
//v60f:071018 (UTF:LNX)chk by g_locale_from_utf8 when forced UTF8(-y8 under no utf8 env)//~v60fI~
//            to avoid screen corrupt at console mode              //~v60fI~
//v600:070710 (UTF8)new typdef                                     //~7712I~
//*********************************************************************//~7712I~
#include <stdio.h>                                                 //~7712I~
#include <stdlib.h>                                                //~7712I~
#include <ctype.h>                                                 //~7712I~
#include <string.h>                                                //~7712I~
#include <errno.h>                                                 //~7712I~
                                                                   //~7712I~
#ifdef UNX                                                         //~7712I~
    #include <unistd.h>                                            //~7712I~
	#define __USE_XOPEN         //for wcwidth                      //~7712I~
	#include <wchar.h>                                             //~7712I~
    #ifdef LNX                                                     //~7712I~
      #ifndef ARM                                                  //~v6a0I~
//	    #include <glib/gunicode.h>                                 //~7712I~//~v6fsR~
//	    #include <glib/gmem.h>                                     //~7712I~//~v6fsR~
//	    #include <glib/gconvert.h>                                 //~7712I~//~v6fsR~
		#include <glib.h>                                          //~v6fsI~
//      #ifdef MGW32                                               //~v5ncI~//~v6S1R~
            #include <wctype.h>                                    //~v5ncI~
//      #endif                                                     //~v5ncI~//~v6S1R~
      #endif	//ARM                                              //~v6a0I~
    #endif                                                         //~7712I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~7712I~
    #ifdef W32                                                     //~v5mQI~
		#include <wchar.h>                                         //~v5mQI~
    #endif                                                         //~v5mQI~
#endif //!!!!!!!!!!!!!!!!!!                                        //~7712I~
//*******************************************************          //~7712I~
#include <ulib.h>                                                  //~7712I~
#include <ualloc.h>                                                //~7922R~
#include <uque.h>                                                  //~7922I~
#include <ucvucs.h>                                                //~7712I~
#include <udbcschk.h>                                              //~7817I~
#include <utrace.h>                                                //~7712I~
#include <uerr.h>                                                  //~7712I~
#include <utf.h>                                                   //~7712I~
#include <utf2.h>                                                  //~7712I~
#include <ufemsg.h>                                                //~7922I~
#ifdef UTF8SUPPH                                                   //~v5ncI~
	#include <ucvext.h>                                            //~v5ncI~
#endif                                                             //~v5ncR~
#ifdef UTF8UCS2                                                    //~v640I~
	#include <utf22.h>                                             //~v640I~
#endif                                                             //~v640I~
//*******************************************************          //~7922I~
typedef struct _UCODETB {                                          //~7925R~
  int first;                                                       //~7922I~
  int last;                                                        //~7922I~
  int datatype;                                                    //~7922R~
#define UCODETB_LENMASK  0x03 //length mask of datatype            //~7924I~
#define UCODETB_UNPF    0x0100 //unprintable                       //~7925R~
#define UCODETB_CMT     '#'                                        //~7925I~
#define UCODETB_COMP    '0'     //width=0;for composite            //~7925I~
#define UCODETB_SBCS    '1'                                        //~7922I~
#define UCODETB_SBCSF   'S'     //ignore wcwidth()=2 and force width=1//~v6WkI~
#define UCODETB_DBCS    '2'     //need 2 column to display         //~7925R~
#define UCODETB_NARROW  'N'     //narrow(fontwidth=1) DBCS         //~v62UR~
//*when wcwidth==2, add padding                                    //~v640I~
#define UCODETB_WIDE    'W'     //wide  (fontwidth=2) SBCS         //~v62UR~
//*font is wide but next gryph override 2nd half of the font,ex 0xa3:pond//~v640R~
#define UCODETB_UNP     '-'     //need 2 column to display         //~7925I~
#define UCODETB_OPTION  '@'     //option entry                     //~7925I~
} UCODETB,*PUCODETB;                                               //~7925R~
//**************************************************               //~7922I~
static PUCODETB Sutftb=0;                                          //~7925R~
static int Sutftbentno=0;                                          //~7922I~
//static int Sutftbopt=0;      //ex) @4 :NOJ                       //~v62UR~
//#define SUO_NATIVE  0x01 //use wcwidth                             //~7929R~//~v6WnR~
//#define SUO_CJK     0x02 //use mk_wcwidth_cjk                      //~7929R~//~v6WnR~
//#define SUO_NOJ     0x04 //skip utftbsrch_j                        //~7A01R~//~v6WnR~
//#define SUO_NOLOCALEP 0x10 //no locale nonversion chk for isprint  //~v60fR~//~v6WnR~
//#define SUO_NOLOCALEW 0x20 //no locale nonversion chk for wcwidth  //~v60fI~//~v6WnR~
//#define SUO_NOEUCTB   0x40 //nochk euc tbl                         //~v60qR~//~v6WnR~
//#define SUO_CONSOLE   0x80 //old terminal emulator                 //~v62UR~//~v6WnR~
#ifdef WXEXXE                                                      //~v62UR~
#ifdef AAA                                                         //~v643I~
static int Sutftbopt=0;      //ex) @4 :NOJ                         //~v62UR~
#else                                                              //~v643I~
#ifdef XXE                                                         //~v651R~
static int Sutftbopt=0; //use GUI versionfor CJK                   //~v651R~
#else                                                              //~v651R~
//static int Sutftbopt=SUO_CONSOLE;   //based on wkwidth_cjk,same as xe//~v643I~//~v6WpR~
static int Sutftbopt=0; //use GUI                                  //~v6WpI~
#endif                                                             //~v651R~
#endif                                                             //~v643I~
#else                                                              //~v62UR~
#ifdef LNX                                                         //~v641I~
static int Sutftbopt=SUO_CONSOLE;   //user cjk                     //~v62UR~
#else                                                              //~v641I~
#ifdef UTF8UCS2                                                    //~v643I~
static int Sutftbopt=SUO_CONSOLE;   //user cjk                     //~v643I~
#else                                                              //~v643I~
static int Sutftbopt=0;   //user cjk                               //~v641I~
#endif                                                             //~v643I~
#endif                                                             //~v641I~
#endif                                                             //~v62UR~
#ifdef W32                                                         //~v6V4I~
	#ifdef WXE                                                     //~v6V4I~
    	static int SswWXE=1;                                       //~v6V4I~
    #else                                                          //~v6V4I~
    	static int SswWXE=0;                                       //~v6V4I~
    #endif                                                         //~v6V4I~
#endif                                                             //~v6V4I~
//static int Sviowidth;                                            //~7924R~
//**************************************************               //~7712I~
int utftbsrch(ULONG Pucs,PUCODETB Ppuctb,int Pmax);                //~7925I~
int utftbsrch_j(ULONG Pucs);                                       //~7925I~
#ifdef UTF8UCS2                                                    //~v640I~
int utfwcwidthsub(int Popt,ULONG Pucs);                            //~v640I~
#else                                                              //~v640I~
int utfwcwidthsub(ULONG Pucs);                                     //~v62UR~
#endif                                                             //~v640I~
void utftbfhelp(void);                                             //~7922I~
#ifdef LNX                                                         //~v62XI~
int utftbsrch_cjk(ULONG Pucs);                                     //~v62UR~
#endif                                                             //~v62XI~
#ifdef LNX                                                         //~v60mI~
	int utftbsrch_jeuc(ULONG Pucs);                                //~v60mI~
#endif                                                             //~v60mI~
int utfwcwidthsubNoMap(int Popt,ULONG Pucs);                       //~v6V4I~
//**************************************************               //~7712M~
//*check utf char                                                  //~7712R~
//*rc:4:err utf,1:width unknown                                    //~7712I~
//**************************************************               //~7712M~
int utfmb2wc(int Popt,UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Ppreadlen,int *Ppwidth)//~7924R~
{                                                                  //~7712M~
//#ifdef LNX                                                       //~v5m0R~
#ifdef UTF8UCS2                                                    //~v647I~
//  UWCHART  wc;                                                   //~v647R~//~v6BjR~
    UWUCS    wc;                                                   //~v6BjI~
#else                                                              //~v647I~
    wchar_t  wc;                                                   //~7712M~
#endif                                                             //~v647I~
//#else                                                            //~v5m0R~
    ULONG    wc4;                                                  //~v5m0R~
//#endif                                                           //~v5m0R~
    int ch,readlen=1,rc=0,rc2,width=1,chlen;                       //~7921R~
#ifdef UTF8SUPPH                                                   //~v5ncI~//~v62UR~
	UCHAR mbstr[MAX_MBCSLEN];                                      //~v5ncI~//~v62UR~
#endif                                                             //~v5ncI~//~v62UR~
//******************                                               //~7712M~
    if (*Ppreadlen)                                                //~7712M~
        *Ppreadlen=0;                                              //~7712M~
	if (!Plen)                                                     //~7712M~
    	return 8;                                                  //~7712M~
//  wc=ch=*Pdata;                                                  //~7921R~//~v6BiR~
    wc=(UWCHART)(ch=*Pdata);                                       //~v6BiI~
    chlen=UTF8CHARLEN(ch);                                         //~7921I~
//UTRACEP("utfmb2wc chlen=%d,ch=%x\n",chlen,ch);                   //~v6a0R~
    if (!chlen || chlen>UTF8_MAXCHARSZ)                            //~7921R~
        rc=4;                                                      //~7921I~
    else                                                           //~7712M~
    if (chlen!=1)    //ch>=128                                     //~7921I~
    {                                                              //~7921I~
//  	rc2=utfgetwc(Pdata,Plen,&wc,&readlen);	//errutf           //~v5m0R~
    	rc2=utfgetwc(Pdata,Plen,&wc4,&readlen);	//errutf           //~v5m0R~
#ifdef UTF8UCS2                                                    //~v647I~
//      wc=(UWCHART)wc4;                                           //~v647R~//~v6BjR~
        wc=(UWUCS)wc4;                                             //~v6BjI~
#else                                                              //~v647I~
        wc=(wchar_t)wc4;                                           //~v5m0R~
#endif                                                             //~v647I~
//UTRACEP("utfmb2wc getwc rc=%d,wc=%x,readlen=%d\n",rc2,wc,readlen);//~v6a0R~
    if (!(Popt & UTCO_NOCHKLOCALE))                                //~v6b5I~
      if (Ppwidth)                                                 //~v62UR~
      {                                                            //~v62UR~
        if (!rc2)                                                  //~7921I~
        {                                                          //~7926I~
#ifdef UTF8SUPPH                                                   //~v5ncI~//~v62UR~
			rc2=utfcvu2lany1mb(0,wc,mbstr,&width);                 //~v5ncI~//~v62UR~
#else                                                              //~v5ncI~//~v62UR~
		    rc2=utfisprint(0,wc)==0;                               //~7921R~
#endif                                                             //~v5ncI~//~v62UR~
//UTRACEP("utfmb2wcisprint wc=%04x,rc2=%d,width=%d\n",wc,rc2,width);//~v6a0R~
		}                                                          //~7926I~
      }                                                            //~v62UR~
        if (rc2)                                                   //~7921I~
        {                                                          //~7921R~
            readlen=1;                                             //~7921R~
//          wc=ch;                                                 //~7921I~//~v6BiR~
            wc=(UWCHART)ch;                                        //~v6BiI~
            rc=4;       //err utf                                  //~7921R~
        }                                                          //~7921R~
        else                                                       //~7921R~
        {                                                          //~7921R~
#ifdef UTF8SUPPH                                                   //~v5ncI~
//     	  if (Popt & UTCO_COLUMNCOUNT)                             //~v62UR~//~v6hHR~
      	  if (Ppwidth)      //param sepecified                     //~v6hHI~
//            width=utfwcwidth(wc);   //!!! wcwidth requires "setlocal" call before//~v62UR~
//            width=utfwcwidth(0,wc,0/*font flag*/);   //!!! wcwidth requires "setlocal" call before//~v62UR~//~v6BkR~
              width=utfwcwidth(0,(ULONG)wc,0/*font flag*/);   //!!! wcwidth requires "setlocal" call before//~v6BkI~
#else                                                              //~v62UR~
			if (width!=1&&width!=2)                                //~v5ncI~
            	width=-1;                                          //~v5ncI~
#endif                                                             //~v5ncI~
//UTRACEP("utfmb2wc width=%d wc=%04x\n",width,wc);                 //~v6a0R~
            if (width<0)                                           //~7921R~
            {                                                      //~7921R~
                UTRACEP("utfmb2wc 62U@ wcwidth width=%d wc=%xd,readlen=%d,parmlen=%d\n",width,wc,readlen,Plen);//~7921R~//~v62UR~
                width=1;                                           //~7921R~
                rc=1;                                              //~7921R~
            }                                                      //~7921R~
            else                                                   //~7921R~
            if (!width)                                            //~7921R~
            {                                                      //~7921R~
                UTRACEP("utfmb2wc 62U@ wcwidth width=%d wc=%04x,readlen=%d,parmlen=%d\n",width,wc,readlen,Plen);//~7921R~//~v62UR~
            }                                                      //~7921R~
        }                                                          //~7921R~
    }//>=0x80                                                      //~7921I~
    if (Ppucs)                                                     //~7730I~
        *Ppucs=(ULONG)wc;                                          //~7730I~
    if (Ppreadlen)                                                 //~7712M~
    	*Ppreadlen=readlen;                                        //~7712M~
    if (Ppwidth)                                                   //~7730R~
    	*Ppwidth=width;                                            //~7730R~
//UTRACEP("utfmb2wc rc=%d,width=%d readlen=%d wc=%04x\n",rc,width,readlen,wc);//~v6a0R~
    return rc;                                                     //~7712M~
}//utfmb2wc                                                        //~7724I~
//*******************************************************          //~7724I~
//*return char width                                               //~v62UR~
//*******************************************************          //~7724I~
//int utfwcwidth(ULONG Pucs)                                       //~v62UR~
int utfwcwidth(int Popt,ULONG Pucs,int *Ppflag)                    //~v62UR~
{                                                                  //~v62UR~
	int flag,rc,len;                                               //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
  #ifdef LNX                                                       //~v640I~
	int wcw;                                                       //~v640I~
  #endif                                                           //~v640I~
	int opt;                                                       //~v640R~
#endif                                                             //~v640I~
//****************                                                 //~v62UR~
//#ifdef UTF8UCS4                                                    //~v65cR~//~v6uBR~
//#ifdef TEST    //@@@@test                                                    //~v6C3I~//~v6V1R~//~v6VbR~//~v6VoR~
if (Pucs==0x0300||Pucs==0x23ce||Pucs==0x093f||Pucs==0xe000||Pucs==0x1161||Pucs==0x01d16d||Pucs==0x20001||Pucs==0xe0001)//@@@@test//~v6V2R~//~v6VbR~//~v6VoR~//~v6VtR~
{                                                                  //~v6VoI~
      UTRACEP("ucs=%04x\n",Pucs);                                  //~v6BCR~//~v6C3R~
}                                                                  //~v6VoI~
if (Pucs==0x01f880)                                                //~v6WkI~
{                                                                  //~v6WkI~
      UTRACEP("ucs=%04x\n",Pucs);                                  //~v6WkI~
}                                                                  //~v6WkI~
//#endif                                                             //~v6C3R~//~v6V1R~//~v6VbR~
	if (Pucs<0x80)      //ascii                                    //~v6WhI~
    {                                                              //~v6WhI~
		if (Ppflag)                                                //~v6WhI~
			*Ppflag=0;                                             //~v6WhI~
    	return 1;                                                  //~v6WhI~
    }                                                              //~v6WhI~
#ifdef UTF8UCS416                                                  //~v6uBI~
  if (Pucs>=UCS2DDMAP_ENTNO)	//no sbcs id tbl                   //~v65cR~
  {                                                                //~v65cI~
	utfddgetlenflag(Popt,Pucs,&len,&flag);                         //~v65cR~
  }                                                                //~v65cI~
  else                                                             //~v65cI~
#endif                                                             //~v65cI~
  {//!UCS4                                                         //~v65cR~
#ifdef UTF8UCS2                                                    //~v640I~
    if (!(Popt & UTFWWO_NOMAPUSE)     //no map use                 //~v640I~
    &&	 Gulibutfmode & GULIBSETUCS2MAP  //mapinit comp            //~v640I~
#ifdef UTF8UCS4                                                    //~v65cR~
//*UTF16 UCS4 is all >UCS2DDMAP_ENTNO**                            //~v6uBI~
#else                                                              //~v65cI~
    &&  Pucs<=UTF_UCS2MAX                                          //~v640I~
#endif                                                             //~v65cI~
    )                                                              //~v640I~
    {                                                              //~v640I~
#ifdef UTF8UCS4                                                    //~v65cI~
//*UTF16 UCS4 is all >UCS2DDMAP_ENTNO**                            //~v6uBI~
		utfddgetlenflag(Popt,Pucs,&len,Ppflag);                    //~v65cI~
#else                                                              //~v65cI~
		utfddgetlenflag(0,Pucs,&len,Ppflag);                       //~v640I~
#endif                                                             //~v65cI~
UTRACEP("utfwcwidth from map ucs=%04x,width=%d,flag=%x\n",Pucs,len,(Ppflag?*Ppflag:-1));   //better to return large value even displayed 1 cell on english terminal//~v640R~//~v6VnR~
        return len;                                                //~v640I~
    }                                                              //~v640I~
	opt=Popt;                                                      //~v640I~
	if (Popt & UTFWWO_UTF8UCS2)                                    //~v640I~
    {                                                              //~v640I~
#ifdef LNX                                                         //~v640I~
//      if (Gudbcschk_flag & UDBCSCHK_UTF8) //env is utf8;wcwidth is common to all locale//~v640R~
//  	    	opt|= UTFWWO_APILAST                               //~v640R~
//  	    	     |UTFWWO_NOMK                                  //~v640R~
//  	    	     |UTFWWO_NOMKCJK                               //~v640R~
//	    		     |UTFWWO_NOMKCJKU                              //~v640R~
// 	    	    	 |UTFWWO_NOJ                                   //~v640R~
//               ;                                                 //~v640R~
//        else                                                     //~v640I~
    #ifdef ARM                                                     //~v6a0M~
        opt|= UTFWWO_NOMK                                          //~v6a0R~
             |UTFWWO_NOCJKU                                        //~v6a0I~
             |UTFWWO_NOJ                                           //~v6a0I~
      		 |UTFWWO_APICHK                                        //~v6a0I~
      		 |UTFWWO_ADJSBCS //reduce sbcstbl                      //~v6c5R~
         ; //api(Java) only;skip utftbsrch_jeuc,utftbsrch_cjk and mk_wcwidth_cjk, use mk_wcwidth for nospacing but dbcs chk//~v6a0R~
    #else                                                          //~v6a0I~
      	opt|=UTFWWO_APICHK;                                        //~v640R~
    #endif                                                         //~v6a0I~
#else                                                              //~v640I~
      	opt|=UTFWWO_APICHK                                         //~v697I~
		;                                                          //~v640I~
#endif                                                             //~v640I~
    }                                                              //~v640I~
#ifdef LNX                                                         //~v640I~
	if (opt & UTFWWO_APIONLY)                                      //~v640I~
    {                                                              //~v640I~
//		wcw=wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v640I~//~v6a0R~
  		wcw=wcwidth((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~
UTRACEP("wcwidth only width=%d for ucs=%x\n",wcw,Pucs);   //better to return large value even displayed 1 cell on english terminal//~v640R~
        return wcw;                                                //~v640I~
    }                                                              //~v640I~
#endif                                                             //~v640I~
//#ifndef AAA //@@@@test                                           //~v6BCR~
//    if (Pucs>=0xe000 && Pucs<=0xf8ff || Pucs>=0xac00 && Pucs<=/*0xd7a3*//*0xba16=just*/0xba16)//~v6BCR~
//    {                                                            //~v6BCR~
//        len=1;                                                   //~v6BCR~
//        if (Ppflag)                                              //~v6BCR~
//            *Ppflag=0;                                           //~v6BCR~
//        return len;                                              //~v6BCR~
//    }                                                            //~v6BCR~
//    if (Pucs>=0xba16 && Pucs<=0xba24)                            //~v6BCR~
//    {                                                            //~v6BCR~
//        len=0;                                                   //~v6BCR~
//        if (Ppflag)                                              //~v6BCR~
//            *Ppflag=0;                                           //~v6BCR~
//        return len;                                              //~v6BCR~
//    }                                                            //~v6BCR~
//#endif     //@@@@test                                            //~v6BCR~
#ifdef TEST                                                        //~v6V1I~
    if (Pucs==0xa7||Pucs==0xb1||Pucs==0x0120||Pucs==0x0389||Pucs==0x0391||Pucs==0x2020||Pucs==0x2025||Pucs==0x2191||Pucs==0x2614||Pucs==0x2642||Pucs==0x2661||Pucs==0x2705)//~v6V1R~
    {                                                              //~v6V1I~
        UTRACEP("%s:trap ucs=%04x\n",UTT,Pucs);	//@@@@test         //~v6V1R~
    }                                                              //~v6V1I~
#endif                                                             //~v6V1I~
	rc=utfwcwidthsub(opt,Pucs);                                    //~v640R~
//UTRACEP("wcwidthsub rc=%d for ucs=%x\n",rc,Pucs);                //~v6a0R~//~v6uER~
#else                                                              //~v640I~
	rc=utfwcwidthsub(Pucs);                                        //~v62UR~
#endif                                                             //~v640I~
//  if (rc>0)                                                      //~v62UR~//~v650R~
    if (rc>=0 && Pucs>=0x80)   //chk unprintable also for combining char(rc=0)//~v650R~
    {                                                              //~v62UR~
		if (utf4_isFormat(0,(UWUCS)Pucs))                          //~v6WqI~
			rc|=UTFWWF_RC_FORMAT; //0x04000000                     //~v6WqI~
        len=rc & UTFWWF_LENMASK;                                   //~v62UR~
//      flag=rc & UTFWWF_FLAGMASK;                                 //~v62UR~//~v6BkR~
        flag=rc & (int)UTFWWF_FLAGMASK;                            //~v6BkI~
#ifdef UTF8UCS2                                                    //~v640I~
#ifdef LNX                                                         //~v640I~
		if (opt & UTFWWO_APICHK)                                   //~v640I~
        {                                                          //~v6c5I~
	#ifdef ARM                                                     //~v6c5R~
			len=utfwwapichk(UTFWWO_APIW0,Pucs,len,&flag,&wcw);  //len=0 if wcwidth()=0//~v6c5R~
	#else                                                          //~v6c5R~
  	   #ifdef UB1710	//test under ub17.10(kernel4.13.0)         //~v6V1I~
         if (rc & UTFWWF_RC_MK_WCWIDTH)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6V7I~
         {                                                         //~v6WiI~
          if (rc & UTFWWF_RC_FORMAT)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6WiI~
//			len=utfwwapichk(UTFWWO_MK_WCWIDTH|UTFWWO_FORMAT|(rc & UTFWWF_RC_MK_COMB? UTFWWO_MK_COMB:0),Pucs,len,&flag,&wcw);//~v6WiR~//~v6WmR~
  			len=utfwwapichk(UTFWWO_MK_WCWIDTH|UTFWWO_FORMAT,Pucs,len,&flag,&wcw);//~v6WmI~
          else                                                     //~v6WiI~
//			len=utfwwapichk(UTFWWO_MK_WCWIDTH,Pucs,len,&flag,&wcw);//~v6V7I~//~v6W9R~
// 			len=utfwwapichk(UTFWWO_MK_WCWIDTH|(rc & UTFWWF_RC_MK_COMB? UTFWWO_MK_COMB:0),Pucs,len,&flag,&wcw);//~v6W9R~//~v6WmR~
  			len=utfwwapichk(UTFWWO_MK_WCWIDTH,Pucs,len,&flag,&wcw);//~v6WmI~
         }                                                         //~v6WiI~
         else                                                      //~v6V7I~
          if (Gulibutfmode & GULIBUTFAPIWIDTH0) //     0x02000000  //accept wcwidth()=0 for not on utf4:combine tbl//~v6V1I~
			len=utfwwapichk(UTFWWO_APIW0,Pucs,len,&flag,&wcw);  //len=0 if wcwidth()=0//~v6V1I~
          else                                                     //~v6V1I~
			len=utfwwapichk(0,Pucs,len,&flag,&wcw);                //~v6V7M~
       #else                                                       //~v6VbI~
			len=utfwwapichk(0,Pucs,len,&flag,&wcw);                //~v640R~
       #endif                                                      //~v6V1I~//~v6VbM~
	#endif                                                         //~v6c5I~
        }                                                          //~v6c5I~
#else                                                              //~v697I~
		if (opt & UTFWWO_APICHK)                                   //~v697I~
			len=utfwwapichk(0,Pucs,len,&flag,0/*wcw*/);            //~v697I~
#endif                                                             //~v640I~
#endif                                                             //~v640I~
    }                                                              //~v62UR~
    else                                                           //~v62UR~
    {                                                              //~v62UR~
    	len=rc;                                                    //~v62UR~
        flag=0;                                                    //~v62UR~
    }                                                              //~v62UR~
  }//!UCS4                                                         //~v65cI~
    if (Ppflag)                                                    //~v62UR~
    	*Ppflag=flag;                                              //~v62UR~
UTRACEP("%s: return len=%d,flag=%x,ucs=%x\n",UTT,len,flag,Pucs);     //~v6a0R~//~v6uER~//~v6VnR~//~v6VrR~
    return len;                                                    //~v62UR~
}//utfwcwidth                                                      //~v6VbR~
#ifdef UTF8UTF16     //W32                                              //~v6uBI~//~v6V4I~
//*******************************************************          //~v6V4I~
//*return char width for Pucs>MAP_ENTRY from utfddgetlenflag       //~v6V4I~
//*******************************************************          //~v6V4I~
int utfwcwidthNoMap(int Popt,ULONG Pucs,int *Ppflag)               //~v6V4I~
{                                                                  //~v6V4I~
	int flag,rc,len;                                               //~v6V4I~
	int opt;                                                       //~v6V4I~
//****************                                                 //~v6V4I~
	opt=Popt;                                                      //~v6V4I~
	if (Popt & UTFWWO_UTF8UCS2)                                    //~v6V4I~
    {                                                              //~v6V4I~
      	opt|=UTFWWO_APICHK                                         //~v6V4I~
		;                                                          //~v6V4I~
    }                                                              //~v6V4I~
//#ifdef TEST                                                      //~v6V4I~
    if (Pucs==0xa7||Pucs==0xb1||Pucs==0x0120||Pucs==0x0389||Pucs==0x0391||Pucs==0x2020||Pucs==0x2025||Pucs==0x2191||Pucs==0x2614||Pucs==0x2642||Pucs==0x2661||Pucs==0x2705)//~v6V4I~
    {                                                              //~v6V4I~
        UTRACEP("%s:trap ucs=%04x\n",UTT,Pucs);	//@@@@test         //~v6V4I~
    }                                                              //~v6V4I~
    if (Pucs==0x0e0001)                                            //~v6WkI~
    {                                                              //~v6WkI~
        UTRACEP("%s:trap ucs=%04x\n",UTT,Pucs);	//@@@@test         //~v6WkI~
    }                                                              //~v6WkI~
//#endif                                                           //~v6V4I~
	rc=utfwcwidthsubNoMap(opt,Pucs);                               //~v6V4I~
UTRACEP("wcwidthsubNoMap rc=%d for ucs=%x\n",rc,Pucs);             //~v6V4I~
    if (rc>=0 && Pucs>=0x80)   //chk unprintable also for combining char(rc=0)//~v6V4I~
    {                                                              //~v6V4I~
        len=rc & UTFWWF_LENMASK;                                   //~v6V4I~
        flag=rc & (int)UTFWWF_FLAGMASK;                            //~v6V4I~
		if (opt & UTFWWO_APICHK)                                   //~v6V4I~
			len=utfwwapichkWucs4(0,Pucs,len,&flag,0/*wcw*/);       //~v6V4I~
    }                                                              //~v6V4I~
    else                                                           //~v6V4I~
    {                                                              //~v6V4I~
    	len=rc;                                                    //~v6V4I~
        flag=0;                                                    //~v6V4I~
    }                                                              //~v6V4I~
    if (Ppflag)                                                    //~v6V4I~
    	*Ppflag=flag;                                              //~v6V4I~
UTRACEP("%s:len=%d,flag=0x%x,ucs=0x%x\n",UTT,len,flag,Pucs);       //~v6V4I~
    return len;                                                    //~v6V4I~
}//utfwcwidthNoMap                                                 //~v6V4I~
#else                //LNX                                         //~v6V4I~
//*******************************************************          //~v6V4I~
//*return char width for Pucs>MAP_ENTRY                            //~v6V4I~
//*******************************************************          //~v6V4I~
int utfwcwidthNoMap(int Popt,ULONG Pucs,int *Ppflag)               //~v6V4I~
{                                                                  //~v6V4I~
	int flag,rc,len;                                               //~v6V4I~
	int wcw;                                                       //~v6V4I~
	int opt;                                                       //~v6V4I~
//****************                                                 //~v6V4I~
	opt=Popt;                                                      //~v6V4I~
	if (Popt & UTFWWO_UTF8UCS2)                                    //~v6V4I~
    {                                                              //~v6V4I~
    #ifdef ARM                                                     //~v6V4I~
        opt|= UTFWWO_NOMK                                          //~v6V4I~
             |UTFWWO_NOCJKU                                        //~v6V4I~
             |UTFWWO_NOJ                                           //~v6V4I~
      		 |UTFWWO_APICHK                                        //~v6V4I~
      		 |UTFWWO_ADJSBCS //reduce sbcstbl                      //~v6V4I~
         ; //api(Java) only;skip utftbsrch_jeuc,utftbsrch_cjk and mk_wcwidth_cjk, use mk_wcwidth for nospacing but dbcs chk//~v6V4I~
    #else                                                          //~v6V4I~
      	opt|=UTFWWO_APICHK;                                        //~v6V4I~
    #endif                                                         //~v6V4I~
    }                                                              //~v6V4I~
	rc=utfwcwidthsubNoMap(opt,Pucs);                               //~v6V4R~
UTRACEP("%s:wcwidthsubNoMap rc=%d for ucs=%x\n",UTT,rc,Pucs);      //~v6V4R~
    if (rc>=0 && Pucs>=0x80)   //chk unprintable also for combining char(rc=0)//~v6V4I~
    {                                                              //~v6V4I~
        len=rc & UTFWWF_LENMASK;                                   //~v6V4I~
        flag=rc & (int)UTFWWF_FLAGMASK;                            //~v6V4I~
		if (opt & UTFWWO_APICHK)                                   //~v6V4I~
        {                                                          //~v6V4I~
	#ifdef ARM                                                     //~v6V4I~
			len=utfwwapichk(UTFWWO_APIW0,Pucs,len,&flag,&wcw);  //len=0 if wcwidth()=0//~v6V4I~
	#else                                                          //~v6V4I~
         if (rc & UTFWWF_RC_MK_WCWIDTH)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6V7I~
         {                                                         //~v6WiI~
          if (rc & UTFWWF_RC_FORMAT)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6WiI~
			len=utfwwapichk(UTFWWO_MK_WCWIDTH|UTFWWO_FORMAT,Pucs,len,&flag,&wcw);//~v6WiI~
          else                                                     //~v6WiI~
			len=utfwwapichk(UTFWWO_MK_WCWIDTH,Pucs,len,&flag,&wcw);//~v6V7I~
         }                                                         //~v6WiI~
         else                                                      //~v6V7I~
          if (Gulibutfmode & GULIBUTFAPIWIDTH0) //     0x02000000  //accept wcwidth()=0 for not on utf4:combine tbl//~v6V4I~
			len=utfwwapichk(UTFWWO_APIW0,Pucs,len,&flag,&wcw);  //len=0 if wcwidth()=0//~v6V4I~
          else                                                     //~v6V4I~
			len=utfwwapichk(0,Pucs,len,&flag,&wcw);                //~v6V4I~
	#endif                                                         //~v6V4I~
        }                                                          //~v6V4I~
    }                                                              //~v6V4I~
    else                                                           //~v6V4I~
    {                                                              //~v6V4I~
    	len=rc;                                                    //~v6V4I~
        flag=0;                                                    //~v6V4I~
    }                                                              //~v6V4I~
    if (Ppflag)                                                    //~v6V4I~
    	*Ppflag=flag;                                              //~v6V4I~
//UTRACEP("utfwcwidth len=%d,flag=%x,ucs=%x\n",len,flag,Pucs);     //~v6V4I~
    return len;                                                    //~v6V4I~
}//utfwcwidthNoMap                                                 //~v6V4I~
#endif //LNX                                                       //~v6V4I~
//*******************************************************          //~v62UR~
//*utfwcwidthsub                                                   //~v640I~
//*******************************************************          //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
int utfwcwidthsub(int Popt,ULONG Pucs)                             //~v640I~
#else                                                              //~v640I~
int utfwcwidthsub(ULONG Pucs)                                      //~v62UR~
#endif                                                             //~v640I~
{                                                                  //~7724I~
#ifdef W32                                                         //~7920I~
#ifndef UTF8UCS2                                                   //~v643I~
    int sjis;                                                      //~7920I~
#endif                                                             //~v643I~
#endif                                                             //~7920I~
    int datatype;                                                  //~7925R~
#ifdef AAA //no validty chk require                                //~v62UR~
#ifdef UTF8SUPPH                                                   //~v620I~
	int width;                                                     //~v620I~
	UCHAR mbstr[MAX_MBCSLEN];                                      //~v620I~
#endif                                                             //~v620I~
#endif                                                             //~v62UR~
//*****************                                                //~7920I~
	if (Pucs<0x80)      //ascii                                    //~v62UR~
    	return 1;                                                  //~v62UR~
#ifdef AAA //no validty chk require                                //~v62UR~
#ifdef UTF8SUPPH                                                   //~v620I~
//	if (!utfcvu2lany1mb(0,(wchar_t)Pucs,mbstr,&width))             //~v620I~//~v6a0R~
  	if (!utfcvu2lany1mb(0,(UWCHART)Pucs,mbstr,&width))             //~v6a0I~
    {                                                              //~v620I~
    	if (width==1||width==2)                                    //~v620I~
        	return width;                                          //~v620I~
        return max(1,width);                                       //~v620I~
    }                                                              //~v620I~
#endif                                                             //~v620I~
#endif                                                             //~v62UR~
	datatype=utftbsrch(Pucs,Sutftb,Sutftbentno);                   //~7925R~
//UTRACEP("utfwcwidth initbsrch ucs=%x,datatype=%x\n",Pucs,datatype);                     //~7926I~//~v650R~
    if (datatype)                                                  //~7925R~
    	return (datatype & UCODETB_LENMASK);                       //~7925R~
#ifdef W32                                                         //~7920M~
//**************W32**************                                  //~v640I~
//*normal seq                                                      //~v640I~
//*          1  utftbsrch_j if UDBCSCHK_ISDBCS_J()   Suctbj/Suctbj_WXE  //~v6V2R~//~v6V4R~
//*          2  mk_wcwidth_cjk if console/wxe & UDBCSCHK_ISDBCS()  Sambiguous_non_langs, Sambiguous_langs, ambiguous//~v6V2R~//~v6V4R~
//*          3  mk_width                                 combining,dbcs chk logic//~v6V2R~
#ifdef AAA                                                         //~v62UR~
    if (UDBCSCHK_ISUTF8J())	//japanese                             //~7920I~
#else                                                              //~v62UR~
    if (UDBCSCHK_ISDBCSJ())	//japanese  sjis or jp.utf8            //~v62UR~
#endif                                                             //~v62UR~
    {                                                              //~7920I~
#ifdef UTF8UCS2                                                    //~v640I~
      if (!(Popt & UTFWWO_NOJ))                                    //~v640I~
#endif                                                             //~v640I~
      {                                                            //~v640I~
    	datatype=utftbsrch_j(Pucs);//chk before old sjis tbl(for new codepoint//~7925I~
//UTRACEP("utfwcwidth tbsrch_j wc=%4x,rc=%x\n",Pucs,datatype);     //~v650R~
	    if (datatype)                                              //~7925I~
//  		return (datatype & UCODETB_LENMASK);                   //~7925I~//~v6VoR~
    		return datatype;                                       //~v6VoR~
#ifndef UTF8UCS2                                                   //~v643I~
 		sjis=uccvucs2sjis(0,Pucs);//chk sjis tbl                   //~7925R~
//UTRACEP("utfwcwidth cvu2s sjis=%x\n",sjis);                      //~v650R~
		if (sjis!=UCVERRUCS)                                       //~7925R~
        {                                                          //~7925I~
			if (sjis>0xff)                                         //~7925R~
                return 2;	//dbcs                                 //~7925R~
            else                                                   //~7925R~
                return 1;   //sbcs(katakana)                       //~7925R~
        }                                                          //~7920I~
#endif                                                             //~v643I~
      }//NOJ                                                       //~v640I~
    }                                                              //~7920I~
    if (Sutftbopt & SUO_CJK)                                       //~v62UR~
    {                                                              //~v640I~
#ifdef UTF8UCS2	//for latin UTF8                                   //~v640I~
      if (!(Popt & UTFWWO_NOMKCJK))                                //~v640I~
#endif                                                             //~v640R~
#ifdef UTF8UCS2                                                    //~v647I~
//  	return mk_wcwidth_cjk((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v647R~//~v6BjR~
    	return mk_wcwidth_cjk((UWUCS)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6BjI~
#else                                                              //~v647I~
    	return mk_wcwidth_cjk((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v62UR~
#endif                                                             //~v647I~
    }                                                              //~v640I~
//  if (Sutftbopt & SUO_NATIVE)  //VCC6 has no API wcwidth         //~v62UR~
//  	return wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v62UR~
#ifdef AAA                                                         //~v62UR~
    if (UDBCSCHK_ISWCDBCS())	//DBCS lang other than japanese    //~v5mQR~
#else                                                              //~v62UR~
  #ifdef UTF8UCS2                                                  //~v640I~
  #else                                                            //~v640I~
    if (UDBCSCHK_ISDBCS())	//CJK(including JP)                    //~v62UR~
  #endif                                                           //~v640I~
#endif                                                             //~v62UR~
    {                                                              //~v5mQI~
#ifdef UTF8UCS2	//for latin UTF8                                   //~v640I~
      if (!(Popt & UTFWWO_NOMK))                                   //~v640I~
#endif                                                             //~v640R~
      {                                                            //~v640I~
#ifdef AAA                                                         //~v62UR~
  		if (Pucs>=0x80)    //confir by wcs2mb                      //~v5mQI~
//  		datatype=wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v5mQR~
//  		datatype=mk_wcwidth_cjk((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v5mQI~//~v6a0R~
    		datatype=mk_wcwidth_cjk((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~
    	else                                                       //~v5mQI~
    		datatype=1;                                            //~v5mQI~
#else                                                              //~v62UR~
//  	if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator    //~v62UR~//~v696R~
//      if (UDBCSCHK_ISDBCS()	//CJK(including JP)                //~v696I~//~vbmkR~
//  	&& Sutftbopt & SUO_CONSOLE 	//old terminal emulator        //~v696I~//~vbmkR~
        if                                                         //~vbmkI~
        (                                                          //~vbmkI~
           (UDBCSCHK_ISDBCS()	//CJK(including JP)                //~vbmkI~
    	    && Sutftbopt & SUO_CONSOLE 	//old terminal emulator    //~vbmkI~
           )                                                       //~vbmkI~
		   || (Gulibutfmode & GULIBUTF_CJK) //          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
        )                                                          //~v696I~
        {                                                          //~v6WpI~
#ifdef UTF8UCS2                                                    //~v647I~
//	    	datatype=mk_wcwidth_cjk((UWCHART)Pucs);   //traditional terminal char spacing//~v647R~//~v6BjR~
  	    	datatype=mk_wcwidth_cjk((UWUCS)Pucs);   //traditional terminal char spacing//~v6BjI~
#else                                                              //~v647I~
	    	datatype=mk_wcwidth_cjk((wchar_t)Pucs);   //traditional terminal char spacing//~v62UR~
#endif                                                             //~v647I~
			UTRACEP("%s:mk_wcwidth_cjk rc=%x,ucs=%06x\n",UTT,datatype,Pucs);//~v6WpR~
		}                                                          //~v6WpI~
        else                                                       //~v62UR~
        {                                                          //~v6WpI~
#ifdef UTF8UCS2                                                    //~v647I~
//      	datatype=mk_wcwidth((UWCHART)Pucs);   //for wxe/gxe    //~v647R~//~v6BjR~
//        	datatype=mk_wcwidth((UWUCS)Pucs);   //for wxe/gxe      //~v6BjI~//~v6WnR~
          	datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //for wxe/gxe//~v6WnI~
#else                                                              //~v647I~
	    	datatype=mk_wcwidth((wchar_t)Pucs);   //for wxe/gxe    //~v62UR~
#endif                                                             //~v647I~
			UTRACEP("%s:mk_wcwidth rc=%x,ucs=%06x\n",UTT,datatype,Pucs);//~v6WpI~
		}                                                          //~v6WpI~
#endif                                                             //~v62UR~
//UTRACEP("%s:after mk_wcwidth(_chk) ucs=%04x,datatype=%x,console=%x\n",UTT,Pucs,datatype,Sutftbopt & SUO_CONSOLE);   //I don't know other language//~v650R~//~v6uER~//~v6V9R~
		return datatype;                                           //~v5mQI~
      }//NOCJK                                                     //~v640I~
    }                                                              //~v5mQI~
//UTRACEP("Not CJK:utfwcwidth %04x,mk_wcwidth =%d\n",Pucs,mk_wcwidth((UWCHART)Pucs));   //I don't know other language//~v62UR~//~v650R~
#ifdef UTF8UCS2                                                    //~v647I~
//  return mk_wcwidth((UWCHART)Pucs);   //I don't know other language//~v647R~//~v6BjR~
//  return mk_wcwidth((UWUCS)Pucs);   //I don't know other language//~v6BjI~//~v6WnR~
    return mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //I don't know other language//~v6WnI~
#else                                                              //~v647I~
    return mk_wcwidth((wchar_t)Pucs);   //I don't know other language//~7925R~
#endif                                                             //~v647I~
#else //LNX                                                        //~7924R~
//**************LNX**************                                  //~v640I~
//*normal seq                                                      //~v640I~
//*          1  utftbsrch_jeuc if UDBCSCHK_ISDBCS_J()         Suctbj_euc_console/Suctbj_euc//~v6V2R~//~v6V9R~
//*          2  utftbsrch_cjk if UDBCSCHK_ISDBCS()           Suctb_utf8/Suctb_utf8_XXE,Suctb_cjk_console/Suctb_cjk//~v6V2R~//~v6V9R~
//*          3  mk_width_cjk if Console & UDBCSCHK_ISDBCS()  ambiguous(+lamg+lang_ucs4);ambiguous is adjusted by wcwidth()=0//~v6V2R~//~v6V9R~//~v6VbR~
//*          4  mk_width if !NOMK                            combining,dbcs chk;adjused by wcwidth()//~v6V2I~//~v6V9R~
//*          5  wcwidth if APILAST or mk_width               APILAST   y//~v640I~//~v6V2R~
//* ARM      mk_wcwidth_adjsbcs only                         Sdbcstb,dbcs chk//~v6V9I~
//#ifdef BBB                                                         //~v62UR~//~v640R~
#ifdef AAA                                                         //~v62UR~
    if (Gulibutfmode & GULIBUTFFROMEUC)	//base is eucJP            //~v60mR~
#else                                                              //~v62UR~
    if (UDBCSCHK_ISDBCSJ())	//japanese EUC or EUC.utf8             //~v62UR~
#endif                                                             //~v62UR~
    {                                                              //~v60mI~
#ifdef UTF8UCS2                                                    //~v640I~
      if (!(Popt & UTFWWO_NOJ))                                    //~v640I~
#endif                                                             //~v640I~
       if (!(Sutftbopt & SUO_NOEUCTB))//no chk euc tbl             //~v60qR~
       {                                                           //~v60mI~
    	datatype=utftbsrch_jeuc(Pucs);//chk before old sjis tbl(for new codepoint//~v60mI~
//UTRACEP("%s:tbsrch_jeuc wc=%4x,rc=%x\n",UTT,Pucs,datatype);  //~v650R~//~v6uER~
	    if (datatype)                                              //~v60mI~
    		return (datatype & UCODETB_LENMASK);                   //~v60mI~
       }                                                           //~v60mI~
    }                                                              //~v60mI~
//#endif                                                             //~v62UR~//~v640R~
    if (Sutftbopt & SUO_CJK)                                       //~7929R~
    {                                                              //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
      if (!(Popt & UTFWWO_NOMKCJK))                                //~v640I~
#endif                                                             //~v640I~
//     	return mk_wcwidth_cjk((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~7925R~//~v6a0R~
//   	return mk_wcwidth_cjk((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~//~v6BjR~
     	return mk_wcwidth_cjk((UWUCS)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6BjI~
    }                                                              //~v640I~
    if (Sutftbopt & SUO_NATIVE)                                    //~7929R~
//    	return wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~7925R~//~v6a0R~
      	return wcwidth((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~
    if (UDBCSCHK_ISDBCS())	//CJK(including JP)                    //~v62UR~
    {                                                              //~v62UR~
#ifdef UTF8UCS2	//for latin UTF8                                   //~v640I~
      if (!(Popt & UTFWWO_NOCJKU))	//adjust tbl by test           //~v640I~
#endif                                                             //~v640I~
      {                                                            //~v640I~
    	datatype=utftbsrch_cjk(Pucs);//ajust by test               //~v62UR~
	    if (datatype)                                              //~v62UR~
//    		return (datatype & UCODETB_LENMASK);                   //~v62UR~
      		return datatype;	//return font width option         //~v62UR~
      }                                                            //~v640I~
#ifdef UTF8UCS2	//for latin UTF8                                   //~v640I~
      if (!(Popt & UTFWWO_NOMK))                                   //~v640I~
#endif                                                             //~v640I~
      {                                                            //~v640I~
//		if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator    //~v62UR~//~vbmkR~
  		if                                                         //~vbmkI~
        (                                                          //~vbmkI~
  		   (Sutftbopt & SUO_CONSOLE)	//old terminal emulator    //~vbmkI~
		|| (Gulibutfmode & GULIBUTF_CJK) //          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
        )                                                          //~vbmkI~
//      	datatype=mk_wcwidth_cjk((wchar_t)Pucs);   //traditional terminal char spacing//~v62UR~//~v6a0R~
//        	datatype=mk_wcwidth_cjk((UWCHART)Pucs);   //traditional terminal char spacing//~v6a0I~//~v6BjR~
          	datatype=mk_wcwidth_cjk((UWUCS)Pucs);   //traditional terminal char spacing//~v6BjI~
        else                                                       //~v62UR~
//      	datatype=mk_wcwidth((wchar_t)Pucs);   //for wxe/gxe    //~v62UR~//~v6a0R~
//        	datatype=mk_wcwidth((UWCHART)Pucs);   //for wxe/gxe    //~v6a0I~//~v6BjR~
//#ifdef TEST                                                      //~v6V1R~
//        	datatype=mk_wcwidth((UWUCS)Pucs);   //for wxe/gxe      //~v6BjI~//~v6WnR~
          	datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //for wxe/gxe//~v6WnI~
//#else                                                            //~v6V1R~
//            datatype=mk_wcwidth_cjk((UWUCS)Pucs);   //@@@@test   //~v6V1R~
//#endif                                                           //~v6V1R~
UTRACEP("%s:ucs=%x,datatype=%x,console=%x\n",UTT,Pucs,datatype,Sutftbopt & SUO_CONSOLE);   //I don't know other language//~v640R~//~v6hHR~//~v6uER~//~v6V9R~
		return datatype;                                           //~v62UR~
      }//NOCJK                                                     //~v640I~
    }                                                              //~v62UR~
#ifdef AAA                                                         //~v62UR~
  #ifdef XXE   //curses use wcwidth                                //~v60mI~
  	if ((Gulibutfmode & GULIBUTFCHKBYCVL)                          //~v60fR~
    &&  !(Sutftbopt & SUO_NOLOCALEW)                               //~v60fR~
       )                                                           //~v60fI~
  #else                                                            //~v60mI~
    if (!(Sutftbopt & SUO_NOLOCALEW))                              //~v60mI~
  #endif                                                           //~v60mI~
    {                                                              //~v60fI~
  		if (Pucs>=0x80)    //confir by wcs2mb                      //~v60fI~
//  		return wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v60fI~//~v6a0R~
    		return wcwidth((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~
    	else                                                       //~v60fI~
    		return 1;                                              //~v60fI~
    }                                                              //~v60fI~
#endif                                                             //~v62UR~
#ifdef UTF8UCS2	//for latin UTF8                                   //~v640I~
    if (Popt & UTFWWO_APILAST)                                     //~v640R~
//      return wcwidth((wchar_t)Pucs);                             //~v640R~//~v6a0R~
        return wcwidth((UWCHART)Pucs);                             //~v6a0I~
    else                                                           //~v6c5I~
    if (Popt & UTFWWO_ADJSBCS)	//for ARM                          //~v6c5R~
    {                                                              //~v6c5I~
//      return mk_wcwidth_adjsbcs((wchar_t)Pucs);  //adjust to reduce sbcs tbl//~v6c5R~//~v6BjR~
        return mk_wcwidth_adjsbcs((UWUCS)Pucs);  //adjust to reduce sbcs tbl//~v6BjI~
    }                                                              //~v6c5I~
#endif                                                             //~v640I~
//    UTRACEP("%s:call return by mk_wcwidth ucs=%x\n",UTT,Pucs);   //~v6uER~
//  return mk_wcwidth((wchar_t)Pucs);                              //~7924R~//~v6BjR~
//  return mk_wcwidth((UWUCS)Pucs);                                //~v6BjI~//~v6WnR~
    return mk_wcwidth(Sutftbopt,(UWUCS)Pucs);                      //~v6WnI~
#endif                                                             //~7920I~
}//utfwcwidthsub                                                   //~7724I~//~v650R~
#ifdef UTF8UTF16     //W32                                         //~v6V4I~
//*******************************************************          //~v6V4I~
//*utfwcwidthsubNoMap (for ucs4)                                   //~v6V4I~
//*******************************************************          //~v6V4I~
int utfwcwidthsubNoMap(int Popt,ULONG Pucs)                        //~v6V4I~
{                                                                  //~v6V4I~
    int datatype;                                                  //~v6V4I~
//*****************                                                //~v6V4I~
	datatype=utftbsrch(Pucs,Sutftb,Sutftbentno);                   //~v6V4I~
	UTRACEP("%s:utfwcwidth initbsrch ucs=%x,datatype=%x\n",UTT,Pucs,datatype);//~v6V4I~
    if (datatype)                                                  //~v6V4I~
    	return (datatype & UCODETB_LENMASK);                       //~v6V4I~
//**************W32**************                                  //~v6V4I~
//*normal seq                                                      //~v6V4I~
//*          1  utftbsrch_j if UDBCSCHK_ISDBCS_J()             Suctbj//~v6V4I~
//*          2  mk_wcwidth_cjk if console & UDBCSCHK_ISDBCS()  Sambiguous_non_langs, Sambiguous_langs, ambiguous//~v6V4I~
//*          3  mk_width                                 combining,dbcs chk logic//~v6V4I~
    if (UDBCSCHK_ISDBCSJ())	//japanese  sjis or jp.utf8            //~v6V4I~
    {                                                              //~v6V4I~
      	if (!(Popt & UTFWWO_NOJ))                                  //~v6V4I~
      	{                                                          //~v6V4I~
    		datatype=utftbsrch_j(Pucs);//chk before old sjis tbl(for new codepoint//~v6V4I~
			UTRACEP("%s:utfwcwidth tbsrch_j wc=%4x,rc=%x\n",UTT,Pucs,datatype);//~v6V4I~
	    	if (datatype)                                          //~v6V4I~
//  			return (datatype & UCODETB_LENMASK);               //~v6V4I~//~v6VoR~
    			return datatype;                                   //~v6VoI~
      	}//NOJ                                                     //~v6V4I~
    }                                                              //~v6V4I~
    if (Sutftbopt & SUO_CJK)                                       //~v6V4I~
    {                                                              //~v6V4I~
      	if (!(Popt & UTFWWO_NOMKCJK))                              //~v6V4I~
    		return mk_wcwidth_cjk((UWUCS)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6V4I~
    }                                                              //~v6V4I~
    if (!(Popt & UTFWWO_NOMK))                                     //~v6V4I~
    {                                                              //~v6V4I~
//      if (UDBCSCHK_ISDBCS()	//CJK(including JP)                //~v6V4I~//~vbmkR~
//  	&& Sutftbopt & SUO_CONSOLE 	//old terminal emulator        //~v6V4I~//~vbmkR~
        if                                                         //~vbmkI~
        (                                                          //~vbmkI~
           (UDBCSCHK_ISDBCS()	//CJK(including JP)                //~vbmkI~
    	    && Sutftbopt & SUO_CONSOLE) 	//old terminal emulator//~vbmkI~
		|| (Gulibutfmode & GULIBUTF_CJK) //          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
        )                                                          //~v6V4I~
  	    	datatype=mk_wcwidth_cjk((UWUCS)Pucs);   //traditional terminal char spacing//~v6V4I~
        else                                                       //~v6V4I~
//        	datatype=mk_wcwidth((UWUCS)Pucs);   //for wxe/gxe      //~v6V4I~//~v6WnR~
          	datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //for wxe/gxe//~v6WnI~
UTRACEP("%s:after mk_wcwidth(_chk) ucs=%06x,datatype=0x%x,console=%x\n",UTT,Pucs,datatype,Sutftbopt & SUO_CONSOLE);   //I don't know other language//~v6V4I~
		return datatype;                                           //~v6V4I~
    }                                                              //~v6V4I~
//  datatype=mk_wcwidth((UWUCS)Pucs);   //I don't know other language//~v6V4I~//~v6WnR~
    datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //I don't know other language//~v6WnI~
	UTRACEP("%s:last mk_wcwidth ucs=%06x,datatype=0x%x\n",UTT,Pucs,datatype);   //I don't know other language//~v6V4I~
    return datatype;                                               //~v6V4I~
}//utfwcwidthsubNoMap //W32                                        //~v6V4I~
#else                //LNX                                         //~v6V4I~
//*******************************************************          //~v6V4I~
//*utfwcwidthsub for ucs>map entry                                 //~v6V4I~
//*return datatype                                                 //~v6V4I~
//*******************************************************          //~v6V4I~
int utfwcwidthsubNoMap(int Popt,ULONG Pucs)                        //~v6V4I~
{                                                                  //~v6V4I~
    int datatype;                                                  //~v6V4I~
//*****************                                                //~v6V4I~
	UTRACEP("%s:ucs=%06x\n",UTT,Pucs);                             //~v6V4I~
	datatype=utftbsrch(Pucs,Sutftb,Sutftbentno);                   //~v6V4I~
    if (datatype)                                                  //~v6V4I~
    	return (datatype & UCODETB_LENMASK);                       //~v6V4I~
    if (UDBCSCHK_ISDBCSJ())	//japanese EUC or EUC.utf8             //~v6V4I~
    {                                                              //~v6V4I~
      if (!(Popt & UTFWWO_NOJ))                                    //~v6V4I~
       if (!(Sutftbopt & SUO_NOEUCTB))//no chk euc tbl             //~v6V4I~
       {                                                           //~v6V4I~
    	datatype=utftbsrch_jeuc(Pucs);//chk before old sjis tbl(Suctbj_euc/Suctbj_euc_console)//~v6V4R~
	    if (datatype)                                              //~v6V4I~
    		return (datatype & UCODETB_LENMASK);                   //~v6V4I~
       }                                                           //~v6V4I~
    }                                                              //~v6V4I~
    if (Sutftbopt & SUO_CJK)                                       //~v6V4I~
    {                                                              //~v6V4I~
      if (!(Popt & UTFWWO_NOMKCJK))                                //~v6V4I~
     	return mk_wcwidth_cjk((UWUCS)Pucs);   //Sambiguous_langs/Sambiguous_langs_ucs4/ambiguous//~v6V4R~
    }                                                              //~v6V4I~
    if (Sutftbopt & SUO_NATIVE)                                    //~v6V4I~
      	return wcwidth((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6V4I~
    if (UDBCSCHK_ISDBCS())	//CJK(including JP)                    //~v6V4I~
    {                                                              //~v6V4I~
      if (!(Popt & UTFWWO_NOCJKU))	//adjust tbl by test           //~v6V4I~
      {                                                            //~v6V4I~
    	datatype=utftbsrch_cjk(Pucs);//Suctb_utf8/Suctb_utf8_XXE+Suctb_cjk_console/Suctb_cjk//~v6V4R~
	    if (datatype)                                              //~v6V4I~
      		return datatype;	//return font width option         //~v6V4I~
      }                                                            //~v6V4I~
      if (!(Popt & UTFWWO_NOMK))                                   //~v6V4I~
      {                                                            //~v6V4I~
//  	if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator    //~v6V4I~//~vbmkR~
    	if                                                         //~vbmkI~
        (                                                          //~vbmkI~
    	   (Sutftbopt & SUO_CONSOLE)	//old terminal emulator    //~vbmkI~
		|| (Gulibutfmode & GULIBUTF_CJK) //          0x04000000  //force mk_wcwidth_cjk//~vbmkI~
        )                                                          //~vbmkI~
          	datatype=mk_wcwidth_cjk((UWUCS)Pucs);  //Sambiguous_langs/Sambiguous_langs_ucs4/ambiguous+mk_wcwidth()//~v6V4R~
        else                                                       //~v6V4I~
//        	datatype=mk_wcwidth((UWUCS)Pucs);   //combining+dbcs logic//~v6V4R~//~v6WnR~
          	datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);   //combining+dbcs logic//~v6WnI~
UTRACEP("%s:ucs=%x,datatype=%0x,console=%x\n",UTT,Pucs,datatype,Sutftbopt & SUO_CONSOLE);   //I don't know other language//~v6V4I~//~v6V9R~
		return datatype;                                           //~v6V4I~
      }//NOCJK                                                     //~v6V4I~
    }                                                              //~v6V4I~
    if (Popt & UTFWWO_APILAST)                                     //~v6V4I~
        return wcwidth((UWCHART)Pucs);                             //~v6V4I~
    else                                                           //~v6V4I~
    if (Popt & UTFWWO_ADJSBCS)	//for ARM                          //~v6V4I~
    {                                                              //~v6V4I~
        return mk_wcwidth_adjsbcs((UWUCS)Pucs);  //adjust to reduce sbcs tbl//~v6V4I~
    }                                                              //~v6V4I~
//  return mk_wcwidth((UWUCS)Pucs);                                //~v6V4I~//~v6WnR~
    return mk_wcwidth(Sutftbopt,(UWUCS)Pucs);                      //~v6WnI~
}//utfwcwidthsubNoMap                                              //~v6V4I~
#endif //LNX                                                       //~v6V4I~
//*******************************************************          //~7724I~
//*chk ucs is wide char                                            //~7724I~
//*  valid sjis chk if japanese mode                               //~7724I~
//*******************************************************          //~7724I~
int utfiswide(int Popt,ULONG Pucs)                                 //~7724I~
{                                                                  //~7724I~
//  return (utfwcwidth(Pucs) & 0x02);	//!!! wcwidth requires "setlocal" call before//~v62UR~
    return (utfwcwidth(0,Pucs,0/*font flag*/) & 0x02);	//!!! wcwidth requires "setlocal" call before//~v62UR~
}//utfiswide                                                       //~7724I~
//*******************************************************          //~7817I~
//*chk ucs is printable                                            //~7817I~
//*  valid sjis chk if japanese mode                               //~7817I~
//*******************************************************          //~7817I~
int utfisprint(int Popt,ULONG Pucs)                                //~7817I~
{                                                                  //~7817I~
    int rc,chartype;                                               //~7922R~
#ifdef LNX                                                         //~v60fI~
    char wkmbs[8];                                                 //~v60fI~
#endif                                                             //~v60fI~
#ifdef UTF8SUPPH                                                   //~v620I~
	int width;                                                     //~v620I~
	UCHAR mbstr[MAX_MBCSLEN];                                      //~v620I~
#endif                                                             //~v620I~
//*************************                                        //~7921I~
#ifdef UTF8SUPPH                                                   //~v620I~
    if (Pucs<0x0100) //sbcs                                        //~v62GI~
    {                                                              //~v62GI~
   		if (Gudbcschk_flag & UDBCSCHK_UNPTBL)//   0x040000  //SBCS unprintable table was set//~v62GI~
        	return (Gpdbcstbl[Pucs] & UDBCSCHK_TYPEUNP)==0;        //~v62GR~
//      return iswprint((WUCS)Pucs);                               //~v62GR~//~v6BkR~
        return iswprint((wint_t)Pucs);                             //~v6BkR~
    }                                                              //~v62GI~
#ifdef UTF8UCS2                                                    //~v647I~
//	if (!utfcvu2lany1mb(0,(UWCHART)Pucs,mbstr,&width))             //~v647R~//~v6BjR~
  	if (!utfcvu2lany1mb(0,(UWUCS)Pucs,mbstr,&width))               //~v6BjI~
#else                                                              //~v647I~
	if (!utfcvu2lany1mb(0,(wchar_t)Pucs,mbstr,&width))             //~v620R~
#endif                                                             //~v647I~
    {                                                              //~v620I~
#ifdef AAA                                                         //~v62UR~
    	if (width==1||width==2)                                    //~v620I~
        	return 1;                                              //~v620I~
        return 0;                                                  //~v620I~
#else                                                              //~v62UR~
        return (width>0);    //width is dbcs byte                  //~v62UR~
#endif                                                             //~v62UR~
    }                                                              //~v620I~
#endif                                                             //~v620I~
	chartype=utftbsrch(Pucs,Sutftb,Sutftbentno);                   //~7925R~
//UTRACEP("utfisprint initbsrch ucs=%x,rc=%x\n",Pucs,chartype);                     //~7926I~//~v650R~
                                                                   //~7926I~
	if (chartype & UCODETB_UNPF) //unprintable entry               //~7925R~
    	return 0;		//user defined unprintable                 //~7922I~
	if (chartype)                                                  //~7922I~
    	return 1;		//user defined unprintable                 //~7922I~
#ifdef W32                                                         //~7925M~
    if (UDBCSCHK_ISUTF8J())	//japanese                             //~7817I~
    {                                                              //~7925I~
    	chartype=utftbsrch_j(Pucs);//chk before old sjis tbl(for new codepoint//~7925I~
UTRACEP("utfisprint tbsrch_j rc=%x\n",chartype);                   //~7926I~
		if (chartype & UCODETB_UNPF) //unprintable entry           //~7925I~
    		return 0;		//user defined unprintable             //~7925I~
		if (chartype)                                              //~7925I~
    		return 1;		//user defined unprintable             //~7925I~
UTRACEP("utfisprint cvu2s rc=%x\n",uccvucs2sjis(0,Pucs));	//limit to sjis to avoid print line shrink when horizontal hex display//~7926I~
    	if (uccvucs2sjis(0,Pucs)!=UCVERRUCS)	//limit to sjis to avoid print line shrink when horizontal hex display//~7925R~
        	return 1;                                              //~7920I~
    }                                                              //~7925I~
    rc=Pucs<' '      //ctl char can be controled by ini file       //~7922I~
#ifdef UTF8UCS2                                                    //~v647I~
//     || iswprint((UWCHART)Pucs); //wider range than wcstombs     //~v647R~//~v6BCR~
       || ISWPRINT(Pucs); //wider range than wcstombs,ucs4 is unprintable//~v6BCR~
#else                                                              //~v647I~
       || iswprint((wchar_t)Pucs); //wider range than wcstombs     //~7922R~
#endif                                                             //~v647I~
UTRACEP("utfisprint iswprint rc=%x\n",rc);	//limit to sjis to avoid print line shrink when horizontal hex display//~7926I~
#else   //LNX                                                      //~7924R~
//for 200b(ZWNJ:ctl char to ctl drawing),1 by iswprint,0 by g_unichar_isprint//~7921I~
//	rc=g_unichar_isprint((gunichar)Pucs);                          //~7921R~
	UTRACEP("utftbopt =%x \n",Sutftbopt);                          //~v60fI~
#ifdef AAA                                                         //~v640I~
    if (Gulibutfmode & GULIBUTFFROMEUC)	//base is eucJP            //~v60mI~
#else                                                              //~v640I~
    if (UDBCSCHK_ISDBCSJ())	//japanese EUC or EUC.utf8             //~v640I~
#endif                                                             //~v640I~
    {                                                              //~v60mI~
       if (!(Sutftbopt & SUO_NOEUCTB))//no chk euc tbl             //~v60qR~
       {                                                           //~v60mI~
    	chartype=utftbsrch_jeuc(Pucs);//chk before old sjis tbl(for new codepoint//~v60mR~
//UTRACEP("utfwcwidth tbsrch_jeuc wc=%4x,rc=%x\n",Pucs,chartype);  //~v650R~
		if (chartype & UCODETB_UNPF) //unprintable entry           //~v60mI~
    		return 0;		//user defined unprintable             //~v60mI~
		if (chartype)                                              //~v60mI~
    		return 1;		//user defined unprintable             //~v60mI~
       }                                                           //~v60mI~
    }                                                              //~v60mI~
#ifdef XXE                                                         //~v60mI~
  if ((Gulibutfmode & GULIBUTFCHKBYCVL)                            //~v60fI~
  &&  !(Sutftbopt & SUO_NOLOCALEP)                                 //~v60fR~
     )                                                             //~v60fR~
#else                                                              //~v60mI~
  if (!(Sutftbopt & SUO_NOLOCALEP))                                //~v60mI~
#endif                                                             //~v60mI~
  {                                                                //~v60fI~
  	if (Pucs>=0x080)                                               //~v60fR~
    {                                                              //~v60fI~
//      rc=(int)wcrtomb(wkmbs,(wchar_t)Pucs,NULL);  //rc=mbs length//~v60mI~//~v6a0R~
        rc=(int)wcrtomb(wkmbs,(UWCHART)Pucs,NULL);  //rc=mbs length//~v6a0I~
        UTRACEP("utfisprint by locale rc=%d ucs=%04x\n",rc,Pucs);  //~v60fR~
        rc=rc>0;                                                   //~v60fR~
    }                                                              //~v60fI~
    else                                                           //~v60fI~
    	rc=1;		//allow control char (0x00-0x1f)               //~v60fI~
  }                                                                //~v60fI~
  else                                                             //~v60fI~
//  rc=iswprint((wchar_t)Pucs)!=0;                                 //~7921I~//~v6a0R~
//  rc=iswprint((UWCHART)Pucs)!=0;                                 //~v6a0I~//~v6BkR~
    rc=iswprint((wint_t)Pucs)!=0;                                  //~v6BkR~
#endif                                                             //~7921M~
	UTRACEP("utfisprint rc=%d ucs=%04x\n",rc,Pucs);                //~v60qR~
    return rc;                                                     //~7921I~
}//utfisprint                                                      //~7817I~
//*******************************************************          //~7712I~
//*get ucs from utf8                                               //~7712I~
//*(accept ucs4 when LNX/W32)                                      //~v6uEI~
//*******************************************************          //~7712I~
int utfgetwc(UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Pchklen)      //~7712I~
{                                                                  //~7712I~
	int rc=0,readlen/*,len*/;                                          //~7805R~//~v6b9R~
//  int len;                                                       //~v6b9R~
//  ULONG wc;                                                      //~7712I~//~v691R~
    UWUCS wc;                                                      //~v691I~
#ifdef UTF8UCS2                                                    //~v647I~
    int opt;                                                       //~v647I~
#endif                                                             //~v647I~
//**************************************                           //~7712I~
#ifdef UTF8UCS2                                                    //~v647I~
	opt=0;                                                         //~v647M~
#ifdef W32                                                         //~v647I~
#else                                                              //~v647I~
//  opt=UCVUCS_UCS4;                                               //~v647R~
#endif                                                             //~v647I~
    if_UTF8UCS4                                                    //~v65cI~
    (                                                              //~v65cI~
//* no UCS4 option required when UTF8UTF16                         //~v6uBI~
    	opt=UCVUCS_UCS4;                                           //~v65cI~
    )                                                              //~v65cI~
#ifdef UTF8UTF16                                                   //~v6uEI~
    opt=UCVUCS_UCS4;                                               //~v6uEI~
#endif                                                             //~v6uEI~
//	if (uccvutf2ucs(opt,Pdata,Plen,&wc,&readlen)	//utf8->ucs2/ucs4//~v647I~//~v6BkR~
  	if (uccvutf2ucs((ULONG)opt,Pdata,Plen,&wc,&readlen)	//utf8->ucs2/ucs4//~v6BkI~
#else                                                              //~v647I~
	if (uccvutf2ucs(UCVUCS_UCS4,Pdata,Plen,&wc,&readlen)	//utf8->ucs2/ucs4//~7712I~
#endif                                                             //~v647I~
    ||  readlen>UTF8_MAXCHARSZ)                                    //~7712I~
    {                                                              //~7712I~
    	rc=4;                                                      //~7712M~
//  	len=UTF8CHARLEN(*Pdata);                                   //~7712R~//~v6b9R~
//    	UTRACEP("utfmb2wc rc=%d wc=%x,len by top char=%d,readlen=%d,parmlen=%d\n",rc,wc,len,readlen,Plen);//~7712I~//~v6a0R~
      	UTRACED("utfmb2wc data",Pdata,min(Plen,UTF8_MAXCHARSZ));   //~v6a0R~
    }                                                              //~7712I~
    *Pchklen=readlen;                                              //~7712I~
//  *Ppucs=wc;                                                     //~7712I~//~v6BkR~
    *Ppucs=(ULONG)wc;                                              //~v6BkI~
	return rc;                                                     //~7712I~
}//utfgetwc                                                        //~v640R~
//*******************************************************          //~7922I~
//*setup user specification SBCS/DBCS/Unprintable table            //~7922I~
//*line fmt   "type 0xaaaa-0xbbbb                                  //~7922I~
//*******************************************************          //~7922I~
int utftbinit(char *Ppfnm)                                         //~7922I~
{                                                                  //~7922I~
	FILE *fh;                                                      //~7922I~
    char buff[512],*pc;                                            //~7925R~
    int ucs1,ucs2,ucso=-1,entno,rc,len,datatype,utftbopt=0;        //~7929R~
    PUCODETB ptb,ptb0;                                             //~7925R~
//**************************************                           //~7922I~
	if (!(fh=fopen(Ppfnm,"r")))                                    //~7922I~
    {                                                              //~7922I~
    	ufileapierr("open(unicode file by inifile)",Ppfnm,errno);  //~7922R~
        return 4;                                                  //~7922I~
	}                                                              //~7922I~
//count data                                                       //~7922I~
    for (entno=0,rc=0;;)                                           //~7922I~
    {                                                              //~7922I~
		if (!fgets(buff,sizeof(buff),fh))                          //~7922I~
        	break;                                                 //~7922I~
        pc=buff;                                                   //~7922I~
//      len=strlen(pc);                                            //~7922I~//~v6BkR~
        len=(int)strlen(pc);                                       //~v6BkI~
        if (len<=1)                                                //~7922I~
        	continue;                                              //~7922I~
        if (*(pc+len-1)=='\n')                                     //~7922I~
        	*(pc+len-1)=0;                                         //~7922I~
        pc+=strspn(pc," ");                                        //~7922I~
        if (*pc==UCODETB_CMT)                                      //~7925R~
        	continue;	//comment                                  //~7922I~
        if (*pc==UCODETB_OPTION)                                   //~7925I~
        {                                                          //~7929I~
            pc++;                                                  //~7929I~
    	    pc+=strspn(pc," ");                                    //~7929I~
            sscanf(pc,"%x",&utftbopt);                             //~7929R~
        	continue;	//comment                                  //~7929I~
        }                                                          //~7929I~
        if (!(*pc==UCODETB_COMP                                    //~7925R~
            ||*pc==UCODETB_SBCS                                    //~7925I~
            ||*pc==UCODETB_DBCS                                    //~7925R~
            ||*pc==UCODETB_UNP                                     //~7925I~
           ))                                                      //~7924I~
        {                                                          //~7922I~
        	uerrmsg("unicode specification datatype err(not 0/1/2) at \"%s\"",0,//~7922R~
						buff);                                     //~7922R~
            rc=4;                                                  //~7922I~
            break;                                                 //~7922I~
        }                                                          //~7922I~
        pc++;                                                      //~7925I~
        pc+=strspn(pc," ");                                        //~7925R~
    	if (sscanf(pc,"%X-%X",&ucs1,&ucs2)!=2)                     //~7922R~
        {                                                          //~7922I~
        	uerrmsg("fmt err at \"%s\"",0,                         //~7922R~
					buff);                                         //~7922I~
			utftbfhelp();                                          //~7922I~
            rc=4;                                                  //~7922I~
            break;                                                 //~7922I~
        }                                                          //~7922I~
        if (ucs1<=ucso||ucs1>ucs2)                                 //~7922I~
        {                                                          //~7922I~
        	uerrmsg("unicode specification sequence down at \"%s\"",0,//~7922R~
					buff);                                         //~7922R~
            rc=4;                                                  //~7922I~
            break;                                                 //~7922I~
        }                                                          //~7922I~
        ucso=ucs2;                                                 //~7922I~
        entno++;                                                   //~7922I~
    }                                                              //~7922I~
    fclose(fh);                                                    //~7922I~
    if (rc)                                                        //~7922I~
    	return rc;                                                 //~7922I~
    Sutftbopt=utftbopt;                                            //~7929I~
    if (!entno)                                                    //~7922I~
    {                                                              //~7922I~
//        if (!utftbopt)                                           //~v60mR~
//            uerrmsg("unicode specification file %s has no data",0,//~v60mR~
//                    Ppfnm);                                      //~v60mR~
        return 0;                                                  //~7922I~
    }                                                              //~7922I~
//  ptb0=(PUCODETB)malloc(sizeof(UCODETB)*entno);                  //~7925R~//~v6BkR~
    ptb0=(PUCODETB)malloc(sizeof(UCODETB)*(size_t)entno);          //~v6BkI~
    if (!ptb0)                                                     //~7922R~
    {                                                              //~7922I~
    	uerrmsg("storage shortage for unicode table",0);           //~7922I~//~v67ZR~
    	return UALLOC_FAILED;                                      //~7922I~
    }                                                              //~7922I~
	fh=fopen(Ppfnm,"r");                                           //~7922I~
//fill data                                                        //~7922I~
    for (ptb=ptb0;;)                                               //~7922R~
    {                                                              //~7922I~
		if (!fgets(buff,sizeof(buff),fh))                          //~7922I~
        	break;                                                 //~7922I~
        pc=buff;                                                   //~7922I~
//      len=strlen(pc);                                            //~7922I~//~v6BkR~
        len=(int)strlen(pc);                                       //~v6BkI~
        if (len<=1)                                                //~7922I~
        	continue;                                              //~7922I~
        if (*(pc+len-1)=='\n')                                     //~7922I~
        	*(pc+len-1)=0;                                         //~7922I~
        pc+=strspn(pc," ");                                        //~7922I~
        if (*pc==UCODETB_CMT)                                      //~7925I~
        	continue;	//comment                                  //~7925M~
        if (*pc==UCODETB_OPTION)                                   //~7925I~
        	continue;	//comment                                  //~7925I~
        if (*pc==UCODETB_UNP)	//unprintable                      //~7925R~
        	datatype=UCODETB_UNPF;                                 //~7925R~
        else                                                       //~7925I~
        	datatype=(int)(*pc);                                   //~7925R~
        pc++;                                                      //~7925R~
        pc+=strspn(pc," ");                                        //~7925R~
    	sscanf(pc,"%X-%X",&ucs1,&ucs2);                            //~7922I~
        ptb->first=ucs1;                                           //~7922I~
        ptb->last=ucs2;                                            //~7922I~
        ptb->datatype=datatype;                                    //~7922R~
        ptb++;                                                     //~7922I~
    }                                                              //~7922I~
    fclose(fh);                                                    //~7922I~
    Sutftb=ptb0;                                                   //~7922I~
    Sutftbentno=entno;                                             //~7922I~
    UTRACED("ini ucstb",Sutftb,entno*(int)sizeof(UCODETB));             //~v643I~//~v6BkR~
#ifdef UTF8UCS2                                                    //~v643I~
	for (ptb=ptb0;entno>0;ptb++,entno--)                           //~v643I~
    {                                                              //~v643I~
    	datatype=ptb->datatype & UTFWWF_LENMASK;                   //~v643R~
    	utfucsmapmodify(0,datatype,ptb->first,ptb->last);   //modfy after mapinit at wcinit//~v643I~
    }                                                              //~v643I~
    utfucsmapmodify(1/*end of list*/,0,0,0);   //end of list, correct overflow sbcs//~v67ZR~
#endif                                                             //~v643I~
    free(ptb0);                                                    //~v6C3I~
	return 0;                                                      //~7922I~
}//utftbinit                                                       //~7922I~
//*******************************************************          //~7922I~
void utftbfhelp(void)                                              //~7922I~
{                                                                  //~7922I~
	uerrmsgcat(" fmt:{0|1|2} xxxx-yyyy //0:unprintable, 1:single, 2:wide char; xxxx-yyyy:unicode range by hex notation",0);//~7922I~
    return;                                                        //~7922I~
}//utftbfhelp(void)                                                //~7922I~
//*******************************************************          //~7922I~
int utftbterm(void)                                                //~7922I~
{                                                                  //~7922I~
    if (Sutftb)                                                    //~7922I~
    {                                                              //~7922I~
    	free(Sutftb);                                              //~7922R~
        Sutftb=0;                                                  //~7922I~
	    Sutftbentno=0;                                             //~7922I~
    }                                                              //~7922I~
	return 0;                                                      //~7922I~
}//utftbterm                                                       //~7922I~
//*******************************************************          //~7922I~
//*search unicode table                                            //~7922I~
//return datatype or 0                                             //~7922I~
//*******************************************************          //~7922I~
int utftbsrch(ULONG Pucs,PUCODETB Ppuctb,int Pmax)                 //~7925R~
{                                                                  //~7922I~
  	int low=0,mid,high,ucs;                                        //~7922I~
//***********************                                          //~7922I~
#ifndef NOTRACE                                                    //~v650R~
	{	//seq ch for bin srch when test                            //~v650R~
    	#define UCTBMAX 10                                         //~v650R~
    	static PUCODETB Sctb[UCTBMAX];                             //~v650R~
        //*************                                            //~v650R~
        for (high=0;high<UCTBMAX;high++)                           //~v650R~
        	if (Sctb[high]==Ppuctb||!Sctb[high])                   //~v650R~
            	break;                                             //~v650R~
        if (!Sctb[high])                                           //~v650R~
        {                                                          //~v650R~
	        Sctb[high]=Ppuctb;                                     //~v650R~
            mid=-1;                                                //~v650R~
            for (high=0;high<Pmax;high++)                          //~v650R~
            {                                                      //~v650R~
                if (mid<Ppuctb[high].first                         //~v650R~
                &&  Ppuctb[high].first<=Ppuctb[high].last)         //~v650R~
                    mid=Ppuctb[high].last;                         //~v650R~
                else                                               //~v650R~
                    uerrexit("width tbl %p seq err at %d(%x--%x)",0,//~v650R~
                                Ppuctb,high,Ppuctb[high].first,Ppuctb[high].last);//~v650R~
            }                                                      //~v650R~
        }                                                          //~v650R~
    }                                                              //~v650R~
#endif                                                             //~v650R~
	high=Pmax-1;                                                   //~7925R~
    if (high<0)                                                    //~7922I~
    	return 0;                                                  //~7922I~
	ucs=(int)Pucs;                                                 //~7922I~
  	if (ucs<Ppuctb[0].first || ucs>Ppuctb[high].last)              //~7925R~
    	return 0;                                                  //~7922I~
  	while (high>=low)                                              //~7922I~
	{                                                              //~7922I~
    	mid=(low+high)/2;                                          //~7922I~
    	if (ucs>Ppuctb[mid].last)                                  //~7925R~
      		low=mid+1;                                             //~7922I~
    	else                                                       //~7922I~
			if (ucs<Ppuctb[mid].first)                             //~7925R~
      			high=mid-1;                                        //~7922I~
    		else                                                   //~7922I~
            	return (Ppuctb[mid].datatype);                     //~7926R~
  	}                                                              //~7922I~
  	return (0);                                                    //~7926R~
}//utftbsrch                                                       //~7922I~
#ifdef UTF8UCS2       //over mkwcwidth_cjk                         //~v650I~
#ifdef AAA                                                         //~v651I~
//******************************************************           //~v650I~
// dbcs if not combineing                                          //~v650I~
//******************************************************           //~v650I~
int utftbsrch_jcombine(int Popt,ULONG Pucs)                        //~v650I~
{                                                                  //~v650I~
  	static UCODETB Suctbj[] = {                                    //~v650I~
      { 0x0460, 0x04ff ,UCODETB_DBCS},  //cyrillic                 //~v650I~
      { 0x0600, 0x06ff ,UCODETB_DBCS},  //arabian                  //~v650I~
      { 0x0700, 0x074f ,UCODETB_DBCS},  //syriac                   //~v650I~
      { 0x0780, 0x07bf ,UCODETB_DBCS},  //thaana                   //~v650I~
      { 0x0900, 0x097f ,UCODETB_DBCS},  //devanagari               //~v650I~
      { 0x0a00, 0x0a7f ,UCODETB_DBCS},  //guirmukhi                //~v650I~
      { 0x0a80, 0x0aff ,UCODETB_DBCS},  //gujarati                 //~v650I~
      { 0x0b80, 0x0bff ,UCODETB_DBCS},  //tamil                    //~v650I~
      { 0x0c00, 0x0c7f ,UCODETB_DBCS},  //telugu                   //~v650I~
      { 0x0c80, 0x0cff ,UCODETB_DBCS},  //kannada                  //~v650I~
      { 0x0d00, 0x0d7f ,UCODETB_DBCS},  //malayalam                //~v650I~
  };                                                               //~v650I~
    int datatype;                                                  //~v650I~
//static int Solddatatype;                                           //~v650I~//~v6VtR~
//static ULONG Solducs;                                              //~v650I~//~v6VtR~
//*******************************                                  //~v650I~
//    if (Pucs==Solducs)                                             //~v650I~//~v6VtR~
//        return Solddatatype;                                       //~v650I~//~v6VtR~
//    Solducs=Pucs;                                                  //~v650I~//~v6VtR~
	datatype=utftbsrch(Pucs,Suctbj,sizeof(Suctbj)/sizeof(UCODETB));//~v650I~
    if (datatype)  //found                                         //~v650I~
    {                                                              //~v650I~
//  	if (!mk_wcwidth_combining((wchar_t)Pucs))	//width=0      //~v650R~//~v6a0R~
//  	if (!mk_wcwidth_combining((UWCHART)Pucs))	//width=0      //~v6a0I~//~v6BjR~
    	if (!mk_wcwidth_combining((UWUCS)Pucs))	//width=0          //~v6BjI~
        	datatype='0';		//width 0;                         //~v650I~
    }                                                              //~v650I~
//    Solddatatype=datatype;                                         //~v650I~//~v6VtR~
    return datatype;                                               //~v650I~
}//utftbsrch_jcombine                                              //~v650I~
#endif   //AAA                                                     //~v651I~
#endif                                                             //~v650I~
#ifdef W32                                                         //~v640I~
//******************************************************           //~v6V4I~
int utftbsrch_j_WXE(ULONG Pucs)                                    //~v6V4I~
{                                                                  //~v6V4I~
  	static UCODETB Suctbj_WXE[] = {                                //~v6V4I~
//U+0370..U+03FF    :Greek and Coptic:Coptic (14 characters), Greek (117 characters), Common (4 characters)//~v6VnI~//~v6VrR~
//    { 0x0391, 0x03a9,UCODETB_WIDE},                                //~v6V4I~//~v6VrR~
//    { 0x03b1, 0x03c9,UCODETB_WIDE},                                //~v6V4I~//~v6VrR~
//U+0400..U+04FF    :Cyrillic:Cyrillic (254 characters), Inherited (2 characters)//~v6VnI~
//    { 0x0410, 0x0451,UCODETB_WIDE},                                //~v6VnI~//~v6VrR~
    { 0x2400, 0x2422,UCODETB_SBCS },                               //~v6WpI~
    { 0x2680, 0x268f,UCODETB_SBCS },                               //~v6WpR~
    { 0x2e26, 0x2e27,UCODETB_WIDE },                               //~v6WpI~
    { 0x10ffff,0x10ffff,UCODETB_WIDE} //last dummy                 //~v6VnI~
  };                                                               //~v6V4I~
    int datatype;                                                  //~v6V4I~
//*******************************                                  //~v6V4I~
	datatype=utftbsrch(Pucs,Suctbj_WXE,sizeof(Suctbj_WXE)/sizeof(UCODETB));//~v6V4I~
    UTRACEP("%s:ucs=%04x,rc=%x\n",UTT,Pucs,datatype);              //~v6VnR~
    return datatype;                                               //~v6V4I~
}//utftbsrch_j_WXE                                                 //~v6V4I~//~v6VnR~
//******************************************************           //~7925I~
//japanese only(W32)                                               //~v65pR~
//chk before ucvucs2sjis() for the case                            //~7927R~
// multiple ucs is converted to single sjis code by ucvucst/ucvucs //~7927R~
// font width is not same as csr width                             //~7927I~
// iswprint fail but symbol defined                                //~7927I~
//******************************************************           //~7925I~
int utftbsrch_j(ULONG Pucs)                                        //~7925I~
{                                                                  //~7925I~
  	static UCODETB Suctbj[] = {                                    //~7925R~
#ifdef UTF8UCS2       //over mkwcwidth_cjk                         //~v643I~
    { 0x00A1, 0x00A1,UCODETB_SBCS },                               //~v643I~
    { 0x00A4, 0x00A4,UCODETB_SBCS },                               //~v643I~
//  { 0x00A7, 0x00A8 },                                            //~v643I~
    { 0x00AA, 0x00AA,UCODETB_SBCS},                                //~v643I~
    { 0x00AE, 0x00AE,UCODETB_SBCS},                                //~v643I~
//  { 0x00B0, 0x00B4 },                                            //~v643I~
    { 0x00b0, 0x00b1,UCODETB_WIDE},                                //~v6WpR~
    { 0x00B2, 0x00B3,UCODETB_SBCS},                                //~v643I~
    { 0x00B4, 0x00B4,UCODETB_WIDE},                                //~v6WpR~
    { 0x00B6, 0x00B6,UCODETB_WIDE},                                //~v6WpR~
//  { 0x00B6, 0x00BA },                                            //~v643I~
    { 0x00B7, 0x00BA,UCODETB_SBCS},                                //~v643I~
    { 0x00BC, 0x00BF,UCODETB_SBCS},                                //~v643R~
    { 0x00C6, 0x00C6,UCODETB_SBCS},                                //~v643I~
    { 0x00D0, 0x00D0,UCODETB_SBCS },                               //~v643I~
//  { 0x00D7, 0x00D8 },                                            //~v643I~
    { 0x00D7, 0x00D7,UCODETB_WIDE },                               //~v6WpR~
                                                                   //~v643I~
//    { 0x00D8, 0x00D8,UCODETB_SBCS },                             //~v643I~
//    { 0x00DE, 0x00E1,UCODETB_SBCS },                             //~v643I~
//    { 0x00E6, 0x00E6,UCODETB_SBCS },                             //~v643I~
//    { 0x00E8, 0x00EA,UCODETB_SBCS },                             //~v643I~
//    { 0x00EC, 0x00ED,UCODETB_SBCS },                             //~v643I~
//    { 0x00F0, 0x00F0,UCODETB_SBCS },                             //~v643I~
//    { 0x00F2, 0x00F3,UCODETB_SBCS },                             //~v643I~
    { 0x00d8, 0x00F3,UCODETB_SBCS },                               //~v643I~
                                                                   //~v643I~
//  { 0x00F7, 0x00FA },                                            //~v643I~
//    { 0x00F8, 0x00FA,UCODETB_SBCS },                             //~v643I~
//    { 0x00FC, 0x00FC,UCODETB_SBCS },                             //~v643I~
//    { 0x00FE, 0x00FE,UCODETB_SBCS },                             //~v643I~
    { 0x00F7, 0x00F7,UCODETB_WIDE },                               //~v6WpR~
    { 0x00f8, 0x00ff,UCODETB_SBCS },                               //~v643R~
                                                                   //~v643I~
//    { 0x0101, 0x0101,UCODETB_SBCS },                             //~v643I~
//    { 0x0111, 0x0111,UCODETB_SBCS },                             //~v643I~
//    { 0x0113, 0x0113,UCODETB_SBCS },                             //~v643I~
//    { 0x011B, 0x011B,UCODETB_SBCS },                             //~v643I~
//    { 0x0126, 0x0127,UCODETB_SBCS },                             //~v643I~
//    { 0x012B, 0x012B,UCODETB_SBCS },                             //~v643I~
//    { 0x0131, 0x0133,UCODETB_SBCS },                             //~v643I~
//    { 0x0138, 0x0138,UCODETB_SBCS },                             //~v643I~
//    { 0x013F, 0x0142,UCODETB_SBCS },                             //~v643I~
//    { 0x0144, 0x0144,UCODETB_SBCS },                             //~v643I~
//    { 0x0148, 0x014B,UCODETB_SBCS },                             //~v643I~
//    { 0x014D, 0x014D,UCODETB_SBCS },                             //~v643I~
//    { 0x0152, 0x0153,UCODETB_SBCS },                             //~v643I~
//    { 0x0166, 0x0167,UCODETB_SBCS },                             //~v643I~
    { 0x0100, 0x017f,UCODETB_SBCS },                               //~v643I~
    { 0x01c4, 0x01cc ,UCODETB_UNPF},  //DZ, shrink/expand by display status//~v643R~
//  { 0x01c4, 0x01cc ,UCODETB_SBCS},  //DZ, shrink/expand by display status//~v643R~
//  { 0x01c4, 0x01cc ,UCODETB_DBCS},  //DZ, shrink/expand by display status//~v643R~
                                                                   //~v643I~
//  { 0x01CE, 0x01CE },                                            //~v643I~
//  { 0x01D0, 0x01D0 },                                            //~v643I~
//  { 0x01D2, 0x01D2 },                                            //~v643I~
//  { 0x01D4, 0x01D4 },                                            //~v643I~
//  { 0x01D6, 0x01D6 },                                            //~v643I~
//  { 0x01D8, 0x01D8 },                                            //~v643I~
//  { 0x01DA, 0x01DA },                                            //~v643I~
//  { 0x01DC, 0x01DC },                                            //~v643I~
      { 0x01cd, 0x01dc,UCODETB_DBCS },  //A                        //~v643I~
      { 0x01f1, 0x01f3 ,UCODETB_UNPF},  //DZ                       //~v643R~
//    { 0x01f1, 0x01f3 ,UCODETB_SBCS},  //DZ                       //~v643R~
//    { 0x01f1, 0x01f3 ,UCODETB_DBCS},  //DZ                       //~v643R~
      { 0x01f5, 0x01f5 ,UCODETB_DBCS},  //g                        //~v643I~
      { 0x0218, 0x0218 ,UCODETB_WIDE},  //g                        //~v6WpR~
      { 0x021a, 0x021a ,UCODETB_WIDE},  //g                        //~v6WpR~
                                                                   //~v643I~
//    { 0x0251, 0x0251,UCODETB_SBCS },                             //~v643I~
//    { 0x0261, 0x0261,UCODETB_SBCS },                             //~v643I~
//    { 0x02C4, 0x02C4,UCODETB_SBCS },                             //~v643I~
//    { 0x02C7, 0x02C7,UCODETB_SBCS },                             //~v643I~
//    { 0x02C9, 0x02CB,UCODETB_SBCS },                             //~v643I~
//    { 0x02CD, 0x02CD,UCODETB_SBCS },                             //~v643I~
//    { 0x02D0, 0x02D0,UCODETB_SBCS },                             //~v643I~
//    { 0x02D8, 0x02DB,UCODETB_SBCS },                             //~v643I~
//    { 0x02DD, 0x02DD,UCODETB_SBCS },                             //~v643I~
//    { 0x02DF, 0x02DF,UCODETB_SBCS },                             //~v643I~
//    { 0x0250, 0x02df,UCODETB_SBCS },                               //~v643I~//~v6WpR~
      { 0x0250, 0x02c9,UCODETB_SBCS },                             //~v6WpR~
      { 0x02ca, 0x02cb,UCODETB_WIDE },                             //~v6WpR~
      { 0x02ce, 0x02df,UCODETB_SBCS },                             //~v6WpR~
      { 0x0376, 0x0376,UCODETB_WIDE },                             //~v6WpR~
                                                                   //~v643I~
//  { 0x0391, 0x03A1 },                                            //~v643I~
//  { 0x03A3, 0x03A9 },                                            //~v643I~
//U+0370..U+03FF    :Greek and Coptic:Coptic (14 characters), Greek (117 characters), Common (4 characters)//~v6VrR~
    { 0x0391, 0x03a1,UCODETB_WIDE},     //for xe and wxe, neew width=2 for print on xe not to override 2nd byte by next char//~v6VrR~
    { 0x03a2, 0x03a2,UCODETB_UNPF},                                //~v6VrR~
    { 0x03a3, 0x03a9,UCODETB_WIDE},                                //~v6VrR~
    { 0x03b1, 0x03c9,UCODETB_WIDE},                                //~v6VrR~
//  { 0x03B1, 0x03C1 },                                            //~v643I~
//  { 0x03C3, 0x03C9 },                                            //~v643I~
    { 0x03d2, 0x03da,UCODETB_WIDE},                                //~v6WpR~
    { 0x03dc, 0x03dc,UCODETB_WIDE},                                //~v6WpR~
    { 0x03de, 0x03e8,UCODETB_WIDE},                                //~v6WpR~
    { 0x03ea, 0x03ee,UCODETB_WIDE},                                //~v6WpR~
    { 0x03f0, 0x03f1,UCODETB_WIDE},                                //~v6WpR~
    { 0x03f4, 0x03fb,UCODETB_WIDE},                                //~v6WpR~
//  { 0x0401, 0x0401 },                                            //~v643I~
    { 0x0401, 0x0401,UCODETB_WIDE},                                //~v6WpR~
    { 0x040d, 0x040d,UCODETB_WIDE},                                //~v6WpR~
//  { 0x0410, 0x044F },                                            //~v643I~
//  { 0x0451, 0x0451 },                                            //~v643I~
//U+0400..U+04FF    :Cyrillic:Cyrillic (254 characters), Inherited (2 characters)//~v6VrI~
    { 0x0410, 0x0451,UCODETB_WIDE},                                //~v6VrI~
#ifdef AAA	//DBCS if not combining                                //~v650R~
      { 0x0460, 0x04ff ,UCODETB_DBCS},  //cyrillic                 //~v643I~
      { 0x0600, 0x06ff ,UCODETB_DBCS},  //arabian                  //~v643I~
      { 0x0700, 0x074f ,UCODETB_DBCS},  //syriac                   //~v643I~
      { 0x0780, 0x07bf ,UCODETB_DBCS},  //thaana                   //~v643I~
      { 0x0900, 0x097f ,UCODETB_DBCS},  //devanagari               //~v643I~
      { 0x0a00, 0x0a7f ,UCODETB_DBCS},  //guirmukhi                //~v643I~
      { 0x0a80, 0x0aff ,UCODETB_DBCS},  //gujarati                 //~v643I~
      { 0x0b80, 0x0bff ,UCODETB_DBCS},  //tamil                    //~v643I~
      { 0x0c00, 0x0c7f ,UCODETB_DBCS},  //telugu                   //~v643I~
      { 0x0c80, 0x0cff ,UCODETB_DBCS},  //kannada                  //~v643I~
      { 0x0d00, 0x0d7f ,UCODETB_DBCS},  //malayalam                //~v643I~
#endif                                                             //~v650I~
#ifdef GGG                                                         //~v6X3I~
      { 0x1160, 0x11ff ,UCODETB_DBCS},  //hangle                   //~v643I~
#endif                                                             //~v6X3R~
      { 0x1e00, 0x1eff ,UCODETB_DBCS},  //latin                    //~v643I~
//  { 0x2010, 0x2010 },                                            //~v643I~
    { 0x2010, 0x2010,UCODETB_WIDE },                               //~v6WpR~
//  { 0x2013, 0x2016 },                                            //~v643I~
    { 0x2013, 0x2014,UCODETB_SBCS },                               //~v643I~
//  { 0x2016, 0x2016,UCODETB_SBCS },                               //~v643I~//~v6VrR~
    { 0x2016, 0x2016,UCODETB_WIDE },                               //~v6VrI~
//  { 0x2018, 0x2019 },                                            //~v643I~
    { 0x2018, 0x2019,UCODETB_WIDE },                               //~v6WpR~
//  { 0x201C, 0x201D },                                            //~v643I~
    { 0x201c, 0x201d,UCODETB_WIDE },                               //~v6WpR~
//  { 0x2020, 0x2022 },                                            //~v643I~
    { 0x2020, 0x2021,UCODETB_WIDE },                               //~v6VrI~
    { 0x2022, 0x2022,UCODETB_SBCS },                               //~v643I~
//  { 0x2024, 0x2027 },                                            //~v643I~
    { 0x2024, 0x2024,UCODETB_SBCS },                               //~v643I~
    { 0x2027, 0x2027,UCODETB_SBCS },                               //~v643I~
//  { 0x2030, 0x2030 },                                            //~v643I~
//  { 0x2032, 0x2033 },                                            //~v643I~
    { 0x2030, 0x2032,UCODETB_WIDE },                               //~v6WpR~
    { 0x2035, 0x2035,UCODETB_SBCS },                               //~v643I~
//  { 0x203B, 0x203B },                                            //~v643I~
    { 0x203E, 0x203E,UCODETB_SBCS },                               //~v643I~
    { 0x2050, 0x2050,UCODETB_WIDE },                               //~v6WpR~
    { 0x2051, 0x2051,UCODETB_WIDE },                               //~v6VnI~
    { 0x2053, 0x2054,UCODETB_WIDE },                               //~v6WpR~
    { 0x205a, 0x205a,UCODETB_WIDE },                               //~v6WpR~
    { 0x205c, 0x205d,UCODETB_WIDE },                               //~v6WpR~
    { 0x205f, 0x205f,UCODETB_WIDE },   //2060-2064:Format          //~v6WpR~
    { 0x2074, 0x2074,UCODETB_SBCS },                               //~v643I~
    { 0x207F, 0x207F,UCODETB_SBCS },                               //~v643I~
    { 0x2081, 0x2084,UCODETB_SBCS },                               //~v643I~
//  { 0x20AC, 0x20AC,UCODETB_SBCS },//euro                         //~v643I~//~v6VrR~
//U+20A0..U+20CF    :Currency Symbols:Common                       //~v6VrI~
//  { 0x20A0, 0x20cf,UCODETB_SBCS },                               //~v6VrI~//~v6WpR~
    { 0x20A0, 0x20b7,UCODETB_SBCS },                               //~v6WpI~
//  { 0x20b8, 0x20b8,UCODETB_WIDE },  //ambiguous no lang          //~v6WpR~
//  { 0x2103, 0x2103 },                                            //~v643I~
    { 0x2105, 0x2105,UCODETB_SBCS },                               //~v643I~
    { 0x2109, 0x2109,UCODETB_SBCS },                               //~v643I~
    { 0x2113, 0x2113,UCODETB_SBCS },                               //~v643I~
//  { 0x2116, 0x2116 },                                            //~v643I~
//  { 0x2121, 0x2122 },                                            //~v643I~
    { 0x2126, 0x2126,UCODETB_SBCS },                               //~v643I~
//  { 0x212B, 0x212B },                                            //~v643I~
    { 0x2150, 0x2152,UCODETB_WIDE },                               //~v6WpR~
    { 0x2153, 0x2154,UCODETB_SBCS },                               //~v643I~
    { 0x215B, 0x215E,UCODETB_SBCS },                               //~v643I~
//  { 0x2160, 0x216B },                                            //~v643I~
      { 0x216c, 0x216f ,UCODETB_DBCS},                             //~v643I~
//  { 0x2170, 0x2179 },                                            //~v643I~
      { 0x217a, 0x2182 ,UCODETB_DBCS},                             //~v643I~
    { 0x2183, 0x2189 ,UCODETB_WIDE},                               //~v6WpR~
//  { 0x2190, 0x2199 },                                            //~v643I~
    { 0x2194, 0x2199,UCODETB_SBCS },                               //~v643I~
    { 0x21B8, 0x21B9,UCODETB_SBCS },                               //~v643I~
    { 0x21D0, 0x21D0,UCODETB_SBCS },        //add <==              //~v643I~
//  { 0x21D2, 0x21D2 },                                            //~v643I~
//  { 0x21D4, 0x21D4 },                                            //~v643I~
    { 0x21E7, 0x21E7,UCODETB_SBCS },                               //~v643I~
    { 0x21f0, 0x21f2,UCODETB_WIDE },                               //~v6WpR~
    { 0x21f4, 0x21ff,UCODETB_WIDE },                               //~v6WpR~
//  { 0x2200, 0x2200 },                                            //~v643I~
//  { 0x2202, 0x2203 },                                            //~v643I~
//  { 0x2207, 0x2208 },                                            //~v643I~
//  { 0x220B, 0x220B },                                            //~v643I~
    { 0x220F, 0x220F,UCODETB_SBCS },                               //~v643I~
//  { 0x2211, 0x2211 },                                            //~v643I~
    { 0x2211, 0x2211,UCODETB_WIDE },                               //~v6WpR~
    { 0x2215, 0x2215,UCODETB_SBCS },                               //~v643I~
//  { 0x221A, 0x221A },                                            //~v643I~
    { 0x221a, 0x221a,UCODETB_WIDE },                               //~v6WpR~
//  { 0x221D, 0x2220 },                                            //~v643I~
    { 0x2223, 0x2223,UCODETB_SBCS },                               //~v643I~
//  { 0x2225, 0x2225 },                                            //~v643I~
//  { 0x2227, 0x222C },                                            //~v643I~
//  { 0x222E, 0x222E },                                            //~v643I~
//  { 0x2234, 0x2237 },                                            //~v643I~
    { 0x2236, 0x2237,UCODETB_SBCS },                               //~v643I~
//  { 0x223C, 0x223D },                                            //~v643I~
    { 0x223C, 0x223c,UCODETB_SBCS },                               //~v643I~
    { 0x2248, 0x2248,UCODETB_SBCS },                               //~v643I~
    { 0x224C, 0x224C,UCODETB_SBCS },                               //~v643I~
//  { 0x2252, 0x2252 },                                            //~v643I~
//  { 0x2260, 0x2261 },                                            //~v643I~
//  { 0x2264, 0x2267 },                                            //~v643I~
    { 0x2264, 0x2265,UCODETB_SBCS },                               //~v643I~
//  { 0x226A, 0x226B },                                            //~v643I~
    { 0x226E, 0x226F,UCODETB_SBCS },                               //~v643I~
//  { 0x2282, 0x2283 },                                            //~v643I~
//  { 0x2286, 0x2287 },                                            //~v643I~
    { 0x2295, 0x2295,UCODETB_SBCS },                               //~v643I~
    { 0x2299, 0x2299,UCODETB_SBCS },                               //~v643I~
//  { 0x22A5, 0x22A5 },                                            //~v643I~
//  { 0x22BF, 0x22BF },                                            //~v643I~
    { 0x22f2, 0x22f2,UCODETB_WIDE },                               //~v6WpR~
    { 0x22fa, 0x22fa,UCODETB_WIDE },                               //~v6WpR~
//  { 0x2312, 0x2312 },                                            //~v643I~
//  { 0x2460, 0x24E9 },                                            //~v643I~
      { 0x24ea, 0x24ea ,UCODETB_DBCS},                             //~v643I~
//  { 0x24EB, 0x254B },                                            //~v643I~
    { 0x2504, 0x250a,UCODETB_SBCS },//grid                         //~v643R~
    { 0x250d, 0x250e,UCODETB_SBCS },                               //~v643I~
    { 0x2511, 0x2512,UCODETB_SBCS },                               //~v643I~
    { 0x2515, 0x2516,UCODETB_SBCS },                               //~v643I~
    { 0x2519, 0x251a,UCODETB_SBCS },                               //~v643I~
    { 0x251e, 0x251f,UCODETB_SBCS },                               //~v643I~
    { 0x2521, 0x2522,UCODETB_SBCS },                               //~v643I~
    { 0x2526, 0x2527,UCODETB_SBCS },                               //~v643I~
    { 0x2529, 0x252a,UCODETB_SBCS },                               //~v643I~
    { 0x252d, 0x252e,UCODETB_SBCS },                               //~v643I~
    { 0x2531, 0x2532,UCODETB_SBCS },                               //~v643I~
    { 0x2535, 0x2536,UCODETB_SBCS },                               //~v643I~
    { 0x2539, 0x253a,UCODETB_SBCS },                               //~v643I~
    { 0x253d, 0x253e,UCODETB_SBCS },                               //~v643I~
    { 0x2540, 0x2541,UCODETB_SBCS },                               //~v643I~
    { 0x2543, 0x254a,UCODETB_SBCS },                               //~v643I~
    { 0x2550, 0x2573,UCODETB_SBCS },                               //~v643I~
    { 0x2580, 0x258F,UCODETB_SBCS },                               //~v643I~
//  { 0x2592, 0x2595,UCODETB_SBCS },                               //~v643I~//~v6WpR~
    { 0x2592, 0x2593,UCODETB_SBCS },                               //~v6WpI~
    { 0x2594, 0x2594,UCODETB_WIDE },                               //~v6WpR~
    { 0x2595, 0x2595,UCODETB_SBCS },                               //~v6WpI~
    { 0x2596, 0x259f,UCODETB_WIDE },                               //~v6WpR~
//  { 0x25A0, 0x25A1 },                                            //~v643I~
    { 0x25A3, 0x25A9,UCODETB_SBCS },                               //~v643I~
//  { 0x25B2, 0x25B3 },                                            //~v643I~
    { 0x25B6, 0x25B7,UCODETB_SBCS },                               //~v643I~
//  { 0x25BC, 0x25BD },                                            //~v643I~
    { 0x25C0, 0x25C1,UCODETB_SBCS },                               //~v643I~
//  { 0x25C6, 0x25C8 },                                            //~v643I~
    { 0x25C8, 0x25C8,UCODETB_SBCS },                               //~v643I~
//  { 0x25CB, 0x25CB },                                            //~v643I~
//  { 0x25CE, 0x25D1 },                                            //~v643I~
    { 0x25d0, 0x25d1,UCODETB_SBCS },                               //~v643I~
    { 0x25E2, 0x25E5,UCODETB_SBCS },                               //~v643I~
                                                                   //~v643I~
//  { 0x25EF, 0x25EF },                                            //~v643I~
//  { 0x2605, 0x2606 },                                            //~v643I~
//  { 0x2609, 0x2609 },                                            //~v643I~
//  { 0x260E, 0x260F },                                            //~v643I~
//  { 0x2614, 0x2615 },                                            //~v643I~
//  { 0x261C, 0x261C },                                            //~v643I~
//  { 0x261E, 0x261E },                                            //~v643I~
      { 0x25ef, 0x2638 ,UCODETB_DBCS},                             //~v643I~
                                                                   //~v643I~
//  { 0x2640, 0x2640 },                                            //~v643I~
//  { 0x2642, 0x2642 },                                            //~v643I~
      { 0x263d, 0x265f ,UCODETB_DBCS},                             //~v643I~
                                                                   //~v643I~
    { 0x2660, 0x2661,UCODETB_SBCS },                               //~v643I~
    { 0x2663, 0x2665,UCODETB_SBCS },                               //~v643I~
//  { 0x2667, 0x266A },                                            //~v643I~
    { 0x2667, 0x2667,UCODETB_SBCS },                               //~v643I~
    { 0x2669, 0x2669,UCODETB_SBCS },                               //~v643I~
//  { 0x266C, 0x266D },                                            //~v643I~
    { 0x266c, 0x266c,UCODETB_SBCS },                               //~v643I~
//  { 0x266F, 0x266F },                                            //~v643I~
    { 0x2672, 0x267E,UCODETB_WIDE },                               //~v6WpR~
    { 0x2680, 0x268f,UCODETB_WIDE },                               //~v6WpR~
    { 0x2690, 0x26bc,UCODETB_WIDE },                               //~v6WpR~
    { 0x26bd, 0x26ff,UCODETB_WIDE },                               //~v6WpR~
                                                                   //~v643I~
//  { 0x273D, 0x273D },                                            //~v643I~
//  { 0x2776, 0x277F },                                            //~v643I~
      { 0x2700, 0x27ff ,UCODETB_DBCS},                             //~v643I~
    { 0x2e0e, 0x2e11 ,UCODETB_WIDE},                               //~v6WpR~
//  { 0x3190, 0x319f,UCODETB_SBCS },                               //~v643R~//~v6WpR~
    { 0xa960, 0xa97c ,UCODETB_WIDE},                               //~v6WpR~
                                                                   //~v643I~
//  { 0xE000, 0xF8FF },    //private                               //~v643I~
      { 0xfb13, 0xfb17 ,UCODETB_DBCS},                             //~v643I~
      { 0xfb50, 0xfdff ,UCODETB_DBCS},//arabian A                  //~v643I~
    { 0xFFFC, 0xFFFD ,UCODETB_WIDE},                               //~v6WpR~
//  { 0xFFFD, 0xFFFD },                                            //~v643I~
    { 0x010ff0, 0x010fff,UCODETB_UNPF} //for unprintable test @@@@test//~v6VrI~
//  { 0xF0000, 0xFFFFD },                                          //~v643I~
//  { 0x100000, 0x10FFFD }                                         //~v643I~//~v6VrR~
#else                                                              //~v643I~
      { 0x00A2, 0x00A3 ,  UCODETB_SBCS} //cent,pond                //~7926R~
     ,{ 0x00A7, 0x00A8 ,UCODETB_DBCS}   //ss,"                     //~7925R~
     ,{ 0x00ac, 0x00ac ,  UCODETB_SBCS} //not                      //~7926R~
     ,{ 0x00B0, 0x00B1 ,UCODETB_DBCS}   //degree,+-                             //~7925I~
     ,{ 0x00B4, 0x00B4 ,UCODETB_DBCS}   //'                                     //~7925I~
     ,{ 0x00B6, 0x00B6 ,UCODETB_DBCS}   //q                                     //~7925I~
     ,{ 0x00D7, 0x00D7 ,UCODETB_DBCS}   //X                                     //~7925I~
//   ,{ 0x00F6, 0x00F6 ,UCODETB_DBCS}   //divide                   //~v642R~
     ,{ 0x00F7, 0x00F7 ,UCODETB_DBCS}   //divide                   //~v642I~
                                                                   //~7925I~
     ,{ 0x01cd, 0x01dc ,UCODETB_DBCS}   //
     ,{ 0x01f5, 0x01f5 ,UCODETB_DBCS}   //g
///  ,{ 0x0b00, 0x0b6f , UCODETB_UNPF}                             //~7930R~
///  ,{ 0x0b80, 0x0dff , UCODETB_UNPF}                             //~7930R~
///  ,{ 0x0e80, 0x0fff , UCODETB_UNPF}                             //~7930R~
                                                                   //~7925I~
///  ,{ 0x1000, 0x10cf , UCODETB_UNPF}                             //~7930R~
     ,{ 0x1160, 0x11f9 ,UCODETB_DBCS}   //hangle                   //~7926R~
///  ,{ 0x1200, 0x135f , UCODETB_UNPF}  //deny iswprint            //~7930R~
///  ,{ 0x1780, 0x18af , UCODETB_UNPF}  //iswprint=1 but           //~7930R~
                                                                   //~7925I~
     ,{ 0x2011, 0x2014 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2016, 0x2016 ,  UCODETB_SBCS} // ucvucs dup define tbl   //~7927I~
     ,{ 0x2070, 0x2070 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2074, 0x208e ,  UCODETB_SBCS} // 208f not used           //~7927R~
     ,{ 0x20a0, 0x20af ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2100, 0x2102 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2104, 0x2105 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2117, 0x2120 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2122, 0x212a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x212c, 0x2138 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2153, 0x215f ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2160, 0x2182 ,UCODETB_DBCS}   //I-->pignose
     ,{ 0x2194, 0x21d1 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x21d3, 0x21d3 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x21d5, 0x21ea ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2201, 0x2201 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2204, 0x2206 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2209, 0x220a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x220c, 0x2210 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2212, 0x2219 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x221a, 0x221a ,UCODETB_DBCS}   //root
     ,{ 0x221b, 0x221c ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2221, 0x2224 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2226, 0x2226 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x222d, 0x222d ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2230, 0x2233 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2236, 0x223c ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x223e, 0x2251 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2253, 0x225f ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2262, 0x2265 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2268, 0x2269 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x226c, 0x2280 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2283, 0x2284 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2287, 0x22a4 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x22a6, 0x22be ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x22c0, 0x22ff ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2302, 0x2302 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2310, 0x2310 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2320, 0x2320 ,  UCODETB_SBCS} //                         //~7925I~
///  ,{ 0x2329, 0x232a , UCODETB_UNPF}                             //~7930R~
     ,{ 0x2474, 0x24ea ,UCODETB_DBCS}   //(1)-->
     ,{ 0x2504, 0x250b ,  UCODETB_SBCS} //box drawing              //~7927R~
     ,{ 0x250d, 0x250e ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2511, 0x2512 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2515, 0x2516 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2519, 0x251a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x251e, 0x251f ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2521, 0x2522 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2526, 0x2527 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2529, 0x252a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x252d, 0x252e ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2531, 0x2532 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2535, 0x2536 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2539, 0x253a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x253d, 0x253e ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2540, 0x2541 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2543, 0x254a ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x254c, 0x2595 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25a2, 0x25b1 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25b4, 0x25bb ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25be, 0x25c5 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25c8, 0x25ca ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25cc, 0x25cd ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x25d0, 0x25ee ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2600, 0x2613 ,UCODETB_DBCS}   //sun-->X
     ,{ 0x261a, 0x2638 ,UCODETB_DBCS}   //
     ,{ 0x2639, 0x263c ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x263d, 0x265f ,UCODETB_DBCS}   //
     ,{ 0x2660, 0x2667 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2668, 0x2668 ,UCODETB_DBCS}   //
     ,{ 0x2669, 0x2669 ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x266b, 0x266c ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x266e, 0x266e ,  UCODETB_SBCS} //                         //~7925I~
     ,{ 0x2701, 0x2704 ,UCODETB_DBCS}   //                         //~7927R~
     ,{ 0x2706, 0x2709 ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x270c, 0x2727 ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x2729, 0x274b ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x274d, 0x274d ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x274f, 0x2752 ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x2756, 0x2756 ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x2758, 0x275e ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x2761, 0x2794 ,UCODETB_DBCS}   //                         //~7927I~
     ,{ 0x2798, 0x27af ,UCODETB_DBCS}   //
     ,{ 0x27b1, 0x27be ,UCODETB_DBCS}   //
     ,{ 0x2ff0, 0x2ffb ,UCODETB_DBCS}   //
                                                                   //~7925I~
     ,{ 0x3000, 0x3020 ,UCODETB_DBCS}   //
//   ,{ 0x3021, 0x3029 ,  UCODETB_SBCS} //csr is narrow but font is dbcs//~7927R~
     ,{ 0x3031, 0x3037 ,UCODETB_DBCS}   //
///  ,{ 0x3038, 0x303a , UCODETB_UNPF}                             //~7930R~
///  ,{ 0x312a, 0x312c , UCODETB_UNPF}                             //~7930R~
     ,{ 0x3192, 0x319f ,UCODETB_SBCS}   //csr is narrow            //~7927R~
///  ,{ 0x31a0, 0x31ff , UCODETB_UNPF}                             //~7930R~
     ,{ 0x3200, 0x3243 ,UCODETB_DBCS}   //
     ,{ 0x3260, 0x32b0 ,UCODETB_DBCS}   //
     ,{ 0x32c0, 0x32cb ,UCODETB_DBCS}   //
     ,{ 0x32d0, 0x32fe ,UCODETB_DBCS}   //
     ,{ 0x3300, 0x3376 ,UCODETB_DBCS}   //
     ,{ 0x337b, 0x33dd ,UCODETB_DBCS}   //                         //~7927R~
     ,{ 0x33e0, 0x33fe ,UCODETB_DBCS}   //
///  ,{ 0x3400, 0x3fff , UCODETB_UNPF}                             //~7930R~
                                                                   //~7925I~
///  ,{ 0x4000, 0x4dff , UCODETB_UNPF}                             //~7930R~
                                                                   //~7925I~
///  ,{ 0xa000, 0xa48c , UCODETB_UNPF}                             //~7930R~
//   ,{ 0xac00, 0xd7a3 , UCODETB_UNPF}  //hangul,leave it as printable//~7927R~
                                                                   //~7925I~
     ,{ 0xf001, 0xf002 ,UCODETB_SBCS}                              //~7927I~
///  ,{ 0xfb21, 0xfb29 , UCODETB_UNPF}                             //~7930R~
///  ,{ 0xfe32, 0xfe32 , UCODETB_UNPF}                             //~7930R~
///  ,{ 0xfe58, 0xfe58 , UCODETB_UNPF}                             //~7930R~
     ,{ 0xfffc, 0xfffc ,UCODETB_DBCS}   //obj                      //~7927I~
#endif                                                             //~v643I~
  };                                                               //~7925I~
    int datatype;                                                  //~7925I~
//static int Solddatatype;                                           //~v60mI~//~v6VtR~
//static ULONG Solducs;                                              //~v60mI~//~v6VtR~
//*******************************                                  //~7925R~
	if (Sutftbopt & SUO_NOJ)                                       //~7929I~
        return 0;                                                  //~7929I~
//    if (Pucs==Solducs)                                             //~v60mI~//~v6VtR~
//        return Solddatatype;                                       //~v60mI~//~v6VtR~
//    Solducs=Pucs;                                                  //~v60mR~//~v6VtR~
    if (SswWXE)                                                    //~v6V4I~
    	datatype=utftbsrch_j_WXE(Pucs);                            //~v6V4I~
    else                                                           //~v6V4I~
        datatype=0;                                                //~v6V4I~
  if (!datatype)                                                   //~v6V4I~
  {                                                                //~v6V4I~
//  datatype=utftbsrch_jcombine(0,Pucs);                           //~v651R~
//if (!datatype)                                                   //~v651R~
	datatype=utftbsrch(Pucs,Suctbj,sizeof(Suctbj)/sizeof(UCODETB));//~7925I~
  }                                                                //~v6V4I~
//    Solddatatype=datatype;                                         //~v60mI~//~v6VtR~
    if (datatype & UCODETB_UNPF) //unprintable entry               //~v6VoI~
        return -1;      //not 0 to return this value               //~v6VoI~
    if (datatype==UCODETB_NARROW)                                  //~v6VoI~
        datatype=(UTFWWF_F1C1|2);  //narrow(fontwidth=1) DBCS      //~v6VoI~
    else                                                           //~v6VoI~
    if (datatype==UCODETB_WIDE)                                    //~v6VoI~
        datatype=(UTFWWF_F2C1|2);  //wide font                     //~v6VoI~
    UTRACEP("%s:ucs=%06x,datatype=%x\n",UTT,Pucs,datatype);        //~v6WpR~
    return datatype;                                               //~7925I~
}//utftbsrch_j                                                     //~7925I~
#endif	//W32                                                      //~v640I~
#ifdef LNX                                                         //~v60mR~
//******************************************************           //~v60mR~
//japanese EUConly                                                 //~v60mR~
//  chked under EUC when -y8 option specified                      //~v60mR~
//******************************************************           //~v60mR~
int utftbsrch_jeuc(ULONG Pucs)                                     //~v60mR~
{                                                                  //~v60mR~
    static UCODETB Suctbj_euc[] = {                                //~v60mR~
#ifdef UTF8UCS2                                                    //~v640R~
     { 0x0000, 0x0000 ,   UCODETB_SBCS}                            //~v640I~
#else     //folowings are SBCS of wcwcdth=2;treated as narrow DBCS by logic//~v640R~
     { 0x00a2, 0x00a3 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00a6, 0x00a6 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00a9, 0x00a9 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00ac, 0x00ac ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00af, 0x00af ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00c0, 0x00c5 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00c7, 0x00cf ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00d1, 0x00d6 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00d9, 0x00dd ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00e2, 0x00e5 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00e7, 0x00e7 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00eb, 0x00eb ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00ee, 0x00ef ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00f1, 0x00f1 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00f4, 0x00f6 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00fb, 0x00fb ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00fd, 0x00fd ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x00ff, 0x00ff ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0100, 0x0100 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0102, 0x010f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0110, 0x0110 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0112, 0x0112 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0116, 0x011a ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x011c, 0x011f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0120, 0x0122 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0124, 0x0125 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0128, 0x012a ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x012e, 0x012f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0130, 0x0130 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0134, 0x0137 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0139, 0x013e ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0143, 0x0143 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0145, 0x0147 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x014c, 0x014c ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0150, 0x0151 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0154, 0x015f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0160, 0x0165 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0168, 0x016a ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x016c, 0x016f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0170, 0x017f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01cd, 0x01cd ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01cf, 0x01cf ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01d1, 0x01d1 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01d3, 0x01d3 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01d5, 0x01d5 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01d7, 0x01d7 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01d9, 0x01d9 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01db, 0x01db ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x01f5, 0x01f5 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0384, 0x0386 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0388, 0x038a ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x038c, 0x038c ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x038e, 0x038f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0390, 0x0390 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x03aa, 0x03af ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x03b0, 0x03b0 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x03c2, 0x03c2 ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x03ca, 0x03ce ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0402, 0x040c ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x040e, 0x040f ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x0452, 0x045c ,   UCODETB_SBCS}                            //~v60mR~
    ,{ 0x045e, 0x045f ,   UCODETB_SBCS}                            //~v60mR~
#endif                                                             //~v640I~
  };                                                               //~v60mR~
    static UCODETB Suctbj_euc_console[] = {                        //~v62UR~
#ifdef UTF8UCS2                                                    //~v640R~
  #ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1I~
     { 0x0000, 0x0000 ,   UCODETB_SBCS}                            //~v6V1I~
#ifdef AAA                                                         //~v6V9I~
    ,{ 0x00a7, 0x00a7 ,   UCODETB_SBCS}    //chapter,dup with ambiguous//~v6V1R~
//  ,{ 0x2022, 0x2022 ,   UCODETB_SBCS}    //arrow;black small ball//~v6V1I~
//  ,{ 0x2190, 0x2194 ,   UCODETB_SBCS}    //arrow;left,up,right,down,left+right//~v6V1I~
    ,{ 0x2190, 0x2193 ,   UCODETB_WIDE}    //arrow;left,up,right,down,left+right//~v6V1I~
    ,{ 0x2194, 0x2194 ,   UCODETB_SBCS}    //arrow;left,up,right,down,left+right,dup with ambiguous//~v6V1I~
//  ,{ 0x221f, 0x221f ,   UCODETB_SBCS}    //left bottom corner    //~v6V1I~
    ,{ 0x221f, 0x221f ,   UCODETB_WIDE}    //left bottom corner    //~v6V1I~
//  ,{ 0x2640, 0x2640 ,   UCODETB_SBCS}    //femail                //~v6V1I~
    ,{ 0x2640, 0x2640 ,   UCODETB_WIDE}    //femail                //~v6V1I~
//  ,{ 0x2642, 0x2642 ,   UCODETB_SBCS}    //mail                  //~v6V1I~
    ,{ 0x2642, 0x2642 ,   UCODETB_WIDE}    //mail                  //~v6V1I~
//  ,{ 0x2660, 0x2660 ,   UCODETB_SBCS}    //black spade suit      //~v6V1I~
    ,{ 0x2665, 0x2665 ,   UCODETB_SBCS}    //black heart suit,dupwith ambiguous//~v6V1R~
#endif                                                             //~v6V9I~
  #else                                                            //~v6V1I~
     { 0x0000, 0x0000 ,   UCODETB_SBCS}                            //~v640I~
    ,{ 0x00a7, 0x00a7 ,   UCODETB_SBCS}    //chapter               //~v65pM~
    ,{ 0x2022, 0x2022 ,   UCODETB_SBCS}    //arrow;black small ball//~v65pM~
    ,{ 0x2190, 0x2194 ,   UCODETB_SBCS}    //arrow;left,up,right,down,left+right//~v65pR~
    ,{ 0x221f, 0x221f ,   UCODETB_SBCS}    //left bottom corner    //~v65pM~
    ,{ 0x2640, 0x2640 ,   UCODETB_SBCS}    //femail                //~v65pM~
    ,{ 0x2642, 0x2642 ,   UCODETB_SBCS}    //mail                  //~v65pM~
    ,{ 0x2660, 0x2660 ,   UCODETB_SBCS}    //black spade suit      //~v65pM~
    ,{ 0x2665, 0x2665 ,   UCODETB_SBCS}    //black heart suit      //~v65pM~
  #endif                                                           //~v6V1I~
#else     //folowings are SBCS of wcwcdth=2;treated as narrow DBCS by logic//~v640I~
     { 0x00a2, 0x00a3 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00a6, 0x00a6 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00a9, 0x00a9 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00ad, 0x00ad ,   UCODETB_DBCS}                            //~v62UR~
    ,{ 0x00af, 0x00af ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00c0, 0x00c5 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00c7, 0x00cf ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00d1, 0x00d6 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00d9, 0x00dd ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00e2, 0x00e5 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00e7, 0x00e7 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00eb, 0x00eb ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00ee, 0x00ef ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00f1, 0x00f1 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00f4, 0x00f6 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00fb, 0x00fb ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00fd, 0x00fd ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x00ff, 0x00ff ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0100, 0x0100 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0102, 0x010f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0110, 0x0110 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0112, 0x0112 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0116, 0x011a ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x011c, 0x011f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0120, 0x0122 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0124, 0x0125 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0128, 0x012a ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x012e, 0x012f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0130, 0x0130 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0134, 0x0137 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0139, 0x013e ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0143, 0x0143 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0145, 0x0147 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x014c, 0x014c ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0150, 0x0151 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0154, 0x015f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0160, 0x0165 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0168, 0x016a ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x016c, 0x016f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0170, 0x017f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01cd, 0x01cd ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01cf, 0x01cf ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01d1, 0x01d1 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01d3, 0x01d3 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01d5, 0x01d5 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01d7, 0x01d7 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01d9, 0x01d9 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01db, 0x01db ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x01f5, 0x01f5 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0384, 0x0386 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0388, 0x038a ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x038c, 0x038c ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x038e, 0x038f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0390, 0x0390 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x03aa, 0x03af ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x03b0, 0x03b0 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x03c2, 0x03c2 ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x03ca, 0x03ce ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0402, 0x040c ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x040e, 0x040f ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x0452, 0x045c ,   UCODETB_SBCS}                            //~v62UR~
    ,{ 0x045e, 0x045f ,   UCODETB_SBCS}                            //~v62UR~
#endif                                                             //~v640I~
  };                                                               //~v62UR~
    int datatype;                                                  //~v60mR~
//static int Solddatatype;                                           //~v60mI~//~v6VtR~
//static ULONG Solducs;                                              //~v60mI~//~v6VtR~
//*******************************                                  //~v60mR~
//    if (Pucs==Solducs)                                             //~v60mI~//~v6VtR~
//        return Solddatatype;                                       //~v60mI~//~v6VtR~
//    Solducs=Pucs;                                                  //~v60mR~//~v6VtR~
  if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator            //~v62UR~
    datatype=utftbsrch(Pucs,Suctbj_euc_console,sizeof(Suctbj_euc_console)/sizeof(UCODETB));//~v62UR~
  else                                                             //~v62UR~
    datatype=utftbsrch(Pucs,Suctbj_euc,sizeof(Suctbj_euc)/sizeof(UCODETB));//~v60mR~
//    Solddatatype=datatype;                                         //~v60mI~//~v6VtR~
    return datatype;                                               //~v60mR~
}//utftbsrch_jeuc                                                  //~v60mR~
#endif                                                             //~v60fI~
#ifdef LNX                                                         //~v62XI~
//******************************************************           //~v62UR~
//ajust by test other than japanese                              //~v62UR~//~v640R~
//******************************************************           //~v62UR~
int utftbsrch_cjk(ULONG Pucs)                                      //~v62UR~
{                                                                  //~v62UR~
#ifdef UTF8UCS2                                                    //~v640R~
//*specifiy WIDE for wide char of wcwidth=1                        //~v640I~
#ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1I~
    static UCODETB Suctb_utf8[] = {                                //~v6V1I~
//*add wide-sbcs over ambiguous                                    //~v6V9R~
//*add sbcs to deny ambiguous                                      //~v6V9I~
//   { 0x0000, 0x0000 ,   UCODETB_SBCS  } //dummy for line cont    //~v6V1I~//~v6V9R~
//  ,{ 0x00a1, 0x00a1 ,   UCODETB_SBCS  } //i                      //~v6V1I~
//  ,{ 0x00a3, 0x00a3 ,   UCODETB_WIDE  } //i ,sbcs                //~v6V1I~
//  ,{ 0x00a8, 0x00a8 ,   UCODETB_SBCS  } //..                     //~v6V1I~
//  ,{ 0x00aa, 0x00aa ,   UCODETB_SBCS  } //a                      //~v6V1I~
//  ,{ 0x00ad, 0x00ad ,   UCODETB_SBCS  } //soft hyphen(SHY),deny wcwidth=0      //~v6V7I~//~v6V9R~
     { 0x00ad, 0x00ad ,   UCODETB_SBCS  } //soft hyphen(SHY),deny wcwidth=0//~v6V9I~
//  ,{ 0x00ae, 0x00ae ,   UCODETB_SBCS  } //R                      //~v6V1I~
//  ,{ 0x00b0, 0x00b0 ,   UCODETB_SBCS  } //degree                 //~v6V1I~
//  ,{ 0x00b2, 0x00b4 ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x00b6, 0x00d5 ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x00d7, 0x00d7 ,   UCODETB_WIDE  } //X, sbcs                //~v6V1I~
//  ,{ 0x00d8, 0x00f6 ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x00f7, 0x00f7 ,   UCODETB_WIDE  } //divide                 //~v6V1I~
//  ,{ 0x00f8, 0x01c3 ,   UCODETB_SBCS  } //divide                 //~v6V1I~
//  ,{ 0x01c4, 0x01cc ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj, sbcs//~v6V1I~
//  ,{ 0x01cd, 0x01f0 ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x01f1, 0x01f3 ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj ,sbcs//~v6V1I~
//  ,{ 0x01f4, 0x02df ,   UCODETB_SBCS  } //                       //~v6V1I~
    ,{ 0x0250, 0x02af ,   UCODETB_WIDE  } //IPA extension contains wide sbcs//~v6V1I~
    ,{ 0x0372, 0x0372 ,   UCODETB_WIDE  } //                       //~v6V2I~
    ,{ 0x0376, 0x0376 ,   UCODETB_WIDE  } //                       //~v6V2I~
//  ,{ 0x0386, 0x0386 ,   UCODETB_WIDE  } // ,sbcs                 //~v6V1I~
//  ,{ 0x0388, 0x0389 ,   UCODETB_WIDE  } //cn,sbcs                //~v6V1I~
//  ,{ 0x038b, 0x038f ,   UCODETB_WIDE  } //cn , 38b,38d is unprintable(wcwidth=-1)//~v6V1I~
//  ,{ 0x03c2, 0x03c2 ,   UCODETB_WIDE  } //sbcs                   //~v6V1I~
//  ,{ 0x03d0, 0x03d1 ,   UCODETB_WIDE  } //sbcs                   //~v6V1I~
//  ,{ 0x03d5, 0x03d6 ,   UCODETB_WIDE  } //                       //~v6V1I~
//  ,{ 0x03d6, 0x03d6 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~
    ,{ 0x03d0, 0x03ff ,   UCODETB_WIDE  } //                       //~v6V2I~
//  ,{ 0x0401, 0x0401 ,   UCODETB_SBCS  } //                       //~v6V1I~
    ,{ 0x0460, 0x0480 ,   UCODETB_WIDE  } //                       //~v6V2I~
    ,{ 0x0559, 0x055f ,   UCODETB_SBCS  } // in Armenian(530-58f)  //~v6WhI~
    ,{ 0x0589, 0x058a ,   UCODETB_SBCS  } // in Armenian(530-58f)  //~v6WhR~
//  ,{ 0x1160, 0x116f ,   UCODETB_WIDE  } //  @@@@test             //~v6V7R~
//  ,{ 0x1160, 0x116f ,   UCODETB_DBCS  } //  @@@@test             //~v6V7R~
//  ,{ 0x1160, 0x116f ,   UCODETB_COMP  } //  @@@@test   COMPOSIT,width0//~v6V7I~//~v6V9R~
#ifdef GGG  //keep combining on linux                              //~v6X3R~
    ,{ 0x1160, 0x11ff ,   UCODETB_WIDE  } //                       //~v6X3M~
#else                                                              //~v6X3R~
#endif                                                             //~v6X3I~
    ,{ 0x2013, 0x2015 ,   UCODETB_SBCS  } //deny ambiguous:2013-2016//~v6V9I~
//  ,{ 0x201a, 0x201b ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x201e, 0x201e ,   UCODETB_WIDE  } //,sbcs                  //~v6V1I~
//  ,{ 0x2020, 0x2021 ,   UCODETB_SBCS  } //                       //~v6V1I~
    ,{ 0x2024, 0x2024 ,   UCODETB_SBCS  } // deny ambiguous 2024-2027//~v6V9R~
    ,{ 0x2026, 0x2027 ,   UCODETB_SBCS  } // deny ambiguous 2024-2027//~v6V9I~
    ,{ 0x2031, 0x2031 ,   UCODETB_WIDE  } //  widewide(4cell) but  //~v6V9I~
    ,{ 0x203f, 0x203f ,   UCODETB_WIDE  } //                       //~v6V9I~
//  ,{ 0x2042, 0x2042 ,   UCODETB_WIDE  } //sbcs                   //~v6V1I~//~v6V9M~
    ,{ 0x2047, 0x2049 ,   UCODETB_WIDE  } // in General Punctuation(2000-206f)//~v6WhI~
    ,{ 0x2050, 0x2051 ,   UCODETB_WIDE  } // in General Punctuation(2000-206f)//~v6WhI~
    ,{ 0x2053, 0x2055 ,   UCODETB_WIDE  } // in General Punctuation(2000-206f)//~v6WhI~
    ,{ 0x2057, 0x2059 ,   UCODETB_WIDE  } // in General Punctuation(2000-206f)//~v6WhI~
    ,{ 0x205b, 0x205c ,   UCODETB_WIDE  } // in General Punctuation(2000-206f)//~v6WhI~
//  ,{ 0x2074, 0x2074 ,   UCODETB_SBCS  } //                       //~v6V1I~//~v6V9M~
//  ,{ 0x207f, 0x207f ,   UCODETB_SBCS  } //                       //~v6V1I~//~v6V9M~
    ,{ 0x20ac, 0x20ac ,   UCODETB_SBCS  } //  Currency Symbols(20a0-20cf is on ambiguous);20ac=euro     //~v6V2I~//~v6V9R~
    ,{ 0x20ae, 0x20ae ,   UCODETB_SBCS  } //  Currency Symbols     //~v6V9I~
    ,{ 0x20b4, 0x20b4 ,   UCODETB_SBCS  } //  Currency Symbols     //~v6V9I~
    ,{ 0x20b6, 0x20b6 ,   UCODETB_SBCS  } //  Currency Symbols     //~v6V9I~
    ,{ 0x20b9, 0x20b9 ,   UCODETB_SBCS  } //  Currency Symbols     //~v6V9I~
//  ,{ 0x2118, 0x2118 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~
//  ,{ 0x211c, 0x211c ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~
//  ,{ 0x2122, 0x2122 ,   UCODETB_SBCS  } //                       //~v6V1I~
//  ,{ 0x2127, 0x2127 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~
//  ,{ 0x2135, 0x2135 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~
    ,{ 0x2150, 0x2152 ,   UCODETB_WIDE  } //                       //~v6V2I~
//  ,{ 0x2155, 0x2155 ,   UCODETB_WIDE  } //sbcs                   //~v6V1I~
    ,{ 0x216c, 0x216f ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x217a, 0x217b ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x217f, 0x217f ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2180, 0x2183 ,   UCODETB_WIDE  } //                       //~v6V2R~//~v6V9R~
    ,{ 0x2185, 0x2185 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2187, 0x2189 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2194, 0x2194 ,   UCODETB_SBCS}    //deny ambiguous 2190-2199//~v6V9R~
    ,{ 0x2196, 0x2199 ,   UCODETB_SBCS}    //deny ambiguous 2190-2199//~v6V9R~
    ,{ 0x219a, 0x219f ,   UCODETB_WIDE}    //                      //~v6V9I~
    ,{ 0x21a0, 0x21b7 ,   UCODETB_WIDE}    //21b0-21b9 is ambiguous/~v6V9I~//~v6V9R~
    ,{ 0x21ba, 0x21c3 ,   UCODETB_WIDE}    //                      //~v6V9I~
//  ,{ 0x21c4, 0x21c4 ,   UCODETB_WIDE  } //cn,sbcs                //~v6V1I~
    ,{ 0x21c5, 0x21d1 ,   UCODETB_WIDE}    //                      //~v6V9R~
    ,{ 0x21d3, 0x21d3 ,   UCODETB_WIDE}    //                      //~v6V9I~
    ,{ 0x21d5, 0x21e5 ,   UCODETB_WIDE}    //                      //~v6V9R~
    ,{ 0x21ea, 0x21ff ,   UCODETB_WIDE}    //                      //~v6V9R~
    ,{ 0x2201, 0x2201 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V2R~//~v6V9R~
    ,{ 0x2202, 0x2202 ,   UCODETB_SBCS  } //deny ambiguous:2202-2203//~v6V9R~
    ,{ 0x2205, 0x2205 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x220c, 0x220c ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2210, 0x2210 ,   UCODETB_WIDE  } //                   //~v6V1I~//~v6V2R~//~v6V9R~
    ,{ 0x2214, 0x2214 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2217, 0x2217 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x221b, 0x221c ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x221e, 0x221e ,   UCODETB_SBCS  } //deny ambiguous 2210-2220//~v6V9R~
    ,{ 0x2221, 0x2222 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2226, 0x2226 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x222b, 0x222b ,   UCODETB_SBCS  } //deny ambiguous 2227-222c//~v6V9R~
    ,{ 0x222d, 0x222d ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x222f, 0x222f ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2230, 0x2230 ,   UCODETB_WIDE  } //                       //~v6V9R~
    ,{ 0x2236, 0x2236 ,   UCODETB_SBCS  } //deny ambiguous 2234-2237//~v6V9I~
    ,{ 0x2238, 0x223b ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x223e, 0x223f ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2241, 0x2247 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2249, 0x224b ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x224d, 0x225f ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2260, 0x2260 ,   UCODETB_SBCS  } //deny ambigyuous 2260-2261//~v6V9I~
    ,{ 0x2262, 0x2263 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2264, 0x2265 ,   UCODETB_SBCS  } //deny ambigyuous 2264-2267//~v6V9I~
    ,{ 0x2268, 0x2269 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x226d, 0x226d ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2270, 0x2281 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2284, 0x2285 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2288, 0x2294 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2296, 0x2298 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x229a, 0x22a4 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x22a8, 0x22b9 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x22bb, 0x22be ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x22c0, 0x22c3 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x22c7, 0x22ff ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2300, 0x2302 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2305, 0x230b ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2311, 0x2311 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2315, 0x2317 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x231c, 0x2323 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2334, 0x2335 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x233d, 0x2340 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2345, 0x2346 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2349, 0x234b ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x234e, 0x234f ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2351, 0x2352 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2355, 0x2356 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2358, 0x235d ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x235f, 0x235f ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2361, 0x236e ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2371, 0x2373 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2376, 0x237a ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x237f, 0x2380 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2386, 0x2386 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x238d, 0x2393 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2396, 0x2396 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x239b, 0x23a6 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23b7, 0x23b7 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23ba, 0x23bd ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23d0, 0x23d0 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23de, 0x23df ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23e2, 0x23e2 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23e4, 0x23e4 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23e6, 0x23e6 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23e8, 0x23e8 ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x23fd, 0x23fd ,   UCODETB_SBCS  } //over ambiguous_non_lang 2300-23ff//~v6V9I~
    ,{ 0x2500, 0x2500 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2502, 0x2502 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2504, 0x250e ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2510, 0x2512 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2514, 0x2516 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2518, 0x251a ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x251c, 0x251c ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x251e, 0x251f ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2521, 0x2522 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2524, 0x2524 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2526, 0x2527 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2529, 0x252a ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x252c, 0x252e ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2531, 0x2532 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2534, 0x2536 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9R~
    ,{ 0x2539, 0x253a ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x253c, 0x253e ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2540, 0x2541 ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x2543, 0x254a ,   UCODETB_SBCS  } //over ambiguous 24eb-254b(24eb-24ff is on ambiguous_non_lang)//~v6V9I~
    ,{ 0x25a2, 0x25a2 ,   UCODETB_WIDE  } //                       //~v6V1I~
    ,{ 0x25aC, 0x25aD ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25B0, 0x25B0 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25BA, 0x25BB ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25C4, 0x25C5 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25cC, 0x25cD ,   UCODETB_WIDE  } //sbcs                   //~v6V1I~//~v6V9R~
    ,{ 0x25d0, 0x25d1 ,   UCODETB_SBCS  } //deny ambiguous 25ce-25d1/~v6V1I~//~v6V9R~
    ,{ 0x25d4, 0x25d5 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25d8, 0x25db ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25e0, 0x25e1 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25e7, 0x25ee ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x25f0, 0x25ff ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2600, 0x2604 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V9R~
    ,{ 0x2608, 0x2608 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x260a, 0x260d ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2610, 0x2612 ,   UCODETB_WIDE  } //                       //~v6V1I~//~v6V9R~
    ,{ 0x2616, 0x261b ,   UCODETB_WIDE  } //                       //~v6V9R~
    ,{ 0x261d, 0x261d ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x261f, 0x2627 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2629, 0x263e ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2641, 0x2641 ,   UCODETB_WIDE  } //                       //~v6V1I~
    ,{ 0x2643, 0x265f ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2667, 0x2667 ,   UCODETB_SBCS  } //deny ambiguous 2667-266a//~v6V9I~
    ,{ 0x2669, 0x2669 ,   UCODETB_SBCS  } //deny ambiguous 2667-266a//~v6V9I~
    ,{ 0x266c, 0x266c ,   UCODETB_SBCS  } //deny ambiguous 266c-266d//~v6V9I~
    ,{ 0x2670, 0x2694 ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2696, 0x26ff ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2700, 0x273c ,   UCODETB_WIDE  } //                       //~v6V9R~
    ,{ 0x273e, 0x275a ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2760, 0x27bf ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x27cb, 0x27cb ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x27cd, 0x27cd ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x27da, 0x27de ,   UCODETB_WIDE  } //                       //~v6V9I~
    ,{ 0x2e0f, 0x2e11 ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e1f, 0x2e1f ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e26, 0x2e27 ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e2a, 0x2e2d ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e3a, 0x2e3b ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e3f, 0x2e3f ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x2e43, 0x2e43 ,   UCODETB_WIDE  } //                       //~v6WhI~
    ,{ 0x303f, 0x303f ,   UCODETB_WIDE  } // 303f:wcwidth=1 and mk_wcwidth=1//~v6V1I~//~v6V9R~
    ,{ 0xfb00, 0xfb02 ,   UCODETB_SBCS  } // over fb00-fb4f(ambiguous_lang), ligature of ff/fi/fl//~v6V9I~
    ,{ 0xfffc, 0xfffc ,   UCODETB_WIDE  } // over ambiguous fff0-ffff//~v6V9I~
     };                                                            //~v6V1I~
#else                                                              //~v6V1I~
    static UCODETB Suctb_utf8[] = {                                //~v640R~
     { 0x0000, 0x0000 ,   UCODETB_SBCS  } //dummy for line cont    //~v640R~
    ,{ 0x00a1, 0x00a1 ,   UCODETB_SBCS  } //i                      //~v640R~
    ,{ 0x00a3, 0x00a3 ,   UCODETB_WIDE  } //i                      //~v640I~
    ,{ 0x00a8, 0x00a8 ,   UCODETB_SBCS  } //..                     //~v640I~
    ,{ 0x00aa, 0x00aa ,   UCODETB_SBCS  } //a                      //~v640I~
    ,{ 0x00ae, 0x00ae ,   UCODETB_SBCS  } //R                      //~v640I~
    ,{ 0x00b0, 0x00b0 ,   UCODETB_SBCS  } //degree                 //~v640I~
    ,{ 0x00b2, 0x00b4 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x00b6, 0x00d5 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x00d7, 0x00d7 ,   UCODETB_WIDE  } //X                      //~v640R~
    ,{ 0x00d8, 0x00f6 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x00f7, 0x00f7 ,   UCODETB_WIDE  } //divide                 //~v640I~
    ,{ 0x00f8, 0x01c3 ,   UCODETB_SBCS  } //divide                 //~v640I~
    ,{ 0x01c4, 0x01cc ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj//~v640I~
    ,{ 0x01cd, 0x01f0 ,   UCODETB_SBCS  } //                       //~v640M~
    ,{ 0x01f1, 0x01f3 ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj//~v640I~
    ,{ 0x01f4, 0x02df ,   UCODETB_SBCS  } //                       //~v640M~
    ,{ 0x0386, 0x0386 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x0388, 0x0389 ,   UCODETB_WIDE  } //cn                     //~v640R~
    ,{ 0x038b, 0x038f ,   UCODETB_WIDE  } //cn                     //~v640I~
    ,{ 0x03c2, 0x03c2 ,   UCODETB_WIDE  } //                       //~v640R~
    ,{ 0x03d0, 0x03d1 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x03d5, 0x03d6 ,   UCODETB_WIDE  } //                       //~v640R~
    ,{ 0x0401, 0x0401 ,   UCODETB_SBCS  } //                       //~v640R~
//  ,{ 0x0451, 0x0451 ,   UCODETB_SBCS  } //cn                     //~v640I~
//  ,{ 0x2013, 0x2014 ,   UCODETB_SBCS  } //CN-utf8                //~v640R~
    ,{ 0x201a, 0x201b ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x201e, 0x201e ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2020, 0x2021 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2024, 0x2024 ,   UCODETB_SBCS  } //                       //~v640I~
//  ,{ 0x203e, 0x203e ,   UCODETB_SBCS  } //cn-utf8                //~v640R~
    ,{ 0x2042, 0x2042 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2074, 0x2074 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x207f, 0x207f ,   UCODETB_SBCS  } //                       //~v640I~
//  ,{ 0x20ac, 0x20ac ,   UCODETB_SBCS  } //cn                     //~v640R~
//  ,{ 0x2116, 0x2116 ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2118, 0x2118 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x211c, 0x211c ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2122, 0x2122 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2127, 0x2127 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2135, 0x2135 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2155, 0x2155 ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x215b, 0x215e ,   UCODETB_SBCS  } //                       //~v640R~
//  ,{ 0x217a, 0x217b ,   UCODETB_WIDE  } //to mk_cjk              //~v640R~
//  ,{ 0x2190, 0x2194 ,   UCODETB_SBCS  } //cn                     //~v640R~
//  ,{ 0x21d0, 0x21d0 ,   UCODETB_WIDE  } //to mk_cjk              //~v640R~
    ,{ 0x21c4, 0x21c4 ,   UCODETB_WIDE  } //cn                     //~v640I~
    ,{ 0x21cc, 0x21cc ,   UCODETB_WIDE  } //cn                     //~v640I~
    ,{ 0x21e6, 0x21e9 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2202, 0x2202 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2205, 0x2206 ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x220f, 0x220f ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2211, 0x2211 ,   UCODETB_WIDE  } //                       //~v640R~
    ,{ 0x2215, 0x2215 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2217, 0x2217 ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x221e, 0x221f ,   UCODETB_SBCS  } //cn                     //~v640R~
//  ,{ 0x2229, 0x2229 ,   UCODETB_SBCS  } //cn                     //~v640R~
//  ,{ 0x222b, 0x222b ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x222d, 0x222d ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x223c, 0x223c ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2243, 0x2243 ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x2260, 0x2265 ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2272, 0x2273 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2296, 0x2298 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x229e, 0x229e ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x22a0, 0x22a0 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2307, 0x2307 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x24ea, 0x24ea ,   UCODETB_WIDE  } //                       //~v640R~
    ,{ 0x2500, 0x2500 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2502, 0x2502 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x250c, 0x250c ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2510, 0x2510 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2514, 0x2514 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2518, 0x2518 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x251c, 0x251c ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2524, 0x2524 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x252c, 0x252c ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x2534, 0x2534 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x253c, 0x253c ,   UCODETB_SBCS  } //                       //~v640R~
//  ,{ 0x2550, 0x256c ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2574, 0x2574 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2580, 0x2580 ,   UCODETB_SBCS  } //                       //~v640I~
//  ,{ 0x25a0, 0x25a0 ,   UCODETB_SBCS  } //                       //~v640R~
    ,{ 0x25a2, 0x25a2 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x25b1, 0x25b1 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x25c9, 0x25c9 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x25d2, 0x25d3 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x25e6, 0x25e6 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2600, 0x2603 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x261b, 0x261b ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x2640, 0x2640 ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2641, 0x2641 ,   UCODETB_WIDE  } //                       //~v640I~
//  ,{ 0x2642, 0x2642 ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x2660, 0x2660 ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2662, 0x2662 ,   UCODETB_WIDE  } //                       //~v640I~
    ,{ 0x2663, 0x2663 ,   UCODETB_SBCS  } //                       //~v640I~
//  ,{ 0x2665, 0x2665 ,   UCODETB_SBCS  } //cn                     //~v640R~
    ,{ 0x266a, 0x266a ,   UCODETB_SBCS  } //                       //~v640I~
    ,{ 0x2700, 0x27bf ,   UCODETB_WIDE  } //                       //~v640R~
     };                                                            //~v640R~
#endif                                                             //~v6V1I~
//*for XXE test result on FC12                                     //~v655R~
    static UCODETB Suctb_utf8_XXE[] = {                            //~v655R~
     { 0x0000, 0x0000 ,   UCODETB_SBCS  } //dummy for line cont    //~v655R~
//  ,{ 0x00a1, 0x00a1 ,   UCODETB_SBCS  } //i                      //~v655R~//~v6V9R~
//  ,{ 0x01c4, 0x01cc ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj//~v655R~//~v6V9R~
//  ,{ 0x01c4, 0x01c7 ,   UCODETB_WIDE  } //                       //~v6V9I~//~v6WnR~
    ,{ 0x01c4, 0x01c6 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x01c7, 0x01cc ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x01ca, 0x01cb ,   UCODETB_WIDE  } //                       //~v6V9I~//~v6WnR~
    ,{ 0x01f1, 0x01f3 ,   UCODETB_WIDE  } //                       //~v6V9R~
//  ,{ 0x01f6, 0x01f6 ,   UCODETB_WIDE  } //                       //~v6V9I~//~v6WnR~
    ,{ 0x0250, 0x02af ,   UCODETB_WIDE  } //=Console,IPA extension contains wide sbcs//~v6WnI~
    ,{ 0x0372, 0x0372 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x0376, 0x0376 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x03d0, 0x03ff ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x0409, 0x040a ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x042e, 0x042e ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x0460, 0x0480 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x04a6, 0x04a7 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x0559, 0x055f ,   UCODETB_SBCS  } // in Armenian(530-58f)  //~v6WnR~
    ,{ 0x0589, 0x058a ,   UCODETB_SBCS  } // in Armenian(530-58f)  //~v6WnR~
    ,{ 0x1f28, 0x1f2f ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x1faa, 0x1faf ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x2025, 0x2025 ,   UCODETB_WIDE  } //3 dot                  //~v6WnI~
//  ,{ 0x2031, 0x2031 ,   UCODETB_WIDE  } // 1/000                 //~v655I~//~v6WkR~
//  ,{ 0x2030, 0x2031 ,   UCODETB_WIDE  } // 1/000                 //~v6WkI~//~v6WnR~
    ,{ 0x2031, 0x2031 ,   UCODETB_WIDE  } // 1/000                 //~v6WnI~
    ,{ 0x203b, 0x203b ,   UCODETB_WIDE  } // =ambiguous            //~v6WnI~
    ,{ 0x203e, 0x203e ,   UCODETB_WIDE  } // =ambiguous            //~v6WnI~
//  ,{ 0x2042, 0x2042 ,   UCODETB_WIDE  } //                       //~v655R~//~v6WkR~
    ,{ 0x2047, 0x2049 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2050, 0x2051 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2053, 0x2055 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x205b, 0x205c ,   UCODETB_WIDE  } //=Console               //~v6WnI~
//  ,{ 0x20a7, 0x20a8 ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x20af, 0x20af ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
    ,{ 0x20a0, 0x20cf ,   UCODETB_WIDE  } //=ambiguous no lang     //~v6WnI~
//  ,{ 0x2100, 0x2101 ,   UCODETB_WIDE  } //                       //~v655I~//~v6WnR~
//  ,{ 0x2103, 0x2103 ,   UCODETB_WIDE  } //                       //~v655I~//~v6WkR~
//  ,{ 0x2105, 0x2106 ,   UCODETB_WIDE  } //                       //~v655I~//~v6WnR~
//  ,{ 0x210b, 0x210c ,   UCODETB_WIDE  } //                       //~v655I~//~v6WkR~
//  ,{ 0x211c, 0x211c ,   UCODETB_WIDE  } //                       //~v655R~//~v6WkR~
//  ,{ 0x2121, 0x2121 ,   UCODETB_WIDE  } //                       //~v655I~//~v6WnR~
//  ,{ 0x213b, 0x213b ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x214d, 0x214d ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2100, 0x214f ,   UCODETB_WIDE  } //=ambiguous no lang     //~v6WnI~
    ,{ 0x2150, 0x2152 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2100, 0x2152 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
//  ,{ 0x2153, 0x215e ,   UCODETB_WIDE  } //                       //~v655I~//~v6WkR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2160, 0x216b ,   UCODETB_WIDE  } //=ambiguous             //~v6WnI~
    ,{ 0x216c, 0x216f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2170, 0x2179 ,   UCODETB_WIDE  } //=ambiguous             //~v6WnR~
    ,{ 0x217a, 0x217b ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2160, 0x217b ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x217f, 0x217f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
//  ,{ 0x2180, 0x2182 ,   UCODETB_WIDE  } //del 2181               //~v655I~//~v6WkR~
    ,{ 0x2180, 0x2180 ,   UCODETB_WIDE  } //                       //~v6WkI~
#else                                                              //~v6WnI~
    ,{ 0x217f, 0x2180 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2182, 0x2182 ,   UCODETB_WIDE  } //                       //~v6WkI~
//  ,{ 0x2187, 0x2188 ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2187, 0x2189 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2190, 0x2193 ,   UCODETB_WIDE  } //=ambiguous of 2190-2199//~v6WnR~
    ,{ 0x219a, 0x219f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x21a0, 0x21b7 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x21b8, 0x21b9 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x21ba, 0x21c3 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x21a0, 0x21c3 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x21c5, 0x21d1 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x21d2, 0x21d2 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x21d3, 0x21d3 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x21d4, 0x21d4 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x21d5, 0x21e5 ,   UCODETB_WIDE  } //=Console               //~v6WnR~
#else                                                              //~v6WnI~
    ,{ 0x21c5, 0x21e5 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x21ea, 0x21ff ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2200, 0x2200 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2201, 0x2201 ,   UCODETB_WIDE  } //=Console               //~v6WnR~
#else                                                              //~v6WnI~
    ,{ 0x21ea, 0x2201 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2203, 0x2203 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2205, 0x2205 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2207, 0x2208 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x220b, 0x220b ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x220c, 0x220c ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x220b, 0x220c ,   UCODETB_WIDE  } //                       //~v6WnR~
#endif                                                             //~v6WnI~
    ,{ 0x2214, 0x2214 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2217, 0x2217 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x221d, 0x221d ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
    ,{ 0x221f, 0x2220 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2227, 0x222a ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x222c, 0x222c ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x222d, 0x222d ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x222e, 0x222e ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x222f, 0x222f ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x2230, 0x2230 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x222c, 0x2230 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2234, 0x2235 ,   UCODETB_WIDE  } //=Ambiguous of 2234-2237//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2237, 0x2237 ,   UCODETB_WIDE  } //=Ambiguous of 2234-2237//~v6WnR~
    ,{ 0x2238, 0x223b ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x223c, 0x223d ,   UCODETB_WIDE  } //=Ambigouous            //~v6WnI~
    ,{ 0x223e, 0x223f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2237, 0x223f ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2241, 0x2247 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
//  ,{ 0x2248, 0x2248 ,   UCODETB_WIDE  } //                       //~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2249, 0x224b ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x224c, 0x224c ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x224d, 0x225f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2249, 0x225f ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2261, 0x2261 ,   UCODETB_WIDE  } //=Ambiguous of 2260-2261//~v6WnR~
    ,{ 0x2262, 0x2263 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2261, 0x2263 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2266, 0x2267 ,   UCODETB_WIDE  } //=Ambiguous of 2264-2267//~v6WnR~
    ,{ 0x2268, 0x2269 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x226a, 0x226b ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2266, 0x226b ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x226d, 0x226d ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x226e, 0x226f ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2270, 0x2281 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2282, 0x2283 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2284, 0x2285 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2286, 0x2287 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2288, 0x2294 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2295, 0x2295 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2296, 0x2298 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2299, 0x2299 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x229a, 0x22a4 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x22a5, 0x22a5 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x226d, 0x22a5 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x22a8, 0x22b9 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x22bb, 0x22be ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x22bf, 0x22bf ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x22c0, 0x22c3 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x22bb, 0x22c3 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
//  ,{ 0x22c7, 0x22ff ,   UCODETB_WIDE  } //=Console               //~v6WnR~
//  ,{ 0x22d8, 0x22d9 ,   UCODETB_WIDE  } // out of 22c7-22ff(=Console)//~v6WnR~
    ,{ 0x22c7, 0x22ff ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2312, 0x2312 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
    ,{ 0x2313, 0x2314 ,   UCODETB_WIDE  } //                       //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2312, 0x2314 ,   UCODETB_WIDE  } //                       //~v6WnR~
#endif                                                             //~v6WnI~
    ,{ 0x2318, 0x2318 ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x231a, 0x231b ,   UCODETB_SBCSF } //                       //~v6WkR~//~v6WnR~
    ,{ 0x231a, 0x231b ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x2324, 0x2328 ,   UCODETB_WIDE  } //                       //~v6WkI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x232b, 0x232b ,   UCODETB_WIDE  } //                       //~v6WkI~
    ,{ 0x232c, 0x2333 ,   UCODETB_WIDE  } //                       //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x232b, 0x2333 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2374, 0x2375 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x237b, 0x237d ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x2387, 0x2387 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x2394, 0x2394 ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x23b8, 0x23cc ,   UCODETB_WIDE  } //                       //~v6WnR~
    ,{ 0x23b8, 0x23b9 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x23be, 0x23cc ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x23ce, 0x23cf ,   UCODETB_WIDE  } //                       //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x23d4, 0x23d6 ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x23d7, 0x23e5 ,   UCODETB_WIDE  } //                       //~v6WnR~
    ,{ 0x23d7, 0x23dd ,   UCODETB_WIDE  } //                       //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x23d4, 0x23dd ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x23e0, 0x23e1 ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x23e3, 0x23e3 ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x23e9, 0x23ec ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x23f1, 0x23f2 ,   UCODETB_WIDE  } //                       //~v6WnI~
//  ,{ 0x23f3, 0x23f3 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x23fb, 0x23ff ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x2400, 0x243f ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
    ,{ 0x2440, 0x245f ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
    ,{ 0x2460, 0x24ea ,   UCODETB_WIDE  } //                       //~v655I~
    ,{ 0x24eb, 0x24ff ,   UCODETB_WIDE  } //=Ambiguous of 24eb-254b//~v6WnR~
#else                                                              //~v6WnI~
    ,{ 0x23fb, 0x24ff ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2501, 0x2501 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2503, 0x2503 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x250f, 0x250f ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2513, 0x2513 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2517, 0x2517 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x251b, 0x251b ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x251d, 0x251d ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2520, 0x2520 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2523, 0x2523 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2525, 0x2525 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2528, 0x2528 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x252b, 0x252b ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x252f, 0x2530 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2533, 0x2533 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2537, 0x2538 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x253b, 0x253b ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x253f, 0x253f ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x2542, 0x2542 ,   UCODETB_WIDE  } //      "                //~v6WnR~
    ,{ 0x254b, 0x254b ,   UCODETB_WIDE  } //      "                //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x25a0, 0x25a1 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
    ,{ 0x25a2, 0x25a2 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x25a3, 0x25a9 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x25a0, 0x25a9 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x25ac, 0x25ad ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25b0, 0x25b0 ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25b2, 0x25b3 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
    ,{ 0x25ba, 0x25bd ,   UCODETB_WIDE  } //=Console               //~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x25c4, 0x25c5 ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25c6, 0x25c8 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x25c4, 0x25c8 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x25cb, 0x25cb ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnR~
    ,{ 0x25cc, 0x25cd ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x25ce, 0x25cf ,   UCODETB_WIDE  } //=Ambiguous of 25ce-25d1//~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x25cb, 0x25cf ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x25d4, 0x25d5 ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25d8, 0x25db ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25de, 0x25de ,   UCODETB_WIDE  } //                       //~v6WnI~
    ,{ 0x25e0, 0x25e1 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x25e2, 0x25e5 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x25e7, 0x25ee ,   UCODETB_WIDE  } //=Console               //~v6WnR~
    ,{ 0x25ef, 0x25ef ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x25e7, 0x25ef ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
//  ,{ 0x25fd, 0x25fe ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x25f0, 0x25ff ,   UCODETB_WIDE  } //=Console               //~v6WnR~
//  ,{ 0x2600, 0x2603 ,   UCODETB_WIDE  } //                       //~v655R~//~v6WnR~
    ,{ 0x2600, 0x2604 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2605, 0x2606 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x25f0, 0x2606 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2608, 0x2608 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2609, 0x2609 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2608, 0x2609 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x260a, 0x260d ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x260e, 0x260f ,   UCODETB_WIDE  } //=Ambiguous             //~v655I~//~v6WnR~
    ,{ 0x2610, 0x2612 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x260a, 0x2612 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
//  ,{ 0x2614, 0x2615 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2614, 0x2615 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2616, 0x261b ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x261c, 0x261c ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x261d, 0x261d ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x261e, 0x261e ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x261f, 0x2627 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2614, 0x2627 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2629, 0x263e ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x2640, 0x2640 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2641, 0x2641 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2642, 0x2642 ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2643, 0x265f ,   UCODETB_WIDE  } //=Console               //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x2640, 0x265f ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
//  ,{ 0x2648, 0x2653 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2668, 0x2668 ,   UCODETB_WIDE  } //=Ambiguous of 2667-266a//~v6WnI~
    ,{ 0x266a, 0x266a ,   UCODETB_WIDE  } //=Ambiguous of 2667-266a//~v6WnI~
    ,{ 0x266d, 0x266d ,   UCODETB_WIDE  } //=Ambiguous of 266c-266d//~v6WnI~
    ,{ 0x266f, 0x266f ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
    ,{ 0x2670, 0x2694 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
//  ,{ 0x267f, 0x267f ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2693, 0x2693 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2696, 0x26a0 ,   UCODETB_WIDE  } //=Console of 2696-26ff  //~v6WnI~
//  ,{ 0x26a1, 0x26a1 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x26a2, 0x26ff ,   UCODETB_WIDE  } //=Console of 2696-26ff  //~v6WnI~
//  ,{ 0x26a3, 0x26a4 ,   UCODETB_WIDE  } //                       //~v6WnR~
//  ,{ 0x26aa, 0x26ab ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2705, 0x2705 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x270a, 0x270b ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2728, 0x2728 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2700, 0x2709 ,   UCODETB_WIDE  } //=Console of 2700-273c  //~v6WnI~
    ,{ 0x270c, 0x273c ,   UCODETB_WIDE  } //=Console of 2700-273c  //~v6WnI~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x273d, 0x273d ,   UCODETB_WIDE  } //=Ambiguous             //~v6WnI~
//  ,{ 0x274c, 0x274e ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2753, 0x2755 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x273e, 0x2752 ,   UCODETB_WIDE  } //=Console of 273e-275a  //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x273d, 0x2752 ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2756, 0x275a ,   UCODETB_WIDE  } //  "                    //~v6WnI~
//  ,{ 0x2757, 0x2757 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2760, 0x2794 ,   UCODETB_WIDE  } //=Console of 2760-27bf  //~v6WnI~
//  ,{ 0x2795, 0x2797 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x27b0, 0x27b0 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2798, 0x27af ,   UCODETB_WIDE  } //=Console of 2760-27bf  //~v6WnI~
    ,{ 0x27b1, 0x27bf ,   UCODETB_WIDE  } //=Console of 2760-27bf  //~v6WnI~
    ,{ 0x27cb, 0x27cb ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x27cd, 0x27cd ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x27da, 0x27de ,   UCODETB_WIDE  } //=Console               //~v6WnI~
//  ,{ 0x27f4, 0x27ff ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
#ifdef AAA                                                         //~v6WnI~
    ,{ 0x27f0, 0x27ff ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
    ,{ 0x2800, 0x28ff ,   UCODETB_WIDE  } // tenji                 //~v6WkI~
//  ,{ 0x29df, 0x29df ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2900, 0x297f ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
    ,{ 0x2980, 0x29ff ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
//  ,{ 0x2a0c, 0x2a0c ,   UCODETB_WIDE  } //                       //~v6WnR~
//  ,{ 0x2a4a, 0x2a4b ,   UCODETB_WIDE  } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2aa5, 0x2aa5 ,   UCODETB_WIDE  } //                       //~v6WnR~
//  ,{ 0x2af7, 0x2af8 ,   UCODETB_WIDE  } //                       //~v6WnR~
    ,{ 0x2a00, 0x2aff ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
//  ,{ 0x2b1b, 0x2b1c ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
//  ,{ 0x2b24, 0x2b24 ,   UCODETB_WIDE  } //                       //~v6WnR~
//  ,{ 0x2b32, 0x2b33 ,   UCODETB_WIDE  } //                       //~v6WnR~
//  ,{ 0x2b50, 0x2b50 ,   UCODETB_SBCSF } //                       //~v6WkI~//~v6WnR~
    ,{ 0x2b00, 0x2bff ,   UCODETB_WIDE  } //=Ambiguous no lang     //~v6WnI~
#else                                                              //~v6WnI~
    ,{ 0x27f0, 0x2bff ,   UCODETB_WIDE  } //                       //~v6WnI~
#endif                                                             //~v6WnI~
    ,{ 0x2e0f, 0x2e11 ,   UCODETB_WIDE  } //=Console               //~v6WnI~
    ,{ 0x2e1f, 0x2e1f ,   UCODETB_WIDE  } //  "                    //~v6WnI~
    ,{ 0x2e26, 0x2e27 ,   UCODETB_WIDE  } //  "                    //~v6WnI~
    ,{ 0x2e2a, 0x2e2d ,   UCODETB_WIDE  } //  "                    //~v6WnI~
    ,{ 0x2e3a, 0x2e3b ,   UCODETB_WIDE  } //  "                    //~v6WkI~//~v6WnR~
    ,{ 0x2e3f, 0x2e3f ,   UCODETB_WIDE  } //  "                    //~v6WnI~
    ,{ 0x2e43, 0x2e43 ,   UCODETB_WIDE  } //  "                    //~v6WnI~
    ,{ 0xd7b0, 0xd7fb ,   UCODETB_WIDE  } //  "                    //~v6WnI~
#ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1I~
//gaiji(private use area);for console,defined on ambiguose, define in this for xxe to reduce sbcsid//~v6V1I~
    ,{ 0xe000, 0xf8ff ,   UCODETB_WIDE  } // gaiji(private use area);for console,defined on ambiguose, define in this for xxe//~v6V1R~
#endif                                                             //~v6V1I~
    ,{ 0xfb00, 0xfb02 ,   UCODETB_SBCS  } // over fb00-fb4f(ambiguous_lang), ligature of ff/fi/fl//~v6WnI~
    ,{ 0xfffc, 0xfffc ,   UCODETB_WIDE  } // =Console              //~v6WnI~
     };                                                            //~v655R~
#endif //UTF8UCS2                                                  //~v640R~
    static UCODETB Suctb_cjk[] = {                                 //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
       { 0x0000, 0x0000 ,   UCODETB_SBCS  } //dummy for line cont  //~v640I~
#else        //by logic; treate wcwidth<=0 as unprintable,wcwith=2 as sbcs of 2 column//~v640I~
     { 0x00ad, 0x00ad ,   UCODETB_SBCS}                            //~v62UR~
#endif                                                             //~v640I~
  };                                                               //~v62UR~
    static UCODETB Suctb_cjk_console[] = {                         //~v62UR~
       { 0x0000, 0x0000 ,   UCODETB_SBCS  } //dummy for line cont  //~v62UR~
#ifdef UTF8UCS2                                                    //~v640R~
      ,{ 0xFF61, 0xFF9F ,   UCODETB_SBCS  } //katakana             //~v640R~
#else        //by logic; treate wcwidth<=0 as unprintable,wcwith=2 as sbcs of 2 column//~v640R~
//    ,{ 0x0080, 0x009f ,   UCODETB_SBCS  } //test unprintable     //~v62UR~
//    ,{ 0x00a3, 0x00a3 ,   UCODETB_WIDE  } //fontw=2 SBCS;  pond  //~v62UR~
      ,{ 0x00ad, 0x00ad ,   UCODETB_DBCS  } //NBSP                 //~v62UR~
//    ,{ 0x01c4, 0x01cc ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz,LJ,Lj,lj,NJ,Nj,nj//~v62UR~
//    ,{ 0x01f1, 0x01f3 ,   UCODETB_WIDE  } //fontw=2 SBCS;  DZ,Dz,dz//~v62UR~
      ,{ 0x01f9, 0x01f9 ,   UCODETB_NARROW} //dbcs but curces width=1//~v62UR~
//    ,{ 0x0270, 0x0271 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0273, 0x0273 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0289, 0x0289 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x028d, 0x028d ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0298, 0x0298 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x02c8, 0x02c8 ,   UCODETB_WIDE  } //fontw=2 SBCS;  '     //~v62UR~
//    ,{ 0x02ea, 0x02eb ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0300, 0x036f ,   UCODETB_DBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0386, 0x0386 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0389, 0x0389 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x038c, 0x038c ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x038e, 0x038f ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x03a2, 0x03a2 ,   UCODETB_UNPF  } //unprintable sbcs;avoid column expand//~v62UR~
//    ,{ 0x03d0, 0x03d1 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x03d5, 0x03d6 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x03f5, 0x03f5 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0483, 0x0486 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0488, 0x0489 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0591, 0x05bd ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x05BF, 0x05BF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x05C1, 0x05C2 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x05C4, 0x05C5 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x05C7, 0x05C7 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0600, 0x0603 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0610, 0x0615 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0633, 0x0638 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0641, 0x0644 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0646, 0x0646 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0649, 0x064A ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x064B, 0x065E ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x066e, 0x066f ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0670, 0x0670 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
 //   ,{ 0x0671, 0x06d5 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x06D6, 0x06E4 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x06d6, 0x06e4 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x06e5, 0x06e6 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x06E7, 0x06E8 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x06e7, 0x06e8 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x06e9, 0x06e9 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x06EA, 0x06ED ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x06ea, 0x06ed ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x06f0, 0x06fe ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x070F, 0x070F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0711, 0x0711 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0730, 0x074A ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x07A6, 0x07B0 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x07EB, 0x07F3 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0901, 0x0902 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x093C, 0x093C ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0941, 0x0948 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x094D, 0x094D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0951, 0x0954 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0962, 0x0963 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0981, 0x0981 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x09BC, 0x09BC ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x09C1, 0x09C4 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x09CD, 0x09CD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x09E2, 0x09E3 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A01, 0x0A02 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A3C, 0x0A3C ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A41, 0x0A42 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A47, 0x0A48 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A4B, 0x0A4D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A70, 0x0A71 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0A81, 0x0A82 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0ABC, 0x0ABC ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0AC1, 0x0AC5 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0AC7, 0x0AC8 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0ACD, 0x0ACD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0AE2, 0x0AE3 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B01, 0x0B01 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B3C, 0x0B3C ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B3F, 0x0B3F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B41, 0x0B43 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B4D, 0x0B4D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B56, 0x0B56 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0B82, 0x0B82 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0BC0, 0x0BC0 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0BCD, 0x0BCD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0C3E, 0x0C40 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0C46, 0x0C48 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0C4A, 0x0C4D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0C55, 0x0C56 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0CBC, 0x0CBC ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0CBF, 0x0CBF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0CC6, 0x0CC6 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0CCC, 0x0CCD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0CE2, 0x0CE3 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0D41, 0x0D43 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0D4D, 0x0D4D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0DCA, 0x0DCA ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0DD2, 0x0DD4 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0DD6, 0x0DD6 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0E31, 0x0E31 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0E34, 0x0E3A ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0E47, 0x0E4E ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0e80, 0x0eb0 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0EB1, 0x0EB1 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0eb1, 0x0eb1 ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0eb2, 0x0eb3 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0EB4, 0x0EB9 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0eb4, 0x0eb9 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0EBB, 0x0EBC ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0ebb, 0x0ebc ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0ebd, 0x0ebd ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0ec0, 0x0ec7 ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0EC8, 0x0ECD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x0ec8, 0x0ecd ,   UCODETB_WIDE  }                        //~v62UR~
//    ,{ 0x0ed0, 0x0eff ,   UCODETB_WIDE  }                        //~v62UR~
      ,{ 0x0F18, 0x0F19 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F35, 0x0F35 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F37, 0x0F37 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F39, 0x0F39 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F71, 0x0F7E ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F80, 0x0F84 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F86, 0x0F87 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F90, 0x0F97 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0F99, 0x0FBC ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x0FC6, 0x0FC6 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x102D, 0x1030 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1032, 0x1032 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1036, 0x1037 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1039, 0x1039 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1058, 0x1059 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x10a0, 0x10ff ,   UCODETB_WIDE  } //Georgian             //~v62UR~
      ,{ 0x1160, 0x11a7 ,   UCODETB_WIDE  } //width=0 by mk_wcwidth;Hangul Jumbo//~v62UR~
      ,{ 0x11a8, 0x11FF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth;Hungul Jumbo//~v62UR~
//    ,{ 0x1200, 0x137f ,   UCODETB_WIDE  } //Ethiopic             //~v62UR~
//    ,{ 0x13a0, 0x13ff ,   UCODETB_WIDE  } //Cherokee             //~v62UR~
      ,{ 0x135F, 0x135F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x1400, 0x167f ,   UCODETB_WIDE  } //UNified Canadian Aboriginal Syllabics//~v62UR~
      ,{ 0x1712, 0x1714 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1732, 0x1734 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1752, 0x1753 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1772, 0x1773 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x17B4, 0x17B5 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x17B7, 0x17BD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x17C6, 0x17C6 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x17C9, 0x17D3 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x17DD, 0x17DD ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x180B, 0x180D ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x18A9, 0x18A9 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1920, 0x1922 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1927, 0x1928 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1932, 0x1932 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1939, 0x193B ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1A17, 0x1A18 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B00, 0x1B03 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B34, 0x1B34 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B36, 0x1B3A ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B3C, 0x1B3C ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B42, 0x1B42 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1B6B, 0x1B73 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1DC0, 0x1DCA ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x1DFE, 0x1DFF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x200B, 0x200F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x201e, 0x201e ,   UCODETB_WIDE  } // ,,                  //~v62UR~
//    ,{ 0x202A, 0x202E ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x203f, 0x203f ,   UCODETB_WIDE  } // _                   //~v62UR~
//    ,{ 0x2042, 0x2042 ,   UCODETB_WIDE  } // ***                 //~v62UR~
//    ,{ 0x2060, 0x2063 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x206A, 0x206F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x20D0, 0x20EF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0x210f, 0x210f ,   UCODETB_WIDE  } //h                    //~v62UR~
//    ,{ 0x2118, 0x2118 ,   UCODETB_WIDE  } //p                    //~v62UR~
//    ,{ 0x211c, 0x211c ,   UCODETB_WIDE  } //R                    //~v62UR~
//    ,{ 0x2127, 0x2127 ,   UCODETB_WIDE  } //Ohm                  //~v62UR~
//    ,{ 0x2135, 0x2135 ,   UCODETB_WIDE  } //X                    //~v62UR~
//    ,{ 0x2155, 0x2155 ,   UCODETB_WIDE  } //1/5                  //~v62UR~
//    ,{ 0x217a, 0x217b ,   UCODETB_WIDE  } //xi,xii               //~v62UR~
//    ,{ 0x21c4, 0x21c4 ,   UCODETB_WIDE  } //<- ->                //~v62UR~
//    ,{ 0x21d0, 0x21d0 ,   UCODETB_WIDE  } //<=                   //~v62UR~
//    ,{ 0x21e6, 0x21e6 ,   UCODETB_WIDE  } //<=                   //~v62UR~
//    ,{ 0x21e8, 0x21e9 ,   UCODETB_WIDE  } //=>,|v                //~v62UR~
//    ,{ 0x2217, 0x2217 ,   UCODETB_WIDE  } //*                    //~v62UR~
//    ,{ 0x2226, 0x2226 ,   UCODETB_WIDE  } //||/                  //~v62UR~
//    ,{ 0x222d, 0x222d ,   UCODETB_WIDE  } //sss                  //~v62UR~
//    ,{ 0x2243, 0x2243 ,   UCODETB_WIDE  } //sss                  //~v62UR~
//    ,{ 0x2284, 0x2285 ,   UCODETB_WIDE  } //<_,>_                //~v62UR~
//    ,{ 0x228a, 0x228b ,   UCODETB_WIDE  } //(_,)_                //~v62UR~
//    ,{ 0x2297, 0x2298 ,   UCODETB_WIDE  } //Ox,O/                //~v62UR~
//    ,{ 0x229e, 0x229e ,   UCODETB_WIDE  } //[+]                  //~v62UR~
//    ,{ 0x22a0, 0x22a0 ,   UCODETB_WIDE  } //[x]                  //~v62UR~
//    ,{ 0x2307, 0x2307 ,   UCODETB_WIDE  } // |                   //~v62UR~
//    ,{ 0x2320, 0x2321 ,   UCODETB_WIDE  } // S,J                 //~v62UR~
      ,{ 0x2329, 0x232a ,   UCODETB_DBCS  } // <,>                 //~v62UR~
//    ,{ 0x24ea, 0x24ea ,   UCODETB_WIDE  } // O0                  //~v62UR~
//    ,{ 0x25a2, 0x25a2 ,   UCODETB_WIDE  } // o                   //~v62UR~
//    ,{ 0x25b1, 0x25b1 ,   UCODETB_WIDE  } // o                   //~v62UR~
//    ,{ 0x25c9, 0x25ca ,   UCODETB_WIDE  } // o.,<>               //~v62UR~
//    ,{ 0x25d2, 0x25d3 ,   UCODETB_WIDE  } // v,^                 //~v62UR~
//    ,{ 0x25e6, 0x25e6 ,   UCODETB_WIDE  } // o                   //~v62UR~
//    ,{ 0x2600, 0x2603 ,   UCODETB_WIDE  } // sun,cloud,umbllela,snowman//~v62UR~
//    ,{ 0x261b, 0x261b ,   UCODETB_WIDE  } // right               //~v62UR~
//    ,{ 0x2641, 0x2641 ,   UCODETB_WIDE  } // +o                  //~v62UR~
//    ,{ 0x2662, 0x2662 ,   UCODETB_WIDE  } // <>                  //~v62UR~
//    ,{ 0x266b, 0x266b ,   UCODETB_WIDE  } // jj                  //~v62UR~
//    ,{ 0x2701, 0x273c ,   UCODETB_WIDE  } // Dingbats            //~v62UR~
//    ,{ 0x273e, 0x2767 ,   UCODETB_WIDE  } // Dingbats            //~v62UR~
//    ,{ 0x2780, 0x27be ,   UCODETB_WIDE  } // Dingbats            //~v62UR~
//    ,{ 0x27d5, 0x27d7 ,   UCODETB_WIDE  } // MMM                 //~v62UR~
//    ,{ 0x27f0, 0x27f4 ,   UCODETB_WIDE  } // MMM                 //~v62UR~
      ,{ 0x302A, 0x302F ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0x3099, 0x309A ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xA806, 0xA806 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xA80B, 0xA80B ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xA825, 0xA826 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xd800, 0xdfff ,   UCODETB_UNPF  } //for surrogate pair   //~v62UR~
//    ,{ 0xfb00, 0xfb04 ,   UCODETB_WIDE  } // ff->ffl             //~v62UR~
      ,{ 0xFB1E, 0xFB1E ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0xfb50, 0xfc62 ,   UCODETB_WIDE  } // ff->ffl             //~v62UR~
//    ,{ 0xfc66, 0xfdff ,   UCODETB_WIDE  } // ff->ffl             //~v62UR~
      ,{ 0xFE00, 0xFE0F ,   UCODETB_DBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xFE20, 0xFE23 ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
      ,{ 0xFE53, 0xFE53 ,   UCODETB_UNPF  } //                     //~v62UR~
      ,{ 0xFE67, 0xFE67 ,   UCODETB_UNPF  } //                     //~v62UR~
      ,{ 0xFE6c, 0xFE6c ,   UCODETB_UNPF  } //                     //~v62UR~
//    ,{ 0xfe70, 0xfefe ,   UCODETB_WIDE  } // Arabic forms B      //~v62UR~
      ,{ 0xFEFF, 0xFEFF ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
//    ,{ 0xFFF9, 0xFFFB ,   UCODETB_SBCS  } //width=0 by mk_wcwidth//~v62UR~
#endif                                                             //~v640I~
  };                                                               //~v62UR~
//  int datatype;                                                  //~v62UR~//~v65eR~
    int datatype=0;                                                //~v65eI~
//*******************************                                  //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
    if (Gudbcschk_flag & UDBCSCHK_UTF8 //env is utf8;wcwidth is common to all locale//~v640R~
//	&&  Sutftbopt & SUO_CONSOLE)	//old terminal emulator        //~v640I~//~v655R~
    )                                                              //~v655R~
  {                                                                //~v655R~
    if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator        //~v655R~
    {                                                              //~v640I~
    	datatype=utftbsrch(Pucs,Suctb_utf8,sizeof(Suctb_utf8)/sizeof(UCODETB));//~v640I~
        if (datatype)                                              //~v6WnI~
    	    UTRACEP("%s:utftbsrch_utf8 datatype=%x(%c),ucs=%x\n",UTT,datatype,datatype,Pucs);//~v650R~//~v6uER~//~v6WnR~
    }                                                              //~v640I~
    else                                                           //~v640I~
    {                                                              //~v655R~
//      datatype=0;                                                //~v640I~//~v655R~
    	datatype=utftbsrch(Pucs,Suctb_utf8_XXE,sizeof(Suctb_utf8_XXE)/sizeof(UCODETB));//~v655R~
        UTRACEP("%s:utftbsrch_utf8_XXE datatype=%x,ucs=%x\n",UTT,datatype,Pucs);//~v655R~//~v6uER~//~v6WnR~
//        if (!datatype)                                             //~v6WkI~//~v6WnR~
//        {                                                          //~v6WkI~//~v6WnR~
//            if (utf4_isAmbiguous_XXE(0,(UWUCS)Pucs))               //~v6WkR~//~v6WnR~
//                datatype=UCODETB_WIDE;                             //~v6WkI~//~v6WnR~
//        }                                                          //~v6WkI~//~v6WnR~
//        else                                                       //~v6WkI~//~v6WnR~
        if (datatype==UCODETB_SBCSF)                               //~v6WkR~
        {                                                          //~v6WkI~
            datatype=UCODETB_SBCS|UTFWWF_SBCSF;	//set flag         //~v6WkI~
        }                                                          //~v6WkI~
        if (datatype)                                              //~v6WnI~
    	    UTRACEP("%s:utftbsrch_utf8_XXE datatype=%x,ucs=%x\n",UTT,datatype,Pucs);//~v6WnI~
    }                                                              //~v655R~
  }                                                                //~v655R~
  if (!datatype)                                                   //~v640I~
#endif                                                             //~v640I~
  {                                                                //~v640I~
  	if (Sutftbopt & SUO_CONSOLE)	//old terminal emulator        //~v62UR~
    	datatype=utftbsrch(Pucs,Suctb_cjk_console,sizeof(Suctb_cjk_console)/sizeof(UCODETB));//~v62UR~
  	else                                                           //~v62UR~
    	datatype=utftbsrch(Pucs,Suctb_cjk,sizeof(Suctb_cjk)/sizeof(UCODETB));//~v62UR~
  }                                                                //~v640I~
    if (datatype)                                                  //~v62UR~
    {                                                              //~v62UR~
		if (datatype & UCODETB_UNPF) //unprintable entry           //~v62UR~
        	return -1;      //not 0 to return this value           //~v62UR~
		if (datatype==UCODETB_NARROW)                              //~v62UR~
   			datatype=(UTFWWF_F1C1|2);  //narrow(fontwidth=1) DBCS  //~v62UR~
        else                                                       //~v62UR~
		if (datatype==UCODETB_WIDE)                                //~v62UR~
   			datatype=(UTFWWF_F2C1|2);  //wide font                 //~v62UR~
    }                                                              //~v62UR~
//    UTRACEP("utftbsrch_cjk datatype=%x,ucs=%x\n",datatype,Pucs);   //~v650R~//~v65eR~//~v6hHR~//~v6uER~
    return datatype;                                               //~v62UR~
}//utftbsrch_cjk                                                   //~v62UR~
#endif // LNX                                                      //~v62XI~
#ifdef LNX                                                         //~v6VbI~
//******************************************************           //~v6VbI~
//get char width for XXE(for test on Console)                      //~v6VbI~
//******************************************************           //~v6VbI~
#ifdef AAA                                                         //~v6VbI~
int utf3_wcwidthXXE(int Popt,UWUCS Pucs,int *Ppflag,int *Pprc)     //~v6VbI~
{                                                                  //~v6VbI~
	int datatype,rc=0,len,flag;                                    //~v6VbI~
    int swconsole,wcw;                                             //~v6VbR~
//*****************                                                //~v6VbI~
	swconsole=Sutftbopt & SUO_CONSOLE;                             //~v6VbI~
	Sutftbopt &= ~SUO_CONSOLE;	//parm to utftbsrch_jeuc;          //~v6VbI~
	datatype=utftbsrch_jeuc((ULONG)Pucs);                          //~v6VbR~
	Sutftbopt |= swconsole;                                        //~v6VbI~
	if (datatype)                                                  //~v6VbI~
    {                                                              //~v6VbI~
    	datatype&=UCODETB_LENMASK;                                 //~v6VbI~
        rc=1;                                                      //~v6VbI~
    }                                                              //~v6VbI~
    else                                                           //~v6VbI~
    {                                                              //~v6VbI~
		Sutftbopt &= ~SUO_CONSOLE;	//parm to utftbsrch_jeuc;      //~v6VbI~
    	datatype=utftbsrch_cjk((ULONG)Pucs);                       //~v6VbI~
//  	Sutftbopt |= swconsole;                                    //~v6VbI~//~v6WnR~
        if (!datatype)                                             //~v6VbI~
        {                                                          //~v6VbI~
//        	datatype=mk_wcwidth((UWUCS)Pucs);                      //~v6VbI~//~v6WnR~
          	datatype=mk_wcwidth(Sutftbopt,(UWUCS)Pucs);            //~v6WnI~
            rc=2;                                                  //~v6VbI~
        }                                                          //~v6VbI~
    	Sutftbopt |= swconsole;                                    //~v6WnI~
    }                                                              //~v6VbI~
    if (datatype<0)                                                //~v6VbI~
    {                                                              //~v6VbI~
        flag=0;rc=0;len=datatype;                                  //~v6VbI~
    }                                                              //~v6VbI~
    else                                                           //~v6VbI~
    {                                                              //~v6VbI~
    	len=datatype & UTFWWF_LENMASK;                             //~v6VbR~
    	flag=datatype & UTFWWF_FLAGMASK;                           //~v6VbR~
    	rc|=datatype & (int)UTFWWF_RC_MASK;                        //~v6VbR~
        if (rc & UTFWWF_RC_MK_WCWIDTH)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6VbI~
        {                                                          //~v6WiI~
          if (rc & UTFWWF_RC_FORMAT)   //datatype by mk_wcwidth,adjustable by wcwidth api for width=0//~v6WiI~
			len=utfwwapichk(UTFWWO_MK_WCWIDTH|UTFWWO_FORMAT,Pucs,len,&flag,&wcw);//~v6WiI~
          else                                                     //~v6WiI~
            len=utfwwapichk(UTFWWO_MK_WCWIDTH,(ULONG)Pucs,len,&flag,&wcw);//~v6VbR~
        }                                                          //~v6WiI~
        else                                                       //~v6VbI~
            if (Gulibutfmode & GULIBUTFAPIWIDTH0) //     0x02000000  //accept wcwidth()=0 for not on utf4:combine tbl//~v6VbI~
                len=utfwwapichk(UTFWWO_APIW0,(ULONG)Pucs,len,&flag,&wcw);  //len=0 if wcwidth()=0//~v6VbR~
            else                                                   //~v6VbI~
                len=utfwwapichk(0,(ULONG)Pucs,len,&flag,&wcw);     //~v6VbR~
    }                                                              //~v6VbI~
    if (Ppflag)                                                    //~v6VbI~
    	*Ppflag=flag;                                              //~v6VbI~
    if (Pprc)                                                      //~v6VbI~
    	*Pprc=rc;                                                  //~v6VbI~
    UTRACEP("%s:ucs=%06x,UDBCSCHK_UTF8=%d,len=%d,flag=%x,rc=%x\n",UTT,Pucs,(Gudbcschk_flag & UDBCSCHK_UTF8)!=0,len,flag,rc);//~v6VbI~
    return len;                                                    //~v6VbI~
}//utf3_wcwidthXXE                                                 //~v6VbI~
#else     //!AAA                                                   //~v6VbI~
//******************************************************           //~v6VbI~
int utf3_wcwidthXXE(int Popt,UWUCS Pucs,int *Ppflag,int *Pprc)     //~v6VbI~
{                                                                  //~v6VbI~
	int len,flag,opt,swconsole;                               //~v6VbI~//+v6X3R~
//*****************                                                //~v6VbI~
	swconsole=Sutftbopt & SUO_CONSOLE;                             //~v6VbI~
	Sutftbopt &= ~SUO_CONSOLE;	//parm to utftbsrch_jeuc;          //~v6VbI~
	opt=UTFWWO_NOMAPUSE|UTFWWO_UTF8UCS2;                           //~v6VbI~
    if (Pucs==0x0103ab)	//@@@@test                                 //~v6WkI~
    {                                                              //~v6WkI~
    	UTRACEP("%s\n",UTT);                                       //~v6WkI~
    }                                                              //~v6WkI~
	len=utfwcwidth(opt,(ULONG)Pucs,&flag);                         //~v6VbI~
	Sutftbopt |= swconsole;                                        //~v6VbI~
    if (Ppflag)                                                    //~v6VbI~
    	*Ppflag=flag;                                              //~v6VbI~
    UTRACEP("%s:ucs=%06x,UDBCSCHK_UTF8=%d,rc=len=%d,flag=%\n",UTT,Pucs,(Gudbcschk_flag & UDBCSCHK_UTF8)!=0,len,flag);//~v6VbI~//+v6X3R~
    return len;                                                    //~v6VbI~
}//utf3_wcwidthXXE                                                 //~v6VbI~
#endif	//!AAA                                                     //~v6VbI~
#endif //LNX                                                       //~v6VbI~
#ifdef W32                                                         //~v6V4I~
#ifndef WXE                                                        //~v6V4I~
//******************************************************           //~v6V4I~
//*to test WXE by console version                                  //~v6V4I~
//******************************************************           //~v6V4I~
int utf3_wcwidthWXE(int Popt,UWUCS Pucs,int *Ppflag,int *Pprc)     //~v6V4I~
{                                                                  //~v6V4I~
	int rc=0,len,flag,opt,swconsole;                                         //~v6V4R~//~v6WpR~
//*****************                                                //~v6V4I~
	swconsole=Sutftbopt & SUO_CONSOLE;                             //~v6WpI~
	Sutftbopt &= ~SUO_CONSOLE;	//parm to utftbsrch_jeuc;          //~v6WpI~
	opt=UTFWWO_NOMAPUSE|UTFWWO_UTF8UCS2;                           //~v6V4I~
	SswWXE=1;                                                      //~v6V4I~
	len=utfwcwidth(opt,(ULONG)Pucs,&flag);                         //~v6V4I~
    if (Ppflag)                                                    //~v6V4I~
    	*Ppflag=flag;                                              //~v6V4I~
    UTRACEP("%s:ucs=%04x,len=%d,flag=%x,rc=%x\n",UTT,Pucs,len,flag,rc);//~v6V4I~//~v6VnR~
	SswWXE=0;                                                      //~v6WpI~
	Sutftbopt |= swconsole;                                        //~v6WpI~
    return len;                                                    //~v6V4I~
}//utf3_wcwidthWXE                                                 //~v6V4I~
#endif  //!WXE                                                     //~v6V4I~
#endif  //W32                                                      //~v6V4I~
