//*CID://+v7fxR~:                             update#=  232;       //~v7c4R~//+v7fxR~
//******************************************************           //~v5n8I~
//v7fx:251205 (Wxe)addtionally to WINCON, optionally chk EOL for also Wxe.//+v7fxI~
//vbEg:251112 (LNXCON)hcopy;save/get by dd str for utf8(shadow of combining generated double a+x300 and a and a+301)//~vbEgI~
//v7c4:240618 (Bug of v7bW) if rep ZWJ to altch,it becomes next combining base.(display doble "+")//~v7c4I~
//v7bW:240525 display category Cf by "+" as itself/shadow          //~v7bWI~
//v7bG:240425 split uviom.c to uvioml.c                            //~v7bGR~
//vbzP:240412 (LNXCON)support hardcopy function(also change key C+h-->A+@)//~vbzPI~
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
#ifdef LNX                                                         //~v7bGI~
//  #define UVIOMATTR_PADDING      0x03         //temporary padding flag//~v653R~//~v7bGM~
    #define UVIOMATTR_DBCS1        0x01         //1:dbcs1st,2:DBCS2ND//~v653R~//~v7bGM~
    #define UVIOMATTR_DBCS2        0x02         //1:dbcs1st,2:DBCS2ND//~v653I~//~v7bGM~
    #define UVIOMATTR_DBCS12       0x03         //1:dbcs1st,2:DBCS2ND//~v653I~//~v7bGM~
    #define UVIOMATTR_BREAK        0x04         //temporary break ligature flag//~v653I~//~v7bGM~
    #define UVIOMATTR_PADDING      0x08         //temporary padding flag//~v653I~//~v65bM~//~v7bGM~
	#define UVIOMATTR_SETATTR      0x10         //for the case ligature not combine mode//~v656I~//~v7bGM~
	#define UVIOMATTR_BASEDBCS     0x20         //base char is dbcs//~v658I~//~v7bGM~
	#define UVIOMATTR_SHADOW       0x40         //shadow entry     //~v65bI~//~v7bGM~
    #define UVIOMATTR_PADDING2     0x80         //temporary padding flag for ucs4 width0//~v6V5I~//~v7bGM~
    #define UVIOMATTR_ATTRMASK     0xFF                            //~v6W2R~//~v7bGM~
    #define UVIOMATTR_COLORMASK    0xFF00                          //~v6W2I~//~v7bGM~
//  #define UVIOMATTR_CURSESMASK   0xff03       //color and dbcs1/2//~v6WbI~//~vbzPR~//~v7bGM~
    #define UVIOMATTR_CURSESMASK   (0xff03+UVIOMATTR_EXT_NOHCOPY)  //~vbzPI~//~v7bGM~
                                                                   //~v6WbI~//~v7bGM~
    #define UVIOMATTR_EXT_LIGATURE 0x010000     //extended option to setcombine1:ligature on//~v6V6I~//~v7bGM~
    #define UVIOMATTR_EXT_PADDING  0x020000     //extended option to mvaddchnstrW_ligature//~v6V6I~//~v7bGM~
    #define UVIOMATTR_EXT_COMBBASE 0x040000     //ligature:off,combinemode,combin base//~v6W5I~//~v7bGM~
    #define UVIOMATTR_EXT_PADDING2 0x080000     //shadow padding for overflowcombining//~v6W7I~//~v7bGM~
//!! don't use 100000, is is same as A_DIM, it is used as padding char to be skip copy to hardcopy//~vbzPR~//~v7bGM~
//  #define UVIOMATTR_EXT_DMYBASE  0x100000     //added "A0" entry for combining//~vbzPR~//~v7bGM~
    #define UVIOMATTR_EXT_NOHCOPY  ATTR_COMBINE_PADDING_NOHCOPY //0x100000; padding to be dropped from hcopy//~vbzPR~//~v7bGM~
    #define UVIOMATTR_EXT_BASEUNP  0x200000     //base is unprintable//~v6WeI~//~v7bGM~
    #define UVIOMATTR_EXT_DMYBASE  0x400000     //added "A0" entry for combining//~vbzPI~//~v7bGM~
    #define UVIOMATTR_EXT_WIDESBCS 0x800000                        //~v7bDI~//~v7bGM~
    #define UVIOMATTR_EXT_DBCSCOMBCTR_MASK 0x07000000 //dbcscombining char ctr mask//~v7bDR~//~v7bGM~
    #define UVIOMATTR_MAXSCM       (UVIOMATTR_EXT_DBCSCOMBCTR_MASK>>24)//~v7bGI~
    #define UVIOMATTR_EXT_DBCSCOMBCTR1     0x01000000 //dbcscombining char ctr mask//~v7bDI~//~v7bGM~
    #define UVIOMATTR_ADD_DBCSCOMBCTR(pcchar) ((pcchar)->attr+=UVIOMATTR_EXT_DBCSCOMBCTR1)//~v7bDI~//~v7bGM~
    #define UVIOMATTR_GET_DBCSCOMBCTR(attr) (((attr) & UVIOMATTR_EXT_DBCSCOMBCTR_MASK)>>24)//~v7bDI~//~v7bGM~
    #define UVIOMATTR_EXT_SCM      0x08000000     //scm comining   //~v7bER~//~v7bGR~
    #define UVIOMATTR_EXT_SCMBASE  0x10000000     //scm base       //~v7bEI~//~v7bGR~
    #define UVIOMATTR_EXT_PADDCOMB 0x20000000     //padding beteen base and combining//~v7bGR~
    #define UVIOMATTR_EXT_BASEWIDE 0x40000000                      //~v7bGI~
    #define UVIOMATTR_EXT_ALTCH    0x80000000     //set altch to cchar//~v7c4I~
#endif //LNX                                                                   //~v653I~//~v7bGR~
                                                                   //~v7bGI~
#define UCS_ZWJ      0x200d                                        //~v7bWI~
#define UCS_ZWNJ     0x200c                                        //~v7bWI~
int uviom_getAltFormat(int Popt,int Pucs,int Pdefault);            //~v7bWI~
#define   UVMGAFO_GETORGUCS     0x01                               //~v7c4I~
#define UVIOM_ALTCH_FORMAT '='                                     //~v7bWR~
#define UVIOM_ALTCH_ZWJ    '+'                                     //~v7bWI~
#define UVIOM_ALTCH_ZWNJ   '-'                                     //~v7bWI~
#define UVIOM_COMBINE_ALTCH2 '.'                                   //~v6V5I~
#define COMBAINE_BASE_SPLIT_ITSELF 0xa0     //u00a0 base for combining char when split itself//~vbzPI~
#define UVIOM_ESC_CHAR        0x1b        //moved to out of #ifndef __cplusplus//+v7fxI~
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
    #define EXT_UVIOM                                              //~v7bGR~
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
#ifdef LNXCON                                                      //~vbEgI~
	chtype *Guvioscrddchtype;                                      //~vbEgI~
	char   *Guvioscrdddbcs;                                        //~vbEgI~
#endif                                                             //~vbEgI~
#else                                                              //~v5n8I~
    #define EXT_UVIOM extern                                       //~v7bGR~
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
#ifdef LNXCON                                                      //~vbEgI~
	extern chtype *Guvioscrddchtype;                               //~vbEgI~
	extern char   *Guvioscrdddbcs;                                 //~vbEgI~
#endif                                                             //~vbEgI~
#endif                                                             //~v5n8I~
#ifdef LNXCON                                                      //~vbEgM~
	int uviolSaveDD(int Popt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~vbEgR~
	int uviolSavecchar(int Popt,int Prow,int Pcol,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen);//~vbEgR~
	#define UVIOLSID_NOTDD            0x7c000000	//save data is not utf8 ddfmt//~vbEgR~
	#define UVIOLSID_NOTDD0           0x7c  //save data is not utf8 ddfmt//~vbEgI~
	#define UVIOLSID_NOTDDSHIFT       24	//save data is not utf8 ddfmt//~vbEgI~
	#define UVIOLSID_UCSMASK          0x00ffffff	//save data is not utf8 ddfmt//~vbEgI~
#endif                                                             //~vbEgM~
//***************                                                  //~v7bGR~
#ifdef JJJ                                                         //~v7bGI~
EXT_UVIOM int Scsrposx,Scsrposy;                                   //~v7bGR~
EXT_UVIOM int Svhexcsrposx,Svhexcsrposy;                           //~v7bGR~
#endif                                                             //~v7bGI~
//***************                                                  //~v7bGR~
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
#define CCH   cchar_t                                              //~v7bGI~
#define PCCH  cchar_t*                                             //~v7bGI~
#define UVIOM_ATTRBG(attr) ((attr) & 0xf0)                         //~v62UR~
#define UVIOM_ATTRFG(attr) ((attr) & 0x0f)                         //~v62UR~
//	      (  ((attr) & ~(0x0f00)) /*clear fg*/                     //~v6BhI~
//        |  (UVIOM_PADATTR<<8)   /*fg*/                           //~v6BhI~
#define UVIOM_SET_PADATTR(attr)                  \
	      (  ( (attr_t)(attr) & (attr_t)(~(0x0f00))  ) /*clear fg*/   \
	      |  (attr_t)(UVIOM_PADATTR<<8)   /*fg*/         \
          )                                                        //~v658I~
//for WinCons                                                      //~v65iI~
//#define UVIOM_ESC_CHAR        0x1b                               //+v7fxR~
//*******************************************************          //~vbzPI~
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
		int uviom_readConsole(int Popt,int Prow,int Pcol,int Plen,cchar_t *Ppcchar);//~vbzPR~
		int uviom_readConsoleUcs(int Popt,int Prow,int Pcol,int Plen,UWCHART *Ppucs);//~vbzPI~
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
#ifdef WINCON                                                      //~v760I~
    #define GOPT_WT_CONHOST          0x01       //not windows terminal(New command prompt)//~v760M~
    #define GOPT_WT_RCOLS            0x02   //Right edge column keep empty//~v760M~
    #define GOPT_WT_CP437            0x10   //display control charcter by alt char over xe.ini definition//~v760M~
    #define GOPT_WT_CP932            0x20   //display control charcter by alt char over xe.ini definition//~v760M~
    #define IS_ON_TERMINAL()  (!(GoptWindowsTerminal & GOPT_WT_CONHOST))//~v760M~
	#ifdef UVIOW_GBLDEF                                            //~v760I~
	    int GoptWindowsTerminal;                                   //~v760I~
    	char *GunprintableOnTerminal;                              //~v760I~
    #else                                                          //~v760I~
    	extern int GoptWindowsTerminal;                            //~v760I~
        extern char *GunprintableOnTerminal;                       //~v760I~
    #endif                                                         //~v760I~
#endif                                                             //~v760I~
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
#define ATTR_COMBINE_PADDING_NOHCOPY  A_DIM //padding to be dropped from hcopy//~vbzPI~
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
