//*CID://+v6X5R~:                             update#=  229;       //~v6X5R~
//*********************************************************************//~v62XI~
//v6X5:180818 (LNX:xe)column shring COMB2SCM(036f+0390) even SPLIT mode,//~v6X5I~
//v6X3:180816 Hangul 1160-11ff is not combining(Category:Lo:Letter,Other) but combined actualy(u1109+u1161), On W32 Suctbj adjust as DBCS if ISDBCS_J()//~v6X3I~
//v6X0:180813 combining require 2 cell when split such as u309a    //~v6X0I~
//v6Wq:180803 Format is not always width=1(u+06dd:End of Ayah is dbcs size)//~v6WqI~
//v6Wp:180802 adjust wcwidth on Win10                              //~v6WpI~
//v6Wn:180724 (v6W9 for gxe) combining char such as u309a(u306f+u309a) exists.//~v6WnI~
//v6Wm:180724 utfwcwidth return len=1 for Category "Cf"(wcwidth=0)  if ucs<ENTNO(2 if ucs>=ENTNO).//~v6WmI~
//            determin combining for ucs>=ENTNOv should not use wcwidth==0 but combining definition//~v6WmI~
//v6Wk:180723 (gxe)ambiguous(width=2) for gxe                      //~v6WkI~
//v6Wj:180722 Combining Enclosed Mark(u0488,..) should be added to combining//~v6WjI~
//v6Wi:180722 u+ad(Soft Hyphen) is wcwidth=0,bu combineprocess A0+ad show on 2 col. trate it as utfwcwidth=1 (unicode category Cf:Format)//~v6WiI~
//v6Wg:180721 (Bug)By v6v7 ud7b0 is sbcs , it need to be dbcs on japanese console//~v6WgI~
//v6Wf:180718 chk combining also gxe(not console)                  //~v6WfI~
//v6Wc:180711 NCM(NonspacingCombiningmark) by //www.fileformat.info/info/unicode/category/Mn/list.htm//~v6WcI~
//v6W9:180708 dbcs combining char such as u309a(u306f+u309a) exists.//~v6W9I~
//v6Vb:180612 add isSpacingCombiningmark                           //~v6VbI~
//v6V9:180608 (LNX)unicode tbl,move Suctb_euc(_console) to Suctbl_utf8(_XXE)//~v6V8I~
//            uviom use move+add_wchnstr for utf8 file             //~v6V8I~
//            uviom use mvaddchnstr for localefile(euc) width UDBCSCHK_DBCS1/2//~v6V8I~
//v6V8:180606 additional to v6V7,allow adjust ambiguous by wcwidth=0//~v6V8I~
//v6V7:180606 do not modify by wcwidth api,acept it only for return by mk_wcwidth//~v6V7I~
//v6V2:180522 unicode display test on ub17.10                      //~v6V2I~
//v6V1:180518 char width adjust to ubuntu 17.10(kernel 4.13.0)     //~v6V1I~
//v6L0:170508 register U-23ce(CRLF sign) as DBCS                   //~v6L0I~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6k2:130525 (Axe)abcstbl overflow on N7(>=api14)                 //~v6k2I~
//            For hangle(ac00-4db4) Java.wcwidth return 1(sbcs=10,dbcs space=16>hangle=15)//~v6k2I~
//v6hs:120715 ARM gcc warning:tbl inedx may be overflow            //~v6hsI~
//v6c5:120121 (Axe)no mk_wcwidth,completeley depends to wcwwidth(Java getTextWidths)(but allow adjust by parameter file)//~v6c5I~
//v6bu:111231 euro(u-20ac) is sbcs on also fc5                     //~v6buI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v650:100121 print width=0(combine mode)                          //~v650R~
//v647:100115 (WIN)wchar_t is ushort on Windows,consideration for UCS4//~v647R~
//v62X:091107_compchkm                                             //~v62XI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//*********************************************************************//~v62XI~
/*                                                                 //~7719I~
 * This is an implementation of wcwidth() and wcswidth() (defined in//~7719I~
 * IEEE Std 1002.1-2001) for Unicode.                              //~7719I~
 *                                                                 //~7719I~
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcwidth.html//~7719I~
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcswidth.html//~7719I~
 *                                                                 //~7719I~
 * In fixed-width output devices, Latin characters all occupy a single//~7719I~
 * "cell" position of equal width, whereas ideographic CJK characters//~7719I~
 * occupy two such cells. Interoperability between terminal-line   //~7719I~
 * applications and (teletype-style) character terminals using the //~7719I~
 * UTF-8 encoding requires agreement on which character should advance//~7719I~
 * the cursor by how many cell positions. No established formal    //~7719I~
 * standards exist at present on which Unicode character shall occupy//~7719I~
 * how many cell positions on character terminals. These routines are//~7719I~
 * a first attempt of defining such behavior based on simple rules //~7719I~
 * applied to data provided by the Unicode Consortium.             //~7719I~
 *                                                                 //~7719I~
 * For some graphical characters, the Unicode standard explicitly  //~7719I~
 * defines a character-cell width via the definition of the East Asian//~7719I~
 * FullWidth (F), Wide (W), Half-width (H), and Narrow (Na) classes.//~7719I~
 * In all these cases, there is no ambiguity about which width a   //~7719I~
 * terminal shall use. For characters in the East Asian Ambiguous (A)//~7719I~
 * class, the width choice depends purely on a preference of backward//~7719I~
 * compatibility with either historic CJK or Western practice.     //~7719I~
 * Choosing single-width for these characters is easy to justify as//~7719I~
 * the appropriate long-term solution, as the CJK practice of      //~7719I~
 * displaying these characters as double-width comes from historic //~7719I~
 * implementation simplicity (8-bit encoded characters were displayed//~7719I~
 * single-width and 16-bit ones double-width, even for Greek,      //~7719I~
 * Cyrillic, etc.) and not any typographic considerations.         //~7719I~
 *                                                                 //~7719I~
 * Much less clear is the choice of width for the Not East Asian   //~7719I~
 * (Neutral) class. Existing practice does not dictate a width for any//~7719I~
 * of these characters. It would nevertheless make sense           //~7719I~
 * typographically to allocate two character cells to characters such//~7719I~
 * as for instance EM SPACE or VOLUME INTEGRAL, which cannot be    //~7719I~
 * represented adequately with a single-width glyph. The following //~7719I~
 * routines at present merely assign a single-cell width to all    //~7719I~
 * neutral characters, in the interest of simplicity. This is not  //~7719I~
 * entirely satisfactory and should be reconsidered before         //~7719I~
 * establishing a formal standard in this area. At the moment, the //~7719I~
 * decision which Not East Asian (Neutral) characters should be    //~7719I~
 * represented by double-width glyphs cannot yet be answered by    //~7719I~
 * applying a simple rule from the Unicode database content. Setting//~7719I~
 * up a proper standard for the behavior of UTF-8 character terminals//~7719I~
 * will require a careful analysis not only of each Unicode character,//~7719I~
 * but also of each presentation form, something the author of these//~7719I~
 * routines has avoided to do so far.                              //~7719I~
 *                                                                 //~7719I~
 * http://www.unicode.org/unicode/reports/tr11/                    //~7719I~
 *                                                                 //~7719I~
 * Markus Kuhn -- 2007-05-26 (Unicode 5.0)                         //~7719I~
 *                                                                 //~7719I~
 * Permission to use, copy, modify, and distribute this software   //~7719I~
 * for any purpose and without fee is hereby granted. The author   //~7719I~
 * disclaims all warranties with regard to this software.          //~7719I~
 *                                                                 //~7719I~
 * Latest version: http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c    //~7719I~
 */                                                                //~7719I~
                                                                   //~7719I~
#include <stdio.h>                                                 //~v650I~
#include <wchar.h>                                                 //~7719I~
#ifdef UTF8UCS2                                                    //~v647I~
//#include <ulibdefc.h>                                              //~v647R~//~v6c5R~
#include <ulib.h>                                                  //~v6c5I~
#include <uerr.h>                                                  //~v650I~
#endif                                                             //~v647I~
#include <utf.h>                                                   //~v6c5I~
#include <utf2.h>                                                  //~v6BjI~
#include <utf22.h>                                                 //~v6VbI~
#include <utrace.h>                                                //~v6VbI~
#include <udbcschk.h>                                              //~v6WnI~
                                                                   //~7719I~
static int Sfromcjk;	//mk_wcwidth_cjk already chked isFormat    //~v6WnI~
struct interval {                                                  //~7719I~
  int first;                                                       //~7719I~
  int last;                                                        //~7719I~
};                                                                 //~7719I~
//************************************************************     //~v6X0I~
//int mk_wcwidth_combining2SCM(int Popt,UWUCS ucs);                  //~v6X0R~//~v6X5R~
//************************************************************     //~v6X0I~
/* auxiliary function for binary search in interval table */       //~7719I~
#ifdef UTF8UCS2                                                    //~v647R~
//static int bisearch(UWCHART ucs, const struct interval *table, int max) {//~v647R~//~v6BjR~
static int bisearch(UWUCS ucs, const struct interval *table, int max) {//~v6BjI~
#else                                                              //~v647R~
static int bisearch(wchar_t ucs, const struct interval *table, int max) {//~7719I~
#endif                                                             //~v647R~
  int min = 0;                                                     //~7719I~
  int mid;                                                         //~7719I~
#ifndef NOTRACE                                                    //~v650I~
	{	//seq ch for bin srch when test                            //~v650I~
    	#define UCTBMAX 10                                         //~v650I~
    	static const struct interval *Sctb[UCTBMAX];               //~v650R~
        int high;                                                  //~v650I~
        //*************                                            //~v650I~
        for (high=0;high<UCTBMAX;high++)                           //~v650I~
        	if (Sctb[high]==table||!Sctb[high])                    //~v650I~
            	break;                                             //~v650I~
      if (high<UCTBMAX)                                            //~v6hsI~
        if (!Sctb[high])                                           //~v650I~
        {                                                          //~v650I~
	        Sctb[high]=table;                                      //~v650I~
            mid=-1;                                                //~v650I~
            for (high=0;high<max;high++)                           //~v650R~
            {                                                      //~v650I~
                if (mid<table[high].first                          //~v650I~
                &&  table[high].first<=table[high].last)           //~v650I~
                    mid=table[high].last;                          //~v650I~
                else                                               //~v650I~
                    uerrexit("utf4:width tbl %p seq err at %d(%x--%x)",0,//~v650I~
                                table,high,table[high].first,table[high].last);//~v650I~
            }                                                      //~v650I~
        }                                                          //~v650I~
    }                                                              //~v650I~
#endif                                                             //~v650I~
                                                                   //~7719I~
//if (ucs < table[0].first || ucs > table[max].last)               //~7719I~//~v6BjR~
  if ((int)ucs < table[0].first || (int)ucs > table[max].last)     //~v6BjI~
    return 0;                                                      //~7719I~
  while (max >= min) {                                             //~7719I~
    mid = (min + max) / 2;                                         //~7719I~
//  if (ucs > table[mid].last)                                     //~7719I~//~v6BjR~
    if ((int)ucs > table[mid].last)                                //~v6BjI~
      min = mid + 1;                                               //~7719I~
//  else if (ucs < table[mid].first)                               //~7719I~//~v6BjR~
    else if ((int)ucs < table[mid].first)                          //~v6BjI~
      max = mid - 1;                                               //~7719I~
    else                                                           //~7719I~
      return 1;                                                    //~7719I~
  }                                                                //~7719I~
                                                                   //~7719I~
  return 0;                                                        //~7719I~
}                                                                  //~7719I~
#ifndef UTF8SUPPH                                                  //~v62UR~//~v62XR~
                                                                   //~7719I~
/* The following two functions define the column width of an ISO 10646//~7719I~
 * character as follows:                                           //~7719I~
 *                                                                 //~7719I~
 *    - The null character (U+0000) has a column width of 0.       //~7719I~
 *                                                                 //~7719I~
 *    - Other C0/C1 control characters and DEL will lead to a return//~7719I~
 *      value of -1.                                               //~7719I~
 *                                                                 //~7719I~
 *    - Non-spacing and enclosing combining characters (general    //~7719I~
 *      category code Mn or Me in the Unicode database) have a     //~7719I~
 *      column width of 0.                                         //~7719I~
 *                                                                 //~7719I~
 *    - SOFT HYPHEN (U+00AD) has a column width of 1.              //~7719I~
 *                                                                 //~7719I~
 *    - Other format characters (general category code Cf in the Unicode//~7719I~
 *      database) and ZERO WIDTH SPACE (U+200B) have a column width of 0.//~7719I~
 *                                                                 //~7719I~
 *    - Hangul Jamo medial vowels and final consonants (U+1160-U+11FF)//~7719I~
 *      have a column width of 0.                                  //~7719I~
 *                                                                 //~7719I~
 *    - Spacing characters in the East Asian Wide (W) or East Asian//~7719I~
 *      Full-width (F) category as defined in Unicode Technical    //~7719I~
 *      Report #11 have a column width of 2.                       //~7719I~
 *                                                                 //~7719I~
 *    - All remaining characters (including all printable          //~7719I~
 *      ISO 8859-1 and WGL4 characters, Unicode control characters,//~7719I~
 *      etc.) have a column width of 1.                            //~7719I~
 *                                                                 //~7719I~
 * This implementation assumes that wchar_t characters are encoded //~7719I~
 * in ISO 10646.                                                   //~7719I~
 */                                                                //~7719I~
                                                                   //~7719I~
//int mk_wcwidth(wchar_t ucs)                                       //~v5ncR~//~v650R~//~v6a0R~
int mk_wcwidth(UWCHART ucs)                                        //~v6a0R~
{                                                                  //~7719I~
  /* sorted list of non-overlapping intervals of non-spacing characters *///~7719I~
  /* generated by "uniset +cat=Me +cat=Mn +cat=Cf -00AD +1160-11FF +200B c" *///~7719I~
  static const struct interval combining[] = {                     //~7719I~
    { 0x0300, 0x036F }, { 0x0483, 0x0486 }, { 0x0488, 0x0489 },
    { 0x0591,0x05BD  }, { 0x05BF, 0x05BF }, { 0x05C1, 0x05C2 },
    { 0x05C4, 0x05C5 }, { 0x05C7, 0x05C7 }, { 0x0600, 0x0603 },
    { 0x0610, 0x0615 }, { 0x064B, 0x065E }, { 0x0670, 0x0670 },
    { 0x06D6, 0x06E4 }, { 0x06E7, 0x06E8 }, { 0x06EA, 0x06ED },
    { 0x070F, 0x070F }, { 0x0711, 0x0711 }, { 0x0730, 0x074A },
    { 0x07A6, 0x07B0 }, { 0x07EB, 0x07F3 }, { 0x0901, 0x0902 },
    { 0x093C, 0x093C }, { 0x0941, 0x0948 }, { 0x094D, 0x094D },
    { 0x0951, 0x0954 }, { 0x0962, 0x0963 }, { 0x0981, 0x0981 },
    { 0x09BC, 0x09BC }, { 0x09C1, 0x09C4 }, { 0x09CD, 0x09CD },
    { 0x09E2, 0x09E3 }, { 0x0A01, 0x0A02 }, { 0x0A3C, 0x0A3C },
    { 0x0A41, 0x0A42 }, { 0x0A47, 0x0A48 }, { 0x0A4B, 0x0A4D },
    { 0x0A70, 0x0A71 }, { 0x0A81, 0x0A82 }, { 0x0ABC, 0x0ABC },
    { 0x0AC1, 0x0AC5 }, { 0x0AC7, 0x0AC8 }, { 0x0ACD, 0x0ACD },
    { 0x0AE2, 0x0AE3 }, { 0x0B01, 0x0B01 }, { 0x0B3C, 0x0B3C },
    { 0x0B3F, 0x0B3F }, { 0x0B41, 0x0B43 }, { 0x0B4D, 0x0B4D },
    { 0x0B56, 0x0B56 }, { 0x0B82, 0x0B82 }, { 0x0BC0, 0x0BC0 },
    { 0x0BCD, 0x0BCD }, { 0x0C3E, 0x0C40 }, { 0x0C46, 0x0C48 },
    { 0x0C4A, 0x0C4D }, { 0x0C55, 0x0C56 }, { 0x0CBC, 0x0CBC },
    { 0x0CBF, 0x0CBF }, { 0x0CC6, 0x0CC6 }, { 0x0CCC, 0x0CCD },
    { 0x0CE2, 0x0CE3 }, { 0x0D41, 0x0D43 }, { 0x0D4D, 0x0D4D },
    { 0x0DCA, 0x0DCA }, { 0x0DD2, 0x0DD4 }, { 0x0DD6, 0x0DD6 },
    { 0x0E31, 0x0E31 }, { 0x0E34, 0x0E3A }, { 0x0E47, 0x0E4E },
    { 0x0EB1, 0x0EB1 }, { 0x0EB4, 0x0EB9 }, { 0x0EBB, 0x0EBC },
    { 0x0EC8, 0x0ECD }, { 0x0F18, 0x0F19 }, { 0x0F35, 0x0F35 },
    { 0x0F37, 0x0F37 }, { 0x0F39, 0x0F39 }, { 0x0F71, 0x0F7E },
    { 0x0F80, 0x0F84 }, { 0x0F86, 0x0F87 }, { 0x0F90, 0x0F97 },
    { 0x0F99, 0x0FBC }, { 0x0FC6, 0x0FC6 }, { 0x102D, 0x1030 },
    { 0x1032, 0x1032 }, { 0x1036, 0x1037 }, { 0x1039, 0x1039 },
    { 0x1058, 0x1059 }, { 0x1160, 0x11FF }, { 0x135F, 0x135F },
    { 0x1712, 0x1714 }, { 0x1732, 0x1734 }, { 0x1752, 0x1753 },
    { 0x1772, 0x1773 }, { 0x17B4, 0x17B5 }, { 0x17B7, 0x17BD },
    { 0x17C6, 0x17C6 }, { 0x17C9, 0x17D3 }, { 0x17DD, 0x17DD },
    { 0x180B, 0x180D }, { 0x18A9, 0x18A9 }, { 0x1920, 0x1922 },
    { 0x1927, 0x1928 }, { 0x1932, 0x1932 }, { 0x1939, 0x193B },
    { 0x1A17, 0x1A18 }, { 0x1B00, 0x1B03 }, { 0x1B34, 0x1B34 },
    { 0x1B36, 0x1B3A }, { 0x1B3C, 0x1B3C }, { 0x1B42, 0x1B42 },
    { 0x1B6B, 0x1B73 }, { 0x1DC0, 0x1DCA }, { 0x1DFE, 0x1DFF },
    { 0x200B, 0x200F }, { 0x202A, 0x202E }, { 0x2060, 0x2063 },
    { 0x206A, 0x206F }, { 0x20D0, 0x20EF }, { 0x302A, 0x302F },
    { 0x3099, 0x309A }, { 0xA806, 0xA806 }, { 0xA80B, 0xA80B },
    { 0xA825, 0xA826 }, { 0xFB1E, 0xFB1E }, { 0xFE00, 0xFE0F },
    { 0xFE20, 0xFE23 }, { 0xFEFF, 0xFEFF }, { 0xFFF9, 0xFFFB },
    { 0x10A01, 0x10A03 }, { 0x10A05, 0x10A06 }, { 0x10A0C, 0x10A0F },
    { 0x10A38, 0x10A3A }, { 0x10A3F, 0x10A3F }, { 0x1D167, 0x1D169 },
    { 0x1D173, 0x1D182 }, { 0x1D185, 0x1D18B }, { 0x1D1AA, 0x1D1AD },
    { 0x1D242, 0x1D244 }, { 0xE0001, 0xE0001 }, { 0xE0020, 0xE007F },
    { 0xE0100, 0xE01EF }
  };                                                               //~7719I~
                                                                   //~8A31I~
  /* test for 8-bit control characters */                          //~7719I~
  if (ucs == 0)                                                    //~7719I~
    return 0;                                                      //~7719I~
  if (ucs < 32 || (ucs >= 0x7f && ucs < 0xa0))                     //~7719I~
    return -1;                                                     //~7719I~
#ifndef ARM	//non spacing chk at java(Ucs.java)                    //~v6a0R~
  /* binary search in table of non-spacing characters */           //~7719I~
  if (bisearch(ucs, combining,                                     //~7719I~
	       sizeof(combining) / sizeof(struct interval) - 1))       //~7719I~
    return 0;                                                      //~7719I~
#endif                                                                   //~7719I~//~v6a0R~
  /* if we arrive here, ucs is not a combining or C0/C1 control character *///~7719I~
                                                                   //~7719I~
  return 1 +                                                       //~7719I~
    (ucs >= 0x1100 &&                                              //~7719I~
     (ucs <= 0x115f ||                    /* Hangul Jamo init. consonants *///~7719I~
      ucs == 0x2329 || ucs == 0x232a ||                            //~7719I~
      ucs == 0x23ce ||                                             //~v6L0I~
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&                           //~7719I~
       ucs != 0x303f) ||                  /* CJK ... Yi */         //~7719I~
      (ucs >= 0xac00 && ucs <= 0xd7a3) || /* Hangul Syllables */   //~7719I~
      (ucs >= 0xf900 && ucs <= 0xfaff) || /* CJK Compatibility Ideographs *///~7719I~
      (ucs >= 0xfe10 && ucs <= 0xfe19) || /* Vertical forms */     //~7719I~
      (ucs >= 0xfe30 && ucs <= 0xfe6f) || /* CJK Compatibility Forms *///~7719I~
      (ucs >= 0xff00 && ucs <= 0xff60) || /* Fullwidth Forms */    //~7719I~
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||                          //~7719I~
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||                        //~7719I~
      (ucs >= 0x30000 && ucs <= 0x3fffd)));                        //~7719I~
}                                                                  //~7719I~
#else                                                              //~7719I~
//***********************************************************************
//By 2009/10 Unicode 5.2.0                                         //~v62UR~
//***********************************************************************
#ifdef AAA                                                         //~v650I~
#ifdef UTF8UCS2                                                    //~v647R~
int mk_wcwidth(UWCHART ucs)                                        //~v647R~
#else                                                              //~v647R~
int mk_wcwidth(wchar_t ucs)
#endif                                                             //~v647R~
{
#endif   //AAA                                                     //~v650I~
#ifdef BBB                                                         //~v6W9I~
//*ncurses-6.0 2018/06/06 confirmed                                //~v6V2I~
  static const struct interval combining[] = {
	{ 0x0300, 0x036F },
    { 0x0483, 0x0486 },
    { 0x0488, 0x0489 },
    { 0x0591, 0x05BD },
    { 0x05BF, 0x05BF },
    { 0x05C1, 0x05C2 },
    { 0x05C4, 0x05C5 },
    { 0x05C7, 0x05C7 },
    { 0x0600, 0x0603 },
    { 0x0610, 0x0615 },
    { 0x064B, 0x065E },
    { 0x0670, 0x0670 },
    { 0x06D6, 0x06E4 },
    { 0x06E7, 0x06E8 },
    { 0x06EA, 0x06ED },
    { 0x070F, 0x070F },
    { 0x0711, 0x0711 },
    { 0x0730, 0x074A },
    { 0x07A6, 0x07B0 },
    { 0x07EB, 0x07F3 },
//  { 0x0800, 0x08ff },    //not defined                           //~v62UR~
    { 0x0901, 0x0902 },
    { 0x093C, 0x093C },
    { 0x0941, 0x0948 },
    { 0x094D, 0x094D },
    { 0x0951, 0x0954 },
    { 0x0962, 0x0963 },
    { 0x0981, 0x0981 },
    { 0x09BC, 0x09BC },
    { 0x09C1, 0x09C4 },
    { 0x09CD, 0x09CD },
    { 0x09E2, 0x09E3 },
    { 0x0A01, 0x0A02 },
    { 0x0A3C, 0x0A3C },
    { 0x0A41, 0x0A42 },
    { 0x0A47, 0x0A48 },
    { 0x0A4B, 0x0A4D },
    { 0x0A70, 0x0A71 },
    { 0x0A81, 0x0A82 },
    { 0x0ABC, 0x0ABC },
    { 0x0AC1, 0x0AC5 },
    { 0x0AC7, 0x0AC8 },
    { 0x0ACD, 0x0ACD },
    { 0x0AE2, 0x0AE3 },
    { 0x0B01, 0x0B01 },
    { 0x0B3C, 0x0B3C },
    { 0x0B3F, 0x0B3F },
    { 0x0B41, 0x0B43 },
    { 0x0B4D, 0x0B4D },
    { 0x0B56, 0x0B56 },
    { 0x0B82, 0x0B82 },
    { 0x0BC0, 0x0BC0 },
    { 0x0BCD, 0x0BCD },
    { 0x0C3E, 0x0C40 },
    { 0x0C46, 0x0C48 },
    { 0x0C4A, 0x0C4D },
    { 0x0C55, 0x0C56 },
    { 0x0CBC, 0x0CBC },
    { 0x0CBF, 0x0CBF },
    { 0x0CC6, 0x0CC6 },
    { 0x0CCC, 0x0CCD },
    { 0x0CE2, 0x0CE3 },
    { 0x0D41, 0x0D43 },
    { 0x0D4D, 0x0D4D },
    { 0x0DCA, 0x0DCA },
    { 0x0DD2, 0x0DD4 },
    { 0x0DD6, 0x0DD6 },
    { 0x0E31, 0x0E31 },
    { 0x0E34, 0x0E3A },
    { 0x0E47, 0x0E4E },
    { 0x0EB1, 0x0EB1 },
    { 0x0EB4, 0x0EB9 },
    { 0x0EBB, 0x0EBC },
    { 0x0EC8, 0x0ECD },
    { 0x0F18, 0x0F19 },
    { 0x0F35, 0x0F35 },
    { 0x0F37, 0x0F37 },
    { 0x0F39, 0x0F39 },
    { 0x0F71, 0x0F7E },
    { 0x0F80, 0x0F84 },
    { 0x0F86, 0x0F87 },
    { 0x0F90, 0x0F97 },
    { 0x0F99, 0x0FBC },
    { 0x0FC6, 0x0FC6 },
    { 0x102D, 0x1030 },
    { 0x1032, 0x1032 },
    { 0x1036, 0x1037 },
    { 0x1039, 0x1039 },
    { 0x1058, 0x1059 },
    { 0x1160, 0x11FF },
    { 0x135F, 0x135F },
    { 0x1712, 0x1714 },
    { 0x1732, 0x1734 },
    { 0x1752, 0x1753 },
    { 0x1772, 0x1773 },
    { 0x17B4, 0x17B5 },
    { 0x17B7, 0x17BD },
    { 0x17C6, 0x17C6 },
    { 0x17C9, 0x17D3 },
    { 0x17DD, 0x17DD },
    { 0x180B, 0x180D },
    { 0x18A9, 0x18A9 },
//  { 0x18b0, 0x18ff },  //not assigned                            //~v62UR~
    { 0x1920, 0x1922 },
    { 0x1927, 0x1928 },
    { 0x1932, 0x1932 },
    { 0x1939, 0x193B },
    { 0x1A17, 0x1A18 },
//  { 0x1A20, 0x1Aff },  //not defined                             //~v62UR~
    { 0x1B00, 0x1B03 },
    { 0x1B34, 0x1B34 },
    { 0x1B36, 0x1B3A },
    { 0x1B3C, 0x1B3C },
    { 0x1B42, 0x1B42 },
    { 0x1B6B, 0x1B73 },
//  { 0x1Bc0, 0x1Bff },  //not assigned                            //~v62UR~
//  { 0x1c80, 0x1cff },  //not assigned                            //~v62UR~
    { 0x1DC0, 0x1DCA },
    { 0x1DFE, 0x1DFF },
    { 0x200B, 0x200F },
    { 0x202A, 0x202E },
    { 0x2060, 0x2063 },
    { 0x206A, 0x206F },
    { 0x20D0, 0x20EF },
    { 0x302A, 0x302F },
    { 0x3099, 0x309A },
//  { 0xa4d0, 0xa4ff },  //not assigned                            //~v62UR~
//  { 0xa5a0, 0xa63f },  //not assigned                            //~v62UR~
//  { 0xa6a0, 0xa6ff },  //not assigned                            //~v62UR~
    { 0xA806, 0xA806 },
    { 0xA80B, 0xA80B },
    { 0xA825, 0xA826 },
//  { 0xa830, 0xa83f },  //not assigned                            //~v62UR~
//  { 0xa8e0, 0xa8ff },  //not assigned                            //~v62UR~
//  { 0xa960, 0xa9ff },  //not assigned                            //~v62UR~
//  { 0xaa60, 0xabff },  //not assigned                            //~v62UR~
//  { 0xd7b0, 0xd7ff },  //not assigned                            //~v62UR~
    { 0xFB1E, 0xFB1E },
    { 0xFE00, 0xFE0F },
    { 0xFE20, 0xFE23 },
    { 0xFEFF, 0xFEFF },
    { 0xFFF9, 0xFFFB },
//  { 0x10200, 0x1027f },  //not assigned                          //~v62UR~
//  { 0x102e0, 0x102ff },  //not assigned                          //~v62UR~
//  { 0x10350, 0x1037f },  //not assigned                          //~v62UR~
//  { 0x103e0, 0x103ff },  //not assigned                          //~v62UR~
//  { 0x104b0, 0x107ff },  //not assigned                          //~v62UR~
//  { 0x10840, 0x108ff },  //not assigned                          //~v62UR~
//  { 0x10940, 0x109ff },  //not assigned                          //~v62UR~
    { 0x10A01, 0x10A03 },
    { 0x10A05, 0x10A06 },
    { 0x10A0C, 0x10A0F },
    { 0x10A38, 0x10A3A },
    { 0x10A3F, 0x10A3F },
//  { 0x10a60, 0x11fff },  //not assigned                          //~v62UR~
//  { 0x12480, 0x1c000 },  //not assigned                          //~v62UR~
    { 0x1D167, 0x1D169 },
    { 0x1D173, 0x1D182 },
    { 0x1D185, 0x1D18B },
    { 0x1D1AA, 0x1D1AD },
    { 0x1D242, 0x1D244 },
//  { 0x1d250, 0x1d2ff },  //not assigned                          //~v62UR~
//  { 0x1d380, 0x1d3ff },  //not assigned                          //~v62UR~
//  { 0x1d800, 0x1efff },  //not assigned                          //~v62UR~
//  { 0x1f0a0, 0x1ffff },  //not assigned                          //~v62UR~
//  { 0x2a6e0, 0x2f7ff },  //not assigned                          //~v62UR~
//  { 0x2aa20, 0xdffff },  //not assigned                          //~v62UR~
    { 0xE0001, 0xE0001 },
    { 0xE0020, 0xE007F },
//  { 0xe0080, 0xe00ff },  //not assigned                          //~v62UR~
    { 0xE0100, 0xE01EF }                                           //~7719I~
//  { 0xe01f0, 0xeffff },  //not assigned                          //~v62UR~
  };
#else  //!BBB                                                      //~v6W9I~
  static const struct interval combining[] = { // 2018/07/11 by //www.fileformat.info/info/unicode/category/Mn/list.htm//~v6WcR~
{0x00300 ,0x0036F },                                               //~v6WcI~
{0x00483 ,0x00487 },                                               //~v6WcI~
 {0x0488     ,0x0489  },  //Me(Mark,Enclosing)                                  ||+8722R~//~v6WjI~
{0x00591 ,0x005BD },                                               //~v6WcI~
{0x005BF ,0x005BF },                                               //~v6WcI~
{0x005C1 ,0x005C2 },                                               //~v6WcI~
{0x005C4 ,0x005C5 },                                               //~v6WcI~
{0x005C7 ,0x005C7 },                                               //~v6WcI~
{0x00610 ,0x0061A },                                               //~v6WcI~
{0x0064B ,0x0065F },                                               //~v6WcI~
{0x00670 ,0x00670 },                                               //~v6WcI~
{0x006D6 ,0x006DC },                                               //~v6WcI~
{0x006DF ,0x006E4 },                                               //~v6WcI~
{0x006E7 ,0x006E8 },                                               //~v6WcI~
{0x006EA ,0x006ED },                                               //~v6WcI~
{0x00711 ,0x00711 },                                               //~v6WcI~
{0x00730 ,0x0074A },                                               //~v6WcI~
{0x007A6 ,0x007B0 },                                               //~v6WcI~
{0x007EB ,0x007F3 },                                               //~v6WcI~
{0x007FD ,0x007FD },                                               //~v6WcI~
{0x00816 ,0x00819 },                                               //~v6WcI~
{0x0081B ,0x00823 },                                               //~v6WcI~
{0x00825 ,0x00827 },                                               //~v6WcI~
{0x00829 ,0x0082D },                                               //~v6WcI~
{0x00859 ,0x0085B },                                               //~v6WcI~
{0x008D3 ,0x008E1 },                                               //~v6WcI~
{0x008E3 ,0x00902 },                                               //~v6WcI~
{0x0093A ,0x0093A },                                               //~v6WcI~
{0x0093C ,0x0093C },                                               //~v6WcI~
{0x00941 ,0x00948 },                                               //~v6WcI~
{0x0094D ,0x0094D },                                               //~v6WcI~
{0x00951 ,0x00957 },                                               //~v6WcI~
{0x00962 ,0x00963 },                                               //~v6WcI~
{0x00981 ,0x00981 },                                               //~v6WcI~
{0x009BC ,0x009BC },                                               //~v6WcI~
{0x009C1 ,0x009C4 },                                               //~v6WcI~
{0x009CD ,0x009CD },                                               //~v6WcI~
{0x009E2 ,0x009E3 },                                               //~v6WcI~
{0x009FE ,0x009FE },                                               //~v6WcI~
{0x00A01 ,0x00A02 },                                               //~v6WcI~
{0x00A3C ,0x00A3C },                                               //~v6WcI~
{0x00A41 ,0x00A42 },                                               //~v6WcI~
{0x00A47 ,0x00A48 },                                               //~v6WcI~
{0x00A4B ,0x00A4D },                                               //~v6WcI~
{0x00A51 ,0x00A51 },                                               //~v6WcI~
{0x00A70 ,0x00A71 },                                               //~v6WcI~
{0x00A75 ,0x00A75 },                                               //~v6WcI~
{0x00A81 ,0x00A82 },                                               //~v6WcI~
{0x00ABC ,0x00ABC },                                               //~v6WcI~
{0x00AC1 ,0x00AC5 },                                               //~v6WcI~
{0x00AC7 ,0x00AC8 },                                               //~v6WcI~
{0x00ACD ,0x00ACD },                                               //~v6WcI~
{0x00AE2 ,0x00AE3 },                                               //~v6WcI~
{0x00AFA ,0x00AFF },                                               //~v6WcI~
{0x00B01 ,0x00B01 },                                               //~v6WcI~
{0x00B3C ,0x00B3C },                                               //~v6WcI~
{0x00B3F ,0x00B3F },                                               //~v6WcI~
{0x00B41 ,0x00B44 },                                               //~v6WcI~
{0x00B4D ,0x00B4D },                                               //~v6WcI~
{0x00B56 ,0x00B56 },                                               //~v6WcI~
{0x00B62 ,0x00B63 },                                               //~v6WcI~
{0x00B82 ,0x00B82 },                                               //~v6WcI~
{0x00BC0 ,0x00BC0 },                                               //~v6WcI~
{0x00BCD ,0x00BCD },                                               //~v6WcI~
{0x00C00 ,0x00C00 },                                               //~v6WcI~
{0x00C04 ,0x00C04 },                                               //~v6WcI~
{0x00C3E ,0x00C40 },                                               //~v6WcI~
{0x00C46 ,0x00C48 },                                               //~v6WcI~
{0x00C4A ,0x00C4D },                                               //~v6WcI~
{0x00C55 ,0x00C56 },                                               //~v6WcI~
{0x00C62 ,0x00C63 },                                               //~v6WcI~
{0x00C81 ,0x00C81 },                                               //~v6WcI~
{0x00CBC ,0x00CBC },                                               //~v6WcI~
{0x00CBF ,0x00CBF },                                               //~v6WcI~
{0x00CC6 ,0x00CC6 },                                               //~v6WcI~
{0x00CCC ,0x00CCD },                                               //~v6WcI~
{0x00CE2 ,0x00CE3 },                                               //~v6WcI~
{0x00D00 ,0x00D01 },                                               //~v6WcI~
{0x00D3B ,0x00D3C },                                               //~v6WcI~
{0x00D41 ,0x00D44 },                                               //~v6WcI~
{0x00D4D ,0x00D4D },                                               //~v6WcI~
{0x00D62 ,0x00D63 },                                               //~v6WcI~
{0x00DCA ,0x00DCA },                                               //~v6WcI~
{0x00DD2 ,0x00DD4 },                                               //~v6WcI~
{0x00DD6 ,0x00DD6 },                                               //~v6WcI~
{0x00E31 ,0x00E31 },                                               //~v6WcI~
{0x00E34 ,0x00E3A },                                               //~v6WcI~
{0x00E47 ,0x00E4E },                                               //~v6WcI~
{0x00EB1 ,0x00EB1 },                                               //~v6WcI~
{0x00EB4 ,0x00EB9 },                                               //~v6WcI~
{0x00EBB ,0x00EBC },                                               //~v6WcI~
{0x00EC8 ,0x00ECD },                                               //~v6WcI~
{0x00F18 ,0x00F19 },                                               //~v6WcI~
{0x00F35 ,0x00F35 },                                               //~v6WcI~
{0x00F37 ,0x00F37 },                                               //~v6WcI~
{0x00F39 ,0x00F39 },                                               //~v6WcI~
{0x00F71 ,0x00F7E },                                               //~v6WcI~
{0x00F80 ,0x00F84 },                                               //~v6WcI~
{0x00F86 ,0x00F87 },                                               //~v6WcI~
{0x00F8D ,0x00F97 },                                               //~v6WcI~
{0x00F99 ,0x00FBC },                                               //~v6WcI~
{0x00FC6 ,0x00FC6 },                                               //~v6WcI~
{0x0102D ,0x01030 },                                               //~v6WcI~
{0x01032 ,0x01037 },                                               //~v6WcI~
{0x01039 ,0x0103A },                                               //~v6WcI~
{0x0103D ,0x0103E },                                               //~v6WcI~
{0x01058 ,0x01059 },                                               //~v6WcI~
{0x0105E ,0x01060 },                                               //~v6WcI~
{0x01071 ,0x01074 },                                               //~v6WcI~
{0x01082 ,0x01082 },                                               //~v6WcI~
{0x01085 ,0x01086 },                                               //~v6WcI~
{0x0108D ,0x0108D },                                               //~v6WcI~
{0x0109D ,0x0109D },                                               //~v6WcI~
#ifdef GGG                                                         //~v6X3I~
//  { 0x1160, 0x11FF },      //hangul                     //~v6WgI~//~v6X0R~//~v6X3R~
#else                                                              //~v6X3I~
  { 0x1160, 0x11FF },      //hangul,combining                      //~v6X3I~
#endif                                                             //~v6X3I~
{0x0135D ,0x0135F },                                               //~v6WcI~
{0x01712 ,0x01714 },                                               //~v6WcI~
{0x01732 ,0x01734 },                                               //~v6WcI~
{0x01752 ,0x01753 },                                               //~v6WcI~
{0x01772 ,0x01773 },                                               //~v6WcI~
{0x017B4 ,0x017B5 },                                               //~v6WcI~
{0x017B7 ,0x017BD },                                               //~v6WcI~
{0x017C6 ,0x017C6 },                                               //~v6WcI~
{0x017C9 ,0x017D3 },                                               //~v6WcI~
{0x017DD ,0x017DD },                                               //~v6WcI~
{0x0180B ,0x0180D },                                               //~v6WcI~
{0x01885 ,0x01886 },                                               //~v6WcI~
{0x018A9 ,0x018A9 },                                               //~v6WcI~
{0x01920 ,0x01922 },                                               //~v6WcI~
{0x01927 ,0x01928 },                                               //~v6WcI~
{0x01932 ,0x01932 },                                               //~v6WcI~
{0x01939 ,0x0193B },                                               //~v6WcI~
{0x01A17 ,0x01A18 },                                               //~v6WcI~
{0x01A1B ,0x01A1B },                                               //~v6WcI~
{0x01A56 ,0x01A56 },                                               //~v6WcI~
{0x01A58 ,0x01A5E },                                               //~v6WcI~
{0x01A60 ,0x01A60 },                                               //~v6WcI~
{0x01A62 ,0x01A62 },                                               //~v6WcI~
{0x01A65 ,0x01A6C },                                               //~v6WcI~
{0x01A73 ,0x01A7C },                                               //~v6WcI~
{0x01A7F ,0x01A7F },                                               //~v6WcI~
{0x01AB0 ,0x01ABD },                                               //~v6WcI~
 {0x1ABE     ,0x1ABE  },  //Me(Mark,Enclosing)                                  ||+8722R~//~v6WjI~
{0x01B00 ,0x01B03 },                                               //~v6WcI~
{0x01B34 ,0x01B34 },                                               //~v6WcI~
{0x01B36 ,0x01B3A },                                               //~v6WcI~
{0x01B3C ,0x01B3C },                                               //~v6WcI~
{0x01B42 ,0x01B42 },                                               //~v6WcI~
{0x01B6B ,0x01B73 },                                               //~v6WcI~
{0x01B80 ,0x01B81 },                                               //~v6WcI~
{0x01BA2 ,0x01BA5 },                                               //~v6WcI~
{0x01BA8 ,0x01BA9 },                                               //~v6WcI~
{0x01BAB ,0x01BAD },                                               //~v6WcI~
{0x01BE6 ,0x01BE6 },                                               //~v6WcI~
{0x01BE8 ,0x01BE9 },                                               //~v6WcI~
{0x01BED ,0x01BED },                                               //~v6WcI~
{0x01BEF ,0x01BF1 },                                               //~v6WcI~
{0x01C2C ,0x01C33 },                                               //~v6WcI~
{0x01C36 ,0x01C37 },                                               //~v6WcI~
{0x01CD0 ,0x01CD2 },                                               //~v6WcI~
{0x01CD4 ,0x01CE0 },                                               //~v6WcI~
{0x01CE2 ,0x01CE8 },                                               //~v6WcI~
{0x01CED ,0x01CED },                                               //~v6WcI~
{0x01CF4 ,0x01CF4 },                                               //~v6WcI~
{0x01CF8 ,0x01CF9 },                                               //~v6WcI~
{0x01DC0 ,0x01DF9 },                                               //~v6WcI~
{0x01DFB ,0x01DFF },                                               //~v6WcI~
{0x020D0 ,0x020DC },                                               //~v6WcI~
 {0x20DD     ,0x20E0  },  //Me(Mark,Enclosing)                                  ||+8722R~//~v6WjI~
{0x020E1 ,0x020E1 },                                               //~v6WcI~
 {0x20E2     ,0x20E4  },  //Me(Mark,Enclosing)                                  ||+8722R~//~v6WjI~
{0x020E5 ,0x020F0 },                                               //~v6WcI~
{0x02CEF ,0x02CF1 },                                               //~v6WcI~
{0x02D7F ,0x02D7F },                                               //~v6WcI~
{0x02DE0 ,0x02DFF },                                               //~v6WcI~
{0x0302A ,0x0302D },                                               //~v6WcI~
{0x03099 ,0x0309A },                                               //~v6WcI~
{0x0A66F ,0x0A66F },                                               //~v6WcI~
 {0xA670     ,0xA672  },  //Me(Mark,Enclosing)                                  ||+8722R~//~v6WjM~
{0x0A674 ,0x0A67D },                                               //~v6WcI~
{0x0A69E ,0x0A69F },                                               //~v6WcI~
{0x0A6F0 ,0x0A6F1 },                                               //~v6WcI~
{0x0A802 ,0x0A802 },                                               //~v6WcI~
{0x0A806 ,0x0A806 },                                               //~v6WcI~
{0x0A80B ,0x0A80B },                                               //~v6WcI~
{0x0A825 ,0x0A826 },                                               //~v6WcI~
{0x0A8C4 ,0x0A8C5 },                                               //~v6WcI~
{0x0A8E0 ,0x0A8F1 },                                               //~v6WcI~
{0x0A8FF ,0x0A8FF },                                               //~v6WcI~
{0x0A926 ,0x0A92D },                                               //~v6WcI~
{0x0A947 ,0x0A951 },                                               //~v6WcI~
{0x0A980 ,0x0A982 },                                               //~v6WcI~
{0x0A9B3 ,0x0A9B3 },                                               //~v6WcI~
{0x0A9B6 ,0x0A9B9 },                                               //~v6WcI~
{0x0A9BC ,0x0A9BC },                                               //~v6WcI~
{0x0A9E5 ,0x0A9E5 },                                               //~v6WcI~
{0x0AA29 ,0x0AA2E },                                               //~v6WcI~
{0x0AA31 ,0x0AA32 },                                               //~v6WcI~
{0x0AA35 ,0x0AA36 },                                               //~v6WcI~
{0x0AA43 ,0x0AA43 },                                               //~v6WcI~
{0x0AA4C ,0x0AA4C },                                               //~v6WcI~
{0x0AA7C ,0x0AA7C },                                               //~v6WcI~
{0x0AAB0 ,0x0AAB0 },                                               //~v6WcI~
{0x0AAB2 ,0x0AAB4 },                                               //~v6WcI~
{0x0AAB7 ,0x0AAB8 },                                               //~v6WcI~
{0x0AABE ,0x0AABF },                                               //~v6WcI~
{0x0AAC1 ,0x0AAC1 },                                               //~v6WcI~
{0x0AAEC ,0x0AAED },                                               //~v6WcI~
{0x0AAF6 ,0x0AAF6 },                                               //~v6WcI~
{0x0ABE5 ,0x0ABE5 },                                               //~v6WcI~
{0x0ABE8 ,0x0ABE8 },                                               //~v6WcI~
{0x0ABED ,0x0ABED },                                               //~v6WcI~
{0x0FB1E ,0x0FB1E },                                               //~v6WcI~
{0x0FE00 ,0x0FE0F },                                               //~v6WcI~
{0x0FE20 ,0x0FE2F },                                               //~v6WcI~
{0x101FD ,0x101FD },                                               //~v6WcI~
{0x102E0 ,0x102E0 },                                               //~v6WcI~
{0x10376 ,0x1037A },                                               //~v6WcI~
{0x10A01 ,0x10A03 },                                               //~v6WcI~
{0x10A05 ,0x10A06 },                                               //~v6WcI~
{0x10A0C ,0x10A0F },                                               //~v6WcI~
{0x10A38 ,0x10A3A },                                               //~v6WcI~
{0x10A3F ,0x10A3F },                                               //~v6WcI~
{0x10AE5 ,0x10AE6 },                                               //~v6WcI~
{0x10D24 ,0x10D27 },                                               //~v6WcI~
{0x10F46 ,0x10F50 },                                               //~v6WcI~
{0x11001 ,0x11001 },                                               //~v6WcI~
{0x11038 ,0x11046 },                                               //~v6WcI~
{0x1107F ,0x11081 },                                               //~v6WcI~
{0x110B3 ,0x110B6 },                                               //~v6WcI~
{0x110B9 ,0x110BA },                                               //~v6WcI~
{0x11100 ,0x11102 },                                               //~v6WcI~
{0x11127 ,0x1112B },                                               //~v6WcI~
{0x1112D ,0x11134 },                                               //~v6WcI~
{0x11173 ,0x11173 },                                               //~v6WcI~
{0x11180 ,0x11181 },                                               //~v6WcI~
{0x111B6 ,0x111BE },                                               //~v6WcI~
{0x111C9 ,0x111CC },                                               //~v6WcI~
{0x1122F ,0x11231 },                                               //~v6WcI~
{0x11234 ,0x11234 },                                               //~v6WcI~
{0x11236 ,0x11237 },                                               //~v6WcI~
{0x1123E ,0x1123E },                                               //~v6WcI~
{0x112DF ,0x112DF },                                               //~v6WcI~
{0x112E3 ,0x112EA },                                               //~v6WcI~
{0x11300 ,0x11301 },                                               //~v6WcI~
{0x1133B ,0x1133C },                                               //~v6WcI~
{0x11340 ,0x11340 },                                               //~v6WcI~
{0x11366 ,0x1136C },                                               //~v6WcI~
{0x11370 ,0x11374 },                                               //~v6WcI~
{0x11438 ,0x1143F },                                               //~v6WcI~
{0x11442 ,0x11444 },                                               //~v6WcI~
{0x11446 ,0x11446 },                                               //~v6WcI~
{0x1145E ,0x1145E },                                               //~v6WcI~
{0x114B3 ,0x114B8 },                                               //~v6WcI~
{0x114BA ,0x114BA },                                               //~v6WcI~
{0x114BF ,0x114C0 },                                               //~v6WcI~
{0x114C2 ,0x114C3 },                                               //~v6WcI~
{0x115B2 ,0x115B5 },                                               //~v6WcI~
{0x115BC ,0x115BD },                                               //~v6WcI~
{0x115BF ,0x115C0 },                                               //~v6WcI~
{0x115DC ,0x115DD },                                               //~v6WcI~
{0x11633 ,0x1163A },                                               //~v6WcI~
{0x1163D ,0x1163D },                                               //~v6WcI~
{0x1163F ,0x11640 },                                               //~v6WcI~
{0x116AB ,0x116AB },                                               //~v6WcI~
{0x116AD ,0x116AD },                                               //~v6WcI~
{0x116B0 ,0x116B5 },                                               //~v6WcI~
{0x116B7 ,0x116B7 },                                               //~v6WcI~
{0x1171D ,0x1171F },                                               //~v6WcI~
{0x11722 ,0x11725 },                                               //~v6WcI~
{0x11727 ,0x1172B },                                               //~v6WcI~
{0x1182F ,0x11837 },                                               //~v6WcI~
{0x11839 ,0x1183A },                                               //~v6WcI~
{0x11A01 ,0x11A0A },                                               //~v6WcI~
{0x11A33 ,0x11A38 },                                               //~v6WcI~
{0x11A3B ,0x11A3E },                                               //~v6WcI~
{0x11A47 ,0x11A47 },                                               //~v6WcI~
{0x11A51 ,0x11A56 },                                               //~v6WcI~
{0x11A59 ,0x11A5B },                                               //~v6WcI~
{0x11A8A ,0x11A96 },                                               //~v6WcI~
{0x11A98 ,0x11A99 },                                               //~v6WcI~
{0x11C30 ,0x11C36 },                                               //~v6WcI~
{0x11C38 ,0x11C3D },                                               //~v6WcI~
{0x11C3F ,0x11C3F },                                               //~v6WcI~
{0x11C92 ,0x11CA7 },                                               //~v6WcI~
{0x11CAA ,0x11CB0 },                                               //~v6WcI~
{0x11CB2 ,0x11CB3 },                                               //~v6WcI~
{0x11CB5 ,0x11CB6 },                                               //~v6WcI~
{0x11D31 ,0x11D36 },                                               //~v6WcI~
{0x11D3A ,0x11D3A },                                               //~v6WcI~
{0x11D3C ,0x11D3D },                                               //~v6WcI~
{0x11D3F ,0x11D45 },                                               //~v6WcI~
{0x11D47 ,0x11D47 },                                               //~v6WcI~
{0x11D90 ,0x11D91 },                                               //~v6WcI~
{0x11D95 ,0x11D95 },                                               //~v6WcI~
{0x11D97 ,0x11D97 },                                               //~v6WcI~
{0x11EF3 ,0x11EF4 },                                               //~v6WcI~
{0x16AF0 ,0x16AF4 },                                               //~v6WcI~
{0x16B30 ,0x16B36 },                                               //~v6WcI~
{0x16F8F ,0x16F92 },                                               //~v6WcI~
{0x1BC9D ,0x1BC9E },                                               //~v6WcI~
{0x1D167 ,0x1D169 },                                               //~v6WcI~
{0x1D17B ,0x1D182 },                                               //~v6WcI~
{0x1D185 ,0x1D18B },                                               //~v6WcI~
{0x1D1AA ,0x1D1AD },                                               //~v6WcI~
{0x1D242 ,0x1D244 },                                               //~v6WcI~
{0x1DA00 ,0x1DA36 },                                               //~v6WcI~
{0x1DA3B ,0x1DA6C },                                               //~v6WcI~
{0x1DA75 ,0x1DA75 },                                               //~v6WcI~
{0x1DA84 ,0x1DA84 },                                               //~v6WcI~
{0x1DA9B ,0x1DA9F },                                               //~v6WcI~
{0x1DAA1 ,0x1DAAF },                                               //~v6WcI~
{0x1E000 ,0x1E006 },                                               //~v6WcI~
{0x1E008 ,0x1E018 },                                               //~v6WcI~
{0x1E01B ,0x1E021 },                                               //~v6WcI~
{0x1E023 ,0x1E024 },                                               //~v6WcI~
{0x1E026 ,0x1E02A },                                               //~v6WcI~
{0x1E8D0 ,0x1E8D6 },                                               //~v6WcI~
{0x1E944 ,0x1E94A },                                               //~v6WcI~
{0xE0100 ,0xE01EF },                                               //~v6WcI~
  };                                                               //~v6WcR~
#endif //!BBB                                                      //~v6W9I~
#ifdef AAA                                                         //~v650I~
#else                                                              //~v650M~
#ifdef UTF8UCS2                                                    //~v650I~
//***************************************************************  //~v650M~
//*chk combining char                                              //~v650M~
//*rc:0:combining, 1:not combining                                 //~v6W9I~
//***************************************************************  //~v650M~
//int mk_wcwidth_combining(UWCHART ucs)                              //~v650R~//~v6BjR~
int mk_wcwidth_combining(UWUCS ucs)                                //~v6BjI~
{                                                                  //~v650M~
  	if (bisearch(ucs, combining,                                   //~v650M~
	       sizeof(combining) / sizeof(struct interval) - 1))       //~v650M~
    {                                                              //~v6WnI~
        UTRACEP("%s:%06x is combining char\n",UTT,ucs);            //~v6WnI~
    	return 0;                                                  //~v650M~
    }                                                              //~v6WnI~
    return 1;                                                      //~v650M~
}//mk_wcwidth_combining                                            //~v650R~
#endif                                                             //~v650I~
//***************************************************************  //~v650M~
//*combining and DBCS                                              //~v650M~
//***************************************************************  //~v650M~
//int mk_wcwidth(UWCHART ucs)                                        //~v650R~//~v6BjR~
//int mk_wcwidth(UWUCS ucs)                                          //~v6BjI~//~v6WnR~
int mk_wcwidth(int Popt,UWUCS ucs)                                 //~v6WnI~
{                                                                  //~v650M~
#endif                                                             //~v650M~
    int rc;                                                        //~v6WqI~
//****************************************************             //~v6WqR~
  /* test for 8-bit control characters */
  if (ucs == 0)
    return 0;
  if (ucs < 32 || (ucs >= 0x7f && ucs < 0xa0))
    return -1;

  if (!Sfromcjk)	//mk_wcwidth_cjk already chked isFormat        //~v6WnI~
  {                                                                //~v6WnI~
//  if (utf4_isFormat(0,ucs))                                      //~v6WiR~//~v6WqR~
//      return 1|UTFWWF_RC_MK_WCWIDTH|UTFWWF_RC_FORMAT; //0x01000000+0x04000000//~v6WiI~//~v6WqR~
    if (!mk_wcwidth_combining(ucs)) //rc=0:combining               //~v6WnI~
		return UTFWWF_RC_MK_WCWIDTH|UTFWWF_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6WnI~
  }                                                                //~v6WnI~
  if (!(Popt & SUO_CONSOLE))                                       //~v6WnI~
  	if (UDBCSCHK_ISDBCS())  //CJK(including JP)                    //~v6WnR~
    {                                                              //~v6WnI~
#ifdef LNX    	                                                   //~v6WnI~
		if (utf4_isAmbiguous_XXE(0,(UWUCS)ucs))                    //~v6WnI~
			return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6WnI~
#else                                                              //~v6WnI~
		if (utf4_isAmbiguous_WXE(0,(UWUCS)ucs))                    //~v6WnI~
			return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6WnI~
#endif                                                             //~v6WnI~
    }                                                              //~v6WnI~
  /* binary search in table of non-spacing characters */
//  if (bisearch(ucs, combining,                                   //~v6WnR~
//           sizeof(combining) / sizeof(struct interval) - 1))     //~v6WnR~
//  return 0;                                                      //~v6V7R~
//  return UTFWWF_RC_MK_WCWIDTH;// 0x01000000   //datatype by mk_wcwidth,adjustable by wcwidth()//~v6V7M~//~v6WfR~
//	return UTFWWF_RC_MK_WCWIDTH|UTFWWF_RC_MK_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6WfI~//~v6WmR~
//	return UTFWWF_RC_MK_WCWIDTH|UTFWWF_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6WmI~//~v6WnR~

  /* if we arrive here, ucs is not a combining or C0/C1 control character */

//return 1 +                                                       //~v6WqR~
  rc=    1 +                                                       //~v6WqI~
	UTFWWF_RC_MK_WCWIDTH + //0x01000000  //datatype by mk_wcwidth,adjustable by wcwidth()//~v6V7R~
    (ucs >= 0x1100 &&
//#ifdef UB1710   //test under ub17.10(kernel4.13.0)                 //~v6V1I~//~v6X3R~
//     (ucs <= 0x11ff ||                    /* Hangul Jamo init. consonants */ //@@@@test//~v6V1I~//~v6X3R~
//#else                                                              //~v6V1I~//~v6X3R~
     (ucs <= 0x115f ||                    /* Hangul Jamo init. consonants */
//#endif                                                             //~v6V1I~//~v6X3R~
      ucs == 0x2329 || ucs == 0x232a ||
      ucs == 0x23ce ||                                             //~v6L0I~
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&
       ucs != 0x303f) ||                  /* CJK ... Yi */
      (ucs >= 0xac00 && ucs <= 0xd7a3) || /* Hangul Syllables */
#ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1I~
      (ucs >= 0xd7b0 && ucs <= 0xd7fb) || /* Hangul Jambo Extended-B *///~v6V1I~
#endif                                                             //~v6V1I~
      (ucs >= 0xf900 && ucs <= 0xfaff) || /* CJK Compatibility Ideographs */
#ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V2I~
      (ucs >= 0xfe10 && ucs <= 0xfe1f) || /* Vertical forms */     //~v6V2I~
#else                                                              //~v6V2I~
      (ucs >= 0xfe10 && ucs <= 0xfe19) || /* Vertical forms */
#endif                                                             //~v6V2I~
      (ucs >= 0xfe30 && ucs <= 0xfe6f) || /* CJK Compatibility Forms */
      (ucs >= 0xff00 && ucs <= 0xff60) || /* Fullwidth Forms */
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||
      (ucs >= 0x30000 && ucs <= 0x3fffd)));
//    UTRACEP("%s:rc=%x,ucs=%06x\n",UTT,rc,ucs);                     //~v6WqI~//+v6X5R~
    return rc;                                                     //~v6WqI~
}
#endif
#ifdef AAA                                                         //~v6WnI~
#ifdef UTF8UCS2                                                                   //~7719I~//~v647R~
//int mk_wcswidth(UWCHART *pwcs, size_t n)                           //~v647R~//~v6BjR~
int mk_wcswidth(UWUCS *pwcs, size_t n)                             //~v6BjI~
#else                                                              //~v647R~
int mk_wcswidth(const wchar_t *pwcs, size_t n)                     //~7719I~
#endif                                                             //~v647R~
{                                                                  //~7719I~
  int w, width = 0;                                                //~7719I~
                                                                   //~7719I~
  for (;*pwcs && n-- > 0; pwcs++)                                  //~7719I~
    if ((w = mk_wcwidth(*pwcs)) < 0)                               //~7719I~
      return -1;                                                   //~7719I~
    else                                                           //~7719I~
      width += w;                                                  //~7719I~
                                                                   //~7719I~
  return width;                                                    //~7719I~
}                                                                  //~7719I~
#endif //AAA                                                                   //~7719I~//~v6WnR~
                                                                   //~7719I~
/*                                                                 //~7719I~
 * The following functions are the same as mk_wcwidth() and        //~7719I~
 * mk_wcswidth(), except that spacing characters in the East Asian //~7719I~
 * Ambiguous (A) category as defined in Unicode Technical Report #11//~7719I~
 * have a column width of 2. This variant might be useful for users of//~7719I~
 * CJK legacy encodings who want to migrate to UCS without changing//~7719I~
 * the traditional terminal character-width behaviour. It is not   //~7719I~
 * otherwise recommended for general use.                          //~7719I~
 */                                                                //~7719I~
//#ifdef UTF8UCS2                                                    //~v647R~//~v6VbR~
////int mk_wcwidth_cjk(UWCHART ucs)                                    //~v647R~//~v6BjR~//~v6VbR~
//int mk_wcwidth_cjk(UWUCS ucs)                                      //~v6BjI~//~v6VbR~
//#else                                                              //~v647R~//~v6VbR~
//int mk_wcwidth_cjk(wchar_t ucs)                                    //~7719I~//~v6VbR~
//#endif                                                             //~v647R~//~v6VbR~
//{                                                                  //~7719I~//~v6VbR~
  /* sorted list of non-overlapping intervals of East Asian Ambiguous//~7719I~
   * characters, generated by "uniset +WIDTH-A -cat=Me -cat=Mn -cat=Cf c" *///~7719I~
  static const struct interval ambiguous[] = {                     //~7719I~
#ifdef AAA                                                         //~v62XI~
    { 0x00A1, 0x00A1 }, { 0x00A4, 0x00A4 }, { 0x00A7, 0x00A8 },    //~7719I~
    { 0x00AA, 0x00AA }, { 0x00AE, 0x00AE }, { 0x00B0, 0x00B4 },    //~7719I~
    { 0x00B6, 0x00BA }, { 0x00BC, 0x00BF }, { 0x00C6, 0x00C6 },    //~7719I~
    { 0x00D0, 0x00D0 }, { 0x00D7, 0x00D8 }, { 0x00DE, 0x00E1 },    //~7719I~
    { 0x00E6, 0x00E6 }, { 0x00E8, 0x00EA }, { 0x00EC, 0x00ED },    //~7719I~
    { 0x00F0, 0x00F0 }, { 0x00F2, 0x00F3 }, { 0x00F7, 0x00FA },    //~7719I~
    { 0x00FC, 0x00FC }, { 0x00FE, 0x00FE }, { 0x0101, 0x0101 },    //~7719I~
    { 0x0111, 0x0111 }, { 0x0113, 0x0113 }, { 0x011B, 0x011B },    //~7719I~
    { 0x0126, 0x0127 }, { 0x012B, 0x012B }, { 0x0131, 0x0133 },    //~7719I~
    { 0x0138, 0x0138 }, { 0x013F, 0x0142 }, { 0x0144, 0x0144 },    //~7719I~
    { 0x0148, 0x014B }, { 0x014D, 0x014D }, { 0x0152, 0x0153 },    //~7719I~
    { 0x0166, 0x0167 }, { 0x016B, 0x016B }, { 0x01CE, 0x01CE },    //~7719I~
    { 0x01D0, 0x01D0 }, { 0x01D2, 0x01D2 }, { 0x01D4, 0x01D4 },    //~7719I~
    { 0x01D6, 0x01D6 }, { 0x01D8, 0x01D8 }, { 0x01DA, 0x01DA },    //~7719I~
    { 0x01DC, 0x01DC }, { 0x0251, 0x0251 }, { 0x0261, 0x0261 },    //~7719I~
    { 0x02C4, 0x02C4 }, { 0x02C7, 0x02C7 }, { 0x02C9, 0x02CB },    //~7719I~
    { 0x02CD, 0x02CD }, { 0x02D0, 0x02D0 }, { 0x02D8, 0x02DB },    //~7719I~
    { 0x02DD, 0x02DD }, { 0x02DF, 0x02DF }, { 0x0391, 0x03A1 },    //~7719I~
    { 0x03A3, 0x03A9 }, { 0x03B1, 0x03C1 }, { 0x03C3, 0x03C9 },    //~7719I~
    { 0x0401, 0x0401 }, { 0x0410, 0x044F }, { 0x0451, 0x0451 },    //~7719I~
    { 0x2010, 0x2010 }, { 0x2013, 0x2016 }, { 0x2018, 0x2019 },    //~7719I~
    { 0x201C, 0x201D }, { 0x2020, 0x2022 }, { 0x2024, 0x2027 },    //~7719I~
    { 0x2030, 0x2030 }, { 0x2032, 0x2033 }, { 0x2035, 0x2035 },    //~7719I~
    { 0x203B, 0x203B }, { 0x203E, 0x203E }, { 0x2074, 0x2074 },    //~7719I~
    { 0x207F, 0x207F }, { 0x2081, 0x2084 }, { 0x20AC, 0x20AC },    //~7719I~
    { 0x2103, 0x2103 }, { 0x2105, 0x2105 }, { 0x2109, 0x2109 },    //~7719I~
    { 0x2113, 0x2113 }, { 0x2116, 0x2116 }, { 0x2121, 0x2122 },    //~7719I~
    { 0x2126, 0x2126 }, { 0x212B, 0x212B }, { 0x2153, 0x2154 },    //~7719I~
    { 0x215B, 0x215E }, { 0x2160, 0x216B }, { 0x2170, 0x2179 },    //~7719I~
    { 0x2190, 0x2199 }, { 0x21B8, 0x21B9 }, { 0x21D2, 0x21D2 },    //~7719I~
    { 0x21D4, 0x21D4 }, { 0x21E7, 0x21E7 }, { 0x2200, 0x2200 },    //~7719I~
    { 0x2202, 0x2203 }, { 0x2207, 0x2208 }, { 0x220B, 0x220B },    //~7719I~
    { 0x220F, 0x220F }, { 0x2211, 0x2211 }, { 0x2215, 0x2215 },    //~7719I~
    { 0x221A, 0x221A }, { 0x221D, 0x2220 }, { 0x2223, 0x2223 },    //~7719I~
    { 0x2225, 0x2225 }, { 0x2227, 0x222C }, { 0x222E, 0x222E },    //~7719I~
    { 0x2234, 0x2237 }, { 0x223C, 0x223D }, { 0x2248, 0x2248 },    //~7719I~
    { 0x224C, 0x224C }, { 0x2252, 0x2252 }, { 0x2260, 0x2261 },    //~7719I~
    { 0x2264, 0x2267 }, { 0x226A, 0x226B }, { 0x226E, 0x226F },    //~7719I~
    { 0x2282, 0x2283 }, { 0x2286, 0x2287 }, { 0x2295, 0x2295 },    //~7719I~
    { 0x2299, 0x2299 }, { 0x22A5, 0x22A5 }, { 0x22BF, 0x22BF },    //~7719I~
    { 0x2312, 0x2312 }, { 0x2460, 0x24E9 }, { 0x24EB, 0x254B },    //~7719I~
    { 0x2550, 0x2573 }, { 0x2580, 0x258F }, { 0x2592, 0x2595 },    //~7719I~
    { 0x25A0, 0x25A1 }, { 0x25A3, 0x25A9 }, { 0x25B2, 0x25B3 },    //~7719I~
    { 0x25B6, 0x25B7 }, { 0x25BC, 0x25BD }, { 0x25C0, 0x25C1 },    //~7719I~
    { 0x25C6, 0x25C8 }, { 0x25CB, 0x25CB }, { 0x25CE, 0x25D1 },    //~7719I~
    { 0x25E2, 0x25E5 }, { 0x25EF, 0x25EF }, { 0x2605, 0x2606 },    //~7719I~
    { 0x2609, 0x2609 }, { 0x260E, 0x260F }, { 0x2614, 0x2615 },    //~7719I~
    { 0x261C, 0x261C }, { 0x261E, 0x261E }, { 0x2640, 0x2640 },    //~7719I~
    { 0x2642, 0x2642 }, { 0x2660, 0x2661 }, { 0x2663, 0x2665 },    //~7719I~
    { 0x2667, 0x266A }, { 0x266C, 0x266D }, { 0x266F, 0x266F },    //~7719I~
    { 0x273D, 0x273D }, { 0x2776, 0x277F }, { 0xE000, 0xF8FF },    //~7719I~
    { 0xFFFD, 0xFFFD }, { 0xF0000, 0xFFFFD }, { 0x100000, 0x10FFFD }//~7719I~
#else                                                              //~v62XI~
#ifdef UB1710	//ambiguous; test under ub17.10(kernel4.13.0)      //~v6V1R~
//*ambiguous:drop/skip sbcs                                        //~v6V8R~
//  { 0x00A1, 0x00A1 },  //sbcs                                    //~v6V1I~//~v6V8R~
//  { 0x00A4, 0x00A4 },  //sbcs                                    //~v6V1R~
#ifdef W32                                                         //~v6WpI~
    { 0x00A7, 0x00A8 },  //sbcs                                    //~v6V8R~//~v6WpR~
#endif                                                             //~v6WpI~
//  { 0x00AA, 0x00AA },  //sbcs                                    //~v6V8R~
//  { 0x00AE, 0x00AE },  //sbcs                                    //~v6V8R~
//  { 0x00B0, 0x00B4 },  //sbcs                                      //~v6V1I~//~v6V8R~
//  { 0x00B6, 0x00BA },  //sbcs                                    //~v6V8R~
//  { 0x00BC, 0x00BF },  //sbcs                                    //~v6V8R~
//  { 0x00C6, 0x00C6 },  //sbcs                                    //~v6V8R~
//  { 0x00D0, 0x00D0 },  //sbcs                                    //~v6V8R~
//  { 0x00D7, 0x00D8 },  //sbcs                                    //~v6V8R~
//  { 0x00DE, 0x00E1 },  //sbcs                                    //~v6V8R~
//  { 0x00E6, 0x00E6 },  //sbcs                                    //~v6V8R~
//  { 0x00E8, 0x00EA },  //sbcs                                    //~v6V8R~
//  { 0x00EC, 0x00ED },  //sbcs                                    //~v6V8R~
//  { 0x00F0, 0x00F0 },  //sbcs                                    //~v6V8R~
//  { 0x00F2, 0x00F3 },  //sbcs                                    //~v6V8R~
//  { 0x00F7, 0x00FA },  //sbcs                                    //~v6V8R~
//  { 0x00FC, 0x00FC }, //sbcs                                     //~v6V8R~
//  { 0x00FE, 0x00FE }, //sbcs                                     //~v6V8R~
//  { 0x0101, 0x0101 }, //sbcs                                     //~v6V8R~
//  { 0x0111, 0x0111 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0113, 0x0113 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x011B, 0x011B }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0126, 0x0127 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x012B, 0x012B }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0131, 0x0133 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0138, 0x0138 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x013F, 0x0142 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0144, 0x0144 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0148, 0x014B }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x014D, 0x014D }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0152, 0x0153 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0166, 0x0167 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x016B, 0x016B }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01CE, 0x01CE }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01D0, 0x01D0 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01D2, 0x01D2 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01D4, 0x01D4 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01D6, 0x01D6 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01D8, 0x01D8 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01DA, 0x01DA }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x01DC, 0x01DC }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0251, 0x0251 }, //utft8:{0x0250, 0x02af ,   UCODETB_WIDE  } //IPA extension contains wide sbcs//~v6V8R~
//  { 0x0261, 0x0261 }, //utft8:{0x0250, 0x02af ,   UCODETB_WIDE  } //IPA extension contains wide sbcs//~v6V8R~
//  { 0x02C4, 0x02C4 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02C7, 0x02C7 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02C9, 0x02CB }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02CD, 0x02CD }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02D0, 0x02D0 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02D8, 0x02DB }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02DD, 0x02DD }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x02DF, 0x02DF }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0391, 0x03A1 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x03A3, 0x03A9 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x03B1, 0x03C1 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x03C3, 0x03C9 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x0401, 0x0401 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x0410, 0x044F }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x0451, 0x0451 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x2010, 0x2010 }, //sbcs                                     //~v6V1R~//~v6V8R~
    { 0x2013, 0x2016 }, //7013-2015:sbcs                             //~v6V1R~//~v6V8R~
//  { 0x2018, 0x2019 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x201C, 0x201D }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x2020, 0x2022 }, //sbcs                                     //~v6V1I~//~v6V8R~
    { 0x2024, 0x2027 }, //2024,2026-2027:sbcs                      //~v6V1I~//~v6V8R~
//  { 0x2030, 0x2030 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x2032, 0x2033 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x2035, 0x2035 }, //sbcs                                     //~v6V1R~//~v6V8R~
    { 0x203B, 0x203B },                                            //~v6V1I~
    { 0x203E, 0x203E },                                            //~v6V8R~
//  { 0x2074, 0x2074 }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x207F, 0x207F }, //sbcs                                     //~v6V1I~//~v6V8R~
//  { 0x2081, 0x2084 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x20ac, 0x20ac }, //sbcs                                     //~v6V8I~
//  { 0x2103, 0x2103 },                                            //~v6V1R~//~v6V8R~
//  { 0x2105, 0x2105 },                                            //~v6V1R~//~v6V8R~
//  { 0x2109, 0x2109 },                                            //~v6V1I~//~v6V8R~
//  { 0x2113, 0x2113 }, sbcs                                       //~v6V1R~
//  { 0x2116, 0x2116 }, sbcs                                       //~v6V1R~
//  { 0x2121, 0x2122 },                                            //~v6V1I~
//  { 0x2121, 0x2121 },                                            //~v6V1I~//~v6V8R~
//  { 0x2126, 0x2126 }, sbcs                                       //~v6V1R~
//  { 0x212B, 0x212B },                                            //~v6V1I~//~v6V8R~
//  { 0x2153, 0x2154 }, //sbcs                                     //~v6V1R~//~v6V8R~
//  { 0x215B, 0x215E }, //sbcs                                     //~v6V1R~//~v6V8R~
    { 0x2160, 0x216B },                                            //~v6V1I~
    { 0x2170, 0x2179 },        //add xi,xii                        //~v6V1I~//~v6V8R~
    { 0x2190, 0x2199 },                                            //~v6V1R~//~v6V8R~
    { 0x21B8, 0x21B9 },                                            //~v6V1I~
    { 0x21D2, 0x21D2 },                                            //~v6V1I~
    { 0x21D4, 0x21D4 },                                            //~v6V1I~
//  { 0x21E7, 0x21E7 },   //sbcs                                   //~v6V1I~//~v6V8R~
    { 0x2200, 0x2200 },                                            //~v6V1I~
    { 0x2202, 0x2203 },                                            //~v6V1I~//~v6V8R~
    { 0x2207, 0x2208 },                                            //~v6V1I~
    { 0x220B, 0x220B },                                            //~v6V1I~
//  { 0x220F, 0x220F },   //sbcs                                   //~v6V8R~
//  { 0x2211, 0x2211 },   //sbcs                                   //~v6V1I~//~v6V8R~
//  { 0x2215, 0x2215 },   //sbcs                                   //~v6V1I~//~v6V8R~
//  { 0x221A, 0x221A },   //sbcs                                   //~v6V8R~
    { 0x221D, 0x2220 },                                            //~v6V8R~
//  { 0x2223, 0x2223 },   //sbcs                                   //~v6V8R~
    { 0x2225, 0x2225 },                                            //~v6V1I~
    { 0x2227, 0x222C },                                            //~v6V1R~//~v6V8R~
    { 0x222E, 0x222E },                                            //~v6V1I~
    { 0x2234, 0x2237 },                                            //~v6V8R~
    { 0x223C, 0x223D },                                            //~v6V1I~//~v6V8R~
//  { 0x2248, 0x2248 },   //sbcs                                   //~v6V1R~//~v6V8R~
    { 0x224C, 0x224C },                                            //~v6V1I~
    { 0x2252, 0x2252 },                                            //~v6V1I~
    { 0x2260, 0x2261 },                                            //~v6V8R~
    { 0x2264, 0x2267 },                                            //~v6V8R~
    { 0x226A, 0x226B },                                            //~v6V1I~
    { 0x226E, 0x226F },                                            //~v6V1I~
    { 0x2282, 0x2283 },                                            //~v6V1I~
    { 0x2286, 0x2287 },                                            //~v6V1I~
    { 0x2295, 0x2295 },                                            //~v6V1I~
    { 0x2299, 0x2299 },                                            //~v6V1I~
    { 0x22A5, 0x22A5 },                                            //~v6V1I~
    { 0x22BF, 0x22BF },                                            //~v6V1I~
    { 0x2312, 0x2312 },                                            //~v6V1I~
    { 0x2460, 0x24E9 },                                            //~v6V1I~
    { 0x24EB, 0x254B },                                            //~v6V1I~//~v6V8R~
//  { 0x2550, 0x2573 },  //sbcs                                    //~v6V8R~
//  { 0x2580, 0x258F },  //sbcs                                    //~v6V1I~//~v6V8R~
//  { 0x2592, 0x2595 },  //sbcs                                    //~v6V1R~//~v6V8R~
    { 0x25A0, 0x25A1 },                                            //~v6V1I~
    { 0x25A3, 0x25A9 },                                            //~v6V1I~
    { 0x25B2, 0x25B3 },                                            //~v6V8I~
//  { 0x25B6, 0x25B7 }, //sbcs                                     //~v6V1R~//~v6V8R~
    { 0x25BC, 0x25BD },                                            //~v6V1I~
//  { 0x25C0, 0x25C1 }, //sbcs                                     //~v6V1R~//~v6V8R~
    { 0x25C6, 0x25C8 },                                            //~v6V1I~
    { 0x25CB, 0x25CB },                                            //~v6V1I~//~v6V8R~
    { 0x25CE, 0x25D1 },                                            //~v6V1R~//~v6V8R~
    { 0x25E2, 0x25E5 },                                            //~v6V1I~//~v6V8R~
    { 0x25EF, 0x25EF },                                            //~v6V1I~//~v6V8R~
    { 0x2605, 0x2606 },                                            //~v6V8R~
    { 0x2609, 0x2609 },                                            //~v6V1I~//~v6V8R~
    { 0x260E, 0x260F },                                            //~v6V1I~//~v6V8R~
    { 0x2614, 0x2615 },                                            //~v6V1I~//~v6V8R~
    { 0x261C, 0x261C },                                            //~v6V1I~//~v6V8R~
    { 0x261E, 0x261E },                                            //~v6V1I~//~v6V8R~
    { 0x2640, 0x2640 },                                            //~v6V1I~//~v6V8R~
    { 0x2642, 0x2642 },                                            //~v6V1I~//~v6V8R~
//  { 0x2660, 0x2661 },   //sbcs                                   //~v6V1I~//~v6V8R~
//  { 0x2663, 0x2665 },   //sbcs                                   //~v6V1I~//~v6V8R~
    { 0x2667, 0x266A },                                            //~v6V1I~//~v6V8R~
    { 0x266C, 0x266D },                                            //~v6V1R~//~v6V8R~
    { 0x266F, 0x266F },                                            //~v6V1I~
    { 0x273D, 0x273D },                                            //~v6V1I~//~v6V8R~
    { 0x2776, 0x277F },                                            //~v6V1I~//~v6V8R~
    { 0xd7b0, 0xd7fb }, //moved from mk_wcwidth because wcwidth=1  //~v6WgR~
    { 0xE000, 0xF8FF }, //private use area(gaiji)                  //~v6V1R~
//  { 0xFFFD, 0xFFFD },  //sbcs                                    //~v6V1I~//~v6V8R~
    { 0xF0000, 0xFFFFD }, //Supplementary Private Use Area-A      //~v6V1I~//~v6V8R~
    { 0x100000, 0x10FFFD }//Supplementry Private Use AerA-B        //~v6V1I~//~v6V8R~
#else                                                              //~v6V1I~
//*ncusrse6.0 2018/06/06                                           //~v6V2I~
    { 0x00A1, 0x00A1 },
    { 0x00A4, 0x00A4 },
    { 0x00A7, 0x00A8 },
    { 0x00AA, 0x00AA },
    { 0x00AE, 0x00AE },
    { 0x00B0, 0x00B4 },
    { 0x00B6, 0x00BA },
    { 0x00BC, 0x00BF },
    { 0x00C6, 0x00C6 },
    { 0x00D0, 0x00D0 },
    { 0x00D7, 0x00D8 },
    { 0x00DE, 0x00E1 },
    { 0x00E6, 0x00E6 },
    { 0x00E8, 0x00EA },
    { 0x00EC, 0x00ED },
    { 0x00F0, 0x00F0 },
    { 0x00F2, 0x00F3 },
    { 0x00F7, 0x00FA },
    { 0x00FC, 0x00FC },
    { 0x00FE, 0x00FE },
    { 0x0101, 0x0101 },
    { 0x0111, 0x0111 },
    { 0x0113, 0x0113 },
    { 0x011B, 0x011B },
    { 0x0126, 0x0127 },
    { 0x012B, 0x012B },
    { 0x0131, 0x0133 },
    { 0x0138, 0x0138 },
    { 0x013F, 0x0142 },
    { 0x0144, 0x0144 },
    { 0x0148, 0x014B },
    { 0x014D, 0x014D },
    { 0x0152, 0x0153 },
    { 0x0166, 0x0167 },
    { 0x016B, 0x016B },
    { 0x01CE, 0x01CE },
    { 0x01D0, 0x01D0 },
    { 0x01D2, 0x01D2 },
    { 0x01D4, 0x01D4 },
    { 0x01D6, 0x01D6 },
    { 0x01D8, 0x01D8 },
    { 0x01DA, 0x01DA },
    { 0x01DC, 0x01DC },
    { 0x0251, 0x0251 },
    { 0x0261, 0x0261 },
    { 0x02C4, 0x02C4 },
    { 0x02C7, 0x02C7 },
    { 0x02C9, 0x02CB },
    { 0x02CD, 0x02CD },
    { 0x02D0, 0x02D0 },
    { 0x02D8, 0x02DB },
    { 0x02DD, 0x02DD },
    { 0x02DF, 0x02DF },
    { 0x0391, 0x03A1 },
    { 0x03A3, 0x03A9 },
    { 0x03B1, 0x03C1 },
    { 0x03C3, 0x03C9 },
    { 0x0401, 0x0401 },
    { 0x0410, 0x044F },
    { 0x0451, 0x0451 },
    { 0x2010, 0x2010 },
    { 0x2013, 0x2016 },
    { 0x2018, 0x2019 },
    { 0x201C, 0x201D },
    { 0x2020, 0x2022 },
    { 0x2024, 0x2027 },
    { 0x2030, 0x2030 },
    { 0x2032, 0x2033 },
    { 0x2035, 0x2035 },
    { 0x203B, 0x203B },
    { 0x203E, 0x203E },
    { 0x2074, 0x2074 },
    { 0x207F, 0x207F },
    { 0x2081, 0x2084 },
//  { 0x20AC, 0x20AC },	//currency:euro                            //~v6buR~
    { 0x2103, 0x2103 },
    { 0x2105, 0x2105 },
    { 0x2109, 0x2109 },
    { 0x2113, 0x2113 },
    { 0x2116, 0x2116 },
    { 0x2121, 0x2122 },
    { 0x2126, 0x2126 },
    { 0x212B, 0x212B },
    { 0x2153, 0x2154 },
    { 0x215B, 0x215E },
    { 0x2160, 0x216B },
//  { 0x2170, 0x2179 },                                            //~v62XR~
    { 0x2170, 0x217b },        //add xi,xii                        //~v62XI~
    { 0x2190, 0x2199 },
    { 0x21B8, 0x21B9 },
    { 0x21D0, 0x21D0 },        //add <==                           //~v62XI~
    { 0x21D2, 0x21D2 },
    { 0x21D4, 0x21D4 },
    { 0x21E7, 0x21E7 },
    { 0x2200, 0x2200 },
    { 0x2202, 0x2203 },
    { 0x2207, 0x2208 },
    { 0x220B, 0x220B },
    { 0x220F, 0x220F },
    { 0x2211, 0x2211 },
    { 0x2215, 0x2215 },
    { 0x221A, 0x221A },
    { 0x221D, 0x2220 },
    { 0x2223, 0x2223 },
    { 0x2225, 0x2225 },
    { 0x2227, 0x222C },
    { 0x222E, 0x222E },
    { 0x2234, 0x2237 },
    { 0x223C, 0x223D },
    { 0x2248, 0x2248 },
    { 0x224C, 0x224C },
    { 0x2252, 0x2252 },
    { 0x2260, 0x2261 },
    { 0x2264, 0x2267 },
    { 0x226A, 0x226B },
    { 0x226E, 0x226F },
    { 0x2282, 0x2283 },
    { 0x2286, 0x2287 },
    { 0x2295, 0x2295 },
    { 0x2299, 0x2299 },
    { 0x22A5, 0x22A5 },
    { 0x22BF, 0x22BF },
    { 0x2312, 0x2312 },
    { 0x2460, 0x24E9 },
    { 0x24EB, 0x254B },
    { 0x2550, 0x2573 },
    { 0x2580, 0x258F },
    { 0x2592, 0x2595 },
    { 0x25A0, 0x25A1 },
    { 0x25A3, 0x25A9 },
    { 0x25B2, 0x25B3 },
    { 0x25B6, 0x25B7 },
    { 0x25BC, 0x25BD },
    { 0x25C0, 0x25C1 },
    { 0x25C6, 0x25C8 },
    { 0x25CB, 0x25CB },
    { 0x25CE, 0x25D1 },
    { 0x25E2, 0x25E5 },
    { 0x25EF, 0x25EF },
    { 0x2605, 0x2606 },
    { 0x2609, 0x2609 },
    { 0x260E, 0x260F },
    { 0x2614, 0x2615 },
    { 0x261C, 0x261C },
    { 0x261E, 0x261E },
    { 0x2640, 0x2640 },
    { 0x2642, 0x2642 },
    { 0x2660, 0x2661 },
    { 0x2663, 0x2665 },
    { 0x2667, 0x266A },
    { 0x266C, 0x266D },
    { 0x266F, 0x266F },
    { 0x273D, 0x273D },
    { 0x2776, 0x277F },
    { 0xE000, 0xF8FF },
    { 0xFFFD, 0xFFFD },
    { 0xF0000, 0xFFFFD },
    { 0x100000, 0x10FFFD }
#endif //UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1I~
#endif                                                             //~v62XI~
  };                                                               //~7719I~
#ifdef UB1710	                                                   //~v6V2I~
//*specify all char in the specific non language block             //~v6V8I~
  static const struct interval Sambiguous_non_langs[] = {          //~v6V8I~
    { 0x20a0, 0x20cf }  //Currency Symbols;sbcs(20ac=euro etc) is denied on _utf8//~v6V8I~//~v6VbR~
   ,{ 0x2100, 0x214f }  //LetterLike Symbols                       //~v6V8I~
   ,{ 0x2300, 0x23ff }  //Miscellaneous Technical//~v6V2I~         //~v6V8I~
   ,{ 0x2400, 0x243f }  //Control Picures        //~v6V2I~         //~v6V8I~
   ,{ 0x2440, 0x245f }  //Optical Character Recognition//~v6V2I~   //~v6V8I~
   ,{ 0x2460, 0x24ff }  //Enclosed Alphanumeric,dup with ambiguous 2460-24e9,24eb-254b//~v6V9I~//~v6V8I~
   ,{ 0x27f0, 0x27ff }  //Supplemental Arrows-A                    //~v6V8I~
   ,{ 0x2800, 0x28ff }  //Braille Patterns                         //~v6V8I~
   ,{ 0x2900, 0x297f }  //Supplemental Arrows-B                    //~v6V8I~
   ,{ 0x2980, 0x29ff }  //Miscellaneous Mathematical Symbol-B      //~v6V8I~
   ,{ 0x2a00, 0x2aff }  //Supplemental Mathematical Operators      //~v6V8I~
   ,{ 0x2b00, 0x2bff }  //Miscellaneous Symbols and Arrows         //~v6V8I~
  };                                                               //~v6V8I~
#ifdef W32                                                         //~v6WpR~
  static const struct interval Sambiguous_non_langs_WXE[] = {      //~v6WpI~
    { 0x20a0, 0x20cf }  //Currency Symbols;sbcs(20ac=euro etc) is denied on _utf8//~v6WpI~
   ,{ 0x2100, 0x214f }  //LetterLike Symbols                       //~v6WpI~
   ,{ 0x2300, 0x23ff }  //Miscellaneous Technical                  //~v6WpI~
// ,{ 0x2400, 0x243f }  //Control Picures del WXE                  //~v6WpI~
// ,{ 0x2440, 0x245f }  //Optical Character Recognition del WXE    //~v6WpR~
   ,{ 0x2460, 0x24ff }  //Enclosed Alphanumeric,dup with ambiguous 2460-24e9,24eb-254b//~v6WpI~
   ,{ 0x27f0, 0x27ff }  //Supplemental Arrows-A                    //~v6WpI~
   ,{ 0x2800, 0x28ff }  //Braille Patterns                         //~v6WpI~
   ,{ 0x2900, 0x297f }  //Supplemental Arrows-B                    //~v6WpI~
   ,{ 0x2980, 0x29ff }  //Miscellaneous Mathematical Symbol-B      //~v6WpI~
   ,{ 0x2a00, 0x2aff }  //Supplemental Mathematical Operators      //~v6WpI~
   ,{ 0x2b00, 0x2bff }  //Miscellaneous Symbols and Arrows         //~v6WpI~
  };                                                               //~v6WpI~
#endif                                                             //~v6WpI~
//*specify all char in the specific language block**                        //~v6V2I~//~v6V8R~
  static const struct interval Sambiguous_langs[] = {              //~v6V2I~
     { 0x0500, 0x052f } //  cyrilic Supplement                     //~v6V2I~//~v6VbR~
    ,{ 0x0530, 0x058f } //  Armenian                               //~v6V2I~
    ,{ 0x0590, 0x05ff } //  Hebrew                                 //~v6V2I~
    ,{ 0x0600, 0x06ff } //  Arabic                                 //~v6V2I~
    ,{ 0x0700, 0x074f } //  Syliac                                 //~v6V2I~
    ,{ 0x0750, 0x077f } //  Arabic Supplement                      //~v6V2I~
    ,{ 0x0780, 0x07bf } //  Thaana                                 //~v6V2I~
    ,{ 0x07c0, 0x07ff } //  Nko                                    //~v6V2I~
    ,{ 0x0800, 0x083f } //  Samaritan 816-819,81b-823,825-827,829-82d is wcwidth0//~v6V2R~//~v6V8R~
//  ,{ 0x0800, 0x0815 } //  Samaritan                              //~v6V2I~//~v6V8R~
//  ,{ 0x081a, 0x081a } //  Samaritan                              //~v6V2I~//~v6V8R~
//  ,{ 0x0824, 0x0824 } //  Samaritan                              //~v6V2I~//~v6V8R~
//  ,{ 0x0828, 0x0828 } //  Samaritan                              //~v6V2I~//~v6V8R~
    ,{ 0x0840, 0x085f } //  Samaritan                              //~v6V2I~
    ,{ 0x0860, 0x086f } //  Syriac Supplement                      //~v6V2I~
                                                                   //~v6V2I~
    ,{ 0x08a0, 0x08ff } //  Arabic Extended-A                      //~v6V2I~
    ,{ 0x0900, 0x097f } //  Devanagari                             //~v6V2I~
    ,{ 0x0980, 0x09ff } //  Bengali                                //~v6V2I~
    ,{ 0x0a00, 0x0a7f } //  Gurmukih                               //~v6V2I~
    ,{ 0x0a80, 0x0aff } //  Gujarati                               //~v6V2I~
    ,{ 0x0b00, 0x0b7f } //  Orya                                   //~v6V2I~
    ,{ 0x0b80, 0x0bff } //  Tamil                                  //~v6V2I~
    ,{ 0x0c00, 0x0c7f } //  Telugu                                 //~v6V2I~
    ,{ 0x0c80, 0x0cff } //  Kannada                                //~v6V2I~
    ,{ 0x0d00, 0x0d7f } //  Malayalam                              //~v6V2I~
    ,{ 0x0d80, 0x0dff } //  Sinhala                                //~v6V2I~
    ,{ 0x0e00, 0x0e7f } //  Thai                                   //~v6V2I~
    ,{ 0x0e80, 0x0eff } //  Lao                                    //~v6V2I~
    ,{ 0x0f00, 0x0fff } //  Tibetan                                //~v6V2I~
    ,{ 0x1000, 0x109f } //  Myanmar                                //~v6V2I~
    ,{ 0x10a0, 0x10ff } //  Myanmar                                //~v6V2I~
//  ,{ 0x1100, 0x11ff } //  Hangul Jumbo (1100-115f:dbcs,1160-11ff:combining)//~v6V2I~
    ,{ 0x1200, 0x137f } //  Ethiopic                               //~v6V2I~
    ,{ 0x1380, 0x139f } //  Ethiopic Supplement                    //~v6V2I~
    ,{ 0x13a0, 0x13ff } //  Cherokee                               //~v6V2I~
    ,{ 0x1400, 0x167f } //  Unified Canadian Aboriginal Syllabics  //~v6V2I~
    ,{ 0x1680, 0x169f } //  Ogham                                  //~v6V2I~
//  ,{ 0x16a0, 0x16ff } //  Runic ,looks like sbcs                 //~v6V2I~
    ,{ 0x1700, 0x171f } //  Tagalog                                //~v6V2I~
//  ,{ 0x1720, 0x173f } //  Hanunoo,looks like sbcs                //~v6V2I~
    ,{ 0x1740, 0x175f } //  Buhid (unprintable)                    //~v6V2I~
    ,{ 0x1760, 0x177f } //  Tagbanwa(unprintable)                  //~v6V2I~
    ,{ 0x1780, 0x17ff } //  Khmer                                  //~v6V2I~
    ,{ 0x1800, 0x18af } //  Mongolian(unprintable)                 //~v6V2I~
    ,{ 0x18b0, 0x18ff } //  Unified Canadian Aboriginal Syllabics extended//~v6V2I~
    ,{ 0x1900, 0x194f } //  Limbu(Unprintable)                     //~v6V2I~
    ,{ 0x1950, 0x197f } //  Tai Le                                 //~v6V2I~
    ,{ 0x1980, 0x19df } //  New Tai Lue(Unprintable)               //~v6V2I~
    ,{ 0x19e0, 0x19ff } //  khmer symbols                          //~v6V2I~
    ,{ 0x1a00, 0x1a1f } //  Buginese                               //~v6V2I~
    ,{ 0x1a20, 0x1aaf } //  Tai Tham(Unprintable)                  //~v6V2I~
//  ,{ 0x1ab0, 0x1aff } //  Combining Diacritical Marks Extended (1ab0-1abe:wcwidth=0, 1abf-1aff:wcwidth=-1)//~v6V2I~
    ,{ 0x1b00, 0x1b7f } //  Balinese(Unprintable)                  //~v6V2I~
    ,{ 0x1b80, 0x1bbf } //  Sundanes(Unprintable)                  //~v6V2I~
    ,{ 0x1bc0, 0x1bff } //  Batak(Unprintable)                     //~v6V2I~
    ,{ 0x1c00, 0x1c4f } //  Lepcha(Unprintable)                    //~v6V2I~
    ,{ 0x1c50, 0x1c7f } //  Ol Chiki(Unprintable)                  //~v6V2I~
    ,{ 0x1c80, 0x1c8f } //  Cyrillic Extended-C                    //~v6V2I~
                                                                   //~v6V2I~
    ,{ 0x1cc0, 0x1ccf } //  Sundanes Supplements(Unprintable)      //~v6V2I~
    ,{ 0x1cd0, 0x1cff } //  Vedic Extensions                       //~v6V2I~
    ,{ 0x1d00, 0x1d7f } //  Phonetic Extensions                    //~v6V2I~
    ,{ 0x1d80, 0x1dbf } //  Phonetic Extensions Supplement         //~v6V2I~
//  ,{ 0x1dc0, 0x1dff } //  Combining Diacritical Marks Supplement , wcwidth=1//~v6V2I~
    ,{ 0x1e00, 0x1eff } //  Latic extended additional              //~v6V2I~
//  ,{ 0x1f00, 0x1fff } //  Greek Extended (sbcs)                  //~v6V2I~
//  ,{ 0x2000, 0x2bff } //  By Suctb_utf8 @@@@test                 //~v6V2I~
    ,{ 0x2c00, 0x2c5f } //  Glagolitic                             //~v6V2I~
    ,{ 0x2c60, 0x2c7f } //  Latic Extended-C                       //~v6V2I~
    ,{ 0x2c80, 0x2cff } //  Coptic                                 //~v6V2I~
    ,{ 0x2d00, 0x2d2f } //  Georgian Supplement                    //~v6V2I~
    ,{ 0x2d30, 0x2d7f } //  Tifinagh                               //~v6V2I~
    ,{ 0x2d80, 0x2ddf } //  Ethiopic Extended                      //~v6V2I~
    ,{ 0x2de0, 0x2dff } //  Cyrillic Extended-A                    //~v6V2I~
//  ,{ 0x2e00, 0x2e7f } //  By Suctb_utf8  @@@@test                //~v6V2I~
    ,{ 0x2e80, 0xa4cf } //  mk_wcwidth dbcs                        //~v6V2I~
    ,{ 0xa4d0, 0xa4ff } //  Lisu                                   //~v6V2I~
    ,{ 0xa500, 0xa63f } //  Vai                                    //~v6V2I~
    ,{ 0xa640, 0xa69f } //  Cyrillic Extended-B                    //~v6V2I~
    ,{ 0xa6a0, 0xa6ff } //  Bamum(Unprintable)                     //~v6V2I~
//  ,{ 0xa700, 0xa71f } //  Modifier Tone Letters, looks like sbcs //~v6V2I~
    ,{ 0xa720, 0xa7ff } //  Latin Extended-D                       //~v6V2I~
    ,{ 0xa800, 0xa82f } //  Syloti Nagri(Unprintable)              //~v6V2I~
    ,{ 0xa830, 0xa83f } //  Common Indic Number Forms              //~v6V2I~
    ,{ 0xa840, 0xa87f } //  Phags-pa                               //~v6V2I~
    ,{ 0xa880, 0xa8df } //  Saurashtra                             //~v6V2I~
    ,{ 0xa8e0, 0xa8ff } //  Devanagari Extended                    //~v6V2I~
//  ,{ 0xa900, 0xa92f } //  Kayah Li , looks like sbcs             //~v6V2R~
    ,{ 0xa930, 0xa95f } //  Rejang                                 //~v6V2I~
//  ,{ 0xa960, 0xa97f } //  Hangul Jambo Extended-A (wcwidth=dbcs) //~v6V2R~
    ,{ 0xa980, 0xa9df } //  Javanese                               //~v6V2I~
    ,{ 0xa9e0, 0xa9ff } //  Myanmar Extended-B                     //~v6V2I~
    ,{ 0xaa00, 0xaa5f } //  Cham                                   //~v6V2I~
    ,{ 0xaa60, 0xaa7f } //  Myanmar Extended-A                     //~v6V2I~
    ,{ 0xaa80, 0xaadf } //  Tai Viet                               //~v6V2I~
    ,{ 0xaae0, 0xaaff } //  Meetei Mayek Extensions                //~v6V2I~
    ,{ 0xab00, 0xab2f } //  Ethiopic Extended-A                    //~v6V2I~
    ,{ 0xab30, 0xab6f } //  Latin Extended-E                       //~v6V2I~
    ,{ 0xab70, 0xabbf } //  Cherokee Supplement                    //~v6V2I~
    ,{ 0xabc0, 0xabff } //  Meetei Mayek                           //~v6V2I~
//  ,{ 0xac00, 0xd7af } //  Hangul Syllables(mk_wcwidth:dbcs)      //~v6V2R~
//  ,{ 0xd7bf, 0xd7ff } //  Hangul Jambo Exteded-B(dbcs)           //~v6V2I~
//  ,{ 0xd800, 0xdfff } //  Surrogate                              //~v6V2I~
//  ,{ 0xe000, 0xf8ff } //  private use area                       //~v6V2R~
//  ,{ 0xf900, 0xfaff } //  CJK Compatibility Ideographs(mk_wcwidth=dbcs)//~v6V2R~
    ,{ 0xfb00, 0xfb4f } //  Alphabetic Presentation Forms          //~v6V2I~
    ,{ 0xfb50, 0xfdff } //  Alphabetic Presentation Forms-A        //~v6V2I~
//  ,{ 0xfe00, 0xfe0f } //  Variation Selectors(wcwidth=0)         //~v6V2I~
//  ,{ 0xfe10, 0xfe1f } //  Vertical Forms (mk_wcwidth=dbcs)       //~v6V2R~
//  ,{ 0xfe20, 0xfe2f } //  Combining Half Marks(wcwidth=0)        //~v6V2I~
//  ,{ 0xfe30, 0xfe4f } //  CJK Compatibility Forms(mk_wcwidth=dbcs)//~v6V2R~
//  ,{ 0xfe50, 0xfe6f } //  Small Form variants(mk_wcwidth=dbcs)   //~v6V2R~
    ,{ 0xfe70, 0xfeff } //  Arabic Presentation Forms-B            //~v6V2I~
//  ,{ 0xff00, 0xffef } //  HalfWidth and Fullwidth Formas         //~v6V2I~
//      { 0xff00, 0xff60 } //  dbcs by mk_wcwidth                  //~v6V2I~
//      { 0xff61, 0xffef } //  sbcs/dbcs by wcwidth                //~v6V2I~
//  ,{ 0xfff0, 0xffff } //  Specials                               //~v6V2I~//~v6V8R~
  };                                                               //~v6V2R~
#ifdef LNX                                                         //~v6WpI~
  static const struct interval Sambiguous_langs_XXE[] = {          //~v6WkI~
     { 0x0500, 0x052f } //  cyrilic Supplement                     //~v6WkI~
    ,{ 0x0530, 0x058f } //  Armenian                               //~v6WkR~
    ,{ 0x0590, 0x05ff } //  Hebrew                                 //~v6WkR~
    ,{ 0x0600, 0x06ff } //  Arabic                                 //~v6WkI~
    ,{ 0x0700, 0x074f } //  Syliac                                 //~v6WkI~
    ,{ 0x0750, 0x077f } //  Arabic Supplement                      //~v6WkI~
    ,{ 0x0780, 0x07bf } //  Thaana                                 //~v6WkI~
    ,{ 0x07c0, 0x07ff } //  Nko                                    //~v6WkI~
    ,{ 0x0800, 0x083f } //  Samaritan 816-819,81b-823,825-827,829-82d is wcwidth0//~v6WkI~
//  ,{ 0x0800, 0x0815 } //  Samaritan                              //~v6WkI~
//  ,{ 0x081a, 0x081a } //  Samaritan                              //~v6WkI~
//  ,{ 0x0824, 0x0824 } //  Samaritan                              //~v6WkI~
//  ,{ 0x0828, 0x0828 } //  Samaritan                              //~v6WkI~
    ,{ 0x0840, 0x085f } //  Samaritan                              //~v6WkI~
    ,{ 0x0860, 0x086f } //  Syriac Supplement                      //~v6WkI~
                                                                   //~v6WkI~
    ,{ 0x08a0, 0x08ff } //  Arabic Extended-A                      //~v6WkI~
    ,{ 0x0900, 0x097f } //  Devanagari                             //~v6WkI~
    ,{ 0x0980, 0x09ff } //  Bengali                                //~v6WkI~
    ,{ 0x0a00, 0x0a7f } //  Gurmukih                               //~v6WkI~
    ,{ 0x0a80, 0x0aff } //  Gujarati                               //~v6WkI~
    ,{ 0x0b00, 0x0b7f } //  Orya                                   //~v6WkI~
    ,{ 0x0b80, 0x0bff } //  Tamil                                  //~v6WkI~
    ,{ 0x0c00, 0x0c7f } //  Telugu                                 //~v6WkI~
    ,{ 0x0c80, 0x0cff } //  Kannada                                //~v6WkI~
    ,{ 0x0d00, 0x0d7f } //  Malayalam                              //~v6WkI~
    ,{ 0x0d80, 0x0dff } //  Sinhala                                //~v6WkI~
    ,{ 0x0e00, 0x0e7f } //  Thai                                   //~v6WkI~
    ,{ 0x0e80, 0x0eff } //  Lao                                    //~v6WkI~
    ,{ 0x0f00, 0x0fff } //  Tibetan                                //~v6WkI~
    ,{ 0x1000, 0x109f } //  Myanmar                                //~v6WkI~
    ,{ 0x10a0, 0x10ff } //  Myanmar                                //~v6WkI~
//  ,{ 0x1100, 0x11ff } //  Hangul Jumbo (1100-115f:dbcs,1160-11ff:combining)//~v6WkI~
    ,{ 0x1200, 0x137f } //  Ethiopic                               //~v6WkI~
    ,{ 0x1380, 0x139f } //  Ethiopic Supplement                    //~v6WkI~
    ,{ 0x13a0, 0x13ff } //  Cherokee                               //~v6WkI~
    ,{ 0x1400, 0x167f } //  Unified Canadian Aboriginal Syllabics  //~v6WkI~
    ,{ 0x1680, 0x169f } //  Ogham                                  //~v6WkI~
//  ,{ 0x16a0, 0x16ff } //  Runic ,looks like sbcs                 //~v6WkI~
    ,{ 0x1700, 0x171f } //  Tagalog                                //~v6WkI~
//  ,{ 0x1720, 0x173f } //  Hanunoo,looks like sbcs                //~v6WkI~
    ,{ 0x1740, 0x175f } //  Buhid (unprintable)                    //~v6WkI~
    ,{ 0x1760, 0x177f } //  Tagbanwa(unprintable)                  //~v6WkI~
    ,{ 0x1780, 0x17ff } //  Khmer                                  //~v6WkI~
    ,{ 0x1800, 0x18af } //  Mongolian(unprintable)                 //~v6WkI~
    ,{ 0x18b0, 0x18ff } //  Unified Canadian Aboriginal Syllabics extended//~v6WkI~
    ,{ 0x1900, 0x194f } //  Limbu(Unprintable)                     //~v6WkI~
    ,{ 0x1950, 0x197f } //  Tai Le                                 //~v6WkI~
    ,{ 0x1980, 0x19df } //  New Tai Lue(Unprintable)               //~v6WkI~
    ,{ 0x19e0, 0x19ff } //  khmer symbols                          //~v6WkI~
    ,{ 0x1a00, 0x1a1f } //  Buginese                               //~v6WkI~
    ,{ 0x1a20, 0x1aaf } //  Tai Tham(Unprintable)                  //~v6WkI~
//  ,{ 0x1ab0, 0x1aff } //  Combining Diacritical Marks Extended (1ab0-1abe:wcwidth=0, 1abf-1aff:wcwidth=-1)//~v6WkI~
    ,{ 0x1b00, 0x1b7f } //  Balinese(Unprintable)                  //~v6WkI~
    ,{ 0x1b80, 0x1bbf } //  Sundanes(Unprintable)                  //~v6WkI~
    ,{ 0x1bc0, 0x1bff } //  Batak(Unprintable)                     //~v6WkI~
    ,{ 0x1c00, 0x1c4f } //  Lepcha(Unprintable)                    //~v6WkI~
    ,{ 0x1c50, 0x1c7f } //  Ol Chiki(Unprintable)                  //~v6WkI~
    ,{ 0x1c80, 0x1c8f } //  Cyrillic Extended-C                    //~v6WkI~
                                                                   //~v6WkI~
    ,{ 0x1cc0, 0x1ccf } //  Sundanes Supplements(Unprintable)      //~v6WkI~
    ,{ 0x1cd0, 0x1cff } //  Vedic Extensions                       //~v6WkI~
    ,{ 0x1d00, 0x1d7f } //  Phonetic Extensions                    //~v6WkI~
    ,{ 0x1d80, 0x1dbf } //  Phonetic Extensions Supplement         //~v6WkI~
//  ,{ 0x1dc0, 0x1dff } //  Combining Diacritical Marks Supplement , wcwidth=1//~v6WkI~
    ,{ 0x1e00, 0x1eff } //  Latic extended additional              //~v6WkI~
//  ,{ 0x1f00, 0x1fff } //  Greek Extended (sbcs)                  //~v6WkI~
//  ,{ 0x2000, 0x2bff } //  By Suctb_utf8 @@@@test                 //~v6WkI~
    ,{ 0x2c00, 0x2c5f } //  Glagolitic                             //~v6WkI~
    ,{ 0x2c60, 0x2c7f } //  Latic Extended-C                       //~v6WkI~
    ,{ 0x2c80, 0x2cff } //  Coptic                                 //~v6WkI~
    ,{ 0x2d00, 0x2d2f } //  Georgian Supplement                    //~v6WkI~
    ,{ 0x2d30, 0x2d7f } //  Tifinagh                               //~v6WkI~
    ,{ 0x2d80, 0x2ddf } //  Ethiopic Extended                      //~v6WkI~
    ,{ 0x2de0, 0x2dff } //  Cyrillic Extended-A                    //~v6WkI~
//  ,{ 0x2e00, 0x2e7f } //  By Suctb_utf8  @@@@test                //~v6WkI~
    ,{ 0x2e80, 0xa4cf } //  mk_wcwidth dbcs                        //~v6WkI~
    ,{ 0xa4d0, 0xa4ff } //  Lisu                                   //~v6WkI~
    ,{ 0xa500, 0xa63f } //  Vai                                    //~v6WkI~
    ,{ 0xa640, 0xa69f } //  Cyrillic Extended-B                    //~v6WkI~
    ,{ 0xa6a0, 0xa6ff } //  Bamum(Unprintable)                     //~v6WkI~
//  ,{ 0xa700, 0xa71f } //  Modifier Tone Letters, looks like sbcs //~v6WkI~
    ,{ 0xa720, 0xa7ff } //  Latin Extended-D                       //~v6WkI~
    ,{ 0xa800, 0xa82f } //  Syloti Nagri(Unprintable)              //~v6WkI~
    ,{ 0xa830, 0xa83f } //  Common Indic Number Forms              //~v6WkI~
    ,{ 0xa840, 0xa87f } //  Phags-pa                               //~v6WkI~
    ,{ 0xa880, 0xa8df } //  Saurashtra                             //~v6WkI~
    ,{ 0xa8e0, 0xa8ff } //  Devanagari Extended                    //~v6WkI~
//  ,{ 0xa900, 0xa92f } //  Kayah Li , looks like sbcs             //~v6WkI~
    ,{ 0xa930, 0xa95f } //  Rejang                                 //~v6WkI~
//  ,{ 0xa960, 0xa97f } //  Hangul Jambo Extended-A (wcwidth=dbcs) //~v6WkI~
    ,{ 0xa980, 0xa9df } //  Javanese                               //~v6WkI~
    ,{ 0xa9e0, 0xa9ff } //  Myanmar Extended-B                     //~v6WkI~
    ,{ 0xaa00, 0xaa5f } //  Cham                                   //~v6WkI~
    ,{ 0xaa60, 0xaa7f } //  Myanmar Extended-A                     //~v6WkI~
    ,{ 0xaa80, 0xaadf } //  Tai Viet                               //~v6WkI~
    ,{ 0xaae0, 0xaaff } //  Meetei Mayek Extensions                //~v6WkI~
    ,{ 0xab00, 0xab2f } //  Ethiopic Extended-A                    //~v6WkI~
    ,{ 0xab30, 0xab6f } //  Latin Extended-E                       //~v6WkI~
    ,{ 0xab70, 0xabbf } //  Cherokee Supplement                    //~v6WkI~
    ,{ 0xabc0, 0xabff } //  Meetei Mayek                           //~v6WkI~
//  ,{ 0xac00, 0xd7af } //  Hangul Syllables(mk_wcwidth:dbcs)      //~v6WkI~
//  ,{ 0xd7bf, 0xd7ff } //  Hangul Jambo Exteded-B(dbcs)           //~v6WkI~
//  ,{ 0xd800, 0xdfff } //  Surrogate                              //~v6WkI~
//  ,{ 0xe000, 0xf8ff } //  private use area                       //~v6WkI~
//  ,{ 0xf900, 0xfaff } //  CJK Compatibility Ideographs(mk_wcwidth=dbcs)//~v6WkI~
    ,{ 0xfb00, 0xfb4f } //  Alphabetic Presentation Forms          //~v6WkI~
    ,{ 0xfb50, 0xfdff } //  Alphabetic Presentation Forms-A        //~v6WkI~
//  ,{ 0xfe00, 0xfe0f } //  Variation Selectors(wcwidth=0)         //~v6WkI~
//  ,{ 0xfe10, 0xfe1f } //  Vertical Forms (mk_wcwidth=dbcs)       //~v6WkI~
//  ,{ 0xfe20, 0xfe2f } //  Combining Half Marks(wcwidth=0)        //~v6WkI~
//  ,{ 0xfe30, 0xfe4f } //  CJK Compatibility Forms(mk_wcwidth=dbcs)//~v6WkI~
//  ,{ 0xfe50, 0xfe6f } //  Small Form variants(mk_wcwidth=dbcs)   //~v6WkI~
    ,{ 0xfe70, 0xfeff } //  Arabic Presentation Forms-B            //~v6WkI~
//  ,{ 0xff00, 0xffef } //  HalfWidth and Fullwidth Formas         //~v6WkI~
//      { 0xff00, 0xff60 } //  dbcs by mk_wcwidth                  //~v6WkI~
//      { 0xff61, 0xffef } //  sbcs/dbcs by wcwidth                //~v6WkI~
//  ,{ 0xfff0, 0xffff } //  Specials                               //~v6WkI~
  };                                                               //~v6WkI~
#endif                                                             //~v6WpI~
#ifdef W32                                                         //~v6WpI~
  static const struct interval Sambiguous_langs_WXE[] = {          //~v6WpI~
     { 0x0500, 0x052f } //  cyrilic Supplement                     //~v6WpI~
    ,{ 0x0530, 0x058f } //  Armenian                               //~v6WpI~
    ,{ 0x0590, 0x05ff } //  Hebrew                                 //~v6WpI~
    ,{ 0x0600, 0x06ff } //  Arabic                                 //~v6WpI~
    ,{ 0x0700, 0x074f } //  Syliac                                 //~v6WpI~
    ,{ 0x0750, 0x077f } //  Arabic Supplement                      //~v6WpI~
    ,{ 0x0780, 0x07bf } //  Thaana                                 //~v6WpI~
    ,{ 0x07c0, 0x07ff } //  Nko                                    //~v6WpI~
    ,{ 0x0800, 0x083f } //  Samaritan 816-819,81b-823,825-827,829-82d is wcwidth0//~v6WpI~
//  ,{ 0x0800, 0x0815 } //  Samaritan                              //~v6WpI~
//  ,{ 0x081a, 0x081a } //  Samaritan                              //~v6WpI~
//  ,{ 0x0824, 0x0824 } //  Samaritan                              //~v6WpI~
//  ,{ 0x0828, 0x0828 } //  Samaritan                              //~v6WpI~
    ,{ 0x0840, 0x085f } //  Samaritan                              //~v6WpI~
    ,{ 0x0860, 0x086f } //  Syriac Supplement                      //~v6WpI~
                                                                   //~v6WpI~
    ,{ 0x08a0, 0x08ff } //  Arabic Extended-A                      //~v6WpI~
    ,{ 0x0900, 0x097f } //  Devanagari                             //~v6WpI~
    ,{ 0x0980, 0x09ff } //  Bengali                                //~v6WpI~
    ,{ 0x0a00, 0x0a7f } //  Gurmukih                               //~v6WpI~
    ,{ 0x0a80, 0x0aff } //  Gujarati                               //~v6WpI~
//  ,{ 0x0b00, 0x0b7f } //  Orya        del WXE                    //~v6WpI~
    ,{ 0x0b80, 0x0bff } //  Tamil                                  //~v6WpI~
    ,{ 0x0c00, 0x0c7f } //  Telugu                                 //~v6WpI~
    ,{ 0x0c80, 0x0cff } //  Kannada                                //~v6WpI~
    ,{ 0x0d00, 0x0d7f } //  Malayalam                              //~v6WpI~
    ,{ 0x0d80, 0x0dff } //  Sinhala                                //~v6WpI~
    ,{ 0x0e00, 0x0e7f } //  Thai                                   //~v6WpI~
    ,{ 0x0e80, 0x0eff } //  Lao                                    //~v6WpI~
    ,{ 0x0f00, 0x0fff } //  Tibetan                                //~v6WpI~
    ,{ 0x1000, 0x109f } //  Myanmar                                //~v6WpI~
    ,{ 0x10a0, 0x10ff } //  Myanmar                                //~v6WpI~
//  ,{ 0x1100, 0x11ff } //  Hangul Jumbo (1100-115f:dbcs,1160-11ff:combining)//~v6WpI~
    ,{ 0x1200, 0x137f } //  Ethiopic                               //~v6WpI~
    ,{ 0x1380, 0x139f } //  Ethiopic Supplement                    //~v6WpI~
    ,{ 0x13a0, 0x13ff } //  Cherokee                               //~v6WpI~
    ,{ 0x1400, 0x167f } //  Unified Canadian Aboriginal Syllabics  //~v6WpI~
//  ,{ 0x1680, 0x169f } //  Ogham del WXE                          //~v6WpI~
//  ,{ 0x16a0, 0x16ff } //  Runic ,looks like sbcs                 //~v6WpI~
    ,{ 0x1700, 0x171f } //  Tagalog                                //~v6WpI~
//  ,{ 0x1720, 0x173f } //  Hanunoo,looks like sbcs                //~v6WpI~
    ,{ 0x1740, 0x175f } //  Buhid (unprintable)                    //~v6WpI~
    ,{ 0x1760, 0x177f } //  Tagbanwa(unprintable)                  //~v6WpI~
    ,{ 0x1780, 0x17ff } //  Khmer                                  //~v6WpI~
    ,{ 0x1800, 0x18af } //  Mongolian(unprintable)                 //~v6WpI~
    ,{ 0x18b0, 0x18ff } //  Unified Canadian Aboriginal Syllabics extended//~v6WpI~
    ,{ 0x1900, 0x194f } //  Limbu(Unprintable)                     //~v6WpI~
//  ,{ 0x1950, 0x197f } //  Tai Le del WXE                         //~v6WpI~
//  ,{ 0x1980, 0x19df } //  New Tai Lue(Unprintable) del WXE       //~v6WpI~
    ,{ 0x19e0, 0x19ff } //  khmer symbols                          //~v6WpI~
    ,{ 0x1a00, 0x1a1f } //  Buginese                               //~v6WpI~
    ,{ 0x1a20, 0x1aaf } //  Tai Tham(Unprintable)                  //~v6WpI~
//  ,{ 0x1ab0, 0x1aff } //  Combining Diacritical Marks Extended (1ab0-1abe:wcwidth=0, 1abf-1aff:wcwidth=-1)//~v6WpI~
    ,{ 0x1b00, 0x1b7f } //  Balinese(Unprintable)                  //~v6WpI~
    ,{ 0x1b80, 0x1bbf } //  Sundanes(Unprintable)                  //~v6WpI~
    ,{ 0x1bc0, 0x1bff } //  Batak(Unprintable)                     //~v6WpI~
    ,{ 0x1c00, 0x1c4f } //  Lepcha(Unprintable)                    //~v6WpI~
//  ,{ 0x1c50, 0x1c7f } //  Ol Chiki(Unprintable) del WXE          //~v6WpI~
    ,{ 0x1c80, 0x1c8f } //  Cyrillic Extended-C                    //~v6WpI~
                                                                   //~v6WpI~
    ,{ 0x1cc0, 0x1ccf } //  Sundanes Supplements(Unprintable)      //~v6WpI~
    ,{ 0x1cd0, 0x1cff } //  Vedic Extensions                       //~v6WpI~
    ,{ 0x1d00, 0x1d7f } //  Phonetic Extensions                    //~v6WpI~
    ,{ 0x1d80, 0x1dbf } //  Phonetic Extensions Supplement         //~v6WpI~
//  ,{ 0x1dc0, 0x1dff } //  Combining Diacritical Marks Supplement , wcwidth=1//~v6WpI~
    ,{ 0x1e00, 0x1eff } //  Latic extended additional              //~v6WpI~
//  ,{ 0x1f00, 0x1fff } //  Greek Extended (sbcs)                  //~v6WpI~
//  ,{ 0x2000, 0x2bff } //  By Suctb_utf8 @@@@test                 //~v6WpI~
    ,{ 0x2c00, 0x2c5f } //  Glagolitic                             //~v6WpI~
    ,{ 0x2c60, 0x2c7f } //  Latic Extended-C                       //~v6WpI~
    ,{ 0x2c80, 0x2cff } //  Coptic                                 //~v6WpI~
    ,{ 0x2d00, 0x2d2f } //  Georgian Supplement                    //~v6WpI~
    ,{ 0x2d30, 0x2d7f } //  Tifinagh                               //~v6WpI~
    ,{ 0x2d80, 0x2ddf } //  Ethiopic Extended                      //~v6WpI~
    ,{ 0x2de0, 0x2dff } //  Cyrillic Extended-A                    //~v6WpI~
//  ,{ 0x2e00, 0x2e7f } //  By Suctb_utf8  @@@@test                //~v6WpI~
    ,{ 0x2e80, 0xa4cf } //  mk_wcwidth dbcs                        //~v6WpI~
    ,{ 0xa4d0, 0xa4ff } //  Lisu                                   //~v6WpI~
    ,{ 0xa500, 0xa63f } //  Vai                                    //~v6WpI~
    ,{ 0xa640, 0xa69f } //  Cyrillic Extended-B                    //~v6WpI~
    ,{ 0xa6a0, 0xa6ff } //  Bamum(Unprintable)                     //~v6WpI~
//  ,{ 0xa700, 0xa71f } //  Modifier Tone Letters, looks like sbcs //~v6WpI~
    ,{ 0xa720, 0xa7ff } //  Latin Extended-D                       //~v6WpI~
    ,{ 0xa800, 0xa82f } //  Syloti Nagri(Unprintable)              //~v6WpI~
    ,{ 0xa830, 0xa83f } //  Common Indic Number Forms              //~v6WpI~
    ,{ 0xa840, 0xa87f } //  Phags-pa                               //~v6WpI~
    ,{ 0xa880, 0xa8df } //  Saurashtra                             //~v6WpI~
    ,{ 0xa8e0, 0xa8ff } //  Devanagari Extended                    //~v6WpI~
//  ,{ 0xa900, 0xa92f } //  Kayah Li , looks like sbcs             //~v6WpI~
    ,{ 0xa930, 0xa95f } //  Rejang                                 //~v6WpI~
//  ,{ 0xa960, 0xa97f } //  Hangul Jambo Extended-A (wcwidth=dbcs) //~v6WpI~
    ,{ 0xa980, 0xa9df } //  Javanese                               //~v6WpI~
    ,{ 0xa9e0, 0xa9ff } //  Myanmar Extended-B                     //~v6WpI~
    ,{ 0xaa00, 0xaa5f } //  Cham                                   //~v6WpI~
    ,{ 0xaa60, 0xaa7f } //  Myanmar Extended-A                     //~v6WpI~
    ,{ 0xaa80, 0xaadf } //  Tai Viet                               //~v6WpI~
    ,{ 0xaae0, 0xaaff } //  Meetei Mayek Extensions                //~v6WpI~
    ,{ 0xab00, 0xab2f } //  Ethiopic Extended-A                    //~v6WpI~
    ,{ 0xab30, 0xab6f } //  Latin Extended-E                       //~v6WpI~
    ,{ 0xab70, 0xabbf } //  Cherokee Supplement                    //~v6WpI~
    ,{ 0xabc0, 0xabff } //  Meetei Mayek                           //~v6WpI~
//  ,{ 0xac00, 0xd7af } //  Hangul Syllables(mk_wcwidth:dbcs)      //~v6WpI~
//  ,{ 0xd7bf, 0xd7ff } //  Hangul Jambo Exteded-B(dbcs)           //~v6WpI~
//  ,{ 0xd800, 0xdfff } //  Surrogate                              //~v6WpI~
//  ,{ 0xe000, 0xf8ff } //  private use area                       //~v6WpI~
//  ,{ 0xf900, 0xfaff } //  CJK Compatibility Ideographs(mk_wcwidth=dbcs)//~v6WpI~
    ,{ 0xfb00, 0xfb4f } //  Alphabetic Presentation Forms          //~v6WpI~
    ,{ 0xfb50, 0xfdff } //  Alphabetic Presentation Forms-A        //~v6WpI~
//  ,{ 0xfe00, 0xfe0f } //  Variation Selectors(wcwidth=0)         //~v6WpI~
//  ,{ 0xfe10, 0xfe1f } //  Vertical Forms (mk_wcwidth=dbcs)       //~v6WpI~
//  ,{ 0xfe20, 0xfe2f } //  Combining Half Marks(wcwidth=0)        //~v6WpI~
//  ,{ 0xfe30, 0xfe4f } //  CJK Compatibility Forms(mk_wcwidth=dbcs)//~v6WpI~
//  ,{ 0xfe50, 0xfe6f } //  Small Form variants(mk_wcwidth=dbcs)   //~v6WpI~
    ,{ 0xfe70, 0xfeff } //  Arabic Presentation Forms-B            //~v6WpI~
//  ,{ 0xff00, 0xffef } //  HalfWidth and Fullwidth Formas         //~v6WpI~
//      { 0xff00, 0xff60 } //  dbcs by mk_wcwidth                  //~v6WpI~
//      { 0xff61, 0xffef } //  sbcs/dbcs by wcwidth                //~v6WpI~
//  ,{ 0xfff0, 0xffff } //  Specials                               //~v6WpI~
  };                                                               //~v6WpI~
#endif                                                             //~v6WpI~
  static const struct interval Sambiguous_langs_ucs4[] = {         //~v6V2I~
     { 0x0000, 0x0000 } //  dummy                                  //~v6V2I~
//U+10000..U+1007F  :Linear B Syllabary:Linear B                   //~v6V2I~
//U+10080..U+100FF  :Linear B Ideograms:Linear B                   //~v6V2I~
//U+10100..U+1013F  :Aegean Numbers:Common                         //~v6V2I~
    ,{0X10100,0X1013F}                                                 //~v6V2I~//~v6V8R~
//U+10140..U+1018F  :Ancient Greek Numbers:Greek                   //~v6V2I~
    ,{0X10140,0X1018f}                                                 //~v6V2R~//~v6V8R~
//U+10190..U+101CF  :Ancient Symbols:Greek (1 character), Common (12 characters)//~v6V2I~
    ,{0x10190,0x101CF}                                                 //~v6V2R~//~v6V8R~
//U+101D0..U+101FF  :Phaistos Disc:Common (45 characters), Inherited (1 character)//~v6V2I~
    ,{0X101d0,0X101fF}                                                 //~v6V2I~//~v6V8R~
//U+10280..U+1029F  :Lycian:Lycian                                 //~v6V2I~
//U+102A0..U+102DF  :Carian:Carian                                 //~v6V2I~
//U+102E0..U+102FF  :Coptic Epact Numbers:Common (27 characters), Inherited (1 character)//~v6V2I~
    ,{0x102E0, 0x102FF}  //102e0:wcwidth=0                             //~v6V2I~//~v6V8R~
//U+10300..U+1032F  :Old Italic:Old Italic                         //~v6V2I~
    ,{0x10300, 0x1032F}                                                //~v6V2I~//~v6V8R~
////1 SMP                                                          //~v6V2I~
//U+10330..U+1034F  :Gothic:Gothic                                 //~v6V2I~
    ,{0x10330, 0x1034F}                                                //~v6V2I~//~v6V8R~
//U+10350..U+1037F  :Old Permic:Old Permic                         //~v6V2I~
//U+10380..U+1039F  :Ugaritic:Ugaritic                             //~v6V2I~
    ,{0x10380, 0x1039F}                                                //~v6V2I~//~v6V8R~
//U+103A0..U+103DF  :Old Persian:Old Persian                       //~v6V2I~
    ,{0x103A0, 0x103DF}                                                //~v6V2I~//~v6V8R~
//U+10400..U+1044F  :Deseret:Deseret                               //~v6V2I~
    ,{0x10400, 0x1044F}                                                //~v6V2I~//~v6V8R~
//U+10450..U+1047F  :Shavian:Shavian                               //~v6V2I~
//U+10480..U+104AF  :Osmanya:Osmanya                               //~v6V2I~
    ,{0x10480, 0x104AF}                                                //~v6V2I~//~v6V8R~
//U+104B0..U+104FF  :Osage:Osage                                   //~v6V2I~
//U+10500..U+1052F  :Elbasan:Elbasan                               //~v6V2I~
//U+10530..U+1056F  :Caucasian Albanian:Caucasian Albanian         //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10600..U+1077F  :Linear A:Linear A                             //~v6V2I~
//U+10800..U+1083F  :Cypriot Syllabary:Cypriot                     //~v6V2I~
//U+10840..U+1085F  :Imperial Aramaic:Imperial Aramaic             //~v6V2I~
//U+10860..U+1087F  :Palmyrene:Palmyrene                           //~v6V2I~
//U+10880..U+108AF  :Nabataean:Nabataean                           //~v6V2I~
//U+108E0..U+108FF  :Hatran:Hatran                                 //~v6V2I~
//U+10900..U+1091F  :Phoenician:Phoenician                         //~v6V2I~
    ,{0x10900, 0x1091F}                                                //~v6V2I~//~v6V8R~
//U+10920..U+1093F  :Lydian:Lydian                                 //~v6V2I~
//U+10980..U+1099F  :Meroitic Hieroglyphs:Meroitic Hieroglyphs     //~v6V2I~
//U+109A0..U+109FF  :Meroitic Cursive:Meroitic Cursive             //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10A00..U+10A5F  :Kharoshthi:Kharoshthi                         //~v6V2I~
//U+10A60..U+10A7F  :Old South Arabian:Old South Arabian           //~v6V2I~
//U+10A80..U+10A9F  :Old North Arabian:Old North Arabian           //~v6V2I~
//U+10AC0..U+10AFF  :Manichaean:Manichaean                         //~v6V2I~
//U+10B00..U+10B3F  :Avestan:Avestan                               //~v6V2I~
//U+10B40..U+10B5F  :Inscriptional Parthian:Inscriptional Parthian //~v6V2I~
//U+10B60..U+10B7F  :Inscriptional Pahlavi:Inscriptional Pahlavi   //~v6V2I~
//U+10B80..U+10BAF  :Psalter Pahlavi:Psalter Pahlavi               //~v6V2I~
//U+10C00..U+10C4F  :Old Turkic:Old Turkic                         //~v6V2I~
//U+10C80..U+10CFF  :Old Hungarian:Old Hungarian                   //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10E60..U+10E7F  :Rumi Numeral Symbols:Arabic                   //~v6V2I~
//U+11000..U+1107F  :Brahmi:Brahmi                                 //~v6V2I~
//U+11080..U+110CF  :Kaithi:Kaithi                                 //~v6V2I~
//U+110D0..U+110FF  :Sora Sompeng:Sora Sompeng                     //~v6V2I~
//U+11100..U+1114F  :Chakma:Chakma                                 //~v6V2I~
//U+11150..U+1117F  :Mahajani:Mahajani                             //~v6V2I~
//U+11180..U+111DF  :Sharada:Sharada                               //~v6V2I~
//U+111E0..U+111FF  :Sinhala Archaic Numbers:Sinhala               //~v6V2I~
//U+11200..U+1124F  :Khojki:Khojki                                 //~v6V2I~
//U+11280..U+112AF  :Multani:Multani                               //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+112B0..U+112FF  :Khudawadi:Khudawadi                           //~v6V2I~
//U+11300..U+1137F  :Grantha:Grantha                               //~v6V2I~
//U+11400..U+1147F  :Newa:Newa                                     //~v6V2I~
//U+11480..U+114DF  :Tirhuta:Tirhuta                               //~v6V2I~
//U+11580..U+115FF  :Siddham:Siddham                               //~v6V2I~
//U+11600..U+1165F  :Modi:Modi                                     //~v6V2I~
//U+11660..U+1167F  :Mongolian Supplement:Mongolian                //~v6V2I~
//U+11680..U+116CF  :Takri:Takri                                   //~v6V2I~
//U+11700..U+1173F  :Ahom:Ahom                                     //~v6V2I~
//U+118A0..U+118FF  :Warang Citi:Warang Citi                       //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+11A00..U+11A4F  :Zanabazar Square:Zanabazar Square             //~v6V2I~
//U+11A50..U+11AAF  :Soyombo:Soyombo                               //~v6V2I~
//U+11AC0..U+11AFF  :Pau Cin Hau:Pau Cin Hau                       //~v6V2I~
//U+11C00..U+11C6F  :Bhaiksuki:Bhaiksuki                           //~v6V2I~
//U+11C70..U+11CBF  :Marchen:Marchen                               //~v6V2I~
//U+11D00..U+11D5F  :Masaram Gondi:Masaram Gondi                   //~v6V2I~
//U+12000..U+123FF  :Cuneiform:Cuneiform                           //~v6V2I~
//U+12400..U+1247F  :Cuneiform Numbers and Punctuation:Cuneiform   //~v6V2I~
//U+12480..U+1254F  :Early Dynastic Cuneiform:Cuneiform            //~v6V2I~
//U+13000..U+1342F  :Egyptian Hieroglyphs:Egyptian Hieroglyphs     //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+14400..U+1467F  :Anatolian Hieroglyphs:Anatolian Hieroglyphs   //~v6V2I~
//U+16800..U+16A3F  :Bamum Supplement:Bamum                        //~v6V2I~
//U+16A40..U+16A6F  :Mro:Mro                                       //~v6V2I~
//U+16AD0..U+16AFF  :Bassa Vah:Bassa Vah                           //~v6V2I~
//U+16B00..U+16B8F  :Pahawh Hmong:Pahawh Hmong                     //~v6V2I~
//U+16F00..U+16F9F  :Miao:Miao                                     //~v6V2I~
//U+16FE0..U+16FFF  :Ideographic Symbols and Punctuation:Nushu (1 character), Tangut (1 character)//~v6V2I~
//U+17000..U+187FF  :Tangut:Tangut                                 //~v6V2I~
//U+18800..U+18AFF  :Tangut Components:Tangut                      //~v6V2I~
//U+1B000..U+1B0FF  :Kana Supplement:Hiragana (255 characters), Katakana (1 character)//~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+1B100..U+1B12F  :Kana Extended-A:Hiragana                      //~v6V2I~
//U+1B170..U+1B2FF  :Nushu:N端shu                                   //~v6V2I~
//U+1BC00..U+1BC9F  :Duployan:Duployan                             //~v6V2I~
//U+1BCA0..U+1BCAF  :Shorthand Format Controls:Common              //~v6V2I~
//U+1D000..U+1D0FF  :Byzantine Musical Symbols:Common              //~v6V2I~
    ,{0x1D000, 0x1D0FF}                                                //~v6V2I~//~v6V8R~
//U+1D100..U+1D1FF  :Musical Symbols:Common (209 characters), Inherited (22 characters)//~v6V2I~
    ,{0x1D100, 0x1D1FF}                                                //~v6V2I~//~v6V8R~
//U+1D200..U+1D24F  :Ancient Greek Musical Notation:Greek          //~v6V2I~
    ,{0x1D200, 0x1D24F}                                                //~v6V2I~//~v6V8R~
//U+1D300..U+1D35F  :Tai Xuan Jing Symbols:Common                  //~v6V2I~
    ,{0x1D300, 0x1D35F}                                                //~v6V2I~//~v6V8R~
//U+1D360..U+1D37F  :Counting Rod Numerals:Common                  //~v6V2I~
    ,{0x1D360, 0x1D37F}                                                //~v6V2I~//~v6V8R~
//U+1D400..U+1D7FF  :Mathematical Alphanumeric Symbols:Common      //~v6V2I~
    ,{0x1D400, 0x1D7FF}                                                //~v6V2I~//~v6V8R~
////1 SMP                                                          //~v6V2I~
//U+1D800..U+1DAAF  :Sutton SignWriting:SignWriting                //~v6V2I~
//U+1E000..U+1E02F  :Glagolitic Supplement:Glagolitic              //~v6V2I~
//U+1E800..U+1E8DF  :Mende Kikakui:Mende Kikakui                   //~v6V2I~
//U+1E900..U+1E95F  :Adlam:Adlam                                   //~v6V2I~
//U+1EE00..U+1EEFF  :Arabic Mathematical Alphabetic Symbols:Arabic //~v6V2I~
    ,{0x1EE00, 0x1EEFF}                                                //~v6V2I~//~v6V8R~
//U+1F000..U+1F02F  :Mahjong Tiles:Common                          //~v6V2I~
    ,{0x1F000, 0x1F02F}                                                //~v6V2I~//~v6V8R~
//U+1F030..U+1F09F  :Domino Tiles:Common                           //~v6V2I~
    ,{0x1F030, 0x1F09F}                                                //~v6V2I~//~v6V8R~
//U+1F0A0..U+1F0FF  :Playing Cards:Common                          //~v6V2I~
    ,{0x1F0A0, 0x1F0FF}                                                //~v6V2I~//~v6V8R~
//U+1F100..U+1F1FF  :Enclosed Alphanumeric Supplement:Common       //~v6V2I~
    ,{0x1F100,0x1F1FF}                                                 //~v6V2I~//~v6V8R~
//U+1F200..U+1F2FF  :Enclosed Ideographic Supplement:Hiragana (1 character), Common (63 characters)//~v6V2I~
//,{0x1F200,0x1F2FF} //wcwidth=2                                   //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+1F300..U+1F5FF  :Miscellaneous Symbols and Pictographs:Common  //~v6V2I~
    ,{0x1F300, 0x1F5FF}                                                //~v6V2I~//~v6V8R~
//U+1F600..U+1F64F  :Emoticons:Common                              //~v6V2I~
//,{0x1F600,0x1F64f} //wcwidth=2                                   //~v6V8I~
//U+1F650..U+1F67F  :Ornamental Dingbats:Common                    //~v6V2I~
    ,{0x1F650, 0x1F67F}                                                //~v6V2I~//~v6V8R~
//U+1F680..U+1F6FF  :Transport and Map Symbols:Common              //~v6V2I~
    ,{0x1F680, 0x1F6FF}                                                //~v6V2I~//~v6V8R~
//U+1F700..U+1F77F  :Alchemical Symbols:Common                     //~v6V2I~
    ,{0x1F700, 0x1F77F}                                                //~v6V2I~//~v6V8R~
//U+1F780..U+1F7FF  :Geometric Shapes Extended:Common              //~v6V2I~
    ,{0x1F780, 0x1F7FF}                                                //~v6V2I~//~v6V8R~
//U+1F800..U+1F8FF  :Supplemental Arrows-C:Common                  //~v6V2I~
    ,{0x1F800, 0x1F8FF}                                                //~v6V2I~//~v6V8R~
//U+1F900..U+1F9FF  :Supplemental Symbols and Pictographs:Common   //~v6V2I~
    ,{0x1F900, 0x1F9FF}                                                //~v6V2I~//~v6V8R~
//2 SIP                                                            //~v6V2I~
//U+20000..U+2A6DF  :CJK Unified Ideographs Extension B:Han        //~v6V2I~
//U+2A700..U+2B73F  :CJK Unified Ideographs Extension C:Han        //~v6V2I~
//U+2B740..U+2B81F  :CJK Unified Ideographs Extension D:Han        //~v6V2I~
//U+2B820..U+2CEAF  :CJK Unified Ideographs Extension E:Han        //~v6V2I~
//U+2CEB0..U+2EBEF  :CJK Unified Ideographs Extension F:Han        //~v6V2I~
//U+2F800..U+2FA1F  :CJK Compatibility Ideographs Supplement:Han   //~v6V2I~
////14 SSP                                                         //~v6V2I~
//U+E0000..U+E007F  :Tags:Common                                   //~v6V2I~
//U+E0100..U+E01EF  :Variation Selectors Supplement:Inherited      //~v6V2I~
////15 PUA-A                                                       //~v6V2I~
//U+F0000..U+FFFFF  :Supplementary Private Use Area-A:Unknown      //~v6V2I~
////16 PUA-B                                                       //~v6V2I~
//U+100000..U+10FFFF:Supplementary Private Use Area-B:Unknown      //~v6V2I~
  };                                                               //~v6V2I~
//also WXE use this ******************************************     //~v6WpI~
  static const struct interval Sambiguous_langs_ucs4_XXE[] = {     //~v6WkI~
     { 0x0000, 0x0000 } //  dummy                                  //~v6WkI~
//U+10000..U+1007F  :Linear B Syllabary:Linear B                   //~v6WkI~
//U+10080..U+100FF  :Linear B Ideograms:Linear B                   //~v6WkI~
//U+10100..U+1013F  :Aegean Numbers:Common                         //~v6WkI~
    ,{0X10100,0X1013F}                                             //~v6WkI~
//U+10140..U+1018F  :Ancient Greek Numbers:Greek                   //~v6WkI~
    ,{0X10140,0X1018f}                                             //~v6WkI~
//U+10190..U+101CF  :Ancient Symbols:Greek (1 character), Common (12 characters)//~v6WkI~
    ,{0x10190,0x101CF}                                             //~v6WkI~
//U+101D0..U+101FF  :Phaistos Disc:Common (45 characters), Inherited (1 character)//~v6WkI~
    ,{0X101d0,0X101fF}                                             //~v6WkI~
//U+10280..U+1029F  :Lycian:Lycian                                 //~v6WkI~
//U+102A0..U+102DF  :Carian:Carian                                 //~v6WkI~
//U+102E0..U+102FF  :Coptic Epact Numbers:Common (27 characters), Inherited (1 character)//~v6WkI~
    ,{0x102E0, 0x102FF}  //102e0:wcwidth=0                         //~v6WkI~
//U+10300..U+1032F  :Old Italic:Old Italic                         //~v6WkI~
    ,{0x10300, 0x1032F}                                            //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+10330..U+1034F  :Gothic:Gothic                                 //~v6WkI~
//    ,{0x10330, 0x1034F}                                          //~v6WkR~
      ,{0x10330, 0x1034F}                                          //~v6WnI~
//U+10350..U+1037F  :Old Permic:Old Permic                         //~v6WkI~
//U+10380..U+1039F  :Ugaritic:Ugaritic                             //~v6WkI~
    ,{0x10380, 0x1039F}                                            //~v6WkI~
//U+103A0..U+103DF  :Old Persian:Old Persian                       //~v6WkI~
    ,{0x103A0, 0x103DF}                                            //~v6WkI~
//U+10400..U+1044F  :Deseret:Deseret                               //~v6WkI~
//    ,{0x10400, 0x1044F}                                          //~v6WkR~
      ,{0x10400, 0x1044F}                                          //~v6WnI~
//U+10450..U+1047F  :Shavian:Shavian                               //~v6WkI~
//U+10480..U+104AF  :Osmanya:Osmanya                               //~v6WkI~
    ,{0x10480, 0x104AF}                                            //~v6WkI~
//U+104B0..U+104FF  :Osage:Osage                                   //~v6WkI~
//U+10500..U+1052F  :Elbasan:Elbasan                               //~v6WkI~
//U+10530..U+1056F  :Caucasian Albanian:Caucasian Albanian         //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+10600..U+1077F  :Linear A:Linear A                             //~v6WkI~
//U+10800..U+1083F  :Cypriot Syllabary:Cypriot                     //~v6WkI~
//U+10840..U+1085F  :Imperial Aramaic:Imperial Aramaic             //~v6WkI~
//U+10860..U+1087F  :Palmyrene:Palmyrene                           //~v6WkI~
//U+10880..U+108AF  :Nabataean:Nabataean                           //~v6WkI~
//U+108E0..U+108FF  :Hatran:Hatran                                 //~v6WkI~
//U+10900..U+1091F  :Phoenician:Phoenician                         //~v6WkI~
    ,{0x10900, 0x1091F}                                            //~v6WkI~
//U+10920..U+1093F  :Lydian:Lydian                                 //~v6WkI~
//U+10980..U+1099F  :Meroitic Hieroglyphs:Meroitic Hieroglyphs     //~v6WkI~
//U+109A0..U+109FF  :Meroitic Cursive:Meroitic Cursive             //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+10A00..U+10A5F  :Kharoshthi:Kharoshthi                         //~v6WkI~
//U+10A60..U+10A7F  :Old South Arabian:Old South Arabian           //~v6WkI~
//U+10A80..U+10A9F  :Old North Arabian:Old North Arabian           //~v6WkI~
//U+10AC0..U+10AFF  :Manichaean:Manichaean                         //~v6WkI~
//U+10B00..U+10B3F  :Avestan:Avestan                               //~v6WkI~
//U+10B40..U+10B5F  :Inscriptional Parthian:Inscriptional Parthian //~v6WkI~
//U+10B60..U+10B7F  :Inscriptional Pahlavi:Inscriptional Pahlavi   //~v6WkI~
//U+10B80..U+10BAF  :Psalter Pahlavi:Psalter Pahlavi               //~v6WkI~
//U+10C00..U+10C4F  :Old Turkic:Old Turkic                         //~v6WkI~
//U+10C80..U+10CFF  :Old Hungarian:Old Hungarian                   //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+10E60..U+10E7F  :Rumi Numeral Symbols:Arabic                   //~v6WkI~
//U+11000..U+1107F  :Brahmi:Brahmi                                 //~v6WkI~
//U+11080..U+110CF  :Kaithi:Kaithi                                 //~v6WkI~
//U+110D0..U+110FF  :Sora Sompeng:Sora Sompeng                     //~v6WkI~
//U+11100..U+1114F  :Chakma:Chakma                                 //~v6WkI~
//U+11150..U+1117F  :Mahajani:Mahajani                             //~v6WkI~
//U+11180..U+111DF  :Sharada:Sharada                               //~v6WkI~
//U+111E0..U+111FF  :Sinhala Archaic Numbers:Sinhala               //~v6WkI~
//U+11200..U+1124F  :Khojki:Khojki                                 //~v6WkI~
//U+11280..U+112AF  :Multani:Multani                               //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+112B0..U+112FF  :Khudawadi:Khudawadi                           //~v6WkI~
//U+11300..U+1137F  :Grantha:Grantha                               //~v6WkI~
//U+11400..U+1147F  :Newa:Newa                                     //~v6WkI~
//U+11480..U+114DF  :Tirhuta:Tirhuta                               //~v6WkI~
//U+11580..U+115FF  :Siddham:Siddham                               //~v6WkI~
//U+11600..U+1165F  :Modi:Modi                                     //~v6WkI~
//U+11660..U+1167F  :Mongolian Supplement:Mongolian                //~v6WkI~
//U+11680..U+116CF  :Takri:Takri                                   //~v6WkI~
//U+11700..U+1173F  :Ahom:Ahom                                     //~v6WkI~
//U+118A0..U+118FF  :Warang Citi:Warang Citi                       //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+11A00..U+11A4F  :Zanabazar Square:Zanabazar Square             //~v6WkI~
//U+11A50..U+11AAF  :Soyombo:Soyombo                               //~v6WkI~
//U+11AC0..U+11AFF  :Pau Cin Hau:Pau Cin Hau                       //~v6WkI~
//U+11C00..U+11C6F  :Bhaiksuki:Bhaiksuki                           //~v6WkI~
//U+11C70..U+11CBF  :Marchen:Marchen                               //~v6WkI~
//U+11D00..U+11D5F  :Masaram Gondi:Masaram Gondi                   //~v6WkI~
//U+12000..U+123FF  :Cuneiform:Cuneiform                           //~v6WkI~
//U+12400..U+1247F  :Cuneiform Numbers and Punctuation:Cuneiform   //~v6WkI~
//U+12480..U+1254F  :Early Dynastic Cuneiform:Cuneiform            //~v6WkI~
//U+13000..U+1342F  :Egyptian Hieroglyphs:Egyptian Hieroglyphs     //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+14400..U+1467F  :Anatolian Hieroglyphs:Anatolian Hieroglyphs   //~v6WkI~
//U+16800..U+16A3F  :Bamum Supplement:Bamum                        //~v6WkI~
//U+16A40..U+16A6F  :Mro:Mro                                       //~v6WkI~
//U+16AD0..U+16AFF  :Bassa Vah:Bassa Vah                           //~v6WkI~
//U+16B00..U+16B8F  :Pahawh Hmong:Pahawh Hmong                     //~v6WkI~
//U+16F00..U+16F9F  :Miao:Miao                                     //~v6WkI~
//U+16FE0..U+16FFF  :Ideographic Symbols and Punctuation:Nushu (1 character), Tangut (1 character)//~v6WkI~
//U+17000..U+187FF  :Tangut:Tangut                                 //~v6WkI~
//U+18800..U+18AFF  :Tangut Components:Tangut                      //~v6WkI~
//U+1B000..U+1B0FF  :Kana Supplement:Hiragana (255 characters), Katakana (1 character)//~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+1B100..U+1B12F  :Kana Extended-A:Hiragana                      //~v6WkI~
//U+1B170..U+1B2FF  :Nushu:N端shu                                  //~v6WkI~
//U+1BC00..U+1BC9F  :Duployan:Duployan                             //~v6WkI~
//U+1BCA0..U+1BCAF  :Shorthand Format Controls:Common              //~v6WkI~
//U+1D000..U+1D0FF  :Byzantine Musical Symbols:Common              //~v6WkI~
    ,{0x1D000, 0x1D0FF}                                            //~v6WkI~
//U+1D100..U+1D1FF  :Musical Symbols:Common (209 characters), Inherited (22 characters)//~v6WkI~
    ,{0x1D100, 0x1D1FF}                                            //~v6WkI~
//U+1D200..U+1D24F  :Ancient Greek Musical Notation:Greek          //~v6WkI~
//    ,{0x1D200, 0x1D24F}                                          //~v6WkR~
      ,{0x1D200, 0x1D24F}                                          //~v6WnI~
//U+1D300..U+1D35F  :Tai Xuan Jing Symbols:Common                  //~v6WkI~
//    ,{0x1D300, 0x1D35F}                                          //~v6WkR~
      ,{0x1D300, 0x1D35F}                                          //~v6WnI~
//U+1D360..U+1D37F  :Counting Rod Numerals:Common                  //~v6WkI~
    ,{0x1D360, 0x1D37F}                                            //~v6WkI~
//U+1D400..U+1D7FF  :Mathematical Alphanumeric Symbols:Common      //~v6WkI~
    ,{0x1D400, 0x1D7FF}                                            //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+1D800..U+1DAAF  :Sutton SignWriting:SignWriting                //~v6WkI~
//U+1E000..U+1E02F  :Glagolitic Supplement:Glagolitic              //~v6WkI~
//U+1E800..U+1E8DF  :Mende Kikakui:Mende Kikakui                   //~v6WkI~
//U+1E900..U+1E95F  :Adlam:Adlam                                   //~v6WkI~
//U+1EE00..U+1EEFF  :Arabic Mathematical Alphabetic Symbols:Arabic //~v6WkI~
    ,{0x1EE00, 0x1EEFF}                                            //~v6WkI~
//U+1F000..U+1F02F  :Mahjong Tiles:Common                          //~v6WkI~
    ,{0x1F000, 0x1F02F}                                            //~v6WkI~
//U+1F030..U+1F09F  :Domino Tiles:Common                           //~v6WkI~
    ,{0x1F030, 0x1F09F}                                            //~v6WkI~
//U+1F0A0..U+1F0FF  :Playing Cards:Common                          //~v6WkI~
    ,{0x1F0A0, 0x1F0FF}                                            //~v6WkI~
//U+1F100..U+1F1FF  :Enclosed Alphanumeric Supplement:Common       //~v6WkI~
    ,{0x1F100,0x1F1FF}                                             //~v6WkI~
//U+1F200..U+1F2FF  :Enclosed Ideographic Supplement:Hiragana (1 character), Common (63 characters)//~v6WkI~
//,{0x1F200,0x1F2FF} //wcwidth=2                                   //~v6WkI~
////1 SMP                                                          //~v6WkI~
//U+1F300..U+1F5FF  :Miscellaneous Symbols and Pictographs:Common  //~v6WkI~
    ,{0x1F300, 0x1F5FF}                                            //~v6WkI~
//U+1F600..U+1F64F  :Emoticons:Common                              //~v6WkI~
//,{0x1F600,0x1F64f} //wcwidth=2                                   //~v6WkI~
//U+1F650..U+1F67F  :Ornamental Dingbats:Common                    //~v6WkI~
    ,{0x1F650, 0x1F67F}                                            //~v6WkI~
//U+1F680..U+1F6FF  :Transport and Map Symbols:Common              //~v6WkI~
    ,{0x1F680, 0x1F6FF}                                            //~v6WkI~
//U+1F700..U+1F77F  :Alchemical Symbols:Common                     //~v6WkI~
    ,{0x1F700, 0x1F77F}                                            //~v6WkI~
//U+1F780..U+1F7FF  :Geometric Shapes Extended:Common              //~v6WkI~
//    ,{0x1F780, 0x1F7FF}                                          //~v6WkI~
      ,{0x1F780, 0x1F7FF}                                          //~v6WnI~
//U+1F800..U+1F8FF  :Supplemental Arrows-C:Common                  //~v6WkI~
//    ,{0x1F800, 0x1F8FF}                                          //~v6WkR~
      ,{0x1F800, 0x1F8FF}                                          //~v6WnI~
//U+1F900..U+1F9FF  :Supplemental Symbols and Pictographs:Common   //~v6WkI~
    ,{0x1F900, 0x1F9FF}                                            //~v6WkI~
//2 SIP                                                            //~v6WkI~
//U+20000..U+2A6DF  :CJK Unified Ideographs Extension B:Han        //~v6WkI~
//U+2A700..U+2B73F  :CJK Unified Ideographs Extension C:Han        //~v6WkI~
//U+2B740..U+2B81F  :CJK Unified Ideographs Extension D:Han        //~v6WkI~
//U+2B820..U+2CEAF  :CJK Unified Ideographs Extension E:Han        //~v6WkI~
//U+2CEB0..U+2EBEF  :CJK Unified Ideographs Extension F:Han        //~v6WkI~
//U+2F800..U+2FA1F  :CJK Compatibility Ideographs Supplement:Han   //~v6WkI~
////14 SSP                                                         //~v6WkI~
//U+E0000..U+E007F  :Tags:Common                                   //~v6WkI~
//U+E0100..U+E01EF  :Variation Selectors Supplement:Inherited      //~v6WkI~
////15 PUA-A                                                       //~v6WkI~
//U+F0000..U+FFFFF  :Supplementary Private Use Area-A:Unknown      //~v6WkI~
////16 PUA-B                                                       //~v6WkI~
//U+100000..U+10FFFF:Supplementary Private Use Area-B:Unknown      //~v6WkI~
  };                                                               //~v6WkI~
#endif //UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V2I~
//******************************************************************//~v6VbI~
//* chk ambiguous then call mk_wcwidth                             //~v6VbI~
//******************************************************************//~v6VbI~
int mk_wcwidth_cjk(UWUCS ucs)                                      //~v6VbI~
{                                                                  //~v6VbI~
    int rc=0;                                                      //~v6W9I~
//*************                                                    //~v6W9I~
  for (;;)                                                         //~v6W9I~
  {                                                                //~v6W9I~
//  if (utf4_isFormat(0,ucs))                                  //~v6WiI~//~v6WjI~//~v6WnR~
//      return 1|UTFWWF_RC_MK_WCWIDTH|UTFWWF_RC_FORMAT; //0x01000000+0x04000000//~v6WiI~//~v6WjI~//~v6WnR~
    if (!mk_wcwidth_combining(ucs)) //rc=0:combining               //~v6WnI~
		return UTFWWF_RC_MK_WCWIDTH|UTFWWF_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6WnI~
#ifdef UB1710                                                      //~v6V2I~
  if (bisearch(ucs, Sambiguous_non_langs,                          //~v6V8I~
	       sizeof(Sambiguous_non_langs) / sizeof(struct interval) - 1))//~v6V8I~
  {                                                                //~v6WnI~
//  return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6V8I~//~v6W9R~
    rc=2;                                                          //~v6W9I~
    UTRACEP("%s:%06x ambiguous non lang\n",UTT,ucs);               //~v6WnI~
  }                                                                //~v6WnI~
  else                                                             //~v6WkI~
  if (bisearch(ucs, Sambiguous_langs,                              //~v6V2I~
	       sizeof(Sambiguous_langs) / sizeof(struct interval) - 1))//~v6V2I~
  {                                                                //~v6WnI~
//  return 2;                                                      //~v6V2I~//~v6V8R~
//  return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6V8I~//~v6W9R~
    rc=2;                                                          //~v6W9I~
    UTRACEP("%s:%06x ambiguous lang\n",UTT,ucs);                   //~v6WnI~
  }                                                                //~v6WnI~
  else                                                             //~v6WkI~
  if (bisearch(ucs, Sambiguous_langs_ucs4,                         //~v6V2I~
	       sizeof(Sambiguous_langs_ucs4) / sizeof(struct interval) - 1))//~v6V2I~
  {                                                                //~v6WnI~
//  return 2;                                                      //~v6V2I~//~v6V8R~
//  return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6V8I~//~v6W9R~
    rc=2;                                                          //~v6W9I~
    UTRACEP("%s:%06x ambiguous lang_ucs4\n",UTT,ucs);              //~v6WnI~
  }                                                                //~v6WnI~
  else                                                             //~v6WkI~
#endif                                                             //~v6V2I~
  /* binary search in table of non-spacing characters */           //~7719I~
  if (bisearch(ucs, ambiguous,                                     //~7719I~
	       sizeof(ambiguous) / sizeof(struct interval) - 1))       //~7719I~
  {                                                                //~v6WnI~
//  return 2;                                                      //~7719I~//~v6V8R~
//  return 2+UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6V8I~//~v6W9R~
    rc=2;                                                          //~v6W9I~
    UTRACEP("%s:%06x ambiguous\n",UTT,ucs);                        //~v6WnI~
  }                                                                //~v6WnI~
    break;                                                         //~v6W9I~
 }	   //for                                                       //~v6W9I~
#ifndef ARM	//non spacing chk at java(Ucs.java)                    //~v6W9I~
 	if (rc)                                                        //~v6W9I~
 	{                                                              //~v6W9I~
//        if (!mk_wcwidth_combining(ucs)) //rc=0:combining           //~v6W9R~//~v6WnR~
////          return UTFWWF_RC_MK_WCWIDTH|UTFWWF_RC_MK_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6W9R~//~v6WmR~//~v6WnR~
//            return UTFWWF_RC_MK_WCWIDTH|UTFWWF_COMB; //by mk_wcwidth() adjustable by wcwidth() but not for combining//~v6WmI~//~v6WnR~
//      UTRACEP("%s:%06x ambigouous\n",UTT,ucs);                   //~v6WnI~//~v6X5R~
    	return rc|UTFWWO_MK_AMBIGUOUS; //x2000   //by mk_wcwidth() adjustable by wcwidth()//~v6W9I~
    }                                                              //~v6W9I~
#endif                                                             //~v6W9I~
                                                                   //~7719I~
//return mk_wcwidth(ucs);                                          //~7719I~//~v6WnR~
	Sfromcjk=1;                                                    //~v6WnI~
//rc=mk_wcwidth(ucs);                                              //~v6WnR~
    rc=mk_wcwidth(SUO_CONSOLE,ucs);  //mk_wcwidth_cjk is called under condition of CONSOLE//~v6WnI~
	Sfromcjk=0;                                                    //~v6WnI~
  return rc;                                                       //~v6WnI~
}                                                                  //~7719I~
#ifdef UTF8UCS2                                                                   //~7719I~//~v647R~
//int mk_wcswidth_cjk(UWCHART *pwcs, size_t n)                       //~v647R~//~v6BjR~
int mk_wcswidth_cjk(UWUCS *pwcs, size_t n)                         //~v6BjI~
#else                                                              //~v647R~
int mk_wcswidth_cjk(const wchar_t *pwcs, size_t n)                 //~7719I~
#endif                                                             //~v647R~
{                                                                  //~7719I~
  int w, width = 0;                                                //~7719I~
                                                                   //~7719I~
  for (;*pwcs && n-- > 0; pwcs++)                                  //~7719I~
    if ((w = mk_wcwidth_cjk(*pwcs)) < 0)                           //~7719I~
      return -1;                                                   //~7719I~
    else                                                           //~7719I~
      width += w;                                                  //~7719I~
                                                                   //~7719I~
  return width;                                                    //~7719I~
}                                                                  //~7719I~
#ifdef AAA                                                         //~7925I~
//******************************************************           //~7920I~
//modification to wcwidth_cjk                                      //~7922R~
//result from display test on WindowsXP:CP932(Japanese)            //~7922M~
//******************************************************           //~7920I~
//int mk_wcwidth_j(wchar_t ucs)                                     //~7920I~//~v650R~//~v6a0R~
int mk_wcwidth_j(UWCHART ucs)                                      //~v6a0R~
{                                                                  //~7920I~
  static const struct interval Sdbcstb[] = {                       //~7922M~
    { 0x00A7, 0x00A8 }   //ss,"                                    //~7922I~
   ,{ 0x00B0, 0x00B1 }   //degree,+-                               //~7922I~
   ,{ 0x00B4, 0x00B4 }   //'                                       //~7922I~
   ,{ 0x00B6, 0x00B6 }   //q                                       //~7922I~
   ,{ 0x00D7, 0x00D7 }   //X                                       //~7922R~
   ,{ 0x00F6, 0x00F6 }   //divide                                  //~7922I~
  };                                                               //~7922M~
  static const struct interval Ssbcstb[] = {                       //~7922I~
    { 0x0080, 0x00ff }   //i,cent,pond                             //~7922R~
  };                                                               //~7922I~
                                                                   //~7920I~
  if (bisearch(ucs,Sdbcstb,     //DBCS                             //~7922I~
	       sizeof(Sdbcstb) / sizeof(struct interval) - 1))         //~7922M~
    return 2;                                                      //~7922M~
  if (bisearch(ucs,Ssbcstb,     //SBCS                             //~7922M~
	       sizeof(Ssbcstb) / sizeof(struct interval) - 1))         //~7922M~
    return 1;                                                      //~7922M~
  return mk_wcwidth_cjk(ucs);                                      //~7922R~
}//mk_wcwidth_j                                                    //~7920I~
#endif                                                             //~7925I~
//******************************************************           //~v6c5I~
//after chked as defined as sbcs by Java                           //~v6c5I~
//to reduce sbcsid tbl, define some range as dbcs                  //~v6c5I~
//******************************************************           //~v6c5I~
//int mk_wcwidth_adjsbcs(UWCHART ucs)                                //~v6c5R~//~v6BjR~
int mk_wcwidth_adjsbcs(UWUCS ucs)                                  //~v6BjI~
{                                                                  //~v6c5I~
// !!! if updated , update also Axe/Ucs.java !!!                   //~v6c5I~
    static const struct interval Sdbcstb[] = {                     //~v6c5R~
         { 0x2e80, 0x2eff }  //128:CJK Radicals Supplement         //~v6c5R~
        ,{ 0x2f00, 0x2fdf }  //224:Kangxi Radicals                 //~v6c5R~
        ,{ 0x3400, 0x4dbf }  //6112:CJK Unified Ideographs Extensions//~v6c5R~
        ,{ 0xa000, 0xa48f }  //1168:Yi Syllables                   //~v6c5R~
        ,{ 0xa490, 0xa4cf }  //64:Yi Radicals                      //~v6c5I~
        ,{ 0xac00, 0xd7af }  //11184:Hangle syllables              //~v6k2I~
        ,{ 0xe000, 0xf8ff}   //6400:private                        //~v6c5I~
        };                                                         //~v6c5R~
	if (Gulibutfmode & GULIBUTF_JAVAWCWIDTH)//char width(sbcs or dbcs) determined not by mk_wcwidth() but by Java wcwidth()//~v6c5I~
    {                                                              //~v6c5I~
    	if (bisearch(ucs,Sdbcstb,sizeof(Sdbcstb) / sizeof(struct interval) - 1))//~v6c5R~
        	return 2;                                              //~v6c5R~
    	return 1;                                                  //~v6c5I~
    }                                                              //~v6c5I~
//*copy from mk_wcwidth, compining and unprintable will be chked after by Java wcwidth()//~v6c5I~
  return 1 +                                                       //~v6c5I~
    (ucs >= 0x1100 &&                                              //~v6c5I~
     (ucs <= 0x115f ||                    /* Hangul Jamo init. consonants *///~v6c5I~
      ucs == 0x2329 || ucs == 0x232a ||                            //~v6c5I~
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&                           //~v6c5I~
       ucs != 0x303f) ||                  /* CJK ... Yi */         //~v6c5I~
      (ucs >= 0xac00 && ucs <= 0xd7a3) || /* Hangul Syllables */   //~v6c5I~
      (ucs >= 0xf900 && ucs <= 0xfaff) || /* CJK Compatibility Ideographs *///~v6c5I~
      (ucs >= 0xfe10 && ucs <= 0xfe19) || /* Vertical forms */     //~v6c5I~
      (ucs >= 0xfe30 && ucs <= 0xfe6f) || /* CJK Compatibility Forms *///~v6c5I~
      (ucs >= 0xff00 && ucs <= 0xff60) || /* Fullwidth Forms */    //~v6c5I~
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||                          //~v6c5I~
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||                        //~v6c5I~
      (ucs >= 0x30000 && ucs <= 0x3fffd)));                        //~v6c5I~
}//mk_wcwidth_afterapi                                             //~v6c5I~
//*************************************************************    //~v6V2I~
//2018/04/24  https://en/wikipedia.org/wiki/Unicode_block          //~v6V2I~
//*************************************************************    //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+0000..U+007F    :Basic Latin[g]:Latin (52 characters), Common (76 characters)//~v6V2I~
//U+0080..U+00FF    :Latin-1 Supplement[h]:Latin (64 characters), Common (64 characters)//~v6V2I~
//U+0100..U+017F    :Latin Extended-A:Latin                        //~v6V2I~
//U+0180..U+024F    :Latin Extended-B:Latin                        //~v6V2I~
//U+0250..U+02AF    :IPA Extensions:Latin                          //~v6V2I~
//U+02B0..U+02FF    :Spacing Modifier Letters:Bopomofo (2 characters), Latin (14 characters), Common (64 characters)//~v6V2I~
//U+0300..U+036F    :Combining Diacritical Marks:Inherited         //~v6V2I~
//U+0370..U+03FF    :Greek and Coptic:Coptic (14 characters), Greek (117 characters), Common (4 characters)//~v6V2I~
//U+0400..U+04FF    :Cyrillic:Cyrillic (254 characters), Inherited (2 characters)//~v6V2I~
//U+0500..U+052F    :Cyrillic Supplement:Cyrillic                  //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+0530..U+058F    :Armenian:Armenian (88 characters), Common (1 character)//~v6V2I~
//U+0590..U+05FF    :Hebrew:Hebrew                                 //~v6V2I~
//U+0600..U+06FF    :Arabic:Arabic (237 characters), Common (6 characters), Inherited (12 characters)//~v6V2I~
//U+0700..U+074F    :Syriac:Syriac                                 //~v6V2I~
//U+0750..U+077F    :Arabic Supplement:Arabic                      //~v6V2I~
//U+0780..U+07BF    :Thaana:Thaana                                 //~v6V2I~
//U+07C0..U+07FF    :NKo:Nko                                       //~v6V2I~
//U+0800..U+083F    :Samaritan:Samaritan                           //~v6V2I~
//U+0840..U+085F    :Mandaic:Mandaic                               //~v6V2I~
//U+0860..U+086F    :Syriac Supplement:Syriac                      //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+08A0..U+08FF    :Arabic Extended-A:Arabic (72 characters), Common (1 character)//~v6V2I~
//U+0900..U+097F    :Devanagari:Devanagari (124 characters), Common (2 characters), Inherited (2 characters)//~v6V2I~
//U+0980..U+09FF    :Bengali:Bengali                               //~v6V2I~
//U+0A00..U+0A7F    :Gurmukhi:Gurmukhi                             //~v6V2I~
//U+0A80..U+0AFF    :Gujarati:Gujarati                             //~v6V2I~
//U+0B00..U+0B7F    :Oriya:Oriya                                   //~v6V2I~
//U+0B80..U+0BFF    :Tamil:Tamil                                   //~v6V2I~
//U+0C00..U+0C7F    :Telugu:Telugu                                 //~v6V2I~
//U+0C80..U+0CFF    :Kannada:Kannada                               //~v6V2I~
//U+0D00..U+0D7F    :Malayalam:Malayalam                           //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+0D80..U+0DFF    :Sinhala:Sinhala                               //~v6V2I~
//U+0E00..U+0E7F    :Thai:Thai (86 characters), Common (1 character)//~v6V2I~
//U+0E80..U+0EFF    :Lao:Lao                                       //~v6V2I~
//U+0F00..U+0FFF    :Tibetan:Tibetan (207 characters), Common (4 characters)//~v6V2I~
//U+1000..U+109F    :Myanmar:Myanmar                               //~v6V2I~
//U+10A0..U+10FF    :Georgian:Georgian (87 characters), Common (1 character)//~v6V2I~
//U+1100..U+11FF    :Hangul Jamo:Hangul                            //~v6V2I~
//U+1200..U+137F    :Ethiopic:Ethiopic                             //~v6V2I~
//U+1380..U+139F    :Ethiopic Supplement:Ethiopic                  //~v6V2I~
//U+13A0..U+13FF    :Cherokee:Cherokee                             //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+1400..U+167F    :Unified Canadian Aboriginal Syllabics:Canadian Aboriginal//~v6V2I~
//U+1680..U+169F    :Ogham:Ogham                                   //~v6V2I~
//U+16A0..U+16FF    :Runic:Runic (86 characters), Common (3 characters)//~v6V2I~
//U+1700..U+171F    :Tagalog:Tagalog                               //~v6V2I~
//U+1720..U+173F    :Hanunoo:Hanunoo (21 characters), Common (2 characters)//~v6V2I~
//U+1740..U+175F    :Buhid:Buhid                                   //~v6V2I~
//U+1760..U+177F    :Tagbanwa:Tagbanwa                             //~v6V2I~
//U+1780..U+17FF    :Khmer:Khmer                                   //~v6V2I~
//U+1800..U+18AF    :Mongolian:Mongolian (153 characters), Common (3 characters)//~v6V2I~
//U+18B0..U+18FF    :Unified Canadian Aboriginal Syllabics Extended:Canadian Aboriginal//~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+1900..U+194F    :Limbu:Limbu                                   //~v6V2I~
//U+1950..U+197F    :Tai Le:Tai Le                                 //~v6V2I~
//U+1980..U+19DF    :New Tai Lue:New Tai Lue                       //~v6V2I~
//U+19E0..U+19FF    :Khmer Symbols:Khmer                           //~v6V2I~
//U+1A00..U+1A1F    :Buginese:Buginese                             //~v6V2I~
//U+1A20..U+1AAF    :Tai Tham:Tai Tham                             //~v6V2I~
//U+1AB0..U+1AFF    :Combining Diacritical Marks Extended:Inherited//~v6V2I~
//U+1B00..U+1B7F    :Balinese:Balinese                             //~v6V2I~
//U+1B80..U+1BBF    :Sundanese:Sundanese                           //~v6V2I~
//U+1BC0..U+1BFF    :Batak:Batak                                   //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+1C00..U+1C4F    :Lepcha:Lepcha                                 //~v6V2I~
//U+1C50..U+1C7F    :Ol Chiki:Ol Chiki                             //~v6V2I~
//U+1C80..U+1C8F    :Cyrillic Extended-C:Cyrillic                  //~v6V2I~
//U+1CC0..U+1CCF    :Sundanese Supplement:Sundanese                //~v6V2I~
//U+1CD0..U+1CFF    :Vedic Extensions:Common (15 characters), Inherited (27 characters)//~v6V2I~
//U+1D00..U+1D7F    :Phonetic Extensions:Cyrillic (2 characters), Greek (15 characters), Latin (111 characters)//~v6V2I~
//U+1D80..U+1DBF    :Phonetic Extensions Supplement:Greek (1 character), Latin (63 characters)//~v6V2I~
//U+1DC0..U+1DFF    :Combining Diacritical Marks Supplement:Inherited//~v6V2I~
//U+1E00..U+1EFF    :Latin Extended Additional:Latin               //~v6V2I~
//U+1F00..U+1FFF    :Greek Extended:Greek                          //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+2000..U+206F    :General Punctuation:Common (109 characters), Inherited (2 characters)//~v6V2I~
//U+2070..U+209F    :Superscripts and Subscripts:Latin (15 characters), Common (27 characters)//~v6V2I~
//U+20A0..U+20CF    :Currency Symbols:Common                       //~v6V2I~
//U+20D0..U+20FF    :Combining Diacritical Marks for Symbols:Inherited//~v6V2I~
//U+2100..U+214F    :Letterlike Symbols:Greek (1 character), Latin (4 characters), Common (75 characters)//~v6V2I~
//U+2150..U+218F    :Number Forms:Latin (41 characters), Common (19 characters)//~v6V2I~
//U+2190..U+21FF    :Arrows:Common                                 //~v6V2I~
//U+2200..U+22FF    :Mathematical Operators:Common                 //~v6V2I~
//U+2300..U+23FF    :Miscellaneous Technical:Common                //~v6V2I~
//U+2400..U+243F    :Control Pictures:Common                       //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+2440..U+245F    :Optical Character Recognition:Common          //~v6V2I~
//U+2460..U+24FF    :Enclosed Alphanumerics:Common                 //~v6V2I~
//U+2500..U+257F    :Box Drawing:Common                            //~v6V2I~
//U+2580..U+259F    :Block Elements:Common                         //~v6V2I~
//U+25A0..U+25FF    :Geometric Shapes:Common                       //~v6V2I~
//U+2600..U+26FF    :Miscellaneous Symbols:Common                  //~v6V2I~
//U+2700..U+27BF    :Dingbats:Common                               //~v6V2I~
//U+27C0..U+27EF    :Miscellaneous Mathematical Symbols-A:Common   //~v6V2I~
//U+27F0..U+27FF    :Supplemental Arrows-A:Common                  //~v6V2I~
//U+2800..U+28FF    :Braille Patterns:Braille                      //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+2900..U+297F    :Supplemental Arrows-B:Common                  //~v6V2I~
//U+2980..U+29FF    :Miscellaneous Mathematical Symbols-B:Common   //~v6V2I~
//U+2A00..U+2AFF    :Supplemental Mathematical Operators:Common    //~v6V2I~
//U+2B00..U+2BFF    :Miscellaneous Symbols and Arrows:Common       //~v6V2I~
//U+2C00..U+2C5F    :Glagolitic:Glagolitic                         //~v6V2I~
//U+2C60..U+2C7F    :Latin Extended-C:Latin                        //~v6V2I~
//U+2C80..U+2CFF    :Coptic:Coptic                                 //~v6V2I~
//U+2D00..U+2D2F    :Georgian Supplement:Georgian                  //~v6V2I~
//U+2D30..U+2D7F    :Tifinagh:Tifinagh                             //~v6V2I~
//U+2D80..U+2DDF    :Ethiopic Extended:Ethiopic                    //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+2DE0..U+2DFF    :Cyrillic Extended-A:Cyrillic                  //~v6V2I~
//U+2E00..U+2E7F    :Supplemental Punctuation:Common               //~v6V2I~
//U+2E80..U+2EFF    :CJK Radicals Supplement:Han                   //~v6V2I~
//U+2F00..U+2FDF    :Kangxi Radicals:Han                           //~v6V2I~
//U+2FF0..U+2FFF    :Ideographic Description Characters:Common     //~v6V2I~
//U+3000..U+303F    :CJK Symbols and Punctuation:Han (15 characters), Hangul (2 characters), Common (43 characters), Inherited (4 characters)//~v6V2I~
//U+3040..U+309F    :Hiragana:Hiragana (89 characters), Common (2 characters), Inherited (2 characters)//~v6V2I~
//U+30A0..U+30FF    :Katakana:Katakana (93 characters), Common (3 characters)//~v6V2I~
//U+3100..U+312F    :Bopomofo:Bopomofo                             //~v6V2I~
//U+3130..U+318F    :Hangul Compatibility Jamo:Hangul              //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+3190..U+319F    :Kanbun:Common                                 //~v6V2I~
//U+31A0..U+31BF    :Bopomofo Extended:Bopomofo                    //~v6V2I~
//U+31C0..U+31EF    :CJK Strokes:Common                            //~v6V2I~
//U+31F0..U+31FF    :Katakana Phonetic Extensions:Katakana         //~v6V2I~
//U+3200..U+32FF    :Enclosed CJK Letters and Months:Hangul (62 characters), Katakana (47 characters), Common (145 characters)//~v6V2I~
//U+3300..U+33FF    :CJK Compatibility:Katakana (88 characters), Common (168 characters)//~v6V2I~
//U+3400..U+4DBF    :CJK Unified Ideographs Extension A:Han        //~v6V2I~
//U+4DC0..U+4DFF    :Yijing Hexagram Symbols:Common                //~v6V2I~
//U+4E00..U+9FFF    :CJK Unified Ideographs:Han                    //~v6V2I~
//U+A000..U+A48F    :Yi Syllables:Yi                               //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+A490..U+A4CF    :Yi Radicals:Yi                                //~v6V2I~
//U+A4D0..U+A4FF    :Lisu:Lisu                                     //~v6V2I~
//U+A500..U+A63F    :Vai:Vai                                       //~v6V2I~
//U+A640..U+A69F    :Cyrillic Extended-B:Cyrillic                  //~v6V2I~
//U+A6A0..U+A6FF    :Bamum:Bamum                                   //~v6V2I~
//U+A700..U+A71F    :Modifier Tone Letters:Common                  //~v6V2I~
//U+A720..U+A7FF    :Latin Extended-D:Latin (155 characters), Common (5 characters)//~v6V2I~
//U+A800..U+A82F    :Syloti Nagri:Syloti Nagri                     //~v6V2I~
//U+A830..U+A83F    :Common Indic Number Forms:Common              //~v6V2I~
//U+A840..U+A87F    :Phags-pa:Phags Pa                             //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+A880..U+A8DF    :Saurashtra:Saurashtra                         //~v6V2I~
//U+A8E0..U+A8FF    :Devanagari Extended:Devanagari                //~v6V2I~
//U+A900..U+A92F    :Kayah Li:Kayah Li (47 characters), Common (1 character)//~v6V2I~
//U+A930..U+A95F    :Rejang:Rejang                                 //~v6V2I~
//U+A960..U+A97F    :Hangul Jamo Extended-A:Hangul                 //~v6V2I~
//U+A980..U+A9DF    :Javanese:Javanese (90 characters), Common (1 character)//~v6V2I~
//U+A9E0..U+A9FF    :Myanmar Extended-B:Myanmar                    //~v6V2I~
//U+AA00..U+AA5F    :Cham:Cham                                     //~v6V2I~
//U+AA60..U+AA7F    :Myanmar Extended-A:Myanmar                    //~v6V2I~
//U+AA80..U+AADF    :Tai Viet:Tai Viet                             //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+AAE0..U+AAFF    :Meetei Mayek Extensions:Meetei Mayek          //~v6V2I~
//U+AB00..U+AB2F    :Ethiopic Extended-A:Ethiopic                  //~v6V2I~
//U+AB30..U+AB6F    :Latin Extended-E:Latin (52 characters), Greek (1 character), Common (1 character)//~v6V2I~
//U+AB70..U+ABBF    :Cherokee Supplement:Cherokee                  //~v6V2I~
//U+ABC0..U+ABFF    :Meetei Mayek:Meetei Mayek                     //~v6V2I~
//U+AC00..U+D7AF    :Hangul Syllables:Hangul                       //~v6V2I~
//U+D7B0..U+D7FF    :Hangul Jamo Extended-B:Hangul                 //~v6V2I~
//U+D800..U+DB7F    :High Surrogates:Unknown                       //~v6V2I~
//U+DB80..U+DBFF    :High Private Use Surrogates:Unknown           //~v6V2I~
//U+DC00..U+DFFF    :Low Surrogates:Unknown                        //~v6V2I~
////0 BMP                                                          //~v6V2I~
//U+E000..U+F8FF    :Private Use Area:Unknown                      //~v6V2I~
//U+F900..U+FAFF    :CJK Compatibility Ideographs:Han              //~v6V2I~
//U+FB00..U+FB4F    :Alphabetic Presentation Forms:Armenian (5 characters), Hebrew (46 characters), Latin (7 characters)//~v6V2I~
//U+FB50..U+FDFF    :Arabic Presentation Forms-A:Arabic (609 characters), Common (2 characters)//~v6V2I~
//U+FE00..U+FE0F    :Variation Selectors:Inherited                 //~v6V2I~
//U+FE10..U+FE1F    :Vertical Forms:Common                         //~v6V2I~
//U+FE20..U+FE2F    :Combining Half Marks:Cyrillic (2 characters), Inherited (14 characters)//~v6V2I~
//U+FE30..U+FE4F    :CJK Compatibility Forms:Common                //~v6V2I~
//U+FE50..U+FE6F    :Small Form Variants:Common                    //~v6V2I~
//U+FE70..U+FEFF    :Arabic Presentation Forms-B:Arabic (140 characters), Common (1 character)//~v6V2I~
//U+FF00..U+FFEF    :Halfwidth and Fullwidth Forms:Hangul (52 characters), Katakana (55 characters), Latin (52 characters), Common (66 characters)//~v6V2I~
//U+FFF0..U+FFFF    :Specials:Common                               //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10000..U+1007F  :Linear B Syllabary:Linear B                   //~v6V2I~
//U+10080..U+100FF  :Linear B Ideograms:Linear B                   //~v6V2I~
//U+10100..U+1013F  :Aegean Numbers:Common                         //~v6V2I~
//U+10140..U+1018F  :Ancient Greek Numbers:Greek                   //~v6V2I~
//U+10190..U+101CF  :Ancient Symbols:Greek (1 character), Common (12 characters)//~v6V2I~
//U+101D0..U+101FF  :Phaistos Disc:Common (45 characters), Inherited (1 character)//~v6V2I~
//U+10280..U+1029F  :Lycian:Lycian                                 //~v6V2I~
//U+102A0..U+102DF  :Carian:Carian                                 //~v6V2I~
//U+102E0..U+102FF  :Coptic Epact Numbers:Common (27 characters), Inherited (1 character)//~v6V2I~
//U+10300..U+1032F  :Old Italic:Old Italic                         //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10330..U+1034F  :Gothic:Gothic                                 //~v6V2I~
//U+10350..U+1037F  :Old Permic:Old Permic                         //~v6V2I~
//U+10380..U+1039F  :Ugaritic:Ugaritic                             //~v6V2I~
//U+103A0..U+103DF  :Old Persian:Old Persian                       //~v6V2I~
//U+10400..U+1044F  :Deseret:Deseret                               //~v6V2I~
//U+10450..U+1047F  :Shavian:Shavian                               //~v6V2I~
//U+10480..U+104AF  :Osmanya:Osmanya                               //~v6V2I~
//U+104B0..U+104FF  :Osage:Osage                                   //~v6V2I~
//U+10500..U+1052F  :Elbasan:Elbasan                               //~v6V2I~
//U+10530..U+1056F  :Caucasian Albanian:Caucasian Albanian         //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10600..U+1077F  :Linear A:Linear A                             //~v6V2I~
//U+10800..U+1083F  :Cypriot Syllabary:Cypriot                     //~v6V2I~
//U+10840..U+1085F  :Imperial Aramaic:Imperial Aramaic             //~v6V2I~
//U+10860..U+1087F  :Palmyrene:Palmyrene                           //~v6V2I~
//U+10880..U+108AF  :Nabataean:Nabataean                           //~v6V2I~
//U+108E0..U+108FF  :Hatran:Hatran                                 //~v6V2I~
//U+10900..U+1091F  :Phoenician:Phoenician                         //~v6V2I~
//U+10920..U+1093F  :Lydian:Lydian                                 //~v6V2I~
//U+10980..U+1099F  :Meroitic Hieroglyphs:Meroitic Hieroglyphs     //~v6V2I~
//U+109A0..U+109FF  :Meroitic Cursive:Meroitic Cursive             //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10A00..U+10A5F  :Kharoshthi:Kharoshthi                         //~v6V2I~
//U+10A60..U+10A7F  :Old South Arabian:Old South Arabian           //~v6V2I~
//U+10A80..U+10A9F  :Old North Arabian:Old North Arabian           //~v6V2I~
//U+10AC0..U+10AFF  :Manichaean:Manichaean                         //~v6V2I~
//U+10B00..U+10B3F  :Avestan:Avestan                               //~v6V2I~
//U+10B40..U+10B5F  :Inscriptional Parthian:Inscriptional Parthian //~v6V2I~
//U+10B60..U+10B7F  :Inscriptional Pahlavi:Inscriptional Pahlavi   //~v6V2I~
//U+10B80..U+10BAF  :Psalter Pahlavi:Psalter Pahlavi               //~v6V2I~
//U+10C00..U+10C4F  :Old Turkic:Old Turkic                         //~v6V2I~
//U+10C80..U+10CFF  :Old Hungarian:Old Hungarian                   //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+10E60..U+10E7F  :Rumi Numeral Symbols:Arabic                   //~v6V2I~
//U+11000..U+1107F  :Brahmi:Brahmi                                 //~v6V2I~
//U+11080..U+110CF  :Kaithi:Kaithi                                 //~v6V2I~
//U+110D0..U+110FF  :Sora Sompeng:Sora Sompeng                     //~v6V2I~
//U+11100..U+1114F  :Chakma:Chakma                                 //~v6V2I~
//U+11150..U+1117F  :Mahajani:Mahajani                             //~v6V2I~
//U+11180..U+111DF  :Sharada:Sharada                               //~v6V2I~
//U+111E0..U+111FF  :Sinhala Archaic Numbers:Sinhala               //~v6V2I~
//U+11200..U+1124F  :Khojki:Khojki                                 //~v6V2I~
//U+11280..U+112AF  :Multani:Multani                               //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+112B0..U+112FF  :Khudawadi:Khudawadi                           //~v6V2I~
//U+11300..U+1137F  :Grantha:Grantha                               //~v6V2I~
//U+11400..U+1147F  :Newa:Newa                                     //~v6V2I~
//U+11480..U+114DF  :Tirhuta:Tirhuta                               //~v6V2I~
//U+11580..U+115FF  :Siddham:Siddham                               //~v6V2I~
//U+11600..U+1165F  :Modi:Modi                                     //~v6V2I~
//U+11660..U+1167F  :Mongolian Supplement:Mongolian                //~v6V2I~
//U+11680..U+116CF  :Takri:Takri                                   //~v6V2I~
//U+11700..U+1173F  :Ahom:Ahom                                     //~v6V2I~
//U+118A0..U+118FF  :Warang Citi:Warang Citi                       //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+11A00..U+11A4F  :Zanabazar Square:Zanabazar Square             //~v6V2I~
//U+11A50..U+11AAF  :Soyombo:Soyombo                               //~v6V2I~
//U+11AC0..U+11AFF  :Pau Cin Hau:Pau Cin Hau                       //~v6V2I~
//U+11C00..U+11C6F  :Bhaiksuki:Bhaiksuki                           //~v6V2I~
//U+11C70..U+11CBF  :Marchen:Marchen                               //~v6V2I~
//U+11D00..U+11D5F  :Masaram Gondi:Masaram Gondi                   //~v6V2I~
//U+12000..U+123FF  :Cuneiform:Cuneiform                           //~v6V2I~
//U+12400..U+1247F  :Cuneiform Numbers and Punctuation:Cuneiform   //~v6V2I~
//U+12480..U+1254F  :Early Dynastic Cuneiform:Cuneiform            //~v6V2I~
//U+13000..U+1342F  :Egyptian Hieroglyphs:Egyptian Hieroglyphs     //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+14400..U+1467F  :Anatolian Hieroglyphs:Anatolian Hieroglyphs   //~v6V2I~
//U+16800..U+16A3F  :Bamum Supplement:Bamum                        //~v6V2I~
//U+16A40..U+16A6F  :Mro:Mro                                       //~v6V2I~
//U+16AD0..U+16AFF  :Bassa Vah:Bassa Vah                           //~v6V2I~
//U+16B00..U+16B8F  :Pahawh Hmong:Pahawh Hmong                     //~v6V2I~
//U+16F00..U+16F9F  :Miao:Miao                                     //~v6V2I~
//U+16FE0..U+16FFF  :Ideographic Symbols and Punctuation:Nushu (1 character), Tangut (1 character)//~v6V2I~
//U+17000..U+187FF  :Tangut:Tangut                                 //~v6V2I~
//U+18800..U+18AFF  :Tangut Components:Tangut                      //~v6V2I~
//U+1B000..U+1B0FF  :Kana Supplement:Hiragana (255 characters), Katakana (1 character)//~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+1B100..U+1B12F  :Kana Extended-A:Hiragana                      //~v6V2I~
//U+1B170..U+1B2FF  :Nushu:N端shu                                   //~v6V2I~
//U+1BC00..U+1BC9F  :Duployan:Duployan                             //~v6V2I~
//U+1BCA0..U+1BCAF  :Shorthand Format Controls:Common              //~v6V2I~
//U+1D000..U+1D0FF  :Byzantine Musical Symbols:Common              //~v6V2I~
//U+1D100..U+1D1FF  :Musical Symbols:Common (209 characters), Inherited (22 characters)//~v6V2I~
//U+1D200..U+1D24F  :Ancient Greek Musical Notation:Greek          //~v6V2I~
//U+1D300..U+1D35F  :Tai Xuan Jing Symbols:Common                  //~v6V2I~
//U+1D360..U+1D37F  :Counting Rod Numerals:Common                  //~v6V2I~
//U+1D400..U+1D7FF  :Mathematical Alphanumeric Symbols:Common      //~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+1D800..U+1DAAF  :Sutton SignWriting:SignWriting                //~v6V2I~
//U+1E000..U+1E02F  :Glagolitic Supplement:Glagolitic              //~v6V2I~
//U+1E800..U+1E8DF  :Mende Kikakui:Mende Kikakui                   //~v6V2I~
//U+1E900..U+1E95F  :Adlam:Adlam                                   //~v6V2I~
//U+1EE00..U+1EEFF  :Arabic Mathematical Alphabetic Symbols:Arabic //~v6V2I~
//U+1F000..U+1F02F  :Mahjong Tiles:Common                          //~v6V2I~
//U+1F030..U+1F09F  :Domino Tiles:Common                           //~v6V2I~
//U+1F0A0..U+1F0FF  :Playing Cards:Common                          //~v6V2I~
//U+1F100..U+1F1FF  :Enclosed Alphanumeric Supplement:Common       //~v6V2I~
//U+1F200..U+1F2FF  :Enclosed Ideographic Supplement:Hiragana (1 character), Common (63 characters)//~v6V2I~
////1 SMP                                                          //~v6V2I~
//U+1F300..U+1F5FF  :Miscellaneous Symbols and Pictographs:Common  //~v6V2I~
//U+1F600..U+1F64F  :Emoticons:Common                              //~v6V2I~
//U+1F650..U+1F67F  :Ornamental Dingbats:Common                    //~v6V2I~
//U+1F680..U+1F6FF  :Transport and Map Symbols:Common              //~v6V2I~
//U+1F700..U+1F77F  :Alchemical Symbols:Common                     //~v6V2I~
//U+1F780..U+1F7FF  :Geometric Shapes Extended:Common              //~v6V2I~
//U+1F800..U+1F8FF  :Supplemental Arrows-C:Common                  //~v6V2I~
//U+1F900..U+1F9FF  :Supplemental Symbols and Pictographs:Common   //~v6V2I~
//2 SIP                                                            //~v6V2I~
//U+20000..U+2A6DF  :CJK Unified Ideographs Extension B:Han        //~v6V2I~
//U+2A700..U+2B73F  :CJK Unified Ideographs Extension C:Han        //~v6V2I~
//U+2B740..U+2B81F  :CJK Unified Ideographs Extension D:Han        //~v6V2I~
//U+2B820..U+2CEAF  :CJK Unified Ideographs Extension E:Han        //~v6V2I~
//U+2CEB0..U+2EBEF  :CJK Unified Ideographs Extension F:Han        //~v6V2I~
//U+2F800..U+2FA1F  :CJK Compatibility Ideographs Supplement:Han   //~v6V2I~
////14 SSP                                                         //~v6V2I~
//U+E0000..U+E007F  :Tags:Common                                   //~v6V2I~
//U+E0100..U+E01EF  :Variation Selectors Supplement:Inherited      //~v6V2I~
////15 PUA-A                                                       //~v6V2I~
//U+F0000..U+FFFFF  :Supplementary Private Use Area-A:Unknown      //~v6V2I~
////16 PUA-B                                                       //~v6V2I~
//U+100000..U+10FFFF:Supplementary Private Use Area-B:Unknown      //~v6V2I~
//******************************************************           //~v6VbI~
//chk Spacing Combining Mark(glphctr=2 if not combined) for XXE    //~v6VbR~
//rc:1:SCM, 2:combining(width=0) but trateas SCM by option         //~v6X0I~
//******************************************************           //~v6VbI~
int utf4_isSpacingCombiningMark(int Popt,UWUCS Pucs)               //~v6VbI~
{                                                                  //~v6VbI~
// 2018/06/12                                                      //~v6VbI~
// https://www.fileformat.info/info/unicode/category/Mc/list.htm   //~v6VbI~
// You are in Browse directory FileFormat.Info  Browse directory Info  Browse directory Unicode  Browse directory Categories  Browse directory Mark, Spacing Combining//~v6VbI~
//     Unicode Characters in the 'Mark, Spacing Combining' Category//~v6VbI~
    static const struct interval Suctb_SCM[] = {                   //~v6VbI~
//         Character   Name                                        //~v6VbI~
     {0x0903  ,0x0903  }, //U+0903  DEVANAGARI SIGN VISARGA        //~v6VbI~
     {0x093B  ,0x093B  }, //U+093B  DEVANAGARI VOWEL SIGN OOE      //~v6VbI~
//     {0x093E  ,0x093E  }, //U+093E  DEVANAGARI VOWEL SIGN AA     //~v6VbI~
//     {0x093F  ,0x093F  }, //U+093F  DEVANAGARI VOWEL SIGN I      //~v6VbI~
     {0x093E  ,0x093f  },                                          //~v6VbI~
     {0x0940  ,0x0940  }, //U+0940  DEVANAGARI VOWEL SIGN II       //~v6VbI~
//     {0x0949  ,0x0949  }, //U+0949  DEVANAGARI VOWEL SIGN CANDRA O//~v6VbI~
//     {0x094A  ,0x094A  }, //U+094A  DEVANAGARI VOWEL SIGN SHORT O//~v6VbI~
//     {0x094B  ,0x094B  }, //U+094B  DEVANAGARI VOWEL SIGN O      //~v6VbI~
//     {0x094C  ,0x094C  }, //U+094C  DEVANAGARI VOWEL SIGN AU     //~v6VbI~
     {0x0949  ,0x094c  },                                          //~v6VbI~
//     {0x094E  ,0x094E  }, //U+094E  DEVANAGARI VOWEL SIGN PRISHTHAMATRA E//~v6VbI~
//     {0x094F  ,0x094F  }, //U+094F  DEVANAGARI VOWEL SIGN AW     //~v6VbI~
     {0x094E  ,0x094f  },                                          //~v6VbI~
//     {0x0982  ,0x0982  }, //U+0982  BENGALI SIGN ANUSVARA        //~v6VbI~
//     {0x0983  ,0x0983  }, //U+0983  BENGALI SIGN VISARGA         //~v6VbI~
     {0x0982  ,0x0983  },                                          //~v6VbI~
//     {0x09BE  ,0x09BE  }, //U+09BE  BENGALI VOWEL SIGN AA        //~v6VbI~
//     {0x09BF  ,0x09BF  }, //U+09BF  BENGALI VOWEL SIGN I         //~v6VbI~
     {0x09BE  ,0x09Bf  },                                          //~v6VbI~
     {0x09C0  ,0x09C0  }, //U+09C0  BENGALI VOWEL SIGN II          //~v6VbI~
//     {0x09C7  ,0x09C7  }, //U+09C7  BENGALI VOWEL SIGN E         //~v6VbI~
//     {0x09C8  ,0x09C8  }, //U+09C8  BENGALI VOWEL SIGN AI        //~v6VbI~
     {0x09C7  ,0x09C8  },                                          //~v6VbI~
//     {0x09CB  ,0x09CB  }, //U+09CB  BENGALI VOWEL SIGN O         //~v6VbI~
//     {0x09CC  ,0x09CC  }, //U+09CC  BENGALI VOWEL SIGN AU        //~v6VbI~
     {0x09CB  ,0x09Cc  },                                          //~v6VbI~
     {0x09D7  ,0x09D7  }, //U+09D7  BENGALI AU LENGTH MARK         //~v6VbI~
     {0x0A03  ,0x0A03  }, //U+0A03  GURMUKHI SIGN VISARGA          //~v6VbI~
//     {0x0A3E  ,0x0A3E  }, //U+0A3E  GURMUKHI VOWEL SIGN AA       //~v6VbI~
//     {0x0A3F  ,0x0A3F  }, //U+0A3F  GURMUKHI VOWEL SIGN I        //~v6VbI~
     {0x0A3E  ,0x0A3f  },                                          //~v6VbI~
     {0x0A40  ,0x0A40  }, //U+0A40  GURMUKHI VOWEL SIGN II         //~v6VbI~
     {0x0A83  ,0x0A83  }, //U+0A83  GUJARATI SIGN VISARGA          //~v6VbI~
//     {0x0ABE  ,0x0ABE  }, //U+0ABE  GUJARATI VOWEL SIGN AA       //~v6VbI~
//     {0x0ABF  ,0x0ABF  }, //U+0ABF  GUJARATI VOWEL SIGN I        //~v6VbI~
     {0x0ABE  ,0x0ABf  },                                          //~v6VbI~
     {0x0AC0  ,0x0AC0  }, //U+0AC0  GUJARATI VOWEL SIGN II         //~v6VbI~
     {0x0AC9  ,0x0AC9  }, //U+0AC9  GUJARATI VOWEL SIGN CANDRA O   //~v6VbI~
//     {0x0ACB  ,0x0ACB  }, //U+0ACB  GUJARATI VOWEL SIGN O        //~v6VbI~
//     {0x0ACC  ,0x0ACC  }, //U+0ACC  GUJARATI VOWEL SIGN AU       //~v6VbI~
     {0x0ACB  ,0x0ACc  },                                          //~v6VbI~
//     {0x0B02  ,0x0B02  }, //U+0B02  ORIYA SIGN ANUSVARA          //~v6VbI~
//     {0x0B03  ,0x0B03  }, //U+0B03  ORIYA SIGN VISARGA           //~v6VbI~
     {0x0B02  ,0x0B03  },                                          //~v6VbI~
     {0x0B3E  ,0x0B3E  }, //U+0B3E  ORIYA VOWEL SIGN AA            //~v6VbI~
     {0x0B40  ,0x0B40  }, //U+0B40  ORIYA VOWEL SIGN II            //~v6VbI~
//     {0x0B47  ,0x0B47  }, //U+0B47  ORIYA VOWEL SIGN E           //~v6VbI~
//     {0x0B48  ,0x0B48  }, //U+0B48  ORIYA VOWEL SIGN AI          //~v6VbI~
     {0x0B47  ,0x0B48  },                                          //~v6VbI~
//     {0x0B4B  ,0x0B4B  }, //U+0B4B  ORIYA VOWEL SIGN O           //~v6VbI~
//     {0x0B4C  ,0x0B4C  }, //U+0B4C  ORIYA VOWEL SIGN AU          //~v6VbI~
     {0x0B4B  ,0x0B4c  },                                          //~v6VbI~
     {0x0B57  ,0x0B57  }, //U+0B57  ORIYA AU LENGTH MARK           //~v6VbI~
//     {0x0BBE  ,0x0BBE  }, //U+0BBE  TAMIL VOWEL SIGN AA          //~v6VbI~
//     {0x0BBF  ,0x0BBF  }, //U+0BBF  TAMIL VOWEL SIGN I           //~v6VbI~
     {0x0BBE  ,0x0BBf  },                                          //~v6VbI~
//     {0x0BC1  ,0x0BC1  }, //U+0BC1  TAMIL VOWEL SIGN U           //~v6VbI~
//     {0x0BC2  ,0x0BC2  }, //U+0BC2  TAMIL VOWEL SIGN UU          //~v6VbI~
     {0x0BC1  ,0x0BC2  },                                          //~v6VbI~
//     {0x0BC6  ,0x0BC6  }, //U+0BC6  TAMIL VOWEL SIGN E           //~v6VbI~
//     {0x0BC7  ,0x0BC7  }, //U+0BC7  TAMIL VOWEL SIGN EE          //~v6VbI~
//     {0x0BC8  ,0x0BC8  }, //U+0BC8  TAMIL VOWEL SIGN AI          //~v6VbI~
     {0x0BC6  ,0x0BC8  },                                          //~v6VbI~
//     {0x0BCA  ,0x0BCA  }, //U+0BCA  TAMIL VOWEL SIGN O           //~v6VbI~
//     {0x0BCB  ,0x0BCB  }, //U+0BCB  TAMIL VOWEL SIGN OO          //~v6VbI~
//     {0x0BCC  ,0x0BCC  }, //U+0BCC  TAMIL VOWEL SIGN AU          //~v6VbI~
     {0x0BCA  ,0x0BCc  },                                          //~v6VbI~
     {0x0BD7  ,0x0BD7  }, //U+0BD7  TAMIL AU LENGTH MARK           //~v6VbI~
//     {0x0C01  ,0x0C01  }, //U+0C01  TELUGU SIGN CANDRABINDU      //~v6VbI~
//     {0x0C02  ,0x0C02  }, //U+0C02  TELUGU SIGN ANUSVARA         //~v6VbI~
//     {0x0C03  ,0x0C03  }, //U+0C03  TELUGU SIGN VISARGA          //~v6VbI~
     {0x0C01  ,0x0C03  },                                          //~v6VbI~
//     {0x0C41  ,0x0C41  }, //U+0C41  TELUGU VOWEL SIGN U          //~v6VbI~
//     {0x0C42  ,0x0C42  }, //U+0C42  TELUGU VOWEL SIGN UU         //~v6VbI~
//     {0x0C43  ,0x0C43  }, //U+0C43  TELUGU VOWEL SIGN VOCALIC R  //~v6VbI~
//     {0x0C44  ,0x0C44  }, //U+0C44  TELUGU VOWEL SIGN VOCALIC RR //~v6VbI~
     {0x0C41  ,0x0C44  },                                          //~v6VbI~
//     {0x0C82  ,0x0C82  }, //U+0C82  KANNADA SIGN ANUSVARA        //~v6VbI~
//     {0x0C83  ,0x0C83  }, //U+0C83  KANNADA SIGN VISARGA         //~v6VbI~
     {0x0C82  ,0x0C83  },                                          //~v6VbI~
     {0x0CBE  ,0x0CBE  }, //U+0CBE  KANNADA VOWEL SIGN AA          //~v6VbI~
//     {0x0CC0  ,0x0CC0  }, //U+0CC0  KANNADA VOWEL SIGN II        //~v6VbI~
//     {0x0CC1  ,0x0CC1  }, //U+0CC1  KANNADA VOWEL SIGN U         //~v6VbI~
//     {0x0CC2  ,0x0CC2  }, //U+0CC2  KANNADA VOWEL SIGN UU        //~v6VbI~
//     {0x0CC3  ,0x0CC3  }, //U+0CC3  KANNADA VOWEL SIGN VOCALIC R //~v6VbI~
//     {0x0CC4  ,0x0CC4  }, //U+0CC4  KANNADA VOWEL SIGN VOCALIC RR//~v6VbI~
     {0x0CC0  ,0x0CC4  },                                          //~v6VbI~
//     {0x0CC7  ,0x0CC7  }, //U+0CC7  KANNADA VOWEL SIGN EE        //~v6VbI~
//     {0x0CC8  ,0x0CC8  }, //U+0CC8  KANNADA VOWEL SIGN AI        //~v6VbI~
     {0x0CC7  ,0x0CC8  },                                          //~v6VbI~
//     {0x0CCA  ,0x0CCA  }, //U+0CCA  KANNADA VOWEL SIGN O         //~v6VbI~
//     {0x0CCB  ,0x0CCB  }, //U+0CCB  KANNADA VOWEL SIGN OO        //~v6VbI~
     {0x0CCA  ,0x0CCb  },                                          //~v6VbI~
//     {0x0CD5  ,0x0CD5  }, //U+0CD5  KANNADA LENGTH MARK          //~v6VbI~
//     {0x0CD6  ,0x0CD6  }, //U+0CD6  KANNADA AI LENGTH MARK       //~v6VbI~
     {0x0CD5  ,0x0CD6  },                                          //~v6VbI~
//     {0x0D02  ,0x0D02  }, //U+0D02  MALAYALAM SIGN ANUSVARA      //~v6VbI~
//     {0x0D03  ,0x0D03  }, //U+0D03  MALAYALAM SIGN VISARGA       //~v6VbI~
     {0x0D02  ,0x0D03  },                                          //~v6VbI~
//     {0x0D3E  ,0x0D3E  }, //U+0D3E  MALAYALAM VOWEL SIGN AA      //~v6VbI~
//     {0x0D3F  ,0x0D3F  }, //U+0D3F  MALAYALAM VOWEL SIGN I       //~v6VbI~
//     {0x0D40  ,0x0D40  }, //U+0D40  MALAYALAM VOWEL SIGN II      //~v6VbI~
     {0x0D3E  ,0x0D40  },                                          //~v6VbI~
//     {0x0D46  ,0x0D46  }, //U+0D46  MALAYALAM VOWEL SIGN E       //~v6VbI~
//     {0x0D47  ,0x0D47  }, //U+0D47  MALAYALAM VOWEL SIGN EE      //~v6VbI~
//     {0x0D48  ,0x0D48  }, //U+0D48  MALAYALAM VOWEL SIGN AI      //~v6VbI~
     {0x0D46  ,0x0D48  },                                          //~v6VbI~
//     {0x0D4A  ,0x0D4A  }, //U+0D4A  MALAYALAM VOWEL SIGN O       //~v6VbI~
//     {0x0D4B  ,0x0D4B  }, //U+0D4B  MALAYALAM VOWEL SIGN OO      //~v6VbI~
//     {0x0D4C  ,0x0D4C  }, //U+0D4C  MALAYALAM VOWEL SIGN AU      //~v6VbI~
     {0x0D4A  ,0x0D4c  },                                          //~v6VbI~
     {0x0D57  ,0x0D57  }, //U+0D57  MALAYALAM AU LENGTH MARK       //~v6VbI~
//     {0x0D82  ,0x0D82  }, //U+0D82  SINHALA SIGN ANUSVARAYA      //~v6VbI~
//     {0x0D83  ,0x0D83  }, //U+0D83  SINHALA SIGN VISARGAYA       //~v6VbI~
     {0x0D82  ,0x0D83  },                                          //~v6VbI~
//     {0x0DCF  ,0x0DCF  }, //U+0DCF  SINHALA VOWEL SIGN AELA-PILLA//~v6VbI~
//     {0x0DD0  ,0x0DD0  }, //U+0DD0  SINHALA VOWEL SIGN KETTI AEDA-PILLA//~v6VbI~
//     {0x0DD1  ,0x0DD1  }, //U+0DD1  SINHALA VOWEL SIGN DIGA AEDA-PILLA//~v6VbI~
     {0x0DCF  ,0x0Dd1  },                                          //~v6VbI~
//     {0x0DD8  ,0x0DD8  }, //U+0DD8  SINHALA VOWEL SIGN GAETTA-PILLA//~v6VbI~
//     {0x0DD9  ,0x0DD9  }, //U+0DD9  SINHALA VOWEL SIGN KOMBUVA   //~v6VbI~
//     {0x0DDA  ,0x0DDA  }, //U+0DDA  SINHALA VOWEL SIGN DIGA KOMBUVA//~v6VbI~
//     {0x0DDB  ,0x0DDB  }, //U+0DDB  SINHALA VOWEL SIGN KOMBU DEKA//~v6VbI~
//     {0x0DDC  ,0x0DDC  }, //U+0DDC  SINHALA VOWEL SIGN KOMBUVA HAA AELA-PILLA//~v6VbI~
//     {0x0DDD  ,0x0DDD  }, //U+0DDD  SINHALA VOWEL SIGN KOMBUVA HAA DIGA AELA-PILLA//~v6VbI~
//     {0x0DDE  ,0x0DDE  }, //U+0DDE  SINHALA VOWEL SIGN KOMBUVA HAA GAYANUKITTA//~v6VbI~
//     {0x0DDF  ,0x0DDF  }, //U+0DDF  SINHALA VOWEL SIGN GAYANUKITTA//~v6VbI~
     {0x0DD8  ,0x0DDf  },                                          //~v6VbI~
//     {0x0DF2  ,0x0DF2  }, //U+0DF2  SINHALA VOWEL SIGN DIGA GAETTA-PILLA//~v6VbI~
//     {0x0DF3  ,0x0DF3  }, //U+0DF3  SINHALA VOWEL SIGN DIGA GAYANUKITTA//~v6VbI~
     {0x0DF2  ,0x0DF3  },                                          //~v6VbI~
//     {0x0F3E  ,0x0F3E  }, //U+0F3E  TIBETAN SIGN YAR TSHES       //~v6VbI~
//     {0x0F3F  ,0x0F3F  }, //U+0F3F  TIBETAN SIGN MAR TSHES       //~v6VbI~
     {0x0F3E  ,0x0F3f  },                                          //~v6VbI~
     {0x0F7F  ,0x0F7F  }, //U+0F7F  TIBETAN SIGN RNAM BCAD         //~v6VbI~
//     {0x102B  ,0x102B  }, //U+102B  MYANMAR VOWEL SIGN TALL AA   //~v6VbI~
//     {0x102C  ,0x102C  }, //U+102C  MYANMAR VOWEL SIGN AA        //~v6VbI~
     {0x102B  ,0x102c  },                                          //~v6VbI~
     {0x1031  ,0x1031  }, //U+1031  MYANMAR VOWEL SIGN E           //~v6VbI~
     {0x1038  ,0x1038  }, //U+1038  MYANMAR SIGN VISARGA           //~v6VbI~
//     {0x103B  ,0x103B  }, //U+103B  MYANMAR CONSONANT SIGN MEDIAL YA//~v6VbI~
//     {0x103C  ,0x103C  }, //U+103C  MYANMAR CONSONANT SIGN MEDIAL RA//~v6VbI~
     {0x103B  ,0x103c  },                                          //~v6VbI~
//     {0x1056  ,0x1056  }, //U+1056  MYANMAR VOWEL SIGN VOCALIC R //~v6VbI~
//     {0x1057  ,0x1057  }, //U+1057  MYANMAR VOWEL SIGN VOCALIC RR//~v6VbI~
     {0x1056  ,0x1057  },                                          //~v6VbI~
//     {0x1062  ,0x1062  }, //U+1062  MYANMAR VOWEL SIGN SGAW KAREN EU//~v6VbI~
//     {0x1063  ,0x1063  }, //U+1063  MYANMAR TONE MARK SGAW KAREN HATHI//~v6VbI~
//     {0x1064  ,0x1064  }, //U+1064  MYANMAR TONE MARK SGAW KAREN KE PHO//~v6VbI~
     {0x1062  ,0x1064  },                                          //~v6VbI~
//     {0x1067  ,0x1067  }, //U+1067  MYANMAR VOWEL SIGN WESTERN PWO KAREN EU//~v6VbI~
//     {0x1068  ,0x1068  }, //U+1068  MYANMAR VOWEL SIGN WESTERN PWO KAREN UE//~v6VbI~
//     {0x1069  ,0x1069  }, //U+1069  MYANMAR SIGN WESTERN PWO KAREN TONE-1//~v6VbI~
//     {0x106A  ,0x106A  }, //U+106A  MYANMAR SIGN WESTERN PWO KAREN TONE-2//~v6VbI~
//     {0x106B  ,0x106B  }, //U+106B  MYANMAR SIGN WESTERN PWO KAREN TONE-3//~v6VbI~
//     {0x106C  ,0x106C  }, //U+106C  MYANMAR SIGN WESTERN PWO KAREN TONE-4//~v6VbI~
//     {0x106D  ,0x106D  }, //U+106D  MYANMAR SIGN WESTERN PWO KAREN TONE-5//~v6VbI~
     {0x1067  ,0x106d  },                                          //~v6VbI~
//     {0x1083  ,0x1083  }, //U+1083  MYANMAR VOWEL SIGN SHAN AA   //~v6VbI~
//     {0x1084  ,0x1084  }, //U+1084  MYANMAR VOWEL SIGN SHAN E    //~v6VbI~
     {0x1083  ,0x1084  },                                          //~v6VbI~
//     {0x1087  ,0x1087  }, //U+1087  MYANMAR SIGN SHAN TONE-2     //~v6VbI~
//     {0x1088  ,0x1088  }, //U+1088  MYANMAR SIGN SHAN TONE-3     //~v6VbI~
//     {0x1089  ,0x1089  }, //U+1089  MYANMAR SIGN SHAN TONE-5     //~v6VbI~
//     {0x108A  ,0x108A  }, //U+108A  MYANMAR SIGN SHAN TONE-6     //~v6VbI~
//     {0x108B  ,0x108B  }, //U+108B  MYANMAR SIGN SHAN COUNCIL TONE-2//~v6VbI~
//     {0x108C  ,0x108C  }, //U+108C  MYANMAR SIGN SHAN COUNCIL TONE-3//~v6VbI~
     {0x1087  ,0x108c  },                                          //~v6VbI~
     {0x108F  ,0x108F  }, //U+108F  MYANMAR SIGN RUMAI PALAUNG TONE-5//~v6VbI~
//     {0x109A  ,0x109A  }, //U+109A  MYANMAR SIGN KHAMTI TONE-1   //~v6VbI~
//     {0x109B  ,0x109B  }, //U+109B  MYANMAR SIGN KHAMTI TONE-3   //~v6VbI~
//     {0x109C  ,0x109C  }, //U+109C  MYANMAR VOWEL SIGN AITON A   //~v6VbI~
       {0x109A  ,0x109c  },                                        //~v6VbI~
     {0x17B6  ,0x17B6  }, //U+17B6  KHMER VOWEL SIGN AA            //~v6VbI~
//     {0x17BE  ,0x17BE  }, //U+17BE  KHMER VOWEL SIGN OE          //~v6VbI~
//     {0x17BF  ,0x17BF  }, //U+17BF  KHMER VOWEL SIGN YA          //~v6VbI~
//     {0x17C0  ,0x17C0  }, //U+17C0  KHMER VOWEL SIGN IE          //~v6VbI~
//     {0x17C1  ,0x17C1  }, //U+17C1  KHMER VOWEL SIGN E           //~v6VbI~
//     {0x17C2  ,0x17C2  }, //U+17C2  KHMER VOWEL SIGN AE          //~v6VbI~
//     {0x17C3  ,0x17C3  }, //U+17C3  KHMER VOWEL SIGN AI          //~v6VbI~
//     {0x17C4  ,0x17C4  }, //U+17C4  KHMER VOWEL SIGN OO          //~v6VbI~
//     {0x17C5  ,0x17C5  }, //U+17C5  KHMER VOWEL SIGN AU          //~v6VbI~
     {0x17BE  ,0x17c5  },                                          //~v6VbI~
//     {0x17C7  ,0x17C7  }, //U+17C7  KHMER SIGN REAHMUK           //~v6VbI~
//     {0x17C8  ,0x17C8  }, //U+17C8  KHMER SIGN YUUKALEAPINTU     //~v6VbI~
     {0x17C7  ,0x17C8  },                                          //~v6VbI~
//     {0x1923  ,0x1923  }, //U+1923  LIMBU VOWEL SIGN EE          //~v6VbI~
//     {0x1924  ,0x1924  }, //U+1924  LIMBU VOWEL SIGN AI          //~v6VbI~
//     {0x1925  ,0x1925  }, //U+1925  LIMBU VOWEL SIGN OO          //~v6VbI~
//     {0x1926  ,0x1926  }, //U+1926  LIMBU VOWEL SIGN AU          //~v6VbI~
     {0x1923  ,0x1926  },                                          //~v6VbI~
//     {0x1929  ,0x1929  }, //U+1929  LIMBU SUBJOINED LETTER YA    //~v6VbI~
//     {0x192A  ,0x192A  }, //U+192A  LIMBU SUBJOINED LETTER RA    //~v6VbI~
//     {0x192B  ,0x192B  }, //U+192B  LIMBU SUBJOINED LETTER WA    //~v6VbI~
     {0x1929  ,0x192b  },                                          //~v6VbI~
//     {0x1930  ,0x1930  }, //U+1930  LIMBU SMALL LETTER KA        //~v6VbI~
//     {0x1931  ,0x1931  }, //U+1931  LIMBU SMALL LETTER NGA       //~v6VbI~
     {0x1930  ,0x1931  },                                          //~v6VbI~
//     {0x1933  ,0x1933  }, //U+1933  LIMBU SMALL LETTER TA        //~v6VbI~
//     {0x1934  ,0x1934  }, //U+1934  LIMBU SMALL LETTER NA        //~v6VbI~
//     {0x1935  ,0x1935  }, //U+1935  LIMBU SMALL LETTER PA        //~v6VbI~
//     {0x1936  ,0x1936  }, //U+1936  LIMBU SMALL LETTER MA        //~v6VbI~
//     {0x1937  ,0x1937  }, //U+1937  LIMBU SMALL LETTER RA        //~v6VbI~
//     {0x1938  ,0x1938  }, //U+1938  LIMBU SMALL LETTER LA        //~v6VbI~
       {0x1933  ,0x1938  },                                        //~v6VbI~
//     {0x1A19  ,0x1A19  }, //U+1A19  BUGINESE VOWEL SIGN E        //~v6VbI~
//     {0x1A1A  ,0x1A1A  }, //U+1A1A  BUGINESE VOWEL SIGN O        //~v6VbI~
     {0x1A19  ,0x1A1a  },                                          //~v6VbI~
     {0x1A55  ,0x1A55  }, //U+1A55  TAI THAM CONSONANT SIGN MEDIAL RA//~v6VbI~
     {0x1A57  ,0x1A57  }, //U+1A57  TAI THAM CONSONANT SIGN LA TANG LAI//~v6VbI~
     {0x1A61  ,0x1A61  }, //U+1A61  TAI THAM VOWEL SIGN A          //~v6VbI~
//     {0x1A63  ,0x1A63  }, //U+1A63  TAI THAM VOWEL SIGN AA       //~v6VbI~
//     {0x1A64  ,0x1A64  }, //U+1A64  TAI THAM VOWEL SIGN TALL AA  //~v6VbI~
     {0x1A63  ,0x1A64  },                                          //~v6VbI~
//     {0x1A6D  ,0x1A6D  }, //U+1A6D  TAI THAM VOWEL SIGN OY       //~v6VbI~
//     {0x1A6E  ,0x1A6E  }, //U+1A6E  TAI THAM VOWEL SIGN E        //~v6VbI~
//     {0x1A6F  ,0x1A6F  }, //U+1A6F  TAI THAM VOWEL SIGN AE       //~v6VbI~
//     {0x1A70  ,0x1A70  }, //U+1A70  TAI THAM VOWEL SIGN OO       //~v6VbI~
//     {0x1A71  ,0x1A71  }, //U+1A71  TAI THAM VOWEL SIGN AI       //~v6VbI~
//     {0x1A72  ,0x1A72  }, //U+1A72  TAI THAM VOWEL SIGN THAM AI  //~v6VbI~
     {0x1A6D  ,0x1A72  }, //U+1A6E  TAI THAM VOWEL SIGN E          //~v6VbI~
     {0x1B04  ,0x1B04  }, //U+1B04  BALINESE SIGN BISAH            //~v6VbI~
     {0x1B35  ,0x1B35  }, //U+1B35  BALINESE VOWEL SIGN TEDUNG     //~v6VbI~
     {0x1B3B  ,0x1B3B  }, //U+1B3B  BALINESE VOWEL SIGN RA REPA TEDUNG//~v6VbI~
//     {0x1B3D  ,0x1B3D  }, //U+1B3D  BALINESE VOWEL SIGN LA LENGA TEDUNG//~v6VbI~
//     {0x1B3E  ,0x1B3E  }, //U+1B3E  BALINESE VOWEL SIGN TALING   //~v6VbI~
//     {0x1B3F  ,0x1B3F  }, //U+1B3F  BALINESE VOWEL SIGN TALING REPA//~v6VbI~
//     {0x1B40  ,0x1B40  }, //U+1B40  BALINESE VOWEL SIGN TALING TEDUNG//~v6VbI~
//     {0x1B41  ,0x1B41  }, //U+1B41  BALINESE VOWEL SIGN TALING REPA TEDUNG//~v6VbI~
     {0x1B3D  ,0x1B41  },                                          //~v6VbI~
//     {0x1B43  ,0x1B43  }, //U+1B43  BALINESE VOWEL SIGN PEPET TEDUNG//~v6VbI~
//     {0x1B44  ,0x1B44  }, //U+1B44  BALINESE ADEG ADEG           //~v6VbI~
       {0x1B43  ,0x1B44  },                                        //~v6VbI~
     {0x1B82  ,0x1B82  }, //U+1B82  SUNDANESE SIGN PANGWISAD       //~v6VbI~
     {0x1BA1  ,0x1BA1  }, //U+1BA1  SUNDANESE CONSONANT SIGN PAMINGKAL//~v6VbI~
//     {0x1BA6  ,0x1BA6  }, //U+1BA6  SUNDANESE VOWEL SIGN PANAELAENG//~v6VbI~
//     {0x1BA7  ,0x1BA7  }, //U+1BA7  SUNDANESE VOWEL SIGN PANOLONG//~v6VbI~
     {0x1BA6  ,0x1BA7  },                                          //~v6VbI~
     {0x1BAA  ,0x1BAA  }, //U+1BAA  SUNDANESE SIGN PAMAAEH         //~v6VbI~
     {0x1BE7  ,0x1BE7  }, //U+1BE7  BATAK VOWEL SIGN E             //~v6VbI~
//     {0x1BEA  ,0x1BEA  }, //U+1BEA  BATAK VOWEL SIGN I           //~v6VbI~
//     {0x1BEB  ,0x1BEB  }, //U+1BEB  BATAK VOWEL SIGN KARO I      //~v6VbI~
//     {0x1BEC  ,0x1BEC  }, //U+1BEC  BATAK VOWEL SIGN O           //~v6VbI~
     {0x1BEA  ,0x1BEc  },                                          //~v6VbI~
     {0x1BEE  ,0x1BEE  }, //U+1BEE  BATAK VOWEL SIGN U             //~v6VbI~
//     {0x1BF2  ,0x1BF2  }, //U+1BF2  BATAK PANGOLAT               //~v6VbI~
//     {0x1BF3  ,0x1BF3  }, //U+1BF3  BATAK PANONGONAN             //~v6VbI~
     {0x1BF2  ,0x1BF3  },                                          //~v6VbI~
//     {0x1C24  ,0x1C24  }, //U+1C24  LEPCHA SUBJOINED LETTER YA   //~v6VbI~
//     {0x1C25  ,0x1C25  }, //U+1C25  LEPCHA SUBJOINED LETTER RA   //~v6VbI~
//     {0x1C26  ,0x1C26  }, //U+1C26  LEPCHA VOWEL SIGN AA         //~v6VbI~
//     {0x1C27  ,0x1C27  }, //U+1C27  LEPCHA VOWEL SIGN I          //~v6VbI~
//     {0x1C28  ,0x1C28  }, //U+1C28  LEPCHA VOWEL SIGN O          //~v6VbI~
//     {0x1C29  ,0x1C29  }, //U+1C29  LEPCHA VOWEL SIGN OO         //~v6VbI~
//     {0x1C2A  ,0x1C2A  }, //U+1C2A  LEPCHA VOWEL SIGN U          //~v6VbI~
//     {0x1C2B  ,0x1C2B  }, //U+1C2B  LEPCHA VOWEL SIGN UU         //~v6VbI~
     {0x1C24  ,0x1C2b  },                                          //~v6VbI~
//     {0x1C34  ,0x1C34  }, //U+1C34  LEPCHA CONSONANT SIGN NYIN-DO//~v6VbI~
//     {0x1C35  ,0x1C35  }, //U+1C35  LEPCHA CONSONANT SIGN KANG   //~v6VbI~
       {0x1C34  ,0x1C35  },                                        //~v6VbI~
     {0x1CE1  ,0x1CE1  }, //U+1CE1  VEDIC TONE ATHARVAVEDIC INDEPENDENT SVARITA//~v6VbI~
//     {0x1CF2  ,0x1CF2  }, //U+1CF2  VEDIC SIGN ARDHAVISARGA      //~v6VbI~
//     {0x1CF3  ,0x1CF3  }, //U+1CF3  VEDIC SIGN ROTATED ARDHAVISARGA//~v6VbI~
     {0x1CF2  ,0x1CF3  },                                          //~v6VbI~
     {0x1CF7  ,0x1CF7  }, //U+1CF7  VEDIC SIGN ATIKRAMA            //~v6VbI~
//     {0x302E  ,0x302E  }, //U+302E  HANGUL SINGLE DOT TONE MARK  //~v6VbI~
//     {0x302F  ,0x302F  }, //U+302F  HANGUL DOUBLE DOT TONE MARK  //~v6VbI~
     {0x302E  ,0x302f  },                                          //~v6VbI~
//     {0xA823  ,0xA823  }, //U+A823  SYLOTI NAGRI VOWEL SIGN A    //~v6VbI~
//     {0xA824  ,0xA824  }, //U+A824  SYLOTI NAGRI VOWEL SIGN I    //~v6VbI~
     {0xA823  ,0xA824  },                                          //~v6VbI~
     {0xA827  ,0xA827  }, //U+A827  SYLOTI NAGRI VOWEL SIGN OO     //~v6VbI~
//     {0xA880  ,0xA880  }, //U+A880  SAURASHTRA SIGN ANUSVARA     //~v6VbI~
//     {0xA881  ,0xA881  }, //U+A881  SAURASHTRA SIGN VISARGA      //~v6VbI~
     {0xA880  ,0xA881  },                                          //~v6VbI~
//     {0xA8B4  ,0xA8B4  }, //U+A8B4  SAURASHTRA CONSONANT SIGN HAARU//~v6VbI~
//     {0xA8B5  ,0xA8B5  }, //U+A8B5  SAURASHTRA VOWEL SIGN AA     //~v6VbI~
//     {0xA8B6  ,0xA8B6  }, //U+A8B6  SAURASHTRA VOWEL SIGN I      //~v6VbI~
//     {0xA8B7  ,0xA8B7  }, //U+A8B7  SAURASHTRA VOWEL SIGN II     //~v6VbI~
//     {0xA8B8  ,0xA8B8  }, //U+A8B8  SAURASHTRA VOWEL SIGN U      //~v6VbI~
//     {0xA8B9  ,0xA8B9  }, //U+A8B9  SAURASHTRA VOWEL SIGN UU     //~v6VbI~
//     {0xA8BA  ,0xA8BA  }, //U+A8BA  SAURASHTRA VOWEL SIGN VOCALIC R//~v6VbI~
//     {0xA8BB  ,0xA8BB  }, //U+A8BB  SAURASHTRA VOWEL SIGN VOCALIC RR//~v6VbI~
//     {0xA8BC  ,0xA8BC  }, //U+A8BC  SAURASHTRA VOWEL SIGN VOCALIC L//~v6VbI~
//     {0xA8BD  ,0xA8BD  }, //U+A8BD  SAURASHTRA VOWEL SIGN VOCALIC LL//~v6VbI~
//     {0xA8BE  ,0xA8BE  }, //U+A8BE  SAURASHTRA VOWEL SIGN E      //~v6VbI~
//     {0xA8BF  ,0xA8BF  }, //U+A8BF  SAURASHTRA VOWEL SIGN EE     //~v6VbI~
//     {0xA8C0  ,0xA8C0  }, //U+A8C0  SAURASHTRA VOWEL SIGN AI     //~v6VbI~
//     {0xA8C1  ,0xA8C1  }, //U+A8C1  SAURASHTRA VOWEL SIGN O      //~v6VbI~
//     {0xA8C2  ,0xA8C2  }, //U+A8C2  SAURASHTRA VOWEL SIGN OO     //~v6VbI~
//     {0xA8C3  ,0xA8C3  }, //U+A8C3  SAURASHTRA VOWEL SIGN AU     //~v6VbI~
     {0xA8B4  ,0xA8c3  },                                          //~v6VbI~
//     {0xA952  ,0xA952  }, //U+A952  REJANG CONSONANT SIGN H      //~v6VbI~
//     {0xA953  ,0xA953  }, //U+A953  REJANG VIRAMA                //~v6VbI~
     {0xA952  ,0xA953  },                                          //~v6VbI~
     {0xA983  ,0xA983  }, //U+A983  JAVANESE SIGN WIGNYAN          //~v6VbI~
//     {0xA9B4  ,0xA9B4  }, //U+A9B4  JAVANESE VOWEL SIGN TARUNG   //~v6VbI~
//     {0xA9B5  ,0xA9B5  }, //U+A9B5  JAVANESE VOWEL SIGN TOLONG   //~v6VbI~
     {0xA9B4  ,0xA9B5  },                                          //~v6VbI~
//     {0xA9BA  ,0xA9BA  }, //U+A9BA  JAVANESE VOWEL SIGN TALING   //~v6VbI~
//     {0xA9BB  ,0xA9BB  }, //U+A9BB  JAVANESE VOWEL SIGN DIRGA MURE//~v6VbI~
     {0xA9BA  ,0xA9Bb  },                                          //~v6VbI~
//     {0xA9BD  ,0xA9BD  }, //U+A9BD  JAVANESE CONSONANT SIGN KERET//~v6VbI~
//     {0xA9BE  ,0xA9BE  }, //U+A9BE  JAVANESE CONSONANT SIGN PENGKAL//~v6VbI~
//     {0xA9BF  ,0xA9BF  }, //U+A9BF  JAVANESE CONSONANT SIGN CAKRA//~v6VbI~
//     {0xA9C0  ,0xA9C0  }, //U+A9C0  JAVANESE PANGKON             //~v6VbI~
     {0xA9BD  ,0xA9c0  },                                          //~v6VbI~
//     {0xAA2F  ,0xAA2F  }, //U+AA2F  CHAM VOWEL SIGN O            //~v6VbI~
//     {0xAA30  ,0xAA30  }, //U+AA30  CHAM VOWEL SIGN AI           //~v6VbI~
     {0xAA2F  ,0xAA30  },                                          //~v6VbI~
//     {0xAA33  ,0xAA33  }, //U+AA33  CHAM CONSONANT SIGN YA       //~v6VbI~
//     {0xAA34  ,0xAA34  }, //U+AA34  CHAM CONSONANT SIGN RA       //~v6VbI~
     {0xAA33  ,0xAA34  },                                          //~v6VbI~
     {0xAA4D  ,0xAA4D  }, //U+AA4D  CHAM CONSONANT SIGN FINAL H    //~v6VbI~
     {0xAA7B  ,0xAA7B  }, //U+AA7B  MYANMAR SIGN PAO KAREN TONE    //~v6VbI~
     {0xAA7D  ,0xAA7D  }, //U+AA7D  MYANMAR SIGN TAI LAING TONE-5  //~v6VbI~
     {0xAAEB  ,0xAAEB  }, //U+AAEB  MEETEI MAYEK VOWEL SIGN II     //~v6VbI~
//     {0xAAEE  ,0xAAEE  }, //U+AAEE  MEETEI MAYEK VOWEL SIGN AU   //~v6VbI~
//     {0xAAEF  ,0xAAEF  }, //U+AAEF  MEETEI MAYEK VOWEL SIGN AAU  //~v6VbI~
     {0xAAEE  ,0xAAEf  },                                          //~v6VbI~
     {0xAAF5  ,0xAAF5  }, //U+AAF5  MEETEI MAYEK VOWEL SIGN VISARGA//~v6VbI~
//     {0xABE3  ,0xABE3  }, //U+ABE3  MEETEI MAYEK VOWEL SIGN ONAP //~v6VbI~
//     {0xABE4  ,0xABE4  }, //U+ABE4  MEETEI MAYEK VOWEL SIGN INAP //~v6VbI~
     {0xABE3  ,0xABE4  },                                          //~v6VbI~
//     {0xABE6  ,0xABE6  }, //U+ABE6  MEETEI MAYEK VOWEL SIGN YENAP//~v6VbI~
//     {0xABE7  ,0xABE7  }, //U+ABE7  MEETEI MAYEK VOWEL SIGN SOUNAP//~v6VbI~
     {0xABE6  ,0xABE7  },                                          //~v6VbI~
//     {0xABE9  ,0xABE9  }, //U+ABE9  MEETEI MAYEK VOWEL SIGN CHEINAP//~v6VbI~
//     {0xABEA  ,0xABEA  }, //U+ABEA  MEETEI MAYEK VOWEL SIGN NUNG //~v6VbI~
     {0xABE9  ,0xABEa  },                                          //~v6VbI~
     {0xABEC  ,0xABEC  }, //U+ABEC  MEETEI MAYEK LUM IYEK          //~v6VbI~
     {0x11000 ,0x11000 }, //U+11000     BRAHMI SIGN CANDRABINDU    //~v6VbI~
     {0x11002 ,0x11002 }, //U+11002     BRAHMI SIGN VISARGA        //~v6VbI~
     {0x11082 ,0x11082 }, //U+11082     KAITHI SIGN VISARGA        //~v6VbI~
//     {0x110B0 ,0x110B0 }, //U+110B0     KAITHI VOWEL SIGN AA     //~v6VbI~
//     {0x110B1 ,0x110B1 }, //U+110B1     KAITHI VOWEL SIGN I      //~v6VbI~
     {0x110B0 ,0x110B1 },                                          //~v6VbI~
     {0x110B2 ,0x110B2 }, //U+110B2     KAITHI VOWEL SIGN II       //~v6VbI~
//     {0x110B7 ,0x110B7 }, //U+110B7     KAITHI VOWEL SIGN O      //~v6VbI~
//     {0x110B8 ,0x110B8 }, //U+110B8     KAITHI VOWEL SIGN AU     //~v6VbI~
     {0x110B7 ,0x110B8 },                                          //~v6VbI~
     {0x1112C ,0x1112C }, //U+1112C     CHAKMA VOWEL SIGN E        //~v6VbI~
//     {0x11145 ,0x11145 }, //U+11145     CHAKMA VOWEL SIGN AA    ？//~v6VbI~
//     {0x11146 ,0x11146 }, //U+11146     CHAKMA VOWEL SIGN EI    ？//~v6VbI~
     {0x11145 ,0x11146 },                                          //~v6VbI~
     {0x11182 ,0x11182 }, //U+11182     SHARADA SIGN VISARGA       //~v6VbI~
//     {0x111B3 ,0x111B3 }, //U+111B3     SHARADA VOWEL SIGN AA    //~v6VbI~
//     {0x111B4 ,0x111B4 }, //U+111B4     SHARADA VOWEL SIGN I     //~v6VbI~
//     {0x111B5 ,0x111B5 }, //U+111B5     SHARADA VOWEL SIGN II    //~v6VbI~
     {0x111B3 ,0x111B5 },                                          //~v6VbI~
//     {0x111BF ,0x111BF }, //U+111BF     SHARADA VOWEL SIGN AU    //~v6VbI~
//     {0x111C0 ,0x111C0 }, //U+111C0     SHARADA SIGN VIRAMA      //~v6VbI~
     {0x111BF ,0x111c0 },                                          //~v6VbI~
//     {0x1122C ,0x1122C }, //U+1122C     KHOJKI VOWEL SIGN AA     //~v6VbI~
//     {0x1122D ,0x1122D }, //U+1122D     KHOJKI VOWEL SIGN I      //~v6VbI~
//     {0x1122E ,0x1122E }, //U+1122E     KHOJKI VOWEL SIGN II     //~v6VbI~
     {0x1122C ,0x1122e },                                          //~v6VbI~
//     {0x11232 ,0x11232 }, //U+11232     KHOJKI VOWEL SIGN O      //~v6VbI~
//     {0x11233 ,0x11233 }, //U+11233     KHOJKI VOWEL SIGN AU     //~v6VbI~
     {0x11232 ,0x11233 },                                          //~v6VbI~
     {0x11235 ,0x11235 }, //U+11235     KHOJKI SIGN VIRAMA         //~v6VbI~
//     {0x112E0 ,0x112E0 }, //U+112E0     KHUDAWADI VOWEL SIGN AA  //~v6VbI~
//     {0x112E1 ,0x112E1 }, //U+112E1     KHUDAWADI VOWEL SIGN I   //~v6VbI~
//     {0x112E2 ,0x112E2 }, //U+112E2     KHUDAWADI VOWEL SIGN II  //~v6VbI~
     {0x112E0 ,0x112E2 },                                          //~v6VbI~
//     {0x11302 ,0x11302 }, //U+11302     GRANTHA SIGN ANUSVARA    //~v6VbI~
//     {0x11303 ,0x11303 }, //U+11303     GRANTHA SIGN VISARGA     //~v6VbI~
     {0x11302 ,0x11303 },                                          //~v6VbI~
//     {0x1133E ,0x1133E }, //U+1133E     GRANTHA VOWEL SIGN AA    //~v6VbI~
//     {0x1133F ,0x1133F }, //U+1133F     GRANTHA VOWEL SIGN I     //~v6VbI~
     {0x1133E ,0x1133f },                                          //~v6VbI~
//     {0x11341 ,0x11341 }, //U+11341     GRANTHA VOWEL SIGN U     //~v6VbI~
//     {0x11342 ,0x11342 }, //U+11342     GRANTHA VOWEL SIGN UU    //~v6VbI~
//     {0x11343 ,0x11343 }, //U+11343     GRANTHA VOWEL SIGN VOCALIC R//~v6VbI~
//     {0x11344 ,0x11344 }, //U+11344     GRANTHA VOWEL SIGN VOCALIC RR//~v6VbI~
     {0x11341 ,0x11344 },                                          //~v6VbI~
//     {0x11347 ,0x11347 }, //U+11347     GRANTHA VOWEL SIGN EE    //~v6VbI~
//     {0x11348 ,0x11348 }, //U+11348     GRANTHA VOWEL SIGN AI    //~v6VbI~
     {0x11347 ,0x11348 },                                          //~v6VbI~
//     {0x1134B ,0x1134B }, //U+1134B     GRANTHA VOWEL SIGN OO    //~v6VbI~
//     {0x1134C ,0x1134C }, //U+1134C     GRANTHA VOWEL SIGN AU    //~v6VbI~
//     {0x1134D ,0x1134D }, //U+1134D     GRANTHA SIGN VIRAMA      //~v6VbI~
     {0x1134B ,0x1134d },                                          //~v6VbI~
     {0x11357 ,0x11357 }, //U+11357     GRANTHA AU LENGTH MARK     //~v6VbI~
//     {0x11362 ,0x11362 }, //U+11362     GRANTHA VOWEL SIGN VOCALIC L//~v6VbI~
//     {0x11363 ,0x11363 }, //U+11363     GRANTHA VOWEL SIGN VOCALIC LL//~v6VbI~
     {0x11362 ,0x11363 },                                          //~v6VbI~
//     {0x11435 ,0x11435 }, //U+11435     NEWA VOWEL SIGN AA       //~v6VbI~
//     {0x11436 ,0x11436 }, //U+11436     NEWA VOWEL SIGN I        //~v6VbI~
//     {0x11437 ,0x11437 }, //U+11437     NEWA VOWEL SIGN II       //~v6VbI~
     {0x11435 ,0x11437 },                                          //~v6VbI~
//     {0x11440 ,0x11440 }, //U+11440     NEWA VOWEL SIGN O        //~v6VbI~
//     {0x11441 ,0x11441 }, //U+11441     NEWA VOWEL SIGN AU       //~v6VbI~
     {0x11440 ,0x11441 },                                          //~v6VbI~
     {0x11445 ,0x11445 }, //U+11445     NEWA SIGN VISARGA          //~v6VbI~
//     {0x114B0 ,0x114B0 }, //U+114B0     TIRHUTA VOWEL SIGN AA    //~v6VbI~
//     {0x114B1 ,0x114B1 }, //U+114B1     TIRHUTA VOWEL SIGN I     //~v6VbI~
//     {0x114B2 ,0x114B2 }, //U+114B2     TIRHUTA VOWEL SIGN II    //~v6VbI~
     {0x114B0 ,0x114B2 },                                          //~v6VbI~
     {0x114B9 ,0x114B9 }, //U+114B9     TIRHUTA VOWEL SIGN E       //~v6VbI~
//     {0x114BB ,0x114BB }, //U+114BB     TIRHUTA VOWEL SIGN AI    //~v6VbI~
//     {0x114BC ,0x114BC }, //U+114BC     TIRHUTA VOWEL SIGN O     //~v6VbI~
//     {0x114BD ,0x114BD }, //U+114BD     TIRHUTA VOWEL SIGN SHORT O//~v6VbI~
//     {0x114BE ,0x114BE }, //U+114BE     TIRHUTA VOWEL SIGN AU    //~v6VbI~
     {0x114BB ,0x114Be },                                          //~v6VbI~
     {0x114C1 ,0x114C1 }, //U+114C1     TIRHUTA SIGN VISARGA       //~v6VbI~
//     {0x115AF ,0x115AF }, //U+115AF     SIDDHAM VOWEL SIGN AA    //~v6VbI~
//     {0x115B0 ,0x115B0 }, //U+115B0     SIDDHAM VOWEL SIGN I     //~v6VbI~
//     {0x115B1 ,0x115B1 }, //U+115B1     SIDDHAM VOWEL SIGN II    //~v6VbI~
     {0x115AF ,0x115b1 },                                          //~v6VbI~
//     {0x115B8 ,0x115B8 }, //U+115B8     SIDDHAM VOWEL SIGN E     //~v6VbI~
//     {0x115B9 ,0x115B9 }, //U+115B9     SIDDHAM VOWEL SIGN AI    //~v6VbI~
//     {0x115BA ,0x115BA }, //U+115BA     SIDDHAM VOWEL SIGN O     //~v6VbI~
//     {0x115BB ,0x115BB }, //U+115BB     SIDDHAM VOWEL SIGN AU    //~v6VbI~
     {0x115B8 ,0x115Bb },                                          //~v6VbI~
     {0x115BE ,0x115BE }, //U+115BE     SIDDHAM SIGN VISARGA       //~v6VbI~
//     {0x11630 ,0x11630 }, //U+11630     MODI VOWEL SIGN AA       //~v6VbI~
//     {0x11631 ,0x11631 }, //U+11631     MODI VOWEL SIGN I        //~v6VbI~
//     {0x11632 ,0x11632 }, //U+11632     MODI VOWEL SIGN II       //~v6VbI~
     {0x11630 ,0x11632 },                                          //~v6VbI~
//     {0x1163B ,0x1163B }, //U+1163B     MODI VOWEL SIGN O        //~v6VbI~
//     {0x1163C ,0x1163C }, //U+1163C     MODI VOWEL SIGN AU       //~v6VbI~
     {0x1163B ,0x1163c },                                          //~v6VbI~
     {0x1163E ,0x1163E }, //U+1163E     MODI SIGN VISARGA          //~v6VbI~
     {0x116AC ,0x116AC }, //U+116AC     TAKRI SIGN VISARGA         //~v6VbI~
//     {0x116AE ,0x116AE }, //U+116AE     TAKRI VOWEL SIGN I       //~v6VbI~
//     {0x116AF ,0x116AF }, //U+116AF     TAKRI VOWEL SIGN II      //~v6VbI~
     {0x116AE ,0x116Af },                                          //~v6VbI~
     {0x116B6 ,0x116B6 }, //U+116B6     TAKRI SIGN VIRAMA          //~v6VbI~
//     {0x11720 ,0x11720 }, //U+11720     AHOM VOWEL SIGN A        //~v6VbI~
//     {0x11721 ,0x11721 }, //U+11721     AHOM VOWEL SIGN AA       //~v6VbI~
     {0x11720 ,0x11721 },                                          //~v6VbI~
     {0x11726 ,0x11726 }, //U+11726     AHOM VOWEL SIGN E          //~v6VbI~
//     {0x1182C ,0x1182C }, //U+1182C     DOGRA VOWEL SIGN AA     ？//~v6VbI~
//     {0x1182D ,0x1182D }, //U+1182D     DOGRA VOWEL SIGN I  ？   //~v6VbI~
//     {0x1182E ,0x1182E }, //U+1182E     DOGRA VOWEL SIGN II     ？//~v6VbI~
     {0x1182C ,0x1182e },                                          //~v6VbI~
     {0x11838 ,0x11838 }, //U+11838     DOGRA SIGN VISARGA  ？     //~v6VbI~
     {0x11A39 ,0x11A39 }, //U+11A39     ZANABAZAR SQUARE SIGN VISARGA//~v6VbI~
//     {0x11A57 ,0x11A57 }, //U+11A57     SOYOMBO VOWEL SIGN AI    //~v6VbI~
//     {0x11A58 ,0x11A58 }, //U+11A58     SOYOMBO VOWEL SIGN AU    //~v6VbI~
     {0x11A57 ,0x11A58 },                                          //~v6VbI~
     {0x11A97 ,0x11A97 }, //U+11A97     SOYOMBO SIGN VISARGA       //~v6VbI~
     {0x11C2F ,0x11C2F }, //U+11C2F     BHAIKSUKI VOWEL SIGN AA    //~v6VbI~
     {0x11C3E ,0x11C3E }, //U+11C3E     BHAIKSUKI SIGN VISARGA     //~v6VbI~
     {0x11CA9 ,0x11CA9 }, //U+11CA9     MARCHEN SUBJOINED LETTER YA//~v6VbI~
     {0x11CB1 ,0x11CB1 }, //U+11CB1     MARCHEN VOWEL SIGN I       //~v6VbI~
     {0x11CB4 ,0x11CB4 }, //U+11CB4     MARCHEN VOWEL SIGN O       //~v6VbI~
//     {0x11D8A ,0x11D8A }, //U+11D8A     GUNJALA GONDI VOWEL SIGN AA     ？//~v6VbI~
//     {0x11D8B ,0x11D8B }, //U+11D8B     GUNJALA GONDI VOWEL SIGN I  ？//~v6VbI~
//     {0x11D8C ,0x11D8C }, //U+11D8C     GUNJALA GONDI VOWEL SIGN II     ？//~v6VbI~
//     {0x11D8D ,0x11D8D }, //U+11D8D     GUNJALA GONDI VOWEL SIGN U  ？//~v6VbI~
//     {0x11D8E ,0x11D8E }, //U+11D8E     GUNJALA GONDI VOWEL SIGN UU     ？//~v6VbI~
     {0x11D8A ,0x11D8e },                                          //~v6VbI~
//     {0x11D93 ,0x11D93 }, //U+11D93     GUNJALA GONDI VOWEL SIGN OO     ？//~v6VbI~
//     {0x11D94 ,0x11D94 }, //U+11D94     GUNJALA GONDI VOWEL SIGN AU     ？//~v6VbI~
     {0x11D93 ,0x11D94 },                                          //~v6VbI~
     {0x11D96 ,0x11D96 }, //U+11D96     GUNJALA GONDI SIGN VISARGA  ？//~v6VbI~
//     {0x11EF5 ,0x11EF5 }, //U+11EF5     MAKASAR VOWEL SIGN E    ？//~v6VbI~
//     {0x11EF6 ,0x11EF6 }, //U+11EF6     MAKASAR VOWEL SIGN O    ？//~v6VbI~
     {0x11EF5 ,0x11EF6 },                                          //~v6VbI~
//     {0x16F51 ,0x16F51 }, //U+16F51     MIAO SIGN ASPIRATION    ？//~v6VbI~
//     {0x16F52 ,0x16F52 }, //U+16F52     MIAO SIGN REFORMED VOICING  ？//~v6VbI~
//     {0x16F53 ,0x16F53 }, //U+16F53     MIAO SIGN REFORMED ASPIRATION   ？//~v6VbI~
//     {0x16F54 ,0x16F54 }, //U+16F54     MIAO VOWEL SIGN A   ？   //~v6VbI~
//     {0x16F55 ,0x16F55 }, //U+16F55     MIAO VOWEL SIGN AA  ？   //~v6VbI~
//     {0x16F56 ,0x16F56 }, //U+16F56     MIAO VOWEL SIGN AHH     ？//~v6VbI~
//     {0x16F57 ,0x16F57 }, //U+16F57     MIAO VOWEL SIGN AN  ？   //~v6VbI~
//     {0x16F58 ,0x16F58 }, //U+16F58     MIAO VOWEL SIGN ANG     ？//~v6VbI~
//     {0x16F59 ,0x16F59 }, //U+16F59     MIAO VOWEL SIGN O   ？   //~v6VbI~
//     {0x16F5A ,0x16F5A }, //U+16F5A     MIAO VOWEL SIGN OO  ？   //~v6VbI~
//     {0x16F5B ,0x16F5B }, //U+16F5B     MIAO VOWEL SIGN WO  ？   //~v6VbI~
//     {0x16F5C ,0x16F5C }, //U+16F5C     MIAO VOWEL SIGN W   ？   //~v6VbI~
//     {0x16F5D ,0x16F5D }, //U+16F5D     MIAO VOWEL SIGN E   ？   //~v6VbI~
//     {0x16F5E ,0x16F5E }, //U+16F5E     MIAO VOWEL SIGN EN  ？   //~v6VbI~
//     {0x16F5F ,0x16F5F }, //U+16F5F     MIAO VOWEL SIGN ENG     ？//~v6VbI~
//     {0x16F60 ,0x16F60 }, //U+16F60     MIAO VOWEL SIGN OEY     ？//~v6VbI~
//     {0x16F61 ,0x16F61 }, //U+16F61     MIAO VOWEL SIGN I   ？   //~v6VbI~
//     {0x16F62 ,0x16F62 }, //U+16F62     MIAO VOWEL SIGN IA  ？   //~v6VbI~
//     {0x16F63 ,0x16F63 }, //U+16F63     MIAO VOWEL SIGN IAN     ？//~v6VbI~
//     {0x16F64 ,0x16F64 }, //U+16F64     MIAO VOWEL SIGN IANG    ？//~v6VbI~
//     {0x16F65 ,0x16F65 }, //U+16F65     MIAO VOWEL SIGN IO  ？   //~v6VbI~
//     {0x16F66 ,0x16F66 }, //U+16F66     MIAO VOWEL SIGN IE  ？   //~v6VbI~
//     {0x16F67 ,0x16F67 }, //U+16F67     MIAO VOWEL SIGN II  ？   //~v6VbI~
//     {0x16F68 ,0x16F68 }, //U+16F68     MIAO VOWEL SIGN IU  ？   //~v6VbI~
//     {0x16F69 ,0x16F69 }, //U+16F69     MIAO VOWEL SIGN ING     ？//~v6VbI~
//     {0x16F6A ,0x16F6A }, //U+16F6A     MIAO VOWEL SIGN U   ？   //~v6VbI~
//     {0x16F6B ,0x16F6B }, //U+16F6B     MIAO VOWEL SIGN UA  ？   //~v6VbI~
//     {0x16F6C ,0x16F6C }, //U+16F6C     MIAO VOWEL SIGN UAN     ？//~v6VbI~
//     {0x16F6D ,0x16F6D }, //U+16F6D     MIAO VOWEL SIGN UANG    ？//~v6VbI~
//     {0x16F6E ,0x16F6E }, //U+16F6E     MIAO VOWEL SIGN UU  ？   //~v6VbI~
//     {0x16F6F ,0x16F6F }, //U+16F6F     MIAO VOWEL SIGN UEI     ？//~v6VbI~
//     {0x16F70 ,0x16F70 }, //U+16F70     MIAO VOWEL SIGN UNG     ？//~v6VbI~
//     {0x16F71 ,0x16F71 }, //U+16F71     MIAO VOWEL SIGN Y   ？   //~v6VbI~
//     {0x16F72 ,0x16F72 }, //U+16F72     MIAO VOWEL SIGN YI  ？   //~v6VbI~
//     {0x16F73 ,0x16F73 }, //U+16F73     MIAO VOWEL SIGN AE  ？   //~v6VbI~
//     {0x16F74 ,0x16F74 }, //U+16F74     MIAO VOWEL SIGN AEE     ？//~v6VbI~
//     {0x16F75 ,0x16F75 }, //U+16F75     MIAO VOWEL SIGN ERR     ？//~v6VbI~
//     {0x16F76 ,0x16F76 }, //U+16F76     MIAO VOWEL SIGN ROUNDED ERR     ？//~v6VbI~
//     {0x16F77 ,0x16F77 }, //U+16F77     MIAO VOWEL SIGN ER  ？   //~v6VbI~
//     {0x16F78 ,0x16F78 }, //U+16F78     MIAO VOWEL SIGN ROUNDED ER  ？//~v6VbI~
//     {0x16F79 ,0x16F79 }, //U+16F79     MIAO VOWEL SIGN AI  ？   //~v6VbI~
//     {0x16F7A ,0x16F7A }, //U+16F7A     MIAO VOWEL SIGN EI  ？   //~v6VbI~
//     {0x16F7B ,0x16F7B }, //U+16F7B     MIAO VOWEL SIGN AU  ？   //~v6VbI~
//     {0x16F7C ,0x16F7C }, //U+16F7C     MIAO VOWEL SIGN OU  ？   //~v6VbI~
//     {0x16F7D ,0x16F7D }, //U+16F7D     MIAO VOWEL SIGN N   ？   //~v6VbI~
//     {0x16F7E ,0x16F7E }, //U+16F7E     MIAO VOWEL SIGN NG  ？   //~v6VbI~
     {0x16F51 ,0x16F7e },                                          //~v6VbI~
//     {0x1D165 ,0x1D165 }, //U+1D165     MUSICAL SYMBOL COMBINING STEM   ？//~v6VbI~
//     {0x1D166 ,0x1D166 }, //U+1D166     MUSICAL SYMBOL COMBINING SPRECHGESANG STEM  ？//~v6VbI~
     {0x1D165 ,0x1D166 },                                          //~v6VbI~
//     {0x1D16D ,0x1D16D }, //U+1D16D     MUSICAL SYMBOL COMBINING AUGMENTATION DOT   ？//~v6VbI~
//     {0x1D16E ,0x1D16E }, //U+1D16E     MUSICAL SYMBOL COMBINING FLAG-1     ？//~v6VbI~
//     {0x1D16F ,0x1D16F }, //U+1D16F     MUSICAL SYMBOL COMBINING FLAG-2     ？//~v6VbI~
//     {0x1D170 ,0x1D170 }, //U+1D170     MUSICAL SYMBOL COMBINING FLAG-3     ？//~v6VbI~
//     {0x1D171 ,0x1D171 }, //U+1D171     MUSICAL SYMBOL COMBINING FLAG-4     ？//~v6VbI~
//     {0x1D172 ,0x1D172 }, //U+1D172     MUSICAL SYMBOL COMBINING FLAG-5     ？//~v6VbI~
     {0x1D16D ,0x1D172 }, //U+1D16D     MUSICAL SYMBOL COMBINING AUGMENTATION DOT   ？//~v6VbI~
        };                                                         //~v6VbI~
#ifndef XXX                                                        //~v6X0I~
	if ((Popt & UTF4ISCMO_WIDTHPARM) 	//0x0200 		//WIDTHMASK contains width//~v6X0I~
    &&  !(Popt & UTF4ISCMO_WIDTHMASK) 	//0x00ff 		//width if WIDTHPARM on//~v6X0I~
    )   //chk combining2SCM                                        //~v6X0I~
    {                                                              //~v6X0I~
		if (mk_wcwidth_combining2SCM(0,Pucs))                      //~v6X0R~
        	return 2;                                              //~v6X0I~
    }                                                              //~v6X0I~
	if (!(Popt & UTF4ISCMO_NOSCM2)) 	//0x0100 		//! No chk combine2//~v6X0I~
    {                                                              //~v6X0I~
		if (mk_wcwidth_combining2SCM(0,Pucs))                      //~v6X0R~
        	return 2;                                              //~v6X0I~
    }                                                              //~v6X0I~
#endif                                                             //~v6X0I~
    if (bisearch(Pucs,Suctb_SCM,sizeof(Suctb_SCM) / sizeof(struct interval) - 1))//~v6VbR~
        return 1;                                                  //~v6VbI~
    return 0;                                                      //~v6VbI~
}//int utf4_isSpacingCombiningMark                                 //~v6VbI~
//******************************************************           //~v6VbI~
//chk ambiguous                                                    //~v6VbI~
//rc: 2:nonlang, 3:lang, 4:langucs4, 1:other                       //~v6VbI~
//******************************************************           //~v6VbI~
int utf4_isAmbiguous(int Popt,UWUCS Pucs)                          //~v6VbI~
{                                                                  //~v6VbI~
	int rc=0;                                                      //~v6VbI~
//*****************                                                //~v6VbI~
  	if (bisearch(Pucs, Sambiguous_non_langs,sizeof(Sambiguous_non_langs) / sizeof(struct interval) - 1))//~v6VbR~
    	rc=2;                                                      //~v6VbI~
    else                                                           //~v6VbI~
  	if (bisearch(Pucs, Sambiguous_langs,sizeof(Sambiguous_langs) / sizeof(struct interval) - 1))//~v6VbR~
		rc=3;                                                      //~v6VbI~
    else                                                           //~v6VbI~
	if (bisearch(Pucs, Sambiguous_langs_ucs4,sizeof(Sambiguous_langs_ucs4) / sizeof(struct interval) - 1))//~v6VbR~
		rc=4;                                                      //~v6VbI~
    else                                                           //~v6VbI~
  	if (bisearch(Pucs, ambiguous,sizeof(ambiguous) / sizeof(struct interval) - 1))//~v6VbR~
    	rc=1;                                                      //~v6VbI~
    else                                                           //~v6VbI~
	if (Popt & UTF4IAO_SCM)	// 0x01 chk Spacing Combining Mark     //~v6VbI~
    {                                                              //~v6VbI~
		if (utf4_isSpacingCombiningMark(0,Pucs))                   //~v6VbI~
        	rc=5;                                                  //~v6VbR~
    }                                                              //~v6VbI~
    if (rc)                                                        //~v6WnI~
    	UTRACEP("%s:rc=%d,ucs=%06x ambiguous\n",UTT,rc,Pucs);                    //~v6VbR~//~v6WnR~
    return rc;                                                     //~v6VbI~
}//utf4_isAmbiguous                                                //~v6VbI~
#ifdef LNX                                                         //~v6WnI~
//******************************************************           //~v6WkM~
//ambiguous for XXE                                                //~v6WkM~
//******************************************************           //~v6WkM~
int utf4_isAmbiguous_XXE(int Popt,UWUCS Pucs)                      //~v6WkI~
{                                                                  //~v6WkM~
	int rc=0;                                                      //~v6WkM~
//**************************                                       //~v6WkM~
	if (bisearch(Pucs, Sambiguous_langs_XXE,sizeof(Sambiguous_langs_XXE) / sizeof(struct interval) - 1))//~v6WkR~
    	rc=2;                                                      //~v6WkI~
    else                                                           //~v6WkI~
	if (bisearch(Pucs, Sambiguous_langs_ucs4_XXE,sizeof(Sambiguous_langs_ucs4_XXE) / sizeof(struct interval) - 1))//~v6WkR~
		rc=2;                                                      //~v6WkI~
    if (rc)                                                        //~v6WnI~
    	UTRACEP("%s:ucs=%04x ambiguousXXE\n",UTT,Pucs);            //~v6WnI~
	return rc;                                                     //~v6WkM~
}//utf4_isAmbiguous_XXE                                            //~v6WkI~
#else                                                              //~v6WnI~
//******************************************************           //~v6WnI~
//ambiguous for XXE                                                //~v6WnI~
//******************************************************           //~v6WnI~
int utf4_isAmbiguous_WXE(int Popt,UWUCS Pucs)                      //~v6WnI~
{                                                                  //~v6WnI~
	int rc=0;                                                      //~v6WnI~
//**************************                                       //~v6WnI~
  	if (bisearch(Pucs, Sambiguous_non_langs_WXE,                   //~v6WpR~
	       sizeof(Sambiguous_non_langs_WXE) / sizeof(struct interval) - 1))//~v6WpR~
  	{                                                              //~v6WpI~
    	UTRACEP("%s:%06x ambiguous non lang\n",UTT,Pucs);          //~v6WpR~
    	rc=2;                                                      //~v6WpI~
  	}                                                              //~v6WpI~
    else                                                           //~v6WpI~
	if (bisearch(Pucs, Sambiguous_langs_WXE,sizeof(Sambiguous_langs_WXE) / sizeof(struct interval) - 1))//~v6WpR~
    {                                                              //~v6WpI~
    	UTRACEP("%s:%06x ambiguous lang_WXE\n",UTT,Pucs);          //~v6WpR~
    	rc=2;                                                      //~v6WpI~
    }                                                              //~v6WpI~
    else                                                           //~v6WpI~
	if (bisearch(Pucs, Sambiguous_langs_ucs4_XXE,sizeof(Sambiguous_langs_ucs4_XXE) / sizeof(struct interval) - 1))//~v6WpI~
    {                                                              //~v6WpI~
    	UTRACEP("%s:%06x ambiguous lang_ucs4_XXE(WXE)\n",UTT,Pucs);//~v6WpR~
		rc=2;                                                      //~v6WpI~
    }                                                              //~v6WpI~
    else                                                           //~v6WpM~
	if (bisearch(Pucs, ambiguous,sizeof(ambiguous) / sizeof(struct interval) - 1))//~v6WpR~
    {                                                              //~v6WpI~
    	UTRACEP("%s:%06x ambiguous\n",UTT,Pucs);                   //~v6WpI~
    	rc=2;                                                      //~v6WpM~
    }                                                              //~v6WpI~
    if (rc)                                                        //~v6WpI~
    	UTRACEP("%s:ucs=%04x ambiguousXXE\n",UTT,Pucs);            //~v6WpI~
	return rc;                                                     //~v6WnI~
}//utf4_isAmbiguous_WXE                                            //~v6WnI~//~v6WpR~
#endif                                                             //~v6WnI~
//******************************************************           //~v6WiI~
//chk category Cf (wcwidth=0 but show by utfwcwidth=1)             //~v6WiI~
//******************************************************           //~v6WiI~
int utf4_isFormat(int Popt,UWUCS Pucs)                             //~v6WiI~
{                                                                  //~v6WiI~
	int rc=0;                                                      //~v6WiI~
//***********************                                          //~v6WiI~
// 2018/07/22                                                      //~v6WiI~
// https://www.fileformat.info/info/unicode/category/Cf/list.htm   //~v6WiI~
    static const struct interval Suctb_Format[] = {                //~v6WiI~
 {0x00AD    ,0x00AD },                                             //~v6WiI~
 {0x0600    ,0x0605 },                                             //~v6WiI~
 {0x061C    ,0x061C },                                             //~v6WiI~
 {0x06DD    ,0x06DD },                                             //~v6WiI~
 {0x070F    ,0x070F },                                             //~v6WiI~
 {0x08E2    ,0x08E2 },                                             //~v6WiI~
 {0x180E    ,0x180E },                                             //~v6WiI~
 {0x200B    ,0x200F },                                             //~v6WiI~
 {0x202A    ,0x202E },                                             //~v6WiI~
 {0x2060    ,0x2064 },                                             //~v6WiI~
 {0x2066    ,0x206F },                                             //~v6WiI~
 {0xFEFF    ,0xFEFF },                                             //~v6WiI~
 {0xFFF9    ,0xFFFB },                                             //~v6WiI~
 {0x110BD   ,0x110BD},                                             //~v6WiI~
 {0x110CD   ,0x110CD},                                             //~v6WiI~
 {0x1BCA0   ,0x1BCA3},                                             //~v6WiI~
 {0x1D173   ,0x1D17A},                                             //~v6WiI~
 {0xE0001   ,0xE0001},                                             //~v6WiI~
 {0xE0020   ,0xE007f}                                             //~v6WiI~//~v6WmR~
 };                                                                //~v6WiI~
 //************************************                            //~v6WiI~
  	if (bisearch(Pucs, Suctb_Format,sizeof(Suctb_Format) / sizeof(struct interval) - 1))//~v6WiI~
    {                                                              //~v6WnI~
    	UTRACEP("%s:ucs=%04x Format\n",UTT,Pucs);                    //~v6WiI~//~v6WnI~
    	rc=1;                                                      //~v6WiI~
    }                                                              //~v6WnI~
    return rc;                                                     //~v6WiI~
}//utf4_isFormat                                                   //~v6WiR~
//***************************************************************  //~v6X0I~
//*NonSpacingCombining of 2 cell when split                        //~v6X0I~
//***************************************************************  //~v6X0I~
  static const struct interval combining2SCM[] = {                 //~v6X0R~
#ifdef TEST //@@@@test                                             //~v6X0I~
{0x005C1 ,0x005C2 },                                               //~v6X0I~
{0x00610 ,0x00615 },                                               //~v6X0I~
{0x00656 ,0x0065f },                                               //~v6X0I~
{0x006D6 ,0x006DC },                                               //~v6X0I~
{0x006DF ,0x006E4 },                                               //~v6X0I~
{0x006E7 ,0x006E8 },                                               //~v6X0I~
{0x006EA ,0x006ED },                                               //~v6X0I~
{0x00711 ,0x00711 },                                               //~v6X0I~
{0x00730 ,0x0074A },                                               //~v6X0I~
{0x007A6 ,0x007B0 },                                               //~v6X0I~
{0x007EB ,0x007F3 },                                               //~v6X0I~
{0x007FD ,0x007FD },    //unp                                      //~v6X0I~
{0x00816 ,0x00819 },    //unp                                      //~v6X0I~
{0x0081B ,0x00823 },    //unp                                      //~v6X0I~
{0x00825 ,0x00827 },    //unp                                      //~v6X0I~
{0x00829 ,0x0082D },    //unp                                      //~v6X0I~
{0x00859 ,0x0085B },    //unp                                      //~v6X0I~
{0x008D3 ,0x008D3 },    //unp                                      //~v6X0I~
{0x0093A ,0x0093A },                                               //~v6X0I~
{0x0093C ,0x0093C },                                               //~v6X0I~
{0x00941 ,0x00948 },                                               //~v6X0I~
{0x0094D ,0x0094D },                                               //~v6X0I~
{0x00953 ,0x00957 },    //of 951,957                               //~v6X0I~
{0x00962 ,0x00963 },                                               //~v6X0I~
{0x009FE ,0x009FE },    //unp                                      //~v6X0I~
{0x00A01 ,0x00A02 },    //0a03:scm                                 //~v6X0I~
{0x00A3C ,0x00A3C },                                               //~v6X0I~
{0x00A41 ,0x00A42 },                                               //~v6X0I~
{0x00A47 ,0x00A48 },                                               //~v6X0I~
{0x00A4B ,0x00A4D },                                               //~v6X0I~
{0x00A70 ,0x00A71 },                                               //~v6X0I~
{0x00A81 ,0x00A82 },    //0a83:SCM                                 //~v6X0I~
{0x00ABC ,0x00ABC },                                               //~v6X0I~
{0x00AC1 ,0x00AC5 },                                               //~v6X0I~
{0x00AC7 ,0x00AC8 },    //0ac9:scm                                 //~v6X0I~
{0x00ACD ,0x00ACD },    //0acb-0acc:scm                            //~v6X0I~
{0x00AE2 ,0x00AE3 },                                               //~v6X0I~
{0x00AFA ,0x00AFF },    //unp                                      //~v6X0I~
{0x00B44 ,0x00B44 },    //of 0b41,0b44                             //~v6X0I~
{0x00B62 ,0x00B63 },                                               //~v6X0I~
{0x00B82 ,0x00B82 },                                               //~v6X0I~
{0x00BC0 ,0x00BC0 },    //0bc1,0bc2:scm                            //~v6X0I~
{0x00BCD ,0x00BCD },                                               //~v6X0I~
{0x00C00 ,0x00C00 },                                               //~v6X0I~
{0x00C04 ,0x00C04 },    //unp                                      //~v6X0I~
{0x00C62 ,0x00C63 },                                               //~v6X0I~
{0x00C81 ,0x00C81 },                                               //~v6X0I~
{0x00CBC ,0x00CBC },                                               //~v6X0I~
{0x00CBF ,0x00CBF },                                               //~v6X0I~
{0x00CC6 ,0x00CC6 },                                               //~v6X0I~
{0x00CCC ,0x00CCC },  //of 0ccc,0ccd                               //~v6X0I~
{0x00CE2 ,0x00CE3 },                                               //~v6X0I~
{0x00D00 ,0x00D01 },                                               //~v6X0I~
{0x00D3B ,0x00D3C },  //unp                                        //~v6X0I~
{0x00D44 ,0x00D44 },  //of 0d41,0d44                               //~v6X0I~
{0x00D62 ,0x00D63 },                                               //~v6X0I~
{0x00DCA ,0x00DCA },                                               //~v6X0I~
{0x00DD2 ,0x00DD4 },                                               //~v6X0I~
{0x00DD6 ,0x00DD6 },                                               //~v6X0I~
{0x00F18 ,0x00F19 },                                               //~v6X0I~
{0x00F35 ,0x00F35 },                                               //~v6X0I~
{0x00F37 ,0x00F37 },                                               //~v6X0I~
{0x00F39 ,0x00F39 },                                               //~v6X0I~
{0x00F71 ,0x00F7E },                                               //~v6X0I~
{0x00F80 ,0x00F84 },                                               //~v6X0I~
{0x00F86 ,0x00F87 },                                               //~v6X0I~
{0x00F8D ,0x00F97 },                                               //~v6X0I~
{0x00F99 ,0x00FBC },                                               //~v6X0I~
{0x00FC6 ,0x00FC6 },                                               //~v6X0I~
{0x0102D ,0x01030 },                                               //~v6X0I~
#endif //TEST                                                      //~v6X0I~
//#ifdef GGG                                                       //~v6X3R~
//{ 0x1160, 0x11FF },      //hangul,combining     @@@@test         //~v6X3R~
//#else                                                            //~v6X3R~
//#endif                                                           //~v6X3R~
                                                                   //~v6X0I~
{0x3099  ,0x309a  },                                               //~v6X0R~
};                                                                 //~v6X0I~
//***************************************************************  //~v6X0I~
//*chk combining char                                              //~v6X0I~
//*rc:1:combining2, 0:not combining                                //~v6X0R~
//***************************************************************  //~v6X0I~
int mk_wcwidth_combining2SCM(int Popt,UWUCS ucs)                   //~v6X0R~
{                                                                  //~v6X0I~
  	if (bisearch(ucs, combining2SCM,                               //~v6X0R~
	       sizeof(combining2SCM) / sizeof(struct interval) - 1))   //~v6X0R~
    {                                                              //~v6X0I~
        UTRACEP("%s:%06x is combining2SCM char\n",UTT,ucs);        //~v6X0R~
    	return 1;                                                  //~v6X0R~
    }                                                              //~v6X0I~
    return 0;                                                      //~v6X0R~
}//mk_wcwidth_combining                                            //~v6X0I~
