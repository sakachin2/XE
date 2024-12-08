//CID://+vbBuR~:      update#=  297                                //~v7dRR~//~vbBuR~
//***********************************************************************//~v57GI~
//* ucvebc.c                                                       //~v57GI~
//***********************************************************************//~v57GI~
//vbBu:241119 Edit/Browse /Mz option for ebc file to accept 0x0d15 as EOL//~vbBuI~
//v7dR:241113 change ctl option is not for pc 00-->1f but for ebc 00-->3f.//~v7dRI~
//v7dP:241109 ccsid-1140(cp037+Euro) support by "SBCS_CHARSET DefaulMapEuro"(1027/290 is already ebc-E1->20ac)//~v7dPI~
//vata:241026 xcv1.24:add option /mcp037                           //~vataI~
//v7dA:241027 0c4 when xcv /s2b print. EBC2ASC_DBCS was effective, then invalid output//~v7dAI~
//v7dy:241022 by CRLF option, EBC_NL(0x15)<-->ascii LF(0x0a). previously was EBC_LF(0x25)<-->ASCII LF which is converter mapping//~v7dyI~
//v7dx:241019 (Bug)a2e was effective only ctl char                 //~v7dxI~
//v7dw:241019 for safety confirm not overflow Stblctla2e           //~v7dwI~
//v7du:241019 accept ucs2 for E2A by Uxxxx                         //~v7duI~
//v7dm:241006 delete EBC2ASC_BASE option, then use the value as SBCS037 for CP037 without DBCS//~v7dmI~
//v7db:240904 (Bug)A2E tbl setting                                 //~v7dbI~
//v7da:240903 (Bug)cp037 was ignored when cfg:dbcscharset=cp930 & sbcscharset=cp037//~v7daI~
//v7d9:240901 b2m depends current local codepag; Adjust ebc2asc table by local converter.//~v7d9I~
//vbB9:240824 add cp931(cp300+cp037)                               //~vbB9I~
//v7d5:240819 add SJIS_OPT=Base (SBCS=CP037 DP94 version,DBCS=CP300)//~v7d5I~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v66R:100612 apply cfg option E2A/A2E to also internal mapping(ctl char only)//~v66RI~
//v66L:100610 update ctl char trans table                          //~v66LI~
//v66G:100610 Euro(u-20ac)                                         //~v66GI~
//v66E:100609 set rc for internal converter                        //~v66EI~
//v66i:100527 B2E support(EBC and EUC)                             //~v66iI~
//v662:100420 (BUG?)"~" tarbslaption change; cp1027 a0(uppaer),a1(~:7e)<->cp290 a0(~:7e),a1(upper:u203e)//~v662I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v5mX:080820 Fixed LRECL support to avoid EBC DBCS split by LRECL //~v5mXI~
//v5mS:080816 (BUG)initsw not static.                              //~v5mSI~
//v5mR:080809 (BUG)Euro is not on Japanese charset tbl now yet     //~v5mRI~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5mC:080624 sjis->ebc conversion;SO/SO shift option(drop following space if SO/SI inserted)//~v5mCI~
//v5eq:041030 ebc<-->sjis:CP290 option(katakana extended)          //~v5eqI~
//                        (previous C1027 is english extended)     //~v5eqI~
//v5ep:041030 (BUG)ebc<-->sjis:ebc "?" should be 0x6f (not 3f)     //~v5epI~
//v5en:041026 ebc<-->sjis:assign euro currency symbole to 0x80(pc) //~v5enI~
//                        ebc-4a(cent) is also conv to pc-80       //~v5enI~
//v5em:041026 ebc<-->sjis chkprint also sbcs tbl                   //~v5emI~
//v5ek:041026 ebc<-->sjis dbcs support;option of asume SO top of line//~v5emI~
//v5ei:041023 ebc<-->sjis dbcs support;xe cont line support        //~v5eiI~
//v5eg:041023 ebc<-->sjis dbcs support;sosi isrt/del/rep option support//~v5egI~
//v5ef:041023 ebc<-->sjis dbcs support,dbcs errrep char support    //~v5efI~
//v5ed:041020 ebc<-->sjis dbcs support                             //~v5edI~
//v57V:030727 conv ascii<->ebc ctl char option                     //~v57VI~
//v57U:030726 conv ascii-->ebc(CP1027âpè¨ï∂éöägí£)                 //~v57UI~
//v57T:030726 some EBC codepage                                    //~v57TI~
//v57S:030726 hankaku katakana<-->alphabet small letter conversion //~v57SI~
//v57G:030607 for EBCDIC-->ASCII conversion                        //~v57GI~
//***********************************************************************//~v57GI~
//***********************************************************************//~v57GI~
                                                                   //~v57GI~
#include <stdio.h>                                                 //~v57GI~
#include <string.h>                                                //~v57GI~
#include <stdlib.h>                                                //~v57GI~
                                                                   //~v57GI~
                                                                   //~v57GI~
#include <ulib.h>                                                  //~v57GI~
#include <uerr.h>                                                  //~v57GI~
#define GLOBAL_EBC                                                 //~v660I~
#include <ucvext.h>                                                //~vbB9I~
#include <uicu.h>                                                  //~vbB9I~
#include <ucvext12.h>                                              //~vbB9I~
#include <ucvebc.h>                                                //~v57GI~
#include <ucvebc2.h>                                               //~v5edR~
#include <utf.h> //utfcvsetdefaultlocale                           //~v7dAR~
#include <ucvebc4.h>   //global                                    //~v69cM~
#include <udbcschk.h>                                              //~v57SI~
#include <ufile5.h>                                                //~v68hI~
#include <utrace.h>                                                //~v5mPI~
                                                                   //~v57GI~
#if 0                                                              //~v57VI~
//**************************************************************** //~v57GI~
// abcdefghijklmnopqrstuvwxyz                                      //~v57SI~
// ±≤≥¥µ∂∑∏π¿¡¬√ƒ≈∆«»ÕŒœ–—“”‘                                      //~v57SI~
// ±≤≥¥µ∂∑∏π∫ªºΩæø¿¡¬√ƒ≈∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›                   //~v57SI~
// abcdefghi      jklmnopqr    stuvwxyz                            //~v57SI~
static unsigned char Skandl[256]=                                  //~v57SI~
//       0123456789abcdef                                          //~v57SI~
        "................"     //00-0f                             //~v57SI~
        "................"     //10-1f                             //~v57SI~
        "................"     //20-2f                             //~v57SI~
        "................"     //30-3f                             //~v57SI~
        " ..............."     //40-4f                             //~v57SI~
        "................"     //50-5f                             //~v57SI~
        ".±≤≥¥µ∂∑∏π¿¡¬√ƒ≈"     //60-6f  x61(a)-->x6f(o)            //~v57SI~
        "∆«»ÕŒœ–—“”‘....."     //70-7f  x70(p)-->x7a(z)            //~v57SI~
        "................"     //80-8f                             //~v57SI~
        "................"     //90-9f                             //~v57SI~
        "................"     //a0-af                             //~v57SI~
        ".abcdefghi......"     //b0-bf  xb1(±)-->xb9(π)            //~v57SI~
        "jklmnopqr....stu"     //c0-cf  xc0(¿)-->xc8(»),xcd(Õ)-->xcf(œ)//~v57SI~
        "vwxyz..........."     //d0-df  xd0(–)-->xd4(‘)            //~v57SI~
        "................"     //e0-ef                             //~v57SI~
        "................";    //f0-ff                             //~v57SI~
#endif                                                             //~v57VI~
#if 0                                                              //~v57TR~
static unsigned char Sebc2asc[256]=                                //~v57GI~
//       0123456789abcdef                                          //~v57GI~
        "................"     //00-0f                             //~v57GI~
        "................"     //10-1f                             //~v57GI~
        "................"     //20-2f                             //~v57GI~
        "................"     //30-3f                             //~v57GI~
        " ...........<(+|"     //40-4f                             //~v57GI~
        "&.........!.*);."     //50-5f                             //~v57GI~
        "-/.........,%_>?"     //60-6f                             //~v57GI~
        "..........:#@'=\""     //70-7f                            //~v57GI~
        "................"     //80-8f                             //~v57GI~
        "................"     //90-9f                             //~v57GI~
        "................"     //a0-af                             //~v57GI~
        "................"     //b0-bf                             //~v57GI~
        "{ABCDEFGHI......"     //c0-cf                             //~v57GI~
        "}JKLMNOPQR......"     //d0-df                             //~v57GI~
        "..STUVWXYZ......"     //e0-ef                             //~v57GI~
        "0123456789......";    //f0-ff                             //~v57GI~
#endif                                                             //~v57TI~
                                                                   //~v57TI~
//#define EBC_CR   0x0d                                            //~v5mPR~
//#define EBC_NL   0x15                                            //~v5mPR~
//#define EBC_PERIOD 0x4b                                          //~v5mPR~
                                                                   //~v57TI~
//EBCDIC common 94 char+space                                      //~v7d5I~
#ifdef BBB //not used                                              //~v7dAI~
static unsigned char Sebcbase[257]=                                //~v7d5R~
//       0123456789abcdef                                          //~v7d5I~
        "................"     //00-0f                             //~v7d5I~
        "................"     //10-1f                             //~v7d5I~
        "................"     //20-2f                             //~v7d5I~
        "................"     //30-3f                             //~v7d5I~
        " .........\xa2\x2e<(+|"  //40-4f                          //~v7d5I~
        "&.........!$*);\xac"     //50-5f                          //~v7d5I~
        "-/........\xa6,%_>?"     //60-6f                          //~v7d5I~
        ".........`:#@'=\""     //70-7f                            //~v7d5I~
        ".abcdefghi......"     //80-8f                             //~v7d5I~
        ".jklmnopqr......"     //90-9f                             //~v7d5I~
        ".~stuvwxyz......"     //a0-af                             //~v7d5I~
        "................"     //b0-bf                             //~v7d5I~
        "{ABCDEFGHI......"     //c0-cf                             //~v7d5I~
        "}JKLMNOPQR......"     //d0-df                             //~v7d5I~
        "\x5c.STUVWXYZ......"     //e0-ef                          //~v7d5I~
        "0123456789......";    //f0-ff                             //~v7d5I~
#endif                                                             //~v7dAI~
#if 0                                                              //~v57TI~
//EBCDIC common 58 char(missing lower-case letter and '!')         //~v57TI~
static unsigned char Sebcbase[256]=                                //~v57TI~
//       0123456789abcdef                                          //~v57TI~
        "................"     //00-0f                             //~v57TI~
        "................"     //10-1f                             //~v57TI~
        "................"     //20-2f                             //~v57TI~
        "................"     //30-3f                             //~v57TI~
        " ...........<(+."     //40-4f                             //~v57TI~
        "&...........*);."     //50-5f                             //~v57TI~
        "-/.........,%_>?"     //60-6f                             //~v57TI~
        "..........:#@'=\""     //70-7f                            //~v57TI~
        "................"     //80-8f                             //~v57TI~
        "................"     //90-9f                             //~v57TI~
        "................"     //a0-af                             //~v57TI~
        "................"     //b0-bf                             //~v57TI~
        ".ABCDEFGHI......"     //c0-cf                             //~v57TI~
        ".JKLMNOPQR......"     //d0-df                             //~v57TI~
        "..STUVWXYZ......"     //e0-ef                             //~v57TI~
        "0123456789......";    //f0-ff                             //~v57TI~
//**CP930:ì˙ñ{åÍâpêîÉJÉi =sbcs:290(EBCâpêîÉJÉi)+dbcs:300           //~v57TI~
//**CP939:ì˙ñ{åÍâpêîägí£ =sbcs:1027+dbcs:300                       //~v57TI~
//**CP5026:sbcs:290+dbcs:300                                       //~v57TI~
//**CP5035:sbcs:1027+dbcs:300                                      //~v57TI~
//EBCDIC-US base+33 char added:  a-z,$,bloken bar,`,~,{,},\(back slash)//~v57TI~
static unsigned char SebcUS[256]=                                  //~v57TI~
//       0123456789abcdef                                          //~v57TI~
//        "................"     //00-0f                             //~v57TI~//~v7d9R~
//        "................"     //10-1f                             //~v57TI~//~v7d9R~
//        "................"     //20-2f                             //~v57TI~//~v7d9R~
//        "................"     //30-3f                             //~v57TI~//~v7d9R~
/*00*/  0x00, 0x01, 0x02, 0x03, '.' , 0x09, '.' , 0x7f,            //~v7d9I~
/*08*/  '.' , '.' , '.' , 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,            //~v7d9I~
/*10*/  0x10, 0x11, 0x12, 0x13, '.' , '.' , 0x08, '.' ,            //~v7d9I~
/*18*/  0x18, 0x19, '.' , '.' , 0x1c, 0x1d, 0x1e, 0x1f,            //~v7d9I~
/*20*/  '.' , '.' , '.' , '.' , '.' , 0x0a, 0x17, 0x1b,            //~v7d9I~
/*28*/  '.' , '.' , '.' , '.' , '.' , 0x05, 0x06, 0x07,            //~v7d9I~
/*30*/  '.' , '.' , 0x16, '.' , '.' , '.' , '.' , 0x04,            //~v7d9I~
/*38*/  '.' , '.' , '.' , '.' , 0x14, 0x15, '.' , 0x1a,            //~v7d9I~
        " ...........<(+|"     //40-4f  4a:cent(no ascii)          //~v57TI~
        "&.........!$*);."     //50-5f  5f:not(no ascii)           //~v57TI~
        "-/.........,%_>?"     //60-6f  6a:broken bar(no ascii)    //~v57TI~
        ".........`:#@'=\""    //70-7f                             //~v57TR~
        ".abcdefghi......"     //80-8f                             //~v57TI~
        ".jklmnopqr......"     //90-9f                             //~v57TI~
        "..stuvwxyz......"     //a0-af  a1:childa(no ascii)        //~v57TI~
        "................"     //b0-bf                             //~v57TI~
        "{ABCDEFGHI......"     //c0-cf                             //~v57TI~
        "}JKLMNOPQR......"     //d0-df                             //~v57TI~
        "..STUVWXYZ......"     //e0-ef e0:backslash(no ascii)      //~v57TR~
        "0123456789......";    //f0-ff                             //~v57TI~
//EBCDIC-CP281(ì˙ñ{åÍâpè¨ï∂éö) EBC-US+4 char repled                //~v57TI~
//   4a:cent-->pond,5b:doller-->yen,a1:tilde->upper line,eo:backslash->doller//~v57TI~
static unsigned char SebcCP281[256]=                               //~v57TI~
//       0123456789abcdef                                          //~v57TI~
        "................"     //00-0f                             //~v57TI~
        "................"     //10-1f                             //~v57TI~
        "................"     //20-2f                             //~v57TI~
        "................"     //30-3f                             //~v57TI~
        " ...........<(+|"     //40-4f  4a:pond(no ascii)          //~v57TI~
        "&.........!\\*);."    //50-5f  5b(yen),5f:not(no ascii)   //~v57TR~
        "-/.........,%_>?"     //60-6f  6a:broken bar(no ascii)    //~v57TI~
        ".........`:#@'=\""    //70-7f                             //~v57TR~
        ".abcdefghi......"     //80-8f                             //~v57TI~
        ".jklmnopqr......"     //90-9f                             //~v57TI~
        ".~stuvwxyz......"     //a0-af  a1:upper line              //~v57TI~
        "................"     //b0-bf                             //~v57TI~
        "{ABCDEFGHI......"     //c0-cf                             //~v57TI~
        "}JKLMNOPQR......"     //d0-df                             //~v57TI~
        "$.STUVWXYZ......"     //e0-ef e0:doller                   //~v57TI~
        "0123456789......";    //f0-ff                             //~v57TI~
#endif                                                             //~v57VI~
//EBCDIC-CP290(ì˙ñ{åÍÉJÉi) cp281+(lowercase-->kana,                //~v57TI~
//            then added lower case: a-z,[,],~,^,cent,backslash,{,}//~v57TI~
//static unsigned char SebcCP290[256]=                               //~v57TI~//~v6hhR~
static unsigned char SebcCP290[257]=	//C4295 warning            //~v6hhI~
//       0123456789abcdef      default unprintable by cp932        //~vbB9R~
        "................"     //00-0f                             //~v57TI~
        "................"     //10-1f                             //~v57TI~
        "................"     //20-2f                             //~v57TI~
        "................"     //30-3f                             //~v57TI~
//      " °¢£§•¶ß®©..<(+|"     //40-4f  4a:pond(no ascii)          //~v5eqR~
//      " °¢£§•¶ß®©\xa0.<(+|"  //40-4f  4a:pond(-->a0)             //~v5eqI~//~v7d9R~
        " °¢£§•¶ß®©..<(+|"     //40-4f  4a:pond(no cp932)          //~v7d9R~
//      "&™´¨≠ÆØ.∞.!\\*);."    //50-5f  5b:yen,5f:not(no ascii)    //~v5eqR~
//      "&™´¨≠ÆØ.∞.!\\*);\xfd" //50-5f  5b:yen,5f:not(-->fd)       //~v5eqI~//~v7d9R~
        "&™´¨≠ÆØ.∞.!.*);."     //50-5f  5b:yen(no cp932),5f:not(no cp932)//~v7d9R~
        "-/abcdefgh.,%_>?"     //60-6f  6a:broken bar(no ascii)    //~v57TI~
        "[ijklmnop`:#@'=\""    //70-7f                             //~v57TI~
        "]±≤≥¥µ∂∑∏π∫qªºΩæ"     //80-8f                             //~v57TI~
//      "ø¿¡¬√ƒ≈∆«»…rs ÀÃ"     //90-9f                             //~v5eqR~
        "ø¿¡¬√ƒ≈∆«»…r. ÀÃ"     //90-9f  Bug creect("s")            //~v5eqI~
//      ".~ÕŒœ–—“”‘’s÷◊ÿŸ"     //a0-af  a0:tilde(no ascii),a1:upper line//~v5eqR~
//      "\xff~ÕŒœ–—“”‘’s÷◊ÿŸ"  //a0-af  a0:tilde(-->ff),a1:upper line//~v5eqI~//~v662R~
//      "~\xffÕŒœ–—“”‘’s÷◊ÿŸ"  //CP290:a0-af  a0:tilde(0x7e),a1:upper line(0xff)//~v662I~//~v7d9R~
        "~.ÕŒœ–—“”‘’s÷◊ÿŸ"     //a0-af  a0:tilde,a1:upper line(no cp932)//~v7d9R~
//      "^..tuvwxyz⁄€‹›ﬁﬂ"     //b0-bf  b1:cent(no ascii),b2:backslash(no ascii)//~v5eqR~
//      "^\x80\xfetuvwxyz⁄€‹›ﬁﬂ"  //b0-bf  b1:cent(-->80),b2:backslash(-->fe)//~v5eqI~//~v7d9R~
        "^.\\tuvwxyz⁄€‹›ﬁﬂ"     //b0-bf  b1:cent(no cp932),b2:backslash//~v7d9R~
        "{ABCDEFGHI......"     //c0-cf                             //~v57TI~
        "}JKLMNOPQR......"     //d0-df                             //~v57TI~
//      "$.STUVWXYZ......"     //e0-ef e0:doller                   //~v5eqR~
//      "$\x80STUVWXYZ......"  //e0-ef e0:doller,e1:euro(-->80:dup with cent)//~v5eqI~//~v7d9R~
        "$.STUVWXYZ......"     //e0-ef e0:doller,e1:euro(no cp932) //~v7d9R~
        "0123456789......";    //f0-ff                             //~v57TI~
#if 0                                                              //~v57VI~
//EBCDIC-CP1027(ì˙ñ{åÍâpè¨ï∂éöägí£) EBC-US+katakana                //~v57TI~
//   4a:cent-->pond,5b:doller-->yen,a1:tilde->upper line,eo:backslash->doller//~v57TI~
static unsigned char SebcCP1027[256]=                              //~v57TI~
//       0123456789abcdef                                          //~v57TI~
        "................"     //00-0f                             //~v57TI~
        "................"     //10-1f                             //~v57TI~
        "................"     //20-2f                             //~v57TI~
        "................"     //30-3f                             //~v57TI~
        " .°¢£§•¶ß®..<(+|"     //40-4f  4a:cent(no ascii)          //~v57TI~
        "&©™´¨≠ÆØ∞±!$*);."     //50-5f  5f:not(no ascii)           //~v57TR~
        "-/≤≥¥µ∂∑∏π.,%_>?"     //60-6f  6a:broken bar(no ascii)    //~v57TI~
        "∫ªºΩæø¿¡¬`:#@'=\""    //70-7f                             //~v57TR~
        ".abcdefghi√ƒ≈∆«»"     //80-8f                             //~v57TI~
        ".jklmnopqr… ÀÃÕŒ"     //90-9f                             //~v57TI~
        "~.stuvwxyzœ–—[“”"     //a0-af  a0:upper line,a1:tilde(no ascii)//~v57TI~
        "^.\\‘’÷◊ÿŸ⁄€‹›]ﬁﬂ"    //b0-bf  b1:pond(no ascii),b2:yen   //~v57TR~
        "{ABCDEFGHI......"     //c0-cf                             //~v57TI~
        "}JKLMNOPQR......"     //d0-df                             //~v57TI~
        "..STUVWXYZ......"     //e0-ef  e0:backslash               //~v57UR~
        "0123456789......";    //f0-ff                             //~v57TI~
#endif                                                             //~v57TI~
//EBCDIC-CP1027(ì˙ñ{åÍâpè¨ï∂éöägí£:EBC-US+katakana)+IBM942(conv cent,pond,not,backslash,tilde//~v57TR~
//   4a:cent-->pond,5b:doller-->yen,a1:tilde->upper line,eo:backslash->doller//~v57TI~
//static unsigned char SebcCP1027[256]=                              //~v57TI~//~v6hhR~
static unsigned char SebcCP1027[257]=	//C4295 warning            //~v6hhI~
//       0123456789abcdef                                          //~v57TI~
        "................"     //00-0f                             //~v57TI~
        "................"     //10-1f                             //~v57TI~
        "................"     //20-2f                             //~v57TI~
        "................"     //30-3f                             //~v57TI~
//      " .°¢£§•¶ß®\x80.<(+|"  //40-4f  4a:cent(-->x80)            //~v57TI~//~v7d9R~
        " .°¢£§•¶ß®..<(+|"  //40-4f  4a:cent(no cp932)             //~v7d9R~
//      "&©™´¨≠ÆØ∞±!$*);\xfd"  //50-5f  5f:not(-->xfd)             //~v57TR~//~v7d9R~
        "&©™´¨≠ÆØ∞±!$*);."  //50-5f  5f:not sign(no cp932)         //~v7d9R~
        "-/≤≥¥µ∂∑∏π.,%_>?"     //60-6f  6a:broken bar(no ascii)    //~v57TI~
        "∫ªºΩæø¿¡¬`:#@'=\""     //70-7f                            //~v57TI~
        ".abcdefghi√ƒ≈∆«»"     //80-8f                             //~v57TI~
        ".jklmnopqr… ÀÃÕŒ"     //90-9f                             //~v57TI~
//      "~\xffstuvwxyzœ–—[“”"  //a0-af  a0:upper line,a1:tilde(-->\xff)//~v57TR~//~v662R~
//      "\xff~stuvwxyzœ–—[“”"  //a0-af CP1027: a0:upper line(0xff),a1:tilde(-->0x7e)//~v662I~//~v7d9R~
        ".~stuvwxyzœ–—[“”"     //a0-af CP1027: a0:upper line(no cp932),a1:tilde(-->0x7e)//~v7d9R~
//      "^\xa0\\‘’÷◊ÿŸ⁄€‹›]ﬁﬂ" //b0-bf  b1:pond(-->xa0),b2:yen     //~v57TR~//~v7d9R~
        "^..‘’÷◊ÿŸ⁄€‹›]ﬁﬂ"     //b0-bf  b1:pond(no co932),b2:yen sign(no cp932)//~v7d9R~
        "{ABCDEFGHI......"     //c0-cf                             //~v57TI~
        "}JKLMNOPQR......"     //d0-df                             //~v57TI~
//      "\xfe.STUVWXYZ......"  //e0-ef e0:backslash(-->xfe)        //~v5enR~
//      "\xfe\x80STUVWXYZ......"  //e0-ef e0:backslash(-->xfe),e1:euro//~v5mRR~
//      "\xfe.STUVWXYZ......"  //e0-ef e0:backslash(-->xfe)        //~v5mRI~//~v7d9R~
        "\\.STUVWXYZ......"    //e0-ef e0:backslash(-->x5c), e1:euro sign(no cp932)//~v7d9R~
        "0123456789......";    //f0-ff                             //~v57TI~
static unsigned char Stbla2e[256];                                 //~v57UI~
                                                                   //~v57VI~
static unsigned char Stblctle2a[0x40]=	//ebcdic ctl char-->ascii(<0x80),ff for >=0x80  //~v57VI~//~v66LR~//~v7dPR~
{0x00,0x01,0x02,0x03,0xff,0x09,0xff,0x7f,//nul,soh,stx,etx,(pf),ht,(lc),del//~v57VI~
 0xff,0xff,0xff,0x0b,0x0c,0x0d,0x0e,0x0f,//(ge),(rlf),(smm),vt,ff,cr,so,si//~v57VI~
// 0x10,0x11,0x12,0x13,0xff,0x0a,0x08,0xff,//del,dc1,dc2,dc3(tm),(res),nl,bs,(il)//~v57VI~//~v66LR~
 0x10,0x11,0x12,0x13,0xff,0xff,0x08,0xff,//del,dc1,dc2,dc3(tm),(res),nl,bs,(il)//~v66LR~
//ebc-5-->u-0085-->sjis:None                                       //~v66LI~
 0x18,0x19,0xff,0xff,0x1c,0x1d,0x1e,0x1f,//can,em,(cc),(cui),ifs,igs,irs,ius//~v57VI~
// 0xff,0xff,0xff,0xff,0xff,0xff,0x17,0x1b,//(ds),(sos),(fs),-,(byp),(lf),etb,esc//~v57VI~//~v66LR~
 0xff,0xff,0xff,0xff,0xff,0x0a,0x17,0x1b,//(ds),(sos),(fs),-,(byp),(lf),etb,esc//~v66LI~
 0xff,0xff,0xff,0xff,0xff,0x05,0x06,0x07,//-,-,(sm),(cu2),-,enq,ack,bel//~v57VI~
 0xff,0xff,0x16,0xff,0xff,0xff,0xff,0x04,//-,-,syn,-,(pn),(rs),(uc),eot//~v57VI~
 0xff,0xff,0xff,0xff,0x14,0x15,0xff,0x1a //-,-,-,(cu3),dc4,nak,-,sub//~v57VI~
};                                                                 //~v57VI~
//static unsigned char Stblctla2e[0x80];  //ebcdic ctl cahr<--ascii  //~v57VI~//~v7dwR~
static unsigned char Stblctla2e[256];  //ebcdic ctl cahr<--ascii   //~v7dwI~
static unsigned char SebcCP290rev[256],SebcCP1027rev[256];         //~v57VI~
static unsigned char SebcCP037rev[256];                            //~v7dbI~
                                                                   //~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
static int Sswinite2u;                                             //~v660I~
static int S1stswa2e=0;   //for the case of external call      //~v660I~//~v66RI~
static USHORT Sibm1027e2u[256]/*eng letter*/,Sibm290e2u[256]/*katakana*/;//~v660R~
static USHORT Sibm037e2u[256];  //latin                            //~vbB9I~
static UCHAR *Sebc2asc037,*Sasc2ebc037;                            //~vbB9I~
//*********************************************                    //~v660I~
//*ebc->ucs tbl init for japanese                                  //~v660I~
//*ctl(0x00--0x3f is same for IBM1027 & IBM290,                    //~v66GI~//~v7daR~
//     and it is from s3270\ibm-1027_p100-1995                     //~v7daI~
//*********************************************                    //~v660I~
void ucvebcinite2uJ(void)                                          //~v660I~
{                                                                  //~v660I~
//IBM1027   Japanese EBCDIC English ext from ICU data\mappings     //~v660I~//~v66GR~
//x:\hercules\c3270-3.3\ibm-1027_p100-1995.ucm                     //~v7d9I~
	USHORT ibm1027e2u[]={                                          //~v660I~
            0x0000, 0x00,                                          //~v660I~
            0x0001, 0x01,                                          //~v660I~
            0x0002, 0x02,                                          //~v660I~
            0x0003, 0x03,                                          //~v660I~
            0x0004, 0x37,                                          //~v660I~
            0x0005, 0x2D,                                          //~v660I~
            0x0006, 0x2E,                                          //~v660I~
            0x0007, 0x2F,                                          //~v660I~
            0x0008, 0x16,                                          //~v660I~
            0x0009, 0x05,                                          //~v660I~
            0x000A, 0x25,                                          //~v660I~
            0x000B, 0x0B,                                          //~v660I~
            0x000C, 0x0C,                                          //~v660I~
            0x000D, 0x0D,                                          //~v660I~
            0x000E, 0x0E,                                          //~v660I~
            0x000F, 0x0F,                                          //~v660I~
            0x0010, 0x10,                                          //~v660I~
            0x0011, 0x11,                                          //~v660I~
            0x0012, 0x12,                                          //~v660I~
            0x0013, 0x13,                                          //~v660I~
            0x0014, 0x3C,                                          //~v660I~
            0x0015, 0x3D,                                          //~v660I~
            0x0016, 0x32,                                          //~v660I~
            0x0017, 0x26,                                          //~v660I~
            0x0018, 0x18,                                          //~v660I~
            0x0019, 0x19,                                          //~v660I~
            0x001A, 0x3F,                                          //~v660I~
            0x001B, 0x27,                                          //~v660I~
            0x001C, 0x1C,                                          //~v660I~
            0x001D, 0x1D,                                          //~v660I~
            0x001E, 0x1E,                                          //~v660I~
            0x001F, 0x1F,                                          //~v660I~
            0x0020, 0x40,                                          //~v660I~
            0x0021, 0x5A,                                          //~v660I~
            0x0022, 0x7F,                                          //~v660I~
            0x0023, 0x7B,                                          //~v660I~
            0x0024, 0x5B,                                          //~v660I~
            0x0025, 0x6C,                                          //~v660I~
            0x0026, 0x50,                                          //~v660I~
            0x0027, 0x7D,                                          //~v660I~
            0x0028, 0x4D,                                          //~v660I~
            0x0029, 0x5D,                                          //~v660I~
            0x002A, 0x5C,                                          //~v660I~
            0x002B, 0x4E,                                          //~v660I~
            0x002C, 0x6B,                                          //~v660I~
            0x002D, 0x60,                                          //~v660I~
            0x002E, 0x4B,                                          //~v660I~
            0x002F, 0x61,                                          //~v660I~
            0x0030, 0xF0,                                          //~v660I~
            0x0031, 0xF1,                                          //~v660I~
            0x0032, 0xF2,                                          //~v660I~
            0x0033, 0xF3,                                          //~v660I~
            0x0034, 0xF4,                                          //~v660I~
            0x0035, 0xF5,                                          //~v660I~
            0x0036, 0xF6,                                          //~v660I~
            0x0037, 0xF7,                                          //~v660I~
            0x0038, 0xF8,                                          //~v660I~
            0x0039, 0xF9,                                          //~v660I~
            0x003A, 0x7A,                                          //~v660I~
            0x003B, 0x5E,                                          //~v660I~
            0x003C, 0x4C,                                          //~v660I~
            0x003D, 0x7E,                                          //~v660I~
            0x003E, 0x6E,                                          //~v660I~
            0x003F, 0x6F,                                          //~v660I~
            0x0040, 0x7C,                                          //~v660I~
            0x0041, 0xC1,                                          //~v660I~
            0x0042, 0xC2,                                          //~v660I~
            0x0043, 0xC3,                                          //~v660I~
            0x0044, 0xC4,                                          //~v660I~
            0x0045, 0xC5,                                          //~v660I~
            0x0046, 0xC6,                                          //~v660I~
            0x0047, 0xC7,                                          //~v660I~
            0x0048, 0xC8,                                          //~v660I~
            0x0049, 0xC9,                                          //~v660I~
            0x004A, 0xD1,                                          //~v660I~
            0x004B, 0xD2,                                          //~v660I~
            0x004C, 0xD3,                                          //~v660I~
            0x004D, 0xD4,                                          //~v660I~
            0x004E, 0xD5,                                          //~v660I~
            0x004F, 0xD6,                                          //~v660I~
            0x0050, 0xD7,                                          //~v660I~
            0x0051, 0xD8,                                          //~v660I~
            0x0052, 0xD9,                                          //~v660I~
            0x0053, 0xE2,                                          //~v660I~
            0x0054, 0xE3,                                          //~v660I~
            0x0055, 0xE4,                                          //~v660I~
            0x0056, 0xE5,                                          //~v660I~
            0x0057, 0xE6,                                          //~v660I~
            0x0058, 0xE7,                                          //~v660I~
            0x0059, 0xE8,                                          //~v660I~
            0x005A, 0xE9,                                          //~v660I~
            0x005B, 0xAD,                                          //~v660I~
            0x005C, 0xE0,                                          //~v660I~
            0x005D, 0xBD,                                          //~v660I~
            0x005E, 0xB0,                                          //~v660I~
            0x005F, 0x6D,                                          //~v660I~
            0x0060, 0x79,                                          //~v660I~
            0x0061, 0x81,                                          //~v660I~
            0x0062, 0x82,                                          //~v660I~
            0x0063, 0x83,                                          //~v660I~
            0x0064, 0x84,                                          //~v660I~
            0x0065, 0x85,                                          //~v660I~
            0x0066, 0x86,                                          //~v660I~
            0x0067, 0x87,                                          //~v660I~
            0x0068, 0x88,                                          //~v660I~
            0x0069, 0x89,                                          //~v660I~
            0x006A, 0x91,                                          //~v660I~
            0x006B, 0x92,                                          //~v660I~
            0x006C, 0x93,                                          //~v660I~
            0x006D, 0x94,                                          //~v660I~
            0x006E, 0x95,                                          //~v660I~
            0x006F, 0x96,                                          //~v660I~
            0x0070, 0x97,                                          //~v660I~
            0x0071, 0x98,                                          //~v660I~
            0x0072, 0x99,                                          //~v660I~
            0x0073, 0xA2,                                          //~v660I~
            0x0074, 0xA3,                                          //~v660I~
            0x0075, 0xA4,                                          //~v660I~
            0x0076, 0xA5,                                          //~v660I~
            0x0077, 0xA6,                                          //~v660I~
            0x0078, 0xA7,                                          //~v660I~
            0x0079, 0xA8,                                          //~v660I~
            0x007A, 0xA9,                                          //~v660I~
            0x007B, 0xC0,                                          //~v660I~
            0x007C, 0x4F,                                          //~v660I~
            0x007D, 0xD0,                                          //~v660I~
            0x007E, 0xA1,                                          //~v660I~
            0x007F, 0x07,                                          //~v660I~
            0x0080, 0x20,                                          //~v660I~
            0x0081, 0x21,                                          //~v660I~
            0x0082, 0x22,                                          //~v660I~
            0x0083, 0x23,                                          //~v660I~
            0x0084, 0x24,                                          //~v660I~
            0x0085, 0x15,                                          //~v660I~
            0x0086, 0x06,                                          //~v660I~
            0x0087, 0x17,                                          //~v660I~
            0x0088, 0x28,                                          //~v660I~
            0x0089, 0x29,                                          //~v660I~
            0x008A, 0x2A,                                          //~v660I~
            0x008B, 0x2B,                                          //~v660I~
            0x008C, 0x2C,                                          //~v660I~
            0x008D, 0x09,                                          //~v660I~
            0x008E, 0x0A,                                          //~v660I~
            0x008F, 0x1B,                                          //~v660I~
            0x0090, 0x30,                                          //~v660I~
            0x0091, 0x31,                                          //~v660I~
            0x0092, 0x1A,                                          //~v660I~
            0x0093, 0x33,                                          //~v660I~
            0x0094, 0x34,                                          //~v660I~
            0x0095, 0x35,                                          //~v660I~
            0x0096, 0x36,                                          //~v660I~
            0x0097, 0x08,                                          //~v660I~
            0x0098, 0x38,                                          //~v660I~
            0x0099, 0x39,                                          //~v660I~
            0x009A, 0x3A,                                          //~v660I~
            0x009B, 0x3B,                                          //~v660I~
            0x009C, 0x04,                                          //~v660I~
            0x009D, 0x14,                                          //~v660I~
            0x009E, 0x3E,                                          //~v660I~
            0x009F, 0xFF,                                          //~v660I~
            0x00A2, 0x4A,                                          //~v660I~
            0x00A3, 0xB1,                                          //~v660I~
            0x00A5, 0xB2,                                          //~v660I~
            0x00AC, 0x5F,                                          //~v660I~
            0x203E, 0xA0,                                          //~v660I~
            0x20AC, 0xE1,      //EURO sign                         //~v66GI~
            0xFF61, 0x42,                                          //~v660I~
            0xFF62, 0x43,                                          //~v660I~
            0xFF63, 0x44,                                          //~v660I~
            0xFF64, 0x45,                                          //~v660I~
            0xFF65, 0x46,                                          //~v660I~
            0xFF66, 0x47,                                          //~v660I~
            0xFF67, 0x48,                                          //~v660I~
            0xFF68, 0x49,                                          //~v660I~
            0xFF69, 0x51,                                          //~v660I~
            0xFF6A, 0x52,                                          //~v660I~
            0xFF6B, 0x53,                                          //~v660I~
            0xFF6C, 0x54,                                          //~v660I~
            0xFF6D, 0x55,                                          //~v660I~
            0xFF6E, 0x56,                                          //~v660I~
            0xFF6F, 0x57,                                          //~v660I~
            0xFF70, 0x58,                                          //~v660I~
            0xFF71, 0x59,                                          //~v660I~
            0xFF72, 0x62,                                          //~v660I~
            0xFF73, 0x63,                                          //~v660I~
            0xFF74, 0x64,                                          //~v660I~
            0xFF75, 0x65,                                          //~v660I~
            0xFF76, 0x66,                                          //~v660I~
            0xFF77, 0x67,                                          //~v660I~
            0xFF78, 0x68,                                          //~v660I~
            0xFF79, 0x69,                                          //~v660I~
            0xFF7A, 0x70,                                          //~v660I~
            0xFF7B, 0x71,                                          //~v660I~
            0xFF7C, 0x72,                                          //~v660I~
            0xFF7D, 0x73,                                          //~v660I~
            0xFF7E, 0x74,                                          //~v660I~
            0xFF7F, 0x75,                                          //~v660I~
            0xFF80, 0x76,                                          //~v660I~
            0xFF81, 0x77,                                          //~v660I~
            0xFF82, 0x78,                                          //~v660I~
            0xFF83, 0x8A,                                          //~v660I~
            0xFF84, 0x8B,                                          //~v660I~
            0xFF85, 0x8C,                                          //~v660I~
            0xFF86, 0x8D,                                          //~v660I~
            0xFF87, 0x8E,                                          //~v660I~
            0xFF88, 0x8F,                                          //~v660I~
            0xFF89, 0x9A,                                          //~v660I~
            0xFF8A, 0x9B,                                          //~v660I~
            0xFF8B, 0x9C,                                          //~v660I~
            0xFF8C, 0x9D,                                          //~v660I~
            0xFF8D, 0x9E,                                          //~v660I~
            0xFF8E, 0x9F,                                          //~v660I~
            0xFF8F, 0xAA,                                          //~v660I~
            0xFF90, 0xAB,                                          //~v660I~
            0xFF91, 0xAC,                                          //~v660I~
            0xFF92, 0xAE,                                          //~v660I~
            0xFF93, 0xAF,                                          //~v660I~
            0xFF94, 0xB3,                                          //~v660I~
            0xFF95, 0xB4,                                          //~v660I~
            0xFF96, 0xB5,                                          //~v660I~
            0xFF97, 0xB6,                                          //~v660I~
            0xFF98, 0xB7,                                          //~v660I~
            0xFF99, 0xB8,                                          //~v660I~
            0xFF9A, 0xB9,                                          //~v660I~
            0xFF9B, 0xBA,                                          //~v660I~
            0xFF9C, 0xBB,                                          //~v660I~
            0xFF9D, 0xBC,                                          //~v660I~
            0xFF9E, 0xBE,                                          //~v660I~
            0xFF9F, 0xBF                                           //~v660I~
            };                                                     //~v660I~
//CP290   Japanese EBCDIC katakana ext                             //~v660I~
	USHORT ibm290e2u[]={                                           //~v660I~
            0x0000, 0x00,                                          //~v660I~
            0x0001, 0x01,                                          //~v660I~
            0x0002, 0x02,                                          //~v660I~
            0x0003, 0x03,                                          //~v660I~
            0x0004, 0x37,                                          //~v660I~
            0x0005, 0x2D,                                          //~v660I~
            0x0006, 0x2E,                                          //~v660I~
            0x0007, 0x2F,                                          //~v660I~
            0x0008, 0x16,                                          //~v660I~
            0x0009, 0x05,                                          //~v660I~
            0x000A, 0x25,                                          //~v660I~
            0x000B, 0x0B,                                          //~v660I~
            0x000C, 0x0C,                                          //~v660I~
            0x000D, 0x0D,                                          //~v660I~
            0x000E, 0x0E,                                          //~v660I~
            0x000F, 0x0F,                                          //~v660I~
            0x0010, 0x10,                                          //~v660I~
            0x0011, 0x11,                                          //~v660I~
            0x0012, 0x12,                                          //~v660I~
            0x0013, 0x13,                                          //~v660I~
            0x0014, 0x3C,                                          //~v660I~
            0x0015, 0x3D,                                          //~v660I~
            0x0016, 0x32,                                          //~v660I~
            0x0017, 0x26,                                          //~v660I~
            0x0018, 0x18,                                          //~v660I~
            0x0019, 0x19,                                          //~v660I~
            0x001A, 0x3F,                                          //~v660I~
            0x001B, 0x27,                                          //~v660I~
            0x001C, 0x1C,                                          //~v660I~
            0x001D, 0x1D,                                          //~v660I~
            0x001E, 0x1E,                                          //~v660I~
            0x001F, 0x1F,                                          //~v660I~
            0x0020, 0x40,                                          //~v660I~
            0x0021, 0x5A,                                          //~v660I~
            0x0022, 0x7F,                                          //~v660I~
            0x0023, 0x7B,                                          //~v660I~
            0x0024, 0xE0,                                          //~v660I~
            0x0025, 0x6C,                                          //~v660I~
            0x0026, 0x50,                                          //~v660I~
            0x0027, 0x7D,                                          //~v660I~
            0x0028, 0x4D,                                          //~v660I~
            0x0029, 0x5D,                                          //~v660I~
            0x002A, 0x5C,                                          //~v660I~
            0x002B, 0x4E,                                          //~v660I~
            0x002C, 0x6B,                                          //~v660I~
            0x002D, 0x60,                                          //~v660I~
            0x002E, 0x4B,                                          //~v660I~
            0x002F, 0x61,                                          //~v660I~
            0x0030, 0xF0,                                          //~v660I~
            0x0031, 0xF1,                                          //~v660I~
            0x0032, 0xF2,                                          //~v660I~
            0x0033, 0xF3,                                          //~v660I~
            0x0034, 0xF4,                                          //~v660I~
            0x0035, 0xF5,                                          //~v660I~
            0x0036, 0xF6,                                          //~v660I~
            0x0037, 0xF7,                                          //~v660I~
            0x0038, 0xF8,                                          //~v660I~
            0x0039, 0xF9,                                          //~v660I~
            0x003A, 0x7A,                                          //~v660I~
            0x003B, 0x5E,                                          //~v660I~
            0x003C, 0x4C,                                          //~v660I~
            0x003D, 0x7E,                                          //~v660I~
            0x003E, 0x6E,                                          //~v660I~
            0x003F, 0x6F,                                          //~v660I~
            0x0040, 0x7C,                                          //~v660I~
            0x0041, 0xC1,                                          //~v660I~
            0x0042, 0xC2,                                          //~v660I~
            0x0043, 0xC3,                                          //~v660I~
            0x0044, 0xC4,                                          //~v660I~
            0x0045, 0xC5,                                          //~v660I~
            0x0046, 0xC6,                                          //~v660I~
            0x0047, 0xC7,                                          //~v660I~
            0x0048, 0xC8,                                          //~v660I~
            0x0049, 0xC9,                                          //~v660I~
            0x004A, 0xD1,                                          //~v660I~
            0x004B, 0xD2,                                          //~v660I~
            0x004C, 0xD3,                                          //~v660I~
            0x004D, 0xD4,                                          //~v660I~
            0x004E, 0xD5,                                          //~v660I~
            0x004F, 0xD6,                                          //~v660I~
            0x0050, 0xD7,                                          //~v660I~
            0x0051, 0xD8,                                          //~v660I~
            0x0052, 0xD9,                                          //~v660I~
            0x0053, 0xE2,                                          //~v660I~
            0x0054, 0xE3,                                          //~v660I~
            0x0055, 0xE4,                                          //~v660I~
            0x0056, 0xE5,                                          //~v660I~
            0x0057, 0xE6,                                          //~v660I~
            0x0058, 0xE7,                                          //~v660I~
            0x0059, 0xE8,                                          //~v660I~
            0x005A, 0xE9,                                          //~v660I~
            0x005B, 0x70,                                          //~v660I~
            0x005C, 0xB2,                                          //~v660I~
            0x005D, 0x80,                                          //~v660I~
            0x005E, 0xB0,                                          //~v660I~
            0x005F, 0x6D,                                          //~v660I~
            0x0060, 0x79,                                          //~v660I~
            0x0061, 0x62,                                          //~v660I~
            0x0062, 0x63,                                          //~v660I~
            0x0063, 0x64,                                          //~v660I~
            0x0064, 0x65,                                          //~v660I~
            0x0065, 0x66,                                          //~v660I~
            0x0066, 0x67,                                          //~v660I~
            0x0067, 0x68,                                          //~v660I~
            0x0068, 0x69,                                          //~v660I~
            0x0069, 0x71,                                          //~v660I~
            0x006A, 0x72,                                          //~v660I~
            0x006B, 0x73,                                          //~v660I~
            0x006C, 0x74,                                          //~v660I~
            0x006D, 0x75,                                          //~v660I~
            0x006E, 0x76,                                          //~v660I~
            0x006F, 0x77,                                          //~v660I~
            0x0070, 0x78,                                          //~v660I~
            0x0071, 0x8B,                                          //~v660I~
            0x0072, 0x9B,                                          //~v660I~
            0x0073, 0xAB,                                          //~v660I~
            0x0074, 0xB3,                                          //~v660I~
            0x0075, 0xB4,                                          //~v660I~
            0x0076, 0xB5,                                          //~v660I~
            0x0077, 0xB6,                                          //~v660I~
            0x0078, 0xB7,                                          //~v660I~
            0x0079, 0xB8,                                          //~v660I~
            0x007A, 0xB9,                                          //~v660I~
            0x007B, 0xC0,                                          //~v660I~
            0x007C, 0x4F,                                          //~v660I~
            0x007D, 0xD0,                                          //~v660I~
            0x007E, 0xA0,                                          //~v660I~
            0x007F, 0x07,                                          //~v660I~
            0x0080, 0x20,                                          //~v660I~
            0x0081, 0x21,                                          //~v660I~
            0x0082, 0x22,                                          //~v660I~
            0x0083, 0x23,                                          //~v660I~
            0x0084, 0x24,                                          //~v660I~
            0x0085, 0x15,                                          //~v660I~
            0x0086, 0x06,                                          //~v660I~
            0x0087, 0x17,                                          //~v660I~
            0x0088, 0x28,                                          //~v660I~
            0x0089, 0x29,                                          //~v660I~
            0x008A, 0x2A,                                          //~v660I~
            0x008B, 0x2B,                                          //~v660I~
            0x008C, 0x2C,                                          //~v660I~
            0x008D, 0x09,                                          //~v660I~
            0x008E, 0x0A,                                          //~v660I~
            0x008F, 0x1B,                                          //~v660I~
            0x0090, 0x30,                                          //~v660I~
            0x0091, 0x31,                                          //~v660I~
            0x0092, 0x1A,                                          //~v660I~
            0x0093, 0x33,                                          //~v660I~
            0x0094, 0x34,                                          //~v660I~
            0x0095, 0x35,                                          //~v660I~
            0x0096, 0x36,                                          //~v660I~
            0x0097, 0x08,                                          //~v660I~
            0x0098, 0x38,                                          //~v660I~
            0x0099, 0x39,                                          //~v660I~
            0x009A, 0x3A,                                          //~v660I~
            0x009B, 0x3B,                                          //~v660I~
            0x009C, 0x04,                                          //~v660I~
            0x009D, 0x14,                                          //~v660I~
            0x009E, 0x3E,                                          //~v660I~
            0x009F, 0xFF,                                          //~v660I~
            0x00A2, 0xB1,                                          //~v660I~
            0x00A3, 0x4A,                                          //~v660I~
            0x00A5, 0x5B,                                          //~v660I~
            0x00AC, 0x5F,                                          //~v660I~
            0x203E, 0xA1,                                          //~v660I~
            0x20AC, 0xE1,      //EURO sign                         //~v66GI~
            0xFF61, 0x41,                                          //~v660I~
            0xFF62, 0x42,                                          //~v660I~
            0xFF63, 0x43,                                          //~v660I~
            0xFF64, 0x44,                                          //~v660I~
            0xFF65, 0x45,                                          //~v660I~
            0xFF66, 0x46,                                          //~v660I~
            0xFF67, 0x47,                                          //~v660I~
            0xFF68, 0x48,                                          //~v660I~
            0xFF69, 0x49,                                          //~v660I~
            0xFF6A, 0x51,                                          //~v660I~
            0xFF6B, 0x52,                                          //~v660I~
            0xFF6C, 0x53,                                          //~v660I~
            0xFF6D, 0x54,                                          //~v660I~
            0xFF6E, 0x55,                                          //~v660I~
            0xFF6F, 0x56,                                          //~v660I~
            0xFF70, 0x58,                                          //~v660I~
            0xFF71, 0x81,                                          //~v660I~
            0xFF72, 0x82,                                          //~v660I~
            0xFF73, 0x83,                                          //~v660I~
            0xFF74, 0x84,                                          //~v660I~
            0xFF75, 0x85,                                          //~v660I~
            0xFF76, 0x86,                                          //~v660I~
            0xFF77, 0x87,                                          //~v660I~
            0xFF78, 0x88,                                          //~v660I~
            0xFF79, 0x89,                                          //~v660I~
            0xFF7A, 0x8A,                                          //~v660I~
            0xFF7B, 0x8C,                                          //~v660I~
            0xFF7C, 0x8D,                                          //~v660I~
            0xFF7D, 0x8E,                                          //~v660I~
            0xFF7E, 0x8F,                                          //~v660I~
            0xFF7F, 0x90,                                          //~v660I~
            0xFF80, 0x91,                                          //~v660I~
            0xFF81, 0x92,                                          //~v660I~
            0xFF82, 0x93,                                          //~v660I~
            0xFF83, 0x94,                                          //~v660I~
            0xFF84, 0x95,                                          //~v660I~
            0xFF85, 0x96,                                          //~v660I~
            0xFF86, 0x97,                                          //~v660I~
            0xFF87, 0x98,                                          //~v660I~
            0xFF88, 0x99,                                          //~v660I~
            0xFF89, 0x9A,                                          //~v660I~
            0xFF8A, 0x9D,                                          //~v660I~
            0xFF8B, 0x9E,                                          //~v660I~
            0xFF8C, 0x9F,                                          //~v660I~
            0xFF8D, 0xA2,                                          //~v660I~
            0xFF8E, 0xA3,                                          //~v660I~
            0xFF8F, 0xA4,                                          //~v660I~
            0xFF90, 0xA5,                                          //~v660I~
            0xFF91, 0xA6,                                          //~v660I~
            0xFF92, 0xA7,                                          //~v660I~
            0xFF93, 0xA8,                                          //~v660I~
            0xFF94, 0xA9,                                          //~v660I~
            0xFF95, 0xAA,                                          //~v660I~
            0xFF96, 0xAC,                                          //~v660I~
            0xFF97, 0xAD,                                          //~v660I~
            0xFF98, 0xAE,                                          //~v660I~
            0xFF99, 0xAF,                                          //~v660I~
            0xFF9A, 0xBA,                                          //~v660I~
            0xFF9B, 0xBB,                                          //~v660I~
            0xFF9C, 0xBC,                                          //~v660I~
            0xFF9D, 0xBD,                                          //~v660I~
            0xFF9E, 0xBE,                                          //~v660I~
            0xFF9F, 0xBF                                           //~v660I~
			};                                                     //~v660I~
    int entno,ebc;                                                 //~v660R~
    USHORT *pus,usucs;                                             //~v660I~
//******************                                               //~v660I~
	Sswinite2u=1;                                                  //~v660I~
    for (entno=sizeof(ibm1027e2u)/sizeof(USHORT)/2,pus=ibm1027e2u;entno>0;entno--)//~v660I~
    {                                                              //~v660I~
    	usucs=*pus++;                                              //~v660I~
        ebc=(int)*pus++;                                           //~v660R~
        Sibm1027e2u[ebc]=usucs;                                    //~v660I~
    }                                                              //~v660I~
    for (entno=sizeof(ibm290e2u)/sizeof(USHORT)/2,pus=ibm290e2u;entno>0;entno--)//~v660I~
    {                                                              //~v660I~
    	usucs=*pus++;                                              //~v660I~
        ebc=(int)*pus++;                                           //~v660R~
        Sibm290e2u[ebc]=usucs;                                     //~v660I~
    }                                                              //~v660I~
    UTRACED("Sibm1027e2u",Sibm1027e2u,sizeof(Sibm1027e2u));            //~v660R~//~v66GR~//~v7dbR~
    UTRACED("Sibm290e2u",Sibm290e2u,sizeof(Sibm290e2u));              //~v660R~//~v66GR~//~v7dbR~
    return;                                                        //~v660I~
}//ucvebcinite2uJ                                                  //~v660I~
#endif                                                             //~v660I~
//*********************************************                    //~vbB9I~
void ucvebcinite2u037(void)                                        //~vbB9I~
{                                                                  //~vbB9I~
//*cp037 ucs latin1 ucs and ebc                                    //~vbB9I~
	USHORT ibm037e2u[]={                                           //~vbB9I~
            0x0000,  0x00,                                         //~vbB9I~
            0x0001,  0x01,                                         //~vbB9I~
            0x0002,  0x02,                                         //~vbB9I~
            0x0003,  0x03,                                         //~vbB9I~
            0x0004,  0x37,                                         //~vbB9I~
            0x0005,  0x2d,                                         //~vbB9I~
            0x0006,  0x2e,                                         //~vbB9I~
            0x0007,  0x2f,                                         //~vbB9I~
            0x0008,  0x16,                                         //~vbB9I~
            0x0009,  0x05,                                         //~vbB9I~
            0x000a,  0x25,                                         //~vbB9I~
            0x000b,  0x0b,                                         //~vbB9I~
            0x000c,  0x0c,                                         //~vbB9I~
            0x000d,  0x0d,                                         //~vbB9I~
            0x000e,  0x0e,                                         //~vbB9I~
            0x000f,  0x0f,                                         //~vbB9I~
            0x0010,  0x10,                                         //~vbB9I~
            0x0011,  0x11,                                         //~vbB9I~
            0x0012,  0x12,                                         //~vbB9I~
            0x0013,  0x13,                                         //~vbB9I~
            0x0014,  0x3c,                                         //~vbB9I~
            0x0015,  0x3d,                                         //~vbB9I~
            0x0016,  0x32,                                         //~vbB9I~
            0x0017,  0x26,                                         //~vbB9I~
            0x0018,  0x18,                                         //~vbB9I~
            0x0019,  0x19,                                         //~vbB9I~
            0x001a,  0x3f,                                         //~vbB9I~
            0x001b,  0x27,                                         //~vbB9I~
            0x001c,  0x1c,                                         //~vbB9I~
            0x001d,  0x1d,                                         //~vbB9I~
            0x001e,  0x1e,                                         //~vbB9I~
            0x001f,  0x1f,                                         //~vbB9I~
            0x0020,  0x40,                                         //~vbB9I~
            0x0021,  0x5a,                                         //~vbB9I~
            0x0022,  0x7f,                                         //~vbB9I~
            0x0023,  0x7b,                                         //~vbB9I~
            0x0024,  0x5b,                                         //~vbB9I~
            0x0025,  0x6c,                                         //~vbB9I~
            0x0026,  0x50,                                         //~vbB9I~
            0x0027,  0x7d,                                         //~vbB9I~
            0x0028,  0x4d,                                         //~vbB9I~
            0x0029,  0x5d,                                         //~vbB9I~
            0x002a,  0x5c,                                         //~vbB9I~
            0x002b,  0x4e,                                         //~vbB9I~
            0x002c,  0x6b,                                         //~vbB9I~
            0x002d,  0x60,                                         //~vbB9I~
            0x002e,  0x4b,                                         //~vbB9I~
            0x002f,  0x61,                                         //~vbB9I~
            0x0030,  0xf0,                                         //~vbB9I~
            0x0031,  0xf1,                                         //~vbB9I~
            0x0032,  0xf2,                                         //~vbB9I~
            0x0033,  0xf3,                                         //~vbB9I~
            0x0034,  0xf4,                                         //~vbB9I~
            0x0035,  0xf5,                                         //~vbB9I~
            0x0036,  0xf6,                                         //~vbB9I~
            0x0037,  0xf7,                                         //~vbB9I~
            0x0038,  0xf8,                                         //~vbB9I~
            0x0039,  0xf9,                                         //~vbB9I~
            0x003a,  0x7a,                                         //~vbB9I~
            0x003b,  0x5e,                                         //~vbB9I~
            0x003c,  0x4c,                                         //~vbB9I~
            0x003d,  0x7e,                                         //~vbB9I~
            0x003e,  0x6e,                                         //~vbB9I~
            0x003f,  0x6f,                                         //~vbB9I~
            0x0040,  0x7c,                                         //~vbB9I~
            0x0041,  0xc1,                                         //~vbB9I~
            0x0042,  0xc2,                                         //~vbB9I~
            0x0043,  0xc3,                                         //~vbB9I~
            0x0044,  0xc4,                                         //~vbB9I~
            0x0045,  0xc5,                                         //~vbB9I~
            0x0046,  0xc6,                                         //~vbB9I~
            0x0047,  0xc7,                                         //~vbB9I~
            0x0048,  0xc8,                                         //~vbB9I~
            0x0049,  0xc9,                                         //~vbB9I~
            0x004a,  0xd1,                                         //~vbB9I~
            0x004b,  0xd2,                                         //~vbB9I~
            0x004c,  0xd3,                                         //~vbB9I~
            0x004d,  0xd4,                                         //~vbB9I~
            0x004e,  0xd5,                                         //~vbB9I~
            0x004f,  0xd6,                                         //~vbB9I~
            0x0050,  0xd7,                                         //~vbB9I~
            0x0051,  0xd8,                                         //~vbB9I~
            0x0052,  0xd9,                                         //~vbB9I~
            0x0053,  0xe2,                                         //~vbB9I~
            0x0054,  0xe3,                                         //~vbB9I~
            0x0055,  0xe4,                                         //~vbB9I~
            0x0056,  0xe5,                                         //~vbB9I~
            0x0057,  0xe6,                                         //~vbB9I~
            0x0058,  0xe7,                                         //~vbB9I~
            0x0059,  0xe8,                                         //~vbB9I~
            0x005a,  0xe9,                                         //~vbB9I~
            0x005b,  0xba,                                         //~vbB9I~
            0x005c,  0xe0,                                         //~vbB9I~
            0x005d,  0xbb,                                         //~vbB9I~
            0x005e,  0xb0,                                         //~vbB9I~
            0x005f,  0x6d,                                         //~vbB9I~
            0x0060,  0x79,                                         //~vbB9I~
            0x0061,  0x81,                                         //~vbB9I~
            0x0062,  0x82,                                         //~vbB9I~
            0x0063,  0x83,                                         //~vbB9I~
            0x0064,  0x84,                                         //~vbB9I~
            0x0065,  0x85,                                         //~vbB9I~
            0x0066,  0x86,                                         //~vbB9I~
            0x0067,  0x87,                                         //~vbB9I~
            0x0068,  0x88,                                         //~vbB9I~
            0x0069,  0x89,                                         //~vbB9I~
            0x006a,  0x91,                                         //~vbB9I~
            0x006b,  0x92,                                         //~vbB9I~
            0x006c,  0x93,                                         //~vbB9I~
            0x006d,  0x94,                                         //~vbB9I~
            0x006e,  0x95,                                         //~vbB9I~
            0x006f,  0x96,                                         //~vbB9I~
            0x0070,  0x97,                                         //~vbB9I~
            0x0071,  0x98,                                         //~vbB9I~
            0x0072,  0x99,                                         //~vbB9I~
            0x0073,  0xa2,                                         //~vbB9I~
            0x0074,  0xa3,                                         //~vbB9I~
            0x0075,  0xa4,                                         //~vbB9I~
            0x0076,  0xa5,                                         //~vbB9I~
            0x0077,  0xa6,                                         //~vbB9I~
            0x0078,  0xa7,                                         //~vbB9I~
            0x0079,  0xa8,                                         //~vbB9I~
            0x007a,  0xa9,                                         //~vbB9I~
            0x007b,  0xc0,                                         //~vbB9I~
            0x007c,  0x4f,                                         //~vbB9I~
            0x007d,  0xd0,                                         //~vbB9I~
            0x007e,  0xa1,                                         //~vbB9I~
            0x007f,  0x07,                                         //~vbB9I~
            0x0080,  0x20,                                         //~vbB9I~
            0x0081,  0x21,                                         //~vbB9I~
            0x0082,  0x22,                                         //~vbB9I~
            0x0083,  0x23,                                         //~vbB9I~
            0x0084,  0x24,                                         //~vbB9I~
            0x0085,  0x15,                                         //~vbB9I~
            0x0086,  0x06,                                         //~vbB9I~
            0x0087,  0x17,                                         //~vbB9I~
            0x0088,  0x28,                                         //~vbB9I~
            0x0089,  0x29,                                         //~vbB9I~
            0x008a,  0x2a,                                         //~vbB9I~
            0x008b,  0x2b,                                         //~vbB9I~
            0x008c,  0x2c,                                         //~vbB9I~
            0x008d,  0x09,                                         //~vbB9I~
            0x008e,  0x0a,                                         //~vbB9I~
            0x008f,  0x1b,                                         //~vbB9I~
            0x0090,  0x30,                                         //~vbB9I~
            0x0091,  0x31,                                         //~vbB9I~
            0x0092,  0x1a,                                         //~vbB9I~
            0x0093,  0x33,                                         //~vbB9I~
            0x0094,  0x34,                                         //~vbB9I~
            0x0095,  0x35,                                         //~vbB9I~
            0x0096,  0x36,                                         //~vbB9I~
            0x0097,  0x08,                                         //~vbB9I~
            0x0098,  0x38,                                         //~vbB9I~
            0x0099,  0x39,                                         //~vbB9I~
            0x009a,  0x3a,                                         //~vbB9I~
            0x009b,  0x3b,                                         //~vbB9I~
            0x009c,  0x04,                                         //~vbB9I~
            0x009d,  0x14,                                         //~vbB9I~
            0x009e,  0x3e,                                         //~vbB9I~
            0x009f,  0xff,                                         //~vbB9R~
            0x00a0,  0x41,                                         //~vbB9I~
            0x00a1,  0xaa,                                         //~vbB9I~
            0x00a2,  0x4a,                                         //~vbB9I~
            0x00a3,  0xb1,                                         //~vbB9I~
//ccsid 1140 is ebc9f-->20ac. cp037 is 9f-->a4                     //~v7dPI~
            0x00a4,  0x9f,                                         //~vbB9I~
            0x00a5,  0xb2,                                         //~vbB9I~
            0x00a6,  0x6a,                                         //~vbB9I~
            0x00a7,  0xb5,                                         //~vbB9I~
            0x00a8,  0xbd,                                         //~vbB9I~
            0x00a9,  0xb4,                                         //~vbB9I~
            0x00aa,  0x9a,                                         //~vbB9I~
            0x00ab,  0x8a,                                         //~vbB9I~
            0x00ac,  0x5f,                                         //~vbB9I~
            0x00ad,  0xca,                                         //~vbB9I~
            0x00ae,  0xaf,                                         //~vbB9I~
            0x00af,  0xbc,                                         //~vbB9I~
            0x00b0,  0x90,                                         //~vbB9I~
            0x00b1,  0x8f,                                         //~vbB9I~
            0x00b2,  0xea,                                         //~vbB9I~
            0x00b3,  0xfa,                                         //~vbB9I~
            0x00b4,  0xbe,                                         //~vbB9I~
            0x00b5,  0xa0,                                         //~vbB9I~
            0x00b6,  0xb6,                                         //~vbB9I~
            0x00b7,  0xb3,                                         //~vbB9I~
            0x00b8,  0x9d,                                         //~vbB9I~
            0x00b9,  0xda,                                         //~vbB9I~
            0x00ba,  0x9b,                                         //~vbB9I~
            0x00bb,  0x8b,                                         //~vbB9I~
            0x00bc,  0xb7,                                         //~vbB9I~
            0x00bd,  0xb8,                                         //~vbB9I~
            0x00be,  0xb9,                                         //~vbB9I~
            0x00bf,  0xab,                                         //~vbB9I~
            0x00c0,  0x64,                                         //~vbB9I~
            0x00c1,  0x65,                                         //~vbB9I~
            0x00c2,  0x62,                                         //~vbB9I~
            0x00c3,  0x66,                                         //~vbB9I~
            0x00c4,  0x63,                                         //~vbB9I~
            0x00c5,  0x67,                                         //~vbB9I~
            0x00c6,  0x9e,                                         //~vbB9I~
            0x00c7,  0x68,                                         //~vbB9I~
            0x00c8,  0x74,                                         //~vbB9I~
            0x00c9,  0x71,                                         //~vbB9I~
            0x00ca,  0x72,                                         //~vbB9I~
            0x00cb,  0x73,                                         //~vbB9I~
            0x00cc,  0x78,                                         //~vbB9I~
            0x00cd,  0x75,                                         //~vbB9I~
            0x00ce,  0x76,                                         //~vbB9I~
            0x00cf,  0x77,                                         //~vbB9I~
            0x00d0,  0xac,                                         //~vbB9I~
            0x00d1,  0x69,                                         //~vbB9I~
            0x00d2,  0xed,                                         //~vbB9I~
            0x00d3,  0xee,                                         //~vbB9I~
            0x00d4,  0xeb,                                         //~vbB9I~
            0x00d5,  0xef,                                         //~vbB9I~
            0x00d6,  0xec,                                         //~vbB9I~
            0x00d7,  0xbf,                                         //~vbB9I~
            0x00d8,  0x80,                                         //~vbB9I~
            0x00d9,  0xfd,                                         //~vbB9I~
            0x00da,  0xfe,                                         //~vbB9I~
            0x00db,  0xfb,                                         //~vbB9I~
            0x00dc,  0xfc,                                         //~vbB9I~
            0x00dd,  0xad,                                         //~vbB9I~
            0x00de,  0xae,                                         //~vbB9I~
            0x00df,  0x59,                                         //~vbB9I~
            0x00e0,  0x44,                                         //~vbB9I~
            0x00e1,  0x45,                                         //~vbB9I~
            0x00e2,  0x42,                                         //~vbB9I~
            0x00e3,  0x46,                                         //~vbB9I~
            0x00e4,  0x43,                                         //~vbB9I~
            0x00e5,  0x47,                                         //~vbB9I~
            0x00e6,  0x9c,                                         //~vbB9I~
            0x00e7,  0x48,                                         //~vbB9I~
            0x00e8,  0x54,                                         //~vbB9I~
            0x00e9,  0x51,                                         //~vbB9I~
            0x00ea,  0x52,                                         //~vbB9I~
            0x00eb,  0x53,                                         //~vbB9I~
            0x00ec,  0x58,                                         //~vbB9I~
            0x00ed,  0x55,                                         //~vbB9I~
            0x00ee,  0x56,                                         //~vbB9I~
            0x00ef,  0x57,                                         //~vbB9I~
            0x00f0,  0x8c,                                         //~vbB9I~
            0x00f1,  0x49,                                         //~vbB9I~
            0x00f2,  0xcd,                                         //~vbB9I~
            0x00f3,  0xce,                                         //~vbB9I~
            0x00f4,  0xcb,                                         //~vbB9I~
            0x00f5,  0xcf,                                         //~vbB9I~
            0x00f6,  0xcc,                                         //~vbB9I~
            0x00f7,  0xe1,                                         //~vbB9I~
            0x00f8,  0x70,                                         //~vbB9I~
            0x00f9,  0xdd,                                         //~vbB9I~
            0x00fa,  0xde,                                         //~vbB9I~
            0x00fb,  0xdb,                                         //~vbB9I~
            0x00fc,  0xdc,                                         //~vbB9I~
            0x00fd,  0x8d,                                         //~vbB9I~
            0x00fe,  0x8e,                                         //~vbB9I~
            0x00ff,  0xdf                                          //~vbB9I~
            };                                                     //~vbB9I~
    int entno,ebc;                                                 //~vbB9I~
    USHORT *pus,usucs;                                             //~vbB9I~
//******************                                               //~vbB9I~
    for (entno=sizeof(ibm037e2u)/sizeof(USHORT)/2,pus=ibm037e2u;entno>0;entno--)//~vbB9I~
    {                                                              //~vbB9I~
    	usucs=*pus++;                                              //~vbB9I~
        ebc=(int)*pus++;                                           //~vbB9I~
        Sibm037e2u[ebc]=usucs;                                     //~vbB9I~
    }                                                              //~vbB9I~
    UTRACED("Sibm037e2u",Sibm037e2u,sizeof(Sibm037e2u));           //~vbB9I~//~v7dbR~
    return;                                                        //~vbB9I~
}//ucvebcinite2u037                                                //~vbB9I~
//*********************************************                    //~vbB9M~
void ucvebcTables(UCHAR *Pebc2asc037,UCHAR *Pasc2ebc037)           //~vbB9M~
{                                                                  //~vbB9M~
    UTRACEP("%s:Sebc2asc037=%p,Sasc2ebc037=%p\n",UTT,Sebc2asc037,Sasc2ebc037);//~vbB9M~
	Sebc2asc037=Pebc2asc037; Sasc2ebc037=Pasc2ebc037;              //~vbB9M~
    UTRACED("Sebc2asc037",Sebc2asc037,256);                        //~vbB9M~
    UTRACED("Sasc2ebc037",Sasc2ebc037,256);                        //~vbB9M~
    ucvebcinite2u037();                                            //~vbB9I~
}                                                                  //~vbB9M~
//*******************************************************          //~v57UI~
//void ucvebcinita2e(void);                                        //~v5eqR~
//void ucvebcinita2e(int Popt);                                      //~v5eqI~//~v660R~
void ucvebcinitkandl(void);                                        //~v57VI~
//*******************************************************          //~v57GI~
//*dummy for lib(same name as file)						*          //~v57GI~
//*******************************************************          //~v57GI~
void ucvebc(void)                                                  //~v57GI~
{                                                                  //~v57GI~
	return;                                                        //~v57GI~
}//ucvebc                                                          //~v57GI~
#ifdef AAA     //no user                                           //~v6BjI~
//**************************************************************** //~v57GI~
//*get translation table                                           //~v57GI~
//*ret :table addr                                                 //~v57GI~
//**************************************************************** //~v57GI~
unsigned char *ucvebc_gettrte2a(void)                              //~v57GI~
{                                                                  //~v57GI~
//********************                                             //~v57GI~
//  return Sebc2asc;                                               //~v57TR~
    return SebcCP1027;                                             //~v57TI~
}//ucvebc_gettrte2a                                                //~v6BjR~
#endif                                                             //~v6BjI~
//**************************************************************** //~v69cI~
//*ebc-->asc with handle                                           //~v69cI~
//*ret :rc:UDBCSCHK_RC_DBCSFOUND                                   //~v69cI~
//**************************************************************** //~v69cI~
int ucvebc2asc_handle(int Popt,int Phandle,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v69cI~
               unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen)//~v69cI~
{                                                                  //~v69cI~
//*********************                                            //~v69cI~
	if (!Phandle)                                                  //~v69cI~
		return ucvebc2asc(Popt,Pibuff,Ppdbcs,Pobuff,Plen,Prepchar,Ppoutlen);//~v69cI~
    return ucvext_icuebc2mbs_handle(Popt,Phandle,Pibuff,Ppdbcs,Plen,Pobuff,Ppoutlen,Prepchar);//~v69cI~
}//ucvebc2asc_handle                                               //~v69cI~
//**************************************************************** //~v69cI~
//*ebc<--asc with handle                                           //~v69cI~
//*ret :rc:UDBCSCHK_RC_DBCSFOUND|DBCSCHK_RC_DBCSSPLIT|UDBCSCHK_RC_DBCSERR//~v69cI~
//**************************************************************** //~v69cI~
int ucvasc2ebc_handle(int Popt,int Phandle,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v69cI~
				unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen)//~v69cI~
{                                                                  //~v69cI~
//*********************                                            //~v69cI~
    UTRACEP("%s:opt=0x%04x,handle=%d\n",UTT,Popt,Phandle);         //~v7dmI~
	if (!Phandle)                                                  //~v69cI~
		return ucvasc2ebc(Popt,Pibuff,Ppdbcs,Pobuff,Plen,Prepchar,Ppoutlen);//~v69cI~
    return ucvext_icumb2ebcs_handle(Popt,Phandle,Pibuff,Ppdbcs,Plen,Pobuff,Ppoutlen,Prepchar);//~v69cR~
}//ucvasc2ebc_handle                                               //~v69cI~
//**************************************************************** //~v57GI~
//*ebc-->asc by cp1027(Japanese Eng-Ext) if not external cv                         //~v57UR~//~v69cR~
//*parm7:output length(reduced by tabskip)                         //~v5eiR~
//*ret :rc:UDBCSCHK_RC_DBCSFOUND                                   //~v5eiI~
//**************************************************************** //~v57GI~
//int ucvebc_2asc(int Popt,unsigned char *Pibuff,unsigned char *Pobuff,int Plen)//~v57TR~
//int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,UCHAR Prepchar)//~v5efR~
//int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,int Prepchar)//~v5eiR~
int ucvebc2asc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v5eiI~
               unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen)//~v5eiI~
{                                                                  //~v57GI~
	UCHAR *pci,*pco,*pce;                                          //~v57GR~
    int crlfsw,ctlsw;                                              //~v57VR~
    UCHAR *pcvt,cho,chi,ctlc;                                      //~v57VR~
    UCHAR *pdbcs,tabid;                                            //~v57UI~
    int   skiplen=0;                                               //~v57UI~
    int reslen,dbcschklen,dbcsoutlen;                              //~v5edR~
    int dbcsrepchar;                                               //~v5efI~
    int topsw=EBC2ASC_BUFTOP;                                      //~v5eiI~
    int rc=0;                                                      //~v5eiI~
    int rc2;                                                       //~v5eiI~
//********************                                             //~v57GI~
    UTRACEP("%s:opt=0x%04x,ebc=%02x,repch=0x%02x\n",UTT,Popt,*Pibuff,Prepchar);                         //~v5mPR~//~v6hhR~//~v6BjR~//~v7daI~
#ifdef WCSUPP                                                      //~v5mPR~
    if (Popt & EBC2ASC_EXT)                                        //~v5mPI~
        return ucvext_icuebc2mbs(Popt,0,Pibuff,Ppdbcs,Plen,Pobuff,Ppoutlen,Prepchar);//~v5mPR~
#endif                                                             //~v5mPI~
    UTRACED("ucvebc2asc inp",Pibuff,Plen);                         //~v6BjI~
	dbcsrepchar=(int)((UINT)Prepchar>>8);                          //~v5eqR~
    Prepchar&=0xff;		//sbcs rep char                            //~v5efI~
    if (!Prepchar)                                                 //~v57UI~
        Prepchar='?';                                              //~v57UI~
//if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/))//~v7d5I~//~v7daR~
//if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/ | UCVEBCS_SBCSLATIN))//~v7daI~//~v7dmR~
//if (Popt & EBC2ASC_SBCSMAP037)                                   //~v7dmI~//~v7dAR~
  if ((UINT)Popt & EBC2ASC_SBCSMAP037)                             //~v7dAI~
  {                                                                //~v7d5I~
	pcvt=Sebc2asc037;                                                //~v7d5R~//~vbB9R~
    UTRACEP("%s:pc is Sebc2asc037\n",UTT);                           //~v7d5I~//~vbB9R~
  }                                                                //~v7d5I~
//  else                                                             //~v7d5I~//~v7dmR~
//  if ((UINT)Popt & EBC2ASC_BASE)                                         //~v7d5R~//~v7dmR~
//  {                                                                //~v7d5I~//~v7dmR~
//    pcvt=Sebcbase;                                                 //~v7d5R~//~v7dmR~
//    UTRACEP("%s:pcvt is SebcBase\n",UTT);                          //~v7d5I~//~v7dmR~
//  }                                                                //~v7d5I~//~v7dmR~
  else                                                             //~v7d5I~
  if (Popt&EBC2ASC_CP290)                                          //~v5eqI~
  {                                                                //~v7d5I~
	pcvt=SebcCP290;                                                //~v5eqI~
    UTRACEP("%s:pcvt is SebcCP290\n",UTT);                         //~v7d5I~
  }                                                                //~v7d5I~
  else                                                             //~v5eqI~
  {                                                                //~v7d5I~
	pcvt=SebcCP1027;                                               //~v57TR~
    UTRACEP("%s:pcvt is SebcCP1027\n",UTT);                        //~v7d5I~
  }                                                                //~v7d5I~
                                                                   //~v7d5I~
    UTRACED("pcvt",pcvt,256);                                      //~v6BjI~
	UTRACED("Stblctle2a",Stblctle2a,sizeof(Stblctle2a));           //~v7dxI~
	crlfsw=Popt & EBC2ASC_CRLF;                                    //~v57GI~
	ctlsw=Popt & EBC2ASC_CTL;                                      //~v57VI~
    UTRACEP("%s:crlfsw=%d,ctlsw=%d\n",UTT,crlfsw,ctlsw);           //~v7dxI~
    pdbcs=Ppdbcs;                                                  //~v57UI~
//  for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;)              //~v5eiR~
    for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;topsw=0)       //~v5eiI~
    {                                                              //~v57GI~
    	chi=*pci++;                                                //~v57TI~
        if (Ppdbcs)                                                //~v57UI~
        {                                                          //~v57UI~
	    	tabid=*pdbcs++;                                        //~v57UI~
            if (tabid==UDBCSCHK_TAB)                               //~v57UI~
            	chi=UDBCSCHK_TAB;                                  //~v57UI~
            else                                                   //~v57UI~
            	if (chi==' ' && tabid!=0)	//tab cont             //~v57UI~
                {                                                  //~v57UI~
                	skiplen++;                                     //~v57UI~
                	continue;                                      //~v57UI~
                }                                                  //~v57UI~
        }                                                          //~v57UI~
//      if (chi==CHAR_SO    //shiftout                             //~v5eiR~
//      &&  Popt & EBC2ASC_DBCS) //dbcs conv                       //~v5eiR~
        if (Popt & EBC2ASC_DBCS)  //dbcs conv                      //~v5eiR~
        if (chi==CHAR_SO                                           //~v5eiR~
        ||  (topsw && Popt & EBC2ASC_SOCONT))	//top of dbcs continued line of SO pending//~v5eiR~
        {                                                          //~v5edR~
        	pci--;                                                 //~v5edR~
//          reslen=(int)((ULONG)pce-(ULONG)pci);                   //~v5edR~//~v6hhR~
            reslen=(int)((ULPTR)pce-(ULPTR)pci);                   //~v6hhI~
//          ucvebc2_stre2s(Popt,pci,pco,reslen,&dbcschklen,&dbcsoutlen,Prepchar);//~v5efR~
            rc2=ucvebc2_stre2s(Popt|topsw,pci,pco,reslen,&dbcschklen,&dbcsoutlen,dbcsrepchar);//~v5eiR~
            pci+=dbcschklen;                                       //~v5edR~
	        if (Ppdbcs)                                            //~v5mCI~
            	pdbcs+=dbcschklen-1;                               //~v5mCI~
            pco+=dbcsoutlen;                                       //~v5edR~
            rc|=rc2;                                               //~v5eiI~
            skiplen+=dbcschklen-dbcsoutlen;                        //~v5egI~
	   		if (Popt & EBC2ASC_LNCONT		//cont line  end by dbcs split//~v5eiI~
	   		&&  rc2 & EBC2ASC_RC_HALFBYTE)                         //~v5eiI~
            	break;                                             //~v5eiI~
          if (dbcschklen)                                          //~v5mPI~
            continue;                                              //~v5edR~
          else                                                     //~v5mPI~
            pci++;                                                 //~v5mPI~
        }                                                          //~v5edR~
    	if (ctlsw                                                  //~v57VI~
//  	&& chi<0x40      //ctl char                                //~v57VI~//~v7d9R~
    	&& chi<CHAR_EBC_SPACE //ctl char                           //~v7d9I~
		&& (ctlc=Stblctle2a[chi])!=0xff)    //corresponding ascii defined//~v57VR~
        {                                                          //~v57VI~
//* Stblctle2a[0x15]=0xff, so 0x15 depends crlfsw                  //~v7dyI~
        	*pco++=ctlc;	                                       //~v57VI~
            continue;                                              //~v57VI~
        }                                                          //~v57VI~
    	if (crlfsw)                                                //~v57GI~
        {                                                          //~v57GI~
//      	if (*pci==EBC_NL)                                      //~v57TR~
//        	if (chi==EBC_NL)                                       //~v57TI~//~v66LR~
//         	if (chi==EBC_LF)                                       //~v66LI~//~v7dyR~
          	if (chi==EBC_NL)   //EBC-0x15,Stblctle2a[0x15]=0xff    //~v7dyR~
            {                                                      //~v57TI~
//          	*pco++='\n',pci++;                                 //~v57TR~
            	*pco++='\n';                                       //~v57TI~
                continue;                                          //~v57TI~
            }                                                      //~v57TI~
            else                                                   //~v57GI~
//      	if (*pci==EBC_CR)                                      //~v57TR~
        	if (chi==EBC_CR)                                       //~v57TI~
            {                                                      //~v57TI~
//          	*pco++='\r',pci++;                                 //~v57TR~
            	*pco++='\r';                                       //~v57TI~
                continue;                                          //~v57TI~
            }                                                      //~v57TI~
//          else                                                   //~v57TR~
//  			*pco++=Sebc2asc[*pci++];                           //~v57TR~
        }                                                          //~v57GI~
//      else                                                       //~v57TR~
//  		*pco++=Sebc2asc[*pci++];                               //~v57TR~
   		cho=pcvt[chi];                                             //~v57TI~
        if (cho=='.')                                              //~v57TI~
        	if (chi!=EBC_PERIOD)                                   //~v57TI~
            {                                                      //~v66EI~
                cho=(UCHAR)Prepchar;                               //~v5eqR~
                rc|=EBC2ASC_RC_ERRREP;                             //~v66EI~
            }                                                      //~v66EI~
        UTRACEP("%s:chi=%02x,cho=%02x\n",UTT,chi,cho);             //~v5mPI~//~v6hhR~//~v6BjR~//~v7dxR~
   		*pco++=cho;                                                //~v57TI~
    }                                                              //~v57GI~
//  return Plen;                                                   //~v57UR~
//  return Plen-skiplen;                                           //~v5eiR~
	if (Ppoutlen)                                                  //~v5eiI~
//		*Ppoutlen=(int)((ULONG)pco-(ULONG)Pobuff);                 //~v5eiI~//~v6hhR~
		*Ppoutlen=(int)((ULPTR)pco-(ULPTR)Pobuff);                 //~v6hhI~
    UTRACEP("%s:rc=%d,outlen=%d\n",UTT,rc,(int)((ULPTR)pco-(ULPTR)Pobuff));//~v5mPI~//~v6hhR~//~v6BjR~//~v7daR~
    UTRACED("Pobuff",Pobuff,Ppoutlen ? *Ppoutlen:0);               //~v6BjI~
    return rc;                                                     //~v5eiI~
}//ucvebc2asc                                                      //~v57UR~
#ifdef UTF8EBCD                                                    //~v660I~
#ifdef AAA	//no caller                                            //~v6BjI~
//**************************************************************** //~v660I~
//*ebc(SBCS)-->sjis                                                //~v660R~
//*ret :1 errrep                                                   //~v660I~
//**************************************************************** //~v660I~
int ucvebc2asc1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,int *Ppsjis)//~v660R~
{                                                                  //~v660I~
    int crlfsw,ctlsw,repch;                                        //~v660I~
    UCHAR *pcvt,ctlc,chi;                                          //~v660R~
    int rc=0,sjis;                                                 //~v660R~
//********************                                             //~v660I~
    UTRACEP("ucvebc2asc1sbcs opt=%x,ebc=%x,repch=%x\n",Popt,*Pebc,Prepchar);//~v660R~
	crlfsw=Popt & EBC2ASC_CRLF;                                    //~v660I~
	ctlsw=Popt & EBC2ASC_CTL;                                      //~v660I~
    repch=Prepchar&0xff;		//sbcs rep char                    //~v660I~
    if (!repch)                                                    //~v660I~
        repch=CHAR_ASCII_ERR; //"?"                                //~v660R~
  	if (Popt&EBC2ASC_CP290)                                        //~v660I~
    {                                                              //~v7d5I~
		pcvt=SebcCP290;                                            //~v660I~
        UTRACEP("%s:pcvt is SebcCP290\n",UTT);                     //~v7d5I~
    }                                                              //~v7d5I~
  	else                                                           //~v660I~
    {                                                              //~v7d5I~
		pcvt=SebcCP1027;                                           //~v660I~
        UTRACEP("%s:pcvt is SebcCP1027\n",UTT);                    //~v7d5I~
    }                                                              //~v7d5I~
    chi=*Pebc;                                                     //~v660I~
    if (chi<CHAR_EBC_SPACE     //ctl char                          //~v660R~
    &&  ctlsw                                                      //~v660I~
    && (ctlc=Stblctle2a[chi])!=0xff    //corresponding ascii defined//~v660R~
    )                                                              //~v660I~
        sjis=(WUCS)ctlc;                                           //~v660R~
    else                                                           //~v660I~
//  if (chi==EBC_NL && crlfsw)                                     //~v660R~//~v66LR~
    if (chi==EBC_LF && crlfsw)                                     //~v66LI~
    	sjis='\n';                                                 //~v660R~
    else                                                           //~v660I~
    if (chi==EBC_CR && crlfsw)                                     //~v660I~
    	sjis='\r';                                                 //~v660R~
    else                                                           //~v660I~
    {                                                              //~v660I~
   		sjis=(WUCS)pcvt[chi];                                      //~v660R~
        if (sjis=='.')                                             //~v660R~
        	if (chi!=EBC_PERIOD)                                   //~v660I~
            {                                                      //~v660I~
                sjis=repch;                                        //~v660R~
                rc|=EBC2ASC_RC_ERRREP;                             //~v660I~
            }                                                      //~v660I~
    }                                                              //~v660I~
    *Ppsjis=sjis;                                                  //~v660I~
    UTRACEP("ucvebc2asc1sbcsJ rc=%d,sjis=%x\n",rc,sjis);           //~v660R~
    return rc;                                                     //~v660I~
}//ucvebc2asc1sbcsJ                                                //~v660R~
#endif //AAA                                                       //~v6BjI~
//**************************************************************** //~v660I~
//*ebc(SBCS)-->sjis                                                //~v660I~
//*ret :1 errrep                                                   //~v660I~
//**************************************************************** //~v660I~
//int ucvebc2ucs1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,WUCS *Ppucs)//~v660I~//~v6BjR~
int ucvebc2ucs1sbcsJ(int Popt,UCHAR *Pebc,int Prepchar,UWUCS *Ppucs)//~v6BjI~
{                                                                  //~v660I~
    int crlfsw,ctlsw,repch;                                        //~v660I~
    USHORT *pcvt;                                                  //~v660R~
    UCHAR chi;                                                     //~v660I~
    int rc=0;                                                      //~v660I~
    WUCS wucs;                                                     //~v660I~
//********************                                             //~v660I~
    UTRACEP("%s:opt=0x%08x,ebc=0x%02x,repch=0x%02x\n",UTT,Popt,*Pebc,Prepchar);//~v660I~//~v6hhR~//~v6BjR~//~v7dbR~
	if (!Sswinite2u)                                               //~v660M~
    	ucvebcinite2uJ();                                          //~v660M~
	crlfsw=Popt & EBC2ASC_CRLF;                                    //~v660I~
	ctlsw=Popt & EBC2ASC_CTL;                                      //~v660I~
    repch=Prepchar&0xff;		//sbcs rep char                    //~v660I~
    if (!repch)                                                    //~v660I~
        repch=CHAR_ASCII_ERR; //"?"                                //~v660I~
//  if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/))//~v7d5I~//~v7daR~
//  if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/ | UCVEBCS_SBCSLATIN))//~v7daI~//~v7dmR~
//  if (Popt & EBC2ASC_SBCSMAP037)                                 //~v7dmI~//~v7dAR~
    if ((UINT)Popt & EBC2ASC_SBCSMAP037)                           //~v7dAI~
    {                                                              //~v7d5I~
		pcvt=Sibm037e2u;                                           //~v7d5I~
        UTRACEP("%s:pc is Sibm037e2u=%p\n",UTT,pcvt);                      //~v7d5I~//~v7dmR~
    }                                                              //~v7d5I~
    else                                                           //~v7d5I~
  	if (Popt&EBC2ASC_CP290)                                        //~v660I~
    {                                                              //~v7d5I~
		pcvt=Sibm290e2u;    //katakana                             //~v660R~
	    UTRACEP("%s:pcvt is Sibm290e2u=%p\n",UTT,pcvt);                    //~v7d5I~//~v7dmR~
    }                                                              //~v7d5I~
  	else                                                           //~v660I~
    {                                                              //~v7d5I~
		pcvt=Sibm1027e2u;                                          //~v660R~
	    UTRACEP("%s:pcvt is Sibm1027e2u=%p\n",UTT,pcvt);                   //~v7d5I~//~v7dmR~
    }                                                              //~v7d5I~
    chi=*Pebc;                                                     //~v660I~
//  if (chi==EBC_NL && crlfsw)                                     //~v660I~//~v66LR~
//  if (chi==EBC_LF && crlfsw)                                     //~v66LI~//~v7dyR~
    if (chi==EBC_NL && crlfsw)  //EBC_NL(0x15)-->u-000a            //~v7dyI~
    	wucs='\n';                                                 //~v660I~
    else                                                           //~v660I~
    if (chi==EBC_CR && crlfsw)                                     //~v660I~
    	wucs='\r';                                                 //~v660I~
    else                                                           //~v660I~
    if (chi<CHAR_EBC_SPACE)                                        //~v660I~
    {                                                              //~v660I~
    	if (ctlsw)                                                 //~v660I~
    		wucs=(WUCS)pcvt[chi];                                  //~v660I~
        else                                                       //~v660I~
        	wucs=0;                                                //~v660I~
    }                                                              //~v660I~
    else                                                           //~v660I~
   		wucs=(WUCS)pcvt[chi];                                      //~v660I~
    if (!wucs && chi)                                              //~v660I~
    {                                                              //~v660I~
//  	wucs=repch;                                                //~v660I~//~v6BiR~
    	wucs=(WUCS)repch;                                          //~v6BiI~
        rc|=EBC2ASC_RC_ERRREP;                                     //~v660I~
    }                                                              //~v660I~
//  *Ppucs=wucs;                                                   //~v660I~//~v6BjR~
    *Ppucs=(UWUCS)wucs;                                            //~v6BjI~
    UTRACEP("%s:rc=%d,ebc=%02x,ucs=%x\n",UTT,rc,*Pebc,wucs);            //~v660I~//~v6hhR~//~v7dbR~//~v7dmR~
    return rc;                                                     //~v660I~
}//ucvebc2ucs1sbcsJ                                                //~v660I~
#endif                                                             //~v660I~
//**************************************************************** //~v57UI~
//*ebc<--asc by cp1027(Japanese Eng-Ext if internal cv)          //~v57UI~//~v69cR~
//*ret :rc:UDBCSCHK_RC_DBCSFOUND|DBCSCHK_RC_DBCSSPLIT|UDBCSCHK_RC_DBCSERR//~v5eiR~
//**************************************************************** //~v57UI~
//int ucvasc2ebc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,unsigned char *Pobuff,int Plen,UCHAR Prepchar)//~v5efR~
int ucvasc2ebc(int Popt,unsigned char *Pibuff,unsigned char *Ppdbcs,//~v5eiR~
				unsigned char *Pobuff,int Plen,int Prepchar,int *Ppoutlen)//~v5eiR~
{                                                                  //~v57UI~
	UCHAR *pci,*pco,*pce;                                          //~v57UI~
    int crlfsw,ctlsw;                                              //~v57VR~
    UCHAR *pcvt,cho,chi,ctlc;                                      //~v57VR~
//  int S1stsw=0;                                                  //~v5mSR~
static int S1stsw=0;                                               //~v5mSI~
    UCHAR *pdbcs,tabid;                                            //~v57UI~
    int   skiplen=0;                                               //~v57UI~
    int dbcsrepchar,reslen,dbcschklen,dbcsoutlen;                  //~v5edR~
    int topsw=EBC2ASC_BUFTOP;                                      //~v5egR~
    int rc=0,rc2;                                                  //~v5eiI~
    int explen=0;                                                  //~v5mCI~
    int lrecl;                                                     //~v5mXI~
    int opteuc,dbcssw;                                             //~v66iR~
//********************                                             //~v57UI~
    UTRACEP("%s:opt=%x,S1stsw=%d,*Ppoutlen=%d\n",UTT,Popt,S1stsw,*Ppoutlen);                              //~v5mXI~//~v7daI~//~v7dmR~//~vataR~
    UTRACED("Pibuff",Pibuff,Plen);                                 //~v7duI~
    UTRACED("Ppdbcs",Ppdbcs,Plen);                                 //~v7duI~
    UTRACED("Stblctla2e",Stblctla2e,sizeof(Stblctla2e));           //~v7duR~
    UTRACED("Stbla2e",Stbla2e,sizeof(Stbla2e));                    //~v7duI~
#ifdef WCSUPP                                                      //~v5mPR~
    if (Popt & EBC2ASC_EXT)                                        //~v5mPR~
        return ucvext_icumb2ebcs(Popt,0,Pibuff,Ppdbcs,Plen,Pobuff,Ppoutlen,Prepchar);//~v5mPR~
#endif                                                             //~v5mPI~
    lrecl=*Ppoutlen;   //input LRECL when EBC2ASC_FIXEDLRECL is on //~v5mXI~
    if (!S1stsw)                                                   //~v57UI~
    {                                                              //~v57UI~
    	S1stsw=1;                                                  //~v57UI~
//      ucvebcinita2e();                                           //~v5eqR~
        ucvebcinita2e(Popt);                                       //~v5eqI~
    }                                                              //~v57UI~
    if (Popt & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert       //~v5mCI~
    	Popt|=EBC2ASC_SOSIOS;        //override boundary space if avail//~v5mCI~
	dbcsrepchar=(int)((UINT)Prepchar>>8);                          //~v5eqR~
    Prepchar&=0xff;		//sbcs rep char                            //~v5efI~
    if (!Prepchar)                                                 //~v57UI~
//      Prepchar='?';                                              //~v5epR~
        Prepchar=CHAR_EBC_ERR;                                     //~v5epI~
	pcvt=Stbla2e;                                                  //~v57UI~
	crlfsw=Popt & EBC2ASC_CRLF;                                    //~v57UI~
	ctlsw=Popt & EBC2ASC_CTL;                                      //~v57VI~
	opteuc=Popt & EBC2ASC_EUC;                                     //~v66iI~
    pdbcs=Ppdbcs;                                                  //~v57UI~
//  for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;)              //~v5eiR~
    for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;topsw=0)       //~v5eiI~
    {                                                              //~v57UI~
    	chi=*pci++;                                                //~v57UI~
        dbcssw=UWHICH(opteuc,ISEUC(chi),SJIS1(chi));               //~v66iI~
        if (Popt & EBC2ASC_DBCS)  //dbcs conv                      //~v5eiR~
        if ((topsw && Popt & EBC2ASC_SOCONT)	//top of continued line of SO pending//~v5eiR~
//  	||  SJIS1(chi))	//dbcs 1st byte                            //~v5eiR~//~v66iR~
    	||  dbcssw	//dbcs 1st byte                                //~v66iI~
        )                                                          //~v66iI~
        {                                                          //~v5edR~
        	pci--;                                                 //~v5edR~
//          reslen=(int)((ULONG)pce-(ULONG)pci);                   //~v5edR~//~v6hhR~
            reslen=(int)((ULPTR)pce-(ULPTR)pci);                   //~v6hhI~
			if (lrecl)                                             //~v5mXI~
//	            dbcsoutlen=lrecl-(int)((ULONG)pco-(ULONG)Pobuff)%lrecl; //optionaly insert SI at EOL by LRECL//~v5mXR~//~v6hhR~
	            dbcsoutlen=lrecl-(int)((ULPTR)pco-(ULPTR)Pobuff)%lrecl; //optionaly insert SI at EOL by LRECL//~v6hhI~
            else                                                   //~v5mXI~
	            dbcsoutlen=0;                                      //~v5mXI~
            dbcsoutlen|=(int)((UINT)lrecl<<16);                    //~v5mXR~
    UTRACEP("strs2e pci=%02x%02x\n",*pci,*(pci+1));                //~v5mXI~
//          ucvebc2_strs2e(Popt,pci,pco,reslen,&dbcschklen,&dbcsoutlen,dbcsrepchar);//~v5egR~
            rc2=                                                   //~v5eiI~
            ucvebc2_strs2e(Popt|topsw,pci,pco,reslen,&dbcschklen,&dbcsoutlen,dbcsrepchar);//~v5egR~
            pci+=dbcschklen;                                       //~v5edR~
	        if (Ppdbcs)                                            //~v5mCI~
            	pdbcs+=dbcschklen-1;                               //~v5mCI~
            pco+=dbcsoutlen;                                       //~v5edR~
            explen+=(dbcsoutlen-dbcschklen);	//expand len by SO/SI insert//~v5mCI~
            rc|=rc2;                                               //~v5eiI~
	   		if (Popt & EBC2ASC_LNCONT		//cont line  end by dbcs split//~v5eiI~
	   		&&  rc2 & EBC2ASC_RC_HALFBYTE)                         //~v5eiI~
            	break;                                             //~v5eiI~
          if (dbcschklen) //avoid loop                             //~v5mPI~
            continue;                                              //~v5edR~
          else                                                     //~v5mPI~
            pci++;  //advance for sbcs                             //~v5mPI~
        }                                                          //~v5edR~
        if (Ppdbcs)                                                //~v57UI~
        {                                                          //~v57UI~
	    	tabid=*pdbcs++;                                        //~v57UI~
            if (tabid==UDBCSCHK_TAB)                               //~v57UI~
            	chi=UDBCSCHK_TAB;                                  //~v57UI~
            else                                                   //~v57UI~
            	if (chi==' ' && tabid!=0)	//tab cont             //~v57UI~
                {                                                  //~v57UI~
				    if (Popt & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert//~v5mCI~
                    	if (explen)                                //~v5mCI~
                        	explen--;                              //~v5mCI~
                	skiplen++;                                     //~v57UI~
                	continue;                                      //~v57UI~
                }                                                  //~v57UI~
        }                                                          //~v57UI~
        if (chi==' ')                                              //~v5mCI~
        {                                                          //~v5mCI~
            if (Popt & EBC2ASC_SOSISHIFT)    //shift by SO/SI insert//~v5mCI~
                if (explen)                                        //~v5mCI~
                {                                                  //~v5mCI~
                	if (*(pco-1)==CHAR_SI||*(pco-1)==CHAR_EBC_SPACE) //keep word delm//~v5mCI~
                    {                                              //~v5mCI~
                    	explen--;                                  //~v5mCR~
            			continue;               //drop input space until expanded len by SO/SI insert//~v5mCR~
                    }                                              //~v5mCI~
            	}                                                  //~v5mCI~
        }                                                          //~v5mCI~
    	if (crlfsw) //before ctl chk                               //~v7dyI~
        {                                                          //~v7dyI~
        	if (chi=='\n')                                         //~v7dyI~
            {                                                      //~v7dyI~
            	*pco++=EBC_NL;    //Ascii-lf(0a)-->EBC-NL(0x15)    //~v7dyI~
                continue;                                          //~v7dyI~
            }                                                      //~v7dyI~
            else                                                   //~v7dyI~
        	if (chi=='\r')                                         //~v7dyI~
            {                                                      //~v7dyI~
            	*pco++=EBC_CR;                                     //~v7dyI~
                continue;                                          //~v7dyI~
            }                                                      //~v7dyI~
        }                                                          //~v7dyI~
//  	if (ctlsw                                                  //~v57VI~//~v7dRR~
//  	&& chi<sizeof(Stblctla2e)     //ctl char(<x20 and 7f)      //~v57VR~//~v7dRR~
//  	&& (ctlc=Stblctla2e[chi])!=0xff)       //corresponding ebc defined//~v57VR~//~v7dRR~
    	if (chi<sizeof(Stblctla2e)     //ctl char(<x20 and 7f)     //~v7dRI~
      	&& (ctlc=Stblctla2e[chi])!=0xff       //corresponding ebc defined//~v7dRI~
        &&  ctlc<CHAR_EBC_SPACE   //ebc ctl                        //~v7dRI~
        )                                                          //~v7dRI~
        {                                                          //~v57VI~
            UTRACEP("%s:asc=%02x,ctlc=%02x,ctlsw=%d\n",UTT,chi,ctlc,ctlsw);//~v7dRI~
          if (ctlsw)                                               //~v7dRI~
          {                                                        //~v7dRI~
        	*pco++=ctlc;                                           //~v57VI~
	        UTRACEP("%s:ctl chi=%02x,ctlc=%02x\n",UTT,chi,ctlc);   //~v7duI~
            continue;                                              //~v57VI~
          }                                                        //~v7dRI~
        }                                                          //~v57VI~
//        if (crlfsw)                                                //~v57UI~//~v7dyR~
//        {                                                          //~v57UI~//~v7dyR~
//            if (chi=='\n')                                         //~v57UI~//~v7dyR~
//            {                                                      //~v57UI~//~v7dyR~
////              *pco++=EBC_NL;                                     //~v57UI~//~v66LR~//~v7dyR~
//                *pco++=EBC_LF;                                     //~v66LI~//~v7dyR~
//                continue;                                          //~v57UI~//~v7dyR~
//            }                                                      //~v57UI~//~v7dyR~
//            else                                                   //~v57UI~//~v7dyR~
//            if (chi=='\r')                                         //~v57UI~//~v7dyR~
//            {                                                      //~v57UI~//~v7dyR~
//                *pco++=EBC_CR;                                     //~v57UI~//~v7dyR~
//                continue;                                          //~v57UI~//~v7dyR~
//            }                                                      //~v57UI~//~v7dyR~
//        }                                                          //~v57UI~//~v7dyR~
   		cho=pcvt[chi];                                             //~v57UI~
        if (!cho)                                                  //~v57UI~
        {                                                          //~v66EI~
        	cho=(UCHAR)Prepchar;                                   //~v5eqR~
            rc|=EBC2ASC_RC_ERRREP;                                 //~v66EI~
        }                                                          //~v66EI~
   		*pco++=cho;                                                //~v57UI~
        UTRACEP("%s:sbcs chi=%02x,cho=%02x\n",UTT,chi,cho);        //~v7duI~
    }                                                              //~v57UI~
//  return Plen-skiplen;                                           //~v5eiR~
    if (Ppoutlen)                                                  //~v5eiI~
//		*Ppoutlen=(int)((ULONG)pco-(ULONG)Pobuff);                 //~v5eiR~//~v6hhR~
		*Ppoutlen=(int)((ULPTR)pco-(ULPTR)Pobuff);                 //~v6hhI~
    UTRACED("Pobuff",Pobuff,PTRDIFF(pco,Pobuff));                  //~v7duR~
    UTRACEP("%s:rc=%x\n",UTT,rc);                                  //~v7duI~
    return rc;                                                     //~v5eiI~
}//ucvasc2ebc                                                      //~v57UI~
//**************************************************************** //~v66LI~
//*apply config parameter after ucvebcinita2e                      //~v66RR~
//**************************************************************** //~v66LI~
int ucvebc_defaultremap(int Popt,void *Ppcfg)                 //~v66LI~//~v66RR~
{                                                                  //~v66LI~
	UCHAR *pc,*pcce2a,*pcca2e,*pca2e,*pce2a;                                                     //~v66LI~//~v66RR~
    int ch,ii;                                                     //~v66LI~
	PUCVEXTCFG pcfg;                                               //~v66RI~
    USHORT *pcvt;                                                  //~v66RI~
    int opt,rc2;                                                   //~v66RI~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    UCHAR mb;                                                      //~v66RI~
    WUCS ucs;                                                      //~v66RI~
    UWUCS ucs4;                                                    //~v6f3I~
//*************************                                        //~v66LI~
	pcfg=(PUCVEXTCFG)Ppcfg;                                        //~v66RI~
    if (pcfg->UCECflag & UCECF_USE_CONVERTER)   //external converter//~v66RI~
        return 0;                                                  //~v66RI~
	if (!Sswinite2u)                                               //~v66RI~
    	ucvebcinite2uJ();                                          //~v66RI~
	pcce2a=Stblctle2a;                                             //~v66RI~
	pcca2e=Stblctla2e;                                             //~v66RI~
    UTRACED("Stblctle2a",Stblctle2a,sizeof(Stblctle2a));           //~v7dmI~
    UTRACED("Stblctla2e",Stblctla2e,sizeof(Stblctla2e));           //~v7dmI~
  	if (S1stswa2e==3)                                              //~v7d5I~
    {                                                              //~v7d5I~
		pce2a=Sebc2asc037;                                         //~vbB9I~
        pcvt=Sibm037e2u;                                             //~v7d5I~//~vbB9R~
        pca2e=SebcCP037rev;                                        //~v7dbI~
        UTRACEP("%s:pc is Sibm037e2u\n",UTT);                      //~v7d5I~
    }                                                              //~v7d5I~
    else                                                           //~v7d5I~
  	if (S1stswa2e==2)                                              //~v66RI~
    {                                                              //~v66RI~
		pce2a=SebcCP290;                                           //~v66RI~
		pcvt=Sibm290e2u;    //katakana                             //~v66RI~
        pca2e=SebcCP290rev;                                        //~v7dbI~
	    UTRACEP("%s:pcvt is Sibm290e2u,pce2a is SebcCP290 \n",UTT);//~v7d5I~
    }                                                              //~v7d5I~
    else                                                           //~v66RI~
    {                                                              //~v66RI~
		pce2a=SebcCP1027;                                          //~v66RI~
		pcvt=Sibm1027e2u;                                          //~v66RI~
        pca2e=SebcCP1027rev;                                       //~v7dbI~
	    UTRACEP("%s:pcvt is Sibm1027e2u,pce2a is SebcCP1027 \n",UTT);//~v7d5I~
    }                                                              //~v66RI~
//  pca2e=Stblctle2a;                                              //~v66RI~//~v7dbR~
    UCHAR *pca2eAll=Stbla2e;                                       //~v7dxR~
    pconverter=pcfg->UCECconverterlocal;                           //~v66RR~
    opt=EBC2ASC_CTL;                                               //~v66RI~
    if (pcfg->UCECflag & UCECF_E2A)     //a2a mapping specified//~v66RI~//~v66LI~//~v66RR~
    {                                                          //~v66RI~//~v66LI~
        pc=pcfg->UCECsbcsmape2a;                               //~v66RI~//~v66LR~//~v66RR~
        UTRACED("sbcsmape2a",pc,256);                              //~v7dmI~
        for (ii=0;ii<0x100;ii++)                                   //~v66LI~
        {                                                          //~v66LI~
        	ch=*pc++;   	//ascii                                //~v66LI~
            if (ch)                                                //~v66RI~
            {                                                      //~v66RI~
            	if (ii<CHAR_EBC_SPACE)                             //~v66RR~
//              	pcce2a[ii]=ch;  //ctl char map                 //~v66RI~//~v6BiR~
                	pcce2a[ii]=(UCHAR)ch;  //ctl char map          //~v6BiI~
                else                                               //~v66RI~
//              	pce2a[ii]=ch;                                  //~v66RI~//~v6BiR~
                	pce2a[ii]=(UCHAR)ch;                           //~v6BiI~
                if (pconverter)	//b2u mapping after a2u            //~v66RI~
                {                                                  //~v66RI~
//              	mb=ch;	//codepage                             //~v66RI~//~v6BiR~
                	mb=(UCHAR)ch;	//codepage                     //~v6BiI~
                    ucs=0;                                         //~v7dmI~
                  if (UDBCSCHK_IS_LOCALICU())                      //~v6f3I~
                  {                                                //~v6f3I~
            		rc2=ucvext_icumb2ucs1(UCVEXTO_SETSUBCHRC,pconverter,&mb,1,0/*chklen*/,&ucs4);//~v6f3R~
//                  ucs=ucs4;                                      //~v6f3I~//~v6BiR~
                   if (!rc2)                                       //~v7dmI~
                    ucs=(WUCS)ucs4;                                //~v6BiI~
                  }                                                //~v6f3I~
                  else                                             //~v6f3I~
                  {                                                //~v6f3I~
//          		rc2=ucvext_iconvlocal2ucs1(opt,pconverter,&mb,1,0/*chklen*/,&ucs);//~v66RI~//~v6BjR~
            		rc2=ucvext_iconvlocal2ucs1(opt,pconverter,&mb,1,0/*chklen*/,&ucs4);//~v6BjI~
                   if (!rc2)                                       //~v7dmI~
                    ucs=(WUCS)ucs4;                                //~v6BjI~
                  }                                                //~v6f3I~
                    if (!rc2)                                      //~v66RR~
//  					pcvt[ii]=ucs;    //b2u mapping             //~v66RR~//~v6BkR~
    					pcvt[ii]=(USHORT)ucs;    //b2u mapping     //~v6BkR~
                }                                                  //~v66RI~
            }                                                      //~v66RI~
        }                                                          //~v66LI~
    }                                                              //~v66LI~
    if (pcfg->UCECflag & UCECF_A2E)     //a2a mapping specified    //~v66RI~
    {                                                              //~v66RI~
        pc=pcfg->UCECsbcsmapa2e;                                   //~v66RR~
        UTRACED("sbcsmapa2e",pc,256);                              //~v7dmI~
        for (ii=0;ii<0x100;ii++)                                   //~v66RI~
        {                                                          //~v66RI~
        	ch=*pc++;   	//ascii                                //~v66RI~
            if (ch)                                                //~v66RI~
            {                                                      //~v66RI~
//          	if (ii<' ')                                        //~v66RR~//~v7dRR~
            	if (ch<CHAR_EBC_SPACE)  //asc->ebc ctl             //~v7dRI~
//              	pcca2e[ii]=ch;                                 //~v66RI~//~v6BiR~
                	pcca2e[ii]=(UCHAR)ch;                          //~v6BiI~
                else                                               //~v66RI~
                {                                                  //~v7dxI~
//              	pca2e[ii]=ch;                                  //~v66RI~//~v6BiR~
                	pca2e[ii]=(UCHAR)ch;                           //~v6BiI~
                	pcca2e[ii]=0xff;    //reset ctl a2e            //~v7dxI~
                	pca2eAll[ii]=(UCHAR)ch;                        //~v7dxI~
                }                                                  //~v7dxI~
            }                                                      //~v66RI~
        }                                                          //~v66RI~
    }                                                              //~v66RI~
    UTRACED("exit E2A",pce2a,256);                         //~v66RI~//~v7dwR~
    UTRACED("exit A2E",pca2e,256);                         //~v66RI~//~v7dwR~
    UTRACED("exit A2EAll",pca2eAll,256);                           //~v7dxI~
    UTRACED("exit Stblctla2e",pcca2e,sizeof(Stblctla2e));     //~v66RI~//~v7dwR~//~v7dxR~//~v7dPR~
    UTRACED("exit Stblctle2a",pcce2a,sizeof(Stblctle2a));     //~v66RI~//~v7dwR~//~v7dxR~//~v7dPR~
    UTRACED("exit b2u    ",pcvt,256*2);                    //~v66RI~//~v7dwR~
    return 0;                                                      //~v66RI~
}//ucvebc_defaultremap                                             //~v66LI~
//**************************************************************** //~v57UI~
//*ebc<--asc by cp1027 or cp290                                    //~v66RR~
//*ret :length                                                     //~v57UI~
//**************************************************************** //~v57UI~
//void ucvebcinita2e(void)                                         //~v5eqR~
void ucvebcinita2e(int Popt)                                       //~v5eqR~
{                                                                  //~v57UI~
	UCHAR *pc;                                                     //~v57UR~
    int ii;                                                        //~v57UR~
    UCHAR ch;                                                      //~v57UR~
//********************                                             //~v57UI~
    UTRACEP("%s:opt=0x%08x,S1stswa2e=%d\n",UTT,Popt,S1stswa2e);                           //~v7dAI~//~v7dPR~
#ifdef UTF8EBCD                                                    //~v660I~
	if (S1stswa2e)                                                 //~v660I~
    	return;                                                    //~v660I~
    S1stswa2e=1;   //for the case of external call                 //~v660R~
#endif                                                             //~v660I~
//if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/))//~v7d5I~//~v7daR~
//if (Gucvebc_stat & (UCVEBCS_CLO_CP931/*cmdline*/ | UCVEBCS_SJISLATIN/*sjisopt*/ | UCVEBCS_SBCSLATIN))//~v7daI~//~v7dmR~
//if (Popt & EBC2ASC_SBCSMAP037)                                   //~v7dmI~//~v7dAR~
  if ((UINT)Popt & EBC2ASC_SBCSMAP037)                             //~v7dAI~
  {                                                                //~v7d5I~
    S1stswa2e=3;   //for ucvebc_defaultremap                       //~v7d5I~
	pc=Sebc2asc037;                                                  //~v7d5I~//~vbB9R~
    UTRACEP("%s:pc is Sebc2asc037\n",UTT);                           //~v7d5I~//~vbB9R~
  }                                                                //~v7d5I~
  else                                                             //~v7d5I~
  if (Popt&EBC2ASC_CP290)                                          //~v5eqI~
  {                                                                //~v66RI~
    S1stswa2e=2;   //for ucvebc_defaultremap                       //~v66RI~
	pc=SebcCP290;                                                  //~v5eqI~
    UTRACEP("%s:pc is SebcCP290\n",UTT);                           //~v7d5I~
  }                                                                //~v66RI~
  else                                                             //~v5eqI~
  {                                                                //~v7d5I~
	pc=SebcCP1027;                                                 //~v57UI~
    UTRACEP("%s:pc is SebcCP1027\n",UTT);                          //~v7d5I~
  }                                                                //~v7d5I~
    UTRACED("e2a",pc,256);                                  //~v662R~//~v7duR~//~v7dPR~
	for (ii=0;ii<256;ii++)                                         //~v57UI~
    {                                                              //~v57UI~
    	ch=*pc++;                                                  //~v57UI~
        if (ch=='.')                                               //~v57UI~
        	if (ii!=EBC_PERIOD)                                    //~v57UI~
            	continue;		//no ebc char                      //~v57UI~
        Stbla2e[ch]=(UCHAR)ii;                                     //~v5eqR~
    }                                                              //~v57UI~
	pc=Stblctle2a;                                                 //~v57VI~
    memset(Stblctla2e,0xff,sizeof(Stblctla2e));	//id of no corresponding ebc//~v57VI~
	for (ii=0;ii<sizeof(Stblctle2a);ii++)                          //~v57VI~
    {                                                              //~v57VI~
    	ch=*pc++;                                                  //~v57VI~
        if (ch==0xff) 	//no corresponding ascii                   //~v57VI~
            continue;		//no ebc char                          //~v57VI~
        if (ch>=sizeof(Stblctla2e)) 	//safety confirm           //~v7dwI~
            continue;		//no ebc char                          //~v7dwI~
        Stblctla2e[ch]=(UCHAR)ii;  //map ascii-->ebc               //~v5eqR~
    }                                                              //~v57VI~
    UTRACED("Stblctle2a",Stblctle2a,sizeof(Stblctle2a));                             //~v662I~//~v7dbR~//~v7duR~
    UTRACED("Stblctla2e",Stblctla2e,sizeof(Stblctla2e));           //~v7duR~
    UTRACED("Stbla2e",Stbla2e,sizeof(Stbla2e));                                //~v7dbI~//~v7duR~
    return;                                                        //~v57UR~
}//ucvebcinita2e                                                   //~v57UI~
//**************************************************************** //~v57SI~
//*hankaku katakana & alphabet lowercase                           //~v57SI~
//*re-conversion ascii file to ascii after b2m by cp290/cp1027              //~v7dpI~//~v7dmR~
//* if outbuff==0;chk only                                         //~v57SI~
//*ret :when chkonly; 1:conv may occur,0:not found                 //~v57SR~
//*    :     conv   ; conv len                                     //~v57SI~
//**************************************************************** //~v57SI~
int ucvkandl(int Popt,unsigned char *Pibuff,unsigned char *Pobuff,int Plen)//~v57SI~
{                                                                  //~v57SI~
	UCHAR *pci,*pco,*pce;                                          //~v57SI~
    int k2lsw;                                                     //~v57SR~
    UCHAR ch,ch2;                                                  //~v57SR~
//  int S1stsw=0;                                                  //~v5mSR~
static int S1stsw=0;                                               //~v5mSI~
//********************                                             //~v57SI~
    UTRACEP("%s:opt=0x%04x\n",UTT,Popt);                           //~v6BjI~
    UTRACED("Pibuff",Pibuff,Plen);                                 //~v6BjI~
    if (!S1stsw)                                                   //~v57VI~
    {                                                              //~v57VI~
    	S1stsw=1;                                                  //~v57VI~
        ucvebcinitkandl();                                         //~v57VI~
    }                                                              //~v57VI~
	k2lsw=Popt & KANDL_K2L;                                        //~v57SI~
//    int swDbcs=0;                                                  //~v7dpI~//~v7dmR~
	for (pci=Pibuff,pco=Pobuff,pce=pci+Plen;pci<pce;)              //~v57SI~
    {                                                              //~v57SI~
    	ch=*pci++;                                                 //~v57SI~
        if (udbcschk(ch))                                          //~v57SI~//~v7dpR~//~v7dmR~
        {                                                          //~v57SI~//~v7dpR~//~v7dmR~
            if (Pobuff)                                            //~v57SI~//~v7dpR~//~v7dmR~
            {                                                      //~v57SI~//~v7dpR~//~v7dmR~
                *pco++=ch;                                         //~v57SR~//~v7dpR~//~v7dmR~
                if (pci==pce)                                      //~v57SI~//~v7dpR~//~v7dmR~
                    return KANDL_RC_DBCSSPLIT;                     //~v57SI~//~v7dpR~//~v7dmR~
                *pco++=*pci;                                       //~v57SR~//~v7dpR~//~v7dmR~
            }                                                      //~v57SI~//~v7dpR~//~v7dmR~
            pci++;                                                 //~v57SI~//~v7dpR~//~v7dmR~
            continue;                                              //~v57SI~//~v7dpR~//~v7dmR~
        }                                                          //~v57SI~//~v7dpR~//~v7dmR~
//        if (ch==CHAR_SO)                                           //~v7dpI~//~v7dmR~
//        {                                                          //~v7dpI~//~v7dmR~
//            if (!swDbcs)                                           //~v7dpI~//~v7dmR~
//                swDbcs=1;                                          //~v7dpI~//~v7dmR~
//            if (Pobuff)                                            //~v7dpI~//~v7dmR~
//            {                                                      //~v7dpI~//~v7dmR~
//                *pco++=ch;                                         //~v7dpI~//~v7dmR~
//            }                                                      //~v7dpI~//~v7dmR~
//            continue;                                              //~v7dpI~//~v7dmR~
//        }                                                          //~v7dpI~//~v7dmR~
//        else                                                       //~v7dpI~//~v7dmR~
//        if (ch==CHAR_SI)                                           //~v7dpI~//~v7dmR~
//        {                                                          //~v7dpI~//~v7dmR~
//            if (swDbcs)                                            //~v7dpI~//~v7dmR~
//                swDbcs=0;                                          //~v7dpI~//~v7dmR~
//            if (Pobuff)                                            //~v7dpI~//~v7dmR~
//                *pco++=ch;                                         //~v7dpI~//~v7dmR~
//            continue;                                              //~v7dpI~//~v7dmR~
//        }                                                          //~v7dpI~//~v7dmR~
//        if (swDbcs)                                                //~v7dpI~//~v7dmR~
//        {                                                          //~v7dpI~//~v7dmR~
//            if (Pobuff)                                            //~v7dpI~//~v7dmR~
//                *pco++=ch;                                         //~v7dpI~//~v7dmR~
//            continue;                                              //~v7dpI~//~v7dmR~
//        }                                                          //~v7dpI~//~v7dmR~
//sbcs                                                             //~v57SI~
    	if (k2lsw)                                                 //~v57SI~
        {                                                          //~v57SI~
//      	if (ch>0x80)	//may katakana                         //~v57VR~
//          {                                                      //~v57VR~
//          	ch2=Skandl[ch];                                    //~v57VR~
            	ch2=SebcCP290rev[ch];	//back to ebc              //~v57VR~
//                UTRACEP("%s:k2lsw SebcCP290rev[%02x]=%02x\n",UTT,ch,ch2);//~v7dpI~//~v7dmR~
//              if (ch2!='.')                                      //~v57VR~
                if (ch2)                                           //~v57VI~
                {                                                  //~v57SI~
                	if (!Pobuff)                                   //~v57SI~
                    	return KANDL_RC_WILLCONV;                  //~v57SR~
//              	ch=ch2;		//conv                             //~v57VR~
                	ch=SebcCP1027[ch2];  //re-conv by 1027         //~v57VR~
                }                                                  //~v57SI~
//          }                                                      //~v57VR~
        }                                                          //~v57SI~
        else		//l-->k                                        //~v57SI~
        {                                                          //~v57VI~
//      	if (ch<0x80)	//may alphabetic                       //~v57VR~
//          {                                                      //~v57VR~
//          	ch2=Skandl[ch];                                    //~v57VR~
            	ch2=SebcCP1027rev[ch];	//back to ebc              //~v57VR~
//              if (ch2!='.')                                      //~v57VR~
                if (ch2)                                           //~v57VI~
                {                                                  //~v57SI~
                	if (!Pobuff)                                   //~v57SI~
                    	return KANDL_RC_WILLCONV;                  //~v57SI~
//              	ch=ch2;		//conv                             //~v57VR~
                	ch=SebcCP290[ch2];   //re-conv by 290          //~v57VR~
                }                                                  //~v57SI~
//          }                                                      //~v57VR~
        }                                                          //~v57VI~
        if (Pobuff)                                                //~v57SI~
    		*pco++=ch;                                             //~v57SR~
//        UTRACEP("%s:k2lsw=%d,in=%02x,out=%02x\n",UTT,k2lsw,*(pci-1),ch);//~v7dpR~//~v7dmR~
    }                                                              //~v57SI~
    if (!Pobuff)	//chk only                                     //~v57SI~
    	return 0;                                                  //~v57SR~
    UTRACED("Pobuff",Pobuff,PTRDIFF(pco,Pobuff));                  //~v6BjI~
    return Plen;                                                   //~v57SI~
}//ucvkandl                                                        //~v57SI~//~v7dmR~
//**************************************************************** //~v57VI~
//*reverse tbl clraeteion ascii-->EBC                              //~v57VI~
//*ret :length                                                     //~v57VI~
//**************************************************************** //~v57VI~
void ucvebcinitkandl(void)                                         //~v57VI~
{                                                                  //~v57VI~
	UCHAR *pc;                                                     //~v57VI~
    int ii;                                                        //~v57VI~
    UCHAR ch;                                                      //~v57VI~
//********************                                             //~v57VI~
	pc=SebcCP1027;                                                 //~v57VI~
	for (ii=0;ii<256;ii++)                                         //~v57VI~
    {                                                              //~v57VI~
    	ch=*pc++;                                                  //~v57VI~
        if (ch!='.'                                                //~v57VR~
        &&  ch!=SebcCP290[ii])                                     //~v57VI~
        	SebcCP1027rev[ch]=(UCHAR)ii;                           //~v5eqR~
    }                                                              //~v57VI~
	pc=SebcCP290;                                                  //~v57VR~
	for (ii=0;ii<256;ii++)                                         //~v57VI~
    {                                                              //~v57VI~
    	ch=*pc++;                                                  //~v57VI~
        if (ch!='.'                                                //~v57VR~
        &&  ch!=SebcCP1027[ii])                                    //~v57VI~
        	SebcCP290rev[ch]=(UCHAR)ii;                            //~v5eqR~
//        UTRACEP("%s:SebcCP290rev[%02x]=%02x,Sebc1027[%02x]=%02x\n",UTT,ch,ii,ii,SebcCP1027[ii]);//~v7dpR~//~v7dmR~
    }                                                              //~v57VI~
    UTRACED("SebcCP290",SebcCP290,256);                      //~v6BjI~//~v7dmR~
    UTRACED("SebcCP1027rev",SebcCP1027rev,256);                    //~v7dmI~
    UTRACED("SebcCP1027",SebcCP1027,256);                    //~v6BjI~//~v7dmI~
    UTRACED("SebcCP290rev",SebcCP290rev,256);                      //~v7dmI~
    return;                                                        //~v57VI~
}//ucvebcinitkandl                                                 //~v57VI~
//**************************************************************** //~v5emR~
//* from xcv                                                       //~v6BjI~
//*ebc-->sjis                                                      //~v5emR~
//*ret :none                                                       //~v5emR~
//**************************************************************** //~v5emR~
int ucvebc2_chkprintsbcs(int Popt,int Prepchar)                    //~v5emR~
{                                                                  //~v5emR~
//  UCHAR cv256out[256],cv256inp[256],*pc;                         //~v5emR~//~v7dAR~
    UCHAR cv256out[512],cv256inp[256],*pc; //asc2ebc may expand output by SO/SI insert//~v7dAI~
    int ans,key,outlen,ii,jj;                                      //~v5emR~
//********************                                             //~v5emR~
    UTRACEP("%s:opt=%08x,repch=%02x\n",UTT,Popt,Prepchar);         //~v7dAI~
    outlen=0;   //asc2ebc                                          //~v7dAI~
    pc=cv256inp;                                                   //~v5emR~
    for (ii=0;ii<256;ii++)                                         //~v5emR~
        *pc++=(UCHAR)ii;                                           //~v5eqR~
    int opt=Popt & ~EBC2ASC_DBCS;                                  //~v7dAI~
    if (Popt & EBC2ASC_A2E)                                        //~v5emR~
    {                                                              //~v5emR~
        printf("*** SJIS --> EBCDIC SBCS conversion table ***\n"); //~v5emR~
//      ucvasc2ebc(Popt,cv256inp,0,cv256out,256,Prepchar,&outlen); //~v5emR~//~v7dAR~
        ucvasc2ebc(opt,cv256inp,0,cv256out,256,Prepchar,&outlen);  //~v7dAI~
    }                                                              //~v5emR~
    else                                                           //~v5emR~
    {                                                              //~v5emR~
        printf("*** EBCDIC --> SJIS SBCS conversion table ***\n"); //~v5emR~
//      ucvebc2asc(Popt,cv256inp,0,cv256out,256,Prepchar,&outlen); //~v5emR~//~v7dAR~
        ucvebc2asc(opt,cv256inp,0,cv256out,256,Prepchar,&outlen);  //~v7dAI~
    }                                                              //~v5emR~
    UTRACED("cv256out",cv256out,sizeof(cv256out));                 //~v7dAI~
    printf("***   option:");                                       //~v5emI~
    if (Prepchar)                                                  //~v5emI~
    	printf("err-char=\"%c\"",Prepchar);                        //~v5emR~
    else                                                           //~v5emI~
    	printf("err-char=?(default)");                             //~v5emI~
    if (Popt & EBC2ASC_CTL)                                        //~v5emI~
    	printf(" default:no ANK/CRLF");                            //~v5enR~
    else                                                           //~v5emI~
    if (Popt & EBC2ASC_CRLF)                                       //~v5emI~
        printf(" CRLF ");                                          //~v5emI~
    else                                                           //~v5emI~
        printf(" ANK ");                                           //~v5emI~
//  if (Popt & EBC2ASC_SBCSMAP037)                                 //~v7dAR~
    if ((UINT)Popt & EBC2ASC_SBCSMAP037)                           //~v7dAI~
        printf(" CP037");                                          //~v7dAI~
    else                                                           //~v7dAI~
    if (Popt & EBC2ASC_CP290)                                      //~v5eqI~
        printf(" CP290");                                          //~v5eqI~
    else                                                           //~v5eqI~
//      printf(" CP1027(default)");                                //~v5eqR~//~v7dAR~
        printf(" CP1027");                                         //~v7dAI~
#ifdef W32                                                         //~v7dAI~
    ULPTR pconverter;                                              //~v7dAI~
	udbcschk_getbaseconverter(0,&pconverter,0/*dbcstbl*/);     //~v66KI~//~v7dAI~
    printf(" local-codepage=%d",(int)pconverter);                  //~v7dAR~
#else                                                              //~v7dAI~
	char *charset=utfcvsetdefaultlocale();                         //~v7dAR~
    printf(" local-charset=%s",charset);                           //~v7dAR~
#endif                                                             //~v7dAI~
    printf("\n");                                                  //~v5emI~
    printf("    0-    1-    2-    3-    4-    5-    6-    7-    8-    9-    a-    b-    c-    d-    e-    f-\n");//~v5enR~
    for (ii=0;ii<16;ii++)                                          //~v5emR~
    {                                                              //~v5emR~
        printf("-%1x ",ii);                                        //~v5enR~
        for (jj=0;jj<16;jj++)                                      //~v5emR~
        {                                                          //~v5emR~
            key=cv256inp[(jj<<4)+ii];                              //~v5emI~
            ans=cv256out[(jj<<4)+ii];                              //~v5emR~
		    if (Popt & EBC2ASC_A2E)                                //~v5emI~
    		  if (!(Popt & EBC2ASC_CTL))                           //~v5enR~
                if (key<' ')                                       //~v5enI~
        	    	printf(" %02x:%02x",key,ans);                  //~v5enI~
                else                                               //~v5enI~
        	    	printf(" %c :%02x",key,ans);                   //~v5enI~
              else                                                 //~v5enI~
        	    printf(" %c :%02x",key,ans);                       //~v5enR~
            else                                                   //~v5emI~
        	    printf(" %02x:%c ",ans,ans);                       //~v5enR~
        }                                                          //~v5emR~
        printf("\n");                                              //~v5emI~
    }                                                              //~v5emR~
    return 0;                                                      //~v5emR~
}//ucvebc2_chkprintsbcs                                            //~v5emR~
//**************************************************************** //~v68hI~
//*ebc-->sjis                                                      //~v68hI~
//*ret :1:yes,0:no                                                 //~v68hI~
//**************************************************************** //~v68hI~
int ucvebc_chkeolopt(int Popt,int *Ppebcopt,int Pmiscopt)          //~v68hR~
{                                                                  //~v68hI~
	int rc=0;                                                      //~v68hR~
//********************                                             //~v68hI~
    if (Popt & UCVEBCCEO_INPUTEOL)  //chk input eol have to be ignore//~v68hI~
    {	                                                           //~v68hI~
       	if (*Ppebcopt & EBC2ASC_A2E)    //ASC2EBC,no RECORD mode for ASC file//~v68hR~
       	{                                                          //~v68hI~
            rc=1;						//ignore input EOLid,set output EOL depend SETEOL option//~v68hR~
       	}                                                          //~v68hI~
        else //EBC2ASC                                             //~v68hI~
        {                                                          //~v68hI~
       		if (!(*Ppebcopt & EBC2ASC_FIXEDLRECL))    //not fixed LRECL//~v68hI~
            	rc=1;						//ignore input EOLid   //~v68hI~
        }                                                          //~v68hI~
    }                                                              //~v68hI~
    else                                                           //~v68hI~
    if (Popt & UCVEBCCEO_FGETSOPT)  //return fgets option for EBC file of B2x//~v68hI~
    {                                                              //~v68hI~
       	if (*Ppebcopt & EBC2ASC_A2E)    //x2B                      //~v68hI~
        {                                                          //~v68hI~
            ;   //read ascii                                       //~v68hR~
        }                                                          //~v68hI~
        else     //B2x                                             //~v68hR~
        {                                                          //~v68hI~
	        rc=UFGETS_EBC;      //binchk by ebc                    //~v68hI~
            if (!(*Ppebcopt & EBC2ASC_FIXEDLRECL))                 //~v68hI~
            {                                                      //~v68hI~
                *Ppebcopt|=EBC2ASC_SETEOL;  //no trans EOL(0a,x15) at read, append eol at write//~v68hI~
                if (!(Pmiscopt & MISC_ASCEOL))    //no asceol option parm//~v68hR~
                {                                                  //~vbBuI~
                    rc|=UFGETS_EBCEOL;       //eol by EBCNL(x15)   //~v68hI~
                    if (Pmiscopt & MISC_EBCEOLZ)                   //+vbBuR~
	                    rc|=UFGETS_EBCEOLZ;   //eol also by 0d15   //~vbBuI~
                }                                                  //~vbBuI~
            }                                                      //~v68hI~
        }                                                          //~v68hI~
    }                                                              //~v68hI~
	UTRACEP("%s:rc=%d,opt=%04x,Pmiscopt=%04x\n",UTT,rc,Popt,Pmiscopt);//~vbBuI~
    return rc;                                                     //~v68hI~
}//ucvebc_chkeolopt                                                //~v68hI~
//************************************************************************//~v7duI~
void adjustByMapE2A(int Popt,USHORT *Pmape2u,PUCVEXTCFG Ppcfg)     //~v7duR~
{                                                                  //~v7duI~
    USHORT *pe2u,*pe2ucfg;                                         //~v7duM~
    UCHAR *pe2a;                                                   //~v7duI~
    pe2u=Pmape2u;                                                  //~v7duI~
    pe2ucfg=Ppcfg->UCECsbcsmape2u;                                 //~v7duI~
    pe2a=Ppcfg->UCECsbcsmape2a;                                    //~v7duI~
    UTRACED("mape2u",pe2u,256*sizeof(USHORT));                     //~v7duR~
    UTRACED("cfgmape2u",pe2ucfg,256*sizeof(USHORT));               //~v7duR~
    for (int ii=0;ii<256;ii++,pe2u++,pe2ucfg++)                    //~v7duI~
    {                                                              //~v7duI~
    	if (*pe2ucfg)                                              //~v7duI~
        {                                                          //~v7duI~
            if (pe2a[ii])                                          //~v7duI~
            {                                                      //~v7duI~
                uerrmsg("ebccfg:Duplicated E2A for ebc=0x%02x",0,ii);//~v7duR~
            }                                                      //~v7duI~
		    UTRACEP("%s:ii=0x%02x:%02x-->%02x\n",UTT,ii,*pe2u,*pe2ucfg);//~v7duR~
        	*pe2u=*pe2ucfg;                                        //~v7duI~
        }                                                          //~v7duI~
    }                                                              //~v7duI~
    UTRACED("mape2u",Pmape2u,256*sizeof(USHORT));                  //~v7duI~
}//adjustByMapE2A                                                  //~v7duI~
//************************************************************************//~v7d9R~
//from ucvext_mapinitsetdefault when No cfg or USE_CONVERTER off   //~v7d9R~
//adjust B2A by B2U depending local converter                      //~v7d9R~
//************************************************************************//~v7d9R~
void ucvebc_adjustB2A(int Popt,void */*PUCVEXTCFG*/Ppcfgvoid)      //~v7d9R~
{                                                                  //~v7d9R~
	PUCVEXTCFG Ppcfg=(PUCVEXTCFG)Ppcfgvoid;                        //~v7d9I~
    UTRACEP("%s:Pcfg=%p,flag=0x%08x,flag2=0x%04x,localconverter=%p\n",UTT,Ppcfg,Ppcfg->UCECflag,Ppcfg->UCECflag2,Ppcfg->UCECconverterlocal);//~v7d9R~//~v7dbR~
    int opt=EBC2ASC_LOCALCV;                                       //~v7d9R~
    UCHAR repch='.';                                               //~v7d9R~
	if (!(Ppcfg->UCECflag & UCECF_LOCALCV)                         //~v7d9R~
    ||  !(Ppcfg->UCECconverterlocal))                              //~v7d9R~
    {                                                              //~v7d9R~
	    UTRACEP("%s:no local converter\n",UTT);                    //~v7d9R~
    	return;                                                    //~v7d9R~
    }                                                              //~v7d9R~
	if (!Sswinite2u)                                               //~v7d9R~
    	ucvebcinite2uJ();                                          //~v7d9R~
    USHORT *mape2u;                                                //~v7d9R~
    UCHAR  *mape2a;                                                //~v7d9R~
    if ((Ppcfg->UCECflag  & UCECF_SBCSDEF)                         //~v7dPI~
    &&  (Ppcfg->UCECflag2 & UCECF2_CP037_EURO))                    //~v7dPI~
    {                                                              //~v7dPI~
        UTRACEP("%s:CP037 EURO option\n",UTT);                     //~v7dPI~
    	Sibm037e2u[CHAR_EBC_CP037_CURRENCY]=CHAR_UCS_EURO;	//ebc9f-->u-20ac(euro)//~v7dPI~
    }                                                              //~v7dPI~
//  if (Ppcfg->UCECflag2 & UCECF2_CP931)                           //~v7d9R~//~v7dbR~
    if (Ppcfg->UCECflag2 & UCECF2_CP931                            //~v7dbI~
    ||  Ppcfg->UCECflag  & UCECF_SBCSDEF)                          //~v7dbI~
    {                                                              //~v7d9R~
    	mape2u=Sibm037e2u;                                         //~v7d9R~
    	mape2a=Sebc2asc037;                                        //~v7d9R~
	    UTRACEP("%s:CP931 Sibm037e2u=%p\n",UTT,mape2u);            //~v7d9R~
    }                                                              //~v7d9R~
    else                                                           //~v7d9R~
    if (Ppcfg->UCECflag & UCECF_CP939)                             //~v7d9R~
    {                                                              //~v7d9R~
    	mape2u=Sibm1027e2u;                                        //~v7d9R~
    	mape2a=SebcCP1027;                                         //~v7d9R~
	    UTRACEP("%s:CP939 Sibm1027e2u=%p\n",UTT,mape2u);           //~v7d9R~
    }                                                              //~v7d9R~
    else                                                           //~v7d9R~
    if (Ppcfg->UCECflag & UCECF_CP930)                             //~v7d9R~
    {                                                              //~v7d9R~
    	mape2u=Sibm290e2u;                                         //~v7d9R~
    	mape2a=SebcCP290;                                          //~v7d9R~
	    UTRACEP("%s:CP930 Sibm290e2u=%p\n",UTT,mape2u);            //~v7d9R~
    }                                                              //~v7d9R~
    else                                                           //~v7d9R~
    {                                                              //~v7d9R~
	    UTRACEP("%s:cp flag err UCECflag=0x%08x,flag2=0x%04x\n",UTT,Ppcfg->UCECflag,Ppcfg->UCECflag2);//~v7d9R~
    	return;                                                    //~v7d9R~
    }                                                              //~v7d9R~
    UTRACED("mape2u",mape2u,512);                                  //~v7d9R~
    UTRACED("mape2a before",mape2a,256);                           //~v7d9R~
    adjustByMapE2A(0,mape2u,Ppcfg);                                //~v7duR~
    ULPTR cvLocal=Ppcfg->UCECconverterlocal;                       //~v7d9R~
    int ii=0;                                                      //~v7d9R~
//    if (mape2u!=Sibm037e2u)                                      //~v7d9R~
//    {                                                            //~v7d9R~
//        ii=CHAR_EBC_SPACE;                                       //~v7d9R~
//        mape2u+=CHAR_EBC_SPACE;                                  //~v7d9R~
//    }                                                            //~v7d9R~
    for (;ii<256;ii++,mape2u++)                                    //~v7d9R~
    {                                                              //~v7d9R~
    	UWUCS/*ucs4*/ ucs=(UWUCS)(*mape2u);                        //~v7d9R~
        UCHAR mb;                                                  //~v7d9R~
        if (!ucs && ii!=0)                                         //~v7d9R~
        	mb=repch;                                              //~v7d9R~
        else                                                       //~v7d9R~
        if ((ucs>='a' && ucs <='z') || (ucs>='A' && ucs <='Z') || (ucs>='0' && ucs<='9'))//~v7d9R~
        	mb=(UCHAR)ucs;                                         //~v7d9R~
        else                                                       //~v7d9R~
        {                                                          //~v7d9R~
		    UCHAR wkmbs[8];                                        //~v7d9R~
            int mblen;                                             //~v7d9R~
			int rc2=ucvext_icuucs2local1(opt,cvLocal,ucs,wkmbs,&mblen);//~v7d9R~
            if (rc2 || mblen!=1)                                   //~v7d9R~
            	mb=repch;                                          //~v7d9R~
            else                                                   //~v7d9R~
            	mb=wkmbs[0];                                       //~v7d9R~
        }                                                          //~v7d9R~
        if (mb!=mape2a[ii])                                        //~v7dbI~
        {                                                          //~v7dbI~
        	UTRACEP("%s:mape2a[0x%02x] old=0x%02x,new=0x%02x\n",UTT,ii,mape2a[ii],mb);//~v7dbI~
        }                                                          //~v7dbI~
        mape2a[ii]=mb;                                             //~v7d9R~
//      UTRACEP("%s:ii=0x%02x,ucs=0x%04x,mb=0x%02x\n",UTT,ii,ucs,mb);//~v7d9R~//~v7dmR~
    }                                                              //~v7d9R~
    UTRACED("mape2a after",mape2a,256);                            //~v7d9R~
    UTRACEP("%s:exit\n",UTT);                                      //~v7d9R~
}//ucvext_adjustB2A                                                //~v7d9R~
