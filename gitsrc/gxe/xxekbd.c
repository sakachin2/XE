//CID://+vbu0R~:                 update#=  162221                  //~vbu0R~
//******************************************************************************//~v003I~
//vbu0:201217 Debian10 compiler warning                            //~vbu0I~
//vbs1:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //~vbs1I~
//vb2b:160119 (gxe)new --xxekbchku8 option to print utf8 char      //~vb2bI~
//var8:140127 gtk3 suppott                                         //~var8I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vak4:130904 deplicated function;XKeycodeToKeysym,use XGetKeyboardMapping//~vak4I~
//vaff:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(compile optio -Ox is required also)//~vaffI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va33:100131 (BUG)additional to va31,LeftAlt+AltGr+9(expected "Alt+]") not effective//~va33I~
//            because other function selected by scancode base     //~va33I~
//va31:100128 (BUG)AltGr(RightAlt key after "setxkbmap de" on JP106 kbd) generate ff03, gxe put 0x03 as kbd input//~va31I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va0b:090707 (BUG)gxe abend at init on z/os(reported by Dirk@...de)//~va0bI~
//v7a9:081106 (LNX:BUG)european lang,char is not by "key-down" but "on-char"(len=1)//~v7a9I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78N:080521 (LNXCON)rctl support                                 //~v78NI~
//v785:080229 (LNX:BUG)on curses version, Ctrl+[ is trated as 011b,//~v785I~
//            and Alt+{|} (A+S+[|]) is same as A+[|] 1b00/2b00.    //~v785I~
//            so chk Shift bit at function of A+[|]                //~v785I~
//v784:080229 (XXE:BUG)Ctrl+[ is trated as "[" not 1b-1b (Esc is defined but 01-1b)//~v784I~
//v76e:070618 (XXE)typematic support for R-Ctrl                    //~v740I~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v73tI~
//            so support specify trigger key on setupdialog        //~v73tI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v70m:060811 (!LNX Cons)change graph key input by Shift key not by opt linech on/off//~v70mI~
//v70f:060801 (BUG:WXE/WIN/XXE)C+10key(VK_Start,GDK_KP_Begin),C+"-",c+"+" is ignored//~v70fI~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~v69YI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v660:050812 (LNX:FC4)compile err(ligid sign chk)                 //~v660I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
#include <X11/Xos.h>                                               //~v78NI~
#include <X11/Xlib.h>                                              //~v78NI~
//                                                                 //~v003R~
#include <sys/timeb.h>                                             //~v69bI~
//                                                                 //~v69bI~
#include <ctype.h>                                                 //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~vXXEI~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#include <gdk/gdkkeysyms-compat.h>                                 //~var8R~
#endif                                                             //~var8R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
                                                                   //~v003I~
                                                                   //~v003I~
#include    "ulib.h"                                               //~v003I~
#include    "uque.h"                                               //~vXXEI~
#include    "ukbdsym.h"                                            //~vXXEI~
#include    "utrace.h"                                             //~v003I~
#include    "ucvebc.h"                                             //~v79zI~
#include    "ucvext.h"                                             //~v79zI~
#include    "uedit.h"                                              //~v76eR~
#define UFTIME                                                     //~vbs1I~
#include <umiscf.h>                                                //~vbs1I~
                                                                   //~vXXEI~
#include    <xe.h>                                                 //~vXXEM~
                                                                   //~vXXEI~
#include    "gxe.h"                                                //~vXXEI~
#include    "xxedef.h"                                             //~vXXEI~
#include    "xxemain.h"                                            //~vXXEI~
#include    "xxexei.h"                                             //~vXXEI~
#include    "xxeres.h"                                             //~vXXEI~
#include    "xxecsub.h"                                            //~vXXEI~
                                                                   //~vXXEI~
                                                                   //~vXXEI~
//===============================================================================//~v69bI~
#define SCROLLLOCKMSGINTVL  200  //interval between SCROLLLOCK up and VK_LEFT/RIGHT down to treate as mouse scroll//~v69bR~
//===============================================================================//~v003I~
#define MODX_PLAIN     0	//tbl index                            //~vXXEI~
#define MODX_SHIFT     1                                           //~vXXEI~
#define MODX_CONTROL   2                                           //~vXXEI~
#define MODX_ALT       3                                           //~vXXEI~
#define MODX_COMBI    -1                                           //~vXXER~
#define EXTKEY_MASK 0xff00                                         //~vXXEI~
//===============================================================================//~vXXEI~
//******************************                                   //~vXXEI~
//* for extendkey conversion ***                                   //~vXXEI~
//******************************                                   //~vXXEI~
typedef struct _KEYSYMTBL {UINT KSTkeysym;int KSTdoskey[4];} KEYSYMTBL, *PKEYSYMTBL;//~vXXEM~
static KEYSYMTBL Skeysymtbl[]={                                    //~vXXER~
// {  GDK_Escape         ,{KEY_ESC       ,KEY_S_ESC       ,KEY_C_ESC       ,KEY_A_ESC        }}, // 0xFF1B//~vXXER~
   {  GDK_Escape         ,{KEY_ESC       ,KEY_S_ESC       ,KEY_ESC         ,KEY_A_ESC        }}, // 0xFF1B Ctl+Esc=011b//~vXXEI~
   {  GDK_Tab            ,{KEY_TAB       ,KEY_S_TAB       ,KEY_C_TAB       ,KEY_A_TAB        }}, // 0xFF09//~vXXER~
   {  GDK_BackSpace      ,{KEY_BS        ,KEY_S_BS        ,KEY_C_BS        ,KEY_A_BS         }}, // 0xFF08//~vXXER~
   {  GDK_Return         ,{KEY_ENTER     ,KEY_S_ENTER     ,KEY_C_ENTER     ,KEY_A_ENTER      }}, // 0xFF0D//~vXXER~
   {  GDK_Insert         ,{KEY_INS       ,KEY_S_INS       ,KEY_C_INS       ,KEY_A_INS        }}, // 0xFF63//~vXXER~
   {  GDK_Delete         ,{KEY_DEL       ,KEY_S_DEL       ,KEY_C_DEL       ,KEY_A_DEL        }}, // 0xFFFF//~vXXER~
   {  GDK_Home           ,{KEY_HOME      ,KEY_S_HOME      ,KEY_C_HOME      ,KEY_A_HOME       }}, // 0xFF50//~vXXER~
   {  GDK_End            ,{KEY_END       ,KEY_S_END       ,KEY_C_END       ,KEY_A_END        }}, // 0xFF57//~vXXER~
   {  GDK_Page_Up        ,{KEY_PGUP      ,KEY_S_PGUP      ,KEY_C_PGUP      ,KEY_A_PGUP       }}, // 0xFF55//~vXXER~
   {  GDK_Page_Down      ,{KEY_PGDN      ,KEY_S_PGDN      ,KEY_C_PGDN      ,KEY_A_PGDN       }}, // 0xFF56//~vXXER~
   {  GDK_Left           ,{KEY_LEFT      ,KEY_S_LEFT      ,KEY_C_LEFT      ,KEY_A_LEFT       }}, // 0xFF51//~vXXER~
   {  GDK_Right          ,{KEY_RIGHT     ,KEY_S_RIGHT     ,KEY_C_RIGHT     ,KEY_A_RIGHT      }}, // 0xFF53//~vXXER~
   {  GDK_Up             ,{KEY_UP        ,KEY_S_UP        ,KEY_C_UP        ,KEY_A_UP         }}, // 0xFF52//~vXXER~
   {  GDK_Down           ,{KEY_DOWN      ,KEY_S_DOWN      ,KEY_C_DOWN      ,KEY_A_DOWN       }}, // 0xFF54//~vXXER~
//                                ,              ,                ,                ,//~vXXEI~
   {  GDK_F1             ,{KEY_F1        ,KEY_S_F1        ,KEY_C_F1        ,KEY_A_F1         }}, // 0xFFBE//~vXXER~
   {  GDK_F2             ,{KEY_F2        ,KEY_S_F2        ,KEY_C_F2        ,KEY_A_F2         }}, // 0xFFBF//~vXXER~
   {  GDK_F3             ,{KEY_F3        ,KEY_S_F3        ,KEY_C_F3        ,KEY_A_F3         }}, // 0xFFC0//~vXXER~
   {  GDK_F4             ,{KEY_F4        ,KEY_S_F4        ,KEY_C_F4        ,KEY_A_F4         }}, // 0xFFC1//~vXXER~
   {  GDK_F5             ,{KEY_F5        ,KEY_S_F5        ,KEY_C_F5        ,KEY_A_F5         }}, // 0xFFC2//~vXXER~
   {  GDK_F6             ,{KEY_F6        ,KEY_S_F6        ,KEY_C_F6        ,KEY_A_F6         }}, // 0xFFC3//~vXXER~
   {  GDK_F7             ,{KEY_F7        ,KEY_S_F7        ,KEY_C_F7        ,KEY_A_F7         }}, // 0xFFC4//~vXXER~
   {  GDK_F8             ,{KEY_F8        ,KEY_S_F8        ,KEY_C_F8        ,KEY_A_F8         }}, // 0xFFC5//~vXXER~
   {  GDK_F9             ,{KEY_F9        ,KEY_S_F9        ,KEY_C_F9        ,KEY_A_F9         }}, // 0xFFC6//~vXXER~
   {  GDK_F10            ,{KEY_F10       ,KEY_S_F10       ,KEY_C_F10       ,KEY_A_F10        }}, // 0xFFC7//~vXXER~
   {  GDK_F11            ,{KEY_F11       ,KEY_S_F11       ,KEY_C_F11       ,KEY_A_F11        }}, // 0xFFC8//~vXXER~
   {  GDK_F12            ,{KEY_F12       ,KEY_S_F12       ,KEY_C_F12       ,KEY_A_F12        }}, // 0xFFC9//~vXXER~
//**                                                               //~vXXEI~
//**if numlock on KP_x send num char by commit event               //~vXXEI~
//**if numlock off Shift+KP_x send num char by commit              //~vXXEI~
//**                                                               //~vXXEI~
   {  GDK_KP_0           ,{KEY_P0        ,KEY_S_P0        ,KEY_C_P0        ,KEY_A_P0         }}, // 0xFFB0//~vXXER~
   {  GDK_KP_1           ,{KEY_P1        ,KEY_S_P1        ,KEY_C_P1        ,KEY_A_P1         }}, // 0xFFB1//~vXXER~
   {  GDK_KP_2           ,{KEY_P2        ,KEY_S_P2        ,KEY_C_P2        ,KEY_A_P2         }}, // 0xFFB2//~vXXER~
   {  GDK_KP_3           ,{KEY_P3        ,KEY_S_P3        ,KEY_C_P3        ,KEY_A_P3         }}, // 0xFFB3//~vXXER~
   {  GDK_KP_4           ,{KEY_P4        ,KEY_S_P4        ,KEY_C_P4        ,KEY_A_P4         }}, // 0xFFB4//~vXXER~
   {  GDK_KP_5           ,{KEY_P5        ,KEY_S_P5        ,KEY_C_P5        ,KEY_A_P5         }}, // 0xFFB5//~vXXER~
   {  GDK_KP_Begin       ,{KEY_P5        ,KEY_S_P5        ,KEY_C_P5        ,KEY_A_P5         }}, // 0xFF9D//~v70fI~
   {  GDK_KP_6           ,{KEY_P6        ,KEY_S_P6        ,KEY_C_P6        ,KEY_A_P6         }}, // 0xFFB6//~vXXER~
   {  GDK_KP_7           ,{KEY_P7        ,KEY_S_P7        ,KEY_C_P7        ,KEY_A_P7         }}, // 0xFFB7//~vXXER~
   {  GDK_KP_8           ,{KEY_P8        ,KEY_S_P8        ,KEY_C_P8        ,KEY_A_P8         }}, // 0xFFB8//~vXXER~
   {  GDK_KP_9           ,{KEY_P9        ,KEY_S_P9        ,KEY_C_P9        ,KEY_A_P9         }}, // 0xFFB9//~vXXER~
   {  GDK_KP_Decimal     ,{KEY_PPERIOD   ,KEY_S_PPERIOD   ,KEY_C_PPERIOD   ,KEY_A_PPERIOD    }}, // 0xFFAE//~vXXER~
   {  GDK_KP_Divide      ,{KEY_PDIVIDE   ,KEY_S_PDIVIDE   ,KEY_C_PDIVIDE   ,KEY_A_PDIVIDE    }}, // 0xFFAF//~vXXER~
   {  GDK_KP_Multiply    ,{KEY_PMULTIPLY ,KEY_S_PMULTIPLY ,KEY_C_PMULTIPLY ,KEY_A_PMULTIPLY  }}, // 0xFFAA//~vXXER~
   {  GDK_KP_Subtract    ,{KEY_PMINUS    ,KEY_S_PMINUS    ,KEY_C_PMINUS    ,KEY_A_PMINUS     }}, // 0xFFAD//~vXXER~
   {  GDK_KP_Add         ,{KEY_PPLUS     ,KEY_S_PPLUS     ,KEY_C_PPLUS     ,KEY_A_PPLUS      }}, // 0xFFAB//~vXXER~
   {  GDK_KP_Enter       ,{KEY_PENTR     ,KEY_S_PENTR     ,KEY_C_PENTR     ,KEY_A_PENTR      }}, // 0xFF8D//~vXXER~
//                                ,              ,                ,                ,//~vXXEI~
   {  GDK_KP_Home        ,{KEY_HOME      ,KEY_S_HOME      ,KEY_C_HOME      ,KEY_A_HOME       }}, // 0xFF95//~vXXER~
   {  GDK_KP_Up          ,{KEY_UP        ,KEY_S_UP        ,KEY_C_UP        ,KEY_A_UP         }}, // 0xFF97//~vXXER~
   {  GDK_KP_Page_Up     ,{KEY_PGUP      ,KEY_S_PGUP      ,KEY_C_PGUP      ,KEY_A_PGUP       }}, // 0xFF9A//~vXXER~
   {  GDK_KP_Left        ,{KEY_LEFT      ,KEY_S_LEFT      ,KEY_C_LEFT      ,KEY_A_LEFT       }}, // 0xFF96//~vXXER~
   {  GDK_KP_Right       ,{KEY_RIGHT     ,KEY_S_RIGHT     ,KEY_C_RIGHT     ,KEY_A_RIGHT      }}, // 0xFF98//~vXXER~
   {  GDK_KP_End         ,{KEY_END       ,KEY_S_END       ,KEY_C_END       ,KEY_A_END        }}, // 0xFF9C//~vXXER~
   {  GDK_KP_Down        ,{KEY_DOWN      ,KEY_S_DOWN      ,KEY_C_DOWN      ,KEY_A_DOWN       }}, // 0xFF99//~vXXER~
   {  GDK_KP_Page_Down   ,{KEY_PGDN      ,KEY_S_PGDN      ,KEY_C_PGDN      ,KEY_A_PGDN       }}, // 0xFF9B//~vXXER~
   {  GDK_KP_Insert      ,{KEY_INS       ,KEY_S_INS       ,KEY_C_INS       ,KEY_A_INS        }}, // 0xFF9E//~vXXER~
   {  GDK_KP_Delete      ,{KEY_DEL       ,KEY_S_DEL       ,KEY_C_DEL       ,KEY_A_DEL        }}, // 0xFF9F//~vXXER~
                                                                   //~vXXEI~
// {  GDK_Break          ,{KEY_NOTUSE    ,KEY_NOTUSE      ,0               ,KEY_NOTUSE       }}, // 0xFF6B(Ctrl+Pause)//~vXXER~
                                                                   //~vXXEI~
   {  0                  ,{0             ,0               ,0               ,0                }}, // 0xFF9F//~vXXER~
};	//Skeysymtbl                                                   //~vXXER~
static	PKEYSYMTBL Spkeysymtbl[256];                               //~vXXER~
static	PKEYSYMTBL Spkeysymtblbykeycode[256];                      //~v78NI~
//******************************                                   //~vXXEI~
//* for Alt+char conversion    *                                   //~vXXEI~
//******************************                                   //~vXXEI~
//typedef struct _ALTCHRTBL {UINT ACTkeysym;int ACTdoskey;} ALTCHRTBL, *PALTCHRTBL;//~v70mR~
typedef struct _ALTCHRTBL {UINT ACTkeysym;int ACTdoskey;int ACTscancode;} ALTCHRTBL, *PALTCHRTBL;//~v70mI~
static  ALTCHRTBL Saltchrtbl[]={                                   //~vXXER~
//     {                  ,                  },//-1,      //0x00   //~vXXEI~
//     {                  ,                  },//-1,      //0x01   //~vXXEI~
//     {                  ,                  },//-1,      //0x02   //~vXXEI~
//     {                  ,                  },//-1,      //0x03   //~vXXEI~
//     {                  ,                  },//-1,      //0x04   //~vXXEI~
//     {                  ,                  },//-1,      //0x05   //~vXXEI~
//     {                  ,                  },//-1,      //0x06   //~vXXEI~
//     {                  ,                  },//-1,      //0x07   //~vXXEI~
//     { GDK_BackSpace    ,KEY_A_BS          },//0x0e00,  //0x08  BackSpace   ff08//~v70mR~
       { GDK_BackSpace    ,KEY_A_BS     ,0x16},//0x0e00,  //0x08  BackSpace   ff08//~v70mI~
//     { GDK_Tab          ,KEY_A_TAB         },//0xa500,  //0x09  Tab         ff09//~v70mR~
       { GDK_Tab          ,KEY_A_TAB    ,0x17},//0xa500,  //0x09  Tab         ff09//~v70mI~
//     {                  ,                  },//-1,      //0x0a   //~vXXEI~
//     {                  ,                  },//-1,      //0x0b   //~vXXEI~
//     {                  ,                  },//-1,      //0x0c   //~vXXEI~
//     { GDK_Return       ,KEY_A_ENTER       },//0x1c00,  //0x0d  Enter       ff0d//~v70mR~
       { GDK_Return       ,KEY_A_ENTER  ,0x24},//0x1c00,  //0x0d  Enter       ff0d//~v70mI~
//     {                  ,                  },//-1,      //0x0e   //~vXXEI~
//     {                  ,                  },//-1,      //0x0f   //~vXXEI~
//     {                  ,                  },//-1,      //0x10   //~vXXEI~
//     {                  ,                  },//-1,      //0x11   //~vXXEI~
//     {                  ,                  },//-1,      //0x12   //~vXXEI~
//     {                  ,                  },//-1,      //0x13   //~vXXEI~
//     {                  ,                  },//-1,      //0x14   //~vXXEI~
//     {                  ,                  },//-1,      //0x15   //~vXXEI~
//     {                  ,                  },//-1,      //0x16   //~vXXEI~
//     {                  ,                  },//-1,      //0x17   //~vXXEI~
//     {                  ,                  },//-1,      //0x18   //~vXXEI~
//     {                  ,                  },//-1,      //0x19   //~vXXEI~
//     {                  ,                  },//-1,      //0x1a   //~vXXEI~
//     { GDK_Escape       ,KEY_A_ESC         },//0x0100,  //0x1b  Escape      ff1b//~v70mR~
       { GDK_Escape       ,KEY_A_ESC    ,0x09},//0x0100,  //0x1b  Escape      ff1b//~v70mI~
//     {                  ,                  },//-1,      //0x1c   //~vXXEI~
//     {                  ,                  },//-1,      //0x1d   //~vXXEI~
//     {                  ,                  },//-1,      //0x1e   //~vXXEI~
//     {                  ,                  },//-1,      //0x1f   //~vXXEI~
       { GDK_space        ,KEY_A_SPACE       },//0x3920,  //0x20                20//~vXXEI~
//     {                  ,                  },//-1,      //0x21  !//~vXXEI~
//     {                  ,                  },//-1,      //0x22  "//~vXXEI~
//     {                  ,                  },//-1,      //0x23  #//~vXXEI~
//     {                  ,                  },//-1,      //0x24  $//~vXXEI~
//     {                  ,                  },//-1,      //0x25  %//~vXXEI~
//     {                  ,                  },//-1,      //0x26  &//~vXXEI~
//     {                  ,                  },//-1,      //0x27  '//~vXXEI~
//     {                  ,                  },//-1,      //0x28  (//~vXXEI~
//     {                  ,                  },//-1,      //0x29  )//~vXXEI~
//     {                  ,                  },//-1,      //0x2a  *//~vXXEI~
//     {                  ,                  },//-1,      //0x2b  +//~vXXEI~
       { GDK_comma        ,KEY_A_COMMA       },//0x3300,  //0x2c  ,             2c//~vXXEI~
//     { GDK_minus        ,KEY_A_MINUS       },//0x8200,  //0x2d  -             2d//~v70mR~
       { GDK_minus        ,KEY_A_MINUS  ,0x14},//0x8200,  //0x2d  -             2d//~v70mI~
       { GDK_period       ,KEY_A_PERIOD      },//0x3400,  //0x2e  .             2e//~vXXEI~
//     { GDK_slash        ,KEY_A_SLASH       },//0x3500,  //0x2f  /             2f//~v70mR~
       { GDK_slash        ,KEY_A_SLASH       },//0x3500,  //0x2f  /  use A+"/" for combine mode switch//~va30I~
//     { GDK_0            ,KEY_A_0           },//0x8100,  //0x30  0             30//~v70mR~
//     { GDK_1            ,KEY_A_1           },//0x7800,  //0x31  1             31//~v70mR~
//     { GDK_2            ,KEY_A_2           },//0x7900,  //0x32  2             32//~v70mR~
//     { GDK_3            ,KEY_A_3           },//0x7a00,  //0x33  3             33//~v70mR~
//     { GDK_4            ,KEY_A_4           },//0x7b00,  //0x34  4             34//~v70mR~
//     { GDK_5            ,KEY_A_5           },//0x7c00,  //0x35  5             35//~v70mR~
//     { GDK_6            ,KEY_A_6           },//0x7d00,  //0x36  6             36//~v70mR~
//     { GDK_7            ,KEY_A_7           },//0x7e00,  //0x37  7             37//~v70mR~
//     { GDK_8            ,KEY_A_8           },//0x7f00,  //0x38  8             38//~v70mR~
//     { GDK_9            ,KEY_A_9           },//0x8000,  //0x39  9             39//~v70mR~
       { GDK_0            ,KEY_A_0      ,0x13},//0x8100,  //0x30  0             30//~v70mI~
       { GDK_1            ,KEY_A_1      ,0x0a},//0x7800,  //0x31  1             31//~v70mI~
       { GDK_2            ,KEY_A_2      ,0x0b},//0x7900,  //0x32  2             32//~v70mI~
       { GDK_3            ,KEY_A_3      ,0x0c},//0x7a00,  //0x33  3             33//~v70mI~
       { GDK_4            ,KEY_A_4      ,0x0d},//0x7b00,  //0x34  4             34//~v70mI~
       { GDK_5            ,KEY_A_5      ,0x0e},//0x7c00,  //0x35  5             35//~v70mI~
       { GDK_6            ,KEY_A_6      ,0x0f},//0x7d00,  //0x36  6             36//~v70mI~
       { GDK_7            ,KEY_A_7      ,0x10},//0x7e00,  //0x37  7             37//~v70mI~
       { GDK_8            ,KEY_A_8      ,0x11},//0x7f00,  //0x38  8             38//~v70mI~
       { GDK_9            ,KEY_A_9      ,0x12},//0x8000,  //0x39  9             39//~v70mI~
       { GDK_colon        ,KEY_A_COLON       },//0x2800,  //0x3a  :             3a//~vXXEI~
       { GDK_semicolon    ,KEY_A_SEMICOLON   },//0x2700,  //0x3b  ;             3b//~vXXEI~
//     {                  ,                  },//-1,      //0x3c   //~vXXEI~
//     {                  ,                  },//-1,      //0x3d   //~vXXEI~
//     { GDK_equal        ,KEY_A_EQUAL       },//0x8300,  //0x3d  = //S+'-' on japanese kbd, '^' on english kbd//~v69YI~,//~v70mR~
//     {                  ,                  },//-1,      //0x3e   //~vXXEI~
//     {                  ,                  },//-1,      //0x3f   //~vXXEI~
       { GDK_at           ,KEY_A_ACCNT       },//0x1a00,  //0x40    @           40//~vXXEI~
//     {                  ,                  },//-1,      //0x41    A//~vXXEI~
//     {                  ,                  },//-1,      //0x42    B//~vXXEI~
//     {                  ,                  },//-1,      //0x43    C//~vXXEI~
//     {                  ,                  },//-1,      //0x44    D//~vXXEI~
//     {                  ,                  },//-1,      //0x45    E//~vXXEI~
//     {                  ,                  },//-1,      //0x46    F//~vXXEI~
//     {                  ,                  },//-1,      //0x47    G//~vXXEI~
//     {                  ,                  },//-1,      //0x48    H//~vXXEI~
//     {                  ,                  },//-1,      //0x49    I//~vXXEI~
//     {                  ,                  },//-1,      //0x4a    J//~vXXEI~
//     {                  ,                  },//-1,      //0x4b    K//~vXXEI~
//     {                  ,                  },//-1,      //0x4c    L//~vXXEI~
//     {                  ,                  },//-1,      //0x4d    M//~vXXEI~
//     {                  ,                  },//-1,      //0x4e    N//~vXXEI~
//     {                  ,                  },//-1,      //0x4f    O//~vXXEI~
//     {                  ,                  },//-1,      //0x50    P//~vXXEI~
//     {                  ,                  },//-1,      //0x51    Q//~vXXEI~
//     {                  ,                  },//-1,      //0x52    R//~vXXEI~
//     {                  ,                  },//-1,      //0x53    S//~vXXEI~
//     {                  ,                  },//-1,      //0x54    T//~vXXEI~
//     {                  ,                  },//-1,      //0x55    U//~vXXEI~
//     {                  ,                  },//-1,      //0x56    V//~vXXEI~
//     {                  ,                  },//-1,      //0x57    W//~vXXEI~
//     {                  ,                  },//-1,      //0x58    X//~vXXEI~
//     {                  ,                  },//-1,      //0x59    Y//~vXXEI~
//     {                  ,                  },//-1,      //0x5a    Z//~vXXEI~
       { GDK_bracketleft  ,KEY_A_LMP         },//0x1b00,  //0x5b   [            5b//~vXXER~
       { GDK_braceleft    ,KEY_A_LBRACE      },//0x1b00,  //0x7b   { /doskey is same as A+[//~v785I~
//     {                  ,                  },//-1,      //0x5c   "\"//~vXXEI~
       { GDK_bracketright ,KEY_A_RMP         },//0x2b00,  //0x5d   ]            5d//~vXXEI~
       { GDK_braceright   ,KEY_A_RBRACE      },//0x1b00,  //0x7d   } /doskey is same as A+}//~v785I~
//     { GDK_asciicircum  ,KEY_A_HAT         },//0x8300,  //0x5e   ^            5e//~v70mR~
       { GDK_asciicircum  ,KEY_A_HAT    ,0x15},//0x8300,  //0x5e   ^            5e//~v70mI~
//     {                  ,                  },//-1,      //0x5f    _ under_score//~vXXEI~
//     {                                                           //~vXXEI~
//     {                  ,                  },//-1,      //0x60    ` grave//~vXXEI~
       { GDK_a            ,KEY_A_a           },//0x1e00,  //0x61    a//~vXXEI~
       { GDK_b            ,KEY_A_b           },//0x3000,  //0x62    b//~vXXEI~
       { GDK_c            ,KEY_A_c           },//0x2e00,  //0x63    c//~vXXEI~
       { GDK_d            ,KEY_A_d           },//0x2000,  //0x64    d//~vXXEI~
       { GDK_e            ,KEY_A_e           },//0x1200,  //0x65    e//~vXXEI~
       { GDK_f            ,KEY_A_f           },//0x2100,  //0x66    f//~vXXEI~
       { GDK_g            ,KEY_A_g           },//0x2200,  //0x67    g//~vXXEI~
       { GDK_h            ,KEY_A_h           },//0x2300,  //0x68    h//~vXXEI~
       { GDK_i            ,KEY_A_i           },//0x1700,  //0x69    i//~vXXEI~
       { GDK_j            ,KEY_A_j           },//0x2400,  //0x6a    j//~vXXEI~
       { GDK_k            ,KEY_A_k           },//0x2500,  //0x6b    k//~vXXEI~
       { GDK_l            ,KEY_A_l           },//0x2600,  //0x6c    l//~vXXEI~
       { GDK_m            ,KEY_A_m           },//0x3200,  //0x6d    m//~vXXEI~
       { GDK_n            ,KEY_A_n           },//0x3100,  //0x6e    n//~vXXEI~
       { GDK_o            ,KEY_A_o           },//0x1800,  //0x6f    o//~vXXEI~
       { GDK_p            ,KEY_A_p           },//0x1900,  //0x70    p//~vXXEI~
       { GDK_q            ,KEY_A_q           },//0x1000,  //0x71    q//~vXXEI~
       { GDK_r            ,KEY_A_r           },//0x1300,  //0x72    r//~vXXEI~
       { GDK_s            ,KEY_A_s           },//0x1f00,  //0x73    s//~vXXEI~
       { GDK_t            ,KEY_A_t           },//0x1400,  //0x74    t//~vXXEI~
       { GDK_u            ,KEY_A_u           },//0x1600,  //0x75    u//~vXXEI~
       { GDK_v            ,KEY_A_v           },//0x2f00,  //0x76    v//~vXXEI~
       { GDK_w            ,KEY_A_w           },//0x1100,  //0x77    w//~vXXEI~
       { GDK_x            ,KEY_A_x           },//0x2d00,  //0x78    x//~vXXEI~
       { GDK_y            ,KEY_A_y           },//0x1500,  //0x79    y//~vXXEI~
       { GDK_z            ,KEY_A_z           },//0x2c00,  //0x7a    z//~vXXEI~
       { GDK_A            ,KEY_A_a           },//0x1e00,  //0x41    A//~vXXEI~
       { GDK_B            ,KEY_A_b           },//0x3000,  //0x42    B//~vXXEI~
       { GDK_C            ,KEY_A_c           },//0x2e00,  //0x43    C//~vXXEI~
       { GDK_D            ,KEY_A_d           },//0x2000,  //0x44    D//~vXXEI~
       { GDK_E            ,KEY_A_e           },//0x1200,  //0x45    E//~vXXEI~
       { GDK_F            ,KEY_A_f           },//0x2100,  //0x46    F//~vXXEI~
       { GDK_G            ,KEY_A_g           },//0x2200,  //0x47    G//~vXXEI~
       { GDK_H            ,KEY_A_h           },//0x2300,  //0x48    H//~vXXEI~
       { GDK_I            ,KEY_A_i           },//0x1700,  //0x49    I//~vXXEI~
       { GDK_J            ,KEY_A_j           },//0x2400,  //0x4a    J//~vXXEI~
       { GDK_K            ,KEY_A_k           },//0x2500,  //0x4b    K//~vXXEI~
       { GDK_L            ,KEY_A_l           },//0x2600,  //0x4c    L//~vXXEI~
       { GDK_M            ,KEY_A_m           },//0x3200,  //0x4d    M//~vXXEI~
       { GDK_N            ,KEY_A_n           },//0x3100,  //0x4e    N//~vXXEI~
       { GDK_O            ,KEY_A_o           },//0x1800,  //0x4f    O//~vXXEI~
       { GDK_P            ,KEY_A_p           },//0x1900,  //0x50    P//~vXXEI~
       { GDK_Q            ,KEY_A_q           },//0x1000,  //0x51    Q//~vXXEI~
       { GDK_R            ,KEY_A_r           },//0x1300,  //0x52    R//~vXXEI~
       { GDK_S            ,KEY_A_s           },//0x1f00,  //0x53    S//~vXXEI~
       { GDK_T            ,KEY_A_t           },//0x1400,  //0x54    T//~vXXEI~
       { GDK_U            ,KEY_A_u           },//0x1600,  //0x55    U//~vXXEI~
       { GDK_V            ,KEY_A_v           },//0x2f00,  //0x56    V//~vXXEI~
       { GDK_W            ,KEY_A_w           },//0x1100,  //0x57    W//~vXXEI~
       { GDK_X            ,KEY_A_x           },//0x2d00,  //0x58    X//~vXXEI~
       { GDK_Y            ,KEY_A_y           },//0x1500,  //0x59    Y//~vXXEI~
       { GDK_Z            ,KEY_A_z           },//0x2c00,  //0x5a    Z//~vXXEI~
//     {                  ,                  },//-1,      //0x7b   //~vXXEI~
//     {                  ,                  },//-1,      //0x7c   //~vXXEI~
//     {                  ,                  },//-1,      //0x7d   //~vXXEI~
//     {                  ,                  },//-1,      //0x7e   //~vXXEI~
//     {                  ,                  },//-1       //0x7f   //~vXXEI~
       { 0                ,0                 }                     //~vXXEI~
                    };                                             //~vXXEI~
#define MAX_ACT 128                                                //~vXXEM~
static	PALTCHRTBL Spaltchrtbl[MAX_ACT];    //index table          //~vXXEI~
static	PALTCHRTBL Spshiftaltchrtbl[MAX_ACT];    //index table;Shift+Alt+//~v70mI~
//******************************                                   //~vXXEI~
//* for Ctrl+char conversion   *                                   //~vXXEI~
//******************************                                   //~vXXEI~
typedef struct _CTLCHRTBL {UINT CCTkeysym;int CCTdoskey;} CTLCHRTBL, *PCTLCHRTBL;//~vXXEI~
static  CTLCHRTBL     Sctlchrtbl[]={                               //~vXXER~
    {  GDK_2              , KEY_C_2       },// 0x03/*00*/  ,      //0x00  return null//~vXXEI~
    {  GDK_a              , KEY_C_a       },// 0x1e,//    0,      //0x01  ctrl+a//~vXXEI~
    {  GDK_b              , KEY_C_b       },// 0x30,//    0,      //0x02  ctrl+b//~vXXEI~
    {  GDK_c              , KEY_C_c       },// 0x2e,//    0,      //0x03  ctrl+c//~vXXEI~
    {  GDK_d              , KEY_C_d       },// 0x20,//    0,      //0x04  ctrl+d//~vXXEI~
    {  GDK_e              , KEY_C_e       },// 0x12,//    0,      //0x05  ctrl+e//~vXXEI~
    {  GDK_f              , KEY_C_f       },// 0x21,//    0,      //0x06  ctrl+f//~vXXEI~
    {  GDK_g              , KEY_C_g       },// 0x22,//    0,      //0x07  ctrl+g//~vXXEI~
    {  GDK_h              , KEY_C_h       },// 0x0e/*08*/  ,      //0x08  BackSpace//~vXXEI~
    {  GDK_i              , KEY_C_i       },// 0x0f/*09*/  ,      //0x09  Tab//~vXXEI~
    {  GDK_j              , KEY_C_j       },// 0x24,//    0,      //0x0a  ctrl+j//~vXXEI~
    {  GDK_k              , KEY_C_k       },// 0x25,//    0,      //0x0b  ctrl+k//~vXXEI~
    {  GDK_l              , KEY_C_l       },// 0x26,//    0,      //0x0c  ctrl+l//~vXXEI~
    {  GDK_m              , KEY_C_m       },// 0x1c/*0d*/  ,      //0x0d  Enter//~vXXEI~
    {  GDK_n              , KEY_C_n       },// 0x31,//    0,      //0x0e  ctrl+n//~vXXEI~
    {  GDK_o              , KEY_C_o       },// 0x18,//    0,      //0x0f  ctrl+o//~vXXEI~
    {  GDK_p              , KEY_C_p       },// 0x19,//    0,      //0x10  ctrl+p//~vXXEI~
    {  GDK_q              , KEY_C_q       },// 0x10,//    0,      //0x11  ctrl+q//~vXXEI~
    {  GDK_r              , KEY_C_r       },// 0x13,//    0,      //0x12  ctrl+r//~vXXEI~
    {  GDK_s              , KEY_C_s       },// 0x1f,//    0,      //0x13  ctrl+s//~vXXEI~
    {  GDK_t              , KEY_C_t       },// 0x14,//    0,      //0x14  ctrl+t//~vXXEI~
    {  GDK_u              , KEY_C_u       },// 0x16,//    0,      //0x15  ctrl+u//~vXXEI~
    {  GDK_v              , KEY_C_v       },// 0x2f,//    0,      //0x16  ctrl+v//~vXXEI~
    {  GDK_w              , KEY_C_w       },// 0x11,//    0,      //0x17  ctrl+w//~vXXEI~
    {  GDK_x              , KEY_C_x       },// 0x2d,//    0,      //0x18  ctrl+x//~vXXEI~
    {  GDK_y              , KEY_C_y       },// 0x15,//    0,      //0x19  ctrl+y//~vXXEI~
    {  GDK_z              , KEY_C_z       },// 0x2c,//    0,      //0x1a  ctrl+z//~vXXEI~
    {  GDK_A              , KEY_C_a       },// 0x1e,//    0,      //0x01  ctrl+a//~vXXEI~
    {  GDK_B              , KEY_C_b       },// 0x30,//    0,      //0x02  ctrl+b//~vXXEI~
    {  GDK_C              , KEY_C_c       },// 0x2e,//    0,      //0x03  ctrl+c//~vXXEI~
    {  GDK_D              , KEY_C_d       },// 0x20,//    0,      //0x04  ctrl+d//~vXXEI~
    {  GDK_E              , KEY_C_e       },// 0x12,//    0,      //0x05  ctrl+e//~vXXEI~
    {  GDK_F              , KEY_C_f       },// 0x21,//    0,      //0x06  ctrl+f//~vXXEI~
    {  GDK_G              , KEY_C_g       },// 0x22,//    0,      //0x07  ctrl+g//~vXXEI~
    {  GDK_H              , KEY_C_h       },// 0x0e/*08*/  ,      //0x08  BackSpace//~vXXEI~
    {  GDK_I              , KEY_C_i       },// 0x0f/*09*/  ,      //0x09  Tab//~vXXEI~
    {  GDK_J              , KEY_C_j       },// 0x24,//    0,      //0x0a  ctrl+j//~vXXEI~
    {  GDK_K              , KEY_C_k       },// 0x25,//    0,      //0x0b  ctrl+k//~vXXEI~
    {  GDK_L              , KEY_C_l       },// 0x26,//    0,      //0x0c  ctrl+l//~vXXEI~
    {  GDK_M              , KEY_C_m       },// 0x1c/*0d*/  ,      //0x0d  Enter//~vXXEI~
    {  GDK_N              , KEY_C_n       },// 0x31,//    0,      //0x0e  ctrl+n//~vXXEI~
    {  GDK_O              , KEY_C_o       },// 0x18,//    0,      //0x0f  ctrl+o//~vXXEI~
    {  GDK_P              , KEY_C_p       },// 0x19,//    0,      //0x10  ctrl+p//~vXXEI~
    {  GDK_Q              , KEY_C_q       },// 0x10,//    0,      //0x11  ctrl+q//~vXXEI~
    {  GDK_R              , KEY_C_r       },// 0x13,//    0,      //0x12  ctrl+r//~vXXEI~
    {  GDK_S              , KEY_C_s       },// 0x1f,//    0,      //0x13  ctrl+s//~vXXEI~
    {  GDK_T              , KEY_C_t       },// 0x14,//    0,      //0x14  ctrl+t//~vXXEI~
    {  GDK_U              , KEY_C_u       },// 0x16,//    0,      //0x15  ctrl+u//~vXXEI~
    {  GDK_V              , KEY_C_v       },// 0x2f,//    0,      //0x16  ctrl+v//~vXXEI~
    {  GDK_W              , KEY_C_w       },// 0x11,//    0,      //0x17  ctrl+w//~vXXEI~
    {  GDK_X              , KEY_C_x       },// 0x2d,//    0,      //0x18  ctrl+x//~vXXEI~
    {  GDK_Y              , KEY_C_y       },// 0x15,//    0,      //0x19  ctrl+y//~vXXEI~
    {  GDK_Z              , KEY_C_z       },// 0x2c,//    0,      //0x1a  ctrl+z//~vXXEI~
    {  GDK_Escape         , KEY_C_ESC     },// 0x01/*1b*/  ,      //0x1b  ctrl+Escape //ff1b//~vXXEI~
    {  GDK_bracketleft    , KEY_C_LMP     },// 0x1b/*1b*/  ,      //0x1b  ctrl+[//~v784R~
    {  GDK_backslash      , KEY_C_BSLASH  },//            0,      //0x1c  ctrl+\//~vXXEI~
    {  GDK_bracketright   , KEY_C_RMP     },//            0,      //0x1d  ctrl+]//~vXXEI~
    {  GDK_6              , KEY_C_6       },//            0,      //0x1e  ctrl+6//~vXXEI~
    {  GDK_minus          , KEY_C_MINUS   },//            0       //0x1f  ctrl+-//~vXXEI~
    {  GDK_braceleft      , KEY_C_LBRACE  },// 0x1b7d      ,      //0x1b  ctrl+[//~v785I~
    {  GDK_braceright     , KEY_C_RBRACE  },// 0x2b7d      ,      //0x1b  ctrl+[//~v785I~
    {  0                  ,0              }                        //~vXXEI~
                     };                                            //~vXXEI~
#define MAX_CCT 128                                                //~vXXEI~
static	PCTLCHRTBL Spctlchrtbl[MAX_CCT];    //index table          //~vXXEI~
//***                                                              //~v78NI~
static	UINT Skeycode_ctlr;	//ControlR(keycode 109) may assigned different keysym by xmodmap cmd//~v78NR~
//***                                                              //~v78NI~
static int Saltgrmask=GDK_MOD5_MASK/*default for AltGr*/;          //~va33R~
static int Sscrolllockmask;                                        //~va33R~
//===============================================================================//~vXXEI~
//int xxemain_keysym2doskey(UINT nScan,UINT nChar,int Pmodx,char *Pstr,int Pstrlen);//~v70mR~
int xxemain_keysym2doskey(UINT nScan,UINT nChar,int Pmodx,char *Pstr,int Pstrlen,int Pshiftstatus);//~v70mI~
//int  shiftstatus(int Pdownsw,UINT nChar,UINT nFlags,int *Ppstat);//~v78NR~
int  shiftstatus(int Pdownsw,UINT nChar,UINT nScan,UINT nFlags,int *Ppstat);//~v78NI~
int xxemain_kbdkeyin(int Popt,UINT Pdosch,UINT Pkeyval,UCHAR *Pstr,int Pstrlen);//~vXXER~
int xekbchk_kbdproc(int Popt,UINT Pscanchar,UINT Pkeyval,UCHAR *Pstr,int Pstrlen);//~vXXER~
BOOL xxemain_ontimer_rctlkey(void *Pdata);                         //~v76eR~
                                                                   //~v78NI~
int getkeycode(void);                                              //~v78NI~
#ifndef OPTGTK3                                                    //~var8R~
Display *open_display(void);                                       //~var8R~
int close_display(Display *Ppdisplay);                             //~var8R~
#else   //OPTGTK3                                                  //~var8R~
#endif                                                             //~var8R~
UINT getkeycode_ctlr(Display *Ppdisplay);                          //~v78NR~
int setkeysymmap(KeySym *Ppkeysym);                                //~v78NI~
int getkeysymtbl(Display *Ppdisplay,KeySym *Ppkeysym);             //~v78NI~
//===============================================================================//~vXXEM~
//create sysb key tbl index;                                       //~vXXEM~
//===============================================================================//~vXXEM~
void xxemain_kbdinit(void)                                         //~vXXEI~
{                                                                  //~vXXEM~
	PKEYSYMTBL pkst;                                               //~vXXEM~
	PALTCHRTBL pact;                                               //~vXXEM~
	PCTLCHRTBL pcct;                                               //~vXXER~
    UINT keysym;                                                   //~vXXEM~
	int ii;                                                        //~vXXEM~
    int scancode;                                                  //~v70mI~
//**************************                                       //~vXXEM~
//keysym tbl index tbl                                             //~vXXEM~
	for (pkst=Skeysymtbl;pkst->KSTkeysym;pkst++)                   //~vXXEM~
    {                                                              //~vXXEM~
		keysym=pkst->KSTkeysym;                                    //~vXXEM~
		if ((keysym & EXTKEY_MASK)!=EXTKEY_MASK)	//not ext key  //~vXXER~
        	continue;                                              //~vXXEM~
		ii=(int)(pkst->KSTkeysym & 0xff);                          //~vXXEM~
        Spkeysymtbl[ii]=pkst;                                      //~vXXEM~
    }                                                              //~vXXEM~
//altchartbl index tbl                                             //~vXXEM~
	for (pact=Saltchrtbl;pact->ACTkeysym;pact++)                   //~vXXEM~
    {                                                              //~vXXEM~
    	scancode=pact->ACTscancode;                                //~v70mI~
		if (scancode && scancode<MAX_ACT)   //ignore ffxx(tab,bs etc)//~v70mI~
	        Spshiftaltchrtbl[scancode]=pact;                       //~v70mI~
		keysym=pact->ACTkeysym;                                    //~vXXEM~
		if (!keysym||keysym>=MAX_ACT)   //ignore ffxx(tab,bs etc)  //~vXXEI~
        	continue;                                              //~vXXEM~
        Spaltchrtbl[keysym]=pact;                                  //~vXXEM~
    }                                                              //~vXXEM~
//ctlchartbl index tbl                                             //~vXXEI~
	for (pcct=Sctlchrtbl;pcct->CCTkeysym;pcct++)                   //~vXXEI~
    {                                                              //~vXXEI~
		keysym=pcct->CCTkeysym;                                    //~vXXEI~
		if (!keysym||keysym>=MAX_CCT)   //ignore ffxx(esc etc)     //~vXXEI~
        	continue;                                              //~vXXEI~
        Spctlchrtbl[keysym]=pcct;                                  //~vXXEI~
    }                                                              //~vXXEI~
    getkeycode();   //keycode->doskey mapping                      //~v78NI~
    return;                                                        //~vXXEM~
}//xxemain_kbdinit                                                 //~v7a9R~
//===============================================================================//~v003I~
int xxemain_onkeyup(UINT nChar, UINT nScan, UINT nFlags,char *Pstr)//~vXXER~
{                                                                  //~v003I~
	int rc=FALSE;                                                  //~vXXER~
	int sstat;                                                     //~vXXER~
    struct timeb ctm;                                              //~v69bR~
//*************************                                        //~vXXER~
	UTRACEP("%s:ch=%x,scan=%x,flag=%x\n",UTT,nChar,nScan,nFlags);     //~v76eR~//~vbu0R~
    Mtypematicintervalwait=0;	//stop rctk key typematic          //~v76eR~
    if (nChar==GDK_Print)                                          //~vXXER~
    {                                                              //~vXXEI~
//	    shiftstatus(0,nChar,nFlags,&sstat);                        //~v78NR~
  	    shiftstatus(0,nChar,nScan,nFlags,&sstat);                  //~v78NI~
	    if (sstat & WXEKBDMSG_SHIFTKEY)                            //~vXXEI~
	    	uactivate_menuitem(STRID_FILE_PRINT); 	//file print   //~vXXER~
        else                                                       //~vXXEI~
	    	uactivate_menuitem(STRID_FILE_PRTSCR); //scr print     //~vXXER~
        rc=TRUE;                                                   //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~v69bI~
    if (nChar==GDK_Scroll_Lock)   //mouse h-scroll generate scroll down/up the vk_left/right//~v69bI~
    {                                                              //~v69bI~
//  	ftime(&ctm);		//chk later lbdown                     //~v69bR~//~vbs1R~
    	uftime(&ctm);		//chk later lbdown                     //~vbs1I~
		Mscrolllocktime=ctm.time;		//chk later lbdown         //~v69bI~
		Mscrolllockmsec=ctm.millitm;	//chk later lbdown         //~v69bI~
        Mscrolllocksw=1;	//start of scroll lock                 //~v69iI~
        rc=FALSE;                                                  //~v69bI~
    }                                                              //~v69bI~
	return rc;                                                     //~vXXER~
}//xxemain_onkeyup                                                 //~vXXER~
//===============================================================================//~v003I~
//rc:0:call defaultwindowproc                                      //~v003I~
//===============================================================================//~v003I~
int xxemain_onchar(UINT nChar, UINT nScan, UINT nFlags,char *Pstr,int Pstrlen)//~vXXER~
{                                                                  //~v003I~
	int sstat,modidx;                                              //~vXXER~
    int dosch=0;                                                   //~vXXER~
    int iconvsw,mbslen;                                            //~v79zR~
    UCHAR *pmbs;                                                   //~v79zI~
#ifdef UTF8UCS4                                                    //~va3DI~
    int opt;                                                       //~va3DI~
#endif                                                             //~va3DI~
//*************************                                        //~v003I~
    UTRACEP("%s\n",UTT);                                           //~vbu0I~
    if (Pstrlen<0)	//ime ICONV require                            //~v79zI~
    {                                                              //~v79zI~
    	Pstrlen=-Pstrlen;                                          //~v79zI~
        iconvsw=1;                                                 //~v79zI~
    }                                                              //~v79zI~
    else                                                           //~v79zI~
    	iconvsw=0;                                                 //~v79zI~
//  if (Pcsrpos)	//preedit change                               //~vXXEI~
//  {                                                              //~vXXEI~
//  	xxemain_preeditchange(Pstr);                               //~vXXEI~
//      return TRUE;                                               //~vXXEI~
//  }                                                              //~vXXEI~
    Mtypematicintervalwait=0;	//stop rctk key typematic          //~v76eR~
//  modidx=shiftstatus(1,nChar,nFlags,&sstat);                     //~v78NR~
    modidx=shiftstatus(1,nChar,nScan,nFlags,&sstat);               //~v78NI~
    UTRACEP("%s:str=%s,modx=%d,scan=%x,char=%x,flag=%x,iconvsw=%d\n",UTT,Pstr,modidx,nScan,nChar,nFlags,iconvsw);//~v79zR~//~vbu0R~
    if (iconvsw)                                                   //~v79zI~
    {                                                              //~v79zI~
      if (Gxxeopt & GXXEOPT_KBCHKU8)                               //~vb2bR~
      {                                                            //~vb2bI~
		opt=sstat|WXEKBDMSG_ONCHAR|WXEKBDMSG_IME;                  //~vb2bI~
		xxemain_kbdkeyin(opt,0,nChar,Pstr,Pstrlen);//xe called by this key//~vb2bI~
      }                                                            //~vb2bI~
      else                                                         //~vb2bI~
      {                                                            //~vb2bI~
    	pmbs=Mwxeintf.WXEIimembs;                                  //~v79zI~
        UTRACED("IME iconv inpstr",Pstr,Pstrlen);                  //~v79zI~
		xxe_imeconv(0,(UCHAR*)Pstr,Pstrlen,pmbs,MAXIMECHARCTR,&mbslen);//~v79zR~
        UTRACED("IME iconv outmbs",pmbs,mbslen);                   //~v79zR~
#ifdef UTF8UCS4                                                    //~va3DI~
		opt=sstat|WXEKBDMSG_ONCHAR|WXEKBDMSG_IME;                  //~va3DI~
		xxemain_kbdkeyin(opt,0,nChar,pmbs,mbslen);//xe called by this key//~va3DI~
#else                                                              //~va3DI~
		xxemain_kbdkeyin(sstat|WXEKBDMSG_ONCHAR,0,nChar,pmbs,mbslen);//xe called by this key//~v79zI~
#endif                                                             //~va3DI~
      }                                                            //~vb2bI~
		return TRUE;                                               //~v79zI~
    }                                                              //~v79zI~
//  if (Pstrlen==1)	//alt+char                                     //~vXXER~//~v7a9R~
    if (Pstrlen==1	//alt+char                                     //~v7a9I~
    &&  (modidx==MODX_CONTROL||modidx==MODX_ALT)                   //~v7a9I~
    )                                                              //~v7a9I~
    {                                                              //~vXXEI~
//    	dosch=xxemain_keysym2doskey(nScan,nChar,modidx,Pstr,Pstrlen);//~v70mR~
      	dosch=xxemain_keysym2doskey(nScan,nChar,modidx,Pstr,Pstrlen,sstat);//~v70mI~
	    UTRACEP("onchar 1 byte dosch=%x,stat=%x\n",dosch,sstat);   //~v69YR~
        if (dosch<0)                                               //~vXXEI~
        	return FALSE;                                          //~vXXEI~
		xxemain_kbdkeyin(sstat|WXEKBDMSG_KEYDOWN,dosch,nChar,0,0);//xe called by this key//~vXXER~
		return TRUE;                                               //~vXXEI~
    }                                                              //~vXXEI~
	xxemain_kbdkeyin(sstat|WXEKBDMSG_ONCHAR,0,nChar,Pstr,Pstrlen);//xe called by this key//~vXXER~
    return TRUE;                                                   //~v003I~
}//xxemain_onchar                                                  //~vXXER~
//===============================================================================//~v003I~
//rc:0:call defaultwindowproc                                      //~v003I~
//p1:event->keycode                                                //~vXXEI~
//p2:event->hardware_keycode                                       //~vXXEI~
//p3:event->state                                                  //~vXXEI~
//p4:event->string                                                 //~vXXEI~
//p5:event->length                                                 //~vXXEI~
//===============================================================================//~v003I~
int xxemain_onkeydown(UINT nChar, UINT nScan, UINT nFlags,char *Pstr,int Pstrlen)//~vXXER~
{                                                                  //~v003I~
	int rc=TRUE,sstat,modidx;                                      //~vXXER~
    int dosch=0;                                                   //~vXXER~
    struct timeb ctm;                                              //~v69bR~
    UINT tid;                                                      //~v76eR~
    int delay;                                                     //~v76eI~
//************************************                             //~v003I~
UTRACEP("%s:ch=%x,scan=%x,flag=%x\n",UTT,nChar,nScan,nFlags);   //~v69YR~//+vbu0R~
    Mtypematicintervalwait=0;	//stop rctk key typematic          //~v76eR~
//  modidx=shiftstatus(1,nChar,nFlags,&sstat);                     //~v78NR~
    modidx=shiftstatus(1,nChar,nScan,nFlags,&sstat);               //~v78NI~
dprintf("onkeydown modidx=%d,char=%x,scan=%x,flag=%x,sstat=%x\n",modidx,nChar,nScan,nFlags,sstat);//~v785R~
//    if (sstat & WXEKBDMSG_SHIFTKEY                               //~v740R~
//    &&  sstat & WXEKBDMSG_CTLKEY)                                //~v740R~
//    {                                                            //~v740R~
//        switch(nChar)                                            //~v740R~
//        {                                                        //~v740R~
//        case GDK_F1:                                             //~v740R~
//            xxemain_scrsetruler(WXERULER_V);                     //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        case GDK_F2:                                             //~v740R~
//            xxemain_scrsetruler(WXERULER_H);                     //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        case GDK_F3:                                             //~v740R~
//            xxemain_scrsetruler(WXERULER_VH);                    //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        }                                                        //~v740R~
//    }                                                            //~v740R~
	if (nChar==GDK_ISO_Level3_Shift)	//AltGr : 0xFE03           //~va31I~
    {                                                              //~va33I~
        return FALSE;       //default proc                         //~va31I~
    }                                                              //~va33I~
    if (nChar==GDK_Scroll_Lock)   //mouse h-scroll generate scroll down/up the vk_left/right//~v69bM~
    {                                                              //~v69bM~
//    dprintf("@@@scrolllock down reset flag\n");                  //~v69YR~
//      wxe_scrollh(0,nChar);   //end scroll by mouse(reset flag)  //~v69iR~
        Mscrolllocksw=0; 	//VK_SCROLL off                        //~v69iI~
        return FALSE;       //default proc                         //~v69bM~
    }                                                              //~v69bM~
    if (nChar==GDK_Left || nChar==GDK_Right)  //to be chk scrolllock on//~v69bM~
    {                                                              //~v69bM~
      if (Mscrolllocksw)	//after VK_SCROLL keyup                //~v69iI~
      {                                                            //~v69iI~
//      ftime(&ctm);                                               //~v69bM~//~vbs1R~
        uftime(&ctm);                                              //~vbs1I~
        ctm.time-=Mscrolllocktime;                                 //~v69bM~
//    dprintf("@@@left/right ctm=%lx-%d,prev=%lx-%d\n",ctm.time,ctm.millitm,Mscrolllocktime,Mscrolllockmsec);//~v69YR~
        if (ctm.time==1 || ctm.time==0)                            //~v69bM~
        {                                                          //~v69bM~
            ctm.time=ctm.time*1000+ctm.millitm-Mscrolllockmsec;    //~v69bM~
            if (ctm.time<SCROLLLOCKMSGINTVL)  //interval between SCROLLLOCK up and VK_LEFT/RIGHT down to treate as mouse scroll//~v69bM~
                Mscrolllocksw=2;	//start of scroll              //~v69iI~
        }                                                          //~v69iI~
        if (Mscrolllocksw==2)                                      //~v69iI~
        {                                                          //~v69iI~
//              wxe_scrollh(Mscrollctr,nChar);  //notify to func_left/right to scroll by mouse//~v69iR~
            wxe_scrollhbar(Mscrollctr,(nChar==GDK_Left?-1:1));	//notify to func_left/right to scroll by mouse//~v69iI~
		    xxemain_scrinvalidate(0);                              //~v69iI~
            return TRUE;    //no kbdinput  process                 //~v69iI~
//    dprintf("@@@left/right intvl=0x%lx,ctr=%d\n",ctm.time,Mscrollctr);//~v69YR~
        }                                                          //~v69bM~
                                                                   //~v69bM~
        rc=TRUE;        //process key down                         //~v69bM~
      }//after VK_SCROLL key up                                    //~v69iI~
    }                                                              //~v69bM~
    if (!(sstat & WXEKBDMSG_RCTLKEY))	//right ctl key down       //~vXXEI~
    {                                                              //~vXXEI~
//    	dosch=xxemain_keysym2doskey(nScan,nChar,modidx,Pstr,Pstrlen);//~v70mR~
      	dosch=xxemain_keysym2doskey(nScan,nChar,modidx,Pstr,Pstrlen,sstat);//~v70mI~
    	if (dosch<0)     	//                                     //~vXXEI~
    		return FALSE;                                          //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~v76eR~
    {                                                              //~v76eR~
        tid=TID_RCTLKEY;                                           //~v76eR~
	    if (Mwxeintf.WXEIkbddelay)	//ini file or gconf            //~v76eR~
        	delay=Mwxeintf.WXEIkbddelay;                           //~v76eI~
        else                                                       //~v76eI~
        	delay=Mtypematicdelay;	//default                      //~v76eR~
    	Mtypematicintervalwait=delay;	//initial interval wait time//~v76eI~
		usettimer(tid,Mtypematicchkinterval,xxemain_ontimer_rctlkey);  //0:callback//~v76eR~
dprintf("%s:start rctlkey timer delay=%d\n",(char*)utimeedit("hh:mm:ss.mil",0),delay);//~v76eR~
    }                                                              //~v76eR~
//    dprintf("onkeydown dosch=%x,stat=%x\n",dosch,sstat);         //~v69YR~
	xxemain_kbdkeyin(sstat|WXEKBDMSG_KEYDOWN,dosch,nChar,0,0);//xe called by this key//~vXXER~
    return rc;                                                     //~v003R~
}//xxemain_keydown                                                 //~vXXER~
//**************************************************************** //~v76eR~
//*return elapsed time                                             //~v76eR~
//**************************************************************** //~v76eR~
BOOL xxemain_ontimer_rctlkey(void *Pdata)                          //~v76eR~
{                                                                  //~v76eR~
	int sstat,speed;                                               //~v76eR~
    UINT nChar;                                                    //~v76eR~
//****************************                                     //~v76eR~
dprintf("%s:onkey timer rctl\n",(char*)utimeedit("hh:mm:ss.mil",0));//~v76eR~
    if (!Mtypematicintervalwait)	//stop by key up etc           //~v76eR~
		return FALSE;		//continue timer                       //~v76eR~
    Mtypematicintervalwait-=Mtypematicchkinterval;                 //~v76eR~
    if (Mtypematicintervalwait>0)                                  //~v76eR~
		return TRUE;		//continue timer                       //~v76eR~
dprintf("onkey timer keyevent gen\n");                             //~v76eR~
    nChar=GDK_Control_R;                                           //~v76eR~
	sstat=(WXEKBDMSG_RCTLKEY|WXEKBDMSG_CTLKEY);                    //~v76eR~
	xxemain_kbdkeyin(sstat|WXEKBDMSG_KEYDOWN,0,nChar,0,0);//xe called by this key//~v76eR~
	if (Mwxeintf.WXEIkbdspeed)                                     //~v76eI~
        speed=Mwxeintf.WXEIkbdspeed;	//ini file value           //~v76eR~
    else                                                           //~v76eI~
        speed=Mtypematicinterval;                                  //~v76eI~
    Mtypematicintervalwait=speed;                                  //~v76eI~
dprintf("onkey next wait=%d\n",speed);                             //~v76eI~
    return TRUE;// Mpview->KillTimer(Pid);                         //~v76eR~
}//xxemain_ontimer_rctlkey                                         //~v76eR~
//===============================================================================//~v003I~
//return TRUE if redraw required                                   //~v003R~
//===============================================================================//~v003I~
int xxemain_kbdkeyin(int Popt,UINT Pscanchar,UINT Pkeyval,UCHAR *Pstr,int Pstrlen)//~vXXER~
{                                                                  //~v003I~
	int rc;                                                        //~vXXER~
//************************************                             //~v003I~
    UTRACEP("%s:scanchar=%04x,keyval=%04x\n",UTT,Pscanchar,Pkeyval);//~vbu0I~
	if (Mcpcopypansw)	                                           //~v003I~
    {                                                              //~v003I~
    	xxemain_mousecpdrawpan(Mcellcopy1.y,Mcellcopy2.y,-1);      //~vXXER~
    	Mcpcopypansw=0;		                                       //~v003I~
    }                                                              //~v003I~
                                                                   //~vXXEI~
    if (Gxxeopt & GXXEOPT_KBCHK)                                   //~vXXEI~
    {                                                              //~vXXEI~
		xekbchk_kbdproc(Popt,Pscanchar,Pkeyval,Pstr,Pstrlen);      //~vXXER~
    	rc=0;                                                      //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
		rc=wxe_kbdmsg(Popt,Pscanchar,Pstr,Pstrlen);//xe called by this key//~vXXER~
    if (rc==-1)                                                    //~vXXER~
    	exitmain();                                                //~vXXER~
    xxemain_scrinvalidate(0);                                      //~vXXER~
    return rc;                                                     //~v003R~
}//xxemain_kbdkeyin                                                //~vXXER~
//===============================================================================//~vXXEI~
//convert x-key symbol to dos key code                             //~vXXEI~
//return:dos key code, -1 to be ignored                            //~vXXEI~
//===============================================================================//~vXXEI~
//int xxemain_keysym2doskey(UINT nScan,UINT nChar,int Pmodidx,char *Pstr,int Pstrlen)//~v70mR~
int xxemain_keysym2doskey(UINT nScan,UINT nChar,int Pmodidx,char *Pstr,int Pstrlen,int Pshiftstatus)//~v70mI~
{                                                                  //~vXXEI~
	int keysym,doskey;                                             //~vXXER~
	PKEYSYMTBL pkst;                                               //~vXXER~
	PALTCHRTBL pact;                                               //~vXXEI~
	PCTLCHRTBL pcct;                                               //~vXXER~
//**************************                                       //~vXXEI~
  pkst=Spkeysymtblbykeycode[nScan & 0xff];                         //~v78NR~
  dprintf("pkst=%p by scan=%d\n",pkst,nScan);                      //~v78NR~
  if (!(nScan<256 && pkst!=0))//NOT extended key scancode          //~v78NR~
  {                                                                //~v78NI~
    if (nScan==Skeycode_ctlr)  //ignore keycode 109 even when other keysym assigned by xmodmap//~v78NR~
	    return -1;                                                 //~v78NI~
    if (nChar==GDK_ISO_Left_Tab)   //Shift+Tab generate fe20 (Redhat9)//~vXXEI~
    	nChar=GDK_Tab;                                             //~vXXER~
	keysym=(int)(nChar & 0xff);                                    //~vXXEI~
	if ((nChar & EXTKEY_MASK)!=EXTKEY_MASK)	//not ext key          //~vXXER~
    {                                                              //~vXXEI~
    	doskey=-1;                                                 //~vXXEI~
    	switch (Pmodidx)                                           //~vXXEI~
        {                                                          //~vXXEI~
        case  MODX_CONTROL:                                        //~vXXEI~
        	if (keysym<MAX_CCT)                                    //~vXXEI~
            {                                                      //~vXXEI~
				pcct=Spctlchrtbl[keysym];            	           //~vXXEI~
                if (pcct)                                          //~vXXEI~
                	doskey=pcct->CCTdoskey;                        //~vXXEI~
            }                                                      //~vXXEI~
        	break;                                                 //~vXXEI~
        case  MODX_ALT:                                            //~vXXEI~
            if ((nScan>0 && nScan<MAX_ACT)                         //~v70mI~
            &&  !(Pshiftstatus & WXEKBDMSG_ALTGR)	//scancode position changed by AltGr//~va33R~
            &&  (pact=Spshiftaltchrtbl[nScan]))                    //~va33I~
            	doskey=pact->ACTdoskey;                            //~v70mI~
            else                                                   //~v70mI~
        	if (keysym<MAX_ACT)                                    //~vXXEI~
            {                                                      //~vXXEI~
				pact=Spaltchrtbl[keysym];                          //~vXXEI~
                if (pact)                                          //~vXXEI~
                	doskey=pact->ACTdoskey;                        //~vXXER~
            }                                                      //~vXXEI~
        	break;                                                 //~vXXEI~
        }                                                          //~vXXEI~
        if (doskey==-1)		//return lnux scancode(no meaningfull for xe)//~vXXER~
            doskey=((nScan&0xff)<<8)|keysym;			//scan+char//~vXXER~
  	    dprintf("no keycode,char key doskey=%04x\n",doskey);       //~v78NI~
        return doskey;                                             //~vXXEI~
    }//char key                                                    //~vXXER~
    pkst=Spkeysymtbl[keysym];                                      //~vXXER~
	dprintf("pkst=%p by keysym=%04x\n",pkst,keysym);               //~v78NR~
    if (!pkst)                                                     //~vXXER~
        return -1;		//ignore                                   //~vXXEI~
  }//NOT extended key scancode                                     //~v78NI~
    if (Pmodidx==MODX_COMBI)                                       //~vXXEI~
        return -1;		//ignore                                   //~vXXEI~
    doskey=pkst->KSTdoskey[Pmodidx];                               //~vXXER~
  dprintf("doskey %04x\n",doskey);                                 //~v78NR~
//  if (nChar==GDK_Break   //Ctrl+Pause generate 0(KEY_NOTUSE)     //~vXXER~
//  &&  Pmodidx==MODX_CONTROL)                                     //~vXXER~
//  	return doskey;                                             //~vXXER~
    if (doskey==KEY_NOTUSE)            // for keypad key           //~vXXER~
    {                                                              //~vXXEI~
    	if (Pstrlen!=1)                                            //~vXXEI~
	    	return -1;                                             //~vXXER~
        doskey=((nScan&0xff)<<8)|*Pstr;			//scan+char        //~vXXEI~
    }                                                              //~vXXEI~
    return doskey;                                                 //~vXXEI~
}//xxemain_keysym2doskey                                           //~vXXER~
//===============================================================================//~vXXEM~
//get kbd shiftstatus                                              //~vXXEI~
//return modifier index                                            //~vXXEI~
//===============================================================================//~vXXEM~
//int  shiftstatus(int Pdownsw,UINT nChar,UINT nFlags,int *Ppstat) //~v78NR~
int  shiftstatus(int Pdownsw,UINT nChar,UINT nScan,UINT nFlags,int *Ppstat)//~v78NI~
{                                                                  //~vXXEM~
    int kstat=0,rc;                                                //~vXXER~
    UINT shiftmask;                                                //~vXXEI~
//******************************                                   //~vXXEM~
	shiftmask=(nFlags & ((GDK_SHIFT_MASK)|(GDK_CONTROL_MASK)|(GDK_MOD1_MASK)));	//key down//~vXXER~
    switch(shiftmask)                                              //~vXXEI~
    {                                                              //~vXXEI~
    case 0:					//no modifier key                      //~vXXEI~
//      if (nChar==GDK_Control_R)   //no status on when modifier key only//~v78NR~
        if (nChar==GDK_Control_R    //no status on when modifier key only//~v78NI~
        ||  nScan==Skeycode_ctlr)    //xmodmap may assigned another keysym to ctlr//~v78NR~
        {                                                          //~vXXEI~
        	if (Pdownsw)                                           //~vXXEI~
            {                                                      //~vXXEI~
	    		if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter//~vXXER~
		        	kstat=(WXEKBDMSG_RCTLKEY|WXEKBDMSG_CTLKEY);    //~vXXER~
            }                                                      //~vXXEI~
        }                                                          //~vXXEI~
    	rc=MODX_PLAIN;                                             //~vXXEI~
        break;                                                     //~vXXEI~
    case (GDK_SHIFT_MASK):	//shift key down                       //~vXXER~
        kstat|=WXEKBDMSG_SHIFTKEY;	                               //~vXXER~
    	rc=MODX_SHIFT;                                             //~vXXEI~
        break;                                                     //~vXXEI~
    case (GDK_CONTROL_MASK):	//ctrl key down                    //~vXXER~
        kstat|=WXEKBDMSG_CTLKEY;	                               //~vXXER~
        if (nChar==GDK_Control_R)                                  //~vXXEM~
        {                                                          //~vXXEM~
    		if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter//~vXXEM~
	        	kstat|=WXEKBDMSG_RCTLKEY;                          //~vXXEM~
        }                                                          //~vXXEM~
    	rc=MODX_CONTROL;                                           //~vXXEI~
        break;                                                     //~vXXEI~
    case (GDK_MOD1_MASK):			//alt key down                 //~vXXER~
        kstat|=WXEKBDMSG_SYSKEY;	                               //~vXXER~
    	rc=MODX_ALT;                                               //~vXXEI~
        break;                                                     //~vXXEI~
    default:                                                       //~vXXEI~
		if (nFlags & (GDK_SHIFT_MASK))	//shift key down           //~vXXER~
	        kstat|=WXEKBDMSG_SHIFTKEY;	//                         //~vXXEI~
		if (nFlags & (GDK_CONTROL_MASK))	//ctrl key down        //~vXXER~
	        kstat|=WXEKBDMSG_CTLKEY;	//                         //~vXXEI~
		if (nFlags & (GDK_MOD1_MASK))		//alt key down         //~vXXER~
	        kstat|=WXEKBDMSG_SYSKEY;	//                         //~vXXEI~
        if (kstat==(WXEKBDMSG_SHIFTKEY|WXEKBDMSG_CTLKEY)) //Shift+Ctl//~vXXER~
            rc=MODX_CONTROL;    //to avoid intercept by accelerater definition//~vXXEI~
        else                                                       //~vXXEI~
        if (kstat==(WXEKBDMSG_SHIFTKEY|WXEKBDMSG_SYSKEY)) //Shift+Alt//~vXXER~
            rc=MODX_ALT;    //to avoid intercept by menu key definition//~vXXEI~
        else                                                       //~vXXEI~
	    	rc=MODX_COMBI;                                         //~vXXER~
    }                                                              //~vXXEM~
    if (nChar & EXTKEY_MASK)                                       //~vXXER~
	    kstat|=WXEKBDMSG_FFKEY;                                    //~vXXER~
//	if (nFlags & (GDK_MOD5_MASK))	//scroll lock on               //~v69bI~//~va33R~
//      kstat|=WXEKBDMSG_SCROLLLOCKON;                             //~v69bI~//~va33R~
  	if (nFlags & Sscrolllockmask)	//scroll lock on               //~va33I~
        kstat|=WXEKBDMSG_SCROLLLOCKON;                             //~va33I~
	if (nFlags & Saltgrmask)	//scroll lock on                   //~va33I~
        kstat|=WXEKBDMSG_ALTGR;                                    //~va33I~
//UTRACEP("shift status shift=%04x,ctl=%04x,rctl=%04x\n",us1,us2,us3);//~vXXEM~
    *Ppstat=kstat;                                                 //~vXXEI~
    return rc;                                                     //~vXXER~
}//shiftstatus                                                     //~vXXER~
//**************************************************               //~v30eI~
//*get keyboard input and call key function                        //~v30eI~
//*rc   :rc from key function(-1 for quit)                         //~v30eI~
//**************************************************               //~v30eI~
//scancode/charcode                                                //~v30eI~
//      xx/yy:scan code/char code                                  //~v30eI~
//      00/yy:katakana,zenkaku                                     //~va3DR~
//      xx/00:psude scancode                                       //~v30eI~
//      xx/e0:psude scancode                                       //~v30eI~
int xekbchk_kbdproc(int Popt,UINT Pscanchar,UINT Pkeyval,UCHAR *Pstr,int Pstrlen)//~vXXER~
{                                                                  //~v30eI~
int xekbchk_showkey(int Pkeytyep,UCHAR *Pscanchar,int Pshift,UINT Pkeyval);//~v660R~
    int rc;                                                        //~v30eI~
    int keytype;                                                   //~v30eI~
    UCHAR inputc[4],*pinp;                                         //~vXXER~
    int shift;                                                     //~v30eI~
    int chScan,chChar;
//**********************                                           //~v30eI~
    chScan=Pscanchar>>8;
    chChar=Pscanchar&255;
    pinp=inputc;                                                   //~vXXER~
    inputc[0]=chChar;    //char code                               //~vXXEI~
    inputc[1]=chScan;    //scan code                               //~vXXEI~
    keytype=0;                                                     //~vXXEI~
    if (!chScan)                                                   //~vXXEI~
    {                                                              //~vXXEI~
        keytype=Pstrlen;                                           //~vXXEI~
        pinp=Pstr;                                                 //~vXXEI~
    }                                                              //~vXXEI~
    shift=Popt  & ( WXEKBDMSG_SHIFTKEY  //    0x10                 //~vXXER~
	              | WXEKBDMSG_CTLKEY    //    0x20
	              | WXEKBDMSG_SYSKEY);  //    0x80
    rc=xekbchk_showkey(keytype,pinp,shift,Pkeyval);                //~vXXER~
    return rc;                                                     //~v30eI~
}//kbdproc                                                         //~v30eI~
//**************************************************               //~v30eI~
//*show key                                                        //~v30eI~
//*rc   :rc -1:when double 'q' entered                             //~v30eI~
//**************************************************               //~v30eI~
int xekbchk_showkey(int Pkeytype,UCHAR *Pcharscan,int Pshift,UINT Pkeyval)//~vXXER~
{                                                                  //~v30eI~
void printline(char *Pstr,int Pposy,int Pposx);                    //~vXXEI~
char *getshiftid(int Pshift);                                      //~vXXEI~
	int ch1,ch2,key;                                               //~v400R~
	char *shiftid,*keynm;                                          //~vXXER~
    char printwk[128];                                             //~1128I~
    char keyvaledit[16];                                           //~vXXEI~
#define  LINE_STRING   3                                           //~1304R~
#define  LINE_KEY      4                                           //~1304R~
#define  LINE_CODE     5                                           //~1304R~
//**********************                                           //~v30eI~
	switch(Pkeytype)                                               //~v30eI~
    {                                                              //~v30eI~
    case 0:		//not ime                                          //~vXXER~
		shiftid=getshiftid(Pshift);                                //~vXXEI~
    	ch1=*Pcharscan;      //char                                //~vXXER~
    	ch2=*(Pcharscan+1);  //scan                                //~vXXER~
    	key=((ch2<<8)|ch1); //scan+char                            //~vXXER~
		keynm=wxe_kbdgetname(key,0);	//0:shiftkey option        //~vXXER~
        if (*keynm)	//not found  or ext key                        //~vXXER~
  	    	sprintf(printwk,"keyname=%s, modifier=%s, genarated keycode=0x%02X/x%02X",keynm,shiftid,ch2,ch1);//~vXXER~
        else                                                       //~vXXEI~
        {                                                          //~vXXEI~
            if (Pkeyval & EXTKEY_MASK)                             //~vXXER~
            	sprintf(keyvaledit,"x%04X",Pkeyval);               //~vXXEI~
            else                                                   //~vXXEI~
    		if (Pkeyval>=' ' && Pkeyval<=0x7f)                     //~vXXEI~
            	sprintf(keyvaledit,"%c",Pkeyval);                  //~vXXER~
            else                                                   //~vXXEI~
            	sprintf(keyvaledit,"x%02X",Pkeyval);               //~vXXER~
            	                                                   //~vXXEI~
    		if (ch1>=' ' && ch1<=0x7f)                             //~vXXER~
        		sprintf(printwk,"char-keycode=%s, modifier=%s, genarated keycode=x%02X/x%02X (%c)",keyvaledit,shiftid,ch2,ch1,ch1);//~vXXER~
        	else                                                   //~vXXER~
          		sprintf(printwk,"char-keycode=%s. modifier=%s, scan=x%02X/char=x%02X",keyvaledit,shiftid,ch2,ch1);//~vXXER~
        }                                                          //~vXXEI~
    	break;                                                     //~v30eI~
    default:	//ime string
        sprintf(printwk,"im-string, len=%d, str=%s",Pkeytype,Pcharscan);//~vXXER~
    	break;                                                     //~v30eI~
    }                                                              //~v30eI~
    printline(printwk,LINE_CODE,1);                                //~vXXEI~
    return 0;                                                      //~1122I~
}//xekbchk_showkey                                                 //~v30eI~
//********************************************************************//~v30eI~
char *getshiftid(int Pshift)                                       //~1122R~
{                                                                  //~v30eI~
static	char Sshiftid[64];                                         //~v30eI~
//******************************	                               //~v30eI~
	Sshiftid[0]=0;                                                 //~1122R~
	if (Pshift & WXEKBDMSG_SHIFTKEY)
    	strcat(Sshiftid,"Shift+");                                 //~v30eI~
	if (Pshift & WXEKBDMSG_CTLKEY)
    	strcat(Sshiftid,"Ctrl+");                                  //~v30eI~
	if (Pshift & WXEKBDMSG_SYSKEY)  //    0x80
    	strcat(Sshiftid,"Alt+");                                     //~v30eI~
    return Sshiftid;                                               //~v30eI~
}//getshiftid                                                      //~v30eI~
//********************************************************************//~vXXEI~
void printline(char *Pstr,int Pposy,int Pposx)                     //~1128R~
{                                                                  //~1128I~
//****************************                                     //~1128I~
	fprintf(stdout,"****** %s\n",Pstr);                            //~v660R~
    return;                                                        //~1128I~
}                                                                  //~1128I~
//********************************************************************//~v78NI~
//* get keycode info                                               //~v78NI~
//********************************************************************//~v78NI~
int getkeycode(void)                                               //~v78NI~
{                                                                  //~v78NI~
	Display *pdisplay;                                             //~v78NM~
    KeySym  keysymtb[256];                                         //~v78NI~
//***********                                                      //~v78NI~
	if (!(pdisplay=open_display()))                                //~v78NI~
    	return 4;                                                  //~v78NI~
	Skeycode_ctlr=getkeycode_ctlr(pdisplay);                       //~v78NI~
	getkeysymtbl(pdisplay,keysymtb);	//keycode->keysym mapping tbl//~v78NI~
	setkeysymmap(keysymtb);	//keycode->KEYSYMTBL mapping           //~v78NI~
	close_display(pdisplay);                                       //~v78NI~
    return 0;                                                      //~v78NI~
}//getkeycode                                                      //~v78NI~
//********************************************************************//~v78NI~
//* open X display                                                 //~v78NI~
//********************************************************************//~v78NI~
Display *open_display(void)                                        //~v78NI~
{                                                                  //~v78NI~
	Display *pdisplay;                                             //~v78NI~
    pdisplay=XOpenDisplay(NULL);                                   //~v78NR~
    if (!pdisplay)                                                 //~v78NI~
        fprintf (stderr,"unable to open display.\n");              //~v78NI~
    return pdisplay;                                               //~v78NI~
}//open_display(void)                                              //~v78NI~
//********************************************************************//~v78NI~
//* close X display                                                //~v78NI~
//********************************************************************//~v78NI~
int close_display(Display *Ppdisplay)                              //~v78NI~
{                                                                  //~v78NI~
	XCloseDisplay(Ppdisplay);                                      //~v78NI~
    return 0;                                                      //~v78NI~
}//close_display(void)                                             //~v78NI~
//********************************************************************//~v78NI~
//* getkeysym_ctlr                                                 //~v78NR~
//*   get keysym of ctrlr                                          //~v78NI~
//********************************************************************//~v78NI~
UINT getkeycode_ctlr(Display *Ppdisplay)                           //~v78NR~
{                                                                  //~v78NI~
	XModifierKeymap *pmap=NULL;                                    //~v78NI~
	int min_keycode,max_keycode,keycode;                           //~v78NR~
//	KeySym keysym;                                                 //~v78NR~
//******************                                               //~v78NI~
    XDisplayKeycodes(Ppdisplay,&min_keycode,&max_keycode);         //~v78NI~
    pmap=XGetModifierMapping (Ppdisplay);                          //~v78NI~
    if (!pmap)                                                     //~v78NI~
    {                                                              //~v78NI~
        fprintf (stderr,"XGetModifierMapping failed.\n");          //~v78NI~
    	return 0;                                                  //~v78NI~
    }                                                              //~v78NI~
    keycode=pmap->modifiermap[pmap->max_keypermod*2+1];            //~v78NR~
    dprintf("rctl keycode=%d\n",keycode);                          //~v78NI~
    return (UINT)keycode;                                          //~v78NI~
}//getkeysym_ctlr                                                  //~v78NI~
//===============================================================================//~va33M~
//get modmask for AltGr and ScrollLock                             //~va33I~
//===============================================================================//~va33M~
int xxekey_getmodmask(int Popt,Display *Ppdisplay,int Pmaxkeysym)  //~va33R~
{                                                                  //~va33M~
	XModifierKeymap *pmap;                                         //~va33I~
	int rc=0,ii,jj,kk,ll,keysym=0,keycode,maxkeycode;              //~vaffR~
    UCHAR *pc;                                                     //~va33I~
    KeySym *pks;                                                   //~vak4R~
    int ksctr;                                                     //~vak4I~
//***********************                                          //~va33M~
dprintf("modmaskchk maxkeysym=%d\n",Pmaxkeysym);                   //~va33I~
    pmap=XGetModifierMapping (Ppdisplay);                          //~va33I~
    if (!pmap)                                                     //~va33I~
    {                                                              //~va33I~
        fprintf (stderr,"XGetModifierMapping failed.\n");          //~va33I~
    	return 0;                                                  //~va33I~
    }                                                              //~va33I~
    maxkeycode=pmap->max_keypermod;                                //~va33I~
    pc=pmap->modifiermap;                                          //~va33I~
	for (ii=1,jj=0;;ii<<=1,jj++,pc+=maxkeycode)                    //~va33I~
    {                                                              //~va33I~
		if (ii<GDK_MOD1_MASK)                                      //~va33I~
        	continue;                                              //~va33I~
        for (kk=0;kk<maxkeycode;kk++)                              //~va33I~
        {                                                          //~va33I~
            keycode=*(pc+kk);                                      //~va33I~
            if (!keycode)                                          //~va33I~
                continue;                                          //~va33I~
#ifdef AAA                                                         //~vak4I~
            for (ll=0;ll<Pmaxkeysym;ll++)                          //~va33I~
            {                                                      //~va33I~
            	keysym=XKeycodeToKeysym(Ppdisplay,keycode,ll);     //~va33R~
                if (keysym)                                        //~va33I~
                	break;                                         //~va33I~
            }                                                      //~va33I~
#else                                                              //~vak4I~
        	pks=XGetKeyboardMapping(Ppdisplay,keycode,1/*request ctr*/,&ksctr);//~vak4I~
        	if (!pks)                                              //~vak4I~
        		continue;                                          //~vak4R~
            for (ll=0;ll<ksctr;ll++)                               //~vak4I~
            {                                                      //~vak4I~
            	keysym=pks[ll];                                    //~vak4R~
                if (keysym!=NoSymbol)                              //~vak4I~
                	break;                                         //~vak4I~
            }                                                      //~vak4I~
        	XFree(pks);                                            //~vak4I~
#endif                                                             //~vak4I~
			if (keysym==GDK_ISO_Level3_Shift)	//AltGr : 0xFE03   //~va33I~
            {                                                      //~va33I~
dprintf("modmaskchk altgr ii=%x,keycode=%x,ll=%d,keysym=%x\n",ii,keycode,ll,keysym);//~vak4I~
            	Saltgrmask=ii;                                     //~va33R~
                rc++;                                              //~va33I~
            }                                                      //~va33I~
            else                                                   //~va33I~
			if (keysym==GDK_Scroll_Lock)	//ScrollLock : 0xFE14  //~va33R~
            {                                                      //~va33I~
//dprintf("modmaskchk scrolllock ii=x,keycooddee==%x,ll=%d,keysym=%x\n",ii,keycode,ll,keysym);//~vak4I~//~vbu0R~
  dprintf("modmaskchk scrolllock ii=%d,keycoodde==x%x,ll=%d,keysym=x%x\n",ii,keycode,ll,keysym);//~vbu0I~
            	Sscrolllockmask=ii;                                //~va33R~
                rc++;                                              //~va33I~
            }                                                      //~va33I~
        }                                                          //~va33I~
		if (ii==GDK_MOD5_MASK)                                     //~va33I~
        	break;                                                 //~va33I~
    }                                                              //~va33I~
dprintf("modmaskchk altgr=%x,scrolllock=%x\n",Saltgrmask,Sscrolllockmask);//~va33R~
    return rc;                                                     //~va33I~
}//xxekey_getmodmask                                               //~va33R~
//********************************************************************//~v78NI~
//* getkeysymtbl                                                   //~v78NI~
//*   kycode->keysym mapping                                       //~v78NI~
//********************************************************************//~v78NI~
int getkeysymtbl(Display *Ppdisplay,KeySym *Ppkeysym)              //~v78NI~
{                                                                  //~v78NI~
    int ii,min_keycode,max_keycode,keysyms_per_keycode;            //~v78NI~
    KeySym *keymap,*keymap0,keysym;                                //~v78NI~
    char *keyname;                                                 //~v78NI~
//********************                                             //~v78NI~
	memset(Ppkeysym,0,256*sizeof(KeySym));                         //~v78NR~
    XDisplayKeycodes(Ppdisplay,&min_keycode,&max_keycode);         //~v78NI~
    keymap0=XGetKeyboardMapping(Ppdisplay,min_keycode,(max_keycode-min_keycode+1),&keysyms_per_keycode);//~v78NR~
    if (!keymap0)                                                  //~v78NI~
    {                                                              //~v78NI~
        fprintf (stderr,"XGetKeyboardMapping failed.\n");          //~v78NI~
        return 4;                                                  //~v78NI~
    }                                                              //~v78NI~
    xxekey_getmodmask(0,Ppdisplay,keysyms_per_keycode);            //~va33R~
    keymap=keymap0;                                                //~v78NI~
    for (ii=min_keycode;ii<=max_keycode;ii++,keymap+=keysyms_per_keycode)//~v78NR~
    {                                                              //~v78NI~
    	keysym=keymap[0];   	//plain (no modifier)              //~v78NI~
        keyname="";                                                //~v78NI~
        if (keysym!=NoSymbol)                                      //~v78NI~
        {                                                          //~v78NI~
			keyname=XKeysymToString(keysym);                       //~v78NI~
          if (keyname!=NULL)                                       //~va0bI~
          {                                                        //~va0bI~
            if (strlen(keyname)<=3 || memcmp(keyname,"KP_",3)) //use not keycode but keysym for keypad key(these key change by Numlock etc)//~v78NI~
		    	Ppkeysym[ii]=keysym;                               //~v78NI~
          }                                                        //~va0bI~
        }                                                          //~v78NI~
//      dprintf("keycode=%d,sym=%04x %s\n",ii,(UINT)keysym,keyname);//~v79zR~
    }                                                              //~v78NI~
    XFree((char *)keymap0);                                        //~v78NI~
    return 0;                                                      //~v78NI~
}//getkeysymtbl                                                    //~v78NI~
//********************************************************************//~v78NI~
//* setkeysymmap                                                   //~v78NI~
//********************************************************************//~v78NI~
int setkeysymmap(KeySym *Ppkeysym)                                 //~v78NI~
{                                                                  //~v78NI~
    int ii,keysymtblidx,doskey;                                    //~v78NR~
    KeySym *pkeysym,keysym;                                        //~v78NI~
    PKEYSYMTBL psymt;                                              //~v78NI~
//********************                                             //~v78NI~
	for (ii=0,pkeysym=Ppkeysym;ii<256;ii++,pkeysym++)              //~v78NI~
    {                                                              //~v78NI~
    	if (ii==Skeycode_ctlr)  //control_R                        //~v78NI~
        	continue;                                              //~v78NI~
    	keysym=*pkeysym;                                           //~v78NI~
        if (keysym && (keysym & 0xff00)) //extended key            //~v78NI~
        {                                                          //~v78NI~
            keysymtblidx=keysym & 0xff;                            //~v78NR~
            psymt=Spkeysymtbl[keysymtblidx];                       //~v78NR~
            if (psymt)                                             //~v78NI~
            {                                                      //~v78NI~
            	doskey=psymt->KSTdoskey[0];                        //~v78NI~
                if (doskey)                                        //~v78NI~
                {                                                  //~v78NI~
            		Spkeysymtblbykeycode[ii]=psymt;	//function by keycode//~v78NR~
            		dprintf("keycode mapping %d & %x doskey=%x\n",ii,(UINT)keysym,psymt->KSTdoskey[0]);//~v78NR~
                }                                                  //~v78NI~
            }                                                      //~v78NI~
        }                                                          //~v78NI~
    }                                                              //~v78NI~
    return 0;                                                      //~v78NI~
}//setkeysymmap                                                    //~v78NR~
