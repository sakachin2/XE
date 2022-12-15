//*CID://+v760R~:                             update#=  192;       //~v760R~
//******************************************************           //~v5n8I~
//v760:221213 On Windows Terminal; qurious action; try panel width decrease one without checking parent process is Terminal(old conhost is no problem)//~v760I~
//v6X7:180820 MXCOMBINE=8 for tibetan who says. but 4 for LNX Console by curses limitation//~v6X7I~
//v6Ww:180807 (W32:Bug)top panel LC line is corrupted,use not OutputW but OutputCharacterW.(See v6C8)//~v6WuI~
//v6Wu:180806 for also console version:set altch for SCM when COMBINE_NP,green if not adter combinable.//~v6WuI~
//v6Wr:180804 process SCM same as NSM(NonSpacing Mark)             //~v6WrI~
//v6Vg:180531 (Win) like as (LNX)v6V5, show org ucs for width0 ucs4(>=map entry)(W32 console version dose not support ligature:On)//~v6VgI~
//v6V5:180531 show org ucs for width0 ucs4(>=map entry)            //~v6V5I~
//v6Fc:160904 in addition to v6F3,also DBCS space altch is changable//~v6FcI~
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //~v6EqI~
//v6Ep:160812 (WXE)errmsg lineopt;strput called intermediate of errmsg string by attr change,it should not Col but msg len//~v6EpI~
//v6Eo:160811 (XXE)v6ei for XXE(specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EoI~
//v6Em:160807 (LNX) v6Ei for LNX(specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~v6EmI~
//v6Ej:160805 v6Ei for wxe(XE:vb4i)specify ligature on/off,combine on/of line by line//~v6EjI~
//v6Ei:160802 specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EiI~
//v6Ee:160801 (W32)for xe:vb4e;forceligature option for dirlsit    //~v6EeI~
//v6E8:160726 set cmdline to not combine mode                      //~v6E8I~
//v6C7:160405 No Ligature line option one by one                   //~v6C7I~
//v6BZ:160327 roundup width0 boundary to dbcsid=xx00 to avoid incresing testcase by change of UDBCSCHK_ISUCSWIDTH0//~v6BZI~
//v6BY:160326 not fixed width0 ucs boundary                        //~v6BYI~
//v6BT:160319 (BUG)isalpha is apply to UCHAR only(UTF_COMBINABLE use it for ucs)//~v6BTI~
//v6Bh:160212 (LNX)compiler warning                                //~v6BhI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v65p:100401 v65n for LNX                                         //~v65pI~
//v65i:100327 (WinCons)display 0x1b by unicodwe letterlike symbols u21xx because 0x1b make trouble for line clear//~v65iI~
//v658:100220 simple split mode like as windows. single write combining char when split mode.//~v658I~
//            visibility depends to curses. user select split or combine mode.//~v658I~
//            shadow is another option by A+":"                    //~v658I~
//v656:100212 LNX:Cons try to display combining char with left adjasent byte when split mode//~v656I~
//v653:100209 (LNX)try ligature for also console version           //~v653I~
//v652:100208 (WIN)try ligature for also console version           //~v652I~
//v650:100121 print width=0(combine mdeo)                          //~v650I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62X:091107_compchkm                                             //~v62XI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//*******************************************************          //~v5n8I~
#define UVIOM_COMBINE_ALTCH2 '.'                                   //~v6V5I~
#ifndef UVIOMDEFONLY                                               //~v6EmI~
#ifndef __cplusplus                                                //~v6EjI~
#ifdef WCSUPP                                                      //~v5n8I~
#ifdef W32                                                         //~v6X7I~
		#define UVIOM_MAXCOMBINE  8                                //~v6X7I~
#else                                                              //~v6X7I~
    #ifdef XXX                                                     //~v6X7I~
		#define UVIOM_MAXCOMBINE  8                                //~v6X7I~
    #else                                                          //~v6X7I~
#define UVIOM_MAXCOMBINE  4                                        //~v653R~
    #endif                                                         //~v6X7I~
#endif                                                             //~v6X7I~
#define UVIOM_MAXCOL      240 //sync with xe.h                     //~v652I~
#define UVIOM_BUFFSZ      2                                        //~v5n8R~
#ifdef UVIOW_GBLDEF                                                //~v5n8I~
    int Guviomopt;                                                 //~v5n8R~
  #ifdef UTF8SUPPH                                                 //~v62XI~
    int Guviomopt2;                                                //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
    unsigned char Guviomoptstr[4];  //[3]:dbcs space rep           //~v640R~
    WUCS Guviomoptstrucs[4];                                       //~v65pI~
#else                                                              //~v640I~
    unsigned char Guviomoptstr[3];                                 //~v62UR~
#endif                                                             //~v640I~
//  unsigned char Guviomdbcspad=' ';     //set by disp on/off      //~v65pR~
    WUCS          Guviomdbcspad=' ';     //set by disp on/off      //~v65pI~
  #endif                                                           //~v62XI~
	WUCS    *Guviombuffu;   	//unicode buff                     //~v5n8I~
	int  *Gw95buffopt;	//ligature option for line by line         //~v6EoI~
#else                                                              //~v5n8I~
    extern int Guviomopt;                                          //~v5n8R~
  #ifdef UTF8SUPPH                                                 //~v62XI~
    extern int Guviomopt2;                                         //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
    extern unsigned char Guviomoptstr[4];                          //~v640I~
    extern WUCS Guviomoptstrucs[4];                                //~v65pI~
#else                                                              //~v640I~
    extern unsigned char Guviomoptstr[3];                          //~v62UR~
#endif                                                             //~v640I~
//  extern unsigned char Guviomdbcspad;     //set by disp on/off   //~v65pR~
    extern WUCS          Guviomdbcspad;     //set by disp on/off   //~v65pI~
  #endif                                                           //~v62XI~
	extern WUCS *Guviombuffu;   	//unicode buff                 //~v5n8I~
	extern int  *Gw95buffopt;	//ligature option for line by line //~v6EoI~
#endif                                                             //~v5n8I~
#define UVIOMO2_PADON         0x01 //DBCS padding display alternative char//~v62UR~
#define UVIOMO2_PADOFF        0x02 //DBCS padding display alternative char//~v62UR~
//#define UVIOMO2_LIGATURE      0x04 //ligature                    //~v653R~
#define UVIOMO2_NONSPACECOMBINE 0x08 //non spacing combining diacritical mark supported//~v656I~
#define UVIOMO2_NOTIFY_DBCSSPACEALT 0x0100 //dbcsspacealt was changed//~v6FcI~
                                                                   //~v6FcI~
                                                                   //~v6FcI~
#define UVIOM_NONSPACECOMBINEMODE()  (Guviomopt2 & UVIOMO2_NONSPACECOMBINE)//~v656R~
//#define UVIOM_SPLITMODE()  (!UTF_COMBINEMODE() && UVIOM_NONSPACECOMBINEMODE())//~v656I~//~v658R~
//#define UVIOM_SPLITTABLEMODE()  (UTF_COMBINEMODE() && UVIOM_NONSPACECOMBINEMODE())//~v656I~//~v658R~
//#define UVIOM_COMBINEMODE()  (!UVIOM_SPLITMODE())   //             //~v656R~//~v658R~
                                                                   //~v656I~
//#define UVIOM_UNPDISPCH  Guviomoptstr[0]    //alternative display char for unprintable//~v65pR~
//#define UVIOM_PADDISPCH  Guviomoptstr[1]    //alternative display char for dbcs padding//~v65pR~
#define UVIOM_UNPDISPCH  Guviomoptstrucs[0]    //alternative display char for unprintable//~v65pI~
#define UVIOM_PADDISPCH  Guviomoptstrucs[1]    //alternative display char for dbcs padding//~v65pI~
#define UVIOM_PADATTR    (Guviomoptstr[2]&0x0f)    //padding attr fg//~v62UR~
                                                                   //~v62UR~
//#define CCTSZ (sizeof(chtype))                                     //~v5n8I~//~v6BhR~
#define CCTSZ ((int)sizeof(chtype))                                //~v6BhI~
//#define CCHSZ (sizeof(cchar_t))                                    //~v5n8R~//~v6BhR~
#define CCHSZ ((int)sizeof(cchar_t))                               //~v6BhI~
#define UVIOM_ATTRBG(attr) ((attr) & 0xf0)                         //~v62UR~
#define UVIOM_ATTRFG(attr) ((attr) & 0x0f)                         //~v62UR~
//	      (  ((attr) & ~(0x0f00)) /*clear fg*/                     //~v6BhI~
//        |  (UVIOM_PADATTR<<8)   /*fg*/                           //~v6BhI~
#define UVIOM_SET_PADATTR(attr)                  \
	      (  ( (attr_t)(attr) & (attr_t)(~(0x0f00))  ) /*clear fg*/   \
	      |  (attr_t)(UVIOM_PADATTR<<8)   /*fg*/         \
          )                                                        //~v658I~
//for WinCons                                                      //~v65iI~
#define UVIOM_ESC_CHAR        0x1b                                 //~v65iR~
//*******************************************************          //~v5n8I~
//  void uviom_init(int Popt,ULONG Phconout,int Pscrwidth,int Pscrsize,int Ptoplineoffs);//~v5n8R~//~v6hhR~
    void uviom_init(int Popt,ULPTR Phconout,int Pscrwidth,int Pscrsize,int Ptoplineoffs);//~v6hhI~
#ifdef UTF8SUPPH                                                   //~v62XI~
//  void uviom_setopt2(int Popt,unsigned char *Pdispch);           //~v652R~
    int  uviom_setopt2(int Popt,unsigned char *Pdispch);           //~v652I~
	int uviom_notify(int Popt,int P1,int P2);                      //~v652I~
	#define UVIOMNO_CSRPOS     0x01 //csrpos                       //~v652I~
	#define UVIOMNO_SPLITPOS   0x02 //split line                   //~v653I~
	#define UVIOMNO_VHEXCSRPOS 0x04 //csrpos of dataline of vhexcsr//~v658I~
	#define UVIOMNO_ALTCH      0x08 //splt mode altchar            //~v658I~
#ifdef W32                                                         //~v6C7R~
//  #define UVIOMNO_NOLIGATURE 0x10 //no ligature line             //~v6EiR~
//  #define UVIOMNO_NOLIGATURE_CMDLINE 0x20 //no ligature line     //~v6EiR~
#endif                                                             //~v6C7R~
//  #define UVIOMNO_FORCELIGATURE 0x40 //for lirlist               //~v6EiR~
#endif                                                             //~v62XI~
    #ifdef LNX                                                     //~v5n8I~
      #ifndef XXE                                                  //~v62UR~
       #ifndef NOCURSES                                            //~v6a0I~
//		int uvio_mvaddchnstrF(int Popt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~v5n8R~//~v6EmR~
  		int uvio_mvaddchnstrF(int Popt,int Plineopt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~v6EmI~
#define UVIOMWFO_UTF8OUT     0x01  //write by utf8 string          //~v5n8R~
#define UVIOMWFO_UTF8IN      0x02  //write source is utf8 string   //~v5n8R~
#define UVIOMWFO_MBIN        0x04  //write source is multibyte string//~v5n8R~
#define UVIOMWFO_NODBCSCLEAR 0x08  //no need to space clear before write for DBCS//~v5n8R~
#define UVIOMWFO_CHKACS      0x10  //not yet ACS trnslated         //~v5n8I~
//*******************************************************          //~v5n8I~
		int uviom_mvaddwchnstr(int Prow,int Pcol,cchar_t *Ppcchar,int Plen);//~v5n8R~
//*******************************************************          //~v5n8I~
		int uviom_readcell(int Popt,int Prow,int Pcol,chtype *Ppcht,int Plen);//~v5n8R~
       #endif  //NOCURSES                                          //~v6a0I~
      #endif                                                       //~v62UR~
    #else                                                          //~v5n8I~
//*******************************************************          //~v5n8I~
        int uviowrtcharstrW(int Popt,UCHAR *Ppstr,int Plen,UCHAR *Ppdbcs,COORD Ptgtcord);//~v5n8R~
//*******************************************************          //~v5n8I~
        int uviowrtcellW(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Psrcrect);//~v5n8R~
    #endif                                                         //~v5n8I~
#endif	//WCSUPP                                                   //~v5n8I~
#ifdef UTF8UCS2                                                    //~v650I~
//int uvio_getcombinectr(int Popt,int Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen);//~v650R~//~v6BTR~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
#ifdef LNX                                                         //~v6V5R~
    #ifndef XXE                                                    //~v6V5I~
int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~v6V5R~
    #endif                                                         //~v6V5I~
#else                                                              //~v6V5R~
//int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen);//~v6BTI~//~v6VgR~
	int uvio_getcombinectr(int Popt,WUCS *Ppucs,int Pchwidth,UCHAR *Ppdbcs,int Plen,int *Ppstrucsctr,int *Ppstrwidth);//~v6VgR~
#endif                                                             //~v6V5R~
//#else                                                              //~v6BYI~//~v6BZR~
//    #ifdef LNX                                                     //~v6BYI~//~v6BZR~
//    #ifndef XXE                                                    //~v6BYI~//~v6BZR~
//        int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,chtype Pcht,UCHAR *Ppdbcs,int Plen);//~v6BYR~//~v6BZR~
//    #endif                                                         //~v6BYI~//~v6BZR~
//    #endif                                                         //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
#endif                                                             //~v650I~
#endif	//__cplusplus                                              //~v6EjI~
#endif //UVIOMDEFONLY                                              //~v6EmI~
#ifdef WINCON                                                      //+v760I~
    #define GOPT_WT_CONHOST          0x01       //not windows terminal(New command prompt)//+v760M~
    #define GOPT_WT_RCOLS            0x02   //Right edge column keep empty//+v760M~
    #define GOPT_WT_CP437            0x10   //display control charcter by alt char over xe.ini definition//+v760M~
    #define GOPT_WT_CP932            0x20   //display control charcter by alt char over xe.ini definition//+v760M~
    #define IS_ON_TERMINAL()  (!(GoptWindowsTerminal & GOPT_WT_CONHOST))//+v760M~
	#ifdef UVIOW_GBLDEF                                            //+v760I~
	    int GoptWindowsTerminal;                                   //+v760I~
    	char *GunprintableOnTerminal;                              //+v760I~
    #else                                                          //+v760I~
    	extern int GoptWindowsTerminal;                            //+v760I~
        extern char *GunprintableOnTerminal;                       //+v760I~
    #endif                                                         //+v760I~
#endif                                                             //+v760I~
//*uvio_xxx common option parameter                                //~v6EiI~
#define UVIOO_LIGATURE1          0x01       //line accept ligature:on option//~v6EiR~
#define UVIOO_FORCELIGATURE      0x02       //line force ligature mode//~v6EiI~
#define UVIOO_LIGATURE    (UVIOO_LIGATURE1|UVIOO_FORCELIGATURE) //ligature anyway//~v6EiI~
#define UVIOO_LIGATURE2          0x04       //special for hdr/cmdline/LC:(for W32/uvio)//~v6EiR~
#define UVIOO_COMBINE            0x08       //line accept combine mode option//~v6EiR~
#define UVIOO_FORCECOMBINE       0x10       //                     //~v6EiR~
#define UVIOO_CSRPOSCHK          0x20       //csr position check   //~v6EiR~
#define UVIOO_CMDLINE            0x40       //special for cmdline  //~v6EiR~
#define UVIOO_ERRMSG             0x80       //special for uerrmsg  //~v6EiI~
#define UVIOO_VSPLIT2ND        0x0100       //2nd of split screen  //~v6EiR~
#define UVIOO_MENULC           0x0200       //MENU LC line         //~v6WuI~
#define UVIOO_ERRMSG2          0x0400       //errmsg 2ndline       //~v6EpI~
#define UVIOO_FULLSCR          0x1000       //all pcw is draw full //~v6EiR~
#define UVIOO_BUFFWRITE        0x2000       //from uvio_w95buffwrite//~v6EiI~
#define UVIOO_NOSAVE           0x4000       //no save lineopt,for vsplit line//~v6EqI~
#define UVIOO_COMBINEOFF       0x8000       //combine mode to uviowrtcellW1_cpu8file_NoLigatureNoCombine//~v6WuI~
#define UVIOO_MASK             0xffff       //0xffff0000 is free   //~v6EiI~
//#ifdef WXE                                                       //~v6EoR~
#ifdef WXEXXE                                                      //~v6EoI~
#define UVIOO_ERRMSGMASK       0xffff0000   //it may change with hdr line//~v6EiI~
#endif                                                             //~v6EiI~
#define UVIOO_ERRMSGSHIFT_ROW  (16+8)                              //~v6EpI~
#define UVIOO_ERRMSGSHIFT_LEN  (16)                                //~v6EpI~
                                                                   //~v6EjI~
#define COMBINEMODE(opt)  ((opt & UVIOO_FORCECOMBINE) || ((opt & UVIOO_COMBINE) && UTF_COMBINEMODE()))//~v6EiR~
//#define LIGATUREMODE(opt)  ((opt & UVIOO_FORCELIGATURE) || ((opt & UVIOO_LIGATURE) && UTF_LIGATUREMODE())) //ligature on//~v6EiR~
#define LIGATUREMODE(opt)  ((opt & UVIOO_LIGATURE) && UTF_LIGATUREMODE()) //ligature on anyway(force or optional)//~v6EiI~
                                                                   //~v6EiI~
//#define ATTR_COMBINE_FG  0x03    //green+blue(!=02)   //WinCon 2nd combine char//~v6EiR~
#define ATTR_COMBINE_FG  0x0a    //green+blue(!=02)   //WinCon 1st combine char//~v6EiI~
#define ATTR_CTLCHAR_FG  0x03    //green+blue(!=02)                //~v6EiM~
//#define ATTR_COMBINE_FG2  0x0E //0x06    //yellow(!=2)//WinCon 1st combinechar//~v6EiR~
#define ATTR_COMBINE_FG2  0x0b   //highlight green(!=2(green for utf8 char))//WinCon 2nd combinechar//~v6EiR~
#define ATTR_COMBINENP_FG 0x0a   //for combine altch,highlight green/+v6EiM~//~v6EiR~
#define ATTR_COMBINE_FG_UCS4 0x03  //highlight green UCS4 width0 2nd padding//~v6V5I~
                                                                   //~v6EmI~
#if defined(LNX) && !defined(XXE)                                  //~v6EmI~
	#define UVIOM_ALTCHPADDING  0 //split mode display char        //~v6EmM~
	#define UVIOM_ALTCHSHADOW   1 //display shadow                 //~v6EmM~
	#define UVIOM_ALTCHITSELF   2 //display combining char itself  //~v6EmM~
#endif                                                             //~v6EmI~
//***************************************************************  //~v6WrI~
int uviom_getcombaltchUcs(int Popt,WUCS *Ppucs);                   //~v6WrI~
int uviom_getcombaltchU8(int Popt,char *Pu8,char *Ppdddata,char *Ppdddbcs,int *Ppddlen);//~v6WrR~
#define UVIOM_GCAC_2CELL   0x01      //2cell out                   //~v6WrI~
