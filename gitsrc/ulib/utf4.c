//*CID://+v6L0R~:                             update#=   72;       //~v6L0R~
//*********************************************************************//~v62XI~
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
                                                                   //~7719I~
struct interval {                                                  //~7719I~
  int first;                                                       //~7719I~
  int last;                                                        //~7719I~
};                                                                 //~7719I~
                                                                   //~7719I~
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
#ifdef AAA                                                         //~v650I~
#else                                                              //~v650M~
#ifdef UTF8UCS2                                                    //~v650I~
//***************************************************************  //~v650M~
//*chk combining char                                              //~v650M~
//***************************************************************  //~v650M~
//int mk_wcwidth_combining(UWCHART ucs)                              //~v650R~//~v6BjR~
int mk_wcwidth_combining(UWUCS ucs)                                //~v6BjI~
{                                                                  //~v650M~
  	if (bisearch(ucs, combining,                                   //~v650M~
	       sizeof(combining) / sizeof(struct interval) - 1))       //~v650M~
    	return 0;                                                  //~v650M~
    return 1;                                                      //~v650M~
}//mk_wcwidth_combining                                            //~v650R~
#endif                                                             //~v650I~
//***************************************************************  //~v650M~
//*combining and DBCS                                              //~v650M~
//***************************************************************  //~v650M~
//int mk_wcwidth(UWCHART ucs)                                        //~v650R~//~v6BjR~
int mk_wcwidth(UWUCS ucs)                                          //~v6BjI~
{                                                                  //~v650M~
#endif                                                             //~v650M~

  /* test for 8-bit control characters */
  if (ucs == 0)
    return 0;
  if (ucs < 32 || (ucs >= 0x7f && ucs < 0xa0))
    return -1;

  /* binary search in table of non-spacing characters */
  if (bisearch(ucs, combining,
	       sizeof(combining) / sizeof(struct interval) - 1))
    return 0;

  /* if we arrive here, ucs is not a combining or C0/C1 control character */

  return 1 +
    (ucs >= 0x1100 &&
     (ucs <= 0x115f ||                    /* Hangul Jamo init. consonants */
      ucs == 0x2329 || ucs == 0x232a ||
      ucs == 0x23ce ||                                             //+v6L0I~
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&
       ucs != 0x303f) ||                  /* CJK ... Yi */
      (ucs >= 0xac00 && ucs <= 0xd7a3) || /* Hangul Syllables */
      (ucs >= 0xf900 && ucs <= 0xfaff) || /* CJK Compatibility Ideographs */
      (ucs >= 0xfe10 && ucs <= 0xfe19) || /* Vertical forms */
      (ucs >= 0xfe30 && ucs <= 0xfe6f) || /* CJK Compatibility Forms */
      (ucs >= 0xff00 && ucs <= 0xff60) || /* Fullwidth Forms */
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||
      (ucs >= 0x30000 && ucs <= 0x3fffd)));
}
#endif
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
                                                                   //~7719I~
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
#ifdef UTF8UCS2                                                    //~v647R~
//int mk_wcwidth_cjk(UWCHART ucs)                                    //~v647R~//~v6BjR~
int mk_wcwidth_cjk(UWUCS ucs)                                      //~v6BjI~
#else                                                              //~v647R~
int mk_wcwidth_cjk(wchar_t ucs)                                    //~7719I~
#endif                                                             //~v647R~
{                                                                  //~7719I~
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
#endif                                                             //~v62XI~
  };                                                               //~7719I~
                                                                   //~7719I~
  /* binary search in table of non-spacing characters */           //~7719I~
  if (bisearch(ucs, ambiguous,                                     //~7719I~
	       sizeof(ambiguous) / sizeof(struct interval) - 1))       //~7719I~
    return 2;                                                      //~7719I~
                                                                   //~7719I~
  return mk_wcwidth(ucs);                                          //~7719I~
}                                                                  //~7719I~
                                                                   //~7719I~
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
